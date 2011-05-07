begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"dragwidget.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|DragWidget
name|DragWidget
operator|::
name|DragWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QFrame
argument_list|(
name|parent
argument_list|)
block|{
name|setMinimumSize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|setFrameStyle
argument_list|(
name|QFrame
operator|::
name|Sunken
operator||
name|QFrame
operator|::
name|StyledPanel
argument_list|)
expr_stmt|;
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|boatIcon
init|=
operator|new
name|QLabel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|boatIcon
operator|->
name|setPixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/boat.png"
argument_list|)
argument_list|)
expr_stmt|;
name|boatIcon
operator|->
name|move
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|boatIcon
operator|->
name|show
argument_list|()
expr_stmt|;
name|boatIcon
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|carIcon
init|=
operator|new
name|QLabel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|carIcon
operator|->
name|setPixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/car.png"
argument_list|)
argument_list|)
expr_stmt|;
name|carIcon
operator|->
name|move
argument_list|(
literal|120
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|carIcon
operator|->
name|show
argument_list|()
expr_stmt|;
name|carIcon
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|houseIcon
init|=
operator|new
name|QLabel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|houseIcon
operator|->
name|setPixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/house.png"
argument_list|)
argument_list|)
expr_stmt|;
name|houseIcon
operator|->
name|move
argument_list|(
literal|20
argument_list|,
literal|120
argument_list|)
expr_stmt|;
name|houseIcon
operator|->
name|show
argument_list|()
expr_stmt|;
name|houseIcon
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|dragEnterEvent
name|void
name|DragWidget
operator|::
name|dragEnterEvent
parameter_list|(
name|QDragEnterEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasFormat
argument_list|(
literal|"application/x-dnditemdata"
argument_list|)
condition|)
block|{
if|if
condition|(
name|event
operator|->
name|source
argument_list|()
operator|==
name|this
condition|)
block|{
name|event
operator|->
name|setDropAction
argument_list|(
name|Qt
operator|::
name|MoveAction
argument_list|)
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|dragMoveEvent
name|void
name|DragWidget
operator|::
name|dragMoveEvent
parameter_list|(
name|QDragMoveEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasFormat
argument_list|(
literal|"application/x-dnditemdata"
argument_list|)
condition|)
block|{
if|if
condition|(
name|event
operator|->
name|source
argument_list|()
operator|==
name|this
condition|)
block|{
name|event
operator|->
name|setDropAction
argument_list|(
name|Qt
operator|::
name|MoveAction
argument_list|)
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|dropEvent
name|void
name|DragWidget
operator|::
name|dropEvent
parameter_list|(
name|QDropEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasFormat
argument_list|(
literal|"application/x-dnditemdata"
argument_list|)
condition|)
block|{
name|QByteArray
name|itemData
init|=
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|data
argument_list|(
literal|"application/x-dnditemdata"
argument_list|)
decl_stmt|;
name|QDataStream
name|dataStream
argument_list|(
operator|&
name|itemData
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|QPixmap
name|pixmap
decl_stmt|;
name|QPoint
name|offset
decl_stmt|;
name|dataStream
operator|>>
name|pixmap
operator|>>
name|offset
expr_stmt|;
name|QLabel
modifier|*
name|newIcon
init|=
operator|new
name|QLabel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|newIcon
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|newIcon
operator|->
name|move
argument_list|(
name|event
operator|->
name|pos
argument_list|()
operator|-
name|offset
argument_list|)
expr_stmt|;
name|newIcon
operator|->
name|show
argument_list|()
expr_stmt|;
name|newIcon
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|source
argument_list|()
operator|==
name|this
condition|)
block|{
name|event
operator|->
name|setDropAction
argument_list|(
name|Qt
operator|::
name|MoveAction
argument_list|)
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|DragWidget
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|QLabel
modifier|*
name|child
init|=
cast|static_cast
argument_list|<
name|QLabel
operator|*
argument_list|>
argument_list|(
name|childAt
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|child
condition|)
return|return;
name|QPixmap
name|pixmap
init|=
operator|*
name|child
operator|->
name|pixmap
argument_list|()
decl_stmt|;
name|QByteArray
name|itemData
decl_stmt|;
name|QDataStream
name|dataStream
argument_list|(
operator|&
name|itemData
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|dataStream
operator|<<
name|pixmap
operator|<<
name|QPoint
argument_list|(
name|event
operator|->
name|pos
argument_list|()
operator|-
name|child
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|QMimeData
modifier|*
name|mimeData
init|=
operator|new
name|QMimeData
decl_stmt|;
name|mimeData
operator|->
name|setData
argument_list|(
literal|"application/x-dnditemdata"
argument_list|,
name|itemData
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|QDrag
modifier|*
name|drag
init|=
operator|new
name|QDrag
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|drag
operator|->
name|setMimeData
argument_list|(
name|mimeData
argument_list|)
expr_stmt|;
name|drag
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|drag
operator|->
name|setHotSpot
argument_list|(
name|event
operator|->
name|pos
argument_list|()
operator|-
name|child
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [3]
name|QPixmap
name|tempPixmap
init|=
name|pixmap
decl_stmt|;
name|QPainter
name|painter
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|tempPixmap
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|pixmap
operator|.
name|rect
argument_list|()
argument_list|,
name|QColor
argument_list|(
literal|127
argument_list|,
literal|127
argument_list|,
literal|127
argument_list|,
literal|127
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
name|child
operator|->
name|setPixmap
argument_list|(
name|tempPixmap
argument_list|)
expr_stmt|;
if|if
condition|(
name|drag
operator|->
name|exec
argument_list|(
name|Qt
operator|::
name|CopyAction
operator||
name|Qt
operator|::
name|MoveAction
argument_list|,
name|Qt
operator|::
name|CopyAction
argument_list|)
operator|==
name|Qt
operator|::
name|MoveAction
condition|)
name|child
operator|->
name|close
argument_list|()
expr_stmt|;
else|else
block|{
name|child
operator|->
name|show
argument_list|()
expr_stmt|;
name|child
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
