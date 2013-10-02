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
file|<QtPlatformSupport/private/qgenericunixservices_p.h>
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
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglpbuffer_p.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EVDEV
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_ANDROID_NO_SDK
argument_list|)
operator|)
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
file|<QtGui/QOffscreenSurface>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontextfactory_p.h>
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
begin_function_decl
name|QT_BEGIN_NAMESPACE
specifier|static
name|void
modifier|*
name|eglContextForContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl
begin_constructor
DECL|function|QEglFSIntegration
name|QEglFSIntegration
operator|::
name|QEglFSIntegration
parameter_list|()
member_init_list|:
name|mFontDb
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|)
member_init_list|,
name|mServices
argument_list|(
operator|new
name|QGenericUnixServices
argument_list|)
member_init_list|,
name|mInputContext
argument_list|(
literal|0
argument_list|)
block|{
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
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
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
condition|?
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
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
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
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
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|&&
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
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
case|case
name|WindowManagement
case|:
return|return
literal|false
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
name|QEglFSWindow
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
name|create
argument_list|()
expr_stmt|;
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
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
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
DECL|function|createPlatformOffscreenSurface
name|QPlatformOffscreenSurface
modifier|*
name|QEglFSIntegration
operator|::
name|createPlatformOffscreenSurface
parameter_list|(
name|QOffscreenSurface
modifier|*
name|surface
parameter_list|)
specifier|const
block|{
name|QEglFSScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QEglFSScreen
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
return|return
operator|new
name|QEGLPbuffer
argument_list|(
name|screen
operator|->
name|display
argument_list|()
argument_list|,
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|surfaceFormatFor
argument_list|(
name|surface
operator|->
name|requestedFormat
argument_list|()
argument_list|)
argument_list|,
name|surface
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
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QEglFSIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|createUnixEventDispatcher
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|initialize
name|void
name|QEglFSIntegration
operator|::
name|initialize
parameter_list|()
block|{
name|mInputContext
operator|=
name|QPlatformInputContextFactory
operator|::
name|create
argument_list|()
expr_stmt|;
name|createInputHandlers
argument_list|()
expr_stmt|;
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
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|QPlatformIntegration
operator|::
name|ShowIsFullScreen
case|:
return|return
name|mScreen
operator|->
name|rootWindow
argument_list|()
operator|==
literal|0
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|styleHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|services
name|QPlatformServices
modifier|*
name|QEglFSIntegration
operator|::
name|services
parameter_list|()
specifier|const
block|{
return|return
name|mServices
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
begin_enum
DECL|enum|ResourceType
enum|enum
name|ResourceType
block|{
DECL|enumerator|EglDisplay
name|EglDisplay
block|,
DECL|enumerator|EglWindow
name|EglWindow
block|,
DECL|enumerator|EglContext
name|EglContext
block|}
enum|;
end_enum
begin_function
DECL|function|resourceType
specifier|static
name|int
name|resourceType
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
block|{
specifier|static
specifier|const
name|QByteArray
name|names
index|[]
init|=
block|{
comment|// match ResourceType
name|QByteArrayLiteral
argument_list|(
literal|"egldisplay"
argument_list|)
block|,
name|QByteArrayLiteral
argument_list|(
literal|"eglwindow"
argument_list|)
block|,
name|QByteArrayLiteral
argument_list|(
literal|"eglcontext"
argument_list|)
block|}
decl_stmt|;
specifier|const
name|QByteArray
modifier|*
name|end
init|=
name|names
operator|+
sizeof|sizeof
argument_list|(
name|names
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|names
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
specifier|const
name|QByteArray
modifier|*
name|result
init|=
name|std
operator|::
name|find
argument_list|(
name|names
argument_list|,
name|end
argument_list|,
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|==
name|end
condition|)
name|result
operator|=
name|std
operator|::
name|find
argument_list|(
name|names
argument_list|,
name|end
argument_list|,
name|key
operator|.
name|toLower
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|int
argument_list|(
name|result
operator|-
name|names
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
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|resourceType
argument_list|(
name|resource
argument_list|)
condition|)
block|{
case|case
name|EglDisplay
case|:
name|result
operator|=
name|mScreen
operator|->
name|display
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForWindow
name|void
modifier|*
name|QEglFSIntegration
operator|::
name|nativeResourceForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|resourceType
argument_list|(
name|resource
argument_list|)
condition|)
block|{
case|case
name|EglDisplay
case|:
if|if
condition|(
name|window
operator|&&
name|window
operator|->
name|handle
argument_list|()
condition|)
name|result
operator|=
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
operator|->
name|screen
argument_list|()
argument_list|)
operator|->
name|display
argument_list|()
expr_stmt|;
else|else
name|result
operator|=
name|mScreen
operator|->
name|display
argument_list|()
expr_stmt|;
break|break;
case|case
name|EglWindow
case|:
if|if
condition|(
name|window
operator|&&
name|window
operator|->
name|handle
argument_list|()
condition|)
name|result
operator|=
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
cast|static_cast
argument_list|<
name|QEglFSWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|eglWindow
argument_list|()
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|result
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
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|resourceType
argument_list|(
name|resource
argument_list|)
condition|)
block|{
case|case
name|EglContext
case|:
if|if
condition|(
name|context
operator|->
name|handle
argument_list|()
condition|)
name|result
operator|=
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
operator|->
name|eglContext
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForContext
name|QPlatformNativeInterface
operator|::
name|NativeResourceForContextFunction
name|QEglFSIntegration
operator|::
name|nativeResourceFunctionForContext
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
literal|"get_egl_context"
condition|)
return|return
name|NativeResourceForContextFunction
argument_list|(
name|eglContextForContext
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|eglContextForContext
specifier|static
name|void
modifier|*
name|eglContextForContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
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
return|return
name|handle
operator|->
name|eglContext
argument_list|()
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
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
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
begin_function
DECL|function|createInputHandlers
name|void
name|QEglFSIntegration
operator|::
name|createInputHandlers
parameter_list|()
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EVDEV
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_ANDROID_NO_SDK
argument_list|)
operator|)
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
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
