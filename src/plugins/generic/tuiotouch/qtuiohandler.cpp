begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Robin Burchell<robin.burchell@viroteck.net> ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<QRect>
end_include
begin_include
include|#
directive|include
file|<QWindow>
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|"qtuiocursor_p.h"
end_include
begin_include
include|#
directive|include
file|"qtuiohandler_p.h"
end_include
begin_include
include|#
directive|include
file|"qoscbundle_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|lcTuioSource
argument_list|,
literal|"qt.qpa.tuio.source"
argument_list|)
name|Q_LOGGING_CATEGORY
argument_list|(
name|lcTuioSet
argument_list|,
literal|"qt.qpa.tuio.set"
argument_list|)
DECL|function|QTuioHandler
name|QTuioHandler
operator|::
name|QTuioHandler
argument_list|(
specifier|const
name|QString
operator|&
name|specification
argument_list|)
range|:
name|m_device
argument_list|(
argument|new QTouchDevice
argument_list|)
comment|// not leaked, QTouchDevice cleans up registered devices itself
block|{
name|QStringList
name|args
operator|=
name|specification
operator|.
name|split
argument_list|(
literal|':'
argument_list|)
block|;
name|int
name|portNumber
operator|=
literal|3333
block|;
name|int
name|rotationAngle
operator|=
literal|0
block|;
name|bool
name|invertx
operator|=
literal|false
block|;
name|bool
name|inverty
operator|=
literal|false
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|args
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|startsWith
argument_list|(
literal|"udp="
argument_list|)
condition|)
block|{
name|QString
name|portString
operator|=
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|section
argument_list|(
literal|'='
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|;
name|portNumber
operator|=
name|portString
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|startsWith
argument_list|(
literal|"tcp="
argument_list|)
condition|)
block|{
name|QString
name|portString
operator|=
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|section
argument_list|(
literal|'='
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|;
name|portNumber
operator|=
name|portString
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"TCP is not yet supported. Falling back to UDP on "
operator|<<
name|portNumber
decl_stmt|;
end_decl_stmt
begin_if
unit|} else
if|if
condition|(
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
literal|"invertx"
condition|)
block|{
name|invertx
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
literal|"inverty"
condition|)
block|{
name|inverty
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|startsWith
argument_list|(
literal|"rotate="
argument_list|)
condition|)
block|{
name|QString
name|rotateArg
init|=
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|section
argument_list|(
literal|'='
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|int
name|argValue
init|=
name|rotateArg
operator|.
name|toInt
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|argValue
condition|)
block|{
case|case
literal|90
case|:
case|case
literal|180
case|:
case|case
literal|270
case|:
name|rotationAngle
operator|=
name|argValue
expr_stmt|;
default|default:
break|break;
block|}
block|}
end_if
begin_expr_stmt
unit|}      if
operator|(
name|rotationAngle
operator|)
name|m_transform
operator|=
name|QTransform
operator|::
name|fromTranslate
argument_list|(
literal|0.5
argument_list|,
literal|0.5
argument_list|)
operator|.
name|rotate
argument_list|(
name|rotationAngle
argument_list|)
operator|.
name|translate
argument_list|(
operator|-
literal|0.5
argument_list|,
operator|-
literal|0.5
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|invertx
condition|)
name|m_transform
operator|*=
name|QTransform
operator|::
name|fromTranslate
argument_list|(
literal|0.5
argument_list|,
literal|0.5
argument_list|)
operator|.
name|scale
argument_list|(
operator|-
literal|1.0
argument_list|,
literal|1.0
argument_list|)
operator|.
name|translate
argument_list|(
operator|-
literal|0.5
argument_list|,
operator|-
literal|0.5
argument_list|)
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|inverty
condition|)
name|m_transform
operator|*=
name|QTransform
operator|::
name|fromTranslate
argument_list|(
literal|0.5
argument_list|,
literal|0.5
argument_list|)
operator|.
name|scale
argument_list|(
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
operator|.
name|translate
argument_list|(
operator|-
literal|0.5
argument_list|,
operator|-
literal|0.5
argument_list|)
expr_stmt|;
end_if
begin_expr_stmt
name|m_device
operator|->
name|setName
argument_list|(
literal|"TUIO"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// TODO: multiple based on SOURCE?
end_comment
begin_expr_stmt
name|m_device
operator|->
name|setType
argument_list|(
name|QTouchDevice
operator|::
name|TouchScreen
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_device
operator|->
name|setCapabilities
argument_list|(
name|QTouchDevice
operator|::
name|Position
operator||
name|QTouchDevice
operator|::
name|Area
operator||
name|QTouchDevice
operator|::
name|Velocity
operator||
name|QTouchDevice
operator|::
name|NormalizedPosition
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QWindowSystemInterface
operator|::
name|registerTouchDevice
argument_list|(
name|m_device
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|m_socket
operator|.
name|bind
argument_list|(
name|QHostAddress
operator|::
name|Any
argument_list|,
name|portNumber
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Failed to bind TUIO socket: "
operator|<<
name|m_socket
operator|.
name|errorString
argument_list|()
expr_stmt|;
return|return;
block|}
end_if
begin_expr_stmt
name|connect
argument_list|(
operator|&
name|m_socket
argument_list|,
operator|&
name|QUdpSocket
operator|::
name|readyRead
argument_list|,
name|this
argument_list|,
operator|&
name|QTuioHandler
operator|::
name|processPackets
argument_list|)
expr_stmt|;
end_expr_stmt
begin_destructor
unit|}  QTuioHandler
DECL|function|~QTuioHandler
operator|::
name|~
name|QTuioHandler
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|processPackets
name|void
name|QTuioHandler
operator|::
name|processPackets
parameter_list|()
block|{
while|while
condition|(
name|m_socket
operator|.
name|hasPendingDatagrams
argument_list|()
condition|)
block|{
name|QByteArray
name|datagram
decl_stmt|;
name|datagram
operator|.
name|resize
argument_list|(
name|m_socket
operator|.
name|pendingDatagramSize
argument_list|()
argument_list|)
expr_stmt|;
name|QHostAddress
name|sender
decl_stmt|;
name|quint16
name|senderPort
decl_stmt|;
name|qint64
name|size
init|=
name|m_socket
operator|.
name|readDatagram
argument_list|(
name|datagram
operator|.
name|data
argument_list|()
argument_list|,
name|datagram
operator|.
name|size
argument_list|()
argument_list|,
operator|&
name|sender
argument_list|,
operator|&
name|senderPort
argument_list|)
decl_stmt|;
if|if
condition|(
name|size
operator|==
operator|-
literal|1
condition|)
continue|continue;
if|if
condition|(
name|size
operator|!=
name|datagram
operator|.
name|size
argument_list|()
condition|)
name|datagram
operator|.
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|QOscBundle
name|bundle
argument_list|(
name|datagram
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|bundle
operator|.
name|isValid
argument_list|()
condition|)
continue|continue;
comment|// "A typical TUIO bundle will contain an initial ALIVE message,
comment|// followed by an arbitrary number of SET messages that can fit into the
comment|// actual bundle capacity and a concluding FSEQ message. A minimal TUIO
comment|// bundle needs to contain at least the compulsory ALIVE and FSEQ
comment|// messages. The FSEQ frame ID is incremented for each delivered bundle,
comment|// while redundant bundles can be marked using the frame sequence ID
comment|// -1."
name|QList
argument_list|<
name|QOscMessage
argument_list|>
name|messages
init|=
name|bundle
operator|.
name|messages
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QOscMessage
modifier|&
name|message
decl|,
name|messages
control|)
block|{
if|if
condition|(
name|message
operator|.
name|addressPattern
argument_list|()
operator|!=
literal|"/tuio/2Dcur"
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Ignoring unknown address pattern "
operator|<<
name|message
operator|.
name|addressPattern
argument_list|()
expr_stmt|;
continue|continue;
block|}
name|QList
argument_list|<
name|QVariant
argument_list|>
name|arguments
init|=
name|message
operator|.
name|arguments
argument_list|()
decl_stmt|;
if|if
condition|(
name|arguments
operator|.
name|count
argument_list|()
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Ignoring TUIO message with no arguments"
expr_stmt|;
continue|continue;
block|}
name|QByteArray
name|messageType
init|=
name|arguments
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toByteArray
argument_list|()
decl_stmt|;
if|if
condition|(
name|messageType
operator|==
literal|"source"
condition|)
block|{
name|process2DCurSource
argument_list|(
name|message
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|messageType
operator|==
literal|"alive"
condition|)
block|{
name|process2DCurAlive
argument_list|(
name|message
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|messageType
operator|==
literal|"set"
condition|)
block|{
name|process2DCurSet
argument_list|(
name|message
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|messageType
operator|==
literal|"fseq"
condition|)
block|{
name|process2DCurFseq
argument_list|(
name|message
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Ignoring unknown TUIO message type: "
operator|<<
name|messageType
expr_stmt|;
continue|continue;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|process2DCurSource
name|void
name|QTuioHandler
operator|::
name|process2DCurSource
parameter_list|(
specifier|const
name|QOscMessage
modifier|&
name|message
parameter_list|)
block|{
name|QList
argument_list|<
name|QVariant
argument_list|>
name|arguments
init|=
name|message
operator|.
name|arguments
argument_list|()
decl_stmt|;
if|if
condition|(
name|arguments
operator|.
name|count
argument_list|()
operator|!=
literal|2
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Ignoring malformed TUIO source message: "
operator|<<
name|arguments
operator|.
name|count
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|QMetaType
operator|::
name|Type
argument_list|(
name|arguments
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|type
argument_list|()
argument_list|)
operator|!=
name|QMetaType
operator|::
name|QByteArray
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Ignoring malformed TUIO source message (bad argument type)"
expr_stmt|;
return|return;
block|}
name|qCDebug
argument_list|(
name|lcTuioSource
argument_list|)
operator|<<
literal|"Got TUIO source message from: "
operator|<<
name|arguments
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toByteArray
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|process2DCurAlive
name|void
name|QTuioHandler
operator|::
name|process2DCurAlive
parameter_list|(
specifier|const
name|QOscMessage
modifier|&
name|message
parameter_list|)
block|{
name|QList
argument_list|<
name|QVariant
argument_list|>
name|arguments
init|=
name|message
operator|.
name|arguments
argument_list|()
decl_stmt|;
comment|// delta the notified cursors that are active, against the ones we already
comment|// know of.
comment|//
comment|// TBD: right now we're assuming one 2Dcur alive message corresponds to a
comment|// new data source from the input. is this correct, or do we need to store
comment|// changes and only process the deltas on fseq?
name|QMap
argument_list|<
name|int
argument_list|,
name|QTuioCursor
argument_list|>
name|oldActiveCursors
init|=
name|m_activeCursors
decl_stmt|;
name|QMap
argument_list|<
name|int
argument_list|,
name|QTuioCursor
argument_list|>
name|newActiveCursors
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|arguments
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|QMetaType
operator|::
name|Type
argument_list|(
name|arguments
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|type
argument_list|()
argument_list|)
operator|!=
name|QMetaType
operator|::
name|Int
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Ignoring malformed TUIO alive message (bad argument on position"
operator|<<
name|i
operator|<<
name|arguments
operator|<<
literal|")"
expr_stmt|;
return|return;
block|}
name|int
name|cursorId
init|=
name|arguments
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|oldActiveCursors
operator|.
name|contains
argument_list|(
name|cursorId
argument_list|)
condition|)
block|{
comment|// newly active
name|QTuioCursor
name|cursor
argument_list|(
name|cursorId
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|setState
argument_list|(
name|Qt
operator|::
name|TouchPointPressed
argument_list|)
expr_stmt|;
name|newActiveCursors
operator|.
name|insert
argument_list|(
name|cursorId
argument_list|,
name|cursor
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// we already know about it, remove it so it isn't marked as released
name|QTuioCursor
name|cursor
init|=
name|oldActiveCursors
operator|.
name|value
argument_list|(
name|cursorId
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|setState
argument_list|(
name|Qt
operator|::
name|TouchPointStationary
argument_list|)
expr_stmt|;
comment|// position change in SET will update if needed
name|newActiveCursors
operator|.
name|insert
argument_list|(
name|cursorId
argument_list|,
name|cursor
argument_list|)
expr_stmt|;
name|oldActiveCursors
operator|.
name|remove
argument_list|(
name|cursorId
argument_list|)
expr_stmt|;
block|}
block|}
comment|// anything left is dead now
name|QMap
argument_list|<
name|int
argument_list|,
name|QTuioCursor
argument_list|>
operator|::
name|ConstIterator
name|it
init|=
name|oldActiveCursors
operator|.
name|constBegin
argument_list|()
decl_stmt|;
comment|// deadCursors should be cleared from the last FSEQ now
name|m_deadCursors
operator|.
name|reserve
argument_list|(
name|oldActiveCursors
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
comment|// TODO: there could be an issue of resource exhaustion here if FSEQ isn't
comment|// sent in a timely fashion. we should probably track message counts and
comment|// force-flush if we get too many built up.
while|while
condition|(
name|it
operator|!=
name|oldActiveCursors
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|m_deadCursors
operator|.
name|append
argument_list|(
name|it
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
operator|++
name|it
expr_stmt|;
block|}
name|m_activeCursors
operator|=
name|newActiveCursors
expr_stmt|;
block|}
end_function
begin_function
DECL|function|process2DCurSet
name|void
name|QTuioHandler
operator|::
name|process2DCurSet
parameter_list|(
specifier|const
name|QOscMessage
modifier|&
name|message
parameter_list|)
block|{
name|QList
argument_list|<
name|QVariant
argument_list|>
name|arguments
init|=
name|message
operator|.
name|arguments
argument_list|()
decl_stmt|;
if|if
condition|(
name|arguments
operator|.
name|count
argument_list|()
operator|<
literal|7
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Ignoring malformed TUIO set message with too few arguments: "
operator|<<
name|arguments
operator|.
name|count
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|QMetaType
operator|::
name|Type
argument_list|(
name|arguments
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|type
argument_list|()
argument_list|)
operator|!=
name|QMetaType
operator|::
name|Int
operator|||
name|QMetaType
operator|::
name|Type
argument_list|(
name|arguments
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|type
argument_list|()
argument_list|)
operator|!=
name|QMetaType
operator|::
name|Float
operator|||
name|QMetaType
operator|::
name|Type
argument_list|(
name|arguments
operator|.
name|at
argument_list|(
literal|3
argument_list|)
operator|.
name|type
argument_list|()
argument_list|)
operator|!=
name|QMetaType
operator|::
name|Float
operator|||
name|QMetaType
operator|::
name|Type
argument_list|(
name|arguments
operator|.
name|at
argument_list|(
literal|4
argument_list|)
operator|.
name|type
argument_list|()
argument_list|)
operator|!=
name|QMetaType
operator|::
name|Float
operator|||
name|QMetaType
operator|::
name|Type
argument_list|(
name|arguments
operator|.
name|at
argument_list|(
literal|5
argument_list|)
operator|.
name|type
argument_list|()
argument_list|)
operator|!=
name|QMetaType
operator|::
name|Float
operator|||
name|QMetaType
operator|::
name|Type
argument_list|(
name|arguments
operator|.
name|at
argument_list|(
literal|6
argument_list|)
operator|.
name|type
argument_list|()
argument_list|)
operator|!=
name|QMetaType
operator|::
name|Float
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Ignoring malformed TUIO set message with bad types: "
operator|<<
name|arguments
expr_stmt|;
return|return;
block|}
name|int
name|cursorId
init|=
name|arguments
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|float
name|x
init|=
name|arguments
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|toFloat
argument_list|()
decl_stmt|;
name|float
name|y
init|=
name|arguments
operator|.
name|at
argument_list|(
literal|3
argument_list|)
operator|.
name|toFloat
argument_list|()
decl_stmt|;
name|float
name|vx
init|=
name|arguments
operator|.
name|at
argument_list|(
literal|4
argument_list|)
operator|.
name|toFloat
argument_list|()
decl_stmt|;
name|float
name|vy
init|=
name|arguments
operator|.
name|at
argument_list|(
literal|5
argument_list|)
operator|.
name|toFloat
argument_list|()
decl_stmt|;
name|float
name|acceleration
init|=
name|arguments
operator|.
name|at
argument_list|(
literal|6
argument_list|)
operator|.
name|toFloat
argument_list|()
decl_stmt|;
name|QMap
argument_list|<
name|int
argument_list|,
name|QTuioCursor
argument_list|>
operator|::
name|Iterator
name|it
init|=
name|m_activeCursors
operator|.
name|find
argument_list|(
name|cursorId
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|m_activeCursors
operator|.
name|end
argument_list|()
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Ignoring malformed TUIO set for nonexistent cursor "
operator|<<
name|cursorId
expr_stmt|;
return|return;
block|}
name|qCDebug
argument_list|(
name|lcTuioSet
argument_list|)
operator|<<
literal|"Processing SET for "
operator|<<
name|cursorId
operator|<<
literal|" x: "
operator|<<
name|x
operator|<<
name|y
operator|<<
name|vx
operator|<<
name|vy
operator|<<
name|acceleration
expr_stmt|;
name|QTuioCursor
modifier|&
name|cur
init|=
operator|*
name|it
decl_stmt|;
name|cur
operator|.
name|setX
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|cur
operator|.
name|setY
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|cur
operator|.
name|setVX
argument_list|(
name|vx
argument_list|)
expr_stmt|;
name|cur
operator|.
name|setVY
argument_list|(
name|vy
argument_list|)
expr_stmt|;
name|cur
operator|.
name|setAcceleration
argument_list|(
name|acceleration
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cursorToTouchPoint
name|QWindowSystemInterface
operator|::
name|TouchPoint
name|QTuioHandler
operator|::
name|cursorToTouchPoint
parameter_list|(
specifier|const
name|QTuioCursor
modifier|&
name|tc
parameter_list|,
name|QWindow
modifier|*
name|win
parameter_list|)
block|{
name|QWindowSystemInterface
operator|::
name|TouchPoint
name|tp
decl_stmt|;
name|tp
operator|.
name|id
operator|=
name|tc
operator|.
name|id
argument_list|()
expr_stmt|;
name|tp
operator|.
name|pressure
operator|=
literal|1.0f
expr_stmt|;
name|tp
operator|.
name|normalPosition
operator|=
name|QPointF
argument_list|(
name|tc
operator|.
name|x
argument_list|()
argument_list|,
name|tc
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_transform
operator|.
name|isIdentity
argument_list|()
condition|)
name|tp
operator|.
name|normalPosition
operator|=
name|m_transform
operator|.
name|map
argument_list|(
name|tp
operator|.
name|normalPosition
argument_list|)
expr_stmt|;
name|tp
operator|.
name|state
operator|=
name|tc
operator|.
name|state
argument_list|()
expr_stmt|;
name|tp
operator|.
name|area
operator|=
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// we map the touch to the size of the window. we do this, because frankly,
comment|// trying to figure out which part of the screen to hit in order to press an
comment|// element on the UI is pretty tricky when one is not using an overlay-style
comment|// TUIO device.
comment|//
comment|// in the future, it might make sense to make this choice optional,
comment|// dependent on the spec.
name|QPointF
name|relPos
init|=
name|QPointF
argument_list|(
name|win
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|*
name|tp
operator|.
name|normalPosition
operator|.
name|x
argument_list|()
argument_list|,
name|win
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
operator|*
name|tp
operator|.
name|normalPosition
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
name|QPointF
name|delta
init|=
name|relPos
operator|-
name|relPos
operator|.
name|toPoint
argument_list|()
decl_stmt|;
name|tp
operator|.
name|area
operator|.
name|moveCenter
argument_list|(
name|win
operator|->
name|mapToGlobal
argument_list|(
name|relPos
operator|.
name|toPoint
argument_list|()
argument_list|)
operator|+
name|delta
argument_list|)
expr_stmt|;
name|tp
operator|.
name|velocity
operator|=
name|QVector2D
argument_list|(
name|win
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|*
name|tc
operator|.
name|vx
argument_list|()
argument_list|,
name|win
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
operator|*
name|tc
operator|.
name|vy
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|tp
return|;
block|}
end_function
begin_function
DECL|function|process2DCurFseq
name|void
name|QTuioHandler
operator|::
name|process2DCurFseq
parameter_list|(
specifier|const
name|QOscMessage
modifier|&
name|message
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|message
argument_list|)
expr_stmt|;
comment|// TODO: do we need to do anything with the frame id?
name|QWindow
modifier|*
name|win
init|=
name|QGuiApplication
operator|::
name|focusWindow
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|win
condition|)
return|return;
name|QList
argument_list|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
argument_list|>
name|tpl
decl_stmt|;
name|tpl
operator|.
name|reserve
argument_list|(
name|m_activeCursors
operator|.
name|size
argument_list|()
operator|+
name|m_deadCursors
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QTuioCursor
modifier|&
name|tc
decl|,
name|m_activeCursors
control|)
block|{
name|QWindowSystemInterface
operator|::
name|TouchPoint
name|tp
init|=
name|cursorToTouchPoint
argument_list|(
name|tc
argument_list|,
name|win
argument_list|)
decl_stmt|;
name|tpl
operator|.
name|append
argument_list|(
name|tp
argument_list|)
expr_stmt|;
block|}
foreach|foreach
control|(
specifier|const
name|QTuioCursor
modifier|&
name|tc
decl|,
name|m_deadCursors
control|)
block|{
name|QWindowSystemInterface
operator|::
name|TouchPoint
name|tp
init|=
name|cursorToTouchPoint
argument_list|(
name|tc
argument_list|,
name|win
argument_list|)
decl_stmt|;
name|tp
operator|.
name|state
operator|=
name|Qt
operator|::
name|TouchPointReleased
expr_stmt|;
name|tpl
operator|.
name|append
argument_list|(
name|tp
argument_list|)
expr_stmt|;
block|}
name|QWindowSystemInterface
operator|::
name|handleTouchEvent
argument_list|(
name|win
argument_list|,
name|m_device
argument_list|,
name|tpl
argument_list|)
expr_stmt|;
name|m_deadCursors
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
