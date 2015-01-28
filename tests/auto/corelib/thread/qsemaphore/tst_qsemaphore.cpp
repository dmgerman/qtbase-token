begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qthread.h>
end_include
begin_include
include|#
directive|include
file|<qsemaphore.h>
end_include
begin_class
DECL|class|tst_QSemaphore
class|class
name|tst_QSemaphore
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|acquire
parameter_list|()
function_decl|;
name|void
name|tryAcquire
parameter_list|()
function_decl|;
name|void
name|tryAcquireWithTimeout_data
parameter_list|()
function_decl|;
name|void
name|tryAcquireWithTimeout
parameter_list|()
function_decl|;
name|void
name|tryAcquireWithTimeoutStarvation
parameter_list|()
function_decl|;
name|void
name|producerConsumer
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|semaphore
specifier|static
name|QSemaphore
modifier|*
name|semaphore
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|ThreadOne
class|class
name|ThreadOne
super|:
specifier|public
name|QThread
block|{
public|public:
DECL|function|ThreadOne
name|ThreadOne
parameter_list|()
block|{}
protected|protected:
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
literal|100
condition|)
block|{
name|semaphore
operator|->
name|acquire
argument_list|()
expr_stmt|;
name|i
operator|++
expr_stmt|;
name|semaphore
operator|->
name|release
argument_list|()
expr_stmt|;
block|}
block|}
block|}
class|;
end_class
begin_class
DECL|class|ThreadN
class|class
name|ThreadN
super|:
specifier|public
name|QThread
block|{
DECL|member|N
name|int
name|N
decl_stmt|;
public|public:
DECL|function|ThreadN
name|ThreadN
parameter_list|(
name|int
name|n
parameter_list|)
member_init_list|:
name|N
argument_list|(
name|n
argument_list|)
block|{ }
protected|protected:
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
literal|100
condition|)
block|{
name|semaphore
operator|->
name|acquire
argument_list|(
name|N
argument_list|)
expr_stmt|;
name|i
operator|++
expr_stmt|;
name|semaphore
operator|->
name|release
argument_list|(
name|N
argument_list|)
expr_stmt|;
block|}
block|}
block|}
class|;
end_class
begin_function
DECL|function|acquire
name|void
name|tst_QSemaphore
operator|::
name|acquire
parameter_list|()
block|{
block|{
comment|// old incrementOne() test
name|QVERIFY
argument_list|(
operator|!
name|semaphore
argument_list|)
expr_stmt|;
name|semaphore
operator|=
operator|new
name|QSemaphore
expr_stmt|;
comment|// make some "thing" available
name|semaphore
operator|->
name|release
argument_list|()
expr_stmt|;
name|ThreadOne
name|t1
decl_stmt|;
name|ThreadOne
name|t2
decl_stmt|;
name|t1
operator|.
name|start
argument_list|()
expr_stmt|;
name|t2
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|t1
operator|.
name|wait
argument_list|(
literal|4000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t2
operator|.
name|wait
argument_list|(
literal|4000
argument_list|)
argument_list|)
expr_stmt|;
operator|delete
name|semaphore
expr_stmt|;
name|semaphore
operator|=
literal|0
expr_stmt|;
block|}
comment|// old incrementN() test
block|{
name|QVERIFY
argument_list|(
operator|!
name|semaphore
argument_list|)
expr_stmt|;
name|semaphore
operator|=
operator|new
name|QSemaphore
expr_stmt|;
comment|// make 4 "things" available
name|semaphore
operator|->
name|release
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|ThreadN
name|t1
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|ThreadN
name|t2
argument_list|(
literal|3
argument_list|)
decl_stmt|;
name|t1
operator|.
name|start
argument_list|()
expr_stmt|;
name|t2
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|t1
operator|.
name|wait
argument_list|(
literal|4000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t2
operator|.
name|wait
argument_list|(
literal|4000
argument_list|)
argument_list|)
expr_stmt|;
operator|delete
name|semaphore
expr_stmt|;
name|semaphore
operator|=
literal|0
expr_stmt|;
block|}
name|QSemaphore
name|semaphore
decl_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|release
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|release
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|release
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|12
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|release
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|21
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|acquire
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|acquire
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tryAcquire
name|void
name|tst_QSemaphore
operator|::
name|tryAcquire
parameter_list|()
block|{
name|QSemaphore
name|semaphore
decl_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|release
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|release
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|release
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|12
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|12
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|release
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|semaphore
operator|.
name|tryAcquire
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|21
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|semaphore
operator|.
name|tryAcquire
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// should not be able to acquire more
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tryAcquireWithTimeout_data
name|void
name|tst_QSemaphore
operator|::
name|tryAcquireWithTimeout_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"timeout"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1s"
argument_list|)
operator|<<
literal|1000
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10s"
argument_list|)
operator|<<
literal|10000
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tryAcquireWithTimeout
name|void
name|tst_QSemaphore
operator|::
name|tryAcquireWithTimeout
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
comment|// timers are not guaranteed to be accurate down to the last millisecond,
comment|// so we permit the elapsed times to be up to this far from the expected value.
name|int
name|fuzz
init|=
literal|50
decl_stmt|;
name|QSemaphore
name|semaphore
decl_stmt|;
name|QElapsedTimer
name|time
decl_stmt|;
DECL|macro|FUZZYCOMPARE
define|#
directive|define
name|FUZZYCOMPARE
parameter_list|(
name|a
parameter_list|,
name|e
parameter_list|)
define|\
value|do { \         int a1 = a; \         int e1 = e; \         QVERIFY2(qAbs(a1-e1)< fuzz, \             qPrintable(QString("(%1=%2) is more than %3 milliseconds different from (%4=%5)") \                         .arg(#a).arg(a1).arg(fuzz).arg(#e).arg(e1))); \     } while (0)
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|release
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|2
argument_list|,
name|timeout
argument_list|)
argument_list|)
expr_stmt|;
name|FUZZYCOMPARE
argument_list|(
name|time
operator|.
name|elapsed
argument_list|()
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|release
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|3
argument_list|,
name|timeout
argument_list|)
argument_list|)
expr_stmt|;
name|FUZZYCOMPARE
argument_list|(
name|time
operator|.
name|elapsed
argument_list|()
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|release
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|12
argument_list|)
expr_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|100
argument_list|,
name|timeout
argument_list|)
argument_list|)
expr_stmt|;
name|FUZZYCOMPARE
argument_list|(
name|time
operator|.
name|elapsed
argument_list|()
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|12
argument_list|)
expr_stmt|;
name|semaphore
operator|.
name|release
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|100
argument_list|,
name|timeout
argument_list|)
argument_list|)
expr_stmt|;
name|FUZZYCOMPARE
argument_list|(
name|time
operator|.
name|elapsed
argument_list|()
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|1
argument_list|,
name|timeout
argument_list|)
argument_list|)
expr_stmt|;
name|FUZZYCOMPARE
argument_list|(
name|time
operator|.
name|elapsed
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|21
argument_list|)
expr_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|1
argument_list|,
name|timeout
argument_list|)
argument_list|)
expr_stmt|;
name|FUZZYCOMPARE
argument_list|(
name|time
operator|.
name|elapsed
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|10
argument_list|,
name|timeout
argument_list|)
argument_list|)
expr_stmt|;
name|FUZZYCOMPARE
argument_list|(
name|time
operator|.
name|elapsed
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|10
argument_list|,
name|timeout
argument_list|)
argument_list|)
expr_stmt|;
name|FUZZYCOMPARE
argument_list|(
name|time
operator|.
name|elapsed
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// should not be able to acquire more
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|1
argument_list|,
name|timeout
argument_list|)
argument_list|)
expr_stmt|;
name|FUZZYCOMPARE
argument_list|(
name|time
operator|.
name|elapsed
argument_list|()
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|1
argument_list|,
name|timeout
argument_list|)
argument_list|)
expr_stmt|;
name|FUZZYCOMPARE
argument_list|(
name|time
operator|.
name|elapsed
argument_list|()
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|10
argument_list|,
name|timeout
argument_list|)
argument_list|)
expr_stmt|;
name|FUZZYCOMPARE
argument_list|(
name|time
operator|.
name|elapsed
argument_list|()
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
literal|10
argument_list|,
name|timeout
argument_list|)
argument_list|)
expr_stmt|;
name|FUZZYCOMPARE
argument_list|(
name|time
operator|.
name|elapsed
argument_list|()
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|semaphore
operator|.
name|available
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
DECL|macro|FUZZYCOMPARE
undef|#
directive|undef
name|FUZZYCOMPARE
block|}
end_function
begin_function
DECL|function|tryAcquireWithTimeoutStarvation
name|void
name|tst_QSemaphore
operator|::
name|tryAcquireWithTimeoutStarvation
parameter_list|()
block|{
class|class
name|Thread
super|:
specifier|public
name|QThread
block|{
public|public:
name|QSemaphore
name|startup
decl_stmt|;
name|QSemaphore
modifier|*
name|semaphore
decl_stmt|;
name|int
name|amountToConsume
decl_stmt|,
name|timeout
decl_stmt|;
name|void
name|run
parameter_list|()
block|{
name|startup
operator|.
name|release
argument_list|()
expr_stmt|;
forever|forever
block|{
if|if
condition|(
operator|!
name|semaphore
operator|->
name|tryAcquire
argument_list|(
name|amountToConsume
argument_list|,
name|timeout
argument_list|)
condition|)
break|break;
name|semaphore
operator|->
name|release
argument_list|(
name|amountToConsume
argument_list|)
expr_stmt|;
block|}
block|}
block|}
class|;
name|QSemaphore
name|semaphore
decl_stmt|;
name|semaphore
operator|.
name|release
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|Thread
name|consumer
decl_stmt|;
name|consumer
operator|.
name|semaphore
operator|=
operator|&
name|semaphore
expr_stmt|;
name|consumer
operator|.
name|amountToConsume
operator|=
literal|1
expr_stmt|;
name|consumer
operator|.
name|timeout
operator|=
literal|1000
expr_stmt|;
comment|// start the thread and wait for it to start consuming
name|consumer
operator|.
name|start
argument_list|()
expr_stmt|;
name|consumer
operator|.
name|startup
operator|.
name|acquire
argument_list|()
expr_stmt|;
comment|// try to consume more than the thread we started is, and provide a longer
comment|// timeout... we should timeout, not wait indefinitely
name|QVERIFY
argument_list|(
operator|!
name|semaphore
operator|.
name|tryAcquire
argument_list|(
name|consumer
operator|.
name|amountToConsume
operator|*
literal|2
argument_list|,
name|consumer
operator|.
name|timeout
operator|*
literal|2
argument_list|)
argument_list|)
expr_stmt|;
comment|// the consumer should still be running
name|QVERIFY
argument_list|(
name|consumer
operator|.
name|isRunning
argument_list|()
operator|&&
operator|!
name|consumer
operator|.
name|isFinished
argument_list|()
argument_list|)
expr_stmt|;
comment|// acquire, and wait for smallConsumer to timeout
name|semaphore
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|consumer
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|alphabet
specifier|const
name|char
name|alphabet
index|[]
init|=
literal|"ACGTH"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|AlphabetSize
specifier|const
name|int
name|AlphabetSize
init|=
sizeof|sizeof
argument_list|(
name|alphabet
argument_list|)
operator|-
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|BufferSize
specifier|const
name|int
name|BufferSize
init|=
literal|4096
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|BufferSize
comment|// GCD of BufferSize and alphabet size must be 1
end_comment
begin_decl_stmt
DECL|variable|buffer
name|char
name|buffer
index|[
name|BufferSize
index|]
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_decl_stmt
DECL|variable|ProducerChunkSize
specifier|const
name|int
name|ProducerChunkSize
init|=
literal|3
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ConsumerChunkSize
specifier|const
name|int
name|ConsumerChunkSize
init|=
literal|7
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Multiplier
specifier|const
name|int
name|Multiplier
init|=
literal|10
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
DECL|variable|ProducerChunkSize
specifier|const
name|int
name|ProducerChunkSize
init|=
literal|2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ConsumerChunkSize
specifier|const
name|int
name|ConsumerChunkSize
init|=
literal|5
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Multiplier
specifier|const
name|int
name|Multiplier
init|=
literal|3
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// note: the code depends on the fact that DataSize is a multiple of
end_comment
begin_comment
comment|// ProducerChunkSize, ConsumerChunkSize, and BufferSize
end_comment
begin_decl_stmt
DECL|variable|DataSize
specifier|const
name|int
name|DataSize
init|=
name|ProducerChunkSize
operator|*
name|ConsumerChunkSize
operator|*
name|BufferSize
operator|*
name|Multiplier
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QSemaphore
name|freeSpace
parameter_list|(
name|BufferSize
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|usedSpace
name|QSemaphore
name|usedSpace
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|Producer
class|class
name|Producer
super|:
specifier|public
name|QThread
block|{
public|public:
name|void
name|run
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|run
name|void
name|Producer
operator|::
name|run
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
name|DataSize
condition|;
operator|++
name|i
control|)
block|{
name|freeSpace
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|buffer
index|[
name|i
operator|%
name|BufferSize
index|]
operator|=
name|alphabet
index|[
name|i
operator|%
name|AlphabetSize
index|]
expr_stmt|;
name|usedSpace
operator|.
name|release
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
name|DataSize
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|(
name|i
operator|%
name|ProducerChunkSize
operator|)
operator|==
literal|0
condition|)
name|freeSpace
operator|.
name|acquire
argument_list|(
name|ProducerChunkSize
argument_list|)
expr_stmt|;
name|buffer
index|[
name|i
operator|%
name|BufferSize
index|]
operator|=
name|alphabet
index|[
name|i
operator|%
name|AlphabetSize
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|i
operator|%
name|ProducerChunkSize
operator|)
operator|==
operator|(
name|ProducerChunkSize
operator|-
literal|1
operator|)
condition|)
name|usedSpace
operator|.
name|release
argument_list|(
name|ProducerChunkSize
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_class
DECL|class|Consumer
class|class
name|Consumer
super|:
specifier|public
name|QThread
block|{
public|public:
name|void
name|run
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|run
name|void
name|Consumer
operator|::
name|run
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
name|DataSize
condition|;
operator|++
name|i
control|)
block|{
name|usedSpace
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buffer
index|[
name|i
operator|%
name|BufferSize
index|]
argument_list|,
name|alphabet
index|[
name|i
operator|%
name|AlphabetSize
index|]
argument_list|)
expr_stmt|;
name|freeSpace
operator|.
name|release
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
name|DataSize
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|(
name|i
operator|%
name|ConsumerChunkSize
operator|)
operator|==
literal|0
condition|)
name|usedSpace
operator|.
name|acquire
argument_list|(
name|ConsumerChunkSize
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buffer
index|[
name|i
operator|%
name|BufferSize
index|]
argument_list|,
name|alphabet
index|[
name|i
operator|%
name|AlphabetSize
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|i
operator|%
name|ConsumerChunkSize
operator|)
operator|==
operator|(
name|ConsumerChunkSize
operator|-
literal|1
operator|)
condition|)
name|freeSpace
operator|.
name|release
argument_list|(
name|ConsumerChunkSize
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|producerConsumer
name|void
name|tst_QSemaphore
operator|::
name|producerConsumer
parameter_list|()
block|{
name|Producer
name|producer
decl_stmt|;
name|Consumer
name|consumer
decl_stmt|;
name|producer
operator|.
name|start
argument_list|()
expr_stmt|;
name|consumer
operator|.
name|start
argument_list|()
expr_stmt|;
name|producer
operator|.
name|wait
argument_list|()
expr_stmt|;
name|consumer
operator|.
name|wait
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSemaphore
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsemaphore.moc"
end_include
end_unit
