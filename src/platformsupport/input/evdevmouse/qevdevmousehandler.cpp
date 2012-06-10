begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qevdevmousehandler_p.h"
end_include
begin_include
include|#
directive|include
file|<QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QPoint>
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_include
include|#
directive|include
file|<QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|<qplatformdefs.h>
end_include
begin_include
include|#
directive|include
file|<private/qcore_unix_p.h>
end_include
begin_comment
comment|// overrides QT_OPEN
end_comment
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<linux/kd.h>
end_include
begin_include
include|#
directive|include
file|<linux/input.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_comment
comment|//#define QT_QPA_MOUSE_HANDLER_DEBUG
end_comment
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|create
name|QEvdevMouseHandler
modifier|*
name|QEvdevMouseHandler
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|device
parameter_list|,
specifier|const
name|QString
modifier|&
name|specification
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_MOUSE_HANDLER_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Try to create mouse handler for"
operator|<<
name|device
operator|<<
name|specification
expr_stmt|;
endif|#
directive|endif
name|bool
name|compression
init|=
literal|true
decl_stmt|;
name|int
name|jitterLimit
init|=
literal|0
decl_stmt|;
name|QStringList
name|args
init|=
name|specification
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|arg
decl|,
name|args
control|)
block|{
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"nocompress"
argument_list|)
condition|)
name|compression
operator|=
literal|false
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"dejitter="
argument_list|)
argument_list|)
condition|)
name|jitterLimit
operator|=
name|arg
operator|.
name|mid
argument_list|(
literal|9
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
name|int
name|fd
decl_stmt|;
name|fd
operator|=
name|qt_safe_open
argument_list|(
name|device
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|O_RDONLY
operator||
name|O_NDELAY
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|>=
literal|0
condition|)
block|{
return|return
operator|new
name|QEvdevMouseHandler
argument_list|(
name|device
argument_list|,
name|fd
argument_list|,
name|compression
argument_list|,
name|jitterLimit
argument_list|)
return|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"Cannot open mouse input device '%s': %s"
argument_list|,
name|qPrintable
argument_list|(
name|device
argument_list|)
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_function
begin_constructor
DECL|function|QEvdevMouseHandler
name|QEvdevMouseHandler
operator|::
name|QEvdevMouseHandler
parameter_list|(
specifier|const
name|QString
modifier|&
name|device
parameter_list|,
name|int
name|fd
parameter_list|,
name|bool
name|compression
parameter_list|,
name|int
name|jitterLimit
parameter_list|)
member_init_list|:
name|m_device
argument_list|(
name|device
argument_list|)
member_init_list|,
name|m_fd
argument_list|(
name|fd
argument_list|)
member_init_list|,
name|m_notify
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_x
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_y
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_prevx
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_prevy
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_compression
argument_list|(
name|compression
argument_list|)
member_init_list|,
name|m_buttons
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_prevInvalid
argument_list|(
literal|true
argument_list|)
block|{
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"Evdev Mouse Handler"
argument_list|)
argument_list|)
expr_stmt|;
name|m_jitterLimitSquared
operator|=
name|jitterLimit
operator|*
name|jitterLimit
expr_stmt|;
comment|// socket notifier for events on the mouse device
name|QSocketNotifier
modifier|*
name|notifier
decl_stmt|;
name|notifier
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|m_fd
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|notifier
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
name|readMouseData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEvdevMouseHandler
name|QEvdevMouseHandler
operator|::
name|~
name|QEvdevMouseHandler
parameter_list|()
block|{
if|if
condition|(
name|m_fd
operator|>=
literal|0
condition|)
name|qt_safe_close
argument_list|(
name|m_fd
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|sendMouseEvent
name|void
name|QEvdevMouseHandler
operator|::
name|sendMouseEvent
parameter_list|()
block|{
name|int
name|x
init|=
name|m_x
operator|-
name|m_prevx
decl_stmt|;
name|int
name|y
init|=
name|m_y
operator|-
name|m_prevy
decl_stmt|;
if|if
condition|(
name|m_prevInvalid
condition|)
block|{
name|x
operator|=
name|y
operator|=
literal|0
expr_stmt|;
name|m_prevInvalid
operator|=
literal|false
expr_stmt|;
block|}
emit|emit
name|handleMouseEvent
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|m_buttons
argument_list|)
emit|;
name|m_prevx
operator|=
name|m_x
expr_stmt|;
name|m_prevy
operator|=
name|m_y
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readMouseData
name|void
name|QEvdevMouseHandler
operator|::
name|readMouseData
parameter_list|()
block|{
name|struct
operator|::
name|input_event
name|buffer
index|[
literal|32
index|]
decl_stmt|;
name|int
name|n
init|=
literal|0
decl_stmt|;
name|bool
name|posChanged
init|=
literal|false
decl_stmt|,
name|btnChanged
init|=
literal|false
decl_stmt|;
name|bool
name|pendingMouseEvent
init|=
literal|false
decl_stmt|;
name|int
name|eventCompressCount
init|=
literal|0
decl_stmt|;
forever|forever
block|{
name|int
name|result
init|=
name|QT_READ
argument_list|(
name|m_fd
argument_list|,
cast|reinterpret_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|buffer
argument_list|)
operator|+
name|n
argument_list|,
sizeof|sizeof
argument_list|(
name|buffer
argument_list|)
operator|-
name|n
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"Got EOF from the input device."
argument_list|)
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
name|result
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|!=
name|EINTR
operator|&&
name|errno
operator|!=
name|EAGAIN
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not read from input device: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
else|else
block|{
name|n
operator|+=
name|result
expr_stmt|;
if|if
condition|(
name|n
operator|%
sizeof|sizeof
argument_list|(
name|buffer
index|[
literal|0
index|]
argument_list|)
operator|==
literal|0
condition|)
break|break;
block|}
block|}
name|n
operator|/=
sizeof|sizeof
argument_list|(
name|buffer
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
block|{
name|struct
operator|::
name|input_event
modifier|*
name|data
init|=
operator|&
name|buffer
index|[
name|i
index|]
decl_stmt|;
comment|//qDebug()<< ">>"<< hex<< data->type<< data->code<< dec<< data->value;
if|if
condition|(
name|data
operator|->
name|type
operator|==
name|EV_ABS
condition|)
block|{
comment|// Touchpads: store the absolute position for now, will calculate a relative one later.
if|if
condition|(
name|data
operator|->
name|code
operator|==
name|ABS_X
operator|&&
name|m_x
operator|!=
name|data
operator|->
name|value
condition|)
block|{
name|m_x
operator|=
name|data
operator|->
name|value
expr_stmt|;
name|posChanged
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|data
operator|->
name|code
operator|==
name|ABS_Y
operator|&&
name|m_y
operator|!=
name|data
operator|->
name|value
condition|)
block|{
name|m_y
operator|=
name|data
operator|->
name|value
expr_stmt|;
name|posChanged
operator|=
literal|true
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|data
operator|->
name|type
operator|==
name|EV_REL
condition|)
block|{
if|if
condition|(
name|data
operator|->
name|code
operator|==
name|REL_X
condition|)
block|{
name|m_x
operator|+=
name|data
operator|->
name|value
expr_stmt|;
name|posChanged
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|data
operator|->
name|code
operator|==
name|REL_Y
condition|)
block|{
name|m_y
operator|+=
name|data
operator|->
name|value
expr_stmt|;
name|posChanged
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|data
operator|->
name|code
operator|==
name|ABS_WHEEL
condition|)
block|{
comment|// vertical scroll
comment|// data->value: 1 == up, -1 == down
specifier|const
name|int
name|delta
init|=
literal|120
operator|*
name|data
operator|->
name|value
decl_stmt|;
emit|emit
name|handleWheelEvent
argument_list|(
name|delta
argument_list|,
name|Qt
operator|::
name|Vertical
argument_list|)
emit|;
block|}
elseif|else
if|if
condition|(
name|data
operator|->
name|code
operator|==
name|ABS_THROTTLE
condition|)
block|{
comment|// horizontal scroll
comment|// data->value: 1 == right, -1 == left
specifier|const
name|int
name|delta
init|=
literal|120
operator|*
operator|-
name|data
operator|->
name|value
decl_stmt|;
emit|emit
name|handleWheelEvent
argument_list|(
name|delta
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|)
emit|;
block|}
block|}
elseif|else
if|if
condition|(
name|data
operator|->
name|type
operator|==
name|EV_KEY
operator|&&
name|data
operator|->
name|code
operator|==
name|BTN_TOUCH
condition|)
block|{
comment|// We care about touchpads only, not touchscreens -> don't map to button press.
comment|// Need to invalidate prevx/y however to get proper relative pos.
name|m_prevInvalid
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|data
operator|->
name|type
operator|==
name|EV_KEY
operator|&&
name|data
operator|->
name|code
operator|>=
name|BTN_LEFT
operator|&&
name|data
operator|->
name|code
operator|<=
name|BTN_JOYSTICK
condition|)
block|{
name|Qt
operator|::
name|MouseButton
name|button
init|=
name|Qt
operator|::
name|NoButton
decl_stmt|;
comment|// BTN_LEFT == 0x110 in kernel's input.h
comment|// The range of possible mouse buttons ends just before BTN_JOYSTICK, value 0x120.
switch|switch
condition|(
name|data
operator|->
name|code
condition|)
block|{
case|case
literal|0x110
case|:
name|button
operator|=
name|Qt
operator|::
name|LeftButton
expr_stmt|;
break|break;
comment|// BTN_LEFT
case|case
literal|0x111
case|:
name|button
operator|=
name|Qt
operator|::
name|RightButton
expr_stmt|;
break|break;
case|case
literal|0x112
case|:
name|button
operator|=
name|Qt
operator|::
name|MiddleButton
expr_stmt|;
break|break;
case|case
literal|0x113
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton1
expr_stmt|;
break|break;
comment|// AKA Qt::BackButton
case|case
literal|0x114
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton2
expr_stmt|;
break|break;
comment|// AKA Qt::ForwardButton
case|case
literal|0x115
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton3
expr_stmt|;
break|break;
comment|// AKA Qt::TaskButton
case|case
literal|0x116
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton4
expr_stmt|;
break|break;
case|case
literal|0x117
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton5
expr_stmt|;
break|break;
case|case
literal|0x118
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton6
expr_stmt|;
break|break;
case|case
literal|0x119
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton7
expr_stmt|;
break|break;
case|case
literal|0x11a
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton8
expr_stmt|;
break|break;
case|case
literal|0x11b
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton9
expr_stmt|;
break|break;
case|case
literal|0x11c
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton10
expr_stmt|;
break|break;
case|case
literal|0x11d
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton11
expr_stmt|;
break|break;
case|case
literal|0x11e
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton12
expr_stmt|;
break|break;
case|case
literal|0x11f
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton13
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|data
operator|->
name|value
condition|)
name|m_buttons
operator||=
name|button
expr_stmt|;
else|else
name|m_buttons
operator|&=
operator|~
name|button
expr_stmt|;
name|btnChanged
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|data
operator|->
name|type
operator|==
name|EV_SYN
operator|&&
name|data
operator|->
name|code
operator|==
name|SYN_REPORT
condition|)
block|{
if|if
condition|(
name|btnChanged
condition|)
block|{
name|btnChanged
operator|=
name|posChanged
operator|=
literal|false
expr_stmt|;
name|sendMouseEvent
argument_list|()
expr_stmt|;
name|pendingMouseEvent
operator|=
literal|false
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|posChanged
condition|)
block|{
name|posChanged
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|m_compression
condition|)
block|{
name|pendingMouseEvent
operator|=
literal|true
expr_stmt|;
name|eventCompressCount
operator|++
expr_stmt|;
block|}
else|else
block|{
name|sendMouseEvent
argument_list|()
expr_stmt|;
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|data
operator|->
name|type
operator|==
name|EV_MSC
operator|&&
name|data
operator|->
name|code
operator|==
name|MSC_SCAN
condition|)
block|{
comment|// kernel encountered an unmapped key - just ignore it
continue|continue;
block|}
block|}
if|if
condition|(
name|m_compression
operator|&&
name|pendingMouseEvent
condition|)
block|{
name|int
name|distanceSquared
init|=
operator|(
name|m_x
operator|-
name|m_prevx
operator|)
operator|*
operator|(
name|m_x
operator|-
name|m_prevx
operator|)
operator|+
operator|(
name|m_y
operator|-
name|m_prevy
operator|)
operator|*
operator|(
name|m_y
operator|-
name|m_prevy
operator|)
decl_stmt|;
if|if
condition|(
name|distanceSquared
operator|>
name|m_jitterLimitSquared
condition|)
name|sendMouseEvent
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
