begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSGRIDLAYOUT_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSGRIDLAYOUT_H
define|#
directive|define
name|QGRAPHICSGRIDLAYOUT_H
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
DECL|variable|QGraphicsGridLayoutPrivate
name|class
name|QGraphicsGridLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsGridLayout
range|:
name|public
name|QGraphicsLayout
block|{
name|public
operator|:
name|QGraphicsGridLayout
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QGraphicsGridLayout
argument_list|()
block|;
name|void
name|addItem
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|int rowSpan
argument_list|,
argument|int columnSpan
argument_list|,
argument|Qt::Alignment alignment =
literal|0
argument_list|)
block|;
specifier|inline
name|void
name|addItem
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|Qt::Alignment alignment =
literal|0
argument_list|)
block|;
name|void
name|setHorizontalSpacing
argument_list|(
argument|qreal spacing
argument_list|)
block|;
name|qreal
name|horizontalSpacing
argument_list|()
specifier|const
block|;
name|void
name|setVerticalSpacing
argument_list|(
argument|qreal spacing
argument_list|)
block|;
name|qreal
name|verticalSpacing
argument_list|()
specifier|const
block|;
name|void
name|setSpacing
argument_list|(
argument|qreal spacing
argument_list|)
block|;
name|void
name|setRowSpacing
argument_list|(
argument|int row
argument_list|,
argument|qreal spacing
argument_list|)
block|;
name|qreal
name|rowSpacing
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|void
name|setColumnSpacing
argument_list|(
argument|int column
argument_list|,
argument|qreal spacing
argument_list|)
block|;
name|qreal
name|columnSpacing
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setRowStretchFactor
argument_list|(
argument|int row
argument_list|,
argument|int stretch
argument_list|)
block|;
name|int
name|rowStretchFactor
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|void
name|setColumnStretchFactor
argument_list|(
argument|int column
argument_list|,
argument|int stretch
argument_list|)
block|;
name|int
name|columnStretchFactor
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setRowMinimumHeight
argument_list|(
argument|int row
argument_list|,
argument|qreal height
argument_list|)
block|;
name|qreal
name|rowMinimumHeight
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|void
name|setRowPreferredHeight
argument_list|(
argument|int row
argument_list|,
argument|qreal height
argument_list|)
block|;
name|qreal
name|rowPreferredHeight
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|void
name|setRowMaximumHeight
argument_list|(
argument|int row
argument_list|,
argument|qreal height
argument_list|)
block|;
name|qreal
name|rowMaximumHeight
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|void
name|setRowFixedHeight
argument_list|(
argument|int row
argument_list|,
argument|qreal height
argument_list|)
block|;
name|void
name|setColumnMinimumWidth
argument_list|(
argument|int column
argument_list|,
argument|qreal width
argument_list|)
block|;
name|qreal
name|columnMinimumWidth
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setColumnPreferredWidth
argument_list|(
argument|int column
argument_list|,
argument|qreal width
argument_list|)
block|;
name|qreal
name|columnPreferredWidth
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setColumnMaximumWidth
argument_list|(
argument|int column
argument_list|,
argument|qreal width
argument_list|)
block|;
name|qreal
name|columnMaximumWidth
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setColumnFixedWidth
argument_list|(
argument|int column
argument_list|,
argument|qreal width
argument_list|)
block|;
name|void
name|setRowAlignment
argument_list|(
argument|int row
argument_list|,
argument|Qt::Alignment alignment
argument_list|)
block|;
name|Qt
operator|::
name|Alignment
name|rowAlignment
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|void
name|setColumnAlignment
argument_list|(
argument|int column
argument_list|,
argument|Qt::Alignment alignment
argument_list|)
block|;
name|Qt
operator|::
name|Alignment
name|columnAlignment
argument_list|(
argument|int column
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
name|int
name|rowCount
argument_list|()
specifier|const
block|;
name|int
name|columnCount
argument_list|()
specifier|const
block|;
name|QGraphicsLayoutItem
operator|*
name|itemAt
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|;
comment|// inherited from QGraphicsLayout
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
name|removeAt
argument_list|(
argument|int index
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
name|invalidate
argument_list|()
block|;
comment|// inherited from QGraphicsLayoutItem
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
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
comment|// ####
comment|//QRect cellRect(int row, int column, int rowSpan = 1, int columnSpan = 1) const;
comment|//QSizePolicy::ControlTypes controlTypes(LayoutSide side) const;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsGridLayout
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsGridLayout
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|addItem
specifier|inline
name|void
name|QGraphicsGridLayout
operator|::
name|addItem
argument_list|(
argument|QGraphicsLayoutItem *aitem
argument_list|,
argument|int arow
argument_list|,
argument|int acolumn
argument_list|,
argument|Qt::Alignment aalignment
argument_list|)
block|{
name|addItem
argument_list|(
name|aitem
argument_list|,
name|arow
argument_list|,
name|acolumn
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|aalignment
argument_list|)
block|; }
endif|#
directive|endif
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
