begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLOCALE_TOOLS_P_H
end_ifndef
begin_define
DECL|macro|QLOCALE_TOOLS_P_H
define|#
directive|define
name|QLOCALE_TOOLS_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of internal files.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
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
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_QLOCALE_NEEDS_VOLATILE
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
end_if
begin_if
if|#
directive|if
name|__GNUC__
operator|==
literal|4
end_if
begin_define
DECL|macro|QT_QLOCALE_NEEDS_VOLATILE
define|#
directive|define
name|QT_QLOCALE_NEEDS_VOLATILE
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_elif
begin_define
DECL|macro|QT_QLOCALE_NEEDS_VOLATILE
define|#
directive|define
name|QT_QLOCALE_NEEDS_VOLATILE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_QLOCALE_NEEDS_VOLATILE
argument_list|)
end_if
begin_define
DECL|macro|NEEDS_VOLATILE
define|#
directive|define
name|NEEDS_VOLATILE
value|volatile
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|NEEDS_VOLATILE
define|#
directive|define
name|NEEDS_VOLATILE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enum|TrailingJunkMode
name|enum
name|TrailingJunkMode
block|{
DECL|enumerator|TrailingJunkProhibited
name|TrailingJunkProhibited
operator|,
DECL|enumerator|TrailingJunkAllowed
name|TrailingJunkAllowed
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function_decl
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
init|=
name|TrailingJunkProhibited
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|doubleToAscii
argument_list|(
name|double
name|d
argument_list|,
name|QLocaleData
operator|::
name|DoubleForm
name|form
argument_list|,
name|int
name|precision
argument_list|,
name|char
operator|*
name|buf
argument_list|,
name|int
name|bufSize
argument_list|,
name|bool
operator|&
name|sign
argument_list|,
name|int
operator|&
name|length
argument_list|,
name|int
operator|&
name|decpt
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
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
function_decl|;
end_function_decl
begin_function_decl
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
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
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
function_decl|;
end_function_decl
begin_enum
DECL|enum|PrecisionMode
enum|enum
name|PrecisionMode
block|{
DECL|enumerator|PMDecimalDigits
name|PMDecimalDigits
init|=
literal|0x01
block|,
DECL|enumerator|PMSignificantDigits
name|PMSignificantDigits
init|=
literal|0x02
block|,
DECL|enumerator|PMChopTrailingZeros
name|PMChopTrailingZeros
init|=
literal|0x03
block|}
enum|;
end_enum
begin_function_decl
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
function_decl|;
end_function_decl
begin_function_decl
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
function_decl|;
end_function_decl
begin_function
DECL|function|isZero
specifier|inline
name|bool
name|isZero
parameter_list|(
name|double
name|d
parameter_list|)
block|{
name|uchar
modifier|*
name|ch
init|=
operator|(
name|uchar
operator|*
operator|)
operator|&
name|d
decl_stmt|;
if|if
condition|(
name|QSysInfo
operator|::
name|ByteOrder
operator|==
name|QSysInfo
operator|::
name|BigEndian
condition|)
block|{
return|return
operator|!
operator|(
name|ch
index|[
literal|0
index|]
operator|&
literal|0x7F
operator|||
name|ch
index|[
literal|1
index|]
operator|||
name|ch
index|[
literal|2
index|]
operator|||
name|ch
index|[
literal|3
index|]
operator|||
name|ch
index|[
literal|4
index|]
operator|||
name|ch
index|[
literal|5
index|]
operator|||
name|ch
index|[
literal|6
index|]
operator|||
name|ch
index|[
literal|7
index|]
operator|)
return|;
block|}
else|else
block|{
return|return
operator|!
operator|(
name|ch
index|[
literal|7
index|]
operator|&
literal|0x7F
operator|||
name|ch
index|[
literal|6
index|]
operator|||
name|ch
index|[
literal|5
index|]
operator|||
name|ch
index|[
literal|4
index|]
operator|||
name|ch
index|[
literal|3
index|]
operator|||
name|ch
index|[
literal|2
index|]
operator|||
name|ch
index|[
literal|1
index|]
operator|||
name|ch
index|[
literal|0
index|]
operator|)
return|;
block|}
block|}
end_function
begin_function_decl
name|Q_CORE_EXPORT
name|double
name|qstrtod
parameter_list|(
specifier|const
name|char
modifier|*
name|s00
parameter_list|,
name|char
specifier|const
modifier|*
modifier|*
name|se
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|double
name|qstrntod
parameter_list|(
specifier|const
name|char
modifier|*
name|s00
parameter_list|,
name|int
name|len
parameter_list|,
name|char
specifier|const
modifier|*
modifier|*
name|se
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|qlonglong
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
function_decl|;
end_function_decl
begin_function_decl
name|qulonglong
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
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
