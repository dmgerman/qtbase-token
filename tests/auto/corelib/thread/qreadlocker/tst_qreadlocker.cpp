begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QReadLocker>
end_include
begin_include
include|#
directive|include
file|<QSemaphore>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_class
DECL|class|tst_QReadLockerThread
class|class
name|tst_QReadLockerThread
super|:
specifier|public
name|QThread
block|{
public|public:
DECL|member|lock
name|QReadWriteLock
name|lock
decl_stmt|;
DECL|member|semaphore
DECL|member|testSemaphore
name|QSemaphore
name|semaphore
decl_stmt|,
name|testSemaphore
decl_stmt|;
DECL|function|waitForTest
name|void
name|waitForTest
parameter_list|()
block|{
name|semaphore
operator|.
name|release
argument_list|()
expr_stmt|;
name|testSemaphore
operator|.
name|acquire
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|tst_QReadLocker
class|class
name|tst_QReadLocker
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|member|thread
name|tst_QReadLockerThread
modifier|*
name|thread
decl_stmt|;
DECL|function|waitForThread
name|void
name|waitForThread
parameter_list|()
block|{
name|thread
operator|->
name|semaphore
operator|.
name|acquire
argument_list|()
expr_stmt|;
block|}
DECL|function|releaseThread
name|void
name|releaseThread
parameter_list|()
block|{
name|thread
operator|->
name|testSemaphore
operator|.
name|release
argument_list|()
expr_stmt|;
block|}
private|private
name|slots
private|:
name|void
name|scopeTest
parameter_list|()
function_decl|;
name|void
name|unlockAndRelockTest
parameter_list|()
function_decl|;
name|void
name|lockerStateTest
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|scopeTest
name|void
name|tst_QReadLocker
operator|::
name|scopeTest
parameter_list|()
block|{
class|class
name|ScopeTestThread
super|:
specifier|public
name|tst_QReadLockerThread
block|{
public|public:
name|void
name|run
parameter_list|()
block|{
name|waitForTest
argument_list|()
expr_stmt|;
block|{
name|QReadLocker
name|locker
argument_list|(
operator|&
name|lock
argument_list|)
decl_stmt|;
name|waitForTest
argument_list|()
expr_stmt|;
block|}
name|waitForTest
argument_list|()
expr_stmt|;
block|}
block|}
class|;
name|thread
operator|=
operator|new
name|ScopeTestThread
expr_stmt|;
name|thread
operator|->
name|start
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// lock should be unlocked before entering the scope that creates the QReadLocker
name|QVERIFY
argument_list|(
name|thread
operator|->
name|lock
operator|.
name|tryLockForWrite
argument_list|()
argument_list|)
expr_stmt|;
name|thread
operator|->
name|lock
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// lock should be locked by the QReadLocker
name|QVERIFY
argument_list|(
operator|!
name|thread
operator|->
name|lock
operator|.
name|tryLockForWrite
argument_list|()
argument_list|)
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// lock should be unlocked when the QReadLocker goes out of scope
name|QVERIFY
argument_list|(
name|thread
operator|->
name|lock
operator|.
name|tryLockForWrite
argument_list|()
argument_list|)
expr_stmt|;
name|thread
operator|->
name|lock
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|thread
operator|->
name|wait
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|thread
expr_stmt|;
name|thread
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unlockAndRelockTest
name|void
name|tst_QReadLocker
operator|::
name|unlockAndRelockTest
parameter_list|()
block|{
class|class
name|UnlockAndRelockThread
super|:
specifier|public
name|tst_QReadLockerThread
block|{
public|public:
name|void
name|run
parameter_list|()
block|{
name|QReadLocker
name|locker
argument_list|(
operator|&
name|lock
argument_list|)
decl_stmt|;
name|waitForTest
argument_list|()
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|waitForTest
argument_list|()
expr_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
name|waitForTest
argument_list|()
expr_stmt|;
block|}
block|}
class|;
name|thread
operator|=
operator|new
name|UnlockAndRelockThread
expr_stmt|;
name|thread
operator|->
name|start
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// lock should be locked by the QReadLocker
name|QVERIFY
argument_list|(
operator|!
name|thread
operator|->
name|lock
operator|.
name|tryLockForWrite
argument_list|()
argument_list|)
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// lock has been explicitly unlocked via QReadLocker
name|QVERIFY
argument_list|(
name|thread
operator|->
name|lock
operator|.
name|tryLockForWrite
argument_list|()
argument_list|)
expr_stmt|;
name|thread
operator|->
name|lock
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// lock has been explicitly relocked via QReadLocker
name|QVERIFY
argument_list|(
operator|!
name|thread
operator|->
name|lock
operator|.
name|tryLockForWrite
argument_list|()
argument_list|)
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|thread
operator|->
name|wait
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|thread
expr_stmt|;
name|thread
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lockerStateTest
name|void
name|tst_QReadLocker
operator|::
name|lockerStateTest
parameter_list|()
block|{
class|class
name|LockerStateThread
super|:
specifier|public
name|tst_QReadLockerThread
block|{
public|public:
name|void
name|run
parameter_list|()
block|{
block|{
name|QReadLocker
name|locker
argument_list|(
operator|&
name|lock
argument_list|)
decl_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|waitForTest
argument_list|()
expr_stmt|;
block|}
name|waitForTest
argument_list|()
expr_stmt|;
block|}
block|}
class|;
name|thread
operator|=
operator|new
name|LockerStateThread
expr_stmt|;
name|thread
operator|->
name|start
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// even though we relock() after creating the QReadLocker, it shouldn't lock the lock more than once
name|QVERIFY
argument_list|(
name|thread
operator|->
name|lock
operator|.
name|tryLockForWrite
argument_list|()
argument_list|)
expr_stmt|;
name|thread
operator|->
name|lock
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|waitForThread
argument_list|()
expr_stmt|;
comment|// if we call QReadLocker::unlock(), its destructor should do nothing
name|QVERIFY
argument_list|(
name|thread
operator|->
name|lock
operator|.
name|tryLockForWrite
argument_list|()
argument_list|)
expr_stmt|;
name|thread
operator|->
name|lock
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|releaseThread
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|thread
operator|->
name|wait
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|thread
expr_stmt|;
name|thread
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QReadLocker
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qreadlocker.moc"
end_include
end_unit
