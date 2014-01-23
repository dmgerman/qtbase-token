begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbxsettings.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<X11/extensions/XIproto.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/* Implementation of http://standards.freedesktop.org/xsettings-spec/xsettings-0.5.html */
DECL|enum|XSettingsType
name|enum
name|XSettingsType
argument_list|{
DECL|enumerator|XSettingsTypeInteger
name|XSettingsTypeInteger
operator|=
literal|0
argument_list|,
DECL|enumerator|XSettingsTypeString
name|XSettingsTypeString
operator|=
literal|1
argument_list|,
DECL|enumerator|XSettingsTypeColor
name|XSettingsTypeColor
operator|=
literal|2
argument_list|}
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|QXcbXSettingsCallback
class|class
name|QXcbXSettingsCallback
block|{
public|public:
DECL|member|func
name|QXcbXSettings
operator|::
name|PropertyChangeFunc
name|func
decl_stmt|;
DECL|member|handle
name|void
modifier|*
name|handle
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|QXcbXSettingsPropertyValue
class|class
name|QXcbXSettingsPropertyValue
block|{
public|public:
DECL|function|QXcbXSettingsPropertyValue
name|QXcbXSettingsPropertyValue
parameter_list|()
member_init_list|:
name|last_change_serial
argument_list|(
operator|-
literal|1
argument_list|)
block|{}
DECL|function|updateValue
name|void
name|updateValue
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|,
name|int
name|last_change_serial
parameter_list|)
block|{
if|if
condition|(
name|last_change_serial
operator|<=
name|this
operator|->
name|last_change_serial
condition|)
return|return;
name|this
operator|->
name|value
operator|=
name|value
expr_stmt|;
name|this
operator|->
name|last_change_serial
operator|=
name|last_change_serial
expr_stmt|;
name|QLinkedList
argument_list|<
name|QXcbXSettingsCallback
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|callback_links
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|callback_links
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|it
operator|->
name|func
argument_list|(
name|screen
argument_list|,
name|name
argument_list|,
name|value
argument_list|,
name|it
operator|->
name|handle
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|addCallback
name|void
name|addCallback
parameter_list|(
name|QXcbXSettings
operator|::
name|PropertyChangeFunc
name|func
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|QXcbXSettingsCallback
name|callback
decl_stmt|;
name|callback
operator|.
name|func
operator|=
name|func
expr_stmt|;
name|callback
operator|.
name|handle
operator|=
name|handle
expr_stmt|;
name|callback_links
operator|.
name|append
argument_list|(
name|callback
argument_list|)
expr_stmt|;
block|}
DECL|member|value
name|QVariant
name|value
decl_stmt|;
DECL|member|last_change_serial
name|int
name|last_change_serial
decl_stmt|;
DECL|member|callback_links
name|QLinkedList
argument_list|<
name|QXcbXSettingsCallback
argument_list|>
name|callback_links
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|QXcbXSettingsPrivate
class|class
name|QXcbXSettingsPrivate
block|{
public|public:
DECL|function|QXcbXSettingsPrivate
name|QXcbXSettingsPrivate
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|screen
argument_list|(
name|screen
argument_list|)
member_init_list|,
name|initialized
argument_list|(
literal|false
argument_list|)
block|{     }
DECL|function|getSettings
name|QByteArray
name|getSettings
parameter_list|()
block|{
name|QXcbConnectionGrabber
name|connectionGrabber
argument_list|(
name|screen
operator|->
name|connection
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|QByteArray
name|settings
decl_stmt|;
name|xcb_atom_t
name|_xsettings_atom
init|=
name|screen
operator|->
name|connection
argument_list|()
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|_XSETTINGS_SETTINGS
argument_list|)
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|xcb_get_property_cookie_t
name|get_prop_cookie
init|=
name|xcb_get_property_unchecked
argument_list|(
name|screen
operator|->
name|xcb_connection
argument_list|()
argument_list|,
literal|false
argument_list|,
name|x_settings_window
argument_list|,
name|_xsettings_atom
argument_list|,
name|_xsettings_atom
argument_list|,
name|offset
operator|/
literal|4
argument_list|,
literal|8192
argument_list|)
decl_stmt|;
name|xcb_get_property_reply_t
modifier|*
name|reply
init|=
name|xcb_get_property_reply
argument_list|(
name|screen
operator|->
name|xcb_connection
argument_list|()
argument_list|,
name|get_prop_cookie
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|bool
name|more
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|reply
condition|)
return|return
name|settings
return|;
name|settings
operator|+=
name|QByteArray
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|xcb_get_property_value
argument_list|(
name|reply
argument_list|)
argument_list|,
name|xcb_get_property_value_length
argument_list|(
name|reply
argument_list|)
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|xcb_get_property_value_length
argument_list|(
name|reply
argument_list|)
expr_stmt|;
name|more
operator|=
name|reply
operator|->
name|bytes_after
operator|!=
literal|0
expr_stmt|;
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|more
condition|)
break|break;
block|}
return|return
name|settings
return|;
block|}
DECL|function|round_to_nearest_multiple_of_4
specifier|static
name|int
name|round_to_nearest_multiple_of_4
parameter_list|(
name|int
name|value
parameter_list|)
block|{
name|int
name|remainder
init|=
name|value
operator|%
literal|4
decl_stmt|;
if|if
condition|(
operator|!
name|remainder
condition|)
return|return
name|value
return|;
return|return
name|value
operator|+
literal|4
operator|-
name|remainder
return|;
block|}
DECL|function|populateSettings
name|void
name|populateSettings
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|xSettings
parameter_list|)
block|{
if|if
condition|(
name|xSettings
operator|.
name|length
argument_list|()
operator|<
literal|12
condition|)
return|return;
comment|// we ignore byteorder for now
name|char
name|byteOrder
init|=
name|xSettings
operator|.
name|at
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|byteOrder
argument_list|)
expr_stmt|;
name|uint
name|number_of_settings
init|=
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|uint
operator|*
argument_list|>
argument_list|(
name|xSettings
operator|.
name|mid
argument_list|(
literal|8
argument_list|,
literal|4
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|data
init|=
name|xSettings
operator|.
name|constData
argument_list|()
operator|+
literal|12
decl_stmt|;
name|size_t
name|offset
init|=
literal|0
decl_stmt|;
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
name|number_of_settings
condition|;
name|i
operator|++
control|)
block|{
name|int
name|local_offset
init|=
literal|0
decl_stmt|;
name|XSettingsType
name|type
init|=
cast|static_cast
argument_list|<
name|XSettingsType
argument_list|>
argument_list|(
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint8
operator|*
argument_list|>
argument_list|(
name|data
operator|+
name|offset
argument_list|)
argument_list|)
decl_stmt|;
name|local_offset
operator|+=
literal|2
expr_stmt|;
name|quint16
name|name_len
init|=
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint16
operator|*
argument_list|>
argument_list|(
name|data
operator|+
name|offset
operator|+
name|local_offset
argument_list|)
decl_stmt|;
name|local_offset
operator|+=
literal|2
expr_stmt|;
name|QByteArray
name|name
argument_list|(
name|data
operator|+
name|offset
operator|+
name|local_offset
argument_list|,
name|name_len
argument_list|)
decl_stmt|;
name|local_offset
operator|+=
name|round_to_nearest_multiple_of_4
argument_list|(
name|name_len
argument_list|)
expr_stmt|;
name|int
name|last_change_serial
init|=
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|int
operator|*
argument_list|>
argument_list|(
name|data
operator|+
name|offset
operator|+
name|local_offset
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|last_change_serial
argument_list|)
expr_stmt|;
name|local_offset
operator|+=
literal|4
expr_stmt|;
name|QVariant
name|value
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|XSettingsTypeString
condition|)
block|{
name|int
name|value_length
init|=
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|int
operator|*
argument_list|>
argument_list|(
name|data
operator|+
name|offset
operator|+
name|local_offset
argument_list|)
decl_stmt|;
name|local_offset
operator|+=
literal|4
expr_stmt|;
name|QByteArray
name|value_string
argument_list|(
name|data
operator|+
name|offset
operator|+
name|local_offset
argument_list|,
name|value_length
argument_list|)
decl_stmt|;
name|value
operator|.
name|setValue
argument_list|(
name|value_string
argument_list|)
expr_stmt|;
name|local_offset
operator|+=
name|round_to_nearest_multiple_of_4
argument_list|(
name|value_length
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|XSettingsTypeInteger
condition|)
block|{
name|int
name|value_length
init|=
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|int
operator|*
argument_list|>
argument_list|(
name|data
operator|+
name|offset
operator|+
name|local_offset
argument_list|)
decl_stmt|;
name|local_offset
operator|+=
literal|4
expr_stmt|;
name|value
operator|.
name|setValue
argument_list|(
name|value_length
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|XSettingsTypeColor
condition|)
block|{
name|quint16
name|red
init|=
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint16
operator|*
argument_list|>
argument_list|(
name|data
operator|+
name|offset
operator|+
name|local_offset
argument_list|)
decl_stmt|;
name|local_offset
operator|+=
literal|2
expr_stmt|;
name|quint16
name|green
init|=
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint16
operator|*
argument_list|>
argument_list|(
name|data
operator|+
name|offset
operator|+
name|local_offset
argument_list|)
decl_stmt|;
name|local_offset
operator|+=
literal|2
expr_stmt|;
name|quint16
name|blue
init|=
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint16
operator|*
argument_list|>
argument_list|(
name|data
operator|+
name|offset
operator|+
name|local_offset
argument_list|)
decl_stmt|;
name|local_offset
operator|+=
literal|2
expr_stmt|;
name|quint16
name|alpha
init|=
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint16
operator|*
argument_list|>
argument_list|(
name|data
operator|+
name|offset
operator|+
name|local_offset
argument_list|)
decl_stmt|;
name|local_offset
operator|+=
literal|2
expr_stmt|;
name|QColor
name|color_value
argument_list|(
name|red
argument_list|,
name|green
argument_list|,
name|blue
argument_list|,
name|alpha
argument_list|)
decl_stmt|;
name|value
operator|.
name|setValue
argument_list|(
name|color_value
argument_list|)
expr_stmt|;
block|}
name|offset
operator|+=
name|local_offset
expr_stmt|;
name|settings
index|[
name|name
index|]
operator|.
name|updateValue
argument_list|(
name|screen
argument_list|,
name|name
argument_list|,
name|value
argument_list|,
name|last_change_serial
argument_list|)
expr_stmt|;
block|}
block|}
DECL|member|screen
name|QXcbScreen
modifier|*
name|screen
decl_stmt|;
DECL|member|x_settings_window
name|xcb_window_t
name|x_settings_window
decl_stmt|;
DECL|member|settings
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QXcbXSettingsPropertyValue
argument_list|>
name|settings
decl_stmt|;
DECL|member|initialized
name|bool
name|initialized
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QXcbXSettings
name|QXcbXSettings
operator|::
name|QXcbXSettings
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QXcbXSettingsPrivate
argument_list|(
name|screen
argument_list|)
argument_list|)
block|{
name|QByteArray
name|settings_atom_for_screen
argument_list|(
literal|"_XSETTINGS_S"
argument_list|)
decl_stmt|;
name|settings_atom_for_screen
operator|.
name|append
argument_list|(
name|QByteArray
operator|::
name|number
argument_list|(
name|screen
operator|->
name|screenNumber
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|xcb_intern_atom_cookie_t
name|atom_cookie
init|=
name|xcb_intern_atom
argument_list|(
name|screen
operator|->
name|xcb_connection
argument_list|()
argument_list|,
literal|true
argument_list|,
name|settings_atom_for_screen
operator|.
name|length
argument_list|()
argument_list|,
name|settings_atom_for_screen
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
name|xcb_generic_error_t
modifier|*
name|error
init|=
literal|0
decl_stmt|;
name|xcb_intern_atom_reply_t
modifier|*
name|atom_reply
init|=
name|xcb_intern_atom_reply
argument_list|(
name|screen
operator|->
name|xcb_connection
argument_list|()
argument_list|,
name|atom_cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return;
block|}
name|xcb_atom_t
name|selection_owner_atom
init|=
name|atom_reply
operator|->
name|atom
decl_stmt|;
name|free
argument_list|(
name|atom_reply
argument_list|)
expr_stmt|;
name|xcb_get_selection_owner_cookie_t
name|selection_cookie
init|=
name|xcb_get_selection_owner
argument_list|(
name|screen
operator|->
name|xcb_connection
argument_list|()
argument_list|,
name|selection_owner_atom
argument_list|)
decl_stmt|;
name|xcb_get_selection_owner_reply_t
modifier|*
name|selection_result
init|=
name|xcb_get_selection_owner_reply
argument_list|(
name|screen
operator|->
name|xcb_connection
argument_list|()
argument_list|,
name|selection_cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return;
block|}
name|d_ptr
operator|->
name|x_settings_window
operator|=
name|selection_result
operator|->
name|owner
expr_stmt|;
name|free
argument_list|(
name|selection_result
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d_ptr
operator|->
name|x_settings_window
condition|)
block|{
return|return;
block|}
specifier|const
name|uint32_t
name|event
init|=
name|XCB_CW_EVENT_MASK
decl_stmt|;
specifier|const
name|uint32_t
name|event_mask
index|[]
init|=
block|{
name|XCB_EVENT_MASK_STRUCTURE_NOTIFY
operator||
name|XCB_EVENT_MASK_PROPERTY_CHANGE
block|}
decl_stmt|;
name|xcb_change_window_attributes
argument_list|(
name|screen
operator|->
name|xcb_connection
argument_list|()
argument_list|,
name|d_ptr
operator|->
name|x_settings_window
argument_list|,
name|event
argument_list|,
name|event_mask
argument_list|)
expr_stmt|;
name|d_ptr
operator|->
name|populateSettings
argument_list|(
name|d_ptr
operator|->
name|getSettings
argument_list|()
argument_list|)
expr_stmt|;
name|d_ptr
operator|->
name|initialized
operator|=
literal|true
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|initialized
name|bool
name|QXcbXSettings
operator|::
name|initialized
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QXcbXSettings
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|initialized
return|;
block|}
end_function
begin_function
DECL|function|handlePropertyNotifyEvent
name|void
name|QXcbXSettings
operator|::
name|handlePropertyNotifyEvent
parameter_list|(
specifier|const
name|xcb_property_notify_event_t
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QXcbXSettings
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|window
operator|!=
name|d
operator|->
name|x_settings_window
condition|)
return|return;
name|d
operator|->
name|populateSettings
argument_list|(
name|d
operator|->
name|getSettings
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|registerCallbackForProperty
name|void
name|QXcbXSettings
operator|::
name|registerCallbackForProperty
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|property
parameter_list|,
name|QXcbXSettings
operator|::
name|PropertyChangeFunc
name|func
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QXcbXSettings
argument_list|)
expr_stmt|;
name|d
operator|->
name|settings
index|[
name|property
index|]
operator|.
name|addCallback
argument_list|(
name|func
argument_list|,
name|handle
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeCallbackForHandle
name|void
name|QXcbXSettings
operator|::
name|removeCallbackForHandle
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|property
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QXcbXSettings
argument_list|)
expr_stmt|;
name|QXcbXSettingsPropertyValue
modifier|&
name|value
init|=
name|d
operator|->
name|settings
index|[
name|property
index|]
decl_stmt|;
name|QLinkedList
argument_list|<
name|QXcbXSettingsCallback
argument_list|>
operator|::
name|iterator
name|it
init|=
name|value
operator|.
name|callback_links
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|value
operator|.
name|callback_links
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|it
operator|->
name|handle
operator|==
name|handle
condition|)
name|it
operator|=
name|value
operator|.
name|callback_links
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
else|else
operator|++
name|it
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|removeCallbackForHandle
name|void
name|QXcbXSettings
operator|::
name|removeCallbackForHandle
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QXcbXSettings
argument_list|)
expr_stmt|;
for|for
control|(
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QXcbXSettingsPropertyValue
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|d
operator|->
name|settings
operator|.
name|cbegin
argument_list|()
init|;
name|it
operator|!=
name|d
operator|->
name|settings
operator|.
name|cend
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|removeCallbackForHandle
argument_list|(
name|it
operator|.
name|key
argument_list|()
argument_list|,
name|handle
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setting
name|QVariant
name|QXcbXSettings
operator|::
name|setting
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|property
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QXcbXSettings
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|settings
operator|.
name|value
argument_list|(
name|property
argument_list|)
operator|.
name|value
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
