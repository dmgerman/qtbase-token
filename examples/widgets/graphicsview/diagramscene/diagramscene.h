begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DIAGRAMSCENE_H
end_ifndef
begin_define
DECL|macro|DIAGRAMSCENE_H
define|#
directive|define
name|DIAGRAMSCENE_H
end_define
begin_include
include|#
directive|include
file|"diagramitem.h"
end_include
begin_include
include|#
directive|include
file|"diagramtextitem.h"
end_include
begin_include
include|#
directive|include
file|<QGraphicsScene>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGraphicsSceneMouseEvent
name|class
name|QGraphicsSceneMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPointF
name|class
name|QPointF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsLineItem
name|class
name|QGraphicsLineItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFont
name|class
name|QFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsTextItem
name|class
name|QGraphicsTextItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColor
name|class
name|QColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|DiagramScene
range|:
name|public
name|QGraphicsScene
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Mode
block|{
name|InsertItem
block|,
name|InsertLine
block|,
name|InsertText
block|,
name|MoveItem
block|}
block|;
name|explicit
name|DiagramScene
argument_list|(
name|QMenu
operator|*
name|itemMenu
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QFont
name|font
argument_list|()
specifier|const
block|{
return|return
name|myFont
return|;
block|}
name|QColor
name|textColor
argument_list|()
specifier|const
block|{
return|return
name|myTextColor
return|;
block|}
name|QColor
name|itemColor
argument_list|()
specifier|const
block|{
return|return
name|myItemColor
return|;
block|}
name|QColor
name|lineColor
argument_list|()
specifier|const
block|{
return|return
name|myLineColor
return|;
block|}
name|void
name|setLineColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|void
name|setTextColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|void
name|setItemColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|void
name|setFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|setMode
argument_list|(
argument|Mode mode
argument_list|)
block|;
name|void
name|setItemType
argument_list|(
argument|DiagramItem::DiagramType type
argument_list|)
block|;
name|void
name|editorLostFocus
argument_list|(
name|DiagramTextItem
operator|*
name|item
argument_list|)
block|;
name|signals
operator|:
name|void
name|itemInserted
argument_list|(
name|DiagramItem
operator|*
name|item
argument_list|)
block|;
name|void
name|textInserted
argument_list|(
name|QGraphicsTextItem
operator|*
name|item
argument_list|)
block|;
name|void
name|itemSelected
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|protected
operator|:
name|void
name|mousePressEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|mouseEvent
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|mouseEvent
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|mouseEvent
argument_list|)
block|;
name|private
operator|:
name|bool
name|isItemChange
argument_list|(
argument|int type
argument_list|)
block|;
name|DiagramItem
operator|::
name|DiagramType
name|myItemType
block|;
name|QMenu
operator|*
name|myItemMenu
block|;
name|Mode
name|myMode
block|;
name|bool
name|leftButtonDown
block|;
name|QPointF
name|startPoint
block|;
name|QGraphicsLineItem
operator|*
name|line
block|;
name|QFont
name|myFont
block|;
name|DiagramTextItem
operator|*
name|textItem
block|;
name|QColor
name|myTextColor
block|;
name|QColor
name|myItemColor
block|;
name|QColor
name|myLineColor
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// DIAGRAMSCENE_H
end_comment
end_unit
