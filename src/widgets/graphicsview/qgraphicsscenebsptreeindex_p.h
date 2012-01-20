begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSBSPTREEINDEX_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSBSPTREEINDEX_H
define|#
directive|define
name|QGRAPHICSBSPTREEINDEX_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GRAPHICSVIEW
argument_list|)
operator|||
operator|(
name|QT_EDITION
operator|&
name|QT_MODULE_GRAPHICSVIEW
operator|)
operator|!=
name|QT_MODULE_GRAPHICSVIEW
end_if
begin_include
include|#
directive|include
file|"qgraphicssceneindex_p.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicsitem_p.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicsscene_bsp_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGRAPHICSSCENE_INDEXTIMER_TIMEOUT
specifier|static
specifier|const
name|int
name|QGRAPHICSSCENE_INDEXTIMER_TIMEOUT
init|=
literal|2000
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsScene
name|class
name|QGraphicsScene
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneBspTreeIndexPrivate
name|class
name|QGraphicsSceneBspTreeIndexPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QGraphicsSceneBspTreeIndex
range|:
name|public
name|QGraphicsSceneIndex
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int bspTreeDepth READ bspTreeDepth WRITE setBspTreeDepth
argument_list|)
name|public
operator|:
name|QGraphicsSceneBspTreeIndex
argument_list|(
name|QGraphicsScene
operator|*
name|scene
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QGraphicsSceneBspTreeIndex
argument_list|()
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|estimateItems
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|Qt::SortOrder order
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|estimateTopLevelItems
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|Qt::SortOrder order
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|(
argument|Qt::SortOrder order = Qt::DescendingOrder
argument_list|)
specifier|const
block|;
name|int
name|bspTreeDepth
argument_list|()
specifier|const
block|;
name|void
name|setBspTreeDepth
argument_list|(
argument|int depth
argument_list|)
block|;
name|protected
name|Q_SLOTS
operator|:
name|void
name|updateSceneRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|void
name|addItem
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|void
name|removeItem
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|void
name|prepareBoundingRectChange
argument_list|(
specifier|const
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|void
name|itemChange
argument_list|(
argument|const QGraphicsItem *item
argument_list|,
argument|QGraphicsItem::GraphicsItemChange change
argument_list|,
argument|const void *const value
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsSceneBspTreeIndex
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsSceneBspTreeIndex
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateSortCache()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateIndex()
argument_list|)
name|friend
name|class
name|QGraphicsScene
block|;
name|friend
name|class
name|QGraphicsScenePrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGraphicsSceneBspTreeIndexPrivate
range|:
name|public
name|QGraphicsSceneIndexPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsSceneBspTreeIndex
argument_list|)
name|public
operator|:
name|QGraphicsSceneBspTreeIndexPrivate
argument_list|(
name|QGraphicsScene
operator|*
name|scene
argument_list|)
block|;
name|QGraphicsSceneBspTree
name|bsp
block|;
name|QRectF
name|sceneRect
block|;
name|int
name|bspTreeDepth
block|;
name|int
name|indexTimerId
block|;
name|bool
name|restartIndexTimer
block|;
name|bool
name|regenerateIndex
block|;
name|int
name|lastItemCount
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|indexedItems
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|unindexedItems
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|untransformableItems
block|;
name|QList
operator|<
name|int
operator|>
name|freeItemIndexes
block|;
name|bool
name|purgePending
block|;
name|QSet
operator|<
name|QGraphicsItem
operator|*
operator|>
name|removedItems
block|;
name|void
name|purgeRemovedItems
argument_list|()
block|;
name|void
name|_q_updateIndex
argument_list|()
block|;
name|void
name|startIndexTimer
argument_list|(
argument|int interval = QGRAPHICSSCENE_INDEXTIMER_TIMEOUT
argument_list|)
block|;
name|void
name|resetIndex
argument_list|()
block|;
name|void
name|_q_updateSortCache
argument_list|()
block|;
name|bool
name|sortCacheEnabled
block|;
name|bool
name|updatingSortCache
block|;
name|void
name|invalidateSortCache
argument_list|()
block|;
name|void
name|addItem
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|bool recursive = false
argument_list|)
block|;
name|void
name|removeItem
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|bool recursive = false
argument_list|,
argument|bool moveToUnindexedItems = false
argument_list|)
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|estimateItems
argument_list|(
argument|const QRectF&
argument_list|,
argument|Qt::SortOrder
argument_list|,
argument|bool b = false
argument_list|)
block|;
specifier|static
name|void
name|climbTree
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|,
name|int
operator|*
name|stackingOrder
argument_list|)
block|;
specifier|static
specifier|inline
name|bool
name|closestItemFirst_withCache
argument_list|(
argument|const QGraphicsItem *item1
argument_list|,
argument|const QGraphicsItem *item2
argument_list|)
block|{
return|return
name|item1
operator|->
name|d_ptr
operator|->
name|globalStackingOrder
operator|<
name|item2
operator|->
name|d_ptr
operator|->
name|globalStackingOrder
return|;
block|}
specifier|static
specifier|inline
name|bool
name|closestItemLast_withCache
argument_list|(
argument|const QGraphicsItem *item1
argument_list|,
argument|const QGraphicsItem *item2
argument_list|)
block|{
return|return
name|item1
operator|->
name|d_ptr
operator|->
name|globalStackingOrder
operator|>=
name|item2
operator|->
name|d_ptr
operator|->
name|globalStackingOrder
return|;
block|}
specifier|static
name|void
name|sortItems
argument_list|(
argument|QList<QGraphicsItem *> *itemList
argument_list|,
argument|Qt::SortOrder order
argument_list|,
argument|bool cached
argument_list|,
argument|bool onlyTopLevelItems = false
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|QRectF_intersects
specifier|static
specifier|inline
name|bool
name|QRectF_intersects
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|s
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|r
parameter_list|)
block|{
name|qreal
name|xp
init|=
name|s
operator|.
name|left
argument_list|()
decl_stmt|;
name|qreal
name|yp
init|=
name|s
operator|.
name|top
argument_list|()
decl_stmt|;
name|qreal
name|w
init|=
name|s
operator|.
name|width
argument_list|()
decl_stmt|;
name|qreal
name|h
init|=
name|s
operator|.
name|height
argument_list|()
decl_stmt|;
name|qreal
name|l1
init|=
name|xp
decl_stmt|;
name|qreal
name|r1
init|=
name|xp
decl_stmt|;
if|if
condition|(
name|w
operator|<
literal|0
condition|)
name|l1
operator|+=
name|w
expr_stmt|;
else|else
name|r1
operator|+=
name|w
expr_stmt|;
name|qreal
name|l2
init|=
name|r
operator|.
name|left
argument_list|()
decl_stmt|;
name|qreal
name|r2
init|=
name|r
operator|.
name|left
argument_list|()
decl_stmt|;
if|if
condition|(
name|w
operator|<
literal|0
condition|)
name|l2
operator|+=
name|r
operator|.
name|width
argument_list|()
expr_stmt|;
else|else
name|r2
operator|+=
name|r
operator|.
name|width
argument_list|()
expr_stmt|;
if|if
condition|(
name|l1
operator|>=
name|r2
operator|||
name|l2
operator|>=
name|r1
condition|)
return|return
name|false
return|;
name|qreal
name|t1
init|=
name|yp
decl_stmt|;
name|qreal
name|b1
init|=
name|yp
decl_stmt|;
if|if
condition|(
name|h
operator|<
literal|0
condition|)
name|t1
operator|+=
name|h
expr_stmt|;
else|else
name|b1
operator|+=
name|h
expr_stmt|;
name|qreal
name|t2
init|=
name|r
operator|.
name|top
argument_list|()
decl_stmt|;
name|qreal
name|b2
init|=
name|r
operator|.
name|top
argument_list|()
decl_stmt|;
if|if
condition|(
name|r
operator|.
name|height
argument_list|()
operator|<
literal|0
condition|)
name|t2
operator|+=
name|r
operator|.
name|height
argument_list|()
expr_stmt|;
else|else
name|b2
operator|+=
name|r
operator|.
name|height
argument_list|()
expr_stmt|;
return|return
operator|!
operator|(
name|t1
operator|>=
name|b2
operator|||
name|t2
operator|>=
name|b1
operator|)
return|;
block|}
end_function
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
comment|// QGRAPHICSBSPTREEINDEX_H
end_comment
end_unit
