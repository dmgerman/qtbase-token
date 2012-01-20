begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GLBUFFERS_H
end_ifndef
begin_define
DECL|macro|GLBUFFERS_H
define|#
directive|define
name|GLBUFFERS_H
end_define
begin_comment
comment|//#include<GL/glew.h>
end_comment
begin_include
include|#
directive|include
file|"glextensions.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL>
end_include
begin_define
DECL|macro|BUFFER_OFFSET
define|#
directive|define
name|BUFFER_OFFSET
parameter_list|(
name|i
parameter_list|)
value|((char*)0 + (i))
end_define
begin_define
DECL|macro|SIZE_OF_MEMBER
define|#
directive|define
name|SIZE_OF_MEMBER
parameter_list|(
name|cls
parameter_list|,
name|member
parameter_list|)
value|sizeof(static_cast<cls *>(0)->member)
end_define
begin_define
DECL|macro|GLBUFFERS_ASSERT_OPENGL
define|#
directive|define
name|GLBUFFERS_ASSERT_OPENGL
parameter_list|(
name|prefix
parameter_list|,
name|assertion
parameter_list|,
name|returnStatement
parameter_list|)
define|\
value|if (m_failed || !(assertion)) {                                                             \     if (!m_failed) qCritical(prefix ": The necessary OpenGL functions are not available."); \     m_failed = true;                                                                        \     returnStatement;                                                                        \ }
end_define
begin_function_decl
name|void
name|qgluPerspective
parameter_list|(
name|GLdouble
name|fovy
parameter_list|,
name|GLdouble
name|aspect
parameter_list|,
name|GLdouble
name|zNear
parameter_list|,
name|GLdouble
name|zFar
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMatrix4x4
name|class
name|QMatrix4x4
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|GLTexture
block|{
name|public
label|:
name|GLTexture
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|GLTexture
argument_list|()
expr_stmt|;
name|virtual
name|void
name|bind
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|unbind
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|failed
argument_list|()
specifier|const
block|{
return|return
name|m_failed
return|;
block|}
name|protected
label|:
name|GLuint
name|m_texture
decl_stmt|;
name|bool
name|m_failed
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|GLFrameBufferObject
block|{
name|public
label|:
name|friend
name|class
name|GLRenderTargetCube
decl_stmt|;
comment|// friend class GLRenderTarget2D;
name|GLFrameBufferObject
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|GLFrameBufferObject
argument_list|()
expr_stmt|;
name|bool
name|isComplete
parameter_list|()
function_decl|;
name|virtual
name|bool
name|failed
argument_list|()
specifier|const
block|{
return|return
name|m_failed
return|;
block|}
name|protected
label|:
name|void
name|setAsRenderTarget
parameter_list|(
name|bool
name|state
init|=
name|true
parameter_list|)
function_decl|;
name|GLuint
name|m_fbo
decl_stmt|;
name|GLuint
name|m_depthBuffer
decl_stmt|;
name|int
name|m_width
decl_stmt|,
name|m_height
decl_stmt|;
name|bool
name|m_failed
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|GLTexture2D
range|:
name|public
name|GLTexture
block|{
name|public
operator|:
name|GLTexture2D
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|GLTexture2D
argument_list|(
argument|const QString& fileName
argument_list|,
argument|int width =
literal|0
argument_list|,
argument|int height =
literal|0
argument_list|)
block|;
name|void
name|load
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|QRgb *data
argument_list|)
block|;
name|virtual
name|void
name|bind
argument_list|()
block|;
name|virtual
name|void
name|unbind
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|GLTexture3D
range|:
name|public
name|GLTexture
block|{
name|public
operator|:
name|GLTexture3D
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int depth
argument_list|)
block|;
comment|// TODO: Implement function below
comment|//GLTexture3D(const QString& fileName, int width = 0, int height = 0);
name|void
name|load
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int depth
argument_list|,
argument|QRgb *data
argument_list|)
block|;
name|virtual
name|void
name|bind
argument_list|()
block|;
name|virtual
name|void
name|unbind
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|GLTextureCube
range|:
name|public
name|GLTexture
block|{
name|public
operator|:
name|GLTextureCube
argument_list|(
argument|int size
argument_list|)
block|;
name|GLTextureCube
argument_list|(
argument|const QStringList& fileNames
argument_list|,
argument|int size =
literal|0
argument_list|)
block|;
name|void
name|load
argument_list|(
argument|int size
argument_list|,
argument|int face
argument_list|,
argument|QRgb *data
argument_list|)
block|;
name|virtual
name|void
name|bind
argument_list|()
block|;
name|virtual
name|void
name|unbind
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// TODO: Define and implement class below
end_comment
begin_comment
comment|//class GLRenderTarget2D : public GLTexture2D
end_comment
begin_decl_stmt
name|class
name|GLRenderTargetCube
range|:
name|public
name|GLTextureCube
block|{
name|public
operator|:
name|GLRenderTargetCube
argument_list|(
argument|int size
argument_list|)
block|;
comment|// begin rendering to one of the cube's faces. 0<= face< 6
name|void
name|begin
argument_list|(
argument|int face
argument_list|)
block|;
comment|// end rendering
name|void
name|end
argument_list|()
block|;
name|virtual
name|bool
name|failed
argument_list|()
specifier|const
block|{
return|return
name|m_failed
operator|||
name|m_fbo
operator|.
name|failed
argument_list|()
return|;
block|}
specifier|static
name|void
name|getViewMatrix
argument_list|(
argument|QMatrix4x4& mat
argument_list|,
argument|int face
argument_list|)
block|;
specifier|static
name|void
name|getProjectionMatrix
argument_list|(
argument|QMatrix4x4& mat
argument_list|,
argument|float nearZ
argument_list|,
argument|float farZ
argument_list|)
block|;
name|private
operator|:
name|GLFrameBufferObject
name|m_fbo
block|; }
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|VertexDescription
struct|struct
name|VertexDescription
block|{
enum|enum
block|{
DECL|enumerator|Null
name|Null
init|=
literal|0
block|,
comment|// Terminates a VertexDescription array
DECL|enumerator|Position
name|Position
block|,
DECL|enumerator|TexCoord
name|TexCoord
block|,
DECL|enumerator|Normal
name|Normal
block|,
DECL|enumerator|Color
name|Color
block|,     }
enum|;
DECL|member|field
name|int
name|field
decl_stmt|;
comment|// Position, TexCoord, Normal, Color
DECL|member|type
name|int
name|type
decl_stmt|;
comment|// GL_FLOAT, GL_UNSIGNED_BYTE
DECL|member|count
name|int
name|count
decl_stmt|;
comment|// number of elements
DECL|member|offset
name|int
name|offset
decl_stmt|;
comment|// field's offset into vertex struct
DECL|member|index
name|int
name|index
decl_stmt|;
comment|// 0 (unused at the moment)
block|}
struct|;
end_struct
begin_comment
comment|// Implementation of interleaved buffers.
end_comment
begin_comment
comment|// 'T' is a struct which must include a null-terminated static array
end_comment
begin_comment
comment|// 'VertexDescription* description'.
end_comment
begin_comment
comment|// Example:
end_comment
begin_comment
comment|/* struct Vertex {     GLfloat position[3];     GLfloat texCoord[2];     GLfloat normal[3];     GLbyte color[4];     static VertexDescription description[]; };  VertexDescription Vertex::description[] = {     {VertexDescription::Position, GL_FLOAT, SIZE_OF_MEMBER(Vertex, position) / sizeof(GLfloat), offsetof(Vertex, position), 0},     {VertexDescription::TexCoord, GL_FLOAT, SIZE_OF_MEMBER(Vertex, texCoord) / sizeof(GLfloat), offsetof(Vertex, texCoord), 0},     {VertexDescription::Normal, GL_FLOAT, SIZE_OF_MEMBER(Vertex, normal) / sizeof(GLfloat), offsetof(Vertex, normal), 0},     {VertexDescription::Color, GL_BYTE, SIZE_OF_MEMBER(Vertex, color) / sizeof(GLbyte), offsetof(Vertex, color), 0},     {VertexDescription::Null, 0, 0, 0, 0}, }; */
end_comment
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|GLVertexBuffer
block|{
name|public
operator|:
name|GLVertexBuffer
argument_list|(
argument|int length
argument_list|,
argument|const T *data =
literal|0
argument_list|,
argument|int mode = GL_STATIC_DRAW
argument_list|)
operator|:
name|m_length
argument_list|(
literal|0
argument_list|)
block|,
name|m_mode
argument_list|(
name|mode
argument_list|)
block|,
name|m_buffer
argument_list|(
literal|0
argument_list|)
block|,
name|m_failed
argument_list|(
argument|false
argument_list|)
block|{
name|GLBUFFERS_ASSERT_OPENGL
argument_list|(
literal|"GLVertexBuffer::GLVertexBuffer"
argument_list|,
argument|glGenBuffers&& glBindBuffer&& glBufferData
argument_list|,
argument|return
argument_list|)
name|glGenBuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|m_buffer
argument_list|)
block|;
name|glBindBuffer
argument_list|(
name|GL_ARRAY_BUFFER
argument_list|,
name|m_buffer
argument_list|)
block|;
name|glBufferData
argument_list|(
name|GL_ARRAY_BUFFER
argument_list|,
operator|(
name|m_length
operator|=
name|length
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|data
argument_list|,
name|mode
argument_list|)
block|;     }
operator|~
name|GLVertexBuffer
argument_list|()
block|{
name|GLBUFFERS_ASSERT_OPENGL
argument_list|(
literal|"GLVertexBuffer::~GLVertexBuffer"
argument_list|,
argument|glDeleteBuffers
argument_list|,
argument|return
argument_list|)
name|glDeleteBuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|m_buffer
argument_list|)
block|;     }
name|void
name|bind
argument_list|()
block|{
name|GLBUFFERS_ASSERT_OPENGL
argument_list|(
literal|"GLVertexBuffer::bind"
argument_list|,
argument|glBindBuffer
argument_list|,
argument|return
argument_list|)
name|glBindBuffer
argument_list|(
name|GL_ARRAY_BUFFER
argument_list|,
name|m_buffer
argument_list|)
block|;
for|for
control|(
name|VertexDescription
modifier|*
name|desc
init|=
name|T
operator|::
name|description
init|;
name|desc
operator|->
name|field
operator|!=
name|VertexDescription
operator|::
name|Null
condition|;
operator|++
name|desc
control|)
block|{
switch|switch
condition|(
name|desc
operator|->
name|field
condition|)
block|{
case|case
name|VertexDescription
operator|::
name|Position
case|:
name|glVertexPointer
argument_list|(
name|desc
operator|->
name|count
argument_list|,
name|desc
operator|->
name|type
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|BUFFER_OFFSET
argument_list|(
name|desc
operator|->
name|offset
argument_list|)
argument_list|)
expr_stmt|;
name|glEnableClientState
argument_list|(
name|GL_VERTEX_ARRAY
argument_list|)
expr_stmt|;
break|break;
case|case
name|VertexDescription
operator|::
name|TexCoord
case|:
name|glTexCoordPointer
argument_list|(
name|desc
operator|->
name|count
argument_list|,
name|desc
operator|->
name|type
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|BUFFER_OFFSET
argument_list|(
name|desc
operator|->
name|offset
argument_list|)
argument_list|)
expr_stmt|;
name|glEnableClientState
argument_list|(
name|GL_TEXTURE_COORD_ARRAY
argument_list|)
expr_stmt|;
break|break;
case|case
name|VertexDescription
operator|::
name|Normal
case|:
name|glNormalPointer
argument_list|(
name|desc
operator|->
name|type
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|BUFFER_OFFSET
argument_list|(
name|desc
operator|->
name|offset
argument_list|)
argument_list|)
expr_stmt|;
name|glEnableClientState
argument_list|(
name|GL_NORMAL_ARRAY
argument_list|)
expr_stmt|;
break|break;
case|case
name|VertexDescription
operator|::
name|Color
case|:
name|glColorPointer
argument_list|(
name|desc
operator|->
name|count
argument_list|,
name|desc
operator|->
name|type
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|BUFFER_OFFSET
argument_list|(
name|desc
operator|->
name|offset
argument_list|)
argument_list|)
expr_stmt|;
name|glEnableClientState
argument_list|(
name|GL_COLOR_ARRAY
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_expr_stmt
begin_macro
unit|}      void
name|unbind
argument_list|()
end_macro
begin_block
block|{
name|GLBUFFERS_ASSERT_OPENGL
argument_list|(
literal|"GLVertexBuffer::unbind"
argument_list|,
argument|glBindBuffer
argument_list|,
argument|return
argument_list|)
name|glBindBuffer
argument_list|(
name|GL_ARRAY_BUFFER
argument_list|,
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|VertexDescription
modifier|*
name|desc
init|=
name|T
operator|::
name|description
init|;
name|desc
operator|->
name|field
operator|!=
name|VertexDescription
operator|::
name|Null
condition|;
operator|++
name|desc
control|)
block|{
switch|switch
condition|(
name|desc
operator|->
name|field
condition|)
block|{
case|case
name|VertexDescription
operator|::
name|Position
case|:
name|glDisableClientState
argument_list|(
name|GL_VERTEX_ARRAY
argument_list|)
expr_stmt|;
break|break;
case|case
name|VertexDescription
operator|::
name|TexCoord
case|:
name|glDisableClientState
argument_list|(
name|GL_TEXTURE_COORD_ARRAY
argument_list|)
expr_stmt|;
break|break;
case|case
name|VertexDescription
operator|::
name|Normal
case|:
name|glDisableClientState
argument_list|(
name|GL_NORMAL_ARRAY
argument_list|)
expr_stmt|;
break|break;
case|case
name|VertexDescription
operator|::
name|Color
case|:
name|glDisableClientState
argument_list|(
name|GL_COLOR_ARRAY
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
block|}
end_block
begin_expr_stmt
name|int
name|length
argument_list|()
specifier|const
block|{
return|return
name|m_length
return|;
block|}
end_expr_stmt
begin_function
name|T
modifier|*
name|lock
parameter_list|()
block|{
name|GLBUFFERS_ASSERT_OPENGL
argument_list|(
literal|"GLVertexBuffer::lock"
argument_list|,
argument|glBindBuffer&& glMapBuffer
argument_list|,
argument|return
literal|0
argument_list|)
name|glBindBuffer
argument_list|(
name|GL_ARRAY_BUFFER
argument_list|,
name|m_buffer
argument_list|)
expr_stmt|;
comment|//glBufferData(GL_ARRAY_BUFFER, m_length, NULL, m_mode);
name|GLvoid
modifier|*
name|buffer
init|=
name|glMapBuffer
argument_list|(
name|GL_ARRAY_BUFFER
argument_list|,
name|GL_READ_WRITE
argument_list|)
decl_stmt|;
name|m_failed
operator|=
operator|(
name|buffer
operator|==
literal|0
operator|)
expr_stmt|;
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|buffer
operator|)
return|;
block|}
end_function
begin_function
name|void
name|unlock
parameter_list|()
block|{
name|GLBUFFERS_ASSERT_OPENGL
argument_list|(
literal|"GLVertexBuffer::unlock"
argument_list|,
argument|glBindBuffer&& glUnmapBuffer
argument_list|,
argument|return
argument_list|)
name|glBindBuffer
argument_list|(
name|GL_ARRAY_BUFFER
argument_list|,
name|m_buffer
argument_list|)
expr_stmt|;
name|glUnmapBuffer
argument_list|(
name|GL_ARRAY_BUFFER
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|bool
name|failed
parameter_list|()
block|{
return|return
name|m_failed
return|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|int
name|m_length
decl_stmt|,
name|m_mode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|GLuint
name|m_buffer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_failed
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|>
name|class
name|GLIndexBuffer
block|{
name|public
operator|:
name|GLIndexBuffer
argument_list|(
argument|int length
argument_list|,
argument|const T *data =
literal|0
argument_list|,
argument|int mode = GL_STATIC_DRAW
argument_list|)
operator|:
name|m_length
argument_list|(
literal|0
argument_list|)
block|,
name|m_mode
argument_list|(
name|mode
argument_list|)
block|,
name|m_buffer
argument_list|(
literal|0
argument_list|)
block|,
name|m_failed
argument_list|(
argument|false
argument_list|)
block|{
name|GLBUFFERS_ASSERT_OPENGL
argument_list|(
literal|"GLIndexBuffer::GLIndexBuffer"
argument_list|,
argument|glGenBuffers&& glBindBuffer&& glBufferData
argument_list|,
argument|return
argument_list|)
name|glGenBuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|m_buffer
argument_list|)
block|;
name|glBindBuffer
argument_list|(
name|GL_ELEMENT_ARRAY_BUFFER
argument_list|,
name|m_buffer
argument_list|)
block|;
name|glBufferData
argument_list|(
name|GL_ELEMENT_ARRAY_BUFFER
argument_list|,
operator|(
name|m_length
operator|=
name|length
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|data
argument_list|,
name|mode
argument_list|)
block|;     }
operator|~
name|GLIndexBuffer
argument_list|()
block|{
name|GLBUFFERS_ASSERT_OPENGL
argument_list|(
literal|"GLIndexBuffer::~GLIndexBuffer"
argument_list|,
argument|glDeleteBuffers
argument_list|,
argument|return
argument_list|)
name|glDeleteBuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|m_buffer
argument_list|)
block|;     }
name|void
name|bind
argument_list|()
block|{
name|GLBUFFERS_ASSERT_OPENGL
argument_list|(
literal|"GLIndexBuffer::bind"
argument_list|,
argument|glBindBuffer
argument_list|,
argument|return
argument_list|)
name|glBindBuffer
argument_list|(
name|GL_ELEMENT_ARRAY_BUFFER
argument_list|,
name|m_buffer
argument_list|)
block|;     }
name|void
name|unbind
argument_list|()
block|{
name|GLBUFFERS_ASSERT_OPENGL
argument_list|(
literal|"GLIndexBuffer::unbind"
argument_list|,
argument|glBindBuffer
argument_list|,
argument|return
argument_list|)
name|glBindBuffer
argument_list|(
name|GL_ELEMENT_ARRAY_BUFFER
argument_list|,
literal|0
argument_list|)
block|;     }
name|int
name|length
argument_list|()
specifier|const
block|{
return|return
name|m_length
return|;
block|}
name|T
operator|*
name|lock
argument_list|()
block|{
name|GLBUFFERS_ASSERT_OPENGL
argument_list|(
literal|"GLIndexBuffer::lock"
argument_list|,
argument|glBindBuffer&& glMapBuffer
argument_list|,
argument|return
literal|0
argument_list|)
name|glBindBuffer
argument_list|(
name|GL_ELEMENT_ARRAY_BUFFER
argument_list|,
name|m_buffer
argument_list|)
block|;
name|GLvoid
operator|*
name|buffer
operator|=
name|glMapBuffer
argument_list|(
name|GL_ELEMENT_ARRAY_BUFFER
argument_list|,
name|GL_READ_WRITE
argument_list|)
block|;
name|m_failed
operator|=
operator|(
name|buffer
operator|==
literal|0
operator|)
block|;
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|buffer
operator|)
return|;
block|}
end_expr_stmt
begin_function
name|void
name|unlock
parameter_list|()
block|{
name|GLBUFFERS_ASSERT_OPENGL
argument_list|(
literal|"GLIndexBuffer::unlock"
argument_list|,
argument|glBindBuffer&& glUnmapBuffer
argument_list|,
argument|return
argument_list|)
name|glBindBuffer
argument_list|(
name|GL_ELEMENT_ARRAY_BUFFER
argument_list|,
name|m_buffer
argument_list|)
expr_stmt|;
name|glUnmapBuffer
argument_list|(
name|GL_ELEMENT_ARRAY_BUFFER
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|bool
name|failed
parameter_list|()
block|{
return|return
name|m_failed
return|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|int
name|m_length
decl_stmt|,
name|m_mode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|GLuint
name|m_buffer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_failed
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
end_unit
