begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LISTMODEL_H
end_ifndef
begin_define
DECL|macro|LISTMODEL_H
define|#
directive|define
name|LISTMODEL_H
end_define
begin_include
include|#
directive|include
file|<QAbstractListModel>
end_include
begin_decl_stmt
DECL|variable|RecycledListItem
name|class
name|RecycledListItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ListItemCache
name|class
name|ListItemCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|ListModel
range|:
name|public
name|QAbstractListModel
block|{
name|Q_OBJECT
name|public
operator|:
name|ListModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|ListModel
argument_list|()
block|;
name|public
operator|:
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|int role = Qt::DisplayRole
argument_list|)
specifier|const
block|;
name|bool
name|setData
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int role = Qt::EditRole
argument_list|)
block|;
name|QModelIndex
name|index
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|void
name|insert
argument_list|(
argument|const int row
argument_list|,
argument|RecycledListItem *item
argument_list|)
block|;
name|void
name|appendRow
argument_list|(
name|RecycledListItem
operator|*
name|item
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|RecycledListItem
operator|*
name|item
argument_list|(
argument|const int row
argument_list|)
specifier|const
block|;
name|RecycledListItem
operator|*
name|takeItem
argument_list|(
argument|const int row
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|ListModel
argument_list|)
name|QList
operator|<
name|RecycledListItem
operator|*
operator|>
name|m_items
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LISTMODEL_H
end_comment
end_unit
