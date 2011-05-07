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
file|"draglabel.h"
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
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|QFile
name|dictionaryFile
argument_list|(
literal|":/dictionary/words.txt"
argument_list|)
decl_stmt|;
name|dictionaryFile
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QTextStream
name|inputStream
argument_list|(
operator|&
name|dictionaryFile
argument_list|)
decl_stmt|;
comment|//! [0]
comment|//! [1]
name|int
name|x
init|=
literal|5
decl_stmt|;
name|int
name|y
init|=
literal|5
decl_stmt|;
while|while
condition|(
operator|!
name|inputStream
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QString
name|word
decl_stmt|;
name|inputStream
operator|>>
name|word
expr_stmt|;
if|if
condition|(
operator|!
name|word
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|DragLabel
modifier|*
name|wordLabel
init|=
operator|new
name|DragLabel
argument_list|(
name|word
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|wordLabel
operator|->
name|move
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|wordLabel
operator|->
name|show
argument_list|()
expr_stmt|;
name|wordLabel
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|x
operator|+=
name|wordLabel
operator|->
name|width
argument_list|()
operator|+
literal|2
expr_stmt|;
if|if
condition|(
name|x
operator|>=
literal|245
condition|)
block|{
name|x
operator|=
literal|5
expr_stmt|;
name|y
operator|+=
name|wordLabel
operator|->
name|height
argument_list|()
operator|+
literal|2
expr_stmt|;
block|}
block|}
block|}
comment|//! [1]
comment|//! [2]
ifndef|#
directive|ifndef
name|Q_WS_S60
comment|//Fridge magnets is used for demoing Qt on S60 and themed backgrounds look better than white
name|QPalette
name|newPalette
init|=
name|palette
argument_list|()
decl_stmt|;
name|newPalette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Window
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|setPalette
argument_list|(
name|newPalette
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setMinimumSize
argument_list|(
literal|400
argument_list|,
name|qMax
argument_list|(
literal|200
argument_list|,
name|y
argument_list|)
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Fridge Magnets"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [2] //! [3]
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
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
comment|//! [4] //! [5]
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasFormat
argument_list|(
literal|"application/x-fridgemagnet"
argument_list|)
condition|)
block|{
if|if
condition|(
name|children
argument_list|()
operator|.
name|contains
argument_list|(
name|event
operator|->
name|source
argument_list|()
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
name|acceptProposedAction
argument_list|()
expr_stmt|;
comment|//! [5] //! [6]
block|}
comment|//! [6] //! [7]
block|}
elseif|else
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasText
argument_list|()
condition|)
block|{
name|event
operator|->
name|acceptProposedAction
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
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
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
literal|"application/x-fridgemagnet"
argument_list|)
condition|)
block|{
if|if
condition|(
name|children
argument_list|()
operator|.
name|contains
argument_list|(
name|event
operator|->
name|source
argument_list|()
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
name|acceptProposedAction
argument_list|()
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasText
argument_list|()
condition|)
block|{
name|event
operator|->
name|acceptProposedAction
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
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
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
literal|"application/x-fridgemagnet"
argument_list|)
condition|)
block|{
specifier|const
name|QMimeData
modifier|*
name|mime
init|=
name|event
operator|->
name|mimeData
argument_list|()
decl_stmt|;
comment|//! [9] //! [10]
name|QByteArray
name|itemData
init|=
name|mime
operator|->
name|data
argument_list|(
literal|"application/x-fridgemagnet"
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
name|QString
name|text
decl_stmt|;
name|QPoint
name|offset
decl_stmt|;
name|dataStream
operator|>>
name|text
operator|>>
name|offset
expr_stmt|;
comment|//! [10]
comment|//! [11]
name|DragLabel
modifier|*
name|newLabel
init|=
operator|new
name|DragLabel
argument_list|(
name|text
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|newLabel
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
name|newLabel
operator|->
name|show
argument_list|()
expr_stmt|;
name|newLabel
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
comment|//! [11] //! [12]
block|}
elseif|else
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasText
argument_list|()
condition|)
block|{
name|QStringList
name|pieces
init|=
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|text
argument_list|()
operator|.
name|split
argument_list|(
name|QRegExp
argument_list|(
literal|"\\s+"
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
decl_stmt|;
name|QPoint
name|position
init|=
name|event
operator|->
name|pos
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QString
name|piece
decl|,
name|pieces
control|)
block|{
name|DragLabel
modifier|*
name|newLabel
init|=
operator|new
name|DragLabel
argument_list|(
name|piece
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|newLabel
operator|->
name|move
argument_list|(
name|position
argument_list|)
expr_stmt|;
name|newLabel
operator|->
name|show
argument_list|()
expr_stmt|;
name|newLabel
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|position
operator|+=
name|QPoint
argument_list|(
name|newLabel
operator|->
name|width
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|event
operator|->
name|acceptProposedAction
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
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
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
comment|//! [13]
comment|//! [14]
name|DragLabel
modifier|*
name|child
init|=
cast|static_cast
argument_list|<
name|DragLabel
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
name|QPoint
name|hotSpot
init|=
name|event
operator|->
name|pos
argument_list|()
operator|-
name|child
operator|->
name|pos
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
name|child
operator|->
name|labelText
argument_list|()
operator|<<
name|QPoint
argument_list|(
name|hotSpot
argument_list|)
expr_stmt|;
comment|//! [14]
comment|//! [15]
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
literal|"application/x-fridgemagnet"
argument_list|,
name|itemData
argument_list|)
expr_stmt|;
name|mimeData
operator|->
name|setText
argument_list|(
name|child
operator|->
name|labelText
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [15]
comment|//! [16]
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
operator|*
name|child
operator|->
name|pixmap
argument_list|()
argument_list|)
expr_stmt|;
name|drag
operator|->
name|setHotSpot
argument_list|(
name|hotSpot
argument_list|)
expr_stmt|;
name|child
operator|->
name|hide
argument_list|()
expr_stmt|;
comment|//! [16]
comment|//! [17]
if|if
condition|(
name|drag
operator|->
name|exec
argument_list|(
name|Qt
operator|::
name|MoveAction
operator||
name|Qt
operator|::
name|CopyAction
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
name|child
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [17]
end_comment
end_unit
