begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOREAPPLICATION_P_H
end_ifndef
begin_define
DECL|macro|QCOREAPPLICATION_P_H
define|#
directive|define
name|QCOREAPPLICATION_P_H
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
file|"QtCore/qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qtranslator.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qsettings.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_include
include|#
directive|include
file|<f32file.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|QTranslatorList
typedef|typedef
name|QList
operator|<
name|QTranslator
operator|*
operator|>
name|QTranslatorList
expr_stmt|;
end_typedef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_SYSTEMLOCALE
argument_list|)
end_if
begin_decl_stmt
DECL|variable|QEnvironmentChangeNotifier
name|class
name|QEnvironmentChangeNotifier
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|CApaCommandLine
name|class
name|CApaCommandLine
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QCoreApplicationPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QCoreApplication
argument_list|)
name|public
operator|:
name|QCoreApplicationPrivate
argument_list|(
argument|int&aargc
argument_list|,
argument|char **aargv
argument_list|,
argument|uint flags
argument_list|)
block|;
operator|~
name|QCoreApplicationPrivate
argument_list|()
block|;
name|bool
name|sendThroughApplicationEventFilters
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|bool
name|sendThroughObjectEventFilters
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|bool
name|notify_helper
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|_q_initializeProcessManager
argument_list|()
block|;
name|virtual
name|QString
name|appName
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|createEventDispatcher
argument_list|()
block|;
specifier|static
name|void
name|removePostedEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
specifier|static
name|void
name|removePostedTimerEvent
argument_list|(
argument|QObject *object
argument_list|,
argument|int timerId
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_MAC
specifier|static
name|QString
name|macMenuBarName
argument_list|()
block|;
endif|#
directive|endif
specifier|static
name|QThread
operator|*
name|theMainThread
block|;
specifier|static
name|QThread
operator|*
name|mainThread
argument_list|()
block|;
specifier|static
name|bool
name|checkInstance
argument_list|(
specifier|const
name|char
operator|*
name|method
argument_list|)
block|;
specifier|static
name|void
name|sendPostedEvents
argument_list|(
argument|QObject *receiver
argument_list|,
argument|int event_type
argument_list|,
argument|QThreadData *data
argument_list|)
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_MAC_FRAMEWORK_BUILD
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|void
name|checkReceiverThread
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|)
block|;
endif|#
directive|endif
name|int
operator|&
name|argc
block|;
name|char
operator|*
operator|*
name|argv
block|;
name|void
name|appendApplicationPathToLibraryPaths
argument_list|(
name|void
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_TRANSLATION
name|QTranslatorList
name|translators
block|;
endif|#
directive|endif
name|uint
name|application_type
block|;
name|QCoreApplication
operator|::
name|EventFilter
name|eventFilter
block|;
name|bool
name|in_exec
block|;
name|bool
name|aboutToQuitEmitted
block|;
name|QString
name|cachedApplicationDirPath
block|;
name|QString
name|cachedApplicationFilePath
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_SYSTEMLOCALE
argument_list|)
name|QScopedPointer
operator|<
name|QEnvironmentChangeNotifier
operator|>
name|environmentChangeNotifier
block|;
name|void
name|symbianInit
argument_list|()
block|;
endif|#
directive|endif
specifier|static
name|CApaCommandLine
operator|*
name|symbianCommandLine
argument_list|()
block|;
endif|#
directive|endif
specifier|static
name|bool
name|isTranslatorInstalled
argument_list|(
name|QTranslator
operator|*
name|translator
argument_list|)
block|;
specifier|static
name|QAbstractEventDispatcher
operator|*
name|eventDispatcher
block|;
specifier|static
name|bool
name|is_app_running
block|;
specifier|static
name|bool
name|is_app_closing
block|;
specifier|static
name|uint
name|attribs
block|;
specifier|static
specifier|inline
name|bool
name|testAttribute
argument_list|(
argument|uint flag
argument_list|)
block|{
return|return
name|attribs
operator|&
operator|(
literal|1
operator|<<
name|flag
operator|)
return|;
block|}
specifier|static
name|int
name|app_compile_version
block|; }
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
comment|// QCOREAPPLICATION_P_H
end_comment
end_unit
