begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"filemanager.h"
end_include
begin_include
include|#
directive|include
file|"metainfo.h"
end_include
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QTimerEvent>
end_include
begin_include
include|#
directive|include
file|<QCryptographicHash>
end_include
begin_constructor
DECL|function|FileManager
name|FileManager
operator|::
name|FileManager
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
block|{
name|quit
operator|=
literal|false
expr_stmt|;
name|totalLength
operator|=
literal|0
expr_stmt|;
name|readId
operator|=
literal|0
expr_stmt|;
name|startVerification
operator|=
literal|false
expr_stmt|;
name|wokeUp
operator|=
literal|false
expr_stmt|;
name|newFile
operator|=
literal|false
expr_stmt|;
name|numPieces
operator|=
literal|0
expr_stmt|;
name|verifiedPieces
operator|.
name|fill
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~FileManager
name|FileManager
operator|::
name|~
name|FileManager
parameter_list|()
block|{
name|quit
operator|=
literal|true
expr_stmt|;
name|cond
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
name|wait
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|QFile
modifier|*
name|file
decl|,
name|files
control|)
block|{
name|file
operator|->
name|close
argument_list|()
expr_stmt|;
operator|delete
name|file
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|read
name|int
name|FileManager
operator|::
name|read
parameter_list|(
name|int
name|pieceIndex
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|length
parameter_list|)
block|{
name|ReadRequest
name|request
decl_stmt|;
name|request
operator|.
name|pieceIndex
operator|=
name|pieceIndex
expr_stmt|;
name|request
operator|.
name|offset
operator|=
name|offset
expr_stmt|;
name|request
operator|.
name|length
operator|=
name|length
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|request
operator|.
name|id
operator|=
name|readId
operator|++
expr_stmt|;
name|readRequests
operator|<<
name|request
expr_stmt|;
if|if
condition|(
operator|!
name|wokeUp
condition|)
block|{
name|wokeUp
operator|=
literal|true
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"wakeUp"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
return|return
name|request
operator|.
name|id
return|;
block|}
end_function
begin_function
DECL|function|write
name|void
name|FileManager
operator|::
name|write
parameter_list|(
name|int
name|pieceIndex
parameter_list|,
name|int
name|offset
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|WriteRequest
name|request
decl_stmt|;
name|request
operator|.
name|pieceIndex
operator|=
name|pieceIndex
expr_stmt|;
name|request
operator|.
name|offset
operator|=
name|offset
expr_stmt|;
name|request
operator|.
name|data
operator|=
name|data
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|writeRequests
operator|<<
name|request
expr_stmt|;
if|if
condition|(
operator|!
name|wokeUp
condition|)
block|{
name|wokeUp
operator|=
literal|true
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"wakeUp"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|verifyPiece
name|void
name|FileManager
operator|::
name|verifyPiece
parameter_list|(
name|int
name|pieceIndex
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|pendingVerificationRequests
operator|<<
name|pieceIndex
expr_stmt|;
name|startVerification
operator|=
literal|true
expr_stmt|;
if|if
condition|(
operator|!
name|wokeUp
condition|)
block|{
name|wokeUp
operator|=
literal|true
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"wakeUp"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|pieceLengthAt
name|int
name|FileManager
operator|::
name|pieceLengthAt
parameter_list|(
name|int
name|pieceIndex
parameter_list|)
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
return|return
operator|(
name|sha1s
operator|.
name|size
argument_list|()
operator|==
name|pieceIndex
operator|+
literal|1
operator|)
condition|?
operator|(
name|totalLength
operator|%
name|pieceLength
operator|)
else|:
name|pieceLength
return|;
block|}
end_function
begin_function
DECL|function|completedPieces
name|QBitArray
name|FileManager
operator|::
name|completedPieces
parameter_list|()
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
return|return
name|verifiedPieces
return|;
block|}
end_function
begin_function
DECL|function|setCompletedPieces
name|void
name|FileManager
operator|::
name|setCompletedPieces
parameter_list|(
specifier|const
name|QBitArray
modifier|&
name|pieces
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|verifiedPieces
operator|=
name|pieces
expr_stmt|;
block|}
end_function
begin_function
DECL|function|errorString
name|QString
name|FileManager
operator|::
name|errorString
parameter_list|()
specifier|const
block|{
return|return
name|errString
return|;
block|}
end_function
begin_function
DECL|function|run
name|void
name|FileManager
operator|::
name|run
parameter_list|()
block|{
if|if
condition|(
operator|!
name|generateFiles
argument_list|()
condition|)
return|return;
do|do
block|{
block|{
comment|// Go to sleep if there's nothing to do.
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|quit
operator|&&
name|readRequests
operator|.
name|isEmpty
argument_list|()
operator|&&
name|writeRequests
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|startVerification
condition|)
name|cond
operator|.
name|wait
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
block|}
comment|// Read pending read requests
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|ReadRequest
argument_list|>
name|newReadRequests
init|=
name|readRequests
decl_stmt|;
name|readRequests
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|newReadRequests
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|ReadRequest
name|request
init|=
name|newReadRequests
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
name|QByteArray
name|block
init|=
name|readBlock
argument_list|(
name|request
operator|.
name|pieceIndex
argument_list|,
name|request
operator|.
name|offset
argument_list|,
name|request
operator|.
name|length
argument_list|)
decl_stmt|;
emit|emit
name|dataRead
argument_list|(
name|request
operator|.
name|id
argument_list|,
name|request
operator|.
name|pieceIndex
argument_list|,
name|request
operator|.
name|offset
argument_list|,
name|block
argument_list|)
emit|;
block|}
comment|// Write pending write requests
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|WriteRequest
argument_list|>
name|newWriteRequests
init|=
name|writeRequests
decl_stmt|;
name|writeRequests
operator|.
name|clear
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|quit
operator|&&
operator|!
name|newWriteRequests
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|WriteRequest
name|request
init|=
name|newWriteRequests
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
name|writeBlock
argument_list|(
name|request
operator|.
name|pieceIndex
argument_list|,
name|request
operator|.
name|offset
argument_list|,
name|request
operator|.
name|data
argument_list|)
expr_stmt|;
block|}
comment|// Process pending verification requests
if|if
condition|(
name|startVerification
condition|)
block|{
name|newPendingVerificationRequests
operator|=
name|pendingVerificationRequests
expr_stmt|;
name|pendingVerificationRequests
operator|.
name|clear
argument_list|()
expr_stmt|;
name|verifyFileContents
argument_list|()
expr_stmt|;
name|startVerification
operator|=
literal|false
expr_stmt|;
block|}
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|newPendingVerificationRequests
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|quit
condition|)
do|;
comment|// Write pending write requests
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|WriteRequest
argument_list|>
name|newWriteRequests
init|=
name|writeRequests
decl_stmt|;
name|writeRequests
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|newWriteRequests
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|WriteRequest
name|request
init|=
name|newWriteRequests
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
name|writeBlock
argument_list|(
name|request
operator|.
name|pieceIndex
argument_list|,
name|request
operator|.
name|offset
argument_list|,
name|request
operator|.
name|data
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|startDataVerification
name|void
name|FileManager
operator|::
name|startDataVerification
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|startVerification
operator|=
literal|true
expr_stmt|;
name|cond
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|generateFiles
name|bool
name|FileManager
operator|::
name|generateFiles
parameter_list|()
block|{
name|numPieces
operator|=
operator|-
literal|1
expr_stmt|;
comment|// Set up the thread local data
if|if
condition|(
name|metaInfo
operator|.
name|fileForm
argument_list|()
operator|==
name|MetaInfo
operator|::
name|SingleFileForm
condition|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|MetaInfoSingleFile
name|singleFile
init|=
name|metaInfo
operator|.
name|singleFile
argument_list|()
decl_stmt|;
name|QString
name|prefix
decl_stmt|;
if|if
condition|(
operator|!
name|destinationPath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|prefix
operator|=
name|destinationPath
expr_stmt|;
if|if
condition|(
operator|!
name|prefix
operator|.
name|endsWith
argument_list|(
literal|"/"
argument_list|)
condition|)
name|prefix
operator|+=
literal|"/"
expr_stmt|;
name|QDir
name|dir
decl_stmt|;
if|if
condition|(
operator|!
name|dir
operator|.
name|mkpath
argument_list|(
name|prefix
argument_list|)
condition|)
block|{
name|errString
operator|=
name|tr
argument_list|(
literal|"Failed to create directory %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|prefix
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|()
emit|;
return|return
literal|false
return|;
block|}
block|}
name|QFile
modifier|*
name|file
init|=
operator|new
name|QFile
argument_list|(
name|prefix
operator|+
name|singleFile
operator|.
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|->
name|open
argument_list|(
name|QFile
operator|::
name|ReadWrite
argument_list|)
condition|)
block|{
name|errString
operator|=
name|tr
argument_list|(
literal|"Failed to open/create file %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|fileName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|()
emit|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|file
operator|->
name|size
argument_list|()
operator|!=
name|singleFile
operator|.
name|length
condition|)
block|{
name|newFile
operator|=
literal|true
expr_stmt|;
if|if
condition|(
operator|!
name|file
operator|->
name|resize
argument_list|(
name|singleFile
operator|.
name|length
argument_list|)
condition|)
block|{
name|errString
operator|=
name|tr
argument_list|(
literal|"Failed to resize file %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|fileName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|()
emit|;
return|return
literal|false
return|;
block|}
block|}
name|fileSizes
operator|<<
name|file
operator|->
name|size
argument_list|()
expr_stmt|;
name|files
operator|<<
name|file
expr_stmt|;
name|file
operator|->
name|close
argument_list|()
expr_stmt|;
name|pieceLength
operator|=
name|singleFile
operator|.
name|pieceLength
expr_stmt|;
name|totalLength
operator|=
name|singleFile
operator|.
name|length
expr_stmt|;
name|sha1s
operator|=
name|singleFile
operator|.
name|sha1Sums
expr_stmt|;
block|}
else|else
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|QDir
name|dir
decl_stmt|;
name|QString
name|prefix
decl_stmt|;
if|if
condition|(
operator|!
name|destinationPath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|prefix
operator|=
name|destinationPath
expr_stmt|;
if|if
condition|(
operator|!
name|prefix
operator|.
name|endsWith
argument_list|(
literal|"/"
argument_list|)
condition|)
name|prefix
operator|+=
literal|"/"
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|metaInfo
operator|.
name|name
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|prefix
operator|+=
name|metaInfo
operator|.
name|name
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|prefix
operator|.
name|endsWith
argument_list|(
literal|"/"
argument_list|)
condition|)
name|prefix
operator|+=
literal|"/"
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|dir
operator|.
name|mkpath
argument_list|(
name|prefix
argument_list|)
condition|)
block|{
name|errString
operator|=
name|tr
argument_list|(
literal|"Failed to create directory %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|prefix
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|()
emit|;
return|return
literal|false
return|;
block|}
foreach|foreach
control|(
specifier|const
name|MetaInfoMultiFile
modifier|&
name|entry
decl|,
name|metaInfo
operator|.
name|multiFiles
argument_list|()
control|)
block|{
name|QString
name|filePath
init|=
name|QFileInfo
argument_list|(
name|prefix
operator|+
name|entry
operator|.
name|path
argument_list|)
operator|.
name|path
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|filePath
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|dir
operator|.
name|mkpath
argument_list|(
name|filePath
argument_list|)
condition|)
block|{
name|errString
operator|=
name|tr
argument_list|(
literal|"Failed to create directory %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|filePath
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|()
emit|;
return|return
literal|false
return|;
block|}
block|}
name|QFile
modifier|*
name|file
init|=
operator|new
name|QFile
argument_list|(
name|prefix
operator|+
name|entry
operator|.
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|->
name|open
argument_list|(
name|QFile
operator|::
name|ReadWrite
argument_list|)
condition|)
block|{
name|errString
operator|=
name|tr
argument_list|(
literal|"Failed to open/create file %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|fileName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|()
emit|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|file
operator|->
name|size
argument_list|()
operator|!=
name|entry
operator|.
name|length
condition|)
block|{
name|newFile
operator|=
literal|true
expr_stmt|;
if|if
condition|(
operator|!
name|file
operator|->
name|resize
argument_list|(
name|entry
operator|.
name|length
argument_list|)
condition|)
block|{
name|errString
operator|=
name|tr
argument_list|(
literal|"Failed to resize file %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|fileName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|()
emit|;
return|return
literal|false
return|;
block|}
block|}
name|fileSizes
operator|<<
name|file
operator|->
name|size
argument_list|()
expr_stmt|;
name|files
operator|<<
name|file
expr_stmt|;
name|file
operator|->
name|close
argument_list|()
expr_stmt|;
name|totalLength
operator|+=
name|entry
operator|.
name|length
expr_stmt|;
block|}
name|sha1s
operator|=
name|metaInfo
operator|.
name|sha1Sums
argument_list|()
expr_stmt|;
name|pieceLength
operator|=
name|metaInfo
operator|.
name|pieceLength
argument_list|()
expr_stmt|;
block|}
name|numPieces
operator|=
name|sha1s
operator|.
name|size
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|readBlock
name|QByteArray
name|FileManager
operator|::
name|readBlock
parameter_list|(
name|int
name|pieceIndex
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|length
parameter_list|)
block|{
name|QByteArray
name|block
decl_stmt|;
name|qint64
name|startReadIndex
init|=
operator|(
name|quint64
argument_list|(
name|pieceIndex
argument_list|)
operator|*
name|pieceLength
operator|)
operator|+
name|offset
decl_stmt|;
name|qint64
name|currentIndex
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
operator|!
name|quit
operator|&&
name|i
argument_list|<
name|files
operator|.
name|size
operator|(
operator|)
operator|&&
name|length
argument_list|>
literal|0
condition|;
operator|++
name|i
control|)
block|{
name|QFile
modifier|*
name|file
init|=
name|files
index|[
name|i
index|]
decl_stmt|;
name|qint64
name|currentFileSize
init|=
name|fileSizes
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|currentIndex
operator|+
name|currentFileSize
operator|)
operator|>
name|startReadIndex
condition|)
block|{
if|if
condition|(
operator|!
name|file
operator|->
name|isOpen
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|file
operator|->
name|open
argument_list|(
name|QFile
operator|::
name|ReadWrite
argument_list|)
condition|)
block|{
name|errString
operator|=
name|tr
argument_list|(
literal|"Failed to read from file %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|fileName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|()
emit|;
break|break;
block|}
block|}
name|file
operator|->
name|seek
argument_list|(
name|startReadIndex
operator|-
name|currentIndex
argument_list|)
expr_stmt|;
name|QByteArray
name|chunk
init|=
name|file
operator|->
name|read
argument_list|(
name|qMin
argument_list|<
name|qint64
argument_list|>
argument_list|(
name|length
argument_list|,
name|currentFileSize
operator|-
name|file
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|file
operator|->
name|close
argument_list|()
expr_stmt|;
name|block
operator|+=
name|chunk
expr_stmt|;
name|length
operator|-=
name|chunk
operator|.
name|size
argument_list|()
expr_stmt|;
name|startReadIndex
operator|+=
name|chunk
operator|.
name|size
argument_list|()
expr_stmt|;
if|if
condition|(
name|length
operator|<
literal|0
condition|)
block|{
name|errString
operator|=
name|tr
argument_list|(
literal|"Failed to read from file %1 (read %3 bytes): %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|fileName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|errorString
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|length
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|()
emit|;
break|break;
block|}
block|}
name|currentIndex
operator|+=
name|currentFileSize
expr_stmt|;
block|}
return|return
name|block
return|;
block|}
end_function
begin_function
DECL|function|writeBlock
name|bool
name|FileManager
operator|::
name|writeBlock
parameter_list|(
name|int
name|pieceIndex
parameter_list|,
name|int
name|offset
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|qint64
name|startWriteIndex
init|=
operator|(
name|qint64
argument_list|(
name|pieceIndex
argument_list|)
operator|*
name|pieceLength
operator|)
operator|+
name|offset
decl_stmt|;
name|qint64
name|currentIndex
init|=
literal|0
decl_stmt|;
name|int
name|bytesToWrite
init|=
name|data
operator|.
name|size
argument_list|()
decl_stmt|;
name|int
name|written
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
operator|!
name|quit
operator|&&
name|i
operator|<
name|files
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QFile
modifier|*
name|file
init|=
name|files
index|[
name|i
index|]
decl_stmt|;
name|qint64
name|currentFileSize
init|=
name|fileSizes
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|currentIndex
operator|+
name|currentFileSize
operator|)
operator|>
name|startWriteIndex
condition|)
block|{
if|if
condition|(
operator|!
name|file
operator|->
name|isOpen
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|file
operator|->
name|open
argument_list|(
name|QFile
operator|::
name|ReadWrite
argument_list|)
condition|)
block|{
name|errString
operator|=
name|tr
argument_list|(
literal|"Failed to write to file %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|fileName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|()
emit|;
break|break;
block|}
block|}
name|file
operator|->
name|seek
argument_list|(
name|startWriteIndex
operator|-
name|currentIndex
argument_list|)
expr_stmt|;
name|qint64
name|bytesWritten
init|=
name|file
operator|->
name|write
argument_list|(
name|data
operator|.
name|constData
argument_list|()
operator|+
name|written
argument_list|,
name|qMin
argument_list|<
name|qint64
argument_list|>
argument_list|(
name|bytesToWrite
argument_list|,
name|currentFileSize
operator|-
name|file
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|file
operator|->
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
name|bytesWritten
operator|<=
literal|0
condition|)
block|{
name|errString
operator|=
name|tr
argument_list|(
literal|"Failed to write to file %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|fileName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|()
emit|;
return|return
literal|false
return|;
block|}
name|written
operator|+=
name|bytesWritten
expr_stmt|;
name|startWriteIndex
operator|+=
name|bytesWritten
expr_stmt|;
name|bytesToWrite
operator|-=
name|bytesWritten
expr_stmt|;
if|if
condition|(
name|bytesToWrite
operator|==
literal|0
condition|)
break|break;
block|}
name|currentIndex
operator|+=
name|currentFileSize
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|verifyFileContents
name|void
name|FileManager
operator|::
name|verifyFileContents
parameter_list|()
block|{
comment|// Verify all pieces the first time
if|if
condition|(
name|newPendingVerificationRequests
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|verifiedPieces
operator|.
name|count
argument_list|(
literal|true
argument_list|)
operator|==
literal|0
condition|)
block|{
name|verifiedPieces
operator|.
name|resize
argument_list|(
name|sha1s
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|oldPercent
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|newFile
condition|)
block|{
name|int
name|numPieces
init|=
name|sha1s
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
name|numPieces
condition|;
operator|++
name|index
control|)
block|{
name|verifySinglePiece
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|int
name|percent
init|=
operator|(
operator|(
name|index
operator|+
literal|1
operator|)
operator|*
literal|100
operator|)
operator|/
name|numPieces
decl_stmt|;
if|if
condition|(
name|oldPercent
operator|!=
name|percent
condition|)
block|{
emit|emit
name|verificationProgress
argument_list|(
name|percent
argument_list|)
emit|;
name|oldPercent
operator|=
name|percent
expr_stmt|;
block|}
block|}
block|}
block|}
emit|emit
name|verificationDone
argument_list|()
emit|;
return|return;
block|}
comment|// Verify all pending pieces
foreach|foreach
control|(
name|int
name|index
decl|,
name|newPendingVerificationRequests
control|)
emit|emit
name|pieceVerified
argument_list|(
name|index
argument_list|,
name|verifySinglePiece
argument_list|(
name|index
argument_list|)
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|verifySinglePiece
name|bool
name|FileManager
operator|::
name|verifySinglePiece
parameter_list|(
name|int
name|pieceIndex
parameter_list|)
block|{
name|QByteArray
name|block
init|=
name|readBlock
argument_list|(
name|pieceIndex
argument_list|,
literal|0
argument_list|,
name|pieceLength
argument_list|)
decl_stmt|;
name|QByteArray
name|sha1Sum
init|=
name|QCryptographicHash
operator|::
name|hash
argument_list|(
name|block
argument_list|,
name|QCryptographicHash
operator|::
name|Sha1
argument_list|)
decl_stmt|;
if|if
condition|(
name|sha1Sum
operator|!=
name|sha1s
operator|.
name|at
argument_list|(
name|pieceIndex
argument_list|)
condition|)
return|return
literal|false
return|;
name|verifiedPieces
operator|.
name|setBit
argument_list|(
name|pieceIndex
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|wakeUp
name|void
name|FileManager
operator|::
name|wakeUp
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|wokeUp
operator|=
literal|false
expr_stmt|;
name|cond
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
