begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfswindowsurface.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformGLContext>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/private/qgl_p.h>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/private/qglpaintdevice_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QEglFSPaintDevice
class|class
name|QEglFSPaintDevice
super|:
specifier|public
name|QGLPaintDevice
block|{
public|public:
DECL|function|QEglFSPaintDevice
name|QEglFSPaintDevice
parameter_list|(
name|QEglFSScreen
modifier|*
name|screen
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
member_init_list|:
name|QGLPaintDevice
argument_list|()
member_init_list|,
name|m_screen
argument_list|(
name|screen
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglPaintDevice %p, %p, %p"
argument_list|,
name|this
argument_list|,
name|screen
argument_list|,
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
DECL|function|size
name|QSize
name|size
parameter_list|()
specifier|const
block|{
return|return
name|m_screen
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
DECL|function|context
name|QGLContext
modifier|*
name|context
parameter_list|()
specifier|const
block|{
return|return
name|QGLContext
operator|::
name|fromPlatformGLContext
argument_list|(
name|m_screen
operator|->
name|platformContext
argument_list|()
argument_list|)
return|;
block|}
DECL|function|paintEngine
name|QPaintEngine
modifier|*
name|paintEngine
parameter_list|()
specifier|const
block|{
return|return
name|qt_qgl_paint_engine
argument_list|()
return|;
block|}
DECL|function|beginPaint
name|void
name|beginPaint
parameter_list|()
block|{
name|QGLPaintDevice
operator|::
name|beginPaint
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|m_screen
name|QEglFSScreen
modifier|*
name|m_screen
decl_stmt|;
DECL|member|m_context
name|QGLContext
modifier|*
name|m_context
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QEglFSWindowSurface
name|QEglFSWindowSurface
operator|::
name|QEglFSWindowSurface
parameter_list|(
name|QEglFSScreen
modifier|*
name|screen
parameter_list|,
name|QWidget
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QWindowSurface
argument_list|(
name|window
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglWindowSurface %p, %p"
argument_list|,
name|window
argument_list|,
name|screen
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m_paintDevice
operator|=
operator|new
name|QEglFSPaintDevice
argument_list|(
name|screen
argument_list|,
name|window
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|flush
name|void
name|QEglFSWindowSurface
operator|::
name|flush
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglWindowSurface::flush %p"
argument_list|,
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|widget
operator|->
name|platformWindow
argument_list|()
operator|->
name|glContext
argument_list|()
operator|->
name|swapBuffers
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QEglFSWindowSurface
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
