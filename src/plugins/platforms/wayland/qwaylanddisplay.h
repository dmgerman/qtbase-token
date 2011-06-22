begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWAYLANDDISPLAY_H
end_ifndef
begin_define
DECL|macro|QWAYLANDDISPLAY_H
define|#
directive|define
name|QWAYLANDDISPLAY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRect>
end_include
begin_include
include|#
directive|include
file|<QtCore/QWaitCondition>
end_include
begin_include
include|#
directive|include
file|<wayland-client.h>
end_include
begin_decl_stmt
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWaylandInputDevice
name|class
name|QWaylandInputDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWaylandBuffer
name|class
name|QWaylandBuffer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformScreen
name|class
name|QPlatformScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWaylandScreen
name|class
name|QWaylandScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWaylandGLIntegration
name|class
name|QWaylandGLIntegration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWaylandWindowManagerIntegration
name|class
name|QWaylandWindowManagerIntegration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWaylandDisplay
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QWaylandDisplay
argument_list|(
name|void
argument_list|)
block|;
operator|~
name|QWaylandDisplay
argument_list|(
name|void
argument_list|)
block|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|screens
argument_list|()
specifier|const
block|{
return|return
name|mScreens
return|;
block|}
expr|struct
name|wl_surface
operator|*
name|createSurface
argument_list|(
name|void
operator|*
name|handle
argument_list|)
block|;     struct
name|wl_buffer
operator|*
name|createShmBuffer
argument_list|(
argument|int fd
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|uint32_t stride
argument_list|,
argument|struct wl_visual *visual
argument_list|)
block|;     struct
name|wl_visual
operator|*
name|rgbVisual
argument_list|()
block|;     struct
name|wl_visual
operator|*
name|argbVisual
argument_list|()
block|;     struct
name|wl_visual
operator|*
name|argbPremultipliedVisual
argument_list|()
block|;
ifdef|#
directive|ifdef
name|QT_WAYLAND_GL_SUPPORT
name|QWaylandGLIntegration
operator|*
name|eglIntegration
argument_list|()
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_WAYLAND_WINDOWMANAGER_SUPPORT
name|QWaylandWindowManagerIntegration
operator|*
name|windowManagerIntegration
argument_list|()
block|;
endif|#
directive|endif
name|void
name|setCursor
argument_list|(
argument|QWaylandBuffer *buffer
argument_list|,
argument|int32_t x
argument_list|,
argument|int32_t y
argument_list|)
block|;
name|void
name|syncCallback
argument_list|(
argument|wl_display_sync_func_t func
argument_list|,
argument|void *data
argument_list|)
block|;
name|void
name|frameCallback
argument_list|(
argument|wl_display_frame_func_t func
argument_list|,
argument|struct wl_surface *surface
argument_list|,
argument|void *data
argument_list|)
block|;      struct
name|wl_display
operator|*
name|wl_display
argument_list|()
specifier|const
block|{
return|return
name|mDisplay
return|;
block|}
expr|struct
name|wl_shell
operator|*
name|wl_shell
argument_list|()
specifier|const
block|{
return|return
name|mShell
return|;
block|}
name|QList
operator|<
name|QWaylandInputDevice
operator|*
operator|>
name|inputDevices
argument_list|()
specifier|const
block|{
return|return
name|mInputDevices
return|;
block|}
name|void
name|eventDispatcherCreated
argument_list|(
name|QAbstractEventDispatcher
operator|*
name|dispatcher
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|createNewScreen
argument_list|(
argument|struct wl_output *output
argument_list|,
argument|QRect geometry
argument_list|)
block|;
name|void
name|readEvents
argument_list|()
block|;
name|void
name|blockingReadEvents
argument_list|()
block|;
name|void
name|flushRequests
argument_list|()
block|;
name|private
operator|:
name|void
name|waitForScreens
argument_list|()
block|;
name|void
name|displayHandleGlobal
argument_list|(
argument|uint32_t id
argument_list|,
argument|const QByteArray&interface
argument_list|,
argument|uint32_t version
argument_list|)
block|;      struct
name|wl_display
operator|*
name|mDisplay
block|;     struct
name|wl_compositor
operator|*
name|mCompositor
block|;     struct
name|wl_shm
operator|*
name|mShm
block|;     struct
name|wl_shell
operator|*
name|mShell
block|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|mScreens
block|;
name|QList
operator|<
name|QWaylandInputDevice
operator|*
operator|>
name|mInputDevices
block|;
name|QSocketNotifier
operator|*
name|mReadNotifier
block|;
name|int
name|mFd
block|;
name|bool
name|mScreensInitialized
block|;
name|uint32_t
name|mSocketMask
block|;      struct
name|wl_visual
operator|*
name|argb_visual
block|,
operator|*
name|premultiplied_argb_visual
block|,
operator|*
name|rgb_visual
block|;
specifier|static
specifier|const
expr|struct
name|wl_output_listener
name|outputListener
block|;
specifier|static
specifier|const
expr|struct
name|wl_compositor_listener
name|compositorListener
block|;
specifier|static
name|int
name|sourceUpdate
argument_list|(
argument|uint32_t mask
argument_list|,
argument|void *data
argument_list|)
block|;
specifier|static
name|void
name|displayHandleGlobal
argument_list|(
argument|struct wl_display *display
argument_list|,
argument|uint32_t id
argument_list|,
argument|const char *interface
argument_list|,
argument|uint32_t version
argument_list|,
argument|void *data
argument_list|)
block|;
specifier|static
name|void
name|outputHandleGeometry
argument_list|(
argument|void *data
argument_list|,
argument|struct wl_output *output
argument_list|,
argument|int32_t x
argument_list|,
argument|int32_t y
argument_list|,
argument|int32_t width
argument_list|,
argument|int32_t height
argument_list|)
block|;
specifier|static
name|void
name|handleVisual
argument_list|(
argument|void *data
argument_list|,
argument|struct wl_compositor *compositor
argument_list|,
argument|uint32_t id
argument_list|,
argument|uint32_t token
argument_list|)
block|;
ifdef|#
directive|ifdef
name|QT_WAYLAND_GL_SUPPORT
name|QWaylandGLIntegration
operator|*
name|mEglIntegration
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_WAYLAND_WINDOWMANAGER_SUPPORT
name|QWaylandWindowManagerIntegration
operator|*
name|mWindowManagerIntegration
block|;
endif|#
directive|endif
specifier|static
name|void
name|shellHandleConfigure
argument_list|(
argument|void *data
argument_list|,
argument|struct wl_shell *shell
argument_list|,
argument|uint32_t time
argument_list|,
argument|uint32_t edges
argument_list|,
argument|struct wl_surface *surface
argument_list|,
argument|int32_t width
argument_list|,
argument|int32_t height
argument_list|)
block|;
specifier|static
specifier|const
expr|struct
name|wl_shell_listener
name|shellListener
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWAYLANDDISPLAY_H
end_comment
end_unit
