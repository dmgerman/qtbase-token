begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLOCALE_P_H
end_ifndef
begin_define
DECL|macro|QLOCALE_P_H
define|#
directive|define
name|QLOCALE_P_H
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
file|"QtCore/qstring.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvarlengtharray.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmetatype.h"
end_include
begin_include
include|#
directive|include
file|"qlocale.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SYSTEMLOCALE
argument_list|)
end_if
begin_decl_stmt
DECL|variable|CEnvironmentChangeNotifier
name|class
name|CEnvironmentChangeNotifier
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QLocalePrivate
struct|struct
name|Q_CORE_EXPORT
name|QLocalePrivate
block|{
DECL|member|public
name|public
label|:
name|QChar
name|decimal
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_decimal
argument_list|)
return|;
block|}
DECL|function|group
name|QChar
name|group
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_group
argument_list|)
return|;
block|}
DECL|function|list
name|QChar
name|list
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_list
argument_list|)
return|;
block|}
DECL|function|percent
name|QChar
name|percent
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_percent
argument_list|)
return|;
block|}
DECL|function|zero
name|QChar
name|zero
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_zero
argument_list|)
return|;
block|}
DECL|function|plus
name|QChar
name|plus
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_plus
argument_list|)
return|;
block|}
DECL|function|minus
name|QChar
name|minus
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_minus
argument_list|)
return|;
block|}
DECL|function|exponential
name|QChar
name|exponential
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_exponential
argument_list|)
return|;
block|}
DECL|function|languageId
name|quint16
name|languageId
argument_list|()
specifier|const
block|{
return|return
name|m_language_id
return|;
block|}
DECL|function|countryId
name|quint16
name|countryId
argument_list|()
specifier|const
block|{
return|return
name|m_country_id
return|;
block|}
name|QString
name|bcp47Name
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|languageCode
argument_list|()
specifier|const
expr_stmt|;
comment|// ### QByteArray::fromRawData would be more optimal
name|QString
name|scriptCode
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|countryCode
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QLocale
operator|::
name|Language
name|codeToLanguage
argument_list|(
specifier|const
name|QString
operator|&
name|code
argument_list|)
expr_stmt|;
specifier|static
name|QLocale
operator|::
name|Script
name|codeToScript
argument_list|(
specifier|const
name|QString
operator|&
name|code
argument_list|)
expr_stmt|;
specifier|static
name|QLocale
operator|::
name|Country
name|codeToCountry
argument_list|(
specifier|const
name|QString
operator|&
name|code
argument_list|)
expr_stmt|;
specifier|static
name|void
name|getLangAndCountry
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|QLocale
operator|::
name|Language
operator|&
name|lang
argument_list|,
name|QLocale
operator|::
name|Script
operator|&
name|script
argument_list|,
name|QLocale
operator|::
name|Country
operator|&
name|cntry
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QLocalePrivate
modifier|*
name|findLocale
argument_list|(
name|QLocale
operator|::
name|Language
name|language
argument_list|,
name|QLocale
operator|::
name|Script
name|script
argument_list|,
name|QLocale
operator|::
name|Country
name|country
argument_list|)
decl_stmt|;
name|QLocale
operator|::
name|MeasurementSystem
name|measurementSystem
argument_list|()
specifier|const
expr_stmt|;
DECL|enum|DoubleForm
enum|enum
name|DoubleForm
block|{
DECL|enumerator|DFExponent
name|DFExponent
init|=
literal|0
block|,
DECL|enumerator|DFDecimal
name|DFDecimal
block|,
DECL|enumerator|DFSignificantDigits
name|DFSignificantDigits
block|,
DECL|enumerator|_DFMax
name|_DFMax
init|=
name|DFSignificantDigits
block|}
enum|;
DECL|enum|Flags
enum|enum
name|Flags
block|{
DECL|enumerator|NoFlags
name|NoFlags
init|=
literal|0
block|,
DECL|enumerator|Alternate
name|Alternate
init|=
literal|0x01
block|,
DECL|enumerator|ZeroPadded
name|ZeroPadded
init|=
literal|0x02
block|,
DECL|enumerator|LeftAdjusted
name|LeftAdjusted
init|=
literal|0x04
block|,
DECL|enumerator|BlankBeforePositive
name|BlankBeforePositive
init|=
literal|0x08
block|,
DECL|enumerator|AlwaysShowSign
name|AlwaysShowSign
init|=
literal|0x10
block|,
DECL|enumerator|ThousandsGroup
name|ThousandsGroup
init|=
literal|0x20
block|,
DECL|enumerator|CapitalEorX
name|CapitalEorX
init|=
literal|0x40
block|,
DECL|enumerator|ShowBase
name|ShowBase
init|=
literal|0x80
block|,
DECL|enumerator|UppercaseBase
name|UppercaseBase
init|=
literal|0x100
block|,
DECL|enumerator|ForcePoint
name|ForcePoint
init|=
name|Alternate
block|}
enum|;
DECL|enum|GroupSeparatorMode
enum|enum
name|GroupSeparatorMode
block|{
DECL|enumerator|FailOnGroupSeparators
name|FailOnGroupSeparators
block|,
DECL|enumerator|ParseGroupSeparators
name|ParseGroupSeparators
block|}
enum|;
specifier|static
name|QString
name|doubleToString
parameter_list|(
specifier|const
name|QChar
name|zero
parameter_list|,
specifier|const
name|QChar
name|plus
parameter_list|,
specifier|const
name|QChar
name|minus
parameter_list|,
specifier|const
name|QChar
name|exponent
parameter_list|,
specifier|const
name|QChar
name|group
parameter_list|,
specifier|const
name|QChar
name|decimal
parameter_list|,
name|double
name|d
parameter_list|,
name|int
name|precision
parameter_list|,
name|DoubleForm
name|form
parameter_list|,
name|int
name|width
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
specifier|static
name|QString
name|longLongToString
parameter_list|(
specifier|const
name|QChar
name|zero
parameter_list|,
specifier|const
name|QChar
name|group
parameter_list|,
specifier|const
name|QChar
name|plus
parameter_list|,
specifier|const
name|QChar
name|minus
parameter_list|,
name|qint64
name|l
parameter_list|,
name|int
name|precision
parameter_list|,
name|int
name|base
parameter_list|,
name|int
name|width
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
specifier|static
name|QString
name|unsLongLongToString
parameter_list|(
specifier|const
name|QChar
name|zero
parameter_list|,
specifier|const
name|QChar
name|group
parameter_list|,
specifier|const
name|QChar
name|plus
parameter_list|,
name|quint64
name|l
parameter_list|,
name|int
name|precision
parameter_list|,
name|int
name|base
parameter_list|,
name|int
name|width
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
name|QString
name|doubleToString
argument_list|(
name|double
name|d
argument_list|,
name|int
name|precision
operator|=
operator|-
literal|1
argument_list|,
name|DoubleForm
name|form
operator|=
name|DFSignificantDigits
argument_list|,
name|int
name|width
operator|=
operator|-
literal|1
argument_list|,
name|unsigned
name|flags
operator|=
name|NoFlags
argument_list|)
decl|const
decl_stmt|;
name|QString
name|longLongToString
argument_list|(
name|qint64
name|l
argument_list|,
name|int
name|precision
operator|=
operator|-
literal|1
argument_list|,
name|int
name|base
operator|=
literal|10
argument_list|,
name|int
name|width
operator|=
operator|-
literal|1
argument_list|,
name|unsigned
name|flags
operator|=
name|NoFlags
argument_list|)
decl|const
decl_stmt|;
name|QString
name|unsLongLongToString
argument_list|(
name|quint64
name|l
argument_list|,
name|int
name|precision
operator|=
operator|-
literal|1
argument_list|,
name|int
name|base
operator|=
literal|10
argument_list|,
name|int
name|width
operator|=
operator|-
literal|1
argument_list|,
name|unsigned
name|flags
operator|=
name|NoFlags
argument_list|)
decl|const
decl_stmt|;
name|double
name|stringToDouble
argument_list|(
specifier|const
name|QString
operator|&
name|num
argument_list|,
name|bool
operator|*
name|ok
argument_list|,
name|GroupSeparatorMode
name|group_sep_mode
argument_list|)
decl|const
decl_stmt|;
name|qint64
name|stringToLongLong
argument_list|(
specifier|const
name|QString
operator|&
name|num
argument_list|,
name|int
name|base
argument_list|,
name|bool
operator|*
name|ok
argument_list|,
name|GroupSeparatorMode
name|group_sep_mode
argument_list|)
decl|const
decl_stmt|;
name|quint64
name|stringToUnsLongLong
argument_list|(
specifier|const
name|QString
operator|&
name|num
argument_list|,
name|int
name|base
argument_list|,
name|bool
operator|*
name|ok
argument_list|,
name|GroupSeparatorMode
name|group_sep_mode
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|double
name|bytearrayToDouble
parameter_list|(
specifier|const
name|char
modifier|*
name|num
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|,
name|bool
modifier|*
name|overflow
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|qint64
name|bytearrayToLongLong
parameter_list|(
specifier|const
name|char
modifier|*
name|num
parameter_list|,
name|int
name|base
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|,
name|bool
modifier|*
name|overflow
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|quint64
name|bytearrayToUnsLongLong
parameter_list|(
specifier|const
name|char
modifier|*
name|num
parameter_list|,
name|int
name|base
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
DECL|typedef|CharBuff
typedef|typedef
name|QVarLengthArray
operator|<
name|char
operator|,
literal|256
operator|>
name|CharBuff
expr_stmt|;
name|bool
name|numberToCLocale
argument_list|(
specifier|const
name|QString
operator|&
name|num
argument_list|,
name|GroupSeparatorMode
name|group_sep_mode
argument_list|,
name|CharBuff
operator|*
name|result
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|char
name|digitToCLocale
argument_list|(
specifier|const
name|QChar
operator|&
name|c
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|void
name|updateSystemPrivate
parameter_list|()
function_decl|;
DECL|enum|NumberMode
DECL|enumerator|IntegerMode
DECL|enumerator|DoubleStandardMode
DECL|enumerator|DoubleScientificMode
enum|enum
name|NumberMode
block|{
name|IntegerMode
block|,
name|DoubleStandardMode
block|,
name|DoubleScientificMode
block|}
enum|;
name|bool
name|validateChars
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|,
name|NumberMode
name|numMode
argument_list|,
name|QByteArray
operator|*
name|buff
argument_list|,
name|int
name|decDigits
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
name|QString
name|dateTimeToString
argument_list|(
specifier|const
name|QString
operator|&
name|format
argument_list|,
specifier|const
name|QDate
operator|*
name|date
argument_list|,
specifier|const
name|QTime
operator|*
name|time
argument_list|,
specifier|const
name|QLocale
operator|*
name|q
argument_list|)
decl|const
decl_stmt|;
DECL|variable|m_language_id
DECL|variable|m_script_id
DECL|variable|m_country_id
name|quint16
name|m_language_id
decl_stmt|,
name|m_script_id
decl_stmt|,
name|m_country_id
decl_stmt|;
DECL|variable|m_decimal
DECL|variable|m_group
DECL|variable|m_list
DECL|variable|m_percent
name|quint16
name|m_decimal
decl_stmt|,
name|m_group
decl_stmt|,
name|m_list
decl_stmt|,
name|m_percent
decl_stmt|,
DECL|variable|m_zero
DECL|variable|m_minus
DECL|variable|m_plus
DECL|variable|m_exponential
name|m_zero
decl_stmt|,
name|m_minus
decl_stmt|,
name|m_plus
decl_stmt|,
name|m_exponential
decl_stmt|;
DECL|variable|m_quotation_start
DECL|variable|m_quotation_end
name|quint16
name|m_quotation_start
decl_stmt|,
name|m_quotation_end
decl_stmt|;
DECL|variable|m_alternate_quotation_start
DECL|variable|m_alternate_quotation_end
name|quint16
name|m_alternate_quotation_start
decl_stmt|,
name|m_alternate_quotation_end
decl_stmt|;
DECL|variable|m_list_pattern_part_start_idx
DECL|variable|m_list_pattern_part_start_size
name|quint16
name|m_list_pattern_part_start_idx
decl_stmt|,
name|m_list_pattern_part_start_size
decl_stmt|;
DECL|variable|m_list_pattern_part_mid_idx
DECL|variable|m_list_pattern_part_mid_size
name|quint16
name|m_list_pattern_part_mid_idx
decl_stmt|,
name|m_list_pattern_part_mid_size
decl_stmt|;
DECL|variable|m_list_pattern_part_end_idx
DECL|variable|m_list_pattern_part_end_size
name|quint16
name|m_list_pattern_part_end_idx
decl_stmt|,
name|m_list_pattern_part_end_size
decl_stmt|;
DECL|variable|m_list_pattern_part_two_idx
DECL|variable|m_list_pattern_part_two_size
name|quint16
name|m_list_pattern_part_two_idx
decl_stmt|,
name|m_list_pattern_part_two_size
decl_stmt|;
DECL|variable|m_short_date_format_idx
DECL|variable|m_short_date_format_size
name|quint16
name|m_short_date_format_idx
decl_stmt|,
name|m_short_date_format_size
decl_stmt|;
DECL|variable|m_long_date_format_idx
DECL|variable|m_long_date_format_size
name|quint16
name|m_long_date_format_idx
decl_stmt|,
name|m_long_date_format_size
decl_stmt|;
DECL|variable|m_short_time_format_idx
DECL|variable|m_short_time_format_size
name|quint16
name|m_short_time_format_idx
decl_stmt|,
name|m_short_time_format_size
decl_stmt|;
DECL|variable|m_long_time_format_idx
DECL|variable|m_long_time_format_size
name|quint16
name|m_long_time_format_idx
decl_stmt|,
name|m_long_time_format_size
decl_stmt|;
DECL|variable|m_standalone_short_month_names_idx
DECL|variable|m_standalone_short_month_names_size
name|quint16
name|m_standalone_short_month_names_idx
decl_stmt|,
name|m_standalone_short_month_names_size
decl_stmt|;
DECL|variable|m_standalone_long_month_names_idx
DECL|variable|m_standalone_long_month_names_size
name|quint16
name|m_standalone_long_month_names_idx
decl_stmt|,
name|m_standalone_long_month_names_size
decl_stmt|;
DECL|variable|m_standalone_narrow_month_names_idx
DECL|variable|m_standalone_narrow_month_names_size
name|quint16
name|m_standalone_narrow_month_names_idx
decl_stmt|,
name|m_standalone_narrow_month_names_size
decl_stmt|;
DECL|variable|m_short_month_names_idx
DECL|variable|m_short_month_names_size
name|quint16
name|m_short_month_names_idx
decl_stmt|,
name|m_short_month_names_size
decl_stmt|;
DECL|variable|m_long_month_names_idx
DECL|variable|m_long_month_names_size
name|quint16
name|m_long_month_names_idx
decl_stmt|,
name|m_long_month_names_size
decl_stmt|;
DECL|variable|m_narrow_month_names_idx
DECL|variable|m_narrow_month_names_size
name|quint16
name|m_narrow_month_names_idx
decl_stmt|,
name|m_narrow_month_names_size
decl_stmt|;
DECL|variable|m_standalone_short_day_names_idx
DECL|variable|m_standalone_short_day_names_size
name|quint16
name|m_standalone_short_day_names_idx
decl_stmt|,
name|m_standalone_short_day_names_size
decl_stmt|;
DECL|variable|m_standalone_long_day_names_idx
DECL|variable|m_standalone_long_day_names_size
name|quint16
name|m_standalone_long_day_names_idx
decl_stmt|,
name|m_standalone_long_day_names_size
decl_stmt|;
DECL|variable|m_standalone_narrow_day_names_idx
DECL|variable|m_standalone_narrow_day_names_size
name|quint16
name|m_standalone_narrow_day_names_idx
decl_stmt|,
name|m_standalone_narrow_day_names_size
decl_stmt|;
DECL|variable|m_short_day_names_idx
DECL|variable|m_short_day_names_size
name|quint16
name|m_short_day_names_idx
decl_stmt|,
name|m_short_day_names_size
decl_stmt|;
DECL|variable|m_long_day_names_idx
DECL|variable|m_long_day_names_size
name|quint16
name|m_long_day_names_idx
decl_stmt|,
name|m_long_day_names_size
decl_stmt|;
DECL|variable|m_narrow_day_names_idx
DECL|variable|m_narrow_day_names_size
name|quint16
name|m_narrow_day_names_idx
decl_stmt|,
name|m_narrow_day_names_size
decl_stmt|;
DECL|variable|m_am_idx
DECL|variable|m_am_size
name|quint16
name|m_am_idx
decl_stmt|,
name|m_am_size
decl_stmt|;
DECL|variable|m_pm_idx
DECL|variable|m_pm_size
name|quint16
name|m_pm_idx
decl_stmt|,
name|m_pm_size
decl_stmt|;
DECL|variable|m_currency_iso_code
name|char
name|m_currency_iso_code
index|[
literal|3
index|]
decl_stmt|;
DECL|variable|m_currency_symbol_idx
DECL|variable|m_currency_symbol_size
name|quint16
name|m_currency_symbol_idx
decl_stmt|,
name|m_currency_symbol_size
decl_stmt|;
DECL|variable|m_currency_display_name_idx
DECL|variable|m_currency_display_name_size
name|quint16
name|m_currency_display_name_idx
decl_stmt|,
name|m_currency_display_name_size
decl_stmt|;
DECL|variable|m_currency_format_idx
DECL|variable|m_currency_format_size
name|quint8
name|m_currency_format_idx
decl_stmt|,
name|m_currency_format_size
decl_stmt|;
DECL|variable|m_currency_negative_format_idx
DECL|variable|m_currency_negative_format_size
name|quint8
name|m_currency_negative_format_idx
decl_stmt|,
name|m_currency_negative_format_size
decl_stmt|;
DECL|variable|m_language_endonym_idx
DECL|variable|m_language_endonym_size
name|quint16
name|m_language_endonym_idx
decl_stmt|,
name|m_language_endonym_size
decl_stmt|;
DECL|variable|m_country_endonym_idx
DECL|variable|m_country_endonym_size
name|quint16
name|m_country_endonym_idx
decl_stmt|,
name|m_country_endonym_size
decl_stmt|;
DECL|variable|m_currency_digits
name|quint16
name|m_currency_digits
range|:
literal|2
decl_stmt|;
DECL|variable|m_currency_rounding
name|quint16
name|m_currency_rounding
range|:
literal|3
decl_stmt|;
DECL|variable|m_first_day_of_week
name|quint16
name|m_first_day_of_week
range|:
literal|3
decl_stmt|;
DECL|variable|m_weekend_start
name|quint16
name|m_weekend_start
range|:
literal|3
decl_stmt|;
DECL|variable|m_weekend_end
name|quint16
name|m_weekend_end
range|:
literal|3
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
specifier|inline
name|char
name|QLocalePrivate
operator|::
name|digitToCLocale
argument_list|(
argument|const QChar&in
argument_list|)
specifier|const
block|{
specifier|const
name|QChar
name|_zero
operator|=
name|zero
argument_list|()
block|;
specifier|const
name|QChar
name|_group
operator|=
name|group
argument_list|()
block|;
specifier|const
name|ushort
name|zeroUnicode
operator|=
name|_zero
operator|.
name|unicode
argument_list|()
block|;
specifier|const
name|ushort
name|tenUnicode
operator|=
name|zeroUnicode
operator|+
literal|10
block|;
if|if
condition|(
name|in
operator|.
name|unicode
argument_list|()
operator|>=
name|zeroUnicode
operator|&&
name|in
operator|.
name|unicode
argument_list|()
operator|<
name|tenUnicode
condition|)
return|return
literal|'0'
operator|+
name|in
operator|.
name|unicode
argument_list|()
operator|-
name|zeroUnicode
return|;
end_expr_stmt
begin_if
if|if
condition|(
name|in
operator|.
name|unicode
argument_list|()
operator|>=
literal|'0'
operator|&&
name|in
operator|.
name|unicode
argument_list|()
operator|<=
literal|'9'
condition|)
return|return
name|in
operator|.
name|toLatin1
argument_list|()
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|plus
argument_list|()
condition|)
return|return
literal|'+'
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|minus
argument_list|()
condition|)
return|return
literal|'-'
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|decimal
argument_list|()
condition|)
return|return
literal|'.'
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|group
argument_list|()
condition|)
return|return
literal|','
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|exponential
argument_list|()
operator|||
name|in
operator|==
name|exponential
argument_list|()
operator|.
name|toUpper
argument_list|()
condition|)
return|return
literal|'e'
return|;
end_if
begin_comment
comment|// In several languages group() is the char 0xA0, which looks like a space.
end_comment
begin_comment
comment|// People use a regular space instead of it and complain it doesn't work.
end_comment
begin_if
if|if
condition|(
name|_group
operator|.
name|unicode
argument_list|()
operator|==
literal|0xA0
operator|&&
name|in
operator|.
name|unicode
argument_list|()
operator|==
literal|' '
condition|)
return|return
literal|','
return|;
end_if
begin_return
return|return
literal|0
return|;
end_return
begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SYSTEMLOCALE
argument_list|)
end_if
begin_macro
unit|class
name|QEnvironmentChangeNotifier
end_macro
begin_block
block|{
name|public
label|:
name|QEnvironmentChangeNotifier
argument_list|()
expr_stmt|;
operator|~
name|QEnvironmentChangeNotifier
argument_list|()
expr_stmt|;
specifier|static
name|TInt
name|localeChanged
parameter_list|(
name|TAny
modifier|*
name|data
parameter_list|)
function_decl|;
name|private
label|:
name|CEnvironmentChangeNotifier
modifier|*
name|iChangeNotifier
decl_stmt|;
block|}
end_block
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|QString
name|qt_readEscapedFormatString
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|,
name|int
modifier|*
name|idx
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|qt_splitLocaleName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|QString
modifier|&
name|lang
parameter_list|,
name|QString
modifier|&
name|script
parameter_list|,
name|QString
modifier|&
name|cntry
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|int
name|qt_repeatCount
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|,
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QStringRef
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QList
operator|<
name|Qt
operator|::
name|DayOfWeek
operator|>
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLOCALE_P_H
end_comment
end_unit
