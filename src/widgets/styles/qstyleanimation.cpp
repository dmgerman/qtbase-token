begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstyleanimation_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
end_ifndef
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qwidget.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|ScrollBarFadeOutDuration
specifier|static
specifier|const
name|qreal
name|ScrollBarFadeOutDuration
init|=
literal|200.0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ScrollBarFadeOutDelay
specifier|static
specifier|const
name|qreal
name|ScrollBarFadeOutDelay
init|=
literal|450.0
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QStyleAnimation
name|QStyleAnimation
operator|::
name|QStyleAnimation
parameter_list|(
name|QObject
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QAbstractAnimation
argument_list|(
name|target
argument_list|)
member_init_list|,
name|_delay
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|_duration
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|_startTime
argument_list|(
name|QTime
operator|::
name|currentTime
argument_list|()
argument_list|)
member_init_list|,
name|_fps
argument_list|(
name|ThirtyFps
argument_list|)
member_init_list|,
name|_skip
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QStyleAnimation
name|QStyleAnimation
operator|::
name|~
name|QStyleAnimation
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|target
name|QObject
modifier|*
name|QStyleAnimation
operator|::
name|target
parameter_list|()
specifier|const
block|{
return|return
name|parent
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|duration
name|int
name|QStyleAnimation
operator|::
name|duration
parameter_list|()
specifier|const
block|{
return|return
name|_duration
return|;
block|}
end_function
begin_function
DECL|function|setDuration
name|void
name|QStyleAnimation
operator|::
name|setDuration
parameter_list|(
name|int
name|duration
parameter_list|)
block|{
name|_duration
operator|=
name|duration
expr_stmt|;
block|}
end_function
begin_function
DECL|function|delay
name|int
name|QStyleAnimation
operator|::
name|delay
parameter_list|()
specifier|const
block|{
return|return
name|_delay
return|;
block|}
end_function
begin_function
DECL|function|setDelay
name|void
name|QStyleAnimation
operator|::
name|setDelay
parameter_list|(
name|int
name|delay
parameter_list|)
block|{
name|_delay
operator|=
name|delay
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startTime
name|QTime
name|QStyleAnimation
operator|::
name|startTime
parameter_list|()
specifier|const
block|{
return|return
name|_startTime
return|;
block|}
end_function
begin_function
DECL|function|setStartTime
name|void
name|QStyleAnimation
operator|::
name|setStartTime
parameter_list|(
specifier|const
name|QTime
modifier|&
name|time
parameter_list|)
block|{
name|_startTime
operator|=
name|time
expr_stmt|;
block|}
end_function
begin_function
DECL|function|frameRate
name|QStyleAnimation
operator|::
name|FrameRate
name|QStyleAnimation
operator|::
name|frameRate
parameter_list|()
specifier|const
block|{
return|return
name|_fps
return|;
block|}
end_function
begin_function
DECL|function|setFrameRate
name|void
name|QStyleAnimation
operator|::
name|setFrameRate
parameter_list|(
name|FrameRate
name|fps
parameter_list|)
block|{
name|_fps
operator|=
name|fps
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateTarget
name|void
name|QStyleAnimation
operator|::
name|updateTarget
parameter_list|()
block|{
name|QEvent
name|event
argument_list|(
name|QEvent
operator|::
name|StyleAnimationUpdate
argument_list|)
decl_stmt|;
name|event
operator|.
name|setAccepted
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|target
argument_list|()
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|event
operator|.
name|isAccepted
argument_list|()
condition|)
name|stop
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|start
name|void
name|QStyleAnimation
operator|::
name|start
parameter_list|()
block|{
name|_skip
operator|=
literal|0
expr_stmt|;
name|QAbstractAnimation
operator|::
name|start
argument_list|(
name|DeleteWhenStopped
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isUpdateNeeded
name|bool
name|QStyleAnimation
operator|::
name|isUpdateNeeded
parameter_list|()
specifier|const
block|{
return|return
name|currentTime
argument_list|()
operator|>
name|_delay
return|;
block|}
end_function
begin_function
DECL|function|updateCurrentTime
name|void
name|QStyleAnimation
operator|::
name|updateCurrentTime
parameter_list|(
name|int
parameter_list|)
block|{
if|if
condition|(
operator|++
name|_skip
operator|>=
name|_fps
condition|)
block|{
name|_skip
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|target
argument_list|()
operator|&&
name|isUpdateNeeded
argument_list|()
condition|)
name|updateTarget
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|QProgressStyleAnimation
name|QProgressStyleAnimation
operator|::
name|QProgressStyleAnimation
parameter_list|(
name|int
name|speed
parameter_list|,
name|QObject
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QStyleAnimation
argument_list|(
name|target
argument_list|)
member_init_list|,
name|_speed
argument_list|(
name|speed
argument_list|)
member_init_list|,
name|_step
argument_list|(
operator|-
literal|1
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|animationStep
name|int
name|QProgressStyleAnimation
operator|::
name|animationStep
parameter_list|()
specifier|const
block|{
return|return
name|currentTime
argument_list|()
operator|/
operator|(
literal|1000.0
operator|/
name|_speed
operator|)
return|;
block|}
end_function
begin_function
DECL|function|progressStep
name|int
name|QProgressStyleAnimation
operator|::
name|progressStep
parameter_list|(
name|int
name|width
parameter_list|)
specifier|const
block|{
name|int
name|step
init|=
name|animationStep
argument_list|()
decl_stmt|;
name|int
name|progress
init|=
operator|(
name|step
operator|*
name|width
operator|/
name|_speed
operator|)
operator|%
name|width
decl_stmt|;
if|if
condition|(
operator|(
operator|(
name|step
operator|*
name|width
operator|/
name|_speed
operator|)
operator|%
operator|(
literal|2
operator|*
name|width
operator|)
operator|)
operator|>=
name|width
condition|)
name|progress
operator|=
name|width
operator|-
name|progress
expr_stmt|;
return|return
name|progress
return|;
block|}
end_function
begin_function
DECL|function|speed
name|int
name|QProgressStyleAnimation
operator|::
name|speed
parameter_list|()
specifier|const
block|{
return|return
name|_speed
return|;
block|}
end_function
begin_function
DECL|function|setSpeed
name|void
name|QProgressStyleAnimation
operator|::
name|setSpeed
parameter_list|(
name|int
name|speed
parameter_list|)
block|{
name|_speed
operator|=
name|speed
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isUpdateNeeded
name|bool
name|QProgressStyleAnimation
operator|::
name|isUpdateNeeded
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|QStyleAnimation
operator|::
name|isUpdateNeeded
argument_list|()
condition|)
block|{
name|int
name|current
init|=
name|animationStep
argument_list|()
decl_stmt|;
if|if
condition|(
name|_step
operator|==
operator|-
literal|1
operator|||
name|_step
operator|!=
name|current
condition|)
block|{
name|_step
operator|=
name|current
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_constructor
DECL|function|QNumberStyleAnimation
name|QNumberStyleAnimation
operator|::
name|QNumberStyleAnimation
parameter_list|(
name|QObject
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QStyleAnimation
argument_list|(
name|target
argument_list|)
member_init_list|,
name|_start
argument_list|(
literal|0.0
argument_list|)
member_init_list|,
name|_end
argument_list|(
literal|1.0
argument_list|)
member_init_list|,
name|_prev
argument_list|(
literal|0.0
argument_list|)
block|{
name|setDuration
argument_list|(
literal|250
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|startValue
name|qreal
name|QNumberStyleAnimation
operator|::
name|startValue
parameter_list|()
specifier|const
block|{
return|return
name|_start
return|;
block|}
end_function
begin_function
DECL|function|setStartValue
name|void
name|QNumberStyleAnimation
operator|::
name|setStartValue
parameter_list|(
name|qreal
name|value
parameter_list|)
block|{
name|_start
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endValue
name|qreal
name|QNumberStyleAnimation
operator|::
name|endValue
parameter_list|()
specifier|const
block|{
return|return
name|_end
return|;
block|}
end_function
begin_function
DECL|function|setEndValue
name|void
name|QNumberStyleAnimation
operator|::
name|setEndValue
parameter_list|(
name|qreal
name|value
parameter_list|)
block|{
name|_end
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentValue
name|qreal
name|QNumberStyleAnimation
operator|::
name|currentValue
parameter_list|()
specifier|const
block|{
name|qreal
name|step
init|=
name|qreal
argument_list|(
name|currentTime
argument_list|()
operator|-
name|delay
argument_list|()
argument_list|)
operator|/
operator|(
name|duration
argument_list|()
operator|-
name|delay
argument_list|()
operator|)
decl_stmt|;
return|return
name|_start
operator|+
name|qMax
argument_list|(
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|,
name|step
argument_list|)
operator|*
operator|(
name|_end
operator|-
name|_start
operator|)
return|;
block|}
end_function
begin_function
DECL|function|isUpdateNeeded
name|bool
name|QNumberStyleAnimation
operator|::
name|isUpdateNeeded
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|QStyleAnimation
operator|::
name|isUpdateNeeded
argument_list|()
condition|)
block|{
name|qreal
name|current
init|=
name|currentValue
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|qFuzzyCompare
argument_list|(
name|_prev
argument_list|,
name|current
argument_list|)
condition|)
block|{
name|_prev
operator|=
name|current
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_constructor
DECL|function|QBlendStyleAnimation
name|QBlendStyleAnimation
operator|::
name|QBlendStyleAnimation
parameter_list|(
name|Type
name|type
parameter_list|,
name|QObject
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QStyleAnimation
argument_list|(
name|target
argument_list|)
member_init_list|,
name|_type
argument_list|(
name|type
argument_list|)
block|{
name|setDuration
argument_list|(
literal|250
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|startImage
name|QImage
name|QBlendStyleAnimation
operator|::
name|startImage
parameter_list|()
specifier|const
block|{
return|return
name|_start
return|;
block|}
end_function
begin_function
DECL|function|setStartImage
name|void
name|QBlendStyleAnimation
operator|::
name|setStartImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|_start
operator|=
name|image
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endImage
name|QImage
name|QBlendStyleAnimation
operator|::
name|endImage
parameter_list|()
specifier|const
block|{
return|return
name|_end
return|;
block|}
end_function
begin_function
DECL|function|setEndImage
name|void
name|QBlendStyleAnimation
operator|::
name|setEndImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|_end
operator|=
name|image
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentImage
name|QImage
name|QBlendStyleAnimation
operator|::
name|currentImage
parameter_list|()
specifier|const
block|{
return|return
name|_current
return|;
block|}
end_function
begin_comment
comment|/*! \internal      A helper function to blend two images.      The result consists of ((alpha)*startImage) + ((1-alpha)*endImage)  */
end_comment
begin_function
DECL|function|blendedImage
specifier|static
name|QImage
name|blendedImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|start
parameter_list|,
specifier|const
name|QImage
modifier|&
name|end
parameter_list|,
name|float
name|alpha
parameter_list|)
block|{
if|if
condition|(
name|start
operator|.
name|isNull
argument_list|()
operator|||
name|end
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|QImage
argument_list|()
return|;
name|QImage
name|blended
decl_stmt|;
specifier|const
name|int
name|a
init|=
name|qRound
argument_list|(
name|alpha
operator|*
literal|256
argument_list|)
decl_stmt|;
specifier|const
name|int
name|ia
init|=
literal|256
operator|-
name|a
decl_stmt|;
specifier|const
name|int
name|sw
init|=
name|start
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|sh
init|=
name|start
operator|.
name|height
argument_list|()
decl_stmt|;
specifier|const
name|int
name|bpl
init|=
name|start
operator|.
name|bytesPerLine
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|start
operator|.
name|depth
argument_list|()
condition|)
block|{
case|case
literal|32
case|:
block|{
name|blended
operator|=
name|QImage
argument_list|(
name|sw
argument_list|,
name|sh
argument_list|,
name|start
operator|.
name|format
argument_list|()
argument_list|)
expr_stmt|;
name|blended
operator|.
name|setDevicePixelRatio
argument_list|(
name|start
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
expr_stmt|;
name|uchar
modifier|*
name|mixed_data
init|=
name|blended
operator|.
name|bits
argument_list|()
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|back_data
init|=
name|start
operator|.
name|bits
argument_list|()
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|front_data
init|=
name|end
operator|.
name|bits
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|sy
init|=
literal|0
init|;
name|sy
operator|<
name|sh
condition|;
name|sy
operator|++
control|)
block|{
name|quint32
modifier|*
name|mixed
init|=
operator|(
name|quint32
operator|*
operator|)
name|mixed_data
decl_stmt|;
specifier|const
name|quint32
modifier|*
name|back
init|=
operator|(
specifier|const
name|quint32
operator|*
operator|)
name|back_data
decl_stmt|;
specifier|const
name|quint32
modifier|*
name|front
init|=
operator|(
specifier|const
name|quint32
operator|*
operator|)
name|front_data
decl_stmt|;
for|for
control|(
name|int
name|sx
init|=
literal|0
init|;
name|sx
operator|<
name|sw
condition|;
name|sx
operator|++
control|)
block|{
name|quint32
name|bp
init|=
name|back
index|[
name|sx
index|]
decl_stmt|;
name|quint32
name|fp
init|=
name|front
index|[
name|sx
index|]
decl_stmt|;
name|mixed
index|[
name|sx
index|]
operator|=
name|qRgba
argument_list|(
operator|(
name|qRed
argument_list|(
name|bp
argument_list|)
operator|*
name|ia
operator|+
name|qRed
argument_list|(
name|fp
argument_list|)
operator|*
name|a
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|qGreen
argument_list|(
name|bp
argument_list|)
operator|*
name|ia
operator|+
name|qGreen
argument_list|(
name|fp
argument_list|)
operator|*
name|a
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|qBlue
argument_list|(
name|bp
argument_list|)
operator|*
name|ia
operator|+
name|qBlue
argument_list|(
name|fp
argument_list|)
operator|*
name|a
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|qAlpha
argument_list|(
name|bp
argument_list|)
operator|*
name|ia
operator|+
name|qAlpha
argument_list|(
name|fp
argument_list|)
operator|*
name|a
operator|)
operator|>>
literal|8
argument_list|)
expr_stmt|;
block|}
name|mixed_data
operator|+=
name|bpl
expr_stmt|;
name|back_data
operator|+=
name|bpl
expr_stmt|;
name|front_data
operator|+=
name|bpl
expr_stmt|;
block|}
block|}
default|default:
break|break;
block|}
return|return
name|blended
return|;
block|}
end_function
begin_function
DECL|function|updateCurrentTime
name|void
name|QBlendStyleAnimation
operator|::
name|updateCurrentTime
parameter_list|(
name|int
name|time
parameter_list|)
block|{
name|QStyleAnimation
operator|::
name|updateCurrentTime
argument_list|(
name|time
argument_list|)
expr_stmt|;
name|float
name|alpha
init|=
literal|1.0
decl_stmt|;
if|if
condition|(
name|duration
argument_list|()
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|_type
operator|==
name|Pulse
condition|)
block|{
name|time
operator|=
name|time
operator|%
name|duration
argument_list|()
operator|*
literal|2
expr_stmt|;
if|if
condition|(
name|time
operator|>
name|duration
argument_list|()
condition|)
name|time
operator|=
name|duration
argument_list|()
operator|*
literal|2
operator|-
name|time
expr_stmt|;
block|}
name|alpha
operator|=
name|time
operator|/
cast|static_cast
argument_list|<
name|float
argument_list|>
argument_list|(
name|duration
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|_type
operator|==
name|Transition
operator|&&
name|time
operator|>
name|duration
argument_list|()
condition|)
block|{
name|alpha
operator|=
literal|1.0
expr_stmt|;
name|stop
argument_list|()
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|time
operator|>
literal|0
condition|)
block|{
name|stop
argument_list|()
expr_stmt|;
block|}
name|_current
operator|=
name|blendedImage
argument_list|(
name|_start
argument_list|,
name|_end
argument_list|,
name|alpha
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QScrollbarStyleAnimation
name|QScrollbarStyleAnimation
operator|::
name|QScrollbarStyleAnimation
parameter_list|(
name|Mode
name|mode
parameter_list|,
name|QObject
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QNumberStyleAnimation
argument_list|(
name|target
argument_list|)
member_init_list|,
name|_mode
argument_list|(
name|mode
argument_list|)
member_init_list|,
name|_active
argument_list|(
literal|false
argument_list|)
block|{
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|Activating
case|:
name|setDuration
argument_list|(
name|ScrollBarFadeOutDuration
argument_list|)
expr_stmt|;
name|setStartValue
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
name|setEndValue
argument_list|(
literal|1.0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Deactivating
case|:
name|setDuration
argument_list|(
name|ScrollBarFadeOutDelay
operator|+
name|ScrollBarFadeOutDuration
argument_list|)
expr_stmt|;
name|setDelay
argument_list|(
name|ScrollBarFadeOutDelay
argument_list|)
expr_stmt|;
name|setStartValue
argument_list|(
literal|1.0
argument_list|)
expr_stmt|;
name|setEndValue
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_constructor
begin_function
DECL|function|mode
name|QScrollbarStyleAnimation
operator|::
name|Mode
name|QScrollbarStyleAnimation
operator|::
name|mode
parameter_list|()
specifier|const
block|{
return|return
name|_mode
return|;
block|}
end_function
begin_function
DECL|function|wasActive
name|bool
name|QScrollbarStyleAnimation
operator|::
name|wasActive
parameter_list|()
specifier|const
block|{
return|return
name|_active
return|;
block|}
end_function
begin_function
DECL|function|setActive
name|void
name|QScrollbarStyleAnimation
operator|::
name|setActive
parameter_list|(
name|bool
name|active
parameter_list|)
block|{
name|_active
operator|=
name|active
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateCurrentTime
name|void
name|QScrollbarStyleAnimation
operator|::
name|updateCurrentTime
parameter_list|(
name|int
name|time
parameter_list|)
block|{
name|QNumberStyleAnimation
operator|::
name|updateCurrentTime
argument_list|(
name|time
argument_list|)
expr_stmt|;
if|if
condition|(
name|_mode
operator|==
name|Deactivating
operator|&&
name|qFuzzyIsNull
argument_list|(
name|currentValue
argument_list|()
argument_list|)
condition|)
name|target
argument_list|()
operator|->
name|setProperty
argument_list|(
literal|"visible"
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qstyleanimation_p.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ANIMATION
end_comment
end_unit
