begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|GL_GLEXT_PROTOTYPES
define|#
directive|define
name|GL_GLEXT_PROTOTYPES
end_define
begin_include
include|#
directive|include
file|"openglwidget.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets/private/qwidget_p.h>
end_include
begin_include
include|#
directive|include
file|<QOpenGLFramebufferObject>
end_include
begin_include
include|#
directive|include
file|<QWindow>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFunctions>
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
begin_include
include|#
directive|include
file|<qopengl.h>
end_include
begin_class
DECL|class|OpenGLWidgetPrivate
class|class
name|OpenGLWidgetPrivate
super|:
specifier|protected
name|QOpenGLFunctions
block|{
public|public:
DECL|function|OpenGLWidgetPrivate
name|OpenGLWidgetPrivate
parameter_list|(
name|QWidget
modifier|*
name|q
parameter_list|)
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
member_init_list|,
name|q
argument_list|(
name|q
argument_list|)
block|{      }
name|void
name|initialize
parameter_list|()
function_decl|;
name|void
name|render
parameter_list|()
function_decl|;
DECL|function|width
name|int
name|width
parameter_list|()
block|{
return|return
name|w
return|;
block|}
DECL|function|height
name|int
name|height
parameter_list|()
block|{
return|return
name|h
return|;
block|}
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
DECL|member|w
DECL|member|h
name|int
name|w
decl_stmt|,
name|h
decl_stmt|;
DECL|member|q
name|QWidget
modifier|*
name|q
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|OpenGLWidget
name|OpenGLWidget
operator|::
name|OpenGLWidget
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
block|{
name|d
operator|=
operator|new
name|OpenGLWidgetPrivate
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QTimer
modifier|*
name|timer
init|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|update
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|->
name|start
argument_list|(
literal|30
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~OpenGLWidget
name|OpenGLWidget
operator|::
name|~
name|OpenGLWidget
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|initializeGL
name|void
name|OpenGLWidget
operator|::
name|initializeGL
parameter_list|()
block|{
comment|//    qDebug("*initializeGL*");
name|d
operator|->
name|initialize
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeGL
name|void
name|OpenGLWidget
operator|::
name|resizeGL
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
comment|//    qDebug("*resizeGL*");
name|d
operator|->
name|w
operator|=
name|w
expr_stmt|;
name|d
operator|->
name|h
operator|=
name|h
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintGL
name|void
name|OpenGLWidget
operator|::
name|paintGL
parameter_list|()
block|{
comment|//    qDebug("*paintGL* %d", d->m_frame);
name|d
operator|->
name|render
argument_list|()
expr_stmt|;
block|}
end_function
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
begin_function
DECL|function|initialize
name|void
name|OpenGLWidgetPrivate
operator|::
name|initialize
parameter_list|()
block|{
name|initializeOpenGLFunctions
argument_list|()
expr_stmt|;
name|m_program
operator|=
operator|new
name|QOpenGLShaderProgram
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
begin_function
DECL|function|render
name|void
name|OpenGLWidgetPrivate
operator|::
name|render
parameter_list|()
block|{
specifier|const
name|qreal
name|retinaScale
init|=
name|q
operator|->
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
name|glClearColor
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|,
literal|0.0
argument_list|,
literal|1.0
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
literal|30
comment|/*screen()->refreshRate()*/
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
end_unit
