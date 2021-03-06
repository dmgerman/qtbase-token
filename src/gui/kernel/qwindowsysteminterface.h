begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSYSTEMINTERFACE_H
end_ifndef
begin_define
DECL|macro|QWINDOWSYSTEMINTERFACE_H
define|#
directive|define
name|QWINDOWSYSTEMINTERFACE_H
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
comment|// This file is part of the QPA API and is not meant to be used
end_comment
begin_comment
comment|// in applications. Usage of this API may make your code
end_comment
begin_comment
comment|// source and binary incompatible with future versions of Qt.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/QTime>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QEvent>
end_include
begin_include
include|#
directive|include
file|<QtCore/QAbstractEventDispatcher>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtCore/QWeakPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMutex>
end_include
begin_include
include|#
directive|include
file|<QtGui/QTouchEvent>
end_include
begin_include
include|#
directive|include
file|<QtCore/QEventLoop>
end_include
begin_include
include|#
directive|include
file|<QtGui/QVector2D>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTouchDevice
name|class
name|QTouchDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformDragQtResponse
name|class
name|QPlatformDragQtResponse
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformDropQtResponse
name|class
name|QPlatformDropQtResponse
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QWindowSystemInterface
block|{
name|public
label|:
specifier|static
name|void
name|handleMouseEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|,
name|Qt
operator|::
name|MouseButtons
name|b
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|Qt
operator|::
name|MouseEventSource
name|source
operator|=
name|Qt
operator|::
name|MouseEventNotSynthesized
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleMouseEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|ulong
name|timestamp
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|,
name|Qt
operator|::
name|MouseButtons
name|b
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|Qt
operator|::
name|MouseEventSource
name|source
operator|=
name|Qt
operator|::
name|MouseEventNotSynthesized
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleFrameStrutMouseEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|,
name|Qt
operator|::
name|MouseButtons
name|b
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|Qt
operator|::
name|MouseEventSource
name|source
operator|=
name|Qt
operator|::
name|MouseEventNotSynthesized
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleFrameStrutMouseEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|ulong
name|timestamp
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|,
name|Qt
operator|::
name|MouseButtons
name|b
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|Qt
operator|::
name|MouseEventSource
name|source
operator|=
name|Qt
operator|::
name|MouseEventNotSynthesized
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|handleShortcutEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|ulong
name|timestamp
argument_list|,
name|int
name|k
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
argument_list|,
name|quint32
name|nativeScanCode
argument_list|,
name|quint32
name|nativeVirtualKey
argument_list|,
name|quint32
name|nativeModifiers
argument_list|,
specifier|const
name|QString
operator|&
name|text
operator|=
name|QString
argument_list|()
argument_list|,
name|bool
name|autorep
operator|=
name|false
argument_list|,
name|ushort
name|count
operator|=
literal|1
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|handleKeyEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|QEvent
operator|::
name|Type
name|t
argument_list|,
name|int
name|k
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
argument_list|,
specifier|const
name|QString
operator|&
name|text
operator|=
name|QString
argument_list|()
argument_list|,
name|bool
name|autorep
operator|=
name|false
argument_list|,
name|ushort
name|count
operator|=
literal|1
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|handleKeyEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|ulong
name|timestamp
argument_list|,
name|QEvent
operator|::
name|Type
name|t
argument_list|,
name|int
name|k
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
argument_list|,
specifier|const
name|QString
operator|&
name|text
operator|=
name|QString
argument_list|()
argument_list|,
name|bool
name|autorep
operator|=
name|false
argument_list|,
name|ushort
name|count
operator|=
literal|1
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|handleExtendedKeyEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|QEvent
operator|::
name|Type
name|type
argument_list|,
name|int
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
argument_list|,
name|quint32
name|nativeScanCode
argument_list|,
name|quint32
name|nativeVirtualKey
argument_list|,
name|quint32
name|nativeModifiers
argument_list|,
specifier|const
name|QString
operator|&
name|text
operator|=
name|QString
argument_list|()
argument_list|,
name|bool
name|autorep
operator|=
name|false
argument_list|,
name|ushort
name|count
operator|=
literal|1
argument_list|,
name|bool
name|tryShortcutOverride
operator|=
name|true
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|handleExtendedKeyEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|ulong
name|timestamp
argument_list|,
name|QEvent
operator|::
name|Type
name|type
argument_list|,
name|int
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
argument_list|,
name|quint32
name|nativeScanCode
argument_list|,
name|quint32
name|nativeVirtualKey
argument_list|,
name|quint32
name|nativeModifiers
argument_list|,
specifier|const
name|QString
operator|&
name|text
operator|=
name|QString
argument_list|()
argument_list|,
name|bool
name|autorep
operator|=
name|false
argument_list|,
name|ushort
name|count
operator|=
literal|1
argument_list|,
name|bool
name|tryShortcutOverride
operator|=
name|true
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleWheelEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|,
name|QPoint
name|pixelDelta
argument_list|,
name|QPoint
name|angleDelta
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|Qt
operator|::
name|ScrollPhase
name|phase
operator|=
name|Qt
operator|::
name|NoScrollPhase
argument_list|,
name|Qt
operator|::
name|MouseEventSource
name|source
operator|=
name|Qt
operator|::
name|MouseEventNotSynthesized
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleWheelEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|ulong
name|timestamp
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|,
name|QPoint
name|pixelDelta
argument_list|,
name|QPoint
name|angleDelta
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|Qt
operator|::
name|ScrollPhase
name|phase
operator|=
name|Qt
operator|::
name|NoScrollPhase
argument_list|,
name|Qt
operator|::
name|MouseEventSource
name|source
operator|=
name|Qt
operator|::
name|MouseEventNotSynthesized
argument_list|,
name|bool
name|inverted
operator|=
name|false
argument_list|)
decl_stmt|;
comment|// Wheel event compatibility functions. Will be removed: do not use.
specifier|static
name|void
name|handleWheelEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|,
name|int
name|d
argument_list|,
name|Qt
operator|::
name|Orientation
name|o
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleWheelEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|ulong
name|timestamp
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|,
name|int
name|d
argument_list|,
name|Qt
operator|::
name|Orientation
name|o
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|)
decl_stmt|;
struct|struct
name|TouchPoint
block|{
name|TouchPoint
argument_list|()
operator|:
name|id
argument_list|(
literal|0
argument_list|)
operator|,
name|pressure
argument_list|(
literal|0
argument_list|)
operator|,
name|state
argument_list|(
argument|Qt::TouchPointStationary
argument_list|)
block|{ }
name|int
name|id
expr_stmt|;
comment|// for application use
name|QPointF
name|normalPosition
decl_stmt|;
comment|// touch device coordinates, (0 to 1, 0 to 1)
name|QRectF
name|area
decl_stmt|;
comment|// the touched area, centered at position in screen coordinates
name|qreal
name|pressure
decl_stmt|;
comment|// 0 to 1
name|Qt
operator|::
name|TouchPointState
name|state
expr_stmt|;
comment|//Qt::TouchPoint{Pressed|Moved|Stationary|Released}
name|QVector2D
name|velocity
decl_stmt|;
comment|// in screen coordinate system, pixels / seconds
name|QTouchEvent
operator|::
name|TouchPoint
operator|::
name|InfoFlags
name|flags
expr_stmt|;
name|QVector
operator|<
name|QPointF
operator|>
name|rawPositions
expr_stmt|;
comment|// in screen coordinates
block|}
struct|;
specifier|static
name|void
name|registerTouchDevice
parameter_list|(
specifier|const
name|QTouchDevice
modifier|*
name|device
parameter_list|)
function_decl|;
specifier|static
name|void
name|unregisterTouchDevice
parameter_list|(
specifier|const
name|QTouchDevice
modifier|*
name|device
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleTouchEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|QTouchDevice
operator|*
name|device
argument_list|,
specifier|const
name|QList
operator|<
expr|struct
name|TouchPoint
operator|>
operator|&
name|points
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleTouchEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|ulong
name|timestamp
argument_list|,
name|QTouchDevice
operator|*
name|device
argument_list|,
specifier|const
name|QList
operator|<
expr|struct
name|TouchPoint
operator|>
operator|&
name|points
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleTouchCancelEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|QTouchDevice
operator|*
name|device
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleTouchCancelEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|ulong
name|timestamp
argument_list|,
name|QTouchDevice
operator|*
name|device
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|)
decl_stmt|;
comment|// rect is relative to parent
specifier|static
name|void
name|handleGeometryChange
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QRect
modifier|&
name|newRect
parameter_list|,
specifier|const
name|QRect
modifier|&
name|oldRect
init|=
name|QRect
argument_list|()
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleCloseEvent
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
name|bool
modifier|*
name|accepted
init|=
name|Q_NULLPTR
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleEnterEvent
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|local
init|=
name|QPointF
argument_list|()
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|global
init|=
name|QPointF
argument_list|()
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleLeaveEvent
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleEnterLeaveEvent
parameter_list|(
name|QWindow
modifier|*
name|enter
parameter_list|,
name|QWindow
modifier|*
name|leave
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|local
init|=
name|QPointF
argument_list|()
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|global
init|=
name|QPointF
argument_list|()
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleWindowActivated
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|Qt
operator|::
name|FocusReason
name|r
operator|=
name|Qt
operator|::
name|OtherFocusReason
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleWindowStateChanged
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|Qt
operator|::
name|WindowState
name|newState
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleWindowScreenChanged
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
name|QScreen
modifier|*
name|newScreen
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleApplicationStateChanged
argument_list|(
name|Qt
operator|::
name|ApplicationState
name|newState
argument_list|,
name|bool
name|forcePropagate
operator|=
name|false
argument_list|)
decl_stmt|;
comment|// region is in local coordinates, do not confuse with geometry which is parent-relative
specifier|static
name|void
name|handleExposeEvent
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
comment|// Drag and drop. These events are sent immediately.
specifier|static
name|QPlatformDragQtResponse
name|handleDrag
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
specifier|const
name|QMimeData
operator|*
name|dropData
argument_list|,
specifier|const
name|QPoint
operator|&
name|p
argument_list|,
name|Qt
operator|::
name|DropActions
name|supportedActions
argument_list|)
decl_stmt|;
specifier|static
name|QPlatformDropQtResponse
name|handleDrop
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
specifier|const
name|QMimeData
operator|*
name|dropData
argument_list|,
specifier|const
name|QPoint
operator|&
name|p
argument_list|,
name|Qt
operator|::
name|DropActions
name|supportedActions
argument_list|)
decl_stmt|;
endif|#
directive|endif
specifier|static
name|bool
name|handleNativeEvent
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|eventType
parameter_list|,
name|void
modifier|*
name|message
parameter_list|,
name|long
modifier|*
name|result
parameter_list|)
function_decl|;
comment|// Changes to the screen
specifier|static
name|void
name|handleScreenOrientationChange
argument_list|(
name|QScreen
operator|*
name|screen
argument_list|,
name|Qt
operator|::
name|ScreenOrientation
name|newOrientation
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleScreenGeometryChange
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|,
specifier|const
name|QRect
modifier|&
name|newGeometry
parameter_list|,
specifier|const
name|QRect
modifier|&
name|newAvailableGeometry
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleScreenLogicalDotsPerInchChange
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|,
name|qreal
name|newDpiX
parameter_list|,
name|qreal
name|newDpiY
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleScreenRefreshRateChange
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|,
name|qreal
name|newRefreshRate
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleThemeChange
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleFileOpenEvent
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleFileOpenEvent
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleTabletEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|ulong
name|timestamp
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|,
name|int
name|device
argument_list|,
name|int
name|pointerType
argument_list|,
name|Qt
operator|::
name|MouseButtons
name|buttons
argument_list|,
name|qreal
name|pressure
argument_list|,
name|int
name|xTilt
argument_list|,
name|int
name|yTilt
argument_list|,
name|qreal
name|tangentialPressure
argument_list|,
name|qreal
name|rotation
argument_list|,
name|int
name|z
argument_list|,
name|qint64
name|uid
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleTabletEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|,
name|int
name|device
argument_list|,
name|int
name|pointerType
argument_list|,
name|Qt
operator|::
name|MouseButtons
name|buttons
argument_list|,
name|qreal
name|pressure
argument_list|,
name|int
name|xTilt
argument_list|,
name|int
name|yTilt
argument_list|,
name|qreal
name|tangentialPressure
argument_list|,
name|qreal
name|rotation
argument_list|,
name|int
name|z
argument_list|,
name|qint64
name|uid
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleTabletEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|ulong
name|timestamp
argument_list|,
name|bool
name|down
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|,
name|int
name|device
argument_list|,
name|int
name|pointerType
argument_list|,
name|qreal
name|pressure
argument_list|,
name|int
name|xTilt
argument_list|,
name|int
name|yTilt
argument_list|,
name|qreal
name|tangentialPressure
argument_list|,
name|qreal
name|rotation
argument_list|,
name|int
name|z
argument_list|,
name|qint64
name|uid
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|)
decl_stmt|;
comment|// ### remove in Qt 6
specifier|static
name|void
name|handleTabletEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|bool
name|down
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|,
name|int
name|device
argument_list|,
name|int
name|pointerType
argument_list|,
name|qreal
name|pressure
argument_list|,
name|int
name|xTilt
argument_list|,
name|int
name|yTilt
argument_list|,
name|qreal
name|tangentialPressure
argument_list|,
name|qreal
name|rotation
argument_list|,
name|int
name|z
argument_list|,
name|qint64
name|uid
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|)
decl_stmt|;
comment|// ### remove in Qt 6
specifier|static
name|void
name|handleTabletEnterProximityEvent
parameter_list|(
name|ulong
name|timestamp
parameter_list|,
name|int
name|device
parameter_list|,
name|int
name|pointerType
parameter_list|,
name|qint64
name|uid
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleTabletEnterProximityEvent
parameter_list|(
name|int
name|device
parameter_list|,
name|int
name|pointerType
parameter_list|,
name|qint64
name|uid
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleTabletLeaveProximityEvent
parameter_list|(
name|ulong
name|timestamp
parameter_list|,
name|int
name|device
parameter_list|,
name|int
name|pointerType
parameter_list|,
name|qint64
name|uid
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleTabletLeaveProximityEvent
parameter_list|(
name|int
name|device
parameter_list|,
name|int
name|pointerType
parameter_list|,
name|qint64
name|uid
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
specifier|static
name|void
name|handleGestureEvent
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|ulong
name|timestamp
argument_list|,
name|Qt
operator|::
name|NativeGestureType
name|type
argument_list|,
name|QPointF
operator|&
name|local
argument_list|,
name|QPointF
operator|&
name|global
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleGestureEventWithRealValue
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|ulong
name|timestamp
argument_list|,
name|Qt
operator|::
name|NativeGestureType
name|type
argument_list|,
name|qreal
name|value
argument_list|,
name|QPointF
operator|&
name|local
argument_list|,
name|QPointF
operator|&
name|global
argument_list|)
decl_stmt|;
specifier|static
name|void
name|handleGestureEventWithSequenceIdAndValue
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|ulong
name|timestamp
argument_list|,
name|Qt
operator|::
name|NativeGestureType
name|type
argument_list|,
name|ulong
name|sequenceId
argument_list|,
name|quint64
name|value
argument_list|,
name|QPointF
operator|&
name|local
argument_list|,
name|QPointF
operator|&
name|global
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|// QT_NO_GESTURES
specifier|static
name|void
name|handlePlatformPanelEvent
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
specifier|static
name|void
name|handleContextMenuEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|bool
name|mouseTriggered
argument_list|,
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
specifier|const
name|QPoint
operator|&
name|globalPos
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
argument_list|)
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
specifier|static
name|void
name|handleEnterWhatsThisEvent
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|// For event dispatcher implementations
specifier|static
name|bool
name|sendWindowSystemEvents
argument_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
argument_list|)
decl_stmt|;
specifier|static
name|void
name|setSynchronousWindowSystemEvents
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
specifier|static
name|bool
name|flushWindowSystemEvents
argument_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
operator|=
name|QEventLoop
operator|::
name|AllEvents
argument_list|)
decl_stmt|;
specifier|static
name|void
name|deferredFlushWindowSystemEvents
argument_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
argument_list|)
decl_stmt|;
specifier|static
name|int
name|windowSystemEventsQueued
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|dbg
operator|,
specifier|const
name|QWindowSystemInterface
operator|::
name|TouchPoint
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSYSTEMINTERFACE_H
end_comment
end_unit
