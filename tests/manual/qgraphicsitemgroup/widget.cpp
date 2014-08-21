begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"widget.h"
end_include
begin_include
include|#
directive|include
file|"ui_widget.h"
end_include
begin_include
include|#
directive|include
file|<QGraphicsOpacityEffect>
end_include
begin_include
include|#
directive|include
file|<QPropertyAnimation>
end_include
begin_constructor
DECL|function|Widget
name|Widget
operator|::
name|Widget
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
member_init_list|,
name|ui
argument_list|(
operator|new
name|Ui
operator|::
name|Widget
argument_list|)
member_init_list|,
name|previousSelectionCount
argument_list|(
literal|0
argument_list|)
block|{
name|ui
operator|->
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|effect
operator|=
operator|new
name|QGraphicsOpacityEffect
expr_stmt|;
name|effect
operator|->
name|setOpacity
argument_list|(
literal|0.3
argument_list|)
expr_stmt|;
name|ui
operator|->
name|groupBox
operator|->
name|setGraphicsEffect
argument_list|(
name|effect
argument_list|)
expr_stmt|;
name|fadeIn
operator|=
operator|new
name|QPropertyAnimation
argument_list|(
name|effect
argument_list|,
literal|"opacity"
argument_list|)
expr_stmt|;
name|fadeIn
operator|->
name|setDuration
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|fadeIn
operator|->
name|setStartValue
argument_list|(
literal|0.3
argument_list|)
expr_stmt|;
name|fadeIn
operator|->
name|setEndValue
argument_list|(
literal|1.
argument_list|)
expr_stmt|;
name|fadeOut
operator|=
operator|new
name|QPropertyAnimation
argument_list|(
name|effect
argument_list|,
literal|"opacity"
argument_list|)
expr_stmt|;
name|fadeOut
operator|->
name|setDuration
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|fadeOut
operator|->
name|setStartValue
argument_list|(
literal|1.
argument_list|)
expr_stmt|;
name|fadeOut
operator|->
name|setEndValue
argument_list|(
literal|0.3
argument_list|)
expr_stmt|;
name|scene
operator|=
operator|new
name|CustomScene
expr_stmt|;
name|scene
operator|->
name|setSceneRect
argument_list|(
operator|-
literal|250
argument_list|,
operator|-
literal|250
argument_list|,
literal|500
argument_list|,
literal|500
argument_list|)
expr_stmt|;
name|ui
operator|->
name|view
operator|->
name|setScene
argument_list|(
name|scene
argument_list|)
expr_stmt|;
name|scene
operator|->
name|setBackgroundBrush
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|ui
operator|->
name|view
operator|->
name|setInteractive
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|ui
operator|->
name|view
operator|->
name|setDragMode
argument_list|(
name|QGraphicsView
operator|::
name|RubberBandDrag
argument_list|)
expr_stmt|;
name|ui
operator|->
name|view
operator|->
name|setViewportUpdateMode
argument_list|(
name|QGraphicsView
operator|::
name|FullViewportUpdate
argument_list|)
expr_stmt|;
name|ui
operator|->
name|view
operator|->
name|setRenderHints
argument_list|(
name|QPainter
operator|::
name|SmoothPixmapTransform
operator||
name|QPainter
operator|::
name|TextAntialiasing
operator||
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|rectBlue
operator|=
operator|new
name|CustomItem
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|100
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
name|QColor
argument_list|(
literal|80
argument_list|,
literal|80
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|rectBlue
argument_list|)
expr_stmt|;
name|rectGreen
operator|=
operator|new
name|CustomItem
argument_list|(
literal|100
argument_list|,
operator|-
literal|100
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
name|QColor
argument_list|(
literal|80
argument_list|,
literal|200
argument_list|,
literal|80
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|rectGreen
argument_list|)
expr_stmt|;
name|rectRed
operator|=
operator|new
name|CustomItem
argument_list|(
operator|-
literal|100
argument_list|,
literal|100
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
name|QColor
argument_list|(
literal|200
argument_list|,
literal|80
argument_list|,
literal|80
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|rectRed
argument_list|)
expr_stmt|;
name|rectYellow
operator|=
operator|new
name|CustomItem
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
name|QColor
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|,
literal|20
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|rectYellow
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|scene
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onSceneSelectionChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~Widget
name|Widget
operator|::
name|~
name|Widget
parameter_list|()
block|{
operator|delete
name|ui
expr_stmt|;
operator|delete
name|fadeIn
expr_stmt|;
operator|delete
name|fadeOut
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|on_rotate_valueChanged
name|void
name|Widget
operator|::
name|on_rotate_valueChanged
parameter_list|(
name|int
name|value
parameter_list|)
block|{
if|if
condition|(
name|scene
operator|->
name|selectedItems
argument_list|()
operator|.
name|count
argument_list|()
operator|!=
literal|1
condition|)
return|return;
name|QGraphicsItem
modifier|*
name|item
init|=
name|scene
operator|->
name|selectedItems
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|item
operator|->
name|setRotation
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|ui
operator|->
name|rotateItem
operator|->
name|setValue
argument_list|(
name|checkedItem
argument_list|()
operator|->
name|rotation
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_scale_valueChanged
name|void
name|Widget
operator|::
name|on_scale_valueChanged
parameter_list|(
name|int
name|value
parameter_list|)
block|{
if|if
condition|(
name|scene
operator|->
name|selectedItems
argument_list|()
operator|.
name|count
argument_list|()
operator|!=
literal|1
condition|)
return|return;
name|QGraphicsItem
modifier|*
name|item
init|=
name|scene
operator|->
name|selectedItems
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|item
operator|->
name|setScale
argument_list|(
name|value
operator|/
literal|10.
argument_list|)
expr_stmt|;
name|ui
operator|->
name|scaleItem
operator|->
name|setValue
argument_list|(
name|checkedItem
argument_list|()
operator|->
name|scale
argument_list|()
operator|*
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_rotateItem_valueChanged
name|void
name|Widget
operator|::
name|on_rotateItem_valueChanged
parameter_list|(
name|int
name|value
parameter_list|)
block|{
if|if
condition|(
operator|!
name|scene
operator|->
name|selectedItems
argument_list|()
operator|.
name|empty
argument_list|()
operator|&&
name|scene
operator|->
name|selectedItems
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|==
name|checkedItem
argument_list|()
condition|)
name|ui
operator|->
name|rotate
operator|->
name|setValue
argument_list|(
name|value
argument_list|)
expr_stmt|;
else|else
name|checkedItem
argument_list|()
operator|->
name|setRotation
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_scaleItem_valueChanged
name|void
name|Widget
operator|::
name|on_scaleItem_valueChanged
parameter_list|(
name|int
name|value
parameter_list|)
block|{
if|if
condition|(
operator|!
name|scene
operator|->
name|selectedItems
argument_list|()
operator|.
name|empty
argument_list|()
operator|&&
name|scene
operator|->
name|selectedItems
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|==
name|checkedItem
argument_list|()
condition|)
name|ui
operator|->
name|scale
operator|->
name|setValue
argument_list|(
name|value
argument_list|)
expr_stmt|;
else|else
name|checkedItem
argument_list|()
operator|->
name|setScale
argument_list|(
name|value
operator|/
literal|10.
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_group_clicked
name|void
name|Widget
operator|::
name|on_group_clicked
parameter_list|()
block|{
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|all
init|=
name|scene
operator|->
name|selectedItems
argument_list|()
decl_stmt|;
if|if
condition|(
name|all
operator|.
name|size
argument_list|()
operator|<
literal|2
condition|)
return|return;
name|QList
argument_list|<
name|CustomItem
modifier|*
argument_list|>
name|items
init|=
name|scene
operator|->
name|selectedCustomItems
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|CustomGroup
modifier|*
argument_list|>
name|groups
init|=
name|scene
operator|->
name|selectedCustomGroups
argument_list|()
decl_stmt|;
if|if
condition|(
name|groups
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
block|{
foreach|foreach
control|(
name|CustomItem
modifier|*
name|item
decl|,
name|items
control|)
block|{
name|item
operator|->
name|setSelected
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|groups
index|[
literal|0
index|]
operator|->
name|addToGroup
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
name|CustomGroup
modifier|*
name|group
init|=
operator|new
name|CustomGroup
decl_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|group
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QGraphicsItem
modifier|*
name|item
decl|,
name|all
control|)
block|{
name|item
operator|->
name|setSelected
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|group
operator|->
name|addToGroup
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
name|group
operator|->
name|setSelected
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|updateUngroupButton
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_dismantle_clicked
name|void
name|Widget
operator|::
name|on_dismantle_clicked
parameter_list|()
block|{
name|QList
argument_list|<
name|CustomGroup
modifier|*
argument_list|>
name|groups
init|=
name|scene
operator|->
name|selectedCustomGroups
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|CustomGroup
modifier|*
name|group
decl|,
name|groups
control|)
block|{
foreach|foreach
control|(
name|QGraphicsItem
modifier|*
name|item
decl|,
name|group
operator|->
name|childItems
argument_list|()
control|)
name|group
operator|->
name|removeFromGroup
argument_list|(
name|item
argument_list|)
expr_stmt|;
operator|delete
name|group
expr_stmt|;
block|}
name|updateUngroupButton
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_merge_clicked
name|void
name|Widget
operator|::
name|on_merge_clicked
parameter_list|()
block|{
name|QList
argument_list|<
name|CustomGroup
modifier|*
argument_list|>
name|groups
init|=
name|scene
operator|->
name|selectedCustomGroups
argument_list|()
decl_stmt|;
if|if
condition|(
name|groups
operator|.
name|size
argument_list|()
operator|<
literal|2
condition|)
return|return;
name|CustomGroup
modifier|*
name|newBigGroup
init|=
name|groups
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|CustomGroup
modifier|*
name|group
decl|,
name|groups
control|)
block|{
foreach|foreach
control|(
name|QGraphicsItem
modifier|*
name|item
decl|,
name|group
operator|->
name|childItems
argument_list|()
control|)
name|item
operator|->
name|setGroup
argument_list|(
name|newBigGroup
argument_list|)
expr_stmt|;
operator|delete
name|group
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|onSceneSelectionChanged
name|void
name|Widget
operator|::
name|onSceneSelectionChanged
parameter_list|()
block|{
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|all
init|=
name|scene
operator|->
name|selectedItems
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|CustomGroup
modifier|*
argument_list|>
name|groups
init|=
name|scene
operator|->
name|selectedCustomGroups
argument_list|()
decl_stmt|;
if|if
condition|(
name|all
operator|.
name|empty
argument_list|()
operator|&&
name|all
operator|.
name|count
argument_list|()
operator|!=
name|previousSelectionCount
condition|)
block|{
name|fadeOut
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|previousSelectionCount
operator|==
literal|0
condition|)
block|{
name|fadeIn
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|all
operator|.
name|count
argument_list|()
operator|==
literal|1
condition|)
block|{
name|QGraphicsItem
modifier|*
name|item
init|=
name|all
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|ui
operator|->
name|rotate
operator|->
name|setValue
argument_list|(
name|item
operator|->
name|rotation
argument_list|()
argument_list|)
expr_stmt|;
name|ui
operator|->
name|scale
operator|->
name|setValue
argument_list|(
name|item
operator|->
name|scale
argument_list|()
operator|*
literal|10
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ui
operator|->
name|rotate
operator|->
name|setValue
argument_list|(
name|ui
operator|->
name|rotate
operator|->
name|minimum
argument_list|()
argument_list|)
expr_stmt|;
name|ui
operator|->
name|scale
operator|->
name|setValue
argument_list|(
name|ui
operator|->
name|scale
operator|->
name|minimum
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|ui
operator|->
name|rotate
operator|->
name|setEnabled
argument_list|(
name|all
operator|.
name|size
argument_list|()
operator|==
literal|1
argument_list|)
expr_stmt|;
name|ui
operator|->
name|scale
operator|->
name|setEnabled
argument_list|(
name|all
operator|.
name|size
argument_list|()
operator|==
literal|1
argument_list|)
expr_stmt|;
name|ui
operator|->
name|group
operator|->
name|setEnabled
argument_list|(
name|all
operator|.
name|size
argument_list|()
operator|>
literal|1
argument_list|)
expr_stmt|;
name|ui
operator|->
name|dismantle
operator|->
name|setEnabled
argument_list|(
operator|!
name|groups
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|ui
operator|->
name|merge
operator|->
name|setEnabled
argument_list|(
name|groups
operator|.
name|size
argument_list|()
operator|>
literal|1
argument_list|)
expr_stmt|;
name|previousSelectionCount
operator|=
name|all
operator|.
name|size
argument_list|()
expr_stmt|;
name|updateUngroupButton
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_ungroup_clicked
name|void
name|Widget
operator|::
name|on_ungroup_clicked
parameter_list|()
block|{
name|QGraphicsItemGroup
modifier|*
name|oldGroup
init|=
name|checkedItem
argument_list|()
operator|->
name|group
argument_list|()
decl_stmt|;
name|checkedItem
argument_list|()
operator|->
name|setGroup
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|oldGroup
operator|&&
name|oldGroup
operator|->
name|childItems
argument_list|()
operator|.
name|empty
argument_list|()
condition|)
operator|delete
name|oldGroup
expr_stmt|;
name|updateUngroupButton
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateUngroupButton
name|void
name|Widget
operator|::
name|updateUngroupButton
parameter_list|()
block|{
name|ui
operator|->
name|ungroup
operator|->
name|setEnabled
argument_list|(
name|checkedItem
argument_list|()
operator|->
name|group
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkedItem
name|CustomItem
modifier|*
name|Widget
operator|::
name|checkedItem
parameter_list|()
specifier|const
block|{
name|CustomItem
modifier|*
name|item
decl_stmt|;
if|if
condition|(
name|ui
operator|->
name|blue
operator|->
name|isChecked
argument_list|()
condition|)
name|item
operator|=
name|rectBlue
expr_stmt|;
elseif|else
if|if
condition|(
name|ui
operator|->
name|red
operator|->
name|isChecked
argument_list|()
condition|)
name|item
operator|=
name|rectRed
expr_stmt|;
elseif|else
if|if
condition|(
name|ui
operator|->
name|green
operator|->
name|isChecked
argument_list|()
condition|)
name|item
operator|=
name|rectGreen
expr_stmt|;
elseif|else
if|if
condition|(
name|ui
operator|->
name|yellow
operator|->
name|isChecked
argument_list|()
condition|)
name|item
operator|=
name|rectYellow
expr_stmt|;
return|return
name|item
return|;
block|}
end_function
begin_function
DECL|function|on_buttonGroup_buttonClicked
name|void
name|Widget
operator|::
name|on_buttonGroup_buttonClicked
parameter_list|()
block|{
name|ui
operator|->
name|rotateItem
operator|->
name|setValue
argument_list|(
name|checkedItem
argument_list|()
operator|->
name|rotation
argument_list|()
argument_list|)
expr_stmt|;
name|ui
operator|->
name|scaleItem
operator|->
name|setValue
argument_list|(
name|checkedItem
argument_list|()
operator|->
name|scale
argument_list|()
operator|*
literal|10
argument_list|)
expr_stmt|;
name|updateUngroupButton
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
