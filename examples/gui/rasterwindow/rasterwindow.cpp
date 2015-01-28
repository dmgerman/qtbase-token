begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"rasterwindow.h"
end_include
begin_comment
comment|//! [1]
end_comment
begin_constructor
DECL|function|RasterWindow
name|RasterWindow
operator|::
name|RasterWindow
parameter_list|(
name|QWindow
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWindow
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_update_pending
argument_list|(
literal|false
argument_list|)
block|{
name|m_backingStore
operator|=
operator|new
name|QBackingStore
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|create
argument_list|()
expr_stmt|;
name|setGeometry
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|,
literal|300
argument_list|,
literal|200
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|event
name|bool
name|RasterWindow
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|UpdateRequest
condition|)
block|{
name|m_update_pending
operator|=
literal|false
expr_stmt|;
name|renderNow
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
name|QWindow
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|renderLater
name|void
name|RasterWindow
operator|::
name|renderLater
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_update_pending
condition|)
block|{
name|m_update_pending
operator|=
literal|true
expr_stmt|;
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|UpdateRequest
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|RasterWindow
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|resizeEvent
parameter_list|)
block|{
name|m_backingStore
operator|->
name|resize
argument_list|(
name|resizeEvent
operator|->
name|size
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|isExposed
argument_list|()
condition|)
name|renderNow
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|exposeEvent
name|void
name|RasterWindow
operator|::
name|exposeEvent
parameter_list|(
name|QExposeEvent
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|isExposed
argument_list|()
condition|)
block|{
name|renderNow
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|renderNow
name|void
name|RasterWindow
operator|::
name|renderNow
parameter_list|()
block|{
if|if
condition|(
operator|!
name|isExposed
argument_list|()
condition|)
return|return;
name|QRect
name|rect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|m_backingStore
operator|->
name|beginPaint
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QPaintDevice
modifier|*
name|device
init|=
name|m_backingStore
operator|->
name|paintDevice
argument_list|()
decl_stmt|;
name|QPainter
name|painter
argument_list|(
name|device
argument_list|)
decl_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|render
argument_list|(
operator|&
name|painter
argument_list|)
expr_stmt|;
name|m_backingStore
operator|->
name|endPaint
argument_list|()
expr_stmt|;
name|m_backingStore
operator|->
name|flush
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|render
name|void
name|RasterWindow
operator|::
name|render
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|)
block|{
name|painter
operator|->
name|drawText
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
name|QStringLiteral
argument_list|(
literal|"QWindow"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
end_unit
