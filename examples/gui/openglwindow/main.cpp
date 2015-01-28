begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"openglwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QMatrix4x4>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLShaderProgram>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmath.h>
end_include
begin_comment
comment|//! [1]
end_comment
begin_class
DECL|class|TriangleWindow
class|class
name|TriangleWindow
super|:
specifier|public
name|OpenGLWindow
block|{
public|public:
name|TriangleWindow
parameter_list|()
constructor_decl|;
DECL|member|Q_DECL_OVERRIDE
name|void
name|initialize
parameter_list|()
name|Q_DECL_OVERRIDE
function_decl|;
DECL|member|Q_DECL_OVERRIDE
name|void
name|render
parameter_list|()
name|Q_DECL_OVERRIDE
function_decl|;
private|private:
name|GLuint
name|loadShader
parameter_list|(
name|GLenum
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|source
parameter_list|)
function_decl|;
DECL|member|m_posAttr
name|GLuint
name|m_posAttr
decl_stmt|;
DECL|member|m_colAttr
name|GLuint
name|m_colAttr
decl_stmt|;
DECL|member|m_matrixUniform
name|GLuint
name|m_matrixUniform
decl_stmt|;
DECL|member|m_program
name|QOpenGLShaderProgram
modifier|*
name|m_program
decl_stmt|;
DECL|member|m_frame
name|int
name|m_frame
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|TriangleWindow
name|TriangleWindow
operator|::
name|TriangleWindow
parameter_list|()
member_init_list|:
name|m_program
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_frame
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QGuiApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QSurfaceFormat
name|format
decl_stmt|;
name|format
operator|.
name|setSamples
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|TriangleWindow
name|window
decl_stmt|;
name|window
operator|.
name|setFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|window
operator|.
name|resize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|window
operator|.
name|show
argument_list|()
expr_stmt|;
name|window
operator|.
name|setAnimating
argument_list|(
literal|true
argument_list|)
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
DECL|variable|vertexShaderSource
specifier|static
specifier|const
name|char
modifier|*
name|vertexShaderSource
init|=
literal|"attribute highp vec4 posAttr;\n"
literal|"attribute lowp vec4 colAttr;\n"
literal|"varying lowp vec4 col;\n"
literal|"uniform highp mat4 matrix;\n"
literal|"void main() {\n"
literal|"   col = colAttr;\n"
literal|"   gl_Position = matrix * posAttr;\n"
literal|"}\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|fragmentShaderSource
specifier|static
specifier|const
name|char
modifier|*
name|fragmentShaderSource
init|=
literal|"varying lowp vec4 col;\n"
literal|"void main() {\n"
literal|"   gl_FragColor = col;\n"
literal|"}\n"
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|loadShader
name|GLuint
name|TriangleWindow
operator|::
name|loadShader
parameter_list|(
name|GLenum
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|source
parameter_list|)
block|{
name|GLuint
name|shader
init|=
name|glCreateShader
argument_list|(
name|type
argument_list|)
decl_stmt|;
name|glShaderSource
argument_list|(
name|shader
argument_list|,
literal|1
argument_list|,
operator|&
name|source
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|glCompileShader
argument_list|(
name|shader
argument_list|)
expr_stmt|;
return|return
name|shader
return|;
block|}
end_function
begin_function
DECL|function|initialize
name|void
name|TriangleWindow
operator|::
name|initialize
parameter_list|()
block|{
name|m_program
operator|=
operator|new
name|QOpenGLShaderProgram
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|addShaderFromSourceCode
argument_list|(
name|QOpenGLShader
operator|::
name|Vertex
argument_list|,
name|vertexShaderSource
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|addShaderFromSourceCode
argument_list|(
name|QOpenGLShader
operator|::
name|Fragment
argument_list|,
name|fragmentShaderSource
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|link
argument_list|()
expr_stmt|;
name|m_posAttr
operator|=
name|m_program
operator|->
name|attributeLocation
argument_list|(
literal|"posAttr"
argument_list|)
expr_stmt|;
name|m_colAttr
operator|=
name|m_program
operator|->
name|attributeLocation
argument_list|(
literal|"colAttr"
argument_list|)
expr_stmt|;
name|m_matrixUniform
operator|=
name|m_program
operator|->
name|uniformLocation
argument_list|(
literal|"matrix"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|render
name|void
name|TriangleWindow
operator|::
name|render
parameter_list|()
block|{
specifier|const
name|qreal
name|retinaScale
init|=
name|devicePixelRatio
argument_list|()
decl_stmt|;
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
operator|*
name|retinaScale
argument_list|,
name|height
argument_list|()
operator|*
name|retinaScale
argument_list|)
expr_stmt|;
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|bind
argument_list|()
expr_stmt|;
name|QMatrix4x4
name|matrix
decl_stmt|;
name|matrix
operator|.
name|perspective
argument_list|(
literal|60.0f
argument_list|,
literal|4.0f
operator|/
literal|3.0f
argument_list|,
literal|0.1f
argument_list|,
literal|100.0f
argument_list|)
expr_stmt|;
name|matrix
operator|.
name|translate
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
operator|-
literal|2
argument_list|)
expr_stmt|;
name|matrix
operator|.
name|rotate
argument_list|(
literal|100.0f
operator|*
name|m_frame
operator|/
name|screen
argument_list|()
operator|->
name|refreshRate
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|setUniformValue
argument_list|(
name|m_matrixUniform
argument_list|,
name|matrix
argument_list|)
expr_stmt|;
name|GLfloat
name|vertices
index|[]
init|=
block|{
literal|0.0f
block|,
literal|0.707f
block|,
operator|-
literal|0.5f
block|,
operator|-
literal|0.5f
block|,
literal|0.5f
block|,
operator|-
literal|0.5f
block|}
decl_stmt|;
name|GLfloat
name|colors
index|[]
init|=
block|{
literal|1.0f
block|,
literal|0.0f
block|,
literal|0.0f
block|,
literal|0.0f
block|,
literal|1.0f
block|,
literal|0.0f
block|,
literal|0.0f
block|,
literal|0.0f
block|,
literal|1.0f
block|}
decl_stmt|;
name|glVertexAttribPointer
argument_list|(
name|m_posAttr
argument_list|,
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|vertices
argument_list|)
expr_stmt|;
name|glVertexAttribPointer
argument_list|(
name|m_colAttr
argument_list|,
literal|3
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|colors
argument_list|)
expr_stmt|;
name|glEnableVertexAttribArray
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|glEnableVertexAttribArray
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|glDrawArrays
argument_list|(
name|GL_TRIANGLES
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|glDisableVertexAttribArray
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|glDisableVertexAttribArray
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|release
argument_list|()
expr_stmt|;
operator|++
name|m_frame
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
end_unit
