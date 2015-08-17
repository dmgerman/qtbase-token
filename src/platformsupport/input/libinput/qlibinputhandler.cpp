begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlibinputhandler_p.h"
end_include
begin_include
include|#
directive|include
file|"qlibinputpointer_p.h"
end_include
begin_include
include|#
directive|include
file|"qlibinputkeyboard_p.h"
end_include
begin_include
include|#
directive|include
file|"qlibinputtouch_p.h"
end_include
begin_include
include|#
directive|include
file|<libudev.h>
end_include
begin_include
include|#
directive|include
file|<libinput.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qcore_unix_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qinputdevicemanager_p_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|qLcLibInput
argument_list|,
literal|"qt.qpa.input"
argument_list|)
decl|static
DECL|function|liOpen
name|int
name|liOpen
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|int
name|flags
argument_list|,
name|void
operator|*
name|user_data
argument_list|)
argument_list|{
name|Q_UNUSED
argument_list|(
name|user_data
argument_list|)
argument_list|;     return
name|qt_safe_open
argument_list|(
name|path
argument_list|,
name|flags
argument_list|)
argument_list|; }
decl|static
DECL|function|liClose
name|void
name|liClose
argument_list|(
name|int
name|fd
argument_list|,
name|void
operator|*
name|user_data
argument_list|)
argument_list|{
name|Q_UNUSED
argument_list|(
name|user_data
argument_list|)
argument_list|;
name|qt_safe_close
argument_list|(
name|fd
argument_list|)
argument_list|; }
decl|static const struct
DECL|variable|liInterface
name|libinput_interface
name|liInterface
init|=
block|{
name|liOpen
block|,
name|liClose
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|liLogHandler
specifier|static
name|void
name|liLogHandler
parameter_list|(
name|libinput
modifier|*
name|libinput
parameter_list|,
name|libinput_log_priority
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|libinput
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|priority
argument_list|)
expr_stmt|;
name|char
name|buf
index|[
literal|512
index|]
decl_stmt|;
name|int
name|n
init|=
name|vsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
name|format
argument_list|,
name|args
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|buf
index|[
name|n
operator|-
literal|1
index|]
operator|==
literal|'\n'
condition|)
name|buf
index|[
name|n
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|qCDebug
argument_list|(
name|qLcLibInput
argument_list|,
literal|"libinput: %s"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|QLibInputHandler
name|QLibInputHandler
operator|::
name|QLibInputHandler
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|spec
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|key
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|spec
argument_list|)
expr_stmt|;
name|m_udev
operator|=
name|udev_new
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_udev
condition|)
name|qFatal
argument_list|(
literal|"Failed to get udev context for libinput"
argument_list|)
expr_stmt|;
name|m_li
operator|=
name|libinput_udev_create_context
argument_list|(
operator|&
name|liInterface
argument_list|,
name|Q_NULLPTR
argument_list|,
name|m_udev
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_li
condition|)
name|qFatal
argument_list|(
literal|"Failed to get libinput context"
argument_list|)
expr_stmt|;
name|libinput_log_set_handler
argument_list|(
name|m_li
argument_list|,
name|liLogHandler
argument_list|)
expr_stmt|;
if|if
condition|(
name|qLcLibInput
argument_list|()
operator|.
name|isDebugEnabled
argument_list|()
condition|)
name|libinput_log_set_priority
argument_list|(
name|m_li
argument_list|,
name|LIBINPUT_LOG_PRIORITY_DEBUG
argument_list|)
expr_stmt|;
if|if
condition|(
name|libinput_udev_assign_seat
argument_list|(
name|m_li
argument_list|,
literal|"seat0"
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Failed to assign seat"
argument_list|)
expr_stmt|;
name|m_liFd
operator|=
name|libinput_get_fd
argument_list|(
name|m_li
argument_list|)
expr_stmt|;
name|m_notifier
operator|.
name|reset
argument_list|(
operator|new
name|QSocketNotifier
argument_list|(
name|m_liFd
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_notifier
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|onReadyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_pointer
operator|.
name|reset
argument_list|(
operator|new
name|QLibInputPointer
argument_list|)
expr_stmt|;
name|m_keyboard
operator|.
name|reset
argument_list|(
operator|new
name|QLibInputKeyboard
argument_list|)
expr_stmt|;
name|m_touch
operator|.
name|reset
argument_list|(
operator|new
name|QLibInputTouch
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|inputDeviceManager
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|cursorPositionChangeRequested
argument_list|(
name|QPoint
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onCursorPositionChangeRequested
argument_list|(
name|QPoint
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// Process the initial burst of DEVICE_ADDED events.
name|onReadyRead
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QLibInputHandler
name|QLibInputHandler
operator|::
name|~
name|QLibInputHandler
parameter_list|()
block|{
if|if
condition|(
name|m_li
condition|)
name|libinput_unref
argument_list|(
name|m_li
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_udev
condition|)
name|udev_unref
argument_list|(
name|m_udev
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|onReadyRead
name|void
name|QLibInputHandler
operator|::
name|onReadyRead
parameter_list|()
block|{
if|if
condition|(
name|libinput_dispatch
argument_list|(
name|m_li
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"libinput_dispatch failed"
argument_list|)
expr_stmt|;
return|return;
block|}
name|libinput_event
modifier|*
name|ev
decl_stmt|;
while|while
condition|(
operator|(
name|ev
operator|=
name|libinput_get_event
argument_list|(
name|m_li
argument_list|)
operator|)
operator|!=
name|Q_NULLPTR
condition|)
block|{
name|processEvent
argument_list|(
name|ev
argument_list|)
expr_stmt|;
name|libinput_event_destroy
argument_list|(
name|ev
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|processEvent
name|void
name|QLibInputHandler
operator|::
name|processEvent
parameter_list|(
name|libinput_event
modifier|*
name|ev
parameter_list|)
block|{
name|libinput_event_type
name|type
init|=
name|libinput_event_get_type
argument_list|(
name|ev
argument_list|)
decl_stmt|;
name|libinput_device
modifier|*
name|dev
init|=
name|libinput_event_get_device
argument_list|(
name|ev
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|LIBINPUT_EVENT_DEVICE_ADDED
case|:
block|{
comment|// This is not just for hotplugging, it is also called for each input
comment|// device libinput reads from on startup. Hence it is suitable for doing
comment|// touch device registration.
specifier|const
name|char
modifier|*
name|sysname
init|=
name|libinput_device_get_sysname
argument_list|(
name|dev
argument_list|)
decl_stmt|;
comment|// node name without path
specifier|const
name|char
modifier|*
name|name
init|=
name|libinput_device_get_name
argument_list|(
name|dev
argument_list|)
decl_stmt|;
emit|emit
name|deviceAdded
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|sysname
argument_list|)
argument_list|,
name|QString
operator|::
name|fromUtf8
argument_list|(
name|name
argument_list|)
argument_list|)
emit|;
name|QInputDeviceManagerPrivate
modifier|*
name|inputManagerPriv
init|=
name|QInputDeviceManagerPrivate
operator|::
name|get
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|inputDeviceManager
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|libinput_device_has_capability
argument_list|(
name|dev
argument_list|,
name|LIBINPUT_DEVICE_CAP_TOUCH
argument_list|)
condition|)
block|{
name|m_touch
operator|->
name|registerDevice
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|int
modifier|&
name|count
argument_list|(
name|m_devCount
index|[
name|QInputDeviceManager
operator|::
name|DeviceTypeTouch
index|]
argument_list|)
decl_stmt|;
operator|++
name|count
expr_stmt|;
name|inputManagerPriv
operator|->
name|setDeviceCount
argument_list|(
name|QInputDeviceManager
operator|::
name|DeviceTypeTouch
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|libinput_device_has_capability
argument_list|(
name|dev
argument_list|,
name|LIBINPUT_DEVICE_CAP_POINTER
argument_list|)
condition|)
block|{
name|int
modifier|&
name|count
argument_list|(
name|m_devCount
index|[
name|QInputDeviceManager
operator|::
name|DeviceTypePointer
index|]
argument_list|)
decl_stmt|;
operator|++
name|count
expr_stmt|;
name|inputManagerPriv
operator|->
name|setDeviceCount
argument_list|(
name|QInputDeviceManager
operator|::
name|DeviceTypePointer
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|libinput_device_has_capability
argument_list|(
name|dev
argument_list|,
name|LIBINPUT_DEVICE_CAP_KEYBOARD
argument_list|)
condition|)
block|{
name|int
modifier|&
name|count
argument_list|(
name|m_devCount
index|[
name|QInputDeviceManager
operator|::
name|DeviceTypeKeyboard
index|]
argument_list|)
decl_stmt|;
operator|++
name|count
expr_stmt|;
name|inputManagerPriv
operator|->
name|setDeviceCount
argument_list|(
name|QInputDeviceManager
operator|::
name|DeviceTypeKeyboard
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
case|case
name|LIBINPUT_EVENT_DEVICE_REMOVED
case|:
block|{
specifier|const
name|char
modifier|*
name|sysname
init|=
name|libinput_device_get_sysname
argument_list|(
name|dev
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
init|=
name|libinput_device_get_name
argument_list|(
name|dev
argument_list|)
decl_stmt|;
emit|emit
name|deviceRemoved
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|sysname
argument_list|)
argument_list|,
name|QString
operator|::
name|fromUtf8
argument_list|(
name|name
argument_list|)
argument_list|)
emit|;
name|QInputDeviceManagerPrivate
modifier|*
name|inputManagerPriv
init|=
name|QInputDeviceManagerPrivate
operator|::
name|get
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|inputDeviceManager
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|libinput_device_has_capability
argument_list|(
name|dev
argument_list|,
name|LIBINPUT_DEVICE_CAP_TOUCH
argument_list|)
condition|)
block|{
name|m_touch
operator|->
name|unregisterDevice
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|int
modifier|&
name|count
argument_list|(
name|m_devCount
index|[
name|QInputDeviceManager
operator|::
name|DeviceTypeTouch
index|]
argument_list|)
decl_stmt|;
operator|--
name|count
expr_stmt|;
name|inputManagerPriv
operator|->
name|setDeviceCount
argument_list|(
name|QInputDeviceManager
operator|::
name|DeviceTypeTouch
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|libinput_device_has_capability
argument_list|(
name|dev
argument_list|,
name|LIBINPUT_DEVICE_CAP_POINTER
argument_list|)
condition|)
block|{
name|int
modifier|&
name|count
argument_list|(
name|m_devCount
index|[
name|QInputDeviceManager
operator|::
name|DeviceTypePointer
index|]
argument_list|)
decl_stmt|;
operator|--
name|count
expr_stmt|;
name|inputManagerPriv
operator|->
name|setDeviceCount
argument_list|(
name|QInputDeviceManager
operator|::
name|DeviceTypePointer
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|libinput_device_has_capability
argument_list|(
name|dev
argument_list|,
name|LIBINPUT_DEVICE_CAP_KEYBOARD
argument_list|)
condition|)
block|{
name|int
modifier|&
name|count
argument_list|(
name|m_devCount
index|[
name|QInputDeviceManager
operator|::
name|DeviceTypeKeyboard
index|]
argument_list|)
decl_stmt|;
operator|--
name|count
expr_stmt|;
name|inputManagerPriv
operator|->
name|setDeviceCount
argument_list|(
name|QInputDeviceManager
operator|::
name|DeviceTypeKeyboard
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
case|case
name|LIBINPUT_EVENT_POINTER_BUTTON
case|:
name|m_pointer
operator|->
name|processButton
argument_list|(
name|libinput_event_get_pointer_event
argument_list|(
name|ev
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|LIBINPUT_EVENT_POINTER_MOTION
case|:
name|m_pointer
operator|->
name|processMotion
argument_list|(
name|libinput_event_get_pointer_event
argument_list|(
name|ev
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|LIBINPUT_EVENT_POINTER_AXIS
case|:
name|m_pointer
operator|->
name|processAxis
argument_list|(
name|libinput_event_get_pointer_event
argument_list|(
name|ev
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|LIBINPUT_EVENT_KEYBOARD_KEY
case|:
name|m_keyboard
operator|->
name|processKey
argument_list|(
name|libinput_event_get_keyboard_event
argument_list|(
name|ev
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|LIBINPUT_EVENT_TOUCH_DOWN
case|:
name|m_touch
operator|->
name|processTouchDown
argument_list|(
name|libinput_event_get_touch_event
argument_list|(
name|ev
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|LIBINPUT_EVENT_TOUCH_MOTION
case|:
name|m_touch
operator|->
name|processTouchMotion
argument_list|(
name|libinput_event_get_touch_event
argument_list|(
name|ev
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|LIBINPUT_EVENT_TOUCH_UP
case|:
name|m_touch
operator|->
name|processTouchUp
argument_list|(
name|libinput_event_get_touch_event
argument_list|(
name|ev
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|LIBINPUT_EVENT_TOUCH_CANCEL
case|:
name|m_touch
operator|->
name|processTouchCancel
argument_list|(
name|libinput_event_get_touch_event
argument_list|(
name|ev
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|LIBINPUT_EVENT_TOUCH_FRAME
case|:
name|m_touch
operator|->
name|processTouchFrame
argument_list|(
name|libinput_event_get_touch_event
argument_list|(
name|ev
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_function
begin_function
DECL|function|onCursorPositionChangeRequested
name|void
name|QLibInputHandler
operator|::
name|onCursorPositionChangeRequested
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|m_pointer
operator|->
name|setPos
argument_list|(
name|pos
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
