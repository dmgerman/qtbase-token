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
comment|// UnfoldShortCircuitToIf is an AST traverser to convert short-circuiting operators to if-else statements.
end_comment
begin_comment
comment|// The results are assigned to s# temporaries, which are used by the main translator instead of
end_comment
begin_comment
comment|// the original expression.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"compiler/translator/UnfoldShortCircuitToIf.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_namespace
namespace|namespace
block|{
comment|// Traverser that unfolds one short-circuiting operation at a time.
DECL|class|UnfoldShortCircuitTraverser
class|class
name|UnfoldShortCircuitTraverser
super|:
specifier|public
name|TIntermTraverser
block|{
public|public:
name|UnfoldShortCircuitTraverser
parameter_list|()
constructor_decl|;
DECL|member|override
name|bool
name|visitBinary
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermBinary
modifier|*
name|node
parameter_list|)
specifier|override
function_decl|;
DECL|member|override
name|bool
name|visitAggregate
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
specifier|override
function_decl|;
DECL|member|override
name|bool
name|visitSelection
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermSelection
modifier|*
name|node
parameter_list|)
specifier|override
function_decl|;
DECL|member|override
name|bool
name|visitLoop
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermLoop
modifier|*
name|node
parameter_list|)
specifier|override
function_decl|;
name|void
name|nextIteration
parameter_list|()
function_decl|;
DECL|function|foundShortCircuit
name|bool
name|foundShortCircuit
parameter_list|()
specifier|const
block|{
return|return
name|mFoundShortCircuit
return|;
block|}
protected|protected:
comment|// Check if the traversal is inside a loop condition or expression, in which case the unfolded
comment|// expression needs to be copied inside the loop. Returns true if the copying is done, in which
comment|// case no further unfolding should be done on the same traversal.
comment|// The parameters are the node that will be unfolded to multiple statements and so can't remain
comment|// inside a loop condition, and its parent.
name|bool
name|copyLoopConditionOrExpression
parameter_list|(
name|TIntermNode
modifier|*
name|parent
parameter_list|,
name|TIntermTyped
modifier|*
name|node
parameter_list|)
function_decl|;
comment|// Marked to true once an operation that needs to be unfolded has been found.
comment|// After that, no more unfolding is performed on that traversal.
DECL|member|mFoundShortCircuit
name|bool
name|mFoundShortCircuit
decl_stmt|;
comment|// Set to the loop node while a loop condition or expression is being traversed.
DECL|member|mParentLoop
name|TIntermLoop
modifier|*
name|mParentLoop
decl_stmt|;
comment|// Parent of the loop node while a loop condition or expression is being traversed.
DECL|member|mLoopParent
name|TIntermNode
modifier|*
name|mLoopParent
decl_stmt|;
DECL|member|mInLoopCondition
name|bool
name|mInLoopCondition
decl_stmt|;
DECL|member|mInLoopExpression
name|bool
name|mInLoopExpression
decl_stmt|;
block|}
class|;
DECL|function|UnfoldShortCircuitTraverser
name|UnfoldShortCircuitTraverser
operator|::
name|UnfoldShortCircuitTraverser
parameter_list|()
member_init_list|:
name|TIntermTraverser
argument_list|(
literal|true
argument_list|,
literal|false
argument_list|,
literal|true
argument_list|)
member_init_list|,
name|mFoundShortCircuit
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mParentLoop
argument_list|(
literal|nullptr
argument_list|)
member_init_list|,
name|mLoopParent
argument_list|(
literal|nullptr
argument_list|)
member_init_list|,
name|mInLoopCondition
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mInLoopExpression
argument_list|(
literal|false
argument_list|)
block|{ }
DECL|function|visitBinary
name|bool
name|UnfoldShortCircuitTraverser
operator|::
name|visitBinary
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermBinary
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|mFoundShortCircuit
condition|)
return|return
literal|false
return|;
comment|// If our right node doesn't have side effects, we know we don't need to unfold this
comment|// expression: there will be no short-circuiting side effects to avoid
comment|// (note: unfolding doesn't depend on the left node -- it will always be evaluated)
if|if
condition|(
operator|!
name|node
operator|->
name|getRight
argument_list|()
operator|->
name|hasSideEffects
argument_list|()
condition|)
block|{
return|return
literal|true
return|;
block|}
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
name|mFoundShortCircuit
operator|=
literal|true
expr_stmt|;
if|if
condition|(
operator|!
name|copyLoopConditionOrExpression
argument_list|(
name|getParentNode
argument_list|()
argument_list|,
name|node
argument_list|)
condition|)
block|{
comment|// "x || y" is equivalent to "x ? true : y", which unfolds to "bool s; if(x) s = true;
comment|// else s = y;",
comment|// and then further simplifies down to "bool s = x; if(!s) s = y;".
name|TIntermSequence
name|insertions
decl_stmt|;
name|TType
name|boolType
argument_list|(
name|EbtBool
argument_list|,
name|EbpUndefined
argument_list|,
name|EvqTemporary
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|node
operator|->
name|getLeft
argument_list|()
operator|->
name|getType
argument_list|()
operator|==
name|boolType
argument_list|)
expr_stmt|;
name|insertions
operator|.
name|push_back
argument_list|(
name|createTempInitDeclaration
argument_list|(
name|node
operator|->
name|getLeft
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|TIntermAggregate
modifier|*
name|assignRightBlock
init|=
operator|new
name|TIntermAggregate
argument_list|(
name|EOpSequence
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|node
operator|->
name|getRight
argument_list|()
operator|->
name|getType
argument_list|()
operator|==
name|boolType
argument_list|)
expr_stmt|;
name|assignRightBlock
operator|->
name|getSequence
argument_list|()
operator|->
name|push_back
argument_list|(
name|createTempAssignment
argument_list|(
name|node
operator|->
name|getRight
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|TIntermUnary
modifier|*
name|notTempSymbol
init|=
operator|new
name|TIntermUnary
argument_list|(
name|EOpLogicalNot
argument_list|,
name|boolType
argument_list|)
decl_stmt|;
name|notTempSymbol
operator|->
name|setOperand
argument_list|(
name|createTempSymbol
argument_list|(
name|boolType
argument_list|)
argument_list|)
expr_stmt|;
name|TIntermSelection
modifier|*
name|ifNode
init|=
operator|new
name|TIntermSelection
argument_list|(
name|notTempSymbol
argument_list|,
name|assignRightBlock
argument_list|,
literal|nullptr
argument_list|)
decl_stmt|;
name|insertions
operator|.
name|push_back
argument_list|(
name|ifNode
argument_list|)
expr_stmt|;
name|insertStatementsInParentBlock
argument_list|(
name|insertions
argument_list|)
expr_stmt|;
name|NodeUpdateEntry
name|replaceVariable
argument_list|(
name|getParentNode
argument_list|()
argument_list|,
name|node
argument_list|,
name|createTempSymbol
argument_list|(
name|boolType
argument_list|)
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|mReplacements
operator|.
name|push_back
argument_list|(
name|replaceVariable
argument_list|)
expr_stmt|;
block|}
return|return
literal|false
return|;
case|case
name|EOpLogicalAnd
case|:
name|mFoundShortCircuit
operator|=
literal|true
expr_stmt|;
if|if
condition|(
operator|!
name|copyLoopConditionOrExpression
argument_list|(
name|getParentNode
argument_list|()
argument_list|,
name|node
argument_list|)
condition|)
block|{
comment|// "x&& y" is equivalent to "x ? y : false", which unfolds to "bool s; if(x) s = y;
comment|// else s = false;",
comment|// and then further simplifies down to "bool s = x; if(s) s = y;".
name|TIntermSequence
name|insertions
decl_stmt|;
name|TType
name|boolType
argument_list|(
name|EbtBool
argument_list|,
name|EbpUndefined
argument_list|,
name|EvqTemporary
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|node
operator|->
name|getLeft
argument_list|()
operator|->
name|getType
argument_list|()
operator|==
name|boolType
argument_list|)
expr_stmt|;
name|insertions
operator|.
name|push_back
argument_list|(
name|createTempInitDeclaration
argument_list|(
name|node
operator|->
name|getLeft
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|TIntermAggregate
modifier|*
name|assignRightBlock
init|=
operator|new
name|TIntermAggregate
argument_list|(
name|EOpSequence
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|node
operator|->
name|getRight
argument_list|()
operator|->
name|getType
argument_list|()
operator|==
name|boolType
argument_list|)
expr_stmt|;
name|assignRightBlock
operator|->
name|getSequence
argument_list|()
operator|->
name|push_back
argument_list|(
name|createTempAssignment
argument_list|(
name|node
operator|->
name|getRight
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|TIntermSelection
modifier|*
name|ifNode
init|=
operator|new
name|TIntermSelection
argument_list|(
name|createTempSymbol
argument_list|(
name|boolType
argument_list|)
argument_list|,
name|assignRightBlock
argument_list|,
literal|nullptr
argument_list|)
decl_stmt|;
name|insertions
operator|.
name|push_back
argument_list|(
name|ifNode
argument_list|)
expr_stmt|;
name|insertStatementsInParentBlock
argument_list|(
name|insertions
argument_list|)
expr_stmt|;
name|NodeUpdateEntry
name|replaceVariable
argument_list|(
name|getParentNode
argument_list|()
argument_list|,
name|node
argument_list|,
name|createTempSymbol
argument_list|(
name|boolType
argument_list|)
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|mReplacements
operator|.
name|push_back
argument_list|(
name|replaceVariable
argument_list|)
expr_stmt|;
block|}
return|return
literal|false
return|;
default|default:
return|return
literal|true
return|;
block|}
block|}
DECL|function|visitSelection
name|bool
name|UnfoldShortCircuitTraverser
operator|::
name|visitSelection
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermSelection
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|mFoundShortCircuit
condition|)
return|return
literal|false
return|;
comment|// Unfold "b ? x : y" into "type s; if(b) s = x; else s = y;"
if|if
condition|(
name|visit
operator|==
name|PreVisit
operator|&&
name|node
operator|->
name|usesTernaryOperator
argument_list|()
condition|)
block|{
name|mFoundShortCircuit
operator|=
literal|true
expr_stmt|;
if|if
condition|(
operator|!
name|copyLoopConditionOrExpression
argument_list|(
name|getParentNode
argument_list|()
argument_list|,
name|node
argument_list|)
condition|)
block|{
name|TIntermSequence
name|insertions
decl_stmt|;
name|TIntermSymbol
modifier|*
name|tempSymbol
init|=
name|createTempSymbol
argument_list|(
name|node
operator|->
name|getType
argument_list|()
argument_list|)
decl_stmt|;
name|TIntermAggregate
modifier|*
name|tempDeclaration
init|=
operator|new
name|TIntermAggregate
argument_list|(
name|EOpDeclaration
argument_list|)
decl_stmt|;
name|tempDeclaration
operator|->
name|getSequence
argument_list|()
operator|->
name|push_back
argument_list|(
name|tempSymbol
argument_list|)
expr_stmt|;
name|insertions
operator|.
name|push_back
argument_list|(
name|tempDeclaration
argument_list|)
expr_stmt|;
name|TIntermAggregate
modifier|*
name|trueBlock
init|=
operator|new
name|TIntermAggregate
argument_list|(
name|EOpSequence
argument_list|)
decl_stmt|;
name|TIntermBinary
modifier|*
name|trueAssignment
init|=
name|createTempAssignment
argument_list|(
name|node
operator|->
name|getTrueBlock
argument_list|()
operator|->
name|getAsTyped
argument_list|()
argument_list|)
decl_stmt|;
name|trueBlock
operator|->
name|getSequence
argument_list|()
operator|->
name|push_back
argument_list|(
name|trueAssignment
argument_list|)
expr_stmt|;
name|TIntermAggregate
modifier|*
name|falseBlock
init|=
operator|new
name|TIntermAggregate
argument_list|(
name|EOpSequence
argument_list|)
decl_stmt|;
name|TIntermBinary
modifier|*
name|falseAssignment
init|=
name|createTempAssignment
argument_list|(
name|node
operator|->
name|getFalseBlock
argument_list|()
operator|->
name|getAsTyped
argument_list|()
argument_list|)
decl_stmt|;
name|falseBlock
operator|->
name|getSequence
argument_list|()
operator|->
name|push_back
argument_list|(
name|falseAssignment
argument_list|)
expr_stmt|;
name|TIntermSelection
modifier|*
name|ifNode
init|=
operator|new
name|TIntermSelection
argument_list|(
name|node
operator|->
name|getCondition
argument_list|()
operator|->
name|getAsTyped
argument_list|()
argument_list|,
name|trueBlock
argument_list|,
name|falseBlock
argument_list|)
decl_stmt|;
name|insertions
operator|.
name|push_back
argument_list|(
name|ifNode
argument_list|)
expr_stmt|;
name|insertStatementsInParentBlock
argument_list|(
name|insertions
argument_list|)
expr_stmt|;
name|TIntermSymbol
modifier|*
name|ternaryResult
init|=
name|createTempSymbol
argument_list|(
name|node
operator|->
name|getType
argument_list|()
argument_list|)
decl_stmt|;
name|NodeUpdateEntry
name|replaceVariable
argument_list|(
name|getParentNode
argument_list|()
argument_list|,
name|node
argument_list|,
name|ternaryResult
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|mReplacements
operator|.
name|push_back
argument_list|(
name|replaceVariable
argument_list|)
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
DECL|function|visitAggregate
name|bool
name|UnfoldShortCircuitTraverser
operator|::
name|visitAggregate
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|visit
operator|==
name|PreVisit
operator|&&
name|mFoundShortCircuit
condition|)
return|return
literal|false
return|;
comment|// No need to traverse further
if|if
condition|(
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpComma
condition|)
block|{
name|ASSERT
argument_list|(
name|visit
operator|!=
name|PreVisit
operator|||
operator|!
name|mFoundShortCircuit
argument_list|)
expr_stmt|;
if|if
condition|(
name|visit
operator|==
name|PostVisit
operator|&&
name|mFoundShortCircuit
condition|)
block|{
comment|// We can be sure that we arrived here because there was a short-circuiting operator
comment|// inside the sequence operator since we only start traversing the sequence operator in
comment|// case a short-circuiting operator has not been found so far.
comment|// We need to unfold the sequence (comma) operator, otherwise the evaluation order of
comment|// statements would be messed up by unfolded operations inside.
comment|// Don't do any other unfolding on this round of traversal.
name|mReplacements
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mMultiReplacements
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mInsertions
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|copyLoopConditionOrExpression
argument_list|(
name|getParentNode
argument_list|()
argument_list|,
name|node
argument_list|)
condition|)
block|{
name|TIntermSequence
name|insertions
decl_stmt|;
name|TIntermSequence
modifier|*
name|seq
init|=
name|node
operator|->
name|getSequence
argument_list|()
decl_stmt|;
name|TIntermSequence
operator|::
name|size_type
name|i
init|=
literal|0
decl_stmt|;
name|ASSERT
argument_list|(
operator|!
name|seq
operator|->
name|empty
argument_list|()
argument_list|)
expr_stmt|;
while|while
condition|(
name|i
operator|<
name|seq
operator|->
name|size
argument_list|()
operator|-
literal|1
condition|)
block|{
name|TIntermTyped
modifier|*
name|child
init|=
operator|(
operator|*
name|seq
operator|)
index|[
name|i
index|]
operator|->
name|getAsTyped
argument_list|()
decl_stmt|;
name|insertions
operator|.
name|push_back
argument_list|(
name|child
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
name|insertStatementsInParentBlock
argument_list|(
name|insertions
argument_list|)
expr_stmt|;
name|NodeUpdateEntry
name|replaceVariable
argument_list|(
name|getParentNode
argument_list|()
argument_list|,
name|node
argument_list|,
operator|(
operator|*
name|seq
operator|)
index|[
name|i
index|]
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|mReplacements
operator|.
name|push_back
argument_list|(
name|replaceVariable
argument_list|)
expr_stmt|;
block|}
block|}
block|}
return|return
literal|true
return|;
block|}
DECL|function|visitLoop
name|bool
name|UnfoldShortCircuitTraverser
operator|::
name|visitLoop
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermLoop
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|visit
operator|==
name|PreVisit
condition|)
block|{
if|if
condition|(
name|mFoundShortCircuit
condition|)
return|return
literal|false
return|;
comment|// No need to traverse further
name|mLoopParent
operator|=
name|getParentNode
argument_list|()
expr_stmt|;
name|mParentLoop
operator|=
name|node
expr_stmt|;
name|incrementDepth
argument_list|(
name|node
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|getInit
argument_list|()
condition|)
block|{
name|node
operator|->
name|getInit
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|mFoundShortCircuit
condition|)
block|{
name|decrementDepth
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
if|if
condition|(
name|node
operator|->
name|getCondition
argument_list|()
condition|)
block|{
name|mInLoopCondition
operator|=
literal|true
expr_stmt|;
name|node
operator|->
name|getCondition
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|mInLoopCondition
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|mFoundShortCircuit
condition|)
block|{
name|decrementDepth
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
if|if
condition|(
name|node
operator|->
name|getExpression
argument_list|()
condition|)
block|{
name|mInLoopExpression
operator|=
literal|true
expr_stmt|;
name|node
operator|->
name|getExpression
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|mInLoopExpression
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|mFoundShortCircuit
condition|)
block|{
name|decrementDepth
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
if|if
condition|(
name|node
operator|->
name|getBody
argument_list|()
condition|)
name|node
operator|->
name|getBody
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|decrementDepth
argument_list|()
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|copyLoopConditionOrExpression
name|bool
name|UnfoldShortCircuitTraverser
operator|::
name|copyLoopConditionOrExpression
parameter_list|(
name|TIntermNode
modifier|*
name|parent
parameter_list|,
name|TIntermTyped
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|mInLoopCondition
condition|)
block|{
name|mReplacements
operator|.
name|push_back
argument_list|(
name|NodeUpdateEntry
argument_list|(
name|parent
argument_list|,
name|node
argument_list|,
name|createTempSymbol
argument_list|(
name|node
operator|->
name|getType
argument_list|()
argument_list|)
argument_list|,
literal|false
argument_list|)
argument_list|)
expr_stmt|;
name|TIntermAggregate
modifier|*
name|body
init|=
name|mParentLoop
operator|->
name|getBody
argument_list|()
decl_stmt|;
name|TIntermSequence
name|empty
decl_stmt|;
if|if
condition|(
name|mParentLoop
operator|->
name|getType
argument_list|()
operator|==
name|ELoopDoWhile
condition|)
block|{
comment|// Declare the temporary variable before the loop.
name|TIntermSequence
name|insertionsBeforeLoop
decl_stmt|;
name|insertionsBeforeLoop
operator|.
name|push_back
argument_list|(
name|createTempDeclaration
argument_list|(
name|node
operator|->
name|getType
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|insertStatementsInParentBlock
argument_list|(
name|insertionsBeforeLoop
argument_list|)
expr_stmt|;
comment|// Move a part of do-while loop condition to inside the loop.
name|TIntermSequence
name|insertionsInLoop
decl_stmt|;
name|insertionsInLoop
operator|.
name|push_back
argument_list|(
name|createTempAssignment
argument_list|(
name|node
argument_list|)
argument_list|)
expr_stmt|;
name|mInsertions
operator|.
name|push_back
argument_list|(
name|NodeInsertMultipleEntry
argument_list|(
name|body
argument_list|,
name|body
operator|->
name|getSequence
argument_list|()
operator|->
name|size
argument_list|()
operator|-
literal|1
argument_list|,
name|empty
argument_list|,
name|insertionsInLoop
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// The loop initializer expression and one copy of the part of the loop condition are
comment|// executed before the loop. They need to be in a new scope.
name|TIntermAggregate
modifier|*
name|loopScope
init|=
operator|new
name|TIntermAggregate
argument_list|(
name|EOpSequence
argument_list|)
decl_stmt|;
name|TIntermNode
modifier|*
name|initializer
init|=
name|mParentLoop
operator|->
name|getInit
argument_list|()
decl_stmt|;
if|if
condition|(
name|initializer
operator|!=
literal|nullptr
condition|)
block|{
comment|// Move the initializer to the newly created outer scope, so that condition can
comment|// depend on it.
name|mReplacements
operator|.
name|push_back
argument_list|(
name|NodeUpdateEntry
argument_list|(
name|mParentLoop
argument_list|,
name|initializer
argument_list|,
literal|nullptr
argument_list|,
literal|false
argument_list|)
argument_list|)
expr_stmt|;
name|loopScope
operator|->
name|getSequence
argument_list|()
operator|->
name|push_back
argument_list|(
name|initializer
argument_list|)
expr_stmt|;
block|}
name|loopScope
operator|->
name|getSequence
argument_list|()
operator|->
name|push_back
argument_list|(
name|createTempInitDeclaration
argument_list|(
name|node
argument_list|)
argument_list|)
expr_stmt|;
name|loopScope
operator|->
name|getSequence
argument_list|()
operator|->
name|push_back
argument_list|(
name|mParentLoop
argument_list|)
expr_stmt|;
name|mReplacements
operator|.
name|push_back
argument_list|(
name|NodeUpdateEntry
argument_list|(
name|mLoopParent
argument_list|,
name|mParentLoop
argument_list|,
name|loopScope
argument_list|,
literal|true
argument_list|)
argument_list|)
expr_stmt|;
comment|// The second copy of the part of the loop condition is executed inside the loop.
name|TIntermSequence
name|insertionsInLoop
decl_stmt|;
name|insertionsInLoop
operator|.
name|push_back
argument_list|(
name|createTempAssignment
argument_list|(
name|node
operator|->
name|deepCopy
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|mInsertions
operator|.
name|push_back
argument_list|(
name|NodeInsertMultipleEntry
argument_list|(
name|body
argument_list|,
name|body
operator|->
name|getSequence
argument_list|()
operator|->
name|size
argument_list|()
operator|-
literal|1
argument_list|,
name|empty
argument_list|,
name|insertionsInLoop
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
if|if
condition|(
name|mInLoopExpression
condition|)
block|{
name|TIntermTyped
modifier|*
name|movedExpression
init|=
name|mParentLoop
operator|->
name|getExpression
argument_list|()
decl_stmt|;
name|mReplacements
operator|.
name|push_back
argument_list|(
name|NodeUpdateEntry
argument_list|(
name|mParentLoop
argument_list|,
name|movedExpression
argument_list|,
literal|nullptr
argument_list|,
literal|false
argument_list|)
argument_list|)
expr_stmt|;
name|TIntermAggregate
modifier|*
name|body
init|=
name|mParentLoop
operator|->
name|getBody
argument_list|()
decl_stmt|;
name|TIntermSequence
name|empty
decl_stmt|;
name|TIntermSequence
name|insertions
decl_stmt|;
name|insertions
operator|.
name|push_back
argument_list|(
name|movedExpression
argument_list|)
expr_stmt|;
name|mInsertions
operator|.
name|push_back
argument_list|(
name|NodeInsertMultipleEntry
argument_list|(
name|body
argument_list|,
name|body
operator|->
name|getSequence
argument_list|()
operator|->
name|size
argument_list|()
operator|-
literal|1
argument_list|,
name|empty
argument_list|,
name|insertions
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|nextIteration
name|void
name|UnfoldShortCircuitTraverser
operator|::
name|nextIteration
parameter_list|()
block|{
name|mFoundShortCircuit
operator|=
literal|false
expr_stmt|;
name|nextTemporaryIndex
argument_list|()
expr_stmt|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace
end_comment
begin_function
DECL|function|UnfoldShortCircuitToIf
name|void
name|UnfoldShortCircuitToIf
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|,
name|unsigned
name|int
modifier|*
name|temporaryIndex
parameter_list|)
block|{
name|UnfoldShortCircuitTraverser
name|traverser
decl_stmt|;
name|ASSERT
argument_list|(
name|temporaryIndex
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
name|traverser
operator|.
name|useTemporaryIndex
argument_list|(
name|temporaryIndex
argument_list|)
expr_stmt|;
comment|// Unfold one operator at a time, and reset the traverser between iterations.
do|do
block|{
name|traverser
operator|.
name|nextIteration
argument_list|()
expr_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|traverser
argument_list|)
expr_stmt|;
if|if
condition|(
name|traverser
operator|.
name|foundShortCircuit
argument_list|()
condition|)
name|traverser
operator|.
name|updateTree
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
name|traverser
operator|.
name|foundShortCircuit
argument_list|()
condition|)
do|;
block|}
end_function
end_unit
