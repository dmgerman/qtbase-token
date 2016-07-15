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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_FLAGSTD140STRUCTS_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_FLAGSTD140STRUCTS_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_FLAGSTD140STRUCTS_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_decl_stmt
name|namespace
name|sh
block|{
comment|// This class finds references to nested structs of std140 blocks that access
comment|// the nested struct "by value", where the padding added in the translator
comment|// conflicts with the "natural" unpadded type.
name|class
name|FlagStd140Structs
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|FlagStd140Structs
argument_list|()
operator|:
name|TIntermTraverser
argument_list|(
argument|true
argument_list|,
argument|false
argument_list|,
argument|false
argument_list|)
block|{     }
specifier|const
name|std
operator|::
name|vector
operator|<
name|TIntermTyped
operator|*
operator|>
name|getFlaggedNodes
argument_list|()
specifier|const
block|{
return|return
name|mFlaggedNodes
return|;
block|}
name|protected
operator|:
name|bool
name|visitBinary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBinary *binaryNode
argument_list|)
name|override
block|;
name|void
name|visitSymbol
argument_list|(
argument|TIntermSymbol *symbol
argument_list|)
name|override
block|;
name|private
operator|:
name|bool
name|isInStd140InterfaceBlock
argument_list|(
argument|TIntermTyped *node
argument_list|)
specifier|const
block|;
name|std
operator|::
name|vector
operator|<
name|TIntermTyped
operator|*
operator|>
name|mFlaggedNodes
block|; }
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|TIntermTyped
operator|*
operator|>
name|FlagStd140ValueStructs
argument_list|(
name|TIntermNode
operator|*
name|node
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_FLAGSTD140STRUCTS_H_
end_comment
end_unit
