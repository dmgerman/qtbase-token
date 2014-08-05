begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013 The ANGLE Project Authors. All rights reserved.
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
file|"compiler/translator/FlagStd140Structs.h"
end_include
begin_namespace
DECL|namespace|sh
namespace|namespace
name|sh
block|{
DECL|function|visitBinary
name|bool
name|FlagStd140Structs
operator|::
name|visitBinary
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermBinary
modifier|*
name|binaryNode
parameter_list|)
block|{
if|if
condition|(
name|binaryNode
operator|->
name|getRight
argument_list|()
operator|->
name|getBasicType
argument_list|()
operator|==
name|EbtStruct
condition|)
block|{
switch|switch
condition|(
name|binaryNode
operator|->
name|getOp
argument_list|()
condition|)
block|{
case|case
name|EOpIndexDirectInterfaceBlock
case|:
case|case
name|EOpIndexDirectStruct
case|:
if|if
condition|(
name|isInStd140InterfaceBlock
argument_list|(
name|binaryNode
operator|->
name|getLeft
argument_list|()
argument_list|)
condition|)
block|{
name|mFlaggedNodes
operator|.
name|push_back
argument_list|(
name|binaryNode
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
return|return
literal|false
return|;
block|}
if|if
condition|(
name|binaryNode
operator|->
name|getOp
argument_list|()
operator|==
name|EOpIndexDirectStruct
condition|)
block|{
return|return
literal|false
return|;
block|}
return|return
name|visit
operator|==
name|PreVisit
return|;
block|}
DECL|function|visitSymbol
name|void
name|FlagStd140Structs
operator|::
name|visitSymbol
parameter_list|(
name|TIntermSymbol
modifier|*
name|symbol
parameter_list|)
block|{
if|if
condition|(
name|isInStd140InterfaceBlock
argument_list|(
name|symbol
argument_list|)
operator|&&
name|symbol
operator|->
name|getBasicType
argument_list|()
operator|==
name|EbtStruct
condition|)
block|{
name|mFlaggedNodes
operator|.
name|push_back
argument_list|(
name|symbol
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|isInStd140InterfaceBlock
name|bool
name|FlagStd140Structs
operator|::
name|isInStd140InterfaceBlock
parameter_list|(
name|TIntermTyped
modifier|*
name|node
parameter_list|)
specifier|const
block|{
name|TIntermBinary
modifier|*
name|binaryNode
init|=
name|node
operator|->
name|getAsBinaryNode
argument_list|()
decl_stmt|;
if|if
condition|(
name|binaryNode
condition|)
block|{
return|return
name|isInStd140InterfaceBlock
argument_list|(
name|binaryNode
operator|->
name|getLeft
argument_list|()
argument_list|)
return|;
block|}
specifier|const
name|TType
modifier|&
name|type
init|=
name|node
operator|->
name|getType
argument_list|()
decl_stmt|;
comment|// determine if we are in the standard layout
specifier|const
name|TInterfaceBlock
modifier|*
name|interfaceBlock
init|=
name|type
operator|.
name|getInterfaceBlock
argument_list|()
decl_stmt|;
if|if
condition|(
name|interfaceBlock
condition|)
block|{
return|return
operator|(
name|interfaceBlock
operator|->
name|blockStorage
argument_list|()
operator|==
name|EbsStd140
operator|)
return|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|FlagStd140ValueStructs
name|std
operator|::
name|vector
argument_list|<
name|TIntermTyped
modifier|*
argument_list|>
name|FlagStd140ValueStructs
parameter_list|(
name|TIntermNode
modifier|*
name|node
parameter_list|)
block|{
name|FlagStd140Structs
name|flaggingTraversal
decl_stmt|;
name|node
operator|->
name|traverse
argument_list|(
operator|&
name|flaggingTraversal
argument_list|)
expr_stmt|;
return|return
name|flaggingTraversal
operator|.
name|getFlaggedNodes
argument_list|()
return|;
block|}
block|}
end_namespace
end_unit
