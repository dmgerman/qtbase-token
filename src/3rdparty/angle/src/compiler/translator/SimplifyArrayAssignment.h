begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2015 The ANGLE Project Authors. All rights reserved.
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
comment|// SimplifyArrayAssignment is an AST traverser to replace statements where
end_comment
begin_comment
comment|// the return value of array assignment is used with statements where
end_comment
begin_comment
comment|// the return value of array assignment is not used.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_SIMPLIFYARRAYASSIGNMENT_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_SIMPLIFYARRAYASSIGNMENT_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_SIMPLIFYARRAYASSIGNMENT_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_decl_stmt
name|class
name|SimplifyArrayAssignment
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|SimplifyArrayAssignment
argument_list|()
block|{ }
name|virtual
name|bool
name|visitBinary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBinary *node
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_SIMPLIFYARRAYASSIGNMENT_H_
end_comment
end_unit
