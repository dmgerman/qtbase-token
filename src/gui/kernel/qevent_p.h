begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVENT_P_H
end_ifndef
begin_define
DECL|macro|QEVENT_P_H
define|#
directive|define
name|QEVENT_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qurl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_include
include|#
directive|include
file|<f32file.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|//
comment|//  W A R N I N G
comment|//  -------------
comment|//
comment|// This file is not part of the Qt API.  It exists purely as an
comment|// implementation detail.  This header file may change from version to
comment|// version without notice, or even be removed.
comment|//
comment|// We mean it.
comment|//
comment|// ### Qt 5: remove
name|class
name|QKeyEventEx
range|:
name|public
name|QKeyEvent
block|{
name|public
operator|:
name|QKeyEventEx
argument_list|(
argument|Type type
argument_list|,
argument|int key
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|,
argument|const QString&text
argument_list|,
argument|bool autorep
argument_list|,
argument|ushort count
argument_list|,
argument|quint32 nativeScanCode
argument_list|,
argument|quint32 nativeVirtualKey
argument_list|,
argument|quint32 nativeModifiers
argument_list|)
block|;
name|QKeyEventEx
argument_list|(
specifier|const
name|QKeyEventEx
operator|&
name|other
argument_list|)
block|;
operator|~
name|QKeyEventEx
argument_list|()
block|;
name|protected
operator|:
name|quint32
name|nScanCode
block|;
name|quint32
name|nVirtualKey
block|;
name|quint32
name|nModifiers
block|;
name|friend
name|class
name|QKeyEvent
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// ### Qt 5: remove
end_comment
begin_decl_stmt
name|class
name|QMouseEventEx
range|:
name|public
name|QMouseEvent
block|{
name|public
operator|:
name|QMouseEventEx
argument_list|(
argument|Type type
argument_list|,
argument|const QPointF&pos
argument_list|,
argument|const QPoint&globalPos
argument_list|,
argument|Qt::MouseButton button
argument_list|,
argument|Qt::MouseButtons buttons
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|)
block|;
operator|~
name|QMouseEventEx
argument_list|()
block|;
name|protected
operator|:
name|QPointF
name|posF
block|;
name|friend
name|class
name|QMouseEvent
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTouchEventTouchPointPrivate
block|{
name|public
label|:
specifier|inline
name|QTouchEventTouchPointPrivate
argument_list|(
argument|int id
argument_list|)
operator|:
name|ref
argument_list|(
literal|1
argument_list|)
operator|,
name|id
argument_list|(
name|id
argument_list|)
operator|,
name|state
argument_list|(
name|Qt
operator|::
name|TouchPointReleased
argument_list|)
operator|,
name|pressure
argument_list|(
argument|qreal(-
literal|1.
argument|)
argument_list|)
block|{ }
specifier|inline
name|QTouchEventTouchPointPrivate
operator|*
name|detach
argument_list|()
block|{
name|QTouchEventTouchPointPrivate
operator|*
name|d
operator|=
name|new
name|QTouchEventTouchPointPrivate
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|d
operator|->
name|ref
operator|=
literal|1
block|;
if|if
condition|(
operator|!
name|this
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|this
decl_stmt|;
return|return
name|d
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|QAtomicInt
name|ref
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|id
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|TouchPointStates
name|state
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QRectF
name|rect
decl_stmt|,
name|sceneRect
decl_stmt|,
name|screenRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPointF
name|normalizedPos
decl_stmt|,
name|startPos
decl_stmt|,
name|startScenePos
decl_stmt|,
name|startScreenPos
decl_stmt|,
name|startNormalizedPos
decl_stmt|,
name|lastPos
decl_stmt|,
name|lastScenePos
decl_stmt|,
name|lastScreenPos
decl_stmt|,
name|lastNormalizedPos
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qreal
name|pressure
decl_stmt|;
end_decl_stmt
begin_ifndef
unit|};
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
begin_decl_stmt
name|class
name|QFileOpenEventPrivate
block|{
name|public
label|:
specifier|inline
name|QFileOpenEventPrivate
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
operator|:
name|url
argument_list|(
argument|url
argument_list|)
block|{     }
operator|~
name|QFileOpenEventPrivate
argument_list|()
expr_stmt|;
name|QUrl
name|url
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|RFile
name|file
decl_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QScrollPrepareEventPrivate
block|{
name|public
label|:
specifier|inline
name|QScrollPrepareEventPrivate
argument_list|()
operator|:
name|target
argument_list|(
literal|0
argument_list|)
block|{     }
name|QObject
operator|*
name|target
expr_stmt|;
name|QPointF
name|startPos
decl_stmt|;
name|QSizeF
name|viewportSize
decl_stmt|;
name|QRectF
name|contentPosRange
decl_stmt|;
name|QPointF
name|contentPos
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QScrollEventPrivate
block|{
name|public
label|:
specifier|inline
name|QScrollEventPrivate
argument_list|()
block|{     }
name|QPointF
name|contentPos
expr_stmt|;
name|QPointF
name|overshoot
decl_stmt|;
name|QScrollEvent
operator|::
name|ScrollState
name|state
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QEVENT_P_H
end_comment
end_unit
