begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argv
parameter_list|,
name|char
modifier|*
name|args
index|[]
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argv
argument_list|,
name|args
argument_list|)
decl_stmt|;
comment|//! [0]
name|QGraphicsItem
modifier|*
name|ball
init|=
operator|new
name|QGraphicsEllipseItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
decl_stmt|;
name|QTimeLine
modifier|*
name|timer
init|=
operator|new
name|QTimeLine
argument_list|(
literal|5000
argument_list|)
decl_stmt|;
name|timer
operator|->
name|setFrameRange
argument_list|(
literal|0
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QGraphicsItemAnimation
modifier|*
name|animation
init|=
operator|new
name|QGraphicsItemAnimation
decl_stmt|;
name|animation
operator|->
name|setItem
argument_list|(
name|ball
argument_list|)
expr_stmt|;
name|animation
operator|->
name|setTimeLine
argument_list|(
name|timer
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|200
condition|;
operator|++
name|i
control|)
name|animation
operator|->
name|setPosAt
argument_list|(
name|i
operator|/
literal|200.0
argument_list|,
name|QPointF
argument_list|(
name|i
argument_list|,
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|QGraphicsScene
modifier|*
name|scene
init|=
operator|new
name|QGraphicsScene
argument_list|()
decl_stmt|;
name|scene
operator|->
name|setSceneRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|250
argument_list|,
literal|250
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|ball
argument_list|)
expr_stmt|;
name|QGraphicsView
modifier|*
name|view
init|=
operator|new
name|QGraphicsView
argument_list|(
name|scene
argument_list|)
decl_stmt|;
name|view
operator|->
name|show
argument_list|()
expr_stmt|;
name|timer
operator|->
name|start
argument_list|()
expr_stmt|;
comment|//! [0]
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
