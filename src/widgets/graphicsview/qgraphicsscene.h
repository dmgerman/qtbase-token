begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSSCENE_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSSCENE_H
define|#
directive|define
name|QGRAPHICSSCENE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qbrush.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qfont.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtransform.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qmatrix.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpen.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GRAPHICSVIEW
argument_list|)
DECL|variable|QList
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QFocusEvent
name|class
name|QFocusEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFont
name|class
name|QFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFontMetrics
name|class
name|QFontMetrics
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsEllipseItem
name|class
name|QGraphicsEllipseItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsItem
name|class
name|QGraphicsItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsItemGroup
name|class
name|QGraphicsItemGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsLineItem
name|class
name|QGraphicsLineItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsPathItem
name|class
name|QGraphicsPathItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsPixmapItem
name|class
name|QGraphicsPixmapItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsPolygonItem
name|class
name|QGraphicsPolygonItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsProxyWidget
name|class
name|QGraphicsProxyWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsRectItem
name|class
name|QGraphicsRectItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneContextMenuEvent
name|class
name|QGraphicsSceneContextMenuEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneDragDropEvent
name|class
name|QGraphicsSceneDragDropEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneEvent
name|class
name|QGraphicsSceneEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneHelpEvent
name|class
name|QGraphicsSceneHelpEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneHoverEvent
name|class
name|QGraphicsSceneHoverEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneMouseEvent
name|class
name|QGraphicsSceneMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneWheelEvent
name|class
name|QGraphicsSceneWheelEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSimpleTextItem
name|class
name|QGraphicsSimpleTextItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsTextItem
name|class
name|QGraphicsTextItem
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
DECL|variable|QGraphicsSceneIndex
name|class
name|QGraphicsSceneIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHelpEvent
name|class
name|QHelpEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QInputMethodEvent
name|class
name|QInputMethodEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QKeyEvent
name|class
name|QKeyEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineF
name|class
name|QLineF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainterPath
name|class
name|QPainterPath
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPointF
name|class
name|QPointF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPolygonF
name|class
name|QPolygonF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRectF
name|class
name|QRectF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSizeF
name|class
name|QSizeF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyle
name|class
name|QStyle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionGraphicsItem
name|class
name|QStyleOptionGraphicsItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsScenePrivate
name|class
name|QGraphicsScenePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsScene
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
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
argument|ItemIndexMethod itemIndexMethod READ itemIndexMethod WRITE setItemIndexMethod
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QRectF sceneRect READ sceneRect WRITE setSceneRect
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int bspTreeDepth READ bspTreeDepth WRITE setBspTreeDepth
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QPalette palette READ palette WRITE setPalette
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QFont font READ font WRITE setFont
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool sortCacheEnabled READ isSortCacheEnabled WRITE setSortCacheEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool stickyFocus READ stickyFocus WRITE setStickyFocus
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal minimumRenderSize READ minimumRenderSize WRITE setMinimumRenderSize
argument_list|)
name|public
operator|:
expr|enum
name|ItemIndexMethod
block|{
name|BspTreeIndex
block|,
name|NoIndex
operator|=
operator|-
literal|1
block|}
block|;      enum
name|SceneLayer
block|{
name|ItemLayer
operator|=
literal|0x1
block|,
name|BackgroundLayer
operator|=
literal|0x2
block|,
name|ForegroundLayer
operator|=
literal|0x4
block|,
name|AllLayers
operator|=
literal|0xffff
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|SceneLayers
argument_list|,
argument|SceneLayer
argument_list|)
name|QGraphicsScene
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QGraphicsScene
argument_list|(
specifier|const
name|QRectF
operator|&
name|sceneRect
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QGraphicsScene
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal width
argument_list|,
argument|qreal height
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QGraphicsScene
argument_list|()
block|;
name|QRectF
name|sceneRect
argument_list|()
specifier|const
block|;
specifier|inline
name|qreal
name|width
argument_list|()
specifier|const
block|{
return|return
name|sceneRect
argument_list|()
operator|.
name|width
argument_list|()
return|;
block|}
specifier|inline
name|qreal
name|height
argument_list|()
specifier|const
block|{
return|return
name|sceneRect
argument_list|()
operator|.
name|height
argument_list|()
return|;
block|}
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
block|{
name|setSceneRect
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
block|; }
name|void
name|render
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QRectF&target = QRectF()
argument_list|,
argument|const QRectF&source = QRectF()
argument_list|,
argument|Qt::AspectRatioMode aspectRatioMode = Qt::KeepAspectRatio
argument_list|)
block|;
name|ItemIndexMethod
name|itemIndexMethod
argument_list|()
specifier|const
block|;
name|void
name|setItemIndexMethod
argument_list|(
argument|ItemIndexMethod method
argument_list|)
block|;
name|bool
name|isSortCacheEnabled
argument_list|()
specifier|const
block|;
name|void
name|setSortCacheEnabled
argument_list|(
argument|bool enabled
argument_list|)
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
name|QRectF
name|itemsBoundingRect
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
argument|Qt::SortOrder order = Qt::DescendingOrder
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
argument|const QPointF&pos
argument_list|,
argument|Qt::ItemSelectionMode mode = Qt::IntersectsItemShape
argument_list|,
argument|Qt::SortOrder order = Qt::DescendingOrder
argument_list|,
argument|const QTransform&deviceTransform = QTransform()
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
argument|const QRectF&rect
argument_list|,
argument|Qt::ItemSelectionMode mode = Qt::IntersectsItemShape
argument_list|,
argument|Qt::SortOrder order = Qt::DescendingOrder
argument_list|,
argument|const QTransform&deviceTransform = QTransform()
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
argument|const QPolygonF&polygon
argument_list|,
argument|Qt::ItemSelectionMode mode = Qt::IntersectsItemShape
argument_list|,
argument|Qt::SortOrder order = Qt::DescendingOrder
argument_list|,
argument|const QTransform&deviceTransform = QTransform()
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
argument_list|,
argument|Qt::SortOrder order = Qt::DescendingOrder
argument_list|,
argument|const QTransform&deviceTransform = QTransform()
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|collidingItems
argument_list|(
argument|const QGraphicsItem *item
argument_list|,
argument|Qt::ItemSelectionMode mode = Qt::IntersectsItemShape
argument_list|)
specifier|const
block|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|QGraphicsItem
operator|*
name|itemAt
argument_list|(
argument|const QPointF&position
argument_list|)
specifier|const
block|{
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|itemsAtPoint
operator|=
name|items
argument_list|(
name|position
argument_list|)
block|;
return|return
name|itemsAtPoint
operator|.
name|isEmpty
argument_list|()
condition|?
literal|0
else|:
name|itemsAtPoint
operator|.
name|first
argument_list|()
return|;
block|}
endif|#
directive|endif
name|QGraphicsItem
operator|*
name|itemAt
argument_list|(
argument|const QPointF&pos
argument_list|,
argument|const QTransform&deviceTransform
argument_list|)
specifier|const
block|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|Qt::ItemSelectionMode mode = Qt::IntersectsItemShape
argument_list|)
specifier|const
block|{
return|return
name|items
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
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
endif|#
directive|endif
specifier|inline
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|Qt::ItemSelectionMode mode
argument_list|,
argument|Qt::SortOrder order
argument_list|,
argument|const QTransform&deviceTransform = QTransform()
argument_list|)
specifier|const
block|{
return|return
name|items
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|mode
argument_list|,
name|order
argument_list|,
name|deviceTransform
argument_list|)
return|;
block|}
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|QGraphicsItem
operator|*
name|itemAt
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|)
specifier|const
block|{
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|itemsAtPoint
operator|=
name|items
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
block|;
return|return
name|itemsAtPoint
operator|.
name|isEmpty
argument_list|()
condition|?
literal|0
else|:
name|itemsAtPoint
operator|.
name|first
argument_list|()
return|;
block|}
endif|#
directive|endif
specifier|inline
name|QGraphicsItem
operator|*
name|itemAt
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|const QTransform&deviceTransform
argument_list|)
specifier|const
block|{
return|return
name|itemAt
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|,
name|deviceTransform
argument_list|)
return|;
block|}
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|selectedItems
argument_list|()
specifier|const
block|;
name|QPainterPath
name|selectionArea
argument_list|()
specifier|const
block|;
name|void
name|setSelectionArea
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|path
argument_list|,
specifier|const
name|QTransform
operator|&
name|deviceTransform
argument_list|)
block|;
name|void
name|setSelectionArea
argument_list|(
argument|const QPainterPath&path
argument_list|,
argument|Qt::ItemSelectionMode mode = Qt::IntersectsItemShape
argument_list|,
argument|const QTransform&deviceTransform = QTransform()
argument_list|)
block|;
name|void
name|setSelectionArea
argument_list|(
argument|const QPainterPath&path
argument_list|,
argument|Qt::ItemSelectionOperation selectionOperation
argument_list|,
argument|Qt::ItemSelectionMode mode = Qt::IntersectsItemShape
argument_list|,
argument|const QTransform&deviceTransform = QTransform()
argument_list|)
block|;
comment|// ### Qt6 merge the last 2 functions and add a default: Qt::ItemSelectionOperation selectionOperation = Qt::ReplaceSelection
name|QGraphicsItemGroup
operator|*
name|createItemGroup
argument_list|(
specifier|const
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
operator|&
name|items
argument_list|)
block|;
name|void
name|destroyItemGroup
argument_list|(
name|QGraphicsItemGroup
operator|*
name|group
argument_list|)
block|;
name|void
name|addItem
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|QGraphicsEllipseItem
operator|*
name|addEllipse
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|,
specifier|const
name|QPen
operator|&
name|pen
operator|=
name|QPen
argument_list|()
argument_list|,
specifier|const
name|QBrush
operator|&
name|brush
operator|=
name|QBrush
argument_list|()
argument_list|)
block|;
name|QGraphicsLineItem
operator|*
name|addLine
argument_list|(
specifier|const
name|QLineF
operator|&
name|line
argument_list|,
specifier|const
name|QPen
operator|&
name|pen
operator|=
name|QPen
argument_list|()
argument_list|)
block|;
name|QGraphicsPathItem
operator|*
name|addPath
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|path
argument_list|,
specifier|const
name|QPen
operator|&
name|pen
operator|=
name|QPen
argument_list|()
argument_list|,
specifier|const
name|QBrush
operator|&
name|brush
operator|=
name|QBrush
argument_list|()
argument_list|)
block|;
name|QGraphicsPixmapItem
operator|*
name|addPixmap
argument_list|(
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|)
block|;
name|QGraphicsPolygonItem
operator|*
name|addPolygon
argument_list|(
specifier|const
name|QPolygonF
operator|&
name|polygon
argument_list|,
specifier|const
name|QPen
operator|&
name|pen
operator|=
name|QPen
argument_list|()
argument_list|,
specifier|const
name|QBrush
operator|&
name|brush
operator|=
name|QBrush
argument_list|()
argument_list|)
block|;
name|QGraphicsRectItem
operator|*
name|addRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|,
specifier|const
name|QPen
operator|&
name|pen
operator|=
name|QPen
argument_list|()
argument_list|,
specifier|const
name|QBrush
operator|&
name|brush
operator|=
name|QBrush
argument_list|()
argument_list|)
block|;
name|QGraphicsTextItem
operator|*
name|addText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
specifier|const
name|QFont
operator|&
name|font
operator|=
name|QFont
argument_list|()
argument_list|)
block|;
name|QGraphicsSimpleTextItem
operator|*
name|addSimpleText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
specifier|const
name|QFont
operator|&
name|font
operator|=
name|QFont
argument_list|()
argument_list|)
block|;
name|QGraphicsProxyWidget
operator|*
name|addWidget
argument_list|(
argument|QWidget *widget
argument_list|,
argument|Qt::WindowFlags wFlags =
literal|0
argument_list|)
block|;
specifier|inline
name|QGraphicsEllipseItem
operator|*
name|addEllipse
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|const QPen&pen = QPen()
argument_list|,
argument|const QBrush&brush = QBrush()
argument_list|)
block|{
return|return
name|addEllipse
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|pen
argument_list|,
name|brush
argument_list|)
return|;
block|}
specifier|inline
name|QGraphicsLineItem
operator|*
name|addLine
argument_list|(
argument|qreal x1
argument_list|,
argument|qreal y1
argument_list|,
argument|qreal x2
argument_list|,
argument|qreal y2
argument_list|,
argument|const QPen&pen = QPen()
argument_list|)
block|{
return|return
name|addLine
argument_list|(
name|QLineF
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
name|x2
argument_list|,
name|y2
argument_list|)
argument_list|,
name|pen
argument_list|)
return|;
block|}
specifier|inline
name|QGraphicsRectItem
operator|*
name|addRect
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|const QPen&pen = QPen()
argument_list|,
argument|const QBrush&brush = QBrush()
argument_list|)
block|{
return|return
name|addRect
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|pen
argument_list|,
name|brush
argument_list|)
return|;
block|}
name|void
name|removeItem
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|QGraphicsItem
operator|*
name|focusItem
argument_list|()
specifier|const
block|;
name|void
name|setFocusItem
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|Qt::FocusReason focusReason = Qt::OtherFocusReason
argument_list|)
block|;
name|bool
name|hasFocus
argument_list|()
specifier|const
block|;
name|void
name|setFocus
argument_list|(
argument|Qt::FocusReason focusReason = Qt::OtherFocusReason
argument_list|)
block|;
name|void
name|clearFocus
argument_list|()
block|;
name|void
name|setStickyFocus
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|stickyFocus
argument_list|()
specifier|const
block|;
name|QGraphicsItem
operator|*
name|mouseGrabberItem
argument_list|()
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
name|virtual
name|QVariant
name|inputMethodQuery
argument_list|(
argument|Qt::InputMethodQuery query
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QGraphicsView
operator|*
operator|>
name|views
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|update
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|)
block|{
name|update
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
block|; }
specifier|inline
name|void
name|invalidate
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|SceneLayers layers = AllLayers
argument_list|)
block|{
name|invalidate
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|layers
argument_list|)
block|; }
name|QStyle
operator|*
name|style
argument_list|()
specifier|const
block|;
name|void
name|setStyle
argument_list|(
name|QStyle
operator|*
name|style
argument_list|)
block|;
name|QFont
name|font
argument_list|()
specifier|const
block|;
name|void
name|setFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|QPalette
name|palette
argument_list|()
specifier|const
block|;
name|void
name|setPalette
argument_list|(
specifier|const
name|QPalette
operator|&
name|palette
argument_list|)
block|;
name|bool
name|isActive
argument_list|()
specifier|const
block|;
name|QGraphicsItem
operator|*
name|activePanel
argument_list|()
specifier|const
block|;
name|void
name|setActivePanel
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|QGraphicsWidget
operator|*
name|activeWindow
argument_list|()
specifier|const
block|;
name|void
name|setActiveWindow
argument_list|(
name|QGraphicsWidget
operator|*
name|widget
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
name|qreal
name|minimumRenderSize
argument_list|()
specifier|const
block|;
name|void
name|setMinimumRenderSize
argument_list|(
argument|qreal minSize
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|update
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
operator|=
name|QRectF
argument_list|()
argument_list|)
block|;
name|void
name|invalidate
argument_list|(
argument|const QRectF&rect = QRectF()
argument_list|,
argument|SceneLayers layers = AllLayers
argument_list|)
block|;
name|void
name|advance
argument_list|()
block|;
name|void
name|clearSelection
argument_list|()
block|;
name|void
name|clear
argument_list|()
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|eventFilter
argument_list|(
argument|QObject *watched
argument_list|,
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|contextMenuEvent
argument_list|(
name|QGraphicsSceneContextMenuEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|dragEnterEvent
argument_list|(
name|QGraphicsSceneDragDropEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|dragMoveEvent
argument_list|(
name|QGraphicsSceneDragDropEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|dragLeaveEvent
argument_list|(
name|QGraphicsSceneDragDropEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|dropEvent
argument_list|(
name|QGraphicsSceneDragDropEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|focusInEvent
argument_list|(
name|QFocusEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|focusOutEvent
argument_list|(
name|QFocusEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|helpEvent
argument_list|(
name|QGraphicsSceneHelpEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|keyReleaseEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|mousePressEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|mouseMoveEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|mouseReleaseEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|mouseDoubleClickEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|wheelEvent
argument_list|(
name|QGraphicsSceneWheelEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
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
argument_list|,
argument|QWidget *widget =
literal|0
argument_list|)
block|;
name|protected
name|Q_SLOTS
operator|:
comment|// ### Qt 6: make unconditional
if|#
directive|if
name|QT_VERSION
operator|>=
name|QT_VERSION_CHECK
argument_list|(
literal|6
operator|,
literal|0
operator|,
literal|0
argument_list|)
name|virtual
endif|#
directive|endif
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|changed
argument_list|(
specifier|const
name|QList
operator|<
name|QRectF
operator|>
operator|&
name|region
argument_list|)
block|;
name|void
name|sceneRectChanged
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|void
name|selectionChanged
argument_list|()
block|;
name|void
name|focusItemChanged
argument_list|(
argument|QGraphicsItem *newFocus
argument_list|,
argument|QGraphicsItem *oldFocus
argument_list|,
argument|Qt::FocusReason reason
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsScene
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsScene
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitUpdated()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_polishItems()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_processDirtyItems()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateScenePosDescendants()
argument_list|)
name|friend
name|class
name|QGraphicsItem
block|;
name|friend
name|class
name|QGraphicsItemPrivate
block|;
name|friend
name|class
name|QGraphicsObject
block|;
name|friend
name|class
name|QGraphicsView
block|;
name|friend
name|class
name|QGraphicsViewPrivate
block|;
name|friend
name|class
name|QGraphicsWidget
block|;
name|friend
name|class
name|QGraphicsWidgetPrivate
block|;
name|friend
name|class
name|QGraphicsEffect
block|;
name|friend
name|class
name|QGraphicsSceneIndex
block|;
name|friend
name|class
name|QGraphicsSceneIndexPrivate
block|;
name|friend
name|class
name|QGraphicsSceneBspTreeIndex
block|;
name|friend
name|class
name|QGraphicsSceneBspTreeIndexPrivate
block|;
name|friend
name|class
name|QGraphicsItemEffectSourcePrivate
block|;
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|friend
name|class
name|QGesture
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QGraphicsScene::SceneLayers
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GRAPHICSVIEW
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
