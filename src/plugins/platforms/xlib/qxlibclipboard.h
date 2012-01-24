begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTLITECLIPBOARD_H
end_ifndef
begin_define
DECL|macro|QTESTLITECLIPBOARD_H
define|#
directive|define
name|QTESTLITECLIPBOARD_H
end_define
begin_include
include|#
directive|include
file|<QPlatformClipboard>
end_include
begin_include
include|#
directive|include
file|"qxlibstatic.h"
end_include
begin_decl_stmt
DECL|variable|QXlibScreen
name|class
name|QXlibScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QXlibClipboard
range|:
name|public
name|QPlatformClipboard
block|{
name|public
operator|:
name|QXlibClipboard
argument_list|(
name|QXlibScreen
operator|*
name|screen
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
name|QXlibScreen
operator|*
name|screen
argument_list|()
specifier|const
block|;
name|Window
name|requestor
argument_list|()
specifier|const
block|;
name|void
name|setRequestor
argument_list|(
argument|Window window
argument_list|)
block|;
name|Window
name|owner
argument_list|()
specifier|const
block|;
name|void
name|handleSelectionRequest
argument_list|(
name|XEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|clipboardReadProperty
argument_list|(
argument|Window win
argument_list|,
argument|Atom property
argument_list|,
argument|bool deleteProperty
argument_list|,
argument|QByteArray *buffer
argument_list|,
argument|int *size
argument_list|,
argument|Atom *type
argument_list|,
argument|int *format
argument_list|)
specifier|const
block|;
name|QByteArray
name|clipboardReadIncrementalProperty
argument_list|(
argument|Window win
argument_list|,
argument|Atom property
argument_list|,
argument|int nbytes
argument_list|,
argument|bool nullterm
argument_list|)
block|;
name|QByteArray
name|getDataInFormat
argument_list|(
argument|Atom modeAtom
argument_list|,
argument|Atom fmtatom
argument_list|)
block|;
name|private
operator|:
name|void
name|setOwner
argument_list|(
argument|Window window
argument_list|)
block|;
name|Atom
name|sendTargetsSelection
argument_list|(
argument|QMimeData *d
argument_list|,
argument|Window window
argument_list|,
argument|Atom property
argument_list|)
block|;
name|Atom
name|sendSelection
argument_list|(
argument|QMimeData *d
argument_list|,
argument|Atom target
argument_list|,
argument|Window window
argument_list|,
argument|Atom property
argument_list|)
block|;
name|QXlibScreen
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
name|Window
name|m_requestor
block|;
name|Window
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
comment|// QTESTLITECLIPBOARD_H
end_comment
end_unit
