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
name|LIBANGLE_PROGRAM_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_PROGRAM_H_
define|#
directive|define
name|LIBANGLE_PROGRAM_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Constants.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/RefCountObject.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_include
include|#
directive|include
file|<GLSLANG/ShaderLang.h>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|<set>
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer
decl_stmt|;
name|class
name|Renderer
decl_stmt|;
struct_decl|struct
name|TranslatedAttribute
struct_decl|;
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
struct_decl|struct
name|Data
struct_decl|;
name|class
name|ResourceManager
decl_stmt|;
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
name|UniformBlock
struct_decl|;
struct_decl|struct
name|LinkedUniform
struct_decl|;
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|g_fakepath
decl_stmt|;
name|class
name|AttributeBindings
block|{
name|public
label|:
name|AttributeBindings
argument_list|()
expr_stmt|;
operator|~
name|AttributeBindings
argument_list|()
expr_stmt|;
name|void
name|bindAttributeLocation
parameter_list|(
name|GLuint
name|index
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|int
name|getAttributeBinding
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>
name|mAttributeBinding
index|[
name|MAX_VERTEX_ATTRIBS
index|]
expr_stmt|;
block|}
empty_stmt|;
name|class
name|InfoLog
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|InfoLog
argument_list|()
block|;
operator|~
name|InfoLog
argument_list|()
block|;
name|int
name|getLength
argument_list|()
specifier|const
block|;
name|void
name|getLog
argument_list|(
argument|GLsizei bufSize
argument_list|,
argument|GLsizei *length
argument_list|,
argument|char *infoLog
argument_list|)
block|;
name|void
name|appendSanitized
argument_list|(
specifier|const
name|char
operator|*
name|message
argument_list|)
block|;
name|void
name|append
argument_list|(
specifier|const
name|char
operator|*
name|info
argument_list|,
operator|...
argument_list|)
block|;
name|void
name|reset
argument_list|()
block|;
name|private
operator|:
name|char
operator|*
name|mInfoLog
block|; }
decl_stmt|;
comment|// Struct used for correlating uniforms/elements of uniform arrays to handles
struct|struct
name|VariableLocation
block|{
name|VariableLocation
argument_list|()
expr_stmt|;
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
name|class
name|Program
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|Program
argument_list|(
argument|rx::ProgramImpl *impl
argument_list|,
argument|ResourceManager *manager
argument_list|,
argument|GLuint handle
argument_list|)
block|;
operator|~
name|Program
argument_list|()
block|;
name|GLuint
name|id
argument_list|()
specifier|const
block|{
return|return
name|mHandle
return|;
block|}
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
name|bool
name|attachShader
argument_list|(
name|Shader
operator|*
name|shader
argument_list|)
block|;
name|bool
name|detachShader
argument_list|(
name|Shader
operator|*
name|shader
argument_list|)
block|;
name|int
name|getAttachedShadersCount
argument_list|()
specifier|const
block|;
name|void
name|bindAttributeLocation
argument_list|(
argument|GLuint index
argument_list|,
argument|const char *name
argument_list|)
block|;
name|Error
name|link
argument_list|(
specifier|const
name|Data
operator|&
name|data
argument_list|)
block|;
name|bool
name|isLinked
argument_list|()
block|;
name|Error
name|loadBinary
argument_list|(
argument|GLenum binaryFormat
argument_list|,
argument|const void *binary
argument_list|,
argument|GLsizei length
argument_list|)
block|;
name|Error
name|saveBinary
argument_list|(
argument|GLenum *binaryFormat
argument_list|,
argument|void *binary
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei *length
argument_list|)
specifier|const
block|;
name|GLint
name|getBinaryLength
argument_list|()
specifier|const
block|;
name|int
name|getInfoLogLength
argument_list|()
specifier|const
block|;
name|void
name|getInfoLog
argument_list|(
argument|GLsizei bufSize
argument_list|,
argument|GLsizei *length
argument_list|,
argument|char *infoLog
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
name|GLuint
name|getAttributeLocation
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
block|;
name|int
name|getSemanticIndex
argument_list|(
argument|int attributeIndex
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
name|getFragDataLocation
argument_list|(
argument|const std::string&name
argument_list|)
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
block|;
name|GLint
name|getActiveUniformCount
argument_list|()
block|;
name|GLint
name|getActiveUniformMaxLength
argument_list|()
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
name|GLint
name|getUniformLocation
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
block|;
name|GLuint
name|getUniformIndex
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
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
name|gl
operator|::
name|Data
operator|&
name|data
argument_list|)
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
block|;
name|GLint
name|getActiveUniformBlockMaxLength
argument_list|()
block|;
name|GLuint
name|getUniformBlockIndex
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
block|;
name|void
name|bindUniformBlock
argument_list|(
argument|GLuint uniformBlockIndex
argument_list|,
argument|GLuint uniformBlockBinding
argument_list|)
block|;
name|GLuint
name|getUniformBlockBinding
argument_list|(
argument|GLuint uniformBlockIndex
argument_list|)
specifier|const
block|;
specifier|const
name|UniformBlock
operator|*
name|getUniformBlockByIndex
argument_list|(
argument|GLuint index
argument_list|)
specifier|const
block|;
name|void
name|setTransformFeedbackVaryings
argument_list|(
argument|GLsizei count
argument_list|,
argument|const GLchar *const *varyings
argument_list|,
argument|GLenum bufferMode
argument_list|)
block|;
name|void
name|getTransformFeedbackVarying
argument_list|(
argument|GLuint index
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLsizei *length
argument_list|,
argument|GLsizei *size
argument_list|,
argument|GLenum *type
argument_list|,
argument|GLchar *name
argument_list|)
specifier|const
block|;
name|GLsizei
name|getTransformFeedbackVaryingCount
argument_list|()
specifier|const
block|;
name|GLsizei
name|getTransformFeedbackVaryingMaxLength
argument_list|()
specifier|const
block|;
name|GLenum
name|getTransformFeedbackBufferMode
argument_list|()
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
name|void
name|addRef
argument_list|()
block|;
name|void
name|release
argument_list|()
block|;
name|unsigned
name|int
name|getRefCount
argument_list|()
specifier|const
block|;
name|void
name|flagForDeletion
argument_list|()
block|;
name|bool
name|isFlaggedForDeletion
argument_list|()
specifier|const
block|;
name|void
name|validate
argument_list|(
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
name|private
operator|:
name|void
name|unlink
argument_list|(
argument|bool destroy = false
argument_list|)
block|;
name|void
name|resetUniformBlockBindings
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
name|Shader
operator|*
name|mFragmentShader
block|;
name|Shader
operator|*
name|mVertexShader
block|;
name|AttributeBindings
name|mAttributeBindings
block|;
name|GLuint
name|mUniformBlockBindings
index|[
name|IMPLEMENTATION_MAX_COMBINED_SHADER_UNIFORM_BUFFERS
index|]
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|mTransformFeedbackVaryings
block|;
name|GLenum
name|mTransformFeedbackBufferMode
block|;
name|bool
name|mLinked
block|;
name|bool
name|mDeleteStatus
block|;
comment|// Flag to indicate that the program can be deleted when no longer in use
name|unsigned
name|int
name|mRefCount
block|;
name|ResourceManager
operator|*
name|mResourceManager
block|;
specifier|const
name|GLuint
name|mHandle
block|;
name|InfoLog
name|mInfoLog
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_PROGRAM_H_
end_comment
end_unit
