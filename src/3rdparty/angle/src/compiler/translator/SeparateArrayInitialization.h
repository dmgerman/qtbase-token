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
comment|// The SeparateArrayInitialization function splits each array initialization into a declaration and an assignment.
end_comment
begin_comment
comment|// Example:
end_comment
begin_comment
comment|//     type[n] a = initializer;
end_comment
begin_comment
comment|// will effectively become
end_comment
begin_comment
comment|//     type[n] a;
end_comment
begin_comment
comment|//     a = initializer;
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Note that if the array is declared as const, the initialization may still be split, making the
end_comment
begin_comment
comment|// AST technically invalid. Because of that this transformation should only be used when subsequent
end_comment
begin_comment
comment|// stages don't care about const qualifiers. However, the initialization will not be split if the
end_comment
begin_comment
comment|// initializer can be written as a HLSL literal.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_SEPARATEARRAYINITIALIZATION_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_SEPARATEARRAYINITIALIZATION_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_SEPARATEARRAYINITIALIZATION_H_
end_define
begin_decl_stmt
DECL|variable|TIntermNode
name|class
name|TIntermNode
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|SeparateArrayInitialization
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_SEPARATEARRAYINITIALIZATION_H_
end_comment
end_unit
