begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Qt
end_comment
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QDataStream>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_comment
comment|// Test
end_comment
begin_include
include|#
directive|include
file|"Test.h"
end_include
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_constructor
DECL|function|My4Socket
name|My4Socket
operator|::
name|My4Socket
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QTcpSocket
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|safeShutDown
argument_list|(
literal|false
argument_list|)
block|{
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|read
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|disconnected
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|closed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|read
name|void
name|My4Socket
operator|::
name|read
parameter_list|(
name|void
parameter_list|)
block|{
name|QDataStream
name|in
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|quint32
name|num
decl_stmt|,
name|reply
decl_stmt|;
while|while
condition|(
name|bytesAvailable
argument_list|()
condition|)
block|{
name|in
operator|>>
name|num
expr_stmt|;
if|if
condition|(
name|num
operator|==
literal|42
condition|)
block|{
name|safeShutDown
operator|=
literal|true
expr_stmt|;
name|qDebug
argument_list|(
literal|"SUCCESS"
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|quit
argument_list|()
expr_stmt|;
return|return;
block|}
name|reply
operator|=
name|num
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|reply
operator|==
literal|42
condition|)
operator|++
name|reply
expr_stmt|;
block|}
comment|// Reply with a bigger number
name|sendTest
argument_list|(
name|reply
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|closed
name|void
name|My4Socket
operator|::
name|closed
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|safeShutDown
condition|)
name|qDebug
argument_list|(
literal|"FAILED"
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|quit
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|sendTest
name|void
name|My4Socket
operator|::
name|sendTest
parameter_list|(
name|quint32
name|num
parameter_list|)
block|{
name|QByteArray
name|block
decl_stmt|;
name|QDataStream
name|out
argument_list|(
operator|&
name|block
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|out
operator|<<
name|num
expr_stmt|;
name|write
argument_list|(
name|block
argument_list|,
name|block
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_constructor
DECL|function|My4Server
name|My4Server
operator|::
name|My4Server
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QTcpServer
argument_list|(
name|parent
argument_list|)
block|{
if|if
condition|(
name|listen
argument_list|(
name|QHostAddress
operator|::
name|Any
argument_list|,
literal|7700
argument_list|)
condition|)
name|qDebug
argument_list|(
literal|"qt4server"
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|5000
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|stopServer
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|incomingConnection
name|void
name|My4Server
operator|::
name|incomingConnection
parameter_list|(
name|int
name|socketId
parameter_list|)
block|{
name|m_socket
operator|=
operator|new
name|My4Socket
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_socket
operator|->
name|setSocketDescriptor
argument_list|(
name|socketId
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|stopServer
name|void
name|My4Server
operator|::
name|stopServer
parameter_list|()
block|{
if|if
condition|(
name|m_socket
condition|)
block|{
name|qDebug
argument_list|(
literal|"SUCCESS"
argument_list|)
expr_stmt|;
name|m_socket
operator|->
name|safeShutDown
operator|=
literal|true
expr_stmt|;
name|m_socket
operator|->
name|sendTest
argument_list|(
literal|42
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|quit
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_constructor
DECL|function|Test
name|Test
operator|::
name|Test
parameter_list|(
name|Type
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|Qt4Client
case|:
block|{
name|qDebug
argument_list|(
literal|"qt4client"
argument_list|)
expr_stmt|;
name|My4Socket
modifier|*
name|s
init|=
operator|new
name|My4Socket
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|s
operator|->
name|connectToHost
argument_list|(
literal|"localhost"
argument_list|,
literal|7700
argument_list|)
expr_stmt|;
name|s
operator|->
name|sendTest
argument_list|(
literal|1
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|Qt4Server
case|:
block|{
operator|new
name|My4Server
argument_list|(
name|this
argument_list|)
expr_stmt|;
break|break;
block|}
default|default:
break|break;
block|}
block|}
end_constructor
end_unit
