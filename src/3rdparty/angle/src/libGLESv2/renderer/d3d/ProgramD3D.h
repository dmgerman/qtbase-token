begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// ProgramD3D.h: Defines the rx::ProgramD3D class which implements rx::ProgramImpl.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_PROGRAMD3D_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_PROGRAMD3D_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_PROGRAMD3D_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/ProgramImpl.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Workarounds.h"
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
name|gl
block|{
struct_decl|struct
name|LinkedUniform
struct_decl|;
struct_decl|struct
name|VariableLocation
struct_decl|;
struct_decl|struct
name|VertexFormat
struct_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RendererD3D
decl_stmt|;
name|class
name|UniformStorage
decl_stmt|;
name|class
name|ProgramD3D
range|:
name|public
name|ProgramImpl
block|{
name|public
operator|:
name|ProgramD3D
argument_list|(
name|RendererD3D
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|ProgramD3D
argument_list|()
block|;
specifier|static
name|ProgramD3D
operator|*
name|makeProgramD3D
argument_list|(
name|ProgramImpl
operator|*
name|impl
argument_list|)
block|;
specifier|static
specifier|const
name|ProgramD3D
operator|*
name|makeProgramD3D
argument_list|(
specifier|const
name|ProgramImpl
operator|*
name|impl
argument_list|)
block|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|PixelShaderOutputVariable
operator|>
operator|&
name|getPixelShaderKey
argument_list|()
block|{
return|return
name|mPixelShaderKey
return|;
block|}
name|int
name|getShaderVersion
argument_list|()
specifier|const
block|{
return|return
name|mShaderVersion
return|;
block|}
name|GLenum
name|getTransformFeedbackBufferMode
argument_list|()
specifier|const
block|{
return|return
name|mTransformFeedbackBufferMode
return|;
block|}
name|GLint
name|getSamplerMapping
argument_list|(
argument|gl::SamplerType type
argument_list|,
argument|unsigned int samplerIndex
argument_list|,
argument|const gl::Caps&caps
argument_list|)
specifier|const
block|;
name|GLenum
name|getSamplerTextureType
argument_list|(
argument|gl::SamplerType type
argument_list|,
argument|unsigned int samplerIndex
argument_list|)
specifier|const
block|;
name|GLint
name|getUsedSamplerRange
argument_list|(
argument|gl::SamplerType type
argument_list|)
specifier|const
block|;
name|void
name|updateSamplerMapping
argument_list|()
block|;
name|bool
name|validateSamplers
argument_list|(
name|gl
operator|::
name|InfoLog
operator|*
name|infoLog
argument_list|,
specifier|const
name|gl
operator|::
name|Caps
operator|&
name|caps
argument_list|)
block|;
name|bool
name|usesPointSize
argument_list|()
specifier|const
block|{
return|return
name|mUsesPointSize
return|;
block|}
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
name|GLenum
name|getBinaryFormat
argument_list|()
block|{
return|return
name|GL_PROGRAM_BINARY_ANGLE
return|;
block|}
name|gl
operator|::
name|LinkResult
name|load
argument_list|(
name|gl
operator|::
name|InfoLog
operator|&
name|infoLog
argument_list|,
name|gl
operator|::
name|BinaryInputStream
operator|*
name|stream
argument_list|)
block|;
name|gl
operator|::
name|Error
name|save
argument_list|(
name|gl
operator|::
name|BinaryOutputStream
operator|*
name|stream
argument_list|)
block|;
name|gl
operator|::
name|Error
name|getPixelExecutableForFramebuffer
argument_list|(
specifier|const
name|gl
operator|::
name|Framebuffer
operator|*
name|fbo
argument_list|,
name|ShaderExecutable
operator|*
operator|*
name|outExectuable
argument_list|)
block|;
name|gl
operator|::
name|Error
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
argument_list|,
name|ShaderExecutable
operator|*
operator|*
name|outExectuable
argument_list|)
block|;
name|gl
operator|::
name|Error
name|getVertexExecutableForInputLayout
argument_list|(
argument|const gl::VertexFormat inputLayout[gl::MAX_VERTEX_ATTRIBS]
argument_list|,
argument|ShaderExecutable **outExectuable
argument_list|)
block|;
name|ShaderExecutable
operator|*
name|getGeometryExecutable
argument_list|()
specifier|const
block|{
return|return
name|mGeometryExecutable
return|;
block|}
name|gl
operator|::
name|LinkResult
name|compileProgramExecutables
argument_list|(
argument|gl::InfoLog&infoLog
argument_list|,
argument|gl::Shader *fragmentShader
argument_list|,
argument|gl::Shader *vertexShader
argument_list|,
argument|int registers
argument_list|)
block|;
name|gl
operator|::
name|LinkResult
name|link
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|gl::InfoLog&infoLog
argument_list|,
argument|gl::Shader *fragmentShader
argument_list|,
argument|gl::Shader *vertexShader
argument_list|,
argument|const std::vector<std::string>&transformFeedbackVaryings
argument_list|,
argument|GLenum transformFeedbackBufferMode
argument_list|,
argument|int *registers
argument_list|,
argument|std::vector<gl::LinkedVarying> *linkedVaryings
argument_list|,
argument|std::map<int
argument_list|,
argument|gl::VariableLocation> *outputVariables
argument_list|)
block|;
name|void
name|getInputLayoutSignature
argument_list|(
argument|const gl::VertexFormat inputLayout[]
argument_list|,
argument|GLenum signature[]
argument_list|)
specifier|const
block|;
name|void
name|initializeUniformStorage
argument_list|()
block|;
name|gl
operator|::
name|Error
name|applyUniforms
argument_list|()
block|;
name|gl
operator|::
name|Error
name|applyUniformBuffers
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|gl
operator|::
name|Buffer
operator|*
operator|>
name|boundBuffers
argument_list|,
specifier|const
name|gl
operator|::
name|Caps
operator|&
name|caps
argument_list|)
block|;
name|bool
name|assignUniformBlockRegister
argument_list|(
argument|gl::InfoLog&infoLog
argument_list|,
argument|gl::UniformBlock *uniformBlock
argument_list|,
argument|GLenum shader
argument_list|,
argument|unsigned int registerIndex
argument_list|,
argument|const gl::Caps&caps
argument_list|)
block|;
name|void
name|dirtyAllUniforms
argument_list|()
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
specifier|const
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
name|bool
name|linkUniforms
argument_list|(
name|gl
operator|::
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|gl
operator|::
name|Shader
operator|&
name|vertexShader
argument_list|,
specifier|const
name|gl
operator|::
name|Shader
operator|&
name|fragmentShader
argument_list|,
specifier|const
name|gl
operator|::
name|Caps
operator|&
name|caps
argument_list|)
block|;
name|bool
name|defineUniformBlock
argument_list|(
name|gl
operator|::
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|gl
operator|::
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
argument_list|,
specifier|const
name|gl
operator|::
name|Caps
operator|&
name|caps
argument_list|)
block|;
name|void
name|reset
argument_list|()
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ProgramD3D
argument_list|)
block|;
name|class
name|VertexExecutable
block|{
name|public
operator|:
name|VertexExecutable
argument_list|(
argument|const gl::VertexFormat inputLayout[gl::MAX_VERTEX_ATTRIBS]
argument_list|,
argument|const GLenum signature[gl::MAX_VERTEX_ATTRIBS]
argument_list|,
argument|ShaderExecutable *shaderExecutable
argument_list|)
block|;
operator|~
name|VertexExecutable
argument_list|()
block|;
name|bool
name|matchesSignature
argument_list|(
argument|const GLenum convertedLayout[gl::MAX_VERTEX_ATTRIBS]
argument_list|)
specifier|const
block|;
specifier|const
name|gl
operator|::
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
name|gl
operator|::
name|VertexFormat
name|mInputs
index|[
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
index|]
block|;
name|GLenum
name|mSignature
index|[
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
index|]
block|;
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
name|ShaderExecutable
operator|*
name|shaderExecutable
argument_list|)
block|;
operator|~
name|PixelExecutable
argument_list|()
block|;
name|bool
name|matchesSignature
argument_list|(
argument|const std::vector<GLenum>&signature
argument_list|)
specifier|const
block|{
return|return
name|mOutputSignature
operator|==
name|signature
return|;
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
name|ShaderExecutable
operator|*
name|mShaderExecutable
block|;     }
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
name|GLenum
name|textureType
block|;     }
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
argument|const sh::ShaderVariable&uniform
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
name|gl
operator|::
name|LinkedUniform
operator|&
name|uniform
argument_list|,
name|gl
operator|::
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|gl
operator|::
name|Caps
operator|&
name|caps
argument_list|)
block|;
name|bool
name|indexUniforms
argument_list|(
name|gl
operator|::
name|InfoLog
operator|&
name|infoLog
argument_list|,
specifier|const
name|gl
operator|::
name|Caps
operator|&
name|caps
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
argument|std::vector<Sampler>&outSamplers
argument_list|,
argument|GLuint *outUsedRange
argument_list|)
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
name|void
name|getUniformv
argument_list|(
argument|GLint location
argument_list|,
argument|T *params
argument_list|,
argument|GLenum uniformType
argument_list|)
block|;
name|template
operator|<
name|typename
name|VarT
operator|>
name|void
name|defineUniformBlockMembers
argument_list|(
argument|const std::vector<VarT>&fields
argument_list|,
argument|const std::string&prefix
argument_list|,
argument|int blockIndex
argument_list|,
argument|sh::BlockLayoutEncoder *encoder
argument_list|,
argument|std::vector<unsigned int> *blockUniformIndexes
argument_list|,
argument|bool inRowMajorLayout
argument_list|)
block|;
name|RendererD3D
operator|*
name|mRenderer
block|;
name|DynamicHLSL
operator|*
name|mDynamicHLSL
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
name|vector
operator|<
name|PixelExecutable
operator|*
operator|>
name|mPixelExecutables
block|;
name|ShaderExecutable
operator|*
name|mGeometryExecutable
block|;
name|std
operator|::
name|string
name|mVertexHLSL
block|;
name|D3DWorkaroundType
name|mVertexWorkarounds
block|;
name|std
operator|::
name|string
name|mPixelHLSL
block|;
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
name|PixelShaderOutputVariable
operator|>
name|mPixelShaderKey
block|;
name|bool
name|mUsesPointSize
block|;
name|UniformStorage
operator|*
name|mVertexUniformStorage
block|;
name|UniformStorage
operator|*
name|mFragmentUniformStorage
block|;
name|GLenum
name|mTransformFeedbackBufferMode
block|;
name|std
operator|::
name|vector
operator|<
name|Sampler
operator|>
name|mSamplersPS
block|;
name|std
operator|::
name|vector
operator|<
name|Sampler
operator|>
name|mSamplersVS
block|;
name|GLuint
name|mUsedVertexSamplerRange
block|;
name|GLuint
name|mUsedPixelSamplerRange
block|;
name|bool
name|mDirtySamplerMapping
block|;
name|int
name|mShaderVersion
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_PROGRAMD3D_H_
end_comment
end_unit
