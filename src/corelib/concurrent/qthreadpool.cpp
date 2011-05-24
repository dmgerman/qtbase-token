begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qthreadpool.h"
end_include
begin_include
include|#
directive|include
file|"qthreadpool_p.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|operator <
specifier|inline
name|bool
name|operator
name|<
parameter_list|(
name|int
name|priority
parameter_list|,
specifier|const
name|QPair
argument_list|<
name|QRunnable
modifier|*
argument_list|,
name|int
argument_list|>
modifier|&
name|p
parameter_list|)
block|{
return|return
name|p
operator|.
name|second
operator|<
name|priority
return|;
block|}
end_function
begin_function
DECL|function|operator <
specifier|inline
name|bool
name|operator
name|<
parameter_list|(
specifier|const
name|QPair
argument_list|<
name|QRunnable
modifier|*
argument_list|,
name|int
argument_list|>
modifier|&
name|p
parameter_list|,
name|int
name|priority
parameter_list|)
block|{
return|return
name|priority
operator|<
name|p
operator|.
name|second
return|;
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QThreadPool
argument_list|,
argument|theInstance
argument_list|)
end_macro
begin_comment
comment|/*     QThread wrapper, provides synchronizitaion against a ThreadPool */
end_comment
begin_class
DECL|class|QThreadPoolThread
class|class
name|QThreadPoolThread
super|:
specifier|public
name|QThread
block|{
public|public:
name|QThreadPoolThread
parameter_list|(
name|QThreadPoolPrivate
modifier|*
name|manager
parameter_list|)
constructor_decl|;
name|void
name|run
parameter_list|()
function_decl|;
name|void
name|registerTheadInactive
parameter_list|()
function_decl|;
DECL|member|manager
name|QThreadPoolPrivate
modifier|*
name|manager
decl_stmt|;
DECL|member|runnable
name|QRunnable
modifier|*
name|runnable
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*     QThreadPool private class. */
end_comment
begin_comment
comment|/*!\internal  */
end_comment
begin_constructor
DECL|function|QThreadPoolThread
name|QThreadPoolThread
operator|::
name|QThreadPoolThread
parameter_list|(
name|QThreadPoolPrivate
modifier|*
name|manager
parameter_list|)
member_init_list|:
name|manager
argument_list|(
name|manager
argument_list|)
member_init_list|,
name|runnable
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/* \internal  */
end_comment
begin_function
DECL|function|run
name|void
name|QThreadPoolThread
operator|::
name|run
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|manager
operator|->
name|mutex
argument_list|)
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|QRunnable
modifier|*
name|r
init|=
name|runnable
decl_stmt|;
name|runnable
operator|=
literal|0
expr_stmt|;
do|do
block|{
if|if
condition|(
name|r
condition|)
block|{
specifier|const
name|bool
name|autoDelete
init|=
name|r
operator|->
name|autoDelete
argument_list|()
decl_stmt|;
comment|// run the task
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
try|try
block|{
endif|#
directive|endif
name|r
operator|->
name|run
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
block|}
catch|catch
parameter_list|(
modifier|...
parameter_list|)
block|{
name|qWarning
argument_list|(
literal|"Qt Concurrent has caught an exception thrown from a worker thread.\n"
literal|"This is not supported, exceptions thrown in worker threads must be\n"
literal|"caught before control returns to Qt Concurrent."
argument_list|)
expr_stmt|;
name|registerTheadInactive
argument_list|()
expr_stmt|;
throw|throw;
block|}
endif|#
directive|endif
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
if|if
condition|(
name|autoDelete
operator|&&
operator|!
operator|--
name|r
operator|->
name|ref
condition|)
operator|delete
name|r
expr_stmt|;
block|}
comment|// if too many threads are active, expire this thread
if|if
condition|(
name|manager
operator|->
name|tooManyThreadsActive
argument_list|()
condition|)
break|break;
name|r
operator|=
operator|!
name|manager
operator|->
name|queue
operator|.
name|isEmpty
argument_list|()
condition|?
name|manager
operator|->
name|queue
operator|.
name|takeFirst
argument_list|()
operator|.
name|first
else|:
literal|0
expr_stmt|;
block|}
do|while
condition|(
name|r
operator|!=
literal|0
condition|)
do|;
if|if
condition|(
name|manager
operator|->
name|isExiting
condition|)
block|{
name|registerTheadInactive
argument_list|()
expr_stmt|;
break|break;
block|}
comment|// if too many threads are active, expire this thread
name|bool
name|expired
init|=
name|manager
operator|->
name|tooManyThreadsActive
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|expired
condition|)
block|{
operator|++
name|manager
operator|->
name|waitingThreads
expr_stmt|;
name|registerTheadInactive
argument_list|()
expr_stmt|;
comment|// wait for work, exiting after the expiry timeout is reached
name|expired
operator|=
operator|!
name|manager
operator|->
name|runnableReady
operator|.
name|wait
argument_list|(
name|locker
operator|.
name|mutex
argument_list|()
argument_list|,
name|manager
operator|->
name|expiryTimeout
argument_list|)
expr_stmt|;
operator|++
name|manager
operator|->
name|activeThreads
expr_stmt|;
if|if
condition|(
name|expired
condition|)
operator|--
name|manager
operator|->
name|waitingThreads
expr_stmt|;
block|}
if|if
condition|(
name|expired
condition|)
block|{
name|manager
operator|->
name|expiredThreads
operator|.
name|enqueue
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|registerTheadInactive
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function
begin_function
DECL|function|registerTheadInactive
name|void
name|QThreadPoolThread
operator|::
name|registerTheadInactive
parameter_list|()
block|{
if|if
condition|(
operator|--
name|manager
operator|->
name|activeThreads
operator|==
literal|0
condition|)
name|manager
operator|->
name|noActiveThreads
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/* \internal  */
end_comment
begin_constructor
DECL|function|QThreadPoolPrivate
name|QThreadPoolPrivate
operator|::
name|QThreadPoolPrivate
parameter_list|()
member_init_list|:
name|isExiting
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|expiryTimeout
argument_list|(
literal|30000
argument_list|)
member_init_list|,
name|maxThreadCount
argument_list|(
name|qAbs
argument_list|(
name|QThread
operator|::
name|idealThreadCount
argument_list|()
argument_list|)
argument_list|)
member_init_list|,
name|reservedThreads
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|waitingThreads
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|activeThreads
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|tryStart
name|bool
name|QThreadPoolPrivate
operator|::
name|tryStart
parameter_list|(
name|QRunnable
modifier|*
name|task
parameter_list|)
block|{
if|if
condition|(
name|allThreads
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// always create at least one thread
name|startThread
argument_list|(
name|task
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
comment|// can't do anything if we're over the limit
if|if
condition|(
name|activeThreadCount
argument_list|()
operator|>=
name|maxThreadCount
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|waitingThreads
operator|>
literal|0
condition|)
block|{
comment|// recycle an available thread
operator|--
name|waitingThreads
expr_stmt|;
name|enqueueTask
argument_list|(
name|task
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
operator|!
name|expiredThreads
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// restart an expired thread
name|QThreadPoolThread
modifier|*
name|thread
init|=
name|expiredThreads
operator|.
name|dequeue
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|thread
operator|->
name|runnable
operator|==
literal|0
argument_list|)
expr_stmt|;
operator|++
name|activeThreads
expr_stmt|;
if|if
condition|(
name|task
operator|->
name|autoDelete
argument_list|()
condition|)
operator|++
name|task
operator|->
name|ref
expr_stmt|;
name|thread
operator|->
name|runnable
operator|=
name|task
expr_stmt|;
name|thread
operator|->
name|start
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
comment|// start a new thread
name|startThread
argument_list|(
name|task
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|enqueueTask
name|void
name|QThreadPoolPrivate
operator|::
name|enqueueTask
parameter_list|(
name|QRunnable
modifier|*
name|runnable
parameter_list|,
name|int
name|priority
parameter_list|)
block|{
if|if
condition|(
name|runnable
operator|->
name|autoDelete
argument_list|()
condition|)
operator|++
name|runnable
operator|->
name|ref
expr_stmt|;
comment|// put it on the queue
name|QList
argument_list|<
name|QPair
argument_list|<
name|QRunnable
modifier|*
argument_list|,
name|int
argument_list|>
argument_list|>
operator|::
name|iterator
name|at
init|=
name|qUpperBound
argument_list|(
name|queue
operator|.
name|begin
argument_list|()
argument_list|,
name|queue
operator|.
name|end
argument_list|()
argument_list|,
name|priority
argument_list|)
decl_stmt|;
name|queue
operator|.
name|insert
argument_list|(
name|at
argument_list|,
name|qMakePair
argument_list|(
name|runnable
argument_list|,
name|priority
argument_list|)
argument_list|)
expr_stmt|;
name|runnableReady
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|activeThreadCount
name|int
name|QThreadPoolPrivate
operator|::
name|activeThreadCount
parameter_list|()
specifier|const
block|{
comment|// To improve scalability this function is called without holding
comment|// the mutex lock -- keep it thread-safe.
return|return
operator|(
name|allThreads
operator|.
name|count
argument_list|()
operator|-
name|expiredThreads
operator|.
name|count
argument_list|()
operator|-
name|waitingThreads
operator|+
name|reservedThreads
operator|)
return|;
block|}
end_function
begin_function
DECL|function|tryToStartMoreThreads
name|void
name|QThreadPoolPrivate
operator|::
name|tryToStartMoreThreads
parameter_list|()
block|{
comment|// try to push tasks on the queue to any available threads
while|while
condition|(
operator|!
name|queue
operator|.
name|isEmpty
argument_list|()
operator|&&
name|tryStart
argument_list|(
name|queue
operator|.
name|first
argument_list|()
operator|.
name|first
argument_list|)
condition|)
name|queue
operator|.
name|removeFirst
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tooManyThreadsActive
name|bool
name|QThreadPoolPrivate
operator|::
name|tooManyThreadsActive
parameter_list|()
specifier|const
block|{
specifier|const
name|int
name|activeThreadCount
init|=
name|this
operator|->
name|activeThreadCount
argument_list|()
decl_stmt|;
return|return
name|activeThreadCount
operator|>
name|maxThreadCount
operator|&&
operator|(
name|activeThreadCount
operator|-
name|reservedThreads
operator|)
operator|>
literal|1
return|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|startThread
name|void
name|QThreadPoolPrivate
operator|::
name|startThread
parameter_list|(
name|QRunnable
modifier|*
name|runnable
parameter_list|)
block|{
name|QScopedPointer
argument_list|<
name|QThreadPoolThread
argument_list|>
name|thread
argument_list|(
operator|new
name|QThreadPoolThread
argument_list|(
name|this
argument_list|)
argument_list|)
decl_stmt|;
name|thread
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"Thread (pooled)"
argument_list|)
argument_list|)
expr_stmt|;
name|allThreads
operator|.
name|insert
argument_list|(
name|thread
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
operator|++
name|activeThreads
expr_stmt|;
if|if
condition|(
name|runnable
operator|->
name|autoDelete
argument_list|()
condition|)
operator|++
name|runnable
operator|->
name|ref
expr_stmt|;
name|thread
operator|->
name|runnable
operator|=
name|runnable
expr_stmt|;
name|thread
operator|.
name|take
argument_list|()
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal     Makes all threads exit, waits for each tread to exit and deletes it. */
end_comment
begin_function
DECL|function|reset
name|void
name|QThreadPoolPrivate
operator|::
name|reset
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|isExiting
operator|=
literal|true
expr_stmt|;
name|runnableReady
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
do|do
block|{
comment|// make a copy of the set so that we can iterate without the lock
name|QSet
argument_list|<
name|QThreadPoolThread
modifier|*
argument_list|>
name|allThreadsCopy
init|=
name|allThreads
decl_stmt|;
name|allThreads
operator|.
name|clear
argument_list|()
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|QThreadPoolThread
modifier|*
name|thread
decl|,
name|allThreadsCopy
control|)
block|{
name|thread
operator|->
name|wait
argument_list|()
expr_stmt|;
operator|delete
name|thread
expr_stmt|;
block|}
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
comment|// repeat until all newly arrived threads have also completed
block|}
do|while
condition|(
operator|!
name|allThreads
operator|.
name|isEmpty
argument_list|()
condition|)
do|;
name|waitingThreads
operator|=
literal|0
expr_stmt|;
name|expiredThreads
operator|.
name|clear
argument_list|()
expr_stmt|;
name|isExiting
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForDone
name|bool
name|QThreadPoolPrivate
operator|::
name|waitForDone
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|msecs
operator|<
literal|0
condition|)
block|{
while|while
condition|(
operator|!
operator|(
name|queue
operator|.
name|isEmpty
argument_list|()
operator|&&
name|activeThreads
operator|==
literal|0
operator|)
condition|)
name|noActiveThreads
operator|.
name|wait
argument_list|(
name|locker
operator|.
name|mutex
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QElapsedTimer
name|timer
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
name|int
name|t
decl_stmt|;
while|while
condition|(
operator|!
operator|(
name|queue
operator|.
name|isEmpty
argument_list|()
operator|&&
name|activeThreads
operator|==
literal|0
operator|)
operator|&&
operator|(
operator|(
name|t
operator|=
name|msecs
operator|-
name|timer
operator|.
name|elapsed
argument_list|()
operator|)
operator|>
literal|0
operator|)
condition|)
name|noActiveThreads
operator|.
name|wait
argument_list|(
name|locker
operator|.
name|mutex
argument_list|()
argument_list|,
name|t
argument_list|)
expr_stmt|;
block|}
return|return
name|queue
operator|.
name|isEmpty
argument_list|()
operator|&&
name|activeThreads
operator|==
literal|0
return|;
block|}
end_function
begin_comment
comment|/*! \internal     Pulls a runnable from the front queue and runs it in the current thread. Blocks     until the runnable has completed. Returns true if a runnable was found. */
end_comment
begin_function
DECL|function|startFrontRunnable
name|bool
name|QThreadPoolPrivate
operator|::
name|startFrontRunnable
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|queue
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
name|QRunnable
modifier|*
name|runnable
init|=
name|queue
operator|.
name|takeFirst
argument_list|()
operator|.
name|first
decl_stmt|;
specifier|const
name|bool
name|autoDelete
init|=
name|runnable
operator|->
name|autoDelete
argument_list|()
decl_stmt|;
name|bool
name|del
init|=
name|autoDelete
operator|&&
operator|!
operator|--
name|runnable
operator|->
name|ref
decl_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|runnable
operator|->
name|run
argument_list|()
expr_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
if|if
condition|(
name|del
condition|)
block|{
operator|delete
name|runnable
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*! \internal     Seaches for \a runnable in the queue, removes it from the queue and     runs it if found. This functon does not return until the runnable     has completed. */
end_comment
begin_function
DECL|function|stealRunnable
name|void
name|QThreadPoolPrivate
operator|::
name|stealRunnable
parameter_list|(
name|QRunnable
modifier|*
name|runnable
parameter_list|)
block|{
if|if
condition|(
name|runnable
operator|==
literal|0
operator|||
name|queue
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|bool
name|found
init|=
literal|false
decl_stmt|;
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QRunnable
modifier|*
argument_list|,
name|int
argument_list|>
argument_list|>
operator|::
name|iterator
name|it
init|=
name|queue
operator|.
name|begin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QRunnable
modifier|*
argument_list|,
name|int
argument_list|>
argument_list|>
operator|::
name|iterator
name|end
init|=
name|queue
operator|.
name|end
argument_list|()
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|end
condition|)
block|{
if|if
condition|(
name|it
operator|->
name|first
operator|==
name|runnable
condition|)
block|{
name|found
operator|=
literal|true
expr_stmt|;
name|queue
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
break|break;
block|}
operator|++
name|it
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|found
condition|)
return|return;
specifier|const
name|bool
name|autoDelete
init|=
name|runnable
operator|->
name|autoDelete
argument_list|()
decl_stmt|;
name|bool
name|del
init|=
name|autoDelete
operator|&&
operator|!
operator|--
name|runnable
operator|->
name|ref
decl_stmt|;
name|runnable
operator|->
name|run
argument_list|()
expr_stmt|;
if|if
condition|(
name|del
condition|)
block|{
operator|delete
name|runnable
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \class QThreadPool     \brief The QThreadPool class manages a collection of QThreads.     \since 4.4     \threadsafe      \ingroup thread      QThreadPool manages and recyles individual QThread objects to help reduce     thread creation costs in programs that use threads. Each Qt application     has one global QThreadPool object, which can be accessed by calling     globalInstance().      To use one of the QThreadPool threads, subclass QRunnable and implement     the run() virtual function. Then create an object of that class and pass     it to QThreadPool::start().      \snippet doc/src/snippets/code/src_corelib_concurrent_qthreadpool.cpp 0      QThreadPool deletes the QRunnable automatically by default. Use      QRunnable::setAutoDelete() to change the auto-deletion flag.      QThreadPool supports executing the same QRunnable more than once     by calling tryStart(this) from within QRunnable::run().      If autoDelete is enabled the QRunnable will be deleted when     the last thread exits the run function. Calling start()     multiple times with the same QRunnable when autoDelete is enabled     creates a race condition and is not recommended.      Threads that are unused for a certain amount of time will expire. The     default expiry timeout is 30000 milliseconds (30 seconds). This can be     changed using setExpiryTimeout(). Setting a negative expiry timeout     disables the expiry mechanism.      Call maxThreadCount() to query the maximum number of threads to be used.     If needed, you can change the limit with setMaxThreadCount(). The default     maxThreadCount() is QThread::idealThreadCount(). The activeThreadCount()     function returns the number of threads currently doing work.      The reserveThread() function reserves a thread for external     use. Use releaseThread() when your are done with the thread, so     that it may be reused.  Essentially, these functions temporarily     increase or reduce the active thread count and are useful when     implementing time-consuming operations that are not visible to the     QThreadPool.      Note that QThreadPool is a low-level class for managing threads, see     QtConcurrent::run() or the other     \l {Concurrent Programming}{Qt Concurrent} APIs for higher     level alternatives.      \sa QRunnable */
end_comment
begin_comment
comment|/*!     Constructs a thread pool with the given \a parent. */
end_comment
begin_constructor
DECL|function|QThreadPool
name|QThreadPool
operator|::
name|QThreadPool
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QThreadPoolPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the QThreadPool.     This function will block until all runnables have been completed. */
end_comment
begin_destructor
DECL|function|~QThreadPool
name|QThreadPool
operator|::
name|~
name|QThreadPool
parameter_list|()
block|{
name|d_func
argument_list|()
operator|->
name|waitForDone
argument_list|()
expr_stmt|;
name|d_func
argument_list|()
operator|->
name|reset
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns the global QThreadPool instance. */
end_comment
begin_function
DECL|function|globalInstance
name|QThreadPool
modifier|*
name|QThreadPool
operator|::
name|globalInstance
parameter_list|()
block|{
return|return
name|theInstance
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Reserves a thread and uses it to run \a runnable, unless this thread will     make the current thread count exceed maxThreadCount().  In that case,     \a runnable is added to a run queue instead. The \a priority argument can     be used to control the run queue's order of execution.      Note that the thread pool takes ownership of the \a runnable if     \l{QRunnable::autoDelete()}{runnable->autoDelete()} returns true,     and the \a runnable will be deleted automatically by the thread     pool after the \l{QRunnable::run()}{runnable->run()} returns. If     \l{QRunnable::autoDelete()}{runnable->autoDelete()} returns false,     ownership of \a runnable remains with the caller. Note that     changing the auto-deletion on \a runnable after calling this     functions results in undefined behavior. */
end_comment
begin_function
DECL|function|start
name|void
name|QThreadPool
operator|::
name|start
parameter_list|(
name|QRunnable
modifier|*
name|runnable
parameter_list|,
name|int
name|priority
parameter_list|)
block|{
if|if
condition|(
operator|!
name|runnable
condition|)
return|return;
name|Q_D
argument_list|(
name|QThreadPool
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|tryStart
argument_list|(
name|runnable
argument_list|)
condition|)
name|d
operator|->
name|enqueueTask
argument_list|(
name|runnable
argument_list|,
name|priority
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Attempts to reserve a thread to run \a runnable.      If no threads are available at the time of calling, then this function     does nothing and returns false.  Otherwise, \a runnable is run immediately     using one available thread and this function returns true.      Note that the thread pool takes ownership of the \a runnable if     \l{QRunnable::autoDelete()}{runnable->autoDelete()} returns true,     and the \a runnable will be deleted automatically by the thread     pool after the \l{QRunnable::run()}{runnable->run()} returns. If     \l{QRunnable::autoDelete()}{runnable->autoDelete()} returns false,     ownership of \a runnable remains with the caller. Note that     changing the auto-deletion on \a runnable after calling this     function results in undefined behavior. */
end_comment
begin_function
DECL|function|tryStart
name|bool
name|QThreadPool
operator|::
name|tryStart
parameter_list|(
name|QRunnable
modifier|*
name|runnable
parameter_list|)
block|{
if|if
condition|(
operator|!
name|runnable
condition|)
return|return
literal|false
return|;
name|Q_D
argument_list|(
name|QThreadPool
argument_list|)
expr_stmt|;
comment|// To improve scalability perform a check on the thread count
comment|// before locking the mutex.
if|if
condition|(
name|d
operator|->
name|allThreads
operator|.
name|isEmpty
argument_list|()
operator|==
literal|false
operator|&&
name|d
operator|->
name|activeThreadCount
argument_list|()
operator|>=
name|d
operator|->
name|maxThreadCount
condition|)
return|return
literal|false
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|tryStart
argument_list|(
name|runnable
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \property QThreadPool::expiryTimeout      Threads that are unused for \a expiryTimeout milliseconds are considered     to have expired and will exit. Such threads will be restarted as needed.     The default \a expiryTimeout is 30000 milliseconds (30 seconds). If     \a expiryTimeout is negative, newly created threads will not expire, e.g.,     they will not exit until the thread pool is destroyed.      Note that setting \a expiryTimeout has no effect on already running     threads. Only newly created threads will use the new \a expiryTimeout.     We recommend setting the \a expiryTimeout immediately after creating the     thread pool, but before calling start(). */
end_comment
begin_function
DECL|function|expiryTimeout
name|int
name|QThreadPool
operator|::
name|expiryTimeout
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QThreadPool
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|expiryTimeout
return|;
block|}
end_function
begin_function
DECL|function|setExpiryTimeout
name|void
name|QThreadPool
operator|::
name|setExpiryTimeout
parameter_list|(
name|int
name|expiryTimeout
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QThreadPool
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|expiryTimeout
operator|==
name|expiryTimeout
condition|)
return|return;
name|d
operator|->
name|expiryTimeout
operator|=
name|expiryTimeout
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \property QThreadPool::maxThreadCount      This property represents the maximum number of threads used by the thread     pool.      \note The thread pool will always use at least 1 thread, even if     \a maxThreadCount limit is zero or negative.      The default \a maxThreadCount is QThread::idealThreadCount(). */
end_comment
begin_function
DECL|function|maxThreadCount
name|int
name|QThreadPool
operator|::
name|maxThreadCount
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QThreadPool
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|maxThreadCount
return|;
block|}
end_function
begin_function
DECL|function|setMaxThreadCount
name|void
name|QThreadPool
operator|::
name|setMaxThreadCount
parameter_list|(
name|int
name|maxThreadCount
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QThreadPool
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|maxThreadCount
operator|==
name|d
operator|->
name|maxThreadCount
condition|)
return|return;
name|d
operator|->
name|maxThreadCount
operator|=
name|maxThreadCount
expr_stmt|;
name|d
operator|->
name|tryToStartMoreThreads
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \property QThreadPool::activeThreadCount      This property represents the number of active threads in the thread pool.      \note It is possible for this function to return a value that is greater     than maxThreadCount(). See reserveThread() for more details.      \sa reserveThread(), releaseThread() */
end_comment
begin_function
DECL|function|activeThreadCount
name|int
name|QThreadPool
operator|::
name|activeThreadCount
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QThreadPool
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|activeThreadCount
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Reserves one thread, disregarding activeThreadCount() and maxThreadCount().      Once you are done with the thread, call releaseThread() to allow it to be     reused.      \note This function will always increase the number of active threads.     This means that by using this function, it is possible for     activeThreadCount() to return a value greater than maxThreadCount() .      \sa releaseThread()  */
end_comment
begin_function
DECL|function|reserveThread
name|void
name|QThreadPool
operator|::
name|reserveThread
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QThreadPool
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
operator|++
name|d
operator|->
name|reservedThreads
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Releases a thread previously reserved by a call to reserveThread().      \note Calling this function without previously reserving a thread     temporarily increases maxThreadCount(). This is useful when a     thread goes to sleep waiting for more work, allowing other threads     to continue. Be sure to call reserveThread() when done waiting, so     that the thread pool can correctly maintain the     activeThreadCount().      \sa reserveThread() */
end_comment
begin_function
DECL|function|releaseThread
name|void
name|QThreadPool
operator|::
name|releaseThread
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QThreadPool
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
operator|--
name|d
operator|->
name|reservedThreads
expr_stmt|;
name|d
operator|->
name|tryToStartMoreThreads
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Waits for each thread to exit and removes all threads from the thread pool. */
end_comment
begin_function
DECL|function|waitForDone
name|void
name|QThreadPool
operator|::
name|waitForDone
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QThreadPool
argument_list|)
expr_stmt|;
name|d
operator|->
name|waitForDone
argument_list|()
expr_stmt|;
name|d
operator|->
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \overload waitForDone()     \since 4.8      Waits up to \a msecs milliseconds for all threads to exit and removes all      threads from the thread pool. Returns true if all threads were removed;      otherwise it returns false. */
end_comment
begin_function
DECL|function|waitForDone
name|bool
name|QThreadPool
operator|::
name|waitForDone
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QThreadPool
argument_list|)
expr_stmt|;
name|bool
name|rc
init|=
name|d
operator|->
name|waitForDone
argument_list|(
name|msecs
argument_list|)
decl_stmt|;
if|if
condition|(
name|rc
condition|)
name|d
operator|->
name|reset
argument_list|()
expr_stmt|;
return|return
name|rc
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
end_unit
