begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_TRANSLATOR_SCALARIZE_VEC_AND_MAT_CONSTRUCTOR_ARGS_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_SCALARIZE_VEC_AND_MAT_CONSTRUCTOR_ARGS_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_SCALARIZE_VEC_AND_MAT_CONSTRUCTOR_ARGS_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/intermediate.h"
end_include
begin_decl_stmt
name|class
name|ScalarizeVecAndMatConstructorArgs
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|ScalarizeVecAndMatConstructorArgs
argument_list|()
operator|:
name|mTempVarCount
argument_list|(
literal|0
argument_list|)
block|{}
name|protected
operator|:
name|virtual
name|bool
name|visitAggregate
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermAggregate *node
argument_list|)
block|;
name|private
operator|:
name|void
name|scalarizeArgs
argument_list|(
argument|TIntermAggregate *aggregate
argument_list|,
argument|bool scalarizeVector
argument_list|,
argument|bool scalarizeMatrix
argument_list|)
block|;
comment|// If we have the following code:
comment|//   mat4 m(0);
comment|//   vec4 v(1, m);
comment|// We will rewrite to:
comment|//   mat4 m(0);
comment|//   mat4 _webgl_tmp_mat_0 = m;
comment|//   vec4 v(1, _webgl_tmp_mat_0[0][0], _webgl_tmp_mat_0[0][1], _webgl_tmp_mat_0[0][2]);
comment|// This function is to create nodes for "mat4 _webgl_tmp_mat_0 = m;" and insert it to
comment|// the code sequence.
comment|// Return the temporary variable name.
name|TString
name|createTempVariable
argument_list|(
name|TIntermTyped
operator|*
name|original
argument_list|)
block|;
name|std
operator|::
name|vector
operator|<
name|TIntermSequence
operator|>
name|mSequenceStack
block|;
name|int
name|mTempVarCount
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_SCALARIZE_VEC_AND_MAT_CONSTRUCTOR_ARGS_H_
end_comment
end_unit
