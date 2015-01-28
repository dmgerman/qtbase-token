begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"borderlayout.h"
end_include
begin_constructor
DECL|function|BorderLayout
name|BorderLayout
operator|::
name|BorderLayout
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
name|int
name|margin
parameter_list|,
name|int
name|spacing
parameter_list|)
member_init_list|:
name|QLayout
argument_list|(
name|parent
argument_list|)
block|{
name|setMargin
argument_list|(
name|margin
argument_list|)
expr_stmt|;
name|setSpacing
argument_list|(
name|spacing
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|BorderLayout
name|BorderLayout
operator|::
name|BorderLayout
parameter_list|(
name|int
name|spacing
parameter_list|)
block|{
name|setSpacing
argument_list|(
name|spacing
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~BorderLayout
name|BorderLayout
operator|::
name|~
name|BorderLayout
parameter_list|()
block|{
name|QLayoutItem
modifier|*
name|l
decl_stmt|;
while|while
condition|(
operator|(
name|l
operator|=
name|takeAt
argument_list|(
literal|0
argument_list|)
operator|)
condition|)
operator|delete
name|l
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|addItem
name|void
name|BorderLayout
operator|::
name|addItem
parameter_list|(
name|QLayoutItem
modifier|*
name|item
parameter_list|)
block|{
name|add
argument_list|(
name|item
argument_list|,
name|West
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addWidget
name|void
name|BorderLayout
operator|::
name|addWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|Position
name|position
parameter_list|)
block|{
name|add
argument_list|(
operator|new
name|QWidgetItem
argument_list|(
name|widget
argument_list|)
argument_list|,
name|position
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|expandingDirections
name|Qt
operator|::
name|Orientations
name|BorderLayout
operator|::
name|expandingDirections
parameter_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|Horizontal
operator||
name|Qt
operator|::
name|Vertical
return|;
block|}
end_function
begin_function
DECL|function|hasHeightForWidth
name|bool
name|BorderLayout
operator|::
name|hasHeightForWidth
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|count
name|int
name|BorderLayout
operator|::
name|count
parameter_list|()
specifier|const
block|{
return|return
name|list
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|itemAt
name|QLayoutItem
modifier|*
name|BorderLayout
operator|::
name|itemAt
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
name|ItemWrapper
modifier|*
name|wrapper
init|=
name|list
operator|.
name|value
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
name|wrapper
condition|)
return|return
name|wrapper
operator|->
name|item
return|;
else|else
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|minimumSize
name|QSize
name|BorderLayout
operator|::
name|minimumSize
parameter_list|()
specifier|const
block|{
return|return
name|calculateSize
argument_list|(
name|MinimumSize
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|BorderLayout
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|ItemWrapper
modifier|*
name|center
init|=
literal|0
decl_stmt|;
name|int
name|eastWidth
init|=
literal|0
decl_stmt|;
name|int
name|westWidth
init|=
literal|0
decl_stmt|;
name|int
name|northHeight
init|=
literal|0
decl_stmt|;
name|int
name|southHeight
init|=
literal|0
decl_stmt|;
name|int
name|centerHeight
init|=
literal|0
decl_stmt|;
name|int
name|i
decl_stmt|;
name|QLayout
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|ItemWrapper
modifier|*
name|wrapper
init|=
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QLayoutItem
modifier|*
name|item
init|=
name|wrapper
operator|->
name|item
decl_stmt|;
name|Position
name|position
init|=
name|wrapper
operator|->
name|position
decl_stmt|;
if|if
condition|(
name|position
operator|==
name|North
condition|)
block|{
name|item
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|northHeight
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|item
operator|->
name|sizeHint
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|northHeight
operator|+=
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
operator|+
name|spacing
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|position
operator|==
name|South
condition|)
block|{
name|item
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|item
operator|->
name|sizeHint
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|southHeight
operator|+=
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
operator|+
name|spacing
argument_list|()
expr_stmt|;
name|item
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|y
argument_list|()
operator|+
name|rect
operator|.
name|height
argument_list|()
operator|-
name|southHeight
operator|+
name|spacing
argument_list|()
argument_list|,
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|position
operator|==
name|Center
condition|)
block|{
name|center
operator|=
name|wrapper
expr_stmt|;
block|}
block|}
name|centerHeight
operator|=
name|rect
operator|.
name|height
argument_list|()
operator|-
name|northHeight
operator|-
name|southHeight
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|ItemWrapper
modifier|*
name|wrapper
init|=
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QLayoutItem
modifier|*
name|item
init|=
name|wrapper
operator|->
name|item
decl_stmt|;
name|Position
name|position
init|=
name|wrapper
operator|->
name|position
decl_stmt|;
if|if
condition|(
name|position
operator|==
name|West
condition|)
block|{
name|item
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|rect
operator|.
name|x
argument_list|()
operator|+
name|westWidth
argument_list|,
name|northHeight
argument_list|,
name|item
operator|->
name|sizeHint
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|centerHeight
argument_list|)
argument_list|)
expr_stmt|;
name|westWidth
operator|+=
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
operator|+
name|spacing
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|position
operator|==
name|East
condition|)
block|{
name|item
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
argument_list|,
name|item
operator|->
name|sizeHint
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|centerHeight
argument_list|)
argument_list|)
expr_stmt|;
name|eastWidth
operator|+=
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
operator|+
name|spacing
argument_list|()
expr_stmt|;
name|item
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|rect
operator|.
name|x
argument_list|()
operator|+
name|rect
operator|.
name|width
argument_list|()
operator|-
name|eastWidth
operator|+
name|spacing
argument_list|()
argument_list|,
name|northHeight
argument_list|,
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|center
condition|)
name|center
operator|->
name|item
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|westWidth
argument_list|,
name|northHeight
argument_list|,
name|rect
operator|.
name|width
argument_list|()
operator|-
name|eastWidth
operator|-
name|westWidth
argument_list|,
name|centerHeight
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSize
name|BorderLayout
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|calculateSize
argument_list|(
name|SizeHint
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|takeAt
name|QLayoutItem
modifier|*
name|BorderLayout
operator|::
name|takeAt
parameter_list|(
name|int
name|index
parameter_list|)
block|{
if|if
condition|(
name|index
operator|>=
literal|0
operator|&&
name|index
operator|<
name|list
operator|.
name|size
argument_list|()
condition|)
block|{
name|ItemWrapper
modifier|*
name|layoutStruct
init|=
name|list
operator|.
name|takeAt
argument_list|(
name|index
argument_list|)
decl_stmt|;
return|return
name|layoutStruct
operator|->
name|item
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|add
name|void
name|BorderLayout
operator|::
name|add
parameter_list|(
name|QLayoutItem
modifier|*
name|item
parameter_list|,
name|Position
name|position
parameter_list|)
block|{
name|list
operator|.
name|append
argument_list|(
operator|new
name|ItemWrapper
argument_list|(
name|item
argument_list|,
name|position
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|calculateSize
name|QSize
name|BorderLayout
operator|::
name|calculateSize
parameter_list|(
name|SizeType
name|sizeType
parameter_list|)
specifier|const
block|{
name|QSize
name|totalSize
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
name|list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|ItemWrapper
modifier|*
name|wrapper
init|=
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|Position
name|position
init|=
name|wrapper
operator|->
name|position
decl_stmt|;
name|QSize
name|itemSize
decl_stmt|;
if|if
condition|(
name|sizeType
operator|==
name|MinimumSize
condition|)
name|itemSize
operator|=
name|wrapper
operator|->
name|item
operator|->
name|minimumSize
argument_list|()
expr_stmt|;
else|else
comment|// (sizeType == SizeHint)
name|itemSize
operator|=
name|wrapper
operator|->
name|item
operator|->
name|sizeHint
argument_list|()
expr_stmt|;
if|if
condition|(
name|position
operator|==
name|North
operator|||
name|position
operator|==
name|South
operator|||
name|position
operator|==
name|Center
condition|)
name|totalSize
operator|.
name|rheight
argument_list|()
operator|+=
name|itemSize
operator|.
name|height
argument_list|()
expr_stmt|;
if|if
condition|(
name|position
operator|==
name|West
operator|||
name|position
operator|==
name|East
operator|||
name|position
operator|==
name|Center
condition|)
name|totalSize
operator|.
name|rwidth
argument_list|()
operator|+=
name|itemSize
operator|.
name|width
argument_list|()
expr_stmt|;
block|}
return|return
name|totalSize
return|;
block|}
end_function
end_unit
