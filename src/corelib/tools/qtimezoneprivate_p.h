begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 John Layt<jlayt@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTIMEZONEPRIVATE_P_H
end_ifndef
begin_define
DECL|macro|QTIMEZONEPRIVATE_P_H
define|#
directive|define
name|QTIMEZONEPRIVATE_P_H
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
file|"qtimezone.h"
end_include
begin_include
include|#
directive|include
file|"qlocale_p.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_USE_ICU
end_ifdef
begin_include
include|#
directive|include
file|<unicode/ucal.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_USE_ICU
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_ifdef
ifdef|#
directive|ifdef
name|__OBJC__
end_ifdef
begin_decl_stmt
unit|@
DECL|variable|NSTimeZone
name|class
name|NSTimeZone
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
DECL|variable|NSTimeZone
name|class
name|NSTimeZone
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// __OBJC__
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_MAC
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WIN
end_comment
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_CORE_EXPORT
name|QTimeZonePrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
comment|//Version of QTimeZone::OffsetData struct using msecs for efficiency
expr|struct
name|Data
block|{
name|QString
name|abbreviation
block|;
name|qint64
name|atMSecsSinceEpoch
block|;
name|int
name|offsetFromUtc
block|;
name|int
name|standardTimeOffset
block|;
name|int
name|daylightTimeOffset
block|;     }
block|;
typedef|typedef
name|QVector
operator|<
name|Data
operator|>
name|DataList
expr_stmt|;
comment|// Create null time zone
name|QTimeZonePrivate
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QTimeZonePrivate
argument_list|(
specifier|const
name|QTimeZonePrivate
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
operator|~
name|QTimeZonePrivate
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|virtual
name|QTimeZonePrivate
modifier|*
name|clone
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QTimeZonePrivate
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QTimeZonePrivate
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QByteArray
name|id
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QLocale
operator|::
name|Country
name|country
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QString
name|comment
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|virtual
name|QString
name|displayName
argument_list|(
name|qint64
name|atMSecsSinceEpoch
argument_list|,
name|QTimeZone
operator|::
name|NameType
name|nameType
argument_list|,
specifier|const
name|QLocale
operator|&
name|locale
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QString
name|displayName
argument_list|(
name|QTimeZone
operator|::
name|TimeType
name|timeType
argument_list|,
name|QTimeZone
operator|::
name|NameType
name|nameType
argument_list|,
specifier|const
name|QLocale
operator|&
name|locale
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QString
name|abbreviation
argument_list|(
name|qint64
name|atMSecsSinceEpoch
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|int
name|offsetFromUtc
argument_list|(
name|qint64
name|atMSecsSinceEpoch
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|int
name|standardTimeOffset
argument_list|(
name|qint64
name|atMSecsSinceEpoch
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|int
name|daylightTimeOffset
argument_list|(
name|qint64
name|atMSecsSinceEpoch
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|virtual
name|bool
name|hasDaylightTime
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|virtual
name|bool
name|isDaylightTime
argument_list|(
name|qint64
name|atMSecsSinceEpoch
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|Data
name|data
argument_list|(
name|qint64
name|forMSecsSinceEpoch
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|Data
name|dataForLocalTime
argument_list|(
name|qint64
name|forLocalMSecs
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|virtual
name|bool
name|hasTransitions
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|virtual
name|Data
name|nextTransition
argument_list|(
name|qint64
name|afterMSecsSinceEpoch
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|Data
name|previousTransition
argument_list|(
name|qint64
name|beforeMSecsSinceEpoch
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|DataList
name|transitions
argument_list|(
name|qint64
name|fromMSecsSinceEpoch
argument_list|,
name|qint64
name|toMSecsSinceEpoch
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|virtual
name|QByteArray
name|systemTimeZoneId
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QSet
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QSet
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|(
argument|QLocale::Country country
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|QSet
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|(
argument|int utcOffset
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|virtual
name|void
name|serialize
argument_list|(
name|QDataStream
operator|&
name|ds
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Static Utility Methods
end_comment
begin_function
specifier|static
specifier|inline
name|qint64
name|maxMSecs
parameter_list|()
block|{
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|qint64
operator|>
operator|::
name|max
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|qint64
name|minMSecs
parameter_list|()
block|{
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|qint64
operator|>
operator|::
name|min
argument_list|()
operator|+
literal|1
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|qint64
name|invalidMSecs
parameter_list|()
block|{
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|qint64
operator|>
operator|::
name|min
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|qint64
name|invalidSeconds
parameter_list|()
block|{
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|int
operator|>
operator|::
name|min
argument_list|()
return|;
block|}
end_function
begin_function_decl
specifier|static
name|Data
name|invalidData
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
specifier|static
name|QTimeZone
operator|::
name|OffsetData
name|invalidOffsetData
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|static
name|QTimeZone
operator|::
name|OffsetData
name|toOffsetData
argument_list|(
specifier|const
name|Data
operator|&
name|data
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|bool
name|isValidId
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ianaId
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|isoOffsetFormat
parameter_list|(
name|int
name|offsetFromUtc
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QByteArray
name|ianaIdToWindowsId
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ianaId
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QByteArray
name|windowsIdToDefaultIanaId
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|windowsId
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
name|QByteArray
name|windowsIdToDefaultIanaId
argument_list|(
specifier|const
name|QByteArray
operator|&
name|windowsId
argument_list|,
name|QLocale
operator|::
name|Country
name|country
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|windowsIdToIanaIds
argument_list|(
specifier|const
name|QByteArray
operator|&
name|windowsId
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|windowsIdToIanaIds
argument_list|(
argument|const QByteArray&windowsId
argument_list|,
argument|QLocale::Country country
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns "UTC" QString and QByteArray
end_comment
begin_function
specifier|static
specifier|inline
name|QString
name|utcQString
parameter_list|()
function|Q_REQUIRED_RESULT
block|{
return|return
name|QStringLiteral
argument_list|(
literal|"UTC"
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|QByteArray
name|utcQByteArray
parameter_list|()
function|Q_REQUIRED_RESULT
block|{
return|return
name|QByteArrayLiteral
argument_list|(
literal|"UTC"
argument_list|)
return|;
block|}
end_function
begin_label
name|protected
label|:
end_label
begin_decl_stmt
name|QByteArray
name|m_id
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
name|QTimeZonePrivate
operator|*
name|QSharedDataPointer
operator|<
name|QTimeZonePrivate
operator|>
operator|::
name|clone
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QUtcTimeZonePrivate
name|Q_DECL_FINAL
range|:
name|public
name|QTimeZonePrivate
block|{
name|public
operator|:
comment|// Create default UTC time zone
name|QUtcTimeZonePrivate
argument_list|()
block|;
comment|// Create named time zone
name|QUtcTimeZonePrivate
argument_list|(
specifier|const
name|QByteArray
operator|&
name|utcId
argument_list|)
block|;
comment|// Create offset from UTC
name|QUtcTimeZonePrivate
argument_list|(
argument|int offsetSeconds
argument_list|)
block|;
comment|// Create custom offset from UTC
name|QUtcTimeZonePrivate
argument_list|(
argument|const QByteArray&zoneId
argument_list|,
argument|int offsetSeconds
argument_list|,
argument|const QString&name
argument_list|,
argument|const QString&abbreviation
argument_list|,
argument|QLocale::Country country
argument_list|,
argument|const QString&comment
argument_list|)
block|;
name|QUtcTimeZonePrivate
argument_list|(
specifier|const
name|QUtcTimeZonePrivate
operator|&
name|other
argument_list|)
block|;
name|virtual
operator|~
name|QUtcTimeZonePrivate
argument_list|()
block|;
name|QTimeZonePrivate
operator|*
name|clone
argument_list|()
block|;
name|Data
name|data
argument_list|(
argument|qint64 forMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QLocale
operator|::
name|Country
name|country
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|comment
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|displayName
argument_list|(
argument|QTimeZone::TimeType timeType
argument_list|,
argument|QTimeZone::NameType nameType
argument_list|,
argument|const QLocale&locale
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|abbreviation
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|standardTimeOffset
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|daylightTimeOffset
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QByteArray
name|systemTimeZoneId
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSet
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSet
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|(
argument|QLocale::Country country
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSet
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|(
argument|int utcOffset
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|serialize
argument_list|(
argument|QDataStream&ds
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|init
argument_list|(
specifier|const
name|QByteArray
operator|&
name|zoneId
argument_list|)
block|;
name|void
name|init
argument_list|(
argument|const QByteArray&zoneId
argument_list|,
argument|int offsetSeconds
argument_list|,
argument|const QString&name
argument_list|,
argument|const QString&abbreviation
argument_list|,
argument|QLocale::Country country
argument_list|,
argument|const QString&comment
argument_list|)
block|;
name|QString
name|m_name
block|;
name|QString
name|m_abbreviation
block|;
name|QString
name|m_comment
block|;
name|QLocale
operator|::
name|Country
name|m_country
block|;
name|int
name|m_offsetFromUtc
block|; }
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_USE_ICU
end_ifdef
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QIcuTimeZonePrivate
name|Q_DECL_FINAL
range|:
name|public
name|QTimeZonePrivate
block|{
name|public
operator|:
comment|// Create default time zone
name|QIcuTimeZonePrivate
argument_list|()
block|;
comment|// Create named time zone
name|QIcuTimeZonePrivate
argument_list|(
specifier|const
name|QByteArray
operator|&
name|ianaId
argument_list|)
block|;
name|QIcuTimeZonePrivate
argument_list|(
specifier|const
name|QIcuTimeZonePrivate
operator|&
name|other
argument_list|)
block|;
operator|~
name|QIcuTimeZonePrivate
argument_list|()
block|;
name|QTimeZonePrivate
operator|*
name|clone
argument_list|()
block|;
name|QString
name|displayName
argument_list|(
argument|QTimeZone::TimeType timeType
argument_list|,
argument|QTimeZone::NameType nameType
argument_list|,
argument|const QLocale&locale
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|abbreviation
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|offsetFromUtc
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|standardTimeOffset
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|daylightTimeOffset
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasDaylightTime
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isDaylightTime
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Data
name|data
argument_list|(
argument|qint64 forMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasTransitions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Data
name|nextTransition
argument_list|(
argument|qint64 afterMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Data
name|previousTransition
argument_list|(
argument|qint64 beforeMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QByteArray
name|systemTimeZoneId
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSet
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSet
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|(
argument|QLocale::Country country
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSet
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|(
argument|int offsetFromUtc
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|init
argument_list|(
specifier|const
name|QByteArray
operator|&
name|ianaId
argument_list|)
block|;
name|UCalendar
operator|*
name|m_ucal
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_USE_ICU
end_comment
begin_if
if|#
directive|if
name|defined
name|Q_OS_UNIX
operator|&&
operator|!
name|defined
name|Q_OS_MAC
end_if
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QTzTimeZonePrivate
name|Q_DECL_FINAL
range|:
name|public
name|QTimeZonePrivate
block|{
name|public
operator|:
comment|// Create default time zone
name|QTzTimeZonePrivate
argument_list|()
block|;
comment|// Create named time zone
name|QTzTimeZonePrivate
argument_list|(
specifier|const
name|QByteArray
operator|&
name|ianaId
argument_list|)
block|;
name|QTzTimeZonePrivate
argument_list|(
specifier|const
name|QTzTimeZonePrivate
operator|&
name|other
argument_list|)
block|;
operator|~
name|QTzTimeZonePrivate
argument_list|()
block|;
name|QTimeZonePrivate
operator|*
name|clone
argument_list|()
block|;
name|QLocale
operator|::
name|Country
name|country
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|comment
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|displayName
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|,
argument|QTimeZone::NameType nameType
argument_list|,
argument|const QLocale&locale
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|displayName
argument_list|(
argument|QTimeZone::TimeType timeType
argument_list|,
argument|QTimeZone::NameType nameType
argument_list|,
argument|const QLocale&locale
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|abbreviation
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|offsetFromUtc
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|standardTimeOffset
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|daylightTimeOffset
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasDaylightTime
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isDaylightTime
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Data
name|data
argument_list|(
argument|qint64 forMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasTransitions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Data
name|nextTransition
argument_list|(
argument|qint64 afterMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Data
name|previousTransition
argument_list|(
argument|qint64 beforeMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QByteArray
name|systemTimeZoneId
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSet
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSet
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|(
argument|QLocale::Country country
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|init
argument_list|(
specifier|const
name|QByteArray
operator|&
name|ianaId
argument_list|)
block|;      struct
name|QTzTransitionTime
block|{
name|qint64
name|atMSecsSinceEpoch
block|;
name|quint8
name|ruleIndex
block|;     }
block|;     struct
name|QTzTransitionRule
block|{
name|int
name|stdOffset
block|;
name|int
name|dstOffset
block|;
name|quint8
name|abbreviationIndex
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QTzTransitionRule
operator|&
name|other
operator|)
block|{
return|return
operator|(
name|stdOffset
operator|==
name|other
operator|.
name|stdOffset
operator|&&
name|dstOffset
operator|==
name|other
operator|.
name|dstOffset
operator|&&
name|abbreviationIndex
operator|==
name|other
operator|.
name|abbreviationIndex
operator|)
return|;
block|}
expr|}
block|;
name|Data
name|dataForTzTransition
argument_list|(
argument|QTzTransitionTime tran
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QTzTransitionTime
operator|>
name|m_tranTimes
block|;
name|QList
operator|<
name|QTzTransitionRule
operator|>
name|m_tranRules
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|m_abbreviations
block|;
ifdef|#
directive|ifdef
name|QT_USE_ICU
name|mutable
name|QSharedDataPointer
operator|<
name|QTimeZonePrivate
operator|>
name|m_icu
block|;
endif|#
directive|endif
comment|// QT_USE_ICU
name|QByteArray
name|m_posixRule
block|; }
block|;
endif|#
directive|endif
comment|// Q_OS_UNIX
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|class
name|Q_AUTOTEST_EXPORT
name|QMacTimeZonePrivate
name|Q_DECL_FINAL
operator|:
name|public
name|QTimeZonePrivate
block|{
name|public
operator|:
comment|// Create default time zone
name|QMacTimeZonePrivate
argument_list|()
block|;
comment|// Create named time zone
name|QMacTimeZonePrivate
argument_list|(
specifier|const
name|QByteArray
operator|&
name|ianaId
argument_list|)
block|;
name|QMacTimeZonePrivate
argument_list|(
specifier|const
name|QMacTimeZonePrivate
operator|&
name|other
argument_list|)
block|;
operator|~
name|QMacTimeZonePrivate
argument_list|()
block|;
name|QTimeZonePrivate
operator|*
name|clone
argument_list|()
block|;
name|QString
name|comment
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|displayName
argument_list|(
argument|QTimeZone::TimeType timeType
argument_list|,
argument|QTimeZone::NameType nameType
argument_list|,
argument|const QLocale&locale
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|abbreviation
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|offsetFromUtc
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|standardTimeOffset
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|daylightTimeOffset
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasDaylightTime
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isDaylightTime
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Data
name|data
argument_list|(
argument|qint64 forMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasTransitions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Data
name|nextTransition
argument_list|(
argument|qint64 afterMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Data
name|previousTransition
argument_list|(
argument|qint64 beforeMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QByteArray
name|systemTimeZoneId
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSet
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|init
argument_list|(
specifier|const
name|QByteArray
operator|&
name|zoneId
argument_list|)
block|;
name|NSTimeZone
operator|*
name|m_nstz
block|; }
block|;
endif|#
directive|endif
comment|// Q_OS_MAC
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|class
name|Q_AUTOTEST_EXPORT
name|QWinTimeZonePrivate
name|Q_DECL_FINAL
operator|:
name|public
name|QTimeZonePrivate
block|{
name|public
operator|:
expr|struct
name|QWinTransitionRule
block|{
name|int
name|startYear
block|;
name|int
name|standardTimeBias
block|;
name|int
name|daylightTimeBias
block|;
name|SYSTEMTIME
name|standardTimeRule
block|;
name|SYSTEMTIME
name|daylightTimeRule
block|;     }
block|;
comment|// Create default time zone
name|QWinTimeZonePrivate
argument_list|()
block|;
comment|// Create named time zone
name|QWinTimeZonePrivate
argument_list|(
specifier|const
name|QByteArray
operator|&
name|ianaId
argument_list|)
block|;
name|QWinTimeZonePrivate
argument_list|(
specifier|const
name|QWinTimeZonePrivate
operator|&
name|other
argument_list|)
block|;
operator|~
name|QWinTimeZonePrivate
argument_list|()
block|;
name|QTimeZonePrivate
operator|*
name|clone
argument_list|()
block|;
name|QString
name|comment
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|displayName
argument_list|(
argument|QTimeZone::TimeType timeType
argument_list|,
argument|QTimeZone::NameType nameType
argument_list|,
argument|const QLocale&locale
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|abbreviation
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|offsetFromUtc
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|standardTimeOffset
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|daylightTimeOffset
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasDaylightTime
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isDaylightTime
argument_list|(
argument|qint64 atMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Data
name|data
argument_list|(
argument|qint64 forMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasTransitions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Data
name|nextTransition
argument_list|(
argument|qint64 afterMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Data
name|previousTransition
argument_list|(
argument|qint64 beforeMSecsSinceEpoch
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QByteArray
name|systemTimeZoneId
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSet
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|init
argument_list|(
specifier|const
name|QByteArray
operator|&
name|ianaId
argument_list|)
block|;
name|QWinTransitionRule
name|ruleForYear
argument_list|(
argument|int year
argument_list|)
specifier|const
block|;
name|QTimeZonePrivate
operator|::
name|Data
name|ruleToData
argument_list|(
argument|const QWinTransitionRule&rule
argument_list|,
argument|qint64 atMSecsSinceEpoch
argument_list|,
argument|QTimeZone::TimeType type
argument_list|)
specifier|const
block|;
name|QByteArray
name|m_windowsId
block|;
name|QString
name|m_displayName
block|;
name|QString
name|m_standardName
block|;
name|QString
name|m_daylightName
block|;
name|QList
operator|<
name|QWinTransitionRule
operator|>
name|m_tranRules
block|; }
block|;
endif|#
directive|endif
comment|// Q_OS_WIN
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTIMEZONEPRIVATE_P_H
end_comment
end_unit
