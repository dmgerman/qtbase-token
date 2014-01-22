begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontextfactory_p.h>
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
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|"qeglplatformintegration_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglplatformcontext_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglplatformwindow_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglplatformbackingstore_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglplatformscreen_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QEGLPlatformIntegration     \brief Base class for EGL-based QPlatformIntegration implementations.     \since 5.2     \internal     \ingroup qpa      This class provides most of the necessary platform integration for     an EGL-based Unix system. Platform plugins must subclass this and     reimplement the virtuals for creating platform screens and windows     since they will most likely wish to use a subclass for these.      The backing store, native interface accessors, font database,     basic capability flags, etc. are provided out of the box, no     further customization is needed. Subclasses are still responsible     however for context and offscreen surface creation.      \note It is critical that this class' implementation of     initialize() is called. Therefore subclasses should either avoid     to reimplement this function or call the base class     implementation.  */
end_comment
begin_constructor
DECL|function|QEGLPlatformIntegration
name|QEGLPlatformIntegration
operator|::
name|QEGLPlatformIntegration
parameter_list|()
member_init_list|:
name|m_screen
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_display
argument_list|(
name|EGL_NO_DISPLAY
argument_list|)
member_init_list|,
name|m_inputContext
argument_list|(
literal|0
argument_list|)
member_init_list|,
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
block|{ }
end_constructor
begin_destructor
DECL|function|~QEGLPlatformIntegration
name|QEGLPlatformIntegration
operator|::
name|~
name|QEGLPlatformIntegration
parameter_list|()
block|{
operator|delete
name|m_screen
expr_stmt|;
if|if
condition|(
name|m_display
operator|!=
name|EGL_NO_DISPLAY
condition|)
name|eglTerminate
argument_list|(
name|m_display
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initialize
name|void
name|QEGLPlatformIntegration
operator|::
name|initialize
parameter_list|()
block|{
if|if
condition|(
operator|!
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Could not bind GL_ES API"
argument_list|)
expr_stmt|;
name|m_display
operator|=
name|eglGetDisplay
argument_list|(
name|nativeDisplay
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_display
operator|==
name|EGL_NO_DISPLAY
condition|)
name|qFatal
argument_list|(
literal|"Could not open egl display"
argument_list|)
expr_stmt|;
name|EGLint
name|major
decl_stmt|,
name|minor
decl_stmt|;
if|if
condition|(
operator|!
name|eglInitialize
argument_list|(
name|m_display
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Could not initialize egl display"
argument_list|)
expr_stmt|;
name|m_screen
operator|=
name|createScreen
argument_list|()
expr_stmt|;
name|screenAdded
argument_list|(
name|m_screen
argument_list|)
expr_stmt|;
name|m_inputContext
operator|=
name|QPlatformInputContextFactory
operator|::
name|create
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QEGLPlatformIntegration
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
DECL|function|services
name|QPlatformServices
modifier|*
name|QEGLPlatformIntegration
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
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QEGLPlatformIntegration
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
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QEGLPlatformIntegration
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
name|QEGLPlatformBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QEGLPlatformIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|QWindowSystemInterface
operator|::
name|flushWindowSystemEvents
argument_list|()
expr_stmt|;
name|QEGLPlatformWindow
modifier|*
name|w
init|=
name|createWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|w
operator|->
name|create
argument_list|()
expr_stmt|;
if|if
condition|(
name|window
operator|->
name|type
argument_list|()
operator|!=
name|Qt
operator|::
name|ToolTip
condition|)
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
DECL|function|hasCapability
name|bool
name|QEGLPlatformIntegration
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
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QEGLPlatformIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
cast|const_cast
argument_list|<
name|QEGLPlatformIntegration
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
name|QEGLPlatformIntegration
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
name|m_screen
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
name|QEGLPlatformIntegration
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
name|QEGLPlatformScreen
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
name|m_screen
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
name|QEGLPlatformWindow
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
name|QEGLPlatformIntegration
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
DECL|function|nativeResourceFunctionForContext
name|QPlatformNativeInterface
operator|::
name|NativeResourceForContextFunction
name|QEGLPlatformIntegration
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
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit