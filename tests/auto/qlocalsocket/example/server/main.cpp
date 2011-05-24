begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlocalserver.h"
end_include
begin_include
include|#
directive|include
file|"qlocalsocket.h"
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_class
DECL|class|EchoServer
class|class
name|EchoServer
super|:
specifier|public
name|QLocalServer
block|{
public|public:
DECL|function|incomingConnection
name|void
name|incomingConnection
parameter_list|(
name|int
name|socketDescriptor
parameter_list|)
block|{
name|QLocalServer
operator|::
name|incomingConnection
argument_list|(
name|socketDescriptor
argument_list|)
expr_stmt|;
name|QLocalSocket
modifier|*
name|socket
init|=
name|nextPendingConnection
argument_list|()
decl_stmt|;
name|socket
operator|->
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadWrite
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"server connection"
expr_stmt|;
do|do
block|{
specifier|const
name|int
name|Timeout
init|=
literal|5
operator|*
literal|1000
decl_stmt|;
while|while
condition|(
operator|!
name|socket
operator|->
name|canReadLine
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|socket
operator|->
name|waitForReadyRead
argument_list|(
name|Timeout
argument_list|)
condition|)
block|{
return|return;
block|}
block|}
name|char
name|str
index|[
literal|100
index|]
decl_stmt|;
name|int
name|n
init|=
name|socket
operator|->
name|readLine
argument_list|(
name|str
argument_list|,
literal|100
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"recv"
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|n
operator|==
literal|0
condition|)
break|break;
name|qDebug
argument_list|()
operator|<<
literal|"Read"
operator|<<
name|str
expr_stmt|;
if|if
condition|(
literal|"exit"
operator|==
name|str
condition|)
name|qApp
operator|->
name|quit
argument_list|()
expr_stmt|;
if|if
condition|(
name|socket
operator|->
name|write
argument_list|(
name|str
argument_list|,
literal|100
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"send"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
do|while
condition|(
literal|true
condition|)
do|;
block|}
block|}
class|;
end_class
begin_define
DECL|macro|SOCK_PATH
define|#
directive|define
name|SOCK_PATH
value|"echo_socket"
end_define
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
name|argv
index|[]
parameter_list|)
block|{
name|QCoreApplication
name|application
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|EchoServer
name|echoServer
decl_stmt|;
name|echoServer
operator|.
name|listen
argument_list|(
name|SOCK_PATH
argument_list|)
expr_stmt|;
return|return
name|application
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
