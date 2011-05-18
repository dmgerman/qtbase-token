begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"abstractviewitem.h"
end_include
begin_constructor
DECL|function|AbstractViewItem
name|AbstractViewItem
operator|::
name|AbstractViewItem
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
name|m_index
argument_list|()
member_init_list|,
name|m_itemView
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_prototype
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*virtual*/
end_comment
begin_destructor
DECL|function|~AbstractViewItem
name|AbstractViewItem
operator|::
name|~
name|AbstractViewItem
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|modelIndex
name|QModelIndex
name|AbstractViewItem
operator|::
name|modelIndex
parameter_list|()
specifier|const
block|{
return|return
name|m_index
return|;
block|}
end_function
begin_function
DECL|function|prototype
name|AbstractViewItem
modifier|*
name|AbstractViewItem
operator|::
name|prototype
parameter_list|()
specifier|const
block|{
return|return
name|m_prototype
return|;
block|}
end_function
begin_function
DECL|function|itemView
name|AbstractItemView
modifier|*
name|AbstractViewItem
operator|::
name|itemView
parameter_list|()
specifier|const
block|{
return|return
name|m_itemView
return|;
block|}
end_function
begin_function
DECL|function|setItemView
name|void
name|AbstractViewItem
operator|::
name|setItemView
parameter_list|(
name|AbstractItemView
modifier|*
name|itemView
parameter_list|)
block|{
name|m_itemView
operator|=
name|itemView
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setModelIndex
name|void
name|AbstractViewItem
operator|::
name|setModelIndex
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
block|{
if|if
condition|(
name|m_index
operator|!=
name|index
condition|)
block|{
name|m_index
operator|=
name|index
expr_stmt|;
name|updateItemContents
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|effectiveSizeHint
name|QSizeF
name|AbstractViewItem
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
return|return
name|GvbWidget
operator|::
name|effectiveSizeHint
argument_list|(
name|which
argument_list|,
name|constraint
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|event
name|bool
name|AbstractViewItem
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QGraphicsWidget
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|updateItemContents
name|void
name|AbstractViewItem
operator|::
name|updateItemContents
parameter_list|()
block|{
empty_stmt|;
comment|// No impl yet
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|themeChange
name|void
name|AbstractViewItem
operator|::
name|themeChange
parameter_list|()
block|{
empty_stmt|;
comment|// No impl yet
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|setSubtreeCacheEnabled
name|void
name|AbstractViewItem
operator|::
name|setSubtreeCacheEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|enabled
argument_list|)
expr_stmt|;
comment|// No impl
block|}
end_function
end_unit
