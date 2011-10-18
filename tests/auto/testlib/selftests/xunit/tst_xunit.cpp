begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_Xunit
class|class
name|tst_Xunit
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_Xunit
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|testFunc1
parameter_list|()
function_decl|;
name|void
name|testFunc2
parameter_list|()
function_decl|;
name|void
name|testFunc3
parameter_list|()
function_decl|;
name|void
name|testFunc4
parameter_list|()
function_decl|;
name|void
name|testFunc5
parameter_list|()
function_decl|;
name|void
name|testFunc6
parameter_list|()
function_decl|;
name|void
name|testFunc7
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_Xunit
name|tst_Xunit
operator|::
name|tst_Xunit
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|testFunc1
name|void
name|tst_Xunit
operator|::
name|testFunc1
parameter_list|()
block|{
name|QWARN
argument_list|(
literal|"just a QWARN() !"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testFunc2
name|void
name|tst_Xunit
operator|::
name|testFunc2
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"a qDebug() call with comment-ending stuff -->"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testFunc3
name|void
name|tst_Xunit
operator|::
name|testFunc3
parameter_list|()
block|{
name|QSKIP
argument_list|(
literal|"skipping this function!"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testFunc4
name|void
name|tst_Xunit
operator|::
name|testFunc4
parameter_list|()
block|{
name|QFAIL
argument_list|(
literal|"a forced failure!"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Note there are two testfunctions which give expected failures.     This is so we can test that expected failures don't add to failure     counts and unexpected passes do.  If we had one xfail and one xpass     testfunction, we couldn't test which one of them adds to the failure     count. */
end_comment
begin_function
DECL|function|testFunc5
name|void
name|tst_Xunit
operator|::
name|testFunc5
parameter_list|()
block|{
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"this failure is expected"
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
DECL|function|testFunc6
name|void
name|tst_Xunit
operator|::
name|testFunc6
parameter_list|()
block|{
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"this failure is also expected"
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
DECL|function|testFunc7
name|void
name|tst_Xunit
operator|::
name|testFunc7
parameter_list|()
block|{
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"this pass is unexpected"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_Xunit
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_xunit.moc"
end_include
end_unit
