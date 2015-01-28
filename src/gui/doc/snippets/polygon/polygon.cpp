begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
block|{
comment|// STREAM
comment|//! [0]
name|QPolygon
name|polygon
decl_stmt|;
name|polygon
operator|<<
name|QPoint
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|20
argument_list|,
literal|30
argument_list|)
expr_stmt|;
comment|//! [0]
block|}
block|{
comment|// STREAMF
comment|//! [1]
name|QPolygonF
name|polygon
decl_stmt|;
name|polygon
operator|<<
name|QPointF
argument_list|(
literal|10.4
argument_list|,
literal|20.5
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|20.2
argument_list|,
literal|30.2
argument_list|)
expr_stmt|;
comment|//! [1]
block|}
block|{
comment|// SETPOINTS
comment|//! [2]
specifier|static
specifier|const
name|int
name|points
index|[]
init|=
block|{
literal|10
block|,
literal|20
block|,
literal|30
block|,
literal|40
block|}
decl_stmt|;
name|QPolygon
name|polygon
decl_stmt|;
name|polygon
operator|.
name|setPoints
argument_list|(
literal|2
argument_list|,
name|points
argument_list|)
expr_stmt|;
comment|//! [2]
block|}
block|{
comment|// SETPOINTS2
comment|//! [3]
name|QPolygon
name|polygon
decl_stmt|;
name|polygon
operator|.
name|setPoints
argument_list|(
literal|2
argument_list|,
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
expr_stmt|;
comment|//! [3]
block|}
block|{
comment|// PUTPOINTS
comment|//! [4]
name|QPolygon
name|polygon
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|polygon
index|[
literal|0
index|]
operator|=
name|QPoint
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|polygon
operator|.
name|putPoints
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|,
literal|8
argument_list|,
literal|9
argument_list|)
expr_stmt|;
comment|//! [4]
block|}
block|{
comment|// PUTPOINTS2
comment|//! [5]
name|QPolygon
name|polygon
argument_list|(
literal|3
argument_list|)
decl_stmt|;
name|polygon
operator|.
name|putPoints
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|8
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|polygon
operator|.
name|putPoints
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|//! [5]
block|}
block|{
comment|// PUTPOINTS3
comment|//! [6]
name|QPolygon
name|polygon1
decl_stmt|;
name|polygon1
operator|.
name|putPoints
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// polygon1 is now the three-point polygon(1,2, 0,0, 5,6);
name|QPolygon
name|polygon2
decl_stmt|;
name|polygon2
operator|.
name|putPoints
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// polygon2 is now (4,4, 5,5, 6,6);
name|polygon1
operator|.
name|putPoints
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|,
name|polygon2
argument_list|)
expr_stmt|;
comment|// polygon1 is now the five-point polygon(1,2, 0,0, 4,4, 5,5, 6,6);
comment|//! [6]
block|}
return|return
literal|0
return|;
block|}
end_function
end_unit
