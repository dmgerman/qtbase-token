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
name|DOUBLE_CONVERSION_FAST_DTOA_H_
end_ifndef
begin_define
DECL|macro|DOUBLE_CONVERSION_FAST_DTOA_H_
define|#
directive|define
name|DOUBLE_CONVERSION_FAST_DTOA_H_
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
name|FastDtoaMode
block|{
comment|// Computes the shortest representation of the given input. The returned
comment|// result will be the most accurate number of this length. Longer
comment|// representations might be more accurate.
name|FAST_DTOA_SHORTEST
block|,
comment|// Same as FAST_DTOA_SHORTEST but for single-precision floats.
name|FAST_DTOA_SHORTEST_SINGLE
block|,
comment|// Computes a representation where the precision (number of digits) is
comment|// given as input. The precision is independent of the decimal point.
name|FAST_DTOA_PRECISION
block|}
enum|;
comment|// FastDtoa will produce at most kFastDtoaMaximalLength digits. This does not
comment|// include the terminating '\0' character.
specifier|static
specifier|const
name|int
name|kFastDtoaMaximalLength
init|=
literal|17
decl_stmt|;
comment|// Same for single-precision numbers.
specifier|static
specifier|const
name|int
name|kFastDtoaMaximalSingleLength
init|=
literal|9
decl_stmt|;
comment|// Provides a decimal representation of v.
comment|// The result should be interpreted as buffer * 10^(point - length).
comment|//
comment|// Precondition:
comment|//   * v must be a strictly positive finite double.
comment|//
comment|// Returns true if it succeeds, otherwise the result can not be trusted.
comment|// There will be *length digits inside the buffer followed by a null terminator.
comment|// If the function returns true and mode equals
comment|//   - FAST_DTOA_SHORTEST, then
comment|//     the parameter requested_digits is ignored.
comment|//     The result satisfies
comment|//         v == (double) (buffer * 10^(point - length)).
comment|//     The digits in the buffer are the shortest representation possible. E.g.
comment|//     if 0.099999999999 and 0.1 represent the same double then "1" is returned
comment|//     with point = 0.
comment|//     The last digit will be closest to the actual v. That is, even if several
comment|//     digits might correctly yield 'v' when read again, the buffer will contain
comment|//     the one closest to v.
comment|//   - FAST_DTOA_PRECISION, then
comment|//     the buffer contains requested_digits digits.
comment|//     the difference v - (buffer * 10^(point-length)) is closest to zero for
comment|//     all possible representations of requested_digits digits.
comment|//     If there are two values that are equally close, then FastDtoa returns
comment|//     false.
comment|// For both modes the buffer must be large enough to hold the result.
name|bool
name|FastDtoa
argument_list|(
name|double
name|d
argument_list|,
name|FastDtoaMode
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
comment|// DOUBLE_CONVERSION_FAST_DTOA_H_
end_comment
end_unit
