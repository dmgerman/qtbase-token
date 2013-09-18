begin_unit
begin_include
include|#
directive|include
file|"precompiled.h"
end_include
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
comment|// RenderStateCache.cpp: Defines rx::RenderStateCache, a cache of Direct3D render
end_comment
begin_comment
comment|// state objects.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/RenderStateCache.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/renderer11_utils.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"third_party/murmurhash/MurmurHash3.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
comment|// MSDN's documentation of ID3D11Device::CreateBlendState, ID3D11Device::CreateRasterizerState,
comment|// ID3D11Device::CreateDepthStencilState and ID3D11Device::CreateSamplerState claims the maximum
comment|// number of unique states of each type an application can create is 4096
DECL|member|kMaxBlendStates
specifier|const
name|unsigned
name|int
name|RenderStateCache
operator|::
name|kMaxBlendStates
init|=
literal|4096
decl_stmt|;
DECL|member|kMaxRasterizerStates
specifier|const
name|unsigned
name|int
name|RenderStateCache
operator|::
name|kMaxRasterizerStates
init|=
literal|4096
decl_stmt|;
DECL|member|kMaxDepthStencilStates
specifier|const
name|unsigned
name|int
name|RenderStateCache
operator|::
name|kMaxDepthStencilStates
init|=
literal|4096
decl_stmt|;
DECL|member|kMaxSamplerStates
specifier|const
name|unsigned
name|int
name|RenderStateCache
operator|::
name|kMaxSamplerStates
init|=
literal|4096
decl_stmt|;
DECL|function|RenderStateCache
name|RenderStateCache
operator|::
name|RenderStateCache
parameter_list|()
member_init_list|:
name|mDevice
argument_list|(
name|NULL
argument_list|)
member_init_list|,
name|mCounter
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mBlendStateCache
argument_list|(
name|kMaxBlendStates
argument_list|,
name|hashBlendState
argument_list|,
name|compareBlendStates
argument_list|)
member_init_list|,
name|mRasterizerStateCache
argument_list|(
name|kMaxRasterizerStates
argument_list|,
name|hashRasterizerState
argument_list|,
name|compareRasterizerStates
argument_list|)
member_init_list|,
name|mDepthStencilStateCache
argument_list|(
name|kMaxDepthStencilStates
argument_list|,
name|hashDepthStencilState
argument_list|,
name|compareDepthStencilStates
argument_list|)
member_init_list|,
name|mSamplerStateCache
argument_list|(
name|kMaxSamplerStates
argument_list|,
name|hashSamplerState
argument_list|,
name|compareSamplerStates
argument_list|)
block|{ }
DECL|function|~RenderStateCache
name|RenderStateCache
operator|::
name|~
name|RenderStateCache
parameter_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|initialize
name|void
name|RenderStateCache
operator|::
name|initialize
parameter_list|(
name|ID3D11Device
modifier|*
name|device
parameter_list|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|mDevice
operator|=
name|device
expr_stmt|;
block|}
DECL|function|clear
name|void
name|RenderStateCache
operator|::
name|clear
parameter_list|()
block|{
for|for
control|(
name|BlendStateMap
operator|::
name|iterator
name|i
init|=
name|mBlendStateCache
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mBlendStateCache
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|i
operator|->
name|second
operator|.
name|first
operator|->
name|Release
argument_list|()
expr_stmt|;
block|}
name|mBlendStateCache
operator|.
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|RasterizerStateMap
operator|::
name|iterator
name|i
init|=
name|mRasterizerStateCache
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mRasterizerStateCache
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|i
operator|->
name|second
operator|.
name|first
operator|->
name|Release
argument_list|()
expr_stmt|;
block|}
name|mRasterizerStateCache
operator|.
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|DepthStencilStateMap
operator|::
name|iterator
name|i
init|=
name|mDepthStencilStateCache
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mDepthStencilStateCache
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|i
operator|->
name|second
operator|.
name|first
operator|->
name|Release
argument_list|()
expr_stmt|;
block|}
name|mDepthStencilStateCache
operator|.
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|SamplerStateMap
operator|::
name|iterator
name|i
init|=
name|mSamplerStateCache
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mSamplerStateCache
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|i
operator|->
name|second
operator|.
name|first
operator|->
name|Release
argument_list|()
expr_stmt|;
block|}
name|mSamplerStateCache
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|hashBlendState
name|std
operator|::
name|size_t
name|RenderStateCache
operator|::
name|hashBlendState
parameter_list|(
specifier|const
name|gl
operator|::
name|BlendState
modifier|&
name|blendState
parameter_list|)
block|{
specifier|static
specifier|const
name|unsigned
name|int
name|seed
init|=
literal|0xABCDEF98
decl_stmt|;
name|std
operator|::
name|size_t
name|hash
init|=
literal|0
decl_stmt|;
name|MurmurHash3_x86_32
argument_list|(
operator|&
name|blendState
argument_list|,
sizeof|sizeof
argument_list|(
name|gl
operator|::
name|BlendState
argument_list|)
argument_list|,
name|seed
argument_list|,
operator|&
name|hash
argument_list|)
expr_stmt|;
return|return
name|hash
return|;
block|}
DECL|function|compareBlendStates
name|bool
name|RenderStateCache
operator|::
name|compareBlendStates
parameter_list|(
specifier|const
name|gl
operator|::
name|BlendState
modifier|&
name|a
parameter_list|,
specifier|const
name|gl
operator|::
name|BlendState
modifier|&
name|b
parameter_list|)
block|{
return|return
name|memcmp
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|gl
operator|::
name|BlendState
argument_list|)
argument_list|)
operator|==
literal|0
return|;
block|}
DECL|function|getBlendState
name|ID3D11BlendState
modifier|*
name|RenderStateCache
operator|::
name|getBlendState
parameter_list|(
specifier|const
name|gl
operator|::
name|BlendState
modifier|&
name|blendState
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mDevice
condition|)
block|{
name|ERR
argument_list|(
literal|"RenderStateCache is not initialized."
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|BlendStateMap
operator|::
name|iterator
name|i
init|=
name|mBlendStateCache
operator|.
name|find
argument_list|(
name|blendState
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|!=
name|mBlendStateCache
operator|.
name|end
argument_list|()
condition|)
block|{
name|BlendStateCounterPair
modifier|&
name|state
init|=
name|i
operator|->
name|second
decl_stmt|;
name|state
operator|.
name|second
operator|=
name|mCounter
operator|++
expr_stmt|;
return|return
name|state
operator|.
name|first
return|;
block|}
else|else
block|{
if|if
condition|(
name|mBlendStateCache
operator|.
name|size
argument_list|()
operator|>=
name|kMaxBlendStates
condition|)
block|{
name|TRACE
argument_list|(
literal|"Overflowed the limit of %u blend states, removing the least recently used "
literal|"to make room."
argument_list|,
name|kMaxBlendStates
argument_list|)
expr_stmt|;
name|BlendStateMap
operator|::
name|iterator
name|leastRecentlyUsed
init|=
name|mBlendStateCache
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
name|BlendStateMap
operator|::
name|iterator
name|i
init|=
name|mBlendStateCache
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mBlendStateCache
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|->
name|second
operator|.
name|second
operator|<
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|second
condition|)
block|{
name|leastRecentlyUsed
operator|=
name|i
expr_stmt|;
block|}
block|}
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|first
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mBlendStateCache
operator|.
name|erase
argument_list|(
name|leastRecentlyUsed
argument_list|)
expr_stmt|;
block|}
comment|// Create a new blend state and insert it into the cache
name|D3D11_BLEND_DESC
name|blendDesc
init|=
block|{
literal|0
block|}
decl_stmt|;
name|blendDesc
operator|.
name|AlphaToCoverageEnable
operator|=
name|blendState
operator|.
name|sampleAlphaToCoverage
expr_stmt|;
name|blendDesc
operator|.
name|IndependentBlendEnable
operator|=
name|FALSE
expr_stmt|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT
condition|;
name|i
operator|++
control|)
block|{
name|D3D11_RENDER_TARGET_BLEND_DESC
modifier|&
name|rtBlend
init|=
name|blendDesc
operator|.
name|RenderTarget
index|[
name|i
index|]
decl_stmt|;
name|rtBlend
operator|.
name|BlendEnable
operator|=
name|blendState
operator|.
name|blend
expr_stmt|;
if|if
condition|(
name|blendState
operator|.
name|blend
condition|)
block|{
name|rtBlend
operator|.
name|SrcBlend
operator|=
name|gl_d3d11
operator|::
name|ConvertBlendFunc
argument_list|(
name|blendState
operator|.
name|sourceBlendRGB
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|rtBlend
operator|.
name|DestBlend
operator|=
name|gl_d3d11
operator|::
name|ConvertBlendFunc
argument_list|(
name|blendState
operator|.
name|destBlendRGB
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|rtBlend
operator|.
name|BlendOp
operator|=
name|gl_d3d11
operator|::
name|ConvertBlendOp
argument_list|(
name|blendState
operator|.
name|blendEquationRGB
argument_list|)
expr_stmt|;
name|rtBlend
operator|.
name|SrcBlendAlpha
operator|=
name|gl_d3d11
operator|::
name|ConvertBlendFunc
argument_list|(
name|blendState
operator|.
name|sourceBlendAlpha
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|rtBlend
operator|.
name|DestBlendAlpha
operator|=
name|gl_d3d11
operator|::
name|ConvertBlendFunc
argument_list|(
name|blendState
operator|.
name|destBlendAlpha
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|rtBlend
operator|.
name|BlendOpAlpha
operator|=
name|gl_d3d11
operator|::
name|ConvertBlendOp
argument_list|(
name|blendState
operator|.
name|blendEquationAlpha
argument_list|)
expr_stmt|;
block|}
name|rtBlend
operator|.
name|RenderTargetWriteMask
operator|=
name|gl_d3d11
operator|::
name|ConvertColorMask
argument_list|(
name|blendState
operator|.
name|colorMaskRed
argument_list|,
name|blendState
operator|.
name|colorMaskGreen
argument_list|,
name|blendState
operator|.
name|colorMaskBlue
argument_list|,
name|blendState
operator|.
name|colorMaskAlpha
argument_list|)
expr_stmt|;
block|}
name|ID3D11BlendState
modifier|*
name|dx11BlendState
init|=
name|NULL
decl_stmt|;
name|HRESULT
name|result
init|=
name|mDevice
operator|->
name|CreateBlendState
argument_list|(
operator|&
name|blendDesc
argument_list|,
operator|&
name|dx11BlendState
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
operator|||
operator|!
name|dx11BlendState
condition|)
block|{
name|ERR
argument_list|(
literal|"Unable to create a ID3D11BlendState, HRESULT: 0x%X."
argument_list|,
name|result
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|mBlendStateCache
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|blendState
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
name|dx11BlendState
argument_list|,
name|mCounter
operator|++
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|dx11BlendState
return|;
block|}
block|}
DECL|function|hashRasterizerState
name|std
operator|::
name|size_t
name|RenderStateCache
operator|::
name|hashRasterizerState
parameter_list|(
specifier|const
name|RasterizerStateKey
modifier|&
name|rasterState
parameter_list|)
block|{
specifier|static
specifier|const
name|unsigned
name|int
name|seed
init|=
literal|0xABCDEF98
decl_stmt|;
name|std
operator|::
name|size_t
name|hash
init|=
literal|0
decl_stmt|;
name|MurmurHash3_x86_32
argument_list|(
operator|&
name|rasterState
argument_list|,
sizeof|sizeof
argument_list|(
name|RasterizerStateKey
argument_list|)
argument_list|,
name|seed
argument_list|,
operator|&
name|hash
argument_list|)
expr_stmt|;
return|return
name|hash
return|;
block|}
DECL|function|compareRasterizerStates
name|bool
name|RenderStateCache
operator|::
name|compareRasterizerStates
parameter_list|(
specifier|const
name|RasterizerStateKey
modifier|&
name|a
parameter_list|,
specifier|const
name|RasterizerStateKey
modifier|&
name|b
parameter_list|)
block|{
return|return
name|memcmp
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|RasterizerStateKey
argument_list|)
argument_list|)
operator|==
literal|0
return|;
block|}
DECL|function|getRasterizerState
name|ID3D11RasterizerState
modifier|*
name|RenderStateCache
operator|::
name|getRasterizerState
parameter_list|(
specifier|const
name|gl
operator|::
name|RasterizerState
modifier|&
name|rasterState
parameter_list|,
name|bool
name|scissorEnabled
parameter_list|,
name|unsigned
name|int
name|depthSize
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mDevice
condition|)
block|{
name|ERR
argument_list|(
literal|"RenderStateCache is not initialized."
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|RasterizerStateKey
name|key
decl_stmt|;
name|key
operator|.
name|rasterizerState
operator|=
name|rasterState
expr_stmt|;
name|key
operator|.
name|scissorEnabled
operator|=
name|scissorEnabled
expr_stmt|;
name|key
operator|.
name|depthSize
operator|=
name|depthSize
expr_stmt|;
name|RasterizerStateMap
operator|::
name|iterator
name|i
init|=
name|mRasterizerStateCache
operator|.
name|find
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|!=
name|mRasterizerStateCache
operator|.
name|end
argument_list|()
condition|)
block|{
name|RasterizerStateCounterPair
modifier|&
name|state
init|=
name|i
operator|->
name|second
decl_stmt|;
name|state
operator|.
name|second
operator|=
name|mCounter
operator|++
expr_stmt|;
return|return
name|state
operator|.
name|first
return|;
block|}
else|else
block|{
if|if
condition|(
name|mRasterizerStateCache
operator|.
name|size
argument_list|()
operator|>=
name|kMaxRasterizerStates
condition|)
block|{
name|TRACE
argument_list|(
literal|"Overflowed the limit of %u rasterizer states, removing the least recently used "
literal|"to make room."
argument_list|,
name|kMaxRasterizerStates
argument_list|)
expr_stmt|;
name|RasterizerStateMap
operator|::
name|iterator
name|leastRecentlyUsed
init|=
name|mRasterizerStateCache
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
name|RasterizerStateMap
operator|::
name|iterator
name|i
init|=
name|mRasterizerStateCache
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mRasterizerStateCache
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|->
name|second
operator|.
name|second
operator|<
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|second
condition|)
block|{
name|leastRecentlyUsed
operator|=
name|i
expr_stmt|;
block|}
block|}
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|first
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mRasterizerStateCache
operator|.
name|erase
argument_list|(
name|leastRecentlyUsed
argument_list|)
expr_stmt|;
block|}
name|D3D11_CULL_MODE
name|cullMode
init|=
name|gl_d3d11
operator|::
name|ConvertCullMode
argument_list|(
name|rasterState
operator|.
name|cullFace
argument_list|,
name|rasterState
operator|.
name|cullMode
argument_list|)
decl_stmt|;
comment|// Disable culling if drawing points
if|if
condition|(
name|rasterState
operator|.
name|pointDrawMode
condition|)
block|{
name|cullMode
operator|=
name|D3D11_CULL_NONE
expr_stmt|;
block|}
name|D3D11_RASTERIZER_DESC
name|rasterDesc
decl_stmt|;
name|rasterDesc
operator|.
name|FillMode
operator|=
name|D3D11_FILL_SOLID
expr_stmt|;
name|rasterDesc
operator|.
name|CullMode
operator|=
name|cullMode
expr_stmt|;
name|rasterDesc
operator|.
name|FrontCounterClockwise
operator|=
operator|(
name|rasterState
operator|.
name|frontFace
operator|==
name|GL_CCW
operator|)
condition|?
name|FALSE
else|:
name|TRUE
expr_stmt|;
name|rasterDesc
operator|.
name|DepthBias
operator|=
name|ldexp
argument_list|(
name|rasterState
operator|.
name|polygonOffsetUnits
argument_list|,
operator|-
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|depthSize
argument_list|)
argument_list|)
expr_stmt|;
name|rasterDesc
operator|.
name|DepthBiasClamp
operator|=
literal|0.0f
expr_stmt|;
comment|// MSDN documentation of DepthBiasClamp implies a value of zero will preform no clamping, must be tested though.
name|rasterDesc
operator|.
name|SlopeScaledDepthBias
operator|=
name|rasterState
operator|.
name|polygonOffsetFactor
expr_stmt|;
name|rasterDesc
operator|.
name|DepthClipEnable
operator|=
name|TRUE
expr_stmt|;
name|rasterDesc
operator|.
name|ScissorEnable
operator|=
name|scissorEnabled
condition|?
name|TRUE
else|:
name|FALSE
expr_stmt|;
name|rasterDesc
operator|.
name|MultisampleEnable
operator|=
name|rasterState
operator|.
name|multiSample
expr_stmt|;
name|rasterDesc
operator|.
name|AntialiasedLineEnable
operator|=
name|FALSE
expr_stmt|;
name|ID3D11RasterizerState
modifier|*
name|dx11RasterizerState
init|=
name|NULL
decl_stmt|;
name|HRESULT
name|result
init|=
name|mDevice
operator|->
name|CreateRasterizerState
argument_list|(
operator|&
name|rasterDesc
argument_list|,
operator|&
name|dx11RasterizerState
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
operator|||
operator|!
name|dx11RasterizerState
condition|)
block|{
name|ERR
argument_list|(
literal|"Unable to create a ID3D11RasterizerState, HRESULT: 0x%X."
argument_list|,
name|result
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|mRasterizerStateCache
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|key
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
name|dx11RasterizerState
argument_list|,
name|mCounter
operator|++
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|dx11RasterizerState
return|;
block|}
block|}
DECL|function|hashDepthStencilState
name|std
operator|::
name|size_t
name|RenderStateCache
operator|::
name|hashDepthStencilState
parameter_list|(
specifier|const
name|gl
operator|::
name|DepthStencilState
modifier|&
name|dsState
parameter_list|)
block|{
specifier|static
specifier|const
name|unsigned
name|int
name|seed
init|=
literal|0xABCDEF98
decl_stmt|;
name|std
operator|::
name|size_t
name|hash
init|=
literal|0
decl_stmt|;
name|MurmurHash3_x86_32
argument_list|(
operator|&
name|dsState
argument_list|,
sizeof|sizeof
argument_list|(
name|gl
operator|::
name|DepthStencilState
argument_list|)
argument_list|,
name|seed
argument_list|,
operator|&
name|hash
argument_list|)
expr_stmt|;
return|return
name|hash
return|;
block|}
DECL|function|compareDepthStencilStates
name|bool
name|RenderStateCache
operator|::
name|compareDepthStencilStates
parameter_list|(
specifier|const
name|gl
operator|::
name|DepthStencilState
modifier|&
name|a
parameter_list|,
specifier|const
name|gl
operator|::
name|DepthStencilState
modifier|&
name|b
parameter_list|)
block|{
return|return
name|memcmp
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|gl
operator|::
name|DepthStencilState
argument_list|)
argument_list|)
operator|==
literal|0
return|;
block|}
DECL|function|getDepthStencilState
name|ID3D11DepthStencilState
modifier|*
name|RenderStateCache
operator|::
name|getDepthStencilState
parameter_list|(
specifier|const
name|gl
operator|::
name|DepthStencilState
modifier|&
name|dsState
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mDevice
condition|)
block|{
name|ERR
argument_list|(
literal|"RenderStateCache is not initialized."
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|DepthStencilStateMap
operator|::
name|iterator
name|i
init|=
name|mDepthStencilStateCache
operator|.
name|find
argument_list|(
name|dsState
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|!=
name|mDepthStencilStateCache
operator|.
name|end
argument_list|()
condition|)
block|{
name|DepthStencilStateCounterPair
modifier|&
name|state
init|=
name|i
operator|->
name|second
decl_stmt|;
name|state
operator|.
name|second
operator|=
name|mCounter
operator|++
expr_stmt|;
return|return
name|state
operator|.
name|first
return|;
block|}
else|else
block|{
if|if
condition|(
name|mDepthStencilStateCache
operator|.
name|size
argument_list|()
operator|>=
name|kMaxDepthStencilStates
condition|)
block|{
name|TRACE
argument_list|(
literal|"Overflowed the limit of %u depth stencil states, removing the least recently used "
literal|"to make room."
argument_list|,
name|kMaxDepthStencilStates
argument_list|)
expr_stmt|;
name|DepthStencilStateMap
operator|::
name|iterator
name|leastRecentlyUsed
init|=
name|mDepthStencilStateCache
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
name|DepthStencilStateMap
operator|::
name|iterator
name|i
init|=
name|mDepthStencilStateCache
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mDepthStencilStateCache
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|->
name|second
operator|.
name|second
operator|<
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|second
condition|)
block|{
name|leastRecentlyUsed
operator|=
name|i
expr_stmt|;
block|}
block|}
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|first
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mDepthStencilStateCache
operator|.
name|erase
argument_list|(
name|leastRecentlyUsed
argument_list|)
expr_stmt|;
block|}
name|D3D11_DEPTH_STENCIL_DESC
name|dsDesc
init|=
block|{
literal|0
block|}
decl_stmt|;
name|dsDesc
operator|.
name|DepthEnable
operator|=
name|dsState
operator|.
name|depthTest
condition|?
name|TRUE
else|:
name|FALSE
expr_stmt|;
name|dsDesc
operator|.
name|DepthWriteMask
operator|=
name|gl_d3d11
operator|::
name|ConvertDepthMask
argument_list|(
name|dsState
operator|.
name|depthMask
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|DepthFunc
operator|=
name|gl_d3d11
operator|::
name|ConvertComparison
argument_list|(
name|dsState
operator|.
name|depthFunc
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|StencilEnable
operator|=
name|dsState
operator|.
name|stencilTest
condition|?
name|TRUE
else|:
name|FALSE
expr_stmt|;
name|dsDesc
operator|.
name|StencilReadMask
operator|=
name|gl_d3d11
operator|::
name|ConvertStencilMask
argument_list|(
name|dsState
operator|.
name|stencilMask
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|StencilWriteMask
operator|=
name|gl_d3d11
operator|::
name|ConvertStencilMask
argument_list|(
name|dsState
operator|.
name|stencilWritemask
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|FrontFace
operator|.
name|StencilFailOp
operator|=
name|gl_d3d11
operator|::
name|ConvertStencilOp
argument_list|(
name|dsState
operator|.
name|stencilFail
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|FrontFace
operator|.
name|StencilDepthFailOp
operator|=
name|gl_d3d11
operator|::
name|ConvertStencilOp
argument_list|(
name|dsState
operator|.
name|stencilPassDepthFail
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|FrontFace
operator|.
name|StencilPassOp
operator|=
name|gl_d3d11
operator|::
name|ConvertStencilOp
argument_list|(
name|dsState
operator|.
name|stencilPassDepthPass
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|FrontFace
operator|.
name|StencilFunc
operator|=
name|gl_d3d11
operator|::
name|ConvertComparison
argument_list|(
name|dsState
operator|.
name|stencilFunc
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|BackFace
operator|.
name|StencilFailOp
operator|=
name|gl_d3d11
operator|::
name|ConvertStencilOp
argument_list|(
name|dsState
operator|.
name|stencilBackFail
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|BackFace
operator|.
name|StencilDepthFailOp
operator|=
name|gl_d3d11
operator|::
name|ConvertStencilOp
argument_list|(
name|dsState
operator|.
name|stencilBackPassDepthFail
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|BackFace
operator|.
name|StencilPassOp
operator|=
name|gl_d3d11
operator|::
name|ConvertStencilOp
argument_list|(
name|dsState
operator|.
name|stencilBackPassDepthPass
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|BackFace
operator|.
name|StencilFunc
operator|=
name|gl_d3d11
operator|::
name|ConvertComparison
argument_list|(
name|dsState
operator|.
name|stencilBackFunc
argument_list|)
expr_stmt|;
name|ID3D11DepthStencilState
modifier|*
name|dx11DepthStencilState
init|=
name|NULL
decl_stmt|;
name|HRESULT
name|result
init|=
name|mDevice
operator|->
name|CreateDepthStencilState
argument_list|(
operator|&
name|dsDesc
argument_list|,
operator|&
name|dx11DepthStencilState
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
operator|||
operator|!
name|dx11DepthStencilState
condition|)
block|{
name|ERR
argument_list|(
literal|"Unable to create a ID3D11DepthStencilState, HRESULT: 0x%X."
argument_list|,
name|result
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|mDepthStencilStateCache
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|dsState
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
name|dx11DepthStencilState
argument_list|,
name|mCounter
operator|++
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|dx11DepthStencilState
return|;
block|}
block|}
DECL|function|hashSamplerState
name|std
operator|::
name|size_t
name|RenderStateCache
operator|::
name|hashSamplerState
parameter_list|(
specifier|const
name|gl
operator|::
name|SamplerState
modifier|&
name|samplerState
parameter_list|)
block|{
specifier|static
specifier|const
name|unsigned
name|int
name|seed
init|=
literal|0xABCDEF98
decl_stmt|;
name|std
operator|::
name|size_t
name|hash
init|=
literal|0
decl_stmt|;
name|MurmurHash3_x86_32
argument_list|(
operator|&
name|samplerState
argument_list|,
sizeof|sizeof
argument_list|(
name|gl
operator|::
name|SamplerState
argument_list|)
argument_list|,
name|seed
argument_list|,
operator|&
name|hash
argument_list|)
expr_stmt|;
return|return
name|hash
return|;
block|}
DECL|function|compareSamplerStates
name|bool
name|RenderStateCache
operator|::
name|compareSamplerStates
parameter_list|(
specifier|const
name|gl
operator|::
name|SamplerState
modifier|&
name|a
parameter_list|,
specifier|const
name|gl
operator|::
name|SamplerState
modifier|&
name|b
parameter_list|)
block|{
return|return
name|memcmp
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|gl
operator|::
name|SamplerState
argument_list|)
argument_list|)
operator|==
literal|0
return|;
block|}
DECL|function|getSamplerState
name|ID3D11SamplerState
modifier|*
name|RenderStateCache
operator|::
name|getSamplerState
parameter_list|(
specifier|const
name|gl
operator|::
name|SamplerState
modifier|&
name|samplerState
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mDevice
condition|)
block|{
name|ERR
argument_list|(
literal|"RenderStateCache is not initialized."
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|SamplerStateMap
operator|::
name|iterator
name|i
init|=
name|mSamplerStateCache
operator|.
name|find
argument_list|(
name|samplerState
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|!=
name|mSamplerStateCache
operator|.
name|end
argument_list|()
condition|)
block|{
name|SamplerStateCounterPair
modifier|&
name|state
init|=
name|i
operator|->
name|second
decl_stmt|;
name|state
operator|.
name|second
operator|=
name|mCounter
operator|++
expr_stmt|;
return|return
name|state
operator|.
name|first
return|;
block|}
else|else
block|{
if|if
condition|(
name|mSamplerStateCache
operator|.
name|size
argument_list|()
operator|>=
name|kMaxSamplerStates
condition|)
block|{
name|TRACE
argument_list|(
literal|"Overflowed the limit of %u sampler states, removing the least recently used "
literal|"to make room."
argument_list|,
name|kMaxSamplerStates
argument_list|)
expr_stmt|;
name|SamplerStateMap
operator|::
name|iterator
name|leastRecentlyUsed
init|=
name|mSamplerStateCache
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
name|SamplerStateMap
operator|::
name|iterator
name|i
init|=
name|mSamplerStateCache
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mSamplerStateCache
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|->
name|second
operator|.
name|second
operator|<
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|second
condition|)
block|{
name|leastRecentlyUsed
operator|=
name|i
expr_stmt|;
block|}
block|}
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|first
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mSamplerStateCache
operator|.
name|erase
argument_list|(
name|leastRecentlyUsed
argument_list|)
expr_stmt|;
block|}
name|D3D11_SAMPLER_DESC
name|samplerDesc
decl_stmt|;
name|samplerDesc
operator|.
name|Filter
operator|=
name|gl_d3d11
operator|::
name|ConvertFilter
argument_list|(
name|samplerState
operator|.
name|minFilter
argument_list|,
name|samplerState
operator|.
name|magFilter
argument_list|,
name|samplerState
operator|.
name|maxAnisotropy
argument_list|)
expr_stmt|;
name|samplerDesc
operator|.
name|AddressU
operator|=
name|gl_d3d11
operator|::
name|ConvertTextureWrap
argument_list|(
name|samplerState
operator|.
name|wrapS
argument_list|)
expr_stmt|;
name|samplerDesc
operator|.
name|AddressV
operator|=
name|gl_d3d11
operator|::
name|ConvertTextureWrap
argument_list|(
name|samplerState
operator|.
name|wrapT
argument_list|)
expr_stmt|;
name|samplerDesc
operator|.
name|AddressW
operator|=
name|D3D11_TEXTURE_ADDRESS_CLAMP
expr_stmt|;
name|samplerDesc
operator|.
name|MipLODBias
operator|=
cast|static_cast
argument_list|<
name|float
argument_list|>
argument_list|(
name|samplerState
operator|.
name|lodOffset
argument_list|)
expr_stmt|;
name|samplerDesc
operator|.
name|MaxAnisotropy
operator|=
name|samplerState
operator|.
name|maxAnisotropy
expr_stmt|;
name|samplerDesc
operator|.
name|ComparisonFunc
operator|=
name|D3D11_COMPARISON_NEVER
expr_stmt|;
name|samplerDesc
operator|.
name|BorderColor
index|[
literal|0
index|]
operator|=
literal|0.0f
expr_stmt|;
name|samplerDesc
operator|.
name|BorderColor
index|[
literal|1
index|]
operator|=
literal|0.0f
expr_stmt|;
name|samplerDesc
operator|.
name|BorderColor
index|[
literal|2
index|]
operator|=
literal|0.0f
expr_stmt|;
name|samplerDesc
operator|.
name|BorderColor
index|[
literal|3
index|]
operator|=
literal|0.0f
expr_stmt|;
name|samplerDesc
operator|.
name|MinLOD
operator|=
name|gl_d3d11
operator|::
name|ConvertMinLOD
argument_list|(
name|samplerState
operator|.
name|minFilter
argument_list|,
name|samplerState
operator|.
name|lodOffset
argument_list|)
expr_stmt|;
name|samplerDesc
operator|.
name|MaxLOD
operator|=
name|gl_d3d11
operator|::
name|ConvertMaxLOD
argument_list|(
name|samplerState
operator|.
name|minFilter
argument_list|,
name|samplerState
operator|.
name|lodOffset
argument_list|)
expr_stmt|;
name|ID3D11SamplerState
modifier|*
name|dx11SamplerState
init|=
name|NULL
decl_stmt|;
name|HRESULT
name|result
init|=
name|mDevice
operator|->
name|CreateSamplerState
argument_list|(
operator|&
name|samplerDesc
argument_list|,
operator|&
name|dx11SamplerState
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
operator|||
operator|!
name|dx11SamplerState
condition|)
block|{
name|ERR
argument_list|(
literal|"Unable to create a ID3D11DepthStencilState, HRESULT: 0x%X."
argument_list|,
name|result
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|mSamplerStateCache
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|samplerState
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
name|dx11SamplerState
argument_list|,
name|mCounter
operator|++
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|dx11SamplerState
return|;
block|}
block|}
block|}
end_namespace
end_unit
