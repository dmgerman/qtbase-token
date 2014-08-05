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
file|"common/mathutil.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/HLSLCompiler.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d9/ShaderCache.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d9/VertexDeclarationCache.h"
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
struct_decl|struct
name|TranslatedAttribute
struct_decl|;
name|class
name|Blit9
decl_stmt|;
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
argument|EGLNativeDisplayType hDc
argument_list|,
argument|EGLint requestedDisplay
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
name|virtual
name|void
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
name|bool
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
argument|gl::Framebuffer *framebuffer
argument_list|,
argument|const gl::BlendState&blendState
argument_list|,
argument|const gl::ColorF&blendColor
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
name|void
name|applyUniforms
argument_list|(
specifier|const
name|gl
operator|::
name|ProgramBinary
operator|&
name|programBinary
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
argument|const gl::VertexAttribute vertexAttributes[]
argument_list|,
argument|const gl::VertexAttribCurrentValueData currentValues[]
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
name|applyTransformFeedbackBuffers
argument_list|(
argument|gl::Buffer *transformFeedbackBuffers[]
argument_list|,
argument|GLintptr offsets[]
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
argument_list|,
argument|bool transformFeedbackActive
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
name|unsigned
name|int
name|getMaxVertexShaderUniformBuffers
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getMaxFragmentShaderUniformBuffers
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
name|unsigned
name|int
name|getMaxTransformFeedbackBuffers
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getMaxTransformFeedbackSeparateComponents
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getMaxTransformFeedbackInterleavedComponents
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getMaxUniformBufferSize
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
name|getMaxRecommendedElementsIndices
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|getMaxRecommendedElementsVertices
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|getSRGBTextureSupport
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|getMajorShaderModel
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
name|virtual
name|GLsizei
name|getMaxSupportedFormatSamples
argument_list|(
argument|GLenum internalFormat
argument_list|)
specifier|const
block|;
name|virtual
name|GLsizei
name|getNumSampleCounts
argument_list|(
argument|GLenum internalFormat
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|getSampleCounts
argument_list|(
argument|GLenum internalFormat
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLint *params
argument_list|)
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
name|copyToRenderTarget
argument_list|(
name|TextureStorageInterface3D
operator|*
name|dest
argument_list|,
name|TextureStorageInterface3D
operator|*
name|source
argument_list|)
block|;
name|virtual
name|bool
name|copyToRenderTarget
argument_list|(
name|TextureStorageInterface2DArray
operator|*
name|dest
argument_list|,
name|TextureStorageInterface2DArray
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
argument|GLint zOffset
argument_list|,
argument|TextureStorageInterface3D *storage
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
argument|GLint zOffset
argument_list|,
argument|TextureStorageInterface2DArray *storage
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
argument|GLuint outputPitch
argument_list|,
argument|const gl::PixelPackState&pack
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
argument_list|,
argument|const std::vector<gl::LinkedVarying>&transformFeedbackVaryings
argument_list|,
argument|bool separatedOutputBuffers
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
argument_list|,
argument|const std::vector<gl::LinkedVarying>&transformFeedbackVaryings
argument_list|,
argument|bool separatedOutputBuffers
argument_list|,
argument|D3DWorkaroundType workaround
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
name|Texture2DImpl
operator|*
name|createTexture2D
argument_list|()
block|;
name|virtual
name|TextureCubeImpl
operator|*
name|createTextureCube
argument_list|()
block|;
name|virtual
name|Texture3DImpl
operator|*
name|createTexture3D
argument_list|()
block|;
name|virtual
name|Texture2DArrayImpl
operator|*
name|createTexture2DArray
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
name|FenceImpl
operator|*
name|createFence
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
name|bool
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
name|virtual
name|bool
name|getLUID
argument_list|(
argument|LUID *adapterLuid
argument_list|)
specifier|const
block|;
name|virtual
name|GLenum
name|getNativeTextureFormat
argument_list|(
argument|GLenum internalFormat
argument_list|)
specifier|const
block|;
name|virtual
name|rx
operator|::
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
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Renderer9
argument_list|)
block|;
name|virtual
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
argument|int minIndex
argument_list|,
argument|gl::Buffer *elementArrayBuffer
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
name|FramebufferAttachment
operator|*
name|getNullColorbuffer
argument_list|(
name|gl
operator|::
name|FramebufferAttachment
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
name|int
name|mMinSwapInterval
block|;
name|int
name|mMaxSwapInterval
block|;
name|bool
name|mVertexTextureSupport
block|;      struct
name|MultisampleSupportInfo
block|{
name|bool
name|supportedSamples
index|[
name|D3DMULTISAMPLE_16_SAMPLES
operator|+
literal|1
index|]
block|;
name|unsigned
name|int
name|maxSupportedSamples
block|;     }
block|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|D3DFORMAT
operator|,
name|MultisampleSupportInfo
operator|>
name|MultisampleSupportMap
expr_stmt|;
name|MultisampleSupportMap
name|mMultiSampleSupport
decl_stmt|;
name|unsigned
name|int
name|mMaxSupportedSamples
decl_stmt|;
name|MultisampleSupportInfo
name|getMultiSampleSupport
parameter_list|(
name|D3DFORMAT
name|format
parameter_list|)
function_decl|;
comment|// current render target states
name|unsigned
name|int
name|mAppliedRenderTargetSerial
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
name|mCurStencilSize
decl_stmt|;
name|unsigned
name|int
name|mCurDepthSize
decl_stmt|;
name|IDirect3DStateBlock9
modifier|*
name|mMaskedClearSavedState
decl_stmt|;
comment|// previously set render states
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
name|bool
name|mCurFrontFaceCCW
decl_stmt|;
name|bool
name|mForceSetRasterState
decl_stmt|;
name|gl
operator|::
name|RasterizerState
name|mCurRasterState
expr_stmt|;
name|bool
name|mForceSetScissor
decl_stmt|;
name|gl
operator|::
name|Rectangle
name|mCurScissor
expr_stmt|;
name|bool
name|mScissorEnabled
decl_stmt|;
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
name|float
name|mCurDepthFront
decl_stmt|;
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
name|ColorF
name|mCurBlendColor
expr_stmt|;
name|GLuint
name|mCurSampleMask
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
name|unsigned
name|int
name|mAppliedIBSerial
decl_stmt|;
name|IDirect3DVertexShader9
modifier|*
name|mAppliedVertexShader
decl_stmt|;
name|IDirect3DPixelShader9
modifier|*
name|mAppliedPixelShader
decl_stmt|;
name|unsigned
name|int
name|mAppliedProgramSerial
decl_stmt|;
name|rx
operator|::
name|dx_VertexConstants
name|mVertexConstants
expr_stmt|;
name|rx
operator|::
name|dx_PixelConstants
name|mPixelConstants
expr_stmt|;
name|bool
name|mDxUniformsDirty
decl_stmt|;
comment|// A pool of event queries that are currently unused.
name|std
operator|::
name|vector
operator|<
name|IDirect3DQuery9
operator|*
operator|>
name|mEventQueryPool
expr_stmt|;
name|VertexShaderCache
name|mVertexShaderCache
decl_stmt|;
name|PixelShaderCache
name|mPixelShaderCache
decl_stmt|;
name|VertexDataManager
modifier|*
name|mVertexDataManager
decl_stmt|;
name|VertexDeclarationCache
name|mVertexDeclarationCache
decl_stmt|;
name|IndexDataManager
modifier|*
name|mIndexDataManager
decl_stmt|;
name|StreamingIndexBufferInterface
modifier|*
name|mLineLoopIB
decl_stmt|;
enum|enum
block|{
name|NUM_NULL_COLORBUFFER_CACHE_ENTRIES
init|=
literal|12
block|}
enum|;
struct|struct
name|NullColorbufferCacheEntry
block|{
name|UINT
name|lruCount
decl_stmt|;
name|int
name|width
decl_stmt|;
name|int
name|height
decl_stmt|;
name|gl
operator|::
name|FramebufferAttachment
operator|*
name|buffer
expr_stmt|;
block|}
name|mNullColorbufferCache
index|[
name|NUM_NULL_COLORBUFFER_CACHE_ENTRIES
index|]
struct|;
name|UINT
name|mMaxNullColorbufferLRU
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
comment|// LIBGLESV2_RENDERER_RENDERER9_H_
end_comment
end_unit
