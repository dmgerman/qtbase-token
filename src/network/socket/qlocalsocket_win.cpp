begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlocalsocket_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qthread_p.h>
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
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|init
name|void
name|QLocalSocketPrivate
operator|::
name|init
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
name|pipeReader
operator|=
operator|new
name|QWindowsPipeReader
argument_list|(
name|q
argument_list|)
expr_stmt|;
name|q
operator|->
name|connect
argument_list|(
name|pipeReader
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|->
name|connect
argument_list|(
name|pipeReader
argument_list|,
name|SIGNAL
argument_list|(
name|pipeClosed
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|_q_pipeClosed
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|q
operator|->
name|connect
argument_list|(
name|pipeReader
argument_list|,
name|SIGNAL
argument_list|(
name|winError
argument_list|(
name|ulong
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|_q_winError
argument_list|(
name|ulong
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setErrorString
name|void
name|QLocalSocketPrivate
operator|::
name|setErrorString
parameter_list|(
specifier|const
name|QString
modifier|&
name|function
parameter_list|)
block|{
name|DWORD
name|windowsError
init|=
name|GetLastError
argument_list|()
decl_stmt|;
name|_q_winError
argument_list|(
name|windowsError
argument_list|,
name|function
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_winError
name|void
name|QLocalSocketPrivate
operator|::
name|_q_winError
parameter_list|(
name|ulong
name|windowsError
parameter_list|,
specifier|const
name|QString
modifier|&
name|function
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
name|QLocalSocket
operator|::
name|LocalSocketState
name|currentState
init|=
name|state
decl_stmt|;
comment|// If the connectToServer fails due to WaitNamedPipe() time-out, assume ConnectionError
if|if
condition|(
name|state
operator|==
name|QLocalSocket
operator|::
name|ConnectingState
operator|&&
name|windowsError
operator|==
name|ERROR_SEM_TIMEOUT
condition|)
name|windowsError
operator|=
name|ERROR_NO_DATA
expr_stmt|;
switch|switch
condition|(
name|windowsError
condition|)
block|{
case|case
name|ERROR_PIPE_NOT_CONNECTED
case|:
case|case
name|ERROR_BROKEN_PIPE
case|:
case|case
name|ERROR_NO_DATA
case|:
name|error
operator|=
name|QLocalSocket
operator|::
name|ConnectionError
expr_stmt|;
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Connection error"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|state
operator|=
name|QLocalSocket
operator|::
name|UnconnectedState
expr_stmt|;
break|break;
case|case
name|ERROR_FILE_NOT_FOUND
case|:
name|error
operator|=
name|QLocalSocket
operator|::
name|ServerNotFoundError
expr_stmt|;
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Invalid name"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|state
operator|=
name|QLocalSocket
operator|::
name|UnconnectedState
expr_stmt|;
break|break;
case|case
name|ERROR_ACCESS_DENIED
case|:
name|error
operator|=
name|QLocalSocket
operator|::
name|SocketAccessError
expr_stmt|;
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Access denied"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|state
operator|=
name|QLocalSocket
operator|::
name|UnconnectedState
expr_stmt|;
break|break;
default|default:
name|error
operator|=
name|QLocalSocket
operator|::
name|UnknownSocketError
expr_stmt|;
name|errorString
operator|=
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Unknown error %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
operator|.
name|arg
argument_list|(
name|windowsError
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QLOCALSOCKET_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"QLocalSocket error not handled:"
operator|<<
name|errorString
expr_stmt|;
endif|#
directive|endif
name|state
operator|=
name|QLocalSocket
operator|::
name|UnconnectedState
expr_stmt|;
block|}
if|if
condition|(
name|currentState
operator|!=
name|state
condition|)
block|{
name|q
operator|->
emit|emit
name|stateChanged
argument_list|(
name|state
argument_list|)
emit|;
if|if
condition|(
name|state
operator|==
name|QLocalSocket
operator|::
name|UnconnectedState
operator|&&
name|currentState
operator|!=
name|QLocalSocket
operator|::
name|ConnectingState
condition|)
name|q
operator|->
emit|emit
name|disconnected
argument_list|()
emit|;
block|}
emit|emit
name|q
operator|->
name|error
argument_list|(
name|error
argument_list|)
emit|;
block|}
end_function
begin_constructor
DECL|function|QLocalSocketPrivate
name|QLocalSocketPrivate
operator|::
name|QLocalSocketPrivate
parameter_list|()
member_init_list|:
name|QIODevicePrivate
argument_list|()
member_init_list|,
name|handle
argument_list|(
name|INVALID_HANDLE_VALUE
argument_list|)
member_init_list|,
name|pipeWriter
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|pipeReader
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|error
argument_list|(
name|QLocalSocket
operator|::
name|UnknownSocketError
argument_list|)
member_init_list|,
name|state
argument_list|(
name|QLocalSocket
operator|::
name|UnconnectedState
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QLocalSocketPrivate
name|QLocalSocketPrivate
operator|::
name|~
name|QLocalSocketPrivate
parameter_list|()
block|{
name|destroyPipeHandles
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|destroyPipeHandles
name|void
name|QLocalSocketPrivate
operator|::
name|destroyPipeHandles
parameter_list|()
block|{
if|if
condition|(
name|handle
operator|!=
name|INVALID_HANDLE_VALUE
condition|)
block|{
name|DisconnectNamedPipe
argument_list|(
name|handle
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|handle
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|connectToServer
name|void
name|QLocalSocket
operator|::
name|connectToServer
parameter_list|(
name|OpenMode
name|openMode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
argument_list|()
operator|==
name|ConnectedState
operator|||
name|state
argument_list|()
operator|==
name|ConnectingState
condition|)
block|{
name|setErrorString
argument_list|(
name|tr
argument_list|(
literal|"Trying to connect while connection is in progress"
argument_list|)
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|(
name|QLocalSocket
operator|::
name|OperationError
argument_list|)
emit|;
return|return;
block|}
name|d
operator|->
name|error
operator|=
name|QLocalSocket
operator|::
name|UnknownSocketError
expr_stmt|;
name|d
operator|->
name|errorString
operator|=
name|QString
argument_list|()
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|ConnectingState
expr_stmt|;
emit|emit
name|stateChanged
argument_list|(
name|d
operator|->
name|state
argument_list|)
emit|;
if|if
condition|(
name|d
operator|->
name|serverName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|d
operator|->
name|error
operator|=
name|QLocalSocket
operator|::
name|ServerNotFoundError
expr_stmt|;
name|setErrorString
argument_list|(
name|QLocalSocket
operator|::
name|tr
argument_list|(
literal|"%1: Invalid name"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalSocket::connectToServer"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|UnconnectedState
expr_stmt|;
emit|emit
name|error
argument_list|(
name|d
operator|->
name|error
argument_list|)
emit|;
emit|emit
name|stateChanged
argument_list|(
name|d
operator|->
name|state
argument_list|)
emit|;
return|return;
block|}
name|QString
name|pipePath
init|=
name|QLatin1String
argument_list|(
literal|"\\\\.\\pipe\\"
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|serverName
operator|.
name|startsWith
argument_list|(
name|pipePath
argument_list|)
condition|)
name|d
operator|->
name|fullServerName
operator|=
name|d
operator|->
name|serverName
expr_stmt|;
else|else
name|d
operator|->
name|fullServerName
operator|=
name|pipePath
operator|+
name|d
operator|->
name|serverName
expr_stmt|;
comment|// Try to open a named pipe
name|HANDLE
name|localSocket
decl_stmt|;
forever|forever
block|{
name|DWORD
name|permissions
init|=
operator|(
name|openMode
operator|&
name|QIODevice
operator|::
name|ReadOnly
operator|)
condition|?
name|GENERIC_READ
else|:
literal|0
decl_stmt|;
name|permissions
operator||=
operator|(
name|openMode
operator|&
name|QIODevice
operator|::
name|WriteOnly
operator|)
condition|?
name|GENERIC_WRITE
else|:
literal|0
expr_stmt|;
name|localSocket
operator|=
name|CreateFile
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|d
operator|->
name|fullServerName
operator|.
name|utf16
argument_list|()
argument_list|,
comment|// pipe name
name|permissions
argument_list|,
literal|0
argument_list|,
comment|// no sharing
name|NULL
argument_list|,
comment|// default security attributes
name|OPEN_EXISTING
argument_list|,
comment|// opens existing pipe
name|FILE_FLAG_OVERLAPPED
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// no template file
if|if
condition|(
name|localSocket
operator|!=
name|INVALID_HANDLE_VALUE
condition|)
break|break;
name|DWORD
name|error
init|=
name|GetLastError
argument_list|()
decl_stmt|;
comment|// It is really an error only if it is not ERROR_PIPE_BUSY
if|if
condition|(
name|ERROR_PIPE_BUSY
operator|!=
name|error
condition|)
block|{
break|break;
block|}
comment|// All pipe instances are busy, so wait until connected or up to 5 seconds.
if|if
condition|(
operator|!
name|WaitNamedPipe
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|d
operator|->
name|fullServerName
operator|.
name|utf16
argument_list|()
argument_list|,
literal|5000
argument_list|)
condition|)
break|break;
block|}
if|if
condition|(
name|localSocket
operator|==
name|INVALID_HANDLE_VALUE
condition|)
block|{
name|d
operator|->
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalSocket::connectToServer"
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|fullServerName
operator|=
name|QString
argument_list|()
expr_stmt|;
return|return;
block|}
comment|// we have a valid handle
if|if
condition|(
name|setSocketDescriptor
argument_list|(
operator|(
name|qintptr
operator|)
name|localSocket
argument_list|,
name|ConnectedState
argument_list|,
name|openMode
argument_list|)
condition|)
block|{
name|d
operator|->
name|handle
operator|=
name|localSocket
expr_stmt|;
emit|emit
name|connected
argument_list|()
emit|;
block|}
block|}
end_function
begin_comment
comment|// This is reading from the buffer
end_comment
begin_function
DECL|function|readData
name|qint64
name|QLocalSocket
operator|::
name|readData
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxSize
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|maxSize
condition|)
return|return
literal|0
return|;
return|return
name|d
operator|->
name|pipeReader
operator|->
name|read
argument_list|(
name|data
argument_list|,
name|maxSize
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|writeData
name|qint64
name|QLocalSocket
operator|::
name|writeData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxSize
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|pipeWriter
condition|)
block|{
name|d
operator|->
name|pipeWriter
operator|=
operator|new
name|QWindowsPipeWriter
argument_list|(
name|d
operator|->
name|handle
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|pipeWriter
argument_list|,
name|SIGNAL
argument_list|(
name|canWrite
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_canWrite
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|pipeWriter
argument_list|,
name|SIGNAL
argument_list|(
name|bytesWritten
argument_list|(
name|qint64
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|bytesWritten
argument_list|(
name|qint64
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|pipeWriter
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
return|return
name|d
operator|->
name|pipeWriter
operator|->
name|write
argument_list|(
name|data
argument_list|,
name|maxSize
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|abort
name|void
name|QLocalSocket
operator|::
name|abort
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|pipeWriter
condition|)
block|{
operator|delete
name|d
operator|->
name|pipeWriter
expr_stmt|;
name|d
operator|->
name|pipeWriter
operator|=
literal|0
expr_stmt|;
block|}
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_pipeClosed
name|void
name|QLocalSocketPrivate
operator|::
name|_q_pipeClosed
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|==
name|QLocalSocket
operator|::
name|UnconnectedState
condition|)
return|return;
emit|emit
name|q
operator|->
name|readChannelFinished
argument_list|()
emit|;
if|if
condition|(
name|state
operator|!=
name|QLocalSocket
operator|::
name|ClosingState
condition|)
block|{
name|state
operator|=
name|QLocalSocket
operator|::
name|ClosingState
expr_stmt|;
emit|emit
name|q
operator|->
name|stateChanged
argument_list|(
name|state
argument_list|)
emit|;
if|if
condition|(
name|state
operator|!=
name|QLocalSocket
operator|::
name|ClosingState
condition|)
return|return;
block|}
name|state
operator|=
name|QLocalSocket
operator|::
name|UnconnectedState
expr_stmt|;
emit|emit
name|q
operator|->
name|stateChanged
argument_list|(
name|state
argument_list|)
emit|;
emit|emit
name|q
operator|->
name|disconnected
argument_list|()
emit|;
name|pipeReader
operator|->
name|stop
argument_list|()
expr_stmt|;
name|destroyPipeHandles
argument_list|()
expr_stmt|;
name|handle
operator|=
name|INVALID_HANDLE_VALUE
expr_stmt|;
if|if
condition|(
name|pipeWriter
condition|)
block|{
operator|delete
name|pipeWriter
expr_stmt|;
name|pipeWriter
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|bytesAvailable
name|qint64
name|QLocalSocket
operator|::
name|bytesAvailable
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
name|qint64
name|available
init|=
name|QIODevice
operator|::
name|bytesAvailable
argument_list|()
decl_stmt|;
name|available
operator|+=
name|d
operator|->
name|pipeReader
operator|->
name|bytesAvailable
argument_list|()
expr_stmt|;
return|return
name|available
return|;
block|}
end_function
begin_function
DECL|function|bytesToWrite
name|qint64
name|QLocalSocket
operator|::
name|bytesToWrite
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
operator|(
name|d
operator|->
name|pipeWriter
operator|)
condition|?
name|d
operator|->
name|pipeWriter
operator|->
name|bytesToWrite
argument_list|()
else|:
literal|0
return|;
block|}
end_function
begin_function
DECL|function|canReadLine
name|bool
name|QLocalSocket
operator|::
name|canReadLine
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|QIODevice
operator|::
name|canReadLine
argument_list|()
operator|||
name|d
operator|->
name|pipeReader
operator|->
name|canReadLine
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|close
name|void
name|QLocalSocket
operator|::
name|close
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
name|openMode
argument_list|()
operator|==
name|NotOpen
condition|)
return|return;
name|QIODevice
operator|::
name|close
argument_list|()
expr_stmt|;
name|d
operator|->
name|serverName
operator|=
name|QString
argument_list|()
expr_stmt|;
name|d
operator|->
name|fullServerName
operator|=
name|QString
argument_list|()
expr_stmt|;
if|if
condition|(
name|state
argument_list|()
operator|!=
name|UnconnectedState
condition|)
block|{
if|if
condition|(
name|bytesToWrite
argument_list|()
operator|>
literal|0
condition|)
block|{
name|disconnectFromServer
argument_list|()
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|_q_pipeClosed
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|flush
name|bool
name|QLocalSocket
operator|::
name|flush
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|pipeWriter
condition|)
return|return
name|d
operator|->
name|pipeWriter
operator|->
name|waitForWrite
argument_list|(
literal|0
argument_list|)
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|disconnectFromServer
name|void
name|QLocalSocket
operator|::
name|disconnectFromServer
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
comment|// Are we still connected?
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
block|{
comment|// If we have unwritten data, the pipeWriter is still present.
comment|// It must be destroyed before close() to prevent an infinite loop.
operator|delete
name|d
operator|->
name|pipeWriter
expr_stmt|;
name|d
operator|->
name|pipeWriter
operator|=
literal|0
expr_stmt|;
block|}
name|flush
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|pipeWriter
operator|&&
name|d
operator|->
name|pipeWriter
operator|->
name|bytesToWrite
argument_list|()
operator|!=
literal|0
condition|)
block|{
name|d
operator|->
name|state
operator|=
name|QLocalSocket
operator|::
name|ClosingState
expr_stmt|;
emit|emit
name|stateChanged
argument_list|(
name|d
operator|->
name|state
argument_list|)
emit|;
block|}
else|else
block|{
name|close
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|error
name|QLocalSocket
operator|::
name|LocalSocketError
name|QLocalSocket
operator|::
name|error
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|error
return|;
block|}
end_function
begin_function
DECL|function|setSocketDescriptor
name|bool
name|QLocalSocket
operator|::
name|setSocketDescriptor
parameter_list|(
name|qintptr
name|socketDescriptor
parameter_list|,
name|LocalSocketState
name|socketState
parameter_list|,
name|OpenMode
name|openMode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
name|d
operator|->
name|pipeReader
operator|->
name|stop
argument_list|()
expr_stmt|;
name|d
operator|->
name|handle
operator|=
cast|reinterpret_cast
argument_list|<
name|HANDLE
argument_list|>
argument_list|(
name|socketDescriptor
argument_list|)
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|socketState
expr_stmt|;
name|d
operator|->
name|pipeReader
operator|->
name|setHandle
argument_list|(
name|d
operator|->
name|handle
argument_list|)
expr_stmt|;
name|QIODevice
operator|::
name|open
argument_list|(
name|openMode
argument_list|)
expr_stmt|;
emit|emit
name|stateChanged
argument_list|(
name|d
operator|->
name|state
argument_list|)
emit|;
if|if
condition|(
name|d
operator|->
name|state
operator|==
name|ConnectedState
operator|&&
name|openMode
operator|.
name|testFlag
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
name|d
operator|->
name|pipeReader
operator|->
name|startAsyncRead
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|_q_canWrite
name|void
name|QLocalSocketPrivate
operator|::
name|_q_canWrite
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|==
name|QLocalSocket
operator|::
name|ClosingState
condition|)
name|q
operator|->
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|socketDescriptor
name|qintptr
name|QLocalSocket
operator|::
name|socketDescriptor
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
operator|(
name|qintptr
operator|)
name|d
operator|->
name|handle
return|;
block|}
end_function
begin_function
DECL|function|readBufferSize
name|qint64
name|QLocalSocket
operator|::
name|readBufferSize
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|pipeReader
operator|->
name|maxReadBufferSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setReadBufferSize
name|void
name|QLocalSocket
operator|::
name|setReadBufferSize
parameter_list|(
name|qint64
name|size
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
name|d
operator|->
name|pipeReader
operator|->
name|setMaxReadBufferSize
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForConnected
name|bool
name|QLocalSocket
operator|::
name|waitForConnected
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|msecs
argument_list|)
expr_stmt|;
return|return
operator|(
name|state
argument_list|()
operator|==
name|ConnectedState
operator|)
return|;
block|}
end_function
begin_function
DECL|function|waitForDisconnected
name|bool
name|QLocalSocket
operator|::
name|waitForDisconnected
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
argument_list|()
operator|==
name|UnconnectedState
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|openMode
argument_list|()
operator|.
name|testFlag
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QLocalSocket::waitForDisconnected isn't supported for write only pipes."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|d
operator|->
name|pipeReader
operator|->
name|waitForPipeClosed
argument_list|(
name|msecs
argument_list|)
condition|)
block|{
name|d
operator|->
name|_q_pipeClosed
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|isValid
name|bool
name|QLocalSocket
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|handle
operator|!=
name|INVALID_HANDLE_VALUE
return|;
block|}
end_function
begin_function
DECL|function|waitForReadyRead
name|bool
name|QLocalSocket
operator|::
name|waitForReadyRead
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
name|bytesAvailable
argument_list|()
operator|>
literal|0
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|d
operator|->
name|state
operator|!=
name|QLocalSocket
operator|::
name|ConnectedState
condition|)
return|return
literal|false
return|;
comment|// We already know that the pipe is gone, but did not enter the event loop yet.
if|if
condition|(
name|d
operator|->
name|pipeReader
operator|->
name|isPipeClosed
argument_list|()
condition|)
block|{
name|d
operator|->
name|_q_pipeClosed
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
name|bool
name|result
init|=
name|d
operator|->
name|pipeReader
operator|->
name|waitForReadyRead
argument_list|(
name|msecs
argument_list|)
decl_stmt|;
comment|// We just noticed that the pipe is gone.
if|if
condition|(
name|d
operator|->
name|pipeReader
operator|->
name|isPipeClosed
argument_list|()
condition|)
name|d
operator|->
name|_q_pipeClosed
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|waitForBytesWritten
name|bool
name|QLocalSocket
operator|::
name|waitForBytesWritten
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalSocket
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|pipeWriter
condition|)
return|return
literal|false
return|;
comment|// Wait for the pipe writer to acknowledge that it has
comment|// written. This will succeed if either the pipe writer has
comment|// already written the data, or if it manages to write data
comment|// within the given timeout.
return|return
name|d
operator|->
name|pipeWriter
operator|->
name|waitForWrite
argument_list|(
name|msecs
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
