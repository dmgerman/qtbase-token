begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxintegration.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreeneventthread.h"
end_include
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
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BLACKBERRY
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qqnxbpseventfilter.h"
end_include
begin_include
include|#
directive|include
file|"qqnxnavigatorbps.h"
end_include
begin_include
include|#
directive|include
file|"qqnxtheme.h"
end_include
begin_include
include|#
directive|include
file|"qqnxvirtualkeyboardbps.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|QQNX_PPS
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"qqnxnavigatorpps.h"
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
file|"qqnxnavigatoreventnotifier.h"
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
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BLACKBERRY
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qqnxeventdispatcher_blackberry.h"
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"private/qgenericunixeventdispatcher_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
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
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QQNXINTEGRATION_DEBUG
end_ifdef
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
begin_constructor
DECL|function|QQnxIntegration
name|QQnxIntegration
operator|::
name|QQnxIntegration
parameter_list|()
member_init_list|:
name|QPlatformIntegration
argument_list|()
member_init_list|,
name|m_screenEventThread
argument_list|(
literal|0
argument_list|)
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
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BLACKBERRY
argument_list|)
member_init_list|,
name|m_eventDispatcher
argument_list|(
operator|new
name|QQnxEventDispatcherBlackberry
argument_list|()
argument_list|)
member_init_list|,
name|m_bpsEventFilter
argument_list|(
literal|0
argument_list|)
else|#
directive|else
member_init_list|,
name|m_eventDispatcher
argument_list|(
name|createUnixEventDispatcher
argument_list|()
argument_list|)
endif|#
directive|endif
member_init_list|,
name|m_nativeInterface
argument_list|(
operator|new
name|QQnxNativeInterface
argument_list|()
argument_list|)
member_init_list|,
name|m_screenEventHandler
argument_list|(
operator|new
name|QQnxScreenEventHandler
argument_list|()
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
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Open connection to QNX composition manager
name|errno
operator|=
literal|0
expr_stmt|;
name|int
name|result
init|=
name|screen_create_context
argument_list|(
operator|&
name|m_screenContext
argument_list|,
name|SCREEN_APPLICATION_CONTEXT
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
block|{
name|qFatal
argument_list|(
literal|"QQnx: failed to connect to composition manager, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
comment|// Not on BlackBerry, it has specialized event dispatcher which also handles navigator events
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_BLACKBERRY
argument_list|)
operator|&&
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
name|initialize
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
name|m_screenContext
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
comment|// Not on BlackBerry, it has specialized event dispatcher which also handles virtual keyboard events
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_BLACKBERRY
argument_list|)
operator|&&
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
name|Q_OS_BLACKBERRY
argument_list|)
name|m_navigator
operator|=
operator|new
name|QQnxNavigatorBps
argument_list|()
expr_stmt|;
elif|#
directive|elif
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
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BLACKBERRY
argument_list|)
name|QQnxVirtualKeyboardBps
modifier|*
name|virtualKeyboardBps
init|=
operator|new
name|QQnxVirtualKeyboardBps
decl_stmt|;
name|m_bpsEventFilter
operator|=
operator|new
name|QQnxBpsEventFilter
argument_list|(
name|m_navigatorEventHandler
argument_list|,
operator|(
name|m_screenEventThread
condition|?
literal|0
else|:
name|m_screenEventHandler
operator|)
argument_list|,
name|virtualKeyboardBps
argument_list|)
expr_stmt|;
name|m_bpsEventFilter
operator|->
name|installOnEventDispatcher
argument_list|(
name|m_eventDispatcher
argument_list|)
expr_stmt|;
name|m_virtualKeyboard
operator|=
name|virtualKeyboardBps
expr_stmt|;
endif|#
directive|endif
comment|// Create displays for all possible screens (which may not be attached). We have to do this
comment|// *after* the call to m_bpsEventFilter->installOnEventDispatcher(m_eventDispatcher). The
comment|// reason for this is that we have to be registered for NAVIGATOR events before we create the
comment|// QQnxScreen objects, and hence the QQnxRootWindow's. It is when the NAVIGATOR service sees
comment|// the window creation that it starts sending us messages which results in a race if we
comment|// create the displays first.
name|createDisplays
argument_list|()
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QQNX_SCREENEVENTTHREAD
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_OS_BLACKBERRY
argument_list|)
comment|// Register for screen domain events with bps
name|Q_FOREACH
argument_list|(
argument|QQnxScreen *screen
argument_list|,
argument|m_screens
argument_list|)
name|m_bpsEventFilter
operator|->
name|registerForScreenEvents
argument_list|(
name|screen
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
operator|*
name|m_virtualKeyboard
argument_list|)
expr_stmt|;
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
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_BLACKBERRY
argument_list|)
name|Q_FOREACH
argument_list|(
argument|QQnxScreen *screen
argument_list|,
argument|m_screens
argument_list|)
name|m_bpsEventFilter
operator|->
name|unregisterForScreenEvents
argument_list|(
name|screen
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BLACKBERRY
argument_list|)
operator|delete
name|m_bpsEventFilter
expr_stmt|;
endif|#
directive|endif
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
name|m_screenContext
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
name|shutdown
argument_list|()
expr_stmt|;
endif|#
directive|endif
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
name|ThreadedPixmaps
case|:
return|return
literal|true
return|;
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES
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
return|return
operator|new
name|QQnxWindow
argument_list|(
name|window
argument_list|,
name|m_screenContext
argument_list|)
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
DECL|function|guiThreadEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QQnxIntegration
operator|::
name|guiThreadEventDispatcher
parameter_list|()
specifier|const
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
return|return
name|m_eventDispatcher
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
block|{
name|m_clipboard
operator|=
operator|new
name|QQnxClipboard
expr_stmt|;
block|}
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
name|hint
operator|==
name|ShowIsFullScreen
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
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BLACKBERRY
argument_list|)
end_if
begin_function
DECL|function|themeNames
name|QStringList
name|QQnxIntegration
operator|::
name|themeNames
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|(
name|QQnxTheme
operator|::
name|name
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformTheme
name|QPlatformTheme
modifier|*
name|QQnxIntegration
operator|::
name|createPlatformTheme
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"name ="
operator|<<
name|name
expr_stmt|;
if|if
condition|(
name|name
operator|==
name|QQnxTheme
operator|::
name|name
argument_list|()
condition|)
return|return
operator|new
name|QQnxTheme
argument_list|(
name|m_fontDatabase
argument_list|,
name|m_bpsEventFilter
argument_list|)
return|;
return|return
name|QPlatformIntegration
operator|::
name|createPlatformTheme
argument_list|(
name|name
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
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
name|errno
operator|=
literal|0
expr_stmt|;
name|int
name|displayCount
decl_stmt|;
name|int
name|result
init|=
name|screen_get_context_property_iv
argument_list|(
name|m_screenContext
argument_list|,
name|SCREEN_PROPERTY_DISPLAY_COUNT
argument_list|,
operator|&
name|displayCount
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
block|{
name|qFatal
argument_list|(
literal|"QQnxIntegration: failed to query display count, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
comment|// Get all displays
name|errno
operator|=
literal|0
expr_stmt|;
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
name|m_screenContext
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
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
block|{
name|qFatal
argument_list|(
literal|"QQnxIntegration: failed to query displays, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|displayCount
condition|;
name|i
operator|++
control|)
block|{
name|qIntegrationDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Creating screen for display"
operator|<<
name|i
expr_stmt|;
name|QQnxScreen
modifier|*
name|screen
init|=
operator|new
name|QQnxScreen
argument_list|(
name|m_screenContext
argument_list|,
name|displays
index|[
name|i
index|]
argument_list|,
name|i
operator|==
literal|0
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
block|}
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
name|qDeleteAll
argument_list|(
name|m_screens
argument_list|)
expr_stmt|;
name|m_screens
operator|.
name|clear
argument_list|()
expr_stmt|;
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
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
