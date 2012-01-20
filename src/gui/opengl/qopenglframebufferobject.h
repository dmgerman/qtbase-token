begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLFRAMEBUFFEROBJECT_H
end_ifndef
begin_define
DECL|macro|QOPENGLFRAMEBUFFEROBJECT_H
define|#
directive|define
name|QOPENGLFRAMEBUFFEROBJECT_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qopengl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QOpenGLFramebufferObjectPrivate
decl_stmt|;
DECL|variable|QOpenGLFramebufferObjectFormat
name|class
name|QOpenGLFramebufferObjectFormat
decl_stmt|;
name|class
name|Q_GUI_EXPORT
name|QOpenGLFramebufferObject
decl_stmt|{     Q_DECLARE_PRIVATE(QOpenGLFramebufferObject
end_function
begin_label
unit|)
name|public
label|:
end_label
begin_enum
enum|enum
name|Attachment
block|{
name|NoAttachment
block|,
name|CombinedDepthStencil
block|,
name|Depth
block|}
enum|;
end_enum
begin_macro
name|QOpenGLFramebufferObject
argument_list|(
argument|const QSize&size
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QOpenGLFramebufferObject
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
end_if
begin_macro
name|QOpenGLFramebufferObject
argument_list|(
argument|const QSize&size
argument_list|,
argument|Attachment attachment
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|,
argument|GLenum internal_format = GL_RGBA8
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QOpenGLFramebufferObject
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|Attachment attachment
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|,
argument|GLenum internal_format = GL_RGBA8
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_else
else|#
directive|else
end_else
begin_macro
name|QOpenGLFramebufferObject
argument_list|(
argument|const QSize&size
argument_list|,
argument|Attachment attachment
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|,
argument|GLenum internal_format = GL_RGBA
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QOpenGLFramebufferObject
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|Attachment attachment
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|,
argument|GLenum internal_format = GL_RGBA
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QOpenGLFramebufferObject
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QOpenGLFramebufferObjectFormat
operator|&
name|format
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QOpenGLFramebufferObject
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|const QOpenGLFramebufferObjectFormat&format
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|virtual
operator|~
name|QOpenGLFramebufferObject
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QOpenGLFramebufferObjectFormat
name|format
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isBound
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|bind
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|release
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|width
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|.
name|width
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|height
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|.
name|height
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|GLuint
name|texture
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QSize
name|size
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QImage
name|toImage
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Attachment
name|attachment
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|GLuint
name|handle
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|bool
name|bindDefault
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|hasOpenGLFramebufferObjects
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|hasOpenGLFramebufferBlit
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|blitFramebuffer
parameter_list|(
name|QOpenGLFramebufferObject
modifier|*
name|target
parameter_list|,
specifier|const
name|QRect
modifier|&
name|targetRect
parameter_list|,
name|QOpenGLFramebufferObject
modifier|*
name|source
parameter_list|,
specifier|const
name|QRect
modifier|&
name|sourceRect
parameter_list|,
name|GLbitfield
name|buffers
init|=
name|GL_COLOR_BUFFER_BIT
parameter_list|,
name|GLenum
name|filter
init|=
name|GL_NEAREST
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|blitFramebuffer
parameter_list|(
name|QOpenGLFramebufferObject
modifier|*
name|target
parameter_list|,
name|QOpenGLFramebufferObject
modifier|*
name|source
parameter_list|,
name|GLbitfield
name|buffers
init|=
name|GL_COLOR_BUFFER_BIT
parameter_list|,
name|GLenum
name|filter
init|=
name|GL_NEAREST
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QOpenGLFramebufferObject
argument_list|)
end_macro
begin_expr_stmt
name|QScopedPointer
operator|<
name|QOpenGLFramebufferObjectPrivate
operator|>
name|d_ptr
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|friend
name|class
name|QOpenGLPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QOpenGLFBOGLPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
DECL|variable|QOpenGLFramebufferObjectFormatPrivate
name|class
name|QOpenGLFramebufferObjectFormatPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLFramebufferObjectFormat
block|{
name|public
label|:
name|QOpenGLFramebufferObjectFormat
argument_list|()
expr_stmt|;
name|QOpenGLFramebufferObjectFormat
argument_list|(
specifier|const
name|QOpenGLFramebufferObjectFormat
operator|&
name|other
argument_list|)
expr_stmt|;
name|QOpenGLFramebufferObjectFormat
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QOpenGLFramebufferObjectFormat
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QOpenGLFramebufferObjectFormat
argument_list|()
expr_stmt|;
name|void
name|setSamples
parameter_list|(
name|int
name|samples
parameter_list|)
function_decl|;
name|int
name|samples
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMipmap
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|mipmap
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAttachment
argument_list|(
name|QOpenGLFramebufferObject
operator|::
name|Attachment
name|attachment
argument_list|)
decl_stmt|;
name|QOpenGLFramebufferObject
operator|::
name|Attachment
name|attachment
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setTextureTarget
parameter_list|(
name|GLenum
name|target
parameter_list|)
function_decl|;
name|GLenum
name|textureTarget
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setInternalTextureFormat
parameter_list|(
name|GLenum
name|internalTextureFormat
parameter_list|)
function_decl|;
name|GLenum
name|internalTextureFormat
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QOpenGLFramebufferObjectFormat
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QOpenGLFramebufferObjectFormat
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|private
label|:
name|QOpenGLFramebufferObjectFormatPrivate
modifier|*
name|d
decl_stmt|;
name|void
name|detach
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENGLFRAMEBUFFEROBJECT_H
end_comment
end_unit
