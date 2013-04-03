begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
comment|// Fence.h: Defines the gl::Fence class, which supports the GL_NV_fence extension.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_FENCE_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_FENCE_H_
define|#
directive|define
name|LIBGLESV2_FENCE_H_
end_define
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
name|Renderer
decl_stmt|;
name|class
name|FenceImpl
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Fence
block|{
name|public
label|:
name|explicit
name|Fence
argument_list|(
name|rx
operator|::
name|Renderer
operator|*
name|renderer
argument_list|)
decl_stmt|;
name|virtual
operator|~
name|Fence
argument_list|()
expr_stmt|;
name|GLboolean
name|isFence
parameter_list|()
function_decl|;
name|void
name|setFence
parameter_list|(
name|GLenum
name|condition
parameter_list|)
function_decl|;
name|GLboolean
name|testFence
parameter_list|()
function_decl|;
name|void
name|finishFence
parameter_list|()
function_decl|;
name|void
name|getFenceiv
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Fence
argument_list|)
expr_stmt|;
name|rx
operator|::
name|FenceImpl
operator|*
name|mFence
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_FENCE_H_
end_comment
end_unit
