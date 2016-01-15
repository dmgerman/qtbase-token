begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_class
DECL|class|ColorWidget
class|class
name|ColorWidget
super|:
specifier|public
name|QWidget
block|{
DECL|member|color
name|QColor
name|color
decl_stmt|;
DECL|member|s
name|int
name|s
decl_stmt|;
DECL|member|v
name|int
name|v
decl_stmt|;
DECL|function|changeColor
name|void
name|changeColor
parameter_list|()
block|{
name|color
operator|.
name|setHsv
argument_list|(
operator|(
name|qreal
argument_list|(
name|qrand
argument_list|()
argument_list|)
operator|/
name|RAND_MAX
operator|)
operator|*
literal|50
operator|+
literal|200
argument_list|,
name|s
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
public|public:
DECL|function|ColorWidget
name|ColorWidget
parameter_list|()
block|{
name|s
operator|=
literal|150
expr_stmt|;
name|v
operator|=
literal|150
expr_stmt|;
name|changeColor
argument_list|()
expr_stmt|;
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
DECL|function|mousePressEvent
name|void
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{
name|changeColor
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
DECL|function|mouseMoveEvent
name|void
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{
name|changeColor
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
DECL|function|enterEvent
name|void
name|enterEvent
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{
name|s
operator|=
literal|200
expr_stmt|;
name|v
operator|=
literal|200
expr_stmt|;
name|changeColor
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
DECL|function|leaveEvent
name|void
name|leaveEvent
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{
name|s
operator|=
literal|75
expr_stmt|;
name|v
operator|=
literal|75
expr_stmt|;
name|changeColor
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|()
argument_list|)
argument_list|,
name|QBrush
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
block|}
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
name|ColorWidget
name|window
decl_stmt|;
name|QWidget
modifier|*
name|w1
init|=
operator|new
name|ColorWidget
decl_stmt|;
name|QWidget
modifier|*
name|w2
init|=
operator|new
name|ColorWidget
decl_stmt|;
name|QWidget
modifier|*
name|w3
init|=
operator|new
name|ColorWidget
decl_stmt|;
name|QHBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|w1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|w2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|w3
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|w3_1
init|=
operator|new
name|ColorWidget
decl_stmt|;
name|QWidget
modifier|*
name|w3_2
init|=
operator|new
name|ColorWidget
decl_stmt|;
name|QWidget
modifier|*
name|w3_3
init|=
operator|new
name|ColorWidget
decl_stmt|;
name|QVBoxLayout
modifier|*
name|layout3
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout3
operator|->
name|setMargin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|layout3
operator|->
name|addWidget
argument_list|(
name|w3_1
argument_list|)
expr_stmt|;
name|layout3
operator|->
name|addWidget
argument_list|(
name|w3_2
argument_list|)
expr_stmt|;
name|layout3
operator|->
name|addWidget
argument_list|(
name|w3_3
argument_list|)
expr_stmt|;
name|w3
operator|->
name|setLayout
argument_list|(
name|layout3
argument_list|)
expr_stmt|;
name|window
operator|.
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|bool
name|native
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|native
condition|)
block|{
name|w1
operator|->
name|winId
argument_list|()
expr_stmt|;
name|w2
operator|->
name|winId
argument_list|()
expr_stmt|;
name|w3
operator|->
name|winId
argument_list|()
expr_stmt|;
name|w3_1
operator|->
name|winId
argument_list|()
expr_stmt|;
name|w3_2
operator|->
name|winId
argument_list|()
expr_stmt|;
name|w3_3
operator|->
name|winId
argument_list|()
expr_stmt|;
block|}
name|window
operator|.
name|resize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|window
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
