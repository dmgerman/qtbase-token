begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PIECESLIST_H
end_ifndef
begin_define
DECL|macro|PIECESLIST_H
define|#
directive|define
name|PIECESLIST_H
end_define
begin_include
include|#
directive|include
file|<QListWidget>
end_include
begin_decl_stmt
name|class
name|PiecesList
range|:
name|public
name|QListWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|PiecesList
argument_list|(
argument|int pieceSize
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
name|void
name|addPiece
argument_list|(
argument|QPixmap pixmap
argument_list|,
argument|QPoint location
argument_list|)
block|;
specifier|static
name|QString
name|puzzleMimeType
argument_list|()
block|{
return|return
name|QStringLiteral
argument_list|(
literal|"image/x-puzzle-piece"
argument_list|)
return|;
block|}
name|protected
operator|:
name|void
name|dragEnterEvent
argument_list|(
argument|QDragEnterEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dragMoveEvent
argument_list|(
argument|QDragMoveEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dropEvent
argument_list|(
argument|QDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|startDrag
argument_list|(
argument|Qt::DropActions supportedActions
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|int
name|m_PieceSize
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PIECESLIST_H
end_comment
end_unit
