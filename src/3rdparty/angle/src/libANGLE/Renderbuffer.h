begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
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
comment|// Renderbuffer.h: Defines the renderer-agnostic container class gl::Renderbuffer.
end_comment
begin_comment
comment|// Implements GL renderbuffer objects and related functionality.
end_comment
begin_comment
comment|// [OpenGL ES 2.0.24] section 4.4.3 page 108.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERBUFFER_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERBUFFER_H_
define|#
directive|define
name|LIBANGLE_RENDERBUFFER_H_
end_define
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/RefCountObject.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RenderbufferImpl
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|FramebufferAttachment
decl_stmt|;
comment|// A GL renderbuffer object is usually used as a depth or stencil buffer attachment
comment|// for a framebuffer object. The renderbuffer itself is a distinct GL object, see
comment|// FramebufferAttachment and Framebuffer for how they are applied to an FBO via an
comment|// attachment point.
name|class
name|Renderbuffer
range|:
name|public
name|RefCountObject
block|{
name|public
operator|:
name|Renderbuffer
argument_list|(
argument|rx::RenderbufferImpl *impl
argument_list|,
argument|GLuint id
argument_list|)
block|;
name|virtual
operator|~
name|Renderbuffer
argument_list|()
block|;
name|Error
name|setStorage
argument_list|(
argument|GLenum internalformat
argument_list|,
argument|size_t width
argument_list|,
argument|size_t height
argument_list|)
block|;
name|Error
name|setStorageMultisample
argument_list|(
argument|size_t samples
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|size_t width
argument_list|,
argument|size_t height
argument_list|)
block|;
name|rx
operator|::
name|RenderbufferImpl
operator|*
name|getImplementation
argument_list|()
block|;
specifier|const
name|rx
operator|::
name|RenderbufferImpl
operator|*
name|getImplementation
argument_list|()
specifier|const
block|;
name|GLsizei
name|getWidth
argument_list|()
specifier|const
block|;
name|GLsizei
name|getHeight
argument_list|()
specifier|const
block|;
name|GLenum
name|getInternalFormat
argument_list|()
specifier|const
block|;
name|GLsizei
name|getSamples
argument_list|()
specifier|const
block|;
name|GLuint
name|getRedSize
argument_list|()
specifier|const
block|;
name|GLuint
name|getGreenSize
argument_list|()
specifier|const
block|;
name|GLuint
name|getBlueSize
argument_list|()
specifier|const
block|;
name|GLuint
name|getAlphaSize
argument_list|()
specifier|const
block|;
name|GLuint
name|getDepthSize
argument_list|()
specifier|const
block|;
name|GLuint
name|getStencilSize
argument_list|()
specifier|const
block|;
name|private
operator|:
name|rx
operator|::
name|RenderbufferImpl
operator|*
name|mRenderbuffer
block|;
name|GLsizei
name|mWidth
block|;
name|GLsizei
name|mHeight
block|;
name|GLenum
name|mInternalFormat
block|;
name|GLsizei
name|mSamples
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERBUFFER_H_
end_comment
end_unit
