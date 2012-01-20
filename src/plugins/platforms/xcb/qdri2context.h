begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDRI2CONTEXT_H
end_ifndef
begin_define
DECL|macro|QDRI2CONTEXT_H
define|#
directive|define
name|QDRI2CONTEXT_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QPlatformOpenGLContext>
end_include
begin_struct_decl
struct_decl|struct
name|xcb_dri2_dri2_buffer_t
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbWindow
name|class
name|QXcbWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDri2ContextPrivate
name|class
name|QDri2ContextPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDri2Context
range|:
name|public
name|QPlatformOpenGLContext
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
name|QDri2Context
argument_list|)
block|;
name|public
operator|:
name|QDri2Context
argument_list|(
name|QXcbWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QDri2Context
argument_list|()
block|;
name|void
name|makeCurrent
argument_list|()
block|;
name|void
name|doneCurrent
argument_list|()
block|;
name|void
name|swapBuffers
argument_list|()
block|;
name|void
operator|*
name|getProcAddress
argument_list|(
specifier|const
name|QString
operator|&
name|procName
argument_list|)
block|;
name|void
name|resize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|QPlatformWindowFormat
name|platformWindowFormat
argument_list|()
specifier|const
block|;
name|void
operator|*
name|eglContext
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|xcb_dri2_dri2_buffer_t
operator|*
name|backBuffer
argument_list|()
block|;
name|QScopedPointer
operator|<
name|QDri2ContextPrivate
operator|>
name|d_ptr
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QDri2Context
argument_list|)
block|}
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
comment|// QDRI2CONTEXT_H
end_comment
end_unit
