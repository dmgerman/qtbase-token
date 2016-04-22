begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbintegration.h"
end_include
begin_include
include|#
directive|include
file|"qxcbconnection.h"
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|"qxcbwindow.h"
end_include
begin_include
include|#
directive|include
file|"qxcbcursor.h"
end_include
begin_include
include|#
directive|include
file|"qxcbkeyboard.h"
end_include
begin_include
include|#
directive|include
file|"qxcbbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qxcbnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qxcbclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qxcbdrag.h"
end_include
begin_include
include|#
directive|include
file|"qxcbglintegration.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SESSIONMANAGER
end_ifndef
begin_include
include|#
directive|include
file|"qxcbsessionmanager.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixfontdatabase_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixservices_p.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_comment
comment|//this has to be included before egl, since egl pulls in X headers
end_comment
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|XCB_USE_EGL
end_ifdef
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qt_egl_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|XCB_USE_XLIB
end_ifdef
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontextfactory_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qgenericunixthemes_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOffscreenSurface>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|<qpa/qplatformaccessibility.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY_ATSPI_BRIDGE
end_ifndef
begin_include
include|#
directive|include
file|"../../../platformsupport/linuxaccessibility/bridge_p.h"
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
file|<QtCore/QFileInfo>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|// Find out if our parent process is gdb by looking at the 'exe' symlink under /proc,.
comment|// or, for older Linuxes, read out 'cmdline'.
DECL|function|runningUnderDebugger
specifier|static
name|bool
name|runningUnderDebugger
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|QT_DEBUG
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
specifier|const
name|QString
name|parentProc
init|=
name|QLatin1String
argument_list|(
literal|"/proc/"
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|getppid
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QFileInfo
name|parentProcExe
argument_list|(
name|parentProc
operator|+
name|QLatin1String
argument_list|(
literal|"/exe"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|parentProcExe
operator|.
name|isSymLink
argument_list|()
condition|)
return|return
name|parentProcExe
operator|.
name|symLinkTarget
argument_list|()
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"/gdb"
argument_list|)
argument_list|)
return|;
name|QFile
name|f
argument_list|(
name|parentProc
operator|+
name|QLatin1String
argument_list|(
literal|"/cmdline"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
return|return
literal|false
return|;
name|QByteArray
name|s
decl_stmt|;
name|char
name|c
decl_stmt|;
while|while
condition|(
name|f
operator|.
name|getChar
argument_list|(
operator|&
name|c
argument_list|)
operator|&&
name|c
condition|)
block|{
if|if
condition|(
name|c
operator|==
literal|'/'
condition|)
name|s
operator|.
name|clear
argument_list|()
expr_stmt|;
else|else
name|s
operator|+=
name|c
expr_stmt|;
block|}
return|return
name|s
operator|==
literal|"gdb"
return|;
else|#
directive|else
return|return
literal|false
return|;
endif|#
directive|endif
block|}
end_function
begin_decl_stmt
DECL|member|m_instance
name|QXcbIntegration
modifier|*
name|QXcbIntegration
operator|::
name|m_instance
init|=
name|Q_NULLPTR
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QXcbIntegration
name|QXcbIntegration
operator|::
name|QXcbIntegration
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|parameters
parameter_list|,
name|int
modifier|&
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
member_init_list|:
name|m_services
argument_list|(
operator|new
name|QGenericUnixServices
argument_list|)
member_init_list|,
name|m_instanceName
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_canGrab
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|m_defaultVisualId
argument_list|(
name|UINT_MAX
argument_list|)
block|{
name|m_instance
operator|=
name|this
expr_stmt|;
name|qRegisterMetaType
argument_list|<
name|QXcbWindow
operator|*
argument_list|>
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|XCB_USE_XLIB
name|XInitThreads
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|m_nativeInterface
operator|.
name|reset
argument_list|(
operator|new
name|QXcbNativeInterface
argument_list|)
expr_stmt|;
comment|// Parse arguments
specifier|const
name|char
modifier|*
name|displayName
init|=
literal|0
decl_stmt|;
name|bool
name|noGrabArg
init|=
literal|false
decl_stmt|;
name|bool
name|doGrabArg
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|argc
condition|)
block|{
name|int
name|j
init|=
literal|1
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|argc
condition|;
name|i
operator|++
control|)
block|{
name|QByteArray
name|arg
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
literal|"--"
argument_list|)
condition|)
name|arg
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|arg
operator|==
literal|"-display"
operator|&&
name|i
operator|<
name|argc
operator|-
literal|1
condition|)
name|displayName
operator|=
name|argv
index|[
operator|++
name|i
index|]
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
literal|"-name"
operator|&&
name|i
operator|<
name|argc
operator|-
literal|1
condition|)
name|m_instanceName
operator|=
name|argv
index|[
operator|++
name|i
index|]
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
literal|"-nograb"
condition|)
name|noGrabArg
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
literal|"-dograb"
condition|)
name|doGrabArg
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
literal|"-visual"
operator|&&
name|i
operator|<
name|argc
operator|-
literal|1
condition|)
block|{
name|bool
name|ok
init|=
literal|false
decl_stmt|;
name|m_defaultVisualId
operator|=
name|QByteArray
argument_list|(
name|argv
index|[
operator|++
name|i
index|]
argument_list|)
operator|.
name|toUInt
argument_list|(
operator|&
name|ok
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|m_defaultVisualId
operator|=
name|UINT_MAX
expr_stmt|;
block|}
else|else
name|argv
index|[
name|j
operator|++
index|]
operator|=
name|argv
index|[
name|i
index|]
expr_stmt|;
block|}
name|argc
operator|=
name|j
expr_stmt|;
block|}
comment|// argc
name|bool
name|underDebugger
init|=
name|runningUnderDebugger
argument_list|()
decl_stmt|;
if|if
condition|(
name|noGrabArg
operator|&&
name|doGrabArg
operator|&&
name|underDebugger
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Both -nograb and -dograb command line arguments specified. Please pick one. -nograb takes prcedence"
expr_stmt|;
name|doGrabArg
operator|=
literal|false
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|QT_DEBUG
argument_list|)
if|if
condition|(
operator|!
name|noGrabArg
operator|&&
operator|!
name|doGrabArg
operator|&&
name|underDebugger
condition|)
block|{
name|qDebug
argument_list|(
literal|"Qt: gdb: -nograb added to command-line options.\n"
literal|"\t Use the -dograb option to enforce grabbing."
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|m_canGrab
operator|=
operator|(
operator|!
name|underDebugger
operator|&&
operator|!
name|noGrabArg
operator|)
operator|||
operator|(
name|underDebugger
operator|&&
name|doGrabArg
operator|)
expr_stmt|;
specifier|static
name|bool
name|canNotGrabEnv
init|=
name|qEnvironmentVariableIsSet
argument_list|(
literal|"QT_XCB_NO_GRAB_SERVER"
argument_list|)
decl_stmt|;
if|if
condition|(
name|canNotGrabEnv
condition|)
name|m_canGrab
operator|=
literal|false
expr_stmt|;
specifier|const
name|int
name|numParameters
init|=
name|parameters
operator|.
name|size
argument_list|()
decl_stmt|;
name|m_connections
operator|.
name|reserve
argument_list|(
literal|1
operator|+
name|numParameters
operator|/
literal|2
argument_list|)
expr_stmt|;
name|m_connections
operator|<<
operator|new
name|QXcbConnection
argument_list|(
name|m_nativeInterface
operator|.
name|data
argument_list|()
argument_list|,
name|m_canGrab
argument_list|,
name|m_defaultVisualId
argument_list|,
name|displayName
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numParameters
operator|-
literal|1
condition|;
name|i
operator|+=
literal|2
control|)
block|{
name|qCDebug
argument_list|(
name|lcQpaScreen
argument_list|)
operator|<<
literal|"connecting to additional display: "
operator|<<
name|parameters
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|<<
name|parameters
operator|.
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
name|QString
name|display
init|=
name|parameters
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
operator|+
name|parameters
operator|.
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
decl_stmt|;
name|m_connections
operator|<<
operator|new
name|QXcbConnection
argument_list|(
name|m_nativeInterface
operator|.
name|data
argument_list|()
argument_list|,
name|m_canGrab
argument_list|,
name|m_defaultVisualId
argument_list|,
name|display
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|m_fontDatabase
operator|.
name|reset
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QXcbIntegration
name|QXcbIntegration
operator|::
name|~
name|QXcbIntegration
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|m_connections
argument_list|)
expr_stmt|;
name|m_instance
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QXcbIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|QXcbScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|QXcbGlIntegration
modifier|*
name|glIntegration
init|=
name|screen
operator|->
name|connection
argument_list|()
operator|->
name|glIntegration
argument_list|()
decl_stmt|;
if|if
condition|(
name|window
operator|->
name|type
argument_list|()
operator|!=
name|Qt
operator|::
name|Desktop
condition|)
block|{
if|if
condition|(
name|glIntegration
condition|)
block|{
name|QXcbWindow
modifier|*
name|xcbWindow
init|=
name|glIntegration
operator|->
name|createWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|xcbWindow
operator|->
name|create
argument_list|()
expr_stmt|;
return|return
name|xcbWindow
return|;
block|}
block|}
name|Q_ASSERT
argument_list|(
name|window
operator|->
name|type
argument_list|()
operator|==
name|Qt
operator|::
name|Desktop
operator|||
operator|!
name|window
operator|->
name|supportsOpenGL
argument_list|()
operator|||
operator|(
operator|!
name|glIntegration
operator|&&
name|window
operator|->
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|RasterGLSurface
operator|)
argument_list|)
expr_stmt|;
comment|// for VNC
name|QXcbWindow
modifier|*
name|xcbWindow
init|=
operator|new
name|QXcbWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|xcbWindow
operator|->
name|create
argument_list|()
expr_stmt|;
return|return
name|xcbWindow
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QXcbIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
name|QXcbScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|QXcbGlIntegration
modifier|*
name|glIntegration
init|=
name|screen
operator|->
name|connection
argument_list|()
operator|->
name|glIntegration
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|glIntegration
condition|)
block|{
name|qWarning
argument_list|(
literal|"QXcbIntegration: Cannot create platform OpenGL context, neither GLX nor EGL are enabled"
argument_list|)
expr_stmt|;
return|return
name|Q_NULLPTR
return|;
block|}
return|return
name|glIntegration
operator|->
name|createPlatformOpenGLContext
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
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QXcbIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QXcbBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOffscreenSurface
name|QPlatformOffscreenSurface
modifier|*
name|QXcbIntegration
operator|::
name|createPlatformOffscreenSurface
parameter_list|(
name|QOffscreenSurface
modifier|*
name|surface
parameter_list|)
specifier|const
block|{
name|QXcbScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|surface
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|QXcbGlIntegration
modifier|*
name|glIntegration
init|=
name|screen
operator|->
name|connection
argument_list|()
operator|->
name|glIntegration
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|glIntegration
condition|)
block|{
name|qWarning
argument_list|(
literal|"QXcbIntegration: Cannot create platform offscreen surface, neither GLX nor EGL are enabled"
argument_list|)
expr_stmt|;
return|return
name|Q_NULLPTR
return|;
block|}
return|return
name|glIntegration
operator|->
name|createPlatformOffscreenSurface
argument_list|(
name|surface
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QXcbIntegration
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
case|case
name|OpenGL
case|:
return|return
name|m_connections
operator|.
name|first
argument_list|()
operator|->
name|glIntegration
argument_list|()
return|;
case|case
name|ThreadedOpenGL
case|:
return|return
name|m_connections
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|threadedEventHandling
argument_list|()
operator|&&
name|m_connections
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|glIntegration
argument_list|()
operator|&&
name|m_connections
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|glIntegration
argument_list|()
operator|->
name|supportsThreadedOpenGL
argument_list|()
return|;
case|case
name|WindowMasks
case|:
return|return
literal|true
return|;
case|case
name|MultipleWindows
case|:
return|return
literal|true
return|;
case|case
name|ForeignWindows
case|:
return|return
literal|true
return|;
case|case
name|SyncState
case|:
return|return
literal|true
return|;
case|case
name|RasterGLSurface
case|:
return|return
literal|true
return|;
case|case
name|SwitchableWidgetComposition
case|:
return|return
literal|true
return|;
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
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QXcbIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
name|QAbstractEventDispatcher
modifier|*
name|dispatcher
init|=
name|createUnixEventDispatcher
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_connections
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
name|m_connections
index|[
name|i
index|]
operator|->
name|eventReader
argument_list|()
operator|->
name|registerEventDispatcher
argument_list|(
name|dispatcher
argument_list|)
expr_stmt|;
return|return
name|dispatcher
return|;
block|}
end_function
begin_function
DECL|function|initialize
name|void
name|QXcbIntegration
operator|::
name|initialize
parameter_list|()
block|{
comment|// Perform everything that may potentially need the event dispatcher (timers, socket
comment|// notifiers) here instead of the constructor.
name|QString
name|icStr
init|=
name|QPlatformInputContextFactory
operator|::
name|requested
argument_list|()
decl_stmt|;
if|if
condition|(
name|icStr
operator|.
name|isNull
argument_list|()
condition|)
name|icStr
operator|=
name|QLatin1String
argument_list|(
literal|"compose"
argument_list|)
expr_stmt|;
name|m_inputContext
operator|.
name|reset
argument_list|(
name|QPlatformInputContextFactory
operator|::
name|create
argument_list|(
name|icStr
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|moveToScreen
name|void
name|QXcbIntegration
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
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QXcbIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|m_fontDatabase
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QXcbIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
name|m_nativeInterface
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_function
DECL|function|clipboard
name|QPlatformClipboard
modifier|*
name|QXcbIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
return|return
name|m_connections
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|clipboard
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_function
DECL|function|drag
name|QPlatformDrag
modifier|*
name|QXcbIntegration
operator|::
name|drag
parameter_list|()
specifier|const
block|{
return|return
name|m_connections
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|drag
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|inputContext
name|QPlatformInputContext
modifier|*
name|QXcbIntegration
operator|::
name|inputContext
parameter_list|()
specifier|const
block|{
return|return
name|m_inputContext
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_function
DECL|function|accessibility
name|QPlatformAccessibility
modifier|*
name|QXcbIntegration
operator|::
name|accessibility
parameter_list|()
specifier|const
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_ACCESSIBILITY_ATSPI_BRIDGE
argument_list|)
if|if
condition|(
operator|!
name|m_accessibility
condition|)
block|{
name|Q_ASSERT_X
argument_list|(
name|QCoreApplication
operator|::
name|eventDispatcher
argument_list|()
argument_list|,
literal|"QXcbIntegration"
argument_list|,
literal|"Initializing accessibility without event-dispatcher!"
argument_list|)
expr_stmt|;
name|m_accessibility
operator|.
name|reset
argument_list|(
operator|new
name|QSpiAccessibleBridge
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|m_accessibility
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|services
name|QPlatformServices
modifier|*
name|QXcbIntegration
operator|::
name|services
parameter_list|()
specifier|const
block|{
return|return
name|m_services
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|queryKeyboardModifiers
name|Qt
operator|::
name|KeyboardModifiers
name|QXcbIntegration
operator|::
name|queryKeyboardModifiers
parameter_list|()
specifier|const
block|{
name|int
name|keybMask
init|=
literal|0
decl_stmt|;
name|QXcbConnection
modifier|*
name|conn
init|=
name|m_connections
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QXcbCursor
operator|::
name|queryPointer
argument_list|(
name|conn
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|keybMask
argument_list|)
expr_stmt|;
return|return
name|conn
operator|->
name|keyboard
argument_list|()
operator|->
name|translateModifiers
argument_list|(
name|keybMask
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|possibleKeys
name|QList
argument_list|<
name|int
argument_list|>
name|QXcbIntegration
operator|::
name|possibleKeys
parameter_list|(
specifier|const
name|QKeyEvent
modifier|*
name|e
parameter_list|)
specifier|const
block|{
return|return
name|m_connections
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|keyboard
argument_list|()
operator|->
name|possibleKeys
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|themeNames
name|QStringList
name|QXcbIntegration
operator|::
name|themeNames
parameter_list|()
specifier|const
block|{
return|return
name|QGenericUnixTheme
operator|::
name|themeNames
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createPlatformTheme
name|QPlatformTheme
modifier|*
name|QXcbIntegration
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
return|return
name|QGenericUnixTheme
operator|::
name|createUnixTheme
argument_list|(
name|name
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|styleHint
name|QVariant
name|QXcbIntegration
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
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|QPlatformIntegration
operator|::
name|CursorFlashTime
case|:
case|case
name|QPlatformIntegration
operator|::
name|KeyboardInputInterval
case|:
case|case
name|QPlatformIntegration
operator|::
name|MouseDoubleClickInterval
case|:
case|case
name|QPlatformIntegration
operator|::
name|StartDragTime
case|:
case|case
name|QPlatformIntegration
operator|::
name|KeyboardAutoRepeatRate
case|:
case|case
name|QPlatformIntegration
operator|::
name|PasswordMaskDelay
case|:
case|case
name|QPlatformIntegration
operator|::
name|StartDragVelocity
case|:
case|case
name|QPlatformIntegration
operator|::
name|UseRtlExtensions
case|:
case|case
name|QPlatformIntegration
operator|::
name|PasswordMaskCharacter
case|:
comment|// TODO using various xcb, gnome or KDE settings
break|break;
comment|// Not implemented, use defaults
case|case
name|QPlatformIntegration
operator|::
name|FontSmoothingGamma
case|:
comment|// Match Qt 4.8 text rendering, and rendering of other X11 toolkits.
return|return
name|qreal
argument_list|(
literal|1.0
argument_list|)
return|;
case|case
name|QPlatformIntegration
operator|::
name|StartDragDistance
case|:
block|{
comment|// The default (in QPlatformTheme::defaultThemeHint) is 10 pixels, but
comment|// on a high-resolution screen it makes sense to increase it.
name|qreal
name|dpi
init|=
literal|100.0
decl_stmt|;
if|if
condition|(
specifier|const
name|QXcbScreen
modifier|*
name|screen
init|=
name|defaultConnection
argument_list|()
operator|->
name|primaryScreen
argument_list|()
condition|)
block|{
if|if
condition|(
name|screen
operator|->
name|logicalDpi
argument_list|()
operator|.
name|first
operator|>
name|dpi
condition|)
name|dpi
operator|=
name|screen
operator|->
name|logicalDpi
argument_list|()
operator|.
name|first
expr_stmt|;
if|if
condition|(
name|screen
operator|->
name|logicalDpi
argument_list|()
operator|.
name|second
operator|>
name|dpi
condition|)
name|dpi
operator|=
name|screen
operator|->
name|logicalDpi
argument_list|()
operator|.
name|second
expr_stmt|;
block|}
return|return
literal|10.0
operator|*
name|dpi
operator|/
literal|100.0
return|;
block|}
case|case
name|QPlatformIntegration
operator|::
name|ShowIsFullScreen
case|:
comment|// X11 always has support for windows, but the
comment|// window manager could prevent it (e.g. matchbox)
return|return
literal|false
return|;
case|case
name|QPlatformIntegration
operator|::
name|ReplayMousePressOutsidePopup
case|:
return|return
literal|false
return|;
default|default:
break|break;
block|}
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
DECL|function|argv0BaseName
specifier|static
name|QString
name|argv0BaseName
parameter_list|()
block|{
name|QString
name|result
decl_stmt|;
specifier|const
name|QStringList
name|arguments
init|=
name|QCoreApplication
operator|::
name|arguments
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|arguments
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|arguments
operator|.
name|front
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|result
operator|=
name|arguments
operator|.
name|front
argument_list|()
expr_stmt|;
specifier|const
name|int
name|lastSlashPos
init|=
name|result
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|lastSlashPos
operator|!=
operator|-
literal|1
condition|)
name|result
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
name|lastSlashPos
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|resourceNameVar
specifier|static
specifier|const
name|char
name|resourceNameVar
index|[]
init|=
literal|"RESOURCE_NAME"
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|wmClass
name|QByteArray
name|QXcbIntegration
operator|::
name|wmClass
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_wmClass
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// Instance name according to ICCCM 4.1.2.5
name|QString
name|name
decl_stmt|;
if|if
condition|(
name|m_instanceName
condition|)
name|name
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|m_instanceName
argument_list|)
expr_stmt|;
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
operator|&&
name|qEnvironmentVariableIsSet
argument_list|(
name|resourceNameVar
argument_list|)
condition|)
name|name
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
name|resourceNameVar
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
name|name
operator|=
name|argv0BaseName
argument_list|()
expr_stmt|;
comment|// Note: QCoreApplication::applicationName() cannot be called from the QGuiApplication constructor,
comment|// hence this delayed initialization.
name|QString
name|className
init|=
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
decl_stmt|;
if|if
condition|(
name|className
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|className
operator|=
name|argv0BaseName
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|className
operator|.
name|isEmpty
argument_list|()
operator|&&
name|className
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|isLower
argument_list|()
condition|)
name|className
index|[
literal|0
index|]
operator|=
name|className
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toUpper
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|name
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|className
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|m_wmClass
operator|=
name|name
operator|.
name|toLocal8Bit
argument_list|()
expr_stmt|;
name|m_wmClass
operator|.
name|append
argument_list|(
literal|'\0'
argument_list|)
expr_stmt|;
name|m_wmClass
operator|.
name|append
argument_list|(
name|className
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
expr_stmt|;
name|m_wmClass
operator|.
name|append
argument_list|(
literal|'\0'
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|m_wmClass
return|;
block|}
end_function
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_SESSIONMANAGER
argument_list|)
operator|&&
name|defined
argument_list|(
name|XCB_USE_SM
argument_list|)
end_if
begin_function
DECL|function|createPlatformSessionManager
name|QPlatformSessionManager
modifier|*
name|QXcbIntegration
operator|::
name|createPlatformSessionManager
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|,
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QXcbSessionManager
argument_list|(
name|id
argument_list|,
name|key
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|sync
name|void
name|QXcbIntegration
operator|::
name|sync
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_connections
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|m_connections
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|sync
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
