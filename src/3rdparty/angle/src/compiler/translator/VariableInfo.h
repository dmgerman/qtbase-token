begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2011 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_VARIABLE_INFO_H_
end_ifndef
begin_define
DECL|macro|COMPILER_VARIABLE_INFO_H_
define|#
directive|define
name|COMPILER_VARIABLE_INFO_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/intermediate.h"
end_include
begin_include
include|#
directive|include
file|"common/shadervars.h"
end_include
begin_comment
comment|// Traverses intermediate tree to collect all attributes, uniforms, varyings.
end_comment
begin_decl_stmt
name|class
name|CollectVariables
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|CollectVariables
argument_list|(
argument|std::vector<sh::Attribute> *attribs
argument_list|,
argument|std::vector<sh::Attribute> *outputVariables
argument_list|,
argument|std::vector<sh::Uniform> *uniforms
argument_list|,
argument|std::vector<sh::Varying> *varyings
argument_list|,
argument|std::vector<sh::InterfaceBlock> *interfaceBlocks
argument_list|,
argument|ShHashFunction64 hashFunction
argument_list|)
block|;
name|virtual
name|void
name|visitSymbol
argument_list|(
name|TIntermSymbol
operator|*
name|symbol
argument_list|)
block|;
name|virtual
name|bool
name|visitAggregate
argument_list|(
name|Visit
argument_list|,
name|TIntermAggregate
operator|*
name|node
argument_list|)
block|;
name|private
operator|:
name|template
operator|<
name|typename
name|VarT
operator|>
name|void
name|visitVariable
argument_list|(
argument|const TIntermSymbol *variable
argument_list|,
argument|std::vector<VarT> *infoList
argument_list|)
specifier|const
block|;
name|template
operator|<
name|typename
name|VarT
operator|>
name|void
name|visitInfoList
argument_list|(
argument|const TIntermSequence&sequence
argument_list|,
argument|std::vector<VarT> *infoList
argument_list|)
specifier|const
block|;
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Attribute
operator|>
operator|*
name|mAttribs
block|;
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Attribute
operator|>
operator|*
name|mOutputVariables
block|;
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Uniform
operator|>
operator|*
name|mUniforms
block|;
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Varying
operator|>
operator|*
name|mVaryings
block|;
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|InterfaceBlock
operator|>
operator|*
name|mInterfaceBlocks
block|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
block|,
name|sh
operator|::
name|InterfaceBlockField
operator|*
operator|>
name|mInterfaceBlockFields
block|;
name|bool
name|mPointCoordAdded
block|;
name|bool
name|mFrontFacingAdded
block|;
name|bool
name|mFragCoordAdded
block|;
name|ShHashFunction64
name|mHashFunction
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Expand struct variables to flattened lists of split variables
end_comment
begin_comment
comment|// Implemented for sh::Varying and sh::Uniform.
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|VarT
operator|>
name|void
name|ExpandVariables
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|VarT
operator|>
operator|&
name|compact
argument_list|,
name|std
operator|::
name|vector
operator|<
name|VarT
operator|>
operator|*
name|expanded
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_VARIABLE_INFO_H_
end_comment
end_unit
