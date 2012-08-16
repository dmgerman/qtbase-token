begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Copyright (C) 2012 Intel Corporation ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMUTEX_P_H
end_ifndef
begin_define
DECL|macro|QMUTEX_P_H
define|#
directive|define
name|QMUTEX_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of qmutex.cpp, qmutex_unix.cpp, and qmutex_win.cpp.  This header
end_comment
begin_comment
comment|// file may change from version to version without notice, or even be
end_comment
begin_comment
comment|// removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_include
include|#
directive|include
file|<mach/semaphore.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_LINUXBASE
argument_list|)
end_if
begin_comment
comment|// use Linux mutexes everywhere except for LSB builds
end_comment
begin_define
DECL|macro|QT_LINUX_FUTEX
define|#
directive|define
name|QT_LINUX_FUTEX
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QMutexData
block|{
name|public
label|:
name|bool
name|recursive
decl_stmt|;
name|QMutexData
argument_list|(
argument|QMutex::RecursionMode mode = QMutex::NonRecursive
argument_list|)
block|:
name|recursive
argument_list|(
argument|mode == QMutex::Recursive
argument_list|)
block|{}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_LINUX_FUTEX
argument_list|)
end_if
begin_decl_stmt
name|class
name|QMutexPrivate
range|:
name|public
name|QMutexData
block|{
name|public
operator|:
operator|~
name|QMutexPrivate
argument_list|()
block|;
name|QMutexPrivate
argument_list|()
block|;
name|bool
name|wait
argument_list|(
argument|int timeout = -
literal|1
argument_list|)
block|;
name|void
name|wakeUp
argument_list|()
name|Q_DECL_NOTHROW
block|;
comment|// Conrol the lifetime of the privates
name|QAtomicInt
name|refCount
block|;
name|int
name|id
block|;
name|bool
name|ref
argument_list|()
block|{
name|Q_ASSERT
argument_list|(
name|refCount
operator|.
name|load
argument_list|()
operator|>=
literal|0
argument_list|)
block|;
name|int
name|c
block|;
do|do
block|{
name|c
operator|=
name|refCount
operator|.
name|load
argument_list|()
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|0
condition|)
return|return
name|false
return|;
block|}
while|while
condition|(
operator|!
name|refCount
operator|.
name|testAndSetRelaxed
argument_list|(
name|c
argument_list|,
name|c
operator|+
literal|1
argument_list|)
condition|)
empty_stmt|;
do|Q_ASSERT(refCount.load(
block|)
operator|>=
literal|0
block|)
block|;
return|return
name|true
return|;
block|}
end_decl_stmt
begin_function
name|void
name|deref
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|refCount
operator|.
name|load
argument_list|()
operator|>=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|refCount
operator|.
name|deref
argument_list|()
condition|)
name|release
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|refCount
operator|.
name|load
argument_list|()
operator|>=
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function_decl
name|void
name|release
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QMutexPrivate
modifier|*
name|allocate
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|QAtomicInt
name|waiters
decl_stmt|;
end_decl_stmt
begin_comment
comment|//number of thread waiting
end_comment
begin_decl_stmt
name|QAtomicInt
name|possiblyUnlocked
decl_stmt|;
end_decl_stmt
begin_comment
comment|//bool saying that a timed wait timed out
end_comment
begin_enum
enum|enum
block|{
name|BigNumber
init|=
literal|0x100000
block|}
enum|;
end_enum
begin_comment
comment|//Must be bigger than the possible number of waiters (number of threads)
end_comment
begin_decl_stmt
name|void
name|derefWaiters
argument_list|(
name|int
name|value
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
end_decl_stmt
begin_comment
comment|//platform specific stuff
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_decl_stmt
name|semaphore_t
name|mach_semaphore
decl_stmt|;
end_decl_stmt
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
end_elif
begin_decl_stmt
name|bool
name|wakeup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|pthread_mutex_t
name|mutex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|pthread_cond_t
name|cond
decl_stmt|;
end_decl_stmt
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_elif
begin_expr_stmt
name|Qt
operator|::
name|HANDLE
name|event
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_LINUX_FUTEX
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMUTEX_P_H
end_comment
end_unit
