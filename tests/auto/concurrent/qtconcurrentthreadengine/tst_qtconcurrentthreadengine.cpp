begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtconcurrentthreadengine.h>
end_include
begin_include
include|#
directive|include
file|<qexception.h>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_using
using|using
namespace|namespace
name|QtConcurrent
namespace|;
end_using
begin_class
DECL|class|tst_QtConcurrentThreadEngine
class|class
name|tst_QtConcurrentThreadEngine
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|runDirectly
parameter_list|()
function_decl|;
name|void
name|result
parameter_list|()
function_decl|;
name|void
name|runThroughStarter
parameter_list|()
function_decl|;
name|void
name|cancel
parameter_list|()
function_decl|;
name|void
name|throttle
parameter_list|()
function_decl|;
name|void
name|threadCount
parameter_list|()
function_decl|;
name|void
name|multipleResults
parameter_list|()
function_decl|;
name|void
name|stresstest
parameter_list|()
function_decl|;
name|void
name|cancelQueuedSlowUser
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
name|void
name|exceptions
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_class
DECL|class|PrintUser
class|class
name|PrintUser
super|:
specifier|public
name|ThreadEngine
argument_list|<
name|void
argument_list|>
block|{
public|public:
DECL|function|threadFunction
name|ThreadFunctionResult
name|threadFunction
parameter_list|()
block|{
name|QTest
operator|::
name|qSleep
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qSleep
argument_list|(
literal|100
argument_list|)
expr_stmt|;
return|return
name|ThreadFinished
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|runDirectly
name|void
name|tst_QtConcurrentThreadEngine
operator|::
name|runDirectly
parameter_list|()
block|{
block|{
name|PrintUser
name|engine
decl_stmt|;
name|engine
operator|.
name|startSingleThreaded
argument_list|()
expr_stmt|;
name|engine
operator|.
name|startBlocking
argument_list|()
expr_stmt|;
block|}
block|{
name|PrintUser
modifier|*
name|engine
init|=
operator|new
name|PrintUser
argument_list|()
decl_stmt|;
name|QFuture
argument_list|<
name|void
argument_list|>
name|f
init|=
name|engine
operator|->
name|startAsynchronously
argument_list|()
decl_stmt|;
name|f
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_class
DECL|class|StringResultUser
class|class
name|StringResultUser
super|:
specifier|public
name|ThreadEngine
argument_list|<
name|QString
argument_list|>
block|{
public|public:
DECL|typedef|ResultType
typedef|typedef
name|QString
name|ResultType
typedef|;
DECL|function|StringResultUser
name|StringResultUser
parameter_list|()
member_init_list|:
name|done
argument_list|(
literal|false
argument_list|)
block|{ }
DECL|function|shouldStartThread
name|bool
name|shouldStartThread
parameter_list|()
block|{
return|return
operator|!
name|done
return|;
block|}
DECL|function|threadFunction
name|ThreadFunctionResult
name|threadFunction
parameter_list|()
block|{
name|done
operator|=
literal|true
expr_stmt|;
return|return
name|ThreadFinished
return|;
block|}
DECL|function|result
name|QString
modifier|*
name|result
parameter_list|()
block|{
name|foo
operator|=
literal|"Foo"
expr_stmt|;
return|return
operator|&
name|foo
return|;
block|}
DECL|member|foo
name|QString
name|foo
decl_stmt|;
DECL|member|done
name|bool
name|done
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|result
name|void
name|tst_QtConcurrentThreadEngine
operator|::
name|result
parameter_list|()
block|{
name|StringResultUser
name|engine
decl_stmt|;
name|QCOMPARE
argument_list|(
operator|*
name|engine
operator|.
name|startBlocking
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Foo"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|VoidResultUser
class|class
name|VoidResultUser
super|:
specifier|public
name|ThreadEngine
argument_list|<
name|void
argument_list|>
block|{
public|public:
DECL|function|shouldStartThread
name|bool
name|shouldStartThread
parameter_list|()
block|{
return|return
operator|!
name|done
return|;
block|}
DECL|function|threadFunction
name|ThreadFunctionResult
name|threadFunction
parameter_list|()
block|{
name|done
operator|=
literal|true
expr_stmt|;
return|return
name|ThreadFinished
return|;
block|}
DECL|function|result
name|void
modifier|*
name|result
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
DECL|member|done
name|bool
name|done
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|runThroughStarter
name|void
name|tst_QtConcurrentThreadEngine
operator|::
name|runThroughStarter
parameter_list|()
block|{
block|{
name|ThreadEngineStarter
argument_list|<
name|QString
argument_list|>
name|starter
init|=
name|startThreadEngine
argument_list|(
operator|new
name|StringResultUser
argument_list|()
argument_list|)
decl_stmt|;
name|QFuture
argument_list|<
name|QString
argument_list|>
name|f
init|=
name|starter
operator|.
name|startAsynchronously
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Foo"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|ThreadEngineStarter
argument_list|<
name|QString
argument_list|>
name|starter
init|=
name|startThreadEngine
argument_list|(
operator|new
name|StringResultUser
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|str
init|=
name|starter
operator|.
name|startBlocking
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"Foo"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_class
DECL|class|CancelUser
class|class
name|CancelUser
super|:
specifier|public
name|ThreadEngine
argument_list|<
name|void
argument_list|>
block|{
public|public:
DECL|function|result
name|void
modifier|*
name|result
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
DECL|function|threadFunction
name|ThreadFunctionResult
name|threadFunction
parameter_list|()
block|{
while|while
condition|(
name|this
operator|->
name|isCanceled
argument_list|()
operator|==
literal|false
condition|)
block|{
name|QTest
operator|::
name|qSleep
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
return|return
name|ThreadFinished
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|cancel
name|void
name|tst_QtConcurrentThreadEngine
operator|::
name|cancel
parameter_list|()
block|{
block|{
name|CancelUser
modifier|*
name|engine
init|=
operator|new
name|CancelUser
argument_list|()
decl_stmt|;
name|QFuture
argument_list|<
name|void
argument_list|>
name|f
init|=
name|engine
operator|->
name|startAsynchronously
argument_list|()
decl_stmt|;
name|f
operator|.
name|cancel
argument_list|()
expr_stmt|;
name|f
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
block|{
name|CancelUser
modifier|*
name|engine
init|=
operator|new
name|CancelUser
argument_list|()
decl_stmt|;
name|QFuture
argument_list|<
name|void
argument_list|>
name|f
init|=
name|engine
operator|->
name|startAsynchronously
argument_list|()
decl_stmt|;
name|QTest
operator|::
name|qSleep
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|f
operator|.
name|cancel
argument_list|()
expr_stmt|;
name|f
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|count
name|QAtomicInt
name|count
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|ThrottleAlwaysUser
class|class
name|ThrottleAlwaysUser
super|:
specifier|public
name|ThreadEngine
argument_list|<
name|void
argument_list|>
block|{
public|public:
DECL|function|ThrottleAlwaysUser
name|ThrottleAlwaysUser
parameter_list|()
block|{
name|count
operator|.
name|store
argument_list|(
name|initialCount
operator|=
literal|100
argument_list|)
expr_stmt|;
name|finishing
operator|=
literal|false
expr_stmt|;
block|}
DECL|function|shouldStartThread
name|bool
name|shouldStartThread
parameter_list|()
block|{
return|return
operator|!
name|finishing
return|;
block|}
DECL|function|threadFunction
name|ThreadFunctionResult
name|threadFunction
parameter_list|()
block|{
forever|forever
block|{
specifier|const
name|int
name|local
init|=
name|count
operator|.
name|load
argument_list|()
decl_stmt|;
if|if
condition|(
name|local
operator|==
literal|0
condition|)
block|{
name|finishing
operator|=
literal|true
expr_stmt|;
return|return
name|ThreadFinished
return|;
block|}
if|if
condition|(
name|count
operator|.
name|testAndSetOrdered
argument_list|(
name|local
argument_list|,
name|local
operator|-
literal|1
argument_list|)
condition|)
break|break;
block|}
return|return
name|ThrottleThread
return|;
block|}
DECL|member|finishing
name|bool
name|finishing
decl_stmt|;
DECL|member|initialCount
name|int
name|initialCount
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|// Test that a user task with a thread function that always
end_comment
begin_comment
comment|// want to be throttled still completes. The thread engine
end_comment
begin_comment
comment|// should make keep one thread running at all times.
end_comment
begin_function
DECL|function|throttle
name|void
name|tst_QtConcurrentThreadEngine
operator|::
name|throttle
parameter_list|()
block|{
specifier|const
name|int
name|repeats
init|=
literal|10
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|repeats
condition|;
operator|++
name|i
control|)
block|{
name|QFuture
argument_list|<
name|void
argument_list|>
name|f
init|=
operator|(
operator|new
name|ThrottleAlwaysUser
argument_list|()
operator|)
operator|->
name|startAsynchronously
argument_list|()
decl_stmt|;
name|f
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|count
operator|.
name|load
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|repeats
condition|;
operator|++
name|i
control|)
block|{
name|ThrottleAlwaysUser
name|t
decl_stmt|;
name|t
operator|.
name|startBlocking
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|count
operator|.
name|load
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|threads
name|QSet
argument_list|<
name|QThread
modifier|*
argument_list|>
name|threads
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|mutex
name|QMutex
name|mutex
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|ThreadCountUser
class|class
name|ThreadCountUser
super|:
specifier|public
name|ThreadEngine
argument_list|<
name|void
argument_list|>
block|{
public|public:
DECL|function|ThreadCountUser
name|ThreadCountUser
parameter_list|(
name|bool
name|finishImmediately
init|=
literal|false
parameter_list|)
block|{
name|threads
operator|.
name|clear
argument_list|()
expr_stmt|;
name|finishing
operator|=
name|finishImmediately
expr_stmt|;
block|}
DECL|function|shouldStartThread
name|bool
name|shouldStartThread
parameter_list|()
block|{
return|return
operator|!
name|finishing
return|;
block|}
DECL|function|threadFunction
name|ThreadFunctionResult
name|threadFunction
parameter_list|()
block|{
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|threads
operator|.
name|insert
argument_list|(
name|QThread
operator|::
name|currentThread
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QTest
operator|::
name|qSleep
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|finishing
operator|=
literal|true
expr_stmt|;
return|return
name|ThreadFinished
return|;
block|}
DECL|member|finishing
name|bool
name|finishing
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|threadCount
name|void
name|tst_QtConcurrentThreadEngine
operator|::
name|threadCount
parameter_list|()
block|{
comment|//QTBUG-23333: This test is unstable
specifier|const
name|int
name|repeats
init|=
literal|10
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|repeats
condition|;
operator|++
name|i
control|)
block|{
name|ThreadCountUser
name|t
decl_stmt|;
name|t
operator|.
name|startBlocking
argument_list|()
expr_stmt|;
name|int
name|count
init|=
name|threads
operator|.
name|count
argument_list|()
decl_stmt|;
name|int
name|count_expected
init|=
name|QThreadPool
operator|::
name|globalInstance
argument_list|()
operator|->
name|maxThreadCount
argument_list|()
operator|+
literal|1
decl_stmt|;
comment|// +1 for the main thread.
if|if
condition|(
name|count
operator|!=
name|count_expected
condition|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"QTBUG-23333"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|count
argument_list|,
name|count_expected
argument_list|)
expr_stmt|;
operator|(
operator|new
name|ThreadCountUser
argument_list|()
operator|)
operator|->
name|startAsynchronously
argument_list|()
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|count
operator|=
name|threads
operator|.
name|count
argument_list|()
expr_stmt|;
name|count_expected
operator|=
name|QThreadPool
operator|::
name|globalInstance
argument_list|()
operator|->
name|maxThreadCount
argument_list|()
expr_stmt|;
if|if
condition|(
name|count
operator|!=
name|count_expected
condition|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"QTBUG-23333"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|count
argument_list|,
name|count_expected
argument_list|)
expr_stmt|;
block|}
comment|// Set the finish flag immediately, this should give us one thread only.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|repeats
condition|;
operator|++
name|i
control|)
block|{
name|ThreadCountUser
name|t
argument_list|(
literal|true
comment|/*finishImmediately*/
argument_list|)
decl_stmt|;
name|t
operator|.
name|startBlocking
argument_list|()
expr_stmt|;
name|int
name|count
init|=
name|threads
operator|.
name|count
argument_list|()
decl_stmt|;
if|if
condition|(
name|count
operator|!=
literal|1
condition|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"QTBUG-23333"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|count
argument_list|,
literal|1
argument_list|)
expr_stmt|;
operator|(
operator|new
name|ThreadCountUser
argument_list|(
literal|true
comment|/*finishImmediately*/
argument_list|)
operator|)
operator|->
name|startAsynchronously
argument_list|()
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|count
operator|=
name|threads
operator|.
name|count
argument_list|()
expr_stmt|;
if|if
condition|(
name|count
operator|!=
literal|1
condition|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"QTBUG-23333"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|count
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_class
DECL|class|MultipleResultsUser
class|class
name|MultipleResultsUser
super|:
specifier|public
name|ThreadEngine
argument_list|<
name|int
argument_list|>
block|{
public|public:
DECL|function|shouldStartThread
name|bool
name|shouldStartThread
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
DECL|function|threadFunction
name|ThreadFunctionResult
name|threadFunction
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
operator|++
name|i
control|)
name|this
operator|->
name|reportResult
argument_list|(
operator|&
name|i
argument_list|)
expr_stmt|;
return|return
name|ThreadFinished
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|multipleResults
name|void
name|tst_QtConcurrentThreadEngine
operator|::
name|multipleResults
parameter_list|()
block|{
name|MultipleResultsUser
modifier|*
name|engine
init|=
operator|new
name|MultipleResultsUser
argument_list|()
decl_stmt|;
name|QFuture
argument_list|<
name|int
argument_list|>
name|f
init|=
name|engine
operator|->
name|startAsynchronously
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|results
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|resultAt
argument_list|(
literal|0
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|resultAt
argument_list|(
literal|5
argument_list|)
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|resultAt
argument_list|(
literal|9
argument_list|)
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|f
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
end_function
begin_class
DECL|class|NoThreadsUser
class|class
name|NoThreadsUser
super|:
specifier|public
name|ThreadEngine
argument_list|<
name|void
argument_list|>
block|{
public|public:
DECL|function|shouldStartThread
name|bool
name|shouldStartThread
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
DECL|function|threadFunction
name|ThreadFunctionResult
name|threadFunction
parameter_list|()
block|{
return|return
name|ThreadFinished
return|;
block|}
DECL|function|result
name|void
modifier|*
name|result
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|stresstest
name|void
name|tst_QtConcurrentThreadEngine
operator|::
name|stresstest
parameter_list|()
block|{
specifier|const
name|int
name|times
init|=
literal|20000
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|times
condition|;
operator|++
name|i
control|)
block|{
name|VoidResultUser
modifier|*
name|engine
init|=
operator|new
name|VoidResultUser
argument_list|()
decl_stmt|;
name|engine
operator|->
name|startAsynchronously
argument_list|()
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|times
condition|;
operator|++
name|i
control|)
block|{
name|VoidResultUser
modifier|*
name|engine
init|=
operator|new
name|VoidResultUser
argument_list|()
decl_stmt|;
name|engine
operator|->
name|startAsynchronously
argument_list|()
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|times
condition|;
operator|++
name|i
control|)
block|{
name|VoidResultUser
modifier|*
name|engine
init|=
operator|new
name|VoidResultUser
argument_list|()
decl_stmt|;
name|engine
operator|->
name|startAsynchronously
argument_list|()
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|sleepTime
specifier|const
name|int
name|sleepTime
init|=
literal|20
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|SlowUser
class|class
name|SlowUser
super|:
specifier|public
name|ThreadEngine
argument_list|<
name|void
argument_list|>
block|{
public|public:
DECL|function|shouldStartThread
name|bool
name|shouldStartThread
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
DECL|function|threadFunction
name|ThreadFunctionResult
name|threadFunction
parameter_list|()
block|{
name|QTest
operator|::
name|qSleep
argument_list|(
name|sleepTime
argument_list|)
expr_stmt|;
return|return
name|ThreadFinished
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|cancelQueuedSlowUser
name|void
name|tst_QtConcurrentThreadEngine
operator|::
name|cancelQueuedSlowUser
parameter_list|()
block|{
specifier|const
name|int
name|times
init|=
literal|100
decl_stmt|;
name|QTime
name|t
decl_stmt|;
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
block|{
name|QList
argument_list|<
name|QFuture
argument_list|<
name|void
argument_list|>
argument_list|>
name|futures
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|times
condition|;
operator|++
name|i
control|)
block|{
name|SlowUser
modifier|*
name|engine
init|=
operator|new
name|SlowUser
argument_list|()
decl_stmt|;
name|futures
operator|.
name|append
argument_list|(
name|engine
operator|->
name|startAsynchronously
argument_list|()
argument_list|)
expr_stmt|;
block|}
foreach|foreach
control|(
name|QFuture
argument_list|<
name|void
argument_list|>
name|future
decl|,
name|futures
control|)
name|future
operator|.
name|cancel
argument_list|()
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|t
operator|.
name|elapsed
argument_list|()
operator|<
operator|(
name|sleepTime
operator|*
name|times
operator|)
operator|/
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
end_ifndef
begin_class
DECL|class|QtConcurrentExceptionThrower
class|class
name|QtConcurrentExceptionThrower
super|:
specifier|public
name|ThreadEngine
argument_list|<
name|void
argument_list|>
block|{
public|public:
DECL|function|QtConcurrentExceptionThrower
name|QtConcurrentExceptionThrower
parameter_list|(
name|QThread
modifier|*
name|blockThread
init|=
literal|0
parameter_list|)
block|{
name|this
operator|->
name|blockThread
operator|=
name|blockThread
expr_stmt|;
block|}
DECL|function|threadFunction
name|ThreadFunctionResult
name|threadFunction
parameter_list|()
block|{
name|QTest
operator|::
name|qSleep
argument_list|(
literal|50
argument_list|)
expr_stmt|;
throw|throw
name|QException
argument_list|()
throw|;
return|return
name|ThreadFinished
return|;
block|}
DECL|member|blockThread
name|QThread
modifier|*
name|blockThread
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|UnrelatedExceptionThrower
class|class
name|UnrelatedExceptionThrower
super|:
specifier|public
name|ThreadEngine
argument_list|<
name|void
argument_list|>
block|{
public|public:
DECL|function|UnrelatedExceptionThrower
name|UnrelatedExceptionThrower
parameter_list|(
name|QThread
modifier|*
name|blockThread
init|=
literal|0
parameter_list|)
block|{
name|this
operator|->
name|blockThread
operator|=
name|blockThread
expr_stmt|;
block|}
DECL|function|threadFunction
name|ThreadFunctionResult
name|threadFunction
parameter_list|()
block|{
name|QTest
operator|::
name|qSleep
argument_list|(
literal|50
argument_list|)
expr_stmt|;
throw|throw
name|int
argument_list|()
throw|;
return|return
name|ThreadFinished
return|;
block|}
DECL|member|blockThread
name|QThread
modifier|*
name|blockThread
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|exceptions
name|void
name|tst_QtConcurrentThreadEngine
operator|::
name|exceptions
parameter_list|()
block|{
comment|// Asynchronous mode:
block|{
name|bool
name|caught
init|=
literal|false
decl_stmt|;
try|try
block|{
name|QtConcurrentExceptionThrower
modifier|*
name|e
init|=
operator|new
name|QtConcurrentExceptionThrower
argument_list|()
decl_stmt|;
name|QFuture
argument_list|<
name|void
argument_list|>
name|f
init|=
name|e
operator|->
name|startAsynchronously
argument_list|()
decl_stmt|;
name|f
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
catch|catch
parameter_list|(
specifier|const
name|QException
modifier|&
parameter_list|)
block|{
name|caught
operator|=
literal|true
expr_stmt|;
block|}
name|QVERIFY2
argument_list|(
name|caught
argument_list|,
literal|"did not get exception"
argument_list|)
expr_stmt|;
block|}
comment|// Blocking mode:
comment|// test throwing the exception from a worker thread.
block|{
name|bool
name|caught
init|=
literal|false
decl_stmt|;
try|try
block|{
name|QtConcurrentExceptionThrower
name|e
argument_list|(
name|QThread
operator|::
name|currentThread
argument_list|()
argument_list|)
decl_stmt|;
name|e
operator|.
name|startBlocking
argument_list|()
expr_stmt|;
block|}
catch|catch
parameter_list|(
specifier|const
name|QException
modifier|&
parameter_list|)
block|{
name|caught
operator|=
literal|true
expr_stmt|;
block|}
name|QVERIFY2
argument_list|(
name|caught
argument_list|,
literal|"did not get exception"
argument_list|)
expr_stmt|;
block|}
comment|// test throwing the exception from the main thread (different code path)
block|{
name|bool
name|caught
init|=
literal|false
decl_stmt|;
try|try
block|{
name|QtConcurrentExceptionThrower
name|e
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|e
operator|.
name|startBlocking
argument_list|()
expr_stmt|;
block|}
catch|catch
parameter_list|(
specifier|const
name|QException
modifier|&
parameter_list|)
block|{
name|caught
operator|=
literal|true
expr_stmt|;
block|}
name|QVERIFY2
argument_list|(
name|caught
argument_list|,
literal|"did not get exception"
argument_list|)
expr_stmt|;
block|}
comment|// Asynchronous mode:
block|{
name|bool
name|caught
init|=
literal|false
decl_stmt|;
try|try
block|{
name|UnrelatedExceptionThrower
modifier|*
name|e
init|=
operator|new
name|UnrelatedExceptionThrower
argument_list|()
decl_stmt|;
name|QFuture
argument_list|<
name|void
argument_list|>
name|f
init|=
name|e
operator|->
name|startAsynchronously
argument_list|()
decl_stmt|;
name|f
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
catch|catch
parameter_list|(
specifier|const
name|QUnhandledException
modifier|&
parameter_list|)
block|{
name|caught
operator|=
literal|true
expr_stmt|;
block|}
name|QVERIFY2
argument_list|(
name|caught
argument_list|,
literal|"did not get exception"
argument_list|)
expr_stmt|;
block|}
comment|// Blocking mode:
comment|// test throwing the exception from a worker thread.
block|{
name|bool
name|caught
init|=
literal|false
decl_stmt|;
try|try
block|{
name|UnrelatedExceptionThrower
name|e
argument_list|(
name|QThread
operator|::
name|currentThread
argument_list|()
argument_list|)
decl_stmt|;
name|e
operator|.
name|startBlocking
argument_list|()
expr_stmt|;
block|}
catch|catch
parameter_list|(
specifier|const
name|QUnhandledException
modifier|&
parameter_list|)
block|{
name|caught
operator|=
literal|true
expr_stmt|;
block|}
name|QVERIFY2
argument_list|(
name|caught
argument_list|,
literal|"did not get exception"
argument_list|)
expr_stmt|;
block|}
comment|// test throwing the exception from the main thread (different code path)
block|{
name|bool
name|caught
init|=
literal|false
decl_stmt|;
try|try
block|{
name|UnrelatedExceptionThrower
name|e
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|e
operator|.
name|startBlocking
argument_list|()
expr_stmt|;
block|}
catch|catch
parameter_list|(
specifier|const
name|QUnhandledException
modifier|&
parameter_list|)
block|{
name|caught
operator|=
literal|true
expr_stmt|;
block|}
name|QVERIFY2
argument_list|(
name|caught
argument_list|,
literal|"did not get exception"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QtConcurrentThreadEngine
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtconcurrentthreadengine.moc"
end_include
end_unit
