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
comment|// Renderer9.h: Defines a back-end specific class for the D3D9 renderer.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D9_RENDERER9_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D9_RENDERER9_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D9_RENDERER9_H_
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
file|"libANGLE/renderer/d3d/d3d9/DebugAnnotator9.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/ShaderCache.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/VertexDeclarationCache.h"
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
name|egl
block|{
name|class
name|AttributeMap
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Blit9
decl_stmt|;
name|class
name|IndexDataManager
decl_stmt|;
name|class
name|StreamingIndexBufferInterface
decl_stmt|;
name|class
name|StaticIndexBufferInterface
decl_stmt|;
name|class
name|VertexDataManager
decl_stmt|;
struct_decl|struct
name|ClearParameters
struct_decl|;
struct_decl|struct
name|TranslatedAttribute
struct_decl|;
enum|enum
name|D3D9InitError
block|{
name|D3D9_INIT_SUCCESS
init|=
literal|0
block|,
comment|// Failed to load the D3D or ANGLE compiler
name|D3D9_INIT_COMPILER_ERROR
block|,
comment|// Failed to load a necessary DLL
name|D3D9_INIT_MISSING_DEP
block|,
comment|// Device creation error
name|D3D9_INIT_CREATE_DEVICE_ERROR
block|,
comment|// System does not meet minimum shader spec
name|D3D9_INIT_UNSUPPORTED_VERSION
block|,
comment|// System does not support stretchrect from textures
name|D3D9_INIT_UNSUPPORTED_STRETCHRECT
block|,
comment|// A call returned out of memory or device lost
name|D3D9_INIT_OUT_OF_MEMORY
block|,
comment|// Other unspecified error
name|D3D9_INIT_OTHER_ERROR
block|,
name|NUM_D3D9_INIT_ERRORS
block|}
enum|;
name|class
name|Renderer9
range|:
name|public
name|RendererD3D
block|{
name|public
operator|:
name|explicit
name|Renderer9
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
name|startScene
argument_list|()
block|;
name|void
name|endScene
argument_list|()
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
name|gl
operator|::
name|Error
name|allocateEventQuery
argument_list|(
name|IDirect3DQuery9
operator|*
operator|*
name|outQuery
argument_list|)
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
name|gl
operator|::
name|Error
name|createVertexShader
argument_list|(
argument|const DWORD *function
argument_list|,
argument|size_t length
argument_list|,
argument|IDirect3DVertexShader9 **outShader
argument_list|)
block|;
name|gl
operator|::
name|Error
name|createPixelShader
argument_list|(
argument|const DWORD *function
argument_list|,
argument|size_t length
argument_list|,
argument|IDirect3DPixelShader9 **outShader
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
name|applyRenderTarget
argument_list|(
specifier|const
name|gl
operator|::
name|FramebufferAttachment
operator|*
name|colorBuffer
argument_list|,
specifier|const
name|gl
operator|::
name|FramebufferAttachment
operator|*
name|depthStencilBuffer
argument_list|)
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
name|bool
name|applyPrimitiveType
argument_list|(
argument|GLenum primitiveType
argument_list|,
argument|GLsizei elementCount
argument_list|,
argument|bool usesPointSize
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
name|gl
operator|::
name|Error
name|clear
argument_list|(
specifier|const
name|ClearParameters
operator|&
name|clearParams
argument_list|,
specifier|const
name|gl
operator|::
name|FramebufferAttachment
operator|*
name|colorBuffer
argument_list|,
specifier|const
name|gl
operator|::
name|FramebufferAttachment
operator|*
name|depthStencilBuffer
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
name|DWORD
name|getCapsDeclTypes
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
comment|// D3D9-renderer specific methods
name|gl
operator|::
name|Error
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
name|copyToRenderTarget
argument_list|(
argument|IDirect3DSurface9 *dest
argument_list|,
argument|IDirect3DSurface9 *source
argument_list|,
argument|bool fromManaged
argument_list|)
block|;
name|RendererClass
name|getRendererClass
argument_list|()
specifier|const
name|override
block|{
return|return
name|RENDERER_D3D9
return|;
block|}
name|D3DDEVTYPE
name|getD3D9DeviceType
argument_list|()
specifier|const
block|{
return|return
name|mDeviceType
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
name|void
name|release
argument_list|()
block|;
name|void
name|applyUniformnfv
argument_list|(
name|gl
operator|::
name|LinkedUniform
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
name|LinkedUniform
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
name|LinkedUniform
operator|*
name|targetUniform
argument_list|,
specifier|const
name|GLint
operator|*
name|v
argument_list|)
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
name|drawIndexedPoints
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
name|getCountingIB
argument_list|(
argument|size_t count
argument_list|,
argument|StaticIndexBufferInterface **outIB
argument_list|)
block|;
name|gl
operator|::
name|Error
name|getNullColorbuffer
argument_list|(
specifier|const
name|gl
operator|::
name|FramebufferAttachment
operator|*
name|depthbuffer
argument_list|,
specifier|const
name|gl
operator|::
name|FramebufferAttachment
operator|*
operator|*
name|outColorBuffer
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
name|HRESULT
name|getDeviceStatusCode
argument_list|()
block|;
name|bool
name|isRemovedDeviceResettable
argument_list|()
specifier|const
block|;
name|bool
name|resetRemovedDevice
argument_list|()
block|;
name|UINT
name|mAdapter
block|;
name|D3DDEVTYPE
name|mDeviceType
block|;
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
name|HLSLCompiler
name|mCompiler
block|;
name|Blit9
operator|*
name|mBlit
block|;
name|HWND
name|mDeviceWindow
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
name|mVertexTextureSupport
block|;
comment|// current render target states
name|unsigned
name|int
name|mAppliedRenderTargetSerial
block|;
name|unsigned
name|int
name|mAppliedDepthStencilSerial
block|;
name|bool
name|mDepthStencilInitialized
block|;
name|bool
name|mRenderTargetDescInitialized
block|;
name|unsigned
name|int
name|mCurStencilSize
block|;
name|unsigned
name|int
name|mCurDepthSize
block|;      struct
name|RenderTargetDesc
block|{
name|size_t
name|width
block|;
name|size_t
name|height
block|;
name|D3DFORMAT
name|format
block|;     }
block|;
name|RenderTargetDesc
name|mRenderTargetDesc
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
name|float
name|mCurDepthFront
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
name|ColorF
name|mCurBlendColor
block|;
name|GLuint
name|mCurSampleMask
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
name|unsigned
name|int
operator|>
name|mCurVertexTextureSerials
block|;
name|std
operator|::
name|vector
operator|<
name|unsigned
name|int
operator|>
name|mCurPixelTextureSerials
block|;
name|unsigned
name|int
name|mAppliedIBSerial
block|;
name|IDirect3DVertexShader9
operator|*
name|mAppliedVertexShader
block|;
name|IDirect3DPixelShader9
operator|*
name|mAppliedPixelShader
block|;
name|unsigned
name|int
name|mAppliedProgramSerial
block|;
name|dx_VertexConstants
name|mVertexConstants
block|;
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
block|;
name|StaticIndexBufferInterface
operator|*
name|mCountingIB
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
name|FramebufferAttachment
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
block|;
name|DebugAnnotator9
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
comment|// LIBANGLE_RENDERER_D3D_D3D9_RENDERER9_H_
end_comment
end_unit
