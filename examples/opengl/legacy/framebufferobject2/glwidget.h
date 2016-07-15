begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtOpenGL>
end_include
begin_decl_stmt
name|class
name|GLWidget
range|:
name|public
name|QGLWidget
block|{
name|public
operator|:
name|GLWidget
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
operator|~
name|GLWidget
argument_list|()
block|;
name|void
name|initializeGL
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|resizeGL
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|paintGL
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|timerEvent
argument_list|(
argument|QTimerEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|update
argument_list|()
block|; }
name|void
name|mousePressEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|killTimer
argument_list|(
name|timerId
argument_list|)
block|; }
name|void
name|mouseReleaseEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|timerId
operator|=
name|startTimer
argument_list|(
literal|20
argument_list|)
block|; }
name|void
name|drawCube
argument_list|(
argument|int i
argument_list|,
argument|GLfloat z
argument_list|,
argument|GLfloat ri
argument_list|,
argument|GLfloat jmp
argument_list|,
argument|GLfloat amp
argument_list|)
block|;
name|private
operator|:
name|GLfloat
name|rot
index|[
literal|3
index|]
block|,
name|xOffs
index|[
literal|3
index|]
block|,
name|yOffs
index|[
literal|3
index|]
block|,
name|xInc
index|[
literal|3
index|]
block|;
name|GLuint
name|pbufferList
block|;
name|GLuint
name|cubeTexture
block|;
name|int
name|timerId
block|;
name|QGLFramebufferObject
operator|*
name|fbo
block|; }
decl_stmt|;
end_decl_stmt
end_unit
