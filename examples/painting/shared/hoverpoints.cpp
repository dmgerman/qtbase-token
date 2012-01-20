begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_OPENGL_SUPPORT
end_ifdef
begin_include
include|#
directive|include
file|<QGLWidget>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"arthurwidgets.h"
end_include
begin_include
include|#
directive|include
file|"hoverpoints.h"
end_include
begin_define
DECL|macro|printf
define|#
directive|define
name|printf
end_define
begin_constructor
DECL|function|HoverPoints
name|HoverPoints
operator|::
name|HoverPoints
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|PointShape
name|shape
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|widget
argument_list|)
block|{
name|m_widget
operator|=
name|widget
expr_stmt|;
name|widget
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_AcceptTouchEvents
argument_list|)
expr_stmt|;
name|m_connectionType
operator|=
name|CurveConnection
expr_stmt|;
name|m_sortType
operator|=
name|NoSort
expr_stmt|;
name|m_shape
operator|=
name|shape
expr_stmt|;
name|m_pointPen
operator|=
name|QPen
argument_list|(
name|QColor
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|,
literal|191
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|m_connectionPen
operator|=
name|QPen
argument_list|(
name|QColor
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|,
literal|127
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|m_pointBrush
operator|=
name|QBrush
argument_list|(
name|QColor
argument_list|(
literal|191
argument_list|,
literal|191
argument_list|,
literal|191
argument_list|,
literal|127
argument_list|)
argument_list|)
expr_stmt|;
name|m_pointSize
operator|=
name|QSize
argument_list|(
literal|11
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|m_currentIndex
operator|=
operator|-
literal|1
expr_stmt|;
name|m_editable
operator|=
literal|true
expr_stmt|;
name|m_enabled
operator|=
literal|true
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|pointsChanged
argument_list|(
name|QPolygonF
argument_list|)
argument_list|)
argument_list|,
name|m_widget
argument_list|,
name|SLOT
argument_list|(
name|update
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setEnabled
name|void
name|HoverPoints
operator|::
name|setEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
if|if
condition|(
name|m_enabled
operator|!=
name|enabled
condition|)
block|{
name|m_enabled
operator|=
name|enabled
expr_stmt|;
name|m_widget
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|eventFilter
name|bool
name|HoverPoints
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|object
operator|==
name|m_widget
operator|&&
name|m_enabled
condition|)
block|{
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
block|{
if|if
condition|(
operator|!
name|m_fingerPointMapping
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|true
return|;
name|QMouseEvent
modifier|*
name|me
init|=
operator|(
name|QMouseEvent
operator|*
operator|)
name|event
decl_stmt|;
name|QPointF
name|clickPos
init|=
name|me
operator|->
name|pos
argument_list|()
decl_stmt|;
name|int
name|index
init|=
operator|-
literal|1
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
name|m_points
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QPainterPath
name|path
decl_stmt|;
if|if
condition|(
name|m_shape
operator|==
name|CircleShape
condition|)
name|path
operator|.
name|addEllipse
argument_list|(
name|pointBoundingRect
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|path
operator|.
name|addRect
argument_list|(
name|pointBoundingRect
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|path
operator|.
name|contains
argument_list|(
name|clickPos
argument_list|)
condition|)
block|{
name|index
operator|=
name|i
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|me
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
block|{
if|if
condition|(
name|index
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
operator|!
name|m_editable
condition|)
return|return
literal|false
return|;
name|int
name|pos
init|=
literal|0
decl_stmt|;
comment|// Insert sort for x or y
if|if
condition|(
name|m_sortType
operator|==
name|XSort
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_points
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|m_points
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|x
argument_list|()
operator|>
name|clickPos
operator|.
name|x
argument_list|()
condition|)
block|{
name|pos
operator|=
name|i
expr_stmt|;
break|break;
block|}
block|}
elseif|else
if|if
condition|(
name|m_sortType
operator|==
name|YSort
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_points
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|m_points
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|y
argument_list|()
operator|>
name|clickPos
operator|.
name|y
argument_list|()
condition|)
block|{
name|pos
operator|=
name|i
expr_stmt|;
break|break;
block|}
block|}
name|m_points
operator|.
name|insert
argument_list|(
name|pos
argument_list|,
name|clickPos
argument_list|)
expr_stmt|;
name|m_locks
operator|.
name|insert
argument_list|(
name|pos
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_currentIndex
operator|=
name|pos
expr_stmt|;
name|firePointChange
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|m_currentIndex
operator|=
name|index
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
name|me
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|RightButton
condition|)
block|{
if|if
condition|(
name|index
operator|>=
literal|0
operator|&&
name|m_editable
condition|)
block|{
if|if
condition|(
name|m_locks
index|[
name|index
index|]
operator|==
literal|0
condition|)
block|{
name|m_locks
operator|.
name|remove
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|m_points
operator|.
name|remove
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
name|firePointChange
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
block|}
break|break;
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
if|if
condition|(
operator|!
name|m_fingerPointMapping
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|true
return|;
name|m_currentIndex
operator|=
operator|-
literal|1
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|MouseMove
case|:
if|if
condition|(
operator|!
name|m_fingerPointMapping
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|m_currentIndex
operator|>=
literal|0
condition|)
name|movePoint
argument_list|(
name|m_currentIndex
argument_list|,
operator|(
operator|(
name|QMouseEvent
operator|*
operator|)
name|event
operator|)
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|TouchBegin
case|:
case|case
name|QEvent
operator|::
name|TouchUpdate
case|:
block|{
specifier|const
name|QTouchEvent
modifier|*
specifier|const
name|touchEvent
init|=
cast|static_cast
argument_list|<
specifier|const
name|QTouchEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
specifier|const
name|QList
argument_list|<
name|QTouchEvent
operator|::
name|TouchPoint
argument_list|>
name|points
init|=
name|touchEvent
operator|->
name|touchPoints
argument_list|()
decl_stmt|;
specifier|const
name|qreal
name|pointSize
init|=
name|qMax
argument_list|(
name|m_pointSize
operator|.
name|width
argument_list|()
argument_list|,
name|m_pointSize
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QTouchEvent
operator|::
name|TouchPoint
modifier|&
name|touchPoint
decl|,
name|points
control|)
block|{
specifier|const
name|int
name|id
init|=
name|touchPoint
operator|.
name|id
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|touchPoint
operator|.
name|state
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|TouchPointPressed
case|:
block|{
comment|// find the point, move it
name|QSet
argument_list|<
name|int
argument_list|>
name|activePoints
init|=
name|QSet
argument_list|<
name|int
argument_list|>
operator|::
name|fromList
argument_list|(
name|m_fingerPointMapping
operator|.
name|values
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|activePoint
init|=
operator|-
literal|1
decl_stmt|;
name|qreal
name|distance
init|=
operator|-
literal|1
decl_stmt|;
specifier|const
name|int
name|pointsCount
init|=
name|m_points
operator|.
name|size
argument_list|()
decl_stmt|;
specifier|const
name|int
name|activePointCount
init|=
name|activePoints
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|pointsCount
operator|==
literal|2
operator|&&
name|activePointCount
operator|==
literal|1
condition|)
block|{
comment|// only two points
name|activePoint
operator|=
name|activePoints
operator|.
name|contains
argument_list|(
literal|0
argument_list|)
condition|?
literal|1
else|:
literal|0
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|pointsCount
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|activePoints
operator|.
name|contains
argument_list|(
name|i
argument_list|)
condition|)
continue|continue;
name|qreal
name|d
init|=
name|QLineF
argument_list|(
name|touchPoint
operator|.
name|pos
argument_list|()
argument_list|,
name|m_points
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
operator|.
name|length
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|distance
operator|<
literal|0
operator|&&
name|d
operator|<
literal|12
operator|*
name|pointSize
operator|)
operator|||
name|d
operator|<
name|distance
condition|)
block|{
name|distance
operator|=
name|d
expr_stmt|;
name|activePoint
operator|=
name|i
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|activePoint
operator|!=
operator|-
literal|1
condition|)
block|{
name|m_fingerPointMapping
operator|.
name|insert
argument_list|(
name|touchPoint
operator|.
name|id
argument_list|()
argument_list|,
name|activePoint
argument_list|)
expr_stmt|;
name|movePoint
argument_list|(
name|activePoint
argument_list|,
name|touchPoint
operator|.
name|pos
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
name|Qt
operator|::
name|TouchPointReleased
case|:
block|{
comment|// move the point and release
name|QHash
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
operator|::
name|iterator
name|it
init|=
name|m_fingerPointMapping
operator|.
name|find
argument_list|(
name|id
argument_list|)
decl_stmt|;
name|movePoint
argument_list|(
name|it
operator|.
name|value
argument_list|()
argument_list|,
name|touchPoint
operator|.
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|m_fingerPointMapping
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|Qt
operator|::
name|TouchPointMoved
case|:
block|{
comment|// move the point
specifier|const
name|int
name|pointIdx
init|=
name|m_fingerPointMapping
operator|.
name|value
argument_list|(
name|id
argument_list|,
operator|-
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|pointIdx
operator|>=
literal|0
condition|)
comment|// do we track this point?
name|movePoint
argument_list|(
name|pointIdx
argument_list|,
name|touchPoint
operator|.
name|pos
argument_list|()
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
block|}
if|if
condition|(
name|m_fingerPointMapping
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
else|else
block|{
return|return
literal|true
return|;
block|}
block|}
break|break;
case|case
name|QEvent
operator|::
name|TouchEnd
case|:
if|if
condition|(
name|m_fingerPointMapping
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
break|break;
case|case
name|QEvent
operator|::
name|Resize
case|:
block|{
name|QResizeEvent
modifier|*
name|e
init|=
operator|(
name|QResizeEvent
operator|*
operator|)
name|event
decl_stmt|;
if|if
condition|(
name|e
operator|->
name|oldSize
argument_list|()
operator|.
name|width
argument_list|()
operator|==
literal|0
operator|||
name|e
operator|->
name|oldSize
argument_list|()
operator|.
name|height
argument_list|()
operator|==
literal|0
condition|)
break|break;
name|qreal
name|stretch_x
init|=
name|e
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|/
name|qreal
argument_list|(
name|e
operator|->
name|oldSize
argument_list|()
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
name|qreal
name|stretch_y
init|=
name|e
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
operator|/
name|qreal
argument_list|(
name|e
operator|->
name|oldSize
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
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
name|m_points
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QPointF
name|p
init|=
name|m_points
index|[
name|i
index|]
decl_stmt|;
name|movePoint
argument_list|(
name|i
argument_list|,
name|QPointF
argument_list|(
name|p
operator|.
name|x
argument_list|()
operator|*
name|stretch_x
argument_list|,
name|p
operator|.
name|y
argument_list|()
operator|*
name|stretch_y
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
name|firePointChange
argument_list|()
expr_stmt|;
break|break;
block|}
case|case
name|QEvent
operator|::
name|Paint
case|:
block|{
name|QWidget
modifier|*
name|that_widget
init|=
name|m_widget
decl_stmt|;
name|m_widget
operator|=
literal|0
expr_stmt|;
name|QApplication
operator|::
name|sendEvent
argument_list|(
name|object
argument_list|,
name|event
argument_list|)
expr_stmt|;
name|m_widget
operator|=
name|that_widget
expr_stmt|;
name|paintPoints
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_OPENGL_SUPPORT
name|ArthurFrame
modifier|*
name|af
init|=
name|qobject_cast
argument_list|<
name|ArthurFrame
operator|*
argument_list|>
argument_list|(
name|that_widget
argument_list|)
decl_stmt|;
if|if
condition|(
name|af
operator|&&
name|af
operator|->
name|usesOpenGL
argument_list|()
condition|)
name|af
operator|->
name|glWidget
argument_list|()
operator|->
name|swapBuffers
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
literal|true
return|;
block|}
default|default:
break|break;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|paintPoints
name|void
name|HoverPoints
operator|::
name|paintPoints
parameter_list|()
block|{
name|QPainter
name|p
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_OPENGL_SUPPORT
name|ArthurFrame
modifier|*
name|af
init|=
name|qobject_cast
argument_list|<
name|ArthurFrame
operator|*
argument_list|>
argument_list|(
name|m_widget
argument_list|)
decl_stmt|;
if|if
condition|(
name|af
operator|&&
name|af
operator|->
name|usesOpenGL
argument_list|()
condition|)
name|p
operator|.
name|begin
argument_list|(
name|af
operator|->
name|glWidget
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|p
operator|.
name|begin
argument_list|(
name|m_widget
argument_list|)
expr_stmt|;
else|#
directive|else
name|p
operator|.
name|begin
argument_list|(
name|m_widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_connectionPen
operator|.
name|style
argument_list|()
operator|!=
name|Qt
operator|::
name|NoPen
operator|&&
name|m_connectionType
operator|!=
name|NoConnection
condition|)
block|{
name|p
operator|.
name|setPen
argument_list|(
name|m_connectionPen
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_connectionType
operator|==
name|CurveConnection
condition|)
block|{
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|moveTo
argument_list|(
name|m_points
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|m_points
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QPointF
name|p1
init|=
name|m_points
operator|.
name|at
argument_list|(
name|i
operator|-
literal|1
argument_list|)
decl_stmt|;
name|QPointF
name|p2
init|=
name|m_points
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|qreal
name|distance
init|=
name|p2
operator|.
name|x
argument_list|()
operator|-
name|p1
operator|.
name|x
argument_list|()
decl_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
name|p1
operator|.
name|x
argument_list|()
operator|+
name|distance
operator|/
literal|2
argument_list|,
name|p1
operator|.
name|y
argument_list|()
argument_list|,
name|p1
operator|.
name|x
argument_list|()
operator|+
name|distance
operator|/
literal|2
argument_list|,
name|p2
operator|.
name|y
argument_list|()
argument_list|,
name|p2
operator|.
name|x
argument_list|()
argument_list|,
name|p2
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|p
operator|.
name|drawPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|p
operator|.
name|drawPolyline
argument_list|(
name|m_points
argument_list|)
expr_stmt|;
block|}
block|}
name|p
operator|.
name|setPen
argument_list|(
name|m_pointPen
argument_list|)
expr_stmt|;
name|p
operator|.
name|setBrush
argument_list|(
name|m_pointBrush
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
name|m_points
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QRectF
name|bounds
init|=
name|pointBoundingRect
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_shape
operator|==
name|CircleShape
condition|)
name|p
operator|.
name|drawEllipse
argument_list|(
name|bounds
argument_list|)
expr_stmt|;
else|else
name|p
operator|.
name|drawRect
argument_list|(
name|bounds
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|bound_point
specifier|static
name|QPointF
name|bound_point
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|point
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|bounds
parameter_list|,
name|int
name|lock
parameter_list|)
block|{
name|QPointF
name|p
init|=
name|point
decl_stmt|;
name|qreal
name|left
init|=
name|bounds
operator|.
name|left
argument_list|()
decl_stmt|;
name|qreal
name|right
init|=
name|bounds
operator|.
name|right
argument_list|()
decl_stmt|;
name|qreal
name|top
init|=
name|bounds
operator|.
name|top
argument_list|()
decl_stmt|;
name|qreal
name|bottom
init|=
name|bounds
operator|.
name|bottom
argument_list|()
decl_stmt|;
if|if
condition|(
name|p
operator|.
name|x
argument_list|()
operator|<
name|left
operator|||
operator|(
name|lock
operator|&
name|HoverPoints
operator|::
name|LockToLeft
operator|)
condition|)
name|p
operator|.
name|setX
argument_list|(
name|left
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|p
operator|.
name|x
argument_list|()
operator|>
name|right
operator|||
operator|(
name|lock
operator|&
name|HoverPoints
operator|::
name|LockToRight
operator|)
condition|)
name|p
operator|.
name|setX
argument_list|(
name|right
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|.
name|y
argument_list|()
operator|<
name|top
operator|||
operator|(
name|lock
operator|&
name|HoverPoints
operator|::
name|LockToTop
operator|)
condition|)
name|p
operator|.
name|setY
argument_list|(
name|top
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|p
operator|.
name|y
argument_list|()
operator|>
name|bottom
operator|||
operator|(
name|lock
operator|&
name|HoverPoints
operator|::
name|LockToBottom
operator|)
condition|)
name|p
operator|.
name|setY
argument_list|(
name|bottom
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
end_function
begin_function
DECL|function|setPoints
name|void
name|HoverPoints
operator|::
name|setPoints
parameter_list|(
specifier|const
name|QPolygonF
modifier|&
name|points
parameter_list|)
block|{
if|if
condition|(
name|points
operator|.
name|size
argument_list|()
operator|!=
name|m_points
operator|.
name|size
argument_list|()
condition|)
name|m_fingerPointMapping
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_points
operator|.
name|clear
argument_list|()
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
name|points
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|m_points
operator|<<
name|bound_point
argument_list|(
name|points
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|boundingRect
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_locks
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_points
operator|.
name|size
argument_list|()
operator|>
literal|0
condition|)
block|{
name|m_locks
operator|.
name|resize
argument_list|(
name|m_points
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|m_locks
operator|.
name|fill
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|movePoint
name|void
name|HoverPoints
operator|::
name|movePoint
parameter_list|(
name|int
name|index
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|point
parameter_list|,
name|bool
name|emitUpdate
parameter_list|)
block|{
name|m_points
index|[
name|index
index|]
operator|=
name|bound_point
argument_list|(
name|point
argument_list|,
name|boundingRect
argument_list|()
argument_list|,
name|m_locks
operator|.
name|at
argument_list|(
name|index
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|emitUpdate
condition|)
name|firePointChange
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|x_less_than
specifier|inline
specifier|static
name|bool
name|x_less_than
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p1
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|p2
parameter_list|)
block|{
return|return
name|p1
operator|.
name|x
argument_list|()
operator|<
name|p2
operator|.
name|x
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|y_less_than
specifier|inline
specifier|static
name|bool
name|y_less_than
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p1
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|p2
parameter_list|)
block|{
return|return
name|p1
operator|.
name|y
argument_list|()
operator|<
name|p2
operator|.
name|y
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|firePointChange
name|void
name|HoverPoints
operator|::
name|firePointChange
parameter_list|()
block|{
comment|//    printf("HoverPoints::firePointChange(), current=%d\n", m_currentIndex);
if|if
condition|(
name|m_sortType
operator|!=
name|NoSort
condition|)
block|{
name|QPointF
name|oldCurrent
decl_stmt|;
if|if
condition|(
name|m_currentIndex
operator|!=
operator|-
literal|1
condition|)
block|{
name|oldCurrent
operator|=
name|m_points
index|[
name|m_currentIndex
index|]
expr_stmt|;
block|}
if|if
condition|(
name|m_sortType
operator|==
name|XSort
condition|)
name|qSort
argument_list|(
name|m_points
operator|.
name|begin
argument_list|()
argument_list|,
name|m_points
operator|.
name|end
argument_list|()
argument_list|,
name|x_less_than
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|m_sortType
operator|==
name|YSort
condition|)
name|qSort
argument_list|(
name|m_points
operator|.
name|begin
argument_list|()
argument_list|,
name|m_points
operator|.
name|end
argument_list|()
argument_list|,
name|y_less_than
argument_list|)
expr_stmt|;
comment|// Compensate for changed order...
if|if
condition|(
name|m_currentIndex
operator|!=
operator|-
literal|1
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_points
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|m_points
index|[
name|i
index|]
operator|==
name|oldCurrent
condition|)
block|{
name|m_currentIndex
operator|=
name|i
expr_stmt|;
break|break;
block|}
block|}
block|}
comment|//         printf(" - firePointChange(), current=%d\n", m_currentIndex);
block|}
comment|//     for (int i=0; i<m_points.size(); ++i) {
comment|//         printf(" - point(%2d)=[%.2f, %.2f], lock=%d\n",
comment|//                i, m_points.at(i).x(), m_points.at(i).y(), m_locks.at(i));
comment|//     }
emit|emit
name|pointsChanged
argument_list|(
name|m_points
argument_list|)
emit|;
block|}
end_function
end_unit
