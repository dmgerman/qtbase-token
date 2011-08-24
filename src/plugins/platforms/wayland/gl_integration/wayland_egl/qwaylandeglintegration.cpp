begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandeglintegration.h"
end_include
begin_include
include|#
directive|include
file|"gl_integration/qwaylandglintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandeglwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandglcontext.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_constructor
DECL|function|QWaylandEglIntegration
name|QWaylandEglIntegration
operator|::
name|QWaylandEglIntegration
parameter_list|(
name|struct
name|wl_display
modifier|*
name|waylandDisplay
parameter_list|)
member_init_list|:
name|m_waylandDisplay
argument_list|(
name|waylandDisplay
argument_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Using Wayland-EGL"
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandEglIntegration
name|QWaylandEglIntegration
operator|::
name|~
name|QWaylandEglIntegration
parameter_list|()
block|{
name|eglTerminate
argument_list|(
name|m_eglDisplay
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initialize
name|void
name|QWaylandEglIntegration
operator|::
name|initialize
parameter_list|()
block|{
name|QByteArray
name|eglPlatform
init|=
name|qgetenv
argument_list|(
literal|"EGL_PLATFORM"
argument_list|)
decl_stmt|;
if|if
condition|(
name|eglPlatform
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|setenv
argument_list|(
literal|"EGL_PLATFORM"
argument_list|,
literal|"wayland"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
name|EGLint
name|major
decl_stmt|,
name|minor
decl_stmt|;
name|m_eglDisplay
operator|=
name|eglGetDisplay
argument_list|(
name|m_waylandDisplay
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglDisplay
operator|==
name|NULL
condition|)
block|{
name|qWarning
argument_list|(
literal|"EGL not available"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|eglInitialize
argument_list|(
name|m_eglDisplay
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"failed to initialize EGL display"
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
end_function
begin_function
DECL|function|createEglWindow
name|QWaylandWindow
modifier|*
name|QWaylandEglIntegration
operator|::
name|createEglWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
return|return
operator|new
name|QWaylandEglWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformGLContext
name|QPlatformGLContext
modifier|*
name|QWaylandEglIntegration
operator|::
name|createPlatformGLContext
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|glFormat
parameter_list|,
name|QPlatformGLContext
modifier|*
name|share
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QWaylandGLContext
argument_list|(
name|m_eglDisplay
argument_list|,
name|glFormat
argument_list|,
name|share
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|eglDisplay
name|EGLDisplay
name|QWaylandEglIntegration
operator|::
name|eglDisplay
parameter_list|()
specifier|const
block|{
return|return
name|m_eglDisplay
return|;
block|}
end_function
begin_function
DECL|function|createGLIntegration
name|QWaylandGLIntegration
modifier|*
name|QWaylandGLIntegration
operator|::
name|createGLIntegration
parameter_list|(
name|QWaylandDisplay
modifier|*
name|waylandDisplay
parameter_list|)
block|{
return|return
operator|new
name|QWaylandEglIntegration
argument_list|(
name|waylandDisplay
operator|->
name|wl_display
argument_list|()
argument_list|)
return|;
block|}
end_function
end_unit
