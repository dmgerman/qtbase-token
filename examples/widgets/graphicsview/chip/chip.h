begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QColor>
end_include
begin_include
include|#
directive|include
file|<QGraphicsItem>
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
name|Q_DECL_OVERRIDE
block|;
name|QPainterPath
name|shape
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionGraphicsItem *item
argument_list|,
argument|QWidget *widget
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|void
name|mousePressEvent
argument_list|(
argument|QGraphicsSceneMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseMoveEvent
argument_list|(
argument|QGraphicsSceneMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseReleaseEvent
argument_list|(
argument|QGraphicsSceneMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|int
name|x
block|;
name|int
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
begin_comment
comment|// CHIP_H
end_comment
end_unit
