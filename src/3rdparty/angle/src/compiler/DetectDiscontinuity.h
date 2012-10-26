begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
comment|// Contains analysis utilities for dealing with HLSL's lack of support for
end_comment
begin_comment
comment|// the use of intrinsic functions which (implicitly or explicitly) compute
end_comment
begin_comment
comment|// gradients of functions with discontinuities.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_DETECTDISCONTINUITY_H_
end_ifndef
begin_define
DECL|macro|COMPILER_DETECTDISCONTINUITY_H_
define|#
directive|define
name|COMPILER_DETECTDISCONTINUITY_H_
end_define
begin_include
include|#
directive|include
file|"compiler/intermediate.h"
end_include
begin_decl_stmt
name|namespace
name|sh
block|{
comment|// Checks whether a loop can run for a variable number of iterations
name|class
name|DetectLoopDiscontinuity
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|bool
name|traverse
argument_list|(
name|TIntermNode
operator|*
name|node
argument_list|)
block|;
name|protected
operator|:
name|bool
name|visitBranch
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBranch *node
argument_list|)
block|;
name|bool
name|visitAggregate
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermAggregate *node
argument_list|)
block|;
name|bool
name|mLoopDiscontinuity
block|; }
decl_stmt|;
name|bool
name|containsLoopDiscontinuity
parameter_list|(
name|TIntermNode
modifier|*
name|node
parameter_list|)
function_decl|;
comment|// Checks for intrinsic functions which compute gradients
name|class
name|DetectGradientOperation
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|bool
name|traverse
argument_list|(
name|TIntermNode
operator|*
name|node
argument_list|)
block|;
name|protected
operator|:
name|bool
name|visitUnary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermUnary *node
argument_list|)
block|;
name|bool
name|visitAggregate
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermAggregate *node
argument_list|)
block|;
name|bool
name|mGradientOperation
block|; }
decl_stmt|;
name|bool
name|containsGradientOperation
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
comment|// COMPILER_DETECTDISCONTINUITY_H_
end_comment
end_unit
