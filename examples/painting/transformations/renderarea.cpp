begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"renderarea.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|RenderArea
name|RenderArea
operator|::
name|RenderArea
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|QFont
name|newFont
init|=
name|font
argument_list|()
decl_stmt|;
name|newFont
operator|.
name|setPixelSize
argument_list|(
literal|12
argument_list|)
expr_stmt|;
name|setFont
argument_list|(
name|newFont
argument_list|)
expr_stmt|;
name|QFontMetrics
name|fontMetrics
argument_list|(
name|newFont
argument_list|)
decl_stmt|;
name|xBoundingRect
operator|=
name|fontMetrics
operator|.
name|boundingRect
argument_list|(
name|tr
argument_list|(
literal|"x"
argument_list|)
argument_list|)
expr_stmt|;
name|yBoundingRect
operator|=
name|fontMetrics
operator|.
name|boundingRect
argument_list|(
name|tr
argument_list|(
literal|"y"
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
DECL|function|setOperations
name|void
name|RenderArea
operator|::
name|setOperations
parameter_list|(
specifier|const
name|QList
argument_list|<
name|Operation
argument_list|>
modifier|&
name|operations
parameter_list|)
block|{
name|this
operator|->
name|operations
operator|=
name|operations
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|setShape
name|void
name|RenderArea
operator|::
name|setShape
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|shape
parameter_list|)
block|{
name|this
operator|->
name|shape
operator|=
name|shape
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|minimumSizeHint
name|QSize
name|RenderArea
operator|::
name|minimumSizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|182
argument_list|,
literal|182
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|RenderArea
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|232
argument_list|,
literal|232
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|RenderArea
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|event
operator|->
name|rect
argument_list|()
argument_list|,
name|QBrush
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|translate
argument_list|(
literal|66
argument_list|,
literal|66
argument_list|)
expr_stmt|;
comment|//! [5]
comment|//! [6]
name|painter
operator|.
name|save
argument_list|()
expr_stmt|;
name|transformPainter
argument_list|(
name|painter
argument_list|)
expr_stmt|;
name|drawShape
argument_list|(
name|painter
argument_list|)
expr_stmt|;
name|painter
operator|.
name|restore
argument_list|()
expr_stmt|;
comment|//! [6]
comment|//! [7]
name|drawOutline
argument_list|(
name|painter
argument_list|)
expr_stmt|;
comment|//! [7]
comment|//! [8]
name|transformPainter
argument_list|(
name|painter
argument_list|)
expr_stmt|;
name|drawCoordinates
argument_list|(
name|painter
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|drawCoordinates
name|void
name|RenderArea
operator|::
name|drawCoordinates
parameter_list|(
name|QPainter
modifier|&
name|painter
parameter_list|)
block|{
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawLine
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawLine
argument_list|(
literal|48
argument_list|,
operator|-
literal|2
argument_list|,
literal|50
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawLine
argument_list|(
literal|48
argument_list|,
literal|2
argument_list|,
literal|50
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
literal|60
operator|-
name|xBoundingRect
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
literal|0
operator|+
name|xBoundingRect
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|tr
argument_list|(
literal|"x"
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawLine
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawLine
argument_list|(
operator|-
literal|2
argument_list|,
literal|48
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawLine
argument_list|(
literal|2
argument_list|,
literal|48
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
literal|0
operator|-
name|yBoundingRect
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
literal|60
operator|+
name|yBoundingRect
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|tr
argument_list|(
literal|"y"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|drawOutline
name|void
name|RenderArea
operator|::
name|drawOutline
parameter_list|(
name|QPainter
modifier|&
name|painter
parameter_list|)
block|{
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|darkGreen
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|DashLine
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|drawShape
name|void
name|RenderArea
operator|::
name|drawShape
parameter_list|(
name|QPainter
modifier|&
name|painter
parameter_list|)
block|{
name|painter
operator|.
name|fillPath
argument_list|(
name|shape
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|transformPainter
name|void
name|RenderArea
operator|::
name|transformPainter
parameter_list|(
name|QPainter
modifier|&
name|painter
parameter_list|)
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
name|operations
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
switch|switch
condition|(
name|operations
index|[
name|i
index|]
condition|)
block|{
case|case
name|Translate
case|:
name|painter
operator|.
name|translate
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
break|break;
case|case
name|Scale
case|:
name|painter
operator|.
name|scale
argument_list|(
literal|0.75
argument_list|,
literal|0.75
argument_list|)
expr_stmt|;
break|break;
case|case
name|Rotate
case|:
name|painter
operator|.
name|rotate
argument_list|(
literal|60
argument_list|)
expr_stmt|;
break|break;
case|case
name|NoTransformation
case|:
default|default:
empty_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|//! [12]
end_comment
end_unit
