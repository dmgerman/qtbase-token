begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwinoverlappedionotifier_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qatomic.h>
end_include
begin_include
include|#
directive|include
file|<qelapsedtimer.h>
end_include
begin_include
include|#
directive|include
file|<qmutex.h>
end_include
begin_include
include|#
directive|include
file|<qpointer.h>
end_include
begin_include
include|#
directive|include
file|<qqueue.h>
end_include
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_include
include|#
directive|include
file|<qthread.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qiodevice_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QWinOverlappedIoNotifier     \inmodule QtCore     \brief The QWinOverlappedIoNotifier class provides support for overlapped I/O notifications on Windows.     \since 5.0     \internal      The QWinOverlappedIoNotifier class makes it possible to use efficient     overlapped (asynchronous) I/O notifications on Windows by using an     I/O completion port.      Once you have obtained a file handle, you can use setHandle() to get     notifications for I/O operations. Whenever an I/O operation completes,     the notified() signal is emitted which will pass the number of transferred     bytes, the operation's error code and a pointer to the operation's     OVERLAPPED object to the receiver.      Every handle that supports overlapped I/O can be used by     QWinOverlappedIoNotifier. That includes file handles, TCP sockets     and named pipes.      Note that you must not use ReadFileEx() and WriteFileEx() together     with QWinOverlappedIoNotifier. They are not supported as they use a     different I/O notification mechanism.      The hEvent member in the OVERLAPPED structure passed to ReadFile()     or WriteFile() is ignored and can be used for other purposes.      \warning This class is only available on Windows. */
end_comment
begin_struct
DECL|struct|IOResult
struct|struct
name|IOResult
block|{
DECL|function|IOResult
name|IOResult
parameter_list|(
name|DWORD
name|n
init|=
literal|0
parameter_list|,
name|DWORD
name|e
init|=
literal|0
parameter_list|,
name|OVERLAPPED
modifier|*
name|p
init|=
literal|0
parameter_list|)
member_init_list|:
name|numberOfBytes
argument_list|(
name|n
argument_list|)
member_init_list|,
name|errorCode
argument_list|(
name|e
argument_list|)
member_init_list|,
name|overlapped
argument_list|(
name|p
argument_list|)
block|{}
DECL|member|numberOfBytes
name|DWORD
name|numberOfBytes
decl_stmt|;
DECL|member|errorCode
name|DWORD
name|errorCode
decl_stmt|;
DECL|member|overlapped
name|OVERLAPPED
modifier|*
name|overlapped
decl_stmt|;
block|}
struct|;
end_struct
begin_class_decl
class_decl|class
name|QWinIoCompletionPort
class_decl|;
end_class_decl
begin_class
DECL|class|QWinOverlappedIoNotifierPrivate
class|class
name|QWinOverlappedIoNotifierPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QWinOverlappedIoNotifier
parameter_list|)
specifier|public
private|:
DECL|function|QWinOverlappedIoNotifierPrivate
name|QWinOverlappedIoNotifierPrivate
parameter_list|()
member_init_list|:
name|hHandle
argument_list|(
name|INVALID_HANDLE_VALUE
argument_list|)
block|{     }
name|OVERLAPPED
modifier|*
name|waitForAnyNotified
parameter_list|(
name|int
name|msecs
parameter_list|)
function_decl|;
name|void
name|notify
parameter_list|(
name|DWORD
name|numberOfBytes
parameter_list|,
name|DWORD
name|errorCode
parameter_list|,
name|OVERLAPPED
modifier|*
name|overlapped
parameter_list|)
function_decl|;
name|void
name|_q_notified
parameter_list|()
function_decl|;
name|OVERLAPPED
modifier|*
name|dispatchNextIoResult
parameter_list|()
function_decl|;
DECL|member|iocp
specifier|static
name|QWinIoCompletionPort
modifier|*
name|iocp
decl_stmt|;
DECL|member|iocpInstanceLock
specifier|static
name|HANDLE
name|iocpInstanceLock
decl_stmt|;
DECL|member|iocpInstanceRefCount
specifier|static
name|unsigned
name|int
name|iocpInstanceRefCount
decl_stmt|;
DECL|member|hHandle
name|HANDLE
name|hHandle
decl_stmt|;
DECL|member|hSemaphore
name|HANDLE
name|hSemaphore
decl_stmt|;
DECL|member|hResultsMutex
name|HANDLE
name|hResultsMutex
decl_stmt|;
DECL|member|waiting
name|QAtomicInt
name|waiting
decl_stmt|;
DECL|member|results
name|QQueue
argument_list|<
name|IOResult
argument_list|>
name|results
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|member|iocp
name|QWinIoCompletionPort
modifier|*
name|QWinOverlappedIoNotifierPrivate
operator|::
name|iocp
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|iocpInstanceLock
name|HANDLE
name|QWinOverlappedIoNotifierPrivate
operator|::
name|iocpInstanceLock
init|=
name|CreateMutex
argument_list|(
name|NULL
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|iocpInstanceRefCount
name|unsigned
name|int
name|QWinOverlappedIoNotifierPrivate
operator|::
name|iocpInstanceRefCount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|QWinIoCompletionPort
class|class
name|QWinIoCompletionPort
super|:
specifier|protected
name|QThread
block|{
public|public:
DECL|function|QWinIoCompletionPort
name|QWinIoCompletionPort
parameter_list|()
member_init_list|:
name|finishThreadKey
argument_list|(
cast|reinterpret_cast
argument_list|<
name|ULONG_PTR
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
member_init_list|,
name|drainQueueKey
argument_list|(
cast|reinterpret_cast
argument_list|<
name|ULONG_PTR
argument_list|>
argument_list|(
name|this
operator|+
literal|1
argument_list|)
argument_list|)
member_init_list|,
name|hPort
argument_list|(
name|INVALID_HANDLE_VALUE
argument_list|)
block|{
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"I/O completion port thread"
argument_list|)
argument_list|)
expr_stmt|;
name|HANDLE
name|hIOCP
init|=
name|CreateIoCompletionPort
argument_list|(
name|INVALID_HANDLE_VALUE
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|hIOCP
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"CreateIoCompletionPort failed."
argument_list|)
expr_stmt|;
return|return;
block|}
name|hPort
operator|=
name|hIOCP
expr_stmt|;
name|hQueueDrainedEvent
operator|=
name|CreateEvent
argument_list|(
name|NULL
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hQueueDrainedEvent
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"CreateEvent failed."
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
DECL|function|~QWinIoCompletionPort
name|~
name|QWinIoCompletionPort
parameter_list|()
block|{
name|PostQueuedCompletionStatus
argument_list|(
name|hPort
argument_list|,
literal|0
argument_list|,
name|finishThreadKey
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|QThread
operator|::
name|wait
argument_list|()
expr_stmt|;
name|CloseHandle
argument_list|(
name|hPort
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|hQueueDrainedEvent
argument_list|)
expr_stmt|;
block|}
DECL|function|registerNotifier
name|void
name|registerNotifier
parameter_list|(
name|QWinOverlappedIoNotifierPrivate
modifier|*
name|notifier
parameter_list|)
block|{
specifier|const
name|HANDLE
name|hHandle
init|=
name|notifier
operator|->
name|hHandle
decl_stmt|;
name|HANDLE
name|hIOCP
init|=
name|CreateIoCompletionPort
argument_list|(
name|hHandle
argument_list|,
name|hPort
argument_list|,
cast|reinterpret_cast
argument_list|<
name|ULONG_PTR
argument_list|>
argument_list|(
name|notifier
argument_list|)
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|hIOCP
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"Can't associate file handle %x with I/O completion port."
argument_list|,
name|hHandle
argument_list|)
expr_stmt|;
return|return;
block|}
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|notifiers
operator|+=
name|notifier
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|QThread
operator|::
name|isRunning
argument_list|()
condition|)
name|QThread
operator|::
name|start
argument_list|()
expr_stmt|;
block|}
DECL|function|unregisterNotifier
name|void
name|unregisterNotifier
parameter_list|(
name|QWinOverlappedIoNotifierPrivate
modifier|*
name|notifier
parameter_list|)
block|{
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|notifiers
operator|.
name|remove
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
DECL|function|drainQueue
name|void
name|drainQueue
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|drainQueueMutex
argument_list|)
decl_stmt|;
name|ResetEvent
argument_list|(
name|hQueueDrainedEvent
argument_list|)
expr_stmt|;
name|PostQueuedCompletionStatus
argument_list|(
name|hPort
argument_list|,
literal|0
argument_list|,
name|drainQueueKey
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|WaitForSingleObject
argument_list|(
name|hQueueDrainedEvent
argument_list|,
name|INFINITE
argument_list|)
expr_stmt|;
block|}
using|using
name|QThread
operator|::
name|isRunning
using|;
protected|protected:
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|DWORD
name|dwBytesRead
decl_stmt|;
name|ULONG_PTR
name|pulCompletionKey
decl_stmt|;
name|OVERLAPPED
modifier|*
name|overlapped
decl_stmt|;
name|DWORD
name|msecs
init|=
name|INFINITE
decl_stmt|;
forever|forever
block|{
name|BOOL
name|success
init|=
name|GetQueuedCompletionStatus
argument_list|(
name|hPort
argument_list|,
operator|&
name|dwBytesRead
argument_list|,
operator|&
name|pulCompletionKey
argument_list|,
operator|&
name|overlapped
argument_list|,
name|msecs
argument_list|)
decl_stmt|;
name|DWORD
name|errorCode
init|=
name|success
condition|?
name|ERROR_SUCCESS
else|:
name|GetLastError
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|success
operator|&&
operator|!
name|overlapped
condition|)
block|{
if|if
condition|(
operator|!
name|msecs
condition|)
block|{
comment|// Time out in drain mode. The completion status queue is empty.
name|msecs
operator|=
name|INFINITE
expr_stmt|;
name|SetEvent
argument_list|(
name|hQueueDrainedEvent
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|qErrnoWarning
argument_list|(
name|errorCode
argument_list|,
literal|"GetQueuedCompletionStatus failed."
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|pulCompletionKey
operator|==
name|finishThreadKey
condition|)
return|return;
if|if
condition|(
name|pulCompletionKey
operator|==
name|drainQueueKey
condition|)
block|{
comment|// Enter drain mode.
name|Q_ASSERT
argument_list|(
name|msecs
operator|==
name|INFINITE
argument_list|)
expr_stmt|;
name|msecs
operator|=
literal|0
expr_stmt|;
continue|continue;
block|}
name|QWinOverlappedIoNotifierPrivate
modifier|*
name|notifier
init|=
cast|reinterpret_cast
argument_list|<
name|QWinOverlappedIoNotifierPrivate
operator|*
argument_list|>
argument_list|(
name|pulCompletionKey
argument_list|)
decl_stmt|;
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|notifiers
operator|.
name|contains
argument_list|(
name|notifier
argument_list|)
condition|)
name|notifier
operator|->
name|notify
argument_list|(
name|dwBytesRead
argument_list|,
name|errorCode
argument_list|,
name|overlapped
argument_list|)
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
block|}
private|private:
DECL|member|finishThreadKey
specifier|const
name|ULONG_PTR
name|finishThreadKey
decl_stmt|;
DECL|member|drainQueueKey
specifier|const
name|ULONG_PTR
name|drainQueueKey
decl_stmt|;
DECL|member|hPort
name|HANDLE
name|hPort
decl_stmt|;
DECL|member|notifiers
name|QSet
argument_list|<
name|QWinOverlappedIoNotifierPrivate
modifier|*
argument_list|>
name|notifiers
decl_stmt|;
DECL|member|mutex
name|QMutex
name|mutex
decl_stmt|;
DECL|member|drainQueueMutex
name|QMutex
name|drainQueueMutex
decl_stmt|;
DECL|member|hQueueDrainedEvent
name|HANDLE
name|hQueueDrainedEvent
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QWinOverlappedIoNotifier
name|QWinOverlappedIoNotifier
operator|::
name|QWinOverlappedIoNotifier
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
name|QWinOverlappedIoNotifierPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QWinOverlappedIoNotifier
argument_list|)
expr_stmt|;
name|WaitForSingleObject
argument_list|(
name|d
operator|->
name|iocpInstanceLock
argument_list|,
name|INFINITE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|iocp
condition|)
name|d
operator|->
name|iocp
operator|=
operator|new
name|QWinIoCompletionPort
expr_stmt|;
name|d
operator|->
name|iocpInstanceRefCount
operator|++
expr_stmt|;
name|ReleaseMutex
argument_list|(
name|d
operator|->
name|iocpInstanceLock
argument_list|)
expr_stmt|;
name|d
operator|->
name|hSemaphore
operator|=
name|CreateSemaphore
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|d
operator|->
name|hResultsMutex
operator|=
name|CreateMutex
argument_list|(
name|NULL
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|_q_notify
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_notified
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWinOverlappedIoNotifier
name|QWinOverlappedIoNotifier
operator|::
name|~
name|QWinOverlappedIoNotifier
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWinOverlappedIoNotifier
argument_list|)
expr_stmt|;
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|d
operator|->
name|hResultsMutex
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|d
operator|->
name|hSemaphore
argument_list|)
expr_stmt|;
name|WaitForSingleObject
argument_list|(
name|d
operator|->
name|iocpInstanceLock
argument_list|,
name|INFINITE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|--
name|d
operator|->
name|iocpInstanceRefCount
condition|)
block|{
operator|delete
name|d
operator|->
name|iocp
expr_stmt|;
name|d
operator|->
name|iocp
operator|=
literal|0
expr_stmt|;
block|}
name|ReleaseMutex
argument_list|(
name|d
operator|->
name|iocpInstanceLock
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setHandle
name|void
name|QWinOverlappedIoNotifier
operator|::
name|setHandle
parameter_list|(
name|Qt
operator|::
name|HANDLE
name|h
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinOverlappedIoNotifier
argument_list|)
expr_stmt|;
name|d
operator|->
name|hHandle
operator|=
name|h
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handle
name|Qt
operator|::
name|HANDLE
name|QWinOverlappedIoNotifier
operator|::
name|handle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinOverlappedIoNotifier
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|hHandle
return|;
block|}
end_function
begin_function
DECL|function|setEnabled
name|void
name|QWinOverlappedIoNotifier
operator|::
name|setEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinOverlappedIoNotifier
argument_list|)
expr_stmt|;
if|if
condition|(
name|enabled
condition|)
name|d
operator|->
name|iocp
operator|->
name|registerNotifier
argument_list|(
name|d
argument_list|)
expr_stmt|;
else|else
name|d
operator|->
name|iocp
operator|->
name|unregisterNotifier
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForAnyNotified
name|OVERLAPPED
modifier|*
name|QWinOverlappedIoNotifierPrivate
operator|::
name|waitForAnyNotified
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
if|if
condition|(
operator|!
name|iocp
operator|->
name|isRunning
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"Called QWinOverlappedIoNotifier::waitForAnyNotified on inactive notifier."
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|msecs
operator|==
literal|0
condition|)
name|iocp
operator|->
name|drainQueue
argument_list|()
expr_stmt|;
specifier|const
name|DWORD
name|wfso
init|=
name|WaitForSingleObject
argument_list|(
name|hSemaphore
argument_list|,
name|msecs
operator|==
operator|-
literal|1
condition|?
name|INFINITE
else|:
name|DWORD
argument_list|(
name|msecs
argument_list|)
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|wfso
condition|)
block|{
case|case
name|WAIT_OBJECT_0
case|:
return|return
name|dispatchNextIoResult
argument_list|()
return|;
case|case
name|WAIT_TIMEOUT
case|:
return|return
literal|0
return|;
default|default:
name|qErrnoWarning
argument_list|(
literal|"QWinOverlappedIoNotifier::waitForAnyNotified: WaitForSingleObject failed."
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_function
begin_class
DECL|class|QScopedAtomicIntIncrementor
class|class
name|QScopedAtomicIntIncrementor
block|{
public|public:
DECL|function|QScopedAtomicIntIncrementor
name|QScopedAtomicIntIncrementor
parameter_list|(
name|QAtomicInt
modifier|&
name|i
parameter_list|)
member_init_list|:
name|m_int
argument_list|(
name|i
argument_list|)
block|{
operator|++
name|m_int
expr_stmt|;
block|}
DECL|function|~QScopedAtomicIntIncrementor
name|~
name|QScopedAtomicIntIncrementor
parameter_list|()
block|{
operator|--
name|m_int
expr_stmt|;
block|}
private|private:
DECL|member|m_int
name|QAtomicInt
modifier|&
name|m_int
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!  * Wait synchronously for any notified signal.  *  * The function returns a pointer to the OVERLAPPED object corresponding to the completed I/O  * operation. In case no I/O operation was completed during the \a msec timeout, this function  * returns a null pointer.  */
end_comment
begin_function
DECL|function|waitForAnyNotified
name|OVERLAPPED
modifier|*
name|QWinOverlappedIoNotifier
operator|::
name|waitForAnyNotified
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinOverlappedIoNotifier
argument_list|)
expr_stmt|;
name|QScopedAtomicIntIncrementor
name|saii
argument_list|(
name|d
operator|->
name|waiting
argument_list|)
decl_stmt|;
name|OVERLAPPED
modifier|*
name|result
init|=
name|d
operator|->
name|waitForAnyNotified
argument_list|(
name|msecs
argument_list|)
decl_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!  * Wait synchronously for the notified signal.  *  * The function returns true if the notified signal was emitted for  * the I/O operation that corresponds to the OVERLAPPED object.  */
end_comment
begin_function
DECL|function|waitForNotified
name|bool
name|QWinOverlappedIoNotifier
operator|::
name|waitForNotified
parameter_list|(
name|int
name|msecs
parameter_list|,
name|OVERLAPPED
modifier|*
name|overlapped
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinOverlappedIoNotifier
argument_list|)
expr_stmt|;
name|QScopedAtomicIntIncrementor
name|saii
argument_list|(
name|d
operator|->
name|waiting
argument_list|)
decl_stmt|;
name|int
name|t
init|=
name|msecs
decl_stmt|;
name|QElapsedTimer
name|stopWatch
decl_stmt|;
name|stopWatch
operator|.
name|start
argument_list|()
expr_stmt|;
forever|forever
block|{
name|OVERLAPPED
modifier|*
name|triggeredOverlapped
init|=
name|waitForAnyNotified
argument_list|(
name|t
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|triggeredOverlapped
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|triggeredOverlapped
operator|==
name|overlapped
condition|)
return|return
literal|true
return|;
name|msecs
operator|=
name|qt_subtract_from_timeout
argument_list|(
name|msecs
argument_list|,
name|stopWatch
operator|.
name|elapsed
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|==
literal|0
condition|)
return|return
literal|false
return|;
block|}
block|}
end_function
begin_comment
comment|/*!   * Note: This function runs in the I/O completion port thread.   */
end_comment
begin_function
DECL|function|notify
name|void
name|QWinOverlappedIoNotifierPrivate
operator|::
name|notify
parameter_list|(
name|DWORD
name|numberOfBytes
parameter_list|,
name|DWORD
name|errorCode
parameter_list|,
name|OVERLAPPED
modifier|*
name|overlapped
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QWinOverlappedIoNotifier
argument_list|)
expr_stmt|;
name|WaitForSingleObject
argument_list|(
name|hResultsMutex
argument_list|,
name|INFINITE
argument_list|)
expr_stmt|;
name|results
operator|.
name|enqueue
argument_list|(
name|IOResult
argument_list|(
name|numberOfBytes
argument_list|,
name|errorCode
argument_list|,
name|overlapped
argument_list|)
argument_list|)
expr_stmt|;
name|ReleaseMutex
argument_list|(
name|hResultsMutex
argument_list|)
expr_stmt|;
name|ReleaseSemaphore
argument_list|(
name|hSemaphore
argument_list|,
literal|1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|waiting
condition|)
emit|emit
name|q
operator|->
name|_q_notify
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|_q_notified
name|void
name|QWinOverlappedIoNotifierPrivate
operator|::
name|_q_notified
parameter_list|()
block|{
if|if
condition|(
name|WaitForSingleObject
argument_list|(
name|hSemaphore
argument_list|,
literal|0
argument_list|)
operator|==
name|WAIT_OBJECT_0
condition|)
name|dispatchNextIoResult
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dispatchNextIoResult
name|OVERLAPPED
modifier|*
name|QWinOverlappedIoNotifierPrivate
operator|::
name|dispatchNextIoResult
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QWinOverlappedIoNotifier
argument_list|)
expr_stmt|;
name|WaitForSingleObject
argument_list|(
name|hResultsMutex
argument_list|,
name|INFINITE
argument_list|)
expr_stmt|;
name|IOResult
name|ioresult
init|=
name|results
operator|.
name|dequeue
argument_list|()
decl_stmt|;
name|ReleaseMutex
argument_list|(
name|hResultsMutex
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|notified
argument_list|(
name|ioresult
operator|.
name|numberOfBytes
argument_list|,
name|ioresult
operator|.
name|errorCode
argument_list|,
name|ioresult
operator|.
name|overlapped
argument_list|)
emit|;
return|return
name|ioresult
operator|.
name|overlapped
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qwinoverlappedionotifier_p.cpp"
end_include
end_unit
