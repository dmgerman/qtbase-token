begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QProcess>
end_include
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_include
include|#
directive|include
file|<QtTest>
end_include
begin_class
DECL|class|tst_QProcessNoApplication
class|class
name|tst_QProcessNoApplication
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|Q_SLOTS
private|:
name|void
name|initializationDeadlock
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initializationDeadlock
name|void
name|tst_QProcessNoApplication
operator|::
name|initializationDeadlock
parameter_list|()
block|{
comment|// see QTBUG-27260
comment|// QProcess on Unix uses (or used to, at the time of the writing of this test)
comment|// a global class called QProcessManager.
comment|// This class is instantiated (or was) only in the main thread, which meant that
comment|// blocking the main thread while waiting for QProcess could mean a deadlock.
struct|struct
name|MyThread
super|:
specifier|public
name|QThread
block|{
name|void
name|run
parameter_list|()
block|{
comment|// what we execute does not matter, as long as we try to
comment|// and that the process exits
name|QProcess
operator|::
name|execute
argument_list|(
literal|"true"
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
name|char
modifier|*
name|argv
index|[]
init|=
block|{
cast|const_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|QTest
operator|::
name|currentAppName
argument_list|()
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
name|int
name|argc
init|=
literal|1
decl_stmt|;
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|MyThread
name|thread
decl_stmt|;
name|thread
operator|.
name|start
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
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QProcessNoApplication
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qprocessnoapplication.moc"
end_include
end_unit
