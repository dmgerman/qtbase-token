begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTSLIDER_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTSLIDER_P_H
define|#
directive|define
name|QABSTRACTSLIDER_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qbasictimer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qelapsedtimer.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"qstyle.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QAbstractSliderPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAbstractSlider
argument_list|)
name|public
operator|:
name|QAbstractSliderPrivate
argument_list|()
block|;
operator|~
name|QAbstractSliderPrivate
argument_list|()
block|;
name|void
name|setSteps
argument_list|(
argument|int single
argument_list|,
argument|int page
argument_list|)
block|;
name|int
name|minimum
block|,
name|maximum
block|,
name|pageStep
block|,
name|value
block|,
name|position
block|,
name|pressValue
block|;
comment|/**      * Call effectiveSingleStep() when changing the slider value.      */
name|int
name|singleStep
block|;
name|float
name|offset_accumulated
block|;
name|uint
name|tracking
operator|:
literal|1
block|;
name|uint
name|blocktracking
operator|:
literal|1
block|;
name|uint
name|pressed
operator|:
literal|1
block|;
name|uint
name|invertedAppearance
operator|:
literal|1
block|;
name|uint
name|invertedControls
operator|:
literal|1
block|;
name|Qt
operator|::
name|Orientation
name|orientation
block|;
name|QBasicTimer
name|repeatActionTimer
block|;
name|int
name|repeatActionTime
block|;
name|QAbstractSlider
operator|::
name|SliderAction
name|repeatAction
block|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|int
name|origValue
block|;
comment|/**      */
name|bool
name|isAutoRepeating
block|;
comment|/**      * When we're auto repeating, we multiply singleStep with this value to      * get our effective step.      */
name|qreal
name|repeatMultiplier
block|;
comment|/**      * The time of when the first auto repeating key press event occurs.      */
name|QElapsedTimer
name|firstRepeat
block|;
endif|#
directive|endif
specifier|inline
name|int
name|effectiveSingleStep
argument_list|()
specifier|const
block|{
return|return
name|singleStep
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
operator|*
name|repeatMultiplier
endif|#
directive|endif
return|;
block|}
name|virtual
name|int
name|bound
argument_list|(
argument|int val
argument_list|)
specifier|const
block|{
return|return
name|qMax
argument_list|(
name|minimum
argument_list|,
name|qMin
argument_list|(
name|maximum
argument_list|,
name|val
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|int
name|overflowSafeAdd
argument_list|(
argument|int add
argument_list|)
specifier|const
block|{
name|int
name|newValue
operator|=
name|value
operator|+
name|add
block|;
if|if
condition|(
name|add
operator|>
literal|0
operator|&&
name|newValue
operator|<
name|value
condition|)
name|newValue
operator|=
name|maximum
expr_stmt|;
elseif|else
if|if
condition|(
name|add
operator|<
literal|0
operator|&&
name|newValue
operator|>
name|value
condition|)
name|newValue
operator|=
name|minimum
expr_stmt|;
return|return
name|newValue
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|void
name|setAdjustedSliderPosition
parameter_list|(
name|int
name|position
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QAbstractSlider
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Slider_StopMouseOverSlider
argument_list|,
literal|0
argument_list|,
name|q
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|position
operator|>
name|pressValue
operator|-
literal|2
operator|*
name|pageStep
operator|)
operator|&&
operator|(
name|position
operator|<
name|pressValue
operator|+
literal|2
operator|*
name|pageStep
operator|)
condition|)
block|{
name|repeatAction
operator|=
name|QAbstractSlider
operator|::
name|SliderNoAction
expr_stmt|;
name|q
operator|->
name|setSliderPosition
argument_list|(
name|pressValue
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|q
operator|->
name|triggerAction
argument_list|(
name|repeatAction
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|bool
name|scrollByDelta
argument_list|(
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
argument_list|,
name|int
name|delta
argument_list|)
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QABSTRACTSLIDER_P_H
end_comment
end_unit
