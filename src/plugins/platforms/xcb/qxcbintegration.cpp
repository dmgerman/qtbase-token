begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<EGL/egl.h>
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
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_GLX
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qglxintegration.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"qxcbeglsurface.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglplatformcontext_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
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
begin_include
include|#
directive|include
file|"../../../platformsupport/linuxaccessibility/bridge_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
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
parameter_list|)
member_init_list|:
name|m_eventDispatcher
argument_list|(
name|createUnixEventDispatcher
argument_list|()
argument_list|)
member_init_list|,
name|m_services
argument_list|(
operator|new
name|QGenericUnixServices
argument_list|)
block|{
name|QGuiApplicationPrivate
operator|::
name|instance
argument_list|()
operator|->
name|setEventDispatcher
argument_list|(
name|m_eventDispatcher
argument_list|)
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
name|m_connections
operator|<<
operator|new
name|QXcbConnection
argument_list|(
name|m_nativeInterface
operator|.
name|data
argument_list|()
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
name|parameters
operator|.
name|size
argument_list|()
operator|-
literal|1
condition|;
name|i
operator|+=
literal|2
control|)
block|{
ifdef|#
directive|ifdef
name|Q_XCB_DEBUG
name|qDebug
argument_list|()
operator|<<
literal|"QXcbIntegration: Connecting to additional display: "
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
endif|#
directive|endif
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
literal|':'
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
name|m_inputContext
operator|.
name|reset
argument_list|(
name|QPlatformInputContextFactory
operator|::
name|create
argument_list|()
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|m_accessibility
operator|.
name|reset
argument_list|(
operator|new
name|QSpiAccessibleBridge
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
operator|&&
name|defined
argument_list|(
name|XCB_USE_GLX
argument_list|)
name|qDeleteAll
argument_list|(
name|m_defaultContextInfos
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|qDeleteAll
argument_list|(
name|m_connections
argument_list|)
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
return|return
operator|new
name|QXcbWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
end_if
begin_class
DECL|class|QEGLXcbPlatformContext
class|class
name|QEGLXcbPlatformContext
super|:
specifier|public
name|QEGLPlatformContext
block|{
public|public:
DECL|function|QEGLXcbPlatformContext
name|QEGLXcbPlatformContext
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|glFormat
parameter_list|,
name|QPlatformOpenGLContext
modifier|*
name|share
parameter_list|,
name|EGLDisplay
name|display
parameter_list|,
name|QXcbConnection
modifier|*
name|c
parameter_list|)
member_init_list|:
name|QEGLPlatformContext
argument_list|(
name|glFormat
argument_list|,
name|share
argument_list|,
name|display
argument_list|)
member_init_list|,
name|m_connection
argument_list|(
name|c
argument_list|)
block|{
name|Q_XCB_NOOP
argument_list|(
name|m_connection
argument_list|)
expr_stmt|;
block|}
DECL|function|swapBuffers
name|void
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|Q_XCB_NOOP
argument_list|(
name|m_connection
argument_list|)
expr_stmt|;
name|QEGLPlatformContext
operator|::
name|swapBuffers
argument_list|(
name|surface
argument_list|)
expr_stmt|;
name|Q_XCB_NOOP
argument_list|(
name|m_connection
argument_list|)
expr_stmt|;
block|}
DECL|function|makeCurrent
name|bool
name|makeCurrent
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|Q_XCB_NOOP
argument_list|(
name|m_connection
argument_list|)
expr_stmt|;
name|bool
name|ret
init|=
name|QEGLPlatformContext
operator|::
name|makeCurrent
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|Q_XCB_NOOP
argument_list|(
name|m_connection
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
DECL|function|doneCurrent
name|void
name|doneCurrent
parameter_list|()
block|{
name|Q_XCB_NOOP
argument_list|(
name|m_connection
argument_list|)
expr_stmt|;
name|QEGLPlatformContext
operator|::
name|doneCurrent
argument_list|()
expr_stmt|;
name|Q_XCB_NOOP
argument_list|(
name|m_connection
argument_list|)
expr_stmt|;
block|}
DECL|function|eglSurfaceForPlatformSurface
name|EGLSurface
name|eglSurfaceForPlatformSurface
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
name|QXcbWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
operator|->
name|eglSurface
argument_list|()
operator|->
name|surface
argument_list|()
return|;
block|}
private|private:
DECL|member|m_connection
name|QXcbConnection
modifier|*
name|m_connection
decl_stmt|;
block|}
class|;
end_class
begin_endif
endif|#
directive|endif
end_endif
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
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_GLX
argument_list|)
name|QOpenGLDefaultContextInfo
modifier|*
name|defaultContextInfo
decl_stmt|;
if|if
condition|(
name|m_defaultContextInfos
operator|.
name|contains
argument_list|(
name|screen
argument_list|)
condition|)
block|{
name|defaultContextInfo
operator|=
name|m_defaultContextInfos
operator|.
name|value
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|defaultContextInfo
operator|=
name|QOpenGLDefaultContextInfo
operator|::
name|create
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|m_defaultContextInfos
operator|.
name|insert
argument_list|(
name|screen
argument_list|,
name|defaultContextInfo
argument_list|)
expr_stmt|;
block|}
return|return
operator|new
name|QGLXContext
argument_list|(
name|screen
argument_list|,
name|context
operator|->
name|format
argument_list|()
argument_list|,
name|context
operator|->
name|shareHandle
argument_list|()
argument_list|,
name|defaultContextInfo
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
return|return
operator|new
name|QEGLXcbPlatformContext
argument_list|(
name|context
operator|->
name|format
argument_list|()
argument_list|,
name|context
operator|->
name|shareHandle
argument_list|()
argument_list|,
name|screen
operator|->
name|connection
argument_list|()
operator|->
name|egl_display
argument_list|()
argument_list|,
name|screen
operator|->
name|connection
argument_list|()
argument_list|)
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"QXcbIntegration: Cannot create platform OpenGL context, neither GLX nor EGL are enabled"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
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
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_GLX
argument_list|)
case|case
name|OpenGL
case|:
return|return
name|m_connections
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|hasGLX
argument_list|()
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
case|case
name|OpenGL
case|:
return|return
literal|true
return|;
else|#
directive|else
case|case
name|OpenGL
case|:
return|return
literal|false
return|;
endif|#
directive|endif
case|case
name|ThreadedOpenGL
case|:
return|return
literal|false
return|;
case|case
name|WindowMasks
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
DECL|function|guiThreadEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QXcbIntegration
operator|::
name|guiThreadEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|m_eventDispatcher
return|;
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
begin_comment
comment|/*!   Called by QXcbConnection prior to a QQnxScreen being deleted.    Destroys and cleans up any default OpenGL context info for this screen. */
end_comment
begin_function
DECL|function|removeDefaultOpenGLContextInfo
name|void
name|QXcbIntegration
operator|::
name|removeDefaultOpenGLContextInfo
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
operator|&&
name|defined
argument_list|(
name|XCB_USE_GLX
argument_list|)
if|if
condition|(
operator|!
name|m_defaultContextInfos
operator|.
name|contains
argument_list|(
name|screen
argument_list|)
condition|)
return|return;
name|QOpenGLDefaultContextInfo
modifier|*
name|info
init|=
name|m_defaultContextInfos
operator|.
name|take
argument_list|(
name|screen
argument_list|)
decl_stmt|;
operator|delete
name|info
expr_stmt|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|screen
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
