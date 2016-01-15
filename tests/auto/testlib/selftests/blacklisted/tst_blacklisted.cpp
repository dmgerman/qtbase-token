begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<private/qtestlog_p.h>
end_include
begin_class
DECL|class|tst_Blacklisted
class|class
name|tst_Blacklisted
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|pass
parameter_list|()
function_decl|;
name|void
name|skip
parameter_list|()
function_decl|;
name|void
name|fail
parameter_list|()
function_decl|;
name|void
name|xfail
parameter_list|()
function_decl|;
name|void
name|xpass
parameter_list|()
function_decl|;
comment|// This test function must be last, as it calls qFatal().
name|void
name|messages
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// All the tests below have been blacklisted in blacklisted/BLACKLIST
end_comment
begin_function
DECL|function|pass
name|void
name|tst_Blacklisted
operator|::
name|pass
parameter_list|()
block|{
name|QVERIFY
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|skip
name|void
name|tst_Blacklisted
operator|::
name|skip
parameter_list|()
block|{
name|QSKIP
argument_list|(
literal|"This test should SKIP"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fail
name|void
name|tst_Blacklisted
operator|::
name|fail
parameter_list|()
block|{
name|QVERIFY2
argument_list|(
literal|false
argument_list|,
literal|"This test should BFAIL"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xfail
name|void
name|tst_Blacklisted
operator|::
name|xfail
parameter_list|()
block|{
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"This test should XFAIL then BFAIL"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xpass
name|void
name|tst_Blacklisted
operator|::
name|xpass
parameter_list|()
block|{
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"This test should XPASS"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
literal|true
argument_list|,
literal|"This test should XPASS, blacklist ignored for XPASS"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|messages
name|void
name|tst_Blacklisted
operator|::
name|messages
parameter_list|()
block|{
name|qWarning
argument_list|(
literal|"This is a warning that should not appear in silent test output"
argument_list|)
expr_stmt|;
name|QWARN
argument_list|(
literal|"This is an internal testlib warning that should not appear in silent test output"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"This is a debug message that should not appear in silent test output"
argument_list|)
expr_stmt|;
name|qCritical
argument_list|(
literal|"This is a critical message that should not appear in silent test output"
argument_list|)
expr_stmt|;
name|qInfo
argument_list|(
literal|"This is an info message that should not appear in silent test output"
argument_list|)
expr_stmt|;
name|QTestLog
operator|::
name|info
argument_list|(
literal|"This is an internal testlib info message that should not appear in silent test output"
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"This is a fatal error message that should still appear in silent test output"
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_Blacklisted
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_blacklisted.moc"
end_include
end_unit
