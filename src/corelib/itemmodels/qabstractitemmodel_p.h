begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTITEMMODEL_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTITEMMODEL_P_H
define|#
directive|define
name|QABSTRACTITEMMODEL_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of QAbstractItemModel*.  This header file may change from version
end_comment
begin_comment
comment|// to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstack.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qset.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QPersistentModelIndexData
block|{
name|public
label|:
name|QPersistentModelIndexData
argument_list|()
operator|:
name|model
argument_list|(
literal|0
argument_list|)
block|{}
name|QPersistentModelIndexData
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|idx
argument_list|)
operator|:
name|index
argument_list|(
name|idx
argument_list|)
operator|,
name|model
argument_list|(
argument|idx.model()
argument_list|)
block|{}
name|QModelIndex
name|index
expr_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
specifier|const
name|QAbstractItemModel
modifier|*
name|model
decl_stmt|;
specifier|static
name|QPersistentModelIndexData
modifier|*
name|create
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
specifier|static
name|void
name|destroy
parameter_list|(
name|QPersistentModelIndexData
modifier|*
name|data
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAbstractItemModelPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAbstractItemModel
argument_list|)
name|public
operator|:
name|QAbstractItemModelPrivate
argument_list|()
operator|:
name|QObjectPrivate
argument_list|()
block|,
name|supportedDragActions
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|roleNames
argument_list|(
argument|defaultRoleNames()
argument_list|)
block|{}
name|void
name|removePersistentIndexData
argument_list|(
name|QPersistentModelIndexData
operator|*
name|data
argument_list|)
block|;
name|void
name|movePersistentIndexes
argument_list|(
argument|QVector<QPersistentModelIndexData *> indexes
argument_list|,
argument|int change
argument_list|,
argument|const QModelIndex&parent
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
name|void
name|rowsAboutToBeInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|rowsInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|rowsAboutToBeRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|rowsRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|columnsAboutToBeInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|columnsInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|columnsAboutToBeRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|columnsRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
specifier|static
name|QAbstractItemModel
operator|*
name|staticEmptyModel
argument_list|()
block|;
specifier|static
name|bool
name|variantLessThan
argument_list|(
specifier|const
name|QVariant
operator|&
name|v1
argument_list|,
specifier|const
name|QVariant
operator|&
name|v2
argument_list|)
block|;
name|void
name|itemsAboutToBeMoved
argument_list|(
argument|const QModelIndex&srcParent
argument_list|,
argument|int srcFirst
argument_list|,
argument|int srcLast
argument_list|,
argument|const QModelIndex&destinationParent
argument_list|,
argument|int destinationChild
argument_list|,
argument|Qt::Orientation
argument_list|)
block|;
name|void
name|itemsMoved
argument_list|(
argument|const QModelIndex&srcParent
argument_list|,
argument|int srcFirst
argument_list|,
argument|int srcLast
argument_list|,
argument|const QModelIndex&destinationParent
argument_list|,
argument|int destinationChild
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
name|bool
name|allowMove
argument_list|(
argument|const QModelIndex&srcParent
argument_list|,
argument|int srcFirst
argument_list|,
argument|int srcLast
argument_list|,
argument|const QModelIndex&destinationParent
argument_list|,
argument|int destinationChild
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
specifier|inline
name|QModelIndex
name|createIndex
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|void *data =
literal|0
argument_list|)
specifier|const
block|{
return|return
name|q_func
argument_list|()
operator|->
name|createIndex
argument_list|(
name|row
argument_list|,
name|column
argument_list|,
name|data
argument_list|)
return|;
block|}
specifier|inline
name|QModelIndex
name|createIndex
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|int id
argument_list|)
specifier|const
block|{
return|return
name|q_func
argument_list|()
operator|->
name|createIndex
argument_list|(
name|row
argument_list|,
name|column
argument_list|,
name|id
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|indexValid
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
return|return
operator|(
name|index
operator|.
name|row
argument_list|()
operator|>=
literal|0
operator|)
operator|&&
operator|(
name|index
operator|.
name|column
argument_list|()
operator|>=
literal|0
operator|)
operator|&&
operator|(
name|index
operator|.
name|model
argument_list|()
operator|==
name|q_func
argument_list|()
operator|)
return|;
block|}
specifier|inline
name|void
name|invalidatePersistentIndexes
argument_list|()
block|{
name|foreach
argument_list|(
argument|QPersistentModelIndexData *data
argument_list|,
argument|persistent.indexes
argument_list|)
block|{
name|data
operator|->
name|index
operator|=
name|QModelIndex
argument_list|()
block|;
name|data
operator|->
name|model
operator|=
literal|0
block|;         }
name|persistent
operator|.
name|indexes
operator|.
name|clear
argument_list|()
block|;     }
comment|/*!       \internal       clean the QPersistentModelIndex relative to the index if there is one.       To be used before an index is invalided       */
specifier|inline
name|void
name|invalidatePersistentIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
block|{
name|QHash
operator|<
name|QModelIndex
block|,
name|QPersistentModelIndexData
operator|*
operator|>
operator|::
name|iterator
name|it
operator|=
name|persistent
operator|.
name|indexes
operator|.
name|find
argument_list|(
name|index
argument_list|)
block|;
if|if
condition|(
name|it
operator|!=
name|persistent
operator|.
name|indexes
operator|.
name|end
argument_list|()
condition|)
block|{
name|QPersistentModelIndexData
modifier|*
name|data
init|=
operator|*
name|it
decl_stmt|;
name|persistent
operator|.
name|indexes
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
name|data
operator|->
name|index
operator|=
name|QModelIndex
argument_list|()
expr_stmt|;
name|data
operator|->
name|model
operator|=
literal|0
expr_stmt|;
block|}
block|}
expr|struct
name|Change
block|{
name|Change
argument_list|()
operator|:
name|first
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|last
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
name|Change
argument_list|(
specifier|const
name|Change
operator|&
name|c
argument_list|)
operator|:
name|parent
argument_list|(
name|c
operator|.
name|parent
argument_list|)
block|,
name|first
argument_list|(
name|c
operator|.
name|first
argument_list|)
block|,
name|last
argument_list|(
name|c
operator|.
name|last
argument_list|)
block|,
name|needsAdjust
argument_list|(
argument|c.needsAdjust
argument_list|)
block|{}
name|Change
argument_list|(
argument|const QModelIndex&p
argument_list|,
argument|int f
argument_list|,
argument|int l
argument_list|)
operator|:
name|parent
argument_list|(
name|p
argument_list|)
block|,
name|first
argument_list|(
name|f
argument_list|)
block|,
name|last
argument_list|(
name|l
argument_list|)
block|,
name|needsAdjust
argument_list|(
argument|false
argument_list|)
block|{}
name|QModelIndex
name|parent
block|;
name|int
name|first
block|,
name|last
block|;
comment|// In cases such as this:
comment|// - A
comment|// - B
comment|// - C
comment|// - - D
comment|// - - E
comment|// - - F
comment|//
comment|// If B is moved to above E, C is the source parent in the signal and its row is 2. When the move is
comment|// completed however, C is at row 1 and there is no row 2 at the same level in the model at all.
comment|// The QModelIndex is adjusted to correct that in those cases before reporting it though the
comment|// rowsMoved signal.
name|bool
name|needsAdjust
block|;
name|bool
name|isValid
argument_list|()
block|{
return|return
name|first
operator|>=
literal|0
operator|&&
name|last
operator|>=
literal|0
return|;
block|}
expr|}
block|;
name|QStack
operator|<
name|Change
operator|>
name|changes
block|;      struct
name|Persistent
block|{
name|Persistent
argument_list|()
block|{}
name|QHash
operator|<
name|QModelIndex
block|,
name|QPersistentModelIndexData
operator|*
operator|>
name|indexes
block|;
name|QStack
operator|<
name|QVector
operator|<
name|QPersistentModelIndexData
operator|*
operator|>
expr|>
name|moved
block|;
name|QStack
operator|<
name|QVector
operator|<
name|QPersistentModelIndexData
operator|*
operator|>
expr|>
name|invalidated
block|;
name|void
name|insertMultiAtEnd
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|key
argument_list|,
name|QPersistentModelIndexData
operator|*
name|data
argument_list|)
block|;     }
name|persistent
block|;
name|Qt
operator|::
name|DropActions
name|supportedDragActions
block|;
name|QHash
operator|<
name|int
block|,
name|QByteArray
operator|>
name|roleNames
block|;
specifier|static
specifier|const
name|QHash
operator|<
name|int
block|,
name|QByteArray
operator|>
operator|&
name|defaultRoleNames
argument_list|()
block|; }
block|;
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QABSTRACTITEMMODEL_P_H
end_comment
end_unit
