begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Program.h: Defines the gl::Program class. Implements GL program objects
end_comment
begin_comment
comment|// and related functionality. [OpenGL ES 2.0.24] section 2.10.3 page 28.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_PROGRAM_BINARY_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_PROGRAM_BINARY_H_
define|#
directive|define
name|LIBGLESV2_PROGRAM_BINARY_H_
end_define
begin_define
DECL|macro|GL_APICALL
define|#
directive|define
name|GL_APICALL
end_define
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2ext.h>
end_include
begin_include
include|#
directive|include
file|<d3dcompiler.h>
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Context.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/D3DConstantTable.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/mathutil.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Shader.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|FragmentShader
decl_stmt|;
name|class
name|VertexShader
decl_stmt|;
comment|// Helper struct representing a single shader uniform
struct|struct
name|Uniform
block|{
name|Uniform
argument_list|(
argument|GLenum type
argument_list|,
argument|const std::string&_name
argument_list|,
argument|unsigned int arraySize
argument_list|)
empty_stmt|;
operator|~
name|Uniform
argument_list|()
expr_stmt|;
name|bool
name|isArray
parameter_list|()
function_decl|;
specifier|const
name|GLenum
name|type
decl_stmt|;
specifier|const
name|std
operator|::
name|string
name|_name
expr_stmt|;
comment|// Decorated name
specifier|const
name|std
operator|::
name|string
name|name
expr_stmt|;
comment|// Undecorated name
specifier|const
name|unsigned
name|int
name|arraySize
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
name|bool
name|dirty
decl_stmt|;
struct|struct
name|RegisterInfo
block|{
name|RegisterInfo
argument_list|()
block|{
name|float4Index
operator|=
operator|-
literal|1
expr_stmt|;
name|samplerIndex
operator|=
operator|-
literal|1
expr_stmt|;
name|boolIndex
operator|=
operator|-
literal|1
expr_stmt|;
name|registerCount
operator|=
literal|0
expr_stmt|;
block|}
name|void
name|set
parameter_list|(
specifier|const
name|D3DConstant
modifier|*
name|constant
parameter_list|)
block|{
switch|switch
condition|(
name|constant
operator|->
name|registerSet
condition|)
block|{
case|case
name|D3DConstant
operator|::
name|RS_BOOL
case|:
name|boolIndex
operator|=
name|constant
operator|->
name|registerIndex
expr_stmt|;
break|break;
case|case
name|D3DConstant
operator|::
name|RS_FLOAT4
case|:
name|float4Index
operator|=
name|constant
operator|->
name|registerIndex
expr_stmt|;
break|break;
case|case
name|D3DConstant
operator|::
name|RS_SAMPLER
case|:
name|samplerIndex
operator|=
name|constant
operator|->
name|registerIndex
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
name|ASSERT
argument_list|(
name|registerCount
operator|==
literal|0
operator|||
name|registerCount
operator|==
operator|(
name|int
operator|)
name|constant
operator|->
name|registerCount
argument_list|)
expr_stmt|;
name|registerCount
operator|=
name|constant
operator|->
name|registerCount
expr_stmt|;
block|}
name|int
name|float4Index
decl_stmt|;
name|int
name|samplerIndex
decl_stmt|;
name|int
name|boolIndex
decl_stmt|;
name|int
name|registerCount
decl_stmt|;
block|}
struct|;
name|RegisterInfo
name|ps
decl_stmt|;
name|RegisterInfo
name|vs
decl_stmt|;
block|}
struct|;
comment|// Struct used for correlating uniforms/elements of uniform arrays to handles
struct|struct
name|UniformLocation
block|{
name|UniformLocation
argument_list|()
block|{     }
name|UniformLocation
argument_list|(
argument|const std::string&_name
argument_list|,
argument|unsigned int element
argument_list|,
argument|unsigned int index
argument_list|)
empty_stmt|;
name|std
operator|::
name|string
name|name
expr_stmt|;
name|unsigned
name|int
name|element
decl_stmt|;
name|unsigned
name|int
name|index
decl_stmt|;
block|}
struct|;
comment|// This is the result of linking a program. It is the state that would be passed to ProgramBinary.
name|class
name|ProgramBinary
range|:
name|public
name|RefCountObject
block|{
name|public
operator|:
name|ProgramBinary
argument_list|()
block|;
operator|~
name|ProgramBinary
argument_list|()
block|;
name|IDirect3DPixelShader9
operator|*
name|getPixelShader
argument_list|()
block|;
name|IDirect3DVertexShader9
operator|*
name|getVertexShader
argument_list|()
block|;
name|GLuint
name|getAttributeLocation
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
name|int
name|getSemanticIndex
argument_list|(
argument|int attributeIndex
argument_list|)
block|;
name|GLint
name|getSamplerMapping
argument_list|(
argument|SamplerType type
argument_list|,
argument|unsigned int samplerIndex
argument_list|)
block|;
name|TextureType
name|getSamplerTextureType
argument_list|(
argument|SamplerType type
argument_list|,
argument|unsigned int samplerIndex
argument_list|)
block|;
name|GLint
name|getUsedSamplerRange
argument_list|(
argument|SamplerType type
argument_list|)
block|;
name|bool
name|usesPointSize
argument_list|()
specifier|const
block|;
name|GLint
name|getUniformLocation
argument_list|(
argument|std::string name
argument_list|)
block|;
name|bool
name|setUniform1fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *v
argument_list|)
block|;
name|bool
name|setUniform2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *v
argument_list|)
block|;
name|bool
name|setUniform3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *v
argument_list|)
block|;
name|bool
name|setUniform4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *v
argument_list|)
block|;
name|bool
name|setUniformMatrix2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|bool
name|setUniformMatrix3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|bool
name|setUniformMatrix4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|bool
name|setUniform1iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
block|;
name|bool
name|setUniform2iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
block|;
name|bool
name|setUniform3iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
block|;
name|bool
name|setUniform4iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
block|;
name|bool
name|getUniformfv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei *bufSize
argument_list|,
argument|GLfloat *params
argument_list|)
block|;
name|bool
name|getUniformiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei *bufSize
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|GLint
name|getDxDepthRangeLocation
argument_list|()
specifier|const
block|;
name|GLint
name|getDxDepthLocation
argument_list|()
specifier|const
block|;
name|GLint
name|getDxCoordLocation
argument_list|()
specifier|const
block|;
name|GLint
name|getDxHalfPixelSizeLocation
argument_list|()
specifier|const
block|;
name|GLint
name|getDxFrontCCWLocation
argument_list|()
specifier|const
block|;
name|GLint
name|getDxPointsOrLinesLocation
argument_list|()
specifier|const
block|;
name|void
name|dirtyAllUniforms
argument_list|()
block|;
name|void
name|applyUniforms
argument_list|()
block|;
name|bool
name|load
argument_list|(
argument|InfoLog&infoLog
argument_list|,
argument|const void *binary
argument_list|,
argument|GLsizei length
argument_list|)
block|;
name|bool
name|save
argument_list|(
argument|void* binary
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei *length
argument_list|)
block|;
name|GLint
name|getLength
argument_list|()
block|;
name|bool
name|link
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|AttributeBindings
operator|&
name|attributeBindings
argument_list|,
name|FragmentShader
operator|*
name|fragmentShader
argument_list|,
name|VertexShader
operator|*
name|vertexShader
argument_list|)
block|;
name|void
name|getAttachedShaders
argument_list|(
argument|GLsizei maxCount
argument_list|,
argument|GLsizei *count
argument_list|,
argument|GLuint *shaders
argument_list|)
block|;
name|void
name|getActiveAttribute
argument_list|(
argument|GLuint index
argument_list|,
argument|GLsizei bufsize
argument_list|,
argument|GLsizei *length
argument_list|,
argument|GLint *size
argument_list|,
argument|GLenum *type
argument_list|,
argument|GLchar *name
argument_list|)
block|;
name|GLint
name|getActiveAttributeCount
argument_list|()
block|;
name|GLint
name|getActiveAttributeMaxLength
argument_list|()
block|;
name|void
name|getActiveUniform
argument_list|(
argument|GLuint index
argument_list|,
argument|GLsizei bufsize
argument_list|,
argument|GLsizei *length
argument_list|,
argument|GLint *size
argument_list|,
argument|GLenum *type
argument_list|,
argument|GLchar *name
argument_list|)
block|;
name|GLint
name|getActiveUniformCount
argument_list|()
block|;
name|GLint
name|getActiveUniformMaxLength
argument_list|()
block|;
name|void
name|validate
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|)
block|;
name|bool
name|validateSamplers
argument_list|(
name|InfoLog
operator|*
name|infoLog
argument_list|)
block|;
name|bool
name|isValidated
argument_list|()
specifier|const
block|;
name|unsigned
name|int
name|getSerial
argument_list|()
specifier|const
block|;
specifier|static
name|std
operator|::
name|string
name|decorateAttribute
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
block|;
comment|// Prepend an underscore
specifier|static
name|std
operator|::
name|string
name|undecorateUniform
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|_name
argument_list|)
block|;
comment|// Remove leading underscore
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ProgramBinary
argument_list|)
block|;
name|ID3D10Blob
operator|*
name|compileToBinary
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|char
operator|*
name|hlsl
argument_list|,
specifier|const
name|char
operator|*
name|profile
argument_list|,
name|D3DConstantTable
operator|*
operator|*
name|constantTable
argument_list|)
block|;
name|int
name|packVaryings
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|Varying
operator|*
name|packing
index|[]
index|[
literal|4
index|]
argument_list|,
name|FragmentShader
operator|*
name|fragmentShader
argument_list|)
block|;
name|bool
name|linkVaryings
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
name|std
operator|::
name|string
operator|&
name|pixelHLSL
argument_list|,
name|std
operator|::
name|string
operator|&
name|vertexHLSL
argument_list|,
name|FragmentShader
operator|*
name|fragmentShader
argument_list|,
name|VertexShader
operator|*
name|vertexShader
argument_list|)
block|;
name|bool
name|linkAttributes
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|AttributeBindings
operator|&
name|attributeBindings
argument_list|,
name|FragmentShader
operator|*
name|fragmentShader
argument_list|,
name|VertexShader
operator|*
name|vertexShader
argument_list|)
block|;
name|bool
name|linkUniforms
argument_list|(
argument|InfoLog&infoLog
argument_list|,
argument|GLenum shader
argument_list|,
argument|D3DConstantTable *constantTable
argument_list|)
block|;
name|bool
name|defineUniform
argument_list|(
argument|InfoLog&infoLog
argument_list|,
argument|GLenum shader
argument_list|,
argument|const D3DConstant *constant
argument_list|,
argument|std::string name =
literal|""
argument_list|)
block|;
name|bool
name|defineUniform
argument_list|(
argument|GLenum shader
argument_list|,
argument|const D3DConstant *constant
argument_list|,
argument|const std::string&name
argument_list|)
block|;
name|Uniform
operator|*
name|createUniform
argument_list|(
specifier|const
name|D3DConstant
operator|*
name|constant
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
block|;
name|bool
name|applyUniformnfv
argument_list|(
name|Uniform
operator|*
name|targetUniform
argument_list|,
specifier|const
name|GLfloat
operator|*
name|v
argument_list|)
block|;
name|bool
name|applyUniform1iv
argument_list|(
argument|Uniform *targetUniform
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
block|;
name|bool
name|applyUniform2iv
argument_list|(
argument|Uniform *targetUniform
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
block|;
name|bool
name|applyUniform3iv
argument_list|(
argument|Uniform *targetUniform
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
block|;
name|bool
name|applyUniform4iv
argument_list|(
argument|Uniform *targetUniform
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
block|;
name|void
name|applyUniformniv
argument_list|(
argument|Uniform *targetUniform
argument_list|,
argument|GLsizei count
argument_list|,
argument|const Vector4 *vector
argument_list|)
block|;
name|void
name|applyUniformnbv
argument_list|(
argument|Uniform *targetUniform
argument_list|,
argument|GLsizei count
argument_list|,
argument|int width
argument_list|,
argument|const GLboolean *v
argument_list|)
block|;
name|IDirect3DDevice9
operator|*
name|mDevice
block|;
name|IDirect3DPixelShader9
operator|*
name|mPixelExecutable
block|;
name|IDirect3DVertexShader9
operator|*
name|mVertexExecutable
block|;
comment|// These are only used during linking.
name|D3DConstantTable
operator|*
name|mConstantTablePS
block|;
name|D3DConstantTable
operator|*
name|mConstantTableVS
block|;
name|Attribute
name|mLinkedAttribute
index|[
name|MAX_VERTEX_ATTRIBS
index|]
block|;
name|int
name|mSemanticIndex
index|[
name|MAX_VERTEX_ATTRIBS
index|]
block|;      struct
name|Sampler
block|{
name|Sampler
argument_list|()
block|;
name|bool
name|active
block|;
name|GLint
name|logicalTextureUnit
block|;
name|TextureType
name|textureType
block|;     }
block|;
name|Sampler
name|mSamplersPS
index|[
name|MAX_TEXTURE_IMAGE_UNITS
index|]
block|;
name|Sampler
name|mSamplersVS
index|[
name|MAX_VERTEX_TEXTURE_IMAGE_UNITS_VTF
index|]
block|;
name|GLuint
name|mUsedVertexSamplerRange
block|;
name|GLuint
name|mUsedPixelSamplerRange
block|;
name|bool
name|mUsesPointSize
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Uniform
operator|*
operator|>
name|UniformArray
expr_stmt|;
name|UniformArray
name|mUniforms
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|UniformLocation
operator|>
name|UniformIndex
expr_stmt|;
name|UniformIndex
name|mUniformIndex
decl_stmt|;
name|GLint
name|mDxDepthRangeLocation
decl_stmt|;
name|GLint
name|mDxDepthLocation
decl_stmt|;
name|GLint
name|mDxCoordLocation
decl_stmt|;
name|GLint
name|mDxHalfPixelSizeLocation
decl_stmt|;
name|GLint
name|mDxFrontCCWLocation
decl_stmt|;
name|GLint
name|mDxPointsOrLinesLocation
decl_stmt|;
name|bool
name|mValidated
decl_stmt|;
specifier|const
name|unsigned
name|int
name|mSerial
decl_stmt|;
specifier|static
name|unsigned
name|int
name|issueSerial
parameter_list|()
function_decl|;
specifier|static
name|unsigned
name|int
name|mCurrentSerial
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_PROGRAM_BINARY_H_
end_comment
end_unit
