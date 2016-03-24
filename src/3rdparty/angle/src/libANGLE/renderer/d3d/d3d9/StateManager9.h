begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2015 The ANGLE Project Authors. All rights reserved.
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
comment|// StateManager9.h: Defines a class for caching D3D9 state
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D9_STATEMANAGER9_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D9_STATEMANAGER9_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D9_STATEMANAGER9_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Data.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/State.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/RendererD3D.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer9
decl_stmt|;
struct|struct
name|dx_VertexConstants9
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
name|dx_PixelConstants9
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
name|class
name|StateManager9
name|final
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|StateManager9
argument_list|(
name|Renderer9
operator|*
name|renderer9
argument_list|)
block|;
operator|~
name|StateManager9
argument_list|()
block|;
name|void
name|syncState
argument_list|(
specifier|const
name|gl
operator|::
name|State
operator|&
name|state
argument_list|,
specifier|const
name|gl
operator|::
name|State
operator|::
name|DirtyBits
operator|&
name|dirtyBits
argument_list|)
block|;
name|gl
operator|::
name|Error
name|setBlendDepthRasterStates
argument_list|(
argument|const gl::State&glState
argument_list|,
argument|unsigned int sampleMask
argument_list|)
block|;
name|void
name|setScissorState
argument_list|(
argument|const gl::Rectangle&scissor
argument_list|,
argument|bool enabled
argument_list|)
block|;
name|void
name|setViewportState
argument_list|(
argument|const gl::Caps *caps
argument_list|,
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
name|void
name|setShaderConstants
argument_list|()
block|;
name|void
name|forceSetBlendState
argument_list|()
block|;
name|void
name|forceSetRasterState
argument_list|()
block|;
name|void
name|forceSetDepthStencilState
argument_list|()
block|;
name|void
name|forceSetScissorState
argument_list|()
block|;
name|void
name|forceSetViewportState
argument_list|()
block|;
name|void
name|forceSetDXUniformsState
argument_list|()
block|;
name|void
name|updateDepthSizeIfChanged
argument_list|(
argument|bool depthStencilInitialized
argument_list|,
argument|unsigned int depthSize
argument_list|)
block|;
name|void
name|updateStencilSizeIfChanged
argument_list|(
argument|bool depthStencilInitialized
argument_list|,
argument|unsigned int stencilSize
argument_list|)
block|;
name|void
name|setRenderTargetBounds
argument_list|(
argument|size_t width
argument_list|,
argument|size_t height
argument_list|)
block|;
name|int
name|getRenderTargetWidth
argument_list|()
specifier|const
block|{
return|return
name|mRenderTargetBounds
operator|.
name|width
return|;
block|}
name|int
name|getRenderTargetHeight
argument_list|()
specifier|const
block|{
return|return
name|mRenderTargetBounds
operator|.
name|height
return|;
block|}
name|void
name|resetDirtyBits
argument_list|()
block|{
name|mDirtyBits
operator|.
name|reset
argument_list|()
block|; }
name|private
operator|:
comment|// Blend state functions
name|void
name|setBlendEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|setBlendColor
argument_list|(
specifier|const
name|gl
operator|::
name|BlendState
operator|&
name|blendState
argument_list|,
specifier|const
name|gl
operator|::
name|ColorF
operator|&
name|blendColor
argument_list|)
block|;
name|void
name|setBlendFuncsEquations
argument_list|(
specifier|const
name|gl
operator|::
name|BlendState
operator|&
name|blendState
argument_list|)
block|;
name|void
name|setColorMask
argument_list|(
argument|const gl::Framebuffer *framebuffer
argument_list|,
argument|bool red
argument_list|,
argument|bool blue
argument_list|,
argument|bool green
argument_list|,
argument|bool alpha
argument_list|)
block|;
name|void
name|setSampleAlphaToCoverage
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|setDither
argument_list|(
argument|bool dither
argument_list|)
block|;
name|void
name|setSampleMask
argument_list|(
argument|unsigned int sampleMask
argument_list|)
block|;
comment|// Current raster state functions
name|void
name|setCullMode
argument_list|(
argument|bool cullFace
argument_list|,
argument|GLenum cullMode
argument_list|,
argument|GLenum frontFace
argument_list|)
block|;
name|void
name|setDepthBias
argument_list|(
argument|bool polygonOffsetFill
argument_list|,
argument|GLfloat polygonOffsetFactor
argument_list|,
argument|GLfloat polygonOffsetUnits
argument_list|)
block|;
comment|// Depth stencil state functions
name|void
name|setStencilOpsFront
argument_list|(
argument|GLenum stencilFail
argument_list|,
argument|GLenum stencilPassDepthFail
argument_list|,
argument|GLenum stencilPassDepthPass
argument_list|,
argument|bool frontFaceCCW
argument_list|)
block|;
name|void
name|setStencilOpsBack
argument_list|(
argument|GLenum stencilBackFail
argument_list|,
argument|GLenum stencilBackPassDepthFail
argument_list|,
argument|GLenum stencilBackPassDepthPass
argument_list|,
argument|bool frontFaceCCW
argument_list|)
block|;
name|void
name|setStencilBackWriteMask
argument_list|(
argument|GLuint stencilBackWriteMask
argument_list|,
argument|bool frontFaceCCW
argument_list|)
block|;
name|void
name|setDepthFunc
argument_list|(
argument|bool depthTest
argument_list|,
argument|GLenum depthFunc
argument_list|)
block|;
name|void
name|setStencilTestEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|setDepthMask
argument_list|(
argument|bool depthMask
argument_list|)
block|;
name|void
name|setStencilFuncsFront
argument_list|(
argument|GLenum stencilFunc
argument_list|,
argument|GLuint stencilMask
argument_list|,
argument|GLint stencilRef
argument_list|,
argument|bool frontFaceCCW
argument_list|,
argument|unsigned int maxStencil
argument_list|)
block|;
name|void
name|setStencilFuncsBack
argument_list|(
argument|GLenum stencilBackFunc
argument_list|,
argument|GLuint stencilBackMask
argument_list|,
argument|GLint stencilBackRef
argument_list|,
argument|bool frontFaceCCW
argument_list|,
argument|unsigned int maxStencil
argument_list|)
block|;
name|void
name|setStencilWriteMask
argument_list|(
argument|GLuint stencilWriteMask
argument_list|,
argument|bool frontFaceCCW
argument_list|)
block|;
name|void
name|setScissorEnabled
argument_list|(
argument|bool scissorEnabled
argument_list|)
block|;
name|void
name|setScissorRect
argument_list|(
argument|const gl::Rectangle&scissor
argument_list|,
argument|bool enabled
argument_list|)
block|;      enum
name|DirtyBitType
block|{
comment|// Blend dirty bits
name|DIRTY_BIT_BLEND_ENABLED
block|,
name|DIRTY_BIT_BLEND_COLOR
block|,
name|DIRTY_BIT_BLEND_FUNCS_EQUATIONS
block|,
name|DIRTY_BIT_SAMPLE_ALPHA_TO_COVERAGE
block|,
name|DIRTY_BIT_COLOR_MASK
block|,
name|DIRTY_BIT_DITHER
block|,
name|DIRTY_BIT_SAMPLE_MASK
block|,
comment|// Rasterizer dirty bits
name|DIRTY_BIT_CULL_MODE
block|,
name|DIRTY_BIT_DEPTH_BIAS
block|,
comment|// Depth stencil dirty bits
name|DIRTY_BIT_STENCIL_DEPTH_MASK
block|,
name|DIRTY_BIT_STENCIL_DEPTH_FUNC
block|,
name|DIRTY_BIT_STENCIL_TEST_ENABLED
block|,
name|DIRTY_BIT_STENCIL_FUNCS_FRONT
block|,
name|DIRTY_BIT_STENCIL_FUNCS_BACK
block|,
name|DIRTY_BIT_STENCIL_WRITEMASK_FRONT
block|,
name|DIRTY_BIT_STENCIL_WRITEMASK_BACK
block|,
name|DIRTY_BIT_STENCIL_OPS_FRONT
block|,
name|DIRTY_BIT_STENCIL_OPS_BACK
block|,
comment|// Scissor dirty bits
name|DIRTY_BIT_SCISSOR_ENABLED
block|,
name|DIRTY_BIT_SCISSOR_RECT
block|,
comment|// Viewport dirty bits
name|DIRTY_BIT_VIEWPORT
block|,
name|DIRTY_BIT_MAX
block|}
block|;
typedef|typedef
name|std
operator|::
name|bitset
operator|<
name|DIRTY_BIT_MAX
operator|>
name|DirtyBits
expr_stmt|;
comment|// Currently applied blend state
name|gl
operator|::
name|BlendState
name|mCurBlendState
decl_stmt|;
name|gl
operator|::
name|ColorF
name|mCurBlendColor
expr_stmt|;
name|unsigned
name|int
name|mCurSampleMask
decl_stmt|;
name|DirtyBits
name|mBlendStateDirtyBits
decl_stmt|;
comment|// Currently applied raster state
name|gl
operator|::
name|RasterizerState
name|mCurRasterState
expr_stmt|;
name|unsigned
name|int
name|mCurDepthSize
decl_stmt|;
name|DirtyBits
name|mRasterizerStateDirtyBits
decl_stmt|;
comment|// Currently applied depth stencil state
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
name|unsigned
name|int
name|mCurStencilSize
decl_stmt|;
name|DirtyBits
name|mDepthStencilStateDirtyBits
decl_stmt|;
comment|// Currently applied scissor states
name|gl
operator|::
name|Rectangle
name|mCurScissorRect
expr_stmt|;
name|bool
name|mCurScissorEnabled
decl_stmt|;
name|gl
operator|::
name|Extents
name|mRenderTargetBounds
expr_stmt|;
name|DirtyBits
name|mScissorStateDirtyBits
decl_stmt|;
comment|// Currently applied viewport states
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
name|mCurIgnoreViewport
decl_stmt|;
name|dx_VertexConstants9
name|mVertexConstants
decl_stmt|;
name|dx_PixelConstants9
name|mPixelConstants
decl_stmt|;
name|bool
name|mDxUniformsDirty
decl_stmt|;
comment|// FIXME: Unsupported by D3D9
specifier|static
specifier|const
name|D3DRENDERSTATETYPE
name|D3DRS_CCW_STENCILREF
init|=
name|D3DRS_STENCILREF
decl_stmt|;
specifier|static
specifier|const
name|D3DRENDERSTATETYPE
name|D3DRS_CCW_STENCILMASK
init|=
name|D3DRS_STENCILMASK
decl_stmt|;
specifier|static
specifier|const
name|D3DRENDERSTATETYPE
name|D3DRS_CCW_STENCILWRITEMASK
init|=
name|D3DRS_STENCILWRITEMASK
decl_stmt|;
name|Renderer9
modifier|*
name|mRenderer9
decl_stmt|;
name|DirtyBits
name|mDirtyBits
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
unit|}
comment|// namespace rx
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D9_STATEMANAGER9_H_
end_comment
end_unit
