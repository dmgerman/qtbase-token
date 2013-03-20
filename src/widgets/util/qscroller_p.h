begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSCROLLER_P_H
end_ifndef
begin_define
DECL|macro|QSCROLLER_P_H
define|#
directive|define
name|QSCROLLER_P_H
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
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QPointer>
end_include
begin_include
include|#
directive|include
file|<QQueue>
end_include
begin_include
include|#
directive|include
file|<QSet>
end_include
begin_include
include|#
directive|include
file|<QEasingCurve>
end_include
begin_include
include|#
directive|include
file|<QElapsedTimer>
end_include
begin_include
include|#
directive|include
file|<QSizeF>
end_include
begin_include
include|#
directive|include
file|<QPointF>
end_include
begin_include
include|#
directive|include
file|<QRectF>
end_include
begin_include
include|#
directive|include
file|<qscroller.h>
end_include
begin_include
include|#
directive|include
file|<qscrollerproperties.h>
end_include
begin_include
include|#
directive|include
file|<private/qscrollerproperties_p.h>
end_include
begin_include
include|#
directive|include
file|<QAbstractAnimation>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
DECL|variable|QFlickGestureRecognizer
name|class
name|QFlickGestureRecognizer
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
end_ifndef
begin_decl_stmt
DECL|variable|QScrollTimer
name|class
name|QScrollTimer
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QScrollerPrivate
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QScroller
argument_list|)
name|public
operator|:
name|QScrollerPrivate
argument_list|(
name|QScroller
operator|*
name|q
argument_list|,
name|QObject
operator|*
name|target
argument_list|)
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|sendEvent
argument_list|(
name|QObject
operator|*
name|o
argument_list|,
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|setState
argument_list|(
argument|QScroller::State s
argument_list|)
block|;      enum
name|ScrollType
block|{
name|ScrollTypeFlick
operator|=
literal|0
block|,
name|ScrollTypeScrollTo
block|,
name|ScrollTypeOvershoot
block|}
block|;      struct
name|ScrollSegment
block|{
name|qint64
name|startTime
block|;
name|qint64
name|deltaTime
block|;
name|qreal
name|startPos
block|;
name|qreal
name|deltaPos
block|;
name|QEasingCurve
name|curve
block|;
name|qreal
name|stopProgress
block|;
comment|// whatever is..
name|qreal
name|stopPos
block|;
comment|// ..reached first
name|ScrollType
name|type
block|;     }
block|;
name|bool
name|pressWhileInactive
argument_list|(
argument|const QPointF&position
argument_list|,
argument|qint64 timestamp
argument_list|)
block|;
name|bool
name|moveWhilePressed
argument_list|(
argument|const QPointF&position
argument_list|,
argument|qint64 timestamp
argument_list|)
block|;
name|bool
name|releaseWhilePressed
argument_list|(
argument|const QPointF&position
argument_list|,
argument|qint64 timestamp
argument_list|)
block|;
name|bool
name|moveWhileDragging
argument_list|(
argument|const QPointF&position
argument_list|,
argument|qint64 timestamp
argument_list|)
block|;
name|bool
name|releaseWhileDragging
argument_list|(
argument|const QPointF&position
argument_list|,
argument|qint64 timestamp
argument_list|)
block|;
name|bool
name|pressWhileScrolling
argument_list|(
argument|const QPointF&position
argument_list|,
argument|qint64 timestamp
argument_list|)
block|;
name|void
name|timerTick
argument_list|()
block|;
name|void
name|timerEventWhileDragging
argument_list|()
block|;
name|void
name|timerEventWhileScrolling
argument_list|()
block|;
name|bool
name|prepareScrolling
argument_list|(
specifier|const
name|QPointF
operator|&
name|position
argument_list|)
block|;
name|void
name|handleDrag
argument_list|(
argument|const QPointF&position
argument_list|,
argument|qint64 timestamp
argument_list|)
block|;
name|QPointF
name|realDpi
argument_list|(
argument|int screen
argument_list|)
block|;
name|QPointF
name|dpi
argument_list|()
specifier|const
block|;
name|void
name|setDpi
argument_list|(
specifier|const
name|QPointF
operator|&
name|dpi
argument_list|)
block|;
name|void
name|setDpiFromWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|updateVelocity
argument_list|(
argument|const QPointF&deltaPixelRaw
argument_list|,
argument|qint64 deltaTime
argument_list|)
block|;
name|void
name|pushSegment
argument_list|(
argument|ScrollType type
argument_list|,
argument|qreal deltaTime
argument_list|,
argument|qreal stopProgress
argument_list|,
argument|qreal startPos
argument_list|,
argument|qreal deltaPos
argument_list|,
argument|qreal stopPos
argument_list|,
argument|QEasingCurve::Type curve
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
name|void
name|recalcScrollingSegments
argument_list|(
argument|bool forceRecalc = false
argument_list|)
block|;
name|qreal
name|scrollingSegmentsEndPos
argument_list|(
argument|Qt::Orientation orientation
argument_list|)
specifier|const
block|;
name|bool
name|scrollingSegmentsValid
argument_list|(
argument|Qt::Orientation orientation
argument_list|)
block|;
name|void
name|createScrollToSegments
argument_list|(
argument|qreal v
argument_list|,
argument|qreal deltaTime
argument_list|,
argument|qreal endPos
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|ScrollType type
argument_list|)
block|;
name|void
name|createScrollingSegments
argument_list|(
argument|qreal v
argument_list|,
argument|qreal startPos
argument_list|,
argument|qreal deltaTime
argument_list|,
argument|qreal deltaPos
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
name|void
name|createScrollingSegments
argument_list|(
specifier|const
name|QPointF
operator|&
name|v
argument_list|,
specifier|const
name|QPointF
operator|&
name|startPos
argument_list|,
specifier|const
name|QPointF
operator|&
name|ppm
argument_list|)
block|;
name|void
name|setContentPositionHelperDragging
argument_list|(
specifier|const
name|QPointF
operator|&
name|deltaPos
argument_list|)
block|;
name|void
name|setContentPositionHelperScrolling
argument_list|()
block|;
name|qreal
name|nextSnapPos
argument_list|(
argument|qreal p
argument_list|,
argument|int dir
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
specifier|static
name|qreal
name|nextSegmentPosition
argument_list|(
argument|QQueue<ScrollSegment>&segments
argument_list|,
argument|qint64 now
argument_list|,
argument|qreal oldPos
argument_list|)
block|;
specifier|inline
name|int
name|frameRateSkip
argument_list|()
specifier|const
block|{
return|return
name|properties
operator|.
name|d
operator|.
name|data
argument_list|()
operator|->
name|frameRate
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|stateName
argument_list|(
argument|QScroller::State state
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|inputName
argument_list|(
argument|QScroller::Input input
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|targetDestroyed
argument_list|()
block|;
name|public
operator|:
comment|// non static
name|QObject
operator|*
name|target
block|;
name|QScrollerProperties
name|properties
block|;
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|QFlickGestureRecognizer
operator|*
name|recognizer
block|;
name|Qt
operator|::
name|GestureType
name|recognizerType
block|;
endif|#
directive|endif
comment|// scroller state:
comment|// QPointer<QObject> scrollTarget;
name|QSizeF
name|viewportSize
block|;
name|QRectF
name|contentPosRange
block|;
name|QPointF
name|contentPosition
block|;
name|QPointF
name|overshootPosition
block|;
comment|// the number of pixels we are overshooting (before overshootDragResistanceFactor)
comment|// state
name|bool
name|enabled
block|;
name|QScroller
operator|::
name|State
name|state
block|;
name|bool
name|firstScroll
block|;
comment|// true if we haven't already send a scroll event
name|QPointF
name|oldVelocity
block|;
comment|// the release velocity of the last drag
name|QPointF
name|pressPosition
block|;
name|QPointF
name|lastPosition
block|;
name|qint64
name|pressTimestamp
block|;
name|qint64
name|lastTimestamp
block|;
name|QPointF
name|dragDistance
block|;
comment|// the distance we should move during the next drag timer event
name|QQueue
operator|<
name|ScrollSegment
operator|>
name|xSegments
block|;
name|QQueue
operator|<
name|ScrollSegment
operator|>
name|ySegments
block|;
comment|// snap positions
name|QList
operator|<
name|qreal
operator|>
name|snapPositionsX
block|;
name|qreal
name|snapFirstX
block|;
name|qreal
name|snapIntervalX
block|;
name|QList
operator|<
name|qreal
operator|>
name|snapPositionsY
block|;
name|qreal
name|snapFirstY
block|;
name|qreal
name|snapIntervalY
block|;
name|QPointF
name|pixelPerMeter
block|;
name|QElapsedTimer
name|monotonicTimer
block|;
name|QPointF
name|releaseVelocity
block|;
comment|// the starting velocity of the scrolling state
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|QScrollTimer
operator|*
name|scrollTimer
block|;
endif|#
directive|endif
name|QScroller
operator|*
name|q_ptr
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
comment|// QSCROLLER_P_H
end_comment
end_unit
