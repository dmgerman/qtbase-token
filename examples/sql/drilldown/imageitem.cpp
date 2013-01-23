begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"imageitem.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|ImageItem
name|ImageItem
operator|::
name|ImageItem
parameter_list|(
name|int
name|id
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsPixmapItem
argument_list|(
name|pixmap
argument_list|,
name|parent
argument_list|)
block|{
name|recordId
operator|=
name|id
expr_stmt|;
name|setAcceptHoverEvents
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|timeLine
operator|.
name|setDuration
argument_list|(
literal|150
argument_list|)
expr_stmt|;
name|timeLine
operator|.
name|setFrameRange
argument_list|(
literal|0
argument_list|,
literal|150
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|timeLine
argument_list|,
name|SIGNAL
argument_list|(
name|frameChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setFrame
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|timeLine
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateItemPosition
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|adjust
argument_list|()
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
DECL|function|hoverEnterEvent
name|void
name|ImageItem
operator|::
name|hoverEnterEvent
parameter_list|(
name|QGraphicsSceneHoverEvent
modifier|*
comment|/*event*/
parameter_list|)
block|{
name|timeLine
operator|.
name|setDirection
argument_list|(
name|QTimeLine
operator|::
name|Forward
argument_list|)
expr_stmt|;
if|if
condition|(
name|z
operator|!=
literal|1.0
condition|)
block|{
name|z
operator|=
literal|1.0
expr_stmt|;
name|updateItemPosition
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|timeLine
operator|.
name|state
argument_list|()
operator|==
name|QTimeLine
operator|::
name|NotRunning
condition|)
name|timeLine
operator|.
name|start
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
DECL|function|hoverLeaveEvent
name|void
name|ImageItem
operator|::
name|hoverLeaveEvent
parameter_list|(
name|QGraphicsSceneHoverEvent
modifier|*
comment|/*event*/
parameter_list|)
block|{
name|timeLine
operator|.
name|setDirection
argument_list|(
name|QTimeLine
operator|::
name|Backward
argument_list|)
expr_stmt|;
if|if
condition|(
name|z
operator|!=
literal|0.0
condition|)
name|z
operator|=
literal|0.0
expr_stmt|;
if|if
condition|(
name|timeLine
operator|.
name|state
argument_list|()
operator|==
name|QTimeLine
operator|::
name|NotRunning
condition|)
name|timeLine
operator|.
name|start
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
DECL|function|setFrame
name|void
name|ImageItem
operator|::
name|setFrame
parameter_list|(
name|int
name|frame
parameter_list|)
block|{
name|adjust
argument_list|()
expr_stmt|;
name|QPointF
name|center
init|=
name|boundingRect
argument_list|()
operator|.
name|center
argument_list|()
decl_stmt|;
name|setTransform
argument_list|(
name|QTransform
operator|::
name|fromTranslate
argument_list|(
name|center
operator|.
name|x
argument_list|()
argument_list|,
name|center
operator|.
name|y
argument_list|()
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setTransform
argument_list|(
name|QTransform
operator|::
name|fromScale
argument_list|(
literal|1
operator|+
name|frame
operator|/
literal|330.0
argument_list|,
literal|1
operator|+
name|frame
operator|/
literal|330.0
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setTransform
argument_list|(
name|QTransform
operator|::
name|fromTranslate
argument_list|(
operator|-
name|center
operator|.
name|x
argument_list|()
argument_list|,
operator|-
name|center
operator|.
name|y
argument_list|()
argument_list|)
argument_list|,
literal|true
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
DECL|function|adjust
name|void
name|ImageItem
operator|::
name|adjust
parameter_list|()
block|{
name|QMatrix
name|matrix
decl_stmt|;
name|matrix
operator|.
name|scale
argument_list|(
literal|150
operator|/
name|boundingRect
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
literal|120
operator|/
name|boundingRect
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|setMatrix
argument_list|(
name|matrix
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|id
name|int
name|ImageItem
operator|::
name|id
parameter_list|()
block|{
return|return
name|recordId
return|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|updateItemPosition
name|void
name|ImageItem
operator|::
name|updateItemPosition
parameter_list|()
block|{
name|setZValue
argument_list|(
name|z
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
end_unit
