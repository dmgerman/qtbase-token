begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBSCREEN_H
end_ifndef
begin_define
DECL|macro|QXCBSCREEN_H
define|#
directive|define
name|QXCBSCREEN_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QPlatformScreen>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_include
include|#
directive|include
file|"qxcbobject.h"
end_include
begin_decl_stmt
DECL|variable|QXcbConnection
name|class
name|QXcbConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbCursor
name|class
name|QXcbCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbObject
name|class
name|QXcbScreen
range|:
name|public
name|QXcbObject
decl_stmt|,
name|public
name|QPlatformScreen
block|{
name|public
label|:
name|QXcbScreen
argument_list|(
argument|QXcbConnection *connection
argument_list|,
argument|xcb_screen_t *screen
argument_list|,
argument|int number
argument_list|)
empty_stmt|;
operator|~
name|QXcbScreen
argument_list|()
expr_stmt|;
name|QWindow
modifier|*
name|topLevelAt
argument_list|(
specifier|const
name|QPoint
operator|&
name|point
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|geometry
argument_list|()
specifier|const
expr_stmt|;
name|int
name|depth
argument_list|()
specifier|const
expr_stmt|;
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|physicalSize
argument_list|()
specifier|const
expr_stmt|;
name|int
name|screenNumber
argument_list|()
specifier|const
expr_stmt|;
name|xcb_screen_t
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
name|root
argument_list|()
specifier|const
block|{
return|return
name|m_screen
operator|->
name|root
return|;
block|}
name|xcb_window_t
name|clientLeader
argument_list|()
specifier|const
block|{
return|return
name|m_clientLeader
return|;
block|}
name|QString
name|windowManagerName
argument_list|()
specifier|const
block|{
return|return
name|m_windowManagerName
return|;
block|}
name|bool
name|syncRequestSupported
argument_list|()
specifier|const
block|{
return|return
name|m_syncRequestSupported
return|;
block|}
specifier|const
name|xcb_visualtype_t
modifier|*
name|visualForId
argument_list|(
name|xcb_visualid_t
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|xcb_screen_t
modifier|*
name|m_screen
decl_stmt|;
name|int
name|m_number
decl_stmt|;
name|QString
name|m_windowManagerName
decl_stmt|;
name|bool
name|m_syncRequestSupported
decl_stmt|;
name|xcb_window_t
name|m_clientLeader
decl_stmt|;
name|QMap
operator|<
name|xcb_visualid_t
operator|,
name|xcb_visualtype_t
operator|>
name|m_visuals
expr_stmt|;
name|QXcbCursor
modifier|*
name|m_cursor
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
end_unit
