begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"customitem.h"
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QStyle>
end_include
begin_include
include|#
directive|include
file|<QStyleOption>
end_include
begin_function
DECL|function|selectedCustomGroups
name|QList
argument_list|<
name|CustomGroup
modifier|*
argument_list|>
name|CustomScene
operator|::
name|selectedCustomGroups
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|all
init|=
name|selectedItems
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|CustomGroup
modifier|*
argument_list|>
name|groups
decl_stmt|;
foreach|foreach
control|(
name|QGraphicsItem
modifier|*
name|item
decl|,
name|all
control|)
block|{
name|CustomGroup
modifier|*
name|group
init|=
name|qgraphicsitem_cast
argument_list|<
name|CustomGroup
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
decl_stmt|;
if|if
condition|(
name|group
condition|)
name|groups
operator|.
name|append
argument_list|(
name|group
argument_list|)
expr_stmt|;
block|}
return|return
name|groups
return|;
block|}
end_function
begin_function
DECL|function|selectedCustomItems
name|QList
argument_list|<
name|CustomItem
modifier|*
argument_list|>
name|CustomScene
operator|::
name|selectedCustomItems
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|all
init|=
name|selectedItems
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|CustomItem
modifier|*
argument_list|>
name|items
decl_stmt|;
foreach|foreach
control|(
name|QGraphicsItem
modifier|*
name|item
decl|,
name|all
control|)
block|{
name|CustomItem
modifier|*
name|citem
init|=
name|qgraphicsitem_cast
argument_list|<
name|CustomItem
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
decl_stmt|;
if|if
condition|(
name|citem
condition|)
name|items
operator|.
name|append
argument_list|(
name|citem
argument_list|)
expr_stmt|;
block|}
return|return
name|items
return|;
block|}
end_function
begin_constructor
DECL|function|CustomGroup
name|CustomGroup
operator|::
name|CustomGroup
parameter_list|()
member_init_list|:
name|QGraphicsItemGroup
argument_list|()
block|{
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsMovable
argument_list|)
expr_stmt|;
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsSelectable
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|paint
name|void
name|CustomGroup
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
name|option
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|option
operator|->
name|state
operator|&
name|QStyle
operator|::
name|State_Selected
condition|)
name|painter
operator|->
name|setOpacity
argument_list|(
literal|1.
argument_list|)
expr_stmt|;
else|else
name|painter
operator|->
name|setOpacity
argument_list|(
literal|0.2
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|QColor
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|DashLine
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRect
argument_list|(
name|boundingRect
argument_list|()
operator|.
name|adjusted
argument_list|(
operator|-
literal|2
argument_list|,
operator|-
literal|2
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|boundingRect
name|QRectF
name|CustomGroup
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QGraphicsItemGroup
operator|::
name|boundingRect
argument_list|()
operator|.
name|adjusted
argument_list|(
operator|-
literal|4
argument_list|,
operator|-
literal|4
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|CustomItem
name|CustomItem
operator|::
name|CustomItem
parameter_list|(
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|,
name|qreal
name|width
parameter_list|,
name|qreal
name|height
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
member_init_list|:
name|QGraphicsRectItem
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
block|{
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsMovable
argument_list|)
expr_stmt|;
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsSelectable
argument_list|)
expr_stmt|;
name|setBrush
argument_list|(
name|brush
argument_list|)
expr_stmt|;
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|setTransformOriginPoint
argument_list|(
name|boundingRect
argument_list|()
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
end_unit
