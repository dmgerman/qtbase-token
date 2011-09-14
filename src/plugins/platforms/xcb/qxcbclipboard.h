begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBCLIPBOARD_H
end_ifndef
begin_define
DECL|macro|QXCBCLIPBOARD_H
define|#
directive|define
name|QXCBCLIPBOARD_H
end_define
begin_include
include|#
directive|include
file|<QPlatformClipboard>
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
file|<xcb/xfixes.h>
end_include
begin_decl_stmt
DECL|variable|QXcbConnection
name|class
name|QXcbConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbScreen
name|class
name|QXcbScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbClipboardMime
name|class
name|QXcbClipboardMime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbObject
name|class
name|QXcbClipboard
range|:
name|public
name|QXcbObject
decl_stmt|,
name|public
name|QPlatformClipboard
block|{
name|public
label|:
name|QXcbClipboard
argument_list|(
name|QXcbConnection
operator|*
name|connection
argument_list|)
expr_stmt|;
operator|~
name|QXcbClipboard
argument_list|()
expr_stmt|;
name|QMimeData
modifier|*
name|mimeData
argument_list|(
name|QClipboard
operator|::
name|Mode
name|mode
argument_list|)
decl_stmt|;
name|void
name|setMimeData
argument_list|(
name|QMimeData
operator|*
name|data
argument_list|,
name|QClipboard
operator|::
name|Mode
name|mode
argument_list|)
decl_stmt|;
name|bool
name|supportsMode
argument_list|(
name|QClipboard
operator|::
name|Mode
name|mode
argument_list|)
decl|const
decl_stmt|;
name|bool
name|ownsMode
argument_list|(
name|QClipboard
operator|::
name|Mode
name|mode
argument_list|)
decl|const
decl_stmt|;
name|QXcbScreen
operator|*
name|screen
argument_list|()
specifier|const
block|{
return|return
name|m_screen
return|;
block|}
name|xcb_window_t
name|requestor
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRequestor
parameter_list|(
name|xcb_window_t
name|window
parameter_list|)
function_decl|;
name|xcb_window_t
name|owner
argument_list|()
specifier|const
expr_stmt|;
name|void
name|handleSelectionRequest
parameter_list|(
name|xcb_selection_request_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleSelectionClearRequest
parameter_list|(
name|xcb_selection_clear_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleXFixesSelectionRequest
parameter_list|(
name|xcb_xfixes_selection_notify_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|bool
name|clipboardReadProperty
argument_list|(
name|xcb_window_t
name|win
argument_list|,
name|xcb_atom_t
name|property
argument_list|,
name|bool
name|deleteProperty
argument_list|,
name|QByteArray
operator|*
name|buffer
argument_list|,
name|int
operator|*
name|size
argument_list|,
name|xcb_atom_t
operator|*
name|type
argument_list|,
name|int
operator|*
name|format
argument_list|)
decl|const
decl_stmt|;
name|QByteArray
name|clipboardReadIncrementalProperty
parameter_list|(
name|xcb_window_t
name|win
parameter_list|,
name|xcb_atom_t
name|property
parameter_list|,
name|int
name|nbytes
parameter_list|,
name|bool
name|nullterm
parameter_list|)
function_decl|;
name|QByteArray
name|getDataInFormat
parameter_list|(
name|xcb_atom_t
name|modeAtom
parameter_list|,
name|xcb_atom_t
name|fmtatom
parameter_list|)
function_decl|;
name|xcb_window_t
name|getSelectionOwner
argument_list|(
name|xcb_atom_t
name|atom
argument_list|)
decl|const
decl_stmt|;
name|QByteArray
name|getSelection
parameter_list|(
name|xcb_atom_t
name|selection
parameter_list|,
name|xcb_atom_t
name|target
parameter_list|,
name|xcb_atom_t
name|property
parameter_list|)
function_decl|;
name|private
label|:
name|xcb_generic_event_t
modifier|*
name|waitForClipboardEvent
parameter_list|(
name|xcb_window_t
name|win
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
name|xcb_atom_t
name|sendTargetsSelection
parameter_list|(
name|QMimeData
modifier|*
name|d
parameter_list|,
name|xcb_window_t
name|window
parameter_list|,
name|xcb_atom_t
name|property
parameter_list|)
function_decl|;
name|xcb_atom_t
name|sendSelection
parameter_list|(
name|QMimeData
modifier|*
name|d
parameter_list|,
name|xcb_atom_t
name|target
parameter_list|,
name|xcb_window_t
name|window
parameter_list|,
name|xcb_atom_t
name|property
parameter_list|)
function_decl|;
name|xcb_atom_t
name|atomForMode
argument_list|(
name|QClipboard
operator|::
name|Mode
name|mode
argument_list|)
decl|const
decl_stmt|;
name|QClipboard
operator|::
name|Mode
name|modeForAtom
argument_list|(
argument|xcb_atom_t atom
argument_list|)
specifier|const
expr_stmt|;
name|QXcbScreen
modifier|*
name|m_screen
decl_stmt|;
comment|// Selection and Clipboard
name|QXcbClipboardMime
modifier|*
name|m_xClipboard
index|[
literal|2
index|]
decl_stmt|;
name|QMimeData
modifier|*
name|m_clientClipboard
index|[
literal|2
index|]
decl_stmt|;
name|xcb_timestamp_t
name|m_timestamp
index|[
literal|2
index|]
decl_stmt|;
name|xcb_window_t
name|m_requestor
decl_stmt|;
name|xcb_window_t
name|m_owner
decl_stmt|;
specifier|static
specifier|const
name|int
name|clipboard_timeout
decl_stmt|;
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
comment|// QXCBCLIPBOARD_H
end_comment
end_unit
