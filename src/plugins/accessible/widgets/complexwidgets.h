begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPLEXWIDGETS_H
end_ifndef
begin_define
DECL|macro|COMPLEXWIDGETS_H
define|#
directive|define
name|COMPLEXWIDGETS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
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
file|<QtGui/qaccessible2.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
DECL|variable|QAbstractButton
name|class
name|QAbstractButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHeaderView
name|class
name|QHeaderView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTabBar
name|class
name|QTabBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QComboBox
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTitleBar
name|class
name|QTitleBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractScrollArea
name|class
name|QAbstractScrollArea
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollArea
name|class
name|QScrollArea
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SCROLLAREA
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleAbstractScrollArea
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleAbstractScrollArea
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;      enum
name|AbstractScrollAreaElement
block|{
name|Self
operator|=
literal|0
block|,
name|Viewport
block|,
name|HorizontalContainer
block|,
name|VerticalContainer
block|,
name|CornerWidget
block|,
name|Undefined
block|}
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|QVariant
name|invokeMethod
argument_list|(
argument|QAccessible::Method method
argument_list|,
argument|int
argument_list|,
argument|const QVariantList&params
argument_list|)
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|int
name|navigate
argument_list|(
argument|RelationFlag relation
argument_list|,
argument|int entry
argument_list|,
argument|QAccessibleInterface **target
argument_list|)
specifier|const
block|;
comment|//    int childAt(int x, int y) const;
comment|//protected:
name|QAbstractScrollArea
operator|*
name|abstractScrollArea
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QWidgetList
name|accessibleChildren
argument_list|()
specifier|const
block|;
name|AbstractScrollAreaElement
name|elementType
argument_list|(
argument|QWidget *widget
argument_list|)
specifier|const
block|;
name|bool
name|isLeftToRight
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleScrollArea
range|:
name|public
name|QAccessibleAbstractScrollArea
block|{
name|public
operator|:
name|explicit
name|QAccessibleScrollArea
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SCROLLAREA
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleHeader
range|:
name|public
name|QAccessibleWidget
block|{
name|Q_ACCESSIBLE_OBJECT
name|public
operator|:
name|explicit
name|QAccessibleHeader
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|QRect
name|rect
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
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
name|protected
operator|:
name|QHeaderView
operator|*
name|header
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleItemRow
range|:
name|public
name|QAccessibleInterface
block|{
name|friend
name|class
name|QAccessibleItemView
block|;
name|public
operator|:
name|QAccessibleItemRow
argument_list|(
argument|QAbstractItemView *view
argument_list|,
argument|const QModelIndex&index = QModelIndex()
argument_list|,
argument|bool isHeader = false
argument_list|)
block|;
name|QRect
name|rect
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
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
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|QObject
operator|*
name|object
argument_list|()
specifier|const
block|;
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
name|QList
operator|<
name|QModelIndex
operator|>
name|children
argument_list|()
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
name|int
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|parent
argument_list|()
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
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
argument|const QVariantList&params = QVariantList()
argument_list|)
block|;
name|QModelIndex
name|childIndex
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|QHeaderView
operator|*
name|horizontalHeader
argument_list|()
specifier|const
block|;
comment|//used by QAccessibleItemView
name|private
operator|:
specifier|static
name|QAbstractItemView
operator|::
name|CursorAction
name|toCursorAction
argument_list|(
argument|Relation rel
argument_list|)
block|;
name|int
name|logicalFromChild
argument_list|(
argument|QHeaderView *header
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|int
name|treeLevel
argument_list|()
specifier|const
block|;
name|QHeaderView
operator|*
name|verticalHeader
argument_list|()
specifier|const
block|;
name|QString
name|text_helper
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|QPersistentModelIndex
name|row
block|;
name|QPointer
operator|<
name|QAbstractItemView
operator|>
name|view
block|;
name|bool
name|m_header
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleAbstractScrollArea
name|class
name|QAccessibleItemView
range|:
name|public
name|QAccessibleAbstractScrollArea
decl_stmt|,
name|public
name|QAccessibleTableInterface
block|{
name|Q_ACCESSIBLE_OBJECT
name|public
range|:
name|explicit
name|QAccessibleItemView
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
decl_stmt|;
name|QObject
operator|*
name|object
argument_list|()
specifier|const
expr_stmt|;
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
name|void
name|setText
parameter_list|(
name|Text
name|t
parameter_list|,
name|int
name|child
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|int
name|indexOfChild
argument_list|(
specifier|const
name|QAccessibleInterface
operator|*
name|iface
argument_list|)
decl|const
decl_stmt|;
name|QModelIndex
name|childIndex
argument_list|(
name|int
name|child
argument_list|)
decl|const
decl_stmt|;
name|int
name|entryFromIndex
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
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
name|QAccessibleInterface
modifier|*
name|accessibleAt
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|)
function_decl|;
name|QAccessibleInterface
modifier|*
name|caption
parameter_list|()
function_decl|;
name|int
name|childIndex
parameter_list|(
name|int
name|rowIndex
parameter_list|,
name|int
name|columnIndex
parameter_list|)
function_decl|;
name|QString
name|columnDescription
parameter_list|(
name|int
name|column
parameter_list|)
function_decl|;
name|int
name|columnSpan
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|)
function_decl|;
name|QAccessibleInterface
modifier|*
name|columnHeader
parameter_list|()
function_decl|;
name|int
name|columnIndex
parameter_list|(
name|int
name|childIndex
parameter_list|)
function_decl|;
name|int
name|columnCount
parameter_list|()
function_decl|;
name|int
name|rowCount
parameter_list|()
function_decl|;
name|int
name|selectedColumnCount
parameter_list|()
function_decl|;
name|int
name|selectedRowCount
parameter_list|()
function_decl|;
name|QString
name|rowDescription
parameter_list|(
name|int
name|row
parameter_list|)
function_decl|;
name|int
name|rowSpan
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|)
function_decl|;
name|QAccessibleInterface
modifier|*
name|rowHeader
parameter_list|()
function_decl|;
name|int
name|rowIndex
parameter_list|(
name|int
name|childIndex
parameter_list|)
function_decl|;
name|int
name|selectedRows
argument_list|(
name|int
name|maxRows
argument_list|,
name|QList
operator|<
name|int
operator|>
operator|*
name|rows
argument_list|)
decl_stmt|;
name|int
name|selectedColumns
argument_list|(
name|int
name|maxColumns
argument_list|,
name|QList
operator|<
name|int
operator|>
operator|*
name|columns
argument_list|)
decl_stmt|;
name|QAccessibleInterface
modifier|*
name|summary
parameter_list|()
function_decl|;
name|bool
name|isColumnSelected
parameter_list|(
name|int
name|column
parameter_list|)
function_decl|;
name|bool
name|isRowSelected
parameter_list|(
name|int
name|row
parameter_list|)
function_decl|;
name|bool
name|isSelected
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|)
function_decl|;
name|void
name|selectRow
parameter_list|(
name|int
name|row
parameter_list|)
function_decl|;
name|void
name|selectColumn
parameter_list|(
name|int
name|column
parameter_list|)
function_decl|;
name|void
name|unselectRow
parameter_list|(
name|int
name|row
parameter_list|)
function_decl|;
name|void
name|unselectColumn
parameter_list|(
name|int
name|column
parameter_list|)
function_decl|;
name|void
name|cellAtIndex
parameter_list|(
name|int
name|index
parameter_list|,
name|int
modifier|*
name|row
parameter_list|,
name|int
modifier|*
name|column
parameter_list|,
name|int
modifier|*
name|rowSpan
parameter_list|,
name|int
modifier|*
name|columnSpan
parameter_list|,
name|bool
modifier|*
name|isSelected
parameter_list|)
function_decl|;
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
name|bool
name|isValidChildRole
argument_list|(
name|QAccessible
operator|::
name|Role
name|role
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|QAbstractItemView
operator|*
name|itemView
argument_list|()
specifier|const
expr_stmt|;
name|QModelIndex
name|index
argument_list|(
name|int
name|row
argument_list|,
name|int
name|column
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
specifier|inline
name|bool
name|atViewport
argument_list|()
specifier|const
block|{
return|return
name|atVP
return|;
block|}
empty_stmt|;
name|QAccessible
operator|::
name|Role
name|expectedRoleOfChildren
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|atVP
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleTabBar
range|:
name|public
name|QAccessibleWidget
block|{
name|Q_ACCESSIBLE_OBJECT
name|public
operator|:
name|explicit
name|QAccessibleTabBar
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|bool
name|setSelected
argument_list|(
argument|int child
argument_list|,
argument|bool on
argument_list|,
argument|bool extend
argument_list|)
block|;
name|QVector
operator|<
name|int
operator|>
name|selection
argument_list|()
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|int
name|navigate
argument_list|(
argument|RelationFlag rel
argument_list|,
argument|int entry
argument_list|,
argument|QAccessibleInterface **target
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QTabBar
operator|*
name|tabBar
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABBAR
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COMBOBOX
end_ifndef
begin_decl_stmt
DECL|variable|QAccessibleWidget
name|class
name|QAccessibleComboBox
range|:
name|public
name|QAccessibleWidget
decl_stmt|,
name|public
name|QAccessibleActionInterface
block|{
name|Q_ACCESSIBLE_OBJECT
name|public
range|:
name|explicit
name|QAccessibleComboBox
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
decl_stmt|;
name|int
name|childCount
argument_list|()
specifier|const
expr_stmt|;
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
name|indexOfChild
argument_list|(
specifier|const
name|QAccessibleInterface
operator|*
name|child
argument_list|)
decl|const
decl_stmt|;
name|QAccessibleInterface
modifier|*
name|child
argument_list|(
name|int
name|index
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
comment|// QAccessibleActionInterface
name|QStringList
name|actionNames
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|localizedActionDescription
argument_list|(
specifier|const
name|QString
operator|&
name|actionName
argument_list|)
decl|const
decl_stmt|;
name|void
name|doAction
parameter_list|(
specifier|const
name|QString
modifier|&
name|actionName
parameter_list|)
function_decl|;
name|QStringList
name|keyBindingsForAction
argument_list|(
specifier|const
name|QString
operator|&
name|actionName
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|QComboBox
operator|*
name|comboBox
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COMBOBOX
end_comment
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
comment|// COMPLEXWIDGETS_H
end_comment
end_unit
