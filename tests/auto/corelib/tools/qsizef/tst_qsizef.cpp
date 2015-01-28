begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qsize.h>
end_include
begin_class
DECL|class|tst_QSizeF
class|class
name|tst_QSizeF
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|isNull_data
parameter_list|()
function_decl|;
name|void
name|isNull
parameter_list|()
function_decl|;
name|void
name|scale
parameter_list|()
function_decl|;
name|void
name|expandedTo
parameter_list|()
function_decl|;
name|void
name|expandedTo_data
parameter_list|()
function_decl|;
name|void
name|boundedTo_data
parameter_list|()
function_decl|;
name|void
name|boundedTo
parameter_list|()
function_decl|;
name|void
name|transpose_data
parameter_list|()
function_decl|;
name|void
name|transpose
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|isNull_data
name|void
name|tst_QSizeF
operator|::
name|isNull_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"width"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"height"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"isNull"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0, 0"
argument_list|)
operator|<<
name|qreal
argument_list|(
literal|0.0
argument_list|)
operator|<<
name|qreal
argument_list|(
literal|0.0
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"-0, -0"
argument_list|)
operator|<<
name|qreal
argument_list|(
operator|-
literal|0.0
argument_list|)
operator|<<
name|qreal
argument_list|(
operator|-
literal|0.0
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0, -0"
argument_list|)
operator|<<
name|qreal
argument_list|(
literal|0
argument_list|)
operator|<<
name|qreal
argument_list|(
operator|-
literal|0.0
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"-0, 0"
argument_list|)
operator|<<
name|qreal
argument_list|(
operator|-
literal|0.0
argument_list|)
operator|<<
name|qreal
argument_list|(
literal|0
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"-0.1, 0"
argument_list|)
operator|<<
name|qreal
argument_list|(
operator|-
literal|0.1
argument_list|)
operator|<<
name|qreal
argument_list|(
literal|0
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0, -0.1"
argument_list|)
operator|<<
name|qreal
argument_list|(
literal|0
argument_list|)
operator|<<
name|qreal
argument_list|(
operator|-
literal|0.1
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0.1, 0"
argument_list|)
operator|<<
name|qreal
argument_list|(
literal|0.1
argument_list|)
operator|<<
name|qreal
argument_list|(
literal|0
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0, 0.1"
argument_list|)
operator|<<
name|qreal
argument_list|(
literal|0
argument_list|)
operator|<<
name|qreal
argument_list|(
literal|0.1
argument_list|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isNull
name|void
name|tst_QSizeF
operator|::
name|isNull
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|width
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|height
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isNull
argument_list|)
expr_stmt|;
name|QSizeF
name|size
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|width
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|size
operator|.
name|height
argument_list|()
argument_list|,
name|height
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|size
operator|.
name|isNull
argument_list|()
argument_list|,
name|isNull
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scale
name|void
name|tst_QSizeF
operator|::
name|scale
parameter_list|()
block|{
name|QSizeF
name|t1
argument_list|(
literal|10.4
argument_list|,
literal|12.8
argument_list|)
decl_stmt|;
name|t1
operator|.
name|scale
argument_list|(
literal|60.6
argument_list|,
literal|60.6
argument_list|,
name|Qt
operator|::
name|IgnoreAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t1
argument_list|,
name|QSizeF
argument_list|(
literal|60.6
argument_list|,
literal|60.6
argument_list|)
argument_list|)
expr_stmt|;
name|QSizeF
name|t2
argument_list|(
literal|10.4
argument_list|,
literal|12.8
argument_list|)
decl_stmt|;
name|t2
operator|.
name|scale
argument_list|(
literal|43.52
argument_list|,
literal|43.52
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t2
argument_list|,
name|QSizeF
argument_list|(
literal|35.36
argument_list|,
literal|43.52
argument_list|)
argument_list|)
expr_stmt|;
name|QSizeF
name|t3
argument_list|(
literal|9.6
argument_list|,
literal|12.48
argument_list|)
decl_stmt|;
name|t3
operator|.
name|scale
argument_list|(
literal|31.68
argument_list|,
literal|31.68
argument_list|,
name|Qt
operator|::
name|KeepAspectRatioByExpanding
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t3
argument_list|,
name|QSizeF
argument_list|(
literal|31.68
argument_list|,
literal|41.184
argument_list|)
argument_list|)
expr_stmt|;
name|QSizeF
name|t4
argument_list|(
literal|12.8
argument_list|,
literal|10.4
argument_list|)
decl_stmt|;
name|t4
operator|.
name|scale
argument_list|(
literal|43.52
argument_list|,
literal|43.52
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t4
argument_list|,
name|QSizeF
argument_list|(
literal|43.52
argument_list|,
literal|35.36
argument_list|)
argument_list|)
expr_stmt|;
name|QSizeF
name|t5
argument_list|(
literal|12.48
argument_list|,
literal|9.6
argument_list|)
decl_stmt|;
name|t5
operator|.
name|scale
argument_list|(
literal|31.68
argument_list|,
literal|31.68
argument_list|,
name|Qt
operator|::
name|KeepAspectRatioByExpanding
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t5
argument_list|,
name|QSizeF
argument_list|(
literal|41.184
argument_list|,
literal|31.68
argument_list|)
argument_list|)
expr_stmt|;
name|QSizeF
name|t6
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
decl_stmt|;
name|t6
operator|.
name|scale
argument_list|(
literal|200
argument_list|,
literal|240
argument_list|,
name|Qt
operator|::
name|IgnoreAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t6
argument_list|,
name|QSizeF
argument_list|(
literal|200
argument_list|,
literal|240
argument_list|)
argument_list|)
expr_stmt|;
name|QSizeF
name|t7
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
decl_stmt|;
name|t7
operator|.
name|scale
argument_list|(
literal|200
argument_list|,
literal|240
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t7
argument_list|,
name|QSizeF
argument_list|(
literal|200
argument_list|,
literal|240
argument_list|)
argument_list|)
expr_stmt|;
name|QSizeF
name|t8
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
decl_stmt|;
name|t8
operator|.
name|scale
argument_list|(
literal|200
argument_list|,
literal|240
argument_list|,
name|Qt
operator|::
name|KeepAspectRatioByExpanding
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t8
argument_list|,
name|QSizeF
argument_list|(
literal|200
argument_list|,
literal|240
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|expandedTo_data
name|void
name|tst_QSizeF
operator|::
name|expandedTo_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"input1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"input2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|10.4
argument_list|,
literal|12.8
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|6.6
argument_list|,
literal|4.4
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|10.4
argument_list|,
literal|12.8
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|6.6
argument_list|,
literal|4.4
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|6.6
argument_list|,
literal|4.4
argument_list|)
expr_stmt|;
comment|// This should pick the highest of w,h components independently of each other,
comment|// thus the result don't have to be equal to neither input1 nor input2.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|6.6
argument_list|,
literal|4.4
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|4.4
argument_list|,
literal|6.6
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|6.6
argument_list|,
literal|6.6
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|expandedTo
name|void
name|tst_QSizeF
operator|::
name|expandedTo
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|input1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|input2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|input1
operator|.
name|expandedTo
argument_list|(
name|input2
argument_list|)
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|boundedTo_data
name|void
name|tst_QSizeF
operator|::
name|boundedTo_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"input1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"input2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|10.4
argument_list|,
literal|12.8
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|6.6
argument_list|,
literal|4.4
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|6.6
argument_list|,
literal|4.4
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|6.6
argument_list|,
literal|4.4
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
comment|// This should pick the lowest of w,h components independently of each other,
comment|// thus the result don't have to be equal to neither input1 nor input2.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|6.6
argument_list|,
literal|4.4
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|4.4
argument_list|,
literal|6.6
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|4.4
argument_list|,
literal|4.4
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|boundedTo
name|void
name|tst_QSizeF
operator|::
name|boundedTo
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|input1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|input2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|input1
operator|.
name|boundedTo
argument_list|(
name|input2
argument_list|)
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|transpose_data
name|void
name|tst_QSizeF
operator|::
name|transpose_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"input1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|10.4
argument_list|,
literal|12.8
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|12.8
argument_list|,
literal|10.4
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|6.6
argument_list|,
literal|4.4
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|4.4
argument_list|,
literal|6.6
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|transpose
name|void
name|tst_QSizeF
operator|::
name|transpose
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|input1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|expected
argument_list|)
expr_stmt|;
comment|// transpose() works only inplace and does not return anything, so we must do the operation itself before the compare.
name|input1
operator|.
name|transpose
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|input1
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QSizeF
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsizef.moc"
end_include
end_unit
