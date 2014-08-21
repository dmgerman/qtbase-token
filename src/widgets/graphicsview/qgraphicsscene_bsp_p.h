begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSSCENEBSPTREE_P_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSSCENEBSPTREE_P_H
define|#
directive|define
name|QGRAPHICSSCENEBSPTREE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GRAPHICSVIEW
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGraphicsItem
name|class
name|QGraphicsItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneBspTreeVisitor
name|class
name|QGraphicsSceneBspTreeVisitor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneInsertItemBspTreeVisitor
name|class
name|QGraphicsSceneInsertItemBspTreeVisitor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneRemoveItemBspTreeVisitor
name|class
name|QGraphicsSceneRemoveItemBspTreeVisitor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneFindItemBspTreeVisitor
name|class
name|QGraphicsSceneFindItemBspTreeVisitor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGraphicsSceneBspTree
block|{
name|public
label|:
struct|struct
name|Node
block|{
enum|enum
name|Type
block|{
name|Horizontal
block|,
name|Vertical
block|,
name|Leaf
block|}
enum|;
union|union
block|{
name|qreal
name|offset
decl_stmt|;
name|int
name|leafIndex
decl_stmt|;
block|}
union|;
name|Type
name|type
decl_stmt|;
block|}
struct|;
name|QGraphicsSceneBspTree
argument_list|()
expr_stmt|;
operator|~
name|QGraphicsSceneBspTree
argument_list|()
expr_stmt|;
name|void
name|initialize
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|int
name|depth
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
name|void
name|insertItem
parameter_list|(
name|QGraphicsItem
modifier|*
name|item
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
function_decl|;
name|void
name|removeItem
parameter_list|(
name|QGraphicsItem
modifier|*
name|item
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
function_decl|;
name|void
name|removeItems
argument_list|(
specifier|const
name|QSet
operator|<
name|QGraphicsItem
operator|*
operator|>
operator|&
name|items
argument_list|)
decl_stmt|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|bool onlyTopLevelItems = false
argument_list|)
specifier|const
expr_stmt|;
name|int
name|leafCount
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|int
name|firstChildIndex
argument_list|(
name|int
name|index
argument_list|)
decl|const
block|{
return|return
name|index
operator|*
literal|2
operator|+
literal|1
return|;
block|}
specifier|inline
name|int
name|parentIndex
argument_list|(
name|int
name|index
argument_list|)
decl|const
block|{
return|return
name|index
operator|>
literal|0
condition|?
operator|(
operator|(
name|index
operator|&
literal|1
operator|)
condition|?
operator|(
operator|(
name|index
operator|-
literal|1
operator|)
operator|/
literal|2
operator|)
else|:
operator|(
operator|(
name|index
operator|-
literal|2
operator|)
operator|/
literal|2
operator|)
operator|)
else|:
operator|-
literal|1
return|;
block|}
name|QString
name|debug
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|initialize
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|int
name|depth
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
name|void
name|climbTree
argument_list|(
name|QGraphicsSceneBspTreeVisitor
operator|*
name|visitor
argument_list|,
specifier|const
name|QRectF
operator|&
name|rect
argument_list|,
name|int
name|index
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|QRectF
name|rectForIndex
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QVector
operator|<
name|Node
operator|>
name|nodes
expr_stmt|;
name|QVector
operator|<
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
expr|>
name|leaves
expr_stmt|;
name|int
name|leafCnt
decl_stmt|;
name|QRectF
name|rect
decl_stmt|;
name|QGraphicsSceneInsertItemBspTreeVisitor
modifier|*
name|insertVisitor
decl_stmt|;
name|QGraphicsSceneRemoveItemBspTreeVisitor
modifier|*
name|removeVisitor
decl_stmt|;
name|QGraphicsSceneFindItemBspTreeVisitor
modifier|*
name|findVisitor
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QGraphicsSceneBspTreeVisitor
block|{
name|public
label|:
name|virtual
operator|~
name|QGraphicsSceneBspTreeVisitor
argument_list|()
block|{ }
name|virtual
name|void
name|visit
argument_list|(
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
operator|*
name|items
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GRAPHICSVIEW
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGRAPHICSSCENEBSPTREE_P_H
end_comment
end_unit
