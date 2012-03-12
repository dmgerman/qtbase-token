begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CHIP_H
end_ifndef
begin_define
DECL|macro|CHIP_H
define|#
directive|define
name|CHIP_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QColor>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsItem>
end_include
begin_decl_stmt
name|class
name|Chip
range|:
name|public
name|QGraphicsItem
block|{
name|public
operator|:
name|Chip
argument_list|(
argument|const QColor&color
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
name|QRectF
name|boundingRect
argument_list|()
specifier|const
block|;
name|QPainterPath
name|shape
argument_list|()
specifier|const
block|;
name|void
name|paint
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QStyleOptionGraphicsItem
operator|*
name|item
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|protected
operator|:
name|void
name|mousePressEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|int
name|x
block|,
name|y
block|;
name|QColor
name|color
block|;
name|QVector
operator|<
name|QPointF
operator|>
name|stuff
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
