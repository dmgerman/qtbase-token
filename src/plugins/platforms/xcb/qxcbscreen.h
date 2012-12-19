begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qpa/qplatformscreen.h>
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
file|<xcb/randr.h>
end_include
begin_include
include|#
directive|include
file|"qxcbobject.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
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
argument|xcb_randr_get_output_info_reply_t *output
argument_list|,
argument|QString outputName
argument_list|,
argument|int number
argument_list|)
empty_stmt|;
operator|~
name|QXcbScreen
argument_list|()
expr_stmt|;
name|QPixmap
name|grabWindow
argument_list|(
name|WId
name|window
argument_list|,
name|int
name|x
argument_list|,
name|int
name|y
argument_list|,
name|int
name|width
argument_list|,
name|int
name|height
argument_list|)
decl|const
decl_stmt|;
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
block|{
return|return
name|m_geometry
return|;
block|}
name|QRect
name|availableGeometry
argument_list|()
specifier|const
block|{
return|return
name|m_availableGeometry
return|;
block|}
name|int
name|depth
argument_list|()
specifier|const
block|{
return|return
name|m_screen
operator|->
name|root_depth
return|;
block|}
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
expr_stmt|;
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
block|{
return|return
name|m_sizeMillimeters
return|;
block|}
name|QDpi
name|logicalDpi
argument_list|()
specifier|const
expr_stmt|;
name|QPlatformCursor
operator|*
name|cursor
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|refreshRate
argument_list|()
specifier|const
block|{
return|return
name|m_refreshRate
return|;
block|}
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
block|{
return|return
name|m_orientation
return|;
block|}
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|virtualSiblings
argument_list|()
specifier|const
block|{
return|return
name|m_siblings
return|;
block|}
name|void
name|setVirtualSiblings
argument_list|(
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|sl
argument_list|)
block|{
name|m_siblings
operator|=
name|sl
expr_stmt|;
block|}
name|int
name|screenNumber
argument_list|()
specifier|const
block|{
return|return
name|m_number
return|;
block|}
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
name|QString
name|name
argument_list|()
specifier|const
block|{
return|return
name|m_outputName
return|;
block|}
name|void
name|handleScreenChange
parameter_list|(
name|xcb_randr_screen_change_notify_event_t
modifier|*
name|change_event
parameter_list|)
function_decl|;
name|void
name|updateGeometry
parameter_list|(
name|xcb_timestamp_t
name|timestamp
parameter_list|)
function_decl|;
name|void
name|updateRefreshRate
parameter_list|()
function_decl|;
name|void
name|readXResources
parameter_list|()
function_decl|;
name|private
label|:
name|xcb_screen_t
modifier|*
name|m_screen
decl_stmt|;
name|xcb_randr_crtc_t
name|m_crtc
decl_stmt|;
name|QString
name|m_outputName
decl_stmt|;
name|QSizeF
name|m_sizeMillimeters
decl_stmt|;
name|QRect
name|m_geometry
decl_stmt|;
name|QRect
name|m_availableGeometry
decl_stmt|;
name|QSize
name|m_virtualSize
decl_stmt|;
name|QSizeF
name|m_virtualSizeMillimeters
decl_stmt|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|m_siblings
expr_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|m_orientation
expr_stmt|;
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
name|int
name|m_refreshRate
decl_stmt|;
name|int
name|m_forcedDpi
decl_stmt|;
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
