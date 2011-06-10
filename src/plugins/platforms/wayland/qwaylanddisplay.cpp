begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylanddisplay.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandscreen.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandcursor.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandinputdevice.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandclipboard.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WAYLAND_GL_SUPPORT
end_ifdef
begin_include
include|#
directive|include
file|"gl_integration/qwaylandglintegration.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WAYLAND_WINDOWMANAGER_SUPPORT
end_ifdef
begin_include
include|#
directive|include
file|"windowmanager_integration/qwaylandwindowmanagerintegration.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/QAbstractEventDispatcher>
end_include
begin_include
include|#
directive|include
file|<QtGui/QApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_function
DECL|function|createSurface
name|struct
name|wl_surface
modifier|*
name|QWaylandDisplay
operator|::
name|createSurface
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|struct
name|wl_surface
modifier|*
name|surface
init|=
name|wl_compositor_create_surface
argument_list|(
name|mCompositor
argument_list|)
decl_stmt|;
name|wl_surface_set_user_data
argument_list|(
name|surface
argument_list|,
name|handle
argument_list|)
expr_stmt|;
return|return
name|surface
return|;
block|}
end_function
begin_function
DECL|function|createShmBuffer
name|struct
name|wl_buffer
modifier|*
name|QWaylandDisplay
operator|::
name|createShmBuffer
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|uint32_t
name|stride
parameter_list|,
name|struct
name|wl_visual
modifier|*
name|visual
parameter_list|)
block|{
return|return
name|wl_shm_create_buffer
argument_list|(
name|mShm
argument_list|,
name|fd
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|stride
argument_list|,
name|visual
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|rgbVisual
name|struct
name|wl_visual
modifier|*
name|QWaylandDisplay
operator|::
name|rgbVisual
parameter_list|()
block|{
return|return
name|rgb_visual
return|;
block|}
end_function
begin_function
DECL|function|argbVisual
name|struct
name|wl_visual
modifier|*
name|QWaylandDisplay
operator|::
name|argbVisual
parameter_list|()
block|{
return|return
name|argb_visual
return|;
block|}
end_function
begin_function
DECL|function|argbPremultipliedVisual
name|struct
name|wl_visual
modifier|*
name|QWaylandDisplay
operator|::
name|argbPremultipliedVisual
parameter_list|()
block|{
return|return
name|premultiplied_argb_visual
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WAYLAND_GL_SUPPORT
end_ifdef
begin_function
DECL|function|eglIntegration
name|QWaylandGLIntegration
modifier|*
name|QWaylandDisplay
operator|::
name|eglIntegration
parameter_list|()
block|{
return|return
name|mEglIntegration
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WAYLAND_WINDOWMANAGER_SUPPORT
end_ifdef
begin_function
DECL|function|windowManagerIntegration
name|QWaylandWindowManagerIntegration
modifier|*
name|QWaylandDisplay
operator|::
name|windowManagerIntegration
parameter_list|()
block|{
return|return
name|mWindowManagerIntegration
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|shellHandleConfigure
name|void
name|QWaylandDisplay
operator|::
name|shellHandleConfigure
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_shell
modifier|*
name|shell
parameter_list|,
name|uint32_t
name|time
parameter_list|,
name|uint32_t
name|edges
parameter_list|,
name|struct
name|wl_surface
modifier|*
name|surface
parameter_list|,
name|int32_t
name|width
parameter_list|,
name|int32_t
name|height
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|shell
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|time
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|edges
argument_list|)
expr_stmt|;
name|QWaylandWindow
modifier|*
name|ww
init|=
operator|(
name|QWaylandWindow
operator|*
operator|)
name|wl_surface_get_user_data
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|ww
operator|->
name|configure
argument_list|(
name|time
argument_list|,
name|edges
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|member|shellListener
specifier|const
name|struct
name|wl_shell_listener
name|QWaylandDisplay
operator|::
name|shellListener
init|=
block|{
name|QWaylandDisplay
operator|::
name|shellHandleConfigure
block|, }
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QWaylandDisplay
name|QWaylandDisplay
operator|::
name|QWaylandDisplay
parameter_list|(
name|void
parameter_list|)
member_init_list|:
name|argb_visual
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|premultiplied_argb_visual
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|rgb_visual
argument_list|(
literal|0
argument_list|)
block|{
name|qRegisterMetaType
argument_list|<
name|uint32_t
argument_list|>
argument_list|(
literal|"uint32_t"
argument_list|)
expr_stmt|;
name|mDisplay
operator|=
name|wl_display_connect
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|mDisplay
operator|==
name|NULL
condition|)
block|{
name|qErrnoWarning
argument_list|(
name|errno
argument_list|,
literal|"Failed to create display"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"No wayland connection available."
argument_list|)
expr_stmt|;
block|}
name|wl_display_add_global_listener
argument_list|(
name|mDisplay
argument_list|,
name|QWaylandDisplay
operator|::
name|displayHandleGlobal
argument_list|,
name|this
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_WAYLAND_GL_SUPPORT
name|mEglIntegration
operator|=
name|QWaylandGLIntegration
operator|::
name|createGLIntegration
argument_list|(
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_WAYLAND_WINDOWMANAGER_SUPPORT
name|mWindowManagerIntegration
operator|=
name|QWaylandWindowManagerIntegration
operator|::
name|createIntegration
argument_list|(
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|blockingReadEvents
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_WAYLAND_GL_SUPPORT
name|mEglIntegration
operator|->
name|initialize
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|connect
argument_list|(
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|aboutToBlock
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|flushRequests
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|mFd
operator|=
name|wl_display_get_fd
argument_list|(
name|mDisplay
argument_list|,
name|sourceUpdate
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|mReadNotifier
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|mFd
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|mReadNotifier
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readEvents
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|waitForScreens
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandDisplay
name|QWaylandDisplay
operator|::
name|~
name|QWaylandDisplay
parameter_list|(
name|void
parameter_list|)
block|{
name|close
argument_list|(
name|mFd
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_WAYLAND_GL_SUPPORT
operator|delete
name|mEglIntegration
expr_stmt|;
endif|#
directive|endif
name|wl_display_destroy
argument_list|(
name|mDisplay
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|createNewScreen
name|void
name|QWaylandDisplay
operator|::
name|createNewScreen
parameter_list|(
name|struct
name|wl_output
modifier|*
name|output
parameter_list|,
name|QRect
name|geometry
parameter_list|)
block|{
name|QWaylandScreen
modifier|*
name|waylandScreen
init|=
operator|new
name|QWaylandScreen
argument_list|(
name|this
argument_list|,
name|output
argument_list|,
name|geometry
argument_list|)
decl_stmt|;
name|mScreens
operator|.
name|append
argument_list|(
name|waylandScreen
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|syncCallback
name|void
name|QWaylandDisplay
operator|::
name|syncCallback
parameter_list|(
name|wl_display_sync_func_t
name|func
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|wl_display_sync_callback
argument_list|(
name|mDisplay
argument_list|,
name|func
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|frameCallback
name|void
name|QWaylandDisplay
operator|::
name|frameCallback
parameter_list|(
name|wl_display_frame_func_t
name|func
parameter_list|,
name|struct
name|wl_surface
modifier|*
name|surface
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|wl_display_frame_callback
argument_list|(
name|mDisplay
argument_list|,
name|surface
argument_list|,
name|func
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|flushRequests
name|void
name|QWaylandDisplay
operator|::
name|flushRequests
parameter_list|()
block|{
if|if
condition|(
name|mSocketMask
operator|&
name|WL_DISPLAY_WRITABLE
condition|)
name|wl_display_iterate
argument_list|(
name|mDisplay
argument_list|,
name|WL_DISPLAY_WRITABLE
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readEvents
name|void
name|QWaylandDisplay
operator|::
name|readEvents
parameter_list|()
block|{
comment|// verify that there is still data on the socket
name|fd_set
name|fds
decl_stmt|;
name|FD_ZERO
argument_list|(
operator|&
name|fds
argument_list|)
expr_stmt|;
name|FD_SET
argument_list|(
name|mFd
argument_list|,
operator|&
name|fds
argument_list|)
expr_stmt|;
name|fd_set
name|nds
decl_stmt|;
name|FD_ZERO
argument_list|(
operator|&
name|nds
argument_list|)
expr_stmt|;
name|fd_set
name|rs
init|=
name|fds
decl_stmt|;
name|fd_set
name|ws
init|=
name|nds
decl_stmt|;
name|fd_set
name|es
init|=
name|nds
decl_stmt|;
name|timeval
name|timeout
decl_stmt|;
name|timeout
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|timeout
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
name|int
name|ret
init|=
operator|::
name|select
argument_list|(
name|mFd
operator|+
literal|1
argument_list|,
operator|&
name|rs
argument_list|,
operator|&
name|ws
argument_list|,
operator|&
name|es
argument_list|,
operator|&
name|timeout
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|<=
literal|0
condition|)
block|{
comment|//qDebug("QWaylandDisplay::readEvents() No data... blocking avoided");
return|return;
block|}
name|wl_display_iterate
argument_list|(
name|mDisplay
argument_list|,
name|WL_DISPLAY_READABLE
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|blockingReadEvents
name|void
name|QWaylandDisplay
operator|::
name|blockingReadEvents
parameter_list|()
block|{
name|wl_display_iterate
argument_list|(
name|mDisplay
argument_list|,
name|WL_DISPLAY_READABLE
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sourceUpdate
name|int
name|QWaylandDisplay
operator|::
name|sourceUpdate
parameter_list|(
name|uint32_t
name|mask
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|QWaylandDisplay
modifier|*
name|waylandDisplay
init|=
cast|static_cast
argument_list|<
name|QWaylandDisplay
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|waylandDisplay
operator|->
name|mSocketMask
operator|=
name|mask
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|outputHandleGeometry
name|void
name|QWaylandDisplay
operator|::
name|outputHandleGeometry
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_output
modifier|*
name|output
parameter_list|,
name|int32_t
name|x
parameter_list|,
name|int32_t
name|y
parameter_list|,
name|int32_t
name|width
parameter_list|,
name|int32_t
name|height
parameter_list|)
block|{
name|QWaylandDisplay
modifier|*
name|waylandDisplay
init|=
cast|static_cast
argument_list|<
name|QWaylandDisplay
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|QRect
name|outputRect
init|=
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
name|waylandDisplay
operator|->
name|createNewScreen
argument_list|(
name|output
argument_list|,
name|outputRect
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|member|outputListener
specifier|const
name|struct
name|wl_output_listener
name|QWaylandDisplay
operator|::
name|outputListener
init|=
block|{
name|QWaylandDisplay
operator|::
name|outputHandleGeometry
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|compositorListener
specifier|const
name|struct
name|wl_compositor_listener
name|QWaylandDisplay
operator|::
name|compositorListener
init|=
block|{
name|QWaylandDisplay
operator|::
name|handleVisual
block|, }
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|waitForScreens
name|void
name|QWaylandDisplay
operator|::
name|waitForScreens
parameter_list|()
block|{
name|flushRequests
argument_list|()
expr_stmt|;
while|while
condition|(
name|mScreens
operator|.
name|isEmpty
argument_list|()
condition|)
name|blockingReadEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|displayHandleGlobal
name|void
name|QWaylandDisplay
operator|::
name|displayHandleGlobal
parameter_list|(
name|struct
name|wl_display
modifier|*
name|display
parameter_list|,
name|uint32_t
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|interface
parameter_list|,
name|uint32_t
name|version
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|display
argument_list|)
expr_stmt|;
name|QWaylandDisplay
modifier|*
name|that
init|=
cast|static_cast
argument_list|<
name|QWaylandDisplay
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|that
operator|->
name|displayHandleGlobal
argument_list|(
name|id
argument_list|,
name|QByteArray
argument_list|(
name|interface
argument_list|)
argument_list|,
name|version
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|displayHandleGlobal
name|void
name|QWaylandDisplay
operator|::
name|displayHandleGlobal
parameter_list|(
name|uint32_t
name|id
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|interface
parameter_list|,
name|uint32_t
name|version
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|version
argument_list|)
expr_stmt|;
if|if
condition|(
name|interface
operator|==
literal|"wl_output"
condition|)
block|{
name|struct
name|wl_output
modifier|*
name|output
init|=
name|wl_output_create
argument_list|(
name|mDisplay
argument_list|,
name|id
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|wl_output_add_listener
argument_list|(
name|output
argument_list|,
operator|&
name|outputListener
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|interface
operator|==
literal|"wl_compositor"
condition|)
block|{
name|mCompositor
operator|=
name|wl_compositor_create
argument_list|(
name|mDisplay
argument_list|,
name|id
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|wl_compositor_add_listener
argument_list|(
name|mCompositor
argument_list|,
operator|&
name|compositorListener
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|interface
operator|==
literal|"wl_shm"
condition|)
block|{
name|mShm
operator|=
name|wl_shm_create
argument_list|(
name|mDisplay
argument_list|,
name|id
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|interface
operator|==
literal|"wl_shell"
condition|)
block|{
name|mShell
operator|=
name|wl_shell_create
argument_list|(
name|mDisplay
argument_list|,
name|id
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|wl_shell_add_listener
argument_list|(
name|mShell
argument_list|,
operator|&
name|shellListener
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|interface
operator|==
literal|"wl_input_device"
condition|)
block|{
name|QWaylandInputDevice
modifier|*
name|inputDevice
init|=
operator|new
name|QWaylandInputDevice
argument_list|(
name|mDisplay
argument_list|,
name|id
argument_list|)
decl_stmt|;
name|mInputDevices
operator|.
name|append
argument_list|(
name|inputDevice
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|interface
operator|==
literal|"wl_selection_offer"
condition|)
block|{
name|QPlatformIntegration
modifier|*
name|plat
init|=
name|QApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
decl_stmt|;
name|mSelectionOfferId
operator|=
name|id
expr_stmt|;
if|if
condition|(
name|plat
condition|)
name|handleSelectionOffer
argument_list|(
name|id
argument_list|)
expr_stmt|;
else|else
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"handleSelectionOffer"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|,
name|Q_ARG
argument_list|(
name|uint32_t
argument_list|,
name|id
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|handleSelectionOffer
name|void
name|QWaylandDisplay
operator|::
name|handleSelectionOffer
parameter_list|(
name|uint32_t
name|id
parameter_list|)
block|{
if|if
condition|(
name|mSelectionOfferId
operator|!=
name|id
condition|)
return|return;
name|QPlatformIntegration
modifier|*
name|plat
init|=
name|QApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
decl_stmt|;
name|QWaylandClipboard
modifier|*
name|clipboard
init|=
cast|static_cast
argument_list|<
name|QWaylandClipboard
operator|*
argument_list|>
argument_list|(
name|plat
operator|->
name|clipboard
argument_list|()
argument_list|)
decl_stmt|;
name|clipboard
operator|->
name|createSelectionOffer
argument_list|(
name|id
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleVisual
name|void
name|QWaylandDisplay
operator|::
name|handleVisual
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_compositor
modifier|*
name|compositor
parameter_list|,
name|uint32_t
name|id
parameter_list|,
name|uint32_t
name|token
parameter_list|)
block|{
name|QWaylandDisplay
modifier|*
name|self
init|=
cast|static_cast
argument_list|<
name|QWaylandDisplay
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|token
condition|)
block|{
case|case
name|WL_COMPOSITOR_VISUAL_ARGB32
case|:
name|self
operator|->
name|argb_visual
operator|=
name|wl_visual_create
argument_list|(
name|self
operator|->
name|mDisplay
argument_list|,
name|id
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
name|WL_COMPOSITOR_VISUAL_PREMULTIPLIED_ARGB32
case|:
name|self
operator|->
name|premultiplied_argb_visual
operator|=
name|wl_visual_create
argument_list|(
name|self
operator|->
name|mDisplay
argument_list|,
name|id
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
name|WL_COMPOSITOR_VISUAL_XRGB32
case|:
name|self
operator|->
name|rgb_visual
operator|=
name|wl_visual_create
argument_list|(
name|self
operator|->
name|mDisplay
argument_list|,
name|id
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function
end_unit
