begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|NORWEGIANWOODSTYLE_H
end_ifndef
begin_define
DECL|macro|NORWEGIANWOODSTYLE_H
define|#
directive|define
name|NORWEGIANWOODSTYLE_H
end_define
begin_include
include|#
directive|include
file|<QProxyStyle>
end_include
begin_include
include|#
directive|include
file|<QPalette>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPainterPath
name|class
name|QPainterPath
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|NorwegianWoodStyle
range|:
name|public
name|QProxyStyle
block|{
name|Q_OBJECT
name|public
operator|:
name|NorwegianWoodStyle
argument_list|()
block|;
name|void
name|polish
argument_list|(
name|QPalette
operator|&
name|palette
argument_list|)
block|;
name|void
name|polish
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|unpolish
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|int
name|pixelMetric
argument_list|(
argument|PixelMetric metric
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|int
name|styleHint
argument_list|(
argument|StyleHint hint
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|const QWidget *widget
argument_list|,
argument|QStyleHintReturn *returnData
argument_list|)
specifier|const
block|;
name|void
name|drawPrimitive
argument_list|(
argument|PrimitiveElement element
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|drawControl
argument_list|(
argument|ControlElement control
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|private
operator|:
specifier|static
name|void
name|setTexture
argument_list|(
argument|QPalette&palette
argument_list|,
argument|QPalette::ColorRole role
argument_list|,
argument|const QPixmap&pixmap
argument_list|)
block|;
specifier|static
name|QPainterPath
name|roundRectPath
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
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
