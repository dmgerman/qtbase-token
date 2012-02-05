begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGESTURE_P_H
end_ifndef
begin_define
DECL|macro|QGESTURE_P_H
define|#
directive|define
name|QGESTURE_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|"qrect.h"
end_include
begin_include
include|#
directive|include
file|"qpoint.h"
end_include
begin_include
include|#
directive|include
file|"qgesture.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QGesturePrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGesture
argument_list|)
name|public
operator|:
name|QGesturePrivate
argument_list|()
operator|:
name|gestureType
argument_list|(
name|Qt
operator|::
name|CustomGesture
argument_list|)
block|,
name|state
argument_list|(
name|Qt
operator|::
name|NoGesture
argument_list|)
block|,
name|isHotSpotSet
argument_list|(
name|false
argument_list|)
block|,
name|gestureCancelPolicy
argument_list|(
literal|0
argument_list|)
block|{     }
name|Qt
operator|::
name|GestureType
name|gestureType
block|;
name|Qt
operator|::
name|GestureState
name|state
block|;
name|QPointF
name|hotSpot
block|;
name|QPointF
name|sceneHotSpot
block|;
name|uint
name|isHotSpotSet
operator|:
literal|1
block|;
name|uint
name|gestureCancelPolicy
operator|:
literal|2
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPanGesturePrivate
range|:
name|public
name|QGesturePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QPanGesture
argument_list|)
name|public
operator|:
name|QPanGesturePrivate
argument_list|()
operator|:
name|acceleration
argument_list|(
literal|0
argument_list|)
block|,
name|xVelocity
argument_list|(
literal|0
argument_list|)
block|,
name|yVelocity
argument_list|(
literal|0
argument_list|)
block|{     }
name|qreal
name|horizontalVelocity
argument_list|()
specifier|const
block|{
return|return
name|xVelocity
return|;
block|}
name|void
name|setHorizontalVelocity
argument_list|(
argument|qreal value
argument_list|)
block|{
name|xVelocity
operator|=
name|value
block|; }
name|qreal
name|verticalVelocity
argument_list|()
specifier|const
block|{
return|return
name|yVelocity
return|;
block|}
name|void
name|setVerticalVelocity
argument_list|(
argument|qreal value
argument_list|)
block|{
name|yVelocity
operator|=
name|value
block|; }
name|QPointF
name|lastOffset
block|;
name|QPointF
name|offset
block|;
name|QPoint
name|startPosition
block|;
name|qreal
name|acceleration
block|;
name|qreal
name|xVelocity
block|;
name|qreal
name|yVelocity
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPinchGesturePrivate
range|:
name|public
name|QGesturePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QPinchGesture
argument_list|)
name|public
operator|:
name|QPinchGesturePrivate
argument_list|()
operator|:
name|totalChangeFlags
argument_list|(
literal|0
argument_list|)
block|,
name|changeFlags
argument_list|(
literal|0
argument_list|)
block|,
name|totalScaleFactor
argument_list|(
literal|1
argument_list|)
block|,
name|lastScaleFactor
argument_list|(
literal|1
argument_list|)
block|,
name|scaleFactor
argument_list|(
literal|1
argument_list|)
block|,
name|totalRotationAngle
argument_list|(
literal|0
argument_list|)
block|,
name|lastRotationAngle
argument_list|(
literal|0
argument_list|)
block|,
name|rotationAngle
argument_list|(
literal|0
argument_list|)
block|,
name|isNewSequence
argument_list|(
argument|true
argument_list|)
block|{     }
name|QPinchGesture
operator|::
name|ChangeFlags
name|totalChangeFlags
block|;
name|QPinchGesture
operator|::
name|ChangeFlags
name|changeFlags
block|;
name|QPointF
name|startCenterPoint
block|;
name|QPointF
name|lastCenterPoint
block|;
name|QPointF
name|centerPoint
block|;
name|qreal
name|totalScaleFactor
block|;
name|qreal
name|lastScaleFactor
block|;
name|qreal
name|scaleFactor
block|;
name|qreal
name|totalRotationAngle
block|;
name|qreal
name|lastRotationAngle
block|;
name|qreal
name|rotationAngle
block|;
name|bool
name|isNewSequence
block|;
name|QPointF
name|startPosition
index|[
literal|2
index|]
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QSwipeGesturePrivate
range|:
name|public
name|QGesturePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QSwipeGesture
argument_list|)
name|public
operator|:
name|QSwipeGesturePrivate
argument_list|()
operator|:
name|horizontalDirection
argument_list|(
name|QSwipeGesture
operator|::
name|NoDirection
argument_list|)
block|,
name|verticalDirection
argument_list|(
name|QSwipeGesture
operator|::
name|NoDirection
argument_list|)
block|,
name|swipeAngle
argument_list|(
literal|0
argument_list|)
block|,
name|started
argument_list|(
name|false
argument_list|)
block|,
name|velocityValue
argument_list|(
literal|0
argument_list|)
block|{     }
name|qreal
name|velocity
argument_list|()
specifier|const
block|{
return|return
name|velocityValue
return|;
block|}
name|void
name|setVelocity
argument_list|(
argument|qreal value
argument_list|)
block|{
name|velocityValue
operator|=
name|value
block|; }
name|QSwipeGesture
operator|::
name|SwipeDirection
name|horizontalDirection
block|;
name|QSwipeGesture
operator|::
name|SwipeDirection
name|verticalDirection
block|;
name|qreal
name|swipeAngle
block|;
name|QPoint
name|lastPositions
index|[
literal|3
index|]
block|;
name|bool
name|started
block|;
name|qreal
name|velocityValue
block|;
name|QElapsedTimer
name|time
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTapGesturePrivate
range|:
name|public
name|QGesturePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTapGesture
argument_list|)
name|public
operator|:
name|QTapGesturePrivate
argument_list|()
block|{     }
name|QPointF
name|position
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTapAndHoldGesturePrivate
range|:
name|public
name|QGesturePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTapAndHoldGesture
argument_list|)
name|public
operator|:
name|QTapAndHoldGesturePrivate
argument_list|()
operator|:
name|timerId
argument_list|(
literal|0
argument_list|)
block|{     }
name|QPointF
name|position
block|;
name|int
name|timerId
block|;
specifier|static
name|int
name|Timeout
block|; }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_decl_stmt
name|class
name|QNativeGestureEvent
range|:
name|public
name|QEvent
block|{
name|public
operator|:
expr|enum
name|Type
block|{
name|None
block|,
name|GestureBegin
block|,
name|GestureEnd
block|,
name|Pan
block|,
name|Zoom
block|,
name|Rotate
block|,
name|Swipe
block|}
block|;
name|QNativeGestureEvent
argument_list|()
operator|:
name|QEvent
argument_list|(
name|QEvent
operator|::
name|NativeGesture
argument_list|)
block|,
name|gestureType
argument_list|(
name|None
argument_list|)
block|,
name|percentage
argument_list|(
literal|0
argument_list|)
ifdef|#
directive|ifdef
name|Q_WS_WIN
block|,
name|sequenceId
argument_list|(
literal|0
argument_list|)
block|,
name|argument
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{     }
name|Type
name|gestureType
block|;
name|float
name|percentage
block|;
name|QPoint
name|position
block|;
name|float
name|angle
block|;
ifdef|#
directive|ifdef
name|Q_WS_WIN
name|ulong
name|sequenceId
block|;
name|quint64
name|argument
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGestureEventPrivate
block|{
name|public
label|:
specifier|inline
name|QGestureEventPrivate
argument_list|(
specifier|const
name|QList
operator|<
name|QGesture
operator|*
operator|>
operator|&
name|list
argument_list|)
operator|:
name|gestures
argument_list|(
name|list
argument_list|)
operator|,
name|widget
argument_list|(
literal|0
argument_list|)
block|{     }
name|QList
operator|<
name|QGesture
operator|*
operator|>
name|gestures
expr_stmt|;
name|QWidget
modifier|*
name|widget
decl_stmt|;
name|QMap
operator|<
name|Qt
operator|::
name|GestureType
operator|,
name|bool
operator|>
name|accepted
expr_stmt|;
name|QMap
operator|<
name|Qt
operator|::
name|GestureType
operator|,
name|QWidget
operator|*
operator|>
name|targetWidgets
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
comment|// QT_NO_GESTURES
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GESTURES
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGESTURE_P_H
end_comment
end_unit
