begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|namespace
name|QAccessible2
decl_stmt|{     enum CoordinateType
block|{
name|RelativeToScreen
operator|=
literal|0
operator|,
name|RelativeToParent
operator|=
literal|1
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_enum
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
end_enum
begin_decl_stmt
unit|}  class
name|Q_GUI_EXPORT
name|QAccessible2Interface
block|{
name|public
label|:
name|virtual
operator|~
name|QAccessible2Interface
argument_list|()
block|{}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// catch-all functions. If an accessible class doesn't implement interface T, return 0
end_comment
begin_function
DECL|function|qAccessibleValueCastHelper
specifier|inline
name|QAccessible2Interface
modifier|*
name|qAccessibleValueCastHelper
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qAccessibleTextCastHelper
specifier|inline
name|QAccessible2Interface
modifier|*
name|qAccessibleTextCastHelper
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qAccessibleEditableTextCastHelper
specifier|inline
name|QAccessible2Interface
modifier|*
name|qAccessibleEditableTextCastHelper
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qAccessibleTableCastHelper
specifier|inline
name|QAccessible2Interface
modifier|*
name|qAccessibleTableCastHelper
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qAccessibleActionCastHelper
specifier|inline
name|QAccessible2Interface
modifier|*
name|qAccessibleActionCastHelper
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qAccessibleImageCastHelper
specifier|inline
name|QAccessible2Interface
modifier|*
name|qAccessibleImageCastHelper
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_define
DECL|macro|Q_ACCESSIBLE_OBJECT
define|#
directive|define
name|Q_ACCESSIBLE_OBJECT
define|\
value|public: \     QAccessible2Interface *interface_cast(QAccessible2::InterfaceType t) \     { \         switch (t) { \         case QAccessible2::TextInterface: \             return qAccessibleTextCastHelper(); \         case QAccessible2::EditableTextInterface: \             return qAccessibleEditableTextCastHelper(); \         case QAccessible2::ValueInterface: \             return qAccessibleValueCastHelper(); \         case QAccessible2::TableInterface: \             return qAccessibleTableCastHelper(); \         case QAccessible2::ActionInterface: \             return qAccessibleActionCastHelper(); \         case QAccessible2::ImageInterface: \             return qAccessibleImageCastHelper(); \         } \         return 0; \     } \     private:
end_define
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleTextInterface
range|:
name|public
name|QAccessible2Interface
block|{
name|public
operator|:
specifier|inline
name|QAccessible2Interface
operator|*
name|qAccessibleTextCastHelper
argument_list|()
block|{
return|return
name|this
return|;
block|}
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
block|;
name|virtual
name|QString
name|attributes
argument_list|(
argument|int offset
argument_list|,
argument|int *startOffset
argument_list|,
argument|int *endOffset
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|cursorPosition
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|QRect
name|characterRect
argument_list|(
argument|int offset
argument_list|,
argument|QAccessible2::CoordinateType coordType
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|selectionCount
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|offsetAtPoint
argument_list|(
argument|const QPoint&point
argument_list|,
argument|QAccessible2::CoordinateType coordType
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|selection
argument_list|(
argument|int selectionIndex
argument_list|,
argument|int *startOffset
argument_list|,
argument|int *endOffset
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QString
name|text
argument_list|(
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QString
name|textBeforeOffset
argument_list|(
argument|int offset
argument_list|,
argument|QAccessible2::BoundaryType boundaryType
argument_list|,
argument|int *startOffset
argument_list|,
argument|int *endOffset
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QString
name|textAfterOffset
argument_list|(
argument|int offset
argument_list|,
argument|QAccessible2::BoundaryType boundaryType
argument_list|,
argument|int *startOffset
argument_list|,
argument|int *endOffset
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QString
name|textAtOffset
argument_list|(
argument|int offset
argument_list|,
argument|QAccessible2::BoundaryType boundaryType
argument_list|,
argument|int *startOffset
argument_list|,
argument|int *endOffset
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|removeSelection
argument_list|(
argument|int selectionIndex
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setCursorPosition
argument_list|(
argument|int position
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setSelection
argument_list|(
argument|int selectionIndex
argument_list|,
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|characterCount
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|scrollToSubstring
argument_list|(
argument|int startIndex
argument_list|,
argument|int endIndex
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleEditableTextInterface
range|:
name|public
name|QAccessible2Interface
block|{
name|public
operator|:
specifier|inline
name|QAccessible2Interface
operator|*
name|qAccessibleEditableTextCastHelper
argument_list|()
block|{
return|return
name|this
return|;
block|}
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
operator|=
literal|0
block|;
name|virtual
name|void
name|deleteText
argument_list|(
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|insertText
argument_list|(
argument|int offset
argument_list|,
argument|const QString&text
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|cutText
argument_list|(
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|pasteText
argument_list|(
argument|int offset
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|replaceText
argument_list|(
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|,
argument|const QString&text
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setAttributes
argument_list|(
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|,
argument|const QString&attributes
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
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
name|QAccessibleSimpleEditableTextInterface
argument_list|(
name|QAccessibleInterface
operator|*
name|accessibleInterface
argument_list|)
block|;
name|void
name|copyText
argument_list|(
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|)
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
range|:
name|public
name|QAccessible2Interface
block|{
name|public
operator|:
specifier|inline
name|QAccessible2Interface
operator|*
name|qAccessibleValueCastHelper
argument_list|()
block|{
return|return
name|this
return|;
block|}
name|virtual
operator|~
name|QAccessibleValueInterface
argument_list|()
block|{}
name|virtual
name|QVariant
name|currentValue
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|setCurrentValue
argument_list|(
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QVariant
name|maximumValue
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|QVariant
name|minimumValue
argument_list|()
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleTableInterface
range|:
name|public
name|QAccessible2Interface
block|{
name|public
operator|:
specifier|inline
name|QAccessible2Interface
operator|*
name|qAccessibleTableCastHelper
argument_list|()
block|{
return|return
name|this
return|;
block|}
name|virtual
name|QAccessibleInterface
operator|*
name|accessibleAt
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QAccessibleInterface
operator|*
name|caption
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|childIndex
argument_list|(
argument|int rowIndex
argument_list|,
argument|int columnIndex
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QString
name|columnDescription
argument_list|(
argument|int column
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|columnSpan
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QAccessibleInterface
operator|*
name|columnHeader
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|columnIndex
argument_list|(
argument|int childIndex
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|columnCount
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|rowCount
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|selectedColumnCount
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|selectedRowCount
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|QString
name|rowDescription
argument_list|(
argument|int row
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|rowSpan
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QAccessibleInterface
operator|*
name|rowHeader
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|rowIndex
argument_list|(
argument|int childIndex
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|selectedRows
argument_list|(
argument|int maxRows
argument_list|,
argument|QList<int> *rows
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|selectedColumns
argument_list|(
argument|int maxColumns
argument_list|,
argument|QList<int> *columns
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QAccessibleInterface
operator|*
name|summary
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|isColumnSelected
argument_list|(
argument|int column
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isRowSelected
argument_list|(
argument|int row
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isSelected
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|selectRow
argument_list|(
argument|int row
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|selectColumn
argument_list|(
argument|int column
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|unselectRow
argument_list|(
argument|int row
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|unselectColumn
argument_list|(
argument|int column
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|cellAtIndex
argument_list|(
argument|int index
argument_list|,
argument|int *row
argument_list|,
argument|int *column
argument_list|,
argument|int *rowSpan
argument_list|,
argument|int *columnSpan
argument_list|,
argument|bool *isSelected
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleActionInterface
range|:
name|public
name|QAccessible2Interface
block|{
name|public
operator|:
specifier|inline
name|QAccessible2Interface
operator|*
name|qAccessibleActionCastHelper
argument_list|()
block|{
return|return
name|this
return|;
block|}
name|virtual
name|int
name|actionCount
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|doAction
argument_list|(
argument|int actionIndex
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QString
name|description
argument_list|(
argument|int actionIndex
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QString
name|name
argument_list|(
argument|int actionIndex
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QString
name|localizedName
argument_list|(
argument|int actionIndex
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QStringList
name|keyBindings
argument_list|(
argument|int actionIndex
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleImageInterface
range|:
name|public
name|QAccessible2Interface
block|{
name|public
operator|:
specifier|inline
name|QAccessible2Interface
operator|*
name|qAccessibleImageCastHelper
argument_list|()
block|{
return|return
name|this
return|;
block|}
name|virtual
name|QString
name|imageDescription
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|QSize
name|imageSize
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|QRect
name|imagePosition
argument_list|(
argument|QAccessible2::CoordinateType coordType
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
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
