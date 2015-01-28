begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GLWIDGET_H
end_ifndef
begin_define
DECL|macro|GLWIDGET_H
define|#
directive|define
name|GLWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QOpenGLWidget>
end_include
begin_include
include|#
directive|include
file|<QOpenGLFunctions>
end_include
begin_include
include|#
directive|include
file|<QOpenGLShaderProgram>
end_include
begin_include
include|#
directive|include
file|<QOpenGLBuffer>
end_include
begin_include
include|#
directive|include
file|<QVector3D>
end_include
begin_include
include|#
directive|include
file|<QMatrix4x4>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<QMutex>
end_include
begin_include
include|#
directive|include
file|<QWaitCondition>
end_include
begin_include
include|#
directive|include
file|<QElapsedTimer>
end_include
begin_decl_stmt
DECL|variable|GLWidget
name|class
name|GLWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|Renderer
range|:
name|public
name|QObject
decl_stmt|,
name|protected
name|QOpenGLFunctions
block|{
name|Q_OBJECT
name|public
range|:
name|Renderer
argument_list|(
name|GLWidget
operator|*
name|w
argument_list|)
decl_stmt|;
name|void
name|lockRenderer
parameter_list|()
block|{
name|m_renderMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
block|}
name|void
name|unlockRenderer
parameter_list|()
block|{
name|m_renderMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
name|QMutex
modifier|*
name|grabMutex
parameter_list|()
block|{
return|return
operator|&
name|m_grabMutex
return|;
block|}
name|QWaitCondition
modifier|*
name|grabCond
parameter_list|()
block|{
return|return
operator|&
name|m_grabCond
return|;
block|}
name|void
name|prepareExit
parameter_list|()
block|{
name|m_exiting
operator|=
name|true
expr_stmt|;
name|m_grabCond
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
block|}
name|signals
label|:
name|void
name|contextWanted
parameter_list|()
function_decl|;
name|public
name|slots
range|:
name|void
name|render
argument_list|()
decl_stmt|;
name|private
label|:
name|void
name|paintQtLogo
parameter_list|()
function_decl|;
name|void
name|createGeometry
parameter_list|()
function_decl|;
name|void
name|quad
parameter_list|(
name|qreal
name|x1
parameter_list|,
name|qreal
name|y1
parameter_list|,
name|qreal
name|x2
parameter_list|,
name|qreal
name|y2
parameter_list|,
name|qreal
name|x3
parameter_list|,
name|qreal
name|y3
parameter_list|,
name|qreal
name|x4
parameter_list|,
name|qreal
name|y4
parameter_list|)
function_decl|;
name|void
name|extrude
parameter_list|(
name|qreal
name|x1
parameter_list|,
name|qreal
name|y1
parameter_list|,
name|qreal
name|x2
parameter_list|,
name|qreal
name|y2
parameter_list|)
function_decl|;
name|bool
name|m_inited
decl_stmt|;
name|qreal
name|m_fAngle
decl_stmt|;
name|qreal
name|m_fScale
decl_stmt|;
name|QVector
operator|<
name|QVector3D
operator|>
name|vertices
expr_stmt|;
name|QVector
operator|<
name|QVector3D
operator|>
name|normals
expr_stmt|;
name|QOpenGLShaderProgram
name|program
decl_stmt|;
name|QOpenGLBuffer
name|vbo
decl_stmt|;
name|int
name|vertexAttr
decl_stmt|;
name|int
name|normalAttr
decl_stmt|;
name|int
name|matrixUniform
decl_stmt|;
name|GLWidget
modifier|*
name|m_glwidget
decl_stmt|;
name|QMutex
name|m_renderMutex
decl_stmt|;
name|QElapsedTimer
name|m_elapsed
decl_stmt|;
name|QMutex
name|m_grabMutex
decl_stmt|;
name|QWaitCondition
name|m_grabCond
decl_stmt|;
name|bool
name|m_exiting
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|GLWidget
range|:
name|public
name|QOpenGLWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|GLWidget
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|GLWidget
argument_list|()
block|;
name|protected
operator|:
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|{ }
name|signals
operator|:
name|void
name|renderRequested
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|grabContext
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|onAboutToCompose
argument_list|()
block|;
name|void
name|onFrameSwapped
argument_list|()
block|;
name|void
name|onAboutToResize
argument_list|()
block|;
name|void
name|onResized
argument_list|()
block|;
name|private
operator|:
name|QThread
operator|*
name|m_thread
block|;
name|Renderer
operator|*
name|m_renderer
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
