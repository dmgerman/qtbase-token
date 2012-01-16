begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIRECTFBINPUT_H
end_ifndef
begin_define
DECL|macro|QDIRECTFBINPUT_H
define|#
directive|define
name|QDIRECTFBINPUT_H
end_define
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QPoint>
end_include
begin_include
include|#
directive|include
file|<QEvent>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|"qdirectfbconvenience.h"
end_include
begin_decl_stmt
name|class
name|QDirectFbInput
range|:
name|public
name|QThread
block|{
name|Q_OBJECT
name|public
operator|:
name|QDirectFbInput
argument_list|(
name|IDirectFB
operator|*
name|dfb
argument_list|,
name|IDirectFBDisplayLayer
operator|*
name|dfbLayer
argument_list|)
block|;
name|void
name|addWindow
argument_list|(
name|IDirectFBWindow
operator|*
name|window
argument_list|,
name|QWindow
operator|*
name|platformWindow
argument_list|)
block|;
name|void
name|removeWindow
argument_list|(
name|IDirectFBWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|stopInputEventLoop
argument_list|()
block|;
name|protected
operator|:
name|void
name|run
argument_list|()
block|;
name|private
operator|:
name|void
name|handleEvents
argument_list|()
block|;
name|void
name|handleMouseEvents
argument_list|(
specifier|const
name|DFBEvent
operator|&
name|event
argument_list|)
block|;
name|void
name|handleWheelEvent
argument_list|(
specifier|const
name|DFBEvent
operator|&
name|event
argument_list|)
block|;
name|void
name|handleKeyEvents
argument_list|(
specifier|const
name|DFBEvent
operator|&
name|event
argument_list|)
block|;
name|void
name|handleEnterLeaveEvents
argument_list|(
specifier|const
name|DFBEvent
operator|&
name|event
argument_list|)
block|;
specifier|inline
name|QPoint
name|globalPoint
argument_list|(
argument|const DFBEvent&event
argument_list|)
specifier|const
block|;
name|IDirectFB
operator|*
name|m_dfbInterface
block|;
name|IDirectFBDisplayLayer
operator|*
name|m_dfbDisplayLayer
block|;
name|QDirectFBPointer
operator|<
name|IDirectFBEventBuffer
operator|>
name|m_eventBuffer
block|;
name|bool
name|m_shouldStop
block|;
name|QHash
operator|<
name|DFBWindowID
block|,
name|QWindow
operator|*
operator|>
name|m_tlwMap
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDIRECTFBINPUT_H
end_comment
end_unit
