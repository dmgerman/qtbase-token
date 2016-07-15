begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PIEVIEW_H
end_ifndef
begin_define
DECL|macro|PIEVIEW_H
define|#
directive|define
name|PIEVIEW_H
end_define
begin_include
include|#
directive|include
file|<QAbstractItemView>
end_include
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|PieView
range|:
name|public
name|QAbstractItemView
block|{
name|Q_OBJECT
name|public
operator|:
name|PieView
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QRect
name|visualRect
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|scrollTo
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|ScrollHint hint = EnsureVisible
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QModelIndex
name|indexAt
argument_list|(
argument|const QPoint&point
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|protected
name|slots
operator|:
name|void
name|dataChanged
argument_list|(
argument|const QModelIndex&topLeft
argument_list|,
argument|const QModelIndex&bottomRight
argument_list|,
argument|const QVector<int>&roles = QVector<int>()
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|rowsInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|rowsAboutToBeRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|bool
name|edit
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|EditTrigger trigger
argument_list|,
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QModelIndex
name|moveCursor
argument_list|(
argument|QAbstractItemView::CursorAction cursorAction
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|int
name|horizontalOffset
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|verticalOffset
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isIndexHidden
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setSelection
argument_list|(
argument|const QRect&
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mousePressEvent
argument_list|(
argument|QMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseMoveEvent
argument_list|(
argument|QMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseReleaseEvent
argument_list|(
argument|QMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|resizeEvent
argument_list|(
argument|QResizeEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|scrollContentsBy
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QRegion
name|visualRegionForSelection
argument_list|(
argument|const QItemSelection&selection
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|QRect
name|itemRect
argument_list|(
argument|const QModelIndex&item
argument_list|)
specifier|const
block|;
name|QRegion
name|itemRegion
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|int
name|rows
argument_list|(
argument|const QModelIndex&index = QModelIndex()
argument_list|)
specifier|const
block|;
name|void
name|updateGeometries
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|int
name|margin
block|;
name|int
name|totalSize
block|;
name|int
name|pieSize
block|;
name|int
name|validItems
block|;
name|double
name|totalValue
block|;
name|QPoint
name|origin
block|;
name|QRubberBand
operator|*
name|rubberBand
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PIEVIEW_H
end_comment
end_unit
