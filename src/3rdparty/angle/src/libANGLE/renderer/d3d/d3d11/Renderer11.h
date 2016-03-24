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
file|"libANGLE/renderer/d3d/d3d11/renderer11_utils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/RenderStateCache.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/StateManager11.h"
end_include
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
begin_struct_decl
struct_decl|struct
name|ID3D11DeviceContext1
struct_decl|;
end_struct_decl
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
name|Buffer11
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
struct|struct
name|Renderer11DeviceCaps
block|{
name|D3D_FEATURE_LEVEL
name|featureLevel
decl_stmt|;
name|bool
name|supportsDXGI1_2
decl_stmt|;
comment|// Support for DXGI 1.2
name|bool
name|supportsClearView
decl_stmt|;
comment|// Support for ID3D11DeviceContext1::ClearView
name|bool
name|supportsConstantBufferOffsets
decl_stmt|;
comment|// Support for Constant buffer offset
name|UINT
name|B5G6R5support
decl_stmt|;
comment|// Bitfield of D3D11_FORMAT_SUPPORT values for DXGI_FORMAT_B5G6R5_UNORM
name|UINT
name|B4G4R4A4support
decl_stmt|;
comment|// Bitfield of D3D11_FORMAT_SUPPORT values for DXGI_FORMAT_B4G4R4A4_UNORM
name|UINT
name|B5G5R5A1support
decl_stmt|;
comment|// Bitfield of D3D11_FORMAT_SUPPORT values for DXGI_FORMAT_B5G5R5A1_UNORM
block|}
struct|;
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
comment|// CreateDevice returned E_FAIL
name|D3D11_INIT_CREATEDEVICE_FAIL
block|,
comment|// CreateDevice returned E_NOTIMPL
name|D3D11_INIT_CREATEDEVICE_NOTIMPL
block|,
comment|// CreateDevice returned E_OUTOFMEMORY
name|D3D11_INIT_CREATEDEVICE_OUTOFMEMORY
block|,
comment|// CreateDevice returned DXGI_ERROR_INVALID_CALL
name|D3D11_INIT_CREATEDEVICE_INVALIDCALL
block|,
comment|// CreateDevice returned DXGI_ERROR_SDK_COMPONENT_MISSING
name|D3D11_INIT_CREATEDEVICE_COMPONENTMISSING
block|,
comment|// CreateDevice returned DXGI_ERROR_WAS_STILL_DRAWING
name|D3D11_INIT_CREATEDEVICE_WASSTILLDRAWING
block|,
comment|// CreateDevice returned DXGI_ERROR_NOT_CURRENTLY_AVAILABLE
name|D3D11_INIT_CREATEDEVICE_NOTAVAILABLE
block|,
comment|// CreateDevice returned DXGI_ERROR_DEVICE_HUNG
name|D3D11_INIT_CREATEDEVICE_DEVICEHUNG
block|,
comment|// CreateDevice returned NULL
name|D3D11_INIT_CREATEDEVICE_NULL
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
name|void
name|generateDisplayExtensions
argument_list|(
argument|egl::DisplayExtensions *outExtensions
argument_list|)
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
argument_list|,
argument|EGLint orientation
argument_list|)
name|override
block|;
name|CompilerImpl
operator|*
name|createCompiler
argument_list|()
name|override
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
argument|const std::vector<GLint>&vertexUniformBuffers
argument_list|,
argument|const std::vector<GLint>&fragmentUniformBuffers
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|updateState
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum drawMode
argument_list|)
name|override
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
name|gl
operator|::
name|Error
name|applyUniforms
argument_list|(
argument|const ProgramD3D&programD3D
argument_list|,
argument|GLenum drawMode
argument_list|,
argument|const std::vector<D3DUniform *>&uniformArray
argument_list|)
name|override
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
argument_list|,
argument|TranslatedIndexData *indexInfo
argument_list|)
block|;
name|gl
operator|::
name|Error
name|applyIndexBuffer
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|const GLvoid *indices
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum mode
argument_list|,
argument|GLenum type
argument_list|,
argument|TranslatedIndexData *indexInfo
argument_list|)
name|override
block|;
name|void
name|applyTransformFeedbackBuffers
argument_list|(
argument|const gl::State&state
argument_list|)
name|override
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
name|std
operator|::
name|string
name|getRendererDescription
argument_list|()
specifier|const
name|override
block|;
name|DeviceIdentifier
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
name|bool
name|getShareHandleSupport
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
name|gl
operator|::
name|Error
name|createRenderTargetCopy
argument_list|(
argument|RenderTargetD3D *source
argument_list|,
argument|RenderTargetD3D **outRT
argument_list|)
name|override
block|;
comment|// Framebuffer creation
name|FramebufferImpl
operator|*
name|createFramebuffer
argument_list|(
argument|const gl::Framebuffer::Data&data
argument_list|)
name|override
block|;
comment|// Shader creation
name|ShaderImpl
operator|*
name|createShader
argument_list|(
argument|const gl::Shader::Data&data
argument_list|)
name|override
block|;
name|ProgramImpl
operator|*
name|createProgram
argument_list|(
argument|const gl::Program::Data&data
argument_list|)
name|override
block|;
comment|// Shader operations
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
argument|const std::vector<D3DVarying>&streamOutVaryings
argument_list|,
argument|bool separatedOutputBuffers
argument_list|,
argument|ShaderExecutableD3D **outExecutable
argument_list|)
name|override
block|;
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
argument|const std::vector<D3DVarying>&streamOutVaryings
argument_list|,
argument|bool separatedOutputBuffers
argument_list|,
argument|const D3DCompilerWorkarounds&workarounds
argument_list|,
argument|ShaderExecutableD3D **outExectuable
argument_list|)
name|override
block|;
name|UniformStorageD3D
operator|*
name|createUniformStorage
argument_list|(
argument|size_t storageSize
argument_list|)
name|override
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
name|gl
operator|::
name|Error
name|generateMipmapsUsingD3D
argument_list|(
argument|TextureStorage *storage
argument_list|,
argument|const gl::TextureState&textureState
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
name|TextureStorage
operator|*
name|createTextureStorageEGLImage
argument_list|(
argument|EGLImageD3D *eglImage
argument_list|)
name|override
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
name|VertexArrayImpl
operator|*
name|createVertexArray
argument_list|(
argument|const gl::VertexArray::Data&data
argument_list|)
name|override
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
name|void
operator|*
name|getD3DDevice
argument_list|()
name|override
block|;
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
name|RenderStateCache
operator|&
name|getStateCache
argument_list|()
block|{
return|return
name|mStateCache
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
name|markAllStateDirty
argument_list|()
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
specifier|const
name|TextureHelper11
operator|&
name|textureHelper
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
name|VertexConversionType
name|getVertexConversionType
argument_list|(
argument|gl::VertexFormatType vertexFormatType
argument_list|)
specifier|const
name|override
block|;
name|GLenum
name|getVertexComponentType
argument_list|(
argument|gl::VertexFormatType vertexFormatType
argument_list|)
specifier|const
name|override
block|;
name|gl
operator|::
name|Error
name|readFromAttachment
argument_list|(
argument|const gl::FramebufferAttachment&srcAttachment
argument_list|,
argument|const gl::Rectangle&sourceArea
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
specifier|const
name|Renderer11DeviceCaps
operator|&
name|getRenderer11DeviceCaps
argument_list|()
block|{
return|return
name|mRenderer11DeviceCaps
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
name|InputLayoutCache
operator|*
name|getInputLayoutCache
argument_list|()
block|{
return|return
operator|&
name|mInputLayoutCache
return|;
block|}
name|StateManager11
operator|*
name|getStateManager
argument_list|()
block|{
return|return
operator|&
name|mStateManager
return|;
block|}
name|void
name|onSwap
argument_list|()
block|;
name|void
name|onBufferDelete
argument_list|(
specifier|const
name|Buffer11
operator|*
name|deleted
argument_list|)
block|;
name|egl
operator|::
name|Error
name|getEGLDevice
argument_list|(
argument|DeviceImpl **device
argument_list|)
name|override
block|;
name|protected
operator|:
name|void
name|createAnnotator
argument_list|()
name|override
block|;
name|gl
operator|::
name|Error
name|clearTextures
argument_list|(
argument|gl::SamplerType samplerType
argument_list|,
argument|size_t rangeStart
argument_list|,
argument|size_t rangeEnd
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|applyShadersImpl
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum drawMode
argument_list|)
name|override
block|;
name|void
name|syncState
argument_list|(
argument|const gl::State&state
argument_list|,
argument|const gl::State::DirtyBits&bitmask
argument_list|)
name|override
block|;
name|private
operator|:
name|gl
operator|::
name|Error
name|drawArraysImpl
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum mode
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
name|drawElementsImpl
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|const TranslatedIndexData&indexInfo
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
argument_list|)
name|override
block|;
name|void
name|generateCaps
argument_list|(
argument|gl::Caps *outCaps
argument_list|,
argument|gl::TextureCapsMap *outTextureCaps
argument_list|,
argument|gl::Extensions *outExtensions
argument_list|,
argument|gl::Limitations *outLimitations
argument_list|)
specifier|const
name|override
block|;
name|WorkaroundsD3D
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
argument|const gl::Data&data
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid *indices
argument_list|,
argument|const TranslatedIndexData *indexInfo
argument_list|,
argument|int instances
argument_list|)
block|;
name|gl
operator|::
name|Error
name|drawTriangleFan
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid *indices
argument_list|,
argument|int minIndex
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
name|populateRenderer11DeviceCaps
argument_list|()
block|;
name|void
name|updateHistograms
argument_list|()
block|;
name|HMODULE
name|mD3d11Module
block|;
name|HMODULE
name|mDxgiModule
block|;
name|HMODULE
name|mDCompModule
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
name|mRequestedDriverType
block|;
name|bool
name|mCreatedWithDeviceEXT
block|;
name|DeviceD3D
operator|*
name|mEGLDevice
block|;
name|HLSLCompiler
name|mCompiler
block|;
name|egl
operator|::
name|Error
name|initializeD3DDevice
argument_list|()
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
name|d3d11
operator|::
name|ANGLED3D11DeviceType
name|getDeviceType
argument_list|()
specifier|const
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
name|StateManager11
name|mStateManager
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
name|bool
name|mAppliedIBChanged
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
name|dx_VertexConstants11
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
name|dx_PixelConstants11
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
comment|// Created objects state tracking
name|std
operator|::
name|set
operator|<
specifier|const
name|Buffer11
operator|*
operator|>
name|mAliveBuffers
block|;
name|double
name|mLastHistogramUpdateTime
block|;
name|ID3D11Device
operator|*
name|mDevice
block|;
name|Renderer11DeviceCaps
name|mRenderer11DeviceCaps
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
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_MINGW32_COMPAT
argument_list|)
name|ID3D11Debug
operator|*
name|mDebug
block|;
endif|#
directive|endif
name|std
operator|::
name|vector
operator|<
name|GLuint
operator|>
name|mScratchIndexDataBuffer
block|;
name|mutable
name|Optional
operator|<
name|bool
operator|>
name|mSupportsShareHandles
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
