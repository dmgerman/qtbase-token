begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLXINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QGLXINTEGRATION_H
define|#
directive|define
name|QGLXINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|"qxcbwindow.h"
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformopenglcontext.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformoffscreensurface.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMutex>
end_include
begin_include
include|#
directive|include
file|<GL/glx.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QGLXContext
range|:
name|public
name|QPlatformOpenGLContext
block|{
name|public
operator|:
name|QGLXContext
argument_list|(
name|QXcbScreen
operator|*
name|screen
argument_list|,
specifier|const
name|QSurfaceFormat
operator|&
name|format
argument_list|,
name|QPlatformOpenGLContext
operator|*
name|share
argument_list|,
specifier|const
name|QVariant
operator|&
name|nativeHandle
argument_list|)
block|;
operator|~
name|QGLXContext
argument_list|()
block|;
name|bool
name|makeCurrent
argument_list|(
name|QPlatformSurface
operator|*
name|surface
argument_list|)
block|;
name|void
name|doneCurrent
argument_list|()
block|;
name|void
name|swapBuffers
argument_list|(
name|QPlatformSurface
operator|*
name|surface
argument_list|)
block|;
name|void
argument_list|(
operator|*
name|getProcAddress
argument_list|(
specifier|const
name|QByteArray
operator|&
name|procName
argument_list|)
argument_list|)
argument_list|()
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|;
name|bool
name|isSharing
argument_list|()
specifier|const
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|GLXContext
name|glxContext
argument_list|()
specifier|const
block|{
return|return
name|m_context
return|;
block|}
name|GLXFBConfig
name|glxConfig
argument_list|()
specifier|const
block|{
return|return
name|m_config
return|;
block|}
name|QVariant
name|nativeHandle
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|supportsThreading
argument_list|()
block|;
specifier|static
name|void
name|queryDummyContext
argument_list|()
block|;
name|private
operator|:
name|void
name|init
argument_list|(
name|QXcbScreen
operator|*
name|screen
argument_list|,
name|QPlatformOpenGLContext
operator|*
name|share
argument_list|)
block|;
name|void
name|init
argument_list|(
name|QXcbScreen
operator|*
name|screen
argument_list|,
name|QPlatformOpenGLContext
operator|*
name|share
argument_list|,
specifier|const
name|QVariant
operator|&
name|nativeHandle
argument_list|)
block|;
name|QXcbScreen
operator|*
name|m_screen
block|;
name|GLXFBConfig
name|m_config
block|;
name|GLXContext
name|m_context
block|;
name|GLXContext
name|m_shareContext
block|;
name|QSurfaceFormat
name|m_format
block|;
name|bool
name|m_isPBufferCurrent
block|;
name|int
name|m_swapInterval
block|;
name|bool
name|m_ownsContext
block|;
specifier|static
name|bool
name|m_queriedDummyContext
block|;
specifier|static
name|bool
name|m_supportsThreading
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGLXPbuffer
range|:
name|public
name|QPlatformOffscreenSurface
block|{
name|public
operator|:
name|explicit
name|QGLXPbuffer
argument_list|(
name|QOffscreenSurface
operator|*
name|offscreenSurface
argument_list|)
block|;
operator|~
name|QGLXPbuffer
argument_list|()
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|m_pbuffer
operator|!=
literal|0
return|;
block|}
name|GLXPbuffer
name|pbuffer
argument_list|()
specifier|const
block|{
return|return
name|m_pbuffer
return|;
block|}
name|private
operator|:
name|QSurfaceFormat
name|m_format
block|;
name|QXcbScreen
operator|*
name|m_screen
block|;
name|GLXPbuffer
name|m_pbuffer
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
end_unit
