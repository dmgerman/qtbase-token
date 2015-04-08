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
comment|// FramebufferImpl.h: Defines the abstract rx::FramebufferImpl class.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_FRAMEBUFFERIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_FRAMEBUFFERIMPL_H_
define|#
directive|define
name|LIBANGLE_RENDERER_FRAMEBUFFERIMPL_H_
end_define
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Framebuffer.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|State
decl_stmt|;
name|class
name|Framebuffer
decl_stmt|;
name|class
name|FramebufferAttachment
decl_stmt|;
struct_decl|struct
name|Rectangle
struct_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|FramebufferImpl
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|explicit
name|FramebufferImpl
argument_list|(
specifier|const
name|gl
operator|::
name|Framebuffer
operator|::
name|Data
operator|&
name|data
argument_list|)
operator|:
name|mData
argument_list|(
argument|data
argument_list|)
block|{ }
name|virtual
operator|~
name|FramebufferImpl
argument_list|()
block|{ }
name|virtual
name|void
name|setColorAttachment
argument_list|(
argument|size_t index
argument_list|,
argument|const gl::FramebufferAttachment *attachment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setDepthAttachment
argument_list|(
specifier|const
name|gl
operator|::
name|FramebufferAttachment
operator|*
name|attachment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setStencilAttachment
argument_list|(
specifier|const
name|gl
operator|::
name|FramebufferAttachment
operator|*
name|attachment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setDepthStencilAttachment
argument_list|(
specifier|const
name|gl
operator|::
name|FramebufferAttachment
operator|*
name|attachment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setDrawBuffers
argument_list|(
argument|size_t count
argument_list|,
argument|const GLenum *buffers
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setReadBuffer
argument_list|(
argument|GLenum buffer
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|invalidate
argument_list|(
argument|size_t count
argument_list|,
argument|const GLenum *attachments
argument_list|)
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|clear
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLbitfield mask
argument_list|)
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
name|GLenum
name|getImplementationColorReadFormat
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|GLenum
name|getImplementationColorReadType
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
name|GLenum
name|checkStatus
argument_list|()
specifier|const
operator|=
literal|0
block|;
specifier|const
name|gl
operator|::
name|Framebuffer
operator|::
name|Data
operator|&
name|getData
argument_list|()
specifier|const
block|{
return|return
name|mData
return|;
block|}
name|protected
operator|:
specifier|const
name|gl
operator|::
name|Framebuffer
operator|::
name|Data
operator|&
name|mData
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_FRAMEBUFFERIMPL_H_
end_comment
end_unit
