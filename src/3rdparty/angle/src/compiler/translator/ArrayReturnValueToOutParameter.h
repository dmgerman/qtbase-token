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
comment|// The ArrayReturnValueToOutParameter function changes return values of an array type to out parameters in
end_comment
begin_comment
comment|// function definitions, prototypes and call sites.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_ARRAYRETURNVALUETOOUTPARAMETER_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_ARRAYRETURNVALUETOOUTPARAMETER_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_ARRAYRETURNVALUETOOUTPARAMETER_H_
end_define
begin_decl_stmt
DECL|variable|TIntermNode
name|class
name|TIntermNode
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|ArrayReturnValueToOutParameter
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
comment|// COMPILER_TRANSLATOR_ARRAYRETURNVALUETOOUTPARAMETER_H_
end_comment
end_unit
