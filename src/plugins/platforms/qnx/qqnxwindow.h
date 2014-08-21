begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2013 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXWINDOW_H
end_ifndef
begin_define
DECL|macro|QQNXWINDOW_H
define|#
directive|define
name|QQNXWINDOW_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|"qqnxabstractcover.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
end_if
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<screen/screen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// all surfaces double buffered
DECL|macro|MAX_BUFFER_COUNT
define|#
directive|define
name|MAX_BUFFER_COUNT
value|2
DECL|variable|QQnxScreen
name|class
name|QQnxScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSurfaceFormat
name|class
name|QSurfaceFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QQnxWindow
range|:
name|public
name|QPlatformWindow
block|{
name|friend
name|class
name|QQnxScreen
block|;
name|public
operator|:
name|QQnxWindow
argument_list|(
argument|QWindow *window
argument_list|,
argument|screen_context_t context
argument_list|,
argument|bool needRootWindow
argument_list|)
block|;
name|virtual
operator|~
name|QQnxWindow
argument_list|()
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|setOpacity
argument_list|(
argument|qreal level
argument_list|)
block|;
name|bool
name|isExposed
argument_list|()
specifier|const
block|;
name|WId
name|winId
argument_list|()
specifier|const
block|{
return|return
name|window
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|Qt
operator|::
name|Desktop
operator|?
operator|-
literal|1
operator|:
operator|(
name|WId
operator|)
name|m_window
return|;
block|}
name|screen_window_t
name|nativeHandle
argument_list|()
specifier|const
block|{
return|return
name|m_window
return|;
block|}
name|void
name|setBufferSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|QSize
name|bufferSize
argument_list|()
specifier|const
block|{
return|return
name|m_bufferSize
return|;
block|}
name|void
name|setScreen
argument_list|(
name|QQnxScreen
operator|*
name|platformScreen
argument_list|)
block|;
name|void
name|setParent
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|raise
argument_list|()
block|;
name|void
name|lower
argument_list|()
block|;
name|void
name|requestActivateWindow
argument_list|()
block|;
name|void
name|setWindowState
argument_list|(
argument|Qt::WindowState state
argument_list|)
block|;
name|void
name|setExposed
argument_list|(
argument|bool exposed
argument_list|)
block|;
name|void
name|propagateSizeHints
argument_list|()
block|;
name|void
name|setMMRendererWindowName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|void
name|setMMRendererWindow
argument_list|(
argument|screen_window_t handle
argument_list|)
block|;
name|void
name|clearMMRendererWindow
argument_list|()
block|;
name|QQnxScreen
operator|*
name|screen
argument_list|()
specifier|const
block|{
return|return
name|m_screen
return|;
block|}
specifier|const
name|QList
operator|<
name|QQnxWindow
operator|*
operator|>
operator|&
name|children
argument_list|()
specifier|const
block|{
return|return
name|m_childWindows
return|;
block|}
name|QQnxWindow
operator|*
name|findWindow
argument_list|(
argument|screen_window_t windowHandle
argument_list|)
block|;
name|void
name|minimize
argument_list|()
block|;
name|QString
name|mmRendererWindowName
argument_list|()
specifier|const
block|{
return|return
name|m_mmRendererWindowName
return|;
block|}
name|screen_window_t
name|mmRendererWindow
argument_list|()
specifier|const
block|{
return|return
name|m_mmRendererWindow
return|;
block|}
name|void
name|setRotation
argument_list|(
argument|int rotation
argument_list|)
block|;
name|QByteArray
name|groupName
argument_list|()
specifier|const
block|{
return|return
name|m_windowGroupName
return|;
block|}
name|void
name|joinWindowGroup
argument_list|(
specifier|const
name|QByteArray
operator|&
name|groupName
argument_list|)
block|;
name|bool
name|shouldMakeFullScreen
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|virtual
name|int
name|pixelFormat
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|resetBuffers
argument_list|()
operator|=
literal|0
block|;
name|void
name|initWindow
argument_list|()
block|;
name|void
name|windowPosted
argument_list|()
block|;
name|screen_context_t
name|m_screenContext
block|;
name|private
operator|:
name|void
name|createWindowGroup
argument_list|()
block|;
name|void
name|setGeometryHelper
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|removeFromParent
argument_list|()
block|;
name|void
name|updateVisibility
argument_list|(
argument|bool parentVisible
argument_list|)
block|;
name|void
name|updateZorder
argument_list|(
name|int
operator|&
name|topZorder
argument_list|)
block|;
name|void
name|updateZorder
argument_list|(
argument|screen_window_t window
argument_list|,
argument|int&zOrder
argument_list|)
block|;
name|void
name|applyWindowState
argument_list|()
block|;
name|void
name|setFocus
argument_list|(
argument|screen_window_t newFocusWindow
argument_list|)
block|;
name|screen_window_t
name|m_window
block|;
name|QSize
name|m_bufferSize
block|;
name|QQnxScreen
operator|*
name|m_screen
block|;
name|QQnxWindow
operator|*
name|m_parentWindow
block|;
name|QList
operator|<
name|QQnxWindow
operator|*
operator|>
name|m_childWindows
block|;
name|QScopedPointer
operator|<
name|QQnxAbstractCover
operator|>
name|m_cover
block|;
name|bool
name|m_visible
block|;
name|bool
name|m_exposed
block|;
name|QRect
name|m_unmaximizedGeometry
block|;
name|Qt
operator|::
name|WindowState
name|m_windowState
block|;
name|QString
name|m_mmRendererWindowName
block|;
name|screen_window_t
name|m_mmRendererWindow
block|;
comment|// Group name of window group headed by this window
name|QByteArray
name|m_windowGroupName
block|;
comment|// Group name that we have joined or "" if we've not joined any group.
name|QByteArray
name|m_parentGroupName
block|;
name|bool
name|m_isTopLevel
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QQNXWINDOW_H
end_comment
end_unit
