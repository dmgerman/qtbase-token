begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qaccessible.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qaccessiblewidget.h>
end_include
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
DECL|variable|QAccessibleTableCell
name|class
name|QAccessibleTableCell
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleTableHeaderCell
name|class
name|QAccessibleTableHeaderCell
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleTableInterface
name|class
name|QAccessibleTable
range|:
name|public
name|QAccessibleTableInterface
decl_stmt|,
name|public
name|QAccessibleObject
block|{
name|public
label|:
name|explicit
name|QAccessibleTable
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
function_decl|;
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QAccessible
operator|::
name|Role
name|role
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QString
name|text
argument_list|(
name|QAccessible
operator|::
name|Text
name|t
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QRect
name|rect
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QAccessibleInterface
modifier|*
name|childAt
argument_list|(
name|int
name|x
argument_list|,
name|int
name|y
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|int
name|childCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|int
name|indexOfChild
argument_list|(
specifier|const
name|QAccessibleInterface
operator|*
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QAccessibleInterface
operator|*
name|parent
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QAccessibleInterface
modifier|*
name|child
argument_list|(
name|int
name|index
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
modifier|*
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|InterfaceType
name|t
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
comment|// table interface
name|virtual
name|QAccessibleInterface
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
name|Q_DECL_OVERRIDE
decl_stmt|;
name|virtual
name|QAccessibleInterface
operator|*
name|caption
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|QAccessibleInterface
operator|*
name|summary
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|QString
name|columnDescription
argument_list|(
name|int
name|column
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|virtual
name|QString
name|rowDescription
argument_list|(
name|int
name|row
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|virtual
name|int
name|columnCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|int
name|rowCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
comment|// selection
name|virtual
name|int
name|selectedCellCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|int
name|selectedColumnCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|int
name|selectedRowCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|QList
operator|<
name|QAccessibleInterface
operator|*
operator|>
name|selectedCells
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|QList
operator|<
name|int
operator|>
name|selectedColumns
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|QList
operator|<
name|int
operator|>
name|selectedRows
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|bool
name|isColumnSelected
argument_list|(
name|int
name|column
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|virtual
name|bool
name|isRowSelected
argument_list|(
name|int
name|row
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|virtual
name|bool
name|selectRow
argument_list|(
name|int
name|row
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|virtual
name|bool
name|selectColumn
argument_list|(
name|int
name|column
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|virtual
name|bool
name|unselectRow
argument_list|(
name|int
name|row
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|virtual
name|bool
name|unselectColumn
argument_list|(
name|int
name|column
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QAbstractItemView
operator|*
name|view
argument_list|()
specifier|const
expr_stmt|;
name|void
name|modelChange
argument_list|(
name|QAccessibleTableModelChangeEvent
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|protected
label|:
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
comment|// maybe vector
typedef|typedef
name|QHash
operator|<
name|int
operator|,
name|QAccessible
operator|::
name|Id
operator|>
name|ChildCache
expr_stmt|;
name|mutable
name|ChildCache
name|childToId
decl_stmt|;
name|virtual
operator|~
name|QAccessibleTable
argument_list|()
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
name|QAccessibleTable
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
name|QAccessibleTable
argument_list|(
argument|w
argument_list|)
block|{}
name|QAccessibleInterface
operator|*
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|childCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|rowCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
comment|// table interface
name|QAccessibleInterface
operator|*
name|cellAt
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|rowDescription
argument_list|(
argument|int row
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isRowSelected
argument_list|(
argument|int row
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|selectRow
argument_list|(
argument|int row
argument_list|)
name|Q_DECL_OVERRIDE
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
block|;
specifier|inline
name|int
name|logicalIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleInterface
DECL|variable|QAccessibleTableCellInterface
name|class
name|QAccessibleTableCell
range|:
name|public
name|QAccessibleInterface
decl_stmt|,
name|public
name|QAccessibleTableCellInterface
decl_stmt|,
name|public
name|QAccessibleActionInterface
block|{
name|public
label|:
name|QAccessibleTableCell
argument_list|(
argument|QAbstractItemView *view
argument_list|,
argument|const QModelIndex&m_index
argument_list|,
argument|QAccessible::Role role
argument_list|)
empty_stmt|;
name|void
modifier|*
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|InterfaceType
name|t
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QObject
operator|*
name|object
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|Q_NULLPTR
return|;
block|}
name|QAccessible
operator|::
name|Role
name|role
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QRect
name|rect
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QAccessibleInterface
modifier|*
name|childAt
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|Q_NULLPTR
return|;
block|}
name|int
name|childCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
literal|0
return|;
block|}
name|int
name|indexOfChild
argument_list|(
specifier|const
name|QAccessibleInterface
operator|*
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
block|{
return|return
operator|-
literal|1
return|;
block|}
name|QString
name|text
argument_list|(
name|QAccessible
operator|::
name|Text
name|t
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setText
argument_list|(
name|QAccessible
operator|::
name|Text
name|t
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QAccessibleInterface
operator|*
name|parent
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QAccessibleInterface
modifier|*
name|child
argument_list|(
name|int
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
comment|// cell interface
name|virtual
name|int
name|columnExtent
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|QList
operator|<
name|QAccessibleInterface
operator|*
operator|>
name|columnHeaderCells
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|int
name|columnIndex
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|int
name|rowExtent
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|QList
operator|<
name|QAccessibleInterface
operator|*
operator|>
name|rowHeaderCells
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|int
name|rowIndex
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|bool
name|isSelected
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|QAccessibleInterface
operator|*
name|table
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
comment|//action interface
name|virtual
name|QStringList
name|actionNames
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|virtual
name|void
name|doAction
argument_list|(
specifier|const
name|QString
operator|&
name|actionName
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|virtual
name|QStringList
name|keyBindingsForAction
argument_list|(
specifier|const
name|QString
operator|&
name|actionName
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|private
label|:
name|QHeaderView
operator|*
name|verticalHeader
argument_list|()
specifier|const
expr_stmt|;
name|QHeaderView
operator|*
name|horizontalHeader
argument_list|()
specifier|const
expr_stmt|;
name|QPointer
operator|<
name|QAbstractItemView
operator|>
name|view
expr_stmt|;
name|QModelIndex
name|m_index
decl_stmt|;
name|QAccessible
operator|::
name|Role
name|m_role
expr_stmt|;
name|void
name|selectCell
parameter_list|()
function_decl|;
name|void
name|unselectCell
parameter_list|()
function_decl|;
name|friend
name|class
name|QAccessibleTable
decl_stmt|;
name|friend
name|class
name|QAccessibleTree
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QAccessibleTableHeaderCell
range|:
name|public
name|QAccessibleInterface
block|{
name|public
operator|:
comment|// For header cells, pass the header view in addition
name|QAccessibleTableHeaderCell
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
name|Q_DECL_OVERRIDE
block|{
return|return
name|Q_NULLPTR
return|;
block|}
name|QAccessible
operator|::
name|Role
name|role
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QRect
name|rect
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QAccessibleInterface
operator|*
name|childAt
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|Q_NULLPTR
return|;
block|}
name|int
name|childCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|{
return|return
operator|-
literal|1
return|;
block|}
name|QString
name|text
argument_list|(
argument|QAccessible::Text t
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setText
argument_list|(
argument|QAccessible::Text t
argument_list|,
argument|const QString&text
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QAccessibleInterface
operator|*
name|parent
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|QHeaderView
operator|*
name|headerView
argument_list|()
specifier|const
block|;
name|QPointer
operator|<
name|QAbstractItemView
operator|>
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
name|QAccessibleTable
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
name|QAccessibleTableCornerButton
range|:
name|public
name|QAccessibleInterface
block|{
name|public
operator|:
name|QAccessibleTableCornerButton
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
name|Q_DECL_OVERRIDE
block|{
return|return
name|Q_NULLPTR
return|;
block|}
name|QAccessible
operator|::
name|Role
name|role
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QAccessible
operator|::
name|Pane
return|;
block|}
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QAccessible
operator|::
name|State
argument_list|()
return|;
block|}
name|QRect
name|rect
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QRect
argument_list|()
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|true
return|;
block|}
name|QAccessibleInterface
operator|*
name|childAt
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|Q_NULLPTR
return|;
block|}
name|int
name|childCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|{
return|return
operator|-
literal|1
return|;
block|}
name|QString
name|text
argument_list|(
argument|QAccessible::Text
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QString
argument_list|()
return|;
block|}
name|void
name|setText
argument_list|(
argument|QAccessible::Text
argument_list|,
argument|const QString&
argument_list|)
name|Q_DECL_OVERRIDE
block|{}
name|QAccessibleInterface
operator|*
name|parent
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|view
argument_list|)
return|;
block|}
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|Q_NULLPTR
return|;
block|}
name|private
operator|:
name|QPointer
operator|<
name|QAbstractItemView
operator|>
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
