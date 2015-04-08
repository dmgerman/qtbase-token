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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_REMOVESWITCHFALLTHROUGH_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_REMOVESWITCHFALLTHROUGH_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_REMOVESWITCHFALLTHROUGH_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_decl_stmt
name|class
name|RemoveSwitchFallThrough
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
comment|// When given a statementList from a switch AST node, return an updated
comment|// statementList that has fall-through removed.
specifier|static
name|TIntermAggregate
operator|*
name|removeFallThrough
argument_list|(
name|TIntermAggregate
operator|*
name|statementList
argument_list|)
block|;
name|private
operator|:
name|RemoveSwitchFallThrough
argument_list|(
name|TIntermAggregate
operator|*
name|statementList
argument_list|)
block|;
name|void
name|visitSymbol
argument_list|(
argument|TIntermSymbol *node
argument_list|)
name|override
block|;
name|void
name|visitConstantUnion
argument_list|(
argument|TIntermConstantUnion *node
argument_list|)
name|override
block|;
name|bool
name|visitBinary
argument_list|(
argument|Visit
argument_list|,
argument|TIntermBinary *node
argument_list|)
name|override
block|;
name|bool
name|visitUnary
argument_list|(
argument|Visit
argument_list|,
argument|TIntermUnary *node
argument_list|)
name|override
block|;
name|bool
name|visitSelection
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermSelection *node
argument_list|)
name|override
block|;
name|bool
name|visitSwitch
argument_list|(
argument|Visit
argument_list|,
argument|TIntermSwitch *node
argument_list|)
name|override
block|;
name|bool
name|visitCase
argument_list|(
argument|Visit
argument_list|,
argument|TIntermCase *node
argument_list|)
name|override
block|;
name|bool
name|visitAggregate
argument_list|(
argument|Visit
argument_list|,
argument|TIntermAggregate *node
argument_list|)
name|override
block|;
name|bool
name|visitLoop
argument_list|(
argument|Visit
argument_list|,
argument|TIntermLoop *node
argument_list|)
name|override
block|;
name|bool
name|visitBranch
argument_list|(
argument|Visit
argument_list|,
argument|TIntermBranch *node
argument_list|)
name|override
block|;
name|void
name|outputSequence
argument_list|(
argument|TIntermSequence *sequence
argument_list|,
argument|size_t startIndex
argument_list|)
block|;
name|void
name|handlePreviousCase
argument_list|()
block|;
name|TIntermAggregate
operator|*
name|mStatementList
block|;
name|TIntermAggregate
operator|*
name|mStatementListOut
block|;
name|bool
name|mLastStatementWasBreak
block|;
name|TIntermAggregate
operator|*
name|mPreviousCase
block|;
name|std
operator|::
name|vector
operator|<
name|TIntermAggregate
operator|*
operator|>
name|mCasesSharingBreak
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_REMOVESWITCHFALLTHROUGH_H_
end_comment
end_unit
