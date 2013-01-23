begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"dragwidget.h"
end_include
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
name|setFrameStyle
argument_list|(
name|QFrame
operator|::
name|StyledPanel
operator||
name|QFrame
operator|::
name|Sunken
argument_list|)
expr_stmt|;
name|dragDropLabel
operator|=
operator|new
name|QLabel
argument_list|(
literal|""
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|dragDropLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|layout
operator|->
name|addStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|dragDropLabel
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|// Accept all actions, but deal with them separately later.
end_comment
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
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
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
name|source
argument_list|()
operator|==
name|this
operator|&&
name|event
operator|->
name|possibleActions
argument_list|()
operator|&
name|Qt
operator|::
name|MoveAction
condition|)
return|return;
comment|//! [1]
comment|//! [2]
if|if
condition|(
name|event
operator|->
name|proposedAction
argument_list|()
operator|==
name|Qt
operator|::
name|MoveAction
condition|)
block|{
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
comment|// Process the data from the event.
comment|//! [2]
emit|emit
name|dragResult
argument_list|(
name|tr
argument_list|(
literal|"The data was moved here."
argument_list|)
argument_list|)
emit|;
comment|//! [3]
block|}
elseif|else
if|if
condition|(
name|event
operator|->
name|proposedAction
argument_list|()
operator|==
name|Qt
operator|::
name|CopyAction
condition|)
block|{
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
comment|// Process the data from the event.
comment|//! [3]
emit|emit
name|dragResult
argument_list|(
name|tr
argument_list|(
literal|"The data was copied here."
argument_list|)
argument_list|)
emit|;
comment|//! [4]
block|}
else|else
block|{
comment|// Ignore the drop.
return|return;
block|}
comment|//! [4]
comment|// End of quote
emit|emit
name|mimeTypes
argument_list|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|formats
argument_list|()
argument_list|)
emit|;
name|setData
argument_list|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|formats
argument_list|()
index|[
literal|0
index|]
argument_list|,
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|data
argument_list|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|formats
argument_list|()
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [5]
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
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
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
name|dragStartPosition
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|DragWidget
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|event
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|LeftButton
operator|)
condition|)
return|return;
if|if
condition|(
operator|(
name|event
operator|->
name|pos
argument_list|()
operator|-
name|dragStartPosition
operator|)
operator|.
name|manhattanLength
argument_list|()
operator|<
name|QApplication
operator|::
name|startDragDistance
argument_list|()
condition|)
return|return;
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
name|mimeType
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|drag
operator|->
name|setMimeData
argument_list|(
name|mimeData
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|DropAction
name|dropAction
init|=
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
argument_list|)
decl_stmt|;
comment|//! [7]
switch|switch
condition|(
name|dropAction
condition|)
block|{
case|case
name|Qt
operator|::
name|CopyAction
case|:
emit|emit
name|dragResult
argument_list|(
name|tr
argument_list|(
literal|"The text was copied."
argument_list|)
argument_list|)
emit|;
break|break;
case|case
name|Qt
operator|::
name|MoveAction
case|:
emit|emit
name|dragResult
argument_list|(
name|tr
argument_list|(
literal|"The text was moved."
argument_list|)
argument_list|)
emit|;
break|break;
default|default:
emit|emit
name|dragResult
argument_list|(
name|tr
argument_list|(
literal|"Unknown action."
argument_list|)
argument_list|)
emit|;
break|break;
block|}
comment|//! [8]
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|setData
name|void
name|DragWidget
operator|::
name|setData
parameter_list|(
specifier|const
name|QString
modifier|&
name|mimetype
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|newData
parameter_list|)
block|{
name|mimeType
operator|=
name|mimetype
expr_stmt|;
name|data
operator|=
name|QByteArray
argument_list|(
name|newData
argument_list|)
expr_stmt|;
name|dragDropLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"%1 bytes"
argument_list|)
operator|.
name|arg
argument_list|(
name|data
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|formats
decl_stmt|;
name|formats
operator|<<
name|mimetype
expr_stmt|;
emit|emit
name|mimeTypes
argument_list|(
name|formats
argument_list|)
emit|;
block|}
end_function
end_unit
