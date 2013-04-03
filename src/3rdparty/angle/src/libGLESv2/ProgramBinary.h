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
file|"common/RefCountObject.h"
end_include
begin_include
include|#
directive|include
file|"angletypes.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/mathutil.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Uniform.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Shader.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Constants.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|ShaderExecutable
decl_stmt|;
name|class
name|Renderer
decl_stmt|;
struct_decl|struct
name|TranslatedAttribute
struct_decl|;
block|}
end_decl_stmt
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
name|class
name|InfoLog
decl_stmt|;
name|class
name|AttributeBindings
decl_stmt|;
struct_decl|struct
name|Varying
struct_decl|;
comment|// Struct used for correlating uniforms/elements of uniform arrays to handles
struct|struct
name|UniformLocation
block|{
name|UniformLocation
argument_list|()
block|{     }
name|UniformLocation
argument_list|(
argument|const std::string&name
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
name|explicit
name|ProgramBinary
argument_list|(
name|rx
operator|::
name|Renderer
operator|*
name|renderer
argument_list|)
block|;
operator|~
name|ProgramBinary
argument_list|()
block|;
name|rx
operator|::
name|ShaderExecutable
operator|*
name|getPixelExecutable
argument_list|()
block|;
name|rx
operator|::
name|ShaderExecutable
operator|*
name|getVertexExecutable
argument_list|()
block|;
name|rx
operator|::
name|ShaderExecutable
operator|*
name|getGeometryExecutable
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
name|bool
name|usesPointSpriteEmulation
argument_list|()
specifier|const
block|;
name|bool
name|usesGeometryShader
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
specifier|const
block|;
name|GLint
name|getActiveAttributeCount
argument_list|()
specifier|const
block|;
name|GLint
name|getActiveAttributeMaxLength
argument_list|()
specifier|const
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
specifier|const
block|;
name|GLint
name|getActiveUniformCount
argument_list|()
specifier|const
block|;
name|GLint
name|getActiveUniformMaxLength
argument_list|()
specifier|const
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
name|void
name|sortAttributesByLayout
argument_list|(
argument|rx::TranslatedAttribute attributes[gl::MAX_VERTEX_ATTRIBS]
argument_list|,
argument|int sortedSemanticIndices[MAX_VERTEX_ATTRIBS]
argument_list|)
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
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ProgramBinary
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
argument|InfoLog&infoLog
argument_list|,
argument|int registers
argument_list|,
argument|const Varying *packing[][
literal|4
argument|]
argument_list|,
argument|std::string& pixelHLSL
argument_list|,
argument|std::string& vertexHLSL
argument_list|,
argument|FragmentShader *fragmentShader
argument_list|,
argument|VertexShader *vertexShader
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
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|sh
operator|::
name|ActiveUniforms
operator|&
name|vertexUniforms
argument_list|,
specifier|const
name|sh
operator|::
name|ActiveUniforms
operator|&
name|fragmentUniforms
argument_list|)
block|;
name|bool
name|defineUniform
argument_list|(
argument|GLenum shader
argument_list|,
argument|const sh::Uniform&constant
argument_list|,
argument|InfoLog&infoLog
argument_list|)
block|;
name|std
operator|::
name|string
name|generateGeometryShaderHLSL
argument_list|(
argument|int registers
argument_list|,
argument|const Varying *packing[][
literal|4
argument|]
argument_list|,
argument|FragmentShader *fragmentShader
argument_list|,
argument|VertexShader *vertexShader
argument_list|)
specifier|const
block|;
name|std
operator|::
name|string
name|generatePointSpriteHLSL
argument_list|(
argument|int registers
argument_list|,
argument|const Varying *packing[][
literal|4
argument|]
argument_list|,
argument|FragmentShader *fragmentShader
argument_list|,
argument|VertexShader *vertexShader
argument_list|)
specifier|const
block|;
name|rx
operator|::
name|Renderer
operator|*
specifier|const
name|mRenderer
block|;
name|rx
operator|::
name|ShaderExecutable
operator|*
name|mPixelExecutable
block|;
name|rx
operator|::
name|ShaderExecutable
operator|*
name|mVertexExecutable
block|;
name|rx
operator|::
name|ShaderExecutable
operator|*
name|mGeometryExecutable
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
name|IMPLEMENTATION_MAX_VERTEX_TEXTURE_IMAGE_UNITS
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
name|UniformArray
name|mUniforms
block|;
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
