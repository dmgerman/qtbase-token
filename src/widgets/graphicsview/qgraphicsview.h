begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSVIEW_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSVIEW_H
define|#
directive|define
name|QGRAPHICSVIEW_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpainter.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qscrollarea.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicsscene.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GRAPHICSVIEW
argument_list|)
DECL|variable|QGraphicsItem
name|class
name|QGraphicsItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainterPath
name|class
name|QPainterPath
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPolygonF
name|class
name|QPolygonF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionGraphicsItem
name|class
name|QStyleOptionGraphicsItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsViewPrivate
name|class
name|QGraphicsViewPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsView
range|:
name|public
name|QAbstractScrollArea
block|{
name|Q_OBJECT
name|Q_FLAGS
argument_list|(
argument|QPainter::RenderHints CacheMode OptimizationFlags
argument_list|)
name|Q_ENUMS
argument_list|(
argument|ViewportAnchor DragMode ViewportUpdateMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QBrush backgroundBrush READ backgroundBrush WRITE setBackgroundBrush
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QBrush foregroundBrush READ foregroundBrush WRITE setForegroundBrush
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool interactive READ isInteractive WRITE setInteractive
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QRectF sceneRect READ sceneRect WRITE setSceneRect
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Alignment alignment READ alignment WRITE setAlignment
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QPainter::RenderHints renderHints READ renderHints WRITE setRenderHints
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|DragMode dragMode READ dragMode WRITE setDragMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|CacheMode cacheMode READ cacheMode WRITE setCacheMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|ViewportAnchor transformationAnchor READ transformationAnchor WRITE setTransformationAnchor
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|ViewportAnchor resizeAnchor READ resizeAnchor WRITE setResizeAnchor
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|ViewportUpdateMode viewportUpdateMode READ viewportUpdateMode WRITE setViewportUpdateMode
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_RUBBERBAND
name|Q_PROPERTY
argument_list|(
argument|Qt::ItemSelectionMode rubberBandSelectionMode READ rubberBandSelectionMode WRITE setRubberBandSelectionMode
argument_list|)
endif|#
directive|endif
name|Q_PROPERTY
argument_list|(
argument|OptimizationFlags optimizationFlags READ optimizationFlags WRITE setOptimizationFlags
argument_list|)
name|public
operator|:
expr|enum
name|ViewportAnchor
block|{
name|NoAnchor
block|,
name|AnchorViewCenter
block|,
name|AnchorUnderMouse
block|}
block|;      enum
name|CacheModeFlag
block|{
name|CacheNone
operator|=
literal|0x0
block|,
name|CacheBackground
operator|=
literal|0x1
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|CacheMode
argument_list|,
name|CacheModeFlag
argument_list|)
expr|enum
name|DragMode
block|{
name|NoDrag
block|,
name|ScrollHandDrag
block|,
name|RubberBandDrag
block|}
block|;      enum
name|ViewportUpdateMode
block|{
name|FullViewportUpdate
block|,
name|MinimalViewportUpdate
block|,
name|SmartViewportUpdate
block|,
name|NoViewportUpdate
block|,
name|BoundingRectViewportUpdate
block|}
block|;      enum
name|OptimizationFlag
block|{
name|DontClipPainter
operator|=
literal|0x1
block|,
comment|// obsolete
name|DontSavePainterState
operator|=
literal|0x2
block|,
name|DontAdjustForAntialiasing
operator|=
literal|0x4
block|,
name|IndirectPainting
operator|=
literal|0x8
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|OptimizationFlags
argument_list|,
argument|OptimizationFlag
argument_list|)
name|QGraphicsView
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QGraphicsView
argument_list|(
name|QGraphicsScene
operator|*
name|scene
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QGraphicsView
argument_list|()
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QPainter
operator|::
name|RenderHints
name|renderHints
argument_list|()
specifier|const
block|;
name|void
name|setRenderHint
argument_list|(
argument|QPainter::RenderHint hint
argument_list|,
argument|bool enabled = true
argument_list|)
block|;
name|void
name|setRenderHints
argument_list|(
argument|QPainter::RenderHints hints
argument_list|)
block|;
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|()
specifier|const
block|;
name|void
name|setAlignment
argument_list|(
argument|Qt::Alignment alignment
argument_list|)
block|;
name|ViewportAnchor
name|transformationAnchor
argument_list|()
specifier|const
block|;
name|void
name|setTransformationAnchor
argument_list|(
argument|ViewportAnchor anchor
argument_list|)
block|;
name|ViewportAnchor
name|resizeAnchor
argument_list|()
specifier|const
block|;
name|void
name|setResizeAnchor
argument_list|(
argument|ViewportAnchor anchor
argument_list|)
block|;
name|ViewportUpdateMode
name|viewportUpdateMode
argument_list|()
specifier|const
block|;
name|void
name|setViewportUpdateMode
argument_list|(
argument|ViewportUpdateMode mode
argument_list|)
block|;
name|OptimizationFlags
name|optimizationFlags
argument_list|()
specifier|const
block|;
name|void
name|setOptimizationFlag
argument_list|(
argument|OptimizationFlag flag
argument_list|,
argument|bool enabled = true
argument_list|)
block|;
name|void
name|setOptimizationFlags
argument_list|(
argument|OptimizationFlags flags
argument_list|)
block|;
name|DragMode
name|dragMode
argument_list|()
specifier|const
block|;
name|void
name|setDragMode
argument_list|(
argument|DragMode mode
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_RUBBERBAND
name|Qt
operator|::
name|ItemSelectionMode
name|rubberBandSelectionMode
argument_list|()
specifier|const
block|;
name|void
name|setRubberBandSelectionMode
argument_list|(
argument|Qt::ItemSelectionMode mode
argument_list|)
block|;
endif|#
directive|endif
name|CacheMode
name|cacheMode
argument_list|()
specifier|const
block|;
name|void
name|setCacheMode
argument_list|(
argument|CacheMode mode
argument_list|)
block|;
name|void
name|resetCachedContent
argument_list|()
block|;
name|bool
name|isInteractive
argument_list|()
specifier|const
block|;
name|void
name|setInteractive
argument_list|(
argument|bool allowed
argument_list|)
block|;
name|QGraphicsScene
operator|*
name|scene
argument_list|()
specifier|const
block|;
name|void
name|setScene
argument_list|(
name|QGraphicsScene
operator|*
name|scene
argument_list|)
block|;
name|QRectF
name|sceneRect
argument_list|()
specifier|const
block|;
name|void
name|setSceneRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
specifier|inline
name|void
name|setSceneRect
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|)
block|;
name|QMatrix
name|matrix
argument_list|()
specifier|const
block|;
name|void
name|setMatrix
argument_list|(
argument|const QMatrix&matrix
argument_list|,
argument|bool combine = false
argument_list|)
block|;
name|void
name|resetMatrix
argument_list|()
block|;
name|QTransform
name|transform
argument_list|()
specifier|const
block|;
name|QTransform
name|viewportTransform
argument_list|()
specifier|const
block|;
name|bool
name|isTransformed
argument_list|()
specifier|const
block|;
name|void
name|setTransform
argument_list|(
argument|const QTransform&matrix
argument_list|,
argument|bool combine = false
argument_list|)
block|;
name|void
name|resetTransform
argument_list|()
block|;
name|void
name|rotate
argument_list|(
argument|qreal angle
argument_list|)
block|;
name|void
name|scale
argument_list|(
argument|qreal sx
argument_list|,
argument|qreal sy
argument_list|)
block|;
name|void
name|shear
argument_list|(
argument|qreal sh
argument_list|,
argument|qreal sv
argument_list|)
block|;
name|void
name|translate
argument_list|(
argument|qreal dx
argument_list|,
argument|qreal dy
argument_list|)
block|;
name|void
name|centerOn
argument_list|(
specifier|const
name|QPointF
operator|&
name|pos
argument_list|)
block|;
specifier|inline
name|void
name|centerOn
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|)
block|;
name|void
name|centerOn
argument_list|(
specifier|const
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|void
name|ensureVisible
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|int xmargin =
literal|50
argument_list|,
argument|int ymargin =
literal|50
argument_list|)
block|;
specifier|inline
name|void
name|ensureVisible
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|int xmargin =
literal|50
argument_list|,
argument|int ymargin =
literal|50
argument_list|)
block|;
name|void
name|ensureVisible
argument_list|(
argument|const QGraphicsItem *item
argument_list|,
argument|int xmargin =
literal|50
argument_list|,
argument|int ymargin =
literal|50
argument_list|)
block|;
name|void
name|fitInView
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|Qt::AspectRatioMode aspectRadioMode = Qt::IgnoreAspectRatio
argument_list|)
block|;
specifier|inline
name|void
name|fitInView
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|Qt::AspectRatioMode aspectRadioMode = Qt::IgnoreAspectRatio
argument_list|)
block|;
name|void
name|fitInView
argument_list|(
argument|const QGraphicsItem *item
argument_list|,
argument|Qt::AspectRatioMode aspectRadioMode = Qt::IgnoreAspectRatio
argument_list|)
block|;
name|void
name|render
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QRectF&target = QRectF()
argument_list|,
argument|const QRect&source = QRect()
argument_list|,
argument|Qt::AspectRatioMode aspectRatioMode = Qt::KeepAspectRatio
argument_list|)
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
specifier|inline
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|(
argument|int x
argument_list|,
argument|int y
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
argument|const QRect&rect
argument_list|,
argument|Qt::ItemSelectionMode mode = Qt::IntersectsItemShape
argument_list|)
specifier|const
block|;
specifier|inline
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|Qt::ItemSelectionMode mode = Qt::IntersectsItemShape
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
argument|const QPolygon&polygon
argument_list|,
argument|Qt::ItemSelectionMode mode = Qt::IntersectsItemShape
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
argument|const QPainterPath&path
argument_list|,
argument|Qt::ItemSelectionMode mode = Qt::IntersectsItemShape
argument_list|)
specifier|const
block|;
name|QGraphicsItem
operator|*
name|itemAt
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
specifier|inline
name|QGraphicsItem
operator|*
name|itemAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|QPointF
name|mapToScene
argument_list|(
argument|const QPoint&point
argument_list|)
specifier|const
block|;
name|QPolygonF
name|mapToScene
argument_list|(
argument|const QRect&rect
argument_list|)
specifier|const
block|;
name|QPolygonF
name|mapToScene
argument_list|(
argument|const QPolygon&polygon
argument_list|)
specifier|const
block|;
name|QPainterPath
name|mapToScene
argument_list|(
argument|const QPainterPath&path
argument_list|)
specifier|const
block|;
name|QPoint
name|mapFromScene
argument_list|(
argument|const QPointF&point
argument_list|)
specifier|const
block|;
name|QPolygon
name|mapFromScene
argument_list|(
argument|const QRectF&rect
argument_list|)
specifier|const
block|;
name|QPolygon
name|mapFromScene
argument_list|(
argument|const QPolygonF&polygon
argument_list|)
specifier|const
block|;
name|QPainterPath
name|mapFromScene
argument_list|(
argument|const QPainterPath&path
argument_list|)
specifier|const
block|;
specifier|inline
name|QPointF
name|mapToScene
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
specifier|inline
name|QPolygonF
name|mapToScene
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
specifier|const
block|;
specifier|inline
name|QPoint
name|mapFromScene
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|)
specifier|const
block|;
specifier|inline
name|QPolygon
name|mapFromScene
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|)
specifier|const
block|;
name|QVariant
name|inputMethodQuery
argument_list|(
argument|Qt::InputMethodQuery query
argument_list|)
specifier|const
block|;
name|QBrush
name|backgroundBrush
argument_list|()
specifier|const
block|;
name|void
name|setBackgroundBrush
argument_list|(
specifier|const
name|QBrush
operator|&
name|brush
argument_list|)
block|;
name|QBrush
name|foregroundBrush
argument_list|()
specifier|const
block|;
name|void
name|setForegroundBrush
argument_list|(
specifier|const
name|QBrush
operator|&
name|brush
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|updateScene
argument_list|(
specifier|const
name|QList
operator|<
name|QRectF
operator|>
operator|&
name|rects
argument_list|)
block|;
name|void
name|invalidateScene
argument_list|(
argument|const QRectF&rect = QRectF()
argument_list|,
argument|QGraphicsScene::SceneLayers layers = QGraphicsScene::AllLayers
argument_list|)
block|;
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
name|Q_SLOTS
operator|:
name|void
name|setupViewport
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|protected
operator|:
name|QGraphicsView
argument_list|(
name|QGraphicsViewPrivate
operator|&
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|viewportEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|void
name|contextMenuEvent
argument_list|(
name|QContextMenuEvent
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
name|void
name|dragEnterEvent
argument_list|(
name|QDragEnterEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|dragLeaveEvent
argument_list|(
name|QDragLeaveEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|dragMoveEvent
argument_list|(
name|QDragMoveEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|dropEvent
argument_list|(
name|QDropEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|focusInEvent
argument_list|(
name|QFocusEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
block|;
name|void
name|focusOutEvent
argument_list|(
name|QFocusEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|keyReleaseEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseDoubleClickEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
name|QWheelEvent
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|scrollContentsBy
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|void
name|showEvent
argument_list|(
name|QShowEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|inputMethodEvent
argument_list|(
name|QInputMethodEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|drawBackground
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|virtual
name|void
name|drawForeground
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|virtual
name|void
name|drawItems
argument_list|(
argument|QPainter *painter
argument_list|,
argument|int numItems
argument_list|,
argument|QGraphicsItem *items[]
argument_list|,
argument|const QStyleOptionGraphicsItem options[]
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsView
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsView
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_setViewportCursor(const QCursor&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_unsetViewportCursor()
argument_list|)
endif|#
directive|endif
name|friend
name|class
name|QGraphicsSceneWidget
block|;
name|friend
name|class
name|QGraphicsScene
block|;
name|friend
name|class
name|QGraphicsScenePrivate
block|;
name|friend
name|class
name|QGraphicsItemPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QGraphicsView::CacheMode
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QGraphicsView::OptimizationFlags
argument_list|)
end_macro
begin_expr_stmt
DECL|function|setSceneRect
specifier|inline
name|void
name|QGraphicsView
operator|::
name|setSceneRect
argument_list|(
argument|qreal ax
argument_list|,
argument|qreal ay
argument_list|,
argument|qreal aw
argument_list|,
argument|qreal ah
argument_list|)
block|{
name|setSceneRect
argument_list|(
name|QRectF
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|aw
argument_list|,
name|ah
argument_list|)
argument_list|)
block|; }
DECL|function|centerOn
specifier|inline
name|void
name|QGraphicsView
operator|::
name|centerOn
argument_list|(
argument|qreal ax
argument_list|,
argument|qreal ay
argument_list|)
block|{
name|centerOn
argument_list|(
name|QPointF
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|)
argument_list|)
block|; }
DECL|function|ensureVisible
specifier|inline
name|void
name|QGraphicsView
operator|::
name|ensureVisible
argument_list|(
argument|qreal ax
argument_list|,
argument|qreal ay
argument_list|,
argument|qreal aw
argument_list|,
argument|qreal ah
argument_list|,
argument|int xmargin
argument_list|,
argument|int ymargin
argument_list|)
block|{
name|ensureVisible
argument_list|(
name|QRectF
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|aw
argument_list|,
name|ah
argument_list|)
argument_list|,
name|xmargin
argument_list|,
name|ymargin
argument_list|)
block|; }
DECL|function|fitInView
specifier|inline
name|void
name|QGraphicsView
operator|::
name|fitInView
argument_list|(
argument|qreal ax
argument_list|,
argument|qreal ay
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|Qt::AspectRatioMode mode
argument_list|)
block|{
name|fitInView
argument_list|(
name|QRectF
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|mode
argument_list|)
block|; }
DECL|function|items
specifier|inline
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|QGraphicsView
operator|::
name|items
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|)
specifier|const
block|{
return|return
name|items
argument_list|(
name|QPoint
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|items
specifier|inline
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|QGraphicsView
operator|::
name|items
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|Qt::ItemSelectionMode mode
argument_list|)
specifier|const
block|{
return|return
name|items
argument_list|(
name|QRect
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|itemAt
specifier|inline
name|QGraphicsItem
operator|*
name|QGraphicsView
operator|::
name|itemAt
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|)
specifier|const
block|{
return|return
name|itemAt
argument_list|(
name|QPoint
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|mapToScene
specifier|inline
name|QPointF
name|QGraphicsView
operator|::
name|mapToScene
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|)
specifier|const
block|{
return|return
name|mapToScene
argument_list|(
name|QPoint
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|mapToScene
specifier|inline
name|QPolygonF
name|QGraphicsView
operator|::
name|mapToScene
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
specifier|const
block|{
return|return
name|mapToScene
argument_list|(
name|QRect
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|mapFromScene
specifier|inline
name|QPoint
name|QGraphicsView
operator|::
name|mapFromScene
argument_list|(
argument|qreal ax
argument_list|,
argument|qreal ay
argument_list|)
specifier|const
block|{
return|return
name|mapFromScene
argument_list|(
name|QPointF
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|mapFromScene
specifier|inline
name|QPolygon
name|QGraphicsView
operator|::
name|mapFromScene
argument_list|(
argument|qreal ax
argument_list|,
argument|qreal ay
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|)
specifier|const
block|{
return|return
name|mapFromScene
argument_list|(
name|QRectF
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GRAPHICSVIEW
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGRAPHICSVIEW_H
end_comment
end_unit
