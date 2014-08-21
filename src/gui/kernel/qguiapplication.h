begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGUIAPPLICATION_H
end_ifndef
begin_define
DECL|macro|QGUIAPPLICATION_H
define|#
directive|define
name|QGUIAPPLICATION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qinputmethod.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlocale.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsize.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSessionManager
name|class
name|QSessionManager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGuiApplicationPrivate
name|class
name|QGuiApplicationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformNativeInterface
name|class
name|QPlatformNativeInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformIntegration
name|class
name|QPlatformIntegration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPalette
name|class
name|QPalette
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScreen
name|class
name|QScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleHints
name|class
name|QStyleHints
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|qApp
argument_list|)
end_if
begin_undef
DECL|macro|qApp
undef|#
directive|undef
name|qApp
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|qApp
define|#
directive|define
name|qApp
value|(static_cast<QGuiApplication *>(QCoreApplication::instance()))
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|qGuiApp
argument_list|)
end_if
begin_undef
DECL|macro|qGuiApp
undef|#
directive|undef
name|qGuiApp
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|qGuiApp
define|#
directive|define
name|qGuiApp
value|(static_cast<QGuiApplication *>(QCoreApplication::instance()))
end_define
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QGuiApplication
range|:
name|public
name|QCoreApplication
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QIcon windowIcon READ windowIcon WRITE setWindowIcon
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString applicationDisplayName READ applicationDisplayName WRITE setApplicationDisplayName
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::LayoutDirection layoutDirection READ layoutDirection WRITE setLayoutDirection NOTIFY layoutDirectionChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString platformName READ platformName STORED false
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool quitOnLastWindowClosed  READ quitOnLastWindowClosed WRITE setQuitOnLastWindowClosed
argument_list|)
name|public
operator|:
ifdef|#
directive|ifdef
name|Q_QDOC
name|QGuiApplication
argument_list|(
name|int
operator|&
name|argc
argument_list|,
name|char
operator|*
operator|*
name|argv
argument_list|)
block|;
else|#
directive|else
name|QGuiApplication
argument_list|(
name|int
operator|&
name|argc
argument_list|,
name|char
operator|*
operator|*
name|argv
argument_list|,
name|int
operator|=
name|ApplicationFlags
argument_list|)
block|;
endif|#
directive|endif
name|virtual
operator|~
name|QGuiApplication
argument_list|()
block|;
specifier|static
name|void
name|setApplicationDisplayName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
specifier|static
name|QString
name|applicationDisplayName
argument_list|()
block|;
specifier|static
name|QWindowList
name|allWindows
argument_list|()
block|;
specifier|static
name|QWindowList
name|topLevelWindows
argument_list|()
block|;
specifier|static
name|QWindow
operator|*
name|topLevelAt
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
specifier|static
name|void
name|setWindowIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
block|;
specifier|static
name|QIcon
name|windowIcon
argument_list|()
block|;
specifier|static
name|QString
name|platformName
argument_list|()
block|;
specifier|static
name|QWindow
operator|*
name|modalWindow
argument_list|()
block|;
specifier|static
name|QWindow
operator|*
name|focusWindow
argument_list|()
block|;
specifier|static
name|QObject
operator|*
name|focusObject
argument_list|()
block|;
specifier|static
name|QScreen
operator|*
name|primaryScreen
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QScreen
operator|*
operator|>
name|screens
argument_list|()
block|;
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
specifier|static
name|QCursor
operator|*
name|overrideCursor
argument_list|()
block|;
specifier|static
name|void
name|setOverrideCursor
argument_list|(
specifier|const
name|QCursor
operator|&
argument_list|)
block|;
specifier|static
name|void
name|changeOverrideCursor
argument_list|(
specifier|const
name|QCursor
operator|&
argument_list|)
block|;
specifier|static
name|void
name|restoreOverrideCursor
argument_list|()
block|;
endif|#
directive|endif
specifier|static
name|QFont
name|font
argument_list|()
block|;
specifier|static
name|void
name|setFont
argument_list|(
specifier|const
name|QFont
operator|&
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
specifier|static
name|QClipboard
operator|*
name|clipboard
argument_list|()
block|;
endif|#
directive|endif
specifier|static
name|QPalette
name|palette
argument_list|()
block|;
specifier|static
name|void
name|setPalette
argument_list|(
specifier|const
name|QPalette
operator|&
name|pal
argument_list|)
block|;
specifier|static
name|Qt
operator|::
name|KeyboardModifiers
name|keyboardModifiers
argument_list|()
block|;
specifier|static
name|Qt
operator|::
name|KeyboardModifiers
name|queryKeyboardModifiers
argument_list|()
block|;
specifier|static
name|Qt
operator|::
name|MouseButtons
name|mouseButtons
argument_list|()
block|;
specifier|static
name|void
name|setLayoutDirection
argument_list|(
argument|Qt::LayoutDirection direction
argument_list|)
block|;
specifier|static
name|Qt
operator|::
name|LayoutDirection
name|layoutDirection
argument_list|()
block|;
specifier|static
specifier|inline
name|bool
name|isRightToLeft
argument_list|()
block|{
return|return
name|layoutDirection
argument_list|()
operator|==
name|Qt
operator|::
name|RightToLeft
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isLeftToRight
argument_list|()
block|{
return|return
name|layoutDirection
argument_list|()
operator|==
name|Qt
operator|::
name|LeftToRight
return|;
block|}
specifier|static
name|QStyleHints
operator|*
name|styleHints
argument_list|()
block|;
specifier|static
name|void
name|setDesktopSettingsAware
argument_list|(
argument|bool on
argument_list|)
block|;
specifier|static
name|bool
name|desktopSettingsAware
argument_list|()
block|;
specifier|static
name|QInputMethod
operator|*
name|inputMethod
argument_list|()
block|;
specifier|static
name|QPlatformNativeInterface
operator|*
name|platformNativeInterface
argument_list|()
block|;
specifier|static
name|QFunctionPointer
name|platformFunction
argument_list|(
specifier|const
name|QByteArray
operator|&
name|function
argument_list|)
block|;
specifier|static
name|void
name|setQuitOnLastWindowClosed
argument_list|(
argument|bool quit
argument_list|)
block|;
specifier|static
name|bool
name|quitOnLastWindowClosed
argument_list|()
block|;
specifier|static
name|Qt
operator|::
name|ApplicationState
name|applicationState
argument_list|()
block|;
specifier|static
name|int
name|exec
argument_list|()
block|;
name|bool
name|notify
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_SESSIONMANAGER
comment|// session management
name|bool
name|isSessionRestored
argument_list|()
specifier|const
block|;
name|QString
name|sessionId
argument_list|()
specifier|const
block|;
name|QString
name|sessionKey
argument_list|()
specifier|const
block|;
name|bool
name|isSavingSession
argument_list|()
specifier|const
block|;
endif|#
directive|endif
specifier|static
name|void
name|sync
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|fontDatabaseChanged
argument_list|()
block|;
name|void
name|screenAdded
argument_list|(
name|QScreen
operator|*
name|screen
argument_list|)
block|;
name|void
name|screenRemoved
argument_list|(
name|QScreen
operator|*
name|screen
argument_list|)
block|;
name|void
name|lastWindowClosed
argument_list|()
block|;
name|void
name|focusObjectChanged
argument_list|(
name|QObject
operator|*
name|focusObject
argument_list|)
block|;
name|void
name|focusWindowChanged
argument_list|(
name|QWindow
operator|*
name|focusWindow
argument_list|)
block|;
name|void
name|applicationStateChanged
argument_list|(
argument|Qt::ApplicationState state
argument_list|)
block|;
name|void
name|layoutDirectionChanged
argument_list|(
argument|Qt::LayoutDirection direction
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_SESSIONMANAGER
name|void
name|commitDataRequest
argument_list|(
name|QSessionManager
operator|&
name|sessionManager
argument_list|)
block|;
name|void
name|saveStateRequest
argument_list|(
name|QSessionManager
operator|&
name|sessionManager
argument_list|)
block|;
endif|#
directive|endif
name|void
name|paletteChanged
argument_list|(
specifier|const
name|QPalette
operator|&
name|pal
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|bool
name|compressEvent
argument_list|(
name|QEvent
operator|*
argument_list|,
name|QObject
operator|*
name|receiver
argument_list|,
name|QPostEventList
operator|*
argument_list|)
block|;
name|QGuiApplication
argument_list|(
name|QGuiApplicationPrivate
operator|&
name|p
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGuiApplication
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGuiApplication
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateFocusObject(QObject *object)
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|friend
name|class
name|QGestureManager
block|;
endif|#
directive|endif
name|friend
name|class
name|QFontDatabasePrivate
block|;
name|friend
name|class
name|QPlatformIntegration
block|;
ifndef|#
directive|ifndef
name|QT_NO_SESSIONMANAGER
name|friend
name|class
name|QPlatformSessionManager
block|;
endif|#
directive|endif
block|}
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
comment|// QGUIAPPLICATION_H
end_comment
end_unit
