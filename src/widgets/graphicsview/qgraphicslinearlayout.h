begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSLINEARLAYOUT_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSLINEARLAYOUT_H
define|#
directive|define
name|QGRAPHICSLINEARLAYOUT_H
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
DECL|variable|QGraphicsLinearLayoutPrivate
name|class
name|QGraphicsLinearLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsLinearLayout
range|:
name|public
name|QGraphicsLayout
block|{
name|public
operator|:
name|QGraphicsLinearLayout
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QGraphicsLinearLayout
argument_list|(
argument|Qt::Orientation orientation
argument_list|,
argument|QGraphicsLayoutItem *parent =
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QGraphicsLinearLayout
argument_list|()
block|;
name|void
name|setOrientation
argument_list|(
argument|Qt::Orientation orientation
argument_list|)
block|;
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|addItem
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|)
block|{
name|insertItem
argument_list|(
operator|-
literal|1
argument_list|,
name|item
argument_list|)
block|; }
specifier|inline
name|void
name|addStretch
argument_list|(
argument|int stretch =
literal|1
argument_list|)
block|{
name|insertStretch
argument_list|(
operator|-
literal|1
argument_list|,
name|stretch
argument_list|)
block|; }
name|void
name|insertItem
argument_list|(
argument|int index
argument_list|,
argument|QGraphicsLayoutItem *item
argument_list|)
block|;
name|void
name|insertStretch
argument_list|(
argument|int index
argument_list|,
argument|int stretch =
literal|1
argument_list|)
block|;
name|void
name|removeItem
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|item
argument_list|)
block|;
name|void
name|removeAt
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|setSpacing
argument_list|(
argument|qreal spacing
argument_list|)
block|;
name|qreal
name|spacing
argument_list|()
specifier|const
block|;
name|void
name|setItemSpacing
argument_list|(
argument|int index
argument_list|,
argument|qreal spacing
argument_list|)
block|;
name|qreal
name|itemSpacing
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|void
name|setStretchFactor
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|,
argument|int stretch
argument_list|)
block|;
name|int
name|stretchFactor
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|)
specifier|const
block|;
name|void
name|setAlignment
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|,
argument|Qt::Alignment alignment
argument_list|)
block|;
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|)
specifier|const
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|int
name|count
argument_list|()
specifier|const
block|;
name|QGraphicsLayoutItem
operator|*
name|itemAt
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|void
name|invalidate
argument_list|()
block|;
name|QSizeF
name|sizeHint
argument_list|(
argument|Qt::SizeHint which
argument_list|,
argument|const QSizeF&constraint = QSizeF()
argument_list|)
specifier|const
block|;
if|#
directive|if
literal|0
comment|// ###
block|Q5SizePolicy::ControlTypes controlTypes(LayoutSide side) const;
endif|#
directive|endif
name|void
name|dump
argument_list|(
argument|int indent =
literal|0
argument_list|)
specifier|const
block|;
name|protected
operator|:
if|#
directive|if
literal|0
expr|QSize contentsSizeHint(Qt::SizeHint which, const QSize&constraint = QSize()) const;
endif|#
directive|endif
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsLinearLayout
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsLinearLayout
argument_list|)
block|}
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
