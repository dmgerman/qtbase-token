begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
