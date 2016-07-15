begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2011 The ANGLE Project Authors. All rights reserved.
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
comment|// HandleAllocator.h: Defines the gl::HandleAllocator class, which is used to
end_comment
begin_comment
comment|// allocate GL handles.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_HANDLEALLOCATOR_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_HANDLEALLOCATOR_H_
define|#
directive|define
name|LIBANGLE_HANDLEALLOCATOR_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|<stack>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|HandleAllocator
name|final
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
comment|// Maximum handle = MAX_UINT-1
name|HandleAllocator
argument_list|()
block|;
comment|// Specify maximum handle value
name|HandleAllocator
argument_list|(
argument|GLuint maximumHandleValue
argument_list|)
block|;
operator|~
name|HandleAllocator
argument_list|()
block|;
name|void
name|setBaseHandle
argument_list|(
argument|GLuint value
argument_list|)
block|;
name|GLuint
name|allocate
argument_list|()
block|;
name|void
name|release
argument_list|(
argument|GLuint handle
argument_list|)
block|;
name|void
name|reserve
argument_list|(
argument|GLuint handle
argument_list|)
block|;
name|private
operator|:
name|GLuint
name|mBaseValue
block|;
name|GLuint
name|mNextValue
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|GLuint
operator|>
name|HandleList
expr_stmt|;
name|HandleList
name|mFreeValues
decl_stmt|;
struct|struct
name|HandleRange
block|{
name|HandleRange
argument_list|(
argument|GLuint beginIn
argument_list|,
argument|GLuint endIn
argument_list|)
block|:
name|begin
argument_list|(
name|beginIn
argument_list|)
operator|,
name|end
argument_list|(
argument|endIn
argument_list|)
block|{}
name|GLuint
name|begin
expr_stmt|;
name|GLuint
name|end
decl_stmt|;
block|}
struct|;
struct_decl|struct
name|HandleRangeComparator
struct_decl|;
comment|// The freelist consists of never-allocated handles, stored
comment|// as ranges, and handles that were previously allocated and
comment|// released, stored in a stack.
name|std
operator|::
name|vector
operator|<
name|HandleRange
operator|>
name|mUnallocatedList
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|GLuint
operator|>
name|mReleasedList
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
unit|}
comment|// namespace gl
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_HANDLEALLOCATOR_H_
end_comment
end_unit
