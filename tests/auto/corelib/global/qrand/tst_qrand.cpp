begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QRand
class|class
name|tst_QRand
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|testqrand
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|testqrand
name|void
name|tst_QRand
operator|::
name|testqrand
parameter_list|()
block|{
specifier|const
name|int
name|numTestValues
init|=
literal|100
decl_stmt|;
name|int
name|generatedNumbers
index|[
name|numTestValues
index|]
decl_stmt|;
name|bool
name|generatesSameSequence
init|=
literal|true
decl_stmt|;
comment|// test without calling srand() first
comment|// should give same sequence as with srand(1)
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numTestValues
condition|;
operator|++
name|i
control|)
name|generatedNumbers
index|[
name|i
index|]
operator|=
name|qrand
argument_list|()
expr_stmt|;
name|qsrand
argument_list|(
literal|1
argument_list|)
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
name|numTestValues
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|generatedNumbers
index|[
name|i
index|]
operator|!=
name|qrand
argument_list|()
condition|)
name|generatesSameSequence
operator|=
literal|false
expr_stmt|;
name|QVERIFY
argument_list|(
name|generatesSameSequence
argument_list|)
expr_stmt|;
for|for
control|(
name|unsigned
name|int
name|seed
init|=
literal|1
init|;
name|seed
operator|<
literal|10
condition|;
name|seed
operator|+=
literal|100
control|)
block|{
name|qsrand
argument_list|(
name|seed
argument_list|)
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
name|numTestValues
condition|;
operator|++
name|i
control|)
name|generatedNumbers
index|[
name|i
index|]
operator|=
name|qrand
argument_list|()
expr_stmt|;
name|qsrand
argument_list|(
name|seed
argument_list|)
expr_stmt|;
name|generatesSameSequence
operator|=
literal|true
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
name|numTestValues
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|generatedNumbers
index|[
name|i
index|]
operator|!=
name|qrand
argument_list|()
condition|)
name|generatesSameSequence
operator|=
literal|false
expr_stmt|;
name|QVERIFY
argument_list|(
name|generatesSameSequence
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QRand
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qrand.moc"
end_include
end_unit
