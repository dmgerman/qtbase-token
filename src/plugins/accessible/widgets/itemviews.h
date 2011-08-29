begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ACCESSIBLE_ITEMVIEWS_H
end_ifndef
begin_define
DECL|macro|ACCESSIBLE_ITEMVIEWS_H
define|#
directive|define
name|ACCESSIBLE_ITEMVIEWS_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qabstractitemview.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qheaderview.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qaccessible.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qaccessible2.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qaccessiblewidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
DECL|variable|QAccessibleTable2Cell
name|class
name|QAccessibleTable2Cell
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleTable2HeaderCell
name|class
name|QAccessibleTable2HeaderCell
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleTable2Interface
name|class
name|QAccessibleTable2
range|:
name|public
name|QAccessibleTable2Interface
decl_stmt|,
name|public
name|QAccessibleObject
block|{
name|Q_ACCESSIBLE_OBJECT
name|public
range|:
name|explicit
name|QAccessibleTable2
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
decl_stmt|;
name|virtual
operator|~
name|QAccessibleTable2
argument_list|()
expr_stmt|;
name|QObject
operator|*
name|object
argument_list|()
specifier|const
block|{
return|return
name|view
return|;
block|}
name|Role
name|role
argument_list|(
name|int
name|child
argument_list|)
decl|const
decl_stmt|;
name|State
name|state
argument_list|(
name|int
name|child
argument_list|)
decl|const
decl_stmt|;
name|QString
name|text
argument_list|(
name|Text
name|t
argument_list|,
name|int
name|child
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|rect
argument_list|(
name|int
name|child
argument_list|)
decl|const
decl_stmt|;
name|int
name|childAt
argument_list|(
name|int
name|x
argument_list|,
name|int
name|y
argument_list|)
decl|const
decl_stmt|;
name|int
name|childCount
argument_list|()
specifier|const
expr_stmt|;
name|int
name|indexOfChild
argument_list|(
specifier|const
name|QAccessibleInterface
operator|*
argument_list|)
decl|const
decl_stmt|;
name|int
name|navigate
argument_list|(
name|RelationFlag
name|relation
argument_list|,
name|int
name|index
argument_list|,
name|QAccessibleInterface
operator|*
operator|*
name|iface
argument_list|)
decl|const
decl_stmt|;
name|Relation
name|relationTo
argument_list|(
name|int
name|child
argument_list|,
specifier|const
name|QAccessibleInterface
operator|*
name|other
argument_list|,
name|int
name|otherChild
argument_list|)
decl|const
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_ACTION
name|int
name|userActionCount
argument_list|(
name|int
name|child
argument_list|)
decl|const
decl_stmt|;
name|QString
name|actionText
argument_list|(
name|int
name|action
argument_list|,
name|Text
name|t
argument_list|,
name|int
name|child
argument_list|)
decl|const
decl_stmt|;
name|bool
name|doAction
parameter_list|(
name|int
name|action
parameter_list|,
name|int
name|child
parameter_list|,
specifier|const
name|QVariantList
modifier|&
name|params
parameter_list|)
function_decl|;
endif|#
directive|endif
name|QVariant
name|invokeMethodEx
parameter_list|(
name|Method
parameter_list|,
name|int
parameter_list|,
specifier|const
name|QVariantList
modifier|&
parameter_list|)
block|{
return|return
name|QVariant
argument_list|()
return|;
block|}
comment|// table2 interface
name|virtual
name|QAccessibleTable2CellInterface
modifier|*
name|cellAt
argument_list|(
name|int
name|row
argument_list|,
name|int
name|column
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QAccessibleInterface
operator|*
name|caption
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QAccessibleInterface
operator|*
name|summary
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QString
name|columnDescription
argument_list|(
name|int
name|column
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QString
name|rowDescription
argument_list|(
name|int
name|row
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|int
name|columnCount
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|rowCount
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QAccessible2
operator|::
name|TableModelChange
name|modelChange
argument_list|()
specifier|const
expr_stmt|;
comment|// selection
name|virtual
name|int
name|selectedCellCount
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|selectedColumnCount
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|selectedRowCount
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QList
operator|<
name|QAccessibleTable2CellInterface
operator|*
operator|>
name|selectedCells
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QList
operator|<
name|int
operator|>
name|selectedColumns
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QList
operator|<
name|int
operator|>
name|selectedRows
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|bool
name|isColumnSelected
argument_list|(
name|int
name|column
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|isRowSelected
argument_list|(
name|int
name|row
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|selectRow
parameter_list|(
name|int
name|row
parameter_list|)
function_decl|;
name|virtual
name|bool
name|selectColumn
parameter_list|(
name|int
name|column
parameter_list|)
function_decl|;
name|virtual
name|bool
name|unselectRow
parameter_list|(
name|int
name|row
parameter_list|)
function_decl|;
name|virtual
name|bool
name|unselectColumn
parameter_list|(
name|int
name|column
parameter_list|)
function_decl|;
name|protected
label|:
name|virtual
name|void
name|modelReset
parameter_list|()
function_decl|;
name|virtual
name|void
name|rowsInserted
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
function_decl|;
name|virtual
name|void
name|rowsRemoved
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
function_decl|;
name|virtual
name|void
name|columnsInserted
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
function_decl|;
name|virtual
name|void
name|columnsRemoved
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
function_decl|;
name|virtual
name|void
name|rowsMoved
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|destination
parameter_list|,
name|int
name|row
parameter_list|)
function_decl|;
name|virtual
name|void
name|columnsMoved
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|destination
parameter_list|,
name|int
name|column
parameter_list|)
function_decl|;
name|protected
label|:
name|QAbstractItemView
modifier|*
name|view
decl_stmt|;
name|QAccessible2
operator|::
name|TableModelChange
name|lastChange
expr_stmt|;
specifier|inline
name|QAccessibleTable2Cell
modifier|*
name|cell
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|QAccessible
operator|::
name|Role
name|cellRole
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|m_role
condition|)
block|{
case|case
name|QAccessible
operator|::
name|List
case|:
return|return
name|QAccessible
operator|::
name|ListItem
return|;
case|case
name|QAccessible
operator|::
name|Table
case|:
return|return
name|QAccessible
operator|::
name|Cell
return|;
case|case
name|QAccessible
operator|::
name|Tree
case|:
return|return
name|QAccessible
operator|::
name|TreeItem
return|;
default|default:
name|Q_ASSERT
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
name|QAccessible
operator|::
name|NoRole
return|;
block|}
name|QHeaderView
operator|*
name|horizontalHeader
argument_list|()
specifier|const
expr_stmt|;
name|QHeaderView
operator|*
name|verticalHeader
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|// the child index for a model index
specifier|inline
name|int
name|logicalIndex
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
decl_stmt|;
comment|// the model index from the child index
name|QAccessibleInterface
modifier|*
name|childFromLogical
argument_list|(
name|int
name|logicalIndex
argument_list|)
decl|const
decl_stmt|;
name|QAccessible
operator|::
name|Role
name|m_role
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QAccessibleTree
range|:
name|public
name|QAccessibleTable2
block|{
name|public
operator|:
name|explicit
name|QAccessibleTree
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
operator|:
name|QAccessibleTable2
argument_list|(
argument|w
argument_list|)
block|{}
name|virtual
operator|~
name|QAccessibleTree
argument_list|()
block|{}
name|int
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *
argument_list|)
specifier|const
block|;
name|int
name|rowCount
argument_list|()
specifier|const
block|;
name|int
name|navigate
argument_list|(
argument|RelationFlag relation
argument_list|,
argument|int index
argument_list|,
argument|QAccessibleInterface **iface
argument_list|)
specifier|const
block|;
name|Relation
name|relationTo
argument_list|(
argument|int child
argument_list|,
argument|const QAccessibleInterface *other
argument_list|,
argument|int otherChild
argument_list|)
specifier|const
block|;
comment|// table2 interface
name|QAccessibleTable2CellInterface
operator|*
name|cellAt
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|;
name|QString
name|rowDescription
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|bool
name|isRowSelected
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|bool
name|selectRow
argument_list|(
argument|int row
argument_list|)
block|;
name|private
operator|:
name|QModelIndex
name|indexFromLogical
argument_list|(
argument|int row
argument_list|,
argument|int column =
literal|0
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleTable2Cell
range|:
name|public
name|QAccessibleTable2CellInterface
comment|/*), public QAccessibleTextInterface, public QAccessibleSimpleEditableTextInterface*/
block|{
name|public
operator|:
name|QAccessibleTable2Cell
argument_list|(
argument|QAbstractItemView *view
argument_list|,
argument|const QModelIndex&m_index
argument_list|,
argument|QAccessible::Role role
argument_list|)
block|;
name|QObject
operator|*
name|object
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|Role
name|role
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|State
name|state
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|QRect
name|rect
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|int
name|childAt
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|int
name|childCount
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *
argument_list|)
specifier|const
block|{
return|return
operator|-
literal|1
return|;
block|}
name|QString
name|text
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|void
name|setText
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|int
name|navigate
argument_list|(
argument|RelationFlag relation
argument_list|,
argument|int m_index
argument_list|,
argument|QAccessibleInterface **iface
argument_list|)
specifier|const
block|;
name|Relation
name|relationTo
argument_list|(
argument|int child
argument_list|,
argument|const QAccessibleInterface *other
argument_list|,
argument|int otherChild
argument_list|)
specifier|const
block|;
name|bool
name|isExpandable
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_ACTION
name|int
name|userActionCount
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|QString
name|actionText
argument_list|(
argument|int action
argument_list|,
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|bool
name|doAction
argument_list|(
argument|int action
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params
argument_list|)
block|;
endif|#
directive|endif
comment|// cell interface
name|virtual
name|int
name|columnExtent
argument_list|()
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QAccessibleInterface
operator|*
operator|>
name|columnHeaderCells
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|columnIndex
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|rowExtent
argument_list|()
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QAccessibleInterface
operator|*
operator|>
name|rowHeaderCells
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|rowIndex
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isSelected
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|rowColumnExtents
argument_list|(
argument|int *row
argument_list|,
argument|int *column
argument_list|,
argument|int *rowExtents
argument_list|,
argument|int *columnExtents
argument_list|,
argument|bool *selected
argument_list|)
specifier|const
block|;
name|virtual
name|QAccessibleTable2Interface
operator|*
name|table
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QHeaderView
operator|*
name|verticalHeader
argument_list|()
specifier|const
block|;
name|QHeaderView
operator|*
name|horizontalHeader
argument_list|()
specifier|const
block|;
name|QAbstractItemView
operator|*
name|view
block|;
name|QModelIndex
name|m_index
block|;
name|QAccessible
operator|::
name|Role
name|m_role
block|;
name|friend
name|class
name|QAccessibleTable2
block|;
name|friend
name|class
name|QAccessibleTree
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleTable2HeaderCell
range|:
name|public
name|QAccessibleInterface
comment|/*), public QAccessibleTextInterface, public QAccessibleSimpleEditableTextInterface*/
block|{
name|public
operator|:
comment|// For header cells, pass the header view in addition
name|QAccessibleTable2HeaderCell
argument_list|(
argument|QAbstractItemView *view
argument_list|,
argument|int index
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
name|QObject
operator|*
name|object
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|Role
name|role
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|State
name|state
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|QRect
name|rect
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|int
name|childAt
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|int
name|childCount
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *
argument_list|)
specifier|const
block|{
return|return
operator|-
literal|1
return|;
block|}
name|QString
name|text
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|void
name|setText
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|int
name|navigate
argument_list|(
argument|RelationFlag relation
argument_list|,
argument|int index
argument_list|,
argument|QAccessibleInterface **iface
argument_list|)
specifier|const
block|;
name|Relation
name|relationTo
argument_list|(
argument|int child
argument_list|,
argument|const QAccessibleInterface *other
argument_list|,
argument|int otherChild
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_ACTION
name|int
name|userActionCount
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|QString
name|actionText
argument_list|(
argument|int action
argument_list|,
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|bool
name|doAction
argument_list|(
argument|int action
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params
argument_list|)
block|;
endif|#
directive|endif
name|private
operator|:
name|QAbstractItemView
operator|*
name|view
block|;
name|int
name|index
block|;
name|Qt
operator|::
name|Orientation
name|orientation
block|;
name|friend
name|class
name|QAccessibleTable2
block|;
name|friend
name|class
name|QAccessibleTree
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// This is the corner button on the top left of a table.
end_comment
begin_comment
comment|// It can be used to select all cells or it is not active at all.
end_comment
begin_comment
comment|// For now it is ignored.
end_comment
begin_decl_stmt
name|class
name|QAccessibleTable2CornerButton
range|:
name|public
name|QAccessibleInterface
block|{
name|public
operator|:
name|QAccessibleTable2CornerButton
argument_list|(
name|QAbstractItemView
operator|*
name|view_
argument_list|)
operator|:
name|view
argument_list|(
argument|view_
argument_list|)
block|{}
name|QObject
operator|*
name|object
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|Role
name|role
argument_list|(
argument|int child
argument_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
block|;
return|return
name|QAccessible
operator|::
name|Pane
return|;
block|}
name|State
name|state
argument_list|(
argument|int child
argument_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
block|;
return|return
name|QAccessible
operator|::
name|Normal
return|;
block|}
name|QRect
name|rect
argument_list|(
argument|int child
argument_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
block|;
return|return
name|QRect
argument_list|()
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|int
name|childAt
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|int
name|childCount
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *
argument_list|)
specifier|const
block|{
return|return
operator|-
literal|1
return|;
block|}
name|QString
name|text
argument_list|(
argument|Text
argument_list|,
argument|int
argument_list|)
specifier|const
block|{
return|return
name|QString
argument_list|()
return|;
block|}
name|void
name|setText
argument_list|(
argument|Text
argument_list|,
argument|int
argument_list|,
argument|const QString&
argument_list|)
block|{}
name|int
name|navigate
argument_list|(
argument|RelationFlag relation
argument_list|,
argument|int index
argument_list|,
argument|QAccessibleInterface **iface
argument_list|)
specifier|const
block|{
if|if
condition|(
name|relation
operator|==
name|QAccessible
operator|::
name|Ancestor
operator|&&
name|index
operator|==
literal|1
condition|)
block|{
operator|*
name|iface
operator|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|view
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
name|Relation
name|relationTo
argument_list|(
argument|int
argument_list|,
argument|const QAccessibleInterface *
argument_list|,
argument|int
argument_list|)
specifier|const
block|{
return|return
name|QAccessible
operator|::
name|Unrelated
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_ACTION
name|int
name|userActionCount
argument_list|(
argument|int
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|QString
name|actionText
argument_list|(
argument|int
argument_list|,
argument|Text
argument_list|,
argument|int
argument_list|)
specifier|const
block|{
return|return
name|QString
argument_list|()
return|;
block|}
name|bool
name|doAction
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
argument|const QVariantList&
argument_list|)
block|{
return|return
name|false
return|;
block|}
endif|#
directive|endif
name|private
operator|:
name|QAbstractItemView
operator|*
name|view
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACCESSIBILITY
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ACCESSIBLE_ITEMVIEWS_H
end_comment
end_unit
