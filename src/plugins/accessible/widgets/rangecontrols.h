begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|RANGECONTROLS_H
end_ifndef
begin_define
DECL|macro|RANGECONTROLS_H
define|#
directive|define
name|RANGECONTROLS_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qaccessiblewidget.h>
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
DECL|variable|QAbstractSpinBox
name|class
name|QAbstractSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractSlider
name|class
name|QAbstractSlider
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollBar
name|class
name|QScrollBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSlider
name|class
name|QSlider
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSpinBox
name|class
name|QSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDoubleSpinBox
name|class
name|QDoubleSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDial
name|class
name|QDial
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SPINBOX
end_ifndef
begin_decl_stmt
DECL|variable|QAccessibleWidgetEx
name|class
name|QAccessibleAbstractSpinBox
range|:
name|public
name|QAccessibleWidgetEx
decl_stmt|,
name|public
name|QAccessibleValueInterface
block|{
name|Q_ACCESSIBLE_OBJECT
name|public
range|:
name|explicit
name|QAccessibleAbstractSpinBox
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
decl_stmt|;
enum|enum
name|SpinBoxElements
block|{
name|SpinBoxSelf
init|=
literal|0
block|,
name|Editor
block|,
name|ValueUp
block|,
name|ValueDown
block|}
enum|;
name|int
name|childCount
argument_list|()
specifier|const
expr_stmt|;
name|QRect
name|rect
argument_list|(
name|int
name|child
argument_list|)
decl|const
decl_stmt|;
name|int
name|navigate
argument_list|(
name|RelationFlag
name|rel
argument_list|,
name|int
name|entry
argument_list|,
name|QAccessibleInterface
operator|*
operator|*
name|target
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
name|Role
name|role
argument_list|(
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
name|QVariant
name|invokeMethodEx
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
function_decl|;
comment|// QAccessibleValueInterface
name|QVariant
name|currentValue
parameter_list|()
function_decl|;
name|void
name|setCurrentValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
name|QVariant
name|maximumValue
parameter_list|()
function_decl|;
name|QVariant
name|minimumValue
parameter_list|()
function_decl|;
name|protected
label|:
name|QAbstractSpinBox
operator|*
name|abstractSpinBox
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QAccessibleSpinBox
range|:
name|public
name|QAccessibleAbstractSpinBox
block|{
name|public
operator|:
name|explicit
name|QAccessibleSpinBox
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|State
name|state
argument_list|(
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
name|protected
operator|:
name|QSpinBox
operator|*
name|spinBox
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleDoubleSpinBox
range|:
name|public
name|QAccessibleWidgetEx
block|{
name|public
operator|:
name|explicit
name|QAccessibleDoubleSpinBox
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;      enum
name|DoubleSpinBoxElements
block|{
name|SpinBoxSelf
operator|=
literal|0
block|,
name|Editor
block|,
name|ValueUp
block|,
name|ValueDown
block|}
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
name|QVariant
name|invokeMethodEx
argument_list|(
argument|QAccessible::Method method
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params
argument_list|)
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
name|QDoubleSpinBox
operator|*
name|doubleSpinBox
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
comment|// QT_NO_SPINBOX
end_comment
begin_decl_stmt
DECL|variable|QAccessibleWidgetEx
name|class
name|QAccessibleAbstractSlider
range|:
name|public
name|QAccessibleWidgetEx
decl_stmt|,
name|public
name|QAccessibleValueInterface
block|{
name|Q_ACCESSIBLE_OBJECT
name|public
range|:
name|explicit
name|QAccessibleAbstractSlider
argument_list|(
argument|QWidget *w
argument_list|,
argument|Role r = Slider
argument_list|)
decl_stmt|;
name|QVariant
name|invokeMethodEx
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
function_decl|;
comment|// QAccessibleValueInterface
name|QVariant
name|currentValue
parameter_list|()
function_decl|;
name|void
name|setCurrentValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
name|QVariant
name|maximumValue
parameter_list|()
function_decl|;
name|QVariant
name|minimumValue
parameter_list|()
function_decl|;
name|protected
label|:
name|QAbstractSlider
operator|*
name|abstractSlider
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SCROLLBAR
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleScrollBar
range|:
name|public
name|QAccessibleAbstractSlider
block|{
name|public
operator|:
name|explicit
name|QAccessibleScrollBar
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;      enum
name|ScrollBarElements
block|{
name|ScrollBarSelf
operator|=
literal|0
block|,
name|LineUp
block|,
name|PageUp
block|,
name|Position
block|,
name|PageDown
block|,
name|LineDown
block|}
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
name|QScrollBar
operator|*
name|scrollBar
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
comment|// QT_NO_SCROLLBAR
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SLIDER
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleSlider
range|:
name|public
name|QAccessibleAbstractSlider
block|{
name|public
operator|:
name|explicit
name|QAccessibleSlider
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;      enum
name|SliderElements
block|{
name|SliderSelf
operator|=
literal|0
block|,
name|PageLeft
block|,
name|Position
block|,
name|PageRight
block|}
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
name|int
name|defaultAction
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
name|protected
operator|:
name|QSlider
operator|*
name|slider
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
comment|// QT_NO_SLIDER
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DIAL
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleDial
range|:
name|public
name|QAccessibleWidgetEx
block|{
name|public
operator|:
name|explicit
name|QAccessibleDial
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;      enum
name|DialElements
block|{
name|Self
operator|=
literal|0
block|,
name|SpeedoMeter
block|,
name|SliderHandle
block|}
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
argument|Text textType
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
name|QVariant
name|invokeMethodEx
argument_list|(
argument|Method method
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params
argument_list|)
block|;
name|protected
operator|:
name|QDial
operator|*
name|dial
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// RANGECONTROLS_H
end_comment
end_unit
