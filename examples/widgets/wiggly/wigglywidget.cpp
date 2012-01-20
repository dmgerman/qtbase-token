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
file|"wigglywidget.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|WigglyWidget
name|WigglyWidget
operator|::
name|WigglyWidget
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
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Midlight
argument_list|)
expr_stmt|;
name|setAutoFillBackground
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QFont
name|newFont
init|=
name|font
argument_list|()
decl_stmt|;
name|newFont
operator|.
name|setPointSize
argument_list|(
name|newFont
operator|.
name|pointSize
argument_list|()
operator|+
literal|20
argument_list|)
expr_stmt|;
name|setFont
argument_list|(
name|newFont
argument_list|)
expr_stmt|;
name|step
operator|=
literal|0
expr_stmt|;
name|timer
operator|.
name|start
argument_list|(
literal|60
argument_list|,
name|this
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
DECL|function|paintEvent
name|void
name|WigglyWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
comment|/* event */
parameter_list|)
comment|//! [1] //! [2]
block|{
specifier|static
specifier|const
name|int
name|sineTable
index|[
literal|16
index|]
init|=
block|{
literal|0
block|,
literal|38
block|,
literal|71
block|,
literal|92
block|,
literal|100
block|,
literal|92
block|,
literal|71
block|,
literal|38
block|,
literal|0
block|,
operator|-
literal|38
block|,
operator|-
literal|71
block|,
operator|-
literal|92
block|,
operator|-
literal|100
block|,
operator|-
literal|92
block|,
operator|-
literal|71
block|,
operator|-
literal|38
block|}
decl_stmt|;
name|QFontMetrics
name|metrics
argument_list|(
name|font
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|x
init|=
operator|(
name|width
argument_list|()
operator|-
name|metrics
operator|.
name|width
argument_list|(
name|text
argument_list|)
operator|)
operator|/
literal|2
decl_stmt|;
name|int
name|y
init|=
operator|(
name|height
argument_list|()
operator|+
name|metrics
operator|.
name|ascent
argument_list|()
operator|-
name|metrics
operator|.
name|descent
argument_list|()
operator|)
operator|/
literal|2
decl_stmt|;
name|QColor
name|color
decl_stmt|;
comment|//! [2]
comment|//! [3]
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
comment|//! [3] //! [4]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|text
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|int
name|index
init|=
operator|(
name|step
operator|+
name|i
operator|)
operator|%
literal|16
decl_stmt|;
name|color
operator|.
name|setHsv
argument_list|(
operator|(
literal|15
operator|-
name|index
operator|)
operator|*
literal|16
argument_list|,
literal|255
argument_list|,
literal|191
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|color
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
name|x
argument_list|,
name|y
operator|-
operator|(
operator|(
name|sineTable
index|[
name|index
index|]
operator|*
name|metrics
operator|.
name|height
argument_list|()
operator|)
operator|/
literal|400
operator|)
argument_list|,
name|QString
argument_list|(
name|text
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|x
operator|+=
name|metrics
operator|.
name|width
argument_list|(
name|text
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|timerEvent
name|void
name|WigglyWidget
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
comment|//! [5] //! [6]
block|{
if|if
condition|(
name|event
operator|->
name|timerId
argument_list|()
operator|==
name|timer
operator|.
name|timerId
argument_list|()
condition|)
block|{
operator|++
name|step
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QWidget
operator|::
name|timerEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
comment|//! [6]
block|}
end_function
end_unit
