begin_unit
begin_comment
comment|// Copyright 2010 the V8 project authors. All rights reserved.
end_comment
begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment
begin_comment
comment|// modification, are permitted provided that the following conditions are
end_comment
begin_comment
comment|// met:
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//     * Redistributions of source code must retain the above copyright
end_comment
begin_comment
comment|//       notice, this list of conditions and the following disclaimer.
end_comment
begin_comment
comment|//     * Redistributions in binary form must reproduce the above
end_comment
begin_comment
comment|//       copyright notice, this list of conditions and the following
end_comment
begin_comment
comment|//       disclaimer in the documentation and/or other materials provided
end_comment
begin_comment
comment|//       with the distribution.
end_comment
begin_comment
comment|//     * Neither the name of Google Inc. nor the names of its
end_comment
begin_comment
comment|//       contributors may be used to endorse or promote products derived
end_comment
begin_comment
comment|//       from this software without specific prior written permission.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
end_comment
begin_comment
comment|// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
end_comment
begin_comment
comment|// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
end_comment
begin_comment
comment|// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
end_comment
begin_comment
comment|// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
end_comment
begin_comment
comment|// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
end_comment
begin_comment
comment|// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
end_comment
begin_comment
comment|// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
end_comment
begin_comment
comment|// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
end_comment
begin_comment
comment|// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
end_comment
begin_comment
comment|// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DOUBLE_CONVERSION_FIXED_DTOA_H_
end_ifndef
begin_define
DECL|macro|DOUBLE_CONVERSION_FIXED_DTOA_H_
define|#
directive|define
name|DOUBLE_CONVERSION_FIXED_DTOA_H_
end_define
begin_include
include|#
directive|include
file|"utils.h"
end_include
begin_decl_stmt
name|namespace
name|double_conversion
block|{
comment|// Produces digits necessary to print a given number with
comment|// 'fractional_count' digits after the decimal point.
comment|// The buffer must be big enough to hold the result plus one terminating null
comment|// character.
comment|//
comment|// The produced digits might be too short in which case the caller has to fill
comment|// the gaps with '0's.
comment|// Example: FastFixedDtoa(0.001, 5, ...) is allowed to return buffer = "1", and
comment|// decimal_point = -2.
comment|// Halfway cases are rounded towards +/-Infinity (away from 0). The call
comment|// FastFixedDtoa(0.15, 2, ...) thus returns buffer = "2", decimal_point = 0.
comment|// The returned buffer may contain digits that would be truncated from the
comment|// shortest representation of the input.
comment|//
comment|// This method only works for some parameters. If it can't handle the input it
comment|// returns false. The output is null-terminated when the function succeeds.
name|bool
name|FastFixedDtoa
argument_list|(
name|double
name|v
argument_list|,
name|int
name|fractional_count
argument_list|,
name|Vector
operator|<
name|char
operator|>
name|buffer
argument_list|,
name|int
operator|*
name|length
argument_list|,
name|int
operator|*
name|decimal_point
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace double_conversion
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// DOUBLE_CONVERSION_FIXED_DTOA_H_
end_comment
end_unit
