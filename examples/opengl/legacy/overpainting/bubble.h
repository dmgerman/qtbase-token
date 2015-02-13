begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|BUBBLE_H
end_ifndef
begin_define
DECL|macro|BUBBLE_H
define|#
directive|define
name|BUBBLE_H
end_define
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_decl_stmt
name|class
name|Bubble
block|{
name|public
label|:
name|Bubble
argument_list|(
argument|const QPointF&position
argument_list|,
argument|qreal radius
argument_list|,
argument|const QPointF&velocity
argument_list|)
empty_stmt|;
name|void
name|drawBubble
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|)
function_decl|;
name|void
name|updateBrush
parameter_list|()
function_decl|;
name|void
name|move
parameter_list|(
specifier|const
name|QRect
modifier|&
name|bbox
parameter_list|)
function_decl|;
name|QRectF
name|rect
parameter_list|()
function_decl|;
name|private
label|:
name|QColor
name|randomColor
parameter_list|()
function_decl|;
name|QBrush
name|brush
decl_stmt|;
name|QPointF
name|position
decl_stmt|;
name|QPointF
name|vel
decl_stmt|;
name|qreal
name|radius
decl_stmt|;
name|QColor
name|innerColor
decl_stmt|;
name|QColor
name|outerColor
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// BUBBLE_H
end_comment
end_unit
