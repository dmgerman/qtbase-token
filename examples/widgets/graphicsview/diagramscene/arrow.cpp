begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"arrow.h"
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|<QPen>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_decl_stmt
DECL|variable|Pi
specifier|const
name|qreal
name|Pi
init|=
literal|3.14
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Arrow
name|Arrow
operator|::
name|Arrow
parameter_list|(
name|DiagramItem
modifier|*
name|startItem
parameter_list|,
name|DiagramItem
modifier|*
name|endItem
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsLineItem
argument_list|(
name|parent
argument_list|)
block|{
name|myStartItem
operator|=
name|startItem
expr_stmt|;
name|myEndItem
operator|=
name|endItem
expr_stmt|;
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsSelectable
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|myColor
operator|=
name|Qt
operator|::
name|black
expr_stmt|;
name|setPen
argument_list|(
name|QPen
argument_list|(
name|myColor
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|SolidLine
argument_list|,
name|Qt
operator|::
name|RoundCap
argument_list|,
name|Qt
operator|::
name|RoundJoin
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|boundingRect
name|QRectF
name|Arrow
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
name|qreal
name|extra
init|=
operator|(
name|pen
argument_list|()
operator|.
name|width
argument_list|()
operator|+
literal|20
operator|)
operator|/
literal|2.0
decl_stmt|;
return|return
name|QRectF
argument_list|(
name|line
argument_list|()
operator|.
name|p1
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
name|line
argument_list|()
operator|.
name|p2
argument_list|()
operator|.
name|x
argument_list|()
operator|-
name|line
argument_list|()
operator|.
name|p1
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|line
argument_list|()
operator|.
name|p2
argument_list|()
operator|.
name|y
argument_list|()
operator|-
name|line
argument_list|()
operator|.
name|p1
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
operator|.
name|normalized
argument_list|()
operator|.
name|adjusted
argument_list|(
operator|-
name|extra
argument_list|,
operator|-
name|extra
argument_list|,
name|extra
argument_list|,
name|extra
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|shape
name|QPainterPath
name|Arrow
operator|::
name|shape
parameter_list|()
specifier|const
block|{
name|QPainterPath
name|path
init|=
name|QGraphicsLineItem
operator|::
name|shape
argument_list|()
decl_stmt|;
name|path
operator|.
name|addPolygon
argument_list|(
name|arrowHead
argument_list|)
expr_stmt|;
return|return
name|path
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|updatePosition
name|void
name|Arrow
operator|::
name|updatePosition
parameter_list|()
block|{
name|QLineF
name|line
argument_list|(
name|mapFromItem
argument_list|(
name|myStartItem
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|mapFromItem
argument_list|(
name|myEndItem
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|setLine
argument_list|(
name|line
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|paint
name|void
name|Arrow
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|myStartItem
operator|->
name|collidesWithItem
argument_list|(
name|myEndItem
argument_list|)
condition|)
return|return;
name|QPen
name|myPen
init|=
name|pen
argument_list|()
decl_stmt|;
name|myPen
operator|.
name|setColor
argument_list|(
name|myColor
argument_list|)
expr_stmt|;
name|qreal
name|arrowSize
init|=
literal|20
decl_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|myPen
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|myColor
argument_list|)
expr_stmt|;
comment|//! [4] //! [5]
name|QLineF
name|centerLine
argument_list|(
name|myStartItem
operator|->
name|pos
argument_list|()
argument_list|,
name|myEndItem
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
name|QPolygonF
name|endPolygon
init|=
name|myEndItem
operator|->
name|polygon
argument_list|()
decl_stmt|;
name|QPointF
name|p1
init|=
name|endPolygon
operator|.
name|first
argument_list|()
operator|+
name|myEndItem
operator|->
name|pos
argument_list|()
decl_stmt|;
name|QPointF
name|p2
decl_stmt|;
name|QPointF
name|intersectPoint
decl_stmt|;
name|QLineF
name|polyLine
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|endPolygon
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|p2
operator|=
name|endPolygon
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|+
name|myEndItem
operator|->
name|pos
argument_list|()
expr_stmt|;
name|polyLine
operator|=
name|QLineF
argument_list|(
name|p1
argument_list|,
name|p2
argument_list|)
expr_stmt|;
name|QLineF
operator|::
name|IntersectType
name|intersectType
init|=
name|polyLine
operator|.
name|intersect
argument_list|(
name|centerLine
argument_list|,
operator|&
name|intersectPoint
argument_list|)
decl_stmt|;
if|if
condition|(
name|intersectType
operator|==
name|QLineF
operator|::
name|BoundedIntersection
condition|)
break|break;
name|p1
operator|=
name|p2
expr_stmt|;
block|}
name|setLine
argument_list|(
name|QLineF
argument_list|(
name|intersectPoint
argument_list|,
name|myStartItem
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [5] //! [6]
name|double
name|angle
init|=
operator|::
name|acos
argument_list|(
name|line
argument_list|()
operator|.
name|dx
argument_list|()
operator|/
name|line
argument_list|()
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|line
argument_list|()
operator|.
name|dy
argument_list|()
operator|>=
literal|0
condition|)
name|angle
operator|=
operator|(
name|Pi
operator|*
literal|2
operator|)
operator|-
name|angle
expr_stmt|;
name|QPointF
name|arrowP1
init|=
name|line
argument_list|()
operator|.
name|p1
argument_list|()
operator|+
name|QPointF
argument_list|(
name|sin
argument_list|(
name|angle
operator|+
name|Pi
operator|/
literal|3
argument_list|)
operator|*
name|arrowSize
argument_list|,
name|cos
argument_list|(
name|angle
operator|+
name|Pi
operator|/
literal|3
argument_list|)
operator|*
name|arrowSize
argument_list|)
decl_stmt|;
name|QPointF
name|arrowP2
init|=
name|line
argument_list|()
operator|.
name|p1
argument_list|()
operator|+
name|QPointF
argument_list|(
name|sin
argument_list|(
name|angle
operator|+
name|Pi
operator|-
name|Pi
operator|/
literal|3
argument_list|)
operator|*
name|arrowSize
argument_list|,
name|cos
argument_list|(
name|angle
operator|+
name|Pi
operator|-
name|Pi
operator|/
literal|3
argument_list|)
operator|*
name|arrowSize
argument_list|)
decl_stmt|;
name|arrowHead
operator|.
name|clear
argument_list|()
expr_stmt|;
name|arrowHead
operator|<<
name|line
argument_list|()
operator|.
name|p1
argument_list|()
operator|<<
name|arrowP1
operator|<<
name|arrowP2
expr_stmt|;
comment|//! [6] //! [7]
name|painter
operator|->
name|drawLine
argument_list|(
name|line
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPolygon
argument_list|(
name|arrowHead
argument_list|)
expr_stmt|;
if|if
condition|(
name|isSelected
argument_list|()
condition|)
block|{
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|myColor
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|DashLine
argument_list|)
argument_list|)
expr_stmt|;
name|QLineF
name|myLine
init|=
name|line
argument_list|()
decl_stmt|;
name|myLine
operator|.
name|translate
argument_list|(
literal|0
argument_list|,
literal|4.0
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawLine
argument_list|(
name|myLine
argument_list|)
expr_stmt|;
name|myLine
operator|.
name|translate
argument_list|(
literal|0
argument_list|,
operator|-
literal|8.0
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawLine
argument_list|(
name|myLine
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [7]
end_comment
end_unit
