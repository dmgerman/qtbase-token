begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSCROLLER_H
end_ifndef
begin_define
DECL|macro|QSCROLLER_H
define|#
directive|define
name|QSCROLLER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPointF>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QScrollerProperties>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollerPrivate
name|class
name|QScrollerPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollerProperties
name|class
name|QScrollerProperties
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_decl_stmt
DECL|variable|QFlickGestureRecognizer
name|class
name|QFlickGestureRecognizer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMouseFlickGestureRecognizer
name|class
name|QMouseFlickGestureRecognizer
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QScroller
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|State state READ state NOTIFY stateChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QScrollerProperties scrollerProperties READ scrollerProperties WRITE setScrollerProperties NOTIFY scrollerPropertiesChanged
argument_list|)
name|Q_ENUMS
argument_list|(
argument|State
argument_list|)
name|public
operator|:
expr|enum
name|State
block|{
name|Inactive
block|,
name|Pressed
block|,
name|Dragging
block|,
name|Scrolling
block|}
block|;      enum
name|ScrollerGestureType
block|{
name|TouchGesture
block|,
name|LeftMouseButtonGesture
block|,
name|RightMouseButtonGesture
block|,
name|MiddleMouseButtonGesture
block|}
block|;      enum
name|Input
block|{
name|InputPress
operator|=
literal|1
block|,
name|InputMove
block|,
name|InputRelease
block|}
block|;
specifier|static
name|bool
name|hasScroller
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
specifier|static
name|QScroller
operator|*
name|scroller
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
specifier|static
specifier|const
name|QScroller
operator|*
name|scroller
argument_list|(
specifier|const
name|QObject
operator|*
name|target
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
specifier|static
name|Qt
operator|::
name|GestureType
name|grabGesture
argument_list|(
argument|QObject *target
argument_list|,
argument|ScrollerGestureType gestureType = TouchGesture
argument_list|)
block|;
specifier|static
name|Qt
operator|::
name|GestureType
name|grabbedGesture
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
specifier|static
name|void
name|ungrabGesture
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
endif|#
directive|endif
specifier|static
name|QList
operator|<
name|QScroller
operator|*
operator|>
name|activeScrollers
argument_list|()
block|;
name|QObject
operator|*
name|target
argument_list|()
specifier|const
block|;
name|State
name|state
argument_list|()
specifier|const
block|;
name|bool
name|handleInput
argument_list|(
argument|Input input
argument_list|,
argument|const QPointF&position
argument_list|,
argument|qint64 timestamp =
literal|0
argument_list|)
block|;
name|void
name|stop
argument_list|()
block|;
name|QPointF
name|velocity
argument_list|()
specifier|const
block|;
name|QPointF
name|finalPosition
argument_list|()
specifier|const
block|;
name|QPointF
name|pixelPerMeter
argument_list|()
specifier|const
block|;
name|QScrollerProperties
name|scrollerProperties
argument_list|()
specifier|const
block|;
name|void
name|setSnapPositionsX
argument_list|(
specifier|const
name|QList
operator|<
name|qreal
operator|>
operator|&
name|positions
argument_list|)
block|;
name|void
name|setSnapPositionsX
argument_list|(
argument|qreal first
argument_list|,
argument|qreal interval
argument_list|)
block|;
name|void
name|setSnapPositionsY
argument_list|(
specifier|const
name|QList
operator|<
name|qreal
operator|>
operator|&
name|positions
argument_list|)
block|;
name|void
name|setSnapPositionsY
argument_list|(
argument|qreal first
argument_list|,
argument|qreal interval
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setScrollerProperties
argument_list|(
specifier|const
name|QScrollerProperties
operator|&
name|prop
argument_list|)
block|;
name|void
name|scrollTo
argument_list|(
specifier|const
name|QPointF
operator|&
name|pos
argument_list|)
block|;
name|void
name|scrollTo
argument_list|(
argument|const QPointF&pos
argument_list|,
argument|int scrollTime
argument_list|)
block|;
name|void
name|ensureVisible
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|qreal xmargin
argument_list|,
argument|qreal ymargin
argument_list|)
block|;
name|void
name|ensureVisible
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|qreal xmargin
argument_list|,
argument|qreal ymargin
argument_list|,
argument|int scrollTime
argument_list|)
block|;
name|void
name|resendPrepareEvent
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|stateChanged
argument_list|(
argument|QScroller::State newstate
argument_list|)
block|;
name|void
name|scrollerPropertiesChanged
argument_list|(
specifier|const
name|QScrollerProperties
operator|&
argument_list|)
block|;
name|private
operator|:
name|QScrollerPrivate
operator|*
name|d_ptr
block|;
name|QScroller
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
name|virtual
operator|~
name|QScroller
argument_list|()
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QScroller
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QScroller
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|friend
name|class
name|QFlickGestureRecognizer
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSCROLLER_H
end_comment
end_unit
