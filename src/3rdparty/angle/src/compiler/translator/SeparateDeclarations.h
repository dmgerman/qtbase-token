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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_SEPARATEDECLARATIONS_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_SEPARATEDECLARATIONS_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_SEPARATEDECLARATIONS_H_
end_define
begin_decl_stmt
DECL|variable|TIntermNode
name|class
name|TIntermNode
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|SeparateDeclarations
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
comment|// COMPILER_TRANSLATOR_SEPARATEDECLARATIONS_H_
end_comment
end_unit
