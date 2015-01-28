begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXEGLWINDOW_H
end_ifndef
begin_define
DECL|macro|QQNXEGLWINDOW_H
define|#
directive|define
name|QQNXEGLWINDOW_H
end_define
begin_include
include|#
directive|include
file|"qqnxwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QMutex>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QQnxGLContext
name|class
name|QQnxGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QQnxEglWindow
range|:
name|public
name|QQnxWindow
block|{
name|public
operator|:
name|QQnxEglWindow
argument_list|(
argument|QWindow *window
argument_list|,
argument|screen_context_t context
argument_list|,
argument|bool needRootWindow
argument_list|)
block|;
operator|~
name|QQnxEglWindow
argument_list|()
block|;
name|void
name|createEGLSurface
argument_list|()
block|;
name|void
name|destroyEGLSurface
argument_list|()
block|;
name|void
name|swapEGLBuffers
argument_list|()
block|;
name|EGLSurface
name|getSurface
argument_list|()
block|;
name|void
name|setPlatformOpenGLContext
argument_list|(
name|QQnxGLContext
operator|*
name|platformOpenGLContext
argument_list|)
block|;
name|QQnxGLContext
operator|*
name|platformOpenGLContext
argument_list|()
specifier|const
block|{
return|return
name|m_platformOpenGLContext
return|;
block|}
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|protected
operator|:
name|int
name|pixelFormat
argument_list|()
specifier|const
block|;
name|void
name|resetBuffers
argument_list|()
block|;
name|private
operator|:
name|QSize
name|m_requestedBufferSize
block|;
comment|// This mutex is used to protect access to the m_requestedBufferSize
comment|// member. This member is used in conjunction with QQnxGLContext::requestNewSurface()
comment|// to coordinate recreating the EGL surface which involves destroying any
comment|// existing EGL surface; resizing the native window buffers; and creating a new
comment|// EGL surface. All of this has to be done from the thread that is calling
comment|// QQnxGLContext::makeCurrent()
name|mutable
name|QMutex
name|m_mutex
block|;
name|QQnxGLContext
operator|*
name|m_platformOpenGLContext
block|;
name|QAtomicInt
name|m_newSurfaceRequested
block|;
name|EGLSurface
name|m_eglSurface
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
comment|// QQNXEGLWINDOW_H
end_comment
end_unit
