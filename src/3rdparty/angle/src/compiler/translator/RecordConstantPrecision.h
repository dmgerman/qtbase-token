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
comment|// During parsing, all constant expressions are folded to constant union nodes. The expressions that have been
end_comment
begin_comment
comment|// folded may have had precision qualifiers, which should affect the precision of the consuming operation.
end_comment
begin_comment
comment|// If the folded constant union nodes are written to output as such they won't have any precision qualifiers,
end_comment
begin_comment
comment|// and their effect on the precision of the consuming operation is lost.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// RecordConstantPrecision is an AST traverser that inspects the precision qualifiers of constants and hoists
end_comment
begin_comment
comment|// the constants outside the containing expression as precision qualified named variables in case that is
end_comment
begin_comment
comment|// required for correct precision propagation.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_RECORDCONSTANTPRECISION_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_RECORDCONSTANTPRECISION_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_RECORDCONSTANTPRECISION_H_
end_define
begin_decl_stmt
DECL|variable|TIntermNode
name|class
name|TIntermNode
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|RecordConstantPrecision
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
comment|// COMPILER_TRANSLATOR_RECORDCONSTANTPRECISION_H_
end_comment
end_unit
