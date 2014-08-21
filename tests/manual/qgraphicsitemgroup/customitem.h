begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
