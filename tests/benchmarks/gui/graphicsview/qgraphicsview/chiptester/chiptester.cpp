begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"chiptester.h"
end_include
begin_include
include|#
directive|include
file|"chip.h"
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtOpenGL>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|ChipTester
name|ChipTester
operator|::
name|ChipTester
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsView
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|npaints
argument_list|(
literal|0
argument_list|)
block|{
name|resize
argument_list|(
literal|400
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|setHorizontalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|setVerticalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|setFrameStyle
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setTransformationAnchor
argument_list|(
name|NoAnchor
argument_list|)
expr_stmt|;
name|populateScene
argument_list|()
expr_stmt|;
name|setScene
argument_list|(
name|scene
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Chip Example"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setAntialias
name|void
name|ChipTester
operator|::
name|setAntialias
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
name|enabled
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setOpenGL
name|void
name|ChipTester
operator|::
name|setOpenGL
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|setViewport
argument_list|(
name|enabled
condition|?
operator|new
name|QGLWidget
argument_list|(
name|QGLFormat
argument_list|(
name|QGL
operator|::
name|SampleBuffers
argument_list|)
argument_list|)
else|:
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|setOperation
name|void
name|ChipTester
operator|::
name|setOperation
parameter_list|(
name|Operation
name|operation
parameter_list|)
block|{
name|this
operator|->
name|operation
operator|=
name|operation
expr_stmt|;
block|}
end_function
begin_function
DECL|function|runBenchmark
name|void
name|ChipTester
operator|::
name|runBenchmark
parameter_list|()
block|{
name|npaints
operator|=
literal|0
expr_stmt|;
name|timerId
operator|=
name|startTimer
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|stopWatch
operator|.
name|start
argument_list|()
expr_stmt|;
name|eventLoop
operator|.
name|exec
argument_list|()
expr_stmt|;
name|killTimer
argument_list|(
name|timerId
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|ChipTester
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|QGraphicsView
operator|::
name|paintEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|npaints
operator|==
literal|50
condition|)
name|eventLoop
operator|.
name|quit
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|ChipTester
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
block|{
switch|switch
condition|(
name|operation
condition|)
block|{
case|case
name|Rotate360
case|:
name|rotate
argument_list|(
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
name|ZoomInOut
case|:
block|{
name|qreal
name|s
init|=
literal|0.05
operator|+
operator|(
name|npaints
operator|/
literal|20.0
operator|)
decl_stmt|;
name|setTransform
argument_list|(
name|QTransform
argument_list|()
operator|.
name|scale
argument_list|(
name|s
argument_list|,
name|s
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|Translate
case|:
block|{
name|int
name|offset
init|=
name|horizontalScrollBar
argument_list|()
operator|->
name|minimum
argument_list|()
operator|+
operator|(
name|npaints
operator|%
operator|(
name|horizontalScrollBar
argument_list|()
operator|->
name|maximum
argument_list|()
operator|-
name|horizontalScrollBar
argument_list|()
operator|->
name|minimum
argument_list|()
operator|)
operator|)
decl_stmt|;
name|horizontalScrollBar
argument_list|()
operator|->
name|setValue
argument_list|(
name|offset
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function
begin_function
DECL|function|populateScene
name|void
name|ChipTester
operator|::
name|populateScene
parameter_list|()
block|{
name|scene
operator|=
operator|new
name|QGraphicsScene
expr_stmt|;
name|QImage
name|image
argument_list|(
literal|":/qt4logo.png"
argument_list|)
decl_stmt|;
comment|// Populate scene
name|int
name|xx
init|=
literal|0
decl_stmt|;
name|int
name|nitems
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
operator|-
literal|1100
init|;
name|i
operator|<
literal|1100
condition|;
name|i
operator|+=
literal|110
control|)
block|{
operator|++
name|xx
expr_stmt|;
name|int
name|yy
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
operator|-
literal|700
init|;
name|j
operator|<
literal|700
condition|;
name|j
operator|+=
literal|70
control|)
block|{
operator|++
name|yy
expr_stmt|;
name|qreal
name|x
init|=
operator|(
name|i
operator|+
literal|1100
operator|)
operator|/
literal|2200.0
decl_stmt|;
name|qreal
name|y
init|=
operator|(
name|j
operator|+
literal|700
operator|)
operator|/
literal|1400.0
decl_stmt|;
name|QColor
name|color
argument_list|(
name|image
operator|.
name|pixel
argument_list|(
name|int
argument_list|(
name|image
operator|.
name|width
argument_list|()
operator|*
name|x
argument_list|)
argument_list|,
name|int
argument_list|(
name|image
operator|.
name|height
argument_list|()
operator|*
name|y
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QGraphicsItem
modifier|*
name|item
init|=
operator|new
name|Chip
argument_list|(
name|color
argument_list|,
name|xx
argument_list|,
name|yy
argument_list|)
decl_stmt|;
name|item
operator|->
name|setPos
argument_list|(
name|QPointF
argument_list|(
name|i
argument_list|,
name|j
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
operator|++
name|nitems
expr_stmt|;
block|}
block|}
block|}
end_function
end_unit
