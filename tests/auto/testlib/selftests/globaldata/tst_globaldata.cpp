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
file|<QDebug>
end_include
begin_class
DECL|class|tst_globaldata
class|class
name|tst_globaldata
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public
name|slots
public|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|initTestCase_data
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|testGlobal_data
parameter_list|()
function_decl|;
name|void
name|testGlobal
parameter_list|()
function_decl|;
name|void
name|skip_data
parameter_list|()
function_decl|;
name|void
name|skip
parameter_list|()
function_decl|;
DECL|function|skipLocal_data
name|void
name|skipLocal_data
parameter_list|()
block|{
name|testGlobal_data
argument_list|()
expr_stmt|;
block|}
name|void
name|skipLocal
parameter_list|()
function_decl|;
DECL|function|skipSingle_data
name|void
name|skipSingle_data
parameter_list|()
block|{
name|testGlobal_data
argument_list|()
expr_stmt|;
block|}
name|void
name|skipSingle
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_globaldata
operator|::
name|initTestCase
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"initTestCase"
operator|<<
operator|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTest
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"(null)"
operator|)
operator|<<
operator|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTest
operator|::
name|currentDataTag
argument_list|()
else|:
literal|"(null)"
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initTestCase_data
name|void
name|tst_globaldata
operator|::
name|initTestCase_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"booli"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_globaldata
operator|::
name|cleanupTestCase
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"cleanupTestCase"
operator|<<
operator|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTest
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"(null)"
operator|)
operator|<<
operator|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTest
operator|::
name|currentDataTag
argument_list|()
else|:
literal|"(null)"
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_globaldata
operator|::
name|init
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"init"
operator|<<
operator|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTest
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"(null)"
operator|)
operator|<<
operator|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTest
operator|::
name|currentDataTag
argument_list|()
else|:
literal|"(null)"
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_globaldata
operator|::
name|cleanup
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"cleanup"
operator|<<
operator|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTest
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"(null)"
operator|)
operator|<<
operator|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTest
operator|::
name|currentDataTag
argument_list|()
else|:
literal|"(null)"
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testGlobal_data
name|void
name|tst_globaldata
operator|::
name|testGlobal_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"booll"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"local 1"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"local 2"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testGlobal
name|void
name|tst_globaldata
operator|::
name|testGlobal
parameter_list|()
block|{
name|QFETCH_GLOBAL
argument_list|(
name|bool
argument_list|,
name|booli
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"global:"
operator|<<
name|booli
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|booll
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"local:"
operator|<<
name|booll
expr_stmt|;
block|}
end_function
begin_function
DECL|function|skip_data
name|void
name|tst_globaldata
operator|::
name|skip_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"booll"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"local 1"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"local 2"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QSKIP
argument_list|(
literal|"skipping"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|skip
name|void
name|tst_globaldata
operator|::
name|skip
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"this line should never be reached"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|skipSingle
name|void
name|tst_globaldata
operator|::
name|skipSingle
parameter_list|()
block|{
name|QFETCH_GLOBAL
argument_list|(
name|bool
argument_list|,
name|booli
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|booll
argument_list|)
expr_stmt|;
if|if
condition|(
name|booli
operator|&&
operator|!
name|booll
condition|)
name|QSKIP
argument_list|(
literal|"skipping"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"global:"
operator|<<
name|booli
operator|<<
literal|"local:"
operator|<<
name|booll
expr_stmt|;
block|}
end_function
begin_function
DECL|function|skipLocal
name|void
name|tst_globaldata
operator|::
name|skipLocal
parameter_list|()
block|{
name|QSKIP
argument_list|(
literal|"skipping"
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_globaldata
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_globaldata.moc"
end_include
end_unit
