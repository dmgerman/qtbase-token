begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_class
DECL|class|MyGLWidget
class|class
name|MyGLWidget
super|:
specifier|public
name|QOpenGLWidget
block|{
public|public:
DECL|function|MyGLWidget
name|MyGLWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QOpenGLWidget
argument_list|(
name|parent
argument_list|)
block|{ }
protected|protected:
DECL|function|initializeGL
name|void
name|initializeGL
parameter_list|()
block|{
comment|// Set up the rendering context, load shaders and other resources, etc.:
name|QOpenGLFunctions
modifier|*
name|f
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
decl_stmt|;
name|f
operator|->
name|glClearColor
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
operator|...
block|}
DECL|function|resizeGL
name|void
name|resizeGL
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
comment|// Update projection matrix and other size related settings:
name|m_projection
operator|.
name|setToIdentity
argument_list|()
expr_stmt|;
name|m_projection
operator|.
name|perspective
argument_list|(
literal|45.0f
argument_list|,
name|w
operator|/
name|float
argument_list|(
name|h
argument_list|)
argument_list|,
literal|0.01f
argument_list|,
literal|100.0f
argument_list|)
expr_stmt|;
operator|...
block|}
DECL|function|paintGL
name|void
name|paintGL
parameter_list|()
block|{
comment|// Draw the scene:
name|QOpenGLFunctions
modifier|*
name|f
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
decl_stmt|;
name|f
operator|->
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
operator|...
block|}
block|}
class|;
end_class
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_class
DECL|class|MyGLWidget
class|class
name|MyGLWidget
super|:
specifier|public
name|QOpenGLWidget
super|,
specifier|protected
name|QOpenGLFunctions
block|{
operator|...
DECL|function|initializeGL
name|void
name|initializeGL
argument_list|()
block|{
name|initializeOpenGLFunctions
argument_list|()
block|;
name|glClearColor
argument_list|(
operator|...
argument_list|)
block|;
operator|...
block|}
operator|...
block|}
class|;
end_class
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|widget
name|QOpenGLWidget
modifier|*
name|widget
init|=
operator|new
name|QOpenGLWidget
argument_list|(
name|parent
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|format
name|QSurfaceFormat
name|format
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|format
operator|.
name|setDepthBufferSize
argument_list|(
literal|24
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|format
operator|.
name|setStencilBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|format
operator|.
name|setVersion
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|format
operator|.
name|setProfile
argument_list|(
name|QSurfaceFormat
operator|::
name|CoreProfile
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|widget
operator|->
name|setFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// must be called before the widget or its parent window gets shown
end_comment
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_expr_stmt
operator|...
DECL|function|paintGL
name|void
name|paintGL
argument_list|()
block|{
name|QOpenGLFunctions_3_2_Core
operator|*
name|f
operator|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|versionFunctions
argument_list|<
name|QOpenGLFunctions_3_2_Core
argument_list|>
argument_list|()
block|;
operator|...
name|f
operator|->
name|glDrawArraysInstanced
argument_list|(
operator|...
argument_list|)
block|;
operator|...
block|}
operator|...
comment|//! [3]
comment|//! [4]
DECL|class|MyGLWidget
name|class
name|MyGLWidget
operator|:
specifier|public
name|QOpenGLWidget
block|{
operator|...
specifier|private
operator|:
DECL|member|m_vao
name|QOpenGLVertexArrayObject
name|m_vao
block|;
DECL|member|m_vbo
name|QOpenGLBuffer
name|m_vbo
block|;
DECL|member|m_program
name|QOpenGLShaderProgram
operator|*
name|m_program
block|;
DECL|member|m_shader
name|QOpenGLShader
operator|*
name|m_shader
block|;
DECL|member|m_texture
name|QOpenGLTexture
operator|*
name|m_texture
block|; }
expr_stmt|;
end_expr_stmt
begin_constructor
DECL|function|MyGLWidget
name|MyGLWidget
operator|::
name|MyGLWidget
parameter_list|()
member_init_list|:
name|m_program
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_shader
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_texture
argument_list|(
literal|0
argument_list|)
block|{
comment|// No OpenGL resource initialization is done here.
block|}
end_constructor
begin_destructor
DECL|function|~MyGLWidget
name|MyGLWidget
operator|::
name|~
name|MyGLWidget
parameter_list|()
block|{
comment|// Make sure the context is current and then explicitly
comment|// destroy all underlying OpenGL resources.
name|makeCurrent
argument_list|()
expr_stmt|;
operator|delete
name|m_texture
expr_stmt|;
operator|delete
name|m_shader
expr_stmt|;
operator|delete
name|m_program
expr_stmt|;
name|m_vbo
operator|.
name|destroy
argument_list|()
expr_stmt|;
name|m_vao
operator|.
name|destroy
argument_list|()
expr_stmt|;
name|doneCurrent
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initializeGL
name|void
name|MyGLWidget
operator|::
name|initializeGL
parameter_list|()
block|{
name|m_vao
operator|.
name|create
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_vao
operator|.
name|isCreated
argument_list|()
condition|)
name|m_vao
operator|.
name|bind
argument_list|()
expr_stmt|;
name|m_vbo
operator|.
name|create
argument_list|()
expr_stmt|;
name|m_vbo
operator|.
name|bind
argument_list|()
expr_stmt|;
name|m_vbo
operator|.
name|allocate
argument_list|(
operator|...
argument_list|)
expr_stmt|;
name|m_texture
operator|=
operator|new
name|QOpenGLTexture
argument_list|(
name|QImage
argument_list|(
operator|...
argument_list|)
argument_list|)
expr_stmt|;
name|m_shader
operator|=
operator|new
name|QOpenGLShader
argument_list|(
operator|...
argument_list|)
expr_stmt|;
name|m_program
operator|=
operator|new
name|QOpenGLShaderProgram
argument_list|(
operator|...
argument_list|)
expr_stmt|;
operator|...
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|initializeGL
name|void
name|MyGLWidget
operator|::
name|initializeGL
parameter_list|()
block|{
comment|// context() and QOpenGLContext::currentContext() are equivalent when called from initializeGL or paintGL.
name|connect
argument_list|(
name|context
argument_list|()
argument_list|,
operator|&
name|QOpenGLContext
operator|::
name|aboutToBeDestroyed
argument_list|,
name|this
argument_list|,
operator|&
name|MyGLWidget
operator|::
name|cleanup
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|MyGLWidget
operator|::
name|cleanup
parameter_list|()
block|{
name|makeCurrent
argument_list|()
expr_stmt|;
operator|delete
name|m_texture
expr_stmt|;
name|m_texture
operator|=
literal|0
expr_stmt|;
operator|...
name|doneCurrent
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
end_unit
