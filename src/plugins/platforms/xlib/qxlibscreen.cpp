begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|"qxlibscreen.h"
end_include
begin_include
include|#
directive|include
file|<X11/extensions/Xfixes.h>
end_include
begin_include
include|#
directive|include
file|"qxlibcursor.h"
end_include
begin_include
include|#
directive|include
file|"qxlibwindow.h"
end_include
begin_include
include|#
directive|include
file|"qxlibkeyboard.h"
end_include
begin_include
include|#
directive|include
file|"qxlibstatic.h"
end_include
begin_include
include|#
directive|include
file|"qxlibclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qxlibdisplay.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<QtCore/QElapsedTimer>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
DECL|variable|original_x_errhandler
specifier|static
name|int
function_decl|(
modifier|*
name|original_x_errhandler
function_decl|)
parameter_list|(
name|Display
modifier|*
name|dpy
parameter_list|,
name|XErrorEvent
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|seen_badwindow
specifier|static
name|bool
name|seen_badwindow
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qt_x_errhandler
specifier|static
name|int
name|qt_x_errhandler
parameter_list|(
name|Display
modifier|*
name|dpy
parameter_list|,
name|XErrorEvent
modifier|*
name|err
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"qt_x_errhandler"
operator|<<
name|err
operator|->
name|error_code
expr_stmt|;
switch|switch
condition|(
name|err
operator|->
name|error_code
condition|)
block|{
case|case
name|BadAtom
case|:
if|#
directive|if
literal|0
block|if (err->request_code == 20
comment|/* X_GetProperty */
block|&& (err->resourceid == XA_RESOURCE_MANAGER                 || err->resourceid == XA_RGB_DEFAULT_MAP                 || err->resourceid == ATOM(_NET_SUPPORTED)                 || err->resourceid == ATOM(_NET_SUPPORTING_WM_CHECK)                 || err->resourceid == ATOM(KDE_FULL_SESSION)                 || err->resourceid == ATOM(KWIN_RUNNING)                 || err->resourceid == ATOM(XdndProxy)                 || err->resourceid == ATOM(XdndAware))               ) {
comment|// Perhaps we're running under SECURITY reduction? :/
block|return 0;         }
endif|#
directive|endif
name|qDebug
argument_list|()
operator|<<
literal|"BadAtom"
expr_stmt|;
break|break;
case|case
name|BadWindow
case|:
if|if
condition|(
name|err
operator|->
name|request_code
operator|==
literal|2
comment|/* X_ChangeWindowAttributes */
operator|||
name|err
operator|->
name|request_code
operator|==
literal|38
comment|/* X_QueryPointer */
condition|)
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
name|ScreenCount
argument_list|(
name|dpy
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|err
operator|->
name|resourceid
operator|==
name|RootWindow
argument_list|(
name|dpy
argument_list|,
name|i
argument_list|)
condition|)
block|{
comment|// Perhaps we're running under SECURITY reduction? :/
return|return
literal|0
return|;
block|}
block|}
block|}
name|seen_badwindow
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|err
operator|->
name|request_code
operator|==
literal|25
comment|/* X_SendEvent */
condition|)
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
name|ScreenCount
argument_list|(
name|dpy
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|err
operator|->
name|resourceid
operator|==
name|RootWindow
argument_list|(
name|dpy
argument_list|,
name|i
argument_list|)
condition|)
block|{
comment|// Perhaps we're running under SECURITY reduction? :/
return|return
literal|0
return|;
block|}
block|}
if|#
directive|if
literal|0
block|if (X11->xdndHandleBadwindow()) {                 qDebug("xdndHandleBadwindow returned true");                 return 0;             }
endif|#
directive|endif
block|}
if|#
directive|if
literal|0
block|if (X11->ignore_badwindow)             return 0;
endif|#
directive|endif
break|break;
case|case
name|BadMatch
case|:
if|if
condition|(
name|err
operator|->
name|request_code
operator|==
literal|42
comment|/* X_SetInputFocus */
condition|)
return|return
literal|0
return|;
break|break;
default|default:
if|#
directive|if
literal|0
comment|//!defined(QT_NO_XINPUT)
block|if (err->request_code == X11->xinput_major&& err->error_code == (X11->xinput_errorbase + XI_BadDevice)&& err->minor_code == 3
comment|/* X_OpenDevice */
block|) {             return 0;         }
endif|#
directive|endif
break|break;
block|}
name|char
name|errstr
index|[
literal|256
index|]
decl_stmt|;
name|XGetErrorText
argument_list|(
name|dpy
argument_list|,
name|err
operator|->
name|error_code
argument_list|,
name|errstr
argument_list|,
literal|256
argument_list|)
expr_stmt|;
name|char
name|buffer
index|[
literal|256
index|]
decl_stmt|;
name|char
name|request_str
index|[
literal|256
index|]
decl_stmt|;
name|qsnprintf
argument_list|(
name|buffer
argument_list|,
literal|256
argument_list|,
literal|"%d"
argument_list|,
name|err
operator|->
name|request_code
argument_list|)
expr_stmt|;
name|XGetErrorDatabaseText
argument_list|(
name|dpy
argument_list|,
literal|"XRequest"
argument_list|,
name|buffer
argument_list|,
literal|""
argument_list|,
name|request_str
argument_list|,
literal|256
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|->
name|request_code
operator|<
literal|128
condition|)
block|{
comment|// X error for a normal protocol request
name|qWarning
argument_list|(
literal|"X Error: %s %d\n"
literal|"  Major opcode: %d (%s)\n"
literal|"  Resource id:  0x%lx"
argument_list|,
name|errstr
argument_list|,
name|err
operator|->
name|error_code
argument_list|,
name|err
operator|->
name|request_code
argument_list|,
name|request_str
argument_list|,
name|err
operator|->
name|resourceid
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// X error for an extension request
specifier|const
name|char
modifier|*
name|extensionName
init|=
literal|0
decl_stmt|;
if|#
directive|if
literal|0
block|if (err->request_code == X11->xrender_major)             extensionName = "RENDER";         else if (err->request_code == X11->xrandr_major)             extensionName = "RANDR";         else if (err->request_code == X11->xinput_major)             extensionName = "XInputExtension";         else if (err->request_code == X11->mitshm_major)             extensionName = "MIT-SHM";
endif|#
directive|endif
name|char
name|minor_str
index|[
literal|256
index|]
decl_stmt|;
if|if
condition|(
name|extensionName
condition|)
block|{
name|qsnprintf
argument_list|(
name|buffer
argument_list|,
literal|256
argument_list|,
literal|"%s.%d"
argument_list|,
name|extensionName
argument_list|,
name|err
operator|->
name|minor_code
argument_list|)
expr_stmt|;
name|XGetErrorDatabaseText
argument_list|(
name|dpy
argument_list|,
literal|"XRequest"
argument_list|,
name|buffer
argument_list|,
literal|""
argument_list|,
name|minor_str
argument_list|,
literal|256
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|extensionName
operator|=
literal|"Uknown extension"
expr_stmt|;
name|qsnprintf
argument_list|(
name|minor_str
argument_list|,
literal|256
argument_list|,
literal|"Unknown request"
argument_list|)
expr_stmt|;
block|}
name|qWarning
argument_list|(
literal|"X Error: %s %d\n"
literal|"  Extension:    %d (%s)\n"
literal|"  Minor opcode: %d (%s)\n"
literal|"  Resource id:  0x%lx"
argument_list|,
name|errstr
argument_list|,
name|err
operator|->
name|error_code
argument_list|,
name|err
operator|->
name|request_code
argument_list|,
name|extensionName
argument_list|,
name|err
operator|->
name|minor_code
argument_list|,
name|minor_str
argument_list|,
name|err
operator|->
name|resourceid
argument_list|)
expr_stmt|;
block|}
comment|// ### we really should distinguish between severe, non-severe and
comment|// ### application specific errors
return|return
literal|0
return|;
block|}
end_function
begin_constructor
DECL|function|QXlibScreen
name|QXlibScreen
operator|::
name|QXlibScreen
parameter_list|()
member_init_list|:
name|mFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
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
name|QT_OPENGL_ES_2
argument_list|)
member_init_list|,
name|mEGLDisplay
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{
name|char
modifier|*
name|display_name
init|=
name|getenv
argument_list|(
literal|"DISPLAY"
argument_list|)
decl_stmt|;
name|Display
modifier|*
name|display
init|=
name|XOpenDisplay
argument_list|(
name|display_name
argument_list|)
decl_stmt|;
name|mDisplay
operator|=
operator|new
name|QXlibDisplay
argument_list|(
name|display
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|DONT_USE_MIT_SHM
name|int
name|MIT_SHM_extension_supported
init|=
name|XShmQueryExtension
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|MIT_SHM_extension_supported
operator|==
name|True
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|original_x_errhandler
operator|=
name|XSetErrorHandler
argument_list|(
name|qt_x_errhandler
argument_list|)
expr_stmt|;
if|if
condition|(
name|qgetenv
argument_list|(
literal|"DO_X_SYNCHRONIZE"
argument_list|)
operator|.
name|toInt
argument_list|()
condition|)
name|XSynchronize
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|mScreen
operator|=
name|DefaultScreen
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|)
expr_stmt|;
name|XSelectInput
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|rootWindow
argument_list|()
argument_list|,
name|KeymapStateMask
operator||
name|EnterWindowMask
operator||
name|LeaveWindowMask
operator||
name|PropertyChangeMask
argument_list|)
expr_stmt|;
name|int
name|width
init|=
name|DisplayWidth
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|mScreen
argument_list|)
decl_stmt|;
name|int
name|height
init|=
name|DisplayHeight
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|mScreen
argument_list|)
decl_stmt|;
name|mGeometry
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
name|int
name|physicalWidth
init|=
name|DisplayWidthMM
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|mScreen
argument_list|)
decl_stmt|;
name|int
name|physicalHeight
init|=
name|DisplayHeightMM
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|mScreen
argument_list|)
decl_stmt|;
name|mPhysicalSize
operator|=
name|QSizeF
argument_list|(
name|physicalWidth
argument_list|,
name|physicalHeight
argument_list|)
expr_stmt|;
name|int
name|xSocketNumber
init|=
name|XConnectionNumber
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|)
decl_stmt|;
name|mDepth
operator|=
name|DefaultDepth
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|mScreen
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MYX11_DEBUG
name|qDebug
argument_list|()
operator|<<
literal|"X socket:"
operator|<<
name|xSocketNumber
expr_stmt|;
endif|#
directive|endif
name|QSocketNotifier
modifier|*
name|sock
init|=
operator|new
name|QSocketNotifier
argument_list|(
name|xSocketNumber
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|sock
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|eventDispatcher
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|mCursor
operator|=
operator|new
name|QXlibCursor
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|mKeyboard
operator|=
operator|new
name|QXlibKeyboard
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QXlibScreen
name|QXlibScreen
operator|::
name|~
name|QXlibScreen
parameter_list|()
block|{
operator|delete
name|mCursor
expr_stmt|;
operator|delete
name|mDisplay
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|rootWindow
name|Window
name|QXlibScreen
operator|::
name|rootWindow
parameter_list|()
block|{
return|return
name|RootWindow
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|mScreen
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|blackPixel
name|unsigned
name|long
name|QXlibScreen
operator|::
name|blackPixel
parameter_list|()
block|{
return|return
name|BlackPixel
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|mScreen
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|whitePixel
name|unsigned
name|long
name|QXlibScreen
operator|::
name|whitePixel
parameter_list|()
block|{
return|return
name|WhitePixel
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|mScreen
argument_list|)
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|KeyPress
end_ifdef
begin_undef
DECL|macro|KeyPress
undef|#
directive|undef
name|KeyPress
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|KeyRelease
end_ifdef
begin_undef
DECL|macro|KeyRelease
undef|#
directive|undef
name|KeyRelease
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|handleEvent
name|bool
name|QXlibScreen
operator|::
name|handleEvent
parameter_list|(
name|XEvent
modifier|*
name|xe
parameter_list|)
block|{
name|int
name|quit
init|=
literal|false
decl_stmt|;
name|QXlibWindow
modifier|*
name|platformWindow
init|=
name|QXlibWindow
operator|::
name|platformWindowForXWindow
argument_list|(
name|xe
operator|->
name|xany
operator|.
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|platformWindow
condition|)
return|return
literal|false
return|;
name|Atom
name|wmProtocolsAtom
init|=
name|QXlibStatic
operator|::
name|atom
argument_list|(
name|QXlibStatic
operator|::
name|WM_PROTOCOLS
argument_list|)
decl_stmt|;
name|Atom
name|wmDeleteWindowAtom
init|=
name|QXlibStatic
operator|::
name|atom
argument_list|(
name|QXlibStatic
operator|::
name|WM_DELETE_WINDOW
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|xe
operator|->
name|type
condition|)
block|{
case|case
name|ClientMessage
case|:
if|if
condition|(
name|xe
operator|->
name|xclient
operator|.
name|format
operator|==
literal|32
operator|&&
name|xe
operator|->
name|xclient
operator|.
name|message_type
operator|==
name|wmProtocolsAtom
condition|)
block|{
name|Atom
name|a
init|=
name|xe
operator|->
name|xclient
operator|.
name|data
operator|.
name|l
index|[
literal|0
index|]
decl_stmt|;
if|if
condition|(
name|a
operator|==
name|wmDeleteWindowAtom
condition|)
name|platformWindow
operator|->
name|handleCloseEvent
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|Expose
case|:
comment|// ###
comment|//            if (xe->xexpose.count == 0)
comment|//                platformWindow->paintEvent();
break|break;
case|case
name|ConfigureNotify
case|:
name|platformWindow
operator|->
name|resizeEvent
argument_list|(
operator|&
name|xe
operator|->
name|xconfigure
argument_list|)
expr_stmt|;
break|break;
case|case
name|ButtonPress
case|:
name|platformWindow
operator|->
name|mousePressEvent
argument_list|(
operator|&
name|xe
operator|->
name|xbutton
argument_list|)
expr_stmt|;
break|break;
case|case
name|ButtonRelease
case|:
name|platformWindow
operator|->
name|handleMouseEvent
argument_list|(
name|QEvent
operator|::
name|MouseButtonRelease
argument_list|,
operator|&
name|xe
operator|->
name|xbutton
argument_list|)
expr_stmt|;
break|break;
case|case
name|MotionNotify
case|:
name|platformWindow
operator|->
name|handleMouseEvent
argument_list|(
name|QEvent
operator|::
name|MouseMove
argument_list|,
operator|&
name|xe
operator|->
name|xbutton
argument_list|)
expr_stmt|;
break|break;
case|case
name|XKeyPress
case|:
name|mKeyboard
operator|->
name|handleKeyEvent
argument_list|(
name|platformWindow
operator|->
name|window
argument_list|()
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
operator|&
name|xe
operator|->
name|xkey
argument_list|)
expr_stmt|;
break|break;
case|case
name|XKeyRelease
case|:
name|mKeyboard
operator|->
name|handleKeyEvent
argument_list|(
name|platformWindow
operator|->
name|window
argument_list|()
argument_list|,
name|QEvent
operator|::
name|KeyRelease
argument_list|,
operator|&
name|xe
operator|->
name|xkey
argument_list|)
expr_stmt|;
break|break;
case|case
name|EnterNotify
case|:
name|platformWindow
operator|->
name|handleEnterEvent
argument_list|()
expr_stmt|;
break|break;
case|case
name|LeaveNotify
case|:
name|platformWindow
operator|->
name|handleLeaveEvent
argument_list|()
expr_stmt|;
break|break;
case|case
name|XFocusIn
case|:
name|platformWindow
operator|->
name|handleFocusInEvent
argument_list|()
expr_stmt|;
break|break;
case|case
name|XFocusOut
case|:
name|platformWindow
operator|->
name|handleFocusOutEvent
argument_list|()
expr_stmt|;
break|break;
case|case
name|PropertyNotify
case|:
break|break;
case|case
name|SelectionClear
case|:
name|qDebug
argument_list|()
operator|<<
literal|"Selection Clear!!!"
expr_stmt|;
break|break;
case|case
name|SelectionRequest
case|:
name|handleSelectionRequest
argument_list|(
name|xe
argument_list|)
expr_stmt|;
break|break;
case|case
name|SelectionNotify
case|:
name|qDebug
argument_list|()
operator|<<
literal|"Selection Notify!!!!"
expr_stmt|;
break|break;
default|default:
ifdef|#
directive|ifdef
name|MYX11_DEBUG
name|qDebug
argument_list|()
operator|<<
name|hex
operator|<<
name|xe
operator|->
name|xany
operator|.
name|window
operator|<<
literal|"Other X event"
operator|<<
name|xe
operator|->
name|type
expr_stmt|;
endif|#
directive|endif
break|break;
block|}
return|return
name|quit
return|;
block|}
end_function
begin_function
DECL|function|checkForClipboardEvents
specifier|static
name|Bool
name|checkForClipboardEvents
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|XEvent
modifier|*
name|e
parameter_list|,
name|XPointer
parameter_list|)
block|{
name|Atom
name|clipboard
init|=
name|QXlibStatic
operator|::
name|atom
argument_list|(
name|QXlibStatic
operator|::
name|CLIPBOARD
argument_list|)
decl_stmt|;
return|return
operator|(
operator|(
name|e
operator|->
name|type
operator|==
name|SelectionRequest
operator|&&
operator|(
name|e
operator|->
name|xselectionrequest
operator|.
name|selection
operator|==
name|XA_PRIMARY
operator|||
name|e
operator|->
name|xselectionrequest
operator|.
name|selection
operator|==
name|clipboard
operator|)
operator|)
operator|||
operator|(
name|e
operator|->
name|type
operator|==
name|SelectionClear
operator|&&
operator|(
name|e
operator|->
name|xselectionclear
operator|.
name|selection
operator|==
name|XA_PRIMARY
operator|||
name|e
operator|->
name|xselectionclear
operator|.
name|selection
operator|==
name|clipboard
operator|)
operator|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|waitForClipboardEvent
name|bool
name|QXlibScreen
operator|::
name|waitForClipboardEvent
parameter_list|(
name|Window
name|win
parameter_list|,
name|int
name|type
parameter_list|,
name|XEvent
modifier|*
name|event
parameter_list|,
name|int
name|timeout
parameter_list|)
block|{
name|QElapsedTimer
name|timer
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
do|do
block|{
if|if
condition|(
name|XCheckTypedWindowEvent
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|win
argument_list|,
name|type
argument_list|,
name|event
argument_list|)
condition|)
return|return
literal|true
return|;
comment|// process other clipboard events, since someone is probably requesting data from us
name|XEvent
name|e
decl_stmt|;
if|if
condition|(
name|XCheckIfEvent
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
operator|&
name|e
argument_list|,
name|checkForClipboardEvents
argument_list|,
literal|0
argument_list|)
condition|)
name|handleEvent
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
name|mDisplay
operator|->
name|flush
argument_list|()
expr_stmt|;
comment|// sleep 50 ms, so we don't use up CPU cycles all the time.
name|struct
name|timeval
name|usleep_tv
decl_stmt|;
name|usleep_tv
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|usleep_tv
operator|.
name|tv_usec
operator|=
literal|50000
expr_stmt|;
name|select
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|usleep_tv
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|timer
operator|.
name|elapsed
argument_list|()
operator|<
name|timeout
condition|)
do|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|eventDispatcher
name|void
name|QXlibScreen
operator|::
name|eventDispatcher
parameter_list|()
block|{
name|ulong
name|marker
init|=
name|XNextRequest
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|)
decl_stmt|;
comment|//    int i = 0;
while|while
condition|(
name|XPending
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|)
condition|)
block|{
name|XEvent
name|event
decl_stmt|;
name|XNextEvent
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
comment|/* done = */
name|handleEvent
argument_list|(
operator|&
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|.
name|xany
operator|.
name|serial
operator|>=
name|marker
condition|)
block|{
ifdef|#
directive|ifdef
name|MYX11_DEBUG
name|qDebug
argument_list|()
operator|<<
literal|"potential livelock averted"
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
literal|0
block|if (XEventsQueued(mDisplay->nativeDisplay(), QueuedAfterFlush)) {                     qDebug()<< "	with events queued";                     QTimer::singleShot(0, this, SLOT(eventDispatcher()));                 }
endif|#
directive|endif
break|break;
block|}
block|}
block|}
end_function
begin_function
DECL|function|grabWindow
name|QImage
name|QXlibScreen
operator|::
name|grabWindow
parameter_list|(
name|Window
name|window
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
if|if
condition|(
name|w
operator|==
literal|0
operator|||
name|h
operator|==
literal|0
condition|)
return|return
name|QImage
argument_list|()
return|;
comment|//WinId 0 means the desktop widget
if|if
condition|(
operator|!
name|window
condition|)
name|window
operator|=
name|rootWindow
argument_list|()
expr_stmt|;
name|XWindowAttributes
name|window_attr
decl_stmt|;
if|if
condition|(
operator|!
name|XGetWindowAttributes
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|window
argument_list|,
operator|&
name|window_attr
argument_list|)
condition|)
return|return
name|QImage
argument_list|()
return|;
if|if
condition|(
name|w
operator|<
literal|0
condition|)
name|w
operator|=
name|window_attr
operator|.
name|width
operator|-
name|x
expr_stmt|;
if|if
condition|(
name|h
operator|<
literal|0
condition|)
name|h
operator|=
name|window_attr
operator|.
name|height
operator|-
name|y
expr_stmt|;
comment|// Ideally, we should also limit ourselves to the screen area, but the Qt docs say
comment|// that it's "unsafe" to go outside the screen, so we can ignore that problem.
comment|//We're definitely not optimizing for speed...
name|XImage
modifier|*
name|xi
init|=
name|XGetImage
argument_list|(
name|mDisplay
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|window
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|AllPlanes
argument_list|,
name|ZPixmap
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|xi
condition|)
return|return
name|QImage
argument_list|()
return|;
comment|//taking a copy to make sure we have ownership -- not fast
name|QImage
name|result
init|=
name|QImage
argument_list|(
operator|(
name|uchar
operator|*
operator|)
name|xi
operator|->
name|data
argument_list|,
name|xi
operator|->
name|width
argument_list|,
name|xi
operator|->
name|height
argument_list|,
name|xi
operator|->
name|bytes_per_line
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
operator|.
name|copy
argument_list|()
decl_stmt|;
name|XDestroyImage
argument_list|(
name|xi
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|testLiteScreenForWidget
name|QXlibScreen
modifier|*
name|QXlibScreen
operator|::
name|testLiteScreenForWidget
parameter_list|(
name|QWindow
modifier|*
name|widget
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
name|QXlibScreen
operator|*
argument_list|>
argument_list|(
name|widget
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|display
name|QXlibDisplay
modifier|*
name|QXlibScreen
operator|::
name|display
parameter_list|()
specifier|const
block|{
return|return
name|mDisplay
return|;
block|}
end_function
begin_function
DECL|function|xScreenNumber
name|int
name|QXlibScreen
operator|::
name|xScreenNumber
parameter_list|()
specifier|const
block|{
return|return
name|mScreen
return|;
block|}
end_function
begin_function
DECL|function|defaultVisual
name|Visual
modifier|*
name|QXlibScreen
operator|::
name|defaultVisual
parameter_list|()
specifier|const
block|{
return|return
name|DefaultVisual
argument_list|(
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|xScreenNumber
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|keyboard
name|QXlibKeyboard
modifier|*
name|QXlibScreen
operator|::
name|keyboard
parameter_list|()
specifier|const
block|{
return|return
name|mKeyboard
return|;
block|}
end_function
begin_function
DECL|function|handleSelectionRequest
name|void
name|QXlibScreen
operator|::
name|handleSelectionRequest
parameter_list|(
name|XEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPlatformIntegration
modifier|*
name|integration
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
decl_stmt|;
name|QXlibClipboard
modifier|*
name|clipboard
init|=
cast|static_cast
argument_list|<
name|QXlibClipboard
operator|*
argument_list|>
argument_list|(
name|integration
operator|->
name|clipboard
argument_list|()
argument_list|)
decl_stmt|;
name|clipboard
operator|->
name|handleSelectionRequest
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
