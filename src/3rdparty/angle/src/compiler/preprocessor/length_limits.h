begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2011 The ANGLE Project Authors. All rights reserved.
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
comment|//
end_comment
begin_comment
comment|// length_limits.h
end_comment
begin_comment
comment|//
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__LENGTH_LIMITS_H
argument_list|)
end_if
begin_define
DECL|macro|__LENGTH_LIMITS_H
define|#
directive|define
name|__LENGTH_LIMITS_H
value|1
end_define
begin_comment
comment|// These constants are factored out from the rest of the headers to
end_comment
begin_comment
comment|// make it easier to reference them from the compiler sources.
end_comment
begin_comment
comment|// These lengths do not include the NULL terminator.
end_comment
begin_define
DECL|macro|MAX_SYMBOL_NAME_LEN
define|#
directive|define
name|MAX_SYMBOL_NAME_LEN
value|256
end_define
begin_define
DECL|macro|MAX_STRING_LEN
define|#
directive|define
name|MAX_STRING_LEN
value|511
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !(defined(__LENGTH_LIMITS_H)
end_comment
end_unit
