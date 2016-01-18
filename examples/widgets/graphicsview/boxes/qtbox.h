begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTBOX_H
end_ifndef
begin_define
DECL|macro|QTBOX_H
define|#
directive|define
name|QTBOX_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtGui/qvector3d.h>
end_include
begin_include
include|#
directive|include
file|"glbuffers.h"
end_include
begin_decl_stmt
name|class
name|ItemBase
range|:
name|public
name|QGraphicsItem
block|{
name|public
operator|:
expr|enum
block|{
name|Type
operator|=
name|UserType
operator|+
literal|1
block|}
block|;
name|ItemBase
argument_list|(
argument|int size
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
name|virtual
operator|~
name|ItemBase
argument_list|()
block|;
name|virtual
name|QRectF
name|boundingRect
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionGraphicsItem *option
argument_list|,
argument|QWidget *widget
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|virtual
name|ItemBase
operator|*
name|createNew
argument_list|(
argument|int size
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|contextMenuEvent
argument_list|(
argument|QGraphicsSceneContextMenuEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|mouseMoveEvent
argument_list|(
argument|QGraphicsSceneMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|hoverMoveEvent
argument_list|(
argument|QGraphicsSceneHoverEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|mousePressEvent
argument_list|(
argument|QGraphicsSceneMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|mouseReleaseEvent
argument_list|(
argument|QGraphicsSceneMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|keyPressEvent
argument_list|(
argument|QKeyEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|wheelEvent
argument_list|(
argument|QGraphicsSceneWheelEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|int
name|type
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isInResizeArea
argument_list|(
specifier|const
name|QPointF
operator|&
name|pos
argument_list|)
block|;
specifier|static
name|void
name|duplicateSelectedItems
argument_list|(
name|QGraphicsScene
operator|*
name|scene
argument_list|)
block|;
specifier|static
name|void
name|deleteSelectedItems
argument_list|(
name|QGraphicsScene
operator|*
name|scene
argument_list|)
block|;
specifier|static
name|void
name|growSelectedItems
argument_list|(
name|QGraphicsScene
operator|*
name|scene
argument_list|)
block|;
specifier|static
name|void
name|shrinkSelectedItems
argument_list|(
name|QGraphicsScene
operator|*
name|scene
argument_list|)
block|;
name|int
name|m_size
block|;
name|QTime
name|m_startTime
block|;
name|bool
name|m_isResizing
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QtBox
range|:
name|public
name|ItemBase
block|{
name|public
operator|:
name|QtBox
argument_list|(
argument|int size
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
name|virtual
operator|~
name|QtBox
argument_list|()
block|;
name|virtual
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionGraphicsItem *option
argument_list|,
argument|QWidget *widget
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|virtual
name|ItemBase
operator|*
name|createNew
argument_list|(
argument|int size
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|QVector3D
name|m_vertices
index|[
literal|8
index|]
block|;
name|QVector3D
name|m_texCoords
index|[
literal|4
index|]
block|;
name|QVector3D
name|m_normals
index|[
literal|6
index|]
block|;
name|GLTexture
operator|*
name|m_texture
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|CircleItem
range|:
name|public
name|ItemBase
block|{
name|public
operator|:
name|CircleItem
argument_list|(
argument|int size
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
name|virtual
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionGraphicsItem *option
argument_list|,
argument|QWidget *widget
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|virtual
name|ItemBase
operator|*
name|createNew
argument_list|(
argument|int size
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QColor
name|m_color
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|SquareItem
range|:
name|public
name|ItemBase
block|{
name|public
operator|:
name|SquareItem
argument_list|(
argument|int size
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
name|virtual
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionGraphicsItem *option
argument_list|,
argument|QWidget *widget
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|virtual
name|ItemBase
operator|*
name|createNew
argument_list|(
argument|int size
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QPixmap
name|m_image
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
