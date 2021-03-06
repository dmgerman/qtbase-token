begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"diagramitem.h"
end_include
begin_constructor
DECL|function|DiagramItem
name|DiagramItem
operator|::
name|DiagramItem
parameter_list|(
name|DiagramType
name|diagramType
parameter_list|,
name|QGraphicsItem
modifier|*
name|item
parameter_list|)
member_init_list|:
name|QGraphicsPolygonItem
argument_list|(
name|item
argument_list|)
block|{
if|if
condition|(
name|diagramType
operator|==
name|Box
condition|)
block|{
name|boxPolygon
operator|<<
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|30
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|30
argument_list|,
literal|30
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|30
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setPolygon
argument_list|(
name|boxPolygon
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|trianglePolygon
operator|<<
name|QPointF
argument_list|(
literal|15
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|30
argument_list|,
literal|30
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|30
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|15
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setPolygon
argument_list|(
name|trianglePolygon
argument_list|)
expr_stmt|;
block|}
name|QColor
name|color
argument_list|(
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|qrand
argument_list|()
argument_list|)
operator|%
literal|256
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|qrand
argument_list|()
argument_list|)
operator|%
literal|256
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|qrand
argument_list|()
argument_list|)
operator|%
literal|256
argument_list|)
decl_stmt|;
name|QBrush
name|brush
argument_list|(
name|color
argument_list|)
decl_stmt|;
name|setBrush
argument_list|(
name|brush
argument_list|)
expr_stmt|;
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsSelectable
argument_list|)
expr_stmt|;
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsMovable
argument_list|)
expr_stmt|;
block|}
end_constructor
end_unit
