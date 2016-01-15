begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSCONTEXT_H
end_ifndef
begin_define
DECL|macro|QEGLFSCONTEXT_H
define|#
directive|define
name|QEGLFSCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglplatformcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|"qeglfsglobal.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_EGLFS_EXPORT
name|QEglFSContext
range|:
name|public
name|QEGLPlatformContext
block|{
name|public
operator|:
name|QEglFSContext
argument_list|(
argument|const QSurfaceFormat&format
argument_list|,
argument|QPlatformOpenGLContext *share
argument_list|,
argument|EGLDisplay display
argument_list|,
argument|EGLConfig *config
argument_list|,
argument|const QVariant&nativeHandle
argument_list|)
block|;
name|EGLSurface
name|eglSurfaceForPlatformSurface
argument_list|(
argument|QPlatformSurface *surface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|EGLSurface
name|createTemporaryOffscreenSurface
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|destroyTemporaryOffscreenSurface
argument_list|(
argument|EGLSurface surface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|swapBuffers
argument_list|(
argument|QPlatformSurface *surface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|EGLNativeWindowType
name|m_tempWindow
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
comment|// QEGLFSCONTEXT_H
end_comment
end_unit
