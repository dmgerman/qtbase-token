begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_include
include|#
directive|include
file|"qsystemerror_p.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
end_if
begin_include
include|#
directive|include
file|<crtdbg.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_THREAD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_INTEGRITY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_QNX
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|_POSIX_THREAD_SAFE_FUNCTIONS
argument_list|)
operator|&&
name|_POSIX_VERSION
operator|>=
literal|200112L
end_if
begin_namespace
namespace|namespace
block|{
comment|// There are two incompatible versions of strerror_r:
comment|// a) the XSI/POSIX.1 version, which returns an int,
comment|//    indicating success or not
comment|// b) the GNU version, which returns a char*, which may or may not
comment|//    be the beginning of the buffer we used
comment|// The GNU libc manpage for strerror_r says you should use the the XSI
comment|// version in portable code. However, it's impossible to do that if
comment|// _GNU_SOURCE is defined so we use C++ overloading to decide what to do
comment|// depending on the return type
DECL|function|fromstrerror_helper
specifier|static
specifier|inline
name|QString
name|fromstrerror_helper
parameter_list|(
name|int
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|buf
parameter_list|)
block|{
return|return
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|buf
argument_list|)
return|;
block|}
DECL|function|fromstrerror_helper
specifier|static
specifier|inline
name|QString
name|fromstrerror_helper
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|QByteArray
modifier|&
parameter_list|)
block|{
return|return
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|str
argument_list|)
return|;
block|}
block|}
end_namespace
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|standardLibraryErrorString
specifier|static
name|QString
name|standardLibraryErrorString
parameter_list|(
name|int
name|errorCode
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|s
init|=
literal|0
decl_stmt|;
name|QString
name|ret
decl_stmt|;
switch|switch
condition|(
name|errorCode
condition|)
block|{
case|case
literal|0
case|:
break|break;
case|case
name|EACCES
case|:
name|s
operator|=
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"QIODevice"
argument_list|,
literal|"Permission denied"
argument_list|)
expr_stmt|;
break|break;
case|case
name|EMFILE
case|:
name|s
operator|=
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"QIODevice"
argument_list|,
literal|"Too many open files"
argument_list|)
expr_stmt|;
break|break;
case|case
name|ENOENT
case|:
name|s
operator|=
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"QIODevice"
argument_list|,
literal|"No such file or directory"
argument_list|)
expr_stmt|;
break|break;
case|case
name|ENOSPC
case|:
name|s
operator|=
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"QIODevice"
argument_list|,
literal|"No space left on device"
argument_list|)
expr_stmt|;
break|break;
default|default:
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_THREAD
argument_list|)
operator|&&
name|defined
argument_list|(
name|_POSIX_THREAD_SAFE_FUNCTIONS
argument_list|)
operator|&&
name|_POSIX_VERSION
operator|>=
literal|200112L
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_INTEGRITY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_QNX
argument_list|)
name|QByteArray
name|buf
argument_list|(
literal|1024
argument_list|,
literal|'\0'
argument_list|)
decl_stmt|;
name|ret
operator|=
name|fromstrerror_helper
argument_list|(
name|strerror_r
argument_list|(
name|errorCode
argument_list|,
name|buf
operator|.
name|data
argument_list|()
argument_list|,
name|buf
operator|.
name|size
argument_list|()
argument_list|)
argument_list|,
name|buf
argument_list|)
expr_stmt|;
else|#
directive|else
name|ret
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|strerror
argument_list|(
name|errorCode
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
block|}
block|}
if|if
condition|(
name|s
condition|)
block|{
comment|// ######## this breaks moc build currently
comment|// ret = QCoreApplication::translate("QIODevice", s);
name|ret
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
operator|.
name|trimmed
argument_list|()
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_function
DECL|function|windowsErrorString
specifier|static
name|QString
name|windowsErrorString
parameter_list|(
name|int
name|errorCode
parameter_list|)
block|{
name|QString
name|ret
decl_stmt|;
name|wchar_t
modifier|*
name|string
init|=
literal|0
decl_stmt|;
name|FormatMessage
argument_list|(
name|FORMAT_MESSAGE_ALLOCATE_BUFFER
operator||
name|FORMAT_MESSAGE_FROM_SYSTEM
argument_list|,
name|NULL
argument_list|,
name|errorCode
argument_list|,
name|MAKELANGID
argument_list|(
name|LANG_NEUTRAL
argument_list|,
name|SUBLANG_DEFAULT
argument_list|)
argument_list|,
operator|(
name|LPWSTR
operator|)
operator|&
name|string
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|ret
operator|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|string
argument_list|)
expr_stmt|;
name|LocalFree
argument_list|(
operator|(
name|HLOCAL
operator|)
name|string
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|.
name|isEmpty
argument_list|()
operator|&&
name|errorCode
operator|==
name|ERROR_MOD_NOT_FOUND
condition|)
name|ret
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"The specified module could not be found."
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_function
DECL|function|symbianErrorString
specifier|static
name|QString
name|symbianErrorString
parameter_list|(
name|int
name|errorCode
parameter_list|)
block|{
switch|switch
condition|(
name|errorCode
condition|)
block|{
case|case
name|KErrNotFound
case|:
return|return
name|QLatin1String
argument_list|(
literal|"not found"
argument_list|)
return|;
case|case
name|KErrCancel
case|:
return|return
name|QLatin1String
argument_list|(
literal|"cancelled"
argument_list|)
return|;
case|case
name|KErrNoMemory
case|:
return|return
name|QLatin1String
argument_list|(
literal|"out of memory"
argument_list|)
return|;
case|case
name|KErrNotSupported
case|:
return|return
name|QLatin1String
argument_list|(
literal|"not supported"
argument_list|)
return|;
case|case
name|KErrBadHandle
case|:
return|return
name|QLatin1String
argument_list|(
literal|"bad handle"
argument_list|)
return|;
comment|//KERN-EXEC 0 panic is more likely
case|case
name|KErrAlreadyExists
case|:
return|return
name|QLatin1String
argument_list|(
literal|"already exists"
argument_list|)
return|;
case|case
name|KErrPathNotFound
case|:
return|return
name|QLatin1String
argument_list|(
literal|"path not found"
argument_list|)
return|;
case|case
name|KErrInUse
case|:
return|return
name|QLatin1String
argument_list|(
literal|"in use"
argument_list|)
return|;
case|case
name|KErrNotReady
case|:
return|return
name|QLatin1String
argument_list|(
literal|"not ready (e.g. FS dismounted, network down)"
argument_list|)
return|;
case|case
name|KErrCorrupt
case|:
return|return
name|QLatin1String
argument_list|(
literal|"corrupt"
argument_list|)
return|;
case|case
name|KErrAccessDenied
case|:
return|return
name|QLatin1String
argument_list|(
literal|"access denied"
argument_list|)
return|;
case|case
name|KErrLocked
case|:
return|return
name|QLatin1String
argument_list|(
literal|"locked"
argument_list|)
return|;
case|case
name|KErrWrite
case|:
return|return
name|QLatin1String
argument_list|(
literal|"incomplete write error"
argument_list|)
return|;
case|case
name|KErrDisMounted
case|:
return|return
name|QLatin1String
argument_list|(
literal|"file system dismounted during operation"
argument_list|)
return|;
comment|//i.e. a forcible dismount was done while we had files open
case|case
name|KErrEof
case|:
return|return
name|QLatin1String
argument_list|(
literal|"end of file"
argument_list|)
return|;
case|case
name|KErrDiskFull
case|:
return|return
name|QLatin1String
argument_list|(
literal|"no space in file system"
argument_list|)
return|;
case|case
name|KErrBadName
case|:
return|return
name|QLatin1String
argument_list|(
literal|"invalid filename"
argument_list|)
return|;
case|case
name|KErrTimedOut
case|:
return|return
name|QLatin1String
argument_list|(
literal|"timed out"
argument_list|)
return|;
case|case
name|KErrBadDescriptor
case|:
return|return
name|QLatin1String
argument_list|(
literal|"bad descriptor (passed address on stack to async call?)"
argument_list|)
return|;
case|case
name|KErrAbort
case|:
return|return
name|QLatin1String
argument_list|(
literal|"aborted"
argument_list|)
return|;
case|case
name|KErrTooBig
case|:
return|return
name|QLatin1String
argument_list|(
literal|"too big"
argument_list|)
return|;
comment|//e.g. trying to open a>2GB file with 32 bit API
case|case
name|KErrBadPower
case|:
return|return
name|QLatin1String
argument_list|(
literal|"insufficient power"
argument_list|)
return|;
case|case
name|KErrDirFull
case|:
return|return
name|QLatin1String
argument_list|(
literal|"no space in directory table"
argument_list|)
return|;
case|case
name|KErrHardwareNotAvailable
case|:
return|return
name|QLatin1String
argument_list|(
literal|"hardware not available"
argument_list|)
return|;
case|case
name|KErrSessionClosed
case|:
return|return
name|QLatin1String
argument_list|(
literal|"session closed"
argument_list|)
return|;
case|case
name|KErrPermissionDenied
case|:
return|return
name|QLatin1String
argument_list|(
literal|"permission denied"
argument_list|)
return|;
default|default:
return|return
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"symbian error %1"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|errorCode
argument_list|)
return|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|toString
name|QString
name|QSystemError
operator|::
name|toString
parameter_list|()
block|{
switch|switch
condition|(
name|errorScope
condition|)
block|{
case|case
name|NativeError
case|:
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
return|return
name|windowsErrorString
argument_list|(
name|errorCode
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
return|return
name|symbianErrorString
argument_list|(
name|errorCode
argument_list|)
return|;
else|#
directive|else
comment|//unix: fall through as native and standard library are the same
endif|#
directive|endif
case|case
name|StandardLibraryError
case|:
return|return
name|standardLibraryErrorString
argument_list|(
name|errorCode
argument_list|)
return|;
default|default:
name|qWarning
argument_list|(
literal|"invalid error scope"
argument_list|)
expr_stmt|;
comment|//fall through
case|case
name|NoError
case|:
return|return
name|QLatin1String
argument_list|(
literal|"No error"
argument_list|)
return|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
