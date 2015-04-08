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
name|LIBANGLE_RENDERER_D3D_RENDERERD3D_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_RENDERERD3D_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_RENDERERD3D_H_
end_define
begin_include
include|#
directive|include
file|"common/MemoryBuffer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Data.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/Renderer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/formatutilsD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/NativeWindow.h"
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
name|egl
block|{
name|class
name|ConfigSet
decl_stmt|;
block|}
end_decl_stmt
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
name|ImageD3D
decl_stmt|;
name|class
name|IndexBuffer
decl_stmt|;
name|class
name|RenderTargetD3D
decl_stmt|;
name|class
name|ShaderExecutableD3D
decl_stmt|;
name|class
name|SwapChainD3D
decl_stmt|;
name|class
name|TextureStorage
decl_stmt|;
name|class
name|UniformStorageD3D
decl_stmt|;
name|class
name|VertexBuffer
decl_stmt|;
enum|enum
name|ShaderType
block|{
name|SHADER_VERTEX
block|,
name|SHADER_PIXEL
block|,
name|SHADER_GEOMETRY
block|}
enum|;
enum|enum
name|RendererClass
block|{
name|RENDERER_D3D11
block|,
name|RENDERER_D3D9
block|, }
enum|;
comment|// Useful for unit testing
name|class
name|BufferFactoryD3D
block|{
name|public
label|:
name|BufferFactoryD3D
argument_list|()
block|{}
name|virtual
operator|~
name|BufferFactoryD3D
argument_list|()
block|{}
name|virtual
name|VertexBuffer
operator|*
name|createVertexBuffer
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|IndexBuffer
modifier|*
name|createIndexBuffer
parameter_list|()
init|=
literal|0
function_decl|;
comment|// TODO(jmadill): add VertexFormatCaps
name|virtual
name|VertexConversionType
name|getVertexConversionType
argument_list|(
specifier|const
name|gl
operator|::
name|VertexFormat
operator|&
name|vertexFormat
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|GLenum
name|getVertexComponentType
argument_list|(
specifier|const
name|gl
operator|::
name|VertexFormat
operator|&
name|vertexFormat
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
name|class
name|RendererD3D
range|:
name|public
name|Renderer
decl_stmt|,
name|public
name|BufferFactoryD3D
block|{
name|public
label|:
name|explicit
name|RendererD3D
argument_list|(
name|egl
operator|::
name|Display
operator|*
name|display
argument_list|)
decl_stmt|;
name|virtual
operator|~
name|RendererD3D
argument_list|()
expr_stmt|;
name|virtual
name|egl
operator|::
name|Error
name|initialize
argument_list|()
operator|=
literal|0
expr_stmt|;
specifier|static
name|RendererD3D
modifier|*
name|makeRendererD3D
parameter_list|(
name|Renderer
modifier|*
name|renderer
parameter_list|)
function_decl|;
name|virtual
name|egl
operator|::
name|ConfigSet
name|generateConfigs
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
name|bool
name|isDeviceLost
argument_list|()
specifier|const
name|override
expr_stmt|;
name|std
operator|::
name|string
name|getVendorString
argument_list|()
specifier|const
name|override
expr_stmt|;
name|virtual
name|int
name|getMinorShaderModel
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|std
operator|::
name|string
name|getShaderModelSuffix
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Direct3D Specific methods
name|virtual
name|GUID
name|getAdapterIdentifier
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|SwapChainD3D
modifier|*
name|createSwapChain
parameter_list|(
name|NativeWindow
name|nativeWindow
parameter_list|,
name|HANDLE
name|shareHandle
parameter_list|,
name|GLenum
name|backBufferFormat
parameter_list|,
name|GLenum
name|depthBufferFormat
parameter_list|)
init|=
literal|0
function_decl|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
name|virtual
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
operator|=
literal|0
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
name|virtual
name|void
name|setScissorRectangle
argument_list|(
specifier|const
name|gl
operator|::
name|Rectangle
operator|&
name|scissor
argument_list|,
name|bool
name|enabled
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|setViewport
argument_list|(
specifier|const
name|gl
operator|::
name|Rectangle
operator|&
name|viewport
argument_list|,
name|float
name|zNear
argument_list|,
name|float
name|zFar
argument_list|,
name|GLenum
name|drawMode
argument_list|,
name|GLenum
name|frontFace
argument_list|,
name|bool
name|ignoreViewport
argument_list|)
init|=
literal|0
decl_stmt|;
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
expr_stmt|;
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
operator|=
literal|0
expr_stmt|;
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
expr_stmt|;
name|virtual
name|bool
name|applyPrimitiveType
parameter_list|(
name|GLenum
name|primitiveType
parameter_list|,
name|GLsizei
name|elementCount
parameter_list|,
name|bool
name|usesPointSize
parameter_list|)
init|=
literal|0
function_decl|;
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
operator|=
literal|0
expr_stmt|;
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
expr_stmt|;
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
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|markAllStateDirty
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|unsigned
name|int
name|getReservedVertexUniformVectors
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|unsigned
name|int
name|getReservedFragmentUniformVectors
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|unsigned
name|int
name|getReservedVertexUniformBuffers
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|unsigned
name|int
name|getReservedFragmentUniformBuffers
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|getShareHandleSupport
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|getPostSubBufferSupport
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|int
name|getMajorShaderModel
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
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
operator|=
literal|0
expr_stmt|;
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
operator|=
literal|0
expr_stmt|;
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
operator|=
literal|0
expr_stmt|;
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
operator|=
literal|0
expr_stmt|;
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
operator|=
literal|0
expr_stmt|;
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
operator|=
literal|0
expr_stmt|;
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
operator|=
literal|0
expr_stmt|;
name|virtual
name|UniformStorageD3D
modifier|*
name|createUniformStorage
parameter_list|(
name|size_t
name|storageSize
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Image operations
name|virtual
name|ImageD3D
modifier|*
name|createImage
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|gl
operator|::
name|Error
name|generateMipmap
argument_list|(
name|ImageD3D
operator|*
name|dest
argument_list|,
name|ImageD3D
operator|*
name|source
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|TextureStorage
modifier|*
name|createTextureStorage2D
parameter_list|(
name|SwapChainD3D
modifier|*
name|swapChain
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|TextureStorage
modifier|*
name|createTextureStorage2D
parameter_list|(
name|GLenum
name|internalformat
parameter_list|,
name|bool
name|renderTarget
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|int
name|levels
parameter_list|,
name|bool
name|hintLevelZeroOnly
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|TextureStorage
modifier|*
name|createTextureStorageCube
parameter_list|(
name|GLenum
name|internalformat
parameter_list|,
name|bool
name|renderTarget
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|levels
parameter_list|,
name|bool
name|hintLevelZeroOnly
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|TextureStorage
modifier|*
name|createTextureStorage3D
parameter_list|(
name|GLenum
name|internalformat
parameter_list|,
name|bool
name|renderTarget
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLsizei
name|depth
parameter_list|,
name|int
name|levels
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|TextureStorage
modifier|*
name|createTextureStorage2DArray
parameter_list|(
name|GLenum
name|internalformat
parameter_list|,
name|bool
name|renderTarget
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLsizei
name|depth
parameter_list|,
name|int
name|levels
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Buffer-to-texture and Texture-to-buffer copies
name|virtual
name|bool
name|supportsFastCopyBufferToTexture
argument_list|(
name|GLenum
name|internalFormat
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
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
operator|=
literal|0
expr_stmt|;
comment|// Device lost
name|void
name|notifyDeviceLost
argument_list|()
name|override
expr_stmt|;
name|virtual
name|bool
name|resetDevice
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|RendererClass
name|getRendererClass
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|gl
operator|::
name|Error
name|getScratchMemoryBuffer
argument_list|(
argument|size_t requestedSize
argument_list|,
argument|MemoryBuffer **bufferOut
argument_list|)
expr_stmt|;
name|protected
label|:
name|virtual
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
operator|=
literal|0
expr_stmt|;
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
expr_stmt|;
name|virtual
name|bool
name|getLUID
argument_list|(
name|LUID
operator|*
name|adapterLuid
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|egl
operator|::
name|Display
operator|*
name|mDisplay
expr_stmt|;
name|bool
name|mDeviceLost
decl_stmt|;
name|private
label|:
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
expr_stmt|;
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
name|gl
operator|::
name|Error
name|applyShaders
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
name|MemoryBuffer
name|mScratchMemoryBuffer
decl_stmt|;
name|unsigned
name|int
name|mScratchMemoryBufferResetCounter
decl_stmt|;
block|}
empty_stmt|;
struct|struct
name|dx_VertexConstants
block|{
name|float
name|depthRange
index|[
literal|4
index|]
decl_stmt|;
name|float
name|viewAdjust
index|[
literal|4
index|]
decl_stmt|;
name|float
name|viewCoords
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|dx_PixelConstants
block|{
name|float
name|depthRange
index|[
literal|4
index|]
decl_stmt|;
name|float
name|viewCoords
index|[
literal|4
index|]
decl_stmt|;
name|float
name|depthFront
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_RENDERERD3D_H_
end_comment
end_unit
