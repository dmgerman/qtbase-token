begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"rangecontrols.h"
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
file|<qmath.h>
end_include
begin_include
include|#
directive|include
file|<private/qmath_p.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
specifier|extern
name|QString
name|Q_GUI_EXPORT
name|qt_accStripAmp
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SCROLLBAR
end_ifndef
begin_function_decl
specifier|extern
name|QStyleOptionSlider
name|Q_GUI_EXPORT
name|qt_qscrollbarStyleOption
parameter_list|(
name|QScrollBar
modifier|*
name|scrollBar
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SLIDER
end_ifndef
begin_function_decl
specifier|extern
name|QStyleOptionSlider
name|Q_GUI_EXPORT
name|qt_qsliderStyleOption
parameter_list|(
name|QSlider
modifier|*
name|slider
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
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
name|SpinBox
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
DECL|function|text
name|QString
name|QAccessibleAbstractSpinBox
operator|::
name|text
parameter_list|(
name|Text
name|t
parameter_list|,
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
argument|child
argument_list|)
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
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|doAction
name|bool
name|QAccessibleAbstractSpinBox
operator|::
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
block|{
name|Q_UNUSED
argument_list|(
argument|child
argument_list|)
if|if
condition|(
operator|!
name|widget
argument_list|()
operator|->
name|isEnabled
argument_list|()
condition|)
return|return
literal|false
return|;
return|return
name|QAccessibleWidget
operator|::
name|doAction
argument_list|(
name|action
argument_list|,
literal|0
argument_list|,
name|params
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
block|{
name|QVariant
name|result
init|=
name|abstractSpinBox
argument_list|()
operator|->
name|property
argument_list|(
literal|"value"
argument_list|)
decl_stmt|;
name|QVariant
operator|::
name|Type
name|type
init|=
name|result
operator|.
name|type
argument_list|()
decl_stmt|;
comment|// IA2 only allows numeric types
if|if
condition|(
name|type
operator|==
name|QVariant
operator|::
name|Int
operator|||
name|type
operator|==
name|QVariant
operator|::
name|UInt
operator|||
name|type
operator|==
name|QVariant
operator|::
name|LongLong
operator|||
name|type
operator|==
name|QVariant
operator|::
name|ULongLong
operator|||
name|type
operator|==
name|QVariant
operator|::
name|Double
condition|)
return|return
name|result
return|;
return|return
name|QVariant
argument_list|()
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
DECL|function|invokeMethod
name|QVariant
name|QAccessibleAbstractSpinBox
operator|::
name|invokeMethod
parameter_list|(
name|Method
name|method
parameter_list|,
name|int
name|child
parameter_list|,
specifier|const
name|QVariantList
modifier|&
name|params
parameter_list|)
block|{
switch|switch
condition|(
name|method
condition|)
block|{
case|case
name|ListSupportedMethods
case|:
block|{
name|QSet
argument_list|<
name|QAccessible
operator|::
name|Method
argument_list|>
name|set
decl_stmt|;
name|set
operator|<<
name|ListSupportedMethods
expr_stmt|;
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|set
operator||
name|qvariant_cast
argument_list|<
name|QSet
argument_list|<
name|QAccessible
operator|::
name|Method
argument_list|>
argument_list|>
argument_list|(
name|QAccessibleWidget
operator|::
name|invokeMethod
argument_list|(
name|method
argument_list|,
name|child
argument_list|,
name|params
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
default|default:
return|return
name|QAccessibleWidget
operator|::
name|invokeMethod
argument_list|(
name|method
argument_list|,
name|child
argument_list|,
name|params
argument_list|)
return|;
block|}
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
begin_function
DECL|function|doAction
name|bool
name|QAccessibleSpinBox
operator|::
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
block|{
name|Q_UNUSED
argument_list|(
argument|child
argument_list|)
if|if
condition|(
operator|!
name|widget
argument_list|()
operator|->
name|isEnabled
argument_list|()
condition|)
return|return
literal|false
return|;
return|return
name|QAccessibleAbstractSpinBox
operator|::
name|doAction
argument_list|(
name|action
argument_list|,
literal|0
argument_list|,
name|params
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
DECL|function|invokeMethod
name|QVariant
name|QAccessibleDoubleSpinBox
operator|::
name|invokeMethod
parameter_list|(
name|QAccessible
operator|::
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
end_function
begin_function
DECL|function|text
name|QString
name|QAccessibleDoubleSpinBox
operator|::
name|text
parameter_list|(
name|Text
name|textType
parameter_list|,
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
argument|child
argument_list|)
if|if
condition|(
name|textType
operator|==
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
argument_list|,
literal|0
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
name|Text
name|t
parameter_list|,
name|int
name|child
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|t
operator|==
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
argument_list|,
name|child
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
name|Text
name|t
parameter_list|,
name|int
name|child
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|t
operator|==
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
argument_list|,
name|child
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn int QAccessibleSlider::defaultAction(int child) const      Returns the default action for the given \a child. The base class     implementation returns 0. */
end_comment
begin_function
DECL|function|defaultAction
name|int
name|QAccessibleSlider
operator|::
name|defaultAction
parameter_list|(
name|int
comment|/*child*/
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*! \internal */
end_comment
begin_function
DECL|function|actionText
name|QString
name|QAccessibleSlider
operator|::
name|actionText
parameter_list|(
name|int
comment|/*action*/
parameter_list|,
name|Text
comment|/*t*/
parameter_list|,
name|int
comment|/*child*/
parameter_list|)
specifier|const
block|{
return|return
name|QLatin1String
argument_list|(
literal|""
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
DECL|function|invokeMethod
name|QVariant
name|QAccessibleAbstractSlider
operator|::
name|invokeMethod
parameter_list|(
name|Method
name|method
parameter_list|,
name|int
name|child
parameter_list|,
specifier|const
name|QVariantList
modifier|&
name|params
parameter_list|)
block|{
switch|switch
condition|(
name|method
condition|)
block|{
case|case
name|ListSupportedMethods
case|:
block|{
name|QSet
argument_list|<
name|QAccessible
operator|::
name|Method
argument_list|>
name|set
decl_stmt|;
name|set
operator|<<
name|ListSupportedMethods
expr_stmt|;
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|set
operator||
name|qvariant_cast
argument_list|<
name|QSet
argument_list|<
name|QAccessible
operator|::
name|Method
argument_list|>
argument_list|>
argument_list|(
name|QAccessibleWidget
operator|::
name|invokeMethod
argument_list|(
name|method
argument_list|,
name|child
argument_list|,
name|params
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
default|default:
return|return
name|QAccessibleWidget
operator|::
name|invokeMethod
argument_list|(
name|method
argument_list|,
name|child
argument_list|,
name|params
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|currentValue
name|QVariant
name|QAccessibleAbstractSlider
operator|::
name|currentValue
parameter_list|()
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
name|Text
name|textType
parameter_list|,
name|int
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|textType
operator|==
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
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|invokeMethod
name|QVariant
name|QAccessibleDial
operator|::
name|invokeMethod
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
