begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowspipereader_p.h"
end_include
begin_include
include|#
directive|include
file|"qwinoverlappedionotifier_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
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
file|<qtimer.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QWindowsPipeReader
name|QWindowsPipeReader
operator|::
name|QWindowsPipeReader
parameter_list|(
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
name|handle
argument_list|(
name|INVALID_HANDLE_VALUE
argument_list|)
member_init_list|,
name|readBufferMaxSize
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|actualReadBufferSize
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|readSequenceStarted
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|emitReadyReadTimer
argument_list|(
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
argument_list|)
member_init_list|,
name|pipeBroken
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|readyReadEmitted
argument_list|(
literal|false
argument_list|)
block|{
name|emitReadyReadTimer
operator|->
name|setSingleShot
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|emitReadyReadTimer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
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
name|dataReadNotifier
operator|=
operator|new
name|QWinOverlappedIoNotifier
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|dataReadNotifier
argument_list|,
operator|&
name|QWinOverlappedIoNotifier
operator|::
name|notified
argument_list|,
name|this
argument_list|,
operator|&
name|QWindowsPipeReader
operator|::
name|notified
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|qt_cancelIo
specifier|static
name|void
name|qt_cancelIo
parameter_list|(
name|HANDLE
name|handle
parameter_list|,
name|OVERLAPPED
modifier|*
name|overlapped
parameter_list|)
block|{
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PtrCancelIoEx
function_decl|)
parameter_list|(
name|HANDLE
parameter_list|,
name|LPOVERLAPPED
parameter_list|)
function_decl|;
specifier|static
name|PtrCancelIoEx
name|ptrCancelIoEx
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|ptrCancelIoEx
condition|)
block|{
name|HMODULE
name|kernel32
init|=
name|GetModuleHandleA
argument_list|(
literal|"kernel32"
argument_list|)
decl_stmt|;
if|if
condition|(
name|kernel32
condition|)
name|ptrCancelIoEx
operator|=
name|PtrCancelIoEx
argument_list|(
name|GetProcAddress
argument_list|(
name|kernel32
argument_list|,
literal|"CancelIoEx"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ptrCancelIoEx
condition|)
name|ptrCancelIoEx
argument_list|(
name|handle
argument_list|,
name|overlapped
argument_list|)
expr_stmt|;
else|else
name|CancelIo
argument_list|(
name|handle
argument_list|)
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~QWindowsPipeReader
name|QWindowsPipeReader
operator|::
name|~
name|QWindowsPipeReader
parameter_list|()
block|{
if|if
condition|(
name|readSequenceStarted
condition|)
block|{
name|qt_cancelIo
argument_list|(
name|handle
argument_list|,
operator|&
name|overlapped
argument_list|)
expr_stmt|;
name|dataReadNotifier
operator|->
name|waitForNotified
argument_list|(
operator|-
literal|1
argument_list|,
operator|&
name|overlapped
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_comment
comment|/*!     Sets the handle to read from. The handle must be valid.  */
end_comment
begin_function
DECL|function|setHandle
name|void
name|QWindowsPipeReader
operator|::
name|setHandle
parameter_list|(
name|HANDLE
name|hPipeReadEnd
parameter_list|)
block|{
name|readBuffer
operator|.
name|clear
argument_list|()
expr_stmt|;
name|actualReadBufferSize
operator|=
literal|0
expr_stmt|;
name|handle
operator|=
name|hPipeReadEnd
expr_stmt|;
name|ZeroMemory
argument_list|(
operator|&
name|overlapped
argument_list|,
sizeof|sizeof
argument_list|(
name|overlapped
argument_list|)
argument_list|)
expr_stmt|;
name|pipeBroken
operator|=
literal|false
expr_stmt|;
name|readyReadEmitted
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|hPipeReadEnd
operator|!=
name|INVALID_HANDLE_VALUE
condition|)
block|{
name|dataReadNotifier
operator|->
name|setHandle
argument_list|(
name|hPipeReadEnd
argument_list|)
expr_stmt|;
name|dataReadNotifier
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Stops the asynchronous read sequence.     This function assumes that the file already has been closed.     It does not cancel any I/O operation.  */
end_comment
begin_function
DECL|function|stop
name|void
name|QWindowsPipeReader
operator|::
name|stop
parameter_list|()
block|{
name|dataReadNotifier
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|readSequenceStarted
operator|=
literal|false
expr_stmt|;
name|handle
operator|=
name|INVALID_HANDLE_VALUE
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of bytes we've read so far.  */
end_comment
begin_function
DECL|function|bytesAvailable
name|qint64
name|QWindowsPipeReader
operator|::
name|bytesAvailable
parameter_list|()
specifier|const
block|{
return|return
name|actualReadBufferSize
return|;
block|}
end_function
begin_comment
comment|/*!     Stops the asynchronous read sequence.  */
end_comment
begin_function
DECL|function|read
name|qint64
name|QWindowsPipeReader
operator|::
name|read
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
block|{
if|if
condition|(
name|pipeBroken
operator|&&
name|actualReadBufferSize
operator|==
literal|0
condition|)
return|return
operator|-
literal|1
return|;
comment|// signal EOF
name|qint64
name|readSoFar
decl_stmt|;
comment|// If startAsyncRead() has read data, copy it to its destination.
if|if
condition|(
name|maxlen
operator|==
literal|1
operator|&&
name|actualReadBufferSize
operator|>
literal|0
condition|)
block|{
operator|*
name|data
operator|=
name|readBuffer
operator|.
name|getChar
argument_list|()
expr_stmt|;
name|actualReadBufferSize
operator|--
expr_stmt|;
name|readSoFar
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|qint64
name|bytesToRead
init|=
name|qMin
argument_list|(
name|qint64
argument_list|(
name|actualReadBufferSize
argument_list|)
argument_list|,
name|maxlen
argument_list|)
decl_stmt|;
name|readSoFar
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|readSoFar
operator|<
name|bytesToRead
condition|)
block|{
specifier|const
name|char
modifier|*
name|ptr
init|=
name|readBuffer
operator|.
name|readPointer
argument_list|()
decl_stmt|;
name|int
name|bytesToReadFromThisBlock
init|=
name|qMin
argument_list|(
name|bytesToRead
operator|-
name|readSoFar
argument_list|,
name|qint64
argument_list|(
name|readBuffer
operator|.
name|nextDataBlockSize
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|data
operator|+
name|readSoFar
argument_list|,
name|ptr
argument_list|,
name|bytesToReadFromThisBlock
argument_list|)
expr_stmt|;
name|readSoFar
operator|+=
name|bytesToReadFromThisBlock
expr_stmt|;
name|readBuffer
operator|.
name|free
argument_list|(
name|bytesToReadFromThisBlock
argument_list|)
expr_stmt|;
name|actualReadBufferSize
operator|-=
name|bytesToReadFromThisBlock
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|pipeBroken
condition|)
block|{
if|if
condition|(
operator|!
name|actualReadBufferSize
condition|)
name|emitReadyReadTimer
operator|->
name|stop
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|readSequenceStarted
condition|)
name|startAsyncRead
argument_list|()
expr_stmt|;
block|}
return|return
name|readSoFar
return|;
block|}
end_function
begin_function
DECL|function|canReadLine
name|bool
name|QWindowsPipeReader
operator|::
name|canReadLine
parameter_list|()
specifier|const
block|{
return|return
name|readBuffer
operator|.
name|indexOf
argument_list|(
literal|'\n'
argument_list|,
name|actualReadBufferSize
argument_list|)
operator|>=
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     \internal     Will be called whenever the read operation completes.  */
end_comment
begin_function
DECL|function|notified
name|void
name|QWindowsPipeReader
operator|::
name|notified
parameter_list|(
name|DWORD
name|numberOfBytesRead
parameter_list|,
name|DWORD
name|errorCode
parameter_list|,
name|OVERLAPPED
modifier|*
name|notifiedOverlapped
parameter_list|)
block|{
if|if
condition|(
operator|&
name|overlapped
operator|!=
name|notifiedOverlapped
condition|)
return|return;
if|if
condition|(
operator|!
name|completeAsyncRead
argument_list|(
name|numberOfBytesRead
argument_list|,
name|errorCode
argument_list|)
condition|)
block|{
name|pipeBroken
operator|=
literal|true
expr_stmt|;
emit|emit
name|pipeClosed
argument_list|()
emit|;
return|return;
block|}
name|startAsyncRead
argument_list|()
expr_stmt|;
name|emitReadyReadTimer
operator|->
name|stop
argument_list|()
expr_stmt|;
name|readyReadEmitted
operator|=
literal|true
expr_stmt|;
emit|emit
name|readyRead
argument_list|()
emit|;
block|}
end_function
begin_comment
comment|/*!     \internal     Reads data from the socket into the readbuffer  */
end_comment
begin_function
DECL|function|startAsyncRead
name|void
name|QWindowsPipeReader
operator|::
name|startAsyncRead
parameter_list|()
block|{
specifier|const
name|DWORD
name|minReadBufferSize
init|=
literal|4096
decl_stmt|;
name|DWORD
name|bytesToRead
init|=
name|qMax
argument_list|(
name|checkPipeState
argument_list|()
argument_list|,
name|minReadBufferSize
argument_list|)
decl_stmt|;
if|if
condition|(
name|pipeBroken
condition|)
return|return;
if|if
condition|(
name|readBufferMaxSize
operator|&&
name|bytesToRead
operator|>
operator|(
name|readBufferMaxSize
operator|-
name|readBuffer
operator|.
name|size
argument_list|()
operator|)
condition|)
block|{
name|bytesToRead
operator|=
name|readBufferMaxSize
operator|-
name|readBuffer
operator|.
name|size
argument_list|()
expr_stmt|;
if|if
condition|(
name|bytesToRead
operator|==
literal|0
condition|)
block|{
comment|// Buffer is full. User must read data from the buffer
comment|// before we can read more from the pipe.
return|return;
block|}
block|}
name|char
modifier|*
name|ptr
init|=
name|readBuffer
operator|.
name|reserve
argument_list|(
name|bytesToRead
argument_list|)
decl_stmt|;
name|readSequenceStarted
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|ReadFile
argument_list|(
name|handle
argument_list|,
name|ptr
argument_list|,
name|bytesToRead
argument_list|,
name|NULL
argument_list|,
operator|&
name|overlapped
argument_list|)
condition|)
block|{
comment|// We get notified by the QWinOverlappedIoNotifier - even in the synchronous case.
return|return;
block|}
else|else
block|{
specifier|const
name|DWORD
name|dwError
init|=
name|GetLastError
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|dwError
condition|)
block|{
case|case
name|ERROR_IO_PENDING
case|:
comment|// This is not an error. We're getting notified, when data arrives.
return|return;
case|case
name|ERROR_MORE_DATA
case|:
comment|// This is not an error. The synchronous read succeeded.
comment|// We're connected to a message mode pipe and the message
comment|// didn't fit into the pipe's system buffer.
comment|// We're getting notified by the QWinOverlappedIoNotifier.
break|break;
case|case
name|ERROR_BROKEN_PIPE
case|:
case|case
name|ERROR_PIPE_NOT_CONNECTED
case|:
block|{
comment|// It may happen, that the other side closes the connection directly
comment|// after writing data. Then we must set the appropriate socket state.
name|readSequenceStarted
operator|=
literal|false
expr_stmt|;
name|pipeBroken
operator|=
literal|true
expr_stmt|;
emit|emit
name|pipeClosed
argument_list|()
emit|;
return|return;
block|}
default|default:
name|readSequenceStarted
operator|=
literal|false
expr_stmt|;
emit|emit
name|winError
argument_list|(
name|dwError
argument_list|,
name|QLatin1String
argument_list|(
literal|"QWindowsPipeReader::startAsyncRead"
argument_list|)
argument_list|)
emit|;
return|return;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!     \internal     Sets the correct size of the read buffer after a read operation.     Returns false, if an error occurred or the connection dropped.  */
end_comment
begin_function
DECL|function|completeAsyncRead
name|bool
name|QWindowsPipeReader
operator|::
name|completeAsyncRead
parameter_list|(
name|DWORD
name|bytesRead
parameter_list|,
name|DWORD
name|errorCode
parameter_list|)
block|{
name|readSequenceStarted
operator|=
literal|false
expr_stmt|;
switch|switch
condition|(
name|errorCode
condition|)
block|{
case|case
name|ERROR_SUCCESS
case|:
break|break;
case|case
name|ERROR_MORE_DATA
case|:
comment|// This is not an error. We're connected to a message mode
comment|// pipe and the message didn't fit into the pipe's system
comment|// buffer. We will read the remaining data in the next call.
break|break;
case|case
name|ERROR_BROKEN_PIPE
case|:
case|case
name|ERROR_PIPE_NOT_CONNECTED
case|:
return|return
literal|false
return|;
default|default:
emit|emit
name|winError
argument_list|(
name|errorCode
argument_list|,
name|QLatin1String
argument_list|(
literal|"QWindowsPipeReader::completeAsyncRead"
argument_list|)
argument_list|)
emit|;
return|return
literal|false
return|;
block|}
name|actualReadBufferSize
operator|+=
name|bytesRead
expr_stmt|;
name|readBuffer
operator|.
name|truncate
argument_list|(
name|actualReadBufferSize
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|emitReadyReadTimer
operator|->
name|isActive
argument_list|()
condition|)
name|emitReadyReadTimer
operator|->
name|start
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     \internal     Returns the number of available bytes in the pipe.     Sets QWindowsPipeReader::pipeBroken to true if the connection is broken.  */
end_comment
begin_function
DECL|function|checkPipeState
name|DWORD
name|QWindowsPipeReader
operator|::
name|checkPipeState
parameter_list|()
block|{
name|DWORD
name|bytes
decl_stmt|;
if|if
condition|(
name|PeekNamedPipe
argument_list|(
name|handle
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
operator|&
name|bytes
argument_list|,
name|NULL
argument_list|)
condition|)
block|{
return|return
name|bytes
return|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|pipeBroken
condition|)
block|{
name|pipeBroken
operator|=
literal|true
expr_stmt|;
emit|emit
name|pipeClosed
argument_list|()
emit|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Waits for the completion of the asynchronous read operation.     Returns true, if we've emitted the readyRead signal.  */
end_comment
begin_function
DECL|function|waitForReadyRead
name|bool
name|QWindowsPipeReader
operator|::
name|waitForReadyRead
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
if|if
condition|(
operator|!
name|readSequenceStarted
condition|)
return|return
literal|false
return|;
name|readyReadEmitted
operator|=
literal|false
expr_stmt|;
name|dataReadNotifier
operator|->
name|waitForNotified
argument_list|(
name|msecs
argument_list|,
operator|&
name|overlapped
argument_list|)
expr_stmt|;
return|return
name|readyReadEmitted
return|;
block|}
end_function
begin_comment
comment|/*!     Waits until the pipe is closed.  */
end_comment
begin_function
DECL|function|waitForPipeClosed
name|bool
name|QWindowsPipeReader
operator|::
name|waitForPipeClosed
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
specifier|const
name|int
name|sleepTime
init|=
literal|10
decl_stmt|;
name|QElapsedTimer
name|stopWatch
decl_stmt|;
name|stopWatch
operator|.
name|start
argument_list|()
expr_stmt|;
forever|forever
block|{
name|checkPipeState
argument_list|()
expr_stmt|;
if|if
condition|(
name|pipeBroken
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|stopWatch
operator|.
name|hasExpired
argument_list|(
name|msecs
operator|-
name|sleepTime
argument_list|)
condition|)
return|return
literal|false
return|;
name|Sleep
argument_list|(
name|sleepTime
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
