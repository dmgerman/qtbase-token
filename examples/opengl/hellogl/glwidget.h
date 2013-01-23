begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QGLWidget>
end_include
begin_decl_stmt
DECL|variable|QtLogo
name|class
name|QtLogo
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|GLWidget
range|:
name|public
name|QGLWidget
block|{
name|Q_OBJECT
name|public
operator|:
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
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
comment|//! [0]
comment|//! [1]
name|public
name|slots
operator|:
name|void
name|setXRotation
argument_list|(
argument|int angle
argument_list|)
block|;
name|void
name|setYRotation
argument_list|(
argument|int angle
argument_list|)
block|;
name|void
name|setZRotation
argument_list|(
argument|int angle
argument_list|)
block|;
name|signals
operator|:
name|void
name|xRotationChanged
argument_list|(
argument|int angle
argument_list|)
block|;
name|void
name|yRotationChanged
argument_list|(
argument|int angle
argument_list|)
block|;
name|void
name|zRotationChanged
argument_list|(
argument|int angle
argument_list|)
block|;
comment|//! [1]
comment|//! [2]
name|protected
operator|:
name|void
name|initializeGL
argument_list|()
block|;
name|void
name|paintGL
argument_list|()
block|;
name|void
name|resizeGL
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
comment|//! [2]
comment|//! [3]
name|private
operator|:
name|QtLogo
operator|*
name|logo
block|;
name|int
name|xRot
block|;
name|int
name|yRot
block|;
name|int
name|zRot
block|;
name|QPoint
name|lastPos
block|;
name|QColor
name|qtGreen
block|;
name|QColor
name|qtPurple
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [3]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
