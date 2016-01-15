begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_struct
DECL|struct|TestIterator
struct|struct
name|TestIterator
block|{
DECL|function|TestIterator
name|TestIterator
parameter_list|(
name|int
name|i
parameter_list|)
member_init_list|:
name|i
argument_list|(
name|i
argument_list|)
block|{ }
DECL|function|operator -
name|int
name|operator
name|-
parameter_list|(
specifier|const
name|TestIterator
modifier|&
name|other
parameter_list|)
block|{
return|return
name|i
operator|-
name|other
operator|.
name|i
return|;
block|}
DECL|function|operator ++
name|TestIterator
modifier|&
name|operator
name|++
parameter_list|()
block|{
operator|++
name|i
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator !=
name|bool
name|operator
name|!=
parameter_list|(
specifier|const
name|TestIterator
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|i
operator|!=
name|other
operator|.
name|i
return|;
block|}
DECL|member|i
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct
begin_include
include|#
directive|include
file|<qiterator.h>
end_include
begin_namespace
DECL|namespace|std
namespace|namespace
name|std
block|{
template|template
parameter_list|<>
struct|struct
DECL|struct|iterator_traits
name|iterator_traits
argument_list|<
name|TestIterator
argument_list|>
block|{
DECL|typedef|iterator_category
typedef|typedef
name|random_access_iterator_tag
name|iterator_category
typedef|;
block|}
struct|;
DECL|function|distance
name|int
name|distance
parameter_list|(
name|TestIterator
modifier|&
name|a
parameter_list|,
name|TestIterator
modifier|&
name|b
parameter_list|)
block|{
return|return
name|b
operator|-
name|a
return|;
block|}
block|}
end_namespace
begin_include
include|#
directive|include
file|<qtconcurrentiteratekernel.h>
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
DECL|class|tst_QtConcurrentIterateKernel
class|class
name|tst_QtConcurrentIterateKernel
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
comment|// "for" iteration tests:
name|void
name|instantiate
parameter_list|()
function_decl|;
name|void
name|cancel
parameter_list|()
function_decl|;
name|void
name|stresstest
parameter_list|()
function_decl|;
name|void
name|noIterations
parameter_list|()
function_decl|;
name|void
name|throttling
parameter_list|()
function_decl|;
name|void
name|blockSize
parameter_list|()
function_decl|;
name|void
name|multipleResults
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|iterations
name|QAtomicInt
name|iterations
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|PrintFor
class|class
name|PrintFor
super|:
specifier|public
name|IterateKernel
argument_list|<
name|TestIterator
argument_list|,
name|void
argument_list|>
block|{
public|public:
DECL|function|PrintFor
name|PrintFor
parameter_list|(
name|TestIterator
name|begin
parameter_list|,
name|TestIterator
name|end
parameter_list|)
member_init_list|:
name|IterateKernel
argument_list|<
name|TestIterator
argument_list|,
name|void
argument_list|>
argument_list|(
name|begin
argument_list|,
name|end
argument_list|)
block|{
name|iterations
operator|.
name|store
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
DECL|function|runIterations
name|bool
name|runIterations
parameter_list|(
name|TestIterator
comment|/*beginIterator*/
parameter_list|,
name|int
name|begin
parameter_list|,
name|int
name|end
parameter_list|,
name|void
modifier|*
parameter_list|)
block|{
name|iterations
operator|.
name|fetchAndAddRelaxed
argument_list|(
name|end
operator|-
name|begin
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|PRINT
name|qDebug
argument_list|()
operator|<<
name|QThread
operator|::
name|currentThread
argument_list|()
operator|<<
literal|"iteration"
operator|<<
name|begin
operator|<<
literal|"to"
operator|<<
name|end
operator|<<
literal|"(exclusive)"
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
DECL|function|runIteration
name|bool
name|runIteration
parameter_list|(
name|TestIterator
name|it
parameter_list|,
name|int
name|index
parameter_list|,
name|void
modifier|*
name|result
parameter_list|)
block|{
return|return
name|runIterations
argument_list|(
name|it
argument_list|,
name|index
argument_list|,
name|index
operator|+
literal|1
argument_list|,
name|result
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|SleepPrintFor
class|class
name|SleepPrintFor
super|:
specifier|public
name|IterateKernel
argument_list|<
name|TestIterator
argument_list|,
name|void
argument_list|>
block|{
public|public:
DECL|function|SleepPrintFor
name|SleepPrintFor
parameter_list|(
name|TestIterator
name|begin
parameter_list|,
name|TestIterator
name|end
parameter_list|)
member_init_list|:
name|IterateKernel
argument_list|<
name|TestIterator
argument_list|,
name|void
argument_list|>
argument_list|(
name|begin
argument_list|,
name|end
argument_list|)
block|{
name|iterations
operator|.
name|store
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
DECL|function|runIterations
specifier|inline
name|bool
name|runIterations
parameter_list|(
name|TestIterator
comment|/*beginIterator*/
parameter_list|,
name|int
name|begin
parameter_list|,
name|int
name|end
parameter_list|,
name|void
modifier|*
parameter_list|)
block|{
name|QTest
operator|::
name|qSleep
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|iterations
operator|.
name|fetchAndAddRelaxed
argument_list|(
name|end
operator|-
name|begin
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|PRINT
name|qDebug
argument_list|()
operator|<<
name|QThread
operator|::
name|currentThread
argument_list|()
operator|<<
literal|"iteration"
operator|<<
name|begin
operator|<<
literal|"to"
operator|<<
name|end
operator|<<
literal|"(exclusive)"
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
DECL|function|runIteration
name|bool
name|runIteration
parameter_list|(
name|TestIterator
name|it
parameter_list|,
name|int
name|index
parameter_list|,
name|void
modifier|*
name|result
parameter_list|)
block|{
return|return
name|runIterations
argument_list|(
name|it
argument_list|,
name|index
argument_list|,
name|index
operator|+
literal|1
argument_list|,
name|result
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|instantiate
name|void
name|tst_QtConcurrentIterateKernel
operator|::
name|instantiate
parameter_list|()
block|{
name|startThreadEngine
argument_list|(
operator|new
name|PrintFor
argument_list|(
literal|0
argument_list|,
literal|40
argument_list|)
argument_list|)
operator|.
name|startBlocking
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|iterations
operator|.
name|load
argument_list|()
argument_list|,
literal|40
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cancel
name|void
name|tst_QtConcurrentIterateKernel
operator|::
name|cancel
parameter_list|()
block|{
block|{
name|QFuture
argument_list|<
name|void
argument_list|>
name|f
init|=
name|startThreadEngine
argument_list|(
operator|new
name|SleepPrintFor
argument_list|(
literal|0
argument_list|,
literal|40
argument_list|)
argument_list|)
operator|.
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
name|QVERIFY
argument_list|(
name|f
operator|.
name|isCanceled
argument_list|()
argument_list|)
expr_stmt|;
comment|// the threads might run one iteration each before they are canceled.
name|QVERIFY2
argument_list|(
name|iterations
operator|.
name|load
argument_list|()
operator|<=
name|QThread
operator|::
name|idealThreadCount
argument_list|()
argument_list|,
operator|(
name|QByteArray
operator|::
name|number
argument_list|(
name|iterations
operator|.
name|load
argument_list|()
argument_list|)
operator|+
literal|' '
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|QThread
operator|::
name|idealThreadCount
argument_list|()
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|counter
name|QAtomicInt
name|counter
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|CountFor
class|class
name|CountFor
super|:
specifier|public
name|IterateKernel
argument_list|<
name|TestIterator
argument_list|,
name|void
argument_list|>
block|{
public|public:
DECL|function|CountFor
name|CountFor
parameter_list|(
name|TestIterator
name|begin
parameter_list|,
name|TestIterator
name|end
parameter_list|)
member_init_list|:
name|IterateKernel
argument_list|<
name|TestIterator
argument_list|,
name|void
argument_list|>
argument_list|(
name|begin
argument_list|,
name|end
argument_list|)
block|{
name|iterations
operator|.
name|store
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
DECL|function|runIterations
specifier|inline
name|bool
name|runIterations
parameter_list|(
name|TestIterator
comment|/*beginIterator*/
parameter_list|,
name|int
name|begin
parameter_list|,
name|int
name|end
parameter_list|,
name|void
modifier|*
parameter_list|)
block|{
name|counter
operator|.
name|fetchAndAddRelaxed
argument_list|(
name|end
operator|-
name|begin
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
DECL|function|runIteration
name|bool
name|runIteration
parameter_list|(
name|TestIterator
name|it
parameter_list|,
name|int
name|index
parameter_list|,
name|void
modifier|*
name|result
parameter_list|)
block|{
return|return
name|runIterations
argument_list|(
name|it
argument_list|,
name|index
argument_list|,
name|index
operator|+
literal|1
argument_list|,
name|result
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|stresstest
name|void
name|tst_QtConcurrentIterateKernel
operator|::
name|stresstest
parameter_list|()
block|{
specifier|const
name|int
name|iterations
init|=
literal|1000
decl_stmt|;
specifier|const
name|int
name|times
init|=
literal|50
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
name|counter
operator|.
name|store
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|CountFor
name|f
argument_list|(
literal|0
argument_list|,
name|iterations
argument_list|)
decl_stmt|;
name|f
operator|.
name|startBlocking
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|counter
operator|.
name|load
argument_list|()
argument_list|,
name|iterations
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|noIterations
name|void
name|tst_QtConcurrentIterateKernel
operator|::
name|noIterations
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
name|startThreadEngine
argument_list|(
operator|new
name|IterateKernel
argument_list|<
name|TestIterator
argument_list|,
name|void
argument_list|>
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|.
name|startBlocking
argument_list|()
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|threadsMutex
name|QMutex
name|threadsMutex
decl_stmt|;
end_decl_stmt
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
begin_class
DECL|class|ThrottleFor
class|class
name|ThrottleFor
super|:
specifier|public
name|IterateKernel
argument_list|<
name|TestIterator
argument_list|,
name|void
argument_list|>
block|{
public|public:
comment|// this class throttles between iterations 100 and 200,
comment|// and then records how many threads that run between
comment|// iterations 140 and 160.
DECL|function|ThrottleFor
name|ThrottleFor
parameter_list|(
name|TestIterator
name|begin
parameter_list|,
name|TestIterator
name|end
parameter_list|)
member_init_list|:
name|IterateKernel
argument_list|<
name|TestIterator
argument_list|,
name|void
argument_list|>
argument_list|(
name|begin
argument_list|,
name|end
argument_list|)
block|{
name|iterations
operator|.
name|store
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|throttling
operator|=
literal|false
expr_stmt|;
block|}
DECL|function|runIterations
specifier|inline
name|bool
name|runIterations
parameter_list|(
name|TestIterator
comment|/*beginIterator*/
parameter_list|,
name|int
name|begin
parameter_list|,
name|int
name|end
parameter_list|,
name|void
modifier|*
parameter_list|)
block|{
if|if
condition|(
literal|200
operator|>=
name|begin
operator|&&
literal|200
operator|<
name|end
condition|)
block|{
name|throttling
operator|=
literal|false
expr_stmt|;
block|}
name|iterations
operator|.
name|fetchAndAddRelaxed
argument_list|(
name|end
operator|-
name|begin
argument_list|)
expr_stmt|;
name|QThread
modifier|*
name|thread
init|=
name|QThread
operator|::
name|currentThread
argument_list|()
decl_stmt|;
if|if
condition|(
name|begin
operator|>
literal|140
operator|&&
name|end
operator|<
literal|160
condition|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|threadsMutex
argument_list|)
decl_stmt|;
name|threads
operator|.
name|insert
argument_list|(
name|thread
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
literal|100
operator|>=
name|begin
operator|&&
literal|100
operator|<
name|end
condition|)
block|{
name|throttling
operator|=
literal|true
expr_stmt|;
block|}
name|QTest
operator|::
name|qWait
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
DECL|function|runIteration
name|bool
name|runIteration
parameter_list|(
name|TestIterator
name|it
parameter_list|,
name|int
name|index
parameter_list|,
name|void
modifier|*
name|result
parameter_list|)
block|{
return|return
name|runIterations
argument_list|(
name|it
argument_list|,
name|index
argument_list|,
name|index
operator|+
literal|1
argument_list|,
name|result
argument_list|)
return|;
block|}
DECL|function|shouldThrottleThread
name|bool
name|shouldThrottleThread
parameter_list|()
block|{
specifier|const
name|int
name|load
init|=
name|iterations
operator|.
name|load
argument_list|()
decl_stmt|;
return|return
operator|(
name|load
operator|>
literal|100
operator|&&
name|load
operator|<
literal|200
operator|)
return|;
block|}
DECL|member|throttling
name|bool
name|throttling
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|throttling
name|void
name|tst_QtConcurrentIterateKernel
operator|::
name|throttling
parameter_list|()
block|{
specifier|const
name|int
name|totalIterations
init|=
literal|400
decl_stmt|;
name|iterations
operator|.
name|store
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|threads
operator|.
name|clear
argument_list|()
expr_stmt|;
name|ThrottleFor
name|f
argument_list|(
literal|0
argument_list|,
name|totalIterations
argument_list|)
decl_stmt|;
name|f
operator|.
name|startBlocking
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|iterations
operator|.
name|load
argument_list|()
argument_list|,
name|totalIterations
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|threads
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|BlockSizeRecorder
class|class
name|BlockSizeRecorder
super|:
specifier|public
name|IterateKernel
argument_list|<
name|TestIterator
argument_list|,
name|void
argument_list|>
block|{
public|public:
DECL|function|BlockSizeRecorder
name|BlockSizeRecorder
parameter_list|(
name|TestIterator
name|begin
parameter_list|,
name|TestIterator
name|end
parameter_list|)
member_init_list|:
name|IterateKernel
argument_list|<
name|TestIterator
argument_list|,
name|void
argument_list|>
argument_list|(
name|begin
argument_list|,
name|end
argument_list|)
member_init_list|,
name|peakBlockSize
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|peakBegin
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|runIterations
specifier|inline
name|bool
name|runIterations
parameter_list|(
name|TestIterator
parameter_list|,
name|int
name|begin
parameter_list|,
name|int
name|end
parameter_list|,
name|void
modifier|*
parameter_list|)
block|{
specifier|const
name|int
name|blockSize
init|=
name|end
operator|-
name|begin
decl_stmt|;
if|if
condition|(
name|blockSize
operator|>
name|peakBlockSize
condition|)
block|{
name|peakBlockSize
operator|=
name|blockSize
expr_stmt|;
name|peakBegin
operator|=
name|begin
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
DECL|member|peakBlockSize
name|int
name|peakBlockSize
decl_stmt|;
DECL|member|peakBegin
name|int
name|peakBegin
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|msgBlockSize
specifier|static
name|QByteArray
name|msgBlockSize
parameter_list|(
specifier|const
name|BlockSizeRecorder
modifier|&
name|recorder
parameter_list|,
name|int
name|expectedMinimumBlockSize
parameter_list|)
block|{
return|return
name|QByteArrayLiteral
argument_list|(
literal|"peakBlockSize="
argument_list|)
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|recorder
operator|.
name|peakBlockSize
argument_list|)
operator|+
name|QByteArrayLiteral
argument_list|(
literal|" is less than expectedMinimumBlockSize="
argument_list|)
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|expectedMinimumBlockSize
argument_list|)
operator|+
name|QByteArrayLiteral
argument_list|(
literal|", reached at: "
argument_list|)
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|recorder
operator|.
name|peakBegin
argument_list|)
operator|+
name|QByteArrayLiteral
argument_list|(
literal|" (ideal thread count: "
argument_list|)
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|QThread
operator|::
name|idealThreadCount
argument_list|()
argument_list|)
operator|+
literal|')'
return|;
block|}
end_function
begin_function
DECL|function|blockSize
name|void
name|tst_QtConcurrentIterateKernel
operator|::
name|blockSize
parameter_list|()
block|{
specifier|const
name|int
name|expectedMinimumBlockSize
init|=
literal|1024
operator|/
name|QThread
operator|::
name|idealThreadCount
argument_list|()
decl_stmt|;
name|BlockSizeRecorder
name|recorder
argument_list|(
literal|0
argument_list|,
literal|10000
argument_list|)
decl_stmt|;
name|recorder
operator|.
name|startBlocking
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|recorder
operator|.
name|peakBlockSize
operator|<
name|expectedMinimumBlockSize
condition|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
name|msgBlockSize
argument_list|(
name|recorder
argument_list|,
name|expectedMinimumBlockSize
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Q_OS_WIN
name|QVERIFY2
argument_list|(
name|recorder
operator|.
name|peakBlockSize
operator|>=
name|expectedMinimumBlockSize
argument_list|,
name|msgBlockSize
argument_list|(
name|recorder
argument_list|,
name|expectedMinimumBlockSize
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|MultipleResultsFor
class|class
name|MultipleResultsFor
super|:
specifier|public
name|IterateKernel
argument_list|<
name|TestIterator
argument_list|,
name|int
argument_list|>
block|{
public|public:
DECL|function|MultipleResultsFor
name|MultipleResultsFor
parameter_list|(
name|TestIterator
name|begin
parameter_list|,
name|TestIterator
name|end
parameter_list|)
member_init_list|:
name|IterateKernel
argument_list|<
name|TestIterator
argument_list|,
name|int
argument_list|>
argument_list|(
name|begin
argument_list|,
name|end
argument_list|)
block|{ }
DECL|function|runIterations
specifier|inline
name|bool
name|runIterations
parameter_list|(
name|TestIterator
parameter_list|,
name|int
name|begin
parameter_list|,
name|int
name|end
parameter_list|,
name|int
modifier|*
name|results
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
name|begin
init|;
name|i
operator|<
name|end
condition|;
operator|++
name|i
control|)
name|results
index|[
name|i
operator|-
name|begin
index|]
operator|=
name|i
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|multipleResults
name|void
name|tst_QtConcurrentIterateKernel
operator|::
name|multipleResults
parameter_list|()
block|{
name|QFuture
argument_list|<
name|int
argument_list|>
name|f
init|=
name|startThreadEngine
argument_list|(
operator|new
name|MultipleResultsFor
argument_list|(
literal|0
argument_list|,
literal|10
argument_list|)
argument_list|)
operator|.
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
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QtConcurrentIterateKernel
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtconcurrentiteratekernel.moc"
end_include
end_unit
