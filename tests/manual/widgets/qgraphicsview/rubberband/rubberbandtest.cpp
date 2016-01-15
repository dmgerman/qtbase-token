begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 ThorbjÃ¸rn Lund Martsum - tmartsum[at]gmail.com ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_class
DECL|class|MyGraphicsItem
class|class
name|MyGraphicsItem
super|:
specifier|public
name|QGraphicsRectItem
block|{
public|public:
DECL|function|MyGraphicsItem
name|MyGraphicsItem
parameter_list|()
member_init_list|:
name|QGraphicsRectItem
argument_list|()
block|{
name|setFlags
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsSelectable
argument_list|)
expr_stmt|;
block|}
name|void
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
comment|/* option*/
parameter_list|,
name|QWidget
modifier|*
comment|/*widget*/
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
if|if
condition|(
name|isSelected
argument_list|()
condition|)
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|()
argument_list|,
name|QColor
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|()
argument_list|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|255
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|MyGraphicsView
class|class
name|MyGraphicsView
super|:
specifier|public
name|QGraphicsView
block|{
name|Q_OBJECT
public|public:
DECL|function|MyGraphicsView
name|MyGraphicsView
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|QLabel
modifier|*
name|l
parameter_list|)
member_init_list|:
name|QGraphicsView
argument_list|(
name|w
argument_list|)
member_init_list|,
name|rubberbandLabel
argument_list|(
name|l
argument_list|)
block|{
name|setDragMode
argument_list|(
name|QGraphicsView
operator|::
name|RubberBandDrag
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|rubberBandChanged
argument_list|(
name|QRect
argument_list|,
name|QPointF
argument_list|,
name|QPointF
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateRubberbandInfo
argument_list|(
name|QRect
argument_list|,
name|QPointF
argument_list|,
name|QPointF
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
protected|protected:
name|void
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|QGraphicsView
operator|::
name|mouseMoveEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|int
name|rightmostInView
init|=
name|viewport
argument_list|()
operator|->
name|mapToGlobal
argument_list|(
name|viewport
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|topRight
argument_list|()
argument_list|)
operator|.
name|x
argument_list|()
decl_stmt|;
name|int
name|xglobal
init|=
name|event
operator|->
name|globalX
argument_list|()
decl_stmt|;
if|if
condition|(
name|xglobal
operator|>
name|rightmostInView
condition|)
name|horizontalScrollBar
argument_list|()
operator|->
name|setValue
argument_list|(
name|horizontalScrollBar
argument_list|()
operator|->
name|value
argument_list|()
operator|+
literal|10
argument_list|)
expr_stmt|;
name|int
name|bottomPos
init|=
name|viewport
argument_list|()
operator|->
name|mapToGlobal
argument_list|(
name|viewport
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|bottomRight
argument_list|()
argument_list|)
operator|.
name|y
argument_list|()
decl_stmt|;
name|int
name|yglobal
init|=
name|event
operator|->
name|globalY
argument_list|()
decl_stmt|;
if|if
condition|(
name|yglobal
operator|>
name|bottomPos
condition|)
name|verticalScrollBar
argument_list|()
operator|->
name|setValue
argument_list|(
name|verticalScrollBar
argument_list|()
operator|->
name|value
argument_list|()
operator|+
literal|10
argument_list|)
expr_stmt|;
block|}
protected|protected
name|slots
protected|:
DECL|function|updateRubberbandInfo
name|void
name|updateRubberbandInfo
parameter_list|(
name|QRect
name|r
parameter_list|,
name|QPointF
name|from
parameter_list|,
name|QPointF
name|to
parameter_list|)
block|{
name|QString
name|textToShow
decl_stmt|;
name|QDebug
name|s
argument_list|(
operator|&
name|textToShow
argument_list|)
decl_stmt|;
name|s
operator|<<
name|r
operator|<<
name|from
operator|<<
name|to
expr_stmt|;
name|rubberbandLabel
operator|->
name|setText
argument_list|(
name|textToShow
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|member|rubberbandLabel
name|QLabel
modifier|*
name|rubberbandLabel
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QWidget
name|w
decl_stmt|;
name|w
operator|.
name|setLayout
argument_list|(
operator|new
name|QVBoxLayout
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|l
init|=
operator|new
name|QLabel
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
name|MyGraphicsView
modifier|*
name|v
init|=
operator|new
name|MyGraphicsView
argument_list|(
operator|&
name|w
argument_list|,
name|l
argument_list|)
decl_stmt|;
name|w
operator|.
name|layout
argument_list|()
operator|->
name|addWidget
argument_list|(
name|v
argument_list|)
expr_stmt|;
name|w
operator|.
name|layout
argument_list|()
operator|->
name|addWidget
argument_list|(
name|l
argument_list|)
expr_stmt|;
name|QGraphicsScene
name|s
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|,
literal|5000.0
argument_list|,
literal|5000.0
argument_list|)
decl_stmt|;
name|v
operator|->
name|setScene
argument_list|(
operator|&
name|s
argument_list|)
expr_stmt|;
name|v
operator|->
name|setInteractive
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|v
operator|->
name|setRubberBandSelectionMode
argument_list|(
name|Qt
operator|::
name|IntersectsItemBoundingRect
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|u
init|=
literal|0
init|;
name|u
operator|<
literal|100
condition|;
operator|++
name|u
control|)
for|for
control|(
name|int
name|n
init|=
literal|0
init|;
name|n
operator|<
literal|100
condition|;
operator|++
name|n
control|)
block|{
name|MyGraphicsItem
modifier|*
name|item
init|=
operator|new
name|MyGraphicsItem
argument_list|()
decl_stmt|;
name|item
operator|->
name|setRect
argument_list|(
name|QRectF
argument_list|(
name|n
operator|*
literal|80.0
argument_list|,
name|u
operator|*
literal|80.0
argument_list|,
literal|50.0
argument_list|,
literal|20.0
argument_list|)
argument_list|)
expr_stmt|;
name|s
operator|.
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|app
operator|.
name|exec
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"rubberbandtest.moc"
end_include
end_unit
