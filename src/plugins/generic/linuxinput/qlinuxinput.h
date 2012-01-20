begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLINUXINPUT_H
end_ifndef
begin_define
DECL|macro|QLINUXINPUT_H
define|#
directive|define
name|QLINUXINPUT_H
end_define
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<Qt>
end_include
begin_include
include|#
directive|include
file|<termios.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLinuxInputMouseHandlerData
name|class
name|QLinuxInputMouseHandlerData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QLinuxInputMouseHandler
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QLinuxInputMouseHandler
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
specifier|const
name|QString
operator|&
name|specification
argument_list|)
block|;
operator|~
name|QLinuxInputMouseHandler
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|readMouseData
argument_list|()
block|;
name|private
operator|:
name|void
name|sendMouseEvent
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|Qt::MouseButtons buttons
argument_list|)
block|;
name|QSocketNotifier
operator|*
name|m_notify
block|;
name|int
name|m_fd
block|;
name|int
name|m_x
block|,
name|m_y
block|;
name|int
name|m_prevx
block|,
name|m_prevy
block|;
name|int
name|m_xoffset
block|,
name|m_yoffset
block|;
name|int
name|m_smoothx
block|,
name|m_smoothy
block|;
name|Qt
operator|::
name|MouseButtons
name|m_buttons
block|;
name|bool
name|m_compression
block|;
name|bool
name|m_smooth
block|;
name|int
name|m_jitterLimitSquared
block|;
name|QLinuxInputMouseHandlerData
operator|*
name|d
block|; }
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
comment|// QLINUXINPUT_H
end_comment
end_unit
