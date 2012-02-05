begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QGraphicsGridLayout>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|"recycledlistitem.h"
end_include
begin_include
include|#
directive|include
file|"listmodel.h"
end_include
begin_decl_stmt
DECL|variable|MinItemHeight
specifier|static
specifier|const
name|int
name|MinItemHeight
init|=
literal|70
decl_stmt|;
end_decl_stmt
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
DECL|function|RecycledListItem
name|RecycledListItem
operator|::
name|RecycledListItem
parameter_list|(
name|QGraphicsWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|AbstractViewItem
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_item
argument_list|(
operator|new
name|ListItem
argument_list|(
name|this
argument_list|)
argument_list|)
member_init_list|,
name|m_item2
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_model
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_layout
argument_list|(
operator|new
name|QGraphicsGridLayout
argument_list|()
argument_list|)
block|{
name|m_item
operator|->
name|setMinimumWidth
argument_list|(
name|MinItemWidth
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
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|addItem
argument_list|(
name|m_item
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|m_layout
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
name|m_layout
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setHorizontalSpacing
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setVerticalSpacing
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~RecycledListItem
name|RecycledListItem
operator|::
name|~
name|RecycledListItem
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|setModel
name|void
name|RecycledListItem
operator|::
name|setModel
parameter_list|(
name|QAbstractItemModel
modifier|*
name|model
parameter_list|)
block|{
name|m_model
operator|=
name|model
expr_stmt|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|newItemInstance
name|AbstractViewItem
modifier|*
name|RecycledListItem
operator|::
name|newItemInstance
parameter_list|()
block|{
name|RecycledListItem
modifier|*
name|item
init|=
operator|new
name|RecycledListItem
argument_list|()
decl_stmt|;
return|return
name|item
return|;
block|}
end_function
begin_function
DECL|function|effectiveSizeHint
name|QSizeF
name|RecycledListItem
operator|::
name|effectiveSizeHint
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
name|s
init|=
name|m_item
operator|->
name|effectiveSizeHint
argument_list|(
name|which
argument_list|,
name|constraint
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_item2
condition|)
name|s
operator|.
name|setWidth
argument_list|(
name|s
operator|.
name|width
argument_list|()
operator|*
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|.
name|height
argument_list|()
operator|<
name|MinItemHeight
condition|)
name|s
operator|.
name|setHeight
argument_list|(
name|MinItemHeight
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|data
name|QVariant
name|RecycledListItem
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
name|m_item
operator|&&
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
condition|)
return|return
name|m_item
operator|->
name|data
argument_list|()
return|;
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setData
name|void
name|RecycledListItem
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
name|m_item
operator|&&
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
condition|)
block|{
name|m_item
operator|->
name|setData
argument_list|(
name|value
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_item2
condition|)
block|{
name|m_item2
operator|->
name|setData
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|RecycledListItem
operator|::
name|resizeEvent
parameter_list|(
name|QGraphicsSceneResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|AbstractViewItem
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateItemContents
name|void
name|RecycledListItem
operator|::
name|updateItemContents
parameter_list|()
block|{
name|AbstractViewItem
operator|::
name|updateItemContents
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_model
operator|&&
name|m_index
operator|.
name|isValid
argument_list|()
condition|)
name|setData
argument_list|(
name|m_model
operator|->
name|data
argument_list|(
name|m_index
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setTwoColumns
name|void
name|RecycledListItem
operator|::
name|setTwoColumns
parameter_list|(
specifier|const
name|bool
name|enabled
parameter_list|)
block|{
if|if
condition|(
name|m_item2
operator|&&
name|enabled
condition|)
return|return;
if|if
condition|(
name|enabled
condition|)
block|{
name|m_item2
operator|=
operator|new
name|ListItem
argument_list|()
expr_stmt|;
name|m_item2
operator|->
name|setMinimumWidth
argument_list|(
name|MinItemWidth
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|addItem
argument_list|(
name|m_item2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|updateItemContents
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|m_layout
operator|->
name|count
argument_list|()
operator|>
literal|1
condition|)
block|{
name|m_layout
operator|->
name|removeAt
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
operator|delete
name|m_item2
expr_stmt|;
name|m_item2
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_layout
operator|->
name|isActivated
argument_list|()
condition|)
name|m_layout
operator|->
name|activate
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
