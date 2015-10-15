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
name|DOUBLE_CONVERSION_BIGNUM_DTOA_H_
end_ifndef
begin_define
DECL|macro|DOUBLE_CONVERSION_BIGNUM_DTOA_H_
define|#
directive|define
name|DOUBLE_CONVERSION_BIGNUM_DTOA_H_
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
enum|enum
name|BignumDtoaMode
block|{
comment|// Return the shortest correct representation.
comment|// For example the output of 0.299999999999999988897 is (the less accurate but
comment|// correct) 0.3.
name|BIGNUM_DTOA_SHORTEST
block|,
comment|// Same as BIGNUM_DTOA_SHORTEST but for single-precision floats.
name|BIGNUM_DTOA_SHORTEST_SINGLE
block|,
comment|// Return a fixed number of digits after the decimal point.
comment|// For instance fixed(0.1, 4) becomes 0.1000
comment|// If the input number is big, the output will be big.
name|BIGNUM_DTOA_FIXED
block|,
comment|// Return a fixed number of digits, no matter what the exponent is.
name|BIGNUM_DTOA_PRECISION
block|}
enum|;
comment|// Converts the given double 'v' to ascii.
comment|// The result should be interpreted as buffer * 10^(point-length).
comment|// The buffer will be null-terminated.
comment|//
comment|// The input v must be> 0 and different from NaN, and Infinity.
comment|//
comment|// The output depends on the given mode:
comment|//  - SHORTEST: produce the least amount of digits for which the internal
comment|//   identity requirement is still satisfied. If the digits are printed
comment|//   (together with the correct exponent) then reading this number will give
comment|//   'v' again. The buffer will choose the representation that is closest to
comment|//   'v'. If there are two at the same distance, than the number is round up.
comment|//   In this mode the 'requested_digits' parameter is ignored.
comment|//  - FIXED: produces digits necessary to print a given number with
comment|//   'requested_digits' digits after the decimal point. The produced digits
comment|//   might be too short in which case the caller has to fill the gaps with '0's.
comment|//   Example: toFixed(0.001, 5) is allowed to return buffer="1", point=-2.
comment|//   Halfway cases are rounded up. The call toFixed(0.15, 2) thus returns
comment|//     buffer="2", point=0.
comment|//   Note: the length of the returned buffer has no meaning wrt the significance
comment|//   of its digits. That is, just because it contains '0's does not mean that
comment|//   any other digit would not satisfy the internal identity requirement.
comment|//  - PRECISION: produces 'requested_digits' where the first digit is not '0'.
comment|//   Even though the length of produced digits usually equals
comment|//   'requested_digits', the function is allowed to return fewer digits, in
comment|//   which case the caller has to fill the missing digits with '0's.
comment|//   Halfway cases are again rounded up.
comment|// 'BignumDtoa' expects the given buffer to be big enough to hold all digits
comment|// and a terminating null-character.
name|void
name|BignumDtoa
argument_list|(
name|double
name|v
argument_list|,
name|BignumDtoaMode
name|mode
argument_list|,
name|int
name|requested_digits
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
name|point
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
comment|// DOUBLE_CONVERSION_BIGNUM_DTOA_H_
end_comment
end_unit
