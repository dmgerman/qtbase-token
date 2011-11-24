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
file|<qcoreapplication.h>
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
begin_include
include|#
directive|include
file|<qthreadstorage.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_include
include|#
directive|include
file|<pthread.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_include
include|#
directive|include
file|<process.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_QThreadStorage
class|class
name|tst_QThreadStorage
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|hasLocalData
parameter_list|()
function_decl|;
name|void
name|localData
parameter_list|()
function_decl|;
name|void
name|localData_const
parameter_list|()
function_decl|;
name|void
name|setLocalData
parameter_list|()
function_decl|;
name|void
name|autoDelete
parameter_list|()
function_decl|;
name|void
name|adoptedThreads
parameter_list|()
function_decl|;
name|void
name|ensureCleanupOrder
parameter_list|()
function_decl|;
name|void
name|crashOnExit
parameter_list|()
function_decl|;
name|void
name|leakInDestructor
parameter_list|()
function_decl|;
name|void
name|resetInDestructor
parameter_list|()
function_decl|;
name|void
name|valueBased
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|Pointer
class|class
name|Pointer
block|{
public|public:
DECL|member|count
specifier|static
name|int
name|count
decl_stmt|;
DECL|function|Pointer
specifier|inline
name|Pointer
parameter_list|()
block|{
operator|++
name|count
expr_stmt|;
block|}
DECL|function|~Pointer
specifier|inline
name|~
name|Pointer
parameter_list|()
block|{
operator|--
name|count
expr_stmt|;
block|}
block|}
class|;
end_class
begin_decl_stmt
DECL|member|count
name|int
name|Pointer
operator|::
name|count
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|hasLocalData
name|void
name|tst_QThreadStorage
operator|::
name|hasLocalData
parameter_list|()
block|{
name|QThreadStorage
argument_list|<
name|Pointer
modifier|*
argument_list|>
name|pointers
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pointers
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|pointers
operator|.
name|setLocalData
argument_list|(
operator|new
name|Pointer
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|pointers
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|pointers
operator|.
name|setLocalData
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pointers
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|localData
name|void
name|tst_QThreadStorage
operator|::
name|localData
parameter_list|()
block|{
name|QThreadStorage
argument_list|<
name|Pointer
modifier|*
argument_list|>
name|pointers
decl_stmt|;
name|Pointer
modifier|*
name|p
init|=
operator|new
name|Pointer
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pointers
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|pointers
operator|.
name|setLocalData
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|pointers
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pointers
operator|.
name|localData
argument_list|()
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|pointers
operator|.
name|setLocalData
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pointers
operator|.
name|localData
argument_list|()
argument_list|,
operator|(
name|Pointer
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pointers
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|localData_const
name|void
name|tst_QThreadStorage
operator|::
name|localData_const
parameter_list|()
block|{
name|QThreadStorage
argument_list|<
name|Pointer
modifier|*
argument_list|>
name|pointers
decl_stmt|;
specifier|const
name|QThreadStorage
argument_list|<
name|Pointer
modifier|*
argument_list|>
modifier|&
name|const_pointers
init|=
name|pointers
decl_stmt|;
name|Pointer
modifier|*
name|p
init|=
operator|new
name|Pointer
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pointers
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|pointers
operator|.
name|setLocalData
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|pointers
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|const_pointers
operator|.
name|localData
argument_list|()
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|pointers
operator|.
name|setLocalData
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|const_pointers
operator|.
name|localData
argument_list|()
argument_list|,
operator|(
name|Pointer
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pointers
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setLocalData
name|void
name|tst_QThreadStorage
operator|::
name|setLocalData
parameter_list|()
block|{
name|QThreadStorage
argument_list|<
name|Pointer
modifier|*
argument_list|>
name|pointers
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pointers
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|pointers
operator|.
name|setLocalData
argument_list|(
operator|new
name|Pointer
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|pointers
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|pointers
operator|.
name|setLocalData
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pointers
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|Thread
class|class
name|Thread
super|:
specifier|public
name|QThread
block|{
public|public:
DECL|member|pointers
name|QThreadStorage
argument_list|<
name|Pointer
modifier|*
argument_list|>
modifier|&
name|pointers
decl_stmt|;
DECL|member|mutex
name|QMutex
name|mutex
decl_stmt|;
DECL|member|cond
name|QWaitCondition
name|cond
decl_stmt|;
DECL|function|Thread
name|Thread
parameter_list|(
name|QThreadStorage
argument_list|<
name|Pointer
modifier|*
argument_list|>
modifier|&
name|p
parameter_list|)
member_init_list|:
name|pointers
argument_list|(
name|p
argument_list|)
block|{ }
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|pointers
operator|.
name|setLocalData
argument_list|(
operator|new
name|Pointer
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
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
block|}
class|;
end_class
begin_function
DECL|function|autoDelete
name|void
name|tst_QThreadStorage
operator|::
name|autoDelete
parameter_list|()
block|{
name|QThreadStorage
argument_list|<
name|Pointer
modifier|*
argument_list|>
name|pointers
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pointers
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|Thread
name|thread
argument_list|(
name|pointers
argument_list|)
decl_stmt|;
name|int
name|c
init|=
name|Pointer
operator|::
name|count
decl_stmt|;
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|thread
operator|.
name|mutex
argument_list|)
decl_stmt|;
name|thread
operator|.
name|start
argument_list|()
expr_stmt|;
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
argument_list|)
expr_stmt|;
comment|// QCOMPARE(Pointer::count, c + 1);
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
name|wait
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|Pointer
operator|::
name|count
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|threadStorageOk
name|bool
name|threadStorageOk
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|testAdoptedThreadStorageWin
name|void
name|testAdoptedThreadStorageWin
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|QThreadStorage
argument_list|<
name|Pointer
modifier|*
argument_list|>
modifier|*
name|pointers
init|=
cast|reinterpret_cast
argument_list|<
name|QThreadStorage
argument_list|<
name|Pointer
operator|*
argument_list|>
operator|*
argument_list|>
argument_list|(
name|p
argument_list|)
decl_stmt|;
if|if
condition|(
name|pointers
operator|->
name|hasLocalData
argument_list|()
condition|)
block|{
name|threadStorageOk
operator|=
literal|false
expr_stmt|;
return|return;
block|}
name|Pointer
modifier|*
name|pointer
init|=
operator|new
name|Pointer
argument_list|()
decl_stmt|;
name|pointers
operator|->
name|setLocalData
argument_list|(
name|pointer
argument_list|)
expr_stmt|;
if|if
condition|(
name|pointers
operator|->
name|hasLocalData
argument_list|()
operator|==
literal|false
condition|)
block|{
name|threadStorageOk
operator|=
literal|false
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|pointers
operator|->
name|localData
argument_list|()
operator|!=
name|pointer
condition|)
block|{
name|threadStorageOk
operator|=
literal|false
expr_stmt|;
return|return;
block|}
name|QObject
operator|::
name|connect
argument_list|(
name|QThread
operator|::
name|currentThread
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
operator|&
name|QTestEventLoop
operator|::
name|instance
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|exitLoop
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testAdoptedThreadStorageUnix
name|void
modifier|*
name|testAdoptedThreadStorageUnix
parameter_list|(
name|void
modifier|*
name|pointers
parameter_list|)
block|{
name|testAdoptedThreadStorageWin
argument_list|(
name|pointers
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|adoptedThreads
name|void
name|tst_QThreadStorage
operator|::
name|adoptedThreads
parameter_list|()
block|{
name|QTestEventLoop
operator|::
name|instance
argument_list|()
expr_stmt|;
comment|// Make sure the instance is created in this thread.
name|QThreadStorage
argument_list|<
name|Pointer
modifier|*
argument_list|>
name|pointers
decl_stmt|;
name|int
name|c
init|=
name|Pointer
operator|::
name|count
decl_stmt|;
name|threadStorageOk
operator|=
literal|true
expr_stmt|;
block|{
ifdef|#
directive|ifdef
name|Q_OS_UNIX
name|pthread_t
name|thread
decl_stmt|;
specifier|const
name|int
name|state
init|=
name|pthread_create
argument_list|(
operator|&
name|thread
argument_list|,
literal|0
argument_list|,
name|testAdoptedThreadStorageUnix
argument_list|,
operator|&
name|pointers
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|state
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pthread_join
argument_list|(
name|thread
argument_list|,
literal|0
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
name|Q_OS_WIN
name|HANDLE
name|thread
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|thread
operator|=
name|CreateThread
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
operator|(
name|LPTHREAD_START_ROUTINE
operator|)
name|testAdoptedThreadStorageWin
argument_list|,
operator|&
name|pointers
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
else|#
directive|else
name|thread
operator|=
operator|(
name|HANDLE
operator|)
name|_beginthread
argument_list|(
name|testAdoptedThreadStorageWin
argument_list|,
literal|0
argument_list|,
operator|&
name|pointers
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|thread
argument_list|)
expr_stmt|;
name|WaitForSingleObject
argument_list|(
name|thread
argument_list|,
name|INFINITE
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|QVERIFY
argument_list|(
name|threadStorageOk
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|Pointer
operator|::
name|count
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|cleanupOrder
name|QBasicAtomicInt
name|cleanupOrder
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|First
class|class
name|First
block|{
public|public:
DECL|function|~First
name|~
name|First
parameter_list|()
block|{
name|order
operator|=
name|cleanupOrder
operator|.
name|fetchAndAddRelaxed
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
DECL|member|order
specifier|static
name|int
name|order
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|member|order
name|int
name|First
operator|::
name|order
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|Second
class|class
name|Second
block|{
public|public:
DECL|function|~Second
name|~
name|Second
parameter_list|()
block|{
name|order
operator|=
name|cleanupOrder
operator|.
name|fetchAndAddRelaxed
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
DECL|member|order
specifier|static
name|int
name|order
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|member|order
name|int
name|Second
operator|::
name|order
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|ensureCleanupOrder
name|void
name|tst_QThreadStorage
operator|::
name|ensureCleanupOrder
parameter_list|()
block|{
class|class
name|Thread
super|:
specifier|public
name|QThread
block|{
public|public:
name|QThreadStorage
argument_list|<
name|First
modifier|*
argument_list|>
modifier|&
name|first
decl_stmt|;
name|QThreadStorage
argument_list|<
name|Second
modifier|*
argument_list|>
modifier|&
name|second
decl_stmt|;
name|Thread
parameter_list|(
name|QThreadStorage
argument_list|<
name|First
modifier|*
argument_list|>
modifier|&
name|first
parameter_list|,
name|QThreadStorage
argument_list|<
name|Second
modifier|*
argument_list|>
modifier|&
name|second
parameter_list|)
member_init_list|:
name|first
argument_list|(
name|first
argument_list|)
member_init_list|,
name|second
argument_list|(
name|second
argument_list|)
block|{ }
name|void
name|run
parameter_list|()
block|{
comment|// set in reverse order, but shouldn't matter, the data
comment|// will be deleted in the order the thread storage objects
comment|// were created
name|second
operator|.
name|setLocalData
argument_list|(
operator|new
name|Second
argument_list|)
expr_stmt|;
name|first
operator|.
name|setLocalData
argument_list|(
operator|new
name|First
argument_list|)
expr_stmt|;
block|}
block|}
class|;
name|QThreadStorage
argument_list|<
name|Second
modifier|*
argument_list|>
name|second
decl_stmt|;
name|QThreadStorage
argument_list|<
name|First
modifier|*
argument_list|>
name|first
decl_stmt|;
name|Thread
name|thread
argument_list|(
name|first
argument_list|,
name|second
argument_list|)
decl_stmt|;
name|thread
operator|.
name|start
argument_list|()
expr_stmt|;
name|thread
operator|.
name|wait
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|First
operator|::
name|order
operator|<
name|Second
operator|::
name|order
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|crashOnExit
name|void
name|tst_QThreadStorage
operator|::
name|crashOnExit
parameter_list|()
block|{
name|QProcess
name|process
decl_stmt|;
comment|// crashOnExit is always expected to be in the same directory
comment|// as this test binary
name|process
operator|.
name|start
argument_list|(
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
operator|+
literal|"/crashOnExit"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|process
operator|.
name|waitForFinished
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|process
operator|.
name|exitStatus
argument_list|()
operator|!=
name|QProcess
operator|::
name|CrashExit
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// S stands for thread Safe.
end_comment
begin_class
DECL|class|SPointer
class|class
name|SPointer
block|{
public|public:
DECL|member|count
specifier|static
name|QBasicAtomicInt
name|count
decl_stmt|;
DECL|function|SPointer
specifier|inline
name|SPointer
parameter_list|()
block|{
name|count
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
DECL|function|~SPointer
specifier|inline
name|~
name|SPointer
parameter_list|()
block|{
name|count
operator|.
name|deref
argument_list|()
expr_stmt|;
block|}
DECL|function|SPointer
specifier|inline
name|SPointer
parameter_list|(
specifier|const
name|SPointer
modifier|&
comment|/* other */
parameter_list|)
block|{
name|count
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_decl_stmt
DECL|member|count
name|QBasicAtomicInt
name|SPointer
operator|::
name|count
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QThreadStorage<SPointer *>
argument_list|,
argument|threadStoragePointers1
argument_list|)
end_macro
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QThreadStorage<SPointer *>
argument_list|,
argument|threadStoragePointers2
argument_list|)
end_macro
begin_class
DECL|class|ThreadStorageLocalDataTester
class|class
name|ThreadStorageLocalDataTester
block|{
public|public:
DECL|member|member
name|SPointer
name|member
decl_stmt|;
DECL|function|~ThreadStorageLocalDataTester
specifier|inline
name|~
name|ThreadStorageLocalDataTester
parameter_list|()
block|{
name|QVERIFY
argument_list|(
operator|!
name|threadStoragePointers1
argument_list|()
operator|->
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|threadStoragePointers2
argument_list|()
operator|->
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|threadStoragePointers2
argument_list|()
operator|->
name|setLocalData
argument_list|(
operator|new
name|SPointer
argument_list|)
expr_stmt|;
name|threadStoragePointers1
argument_list|()
operator|->
name|setLocalData
argument_list|(
operator|new
name|SPointer
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|threadStoragePointers1
argument_list|()
operator|->
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|threadStoragePointers2
argument_list|()
operator|->
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|leakInDestructor
name|void
name|tst_QThreadStorage
operator|::
name|leakInDestructor
parameter_list|()
block|{
class|class
name|Thread
super|:
specifier|public
name|QThread
block|{
public|public:
name|QThreadStorage
argument_list|<
name|ThreadStorageLocalDataTester
modifier|*
argument_list|>
modifier|&
name|tls
decl_stmt|;
name|Thread
parameter_list|(
name|QThreadStorage
argument_list|<
name|ThreadStorageLocalDataTester
modifier|*
argument_list|>
modifier|&
name|t
parameter_list|)
member_init_list|:
name|tls
argument_list|(
name|t
argument_list|)
block|{ }
name|void
name|run
parameter_list|()
block|{
name|QVERIFY
argument_list|(
operator|!
name|tls
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|tls
operator|.
name|setLocalData
argument_list|(
operator|new
name|ThreadStorageLocalDataTester
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|tls
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
class|;
name|int
name|c
init|=
name|SPointer
operator|::
name|count
operator|.
name|load
argument_list|()
decl_stmt|;
name|QThreadStorage
argument_list|<
name|ThreadStorageLocalDataTester
modifier|*
argument_list|>
name|tls
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|threadStoragePointers1
argument_list|()
operator|->
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|QThreadStorage
argument_list|<
name|int
modifier|*
argument_list|>
name|tls2
decl_stmt|;
comment|//add some more tls to make sure ids are not following each other too much
name|QThreadStorage
argument_list|<
name|int
modifier|*
argument_list|>
name|tls3
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|tls2
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|tls3
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|tls
operator|.
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|Thread
name|t1
argument_list|(
name|tls
argument_list|)
decl_stmt|;
name|Thread
name|t2
argument_list|(
name|tls
argument_list|)
decl_stmt|;
name|Thread
name|t3
argument_list|(
name|tls
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
name|QVERIFY
argument_list|(
name|t1
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t2
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t3
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
comment|//check all the constructed things have been destructed
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|SPointer
operator|::
name|count
operator|.
name|load
argument_list|()
argument_list|)
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|ThreadStorageResetLocalDataTester
class|class
name|ThreadStorageResetLocalDataTester
block|{
public|public:
DECL|member|member
name|SPointer
name|member
decl_stmt|;
name|~
name|ThreadStorageResetLocalDataTester
parameter_list|()
destructor_decl|;
block|}
class|;
end_class
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QThreadStorage<ThreadStorageResetLocalDataTester *>
argument_list|,
argument|ThreadStorageResetLocalDataTesterTls
argument_list|)
end_macro
begin_destructor
DECL|function|~ThreadStorageResetLocalDataTester
name|ThreadStorageResetLocalDataTester
operator|::
name|~
name|ThreadStorageResetLocalDataTester
parameter_list|()
block|{
comment|//Quite stupid, but WTF::ThreadSpecific<T>::destroy does it.
name|ThreadStorageResetLocalDataTesterTls
argument_list|()
operator|->
name|setLocalData
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|resetInDestructor
name|void
name|tst_QThreadStorage
operator|::
name|resetInDestructor
parameter_list|()
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
name|QVERIFY
argument_list|(
operator|!
name|ThreadStorageResetLocalDataTesterTls
argument_list|()
operator|->
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
name|ThreadStorageResetLocalDataTesterTls
argument_list|()
operator|->
name|setLocalData
argument_list|(
operator|new
name|ThreadStorageResetLocalDataTester
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|ThreadStorageResetLocalDataTesterTls
argument_list|()
operator|->
name|hasLocalData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
class|;
name|int
name|c
init|=
name|SPointer
operator|::
name|count
operator|.
name|load
argument_list|()
decl_stmt|;
name|Thread
name|t1
decl_stmt|;
name|Thread
name|t2
decl_stmt|;
name|Thread
name|t3
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
name|QVERIFY
argument_list|(
name|t1
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t2
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t3
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
comment|//check all the constructed things have been destructed
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|SPointer
operator|::
name|count
operator|.
name|load
argument_list|()
argument_list|)
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|valueBased
name|void
name|tst_QThreadStorage
operator|::
name|valueBased
parameter_list|()
block|{
struct|struct
name|Thread
super|:
name|QThread
block|{
name|QThreadStorage
argument_list|<
name|SPointer
argument_list|>
modifier|&
name|tlsSPointer
decl_stmt|;
name|QThreadStorage
argument_list|<
name|QString
argument_list|>
modifier|&
name|tlsString
decl_stmt|;
name|QThreadStorage
argument_list|<
name|int
argument_list|>
modifier|&
name|tlsInt
decl_stmt|;
name|int
name|someNumber
decl_stmt|;
name|QString
name|someString
decl_stmt|;
name|Thread
parameter_list|(
name|QThreadStorage
argument_list|<
name|SPointer
argument_list|>
modifier|&
name|t1
parameter_list|,
name|QThreadStorage
argument_list|<
name|QString
argument_list|>
modifier|&
name|t2
parameter_list|,
name|QThreadStorage
argument_list|<
name|int
argument_list|>
modifier|&
name|t3
parameter_list|)
member_init_list|:
name|tlsSPointer
argument_list|(
name|t1
argument_list|)
member_init_list|,
name|tlsString
argument_list|(
name|t2
argument_list|)
member_init_list|,
name|tlsInt
argument_list|(
name|t3
argument_list|)
block|{ }
name|void
name|run
parameter_list|()
block|{
comment|/*QVERIFY(!tlsSPointer.hasLocalData());             QVERIFY(!tlsString.hasLocalData());             QVERIFY(!tlsInt.hasLocalData());*/
name|SPointer
name|pointercopy
init|=
name|tlsSPointer
operator|.
name|localData
argument_list|()
decl_stmt|;
comment|//Default constructed values
name|QVERIFY
argument_list|(
name|tlsString
operator|.
name|localData
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tlsInt
operator|.
name|localData
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|//setting
name|tlsString
operator|.
name|setLocalData
argument_list|(
name|someString
argument_list|)
expr_stmt|;
name|tlsInt
operator|.
name|setLocalData
argument_list|(
name|someNumber
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tlsString
operator|.
name|localData
argument_list|()
argument_list|,
name|someString
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tlsInt
operator|.
name|localData
argument_list|()
argument_list|,
name|someNumber
argument_list|)
expr_stmt|;
comment|//changing
name|tlsSPointer
operator|.
name|setLocalData
argument_list|(
name|SPointer
argument_list|()
argument_list|)
expr_stmt|;
name|tlsInt
operator|.
name|localData
argument_list|()
operator|+=
literal|42
expr_stmt|;
name|tlsString
operator|.
name|localData
argument_list|()
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|" world"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tlsString
operator|.
name|localData
argument_list|()
argument_list|,
operator|(
name|someString
operator|+
name|QLatin1String
argument_list|(
literal|" world"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tlsInt
operator|.
name|localData
argument_list|()
argument_list|,
operator|(
name|someNumber
operator|+
literal|42
operator|)
argument_list|)
expr_stmt|;
comment|// operator=
name|tlsString
operator|.
name|localData
argument_list|()
operator|=
name|QString
operator|::
name|number
argument_list|(
name|someNumber
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tlsString
operator|.
name|localData
argument_list|()
operator|.
name|toInt
argument_list|()
argument_list|,
name|someNumber
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
name|QThreadStorage
argument_list|<
name|SPointer
argument_list|>
name|tlsSPointer
decl_stmt|;
name|QThreadStorage
argument_list|<
name|QString
argument_list|>
name|tlsString
decl_stmt|;
name|QThreadStorage
argument_list|<
name|int
argument_list|>
name|tlsInt
decl_stmt|;
name|int
name|c
init|=
name|SPointer
operator|::
name|count
operator|.
name|load
argument_list|()
decl_stmt|;
name|Thread
name|t1
argument_list|(
name|tlsSPointer
argument_list|,
name|tlsString
argument_list|,
name|tlsInt
argument_list|)
decl_stmt|;
name|Thread
name|t2
argument_list|(
name|tlsSPointer
argument_list|,
name|tlsString
argument_list|,
name|tlsInt
argument_list|)
decl_stmt|;
name|Thread
name|t3
argument_list|(
name|tlsSPointer
argument_list|,
name|tlsString
argument_list|,
name|tlsInt
argument_list|)
decl_stmt|;
name|t1
operator|.
name|someNumber
operator|=
literal|42
expr_stmt|;
name|t2
operator|.
name|someNumber
operator|=
operator|-
literal|128
expr_stmt|;
name|t3
operator|.
name|someNumber
operator|=
literal|78
expr_stmt|;
name|t1
operator|.
name|someString
operator|=
literal|"hello"
expr_stmt|;
name|t2
operator|.
name|someString
operator|=
literal|"trolltech"
expr_stmt|;
name|t3
operator|.
name|someString
operator|=
literal|"nokia"
expr_stmt|;
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
name|QVERIFY
argument_list|(
name|t1
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t2
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t3
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|c
argument_list|,
name|int
argument_list|(
name|SPointer
operator|::
name|count
operator|.
name|load
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QThreadStorage
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qthreadstorage.moc"
end_include
end_unit
