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
comment|// Renderer9.h: Defines a back-end specific class for the D3D9 renderer.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_RENDERER9_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_RENDERER9_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_RENDERER9_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/mathutil.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/ShaderCache.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/VertexDeclarationCache.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Renderer.h"
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
struct_decl|struct
name|TranslatedAttribute
struct_decl|;
name|class
name|Renderer9
range|:
name|public
name|Renderer
block|{
name|public
operator|:
name|Renderer9
argument_list|(
argument|egl::Display *display
argument_list|,
argument|HDC hDc
argument_list|,
argument|bool softwareDevice
argument_list|)
block|;
name|virtual
operator|~
name|Renderer9
argument_list|()
block|;
specifier|static
name|Renderer9
operator|*
name|makeRenderer9
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
name|void
name|startScene
argument_list|()
block|;
name|void
name|endScene
argument_list|()
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
name|IDirect3DQuery9
operator|*
name|allocateEventQuery
argument_list|()
block|;
name|void
name|freeEventQuery
argument_list|(
name|IDirect3DQuery9
operator|*
name|query
argument_list|)
block|;
comment|// resource creation
name|IDirect3DVertexShader9
operator|*
name|createVertexShader
argument_list|(
argument|const DWORD *function
argument_list|,
argument|size_t length
argument_list|)
block|;
name|IDirect3DPixelShader9
operator|*
name|createPixelShader
argument_list|(
argument|const DWORD *function
argument_list|,
argument|size_t length
argument_list|)
block|;
name|HRESULT
name|createVertexBuffer
argument_list|(
argument|UINT Length
argument_list|,
argument|DWORD Usage
argument_list|,
argument|IDirect3DVertexBuffer9 **ppVertexBuffer
argument_list|)
block|;
name|HRESULT
name|createIndexBuffer
argument_list|(
argument|UINT Length
argument_list|,
argument|DWORD Usage
argument_list|,
argument|D3DFORMAT Format
argument_list|,
argument|IDirect3DIndexBuffer9 **ppIndexBuffer
argument_list|)
block|;
if|#
directive|if
literal|0
block|void *createTexture2D();     void *createTextureCube();     void *createQuery();     void *createIndexBuffer();     void *createVertexbuffer();
comment|// state setup
block|void applyShaders();     void applyConstants();
endif|#
directive|endif
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
name|bool
name|applyPrimitiveType
argument_list|(
argument|GLenum primitiveType
argument_list|,
argument|GLsizei elementCount
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
name|IDirect3DDevice9
operator|*
name|getDevice
argument_list|()
block|{
return|return
name|mDevice
return|;
block|}
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
name|DWORD
name|getCapsDeclTypes
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
argument|D3DFORMAT format
argument_list|,
argument|int requested
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
name|D3DFORMAT
name|ConvertTextureInternalFormat
argument_list|(
argument|GLint internalformat
argument_list|)
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
comment|// D3D9-renderer specific methods
name|bool
name|boxFilter
argument_list|(
name|IDirect3DSurface9
operator|*
name|source
argument_list|,
name|IDirect3DSurface9
operator|*
name|dest
argument_list|)
block|;
name|D3DPOOL
name|getTexturePool
argument_list|(
argument|DWORD usage
argument_list|)
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Renderer9
argument_list|)
block|;
name|void
name|applyUniformnfv
argument_list|(
name|gl
operator|::
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
name|void
name|applyUniformniv
argument_list|(
name|gl
operator|::
name|Uniform
operator|*
name|targetUniform
argument_list|,
specifier|const
name|GLint
operator|*
name|v
argument_list|)
block|;
name|void
name|applyUniformnbv
argument_list|(
name|gl
operator|::
name|Uniform
operator|*
name|targetUniform
argument_list|,
specifier|const
name|GLint
operator|*
name|v
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
name|drawIndexedPoints
argument_list|(
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid *indices
argument_list|,
argument|gl::Buffer *elementArrayBuffer
argument_list|)
block|;
name|void
name|getMultiSampleSupport
argument_list|(
argument|D3DFORMAT format
argument_list|,
argument|bool *multiSampleArray
argument_list|)
block|;
name|bool
name|copyToRenderTarget
argument_list|(
argument|IDirect3DSurface9 *dest
argument_list|,
argument|IDirect3DSurface9 *source
argument_list|,
argument|bool fromManaged
argument_list|)
block|;
name|gl
operator|::
name|Renderbuffer
operator|*
name|getNullColorbuffer
argument_list|(
name|gl
operator|::
name|Renderbuffer
operator|*
name|depthbuffer
argument_list|)
block|;
name|D3DPOOL
name|getBufferPool
argument_list|(
argument|DWORD usage
argument_list|)
specifier|const
block|;
name|HMODULE
name|mD3d9Module
block|;
name|HDC
name|mDc
block|;
name|void
name|initializeDevice
argument_list|()
block|;
name|D3DPRESENT_PARAMETERS
name|getDefaultPresentParameters
argument_list|()
block|;
name|void
name|releaseDeviceResources
argument_list|()
block|;
name|UINT
name|mAdapter
block|;
name|D3DDEVTYPE
name|mDeviceType
block|;
name|bool
name|mSoftwareDevice
block|;
comment|// FIXME: Deprecate
name|IDirect3D9
operator|*
name|mD3d9
block|;
comment|// Always valid after successful initialization.
name|IDirect3D9Ex
operator|*
name|mD3d9Ex
block|;
comment|// Might be null if D3D9Ex is not supported.
name|IDirect3DDevice9
operator|*
name|mDevice
block|;
name|IDirect3DDevice9Ex
operator|*
name|mDeviceEx
block|;
comment|// Might be null if D3D9Ex is not supported.
name|Blit
operator|*
name|mBlit
block|;
name|HWND
name|mDeviceWindow
block|;
name|bool
name|mDeviceLost
block|;
name|D3DCAPS9
name|mDeviceCaps
block|;
name|D3DADAPTER_IDENTIFIER9
name|mAdapterIdentifier
block|;
name|D3DPRIMITIVETYPE
name|mPrimitiveType
block|;
name|int
name|mPrimitiveCount
block|;
name|GLsizei
name|mRepeatDraw
block|;
name|bool
name|mSceneStarted
block|;
name|bool
name|mSupportsNonPower2Textures
block|;
name|bool
name|mSupportsTextureFilterAnisotropy
block|;
name|int
name|mMinSwapInterval
block|;
name|int
name|mMaxSwapInterval
block|;
name|bool
name|mOcclusionQuerySupport
block|;
name|bool
name|mEventQuerySupport
block|;
name|bool
name|mVertexTextureSupport
block|;
name|bool
name|mDepthTextureSupport
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
name|mFloat16TextureSupport
block|;
name|bool
name|mFloat16FilterSupport
block|;
name|bool
name|mFloat16RenderSupport
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
name|mLuminanceTextureSupport
block|;
name|bool
name|mLuminanceAlphaTextureSupport
block|;
name|std
operator|::
name|map
operator|<
name|D3DFORMAT
block|,
name|bool
operator|*
operator|>
name|mMultiSampleSupport
block|;
name|GLsizei
name|mMaxSupportedSamples
block|;
comment|// current render target states
name|unsigned
name|int
name|mAppliedRenderTargetSerial
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
name|rx
operator|::
name|RenderTarget
operator|::
name|Desc
name|mRenderTargetDesc
block|;
name|unsigned
name|int
name|mCurStencilSize
block|;
name|unsigned
name|int
name|mCurDepthSize
block|;
name|IDirect3DStateBlock9
operator|*
name|mMaskedClearSavedState
block|;
comment|// previously set render states
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
name|bool
name|mCurFrontFaceCCW
block|;
name|bool
name|mForceSetRasterState
block|;
name|gl
operator|::
name|RasterizerState
name|mCurRasterState
block|;
name|bool
name|mForceSetScissor
block|;
name|gl
operator|::
name|Rectangle
name|mCurScissor
block|;
name|bool
name|mScissorEnabled
block|;
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
name|Color
name|mCurBlendColor
block|;
name|GLuint
name|mCurSampleMask
block|;
comment|// Currently applied sampler states
name|bool
name|mForceSetVertexSamplerStates
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_VERTEX_TEXTURE_IMAGE_UNITS
index|]
block|;
name|gl
operator|::
name|SamplerState
name|mCurVertexSamplerStates
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_VERTEX_TEXTURE_IMAGE_UNITS
index|]
block|;
name|bool
name|mForceSetPixelSamplerStates
index|[
name|gl
operator|::
name|MAX_TEXTURE_IMAGE_UNITS
index|]
block|;
name|gl
operator|::
name|SamplerState
name|mCurPixelSamplerStates
index|[
name|gl
operator|::
name|MAX_TEXTURE_IMAGE_UNITS
index|]
block|;
comment|// Currently applied textures
name|unsigned
name|int
name|mCurVertexTextureSerials
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_VERTEX_TEXTURE_IMAGE_UNITS
index|]
block|;
name|unsigned
name|int
name|mCurPixelTextureSerials
index|[
name|gl
operator|::
name|MAX_TEXTURE_IMAGE_UNITS
index|]
block|;
name|unsigned
name|int
name|mAppliedIBSerial
block|;
name|unsigned
name|int
name|mAppliedProgramBinarySerial
block|;
name|rx
operator|::
name|dx_VertexConstants
name|mVertexConstants
block|;
name|rx
operator|::
name|dx_PixelConstants
name|mPixelConstants
block|;
name|bool
name|mDxUniformsDirty
block|;
comment|// A pool of event queries that are currently unused.
name|std
operator|::
name|vector
operator|<
name|IDirect3DQuery9
operator|*
operator|>
name|mEventQueryPool
block|;
name|VertexShaderCache
name|mVertexShaderCache
block|;
name|PixelShaderCache
name|mPixelShaderCache
block|;
name|VertexDataManager
operator|*
name|mVertexDataManager
block|;
name|VertexDeclarationCache
name|mVertexDeclarationCache
block|;
name|IndexDataManager
operator|*
name|mIndexDataManager
block|;
name|StreamingIndexBufferInterface
operator|*
name|mLineLoopIB
block|;      enum
block|{
name|NUM_NULL_COLORBUFFER_CACHE_ENTRIES
operator|=
literal|12
block|}
block|;     struct
name|NullColorbufferCacheEntry
block|{
name|UINT
name|lruCount
block|;
name|int
name|width
block|;
name|int
name|height
block|;
name|gl
operator|::
name|Renderbuffer
operator|*
name|buffer
block|;     }
name|mNullColorbufferCache
index|[
name|NUM_NULL_COLORBUFFER_CACHE_ENTRIES
index|]
block|;
name|UINT
name|mMaxNullColorbufferLRU
block|;  }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_RENDERER9_H_
end_comment
end_unit
