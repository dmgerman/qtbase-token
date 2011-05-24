begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qatomic.h>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qmutex.h>
end_include
begin_include
include|#
directive|include
file|<qthread.h>
end_include
begin_include
include|#
directive|include
file|<qwaitcondition.h>
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_QMutex
class|class
name|tst_QMutex
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QMutex
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QMutex
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|tryLock
parameter_list|()
function_decl|;
name|void
name|lock_unlock_locked_tryLock
parameter_list|()
function_decl|;
name|void
name|stressTest
parameter_list|()
function_decl|;
name|void
name|tryLockRace
parameter_list|()
function_decl|;
name|void
name|qtbug16115_trylock
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|iterations
specifier|static
specifier|const
name|int
name|iterations
init|=
literal|100
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|tst_QMutex
name|tst_QMutex
operator|::
name|tst_QMutex
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QMutex
name|tst_QMutex
operator|::
name|~
name|tst_QMutex
parameter_list|()
block|{ }
end_destructor
begin_decl_stmt
name|QAtomicInt
name|lockCount
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|normalMutex
name|QMutex
name|normalMutex
decl_stmt|,
name|recursiveMutex
argument_list|(
name|QMutex
operator|::
name|Recursive
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|testsTurn
name|QSemaphore
name|testsTurn
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|threadsTurn
name|QSemaphore
name|threadsTurn
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|tryLock
name|void
name|tst_QMutex
operator|::
name|tryLock
parameter_list|()
block|{
comment|// test non-recursive mutex
block|{
class|class
name|Thread
super|:
specifier|public
name|QThread
block|{
public|public:
name|void
name|run
parameter_list|()
block|{
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|normalMutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|normalMutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|normalMutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|normalMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QTime
name|timer
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|normalMutex
operator|.
name|tryLock
argument_list|(
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|timer
operator|.
name|elapsed
argument_list|()
operator|>=
literal|1000
argument_list|)
expr_stmt|;
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|normalMutex
operator|.
name|tryLock
argument_list|(
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|timer
operator|.
name|elapsed
argument_list|()
operator|<=
literal|1000
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|normalMutex
operator|.
name|tryLock
argument_list|(
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|timer
operator|.
name|elapsed
argument_list|()
operator|>=
literal|1000
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|normalMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|normalMutex
operator|.
name|tryLock
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|normalMutex
operator|.
name|tryLock
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|timer
operator|.
name|elapsed
argument_list|()
operator|<
literal|1000
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|normalMutex
operator|.
name|tryLock
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|normalMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
block|}
block|}
class|;
name|Thread
name|thread
decl_stmt|;
name|thread
operator|.
name|start
argument_list|()
expr_stmt|;
comment|// thread can't acquire lock
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|normalMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// thread can acquire lock
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|normalMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// thread can't acquire lock, timeout = 1000
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|normalMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// thread can acquire lock, timeout = 1000
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|normalMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// thread can't acquire lock, timeout = 0
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|normalMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// thread can acquire lock, timeout = 0
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|normalMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// wait for thread to finish
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|thread
operator|.
name|wait
argument_list|()
expr_stmt|;
block|}
comment|// test recursive mutex
block|{
class|class
name|Thread
super|:
specifier|public
name|QThread
block|{
public|public:
name|void
name|run
parameter_list|()
block|{
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|recursiveMutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|recursiveMutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|recursiveMutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QTime
name|timer
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|recursiveMutex
operator|.
name|tryLock
argument_list|(
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|timer
operator|.
name|elapsed
argument_list|()
operator|>=
literal|1000
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|recursiveMutex
operator|.
name|tryLock
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|recursiveMutex
operator|.
name|tryLock
argument_list|(
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|timer
operator|.
name|elapsed
argument_list|()
operator|<=
literal|1000
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|recursiveMutex
operator|.
name|tryLock
argument_list|(
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|recursiveMutex
operator|.
name|tryLock
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|recursiveMutex
operator|.
name|tryLock
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|recursiveMutex
operator|.
name|tryLock
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|timer
operator|.
name|elapsed
argument_list|()
operator|<
literal|1000
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|recursiveMutex
operator|.
name|tryLock
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|testsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
block|}
block|}
class|;
name|Thread
name|thread
decl_stmt|;
name|thread
operator|.
name|start
argument_list|()
expr_stmt|;
comment|// thread can't acquire lock
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|recursiveMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// thread can acquire lock
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// thread can't acquire lock, timeout = 1000
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|recursiveMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// thread can acquire lock, timeout = 1000
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// thread can't acquire lock, timeout = 0
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|recursiveMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// thread can acquire lock, timeout = 0
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|lockCount
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|recursiveMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// stop thread
name|testsTurn
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|threadsTurn
operator|.
name|release
argument_list|()
expr_stmt|;
name|thread
operator|.
name|wait
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_class
DECL|class|mutex_Thread
class|class
name|mutex_Thread
super|:
specifier|public
name|QThread
block|{
public|public:
DECL|member|mutex
name|QMutex
name|mutex
decl_stmt|;
DECL|member|cond
name|QWaitCondition
name|cond
decl_stmt|;
DECL|member|test_mutex
name|QMutex
modifier|&
name|test_mutex
decl_stmt|;
DECL|function|mutex_Thread
specifier|inline
name|mutex_Thread
parameter_list|(
name|QMutex
modifier|&
name|m
parameter_list|)
member_init_list|:
name|test_mutex
argument_list|(
name|m
argument_list|)
block|{ }
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|test_mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|iterations
condition|;
operator|++
name|i
control|)
block|{
name|cond
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
name|cond
operator|.
name|wait
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
block|}
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|test_mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|rmutex_Thread
class|class
name|rmutex_Thread
super|:
specifier|public
name|QThread
block|{
public|public:
DECL|member|mutex
name|QMutex
name|mutex
decl_stmt|;
DECL|member|cond
name|QWaitCondition
name|cond
decl_stmt|;
DECL|member|test_mutex
name|QMutex
modifier|&
name|test_mutex
decl_stmt|;
DECL|function|rmutex_Thread
specifier|inline
name|rmutex_Thread
parameter_list|(
name|QMutex
modifier|&
name|m
parameter_list|)
member_init_list|:
name|test_mutex
argument_list|(
name|m
argument_list|)
block|{ }
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|test_mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|test_mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|test_mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|test_mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|iterations
condition|;
operator|++
name|i
control|)
block|{
name|cond
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
name|cond
operator|.
name|wait
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
block|}
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|test_mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|test_mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|test_mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|test_mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|lock_unlock_locked_tryLock
name|void
name|tst_QMutex
operator|::
name|lock_unlock_locked_tryLock
parameter_list|()
block|{
comment|// normal mutex
name|QMutex
name|mutex
decl_stmt|;
name|mutex_Thread
name|thread
argument_list|(
name|mutex
argument_list|)
decl_stmt|;
name|QMutex
name|rmutex
argument_list|(
name|QMutex
operator|::
name|Recursive
argument_list|)
decl_stmt|;
name|rmutex_Thread
name|rthread
argument_list|(
name|rmutex
argument_list|)
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
name|iterations
condition|;
operator|++
name|i
control|)
block|{
comment|// normal mutex
name|QVERIFY
argument_list|(
name|mutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|thread
operator|.
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|thread
operator|.
name|start
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|iterations
condition|;
operator|++
name|j
control|)
block|{
name|QVERIFY
argument_list|(
name|thread
operator|.
name|cond
operator|.
name|wait
argument_list|(
operator|&
name|thread
operator|.
name|mutex
argument_list|,
literal|10000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|thread
operator|.
name|cond
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
block|}
name|thread
operator|.
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|thread
operator|.
name|wait
argument_list|(
literal|10000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
comment|// recursive mutex
name|QVERIFY
argument_list|(
name|rmutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|rmutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|rmutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|rmutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|rmutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|rmutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|rmutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|rmutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|rthread
operator|.
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|rthread
operator|.
name|start
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|k
init|=
literal|0
init|;
name|k
operator|<
name|iterations
condition|;
operator|++
name|k
control|)
block|{
name|QVERIFY
argument_list|(
name|rthread
operator|.
name|cond
operator|.
name|wait
argument_list|(
operator|&
name|rthread
operator|.
name|mutex
argument_list|,
literal|10000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|rmutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|rthread
operator|.
name|cond
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
block|}
name|rthread
operator|.
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|rthread
operator|.
name|wait
argument_list|(
literal|10000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|rmutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|rmutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|rmutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|rmutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|rmutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|rmutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|rmutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|rmutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_enum
DECL|enumerator|one_minute
DECL|enumerator|threadCount
enum|enum
block|{
name|one_minute
init|=
literal|60
operator|*
literal|1000
block|,
name|threadCount
init|=
literal|10
block|}
enum|;
end_enum
begin_class
DECL|class|StressTestThread
class|class
name|StressTestThread
super|:
specifier|public
name|QThread
block|{
DECL|member|t
name|QTime
name|t
decl_stmt|;
public|public:
DECL|member|lockCount
specifier|static
name|QBasicAtomicInt
name|lockCount
decl_stmt|;
DECL|member|sentinel
specifier|static
name|QBasicAtomicInt
name|sentinel
decl_stmt|;
DECL|member|mutex
specifier|static
name|QMutex
name|mutex
decl_stmt|;
DECL|member|errorCount
specifier|static
name|int
name|errorCount
decl_stmt|;
DECL|function|start
name|void
name|start
parameter_list|()
block|{
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
name|QThread
operator|::
name|start
argument_list|()
expr_stmt|;
block|}
DECL|function|run
name|void
name|run
parameter_list|()
block|{
while|while
condition|(
name|t
operator|.
name|elapsed
argument_list|()
operator|<
name|one_minute
condition|)
block|{
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|sentinel
operator|.
name|ref
argument_list|()
condition|)
operator|++
name|errorCount
expr_stmt|;
if|if
condition|(
operator|!
name|sentinel
operator|.
name|deref
argument_list|()
condition|)
operator|++
name|errorCount
expr_stmt|;
name|lockCount
operator|.
name|ref
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
if|if
condition|(
name|mutex
operator|.
name|tryLock
argument_list|()
condition|)
block|{
if|if
condition|(
name|sentinel
operator|.
name|ref
argument_list|()
condition|)
operator|++
name|errorCount
expr_stmt|;
if|if
condition|(
operator|!
name|sentinel
operator|.
name|deref
argument_list|()
condition|)
operator|++
name|errorCount
expr_stmt|;
name|lockCount
operator|.
name|ref
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
block|}
block|}
block|}
class|;
end_class
begin_decl_stmt
DECL|member|mutex
name|QMutex
name|StressTestThread
operator|::
name|mutex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|lockCount
name|QBasicAtomicInt
name|StressTestThread
operator|::
name|lockCount
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|sentinel
name|QBasicAtomicInt
name|StressTestThread
operator|::
name|sentinel
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|errorCount
name|int
name|StressTestThread
operator|::
name|errorCount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|stressTest
name|void
name|tst_QMutex
operator|::
name|stressTest
parameter_list|()
block|{
name|StressTestThread
name|threads
index|[
name|threadCount
index|]
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
name|threadCount
condition|;
operator|++
name|i
control|)
name|threads
index|[
name|i
index|]
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|threads
index|[
literal|0
index|]
operator|.
name|wait
argument_list|(
name|one_minute
operator|+
literal|10000
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|threadCount
condition|;
operator|++
name|i
control|)
name|QVERIFY
argument_list|(
name|threads
index|[
name|i
index|]
operator|.
name|wait
argument_list|(
literal|10000
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|StressTestThread
operator|::
name|errorCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"locked %d times"
argument_list|,
name|int
argument_list|(
name|StressTestThread
operator|::
name|lockCount
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|TryLockRaceThread
class|class
name|TryLockRaceThread
super|:
specifier|public
name|QThread
block|{
public|public:
DECL|member|mutex
specifier|static
name|QMutex
name|mutex
decl_stmt|;
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|QTime
name|t
decl_stmt|;
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
do|do
block|{
if|if
condition|(
name|mutex
operator|.
name|tryLock
argument_list|()
condition|)
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
name|t
operator|.
name|elapsed
argument_list|()
operator|<
literal|20000
condition|)
do|;
block|}
block|}
class|;
end_class
begin_decl_stmt
DECL|member|mutex
name|QMutex
name|TryLockRaceThread
operator|::
name|mutex
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|tryLockRace
name|void
name|tst_QMutex
operator|::
name|tryLockRace
parameter_list|()
block|{
comment|// mutex not in use, should be able to lock it
name|QVERIFY
argument_list|(
name|TryLockRaceThread
operator|::
name|mutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|TryLockRaceThread
operator|::
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
comment|// try to break tryLock
name|TryLockRaceThread
name|thread
index|[
name|threadCount
index|]
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
name|threadCount
condition|;
operator|++
name|i
control|)
name|thread
index|[
name|i
index|]
operator|.
name|start
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|threadCount
condition|;
operator|++
name|i
control|)
name|QVERIFY
argument_list|(
name|thread
index|[
name|i
index|]
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
comment|// mutex not in use, should be able to lock it
name|QVERIFY
argument_list|(
name|TryLockRaceThread
operator|::
name|mutex
operator|.
name|tryLock
argument_list|()
argument_list|)
expr_stmt|;
name|TryLockRaceThread
operator|::
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// Variable that will be protected by the mutex. Volatile so that the
end_comment
begin_comment
comment|// the optimiser doesn't mess with it based on the increment-then-decrement
end_comment
begin_comment
comment|// usage pattern.
end_comment
begin_decl_stmt
DECL|variable|qtbug16115_trylock_counter
specifier|static
specifier|volatile
name|int
name|qtbug16115_trylock_counter
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Counter for how many times the protected variable has an incorrect value.
end_comment
begin_decl_stmt
DECL|variable|qtbug16115_failure_count
specifier|static
name|int
name|qtbug16115_failure_count
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qtbug16115_trylock
name|void
name|tst_QMutex
operator|::
name|qtbug16115_trylock
parameter_list|()
block|{
comment|//Used to deadlock on unix
struct|struct
name|TrylockThread
super|:
name|QThread
block|{
name|TrylockThread
parameter_list|(
name|QMutex
modifier|&
name|mut
parameter_list|)
member_init_list|:
name|mut
argument_list|(
name|mut
argument_list|)
block|{}
name|QMutex
modifier|&
name|mut
decl_stmt|;
name|void
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
literal|1000000
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|mut
operator|.
name|tryLock
argument_list|(
literal|0
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
operator|++
name|qtbug16115_trylock_counter
operator|)
operator|!=
literal|1
condition|)
operator|++
name|qtbug16115_failure_count
expr_stmt|;
if|if
condition|(
operator|(
operator|--
name|qtbug16115_trylock_counter
operator|)
operator|!=
literal|0
condition|)
operator|++
name|qtbug16115_failure_count
expr_stmt|;
name|mut
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
block|}
block|}
block|}
struct|;
name|QMutex
name|mut
decl_stmt|;
name|TrylockThread
name|t1
argument_list|(
name|mut
argument_list|)
decl_stmt|;
name|TrylockThread
name|t2
argument_list|(
name|mut
argument_list|)
decl_stmt|;
name|TrylockThread
name|t3
argument_list|(
name|mut
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
name|t3
operator|.
name|start
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|1000000
condition|;
operator|++
name|i
control|)
block|{
name|mut
operator|.
name|lock
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
operator|++
name|qtbug16115_trylock_counter
operator|)
operator|!=
literal|1
condition|)
operator|++
name|qtbug16115_failure_count
expr_stmt|;
if|if
condition|(
operator|(
operator|--
name|qtbug16115_trylock_counter
operator|)
operator|!=
literal|0
condition|)
operator|++
name|qtbug16115_failure_count
expr_stmt|;
name|mut
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
name|t1
operator|.
name|wait
argument_list|()
expr_stmt|;
name|t2
operator|.
name|wait
argument_list|()
expr_stmt|;
name|t3
operator|.
name|wait
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qtbug16115_failure_count
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QMutex
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qmutex.moc"
end_include
end_unit
