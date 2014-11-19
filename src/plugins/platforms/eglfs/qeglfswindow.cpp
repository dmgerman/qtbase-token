begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfswindow.h"
end_include
begin_include
include|#
directive|include
file|"qeglfshooks.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglplatformcursor_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEglFSWindow
name|QEglFSWindow
operator|::
name|QEglFSWindow
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QEGLPlatformWindow
argument_list|(
name|w
argument_list|)
member_init_list|,
name|m_surface
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_window
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_flags
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QEglFSWindow
name|QEglFSWindow
operator|::
name|~
name|QEglFSWindow
parameter_list|()
block|{
name|destroy
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|create
name|void
name|QEglFSWindow
operator|::
name|create
parameter_list|()
block|{
if|if
condition|(
name|m_flags
operator|.
name|testFlag
argument_list|(
name|Created
argument_list|)
condition|)
return|return;
name|QEGLPlatformWindow
operator|::
name|create
argument_list|()
expr_stmt|;
name|m_flags
operator|=
name|Created
expr_stmt|;
if|if
condition|(
name|window
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|Qt
operator|::
name|Desktop
condition|)
return|return;
comment|// Stop if there is already a window backed by a native window and surface. Additional
comment|// raster windows will not have their own native window, surface and context. Instead,
comment|// they will be composited onto the root window's surface.
name|QEglFSScreen
modifier|*
name|screen
init|=
name|this
operator|->
name|screen
argument_list|()
decl_stmt|;
name|QOpenGLCompositor
modifier|*
name|compositor
init|=
name|QOpenGLCompositor
operator|::
name|instance
argument_list|()
decl_stmt|;
if|if
condition|(
name|screen
operator|->
name|primarySurface
argument_list|()
operator|!=
name|EGL_NO_SURFACE
condition|)
block|{
if|if
condition|(
name|isRaster
argument_list|()
operator|&&
name|compositor
operator|->
name|targetWindow
argument_list|()
condition|)
block|{
name|m_format
operator|=
name|compositor
operator|->
name|targetWindow
argument_list|()
operator|->
name|format
argument_list|()
expr_stmt|;
return|return;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_ANDROID_NO_SDK
argument_list|)
comment|// We can have either a single OpenGL window or multiple raster windows.
comment|// Other combinations cannot work.
name|qFatal
argument_list|(
literal|"EGLFS: OpenGL windows cannot be mixed with others."
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
name|m_flags
operator||=
name|HasNativeWindow
expr_stmt|;
name|setGeometry
argument_list|(
name|QRect
argument_list|()
argument_list|)
expr_stmt|;
comment|// will become fullscreen
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|window
argument_list|()
argument_list|,
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|EGLDisplay
name|display
init|=
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|)
operator|->
name|display
argument_list|()
decl_stmt|;
name|QSurfaceFormat
name|platformFormat
init|=
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|surfaceFormatFor
argument_list|(
name|window
argument_list|()
operator|->
name|requestedFormat
argument_list|()
argument_list|)
decl_stmt|;
name|m_config
operator|=
name|QEglFSIntegration
operator|::
name|chooseConfig
argument_list|(
name|display
argument_list|,
name|platformFormat
argument_list|)
expr_stmt|;
name|m_format
operator|=
name|q_glFormatFromConfig
argument_list|(
name|display
argument_list|,
name|m_config
argument_list|,
name|platformFormat
argument_list|)
expr_stmt|;
name|resetSurface
argument_list|()
expr_stmt|;
name|screen
operator|->
name|setPrimarySurface
argument_list|(
name|m_surface
argument_list|)
expr_stmt|;
if|if
condition|(
name|isRaster
argument_list|()
condition|)
block|{
name|QOpenGLContext
modifier|*
name|context
init|=
operator|new
name|QOpenGLContext
argument_list|(
name|QGuiApplication
operator|::
name|instance
argument_list|()
argument_list|)
decl_stmt|;
name|context
operator|->
name|setFormat
argument_list|(
name|m_format
argument_list|)
expr_stmt|;
name|context
operator|->
name|setScreen
argument_list|(
name|window
argument_list|()
operator|->
name|screen
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|context
operator|->
name|create
argument_list|()
condition|)
name|qFatal
argument_list|(
literal|"EGLFS: Failed to create compositing context"
argument_list|)
expr_stmt|;
name|compositor
operator|->
name|setTarget
argument_list|(
name|context
argument_list|,
name|window
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|destroy
name|void
name|QEglFSWindow
operator|::
name|destroy
parameter_list|()
block|{
name|QEglFSScreen
modifier|*
name|screen
init|=
name|this
operator|->
name|screen
argument_list|()
decl_stmt|;
if|if
condition|(
name|m_flags
operator|.
name|testFlag
argument_list|(
name|HasNativeWindow
argument_list|)
condition|)
block|{
name|QEGLPlatformCursor
modifier|*
name|cursor
init|=
name|qobject_cast
argument_list|<
name|QEGLPlatformCursor
operator|*
argument_list|>
argument_list|(
name|screen
operator|->
name|cursor
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|cursor
condition|)
name|cursor
operator|->
name|resetResources
argument_list|()
expr_stmt|;
if|if
condition|(
name|screen
operator|->
name|primarySurface
argument_list|()
operator|==
name|m_surface
condition|)
name|screen
operator|->
name|setPrimarySurface
argument_list|(
name|EGL_NO_SURFACE
argument_list|)
expr_stmt|;
name|invalidateSurface
argument_list|()
expr_stmt|;
block|}
name|m_flags
operator|=
literal|0
expr_stmt|;
name|QOpenGLCompositor
operator|::
name|instance
argument_list|()
operator|->
name|removeWindow
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// The virtual functions resetSurface and invalidateSurface may get overridden
end_comment
begin_comment
comment|// in derived classes, for example in the Android port, to perform the native
end_comment
begin_comment
comment|// window and surface creation differently.
end_comment
begin_function
DECL|function|invalidateSurface
name|void
name|QEglFSWindow
operator|::
name|invalidateSurface
parameter_list|()
block|{
if|if
condition|(
name|m_surface
operator|!=
name|EGL_NO_SURFACE
condition|)
block|{
name|EGLDisplay
name|display
init|=
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|()
argument_list|)
operator|->
name|display
argument_list|()
decl_stmt|;
name|eglDestroySurface
argument_list|(
name|display
argument_list|,
name|m_surface
argument_list|)
expr_stmt|;
name|m_surface
operator|=
name|EGL_NO_SURFACE
expr_stmt|;
block|}
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|destroyNativeWindow
argument_list|(
name|m_window
argument_list|)
expr_stmt|;
name|m_window
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resetSurface
name|void
name|QEglFSWindow
operator|::
name|resetSurface
parameter_list|()
block|{
name|QEglFSScreen
modifier|*
name|nativeScreen
init|=
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|()
argument_list|)
decl_stmt|;
name|EGLDisplay
name|display
init|=
name|nativeScreen
operator|->
name|display
argument_list|()
decl_stmt|;
name|m_window
operator|=
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|createNativeWindow
argument_list|(
name|this
argument_list|,
name|nativeScreen
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
name|m_format
argument_list|)
expr_stmt|;
name|m_surface
operator|=
name|eglCreateWindowSurface
argument_list|(
name|display
argument_list|,
name|m_config
argument_list|,
name|m_window
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_surface
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
name|EGLint
name|error
init|=
name|eglGetError
argument_list|()
decl_stmt|;
name|eglTerminate
argument_list|(
name|display
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGL Error : Could not create the egl surface: error = 0x%x\n"
argument_list|,
name|error
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QEglFSWindow
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|QOpenGLCompositor
modifier|*
name|compositor
init|=
name|QOpenGLCompositor
operator|::
name|instance
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QOpenGLCompositorWindow
modifier|*
argument_list|>
name|windows
init|=
name|compositor
operator|->
name|windows
argument_list|()
decl_stmt|;
name|QWindow
modifier|*
name|wnd
init|=
name|window
argument_list|()
decl_stmt|;
if|if
condition|(
name|wnd
operator|->
name|type
argument_list|()
operator|!=
name|Qt
operator|::
name|Desktop
condition|)
block|{
if|if
condition|(
name|visible
condition|)
block|{
name|compositor
operator|->
name|addWindow
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|compositor
operator|->
name|removeWindow
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|windows
operator|=
name|compositor
operator|->
name|windows
argument_list|()
expr_stmt|;
if|if
condition|(
name|windows
operator|.
name|size
argument_list|()
condition|)
name|windows
operator|.
name|last
argument_list|()
operator|->
name|sourceWindow
argument_list|()
operator|->
name|requestActivate
argument_list|()
expr_stmt|;
block|}
block|}
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|wnd
argument_list|,
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|wnd
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|visible
condition|)
name|QWindowSystemInterface
operator|::
name|flushWindowSystemEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QEglFSWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|r
parameter_list|)
block|{
name|QRect
name|rect
decl_stmt|;
name|bool
name|forceFullscreen
init|=
name|m_flags
operator|.
name|testFlag
argument_list|(
name|HasNativeWindow
argument_list|)
decl_stmt|;
if|if
condition|(
name|forceFullscreen
condition|)
name|rect
operator|=
name|screen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
expr_stmt|;
else|else
name|rect
operator|=
name|r
expr_stmt|;
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
comment|// if we corrected the size, trigger a resize event
if|if
condition|(
name|rect
operator|!=
name|r
condition|)
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|rect
argument_list|,
name|r
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|geometry
name|QRect
name|QEglFSWindow
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
comment|// For yet-to-become-fullscreen windows report the geometry covering the entire
comment|// screen. This is particularly important for Quick where the root object may get
comment|// sized to some geometry queried before calling create().
if|if
condition|(
operator|!
name|m_flags
operator|.
name|testFlag
argument_list|(
name|Created
argument_list|)
operator|&&
name|screen
argument_list|()
operator|->
name|primarySurface
argument_list|()
operator|==
name|EGL_NO_SURFACE
condition|)
return|return
name|screen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
return|;
return|return
name|QPlatformWindow
operator|::
name|geometry
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|requestActivateWindow
name|void
name|QEglFSWindow
operator|::
name|requestActivateWindow
parameter_list|()
block|{
if|if
condition|(
name|window
argument_list|()
operator|->
name|type
argument_list|()
operator|!=
name|Qt
operator|::
name|Desktop
condition|)
name|QOpenGLCompositor
operator|::
name|instance
argument_list|()
operator|->
name|moveToTop
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|wnd
init|=
name|window
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
name|wnd
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|wnd
argument_list|,
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|wnd
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|raise
name|void
name|QEglFSWindow
operator|::
name|raise
parameter_list|()
block|{
name|QWindow
modifier|*
name|wnd
init|=
name|window
argument_list|()
decl_stmt|;
if|if
condition|(
name|wnd
operator|->
name|type
argument_list|()
operator|!=
name|Qt
operator|::
name|Desktop
condition|)
block|{
name|QOpenGLCompositor
operator|::
name|instance
argument_list|()
operator|->
name|moveToTop
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|wnd
argument_list|,
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|wnd
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|lower
name|void
name|QEglFSWindow
operator|::
name|lower
parameter_list|()
block|{
name|QOpenGLCompositor
modifier|*
name|compositor
init|=
name|QOpenGLCompositor
operator|::
name|instance
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QOpenGLCompositorWindow
modifier|*
argument_list|>
name|windows
init|=
name|compositor
operator|->
name|windows
argument_list|()
decl_stmt|;
if|if
condition|(
name|window
argument_list|()
operator|->
name|type
argument_list|()
operator|!=
name|Qt
operator|::
name|Desktop
operator|&&
name|windows
operator|.
name|count
argument_list|()
operator|>
literal|1
condition|)
block|{
name|int
name|idx
init|=
name|windows
operator|.
name|indexOf
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|idx
operator|>
literal|0
condition|)
block|{
name|compositor
operator|->
name|changeWindowIndex
argument_list|(
name|this
argument_list|,
name|idx
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|windows
operator|.
name|last
argument_list|()
operator|->
name|sourceWindow
argument_list|()
argument_list|,
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|windows
operator|.
name|last
argument_list|()
operator|->
name|sourceWindow
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|surface
name|EGLSurface
name|QEglFSWindow
operator|::
name|surface
parameter_list|()
specifier|const
block|{
return|return
name|m_surface
operator|!=
name|EGL_NO_SURFACE
condition|?
name|m_surface
else|:
name|screen
argument_list|()
operator|->
name|primarySurface
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|format
name|QSurfaceFormat
name|QEglFSWindow
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
end_function
begin_function
DECL|function|eglWindow
name|EGLNativeWindowType
name|QEglFSWindow
operator|::
name|eglWindow
parameter_list|()
specifier|const
block|{
return|return
name|m_window
return|;
block|}
end_function
begin_function
DECL|function|screen
name|QEglFSScreen
modifier|*
name|QEglFSWindow
operator|::
name|screen
parameter_list|()
specifier|const
block|{
return|return
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|QPlatformWindow
operator|::
name|screen
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
