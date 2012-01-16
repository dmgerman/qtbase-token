begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBDRAG_H
end_ifndef
begin_define
DECL|macro|QXCBDRAG_H
define|#
directive|define
name|QXCBDRAG_H
end_define
begin_include
include|#
directive|include
file|<qplatformdrag_qpa.h>
end_include
begin_include
include|#
directive|include
file|<qxcbobject.h>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qpoint.h>
end_include
begin_include
include|#
directive|include
file|<qrect.h>
end_include
begin_include
include|#
directive|include
file|<qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<qvector.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMouseEvent
name|class
name|QMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbConnection
name|class
name|QXcbConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbWindow
name|class
name|QXcbWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDropData
name|class
name|QDropData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbScreen
name|class
name|QXcbScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDrag
name|class
name|QDrag
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
DECL|variable|QXcbObject
name|class
name|QXcbDrag
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QXcbObject
decl_stmt|,
name|public
name|QPlatformDrag
block|{
name|public
label|:
name|QXcbDrag
argument_list|(
name|QXcbConnection
operator|*
name|c
argument_list|)
expr_stmt|;
operator|~
name|QXcbDrag
argument_list|()
expr_stmt|;
name|virtual
name|QMimeData
modifier|*
name|platformDropData
parameter_list|()
function_decl|;
comment|//    virtual Qt::DropAction drag(QDrag *);
name|virtual
name|void
name|startDrag
parameter_list|()
function_decl|;
name|virtual
name|void
name|cancel
parameter_list|()
function_decl|;
name|virtual
name|void
name|move
parameter_list|(
specifier|const
name|QMouseEvent
modifier|*
name|me
parameter_list|)
function_decl|;
name|virtual
name|void
name|drop
parameter_list|(
specifier|const
name|QMouseEvent
modifier|*
name|me
parameter_list|)
function_decl|;
name|void
name|endDrag
parameter_list|()
function_decl|;
name|void
name|handleEnter
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|xcb_client_message_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handlePosition
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|xcb_client_message_event_t
modifier|*
name|event
parameter_list|,
name|bool
name|passive
parameter_list|)
function_decl|;
name|void
name|handleLeave
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|xcb_client_message_event_t
modifier|*
name|event
parameter_list|,
name|bool
comment|/*passive*/
parameter_list|)
function_decl|;
name|void
name|handleDrop
parameter_list|(
name|QWindow
modifier|*
parameter_list|,
specifier|const
name|xcb_client_message_event_t
modifier|*
name|event
parameter_list|,
name|bool
name|passive
parameter_list|)
function_decl|;
name|void
name|handleStatus
parameter_list|(
specifier|const
name|xcb_client_message_event_t
modifier|*
name|event
parameter_list|,
name|bool
name|passive
parameter_list|)
function_decl|;
name|void
name|handleSelectionRequest
parameter_list|(
specifier|const
name|xcb_selection_request_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleFinished
parameter_list|(
specifier|const
name|xcb_client_message_event_t
modifier|*
name|event
parameter_list|,
name|bool
name|passive
parameter_list|)
function_decl|;
name|bool
name|dndEnable
parameter_list|(
name|QXcbWindow
modifier|*
name|win
parameter_list|,
name|bool
name|on
parameter_list|)
function_decl|;
name|protected
label|:
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|e
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|QDropData
decl_stmt|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|handle_xdnd_position
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|xcb_client_message_event_t
modifier|*
name|event
parameter_list|,
name|bool
name|passive
parameter_list|)
function_decl|;
name|void
name|handle_xdnd_status
parameter_list|(
specifier|const
name|xcb_client_message_event_t
modifier|*
name|event
parameter_list|,
name|bool
parameter_list|)
function_decl|;
name|void
name|send_leave
parameter_list|()
function_decl|;
name|Qt
operator|::
name|DropAction
name|toDropAction
argument_list|(
argument|xcb_atom_t atom
argument_list|)
specifier|const
expr_stmt|;
name|xcb_atom_t
name|toXdndAction
argument_list|(
name|Qt
operator|::
name|DropAction
name|a
argument_list|)
decl|const
decl_stmt|;
name|QWeakPointer
operator|<
name|QWindow
operator|>
name|currentWindow
expr_stmt|;
name|QPoint
name|currentPosition
decl_stmt|;
name|QDropData
modifier|*
name|dropData
decl_stmt|;
name|QWindow
modifier|*
name|desktop_proxy
decl_stmt|;
name|xcb_atom_t
name|xdnd_dragsource
decl_stmt|;
comment|// the types in this drop. 100 is no good, but at least it's big.
enum|enum
block|{
name|xdnd_max_type
init|=
literal|100
block|}
enum|;
name|QList
operator|<
name|xcb_atom_t
operator|>
name|xdnd_types
expr_stmt|;
name|xcb_timestamp_t
name|target_time
decl_stmt|;
name|xcb_timestamp_t
name|source_time
decl_stmt|;
name|Qt
operator|::
name|DropAction
name|last_target_accepted_action
expr_stmt|;
comment|// rectangle in which the answer will be the same
name|QRect
name|source_sameanswer
decl_stmt|;
name|bool
name|waiting_for_status
decl_stmt|;
comment|// top-level window we sent position to last.
name|xcb_window_t
name|current_target
decl_stmt|;
comment|// window to send events to (always valid if current_target)
name|xcb_window_t
name|current_proxy_target
decl_stmt|;
name|QXcbScreen
modifier|*
name|current_screen
decl_stmt|;
name|int
name|heartbeat
decl_stmt|;
name|bool
name|xdnd_dragging
decl_stmt|;
name|QVector
operator|<
name|xcb_atom_t
operator|>
name|drag_types
expr_stmt|;
struct|struct
name|Transaction
block|{
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
name|xcb_window_t
name|target
decl_stmt|;
name|xcb_window_t
name|proxy_target
decl_stmt|;
name|QWindow
modifier|*
name|targetWindow
decl_stmt|;
comment|//        QWidget *embedding_widget;
name|QDrag
modifier|*
name|object
decl_stmt|;
block|}
struct|;
name|QList
operator|<
name|Transaction
operator|>
name|transactions
expr_stmt|;
name|int
name|transaction_expiry_timer
decl_stmt|;
name|void
name|restartDropExpiryTimer
parameter_list|()
function_decl|;
name|int
name|findTransactionByWindow
parameter_list|(
name|xcb_window_t
name|window
parameter_list|)
function_decl|;
name|int
name|findTransactionByTime
parameter_list|(
name|xcb_timestamp_t
name|timestamp
parameter_list|)
function_decl|;
name|xcb_window_t
name|findRealWindow
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
name|xcb_window_t
name|w
parameter_list|,
name|int
name|md
parameter_list|)
function_decl|;
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
end_unit
