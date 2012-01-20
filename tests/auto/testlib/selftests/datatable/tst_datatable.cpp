begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_comment
comment|/*!  \internal  \since 4.4  \brief Tests that reporting of tables are done in a certain way.  */
end_comment
begin_class
DECL|class|tst_DataTable
class|class
name|tst_DataTable
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|singleTestFunction1
parameter_list|()
specifier|const
function_decl|;
name|void
name|singleTestFunction2
parameter_list|()
specifier|const
function_decl|;
name|void
name|fiveTablePasses
parameter_list|()
specifier|const
function_decl|;
name|void
name|fiveTablePasses_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|fiveTableFailures
parameter_list|()
specifier|const
function_decl|;
name|void
name|fiveTableFailures_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|startsWithFailure
parameter_list|()
specifier|const
function_decl|;
name|void
name|startsWithFailure_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|endsWithFailure
parameter_list|()
specifier|const
function_decl|;
name|void
name|endsWithFailure_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|failureInMiddle
parameter_list|()
specifier|const
function_decl|;
name|void
name|failureInMiddle_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|fiveIsolatedFailures
parameter_list|()
specifier|const
function_decl|;
name|void
name|fiveIsolatedFailures_data
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|singleTestFunction1
name|void
name|tst_DataTable
operator|::
name|singleTestFunction1
parameter_list|()
specifier|const
block|{
comment|/* Do nothing, just pass. */
block|}
end_function
begin_function
DECL|function|singleTestFunction2
name|void
name|tst_DataTable
operator|::
name|singleTestFunction2
parameter_list|()
specifier|const
block|{
comment|/* Do nothing, just pass. */
block|}
end_function
begin_function
DECL|function|fiveTableFailures
name|void
name|tst_DataTable
operator|::
name|fiveTableFailures
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|test
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|test
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fiveTableFailures_data
name|void
name|tst_DataTable
operator|::
name|fiveTableFailures_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"test"
argument_list|)
expr_stmt|;
comment|/* Unconditionally fail. */
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveTableFailures_data 1"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveTableFailures_data 2"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveTableFailures_data 3"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveTableFailures_data 4"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveTableFailures_data 5"
argument_list|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startsWithFailure
name|void
name|tst_DataTable
operator|::
name|startsWithFailure
parameter_list|()
specifier|const
block|{
name|fiveTableFailures
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fiveTablePasses
name|void
name|tst_DataTable
operator|::
name|fiveTablePasses
parameter_list|()
specifier|const
block|{
name|fiveTableFailures
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fiveTablePasses_data
name|void
name|tst_DataTable
operator|::
name|fiveTablePasses_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"test"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveTablePasses_data 1"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveTablePasses_data 2"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveTablePasses_data 3"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveTablePasses_data 4"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveTablePasses_data 5"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startsWithFailure_data
name|void
name|tst_DataTable
operator|::
name|startsWithFailure_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"test"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"startsWithFailure_data 1"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"startsWithFailure_data 2"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"startsWithFailure_data 3"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"startsWithFailure_data 4"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"startsWithFailure_data 5"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endsWithFailure
name|void
name|tst_DataTable
operator|::
name|endsWithFailure
parameter_list|()
specifier|const
block|{
name|fiveTableFailures
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endsWithFailure_data
name|void
name|tst_DataTable
operator|::
name|endsWithFailure_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"test"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"endsWithFailure 1"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"endsWithFailure 2"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"endsWithFailure 3"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"endsWithFailure 4"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"endsWithFailure 5"
argument_list|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|failureInMiddle
name|void
name|tst_DataTable
operator|::
name|failureInMiddle
parameter_list|()
specifier|const
block|{
name|fiveTableFailures
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|failureInMiddle_data
name|void
name|tst_DataTable
operator|::
name|failureInMiddle_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"test"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"failureInMiddle_data 1"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"failureInMiddle_data 2"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"failureInMiddle_data 3"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"failureInMiddle_data 4"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"failureInMiddle_data 5"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fiveIsolatedFailures
name|void
name|tst_DataTable
operator|::
name|fiveIsolatedFailures
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|test
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|test
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fiveIsolatedFailures_data
name|void
name|tst_DataTable
operator|::
name|fiveIsolatedFailures_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"test"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveIsolatedFailures_data 1"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveIsolatedFailures_data 2"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveIsolatedFailures_data 3"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveIsolatedFailures_data 4"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fiveIsolatedFailures_data 5"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_DataTable
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_datatable.moc"
end_include
end_unit
