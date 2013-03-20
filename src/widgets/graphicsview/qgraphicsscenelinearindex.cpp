begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QGraphicsSceneLinearIndex     \brief The QGraphicsSceneLinearIndex class provides an implementation of     a linear indexing algorithm for discovering items in QGraphicsScene.     \since 4.6     \ingroup graphicsview-api     \internal      QGraphicsSceneLinearIndex index is default linear implementation to discover items.     It basically store all items in a list and return them to the scene.      \sa QGraphicsScene, QGraphicsView, QGraphicsSceneIndex, QGraphicsSceneBspTreeIndex */
end_comment
begin_include
include|#
directive|include
file|<private/qgraphicsscenelinearindex_p.h>
end_include
begin_comment
comment|/*!     \fn QGraphicsSceneLinearIndex::QGraphicsSceneLinearIndex(QGraphicsScene *scene = 0):      Construct a linear index for the given \a scene. */
end_comment
begin_comment
comment|/*!     \fn QList<QGraphicsItem *> QGraphicsSceneLinearIndex::items(Qt::SortOrder order = Qt::DescendingOrder) const;      Return all items in the index and sort them using \a order. */
end_comment
begin_comment
comment|/*!     \fn virtual QList<QGraphicsItem *> QGraphicsSceneLinearIndex::estimateItems(const QRectF&rect, Qt::SortOrder order) const      Returns an estimation visible items that are either inside or     intersect with the specified \a rect and return a list sorted using \a order. */
end_comment
begin_comment
comment|/*!     \fn void QGraphicsSceneLinearIndex::clear()     \internal     Clear the all the BSP index. */
end_comment
begin_comment
comment|/*!     \fn virtual void QGraphicsSceneLinearIndex::addItem(QGraphicsItem *item)      Add the \a item into the index. */
end_comment
begin_comment
comment|/*!     \fn virtual void QGraphicsSceneLinearIndex::removeItem(QGraphicsItem *item)      Add the \a item from the index. */
end_comment
end_unit
