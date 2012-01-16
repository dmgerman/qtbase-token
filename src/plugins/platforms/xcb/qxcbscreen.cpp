begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
file|"qxcbimage.h"
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QXcbScreen
name|QXcbScreen
operator|::
name|QXcbScreen
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|,
name|xcb_screen_t
modifier|*
name|screen
parameter_list|,
name|int
name|number
parameter_list|)
member_init_list|:
name|QXcbObject
argument_list|(
name|connection
argument_list|)
member_init_list|,
name|m_screen
argument_list|(
name|screen
argument_list|)
member_init_list|,
name|m_number
argument_list|(
name|number
argument_list|)
block|{
name|qDebug
argument_list|()
expr_stmt|;
name|qDebug
argument_list|(
literal|"Information of screen %d:"
argument_list|,
name|screen
operator|->
name|root
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"  width.........: %d"
argument_list|,
name|screen
operator|->
name|width_in_pixels
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"  height........: %d"
argument_list|,
name|screen
operator|->
name|height_in_pixels
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"  depth.........: %d"
argument_list|,
name|screen
operator|->
name|root_depth
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"  white pixel...: %x"
argument_list|,
name|screen
operator|->
name|white_pixel
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"  black pixel...: %x"
argument_list|,
name|screen
operator|->
name|black_pixel
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
expr_stmt|;
specifier|const
name|quint32
name|mask
init|=
name|XCB_CW_EVENT_MASK
decl_stmt|;
specifier|const
name|quint32
name|values
index|[]
init|=
block|{
comment|// XCB_CW_EVENT_MASK
name|XCB_EVENT_MASK_ENTER_WINDOW
operator||
name|XCB_EVENT_MASK_LEAVE_WINDOW
operator||
name|XCB_EVENT_MASK_PROPERTY_CHANGE
block|}
decl_stmt|;
name|xcb_change_window_attributes
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|screen
operator|->
name|root
argument_list|,
name|mask
argument_list|,
name|values
argument_list|)
expr_stmt|;
name|xcb_generic_error_t
modifier|*
name|error
decl_stmt|;
name|xcb_get_property_reply_t
modifier|*
name|reply
init|=
name|xcb_get_property_reply
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|xcb_get_property
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
literal|false
argument_list|,
name|screen
operator|->
name|root
argument_list|,
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|_NET_SUPPORTING_WM_CHECK
argument_list|)
argument_list|,
name|XCB_ATOM_WINDOW
argument_list|,
literal|0
argument_list|,
literal|1024
argument_list|)
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
name|reply
operator|&&
name|reply
operator|->
name|format
operator|==
literal|32
operator|&&
name|reply
operator|->
name|type
operator|==
name|XCB_ATOM_WINDOW
condition|)
block|{
name|xcb_window_t
name|windowManager
init|=
operator|*
operator|(
operator|(
name|xcb_window_t
operator|*
operator|)
name|xcb_get_property_value
argument_list|(
name|reply
argument_list|)
operator|)
decl_stmt|;
if|if
condition|(
name|windowManager
operator|!=
name|XCB_WINDOW_NONE
condition|)
block|{
name|xcb_get_property_reply_t
modifier|*
name|windowManagerReply
init|=
name|xcb_get_property_reply
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|xcb_get_property
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
literal|false
argument_list|,
name|windowManager
argument_list|,
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|_NET_WM_NAME
argument_list|)
argument_list|,
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|UTF8_STRING
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|1024
argument_list|)
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
name|windowManagerReply
operator|&&
name|windowManagerReply
operator|->
name|format
operator|==
literal|8
operator|&&
name|windowManagerReply
operator|->
name|type
operator|==
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|UTF8_STRING
argument_list|)
condition|)
block|{
name|m_windowManagerName
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|xcb_get_property_value
argument_list|(
name|windowManagerReply
argument_list|)
argument_list|,
name|xcb_get_property_value_length
argument_list|(
name|windowManagerReply
argument_list|)
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"Running window manager: %s"
argument_list|,
name|qPrintable
argument_list|(
name|m_windowManagerName
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|error
condition|)
block|{
name|connection
operator|->
name|handleXcbError
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|windowManagerReply
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|error
condition|)
block|{
name|connection
operator|->
name|handleXcbError
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
name|m_syncRequestSupported
operator|=
name|m_windowManagerName
operator|!=
name|QLatin1String
argument_list|(
literal|"KWin"
argument_list|)
expr_stmt|;
name|m_clientLeader
operator|=
name|xcb_generate_id
argument_list|(
name|xcb_connection
argument_list|()
argument_list|)
expr_stmt|;
name|Q_XCB_CALL2
argument_list|(
name|xcb_create_window
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|XCB_COPY_FROM_PARENT
argument_list|,
name|m_clientLeader
argument_list|,
name|m_screen
operator|->
name|root
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
name|XCB_WINDOW_CLASS_INPUT_OUTPUT
argument_list|,
name|m_screen
operator|->
name|root_visual
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|connection
argument_list|)
expr_stmt|;
name|Q_XCB_CALL2
argument_list|(
name|xcb_change_property
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|XCB_PROP_MODE_REPLACE
argument_list|,
name|m_clientLeader
argument_list|,
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|WM_CLIENT_LEADER
argument_list|)
argument_list|,
name|XCB_ATOM_WINDOW
argument_list|,
literal|32
argument_list|,
literal|1
argument_list|,
operator|&
name|m_clientLeader
argument_list|)
argument_list|,
name|connection
argument_list|)
expr_stmt|;
name|xcb_depth_iterator_t
name|depth_iterator
init|=
name|xcb_screen_allowed_depths_iterator
argument_list|(
name|screen
argument_list|)
decl_stmt|;
while|while
condition|(
name|depth_iterator
operator|.
name|rem
condition|)
block|{
name|xcb_depth_t
modifier|*
name|depth
init|=
name|depth_iterator
operator|.
name|data
decl_stmt|;
name|xcb_visualtype_iterator_t
name|visualtype_iterator
init|=
name|xcb_depth_visuals_iterator
argument_list|(
name|depth
argument_list|)
decl_stmt|;
while|while
condition|(
name|visualtype_iterator
operator|.
name|rem
condition|)
block|{
name|xcb_visualtype_t
modifier|*
name|visualtype
init|=
name|visualtype_iterator
operator|.
name|data
decl_stmt|;
name|m_visuals
operator|.
name|insert
argument_list|(
name|visualtype
operator|->
name|visual_id
argument_list|,
operator|*
name|visualtype
argument_list|)
expr_stmt|;
name|xcb_visualtype_next
argument_list|(
operator|&
name|visualtype_iterator
argument_list|)
expr_stmt|;
block|}
name|xcb_depth_next
argument_list|(
operator|&
name|depth_iterator
argument_list|)
expr_stmt|;
block|}
name|m_cursor
operator|=
operator|new
name|QXcbCursor
argument_list|(
name|connection
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QXcbScreen
name|QXcbScreen
operator|::
name|~
name|QXcbScreen
parameter_list|()
block|{
operator|delete
name|m_cursor
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|topLevelAt
name|QWindow
modifier|*
name|QXcbScreen
operator|::
name|topLevelAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
specifier|const
block|{
name|xcb_window_t
name|root
init|=
name|m_screen
operator|->
name|root
decl_stmt|;
name|int
name|x
init|=
name|p
operator|.
name|x
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|p
operator|.
name|y
argument_list|()
decl_stmt|;
name|xcb_generic_error_t
modifier|*
name|error
decl_stmt|;
name|xcb_window_t
name|parent
init|=
name|root
decl_stmt|;
name|xcb_window_t
name|child
init|=
name|root
decl_stmt|;
do|do
block|{
name|xcb_translate_coordinates_cookie_t
name|translate_cookie
init|=
name|xcb_translate_coordinates
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|parent
argument_list|,
name|child
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|xcb_translate_coordinates_reply_t
modifier|*
name|translate_reply
init|=
name|xcb_translate_coordinates_reply
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|translate_cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|translate_reply
condition|)
block|{
if|if
condition|(
name|error
condition|)
block|{
name|connection
argument_list|()
operator|->
name|handleXcbError
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
name|parent
operator|=
name|child
expr_stmt|;
name|child
operator|=
name|translate_reply
operator|->
name|child
expr_stmt|;
name|x
operator|=
name|translate_reply
operator|->
name|dst_x
expr_stmt|;
name|y
operator|=
name|translate_reply
operator|->
name|dst_y
expr_stmt|;
name|free
argument_list|(
name|translate_reply
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|child
operator|||
name|child
operator|==
name|root
condition|)
return|return
literal|0
return|;
name|QPlatformWindow
modifier|*
name|platformWindow
init|=
name|connection
argument_list|()
operator|->
name|platformWindowFromId
argument_list|(
name|child
argument_list|)
decl_stmt|;
if|if
condition|(
name|platformWindow
condition|)
return|return
name|platformWindow
operator|->
name|window
argument_list|()
return|;
block|}
do|while
condition|(
name|parent
operator|!=
name|child
condition|)
do|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|visualForId
specifier|const
name|xcb_visualtype_t
modifier|*
name|QXcbScreen
operator|::
name|visualForId
parameter_list|(
name|xcb_visualid_t
name|visualid
parameter_list|)
specifier|const
block|{
name|QMap
argument_list|<
name|xcb_visualid_t
argument_list|,
name|xcb_visualtype_t
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|m_visuals
operator|.
name|find
argument_list|(
name|visualid
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|m_visuals
operator|.
name|constEnd
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
operator|&
operator|*
name|it
return|;
block|}
end_function
begin_function
DECL|function|geometry
name|QRect
name|QXcbScreen
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
return|return
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_screen
operator|->
name|width_in_pixels
argument_list|,
name|m_screen
operator|->
name|height_in_pixels
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QXcbScreen
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
name|m_screen
operator|->
name|root_depth
return|;
block|}
end_function
begin_function
DECL|function|format
name|QImage
operator|::
name|Format
name|QXcbScreen
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|QImage
operator|::
name|Format_RGB32
return|;
block|}
end_function
begin_function
DECL|function|physicalSize
name|QSizeF
name|QXcbScreen
operator|::
name|physicalSize
parameter_list|()
specifier|const
block|{
return|return
name|QSizeF
argument_list|(
name|m_screen
operator|->
name|width_in_millimeters
argument_list|,
name|m_screen
operator|->
name|height_in_millimeters
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|screenNumber
name|int
name|QXcbScreen
operator|::
name|screenNumber
parameter_list|()
specifier|const
block|{
return|return
name|m_number
return|;
block|}
end_function
begin_function
DECL|function|grabWindow
name|QPixmap
name|QXcbScreen
operator|::
name|grabWindow
parameter_list|(
name|WId
name|window
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|width
operator|==
literal|0
operator|||
name|height
operator|==
literal|0
condition|)
return|return
name|QPixmap
argument_list|()
return|;
name|xcb_get_geometry_cookie_t
name|geometry_cookie
init|=
name|xcb_get_geometry
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|xcb_generic_error_t
modifier|*
name|error
decl_stmt|;
name|xcb_get_geometry_reply_t
modifier|*
name|reply
init|=
name|xcb_get_geometry_reply
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|geometry_cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reply
condition|)
block|{
if|if
condition|(
name|error
condition|)
block|{
name|connection
argument_list|()
operator|->
name|handleXcbError
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
block|}
return|return
name|QPixmap
argument_list|()
return|;
block|}
if|if
condition|(
name|width
operator|<
literal|0
condition|)
name|width
operator|=
name|reply
operator|->
name|width
operator|-
name|x
expr_stmt|;
if|if
condition|(
name|height
operator|<
literal|0
condition|)
name|height
operator|=
name|reply
operator|->
name|height
operator|-
name|y
expr_stmt|;
comment|// TODO: handle multiple screens
name|QXcbScreen
modifier|*
name|screen
init|=
cast|const_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|xcb_window_t
name|root
init|=
name|screen
operator|->
name|root
argument_list|()
decl_stmt|;
name|geometry_cookie
operator|=
name|xcb_get_geometry
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|root
argument_list|)
expr_stmt|;
name|xcb_get_geometry_reply_t
modifier|*
name|root_reply
init|=
name|xcb_get_geometry_reply
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|geometry_cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|root_reply
condition|)
block|{
if|if
condition|(
name|error
condition|)
block|{
name|connection
argument_list|()
operator|->
name|handleXcbError
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
if|if
condition|(
name|reply
operator|->
name|depth
operator|==
name|root_reply
operator|->
name|depth
condition|)
block|{
comment|// if the depth of the specified window and the root window are the
comment|// same, grab pixels from the root window (so that we get the any
comment|// overlapping windows and window manager frames)
comment|// map x and y to the root window
name|xcb_translate_coordinates_cookie_t
name|translate_cookie
init|=
name|xcb_translate_coordinates
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|window
argument_list|,
name|root
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|xcb_translate_coordinates_reply_t
modifier|*
name|translate_reply
init|=
name|xcb_translate_coordinates_reply
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|translate_cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|translate_reply
condition|)
block|{
if|if
condition|(
name|error
condition|)
block|{
name|connection
argument_list|()
operator|->
name|handleXcbError
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|root_reply
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
name|x
operator|=
name|translate_reply
operator|->
name|dst_x
expr_stmt|;
name|y
operator|=
name|translate_reply
operator|->
name|dst_y
expr_stmt|;
name|window
operator|=
name|root
expr_stmt|;
name|free
argument_list|(
name|translate_reply
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
name|reply
operator|=
name|root_reply
expr_stmt|;
block|}
else|else
block|{
name|free
argument_list|(
name|root_reply
argument_list|)
expr_stmt|;
name|root_reply
operator|=
literal|0
expr_stmt|;
block|}
name|xcb_get_window_attributes_reply_t
modifier|*
name|attributes_reply
init|=
name|xcb_get_window_attributes_reply
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|xcb_get_window_attributes
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|window
argument_list|)
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|attributes_reply
condition|)
block|{
if|if
condition|(
name|error
condition|)
block|{
name|connection
argument_list|()
operator|->
name|handleXcbError
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
specifier|const
name|xcb_visualtype_t
modifier|*
name|visual
init|=
name|screen
operator|->
name|visualForId
argument_list|(
name|attributes_reply
operator|->
name|visual
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|attributes_reply
argument_list|)
expr_stmt|;
name|xcb_pixmap_t
name|pixmap
init|=
name|xcb_generate_id
argument_list|(
name|xcb_connection
argument_list|()
argument_list|)
decl_stmt|;
name|error
operator|=
name|xcb_request_check
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|xcb_create_pixmap_checked
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|reply
operator|->
name|depth
argument_list|,
name|pixmap
argument_list|,
name|window
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|connection
argument_list|()
operator|->
name|handleXcbError
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
block|}
name|uint32_t
name|gc_value_mask
init|=
name|XCB_GC_SUBWINDOW_MODE
decl_stmt|;
name|uint32_t
name|gc_value_list
index|[]
init|=
block|{
name|XCB_SUBWINDOW_MODE_INCLUDE_INFERIORS
block|}
decl_stmt|;
name|xcb_gcontext_t
name|gc
init|=
name|xcb_generate_id
argument_list|(
name|xcb_connection
argument_list|()
argument_list|)
decl_stmt|;
name|xcb_create_gc
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|gc
argument_list|,
name|pixmap
argument_list|,
name|gc_value_mask
argument_list|,
name|gc_value_list
argument_list|)
expr_stmt|;
name|error
operator|=
name|xcb_request_check
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|xcb_copy_area_checked
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|window
argument_list|,
name|pixmap
argument_list|,
name|gc
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|connection
argument_list|()
operator|->
name|handleXcbError
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
block|}
name|QPixmap
name|result
init|=
name|qt_xcb_pixmapFromXPixmap
argument_list|(
name|connection
argument_list|()
argument_list|,
name|pixmap
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|reply
operator|->
name|depth
argument_list|,
name|visual
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
name|xcb_free_gc
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|gc
argument_list|)
expr_stmt|;
name|xcb_free_pixmap
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|name
name|QString
name|QXcbScreen
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|connection
argument_list|()
operator|->
name|displayName
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|screenNumber
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
