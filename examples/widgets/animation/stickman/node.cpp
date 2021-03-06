begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_include
include|#
directive|include
file|"stickman.h"
end_include
begin_include
include|#
directive|include
file|<QRectF>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QGraphicsSceneMouseEvent>
end_include
begin_constructor
DECL|function|Node
name|Node
operator|::
name|Node
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|pos
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_dragging
argument_list|(
literal|false
argument_list|)
block|{
name|setPos
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemSendsGeometryChanges
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~Node
name|Node
operator|::
name|~
name|Node
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|boundingRect
name|QRectF
name|Node
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
operator|-
literal|6.0
argument_list|,
operator|-
literal|6.0
argument_list|,
literal|12.0
argument_list|,
literal|12.0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|Node
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
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
name|QPointF
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
argument_list|,
literal|5.0
argument_list|,
literal|5.0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|itemChange
name|QVariant
name|Node
operator|::
name|itemChange
parameter_list|(
name|GraphicsItemChange
name|change
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|change
operator|==
name|QGraphicsItem
operator|::
name|ItemPositionChange
condition|)
emit|emit
name|positionChanged
argument_list|()
emit|;
return|return
name|QGraphicsObject
operator|::
name|itemChange
argument_list|(
name|change
argument_list|,
name|value
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|Node
operator|::
name|mousePressEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
parameter_list|)
block|{
name|m_dragging
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|Node
operator|::
name|mouseMoveEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|m_dragging
condition|)
name|setPos
argument_list|(
name|mapToParent
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseReleaseEvent
name|void
name|Node
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
parameter_list|)
block|{
name|m_dragging
operator|=
literal|false
expr_stmt|;
block|}
end_function
end_unit
