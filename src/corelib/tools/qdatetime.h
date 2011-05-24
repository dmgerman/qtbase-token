begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDATETIME_H
end_ifndef
begin_define
DECL|macro|QDATETIME_H
define|#
directive|define
name|QDATETIME_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|Q_CORE_EXPORT
name|QDate
decl_stmt|{ public:     enum MonthNameType
block|{
name|DateFormat
operator|=
literal|0
operator|,
name|StandaloneFormat
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_label
name|public
label|:
end_label
begin_macro
name|QDate
argument_list|()
end_macro
begin_block
block|{
name|jd
operator|=
literal|0
expr_stmt|;
block|}
end_block
begin_macro
name|QDate
argument_list|(
argument|int y
argument_list|,
argument|int m
argument_list|,
argument|int d
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|jd
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|year
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|month
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|day
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|dayOfWeek
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|dayOfYear
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|daysInMonth
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|daysInYear
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|weekNumber
argument_list|(
name|int
operator|*
name|yearNum
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTDATE
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_function
specifier|static
name|QT3_SUPPORT
name|QString
name|monthName
parameter_list|(
name|int
name|month
parameter_list|)
block|{
return|return
name|shortMonthName
argument_list|(
name|month
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|QT3_SUPPORT
name|QString
name|dayName
parameter_list|(
name|int
name|weekday
parameter_list|)
block|{
return|return
name|shortDayName
argument_list|(
name|weekday
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ### Qt 5: merge these functions.
end_comment
begin_function_decl
specifier|static
name|QString
name|shortMonthName
parameter_list|(
name|int
name|month
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|shortMonthName
parameter_list|(
name|int
name|month
parameter_list|,
name|MonthNameType
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|shortDayName
parameter_list|(
name|int
name|weekday
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|shortDayName
parameter_list|(
name|int
name|weekday
parameter_list|,
name|MonthNameType
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|longMonthName
parameter_list|(
name|int
name|month
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|longMonthName
parameter_list|(
name|int
name|month
parameter_list|,
name|MonthNameType
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|longDayName
parameter_list|(
name|int
name|weekday
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|longDayName
parameter_list|(
name|int
name|weekday
parameter_list|,
name|MonthNameType
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTDATE
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
end_ifndef
begin_decl_stmt
name|QString
name|toString
argument_list|(
name|Qt
operator|::
name|DateFormat
name|f
operator|=
name|Qt
operator|::
name|TextDate
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|toString
argument_list|(
specifier|const
name|QString
operator|&
name|format
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|bool
name|setYMD
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|m
parameter_list|,
name|int
name|d
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|setDate
parameter_list|(
name|int
name|year
parameter_list|,
name|int
name|month
parameter_list|,
name|int
name|day
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|getDate
parameter_list|(
name|int
modifier|*
name|year
parameter_list|,
name|int
modifier|*
name|month
parameter_list|,
name|int
modifier|*
name|day
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QDate
name|addDays
argument_list|(
name|int
name|days
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QDate
name|addMonths
argument_list|(
name|int
name|months
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QDate
name|addYears
argument_list|(
name|int
name|years
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|daysTo
argument_list|(
specifier|const
name|QDate
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QDate
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|jd
operator|==
name|other
operator|.
name|jd
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QDate
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|jd
operator|!=
name|other
operator|.
name|jd
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QDate
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|jd
operator|<
name|other
operator|.
name|jd
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|QDate
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|jd
operator|<=
name|other
operator|.
name|jd
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|>
operator|(
specifier|const
name|QDate
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|jd
operator|>
name|other
operator|.
name|jd
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|QDate
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|jd
operator|>=
name|other
operator|.
name|jd
return|;
block|}
end_expr_stmt
begin_function_decl
specifier|static
name|QDate
name|currentDate
parameter_list|()
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
end_ifndef
begin_decl_stmt
specifier|static
name|QDate
name|fromString
argument_list|(
specifier|const
name|QString
operator|&
name|s
argument_list|,
name|Qt
operator|::
name|DateFormat
name|f
operator|=
name|Qt
operator|::
name|TextDate
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|QDate
name|fromString
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|,
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|bool
name|isValid
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|m
parameter_list|,
name|int
name|d
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|isLeapYear
parameter_list|(
name|int
name|year
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_function
specifier|inline
specifier|static
name|QT3_SUPPORT
name|bool
name|leapYear
parameter_list|(
name|int
name|year
parameter_list|)
block|{
return|return
name|isLeapYear
argument_list|(
name|year
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ### Qt 5: remove these two functions
end_comment
begin_function_decl
specifier|static
name|uint
name|gregorianToJulian
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|m
parameter_list|,
name|int
name|d
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|julianToGregorian
parameter_list|(
name|uint
name|jd
parameter_list|,
name|int
modifier|&
name|y
parameter_list|,
name|int
modifier|&
name|m
parameter_list|,
name|int
modifier|&
name|d
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_decl_stmt
specifier|static
name|QT3_SUPPORT
name|QDate
name|currentDate
argument_list|(
name|Qt
operator|::
name|TimeSpec
name|spec
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
specifier|inline
name|QDate
name|fromJulianDay
parameter_list|(
name|int
name|jd
parameter_list|)
block|{
name|QDate
name|d
decl_stmt|;
name|d
operator|.
name|jd
operator|=
name|jd
expr_stmt|;
return|return
name|d
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|int
name|toJulianDay
argument_list|()
specifier|const
block|{
return|return
name|jd
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|uint
name|jd
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QDateTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QDateTimePrivate
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|friend
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QDate
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QDate
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|};
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QDate
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QTime
block|{
name|public
label|:
name|QTime
argument_list|()
operator|:
name|mds
argument_list|(
name|NullTime
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|,
name|startTick
argument_list|(
argument|NullTime
argument_list|)
endif|#
directive|endif
block|{}
name|QTime
argument_list|(
argument|int h
argument_list|,
argument|int m
argument_list|,
argument|int s =
literal|0
argument_list|,
argument|int ms =
literal|0
argument_list|)
expr_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|mds
operator|==
name|NullTime
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|int
name|hour
argument_list|()
specifier|const
expr_stmt|;
name|int
name|minute
argument_list|()
specifier|const
expr_stmt|;
name|int
name|second
argument_list|()
specifier|const
expr_stmt|;
name|int
name|msec
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
name|QString
name|toString
argument_list|(
name|Qt
operator|::
name|DateFormat
name|f
operator|=
name|Qt
operator|::
name|TextDate
argument_list|)
decl|const
decl_stmt|;
name|QString
name|toString
argument_list|(
specifier|const
name|QString
operator|&
name|format
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|bool
name|setHMS
parameter_list|(
name|int
name|h
parameter_list|,
name|int
name|m
parameter_list|,
name|int
name|s
parameter_list|,
name|int
name|ms
init|=
literal|0
parameter_list|)
function_decl|;
name|QTime
name|addSecs
argument_list|(
name|int
name|secs
argument_list|)
decl|const
decl_stmt|;
name|int
name|secsTo
argument_list|(
specifier|const
name|QTime
operator|&
argument_list|)
decl|const
decl_stmt|;
name|QTime
name|addMSecs
argument_list|(
name|int
name|ms
argument_list|)
decl|const
decl_stmt|;
name|int
name|msecsTo
argument_list|(
specifier|const
name|QTime
operator|&
argument_list|)
decl|const
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QTime
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|mds
operator|==
name|other
operator|.
name|mds
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QTime
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|mds
operator|!=
name|other
operator|.
name|mds
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QTime
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|mds
operator|<
name|other
operator|.
name|mds
return|;
block|}
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|QTime
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|mds
operator|<=
name|other
operator|.
name|mds
return|;
block|}
name|bool
name|operator
operator|>
operator|(
specifier|const
name|QTime
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|mds
operator|>
name|other
operator|.
name|mds
return|;
block|}
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|QTime
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|mds
operator|>=
name|other
operator|.
name|mds
return|;
block|}
specifier|static
name|QTime
name|currentTime
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
specifier|static
name|QTime
name|fromString
argument_list|(
specifier|const
name|QString
operator|&
name|s
argument_list|,
name|Qt
operator|::
name|DateFormat
name|f
operator|=
name|Qt
operator|::
name|TextDate
argument_list|)
decl_stmt|;
specifier|static
name|QTime
name|fromString
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|,
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|static
name|bool
name|isValid
parameter_list|(
name|int
name|h
parameter_list|,
name|int
name|m
parameter_list|,
name|int
name|s
parameter_list|,
name|int
name|ms
init|=
literal|0
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
specifier|static
name|QT3_SUPPORT
name|QTime
name|currentTime
argument_list|(
name|Qt
operator|::
name|TimeSpec
name|spec
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|void
name|start
parameter_list|()
function_decl|;
name|int
name|restart
parameter_list|()
function_decl|;
name|int
name|elapsed
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
enum|enum
name|TimeFlag
block|{
name|NullTime
init|=
operator|-
literal|1
block|}
enum|;
specifier|inline
name|int
name|ds
argument_list|()
specifier|const
block|{
return|return
name|mds
operator|==
operator|-
literal|1
operator|?
literal|0
operator|:
name|mds
return|;
block|}
name|int
name|mds
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|int
name|startTick
decl_stmt|;
endif|#
directive|endif
name|friend
name|class
name|QDateTime
decl_stmt|;
name|friend
name|class
name|QDateTimePrivate
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|friend
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QTime
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QTime
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QTime
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QDateTimePrivate
name|class
name|QDateTimePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QDateTime
block|{
name|public
label|:
name|QDateTime
argument_list|()
expr_stmt|;
name|explicit
name|QDateTime
parameter_list|(
specifier|const
name|QDate
modifier|&
parameter_list|)
function_decl|;
name|QDateTime
argument_list|(
argument|const QDate&
argument_list|,
argument|const QTime&
argument_list|,
argument|Qt::TimeSpec spec = Qt::LocalTime
argument_list|)
empty_stmt|;
name|QDateTime
argument_list|(
specifier|const
name|QDateTime
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QDateTime
argument_list|()
expr_stmt|;
name|QDateTime
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDateTime
operator|&
name|other
operator|)
decl_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|QDate
name|date
argument_list|()
specifier|const
expr_stmt|;
name|QTime
name|time
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|TimeSpec
name|timeSpec
argument_list|()
specifier|const
expr_stmt|;
name|qint64
name|toMSecsSinceEpoch
argument_list|()
specifier|const
expr_stmt|;
name|uint
name|toTime_t
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDate
parameter_list|(
specifier|const
name|QDate
modifier|&
name|date
parameter_list|)
function_decl|;
name|void
name|setTime
parameter_list|(
specifier|const
name|QTime
modifier|&
name|time
parameter_list|)
function_decl|;
name|void
name|setTimeSpec
argument_list|(
name|Qt
operator|::
name|TimeSpec
name|spec
argument_list|)
decl_stmt|;
name|void
name|setMSecsSinceEpoch
parameter_list|(
name|qint64
name|msecs
parameter_list|)
function_decl|;
name|void
name|setTime_t
parameter_list|(
name|uint
name|secsSince1Jan1970UTC
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
name|QString
name|toString
argument_list|(
name|Qt
operator|::
name|DateFormat
name|f
operator|=
name|Qt
operator|::
name|TextDate
argument_list|)
decl|const
decl_stmt|;
name|QString
name|toString
argument_list|(
specifier|const
name|QString
operator|&
name|format
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|QDateTime
name|addDays
argument_list|(
name|int
name|days
argument_list|)
decl|const
decl_stmt|;
name|QDateTime
name|addMonths
argument_list|(
name|int
name|months
argument_list|)
decl|const
decl_stmt|;
name|QDateTime
name|addYears
argument_list|(
name|int
name|years
argument_list|)
decl|const
decl_stmt|;
name|QDateTime
name|addSecs
argument_list|(
name|int
name|secs
argument_list|)
decl|const
decl_stmt|;
name|QDateTime
name|addMSecs
argument_list|(
name|qint64
name|msecs
argument_list|)
decl|const
decl_stmt|;
name|QDateTime
name|toTimeSpec
argument_list|(
name|Qt
operator|::
name|TimeSpec
name|spec
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|QDateTime
name|toLocalTime
argument_list|()
specifier|const
block|{
return|return
name|toTimeSpec
argument_list|(
name|Qt
operator|::
name|LocalTime
argument_list|)
return|;
block|}
specifier|inline
name|QDateTime
name|toUTC
argument_list|()
specifier|const
block|{
return|return
name|toTimeSpec
argument_list|(
name|Qt
operator|::
name|UTC
argument_list|)
return|;
block|}
name|int
name|daysTo
argument_list|(
specifier|const
name|QDateTime
operator|&
argument_list|)
decl|const
decl_stmt|;
name|int
name|secsTo
argument_list|(
specifier|const
name|QDateTime
operator|&
argument_list|)
decl|const
decl_stmt|;
name|qint64
name|msecsTo
argument_list|(
specifier|const
name|QDateTime
operator|&
argument_list|)
decl|const
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QDateTime
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QDateTime
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QDateTime
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|QDateTime
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
name|other
operator|<
operator|*
name|this
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|QDateTime
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|other
operator|<
operator|*
name|this
return|;
block|}
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|QDateTime
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|<
name|other
operator|)
return|;
block|}
name|void
name|setUtcOffset
parameter_list|(
name|int
name|seconds
parameter_list|)
function_decl|;
name|int
name|utcOffset
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QDateTime
name|currentDateTime
parameter_list|()
function_decl|;
specifier|static
name|QDateTime
name|currentDateTimeUtc
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
specifier|static
name|QDateTime
name|fromString
argument_list|(
specifier|const
name|QString
operator|&
name|s
argument_list|,
name|Qt
operator|::
name|DateFormat
name|f
operator|=
name|Qt
operator|::
name|TextDate
argument_list|)
decl_stmt|;
specifier|static
name|QDateTime
name|fromString
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|,
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|static
name|QDateTime
name|fromTime_t
parameter_list|(
name|uint
name|secsSince1Jan1970UTC
parameter_list|)
function_decl|;
specifier|static
name|QDateTime
name|fromMSecsSinceEpoch
parameter_list|(
name|qint64
name|msecs
parameter_list|)
function_decl|;
specifier|static
name|qint64
name|currentMSecsSinceEpoch
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
specifier|inline
name|QT3_SUPPORT
name|void
name|setTime_t
argument_list|(
name|uint
name|secsSince1Jan1970UTC
argument_list|,
name|Qt
operator|::
name|TimeSpec
name|spec
argument_list|)
block|{
name|setTime_t
argument_list|(
name|secsSince1Jan1970UTC
argument_list|)
expr_stmt|;
if|if
condition|(
name|spec
operator|==
name|Qt
operator|::
name|UTC
condition|)
operator|*
name|this
operator|=
name|toUTC
argument_list|()
expr_stmt|;
block|}
specifier|static
specifier|inline
name|QT3_SUPPORT
name|QDateTime
name|currentDateTime
argument_list|(
name|Qt
operator|::
name|TimeSpec
name|spec
argument_list|)
block|{
if|if
condition|(
name|spec
operator|==
name|Qt
operator|::
name|LocalTime
condition|)
return|return
name|currentDateTime
argument_list|()
return|;
else|else
return|return
name|currentDateTime
argument_list|()
operator|.
name|toUTC
argument_list|()
return|;
block|}
endif|#
directive|endif
name|private
label|:
name|friend
name|class
name|QDateTimePrivate
decl_stmt|;
name|void
name|detach
parameter_list|()
function_decl|;
name|QExplicitlySharedDataPointer
operator|<
name|QDateTimePrivate
operator|>
name|d
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|friend
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QDateTime
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QDateTime
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QDateTime
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_expr_stmt
DECL|function|currentDate
specifier|inline
name|QDate
name|QDate
operator|::
name|currentDate
argument_list|(
argument|Qt::TimeSpec spec
argument_list|)
block|{
if|if
condition|(
name|spec
operator|==
name|Qt
operator|::
name|LocalTime
condition|)
return|return
name|currentDate
argument_list|()
return|;
else|else
return|return
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
operator|.
name|toUTC
argument_list|()
operator|.
name|date
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|currentTime
specifier|inline
name|QTime
name|QTime
operator|::
name|currentTime
argument_list|(
argument|Qt::TimeSpec spec
argument_list|)
block|{
if|if
condition|(
name|spec
operator|==
name|Qt
operator|::
name|LocalTime
condition|)
return|return
name|currentTime
argument_list|()
return|;
else|else
return|return
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
operator|.
name|toUTC
argument_list|()
operator|.
name|time
argument_list|()
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QDate
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QDate
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QTime
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QTime
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QDateTime
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QDateTime
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG_STREAM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_DATESTRING
argument_list|)
end_if
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QDate
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QTime
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QDateTime
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDATETIME_H
end_comment
end_unit
