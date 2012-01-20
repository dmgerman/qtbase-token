begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_LINUX
end_ifndef
begin_include
include|#
directive|include
file|"private/qfreelist_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QBasicMutex     \brief QMutex POD     \internal      \ingroup thread      - Can be used as global static object.     - Always non-recursive     - Do not use tryLock with timeout> 0, else you can have a leak (see the ~QMutex destructor) */
comment|/*!     \class QMutex     \brief The QMutex class provides access serialization between threads.      \threadsafe      \ingroup thread      The purpose of a QMutex is to protect an object, data structure or     section of code so that only one thread can access it at a time     (this is similar to the Java \c synchronized keyword). It is     usually best to use a mutex with a QMutexLocker since this makes     it easy to ensure that locking and unlocking are performed     consistently.      For example, say there is a method that prints a message to the     user on two lines:      \snippet doc/src/snippets/code/src_corelib_thread_qmutex.cpp 0      If these two methods are called in succession, the following happens:      \snippet doc/src/snippets/code/src_corelib_thread_qmutex.cpp 1      If these two methods are called simultaneously from two threads then the     following sequence could result:      \snippet doc/src/snippets/code/src_corelib_thread_qmutex.cpp 2      If we add a mutex, we should get the result we want:      \snippet doc/src/snippets/code/src_corelib_thread_qmutex.cpp 3      Then only one thread can modify \c number at any given time and     the result is correct. This is a trivial example, of course, but     applies to any other case where things need to happen in a     particular sequence.      When you call lock() in a thread, other threads that try to call     lock() in the same place will block until the thread that got the     lock calls unlock(). A non-blocking alternative to lock() is     tryLock().      \sa QMutexLocker, QReadWriteLock, QSemaphore, QWaitCondition */
comment|/*!     \enum QMutex::RecursionMode      \value Recursive  In this mode, a thread can lock the same mutex                       multiple times and the mutex won't be unlocked                       until a corresponding number of unlock() calls                       have been made.      \value NonRecursive  In this mode, a thread may only lock a mutex                          once.      \sa QMutex() */
comment|/*!     Constructs a new mutex. The mutex is created in an unlocked state.      If \a mode is QMutex::Recursive, a thread can lock the same mutex     multiple times and the mutex won't be unlocked until a     corresponding number of unlock() calls have been made. The     default is QMutex::NonRecursive.      \sa lock(), unlock() */
DECL|function|QMutex
name|QMutex
operator|::
name|QMutex
parameter_list|(
name|RecursionMode
name|mode
parameter_list|)
block|{
name|d_ptr
operator|.
name|store
argument_list|(
name|mode
operator|==
name|Recursive
condition|?
operator|new
name|QRecursiveMutexPrivate
else|:
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
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
name|QMutexData
modifier|*
name|d
init|=
name|d_ptr
operator|.
name|load
argument_list|()
decl_stmt|;
if|if
condition|(
name|quintptr
argument_list|(
name|d
argument_list|)
operator|>
literal|0x3
operator|&&
name|d
operator|->
name|recursive
condition|)
block|{
operator|delete
cast|static_cast
argument_list|<
name|QRecursiveMutexPrivate
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|d
condition|)
block|{
ifndef|#
directive|ifndef
name|Q_OS_LINUX
if|if
condition|(
name|d
operator|!=
name|dummyLocked
argument_list|()
operator|&&
cast|static_cast
argument_list|<
name|QMutexPrivate
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|possiblyUnlocked
operator|.
name|load
argument_list|()
operator|&&
name|tryLock
argument_list|()
condition|)
block|{
name|unlock
argument_list|()
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
name|qWarning
argument_list|(
literal|"QMutex: destroying locked mutex"
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_comment
comment|/*! \fn void QMutex::lock()     Locks the mutex. If another thread has locked the mutex then this     call will block until that thread has unlocked it.      Calling this function multiple times on the same mutex from the     same thread is allowed if this mutex is a     \l{QMutex::Recursive}{recursive mutex}. If this mutex is a     \l{QMutex::NonRecursive}{non-recursive mutex}, this function will     \e dead-lock when the mutex is locked recursively.      \sa unlock() */
end_comment
begin_comment
comment|/*!\fn bool QMutex::trylock()     Attempts to lock the mutex. If the lock was obtained, this function     returns true. If another thread has locked the mutex, this     function returns false immediately.      If the lock was obtained, the mutex must be unlocked with unlock()     before another thread can successfully lock it.      Calling this function multiple times on the same mutex from the     same thread is allowed if this mutex is a     \l{QMutex::Recursive}{recursive mutex}. If this mutex is a     \l{QMutex::NonRecursive}{non-recursive mutex}, this function will     \e always return false when attempting to lock the mutex     recursively.      \sa lock(), unlock() */
end_comment
begin_comment
comment|/*! \fn bool QMutex::tryLock(int timeout)      \overload      Attempts to lock the mutex. This function returns true if the lock     was obtained; otherwise it returns false. If another thread has     locked the mutex, this function will wait for at most \a timeout     milliseconds for the mutex to become available.      Note: Passing a negative number as the \a timeout is equivalent to     calling lock(), i.e. this function will wait forever until mutex     can be locked if \a timeout is negative.      If the lock was obtained, the mutex must be unlocked with unlock()     before another thread can successfully lock it.      Calling this function multiple times on the same mutex from the     same thread is allowed if this mutex is a     \l{QMutex::Recursive}{recursive mutex}. If this mutex is a     \l{QMutex::NonRecursive}{non-recursive mutex}, this function will     \e always return false when attempting to lock the mutex     recursively.      \sa lock(), unlock() */
end_comment
begin_comment
comment|/*! \fn void QMutex::unlock()     Unlocks the mutex. Attempting to unlock a mutex in a different     thread to the one that locked it results in an error. Unlocking a     mutex that is not locked results in undefined behavior.      \sa lock() */
end_comment
begin_comment
comment|/*!     \fn void QMutex::isRecursive()     \since 5.0      Returns true if the mutex is recursive  */
end_comment
begin_function
DECL|function|isRecursive
name|bool
name|QBasicMutex
operator|::
name|isRecursive
parameter_list|()
block|{
name|QMutexData
modifier|*
name|d
init|=
name|d_ptr
operator|.
name|load
argument_list|()
decl_stmt|;
if|if
condition|(
name|quintptr
argument_list|(
name|d
argument_list|)
operator|<=
literal|0x3
condition|)
return|return
literal|false
return|;
return|return
name|d
operator|->
name|recursive
return|;
block|}
end_function
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
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_LINUX
end_ifndef
begin_comment
comment|//linux implementation is in qmutex_linux.cpp
end_comment
begin_comment
comment|/*!     \internal helper for lock()  */
end_comment
begin_function
DECL|function|lockInternal
name|bool
name|QBasicMutex
operator|::
name|lockInternal
parameter_list|(
name|int
name|timeout
parameter_list|)
block|{
while|while
condition|(
operator|!
name|fastTryLock
argument_list|()
condition|)
block|{
name|QMutexData
modifier|*
name|copy
init|=
name|d_ptr
operator|.
name|loadAcquire
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|copy
condition|)
comment|// if d is 0, the mutex is unlocked
continue|continue;
if|if
condition|(
name|copy
operator|==
name|dummyLocked
argument_list|()
condition|)
block|{
if|if
condition|(
name|timeout
operator|==
literal|0
condition|)
return|return
literal|false
return|;
name|QMutexPrivate
modifier|*
name|newD
init|=
name|QMutexPrivate
operator|::
name|allocate
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|d_ptr
operator|.
name|testAndSetOrdered
argument_list|(
name|dummyLocked
argument_list|()
argument_list|,
name|newD
argument_list|)
condition|)
block|{
comment|//Either the mutex is already unlocked, or another thread already set it.
name|newD
operator|->
name|deref
argument_list|()
expr_stmt|;
continue|continue;
block|}
name|copy
operator|=
name|newD
expr_stmt|;
comment|//the d->refCount is already 1 the deref will occurs when we unlock
block|}
elseif|else
if|if
condition|(
name|copy
operator|->
name|recursive
condition|)
block|{
return|return
cast|static_cast
argument_list|<
name|QRecursiveMutexPrivate
operator|*
argument_list|>
argument_list|(
name|copy
argument_list|)
operator|->
name|lock
argument_list|(
name|timeout
argument_list|)
return|;
block|}
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
name|copy
argument_list|)
decl_stmt|;
if|if
condition|(
name|timeout
operator|==
literal|0
operator|&&
operator|!
name|d
operator|->
name|possiblyUnlocked
operator|.
name|load
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|d
operator|->
name|ref
argument_list|()
condition|)
continue|continue;
comment|//that QMutexData was already released
if|if
condition|(
name|d
operator|!=
name|d_ptr
operator|.
name|loadAcquire
argument_list|()
condition|)
block|{
comment|//Either the mutex is already unlocked, or relocked with another mutex
name|d
operator|->
name|deref
argument_list|()
expr_stmt|;
continue|continue;
block|}
name|int
name|old_waiters
decl_stmt|;
do|do
block|{
name|old_waiters
operator|=
name|d
operator|->
name|waiters
operator|.
name|load
argument_list|()
expr_stmt|;
if|if
condition|(
name|old_waiters
operator|==
operator|-
name|QMutexPrivate
operator|::
name|BigNumber
condition|)
block|{
comment|// we are unlocking, and the thread that unlocks is about to change d to 0
comment|// we try to aquire the mutex by changing to dummyLocked()
if|if
condition|(
name|d_ptr
operator|.
name|testAndSetAcquire
argument_list|(
name|d
argument_list|,
name|dummyLocked
argument_list|()
argument_list|)
condition|)
block|{
comment|// Mutex aquired
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|waiters
operator|.
name|load
argument_list|()
operator|==
operator|-
name|QMutexPrivate
operator|::
name|BigNumber
operator|||
name|d
operator|->
name|waiters
operator|.
name|load
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|waiters
operator|.
name|store
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|deref
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
block|{
name|Q_ASSERT
argument_list|(
name|d
operator|!=
name|d_ptr
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
comment|//else testAndSetAcquire should have succeeded
comment|// Mutex is likely to bo 0, we should continue the outer-loop,
comment|//  set old_waiters to the magic value of BigNumber
name|old_waiters
operator|=
name|QMutexPrivate
operator|::
name|BigNumber
expr_stmt|;
break|break;
block|}
block|}
block|}
do|while
condition|(
operator|!
name|d
operator|->
name|waiters
operator|.
name|testAndSetRelaxed
argument_list|(
name|old_waiters
argument_list|,
name|old_waiters
operator|+
literal|1
argument_list|)
condition|)
do|;
if|if
condition|(
name|d
operator|!=
name|d_ptr
operator|.
name|loadAcquire
argument_list|()
condition|)
block|{
comment|// Mutex was unlocked.
if|if
condition|(
name|old_waiters
operator|!=
name|QMutexPrivate
operator|::
name|BigNumber
condition|)
block|{
comment|//we did not break the previous loop
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|waiters
operator|.
name|load
argument_list|()
operator|>=
literal|1
argument_list|)
expr_stmt|;
name|d
operator|->
name|waiters
operator|.
name|deref
argument_list|()
expr_stmt|;
block|}
name|d
operator|->
name|deref
argument_list|()
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|d
operator|->
name|wait
argument_list|(
name|timeout
argument_list|)
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|possiblyUnlocked
operator|.
name|load
argument_list|()
operator|&&
name|d
operator|->
name|possiblyUnlocked
operator|.
name|testAndSetRelaxed
argument_list|(
literal|true
argument_list|,
literal|false
argument_list|)
condition|)
name|d
operator|->
name|deref
argument_list|()
expr_stmt|;
name|d
operator|->
name|derefWaiters
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|//we got the lock. (do not deref)
name|Q_ASSERT
argument_list|(
name|d
operator|==
name|d_ptr
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
block|{
name|Q_ASSERT
argument_list|(
name|timeout
operator|>=
literal|0
argument_list|)
expr_stmt|;
comment|//timeout
name|d
operator|->
name|derefWaiters
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|//There may be a race in which the mutex is unlocked right after we timed out,
comment|// and before we deref the waiters, so maybe the mutex is actually unlocked.
if|if
condition|(
operator|!
name|d
operator|->
name|possiblyUnlocked
operator|.
name|testAndSetRelaxed
argument_list|(
literal|false
argument_list|,
literal|true
argument_list|)
condition|)
name|d
operator|->
name|deref
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
name|Q_ASSERT
argument_list|(
name|d_ptr
operator|.
name|load
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|unlockInternal
name|void
name|QBasicMutex
operator|::
name|unlockInternal
parameter_list|()
block|{
name|QMutexData
modifier|*
name|copy
init|=
name|d_ptr
operator|.
name|loadAcquire
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|copy
argument_list|)
expr_stmt|;
comment|//we must be locked
name|Q_ASSERT
argument_list|(
name|copy
operator|!=
name|dummyLocked
argument_list|()
argument_list|)
expr_stmt|;
comment|// testAndSetRelease(dummyLocked(), 0) failed
if|if
condition|(
name|copy
operator|->
name|recursive
condition|)
block|{
cast|static_cast
argument_list|<
name|QRecursiveMutexPrivate
operator|*
argument_list|>
argument_list|(
name|copy
argument_list|)
operator|->
name|unlock
argument_list|()
expr_stmt|;
return|return;
block|}
name|QMutexPrivate
modifier|*
name|d
init|=
cast|reinterpret_cast
argument_list|<
name|QMutexPrivate
operator|*
argument_list|>
argument_list|(
name|copy
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|waiters
operator|.
name|fetchAndAddRelease
argument_list|(
operator|-
name|QMutexPrivate
operator|::
name|BigNumber
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|//there is no one waiting on this mutex anymore, set the mutex as unlocked (d = 0)
if|if
condition|(
name|d_ptr
operator|.
name|testAndSetRelease
argument_list|(
name|d
argument_list|,
literal|0
argument_list|)
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|possiblyUnlocked
operator|.
name|load
argument_list|()
operator|&&
name|d
operator|->
name|possiblyUnlocked
operator|.
name|testAndSetRelaxed
argument_list|(
literal|true
argument_list|,
literal|false
argument_list|)
condition|)
name|d
operator|->
name|deref
argument_list|()
expr_stmt|;
block|}
name|d
operator|->
name|derefWaiters
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|derefWaiters
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|//there are thread waiting, transfer the lock.
name|d
operator|->
name|wakeUp
argument_list|()
expr_stmt|;
block|}
name|d
operator|->
name|deref
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//The freelist managment
end_comment
begin_namespace
namespace|namespace
block|{
DECL|struct|FreeListConstants
struct|struct
name|FreeListConstants
super|:
name|QFreeListDefaultConstants
block|{
DECL|enumerator|BlockCount
DECL|enumerator|MaxIndex
enum|enum
block|{
name|BlockCount
init|=
literal|4
block|,
name|MaxIndex
init|=
literal|0xffff
block|}
enum|;
DECL|member|Sizes
specifier|static
specifier|const
name|int
name|Sizes
index|[
name|BlockCount
index|]
decl_stmt|;
block|}
struct|;
DECL|member|Sizes
specifier|const
name|int
name|FreeListConstants
operator|::
name|Sizes
index|[
name|FreeListConstants
operator|::
name|BlockCount
index|]
init|=
block|{
literal|16
block|,
literal|128
block|,
literal|1024
block|,
name|FreeListConstants
operator|::
name|MaxIndex
operator|-
operator|(
literal|16
operator|-
literal|128
operator|-
literal|1024
operator|)
block|}
decl_stmt|;
DECL|typedef|FreeList
typedef|typedef
name|QFreeList
argument_list|<
name|QMutexPrivate
argument_list|,
name|FreeListConstants
argument_list|>
name|FreeList
typedef|;
name|Q_GLOBAL_STATIC
argument_list|(
name|FreeList
argument_list|,
name|freelist
argument_list|)
expr_stmt|;
block|}
end_namespace
begin_function
DECL|function|allocate
name|QMutexPrivate
modifier|*
name|QMutexPrivate
operator|::
name|allocate
parameter_list|()
block|{
name|int
name|i
init|=
name|freelist
argument_list|()
operator|->
name|next
argument_list|()
decl_stmt|;
name|QMutexPrivate
modifier|*
name|d
init|=
operator|&
operator|(
operator|*
name|freelist
argument_list|()
operator|)
index|[
name|i
index|]
decl_stmt|;
name|d
operator|->
name|id
operator|=
name|i
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|refCount
operator|.
name|load
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|d
operator|->
name|recursive
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|d
operator|->
name|possiblyUnlocked
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|waiters
operator|.
name|load
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|refCount
operator|.
name|store
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
name|d
return|;
block|}
end_function
begin_function
DECL|function|release
name|void
name|QMutexPrivate
operator|::
name|release
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|recursive
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|refCount
operator|.
name|load
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|possiblyUnlocked
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|waiters
operator|.
name|load
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|freelist
argument_list|()
operator|->
name|release
argument_list|(
name|id
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// atomically substract "value" to the waiters, and remove the QMutexPrivate::BigNumber flag
end_comment
begin_function
DECL|function|derefWaiters
name|void
name|QMutexPrivate
operator|::
name|derefWaiters
parameter_list|(
name|int
name|value
parameter_list|)
block|{
name|int
name|old_waiters
decl_stmt|;
name|int
name|new_waiters
decl_stmt|;
do|do
block|{
name|old_waiters
operator|=
name|waiters
operator|.
name|load
argument_list|()
expr_stmt|;
name|new_waiters
operator|=
name|old_waiters
expr_stmt|;
if|if
condition|(
name|new_waiters
operator|<
literal|0
condition|)
block|{
name|new_waiters
operator|+=
name|QMutexPrivate
operator|::
name|BigNumber
expr_stmt|;
block|}
name|new_waiters
operator|-=
name|value
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|waiters
operator|.
name|testAndSetRelaxed
argument_list|(
name|old_waiters
argument_list|,
name|new_waiters
argument_list|)
condition|)
do|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!    \internal  */
end_comment
begin_function
DECL|function|lock
name|bool
name|QRecursiveMutexPrivate
operator|::
name|lock
parameter_list|(
name|int
name|timeout
parameter_list|)
block|{
name|Qt
operator|::
name|HANDLE
name|self
init|=
name|QThread
operator|::
name|currentThreadId
argument_list|()
decl_stmt|;
if|if
condition|(
name|owner
operator|==
name|self
condition|)
block|{
operator|++
name|count
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|count
operator|!=
literal|0
argument_list|,
literal|"QMutex::lock"
argument_list|,
literal|"Overflow in recursion counter"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|bool
name|success
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|timeout
operator|==
operator|-
literal|1
condition|)
block|{
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|success
operator|=
name|mutex
operator|.
name|tryLock
argument_list|(
name|timeout
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|success
condition|)
name|owner
operator|=
name|self
expr_stmt|;
return|return
name|success
return|;
block|}
end_function
begin_comment
comment|/*!    \internal  */
end_comment
begin_function
DECL|function|unlock
name|void
name|QRecursiveMutexPrivate
operator|::
name|unlock
parameter_list|()
block|{
if|if
condition|(
name|count
operator|>
literal|0
condition|)
block|{
name|count
operator|--
expr_stmt|;
block|}
else|else
block|{
name|owner
operator|=
literal|0
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
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
