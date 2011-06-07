begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<xcb/xcb.h>
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
name|class
name|QXcbClipboard
range|:
name|public
name|QPlatformClipboard
block|{
name|public
operator|:
name|QXcbClipboard
argument_list|(
name|QXcbConnection
operator|*
name|connection
argument_list|)
block|;
name|QMimeData
operator|*
name|mimeData
argument_list|(
argument|QClipboard::Mode mode
argument_list|)
block|;
name|void
name|setMimeData
argument_list|(
argument|QMimeData *data
argument_list|,
argument|QClipboard::Mode mode
argument_list|)
block|;
name|bool
name|supportsMode
argument_list|(
argument|QClipboard::Mode mode
argument_list|)
specifier|const
block|;
name|QXcbConnection
operator|*
name|connection
argument_list|()
specifier|const
block|{
return|return
name|m_connection
return|;
block|}
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
block|;
name|void
name|setRequestor
argument_list|(
argument|xcb_window_t window
argument_list|)
block|;
name|xcb_window_t
name|owner
argument_list|()
specifier|const
block|;
name|void
name|handleSelectionRequest
argument_list|(
name|xcb_selection_request_event_t
operator|*
name|event
argument_list|)
block|;
name|bool
name|clipboardReadProperty
argument_list|(
argument|xcb_window_t win
argument_list|,
argument|xcb_atom_t property
argument_list|,
argument|bool deleteProperty
argument_list|,
argument|QByteArray *buffer
argument_list|,
argument|int *size
argument_list|,
argument|xcb_atom_t *type
argument_list|,
argument|int *format
argument_list|)
specifier|const
block|;
name|QByteArray
name|clipboardReadIncrementalProperty
argument_list|(
argument|xcb_window_t win
argument_list|,
argument|xcb_atom_t property
argument_list|,
argument|int nbytes
argument_list|,
argument|bool nullterm
argument_list|)
block|;
name|QByteArray
name|getDataInFormat
argument_list|(
argument|xcb_atom_t modeAtom
argument_list|,
argument|xcb_atom_t fmtatom
argument_list|)
block|;
name|xcb_window_t
name|getSelectionOwner
argument_list|(
argument|xcb_atom_t atom
argument_list|)
specifier|const
block|;
name|QByteArray
name|getSelection
argument_list|(
argument|xcb_atom_t selection
argument_list|,
argument|xcb_atom_t target
argument_list|,
argument|xcb_atom_t property
argument_list|)
block|;
name|private
operator|:
name|void
name|setOwner
argument_list|(
argument|xcb_window_t window
argument_list|)
block|;
name|xcb_generic_event_t
operator|*
name|waitForClipboardEvent
argument_list|(
argument|xcb_window_t win
argument_list|,
argument|int type
argument_list|,
argument|int timeout
argument_list|)
block|;
name|xcb_atom_t
name|sendTargetsSelection
argument_list|(
argument|QMimeData *d
argument_list|,
argument|xcb_window_t window
argument_list|,
argument|xcb_atom_t property
argument_list|)
block|;
name|xcb_atom_t
name|sendSelection
argument_list|(
argument|QMimeData *d
argument_list|,
argument|xcb_atom_t target
argument_list|,
argument|xcb_window_t window
argument_list|,
argument|xcb_atom_t property
argument_list|)
block|;
name|QXcbConnection
operator|*
name|m_connection
block|;
name|QXcbScreen
operator|*
name|m_screen
block|;
name|QMimeData
operator|*
name|m_xClipboard
block|;
name|QMimeData
operator|*
name|m_clientClipboard
block|;
name|QMimeData
operator|*
name|m_xSelection
block|;
name|QMimeData
operator|*
name|m_clientSelection
block|;
name|xcb_window_t
name|m_requestor
block|;
name|xcb_window_t
name|m_owner
block|;
specifier|static
specifier|const
name|int
name|clipboard_timeout
block|;  }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QXCBCLIPBOARD_H
end_comment
end_unit
