begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfuturewatcher.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QFUTURE
end_ifndef
begin_include
include|#
directive|include
file|"qfuturewatcher_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreevent.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qthread.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*! \class QFutureWatcher     \reentrant     \since 4.4      \inmodule QtCore     \ingroup thread      \brief The QFutureWatcher class allows monitoring a QFuture using signals     and slots.      QFutureWatcher provides information and notifications about a QFuture. Use     the setFuture() function to start watching a particular QFuture. The     future() function returns the future set with setFuture().      For convenience, several of QFuture's functions are also available in     QFutureWatcher: progressValue(), progressMinimum(), progressMaximum(),     progressText(), isStarted(), isFinished(), isRunning(), isCanceled(),     isPaused(), waitForFinished(), result(), and resultAt(). The cancel(),     setPaused(), pause(), resume(), and togglePaused() functions are slots in     QFutureWatcher.      Status changes are reported via the started(), finished(), canceled(),     paused(), resumed(), resultReadyAt(), and resultsReadyAt() signals.     Progress information is provided from the progressRangeChanged(),     void progressValueChanged(), and progressTextChanged() signals.      Throttling control is provided by the setPendingResultsLimit() function.     When the number of pending resultReadyAt() or resultsReadyAt() signals     exceeds the limit, the computation represented by the future will be     throttled automatically. The computation will resume once the number of     pending signals drops below the limit.      Example: Starting a computation and getting a slot callback when it's     finished:      \snippet code/src_corelib_thread_qfuturewatcher.cpp 0      Be aware that not all asynchronous computations can be canceled or paused.     For example, the future returned by QtConcurrent::run() cannot be     canceled; but the future returned by QtConcurrent::mappedReduced() can.      QFutureWatcher<void> is specialized to not contain any of the result     fetching functions. Any QFuture<T> can be watched by a     QFutureWatcher<void> as well. This is useful if only status or progress     information is needed; not the actual result data.      \sa QFuture, {Qt Concurrent} */
end_comment
begin_comment
comment|/*! \fn QFutureWatcher::QFutureWatcher(QObject *parent)      Constructs a new QFutureWatcher with the given \a parent. */
end_comment
begin_constructor
DECL|function|QFutureWatcherBase
name|QFutureWatcherBase
operator|::
name|QFutureWatcherBase
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
name|QFutureWatcherBasePrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*! \fn QFutureWatcher::~QFutureWatcher()      Destroys the QFutureWatcher. */
end_comment
begin_comment
comment|/*! \fn void QFutureWatcher::cancel()      Cancels the asynchronous computation represented by the future(). Note that     the cancelation is asynchronous. Use waitForFinished() after calling     cancel() when you need synchronous cancelation.      Currently available results may still be accessed on a canceled QFuture,     but new results will \e not become available after calling this function.     Also, this QFutureWatcher will not deliver progress and result ready     signals once canceled. This includes the progressValueChanged(),     progressRangeChanged(), progressTextChanged(), resultReadyAt(), and     resultsReadyAt() signals.      Be aware that not all asynchronous computations can be canceled. For     example, the QFuture returned by QtConcurrent::run() cannot be canceled;     but the QFuture returned by QtConcurrent::mappedReduced() can. */
end_comment
begin_function
DECL|function|cancel
name|void
name|QFutureWatcherBase
operator|::
name|cancel
parameter_list|()
block|{
name|futureInterface
argument_list|()
operator|.
name|cancel
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \fn void QFutureWatcher::setPaused(bool paused)      If \a paused is true, this function pauses the asynchronous computation     represented by the future(). If the computation is already paused, this     function does nothing. This QFutureWatcher will stop delivering progress     and result ready signals while the future is paused. Signal delivery will     continue once the computation is resumed.      If \a paused is false, this function resumes the asynchronous computation.     If the computation was not previously paused, this function does nothing.      Be aware that not all computations can be paused. For example, the     QFuture returned by QtConcurrent::run() cannot be paused; but the QFuture     returned by QtConcurrent::mappedReduced() can.      \sa pause(), resume(), togglePaused() */
end_comment
begin_function
DECL|function|setPaused
name|void
name|QFutureWatcherBase
operator|::
name|setPaused
parameter_list|(
name|bool
name|paused
parameter_list|)
block|{
name|futureInterface
argument_list|()
operator|.
name|setPaused
argument_list|(
name|paused
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \fn void QFutureWatcher::pause()      Pauses the asynchronous computation represented by the future(). This is a     convenience method that simply calls setPaused(true).      \sa resume() */
end_comment
begin_function
DECL|function|pause
name|void
name|QFutureWatcherBase
operator|::
name|pause
parameter_list|()
block|{
name|futureInterface
argument_list|()
operator|.
name|setPaused
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \fn void QFutureWatcher::resume()      Resumes the asynchronous computation represented by the future(). This is     a convenience method that simply calls setPaused(false).      \sa pause() */
end_comment
begin_function
DECL|function|resume
name|void
name|QFutureWatcherBase
operator|::
name|resume
parameter_list|()
block|{
name|futureInterface
argument_list|()
operator|.
name|setPaused
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \fn void QFutureWatcher::togglePaused()      Toggles the paused state of the asynchronous computation. In other words,     if the computation is currently paused, calling this function resumes it;     if the computation is running, it becomes paused. This is a convenience     method for calling setPaused(!isPaused()).      \sa setPaused(), pause(), resume() */
end_comment
begin_function
DECL|function|togglePaused
name|void
name|QFutureWatcherBase
operator|::
name|togglePaused
parameter_list|()
block|{
name|futureInterface
argument_list|()
operator|.
name|togglePaused
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \fn int QFutureWatcher::progressValue() const      Returns the current progress value, which is between the progressMinimum()     and progressMaximum().      \sa progressMinimum(), progressMaximum() */
end_comment
begin_function
DECL|function|progressValue
name|int
name|QFutureWatcherBase
operator|::
name|progressValue
parameter_list|()
specifier|const
block|{
return|return
name|futureInterface
argument_list|()
operator|.
name|progressValue
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \fn int QFutureWatcher::progressMinimum() const      Returns the minimum progressValue().      \sa progressValue(), progressMaximum() */
end_comment
begin_function
DECL|function|progressMinimum
name|int
name|QFutureWatcherBase
operator|::
name|progressMinimum
parameter_list|()
specifier|const
block|{
return|return
name|futureInterface
argument_list|()
operator|.
name|progressMinimum
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \fn int QFutureWatcher::progressMaximum() const      Returns the maximum progressValue().      \sa progressValue(), progressMinimum() */
end_comment
begin_function
DECL|function|progressMaximum
name|int
name|QFutureWatcherBase
operator|::
name|progressMaximum
parameter_list|()
specifier|const
block|{
return|return
name|futureInterface
argument_list|()
operator|.
name|progressMaximum
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \fn QString QFutureWatcher::progressText() const      Returns the (optional) textual representation of the progress as reported     by the asynchronous computation.      Be aware that not all computations provide a textual representation of the     progress, and as such, this function may return an empty string. */
end_comment
begin_function
DECL|function|progressText
name|QString
name|QFutureWatcherBase
operator|::
name|progressText
parameter_list|()
specifier|const
block|{
return|return
name|futureInterface
argument_list|()
operator|.
name|progressText
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \fn bool QFutureWatcher::isStarted() const      Returns \c true if the asynchronous computation represented by the future()     has been started; otherwise returns \c false. */
end_comment
begin_function
DECL|function|isStarted
name|bool
name|QFutureWatcherBase
operator|::
name|isStarted
parameter_list|()
specifier|const
block|{
return|return
name|futureInterface
argument_list|()
operator|.
name|queryState
argument_list|(
name|QFutureInterfaceBase
operator|::
name|Started
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \fn bool QFutureWatcher::isFinished() const      Returns \c true if the asynchronous computation represented by the future()     has finished; otherwise returns \c false. */
end_comment
begin_function
DECL|function|isFinished
name|bool
name|QFutureWatcherBase
operator|::
name|isFinished
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFutureWatcherBase
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|finished
return|;
block|}
end_function
begin_comment
comment|/*! \fn bool QFutureWatcher::isRunning() const      Returns \c true if the asynchronous computation represented by the future()     is currently running; otherwise returns \c false. */
end_comment
begin_function
DECL|function|isRunning
name|bool
name|QFutureWatcherBase
operator|::
name|isRunning
parameter_list|()
specifier|const
block|{
return|return
name|futureInterface
argument_list|()
operator|.
name|queryState
argument_list|(
name|QFutureInterfaceBase
operator|::
name|Running
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \fn bool QFutureWatcher::isCanceled() const      Returns \c true if the asynchronous computation has been canceled with the     cancel() function; otherwise returns \c false.      Be aware that the computation may still be running even though this     function returns \c true. See cancel() for more details. */
end_comment
begin_function
DECL|function|isCanceled
name|bool
name|QFutureWatcherBase
operator|::
name|isCanceled
parameter_list|()
specifier|const
block|{
return|return
name|futureInterface
argument_list|()
operator|.
name|queryState
argument_list|(
name|QFutureInterfaceBase
operator|::
name|Canceled
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \fn bool QFutureWatcher::isPaused() const      Returns \c true if the asynchronous computation has been paused with the     pause() function; otherwise returns \c false.      Be aware that the computation may still be running even though this     function returns \c true. See setPaused() for more details.      \sa setPaused(), togglePaused() */
end_comment
begin_function
DECL|function|isPaused
name|bool
name|QFutureWatcherBase
operator|::
name|isPaused
parameter_list|()
specifier|const
block|{
return|return
name|futureInterface
argument_list|()
operator|.
name|queryState
argument_list|(
name|QFutureInterfaceBase
operator|::
name|Paused
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \fn void QFutureWatcher::waitForFinished()      Waits for the asynchronous computation to finish (including cancel()ed     computations). */
end_comment
begin_function
DECL|function|waitForFinished
name|void
name|QFutureWatcherBase
operator|::
name|waitForFinished
parameter_list|()
block|{
name|futureInterface
argument_list|()
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \fn void QFutureWatcher::setPendingResultsLimit(int limit)      The setPendingResultsLimit() provides throttling control. When the number     of pending resultReadyAt() or resultsReadyAt() signals exceeds the     \a limit, the computation represented by the future will be throttled     automatically. The computation will resume once the number of pending     signals drops below the \a limit. */
end_comment
begin_function
DECL|function|event
name|bool
name|QFutureWatcherBase
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFutureWatcherBase
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|FutureCallOut
condition|)
block|{
name|QFutureCallOutEvent
modifier|*
name|callOutEvent
init|=
cast|static_cast
argument_list|<
name|QFutureCallOutEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|futureInterface
argument_list|()
operator|.
name|isPaused
argument_list|()
condition|)
block|{
name|d
operator|->
name|pendingCallOutEvents
operator|.
name|append
argument_list|(
name|callOutEvent
operator|->
name|clone
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
name|callOutEvent
operator|->
name|callOutType
operator|==
name|QFutureCallOutEvent
operator|::
name|Resumed
operator|&&
operator|!
name|d
operator|->
name|pendingCallOutEvents
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// send the resume
name|d
operator|->
name|sendCallOutEvent
argument_list|(
name|callOutEvent
argument_list|)
expr_stmt|;
comment|// next send all pending call outs
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|pendingCallOutEvents
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|d
operator|->
name|sendCallOutEvent
argument_list|(
name|d
operator|->
name|pendingCallOutEvents
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|qDeleteAll
argument_list|(
name|d
operator|->
name|pendingCallOutEvents
argument_list|)
expr_stmt|;
name|d
operator|->
name|pendingCallOutEvents
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|sendCallOutEvent
argument_list|(
name|callOutEvent
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
return|return
name|QObject
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setPendingResultsLimit
name|void
name|QFutureWatcherBase
operator|::
name|setPendingResultsLimit
parameter_list|(
name|int
name|limit
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFutureWatcherBase
argument_list|)
expr_stmt|;
name|d
operator|->
name|maximumPendingResultsReady
operator|=
name|limit
expr_stmt|;
block|}
end_function
begin_function
DECL|function|connectNotify
name|void
name|QFutureWatcherBase
operator|::
name|connectNotify
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
name|signal
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFutureWatcherBase
argument_list|)
expr_stmt|;
specifier|static
specifier|const
name|QMetaMethod
name|resultReadyAtSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QFutureWatcherBase
operator|::
name|resultReadyAt
argument_list|)
decl_stmt|;
if|if
condition|(
name|signal
operator|==
name|resultReadyAtSignal
condition|)
name|d
operator|->
name|resultAtConnected
operator|.
name|ref
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
specifier|static
specifier|const
name|QMetaMethod
name|finishedSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QFutureWatcherBase
operator|::
name|finished
argument_list|)
decl_stmt|;
if|if
condition|(
name|signal
operator|==
name|finishedSignal
condition|)
block|{
if|if
condition|(
name|futureInterface
argument_list|()
operator|.
name|isRunning
argument_list|()
condition|)
block|{
comment|//connections should be established before calling stFuture to avoid race.
comment|// (The future could finish before the connection is made.)
name|qWarning
argument_list|(
literal|"QFutureWatcher::connect: connecting after calling setFuture() is likely to produce race"
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|disconnectNotify
name|void
name|QFutureWatcherBase
operator|::
name|disconnectNotify
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
name|signal
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFutureWatcherBase
argument_list|)
expr_stmt|;
specifier|static
specifier|const
name|QMetaMethod
name|resultReadyAtSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QFutureWatcherBase
operator|::
name|resultReadyAt
argument_list|)
decl_stmt|;
if|if
condition|(
name|signal
operator|==
name|resultReadyAtSignal
condition|)
name|d
operator|->
name|resultAtConnected
operator|.
name|deref
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QFutureWatcherBasePrivate
name|QFutureWatcherBasePrivate
operator|::
name|QFutureWatcherBasePrivate
parameter_list|()
member_init_list|:
name|maximumPendingResultsReady
argument_list|(
name|QThread
operator|::
name|idealThreadCount
argument_list|()
operator|*
literal|2
argument_list|)
member_init_list|,
name|resultAtConnected
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|connectOutputInterface
name|void
name|QFutureWatcherBase
operator|::
name|connectOutputInterface
parameter_list|()
block|{
name|futureInterface
argument_list|()
operator|.
name|d
operator|->
name|connectOutputInterface
argument_list|(
name|d_func
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|disconnectOutputInterface
name|void
name|QFutureWatcherBase
operator|::
name|disconnectOutputInterface
parameter_list|(
name|bool
name|pendingAssignment
parameter_list|)
block|{
if|if
condition|(
name|pendingAssignment
condition|)
block|{
name|Q_D
argument_list|(
name|QFutureWatcherBase
argument_list|)
expr_stmt|;
name|d
operator|->
name|pendingResultsReady
operator|.
name|store
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|qDeleteAll
argument_list|(
name|d
operator|->
name|pendingCallOutEvents
argument_list|)
expr_stmt|;
name|d
operator|->
name|pendingCallOutEvents
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|finished
operator|=
literal|false
expr_stmt|;
block|}
name|futureInterface
argument_list|()
operator|.
name|d
operator|->
name|disconnectOutputInterface
argument_list|(
name|d_func
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|postCallOutEvent
name|void
name|QFutureWatcherBasePrivate
operator|::
name|postCallOutEvent
parameter_list|(
specifier|const
name|QFutureCallOutEvent
modifier|&
name|callOutEvent
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QFutureWatcherBase
argument_list|)
expr_stmt|;
if|if
condition|(
name|callOutEvent
operator|.
name|callOutType
operator|==
name|QFutureCallOutEvent
operator|::
name|ResultsReady
condition|)
block|{
if|if
condition|(
name|pendingResultsReady
operator|.
name|fetchAndAddRelaxed
argument_list|(
literal|1
argument_list|)
operator|>=
name|maximumPendingResultsReady
condition|)
name|q
operator|->
name|futureInterface
argument_list|()
operator|.
name|d
operator|->
name|internal_setThrottled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|q
argument_list|,
name|callOutEvent
operator|.
name|clone
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|callOutInterfaceDisconnected
name|void
name|QFutureWatcherBasePrivate
operator|::
name|callOutInterfaceDisconnected
parameter_list|()
block|{
name|QCoreApplication
operator|::
name|removePostedEvents
argument_list|(
name|q_func
argument_list|()
argument_list|,
name|QEvent
operator|::
name|FutureCallOut
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sendCallOutEvent
name|void
name|QFutureWatcherBasePrivate
operator|::
name|sendCallOutEvent
parameter_list|(
name|QFutureCallOutEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QFutureWatcherBase
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|event
operator|->
name|callOutType
condition|)
block|{
case|case
name|QFutureCallOutEvent
operator|::
name|Started
case|:
emit|emit
name|q
operator|->
name|started
argument_list|()
emit|;
break|break;
case|case
name|QFutureCallOutEvent
operator|::
name|Finished
case|:
name|finished
operator|=
literal|true
expr_stmt|;
emit|emit
name|q
operator|->
name|finished
argument_list|()
emit|;
break|break;
case|case
name|QFutureCallOutEvent
operator|::
name|Canceled
case|:
name|pendingResultsReady
operator|.
name|store
argument_list|(
literal|0
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|canceled
argument_list|()
emit|;
break|break;
case|case
name|QFutureCallOutEvent
operator|::
name|Paused
case|:
if|if
condition|(
name|q
operator|->
name|futureInterface
argument_list|()
operator|.
name|isCanceled
argument_list|()
condition|)
break|break;
emit|emit
name|q
operator|->
name|paused
argument_list|()
emit|;
break|break;
case|case
name|QFutureCallOutEvent
operator|::
name|Resumed
case|:
if|if
condition|(
name|q
operator|->
name|futureInterface
argument_list|()
operator|.
name|isCanceled
argument_list|()
condition|)
break|break;
emit|emit
name|q
operator|->
name|resumed
argument_list|()
emit|;
break|break;
case|case
name|QFutureCallOutEvent
operator|::
name|ResultsReady
case|:
block|{
if|if
condition|(
name|q
operator|->
name|futureInterface
argument_list|()
operator|.
name|isCanceled
argument_list|()
condition|)
break|break;
if|if
condition|(
name|pendingResultsReady
operator|.
name|fetchAndAddRelaxed
argument_list|(
operator|-
literal|1
argument_list|)
operator|<=
name|maximumPendingResultsReady
condition|)
name|q
operator|->
name|futureInterface
argument_list|()
operator|.
name|setThrottled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
specifier|const
name|int
name|beginIndex
init|=
name|event
operator|->
name|index1
decl_stmt|;
specifier|const
name|int
name|endIndex
init|=
name|event
operator|->
name|index2
decl_stmt|;
emit|emit
name|q
operator|->
name|resultsReadyAt
argument_list|(
name|beginIndex
argument_list|,
name|endIndex
argument_list|)
emit|;
if|if
condition|(
name|resultAtConnected
operator|.
name|load
argument_list|()
operator|<=
literal|0
condition|)
break|break;
for|for
control|(
name|int
name|i
init|=
name|beginIndex
init|;
name|i
operator|<
name|endIndex
condition|;
operator|++
name|i
control|)
emit|emit
name|q
operator|->
name|resultReadyAt
argument_list|(
name|i
argument_list|)
emit|;
block|}
break|break;
case|case
name|QFutureCallOutEvent
operator|::
name|Progress
case|:
if|if
condition|(
name|q
operator|->
name|futureInterface
argument_list|()
operator|.
name|isCanceled
argument_list|()
condition|)
break|break;
emit|emit
name|q
operator|->
name|progressValueChanged
argument_list|(
name|event
operator|->
name|index1
argument_list|)
emit|;
if|if
condition|(
operator|!
name|event
operator|->
name|text
operator|.
name|isNull
argument_list|()
condition|)
comment|// ###
name|q
operator|->
name|progressTextChanged
argument_list|(
name|event
operator|->
name|text
argument_list|)
expr_stmt|;
break|break;
case|case
name|QFutureCallOutEvent
operator|::
name|ProgressRange
case|:
emit|emit
name|q
operator|->
name|progressRangeChanged
argument_list|(
name|event
operator|->
name|index1
argument_list|,
name|event
operator|->
name|index2
argument_list|)
emit|;
break|break;
default|default:
break|break;
block|}
block|}
end_function
begin_comment
comment|/*! \fn const T&QFutureWatcher::result() const      Returns the first result in the future(). If the result is not immediately     available, this function will block and wait for the result to become     available. This is a convenience method for calling resultAt(0).      \sa resultAt() */
end_comment
begin_comment
comment|/*! \fn const T&QFutureWatcher::resultAt(int index) const      Returns the result at \a index in the future(). If the result is not     immediately available, this function will block and wait for the result to     become available.      \sa result() */
end_comment
begin_comment
comment|/*! \fn void QFutureWatcher::setFuture(const QFuture<T>&future)      Starts watching the given \a future.      One of the signals might be emitted for the current state of the     \a future. For example, if the future is already stopped, the     finished signal will be emitted.      To avoid a race condition, it is important to call this function     \e after doing the connections. */
end_comment
begin_comment
comment|/*! \fn QFuture<T> QFutureWatcher::future() const      Returns the watched future. */
end_comment
begin_comment
comment|/*! \fn void QFutureWatcher::started()      This signal is emitted when this QFutureWatcher starts watching the future     set with setFuture(). */
end_comment
begin_comment
comment|/*!     \fn void QFutureWatcher::finished()     This signal is emitted when the watched future finishes. */
end_comment
begin_comment
comment|/*!     \fn void QFutureWatcher::canceled()     This signal is emitted if the watched future is canceled. */
end_comment
begin_comment
comment|/*! \fn void QFutureWatcher::paused()     This signal is emitted when the watched future is paused. */
end_comment
begin_comment
comment|/*! \fn void QFutureWatcher::resumed()     This signal is emitted when the watched future is resumed. */
end_comment
begin_comment
comment|/*!     \fn void QFutureWatcher::progressRangeChanged(int minimum, int maximum)      The progress range for the watched future has changed to \a minimum and     \a maximum */
end_comment
begin_comment
comment|/*!     \fn void QFutureWatcher::progressValueChanged(int progressValue)      This signal is emitted when the watched future reports progress,     \a progressValue gives the current progress. In order to avoid overloading     the GUI event loop, QFutureWatcher limits the progress signal emission     rate. This means that listeners connected to this slot might not get all     progress reports the future makes. The last progress update (where     \a progressValue equals the maximum value) will always be delivered. */
end_comment
begin_comment
comment|/*! \fn void QFutureWatcher::progressTextChanged(const QString&progressText)      This signal is emitted when the watched future reports textual progress     information, \a progressText. */
end_comment
begin_comment
comment|/*!     \fn void QFutureWatcher::resultReadyAt(int index)      This signal is emitted when the watched future reports a ready result at     \a index. If the future reports multiple results, the index will indicate     which one it is. Results can be reported out-of-order. To get the result,     call future().result(index); */
end_comment
begin_comment
comment|/*!     \fn void QFutureWatcher::resultsReadyAt(int beginIndex, int endIndex);      This signal is emitted when the watched future reports ready results.     The results are indexed from \a beginIndex to \a endIndex.  */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QFUTURE
end_comment
end_unit
