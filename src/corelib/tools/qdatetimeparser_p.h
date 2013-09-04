begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDATETIMEPARSER_P_H
end_ifndef
begin_define
DECL|macro|QDATETIMEPARSER_P_H
define|#
directive|define
name|QDATETIMEPARSER_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qatomic.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qlocale.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
end_ifndef
begin_include
include|#
directive|include
file|"QtCore/qvariant.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"QtCore/qvector.h"
end_include
begin_define
DECL|macro|QDATETIMEEDIT_TIME_MIN
define|#
directive|define
name|QDATETIMEEDIT_TIME_MIN
value|QTime(0, 0, 0, 0)
end_define
begin_define
DECL|macro|QDATETIMEEDIT_TIME_MAX
define|#
directive|define
name|QDATETIMEEDIT_TIME_MAX
value|QTime(23, 59, 59, 999)
end_define
begin_define
DECL|macro|QDATETIMEEDIT_DATE_MIN
define|#
directive|define
name|QDATETIMEEDIT_DATE_MIN
value|QDate(100, 1, 1)
end_define
begin_define
DECL|macro|QDATETIMEEDIT_COMPAT_DATE_MIN
define|#
directive|define
name|QDATETIMEEDIT_COMPAT_DATE_MIN
value|QDate(1752, 9, 14)
end_define
begin_define
DECL|macro|QDATETIMEEDIT_DATE_MAX
define|#
directive|define
name|QDATETIMEEDIT_DATE_MAX
value|QDate(7999, 12, 31)
end_define
begin_define
DECL|macro|QDATETIMEEDIT_DATETIME_MIN
define|#
directive|define
name|QDATETIMEEDIT_DATETIME_MIN
value|QDateTime(QDATETIMEEDIT_DATE_MIN, QDATETIMEEDIT_TIME_MIN)
end_define
begin_define
DECL|macro|QDATETIMEEDIT_COMPAT_DATETIME_MIN
define|#
directive|define
name|QDATETIMEEDIT_COMPAT_DATETIME_MIN
value|QDateTime(QDATETIMEEDIT_COMPAT_DATE_MIN, QDATETIMEEDIT_TIME_MIN)
end_define
begin_define
DECL|macro|QDATETIMEEDIT_DATETIME_MAX
define|#
directive|define
name|QDATETIMEEDIT_DATETIME_MAX
value|QDateTime(QDATETIMEEDIT_DATE_MAX, QDATETIMEEDIT_TIME_MAX)
end_define
begin_define
DECL|macro|QDATETIMEEDIT_DATE_INITIAL
define|#
directive|define
name|QDATETIMEEDIT_DATE_INITIAL
value|QDate(2000, 1, 1)
end_define
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|class
name|Q_CORE_EXPORT
name|QDateTimeParser
block|{
name|public
label|:
enum|enum
name|Context
block|{
name|FromString
block|,
name|DateTimeEdit
block|}
enum|;
name|QDateTimeParser
argument_list|(
argument|QVariant::Type t
argument_list|,
argument|Context ctx
argument_list|)
block|:
name|currentSectionIndex
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|display
argument_list|(
literal|0
argument_list|)
operator|,
name|cachedDay
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|parserType
argument_list|(
name|t
argument_list|)
operator|,
name|fixday
argument_list|(
name|false
argument_list|)
operator|,
name|spec
argument_list|(
name|Qt
operator|::
name|LocalTime
argument_list|)
operator|,
name|context
argument_list|(
argument|ctx
argument_list|)
block|{
name|defaultLocale
operator|=
name|QLocale
operator|::
name|system
argument_list|()
block|;
name|first
operator|.
name|type
operator|=
name|FirstSection
block|;
name|first
operator|.
name|pos
operator|=
operator|-
literal|1
block|;
name|first
operator|.
name|count
operator|=
operator|-
literal|1
block|;
name|first
operator|.
name|zeroesAdded
operator|=
literal|0
block|;
name|last
operator|.
name|type
operator|=
name|FirstSection
block|;
name|last
operator|.
name|pos
operator|=
operator|-
literal|1
block|;
name|last
operator|.
name|count
operator|=
operator|-
literal|1
block|;
name|last
operator|.
name|zeroesAdded
operator|=
literal|0
block|;
name|none
operator|.
name|type
operator|=
name|NoSection
block|;
name|none
operator|.
name|pos
operator|=
operator|-
literal|1
block|;
name|none
operator|.
name|count
operator|=
operator|-
literal|1
block|;
name|none
operator|.
name|zeroesAdded
operator|=
literal|0
block|;     }
name|virtual
operator|~
name|QDateTimeParser
argument_list|()
block|{}
expr|enum
block|{
name|Neither
operator|=
operator|-
literal|1
block|,
name|AM
operator|=
literal|0
block|,
name|PM
operator|=
literal|1
block|,
name|PossibleAM
operator|=
literal|2
block|,
name|PossiblePM
operator|=
literal|3
block|,
name|PossibleBoth
operator|=
literal|4
block|}
expr_stmt|;
enum|enum
name|Section
block|{
name|NoSection
init|=
literal|0x00000
block|,
name|AmPmSection
init|=
literal|0x00001
block|,
name|MSecSection
init|=
literal|0x00002
block|,
name|SecondSection
init|=
literal|0x00004
block|,
name|MinuteSection
init|=
literal|0x00008
block|,
name|Hour12Section
init|=
literal|0x00010
block|,
name|Hour24Section
init|=
literal|0x00020
block|,
name|TimeSectionMask
init|=
operator|(
name|AmPmSection
operator||
name|MSecSection
operator||
name|SecondSection
operator||
name|MinuteSection
operator||
name|Hour12Section
operator||
name|Hour24Section
operator|)
block|,
name|Internal
init|=
literal|0x10000
block|,
name|DaySection
init|=
literal|0x00100
block|,
name|MonthSection
init|=
literal|0x00200
block|,
name|YearSection
init|=
literal|0x00400
block|,
name|YearSection2Digits
init|=
literal|0x00800
block|,
name|DayOfWeekSectionShort
init|=
literal|0x01000
block|,
name|DayOfWeekSectionLong
init|=
literal|0x20000
block|,
name|DateSectionMask
init|=
operator|(
name|DaySection
operator||
name|MonthSection
operator||
name|YearSection
operator||
name|YearSection2Digits
operator||
name|DayOfWeekSectionShort
operator||
name|DayOfWeekSectionLong
operator|)
block|,
name|FirstSection
init|=
literal|0x02000
operator||
name|Internal
block|,
name|LastSection
init|=
literal|0x04000
operator||
name|Internal
block|,
name|CalendarPopupSection
init|=
literal|0x08000
operator||
name|Internal
block|,
name|NoSectionIndex
init|=
operator|-
literal|1
block|,
name|FirstSectionIndex
init|=
operator|-
literal|2
block|,
name|LastSectionIndex
init|=
operator|-
literal|3
block|,
name|CalendarPopupIndex
init|=
operator|-
literal|4
block|}
enum|;
comment|// duplicated from qdatetimeedit.h
name|Q_DECLARE_FLAGS
argument_list|(
argument|Sections
argument_list|,
argument|Section
argument_list|)
struct|struct
name|SectionNode
block|{
name|Section
name|type
decl_stmt|;
name|mutable
name|int
name|pos
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|zeroesAdded
decl_stmt|;
block|}
struct|;
enum|enum
name|State
block|{
comment|// duplicated from QValidator
name|Invalid
block|,
name|Intermediate
block|,
name|Acceptable
block|}
enum|;
struct|struct
name|StateNode
block|{
name|StateNode
argument_list|()
operator|:
name|state
argument_list|(
name|Invalid
argument_list|)
operator|,
name|conflicts
argument_list|(
argument|false
argument_list|)
block|{}
name|QString
name|input
expr_stmt|;
name|State
name|state
decl_stmt|;
name|bool
name|conflicts
decl_stmt|;
name|QDateTime
name|value
decl_stmt|;
block|}
struct|;
enum|enum
name|AmPm
block|{
name|AmText
block|,
name|PmText
block|}
enum|;
enum|enum
name|Case
block|{
name|UpperCase
block|,
name|LowerCase
block|}
enum|;
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
name|StateNode
name|parse
argument_list|(
name|QString
operator|&
name|input
argument_list|,
name|int
operator|&
name|cursorPosition
argument_list|,
specifier|const
name|QDateTime
operator|&
name|currentValue
argument_list|,
name|bool
name|fixup
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|int
name|sectionMaxSize
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|int
name|sectionSize
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|int
name|sectionMaxSize
argument_list|(
name|Section
name|s
argument_list|,
name|int
name|count
argument_list|)
decl|const
decl_stmt|;
name|int
name|sectionPos
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|int
name|sectionPos
argument_list|(
specifier|const
name|SectionNode
operator|&
name|sn
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|SectionNode
modifier|&
name|sectionNode
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|Section
name|sectionType
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QString
name|sectionText
argument_list|(
name|int
name|sectionIndex
argument_list|)
decl|const
decl_stmt|;
name|QString
name|sectionText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|int
name|sectionIndex
argument_list|,
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|int
name|getDigit
argument_list|(
specifier|const
name|QDateTime
operator|&
name|dt
argument_list|,
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|bool
name|setDigit
argument_list|(
name|QDateTime
operator|&
name|t
argument_list|,
name|int
name|index
argument_list|,
name|int
name|newval
argument_list|)
decl|const
decl_stmt|;
name|int
name|parseSection
argument_list|(
specifier|const
name|QDateTime
operator|&
name|currentValue
argument_list|,
name|int
name|sectionIndex
argument_list|,
name|QString
operator|&
name|txt
argument_list|,
name|int
operator|&
name|cursorPosition
argument_list|,
name|int
name|index
argument_list|,
name|QDateTimeParser
operator|::
name|State
operator|&
name|state
argument_list|,
name|int
operator|*
name|used
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|int
name|absoluteMax
argument_list|(
name|int
name|index
argument_list|,
specifier|const
name|QDateTime
operator|&
name|value
operator|=
name|QDateTime
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|int
name|absoluteMin
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|bool
name|parseFormat
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
name|bool
name|fromString
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|QDate
operator|*
name|date
argument_list|,
name|QTime
operator|*
name|time
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_TEXTDATE
name|int
name|findMonth
argument_list|(
specifier|const
name|QString
operator|&
name|str1
argument_list|,
name|int
name|monthstart
argument_list|,
name|int
name|sectionIndex
argument_list|,
name|QString
operator|*
name|monthName
operator|=
literal|0
argument_list|,
name|int
operator|*
name|used
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|int
name|findDay
argument_list|(
specifier|const
name|QString
operator|&
name|str1
argument_list|,
name|int
name|intDaystart
argument_list|,
name|int
name|sectionIndex
argument_list|,
name|QString
operator|*
name|dayName
operator|=
literal|0
argument_list|,
name|int
operator|*
name|used
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|int
name|findAmPm
argument_list|(
name|QString
operator|&
name|str1
argument_list|,
name|int
name|index
argument_list|,
name|int
operator|*
name|used
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|int
name|maxChange
argument_list|(
name|int
name|s
argument_list|)
decl|const
decl_stmt|;
name|bool
name|potentialValue
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|,
name|int
name|min
argument_list|,
name|int
name|max
argument_list|,
name|int
name|index
argument_list|,
specifier|const
name|QDateTime
operator|&
name|currentValue
argument_list|,
name|int
name|insert
argument_list|)
decl|const
decl_stmt|;
name|bool
name|skipToNextSection
argument_list|(
name|int
name|section
argument_list|,
specifier|const
name|QDateTime
operator|&
name|current
argument_list|,
specifier|const
name|QString
operator|&
name|sectionText
argument_list|)
decl|const
decl_stmt|;
name|QString
name|sectionName
argument_list|(
name|int
name|s
argument_list|)
decl|const
decl_stmt|;
name|QString
name|stateName
argument_list|(
name|int
name|s
argument_list|)
decl|const
decl_stmt|;
name|QString
name|sectionFormat
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QString
name|sectionFormat
argument_list|(
name|Section
name|s
argument_list|,
name|int
name|count
argument_list|)
decl|const
decl_stmt|;
enum|enum
name|FieldInfoFlag
block|{
name|Numeric
init|=
literal|0x01
block|,
name|FixedWidth
init|=
literal|0x02
block|,
name|AllowPartial
init|=
literal|0x04
block|,
name|Fraction
init|=
literal|0x08
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|FieldInfo
argument_list|,
argument|FieldInfoFlag
argument_list|)
name|FieldInfo
name|fieldInfo
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QDateTime
name|getMinimum
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QDateTime
name|getMaximum
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|cursorPosition
argument_list|()
specifier|const
block|{
return|return
operator|-
literal|1
return|;
block|}
name|virtual
name|QString
name|displayText
argument_list|()
specifier|const
block|{
return|return
name|text
return|;
block|}
name|virtual
name|QString
name|getAmPmText
argument_list|(
name|AmPm
name|ap
argument_list|,
name|Case
name|cs
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QLocale
name|locale
argument_list|()
specifier|const
block|{
return|return
name|defaultLocale
return|;
block|}
name|mutable
name|int
name|currentSectionIndex
decl_stmt|;
name|Sections
name|display
decl_stmt|;
comment|/*         This stores the stores the most recently selected day.         It is useful when considering the following scenario:          1. Date is: 31/01/2000         2. User increments month: 29/02/2000         3. User increments month: 31/03/2000          At step 1, cachedDay stores 31. At step 2, the 31 is invalid for February, so the cachedDay is not updated.         At step 3, the the month is changed to March, for which 31 is a valid day. Since 29< 31, the day is set to cachedDay.         This is good for when users have selected their desired day and are scrolling up or down in the month or year section         and do not want smaller months (or non-leap years) to alter the day that they chose.     */
name|mutable
name|int
name|cachedDay
decl_stmt|;
name|mutable
name|QString
name|text
decl_stmt|;
name|QVector
operator|<
name|SectionNode
operator|>
name|sectionNodes
expr_stmt|;
name|SectionNode
name|first
decl_stmt|,
name|last
decl_stmt|,
name|none
decl_stmt|,
name|popup
decl_stmt|;
name|QStringList
name|separators
decl_stmt|;
name|QString
name|displayFormat
decl_stmt|;
name|QLocale
name|defaultLocale
decl_stmt|;
name|QVariant
operator|::
name|Type
name|parserType
expr_stmt|;
name|bool
name|fixday
decl_stmt|;
name|Qt
operator|::
name|TimeSpec
name|spec
expr_stmt|;
comment|// spec if used by QDateTimeEdit
name|Context
name|context
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QDateTimeParser
operator|::
name|SectionNode
operator|&
name|s1
operator|,
specifier|const
name|QDateTimeParser
operator|::
name|SectionNode
operator|&
name|s2
operator|)
expr_stmt|;
end_expr_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QDateTimeParser::Sections
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QDateTimeParser::FieldInfo
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_BOOTSTRAPPED
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDATETIME_P_H
end_comment
end_unit