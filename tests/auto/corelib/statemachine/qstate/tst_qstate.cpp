begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|"qstate.h"
end_include
begin_include
include|#
directive|include
file|"qstatemachine.h"
end_include
begin_include
include|#
directive|include
file|"qsignaltransition.h"
end_include
begin_class
DECL|class|tst_QState
class|class
name|tst_QState
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|assignProperty
parameter_list|()
function_decl|;
name|void
name|assignPropertyTwice
parameter_list|()
function_decl|;
name|void
name|historyInitialState
parameter_list|()
function_decl|;
name|void
name|transitions
parameter_list|()
function_decl|;
name|void
name|privateSignals
parameter_list|()
function_decl|;
name|void
name|parallelStateAndInitialState
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|TestClass
class|class
name|TestClass
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|TestClass
name|TestClass
parameter_list|()
member_init_list|:
name|called
argument_list|(
literal|false
argument_list|)
block|{}
DECL|member|called
name|bool
name|called
decl_stmt|;
public|public
name|slots
public|:
DECL|function|slot
name|void
name|slot
parameter_list|()
block|{
name|called
operator|=
literal|true
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|assignProperty
name|void
name|tst_QState
operator|::
name|assignProperty
parameter_list|()
block|{
name|QStateMachine
name|machine
decl_stmt|;
name|QObject
name|object
decl_stmt|;
name|object
operator|.
name|setProperty
argument_list|(
literal|"fooBar"
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|s1
operator|->
name|assignProperty
argument_list|(
operator|&
name|object
argument_list|,
literal|"fooBar"
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|machine
operator|.
name|setInitialState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|machine
operator|.
name|start
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|object
operator|.
name|property
argument_list|(
literal|"fooBar"
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|assignPropertyTwice
name|void
name|tst_QState
operator|::
name|assignPropertyTwice
parameter_list|()
block|{
name|QStateMachine
name|machine
decl_stmt|;
name|QObject
name|object
decl_stmt|;
name|object
operator|.
name|setProperty
argument_list|(
literal|"fooBar"
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|s1
operator|->
name|assignProperty
argument_list|(
operator|&
name|object
argument_list|,
literal|"fooBar"
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|s1
operator|->
name|assignProperty
argument_list|(
operator|&
name|object
argument_list|,
literal|"fooBar"
argument_list|,
literal|30
argument_list|)
expr_stmt|;
name|machine
operator|.
name|setInitialState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|machine
operator|.
name|start
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|object
operator|.
name|property
argument_list|(
literal|"fooBar"
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|30
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|EventTestTransition
class|class
name|EventTestTransition
super|:
specifier|public
name|QAbstractTransition
block|{
public|public:
DECL|function|EventTestTransition
name|EventTestTransition
parameter_list|(
name|QEvent
operator|::
name|Type
name|type
parameter_list|,
name|QState
modifier|*
name|targetState
parameter_list|)
member_init_list|:
name|QAbstractTransition
argument_list|()
member_init_list|,
name|m_type
argument_list|(
name|type
argument_list|)
block|{
name|setTargetState
argument_list|(
name|targetState
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|function|eventTest
name|bool
name|eventTest
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|e
operator|->
name|type
argument_list|()
operator|==
name|m_type
return|;
block|}
DECL|function|onTransition
name|void
name|onTransition
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{}
private|private:
DECL|member|m_type
name|QEvent
operator|::
name|Type
name|m_type
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|historyInitialState
name|void
name|tst_QState
operator|::
name|historyInitialState
parameter_list|()
block|{
name|QStateMachine
name|machine
decl_stmt|;
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|s2
init|=
operator|new
name|QState
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|QHistoryState
modifier|*
name|h1
init|=
operator|new
name|QHistoryState
argument_list|(
name|s2
argument_list|)
decl_stmt|;
name|s2
operator|->
name|setInitialState
argument_list|(
name|h1
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s3
init|=
operator|new
name|QState
argument_list|(
name|s2
argument_list|)
decl_stmt|;
name|h1
operator|->
name|setDefaultState
argument_list|(
name|s3
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s4
init|=
operator|new
name|QState
argument_list|(
name|s2
argument_list|)
decl_stmt|;
name|s1
operator|->
name|addTransition
argument_list|(
operator|new
name|EventTestTransition
argument_list|(
name|QEvent
operator|::
name|User
argument_list|,
name|s2
argument_list|)
argument_list|)
expr_stmt|;
name|s2
operator|->
name|addTransition
argument_list|(
operator|new
name|EventTestTransition
argument_list|(
name|QEvent
operator|::
name|User
argument_list|,
name|s1
argument_list|)
argument_list|)
expr_stmt|;
name|s3
operator|->
name|addTransition
argument_list|(
operator|new
name|EventTestTransition
argument_list|(
name|QEvent
operator|::
name|Type
argument_list|(
name|QEvent
operator|::
name|User
operator|+
literal|1
argument_list|)
argument_list|,
name|s4
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|setInitialState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|machine
operator|.
name|start
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s1
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|postEvent
argument_list|(
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|User
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s3
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|postEvent
argument_list|(
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|User
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s1
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|postEvent
argument_list|(
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|User
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s3
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|postEvent
argument_list|(
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|Type
argument_list|(
name|QEvent
operator|::
name|User
operator|+
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s4
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|postEvent
argument_list|(
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|User
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s1
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|postEvent
argument_list|(
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|User
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s4
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|transitions
name|void
name|tst_QState
operator|::
name|transitions
parameter_list|()
block|{
name|QState
name|s1
decl_stmt|;
name|QState
name|s2
decl_stmt|;
name|QVERIFY
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QAbstractTransition
modifier|*
name|t1
init|=
name|s1
operator|.
name|addTransition
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|,
operator|&
name|s2
argument_list|)
decl_stmt|;
name|QAbstractTransition
modifier|*
name|t1_1
init|=
name|s1
operator|.
name|addTransition
argument_list|(
name|this
argument_list|,
operator|&
name|tst_QState
operator|::
name|destroyed
argument_list|,
operator|&
name|s2
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|t1
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t1_1
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|first
argument_list|()
argument_list|,
name|t1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|last
argument_list|()
argument_list|,
name|t1_1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|s2
operator|.
name|transitions
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|s1
operator|.
name|removeTransition
argument_list|(
name|t1
argument_list|)
expr_stmt|;
name|s1
operator|.
name|removeTransition
argument_list|(
name|t1_1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|s1
operator|.
name|addTransition
argument_list|(
name|t1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|first
argument_list|()
argument_list|,
name|t1
argument_list|)
expr_stmt|;
name|QAbstractTransition
modifier|*
name|t2
init|=
operator|new
name|QEventTransition
argument_list|(
operator|&
name|s1
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|contains
argument_list|(
name|t1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|contains
argument_list|(
name|t2
argument_list|)
argument_list|)
expr_stmt|;
comment|// Transitions from child states should not be reported.
name|QState
modifier|*
name|s21
init|=
operator|new
name|QState
argument_list|(
operator|&
name|s2
argument_list|)
decl_stmt|;
name|QAbstractTransition
modifier|*
name|t3
init|=
name|s21
operator|->
name|addTransition
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|,
operator|&
name|s2
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|s2
operator|.
name|transitions
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s21
operator|->
name|transitions
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s21
operator|->
name|transitions
argument_list|()
operator|.
name|first
argument_list|()
argument_list|,
name|t3
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|MyState
class|class
name|MyState
super|:
specifier|public
name|QState
block|{
name|Q_OBJECT
public|public:
DECL|function|MyState
name|MyState
parameter_list|(
name|QState
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QState
argument_list|(
name|parent
argument_list|)
block|{      }
DECL|function|emitPrivateSignals
name|void
name|emitPrivateSignals
parameter_list|()
block|{
comment|// These deliberately do not compile
comment|//         emit entered();
comment|//         emit exited();
comment|//
comment|//         emit entered(QPrivateSignal());
comment|//         emit exited(QPrivateSignal());
comment|//
comment|//         emit entered(QAbstractState::QPrivateSignal());
comment|//         emit exited(QAbstractState::QPrivateSignal());
block|}
block|}
class|;
end_class
begin_class
DECL|class|MyTransition
class|class
name|MyTransition
super|:
specifier|public
name|QSignalTransition
block|{
name|Q_OBJECT
public|public:
DECL|function|MyTransition
name|MyTransition
parameter_list|(
name|QObject
modifier|*
name|sender
parameter_list|,
specifier|const
name|char
modifier|*
name|signal
parameter_list|,
name|QState
modifier|*
name|sourceState
init|=
literal|0
parameter_list|)
member_init_list|:
name|QSignalTransition
argument_list|(
name|sender
argument_list|,
name|signal
argument_list|,
name|sourceState
argument_list|)
block|{      }
DECL|function|emitPrivateSignals
name|void
name|emitPrivateSignals
parameter_list|()
block|{
comment|// These deliberately do not compile
comment|//         emit triggered();
comment|//
comment|//         emit triggered(QPrivateSignal());
comment|//
comment|//         emit triggered(QAbstractTransition::QPrivateSignal());
block|}
block|}
class|;
end_class
begin_class
DECL|class|SignalConnectionTester
class|class
name|SignalConnectionTester
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|SignalConnectionTester
name|SignalConnectionTester
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|testPassed
argument_list|(
literal|false
argument_list|)
block|{      }
public|public
name|Q_SLOTS
public|:
DECL|function|testSlot
name|void
name|testSlot
parameter_list|()
block|{
name|testPassed
operator|=
literal|true
expr_stmt|;
block|}
public|public:
DECL|member|testPassed
name|bool
name|testPassed
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|TestTrigger
class|class
name|TestTrigger
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|TestTrigger
name|TestTrigger
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{      }
DECL|function|emitTrigger
name|void
name|emitTrigger
parameter_list|()
block|{
emit|emit
name|trigger
argument_list|()
emit|;
block|}
signals|signals:
name|void
name|trigger
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|privateSignals
name|void
name|tst_QState
operator|::
name|privateSignals
parameter_list|()
block|{
name|QStateMachine
name|machine
decl_stmt|;
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|MyState
modifier|*
name|s2
init|=
operator|new
name|MyState
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|TestTrigger
name|testTrigger
decl_stmt|;
name|MyTransition
modifier|*
name|t1
init|=
operator|new
name|MyTransition
argument_list|(
operator|&
name|testTrigger
argument_list|,
name|SIGNAL
argument_list|(
name|trigger
argument_list|()
argument_list|)
argument_list|,
name|s1
argument_list|)
decl_stmt|;
name|s1
operator|->
name|addTransition
argument_list|(
name|t1
argument_list|)
expr_stmt|;
name|t1
operator|->
name|setTargetState
argument_list|(
name|s2
argument_list|)
expr_stmt|;
name|machine
operator|.
name|setInitialState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|machine
operator|.
name|start
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|SignalConnectionTester
name|s1Tester
decl_stmt|;
name|SignalConnectionTester
name|s2Tester
decl_stmt|;
name|SignalConnectionTester
name|t1Tester
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|s1
argument_list|,
operator|&
name|QState
operator|::
name|exited
argument_list|,
operator|&
name|s1Tester
argument_list|,
operator|&
name|SignalConnectionTester
operator|::
name|testSlot
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|s2
argument_list|,
operator|&
name|QState
operator|::
name|entered
argument_list|,
operator|&
name|s2Tester
argument_list|,
operator|&
name|SignalConnectionTester
operator|::
name|testSlot
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|t1
argument_list|,
operator|&
name|QSignalTransition
operator|::
name|triggered
argument_list|,
operator|&
name|t1Tester
argument_list|,
operator|&
name|SignalConnectionTester
operator|::
name|testSlot
argument_list|)
expr_stmt|;
name|testTrigger
operator|.
name|emitTrigger
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|s1Tester
operator|.
name|testPassed
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|s2Tester
operator|.
name|testPassed
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t1Tester
operator|.
name|testPassed
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parallelStateAndInitialState
name|void
name|tst_QState
operator|::
name|parallelStateAndInitialState
parameter_list|()
block|{
name|QStateMachine
name|machine
decl_stmt|;
block|{
comment|// setting an initial state on a parallel state:
name|QState
name|a
argument_list|(
name|QState
operator|::
name|ParallelStates
argument_list|,
operator|&
name|machine
argument_list|)
decl_stmt|;
name|QState
name|b
argument_list|(
operator|&
name|a
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|a
operator|.
name|initialState
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|warning
init|=
name|QString
operator|::
name|asprintf
argument_list|(
literal|"QState::setInitialState: ignoring attempt to set initial state of parallel state group %p"
argument_list|,
operator|&
name|a
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
name|qPrintable
argument_list|(
name|warning
argument_list|)
argument_list|)
expr_stmt|;
name|a
operator|.
name|setInitialState
argument_list|(
operator|&
name|b
argument_list|)
expr_stmt|;
comment|// should produce a warning and do nothing.
name|QVERIFY
argument_list|(
operator|!
name|a
operator|.
name|initialState
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|{
comment|// setting the child-mode from ExclusiveStates to ParallelStates should remove the initial state:
name|QState
name|a
argument_list|(
name|QState
operator|::
name|ExclusiveStates
argument_list|,
operator|&
name|machine
argument_list|)
decl_stmt|;
name|QState
name|b
argument_list|(
operator|&
name|a
argument_list|)
decl_stmt|;
name|a
operator|.
name|setInitialState
argument_list|(
operator|&
name|b
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a
operator|.
name|initialState
argument_list|()
argument_list|,
operator|&
name|b
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|warning
init|=
name|QString
operator|::
name|asprintf
argument_list|(
literal|"QState::setChildMode: setting the child-mode of state %p to "
literal|"parallel removes the initial state"
argument_list|,
operator|&
name|a
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
name|qPrintable
argument_list|(
name|warning
argument_list|)
argument_list|)
expr_stmt|;
name|a
operator|.
name|setChildMode
argument_list|(
name|QState
operator|::
name|ParallelStates
argument_list|)
expr_stmt|;
comment|// should produce a warning and remove the initial state
name|QVERIFY
argument_list|(
operator|!
name|a
operator|.
name|initialState
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a
operator|.
name|childMode
argument_list|()
argument_list|,
name|QState
operator|::
name|ParallelStates
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QState
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qstate.moc"
end_include
end_unit
