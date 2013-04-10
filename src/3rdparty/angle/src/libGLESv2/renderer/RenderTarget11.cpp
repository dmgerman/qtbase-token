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
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
comment|// RenderTarget11.cpp: Implements a DX11-specific wrapper for ID3D11View pointers
end_comment
begin_comment
comment|// retained by Renderbuffers.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/RenderTarget11.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Renderer11.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/renderer11_utils.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/main.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|getRTVSubresourceIndex
specifier|static
name|unsigned
name|int
name|getRTVSubresourceIndex
parameter_list|(
name|ID3D11Texture2D
modifier|*
name|texture
parameter_list|,
name|ID3D11RenderTargetView
modifier|*
name|view
parameter_list|)
block|{
name|D3D11_RENDER_TARGET_VIEW_DESC
name|rtvDesc
decl_stmt|;
name|view
operator|->
name|GetDesc
argument_list|(
operator|&
name|rtvDesc
argument_list|)
expr_stmt|;
name|D3D11_TEXTURE2D_DESC
name|texDesc
decl_stmt|;
name|texture
operator|->
name|GetDesc
argument_list|(
operator|&
name|texDesc
argument_list|)
expr_stmt|;
name|unsigned
name|int
name|mipSlice
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|arraySlice
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|mipLevels
init|=
name|texDesc
operator|.
name|MipLevels
decl_stmt|;
switch|switch
condition|(
name|rtvDesc
operator|.
name|ViewDimension
condition|)
block|{
case|case
name|D3D11_RTV_DIMENSION_TEXTURE1D
case|:
name|mipSlice
operator|=
name|rtvDesc
operator|.
name|Texture1D
operator|.
name|MipSlice
expr_stmt|;
name|arraySlice
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|D3D11_RTV_DIMENSION_TEXTURE1DARRAY
case|:
name|mipSlice
operator|=
name|rtvDesc
operator|.
name|Texture1DArray
operator|.
name|MipSlice
expr_stmt|;
name|arraySlice
operator|=
name|rtvDesc
operator|.
name|Texture1DArray
operator|.
name|FirstArraySlice
expr_stmt|;
break|break;
case|case
name|D3D11_RTV_DIMENSION_TEXTURE2D
case|:
name|mipSlice
operator|=
name|rtvDesc
operator|.
name|Texture2D
operator|.
name|MipSlice
expr_stmt|;
name|arraySlice
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|D3D11_RTV_DIMENSION_TEXTURE2DARRAY
case|:
name|mipSlice
operator|=
name|rtvDesc
operator|.
name|Texture2DArray
operator|.
name|MipSlice
expr_stmt|;
name|arraySlice
operator|=
name|rtvDesc
operator|.
name|Texture2DArray
operator|.
name|FirstArraySlice
expr_stmt|;
break|break;
case|case
name|D3D11_RTV_DIMENSION_TEXTURE2DMS
case|:
name|mipSlice
operator|=
literal|0
expr_stmt|;
name|arraySlice
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|D3D11_RTV_DIMENSION_TEXTURE2DMSARRAY
case|:
name|mipSlice
operator|=
literal|0
expr_stmt|;
name|arraySlice
operator|=
name|rtvDesc
operator|.
name|Texture2DMSArray
operator|.
name|FirstArraySlice
expr_stmt|;
break|break;
case|case
name|D3D11_RTV_DIMENSION_TEXTURE3D
case|:
name|mipSlice
operator|=
name|rtvDesc
operator|.
name|Texture3D
operator|.
name|MipSlice
expr_stmt|;
name|arraySlice
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|D3D11_RTV_DIMENSION_UNKNOWN
case|:
case|case
name|D3D11_RTV_DIMENSION_BUFFER
case|:
name|UNIMPLEMENTED
argument_list|()
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
break|break;
block|}
return|return
name|D3D11CalcSubresource
argument_list|(
name|mipSlice
argument_list|,
name|arraySlice
argument_list|,
name|mipLevels
argument_list|)
return|;
block|}
DECL|function|getDSVSubresourceIndex
specifier|static
name|unsigned
name|int
name|getDSVSubresourceIndex
parameter_list|(
name|ID3D11Texture2D
modifier|*
name|texture
parameter_list|,
name|ID3D11DepthStencilView
modifier|*
name|view
parameter_list|)
block|{
name|D3D11_DEPTH_STENCIL_VIEW_DESC
name|dsvDesc
decl_stmt|;
name|view
operator|->
name|GetDesc
argument_list|(
operator|&
name|dsvDesc
argument_list|)
expr_stmt|;
name|D3D11_TEXTURE2D_DESC
name|texDesc
decl_stmt|;
name|texture
operator|->
name|GetDesc
argument_list|(
operator|&
name|texDesc
argument_list|)
expr_stmt|;
name|unsigned
name|int
name|mipSlice
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|arraySlice
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|mipLevels
init|=
name|texDesc
operator|.
name|MipLevels
decl_stmt|;
switch|switch
condition|(
name|dsvDesc
operator|.
name|ViewDimension
condition|)
block|{
case|case
name|D3D11_DSV_DIMENSION_TEXTURE1D
case|:
name|mipSlice
operator|=
name|dsvDesc
operator|.
name|Texture1D
operator|.
name|MipSlice
expr_stmt|;
name|arraySlice
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|D3D11_DSV_DIMENSION_TEXTURE1DARRAY
case|:
name|mipSlice
operator|=
name|dsvDesc
operator|.
name|Texture1DArray
operator|.
name|MipSlice
expr_stmt|;
name|arraySlice
operator|=
name|dsvDesc
operator|.
name|Texture1DArray
operator|.
name|FirstArraySlice
expr_stmt|;
break|break;
case|case
name|D3D11_DSV_DIMENSION_TEXTURE2D
case|:
name|mipSlice
operator|=
name|dsvDesc
operator|.
name|Texture2D
operator|.
name|MipSlice
expr_stmt|;
name|arraySlice
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|D3D11_DSV_DIMENSION_TEXTURE2DARRAY
case|:
name|mipSlice
operator|=
name|dsvDesc
operator|.
name|Texture2DArray
operator|.
name|MipSlice
expr_stmt|;
name|arraySlice
operator|=
name|dsvDesc
operator|.
name|Texture2DArray
operator|.
name|FirstArraySlice
expr_stmt|;
break|break;
case|case
name|D3D11_DSV_DIMENSION_TEXTURE2DMS
case|:
name|mipSlice
operator|=
literal|0
expr_stmt|;
name|arraySlice
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|D3D11_DSV_DIMENSION_TEXTURE2DMSARRAY
case|:
name|mipSlice
operator|=
literal|0
expr_stmt|;
name|arraySlice
operator|=
name|dsvDesc
operator|.
name|Texture2DMSArray
operator|.
name|FirstArraySlice
expr_stmt|;
break|break;
case|case
name|D3D11_RTV_DIMENSION_UNKNOWN
case|:
name|UNIMPLEMENTED
argument_list|()
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
break|break;
block|}
return|return
name|D3D11CalcSubresource
argument_list|(
name|mipSlice
argument_list|,
name|arraySlice
argument_list|,
name|mipLevels
argument_list|)
return|;
block|}
DECL|function|RenderTarget11
name|RenderTarget11
operator|::
name|RenderTarget11
parameter_list|(
name|Renderer
modifier|*
name|renderer
parameter_list|,
name|ID3D11RenderTargetView
modifier|*
name|rtv
parameter_list|,
name|ID3D11Texture2D
modifier|*
name|tex
parameter_list|,
name|ID3D11ShaderResourceView
modifier|*
name|srv
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
block|{
name|mRenderer
operator|=
name|Renderer11
operator|::
name|makeRenderer11
argument_list|(
name|renderer
argument_list|)
expr_stmt|;
name|mTexture
operator|=
name|tex
expr_stmt|;
name|mRenderTarget
operator|=
name|rtv
expr_stmt|;
name|mDepthStencil
operator|=
name|NULL
expr_stmt|;
name|mShaderResource
operator|=
name|srv
expr_stmt|;
name|mSubresourceIndex
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|mRenderTarget
operator|&&
name|mTexture
condition|)
block|{
name|D3D11_RENDER_TARGET_VIEW_DESC
name|desc
decl_stmt|;
name|mRenderTarget
operator|->
name|GetDesc
argument_list|(
operator|&
name|desc
argument_list|)
expr_stmt|;
name|D3D11_TEXTURE2D_DESC
name|texDesc
decl_stmt|;
name|mTexture
operator|->
name|GetDesc
argument_list|(
operator|&
name|texDesc
argument_list|)
expr_stmt|;
name|mSubresourceIndex
operator|=
name|getRTVSubresourceIndex
argument_list|(
name|mTexture
argument_list|,
name|mRenderTarget
argument_list|)
expr_stmt|;
name|mWidth
operator|=
name|width
expr_stmt|;
name|mHeight
operator|=
name|height
expr_stmt|;
name|mSamples
operator|=
operator|(
name|texDesc
operator|.
name|SampleDesc
operator|.
name|Count
operator|>
literal|1
operator|)
condition|?
name|texDesc
operator|.
name|SampleDesc
operator|.
name|Count
else|:
literal|0
expr_stmt|;
name|mInternalFormat
operator|=
name|d3d11_gl
operator|::
name|ConvertTextureInternalFormat
argument_list|(
name|desc
operator|.
name|Format
argument_list|)
expr_stmt|;
name|mActualFormat
operator|=
name|d3d11_gl
operator|::
name|ConvertTextureInternalFormat
argument_list|(
name|desc
operator|.
name|Format
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|RenderTarget11
name|RenderTarget11
operator|::
name|RenderTarget11
parameter_list|(
name|Renderer
modifier|*
name|renderer
parameter_list|,
name|ID3D11DepthStencilView
modifier|*
name|dsv
parameter_list|,
name|ID3D11Texture2D
modifier|*
name|tex
parameter_list|,
name|ID3D11ShaderResourceView
modifier|*
name|srv
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
block|{
name|mRenderer
operator|=
name|Renderer11
operator|::
name|makeRenderer11
argument_list|(
name|renderer
argument_list|)
expr_stmt|;
name|mTexture
operator|=
name|tex
expr_stmt|;
name|mRenderTarget
operator|=
name|NULL
expr_stmt|;
name|mDepthStencil
operator|=
name|dsv
expr_stmt|;
name|mShaderResource
operator|=
name|srv
expr_stmt|;
name|mSubresourceIndex
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|mDepthStencil
operator|&&
name|mTexture
condition|)
block|{
name|D3D11_DEPTH_STENCIL_VIEW_DESC
name|desc
decl_stmt|;
name|mDepthStencil
operator|->
name|GetDesc
argument_list|(
operator|&
name|desc
argument_list|)
expr_stmt|;
name|D3D11_TEXTURE2D_DESC
name|texDesc
decl_stmt|;
name|mTexture
operator|->
name|GetDesc
argument_list|(
operator|&
name|texDesc
argument_list|)
expr_stmt|;
name|mSubresourceIndex
operator|=
name|getDSVSubresourceIndex
argument_list|(
name|mTexture
argument_list|,
name|mDepthStencil
argument_list|)
expr_stmt|;
name|mWidth
operator|=
name|width
expr_stmt|;
name|mHeight
operator|=
name|height
expr_stmt|;
name|mSamples
operator|=
operator|(
name|texDesc
operator|.
name|SampleDesc
operator|.
name|Count
operator|>
literal|1
operator|)
condition|?
name|texDesc
operator|.
name|SampleDesc
operator|.
name|Count
else|:
literal|0
expr_stmt|;
name|mInternalFormat
operator|=
name|d3d11_gl
operator|::
name|ConvertTextureInternalFormat
argument_list|(
name|desc
operator|.
name|Format
argument_list|)
expr_stmt|;
name|mActualFormat
operator|=
name|d3d11_gl
operator|::
name|ConvertTextureInternalFormat
argument_list|(
name|desc
operator|.
name|Format
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|RenderTarget11
name|RenderTarget11
operator|::
name|RenderTarget11
parameter_list|(
name|Renderer
modifier|*
name|renderer
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLsizei
name|samples
parameter_list|,
name|bool
name|depth
parameter_list|)
block|{
name|mRenderer
operator|=
name|Renderer11
operator|::
name|makeRenderer11
argument_list|(
name|renderer
argument_list|)
expr_stmt|;
name|mTexture
operator|=
name|NULL
expr_stmt|;
name|mRenderTarget
operator|=
name|NULL
expr_stmt|;
name|mDepthStencil
operator|=
name|NULL
expr_stmt|;
name|mShaderResource
operator|=
name|NULL
expr_stmt|;
name|DXGI_FORMAT
name|requestedFormat
init|=
name|gl_d3d11
operator|::
name|ConvertRenderbufferFormat
argument_list|(
name|format
argument_list|)
decl_stmt|;
name|int
name|supportedSamples
init|=
name|mRenderer
operator|->
name|getNearestSupportedSamples
argument_list|(
name|requestedFormat
argument_list|,
name|samples
argument_list|)
decl_stmt|;
if|if
condition|(
name|supportedSamples
operator|<
literal|0
condition|)
block|{
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|width
operator|>
literal|0
operator|&&
name|height
operator|>
literal|0
condition|)
block|{
comment|// Create texture resource
name|D3D11_TEXTURE2D_DESC
name|desc
decl_stmt|;
name|desc
operator|.
name|Width
operator|=
name|width
expr_stmt|;
name|desc
operator|.
name|Height
operator|=
name|height
expr_stmt|;
name|desc
operator|.
name|MipLevels
operator|=
literal|1
expr_stmt|;
name|desc
operator|.
name|ArraySize
operator|=
literal|1
expr_stmt|;
name|desc
operator|.
name|Format
operator|=
name|requestedFormat
expr_stmt|;
name|desc
operator|.
name|SampleDesc
operator|.
name|Count
operator|=
operator|(
name|supportedSamples
operator|==
literal|0
operator|)
condition|?
literal|1
else|:
name|supportedSamples
expr_stmt|;
name|desc
operator|.
name|SampleDesc
operator|.
name|Quality
operator|=
literal|0
expr_stmt|;
name|desc
operator|.
name|Usage
operator|=
name|D3D11_USAGE_DEFAULT
expr_stmt|;
name|desc
operator|.
name|CPUAccessFlags
operator|=
literal|0
expr_stmt|;
name|desc
operator|.
name|MiscFlags
operator|=
literal|0
expr_stmt|;
name|desc
operator|.
name|BindFlags
operator|=
operator|(
name|depth
condition|?
name|D3D11_BIND_DEPTH_STENCIL
else|:
operator|(
name|D3D11_BIND_RENDER_TARGET
operator||
name|D3D11_BIND_SHADER_RESOURCE
operator|)
operator|)
expr_stmt|;
name|ID3D11Device
modifier|*
name|device
init|=
name|mRenderer
operator|->
name|getDevice
argument_list|()
decl_stmt|;
name|HRESULT
name|result
init|=
name|device
operator|->
name|CreateTexture2D
argument_list|(
operator|&
name|desc
argument_list|,
name|NULL
argument_list|,
operator|&
name|mTexture
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|==
name|E_OUTOFMEMORY
condition|)
block|{
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|)
expr_stmt|;
return|return;
block|}
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|depth
condition|)
block|{
name|D3D11_DEPTH_STENCIL_VIEW_DESC
name|dsvDesc
decl_stmt|;
name|dsvDesc
operator|.
name|Format
operator|=
name|requestedFormat
expr_stmt|;
name|dsvDesc
operator|.
name|ViewDimension
operator|=
operator|(
name|supportedSamples
operator|==
literal|0
operator|)
condition|?
name|D3D11_DSV_DIMENSION_TEXTURE2D
else|:
name|D3D11_DSV_DIMENSION_TEXTURE2DMS
expr_stmt|;
name|dsvDesc
operator|.
name|Texture2D
operator|.
name|MipSlice
operator|=
literal|0
expr_stmt|;
name|dsvDesc
operator|.
name|Flags
operator|=
literal|0
expr_stmt|;
name|result
operator|=
name|device
operator|->
name|CreateDepthStencilView
argument_list|(
name|mTexture
argument_list|,
operator|&
name|dsvDesc
argument_list|,
operator|&
name|mDepthStencil
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|E_OUTOFMEMORY
condition|)
block|{
name|mTexture
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mTexture
operator|=
name|NULL
expr_stmt|;
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|)
expr_stmt|;
block|}
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|D3D11_RENDER_TARGET_VIEW_DESC
name|rtvDesc
decl_stmt|;
name|rtvDesc
operator|.
name|Format
operator|=
name|requestedFormat
expr_stmt|;
name|rtvDesc
operator|.
name|ViewDimension
operator|=
operator|(
name|supportedSamples
operator|==
literal|0
operator|)
condition|?
name|D3D11_RTV_DIMENSION_TEXTURE2D
else|:
name|D3D11_RTV_DIMENSION_TEXTURE2DMS
expr_stmt|;
name|rtvDesc
operator|.
name|Texture2D
operator|.
name|MipSlice
operator|=
literal|0
expr_stmt|;
name|result
operator|=
name|device
operator|->
name|CreateRenderTargetView
argument_list|(
name|mTexture
argument_list|,
operator|&
name|rtvDesc
argument_list|,
operator|&
name|mRenderTarget
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|E_OUTOFMEMORY
condition|)
block|{
name|mTexture
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mTexture
operator|=
name|NULL
expr_stmt|;
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|)
expr_stmt|;
return|return;
block|}
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
name|D3D11_SHADER_RESOURCE_VIEW_DESC
name|srvDesc
decl_stmt|;
name|srvDesc
operator|.
name|Format
operator|=
name|requestedFormat
expr_stmt|;
name|srvDesc
operator|.
name|ViewDimension
operator|=
operator|(
name|supportedSamples
operator|==
literal|0
operator|)
condition|?
name|D3D11_SRV_DIMENSION_TEXTURE2D
else|:
name|D3D11_SRV_DIMENSION_TEXTURE2DMS
expr_stmt|;
name|srvDesc
operator|.
name|Texture2D
operator|.
name|MostDetailedMip
operator|=
literal|0
expr_stmt|;
name|srvDesc
operator|.
name|Texture2D
operator|.
name|MipLevels
operator|=
literal|1
expr_stmt|;
name|result
operator|=
name|device
operator|->
name|CreateShaderResourceView
argument_list|(
name|mTexture
argument_list|,
operator|&
name|srvDesc
argument_list|,
operator|&
name|mShaderResource
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|E_OUTOFMEMORY
condition|)
block|{
name|mTexture
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mTexture
operator|=
name|NULL
expr_stmt|;
name|mRenderTarget
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mRenderTarget
operator|=
name|NULL
expr_stmt|;
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|)
expr_stmt|;
return|return;
block|}
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|mWidth
operator|=
name|width
expr_stmt|;
name|mHeight
operator|=
name|height
expr_stmt|;
name|mInternalFormat
operator|=
name|format
expr_stmt|;
name|mSamples
operator|=
name|supportedSamples
expr_stmt|;
name|mActualFormat
operator|=
name|d3d11_gl
operator|::
name|ConvertTextureInternalFormat
argument_list|(
name|requestedFormat
argument_list|)
expr_stmt|;
name|mSubresourceIndex
operator|=
name|D3D11CalcSubresource
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
DECL|function|~RenderTarget11
name|RenderTarget11
operator|::
name|~
name|RenderTarget11
parameter_list|()
block|{
if|if
condition|(
name|mTexture
condition|)
block|{
name|mTexture
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mTexture
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|mRenderTarget
condition|)
block|{
name|mRenderTarget
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mRenderTarget
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|mDepthStencil
condition|)
block|{
name|mDepthStencil
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mDepthStencil
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|mShaderResource
condition|)
block|{
name|mShaderResource
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mShaderResource
operator|=
name|NULL
expr_stmt|;
block|}
block|}
DECL|function|makeRenderTarget11
name|RenderTarget11
modifier|*
name|RenderTarget11
operator|::
name|makeRenderTarget11
parameter_list|(
name|RenderTarget
modifier|*
name|target
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|HAS_DYNAMIC_TYPE
argument_list|(
name|rx
operator|::
name|RenderTarget11
operator|*
argument_list|,
name|target
argument_list|)
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|rx
operator|::
name|RenderTarget11
operator|*
argument_list|>
argument_list|(
name|target
argument_list|)
return|;
block|}
DECL|function|getTexture
name|ID3D11Texture2D
modifier|*
name|RenderTarget11
operator|::
name|getTexture
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|mTexture
condition|)
block|{
name|mTexture
operator|->
name|AddRef
argument_list|()
expr_stmt|;
block|}
return|return
name|mTexture
return|;
block|}
comment|// Adds reference, caller must call Release
DECL|function|getRenderTargetView
name|ID3D11RenderTargetView
modifier|*
name|RenderTarget11
operator|::
name|getRenderTargetView
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|mRenderTarget
condition|)
block|{
name|mRenderTarget
operator|->
name|AddRef
argument_list|()
expr_stmt|;
block|}
return|return
name|mRenderTarget
return|;
block|}
comment|// Adds reference, caller must call Release
DECL|function|getDepthStencilView
name|ID3D11DepthStencilView
modifier|*
name|RenderTarget11
operator|::
name|getDepthStencilView
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|mDepthStencil
condition|)
block|{
name|mDepthStencil
operator|->
name|AddRef
argument_list|()
expr_stmt|;
block|}
return|return
name|mDepthStencil
return|;
block|}
comment|// Adds reference, caller must call Release
DECL|function|getShaderResourceView
name|ID3D11ShaderResourceView
modifier|*
name|RenderTarget11
operator|::
name|getShaderResourceView
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|mShaderResource
condition|)
block|{
name|mShaderResource
operator|->
name|AddRef
argument_list|()
expr_stmt|;
block|}
return|return
name|mShaderResource
return|;
block|}
DECL|function|getSubresourceIndex
name|unsigned
name|int
name|RenderTarget11
operator|::
name|getSubresourceIndex
parameter_list|()
specifier|const
block|{
return|return
name|mSubresourceIndex
return|;
block|}
block|}
end_namespace
end_unit
