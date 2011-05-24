begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// qfutureinterface.h included from qfuture.h
end_comment
begin_include
include|#
directive|include
file|"qfuture.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QFUTURE
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qthread.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qthreadpool.h>
end_include
begin_include
include|#
directive|include
file|<private/qthreadpool_p.h>
end_include
begin_include
include|#
directive|include
file|"qfutureinterface_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|enum
type|{
DECL|enumerator|MaxProgressEmitsPerSecond
name|MaxProgressEmitsPerSecond
init|=
literal|25
end_decl_stmt
begin_constructor
DECL|enumerator|MaxProgressEmitsPerSecond
unit|};
DECL|function|QFutureInterfaceBase
name|QFutureInterfaceBase
operator|::
name|QFutureInterfaceBase
parameter_list|(
name|State
name|initialState
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QFutureInterfaceBasePrivate
argument_list|(
name|initialState
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QFutureInterfaceBase
name|QFutureInterfaceBase
operator|::
name|QFutureInterfaceBase
parameter_list|(
specifier|const
name|QFutureInterfaceBase
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|other
operator|.
name|d
argument_list|)
block|{
name|d
operator|->
name|refCount
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QFutureInterfaceBase
name|QFutureInterfaceBase
operator|::
name|~
name|QFutureInterfaceBase
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|refCount
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|cancel
name|void
name|QFutureInterfaceBase
operator|::
name|cancel
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|state
operator|&
name|Canceled
condition|)
return|return;
name|d
operator|->
name|state
operator|=
name|State
argument_list|(
operator|(
name|d
operator|->
name|state
operator|&
operator|~
name|Paused
operator|)
operator||
name|Canceled
argument_list|)
expr_stmt|;
name|d
operator|->
name|waitCondition
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
name|d
operator|->
name|pausedWaitCondition
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
name|d
operator|->
name|sendCallOut
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Canceled
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setPaused
name|void
name|QFutureInterfaceBase
operator|::
name|setPaused
parameter_list|(
name|bool
name|paused
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|paused
condition|)
block|{
name|d
operator|->
name|state
operator|=
name|State
argument_list|(
name|d
operator|->
name|state
operator||
name|Paused
argument_list|)
expr_stmt|;
name|d
operator|->
name|sendCallOut
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Paused
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|state
operator|=
name|State
argument_list|(
name|d
operator|->
name|state
operator|&
operator|~
name|Paused
argument_list|)
expr_stmt|;
name|d
operator|->
name|pausedWaitCondition
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
name|d
operator|->
name|sendCallOut
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Resumed
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|togglePaused
name|void
name|QFutureInterfaceBase
operator|::
name|togglePaused
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|state
operator|&
name|Paused
condition|)
block|{
name|d
operator|->
name|state
operator|=
name|State
argument_list|(
name|d
operator|->
name|state
operator|&
operator|~
name|Paused
argument_list|)
expr_stmt|;
name|d
operator|->
name|pausedWaitCondition
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
name|d
operator|->
name|sendCallOut
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Resumed
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|state
operator|=
name|State
argument_list|(
name|d
operator|->
name|state
operator||
name|Paused
argument_list|)
expr_stmt|;
name|d
operator|->
name|sendCallOut
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Paused
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setThrottled
name|void
name|QFutureInterfaceBase
operator|::
name|setThrottled
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
comment|// bail out if we are not changing the state
if|if
condition|(
operator|(
name|enable
operator|&&
operator|(
name|d
operator|->
name|state
operator|&
name|Throttled
operator|)
operator|)
operator|||
operator|(
operator|!
name|enable
operator|&&
operator|!
operator|(
name|d
operator|->
name|state
operator|&
name|Throttled
operator|)
operator|)
condition|)
return|return;
comment|// lock and change the state
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|enable
condition|)
block|{
name|d
operator|->
name|state
operator|=
name|State
argument_list|(
name|d
operator|->
name|state
operator||
name|Throttled
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|state
operator|=
name|State
argument_list|(
name|d
operator|->
name|state
operator|&
operator|~
name|Throttled
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|d
operator|->
name|state
operator|&
name|Paused
operator|)
condition|)
name|d
operator|->
name|pausedWaitCondition
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isRunning
name|bool
name|QFutureInterfaceBase
operator|::
name|isRunning
parameter_list|()
specifier|const
block|{
return|return
name|queryState
argument_list|(
name|Running
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isStarted
name|bool
name|QFutureInterfaceBase
operator|::
name|isStarted
parameter_list|()
specifier|const
block|{
return|return
name|queryState
argument_list|(
name|Started
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isCanceled
name|bool
name|QFutureInterfaceBase
operator|::
name|isCanceled
parameter_list|()
specifier|const
block|{
return|return
name|queryState
argument_list|(
name|Canceled
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isFinished
name|bool
name|QFutureInterfaceBase
operator|::
name|isFinished
parameter_list|()
specifier|const
block|{
return|return
name|queryState
argument_list|(
name|Finished
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isPaused
name|bool
name|QFutureInterfaceBase
operator|::
name|isPaused
parameter_list|()
specifier|const
block|{
return|return
name|queryState
argument_list|(
name|Paused
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isThrottled
name|bool
name|QFutureInterfaceBase
operator|::
name|isThrottled
parameter_list|()
specifier|const
block|{
return|return
name|queryState
argument_list|(
name|Throttled
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isResultReadyAt
name|bool
name|QFutureInterfaceBase
operator|::
name|isResultReadyAt
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|internal_isResultReadyAt
argument_list|(
name|index
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|waitForNextResult
name|bool
name|QFutureInterfaceBase
operator|::
name|waitForNextResult
parameter_list|()
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|internal_waitForNextResult
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|waitForResume
name|void
name|QFutureInterfaceBase
operator|::
name|waitForResume
parameter_list|()
block|{
comment|// return early if possible to avoid taking the mutex lock.
if|if
condition|(
operator|(
name|d
operator|->
name|state
operator|&
name|Paused
operator|)
operator|==
literal|false
operator|||
operator|(
name|d
operator|->
name|state
operator|&
name|Canceled
operator|)
condition|)
return|return;
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|d
operator|->
name|state
operator|&
name|Paused
operator|)
operator|==
literal|false
operator|||
operator|(
name|d
operator|->
name|state
operator|&
name|Canceled
operator|)
condition|)
return|return;
comment|// decrease active thread count since this thread will wait.
name|QThreadPool
operator|::
name|globalInstance
argument_list|()
operator|->
name|releaseThread
argument_list|()
expr_stmt|;
name|d
operator|->
name|pausedWaitCondition
operator|.
name|wait
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
expr_stmt|;
name|QThreadPool
operator|::
name|globalInstance
argument_list|()
operator|->
name|reserveThread
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|progressValue
name|int
name|QFutureInterfaceBase
operator|::
name|progressValue
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|m_progressValue
return|;
block|}
end_function
begin_function
DECL|function|progressMinimum
name|int
name|QFutureInterfaceBase
operator|::
name|progressMinimum
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|m_progressMinimum
return|;
block|}
end_function
begin_function
DECL|function|progressMaximum
name|int
name|QFutureInterfaceBase
operator|::
name|progressMaximum
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|m_progressMaximum
return|;
block|}
end_function
begin_function
DECL|function|resultCount
name|int
name|QFutureInterfaceBase
operator|::
name|resultCount
parameter_list|()
specifier|const
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|internal_resultCount
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|progressText
name|QString
name|QFutureInterfaceBase
operator|::
name|progressText
parameter_list|()
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|m_progressText
return|;
block|}
end_function
begin_function
DECL|function|isProgressUpdateNeeded
name|bool
name|QFutureInterfaceBase
operator|::
name|isProgressUpdateNeeded
parameter_list|()
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
return|return
operator|!
name|d
operator|->
name|progressTime
operator|.
name|isValid
argument_list|()
operator|||
operator|(
name|d
operator|->
name|progressTime
operator|.
name|elapsed
argument_list|()
operator|>
operator|(
literal|1000
operator|/
name|MaxProgressEmitsPerSecond
operator|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|reportStarted
name|void
name|QFutureInterfaceBase
operator|::
name|reportStarted
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|d
operator|->
name|state
operator|&
name|Started
operator|)
operator|||
operator|(
name|d
operator|->
name|state
operator|&
name|Canceled
operator|)
operator|||
operator|(
name|d
operator|->
name|state
operator|&
name|Finished
operator|)
condition|)
return|return;
name|d
operator|->
name|setState
argument_list|(
name|State
argument_list|(
name|Started
operator||
name|Running
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|sendCallOut
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Started
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reportCanceled
name|void
name|QFutureInterfaceBase
operator|::
name|reportCanceled
parameter_list|()
block|{
name|cancel
argument_list|()
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
end_ifndef
begin_function
DECL|function|reportException
name|void
name|QFutureInterfaceBase
operator|::
name|reportException
parameter_list|(
specifier|const
name|QtConcurrent
operator|::
name|Exception
modifier|&
name|exception
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|d
operator|->
name|state
operator|&
name|Canceled
operator|)
operator|||
operator|(
name|d
operator|->
name|state
operator|&
name|Finished
operator|)
condition|)
return|return;
name|d
operator|->
name|m_exceptionStore
operator|.
name|setException
argument_list|(
name|exception
argument_list|)
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|State
argument_list|(
name|d
operator|->
name|state
operator||
name|Canceled
argument_list|)
expr_stmt|;
name|d
operator|->
name|waitCondition
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
name|d
operator|->
name|pausedWaitCondition
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
name|d
operator|->
name|sendCallOut
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Canceled
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|reportFinished
name|void
name|QFutureInterfaceBase
operator|::
name|reportFinished
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|d
operator|->
name|state
operator|&
name|Finished
operator|)
condition|)
block|{
name|d
operator|->
name|state
operator|=
name|State
argument_list|(
operator|(
name|d
operator|->
name|state
operator|&
operator|~
name|Running
operator|)
operator||
name|Finished
argument_list|)
expr_stmt|;
name|d
operator|->
name|waitCondition
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
name|d
operator|->
name|sendCallOut
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Finished
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setExpectedResultCount
name|void
name|QFutureInterfaceBase
operator|::
name|setExpectedResultCount
parameter_list|(
name|int
name|resultCount
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|manualProgress
operator|==
literal|false
condition|)
name|setProgressRange
argument_list|(
literal|0
argument_list|,
name|resultCount
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_expectedResultCount
operator|=
name|resultCount
expr_stmt|;
block|}
end_function
begin_function
DECL|function|expectedResultCount
name|int
name|QFutureInterfaceBase
operator|::
name|expectedResultCount
parameter_list|()
block|{
return|return
name|d
operator|->
name|m_expectedResultCount
return|;
block|}
end_function
begin_function
DECL|function|queryState
name|bool
name|QFutureInterfaceBase
operator|::
name|queryState
parameter_list|(
name|State
name|state
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|d
operator|->
name|state
operator|&
name|state
operator|)
return|;
block|}
end_function
begin_function
DECL|function|waitForResult
name|void
name|QFutureInterfaceBase
operator|::
name|waitForResult
parameter_list|(
name|int
name|resultIndex
parameter_list|)
block|{
name|d
operator|->
name|m_exceptionStore
operator|.
name|throwPossibleException
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|d
operator|->
name|state
operator|&
name|Running
operator|)
condition|)
return|return;
comment|// To avoid deadlocks and reduce the number of threads used, try to
comment|// run the runnable in the current thread.
name|QThreadPool
operator|::
name|globalInstance
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|stealRunnable
argument_list|(
name|d
operator|->
name|runnable
argument_list|)
expr_stmt|;
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|d
operator|->
name|state
operator|&
name|Running
operator|)
condition|)
return|return;
specifier|const
name|int
name|waitIndex
init|=
operator|(
name|resultIndex
operator|==
operator|-
literal|1
operator|)
condition|?
name|INT_MAX
else|:
name|resultIndex
decl_stmt|;
while|while
condition|(
operator|(
name|d
operator|->
name|state
operator|&
name|Running
operator|)
operator|&&
name|d
operator|->
name|internal_isResultReadyAt
argument_list|(
name|waitIndex
argument_list|)
operator|==
literal|false
condition|)
name|d
operator|->
name|waitCondition
operator|.
name|wait
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_exceptionStore
operator|.
name|throwPossibleException
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForFinished
name|void
name|QFutureInterfaceBase
operator|::
name|waitForFinished
parameter_list|()
block|{
if|if
condition|(
name|d
operator|->
name|state
operator|&
name|Running
condition|)
block|{
name|QThreadPool
operator|::
name|globalInstance
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|stealRunnable
argument_list|(
name|d
operator|->
name|runnable
argument_list|)
expr_stmt|;
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
while|while
condition|(
name|d
operator|->
name|state
operator|&
name|Running
condition|)
name|d
operator|->
name|waitCondition
operator|.
name|wait
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|m_exceptionStore
operator|.
name|throwPossibleException
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reportResultsReady
name|void
name|QFutureInterfaceBase
operator|::
name|reportResultsReady
parameter_list|(
name|int
name|beginIndex
parameter_list|,
name|int
name|endIndex
parameter_list|)
block|{
if|if
condition|(
operator|(
name|d
operator|->
name|state
operator|&
name|Canceled
operator|)
operator|||
operator|(
name|d
operator|->
name|state
operator|&
name|Finished
operator|)
operator|||
name|beginIndex
operator|==
name|endIndex
condition|)
return|return;
name|d
operator|->
name|waitCondition
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|manualProgress
operator|==
literal|false
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|internal_updateProgress
argument_list|(
name|d
operator|->
name|m_progressValue
operator|+
name|endIndex
operator|-
name|beginIndex
argument_list|)
operator|==
literal|false
condition|)
block|{
name|d
operator|->
name|sendCallOut
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|ResultsReady
argument_list|,
name|beginIndex
argument_list|,
name|endIndex
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|sendCallOuts
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Progress
argument_list|,
name|d
operator|->
name|m_progressValue
argument_list|,
name|d
operator|->
name|m_progressText
argument_list|)
argument_list|,
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|ResultsReady
argument_list|,
name|beginIndex
argument_list|,
name|endIndex
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|sendCallOut
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|ResultsReady
argument_list|,
name|beginIndex
argument_list|,
name|endIndex
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setRunnable
name|void
name|QFutureInterfaceBase
operator|::
name|setRunnable
parameter_list|(
name|QRunnable
modifier|*
name|runnable
parameter_list|)
block|{
name|d
operator|->
name|runnable
operator|=
name|runnable
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setFilterMode
name|void
name|QFutureInterfaceBase
operator|::
name|setFilterMode
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
name|resultStoreBase
argument_list|()
operator|.
name|setFilterMode
argument_list|(
name|enable
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setProgressRange
name|void
name|QFutureInterfaceBase
operator|::
name|setProgressRange
parameter_list|(
name|int
name|minimum
parameter_list|,
name|int
name|maximum
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
name|d
operator|->
name|m_progressMinimum
operator|=
name|minimum
expr_stmt|;
name|d
operator|->
name|m_progressMaximum
operator|=
name|maximum
expr_stmt|;
name|d
operator|->
name|sendCallOut
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|ProgressRange
argument_list|,
name|minimum
argument_list|,
name|maximum
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setProgressValue
name|void
name|QFutureInterfaceBase
operator|::
name|setProgressValue
parameter_list|(
name|int
name|progressValue
parameter_list|)
block|{
name|setProgressValueAndText
argument_list|(
name|progressValue
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setProgressValueAndText
name|void
name|QFutureInterfaceBase
operator|::
name|setProgressValueAndText
parameter_list|(
name|int
name|progressValue
parameter_list|,
specifier|const
name|QString
modifier|&
name|progressText
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|m_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|manualProgress
operator|==
literal|false
condition|)
name|d
operator|->
name|manualProgress
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_progressValue
operator|>=
name|progressValue
condition|)
return|return;
if|if
condition|(
operator|(
name|d
operator|->
name|state
operator|&
name|Canceled
operator|)
operator|||
operator|(
name|d
operator|->
name|state
operator|&
name|Finished
operator|)
condition|)
return|return;
if|if
condition|(
name|d
operator|->
name|internal_updateProgress
argument_list|(
name|progressValue
argument_list|,
name|progressText
argument_list|)
condition|)
block|{
name|d
operator|->
name|sendCallOut
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Progress
argument_list|,
name|d
operator|->
name|m_progressValue
argument_list|,
name|d
operator|->
name|m_progressText
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|mutex
name|QMutex
modifier|*
name|QFutureInterfaceBase
operator|::
name|mutex
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|d
operator|->
name|m_mutex
return|;
block|}
end_function
begin_function
DECL|function|exceptionStore
name|QtConcurrent
operator|::
name|internal
operator|::
name|ExceptionStore
modifier|&
name|QFutureInterfaceBase
operator|::
name|exceptionStore
parameter_list|()
block|{
return|return
name|d
operator|->
name|m_exceptionStore
return|;
block|}
end_function
begin_function
DECL|function|resultStoreBase
name|QtConcurrent
operator|::
name|ResultStoreBase
modifier|&
name|QFutureInterfaceBase
operator|::
name|resultStoreBase
parameter_list|()
block|{
return|return
name|d
operator|->
name|m_results
return|;
block|}
end_function
begin_function
DECL|function|resultStoreBase
specifier|const
name|QtConcurrent
operator|::
name|ResultStoreBase
modifier|&
name|QFutureInterfaceBase
operator|::
name|resultStoreBase
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|m_results
return|;
block|}
end_function
begin_function
DECL|function|operator =
name|QFutureInterfaceBase
modifier|&
name|QFutureInterfaceBase
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QFutureInterfaceBase
modifier|&
name|other
parameter_list|)
block|{
name|other
operator|.
name|d
operator|->
name|refCount
operator|.
name|ref
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|refCount
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_function
DECL|function|referenceCountIsOne
name|bool
name|QFutureInterfaceBase
operator|::
name|referenceCountIsOne
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|refCount
operator|==
literal|1
return|;
block|}
end_function
begin_constructor
DECL|function|QFutureInterfaceBasePrivate
name|QFutureInterfaceBasePrivate
operator|::
name|QFutureInterfaceBasePrivate
parameter_list|(
name|QFutureInterfaceBase
operator|::
name|State
name|initialState
parameter_list|)
member_init_list|:
name|refCount
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|m_progressValue
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_progressMinimum
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_progressMaximum
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|state
argument_list|(
name|initialState
argument_list|)
member_init_list|,
name|pendingResults
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|manualProgress
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_expectedResultCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|runnable
argument_list|(
literal|0
argument_list|)
block|{
name|progressTime
operator|.
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|internal_resultCount
name|int
name|QFutureInterfaceBasePrivate
operator|::
name|internal_resultCount
parameter_list|()
specifier|const
block|{
return|return
name|m_results
operator|.
name|count
argument_list|()
return|;
comment|// ### subtract canceled results.
block|}
end_function
begin_function
DECL|function|internal_isResultReadyAt
name|bool
name|QFutureInterfaceBasePrivate
operator|::
name|internal_isResultReadyAt
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|m_results
operator|.
name|contains
argument_list|(
name|index
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|internal_waitForNextResult
name|bool
name|QFutureInterfaceBasePrivate
operator|::
name|internal_waitForNextResult
parameter_list|()
block|{
if|if
condition|(
name|m_results
operator|.
name|hasNextResult
argument_list|()
condition|)
return|return
literal|true
return|;
while|while
condition|(
operator|(
name|state
operator|&
name|QFutureInterfaceBase
operator|::
name|Running
operator|)
operator|&&
name|m_results
operator|.
name|hasNextResult
argument_list|()
operator|==
literal|false
condition|)
name|waitCondition
operator|.
name|wait
argument_list|(
operator|&
name|m_mutex
argument_list|)
expr_stmt|;
return|return
operator|(
operator|!
operator|(
name|state
operator|&
name|QFutureInterfaceBase
operator|::
name|Canceled
operator|)
operator|&&
name|m_results
operator|.
name|hasNextResult
argument_list|()
operator|)
return|;
block|}
end_function
begin_function
DECL|function|internal_updateProgress
name|bool
name|QFutureInterfaceBasePrivate
operator|::
name|internal_updateProgress
parameter_list|(
name|int
name|progress
parameter_list|,
specifier|const
name|QString
modifier|&
name|progressText
parameter_list|)
block|{
if|if
condition|(
name|m_progressValue
operator|>=
name|progress
condition|)
return|return
literal|false
return|;
name|m_progressValue
operator|=
name|progress
expr_stmt|;
name|m_progressText
operator|=
name|progressText
expr_stmt|;
if|if
condition|(
name|progressTime
operator|.
name|isValid
argument_list|()
operator|&&
name|m_progressValue
operator|!=
name|m_progressMaximum
condition|)
comment|// make sure the first and last steps are emitted.
if|if
condition|(
name|progressTime
operator|.
name|elapsed
argument_list|()
operator|<
operator|(
literal|1000
operator|/
name|MaxProgressEmitsPerSecond
operator|)
condition|)
return|return
literal|false
return|;
name|progressTime
operator|.
name|start
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|internal_setThrottled
name|void
name|QFutureInterfaceBasePrivate
operator|::
name|internal_setThrottled
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
comment|// bail out if we are not changing the state
if|if
condition|(
operator|(
name|enable
operator|&&
operator|(
name|state
operator|&
name|QFutureInterfaceBase
operator|::
name|Throttled
operator|)
operator|)
operator|||
operator|(
operator|!
name|enable
operator|&&
operator|!
operator|(
name|state
operator|&
name|QFutureInterfaceBase
operator|::
name|Throttled
operator|)
operator|)
condition|)
return|return;
comment|// change the state
if|if
condition|(
name|enable
condition|)
block|{
name|state
operator|=
name|QFutureInterfaceBase
operator|::
name|State
argument_list|(
name|state
operator||
name|QFutureInterfaceBase
operator|::
name|Throttled
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|state
operator|=
name|QFutureInterfaceBase
operator|::
name|State
argument_list|(
name|state
operator|&
operator|~
name|QFutureInterfaceBase
operator|::
name|Throttled
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|state
operator|&
name|QFutureInterfaceBase
operator|::
name|Paused
operator|)
condition|)
name|pausedWaitCondition
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|sendCallOut
name|void
name|QFutureInterfaceBasePrivate
operator|::
name|sendCallOut
parameter_list|(
specifier|const
name|QFutureCallOutEvent
modifier|&
name|callOutEvent
parameter_list|)
block|{
if|if
condition|(
name|outputConnections
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|outputConnections
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|outputConnections
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|postCallOutEvent
argument_list|(
name|callOutEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sendCallOuts
name|void
name|QFutureInterfaceBasePrivate
operator|::
name|sendCallOuts
parameter_list|(
specifier|const
name|QFutureCallOutEvent
modifier|&
name|callOutEvent1
parameter_list|,
specifier|const
name|QFutureCallOutEvent
modifier|&
name|callOutEvent2
parameter_list|)
block|{
if|if
condition|(
name|outputConnections
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|outputConnections
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QFutureCallOutInterface
modifier|*
name|interface
init|=
name|outputConnections
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|interface
operator|->
name|postCallOutEvent
argument_list|(
name|callOutEvent1
argument_list|)
expr_stmt|;
name|interface
operator|->
name|postCallOutEvent
argument_list|(
name|callOutEvent2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|// This function connects an output interface (for example a QFutureWatcher)
end_comment
begin_comment
comment|// to this future. While holding the lock we check the state and ready results
end_comment
begin_comment
comment|// and add the appropriate callouts to the queue. In order to avoid deadlocks,
end_comment
begin_comment
comment|// the actual callouts are made at the end while not holding the lock.
end_comment
begin_function
DECL|function|connectOutputInterface
name|void
name|QFutureInterfaceBasePrivate
operator|::
name|connectOutputInterface
parameter_list|(
name|QFutureCallOutInterface
modifier|*
name|interface
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|state
operator|&
name|QFutureInterfaceBase
operator|::
name|Started
condition|)
block|{
name|interface
operator|->
name|postCallOutEvent
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Started
argument_list|)
argument_list|)
expr_stmt|;
name|interface
operator|->
name|postCallOutEvent
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|ProgressRange
argument_list|,
name|m_progressMinimum
argument_list|,
name|m_progressMaximum
argument_list|)
argument_list|)
expr_stmt|;
name|interface
operator|->
name|postCallOutEvent
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Progress
argument_list|,
name|m_progressValue
argument_list|,
name|m_progressText
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QtConcurrent
operator|::
name|ResultIteratorBase
name|it
init|=
name|m_results
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|m_results
operator|.
name|end
argument_list|()
condition|)
block|{
specifier|const
name|int
name|begin
init|=
name|it
operator|.
name|resultIndex
argument_list|()
decl_stmt|;
specifier|const
name|int
name|end
init|=
name|begin
operator|+
name|it
operator|.
name|batchSize
argument_list|()
decl_stmt|;
name|interface
operator|->
name|postCallOutEvent
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|ResultsReady
argument_list|,
name|begin
argument_list|,
name|end
argument_list|)
argument_list|)
expr_stmt|;
name|it
operator|.
name|batchedAdvance
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|state
operator|&
name|QFutureInterfaceBase
operator|::
name|Paused
condition|)
name|interface
operator|->
name|postCallOutEvent
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Paused
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|&
name|QFutureInterfaceBase
operator|::
name|Canceled
condition|)
name|interface
operator|->
name|postCallOutEvent
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Canceled
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|&
name|QFutureInterfaceBase
operator|::
name|Finished
condition|)
name|interface
operator|->
name|postCallOutEvent
argument_list|(
name|QFutureCallOutEvent
argument_list|(
name|QFutureCallOutEvent
operator|::
name|Finished
argument_list|)
argument_list|)
expr_stmt|;
name|outputConnections
operator|.
name|append
argument_list|(
name|interface
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|disconnectOutputInterface
name|void
name|QFutureInterfaceBasePrivate
operator|::
name|disconnectOutputInterface
parameter_list|(
name|QFutureCallOutInterface
modifier|*
name|interface
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
specifier|const
name|int
name|index
init|=
name|outputConnections
operator|.
name|indexOf
argument_list|(
name|interface
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|==
operator|-
literal|1
condition|)
return|return;
name|outputConnections
operator|.
name|removeAt
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|interface
operator|->
name|callOutInterfaceDisconnected
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setState
name|void
name|QFutureInterfaceBasePrivate
operator|::
name|setState
parameter_list|(
name|QFutureInterfaceBase
operator|::
name|State
name|newState
parameter_list|)
block|{
name|state
operator|=
name|newState
expr_stmt|;
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
comment|// QT_NO_CONCURRENT
end_comment
end_unit
