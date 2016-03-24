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
comment|// CallDAG.h: Defines a call graph DAG of functions to be re-used accross
end_comment
begin_comment
comment|// analyses, allows to efficiently traverse the functions in topological
end_comment
begin_comment
comment|// order.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_CALLDAG_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_CALLDAG_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_CALLDAG_H_
end_define
begin_include
include|#
directive|include
file|<map>
end_include
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/VariableInfo.h"
end_include
begin_comment
comment|// The translator needs to analyze the the graph of the function calls
end_comment
begin_comment
comment|// to run checks and analyses; since in GLSL recursion is not allowed
end_comment
begin_comment
comment|// that graph is a DAG.
end_comment
begin_comment
comment|// This class is used to precompute that function call DAG so that it
end_comment
begin_comment
comment|// can be reused by multiple analyses.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// It stores a vector of function records, with one record per function.
end_comment
begin_comment
comment|// Records are accessed by index but a mangled function name can be converted
end_comment
begin_comment
comment|// to the index of the corresponding record. The records mostly contain the
end_comment
begin_comment
comment|// AST node of the function and the indices of the function's callees.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// In addition, records are in reverse topological order: a function F being
end_comment
begin_comment
comment|// called by a function G will have index index(F)< index(G), that way
end_comment
begin_comment
comment|// depth-first analysis becomes analysis in the order of indices.
end_comment
begin_decl_stmt
name|class
name|CallDAG
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|CallDAG
argument_list|()
block|;
operator|~
name|CallDAG
argument_list|()
block|;      struct
name|Record
block|{
name|std
operator|::
name|string
name|name
block|;
name|TIntermAggregate
operator|*
name|node
block|;
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|callees
block|;     }
block|;      enum
name|InitResult
block|{
name|INITDAG_SUCCESS
block|,
name|INITDAG_RECURSION
block|,
name|INITDAG_UNDEFINED
block|,     }
block|;
comment|// Returns INITDAG_SUCCESS if it was able to create the DAG, otherwise prints
comment|// the initialization error in info, if present.
name|InitResult
name|init
argument_list|(
name|TIntermNode
operator|*
name|root
argument_list|,
name|TInfoSinkBase
operator|*
name|info
argument_list|)
block|;
comment|// Returns InvalidIndex if the function wasn't found
name|size_t
name|findIndex
argument_list|(
argument|const TIntermAggregate *function
argument_list|)
specifier|const
block|;
specifier|const
name|Record
operator|&
name|getRecordFromIndex
argument_list|(
argument|size_t index
argument_list|)
specifier|const
block|;
specifier|const
name|Record
operator|&
name|getRecord
argument_list|(
argument|const TIntermAggregate *function
argument_list|)
specifier|const
block|;
name|size_t
name|size
argument_list|()
specifier|const
block|;
name|void
name|clear
argument_list|()
block|;
specifier|const
specifier|static
name|size_t
name|InvalidIndex
block|;
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|Record
operator|>
name|mRecords
block|;
name|std
operator|::
name|map
operator|<
name|int
block|,
name|int
operator|>
name|mFunctionIdToIndex
block|;
name|class
name|CallDAGCreator
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_CALLDAG_H_
end_comment
end_unit
