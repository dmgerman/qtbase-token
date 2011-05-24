begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"pvreglscreen.h"
end_include
begin_include
include|#
directive|include
file|"pvreglwindowsurface.h"
end_include
begin_include
include|#
directive|include
file|"pvrqwsdrawable_p.h"
end_include
begin_include
include|#
directive|include
file|<QRegExp>
end_include
begin_include
include|#
directive|include
file|<qwindowsystem_qws.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_TRANSFORMED
end_ifndef
begin_include
include|#
directive|include
file|<qscreentransformed_qws.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include
begin_include
include|#
directive|include
file|<sys/kd.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_comment
comment|//![0]
end_comment
begin_constructor
DECL|function|PvrEglScreen
name|PvrEglScreen
operator|::
name|PvrEglScreen
parameter_list|(
name|int
name|displayId
parameter_list|)
member_init_list|:
name|QGLScreen
argument_list|(
name|displayId
argument_list|)
block|{
name|setOptions
argument_list|(
name|NativeWindows
argument_list|)
expr_stmt|;
name|setSupportsBlitInClients
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setSurfaceFunctions
argument_list|(
operator|new
name|PvrEglScreenSurfaceFunctions
argument_list|(
name|this
argument_list|,
name|displayId
argument_list|)
argument_list|)
expr_stmt|;
comment|//![0]
name|fd
operator|=
operator|-
literal|1
expr_stmt|;
name|ttyfd
operator|=
operator|-
literal|1
expr_stmt|;
name|doGraphicsMode
operator|=
literal|true
expr_stmt|;
name|oldKdMode
operator|=
name|KD_TEXT
expr_stmt|;
name|parent
operator|=
literal|0
expr_stmt|;
comment|// Make sure that the EGL layer is initialized and the drivers loaded.
name|EGLDisplay
name|dpy
init|=
name|eglGetDisplay
argument_list|(
operator|(
name|EGLNativeDisplayType
operator|)
name|EGL_DEFAULT_DISPLAY
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|eglInitialize
argument_list|(
name|dpy
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"Could not initialize EGL display - are the drivers loaded?"
argument_list|)
expr_stmt|;
comment|// Make sure that screen 0 is initialized.
name|pvrQwsScreenWindow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~PvrEglScreen
name|PvrEglScreen
operator|::
name|~
name|PvrEglScreen
parameter_list|()
block|{
if|if
condition|(
name|fd
operator|>=
literal|0
condition|)
operator|::
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initDevice
name|bool
name|PvrEglScreen
operator|::
name|initDevice
parameter_list|()
block|{
name|openTty
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|connect
name|bool
name|PvrEglScreen
operator|::
name|connect
parameter_list|(
specifier|const
name|QString
modifier|&
name|displaySpec
parameter_list|)
block|{
if|if
condition|(
operator|!
name|pvrQwsDisplayOpen
argument_list|()
condition|)
return|return
literal|false
return|;
comment|// Initialize the QScreen properties.
name|data
operator|=
operator|(
name|uchar
operator|*
operator|)
operator|(
name|pvrQwsDisplay
operator|.
name|screens
index|[
literal|0
index|]
operator|.
name|mapped
operator|)
expr_stmt|;
name|w
operator|=
name|pvrQwsDisplay
operator|.
name|screens
index|[
literal|0
index|]
operator|.
name|screenRect
operator|.
name|width
expr_stmt|;
name|h
operator|=
name|pvrQwsDisplay
operator|.
name|screens
index|[
literal|0
index|]
operator|.
name|screenRect
operator|.
name|height
expr_stmt|;
name|lstep
operator|=
name|pvrQwsDisplay
operator|.
name|screens
index|[
literal|0
index|]
operator|.
name|screenStride
expr_stmt|;
name|dw
operator|=
name|w
expr_stmt|;
name|dh
operator|=
name|h
expr_stmt|;
name|size
operator|=
name|h
operator|*
name|lstep
expr_stmt|;
name|mapsize
operator|=
name|size
expr_stmt|;
switch|switch
condition|(
name|pvrQwsDisplay
operator|.
name|screens
index|[
literal|0
index|]
operator|.
name|pixelFormat
condition|)
block|{
case|case
name|PVR2D_RGB565
case|:
name|d
operator|=
literal|16
expr_stmt|;
name|setPixelFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB16
argument_list|)
expr_stmt|;
break|break;
case|case
name|PVR2D_ARGB4444
case|:
name|d
operator|=
literal|16
expr_stmt|;
name|setPixelFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB4444_Premultiplied
argument_list|)
expr_stmt|;
break|break;
case|case
name|PVR2D_ARGB8888
case|:
name|d
operator|=
literal|32
expr_stmt|;
name|setPixelFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
expr_stmt|;
break|break;
default|default:
name|pvrQwsDisplayClose
argument_list|()
expr_stmt|;
name|qWarning
argument_list|(
literal|"PvrEglScreen::connect: unsupported pixel format %d"
argument_list|,
call|(
name|int
call|)
argument_list|(
name|pvrQwsDisplay
operator|.
name|screens
index|[
literal|0
index|]
operator|.
name|pixelFormat
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Handle display physical size spec.
name|QStringList
name|displayArgs
init|=
name|displaySpec
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
decl_stmt|;
name|QRegExp
name|mmWidthRx
argument_list|(
name|QLatin1String
argument_list|(
literal|"mmWidth=?(\\d+)"
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|dimIdxW
init|=
name|displayArgs
operator|.
name|indexOf
argument_list|(
name|mmWidthRx
argument_list|)
decl_stmt|;
name|QRegExp
name|mmHeightRx
argument_list|(
name|QLatin1String
argument_list|(
literal|"mmHeight=?(\\d+)"
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|dimIdxH
init|=
name|displayArgs
operator|.
name|indexOf
argument_list|(
name|mmHeightRx
argument_list|)
decl_stmt|;
if|if
condition|(
name|dimIdxW
operator|>=
literal|0
condition|)
block|{
name|mmWidthRx
operator|.
name|exactMatch
argument_list|(
name|displayArgs
operator|.
name|at
argument_list|(
name|dimIdxW
argument_list|)
argument_list|)
expr_stmt|;
name|physWidth
operator|=
name|mmWidthRx
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
if|if
condition|(
name|dimIdxH
operator|<
literal|0
condition|)
name|physHeight
operator|=
name|dh
operator|*
name|physWidth
operator|/
name|dw
expr_stmt|;
block|}
if|if
condition|(
name|dimIdxH
operator|>=
literal|0
condition|)
block|{
name|mmHeightRx
operator|.
name|exactMatch
argument_list|(
name|displayArgs
operator|.
name|at
argument_list|(
name|dimIdxH
argument_list|)
argument_list|)
expr_stmt|;
name|physHeight
operator|=
name|mmHeightRx
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
if|if
condition|(
name|dimIdxW
operator|<
literal|0
condition|)
name|physWidth
operator|=
name|dw
operator|*
name|physHeight
operator|/
name|dh
expr_stmt|;
block|}
if|if
condition|(
name|dimIdxW
operator|<
literal|0
operator|&&
name|dimIdxH
operator|<
literal|0
condition|)
block|{
specifier|const
name|int
name|dpi
init|=
literal|72
decl_stmt|;
name|physWidth
operator|=
name|qRound
argument_list|(
name|dw
operator|*
literal|25.4
operator|/
name|dpi
argument_list|)
expr_stmt|;
name|physHeight
operator|=
name|qRound
argument_list|(
name|dh
operator|*
literal|25.4
operator|/
name|dpi
argument_list|)
expr_stmt|;
block|}
comment|// Find the name of the tty device to use.
name|QRegExp
name|ttyRegExp
argument_list|(
name|QLatin1String
argument_list|(
literal|"tty=(.*)"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|displayArgs
operator|.
name|indexOf
argument_list|(
name|ttyRegExp
argument_list|)
operator|!=
operator|-
literal|1
condition|)
name|ttyDevice
operator|=
name|ttyRegExp
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|displayArgs
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"nographicsmodeswitch"
argument_list|)
argument_list|)
condition|)
name|doGraphicsMode
operator|=
literal|false
expr_stmt|;
comment|// The screen is ready.
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|disconnect
name|void
name|PvrEglScreen
operator|::
name|disconnect
parameter_list|()
block|{
name|pvrQwsDisplayClose
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|shutdownDevice
name|void
name|PvrEglScreen
operator|::
name|shutdownDevice
parameter_list|()
block|{
name|closeTty
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|blit
name|void
name|PvrEglScreen
operator|::
name|blit
parameter_list|(
specifier|const
name|QImage
modifier|&
name|img
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|topLeft
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|QGLScreen
operator|::
name|blit
argument_list|(
name|img
argument_list|,
name|topLeft
argument_list|,
name|region
argument_list|)
expr_stmt|;
name|sync
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|solidFill
name|void
name|PvrEglScreen
operator|::
name|solidFill
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|QGLScreen
operator|::
name|solidFill
argument_list|(
name|color
argument_list|,
name|region
argument_list|)
expr_stmt|;
name|sync
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|chooseContext
name|bool
name|PvrEglScreen
operator|::
name|chooseContext
parameter_list|(
name|QGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|QGLContext
modifier|*
name|shareContext
parameter_list|)
block|{
comment|// We use PvrEglScreenSurfaceFunctions instead.
name|Q_UNUSED
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|shareContext
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|hasOpenGL
name|bool
name|PvrEglScreen
operator|::
name|hasOpenGL
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//![1]
end_comment
begin_function
DECL|function|createSurface
name|QWSWindowSurface
modifier|*
name|PvrEglScreen
operator|::
name|createSurface
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|qobject_cast
argument_list|<
name|QGLWidget
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
condition|)
return|return
operator|new
name|PvrEglWindowSurface
argument_list|(
name|widget
argument_list|,
operator|(
name|PvrEglScreen
operator|*
operator|)
name|this
argument_list|,
name|displayId
argument_list|)
return|;
return|return
name|QScreen
operator|::
name|createSurface
argument_list|(
name|widget
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createSurface
name|QWSWindowSurface
modifier|*
name|PvrEglScreen
operator|::
name|createSurface
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|key
operator|==
name|QLatin1String
argument_list|(
literal|"PvrEgl"
argument_list|)
condition|)
return|return
operator|new
name|PvrEglWindowSurface
argument_list|()
return|;
return|return
name|QScreen
operator|::
name|createSurface
argument_list|(
name|key
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//![1]
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_TRANSFORMED
end_ifndef
begin_function
DECL|function|parentScreen
specifier|static
specifier|const
name|QScreen
modifier|*
name|parentScreen
parameter_list|(
specifier|const
name|QScreen
modifier|*
name|current
parameter_list|,
specifier|const
name|QScreen
modifier|*
name|lookingFor
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current
condition|)
return|return
literal|0
return|;
switch|switch
condition|(
name|current
operator|->
name|classId
argument_list|()
condition|)
block|{
case|case
name|QScreen
operator|::
name|ProxyClass
case|:
case|case
name|QScreen
operator|::
name|TransformedClass
case|:
block|{
specifier|const
name|QScreen
modifier|*
name|child
init|=
cast|static_cast
argument_list|<
specifier|const
name|QProxyScreen
operator|*
argument_list|>
argument_list|(
name|current
argument_list|)
operator|->
name|screen
argument_list|()
decl_stmt|;
if|if
condition|(
name|child
operator|==
name|lookingFor
condition|)
return|return
name|current
return|;
else|else
return|return
name|parentScreen
argument_list|(
name|child
argument_list|,
name|lookingFor
argument_list|)
return|;
block|}
comment|// Not reached.
case|case
name|QScreen
operator|::
name|MultiClass
case|:
block|{
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
init|=
name|current
operator|->
name|subScreens
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QScreen
modifier|*
name|screen
decl|,
name|screens
control|)
block|{
if|if
condition|(
name|screen
operator|==
name|lookingFor
condition|)
return|return
name|current
return|;
specifier|const
name|QScreen
modifier|*
name|parent
init|=
name|parentScreen
argument_list|(
name|screen
argument_list|,
name|lookingFor
argument_list|)
decl_stmt|;
if|if
condition|(
name|parent
condition|)
return|return
name|parent
return|;
block|}
block|}
break|break;
default|default:
break|break;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|transformation
name|int
name|PvrEglScreen
operator|::
name|transformation
parameter_list|()
specifier|const
block|{
comment|// We need to search for our parent screen, which is assumed to be
comment|// "Transformed".  If it isn't, then there is no transformation.
comment|// There is no direct method to get the parent screen so we need
comment|// to search every screen until we find ourselves.
if|if
condition|(
operator|!
name|parent
operator|&&
name|qt_screen
operator|!=
name|this
condition|)
name|parent
operator|=
name|parentScreen
argument_list|(
name|qt_screen
argument_list|,
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|parent
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|parent
operator|->
name|classId
argument_list|()
operator|!=
name|QScreen
operator|::
name|TransformedClass
condition|)
return|return
literal|0
return|;
return|return
literal|90
operator|*
cast|static_cast
argument_list|<
specifier|const
name|QTransformedScreen
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|)
operator|->
name|transformOrientation
argument_list|()
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
DECL|function|transformation
name|int
name|PvrEglScreen
operator|::
name|transformation
parameter_list|()
specifier|const
block|{
return|return
literal|0
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
name|PvrEglScreen
operator|::
name|sync
parameter_list|()
block|{
comment|// Put code here to synchronize 2D and 3D operations if necessary.
block|}
end_function
begin_function
DECL|function|openTty
name|void
name|PvrEglScreen
operator|::
name|openTty
parameter_list|()
block|{
specifier|const
name|char
modifier|*
specifier|const
name|devs
index|[]
init|=
block|{
literal|"/dev/tty0"
block|,
literal|"/dev/tty"
block|,
literal|"/dev/console"
block|,
literal|0
block|}
decl_stmt|;
if|if
condition|(
name|ttyDevice
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
for|for
control|(
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|dev
init|=
name|devs
init|;
operator|*
name|dev
condition|;
operator|++
name|dev
control|)
block|{
name|ttyfd
operator|=
operator|::
name|open
argument_list|(
operator|*
name|dev
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
if|if
condition|(
name|ttyfd
operator|!=
operator|-
literal|1
condition|)
break|break;
block|}
block|}
else|else
block|{
name|ttyfd
operator|=
operator|::
name|open
argument_list|(
name|ttyDevice
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ttyfd
operator|==
operator|-
literal|1
condition|)
return|return;
operator|::
name|fcntl
argument_list|(
name|ttyfd
argument_list|,
name|F_SETFD
argument_list|,
name|FD_CLOEXEC
argument_list|)
expr_stmt|;
if|if
condition|(
name|doGraphicsMode
condition|)
block|{
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|KDGETMODE
argument_list|,
operator|&
name|oldKdMode
argument_list|)
expr_stmt|;
if|if
condition|(
name|oldKdMode
operator|!=
name|KD_GRAPHICS
condition|)
block|{
name|int
name|ret
init|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|KDSETMODE
argument_list|,
name|KD_GRAPHICS
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
operator|-
literal|1
condition|)
name|doGraphicsMode
operator|=
literal|false
expr_stmt|;
block|}
block|}
comment|// No blankin' screen, no blinkin' cursor!, no cursor!
specifier|const
name|char
name|termctl
index|[]
init|=
literal|"\033[9;0]\033[?33l\033[?25l\033[?1c"
decl_stmt|;
operator|::
name|write
argument_list|(
name|ttyfd
argument_list|,
name|termctl
argument_list|,
sizeof|sizeof
argument_list|(
name|termctl
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|closeTty
name|void
name|PvrEglScreen
operator|::
name|closeTty
parameter_list|()
block|{
if|if
condition|(
name|ttyfd
operator|==
operator|-
literal|1
condition|)
return|return;
if|if
condition|(
name|doGraphicsMode
condition|)
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|KDSETMODE
argument_list|,
name|oldKdMode
argument_list|)
expr_stmt|;
comment|// Blankin' screen, blinkin' cursor!
specifier|const
name|char
name|termctl
index|[]
init|=
literal|"\033[9;15]\033[?33h\033[?25h\033[?0c"
decl_stmt|;
operator|::
name|write
argument_list|(
name|ttyfd
argument_list|,
name|termctl
argument_list|,
sizeof|sizeof
argument_list|(
name|termctl
argument_list|)
argument_list|)
expr_stmt|;
operator|::
name|close
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
name|ttyfd
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_function
begin_comment
comment|//![2]
end_comment
begin_function
DECL|function|createNativeWindow
name|bool
name|PvrEglScreenSurfaceFunctions
operator|::
name|createNativeWindow
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|EGLNativeWindowType
modifier|*
name|native
parameter_list|)
block|{
comment|//![2]
name|QWSWindowSurface
modifier|*
name|surface
init|=
cast|static_cast
argument_list|<
name|QWSWindowSurface
operator|*
argument_list|>
argument_list|(
name|widget
operator|->
name|windowSurface
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|surface
condition|)
block|{
comment|// The widget does not have a surface yet, so give it one.
name|surface
operator|=
operator|new
name|PvrEglWindowSurface
argument_list|(
name|widget
argument_list|,
name|screen
argument_list|,
name|displayId
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setWindowSurface
argument_list|(
name|surface
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|surface
operator|->
name|key
argument_list|()
operator|!=
name|QLatin1String
argument_list|(
literal|"PvrEgl"
argument_list|)
condition|)
block|{
comment|// The application has attached a QGLContext to an ordinary QWidget.
comment|// Replace the widget's window surface with a new one that can do GL.
name|QRect
name|geometry
init|=
name|widget
operator|->
name|frameGeometry
argument_list|()
decl_stmt|;
name|geometry
operator|.
name|moveTo
argument_list|(
name|widget
operator|->
name|mapToGlobal
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|surface
operator|=
operator|new
name|PvrEglWindowSurface
argument_list|(
name|widget
argument_list|,
name|screen
argument_list|,
name|displayId
argument_list|)
expr_stmt|;
name|surface
operator|->
name|setGeometry
argument_list|(
name|geometry
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setWindowSurface
argument_list|(
name|surface
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_NoSystemBackground
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
name|PvrEglWindowSurface
modifier|*
name|nsurface
init|=
cast|static_cast
argument_list|<
name|PvrEglWindowSurface
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
operator|*
name|native
operator|=
call|(
name|EGLNativeWindowType
call|)
argument_list|(
name|nsurface
operator|->
name|nativeDrawable
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
end_unit
