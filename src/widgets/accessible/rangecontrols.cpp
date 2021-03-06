begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"rangecontrols_p.h"
end_include
begin_include
include|#
directive|include
file|<qslider.h>
end_include
begin_include
include|#
directive|include
file|<qdial.h>
end_include
begin_include
include|#
directive|include
file|<qspinbox.h>
end_include
begin_include
include|#
directive|include
file|<qscrollbar.h>
end_include
begin_include
include|#
directive|include
file|<qstyle.h>
end_include
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QDoubleSpinBox>
end_include
begin_include
include|#
directive|include
file|<QDial>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qlineedit.h>
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_include
include|#
directive|include
file|<private/qmath_p.h>
end_include
begin_include
include|#
directive|include
file|"simplewidgets_p.h"
end_include
begin_comment
comment|// let spinbox use line edit's interface
end_comment
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SPINBOX
end_ifndef
begin_constructor
DECL|function|QAccessibleAbstractSpinBox
name|QAccessibleAbstractSpinBox
operator|::
name|QAccessibleAbstractSpinBox
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QAccessibleWidget
argument_list|(
name|w
argument_list|,
name|QAccessible
operator|::
name|SpinBox
argument_list|)
member_init_list|,
name|lineEdit
argument_list|(
name|Q_NULLPTR
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|abstractSpinBox
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QAccessibleAbstractSpinBox
name|QAccessibleAbstractSpinBox
operator|::
name|~
name|QAccessibleAbstractSpinBox
parameter_list|()
block|{
operator|delete
name|lineEdit
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns the underlying QAbstractSpinBox. */
end_comment
begin_function
DECL|function|abstractSpinBox
name|QAbstractSpinBox
modifier|*
name|QAccessibleAbstractSpinBox
operator|::
name|abstractSpinBox
parameter_list|()
specifier|const
block|{
return|return
name|qobject_cast
argument_list|<
name|QAbstractSpinBox
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|lineEditIface
name|QAccessibleInterface
modifier|*
name|QAccessibleAbstractSpinBox
operator|::
name|lineEditIface
parameter_list|()
specifier|const
block|{
comment|// QAccessibleLineEdit is only used to forward the text functions
if|if
condition|(
operator|!
name|lineEdit
condition|)
name|lineEdit
operator|=
operator|new
name|QAccessibleLineEdit
argument_list|(
name|abstractSpinBox
argument_list|()
operator|->
name|lineEdit
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|lineEdit
return|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|QAccessibleAbstractSpinBox
operator|::
name|text
parameter_list|(
name|QAccessible
operator|::
name|Text
name|t
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|t
operator|==
name|QAccessible
operator|::
name|Value
condition|)
return|return
name|abstractSpinBox
argument_list|()
operator|->
name|text
argument_list|()
return|;
return|return
name|QAccessibleWidget
operator|::
name|text
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|interface_cast
name|void
modifier|*
name|QAccessibleAbstractSpinBox
operator|::
name|interface_cast
parameter_list|(
name|QAccessible
operator|::
name|InterfaceType
name|t
parameter_list|)
block|{
if|if
condition|(
name|t
operator|==
name|QAccessible
operator|::
name|ValueInterface
condition|)
return|return
cast|static_cast
argument_list|<
name|QAccessibleValueInterface
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
return|;
if|if
condition|(
name|t
operator|==
name|QAccessible
operator|::
name|TextInterface
condition|)
return|return
cast|static_cast
argument_list|<
name|QAccessibleTextInterface
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
return|;
if|if
condition|(
name|t
operator|==
name|QAccessible
operator|::
name|EditableTextInterface
condition|)
return|return
cast|static_cast
argument_list|<
name|QAccessibleEditableTextInterface
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
return|;
return|return
name|QAccessibleWidget
operator|::
name|interface_cast
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|currentValue
name|QVariant
name|QAccessibleAbstractSpinBox
operator|::
name|currentValue
parameter_list|()
specifier|const
block|{
return|return
name|abstractSpinBox
argument_list|()
operator|->
name|property
argument_list|(
literal|"value"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setCurrentValue
name|void
name|QAccessibleAbstractSpinBox
operator|::
name|setCurrentValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
name|abstractSpinBox
argument_list|()
operator|->
name|setProperty
argument_list|(
literal|"value"
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|maximumValue
name|QVariant
name|QAccessibleAbstractSpinBox
operator|::
name|maximumValue
parameter_list|()
specifier|const
block|{
return|return
name|abstractSpinBox
argument_list|()
operator|->
name|property
argument_list|(
literal|"maximum"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|minimumValue
name|QVariant
name|QAccessibleAbstractSpinBox
operator|::
name|minimumValue
parameter_list|()
specifier|const
block|{
return|return
name|abstractSpinBox
argument_list|()
operator|->
name|property
argument_list|(
literal|"minimum"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|minimumStepSize
name|QVariant
name|QAccessibleAbstractSpinBox
operator|::
name|minimumStepSize
parameter_list|()
specifier|const
block|{
return|return
name|abstractSpinBox
argument_list|()
operator|->
name|property
argument_list|(
literal|"stepSize"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|addSelection
name|void
name|QAccessibleAbstractSpinBox
operator|::
name|addSelection
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
block|{
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|addSelection
argument_list|(
name|startOffset
argument_list|,
name|endOffset
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|attributes
name|QString
name|QAccessibleAbstractSpinBox
operator|::
name|attributes
parameter_list|(
name|int
name|offset
parameter_list|,
name|int
modifier|*
name|startOffset
parameter_list|,
name|int
modifier|*
name|endOffset
parameter_list|)
specifier|const
block|{
return|return
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|attributes
argument_list|(
name|offset
argument_list|,
name|startOffset
argument_list|,
name|endOffset
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|cursorPosition
name|int
name|QAccessibleAbstractSpinBox
operator|::
name|cursorPosition
parameter_list|()
specifier|const
block|{
return|return
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|cursorPosition
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|characterRect
name|QRect
name|QAccessibleAbstractSpinBox
operator|::
name|characterRect
parameter_list|(
name|int
name|offset
parameter_list|)
specifier|const
block|{
return|return
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|characterRect
argument_list|(
name|offset
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|selectionCount
name|int
name|QAccessibleAbstractSpinBox
operator|::
name|selectionCount
parameter_list|()
specifier|const
block|{
return|return
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|selectionCount
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|offsetAtPoint
name|int
name|QAccessibleAbstractSpinBox
operator|::
name|offsetAtPoint
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|point
parameter_list|)
specifier|const
block|{
return|return
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|offsetAtPoint
argument_list|(
name|point
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|selection
name|void
name|QAccessibleAbstractSpinBox
operator|::
name|selection
parameter_list|(
name|int
name|selectionIndex
parameter_list|,
name|int
modifier|*
name|startOffset
parameter_list|,
name|int
modifier|*
name|endOffset
parameter_list|)
specifier|const
block|{
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|selection
argument_list|(
name|selectionIndex
argument_list|,
name|startOffset
argument_list|,
name|endOffset
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|QAccessibleAbstractSpinBox
operator|::
name|text
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
specifier|const
block|{
return|return
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|text
argument_list|(
name|startOffset
argument_list|,
name|endOffset
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|textBeforeOffset
name|QString
name|QAccessibleAbstractSpinBox
operator|::
name|textBeforeOffset
parameter_list|(
name|int
name|offset
parameter_list|,
name|QAccessible
operator|::
name|TextBoundaryType
name|boundaryType
parameter_list|,
name|int
modifier|*
name|startOffset
parameter_list|,
name|int
modifier|*
name|endOffset
parameter_list|)
specifier|const
block|{
return|return
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|textBeforeOffset
argument_list|(
name|offset
argument_list|,
name|boundaryType
argument_list|,
name|startOffset
argument_list|,
name|endOffset
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|textAfterOffset
name|QString
name|QAccessibleAbstractSpinBox
operator|::
name|textAfterOffset
parameter_list|(
name|int
name|offset
parameter_list|,
name|QAccessible
operator|::
name|TextBoundaryType
name|boundaryType
parameter_list|,
name|int
modifier|*
name|startOffset
parameter_list|,
name|int
modifier|*
name|endOffset
parameter_list|)
specifier|const
block|{
return|return
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|textAfterOffset
argument_list|(
name|offset
argument_list|,
name|boundaryType
argument_list|,
name|startOffset
argument_list|,
name|endOffset
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|textAtOffset
name|QString
name|QAccessibleAbstractSpinBox
operator|::
name|textAtOffset
parameter_list|(
name|int
name|offset
parameter_list|,
name|QAccessible
operator|::
name|TextBoundaryType
name|boundaryType
parameter_list|,
name|int
modifier|*
name|startOffset
parameter_list|,
name|int
modifier|*
name|endOffset
parameter_list|)
specifier|const
block|{
return|return
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|textAtOffset
argument_list|(
name|offset
argument_list|,
name|boundaryType
argument_list|,
name|startOffset
argument_list|,
name|endOffset
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|removeSelection
name|void
name|QAccessibleAbstractSpinBox
operator|::
name|removeSelection
parameter_list|(
name|int
name|selectionIndex
parameter_list|)
block|{
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|removeSelection
argument_list|(
name|selectionIndex
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCursorPosition
name|void
name|QAccessibleAbstractSpinBox
operator|::
name|setCursorPosition
parameter_list|(
name|int
name|position
parameter_list|)
block|{
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|setCursorPosition
argument_list|(
name|position
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setSelection
name|void
name|QAccessibleAbstractSpinBox
operator|::
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
block|{
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|setSelection
argument_list|(
name|selectionIndex
argument_list|,
name|startOffset
argument_list|,
name|endOffset
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|characterCount
name|int
name|QAccessibleAbstractSpinBox
operator|::
name|characterCount
parameter_list|()
specifier|const
block|{
return|return
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|characterCount
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|scrollToSubstring
name|void
name|QAccessibleAbstractSpinBox
operator|::
name|scrollToSubstring
parameter_list|(
name|int
name|startIndex
parameter_list|,
name|int
name|endIndex
parameter_list|)
block|{
name|lineEditIface
argument_list|()
operator|->
name|textInterface
argument_list|()
operator|->
name|scrollToSubstring
argument_list|(
name|startIndex
argument_list|,
name|endIndex
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|deleteText
name|void
name|QAccessibleAbstractSpinBox
operator|::
name|deleteText
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
block|{
name|lineEditIface
argument_list|()
operator|->
name|editableTextInterface
argument_list|()
operator|->
name|deleteText
argument_list|(
name|startOffset
argument_list|,
name|endOffset
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertText
name|void
name|QAccessibleAbstractSpinBox
operator|::
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
block|{
name|lineEditIface
argument_list|()
operator|->
name|editableTextInterface
argument_list|()
operator|->
name|insertText
argument_list|(
name|offset
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|replaceText
name|void
name|QAccessibleAbstractSpinBox
operator|::
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
block|{
name|lineEditIface
argument_list|()
operator|->
name|editableTextInterface
argument_list|()
operator|->
name|replaceText
argument_list|(
name|startOffset
argument_list|,
name|endOffset
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \class QAccessibleSpinBox   \brief The QAccessibleSpinBox class implements the QAccessibleInterface for spinbox widgets.   \internal    \ingroup accessibility */
end_comment
begin_comment
comment|/*!   Constructs a QAccessibleSpinWidget object for \a w. */
end_comment
begin_constructor
DECL|function|QAccessibleSpinBox
name|QAccessibleSpinBox
operator|::
name|QAccessibleSpinBox
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QAccessibleAbstractSpinBox
argument_list|(
name|w
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|spinBox
argument_list|()
argument_list|)
expr_stmt|;
name|addControllingSignal
argument_list|(
name|QLatin1String
argument_list|(
literal|"valueChanged(int)"
argument_list|)
argument_list|)
expr_stmt|;
name|addControllingSignal
argument_list|(
name|QLatin1String
argument_list|(
literal|"valueChanged(QString)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Returns the underlying QSpinBox. */
end_comment
begin_function
DECL|function|spinBox
name|QSpinBox
modifier|*
name|QAccessibleSpinBox
operator|::
name|spinBox
parameter_list|()
specifier|const
block|{
return|return
name|qobject_cast
argument_list|<
name|QSpinBox
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// ================================== QAccessibleDoubleSpinBox ==================================
end_comment
begin_constructor
DECL|function|QAccessibleDoubleSpinBox
name|QAccessibleDoubleSpinBox
operator|::
name|QAccessibleDoubleSpinBox
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
member_init_list|:
name|QAccessibleAbstractSpinBox
argument_list|(
name|widget
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|qobject_cast
argument_list|<
name|QDoubleSpinBox
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
argument_list|)
expr_stmt|;
name|addControllingSignal
argument_list|(
name|QLatin1String
argument_list|(
literal|"valueChanged(double)"
argument_list|)
argument_list|)
expr_stmt|;
name|addControllingSignal
argument_list|(
name|QLatin1String
argument_list|(
literal|"valueChanged(QString)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Returns the underlying QDoubleSpinBox. */
end_comment
begin_function
DECL|function|doubleSpinBox
name|QDoubleSpinBox
modifier|*
name|QAccessibleDoubleSpinBox
operator|::
name|doubleSpinBox
parameter_list|()
specifier|const
block|{
return|return
cast|static_cast
argument_list|<
name|QDoubleSpinBox
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|QAccessibleDoubleSpinBox
operator|::
name|text
parameter_list|(
name|QAccessible
operator|::
name|Text
name|textType
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|textType
operator|==
name|QAccessible
operator|::
name|Value
condition|)
return|return
name|doubleSpinBox
argument_list|()
operator|->
name|textFromValue
argument_list|(
name|doubleSpinBox
argument_list|()
operator|->
name|value
argument_list|()
argument_list|)
return|;
return|return
name|QAccessibleWidget
operator|::
name|text
argument_list|(
name|textType
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SPINBOX
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SCROLLBAR
end_ifndef
begin_comment
comment|/*!   \class QAccessibleScrollBar   \brief The QAccessibleScrollBar class implements the QAccessibleInterface for scroll bars.   \internal    \ingroup accessibility */
end_comment
begin_comment
comment|/*!   Constructs a QAccessibleScrollBar object for \a w.   \a name is propagated to the QAccessibleWidget constructor. */
end_comment
begin_constructor
DECL|function|QAccessibleScrollBar
name|QAccessibleScrollBar
operator|::
name|QAccessibleScrollBar
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QAccessibleAbstractSlider
argument_list|(
name|w
argument_list|,
name|QAccessible
operator|::
name|ScrollBar
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|scrollBar
argument_list|()
argument_list|)
expr_stmt|;
name|addControllingSignal
argument_list|(
name|QLatin1String
argument_list|(
literal|"valueChanged(int)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*! Returns the scroll bar. */
end_comment
begin_function
DECL|function|scrollBar
name|QScrollBar
modifier|*
name|QAccessibleScrollBar
operator|::
name|scrollBar
parameter_list|()
specifier|const
block|{
return|return
name|qobject_cast
argument_list|<
name|QScrollBar
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|QAccessibleScrollBar
operator|::
name|text
parameter_list|(
name|QAccessible
operator|::
name|Text
name|t
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|t
operator|==
name|QAccessible
operator|::
name|Value
condition|)
return|return
name|QString
operator|::
name|number
argument_list|(
name|scrollBar
argument_list|()
operator|->
name|value
argument_list|()
argument_list|)
return|;
return|return
name|QAccessibleAbstractSlider
operator|::
name|text
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SCROLLBAR
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SLIDER
end_ifndef
begin_comment
comment|/*!   \class QAccessibleSlider   \brief The QAccessibleSlider class implements the QAccessibleInterface for sliders.   \internal    \ingroup accessibility */
end_comment
begin_comment
comment|/*!   Constructs a QAccessibleScrollBar object for \a w.   \a name is propagated to the QAccessibleWidget constructor. */
end_comment
begin_constructor
DECL|function|QAccessibleSlider
name|QAccessibleSlider
operator|::
name|QAccessibleSlider
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QAccessibleAbstractSlider
argument_list|(
name|w
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|slider
argument_list|()
argument_list|)
expr_stmt|;
name|addControllingSignal
argument_list|(
name|QLatin1String
argument_list|(
literal|"valueChanged(int)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*! Returns the slider. */
end_comment
begin_function
DECL|function|slider
name|QSlider
modifier|*
name|QAccessibleSlider
operator|::
name|slider
parameter_list|()
specifier|const
block|{
return|return
name|qobject_cast
argument_list|<
name|QSlider
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|QAccessibleSlider
operator|::
name|text
parameter_list|(
name|QAccessible
operator|::
name|Text
name|t
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|t
operator|==
name|QAccessible
operator|::
name|Value
condition|)
return|return
name|QString
operator|::
name|number
argument_list|(
name|slider
argument_list|()
operator|->
name|value
argument_list|()
argument_list|)
return|;
return|return
name|QAccessibleAbstractSlider
operator|::
name|text
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QAccessibleAbstractSlider
name|QAccessibleAbstractSlider
operator|::
name|QAccessibleAbstractSlider
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|QAccessible
operator|::
name|Role
name|r
parameter_list|)
member_init_list|:
name|QAccessibleWidget
argument_list|(
name|w
argument_list|,
name|r
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|qobject_cast
argument_list|<
name|QAbstractSlider
operator|*
argument_list|>
argument_list|(
name|w
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|interface_cast
name|void
modifier|*
name|QAccessibleAbstractSlider
operator|::
name|interface_cast
parameter_list|(
name|QAccessible
operator|::
name|InterfaceType
name|t
parameter_list|)
block|{
if|if
condition|(
name|t
operator|==
name|QAccessible
operator|::
name|ValueInterface
condition|)
return|return
cast|static_cast
argument_list|<
name|QAccessibleValueInterface
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
return|;
return|return
name|QAccessibleWidget
operator|::
name|interface_cast
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|currentValue
name|QVariant
name|QAccessibleAbstractSlider
operator|::
name|currentValue
parameter_list|()
specifier|const
block|{
return|return
name|abstractSlider
argument_list|()
operator|->
name|value
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setCurrentValue
name|void
name|QAccessibleAbstractSlider
operator|::
name|setCurrentValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
name|abstractSlider
argument_list|()
operator|->
name|setValue
argument_list|(
name|value
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|maximumValue
name|QVariant
name|QAccessibleAbstractSlider
operator|::
name|maximumValue
parameter_list|()
specifier|const
block|{
return|return
name|abstractSlider
argument_list|()
operator|->
name|maximum
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|minimumValue
name|QVariant
name|QAccessibleAbstractSlider
operator|::
name|minimumValue
parameter_list|()
specifier|const
block|{
return|return
name|abstractSlider
argument_list|()
operator|->
name|minimum
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|minimumStepSize
name|QVariant
name|QAccessibleAbstractSlider
operator|::
name|minimumStepSize
parameter_list|()
specifier|const
block|{
return|return
name|abstractSlider
argument_list|()
operator|->
name|singleStep
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|abstractSlider
name|QAbstractSlider
modifier|*
name|QAccessibleAbstractSlider
operator|::
name|abstractSlider
parameter_list|()
specifier|const
block|{
return|return
cast|static_cast
argument_list|<
name|QAbstractSlider
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SLIDER
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DIAL
end_ifndef
begin_comment
comment|// ======================================= QAccessibleDial ======================================
end_comment
begin_constructor
DECL|function|QAccessibleDial
name|QAccessibleDial
operator|::
name|QAccessibleDial
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
member_init_list|:
name|QAccessibleAbstractSlider
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|Dial
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|qobject_cast
argument_list|<
name|QDial
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
argument_list|)
expr_stmt|;
name|addControllingSignal
argument_list|(
name|QLatin1String
argument_list|(
literal|"valueChanged(int)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|text
name|QString
name|QAccessibleDial
operator|::
name|text
parameter_list|(
name|QAccessible
operator|::
name|Text
name|textType
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|textType
operator|==
name|QAccessible
operator|::
name|Value
condition|)
return|return
name|QString
operator|::
name|number
argument_list|(
name|dial
argument_list|()
operator|->
name|value
argument_list|()
argument_list|)
return|;
return|return
name|QAccessibleAbstractSlider
operator|::
name|text
argument_list|(
name|textType
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|dial
name|QDial
modifier|*
name|QAccessibleDial
operator|::
name|dial
parameter_list|()
specifier|const
block|{
return|return
cast|static_cast
argument_list|<
name|QDial
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DIAL
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
end_unit
