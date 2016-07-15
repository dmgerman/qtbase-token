begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSANCHORLAYOUT_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSANCHORLAYOUT_H
define|#
directive|define
name|QGRAPHICSANCHORLAYOUT_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicsitem.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicslayout.h>
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
DECL|variable|QGraphicsAnchorPrivate
name|class
name|QGraphicsAnchorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsAnchorLayout
name|class
name|QGraphicsAnchorLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsAnchorLayoutPrivate
name|class
name|QGraphicsAnchorLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsAnchor
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|qreal spacing READ spacing WRITE setSpacing RESET unsetSpacing
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QSizePolicy::Policy sizePolicy READ sizePolicy WRITE setSizePolicy
argument_list|)
name|public
operator|:
name|void
name|setSpacing
argument_list|(
argument|qreal spacing
argument_list|)
block|;
name|void
name|unsetSpacing
argument_list|()
block|;
name|qreal
name|spacing
argument_list|()
specifier|const
block|;
name|void
name|setSizePolicy
argument_list|(
argument|QSizePolicy::Policy policy
argument_list|)
block|;
name|QSizePolicy
operator|::
name|Policy
name|sizePolicy
argument_list|()
specifier|const
block|;
operator|~
name|QGraphicsAnchor
argument_list|()
block|;
name|private
operator|:
name|QGraphicsAnchor
argument_list|(
name|QGraphicsAnchorLayout
operator|*
name|parent
argument_list|)
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsAnchor
argument_list|)
name|friend
name|class
name|QGraphicsAnchorLayoutPrivate
block|;
name|friend
expr|struct
name|AnchorData
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsAnchorLayout
range|:
name|public
name|QGraphicsLayout
block|{
name|public
operator|:
name|QGraphicsAnchorLayout
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|virtual
operator|~
name|QGraphicsAnchorLayout
argument_list|()
block|;
name|QGraphicsAnchor
operator|*
name|addAnchor
argument_list|(
argument|QGraphicsLayoutItem *firstItem
argument_list|,
argument|Qt::AnchorPoint firstEdge
argument_list|,
argument|QGraphicsLayoutItem *secondItem
argument_list|,
argument|Qt::AnchorPoint secondEdge
argument_list|)
block|;
name|QGraphicsAnchor
operator|*
name|anchor
argument_list|(
argument|QGraphicsLayoutItem *firstItem
argument_list|,
argument|Qt::AnchorPoint firstEdge
argument_list|,
argument|QGraphicsLayoutItem *secondItem
argument_list|,
argument|Qt::AnchorPoint secondEdge
argument_list|)
block|;
name|void
name|addCornerAnchors
argument_list|(
argument|QGraphicsLayoutItem *firstItem
argument_list|,
argument|Qt::Corner firstCorner
argument_list|,
argument|QGraphicsLayoutItem *secondItem
argument_list|,
argument|Qt::Corner secondCorner
argument_list|)
block|;
name|void
name|addAnchors
argument_list|(
argument|QGraphicsLayoutItem *firstItem
argument_list|,
argument|QGraphicsLayoutItem *secondItem
argument_list|,
argument|Qt::Orientations orientations = Qt::Horizontal | Qt::Vertical
argument_list|)
block|;
name|void
name|setHorizontalSpacing
argument_list|(
argument|qreal spacing
argument_list|)
block|;
name|void
name|setVerticalSpacing
argument_list|(
argument|qreal spacing
argument_list|)
block|;
name|void
name|setSpacing
argument_list|(
argument|qreal spacing
argument_list|)
block|;
name|qreal
name|horizontalSpacing
argument_list|()
specifier|const
block|;
name|qreal
name|verticalSpacing
argument_list|()
specifier|const
block|;
name|void
name|removeAt
argument_list|(
argument|int index
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setGeometry
argument_list|(
argument|const QRectF&rect
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|int
name|count
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QGraphicsLayoutItem
operator|*
name|itemAt
argument_list|(
argument|int index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|invalidate
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
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
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsAnchorLayout
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsAnchorLayout
argument_list|)
name|friend
name|class
name|QGraphicsAnchor
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
