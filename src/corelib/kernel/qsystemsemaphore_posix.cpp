begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Konstantin Ritt<ritt.ks@gmail.com> ** Copyright (C) 2015 The Qt Company Ltd. ** Copyright (C) 2015 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Tobias Koenig<tobias.koenig@kdab.com> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsystemsemaphore.h"
end_include
begin_include
include|#
directive|include
file|"qsystemsemaphore_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_POSIX_IPC
end_ifdef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
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
file|<sys/sem.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_comment
comment|// OpenBSD 4.2 doesn't define EIDRM, see BUGS section:
end_comment
begin_comment
comment|// http://www.openbsd.org/cgi-bin/man.cgi?query=semop&manpath=OpenBSD+4.2
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_OPENBSD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EIDRM
argument_list|)
end_if
begin_define
DECL|macro|EIDRM
define|#
directive|define
name|EIDRM
value|EINVAL
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|handle
name|bool
name|QSystemSemaphorePrivate
operator|::
name|handle
parameter_list|(
name|QSystemSemaphore
operator|::
name|AccessMode
name|mode
parameter_list|)
block|{
if|if
condition|(
name|semaphore
operator|!=
name|SEM_FAILED
condition|)
return|return
literal|true
return|;
comment|// we already have a semaphore
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|errorString
operator|=
name|QCoreApplication
operator|::
name|tr
argument_list|(
literal|"%1: key is empty"
argument_list|,
literal|"QSystemSemaphore"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::handle"
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|KeyError
expr_stmt|;
return|return
literal|false
return|;
block|}
specifier|const
name|QByteArray
name|semName
init|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
comment|// Always try with O_EXCL so we know whether we created the semaphore.
name|int
name|oflag
init|=
name|O_CREAT
operator||
name|O_EXCL
decl_stmt|;
for|for
control|(
name|int
name|tryNum
init|=
literal|0
init|,
name|maxTries
init|=
literal|1
init|;
name|tryNum
operator|<
name|maxTries
condition|;
operator|++
name|tryNum
control|)
block|{
do|do
block|{
name|semaphore
operator|=
operator|::
name|sem_open
argument_list|(
name|semName
operator|.
name|constData
argument_list|()
argument_list|,
name|oflag
argument_list|,
literal|0600
argument_list|,
name|initialValue
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|semaphore
operator|==
name|SEM_FAILED
operator|&&
name|errno
operator|==
name|EINTR
condition|)
do|;
if|if
condition|(
name|semaphore
operator|==
name|SEM_FAILED
operator|&&
name|errno
operator|==
name|EEXIST
condition|)
block|{
if|if
condition|(
name|mode
operator|==
name|QSystemSemaphore
operator|::
name|Create
condition|)
block|{
if|if
condition|(
operator|::
name|sem_unlink
argument_list|(
name|semName
operator|.
name|constData
argument_list|()
argument_list|)
operator|==
operator|-
literal|1
operator|&&
name|errno
operator|!=
name|ENOENT
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::handle (sem_unlink)"
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Race condition: the semaphore might be recreated before
comment|// we call sem_open again, so we'll retry several times.
name|maxTries
operator|=
literal|3
expr_stmt|;
block|}
else|else
block|{
comment|// Race condition: if it no longer exists at the next sem_open
comment|// call, we won't realize we created it, so we'll leak it later.
name|oflag
operator|&=
operator|~
name|O_EXCL
expr_stmt|;
name|maxTries
operator|=
literal|2
expr_stmt|;
block|}
block|}
else|else
block|{
break|break;
block|}
block|}
if|if
condition|(
name|semaphore
operator|==
name|SEM_FAILED
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::handle"
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|createdSemaphore
operator|=
operator|(
name|oflag
operator|&
name|O_EXCL
operator|)
operator|!=
literal|0
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|cleanHandle
name|void
name|QSystemSemaphorePrivate
operator|::
name|cleanHandle
parameter_list|()
block|{
if|if
condition|(
name|semaphore
operator|!=
name|SEM_FAILED
condition|)
block|{
if|if
condition|(
operator|::
name|sem_close
argument_list|(
name|semaphore
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::cleanHandle (sem_close)"
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::cleanHandle sem_close failed."
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|semaphore
operator|=
name|SEM_FAILED
expr_stmt|;
block|}
if|if
condition|(
name|createdSemaphore
condition|)
block|{
if|if
condition|(
operator|::
name|sem_unlink
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
argument_list|)
operator|==
operator|-
literal|1
operator|&&
name|errno
operator|!=
name|ENOENT
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::cleanHandle (sem_unlink)"
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::cleanHandle sem_unlink failed."
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|createdSemaphore
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|modifySemaphore
name|bool
name|QSystemSemaphorePrivate
operator|::
name|modifySemaphore
parameter_list|(
name|int
name|count
parameter_list|)
block|{
if|if
condition|(
operator|!
name|handle
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|count
operator|>
literal|0
condition|)
block|{
name|int
name|cnt
init|=
name|count
decl_stmt|;
do|do
block|{
if|if
condition|(
operator|::
name|sem_post
argument_list|(
name|semaphore
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modifySemaphore (sem_post)"
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modify sem_post failed"
argument_list|)
operator|<<
name|count
operator|<<
name|errno
expr_stmt|;
endif|#
directive|endif
comment|// rollback changes to preserve the SysV semaphore behavior
for|for
control|(
init|;
name|cnt
operator|<
name|count
condition|;
operator|++
name|cnt
control|)
block|{
name|int
name|res
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|res
argument_list|,
operator|::
name|sem_wait
argument_list|(
name|semaphore
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
operator|--
name|cnt
expr_stmt|;
block|}
do|while
condition|(
name|cnt
operator|>
literal|0
condition|)
do|;
block|}
else|else
block|{
name|int
name|res
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|res
argument_list|,
operator|::
name|sem_wait
argument_list|(
name|semaphore
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|res
operator|==
operator|-
literal|1
condition|)
block|{
comment|// If the semaphore was removed be nice and create it and then modifySemaphore again
if|if
condition|(
name|errno
operator|==
name|EINVAL
operator|||
name|errno
operator|==
name|EIDRM
condition|)
block|{
name|semaphore
operator|=
name|SEM_FAILED
expr_stmt|;
return|return
name|modifySemaphore
argument_list|(
name|count
argument_list|)
return|;
block|}
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modifySemaphore (sem_wait)"
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modify sem_wait failed"
argument_list|)
operator|<<
name|count
operator|<<
name|errno
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
block|}
name|clearError
argument_list|()
expr_stmt|;
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
comment|// QT_NO_SYSTEMSEMAPHORE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_POSIX_IPC
end_comment
end_unit
