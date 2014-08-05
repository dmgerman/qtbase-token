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
file|"libGLESv2/DynamicHLSL.h"
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
name|class
name|UniformStorage
decl_stmt|;
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
name|class
name|Buffer
decl_stmt|;
name|class
name|Framebuffer
decl_stmt|;
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
name|getPixelExecutableForFramebuffer
argument_list|(
specifier|const
name|Framebuffer
operator|*
name|fbo
argument_list|)
block|;
name|rx
operator|::
name|ShaderExecutable
operator|*
name|getPixelExecutableForOutputLayout
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|GLenum
operator|>
operator|&
name|outputLayout
argument_list|)
block|;
name|rx
operator|::
name|ShaderExecutable
operator|*
name|getVertexExecutableForInputLayout
argument_list|(
argument|const VertexFormat inputLayout[MAX_VERTEX_ATTRIBS]
argument_list|)
block|;
name|rx
operator|::
name|ShaderExecutable
operator|*
name|getGeometryExecutable
argument_list|()
specifier|const
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
name|bool
name|getUniformuiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei *bufSize
argument_list|,
argument|GLuint *params
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
argument_list|)
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
argument|InfoLog&infoLog
argument_list|,
argument|const AttributeBindings&attributeBindings
argument_list|,
argument|FragmentShader *fragmentShader
argument_list|,
argument|VertexShader *vertexShader
argument_list|,
argument|const std::vector<std::string>& transformFeedbackVaryings
argument_list|,
argument|GLenum transformFeedbackBufferMode
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
name|int
name|getShaderVersion
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
specifier|const
name|std
operator|::
name|vector
operator|<
name|LinkedUniform
operator|*
operator|>
operator|&
name|getUniforms
argument_list|()
specifier|const
block|{
return|return
name|mUniforms
return|;
block|}
specifier|const
name|rx
operator|::
name|UniformStorage
operator|&
name|getVertexUniformStorage
argument_list|()
specifier|const
block|{
return|return
operator|*
name|mVertexUniformStorage
return|;
block|}
specifier|const
name|rx
operator|::
name|UniformStorage
operator|&
name|getFragmentUniformStorage
argument_list|()
specifier|const
block|{
return|return
operator|*
name|mFragmentUniformStorage
return|;
block|}
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ProgramBinary
argument_list|)
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
name|void
name|reset
argument_list|()
block|;
name|bool
name|linkVaryings
argument_list|(
name|InfoLog
operator|&
name|infoLog
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
name|template
operator|<
name|class
name|ShaderVarType
operator|>
name|bool
name|linkValidateFields
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
name|varName
argument_list|,
specifier|const
name|ShaderVarType
operator|&
name|vertexVar
argument_list|,
specifier|const
name|ShaderVarType
operator|&
name|fragmentVar
argument_list|)
block|;
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
name|bool
name|linkValidateVariables
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
name|bool
name|linkValidateVariables
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
name|linkValidateVariables
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
name|bool
name|linkUniforms
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|VertexShader
operator|&
name|vertexShader
argument_list|,
specifier|const
name|FragmentShader
operator|&
name|fragmentShader
argument_list|)
block|;
name|void
name|defineUniformBase
argument_list|(
argument|GLenum shader
argument_list|,
argument|const sh::Uniform&uniform
argument_list|,
argument|unsigned int uniformRegister
argument_list|)
block|;
name|void
name|defineUniform
argument_list|(
argument|GLenum shader
argument_list|,
argument|const sh::Uniform&uniform
argument_list|,
argument|const std::string&fullName
argument_list|,
argument|sh::HLSLBlockEncoder *encoder
argument_list|)
block|;
name|bool
name|indexSamplerUniform
argument_list|(
specifier|const
name|LinkedUniform
operator|&
name|uniform
argument_list|,
name|InfoLog
operator|&
name|infoLog
argument_list|)
block|;
name|bool
name|indexUniforms
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|)
block|;
specifier|static
name|bool
name|assignSamplers
argument_list|(
argument|unsigned int startSamplerIndex
argument_list|,
argument|GLenum samplerType
argument_list|,
argument|unsigned int samplerCount
argument_list|,
argument|Sampler *outArray
argument_list|,
argument|GLuint *usedRange
argument_list|,
argument|unsigned int limit
argument_list|)
block|;
name|bool
name|areMatchingInterfaceBlocks
argument_list|(
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
name|bool
name|linkUniformBlocks
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|VertexShader
operator|&
name|vertexShader
argument_list|,
specifier|const
name|FragmentShader
operator|&
name|fragmentShader
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
argument_list|)
specifier|const
block|;
name|void
name|defineUniformBlockMembers
argument_list|(
argument|const std::vector<sh::InterfaceBlockField>&fields
argument_list|,
argument|const std::string&prefix
argument_list|,
argument|int blockIndex
argument_list|,
argument|sh::BlockLayoutEncoder *encoder
argument_list|,
argument|std::vector<unsigned int> *blockUniformIndexes
argument_list|)
block|;
name|bool
name|defineUniformBlock
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|Shader
operator|&
name|shader
argument_list|,
specifier|const
name|sh
operator|::
name|InterfaceBlock
operator|&
name|interfaceBlock
argument_list|)
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
argument_list|)
block|;
name|void
name|defineOutputVariables
argument_list|(
name|FragmentShader
operator|*
name|fragmentShader
argument_list|)
block|;
name|void
name|initializeUniformStorage
argument_list|()
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|setUniform
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const T* v
argument_list|,
argument|GLenum targetUniformType
argument_list|)
block|;
name|template
operator|<
name|int
name|cols
block|,
name|int
name|rows
operator|>
name|void
name|setUniformMatrixfv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|,
argument|GLenum targetUniformType
argument_list|)
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|getUniformv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei *bufSize
argument_list|,
argument|T *params
argument_list|,
argument|GLenum uniformType
argument_list|)
block|;
name|class
name|VertexExecutable
block|{
name|public
operator|:
name|VertexExecutable
argument_list|(
argument|const VertexFormat inputLayout[MAX_VERTEX_ATTRIBS]
argument_list|,
argument|const GLenum signature[MAX_VERTEX_ATTRIBS]
argument_list|,
argument|rx::ShaderExecutable *shaderExecutable
argument_list|)
block|;
operator|~
name|VertexExecutable
argument_list|()
block|;
name|bool
name|matchesSignature
argument_list|(
argument|const GLenum convertedLayout[MAX_VERTEX_ATTRIBS]
argument_list|)
specifier|const
block|;
specifier|const
name|VertexFormat
operator|*
name|inputs
argument_list|()
specifier|const
block|{
return|return
name|mInputs
return|;
block|}
specifier|const
name|GLenum
operator|*
name|signature
argument_list|()
specifier|const
block|{
return|return
name|mSignature
return|;
block|}
name|rx
operator|::
name|ShaderExecutable
operator|*
name|shaderExecutable
argument_list|()
specifier|const
block|{
return|return
name|mShaderExecutable
return|;
block|}
name|private
operator|:
name|VertexFormat
name|mInputs
index|[
name|MAX_VERTEX_ATTRIBS
index|]
block|;
name|GLenum
name|mSignature
index|[
name|MAX_VERTEX_ATTRIBS
index|]
block|;
name|rx
operator|::
name|ShaderExecutable
operator|*
name|mShaderExecutable
block|;     }
block|;
name|class
name|PixelExecutable
block|{
name|public
operator|:
name|PixelExecutable
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|GLenum
operator|>
operator|&
name|outputSignature
argument_list|,
name|rx
operator|::
name|ShaderExecutable
operator|*
name|shaderExecutable
argument_list|)
block|;
operator|~
name|PixelExecutable
argument_list|()
block|;
comment|// FIXME(geofflang): Work around NVIDIA driver bug by repacking buffers
name|bool
name|matchesSignature
argument_list|(
argument|const std::vector<GLenum>&signature
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
comment|/* mOutputSignature == signature; */
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|GLenum
operator|>
operator|&
name|outputSignature
argument_list|()
specifier|const
block|{
return|return
name|mOutputSignature
return|;
block|}
name|rx
operator|::
name|ShaderExecutable
operator|*
name|shaderExecutable
argument_list|()
specifier|const
block|{
return|return
name|mShaderExecutable
return|;
block|}
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|GLenum
operator|>
name|mOutputSignature
block|;
name|rx
operator|::
name|ShaderExecutable
operator|*
name|mShaderExecutable
block|;     }
block|;
name|rx
operator|::
name|Renderer
operator|*
specifier|const
name|mRenderer
block|;
name|DynamicHLSL
operator|*
name|mDynamicHLSL
block|;
name|std
operator|::
name|string
name|mVertexHLSL
block|;
name|rx
operator|::
name|D3DWorkaroundType
name|mVertexWorkarounds
block|;
name|std
operator|::
name|vector
operator|<
name|VertexExecutable
operator|*
operator|>
name|mVertexExecutables
block|;
name|std
operator|::
name|string
name|mPixelHLSL
block|;
name|rx
operator|::
name|D3DWorkaroundType
name|mPixelWorkarounds
block|;
name|bool
name|mUsesFragDepth
block|;
name|std
operator|::
name|vector
operator|<
name|PixelShaderOuputVariable
operator|>
name|mPixelShaderKey
block|;
name|std
operator|::
name|vector
operator|<
name|PixelExecutable
operator|*
operator|>
name|mPixelExecutables
block|;
name|rx
operator|::
name|ShaderExecutable
operator|*
name|mGeometryExecutable
block|;
name|sh
operator|::
name|Attribute
name|mLinkedAttribute
index|[
name|MAX_VERTEX_ATTRIBS
index|]
block|;
name|sh
operator|::
name|Attribute
name|mShaderAttributes
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
name|GLenum
name|mTransformFeedbackBufferMode
block|;
name|std
operator|::
name|vector
operator|<
name|LinkedVarying
operator|>
name|mTransformFeedbackLinkedVaryings
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
name|int
name|mShaderVersion
block|;
name|bool
name|mDirtySamplerMapping
block|;
name|std
operator|::
name|vector
operator|<
name|LinkedUniform
operator|*
operator|>
name|mUniforms
block|;
name|std
operator|::
name|vector
operator|<
name|UniformBlock
operator|*
operator|>
name|mUniformBlocks
block|;
name|std
operator|::
name|vector
operator|<
name|VariableLocation
operator|>
name|mUniformIndex
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
name|rx
operator|::
name|UniformStorage
operator|*
name|mVertexUniformStorage
block|;
name|rx
operator|::
name|UniformStorage
operator|*
name|mFragmentUniformStorage
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
