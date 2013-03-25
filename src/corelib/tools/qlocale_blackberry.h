begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLOCALE_BLACKBERRY_H
end_ifndef
begin_define
DECL|macro|QLOCALE_BLACKBERRY_H
define|#
directive|define
name|QLOCALE_BLACKBERRY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qsocketnotifier.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qreadwritelock.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlocale.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMLOCALE
name|class
name|QBBSystemLocaleData
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QBBSystemLocaleData
argument_list|()
block|;
name|virtual
operator|~
name|QBBSystemLocaleData
argument_list|()
block|;
name|uint
name|measurementSystem
argument_list|()
block|;
name|QVariant
name|timeFormat
argument_list|(
name|QLocale
operator|::
name|FormatType
argument_list|)
block|;
name|QVariant
name|dateTimeFormat
argument_list|(
name|QLocale
operator|::
name|FormatType
argument_list|)
block|;
name|QLocale
name|languageLocale
argument_list|()
block|;
name|QLocale
name|regionLocale
argument_list|()
block|;
name|QReadWriteLock
name|lock
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|installSocketNotifiers
argument_list|()
block|;
name|void
name|readLangageLocale
argument_list|()
block|;
name|void
name|readRegionLocale
argument_list|()
block|;
name|void
name|readMeasurementSystem
argument_list|()
block|;
name|void
name|readHourFormat
argument_list|()
block|;
name|private
operator|:
name|QByteArray
name|readPpsValue
argument_list|(
specifier|const
name|char
operator|*
name|ppsPath
argument_list|,
specifier|const
name|char
operator|*
name|ppsObject
argument_list|,
name|int
operator|*
name|ppsFd
argument_list|)
block|;
name|QString
name|getCorrectFormat
argument_list|(
argument|const QString&baseFormat
argument_list|,
argument|QLocale::FormatType typeFormat
argument_list|)
block|;
name|QByteArray
name|lc_langage
block|;
name|QByteArray
name|lc_region
block|;
name|uint
name|m_measurementSystem
block|;
name|bool
name|is24HourFormat
block|;
name|QSocketNotifier
operator|*
name|languageNotifier
block|;
name|QSocketNotifier
operator|*
name|regionNotifier
block|;
name|QSocketNotifier
operator|*
name|measurementNotifier
block|;
name|QSocketNotifier
operator|*
name|hourNotifier
block|;
name|int
name|languageFd
block|;
name|int
name|regionFd
block|;
name|int
name|measurementFd
block|;
name|int
name|hourFd
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYSTEMLOCALE
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLOCALE_BLACKBERRY_H
end_comment
end_unit
