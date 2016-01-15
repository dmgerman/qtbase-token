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
file|<QGraphicsGridLayout>
end_include
begin_include
include|#
directive|include
file|<QGraphicsLinearLayout>
end_include
begin_include
include|#
directive|include
file|<QGraphicsSceneMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QStyleOptionGraphicsItem>
end_include
begin_include
include|#
directive|include
file|"listitem.h"
end_include
begin_include
include|#
directive|include
file|"theme.h"
end_include
begin_struct
DECL|struct|ItemData
struct|struct
name|ItemData
block|{
DECL|member|texts
name|QHash
argument_list|<
name|ListItem
operator|::
name|TextPos
argument_list|,
name|QString
argument_list|>
name|texts
decl_stmt|;
DECL|member|fonts
name|QHash
argument_list|<
name|ListItem
operator|::
name|TextPos
argument_list|,
name|QFont
argument_list|>
name|fonts
decl_stmt|;
DECL|member|icons
name|QHash
argument_list|<
name|ListItem
operator|::
name|IconItemPos
argument_list|,
name|QString
argument_list|>
name|icons
decl_stmt|;
DECL|member|iconRotations
name|QHash
argument_list|<
name|ListItem
operator|::
name|IconItemPos
argument_list|,
name|qreal
argument_list|>
name|iconRotations
decl_stmt|;
DECL|member|iconSmoothTransformations
name|QHash
argument_list|<
name|ListItem
operator|::
name|IconItemPos
argument_list|,
name|bool
argument_list|>
name|iconSmoothTransformations
decl_stmt|;
DECL|member|iconOpacityEffets
name|QHash
argument_list|<
name|ListItem
operator|::
name|IconItemPos
argument_list|,
name|bool
argument_list|>
name|iconOpacityEffets
decl_stmt|;
DECL|member|borderPen
name|QPen
name|borderPen
decl_stmt|;
DECL|member|backgroundBrush
name|QBrush
name|backgroundBrush
decl_stmt|;
DECL|member|backgroundOpacity
name|qreal
name|backgroundOpacity
decl_stmt|;
DECL|member|rounding
name|QSize
name|rounding
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
DECL|variable|ItemData
name|Q_DECLARE_METATYPE
argument_list|(
name|ItemData
argument_list|)
expr_stmt|;
end_expr_stmt
begin_constructor
DECL|function|ListItem
name|ListItem
operator|::
name|ListItem
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
name|m_txtlayout
argument_list|(
operator|new
name|QGraphicsGridLayout
argument_list|()
argument_list|)
member_init_list|,
name|m_layout
argument_list|(
operator|new
name|QGraphicsLinearLayout
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
argument_list|)
member_init_list|,
name|m_liconlayout
argument_list|(
operator|new
name|QGraphicsLinearLayout
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
argument_list|)
member_init_list|,
name|m_riconlayout
argument_list|(
operator|new
name|QGraphicsLinearLayout
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
argument_list|)
member_init_list|,
name|m_fonts
argument_list|()
member_init_list|,
name|m_borderPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
member_init_list|,
name|m_backgroundBrush
argument_list|(
name|QBrush
argument_list|()
argument_list|)
member_init_list|,
name|m_backgroundOpacity
argument_list|(
literal|1.0
argument_list|)
member_init_list|,
name|m_rounding
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
block|{
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
expr_stmt|;
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_layout
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
name|m_txtlayout
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|8
argument_list|,
literal|0
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|m_liconlayout
operator|->
name|setContentsMargins
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|m_riconlayout
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|8
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|insertItem
argument_list|(
literal|0
argument_list|,
name|m_liconlayout
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|insertItem
argument_list|(
literal|1
argument_list|,
name|m_txtlayout
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|insertItem
argument_list|(
literal|2
argument_list|,
name|m_riconlayout
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setStretchFactor
argument_list|(
name|m_liconlayout
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setStretchFactor
argument_list|(
name|m_txtlayout
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setStretchFactor
argument_list|(
name|m_riconlayout
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemClipsToShape
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|m_layout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~ListItem
name|ListItem
operator|::
name|~
name|ListItem
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_liconlayout
operator|->
name|parentLayoutItem
argument_list|()
condition|)
operator|delete
name|m_liconlayout
expr_stmt|;
if|if
condition|(
operator|!
name|m_riconlayout
operator|->
name|parentLayoutItem
argument_list|()
condition|)
operator|delete
name|m_riconlayout
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setIcon
name|void
name|ListItem
operator|::
name|setIcon
parameter_list|(
name|IconItem
modifier|*
name|iconItem
parameter_list|,
specifier|const
name|IconItemPos
name|iconPos
parameter_list|)
block|{
if|if
condition|(
name|iconPos
operator|==
name|LeftIcon
condition|)
block|{
if|if
condition|(
name|m_liconlayout
operator|->
name|count
argument_list|()
operator|>
literal|0
operator|&&
name|m_liconlayout
operator|->
name|itemAt
argument_list|(
literal|0
argument_list|)
condition|)
block|{
operator|delete
name|m_liconlayout
operator|->
name|itemAt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_liconlayout
operator|->
name|addItem
argument_list|(
name|iconItem
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_liconlayout
operator|->
name|addItem
argument_list|(
name|iconItem
argument_list|)
expr_stmt|;
block|}
name|m_liconlayout
operator|->
name|itemAt
argument_list|(
literal|0
argument_list|)
operator|->
name|setMaximumSize
argument_list|(
literal|58
argument_list|,
literal|58
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|iconPos
operator|==
name|RightIcon
condition|)
block|{
if|if
condition|(
name|m_riconlayout
operator|->
name|count
argument_list|()
operator|>
literal|0
operator|&&
name|m_riconlayout
operator|->
name|itemAt
argument_list|(
literal|0
argument_list|)
condition|)
block|{
operator|delete
name|m_riconlayout
operator|->
name|itemAt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_riconlayout
operator|->
name|addItem
argument_list|(
name|iconItem
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_riconlayout
operator|->
name|addItem
argument_list|(
name|iconItem
argument_list|)
expr_stmt|;
block|}
name|m_riconlayout
operator|->
name|itemAt
argument_list|(
literal|0
argument_list|)
operator|->
name|setMaximumSize
argument_list|(
literal|22
argument_list|,
literal|22
argument_list|)
expr_stmt|;
block|}
name|m_layout
operator|->
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|icon
name|IconItem
modifier|*
name|ListItem
operator|::
name|icon
parameter_list|(
specifier|const
name|IconItemPos
name|iconPos
parameter_list|)
specifier|const
block|{
name|QGraphicsLayoutItem
modifier|*
name|item
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|iconPos
operator|==
name|LeftIcon
operator|&&
name|m_liconlayout
operator|->
name|count
argument_list|()
operator|>
literal|0
condition|)
block|{
name|item
operator|=
name|m_liconlayout
operator|->
name|itemAt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|iconPos
operator|==
name|RightIcon
operator|&&
name|m_riconlayout
operator|->
name|count
argument_list|()
operator|>
literal|0
condition|)
block|{
name|item
operator|=
name|m_riconlayout
operator|->
name|itemAt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|item
condition|)
block|{
name|IconItem
modifier|*
name|titem
init|=
cast|static_cast
argument_list|<
name|IconItem
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
decl_stmt|;
return|return
name|titem
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|data
name|QVariant
name|ListItem
operator|::
name|data
parameter_list|(
name|int
name|role
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|role
operator|!=
name|Qt
operator|::
name|DisplayRole
condition|)
return|return
name|QVariant
argument_list|()
return|;
name|ItemData
name|data
decl_stmt|;
if|if
condition|(
name|text
argument_list|(
name|ListItem
operator|::
name|FirstPos
argument_list|)
operator|.
name|size
argument_list|()
operator|>
literal|0
condition|)
block|{
name|data
operator|.
name|texts
index|[
name|ListItem
operator|::
name|FirstPos
index|]
operator|=
name|text
argument_list|(
name|ListItem
operator|::
name|FirstPos
argument_list|)
expr_stmt|;
name|data
operator|.
name|fonts
index|[
name|ListItem
operator|::
name|FirstPos
index|]
operator|=
name|m_fonts
index|[
name|ListItem
operator|::
name|FirstPos
index|]
expr_stmt|;
block|}
if|if
condition|(
name|text
argument_list|(
name|ListItem
operator|::
name|SecondPos
argument_list|)
operator|.
name|size
argument_list|()
operator|>
literal|0
condition|)
block|{
name|data
operator|.
name|texts
index|[
name|ListItem
operator|::
name|SecondPos
index|]
operator|=
name|text
argument_list|(
name|ListItem
operator|::
name|SecondPos
argument_list|)
expr_stmt|;
name|data
operator|.
name|fonts
index|[
name|ListItem
operator|::
name|SecondPos
index|]
operator|=
name|m_fonts
index|[
name|ListItem
operator|::
name|SecondPos
index|]
expr_stmt|;
block|}
if|if
condition|(
name|text
argument_list|(
name|ListItem
operator|::
name|ThirdPos
argument_list|)
operator|.
name|size
argument_list|()
operator|>
literal|0
condition|)
block|{
name|data
operator|.
name|texts
index|[
name|ListItem
operator|::
name|ThirdPos
index|]
operator|=
name|text
argument_list|(
name|ListItem
operator|::
name|ThirdPos
argument_list|)
expr_stmt|;
name|data
operator|.
name|fonts
index|[
name|ListItem
operator|::
name|ThirdPos
index|]
operator|=
name|m_fonts
index|[
name|ListItem
operator|::
name|ThirdPos
index|]
expr_stmt|;
block|}
if|if
condition|(
name|text
argument_list|(
name|ListItem
operator|::
name|LastPos
argument_list|)
operator|.
name|size
argument_list|()
operator|>
literal|0
condition|)
block|{
name|data
operator|.
name|texts
index|[
name|ListItem
operator|::
name|LastPos
index|]
operator|=
name|text
argument_list|(
name|ListItem
operator|::
name|LastPos
argument_list|)
expr_stmt|;
name|data
operator|.
name|fonts
index|[
name|ListItem
operator|::
name|LastPos
index|]
operator|=
name|m_fonts
index|[
name|ListItem
operator|::
name|LastPos
index|]
expr_stmt|;
block|}
if|if
condition|(
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
condition|)
block|{
name|data
operator|.
name|icons
index|[
name|ListItem
operator|::
name|LeftIcon
index|]
operator|=
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
operator|->
name|fileName
argument_list|()
expr_stmt|;
name|data
operator|.
name|iconRotations
index|[
name|ListItem
operator|::
name|LeftIcon
index|]
operator|=
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
operator|->
name|rotation
argument_list|()
expr_stmt|;
name|data
operator|.
name|iconSmoothTransformations
index|[
name|ListItem
operator|::
name|LeftIcon
index|]
operator|=
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
operator|->
name|isSmoothTransformationEnabled
argument_list|()
expr_stmt|;
name|data
operator|.
name|iconOpacityEffets
index|[
name|ListItem
operator|::
name|LeftIcon
index|]
operator|=
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
operator|->
name|isOpacityEffectEnabled
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
condition|)
block|{
name|data
operator|.
name|icons
index|[
name|ListItem
operator|::
name|RightIcon
index|]
operator|=
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
operator|->
name|fileName
argument_list|()
expr_stmt|;
name|data
operator|.
name|iconRotations
index|[
name|ListItem
operator|::
name|RightIcon
index|]
operator|=
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
operator|->
name|rotation
argument_list|()
expr_stmt|;
name|data
operator|.
name|iconSmoothTransformations
index|[
name|ListItem
operator|::
name|RightIcon
index|]
operator|=
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
operator|->
name|isSmoothTransformationEnabled
argument_list|()
expr_stmt|;
name|data
operator|.
name|iconOpacityEffets
index|[
name|ListItem
operator|::
name|RightIcon
index|]
operator|=
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
operator|->
name|isOpacityEffectEnabled
argument_list|()
expr_stmt|;
block|}
name|data
operator|.
name|borderPen
operator|=
name|m_borderPen
expr_stmt|;
name|data
operator|.
name|backgroundBrush
operator|=
name|m_backgroundBrush
expr_stmt|;
name|data
operator|.
name|backgroundOpacity
operator|=
name|m_backgroundOpacity
expr_stmt|;
name|data
operator|.
name|rounding
operator|=
name|m_rounding
expr_stmt|;
name|QVariant
name|var
decl_stmt|;
name|var
operator|.
name|setValue
argument_list|(
name|data
argument_list|)
expr_stmt|;
return|return
name|var
return|;
block|}
end_function
begin_function
DECL|function|setData
name|void
name|ListItem
operator|::
name|setData
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|,
name|int
name|role
parameter_list|)
block|{
if|if
condition|(
name|role
operator|!=
name|Qt
operator|::
name|DisplayRole
condition|)
return|return;
name|ItemData
name|data
init|=
name|value
operator|.
name|value
argument_list|<
name|ItemData
argument_list|>
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|ListItem
operator|::
name|TextPos
argument_list|>
name|textkeys
init|=
name|data
operator|.
name|texts
operator|.
name|keys
argument_list|()
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
name|textkeys
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|setText
argument_list|(
name|data
operator|.
name|texts
index|[
name|textkeys
operator|.
name|at
argument_list|(
name|i
argument_list|)
index|]
argument_list|,
name|textkeys
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|setFont
argument_list|(
name|data
operator|.
name|fonts
index|[
name|textkeys
operator|.
name|at
argument_list|(
name|i
argument_list|)
index|]
argument_list|,
name|textkeys
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QList
argument_list|<
name|ListItem
operator|::
name|IconItemPos
argument_list|>
name|iconkeys
init|=
name|data
operator|.
name|icons
operator|.
name|keys
argument_list|()
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
name|iconkeys
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|IconItem
modifier|*
name|iconItem
init|=
name|icon
argument_list|(
name|iconkeys
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|iconItem
condition|)
name|iconItem
operator|->
name|setFileName
argument_list|(
name|data
operator|.
name|icons
index|[
name|iconkeys
operator|.
name|at
argument_list|(
name|i
argument_list|)
index|]
argument_list|)
expr_stmt|;
else|else
block|{
name|IconItem
modifier|*
name|iconItem
init|=
operator|new
name|IconItem
argument_list|(
name|data
operator|.
name|icons
index|[
name|iconkeys
operator|.
name|at
argument_list|(
name|i
argument_list|)
index|]
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|setIcon
argument_list|(
name|iconItem
argument_list|,
name|iconkeys
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
condition|)
block|{
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
operator|->
name|setRotation
argument_list|(
name|data
operator|.
name|iconRotations
index|[
name|ListItem
operator|::
name|LeftIcon
index|]
argument_list|)
expr_stmt|;
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
operator|->
name|setSmoothTransformationEnabled
argument_list|(
name|data
operator|.
name|iconSmoothTransformations
index|[
name|ListItem
operator|::
name|LeftIcon
index|]
argument_list|)
expr_stmt|;
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
operator|->
name|setOpacityEffectEnabled
argument_list|(
name|data
operator|.
name|iconOpacityEffets
index|[
name|ListItem
operator|::
name|LeftIcon
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
condition|)
block|{
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
operator|->
name|setRotation
argument_list|(
name|data
operator|.
name|iconRotations
index|[
name|ListItem
operator|::
name|RightIcon
index|]
argument_list|)
expr_stmt|;
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
operator|->
name|setSmoothTransformationEnabled
argument_list|(
name|data
operator|.
name|iconSmoothTransformations
index|[
name|ListItem
operator|::
name|RightIcon
index|]
argument_list|)
expr_stmt|;
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
operator|->
name|setOpacityEffectEnabled
argument_list|(
name|data
operator|.
name|iconOpacityEffets
index|[
name|ListItem
operator|::
name|RightIcon
index|]
argument_list|)
expr_stmt|;
block|}
name|m_borderPen
operator|=
name|data
operator|.
name|borderPen
expr_stmt|;
name|m_backgroundBrush
operator|=
name|data
operator|.
name|backgroundBrush
expr_stmt|;
name|m_backgroundOpacity
operator|=
name|data
operator|.
name|backgroundOpacity
expr_stmt|;
name|m_rounding
operator|=
name|data
operator|.
name|rounding
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setText
name|void
name|ListItem
operator|::
name|setText
parameter_list|(
specifier|const
name|QString
name|str
parameter_list|,
specifier|const
name|TextPos
name|position
parameter_list|)
block|{
name|QGraphicsLayoutItem
modifier|*
name|item
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|m_txtlayout
operator|->
name|rowCount
argument_list|()
operator|>
name|position
operator|&&
name|position
operator|>=
literal|0
condition|)
name|item
operator|=
name|m_txtlayout
operator|->
name|itemAt
argument_list|(
name|position
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|item
condition|)
block|{
name|Label
modifier|*
name|label
init|=
operator|new
name|Label
argument_list|(
name|str
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|m_txtlayout
operator|->
name|addItem
argument_list|(
name|label
argument_list|,
name|position
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_fonts
operator|.
name|contains
argument_list|(
name|position
argument_list|)
condition|)
name|label
operator|->
name|setFont
argument_list|(
name|m_fonts
index|[
name|position
index|]
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Label
modifier|*
name|titem
init|=
cast|static_cast
argument_list|<
name|Label
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
decl_stmt|;
name|titem
operator|->
name|setText
argument_list|(
name|str
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setFont
name|void
name|ListItem
operator|::
name|setFont
parameter_list|(
specifier|const
name|QFont
name|font
parameter_list|,
specifier|const
name|TextPos
name|position
parameter_list|)
block|{
name|m_fonts
operator|.
name|insert
argument_list|(
name|position
argument_list|,
name|font
argument_list|)
expr_stmt|;
name|QGraphicsLayoutItem
modifier|*
name|item
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|m_txtlayout
operator|->
name|rowCount
argument_list|()
operator|>
name|position
operator|&&
name|position
operator|>=
literal|0
condition|)
name|item
operator|=
name|m_txtlayout
operator|->
name|itemAt
argument_list|(
name|position
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
condition|)
block|{
name|Label
modifier|*
name|titem
init|=
cast|static_cast
argument_list|<
name|Label
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
decl_stmt|;
name|titem
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|text
name|QString
name|ListItem
operator|::
name|text
parameter_list|(
specifier|const
name|TextPos
name|position
parameter_list|)
specifier|const
block|{
name|QGraphicsLayoutItem
modifier|*
name|item
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|m_txtlayout
operator|->
name|rowCount
argument_list|()
operator|>
name|position
operator|&&
name|position
operator|>=
literal|0
condition|)
name|item
operator|=
name|m_txtlayout
operator|->
name|itemAt
argument_list|(
name|position
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
condition|)
block|{
name|Label
modifier|*
name|titem
init|=
cast|static_cast
argument_list|<
name|Label
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
decl_stmt|;
return|return
name|titem
operator|->
name|text
argument_list|()
return|;
block|}
return|return
literal|""
return|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|ListItem
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
comment|/*option*/
parameter_list|,
name|QWidget
modifier|*
comment|/*widget*/
parameter_list|)
block|{
specifier|const
name|int
name|penWidth
init|=
name|m_borderPen
operator|.
name|width
argument_list|()
decl_stmt|;
name|QRectF
name|r
init|=
name|rect
argument_list|()
decl_stmt|;
name|r
operator|.
name|adjust
argument_list|(
name|penWidth
argument_list|,
name|penWidth
argument_list|,
operator|-
name|penWidth
argument_list|,
operator|-
name|penWidth
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_borderPen
operator|!=
name|Qt
operator|::
name|NoPen
condition|)
block|{
name|painter
operator|->
name|setPen
argument_list|(
name|m_borderPen
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRoundedRect
argument_list|(
name|r
argument_list|,
name|m_rounding
operator|.
name|width
argument_list|()
argument_list|,
name|m_rounding
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m_backgroundBrush
operator|!=
name|Qt
operator|::
name|NoBrush
condition|)
block|{
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|m_backgroundBrush
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setOpacity
argument_list|(
name|m_backgroundOpacity
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRoundedRect
argument_list|(
name|r
argument_list|,
name|m_rounding
operator|.
name|width
argument_list|()
argument_list|,
name|m_rounding
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
