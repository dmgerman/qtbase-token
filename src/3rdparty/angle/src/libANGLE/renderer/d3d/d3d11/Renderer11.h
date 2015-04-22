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
name|LIBANGLE_RENDERER_D3D_D3D11_RENDERER11_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D11_RENDERER11_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D11_RENDERER11_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"common/mathutil.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/AttributeMap.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/HLSLCompiler.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/RendererD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/RenderTargetD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/DebugAnnotator11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/InputLayoutCache.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/RenderStateCache.h"
end_include
begin_struct_decl
struct_decl|struct
name|ID3D11DeviceContext1
struct_decl|;
end_struct_decl
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|FramebufferAttachment
decl_stmt|;
struct_decl|struct
name|ImageIndex
struct_decl|;
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
name|class
name|Trim11
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
comment|// Possible reasons RendererD3D initialize can fail
enum|enum
name|D3D11InitError
block|{
comment|// The renderer loaded successfully
name|D3D11_INIT_SUCCESS
init|=
literal|0
block|,
comment|// Failed to load the ANGLE& D3D compiler libraries
name|D3D11_INIT_COMPILER_ERROR
block|,
comment|// Failed to load a necessary DLL (non-compiler)
name|D3D11_INIT_MISSING_DEP
block|,
comment|// CreateDevice returned E_INVALIDARG
name|D3D11_INIT_CREATEDEVICE_INVALIDARG
block|,
comment|// CreateDevice failed with an error other than invalid arg
name|D3D11_INIT_CREATEDEVICE_ERROR
block|,
comment|// DXGI 1.2 required but not found
name|D3D11_INIT_INCOMPATIBLE_DXGI
block|,
comment|// Other initialization error
name|D3D11_INIT_OTHER_ERROR
block|,
name|NUM_D3D11_INIT_ERRORS
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
name|explicit
name|Renderer11
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
name|egl
operator|::
name|Error
name|initialize
argument_list|()
name|override
block|;
name|virtual
name|bool
name|resetDevice
argument_list|()
block|;
name|egl
operator|::
name|ConfigSet
name|generateConfigs
argument_list|()
specifier|const
name|override
block|;
name|gl
operator|::
name|Error
name|flush
argument_list|()
name|override
block|;
name|gl
operator|::
name|Error
name|finish
argument_list|()
name|override
block|;
name|virtual
name|SwapChainD3D
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
name|gl
operator|::
name|Error
name|setUniformBuffers
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|const GLint vertexUniformBuffers[]
argument_list|,
argument|const GLint fragmentUniformBuffers[]
argument_list|)
name|override
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
argument_list|,
argument|bool usesPointSize
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
argument|gl::Program *program
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
argument|GLenum mode
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
name|void
name|applyTransformFeedbackBuffers
argument_list|(
argument|const gl::State&state
argument_list|)
name|override
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
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|,
argument|bool usesPointSize
argument_list|)
name|override
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
name|virtual
name|void
name|markAllStateDirty
argument_list|()
block|;
comment|// lost device
name|bool
name|testDeviceLost
argument_list|()
name|override
block|;
name|bool
name|testDeviceResettable
argument_list|()
name|override
block|;
name|VendorID
name|getVendorId
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
name|int
name|getMinorShaderModel
argument_list|()
specifier|const
name|override
block|;
name|std
operator|::
name|string
name|getShaderModelSuffix
argument_list|()
specifier|const
name|override
block|;
comment|// Pixel operations
name|virtual
name|gl
operator|::
name|Error
name|copyImage2D
argument_list|(
argument|const gl::Framebuffer *framebuffer
argument_list|,
argument|const gl::Rectangle&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|const gl::Offset&destOffset
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
argument|const gl::Framebuffer *framebuffer
argument_list|,
argument|const gl::Rectangle&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|const gl::Offset&destOffset
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
argument|const gl::Framebuffer *framebuffer
argument_list|,
argument|const gl::Rectangle&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|const gl::Offset&destOffset
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
argument|const gl::Framebuffer *framebuffer
argument_list|,
argument|const gl::Rectangle&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|const gl::Offset&destOffset
argument_list|,
argument|TextureStorage *storage
argument_list|,
argument|GLint level
argument_list|)
block|;
comment|// RenderTarget creation
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
argument|RenderTargetD3D **outRT
argument_list|)
block|;
comment|// Framebuffer creation
name|FramebufferImpl
operator|*
name|createDefaultFramebuffer
argument_list|(
argument|const gl::Framebuffer::Data&data
argument_list|)
name|override
block|;
name|FramebufferImpl
operator|*
name|createFramebuffer
argument_list|(
argument|const gl::Framebuffer::Data&data
argument_list|)
name|override
block|;
comment|// Shader creation
name|virtual
name|CompilerImpl
operator|*
name|createCompiler
argument_list|(
specifier|const
name|gl
operator|::
name|Data
operator|&
name|data
argument_list|)
block|;
name|virtual
name|ShaderImpl
operator|*
name|createShader
argument_list|(
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
argument|ShaderExecutableD3D **outExecutable
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
argument|const D3DCompilerWorkarounds&workarounds
argument_list|,
argument|ShaderExecutableD3D **outExectuable
argument_list|)
block|;
name|virtual
name|UniformStorageD3D
operator|*
name|createUniformStorage
argument_list|(
argument|size_t storageSize
argument_list|)
block|;
comment|// Image operations
name|virtual
name|ImageD3D
operator|*
name|createImage
argument_list|()
block|;
name|gl
operator|::
name|Error
name|generateMipmap
argument_list|(
argument|ImageD3D *dest
argument_list|,
argument|ImageD3D *source
argument_list|)
name|override
block|;
name|virtual
name|TextureStorage
operator|*
name|createTextureStorage2D
argument_list|(
name|SwapChainD3D
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
argument_list|,
argument|bool hintLevelZeroOnly
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
argument_list|,
argument|bool hintLevelZeroOnly
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
name|ID3D11DeviceContext1
operator|*
name|getDeviceContext1IfSupported
argument_list|()
block|{
return|return
name|mDeviceContext1
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
name|Blit11
operator|*
name|getBlitter
argument_list|()
block|{
return|return
name|mBlit
return|;
block|}
name|Clear11
operator|*
name|getClearer
argument_list|()
block|{
return|return
name|mClear
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
argument|RenderTargetD3D *destRenderTarget
argument_list|,
argument|GLenum destinationFormat
argument_list|,
argument|GLenum sourcePixelsType
argument_list|,
argument|const gl::Box&destArea
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
name|bool
name|getLUID
argument_list|(
argument|LUID *adapterLuid
argument_list|)
specifier|const
name|override
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
name|gl
operator|::
name|Error
name|blitRenderbufferRect
argument_list|(
argument|const gl::Rectangle&readRect
argument_list|,
argument|const gl::Rectangle&drawRect
argument_list|,
argument|RenderTargetD3D *readRenderTarget
argument_list|,
argument|RenderTargetD3D *drawRenderTarget
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
name|bool
name|isES3Capable
argument_list|()
specifier|const
block|;
name|D3D_FEATURE_LEVEL
name|getFeatureLevel
argument_list|()
specifier|const
block|{
return|return
name|mFeatureLevel
return|;
block|}
block|;
name|RendererClass
name|getRendererClass
argument_list|()
specifier|const
name|override
block|{
return|return
name|RENDERER_D3D11
return|;
block|}
name|private
operator|:
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
name|unsetConflictingSRVs
argument_list|(
argument|gl::SamplerType shaderType
argument_list|,
argument|uintptr_t resource
argument_list|,
argument|const gl::ImageIndex *index
argument_list|)
block|;
name|HMODULE
name|mD3d11Module
block|;
name|HMODULE
name|mDxgiModule
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
name|void
name|initializeDevice
argument_list|()
block|;
name|void
name|releaseDeviceResources
argument_list|()
block|;
name|void
name|release
argument_list|()
block|;
name|RenderStateCache
name|mStateCache
block|;
comment|// current render target states
name|uintptr_t
name|mAppliedRTVs
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_DRAW_BUFFERS
index|]
block|;
name|uintptr_t
name|mAppliedDSV
block|;
name|bool
name|mDepthStencilInitialized
block|;
name|bool
name|mRenderTargetDescInitialized
block|;      struct
name|RenderTargetDesc
block|{
name|size_t
name|width
block|;
name|size_t
name|height
block|;
name|DXGI_FORMAT
name|format
block|;     }
block|;
name|RenderTargetDesc
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
block|struct
name|SRVRecord
block|{
name|uintptr_t
name|srv
block|;
name|uintptr_t
name|resource
block|;
name|D3D11_SHADER_RESOURCE_VIEW_DESC
name|desc
block|;     }
block|;
name|std
operator|::
name|vector
operator|<
name|SRVRecord
operator|>
name|mCurVertexSRVs
block|;
name|std
operator|::
name|vector
operator|<
name|SRVRecord
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
name|size_t
name|mAppliedNumXFBBindings
block|;
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
name|uintptr_t
name|mAppliedVertexShader
block|;
name|uintptr_t
name|mAppliedGeometryShader
block|;
name|uintptr_t
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
name|GLintptr
name|mCurrentConstantBufferVSOffset
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_VERTEX_SHADER_UNIFORM_BUFFERS
index|]
block|;
name|GLsizeiptr
name|mCurrentConstantBufferVSSize
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
name|IMPLEMENTATION_MAX_FRAGMENT_SHADER_UNIFORM_BUFFERS
index|]
block|;
name|GLintptr
name|mCurrentConstantBufferPSOffset
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_FRAGMENT_SHADER_UNIFORM_BUFFERS
index|]
block|;
name|GLsizeiptr
name|mCurrentConstantBufferPSSize
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_FRAGMENT_SHADER_UNIFORM_BUFFERS
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
comment|// Perform trim for D3D resources
name|Trim11
operator|*
name|mTrim
block|;
comment|// Sync query
name|ID3D11Query
operator|*
name|mSyncQuery
block|;
comment|// Constant buffer offset support
name|bool
name|mSupportsConstantBufferOffsets
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
name|ID3D11DeviceContext1
operator|*
name|mDeviceContext1
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
block|;
name|DebugAnnotator11
name|mAnnotator
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D11_RENDERER11_H_
end_comment
end_unit
