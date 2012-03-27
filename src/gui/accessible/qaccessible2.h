begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACCESSIBLE2_H
end_ifndef
begin_define
DECL|macro|QACCESSIBLE2_H
define|#
directive|define
name|QACCESSIBLE2_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qaccessible.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
DECL|variable|QModelIndex
name|class
name|QModelIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QAccessible2
block|{
enum|enum
name|BoundaryType
block|{
name|CharBoundary
block|,
name|WordBoundary
block|,
name|SentenceBoundary
block|,
name|ParagraphBoundary
block|,
name|LineBoundary
block|,
name|NoBoundary
block|}
enum|;
block|}
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleTextInterface
block|{
name|public
label|:
name|virtual
operator|~
name|QAccessibleTextInterface
argument_list|()
block|{}
name|virtual
name|void
name|addSelection
argument_list|(
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|QString
name|attributes
argument_list|(
name|int
name|offset
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|int
name|cursorPosition
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QRect
name|characterRect
argument_list|(
name|int
name|offset
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|int
name|selectionCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|int
name|offsetAtPoint
argument_list|(
specifier|const
name|QPoint
operator|&
name|point
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|selection
argument_list|(
name|int
name|selectionIndex
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|QString
name|text
argument_list|(
name|int
name|startOffset
argument_list|,
name|int
name|endOffset
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|QString
name|textBeforeOffset
argument_list|(
name|int
name|offset
argument_list|,
name|QAccessible2
operator|::
name|BoundaryType
name|boundaryType
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|QString
name|textAfterOffset
argument_list|(
name|int
name|offset
argument_list|,
name|QAccessible2
operator|::
name|BoundaryType
name|boundaryType
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|QString
name|textAtOffset
argument_list|(
name|int
name|offset
argument_list|,
name|QAccessible2
operator|::
name|BoundaryType
name|boundaryType
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|removeSelection
parameter_list|(
name|int
name|selectionIndex
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|setCursorPosition
parameter_list|(
name|int
name|position
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|setSelection
parameter_list|(
name|int
name|selectionIndex
parameter_list|,
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|int
name|characterCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|scrollToSubstring
parameter_list|(
name|int
name|startIndex
parameter_list|,
name|int
name|endIndex
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleEditableTextInterface
block|{
name|public
label|:
name|virtual
operator|~
name|QAccessibleEditableTextInterface
argument_list|()
block|{}
name|virtual
name|void
name|copyText
argument_list|(
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|deleteText
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|insertText
parameter_list|(
name|int
name|offset
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|cutText
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|pasteText
parameter_list|(
name|int
name|offset
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|replaceText
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|setAttributes
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|,
specifier|const
name|QString
modifier|&
name|attributes
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleSimpleEditableTextInterface
range|:
name|public
name|QAccessibleEditableTextInterface
block|{
name|public
operator|:
name|explicit
name|QAccessibleSimpleEditableTextInterface
argument_list|(
name|QAccessibleInterface
operator|*
name|accessibleInterface
argument_list|)
block|;
comment|//###
name|void
name|copyText
argument_list|(
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|)
specifier|const
block|;
name|void
name|deleteText
argument_list|(
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|)
block|;
name|void
name|insertText
argument_list|(
argument|int offset
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|void
name|cutText
argument_list|(
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|)
block|;
name|void
name|pasteText
argument_list|(
argument|int offset
argument_list|)
block|;
name|void
name|replaceText
argument_list|(
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|,
argument|const QString&text
argument_list|)
block|;
specifier|inline
name|void
name|setAttributes
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
argument|const QString&
argument_list|)
block|{}
name|private
operator|:
name|QAccessibleInterface
operator|*
name|iface
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleValueInterface
block|{
name|public
label|:
name|virtual
operator|~
name|QAccessibleValueInterface
argument_list|()
block|{}
name|virtual
name|QVariant
name|currentValue
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setCurrentValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QVariant
name|maximumValue
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QVariant
name|minimumValue
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleTableCellInterface
block|{
name|public
label|:
name|virtual
operator|~
name|QAccessibleTableCellInterface
argument_list|()
block|{}
comment|//            Returns the number of columns occupied by this cell accessible.
name|virtual
name|int
name|columnExtent
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//            Returns the column headers as an array of cell accessibles.
name|virtual
name|QList
operator|<
name|QAccessibleInterface
operator|*
operator|>
name|columnHeaderCells
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//            Translates this cell accessible into the corresponding column index.
name|virtual
name|int
name|columnIndex
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//            Returns the number of rows occupied by this cell accessible.
name|virtual
name|int
name|rowExtent
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//            Returns the row headers as an array of cell accessibles.
name|virtual
name|QList
operator|<
name|QAccessibleInterface
operator|*
operator|>
name|rowHeaderCells
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//            Translates this cell accessible into the corresponding row index.
name|virtual
name|int
name|rowIndex
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//            Returns a boolean value indicating whether this cell is selected.
name|virtual
name|bool
name|isSelected
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//            Gets the row and column indexes and extents of this cell accessible and whether or not it is selected.
comment|//          ### Is this really needed??
comment|//
comment|//          ### Maybe change to QSize cellSize(), we already have accessors for the row, column and selected
name|virtual
name|void
name|rowColumnExtents
argument_list|(
name|int
operator|*
name|row
argument_list|,
name|int
operator|*
name|column
argument_list|,
name|int
operator|*
name|rowExtents
argument_list|,
name|int
operator|*
name|columnExtents
argument_list|,
name|bool
operator|*
name|selected
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|//            Returns a reference to the accessbile of the containing table.
name|virtual
name|QAccessibleInterface
operator|*
name|table
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleTableInterface
block|{
name|public
label|:
name|virtual
operator|~
name|QAccessibleTableInterface
argument_list|()
block|{}
comment|// Returns the cell at the specified row and column in the table.
name|virtual
name|QAccessibleInterface
operator|*
name|cellAt
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns the caption for the table.
name|virtual
name|QAccessibleInterface
operator|*
name|caption
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns the description text of the specified column in the table.
name|virtual
name|QString
name|columnDescription
argument_list|(
name|int
name|column
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// Returns the total number of columns in table.
name|virtual
name|int
name|columnCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns the total number of rows in table.
name|virtual
name|int
name|rowCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns the total number of selected cells.
name|virtual
name|int
name|selectedCellCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns the total number of selected columns.
name|virtual
name|int
name|selectedColumnCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns the total number of selected rows.
name|virtual
name|int
name|selectedRowCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns the description text of the specified row in the table.
name|virtual
name|QString
name|rowDescription
argument_list|(
name|int
name|row
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// Returns a list of accessibles currently selected.
name|virtual
name|QList
operator|<
name|QAccessibleInterface
operator|*
operator|>
name|selectedCells
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns a list of column indexes currently selected (0 based).
name|virtual
name|QList
operator|<
name|int
operator|>
name|selectedColumns
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns a list of row indexes currently selected (0 based).
name|virtual
name|QList
operator|<
name|int
operator|>
name|selectedRows
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns the summary description of the table.
name|virtual
name|QAccessibleInterface
operator|*
name|summary
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns a boolean value indicating whether the specified column is completely selected.
name|virtual
name|bool
name|isColumnSelected
argument_list|(
name|int
name|column
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// Returns a boolean value indicating whether the specified row is completely selected.
name|virtual
name|bool
name|isRowSelected
argument_list|(
name|int
name|row
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// Selects a row and unselects all previously selected rows.
name|virtual
name|bool
name|selectRow
parameter_list|(
name|int
name|row
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Selects a column and unselects all previously selected columns.
name|virtual
name|bool
name|selectColumn
parameter_list|(
name|int
name|column
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Unselects one row, leaving other selected rows selected (if any).
name|virtual
name|bool
name|unselectRow
parameter_list|(
name|int
name|row
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Unselects one column, leaving other selected columns selected (if any).
name|virtual
name|bool
name|unselectColumn
parameter_list|(
name|int
name|column
parameter_list|)
init|=
literal|0
function_decl|;
name|protected
label|:
name|friend
name|class
name|QAbstractItemView
decl_stmt|;
name|friend
name|class
name|QAbstractItemViewPrivate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleActionInterface
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QAccessibleActionInterface
argument_list|)
name|public
label|:
name|virtual
operator|~
name|QAccessibleActionInterface
argument_list|()
block|{}
name|virtual
name|QStringList
name|actionNames
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QString
name|localizedActionName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QString
name|localizedActionDescription
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|doAction
parameter_list|(
specifier|const
name|QString
modifier|&
name|actionName
parameter_list|)
init|=
literal|0
function_decl|;
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
init|=
literal|0
decl_stmt|;
specifier|static
specifier|const
name|QString
modifier|&
name|pressAction
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|QString
modifier|&
name|increaseAction
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|QString
modifier|&
name|decreaseAction
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|QString
modifier|&
name|showMenuAction
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|QString
modifier|&
name|setFocusAction
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|QString
modifier|&
name|checkAction
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|QString
modifier|&
name|uncheckAction
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleImageInterface
block|{
name|public
label|:
name|virtual
operator|~
name|QAccessibleImageInterface
argument_list|()
block|{}
name|virtual
name|QString
name|imageDescription
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QSize
name|imageSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QRect
name|imagePosition
argument_list|()
specifier|const
operator|=
literal|0
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
comment|// QT_NO_ACCESSIBILITY
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
