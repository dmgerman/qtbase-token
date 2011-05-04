begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtGui/qwindowcontext_qpa.h>
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
file|"../eglconvenience/qeglplatformcontext.h"
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
case|case
name|EglContext
case|:
name|result
operator|=
name|eglContextForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
break|break;
default|default:
name|result
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|result
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
name|QPlatformScreen
operator|::
name|platformScreenForWindow
argument_list|(
name|window
argument_list|)
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
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|screens
argument_list|()
index|[
literal|0
index|]
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
DECL|function|eglContextForWindow
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|eglContextForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|QPlatformGLContext
modifier|*
name|platformContext
init|=
name|window
operator|->
name|glContext
argument_list|()
operator|->
name|handle
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|platformContext
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"QWindow"
operator|<<
name|window
operator|<<
literal|"does not have a glContext"
operator|<<
literal|"cannot return EGLContext"
expr_stmt|;
return|return
literal|0
return|;
block|}
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
name|platformContext
argument_list|)
decl_stmt|;
return|return
name|eglPlatformContext
operator|->
name|eglContext
argument_list|()
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|XCB_USE_DRI2
argument_list|)
name|QDri2Context
modifier|*
name|dri2Context
init|=
cast|static_cast
argument_list|<
name|QDri2Context
operator|*
argument_list|>
argument_list|(
name|platformContext
argument_list|)
decl_stmt|;
return|return
name|dri2Context
operator|->
name|eglContext
argument_list|()
return|;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
end_unit
