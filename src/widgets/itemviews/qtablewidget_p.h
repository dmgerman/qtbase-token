begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTABLEWIDGET_P_H
end_ifndef
begin_define
DECL|macro|QTABLEWIDGET_P_H
define|#
directive|define
name|QTABLEWIDGET_P_H
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
comment|// This file is not part of the Qt API. This header file may change
end_comment
begin_comment
comment|// from version to version without notice, or even be removed.
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
begin_include
include|#
directive|include
file|<qheaderview.h>
end_include
begin_include
include|#
directive|include
file|<qtablewidget.h>
end_include
begin_include
include|#
directive|include
file|<qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<private/qabstractitemmodel_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qtableview_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qwidgetitemdata_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABLEWIDGET
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// workaround for VC++ 6.0 linker bug
end_comment
begin_typedef
DECL|typedef|LessThan
typedef|typedef
name|bool
argument_list|(
operator|*
name|LessThan
argument_list|)
argument_list|(
specifier|const
name|QPair
operator|<
name|QTableWidgetItem
operator|*
argument_list|,
name|int
operator|>
operator|&
argument_list|,
specifier|const
name|QPair
operator|<
name|QTableWidgetItem
operator|*
argument_list|,
name|int
operator|>
operator|&
argument_list|)
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QTableWidgetMimeData
range|:
name|public
name|QMimeData
block|{
name|Q_OBJECT
name|public
operator|:
name|QList
operator|<
name|QTableWidgetItem
operator|*
operator|>
name|items
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTableModelLessThan
block|{
name|public
label|:
specifier|inline
name|bool
name|operator
argument_list|()
operator|(
name|QTableWidgetItem
operator|*
name|i1
operator|,
name|QTableWidgetItem
operator|*
name|i2
operator|)
specifier|const
block|{
return|return
operator|(
operator|*
name|i1
operator|<
operator|*
name|i2
operator|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QTableModelGreaterThan
block|{
name|public
label|:
specifier|inline
name|bool
name|operator
argument_list|()
operator|(
name|QTableWidgetItem
operator|*
name|i1
operator|,
name|QTableWidgetItem
operator|*
name|i2
operator|)
specifier|const
block|{
return|return
operator|(
operator|*
name|i2
operator|<
operator|*
name|i1
operator|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QTableModel
range|:
name|public
name|QAbstractTableModel
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|ItemFlagsExtension
block|{
name|ItemIsHeaderItem
operator|=
literal|128
block|}
block|;
comment|// we need this to separate header items from other items
name|QTableModel
argument_list|(
argument|int rows
argument_list|,
argument|int columns
argument_list|,
argument|QTableWidget *parent
argument_list|)
block|;
operator|~
name|QTableModel
argument_list|()
block|;
name|bool
name|insertRows
argument_list|(
argument|int row
argument_list|,
argument|int count =
literal|1
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|bool
name|insertColumns
argument_list|(
argument|int column
argument_list|,
argument|int count =
literal|1
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|bool
name|removeRows
argument_list|(
argument|int row
argument_list|,
argument|int count =
literal|1
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|bool
name|removeColumns
argument_list|(
argument|int column
argument_list|,
argument|int count =
literal|1
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|void
name|setItem
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|QTableWidgetItem *item
argument_list|)
block|;
name|QTableWidgetItem
operator|*
name|takeItem
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
block|;
name|QTableWidgetItem
operator|*
name|item
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|;
name|QTableWidgetItem
operator|*
name|item
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|removeItem
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|setHorizontalHeaderItem
argument_list|(
argument|int section
argument_list|,
argument|QTableWidgetItem *item
argument_list|)
block|;
name|void
name|setVerticalHeaderItem
argument_list|(
argument|int section
argument_list|,
argument|QTableWidgetItem *item
argument_list|)
block|;
name|QTableWidgetItem
operator|*
name|takeHorizontalHeaderItem
argument_list|(
argument|int section
argument_list|)
block|;
name|QTableWidgetItem
operator|*
name|takeVerticalHeaderItem
argument_list|(
argument|int section
argument_list|)
block|;
name|QTableWidgetItem
operator|*
name|horizontalHeaderItem
argument_list|(
argument|int section
argument_list|)
block|;
name|QTableWidgetItem
operator|*
name|verticalHeaderItem
argument_list|(
argument|int section
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
block|{
return|return
name|QAbstractTableModel
operator|::
name|index
argument_list|(
name|row
argument_list|,
name|column
argument_list|,
name|parent
argument_list|)
return|;
block|}
name|QModelIndex
name|index
argument_list|(
argument|const QTableWidgetItem *item
argument_list|)
specifier|const
block|;
name|void
name|setRowCount
argument_list|(
argument|int rows
argument_list|)
block|;
name|void
name|setColumnCount
argument_list|(
argument|int columns
argument_list|)
block|;
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|int
name|columnCount
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
argument|int role
argument_list|)
block|;
name|bool
name|setItemData
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|,
specifier|const
name|QMap
operator|<
name|int
argument_list|,
name|QVariant
operator|>
operator|&
name|roles
argument_list|)
block|;
name|QMap
operator|<
name|int
block|,
name|QVariant
operator|>
name|itemData
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QVariant
name|headerData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|int role
argument_list|)
specifier|const
block|;
name|bool
name|setHeaderData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int role
argument_list|)
block|;
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|sort
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order
argument_list|)
block|;
specifier|static
name|bool
name|itemLessThan
argument_list|(
specifier|const
name|QPair
operator|<
name|QTableWidgetItem
operator|*
argument_list|,
name|int
operator|>
operator|&
name|left
argument_list|,
specifier|const
name|QPair
operator|<
name|QTableWidgetItem
operator|*
argument_list|,
name|int
operator|>
operator|&
name|right
argument_list|)
block|;
specifier|static
name|bool
name|itemGreaterThan
argument_list|(
specifier|const
name|QPair
operator|<
name|QTableWidgetItem
operator|*
argument_list|,
name|int
operator|>
operator|&
name|left
argument_list|,
specifier|const
name|QPair
operator|<
name|QTableWidgetItem
operator|*
argument_list|,
name|int
operator|>
operator|&
name|right
argument_list|)
block|;
name|void
name|ensureSorted
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|QVector
operator|<
name|QTableWidgetItem
operator|*
operator|>
name|columnItems
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|updateRowIndexes
argument_list|(
argument|QModelIndexList&indexes
argument_list|,
argument|int movedFromRow
argument_list|,
argument|int movedToRow
argument_list|)
block|;
specifier|static
name|QVector
operator|<
name|QTableWidgetItem
operator|*
operator|>
operator|::
name|iterator
name|sortedInsertionIterator
argument_list|(
argument|const QVector<QTableWidgetItem*>::iterator&begin
argument_list|,
argument|const QVector<QTableWidgetItem*>::iterator&end
argument_list|,
argument|Qt::SortOrder order
argument_list|,
argument|QTableWidgetItem *item
argument_list|)
block|;
name|bool
name|isValid
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
specifier|inline
name|long
name|tableIndex
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|{
return|return
operator|(
name|row
operator|*
name|horizontalHeaderItems
operator|.
name|count
argument_list|()
operator|)
operator|+
name|column
return|;
block|}
name|void
name|clear
argument_list|()
block|;
name|void
name|clearContents
argument_list|()
block|;
name|void
name|itemChanged
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|QTableWidgetItem
operator|*
name|createItem
argument_list|()
specifier|const
block|;
specifier|const
name|QTableWidgetItem
operator|*
name|itemPrototype
argument_list|()
specifier|const
block|;
name|void
name|setItemPrototype
argument_list|(
specifier|const
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
comment|// dnd
name|QStringList
name|mimeTypes
argument_list|()
specifier|const
block|;
name|QMimeData
operator|*
name|mimeData
argument_list|(
argument|const QModelIndexList&indexes
argument_list|)
specifier|const
block|;
name|bool
name|dropMimeData
argument_list|(
argument|const QMimeData *data
argument_list|,
argument|Qt::DropAction action
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex&parent
argument_list|)
block|;
name|Qt
operator|::
name|DropActions
name|supportedDropActions
argument_list|()
specifier|const
block|;
name|QMimeData
operator|*
name|internalMimeData
argument_list|()
specifier|const
block|;
name|private
operator|:
specifier|const
name|QTableWidgetItem
operator|*
name|prototype
block|;
name|QVector
operator|<
name|QTableWidgetItem
operator|*
operator|>
name|tableItems
block|;
name|QVector
operator|<
name|QTableWidgetItem
operator|*
operator|>
name|verticalHeaderItems
block|;
name|QVector
operator|<
name|QTableWidgetItem
operator|*
operator|>
name|horizontalHeaderItems
block|;
comment|// A cache must be mutable if get-functions should have const modifiers
name|mutable
name|QModelIndexList
name|cachedIndexes
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTableWidgetPrivate
range|:
name|public
name|QTableViewPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTableWidget
argument_list|)
name|public
operator|:
name|QTableWidgetPrivate
argument_list|()
operator|:
name|QTableViewPrivate
argument_list|()
block|{}
specifier|inline
name|QTableModel
operator|*
name|tableModel
argument_list|()
specifier|const
block|{
return|return
name|qobject_cast
operator|<
name|QTableModel
operator|*
operator|>
operator|(
name|model
operator|)
return|;
block|}
name|void
name|setup
argument_list|()
block|;
comment|// view signals
name|void
name|_q_emitItemPressed
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|_q_emitItemClicked
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|_q_emitItemDoubleClicked
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|_q_emitItemActivated
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|_q_emitItemEntered
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
comment|// model signals
name|void
name|_q_emitItemChanged
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
comment|// selection signals
name|void
name|_q_emitCurrentItemChanged
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|previous
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|current
argument_list|)
block|;
comment|// sorting
name|void
name|_q_sort
argument_list|()
block|;
name|void
name|_q_dataChanged
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|topLeft
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|bottomRight
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTableWidgetItemPrivate
block|{
name|public
label|:
name|QTableWidgetItemPrivate
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
operator|:
name|q
argument_list|(
name|item
argument_list|)
operator|,
name|id
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
name|QTableWidgetItem
operator|*
name|q
expr_stmt|;
name|int
name|id
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABLEWIDGET
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTABLEWIDGET_P_H
end_comment
end_unit
