begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"helper.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Helper
name|Helper
operator|::
name|Helper
parameter_list|()
block|{
name|QLinearGradient
name|gradient
argument_list|(
name|QPointF
argument_list|(
literal|50
argument_list|,
operator|-
literal|20
argument_list|)
argument_list|,
name|QPointF
argument_list|(
literal|80
argument_list|,
literal|20
argument_list|)
argument_list|)
decl_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.0
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|1.0
argument_list|,
name|QColor
argument_list|(
literal|0xa6
argument_list|,
literal|0xce
argument_list|,
literal|0x39
argument_list|)
argument_list|)
expr_stmt|;
name|background
operator|=
name|QBrush
argument_list|(
name|QColor
argument_list|(
literal|64
argument_list|,
literal|32
argument_list|,
literal|64
argument_list|)
argument_list|)
expr_stmt|;
name|circleBrush
operator|=
name|QBrush
argument_list|(
name|gradient
argument_list|)
expr_stmt|;
name|circlePen
operator|=
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|circlePen
operator|.
name|setWidth
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|textPen
operator|=
name|QPen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|textFont
operator|.
name|setPixelSize
argument_list|(
literal|50
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|paint
name|void
name|Helper
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
name|QPaintEvent
modifier|*
name|event
parameter_list|,
name|int
name|elapsed
parameter_list|)
block|{
name|painter
operator|->
name|fillRect
argument_list|(
name|event
operator|->
name|rect
argument_list|()
argument_list|,
name|background
argument_list|)
expr_stmt|;
name|painter
operator|->
name|translate
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|circleBrush
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|circlePen
argument_list|)
expr_stmt|;
name|painter
operator|->
name|rotate
argument_list|(
name|elapsed
operator|*
literal|0.030
argument_list|)
expr_stmt|;
name|qreal
name|r
init|=
name|elapsed
operator|/
literal|1000.0
decl_stmt|;
name|int
name|n
init|=
literal|30
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
block|{
name|painter
operator|->
name|rotate
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|qreal
name|radius
init|=
literal|0
operator|+
literal|120.0
operator|*
operator|(
operator|(
name|i
operator|+
name|r
operator|)
operator|/
name|n
operator|)
decl_stmt|;
name|qreal
name|circleRadius
init|=
literal|1
operator|+
operator|(
operator|(
name|i
operator|+
name|r
operator|)
operator|/
name|n
operator|)
operator|*
literal|20
decl_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
name|QRectF
argument_list|(
name|radius
argument_list|,
operator|-
name|circleRadius
argument_list|,
name|circleRadius
operator|*
literal|2
argument_list|,
name|circleRadius
operator|*
literal|2
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|painter
operator|->
name|setPen
argument_list|(
name|textPen
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setFont
argument_list|(
name|textFont
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
name|QRect
argument_list|(
operator|-
literal|50
argument_list|,
operator|-
literal|50
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
literal|"Qt"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
end_unit
