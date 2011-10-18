begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdirectfbinput.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbconvenience.h"
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|<QMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QEvent>
end_include
begin_include
include|#
directive|include
file|<directfb.h>
end_include
begin_constructor
DECL|function|QDirectFbInput
name|QDirectFbInput
operator|::
name|QDirectFbInput
parameter_list|()
member_init_list|:
name|m_dfbInterface
argument_list|(
name|QDirectFbConvenience
operator|::
name|dfbInterface
argument_list|()
argument_list|)
member_init_list|,
name|m_shouldStop
argument_list|(
literal|false
argument_list|)
block|{
name|DFBResult
name|ok
init|=
name|m_dfbInterface
operator|->
name|CreateEventBuffer
argument_list|(
name|m_dfbInterface
argument_list|,
name|m_eventBuffer
operator|.
name|outPtr
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
operator|!=
name|DFB_OK
condition|)
name|DirectFBError
argument_list|(
literal|"Failed to initialise eventbuffer"
argument_list|,
name|ok
argument_list|)
expr_stmt|;
name|m_dfbInterface
operator|->
name|GetDisplayLayer
argument_list|(
name|m_dfbInterface
argument_list|,
name|DLID_PRIMARY
argument_list|,
name|m_dfbDisplayLayer
operator|.
name|outPtr
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|run
name|void
name|QDirectFbInput
operator|::
name|run
parameter_list|()
block|{
while|while
condition|(
operator|!
name|m_shouldStop
condition|)
block|{
if|if
condition|(
name|m_eventBuffer
operator|->
name|WaitForEvent
argument_list|(
name|m_eventBuffer
operator|.
name|data
argument_list|()
argument_list|)
operator|==
name|DFB_OK
condition|)
name|handleEvents
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|stopInputEventLoop
name|void
name|QDirectFbInput
operator|::
name|stopInputEventLoop
parameter_list|()
block|{
name|m_shouldStop
operator|=
literal|true
expr_stmt|;
name|m_eventBuffer
operator|->
name|WakeUp
argument_list|(
name|m_eventBuffer
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addWindow
name|void
name|QDirectFbInput
operator|::
name|addWindow
parameter_list|(
name|DFBWindowID
name|id
parameter_list|,
name|QWindow
modifier|*
name|qt_window
parameter_list|)
block|{
name|m_tlwMap
operator|.
name|insert
argument_list|(
name|id
argument_list|,
name|qt_window
argument_list|)
expr_stmt|;
name|QDirectFBPointer
argument_list|<
name|IDirectFBWindow
argument_list|>
name|window
decl_stmt|;
name|m_dfbDisplayLayer
operator|->
name|GetWindow
argument_list|(
name|m_dfbDisplayLayer
operator|.
name|data
argument_list|()
argument_list|,
name|id
argument_list|,
name|window
operator|.
name|outPtr
argument_list|()
argument_list|)
expr_stmt|;
name|window
operator|->
name|AttachEventBuffer
argument_list|(
name|window
operator|.
name|data
argument_list|()
argument_list|,
name|m_eventBuffer
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeWindow
name|void
name|QDirectFbInput
operator|::
name|removeWindow
parameter_list|(
name|WId
name|wId
parameter_list|)
block|{
name|QDirectFBPointer
argument_list|<
name|IDirectFBWindow
argument_list|>
name|window
decl_stmt|;
name|m_dfbDisplayLayer
operator|->
name|GetWindow
argument_list|(
name|m_dfbDisplayLayer
operator|.
name|data
argument_list|()
argument_list|,
name|wId
argument_list|,
name|window
operator|.
name|outPtr
argument_list|()
argument_list|)
expr_stmt|;
name|window
operator|->
name|DetachEventBuffer
argument_list|(
name|window
operator|.
name|data
argument_list|()
argument_list|,
name|m_eventBuffer
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|m_tlwMap
operator|.
name|remove
argument_list|(
name|wId
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleEvents
name|void
name|QDirectFbInput
operator|::
name|handleEvents
parameter_list|()
block|{
name|DFBResult
name|hasEvent
init|=
name|m_eventBuffer
operator|->
name|HasEvent
argument_list|(
name|m_eventBuffer
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
while|while
condition|(
name|hasEvent
operator|==
name|DFB_OK
condition|)
block|{
name|DFBEvent
name|event
decl_stmt|;
name|DFBResult
name|ok
init|=
name|m_eventBuffer
operator|->
name|GetEvent
argument_list|(
name|m_eventBuffer
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
operator|!=
name|DFB_OK
condition|)
name|DirectFBError
argument_list|(
literal|"Failed to get event"
argument_list|,
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|.
name|clazz
operator|==
name|DFEC_WINDOW
condition|)
block|{
switch|switch
condition|(
name|event
operator|.
name|window
operator|.
name|type
condition|)
block|{
case|case
name|DWET_BUTTONDOWN
case|:
case|case
name|DWET_BUTTONUP
case|:
case|case
name|DWET_MOTION
case|:
name|handleMouseEvents
argument_list|(
name|event
argument_list|)
expr_stmt|;
break|break;
case|case
name|DWET_WHEEL
case|:
name|handleWheelEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
break|break;
case|case
name|DWET_KEYDOWN
case|:
case|case
name|DWET_KEYUP
case|:
name|handleKeyEvents
argument_list|(
name|event
argument_list|)
expr_stmt|;
break|break;
case|case
name|DWET_ENTER
case|:
case|case
name|DWET_LEAVE
case|:
name|handleEnterLeaveEvents
argument_list|(
name|event
argument_list|)
expr_stmt|;
default|default:
break|break;
block|}
block|}
name|hasEvent
operator|=
name|m_eventBuffer
operator|->
name|HasEvent
argument_list|(
name|m_eventBuffer
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|handleMouseEvents
name|void
name|QDirectFbInput
operator|::
name|handleMouseEvents
parameter_list|(
specifier|const
name|DFBEvent
modifier|&
name|event
parameter_list|)
block|{
name|QPoint
name|p
argument_list|(
name|event
operator|.
name|window
operator|.
name|x
argument_list|,
name|event
operator|.
name|window
operator|.
name|y
argument_list|)
decl_stmt|;
name|QPoint
name|globalPos
init|=
name|globalPoint
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|MouseButtons
name|buttons
init|=
name|QDirectFbConvenience
operator|::
name|mouseButtons
argument_list|(
name|event
operator|.
name|window
operator|.
name|buttons
argument_list|)
decl_stmt|;
name|QDirectFBPointer
argument_list|<
name|IDirectFBDisplayLayer
argument_list|>
name|layer
argument_list|(
name|QDirectFbConvenience
operator|::
name|dfbDisplayLayer
argument_list|()
argument_list|)
decl_stmt|;
name|QDirectFBPointer
argument_list|<
name|IDirectFBWindow
argument_list|>
name|window
decl_stmt|;
name|layer
operator|->
name|GetWindow
argument_list|(
name|layer
operator|.
name|data
argument_list|()
argument_list|,
name|event
operator|.
name|window
operator|.
name|window_id
argument_list|,
name|window
operator|.
name|outPtr
argument_list|()
argument_list|)
expr_stmt|;
name|long
name|timestamp
init|=
operator|(
name|event
operator|.
name|window
operator|.
name|timestamp
operator|.
name|tv_sec
operator|*
literal|1000
operator|)
operator|+
operator|(
name|event
operator|.
name|window
operator|.
name|timestamp
operator|.
name|tv_usec
operator|/
literal|1000
operator|)
decl_stmt|;
name|QWindow
modifier|*
name|tlw
init|=
name|m_tlwMap
operator|.
name|value
argument_list|(
name|event
operator|.
name|window
operator|.
name|window_id
argument_list|)
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
name|tlw
argument_list|,
name|timestamp
argument_list|,
name|p
argument_list|,
name|globalPos
argument_list|,
name|buttons
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleWheelEvent
name|void
name|QDirectFbInput
operator|::
name|handleWheelEvent
parameter_list|(
specifier|const
name|DFBEvent
modifier|&
name|event
parameter_list|)
block|{
name|QPoint
name|p
argument_list|(
name|event
operator|.
name|window
operator|.
name|cx
argument_list|,
name|event
operator|.
name|window
operator|.
name|cy
argument_list|)
decl_stmt|;
name|QPoint
name|globalPos
init|=
name|globalPoint
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|long
name|timestamp
init|=
operator|(
name|event
operator|.
name|window
operator|.
name|timestamp
operator|.
name|tv_sec
operator|*
literal|1000
operator|)
operator|+
operator|(
name|event
operator|.
name|window
operator|.
name|timestamp
operator|.
name|tv_usec
operator|/
literal|1000
operator|)
decl_stmt|;
name|QWindow
modifier|*
name|tlw
init|=
name|m_tlwMap
operator|.
name|value
argument_list|(
name|event
operator|.
name|window
operator|.
name|window_id
argument_list|)
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWheelEvent
argument_list|(
name|tlw
argument_list|,
name|timestamp
argument_list|,
name|p
argument_list|,
name|globalPos
argument_list|,
name|event
operator|.
name|window
operator|.
name|step
operator|*
literal|120
argument_list|,
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleKeyEvents
name|void
name|QDirectFbInput
operator|::
name|handleKeyEvents
parameter_list|(
specifier|const
name|DFBEvent
modifier|&
name|event
parameter_list|)
block|{
name|QEvent
operator|::
name|Type
name|type
init|=
name|QDirectFbConvenience
operator|::
name|eventType
argument_list|(
name|event
operator|.
name|window
operator|.
name|type
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|Key
name|key
init|=
name|QDirectFbConvenience
operator|::
name|keyMap
argument_list|()
operator|->
name|value
argument_list|(
name|event
operator|.
name|window
operator|.
name|key_symbol
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
init|=
name|QDirectFbConvenience
operator|::
name|keyboardModifiers
argument_list|(
name|event
operator|.
name|window
operator|.
name|modifiers
argument_list|)
decl_stmt|;
name|long
name|timestamp
init|=
operator|(
name|event
operator|.
name|window
operator|.
name|timestamp
operator|.
name|tv_sec
operator|*
literal|1000
operator|)
operator|+
operator|(
name|event
operator|.
name|window
operator|.
name|timestamp
operator|.
name|tv_usec
operator|/
literal|1000
operator|)
decl_stmt|;
name|QChar
name|character
decl_stmt|;
if|if
condition|(
name|DFB_KEY_TYPE
argument_list|(
name|event
operator|.
name|window
operator|.
name|key_symbol
argument_list|)
operator|==
name|DIKT_UNICODE
condition|)
name|character
operator|=
name|QChar
argument_list|(
name|event
operator|.
name|window
operator|.
name|key_symbol
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|tlw
init|=
name|m_tlwMap
operator|.
name|value
argument_list|(
name|event
operator|.
name|window
operator|.
name|window_id
argument_list|)
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleKeyEvent
argument_list|(
name|tlw
argument_list|,
name|timestamp
argument_list|,
name|type
argument_list|,
name|key
argument_list|,
name|modifiers
argument_list|,
name|character
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleEnterLeaveEvents
name|void
name|QDirectFbInput
operator|::
name|handleEnterLeaveEvents
parameter_list|(
specifier|const
name|DFBEvent
modifier|&
name|event
parameter_list|)
block|{
name|QWindow
modifier|*
name|tlw
init|=
name|m_tlwMap
operator|.
name|value
argument_list|(
name|event
operator|.
name|window
operator|.
name|window_id
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|event
operator|.
name|window
operator|.
name|type
condition|)
block|{
case|case
name|DWET_ENTER
case|:
name|QWindowSystemInterface
operator|::
name|handleEnterEvent
argument_list|(
name|tlw
argument_list|)
expr_stmt|;
break|break;
case|case
name|DWET_LEAVE
case|:
name|QWindowSystemInterface
operator|::
name|handleLeaveEvent
argument_list|(
name|tlw
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_function
begin_function
DECL|function|globalPoint
specifier|inline
name|QPoint
name|QDirectFbInput
operator|::
name|globalPoint
parameter_list|(
specifier|const
name|DFBEvent
modifier|&
name|event
parameter_list|)
specifier|const
block|{
name|QDirectFBPointer
argument_list|<
name|IDirectFBWindow
argument_list|>
name|window
decl_stmt|;
name|m_dfbDisplayLayer
operator|->
name|GetWindow
argument_list|(
name|m_dfbDisplayLayer
operator|.
name|data
argument_list|()
argument_list|,
name|event
operator|.
name|window
operator|.
name|window_id
argument_list|,
name|window
operator|.
name|outPtr
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|window
operator|->
name|GetPosition
argument_list|(
name|window
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|x
argument_list|,
operator|&
name|y
argument_list|)
expr_stmt|;
return|return
name|QPoint
argument_list|(
name|event
operator|.
name|window
operator|.
name|cx
operator|+
name|x
argument_list|,
name|event
operator|.
name|window
operator|.
name|cy
operator|+
name|y
argument_list|)
return|;
block|}
end_function
end_unit
