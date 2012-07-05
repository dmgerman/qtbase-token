begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qscreen.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
end_if
begin_include
include|#
directive|include
file|"QtPlatformSupport/private/qeglplatformcontext_p.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|XCB_USE_DRI2
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"qdri2context.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QXcbResourceMap
class|class
name|QXcbResourceMap
super|:
specifier|public
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QXcbNativeInterface
operator|::
name|ResourceType
argument_list|>
block|{
public|public:
DECL|function|QXcbResourceMap
name|QXcbResourceMap
parameter_list|()
member_init_list|:
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QXcbNativeInterface
operator|::
name|ResourceType
argument_list|>
argument_list|()
block|{
name|insert
argument_list|(
literal|"display"
argument_list|,
name|QXcbNativeInterface
operator|::
name|Display
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"egldisplay"
argument_list|,
name|QXcbNativeInterface
operator|::
name|EglDisplay
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"connection"
argument_list|,
name|QXcbNativeInterface
operator|::
name|Connection
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"screen"
argument_list|,
name|QXcbNativeInterface
operator|::
name|Screen
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"graphicsdevice"
argument_list|,
name|QXcbNativeInterface
operator|::
name|GraphicsDevice
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"eglcontext"
argument_list|,
name|QXcbNativeInterface
operator|::
name|EglContext
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QXcbResourceMap
argument_list|,
argument|qXcbResourceMap
argument_list|)
end_macro
begin_constructor
DECL|function|QXcbNativeInterface
name|QXcbNativeInterface
operator|::
name|QXcbNativeInterface
parameter_list|()
member_init_list|:
name|m_genericEventFilterType
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"xcb_generic_event_t"
argument_list|)
argument_list|)
block|{
name|qFill
argument_list|(
name|m_eventFilters
argument_list|,
name|m_eventFilters
operator|+
name|EventFilterCount
argument_list|,
name|EventFilter
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|nativeResourceForContext
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|nativeResourceForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resourceString
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|QByteArray
name|lowerCaseResource
init|=
name|resourceString
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|qXcbResourceMap
argument_list|()
operator|->
name|contains
argument_list|(
name|lowerCaseResource
argument_list|)
condition|)
return|return
literal|0
return|;
name|ResourceType
name|resource
init|=
name|qXcbResourceMap
argument_list|()
operator|->
name|value
argument_list|(
name|lowerCaseResource
argument_list|)
decl_stmt|;
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|resource
condition|)
block|{
case|case
name|EglContext
case|:
name|result
operator|=
name|eglContextForContext
argument_list|(
name|context
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
DECL|function|nativeResourceForWindow
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|nativeResourceForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resourceString
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QByteArray
name|lowerCaseResource
init|=
name|resourceString
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|qXcbResourceMap
argument_list|()
operator|->
name|contains
argument_list|(
name|lowerCaseResource
argument_list|)
condition|)
return|return
literal|0
return|;
name|ResourceType
name|resource
init|=
name|qXcbResourceMap
argument_list|()
operator|->
name|value
argument_list|(
name|lowerCaseResource
argument_list|)
decl_stmt|;
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|resource
condition|)
block|{
case|case
name|Display
case|:
name|result
operator|=
name|displayForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
break|break;
case|case
name|EglDisplay
case|:
name|result
operator|=
name|eglDisplayForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
break|break;
case|case
name|Connection
case|:
name|result
operator|=
name|connectionForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
break|break;
case|case
name|Screen
case|:
name|result
operator|=
name|qPlatformScreenForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
break|break;
case|case
name|GraphicsDevice
case|:
name|result
operator|=
name|graphicsDeviceForWindow
argument_list|(
name|window
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
DECL|function|nativeResourceFunctionForContext
name|QPlatformNativeInterface
operator|::
name|NativeResourceForContextFunction
name|QXcbNativeInterface
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
block|{
return|return
name|eglContextForContext
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|setEventFilter
name|QPlatformNativeInterface
operator|::
name|EventFilter
name|QXcbNativeInterface
operator|::
name|setEventFilter
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|eventType
parameter_list|,
name|QPlatformNativeInterface
operator|::
name|EventFilter
name|filter
parameter_list|)
block|{
name|int
name|type
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|eventType
operator|==
name|m_genericEventFilterType
condition|)
name|type
operator|=
name|GenericEventFilter
expr_stmt|;
if|if
condition|(
name|type
operator|==
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QXcbNativeInterface: %s: Attempt to set invalid event filter type '%s'."
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|eventType
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
specifier|const
name|EventFilter
name|oldFilter
init|=
name|m_eventFilters
index|[
name|type
index|]
decl_stmt|;
name|m_eventFilters
index|[
name|type
index|]
operator|=
name|filter
expr_stmt|;
return|return
name|oldFilter
return|;
block|}
end_function
begin_function
DECL|function|qPlatformScreenForWindow
name|QXcbScreen
modifier|*
name|QXcbNativeInterface
operator|::
name|qPlatformScreenForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QXcbScreen
modifier|*
name|screen
decl_stmt|;
if|if
condition|(
name|window
condition|)
block|{
name|screen
operator|=
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
expr_stmt|;
block|}
else|else
block|{
name|screen
operator|=
cast|static_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|screen
return|;
block|}
end_function
begin_function
DECL|function|displayForWindow
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|displayForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_XLIB
argument_list|)
name|QXcbScreen
modifier|*
name|screen
init|=
name|qPlatformScreenForWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
return|return
name|screen
operator|->
name|connection
argument_list|()
operator|->
name|xlib_display
argument_list|()
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|eglDisplayForWindow
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|eglDisplayForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_DRI2
argument_list|)
operator|||
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
name|QXcbScreen
modifier|*
name|screen
init|=
name|qPlatformScreenForWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
return|return
name|screen
operator|->
name|connection
argument_list|()
operator|->
name|egl_display
argument_list|()
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|window
argument_list|)
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|connectionForWindow
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|connectionForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QXcbScreen
modifier|*
name|screen
init|=
name|qPlatformScreenForWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
return|return
name|screen
operator|->
name|xcb_connection
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|screenForWindow
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|screenForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QXcbScreen
modifier|*
name|screen
init|=
name|qPlatformScreenForWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
return|return
name|screen
operator|->
name|screen
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|graphicsDeviceForWindow
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|graphicsDeviceForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_DRI2
argument_list|)
name|QXcbScreen
modifier|*
name|screen
init|=
name|qPlatformScreenForWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|QByteArray
name|deviceName
init|=
name|screen
operator|->
name|connection
argument_list|()
operator|->
name|dri2DeviceName
argument_list|()
decl_stmt|;
return|return
name|deviceName
operator|.
name|data
argument_list|()
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|eglContextForContext
name|void
modifier|*
name|QXcbNativeInterface
operator|::
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
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
name|QEGLPlatformContext
modifier|*
name|eglPlatformContext
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
return|return
name|eglPlatformContext
operator|->
name|eglContext
argument_list|()
return|;
endif|#
directive|endif
if|#
directive|if
literal|0
block|Q_ASSERT(window);     QPlatformOpenGLContext *platformContext = window->glContext()->handle();     if (!platformContext) {         qDebug()<< "QWindow"<< window<< "does not have a glContext"<< "cannot return EGLContext";         return 0;     }
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
block|QEGLPlatformContext *eglPlatformContext = static_cast<QEGLPlatformContext *>(platformContext);     return eglPlatformContext->eglContext();
elif|#
directive|elif
name|defined
argument_list|(
name|XCB_USE_DRI2
argument_list|)
block|QDri2Context *dri2Context = static_cast<QDri2Context *>(platformContext);     return dri2Context->eglContext();
else|#
directive|else
block|return 0;
endif|#
directive|endif
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|context
argument_list|)
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
