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
comment|// RenderTarget9.h: Defines a D3D9-specific wrapper for IDirect3DSurface9 pointers
end_comment
begin_comment
comment|// retained by Renderbuffers.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D9_RENDERTARGET9_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D9_RENDERTARGET9_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D9_RENDERTARGET9_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/RenderTargetD3D.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer9
decl_stmt|;
name|class
name|SwapChain9
decl_stmt|;
name|class
name|RenderTarget9
range|:
name|public
name|RenderTargetD3D
block|{
name|public
operator|:
name|RenderTarget9
argument_list|()
block|{ }
name|virtual
operator|~
name|RenderTarget9
argument_list|()
block|{ }
comment|// Retrieve the texture that backs this render target, may be null for swap chain render
comment|// targets.
name|virtual
name|IDirect3DBaseTexture9
operator|*
name|getTexture
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|size_t
name|getTextureLevel
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|IDirect3DSurface9
operator|*
name|getSurface
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|D3DFORMAT
name|getD3DFormat
argument_list|()
specifier|const
operator|=
literal|0
block|; }
decl_stmt|;
name|class
name|TextureRenderTarget9
range|:
name|public
name|RenderTarget9
block|{
name|public
operator|:
name|TextureRenderTarget9
argument_list|(
argument|IDirect3DBaseTexture9 *texture
argument_list|,
argument|size_t textureLevel
argument_list|,
argument|IDirect3DSurface9 *surface
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLsizei samples
argument_list|)
block|;
name|virtual
operator|~
name|TextureRenderTarget9
argument_list|()
block|;
name|GLsizei
name|getWidth
argument_list|()
specifier|const
name|override
block|;
name|GLsizei
name|getHeight
argument_list|()
specifier|const
name|override
block|;
name|GLsizei
name|getDepth
argument_list|()
specifier|const
name|override
block|;
name|GLenum
name|getInternalFormat
argument_list|()
specifier|const
name|override
block|;
name|GLsizei
name|getSamples
argument_list|()
specifier|const
name|override
block|;
name|IDirect3DBaseTexture9
operator|*
name|getTexture
argument_list|()
specifier|const
name|override
block|;
name|size_t
name|getTextureLevel
argument_list|()
specifier|const
name|override
block|;
name|IDirect3DSurface9
operator|*
name|getSurface
argument_list|()
specifier|const
name|override
block|;
name|D3DFORMAT
name|getD3DFormat
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|GLsizei
name|mWidth
block|;
name|GLsizei
name|mHeight
block|;
name|GLsizei
name|mDepth
block|;
name|GLenum
name|mInternalFormat
block|;
name|D3DFORMAT
name|mD3DFormat
block|;
name|GLsizei
name|mSamples
block|;
name|IDirect3DBaseTexture9
operator|*
name|mTexture
block|;
name|size_t
name|mTextureLevel
block|;
name|IDirect3DSurface9
operator|*
name|mRenderTarget
block|; }
decl_stmt|;
name|class
name|SurfaceRenderTarget9
range|:
name|public
name|RenderTarget9
block|{
name|public
operator|:
name|SurfaceRenderTarget9
argument_list|(
argument|SwapChain9 *swapChain
argument_list|,
argument|bool depth
argument_list|)
block|;
name|virtual
operator|~
name|SurfaceRenderTarget9
argument_list|()
block|;
name|GLsizei
name|getWidth
argument_list|()
specifier|const
name|override
block|;
name|GLsizei
name|getHeight
argument_list|()
specifier|const
name|override
block|;
name|GLsizei
name|getDepth
argument_list|()
specifier|const
name|override
block|;
name|GLenum
name|getInternalFormat
argument_list|()
specifier|const
name|override
block|;
name|GLsizei
name|getSamples
argument_list|()
specifier|const
name|override
block|;
name|IDirect3DBaseTexture9
operator|*
name|getTexture
argument_list|()
specifier|const
name|override
block|;
name|size_t
name|getTextureLevel
argument_list|()
specifier|const
name|override
block|;
name|IDirect3DSurface9
operator|*
name|getSurface
argument_list|()
specifier|const
name|override
block|;
name|D3DFORMAT
name|getD3DFormat
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|SwapChain9
operator|*
name|mSwapChain
block|;
name|bool
name|mDepth
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D9_RENDERTARGET9_H_
end_comment
end_unit
