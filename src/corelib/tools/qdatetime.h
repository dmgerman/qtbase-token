begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<limits>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_expr_stmt
DECL|variable|CFDate
name|Q_FORWARD_DECLARE_CF_TYPE
argument_list|(
name|CFDate
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|__OBJC__
end_ifdef
begin_expr_stmt
DECL|variable|NSDate
name|Q_FORWARD_DECLARE_OBJC_CLASS
argument_list|(
name|NSDate
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTimeZone
name|class
name|QTimeZone
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QDate
block|{
name|public
label|:
enum|enum
name|MonthNameType
block|{
name|DateFormat
init|=
literal|0
block|,
name|StandaloneFormat
block|}
enum|;
name|private
label|:
name|explicit
name|Q_DECL_CONSTEXPR
name|QDate
argument_list|(
argument|qint64 julianDay
argument_list|)
block|:
name|jd
argument_list|(
argument|julianDay
argument_list|)
block|{}
name|public
label|:
name|Q_DECL_CONSTEXPR
name|QDate
argument_list|()
operator|:
name|jd
argument_list|(
argument|nullJd()
argument_list|)
block|{}
name|QDate
argument_list|(
argument|int y
argument_list|,
argument|int m
argument_list|,
argument|int d
argument_list|)
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isValid
argument_list|()
return|;
block|}
name|Q_DECL_CONSTEXPR
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|jd
operator|>=
name|minJd
argument_list|()
operator|&&
name|jd
operator|<=
name|maxJd
argument_list|()
return|;
block|}
name|int
name|year
argument_list|()
specifier|const
expr_stmt|;
name|int
name|month
argument_list|()
specifier|const
expr_stmt|;
name|int
name|day
argument_list|()
specifier|const
expr_stmt|;
name|int
name|dayOfWeek
argument_list|()
specifier|const
expr_stmt|;
name|int
name|dayOfYear
argument_list|()
specifier|const
expr_stmt|;
name|int
name|daysInMonth
argument_list|()
specifier|const
expr_stmt|;
name|int
name|daysInYear
argument_list|()
specifier|const
expr_stmt|;
name|int
name|weekNumber
argument_list|(
name|int
operator|*
name|yearNum
operator|=
name|Q_NULLPTR
argument_list|)
decl|const
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTDATE
specifier|static
name|QString
name|shortMonthName
parameter_list|(
name|int
name|month
parameter_list|,
name|MonthNameType
name|type
init|=
name|DateFormat
parameter_list|)
function_decl|;
specifier|static
name|QString
name|shortDayName
parameter_list|(
name|int
name|weekday
parameter_list|,
name|MonthNameType
name|type
init|=
name|DateFormat
parameter_list|)
function_decl|;
specifier|static
name|QString
name|longMonthName
parameter_list|(
name|int
name|month
parameter_list|,
name|MonthNameType
name|type
init|=
name|DateFormat
parameter_list|)
function_decl|;
specifier|static
name|QString
name|longDayName
parameter_list|(
name|int
name|weekday
parameter_list|,
name|MonthNameType
name|type
init|=
name|DateFormat
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// QT_NO_TEXTDATE
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
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
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
block|{
if|if
condition|(
name|uint
argument_list|(
name|y
argument_list|)
operator|<=
literal|99
condition|)
name|y
operator|+=
literal|1900
expr_stmt|;
return|return
name|setDate
argument_list|(
name|y
argument_list|,
name|m
argument_list|,
name|d
argument_list|)
return|;
block|}
endif|#
directive|endif
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
name|QDate
name|addDays
argument_list|(
name|qint64
name|days
argument_list|)
decl|const
name|Q_REQUIRED_RESULT
decl_stmt|;
name|QDate
name|addMonths
argument_list|(
name|int
name|months
argument_list|)
decl|const
name|Q_REQUIRED_RESULT
decl_stmt|;
name|QDate
name|addYears
argument_list|(
name|int
name|years
argument_list|)
decl|const
name|Q_REQUIRED_RESULT
decl_stmt|;
name|qint64
name|daysTo
argument_list|(
specifier|const
name|QDate
operator|&
argument_list|)
decl|const
decl_stmt|;
name|Q_DECL_CONSTEXPR
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
name|Q_DECL_CONSTEXPR
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
name|Q_DECL_CONSTEXPR
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
name|Q_DECL_CONSTEXPR
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
name|Q_DECL_CONSTEXPR
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
name|Q_DECL_CONSTEXPR
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
specifier|static
name|QDate
name|currentDate
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
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
endif|#
directive|endif
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
specifier|static
name|bool
name|isLeapYear
parameter_list|(
name|int
name|year
parameter_list|)
function_decl|;
specifier|static
name|Q_DECL_CONSTEXPR
specifier|inline
name|QDate
name|fromJulianDay
parameter_list|(
name|qint64
name|jd
parameter_list|)
block|{
return|return
name|jd
operator|>=
name|minJd
argument_list|()
operator|&&
name|jd
operator|<=
name|maxJd
argument_list|()
condition|?
name|QDate
argument_list|(
name|jd
argument_list|)
else|:
name|QDate
argument_list|()
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|qint64
name|toJulianDay
argument_list|()
specifier|const
block|{
return|return
name|jd
return|;
block|}
name|private
label|:
comment|// using extra parentheses around min to avoid expanding it if it is a macro
specifier|static
name|Q_DECL_CONSTEXPR
specifier|inline
name|qint64
name|nullJd
parameter_list|()
block|{
return|return
operator|(
name|std
operator|::
name|numeric_limits
operator|<
name|qint64
operator|>
operator|::
name|min
operator|)
operator|(
operator|)
return|;
block|}
specifier|static
name|Q_DECL_CONSTEXPR
specifier|inline
name|qint64
name|minJd
parameter_list|()
block|{
return|return
name|Q_INT64_C
argument_list|(
operator|-
literal|784350574879
argument_list|)
return|;
block|}
specifier|static
name|Q_DECL_CONSTEXPR
specifier|inline
name|qint64
name|maxJd
parameter_list|()
block|{
return|return
name|Q_INT64_C
argument_list|(
literal|784354017364
argument_list|)
return|;
block|}
name|qint64
name|jd
decl_stmt|;
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
name|QDate
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
name|QDate
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
name|explicit
name|Q_DECL_CONSTEXPR
name|QTime
argument_list|(
argument|int ms
argument_list|)
block|:
name|mds
argument_list|(
name|ms
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
name|public
operator|:
name|Q_DECL_CONSTEXPR
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
name|Q_DECL_CONSTEXPR
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
name|Q_REQUIRED_RESULT
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
name|Q_REQUIRED_RESULT
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
name|Q_DECL_CONSTEXPR
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
name|Q_DECL_CONSTEXPR
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
name|Q_DECL_CONSTEXPR
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
name|Q_DECL_CONSTEXPR
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
name|Q_DECL_CONSTEXPR
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
name|Q_DECL_CONSTEXPR
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
name|Q_DECL_CONSTEXPR
specifier|inline
name|QTime
name|fromMSecsSinceStartOfDay
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
return|return
name|QTime
argument_list|(
name|msecs
argument_list|)
return|;
block|}
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|msecsSinceStartOfDay
argument_list|()
specifier|const
block|{
return|return
name|mds
operator|==
name|NullTime
operator|?
literal|0
operator|:
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
name|Q_DECL_CONSTEXPR
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
comment|// ### Qt 6: Merge with above with default offsetSeconds = 0
name|QDateTime
argument_list|(
argument|const QDate&date
argument_list|,
argument|const QTime&time
argument_list|,
argument|Qt::TimeSpec spec
argument_list|,
argument|int offsetSeconds
argument_list|)
empty_stmt|;
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|QDateTime
argument_list|(
specifier|const
name|QDate
operator|&
name|date
argument_list|,
specifier|const
name|QTime
operator|&
name|time
argument_list|,
specifier|const
name|QTimeZone
operator|&
name|timeZone
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_BOOTSTRAPPED
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
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QDateTime
modifier|&
name|operator
init|=
operator|(
name|QDateTime
operator|&&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
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
name|void
name|swap
parameter_list|(
name|QDateTime
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
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
name|int
name|offsetFromUtc
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|QTimeZone
name|timeZone
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
comment|// QT_BOOTSTRAPPED
name|QString
name|timeZoneAbbreviation
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDaylightTime
argument_list|()
specifier|const
expr_stmt|;
name|qint64
name|toMSecsSinceEpoch
argument_list|()
specifier|const
expr_stmt|;
comment|// ### Qt 6: use quint64 instead of uint
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
name|setOffsetFromUtc
parameter_list|(
name|int
name|offsetSeconds
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|void
name|setTimeZone
parameter_list|(
specifier|const
name|QTimeZone
modifier|&
name|toZone
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// QT_BOOTSTRAPPED
name|void
name|setMSecsSinceEpoch
parameter_list|(
name|qint64
name|msecs
parameter_list|)
function_decl|;
comment|// ### Qt 6: use quint64 instead of uint
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
name|qint64
name|days
argument_list|)
decl|const
name|Q_REQUIRED_RESULT
decl_stmt|;
name|QDateTime
name|addMonths
argument_list|(
name|int
name|months
argument_list|)
decl|const
name|Q_REQUIRED_RESULT
decl_stmt|;
name|QDateTime
name|addYears
argument_list|(
name|int
name|years
argument_list|)
decl|const
name|Q_REQUIRED_RESULT
decl_stmt|;
name|QDateTime
name|addSecs
argument_list|(
name|qint64
name|secs
argument_list|)
decl|const
name|Q_REQUIRED_RESULT
decl_stmt|;
name|QDateTime
name|addMSecs
argument_list|(
name|qint64
name|msecs
argument_list|)
decl|const
name|Q_REQUIRED_RESULT
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
name|QDateTime
name|toOffsetFromUtc
argument_list|(
name|int
name|offsetSeconds
argument_list|)
decl|const
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|QDateTime
name|toTimeZone
argument_list|(
specifier|const
name|QTimeZone
operator|&
name|toZone
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
comment|// QT_BOOTSTRAPPED
name|qint64
name|daysTo
argument_list|(
specifier|const
name|QDateTime
operator|&
argument_list|)
decl|const
decl_stmt|;
name|qint64
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
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|2
argument_list|)
name|QT_DEPRECATED
name|void
name|setUtcOffset
parameter_list|(
name|int
name|seconds
parameter_list|)
function_decl|;
name|QT_DEPRECATED
name|int
name|utcOffset
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
comment|// QT_DEPRECATED_SINCE
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
comment|// ### Qt 6: use quint64 instead of uint
specifier|static
name|QDateTime
name|fromTime_t
parameter_list|(
name|uint
name|secsSince1Jan1970UTC
parameter_list|)
function_decl|;
comment|// ### Qt 6: Merge with above with default spec = Qt::LocalTime
specifier|static
name|QDateTime
name|fromTime_t
argument_list|(
name|uint
name|secsSince1Jan1970UTC
argument_list|,
name|Qt
operator|::
name|TimeSpec
name|spec
argument_list|,
name|int
name|offsetFromUtc
operator|=
literal|0
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
specifier|static
name|QDateTime
name|fromTime_t
parameter_list|(
name|uint
name|secsSince1Jan1970UTC
parameter_list|,
specifier|const
name|QTimeZone
modifier|&
name|timeZone
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|static
name|QDateTime
name|fromMSecsSinceEpoch
parameter_list|(
name|qint64
name|msecs
parameter_list|)
function_decl|;
comment|// ### Qt 6: Merge with above with default spec = Qt::LocalTime
specifier|static
name|QDateTime
name|fromMSecsSinceEpoch
argument_list|(
name|qint64
name|msecs
argument_list|,
name|Qt
operator|::
name|TimeSpec
name|spec
argument_list|,
name|int
name|offsetFromUtc
operator|=
literal|0
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
specifier|static
name|QDateTime
name|fromMSecsSinceEpoch
parameter_list|(
name|qint64
name|msecs
parameter_list|,
specifier|const
name|QTimeZone
modifier|&
name|timeZone
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|static
name|qint64
name|currentMSecsSinceEpoch
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
specifier|static
name|QDateTime
name|fromCFDate
parameter_list|(
name|CFDateRef
name|date
parameter_list|)
function_decl|;
name|CFDateRef
name|toCFDate
argument_list|()
specifier|const
name|Q_DECL_CF_RETURNS_RETAINED
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__OBJC__
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
specifier|static
name|QDateTime
name|fromNSDate
parameter_list|(
specifier|const
name|NSDate
modifier|*
name|date
parameter_list|)
function_decl|;
name|NSDate
operator|*
name|toNSDate
argument_list|()
specifier|const
name|Q_DECL_NS_RETURNS_AUTORELEASED
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|private
label|:
name|friend
name|class
name|QDateTimePrivate
decl_stmt|;
comment|// ### Qt6: Using a private here has high impact on runtime
comment|// on users such as QFileInfo. In Qt 6, the data members
comment|// should be inlined.
name|QSharedDataPointer
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
name|friend
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
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QDateTime
argument_list|)
end_macro
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
DECL|variable|operator
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
begin_comment
comment|// QDateTime is not noexcept for now -- to be revised once
end_comment
begin_comment
comment|// timezone and calendaring support is added
end_comment
begin_function_decl
name|Q_CORE_EXPORT
name|uint
name|qHash
parameter_list|(
specifier|const
name|QDateTime
modifier|&
name|key
parameter_list|,
name|uint
name|seed
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|Q_CORE_EXPORT
name|uint
name|qHash
argument_list|(
specifier|const
name|QDate
operator|&
name|key
argument_list|,
name|uint
name|seed
operator|=
literal|0
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|Q_CORE_EXPORT
name|uint
name|qHash
argument_list|(
specifier|const
name|QTime
operator|&
name|key
argument_list|,
name|uint
name|seed
operator|=
literal|0
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDATETIME_H
end_comment
end_unit
