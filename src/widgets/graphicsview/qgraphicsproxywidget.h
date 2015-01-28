begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSPROXYWIDGET_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSPROXYWIDGET_H
define|#
directive|define
name|QGRAPHICSPROXYWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicswidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GRAPHICSVIEW
argument_list|)
DECL|variable|QGraphicsProxyWidgetPrivate
name|class
name|QGraphicsProxyWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsProxyWidget
range|:
name|public
name|QGraphicsWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|QGraphicsProxyWidget
argument_list|(
argument|QGraphicsItem *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags wFlags =
literal|0
argument_list|)
block|;
operator|~
name|QGraphicsProxyWidget
argument_list|()
block|;
name|void
name|setWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QWidget
operator|*
name|widget
argument_list|()
specifier|const
block|;
name|QRectF
name|subWidgetRect
argument_list|(
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|setGeometry
argument_list|(
argument|const QRectF&rect
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionGraphicsItem *option
argument_list|,
argument|QWidget *widget
argument_list|)
name|Q_DECL_OVERRIDE
block|;      enum
block|{
name|Type
operator|=
literal|12
block|}
block|;
name|int
name|type
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QGraphicsProxyWidget
operator|*
name|createProxyForChildWidget
argument_list|(
name|QWidget
operator|*
name|child
argument_list|)
block|;
name|protected
operator|:
name|QVariant
name|itemChange
argument_list|(
argument|GraphicsItemChange change
argument_list|,
argument|const QVariant&value
argument_list|)
name|Q_DECL_OVERRIDE
block|;
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
argument|QObject *object
argument_list|,
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|showEvent
argument_list|(
argument|QShowEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|hideEvent
argument_list|(
argument|QHideEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|void
name|contextMenuEvent
argument_list|(
argument|QGraphicsSceneContextMenuEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|void
name|dragEnterEvent
argument_list|(
argument|QGraphicsSceneDragDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dragLeaveEvent
argument_list|(
argument|QGraphicsSceneDragDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dragMoveEvent
argument_list|(
argument|QGraphicsSceneDragDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dropEvent
argument_list|(
argument|QGraphicsSceneDragDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|void
name|hoverEnterEvent
argument_list|(
argument|QGraphicsSceneHoverEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|hoverLeaveEvent
argument_list|(
argument|QGraphicsSceneHoverEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|hoverMoveEvent
argument_list|(
argument|QGraphicsSceneHoverEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|grabMouseEvent
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|ungrabMouseEvent
argument_list|(
argument|QEvent *event
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
name|mousePressEvent
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
name|void
name|mouseDoubleClickEvent
argument_list|(
argument|QGraphicsSceneMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
argument|QGraphicsSceneWheelEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|void
name|keyPressEvent
argument_list|(
argument|QKeyEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|keyReleaseEvent
argument_list|(
argument|QKeyEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|focusInEvent
argument_list|(
argument|QFocusEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|focusOutEvent
argument_list|(
argument|QFocusEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|inputMethodQuery
argument_list|(
argument|Qt::InputMethodQuery query
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|inputMethodEvent
argument_list|(
argument|QInputMethodEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QSizeF
name|sizeHint
argument_list|(
argument|Qt::SizeHint which
argument_list|,
argument|const QSizeF&constraint = QSizeF()
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|resizeEvent
argument_list|(
argument|QGraphicsSceneResizeEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
name|Q_SLOTS
operator|:
name|QGraphicsProxyWidget
operator|*
name|newProxyWidget
argument_list|(
specifier|const
name|QWidget
operator|*
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsProxyWidget
argument_list|)
name|Q_DECLARE_PRIVATE_D
argument_list|(
argument|QGraphicsItem::d_ptr.data()
argument_list|,
argument|QGraphicsProxyWidget
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_removeWidgetSlot()
argument_list|)
name|friend
name|class
name|QWidget
block|;
name|friend
name|class
name|QWidgetPrivate
block|;
name|friend
name|class
name|QGraphicsItem
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
