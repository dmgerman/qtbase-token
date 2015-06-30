begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFUTUREINTERFACE_H
end_ifndef
begin_define
DECL|macro|QFUTUREINTERFACE_H
define|#
directive|define
name|QFUTUREINTERFACE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qrunnable.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QFUTURE
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qexception.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qresultstore.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFuture
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QFuture
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QThreadPool
name|class
name|QThreadPool
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFutureInterfaceBasePrivate
name|class
name|QFutureInterfaceBasePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFutureWatcherBase
name|class
name|QFutureWatcherBase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFutureWatcherBasePrivate
name|class
name|QFutureWatcherBasePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QFutureInterfaceBase
block|{
name|public
label|:
enum|enum
name|State
block|{
name|NoState
init|=
literal|0x00
block|,
name|Running
init|=
literal|0x01
block|,
name|Started
init|=
literal|0x02
block|,
name|Finished
init|=
literal|0x04
block|,
name|Canceled
init|=
literal|0x08
block|,
name|Paused
init|=
literal|0x10
block|,
name|Throttled
init|=
literal|0x20
block|}
enum|;
name|QFutureInterfaceBase
argument_list|(
argument|State initialState = NoState
argument_list|)
empty_stmt|;
name|QFutureInterfaceBase
argument_list|(
specifier|const
name|QFutureInterfaceBase
operator|&
name|other
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QFutureInterfaceBase
argument_list|()
expr_stmt|;
comment|// reporting functions available to the engine author:
name|void
name|reportStarted
parameter_list|()
function_decl|;
name|void
name|reportFinished
parameter_list|()
function_decl|;
name|void
name|reportCanceled
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
name|void
name|reportException
parameter_list|(
specifier|const
name|QException
modifier|&
name|e
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|reportResultsReady
parameter_list|(
name|int
name|beginIndex
parameter_list|,
name|int
name|endIndex
parameter_list|)
function_decl|;
name|void
name|setRunnable
parameter_list|(
name|QRunnable
modifier|*
name|runnable
parameter_list|)
function_decl|;
name|void
name|setThreadPool
parameter_list|(
name|QThreadPool
modifier|*
name|pool
parameter_list|)
function_decl|;
name|void
name|setFilterMode
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|void
name|setProgressRange
parameter_list|(
name|int
name|minimum
parameter_list|,
name|int
name|maximum
parameter_list|)
function_decl|;
name|int
name|progressMinimum
argument_list|()
specifier|const
expr_stmt|;
name|int
name|progressMaximum
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isProgressUpdateNeeded
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setProgressValue
parameter_list|(
name|int
name|progressValue
parameter_list|)
function_decl|;
name|int
name|progressValue
argument_list|()
specifier|const
expr_stmt|;
name|void
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
function_decl|;
name|QString
name|progressText
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setExpectedResultCount
parameter_list|(
name|int
name|resultCount
parameter_list|)
function_decl|;
name|int
name|expectedResultCount
parameter_list|()
function_decl|;
name|int
name|resultCount
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|queryState
argument_list|(
name|State
name|state
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isRunning
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isStarted
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isCanceled
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isFinished
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isPaused
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isThrottled
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isResultReadyAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|void
name|cancel
parameter_list|()
function_decl|;
name|void
name|setPaused
parameter_list|(
name|bool
name|paused
parameter_list|)
function_decl|;
name|void
name|togglePaused
parameter_list|()
function_decl|;
name|void
name|setThrottled
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|void
name|waitForFinished
parameter_list|()
function_decl|;
name|bool
name|waitForNextResult
parameter_list|()
function_decl|;
name|void
name|waitForResult
parameter_list|(
name|int
name|resultIndex
parameter_list|)
function_decl|;
name|void
name|waitForResume
parameter_list|()
function_decl|;
name|QMutex
operator|*
name|mutex
argument_list|()
specifier|const
expr_stmt|;
name|QtPrivate
operator|::
name|ExceptionStore
operator|&
name|exceptionStore
argument_list|()
expr_stmt|;
name|QtPrivate
operator|::
name|ResultStoreBase
operator|&
name|resultStoreBase
argument_list|()
expr_stmt|;
specifier|const
name|QtPrivate
operator|::
name|ResultStoreBase
operator|&
name|resultStoreBase
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QFutureInterfaceBase
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|d
operator|==
name|other
operator|.
name|d
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QFutureInterfaceBase
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|d
operator|!=
name|other
operator|.
name|d
return|;
block|}
name|QFutureInterfaceBase
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFutureInterfaceBase
operator|&
name|other
operator|)
decl_stmt|;
name|protected
label|:
name|bool
name|refT
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|derefT
argument_list|()
specifier|const
expr_stmt|;
name|public
label|:
ifndef|#
directive|ifndef
name|QFUTURE_TEST
name|private
label|:
endif|#
directive|endif
name|QFutureInterfaceBasePrivate
modifier|*
name|d
decl_stmt|;
name|private
label|:
name|friend
name|class
name|QFutureWatcherBase
decl_stmt|;
name|friend
name|class
name|QFutureWatcherBasePrivate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QFutureInterface
operator|:
name|public
name|QFutureInterfaceBase
block|{
name|public
operator|:
name|QFutureInterface
argument_list|(
argument|State initialState = NoState
argument_list|)
operator|:
name|QFutureInterfaceBase
argument_list|(
argument|initialState
argument_list|)
block|{
name|refT
argument_list|()
block|;     }
name|QFutureInterface
argument_list|(
specifier|const
name|QFutureInterface
operator|&
name|other
argument_list|)
operator|:
name|QFutureInterfaceBase
argument_list|(
argument|other
argument_list|)
block|{
name|refT
argument_list|()
block|;     }
operator|~
name|QFutureInterface
argument_list|()
block|{
if|if
condition|(
operator|!
name|derefT
argument_list|()
condition|)
name|resultStore
argument_list|()
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
specifier|static
name|QFutureInterface
name|canceledResult
argument_list|()
block|{
return|return
name|QFutureInterface
argument_list|(
name|State
argument_list|(
name|Started
operator||
name|Finished
operator||
name|Canceled
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|QFutureInterface
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFutureInterface
operator|&
name|other
operator|)
block|{
name|other
operator|.
name|refT
argument_list|()
block|;
if|if
condition|(
operator|!
name|derefT
argument_list|()
condition|)
name|resultStore
argument_list|()
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QFutureInterfaceBase
operator|::
name|operator
operator|=
operator|(
name|other
operator|)
decl_stmt|;
end_decl_stmt
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_expr_stmt
unit|}      inline
name|QFuture
operator|<
name|T
operator|>
name|future
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// implemented in qfuture.h
end_comment
begin_function_decl
specifier|inline
name|void
name|reportResult
parameter_list|(
specifier|const
name|T
modifier|*
name|result
parameter_list|,
name|int
name|index
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|inline
name|void
name|reportResult
parameter_list|(
specifier|const
name|T
modifier|&
name|result
parameter_list|,
name|int
name|index
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|inline
name|void
name|reportResults
argument_list|(
specifier|const
name|QVector
operator|<
name|T
operator|>
operator|&
name|results
argument_list|,
name|int
name|beginIndex
operator|=
operator|-
literal|1
argument_list|,
name|int
name|count
operator|=
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|inline
name|void
name|reportFinished
parameter_list|(
specifier|const
name|T
modifier|*
name|result
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|inline
specifier|const
name|T
modifier|&
name|resultReference
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|inline
specifier|const
name|T
modifier|*
name|resultPointer
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|QList
operator|<
name|T
operator|>
name|results
argument_list|()
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|QtPrivate
operator|::
name|ResultStore
operator|<
name|T
operator|>
operator|&
name|resultStore
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|QtPrivate
operator|::
name|ResultStore
operator|<
name|T
operator|>
operator|&
operator|>
operator|(
name|resultStoreBase
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|const
name|QtPrivate
operator|::
name|ResultStore
operator|<
name|T
operator|>
operator|&
name|resultStore
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|QtPrivate
operator|::
name|ResultStore
operator|<
name|T
operator|>
operator|&
operator|>
operator|(
name|resultStoreBase
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|reportResult
specifier|inline
name|void
name|QFutureInterface
operator|<
name|T
operator|>
operator|::
name|reportResult
argument_list|(
argument|const T *result
argument_list|,
argument|int index
argument_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
name|mutex
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|this
operator|->
name|queryState
argument_list|(
name|Canceled
argument_list|)
operator|||
name|this
operator|->
name|queryState
argument_list|(
name|Finished
argument_list|)
condition|)
block|{
return|return;
block|}
name|QtPrivate
operator|::
name|ResultStore
operator|<
name|T
operator|>
operator|&
name|store
operator|=
name|resultStore
argument_list|()
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|store
operator|.
name|filterMode
argument_list|()
condition|)
block|{
specifier|const
name|int
name|resultCountBefore
init|=
name|store
operator|.
name|count
argument_list|()
decl_stmt|;
name|store
operator|.
name|addResult
argument_list|(
name|index
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|this
operator|->
name|reportResultsReady
argument_list|(
name|resultCountBefore
argument_list|,
name|resultCountBefore
operator|+
name|store
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|int
name|insertIndex
init|=
name|store
operator|.
name|addResult
argument_list|(
name|index
argument_list|,
name|result
argument_list|)
decl_stmt|;
name|this
operator|->
name|reportResultsReady
argument_list|(
name|insertIndex
argument_list|,
name|insertIndex
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_if
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|reportResult
specifier|inline
name|void
name|QFutureInterface
operator|<
name|T
operator|>
operator|::
name|reportResult
argument_list|(
argument|const T&result
argument_list|,
argument|int index
argument_list|)
block|{
name|reportResult
argument_list|(
operator|&
name|result
argument_list|,
name|index
argument_list|)
block|; }
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|QFutureInterface
operator|<
name|T
operator|>
operator|::
name|reportResults
argument_list|(
argument|const QVector<T>&_results
argument_list|,
argument|int beginIndex
argument_list|,
argument|int count
argument_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
name|mutex
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|this
operator|->
name|queryState
argument_list|(
name|Canceled
argument_list|)
operator|||
name|this
operator|->
name|queryState
argument_list|(
name|Finished
argument_list|)
condition|)
block|{
return|return;
block|}
name|QtPrivate
operator|::
name|ResultStore
operator|<
name|T
operator|>
operator|&
name|store
operator|=
name|resultStore
argument_list|()
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|store
operator|.
name|filterMode
argument_list|()
condition|)
block|{
specifier|const
name|int
name|resultCountBefore
init|=
name|store
operator|.
name|count
argument_list|()
decl_stmt|;
name|store
operator|.
name|addResults
argument_list|(
name|beginIndex
argument_list|,
operator|&
name|_results
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|this
operator|->
name|reportResultsReady
argument_list|(
name|resultCountBefore
argument_list|,
name|store
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|int
name|insertIndex
init|=
name|store
operator|.
name|addResults
argument_list|(
name|beginIndex
argument_list|,
operator|&
name|_results
argument_list|,
name|count
argument_list|)
decl_stmt|;
name|this
operator|->
name|reportResultsReady
argument_list|(
name|insertIndex
argument_list|,
name|insertIndex
operator|+
name|_results
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_if
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|reportFinished
specifier|inline
name|void
name|QFutureInterface
operator|<
name|T
operator|>
operator|::
name|reportFinished
argument_list|(
argument|const T *result
argument_list|)
block|{
if|if
condition|(
name|result
condition|)
name|reportResult
argument_list|(
name|result
argument_list|)
expr_stmt|;
name|QFutureInterfaceBase
operator|::
name|reportFinished
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|resultReference
specifier|inline
specifier|const
name|T
operator|&
name|QFutureInterface
operator|<
name|T
operator|>
operator|::
name|resultReference
argument_list|(
argument|int index
argument_list|)
specifier|const
block|{
name|QMutexLocker
name|lock
argument_list|(
name|mutex
argument_list|()
argument_list|)
block|;
return|return
name|resultStore
argument_list|()
operator|.
name|resultAt
argument_list|(
name|index
argument_list|)
operator|.
name|value
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|resultPointer
specifier|inline
specifier|const
name|T
operator|*
name|QFutureInterface
operator|<
name|T
operator|>
operator|::
name|resultPointer
argument_list|(
argument|int index
argument_list|)
specifier|const
block|{
name|QMutexLocker
name|lock
argument_list|(
name|mutex
argument_list|()
argument_list|)
block|;
return|return
name|resultStore
argument_list|()
operator|.
name|resultAt
argument_list|(
name|index
argument_list|)
operator|.
name|pointer
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|results
specifier|inline
name|QList
operator|<
name|T
operator|>
name|QFutureInterface
operator|<
name|T
operator|>
operator|::
name|results
argument_list|()
block|{
if|if
condition|(
name|this
operator|->
name|isCanceled
argument_list|()
condition|)
block|{
name|exceptionStore
argument_list|()
operator|.
name|throwPossibleException
argument_list|()
expr_stmt|;
return|return
name|QList
operator|<
name|T
operator|>
operator|(
operator|)
return|;
block|}
name|QFutureInterfaceBase
operator|::
name|waitForResult
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|T
operator|>
name|res
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QMutexLocker
name|lock
argument_list|(
name|mutex
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QtPrivate
operator|::
name|ResultIterator
operator|<
name|T
operator|>
name|it
operator|=
name|resultStore
argument_list|()
operator|.
name|begin
argument_list|()
expr_stmt|;
end_expr_stmt
begin_while
while|while
condition|(
name|it
operator|!=
name|resultStore
argument_list|()
operator|.
name|end
argument_list|()
condition|)
block|{
name|res
operator|.
name|append
argument_list|(
name|it
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
operator|++
name|it
expr_stmt|;
block|}
end_while
begin_return
return|return
name|res
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
operator|>
name|class
name|QFutureInterface
operator|<
name|void
operator|>
operator|:
name|public
name|QFutureInterfaceBase
block|{
name|public
operator|:
name|QFutureInterface
operator|<
name|void
operator|>
operator|(
name|State
name|initialState
operator|=
name|NoState
operator|)
operator|:
name|QFutureInterfaceBase
argument_list|(
argument|initialState
argument_list|)
block|{ }
name|QFutureInterface
operator|<
name|void
operator|>
operator|(
specifier|const
name|QFutureInterface
operator|<
name|void
operator|>
operator|&
name|other
operator|)
operator|:
name|QFutureInterfaceBase
argument_list|(
argument|other
argument_list|)
block|{ }
specifier|static
name|QFutureInterface
operator|<
name|void
operator|>
name|canceledResult
argument_list|()
block|{
return|return
name|QFutureInterface
argument_list|(
name|State
argument_list|(
name|Started
operator||
name|Finished
operator||
name|Canceled
argument_list|)
argument_list|)
return|;
block|}
name|QFutureInterface
operator|<
name|void
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QFutureInterface
operator|<
name|void
operator|>
operator|&
name|other
operator|)
block|{
name|QFutureInterfaceBase
operator|::
name|operator
operator|=
operator|(
name|other
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFuture
operator|<
name|void
operator|>
name|future
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// implemented in qfuture.h
end_comment
begin_function
name|void
name|reportResult
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
block|{ }
end_function
begin_decl_stmt
name|void
name|reportResults
argument_list|(
specifier|const
name|QVector
operator|<
name|void
operator|>
operator|&
argument_list|,
name|int
argument_list|)
block|{ }
end_decl_stmt
begin_function
name|void
name|reportFinished
parameter_list|(
specifier|const
name|void
modifier|*
init|=
name|Q_NULLPTR
parameter_list|)
block|{
name|QFutureInterfaceBase
operator|::
name|reportFinished
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QFUTURE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFUTUREINTERFACE_H
end_comment
end_unit
