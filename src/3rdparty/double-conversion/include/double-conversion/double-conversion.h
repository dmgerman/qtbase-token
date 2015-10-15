begin_unit
begin_comment
comment|// Copyright 2012 the V8 project authors. All rights reserved.
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
name|DOUBLE_CONVERSION_DOUBLE_CONVERSION_H_
end_ifndef
begin_define
DECL|macro|DOUBLE_CONVERSION_DOUBLE_CONVERSION_H_
define|#
directive|define
name|DOUBLE_CONVERSION_DOUBLE_CONVERSION_H_
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
name|class
name|DoubleToStringConverter
block|{
name|public
label|:
comment|// When calling ToFixed with a double> 10^kMaxFixedDigitsBeforePoint
comment|// or a requested_digits parameter> kMaxFixedDigitsAfterPoint then the
comment|// function returns false.
specifier|static
specifier|const
name|int
name|kMaxFixedDigitsBeforePoint
init|=
literal|60
decl_stmt|;
specifier|static
specifier|const
name|int
name|kMaxFixedDigitsAfterPoint
init|=
literal|60
decl_stmt|;
comment|// When calling ToExponential with a requested_digits
comment|// parameter> kMaxExponentialDigits then the function returns false.
specifier|static
specifier|const
name|int
name|kMaxExponentialDigits
init|=
literal|120
decl_stmt|;
comment|// When calling ToPrecision with a requested_digits
comment|// parameter< kMinPrecisionDigits or requested_digits> kMaxPrecisionDigits
comment|// then the function returns false.
specifier|static
specifier|const
name|int
name|kMinPrecisionDigits
init|=
literal|1
decl_stmt|;
specifier|static
specifier|const
name|int
name|kMaxPrecisionDigits
init|=
literal|120
decl_stmt|;
enum|enum
name|Flags
block|{
name|NO_FLAGS
init|=
literal|0
block|,
name|EMIT_POSITIVE_EXPONENT_SIGN
init|=
literal|1
block|,
name|EMIT_TRAILING_DECIMAL_POINT
init|=
literal|2
block|,
name|EMIT_TRAILING_ZERO_AFTER_POINT
init|=
literal|4
block|,
name|UNIQUE_ZERO
init|=
literal|8
block|}
enum|;
comment|// Flags should be a bit-or combination of the possible Flags-enum.
comment|//  - NO_FLAGS: no special flags.
comment|//  - EMIT_POSITIVE_EXPONENT_SIGN: when the number is converted into exponent
comment|//    form, emits a '+' for positive exponents. Example: 1.2e+2.
comment|//  - EMIT_TRAILING_DECIMAL_POINT: when the input number is an integer and is
comment|//    converted into decimal format then a trailing decimal point is appended.
comment|//    Example: 2345.0 is converted to "2345.".
comment|//  - EMIT_TRAILING_ZERO_AFTER_POINT: in addition to a trailing decimal point
comment|//    emits a trailing '0'-character. This flag requires the
comment|//    EXMIT_TRAILING_DECIMAL_POINT flag.
comment|//    Example: 2345.0 is converted to "2345.0".
comment|//  - UNIQUE_ZERO: "-0.0" is converted to "0.0".
comment|//
comment|// Infinity symbol and nan_symbol provide the string representation for these
comment|// special values. If the string is NULL and the special value is encountered
comment|// then the conversion functions return false.
comment|//
comment|// The exponent_character is used in exponential representations. It is
comment|// usually 'e' or 'E'.
comment|//
comment|// When converting to the shortest representation the converter will
comment|// represent input numbers in decimal format if they are in the interval
comment|// [10^decimal_in_shortest_low; 10^decimal_in_shortest_high[
comment|//    (lower boundary included, greater boundary excluded).
comment|// Example: with decimal_in_shortest_low = -6 and
comment|//               decimal_in_shortest_high = 21:
comment|//   ToShortest(0.000001)  -> "0.000001"
comment|//   ToShortest(0.0000001) -> "1e-7"
comment|//   ToShortest(111111111111111111111.0)  -> "111111111111111110000"
comment|//   ToShortest(100000000000000000000.0)  -> "100000000000000000000"
comment|//   ToShortest(1111111111111111111111.0) -> "1.1111111111111111e+21"
comment|//
comment|// When converting to precision mode the converter may add
comment|// max_leading_padding_zeroes before returning the number in exponential
comment|// format.
comment|// Example with max_leading_padding_zeroes_in_precision_mode = 6.
comment|//   ToPrecision(0.0000012345, 2) -> "0.0000012"
comment|//   ToPrecision(0.00000012345, 2) -> "1.2e-7"
comment|// Similarily the converter may add up to
comment|// max_trailing_padding_zeroes_in_precision_mode in precision mode to avoid
comment|// returning an exponential representation. A zero added by the
comment|// EMIT_TRAILING_ZERO_AFTER_POINT flag is counted for this limit.
comment|// Examples for max_trailing_padding_zeroes_in_precision_mode = 1:
comment|//   ToPrecision(230.0, 2) -> "230"
comment|//   ToPrecision(230.0, 2) -> "230."  with EMIT_TRAILING_DECIMAL_POINT.
comment|//   ToPrecision(230.0, 2) -> "2.3e2" with EMIT_TRAILING_ZERO_AFTER_POINT.
name|DoubleToStringConverter
argument_list|(
argument|int flags
argument_list|,
argument|const char* infinity_symbol
argument_list|,
argument|const char* nan_symbol
argument_list|,
argument|char exponent_character
argument_list|,
argument|int decimal_in_shortest_low
argument_list|,
argument|int decimal_in_shortest_high
argument_list|,
argument|int max_leading_padding_zeroes_in_precision_mode
argument_list|,
argument|int max_trailing_padding_zeroes_in_precision_mode
argument_list|)
block|:
name|flags_
argument_list|(
name|flags
argument_list|)
operator|,
name|infinity_symbol_
argument_list|(
name|infinity_symbol
argument_list|)
operator|,
name|nan_symbol_
argument_list|(
name|nan_symbol
argument_list|)
operator|,
name|exponent_character_
argument_list|(
name|exponent_character
argument_list|)
operator|,
name|decimal_in_shortest_low_
argument_list|(
name|decimal_in_shortest_low
argument_list|)
operator|,
name|decimal_in_shortest_high_
argument_list|(
name|decimal_in_shortest_high
argument_list|)
operator|,
name|max_leading_padding_zeroes_in_precision_mode_
argument_list|(
name|max_leading_padding_zeroes_in_precision_mode
argument_list|)
operator|,
name|max_trailing_padding_zeroes_in_precision_mode_
argument_list|(
argument|max_trailing_padding_zeroes_in_precision_mode
argument_list|)
block|{
comment|// When 'trailing zero after the point' is set, then 'trailing point'
comment|// must be set too.
name|ASSERT
argument_list|(
operator|(
operator|(
name|flags
operator|&
name|EMIT_TRAILING_DECIMAL_POINT
operator|)
operator|!=
literal|0
operator|)
operator|||
operator|!
operator|(
operator|(
name|flags
operator|&
name|EMIT_TRAILING_ZERO_AFTER_POINT
operator|)
operator|!=
literal|0
operator|)
argument_list|)
block|;   }
comment|// Returns a converter following the EcmaScript specification.
specifier|static
specifier|const
name|DoubleToStringConverter
operator|&
name|EcmaScriptConverter
argument_list|()
expr_stmt|;
comment|// Computes the shortest string of digits that correctly represent the input
comment|// number. Depending on decimal_in_shortest_low and decimal_in_shortest_high
comment|// (see constructor) it then either returns a decimal representation, or an
comment|// exponential representation.
comment|// Example with decimal_in_shortest_low = -6,
comment|//              decimal_in_shortest_high = 21,
comment|//              EMIT_POSITIVE_EXPONENT_SIGN activated, and
comment|//              EMIT_TRAILING_DECIMAL_POINT deactived:
comment|//   ToShortest(0.000001)  -> "0.000001"
comment|//   ToShortest(0.0000001) -> "1e-7"
comment|//   ToShortest(111111111111111111111.0)  -> "111111111111111110000"
comment|//   ToShortest(100000000000000000000.0)  -> "100000000000000000000"
comment|//   ToShortest(1111111111111111111111.0) -> "1.1111111111111111e+21"
comment|//
comment|// Note: the conversion may round the output if the returned string
comment|// is accurate enough to uniquely identify the input-number.
comment|// For example the most precise representation of the double 9e59 equals
comment|// "899999999999999918767229449717619953810131273674690656206848", but
comment|// the converter will return the shorter (but still correct) "9e59".
comment|//
comment|// Returns true if the conversion succeeds. The conversion always succeeds
comment|// except when the input value is special and no infinity_symbol or
comment|// nan_symbol has been given to the constructor.
name|bool
name|ToShortest
argument_list|(
name|double
name|value
argument_list|,
name|StringBuilder
operator|*
name|result_builder
argument_list|)
decl|const
block|{
return|return
name|ToShortestIeeeNumber
argument_list|(
name|value
argument_list|,
name|result_builder
argument_list|,
name|SHORTEST
argument_list|)
return|;
block|}
comment|// Same as ToShortest, but for single-precision floats.
name|bool
name|ToShortestSingle
argument_list|(
name|float
name|value
argument_list|,
name|StringBuilder
operator|*
name|result_builder
argument_list|)
decl|const
block|{
return|return
name|ToShortestIeeeNumber
argument_list|(
name|value
argument_list|,
name|result_builder
argument_list|,
name|SHORTEST_SINGLE
argument_list|)
return|;
block|}
comment|// Computes a decimal representation with a fixed number of digits after the
comment|// decimal point. The last emitted digit is rounded.
comment|//
comment|// Examples:
comment|//   ToFixed(3.12, 1) -> "3.1"
comment|//   ToFixed(3.1415, 3) -> "3.142"
comment|//   ToFixed(1234.56789, 4) -> "1234.5679"
comment|//   ToFixed(1.23, 5) -> "1.23000"
comment|//   ToFixed(0.1, 4) -> "0.1000"
comment|//   ToFixed(1e30, 2) -> "1000000000000000019884624838656.00"
comment|//   ToFixed(0.1, 30) -> "0.100000000000000005551115123126"
comment|//   ToFixed(0.1, 17) -> "0.10000000000000001"
comment|//
comment|// If requested_digits equals 0, then the tail of the result depends on
comment|// the EMIT_TRAILING_DECIMAL_POINT and EMIT_TRAILING_ZERO_AFTER_POINT.
comment|// Examples, for requested_digits == 0,
comment|//   let EMIT_TRAILING_DECIMAL_POINT and EMIT_TRAILING_ZERO_AFTER_POINT be
comment|//    - false and false: then 123.45 -> 123
comment|//                             0.678 -> 1
comment|//    - true and false: then 123.45 -> 123.
comment|//                            0.678 -> 1.
comment|//    - true and true: then 123.45 -> 123.0
comment|//                           0.678 -> 1.0
comment|//
comment|// Returns true if the conversion succeeds. The conversion always succeeds
comment|// except for the following cases:
comment|//   - the input value is special and no infinity_symbol or nan_symbol has
comment|//     been provided to the constructor,
comment|//   - 'value'> 10^kMaxFixedDigitsBeforePoint, or
comment|//   - 'requested_digits'> kMaxFixedDigitsAfterPoint.
comment|// The last two conditions imply that the result will never contain more than
comment|// 1 + kMaxFixedDigitsBeforePoint + 1 + kMaxFixedDigitsAfterPoint characters
comment|// (one additional character for the sign, and one for the decimal point).
name|bool
name|ToFixed
argument_list|(
name|double
name|value
argument_list|,
name|int
name|requested_digits
argument_list|,
name|StringBuilder
operator|*
name|result_builder
argument_list|)
decl|const
decl_stmt|;
comment|// Computes a representation in exponential format with requested_digits
comment|// after the decimal point. The last emitted digit is rounded.
comment|// If requested_digits equals -1, then the shortest exponential representation
comment|// is computed.
comment|//
comment|// Examples with EMIT_POSITIVE_EXPONENT_SIGN deactivated, and
comment|//               exponent_character set to 'e'.
comment|//   ToExponential(3.12, 1) -> "3.1e0"
comment|//   ToExponential(5.0, 3) -> "5.000e0"
comment|//   ToExponential(0.001, 2) -> "1.00e-3"
comment|//   ToExponential(3.1415, -1) -> "3.1415e0"
comment|//   ToExponential(3.1415, 4) -> "3.1415e0"
comment|//   ToExponential(3.1415, 3) -> "3.142e0"
comment|//   ToExponential(123456789000000, 3) -> "1.235e14"
comment|//   ToExponential(1000000000000000019884624838656.0, -1) -> "1e30"
comment|//   ToExponential(1000000000000000019884624838656.0, 32) ->
comment|//                     "1.00000000000000001988462483865600e30"
comment|//   ToExponential(1234, 0) -> "1e3"
comment|//
comment|// Returns true if the conversion succeeds. The conversion always succeeds
comment|// except for the following cases:
comment|//   - the input value is special and no infinity_symbol or nan_symbol has
comment|//     been provided to the constructor,
comment|//   - 'requested_digits'> kMaxExponentialDigits.
comment|// The last condition implies that the result will never contain more than
comment|// kMaxExponentialDigits + 8 characters (the sign, the digit before the
comment|// decimal point, the decimal point, the exponent character, the
comment|// exponent's sign, and at most 3 exponent digits).
name|bool
name|ToExponential
argument_list|(
name|double
name|value
argument_list|,
name|int
name|requested_digits
argument_list|,
name|StringBuilder
operator|*
name|result_builder
argument_list|)
decl|const
decl_stmt|;
comment|// Computes 'precision' leading digits of the given 'value' and returns them
comment|// either in exponential or decimal format, depending on
comment|// max_{leading|trailing}_padding_zeroes_in_precision_mode (given to the
comment|// constructor).
comment|// The last computed digit is rounded.
comment|//
comment|// Example with max_leading_padding_zeroes_in_precision_mode = 6.
comment|//   ToPrecision(0.0000012345, 2) -> "0.0000012"
comment|//   ToPrecision(0.00000012345, 2) -> "1.2e-7"
comment|// Similarily the converter may add up to
comment|// max_trailing_padding_zeroes_in_precision_mode in precision mode to avoid
comment|// returning an exponential representation. A zero added by the
comment|// EMIT_TRAILING_ZERO_AFTER_POINT flag is counted for this limit.
comment|// Examples for max_trailing_padding_zeroes_in_precision_mode = 1:
comment|//   ToPrecision(230.0, 2) -> "230"
comment|//   ToPrecision(230.0, 2) -> "230."  with EMIT_TRAILING_DECIMAL_POINT.
comment|//   ToPrecision(230.0, 2) -> "2.3e2" with EMIT_TRAILING_ZERO_AFTER_POINT.
comment|// Examples for max_trailing_padding_zeroes_in_precision_mode = 3, and no
comment|//    EMIT_TRAILING_ZERO_AFTER_POINT:
comment|//   ToPrecision(123450.0, 6) -> "123450"
comment|//   ToPrecision(123450.0, 5) -> "123450"
comment|//   ToPrecision(123450.0, 4) -> "123500"
comment|//   ToPrecision(123450.0, 3) -> "123000"
comment|//   ToPrecision(123450.0, 2) -> "1.2e5"
comment|//
comment|// Returns true if the conversion succeeds. The conversion always succeeds
comment|// except for the following cases:
comment|//   - the input value is special and no infinity_symbol or nan_symbol has
comment|//     been provided to the constructor,
comment|//   - precision< kMinPericisionDigits
comment|//   - precision> kMaxPrecisionDigits
comment|// The last condition implies that the result will never contain more than
comment|// kMaxPrecisionDigits + 7 characters (the sign, the decimal point, the
comment|// exponent character, the exponent's sign, and at most 3 exponent digits).
name|bool
name|ToPrecision
argument_list|(
name|double
name|value
argument_list|,
name|int
name|precision
argument_list|,
name|StringBuilder
operator|*
name|result_builder
argument_list|)
decl|const
decl_stmt|;
enum|enum
name|DtoaMode
block|{
comment|// Produce the shortest correct representation.
comment|// For example the output of 0.299999999999999988897 is (the less accurate
comment|// but correct) 0.3.
name|SHORTEST
block|,
comment|// Same as SHORTEST, but for single-precision floats.
name|SHORTEST_SINGLE
block|,
comment|// Produce a fixed number of digits after the decimal point.
comment|// For instance fixed(0.1, 4) becomes 0.1000
comment|// If the input number is big, the output will be big.
name|FIXED
block|,
comment|// Fixed number of digits (independent of the decimal point).
name|PRECISION
block|}
enum|;
comment|// The maximal number of digits that are needed to emit a double in base 10.
comment|// A higher precision can be achieved by using more digits, but the shortest
comment|// accurate representation of any double will never use more digits than
comment|// kBase10MaximalLength.
comment|// Note that DoubleToAscii null-terminates its input. So the given buffer
comment|// should be at least kBase10MaximalLength + 1 characters long.
specifier|static
specifier|const
name|int
name|kBase10MaximalLength
init|=
literal|17
decl_stmt|;
comment|// Converts the given double 'v' to ascii. 'v' must not be NaN, +Infinity, or
comment|// -Infinity. In SHORTEST_SINGLE-mode this restriction also applies to 'v'
comment|// after it has been casted to a single-precision float. That is, in this
comment|// mode static_cast<float>(v) must not be NaN, +Infinity or -Infinity.
comment|//
comment|// The result should be interpreted as buffer * 10^(point-length).
comment|//
comment|// The output depends on the given mode:
comment|//  - SHORTEST: produce the least amount of digits for which the internal
comment|//   identity requirement is still satisfied. If the digits are printed
comment|//   (together with the correct exponent) then reading this number will give
comment|//   'v' again. The buffer will choose the representation that is closest to
comment|//   'v'. If there are two at the same distance, than the one farther away
comment|//   from 0 is chosen (halfway cases - ending with 5 - are rounded up).
comment|//   In this mode the 'requested_digits' parameter is ignored.
comment|//  - SHORTEST_SINGLE: same as SHORTEST but with single-precision.
comment|//  - FIXED: produces digits necessary to print a given number with
comment|//   'requested_digits' digits after the decimal point. The produced digits
comment|//   might be too short in which case the caller has to fill the remainder
comment|//   with '0's.
comment|//   Example: toFixed(0.001, 5) is allowed to return buffer="1", point=-2.
comment|//   Halfway cases are rounded towards +/-Infinity (away from 0). The call
comment|//   toFixed(0.15, 2) thus returns buffer="2", point=0.
comment|//   The returned buffer may contain digits that would be truncated from the
comment|//   shortest representation of the input.
comment|//  - PRECISION: produces 'requested_digits' where the first digit is not '0'.
comment|//   Even though the length of produced digits usually equals
comment|//   'requested_digits', the function is allowed to return fewer digits, in
comment|//   which case the caller has to fill the missing digits with '0's.
comment|//   Halfway cases are again rounded away from 0.
comment|// DoubleToAscii expects the given buffer to be big enough to hold all
comment|// digits and a terminating null-character. In SHORTEST-mode it expects a
comment|// buffer of at least kBase10MaximalLength + 1. In all other modes the
comment|// requested_digits parameter and the padding-zeroes limit the size of the
comment|// output. Don't forget the decimal point, the exponent character and the
comment|// terminating null-character when computing the maximal output size.
comment|// The given length is only used in debug mode to ensure the buffer is big
comment|// enough.
specifier|static
name|void
name|DoubleToAscii
parameter_list|(
name|double
name|v
parameter_list|,
name|DtoaMode
name|mode
parameter_list|,
name|int
name|requested_digits
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|buffer_length
parameter_list|,
name|bool
modifier|*
name|sign
parameter_list|,
name|int
modifier|*
name|length
parameter_list|,
name|int
modifier|*
name|point
parameter_list|)
function_decl|;
name|private
label|:
comment|// Implementation for ToShortest and ToShortestSingle.
name|bool
name|ToShortestIeeeNumber
argument_list|(
name|double
name|value
argument_list|,
name|StringBuilder
operator|*
name|result_builder
argument_list|,
name|DtoaMode
name|mode
argument_list|)
decl|const
decl_stmt|;
comment|// If the value is a special value (NaN or Infinity) constructs the
comment|// corresponding string using the configured infinity/nan-symbol.
comment|// If either of them is NULL or the value is not special then the
comment|// function returns false.
name|bool
name|HandleSpecialValues
argument_list|(
name|double
name|value
argument_list|,
name|StringBuilder
operator|*
name|result_builder
argument_list|)
decl|const
decl_stmt|;
comment|// Constructs an exponential representation (i.e. 1.234e56).
comment|// The given exponent assumes a decimal point after the first decimal digit.
name|void
name|CreateExponentialRepresentation
argument_list|(
specifier|const
name|char
operator|*
name|decimal_digits
argument_list|,
name|int
name|length
argument_list|,
name|int
name|exponent
argument_list|,
name|StringBuilder
operator|*
name|result_builder
argument_list|)
decl|const
decl_stmt|;
comment|// Creates a decimal representation (i.e 1234.5678).
name|void
name|CreateDecimalRepresentation
parameter_list|(
specifier|const
name|char
modifier|*
name|decimal_digits
parameter_list|,
name|int
name|length
parameter_list|,
name|int
name|decimal_point
parameter_list|,
name|int
name|digits_after_point
parameter_list|,
name|StringBuilder
modifier|*
name|result_builder
parameter_list|)
function_decl|const;
specifier|const
name|int
name|flags_
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|infinity_symbol_
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|nan_symbol_
decl_stmt|;
specifier|const
name|char
name|exponent_character_
decl_stmt|;
specifier|const
name|int
name|decimal_in_shortest_low_
decl_stmt|;
specifier|const
name|int
name|decimal_in_shortest_high_
decl_stmt|;
specifier|const
name|int
name|max_leading_padding_zeroes_in_precision_mode_
decl_stmt|;
specifier|const
name|int
name|max_trailing_padding_zeroes_in_precision_mode_
decl_stmt|;
name|DISALLOW_IMPLICIT_CONSTRUCTORS
argument_list|(
name|DoubleToStringConverter
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|class
name|StringToDoubleConverter
block|{
name|public
label|:
comment|// Enumeration for allowing octals and ignoring junk when converting
comment|// strings to numbers.
enum|enum
name|Flags
block|{
name|NO_FLAGS
init|=
literal|0
block|,
name|ALLOW_HEX
init|=
literal|1
block|,
name|ALLOW_OCTALS
init|=
literal|2
block|,
name|ALLOW_TRAILING_JUNK
init|=
literal|4
block|,
name|ALLOW_LEADING_SPACES
init|=
literal|8
block|,
name|ALLOW_TRAILING_SPACES
init|=
literal|16
block|,
name|ALLOW_SPACES_AFTER_SIGN
init|=
literal|32
block|}
enum|;
comment|// Flags should be a bit-or combination of the possible Flags-enum.
comment|//  - NO_FLAGS: no special flags.
comment|//  - ALLOW_HEX: recognizes the prefix "0x". Hex numbers may only be integers.
comment|//      Ex: StringToDouble("0x1234") -> 4660.0
comment|//          In StringToDouble("0x1234.56") the characters ".56" are trailing
comment|//          junk. The result of the call is hence dependent on
comment|//          the ALLOW_TRAILING_JUNK flag and/or the junk value.
comment|//      With this flag "0x" is a junk-string. Even with ALLOW_TRAILING_JUNK,
comment|//      the string will not be parsed as "0" followed by junk.
comment|//
comment|//  - ALLOW_OCTALS: recognizes the prefix "0" for octals:
comment|//      If a sequence of octal digits starts with '0', then the number is
comment|//      read as octal integer. Octal numbers may only be integers.
comment|//      Ex: StringToDouble("01234") -> 668.0
comment|//          StringToDouble("012349") -> 12349.0  // Not a sequence of octal
comment|//                                               // digits.
comment|//          In StringToDouble("01234.56") the characters ".56" are trailing
comment|//          junk. The result of the call is hence dependent on
comment|//          the ALLOW_TRAILING_JUNK flag and/or the junk value.
comment|//          In StringToDouble("01234e56") the characters "e56" are trailing
comment|//          junk, too.
comment|//  - ALLOW_TRAILING_JUNK: ignore trailing characters that are not part of
comment|//      a double literal.
comment|//  - ALLOW_LEADING_SPACES: skip over leading whitespace, including spaces,
comment|//                          new-lines, and tabs.
comment|//  - ALLOW_TRAILING_SPACES: ignore trailing whitespace.
comment|//  - ALLOW_SPACES_AFTER_SIGN: ignore whitespace after the sign.
comment|//       Ex: StringToDouble("-   123.2") -> -123.2.
comment|//           StringToDouble("+   123.2") -> 123.2
comment|//
comment|// empty_string_value is returned when an empty string is given as input.
comment|// If ALLOW_LEADING_SPACES or ALLOW_TRAILING_SPACES are set, then a string
comment|// containing only spaces is converted to the 'empty_string_value', too.
comment|//
comment|// junk_string_value is returned when
comment|//  a) ALLOW_TRAILING_JUNK is not set, and a junk character (a character not
comment|//     part of a double-literal) is found.
comment|//  b) ALLOW_TRAILING_JUNK is set, but the string does not start with a
comment|//     double literal.
comment|//
comment|// infinity_symbol and nan_symbol are strings that are used to detect
comment|// inputs that represent infinity and NaN. They can be null, in which case
comment|// they are ignored.
comment|// The conversion routine first reads any possible signs. Then it compares the
comment|// following character of the input-string with the first character of
comment|// the infinity, and nan-symbol. If either matches, the function assumes, that
comment|// a match has been found, and expects the following input characters to match
comment|// the remaining characters of the special-value symbol.
comment|// This means that the following restrictions apply to special-value symbols:
comment|//  - they must not start with signs ('+', or '-'),
comment|//  - they must not have the same first character.
comment|//  - they must not start with digits.
comment|//
comment|// Examples:
comment|//  flags = ALLOW_HEX | ALLOW_TRAILING_JUNK,
comment|//  empty_string_value = 0.0,
comment|//  junk_string_value = NaN,
comment|//  infinity_symbol = "infinity",
comment|//  nan_symbol = "nan":
comment|//    StringToDouble("0x1234") -> 4660.0.
comment|//    StringToDouble("0x1234K") -> 4660.0.
comment|//    StringToDouble("") -> 0.0  // empty_string_value.
comment|//    StringToDouble(" ") -> NaN  // junk_string_value.
comment|//    StringToDouble(" 1") -> NaN  // junk_string_value.
comment|//    StringToDouble("0x") -> NaN  // junk_string_value.
comment|//    StringToDouble("-123.45") -> -123.45.
comment|//    StringToDouble("--123.45") -> NaN  // junk_string_value.
comment|//    StringToDouble("123e45") -> 123e45.
comment|//    StringToDouble("123E45") -> 123e45.
comment|//    StringToDouble("123e+45") -> 123e45.
comment|//    StringToDouble("123E-45") -> 123e-45.
comment|//    StringToDouble("123e") -> 123.0  // trailing junk ignored.
comment|//    StringToDouble("123e-") -> 123.0  // trailing junk ignored.
comment|//    StringToDouble("+NaN") -> NaN  // NaN string literal.
comment|//    StringToDouble("-infinity") -> -inf.  // infinity literal.
comment|//    StringToDouble("Infinity") -> NaN  // junk_string_value.
comment|//
comment|//  flags = ALLOW_OCTAL | ALLOW_LEADING_SPACES,
comment|//  empty_string_value = 0.0,
comment|//  junk_string_value = NaN,
comment|//  infinity_symbol = NULL,
comment|//  nan_symbol = NULL:
comment|//    StringToDouble("0x1234") -> NaN  // junk_string_value.
comment|//    StringToDouble("01234") -> 668.0.
comment|//    StringToDouble("") -> 0.0  // empty_string_value.
comment|//    StringToDouble(" ") -> 0.0  // empty_string_value.
comment|//    StringToDouble(" 1") -> 1.0
comment|//    StringToDouble("0x") -> NaN  // junk_string_value.
comment|//    StringToDouble("0123e45") -> NaN  // junk_string_value.
comment|//    StringToDouble("01239E45") -> 1239e45.
comment|//    StringToDouble("-infinity") -> NaN  // junk_string_value.
comment|//    StringToDouble("NaN") -> NaN  // junk_string_value.
name|StringToDoubleConverter
argument_list|(
argument|int flags
argument_list|,
argument|double empty_string_value
argument_list|,
argument|double junk_string_value
argument_list|,
argument|const char* infinity_symbol
argument_list|,
argument|const char* nan_symbol
argument_list|)
block|:
name|flags_
argument_list|(
name|flags
argument_list|)
operator|,
name|empty_string_value_
argument_list|(
name|empty_string_value
argument_list|)
operator|,
name|junk_string_value_
argument_list|(
name|junk_string_value
argument_list|)
operator|,
name|infinity_symbol_
argument_list|(
name|infinity_symbol
argument_list|)
operator|,
name|nan_symbol_
argument_list|(
argument|nan_symbol
argument_list|)
block|{   }
comment|// Performs the conversion.
comment|// The output parameter 'processed_characters_count' is set to the number
comment|// of characters that have been processed to read the number.
comment|// Spaces than are processed with ALLOW_{LEADING|TRAILING}_SPACES are included
comment|// in the 'processed_characters_count'. Trailing junk is never included.
name|double
name|StringToDouble
argument_list|(
argument|const char* buffer
argument_list|,
argument|int length
argument_list|,
argument|int* processed_characters_count
argument_list|)
specifier|const
expr_stmt|;
comment|// Same as StringToDouble above but for 16 bit characters.
name|double
name|StringToDouble
argument_list|(
specifier|const
name|uc16
operator|*
name|buffer
argument_list|,
name|int
name|length
argument_list|,
name|int
operator|*
name|processed_characters_count
argument_list|)
decl|const
decl_stmt|;
comment|// Same as StringToDouble but reads a float.
comment|// Note that this is not equivalent to static_cast<float>(StringToDouble(...))
comment|// due to potential double-rounding.
name|float
name|StringToFloat
argument_list|(
specifier|const
name|char
operator|*
name|buffer
argument_list|,
name|int
name|length
argument_list|,
name|int
operator|*
name|processed_characters_count
argument_list|)
decl|const
decl_stmt|;
comment|// Same as StringToFloat above but for 16 bit characters.
name|float
name|StringToFloat
argument_list|(
specifier|const
name|uc16
operator|*
name|buffer
argument_list|,
name|int
name|length
argument_list|,
name|int
operator|*
name|processed_characters_count
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
specifier|const
name|int
name|flags_
decl_stmt|;
specifier|const
name|double
name|empty_string_value_
decl_stmt|;
specifier|const
name|double
name|junk_string_value_
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|infinity_symbol_
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|nan_symbol_
decl_stmt|;
name|template
operator|<
name|class
name|Iterator
operator|>
name|double
name|StringToIeee
argument_list|(
argument|Iterator start_pointer
argument_list|,
argument|int length
argument_list|,
argument|bool read_as_double
argument_list|,
argument|int* processed_characters_count
argument_list|)
specifier|const
expr_stmt|;
name|DISALLOW_IMPLICIT_CONSTRUCTORS
argument_list|(
name|StringToDoubleConverter
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
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
comment|// DOUBLE_CONVERSION_DOUBLE_CONVERSION_H_
end_comment
end_unit
