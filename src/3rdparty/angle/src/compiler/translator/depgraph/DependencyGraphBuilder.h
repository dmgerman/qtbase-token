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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_DEPGRAPH_DEPENDENCY_GRAPH_BUILDER_H
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_DEPGRAPH_DEPENDENCY_GRAPH_BUILDER_H
define|#
directive|define
name|COMPILER_TRANSLATOR_DEPGRAPH_DEPENDENCY_GRAPH_BUILDER_H
end_define
begin_include
include|#
directive|include
file|"compiler/translator/depgraph/DependencyGraph.h"
end_include
begin_comment
comment|//
end_comment
begin_comment
comment|// Creates a dependency graph of symbols, function calls, conditions etc. by
end_comment
begin_comment
comment|// traversing a intermediate tree.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TDependencyGraphBuilder
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
specifier|static
name|void
name|build
argument_list|(
name|TIntermNode
operator|*
name|node
argument_list|,
name|TDependencyGraph
operator|*
name|graph
argument_list|)
block|;
name|virtual
name|void
name|visitSymbol
argument_list|(
name|TIntermSymbol
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visitBinary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBinary *
argument_list|)
block|;
name|virtual
name|bool
name|visitSelection
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermSelection *
argument_list|)
block|;
name|virtual
name|bool
name|visitAggregate
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermAggregate *
argument_list|)
block|;
name|virtual
name|bool
name|visitLoop
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermLoop *
argument_list|)
block|;
name|private
operator|:
typedef|typedef
name|std
operator|::
name|stack
operator|<
name|TGraphSymbol
operator|*
operator|>
name|TSymbolStack
expr_stmt|;
end_decl_stmt
begin_typedef
typedef|typedef
name|std
operator|::
name|set
operator|<
name|TGraphParentNode
operator|*
operator|>
name|TParentNodeSet
expr_stmt|;
end_typedef
begin_comment
comment|//
end_comment
begin_comment
comment|// For collecting the dependent nodes of assignments, conditions, etc.
end_comment
begin_comment
comment|// while traversing the intermediate tree.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This data structure is stack of sets. Each set contains dependency graph
end_comment
begin_comment
comment|// parent nodes.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TNodeSetStack
block|{
name|public
label|:
name|TNodeSetStack
argument_list|()
block|{}
empty_stmt|;
operator|~
name|TNodeSetStack
argument_list|()
block|{
name|clear
argument_list|()
block|; }
comment|// This should only be called after a pushSet.
comment|// Returns NULL if the top set is empty.
name|TParentNodeSet
operator|*
name|getTopSet
argument_list|()
specifier|const
block|{
name|ASSERT
argument_list|(
operator|!
name|mNodeSets
operator|.
name|empty
argument_list|()
argument_list|)
block|;
name|TParentNodeSet
operator|*
name|topSet
operator|=
name|mNodeSets
operator|.
name|top
argument_list|()
block|;
return|return
operator|!
name|topSet
operator|->
name|empty
argument_list|()
condition|?
name|topSet
else|:
name|NULL
return|;
block|}
name|void
name|pushSet
parameter_list|()
block|{
name|mNodeSets
operator|.
name|push
argument_list|(
argument|new TParentNodeSet()
argument_list|)
expr_stmt|;
block|}
name|void
name|popSet
parameter_list|()
block|{
name|ASSERT
argument_list|(
operator|!
name|mNodeSets
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|delete
name|mNodeSets
operator|.
name|top
parameter_list|()
function_decl|;
name|mNodeSets
operator|.
name|pop
argument_list|()
expr_stmt|;
block|}
comment|// Pops the top set and adds its contents to the new top set.
comment|// This should only be called after a pushSet.
comment|// If there is no set below the top set, the top set is just deleted.
name|void
name|popSetIntoNext
parameter_list|()
block|{
name|ASSERT
argument_list|(
operator|!
name|mNodeSets
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|TParentNodeSet
modifier|*
name|oldTopSet
init|=
name|mNodeSets
operator|.
name|top
argument_list|()
decl_stmt|;
name|mNodeSets
operator|.
name|pop
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|mNodeSets
operator|.
name|empty
argument_list|()
condition|)
block|{
name|TParentNodeSet
modifier|*
name|newTopSet
init|=
name|mNodeSets
operator|.
name|top
argument_list|()
decl_stmt|;
name|newTopSet
operator|->
name|insert
argument_list|(
name|oldTopSet
operator|->
name|begin
argument_list|()
argument_list|,
name|oldTopSet
operator|->
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|delete
name|oldTopSet
decl_stmt|;
block|}
comment|// Does nothing if there is no top set.
comment|// This can be called when there is no top set if we are visiting
comment|// symbols that are not under an assignment or condition.
comment|// We don't need to track those symbols.
name|void
name|insertIntoTopSet
parameter_list|(
name|TGraphParentNode
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|mNodeSets
operator|.
name|empty
argument_list|()
condition|)
return|return;
name|mNodeSets
operator|.
name|top
argument_list|()
operator|->
name|insert
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
name|void
name|clear
parameter_list|()
block|{
while|while
condition|(
operator|!
name|mNodeSets
operator|.
name|empty
argument_list|()
condition|)
name|popSet
argument_list|()
expr_stmt|;
block|}
name|private
label|:
typedef|typedef
name|std
operator|::
name|stack
operator|<
name|TParentNodeSet
operator|*
operator|>
name|TParentNodeSetStack
expr_stmt|;
name|TParentNodeSetStack
name|mNodeSets
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// An instance of this class pushes a new node set when instantiated.
end_comment
begin_comment
comment|// When the instance goes out of scope, it and pops the node set.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TNodeSetMaintainer
block|{
name|public
label|:
name|TNodeSetMaintainer
argument_list|(
name|TDependencyGraphBuilder
operator|*
name|factory
argument_list|)
operator|:
name|mSets
argument_list|(
argument|factory->mNodeSets
argument_list|)
block|{
name|mSets
operator|.
name|pushSet
argument_list|()
block|;         }
operator|~
name|TNodeSetMaintainer
argument_list|()
block|{
name|mSets
operator|.
name|popSet
argument_list|()
block|; }
name|protected
operator|:
name|TNodeSetStack
operator|&
name|mSets
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// An instance of this class pushes a new node set when instantiated.
end_comment
begin_comment
comment|// When the instance goes out of scope, it and pops the top node set and adds
end_comment
begin_comment
comment|// its contents to the new top node set.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TNodeSetPropagatingMaintainer
block|{
name|public
label|:
name|TNodeSetPropagatingMaintainer
argument_list|(
name|TDependencyGraphBuilder
operator|*
name|factory
argument_list|)
operator|:
name|mSets
argument_list|(
argument|factory->mNodeSets
argument_list|)
block|{
name|mSets
operator|.
name|pushSet
argument_list|()
block|;         }
operator|~
name|TNodeSetPropagatingMaintainer
argument_list|()
block|{
name|mSets
operator|.
name|popSetIntoNext
argument_list|()
block|; }
name|protected
operator|:
name|TNodeSetStack
operator|&
name|mSets
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// An instance of this class keeps track of the leftmost symbol while we're
end_comment
begin_comment
comment|// exploring an assignment.
end_comment
begin_comment
comment|// It will push the placeholder symbol kLeftSubtree when instantiated under a
end_comment
begin_comment
comment|// left subtree, and kRightSubtree under a right subtree.
end_comment
begin_comment
comment|// When it goes out of scope, it will pop the leftmost symbol at the top of the
end_comment
begin_comment
comment|// scope.
end_comment
begin_comment
comment|// During traversal, the TDependencyGraphBuilder will replace kLeftSubtree with
end_comment
begin_comment
comment|// a real symbol.
end_comment
begin_comment
comment|// kRightSubtree will never be replaced by a real symbol because we are tracking
end_comment
begin_comment
comment|// the leftmost symbol.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TLeftmostSymbolMaintainer
block|{
name|public
label|:
name|TLeftmostSymbolMaintainer
argument_list|(
name|TDependencyGraphBuilder
operator|*
name|factory
argument_list|,
name|TGraphSymbol
operator|&
name|subtree
argument_list|)
operator|:
name|mLeftmostSymbols
argument_list|(
argument|factory->mLeftmostSymbols
argument_list|)
block|{
name|mNeedsPlaceholderSymbol
operator|=
name|mLeftmostSymbols
operator|.
name|empty
argument_list|()
operator|||
name|mLeftmostSymbols
operator|.
name|top
argument_list|()
operator|!=
operator|&
name|subtree
block|;
if|if
condition|(
name|mNeedsPlaceholderSymbol
condition|)
name|mLeftmostSymbols
operator|.
name|push
argument_list|(
operator|&
name|subtree
argument_list|)
expr_stmt|;
block|}
operator|~
name|TLeftmostSymbolMaintainer
argument_list|()
block|{
if|if
condition|(
name|mNeedsPlaceholderSymbol
condition|)
name|mLeftmostSymbols
operator|.
name|pop
argument_list|()
expr_stmt|;
block|}
name|protected
label|:
name|TSymbolStack
modifier|&
name|mLeftmostSymbols
decl_stmt|;
name|bool
name|mNeedsPlaceholderSymbol
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|TDependencyGraphBuilder
argument_list|(
name|TDependencyGraph
operator|*
name|graph
argument_list|)
operator|:
name|TIntermTraverser
argument_list|(
name|true
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
operator|,
name|mLeftSubtree
argument_list|(
name|NULL
argument_list|)
operator|,
name|mRightSubtree
argument_list|(
name|NULL
argument_list|)
operator|,
name|mGraph
argument_list|(
argument|graph
argument_list|)
block|{}
name|void
name|build
argument_list|(
argument|TIntermNode *intermNode
argument_list|)
block|{
name|intermNode
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
block|; }
name|void
name|connectMultipleNodesToSingleNode
argument_list|(
argument|TParentNodeSet *nodes
argument_list|,
argument|TGraphNode *node
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|visitAssignment
parameter_list|(
name|TIntermBinary
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|visitLogicalOp
parameter_list|(
name|TIntermBinary
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|visitBinaryChildren
parameter_list|(
name|TIntermBinary
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|visitFunctionDefinition
parameter_list|(
name|TIntermAggregate
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|visitFunctionCall
parameter_list|(
name|TIntermAggregate
modifier|*
name|intermFunctionCall
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|visitAggregateChildren
parameter_list|(
name|TIntermAggregate
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|TGraphSymbol
name|mLeftSubtree
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TGraphSymbol
name|mRightSubtree
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TDependencyGraph
modifier|*
name|mGraph
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TNodeSetStack
name|mNodeSets
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TSymbolStack
name|mLeftmostSymbols
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_DEPGRAPH_DEPENDENCY_GRAPH_BUILDER_H
end_comment
end_unit
