begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIOSCONTEXT_H
end_ifndef
begin_define
DECL|macro|QIOSCONTEXT_H
define|#
directive|define
name|QIOSCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformopenglcontext.h>
end_include
begin_decl_stmt
unit|@
DECL|variable|EAGLContext
name|class
name|EAGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QIOSWindow
name|class
name|QIOSWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QIOSContext
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPlatformOpenGLContext
block|{
name|Q_OBJECT
name|public
range|:
name|QIOSContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
decl_stmt|;
operator|~
name|QIOSContext
argument_list|()
expr_stmt|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|swapBuffers
argument_list|(
name|QPlatformSurface
operator|*
name|surface
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|makeCurrent
argument_list|(
name|QPlatformSurface
operator|*
name|surface
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|doneCurrent
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|GLuint
name|defaultFramebufferObject
argument_list|(
name|QPlatformSurface
operator|*
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QFunctionPointer
name|getProcAddress
argument_list|(
specifier|const
name|QByteArray
operator|&
name|procName
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|isSharing
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|private
name|Q_SLOTS
range|:
name|void
name|windowDestroyed
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
decl_stmt|;
name|private
label|:
name|QIOSContext
modifier|*
name|m_sharedContext
decl_stmt|;
name|EAGLContext
modifier|*
name|m_eaglContext
decl_stmt|;
name|QSurfaceFormat
name|m_format
decl_stmt|;
struct|struct
name|FramebufferObject
block|{
name|GLuint
name|handle
decl_stmt|;
name|GLuint
name|colorRenderbuffer
decl_stmt|;
name|GLuint
name|depthRenderbuffer
decl_stmt|;
name|GLint
name|renderbufferWidth
decl_stmt|;
name|GLint
name|renderbufferHeight
decl_stmt|;
name|bool
name|isComplete
decl_stmt|;
block|}
struct|;
specifier|static
name|void
name|deleteBuffers
parameter_list|(
specifier|const
name|FramebufferObject
modifier|&
name|framebufferObject
parameter_list|)
function_decl|;
name|FramebufferObject
modifier|&
name|backingFramebufferObjectFor
argument_list|(
name|QPlatformSurface
operator|*
argument_list|)
decl|const
decl_stmt|;
name|mutable
name|QHash
operator|<
name|QIOSWindow
operator|*
operator|,
name|FramebufferObject
operator|>
name|m_framebufferObjects
expr_stmt|;
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
comment|// QIOSCONTEXT_H
end_comment
end_unit
