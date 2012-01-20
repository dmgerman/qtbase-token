begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTLITESTATICINFO_H
end_ifndef
begin_define
DECL|macro|QTESTLITESTATICINFO_H
define|#
directive|define
name|QTESTLITESTATICINFO_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDataStream>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaType>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_comment
comment|// qcoreapplication_p.h includes qsettings.h which undefines Status
end_comment
begin_comment
comment|// therefore it is included here before the X stuff.
end_comment
begin_include
include|#
directive|include
file|<QtCore/private/qcoreapplication_p.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_XLIB_H_
argument_list|)
end_if
begin_comment
comment|// crude hack, but...
end_comment
begin_error
error|#
directive|error
literal|"cannot include<X11/Xlib.h> before this file"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|XRegisterIMInstantiateCallback
define|#
directive|define
name|XRegisterIMInstantiateCallback
value|qt_XRegisterIMInstantiateCallback
end_define
begin_define
DECL|macro|XUnregisterIMInstantiateCallback
define|#
directive|define
name|XUnregisterIMInstantiateCallback
value|qt_XUnregisterIMInstantiateCallback
end_define
begin_define
DECL|macro|XSetIMValues
define|#
directive|define
name|XSetIMValues
value|qt_XSetIMValues
end_define
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_undef
DECL|macro|XRegisterIMInstantiateCallback
undef|#
directive|undef
name|XRegisterIMInstantiateCallback
end_undef
begin_undef
DECL|macro|XUnregisterIMInstantiateCallback
undef|#
directive|undef
name|XUnregisterIMInstantiateCallback
end_undef
begin_undef
DECL|macro|XSetIMValues
undef|#
directive|undef
name|XSetIMValues
end_undef
begin_include
include|#
directive|include
file|<X11/Xutil.h>
end_include
begin_include
include|#
directive|include
file|<X11/Xos.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|index
end_ifdef
begin_undef
DECL|macro|index
undef|#
directive|undef
name|index
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|rindex
end_ifdef
begin_undef
DECL|macro|rindex
undef|#
directive|undef
name|rindex
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_VXWORS
end_ifdef
begin_ifdef
ifdef|#
directive|ifdef
name|open
end_ifdef
begin_undef
DECL|macro|open
undef|#
directive|undef
name|open
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|getpid
end_ifdef
begin_undef
DECL|macro|getpid
undef|#
directive|undef
name|getpid
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_VXWORKS
end_comment
begin_include
include|#
directive|include
file|<X11/Xatom.h>
end_include
begin_comment
comment|//#define QT_NO_SHAPE
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_SHAPE
end_ifdef
begin_define
DECL|macro|XShapeCombineRegion
define|#
directive|define
name|XShapeCombineRegion
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|)
end_define
begin_define
DECL|macro|XShapeCombineMask
define|#
directive|define
name|XShapeCombineMask
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|)
end_define
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<X11/extensions/shape.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SHAPE
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_TABLET
argument_list|)
end_if
begin_include
include|#
directive|include
file|<X11/extensions/XInput.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_IRIX
argument_list|)
end_if
begin_include
include|#
directive|include
file|<X11/extensions/SGIMisc.h>
end_include
begin_include
include|#
directive|include
file|<wacom.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABLET
end_comment
begin_comment
comment|// #define QT_NO_XINERAMA
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XINERAMA
end_ifndef
begin_comment
comment|// XFree86 does not C++ify Xinerama (at least up to XFree86 4.0.3).
end_comment
begin_extern
extern|extern
literal|"C"
block|{
include|#
directive|include
file|<X11/extensions/Xinerama.h>
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_XINERAMA
end_comment
begin_comment
comment|// #define QT_NO_XRANDR
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XRANDR
end_ifndef
begin_include
include|#
directive|include
file|<X11/extensions/Xrandr.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_XRANDR
end_comment
begin_comment
comment|// #define QT_NO_XRENDER
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XRENDER
end_ifndef
begin_include
include|#
directive|include
file|<X11/extensions/Xrender.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_XRENDER
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XSYNC
end_ifndef
begin_extern
extern|extern
literal|"C"
block|{
include|#
directive|include
file|"X11/extensions/sync.h"
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// #define QT_NO_XKB
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XKB
end_ifndef
begin_include
include|#
directive|include
file|<X11/XKBlib.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_XKB
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|XlibSpecificationRelease
argument_list|)
end_if
begin_define
DECL|macro|X11R4
define|#
directive|define
name|X11R4
end_define
begin_typedef
DECL|typedef|XPointer
typedef|typedef
name|char
modifier|*
name|XPointer
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_undef
DECL|macro|X11R4
undef|#
directive|undef
name|X11R4
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XFIXES
end_ifndef
begin_include
include|#
directive|include
file|<X11/extensions/Xfixes.h>
end_include
begin_typedef
DECL|typedef|PtrXFixesQueryExtension
typedef|typedef
name|Bool
function_decl|(
modifier|*
name|PtrXFixesQueryExtension
function_decl|)
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrXFixesQueryVersion
typedef|typedef
name|Status
function_decl|(
modifier|*
name|PtrXFixesQueryVersion
function_decl|)
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrXFixesSetCursorName
typedef|typedef
name|void
function_decl|(
modifier|*
name|PtrXFixesSetCursorName
function_decl|)
parameter_list|(
name|Display
modifier|*
name|dpy
parameter_list|,
name|Cursor
name|cursor
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrXFixesSelectSelectionInput
typedef|typedef
name|void
function_decl|(
modifier|*
name|PtrXFixesSelectSelectionInput
function_decl|)
parameter_list|(
name|Display
modifier|*
name|dpy
parameter_list|,
name|Window
name|win
parameter_list|,
name|Atom
name|selection
parameter_list|,
name|unsigned
name|long
name|eventMask
parameter_list|)
function_decl|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_XFIXES
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XCURSOR
end_ifndef
begin_include
include|#
directive|include
file|<X11/Xcursor/Xcursor.h>
end_include
begin_typedef
DECL|typedef|PtrXcursorLibraryLoadCursor
typedef|typedef
name|Cursor
function_decl|(
modifier|*
name|PtrXcursorLibraryLoadCursor
function_decl|)
parameter_list|(
name|Display
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_XCURSOR
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XINERAMA
end_ifndef
begin_typedef
DECL|typedef|PtrXineramaQueryExtension
typedef|typedef
name|Bool
function_decl|(
modifier|*
name|PtrXineramaQueryExtension
function_decl|)
parameter_list|(
name|Display
modifier|*
name|dpy
parameter_list|,
name|int
modifier|*
name|event_base
parameter_list|,
name|int
modifier|*
name|error_base
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrXineramaIsActive
typedef|typedef
name|Bool
function_decl|(
modifier|*
name|PtrXineramaIsActive
function_decl|)
parameter_list|(
name|Display
modifier|*
name|dpy
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrXineramaQueryScreens
typedef|typedef
name|XineramaScreenInfo
modifier|*
function_decl|(
modifier|*
name|PtrXineramaQueryScreens
function_decl|)
parameter_list|(
name|Display
modifier|*
name|dpy
parameter_list|,
name|int
modifier|*
name|number
parameter_list|)
function_decl|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_XINERAMA
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XRANDR
end_ifndef
begin_typedef
DECL|typedef|PtrXRRSelectInput
typedef|typedef
name|void
function_decl|(
modifier|*
name|PtrXRRSelectInput
function_decl|)
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|Window
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrXRRUpdateConfiguration
typedef|typedef
name|int
function_decl|(
modifier|*
name|PtrXRRUpdateConfiguration
function_decl|)
parameter_list|(
name|XEvent
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrXRRRootToScreen
typedef|typedef
name|int
function_decl|(
modifier|*
name|PtrXRRRootToScreen
function_decl|)
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|Window
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrXRRQueryExtension
typedef|typedef
name|Bool
function_decl|(
modifier|*
name|PtrXRRQueryExtension
function_decl|)
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_XRANDR
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XINPUT
end_ifndef
begin_typedef
DECL|typedef|PtrXCloseDevice
typedef|typedef
name|int
function_decl|(
modifier|*
name|PtrXCloseDevice
function_decl|)
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|XDevice
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrXListInputDevices
typedef|typedef
name|XDeviceInfo
modifier|*
function_decl|(
modifier|*
name|PtrXListInputDevices
function_decl|)
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrXOpenDevice
typedef|typedef
name|XDevice
modifier|*
function_decl|(
modifier|*
name|PtrXOpenDevice
function_decl|)
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|XID
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrXFreeDeviceList
typedef|typedef
name|void
function_decl|(
modifier|*
name|PtrXFreeDeviceList
function_decl|)
parameter_list|(
name|XDeviceInfo
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrXSelectExtensionEvent
typedef|typedef
name|int
function_decl|(
modifier|*
name|PtrXSelectExtensionEvent
function_decl|)
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|Window
parameter_list|,
name|XEventClass
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_XINPUT
end_comment
begin_comment
comment|/*  * Solaris patch 108652-47 and higher fixes crases in  * XRegisterIMInstantiateCallback, but the function doesn't seem to  * work.  *  * Instead, we disabled R6 input, and open the input method  * immediately at application start.  */
end_comment
begin_comment
comment|//######### XFree86 has wrong declarations for XRegisterIMInstantiateCallback
end_comment
begin_comment
comment|//######### and XUnregisterIMInstantiateCallback in at least version 3.3.2.
end_comment
begin_comment
comment|//######### Many old X11R6 header files lack XSetIMValues.
end_comment
begin_comment
comment|//######### Therefore, we have to declare these functions ourselves.
end_comment
begin_extern
extern|extern
literal|"C"
name|Bool
name|XRegisterIMInstantiateCallback
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|struct
name|_XrmHashBucketRec
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|XIMProc
parameter_list|,
comment|//XFree86 has XIDProc, which has to be wrong
name|XPointer
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|Bool
name|XUnregisterIMInstantiateCallback
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|struct
name|_XrmHashBucketRec
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|XIMProc
parameter_list|,
comment|//XFree86 has XIDProc, which has to be wrong
name|XPointer
parameter_list|)
function_decl|;
end_extern
begin_ifndef
ifndef|#
directive|ifndef
name|X11R4
end_ifndef
begin_include
include|#
directive|include
file|<X11/Xlocale.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// X11R4
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MITSHM
end_ifndef
begin_include
include|#
directive|include
file|<X11/extensions/XShm.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MITSHM
end_comment
begin_comment
comment|// rename a couple of X defines to get rid of name clashes
end_comment
begin_comment
comment|// resolve the conflict between X11's FocusIn and QEvent::FocusIn
end_comment
begin_enum
enum|enum
block|{
DECL|enumerator|XFocusOut
name|XFocusOut
init|=
name|FocusOut
block|,
DECL|enumerator|XFocusIn
name|XFocusIn
init|=
name|FocusIn
block|,
DECL|enumerator|XKeyPress
name|XKeyPress
init|=
name|KeyPress
block|,
DECL|enumerator|XKeyRelease
name|XKeyRelease
init|=
name|KeyRelease
block|,
DECL|enumerator|XNone
name|XNone
init|=
name|None
block|,
DECL|enumerator|XRevertToParent
name|XRevertToParent
init|=
name|RevertToParent
block|,
DECL|enumerator|XGrayScale
name|XGrayScale
init|=
name|GrayScale
block|,
DECL|enumerator|XCursorShape
name|XCursorShape
init|=
name|CursorShape
block|}
enum|;
end_enum
begin_undef
DECL|macro|FocusOut
undef|#
directive|undef
name|FocusOut
end_undef
begin_undef
DECL|macro|FocusIn
undef|#
directive|undef
name|FocusIn
end_undef
begin_undef
DECL|macro|KeyPress
undef|#
directive|undef
name|KeyPress
end_undef
begin_undef
DECL|macro|KeyRelease
undef|#
directive|undef
name|KeyRelease
end_undef
begin_undef
DECL|macro|None
undef|#
directive|undef
name|None
end_undef
begin_undef
DECL|macro|RevertToParent
undef|#
directive|undef
name|RevertToParent
end_undef
begin_undef
DECL|macro|GrayScale
undef|#
directive|undef
name|GrayScale
end_undef
begin_undef
DECL|macro|CursorShape
undef|#
directive|undef
name|CursorShape
end_undef
begin_ifdef
ifdef|#
directive|ifdef
name|FontChange
end_ifdef
begin_undef
DECL|macro|FontChange
undef|#
directive|undef
name|FontChange
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QXlibStatic
block|{
name|public
label|:
enum|enum
name|X11Atom
block|{
comment|// window-manager<-> client protocols
name|WM_PROTOCOLS
block|,
name|WM_DELETE_WINDOW
block|,
name|WM_TAKE_FOCUS
block|,
name|_NET_WM_PING
block|,
name|_NET_WM_CONTEXT_HELP
block|,
name|_NET_WM_SYNC_REQUEST
block|,
name|_NET_WM_SYNC_REQUEST_COUNTER
block|,
comment|// ICCCM window state
name|WM_STATE
block|,
name|WM_CHANGE_STATE
block|,
comment|// Session management
name|WM_CLIENT_LEADER
block|,
name|WM_WINDOW_ROLE
block|,
name|SM_CLIENT_ID
block|,
comment|// Clipboard
name|CLIPBOARD
block|,
name|INCR
block|,
name|TARGETS
block|,
name|MULTIPLE
block|,
name|TIMESTAMP
block|,
name|SAVE_TARGETS
block|,
name|CLIP_TEMPORARY
block|,
name|_QT_SELECTION
block|,
name|_QT_CLIPBOARD_SENTINEL
block|,
name|_QT_SELECTION_SENTINEL
block|,
name|CLIPBOARD_MANAGER
block|,
name|RESOURCE_MANAGER
block|,
name|_XSETROOT_ID
block|,
name|_QT_SCROLL_DONE
block|,
name|_QT_INPUT_ENCODING
block|,
name|_MOTIF_WM_HINTS
block|,
name|DTWM_IS_RUNNING
block|,
name|ENLIGHTENMENT_DESKTOP
block|,
name|_DT_SAVE_MODE
block|,
name|_SGI_DESKS_MANAGER
block|,
comment|// EWMH (aka NETWM)
name|_NET_SUPPORTED
block|,
name|_NET_VIRTUAL_ROOTS
block|,
name|_NET_WORKAREA
block|,
name|_NET_MOVERESIZE_WINDOW
block|,
name|_NET_WM_MOVERESIZE
block|,
name|_NET_WM_NAME
block|,
name|_NET_WM_ICON_NAME
block|,
name|_NET_WM_ICON
block|,
name|_NET_WM_PID
block|,
name|_NET_WM_WINDOW_OPACITY
block|,
name|_NET_WM_STATE
block|,
name|_NET_WM_STATE_ABOVE
block|,
name|_NET_WM_STATE_BELOW
block|,
name|_NET_WM_STATE_FULLSCREEN
block|,
name|_NET_WM_STATE_MAXIMIZED_HORZ
block|,
name|_NET_WM_STATE_MAXIMIZED_VERT
block|,
name|_NET_WM_STATE_MODAL
block|,
name|_NET_WM_STATE_STAYS_ON_TOP
block|,
name|_NET_WM_STATE_DEMANDS_ATTENTION
block|,
name|_NET_WM_USER_TIME
block|,
name|_NET_WM_USER_TIME_WINDOW
block|,
name|_NET_WM_FULL_PLACEMENT
block|,
name|_NET_WM_WINDOW_TYPE
block|,
name|_NET_WM_WINDOW_TYPE_DESKTOP
block|,
name|_NET_WM_WINDOW_TYPE_DOCK
block|,
name|_NET_WM_WINDOW_TYPE_TOOLBAR
block|,
name|_NET_WM_WINDOW_TYPE_MENU
block|,
name|_NET_WM_WINDOW_TYPE_UTILITY
block|,
name|_NET_WM_WINDOW_TYPE_SPLASH
block|,
name|_NET_WM_WINDOW_TYPE_DIALOG
block|,
name|_NET_WM_WINDOW_TYPE_DROPDOWN_MENU
block|,
name|_NET_WM_WINDOW_TYPE_POPUP_MENU
block|,
name|_NET_WM_WINDOW_TYPE_TOOLTIP
block|,
name|_NET_WM_WINDOW_TYPE_NOTIFICATION
block|,
name|_NET_WM_WINDOW_TYPE_COMBO
block|,
name|_NET_WM_WINDOW_TYPE_DND
block|,
name|_NET_WM_WINDOW_TYPE_NORMAL
block|,
name|_KDE_NET_WM_WINDOW_TYPE_OVERRIDE
block|,
name|_KDE_NET_WM_FRAME_STRUT
block|,
name|_NET_STARTUP_INFO
block|,
name|_NET_STARTUP_INFO_BEGIN
block|,
name|_NET_SUPPORTING_WM_CHECK
block|,
name|_NET_WM_CM_S0
block|,
name|_NET_SYSTEM_TRAY_VISUAL
block|,
name|_NET_ACTIVE_WINDOW
block|,
comment|// Property formats
name|COMPOUND_TEXT
block|,
name|TEXT
block|,
name|UTF8_STRING
block|,
comment|// Xdnd
name|XdndEnter
block|,
name|XdndPosition
block|,
name|XdndStatus
block|,
name|XdndLeave
block|,
name|XdndDrop
block|,
name|XdndFinished
block|,
name|XdndTypelist
block|,
name|XdndActionList
block|,
name|XdndSelection
block|,
name|XdndAware
block|,
name|XdndProxy
block|,
name|XdndActionCopy
block|,
name|XdndActionLink
block|,
name|XdndActionMove
block|,
name|XdndActionPrivate
block|,
comment|// Motif DND
name|_MOTIF_DRAG_AND_DROP_MESSAGE
block|,
name|_MOTIF_DRAG_INITIATOR_INFO
block|,
name|_MOTIF_DRAG_RECEIVER_INFO
block|,
name|_MOTIF_DRAG_WINDOW
block|,
name|_MOTIF_DRAG_TARGETS
block|,
name|XmTRANSFER_SUCCESS
block|,
name|XmTRANSFER_FAILURE
block|,
comment|// Xkb
name|_XKB_RULES_NAMES
block|,
comment|// XEMBED
name|_XEMBED
block|,
name|_XEMBED_INFO
block|,
name|XWacomStylus
block|,
name|XWacomCursor
block|,
name|XWacomEraser
block|,
name|XTabletStylus
block|,
name|XTabletEraser
block|,
name|NPredefinedAtoms
block|,
name|_QT_SETTINGS_TIMESTAMP
init|=
name|NPredefinedAtoms
block|,
name|NAtoms
block|}
enum|;
specifier|static
name|Atom
name|atom
parameter_list|(
name|X11Atom
name|atom
parameter_list|)
function_decl|;
specifier|static
name|bool
name|isSupportedByWM
parameter_list|(
name|Atom
name|atom
parameter_list|)
function_decl|;
specifier|static
name|bool
name|useXFixes
parameter_list|()
function_decl|;
specifier|static
name|int
name|xFixesEventBase
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_XFIXES
specifier|static
name|PtrXFixesSelectSelectionInput
name|xFixesSelectSelectionInput
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|//QT_NO_XFIXES
specifier|static
name|QImage
name|qimageFromXImage
parameter_list|(
name|XImage
modifier|*
name|xi
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTESTLITESTATICINFO_H
end_comment
end_unit
