begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"application_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbuspendingreply.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"deviceeventcontroller_adaptor.h"
end_include
begin_include
include|#
directive|include
file|"atspi/atspi-constants.h"
end_include
begin_comment
comment|//#define KEYBOARD_DEBUG
end_comment
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QSpiApplicationAdaptor     \internal      \brief QSpiApplicationAdaptor      QSpiApplicationAdaptor */
end_comment
begin_constructor
DECL|function|QSpiApplicationAdaptor
name|QSpiApplicationAdaptor
operator|::
name|QSpiApplicationAdaptor
parameter_list|(
specifier|const
name|QDBusConnection
modifier|&
name|connection
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|dbusConnection
argument_list|(
name|connection
argument_list|)
member_init_list|,
name|inCapsLock
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_enum
DECL|enum|QSpiKeyEventType
enum|enum
name|QSpiKeyEventType
block|{
DECL|enumerator|QSPI_KEY_EVENT_PRESS
name|QSPI_KEY_EVENT_PRESS
block|,
DECL|enumerator|QSPI_KEY_EVENT_RELEASE
name|QSPI_KEY_EVENT_RELEASE
block|,
DECL|enumerator|QSPI_KEY_EVENT_LAST_DEFINED
name|QSPI_KEY_EVENT_LAST_DEFINED
block|}
enum|;
end_enum
begin_function
DECL|function|sendEvents
name|void
name|QSpiApplicationAdaptor
operator|::
name|sendEvents
parameter_list|(
name|bool
name|active
parameter_list|)
block|{
if|if
condition|(
name|active
condition|)
block|{
name|qApp
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qApp
operator|->
name|removeEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|eventFilter
name|bool
name|QSpiApplicationAdaptor
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|target
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
operator|!
name|event
operator|->
name|spontaneous
argument_list|()
condition|)
return|return
literal|false
return|;
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|WindowActivate
case|:
emit|emit
name|windowActivated
argument_list|(
name|target
argument_list|,
literal|true
argument_list|)
emit|;
break|break;
case|case
name|QEvent
operator|::
name|WindowDeactivate
case|:
emit|emit
name|windowActivated
argument_list|(
name|target
argument_list|,
literal|false
argument_list|)
emit|;
break|break;
case|case
name|QEvent
operator|::
name|KeyPress
case|:
case|case
name|QEvent
operator|::
name|KeyRelease
case|:
block|{
name|QKeyEvent
modifier|*
name|keyEvent
init|=
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|QSpiDeviceEvent
name|de
decl_stmt|;
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|KeyPress
condition|)
name|de
operator|.
name|type
operator|=
name|QSPI_KEY_EVENT_PRESS
expr_stmt|;
else|else
name|de
operator|.
name|type
operator|=
name|QSPI_KEY_EVENT_RELEASE
expr_stmt|;
name|de
operator|.
name|id
operator|=
name|keyEvent
operator|->
name|nativeVirtualKey
argument_list|()
expr_stmt|;
name|de
operator|.
name|hardwareCode
operator|=
name|keyEvent
operator|->
name|nativeScanCode
argument_list|()
expr_stmt|;
name|de
operator|.
name|timestamp
operator|=
name|QDateTime
operator|::
name|currentMSecsSinceEpoch
argument_list|()
expr_stmt|;
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Tab
condition|)
name|de
operator|.
name|text
operator|=
name|QStringLiteral
argument_list|(
literal|"Tab"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Backtab
condition|)
name|de
operator|.
name|text
operator|=
name|QStringLiteral
argument_list|(
literal|"Backtab"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Control
condition|)
name|de
operator|.
name|text
operator|=
name|QStringLiteral
argument_list|(
literal|"Control_L"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Left
condition|)
name|de
operator|.
name|text
operator|=
operator|(
name|keyEvent
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|KeypadModifier
operator|)
condition|?
name|QStringLiteral
argument_list|(
literal|"KP_Left"
argument_list|)
else|:
name|QStringLiteral
argument_list|(
literal|"Left"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Right
condition|)
name|de
operator|.
name|text
operator|=
operator|(
name|keyEvent
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|KeypadModifier
operator|)
condition|?
name|QStringLiteral
argument_list|(
literal|"KP_Right"
argument_list|)
else|:
name|QStringLiteral
argument_list|(
literal|"Right"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Up
condition|)
name|de
operator|.
name|text
operator|=
operator|(
name|keyEvent
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|KeypadModifier
operator|)
condition|?
name|QStringLiteral
argument_list|(
literal|"KP_Up"
argument_list|)
else|:
name|QStringLiteral
argument_list|(
literal|"Up"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Down
condition|)
name|de
operator|.
name|text
operator|=
operator|(
name|keyEvent
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|KeypadModifier
operator|)
condition|?
name|QStringLiteral
argument_list|(
literal|"KP_Down"
argument_list|)
else|:
name|QStringLiteral
argument_list|(
literal|"Down"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Enter
operator|||
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Return
condition|)
name|de
operator|.
name|text
operator|=
name|QStringLiteral
argument_list|(
literal|"Return"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Backspace
condition|)
name|de
operator|.
name|text
operator|=
name|QStringLiteral
argument_list|(
literal|"BackSpace"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Delete
condition|)
name|de
operator|.
name|text
operator|=
name|QStringLiteral
argument_list|(
literal|"Delete"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_PageUp
condition|)
name|de
operator|.
name|text
operator|=
operator|(
name|keyEvent
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|KeypadModifier
operator|)
condition|?
name|QStringLiteral
argument_list|(
literal|"KP_Page_Up"
argument_list|)
else|:
name|QStringLiteral
argument_list|(
literal|"Page_Up"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_PageDown
condition|)
name|de
operator|.
name|text
operator|=
operator|(
name|keyEvent
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|KeypadModifier
operator|)
condition|?
name|QStringLiteral
argument_list|(
literal|"KP_Page_Up"
argument_list|)
else|:
name|QStringLiteral
argument_list|(
literal|"Page_Down"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Home
condition|)
name|de
operator|.
name|text
operator|=
operator|(
name|keyEvent
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|KeypadModifier
operator|)
condition|?
name|QStringLiteral
argument_list|(
literal|"KP_Home"
argument_list|)
else|:
name|QStringLiteral
argument_list|(
literal|"Home"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_End
condition|)
name|de
operator|.
name|text
operator|=
operator|(
name|keyEvent
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|KeypadModifier
operator|)
condition|?
name|QStringLiteral
argument_list|(
literal|"KP_End"
argument_list|)
else|:
name|QStringLiteral
argument_list|(
literal|"End"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Clear
operator|&&
operator|(
name|keyEvent
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|KeypadModifier
operator|)
condition|)
name|de
operator|.
name|text
operator|=
name|QStringLiteral
argument_list|(
literal|"KP_Begin"
argument_list|)
expr_stmt|;
comment|// Key pad 5
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Escape
condition|)
name|de
operator|.
name|text
operator|=
name|QStringLiteral
argument_list|(
literal|"Escape"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Space
condition|)
name|de
operator|.
name|text
operator|=
name|QStringLiteral
argument_list|(
literal|"space"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_CapsLock
condition|)
block|{
name|de
operator|.
name|text
operator|=
name|QStringLiteral
argument_list|(
literal|"Caps_Lock"
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|KeyPress
condition|)
name|inCapsLock
operator|=
literal|true
expr_stmt|;
else|else
name|inCapsLock
operator|=
literal|false
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_NumLock
condition|)
name|de
operator|.
name|text
operator|=
name|QStringLiteral
argument_list|(
literal|"Num_Lock"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Insert
condition|)
name|de
operator|.
name|text
operator|=
name|QStringLiteral
argument_list|(
literal|"Insert"
argument_list|)
expr_stmt|;
else|else
name|de
operator|.
name|text
operator|=
name|keyEvent
operator|->
name|text
argument_list|()
expr_stmt|;
comment|// This is a bit dubious, Gnome uses some gtk function here.
comment|// Long term the spec will hopefully change to just use keycodes.
name|de
operator|.
name|isText
operator|=
operator|!
name|de
operator|.
name|text
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
name|de
operator|.
name|modifiers
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|inCapsLock
operator|&&
name|keyEvent
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|ShiftModifier
condition|)
name|de
operator|.
name|modifiers
operator||=
literal|1
operator|<<
name|ATSPI_MODIFIER_SHIFT
expr_stmt|;
if|if
condition|(
name|inCapsLock
operator|&&
operator|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|!=
name|Qt
operator|::
name|Key_CapsLock
operator|)
condition|)
name|de
operator|.
name|modifiers
operator||=
literal|1
operator|<<
name|ATSPI_MODIFIER_SHIFTLOCK
expr_stmt|;
if|if
condition|(
operator|(
name|keyEvent
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|ControlModifier
operator|)
operator|&&
operator|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|!=
name|Qt
operator|::
name|Key_Control
operator|)
condition|)
name|de
operator|.
name|modifiers
operator||=
literal|1
operator|<<
name|ATSPI_MODIFIER_CONTROL
expr_stmt|;
if|if
condition|(
operator|(
name|keyEvent
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|AltModifier
operator|)
operator|&&
operator|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|!=
name|Qt
operator|::
name|Key_Alt
operator|)
condition|)
name|de
operator|.
name|modifiers
operator||=
literal|1
operator|<<
name|ATSPI_MODIFIER_ALT
expr_stmt|;
if|if
condition|(
operator|(
name|keyEvent
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|MetaModifier
operator|)
operator|&&
operator|(
name|keyEvent
operator|->
name|key
argument_list|()
operator|!=
name|Qt
operator|::
name|Key_Meta
operator|)
condition|)
name|de
operator|.
name|modifiers
operator||=
literal|1
operator|<<
name|ATSPI_MODIFIER_META
expr_stmt|;
ifdef|#
directive|ifdef
name|KEYBOARD_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"Key event text:"
argument_list|)
operator|<<
name|event
operator|->
name|type
argument_list|()
operator|<<
name|de
operator|.
name|text
operator|<<
name|QStringLiteral
argument_list|(
literal|"native virtual key:"
argument_list|)
operator|<<
name|de
operator|.
name|id
operator|<<
name|QStringLiteral
argument_list|(
literal|"hardware code/scancode:"
argument_list|)
operator|<<
name|de
operator|.
name|hardwareCode
operator|<<
name|QStringLiteral
argument_list|(
literal|"modifiers:"
argument_list|)
operator|<<
name|de
operator|.
name|modifiers
operator|<<
name|QStringLiteral
argument_list|(
literal|"text:"
argument_list|)
operator|<<
name|de
operator|.
name|text
expr_stmt|;
endif|#
directive|endif
name|QDBusMessage
name|m
init|=
name|QDBusMessage
operator|::
name|createMethodCall
argument_list|(
name|QStringLiteral
argument_list|(
literal|"org.a11y.atspi.Registry"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"/org/a11y/atspi/registry/deviceeventcontroller"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"org.a11y.atspi.DeviceEventController"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"NotifyListenersSync"
argument_list|)
argument_list|)
decl_stmt|;
name|m
operator|.
name|setArguments
argument_list|(
name|QVariantList
argument_list|()
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|de
argument_list|)
argument_list|)
expr_stmt|;
comment|// FIXME: this is critical, the timeout should probably be pretty low to allow normal processing
name|int
name|timeout
init|=
literal|100
decl_stmt|;
name|bool
name|sent
init|=
name|dbusConnection
operator|.
name|callWithCallback
argument_list|(
name|m
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|notifyKeyboardListenerCallback
argument_list|(
name|QDBusMessage
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|notifyKeyboardListenerError
argument_list|(
name|QDBusError
argument_list|,
name|QDBusMessage
argument_list|)
argument_list|)
argument_list|,
name|timeout
argument_list|)
decl_stmt|;
if|if
condition|(
name|sent
condition|)
block|{
comment|//queue the event and send it after callback
name|keyEvents
operator|.
name|enqueue
argument_list|(
name|QPair
argument_list|<
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|,
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|target
argument_list|)
argument_list|,
name|copyKeyEvent
argument_list|(
name|keyEvent
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
default|default:
break|break;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|copyKeyEvent
name|QKeyEvent
modifier|*
name|QSpiApplicationAdaptor
operator|::
name|copyKeyEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|old
parameter_list|)
block|{
return|return
operator|new
name|QKeyEvent
argument_list|(
name|old
operator|->
name|type
argument_list|()
argument_list|,
name|old
operator|->
name|key
argument_list|()
argument_list|,
name|old
operator|->
name|modifiers
argument_list|()
argument_list|,
name|old
operator|->
name|text
argument_list|()
argument_list|,
name|old
operator|->
name|isAutoRepeat
argument_list|()
argument_list|,
name|old
operator|->
name|count
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|notifyKeyboardListenerCallback
name|void
name|QSpiApplicationAdaptor
operator|::
name|notifyKeyboardListenerCallback
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|message
parameter_list|)
block|{
if|if
condition|(
operator|!
name|keyEvents
operator|.
name|length
argument_list|()
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"QSpiApplication::notifyKeyboardListenerCallback with no queued key called"
argument_list|)
expr_stmt|;
return|return;
block|}
name|Q_ASSERT
argument_list|(
name|message
operator|.
name|arguments
argument_list|()
operator|.
name|length
argument_list|()
operator|==
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|message
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toBool
argument_list|()
operator|==
literal|true
condition|)
block|{
name|QPair
argument_list|<
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|,
name|QKeyEvent
modifier|*
argument_list|>
name|event
init|=
name|keyEvents
operator|.
name|dequeue
argument_list|()
decl_stmt|;
operator|delete
name|event
operator|.
name|second
expr_stmt|;
block|}
else|else
block|{
name|QPair
argument_list|<
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|,
name|QKeyEvent
modifier|*
argument_list|>
name|event
init|=
name|keyEvents
operator|.
name|dequeue
argument_list|()
decl_stmt|;
if|if
condition|(
name|event
operator|.
name|first
condition|)
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|event
operator|.
name|first
operator|.
name|data
argument_list|()
argument_list|,
name|event
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|notifyKeyboardListenerError
name|void
name|QSpiApplicationAdaptor
operator|::
name|notifyKeyboardListenerError
parameter_list|(
specifier|const
name|QDBusError
modifier|&
name|error
parameter_list|,
specifier|const
name|QDBusMessage
modifier|&
comment|/*message*/
parameter_list|)
block|{
name|qWarning
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"QSpiApplication::keyEventError "
argument_list|)
operator|<<
name|error
operator|.
name|name
argument_list|()
operator|<<
name|error
operator|.
name|message
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|keyEvents
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QPair
argument_list|<
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|,
name|QKeyEvent
modifier|*
argument_list|>
name|event
init|=
name|keyEvents
operator|.
name|dequeue
argument_list|()
decl_stmt|;
if|if
condition|(
name|event
operator|.
name|first
condition|)
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|event
operator|.
name|first
operator|.
name|data
argument_list|()
argument_list|,
name|event
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
