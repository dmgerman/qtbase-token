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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_DETECT_RECURSION_H_
end_ifndef
begin_define
DECL|macro|COMPILER_DETECT_RECURSION_H_
define|#
directive|define
name|COMPILER_DETECT_RECURSION_H_
end_define
begin_include
include|#
directive|include
file|"GLSLANG/ShaderLang.h"
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_include
include|#
directive|include
file|"compiler/intermediate.h"
end_include
begin_include
include|#
directive|include
file|"compiler/VariableInfo.h"
end_include
begin_decl_stmt
DECL|variable|TInfoSink
name|class
name|TInfoSink
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Traverses intermediate tree to detect function recursion.
end_comment
begin_decl_stmt
name|class
name|DetectCallDepth
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
expr|enum
name|ErrorCode
block|{
name|kErrorMissingMain
block|,
name|kErrorRecursion
block|,
name|kErrorMaxDepthExceeded
block|,
name|kErrorNone
block|}
block|;
name|DetectCallDepth
argument_list|(
argument|TInfoSink& infoSync
argument_list|,
argument|bool limitCallStackDepth
argument_list|,
argument|int maxCallStackDepth
argument_list|)
block|;
operator|~
name|DetectCallDepth
argument_list|()
block|;
name|virtual
name|bool
name|visitAggregate
argument_list|(
name|Visit
argument_list|,
name|TIntermAggregate
operator|*
argument_list|)
block|;
name|bool
name|checkExceedsMaxDepth
argument_list|(
argument|int depth
argument_list|)
block|;
name|ErrorCode
name|detectCallDepth
argument_list|()
block|;
name|private
operator|:
name|class
name|FunctionNode
block|{
name|public
operator|:
specifier|static
specifier|const
name|int
name|kInfiniteCallDepth
operator|=
name|INT_MAX
block|;
name|FunctionNode
argument_list|(
specifier|const
name|TString
operator|&
name|fname
argument_list|)
block|;
specifier|const
name|TString
operator|&
name|getName
argument_list|()
specifier|const
block|;
comment|// If a function is already in the callee list, this becomes a no-op.
name|void
name|addCallee
argument_list|(
name|FunctionNode
operator|*
name|callee
argument_list|)
block|;
comment|// Returns kInifinityCallDepth if recursive function calls are detected.
name|int
name|detectCallDepth
argument_list|(
argument|DetectCallDepth* detectCallDepth
argument_list|,
argument|int depth
argument_list|)
block|;
comment|// Reset state.
name|void
name|reset
argument_list|()
block|;
name|private
operator|:
comment|// mangled function name is unique.
name|TString
name|name
block|;
comment|// functions that are directly called by this function.
name|TVector
operator|<
name|FunctionNode
operator|*
operator|>
name|callees
block|;
name|Visit
name|visit
block|;     }
block|;
name|ErrorCode
name|detectCallDepthForFunction
argument_list|(
name|FunctionNode
operator|*
name|func
argument_list|)
block|;
name|FunctionNode
operator|*
name|findFunctionByName
argument_list|(
specifier|const
name|TString
operator|&
name|name
argument_list|)
block|;
name|void
name|resetFunctionNodes
argument_list|()
block|;
name|TInfoSink
operator|&
name|getInfoSink
argument_list|()
block|{
return|return
name|infoSink
return|;
block|}
name|TVector
operator|<
name|FunctionNode
operator|*
operator|>
name|functions
block|;
name|FunctionNode
operator|*
name|currentFunction
block|;
name|TInfoSink
operator|&
name|infoSink
block|;
name|int
name|maxDepth
block|;
name|DetectCallDepth
argument_list|(
specifier|const
name|DetectCallDepth
operator|&
argument_list|)
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|DetectCallDepth
operator|&
operator|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_DETECT_RECURSION_H_
end_comment
end_unit
