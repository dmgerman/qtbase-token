begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Copyright (C) 2014 Intel Corporation ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlocale_tools_p.h"
end_include
begin_include
include|#
directive|include
file|"qdoublescanprint_p.h"
end_include
begin_include
include|#
directive|include
file|"qlocale_p.h"
end_include
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_include
include|#
directive|include
file|<private/qnumeric_p.h>
end_include
begin_include
include|#
directive|include
file|<ctype.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<float.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__UCLIBC__
argument_list|)
end_if
begin_include
include|#
directive|include
file|<fenv.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Sizes as defined by the ISO C99 standard - fallback
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LLONG_MAX
end_ifndef
begin_define
DECL|macro|LLONG_MAX
define|#
directive|define
name|LLONG_MAX
value|Q_INT64_C(0x7fffffffffffffff)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|LLONG_MIN
end_ifndef
begin_define
DECL|macro|LLONG_MIN
define|#
directive|define
name|LLONG_MIN
value|(-LLONG_MAX - Q_INT64_C(1))
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|ULLONG_MAX
end_ifndef
begin_define
DECL|macro|ULLONG_MAX
define|#
directive|define
name|ULLONG_MAX
value|Q_UINT64_C(0xffffffffffffffff)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
include|#
directive|include
file|"../../3rdparty/freebsd/strtoull.c"
include|#
directive|include
file|"../../3rdparty/freebsd/strtoll.c"
name|QT_CLOCALE_HOLDER
DECL|function|doubleToAscii
name|void
name|doubleToAscii
parameter_list|(
name|double
name|d
parameter_list|,
name|QLocaleData
operator|::
name|DoubleForm
name|form
parameter_list|,
name|int
name|precision
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|bufSize
parameter_list|,
name|bool
modifier|&
name|sign
parameter_list|,
name|int
modifier|&
name|length
parameter_list|,
name|int
modifier|&
name|decpt
parameter_list|)
block|{
if|if
condition|(
name|bufSize
operator|==
literal|0
condition|)
block|{
name|decpt
operator|=
literal|0
expr_stmt|;
name|sign
operator|=
name|d
operator|<
literal|0
expr_stmt|;
name|length
operator|=
literal|0
expr_stmt|;
return|return;
block|}
comment|// Detect special numbers (nan, +/-inf)
comment|// We cannot use the high-level API of libdouble-conversion as we need to apply locale-specific
comment|// formatting, such as decimal points, thousands-separators, etc. Because of this, we have to
comment|// check for infinity and NaN before calling DoubleToAscii.
if|if
condition|(
name|qt_is_inf
argument_list|(
name|d
argument_list|)
condition|)
block|{
name|sign
operator|=
name|d
operator|<
literal|0
expr_stmt|;
if|if
condition|(
name|bufSize
operator|>=
literal|3
condition|)
block|{
name|buf
index|[
literal|0
index|]
operator|=
literal|'i'
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
literal|'n'
expr_stmt|;
name|buf
index|[
literal|2
index|]
operator|=
literal|'f'
expr_stmt|;
name|length
operator|=
literal|3
expr_stmt|;
block|}
else|else
block|{
name|length
operator|=
literal|0
expr_stmt|;
block|}
return|return;
block|}
elseif|else
if|if
condition|(
name|qt_is_nan
argument_list|(
name|d
argument_list|)
condition|)
block|{
if|if
condition|(
name|bufSize
operator|>=
literal|3
condition|)
block|{
name|buf
index|[
literal|0
index|]
operator|=
literal|'n'
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
literal|'a'
expr_stmt|;
name|buf
index|[
literal|2
index|]
operator|=
literal|'n'
expr_stmt|;
name|length
operator|=
literal|3
expr_stmt|;
block|}
else|else
block|{
name|length
operator|=
literal|0
expr_stmt|;
block|}
return|return;
block|}
if|if
condition|(
name|form
operator|==
name|QLocaleData
operator|::
name|DFSignificantDigits
operator|&&
name|precision
operator|==
literal|0
condition|)
name|precision
operator|=
literal|1
expr_stmt|;
comment|// 0 significant digits is silently converted to 1
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DOUBLECONVERSION
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
comment|// one digit before the decimal dot, counts as significant digit for DoubleToStringConverter
if|if
condition|(
name|form
operator|==
name|QLocaleData
operator|::
name|DFExponent
operator|&&
name|precision
operator|>=
literal|0
condition|)
operator|++
name|precision
expr_stmt|;
name|double_conversion
operator|::
name|DoubleToStringConverter
operator|::
name|DtoaMode
name|mode
decl_stmt|;
if|if
condition|(
name|precision
operator|==
name|QLocale
operator|::
name|FloatingPointShortest
condition|)
block|{
name|mode
operator|=
name|double_conversion
operator|::
name|DoubleToStringConverter
operator|::
name|SHORTEST
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|form
operator|==
name|QLocaleData
operator|::
name|DFSignificantDigits
operator|||
name|form
operator|==
name|QLocaleData
operator|::
name|DFExponent
condition|)
block|{
name|mode
operator|=
name|double_conversion
operator|::
name|DoubleToStringConverter
operator|::
name|PRECISION
expr_stmt|;
block|}
else|else
block|{
name|mode
operator|=
name|double_conversion
operator|::
name|DoubleToStringConverter
operator|::
name|FIXED
expr_stmt|;
block|}
name|double_conversion
operator|::
name|DoubleToStringConverter
operator|::
name|DoubleToAscii
argument_list|(
name|d
argument_list|,
name|mode
argument_list|,
name|precision
argument_list|,
name|buf
argument_list|,
name|bufSize
argument_list|,
operator|&
name|sign
argument_list|,
operator|&
name|length
argument_list|,
operator|&
name|decpt
argument_list|)
expr_stmt|;
else|#
directive|else
comment|// QT_NO_DOUBLECONVERSION || QT_BOOTSTRAPPED
comment|// Cut the precision at 999, to fit it into the format string. We can't get more than 17
comment|// significant digits, so anything after that is mostly noise. You do get closer to the "middle"
comment|// of the range covered by the given double with more digits, so to a degree it does make sense
comment|// to honor higher precisions. We define that at more than 999 digits that is not the case.
if|if
condition|(
name|precision
operator|>
literal|999
condition|)
name|precision
operator|=
literal|999
expr_stmt|;
elseif|else
if|if
condition|(
name|precision
operator|==
name|QLocale
operator|::
name|FloatingPointShortest
condition|)
name|precision
operator|=
name|QLocaleData
operator|::
name|DoubleMaxSignificant
expr_stmt|;
comment|// "shortest" mode not supported by snprintf
if|if
condition|(
name|isZero
argument_list|(
name|d
argument_list|)
condition|)
block|{
comment|// Negative zero is expected as simple "0", not "-0". We cannot do d< 0, though.
name|sign
operator|=
literal|false
expr_stmt|;
name|buf
index|[
literal|0
index|]
operator|=
literal|'0'
expr_stmt|;
name|length
operator|=
literal|1
expr_stmt|;
name|decpt
operator|=
literal|1
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
name|d
operator|<
literal|0
condition|)
block|{
name|sign
operator|=
literal|true
expr_stmt|;
name|d
operator|=
operator|-
name|d
expr_stmt|;
block|}
else|else
block|{
name|sign
operator|=
literal|false
expr_stmt|;
block|}
specifier|const
name|int
name|formatLength
init|=
literal|7
decl_stmt|;
comment|// '%', '.', 3 digits precision, 'f', '\0'
name|char
name|format
index|[
name|formatLength
index|]
decl_stmt|;
name|format
index|[
name|formatLength
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|format
index|[
literal|0
index|]
operator|=
literal|'%'
expr_stmt|;
name|format
index|[
literal|1
index|]
operator|=
literal|'.'
expr_stmt|;
name|format
index|[
literal|2
index|]
operator|=
name|char
argument_list|(
operator|(
name|precision
operator|/
literal|100
operator|)
operator|%
literal|10
argument_list|)
operator|+
literal|'0'
expr_stmt|;
name|format
index|[
literal|3
index|]
operator|=
name|char
argument_list|(
operator|(
name|precision
operator|/
literal|10
operator|)
operator|%
literal|10
argument_list|)
operator|+
literal|'0'
expr_stmt|;
name|format
index|[
literal|4
index|]
operator|=
name|char
argument_list|(
name|precision
operator|%
literal|10
argument_list|)
operator|+
literal|'0'
expr_stmt|;
name|int
name|extraChars
decl_stmt|;
switch|switch
condition|(
name|form
condition|)
block|{
case|case
name|QLocaleData
operator|::
name|DFDecimal
case|:
name|format
index|[
name|formatLength
operator|-
literal|2
index|]
operator|=
literal|'f'
expr_stmt|;
comment|//<anything> '.'<precision> '\0' - optimize for numbers smaller than 512k
name|extraChars
operator|=
operator|(
name|d
operator|>
operator|(
literal|1
operator|<<
literal|19
operator|)
condition|?
name|QLocaleData
operator|::
name|DoubleMaxDigitsBeforeDecimal
else|:
literal|6
operator|)
operator|+
literal|2
expr_stmt|;
break|break;
case|case
name|QLocaleData
operator|::
name|DFExponent
case|:
name|format
index|[
name|formatLength
operator|-
literal|2
index|]
operator|=
literal|'e'
expr_stmt|;
comment|// '.', 'e', '-',<exponent> '\0'
name|extraChars
operator|=
literal|7
expr_stmt|;
break|break;
case|case
name|QLocaleData
operator|::
name|DFSignificantDigits
case|:
name|format
index|[
name|formatLength
operator|-
literal|2
index|]
operator|=
literal|'g'
expr_stmt|;
comment|// either the same as in the 'e' case, or '.' and '\0'
comment|// precision covers part before '.'
name|extraChars
operator|=
literal|7
expr_stmt|;
break|break;
default|default:
name|Q_UNREACHABLE
argument_list|()
expr_stmt|;
block|}
name|QVarLengthArray
argument_list|<
name|char
argument_list|>
name|target
argument_list|(
name|precision
operator|+
name|extraChars
argument_list|)
decl_stmt|;
name|length
operator|=
name|qDoubleSnprintf
argument_list|(
name|target
operator|.
name|data
argument_list|()
argument_list|,
name|target
operator|.
name|size
argument_list|()
argument_list|,
name|QT_CLOCALE
argument_list|,
name|format
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|int
name|firstSignificant
init|=
literal|0
decl_stmt|;
name|int
name|decptInTarget
init|=
name|length
decl_stmt|;
comment|// Find the first significant digit (not 0), and note any '.' we encounter.
comment|// There is no '-' at the front of target because we made sure d> 0 above.
while|while
condition|(
name|firstSignificant
operator|<
name|length
condition|)
block|{
if|if
condition|(
name|target
index|[
name|firstSignificant
index|]
operator|==
literal|'.'
condition|)
name|decptInTarget
operator|=
name|firstSignificant
expr_stmt|;
elseif|else
if|if
condition|(
name|target
index|[
name|firstSignificant
index|]
operator|!=
literal|'0'
condition|)
break|break;
operator|++
name|firstSignificant
expr_stmt|;
block|}
comment|// If no '.' found so far, search the rest of the target buffer for it.
if|if
condition|(
name|decptInTarget
operator|==
name|length
condition|)
name|decptInTarget
operator|=
name|std
operator|::
name|find
argument_list|(
name|target
operator|.
name|data
argument_list|()
operator|+
name|firstSignificant
argument_list|,
name|target
operator|.
name|data
argument_list|()
operator|+
name|length
argument_list|,
literal|'.'
argument_list|)
operator|-
name|target
operator|.
name|data
argument_list|()
expr_stmt|;
name|int
name|eSign
init|=
name|length
decl_stmt|;
if|if
condition|(
name|form
operator|!=
name|QLocaleData
operator|::
name|DFDecimal
condition|)
block|{
comment|// In 'e' or 'g' form, look for the 'e'.
name|eSign
operator|=
name|std
operator|::
name|find
argument_list|(
name|target
operator|.
name|data
argument_list|()
operator|+
name|firstSignificant
argument_list|,
name|target
operator|.
name|data
argument_list|()
operator|+
name|length
argument_list|,
literal|'e'
argument_list|)
operator|-
name|target
operator|.
name|data
argument_list|()
expr_stmt|;
if|if
condition|(
name|eSign
operator|<
name|length
condition|)
block|{
comment|// If 'e' is found, the final decimal point is determined by the number after 'e'.
comment|// Mind that the final decimal point, decpt, is the offset of the decimal point from the
comment|// start of the resulting string in buf. It may be negative or larger than bufSize, in
comment|// which case the missing digits are zeroes. In the 'e' case decptInTarget is always 1,
comment|// as variants of snprintf always generate numbers with one digit before the '.' then.
comment|// This is why the final decimal point is offset by 1, relative to the number after 'e'.
name|bool
name|ok
decl_stmt|;
specifier|const
name|char
modifier|*
name|endptr
decl_stmt|;
name|decpt
operator|=
name|qstrtoll
argument_list|(
name|target
operator|.
name|data
argument_list|()
operator|+
name|eSign
operator|+
literal|1
argument_list|,
operator|&
name|endptr
argument_list|,
literal|10
argument_list|,
operator|&
name|ok
argument_list|)
operator|+
literal|1
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|endptr
operator|-
name|target
operator|.
name|data
argument_list|()
operator|<=
name|length
operator|-
name|eSign
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// No 'e' found, so it's the 'f' form. Variants of snprintf generate numbers with
comment|// potentially multiple digits before the '.', but without decimal exponent then. So we
comment|// get the final decimal point from the position of the '.'. The '.' itself takes up one
comment|// character. We adjust by 1 below if that gets in the way.
name|decpt
operator|=
name|decptInTarget
operator|-
name|firstSignificant
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// In 'f' form, there can not be an 'e', so it's enough to look for the '.'
comment|// (and possibly adjust by 1 below)
name|decpt
operator|=
name|decptInTarget
operator|-
name|firstSignificant
expr_stmt|;
block|}
comment|// Move the actual digits from the snprintf target to the actual buffer.
if|if
condition|(
name|decptInTarget
operator|>
name|firstSignificant
condition|)
block|{
comment|// First move the digits before the '.', if any
name|int
name|lengthBeforeDecpt
init|=
name|decptInTarget
operator|-
name|firstSignificant
decl_stmt|;
name|memcpy
argument_list|(
name|buf
argument_list|,
name|target
operator|.
name|data
argument_list|()
operator|+
name|firstSignificant
argument_list|,
name|qMin
argument_list|(
name|lengthBeforeDecpt
argument_list|,
name|bufSize
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|eSign
operator|>
name|decptInTarget
operator|&&
name|lengthBeforeDecpt
operator|<
name|bufSize
condition|)
block|{
comment|// Then move any remaining digits, until 'e'
name|memcpy
argument_list|(
name|buf
operator|+
name|lengthBeforeDecpt
argument_list|,
name|target
operator|.
name|data
argument_list|()
operator|+
name|decptInTarget
operator|+
literal|1
argument_list|,
name|qMin
argument_list|(
name|eSign
operator|-
name|decptInTarget
operator|-
literal|1
argument_list|,
name|bufSize
operator|-
name|lengthBeforeDecpt
argument_list|)
argument_list|)
expr_stmt|;
comment|// The final length of the output is the distance between the first significant digit
comment|// and 'e' minus 1, for the '.', except if the buffer is smaller.
name|length
operator|=
name|qMin
argument_list|(
name|eSign
operator|-
name|firstSignificant
operator|-
literal|1
argument_list|,
name|bufSize
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// 'e' was before the decpt or things didn't fit. Don't subtract the '.' from the length.
name|length
operator|=
name|qMin
argument_list|(
name|eSign
operator|-
name|firstSignificant
argument_list|,
name|bufSize
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|eSign
operator|>
name|firstSignificant
condition|)
block|{
comment|// If there are any significant digits at all, they are all after the '.' now.
comment|// Just copy them straight away.
name|memcpy
argument_list|(
name|buf
argument_list|,
name|target
operator|.
name|data
argument_list|()
operator|+
name|firstSignificant
argument_list|,
name|qMin
argument_list|(
name|eSign
operator|-
name|firstSignificant
argument_list|,
name|bufSize
argument_list|)
argument_list|)
expr_stmt|;
comment|// The decimal point was before the first significant digit, so we were one off above.
comment|// Consider 0.1 - buf will be just '1', and decpt should be 0. But
comment|// "decptInTarget - firstSignificant" will yield -1.
operator|++
name|decpt
expr_stmt|;
name|length
operator|=
name|qMin
argument_list|(
name|eSign
operator|-
name|firstSignificant
argument_list|,
name|bufSize
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// No significant digits means the number is just 0.
name|buf
index|[
literal|0
index|]
operator|=
literal|'0'
expr_stmt|;
name|length
operator|=
literal|1
expr_stmt|;
name|decpt
operator|=
literal|1
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|// QT_NO_DOUBLECONVERSION || QT_BOOTSTRAPPED
while|while
condition|(
name|length
operator|>
literal|1
operator|&&
name|buf
index|[
name|length
operator|-
literal|1
index|]
operator|==
literal|'0'
condition|)
comment|// drop trailing zeroes
operator|--
name|length
expr_stmt|;
block|}
end_function
begin_function
DECL|function|asciiToDouble
name|double
name|asciiToDouble
parameter_list|(
specifier|const
name|char
modifier|*
name|num
parameter_list|,
name|int
name|numLen
parameter_list|,
name|bool
modifier|&
name|ok
parameter_list|,
name|int
modifier|&
name|processed
parameter_list|,
name|TrailingJunkMode
name|trailingJunkMode
parameter_list|)
block|{
if|if
condition|(
operator|*
name|num
operator|==
literal|'\0'
condition|)
block|{
name|ok
operator|=
literal|false
expr_stmt|;
name|processed
operator|=
literal|0
expr_stmt|;
return|return
literal|0.0
return|;
block|}
name|ok
operator|=
literal|true
expr_stmt|;
comment|// We have to catch NaN before because we need NaN as marker for "garbage" in the
comment|// libdouble-conversion case and, in contrast to libdouble-conversion or sscanf, we don't allow
comment|// "-nan" or "+nan"
if|if
condition|(
name|qstrcmp
argument_list|(
name|num
argument_list|,
literal|"nan"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|processed
operator|=
literal|3
expr_stmt|;
return|return
name|qt_snan
argument_list|()
return|;
block|}
elseif|else
if|if
condition|(
operator|(
name|num
index|[
literal|0
index|]
operator|==
literal|'-'
operator|||
name|num
index|[
literal|0
index|]
operator|==
literal|'+'
operator|)
operator|&&
name|qstrcmp
argument_list|(
name|num
operator|+
literal|1
argument_list|,
literal|"nan"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|processed
operator|=
literal|0
expr_stmt|;
name|ok
operator|=
literal|false
expr_stmt|;
return|return
literal|0.0
return|;
block|}
comment|// Infinity values are implementation defined in the sscanf case. In the libdouble-conversion
comment|// case we need infinity as overflow marker.
if|if
condition|(
name|qstrcmp
argument_list|(
name|num
argument_list|,
literal|"+inf"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|processed
operator|=
literal|4
expr_stmt|;
return|return
name|qt_inf
argument_list|()
return|;
block|}
elseif|else
if|if
condition|(
name|qstrcmp
argument_list|(
name|num
argument_list|,
literal|"inf"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|processed
operator|=
literal|3
expr_stmt|;
return|return
name|qt_inf
argument_list|()
return|;
block|}
elseif|else
if|if
condition|(
name|qstrcmp
argument_list|(
name|num
argument_list|,
literal|"-inf"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|processed
operator|=
literal|4
expr_stmt|;
return|return
operator|-
name|qt_inf
argument_list|()
return|;
block|}
name|double
name|d
init|=
literal|0.0
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DOUBLECONVERSION
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
name|int
name|conv_flags
init|=
operator|(
name|trailingJunkMode
operator|==
name|TrailingJunkAllowed
operator|)
condition|?
name|double_conversion
operator|::
name|StringToDoubleConverter
operator|::
name|ALLOW_TRAILING_JUNK
else|:
name|double_conversion
operator|::
name|StringToDoubleConverter
operator|::
name|NO_FLAGS
decl_stmt|;
name|double_conversion
operator|::
name|StringToDoubleConverter
name|conv
argument_list|(
name|conv_flags
argument_list|,
literal|0.0
argument_list|,
name|qt_snan
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|d
operator|=
name|conv
operator|.
name|StringToDouble
argument_list|(
name|num
argument_list|,
name|numLen
argument_list|,
operator|&
name|processed
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|qIsFinite
argument_list|(
name|d
argument_list|)
condition|)
block|{
name|ok
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|qIsNaN
argument_list|(
name|d
argument_list|)
condition|)
block|{
comment|// Garbage found. We don't accept it and return 0.
name|processed
operator|=
literal|0
expr_stmt|;
return|return
literal|0.0
return|;
block|}
else|else
block|{
comment|// Overflow. That's not OK, but we still return infinity.
return|return
name|d
return|;
block|}
block|}
else|#
directive|else
if|if
condition|(
name|qDoubleSscanf
argument_list|(
name|num
argument_list|,
name|QT_CLOCALE
argument_list|,
literal|"%lf%n"
argument_list|,
operator|&
name|d
argument_list|,
operator|&
name|processed
argument_list|)
operator|<
literal|1
condition|)
name|processed
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
name|trailingJunkMode
operator|==
name|TrailingJunkProhibited
operator|&&
name|processed
operator|!=
name|numLen
operator|)
operator|||
name|qIsNaN
argument_list|(
name|d
argument_list|)
condition|)
block|{
comment|// Implementation defined nan symbol or garbage found. We don't accept it.
name|processed
operator|=
literal|0
expr_stmt|;
name|ok
operator|=
literal|false
expr_stmt|;
return|return
literal|0.0
return|;
block|}
if|if
condition|(
operator|!
name|qIsFinite
argument_list|(
name|d
argument_list|)
condition|)
block|{
comment|// Overflow. Check for implementation-defined infinity symbols and reject them.
comment|// We assume that any infinity symbol has to contain a character that cannot be part of a
comment|// "normal" number (that is 0-9, ., -, +, e).
name|ok
operator|=
literal|false
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|processed
condition|;
operator|++
name|i
control|)
block|{
name|char
name|c
init|=
name|num
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
operator|(
name|c
argument_list|<
literal|'0'
operator|||
name|c
argument_list|>
literal|'9'
operator|)
operator|&&
name|c
operator|!=
literal|'.'
operator|&&
name|c
operator|!=
literal|'-'
operator|&&
name|c
operator|!=
literal|'+'
operator|&&
name|c
operator|!=
literal|'e'
condition|)
block|{
comment|// Garbage found
name|processed
operator|=
literal|0
expr_stmt|;
return|return
literal|0.0
return|;
block|}
block|}
return|return
name|d
return|;
block|}
endif|#
directive|endif
comment|// !defined(QT_NO_DOUBLECONVERSION)&& !defined(QT_BOOTSTRAPPED)
comment|// Otherwise we would have gotten NaN or sorted it out above.
name|Q_ASSERT
argument_list|(
name|trailingJunkMode
operator|==
name|TrailingJunkAllowed
operator|||
name|processed
operator|==
name|numLen
argument_list|)
expr_stmt|;
comment|// Check if underflow has occurred.
if|if
condition|(
name|isZero
argument_list|(
name|d
argument_list|)
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|processed
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|num
index|[
name|i
index|]
operator|>=
literal|'1'
operator|&&
name|num
index|[
name|i
index|]
operator|<=
literal|'9'
condition|)
block|{
comment|// if a digit before any 'e' is not 0, then a non-zero number was intended.
name|ok
operator|=
literal|false
expr_stmt|;
return|return
literal|0.0
return|;
block|}
elseif|else
if|if
condition|(
name|num
index|[
name|i
index|]
operator|==
literal|'e'
condition|)
block|{
break|break;
block|}
block|}
block|}
return|return
name|d
return|;
block|}
end_function
begin_function
name|unsigned
name|long
name|long
DECL|function|qstrtoull
name|qstrtoull
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
block|{
comment|// strtoull accepts negative numbers. We don't.
comment|// Use a different variable so we pass the original nptr to strtoul
comment|// (we need that so endptr may be nptr in case of failure)
specifier|const
name|char
modifier|*
name|begin
init|=
name|nptr
decl_stmt|;
while|while
condition|(
name|ascii_isspace
argument_list|(
operator|*
name|begin
argument_list|)
condition|)
operator|++
name|begin
expr_stmt|;
if|if
condition|(
operator|*
name|begin
operator|==
literal|'-'
condition|)
block|{
operator|*
name|ok
operator|=
literal|false
expr_stmt|;
return|return
literal|0
return|;
block|}
operator|*
name|ok
operator|=
literal|true
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
name|char
modifier|*
name|endptr2
init|=
literal|0
decl_stmt|;
name|unsigned
name|long
name|long
name|result
init|=
name|qt_strtoull
argument_list|(
name|nptr
argument_list|,
operator|&
name|endptr2
argument_list|,
name|base
argument_list|)
decl_stmt|;
if|if
condition|(
name|endptr
condition|)
operator|*
name|endptr
operator|=
name|endptr2
expr_stmt|;
if|if
condition|(
operator|(
name|result
operator|==
literal|0
operator|||
name|result
operator|==
name|std
operator|::
name|numeric_limits
argument_list|<
name|unsigned
name|long
name|long
argument_list|>
operator|::
name|max
argument_list|()
operator|)
operator|&&
operator|(
name|errno
operator|||
name|endptr2
operator|==
name|nptr
operator|)
condition|)
block|{
operator|*
name|ok
operator|=
literal|false
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
name|long
name|long
DECL|function|qstrtoll
name|qstrtoll
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
block|{
operator|*
name|ok
operator|=
literal|true
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
name|char
modifier|*
name|endptr2
init|=
literal|0
decl_stmt|;
name|long
name|long
name|result
init|=
name|qt_strtoll
argument_list|(
name|nptr
argument_list|,
operator|&
name|endptr2
argument_list|,
name|base
argument_list|)
decl_stmt|;
if|if
condition|(
name|endptr
condition|)
operator|*
name|endptr
operator|=
name|endptr2
expr_stmt|;
if|if
condition|(
operator|(
name|result
operator|==
literal|0
operator|||
name|result
operator|==
name|std
operator|::
name|numeric_limits
argument_list|<
name|long
name|long
argument_list|>
operator|::
name|min
argument_list|()
operator|||
name|result
operator|==
name|std
operator|::
name|numeric_limits
argument_list|<
name|long
name|long
argument_list|>
operator|::
name|max
argument_list|()
operator|)
operator|&&
operator|(
name|errno
operator|||
name|nptr
operator|==
name|endptr2
operator|)
condition|)
block|{
operator|*
name|ok
operator|=
literal|false
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|qulltoa
name|QString
name|qulltoa
parameter_list|(
name|qulonglong
name|l
parameter_list|,
name|int
name|base
parameter_list|,
specifier|const
name|QChar
name|_zero
parameter_list|)
block|{
name|ushort
name|buff
index|[
literal|65
index|]
decl_stmt|;
comment|// length of MAX_ULLONG in base 2
name|ushort
modifier|*
name|p
init|=
name|buff
operator|+
literal|65
decl_stmt|;
if|if
condition|(
name|base
operator|!=
literal|10
operator|||
name|_zero
operator|.
name|unicode
argument_list|()
operator|==
literal|'0'
condition|)
block|{
while|while
condition|(
name|l
operator|!=
literal|0
condition|)
block|{
name|int
name|c
init|=
name|l
operator|%
name|base
decl_stmt|;
operator|--
name|p
expr_stmt|;
if|if
condition|(
name|c
operator|<
literal|10
condition|)
operator|*
name|p
operator|=
literal|'0'
operator|+
name|c
expr_stmt|;
else|else
operator|*
name|p
operator|=
name|c
operator|-
literal|10
operator|+
literal|'a'
expr_stmt|;
name|l
operator|/=
name|base
expr_stmt|;
block|}
block|}
else|else
block|{
while|while
condition|(
name|l
operator|!=
literal|0
condition|)
block|{
name|int
name|c
init|=
name|l
operator|%
name|base
decl_stmt|;
operator|*
operator|(
operator|--
name|p
operator|)
operator|=
name|_zero
operator|.
name|unicode
argument_list|()
operator|+
name|c
expr_stmt|;
name|l
operator|/=
name|base
expr_stmt|;
block|}
block|}
return|return
name|QString
argument_list|(
cast|reinterpret_cast
argument_list|<
name|QChar
operator|*
argument_list|>
argument_list|(
name|p
argument_list|)
argument_list|,
literal|65
operator|-
operator|(
name|p
operator|-
name|buff
operator|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qlltoa
name|QString
name|qlltoa
parameter_list|(
name|qlonglong
name|l
parameter_list|,
name|int
name|base
parameter_list|,
specifier|const
name|QChar
name|zero
parameter_list|)
block|{
return|return
name|qulltoa
argument_list|(
name|l
operator|<
literal|0
condition|?
operator|-
name|l
else|:
name|l
argument_list|,
name|base
argument_list|,
name|zero
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|decimalForm
name|QString
modifier|&
name|decimalForm
parameter_list|(
name|QChar
name|zero
parameter_list|,
name|QChar
name|decimal
parameter_list|,
name|QChar
name|group
parameter_list|,
name|QString
modifier|&
name|digits
parameter_list|,
name|int
name|decpt
parameter_list|,
name|int
name|precision
parameter_list|,
name|PrecisionMode
name|pm
parameter_list|,
name|bool
name|always_show_decpt
parameter_list|,
name|bool
name|thousands_group
parameter_list|)
block|{
if|if
condition|(
name|decpt
operator|<
literal|0
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
operator|-
name|decpt
condition|;
operator|++
name|i
control|)
name|digits
operator|.
name|prepend
argument_list|(
name|zero
argument_list|)
expr_stmt|;
name|decpt
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|decpt
operator|>
name|digits
operator|.
name|length
argument_list|()
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
name|digits
operator|.
name|length
argument_list|()
init|;
name|i
operator|<
name|decpt
condition|;
operator|++
name|i
control|)
name|digits
operator|.
name|append
argument_list|(
name|zero
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|pm
operator|==
name|PMDecimalDigits
condition|)
block|{
name|uint
name|decimal_digits
init|=
name|digits
operator|.
name|length
argument_list|()
operator|-
name|decpt
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|decimal_digits
init|;
name|i
operator|<
name|precision
condition|;
operator|++
name|i
control|)
name|digits
operator|.
name|append
argument_list|(
name|zero
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pm
operator|==
name|PMSignificantDigits
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
name|digits
operator|.
name|length
argument_list|()
init|;
name|i
operator|<
name|precision
condition|;
operator|++
name|i
control|)
name|digits
operator|.
name|append
argument_list|(
name|zero
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// pm == PMChopTrailingZeros
block|}
if|if
condition|(
name|always_show_decpt
operator|||
name|decpt
operator|<
name|digits
operator|.
name|length
argument_list|()
condition|)
name|digits
operator|.
name|insert
argument_list|(
name|decpt
argument_list|,
name|decimal
argument_list|)
expr_stmt|;
if|if
condition|(
name|thousands_group
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
name|decpt
operator|-
literal|3
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|-=
literal|3
control|)
name|digits
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|group
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|decpt
operator|==
literal|0
condition|)
name|digits
operator|.
name|prepend
argument_list|(
name|zero
argument_list|)
expr_stmt|;
return|return
name|digits
return|;
block|}
end_function
begin_function
DECL|function|exponentForm
name|QString
modifier|&
name|exponentForm
parameter_list|(
name|QChar
name|zero
parameter_list|,
name|QChar
name|decimal
parameter_list|,
name|QChar
name|exponential
parameter_list|,
name|QChar
name|group
parameter_list|,
name|QChar
name|plus
parameter_list|,
name|QChar
name|minus
parameter_list|,
name|QString
modifier|&
name|digits
parameter_list|,
name|int
name|decpt
parameter_list|,
name|int
name|precision
parameter_list|,
name|PrecisionMode
name|pm
parameter_list|,
name|bool
name|always_show_decpt
parameter_list|,
name|bool
name|leading_zero_in_exponent
parameter_list|)
block|{
name|int
name|exp
init|=
name|decpt
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|pm
operator|==
name|PMDecimalDigits
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
name|digits
operator|.
name|length
argument_list|()
init|;
name|i
operator|<
name|precision
operator|+
literal|1
condition|;
operator|++
name|i
control|)
name|digits
operator|.
name|append
argument_list|(
name|zero
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pm
operator|==
name|PMSignificantDigits
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
name|digits
operator|.
name|length
argument_list|()
init|;
name|i
operator|<
name|precision
condition|;
operator|++
name|i
control|)
name|digits
operator|.
name|append
argument_list|(
name|zero
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// pm == PMChopTrailingZeros
block|}
if|if
condition|(
name|always_show_decpt
operator|||
name|digits
operator|.
name|length
argument_list|()
operator|>
literal|1
condition|)
name|digits
operator|.
name|insert
argument_list|(
literal|1
argument_list|,
name|decimal
argument_list|)
expr_stmt|;
name|digits
operator|.
name|append
argument_list|(
name|exponential
argument_list|)
expr_stmt|;
name|digits
operator|.
name|append
argument_list|(
name|QLocaleData
operator|::
name|longLongToString
argument_list|(
name|zero
argument_list|,
name|group
argument_list|,
name|plus
argument_list|,
name|minus
argument_list|,
name|exp
argument_list|,
name|leading_zero_in_exponent
condition|?
literal|2
else|:
literal|1
argument_list|,
literal|10
argument_list|,
operator|-
literal|1
argument_list|,
name|QLocaleData
operator|::
name|AlwaysShowSign
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|digits
return|;
block|}
end_function
begin_function
DECL|function|qstrtod
name|double
name|qstrtod
parameter_list|(
specifier|const
name|char
modifier|*
name|s00
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|se
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
block|{
name|int
name|processed
init|=
literal|0
decl_stmt|;
name|bool
name|nonNullOk
init|=
literal|false
decl_stmt|;
name|int
name|len
init|=
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|strlen
argument_list|(
name|s00
argument_list|)
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|len
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|double
name|d
init|=
name|asciiToDouble
argument_list|(
name|s00
argument_list|,
name|len
argument_list|,
name|nonNullOk
argument_list|,
name|processed
argument_list|,
name|TrailingJunkAllowed
argument_list|)
decl_stmt|;
if|if
condition|(
name|se
condition|)
operator|*
name|se
operator|=
name|s00
operator|+
name|processed
expr_stmt|;
if|if
condition|(
name|ok
condition|)
operator|*
name|ok
operator|=
name|nonNullOk
expr_stmt|;
return|return
name|d
return|;
block|}
end_function
begin_function
DECL|function|qdtoa
name|QString
name|qdtoa
parameter_list|(
name|qreal
name|d
parameter_list|,
name|int
modifier|*
name|decpt
parameter_list|,
name|int
modifier|*
name|sign
parameter_list|)
block|{
name|bool
name|nonNullSign
init|=
literal|false
decl_stmt|;
name|int
name|nonNullDecpt
init|=
literal|0
decl_stmt|;
name|int
name|length
init|=
literal|0
decl_stmt|;
comment|// Some versions of libdouble-conversion like an extra digit, probably for '\0'
name|char
name|result
index|[
name|QLocaleData
operator|::
name|DoubleMaxSignificant
operator|+
literal|1
index|]
decl_stmt|;
name|doubleToAscii
argument_list|(
name|d
argument_list|,
name|QLocaleData
operator|::
name|DFSignificantDigits
argument_list|,
name|QLocale
operator|::
name|FloatingPointShortest
argument_list|,
name|result
argument_list|,
name|QLocaleData
operator|::
name|DoubleMaxSignificant
operator|+
literal|1
argument_list|,
name|nonNullSign
argument_list|,
name|length
argument_list|,
name|nonNullDecpt
argument_list|)
expr_stmt|;
if|if
condition|(
name|sign
condition|)
operator|*
name|sign
operator|=
name|nonNullSign
condition|?
literal|1
else|:
literal|0
expr_stmt|;
if|if
condition|(
name|decpt
condition|)
operator|*
name|decpt
operator|=
name|nonNullDecpt
expr_stmt|;
return|return
name|QLatin1String
argument_list|(
name|result
argument_list|,
name|length
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
