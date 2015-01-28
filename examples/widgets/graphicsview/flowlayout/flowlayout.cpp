begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"flowlayout.h"
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_constructor
DECL|function|FlowLayout
name|FlowLayout
operator|::
name|FlowLayout
parameter_list|()
block|{
name|m_spacing
index|[
literal|0
index|]
operator|=
literal|6
expr_stmt|;
name|m_spacing
index|[
literal|1
index|]
operator|=
literal|6
expr_stmt|;
name|QSizePolicy
name|sp
init|=
name|sizePolicy
argument_list|()
decl_stmt|;
name|sp
operator|.
name|setHeightForWidth
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setSizePolicy
argument_list|(
name|sp
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|insertItem
name|void
name|FlowLayout
operator|::
name|insertItem
parameter_list|(
name|int
name|index
parameter_list|,
name|QGraphicsLayoutItem
modifier|*
name|item
parameter_list|)
block|{
name|item
operator|->
name|setParentLayoutItem
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|uint
argument_list|(
name|index
argument_list|)
operator|>
name|uint
argument_list|(
name|m_items
operator|.
name|count
argument_list|()
argument_list|)
condition|)
name|index
operator|=
name|m_items
operator|.
name|count
argument_list|()
expr_stmt|;
name|m_items
operator|.
name|insert
argument_list|(
name|index
argument_list|,
name|item
argument_list|)
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|count
name|int
name|FlowLayout
operator|::
name|count
parameter_list|()
specifier|const
block|{
return|return
name|m_items
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|itemAt
name|QGraphicsLayoutItem
modifier|*
name|FlowLayout
operator|::
name|itemAt
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
return|return
name|m_items
operator|.
name|value
argument_list|(
name|index
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|removeAt
name|void
name|FlowLayout
operator|::
name|removeAt
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|m_items
operator|.
name|removeAt
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|spacing
name|qreal
name|FlowLayout
operator|::
name|spacing
parameter_list|(
name|Qt
operator|::
name|Orientation
name|o
parameter_list|)
specifier|const
block|{
return|return
name|m_spacing
index|[
name|int
argument_list|(
name|o
argument_list|)
operator|-
literal|1
index|]
return|;
block|}
end_function
begin_function
DECL|function|setSpacing
name|void
name|FlowLayout
operator|::
name|setSpacing
parameter_list|(
name|Qt
operator|::
name|Orientations
name|o
parameter_list|,
name|qreal
name|spacing
parameter_list|)
block|{
if|if
condition|(
name|o
operator|&
name|Qt
operator|::
name|Horizontal
condition|)
name|m_spacing
index|[
literal|0
index|]
operator|=
name|spacing
expr_stmt|;
if|if
condition|(
name|o
operator|&
name|Qt
operator|::
name|Vertical
condition|)
name|m_spacing
index|[
literal|1
index|]
operator|=
name|spacing
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|FlowLayout
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|geom
parameter_list|)
block|{
name|QGraphicsLayout
operator|::
name|setGeometry
argument_list|(
name|geom
argument_list|)
expr_stmt|;
name|doLayout
argument_list|(
name|geom
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doLayout
name|qreal
name|FlowLayout
operator|::
name|doLayout
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|geom
parameter_list|,
name|bool
name|applyNewGeometry
parameter_list|)
specifier|const
block|{
name|qreal
name|left
decl_stmt|,
name|top
decl_stmt|,
name|right
decl_stmt|,
name|bottom
decl_stmt|;
name|getContentsMargins
argument_list|(
operator|&
name|left
argument_list|,
operator|&
name|top
argument_list|,
operator|&
name|right
argument_list|,
operator|&
name|bottom
argument_list|)
expr_stmt|;
specifier|const
name|qreal
name|maxw
init|=
name|geom
operator|.
name|width
argument_list|()
operator|-
name|left
operator|-
name|right
decl_stmt|;
name|qreal
name|x
init|=
literal|0
decl_stmt|;
name|qreal
name|y
init|=
literal|0
decl_stmt|;
name|qreal
name|maxRowHeight
init|=
literal|0
decl_stmt|;
name|QSizeF
name|pref
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
name|m_items
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QGraphicsLayoutItem
modifier|*
name|item
init|=
name|m_items
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|pref
operator|=
name|item
operator|->
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|PreferredSize
argument_list|)
expr_stmt|;
name|maxRowHeight
operator|=
name|qMax
argument_list|(
name|maxRowHeight
argument_list|,
name|pref
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|qreal
name|next_x
decl_stmt|;
name|next_x
operator|=
name|x
operator|+
name|pref
operator|.
name|width
argument_list|()
expr_stmt|;
if|if
condition|(
name|next_x
operator|>
name|maxw
condition|)
block|{
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{
name|pref
operator|.
name|setWidth
argument_list|(
name|maxw
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|x
operator|=
literal|0
expr_stmt|;
name|next_x
operator|=
name|pref
operator|.
name|width
argument_list|()
expr_stmt|;
block|}
name|y
operator|+=
name|maxRowHeight
operator|+
name|spacing
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|maxRowHeight
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|applyNewGeometry
condition|)
name|item
operator|->
name|setGeometry
argument_list|(
name|QRectF
argument_list|(
name|QPointF
argument_list|(
name|left
operator|+
name|x
argument_list|,
name|top
operator|+
name|y
argument_list|)
argument_list|,
name|pref
argument_list|)
argument_list|)
expr_stmt|;
name|x
operator|=
name|next_x
operator|+
name|spacing
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
block|}
name|maxRowHeight
operator|=
name|qMax
argument_list|(
name|maxRowHeight
argument_list|,
name|pref
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|top
operator|+
name|y
operator|+
name|maxRowHeight
operator|+
name|bottom
return|;
block|}
end_function
begin_function
DECL|function|minSize
name|QSizeF
name|FlowLayout
operator|::
name|minSize
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|constraint
parameter_list|)
specifier|const
block|{
name|QSizeF
name|size
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|qreal
name|left
decl_stmt|,
name|top
decl_stmt|,
name|right
decl_stmt|,
name|bottom
decl_stmt|;
name|getContentsMargins
argument_list|(
operator|&
name|left
argument_list|,
operator|&
name|top
argument_list|,
operator|&
name|right
argument_list|,
operator|&
name|bottom
argument_list|)
expr_stmt|;
if|if
condition|(
name|constraint
operator|.
name|width
argument_list|()
operator|>=
literal|0
condition|)
block|{
comment|// height for width
specifier|const
name|qreal
name|height
init|=
name|doLayout
argument_list|(
name|QRectF
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|constraint
argument_list|)
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|size
operator|=
name|QSizeF
argument_list|(
name|constraint
operator|.
name|width
argument_list|()
argument_list|,
name|height
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|constraint
operator|.
name|height
argument_list|()
operator|>=
literal|0
condition|)
block|{
comment|// width for height?
comment|// not supported
block|}
else|else
block|{
name|QGraphicsLayoutItem
modifier|*
name|item
decl_stmt|;
foreach|foreach
control|(
name|item
init|,
name|m_items
control|)
name|size
operator|=
name|size
operator|.
name|expandedTo
argument_list|(
name|item
operator|->
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|MinimumSize
argument_list|)
argument_list|)
expr_stmt|;
name|size
operator|+=
name|QSize
argument_list|(
name|left
operator|+
name|right
argument_list|,
name|top
operator|+
name|bottom
argument_list|)
expr_stmt|;
block|}
return|return
name|size
return|;
block|}
end_function
begin_function
DECL|function|prefSize
name|QSizeF
name|FlowLayout
operator|::
name|prefSize
parameter_list|()
specifier|const
block|{
name|qreal
name|left
decl_stmt|,
name|right
decl_stmt|;
name|getContentsMargins
argument_list|(
operator|&
name|left
argument_list|,
literal|0
argument_list|,
operator|&
name|right
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QGraphicsLayoutItem
modifier|*
name|item
decl_stmt|;
name|qreal
name|maxh
init|=
literal|0
decl_stmt|;
name|qreal
name|totalWidth
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|item
init|,
name|m_items
control|)
block|{
if|if
condition|(
name|totalWidth
operator|>
literal|0
condition|)
name|totalWidth
operator|+=
name|spacing
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|QSizeF
name|pref
init|=
name|item
operator|->
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|PreferredSize
argument_list|)
decl_stmt|;
name|totalWidth
operator|+=
name|pref
operator|.
name|width
argument_list|()
expr_stmt|;
name|maxh
operator|=
name|qMax
argument_list|(
name|maxh
argument_list|,
name|pref
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|maxh
operator|+=
name|spacing
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
specifier|const
name|qreal
name|goldenAspectRatio
init|=
literal|1.61803399
decl_stmt|;
name|qreal
name|w
init|=
name|qSqrt
argument_list|(
name|totalWidth
operator|*
name|maxh
operator|*
name|goldenAspectRatio
argument_list|)
operator|+
name|left
operator|+
name|right
decl_stmt|;
return|return
name|minSize
argument_list|(
name|QSizeF
argument_list|(
name|w
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|maxSize
name|QSizeF
name|FlowLayout
operator|::
name|maxSize
parameter_list|()
specifier|const
block|{
name|QGraphicsLayoutItem
modifier|*
name|item
decl_stmt|;
name|qreal
name|totalWidth
init|=
literal|0
decl_stmt|;
name|qreal
name|totalHeight
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|item
init|,
name|m_items
control|)
block|{
if|if
condition|(
name|totalWidth
operator|>
literal|0
condition|)
name|totalWidth
operator|+=
name|spacing
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
if|if
condition|(
name|totalHeight
operator|>
literal|0
condition|)
name|totalHeight
operator|+=
name|spacing
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|QSizeF
name|pref
init|=
name|item
operator|->
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|PreferredSize
argument_list|)
decl_stmt|;
name|totalWidth
operator|+=
name|pref
operator|.
name|width
argument_list|()
expr_stmt|;
name|totalHeight
operator|+=
name|pref
operator|.
name|height
argument_list|()
expr_stmt|;
block|}
name|qreal
name|left
decl_stmt|,
name|top
decl_stmt|,
name|right
decl_stmt|,
name|bottom
decl_stmt|;
name|getContentsMargins
argument_list|(
operator|&
name|left
argument_list|,
operator|&
name|top
argument_list|,
operator|&
name|right
argument_list|,
operator|&
name|bottom
argument_list|)
expr_stmt|;
return|return
name|QSizeF
argument_list|(
name|left
operator|+
name|totalWidth
operator|+
name|right
argument_list|,
name|top
operator|+
name|totalHeight
operator|+
name|bottom
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSizeF
name|FlowLayout
operator|::
name|sizeHint
parameter_list|(
name|Qt
operator|::
name|SizeHint
name|which
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|constraint
parameter_list|)
specifier|const
block|{
name|QSizeF
name|sh
init|=
name|constraint
decl_stmt|;
switch|switch
condition|(
name|which
condition|)
block|{
case|case
name|Qt
operator|::
name|PreferredSize
case|:
name|sh
operator|=
name|prefSize
argument_list|()
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|MinimumSize
case|:
name|sh
operator|=
name|minSize
argument_list|(
name|constraint
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|MaximumSize
case|:
name|sh
operator|=
name|maxSize
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|sh
return|;
block|}
end_function
end_unit
