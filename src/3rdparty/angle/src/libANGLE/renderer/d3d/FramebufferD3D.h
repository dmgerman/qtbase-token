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
comment|// FramebufferD3D.h: Defines the DefaultAttachmentD3D and FramebufferD3D classes.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_FRAMBUFFERD3D_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_FRAMBUFFERD3D_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_FRAMBUFFERD3D_H_
end_define
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|<cstdint>
end_include
begin_include
include|#
directive|include
file|"libANGLE/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/FramebufferImpl.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|FramebufferAttachment
decl_stmt|;
struct_decl|struct
name|PixelPackState
struct_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RenderTargetD3D
decl_stmt|;
name|class
name|RendererD3D
decl_stmt|;
struct|struct
name|ClearParameters
block|{
name|bool
name|clearColor
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_DRAW_BUFFERS
index|]
decl_stmt|;
name|gl
operator|::
name|ColorF
name|colorFClearValue
expr_stmt|;
name|gl
operator|::
name|ColorI
name|colorIClearValue
expr_stmt|;
name|gl
operator|::
name|ColorUI
name|colorUIClearValue
expr_stmt|;
name|GLenum
name|colorClearType
decl_stmt|;
name|bool
name|colorMaskRed
decl_stmt|;
name|bool
name|colorMaskGreen
decl_stmt|;
name|bool
name|colorMaskBlue
decl_stmt|;
name|bool
name|colorMaskAlpha
decl_stmt|;
name|bool
name|clearDepth
decl_stmt|;
name|float
name|depthClearValue
decl_stmt|;
name|bool
name|clearStencil
decl_stmt|;
name|GLint
name|stencilClearValue
decl_stmt|;
name|GLuint
name|stencilWriteMask
decl_stmt|;
name|bool
name|scissorEnabled
decl_stmt|;
name|gl
operator|::
name|Rectangle
name|scissor
expr_stmt|;
block|}
struct|;
name|class
name|FramebufferD3D
range|:
name|public
name|FramebufferImpl
block|{
name|public
operator|:
name|FramebufferD3D
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
name|RendererD3D
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|FramebufferD3D
argument_list|()
block|;
name|void
name|setColorAttachment
argument_list|(
argument|size_t index
argument_list|,
argument|const gl::FramebufferAttachment *attachment
argument_list|)
name|override
block|;
name|void
name|setDepthAttachment
argument_list|(
argument|const gl::FramebufferAttachment *attachment
argument_list|)
name|override
block|;
name|void
name|setStencilAttachment
argument_list|(
argument|const gl::FramebufferAttachment *attachment
argument_list|)
name|override
block|;
name|void
name|setDepthStencilAttachment
argument_list|(
argument|const gl::FramebufferAttachment *attachment
argument_list|)
name|override
block|;
name|void
name|setDrawBuffers
argument_list|(
argument|size_t count
argument_list|,
argument|const GLenum *buffers
argument_list|)
name|override
block|;
name|void
name|setReadBuffer
argument_list|(
argument|GLenum buffer
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|invalidate
argument_list|(
argument|size_t count
argument_list|,
argument|const GLenum *attachments
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|invalidateSub
argument_list|(
argument|size_t count
argument_list|,
argument|const GLenum *attachments
argument_list|,
argument|const gl::Rectangle&area
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|clear
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLbitfield mask
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|clearBufferfv
argument_list|(
argument|const gl::State&state
argument_list|,
argument|GLenum buffer
argument_list|,
argument|GLint drawbuffer
argument_list|,
argument|const GLfloat *values
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|clearBufferuiv
argument_list|(
argument|const gl::State&state
argument_list|,
argument|GLenum buffer
argument_list|,
argument|GLint drawbuffer
argument_list|,
argument|const GLuint *values
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|clearBufferiv
argument_list|(
argument|const gl::State&state
argument_list|,
argument|GLenum buffer
argument_list|,
argument|GLint drawbuffer
argument_list|,
argument|const GLint *values
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|clearBufferfi
argument_list|(
argument|const gl::State&state
argument_list|,
argument|GLenum buffer
argument_list|,
argument|GLint drawbuffer
argument_list|,
argument|GLfloat depth
argument_list|,
argument|GLint stencil
argument_list|)
name|override
block|;
name|GLenum
name|getImplementationColorReadFormat
argument_list|()
specifier|const
name|override
block|;
name|GLenum
name|getImplementationColorReadType
argument_list|()
specifier|const
name|override
block|;
name|gl
operator|::
name|Error
name|readPixels
argument_list|(
argument|const gl::State&state
argument_list|,
argument|const gl::Rectangle&area
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLvoid *pixels
argument_list|)
specifier|const
name|override
block|;
name|gl
operator|::
name|Error
name|blit
argument_list|(
argument|const gl::State&state
argument_list|,
argument|const gl::Rectangle&sourceArea
argument_list|,
argument|const gl::Rectangle&destArea
argument_list|,
argument|GLbitfield mask
argument_list|,
argument|GLenum filter
argument_list|,
argument|const gl::Framebuffer *sourceFramebuffer
argument_list|)
name|override
block|;
name|GLenum
name|checkStatus
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|gl
operator|::
name|AttachmentList
operator|&
name|getColorAttachmentsForRender
argument_list|(
argument|const Workarounds&workarounds
argument_list|)
specifier|const
block|;
name|protected
operator|:
comment|// Cache variable
name|mutable
name|gl
operator|::
name|AttachmentList
name|mColorAttachmentsForRender
block|;
name|mutable
name|bool
name|mInvalidateColorAttachmentCache
block|;
name|private
operator|:
name|RendererD3D
operator|*
specifier|const
name|mRenderer
block|;
name|virtual
name|gl
operator|::
name|Error
name|clear
argument_list|(
specifier|const
name|gl
operator|::
name|State
operator|&
name|state
argument_list|,
specifier|const
name|ClearParameters
operator|&
name|clearParams
argument_list|)
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
name|GLenum
name|getRenderTargetImplementationFormat
argument_list|(
argument|RenderTargetD3D *renderTarget
argument_list|)
specifier|const
operator|=
literal|0
block|; }
decl_stmt|;
name|gl
operator|::
name|Error
name|GetAttachmentRenderTarget
argument_list|(
specifier|const
name|gl
operator|::
name|FramebufferAttachment
operator|*
name|attachment
argument_list|,
name|RenderTargetD3D
operator|*
operator|*
name|outRT
argument_list|)
expr_stmt|;
name|unsigned
name|int
name|GetAttachmentSerial
argument_list|(
specifier|const
name|gl
operator|::
name|FramebufferAttachment
operator|*
name|attachment
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_FRAMBUFFERD3D_H_
end_comment
end_unit
