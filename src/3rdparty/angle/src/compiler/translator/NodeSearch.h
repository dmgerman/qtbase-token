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
comment|// NodeSearch.h: Utilities for searching translator node graphs
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TRANSLATOR_NODESEARCH_H_
end_ifndef
begin_define
DECL|macro|TRANSLATOR_NODESEARCH_H_
define|#
directive|define
name|TRANSLATOR_NODESEARCH_H_
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
name|template
operator|<
name|class
name|Parent
operator|>
name|class
name|NodeSearchTraverser
operator|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|NodeSearchTraverser
argument_list|()
operator|:
name|mFound
argument_list|(
argument|false
argument_list|)
block|{}
name|bool
name|found
argument_list|()
specifier|const
block|{
return|return
name|mFound
return|;
block|}
specifier|static
name|bool
name|search
argument_list|(
argument|TIntermNode *node
argument_list|)
block|{
name|Parent
name|searchTraverser
block|;
name|node
operator|->
name|traverse
argument_list|(
operator|&
name|searchTraverser
argument_list|)
block|;
return|return
name|searchTraverser
operator|.
name|found
argument_list|()
return|;
block|}
name|protected
operator|:
name|bool
name|mFound
block|; }
expr_stmt|;
name|class
name|FindDiscard
range|:
name|public
name|NodeSearchTraverser
operator|<
name|FindDiscard
operator|>
block|{
name|public
operator|:
name|virtual
name|bool
name|visitBranch
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBranch *node
argument_list|)
block|{
switch|switch
condition|(
name|node
operator|->
name|getFlowOp
argument_list|()
condition|)
block|{
case|case
name|EOpKill
case|:
name|mFound
operator|=
name|true
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
operator|!
name|mFound
return|;
block|}
block|}
decl_stmt|;
name|class
name|FindSideEffectRewriting
range|:
name|public
name|NodeSearchTraverser
operator|<
name|FindSideEffectRewriting
operator|>
block|{
name|public
operator|:
name|virtual
name|bool
name|visitBinary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBinary *node
argument_list|)
block|{
switch|switch
condition|(
name|node
operator|->
name|getOp
argument_list|()
condition|)
block|{
case|case
name|EOpLogicalOr
case|:
case|case
name|EOpLogicalAnd
case|:
if|if
condition|(
name|node
operator|->
name|getRight
argument_list|()
operator|->
name|hasSideEffects
argument_list|()
condition|)
block|{
name|mFound
operator|=
name|true
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
return|return
operator|!
name|mFound
return|;
block|}
block|}
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TRANSLATOR_NODESEARCH_H_
end_comment
end_unit
