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
file|"GLSLANG/ShaderLang.h"
end_include
begin_include
include|#
directive|include
file|"compiler/intermediate.h"
end_include
begin_comment
comment|// Provides information about a variable.
end_comment
begin_comment
comment|// It is currently being used to store info about active attribs and uniforms.
end_comment
begin_struct
DECL|struct|TVariableInfo
struct|struct
name|TVariableInfo
block|{
name|TVariableInfo
argument_list|(
argument|ShDataType type
argument_list|,
argument|int size
argument_list|)
empty_stmt|;
name|TVariableInfo
argument_list|()
expr_stmt|;
DECL|member|name
name|TPersistString
name|name
decl_stmt|;
DECL|member|mappedName
name|TPersistString
name|mappedName
decl_stmt|;
DECL|member|type
name|ShDataType
name|type
decl_stmt|;
DECL|member|size
name|int
name|size
decl_stmt|;
DECL|member|precision
name|TPrecision
name|precision
decl_stmt|;
DECL|member|staticUse
name|bool
name|staticUse
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|TVariableInfoList
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|TVariableInfo
operator|>
name|TVariableInfoList
expr_stmt|;
end_typedef
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
argument|TVariableInfoList& attribs
argument_list|,
argument|TVariableInfoList& uniforms
argument_list|,
argument|TVariableInfoList& varyings
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
argument_list|)
block|;
name|private
operator|:
name|TVariableInfoList
operator|&
name|mAttribs
block|;
name|TVariableInfoList
operator|&
name|mUniforms
block|;
name|TVariableInfoList
operator|&
name|mVaryings
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_VARIABLE_INFO_H_
end_comment
end_unit
