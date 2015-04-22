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
begin_include
include|#
directive|include
file|"compiler/translator/UnfoldShortCircuitAST.h"
end_include
begin_namespace
namespace|namespace
block|{
comment|// "x || y" is equivalent to "x ? true : y".
DECL|function|UnfoldOR
name|TIntermSelection
modifier|*
name|UnfoldOR
parameter_list|(
name|TIntermTyped
modifier|*
name|x
parameter_list|,
name|TIntermTyped
modifier|*
name|y
parameter_list|)
block|{
specifier|const
name|TType
name|boolType
argument_list|(
name|EbtBool
argument_list|,
name|EbpUndefined
argument_list|)
decl_stmt|;
name|ConstantUnion
modifier|*
name|u
init|=
operator|new
name|ConstantUnion
decl_stmt|;
name|u
operator|->
name|setBConst
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|TIntermConstantUnion
modifier|*
name|trueNode
init|=
operator|new
name|TIntermConstantUnion
argument_list|(
name|u
argument_list|,
name|TType
argument_list|(
name|EbtBool
argument_list|,
name|EbpUndefined
argument_list|,
name|EvqConst
argument_list|,
literal|1
argument_list|)
argument_list|)
decl_stmt|;
return|return
operator|new
name|TIntermSelection
argument_list|(
name|x
argument_list|,
name|trueNode
argument_list|,
name|y
argument_list|,
name|boolType
argument_list|)
return|;
block|}
comment|// "x&& y" is equivalent to "x ? y : false".
DECL|function|UnfoldAND
name|TIntermSelection
modifier|*
name|UnfoldAND
parameter_list|(
name|TIntermTyped
modifier|*
name|x
parameter_list|,
name|TIntermTyped
modifier|*
name|y
parameter_list|)
block|{
specifier|const
name|TType
name|boolType
argument_list|(
name|EbtBool
argument_list|,
name|EbpUndefined
argument_list|)
decl_stmt|;
name|ConstantUnion
modifier|*
name|u
init|=
operator|new
name|ConstantUnion
decl_stmt|;
name|u
operator|->
name|setBConst
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|TIntermConstantUnion
modifier|*
name|falseNode
init|=
operator|new
name|TIntermConstantUnion
argument_list|(
name|u
argument_list|,
name|TType
argument_list|(
name|EbtBool
argument_list|,
name|EbpUndefined
argument_list|,
name|EvqConst
argument_list|,
literal|1
argument_list|)
argument_list|)
decl_stmt|;
return|return
operator|new
name|TIntermSelection
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|falseNode
argument_list|,
name|boolType
argument_list|)
return|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace anonymous
end_comment
begin_function
DECL|function|visitBinary
name|bool
name|UnfoldShortCircuitAST
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
name|TIntermSelection
modifier|*
name|replacement
init|=
name|NULL
decl_stmt|;
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
name|replacement
operator|=
name|UnfoldOR
argument_list|(
name|node
operator|->
name|getLeft
argument_list|()
argument_list|,
name|node
operator|->
name|getRight
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|EOpLogicalAnd
case|:
name|replacement
operator|=
name|UnfoldAND
argument_list|(
name|node
operator|->
name|getLeft
argument_list|()
argument_list|,
name|node
operator|->
name|getRight
argument_list|()
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
name|replacement
condition|)
block|{
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
name|replacement
argument_list|,
literal|false
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
end_unit
