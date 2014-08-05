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
comment|// RewriteElseBlocks.h: Prototype for tree transform to change
end_comment
begin_comment
comment|//   all if-else blocks to if-if blocks.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_REWRITE_ELSE_BLOCKS_H_
end_ifndef
begin_define
DECL|macro|COMPILER_REWRITE_ELSE_BLOCKS_H_
define|#
directive|define
name|COMPILER_REWRITE_ELSE_BLOCKS_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/intermediate.h"
end_include
begin_decl_stmt
name|namespace
name|sh
block|{
name|void
name|RewriteElseBlocks
parameter_list|(
name|TIntermNode
modifier|*
name|node
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_REWRITE_ELSE_BLOCKS_H_
end_comment
end_unit
