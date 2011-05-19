begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxlibstatic.h"
end_include
begin_include
include|#
directive|include
file|"qxlibscreen.h"
end_include
begin_include
include|#
directive|include
file|"qxlibdisplay.h"
end_include
begin_include
include|#
directive|include
file|<qplatformdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QBuffer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLibrary>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_decl_stmt
DECL|variable|x11_atomnames
specifier|static
specifier|const
name|char
modifier|*
name|x11_atomnames
init|=
block|{
comment|// window-manager<-> client protocols
literal|"WM_PROTOCOLS\0"
literal|"WM_DELETE_WINDOW\0"
literal|"WM_TAKE_FOCUS\0"
literal|"_NET_WM_PING\0"
literal|"_NET_WM_CONTEXT_HELP\0"
literal|"_NET_WM_SYNC_REQUEST\0"
literal|"_NET_WM_SYNC_REQUEST_COUNTER\0"
comment|// ICCCM window state
literal|"WM_STATE\0"
literal|"WM_CHANGE_STATE\0"
comment|// Session management
literal|"WM_CLIENT_LEADER\0"
literal|"WM_WINDOW_ROLE\0"
literal|"SM_CLIENT_ID\0"
comment|// Clipboard
literal|"CLIPBOARD\0"
literal|"INCR\0"
literal|"TARGETS\0"
literal|"MULTIPLE\0"
literal|"TIMESTAMP\0"
literal|"SAVE_TARGETS\0"
literal|"CLIP_TEMPORARY\0"
literal|"_QT_SELECTION\0"
literal|"_QT_CLIPBOARD_SENTINEL\0"
literal|"_QT_SELECTION_SENTINEL\0"
literal|"CLIPBOARD_MANAGER\0"
literal|"RESOURCE_MANAGER\0"
literal|"_XSETROOT_ID\0"
literal|"_QT_SCROLL_DONE\0"
literal|"_QT_INPUT_ENCODING\0"
literal|"_MOTIF_WM_HINTS\0"
literal|"DTWM_IS_RUNNING\0"
literal|"ENLIGHTENMENT_DESKTOP\0"
literal|"_DT_SAVE_MODE\0"
literal|"_SGI_DESKS_MANAGER\0"
comment|// EWMH (aka NETWM)
literal|"_NET_SUPPORTED\0"
literal|"_NET_VIRTUAL_ROOTS\0"
literal|"_NET_WORKAREA\0"
literal|"_NET_MOVERESIZE_WINDOW\0"
literal|"_NET_WM_MOVERESIZE\0"
literal|"_NET_WM_NAME\0"
literal|"_NET_WM_ICON_NAME\0"
literal|"_NET_WM_ICON\0"
literal|"_NET_WM_PID\0"
literal|"_NET_WM_WINDOW_OPACITY\0"
literal|"_NET_WM_STATE\0"
literal|"_NET_WM_STATE_ABOVE\0"
literal|"_NET_WM_STATE_BELOW\0"
literal|"_NET_WM_STATE_FULLSCREEN\0"
literal|"_NET_WM_STATE_MAXIMIZED_HORZ\0"
literal|"_NET_WM_STATE_MAXIMIZED_VERT\0"
literal|"_NET_WM_STATE_MODAL\0"
literal|"_NET_WM_STATE_STAYS_ON_TOP\0"
literal|"_NET_WM_STATE_DEMANDS_ATTENTION\0"
literal|"_NET_WM_USER_TIME\0"
literal|"_NET_WM_USER_TIME_WINDOW\0"
literal|"_NET_WM_FULL_PLACEMENT\0"
literal|"_NET_WM_WINDOW_TYPE\0"
literal|"_NET_WM_WINDOW_TYPE_DESKTOP\0"
literal|"_NET_WM_WINDOW_TYPE_DOCK\0"
literal|"_NET_WM_WINDOW_TYPE_TOOLBAR\0"
literal|"_NET_WM_WINDOW_TYPE_MENU\0"
literal|"_NET_WM_WINDOW_TYPE_UTILITY\0"
literal|"_NET_WM_WINDOW_TYPE_SPLASH\0"
literal|"_NET_WM_WINDOW_TYPE_DIALOG\0"
literal|"_NET_WM_WINDOW_TYPE_DROPDOWN_MENU\0"
literal|"_NET_WM_WINDOW_TYPE_POPUP_MENU\0"
literal|"_NET_WM_WINDOW_TYPE_TOOLTIP\0"
literal|"_NET_WM_WINDOW_TYPE_NOTIFICATION\0"
literal|"_NET_WM_WINDOW_TYPE_COMBO\0"
literal|"_NET_WM_WINDOW_TYPE_DND\0"
literal|"_NET_WM_WINDOW_TYPE_NORMAL\0"
literal|"_KDE_NET_WM_WINDOW_TYPE_OVERRIDE\0"
literal|"_KDE_NET_WM_FRAME_STRUT\0"
literal|"_NET_STARTUP_INFO\0"
literal|"_NET_STARTUP_INFO_BEGIN\0"
literal|"_NET_SUPPORTING_WM_CHECK\0"
literal|"_NET_WM_CM_S0\0"
literal|"_NET_SYSTEM_TRAY_VISUAL\0"
literal|"_NET_ACTIVE_WINDOW\0"
comment|// Property formats
literal|"COMPOUND_TEXT\0"
literal|"TEXT\0"
literal|"UTF8_STRING\0"
comment|// xdnd
literal|"XdndEnter\0"
literal|"XdndPosition\0"
literal|"XdndStatus\0"
literal|"XdndLeave\0"
literal|"XdndDrop\0"
literal|"XdndFinished\0"
literal|"XdndTypeList\0"
literal|"XdndActionList\0"
literal|"XdndSelection\0"
literal|"XdndAware\0"
literal|"XdndProxy\0"
literal|"XdndActionCopy\0"
literal|"XdndActionLink\0"
literal|"XdndActionMove\0"
literal|"XdndActionPrivate\0"
comment|// Motif DND
literal|"_MOTIF_DRAG_AND_DROP_MESSAGE\0"
literal|"_MOTIF_DRAG_INITIATOR_INFO\0"
literal|"_MOTIF_DRAG_RECEIVER_INFO\0"
literal|"_MOTIF_DRAG_WINDOW\0"
literal|"_MOTIF_DRAG_TARGETS\0"
literal|"XmTRANSFER_SUCCESS\0"
literal|"XmTRANSFER_FAILURE\0"
comment|// Xkb
literal|"_XKB_RULES_NAMES\0"
comment|// XEMBED
literal|"_XEMBED\0"
literal|"_XEMBED_INFO\0"
comment|// Wacom old. (before version 0.10)
literal|"Wacom Stylus\0"
literal|"Wacom Cursor\0"
literal|"Wacom Eraser\0"
comment|// Tablet
literal|"STYLUS\0"
literal|"ERASER\0"
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     \internal     Try to resolve a \a symbol from \a library with the version specified     by \a vernum.      Note that, in the case of the Xfixes library, \a vernum is not the same as     \c XFIXES_MAJOR - it is a part of soname and may differ from the Xfixes     version. */
end_comment
begin_function
DECL|function|qt_load_library_runtime
specifier|static
name|void
modifier|*
name|qt_load_library_runtime
parameter_list|(
specifier|const
name|char
modifier|*
name|library
parameter_list|,
name|int
name|vernum
parameter_list|,
name|int
name|highestVernum
parameter_list|,
specifier|const
name|char
modifier|*
name|symbol
parameter_list|)
block|{
name|QList
argument_list|<
name|int
argument_list|>
name|versions
decl_stmt|;
comment|// we try to load in the following order:
comment|// explicit version -> the default one -> (from the highest (highestVernum) to the lowest (vernum) )
if|if
condition|(
name|vernum
operator|!=
operator|-
literal|1
condition|)
name|versions
operator|<<
name|vernum
expr_stmt|;
name|versions
operator|<<
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|vernum
operator|!=
operator|-
literal|1
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
name|highestVernum
init|;
name|i
operator|>
name|vernum
condition|;
operator|--
name|i
control|)
name|versions
operator|<<
name|i
expr_stmt|;
block|}
name|Q_FOREACH
argument_list|(
argument|int version
argument_list|,
argument|versions
argument_list|)
block|{
name|QLatin1String
name|libName
argument_list|(
name|library
argument_list|)
decl_stmt|;
name|QLibrary
name|xfixesLib
argument_list|(
name|libName
argument_list|,
name|version
argument_list|)
decl_stmt|;
name|void
modifier|*
name|ptr
init|=
name|xfixesLib
operator|.
name|resolve
argument_list|(
name|symbol
argument_list|)
decl_stmt|;
if|if
condition|(
name|ptr
condition|)
return|return
name|ptr
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_define
DECL|macro|XFIXES_LOAD_RUNTIME
define|#
directive|define
name|XFIXES_LOAD_RUNTIME
parameter_list|(
name|vernum
parameter_list|,
name|symbol
parameter_list|,
name|symbol_type
parameter_list|)
define|\
value|(symbol_type)qt_load_library_runtime("libXfixes", vernum, 4, #symbol);
end_define
begin_define
DECL|macro|XFIXES_LOAD_V1
define|#
directive|define
name|XFIXES_LOAD_V1
parameter_list|(
name|symbol
parameter_list|)
define|\
value|XFIXES_LOAD_RUNTIME(1, symbol, Ptr##symbol)
end_define
begin_define
DECL|macro|XFIXES_LOAD_V2
define|#
directive|define
name|XFIXES_LOAD_V2
parameter_list|(
name|symbol
parameter_list|)
define|\
value|XFIXES_LOAD_RUNTIME(2, symbol, Ptr##symbol)
end_define
begin_class
DECL|class|QTestLiteStaticInfoPrivate
class|class
name|QTestLiteStaticInfoPrivate
block|{
public|public:
DECL|function|QTestLiteStaticInfoPrivate
name|QTestLiteStaticInfoPrivate
parameter_list|()
member_init_list|:
name|use_xfixes
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|xfixes_major
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|xfixes_eventbase
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|xfixes_errorbase
argument_list|(
literal|0
argument_list|)
block|{
name|QXlibScreen
modifier|*
name|screen
init|=
name|qobject_cast
argument_list|<
name|QXlibScreen
operator|*
argument_list|>
argument_list|(
name|QApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|screens
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|initializeAllAtoms
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|initializeSupportedAtoms
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|resolveXFixes
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
DECL|function|isSupportedByWM
name|bool
name|isSupportedByWM
parameter_list|(
name|Atom
name|atom
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_supportedAtoms
condition|)
return|return
literal|false
return|;
name|bool
name|supported
init|=
literal|false
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|m_supportedAtoms
index|[
name|i
index|]
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|m_supportedAtoms
index|[
name|i
operator|++
index|]
operator|==
name|atom
condition|)
block|{
name|supported
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
return|return
name|supported
return|;
block|}
DECL|function|atom
name|Atom
name|atom
parameter_list|(
name|QXlibStatic
operator|::
name|X11Atom
name|atom
parameter_list|)
block|{
return|return
name|m_allAtoms
index|[
name|atom
index|]
return|;
block|}
DECL|function|useXFixes
name|bool
name|useXFixes
parameter_list|()
specifier|const
block|{
return|return
name|use_xfixes
return|;
block|}
DECL|function|xFixesEventBase
name|int
name|xFixesEventBase
parameter_list|()
specifier|const
block|{
return|return
name|xfixes_eventbase
return|;
block|}
DECL|function|xFixesSelectSelectionInput
name|PtrXFixesSelectSelectionInput
name|xFixesSelectSelectionInput
parameter_list|()
specifier|const
block|{
return|return
name|ptrXFixesSelectSelectionInput
return|;
block|}
DECL|function|qimageFromXImage
name|QImage
name|qimageFromXImage
parameter_list|(
name|XImage
modifier|*
name|xi
parameter_list|)
block|{
name|QImage
operator|::
name|Format
name|format
init|=
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
decl_stmt|;
if|if
condition|(
name|xi
operator|->
name|depth
operator|==
literal|24
condition|)
name|format
operator|=
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
elseif|else
if|if
condition|(
name|xi
operator|->
name|depth
operator|==
literal|16
condition|)
name|format
operator|=
name|QImage
operator|::
name|Format_RGB16
expr_stmt|;
name|QImage
name|image
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
name|format
argument_list|)
operator|.
name|copy
argument_list|()
decl_stmt|;
comment|// we may have to swap the byte order
if|if
condition|(
operator|(
name|QSysInfo
operator|::
name|ByteOrder
operator|==
name|QSysInfo
operator|::
name|LittleEndian
operator|&&
name|xi
operator|->
name|byte_order
operator|==
name|MSBFirst
operator|)
operator|||
operator|(
name|QSysInfo
operator|::
name|ByteOrder
operator|==
name|QSysInfo
operator|::
name|BigEndian
operator|&&
name|xi
operator|->
name|byte_order
operator|==
name|LSBFirst
operator|)
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
name|image
operator|.
name|height
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|xi
operator|->
name|depth
operator|==
literal|16
condition|)
block|{
name|ushort
modifier|*
name|p
init|=
operator|(
name|ushort
operator|*
operator|)
name|image
operator|.
name|scanLine
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|ushort
modifier|*
name|end
init|=
name|p
operator|+
name|image
operator|.
name|width
argument_list|()
decl_stmt|;
while|while
condition|(
name|p
operator|<
name|end
condition|)
block|{
operator|*
name|p
operator|=
operator|(
operator|(
operator|*
name|p
operator|<<
literal|8
operator|)
operator|&
literal|0xff00
operator|)
operator||
operator|(
operator|(
operator|*
name|p
operator|>>
literal|8
operator|)
operator|&
literal|0x00ff
operator|)
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
block|}
else|else
block|{
name|uint
modifier|*
name|p
init|=
operator|(
name|uint
operator|*
operator|)
name|image
operator|.
name|scanLine
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|uint
modifier|*
name|end
init|=
name|p
operator|+
name|image
operator|.
name|width
argument_list|()
decl_stmt|;
while|while
condition|(
name|p
operator|<
name|end
condition|)
block|{
operator|*
name|p
operator|=
operator|(
operator|(
operator|*
name|p
operator|<<
literal|24
operator|)
operator|&
literal|0xff000000
operator|)
operator||
operator|(
operator|(
operator|*
name|p
operator|<<
literal|8
operator|)
operator|&
literal|0x00ff0000
operator|)
operator||
operator|(
operator|(
operator|*
name|p
operator|>>
literal|8
operator|)
operator|&
literal|0x0000ff00
operator|)
operator||
operator|(
operator|(
operator|*
name|p
operator|>>
literal|24
operator|)
operator|&
literal|0x000000ff
operator|)
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
block|}
block|}
block|}
comment|// fix-up alpha channel
if|if
condition|(
name|format
operator|==
name|QImage
operator|::
name|Format_RGB32
condition|)
block|{
name|QRgb
modifier|*
name|p
init|=
operator|(
name|QRgb
operator|*
operator|)
name|image
operator|.
name|bits
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|xi
operator|->
name|height
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|xi
operator|->
name|width
condition|;
operator|++
name|x
control|)
name|p
index|[
name|x
index|]
operator||=
literal|0xff000000
expr_stmt|;
name|p
operator|+=
name|xi
operator|->
name|bytes_per_line
operator|/
literal|4
expr_stmt|;
block|}
block|}
return|return
name|image
return|;
block|}
private|private:
DECL|function|initializeAllAtoms
name|void
name|initializeAllAtoms
parameter_list|(
name|QXlibScreen
modifier|*
name|screen
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|names
index|[
name|QXlibStatic
operator|::
name|NAtoms
index|]
decl_stmt|;
specifier|const
name|char
modifier|*
name|ptr
init|=
name|x11_atomnames
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|*
name|ptr
condition|)
block|{
name|names
index|[
name|i
operator|++
index|]
operator|=
name|ptr
expr_stmt|;
while|while
condition|(
operator|*
name|ptr
condition|)
operator|++
name|ptr
expr_stmt|;
operator|++
name|ptr
expr_stmt|;
block|}
name|Q_ASSERT
argument_list|(
name|i
operator|==
name|QXlibStatic
operator|::
name|NPredefinedAtoms
argument_list|)
expr_stmt|;
name|QByteArray
name|settings_atom_name
argument_list|(
literal|"_QT_SETTINGS_TIMESTAMP_"
argument_list|)
decl_stmt|;
name|settings_atom_name
operator|+=
name|XDisplayName
argument_list|(
name|qPrintable
argument_list|(
name|screen
operator|->
name|display
argument_list|()
operator|->
name|displayName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|names
index|[
name|i
operator|++
index|]
operator|=
name|settings_atom_name
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|i
operator|==
name|QXlibStatic
operator|::
name|NAtoms
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
comment|//defined(XlibSpecificationRelease)&& (XlibSpecificationRelease>= 6)
block|XInternAtoms(screen->display(), (char **)names, i, False, m_allAtoms);
else|#
directive|else
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|QXlibStatic
operator|::
name|NAtoms
condition|;
operator|++
name|i
control|)
name|m_allAtoms
index|[
name|i
index|]
operator|=
name|XInternAtom
argument_list|(
name|screen
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
operator|(
name|char
operator|*
operator|)
name|names
index|[
name|i
index|]
argument_list|,
name|False
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
DECL|function|initializeSupportedAtoms
name|void
name|initializeSupportedAtoms
parameter_list|(
name|QXlibScreen
modifier|*
name|screen
parameter_list|)
block|{
name|Atom
name|type
decl_stmt|;
name|int
name|format
decl_stmt|;
name|long
name|offset
init|=
literal|0
decl_stmt|;
name|unsigned
name|long
name|nitems
decl_stmt|,
name|after
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
init|=
literal|0
decl_stmt|;
name|int
name|e
init|=
name|XGetWindowProperty
argument_list|(
name|screen
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|screen
operator|->
name|rootWindow
argument_list|()
argument_list|,
name|this
operator|->
name|atom
argument_list|(
name|QXlibStatic
operator|::
name|_NET_SUPPORTED
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|False
argument_list|,
name|XA_ATOM
argument_list|,
operator|&
name|type
argument_list|,
operator|&
name|format
argument_list|,
operator|&
name|nitems
argument_list|,
operator|&
name|after
argument_list|,
operator|&
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
name|data
condition|)
name|XFree
argument_list|(
name|data
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|==
name|Success
operator|&&
name|type
operator|==
name|XA_ATOM
operator|&&
name|format
operator|==
literal|32
condition|)
block|{
name|QBuffer
name|ts
decl_stmt|;
name|ts
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
while|while
condition|(
name|after
operator|>
literal|0
condition|)
block|{
name|XGetWindowProperty
argument_list|(
name|screen
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|screen
operator|->
name|rootWindow
argument_list|()
argument_list|,
name|this
operator|->
name|atom
argument_list|(
name|QXlibStatic
operator|::
name|_NET_SUPPORTED
argument_list|)
argument_list|,
name|offset
argument_list|,
literal|1024
argument_list|,
name|False
argument_list|,
name|XA_ATOM
argument_list|,
operator|&
name|type
argument_list|,
operator|&
name|format
argument_list|,
operator|&
name|nitems
argument_list|,
operator|&
name|after
argument_list|,
operator|&
name|data
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|XA_ATOM
operator|&&
name|format
operator|==
literal|32
condition|)
block|{
name|ts
operator|.
name|write
argument_list|(
cast|reinterpret_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
argument_list|,
name|nitems
operator|*
sizeof|sizeof
argument_list|(
name|long
argument_list|)
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|nitems
expr_stmt|;
block|}
else|else
name|after
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|data
condition|)
name|XFree
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
comment|// compute nitems
name|QByteArray
name|buffer
argument_list|(
name|ts
operator|.
name|buffer
argument_list|()
argument_list|)
decl_stmt|;
name|nitems
operator|=
name|buffer
operator|.
name|size
argument_list|()
operator|/
sizeof|sizeof
argument_list|(
name|Atom
argument_list|)
expr_stmt|;
name|m_supportedAtoms
operator|=
operator|new
name|Atom
index|[
name|nitems
operator|+
literal|1
index|]
expr_stmt|;
name|Atom
modifier|*
name|a
init|=
operator|(
name|Atom
operator|*
operator|)
name|buffer
operator|.
name|data
argument_list|()
decl_stmt|;
name|uint
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nitems
condition|;
name|i
operator|++
control|)
name|m_supportedAtoms
index|[
name|i
index|]
operator|=
name|a
index|[
name|i
index|]
expr_stmt|;
name|m_supportedAtoms
index|[
name|nitems
index|]
operator|=
literal|0
expr_stmt|;
block|}
block|}
DECL|function|resolveXFixes
name|void
name|resolveXFixes
parameter_list|(
name|QXlibScreen
modifier|*
name|screen
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_XFIXES
comment|// See if Xfixes is supported on the connected display
if|if
condition|(
name|XQueryExtension
argument_list|(
name|screen
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
literal|"XFIXES"
argument_list|,
operator|&
name|xfixes_major
argument_list|,
operator|&
name|xfixes_eventbase
argument_list|,
operator|&
name|xfixes_errorbase
argument_list|)
condition|)
block|{
name|ptrXFixesQueryExtension
operator|=
name|XFIXES_LOAD_V1
argument_list|(
name|XFixesQueryExtension
argument_list|)
expr_stmt|;
name|ptrXFixesQueryVersion
operator|=
name|XFIXES_LOAD_V1
argument_list|(
name|XFixesQueryVersion
argument_list|)
expr_stmt|;
name|ptrXFixesSetCursorName
operator|=
name|XFIXES_LOAD_V2
argument_list|(
name|XFixesSetCursorName
argument_list|)
expr_stmt|;
name|ptrXFixesSelectSelectionInput
operator|=
name|XFIXES_LOAD_V2
argument_list|(
name|XFixesSelectSelectionInput
argument_list|)
expr_stmt|;
if|if
condition|(
name|ptrXFixesQueryExtension
operator|&&
name|ptrXFixesQueryVersion
operator|&&
name|ptrXFixesQueryExtension
argument_list|(
name|screen
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
operator|&
name|xfixes_eventbase
argument_list|,
operator|&
name|xfixes_errorbase
argument_list|)
condition|)
block|{
comment|// Xfixes is supported.
comment|// Note: the XFixes protocol version is negotiated using QueryVersion.
comment|// We supply the highest version we support, the X server replies with
comment|// the highest version it supports, but no higher than the version we
comment|// asked for. The version sent back is the protocol version the X server
comment|// will use to talk us. If this call is removed, the behavior of the
comment|// X server when it receives an XFixes request is undefined.
name|int
name|major
init|=
literal|3
decl_stmt|;
name|int
name|minor
init|=
literal|0
decl_stmt|;
name|ptrXFixesQueryVersion
argument_list|(
name|screen
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
expr_stmt|;
name|use_xfixes
operator|=
operator|(
name|major
operator|>=
literal|1
operator|)
expr_stmt|;
name|xfixes_major
operator|=
name|major
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|// QT_NO_XFIXES
block|}
DECL|member|m_supportedAtoms
name|Atom
modifier|*
name|m_supportedAtoms
decl_stmt|;
DECL|member|m_allAtoms
name|Atom
name|m_allAtoms
index|[
name|QXlibStatic
operator|::
name|NAtoms
index|]
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_XFIXES
DECL|member|ptrXFixesQueryExtension
name|PtrXFixesQueryExtension
name|ptrXFixesQueryExtension
decl_stmt|;
DECL|member|ptrXFixesQueryVersion
name|PtrXFixesQueryVersion
name|ptrXFixesQueryVersion
decl_stmt|;
DECL|member|ptrXFixesSetCursorName
name|PtrXFixesSetCursorName
name|ptrXFixesSetCursorName
decl_stmt|;
DECL|member|ptrXFixesSelectSelectionInput
name|PtrXFixesSelectSelectionInput
name|ptrXFixesSelectSelectionInput
decl_stmt|;
endif|#
directive|endif
DECL|member|use_xfixes
name|bool
name|use_xfixes
decl_stmt|;
DECL|member|xfixes_major
name|int
name|xfixes_major
decl_stmt|;
DECL|member|xfixes_eventbase
name|int
name|xfixes_eventbase
decl_stmt|;
DECL|member|xfixes_errorbase
name|int
name|xfixes_errorbase
decl_stmt|;
block|}
class|;
end_class
begin_expr_stmt
name|Q_GLOBAL_STATIC
argument_list|(
name|QTestLiteStaticInfoPrivate
argument_list|,
name|qTestLiteStaticInfoPrivate
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|atom
name|Atom
name|QXlibStatic
operator|::
name|atom
parameter_list|(
name|QXlibStatic
operator|::
name|X11Atom
name|atom
parameter_list|)
block|{
return|return
name|qTestLiteStaticInfoPrivate
argument_list|()
operator|->
name|atom
argument_list|(
name|atom
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isSupportedByWM
name|bool
name|QXlibStatic
operator|::
name|isSupportedByWM
parameter_list|(
name|Atom
name|atom
parameter_list|)
block|{
return|return
name|qTestLiteStaticInfoPrivate
argument_list|()
operator|->
name|isSupportedByWM
argument_list|(
name|atom
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|useXFixes
name|bool
name|QXlibStatic
operator|::
name|useXFixes
parameter_list|()
block|{
return|return
name|qTestLiteStaticInfoPrivate
argument_list|()
operator|->
name|useXFixes
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|xFixesEventBase
name|int
name|QXlibStatic
operator|::
name|xFixesEventBase
parameter_list|()
block|{
return|return
name|qTestLiteStaticInfoPrivate
argument_list|()
operator|->
name|xFixesEventBase
argument_list|()
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XFIXES
end_ifndef
begin_function
DECL|function|xFixesSelectSelectionInput
name|PtrXFixesSelectSelectionInput
name|QXlibStatic
operator|::
name|xFixesSelectSelectionInput
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
name|qTestLiteStaticInfoPrivate
argument_list|()
operator|->
name|useXFixes
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|qTestLiteStaticInfoPrivate
argument_list|()
operator|->
name|useXFixes
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|qTestLiteStaticInfoPrivate
argument_list|()
operator|->
name|xFixesSelectSelectionInput
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|qimageFromXImage
name|QImage
name|QXlibStatic
operator|::
name|qimageFromXImage
parameter_list|(
name|XImage
modifier|*
name|xi
parameter_list|)
block|{
return|return
name|qTestLiteStaticInfoPrivate
argument_list|()
operator|->
name|qimageFromXImage
argument_list|(
name|xi
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_XFIXES
end_comment
end_unit
