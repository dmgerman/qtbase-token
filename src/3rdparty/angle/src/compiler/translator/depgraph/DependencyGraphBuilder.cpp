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
begin_include
include|#
directive|include
file|"compiler/translator/depgraph/DependencyGraphBuilder.h"
end_include
begin_function
DECL|function|build
name|void
name|TDependencyGraphBuilder
operator|::
name|build
parameter_list|(
name|TIntermNode
modifier|*
name|node
parameter_list|,
name|TDependencyGraph
modifier|*
name|graph
parameter_list|)
block|{
name|TDependencyGraphBuilder
name|builder
argument_list|(
name|graph
argument_list|)
decl_stmt|;
name|builder
operator|.
name|build
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visitAggregate
name|bool
name|TDependencyGraphBuilder
operator|::
name|visitAggregate
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|intermAggregate
parameter_list|)
block|{
switch|switch
condition|(
name|intermAggregate
operator|->
name|getOp
argument_list|()
condition|)
block|{
case|case
name|EOpFunction
case|:
name|visitFunctionDefinition
argument_list|(
name|intermAggregate
argument_list|)
expr_stmt|;
break|break;
case|case
name|EOpFunctionCall
case|:
name|visitFunctionCall
argument_list|(
name|intermAggregate
argument_list|)
expr_stmt|;
break|break;
default|default:
name|visitAggregateChildren
argument_list|(
name|intermAggregate
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|visitFunctionDefinition
name|void
name|TDependencyGraphBuilder
operator|::
name|visitFunctionDefinition
parameter_list|(
name|TIntermAggregate
modifier|*
name|intermAggregate
parameter_list|)
block|{
comment|// Currently, we do not support user defined functions.
if|if
condition|(
name|intermAggregate
operator|->
name|getName
argument_list|()
operator|!=
literal|"main("
condition|)
return|return;
name|visitAggregateChildren
argument_list|(
name|intermAggregate
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Takes an expression like "f(x)" and creates a dependency graph like
end_comment
begin_comment
comment|// "x -> argument 0 -> function call".
end_comment
begin_function
DECL|function|visitFunctionCall
name|void
name|TDependencyGraphBuilder
operator|::
name|visitFunctionCall
parameter_list|(
name|TIntermAggregate
modifier|*
name|intermFunctionCall
parameter_list|)
block|{
name|TGraphFunctionCall
modifier|*
name|functionCall
init|=
name|mGraph
operator|->
name|createFunctionCall
argument_list|(
name|intermFunctionCall
argument_list|)
decl_stmt|;
comment|// Run through the function call arguments.
name|int
name|argumentNumber
init|=
literal|0
decl_stmt|;
name|TIntermSequence
modifier|*
name|intermArguments
init|=
name|intermFunctionCall
operator|->
name|getSequence
argument_list|()
decl_stmt|;
for|for
control|(
name|TIntermSequence
operator|::
name|const_iterator
name|iter
init|=
name|intermArguments
operator|->
name|begin
argument_list|()
init|;
name|iter
operator|!=
name|intermArguments
operator|->
name|end
argument_list|()
condition|;
operator|++
name|iter
operator|,
operator|++
name|argumentNumber
control|)
block|{
name|TNodeSetMaintainer
name|nodeSetMaintainer
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|TIntermNode
modifier|*
name|intermArgument
init|=
operator|*
name|iter
decl_stmt|;
name|intermArgument
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|TParentNodeSet
modifier|*
name|argumentNodes
init|=
name|mNodeSets
operator|.
name|getTopSet
argument_list|()
condition|)
block|{
name|TGraphArgument
modifier|*
name|argument
init|=
name|mGraph
operator|->
name|createArgument
argument_list|(
name|intermFunctionCall
argument_list|,
name|argumentNumber
argument_list|)
decl_stmt|;
name|connectMultipleNodesToSingleNode
argument_list|(
name|argumentNodes
argument_list|,
name|argument
argument_list|)
expr_stmt|;
name|argument
operator|->
name|addDependentNode
argument_list|(
name|functionCall
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Push the leftmost symbol of this function call into the current set of
comment|// dependent symbols to represent the result of this function call.
comment|// Thus, an expression like "y = f(x)" will yield a dependency graph like
comment|// "x -> argument 0 -> function call -> y".
comment|// This line essentially passes the function call node back up to an earlier
comment|// visitAssignment call, which will create the connection "function call -> y".
name|mNodeSets
operator|.
name|insertIntoTopSet
argument_list|(
name|functionCall
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visitAggregateChildren
name|void
name|TDependencyGraphBuilder
operator|::
name|visitAggregateChildren
parameter_list|(
name|TIntermAggregate
modifier|*
name|intermAggregate
parameter_list|)
block|{
name|TIntermSequence
modifier|*
name|sequence
init|=
name|intermAggregate
operator|->
name|getSequence
argument_list|()
decl_stmt|;
for|for
control|(
name|TIntermSequence
operator|::
name|const_iterator
name|iter
init|=
name|sequence
operator|->
name|begin
argument_list|()
init|;
name|iter
operator|!=
name|sequence
operator|->
name|end
argument_list|()
condition|;
operator|++
name|iter
control|)
block|{
name|TIntermNode
modifier|*
name|intermChild
init|=
operator|*
name|iter
decl_stmt|;
name|intermChild
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|visitSymbol
name|void
name|TDependencyGraphBuilder
operator|::
name|visitSymbol
parameter_list|(
name|TIntermSymbol
modifier|*
name|intermSymbol
parameter_list|)
block|{
comment|// Push this symbol into the set of dependent symbols for the current
comment|// assignment or condition that we are traversing.
name|TGraphSymbol
modifier|*
name|symbol
init|=
name|mGraph
operator|->
name|getOrCreateSymbol
argument_list|(
name|intermSymbol
argument_list|)
decl_stmt|;
name|mNodeSets
operator|.
name|insertIntoTopSet
argument_list|(
name|symbol
argument_list|)
expr_stmt|;
comment|// If this symbol is the current leftmost symbol under an assignment, replace
comment|// the previous leftmost symbol with this symbol.
if|if
condition|(
operator|!
name|mLeftmostSymbols
operator|.
name|empty
argument_list|()
operator|&&
name|mLeftmostSymbols
operator|.
name|top
argument_list|()
operator|!=
operator|&
name|mRightSubtree
condition|)
block|{
name|mLeftmostSymbols
operator|.
name|pop
argument_list|()
expr_stmt|;
name|mLeftmostSymbols
operator|.
name|push
argument_list|(
name|symbol
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|visitBinary
name|bool
name|TDependencyGraphBuilder
operator|::
name|visitBinary
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermBinary
modifier|*
name|intermBinary
parameter_list|)
block|{
name|TOperator
name|op
init|=
name|intermBinary
operator|->
name|getOp
argument_list|()
decl_stmt|;
if|if
condition|(
name|op
operator|==
name|EOpInitialize
operator|||
name|intermBinary
operator|->
name|isAssignment
argument_list|()
condition|)
name|visitAssignment
argument_list|(
name|intermBinary
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|op
operator|==
name|EOpLogicalAnd
operator|||
name|op
operator|==
name|EOpLogicalOr
condition|)
name|visitLogicalOp
argument_list|(
name|intermBinary
argument_list|)
expr_stmt|;
else|else
name|visitBinaryChildren
argument_list|(
name|intermBinary
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|visitAssignment
name|void
name|TDependencyGraphBuilder
operator|::
name|visitAssignment
parameter_list|(
name|TIntermBinary
modifier|*
name|intermAssignment
parameter_list|)
block|{
name|TIntermTyped
modifier|*
name|intermLeft
init|=
name|intermAssignment
operator|->
name|getLeft
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|intermLeft
condition|)
return|return;
name|TGraphSymbol
modifier|*
name|leftmostSymbol
init|=
name|NULL
decl_stmt|;
block|{
name|TNodeSetMaintainer
name|nodeSetMaintainer
argument_list|(
name|this
argument_list|)
decl_stmt|;
block|{
name|TLeftmostSymbolMaintainer
name|leftmostSymbolMaintainer
argument_list|(
name|this
argument_list|,
name|mLeftSubtree
argument_list|)
decl_stmt|;
name|intermLeft
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|leftmostSymbol
operator|=
name|mLeftmostSymbols
operator|.
name|top
argument_list|()
expr_stmt|;
comment|// After traversing the left subtree of this assignment, we should
comment|// have found a real leftmost symbol, and the leftmost symbol should
comment|// not be a placeholder.
name|ASSERT
argument_list|(
name|leftmostSymbol
operator|!=
operator|&
name|mLeftSubtree
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|leftmostSymbol
operator|!=
operator|&
name|mRightSubtree
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|TIntermTyped
modifier|*
name|intermRight
init|=
name|intermAssignment
operator|->
name|getRight
argument_list|()
condition|)
block|{
name|TLeftmostSymbolMaintainer
name|leftmostSymbolMaintainer
argument_list|(
name|this
argument_list|,
name|mRightSubtree
argument_list|)
decl_stmt|;
name|intermRight
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|TParentNodeSet
modifier|*
name|assignmentNodes
init|=
name|mNodeSets
operator|.
name|getTopSet
argument_list|()
condition|)
name|connectMultipleNodesToSingleNode
argument_list|(
name|assignmentNodes
argument_list|,
name|leftmostSymbol
argument_list|)
expr_stmt|;
block|}
comment|// Push the leftmost symbol of this assignment into the current set of dependent
comment|// symbols to represent the result of this assignment.
comment|// An expression like "a = (b = c)" will yield a dependency graph like
comment|// "c -> b -> a".
comment|// This line essentially passes the leftmost symbol of the nested assignment
comment|// ("b" in this example) back up to the earlier visitAssignment call for the
comment|// outer assignment, which will create the connection "b -> a".
name|mNodeSets
operator|.
name|insertIntoTopSet
argument_list|(
name|leftmostSymbol
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visitLogicalOp
name|void
name|TDependencyGraphBuilder
operator|::
name|visitLogicalOp
parameter_list|(
name|TIntermBinary
modifier|*
name|intermLogicalOp
parameter_list|)
block|{
if|if
condition|(
name|TIntermTyped
modifier|*
name|intermLeft
init|=
name|intermLogicalOp
operator|->
name|getLeft
argument_list|()
condition|)
block|{
name|TNodeSetPropagatingMaintainer
name|nodeSetMaintainer
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|intermLeft
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|TParentNodeSet
modifier|*
name|leftNodes
init|=
name|mNodeSets
operator|.
name|getTopSet
argument_list|()
condition|)
block|{
name|TGraphLogicalOp
modifier|*
name|logicalOp
init|=
name|mGraph
operator|->
name|createLogicalOp
argument_list|(
name|intermLogicalOp
argument_list|)
decl_stmt|;
name|connectMultipleNodesToSingleNode
argument_list|(
name|leftNodes
argument_list|,
name|logicalOp
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|TIntermTyped
modifier|*
name|intermRight
init|=
name|intermLogicalOp
operator|->
name|getRight
argument_list|()
condition|)
block|{
name|TLeftmostSymbolMaintainer
name|leftmostSymbolMaintainer
argument_list|(
name|this
argument_list|,
name|mRightSubtree
argument_list|)
decl_stmt|;
name|intermRight
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|visitBinaryChildren
name|void
name|TDependencyGraphBuilder
operator|::
name|visitBinaryChildren
parameter_list|(
name|TIntermBinary
modifier|*
name|intermBinary
parameter_list|)
block|{
if|if
condition|(
name|TIntermTyped
modifier|*
name|intermLeft
init|=
name|intermBinary
operator|->
name|getLeft
argument_list|()
condition|)
name|intermLeft
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|TIntermTyped
modifier|*
name|intermRight
init|=
name|intermBinary
operator|->
name|getRight
argument_list|()
condition|)
block|{
name|TLeftmostSymbolMaintainer
name|leftmostSymbolMaintainer
argument_list|(
name|this
argument_list|,
name|mRightSubtree
argument_list|)
decl_stmt|;
name|intermRight
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|visitSelection
name|bool
name|TDependencyGraphBuilder
operator|::
name|visitSelection
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermSelection
modifier|*
name|intermSelection
parameter_list|)
block|{
if|if
condition|(
name|TIntermNode
modifier|*
name|intermCondition
init|=
name|intermSelection
operator|->
name|getCondition
argument_list|()
condition|)
block|{
name|TNodeSetMaintainer
name|nodeSetMaintainer
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|intermCondition
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|TParentNodeSet
modifier|*
name|conditionNodes
init|=
name|mNodeSets
operator|.
name|getTopSet
argument_list|()
condition|)
block|{
name|TGraphSelection
modifier|*
name|selection
init|=
name|mGraph
operator|->
name|createSelection
argument_list|(
name|intermSelection
argument_list|)
decl_stmt|;
name|connectMultipleNodesToSingleNode
argument_list|(
name|conditionNodes
argument_list|,
name|selection
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|TIntermNode
modifier|*
name|intermTrueBlock
init|=
name|intermSelection
operator|->
name|getTrueBlock
argument_list|()
condition|)
name|intermTrueBlock
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|TIntermNode
modifier|*
name|intermFalseBlock
init|=
name|intermSelection
operator|->
name|getFalseBlock
argument_list|()
condition|)
name|intermFalseBlock
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|visitLoop
name|bool
name|TDependencyGraphBuilder
operator|::
name|visitLoop
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermLoop
modifier|*
name|intermLoop
parameter_list|)
block|{
if|if
condition|(
name|TIntermTyped
modifier|*
name|intermCondition
init|=
name|intermLoop
operator|->
name|getCondition
argument_list|()
condition|)
block|{
name|TNodeSetMaintainer
name|nodeSetMaintainer
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|intermCondition
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|TParentNodeSet
modifier|*
name|conditionNodes
init|=
name|mNodeSets
operator|.
name|getTopSet
argument_list|()
condition|)
block|{
name|TGraphLoop
modifier|*
name|loop
init|=
name|mGraph
operator|->
name|createLoop
argument_list|(
name|intermLoop
argument_list|)
decl_stmt|;
name|connectMultipleNodesToSingleNode
argument_list|(
name|conditionNodes
argument_list|,
name|loop
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|TIntermNode
modifier|*
name|intermBody
init|=
name|intermLoop
operator|->
name|getBody
argument_list|()
condition|)
name|intermBody
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|TIntermTyped
modifier|*
name|intermExpression
init|=
name|intermLoop
operator|->
name|getExpression
argument_list|()
condition|)
name|intermExpression
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|connectMultipleNodesToSingleNode
name|void
name|TDependencyGraphBuilder
operator|::
name|connectMultipleNodesToSingleNode
parameter_list|(
name|TParentNodeSet
modifier|*
name|nodes
parameter_list|,
name|TGraphNode
modifier|*
name|node
parameter_list|)
specifier|const
block|{
for|for
control|(
name|TParentNodeSet
operator|::
name|const_iterator
name|iter
init|=
name|nodes
operator|->
name|begin
argument_list|()
init|;
name|iter
operator|!=
name|nodes
operator|->
name|end
argument_list|()
condition|;
operator|++
name|iter
control|)
block|{
name|TGraphParentNode
modifier|*
name|currentNode
init|=
operator|*
name|iter
decl_stmt|;
name|currentNode
operator|->
name|addDependentNode
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
