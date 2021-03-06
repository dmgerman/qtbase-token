begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"circlewidget.h"
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|CircleWidget
name|CircleWidget
operator|::
name|CircleWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|floatBased
operator|=
literal|false
expr_stmt|;
name|antialiased
operator|=
literal|false
expr_stmt|;
name|frameNo
operator|=
literal|0
expr_stmt|;
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|)
expr_stmt|;
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
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
DECL|function|setFloatBased
name|void
name|CircleWidget
operator|::
name|setFloatBased
parameter_list|(
name|bool
name|floatBased
parameter_list|)
block|{
name|this
operator|->
name|floatBased
operator|=
name|floatBased
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|setAntialiased
name|void
name|CircleWidget
operator|::
name|setAntialiased
parameter_list|(
name|bool
name|antialiased
parameter_list|)
block|{
name|this
operator|->
name|antialiased
operator|=
name|antialiased
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|minimumSizeHint
name|QSize
name|CircleWidget
operator|::
name|minimumSizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|CircleWidget
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|180
argument_list|,
literal|180
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|nextAnimationFrame
name|void
name|CircleWidget
operator|::
name|nextAnimationFrame
parameter_list|()
block|{
operator|++
name|frameNo
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|CircleWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
name|antialiased
argument_list|)
expr_stmt|;
name|painter
operator|.
name|translate
argument_list|(
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
comment|//! [6]
comment|//! [7]
for|for
control|(
name|int
name|diameter
init|=
literal|0
init|;
name|diameter
operator|<
literal|256
condition|;
name|diameter
operator|+=
literal|9
control|)
block|{
name|int
name|delta
init|=
name|abs
argument_list|(
operator|(
name|frameNo
operator|%
literal|128
operator|)
operator|-
name|diameter
operator|/
literal|2
argument_list|)
decl_stmt|;
name|int
name|alpha
init|=
literal|255
operator|-
operator|(
name|delta
operator|*
name|delta
operator|)
operator|/
literal|4
operator|-
name|diameter
decl_stmt|;
comment|//! [7] //! [8]
if|if
condition|(
name|alpha
operator|>
literal|0
condition|)
block|{
name|painter
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|QColor
argument_list|(
literal|0
argument_list|,
name|diameter
operator|/
literal|2
argument_list|,
literal|127
argument_list|,
name|alpha
argument_list|)
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|floatBased
condition|)
name|painter
operator|.
name|drawEllipse
argument_list|(
name|QRectF
argument_list|(
operator|-
name|diameter
operator|/
literal|2.0
argument_list|,
operator|-
name|diameter
operator|/
literal|2.0
argument_list|,
name|diameter
argument_list|,
name|diameter
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|painter
operator|.
name|drawEllipse
argument_list|(
name|QRect
argument_list|(
operator|-
name|diameter
operator|/
literal|2
argument_list|,
operator|-
name|diameter
operator|/
literal|2
argument_list|,
name|diameter
argument_list|,
name|diameter
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|//! [8]
end_comment
end_unit
