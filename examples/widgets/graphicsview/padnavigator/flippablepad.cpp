begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"flippablepad.h"
end_include
begin_include
include|#
directive|include
file|<QDirIterator>
end_include
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|boundsFromSize
specifier|static
name|QRectF
name|boundsFromSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
return|return
name|QRectF
argument_list|(
operator|(
operator|-
name|size
operator|.
name|width
argument_list|()
operator|/
literal|2.0
operator|)
operator|*
literal|150
argument_list|,
operator|(
operator|-
name|size
operator|.
name|height
argument_list|()
operator|/
literal|2.0
operator|)
operator|*
literal|150
argument_list|,
name|size
operator|.
name|width
argument_list|()
operator|*
literal|150
argument_list|,
name|size
operator|.
name|height
argument_list|()
operator|*
literal|150
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|posForLocation
specifier|static
name|QPointF
name|posForLocation
parameter_list|(
name|int
name|column
parameter_list|,
name|int
name|row
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
return|return
name|QPointF
argument_list|(
name|column
operator|*
literal|150
argument_list|,
name|row
operator|*
literal|150
argument_list|)
operator|-
name|QPointF
argument_list|(
operator|(
name|size
operator|.
name|width
argument_list|()
operator|-
literal|1
operator|)
operator|*
literal|75
argument_list|,
operator|(
name|size
operator|.
name|height
argument_list|()
operator|-
literal|1
operator|)
operator|*
literal|75
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_constructor
DECL|function|FlippablePad
name|FlippablePad
operator|::
name|FlippablePad
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|RoundRectItem
argument_list|(
name|boundsFromSize
argument_list|(
name|size
argument_list|)
argument_list|,
name|QColor
argument_list|(
literal|226
argument_list|,
literal|255
argument_list|,
literal|92
argument_list|,
literal|64
argument_list|)
argument_list|,
name|parent
argument_list|)
block|{
comment|//! [2]
comment|//! [3]
name|int
name|numIcons
init|=
name|size
operator|.
name|width
argument_list|()
operator|*
name|size
operator|.
name|height
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QPixmap
argument_list|>
name|pixmaps
decl_stmt|;
name|QDirIterator
name|it
argument_list|(
literal|":/images"
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"*.png"
argument_list|)
decl_stmt|;
while|while
condition|(
name|it
operator|.
name|hasNext
argument_list|()
operator|&&
name|pixmaps
operator|.
name|size
argument_list|()
operator|<
name|numIcons
condition|)
name|pixmaps
operator|<<
name|it
operator|.
name|next
argument_list|()
expr_stmt|;
comment|//! [3]
comment|//! [4]
specifier|const
name|QRectF
name|iconRect
argument_list|(
operator|-
literal|54
argument_list|,
operator|-
literal|54
argument_list|,
literal|108
argument_list|,
literal|108
argument_list|)
decl_stmt|;
specifier|const
name|QColor
name|iconColor
argument_list|(
literal|214
argument_list|,
literal|240
argument_list|,
literal|110
argument_list|,
literal|128
argument_list|)
decl_stmt|;
name|iconGrid
operator|.
name|resize
argument_list|(
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|n
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|size
operator|.
name|height
argument_list|()
condition|;
operator|++
name|y
control|)
block|{
name|iconGrid
index|[
name|y
index|]
operator|.
name|resize
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|size
operator|.
name|width
argument_list|()
condition|;
operator|++
name|x
control|)
block|{
name|RoundRectItem
modifier|*
name|rect
init|=
operator|new
name|RoundRectItem
argument_list|(
name|iconRect
argument_list|,
name|iconColor
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|rect
operator|->
name|setZValue
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|rect
operator|->
name|setPos
argument_list|(
name|posForLocation
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|rect
operator|->
name|setPixmap
argument_list|(
name|pixmaps
operator|.
name|at
argument_list|(
name|n
operator|++
operator|%
name|pixmaps
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|iconGrid
index|[
name|y
index|]
index|[
name|x
index|]
operator|=
name|rect
expr_stmt|;
block|}
block|}
block|}
end_constructor
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|iconAt
name|RoundRectItem
modifier|*
name|FlippablePad
operator|::
name|iconAt
parameter_list|(
name|int
name|column
parameter_list|,
name|int
name|row
parameter_list|)
specifier|const
block|{
return|return
name|iconGrid
index|[
name|row
index|]
index|[
name|column
index|]
return|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
end_unit
