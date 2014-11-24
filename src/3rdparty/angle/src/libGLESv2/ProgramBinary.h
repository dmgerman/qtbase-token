begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
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
file|"common/mathutil.h"
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
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/VertexDataManager.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/DynamicHLSL.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
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
begin_decl_stmt
name|namespace
name|sh
block|{
name|class
name|HLSLBlockEncoder
decl_stmt|;
block|}
end_decl_stmt
begin_include
include|#
directive|include
file|<GLES3/gl3.h>
end_include
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
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|ShaderExecutable
decl_stmt|;
struct_decl|struct
name|TranslatedAttribute
struct_decl|;
name|class
name|UniformStorage
decl_stmt|;
name|class
name|ProgramImpl
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|gl
block|{
struct_decl|struct
name|Caps
struct_decl|;
name|class
name|Shader
decl_stmt|;
name|class
name|InfoLog
decl_stmt|;
name|class
name|AttributeBindings
decl_stmt|;
name|class
name|Buffer
decl_stmt|;
name|class
name|Framebuffer
decl_stmt|;
struct_decl|struct
name|Data
struct_decl|;
comment|// Struct used for correlating uniforms/elements of uniform arrays to handles
struct|struct
name|VariableLocation
block|{
name|VariableLocation
argument_list|()
block|{     }
name|VariableLocation
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
struct|struct
name|LinkedVarying
block|{
name|LinkedVarying
argument_list|()
expr_stmt|;
name|LinkedVarying
argument_list|(
argument|const std::string&name
argument_list|,
argument|GLenum type
argument_list|,
argument|GLsizei size
argument_list|,
argument|const std::string&semanticName
argument_list|,
argument|unsigned int semanticIndex
argument_list|,
argument|unsigned int semanticIndexCount
argument_list|)
empty_stmt|;
comment|// Original GL name
name|std
operator|::
name|string
name|name
expr_stmt|;
name|GLenum
name|type
decl_stmt|;
name|GLsizei
name|size
decl_stmt|;
comment|// DirectX semantic information
name|std
operator|::
name|string
name|semanticName
expr_stmt|;
name|unsigned
name|int
name|semanticIndex
decl_stmt|;
name|unsigned
name|int
name|semanticIndexCount
decl_stmt|;
block|}
struct|;
struct|struct
name|LinkResult
block|{
name|bool
name|linkSuccess
decl_stmt|;
name|Error
name|error
decl_stmt|;
name|LinkResult
argument_list|(
argument|bool linkSuccess
argument_list|,
argument|const Error&error
argument_list|)
empty_stmt|;
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
name|ProgramImpl
operator|*
name|impl
argument_list|)
block|;
operator|~
name|ProgramBinary
argument_list|()
block|;
name|rx
operator|::
name|ProgramImpl
operator|*
name|getImplementation
argument_list|()
block|{
return|return
name|mProgram
return|;
block|}
specifier|const
name|rx
operator|::
name|ProgramImpl
operator|*
name|getImplementation
argument_list|()
specifier|const
block|{
return|return
name|mProgram
return|;
block|}
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
argument_list|,
argument|const Caps&caps
argument_list|)
block|;
name|GLenum
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
name|GLuint
name|getUniformIndex
argument_list|(
argument|std::string name
argument_list|)
block|;
name|GLuint
name|getUniformBlockIndex
argument_list|(
argument|std::string name
argument_list|)
block|;
name|void
name|setUniform1fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *v
argument_list|)
block|;
name|void
name|setUniform2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *v
argument_list|)
block|;
name|void
name|setUniform3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *v
argument_list|)
block|;
name|void
name|setUniform4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *v
argument_list|)
block|;
name|void
name|setUniform1iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
block|;
name|void
name|setUniform2iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
block|;
name|void
name|setUniform3iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
block|;
name|void
name|setUniform4iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
block|;
name|void
name|setUniform1uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *v
argument_list|)
block|;
name|void
name|setUniform2uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *v
argument_list|)
block|;
name|void
name|setUniform3uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *v
argument_list|)
block|;
name|void
name|setUniform4uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *v
argument_list|)
block|;
name|void
name|setUniformMatrix2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|setUniformMatrix3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|setUniformMatrix4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|setUniformMatrix2x3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|setUniformMatrix3x2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|setUniformMatrix2x4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|setUniformMatrix4x2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|setUniformMatrix3x4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|setUniformMatrix4x3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
block|;
name|void
name|getUniformfv
argument_list|(
argument|GLint location
argument_list|,
argument|GLfloat *params
argument_list|)
block|;
name|void
name|getUniformiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|void
name|getUniformuiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLuint *params
argument_list|)
block|;
name|Error
name|applyUniforms
argument_list|()
block|;
name|Error
name|applyUniformBuffers
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|Buffer
operator|*
operator|>
name|boundBuffers
argument_list|,
specifier|const
name|Caps
operator|&
name|caps
argument_list|)
block|;
name|LinkResult
name|load
argument_list|(
argument|InfoLog&infoLog
argument_list|,
argument|GLenum binaryFormat
argument_list|,
argument|const void *binary
argument_list|,
argument|GLsizei length
argument_list|)
block|;
name|Error
name|save
argument_list|(
argument|GLenum *binaryFormat
argument_list|,
argument|void *binary
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
name|LinkResult
name|link
argument_list|(
argument|const Data&data
argument_list|,
argument|InfoLog&infoLog
argument_list|,
argument|const AttributeBindings&attributeBindings
argument_list|,
argument|Shader *fragmentShader
argument_list|,
argument|Shader *vertexShader
argument_list|,
argument|const std::vector<std::string>&transformFeedbackVaryings
argument_list|,
argument|GLenum transformFeedbackBufferMode
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
name|GLint
name|getActiveUniformi
argument_list|(
argument|GLuint index
argument_list|,
argument|GLenum pname
argument_list|)
specifier|const
block|;
name|bool
name|isValidUniformLocation
argument_list|(
argument|GLint location
argument_list|)
specifier|const
block|;
name|LinkedUniform
operator|*
name|getUniformByLocation
argument_list|(
argument|GLint location
argument_list|)
specifier|const
block|;
name|LinkedUniform
operator|*
name|getUniformByName
argument_list|(
argument|const std::string&name
argument_list|)
specifier|const
block|;
name|void
name|getActiveUniformBlockName
argument_list|(
argument|GLuint uniformBlockIndex
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei *length
argument_list|,
argument|GLchar *uniformBlockName
argument_list|)
specifier|const
block|;
name|void
name|getActiveUniformBlockiv
argument_list|(
argument|GLuint uniformBlockIndex
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
specifier|const
block|;
name|GLuint
name|getActiveUniformBlockCount
argument_list|()
specifier|const
block|;
name|GLuint
name|getActiveUniformBlockMaxLength
argument_list|()
specifier|const
block|;
name|UniformBlock
operator|*
name|getUniformBlockByIndex
argument_list|(
argument|GLuint blockIndex
argument_list|)
block|;
name|GLint
name|getFragDataLocation
argument_list|(
argument|const char *name
argument_list|)
specifier|const
block|;
name|size_t
name|getTransformFeedbackVaryingCount
argument_list|()
specifier|const
block|;
specifier|const
name|LinkedVarying
operator|&
name|getTransformFeedbackVarying
argument_list|(
argument|size_t idx
argument_list|)
specifier|const
block|;
name|GLenum
name|getTransformFeedbackBufferMode
argument_list|()
specifier|const
block|;
name|void
name|validate
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|Caps
operator|&
name|caps
argument_list|)
block|;
name|bool
name|validateSamplers
argument_list|(
name|InfoLog
operator|*
name|infoLog
argument_list|,
specifier|const
name|Caps
operator|&
name|caps
argument_list|)
block|;
name|bool
name|isValidated
argument_list|()
specifier|const
block|;
name|void
name|updateSamplerMapping
argument_list|()
block|;
name|unsigned
name|int
name|getSerial
argument_list|()
specifier|const
block|;
name|void
name|initAttributesByLayout
argument_list|()
block|;
name|void
name|sortAttributesByLayout
argument_list|(
argument|rx::TranslatedAttribute attributes[MAX_VERTEX_ATTRIBS]
argument_list|,
argument|int sortedSemanticIndices[MAX_VERTEX_ATTRIBS]
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|linkVaryings
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
name|Shader
operator|*
name|fragmentShader
argument_list|,
name|Shader
operator|*
name|vertexShader
argument_list|)
block|;
specifier|static
name|bool
name|linkValidateUniforms
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|uniformName
argument_list|,
specifier|const
name|sh
operator|::
name|Uniform
operator|&
name|vertexUniform
argument_list|,
specifier|const
name|sh
operator|::
name|Uniform
operator|&
name|fragmentUniform
argument_list|)
block|;
specifier|static
name|bool
name|linkValidateInterfaceBlockFields
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|uniformName
argument_list|,
specifier|const
name|sh
operator|::
name|InterfaceBlockField
operator|&
name|vertexUniform
argument_list|,
specifier|const
name|sh
operator|::
name|InterfaceBlockField
operator|&
name|fragmentUniform
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ProgramBinary
argument_list|)
block|;
name|void
name|reset
argument_list|()
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
specifier|const
name|Shader
operator|*
name|vertexShader
argument_list|)
block|;
name|bool
name|linkUniformBlocks
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|Shader
operator|&
name|vertexShader
argument_list|,
specifier|const
name|Shader
operator|&
name|fragmentShader
argument_list|,
specifier|const
name|Caps
operator|&
name|caps
argument_list|)
block|;
name|bool
name|areMatchingInterfaceBlocks
argument_list|(
name|gl
operator|::
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|sh
operator|::
name|InterfaceBlock
operator|&
name|vertexInterfaceBlock
argument_list|,
specifier|const
name|sh
operator|::
name|InterfaceBlock
operator|&
name|fragmentInterfaceBlock
argument_list|)
block|;
specifier|static
name|bool
name|linkValidateVariablesBase
argument_list|(
argument|InfoLog&infoLog
argument_list|,
argument|const std::string&variableName
argument_list|,
argument|const sh::ShaderVariable&vertexVariable
argument_list|,
argument|const sh::ShaderVariable&fragmentVariable
argument_list|,
argument|bool validatePrecision
argument_list|)
block|;
specifier|static
name|bool
name|linkValidateVaryings
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|varyingName
argument_list|,
specifier|const
name|sh
operator|::
name|Varying
operator|&
name|vertexVarying
argument_list|,
specifier|const
name|sh
operator|::
name|Varying
operator|&
name|fragmentVarying
argument_list|)
block|;
name|bool
name|gatherTransformFeedbackLinkedVaryings
argument_list|(
argument|InfoLog&infoLog
argument_list|,
argument|const std::vector<LinkedVarying>&linkedVaryings
argument_list|,
argument|const std::vector<std::string>&transformFeedbackVaryingNames
argument_list|,
argument|GLenum transformFeedbackBufferMode
argument_list|,
argument|std::vector<LinkedVarying> *outTransformFeedbackLinkedVaryings
argument_list|,
argument|const Caps&caps
argument_list|)
specifier|const
block|;
name|bool
name|assignUniformBlockRegister
argument_list|(
argument|InfoLog&infoLog
argument_list|,
argument|UniformBlock *uniformBlock
argument_list|,
argument|GLenum shader
argument_list|,
argument|unsigned int registerIndex
argument_list|,
argument|const Caps&caps
argument_list|)
block|;
name|void
name|defineOutputVariables
argument_list|(
name|Shader
operator|*
name|fragmentShader
argument_list|)
block|;
name|rx
operator|::
name|ProgramImpl
operator|*
name|mProgram
block|;
name|sh
operator|::
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
block|;
name|int
name|mAttributesByLayout
index|[
name|MAX_VERTEX_ATTRIBS
index|]
block|;
name|std
operator|::
name|map
operator|<
name|int
block|,
name|VariableLocation
operator|>
name|mOutputVariables
block|;
name|bool
name|mValidated
block|;
specifier|const
name|unsigned
name|int
name|mSerial
block|;
specifier|static
name|unsigned
name|int
name|issueSerial
argument_list|()
block|;
specifier|static
name|unsigned
name|int
name|mCurrentSerial
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_PROGRAM_BINARY_H_
end_comment
end_unit
