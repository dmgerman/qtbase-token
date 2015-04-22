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
name|COMPILER_TRANSLATOR_VALIDATESWITCH_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_VALIDATESWITCH_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_VALIDATESWITCH_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_struct_decl
struct_decl|struct
name|TParseContext
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|ValidateSwitch
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
comment|// Check for errors and output messages any remaining errors on the context.
comment|// Returns true if there are no errors.
specifier|static
name|bool
name|validate
argument_list|(
argument|TBasicType switchType
argument_list|,
argument|TParseContext *context
argument_list|,
argument|TIntermAggregate *statementList
argument_list|,
argument|const TSourceLoc&loc
argument_list|)
block|;
name|void
name|visitSymbol
argument_list|(
argument|TIntermSymbol *
argument_list|)
name|override
block|;
name|void
name|visitConstantUnion
argument_list|(
argument|TIntermConstantUnion *
argument_list|)
name|override
block|;
name|bool
name|visitBinary
argument_list|(
argument|Visit
argument_list|,
argument|TIntermBinary *
argument_list|)
name|override
block|;
name|bool
name|visitUnary
argument_list|(
argument|Visit
argument_list|,
argument|TIntermUnary *
argument_list|)
name|override
block|;
name|bool
name|visitSelection
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermSelection *
argument_list|)
name|override
block|;
name|bool
name|visitSwitch
argument_list|(
argument|Visit
argument_list|,
argument|TIntermSwitch *
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
argument|TIntermAggregate *
argument_list|)
name|override
block|;
name|bool
name|visitLoop
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermLoop *
argument_list|)
name|override
block|;
name|bool
name|visitBranch
argument_list|(
argument|Visit
argument_list|,
argument|TIntermBranch *
argument_list|)
name|override
block|;
name|private
operator|:
name|ValidateSwitch
argument_list|(
argument|TBasicType switchType
argument_list|,
argument|TParseContext *context
argument_list|)
block|;
name|bool
name|validateInternal
argument_list|(
specifier|const
name|TSourceLoc
operator|&
name|loc
argument_list|)
block|;
name|TBasicType
name|mSwitchType
block|;
name|TParseContext
operator|*
name|mContext
block|;
name|bool
name|mCaseTypeMismatch
block|;
name|bool
name|mFirstCaseFound
block|;
name|bool
name|mStatementBeforeCase
block|;
name|bool
name|mLastStatementWasCase
block|;
name|int
name|mControlFlowDepth
block|;
name|bool
name|mCaseInsideControlFlow
block|;
name|int
name|mDefaultCount
block|;
name|std
operator|::
name|set
operator|<
name|int
operator|>
name|mCasesSigned
block|;
name|std
operator|::
name|set
operator|<
name|unsigned
name|int
operator|>
name|mCasesUnsigned
block|;
name|bool
name|mDuplicateCases
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_VALIDATESWITCH_H_
end_comment
end_unit
