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
comment|// The SeparateDeclarations function processes declarations, so that in the end each declaration
end_comment
begin_comment
comment|// contains only one declarator.
end_comment
begin_comment
comment|// This is useful as an intermediate step when initialization needs to be separated from declaration,
end_comment
begin_comment
comment|// or when things need to be unfolded out of the initializer.
end_comment
begin_comment
comment|// Example:
end_comment
begin_comment
comment|//     int a[1] = int[1](1), b[1] = int[1](2);
end_comment
begin_comment
comment|// gets transformed when run through this class into the AST equivalent of:
end_comment
begin_comment
comment|//     int a[1] = int[1](1);
end_comment
begin_comment
comment|//     int b[1] = int[1](2);
end_comment
begin_include
include|#
directive|include
file|"compiler/translator/SeparateDeclarations.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_namespace
namespace|namespace
block|{
DECL|class|SeparateDeclarationsTraverser
class|class
name|SeparateDeclarationsTraverser
super|:
specifier|private
name|TIntermTraverser
block|{
public|public:
specifier|static
name|void
name|apply
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
function_decl|;
private|private:
name|SeparateDeclarationsTraverser
parameter_list|()
constructor_decl|;
DECL|member|override
name|bool
name|visitAggregate
parameter_list|(
name|Visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
specifier|override
function_decl|;
block|}
class|;
DECL|function|apply
name|void
name|SeparateDeclarationsTraverser
operator|::
name|apply
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|SeparateDeclarationsTraverser
name|separateDecl
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|separateDecl
argument_list|)
expr_stmt|;
name|separateDecl
operator|.
name|updateTree
argument_list|()
expr_stmt|;
block|}
DECL|function|SeparateDeclarationsTraverser
name|SeparateDeclarationsTraverser
operator|::
name|SeparateDeclarationsTraverser
parameter_list|()
member_init_list|:
name|TIntermTraverser
argument_list|(
literal|true
argument_list|,
literal|false
argument_list|,
literal|false
argument_list|)
block|{ }
DECL|function|visitAggregate
name|bool
name|SeparateDeclarationsTraverser
operator|::
name|visitAggregate
parameter_list|(
name|Visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpDeclaration
condition|)
block|{
name|TIntermSequence
modifier|*
name|sequence
init|=
name|node
operator|->
name|getSequence
argument_list|()
decl_stmt|;
if|if
condition|(
name|sequence
operator|->
name|size
argument_list|()
operator|>
literal|1
condition|)
block|{
name|TIntermAggregate
modifier|*
name|parentAgg
init|=
name|getParentNode
argument_list|()
operator|->
name|getAsAggregate
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|parentAgg
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
name|TIntermSequence
name|replacementDeclarations
decl_stmt|;
for|for
control|(
name|size_t
name|ii
init|=
literal|0
init|;
name|ii
operator|<
name|sequence
operator|->
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
name|TIntermAggregate
modifier|*
name|replacementDeclaration
init|=
operator|new
name|TIntermAggregate
decl_stmt|;
name|replacementDeclaration
operator|->
name|setOp
argument_list|(
name|EOpDeclaration
argument_list|)
expr_stmt|;
name|replacementDeclaration
operator|->
name|getSequence
argument_list|()
operator|->
name|push_back
argument_list|(
name|sequence
operator|->
name|at
argument_list|(
name|ii
argument_list|)
argument_list|)
expr_stmt|;
name|replacementDeclaration
operator|->
name|setLine
argument_list|(
name|sequence
operator|->
name|at
argument_list|(
name|ii
argument_list|)
operator|->
name|getLine
argument_list|()
argument_list|)
expr_stmt|;
name|replacementDeclarations
operator|.
name|push_back
argument_list|(
name|replacementDeclaration
argument_list|)
expr_stmt|;
block|}
name|mMultiReplacements
operator|.
name|push_back
argument_list|(
name|NodeReplaceWithMultipleEntry
argument_list|(
name|parentAgg
argument_list|,
name|node
argument_list|,
name|replacementDeclarations
argument_list|)
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
block|}
end_namespace
begin_comment
comment|// namespace
end_comment
begin_function
DECL|function|SeparateDeclarations
name|void
name|SeparateDeclarations
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|SeparateDeclarationsTraverser
operator|::
name|apply
argument_list|(
name|root
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
