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
comment|// During parsing, all constant expressions are folded to constant union nodes. The expressions that have been
end_comment
begin_comment
comment|// folded may have had precision qualifiers, which should affect the precision of the consuming operation.
end_comment
begin_comment
comment|// If the folded constant union nodes are written to output as such they won't have any precision qualifiers,
end_comment
begin_comment
comment|// and their effect on the precision of the consuming operation is lost.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// RecordConstantPrecision is an AST traverser that inspects the precision qualifiers of constants and hoists
end_comment
begin_comment
comment|// the constants outside the containing expression as precision qualified named variables in case that is
end_comment
begin_comment
comment|// required for correct precision propagation.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"compiler/translator/RecordConstantPrecision.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/InfoSink.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_namespace
namespace|namespace
block|{
DECL|class|RecordConstantPrecisionTraverser
class|class
name|RecordConstantPrecisionTraverser
super|:
specifier|public
name|TIntermTraverser
block|{
public|public:
name|RecordConstantPrecisionTraverser
parameter_list|()
constructor_decl|;
DECL|member|override
name|void
name|visitConstantUnion
parameter_list|(
name|TIntermConstantUnion
modifier|*
name|node
parameter_list|)
specifier|override
function_decl|;
name|void
name|nextIteration
parameter_list|()
function_decl|;
DECL|function|foundHigherPrecisionConstant
name|bool
name|foundHigherPrecisionConstant
parameter_list|()
specifier|const
block|{
return|return
name|mFoundHigherPrecisionConstant
return|;
block|}
protected|protected:
name|bool
name|operandAffectsParentOperationPrecision
parameter_list|(
name|TIntermTyped
modifier|*
name|operand
parameter_list|)
function_decl|;
DECL|member|mFoundHigherPrecisionConstant
name|bool
name|mFoundHigherPrecisionConstant
decl_stmt|;
block|}
class|;
DECL|function|RecordConstantPrecisionTraverser
name|RecordConstantPrecisionTraverser
operator|::
name|RecordConstantPrecisionTraverser
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
name|mFoundHigherPrecisionConstant
argument_list|(
literal|false
argument_list|)
block|{ }
DECL|function|operandAffectsParentOperationPrecision
name|bool
name|RecordConstantPrecisionTraverser
operator|::
name|operandAffectsParentOperationPrecision
parameter_list|(
name|TIntermTyped
modifier|*
name|operand
parameter_list|)
block|{
specifier|const
name|TIntermBinary
modifier|*
name|parentAsBinary
init|=
name|getParentNode
argument_list|()
operator|->
name|getAsBinaryNode
argument_list|()
decl_stmt|;
if|if
condition|(
name|parentAsBinary
operator|!=
literal|nullptr
condition|)
block|{
comment|// If the constant is assigned or is used to initialize a variable, or if it's an index,
comment|// its precision has no effect.
switch|switch
condition|(
name|parentAsBinary
operator|->
name|getOp
argument_list|()
condition|)
block|{
case|case
name|EOpInitialize
case|:
case|case
name|EOpAssign
case|:
case|case
name|EOpIndexDirect
case|:
case|case
name|EOpIndexDirectStruct
case|:
case|case
name|EOpIndexDirectInterfaceBlock
case|:
case|case
name|EOpIndexIndirect
case|:
return|return
literal|false
return|;
default|default:
break|break;
block|}
name|TIntermTyped
modifier|*
name|otherOperand
init|=
name|parentAsBinary
operator|->
name|getRight
argument_list|()
decl_stmt|;
if|if
condition|(
name|otherOperand
operator|==
name|operand
condition|)
block|{
name|otherOperand
operator|=
name|parentAsBinary
operator|->
name|getLeft
argument_list|()
expr_stmt|;
block|}
comment|// If the precision of the other child is at least as high as the precision of the constant, the precision of
comment|// the constant has no effect.
if|if
condition|(
name|otherOperand
operator|->
name|getAsConstantUnion
argument_list|()
operator|==
literal|nullptr
operator|&&
name|otherOperand
operator|->
name|getPrecision
argument_list|()
operator|>=
name|operand
operator|->
name|getPrecision
argument_list|()
condition|)
block|{
return|return
literal|false
return|;
block|}
block|}
name|TIntermAggregate
modifier|*
name|parentAsAggregate
init|=
name|getParentNode
argument_list|()
operator|->
name|getAsAggregate
argument_list|()
decl_stmt|;
if|if
condition|(
name|parentAsAggregate
operator|!=
literal|nullptr
condition|)
block|{
if|if
condition|(
operator|!
name|parentAsAggregate
operator|->
name|gotPrecisionFromChildren
argument_list|()
condition|)
block|{
comment|// This can be either:
comment|// * a call to an user-defined function
comment|// * a call to a texture function
comment|// * some other kind of aggregate
comment|// In any of these cases the constant precision has no effect.
return|return
literal|false
return|;
block|}
if|if
condition|(
name|parentAsAggregate
operator|->
name|isConstructor
argument_list|()
operator|&&
name|parentAsAggregate
operator|->
name|getBasicType
argument_list|()
operator|==
name|EbtBool
condition|)
block|{
return|return
literal|false
return|;
block|}
comment|// If the precision of operands does affect the result, but the precision of any of the other children
comment|// has a precision that's at least as high as the precision of the constant, the precision of the constant
comment|// has no effect.
name|TIntermSequence
modifier|*
name|parameters
init|=
name|parentAsAggregate
operator|->
name|getSequence
argument_list|()
decl_stmt|;
for|for
control|(
name|TIntermNode
modifier|*
name|parameter
range|:
operator|*
name|parameters
control|)
block|{
specifier|const
name|TIntermTyped
modifier|*
name|typedParameter
init|=
name|parameter
operator|->
name|getAsTyped
argument_list|()
decl_stmt|;
if|if
condition|(
name|parameter
operator|!=
name|operand
operator|&&
name|typedParameter
operator|!=
literal|nullptr
operator|&&
name|parameter
operator|->
name|getAsConstantUnion
argument_list|()
operator|==
literal|nullptr
operator|&&
name|typedParameter
operator|->
name|getPrecision
argument_list|()
operator|>=
name|operand
operator|->
name|getPrecision
argument_list|()
condition|)
block|{
return|return
literal|false
return|;
block|}
block|}
block|}
return|return
literal|true
return|;
block|}
DECL|function|visitConstantUnion
name|void
name|RecordConstantPrecisionTraverser
operator|::
name|visitConstantUnion
parameter_list|(
name|TIntermConstantUnion
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|mFoundHigherPrecisionConstant
condition|)
return|return;
comment|// If the constant has lowp or undefined precision, it can't increase the precision of consuming operations.
if|if
condition|(
name|node
operator|->
name|getPrecision
argument_list|()
operator|<
name|EbpMedium
condition|)
return|return;
comment|// It's possible the node has no effect on the precision of the consuming expression, depending on the
comment|// consuming expression, and the precision of the other parameters of the expression.
if|if
condition|(
operator|!
name|operandAffectsParentOperationPrecision
argument_list|(
name|node
argument_list|)
condition|)
return|return;
comment|// Make the constant a precision-qualified named variable to make sure it affects the precision of the consuming
comment|// expression.
name|TIntermSequence
name|insertions
decl_stmt|;
name|insertions
operator|.
name|push_back
argument_list|(
name|createTempInitDeclaration
argument_list|(
name|node
argument_list|,
name|EvqConst
argument_list|)
argument_list|)
expr_stmt|;
name|insertStatementsInParentBlock
argument_list|(
name|insertions
argument_list|)
expr_stmt|;
name|mReplacements
operator|.
name|push_back
argument_list|(
name|NodeUpdateEntry
argument_list|(
name|getParentNode
argument_list|()
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
name|mFoundHigherPrecisionConstant
operator|=
literal|true
expr_stmt|;
block|}
DECL|function|nextIteration
name|void
name|RecordConstantPrecisionTraverser
operator|::
name|nextIteration
parameter_list|()
block|{
name|nextTemporaryIndex
argument_list|()
expr_stmt|;
name|mFoundHigherPrecisionConstant
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace
end_comment
begin_function
DECL|function|RecordConstantPrecision
name|void
name|RecordConstantPrecision
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
name|RecordConstantPrecisionTraverser
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
comment|// Iterate as necessary, and reset the traverser between iterations.
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
name|foundHigherPrecisionConstant
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
name|foundHigherPrecisionConstant
argument_list|()
condition|)
do|;
block|}
end_function
end_unit
