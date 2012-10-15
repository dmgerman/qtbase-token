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
name|COMPILER_RENAME_FUNCTION
end_ifndef
begin_define
DECL|macro|COMPILER_RENAME_FUNCTION
define|#
directive|define
name|COMPILER_RENAME_FUNCTION
end_define
begin_include
include|#
directive|include
file|"compiler/intermediate.h"
end_include
begin_comment
comment|//
end_comment
begin_comment
comment|// Renames a function, including its declaration and any calls to it.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|RenameFunction
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|RenameFunction
argument_list|(
specifier|const
name|TString
operator|&
name|oldFunctionName
argument_list|,
specifier|const
name|TString
operator|&
name|newFunctionName
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
block|,
name|mOldFunctionName
argument_list|(
name|oldFunctionName
argument_list|)
block|,
name|mNewFunctionName
argument_list|(
argument|newFunctionName
argument_list|)
block|{}
name|virtual
name|bool
name|visitAggregate
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermAggregate* node
argument_list|)
block|{
name|TOperator
name|op
operator|=
name|node
operator|->
name|getOp
argument_list|()
block|;
if|if
condition|(
operator|(
name|op
operator|==
name|EOpFunction
operator|||
name|op
operator|==
name|EOpFunctionCall
operator|)
operator|&&
name|node
operator|->
name|getName
argument_list|()
operator|==
name|mOldFunctionName
condition|)
name|node
operator|->
name|setName
argument_list|(
name|mNewFunctionName
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
specifier|const
name|TString
name|mOldFunctionName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|TString
name|mNewFunctionName
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_RENAME_FUNCTION
end_comment
end_unit
