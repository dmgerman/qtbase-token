begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_Skip
class|class
name|tst_Skip
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|test_data
parameter_list|()
function_decl|;
name|void
name|test
parameter_list|()
function_decl|;
name|void
name|emptytest_data
parameter_list|()
function_decl|;
name|void
name|emptytest
parameter_list|()
function_decl|;
name|void
name|singleSkip_data
parameter_list|()
function_decl|;
name|void
name|singleSkip
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|test_data
name|void
name|tst_Skip
operator|::
name|test_data
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
literal|"skipping all"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|test
name|void
name|tst_Skip
operator|::
name|test
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"this line should never be reached, since we skip in the _data function"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|emptytest_data
name|void
name|tst_Skip
operator|::
name|emptytest_data
parameter_list|()
block|{
name|QSKIP
argument_list|(
literal|"skipping all"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|emptytest
name|void
name|tst_Skip
operator|::
name|emptytest
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"this line should never be reached, since we skip in the _data function"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|singleSkip_data
name|void
name|tst_Skip
operator|::
name|singleSkip_data
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
DECL|function|singleSkip
name|void
name|tst_Skip
operator|::
name|singleSkip
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|booll
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|booll
condition|)
name|QSKIP
argument_list|(
literal|"skipping one"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"this line should only be reached once (%s)"
argument_list|,
name|booll
condition|?
literal|"true"
else|:
literal|"false"
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_Skip
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_skip.moc"
end_include
end_unit
