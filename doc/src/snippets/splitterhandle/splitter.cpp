begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"splitter.h"
end_include
begin_constructor
DECL|function|SplitterHandle
name|SplitterHandle
operator|::
name|SplitterHandle
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
name|QSplitter
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QSplitterHandle
argument_list|(
name|orientation
argument_list|,
name|parent
argument_list|)
block|{
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.0
argument_list|,
name|Qt
operator|::
name|darkGreen
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.25
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
name|Qt
operator|::
name|darkGreen
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|SplitterHandle
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|orientation
argument_list|()
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
name|gradient
operator|.
name|setStart
argument_list|(
name|rect
argument_list|()
operator|.
name|left
argument_list|()
argument_list|,
name|rect
argument_list|()
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setFinalStop
argument_list|(
name|rect
argument_list|()
operator|.
name|right
argument_list|()
argument_list|,
name|rect
argument_list|()
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|gradient
operator|.
name|setStart
argument_list|(
name|rect
argument_list|()
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|rect
argument_list|()
operator|.
name|top
argument_list|()
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setFinalStop
argument_list|(
name|rect
argument_list|()
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|rect
argument_list|()
operator|.
name|bottom
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|painter
operator|.
name|fillRect
argument_list|(
name|event
operator|->
name|rect
argument_list|()
argument_list|,
name|QBrush
argument_list|(
name|gradient
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Splitter
name|Splitter
operator|::
name|Splitter
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QSplitter
argument_list|(
name|orientation
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|createHandle
name|QSplitterHandle
modifier|*
name|Splitter
operator|::
name|createHandle
parameter_list|()
block|{
return|return
operator|new
name|SplitterHandle
argument_list|(
name|orientation
argument_list|()
argument_list|,
name|this
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
end_unit
