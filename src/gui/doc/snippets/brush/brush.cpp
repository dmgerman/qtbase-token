begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
name|QWidget
name|anyPaintDevice
decl_stmt|;
block|{
comment|// PEN SNIPPET
name|QPainter
name|painter
decl_stmt|;
name|QPen
name|pen
argument_list|(
name|Qt
operator|::
name|red
argument_list|,
literal|2
argument_list|)
decl_stmt|;
comment|// red solid line, 2 pixels wide
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|anyPaintDevice
argument_list|)
expr_stmt|;
comment|// paint something
name|painter
operator|.
name|setPen
argument_list|(
name|pen
argument_list|)
expr_stmt|;
comment|// set the red, wide pen
name|painter
operator|.
name|drawRect
argument_list|(
literal|40
argument_list|,
literal|30
argument_list|,
literal|200
argument_list|,
literal|100
argument_list|)
expr_stmt|;
comment|// draw a rectangle
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
comment|// set blue pen, 0 pixel width
name|painter
operator|.
name|drawLine
argument_list|(
literal|40
argument_list|,
literal|30
argument_list|,
literal|240
argument_list|,
literal|130
argument_list|)
expr_stmt|;
comment|// draw a diagonal in rectangle
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
comment|// painting done
block|}
block|{
comment|// BRUSH SNIPPET
name|QPainter
name|painter
decl_stmt|;
name|QBrush
name|brush
argument_list|(
name|Qt
operator|::
name|yellow
argument_list|)
decl_stmt|;
comment|// yellow solid pattern
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|anyPaintDevice
argument_list|)
expr_stmt|;
comment|// paint something
name|painter
operator|.
name|setBrush
argument_list|(
name|brush
argument_list|)
expr_stmt|;
comment|// set the yellow brush
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
comment|// do not draw outline
name|painter
operator|.
name|drawRect
argument_list|(
literal|40
argument_list|,
literal|30
argument_list|,
literal|200
argument_list|,
literal|100
argument_list|)
expr_stmt|;
comment|// draw filled rectangle
name|painter
operator|.
name|setBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
comment|// do not fill
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
comment|// set black pen, 0 pixel width
name|painter
operator|.
name|drawRect
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|30
argument_list|,
literal|20
argument_list|)
expr_stmt|;
comment|// draw rectangle outline
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
comment|// painting done
block|}
comment|// LINEAR
comment|//! [0]
name|QLinearGradient
name|linearGrad
argument_list|(
name|QPointF
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|,
name|QPointF
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
argument_list|)
decl_stmt|;
name|linearGrad
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|linearGrad
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
comment|//! [0]
comment|// RADIAL
comment|//! [1]
name|QRadialGradient
name|radialGrad
argument_list|(
name|QPointF
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|,
literal|100
argument_list|)
decl_stmt|;
name|radialGrad
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
name|radialGrad
operator|.
name|setColorAt
argument_list|(
literal|0.5
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|radialGrad
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
comment|//! [1]
block|}
end_function
end_unit
