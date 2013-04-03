begin_unit
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
comment|// RenderTarget11.h: Defines a DX11-specific wrapper for ID3D11View pointers
end_comment
begin_comment
comment|// retained by Renderbuffers.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_RENDERTARGET11_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_RENDERTARGET11_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_RENDERTARGET11_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/RenderTarget.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer
decl_stmt|;
name|class
name|Renderer11
decl_stmt|;
name|class
name|RenderTarget11
range|:
name|public
name|RenderTarget
block|{
name|public
operator|:
name|RenderTarget11
argument_list|(
argument|Renderer *renderer
argument_list|,
argument|ID3D11RenderTargetView *rtv
argument_list|,
argument|ID3D11Texture2D *tex
argument_list|,
argument|ID3D11ShaderResourceView *srv
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|RenderTarget11
argument_list|(
argument|Renderer *renderer
argument_list|,
argument|ID3D11DepthStencilView *dsv
argument_list|,
argument|ID3D11Texture2D *tex
argument_list|,
argument|ID3D11ShaderResourceView *srv
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|RenderTarget11
argument_list|(
argument|Renderer *renderer
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei samples
argument_list|,
argument|bool depth
argument_list|)
block|;
name|virtual
operator|~
name|RenderTarget11
argument_list|()
block|;
specifier|static
name|RenderTarget11
operator|*
name|makeRenderTarget11
argument_list|(
name|RenderTarget
operator|*
name|renderTarget
argument_list|)
block|;
comment|// Adds reference, caller must call Release
name|ID3D11Texture2D
operator|*
name|getTexture
argument_list|()
specifier|const
block|;
comment|// Adds reference, caller must call Release
name|ID3D11RenderTargetView
operator|*
name|getRenderTargetView
argument_list|()
specifier|const
block|;
comment|// Adds reference, caller must call Release
name|ID3D11DepthStencilView
operator|*
name|getDepthStencilView
argument_list|()
specifier|const
block|;
comment|// Adds reference, caller must call Release
name|ID3D11ShaderResourceView
operator|*
name|getShaderResourceView
argument_list|()
specifier|const
block|;
name|unsigned
name|int
name|getSubresourceIndex
argument_list|()
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RenderTarget11
argument_list|)
block|;
name|unsigned
name|int
name|mSubresourceIndex
block|;
name|ID3D11Texture2D
operator|*
name|mTexture
block|;
name|ID3D11RenderTargetView
operator|*
name|mRenderTarget
block|;
name|ID3D11DepthStencilView
operator|*
name|mDepthStencil
block|;
name|ID3D11ShaderResourceView
operator|*
name|mShaderResource
block|;
name|Renderer11
operator|*
name|mRenderer
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
endif|LIBGLESV2_RENDERER_RENDERTARGET11_H_
end_endif
end_unit
