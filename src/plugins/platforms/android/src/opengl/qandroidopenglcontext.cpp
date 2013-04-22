begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidopenglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qandroidopenglplatformwindow.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QAndroidOpenGLContext
name|QAndroidOpenGLContext
operator|::
name|QAndroidOpenGLContext
parameter_list|(
specifier|const
name|QAndroidPlatformIntegration
modifier|*
name|integration
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|QPlatformOpenGLContext
modifier|*
name|share
parameter_list|,
name|EGLDisplay
name|display
parameter_list|,
name|EGLenum
name|eglApi
parameter_list|)
member_init_list|:
name|QEglFSContext
argument_list|(
name|format
argument_list|,
name|share
argument_list|,
name|display
argument_list|,
name|eglApi
argument_list|)
member_init_list|,
name|m_platformIntegration
argument_list|(
name|integration
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|swapBuffers
name|void
name|QAndroidOpenGLContext
operator|::
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|QEglFSContext
operator|::
name|swapBuffers
argument_list|(
name|surface
argument_list|)
expr_stmt|;
if|if
condition|(
name|surface
operator|->
name|surface
argument_list|()
operator|->
name|surfaceClass
argument_list|()
operator|==
name|QSurface
operator|::
name|Window
condition|)
block|{
name|QAndroidOpenGLPlatformWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QAndroidOpenGLPlatformWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|window
operator|->
name|lock
argument_list|()
expr_stmt|;
name|QSize
name|size
init|=
name|window
operator|->
name|scheduledResize
argument_list|()
decl_stmt|;
if|if
condition|(
name|size
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QRect
name|geometry
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|)
decl_stmt|;
name|window
operator|->
name|setGeometry
argument_list|(
name|geometry
argument_list|)
expr_stmt|;
name|window
operator|->
name|scheduleResize
argument_list|(
name|QSize
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|window
operator|->
name|unlock
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
