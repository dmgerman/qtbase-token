begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"pieceslist.h"
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
begin_constructor
DECL|function|PiecesList
name|PiecesList
operator|::
name|PiecesList
parameter_list|(
name|int
name|pieceSize
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QListWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_PieceSize
argument_list|(
name|pieceSize
argument_list|)
block|{
name|setDragEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setViewMode
argument_list|(
name|QListView
operator|::
name|IconMode
argument_list|)
expr_stmt|;
name|setIconSize
argument_list|(
name|QSize
argument_list|(
name|m_PieceSize
argument_list|,
name|m_PieceSize
argument_list|)
argument_list|)
expr_stmt|;
name|setSpacing
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setDropIndicatorShown
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|dragEnterEvent
name|void
name|PiecesList
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
DECL|function|dragMoveEvent
name|void
name|PiecesList
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
literal|"image/x-puzzle-piece"
argument_list|)
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
name|ignore
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|dropEvent
name|void
name|PiecesList
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
name|addPiece
argument_list|(
name|pixmap
argument_list|,
name|location
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
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|addPiece
name|void
name|PiecesList
operator|::
name|addPiece
parameter_list|(
name|QPixmap
name|pixmap
parameter_list|,
name|QPoint
name|location
parameter_list|)
block|{
name|QListWidgetItem
modifier|*
name|pieceItem
init|=
operator|new
name|QListWidgetItem
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|pieceItem
operator|->
name|setIcon
argument_list|(
name|QIcon
argument_list|(
name|pixmap
argument_list|)
argument_list|)
expr_stmt|;
name|pieceItem
operator|->
name|setData
argument_list|(
name|Qt
operator|::
name|UserRole
argument_list|,
name|QVariant
argument_list|(
name|pixmap
argument_list|)
argument_list|)
expr_stmt|;
name|pieceItem
operator|->
name|setData
argument_list|(
name|Qt
operator|::
name|UserRole
operator|+
literal|1
argument_list|,
name|location
argument_list|)
expr_stmt|;
name|pieceItem
operator|->
name|setFlags
argument_list|(
name|Qt
operator|::
name|ItemIsEnabled
operator||
name|Qt
operator|::
name|ItemIsSelectable
operator||
name|Qt
operator|::
name|ItemIsDragEnabled
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startDrag
name|void
name|PiecesList
operator|::
name|startDrag
parameter_list|(
name|Qt
operator|::
name|DropActions
comment|/*supportedActions*/
parameter_list|)
block|{
name|QListWidgetItem
modifier|*
name|item
init|=
name|currentItem
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
name|QPixmap
name|pixmap
init|=
name|qvariant_cast
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
name|item
operator|->
name|data
argument_list|(
name|Qt
operator|::
name|UserRole
argument_list|)
argument_list|)
decl_stmt|;
name|QPoint
name|location
init|=
name|item
operator|->
name|data
argument_list|(
name|Qt
operator|::
name|UserRole
operator|+
literal|1
argument_list|)
operator|.
name|toPoint
argument_list|()
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
name|QPoint
argument_list|(
name|pixmap
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|pixmap
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
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
condition|)
operator|delete
name|takeItem
argument_list|(
name|row
argument_list|(
name|item
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
