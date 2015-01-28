begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"puzzlewidget.h"
end_include
begin_include
include|#
directive|include
file|<QDrag>
end_include
begin_include
include|#
directive|include
file|<QDragEnterEvent>
end_include
begin_include
include|#
directive|include
file|<QMimeData>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_constructor
DECL|function|PuzzleWidget
name|PuzzleWidget
operator|::
name|PuzzleWidget
parameter_list|(
name|int
name|imageSize
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_ImageSize
argument_list|(
name|imageSize
argument_list|)
block|{
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setMinimumSize
argument_list|(
name|m_ImageSize
argument_list|,
name|m_ImageSize
argument_list|)
expr_stmt|;
name|setMaximumSize
argument_list|(
name|m_ImageSize
argument_list|,
name|m_ImageSize
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|clear
name|void
name|PuzzleWidget
operator|::
name|clear
parameter_list|()
block|{
name|pieceLocations
operator|.
name|clear
argument_list|()
expr_stmt|;
name|piecePixmaps
operator|.
name|clear
argument_list|()
expr_stmt|;
name|pieceRects
operator|.
name|clear
argument_list|()
expr_stmt|;
name|highlightedRect
operator|=
name|QRect
argument_list|()
expr_stmt|;
name|inPlace
operator|=
literal|0
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dragEnterEvent
name|void
name|PuzzleWidget
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
literal|"image/x-puzzle-piece"
argument_list|)
condition|)
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
else|else
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dragLeaveEvent
name|void
name|PuzzleWidget
operator|::
name|dragLeaveEvent
parameter_list|(
name|QDragLeaveEvent
modifier|*
name|event
parameter_list|)
block|{
name|QRect
name|updateRect
init|=
name|highlightedRect
decl_stmt|;
name|highlightedRect
operator|=
name|QRect
argument_list|()
expr_stmt|;
name|update
argument_list|(
name|updateRect
argument_list|)
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dragMoveEvent
name|void
name|PuzzleWidget
operator|::
name|dragMoveEvent
parameter_list|(
name|QDragMoveEvent
modifier|*
name|event
parameter_list|)
block|{
name|QRect
name|updateRect
init|=
name|highlightedRect
operator|.
name|united
argument_list|(
name|targetSquare
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
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasFormat
argument_list|(
literal|"image/x-puzzle-piece"
argument_list|)
operator|&&
name|findPiece
argument_list|(
name|targetSquare
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|highlightedRect
operator|=
name|targetSquare
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
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
name|highlightedRect
operator|=
name|QRect
argument_list|()
expr_stmt|;
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
name|update
argument_list|(
name|updateRect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dropEvent
name|void
name|PuzzleWidget
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
literal|"image/x-puzzle-piece"
argument_list|)
operator|&&
name|findPiece
argument_list|(
name|targetSquare
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|QByteArray
name|pieceData
init|=
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|data
argument_list|(
literal|"image/x-puzzle-piece"
argument_list|)
decl_stmt|;
name|QDataStream
name|dataStream
argument_list|(
operator|&
name|pieceData
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|QRect
name|square
init|=
name|targetSquare
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
name|QPixmap
name|pixmap
decl_stmt|;
name|QPoint
name|location
decl_stmt|;
name|dataStream
operator|>>
name|pixmap
operator|>>
name|location
expr_stmt|;
name|pieceLocations
operator|.
name|append
argument_list|(
name|location
argument_list|)
expr_stmt|;
name|piecePixmaps
operator|.
name|append
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|pieceRects
operator|.
name|append
argument_list|(
name|square
argument_list|)
expr_stmt|;
name|highlightedRect
operator|=
name|QRect
argument_list|()
expr_stmt|;
name|update
argument_list|(
name|square
argument_list|)
expr_stmt|;
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
if|if
condition|(
name|location
operator|==
name|QPoint
argument_list|(
name|square
operator|.
name|x
argument_list|()
operator|/
name|pieceSize
argument_list|()
argument_list|,
name|square
operator|.
name|y
argument_list|()
operator|/
name|pieceSize
argument_list|()
argument_list|)
condition|)
block|{
name|inPlace
operator|++
expr_stmt|;
if|if
condition|(
name|inPlace
operator|==
literal|25
condition|)
emit|emit
name|puzzleCompleted
argument_list|()
emit|;
block|}
block|}
else|else
block|{
name|highlightedRect
operator|=
name|QRect
argument_list|()
expr_stmt|;
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|findPiece
name|int
name|PuzzleWidget
operator|::
name|findPiece
parameter_list|(
specifier|const
name|QRect
modifier|&
name|pieceRect
parameter_list|)
specifier|const
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|pieceRects
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|pieceRect
operator|==
name|pieceRects
index|[
name|i
index|]
condition|)
return|return
name|i
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|PuzzleWidget
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|QRect
name|square
init|=
name|targetSquare
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|found
init|=
name|findPiece
argument_list|(
name|square
argument_list|)
decl_stmt|;
if|if
condition|(
name|found
operator|==
operator|-
literal|1
condition|)
return|return;
name|QPoint
name|location
init|=
name|pieceLocations
index|[
name|found
index|]
decl_stmt|;
name|QPixmap
name|pixmap
init|=
name|piecePixmaps
index|[
name|found
index|]
decl_stmt|;
name|pieceLocations
operator|.
name|removeAt
argument_list|(
name|found
argument_list|)
expr_stmt|;
name|piecePixmaps
operator|.
name|removeAt
argument_list|(
name|found
argument_list|)
expr_stmt|;
name|pieceRects
operator|.
name|removeAt
argument_list|(
name|found
argument_list|)
expr_stmt|;
if|if
condition|(
name|location
operator|==
name|QPoint
argument_list|(
name|square
operator|.
name|x
argument_list|()
operator|/
name|pieceSize
argument_list|()
argument_list|,
name|square
operator|.
name|y
argument_list|()
operator|/
name|pieceSize
argument_list|()
argument_list|)
condition|)
name|inPlace
operator|--
expr_stmt|;
name|update
argument_list|(
name|square
argument_list|)
expr_stmt|;
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
name|location
expr_stmt|;
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
literal|"image/x-puzzle-piece"
argument_list|,
name|itemData
argument_list|)
expr_stmt|;
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
name|setHotSpot
argument_list|(
name|event
operator|->
name|pos
argument_list|()
operator|-
name|square
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
name|drag
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|drag
operator|->
name|exec
argument_list|(
name|Qt
operator|::
name|MoveAction
argument_list|)
operator|==
name|Qt
operator|::
name|MoveAction
operator|)
condition|)
block|{
name|pieceLocations
operator|.
name|insert
argument_list|(
name|found
argument_list|,
name|location
argument_list|)
expr_stmt|;
name|piecePixmaps
operator|.
name|insert
argument_list|(
name|found
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
name|pieceRects
operator|.
name|insert
argument_list|(
name|found
argument_list|,
name|square
argument_list|)
expr_stmt|;
name|update
argument_list|(
name|targetSquare
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|location
operator|==
name|QPoint
argument_list|(
name|square
operator|.
name|x
argument_list|()
operator|/
name|pieceSize
argument_list|()
argument_list|,
name|square
operator|.
name|y
argument_list|()
operator|/
name|pieceSize
argument_list|()
argument_list|)
condition|)
name|inPlace
operator|++
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|PuzzleWidget
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
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|event
operator|->
name|rect
argument_list|()
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
if|if
condition|(
name|highlightedRect
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|painter
operator|.
name|setBrush
argument_list|(
name|QColor
argument_list|(
literal|"#ffcccc"
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawRect
argument_list|(
name|highlightedRect
operator|.
name|adjusted
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|pieceRects
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|painter
operator|.
name|drawPixmap
argument_list|(
name|pieceRects
index|[
name|i
index|]
argument_list|,
name|piecePixmaps
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|targetSquare
specifier|const
name|QRect
name|PuzzleWidget
operator|::
name|targetSquare
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|position
parameter_list|)
specifier|const
block|{
return|return
name|QRect
argument_list|(
name|position
operator|.
name|x
argument_list|()
operator|/
name|pieceSize
argument_list|()
operator|*
name|pieceSize
argument_list|()
argument_list|,
name|position
operator|.
name|y
argument_list|()
operator|/
name|pieceSize
argument_list|()
operator|*
name|pieceSize
argument_list|()
argument_list|,
name|pieceSize
argument_list|()
argument_list|,
name|pieceSize
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|pieceSize
name|int
name|PuzzleWidget
operator|::
name|pieceSize
parameter_list|()
specifier|const
block|{
return|return
name|m_ImageSize
operator|/
literal|5
return|;
block|}
end_function
begin_function
DECL|function|imageSize
name|int
name|PuzzleWidget
operator|::
name|imageSize
parameter_list|()
specifier|const
block|{
return|return
name|m_ImageSize
return|;
block|}
end_function
end_unit
