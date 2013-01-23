begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qibusplatforminputcontext.h"
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_include
include|#
directive|include
file|<QTextCharFormat>
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<qwindow.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|"qibusproxy.h"
end_include
begin_include
include|#
directive|include
file|"qibusinputcontextproxy.h"
end_include
begin_include
include|#
directive|include
file|"qibustypes.h"
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<signal.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enumerator|debug
name|enum
type|{
name|debug
init|=
literal|0
end_decl_stmt
begin_class
DECL|class|QIBusPlatformInputContextPrivate
unit|};
class|class
name|QIBusPlatformInputContextPrivate
block|{
public|public:
name|QIBusPlatformInputContextPrivate
parameter_list|()
constructor_decl|;
DECL|function|~QIBusPlatformInputContextPrivate
name|~
name|QIBusPlatformInputContextPrivate
parameter_list|()
block|{
operator|delete
name|context
expr_stmt|;
operator|delete
name|bus
expr_stmt|;
operator|delete
name|connection
expr_stmt|;
block|}
specifier|static
name|QDBusConnection
modifier|*
name|createConnection
parameter_list|()
function_decl|;
DECL|member|connection
name|QDBusConnection
modifier|*
name|connection
decl_stmt|;
DECL|member|bus
name|QIBusProxy
modifier|*
name|bus
decl_stmt|;
DECL|member|context
name|QIBusInputContextProxy
modifier|*
name|context
decl_stmt|;
DECL|member|valid
name|bool
name|valid
decl_stmt|;
DECL|member|predit
name|QString
name|predit
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QIBusPlatformInputContext
name|QIBusPlatformInputContext
operator|::
name|QIBusPlatformInputContext
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QIBusPlatformInputContextPrivate
argument_list|()
argument_list|)
block|{
if|if
condition|(
name|d
operator|->
name|context
condition|)
block|{
name|connect
argument_list|(
name|d
operator|->
name|context
argument_list|,
name|SIGNAL
argument_list|(
name|CommitText
argument_list|(
name|QDBusVariant
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|commitText
argument_list|(
name|QDBusVariant
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|context
argument_list|,
name|SIGNAL
argument_list|(
name|UpdatePreeditText
argument_list|(
name|QDBusVariant
argument_list|,
name|uint
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updatePreeditText
argument_list|(
name|QDBusVariant
argument_list|,
name|uint
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QInputMethod
modifier|*
name|p
init|=
name|qApp
operator|->
name|inputMethod
argument_list|()
decl_stmt|;
name|connect
argument_list|(
name|p
argument_list|,
name|SIGNAL
argument_list|(
name|cursorRectangleChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|cursorRectChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QIBusPlatformInputContext
name|QIBusPlatformInputContext
operator|::
name|~
name|QIBusPlatformInputContext
parameter_list|(
name|void
parameter_list|)
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|isValid
name|bool
name|QIBusPlatformInputContext
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|valid
return|;
block|}
end_function
begin_function
DECL|function|invokeAction
name|void
name|QIBusPlatformInputContext
operator|::
name|invokeAction
parameter_list|(
name|QInputMethod
operator|::
name|Action
name|a
parameter_list|,
name|int
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|valid
condition|)
return|return;
if|if
condition|(
name|a
operator|==
name|QInputMethod
operator|::
name|Click
condition|)
name|commit
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|QIBusPlatformInputContext
operator|::
name|reset
parameter_list|()
block|{
name|QPlatformInputContext
operator|::
name|reset
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|valid
condition|)
return|return;
name|d
operator|->
name|context
operator|->
name|Reset
argument_list|()
expr_stmt|;
name|d
operator|->
name|predit
operator|=
name|QString
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|commit
name|void
name|QIBusPlatformInputContext
operator|::
name|commit
parameter_list|()
block|{
name|QPlatformInputContext
operator|::
name|commit
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|valid
condition|)
return|return;
name|QObject
modifier|*
name|input
init|=
name|qApp
operator|->
name|focusObject
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|input
condition|)
block|{
name|d
operator|->
name|predit
operator|=
name|QString
argument_list|()
expr_stmt|;
return|return;
block|}
name|QInputMethodEvent
name|event
decl_stmt|;
name|event
operator|.
name|setCommitString
argument_list|(
name|d
operator|->
name|predit
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|input
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
name|d
operator|->
name|context
operator|->
name|Reset
argument_list|()
expr_stmt|;
name|d
operator|->
name|predit
operator|=
name|QString
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|update
name|void
name|QIBusPlatformInputContext
operator|::
name|update
parameter_list|(
name|Qt
operator|::
name|InputMethodQueries
name|q
parameter_list|)
block|{
name|QPlatformInputContext
operator|::
name|update
argument_list|(
name|q
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cursorRectChanged
name|void
name|QIBusPlatformInputContext
operator|::
name|cursorRectChanged
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|valid
condition|)
return|return;
name|QRect
name|r
init|=
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|cursorRectangle
argument_list|()
operator|.
name|toRect
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|r
operator|.
name|isValid
argument_list|()
condition|)
return|return;
name|QWindow
modifier|*
name|inputWindow
init|=
name|qApp
operator|->
name|focusWindow
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|inputWindow
condition|)
return|return;
name|r
operator|.
name|moveTopLeft
argument_list|(
name|inputWindow
operator|->
name|mapToGlobal
argument_list|(
name|r
operator|.
name|topLeft
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"microFocus"
operator|<<
name|r
expr_stmt|;
name|d
operator|->
name|context
operator|->
name|SetCursorLocation
argument_list|(
name|r
operator|.
name|x
argument_list|()
argument_list|,
name|r
operator|.
name|y
argument_list|()
argument_list|,
name|r
operator|.
name|width
argument_list|()
argument_list|,
name|r
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setFocusObject
name|void
name|QIBusPlatformInputContext
operator|::
name|setFocusObject
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|valid
condition|)
return|return;
if|if
condition|(
name|debug
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"setFocusObject"
operator|<<
name|object
expr_stmt|;
if|if
condition|(
name|object
condition|)
name|d
operator|->
name|context
operator|->
name|FocusIn
argument_list|()
expr_stmt|;
else|else
name|d
operator|->
name|context
operator|->
name|FocusOut
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|commitText
name|void
name|QIBusPlatformInputContext
operator|::
name|commitText
parameter_list|(
specifier|const
name|QDBusVariant
modifier|&
name|text
parameter_list|)
block|{
name|QObject
modifier|*
name|input
init|=
name|qApp
operator|->
name|focusObject
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|input
condition|)
return|return;
specifier|const
name|QDBusArgument
name|arg
init|=
name|text
operator|.
name|variant
argument_list|()
operator|.
name|value
argument_list|<
name|QDBusArgument
argument_list|>
argument_list|()
decl_stmt|;
name|QIBusText
name|t
decl_stmt|;
if|if
condition|(
name|debug
condition|)
name|qDebug
argument_list|()
operator|<<
name|arg
operator|.
name|currentSignature
argument_list|()
expr_stmt|;
name|t
operator|.
name|fromDBusArgument
argument_list|(
name|arg
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"commit text:"
operator|<<
name|t
operator|.
name|text
expr_stmt|;
name|QInputMethodEvent
name|event
decl_stmt|;
name|event
operator|.
name|setCommitString
argument_list|(
name|t
operator|.
name|text
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|input
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
name|d
operator|->
name|predit
operator|=
name|QString
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updatePreeditText
name|void
name|QIBusPlatformInputContext
operator|::
name|updatePreeditText
parameter_list|(
specifier|const
name|QDBusVariant
modifier|&
name|text
parameter_list|,
name|uint
name|cursorPos
parameter_list|,
name|bool
name|visible
parameter_list|)
block|{
name|QObject
modifier|*
name|input
init|=
name|qApp
operator|->
name|focusObject
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|input
condition|)
return|return;
specifier|const
name|QDBusArgument
name|arg
init|=
name|text
operator|.
name|variant
argument_list|()
operator|.
name|value
argument_list|<
name|QDBusArgument
argument_list|>
argument_list|()
decl_stmt|;
name|QIBusText
name|t
decl_stmt|;
name|t
operator|.
name|fromDBusArgument
argument_list|(
name|arg
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"preedit text:"
operator|<<
name|t
operator|.
name|text
expr_stmt|;
name|QList
argument_list|<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|>
name|attributes
init|=
name|t
operator|.
name|attributes
operator|.
name|imAttributes
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|t
operator|.
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
name|attributes
operator|+=
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|(
name|QInputMethodEvent
operator|::
name|Cursor
argument_list|,
name|cursorPos
argument_list|,
name|visible
condition|?
literal|1
else|:
literal|0
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
name|QInputMethodEvent
name|event
argument_list|(
name|t
operator|.
name|text
argument_list|,
name|attributes
argument_list|)
decl_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|input
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
name|d
operator|->
name|predit
operator|=
name|t
operator|.
name|text
expr_stmt|;
block|}
end_function
begin_comment
comment|/* Kernel keycode -> X keycode table */
end_comment
begin_decl_stmt
DECL|variable|keycode_table
specifier|static
specifier|const
name|unsigned
name|int
name|keycode_table
index|[
literal|256
index|]
init|=
block|{
literal|0
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|,
literal|15
block|,
literal|16
block|,
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
block|,
literal|24
block|,
literal|25
block|,
literal|26
block|,
literal|27
block|,
literal|28
block|,
literal|29
block|,
literal|30
block|,
literal|31
block|,
literal|32
block|,
literal|33
block|,
literal|34
block|,
literal|35
block|,
literal|36
block|,
literal|37
block|,
literal|38
block|,
literal|39
block|,
literal|40
block|,
literal|41
block|,
literal|42
block|,
literal|43
block|,
literal|44
block|,
literal|45
block|,
literal|46
block|,
literal|47
block|,
literal|48
block|,
literal|49
block|,
literal|50
block|,
literal|51
block|,
literal|52
block|,
literal|53
block|,
literal|54
block|,
literal|55
block|,
literal|56
block|,
literal|57
block|,
literal|58
block|,
literal|59
block|,
literal|60
block|,
literal|61
block|,
literal|62
block|,
literal|63
block|,
literal|64
block|,
literal|65
block|,
literal|66
block|,
literal|67
block|,
literal|68
block|,
literal|69
block|,
literal|70
block|,
literal|71
block|,
literal|72
block|,
literal|73
block|,
literal|74
block|,
literal|75
block|,
literal|76
block|,
literal|77
block|,
literal|76
block|,
literal|79
block|,
literal|80
block|,
literal|81
block|,
literal|82
block|,
literal|83
block|,
literal|84
block|,
literal|85
block|,
literal|86
block|,
literal|87
block|,
literal|88
block|,
literal|89
block|,
literal|90
block|,
literal|91
block|,
literal|111
block|,
literal|221
block|,
literal|94
block|,
literal|95
block|,
literal|96
block|,
literal|211
block|,
literal|128
block|,
literal|127
block|,
literal|129
block|,
literal|208
block|,
literal|131
block|,
literal|126
block|,
literal|108
block|,
literal|109
block|,
literal|112
block|,
literal|111
block|,
literal|113
block|,
literal|181
block|,
literal|97
block|,
literal|98
block|,
literal|99
block|,
literal|100
block|,
literal|102
block|,
literal|103
block|,
literal|104
block|,
literal|105
block|,
literal|106
block|,
literal|107
block|,
literal|239
block|,
literal|160
block|,
literal|174
block|,
literal|176
block|,
literal|222
block|,
literal|157
block|,
literal|123
block|,
literal|110
block|,
literal|139
block|,
literal|134
block|,
literal|209
block|,
literal|210
block|,
literal|133
block|,
literal|115
block|,
literal|116
block|,
literal|117
block|,
literal|232
block|,
literal|133
block|,
literal|134
block|,
literal|135
block|,
literal|140
block|,
literal|248
block|,
literal|191
block|,
literal|192
block|,
literal|122
block|,
literal|188
block|,
literal|245
block|,
literal|158
block|,
literal|161
block|,
literal|193
block|,
literal|223
block|,
literal|227
block|,
literal|198
block|,
literal|199
block|,
literal|200
block|,
literal|147
block|,
literal|159
block|,
literal|151
block|,
literal|178
block|,
literal|201
block|,
literal|146
block|,
literal|203
block|,
literal|166
block|,
literal|236
block|,
literal|230
block|,
literal|235
block|,
literal|234
block|,
literal|233
block|,
literal|163
block|,
literal|204
block|,
literal|253
block|,
literal|153
block|,
literal|162
block|,
literal|144
block|,
literal|164
block|,
literal|177
block|,
literal|152
block|,
literal|190
block|,
literal|208
block|,
literal|129
block|,
literal|130
block|,
literal|231
block|,
literal|209
block|,
literal|210
block|,
literal|136
block|,
literal|220
block|,
literal|143
block|,
literal|246
block|,
literal|251
block|,
literal|137
block|,
literal|138
block|,
literal|182
block|,
literal|183
block|,
literal|184
block|,
literal|93
block|,
literal|184
block|,
literal|247
block|,
literal|132
block|,
literal|170
block|,
literal|219
block|,
literal|249
block|,
literal|205
block|,
literal|207
block|,
literal|149
block|,
literal|150
block|,
literal|154
block|,
literal|155
block|,
literal|167
block|,
literal|168
block|,
literal|169
block|,
literal|171
block|,
literal|172
block|,
literal|173
block|,
literal|165
block|,
literal|175
block|,
literal|179
block|,
literal|180
block|,
literal|0
block|,
literal|185
block|,
literal|186
block|,
literal|187
block|,
literal|118
block|,
literal|119
block|,
literal|120
block|,
literal|121
block|,
literal|229
block|,
literal|194
block|,
literal|195
block|,
literal|196
block|,
literal|197
block|,
literal|148
block|,
literal|202
block|,
literal|101
block|,
literal|212
block|,
literal|237
block|,
literal|214
block|,
literal|215
block|,
literal|216
block|,
literal|217
block|,
literal|218
block|,
literal|228
block|,
literal|142
block|,
literal|213
block|,
literal|240
block|,
literal|241
block|,
literal|242
block|,
literal|243
block|,
literal|244
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_function
name|bool
DECL|function|x11FilterEvent
name|QIBusPlatformInputContext
operator|::
name|x11FilterEvent
parameter_list|(
name|uint
name|keyval
parameter_list|,
name|uint
name|keycode
parameter_list|,
name|uint
name|state
parameter_list|,
name|bool
name|press
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|valid
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|inputMethodAccepted
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|press
condition|)
return|return
literal|false
return|;
name|keycode
operator|-=
literal|8
expr_stmt|;
comment|// ###
name|QDBusReply
argument_list|<
name|bool
argument_list|>
name|reply
init|=
name|d
operator|->
name|context
operator|->
name|ProcessKeyEvent
argument_list|(
name|keyval
argument_list|,
name|keycode
argument_list|,
name|state
argument_list|)
decl_stmt|;
comment|//    qDebug()<< "x11FilterEvent return"<< reply.value();
return|return
name|reply
operator|.
name|value
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QIBusPlatformInputContextPrivate
name|QIBusPlatformInputContextPrivate
operator|::
name|QIBusPlatformInputContextPrivate
parameter_list|()
member_init_list|:
name|connection
argument_list|(
name|createConnection
argument_list|()
argument_list|)
member_init_list|,
name|bus
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|context
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|valid
argument_list|(
literal|false
argument_list|)
block|{
if|if
condition|(
operator|!
name|connection
operator|||
operator|!
name|connection
operator|->
name|isConnected
argument_list|()
condition|)
return|return;
name|bus
operator|=
operator|new
name|QIBusProxy
argument_list|(
name|QLatin1String
argument_list|(
literal|"org.freedesktop.IBus"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"/org/freedesktop/IBus"
argument_list|)
argument_list|,
operator|*
name|connection
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|bus
operator|->
name|isValid
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QIBusPlatformInputContext: invalid bus."
argument_list|)
expr_stmt|;
return|return;
block|}
name|QDBusReply
argument_list|<
name|QDBusObjectPath
argument_list|>
name|ic
init|=
name|bus
operator|->
name|CreateInputContext
argument_list|(
name|QLatin1String
argument_list|(
literal|"QIBusInputContext"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ic
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QIBusPlatformInputContext: CreateInputContext failed."
argument_list|)
expr_stmt|;
return|return;
block|}
name|context
operator|=
operator|new
name|QIBusInputContextProxy
argument_list|(
name|QLatin1String
argument_list|(
literal|"org.freedesktop.IBus"
argument_list|)
argument_list|,
name|ic
operator|.
name|value
argument_list|()
operator|.
name|path
argument_list|()
argument_list|,
operator|*
name|connection
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|context
operator|->
name|isValid
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QIBusPlatformInputContext: invalid input context."
argument_list|)
expr_stmt|;
return|return;
block|}
enum|enum
name|Capabilities
block|{
name|IBUS_CAP_PREEDIT_TEXT
init|=
literal|1
operator|<<
literal|0
block|,
name|IBUS_CAP_AUXILIARY_TEXT
init|=
literal|1
operator|<<
literal|1
block|,
name|IBUS_CAP_LOOKUP_TABLE
init|=
literal|1
operator|<<
literal|2
block|,
name|IBUS_CAP_FOCUS
init|=
literal|1
operator|<<
literal|3
block|,
name|IBUS_CAP_PROPERTY
init|=
literal|1
operator|<<
literal|4
block|,
name|IBUS_CAP_SURROUNDING_TEXT
init|=
literal|1
operator|<<
literal|5
block|}
enum|;
name|context
operator|->
name|SetCapabilities
argument_list|(
name|IBUS_CAP_PREEDIT_TEXT
operator||
name|IBUS_CAP_FOCUS
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|qDebug
argument_list|(
literal|">>>> valid!"
argument_list|)
expr_stmt|;
name|valid
operator|=
literal|true
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|createConnection
name|QDBusConnection
modifier|*
name|QIBusPlatformInputContextPrivate
operator|::
name|createConnection
parameter_list|()
block|{
name|QByteArray
name|display
argument_list|(
name|getenv
argument_list|(
literal|"DISPLAY"
argument_list|)
argument_list|)
decl_stmt|;
name|QByteArray
name|host
init|=
literal|"unix"
decl_stmt|;
name|QByteArray
name|displayNumber
init|=
literal|"0"
decl_stmt|;
name|int
name|pos
init|=
name|display
operator|.
name|indexOf
argument_list|(
literal|':'
argument_list|)
decl_stmt|;
if|if
condition|(
name|pos
operator|>
literal|0
condition|)
name|host
operator|=
name|display
operator|.
name|left
argument_list|(
name|pos
argument_list|)
expr_stmt|;
operator|++
name|pos
expr_stmt|;
name|int
name|pos2
init|=
name|display
operator|.
name|indexOf
argument_list|(
literal|'.'
argument_list|,
name|pos
argument_list|)
decl_stmt|;
if|if
condition|(
name|pos2
operator|>
literal|0
condition|)
name|displayNumber
operator|=
name|display
operator|.
name|mid
argument_list|(
name|pos
argument_list|,
name|pos2
operator|-
name|pos
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"host="
operator|<<
name|host
operator|<<
literal|"displayNumber"
operator|<<
name|displayNumber
expr_stmt|;
name|QFile
name|file
argument_list|(
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/.config/ibus/bus/"
argument_list|)
operator|+
name|QLatin1String
argument_list|(
name|QDBusConnection
operator|::
name|localMachineId
argument_list|()
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'-'
argument_list|)
operator|+
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|host
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'-'
argument_list|)
operator|+
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|displayNumber
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
return|return
literal|0
return|;
name|QByteArray
name|address
decl_stmt|;
name|int
name|pid
init|=
operator|-
literal|1
decl_stmt|;
while|while
condition|(
operator|!
name|file
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QByteArray
name|line
init|=
name|file
operator|.
name|readLine
argument_list|()
operator|.
name|trimmed
argument_list|()
decl_stmt|;
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
literal|'#'
argument_list|)
condition|)
continue|continue;
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
literal|"IBUS_ADDRESS="
argument_list|)
condition|)
name|address
operator|=
name|line
operator|.
name|mid
argument_list|(
sizeof|sizeof
argument_list|(
literal|"IBUS_ADDRESS="
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
literal|"IBUS_DAEMON_PID="
argument_list|)
condition|)
name|pid
operator|=
name|line
operator|.
name|mid
argument_list|(
sizeof|sizeof
argument_list|(
literal|"IBUS_DAEMON_PID="
argument_list|)
operator|-
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|debug
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"IBUS_ADDRESS="
operator|<<
name|address
operator|<<
literal|"PID="
operator|<<
name|pid
expr_stmt|;
if|if
condition|(
name|address
operator|.
name|isEmpty
argument_list|()
operator|||
name|pid
operator|<
literal|0
operator|||
name|kill
argument_list|(
name|pid
argument_list|,
literal|0
argument_list|)
operator|!=
literal|0
condition|)
return|return
literal|0
return|;
return|return
operator|new
name|QDBusConnection
argument_list|(
name|QDBusConnection
operator|::
name|connectToBus
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|address
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"QIBusProxy"
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
