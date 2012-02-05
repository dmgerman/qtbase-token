begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qsharedmemory.h"
end_include
begin_include
include|#
directive|include
file|"qsharedmemory_p.h"
end_include
begin_include
include|#
directive|include
file|"qsystemsemaphore.h"
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SHAREDMEMORY
end_ifndef
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include
begin_include
include|#
directive|include
file|<sys/shm.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_SHAREDMEMORY
end_comment
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SHAREDMEMORY
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QSharedMemoryPrivate
name|QSharedMemoryPrivate
operator|::
name|QSharedMemoryPrivate
parameter_list|()
member_init_list|:
name|QObjectPrivate
argument_list|()
member_init_list|,
name|memory
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|size
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|error
argument_list|(
name|QSharedMemory
operator|::
name|NoError
argument_list|)
member_init_list|,
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
name|systemSemaphore
argument_list|(
name|QString
argument_list|()
argument_list|)
member_init_list|,
name|lockedByMe
argument_list|(
literal|false
argument_list|)
member_init_list|,
endif|#
directive|endif
name|unix_key
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|setErrorString
name|void
name|QSharedMemoryPrivate
operator|::
name|setErrorString
parameter_list|(
specifier|const
name|QString
modifier|&
name|function
parameter_list|)
block|{
comment|// EINVAL is handled in functions so they can give better error strings
switch|switch
condition|(
name|errno
condition|)
block|{
case|case
name|EACCES
case|:
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: permission denied"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|PermissionDenied
expr_stmt|;
break|break;
case|case
name|EEXIST
case|:
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: already exists"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|AlreadyExists
expr_stmt|;
break|break;
case|case
name|ENOENT
case|:
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: doesn't exist"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|NotFound
expr_stmt|;
break|break;
case|case
name|EMFILE
case|:
case|case
name|ENOMEM
case|:
case|case
name|ENOSPC
case|:
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: out of resources"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|OutOfResources
expr_stmt|;
break|break;
default|default:
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: unknown error %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
operator|.
name|arg
argument_list|(
name|errno
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|UnknownError
expr_stmt|;
if|#
directive|if
name|defined
name|QSHAREDMEMORY_DEBUG
name|qDebug
argument_list|()
operator|<<
name|errorString
operator|<<
literal|"key"
operator|<<
name|key
operator|<<
literal|"errno"
operator|<<
name|errno
operator|<<
name|EINVAL
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_comment
comment|/*!     \internal      If not already made create the handle used for accessing the shared memory. */
end_comment
begin_function
DECL|function|handle
name|key_t
name|QSharedMemoryPrivate
operator|::
name|handle
parameter_list|()
block|{
comment|// already made
if|if
condition|(
name|unix_key
condition|)
return|return
name|unix_key
return|;
comment|// don't allow making handles on empty keys
if|if
condition|(
name|nativeKey
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: key is empty"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSharedMemory::handle:"
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|KeyError
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|// ftok requires that an actual file exists somewhere
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|nativeKey
argument_list|)
condition|)
block|{
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: UNIX key file doesn't exist"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSharedMemory::handle:"
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|NotFound
expr_stmt|;
return|return
literal|0
return|;
block|}
name|unix_key
operator|=
name|ftok
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|nativeKey
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|,
literal|'Q'
argument_list|)
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|unix_key
condition|)
block|{
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: ftok failed"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSharedMemory::handle:"
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|KeyError
expr_stmt|;
name|unix_key
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|unix_key
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SHAREDMEMORY
end_comment
begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|QT_NO_SHAREDMEMORY
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_NO_SYSTEMSEMAPHORE
argument_list|)
operator|)
end_if
begin_comment
comment|/*!     \internal     Creates the unix file if needed.     returns true if the unix file was created.      -1 error      0 already existed      1 created   */
end_comment
begin_function
DECL|function|createUnixKeyFile
name|int
name|QSharedMemoryPrivate
operator|::
name|createUnixKeyFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|fileName
argument_list|)
condition|)
return|return
literal|0
return|;
name|int
name|fd
init|=
name|qt_safe_open
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|fileName
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|,
name|O_EXCL
operator||
name|O_CREAT
operator||
name|O_RDWR
argument_list|,
literal|0640
argument_list|)
decl_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|fd
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|EEXIST
condition|)
return|return
literal|0
return|;
return|return
operator|-
literal|1
return|;
block|}
else|else
block|{
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
return|return
literal|1
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SHAREDMEMORY&& QT_NO_SYSTEMSEMAPHORE
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SHAREDMEMORY
end_ifndef
begin_function
DECL|function|cleanHandle
name|bool
name|QSharedMemoryPrivate
operator|::
name|cleanHandle
parameter_list|()
block|{
name|unix_key
operator|=
literal|0
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|create
name|bool
name|QSharedMemoryPrivate
operator|::
name|create
parameter_list|(
name|int
name|size
parameter_list|)
block|{
comment|// build file if needed
name|bool
name|createdFile
init|=
literal|false
decl_stmt|;
name|int
name|built
init|=
name|createUnixKeyFile
argument_list|(
name|nativeKey
argument_list|)
decl_stmt|;
if|if
condition|(
name|built
operator|==
operator|-
literal|1
condition|)
block|{
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: unable to make key"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSharedMemory::handle:"
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|KeyError
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|built
operator|==
literal|1
condition|)
block|{
name|createdFile
operator|=
literal|true
expr_stmt|;
block|}
comment|// get handle
if|if
condition|(
operator|!
name|handle
argument_list|()
condition|)
block|{
if|if
condition|(
name|createdFile
condition|)
name|QFile
operator|::
name|remove
argument_list|(
name|nativeKey
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// create
if|if
condition|(
operator|-
literal|1
operator|==
name|shmget
argument_list|(
name|unix_key
argument_list|,
name|size
argument_list|,
literal|0666
operator||
name|IPC_CREAT
operator||
name|IPC_EXCL
argument_list|)
condition|)
block|{
name|QString
name|function
init|=
name|QLatin1String
argument_list|(
literal|"QSharedMemory::create"
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|errno
condition|)
block|{
case|case
name|EINVAL
case|:
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: system-imposed size restrictions"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSharedMemory::handle"
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|InvalidSize
expr_stmt|;
break|break;
default|default:
name|setErrorString
argument_list|(
name|function
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|createdFile
operator|&&
name|error
operator|!=
name|QSharedMemory
operator|::
name|AlreadyExists
condition|)
name|QFile
operator|::
name|remove
argument_list|(
name|nativeKey
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
DECL|function|attach
name|bool
name|QSharedMemoryPrivate
operator|::
name|attach
parameter_list|(
name|QSharedMemory
operator|::
name|AccessMode
name|mode
parameter_list|)
block|{
comment|// grab the shared memory segment id
name|int
name|id
init|=
name|shmget
argument_list|(
name|unix_key
argument_list|,
literal|0
argument_list|,
operator|(
name|mode
operator|==
name|QSharedMemory
operator|::
name|ReadOnly
condition|?
literal|0444
else|:
literal|0660
operator|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|id
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSharedMemory::attach (shmget)"
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// grab the memory
name|memory
operator|=
name|shmat
argument_list|(
name|id
argument_list|,
literal|0
argument_list|,
operator|(
name|mode
operator|==
name|QSharedMemory
operator|::
name|ReadOnly
condition|?
name|SHM_RDONLY
else|:
literal|0
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|void
operator|*
operator|)
operator|-
literal|1
operator|==
name|memory
condition|)
block|{
name|memory
operator|=
literal|0
expr_stmt|;
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSharedMemory::attach (shmat)"
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// grab the size
name|shmid_ds
name|shmid_ds
decl_stmt|;
if|if
condition|(
operator|!
name|shmctl
argument_list|(
name|id
argument_list|,
name|IPC_STAT
argument_list|,
operator|&
name|shmid_ds
argument_list|)
condition|)
block|{
name|size
operator|=
operator|(
name|int
operator|)
name|shmid_ds
operator|.
name|shm_segsz
expr_stmt|;
block|}
else|else
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSharedMemory::attach (shmctl)"
argument_list|)
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
DECL|function|detach
name|bool
name|QSharedMemoryPrivate
operator|::
name|detach
parameter_list|()
block|{
comment|// detach from the memory segment
if|if
condition|(
operator|-
literal|1
operator|==
name|shmdt
argument_list|(
name|memory
argument_list|)
condition|)
block|{
name|QString
name|function
init|=
name|QLatin1String
argument_list|(
literal|"QSharedMemory::detach"
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|errno
condition|)
block|{
case|case
name|EINVAL
case|:
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: not attached"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|NotFound
expr_stmt|;
break|break;
default|default:
name|setErrorString
argument_list|(
name|function
argument_list|)
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
name|memory
operator|=
literal|0
expr_stmt|;
name|size
operator|=
literal|0
expr_stmt|;
comment|// Get the number of current attachments
name|int
name|id
init|=
name|shmget
argument_list|(
name|unix_key
argument_list|,
literal|0
argument_list|,
literal|0444
argument_list|)
decl_stmt|;
name|cleanHandle
argument_list|()
expr_stmt|;
name|struct
name|shmid_ds
name|shmid_ds
decl_stmt|;
if|if
condition|(
literal|0
operator|!=
name|shmctl
argument_list|(
name|id
argument_list|,
name|IPC_STAT
argument_list|,
operator|&
name|shmid_ds
argument_list|)
condition|)
block|{
switch|switch
condition|(
name|errno
condition|)
block|{
case|case
name|EINVAL
case|:
return|return
literal|true
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
comment|// If there are no attachments then remove it.
if|if
condition|(
name|shmid_ds
operator|.
name|shm_nattch
operator|==
literal|0
condition|)
block|{
comment|// mark for removal
if|if
condition|(
operator|-
literal|1
operator|==
name|shmctl
argument_list|(
name|id
argument_list|,
name|IPC_RMID
argument_list|,
operator|&
name|shmid_ds
argument_list|)
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSharedMemory::remove"
argument_list|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|errno
condition|)
block|{
case|case
name|EINVAL
case|:
return|return
literal|true
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
comment|// remove file
if|if
condition|(
operator|!
name|QFile
operator|::
name|remove
argument_list|(
name|nativeKey
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SHAREDMEMORY
end_comment
end_unit
