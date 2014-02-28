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
name|LIBGLESV2_RENDERER_RENDERTARGET9_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_RENDERTARGET9_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_RENDERTARGET9_H_
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
name|Renderer9
decl_stmt|;
name|class
name|RenderTarget9
range|:
name|public
name|RenderTarget
block|{
name|public
operator|:
name|RenderTarget9
argument_list|(
name|Renderer
operator|*
name|renderer
argument_list|,
name|IDirect3DSurface9
operator|*
name|surface
argument_list|)
block|;
name|RenderTarget9
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
argument_list|)
block|;
name|virtual
operator|~
name|RenderTarget9
argument_list|()
block|;
specifier|static
name|RenderTarget9
operator|*
name|makeRenderTarget9
argument_list|(
name|RenderTarget
operator|*
name|renderTarget
argument_list|)
block|;
name|IDirect3DSurface9
operator|*
name|getSurface
argument_list|()
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RenderTarget9
argument_list|)
block|;
name|IDirect3DSurface9
operator|*
name|mRenderTarget
block|;
name|Renderer9
operator|*
name|mRenderer
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_RENDERTARGET9_H_
end_comment
end_unit
