begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SIMPLEWIDGETS_H
end_ifndef
begin_define
DECL|macro|SIMPLEWIDGETS_H
define|#
directive|define
name|SIMPLEWIDGETS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qaccessible2.h>
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
DECL|variable|QAbstractButton
name|class
name|QAbstractButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QToolButton
name|class
name|QToolButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QProgressBar
name|class
name|QProgressBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleButton
range|:
name|public
name|QAccessibleWidget
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QAccessibleButton
argument_list|)
name|public
operator|:
name|QAccessibleButton
argument_list|(
argument|QWidget *w
argument_list|,
argument|QAccessible::Role r
argument_list|)
block|;
name|QString
name|text
argument_list|(
argument|QAccessible::Text t
argument_list|)
specifier|const
block|;
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
block|;
name|QStringList
name|actionNames
argument_list|()
specifier|const
block|;
name|void
name|doAction
argument_list|(
specifier|const
name|QString
operator|&
name|actionName
argument_list|)
block|;
name|QStringList
name|keyBindingsForAction
argument_list|(
argument|const QString&actionName
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QAbstractButton
operator|*
name|button
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TOOLBUTTON
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleToolButton
range|:
name|public
name|QAccessibleButton
block|{
name|public
operator|:
name|QAccessibleToolButton
argument_list|(
argument|QWidget *w
argument_list|,
argument|QAccessible::Role role
argument_list|)
block|;
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
block|;
name|int
name|childCount
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
name|QString
name|text
argument_list|(
argument|QAccessible::Text t
argument_list|)
specifier|const
block|;
comment|// QAccessibleActionInterface
name|QStringList
name|actionNames
argument_list|()
specifier|const
block|;
name|void
name|doAction
argument_list|(
specifier|const
name|QString
operator|&
name|actionName
argument_list|)
block|;
name|protected
operator|:
name|QToolButton
operator|*
name|toolButton
argument_list|()
specifier|const
block|;
name|bool
name|isSplitButton
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
comment|// QT_NO_TOOLBUTTON
end_comment
begin_decl_stmt
DECL|variable|QAccessibleWidget
name|class
name|QAccessibleDisplay
range|:
name|public
name|QAccessibleWidget
decl_stmt|,
name|public
name|QAccessibleImageInterface
block|{
name|public
label|:
name|explicit
name|QAccessibleDisplay
argument_list|(
name|QWidget
operator|*
name|w
argument_list|,
name|QAccessible
operator|::
name|Role
name|role
operator|=
name|QAccessible
operator|::
name|StaticText
argument_list|)
decl_stmt|;
name|QString
name|text
argument_list|(
name|QAccessible
operator|::
name|Text
name|t
argument_list|)
decl|const
decl_stmt|;
name|QAccessible
operator|::
name|Role
name|role
argument_list|()
specifier|const
expr_stmt|;
name|QVector
operator|<
name|QPair
operator|<
name|QAccessibleInterface
operator|*
operator|,
name|QAccessible
operator|::
name|Relation
operator|>
expr|>
name|relations
argument_list|(
argument|QAccessible::Relation match = QAccessible::AllRelations
argument_list|)
specifier|const
expr_stmt|;
name|void
modifier|*
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|InterfaceType
name|t
argument_list|)
decl_stmt|;
comment|// QAccessibleImageInterface
name|QString
name|imageDescription
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|imageSize
argument_list|()
specifier|const
expr_stmt|;
name|QRect
name|imagePosition
argument_list|(
name|QAccessible2
operator|::
name|CoordinateType
name|coordType
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LINEEDIT
end_ifndef
begin_decl_stmt
DECL|variable|QAccessibleWidget
DECL|variable|QAccessibleTextInterface
name|class
name|QAccessibleLineEdit
range|:
name|public
name|QAccessibleWidget
decl_stmt|,
name|public
name|QAccessibleTextInterface
decl_stmt|,
name|public
name|QAccessibleSimpleEditableTextInterface
block|{
name|public
label|:
name|explicit
name|QAccessibleLineEdit
parameter_list|(
name|QWidget
modifier|*
name|o
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
name|QString
name|text
argument_list|(
name|QAccessible
operator|::
name|Text
name|t
argument_list|)
decl|const
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
decl_stmt|;
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
expr_stmt|;
name|void
modifier|*
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|InterfaceType
name|t
argument_list|)
decl_stmt|;
comment|// QAccessibleTextInterface
name|void
name|addSelection
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
function_decl|;
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
decl_stmt|;
name|int
name|cursorPosition
argument_list|()
specifier|const
expr_stmt|;
name|QRect
name|characterRect
argument_list|(
name|int
name|offset
argument_list|,
name|QAccessible2
operator|::
name|CoordinateType
name|coordType
argument_list|)
decl|const
decl_stmt|;
name|int
name|selectionCount
argument_list|()
specifier|const
expr_stmt|;
name|int
name|offsetAtPoint
argument_list|(
specifier|const
name|QPoint
operator|&
name|point
argument_list|,
name|QAccessible2
operator|::
name|CoordinateType
name|coordType
argument_list|)
decl|const
decl_stmt|;
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
decl_stmt|;
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
decl_stmt|;
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
decl_stmt|;
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
decl_stmt|;
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
decl_stmt|;
name|void
name|removeSelection
parameter_list|(
name|int
name|selectionIndex
parameter_list|)
function_decl|;
name|void
name|setCursorPosition
parameter_list|(
name|int
name|position
parameter_list|)
function_decl|;
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
function_decl|;
name|int
name|characterCount
argument_list|()
specifier|const
expr_stmt|;
name|void
name|scrollToSubstring
parameter_list|(
name|int
name|startIndex
parameter_list|,
name|int
name|endIndex
parameter_list|)
function_decl|;
name|protected
label|:
name|QLineEdit
operator|*
name|lineEdit
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
comment|// QT_NO_LINEEDIT
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROGRESSBAR
end_ifndef
begin_decl_stmt
DECL|variable|QAccessibleDisplay
name|class
name|QAccessibleProgressBar
range|:
name|public
name|QAccessibleDisplay
decl_stmt|,
name|public
name|QAccessibleValueInterface
block|{
name|public
label|:
name|explicit
name|QAccessibleProgressBar
parameter_list|(
name|QWidget
modifier|*
name|o
parameter_list|)
function_decl|;
name|void
modifier|*
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|InterfaceType
name|t
argument_list|)
decl_stmt|;
comment|// QAccessibleValueInterface
name|QVariant
name|currentValue
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
name|maximumValue
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
name|minimumValue
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|void
name|setCurrentValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
parameter_list|)
block|{}
name|protected
label|:
name|QProgressBar
operator|*
name|progressBar
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
comment|// SIMPLEWIDGETS_H
end_comment
end_unit
