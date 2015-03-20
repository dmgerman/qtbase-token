begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBWINDOW_H
end_ifndef
begin_define
DECL|macro|QXCBWINDOW_H
define|#
directive|define
name|QXCBWINDOW_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_include
include|#
directive|include
file|<xcb/sync.h>
end_include
begin_include
include|#
directive|include
file|"qxcbobject.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformHeaders/qxcbwindowfunctions.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbScreen
name|class
name|QXcbScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbSyncWindowRequest
name|class
name|QXcbSyncWindowRequest
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIcon
name|class
name|QIcon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbObject
DECL|variable|QXcbWindowEventListener
name|class
name|Q_XCB_EXPORT
name|QXcbWindow
range|:
name|public
name|QXcbObject
decl_stmt|,
name|public
name|QXcbWindowEventListener
decl_stmt|,
name|public
name|QPlatformWindow
block|{
name|public
label|:
enum|enum
name|NetWmState
block|{
name|NetWmStateAbove
init|=
literal|0x1
block|,
name|NetWmStateBelow
init|=
literal|0x2
block|,
name|NetWmStateFullScreen
init|=
literal|0x4
block|,
name|NetWmStateMaximizedHorz
init|=
literal|0x8
block|,
name|NetWmStateMaximizedVert
init|=
literal|0x10
block|,
name|NetWmStateModal
init|=
literal|0x20
block|,
name|NetWmStateStaysOnTop
init|=
literal|0x40
block|,
name|NetWmStateDemandsAttention
init|=
literal|0x80
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|NetWmStates
argument_list|,
argument|NetWmState
argument_list|)
name|QXcbWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
expr_stmt|;
operator|~
name|QXcbWindow
argument_list|()
expr_stmt|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QMargins
name|frameMargins
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|setVisible
argument_list|(
name|bool
name|visible
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setWindowFlags
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setWindowState
argument_list|(
name|Qt
operator|::
name|WindowState
name|state
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|WId
name|winId
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|setParent
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|window
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|isExposed
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|bool
name|isEmbedded
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|parentWindow
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPoint
name|mapToGlobal
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPoint
name|mapFromGlobal
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setWindowTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setWindowIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|raise
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|lower
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|propagateSizeHints
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|requestActivateWindow
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|bool
name|setKeyboardGrabEnabled
argument_list|(
name|bool
name|grab
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|setMouseGrabEnabled
argument_list|(
name|bool
name|grab
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setCursor
parameter_list|(
name|xcb_cursor_t
name|cursor
parameter_list|)
function_decl|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|windowEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|startSystemResize
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
name|Qt
operator|::
name|Corner
name|corner
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setOpacity
argument_list|(
name|qreal
name|level
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setMask
argument_list|(
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setAlertState
argument_list|(
name|bool
name|enabled
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|isAlertState
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_alertState
return|;
block|}
name|xcb_window_t
name|xcb_window
argument_list|()
specifier|const
block|{
return|return
name|m_window
return|;
block|}
name|uint
name|depth
argument_list|()
specifier|const
block|{
return|return
name|m_depth
return|;
block|}
name|QImage
operator|::
name|Format
name|imageFormat
argument_list|()
specifier|const
block|{
return|return
name|m_imageFormat
return|;
block|}
name|bool
name|imageNeedsRgbSwap
argument_list|()
specifier|const
block|{
return|return
name|m_imageRgbSwap
return|;
block|}
name|bool
name|handleGenericEvent
argument_list|(
name|xcb_generic_event_t
operator|*
name|event
argument_list|,
name|long
operator|*
name|result
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|handleExposeEvent
argument_list|(
specifier|const
name|xcb_expose_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|handleClientMessageEvent
argument_list|(
specifier|const
name|xcb_client_message_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|handleConfigureNotifyEvent
argument_list|(
specifier|const
name|xcb_configure_notify_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|handleMapNotifyEvent
argument_list|(
specifier|const
name|xcb_map_notify_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|handleUnmapNotifyEvent
argument_list|(
specifier|const
name|xcb_unmap_notify_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|handleButtonPressEvent
argument_list|(
specifier|const
name|xcb_button_press_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|handleButtonReleaseEvent
argument_list|(
specifier|const
name|xcb_button_release_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|handleMotionNotifyEvent
argument_list|(
specifier|const
name|xcb_motion_notify_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|handleEnterNotifyEvent
argument_list|(
specifier|const
name|xcb_enter_notify_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|handleLeaveNotifyEvent
argument_list|(
specifier|const
name|xcb_leave_notify_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|handleFocusInEvent
argument_list|(
specifier|const
name|xcb_focus_in_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|handleFocusOutEvent
argument_list|(
specifier|const
name|xcb_focus_out_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|handlePropertyNotifyEvent
argument_list|(
specifier|const
name|xcb_property_notify_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QXcbWindow
operator|*
name|toWindow
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|handleMouseEvent
argument_list|(
name|xcb_timestamp_t
name|time
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
name|KeyboardModifiers
name|modifiers
argument_list|)
decl_stmt|;
name|void
name|updateNetWmUserTime
parameter_list|(
name|xcb_timestamp_t
name|timestamp
parameter_list|)
function_decl|;
specifier|static
name|void
name|setWmWindowTypeStatic
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|QXcbWindowFunctions
operator|::
name|WmWindowTypes
name|windowTypes
argument_list|)
decl_stmt|;
name|QXcbWindowFunctions
operator|::
name|WmWindowTypes
name|wmWindowTypes
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWmWindowType
argument_list|(
name|QXcbWindowFunctions
operator|::
name|WmWindowTypes
name|types
argument_list|)
decl_stmt|;
name|bool
name|needsSync
argument_list|()
specifier|const
expr_stmt|;
name|void
name|postSyncWindowRequest
parameter_list|()
function_decl|;
name|void
name|clearSyncWindowRequest
parameter_list|()
block|{
name|m_pendingSyncRequest
operator|=
literal|0
expr_stmt|;
block|}
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QXcbScreen
operator|*
name|xcbScreen
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|create
parameter_list|()
function_decl|;
name|virtual
name|void
name|destroy
parameter_list|()
function_decl|;
name|void
name|maybeSetScreen
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|)
function_decl|;
name|QXcbScreen
modifier|*
name|screenForNativeGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|newGeometry
argument_list|)
decl|const
decl_stmt|;
name|public
name|Q_SLOTS
range|:
name|void
name|updateSyncRequestCounter
argument_list|()
decl_stmt|;
name|protected
label|:
name|virtual
name|void
name|resolveFormat
parameter_list|()
block|{
name|m_format
operator|=
name|window
argument_list|()
operator|->
name|requestedFormat
argument_list|()
expr_stmt|;
block|}
name|virtual
name|void
modifier|*
name|createVisual
parameter_list|()
block|{
return|return
name|Q_NULLPTR
return|;
block|}
name|virtual
name|bool
name|supportsSyncProtocol
parameter_list|()
block|{
return|return
operator|!
name|window
argument_list|()
operator|->
name|supportsOpenGL
argument_list|()
return|;
block|}
name|QPoint
name|mapToNative
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
specifier|const
name|QXcbScreen
operator|*
name|screen
argument_list|)
decl|const
decl_stmt|;
name|QPoint
name|mapFromNative
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
specifier|const
name|QXcbScreen
operator|*
name|screen
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|mapToNative
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|,
specifier|const
name|QXcbScreen
operator|*
name|screen
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|mapFromNative
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|,
specifier|const
name|QXcbScreen
operator|*
name|screen
argument_list|)
decl|const
decl_stmt|;
name|QXcbScreen
modifier|*
name|parentScreen
parameter_list|()
function_decl|;
name|void
name|changeNetWmState
parameter_list|(
name|bool
name|set
parameter_list|,
name|xcb_atom_t
name|one
parameter_list|,
name|xcb_atom_t
name|two
init|=
literal|0
parameter_list|)
function_decl|;
name|NetWmStates
name|netWmStates
parameter_list|()
function_decl|;
name|void
name|setNetWmStates
parameter_list|(
name|NetWmStates
parameter_list|)
function_decl|;
name|void
name|setNetWmWindowFlags
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
argument_list|)
decl_stmt|;
name|void
name|setMotifWindowFlags
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
argument_list|)
decl_stmt|;
name|void
name|updateMotifWmHintsBeforeMap
parameter_list|()
function_decl|;
name|void
name|updateNetWmStateBeforeMap
parameter_list|()
function_decl|;
name|void
name|setTransparentForMouseEvents
parameter_list|(
name|bool
name|transparent
parameter_list|)
function_decl|;
name|void
name|updateDoesNotAcceptFocus
parameter_list|(
name|bool
name|doesNotAcceptFocus
parameter_list|)
function_decl|;
name|QRect
name|windowToWmGeometry
argument_list|(
name|QRect
name|r
argument_list|)
decl|const
decl_stmt|;
name|void
name|sendXEmbedMessage
parameter_list|(
name|xcb_window_t
name|window
parameter_list|,
name|quint32
name|message
parameter_list|,
name|quint32
name|detail
init|=
literal|0
parameter_list|,
name|quint32
name|data1
init|=
literal|0
parameter_list|,
name|quint32
name|data2
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|handleXEmbedMessage
parameter_list|(
specifier|const
name|xcb_client_message_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|show
parameter_list|()
function_decl|;
name|void
name|hide
parameter_list|()
function_decl|;
name|bool
name|relayFocusToModalWindow
argument_list|()
specifier|const
expr_stmt|;
name|void
name|doFocusIn
parameter_list|()
function_decl|;
name|void
name|doFocusOut
parameter_list|()
function_decl|;
name|xcb_window_t
name|m_window
decl_stmt|;
name|QXcbScreen
modifier|*
name|m_xcbScreen
decl_stmt|;
name|uint
name|m_depth
decl_stmt|;
name|QImage
operator|::
name|Format
name|m_imageFormat
expr_stmt|;
name|bool
name|m_imageRgbSwap
decl_stmt|;
name|xcb_sync_int64_t
name|m_syncValue
decl_stmt|;
name|xcb_sync_counter_t
name|m_syncCounter
decl_stmt|;
name|Qt
operator|::
name|WindowState
name|m_windowState
expr_stmt|;
name|xcb_gravity_t
name|m_gravity
decl_stmt|;
name|bool
name|m_mapped
decl_stmt|;
name|bool
name|m_transparent
decl_stmt|;
name|bool
name|m_usingSyncProtocol
decl_stmt|;
name|bool
name|m_deferredActivation
decl_stmt|;
name|bool
name|m_deferredExpose
decl_stmt|;
name|bool
name|m_configureNotifyPending
decl_stmt|;
name|bool
name|m_embedded
decl_stmt|;
name|bool
name|m_alertState
decl_stmt|;
name|xcb_window_t
name|m_netWmUserTimeWindow
decl_stmt|;
name|QSurfaceFormat
name|m_format
decl_stmt|;
name|mutable
name|bool
name|m_dirtyFrameMargins
decl_stmt|;
name|mutable
name|QMargins
name|m_frameMargins
decl_stmt|;
name|QRegion
name|m_exposeRegion
decl_stmt|;
name|xcb_visualid_t
name|m_visualId
decl_stmt|;
name|int
name|m_lastWindowStateEvent
decl_stmt|;
enum|enum
name|SyncState
block|{
name|NoSyncNeeded
block|,
name|SyncReceived
block|,
name|SyncAndConfigureReceived
block|}
enum|;
name|SyncState
name|m_syncState
decl_stmt|;
name|QXcbSyncWindowRequest
modifier|*
name|m_pendingSyncRequest
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QXcbWindow
operator|*
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
