begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QGraphicsLinearLayout>
end_include
begin_include
include|#
directive|include
file|<QFont>
end_include
begin_include
include|#
directive|include
file|<QTime>
end_include
begin_include
include|#
directive|include
file|"simplelist.h"
end_include
begin_decl_stmt
DECL|variable|MinItemWidth
specifier|static
specifier|const
name|int
name|MinItemWidth
init|=
literal|276
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|SimpleList
name|SimpleList
operator|::
name|SimpleList
parameter_list|(
name|QGraphicsWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|GvbWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_list
argument_list|(
operator|new
name|ListWidget
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|QGraphicsLinearLayout
modifier|*
name|layout
init|=
operator|new
name|QGraphicsLinearLayout
argument_list|()
decl_stmt|;
name|layout
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addItem
argument_list|(
name|m_list
argument_list|)
expr_stmt|;
name|setObjectName
argument_list|(
literal|"SimpleList"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*virtual*/
end_comment
begin_destructor
DECL|function|~SimpleList
name|SimpleList
operator|::
name|~
name|SimpleList
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|addItem
name|void
name|SimpleList
operator|::
name|addItem
parameter_list|(
name|ListItem
modifier|*
name|item
parameter_list|)
block|{
name|item
operator|->
name|setMinimumWidth
argument_list|(
name|MinItemWidth
argument_list|)
expr_stmt|;
name|m_list
operator|->
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertItem
name|void
name|SimpleList
operator|::
name|insertItem
parameter_list|(
name|int
name|index
parameter_list|,
name|ListItem
modifier|*
name|item
parameter_list|)
block|{
name|item
operator|->
name|setMinimumWidth
argument_list|(
name|MinItemWidth
argument_list|)
expr_stmt|;
name|m_list
operator|->
name|insertItem
argument_list|(
name|index
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|takeItem
name|ListItem
modifier|*
name|SimpleList
operator|::
name|takeItem
parameter_list|(
name|int
name|row
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
name|ListItem
operator|*
argument_list|>
argument_list|(
name|m_list
operator|->
name|takeItem
argument_list|(
name|row
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|itemAt
name|ListItem
modifier|*
name|SimpleList
operator|::
name|itemAt
parameter_list|(
name|int
name|row
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
name|ListItem
operator|*
argument_list|>
argument_list|(
name|m_list
operator|->
name|itemAt
argument_list|(
name|row
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|itemCount
name|int
name|SimpleList
operator|::
name|itemCount
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_list
condition|)
return|return
name|m_list
operator|->
name|itemCount
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|verticalScrollBar
name|ScrollBar
modifier|*
name|SimpleList
operator|::
name|verticalScrollBar
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_list
condition|)
return|return
name|m_list
operator|->
name|verticalScrollBar
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|listItemCaching
name|bool
name|SimpleList
operator|::
name|listItemCaching
parameter_list|()
specifier|const
block|{
return|return
name|m_list
operator|->
name|listItemCaching
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setListItemCaching
name|void
name|SimpleList
operator|::
name|setListItemCaching
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|m_list
operator|->
name|setListItemCaching
argument_list|(
name|enable
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyPressEvent
name|void
name|SimpleList
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
specifier|static
name|QTime
name|keyPressInterval
init|=
name|QTime
operator|::
name|currentTime
argument_list|()
decl_stmt|;
specifier|static
name|qreal
name|step
init|=
literal|0.0
decl_stmt|;
specifier|static
name|bool
name|repeat
init|=
literal|false
decl_stmt|;
name|int
name|interval
init|=
name|keyPressInterval
operator|.
name|elapsed
argument_list|()
decl_stmt|;
name|ScrollBar
modifier|*
name|sb
init|=
name|verticalScrollBar
argument_list|()
decl_stmt|;
name|qreal
name|currentValue
init|=
name|sb
operator|->
name|sliderPosition
argument_list|()
decl_stmt|;
if|if
condition|(
name|interval
operator|<
literal|250
condition|)
block|{
if|if
condition|(
operator|!
name|repeat
condition|)
name|step
operator|=
literal|0.0
expr_stmt|;
name|step
operator|=
name|step
operator|+
literal|2.0
expr_stmt|;
if|if
condition|(
name|step
operator|>
literal|100
condition|)
name|step
operator|=
literal|100
expr_stmt|;
name|repeat
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|step
operator|=
literal|1.0
expr_stmt|;
if|if
condition|(
name|itemAt
argument_list|(
literal|0
argument_list|)
condition|)
name|step
operator|=
name|itemAt
argument_list|(
literal|0
argument_list|)
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
expr_stmt|;
name|repeat
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Up
condition|)
block|{
comment|//Up Arrow
name|sb
operator|->
name|setSliderPosition
argument_list|(
name|currentValue
operator|-
name|step
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Down
condition|)
block|{
comment|//Down Arrow
name|sb
operator|->
name|setSliderPosition
argument_list|(
name|currentValue
operator|+
name|step
argument_list|)
expr_stmt|;
block|}
name|keyPressInterval
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setTwoColumns
name|void
name|SimpleList
operator|::
name|setTwoColumns
parameter_list|(
specifier|const
name|bool
name|twoColumns
parameter_list|)
block|{
name|m_list
operator|->
name|setTwoColumns
argument_list|(
name|twoColumns
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|twoColumns
name|bool
name|SimpleList
operator|::
name|twoColumns
parameter_list|()
block|{
return|return
name|m_list
operator|->
name|twoColumns
argument_list|()
return|;
block|}
end_function
end_unit
