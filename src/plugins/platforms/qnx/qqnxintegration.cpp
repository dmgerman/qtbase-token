begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxglobal.h"
end_include
begin_include
include|#
directive|include
file|"qqnxintegration.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNX_SCREENEVENTTHREAD
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qqnxscreeneventthread.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qqnxnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qqnxrasterbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreen.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreeneventhandler.h"
end_include
begin_include
include|#
directive|include
file|"qqnxwindow.h"
end_include
begin_include
include|#
directive|include
file|"qqnxnavigatoreventhandler.h"
end_include
begin_include
include|#
directive|include
file|"qqnxabstractnavigator.h"
end_include
begin_include
include|#
directive|include
file|"qqnxabstractvirtualkeyboard.h"
end_include
begin_include
include|#
directive|include
file|"qqnxservices.h"
end_include
begin_include
include|#
directive|include
file|"qqnxrasterwindow.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qqnxeglwindow.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNX_PPS
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qqnxnavigatorpps.h"
end_include
begin_include
include|#
directive|include
file|"qqnxnavigatoreventnotifier.h"
end_include
begin_include
include|#
directive|include
file|"qqnxvirtualkeyboardpps.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNX_PPS
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qqnxbuttoneventnotifier.h"
end_include
begin_include
include|#
directive|include
file|"qqnxclipboard.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNX_IMF
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qqnxinputcontext_imf.h"
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"qqnxinputcontext_noimf.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"private/qgenericunixfontdatabase_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qgenericunixeventdispatcher_p.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qqnxglcontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<private/qsimpledrag_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNXINTEGRATION_DEBUG
argument_list|)
end_if
begin_define
DECL|macro|qIntegrationDebug
define|#
directive|define
name|qIntegrationDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qIntegrationDebug
define|#
directive|define
name|qIntegrationDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|ms_windowMapper
name|QQnxWindowMapper
name|QQnxIntegration
operator|::
name|ms_windowMapper
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|ms_windowMapperMutex
name|QMutex
name|QQnxIntegration
operator|::
name|ms_windowMapperMutex
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|parseOptions
specifier|static
specifier|inline
name|QQnxIntegration
operator|::
name|Options
name|parseOptions
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paramList
parameter_list|)
block|{
name|QQnxIntegration
operator|::
name|Options
name|options
init|=
name|QQnxIntegration
operator|::
name|NoOptions
decl_stmt|;
if|if
condition|(
operator|!
name|paramList
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"no-fullscreen"
argument_list|)
argument_list|)
condition|)
block|{
name|options
operator||=
name|QQnxIntegration
operator|::
name|FullScreenApplication
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|paramList
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"flush-screen-context"
argument_list|)
argument_list|)
condition|)
block|{
name|options
operator||=
name|QQnxIntegration
operator|::
name|AlwaysFlushScreenContext
expr_stmt|;
block|}
if|if
condition|(
name|paramList
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"rootwindow"
argument_list|)
argument_list|)
condition|)
block|{
name|options
operator||=
name|QQnxIntegration
operator|::
name|RootWindow
expr_stmt|;
block|}
return|return
name|options
return|;
block|}
end_function
begin_constructor
DECL|function|QQnxIntegration
name|QQnxIntegration
operator|::
name|QQnxIntegration
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paramList
parameter_list|)
member_init_list|:
name|QPlatformIntegration
argument_list|()
if|#
directive|if
name|defined
argument_list|(
name|QQNX_SCREENEVENTTHREAD
argument_list|)
member_init_list|,
name|m_screenEventThread
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
member_init_list|,
name|m_navigatorEventHandler
argument_list|(
operator|new
name|QQnxNavigatorEventHandler
argument_list|()
argument_list|)
member_init_list|,
name|m_virtualKeyboard
argument_list|(
literal|0
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|QQNX_PPS
argument_list|)
member_init_list|,
name|m_navigatorEventNotifier
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_inputContext
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_buttonsNotifier
argument_list|(
operator|new
name|QQnxButtonEventNotifier
argument_list|()
argument_list|)
endif|#
directive|endif
member_init_list|,
name|m_services
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_fontDatabase
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|()
argument_list|)
member_init_list|,
name|m_eventDispatcher
argument_list|(
name|createUnixEventDispatcher
argument_list|()
argument_list|)
member_init_list|,
name|m_nativeInterface
argument_list|(
operator|new
name|QQnxNativeInterface
argument_list|(
name|this
argument_list|)
argument_list|)
member_init_list|,
name|m_screenEventHandler
argument_list|(
operator|new
name|QQnxScreenEventHandler
argument_list|(
name|this
argument_list|)
argument_list|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_CLIPBOARD
argument_list|)
member_init_list|,
name|m_clipboard
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
member_init_list|,
name|m_navigator
argument_list|(
literal|0
argument_list|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DRAGANDDROP
argument_list|)
member_init_list|,
name|m_drag
argument_list|(
operator|new
name|QSimpleDrag
argument_list|()
argument_list|)
endif|#
directive|endif
block|{
name|ms_options
operator|=
name|parseOptions
argument_list|(
name|paramList
argument_list|)
expr_stmt|;
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Open connection to QNX composition manager
name|Q_SCREEN_CRITICALERROR
argument_list|(
name|screen_create_context
argument_list|(
operator|&
name|ms_screenContext
argument_list|,
name|SCREEN_APPLICATION_CONTEXT
argument_list|)
argument_list|,
literal|"Failed to create screen context"
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QQNX_PPS
argument_list|)
comment|// Create/start navigator event notifier
name|m_navigatorEventNotifier
operator|=
operator|new
name|QQnxNavigatorEventNotifier
argument_list|(
name|m_navigatorEventHandler
argument_list|)
expr_stmt|;
comment|// delay invocation of start() to the time the event loop is up and running
comment|// needed to have the QThread internals of the main thread properly initialized
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|m_navigatorEventNotifier
argument_list|,
literal|"start"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
comment|// Initialize global OpenGL resources
name|QQnxGLContext
operator|::
name|initializeContext
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|// Create/start event thread
if|#
directive|if
name|defined
argument_list|(
name|QQNX_SCREENEVENTTHREAD
argument_list|)
name|m_screenEventThread
operator|=
operator|new
name|QQnxScreenEventThread
argument_list|(
name|ms_screenContext
argument_list|,
name|m_screenEventHandler
argument_list|)
expr_stmt|;
name|m_screenEventThread
operator|->
name|start
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|QQNX_PPS
argument_list|)
comment|// Create/start the keyboard class.
name|m_virtualKeyboard
operator|=
operator|new
name|QQnxVirtualKeyboardPps
argument_list|()
expr_stmt|;
comment|// delay invocation of start() to the time the event loop is up and running
comment|// needed to have the QThread internals of the main thread properly initialized
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|m_virtualKeyboard
argument_list|,
literal|"start"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|QQNX_PPS
argument_list|)
name|m_navigator
operator|=
operator|new
name|QQnxNavigatorPps
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|// Create services handling class
if|if
condition|(
name|m_navigator
condition|)
name|m_services
operator|=
operator|new
name|QQnxServices
argument_list|(
name|m_navigator
argument_list|)
expr_stmt|;
name|createDisplays
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_virtualKeyboard
condition|)
block|{
comment|// TODO check if we need to do this for all screens or only the primary one
name|QObject
operator|::
name|connect
argument_list|(
name|m_virtualKeyboard
argument_list|,
name|SIGNAL
argument_list|(
name|heightChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|primaryDisplay
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|keyboardHeightChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QQNX_PPS
argument_list|)
comment|// Set up the input context
name|m_inputContext
operator|=
operator|new
name|QQnxInputContext
argument_list|(
name|this
argument_list|,
operator|*
name|m_virtualKeyboard
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QQNX_IMF
argument_list|)
name|m_screenEventHandler
operator|->
name|addScreenEventFilter
argument_list|(
name|m_inputContext
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
if|#
directive|if
name|defined
argument_list|(
name|QQNX_PPS
argument_list|)
comment|// delay invocation of start() to the time the event loop is up and running
comment|// needed to have the QThread internals of the main thread properly initialized
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|m_buttonsNotifier
argument_list|,
literal|"start"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_destructor
DECL|function|~QQnxIntegration
name|QQnxIntegration
operator|::
name|~
name|QQnxIntegration
parameter_list|()
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"platform plugin shutdown begin"
expr_stmt|;
operator|delete
name|m_nativeInterface
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DRAGANDDROP
argument_list|)
comment|// Destroy the drag object
operator|delete
name|m_drag
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_CLIPBOARD
argument_list|)
comment|// Delete the clipboard
operator|delete
name|m_clipboard
expr_stmt|;
endif|#
directive|endif
comment|// Stop/destroy navigator event notifier
if|#
directive|if
name|defined
argument_list|(
name|QQNX_PPS
argument_list|)
operator|delete
name|m_navigatorEventNotifier
expr_stmt|;
endif|#
directive|endif
operator|delete
name|m_navigatorEventHandler
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QQNX_SCREENEVENTTHREAD
argument_list|)
comment|// Stop/destroy screen event thread
operator|delete
name|m_screenEventThread
expr_stmt|;
endif|#
directive|endif
comment|// In case the event-dispatcher was never transferred to QCoreApplication
operator|delete
name|m_eventDispatcher
expr_stmt|;
operator|delete
name|m_screenEventHandler
expr_stmt|;
comment|// Destroy all displays
name|destroyDisplays
argument_list|()
expr_stmt|;
comment|// Close connection to QNX composition manager
name|screen_destroy_context
argument_list|(
name|ms_screenContext
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
comment|// Cleanup global OpenGL resources
name|QQnxGLContext
operator|::
name|shutdownContext
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|QQNX_PPS
argument_list|)
comment|// Destroy the hardware button notifier
operator|delete
name|m_buttonsNotifier
expr_stmt|;
comment|// Destroy input context
operator|delete
name|m_inputContext
expr_stmt|;
endif|#
directive|endif
comment|// Destroy the keyboard class.
operator|delete
name|m_virtualKeyboard
expr_stmt|;
comment|// Destroy services class
operator|delete
name|m_services
expr_stmt|;
comment|// Destroy navigator interface
operator|delete
name|m_navigator
expr_stmt|;
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"platform plugin shutdown end"
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|hasCapability
name|bool
name|QQnxIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|MultipleWindows
case|:
case|case
name|ThreadedPixmaps
case|:
return|return
literal|true
return|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
case|case
name|OpenGL
case|:
case|case
name|ThreadedOpenGL
case|:
case|case
name|BufferQueueingOpenGL
case|:
return|return
literal|true
return|;
endif|#
directive|endif
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QQnxIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|QSurface
operator|::
name|SurfaceType
name|surfaceType
init|=
name|window
operator|->
name|surfaceType
argument_list|()
decl_stmt|;
specifier|const
name|bool
name|needRootWindow
init|=
name|options
argument_list|()
operator|&
name|RootWindow
decl_stmt|;
switch|switch
condition|(
name|surfaceType
condition|)
block|{
case|case
name|QSurface
operator|::
name|RasterSurface
case|:
return|return
operator|new
name|QQnxRasterWindow
argument_list|(
name|window
argument_list|,
name|ms_screenContext
argument_list|,
name|needRootWindow
argument_list|)
return|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
case|case
name|QSurface
operator|::
name|OpenGLSurface
case|:
return|return
operator|new
name|QQnxEglWindow
argument_list|(
name|window
argument_list|,
name|ms_screenContext
argument_list|,
name|needRootWindow
argument_list|)
return|;
endif|#
directive|endif
default|default:
name|qFatal
argument_list|(
literal|"QQnxWindow: unsupported window API"
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QQnxIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
return|return
operator|new
name|QQnxRasterBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
end_if
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QQnxIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
return|return
operator|new
name|QQnxGLContext
argument_list|(
name|context
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNX_PPS
argument_list|)
end_if
begin_function
DECL|function|inputContext
name|QPlatformInputContext
modifier|*
name|QQnxIntegration
operator|::
name|inputContext
parameter_list|()
specifier|const
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
return|return
name|m_inputContext
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|moveToScreen
name|void
name|QQnxIntegration
operator|::
name|moveToScreen
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|int
name|screen
parameter_list|)
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"w ="
operator|<<
name|window
operator|<<
literal|", s ="
operator|<<
name|screen
expr_stmt|;
comment|// get platform window used by widget
name|QQnxWindow
modifier|*
name|platformWindow
init|=
cast|static_cast
argument_list|<
name|QQnxWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
comment|// lookup platform screen by index
name|QQnxScreen
modifier|*
name|platformScreen
init|=
name|m_screens
operator|.
name|at
argument_list|(
name|screen
argument_list|)
decl_stmt|;
comment|// move the platform window to the platform screen
name|platformWindow
operator|->
name|setScreen
argument_list|(
name|platformScreen
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QQnxIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// We transfer ownersip of the event-dispatcher to QtCoreApplication
name|QAbstractEventDispatcher
modifier|*
name|eventDispatcher
init|=
name|m_eventDispatcher
decl_stmt|;
name|m_eventDispatcher
operator|=
literal|0
expr_stmt|;
return|return
name|eventDispatcher
return|;
block|}
end_function
begin_function
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QQnxIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
name|m_nativeInterface
return|;
block|}
end_function
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_CLIPBOARD
argument_list|)
end_if
begin_function
DECL|function|clipboard
name|QPlatformClipboard
modifier|*
name|QQnxIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QQNX_PPS
argument_list|)
if|if
condition|(
operator|!
name|m_clipboard
condition|)
name|m_clipboard
operator|=
operator|new
name|QQnxClipboard
expr_stmt|;
endif|#
directive|endif
return|return
name|m_clipboard
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DRAGANDDROP
argument_list|)
end_if
begin_function
DECL|function|drag
name|QPlatformDrag
modifier|*
name|QQnxIntegration
operator|::
name|drag
parameter_list|()
specifier|const
block|{
return|return
name|m_drag
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|styleHint
name|QVariant
name|QQnxIntegration
operator|::
name|styleHint
parameter_list|(
name|QPlatformIntegration
operator|::
name|StyleHint
name|hint
parameter_list|)
specifier|const
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
if|if
condition|(
operator|(
name|hint
operator|==
name|ShowIsFullScreen
operator|)
operator|&&
operator|(
name|ms_options
operator|&
name|FullScreenApplication
operator|)
condition|)
return|return
literal|true
return|;
return|return
name|QPlatformIntegration
operator|::
name|styleHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|services
name|QPlatformServices
modifier|*
name|QQnxIntegration
operator|::
name|services
parameter_list|()
specifier|const
block|{
return|return
name|m_services
return|;
block|}
end_function
begin_function
DECL|function|window
name|QWindow
modifier|*
name|QQnxIntegration
operator|::
name|window
parameter_list|(
name|screen_window_t
name|qnxWindow
parameter_list|)
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|ms_windowMapperMutex
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|locker
argument_list|)
expr_stmt|;
return|return
name|ms_windowMapper
operator|.
name|value
argument_list|(
name|qnxWindow
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|addWindow
name|void
name|QQnxIntegration
operator|::
name|addWindow
parameter_list|(
name|screen_window_t
name|qnxWindow
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|ms_windowMapperMutex
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|locker
argument_list|)
expr_stmt|;
name|ms_windowMapper
operator|.
name|insert
argument_list|(
name|qnxWindow
argument_list|,
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeWindow
name|void
name|QQnxIntegration
operator|::
name|removeWindow
parameter_list|(
name|screen_window_t
name|qnxWindow
parameter_list|)
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|ms_windowMapperMutex
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|locker
argument_list|)
expr_stmt|;
name|ms_windowMapper
operator|.
name|remove
argument_list|(
name|qnxWindow
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createDisplays
name|void
name|QQnxIntegration
operator|::
name|createDisplays
parameter_list|()
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Query number of displays
name|int
name|displayCount
init|=
literal|0
decl_stmt|;
name|int
name|result
init|=
name|screen_get_context_property_iv
argument_list|(
name|ms_screenContext
argument_list|,
name|SCREEN_PROPERTY_DISPLAY_COUNT
argument_list|,
operator|&
name|displayCount
argument_list|)
decl_stmt|;
name|Q_SCREEN_CRITICALERROR
argument_list|(
name|result
argument_list|,
literal|"Failed to query display count"
argument_list|)
expr_stmt|;
if|if
condition|(
name|displayCount
operator|<
literal|1
condition|)
block|{
comment|// Never happens, even if there's no display, libscreen returns 1
name|qFatal
argument_list|(
literal|"QQnxIntegration: displayCount=%d"
argument_list|,
name|displayCount
argument_list|)
expr_stmt|;
block|}
comment|// Get all displays
name|screen_display_t
modifier|*
name|displays
init|=
operator|(
name|screen_display_t
operator|*
operator|)
name|alloca
argument_list|(
sizeof|sizeof
argument_list|(
name|screen_display_t
argument_list|)
operator|*
name|displayCount
argument_list|)
decl_stmt|;
name|result
operator|=
name|screen_get_context_property_pv
argument_list|(
name|ms_screenContext
argument_list|,
name|SCREEN_PROPERTY_DISPLAYS
argument_list|,
operator|(
name|void
operator|*
operator|*
operator|)
name|displays
argument_list|)
expr_stmt|;
name|Q_SCREEN_CRITICALERROR
argument_list|(
name|result
argument_list|,
literal|"Failed to query displays"
argument_list|)
expr_stmt|;
comment|// If it's primary, we create a QScreen for it even if it's not attached
comment|// since Qt will dereference QGuiApplication::primaryScreen()
name|createDisplay
argument_list|(
name|displays
index|[
literal|0
index|]
argument_list|,
comment|/*isPrimary=*/
literal|true
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|displayCount
condition|;
name|i
operator|++
control|)
block|{
name|int
name|isAttached
init|=
literal|1
decl_stmt|;
name|result
operator|=
name|screen_get_display_property_iv
argument_list|(
name|displays
index|[
name|i
index|]
argument_list|,
name|SCREEN_PROPERTY_ATTACHED
argument_list|,
operator|&
name|isAttached
argument_list|)
expr_stmt|;
name|Q_SCREEN_CHECKERROR
argument_list|(
name|result
argument_list|,
literal|"Failed to query display attachment"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isAttached
condition|)
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Skipping non-attached display"
operator|<<
name|i
expr_stmt|;
continue|continue;
block|}
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Creating screen for display"
operator|<<
name|i
expr_stmt|;
name|createDisplay
argument_list|(
name|displays
index|[
name|i
index|]
argument_list|,
comment|/*isPrimary=*/
literal|false
argument_list|)
expr_stmt|;
block|}
comment|// of displays iteration
block|}
end_function
begin_function
DECL|function|createDisplay
name|void
name|QQnxIntegration
operator|::
name|createDisplay
parameter_list|(
name|screen_display_t
name|display
parameter_list|,
name|bool
name|isPrimary
parameter_list|)
block|{
name|QQnxScreen
modifier|*
name|screen
init|=
operator|new
name|QQnxScreen
argument_list|(
name|ms_screenContext
argument_list|,
name|display
argument_list|,
name|isPrimary
argument_list|)
decl_stmt|;
name|m_screens
operator|.
name|append
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|screenAdded
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|screen
operator|->
name|adjustOrientation
argument_list|()
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|m_screenEventHandler
argument_list|,
name|SIGNAL
argument_list|(
name|newWindowCreated
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
argument_list|,
name|screen
argument_list|,
name|SLOT
argument_list|(
name|newWindowCreated
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|m_screenEventHandler
argument_list|,
name|SIGNAL
argument_list|(
name|windowClosed
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
argument_list|,
name|screen
argument_list|,
name|SLOT
argument_list|(
name|windowClosed
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|m_navigatorEventHandler
argument_list|,
name|SIGNAL
argument_list|(
name|rotationChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|screen
argument_list|,
name|SLOT
argument_list|(
name|setRotation
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|m_navigatorEventHandler
argument_list|,
name|SIGNAL
argument_list|(
name|windowGroupActivated
argument_list|(
name|QByteArray
argument_list|)
argument_list|)
argument_list|,
name|screen
argument_list|,
name|SLOT
argument_list|(
name|activateWindowGroup
argument_list|(
name|QByteArray
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|m_navigatorEventHandler
argument_list|,
name|SIGNAL
argument_list|(
name|windowGroupDeactivated
argument_list|(
name|QByteArray
argument_list|)
argument_list|)
argument_list|,
name|screen
argument_list|,
name|SLOT
argument_list|(
name|deactivateWindowGroup
argument_list|(
name|QByteArray
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|m_navigatorEventHandler
argument_list|,
name|SIGNAL
argument_list|(
name|windowGroupStateChanged
argument_list|(
name|QByteArray
argument_list|,
name|Qt
operator|::
name|WindowState
argument_list|)
argument_list|)
argument_list|,
name|screen
argument_list|,
name|SLOT
argument_list|(
name|windowGroupStateChanged
argument_list|(
name|QByteArray
argument_list|,
name|Qt
operator|::
name|WindowState
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeDisplay
name|void
name|QQnxIntegration
operator|::
name|removeDisplay
parameter_list|(
name|QQnxScreen
modifier|*
name|screen
parameter_list|)
block|{
name|Q_CHECK_PTR
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|m_screens
operator|.
name|contains
argument_list|(
name|screen
argument_list|)
argument_list|)
expr_stmt|;
name|m_screens
operator|.
name|removeAll
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|destroyScreen
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|destroyDisplays
name|void
name|QQnxIntegration
operator|::
name|destroyDisplays
parameter_list|()
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|Q_FOREACH
argument_list|(
argument|QQnxScreen *screen
argument_list|,
argument|m_screens
argument_list|)
block|{
name|QPlatformIntegration
operator|::
name|destroyScreen
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
name|m_screens
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|screenForNative
name|QQnxScreen
modifier|*
name|QQnxIntegration
operator|::
name|screenForNative
parameter_list|(
name|screen_display_t
name|qnxScreen
parameter_list|)
specifier|const
block|{
name|Q_FOREACH
argument_list|(
argument|QQnxScreen *screen
argument_list|,
argument|m_screens
argument_list|)
block|{
if|if
condition|(
name|screen
operator|->
name|nativeDisplay
argument_list|()
operator|==
name|qnxScreen
condition|)
return|return
name|screen
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|primaryDisplay
name|QQnxScreen
modifier|*
name|QQnxIntegration
operator|::
name|primaryDisplay
parameter_list|()
specifier|const
block|{
return|return
name|m_screens
operator|.
name|first
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|options
name|QQnxIntegration
operator|::
name|Options
name|QQnxIntegration
operator|::
name|options
parameter_list|()
block|{
return|return
name|ms_options
return|;
block|}
end_function
begin_function
DECL|function|screenContext
name|screen_context_t
name|QQnxIntegration
operator|::
name|screenContext
parameter_list|()
block|{
return|return
name|ms_screenContext
return|;
block|}
end_function
begin_function
DECL|function|navigatorEventHandler
name|QQnxNavigatorEventHandler
modifier|*
name|QQnxIntegration
operator|::
name|navigatorEventHandler
parameter_list|()
block|{
return|return
name|m_navigatorEventHandler
return|;
block|}
end_function
begin_decl_stmt
DECL|member|ms_screenContext
name|screen_context_t
name|QQnxIntegration
operator|::
name|ms_screenContext
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|ms_options
name|QQnxIntegration
operator|::
name|Options
name|QQnxIntegration
operator|::
name|ms_options
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|supportsNavigatorEvents
name|bool
name|QQnxIntegration
operator|::
name|supportsNavigatorEvents
parameter_list|()
specifier|const
block|{
comment|// If QQNX_PPS is defined then we have navigator
return|return
name|m_navigator
operator|!=
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
