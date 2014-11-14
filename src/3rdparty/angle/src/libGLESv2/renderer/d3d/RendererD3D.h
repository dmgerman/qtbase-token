begin_unit
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
comment|// RendererD3D.h: Defines a back-end specific class for the DirectX renderer.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_RENDERERD3D_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_RENDERERD3D_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_RENDERERD3D_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Renderer.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Data.h"
end_include
begin_comment
comment|//FIXME(jmadill): std::array is currently prohibited by Chromium style guide
end_comment
begin_include
include|#
directive|include
file|<array>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|InfoLog
decl_stmt|;
struct_decl|struct
name|LinkedVarying
struct_decl|;
name|class
name|Texture
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|TextureStorage
decl_stmt|;
name|class
name|VertexBuffer
decl_stmt|;
name|class
name|IndexBuffer
decl_stmt|;
name|class
name|ShaderExecutable
decl_stmt|;
name|class
name|SwapChain
decl_stmt|;
name|class
name|RenderTarget
decl_stmt|;
name|class
name|Image
decl_stmt|;
name|class
name|TextureStorage
decl_stmt|;
name|class
name|UniformStorage
decl_stmt|;
name|class
name|RendererD3D
range|:
name|public
name|Renderer
block|{
name|public
operator|:
name|explicit
name|RendererD3D
argument_list|(
name|egl
operator|::
name|Display
operator|*
name|display
argument_list|)
block|;
name|virtual
operator|~
name|RendererD3D
argument_list|()
block|;
specifier|static
name|RendererD3D
operator|*
name|makeRendererD3D
argument_list|(
name|Renderer
operator|*
name|renderer
argument_list|)
block|;
name|gl
operator|::
name|Error
name|drawArrays
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum mode
argument_list|,
argument|GLint first
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|drawElements
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum mode
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid *indices
argument_list|,
argument|GLsizei instances
argument_list|,
argument|const RangeUI&indexRange
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|clear
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLbitfield mask
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|clearBufferfv
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum buffer
argument_list|,
argument|int drawbuffer
argument_list|,
argument|const GLfloat *values
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|clearBufferuiv
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum buffer
argument_list|,
argument|int drawbuffer
argument_list|,
argument|const GLuint *values
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|clearBufferiv
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum buffer
argument_list|,
argument|int drawbuffer
argument_list|,
argument|const GLint *values
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|clearBufferfi
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum buffer
argument_list|,
argument|GLint drawbuffer
argument_list|,
argument|GLfloat depth
argument_list|,
argument|GLint stencil
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|readPixels
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLsizei *bufSize
argument_list|,
argument|void* pixels
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|blitFramebuffer
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLint srcX0
argument_list|,
argument|GLint srcY0
argument_list|,
argument|GLint srcX1
argument_list|,
argument|GLint srcY1
argument_list|,
argument|GLint dstX0
argument_list|,
argument|GLint dstY0
argument_list|,
argument|GLint dstX1
argument_list|,
argument|GLint dstY1
argument_list|,
argument|GLbitfield mask
argument_list|,
argument|GLenum filter
argument_list|)
name|override
block|;
comment|// Direct3D Specific methods
name|virtual
name|SwapChain
operator|*
name|createSwapChain
argument_list|(
argument|NativeWindow nativeWindow
argument_list|,
argument|HANDLE shareHandle
argument_list|,
argument|GLenum backBufferFormat
argument_list|,
argument|GLenum depthBufferFormat
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|generateSwizzle
argument_list|(
name|gl
operator|::
name|Texture
operator|*
name|texture
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|setSamplerState
argument_list|(
argument|gl::SamplerType type
argument_list|,
argument|int index
argument_list|,
argument|gl::Texture *texture
argument_list|,
argument|const gl::SamplerState&sampler
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|setTexture
argument_list|(
argument|gl::SamplerType type
argument_list|,
argument|int index
argument_list|,
argument|gl::Texture *texture
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|setUniformBuffers
argument_list|(
specifier|const
name|gl
operator|::
name|Buffer
operator|*
name|vertexUniformBuffers
index|[]
argument_list|,
specifier|const
name|gl
operator|::
name|Buffer
operator|*
name|fragmentUniformBuffers
index|[]
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|setRasterizerState
argument_list|(
specifier|const
name|gl
operator|::
name|RasterizerState
operator|&
name|rasterState
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|setBlendState
argument_list|(
argument|const gl::Framebuffer *framebuffer
argument_list|,
argument|const gl::BlendState&blendState
argument_list|,
argument|const gl::ColorF&blendColor
argument_list|,
argument|unsigned int sampleMask
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|setDepthStencilState
argument_list|(
argument|const gl::DepthStencilState&depthStencilState
argument_list|,
argument|int stencilRef
argument_list|,
argument|int stencilBackRef
argument_list|,
argument|bool frontFaceCCW
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setScissorRectangle
argument_list|(
argument|const gl::Rectangle&scissor
argument_list|,
argument|bool enabled
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setViewport
argument_list|(
argument|const gl::Rectangle&viewport
argument_list|,
argument|float zNear
argument_list|,
argument|float zFar
argument_list|,
argument|GLenum drawMode
argument_list|,
argument|GLenum frontFace
argument_list|,
argument|bool ignoreViewport
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|applyRenderTarget
argument_list|(
specifier|const
name|gl
operator|::
name|Framebuffer
operator|*
name|frameBuffer
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|applyShaders
argument_list|(
argument|gl::ProgramBinary *programBinary
argument_list|,
argument|const gl::VertexFormat inputLayout[]
argument_list|,
argument|const gl::Framebuffer *framebuffer
argument_list|,
argument|bool rasterizerDiscard
argument_list|,
argument|bool transformFeedbackActive
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|applyUniforms
argument_list|(
specifier|const
name|ProgramImpl
operator|&
name|program
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|gl
operator|::
name|LinkedUniform
operator|*
operator|>
operator|&
name|uniformArray
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|applyPrimitiveType
argument_list|(
argument|GLenum primitiveType
argument_list|,
argument|GLsizei elementCount
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|applyVertexBuffer
argument_list|(
argument|const gl::State&state
argument_list|,
argument|GLint first
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|applyIndexBuffer
argument_list|(
argument|const GLvoid *indices
argument_list|,
argument|gl::Buffer *elementArrayBuffer
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum mode
argument_list|,
argument|GLenum type
argument_list|,
argument|TranslatedIndexData *indexInfo
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|applyTransformFeedbackBuffers
argument_list|(
specifier|const
name|gl
operator|::
name|State
operator|&
name|state
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|markAllStateDirty
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|int
name|getReservedVertexUniformVectors
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|int
name|getReservedFragmentUniformVectors
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|int
name|getReservedVertexUniformBuffers
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|int
name|getReservedFragmentUniformBuffers
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|getShareHandleSupport
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|getPostSubBufferSupport
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|// Pixel operations
name|virtual
name|gl
operator|::
name|Error
name|copyImage2D
argument_list|(
argument|gl::Framebuffer *framebuffer
argument_list|,
argument|const gl::Rectangle&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|TextureStorage *storage
argument_list|,
argument|GLint level
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|copyImageCube
argument_list|(
argument|gl::Framebuffer *framebuffer
argument_list|,
argument|const gl::Rectangle&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|TextureStorage *storage
argument_list|,
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|copyImage3D
argument_list|(
argument|gl::Framebuffer *framebuffer
argument_list|,
argument|const gl::Rectangle&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zOffset
argument_list|,
argument|TextureStorage *storage
argument_list|,
argument|GLint level
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|copyImage2DArray
argument_list|(
argument|gl::Framebuffer *framebuffer
argument_list|,
argument|const gl::Rectangle&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zOffset
argument_list|,
argument|TextureStorage *storage
argument_list|,
argument|GLint level
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|readPixels
argument_list|(
argument|const gl::Framebuffer *framebuffer
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLuint outputPitch
argument_list|,
argument|const gl::PixelPackState&pack
argument_list|,
argument|uint8_t *pixels
argument_list|)
operator|=
literal|0
block|;
comment|// RenderTarget creation
name|virtual
name|gl
operator|::
name|Error
name|createRenderTarget
argument_list|(
argument|SwapChain *swapChain
argument_list|,
argument|bool depth
argument_list|,
argument|RenderTarget **outRT
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|createRenderTarget
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei samples
argument_list|,
argument|RenderTarget **outRT
argument_list|)
operator|=
literal|0
block|;
comment|// Shader operations
name|virtual
name|void
name|releaseShaderCompiler
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|loadExecutable
argument_list|(
argument|const void *function
argument_list|,
argument|size_t length
argument_list|,
argument|ShaderType type
argument_list|,
argument|const std::vector<gl::LinkedVarying>&transformFeedbackVaryings
argument_list|,
argument|bool separatedOutputBuffers
argument_list|,
argument|ShaderExecutable **outExecutable
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|compileToExecutable
argument_list|(
argument|gl::InfoLog&infoLog
argument_list|,
argument|const std::string&shaderHLSL
argument_list|,
argument|ShaderType type
argument_list|,
argument|const std::vector<gl::LinkedVarying>&transformFeedbackVaryings
argument_list|,
argument|bool separatedOutputBuffers
argument_list|,
argument|D3DWorkaroundType workaround
argument_list|,
argument|ShaderExecutable **outExectuable
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|UniformStorage
operator|*
name|createUniformStorage
argument_list|(
argument|size_t storageSize
argument_list|)
operator|=
literal|0
block|;
comment|// Image operations
name|virtual
name|Image
operator|*
name|createImage
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|generateMipmap
argument_list|(
name|Image
operator|*
name|dest
argument_list|,
name|Image
operator|*
name|source
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|TextureStorage
operator|*
name|createTextureStorage2D
argument_list|(
name|SwapChain
operator|*
name|swapChain
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|TextureStorage
operator|*
name|createTextureStorage2D
argument_list|(
argument|GLenum internalformat
argument_list|,
argument|bool renderTarget
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|int levels
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|TextureStorage
operator|*
name|createTextureStorageCube
argument_list|(
argument|GLenum internalformat
argument_list|,
argument|bool renderTarget
argument_list|,
argument|int size
argument_list|,
argument|int levels
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|TextureStorage
operator|*
name|createTextureStorage3D
argument_list|(
argument|GLenum internalformat
argument_list|,
argument|bool renderTarget
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|int levels
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|TextureStorage
operator|*
name|createTextureStorage2DArray
argument_list|(
argument|GLenum internalformat
argument_list|,
argument|bool renderTarget
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|int levels
argument_list|)
operator|=
literal|0
block|;
comment|// Buffer-to-texture and Texture-to-buffer copies
name|virtual
name|bool
name|supportsFastCopyBufferToTexture
argument_list|(
argument|GLenum internalFormat
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|fastCopyBufferToTexture
argument_list|(
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|unsigned int offset
argument_list|,
argument|RenderTarget *destRenderTarget
argument_list|,
argument|GLenum destinationFormat
argument_list|,
argument|GLenum sourcePixelsType
argument_list|,
argument|const gl::Box&destArea
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|VertexConversionType
name|getVertexConversionType
argument_list|(
argument|const gl::VertexFormat&vertexFormat
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|GLenum
name|getVertexComponentType
argument_list|(
argument|const gl::VertexFormat&vertexFormat
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|VertexBuffer
operator|*
name|createVertexBuffer
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|IndexBuffer
operator|*
name|createIndexBuffer
argument_list|()
operator|=
literal|0
block|;
name|protected
operator|:
name|virtual
name|gl
operator|::
name|Error
name|drawArrays
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|,
argument|bool transformFeedbackActive
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|drawElements
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid *indices
argument_list|,
argument|gl::Buffer *elementArrayBuffer
argument_list|,
argument|const TranslatedIndexData&indexInfo
argument_list|,
argument|GLsizei instances
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|clear
argument_list|(
specifier|const
name|gl
operator|::
name|ClearParameters
operator|&
name|clearParams
argument_list|,
specifier|const
name|gl
operator|::
name|Framebuffer
operator|*
name|frameBuffer
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|blitRect
argument_list|(
argument|const gl::Framebuffer *readTarget
argument_list|,
argument|const gl::Rectangle&readRect
argument_list|,
argument|const gl::Framebuffer *drawTarget
argument_list|,
argument|const gl::Rectangle&drawRect
argument_list|,
argument|const gl::Rectangle *scissor
argument_list|,
argument|bool blitRenderTarget
argument_list|,
argument|bool blitDepth
argument_list|,
argument|bool blitStencil
argument_list|,
argument|GLenum filter
argument_list|)
operator|=
literal|0
block|;
name|egl
operator|::
name|Display
operator|*
name|mDisplay
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RendererD3D
argument_list|)
block|;
comment|//FIXME(jmadill): std::array is currently prohibited by Chromium style guide
typedef|typedef
name|std
operator|::
name|array
operator|<
name|unsigned
name|int
operator|,
name|gl
operator|::
name|IMPLEMENTATION_MAX_FRAMEBUFFER_ATTACHMENTS
operator|>
name|FramebufferTextureSerialArray
expr_stmt|;
name|gl
operator|::
name|Error
name|generateSwizzles
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|gl::SamplerType type
argument_list|)
decl_stmt|;
name|gl
operator|::
name|Error
name|generateSwizzles
argument_list|(
specifier|const
name|gl
operator|::
name|Data
operator|&
name|data
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|applyRenderTarget
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum drawMode
argument_list|,
argument|bool ignoreViewport
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|applyState
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum drawMode
argument_list|)
expr_stmt|;
name|bool
name|applyTransformFeedbackBuffers
argument_list|(
specifier|const
name|gl
operator|::
name|Data
operator|&
name|data
argument_list|)
decl_stmt|;
name|gl
operator|::
name|Error
name|applyShaders
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|bool transformFeedbackActive
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|applyTextures
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|gl::SamplerType shaderType
argument_list|,
argument|const FramebufferTextureSerialArray&framebufferSerials
argument_list|,
argument|size_t framebufferSerialCount
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|applyTextures
argument_list|(
specifier|const
name|gl
operator|::
name|Data
operator|&
name|data
argument_list|)
expr_stmt|;
name|gl
operator|::
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
expr_stmt|;
name|bool
name|skipDraw
argument_list|(
specifier|const
name|gl
operator|::
name|Data
operator|&
name|data
argument_list|,
name|GLenum
name|drawMode
argument_list|)
decl_stmt|;
name|void
name|markTransformFeedbackUsage
argument_list|(
specifier|const
name|gl
operator|::
name|Data
operator|&
name|data
argument_list|)
decl_stmt|;
name|size_t
name|getBoundFramebufferTextureSerials
argument_list|(
specifier|const
name|gl
operator|::
name|Data
operator|&
name|data
argument_list|,
name|FramebufferTextureSerialArray
operator|*
name|outSerialArray
argument_list|)
decl_stmt|;
name|gl
operator|::
name|Texture
operator|*
name|getIncompleteTexture
argument_list|(
argument|GLenum type
argument_list|)
expr_stmt|;
name|gl
operator|::
name|TextureMap
name|mIncompleteTextures
expr_stmt|;
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
comment|// LIBGLESV2_RENDERER_RENDERERD3D_H_
end_comment
end_unit
