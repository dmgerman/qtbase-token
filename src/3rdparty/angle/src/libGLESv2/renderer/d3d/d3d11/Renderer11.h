begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// Renderer11.h: Defines a back-end specific class for the D3D11 renderer.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_RENDERER11_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_RENDERER11_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_RENDERER11_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"common/mathutil.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d11/RenderStateCache.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d11/InputLayoutCache.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/HLSLCompiler.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/RendererD3D.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/RenderTarget.h"
end_include
begin_include
include|#
directive|include
file|"libEGL/AttributeMap.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|FramebufferAttachment
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|VertexDataManager
decl_stmt|;
name|class
name|IndexDataManager
decl_stmt|;
name|class
name|StreamingIndexBufferInterface
decl_stmt|;
name|class
name|Blit11
decl_stmt|;
name|class
name|Clear11
decl_stmt|;
name|class
name|PixelTransfer11
decl_stmt|;
name|class
name|RenderTarget11
decl_stmt|;
struct_decl|struct
name|PackPixelsParams
struct_decl|;
enum|enum
block|{
name|MAX_VERTEX_UNIFORM_VECTORS_D3D11
init|=
literal|1024
block|,
name|MAX_FRAGMENT_UNIFORM_VECTORS_D3D11
init|=
literal|1024
block|}
enum|;
name|class
name|Renderer11
range|:
name|public
name|RendererD3D
block|{
name|public
operator|:
name|Renderer11
argument_list|(
argument|egl::Display *display
argument_list|,
argument|EGLNativeDisplayType hDc
argument_list|,
argument|const egl::AttributeMap&attributes
argument_list|)
block|;
name|virtual
operator|~
name|Renderer11
argument_list|()
block|;
specifier|static
name|Renderer11
operator|*
name|makeRenderer11
argument_list|(
name|Renderer
operator|*
name|renderer
argument_list|)
block|;
name|virtual
name|EGLint
name|initialize
argument_list|()
block|;
name|virtual
name|bool
name|resetDevice
argument_list|()
block|;
name|virtual
name|int
name|generateConfigs
argument_list|(
name|ConfigDesc
operator|*
operator|*
name|configDescList
argument_list|)
block|;
name|virtual
name|void
name|deleteConfigs
argument_list|(
name|ConfigDesc
operator|*
name|configDescList
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|sync
argument_list|(
argument|bool block
argument_list|)
block|;
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
block|;
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
name|override
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
block|;
name|virtual
name|void
name|setScissorRectangle
argument_list|(
argument|const gl::Rectangle&scissor
argument_list|,
argument|bool enabled
argument_list|)
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
block|;
name|virtual
name|bool
name|applyPrimitiveType
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLsizei count
argument_list|)
block|;
name|gl
operator|::
name|Error
name|applyRenderTarget
argument_list|(
argument|const gl::Framebuffer *frameBuffer
argument_list|)
name|override
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
block|;
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
block|;
name|gl
operator|::
name|Error
name|clear
argument_list|(
argument|const gl::ClearParameters&clearParams
argument_list|,
argument|const gl::Framebuffer *frameBuffer
argument_list|)
name|override
block|;
name|virtual
name|void
name|markAllStateDirty
argument_list|()
block|;
comment|// lost device
name|void
name|notifyDeviceLost
argument_list|()
name|override
block|;
name|bool
name|isDeviceLost
argument_list|()
name|override
block|;
name|bool
name|testDeviceLost
argument_list|(
argument|bool notify
argument_list|)
name|override
block|;
name|bool
name|testDeviceResettable
argument_list|()
name|override
block|;
name|DWORD
name|getAdapterVendor
argument_list|()
specifier|const
name|override
block|;
name|std
operator|::
name|string
name|getRendererDescription
argument_list|()
specifier|const
name|override
block|;
name|GUID
name|getAdapterIdentifier
argument_list|()
specifier|const
name|override
block|;
name|virtual
name|unsigned
name|int
name|getReservedVertexUniformVectors
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getReservedFragmentUniformVectors
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getReservedVertexUniformBuffers
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getReservedFragmentUniformBuffers
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|getShareHandleSupport
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|getPostSubBufferSupport
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|getMajorShaderModel
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|getMinSwapInterval
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|getMaxSwapInterval
argument_list|()
specifier|const
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
block|;
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
name|override
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
block|;
comment|// Shader creation
name|virtual
name|ShaderImpl
operator|*
name|createShader
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum type
argument_list|)
block|;
name|virtual
name|ProgramImpl
operator|*
name|createProgram
argument_list|()
block|;
comment|// Shader operations
name|void
name|releaseShaderCompiler
argument_list|()
name|override
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
block|;
name|virtual
name|UniformStorage
operator|*
name|createUniformStorage
argument_list|(
argument|size_t storageSize
argument_list|)
block|;
comment|// Image operations
name|virtual
name|Image
operator|*
name|createImage
argument_list|()
block|;
name|gl
operator|::
name|Error
name|generateMipmap
argument_list|(
argument|Image *dest
argument_list|,
argument|Image *source
argument_list|)
name|override
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
block|;
comment|// Texture creation
name|virtual
name|TextureImpl
operator|*
name|createTexture
argument_list|(
argument|GLenum target
argument_list|)
block|;
comment|// Renderbuffer creation
name|virtual
name|RenderbufferImpl
operator|*
name|createRenderbuffer
argument_list|()
block|;
name|virtual
name|RenderbufferImpl
operator|*
name|createRenderbuffer
argument_list|(
argument|SwapChain *swapChain
argument_list|,
argument|bool depth
argument_list|)
block|;
comment|// Buffer creation
name|virtual
name|BufferImpl
operator|*
name|createBuffer
argument_list|()
block|;
name|virtual
name|VertexBuffer
operator|*
name|createVertexBuffer
argument_list|()
block|;
name|virtual
name|IndexBuffer
operator|*
name|createIndexBuffer
argument_list|()
block|;
comment|// Vertex Array creation
name|virtual
name|VertexArrayImpl
operator|*
name|createVertexArray
argument_list|()
block|;
comment|// Query and Fence creation
name|virtual
name|QueryImpl
operator|*
name|createQuery
argument_list|(
argument|GLenum type
argument_list|)
block|;
name|virtual
name|FenceNVImpl
operator|*
name|createFenceNV
argument_list|()
block|;
name|virtual
name|FenceSyncImpl
operator|*
name|createFenceSync
argument_list|()
block|;
comment|// Transform Feedback creation
name|virtual
name|TransformFeedbackImpl
operator|*
name|createTransformFeedback
argument_list|()
block|;
comment|// D3D11-renderer specific methods
name|ID3D11Device
operator|*
name|getDevice
argument_list|()
block|{
return|return
name|mDevice
return|;
block|}
name|ID3D11DeviceContext
operator|*
name|getDeviceContext
argument_list|()
block|{
return|return
name|mDeviceContext
return|;
block|}
block|;
name|DXGIFactory
operator|*
name|getDxgiFactory
argument_list|()
block|{
return|return
name|mDxgiFactory
return|;
block|}
block|;
name|bool
name|isLevel9
argument_list|()
block|{
return|return
name|mFeatureLevel
operator|<=
name|D3D_FEATURE_LEVEL_9_3
return|;
block|}
name|Blit11
operator|*
name|getBlitter
argument_list|()
block|{
return|return
name|mBlit
return|;
block|}
comment|// Buffer-to-texture and Texture-to-buffer copies
name|virtual
name|bool
name|supportsFastCopyBufferToTexture
argument_list|(
argument|GLenum internalFormat
argument_list|)
specifier|const
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
block|;
name|gl
operator|::
name|Error
name|getRenderTargetResource
argument_list|(
argument|gl::FramebufferAttachment *colorbuffer
argument_list|,
argument|unsigned int *subresourceIndexOut
argument_list|,
argument|ID3D11Texture2D **texture2DOut
argument_list|)
block|;
name|void
name|unapplyRenderTargets
argument_list|()
block|;
name|void
name|setOneTimeRenderTarget
argument_list|(
name|ID3D11RenderTargetView
operator|*
name|renderTargetView
argument_list|)
block|;
name|gl
operator|::
name|Error
name|packPixels
argument_list|(
name|ID3D11Texture2D
operator|*
name|readTexture
argument_list|,
specifier|const
name|PackPixelsParams
operator|&
name|params
argument_list|,
name|uint8_t
operator|*
name|pixelsOut
argument_list|)
block|;
name|virtual
name|bool
name|getLUID
argument_list|(
argument|LUID *adapterLuid
argument_list|)
specifier|const
block|;
name|virtual
name|VertexConversionType
name|getVertexConversionType
argument_list|(
argument|const gl::VertexFormat&vertexFormat
argument_list|)
specifier|const
block|;
name|virtual
name|GLenum
name|getVertexComponentType
argument_list|(
argument|const gl::VertexFormat&vertexFormat
argument_list|)
specifier|const
block|;
name|gl
operator|::
name|Error
name|readTextureData
argument_list|(
argument|ID3D11Texture2D *texture
argument_list|,
argument|unsigned int subResource
argument_list|,
argument|const gl::Rectangle&area
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
block|;
name|void
name|setShaderResource
argument_list|(
argument|gl::SamplerType shaderType
argument_list|,
argument|UINT resourceSlot
argument_list|,
argument|ID3D11ShaderResourceView *srv
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Renderer11
argument_list|)
block|;
name|void
name|generateCaps
argument_list|(
argument|gl::Caps *outCaps
argument_list|,
argument|gl::TextureCapsMap *outTextureCaps
argument_list|,
argument|gl::Extensions *outExtensions
argument_list|)
specifier|const
name|override
block|;
name|Workarounds
name|generateWorkarounds
argument_list|()
specifier|const
name|override
block|;
name|gl
operator|::
name|Error
name|drawLineLoop
argument_list|(
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid *indices
argument_list|,
argument|int minIndex
argument_list|,
argument|gl::Buffer *elementArrayBuffer
argument_list|)
block|;
name|gl
operator|::
name|Error
name|drawTriangleFan
argument_list|(
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid *indices
argument_list|,
argument|int minIndex
argument_list|,
argument|gl::Buffer *elementArrayBuffer
argument_list|,
argument|int instances
argument_list|)
block|;
name|gl
operator|::
name|Error
name|blitRenderbufferRect
argument_list|(
argument|const gl::Rectangle&readRect
argument_list|,
argument|const gl::Rectangle&drawRect
argument_list|,
argument|RenderTarget *readRenderTarget
argument_list|,
argument|RenderTarget *drawRenderTarget
argument_list|,
argument|GLenum filter
argument_list|,
argument|const gl::Rectangle *scissor
argument_list|,
argument|bool colorBlit
argument_list|,
argument|bool depthBlit
argument_list|,
argument|bool stencilBlit
argument_list|)
block|;
name|ID3D11Texture2D
operator|*
name|resolveMultisampledTexture
argument_list|(
argument|ID3D11Texture2D *source
argument_list|,
argument|unsigned int subresource
argument_list|)
block|;
name|void
name|unsetSRVsWithResource
argument_list|(
argument|gl::SamplerType shaderType
argument_list|,
argument|const ID3D11Resource *resource
argument_list|)
block|;
specifier|static
name|void
name|invalidateFBOAttachmentSwizzles
argument_list|(
argument|gl::FramebufferAttachment *attachment
argument_list|,
argument|int mipLevel
argument_list|)
block|;
specifier|static
name|void
name|invalidateFramebufferSwizzles
argument_list|(
specifier|const
name|gl
operator|::
name|Framebuffer
operator|*
name|framebuffer
argument_list|)
block|;
name|HMODULE
name|mD3d11Module
block|;
name|HMODULE
name|mDxgiModule
block|;
name|EGLNativeDisplayType
name|mDc
block|;
name|std
operator|::
name|vector
operator|<
name|D3D_FEATURE_LEVEL
operator|>
name|mAvailableFeatureLevels
block|;
name|D3D_DRIVER_TYPE
name|mDriverType
block|;
name|HLSLCompiler
name|mCompiler
block|;
name|bool
name|mDeviceLost
block|;
name|void
name|initializeDevice
argument_list|()
block|;
name|void
name|releaseDeviceResources
argument_list|()
block|;
name|int
name|getMinorShaderModel
argument_list|()
specifier|const
block|;
name|void
name|release
argument_list|()
block|;
name|RenderStateCache
name|mStateCache
block|;
comment|// current render target states
name|unsigned
name|int
name|mAppliedRenderTargetSerials
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_DRAW_BUFFERS
index|]
block|;
name|unsigned
name|int
name|mAppliedDepthbufferSerial
block|;
name|unsigned
name|int
name|mAppliedStencilbufferSerial
block|;
name|bool
name|mDepthStencilInitialized
block|;
name|bool
name|mRenderTargetDescInitialized
block|;
name|RenderTarget
operator|::
name|Desc
name|mRenderTargetDesc
block|;
comment|// Currently applied sampler states
name|std
operator|::
name|vector
operator|<
name|bool
operator|>
name|mForceSetVertexSamplerStates
block|;
name|std
operator|::
name|vector
operator|<
name|gl
operator|::
name|SamplerState
operator|>
name|mCurVertexSamplerStates
block|;
name|std
operator|::
name|vector
operator|<
name|bool
operator|>
name|mForceSetPixelSamplerStates
block|;
name|std
operator|::
name|vector
operator|<
name|gl
operator|::
name|SamplerState
operator|>
name|mCurPixelSamplerStates
block|;
comment|// Currently applied textures
name|std
operator|::
name|vector
operator|<
name|ID3D11ShaderResourceView
operator|*
operator|>
name|mCurVertexSRVs
block|;
name|std
operator|::
name|vector
operator|<
name|ID3D11ShaderResourceView
operator|*
operator|>
name|mCurPixelSRVs
block|;
comment|// Currently applied blend state
name|bool
name|mForceSetBlendState
block|;
name|gl
operator|::
name|BlendState
name|mCurBlendState
block|;
name|gl
operator|::
name|ColorF
name|mCurBlendColor
block|;
name|unsigned
name|int
name|mCurSampleMask
block|;
comment|// Currently applied rasterizer state
name|bool
name|mForceSetRasterState
block|;
name|gl
operator|::
name|RasterizerState
name|mCurRasterState
block|;
comment|// Currently applied depth stencil state
name|bool
name|mForceSetDepthStencilState
block|;
name|gl
operator|::
name|DepthStencilState
name|mCurDepthStencilState
block|;
name|int
name|mCurStencilRef
block|;
name|int
name|mCurStencilBackRef
block|;
comment|// Currently applied scissor rectangle
name|bool
name|mForceSetScissor
block|;
name|bool
name|mScissorEnabled
block|;
name|gl
operator|::
name|Rectangle
name|mCurScissor
block|;
comment|// Currently applied viewport
name|bool
name|mForceSetViewport
block|;
name|gl
operator|::
name|Rectangle
name|mCurViewport
block|;
name|float
name|mCurNear
block|;
name|float
name|mCurFar
block|;
comment|// Currently applied primitive topology
name|D3D11_PRIMITIVE_TOPOLOGY
name|mCurrentPrimitiveTopology
block|;
comment|// Currently applied index buffer
name|ID3D11Buffer
operator|*
name|mAppliedIB
block|;
name|DXGI_FORMAT
name|mAppliedIBFormat
block|;
name|unsigned
name|int
name|mAppliedIBOffset
block|;
comment|// Currently applied transform feedback buffers
name|ID3D11Buffer
operator|*
name|mAppliedTFBuffers
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TRANSFORM_FEEDBACK_BUFFERS
index|]
block|;
comment|// Tracks the current D3D buffers
comment|// in use for streamout
name|GLintptr
name|mAppliedTFOffsets
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TRANSFORM_FEEDBACK_BUFFERS
index|]
block|;
comment|// Tracks the current GL-specified
comment|// buffer offsets to transform feedback
comment|// buffers
name|UINT
name|mCurrentD3DOffsets
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TRANSFORM_FEEDBACK_BUFFERS
index|]
block|;
comment|// Tracks the D3D buffer offsets,
comment|// which may differ from GLs, due
comment|// to different append behavior
comment|// Currently applied shaders
name|ID3D11VertexShader
operator|*
name|mAppliedVertexShader
block|;
name|ID3D11GeometryShader
operator|*
name|mAppliedGeometryShader
block|;
name|ID3D11GeometryShader
operator|*
name|mCurPointGeometryShader
block|;
name|ID3D11PixelShader
operator|*
name|mAppliedPixelShader
block|;
name|dx_VertexConstants
name|mVertexConstants
block|;
name|dx_VertexConstants
name|mAppliedVertexConstants
block|;
name|ID3D11Buffer
operator|*
name|mDriverConstantBufferVS
block|;
name|ID3D11Buffer
operator|*
name|mCurrentVertexConstantBuffer
block|;
name|unsigned
name|int
name|mCurrentConstantBufferVS
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_VERTEX_SHADER_UNIFORM_BUFFERS
index|]
block|;
name|dx_PixelConstants
name|mPixelConstants
block|;
name|dx_PixelConstants
name|mAppliedPixelConstants
block|;
name|ID3D11Buffer
operator|*
name|mDriverConstantBufferPS
block|;
name|ID3D11Buffer
operator|*
name|mCurrentPixelConstantBuffer
block|;
name|unsigned
name|int
name|mCurrentConstantBufferPS
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_VERTEX_SHADER_UNIFORM_BUFFERS
index|]
block|;
name|ID3D11Buffer
operator|*
name|mCurrentGeometryConstantBuffer
block|;
comment|// Vertex, index and input layouts
name|VertexDataManager
operator|*
name|mVertexDataManager
block|;
name|IndexDataManager
operator|*
name|mIndexDataManager
block|;
name|InputLayoutCache
name|mInputLayoutCache
block|;
name|StreamingIndexBufferInterface
operator|*
name|mLineLoopIB
block|;
name|StreamingIndexBufferInterface
operator|*
name|mTriangleFanIB
block|;
comment|// Texture copy resources
name|Blit11
operator|*
name|mBlit
block|;
name|PixelTransfer11
operator|*
name|mPixelTransfer
block|;
comment|// Masked clear resources
name|Clear11
operator|*
name|mClear
block|;
comment|// Sync query
name|ID3D11Query
operator|*
name|mSyncQuery
block|;
name|ID3D11Device
operator|*
name|mDevice
block|;
name|D3D_FEATURE_LEVEL
name|mFeatureLevel
block|;
name|ID3D11DeviceContext
operator|*
name|mDeviceContext
block|;
name|IDXGIAdapter
operator|*
name|mDxgiAdapter
block|;
name|DXGI_ADAPTER_DESC
name|mAdapterDescription
block|;
name|char
name|mDescription
index|[
literal|128
index|]
block|;
name|DXGIFactory
operator|*
name|mDxgiFactory
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_RENDERER11_H_
end_comment
end_unit
