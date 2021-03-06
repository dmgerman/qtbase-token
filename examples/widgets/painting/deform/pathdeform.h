begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PATHDEFORM_H
end_ifndef
begin_define
DECL|macro|PATHDEFORM_H
define|#
directive|define
name|PATHDEFORM_H
end_define
begin_include
include|#
directive|include
file|"arthurwidgets.h"
end_include
begin_include
include|#
directive|include
file|<QBasicTimer>
end_include
begin_include
include|#
directive|include
file|<QDateTime>
end_include
begin_include
include|#
directive|include
file|<QPainterPath>
end_include
begin_decl_stmt
name|class
name|PathDeformRenderer
range|:
name|public
name|ArthurFrame
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool animated READ animated WRITE setAnimated
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int radius READ radius WRITE setRadius
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int fontSize READ fontSize WRITE setFontSize
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int intensity READ intensity WRITE setIntensity
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString text READ text WRITE setText
argument_list|)
name|public
operator|:
name|explicit
name|PathDeformRenderer
argument_list|(
argument|QWidget *widget
argument_list|,
argument|bool smallScreen = false
argument_list|)
block|;
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mousePressEvent
argument_list|(
argument|QMouseEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseReleaseEvent
argument_list|(
argument|QMouseEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseMoveEvent
argument_list|(
argument|QMouseEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|timerEvent
argument_list|(
argument|QTimerEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QSize
argument_list|(
literal|600
argument_list|,
literal|500
argument_list|)
return|;
block|}
name|bool
name|animated
argument_list|()
specifier|const
block|{
return|return
name|m_animated
return|;
block|}
name|int
name|radius
argument_list|()
specifier|const
block|{
return|return
name|int
argument_list|(
name|m_radius
argument_list|)
return|;
block|}
name|int
name|fontSize
argument_list|()
specifier|const
block|{
return|return
name|m_fontSize
return|;
block|}
name|int
name|intensity
argument_list|()
specifier|const
block|{
return|return
name|int
argument_list|(
name|m_intensity
argument_list|)
return|;
block|}
name|QString
name|text
argument_list|()
specifier|const
block|{
return|return
name|m_text
return|;
block|}
name|public
name|slots
operator|:
name|void
name|setRadius
argument_list|(
argument|int radius
argument_list|)
block|;
name|void
name|setFontSize
argument_list|(
argument|int fontSize
argument_list|)
block|{
name|m_fontSize
operator|=
name|fontSize
block|;
name|setText
argument_list|(
name|m_text
argument_list|)
block|; }
name|void
name|setText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|setIntensity
argument_list|(
argument|int intensity
argument_list|)
block|;
name|void
name|setAnimated
argument_list|(
argument|bool animated
argument_list|)
block|;
name|signals
operator|:
name|void
name|clicked
argument_list|()
block|;
comment|//     void frameRate(double fps);
name|private
operator|:
name|void
name|generateLensPixmap
argument_list|()
block|;
name|QPainterPath
name|lensDeform
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|source
argument_list|,
specifier|const
name|QPointF
operator|&
name|offset
argument_list|)
block|;
name|QBasicTimer
name|m_repaintTimer
block|;
comment|//     QBasicTimer m_fpsTimer;
comment|//     int m_fpsCounter;
name|QTime
name|m_repaintTracker
block|;
name|QVector
operator|<
name|QPainterPath
operator|>
name|m_paths
block|;
name|QVector
operator|<
name|QPointF
operator|>
name|m_advances
block|;
name|QRectF
name|m_pathBounds
block|;
name|QString
name|m_text
block|;
name|QPixmap
name|m_lens_pixmap
block|;
name|QImage
name|m_lens_image
block|;
name|int
name|m_fontSize
block|;
name|bool
name|m_animated
block|;
name|qreal
name|m_intensity
block|;
name|qreal
name|m_radius
block|;
name|QPointF
name|m_pos
block|;
name|QPointF
name|m_offset
block|;
name|QPointF
name|m_direction
block|;
name|QPointF
name|m_mousePress
block|;
name|bool
name|m_mouseDrag
block|;
name|bool
name|m_smallScreen
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|PathDeformControls
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|PathDeformControls
argument_list|(
argument|QWidget *parent
argument_list|,
argument|PathDeformRenderer* renderer
argument_list|,
argument|bool smallScreen
argument_list|)
block|;
name|signals
operator|:
name|void
name|okPressed
argument_list|()
block|;
name|void
name|quitPressed
argument_list|()
block|;
name|private
operator|:
name|PathDeformRenderer
operator|*
name|m_renderer
block|;
name|void
name|layoutForDesktop
argument_list|()
block|;
name|void
name|layoutForSmallScreen
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|PathDeformWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|PathDeformWidget
argument_list|(
argument|QWidget *parent
argument_list|,
argument|bool smallScreen
argument_list|)
block|;
name|void
name|setStyle
argument_list|(
name|QStyle
operator|*
name|style
argument_list|)
block|;
name|private
operator|:
name|PathDeformRenderer
operator|*
name|m_renderer
block|;
name|PathDeformControls
operator|*
name|m_controls
block|;
name|private
name|slots
operator|:
name|void
name|showControls
argument_list|()
block|;
name|void
name|hideControls
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PATHDEFORM_H
end_comment
end_unit
