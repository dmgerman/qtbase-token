begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopengltextureblitter_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLBuffer>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLShaderProgram>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLVertexArrayObject>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFunctions>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|vertex_shader150
specifier|static
specifier|const
name|char
name|vertex_shader150
index|[]
init|=
literal|"#version 150 core\n"
literal|"in vec3 vertexCoord;"
literal|"in vec2 textureCoord;"
literal|"out vec2 uv;"
literal|"uniform mat4 vertexTransform;"
literal|"uniform mat3 textureTransform;"
literal|"void main() {"
literal|"   uv = (textureTransform * vec3(textureCoord,1.0)).xy;"
literal|"   gl_Position = vertexTransform * vec4(vertexCoord,1.0);"
literal|"}"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|fragment_shader150
specifier|static
specifier|const
name|char
name|fragment_shader150
index|[]
init|=
literal|"#version 150 core\n"
literal|"in vec2 uv;"
literal|"out vec4 fragcolor;"
literal|"uniform sampler2D textureSampler;"
literal|"uniform bool swizzle;"
literal|"void main() {"
literal|"   vec4 tmpFragColor = texture(textureSampler, uv);"
literal|"   fragcolor = swizzle ? tmpFragColor.bgra : tmpFragColor;"
literal|"}"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|vertex_shader
specifier|static
specifier|const
name|char
name|vertex_shader
index|[]
init|=
literal|"attribute highp vec3 vertexCoord;"
literal|"attribute highp vec2 textureCoord;"
literal|"varying highp vec2 uv;"
literal|"uniform highp mat4 vertexTransform;"
literal|"uniform highp mat3 textureTransform;"
literal|"void main() {"
literal|"   uv = (textureTransform * vec3(textureCoord,1.0)).xy;"
literal|"   gl_Position = vertexTransform * vec4(vertexCoord,1.0);"
literal|"}"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|fragment_shader
specifier|static
specifier|const
name|char
name|fragment_shader
index|[]
init|=
literal|"varying highp vec2 uv;"
literal|"uniform sampler2D textureSampler;"
literal|"uniform bool swizzle;"
literal|"void main() {"
literal|"   highp vec4 tmpFragColor = texture2D(textureSampler,uv);"
literal|"   gl_FragColor = swizzle ? tmpFragColor.bgra : tmpFragColor;"
literal|"}"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|vertex_buffer_data
specifier|static
specifier|const
name|GLfloat
name|vertex_buffer_data
index|[]
init|=
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|texture_buffer_data
specifier|static
specifier|const
name|GLfloat
name|texture_buffer_data
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|}
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|TextureBinder
class|class
name|TextureBinder
block|{
public|public:
DECL|function|TextureBinder
name|TextureBinder
parameter_list|(
name|GLuint
name|textureId
parameter_list|)
block|{
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|textureId
argument_list|)
expr_stmt|;
block|}
DECL|function|~TextureBinder
name|~
name|TextureBinder
parameter_list|()
block|{
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|QOpenGLTextureBlitterPrivate
class|class
name|QOpenGLTextureBlitterPrivate
block|{
public|public:
DECL|enum|TextureMatrixUniform
enum|enum
name|TextureMatrixUniform
block|{
DECL|enumerator|User
name|User
block|,
DECL|enumerator|Identity
name|Identity
block|,
DECL|enumerator|IdentityFlipped
name|IdentityFlipped
block|}
enum|;
DECL|function|QOpenGLTextureBlitterPrivate
name|QOpenGLTextureBlitterPrivate
parameter_list|()
member_init_list|:
name|program
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|vertexCoordAttribPos
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|vertexTransformUniformPos
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|textureCoordAttribPos
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|textureTransformUniformPos
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|swizzle
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|swizzleOld
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|textureMatrixUniformState
argument_list|(
name|User
argument_list|)
member_init_list|,
name|vao
argument_list|(
operator|new
name|QOpenGLVertexArrayObject
argument_list|()
argument_list|)
block|{ }
name|void
name|blit
parameter_list|(
name|GLuint
name|texture
parameter_list|,
specifier|const
name|QMatrix4x4
modifier|&
name|vertexTransform
parameter_list|,
specifier|const
name|QMatrix3x3
modifier|&
name|textureTransform
parameter_list|)
function_decl|;
name|void
name|blit
parameter_list|(
name|GLuint
name|texture
parameter_list|,
specifier|const
name|QMatrix4x4
modifier|&
name|vertexTransform
parameter_list|,
name|QOpenGLTextureBlitter
operator|::
name|Origin
name|origin
parameter_list|)
function_decl|;
DECL|function|prepareProgram
name|void
name|prepareProgram
parameter_list|(
specifier|const
name|QMatrix4x4
modifier|&
name|vertexTransform
parameter_list|)
block|{
name|vertexBuffer
operator|.
name|bind
argument_list|()
expr_stmt|;
name|program
operator|->
name|setAttributeBuffer
argument_list|(
name|vertexCoordAttribPos
argument_list|,
name|GL_FLOAT
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|program
operator|->
name|enableAttributeArray
argument_list|(
name|vertexCoordAttribPos
argument_list|)
expr_stmt|;
name|vertexBuffer
operator|.
name|release
argument_list|()
expr_stmt|;
name|program
operator|->
name|setUniformValue
argument_list|(
name|vertexTransformUniformPos
argument_list|,
name|vertexTransform
argument_list|)
expr_stmt|;
name|textureBuffer
operator|.
name|bind
argument_list|()
expr_stmt|;
name|program
operator|->
name|setAttributeBuffer
argument_list|(
name|textureCoordAttribPos
argument_list|,
name|GL_FLOAT
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|program
operator|->
name|enableAttributeArray
argument_list|(
name|textureCoordAttribPos
argument_list|)
expr_stmt|;
name|textureBuffer
operator|.
name|release
argument_list|()
expr_stmt|;
if|if
condition|(
name|swizzle
operator|!=
name|swizzleOld
condition|)
block|{
name|program
operator|->
name|setUniformValue
argument_list|(
name|swizzleUniformPos
argument_list|,
name|swizzle
argument_list|)
expr_stmt|;
name|swizzleOld
operator|=
name|swizzle
expr_stmt|;
block|}
block|}
DECL|member|vertexBuffer
name|QOpenGLBuffer
name|vertexBuffer
decl_stmt|;
DECL|member|textureBuffer
name|QOpenGLBuffer
name|textureBuffer
decl_stmt|;
DECL|member|program
name|QScopedPointer
argument_list|<
name|QOpenGLShaderProgram
argument_list|>
name|program
decl_stmt|;
DECL|member|vertexCoordAttribPos
name|GLuint
name|vertexCoordAttribPos
decl_stmt|;
DECL|member|vertexTransformUniformPos
name|GLuint
name|vertexTransformUniformPos
decl_stmt|;
DECL|member|textureCoordAttribPos
name|GLuint
name|textureCoordAttribPos
decl_stmt|;
DECL|member|textureTransformUniformPos
name|GLuint
name|textureTransformUniformPos
decl_stmt|;
DECL|member|swizzleUniformPos
name|GLuint
name|swizzleUniformPos
decl_stmt|;
DECL|member|swizzle
name|bool
name|swizzle
decl_stmt|;
DECL|member|swizzleOld
name|bool
name|swizzleOld
decl_stmt|;
DECL|member|textureMatrixUniformState
name|TextureMatrixUniform
name|textureMatrixUniformState
decl_stmt|;
DECL|member|vao
name|QScopedPointer
argument_list|<
name|QOpenGLVertexArrayObject
argument_list|>
name|vao
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|blit
name|void
name|QOpenGLTextureBlitterPrivate
operator|::
name|blit
parameter_list|(
name|GLuint
name|texture
parameter_list|,
specifier|const
name|QMatrix4x4
modifier|&
name|vertexTransform
parameter_list|,
specifier|const
name|QMatrix3x3
modifier|&
name|textureTransform
parameter_list|)
block|{
name|TextureBinder
name|binder
argument_list|(
name|texture
argument_list|)
decl_stmt|;
name|prepareProgram
argument_list|(
name|vertexTransform
argument_list|)
expr_stmt|;
name|program
operator|->
name|setUniformValue
argument_list|(
name|textureTransformUniformPos
argument_list|,
name|textureTransform
argument_list|)
expr_stmt|;
name|textureMatrixUniformState
operator|=
name|User
expr_stmt|;
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
operator|->
name|glDrawArrays
argument_list|(
name|GL_TRIANGLES
argument_list|,
literal|0
argument_list|,
literal|6
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|blit
name|void
name|QOpenGLTextureBlitterPrivate
operator|::
name|blit
parameter_list|(
name|GLuint
name|texture
parameter_list|,
specifier|const
name|QMatrix4x4
modifier|&
name|vertexTransform
parameter_list|,
name|QOpenGLTextureBlitter
operator|::
name|Origin
name|origin
parameter_list|)
block|{
name|TextureBinder
name|binder
argument_list|(
name|texture
argument_list|)
decl_stmt|;
name|prepareProgram
argument_list|(
name|vertexTransform
argument_list|)
expr_stmt|;
if|if
condition|(
name|origin
operator|==
name|QOpenGLTextureBlitter
operator|::
name|OriginTopLeft
condition|)
block|{
if|if
condition|(
name|textureMatrixUniformState
operator|!=
name|IdentityFlipped
condition|)
block|{
name|QMatrix3x3
name|flipped
decl_stmt|;
name|flipped
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
operator|=
operator|-
literal|1
expr_stmt|;
name|flipped
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
operator|=
literal|1
expr_stmt|;
name|program
operator|->
name|setUniformValue
argument_list|(
name|textureTransformUniformPos
argument_list|,
name|flipped
argument_list|)
expr_stmt|;
name|textureMatrixUniformState
operator|=
name|IdentityFlipped
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|textureMatrixUniformState
operator|!=
name|Identity
condition|)
block|{
name|program
operator|->
name|setUniformValue
argument_list|(
name|textureTransformUniformPos
argument_list|,
name|QMatrix3x3
argument_list|()
argument_list|)
expr_stmt|;
name|textureMatrixUniformState
operator|=
name|Identity
expr_stmt|;
block|}
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
operator|->
name|glDrawArrays
argument_list|(
name|GL_TRIANGLES
argument_list|,
literal|0
argument_list|,
literal|6
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QOpenGLTextureBlitter
name|QOpenGLTextureBlitter
operator|::
name|QOpenGLTextureBlitter
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QOpenGLTextureBlitterPrivate
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QOpenGLTextureBlitter
name|QOpenGLTextureBlitter
operator|::
name|~
name|QOpenGLTextureBlitter
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|create
name|bool
name|QOpenGLTextureBlitter
operator|::
name|create
parameter_list|()
block|{
name|QOpenGLContext
modifier|*
name|currentContext
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|currentContext
condition|)
return|return
literal|false
return|;
name|Q_D
argument_list|(
name|QOpenGLTextureBlitter
argument_list|)
expr_stmt|;
name|d
operator|->
name|vao
operator|->
name|create
argument_list|()
expr_stmt|;
name|d
operator|->
name|vao
operator|->
name|bind
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|program
condition|)
return|return
literal|true
return|;
name|d
operator|->
name|program
operator|.
name|reset
argument_list|(
operator|new
name|QOpenGLShaderProgram
argument_list|()
argument_list|)
expr_stmt|;
name|QSurfaceFormat
name|format
init|=
name|currentContext
operator|->
name|format
argument_list|()
decl_stmt|;
if|if
condition|(
name|format
operator|.
name|profile
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|CoreProfile
operator|&&
name|format
operator|.
name|version
argument_list|()
operator|>=
name|qMakePair
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|)
condition|)
block|{
name|d
operator|->
name|program
operator|->
name|addShaderFromSourceCode
argument_list|(
name|QOpenGLShader
operator|::
name|Vertex
argument_list|,
name|vertex_shader150
argument_list|)
expr_stmt|;
name|d
operator|->
name|program
operator|->
name|addShaderFromSourceCode
argument_list|(
name|QOpenGLShader
operator|::
name|Fragment
argument_list|,
name|fragment_shader150
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|program
operator|->
name|addShaderFromSourceCode
argument_list|(
name|QOpenGLShader
operator|::
name|Vertex
argument_list|,
name|vertex_shader
argument_list|)
expr_stmt|;
name|d
operator|->
name|program
operator|->
name|addShaderFromSourceCode
argument_list|(
name|QOpenGLShader
operator|::
name|Fragment
argument_list|,
name|fragment_shader
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|program
operator|->
name|link
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|program
operator|->
name|isLinked
argument_list|()
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Could not link shader program:\n"
operator|<<
name|d
operator|->
name|program
operator|->
name|log
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
name|d
operator|->
name|program
operator|->
name|bind
argument_list|()
expr_stmt|;
name|d
operator|->
name|vertexBuffer
operator|.
name|create
argument_list|()
expr_stmt|;
name|d
operator|->
name|vertexBuffer
operator|.
name|bind
argument_list|()
expr_stmt|;
name|d
operator|->
name|vertexBuffer
operator|.
name|allocate
argument_list|(
name|vertex_buffer_data
argument_list|,
sizeof|sizeof
argument_list|(
name|vertex_buffer_data
argument_list|)
operator|*
sizeof|sizeof
argument_list|(
name|vertex_buffer_data
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|vertexBuffer
operator|.
name|release
argument_list|()
expr_stmt|;
name|d
operator|->
name|textureBuffer
operator|.
name|create
argument_list|()
expr_stmt|;
name|d
operator|->
name|textureBuffer
operator|.
name|bind
argument_list|()
expr_stmt|;
name|d
operator|->
name|textureBuffer
operator|.
name|allocate
argument_list|(
name|texture_buffer_data
argument_list|,
sizeof|sizeof
argument_list|(
name|texture_buffer_data
argument_list|)
operator|*
sizeof|sizeof
argument_list|(
name|texture_buffer_data
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|textureBuffer
operator|.
name|release
argument_list|()
expr_stmt|;
name|d
operator|->
name|vertexCoordAttribPos
operator|=
name|d
operator|->
name|program
operator|->
name|attributeLocation
argument_list|(
literal|"vertexCoord"
argument_list|)
expr_stmt|;
name|d
operator|->
name|vertexTransformUniformPos
operator|=
name|d
operator|->
name|program
operator|->
name|uniformLocation
argument_list|(
literal|"vertexTransform"
argument_list|)
expr_stmt|;
name|d
operator|->
name|textureCoordAttribPos
operator|=
name|d
operator|->
name|program
operator|->
name|attributeLocation
argument_list|(
literal|"textureCoord"
argument_list|)
expr_stmt|;
name|d
operator|->
name|textureTransformUniformPos
operator|=
name|d
operator|->
name|program
operator|->
name|uniformLocation
argument_list|(
literal|"textureTransform"
argument_list|)
expr_stmt|;
name|d
operator|->
name|swizzleUniformPos
operator|=
name|d
operator|->
name|program
operator|->
name|uniformLocation
argument_list|(
literal|"swizzle"
argument_list|)
expr_stmt|;
name|d
operator|->
name|program
operator|->
name|setUniformValue
argument_list|(
name|d
operator|->
name|swizzleUniformPos
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|d
operator|->
name|vao
operator|->
name|release
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|isCreated
name|bool
name|QOpenGLTextureBlitter
operator|::
name|isCreated
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOpenGLTextureBlitter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|program
return|;
block|}
end_function
begin_function
DECL|function|destroy
name|void
name|QOpenGLTextureBlitter
operator|::
name|destroy
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLTextureBlitter
argument_list|)
expr_stmt|;
name|d
operator|->
name|program
operator|.
name|reset
argument_list|()
expr_stmt|;
name|d
operator|->
name|vertexBuffer
operator|.
name|destroy
argument_list|()
expr_stmt|;
name|d
operator|->
name|textureBuffer
operator|.
name|destroy
argument_list|()
expr_stmt|;
name|d
operator|->
name|vao
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bind
name|void
name|QOpenGLTextureBlitter
operator|::
name|bind
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLTextureBlitter
argument_list|)
expr_stmt|;
name|d
operator|->
name|vao
operator|->
name|bind
argument_list|()
expr_stmt|;
name|d
operator|->
name|program
operator|->
name|bind
argument_list|()
expr_stmt|;
name|d
operator|->
name|vertexBuffer
operator|.
name|bind
argument_list|()
expr_stmt|;
name|d
operator|->
name|program
operator|->
name|setAttributeBuffer
argument_list|(
name|d
operator|->
name|vertexCoordAttribPos
argument_list|,
name|GL_FLOAT
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|program
operator|->
name|enableAttributeArray
argument_list|(
name|d
operator|->
name|vertexCoordAttribPos
argument_list|)
expr_stmt|;
name|d
operator|->
name|vertexBuffer
operator|.
name|release
argument_list|()
expr_stmt|;
name|d
operator|->
name|textureBuffer
operator|.
name|bind
argument_list|()
expr_stmt|;
name|d
operator|->
name|program
operator|->
name|setAttributeBuffer
argument_list|(
name|d
operator|->
name|textureCoordAttribPos
argument_list|,
name|GL_FLOAT
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|program
operator|->
name|enableAttributeArray
argument_list|(
name|d
operator|->
name|textureCoordAttribPos
argument_list|)
expr_stmt|;
name|d
operator|->
name|textureBuffer
operator|.
name|release
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|release
name|void
name|QOpenGLTextureBlitter
operator|::
name|release
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLTextureBlitter
argument_list|)
expr_stmt|;
name|d
operator|->
name|program
operator|->
name|release
argument_list|()
expr_stmt|;
name|d
operator|->
name|vao
operator|->
name|release
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setSwizzleRB
name|void
name|QOpenGLTextureBlitter
operator|::
name|setSwizzleRB
parameter_list|(
name|bool
name|swizzle
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLTextureBlitter
argument_list|)
expr_stmt|;
name|d
operator|->
name|swizzle
operator|=
name|swizzle
expr_stmt|;
block|}
end_function
begin_function
DECL|function|blit
name|void
name|QOpenGLTextureBlitter
operator|::
name|blit
parameter_list|(
name|GLuint
name|texture
parameter_list|,
specifier|const
name|QMatrix4x4
modifier|&
name|targetTransform
parameter_list|,
name|Origin
name|sourceOrigin
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLTextureBlitter
argument_list|)
expr_stmt|;
name|d
operator|->
name|blit
argument_list|(
name|texture
argument_list|,
name|targetTransform
argument_list|,
name|sourceOrigin
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|blit
name|void
name|QOpenGLTextureBlitter
operator|::
name|blit
parameter_list|(
name|GLuint
name|texture
parameter_list|,
specifier|const
name|QMatrix4x4
modifier|&
name|targetTransform
parameter_list|,
specifier|const
name|QMatrix3x3
modifier|&
name|sourceTransform
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLTextureBlitter
argument_list|)
expr_stmt|;
name|d
operator|->
name|blit
argument_list|(
name|texture
argument_list|,
name|targetTransform
argument_list|,
name|sourceTransform
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|targetTransform
name|QMatrix4x4
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|target
parameter_list|,
specifier|const
name|QRect
modifier|&
name|viewport
parameter_list|)
block|{
name|qreal
name|x_scale
init|=
name|target
operator|.
name|width
argument_list|()
operator|/
name|viewport
operator|.
name|width
argument_list|()
decl_stmt|;
name|qreal
name|y_scale
init|=
name|target
operator|.
name|height
argument_list|()
operator|/
name|viewport
operator|.
name|height
argument_list|()
decl_stmt|;
specifier|const
name|QPointF
name|relative_to_viewport
init|=
name|target
operator|.
name|topLeft
argument_list|()
operator|-
name|viewport
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|qreal
name|x_translate
init|=
name|x_scale
operator|-
literal|1
operator|+
operator|(
operator|(
name|relative_to_viewport
operator|.
name|x
argument_list|()
operator|/
name|viewport
operator|.
name|width
argument_list|()
operator|)
operator|*
literal|2
operator|)
decl_stmt|;
name|qreal
name|y_translate
init|=
operator|-
name|y_scale
operator|+
literal|1
operator|-
operator|(
operator|(
name|relative_to_viewport
operator|.
name|y
argument_list|()
operator|/
name|viewport
operator|.
name|height
argument_list|()
operator|)
operator|*
literal|2
operator|)
decl_stmt|;
name|QMatrix4x4
name|matrix
decl_stmt|;
name|matrix
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|)
operator|=
name|x_translate
expr_stmt|;
name|matrix
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|)
operator|=
name|y_translate
expr_stmt|;
name|matrix
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|=
name|x_scale
expr_stmt|;
name|matrix
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
operator|=
name|y_scale
expr_stmt|;
return|return
name|matrix
return|;
block|}
end_function
begin_function
DECL|function|sourceTransform
name|QMatrix3x3
name|QOpenGLTextureBlitter
operator|::
name|sourceTransform
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|subTexture
parameter_list|,
specifier|const
name|QSize
modifier|&
name|textureSize
parameter_list|,
name|Origin
name|origin
parameter_list|)
block|{
name|qreal
name|x_scale
init|=
name|subTexture
operator|.
name|width
argument_list|()
operator|/
name|textureSize
operator|.
name|width
argument_list|()
decl_stmt|;
name|qreal
name|y_scale
init|=
name|subTexture
operator|.
name|height
argument_list|()
operator|/
name|textureSize
operator|.
name|height
argument_list|()
decl_stmt|;
specifier|const
name|QPointF
name|topLeft
init|=
name|subTexture
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|qreal
name|x_translate
init|=
name|topLeft
operator|.
name|x
argument_list|()
operator|/
name|textureSize
operator|.
name|width
argument_list|()
decl_stmt|;
name|qreal
name|y_translate
init|=
name|topLeft
operator|.
name|y
argument_list|()
operator|/
name|textureSize
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
name|origin
operator|==
name|OriginTopLeft
condition|)
block|{
name|y_scale
operator|=
operator|-
name|y_scale
expr_stmt|;
name|y_translate
operator|=
literal|1
operator|-
name|y_translate
expr_stmt|;
block|}
name|QMatrix3x3
name|matrix
decl_stmt|;
name|matrix
argument_list|(
literal|0
argument_list|,
literal|2
argument_list|)
operator|=
name|x_translate
expr_stmt|;
name|matrix
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
operator|=
name|y_translate
expr_stmt|;
name|matrix
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|=
name|x_scale
expr_stmt|;
name|matrix
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
operator|=
name|y_scale
expr_stmt|;
return|return
name|matrix
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
