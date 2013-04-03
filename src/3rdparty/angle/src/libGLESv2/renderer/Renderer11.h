begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2013 The ANGLE Project Authors. All rights reserved.
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
file|"libGLESv2/mathutil.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Renderer.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/RenderStateCache.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/InputLayoutCache.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/RenderTarget.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Renderbuffer
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
name|Renderer
block|{
name|public
operator|:
name|Renderer11
argument_list|(
argument|egl::Display *display
argument_list|,
argument|HDC hDc
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
name|void
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
argument|HWND window
argument_list|,
argument|HANDLE shareHandle
argument_list|,
argument|GLenum backBufferFormat
argument_list|,
argument|GLenum depthBufferFormat
argument_list|)
block|;
name|virtual
name|void
name|setSamplerState
argument_list|(
argument|gl::SamplerType type
argument_list|,
argument|int index
argument_list|,
argument|const gl::SamplerState&sampler
argument_list|)
block|;
name|virtual
name|void
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
name|void
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
name|virtual
name|void
name|setBlendState
argument_list|(
argument|const gl::BlendState&blendState
argument_list|,
argument|const gl::Color&blendColor
argument_list|,
argument|unsigned int sampleMask
argument_list|)
block|;
name|virtual
name|void
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
name|bool
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
name|virtual
name|bool
name|applyRenderTarget
argument_list|(
name|gl
operator|::
name|Framebuffer
operator|*
name|frameBuffer
argument_list|)
block|;
name|virtual
name|void
name|applyShaders
argument_list|(
name|gl
operator|::
name|ProgramBinary
operator|*
name|programBinary
argument_list|)
block|;
name|virtual
name|void
name|applyUniforms
argument_list|(
name|gl
operator|::
name|ProgramBinary
operator|*
name|programBinary
argument_list|,
name|gl
operator|::
name|UniformArray
operator|*
name|uniformArray
argument_list|)
block|;
name|virtual
name|GLenum
name|applyVertexBuffer
argument_list|(
argument|gl::ProgramBinary *programBinary
argument_list|,
argument|gl::VertexAttribute vertexAttributes[]
argument_list|,
argument|GLint first
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|)
block|;
name|virtual
name|GLenum
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
name|drawArrays
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|)
block|;
name|virtual
name|void
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
name|virtual
name|void
name|clear
argument_list|(
specifier|const
name|gl
operator|::
name|ClearParameters
operator|&
name|clearParams
argument_list|,
name|gl
operator|::
name|Framebuffer
operator|*
name|frameBuffer
argument_list|)
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
block|;
name|virtual
name|bool
name|isDeviceLost
argument_list|()
block|;
name|virtual
name|bool
name|testDeviceLost
argument_list|(
argument|bool notify
argument_list|)
block|;
name|virtual
name|bool
name|testDeviceResettable
argument_list|()
block|;
comment|// Renderer capabilities
name|virtual
name|DWORD
name|getAdapterVendor
argument_list|()
specifier|const
block|;
name|virtual
name|std
operator|::
name|string
name|getRendererDescription
argument_list|()
specifier|const
block|;
name|virtual
name|GUID
name|getAdapterIdentifier
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|getBGRATextureSupport
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|getDXT1TextureSupport
argument_list|()
block|;
name|virtual
name|bool
name|getDXT3TextureSupport
argument_list|()
block|;
name|virtual
name|bool
name|getDXT5TextureSupport
argument_list|()
block|;
name|virtual
name|bool
name|getEventQuerySupport
argument_list|()
block|;
name|virtual
name|bool
name|getFloat32TextureSupport
argument_list|(
name|bool
operator|*
name|filtering
argument_list|,
name|bool
operator|*
name|renderable
argument_list|)
block|;
name|virtual
name|bool
name|getFloat16TextureSupport
argument_list|(
name|bool
operator|*
name|filtering
argument_list|,
name|bool
operator|*
name|renderable
argument_list|)
block|;
name|virtual
name|bool
name|getLuminanceTextureSupport
argument_list|()
block|;
name|virtual
name|bool
name|getLuminanceAlphaTextureSupport
argument_list|()
block|;
name|virtual
name|unsigned
name|int
name|getMaxVertexTextureImageUnits
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getMaxCombinedTextureImageUnits
argument_list|()
specifier|const
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
name|getMaxVertexUniformVectors
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getMaxFragmentUniformVectors
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getMaxVaryingVectors
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|getNonPower2TextureSupport
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|getDepthTextureSupport
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|getOcclusionQuerySupport
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|getInstancingSupport
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|getTextureFilterAnisotropySupport
argument_list|()
specifier|const
block|;
name|virtual
name|float
name|getTextureMaxAnisotropy
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
name|getDerivativeInstructionSupport
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
name|float
name|getMaxPointSize
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|getMaxViewportDimension
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|getMaxTextureWidth
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|getMaxTextureHeight
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|get32BitIndexSupport
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
name|virtual
name|GLsizei
name|getMaxSupportedSamples
argument_list|()
specifier|const
block|;
name|int
name|getNearestSupportedSamples
argument_list|(
argument|DXGI_FORMAT format
argument_list|,
argument|unsigned int requested
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getMaxRenderTargets
argument_list|()
specifier|const
block|;
comment|// Pixel operations
name|virtual
name|bool
name|copyToRenderTarget
argument_list|(
name|TextureStorageInterface2D
operator|*
name|dest
argument_list|,
name|TextureStorageInterface2D
operator|*
name|source
argument_list|)
block|;
name|virtual
name|bool
name|copyToRenderTarget
argument_list|(
name|TextureStorageInterfaceCube
operator|*
name|dest
argument_list|,
name|TextureStorageInterfaceCube
operator|*
name|source
argument_list|)
block|;
name|virtual
name|bool
name|copyImage
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
argument|TextureStorageInterface2D *storage
argument_list|,
argument|GLint level
argument_list|)
block|;
name|virtual
name|bool
name|copyImage
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
argument|TextureStorageInterfaceCube *storage
argument_list|,
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|)
block|;
name|bool
name|copyTexture
argument_list|(
argument|ID3D11ShaderResourceView *source
argument_list|,
argument|const gl::Rectangle&sourceArea
argument_list|,
argument|unsigned int sourceWidth
argument_list|,
argument|unsigned int sourceHeight
argument_list|,
argument|ID3D11RenderTargetView *dest
argument_list|,
argument|const gl::Rectangle&destArea
argument_list|,
argument|unsigned int destWidth
argument_list|,
argument|unsigned int destHeight
argument_list|,
argument|GLenum destFormat
argument_list|)
block|;
name|virtual
name|bool
name|blitRect
argument_list|(
argument|gl::Framebuffer *readTarget
argument_list|,
argument|const gl::Rectangle&readRect
argument_list|,
argument|gl::Framebuffer *drawTarget
argument_list|,
argument|const gl::Rectangle&drawRect
argument_list|,
argument|bool blitRenderTarget
argument_list|,
argument|bool blitDepthStencil
argument_list|)
block|;
name|virtual
name|void
name|readPixels
argument_list|(
argument|gl::Framebuffer *framebuffer
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
argument|GLsizei outputPitch
argument_list|,
argument|bool packReverseRowOrder
argument_list|,
argument|GLint packAlignment
argument_list|,
argument|void* pixels
argument_list|)
block|;
comment|// RenderTarget creation
name|virtual
name|RenderTarget
operator|*
name|createRenderTarget
argument_list|(
argument|SwapChain *swapChain
argument_list|,
argument|bool depth
argument_list|)
block|;
name|virtual
name|RenderTarget
operator|*
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
argument|bool depth
argument_list|)
block|;
comment|// Shader operations
name|virtual
name|ShaderExecutable
operator|*
name|loadExecutable
argument_list|(
argument|const void *function
argument_list|,
argument|size_t length
argument_list|,
argument|rx::ShaderType type
argument_list|)
block|;
name|virtual
name|ShaderExecutable
operator|*
name|compileToExecutable
argument_list|(
argument|gl::InfoLog&infoLog
argument_list|,
argument|const char *shaderHLSL
argument_list|,
argument|rx::ShaderType type
argument_list|)
block|;
comment|// Image operations
name|virtual
name|Image
operator|*
name|createImage
argument_list|()
block|;
name|virtual
name|void
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
argument|int levels
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLenum usage
argument_list|,
argument|bool forceRenderable
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|virtual
name|TextureStorage
operator|*
name|createTextureStorageCube
argument_list|(
argument|int levels
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLenum usage
argument_list|,
argument|bool forceRenderable
argument_list|,
argument|int size
argument_list|)
block|;
comment|// Buffer creation
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
name|virtual
name|BufferStorage
operator|*
name|createBufferStorage
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
name|FenceImpl
operator|*
name|createFence
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
name|IDXGIFactory
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
name|getRenderTargetResource
argument_list|(
argument|gl::Renderbuffer *colorbuffer
argument_list|,
argument|unsigned int *subresourceIndex
argument_list|,
argument|ID3D11Texture2D **resource
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
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Renderer11
argument_list|)
block|;
name|void
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
name|void
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
name|void
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
argument|GLsizei outputPitch
argument_list|,
argument|bool packReverseRowOrder
argument_list|,
argument|GLint packAlignment
argument_list|,
argument|void *pixels
argument_list|)
block|;
name|void
name|maskedClear
argument_list|(
specifier|const
name|gl
operator|::
name|ClearParameters
operator|&
name|clearParams
argument_list|)
block|;
name|rx
operator|::
name|Range
name|getViewportBounds
argument_list|()
specifier|const
block|;
name|bool
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
argument|bool wholeBufferCopy
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
name|HMODULE
name|mD3d11Module
block|;
name|HMODULE
name|mDxgiModule
block|;
name|HDC
name|mDc
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
comment|// Support flags
name|bool
name|mFloat16TextureSupport
block|;
name|bool
name|mFloat16FilterSupport
block|;
name|bool
name|mFloat16RenderSupport
block|;
name|bool
name|mFloat32TextureSupport
block|;
name|bool
name|mFloat32FilterSupport
block|;
name|bool
name|mFloat32RenderSupport
block|;
name|bool
name|mDXT1TextureSupport
block|;
name|bool
name|mDXT3TextureSupport
block|;
name|bool
name|mDXT5TextureSupport
block|;
name|bool
name|mDepthTextureSupport
block|;
comment|// Multisample format support
block|struct
name|MultisampleSupportInfo
block|{
name|unsigned
name|int
name|qualityLevels
index|[
name|D3D11_MAX_MULTISAMPLE_SAMPLE_COUNT
index|]
block|;     }
block|;
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|DXGI_FORMAT
operator|,
name|MultisampleSupportInfo
operator|>
name|MultisampleSupportMap
expr_stmt|;
name|MultisampleSupportMap
name|mMultisampleSupportMap
decl_stmt|;
name|unsigned
name|int
name|mMaxSupportedSamples
decl_stmt|;
comment|// current render target states
name|unsigned
name|int
name|mAppliedRenderTargetSerials
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_DRAW_BUFFERS
index|]
decl_stmt|;
name|unsigned
name|int
name|mAppliedDepthbufferSerial
decl_stmt|;
name|unsigned
name|int
name|mAppliedStencilbufferSerial
decl_stmt|;
name|bool
name|mDepthStencilInitialized
decl_stmt|;
name|bool
name|mRenderTargetDescInitialized
decl_stmt|;
name|rx
operator|::
name|RenderTarget
operator|::
name|Desc
name|mRenderTargetDesc
expr_stmt|;
name|unsigned
name|int
name|mCurDepthSize
decl_stmt|;
name|unsigned
name|int
name|mCurStencilSize
decl_stmt|;
comment|// Currently applied sampler states
name|bool
name|mForceSetVertexSamplerStates
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_VERTEX_TEXTURE_IMAGE_UNITS
index|]
decl_stmt|;
name|gl
operator|::
name|SamplerState
name|mCurVertexSamplerStates
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_VERTEX_TEXTURE_IMAGE_UNITS
index|]
expr_stmt|;
name|bool
name|mForceSetPixelSamplerStates
index|[
name|gl
operator|::
name|MAX_TEXTURE_IMAGE_UNITS
index|]
decl_stmt|;
name|gl
operator|::
name|SamplerState
name|mCurPixelSamplerStates
index|[
name|gl
operator|::
name|MAX_TEXTURE_IMAGE_UNITS
index|]
expr_stmt|;
comment|// Currently applied textures
name|unsigned
name|int
name|mCurVertexTextureSerials
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_VERTEX_TEXTURE_IMAGE_UNITS
index|]
decl_stmt|;
name|unsigned
name|int
name|mCurPixelTextureSerials
index|[
name|gl
operator|::
name|MAX_TEXTURE_IMAGE_UNITS
index|]
decl_stmt|;
comment|// Currently applied blend state
name|bool
name|mForceSetBlendState
decl_stmt|;
name|gl
operator|::
name|BlendState
name|mCurBlendState
expr_stmt|;
name|gl
operator|::
name|Color
name|mCurBlendColor
expr_stmt|;
name|unsigned
name|int
name|mCurSampleMask
decl_stmt|;
comment|// Currently applied rasterizer state
name|bool
name|mForceSetRasterState
decl_stmt|;
name|gl
operator|::
name|RasterizerState
name|mCurRasterState
expr_stmt|;
comment|// Currently applied depth stencil state
name|bool
name|mForceSetDepthStencilState
decl_stmt|;
name|gl
operator|::
name|DepthStencilState
name|mCurDepthStencilState
expr_stmt|;
name|int
name|mCurStencilRef
decl_stmt|;
name|int
name|mCurStencilBackRef
decl_stmt|;
comment|// Currently applied scissor rectangle
name|bool
name|mForceSetScissor
decl_stmt|;
name|bool
name|mScissorEnabled
decl_stmt|;
name|gl
operator|::
name|Rectangle
name|mCurScissor
expr_stmt|;
comment|// Currently applied viewport
name|bool
name|mForceSetViewport
decl_stmt|;
name|gl
operator|::
name|Rectangle
name|mCurViewport
expr_stmt|;
name|float
name|mCurNear
decl_stmt|;
name|float
name|mCurFar
decl_stmt|;
name|unsigned
name|int
name|mAppliedIBSerial
decl_stmt|;
name|unsigned
name|int
name|mAppliedStorageIBSerial
decl_stmt|;
name|unsigned
name|int
name|mAppliedIBOffset
decl_stmt|;
name|unsigned
name|int
name|mAppliedProgramBinarySerial
decl_stmt|;
name|bool
name|mIsGeometryShaderActive
decl_stmt|;
name|dx_VertexConstants
name|mVertexConstants
decl_stmt|;
name|dx_VertexConstants
name|mAppliedVertexConstants
decl_stmt|;
name|ID3D11Buffer
modifier|*
name|mDriverConstantBufferVS
decl_stmt|;
name|dx_PixelConstants
name|mPixelConstants
decl_stmt|;
name|dx_PixelConstants
name|mAppliedPixelConstants
decl_stmt|;
name|ID3D11Buffer
modifier|*
name|mDriverConstantBufferPS
decl_stmt|;
comment|// Vertex, index and input layouts
name|VertexDataManager
modifier|*
name|mVertexDataManager
decl_stmt|;
name|IndexDataManager
modifier|*
name|mIndexDataManager
decl_stmt|;
name|InputLayoutCache
name|mInputLayoutCache
decl_stmt|;
name|StreamingIndexBufferInterface
modifier|*
name|mLineLoopIB
decl_stmt|;
name|StreamingIndexBufferInterface
modifier|*
name|mTriangleFanIB
decl_stmt|;
comment|// Texture copy resources
name|bool
name|mCopyResourcesInitialized
decl_stmt|;
name|ID3D11Buffer
modifier|*
name|mCopyVB
decl_stmt|;
name|ID3D11SamplerState
modifier|*
name|mCopySampler
decl_stmt|;
name|ID3D11InputLayout
modifier|*
name|mCopyIL
decl_stmt|;
name|ID3D11VertexShader
modifier|*
name|mCopyVS
decl_stmt|;
name|ID3D11PixelShader
modifier|*
name|mCopyRGBAPS
decl_stmt|;
name|ID3D11PixelShader
modifier|*
name|mCopyRGBPS
decl_stmt|;
name|ID3D11PixelShader
modifier|*
name|mCopyLumPS
decl_stmt|;
name|ID3D11PixelShader
modifier|*
name|mCopyLumAlphaPS
decl_stmt|;
comment|// Masked clear resources
name|bool
name|mClearResourcesInitialized
decl_stmt|;
name|ID3D11Buffer
modifier|*
name|mClearVB
decl_stmt|;
name|ID3D11InputLayout
modifier|*
name|mClearIL
decl_stmt|;
name|ID3D11VertexShader
modifier|*
name|mClearVS
decl_stmt|;
name|ID3D11PixelShader
modifier|*
name|mClearPS
decl_stmt|;
name|ID3D11RasterizerState
modifier|*
name|mClearScissorRS
decl_stmt|;
name|ID3D11RasterizerState
modifier|*
name|mClearNoScissorRS
decl_stmt|;
comment|// Sync query
name|ID3D11Query
modifier|*
name|mSyncQuery
decl_stmt|;
name|ID3D11Device
modifier|*
name|mDevice
decl_stmt|;
name|D3D_FEATURE_LEVEL
name|mFeatureLevel
decl_stmt|;
name|ID3D11DeviceContext
modifier|*
name|mDeviceContext
decl_stmt|;
name|IDXGIAdapter
modifier|*
name|mDxgiAdapter
decl_stmt|;
name|DXGI_ADAPTER_DESC
name|mAdapterDescription
decl_stmt|;
name|char
name|mDescription
index|[
literal|128
index|]
decl_stmt|;
name|IDXGIFactory
modifier|*
name|mDxgiFactory
decl_stmt|;
comment|// Cached device caps
name|bool
name|mBGRATextureSupport
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
comment|// LIBGLESV2_RENDERER_RENDERER11_H_
end_comment
end_unit
