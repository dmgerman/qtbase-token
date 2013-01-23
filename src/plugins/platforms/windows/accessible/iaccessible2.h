begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|IACCESSIBLE2_H
end_ifndef
begin_define
DECL|macro|IACCESSIBLE2_H
define|#
directive|define
name|IACCESSIBLE2_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QtConfig>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|"qwindowsmsaaaccessible.h"
end_include
begin_include
include|#
directive|include
file|"comutils.h"
end_include
begin_include
include|#
directive|include
file|"Accessible2.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleAction.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleApplication.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleComponent.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleEditableText.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleHyperlink.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleHypertext.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleImage.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleRelation.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleTable.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleTable2.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleTableCell.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleText.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleValue.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleEventID.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleRole.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleStates.h"
end_include
begin_include
include|#
directive|include
file|<servprov.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowsMsaaAccessible
name|class
name|QWindowsIA2Accessible
range|:
name|public
name|QWindowsMsaaAccessible
decl_stmt|,
DECL|variable|IAccessibleAction
name|public
name|IAccessibleAction
decl_stmt|,
DECL|variable|IAccessibleComponent
name|public
name|IAccessibleComponent
decl_stmt|,
DECL|variable|IAccessibleEditableText
name|public
name|IAccessibleEditableText
decl_stmt|,
DECL|variable|IAccessibleTable2
name|public
name|IAccessibleTable2
decl_stmt|,
DECL|variable|IAccessibleTableCell
name|public
name|IAccessibleTableCell
decl_stmt|,
DECL|variable|IAccessibleText
name|public
name|IAccessibleText
decl_stmt|,
DECL|variable|IAccessibleValue
name|public
name|IAccessibleValue
decl_stmt|,
name|public
name|IServiceProvider
block|{
name|public
label|:
name|QWindowsIA2Accessible
argument_list|(
name|QAccessibleInterface
operator|*
name|a
argument_list|)
operator|:
name|QWindowsMsaaAccessible
argument_list|(
argument|a
argument_list|)
block|{}
comment|/* IUnknown */
name|HRESULT
name|STDMETHODCALLTYPE
name|QueryInterface
argument_list|(
name|REFIID
argument_list|,
name|LPVOID
operator|*
argument_list|)
expr_stmt|;
name|ULONG
name|STDMETHODCALLTYPE
name|AddRef
parameter_list|()
function_decl|;
name|ULONG
name|STDMETHODCALLTYPE
name|Release
parameter_list|()
function_decl|;
comment|/* IAccessible2 */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nRelations
parameter_list|(
name|long
modifier|*
name|nRelations
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_relation
parameter_list|(
name|long
name|relationIndex
parameter_list|,
name|IAccessibleRelation
modifier|*
modifier|*
name|relation
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_relations
parameter_list|(
name|long
name|maxRelations
parameter_list|,
name|IAccessibleRelation
modifier|*
modifier|*
name|relations
parameter_list|,
name|long
modifier|*
name|nRelations
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|role
parameter_list|(
name|long
modifier|*
name|role
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|scrollTo
parameter_list|(
name|enum
name|IA2ScrollType
name|scrollType
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|scrollToPoint
parameter_list|(
name|enum
name|IA2CoordinateType
name|coordinateType
parameter_list|,
name|long
name|x
parameter_list|,
name|long
name|y
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_groupPosition
parameter_list|(
name|long
modifier|*
name|groupLevel
parameter_list|,
name|long
modifier|*
name|similarItemsInGroup
parameter_list|,
name|long
modifier|*
name|positionInGroup
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_states
parameter_list|(
name|AccessibleStates
modifier|*
name|states
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_extendedRole
parameter_list|(
name|BSTR
modifier|*
name|extendedRole
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_localizedExtendedRole
parameter_list|(
name|BSTR
modifier|*
name|localizedExtendedRole
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nExtendedStates
parameter_list|(
name|long
modifier|*
name|nExtendedStates
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_extendedStates
parameter_list|(
name|long
name|maxExtendedStates
parameter_list|,
name|BSTR
modifier|*
modifier|*
name|extendedStates
parameter_list|,
name|long
modifier|*
name|nExtendedStates
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_localizedExtendedStates
parameter_list|(
name|long
name|maxLocalizedExtendedStates
parameter_list|,
name|BSTR
modifier|*
modifier|*
name|localizedExtendedStates
parameter_list|,
name|long
modifier|*
name|nLocalizedExtendedStates
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_uniqueID
parameter_list|(
name|long
modifier|*
name|uniqueID
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_windowHandle
parameter_list|(
name|HWND
modifier|*
name|windowHandle
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_indexInParent
parameter_list|(
name|long
modifier|*
name|indexInParent
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_locale
parameter_list|(
name|IA2Locale
modifier|*
name|locale
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_attributes
parameter_list|(
name|BSTR
modifier|*
name|attributes
parameter_list|)
function_decl|;
comment|/* IAccessibleAction */
name|HRESULT
name|STDMETHODCALLTYPE
name|nActions
parameter_list|(
name|long
modifier|*
name|nActions
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|doAction
parameter_list|(
name|long
name|actionIndex
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_description
parameter_list|(
name|long
name|actionIndex
parameter_list|,
name|BSTR
modifier|*
name|description
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_keyBinding
parameter_list|(
name|long
name|actionIndex
parameter_list|,
name|long
name|nMaxBindings
parameter_list|,
name|BSTR
modifier|*
modifier|*
name|keyBindings
parameter_list|,
name|long
modifier|*
name|nBindings
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_name
parameter_list|(
name|long
name|actionIndex
parameter_list|,
name|BSTR
modifier|*
name|name
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_localizedName
parameter_list|(
name|long
name|actionIndex
parameter_list|,
name|BSTR
modifier|*
name|localizedName
parameter_list|)
function_decl|;
comment|/* IAccessibleComponent */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_locationInParent
parameter_list|(
name|long
modifier|*
name|x
parameter_list|,
name|long
modifier|*
name|y
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_foreground
parameter_list|(
name|IA2Color
modifier|*
name|foreground
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_background
parameter_list|(
name|IA2Color
modifier|*
name|background
parameter_list|)
function_decl|;
comment|/* IAccessibleEditableText */
name|HRESULT
name|STDMETHODCALLTYPE
name|copyText
parameter_list|(
name|long
name|startOffset
parameter_list|,
name|long
name|endOffset
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|deleteText
parameter_list|(
name|long
name|startOffset
parameter_list|,
name|long
name|endOffset
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|insertText
parameter_list|(
name|long
name|offset
parameter_list|,
name|BSTR
modifier|*
name|text
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|cutText
parameter_list|(
name|long
name|startOffset
parameter_list|,
name|long
name|endOffset
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|pasteText
parameter_list|(
name|long
name|offset
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|replaceText
parameter_list|(
name|long
name|startOffset
parameter_list|,
name|long
name|endOffset
parameter_list|,
name|BSTR
modifier|*
name|text
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|setAttributes
parameter_list|(
name|long
name|startOffset
parameter_list|,
name|long
name|endOffset
parameter_list|,
name|BSTR
modifier|*
name|attributes
parameter_list|)
function_decl|;
comment|/* IAccessibleTable2 */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_cellAt
parameter_list|(
name|long
name|row
parameter_list|,
name|long
name|column
parameter_list|,
name|IUnknown
modifier|*
modifier|*
name|cell
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_caption
parameter_list|(
name|IUnknown
modifier|*
modifier|*
name|accessible
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_columnDescription
parameter_list|(
name|long
name|column
parameter_list|,
name|BSTR
modifier|*
name|description
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nColumns
parameter_list|(
name|long
modifier|*
name|columnCount
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nRows
parameter_list|(
name|long
modifier|*
name|rowCount
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nSelectedCells
parameter_list|(
name|long
modifier|*
name|cellCount
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nSelectedColumns
parameter_list|(
name|long
modifier|*
name|columnCount
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nSelectedRows
parameter_list|(
name|long
modifier|*
name|rowCount
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_rowDescription
parameter_list|(
name|long
name|row
parameter_list|,
name|BSTR
modifier|*
name|description
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_selectedCells
parameter_list|(
name|IUnknown
modifier|*
modifier|*
modifier|*
name|cells
parameter_list|,
name|long
modifier|*
name|nSelectedCells
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_selectedColumns
parameter_list|(
name|long
modifier|*
modifier|*
name|selectedColumns
parameter_list|,
name|long
modifier|*
name|nColumns
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_selectedRows
parameter_list|(
name|long
modifier|*
modifier|*
name|selectedRows
parameter_list|,
name|long
modifier|*
name|nRows
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_summary
parameter_list|(
name|IUnknown
modifier|*
modifier|*
name|accessible
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_isColumnSelected
parameter_list|(
name|long
name|column
parameter_list|,
name|boolean
modifier|*
name|isSelected
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_isRowSelected
parameter_list|(
name|long
name|row
parameter_list|,
name|boolean
modifier|*
name|isSelected
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|selectRow
parameter_list|(
name|long
name|row
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|selectColumn
parameter_list|(
name|long
name|column
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|unselectRow
parameter_list|(
name|long
name|row
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|unselectColumn
parameter_list|(
name|long
name|column
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_modelChange
parameter_list|(
name|IA2TableModelChange
modifier|*
name|modelChange
parameter_list|)
function_decl|;
comment|/* IAccessibleTableCell */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_columnExtent
parameter_list|(
name|long
modifier|*
name|nColumnsSpanned
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_columnHeaderCells
parameter_list|(
name|IUnknown
modifier|*
modifier|*
modifier|*
name|cellAccessibles
parameter_list|,
name|long
modifier|*
name|nColumnHeaderCells
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_columnIndex
parameter_list|(
name|long
modifier|*
name|columnIndex
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_rowExtent
parameter_list|(
name|long
modifier|*
name|nRowsSpanned
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_rowHeaderCells
parameter_list|(
name|IUnknown
modifier|*
modifier|*
modifier|*
name|cellAccessibles
parameter_list|,
name|long
modifier|*
name|nRowHeaderCells
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_rowIndex
parameter_list|(
name|long
modifier|*
name|rowIndex
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_isSelected
parameter_list|(
name|boolean
modifier|*
name|isSelected
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_rowColumnExtents
parameter_list|(
name|long
modifier|*
name|row
parameter_list|,
name|long
modifier|*
name|column
parameter_list|,
name|long
modifier|*
name|rowExtents
parameter_list|,
name|long
modifier|*
name|columnExtents
parameter_list|,
name|boolean
modifier|*
name|isSelected
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_table
parameter_list|(
name|IUnknown
modifier|*
modifier|*
name|table
parameter_list|)
function_decl|;
comment|/* IAccessibleText */
name|HRESULT
name|STDMETHODCALLTYPE
name|addSelection
parameter_list|(
name|long
name|startOffset
parameter_list|,
name|long
name|endOffset
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_attributes
parameter_list|(
name|long
name|offset
parameter_list|,
name|long
modifier|*
name|startOffset
parameter_list|,
name|long
modifier|*
name|endOffset
parameter_list|,
name|BSTR
modifier|*
name|textAttributes
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_caretOffset
parameter_list|(
name|long
modifier|*
name|offset
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_characterExtents
parameter_list|(
name|long
name|offset
parameter_list|,
name|enum
name|IA2CoordinateType
name|coordType
parameter_list|,
name|long
modifier|*
name|x
parameter_list|,
name|long
modifier|*
name|y
parameter_list|,
name|long
modifier|*
name|width
parameter_list|,
name|long
modifier|*
name|height
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nSelections
parameter_list|(
name|long
modifier|*
name|nSelections
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_offsetAtPoint
parameter_list|(
name|long
name|x
parameter_list|,
name|long
name|y
parameter_list|,
name|enum
name|IA2CoordinateType
name|coordType
parameter_list|,
name|long
modifier|*
name|offset
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_selection
parameter_list|(
name|long
name|selectionIndex
parameter_list|,
name|long
modifier|*
name|startOffset
parameter_list|,
name|long
modifier|*
name|endOffset
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_text
parameter_list|(
name|long
name|startOffset
parameter_list|,
name|long
name|endOffset
parameter_list|,
name|BSTR
modifier|*
name|text
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_textBeforeOffset
parameter_list|(
name|long
name|offset
parameter_list|,
name|enum
name|IA2TextBoundaryType
name|boundaryType
parameter_list|,
name|long
modifier|*
name|startOffset
parameter_list|,
name|long
modifier|*
name|endOffset
parameter_list|,
name|BSTR
modifier|*
name|text
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_textAfterOffset
parameter_list|(
name|long
name|offset
parameter_list|,
name|enum
name|IA2TextBoundaryType
name|boundaryType
parameter_list|,
name|long
modifier|*
name|startOffset
parameter_list|,
name|long
modifier|*
name|endOffset
parameter_list|,
name|BSTR
modifier|*
name|text
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_textAtOffset
parameter_list|(
name|long
name|offset
parameter_list|,
name|enum
name|IA2TextBoundaryType
name|boundaryType
parameter_list|,
name|long
modifier|*
name|startOffset
parameter_list|,
name|long
modifier|*
name|endOffset
parameter_list|,
name|BSTR
modifier|*
name|text
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|removeSelection
parameter_list|(
name|long
name|selectionIndex
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|setCaretOffset
parameter_list|(
name|long
name|offset
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|setSelection
parameter_list|(
name|long
name|selectionIndex
parameter_list|,
name|long
name|startOffset
parameter_list|,
name|long
name|endOffset
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nCharacters
parameter_list|(
name|long
modifier|*
name|nCharacters
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|scrollSubstringTo
parameter_list|(
name|long
name|startIndex
parameter_list|,
name|long
name|endIndex
parameter_list|,
name|enum
name|IA2ScrollType
name|scrollType
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|scrollSubstringToPoint
parameter_list|(
name|long
name|startIndex
parameter_list|,
name|long
name|endIndex
parameter_list|,
name|enum
name|IA2CoordinateType
name|coordinateType
parameter_list|,
name|long
name|x
parameter_list|,
name|long
name|y
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_newText
parameter_list|(
name|IA2TextSegment
modifier|*
name|newText
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_oldText
parameter_list|(
name|IA2TextSegment
modifier|*
name|oldText
parameter_list|)
function_decl|;
comment|/* IAccessibleValue */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_currentValue
parameter_list|(
name|VARIANT
modifier|*
name|currentValue
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|setCurrentValue
parameter_list|(
name|VARIANT
name|value
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_maximumValue
parameter_list|(
name|VARIANT
modifier|*
name|maximumValue
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_minimumValue
parameter_list|(
name|VARIANT
modifier|*
name|minimumValue
parameter_list|)
function_decl|;
comment|/* IServiceProvider */
name|HRESULT
name|STDMETHODCALLTYPE
name|QueryService
parameter_list|(
name|REFGUID
name|guidService
parameter_list|,
name|REFIID
name|riid
parameter_list|,
name|void
modifier|*
modifier|*
name|ppv
parameter_list|)
function_decl|;
comment|/* private helper functions */
name|private
label|:
specifier|inline
name|QAccessibleTextInterface
operator|*
name|textInterface
argument_list|()
specifier|const
block|{
return|return
name|accessible
operator|->
name|isValid
argument_list|()
operator|?
name|accessible
operator|->
name|textInterface
argument_list|()
operator|:
name|static_cast
operator|<
name|QAccessibleTextInterface
operator|*
operator|>
operator|(
literal|0
operator|)
return|;
block|}
specifier|inline
name|QAccessibleActionInterface
operator|*
name|actionInterface
argument_list|()
specifier|const
block|{
return|return
name|accessible
operator|->
name|actionInterface
argument_list|()
return|;
block|}
specifier|inline
name|QAccessibleValueInterface
operator|*
name|valueInterface
argument_list|()
specifier|const
block|{
return|return
name|accessible
operator|->
name|valueInterface
argument_list|()
return|;
block|}
specifier|inline
name|QAccessibleTableInterface
operator|*
name|tableInterface
argument_list|()
specifier|const
block|{
return|return
name|accessible
operator|->
name|tableInterface
argument_list|()
return|;
block|}
specifier|inline
name|QAccessibleTableCellInterface
operator|*
name|tableCellInterface
argument_list|()
specifier|const
block|{
return|return
name|accessible
operator|->
name|tableCellInterface
argument_list|()
return|;
block|}
comment|/*!       \internal       \a screenPos is in screen relative position       \a x and \y (out) is in parent relative position if coordType == IA2_COORDTYPE_PARENT_RELATIVE     */
name|void
name|mapFromScreenPos
argument_list|(
expr|enum
name|IA2CoordinateType
name|coordType
argument_list|,
specifier|const
name|QPoint
operator|&
name|screenPos
argument_list|,
name|long
operator|*
name|x
argument_list|,
name|long
operator|*
name|y
argument_list|)
decl|const
block|{
if|if
condition|(
name|coordType
operator|==
name|IA2_COORDTYPE_PARENT_RELATIVE
condition|)
block|{
comment|// caller wants relative to parent
if|if
condition|(
name|QAccessibleInterface
modifier|*
name|parent
init|=
name|accessible
operator|->
name|parent
argument_list|()
condition|)
block|{
specifier|const
name|QRect
name|parentScreenRect
init|=
name|parent
operator|->
name|rect
argument_list|()
decl_stmt|;
operator|*
name|x
operator|=
name|parentScreenRect
operator|.
name|x
argument_list|()
operator|-
name|screenPos
operator|.
name|x
argument_list|()
expr_stmt|;
operator|*
name|y
operator|=
name|parentScreenRect
operator|.
name|y
argument_list|()
operator|-
name|screenPos
operator|.
name|y
argument_list|()
expr_stmt|;
return|return;
block|}
block|}
operator|*
name|x
operator|=
name|screenPos
operator|.
name|x
argument_list|()
expr_stmt|;
operator|*
name|y
operator|=
name|screenPos
operator|.
name|y
argument_list|()
expr_stmt|;
block|}
comment|/*!       \internal       \a x and \y is in parent relative position if coordType == IA2_COORDTYPE_PARENT_RELATIVE       \return a screen relative position     */
name|QPoint
name|mapToScreenPos
argument_list|(
expr|enum
name|IA2CoordinateType
name|coordType
argument_list|,
name|long
name|x
argument_list|,
name|long
name|y
argument_list|)
decl|const
block|{
if|if
condition|(
name|coordType
operator|==
name|IA2_COORDTYPE_PARENT_RELATIVE
condition|)
block|{
if|if
condition|(
name|QAccessibleInterface
modifier|*
name|parent
init|=
name|accessible
operator|->
name|parent
argument_list|()
condition|)
block|{
specifier|const
name|QRect
name|parentScreenRect
init|=
name|parent
operator|->
name|rect
argument_list|()
decl_stmt|;
return|return
name|QPoint
argument_list|(
name|parentScreenRect
operator|.
name|x
argument_list|()
operator|+
name|x
argument_list|,
name|parentScreenRect
operator|.
name|y
argument_list|()
operator|+
name|y
argument_list|)
return|;
block|}
block|}
return|return
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
name|HRESULT
name|getRelationsHelper
parameter_list|(
name|IAccessibleRelation
modifier|*
modifier|*
name|relations
parameter_list|,
name|int
name|startIndex
parameter_list|,
name|long
name|maxRelations
parameter_list|,
name|long
modifier|*
name|nRelations
init|=
literal|0
parameter_list|)
function_decl|;
name|HRESULT
name|wrapListOfCells
argument_list|(
specifier|const
name|QList
operator|<
name|QAccessibleInterface
operator|*
operator|>
operator|&
name|inputCells
argument_list|,
name|IUnknown
operator|*
operator|*
operator|*
name|outputAccessibles
argument_list|,
name|long
operator|*
name|nCellCount
argument_list|)
decl_stmt|;
name|uint
name|uniqueID
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|IIDToString
parameter_list|(
name|REFIID
name|id
parameter_list|)
function_decl|;
name|QString
name|textForRange
argument_list|(
name|int
name|startOffset
argument_list|,
name|int
name|endOffset
argument_list|)
decl|const
decl_stmt|;
name|void
name|replaceTextFallback
parameter_list|(
name|long
name|startOffset
parameter_list|,
name|long
name|endOffset
parameter_list|,
specifier|const
name|QString
modifier|&
name|txt
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************\  *                     AccessibleApplication                  *  **************************************************************/
end_comment
begin_decl_stmt
name|class
name|AccessibleApplication
range|:
name|public
name|IAccessibleApplication
block|{
name|public
operator|:
name|AccessibleApplication
argument_list|()
operator|:
name|m_ref
argument_list|(
literal|1
argument_list|)
block|{      }
name|virtual
operator|~
name|AccessibleApplication
argument_list|()
block|{}
comment|/* IUnknown */
name|HRESULT
name|STDMETHODCALLTYPE
name|QueryInterface
argument_list|(
name|REFIID
argument_list|,
name|LPVOID
operator|*
argument_list|)
block|;
name|ULONG
name|STDMETHODCALLTYPE
name|AddRef
argument_list|()
block|;
name|ULONG
name|STDMETHODCALLTYPE
name|Release
argument_list|()
block|;
comment|/* IAccessibleApplication */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_appName
argument_list|(
comment|/* [retval][out] */
name|BSTR
operator|*
name|name
argument_list|)
block|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_appVersion
argument_list|(
comment|/* [retval][out] */
name|BSTR
operator|*
name|version
argument_list|)
block|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_toolkitName
argument_list|(
comment|/* [retval][out] */
name|BSTR
operator|*
name|name
argument_list|)
block|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_toolkitVersion
argument_list|(
comment|/* [retval][out] */
name|BSTR
operator|*
name|version
argument_list|)
block|;
name|private
operator|:
name|ULONG
name|m_ref
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/**************************************************************\  *                     AccessibleRelation                      *  **************************************************************/
end_comment
begin_decl_stmt
name|class
name|AccessibleRelation
range|:
name|public
name|IAccessibleRelation
block|{
name|public
operator|:
name|AccessibleRelation
argument_list|(
argument|const QList<QAccessibleInterface *>&targets
argument_list|,
argument|QAccessible::Relation relation
argument_list|)
block|;
name|virtual
operator|~
name|AccessibleRelation
argument_list|()
block|{}
comment|/* IUnknown */
name|HRESULT
name|STDMETHODCALLTYPE
name|QueryInterface
argument_list|(
argument|REFIID id
argument_list|,
argument|LPVOID *iface
argument_list|)
block|;
name|ULONG
name|STDMETHODCALLTYPE
name|AddRef
argument_list|()
block|;
name|ULONG
name|STDMETHODCALLTYPE
name|Release
argument_list|()
block|;
comment|/* IAccessibleRelation */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_relationType
argument_list|(
name|BSTR
operator|*
name|relationType
argument_list|)
block|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_localizedRelationType
argument_list|(
name|BSTR
operator|*
name|localizedRelationType
argument_list|)
block|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nTargets
argument_list|(
name|long
operator|*
name|nTargets
argument_list|)
block|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_target
argument_list|(
argument|long targetIndex
argument_list|,
argument|IUnknown **target
argument_list|)
block|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_targets
argument_list|(
argument|long maxTargets
argument_list|,
argument|IUnknown **targets
argument_list|,
argument|long *nTargets
argument_list|)
block|;
name|private
operator|:
specifier|static
name|BSTR
name|relationToBSTR
argument_list|(
argument|QAccessible::Relation relation
argument_list|)
block|{
name|wchar_t
operator|*
name|constRelationString
operator|=
literal|0
block|;
switch|switch
condition|(
name|relation
condition|)
block|{
case|case
name|QAccessible
operator|::
name|Controlled
case|:
name|constRelationString
operator|=
name|IA2_RELATION_CONTROLLED_BY
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|constRelationString
condition|)
block|{
name|BSTR
name|bstrVal
decl_stmt|;
specifier|const
name|UINT
name|wlen
init|=
operator|(
name|UINT
operator|)
name|wcslen
argument_list|(
name|constRelationString
argument_list|)
decl_stmt|;
name|bstrVal
operator|=
operator|::
name|SysAllocStringLen
argument_list|(
name|constRelationString
argument_list|,
name|wlen
argument_list|)
expr_stmt|;
return|return
name|bstrVal
return|;
block|}
return|return
literal|0
return|;
block|}
name|QList
operator|<
name|QAccessibleInterface
operator|*
operator|>
name|m_targets
block|;
name|QAccessible
operator|::
name|Relation
name|m_relation
block|;
name|ULONG
name|m_ref
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ACCESSIBILITY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// IACCESSIBLE2_H
end_comment
end_unit
