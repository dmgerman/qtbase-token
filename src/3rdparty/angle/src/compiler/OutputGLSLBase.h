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
name|CROSSCOMPILERGLSL_OUTPUTGLSLBASE_H_
end_ifndef
begin_define
DECL|macro|CROSSCOMPILERGLSL_OUTPUTGLSLBASE_H_
define|#
directive|define
name|CROSSCOMPILERGLSL_OUTPUTGLSLBASE_H_
end_define
begin_include
include|#
directive|include
file|<set>
end_include
begin_include
include|#
directive|include
file|"compiler/ForLoopUnroll.h"
end_include
begin_include
include|#
directive|include
file|"compiler/intermediate.h"
end_include
begin_include
include|#
directive|include
file|"compiler/ParseHelper.h"
end_include
begin_decl_stmt
name|class
name|TOutputGLSLBase
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|TOutputGLSLBase
argument_list|(
argument|TInfoSinkBase& objSink
argument_list|,
argument|ShArrayIndexClampingStrategy clampingStrategy
argument_list|,
argument|ShHashFunction64 hashFunction
argument_list|,
argument|NameMap& nameMap
argument_list|,
argument|TSymbolTable& symbolTable
argument_list|)
block|;
name|protected
operator|:
name|TInfoSinkBase
operator|&
name|objSink
argument_list|()
block|{
return|return
name|mObjSink
return|;
block|}
name|void
name|writeTriplet
argument_list|(
argument|Visit visit
argument_list|,
argument|const char* preStr
argument_list|,
argument|const char* inStr
argument_list|,
argument|const char* postStr
argument_list|)
block|;
name|void
name|writeVariableType
argument_list|(
specifier|const
name|TType
operator|&
name|type
argument_list|)
block|;
name|virtual
name|bool
name|writeVariablePrecision
argument_list|(
argument|TPrecision precision
argument_list|)
operator|=
literal|0
block|;
name|void
name|writeFunctionParameters
argument_list|(
specifier|const
name|TIntermSequence
operator|&
name|args
argument_list|)
block|;
specifier|const
name|ConstantUnion
operator|*
name|writeConstantUnion
argument_list|(
specifier|const
name|TType
operator|&
name|type
argument_list|,
specifier|const
name|ConstantUnion
operator|*
name|pConstUnion
argument_list|)
block|;
name|TString
name|getTypeName
argument_list|(
specifier|const
name|TType
operator|&
name|type
argument_list|)
block|;
name|virtual
name|void
name|visitSymbol
argument_list|(
name|TIntermSymbol
operator|*
name|node
argument_list|)
block|;
name|virtual
name|void
name|visitConstantUnion
argument_list|(
name|TIntermConstantUnion
operator|*
name|node
argument_list|)
block|;
name|virtual
name|bool
name|visitBinary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBinary* node
argument_list|)
block|;
name|virtual
name|bool
name|visitUnary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermUnary* node
argument_list|)
block|;
name|virtual
name|bool
name|visitSelection
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermSelection* node
argument_list|)
block|;
name|virtual
name|bool
name|visitAggregate
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermAggregate* node
argument_list|)
block|;
name|virtual
name|bool
name|visitLoop
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermLoop* node
argument_list|)
block|;
name|virtual
name|bool
name|visitBranch
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBranch* node
argument_list|)
block|;
name|void
name|visitCodeBlock
argument_list|(
name|TIntermNode
operator|*
name|node
argument_list|)
block|;
comment|// Return the original name if hash function pointer is NULL;
comment|// otherwise return the hashed name.
name|TString
name|hashName
argument_list|(
specifier|const
name|TString
operator|&
name|name
argument_list|)
block|;
comment|// Same as hashName(), but without hashing built-in variables.
name|TString
name|hashVariableName
argument_list|(
specifier|const
name|TString
operator|&
name|name
argument_list|)
block|;
comment|// Same as hashName(), but without hashing built-in functions.
name|TString
name|hashFunctionName
argument_list|(
specifier|const
name|TString
operator|&
name|mangled_name
argument_list|)
block|;
name|private
operator|:
name|TInfoSinkBase
operator|&
name|mObjSink
block|;
name|bool
name|mDeclaringVariables
block|;
comment|// Structs are declared as the tree is traversed. This set contains all
comment|// the structs already declared. It is maintained so that a struct is
comment|// declared only once.
typedef|typedef
name|std
operator|::
name|set
operator|<
name|TString
operator|>
name|DeclaredStructs
expr_stmt|;
name|DeclaredStructs
name|mDeclaredStructs
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ForLoopUnroll
name|mLoopUnroll
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ShArrayIndexClampingStrategy
name|mClampingStrategy
decl_stmt|;
end_decl_stmt
begin_comment
comment|// name hashing.
end_comment
begin_decl_stmt
name|ShHashFunction64
name|mHashFunction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|NameMap
modifier|&
name|mNameMap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TSymbolTable
modifier|&
name|mSymbolTable
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// CROSSCOMPILERGLSL_OUTPUTGLSLBASE_H_
end_comment
end_unit
