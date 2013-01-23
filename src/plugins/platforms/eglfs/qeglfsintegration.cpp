begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qeglfswindow.h"
end_include
begin_include
include|#
directive|include
file|"qeglfsbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qeglfshooks.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixfontdatabase_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglplatformcontext_p.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EVDEV
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qevdevmousemanager_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qevdevkeyboardmanager_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qevdevtouch_p.h>
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
file|<QtGui/QSurfaceFormat>
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
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|"qeglfscontext.h"
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEglFSIntegration
name|QEglFSIntegration
operator|::
name|QEglFSIntegration
parameter_list|()
member_init_list|:
name|mEventDispatcher
argument_list|(
name|createUnixEventDispatcher
argument_list|()
argument_list|)
member_init_list|,
name|mFontDb
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|()
argument_list|)
block|{
name|QGuiApplicationPrivate
operator|::
name|instance
argument_list|()
operator|->
name|setEventDispatcher
argument_list|(
name|mEventDispatcher
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EVDEV
argument_list|)
operator|new
name|QEvdevKeyboardManager
argument_list|(
name|QLatin1String
argument_list|(
literal|"EvdevKeyboard"
argument_list|)
argument_list|,
name|QString
argument_list|()
comment|/* spec */
argument_list|,
name|this
argument_list|)
expr_stmt|;
operator|new
name|QEvdevMouseManager
argument_list|(
name|QLatin1String
argument_list|(
literal|"EvdevMouse"
argument_list|)
argument_list|,
name|QString
argument_list|()
comment|/* spec */
argument_list|,
name|this
argument_list|)
expr_stmt|;
operator|new
name|QEvdevTouchScreenHandlerThread
argument_list|(
name|QString
argument_list|()
comment|/* spec */
argument_list|,
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|hooks
operator|->
name|platformInit
argument_list|()
expr_stmt|;
name|EGLint
name|major
decl_stmt|,
name|minor
decl_stmt|;
if|if
condition|(
operator|!
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not bind GL_ES API\n"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGL error"
argument_list|)
expr_stmt|;
block|}
name|mDisplay
operator|=
name|eglGetDisplay
argument_list|(
name|hooks
condition|?
name|hooks
operator|->
name|platformDisplay
argument_list|()
else|:
name|EGL_DEFAULT_DISPLAY
argument_list|)
expr_stmt|;
if|if
condition|(
name|mDisplay
operator|==
name|EGL_NO_DISPLAY
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not open egl display\n"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGL error"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|eglInitialize
argument_list|(
name|mDisplay
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not initialize egl display\n"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGL error"
argument_list|)
expr_stmt|;
block|}
name|int
name|swapInterval
init|=
literal|1
decl_stmt|;
name|QByteArray
name|swapIntervalString
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_SWAPINTERVAL"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|swapIntervalString
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|bool
name|ok
decl_stmt|;
name|swapInterval
operator|=
name|swapIntervalString
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|swapInterval
operator|=
literal|1
expr_stmt|;
block|}
name|eglSwapInterval
argument_list|(
name|mDisplay
argument_list|,
name|swapInterval
argument_list|)
expr_stmt|;
name|mScreen
operator|=
operator|new
name|QEglFSScreen
argument_list|(
name|mDisplay
argument_list|)
expr_stmt|;
name|screenAdded
argument_list|(
name|mScreen
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEglFSIntegration
name|QEglFSIntegration
operator|::
name|~
name|QEglFSIntegration
parameter_list|()
block|{
operator|delete
name|mScreen
expr_stmt|;
name|eglTerminate
argument_list|(
name|mDisplay
argument_list|)
expr_stmt|;
name|hooks
operator|->
name|platformDestroy
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|hasCapability
name|bool
name|QEglFSIntegration
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
comment|// We assume that devices will have more and not less capabilities
if|if
condition|(
name|hooks
operator|&&
name|hooks
operator|->
name|hasCapability
argument_list|(
name|cap
argument_list|)
condition|)
return|return
literal|true
return|;
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
literal|true
return|;
case|case
name|ThreadedOpenGL
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
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QEglFSIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|QPlatformWindow
modifier|*
name|w
init|=
operator|new
name|QEglFSWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|w
operator|->
name|requestActivateWindow
argument_list|()
expr_stmt|;
return|return
name|w
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QEglFSIntegration
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
name|QEglFSBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QEglFSIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QEglFSContext
argument_list|(
name|hooks
operator|->
name|surfaceFormatFor
argument_list|(
name|context
operator|->
name|format
argument_list|()
argument_list|)
argument_list|,
name|context
operator|->
name|shareHandle
argument_list|()
argument_list|,
name|mDisplay
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QEglFSIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|mFontDb
return|;
block|}
end_function
begin_function
DECL|function|guiThreadEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QEglFSIntegration
operator|::
name|guiThreadEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|mEventDispatcher
return|;
block|}
end_function
begin_function
DECL|function|styleHint
name|QVariant
name|QEglFSIntegration
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
if|if
condition|(
name|hint
operator|==
name|QPlatformIntegration
operator|::
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
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QEglFSIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
cast|const_cast
argument_list|<
name|QEglFSIntegration
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForIntegration
name|void
modifier|*
name|QEglFSIntegration
operator|::
name|nativeResourceForIntegration
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
name|QByteArray
name|lowerCaseResource
init|=
name|resource
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
name|lowerCaseResource
operator|==
literal|"egldisplay"
condition|)
return|return
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|mScreen
argument_list|)
operator|->
name|display
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForContext
name|void
modifier|*
name|QEglFSIntegration
operator|::
name|nativeResourceForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|QByteArray
name|lowerCaseResource
init|=
name|resource
operator|.
name|toLower
argument_list|()
decl_stmt|;
name|QEGLPlatformContext
modifier|*
name|handle
init|=
cast|static_cast
argument_list|<
name|QEGLPlatformContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|handle
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|lowerCaseResource
operator|==
literal|"eglcontext"
condition|)
return|return
name|handle
operator|->
name|eglContext
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|chooseConfig
name|EGLConfig
name|QEglFSIntegration
operator|::
name|chooseConfig
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
class|class
name|Chooser
super|:
specifier|public
name|QEglConfigChooser
block|{
public|public:
name|Chooser
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
name|QEglFSHooks
modifier|*
name|hooks
parameter_list|)
member_init_list|:
name|QEglConfigChooser
argument_list|(
name|display
argument_list|)
member_init_list|,
name|m_hooks
argument_list|(
name|hooks
argument_list|)
block|{         }
protected|protected:
name|bool
name|filterConfig
parameter_list|(
name|EGLConfig
name|config
parameter_list|)
specifier|const
block|{
return|return
name|m_hooks
operator|->
name|filterConfig
argument_list|(
name|display
argument_list|()
argument_list|,
name|config
argument_list|)
operator|&&
name|QEglConfigChooser
operator|::
name|filterConfig
argument_list|(
name|config
argument_list|)
return|;
block|}
private|private:
name|QEglFSHooks
modifier|*
name|m_hooks
decl_stmt|;
block|}
class|;
name|Chooser
name|chooser
argument_list|(
name|display
argument_list|,
name|hooks
argument_list|)
decl_stmt|;
name|chooser
operator|.
name|setSurfaceFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
return|return
name|chooser
operator|.
name|chooseConfig
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
