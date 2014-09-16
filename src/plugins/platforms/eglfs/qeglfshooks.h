begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSHOOKS_H
end_ifndef
begin_define
DECL|macro|QEGLFSHOOKS_H
define|#
directive|define
name|QEGLFSHOOKS_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEglFSScreen
name|class
name|QEglFSScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEglFSHooks
block|{
name|public
label|:
name|virtual
operator|~
name|QEglFSHooks
argument_list|()
block|{}
name|virtual
name|void
name|platformInit
argument_list|()
expr_stmt|;
name|virtual
name|void
name|platformDestroy
parameter_list|()
function_decl|;
name|virtual
name|EGLNativeDisplayType
name|platformDisplay
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QSizeF
name|physicalScreenSize
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QSize
name|screenSize
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QDpi
name|logicalDpi
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|Qt
operator|::
name|ScreenOrientation
name|nativeOrientation
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|screenDepth
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QImage
operator|::
name|Format
name|screenFormat
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QSurfaceFormat
name|surfaceFormatFor
argument_list|(
specifier|const
name|QSurfaceFormat
operator|&
name|inputFormat
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|EGLNativeWindowType
name|createNativeWindow
parameter_list|(
name|QPlatformWindow
modifier|*
name|platformWindow
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|virtual
name|void
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
function_decl|;
name|virtual
name|bool
name|hasCapability
argument_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QPlatformCursor
modifier|*
name|createCursor
argument_list|(
name|QPlatformScreen
operator|*
name|screen
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|filterConfig
argument_list|(
name|EGLDisplay
name|display
argument_list|,
name|EGLConfig
name|config
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|waitForVSync
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|presentBuffer
parameter_list|()
function_decl|;
name|virtual
name|QByteArray
name|fbDeviceName
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|framebufferIndex
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QEglFSHooks
modifier|*
name|hooks
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|EGLFS_PLATFORM_HOOKS
specifier|extern
name|QEglFSHooks
modifier|*
name|platformHooks
decl_stmt|;
return|return
name|platformHooks
return|;
else|#
directive|else
specifier|extern
name|QEglFSHooks
name|stubHooks
decl_stmt|;
return|return
operator|&
name|stubHooks
return|;
endif|#
directive|endif
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QEGLFSHOOKS_H
end_comment
end_unit
