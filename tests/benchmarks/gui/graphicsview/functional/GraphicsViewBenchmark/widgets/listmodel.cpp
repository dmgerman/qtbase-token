begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"listmodel.h"
end_include
begin_include
include|#
directive|include
file|"recycledlistitem.h"
end_include
begin_constructor
DECL|function|ListModel
name|ListModel
operator|::
name|ListModel
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractListModel
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_items
argument_list|()
block|{  }
end_constructor
begin_destructor
DECL|function|~ListModel
name|ListModel
operator|::
name|~
name|ListModel
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|m_items
argument_list|)
expr_stmt|;
name|m_items
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|rowCount
name|int
name|ListModel
operator|::
name|rowCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|parent
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|m_items
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|data
name|QVariant
name|ListModel
operator|::
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|index
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|index
operator|.
name|row
argument_list|()
operator|>=
name|m_items
operator|.
name|size
argument_list|()
operator|||
name|index
operator|.
name|row
argument_list|()
operator|<
literal|0
condition|)
return|return
name|QVariant
argument_list|()
return|;
switch|switch
condition|(
name|role
condition|)
block|{
case|case
name|Qt
operator|::
name|DisplayRole
case|:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|m_items
operator|.
name|at
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
operator|->
name|data
argument_list|(
name|role
argument_list|)
argument_list|)
return|;
default|default:
return|return
name|QVariant
argument_list|()
return|;
block|}
block|}
end_function
begin_function
DECL|function|setData
name|bool
name|ListModel
operator|::
name|setData
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|,
name|int
name|role
parameter_list|)
block|{
comment|// TODO implement if we like to edit list items
name|Q_UNUSED
argument_list|(
argument|index
argument_list|)
name|Q_UNUSED
argument_list|(
argument|value
argument_list|)
name|Q_UNUSED
argument_list|(
argument|role
argument_list|)
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|clear
name|void
name|ListModel
operator|::
name|clear
parameter_list|()
block|{
name|m_items
operator|.
name|clear
argument_list|()
expr_stmt|;
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|index
name|QModelIndex
name|ListModel
operator|::
name|index
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|hasIndex
argument_list|(
name|row
argument_list|,
name|column
argument_list|,
name|parent
argument_list|)
condition|)
return|return
name|createIndex
argument_list|(
name|row
argument_list|,
name|column
argument_list|,
name|m_items
operator|.
name|at
argument_list|(
name|row
argument_list|)
argument_list|)
return|;
return|return
name|QModelIndex
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|insert
name|void
name|ListModel
operator|::
name|insert
parameter_list|(
name|int
name|row
parameter_list|,
name|RecycledListItem
modifier|*
name|item
parameter_list|)
block|{
if|if
condition|(
name|item
condition|)
name|item
operator|->
name|setModel
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|item
operator|||
name|m_items
operator|.
name|contains
argument_list|(
name|item
argument_list|)
condition|)
block|{
return|return;
block|}
if|if
condition|(
name|row
operator|<
literal|0
condition|)
name|row
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|row
operator|>
name|m_items
operator|.
name|count
argument_list|()
condition|)
name|row
operator|=
name|m_items
operator|.
name|count
argument_list|()
expr_stmt|;
name|beginInsertRows
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
name|row
argument_list|,
name|row
argument_list|)
expr_stmt|;
name|m_items
operator|.
name|insert
argument_list|(
name|row
argument_list|,
name|item
argument_list|)
expr_stmt|;
name|endInsertRows
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|appendRow
name|void
name|ListModel
operator|::
name|appendRow
parameter_list|(
name|RecycledListItem
modifier|*
name|item
parameter_list|)
block|{
if|if
condition|(
operator|!
name|item
condition|)
return|return;
name|item
operator|->
name|setModel
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|rowCount
argument_list|()
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|item
name|RecycledListItem
modifier|*
name|ListModel
operator|::
name|item
parameter_list|(
specifier|const
name|int
name|row
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|row
argument_list|<
literal|0
operator|||
name|row
argument_list|>
name|m_items
operator|.
name|count
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|m_items
operator|.
name|at
argument_list|(
name|row
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|takeItem
name|RecycledListItem
modifier|*
name|ListModel
operator|::
name|takeItem
parameter_list|(
specifier|const
name|int
name|row
parameter_list|)
block|{
if|if
condition|(
name|row
operator|<
literal|0
operator|||
name|row
operator|>=
name|m_items
operator|.
name|count
argument_list|()
condition|)
return|return
literal|0
return|;
name|beginRemoveRows
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
name|row
argument_list|,
name|row
argument_list|)
expr_stmt|;
name|RecycledListItem
modifier|*
name|item
init|=
name|m_items
operator|.
name|takeAt
argument_list|(
name|row
argument_list|)
decl_stmt|;
name|endRemoveRows
argument_list|()
expr_stmt|;
return|return
name|item
return|;
block|}
end_function
end_unit
