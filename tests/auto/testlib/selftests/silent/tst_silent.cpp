begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
DECL|class|tst_Silent
class|class
name|tst_Silent
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
begin_function
DECL|function|pass
name|void
name|tst_Silent
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
name|tst_Silent
operator|::
name|skip
parameter_list|()
block|{
name|QSKIP
argument_list|(
literal|"This test should skip"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fail
name|void
name|tst_Silent
operator|::
name|fail
parameter_list|()
block|{
name|QVERIFY2
argument_list|(
literal|false
argument_list|,
literal|"This test should fail"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|xfail
name|void
name|tst_Silent
operator|::
name|xfail
parameter_list|()
block|{
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"This test should XFAIL"
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
name|tst_Silent
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
literal|"This test should XPASS"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|messages
name|void
name|tst_Silent
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
argument|tst_Silent
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_silent.moc"
end_include
end_unit
