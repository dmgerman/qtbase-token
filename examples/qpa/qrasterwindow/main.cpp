begin_unit
begin_comment
comment|/****************************************************************************  **  ** Copyright (C) 2016 The Qt Company Ltd.  ** Contact: https://www.qt.io/licensing/  **  ** This file is part of the examples of the Qt Toolkit.  **  ** $QT_BEGIN_LICENSE:BSD$  ** Commercial License Usage  ** Licensees holding valid commercial Qt licenses may use this file in  ** accordance with the commercial license agreement provided with the  ** Software or, alternatively, in accordance with the terms contained in  ** a written agreement between you and The Qt Company. For licensing terms  ** and conditions see https://www.qt.io/terms-conditions. For further  ** information use the contact form at https://www.qt.io/contact-us.  **  ** BSD License Usage  ** Alternatively, you may use this file under the terms of the BSD license  ** as follows:  **  ** "Redistribution and use in source and binary forms, with or without  ** modification, are permitted provided that the following conditions are  ** met:  **   * Redistributions of source code must retain the above copyright  **     notice, this list of conditions and the following disclaimer.  **   * Redistributions in binary form must reproduce the above copyright  **     notice, this list of conditions and the following disclaimer in  **     the documentation and/or other materials provided with the  **     distribution.  **   * Neither the name of The Qt Company Ltd nor the names of its  **     contributors may be used to endorse or promote products derived  **     from this software without specific prior written permission.  **  **  ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."  **  ** $QT_END_LICENSE$  **  ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QRasterWindow>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QMatrix4x4>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_function
DECL|function|painterPathForTriangle
specifier|static
name|QPainterPath
name|painterPathForTriangle
parameter_list|()
block|{
specifier|static
specifier|const
name|QPointF
name|bottomLeft
argument_list|(
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QPointF
name|top
argument_list|(
literal|0.0
argument_list|,
literal|1.0
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QPointF
name|bottomRight
argument_list|(
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
decl_stmt|;
name|QPainterPath
name|path
argument_list|(
name|bottomLeft
argument_list|)
decl_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
name|top
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
name|bottomRight
argument_list|)
expr_stmt|;
name|path
operator|.
name|closeSubpath
argument_list|()
expr_stmt|;
return|return
name|path
return|;
block|}
end_function
begin_class
DECL|class|PaintedWindow
class|class
name|PaintedWindow
super|:
specifier|public
name|QRasterWindow
block|{
name|Q_OBJECT
public|public:
DECL|function|PaintedWindow
name|PaintedWindow
parameter_list|()
block|{
name|m_view
operator|.
name|lookAt
argument_list|(
name|QVector3D
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|,
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|m_timer
operator|.
name|setInterval
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|m_timer
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
name|m_timer
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
protected|protected:
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|gray
argument_list|)
expr_stmt|;
name|p
operator|.
name|setWorldTransform
argument_list|(
name|m_window_matrix
operator|.
name|toTransform
argument_list|()
argument_list|)
expr_stmt|;
name|QMatrix4x4
name|mvp
init|=
name|m_projection
operator|*
name|m_view
operator|*
name|m_model
decl_stmt|;
name|p
operator|.
name|setTransform
argument_list|(
name|mvp
operator|.
name|toTransform
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillPath
argument_list|(
name|painterPathForTriangle
argument_list|()
argument_list|,
name|m_brush
argument_list|)
expr_stmt|;
name|m_model
operator|.
name|rotate
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
DECL|function|resizeEvent
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{
name|m_window_matrix
operator|=
name|QTransform
argument_list|()
expr_stmt|;
name|m_window_matrix
operator|.
name|translate
argument_list|(
name|width
argument_list|()
operator|/
literal|2.0
argument_list|,
name|height
argument_list|()
operator|/
literal|2.0
argument_list|)
expr_stmt|;
name|m_window_matrix
operator|.
name|scale
argument_list|(
name|width
argument_list|()
operator|/
literal|2.0
argument_list|,
operator|-
name|height
argument_list|()
operator|/
literal|2.0
argument_list|)
expr_stmt|;
name|m_projection
operator|.
name|setToIdentity
argument_list|()
expr_stmt|;
name|m_projection
operator|.
name|perspective
argument_list|(
literal|45.f
argument_list|,
name|qreal
argument_list|(
name|width
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|height
argument_list|()
argument_list|)
argument_list|,
literal|0.1f
argument_list|,
literal|100.f
argument_list|)
expr_stmt|;
name|QLinearGradient
name|gradient
argument_list|(
name|QPointF
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|,
name|QPointF
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
decl_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|m_brush
operator|=
name|QBrush
argument_list|(
name|gradient
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|m_window_matrix
name|QMatrix4x4
name|m_window_matrix
decl_stmt|;
DECL|member|m_projection
name|QMatrix4x4
name|m_projection
decl_stmt|;
DECL|member|m_view
name|QMatrix4x4
name|m_view
decl_stmt|;
DECL|member|m_model
name|QMatrix4x4
name|m_model
decl_stmt|;
DECL|member|m_brush
name|QBrush
name|m_brush
decl_stmt|;
DECL|member|m_timer
name|QTimer
name|m_timer
decl_stmt|;
block|}
class|;
end_class
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
name|PaintedWindow
name|window
decl_stmt|;
name|window
operator|.
name|create
argument_list|()
expr_stmt|;
name|window
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
