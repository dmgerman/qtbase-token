begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|protected
operator|:
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
block|;
name|void
name|makeObject
argument_list|()
block|;
name|void
name|quad
argument_list|(
argument|GLenum primitive
argument_list|,
argument|GLdouble x1
argument_list|,
argument|GLdouble y1
argument_list|,
argument|GLdouble x2
argument_list|,
argument|GLdouble y2
argument_list|,
argument|GLdouble x3
argument_list|,
argument|GLdouble y3
argument_list|,
argument|GLdouble x4
argument_list|,
argument|GLdouble y4
argument_list|)
block|;
name|private
operator|:
name|GLuint
name|list
block|; }
decl_stmt|;
end_decl_stmt
end_unit
