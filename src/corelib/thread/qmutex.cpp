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
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_include
include|#
directive|include
file|"qatomic.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_include
include|#
directive|include
file|"qthread.h"
end_include
begin_include
include|#
directive|include
file|"qmutex_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QMutex     \brief The QMutex class provides access serialization between threads.      \threadsafe      \ingroup thread      The purpose of a QMutex is to protect an object, data structure or     section of code so that only one thread can access it at a time     (this is similar to the Java \c synchronized keyword). It is     usually best to use a mutex with a QMutexLocker since this makes     it easy to ensure that locking and unlocking are performed     consistently.      For example, say there is a method that prints a message to the     user on two lines:      \snippet doc/src/snippets/code/src_corelib_thread_qmutex.cpp 0      If these two methods are called in succession, the following happens:      \snippet doc/src/snippets/code/src_corelib_thread_qmutex.cpp 1      If these two methods are called simultaneously from two threads then the     following sequence could result:      \snippet doc/src/snippets/code/src_corelib_thread_qmutex.cpp 2      If we add a mutex, we should get the result we want:      \snippet doc/src/snippets/code/src_corelib_thread_qmutex.cpp 3      Then only one thread can modify \c number at any given time and     the result is correct. This is a trivial example, of course, but     applies to any other case where things need to happen in a     particular sequence.      When you call lock() in a thread, other threads that try to call     lock() in the same place will block until the thread that got the     lock calls unlock(). A non-blocking alternative to lock() is     tryLock().      \sa QMutexLocker, QReadWriteLock, QSemaphore, QWaitCondition */
end_comment
begin_comment
comment|/*!     \enum QMutex::RecursionMode      \value Recursive  In this mode, a thread can lock the same mutex                       multiple times and the mutex won't be unlocked                       until a corresponding number of unlock() calls                       have been made.      \value NonRecursive  In this mode, a thread may only lock a mutex                          once.      \sa QMutex() */
end_comment
begin_comment
comment|/*!     Constructs a new mutex. The mutex is created in an unlocked state.      If \a mode is QMutex::Recursive, a thread can lock the same mutex     multiple times and the mutex won't be unlocked until a     corresponding number of unlock() calls have been made. The     default is QMutex::NonRecursive.      \sa lock(), unlock() */
end_comment
begin_constructor
DECL|function|QMutex
name|QMutex
operator|::
name|QMutex
parameter_list|(
name|RecursionMode
name|mode
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QMutexPrivate
argument_list|(
name|mode
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the mutex.      \warning Destroying a locked mutex may result in undefined behavior. */
end_comment
begin_destructor
DECL|function|~QMutex
name|QMutex
operator|::
name|~
name|QMutex
parameter_list|()
block|{
operator|delete
cast|static_cast
argument_list|<
name|QMutexPrivate
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Locks the mutex. If another thread has locked the mutex then this     call will block until that thread has unlocked it.      Calling this function multiple times on the same mutex from the     same thread is allowed if this mutex is a     \l{QMutex::Recursive}{recursive mutex}. If this mutex is a     \l{QMutex::NonRecursive}{non-recursive mutex}, this function will     \e dead-lock when the mutex is locked recursively.      \sa unlock() */
end_comment
begin_function
DECL|function|lock
name|void
name|QMutex
operator|::
name|lock
parameter_list|()
block|{
name|QMutexPrivate
modifier|*
name|d
init|=
cast|static_cast
argument_list|<
name|QMutexPrivate
operator|*
argument_list|>
argument_list|(
name|this
operator|->
name|d
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|HANDLE
name|self
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|recursive
condition|)
block|{
name|self
operator|=
name|QThread
operator|::
name|currentThreadId
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|owner
operator|==
name|self
condition|)
block|{
operator|++
name|d
operator|->
name|count
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|d
operator|->
name|count
operator|!=
literal|0
argument_list|,
literal|"QMutex::lock"
argument_list|,
literal|"Overflow in recursion counter"
argument_list|)
expr_stmt|;
return|return;
block|}
name|bool
name|isLocked
init|=
name|d
operator|->
name|contenders
operator|.
name|testAndSetAcquire
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|isLocked
condition|)
block|{
comment|// didn't get the lock, wait for it
name|isLocked
operator|=
name|d
operator|->
name|wait
argument_list|()
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|isLocked
argument_list|,
literal|"QMutex::lock"
argument_list|,
literal|"Internal error, infinite wait has timed out."
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|owner
operator|=
name|self
expr_stmt|;
operator|++
name|d
operator|->
name|count
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|d
operator|->
name|count
operator|!=
literal|0
argument_list|,
literal|"QMutex::lock"
argument_list|,
literal|"Overflow in recursion counter"
argument_list|)
expr_stmt|;
return|return;
block|}
name|bool
name|isLocked
init|=
name|d
operator|->
name|contenders
operator|.
name|testAndSetAcquire
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|isLocked
condition|)
block|{
name|lockInternal
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Attempts to lock the mutex. If the lock was obtained, this function     returns true. If another thread has locked the mutex, this     function returns false immediately.      If the lock was obtained, the mutex must be unlocked with unlock()     before another thread can successfully lock it.      Calling this function multiple times on the same mutex from the     same thread is allowed if this mutex is a     \l{QMutex::Recursive}{recursive mutex}. If this mutex is a     \l{QMutex::NonRecursive}{non-recursive mutex}, this function will     \e always return false when attempting to lock the mutex     recursively.      \sa lock(), unlock() */
end_comment
begin_function
DECL|function|tryLock
name|bool
name|QMutex
operator|::
name|tryLock
parameter_list|()
block|{
name|QMutexPrivate
modifier|*
name|d
init|=
cast|static_cast
argument_list|<
name|QMutexPrivate
operator|*
argument_list|>
argument_list|(
name|this
operator|->
name|d
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|HANDLE
name|self
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|recursive
condition|)
block|{
name|self
operator|=
name|QThread
operator|::
name|currentThreadId
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|owner
operator|==
name|self
condition|)
block|{
operator|++
name|d
operator|->
name|count
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|d
operator|->
name|count
operator|!=
literal|0
argument_list|,
literal|"QMutex::tryLock"
argument_list|,
literal|"Overflow in recursion counter"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|bool
name|isLocked
init|=
name|d
operator|->
name|contenders
operator|.
name|testAndSetAcquire
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|isLocked
condition|)
block|{
comment|// some other thread has the mutex locked, or we tried to
comment|// recursively lock an non-recursive mutex
return|return
name|isLocked
return|;
block|}
name|d
operator|->
name|owner
operator|=
name|self
expr_stmt|;
operator|++
name|d
operator|->
name|count
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|d
operator|->
name|count
operator|!=
literal|0
argument_list|,
literal|"QMutex::tryLock"
argument_list|,
literal|"Overflow in recursion counter"
argument_list|)
expr_stmt|;
return|return
name|isLocked
return|;
block|}
return|return
name|d
operator|->
name|contenders
operator|.
name|testAndSetAcquire
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \overload      Attempts to lock the mutex. This function returns true if the lock     was obtained; otherwise it returns false. If another thread has     locked the mutex, this function will wait for at most \a timeout     milliseconds for the mutex to become available.      Note: Passing a negative number as the \a timeout is equivalent to     calling lock(), i.e. this function will wait forever until mutex     can be locked if \a timeout is negative.      If the lock was obtained, the mutex must be unlocked with unlock()     before another thread can successfully lock it.      Calling this function multiple times on the same mutex from the     same thread is allowed if this mutex is a     \l{QMutex::Recursive}{recursive mutex}. If this mutex is a     \l{QMutex::NonRecursive}{non-recursive mutex}, this function will     \e always return false when attempting to lock the mutex     recursively.      \sa lock(), unlock() */
end_comment
begin_function
DECL|function|tryLock
name|bool
name|QMutex
operator|::
name|tryLock
parameter_list|(
name|int
name|timeout
parameter_list|)
block|{
name|QMutexPrivate
modifier|*
name|d
init|=
cast|static_cast
argument_list|<
name|QMutexPrivate
operator|*
argument_list|>
argument_list|(
name|this
operator|->
name|d
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|HANDLE
name|self
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|recursive
condition|)
block|{
name|self
operator|=
name|QThread
operator|::
name|currentThreadId
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|owner
operator|==
name|self
condition|)
block|{
operator|++
name|d
operator|->
name|count
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|d
operator|->
name|count
operator|!=
literal|0
argument_list|,
literal|"QMutex::tryLock"
argument_list|,
literal|"Overflow in recursion counter"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|bool
name|isLocked
init|=
name|d
operator|->
name|contenders
operator|.
name|testAndSetAcquire
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|isLocked
condition|)
block|{
comment|// didn't get the lock, wait for it
name|isLocked
operator|=
name|d
operator|->
name|wait
argument_list|(
name|timeout
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isLocked
condition|)
return|return
literal|false
return|;
block|}
name|d
operator|->
name|owner
operator|=
name|self
expr_stmt|;
operator|++
name|d
operator|->
name|count
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|d
operator|->
name|count
operator|!=
literal|0
argument_list|,
literal|"QMutex::tryLock"
argument_list|,
literal|"Overflow in recursion counter"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
operator|(
name|d
operator|->
name|contenders
operator|.
name|testAndSetAcquire
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
comment|// didn't get the lock, wait for it
operator|||
name|d
operator|->
name|wait
argument_list|(
name|timeout
argument_list|)
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Unlocks the mutex. Attempting to unlock a mutex in a different     thread to the one that locked it results in an error. Unlocking a     mutex that is not locked results in undefined behavior.      \sa lock() */
end_comment
begin_function
DECL|function|unlock
name|void
name|QMutex
operator|::
name|unlock
parameter_list|()
block|{
name|QMutexPrivate
modifier|*
name|d
init|=
cast|static_cast
argument_list|<
name|QMutexPrivate
operator|*
argument_list|>
argument_list|(
name|this
operator|->
name|d
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|recursive
condition|)
block|{
if|if
condition|(
operator|!
operator|--
name|d
operator|->
name|count
condition|)
block|{
name|d
operator|->
name|owner
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|contenders
operator|.
name|testAndSetRelease
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
condition|)
name|d
operator|->
name|wakeUp
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|contenders
operator|.
name|testAndSetRelease
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
condition|)
name|d
operator|->
name|wakeUp
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \fn bool QMutex::locked()      Returns true if the mutex is locked by another thread; otherwise     returns false.      It is generally a bad idea to use this function, because code     that uses it has a race condition. Use tryLock() and unlock()     instead.      \oldcode         bool isLocked = mutex.locked();     \newcode         bool isLocked = true;         if (mutex.tryLock()) {             mutex.unlock();             isLocked = false;         }     \endcode */
end_comment
begin_comment
comment|/*!     \class QMutexLocker     \brief The QMutexLocker class is a convenience class that simplifies     locking and unlocking mutexes.      \threadsafe      \ingroup thread      Locking and unlocking a QMutex in complex functions and     statements or in exception handling code is error-prone and     difficult to debug. QMutexLocker can be used in such situations     to ensure that the state of the mutex is always well-defined.      QMutexLocker should be created within a function where a     QMutex needs to be locked. The mutex is locked when QMutexLocker     is created. You can unlock and relock the mutex with \c unlock()     and \c relock(). If locked, the mutex will be unlocked when the     QMutexLocker is destroyed.      For example, this complex function locks a QMutex upon entering     the function and unlocks the mutex at all the exit points:      \snippet doc/src/snippets/code/src_corelib_thread_qmutex.cpp 4      This example function will get more complicated as it is     developed, which increases the likelihood that errors will occur.      Using QMutexLocker greatly simplifies the code, and makes it more     readable:      \snippet doc/src/snippets/code/src_corelib_thread_qmutex.cpp 5      Now, the mutex will always be unlocked when the QMutexLocker     object is destroyed (when the function returns since \c locker is     an auto variable).      The same principle applies to code that throws and catches     exceptions. An exception that is not caught in the function that     has locked the mutex has no way of unlocking the mutex before the     exception is passed up the stack to the calling function.      QMutexLocker also provides a \c mutex() member function that returns     the mutex on which the QMutexLocker is operating. This is useful     for code that needs access to the mutex, such as     QWaitCondition::wait(). For example:      \snippet doc/src/snippets/code/src_corelib_thread_qmutex.cpp 6      \sa QReadLocker, QWriteLocker, QMutex */
end_comment
begin_comment
comment|/*!     \fn QMutexLocker::QMutexLocker(QMutex *mutex)      Constructs a QMutexLocker and locks \a mutex. The mutex will be     unlocked when the QMutexLocker is destroyed. If \a mutex is zero,     QMutexLocker does nothing.      \sa QMutex::lock() */
end_comment
begin_comment
comment|/*!     \fn QMutexLocker::~QMutexLocker()      Destroys the QMutexLocker and unlocks the mutex that was locked     in the constructor.      \sa QMutex::unlock() */
end_comment
begin_comment
comment|/*!     \fn QMutex *QMutexLocker::mutex() const      Returns a pointer to the mutex that was locked in the     constructor. */
end_comment
begin_comment
comment|/*!     \fn void QMutexLocker::unlock()      Unlocks this mutex locker. You can use \c relock() to lock     it again. It does not need to be locked when destroyed.      \sa relock() */
end_comment
begin_comment
comment|/*!     \fn void QMutexLocker::relock()      Relocks an unlocked mutex locker.      \sa unlock() */
end_comment
begin_comment
comment|/*!     \fn QMutex::QMutex(bool recursive)      Use the constructor that takes a RecursionMode parameter instead. */
end_comment
begin_comment
comment|/*!     \internal helper for lockInline()  */
end_comment
begin_function
DECL|function|lockInternal
name|void
name|QMutex
operator|::
name|lockInternal
parameter_list|()
block|{
name|QMutexPrivate
modifier|*
name|d
init|=
cast|static_cast
argument_list|<
name|QMutexPrivate
operator|*
argument_list|>
argument_list|(
name|this
operator|->
name|d
argument_list|)
decl_stmt|;
if|if
condition|(
name|QThread
operator|::
name|idealThreadCount
argument_list|()
operator|==
literal|1
condition|)
block|{
comment|// don't spin on single cpu machines
name|bool
name|isLocked
init|=
name|d
operator|->
name|wait
argument_list|()
decl_stmt|;
name|Q_ASSERT_X
argument_list|(
name|isLocked
argument_list|,
literal|"QMutex::lock"
argument_list|,
literal|"Internal error, infinite wait has timed out."
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|isLocked
argument_list|)
expr_stmt|;
return|return;
block|}
name|QElapsedTimer
name|elapsedTimer
decl_stmt|;
name|elapsedTimer
operator|.
name|start
argument_list|()
expr_stmt|;
do|do
block|{
name|qint64
name|spinTime
init|=
name|elapsedTimer
operator|.
name|nsecsElapsed
argument_list|()
decl_stmt|;
if|if
condition|(
name|spinTime
operator|>
name|d
operator|->
name|maximumSpinTime
condition|)
block|{
comment|// didn't get the lock, wait for it, since we're not going to gain anything by spinning more
name|elapsedTimer
operator|.
name|start
argument_list|()
expr_stmt|;
name|bool
name|isLocked
init|=
name|d
operator|->
name|wait
argument_list|()
decl_stmt|;
name|Q_ASSERT_X
argument_list|(
name|isLocked
argument_list|,
literal|"QMutex::lock"
argument_list|,
literal|"Internal error, infinite wait has timed out."
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|isLocked
argument_list|)
expr_stmt|;
name|qint64
name|maximumSpinTime
init|=
name|d
operator|->
name|maximumSpinTime
decl_stmt|;
name|qint64
name|averageWaitTime
init|=
name|d
operator|->
name|averageWaitTime
decl_stmt|;
name|qint64
name|actualWaitTime
init|=
name|elapsedTimer
operator|.
name|nsecsElapsed
argument_list|()
decl_stmt|;
if|if
condition|(
name|actualWaitTime
operator|<
operator|(
name|QMutexPrivate
operator|::
name|MaximumSpinTimeThreshold
operator|*
literal|3
operator|/
literal|2
operator|)
condition|)
block|{
comment|// measure the wait times
name|averageWaitTime
operator|=
name|d
operator|->
name|averageWaitTime
operator|=
name|qMin
argument_list|(
operator|(
name|averageWaitTime
operator|+
name|actualWaitTime
operator|)
operator|/
literal|2
argument_list|,
name|qint64
argument_list|(
name|QMutexPrivate
operator|::
name|MaximumSpinTimeThreshold
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// adjust the spin count when spinning does not benefit contention performance
if|if
condition|(
operator|(
name|spinTime
operator|+
name|actualWaitTime
operator|)
operator|-
name|qint64
argument_list|(
name|QMutexPrivate
operator|::
name|MaximumSpinTimeThreshold
argument_list|)
operator|>=
name|qint64
argument_list|(
name|QMutexPrivate
operator|::
name|MaximumSpinTimeThreshold
argument_list|)
condition|)
block|{
comment|// long waits, stop spinning
name|d
operator|->
name|maximumSpinTime
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
comment|// allow spinning if wait times decrease, but never spin more than the average wait time (otherwise we may perform worse)
name|d
operator|->
name|maximumSpinTime
operator|=
name|qBound
argument_list|(
name|qint64
argument_list|(
name|averageWaitTime
operator|*
literal|3
operator|/
literal|2
argument_list|)
argument_list|,
name|maximumSpinTime
operator|/
literal|2
argument_list|,
name|qint64
argument_list|(
name|QMutexPrivate
operator|::
name|MaximumSpinTimeThreshold
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
comment|// be a good citizen... yielding lets something else run if there is something to run, but may also relieve memory pressure if not
name|QThread
operator|::
name|yieldCurrentThread
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
name|d
operator|->
name|contenders
operator|!=
literal|0
operator|||
operator|!
name|d
operator|->
name|contenders
operator|.
name|testAndSetAcquire
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
condition|)
do|;
comment|// spinning is working, do not change the spin time (unless we are using much less time than allowed to spin)
name|qint64
name|maximumSpinTime
init|=
name|d
operator|->
name|maximumSpinTime
decl_stmt|;
name|qint64
name|spinTime
init|=
name|elapsedTimer
operator|.
name|nsecsElapsed
argument_list|()
decl_stmt|;
if|if
condition|(
name|spinTime
operator|<
name|maximumSpinTime
operator|/
literal|2
condition|)
block|{
comment|// we are using much less time than we need, adjust the limit
name|d
operator|->
name|maximumSpinTime
operator|=
name|qBound
argument_list|(
name|qint64
argument_list|(
name|d
operator|->
name|averageWaitTime
operator|*
literal|3
operator|/
literal|2
argument_list|)
argument_list|,
name|maximumSpinTime
operator|/
literal|2
argument_list|,
name|qint64
argument_list|(
name|QMutexPrivate
operator|::
name|MaximumSpinTimeThreshold
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|unlockInternal
name|void
name|QMutex
operator|::
name|unlockInternal
parameter_list|()
block|{
cast|static_cast
argument_list|<
name|QMutexPrivate
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|wakeUp
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!    \fn QMutex::lockInline()    \internal    inline version of QMutex::lock() */
end_comment
begin_comment
comment|/*!    \fn QMutex::unlockInline()    \internal    inline version of QMutex::unlock() */
end_comment
begin_comment
comment|/*!    \fn QMutex::tryLockInline()    \internal    inline version of QMutex::tryLock() */
end_comment
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
