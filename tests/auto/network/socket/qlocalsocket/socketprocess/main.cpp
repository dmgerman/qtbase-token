begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qelapsedtimer.h>
end_include
begin_include
include|#
directive|include
file|<qeventloop.h>
end_include
begin_include
include|#
directive|include
file|<qlocalsocket.h>
end_include
begin_include
include|#
directive|include
file|<qlocalserver.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_decl_stmt
DECL|variable|serverName
specifier|const
name|QString
name|serverName
init|=
name|QStringLiteral
argument_list|(
literal|"qlocalsocket_autotest"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QByteArray
name|testData
argument_list|(
literal|"test"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|runServer
name|bool
name|runServer
parameter_list|(
name|int
name|numberOfConnections
parameter_list|)
block|{
name|QLocalServer
modifier|*
name|server
init|=
operator|new
name|QLocalServer
argument_list|(
name|qApp
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|server
operator|->
name|removeServer
argument_list|(
name|serverName
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"server: cannot remove server: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|server
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|printf
argument_list|(
literal|"server: listen on \"%s\"\n"
argument_list|,
name|qPrintable
argument_list|(
name|serverName
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|server
operator|->
name|listen
argument_list|(
name|serverName
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"server: listen failed: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|server
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
name|numberOfConnections
condition|;
operator|++
name|i
control|)
block|{
name|printf
argument_list|(
literal|"server: wait for connection %d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|server
operator|->
name|waitForNewConnection
argument_list|(
literal|30000
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"server: waitForNewConnection failed: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|server
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QLocalSocket
modifier|*
name|socket
init|=
name|server
operator|->
name|nextPendingConnection
argument_list|()
decl_stmt|;
name|printf
argument_list|(
literal|"server: writing \"%s\"\n"
argument_list|,
name|testData
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|socket
operator|->
name|write
argument_list|(
name|testData
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|socket
operator|->
name|waitForBytesWritten
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"server: waitForBytesWritten failed: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|socket
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|printf
argument_list|(
literal|"server: data written\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|socket
operator|->
name|error
argument_list|()
operator|!=
name|QLocalSocket
operator|::
name|UnknownSocketError
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"server: socket error %d\n"
argument_list|,
name|socket
operator|->
name|error
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|runClient
name|bool
name|runClient
parameter_list|()
block|{
name|QLocalSocket
name|socket
decl_stmt|;
name|printf
argument_list|(
literal|"client: connecting to \"%s\"\n"
argument_list|,
name|qPrintable
argument_list|(
name|serverName
argument_list|)
argument_list|)
expr_stmt|;
name|QElapsedTimer
name|connectTimer
decl_stmt|;
name|connectTimer
operator|.
name|start
argument_list|()
expr_stmt|;
forever|forever
block|{
name|socket
operator|.
name|connectToServer
argument_list|(
name|serverName
argument_list|,
name|QLocalSocket
operator|::
name|ReadWrite
argument_list|)
expr_stmt|;
if|if
condition|(
name|socket
operator|.
name|waitForConnected
argument_list|()
condition|)
break|break;
if|if
condition|(
name|socket
operator|.
name|error
argument_list|()
operator|==
name|QLocalSocket
operator|::
name|ServerNotFoundError
condition|)
block|{
if|if
condition|(
name|connectTimer
operator|.
name|elapsed
argument_list|()
operator|>
literal|5000
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"client: server not found. Giving up.\n"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|printf
argument_list|(
literal|"client: server not found. Trying again...\n"
argument_list|)
expr_stmt|;
name|QEventLoop
name|eventLoop
decl_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|500
argument_list|,
operator|&
name|eventLoop
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|eventLoop
operator|.
name|exec
argument_list|()
expr_stmt|;
continue|continue;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"client: waitForConnected failed: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|socket
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|printf
argument_list|(
literal|"client: connected\n"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|socket
operator|.
name|waitForReadyRead
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"client: waitForReadyRead failed: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|socket
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|printf
argument_list|(
literal|"client: data is available for reading\n"
argument_list|)
expr_stmt|;
specifier|const
name|QByteArray
name|data
init|=
name|socket
operator|.
name|readLine
argument_list|()
decl_stmt|;
name|printf
argument_list|(
literal|"client: received \"%s\"\n"
argument_list|,
name|data
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|data
operator|!=
name|testData
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"client: received unexpected data\n"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
return|return
name|EXIT_FAILURE
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"--server"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|argc
operator|<
literal|3
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"--server needs the number of incoming connections\n"
argument_list|)
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
name|bool
name|ok
decl_stmt|;
name|int
name|n
init|=
name|QByteArray
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Cannot convert %s to a number.\n"
argument_list|,
name|argv
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
if|if
condition|(
operator|!
name|runServer
argument_list|(
name|n
argument_list|)
condition|)
return|return
name|EXIT_FAILURE
return|;
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"--client"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|runClient
argument_list|()
condition|)
return|return
name|EXIT_FAILURE
return|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"unknown command line option: %s\n"
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
return|return
name|EXIT_SUCCESS
return|;
block|}
end_function
end_unit
