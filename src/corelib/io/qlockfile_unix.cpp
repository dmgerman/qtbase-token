begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 David Faure<faure+bluesystems@kde.org> ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"private/qlockfile_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qtemporaryfile.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qfileinfo.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdebug.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_comment
comment|// qt_safe_open
end_comment
begin_include
include|#
directive|include
file|"private/qabstractfileengine_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qtemporaryfile_p.h"
end_include
begin_include
include|#
directive|include
file|<sys/file.h>
end_include
begin_comment
comment|// flock
end_comment
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_comment
comment|// kill
end_comment
begin_include
include|#
directive|include
file|<signal.h>
end_include
begin_comment
comment|// kill
end_comment
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_comment
comment|// gethostname
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_OSX
argument_list|)
end_if
begin_include
include|#
directive|include
file|<libproc.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<cstdio>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_IOS
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<sys/user.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|localHostName
specifier|static
name|QByteArray
name|localHostName
parameter_list|()
comment|// from QHostInfo::localHostName(), modified to return a QByteArray
block|{
name|QByteArray
name|hostName
argument_list|(
literal|512
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
if|if
condition|(
name|gethostname
argument_list|(
name|hostName
operator|.
name|data
argument_list|()
argument_list|,
name|hostName
operator|.
name|size
argument_list|()
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
name|QByteArray
argument_list|()
return|;
name|hostName
operator|.
name|truncate
argument_list|(
name|strlen
argument_list|(
name|hostName
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|hostName
return|;
block|}
end_function
begin_comment
comment|// ### merge into qt_safe_write?
end_comment
begin_function
DECL|function|qt_write_loop
specifier|static
name|qint64
name|qt_write_loop
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|len
parameter_list|)
block|{
name|qint64
name|pos
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|pos
operator|<
name|len
condition|)
block|{
specifier|const
name|qint64
name|ret
init|=
name|qt_safe_write
argument_list|(
name|fd
argument_list|,
name|data
operator|+
name|pos
argument_list|,
name|len
operator|-
name|pos
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
operator|-
literal|1
condition|)
comment|// e.g. partition full
return|return
name|pos
return|;
name|pos
operator|+=
name|ret
expr_stmt|;
block|}
return|return
name|pos
return|;
block|}
end_function
begin_function
DECL|function|checkFcntlWorksAfterFlock
name|int
name|QLockFilePrivate
operator|::
name|checkFcntlWorksAfterFlock
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_TEMPORARYFILE
name|QTemporaryFile
name|file
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|()
condition|)
return|return
literal|0
return|;
specifier|const
name|int
name|fd
init|=
name|file
operator|.
name|d_func
argument_list|()
operator|->
name|engine
argument_list|()
operator|->
name|handle
argument_list|()
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|LOCK_EX
argument_list|)
operator|&&
name|defined
argument_list|(
name|LOCK_NB
argument_list|)
if|if
condition|(
name|flock
argument_list|(
name|fd
argument_list|,
name|LOCK_EX
operator||
name|LOCK_NB
argument_list|)
operator|==
operator|-
literal|1
condition|)
comment|// other threads, and other processes on a local fs
return|return
literal|0
return|;
endif|#
directive|endif
name|struct
name|flock
name|flockData
decl_stmt|;
name|flockData
operator|.
name|l_type
operator|=
name|F_WRLCK
expr_stmt|;
name|flockData
operator|.
name|l_whence
operator|=
name|SEEK_SET
expr_stmt|;
name|flockData
operator|.
name|l_start
operator|=
literal|0
expr_stmt|;
name|flockData
operator|.
name|l_len
operator|=
literal|0
expr_stmt|;
comment|// 0 = entire file
name|flockData
operator|.
name|l_pid
operator|=
name|getpid
argument_list|()
expr_stmt|;
if|if
condition|(
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETLK
argument_list|,
operator|&
name|flockData
argument_list|)
operator|==
operator|-
literal|1
condition|)
comment|// for networked filesystems
return|return
literal|0
return|;
return|return
literal|1
return|;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_decl_stmt
DECL|variable|fcntlOK
specifier|static
name|QBasicAtomicInt
name|fcntlOK
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!   \internal   Checks that the OS isn't using POSIX locks to emulate flock().   OS X is one of those. */
end_comment
begin_function
DECL|function|fcntlWorksAfterFlock
specifier|static
name|bool
name|fcntlWorksAfterFlock
parameter_list|()
block|{
name|int
name|value
init|=
name|fcntlOK
operator|.
name|load
argument_list|()
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|value
operator|==
operator|-
literal|1
argument_list|)
condition|)
block|{
name|value
operator|=
name|QLockFilePrivate
operator|::
name|checkFcntlWorksAfterFlock
argument_list|()
expr_stmt|;
name|fcntlOK
operator|.
name|store
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
return|return
name|value
operator|==
literal|1
return|;
block|}
end_function
begin_function
DECL|function|setNativeLocks
specifier|static
name|bool
name|setNativeLocks
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|LOCK_EX
argument_list|)
operator|&&
name|defined
argument_list|(
name|LOCK_NB
argument_list|)
if|if
condition|(
name|flock
argument_list|(
name|fd
argument_list|,
name|LOCK_EX
operator||
name|LOCK_NB
argument_list|)
operator|==
operator|-
literal|1
condition|)
comment|// other threads, and other processes on a local fs
return|return
literal|false
return|;
endif|#
directive|endif
name|struct
name|flock
name|flockData
decl_stmt|;
name|flockData
operator|.
name|l_type
operator|=
name|F_WRLCK
expr_stmt|;
name|flockData
operator|.
name|l_whence
operator|=
name|SEEK_SET
expr_stmt|;
name|flockData
operator|.
name|l_start
operator|=
literal|0
expr_stmt|;
name|flockData
operator|.
name|l_len
operator|=
literal|0
expr_stmt|;
comment|// 0 = entire file
name|flockData
operator|.
name|l_pid
operator|=
name|getpid
argument_list|()
expr_stmt|;
if|if
condition|(
name|fcntlWorksAfterFlock
argument_list|()
operator|&&
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETLK
argument_list|,
operator|&
name|flockData
argument_list|)
operator|==
operator|-
literal|1
condition|)
comment|// for networked filesystems
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|tryLock_sys
name|QLockFile
operator|::
name|LockError
name|QLockFilePrivate
operator|::
name|tryLock_sys
parameter_list|()
block|{
comment|// Assemble data, to write in a single call to write
comment|// (otherwise we'd have to check every write call)
comment|// Use operator% from the fast builder to avoid multiple memory allocations.
name|QByteArray
name|fileData
init|=
name|QByteArray
operator|::
name|number
argument_list|(
name|QCoreApplication
operator|::
name|applicationPid
argument_list|()
argument_list|)
operator|%
literal|'\n'
operator|%
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
operator|.
name|toUtf8
argument_list|()
operator|%
literal|'\n'
operator|%
name|localHostName
argument_list|()
operator|%
literal|'\n'
decl_stmt|;
specifier|const
name|QByteArray
name|lockFileName
init|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
specifier|const
name|int
name|fd
init|=
name|qt_safe_open
argument_list|(
name|lockFileName
operator|.
name|constData
argument_list|()
argument_list|,
name|O_WRONLY
operator||
name|O_CREAT
operator||
name|O_EXCL
argument_list|,
literal|0644
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
switch|switch
condition|(
name|errno
condition|)
block|{
case|case
name|EEXIST
case|:
return|return
name|QLockFile
operator|::
name|LockFailedError
return|;
case|case
name|EACCES
case|:
case|case
name|EROFS
case|:
return|return
name|QLockFile
operator|::
name|PermissionError
return|;
default|default:
return|return
name|QLockFile
operator|::
name|UnknownError
return|;
block|}
block|}
comment|// Ensure nobody else can delete the file while we have it
if|if
condition|(
operator|!
name|setNativeLocks
argument_list|(
name|fd
argument_list|)
condition|)
name|qWarning
argument_list|()
operator|<<
literal|"setNativeLocks failed:"
operator|<<
name|strerror
argument_list|(
name|errno
argument_list|)
expr_stmt|;
if|if
condition|(
name|qt_write_loop
argument_list|(
name|fd
argument_list|,
name|fileData
operator|.
name|constData
argument_list|()
argument_list|,
name|fileData
operator|.
name|size
argument_list|()
argument_list|)
operator|<
name|fileData
operator|.
name|size
argument_list|()
condition|)
block|{
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QFile
operator|::
name|remove
argument_list|(
name|fileName
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QLockFile: Could not remove our own lock file %s."
argument_list|,
name|qPrintable
argument_list|(
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QLockFile
operator|::
name|UnknownError
return|;
comment|// partition full
block|}
comment|// We hold the lock, continue.
name|fileHandle
operator|=
name|fd
expr_stmt|;
return|return
name|QLockFile
operator|::
name|NoError
return|;
block|}
end_function
begin_function
DECL|function|removeStaleLock
name|bool
name|QLockFilePrivate
operator|::
name|removeStaleLock
parameter_list|()
block|{
specifier|const
name|QByteArray
name|lockFileName
init|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
specifier|const
name|int
name|fd
init|=
name|qt_safe_open
argument_list|(
name|lockFileName
operator|.
name|constData
argument_list|()
argument_list|,
name|O_WRONLY
argument_list|,
literal|0644
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
comment|// gone already?
return|return
literal|false
return|;
name|bool
name|success
init|=
name|setNativeLocks
argument_list|(
name|fd
argument_list|)
operator|&&
operator|(
operator|::
name|unlink
argument_list|(
name|lockFileName
argument_list|)
operator|==
literal|0
operator|)
decl_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
name|success
return|;
block|}
end_function
begin_function
DECL|function|isApparentlyStale
name|bool
name|QLockFilePrivate
operator|::
name|isApparentlyStale
parameter_list|()
specifier|const
block|{
name|qint64
name|pid
decl_stmt|;
name|QString
name|hostname
decl_stmt|,
name|appname
decl_stmt|;
if|if
condition|(
name|getLockInfo
argument_list|(
operator|&
name|pid
argument_list|,
operator|&
name|hostname
argument_list|,
operator|&
name|appname
argument_list|)
condition|)
block|{
if|if
condition|(
name|hostname
operator|.
name|isEmpty
argument_list|()
operator|||
name|hostname
operator|==
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|localHostName
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
operator|::
name|kill
argument_list|(
name|pid
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
operator|&&
name|errno
operator|==
name|ESRCH
condition|)
return|return
literal|true
return|;
comment|// PID doesn't exist anymore
specifier|const
name|QString
name|processName
init|=
name|processNameByPid
argument_list|(
name|pid
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|processName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QFileInfo
name|fi
argument_list|(
name|appname
argument_list|)
decl_stmt|;
if|if
condition|(
name|fi
operator|.
name|isSymLink
argument_list|()
condition|)
name|fi
operator|.
name|setFile
argument_list|(
name|fi
operator|.
name|symLinkTarget
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|processName
operator|!=
name|fi
operator|.
name|fileName
argument_list|()
condition|)
return|return
literal|true
return|;
comment|// PID got reused by a different application.
block|}
block|}
block|}
specifier|const
name|qint64
name|age
init|=
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|lastModified
argument_list|()
operator|.
name|msecsTo
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|staleLockTime
operator|>
literal|0
operator|&&
name|age
operator|>
name|staleLockTime
return|;
block|}
end_function
begin_function
DECL|function|processNameByPid
name|QString
name|QLockFilePrivate
operator|::
name|processNameByPid
parameter_list|(
name|qint64
name|pid
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_OSX
argument_list|)
name|char
name|name
index|[
literal|1024
index|]
decl_stmt|;
name|proc_name
argument_list|(
name|pid
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|name
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QFile
operator|::
name|decodeName
argument_list|(
name|name
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|QStringLiteral
argument_list|(
literal|"/proc/version"
argument_list|)
argument_list|)
condition|)
return|return
name|QString
argument_list|()
return|;
name|char
name|exePath
index|[
literal|64
index|]
decl_stmt|;
name|char
name|buf
index|[
name|PATH_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|exePath
argument_list|,
literal|"/proc/%lld/exe"
argument_list|,
name|pid
argument_list|)
expr_stmt|;
name|size_t
name|len
init|=
operator|(
name|size_t
operator|)
name|readlink
argument_list|(
name|exePath
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|len
operator|>=
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
condition|)
block|{
comment|// The pid is gone. Return some invalid process name to fail the test.
return|return
name|QStringLiteral
argument_list|(
literal|"/ERROR/"
argument_list|)
return|;
block|}
name|buf
index|[
name|len
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|QFileInfo
argument_list|(
name|QFile
operator|::
name|decodeName
argument_list|(
name|buf
argument_list|)
argument_list|)
operator|.
name|fileName
argument_list|()
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_IOS
argument_list|)
name|kinfo_proc
modifier|*
name|proc
init|=
name|kinfo_getproc
argument_list|(
name|pid
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|proc
condition|)
return|return
name|QString
argument_list|()
return|;
name|QString
name|name
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|proc
operator|->
name|ki_comm
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|proc
argument_list|)
expr_stmt|;
return|return
name|name
return|;
else|#
directive|else
return|return
name|QString
argument_list|()
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|unlock
name|void
name|QLockFile
operator|::
name|unlock
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QLockFile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|isLocked
condition|)
return|return;
name|close
argument_list|(
name|d
operator|->
name|fileHandle
argument_list|)
expr_stmt|;
name|d
operator|->
name|fileHandle
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|QFile
operator|::
name|remove
argument_list|(
name|d
operator|->
name|fileName
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Could not remove our own lock file"
operator|<<
name|d
operator|->
name|fileName
operator|<<
literal|"maybe permissions changed meanwhile?"
expr_stmt|;
comment|// This is bad because other users of this lock file will now have to wait for the stale-lock-timeout...
block|}
name|d
operator|->
name|lockError
operator|=
name|QLockFile
operator|::
name|NoError
expr_stmt|;
name|d
operator|->
name|isLocked
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
