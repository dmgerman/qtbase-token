begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAGLCONTEXT_H
end_ifndef
begin_define
DECL|macro|QCOCOAGLCONTEXT_H
define|#
directive|define
name|QCOCOAGLCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QPointer>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformopenglcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_undef
DECL|macro|slots
undef|#
directive|undef
name|slots
end_undef
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QCocoaGLContext
range|:
name|public
name|QPlatformOpenGLContext
block|{
name|public
operator|:
name|QCocoaGLContext
argument_list|(
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
name|QCocoaGLContext
argument_list|()
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|;
name|void
name|swapBuffers
argument_list|(
name|QPlatformSurface
operator|*
name|surface
argument_list|)
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
name|void
name|update
argument_list|()
block|;
specifier|static
name|NSOpenGLPixelFormat
operator|*
name|createNSOpenGLPixelFormat
argument_list|(
specifier|const
name|QSurfaceFormat
operator|&
name|format
argument_list|)
block|;
name|NSOpenGLContext
operator|*
name|nsOpenGLContext
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
name|void
name|windowWasHidden
argument_list|()
block|;
name|QVariant
name|nativeHandle
argument_list|()
specifier|const
block|;
name|private
operator|:
name|void
name|setActiveWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|updateSurfaceFormat
argument_list|()
block|;
name|NSOpenGLContext
operator|*
name|m_context
block|;
name|NSOpenGLContext
operator|*
name|m_shareContext
block|;
name|QSurfaceFormat
name|m_format
block|;
name|QPointer
operator|<
name|QWindow
operator|>
name|m_currentWindow
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
comment|// QCOCOAGLCONTEXT_H
end_comment
end_unit
