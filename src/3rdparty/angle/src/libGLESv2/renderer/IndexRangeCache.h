begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013 The ANGLE Project Authors. All rights reserved.
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
comment|// IndexRangeCache.h: Defines the rx::IndexRangeCache class which stores information about
end_comment
begin_comment
comment|// ranges of indices.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_INDEXRANGECACHE_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_INDEXRANGECACHE_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_INDEXRANGECACHE_H_
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
name|IndexRangeCache
block|{
name|public
label|:
name|void
name|addRange
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|unsigned
name|int
name|offset
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|unsigned
name|int
name|minIdx
parameter_list|,
name|unsigned
name|int
name|maxIdx
parameter_list|,
name|unsigned
name|int
name|streamOffset
parameter_list|)
function_decl|;
name|bool
name|findRange
argument_list|(
name|GLenum
name|type
argument_list|,
name|unsigned
name|int
name|offset
argument_list|,
name|GLsizei
name|count
argument_list|,
name|unsigned
name|int
operator|*
name|outMinIndex
argument_list|,
name|unsigned
name|int
operator|*
name|outMaxIndex
argument_list|,
name|unsigned
name|int
operator|*
name|outStreamOffset
argument_list|)
decl|const
decl_stmt|;
name|void
name|invalidateRange
parameter_list|(
name|unsigned
name|int
name|offset
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
name|private
label|:
struct|struct
name|IndexRange
block|{
name|GLenum
name|type
decl_stmt|;
name|unsigned
name|int
name|offset
decl_stmt|;
name|GLsizei
name|count
decl_stmt|;
name|IndexRange
argument_list|()
expr_stmt|;
name|IndexRange
argument_list|(
argument|GLenum type
argument_list|,
argument|intptr_t offset
argument_list|,
argument|GLsizei count
argument_list|)
empty_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|IndexRange
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
block|}
struct|;
struct|struct
name|IndexBounds
block|{
name|unsigned
name|int
name|minIndex
decl_stmt|;
name|unsigned
name|int
name|maxIndex
decl_stmt|;
name|unsigned
name|int
name|streamOffset
decl_stmt|;
name|IndexBounds
argument_list|()
expr_stmt|;
name|IndexBounds
argument_list|(
argument|unsigned int minIdx
argument_list|,
argument|unsigned int maxIdx
argument_list|,
argument|unsigned int offset
argument_list|)
empty_stmt|;
block|}
struct|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|IndexRange
operator|,
name|IndexBounds
operator|>
name|IndexRangeMap
expr_stmt|;
name|IndexRangeMap
name|mIndexRangeCache
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
endif|LIBGLESV2_RENDERER_INDEXRANGECACHE_H
end_endif
end_unit
