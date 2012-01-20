begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"diagramscene.h"
end_include
begin_include
include|#
directive|include
file|"arrow.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|DiagramScene
name|DiagramScene
operator|::
name|DiagramScene
parameter_list|(
name|QMenu
modifier|*
name|itemMenu
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsScene
argument_list|(
name|parent
argument_list|)
block|{
name|myItemMenu
operator|=
name|itemMenu
expr_stmt|;
name|myMode
operator|=
name|MoveItem
expr_stmt|;
name|myItemType
operator|=
name|DiagramItem
operator|::
name|Step
expr_stmt|;
name|line
operator|=
literal|0
expr_stmt|;
name|textItem
operator|=
literal|0
expr_stmt|;
name|myItemColor
operator|=
name|Qt
operator|::
name|white
expr_stmt|;
name|myTextColor
operator|=
name|Qt
operator|::
name|black
expr_stmt|;
name|myLineColor
operator|=
name|Qt
operator|::
name|black
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
DECL|function|setLineColor
name|void
name|DiagramScene
operator|::
name|setLineColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|myLineColor
operator|=
name|color
expr_stmt|;
if|if
condition|(
name|isItemChange
argument_list|(
name|Arrow
operator|::
name|Type
argument_list|)
condition|)
block|{
name|Arrow
modifier|*
name|item
init|=
name|qgraphicsitem_cast
argument_list|<
name|Arrow
operator|*
argument_list|>
argument_list|(
name|selectedItems
argument_list|()
operator|.
name|first
argument_list|()
argument_list|)
decl_stmt|;
name|item
operator|->
name|setColor
argument_list|(
name|myLineColor
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|setTextColor
name|void
name|DiagramScene
operator|::
name|setTextColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|myTextColor
operator|=
name|color
expr_stmt|;
if|if
condition|(
name|isItemChange
argument_list|(
name|DiagramTextItem
operator|::
name|Type
argument_list|)
condition|)
block|{
name|DiagramTextItem
modifier|*
name|item
init|=
name|qgraphicsitem_cast
argument_list|<
name|DiagramTextItem
operator|*
argument_list|>
argument_list|(
name|selectedItems
argument_list|()
operator|.
name|first
argument_list|()
argument_list|)
decl_stmt|;
name|item
operator|->
name|setDefaultTextColor
argument_list|(
name|myTextColor
argument_list|)
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
DECL|function|setItemColor
name|void
name|DiagramScene
operator|::
name|setItemColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|myItemColor
operator|=
name|color
expr_stmt|;
if|if
condition|(
name|isItemChange
argument_list|(
name|DiagramItem
operator|::
name|Type
argument_list|)
condition|)
block|{
name|DiagramItem
modifier|*
name|item
init|=
name|qgraphicsitem_cast
argument_list|<
name|DiagramItem
operator|*
argument_list|>
argument_list|(
name|selectedItems
argument_list|()
operator|.
name|first
argument_list|()
argument_list|)
decl_stmt|;
name|item
operator|->
name|setBrush
argument_list|(
name|myItemColor
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|setFont
name|void
name|DiagramScene
operator|::
name|setFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
block|{
name|myFont
operator|=
name|font
expr_stmt|;
if|if
condition|(
name|isItemChange
argument_list|(
name|DiagramTextItem
operator|::
name|Type
argument_list|)
condition|)
block|{
name|QGraphicsTextItem
modifier|*
name|item
init|=
name|qgraphicsitem_cast
argument_list|<
name|DiagramTextItem
operator|*
argument_list|>
argument_list|(
name|selectedItems
argument_list|()
operator|.
name|first
argument_list|()
argument_list|)
decl_stmt|;
comment|//At this point the selection can change so the first selected item might not be a DiagramTextItem
if|if
condition|(
name|item
condition|)
name|item
operator|->
name|setFont
argument_list|(
name|myFont
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|setMode
name|void
name|DiagramScene
operator|::
name|setMode
parameter_list|(
name|Mode
name|mode
parameter_list|)
block|{
name|myMode
operator|=
name|mode
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setItemType
name|void
name|DiagramScene
operator|::
name|setItemType
parameter_list|(
name|DiagramItem
operator|::
name|DiagramType
name|type
parameter_list|)
block|{
name|myItemType
operator|=
name|type
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|editorLostFocus
name|void
name|DiagramScene
operator|::
name|editorLostFocus
parameter_list|(
name|DiagramTextItem
modifier|*
name|item
parameter_list|)
block|{
name|QTextCursor
name|cursor
init|=
name|item
operator|->
name|textCursor
argument_list|()
decl_stmt|;
name|cursor
operator|.
name|clearSelection
argument_list|()
expr_stmt|;
name|item
operator|->
name|setTextCursor
argument_list|(
name|cursor
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
operator|->
name|toPlainText
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|removeItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|item
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
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
name|DiagramScene
operator|::
name|mousePressEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|mouseEvent
parameter_list|)
block|{
if|if
condition|(
name|mouseEvent
operator|->
name|button
argument_list|()
operator|!=
name|Qt
operator|::
name|LeftButton
condition|)
return|return;
name|DiagramItem
modifier|*
name|item
decl_stmt|;
switch|switch
condition|(
name|myMode
condition|)
block|{
case|case
name|InsertItem
case|:
name|item
operator|=
operator|new
name|DiagramItem
argument_list|(
name|myItemType
argument_list|,
name|myItemMenu
argument_list|)
expr_stmt|;
name|item
operator|->
name|setBrush
argument_list|(
name|myItemColor
argument_list|)
expr_stmt|;
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|item
operator|->
name|setPos
argument_list|(
name|mouseEvent
operator|->
name|scenePos
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|itemInserted
argument_list|(
name|item
argument_list|)
emit|;
break|break;
comment|//! [6] //! [7]
case|case
name|InsertLine
case|:
name|line
operator|=
operator|new
name|QGraphicsLineItem
argument_list|(
name|QLineF
argument_list|(
name|mouseEvent
operator|->
name|scenePos
argument_list|()
argument_list|,
name|mouseEvent
operator|->
name|scenePos
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|line
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|myLineColor
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|addItem
argument_list|(
name|line
argument_list|)
expr_stmt|;
break|break;
comment|//! [7] //! [8]
case|case
name|InsertText
case|:
name|textItem
operator|=
operator|new
name|DiagramTextItem
argument_list|()
expr_stmt|;
name|textItem
operator|->
name|setFont
argument_list|(
name|myFont
argument_list|)
expr_stmt|;
name|textItem
operator|->
name|setTextInteractionFlags
argument_list|(
name|Qt
operator|::
name|TextEditorInteraction
argument_list|)
expr_stmt|;
name|textItem
operator|->
name|setZValue
argument_list|(
literal|1000.0
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|textItem
argument_list|,
name|SIGNAL
argument_list|(
name|lostFocus
argument_list|(
name|DiagramTextItem
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|editorLostFocus
argument_list|(
name|DiagramTextItem
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|textItem
argument_list|,
name|SIGNAL
argument_list|(
name|selectedChange
argument_list|(
name|QGraphicsItem
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|itemSelected
argument_list|(
name|QGraphicsItem
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|addItem
argument_list|(
name|textItem
argument_list|)
expr_stmt|;
name|textItem
operator|->
name|setDefaultTextColor
argument_list|(
name|myTextColor
argument_list|)
expr_stmt|;
name|textItem
operator|->
name|setPos
argument_list|(
name|mouseEvent
operator|->
name|scenePos
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|textInserted
argument_list|(
name|textItem
argument_list|)
emit|;
comment|//! [8] //! [9]
default|default:
empty_stmt|;
block|}
name|QGraphicsScene
operator|::
name|mousePressEvent
argument_list|(
name|mouseEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|DiagramScene
operator|::
name|mouseMoveEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|mouseEvent
parameter_list|)
block|{
if|if
condition|(
name|myMode
operator|==
name|InsertLine
operator|&&
name|line
operator|!=
literal|0
condition|)
block|{
name|QLineF
name|newLine
argument_list|(
name|line
operator|->
name|line
argument_list|()
operator|.
name|p1
argument_list|()
argument_list|,
name|mouseEvent
operator|->
name|scenePos
argument_list|()
argument_list|)
decl_stmt|;
name|line
operator|->
name|setLine
argument_list|(
name|newLine
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|myMode
operator|==
name|MoveItem
condition|)
block|{
name|QGraphicsScene
operator|::
name|mouseMoveEvent
argument_list|(
name|mouseEvent
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|mouseReleaseEvent
name|void
name|DiagramScene
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|mouseEvent
parameter_list|)
block|{
if|if
condition|(
name|line
operator|!=
literal|0
operator|&&
name|myMode
operator|==
name|InsertLine
condition|)
block|{
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|startItems
init|=
name|items
argument_list|(
name|line
operator|->
name|line
argument_list|()
operator|.
name|p1
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|startItems
operator|.
name|count
argument_list|()
operator|&&
name|startItems
operator|.
name|first
argument_list|()
operator|==
name|line
condition|)
name|startItems
operator|.
name|removeFirst
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|endItems
init|=
name|items
argument_list|(
name|line
operator|->
name|line
argument_list|()
operator|.
name|p2
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|endItems
operator|.
name|count
argument_list|()
operator|&&
name|endItems
operator|.
name|first
argument_list|()
operator|==
name|line
condition|)
name|endItems
operator|.
name|removeFirst
argument_list|()
expr_stmt|;
name|removeItem
argument_list|(
name|line
argument_list|)
expr_stmt|;
operator|delete
name|line
expr_stmt|;
comment|//! [11] //! [12]
if|if
condition|(
name|startItems
operator|.
name|count
argument_list|()
operator|>
literal|0
operator|&&
name|endItems
operator|.
name|count
argument_list|()
operator|>
literal|0
operator|&&
name|startItems
operator|.
name|first
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|DiagramItem
operator|::
name|Type
operator|&&
name|endItems
operator|.
name|first
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|DiagramItem
operator|::
name|Type
operator|&&
name|startItems
operator|.
name|first
argument_list|()
operator|!=
name|endItems
operator|.
name|first
argument_list|()
condition|)
block|{
name|DiagramItem
modifier|*
name|startItem
init|=
name|qgraphicsitem_cast
argument_list|<
name|DiagramItem
operator|*
argument_list|>
argument_list|(
name|startItems
operator|.
name|first
argument_list|()
argument_list|)
decl_stmt|;
name|DiagramItem
modifier|*
name|endItem
init|=
name|qgraphicsitem_cast
argument_list|<
name|DiagramItem
operator|*
argument_list|>
argument_list|(
name|endItems
operator|.
name|first
argument_list|()
argument_list|)
decl_stmt|;
name|Arrow
modifier|*
name|arrow
init|=
operator|new
name|Arrow
argument_list|(
name|startItem
argument_list|,
name|endItem
argument_list|)
decl_stmt|;
name|arrow
operator|->
name|setColor
argument_list|(
name|myLineColor
argument_list|)
expr_stmt|;
name|startItem
operator|->
name|addArrow
argument_list|(
name|arrow
argument_list|)
expr_stmt|;
name|endItem
operator|->
name|addArrow
argument_list|(
name|arrow
argument_list|)
expr_stmt|;
name|arrow
operator|->
name|setZValue
argument_list|(
operator|-
literal|1000.0
argument_list|)
expr_stmt|;
name|addItem
argument_list|(
name|arrow
argument_list|)
expr_stmt|;
name|arrow
operator|->
name|updatePosition
argument_list|()
expr_stmt|;
block|}
block|}
comment|//! [12] //! [13]
name|line
operator|=
literal|0
expr_stmt|;
name|QGraphicsScene
operator|::
name|mouseReleaseEvent
argument_list|(
name|mouseEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_function
DECL|function|isItemChange
name|bool
name|DiagramScene
operator|::
name|isItemChange
parameter_list|(
name|int
name|type
parameter_list|)
block|{
foreach|foreach
control|(
name|QGraphicsItem
modifier|*
name|item
decl|,
name|selectedItems
argument_list|()
control|)
block|{
if|if
condition|(
name|item
operator|->
name|type
argument_list|()
operator|==
name|type
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|//! [14]
end_comment
end_unit
