begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CUSTOMITEM_H
end_ifndef
begin_define
DECL|macro|CUSTOMITEM_H
define|#
directive|define
name|CUSTOMITEM_H
end_define
begin_include
include|#
directive|include
file|<QGraphicsItem>
end_include
begin_include
include|#
directive|include
file|<QBrush>
end_include
begin_include
include|#
directive|include
file|<QGraphicsScene>
end_include
begin_decl_stmt
name|class
name|CustomGroup
range|:
name|public
name|QGraphicsItemGroup
block|{
name|public
operator|:
name|CustomGroup
argument_list|()
block|;
name|virtual
operator|~
name|CustomGroup
argument_list|()
block|{ }
name|protected
operator|:
name|virtual
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
name|option
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|virtual
name|QRectF
name|boundingRect
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|CustomItem
range|:
name|public
name|QGraphicsRectItem
block|{
name|public
operator|:
name|CustomItem
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal width
argument_list|,
argument|qreal height
argument_list|,
argument|const QBrush& brush = QBrush()
argument_list|)
block|;
name|virtual
operator|~
name|CustomItem
argument_list|()
block|{ }
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|CustomScene
range|:
name|public
name|QGraphicsScene
block|{
name|Q_OBJECT
name|public
operator|:
name|CustomScene
argument_list|()
operator|:
name|QGraphicsScene
argument_list|()
block|{ }
name|QList
operator|<
name|CustomItem
operator|*
operator|>
name|selectedCustomItems
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|CustomGroup
operator|*
operator|>
name|selectedCustomGroups
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// CUSTOMITEM_H
end_comment
end_unit
