begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// RenderbufferImpl.h: Defines the abstract class gl::RenderbufferImpl
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_RENDERBUFFERIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_RENDERBUFFERIMPL_H_
define|#
directive|define
name|LIBANGLE_RENDERER_RENDERBUFFERIMPL_H_
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
file|"common/angleutils.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RenderbufferImpl
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|RenderbufferImpl
argument_list|()
block|;
name|virtual
operator|~
name|RenderbufferImpl
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|setStorage
argument_list|(
argument|GLenum internalformat
argument_list|,
argument|size_t width
argument_list|,
argument|size_t height
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
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
operator|=
literal|0
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_RENDERBUFFERIMPL_H_
end_comment
end_unit
