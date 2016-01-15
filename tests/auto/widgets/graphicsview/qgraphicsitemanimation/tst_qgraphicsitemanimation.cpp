begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qgraphicsitemanimation.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtimeline.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qmatrix.h>
end_include
begin_class
DECL|class|tst_QGraphicsItemAnimation
class|class
name|tst_QGraphicsItemAnimation
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|construction
parameter_list|()
function_decl|;
name|void
name|linearMove
parameter_list|()
function_decl|;
name|void
name|linearRotation
parameter_list|()
function_decl|;
name|void
name|checkReturnedLists
parameter_list|()
function_decl|;
name|void
name|overwriteValueForStep
parameter_list|()
function_decl|;
name|void
name|setTimeLine
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|construction
name|void
name|tst_QGraphicsItemAnimation
operator|::
name|construction
parameter_list|()
block|{
name|QGraphicsItemAnimation
name|animation
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|animation
operator|.
name|item
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|animation
operator|.
name|timeLine
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|posAt
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QPointF
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|posAt
argument_list|(
literal|0.5
argument_list|)
argument_list|,
name|QPointF
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|posAt
argument_list|(
literal|1
argument_list|)
argument_list|,
name|QPointF
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|matrixAt
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QMatrix
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|matrixAt
argument_list|(
literal|0.5
argument_list|)
argument_list|,
name|QMatrix
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|matrixAt
argument_list|(
literal|1
argument_list|)
argument_list|,
name|QMatrix
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|rotationAt
argument_list|(
literal|0
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|rotationAt
argument_list|(
literal|0.5
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|rotationAt
argument_list|(
literal|1
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|xTranslationAt
argument_list|(
literal|0
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|xTranslationAt
argument_list|(
literal|0.5
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|xTranslationAt
argument_list|(
literal|1
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|yTranslationAt
argument_list|(
literal|0
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|yTranslationAt
argument_list|(
literal|0.5
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|yTranslationAt
argument_list|(
literal|1
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|verticalScaleAt
argument_list|(
literal|0
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|1.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|horizontalScaleAt
argument_list|(
literal|0
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|1.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|verticalShearAt
argument_list|(
literal|0
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|horizontalShearAt
argument_list|(
literal|0
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|animation
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// don't crash
block|}
end_function
begin_function
DECL|function|linearMove
name|void
name|tst_QGraphicsItemAnimation
operator|::
name|linearMove
parameter_list|()
block|{
name|QGraphicsItemAnimation
name|animation
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
literal|10
condition|;
operator|++
name|i
control|)
block|{
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|posAt
argument_list|(
name|i
operator|/
literal|10.0
argument_list|)
operator|.
name|x
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|posAt
argument_list|(
name|i
operator|/
literal|10.0
argument_list|)
operator|.
name|y
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|animation
operator|.
name|setPosAt
argument_list|(
literal|1
argument_list|,
name|QPointF
argument_list|(
literal|10
argument_list|,
operator|-
literal|10
argument_list|)
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
operator|<=
literal|10
condition|;
operator|++
name|i
control|)
block|{
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|posAt
argument_list|(
name|i
operator|/
literal|10.0
argument_list|)
operator|.
name|x
argument_list|()
argument_list|,
name|qreal
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|posAt
argument_list|(
name|i
operator|/
literal|10.0
argument_list|)
operator|.
name|y
argument_list|()
argument_list|,
name|qreal
argument_list|(
operator|-
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|animation
operator|.
name|setPosAt
argument_list|(
literal|2
argument_list|,
name|QPointF
argument_list|(
literal|10
argument_list|,
operator|-
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|posAt
argument_list|(
literal|11
argument_list|)
operator|.
name|x
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|10
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|linearRotation
name|void
name|tst_QGraphicsItemAnimation
operator|::
name|linearRotation
parameter_list|()
block|{
name|QGraphicsItemAnimation
name|animation
decl_stmt|;
name|animation
operator|.
name|setRotationAt
argument_list|(
literal|1
argument_list|,
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
operator|<=
literal|10
condition|;
operator|++
name|i
control|)
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|rotationAt
argument_list|(
name|i
operator|/
literal|10.0
argument_list|)
argument_list|,
name|qreal
argument_list|(
name|i
operator|/
literal|10.0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkReturnedLists
name|void
name|tst_QGraphicsItemAnimation
operator|::
name|checkReturnedLists
parameter_list|()
block|{
name|QGraphicsItemAnimation
name|animation
decl_stmt|;
name|animation
operator|.
name|setPosAt
argument_list|(
literal|1.0
argument_list|,
name|QPointF
argument_list|(
literal|10
argument_list|,
operator|-
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setPosAt
argument_list|(
literal|0.5
argument_list|,
name|QPointF
argument_list|(
literal|5
argument_list|,
operator|-
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setRotationAt
argument_list|(
literal|0.3
argument_list|,
literal|2.3
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setTranslationAt
argument_list|(
literal|0.3
argument_list|,
literal|15
argument_list|,
literal|15
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setScaleAt
argument_list|(
literal|0.3
argument_list|,
literal|2.5
argument_list|,
literal|1.8
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setShearAt
argument_list|(
literal|0.3
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|posList
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
operator|(
name|QPair
argument_list|<
name|qreal
argument_list|,
name|QPointF
argument_list|>
argument_list|(
literal|0.5
argument_list|,
name|QPointF
argument_list|(
literal|5
argument_list|,
operator|-
literal|5
argument_list|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|posList
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|,
operator|(
name|QPair
argument_list|<
name|qreal
argument_list|,
name|QPointF
argument_list|>
argument_list|(
literal|1.0
argument_list|,
name|QPointF
argument_list|(
literal|10
argument_list|,
operator|-
literal|10
argument_list|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|rotationList
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
operator|(
name|QPair
argument_list|<
name|qreal
argument_list|,
name|qreal
argument_list|>
argument_list|(
literal|0.3
argument_list|,
literal|2.3
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|translationList
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
operator|(
name|QPair
argument_list|<
name|qreal
argument_list|,
name|QPointF
argument_list|>
argument_list|(
literal|0.3
argument_list|,
name|QPointF
argument_list|(
literal|15
argument_list|,
literal|15
argument_list|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|scaleList
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
operator|(
name|QPair
argument_list|<
name|qreal
argument_list|,
name|QPointF
argument_list|>
argument_list|(
literal|0.3
argument_list|,
name|QPointF
argument_list|(
literal|2.5
argument_list|,
literal|1.8
argument_list|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|shearList
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
operator|(
name|QPair
argument_list|<
name|qreal
argument_list|,
name|QPointF
argument_list|>
argument_list|(
literal|0.3
argument_list|,
name|QPointF
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|posList
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|rotationList
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|translationList
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|scaleList
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|shearList
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|overwriteValueForStep
name|void
name|tst_QGraphicsItemAnimation
operator|::
name|overwriteValueForStep
parameter_list|()
block|{
name|QGraphicsItemAnimation
name|animation
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
name|i
operator|++
control|)
block|{
name|animation
operator|.
name|setPosAt
argument_list|(
literal|0.3
argument_list|,
name|QPointF
argument_list|(
literal|3
argument_list|,
operator|-
literal|3.1
argument_list|)
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setRotationAt
argument_list|(
literal|0.3
argument_list|,
literal|2.3
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setTranslationAt
argument_list|(
literal|0.3
argument_list|,
literal|15
argument_list|,
literal|15
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setScaleAt
argument_list|(
literal|0.3
argument_list|,
literal|2.5
argument_list|,
literal|1.8
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setShearAt
argument_list|(
literal|0.3
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|posList
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|rotationList
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|translationList
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|scaleList
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|shearList
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setTimeLine
name|void
name|tst_QGraphicsItemAnimation
operator|::
name|setTimeLine
parameter_list|()
block|{
name|QGraphicsItemAnimation
name|animation
decl_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|timeLine
argument_list|()
argument_list|,
operator|(
name|QTimeLine
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QPointer
argument_list|<
name|QTimeLine
argument_list|>
name|line1
init|=
operator|new
name|QTimeLine
decl_stmt|;
name|animation
operator|.
name|setTimeLine
argument_list|(
name|line1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|timeLine
argument_list|()
argument_list|,
operator|(
name|QTimeLine
operator|*
operator|)
name|line1
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setTimeLine
argument_list|(
name|line1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|line1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|timeLine
argument_list|()
argument_list|,
operator|(
name|QTimeLine
operator|*
operator|)
name|line1
argument_list|)
expr_stmt|;
name|animation
operator|.
name|setTimeLine
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|timeLine
argument_list|()
argument_list|,
operator|(
name|QTimeLine
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|line1
argument_list|)
expr_stmt|;
name|QTimeLine
modifier|*
name|line2
init|=
operator|new
name|QTimeLine
decl_stmt|;
name|animation
operator|.
name|setTimeLine
argument_list|(
name|line2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|timeLine
argument_list|()
argument_list|,
operator|(
name|QTimeLine
operator|*
operator|)
name|line2
argument_list|)
expr_stmt|;
operator|delete
name|line2
expr_stmt|;
name|QCOMPARE
argument_list|(
name|animation
operator|.
name|timeLine
argument_list|()
argument_list|,
operator|(
name|QTimeLine
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGraphicsItemAnimation
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qgraphicsitemanimation.moc"
end_include
end_unit
