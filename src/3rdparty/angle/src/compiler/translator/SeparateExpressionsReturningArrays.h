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
comment|// SeparateExpressionsReturningArrays splits array-returning expressions that are not array names from more complex
end_comment
begin_comment
comment|// expressions, assigning them to a temporary variable a#.
end_comment
begin_comment
comment|// Examples where a, b and c are all arrays:
end_comment
begin_comment
comment|// (a = b) == (a = c) is split into a = b; type[n] a1 = a; a = c; type[n] a2 = a; a1 == a2;
end_comment
begin_comment
comment|// type d = type[n](...)[i]; is split into type[n] a1 = type[n](...); type d = a1[i];
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_SEPARATEEXPRESSIONSRETURNINGARRAYS_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_SEPARATEEXPRESSIONSRETURNINGARRAYS_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_SEPARATEEXPRESSIONSRETURNINGARRAYS_H_
end_define
begin_decl_stmt
DECL|variable|TIntermNode
name|class
name|TIntermNode
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|SeparateExpressionsReturningArrays
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
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_SEPARATEEXPRESSIONSRETURNINGARRAYS_H_
end_comment
end_unit
