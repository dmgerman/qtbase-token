begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMINIMALEGLSCREEN_H
end_ifndef
begin_define
DECL|macro|QMINIMALEGLSCREEN_H
define|#
directive|define
name|QMINIMALEGLSCREEN_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformOpenGLContext
name|class
name|QPlatformOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMinimalEglScreen
range|:
name|public
name|QPlatformScreen
block|{
name|public
operator|:
name|QMinimalEglScreen
argument_list|(
argument|EGLNativeDisplayType display
argument_list|)
block|;
operator|~
name|QMinimalEglScreen
argument_list|()
block|;
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|int
name|depth
argument_list|()
specifier|const
block|;
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
block|;
name|QPlatformOpenGLContext
operator|*
name|platformContext
argument_list|()
specifier|const
block|;
name|EGLSurface
name|surface
argument_list|()
specifier|const
block|{
return|return
name|m_surface
return|;
block|}
name|private
operator|:
name|void
name|createAndSetPlatformContext
argument_list|()
specifier|const
block|;
name|void
name|createAndSetPlatformContext
argument_list|()
block|;
name|QRect
name|m_geometry
block|;
name|int
name|m_depth
block|;
name|QImage
operator|::
name|Format
name|m_format
block|;
name|QPlatformOpenGLContext
operator|*
name|m_platformContext
block|;
name|EGLDisplay
name|m_dpy
block|;
name|EGLSurface
name|m_surface
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
comment|// QMINIMALEGLSCREEN_H
end_comment
end_unit
