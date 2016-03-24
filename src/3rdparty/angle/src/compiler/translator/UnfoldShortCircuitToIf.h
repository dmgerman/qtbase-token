begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
comment|// UnfoldShortCircuitToIf is an AST traverser to convert short-circuiting operators to if-else statements.
end_comment
begin_comment
comment|// The results are assigned to s# temporaries, which are used by the main translator instead of
end_comment
begin_comment
comment|// the original expression.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_UNFOLDSHORTCIRCUIT_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_UNFOLDSHORTCIRCUIT_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_UNFOLDSHORTCIRCUIT_H_
end_define
begin_decl_stmt
DECL|variable|TIntermNode
name|class
name|TIntermNode
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|UnfoldShortCircuitToIf
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
comment|// COMPILER_TRANSLATOR_UNFOLDSHORTCIRCUIT_H_
end_comment
end_unit
