begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TABLETCANVAS_H
end_ifndef
begin_define
DECL|macro|TABLETCANVAS_H
define|#
directive|define
name|TABLETCANVAS_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|<QPixmap>
end_include
begin_include
include|#
directive|include
file|<QPoint>
end_include
begin_include
include|#
directive|include
file|<QTabletEvent>
end_include
begin_include
include|#
directive|include
file|<QColor>
end_include
begin_include
include|#
directive|include
file|<QBrush>
end_include
begin_include
include|#
directive|include
file|<QPen>
end_include
begin_include
include|#
directive|include
file|<QPoint>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPaintEvent
name|class
name|QPaintEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|TabletCanvas
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|AlphaChannelType
block|{
name|AlphaPressure
block|,
name|AlphaTilt
block|,
name|NoAlpha
block|}
block|;     enum
name|ColorSaturationType
block|{
name|SaturationVTilt
block|,
name|SaturationHTilt
block|,
name|SaturationPressure
block|,
name|NoSaturation
block|}
block|;     enum
name|LineWidthType
block|{
name|LineWidthPressure
block|,
name|LineWidthTilt
block|,
name|NoLineWidth
block|}
block|;
name|TabletCanvas
argument_list|()
block|;
name|bool
name|saveImage
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|bool
name|loadImage
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|void
name|setAlphaChannelType
argument_list|(
argument|AlphaChannelType type
argument_list|)
block|{
name|alphaChannelType
operator|=
name|type
block|; }
name|void
name|setColorSaturationType
argument_list|(
argument|ColorSaturationType type
argument_list|)
block|{
name|colorSaturationType
operator|=
name|type
block|; }
name|void
name|setLineWidthType
argument_list|(
argument|LineWidthType type
argument_list|)
block|{
name|lineWidthType
operator|=
name|type
block|; }
name|void
name|setColor
argument_list|(
argument|const QColor&color
argument_list|)
block|{
name|myColor
operator|=
name|color
block|; }
name|QColor
name|color
argument_list|()
specifier|const
block|{
return|return
name|myColor
return|;
block|}
name|void
name|setTabletDevice
argument_list|(
argument|QTabletEvent::TabletDevice device
argument_list|)
block|{
name|myTabletDevice
operator|=
name|device
block|; }
name|int
name|maximum
argument_list|(
argument|int a
argument_list|,
argument|int b
argument_list|)
block|{
return|return
name|a
operator|>
name|b
operator|?
name|a
operator|:
name|b
return|;
block|}
name|protected
operator|:
name|void
name|tabletEvent
argument_list|(
argument|QTabletEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|resizeEvent
argument_list|(
argument|QResizeEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|initPixmap
argument_list|()
block|;
name|void
name|paintPixmap
argument_list|(
name|QPainter
operator|&
name|painter
argument_list|,
name|QTabletEvent
operator|*
name|event
argument_list|)
block|;
name|Qt
operator|::
name|BrushStyle
name|brushPattern
argument_list|(
argument|qreal value
argument_list|)
block|;
name|void
name|updateBrush
argument_list|(
name|QTabletEvent
operator|*
name|event
argument_list|)
block|;
name|AlphaChannelType
name|alphaChannelType
block|;
name|ColorSaturationType
name|colorSaturationType
block|;
name|LineWidthType
name|lineWidthType
block|;
name|QTabletEvent
operator|::
name|PointerType
name|pointerType
block|;
name|QTabletEvent
operator|::
name|TabletDevice
name|myTabletDevice
block|;
name|QColor
name|myColor
block|;
name|QPixmap
name|pixmap
block|;
name|QBrush
name|myBrush
block|;
name|QPen
name|myPen
block|;
name|bool
name|deviceDown
block|;
name|QPoint
name|polyLine
index|[
literal|3
index|]
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
