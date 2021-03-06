begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|Q_DECL_OVERRIDE
block|;
name|int
name|depth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
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
