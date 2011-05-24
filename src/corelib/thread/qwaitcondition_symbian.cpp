begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qwaitcondition.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|"qreadwritelock.h"
end_include
begin_include
include|#
directive|include
file|"qatomic.h"
end_include
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_include
include|#
directive|include
file|"qmutex_p.h"
end_include
begin_include
include|#
directive|include
file|"qreadwritelock_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|report_error
specifier|static
name|void
name|report_error
parameter_list|(
name|int
name|err
parameter_list|,
specifier|const
name|char
modifier|*
name|where
parameter_list|,
specifier|const
name|char
modifier|*
name|what
parameter_list|)
block|{
if|if
condition|(
name|err
operator|!=
name|KErrNone
condition|)
name|qWarning
argument_list|(
literal|"%s: %s failure: %d"
argument_list|,
name|where
argument_list|,
name|what
argument_list|,
name|err
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QWaitConditionPrivate
class|class
name|QWaitConditionPrivate
block|{
public|public:
DECL|member|mutex
name|RMutex
name|mutex
decl_stmt|;
DECL|member|cond
name|RCondVar
name|cond
decl_stmt|;
DECL|member|waiters
name|int
name|waiters
decl_stmt|;
DECL|member|wakeups
name|int
name|wakeups
decl_stmt|;
DECL|function|QWaitConditionPrivate
name|QWaitConditionPrivate
parameter_list|()
member_init_list|:
name|waiters
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|wakeups
argument_list|(
literal|0
argument_list|)
block|{
name|qt_symbian_throwIfError
argument_list|(
name|mutex
operator|.
name|CreateLocal
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|err
init|=
name|cond
operator|.
name|CreateLocal
argument_list|()
decl_stmt|;
if|if
condition|(
name|err
operator|!=
name|KErrNone
condition|)
block|{
name|mutex
operator|.
name|Close
argument_list|()
expr_stmt|;
name|qt_symbian_throwIfError
argument_list|(
name|err
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|~QWaitConditionPrivate
name|~
name|QWaitConditionPrivate
parameter_list|()
block|{
name|cond
operator|.
name|Close
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|Close
argument_list|()
expr_stmt|;
block|}
DECL|function|wait
name|bool
name|wait
parameter_list|(
name|unsigned
name|long
name|time
parameter_list|)
block|{
name|TInt
name|err
init|=
name|KErrNone
decl_stmt|;
if|if
condition|(
name|time
operator|==
name|ULONG_MAX
condition|)
block|{
comment|// untimed wait, loop because RCondVar::Wait may return before the condition is triggered
do|do
block|{
name|err
operator|=
name|cond
operator|.
name|Wait
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|err
operator|==
name|KErrNone
operator|&&
name|wakeups
operator|==
literal|0
condition|)
do|;
block|}
else|else
block|{
name|unsigned
name|long
name|maxWait
init|=
name|KMaxTInt
operator|/
literal|1000
decl_stmt|;
name|QElapsedTimer
name|waitTimer
decl_stmt|;
do|do
block|{
name|waitTimer
operator|.
name|start
argument_list|()
expr_stmt|;
name|unsigned
name|long
name|waitTime
init|=
name|qMin
argument_list|(
name|maxWait
argument_list|,
name|time
argument_list|)
decl_stmt|;
comment|// wait at least 1ms, as 0 means no wait
name|err
operator|=
name|cond
operator|.
name|TimedWait
argument_list|(
name|mutex
argument_list|,
name|qMax
argument_list|(
literal|1ul
argument_list|,
name|waitTime
argument_list|)
operator|*
literal|1000
argument_list|)
expr_stmt|;
comment|// RCondVar::TimedWait may return before the condition is triggered, update the timeout with actual wait time
name|time
operator|-=
name|qMin
argument_list|(
operator|(
name|unsigned
name|long
operator|)
name|waitTimer
operator|.
name|elapsed
argument_list|()
argument_list|,
name|waitTime
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|err
operator|==
name|KErrNone
operator|&&
name|wakeups
operator|==
literal|0
operator|)
operator|||
operator|(
name|err
operator|==
name|KErrTimedOut
operator|&&
name|time
operator|>
literal|0
operator|)
condition|)
do|;
block|}
name|Q_ASSERT_X
argument_list|(
name|waiters
operator|>
literal|0
argument_list|,
literal|"QWaitCondition::wait"
argument_list|,
literal|"internal error (waiters)"
argument_list|)
expr_stmt|;
operator|--
name|waiters
expr_stmt|;
if|if
condition|(
name|err
operator|==
name|KErrNone
condition|)
block|{
name|Q_ASSERT_X
argument_list|(
name|wakeups
operator|>
literal|0
argument_list|,
literal|"QWaitCondition::wait"
argument_list|,
literal|"internal error (wakeups)"
argument_list|)
expr_stmt|;
operator|--
name|wakeups
expr_stmt|;
block|}
name|mutex
operator|.
name|Signal
argument_list|()
expr_stmt|;
if|if
condition|(
name|err
operator|&&
name|err
operator|!=
name|KErrTimedOut
condition|)
name|report_error
argument_list|(
name|err
argument_list|,
literal|"QWaitCondition::wait()"
argument_list|,
literal|"cv wait"
argument_list|)
expr_stmt|;
return|return
name|err
operator|==
name|KErrNone
return|;
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|QWaitCondition
name|QWaitCondition
operator|::
name|QWaitCondition
parameter_list|()
block|{
name|d
operator|=
operator|new
name|QWaitConditionPrivate
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaitCondition
name|QWaitCondition
operator|::
name|~
name|QWaitCondition
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|wakeOne
name|void
name|QWaitCondition
operator|::
name|wakeOne
parameter_list|()
block|{
name|d
operator|->
name|mutex
operator|.
name|Wait
argument_list|()
expr_stmt|;
name|d
operator|->
name|wakeups
operator|=
name|qMin
argument_list|(
name|d
operator|->
name|wakeups
operator|+
literal|1
argument_list|,
name|d
operator|->
name|waiters
argument_list|)
expr_stmt|;
name|d
operator|->
name|cond
operator|.
name|Signal
argument_list|()
expr_stmt|;
name|d
operator|->
name|mutex
operator|.
name|Signal
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wakeAll
name|void
name|QWaitCondition
operator|::
name|wakeAll
parameter_list|()
block|{
name|d
operator|->
name|mutex
operator|.
name|Wait
argument_list|()
expr_stmt|;
name|d
operator|->
name|wakeups
operator|=
name|d
operator|->
name|waiters
expr_stmt|;
name|d
operator|->
name|cond
operator|.
name|Broadcast
argument_list|()
expr_stmt|;
name|d
operator|->
name|mutex
operator|.
name|Signal
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wait
name|bool
name|QWaitCondition
operator|::
name|wait
parameter_list|(
name|QMutex
modifier|*
name|mutex
parameter_list|,
name|unsigned
name|long
name|time
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mutex
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|mutex
operator|->
name|d
operator|->
name|recursive
condition|)
block|{
name|qWarning
argument_list|(
literal|"QWaitCondition: cannot wait on recursive mutexes"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|d
operator|->
name|mutex
operator|.
name|Wait
argument_list|()
expr_stmt|;
operator|++
name|d
operator|->
name|waiters
expr_stmt|;
name|mutex
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|bool
name|returnValue
init|=
name|d
operator|->
name|wait
argument_list|(
name|time
argument_list|)
decl_stmt|;
name|mutex
operator|->
name|lock
argument_list|()
expr_stmt|;
return|return
name|returnValue
return|;
block|}
end_function
begin_function
DECL|function|wait
name|bool
name|QWaitCondition
operator|::
name|wait
parameter_list|(
name|QReadWriteLock
modifier|*
name|readWriteLock
parameter_list|,
name|unsigned
name|long
name|time
parameter_list|)
block|{
if|if
condition|(
operator|!
name|readWriteLock
operator|||
name|readWriteLock
operator|->
name|d
operator|->
name|accessCount
operator|==
literal|0
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|readWriteLock
operator|->
name|d
operator|->
name|accessCount
operator|<
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QWaitCondition: cannot wait on QReadWriteLocks with recursive lockForWrite()"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|d
operator|->
name|mutex
operator|.
name|Wait
argument_list|()
expr_stmt|;
operator|++
name|d
operator|->
name|waiters
expr_stmt|;
name|int
name|previousAccessCount
init|=
name|readWriteLock
operator|->
name|d
operator|->
name|accessCount
decl_stmt|;
name|readWriteLock
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|bool
name|returnValue
init|=
name|d
operator|->
name|wait
argument_list|(
name|time
argument_list|)
decl_stmt|;
if|if
condition|(
name|previousAccessCount
operator|<
literal|0
condition|)
name|readWriteLock
operator|->
name|lockForWrite
argument_list|()
expr_stmt|;
else|else
name|readWriteLock
operator|->
name|lockForRead
argument_list|()
expr_stmt|;
return|return
name|returnValue
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
comment|// QT_NO_THREAD
end_comment
end_unit
