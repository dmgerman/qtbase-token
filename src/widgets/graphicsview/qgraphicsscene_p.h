begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSSCENE_P_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSSCENE_P_H
define|#
directive|define
name|QGRAPHICSSCENE_P_H
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
file|"qgraphicsscene.h"
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
file|"qgraphicssceneevent.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicsview.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicsview_p.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicsitem_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbitarray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qfont.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpalette.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qstyle.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qstyleoption.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGraphicsSceneIndex
name|class
name|QGraphicsSceneIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsView
name|class
name|QGraphicsView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsWidget
name|class
name|QGraphicsWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QGraphicsScenePrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsScene
argument_list|)
name|public
operator|:
name|QGraphicsScenePrivate
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
specifier|static
name|QGraphicsScenePrivate
operator|*
name|get
argument_list|(
name|QGraphicsScene
operator|*
name|q
argument_list|)
block|;
name|int
name|changedSignalIndex
block|;
name|int
name|processDirtyItemsIndex
block|;
name|int
name|polishItemsIndex
block|;
name|QGraphicsScene
operator|::
name|ItemIndexMethod
name|indexMethod
block|;
name|QGraphicsSceneIndex
operator|*
name|index
block|;
name|int
name|lastItemCount
block|;
name|QRectF
name|sceneRect
block|;
name|quint32
name|hasSceneRect
operator|:
literal|1
block|;
name|quint32
name|dirtyGrowingItemsBoundingRect
operator|:
literal|1
block|;
name|quint32
name|updateAll
operator|:
literal|1
block|;
name|quint32
name|calledEmitUpdated
operator|:
literal|1
block|;
name|quint32
name|processDirtyItemsEmitted
operator|:
literal|1
block|;
name|quint32
name|needSortTopLevelItems
operator|:
literal|1
block|;
name|quint32
name|holesInTopLevelSiblingIndex
operator|:
literal|1
block|;
name|quint32
name|topLevelSequentialOrdering
operator|:
literal|1
block|;
name|quint32
name|scenePosDescendantsUpdatePending
operator|:
literal|1
block|;
name|quint32
name|stickyFocus
operator|:
literal|1
block|;
name|quint32
name|hasFocus
operator|:
literal|1
block|;
name|quint32
name|lastMouseGrabberItemHasImplicitMouseGrab
operator|:
literal|1
block|;
name|quint32
name|allItemsIgnoreHoverEvents
operator|:
literal|1
block|;
name|quint32
name|allItemsUseDefaultCursor
operator|:
literal|1
block|;
name|quint32
name|painterStateProtection
operator|:
literal|1
block|;
name|quint32
name|sortCacheEnabled
operator|:
literal|1
block|;
comment|// for compatibility
name|quint32
name|allItemsIgnoreTouchEvents
operator|:
literal|1
block|;
name|quint32
name|padding
operator|:
literal|15
block|;
name|qreal
name|minimumRenderSize
block|;
name|QRectF
name|growingItemsBoundingRect
block|;
name|void
name|_q_emitUpdated
argument_list|()
block|;
name|QList
operator|<
name|QRectF
operator|>
name|updatedRects
block|;
name|QPainterPath
name|selectionArea
block|;
name|int
name|selectionChanging
block|;
name|QSet
operator|<
name|QGraphicsItem
operator|*
operator|>
name|selectedItems
block|;
name|QVector
operator|<
name|QGraphicsItem
operator|*
operator|>
name|unpolishedItems
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|topLevelItems
block|;
name|QHash
operator|<
name|QGraphicsItem
operator|*
block|,
name|QPointF
operator|>
name|movingItemsInitialPositions
block|;
name|void
name|registerTopLevelItem
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|void
name|unregisterTopLevelItem
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|void
name|_q_updateLater
argument_list|()
block|;
name|void
name|_q_polishItems
argument_list|()
block|;
name|void
name|_q_processDirtyItems
argument_list|()
block|;
name|QSet
operator|<
name|QGraphicsItem
operator|*
operator|>
name|scenePosItems
block|;
name|void
name|setScenePosItemEnabled
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|bool enabled
argument_list|)
block|;
name|void
name|registerScenePosItem
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|void
name|unregisterScenePosItem
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|void
name|_q_updateScenePosDescendants
argument_list|()
block|;
name|void
name|removeItemHelper
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|QBrush
name|backgroundBrush
block|;
name|QBrush
name|foregroundBrush
block|;
name|quint32
name|rectAdjust
block|;
name|QGraphicsItem
operator|*
name|focusItem
block|;
name|QGraphicsItem
operator|*
name|lastFocusItem
block|;
name|QGraphicsItem
operator|*
name|passiveFocusItem
block|;
name|QGraphicsWidget
operator|*
name|tabFocusFirst
block|;
name|QGraphicsItem
operator|*
name|activePanel
block|;
name|QGraphicsItem
operator|*
name|lastActivePanel
block|;
name|int
name|activationRefCount
block|;
name|int
name|childExplicitActivation
block|;
name|void
name|setActivePanelHelper
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|bool duringActivationEvent
argument_list|)
block|;
name|void
name|setFocusItemHelper
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|Qt::FocusReason focusReason
argument_list|,
argument|bool emitFocusChanged = true
argument_list|)
block|;
name|QList
operator|<
name|QGraphicsWidget
operator|*
operator|>
name|popupWidgets
block|;
name|void
name|addPopup
argument_list|(
name|QGraphicsWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|removePopup
argument_list|(
argument|QGraphicsWidget *widget
argument_list|,
argument|bool itemIsDying = false
argument_list|)
block|;
name|QGraphicsItem
operator|*
name|lastMouseGrabberItem
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|mouseGrabberItems
block|;
name|void
name|grabMouse
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|bool implicit = false
argument_list|)
block|;
name|void
name|ungrabMouse
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|bool itemIsDying = false
argument_list|)
block|;
name|void
name|clearMouseGrabber
argument_list|()
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|keyboardGrabberItems
block|;
name|void
name|grabKeyboard
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|void
name|ungrabKeyboard
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|bool itemIsDying = false
argument_list|)
block|;
name|void
name|clearKeyboardGrabber
argument_list|()
block|;
name|QGraphicsItem
operator|*
name|dragDropItem
block|;
name|QGraphicsWidget
operator|*
name|enterWidget
block|;
name|Qt
operator|::
name|DropAction
name|lastDropAction
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|cachedItemsUnderMouse
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|hoverItems
block|;
name|QPointF
name|lastSceneMousePos
block|;
name|void
name|enableMouseTrackingOnViews
argument_list|()
block|;
name|QMap
operator|<
name|Qt
operator|::
name|MouseButton
block|,
name|QPointF
operator|>
name|mouseGrabberButtonDownPos
block|;
name|QMap
operator|<
name|Qt
operator|::
name|MouseButton
block|,
name|QPointF
operator|>
name|mouseGrabberButtonDownScenePos
block|;
name|QMap
operator|<
name|Qt
operator|::
name|MouseButton
block|,
name|QPoint
operator|>
name|mouseGrabberButtonDownScreenPos
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|itemsAtPosition
argument_list|(
argument|const QPoint&screenPos
argument_list|,
argument|const QPointF&scenePos
argument_list|,
argument|QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|storeMouseButtonsForMouseGrabber
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|QList
operator|<
name|QGraphicsView
operator|*
operator|>
name|views
block|;
name|void
name|addView
argument_list|(
name|QGraphicsView
operator|*
name|view
argument_list|)
block|;
name|void
name|removeView
argument_list|(
name|QGraphicsView
operator|*
name|view
argument_list|)
block|;
name|QMultiMap
operator|<
name|QGraphicsItem
operator|*
block|,
name|QGraphicsItem
operator|*
operator|>
name|sceneEventFilters
block|;
name|void
name|installSceneEventFilter
argument_list|(
name|QGraphicsItem
operator|*
name|watched
argument_list|,
name|QGraphicsItem
operator|*
name|filter
argument_list|)
block|;
name|void
name|removeSceneEventFilter
argument_list|(
name|QGraphicsItem
operator|*
name|watched
argument_list|,
name|QGraphicsItem
operator|*
name|filter
argument_list|)
block|;
name|bool
name|filterDescendantEvent
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|filterEvent
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|sendEvent
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|dispatchHoverEvent
argument_list|(
name|QGraphicsSceneHoverEvent
operator|*
name|hoverEvent
argument_list|)
block|;
name|bool
name|itemAcceptsHoverEvents_helper
argument_list|(
argument|const QGraphicsItem *item
argument_list|)
specifier|const
block|;
name|void
name|leaveScene
argument_list|(
name|QWidget
operator|*
name|viewport
argument_list|)
block|;
name|void
name|cloneDragDropEvent
argument_list|(
name|QGraphicsSceneDragDropEvent
operator|*
name|dest
argument_list|,
name|QGraphicsSceneDragDropEvent
operator|*
name|source
argument_list|)
block|;
name|void
name|sendDragDropEvent
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|,
name|QGraphicsSceneDragDropEvent
operator|*
name|dragDropEvent
argument_list|)
block|;
name|void
name|sendHoverEvent
argument_list|(
argument|QEvent::Type type
argument_list|,
argument|QGraphicsItem *item
argument_list|,
argument|QGraphicsSceneHoverEvent *hoverEvent
argument_list|)
block|;
name|void
name|sendMouseEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|mouseEvent
argument_list|)
block|;
name|void
name|mousePressEventHandler
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|mouseEvent
argument_list|)
block|;
name|QGraphicsWidget
operator|*
name|windowForItem
argument_list|(
argument|const QGraphicsItem *item
argument_list|)
specifier|const
block|;
name|void
name|drawItemHelper
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionGraphicsItem *option
argument_list|,
argument|QWidget *widget
argument_list|,
argument|bool painterStateProtection
argument_list|)
block|;
name|void
name|drawItems
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QTransform
operator|*
specifier|const
name|viewTransform
argument_list|,
name|QRegion
operator|*
name|exposedRegion
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|drawSubtreeRecursive
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QTransform *const
argument_list|,
argument|QRegion *exposedRegion
argument_list|,
argument|QWidget *widget
argument_list|,
argument|qreal parentOpacity = qreal(
literal|1.0
argument|)
argument_list|,
argument|const QTransform *const effectTransform =
literal|0
argument_list|)
block|;
name|void
name|draw
argument_list|(
name|QGraphicsItem
operator|*
argument_list|,
name|QPainter
operator|*
argument_list|,
specifier|const
name|QTransform
operator|*
specifier|const
argument_list|,
specifier|const
name|QTransform
operator|*
specifier|const
argument_list|,
name|QRegion
operator|*
argument_list|,
name|QWidget
operator|*
argument_list|,
name|qreal
argument_list|,
specifier|const
name|QTransform
operator|*
specifier|const
argument_list|,
name|bool
argument_list|,
name|bool
argument_list|)
block|;
name|void
name|markDirty
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|const QRectF&rect = QRectF()
argument_list|,
argument|bool invalidateChildren = false
argument_list|,
argument|bool force = false
argument_list|,
argument|bool ignoreOpacity = false
argument_list|,
argument|bool removingItemFromScene = false
argument_list|,
argument|bool updateBoundingRect = false
argument_list|)
block|;
name|void
name|processDirtyItemsRecursive
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|bool dirtyAncestorContainsChildren = false
argument_list|,
argument|qreal parentOpacity = qreal(
literal|1.0
argument|)
argument_list|)
block|;
specifier|inline
name|void
name|resetDirtyItem
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|bool recursive = false
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|item
argument_list|)
block|;
name|item
operator|->
name|d_ptr
operator|->
name|dirty
operator|=
literal|0
block|;
name|item
operator|->
name|d_ptr
operator|->
name|paintedViewBoundingRectsNeedRepaint
operator|=
literal|0
block|;
name|item
operator|->
name|d_ptr
operator|->
name|geometryChanged
operator|=
literal|0
block|;
if|if
condition|(
operator|!
name|item
operator|->
name|d_ptr
operator|->
name|dirtyChildren
condition|)
name|recursive
operator|=
name|false
expr_stmt|;
name|item
operator|->
name|d_ptr
operator|->
name|dirtyChildren
operator|=
literal|0
block|;
name|item
operator|->
name|d_ptr
operator|->
name|needsRepaint
operator|=
name|QRectF
argument_list|()
block|;
name|item
operator|->
name|d_ptr
operator|->
name|allChildrenDirty
operator|=
literal|0
block|;
name|item
operator|->
name|d_ptr
operator|->
name|fullUpdatePending
operator|=
literal|0
block|;
name|item
operator|->
name|d_ptr
operator|->
name|ignoreVisible
operator|=
literal|0
block|;
name|item
operator|->
name|d_ptr
operator|->
name|ignoreOpacity
operator|=
literal|0
block|;
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSEFFECT
name|QGraphicsEffect
operator|::
name|ChangeFlags
name|flags
block|;
if|if
condition|(
name|item
operator|->
name|d_ptr
operator|->
name|notifyBoundingRectChanged
condition|)
block|{
name|flags
operator||=
name|QGraphicsEffect
operator|::
name|SourceBoundingRectChanged
expr_stmt|;
name|item
operator|->
name|d_ptr
operator|->
name|notifyBoundingRectChanged
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|item
operator|->
name|d_ptr
operator|->
name|notifyInvalidated
condition|)
block|{
name|flags
operator||=
name|QGraphicsEffect
operator|::
name|SourceInvalidated
expr_stmt|;
name|item
operator|->
name|d_ptr
operator|->
name|notifyInvalidated
operator|=
literal|0
expr_stmt|;
block|}
endif|#
directive|endif
comment|//QT_NO_GRAPHICSEFFECT
if|if
condition|(
name|recursive
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|item
operator|->
name|d_ptr
operator|->
name|children
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|resetDirtyItem
argument_list|(
name|item
operator|->
name|d_ptr
operator|->
name|children
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|recursive
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSEFFECT
if|if
condition|(
name|flags
operator|&&
name|item
operator|->
name|d_ptr
operator|->
name|graphicsEffect
condition|)
name|item
operator|->
name|d_ptr
operator|->
name|graphicsEffect
operator|->
name|sourceChanged
argument_list|(
name|flags
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|//QT_NO_GRAPHICSEFFECT
block|}
end_decl_stmt
begin_function
specifier|inline
name|void
name|ensureSortedTopLevelItems
parameter_list|()
block|{
if|if
condition|(
name|needSortTopLevelItems
condition|)
block|{
name|std
operator|::
name|sort
argument_list|(
name|topLevelItems
operator|.
name|begin
argument_list|()
argument_list|,
name|topLevelItems
operator|.
name|end
argument_list|()
argument_list|,
name|qt_notclosestLeaf
argument_list|)
expr_stmt|;
name|topLevelSequentialOrdering
operator|=
name|false
expr_stmt|;
name|needSortTopLevelItems
operator|=
name|false
expr_stmt|;
block|}
block|}
end_function
begin_function_decl
name|void
name|ensureSequentialTopLevelSiblingIndexes
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|QStyle
modifier|*
name|style
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QFont
name|font
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setFont_helper
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|resolveFont
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|updateFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QPalette
name|palette
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setPalette_helper
parameter_list|(
specifier|const
name|QPalette
modifier|&
name|palette
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|resolvePalette
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|updatePalette
parameter_list|(
specifier|const
name|QPalette
modifier|&
name|palette
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QStyleOptionGraphicsItem
name|styleOptionTmp
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QMap
operator|<
name|int
operator|,
name|QTouchEvent
operator|::
name|TouchPoint
operator|>
name|sceneCurrentTouchPoints
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMap
operator|<
name|int
operator|,
name|QGraphicsItem
operator|*
operator|>
name|itemForTouchPointId
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|void
name|updateTouchPointsForItem
parameter_list|(
name|QGraphicsItem
modifier|*
name|item
parameter_list|,
name|QTouchEvent
modifier|*
name|touchEvent
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|int
name|findClosestTouchPointId
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|scenePos
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|touchEventHandler
parameter_list|(
name|QTouchEvent
modifier|*
name|touchEvent
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|sendTouchBeginEvent
parameter_list|(
name|QGraphicsItem
modifier|*
name|item
parameter_list|,
name|QTouchEvent
modifier|*
name|touchEvent
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|enableTouchEventsOnViews
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|QList
operator|<
name|QGraphicsObject
operator|*
operator|>
name|cachedTargetItems
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_expr_stmt
name|QHash
operator|<
name|QGraphicsObject
operator|*
operator|,
name|QSet
operator|<
name|QGesture
operator|*
operator|>
expr|>
name|cachedItemGestures
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
name|QGraphicsObject
operator|*
operator|,
name|QSet
operator|<
name|QGesture
operator|*
operator|>
expr|>
name|cachedAlreadyDeliveredGestures
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
name|QGesture
operator|*
operator|,
name|QGraphicsObject
operator|*
operator|>
name|gestureTargets
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
name|Qt
operator|::
name|GestureType
operator|,
name|int
operator|>
name|grabbedGestures
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|gestureEventHandler
parameter_list|(
name|QGestureEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|gestureTargetsAtHotSpots
argument_list|(
specifier|const
name|QSet
operator|<
name|QGesture
operator|*
operator|>
operator|&
name|gestures
argument_list|,
name|Qt
operator|::
name|GestureFlag
name|flag
argument_list|,
name|QHash
operator|<
name|QGraphicsObject
operator|*
argument_list|,
name|QSet
operator|<
name|QGesture
operator|*
operator|>
expr|>
operator|*
name|targets
argument_list|,
name|QSet
operator|<
name|QGraphicsObject
operator|*
operator|>
operator|*
name|itemsSet
operator|=
literal|0
argument_list|,
name|QSet
operator|<
name|QGesture
operator|*
operator|>
operator|*
name|normal
operator|=
literal|0
argument_list|,
name|QSet
operator|<
name|QGesture
operator|*
operator|>
operator|*
name|conflicts
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|cancelGesturesForChildren
parameter_list|(
name|QGesture
modifier|*
name|original
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|grabGesture
argument_list|(
name|QGraphicsItem
operator|*
argument_list|,
name|Qt
operator|::
name|GestureType
name|gesture
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|ungrabGesture
argument_list|(
name|QGraphicsItem
operator|*
argument_list|,
name|Qt
operator|::
name|GestureType
name|gesture
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GESTURES
end_comment
begin_function_decl
name|void
name|updateInputMethodSensitivityInViews
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|modalPanels
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|void
name|enterModal
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|,
name|QGraphicsItem
operator|::
name|PanelModality
name|panelModality
operator|=
name|QGraphicsItem
operator|::
name|NonModal
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|leaveModal
parameter_list|(
name|QGraphicsItem
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl
begin_comment
unit|};
comment|// QRectF::intersects() returns false always if either the source or target
end_comment
begin_comment
comment|// rectangle's width or height are 0. This works around that problem.
end_comment
begin_function
DECL|function|_q_adjustRect
specifier|static
specifier|inline
name|void
name|_q_adjustRect
parameter_list|(
name|QRectF
modifier|*
name|rect
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|rect
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|rect
operator|->
name|width
argument_list|()
condition|)
name|rect
operator|->
name|adjust
argument_list|(
name|qreal
argument_list|(
operator|-
literal|0.00001
argument_list|)
argument_list|,
literal|0
argument_list|,
name|qreal
argument_list|(
literal|0.00001
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|rect
operator|->
name|height
argument_list|()
condition|)
name|rect
operator|->
name|adjust
argument_list|(
literal|0
argument_list|,
name|qreal
argument_list|(
operator|-
literal|0.00001
argument_list|)
argument_list|,
literal|0
argument_list|,
name|qreal
argument_list|(
literal|0.00001
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|adjustedItemBoundingRect
specifier|static
specifier|inline
name|QRectF
name|adjustedItemBoundingRect
parameter_list|(
specifier|const
name|QGraphicsItem
modifier|*
name|item
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|QRectF
name|boundingRect
argument_list|(
name|item
operator|->
name|boundingRect
argument_list|()
argument_list|)
decl_stmt|;
name|_q_adjustRect
argument_list|(
operator|&
name|boundingRect
argument_list|)
expr_stmt|;
return|return
name|boundingRect
return|;
block|}
end_function
begin_function
DECL|function|adjustedItemEffectiveBoundingRect
specifier|static
specifier|inline
name|QRectF
name|adjustedItemEffectiveBoundingRect
parameter_list|(
specifier|const
name|QGraphicsItem
modifier|*
name|item
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|QRectF
name|boundingRect
argument_list|(
name|QGraphicsItemPrivate
operator|::
name|get
argument_list|(
name|item
argument_list|)
operator|->
name|effectiveBoundingRect
argument_list|()
argument_list|)
decl_stmt|;
name|_q_adjustRect
argument_list|(
operator|&
name|boundingRect
argument_list|)
expr_stmt|;
return|return
name|boundingRect
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
end_unit
