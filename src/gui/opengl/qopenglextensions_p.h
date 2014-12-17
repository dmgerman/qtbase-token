begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGL_EXTENSIONS_P_H
end_ifndef
begin_define
DECL|macro|QOPENGL_EXTENSIONS_P_H
define|#
directive|define
name|QOPENGL_EXTENSIONS_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the Qt OpenGL classes.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qopenglfunctions.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qlibrary.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLExtensionsPrivate
name|class
name|QOpenGLExtensionsPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOpenGLES3Helper
block|{
name|public
label|:
name|QOpenGLES3Helper
argument_list|()
expr_stmt|;
name|GLvoid
modifier|*
function_decl|(
name|QOPENGLF_APIENTRYP
name|MapBufferRange
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|qopengl_GLintptr
name|offset
parameter_list|,
name|qopengl_GLsizeiptr
name|length
parameter_list|,
name|GLbitfield
name|access
parameter_list|)
function_decl|;
name|GLboolean
function_decl|(
name|QOPENGLF_APIENTRYP
name|UnmapBuffer
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|BlitFramebuffer
function_decl|)
parameter_list|(
name|GLint
name|srcX0
parameter_list|,
name|GLint
name|srcY0
parameter_list|,
name|GLint
name|srcX1
parameter_list|,
name|GLint
name|srcY1
parameter_list|,
name|GLint
name|dstX0
parameter_list|,
name|GLint
name|dstY0
parameter_list|,
name|GLint
name|dstX1
parameter_list|,
name|GLint
name|dstY1
parameter_list|,
name|GLbitfield
name|mask
parameter_list|,
name|GLenum
name|filter
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|RenderbufferStorageMultisample
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLsizei
name|samples
parameter_list|,
name|GLenum
name|internalFormat
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|GenVertexArrays
function_decl|)
parameter_list|(
name|GLsizei
name|n
parameter_list|,
name|GLuint
modifier|*
name|arrays
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|DeleteVertexArrays
function_decl|)
parameter_list|(
name|GLsizei
name|n
parameter_list|,
specifier|const
name|GLuint
modifier|*
name|arrays
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|BindVertexArray
function_decl|)
parameter_list|(
name|GLuint
name|array
parameter_list|)
function_decl|;
name|GLboolean
function_decl|(
name|QOPENGLF_APIENTRYP
name|IsVertexArray
function_decl|)
parameter_list|(
name|GLuint
name|array
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|TexImage3D
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLint
name|internalFormat
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLsizei
name|depth
parameter_list|,
name|GLint
name|border
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|pixels
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|TexSubImage3D
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLint
name|xoffset
parameter_list|,
name|GLint
name|yoffset
parameter_list|,
name|GLint
name|zoffset
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLsizei
name|depth
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|pixels
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|CompressedTexImage3D
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLenum
name|internalFormat
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLsizei
name|depth
parameter_list|,
name|GLint
name|border
parameter_list|,
name|GLsizei
name|imageSize
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|data
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|CompressedTexSubImage3D
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLint
name|xoffset
parameter_list|,
name|GLint
name|yoffset
parameter_list|,
name|GLint
name|zoffset
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLsizei
name|depth
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLsizei
name|imageSize
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|data
parameter_list|)
function_decl|;
name|private
label|:
name|QLibrary
name|m_gl
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLExtensions
range|:
name|public
name|QOpenGLFunctions
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLExtensions
argument_list|)
name|public
operator|:
name|QOpenGLExtensions
argument_list|()
block|;
name|QOpenGLExtensions
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
operator|~
name|QOpenGLExtensions
argument_list|()
block|{}
expr|enum
name|OpenGLExtension
block|{
name|TextureRectangle
operator|=
literal|0x00000001
block|,
name|GenerateMipmap
operator|=
literal|0x00000002
block|,
name|TextureCompression
operator|=
literal|0x00000004
block|,
name|MirroredRepeat
operator|=
literal|0x00000008
block|,
name|FramebufferMultisample
operator|=
literal|0x00000010
block|,
name|StencilTwoSide
operator|=
literal|0x00000020
block|,
name|StencilWrap
operator|=
literal|0x00000040
block|,
name|PackedDepthStencil
operator|=
literal|0x00000080
block|,
name|NVFloatBuffer
operator|=
literal|0x00000100
block|,
name|PixelBufferObject
operator|=
literal|0x00000200
block|,
name|FramebufferBlit
operator|=
literal|0x00000400
block|,
name|BGRATextureFormat
operator|=
literal|0x00000800
block|,
name|DDSTextureCompression
operator|=
literal|0x00001000
block|,
name|ETC1TextureCompression
operator|=
literal|0x00002000
block|,
name|PVRTCTextureCompression
operator|=
literal|0x00004000
block|,
name|ElementIndexUint
operator|=
literal|0x00008000
block|,
name|Depth24
operator|=
literal|0x00010000
block|,
name|SRGBFrameBuffer
operator|=
literal|0x00020000
block|,
name|MapBuffer
operator|=
literal|0x00040000
block|,
name|GeometryShaders
operator|=
literal|0x00080000
block|,
name|MapBufferRange
operator|=
literal|0x00100000
block|,
name|Sized8Formats
operator|=
literal|0x00200000
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|OpenGLExtensions
argument_list|,
argument|OpenGLExtension
argument_list|)
name|OpenGLExtensions
name|openGLExtensions
argument_list|()
block|;
name|bool
name|hasOpenGLExtension
argument_list|(
argument|QOpenGLExtensions::OpenGLExtension extension
argument_list|)
specifier|const
block|;
name|GLvoid
operator|*
name|glMapBuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum access
argument_list|)
block|;
name|GLvoid
operator|*
name|glMapBufferRange
argument_list|(
argument|GLenum target
argument_list|,
argument|qopengl_GLintptr offset
argument_list|,
argument|qopengl_GLsizeiptr length
argument_list|,
argument|GLbitfield access
argument_list|)
block|;
name|GLboolean
name|glUnmapBuffer
argument_list|(
argument|GLenum target
argument_list|)
block|;
name|void
name|glBlitFramebuffer
argument_list|(
argument|GLint srcX0
argument_list|,
argument|GLint srcY0
argument_list|,
argument|GLint srcX1
argument_list|,
argument|GLint srcY1
argument_list|,
argument|GLint dstX0
argument_list|,
argument|GLint dstY0
argument_list|,
argument|GLint dstX1
argument_list|,
argument|GLint dstY1
argument_list|,
argument|GLbitfield mask
argument_list|,
argument|GLenum filter
argument_list|)
block|;
name|void
name|glRenderbufferStorageMultisample
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei samples
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|void
name|glGetBufferSubData
argument_list|(
argument|GLenum target
argument_list|,
argument|qopengl_GLintptr offset
argument_list|,
argument|qopengl_GLsizeiptr size
argument_list|,
argument|GLvoid *data
argument_list|)
block|;
name|QOpenGLES3Helper
operator|*
name|gles3Helper
argument_list|()
block|;
name|private
operator|:
specifier|static
name|bool
name|isInitialized
argument_list|(
argument|const QOpenGLFunctionsPrivate *d
argument_list|)
block|{
return|return
name|d
operator|!=
literal|0
return|;
block|}
expr|}
block|;
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QOpenGLExtensions::OpenGLExtensions
argument_list|)
name|class
name|QOpenGLExtensionsPrivate
operator|:
name|public
name|QOpenGLFunctionsPrivate
block|{
name|public
operator|:
name|explicit
name|QOpenGLExtensionsPrivate
argument_list|(
name|QOpenGLContext
operator|*
name|ctx
argument_list|)
block|;
name|GLvoid
operator|*
operator|(
name|QOPENGLF_APIENTRYP
name|MapBuffer
operator|)
operator|(
name|GLenum
name|target
expr|,
name|GLenum
name|access
operator|)
block|;
name|GLvoid
operator|*
operator|(
name|QOPENGLF_APIENTRYP
name|MapBufferRange
operator|)
operator|(
name|GLenum
name|target
expr|,
name|qopengl_GLintptr
name|offset
expr|,
name|qopengl_GLsizeiptr
name|length
expr|,
name|GLbitfield
name|access
operator|)
block|;
name|GLboolean
argument_list|(
argument|QOPENGLF_APIENTRYP UnmapBuffer
argument_list|)
operator|(
name|GLenum
name|target
operator|)
block|;
name|void
argument_list|(
argument|QOPENGLF_APIENTRYP BlitFramebuffer
argument_list|)
operator|(
name|GLint
name|srcX0
expr|,
name|GLint
name|srcY0
expr|,
name|GLint
name|srcX1
expr|,
name|GLint
name|srcY1
expr|,
name|GLint
name|dstX0
expr|,
name|GLint
name|dstY0
expr|,
name|GLint
name|dstX1
expr|,
name|GLint
name|dstY1
expr|,
name|GLbitfield
name|mask
expr|,
name|GLenum
name|filter
operator|)
block|;
name|void
argument_list|(
argument|QOPENGLF_APIENTRYP RenderbufferStorageMultisample
argument_list|)
operator|(
name|GLenum
name|target
expr|,
name|GLsizei
name|samples
expr|,
name|GLenum
name|internalFormat
expr|,
name|GLsizei
name|width
expr|,
name|GLsizei
name|height
operator|)
block|;
name|void
argument_list|(
argument|QOPENGLF_APIENTRYP GetBufferSubData
argument_list|)
operator|(
name|GLenum
name|target
expr|,
name|qopengl_GLintptr
name|offset
expr|,
name|qopengl_GLsizeiptr
name|size
expr|,
name|GLvoid
operator|*
name|data
operator|)
block|; }
block|;
DECL|function|glMapBuffer
specifier|inline
name|GLvoid
operator|*
name|QOpenGLExtensions
operator|::
name|glMapBuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum access
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtensions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtensions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLvoid
operator|*
name|result
operator|=
name|d
operator|->
name|MapBuffer
argument_list|(
name|target
argument_list|,
name|access
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glMapBufferRange
specifier|inline
name|GLvoid
operator|*
name|QOpenGLExtensions
operator|::
name|glMapBufferRange
argument_list|(
argument|GLenum target
argument_list|,
argument|qopengl_GLintptr offset
argument_list|,
argument|qopengl_GLsizeiptr length
argument_list|,
argument|GLbitfield access
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtensions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtensions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLvoid
operator|*
name|result
operator|=
name|d
operator|->
name|MapBufferRange
argument_list|(
name|target
argument_list|,
name|offset
argument_list|,
name|length
argument_list|,
name|access
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glUnmapBuffer
specifier|inline
name|GLboolean
name|QOpenGLExtensions
operator|::
name|glUnmapBuffer
argument_list|(
argument|GLenum target
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtensions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtensions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|GLboolean
name|result
operator|=
name|d
operator|->
name|UnmapBuffer
argument_list|(
name|target
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
return|return
name|result
return|;
block|}
DECL|function|glBlitFramebuffer
specifier|inline
name|void
name|QOpenGLExtensions
operator|::
name|glBlitFramebuffer
argument_list|(
argument|GLint srcX0
argument_list|,
argument|GLint srcY0
argument_list|,
argument|GLint srcX1
argument_list|,
argument|GLint srcY1
argument_list|,
argument|GLint dstX0
argument_list|,
argument|GLint dstY0
argument_list|,
argument|GLint dstX1
argument_list|,
argument|GLint dstY1
argument_list|,
argument|GLbitfield mask
argument_list|,
argument|GLenum filter
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtensions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtensions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|BlitFramebuffer
argument_list|(
name|srcX0
argument_list|,
name|srcY0
argument_list|,
name|srcX1
argument_list|,
name|srcY1
argument_list|,
name|dstX0
argument_list|,
name|dstY0
argument_list|,
name|dstX1
argument_list|,
name|dstY1
argument_list|,
name|mask
argument_list|,
name|filter
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glRenderbufferStorageMultisample
specifier|inline
name|void
name|QOpenGLExtensions
operator|::
name|glRenderbufferStorageMultisample
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei samples
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtensions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtensions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|RenderbufferStorageMultisample
argument_list|(
name|target
argument_list|,
name|samples
argument_list|,
name|internalFormat
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
DECL|function|glGetBufferSubData
specifier|inline
name|void
name|QOpenGLExtensions
operator|::
name|glGetBufferSubData
argument_list|(
argument|GLenum target
argument_list|,
argument|qopengl_GLintptr offset
argument_list|,
argument|qopengl_GLsizeiptr size
argument_list|,
argument|GLvoid *data
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLExtensions
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|QOpenGLExtensions
operator|::
name|isInitialized
argument_list|(
name|d
argument_list|)
argument_list|)
block|;
name|d
operator|->
name|GetBufferSubData
argument_list|(
name|target
argument_list|,
name|offset
argument_list|,
name|size
argument_list|,
name|data
argument_list|)
block|;
name|Q_OPENGL_FUNCTIONS_DEBUG
block|}
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENGL_EXTENSIONS_P_H
end_comment
end_unit
