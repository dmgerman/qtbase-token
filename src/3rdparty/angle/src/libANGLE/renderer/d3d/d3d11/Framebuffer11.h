begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// Framebuffer11.h: Defines the Framebuffer11 class.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D11_FRAMBUFFER11_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D11_FRAMBUFFER11_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D11_FRAMBUFFER11_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/FramebufferD3D.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer11
decl_stmt|;
name|class
name|Framebuffer11
range|:
name|public
name|FramebufferD3D
block|{
name|public
operator|:
name|Framebuffer11
argument_list|(
specifier|const
name|gl
operator|::
name|Framebuffer
operator|::
name|Data
operator|&
name|data
argument_list|,
name|Renderer11
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|Framebuffer11
argument_list|()
block|;
comment|// Invalidate the cached swizzles of all bound texture attachments.
name|gl
operator|::
name|Error
name|invalidateSwizzles
argument_list|()
specifier|const
block|;
name|private
operator|:
name|gl
operator|::
name|Error
name|clear
argument_list|(
argument|const gl::State&state
argument_list|,
argument|const ClearParameters&clearParams
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|readPixels
argument_list|(
argument|const gl::Rectangle&area
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|size_t outputPitch
argument_list|,
argument|const gl::PixelPackState&pack
argument_list|,
argument|uint8_t *pixels
argument_list|)
specifier|const
name|override
block|;
name|gl
operator|::
name|Error
name|blit
argument_list|(
argument|const gl::Rectangle&sourceArea
argument_list|,
argument|const gl::Rectangle&destArea
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
argument_list|,
argument|const gl::Framebuffer *sourceFramebuffer
argument_list|)
name|override
block|;
name|GLenum
name|getRenderTargetImplementationFormat
argument_list|(
argument|RenderTargetD3D *renderTarget
argument_list|)
specifier|const
name|override
block|;
name|Renderer11
operator|*
specifier|const
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
comment|// LIBANGLE_RENDERER_D3D_D3D11_FRAMBUFFER11_H_
end_comment
end_unit
