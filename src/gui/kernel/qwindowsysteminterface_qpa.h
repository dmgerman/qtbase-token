begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_macro
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
argument|Gui
argument_list|)
end_macro
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
name|QPoint
operator|&
name|local
argument_list|,
specifier|const
name|QPoint
operator|&
name|global
argument_list|,
name|Qt
operator|::
name|MouseButtons
name|b
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
name|QPoint
operator|&
name|local
argument_list|,
specifier|const
name|QPoint
operator|&
name|global
argument_list|,
name|Qt
operator|::
name|MouseButtons
name|b
argument_list|)
decl_stmt|;
specifier|static
name|void
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
name|void
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
name|void
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
argument_list|)
decl_stmt|;
specifier|static
name|void
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
name|QPoint
operator|&
name|local
argument_list|,
specifier|const
name|QPoint
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
name|QPoint
operator|&
name|local
argument_list|,
specifier|const
name|QPoint
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
argument_list|)
decl_stmt|;
struct|struct
name|TouchPoint
block|{
name|int
name|id
decl_stmt|;
comment|// for application use
name|bool
name|isPrimary
decl_stmt|;
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
block|}
struct|;
specifier|static
name|void
name|handleTouchEvent
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
name|QTouchEvent
operator|::
name|DeviceType
name|devType
argument_list|,
specifier|const
name|QList
operator|<
expr|struct
name|TouchPoint
operator|>
operator|&
name|points
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
name|QEvent
operator|::
name|Type
name|type
argument_list|,
name|QTouchEvent
operator|::
name|DeviceType
name|devType
argument_list|,
specifier|const
name|QList
operator|<
expr|struct
name|TouchPoint
operator|>
operator|&
name|points
argument_list|)
decl_stmt|;
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
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleSynchronousGeometryChange
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QRect
modifier|&
name|newRect
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleCloseEvent
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleEnterEvent
parameter_list|(
name|QWindow
modifier|*
name|w
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
name|handleWindowActivated
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
function_decl|;
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
name|handleMapEvent
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleUnmapEvent
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleExposeEvent
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
comment|// Drag and drop. These events are sent immediately.
specifier|static
name|Qt
operator|::
name|DropAction
name|handleDrag
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|QMimeData
operator|*
name|dropData
argument_list|,
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
expr_stmt|;
specifier|static
name|Qt
operator|::
name|DropAction
name|handleDrop
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|QMimeData
operator|*
name|dropData
argument_list|,
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
expr_stmt|;
comment|// Changes to the screen
specifier|static
name|void
name|handleScreenGeometryChange
parameter_list|(
name|int
name|screenIndex
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleScreenAvailableGeometryChange
parameter_list|(
name|int
name|screenIndex
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleScreenCountChange
parameter_list|(
name|int
name|count
parameter_list|)
function_decl|;
comment|// For event dispatcher implementations
specifier|static
name|bool
name|sendWindowSystemEvents
argument_list|(
name|QAbstractEventDispatcher
operator|*
name|eventDispatcher
argument_list|,
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
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSYSTEMINTERFACE_H
end_comment
end_unit
