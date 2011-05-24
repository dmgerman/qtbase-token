begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSYSTEMLOCK_P_H
end_ifndef
begin_define
DECL|macro|QSYSTEMLOCK_P_H
define|#
directive|define
name|QSYSTEMLOCK_P_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMLOCK
end_ifndef
begin_include
include|#
directive|include
file|"qsystemlock.h"
end_include
begin_include
include|#
directive|include
file|"private/qsharedmemory_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|MAX_LOCKS
define|#
directive|define
name|MAX_LOCKS
value|64
end_define
begin_decl_stmt
name|class
name|QSystemLockPrivate
block|{
name|public
label|:
name|QSystemLockPrivate
argument_list|()
expr_stmt|;
name|QString
name|makeKeyFileName
parameter_list|()
block|{
return|return
name|QSharedMemoryPrivate
operator|::
name|makePlatformSafeKey
argument_list|(
name|key
argument_list|,
name|QLatin1String
argument_list|(
literal|"qipc_systemlock_"
argument_list|)
argument_list|)
return|;
block|}
name|void
name|setErrorString
parameter_list|(
specifier|const
name|QString
modifier|&
name|function
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|HANDLE
name|handle
parameter_list|()
function_decl|;
name|bool
name|lock
parameter_list|(
name|HANDLE
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
name|bool
name|unlock
parameter_list|(
name|HANDLE
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
else|#
directive|else
name|key_t
name|handle
parameter_list|()
function_decl|;
endif|#
directive|endif
name|void
name|cleanHandle
parameter_list|()
function_decl|;
enum|enum
name|Operation
block|{
name|Lock
block|,
name|Unlock
block|}
enum|;
name|bool
name|modifySemaphore
argument_list|(
name|Operation
name|op
argument_list|,
name|QSystemLock
operator|::
name|LockMode
name|mode
operator|=
name|QSystemLock
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|QString
name|key
decl_stmt|;
name|QString
name|fileName
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|HANDLE
name|semaphore
decl_stmt|;
name|HANDLE
name|semaphoreLock
decl_stmt|;
else|#
directive|else
name|int
name|semaphore
decl_stmt|;
endif|#
directive|endif
name|int
name|lockCount
decl_stmt|;
name|QSystemLock
operator|::
name|LockMode
name|lockedMode
expr_stmt|;
name|QSystemLock
operator|::
name|SystemLockError
name|error
expr_stmt|;
name|QString
name|errorString
decl_stmt|;
name|private
label|:
ifndef|#
directive|ifndef
name|Q_OS_WIN
name|key_t
name|unix_key
decl_stmt|;
name|bool
name|createdFile
decl_stmt|;
name|bool
name|createdSemaphore
decl_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYSTEMLOCK
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSYSTEMLOCK_P_H
end_comment
end_unit
