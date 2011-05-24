begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2009 Stephen Kelly<steveire@gmail.com> ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DYNAMICTREEMODEL_H
end_ifndef
begin_define
DECL|macro|DYNAMICTREEMODEL_H
define|#
directive|define
name|DYNAMICTREEMODEL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QAbstractItemModel>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_decl_stmt
name|class
name|DynamicTreeModel
range|:
name|public
name|QAbstractItemModel
block|{
name|Q_OBJECT
name|public
operator|:
name|DynamicTreeModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
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
name|QModelIndex
name|parent
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&index = QModelIndex()
argument_list|)
specifier|const
block|;
name|int
name|columnCount
argument_list|(
argument|const QModelIndex&index = QModelIndex()
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
name|void
name|clear
argument_list|()
block|;
name|protected
name|slots
operator|:
comment|/**   Finds the parent id of the string with id @p searchId.    Returns -1 if not found.   */
name|qint64
name|findParentId
argument_list|(
argument|qint64 searchId
argument_list|)
specifier|const
block|;
name|private
operator|:
name|QHash
operator|<
name|qint64
block|,
name|QString
operator|>
name|m_items
block|;
name|QHash
operator|<
name|qint64
block|,
name|QList
operator|<
name|QList
operator|<
name|qint64
operator|>
expr|>
operator|>
name|m_childItems
block|;
name|qint64
name|nextId
block|;
name|qint64
name|newId
argument_list|()
block|{
return|return
name|nextId
operator|++
return|;
block|}
block|;
name|QModelIndex
name|m_nextParentIndex
block|;
name|int
name|m_nextRow
block|;
name|int
name|m_depth
block|;
name|int
name|maxDepth
block|;
name|friend
name|class
name|ModelInsertCommand
block|;
name|friend
name|class
name|ModelMoveCommand
block|;
name|friend
name|class
name|ModelResetCommand
block|;
name|friend
name|class
name|ModelResetCommandFixed
block|;  }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|ModelChangeCommand
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|ModelChangeCommand
argument_list|(
name|DynamicTreeModel
operator|*
name|model
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|ModelChangeCommand
argument_list|()
block|{}
name|void
name|setAncestorRowNumbers
argument_list|(
argument|QList<int> rowNumbers
argument_list|)
block|{
name|m_rowNumbers
operator|=
name|rowNumbers
block|; }
name|QModelIndex
name|findIndex
argument_list|(
name|QList
operator|<
name|int
operator|>
name|rows
argument_list|)
block|;
name|void
name|setStartRow
argument_list|(
argument|int row
argument_list|)
block|{
name|m_startRow
operator|=
name|row
block|; }
name|void
name|setEndRow
argument_list|(
argument|int row
argument_list|)
block|{
name|m_endRow
operator|=
name|row
block|; }
name|void
name|setNumCols
argument_list|(
argument|int cols
argument_list|)
block|{
name|m_numCols
operator|=
name|cols
block|; }
name|virtual
name|void
name|doCommand
argument_list|()
operator|=
literal|0
block|;
name|protected
operator|:
name|DynamicTreeModel
operator|*
name|m_model
block|;
name|QList
operator|<
name|int
operator|>
name|m_rowNumbers
block|;
name|int
name|m_numCols
block|;
name|int
name|m_startRow
block|;
name|int
name|m_endRow
block|;  }
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|ModelChangeCommandList
typedef|typedef
name|QList
operator|<
name|ModelChangeCommand
operator|*
operator|>
name|ModelChangeCommandList
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|ModelInsertCommand
range|:
name|public
name|ModelChangeCommand
block|{
name|Q_OBJECT
name|public
operator|:
name|ModelInsertCommand
argument_list|(
name|DynamicTreeModel
operator|*
name|model
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|ModelInsertCommand
argument_list|()
block|{}
name|virtual
name|void
name|doCommand
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|ModelMoveCommand
range|:
name|public
name|ModelChangeCommand
block|{
name|Q_OBJECT
name|public
operator|:
name|ModelMoveCommand
argument_list|(
name|DynamicTreeModel
operator|*
name|model
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|virtual
operator|~
name|ModelMoveCommand
argument_list|()
block|{}
name|virtual
name|bool
name|emitPreSignal
argument_list|(
argument|const QModelIndex&srcParent
argument_list|,
argument|int srcStart
argument_list|,
argument|int srcEnd
argument_list|,
argument|const QModelIndex&destParent
argument_list|,
argument|int destRow
argument_list|)
block|;
name|virtual
name|void
name|doCommand
argument_list|()
block|;
name|virtual
name|void
name|emitPostSignal
argument_list|()
block|;
name|void
name|setDestAncestors
argument_list|(
argument|QList<int> rows
argument_list|)
block|{
name|m_destRowNumbers
operator|=
name|rows
block|; }
name|void
name|setDestRow
argument_list|(
argument|int row
argument_list|)
block|{
name|m_destRow
operator|=
name|row
block|; }
name|protected
operator|:
name|QList
operator|<
name|int
operator|>
name|m_destRowNumbers
block|;
name|int
name|m_destRow
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/**   A command which does a move and emits a reset signal. */
end_comment
begin_decl_stmt
name|class
name|ModelResetCommand
range|:
name|public
name|ModelMoveCommand
block|{
name|Q_OBJECT
name|public
operator|:
name|ModelResetCommand
argument_list|(
name|DynamicTreeModel
operator|*
name|model
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|ModelResetCommand
argument_list|()
block|;
name|virtual
name|bool
name|emitPreSignal
argument_list|(
argument|const QModelIndex&srcParent
argument_list|,
argument|int srcStart
argument_list|,
argument|int srcEnd
argument_list|,
argument|const QModelIndex&destParent
argument_list|,
argument|int destRow
argument_list|)
block|;
name|virtual
name|void
name|emitPostSignal
argument_list|()
block|;  }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/**   A command which does a move and emits a beginResetModel and endResetModel signals. */
end_comment
begin_decl_stmt
name|class
name|ModelResetCommandFixed
range|:
name|public
name|ModelMoveCommand
block|{
name|Q_OBJECT
name|public
operator|:
name|ModelResetCommandFixed
argument_list|(
name|DynamicTreeModel
operator|*
name|model
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|ModelResetCommandFixed
argument_list|()
block|;
name|virtual
name|bool
name|emitPreSignal
argument_list|(
argument|const QModelIndex&srcParent
argument_list|,
argument|int srcStart
argument_list|,
argument|int srcEnd
argument_list|,
argument|const QModelIndex&destParent
argument_list|,
argument|int destRow
argument_list|)
block|;
name|virtual
name|void
name|emitPostSignal
argument_list|()
block|;  }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
