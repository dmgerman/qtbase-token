begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLISTVIEW_H
end_ifndef
begin_define
DECL|macro|QLISTVIEW_H
define|#
directive|define
name|QLISTVIEW_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qabstractitemview.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_LISTVIEW
DECL|variable|QListViewPrivate
name|class
name|QListViewPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QListView
range|:
name|public
name|QAbstractItemView
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|Movement movement READ movement WRITE setMovement
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Flow flow READ flow WRITE setFlow
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool isWrapping READ isWrapping WRITE setWrapping
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|ResizeMode resizeMode READ resizeMode WRITE setResizeMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|LayoutMode layoutMode READ layoutMode WRITE setLayoutMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int spacing READ spacing WRITE setSpacing
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QSize gridSize READ gridSize WRITE setGridSize
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|ViewMode viewMode READ viewMode WRITE setViewMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int modelColumn READ modelColumn WRITE setModelColumn
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool uniformItemSizes READ uniformItemSizes WRITE setUniformItemSizes
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int batchSize READ batchSize WRITE setBatchSize
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool wordWrap READ wordWrap WRITE setWordWrap
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool selectionRectVisible READ isSelectionRectVisible WRITE setSelectionRectVisible
argument_list|)
name|public
operator|:
expr|enum
name|Movement
block|{
name|Static
block|,
name|Free
block|,
name|Snap
block|}
block|;
name|Q_ENUM
argument_list|(
name|Movement
argument_list|)
expr|enum
name|Flow
block|{
name|LeftToRight
block|,
name|TopToBottom
block|}
block|;
name|Q_ENUM
argument_list|(
name|Flow
argument_list|)
expr|enum
name|ResizeMode
block|{
name|Fixed
block|,
name|Adjust
block|}
block|;
name|Q_ENUM
argument_list|(
name|ResizeMode
argument_list|)
expr|enum
name|LayoutMode
block|{
name|SinglePass
block|,
name|Batched
block|}
block|;
name|Q_ENUM
argument_list|(
name|LayoutMode
argument_list|)
expr|enum
name|ViewMode
block|{
name|ListMode
block|,
name|IconMode
block|}
block|;
name|Q_ENUM
argument_list|(
argument|ViewMode
argument_list|)
name|explicit
name|QListView
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QListView
argument_list|()
block|;
name|void
name|setMovement
argument_list|(
argument|Movement movement
argument_list|)
block|;
name|Movement
name|movement
argument_list|()
specifier|const
block|;
name|void
name|setFlow
argument_list|(
argument|Flow flow
argument_list|)
block|;
name|Flow
name|flow
argument_list|()
specifier|const
block|;
name|void
name|setWrapping
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isWrapping
argument_list|()
specifier|const
block|;
name|void
name|setResizeMode
argument_list|(
argument|ResizeMode mode
argument_list|)
block|;
name|ResizeMode
name|resizeMode
argument_list|()
specifier|const
block|;
name|void
name|setLayoutMode
argument_list|(
argument|LayoutMode mode
argument_list|)
block|;
name|LayoutMode
name|layoutMode
argument_list|()
specifier|const
block|;
name|void
name|setSpacing
argument_list|(
argument|int space
argument_list|)
block|;
name|int
name|spacing
argument_list|()
specifier|const
block|;
name|void
name|setBatchSize
argument_list|(
argument|int batchSize
argument_list|)
block|;
name|int
name|batchSize
argument_list|()
specifier|const
block|;
name|void
name|setGridSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|QSize
name|gridSize
argument_list|()
specifier|const
block|;
name|void
name|setViewMode
argument_list|(
argument|ViewMode mode
argument_list|)
block|;
name|ViewMode
name|viewMode
argument_list|()
specifier|const
block|;
name|void
name|clearPropertyFlags
argument_list|()
block|;
name|bool
name|isRowHidden
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|void
name|setRowHidden
argument_list|(
argument|int row
argument_list|,
argument|bool hide
argument_list|)
block|;
name|void
name|setModelColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|int
name|modelColumn
argument_list|()
specifier|const
block|;
name|void
name|setUniformItemSizes
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|uniformItemSizes
argument_list|()
specifier|const
block|;
name|void
name|setWordWrap
argument_list|(
argument|bool on
argument_list|)
block|;
name|bool
name|wordWrap
argument_list|()
specifier|const
block|;
name|void
name|setSelectionRectVisible
argument_list|(
argument|bool show
argument_list|)
block|;
name|bool
name|isSelectionRectVisible
argument_list|()
specifier|const
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
argument|const QPoint&p
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|doItemsLayout
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|reset
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|setRootIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|Q_SIGNALS
operator|:
name|void
name|indexesMoved
argument_list|(
specifier|const
name|QModelIndexList
operator|&
name|indexes
argument_list|)
block|;
name|protected
operator|:
name|QListView
argument_list|(
name|QListViewPrivate
operator|&
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|bool
name|event
argument_list|(
argument|QEvent *e
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
name|void
name|resizeContents
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|QSize
name|contentsSize
argument_list|()
specifier|const
block|;
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
name|void
name|mouseMoveEvent
argument_list|(
argument|QMouseEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseReleaseEvent
argument_list|(
argument|QMouseEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
argument|QWheelEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|void
name|timerEvent
argument_list|(
argument|QTimerEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|resizeEvent
argument_list|(
argument|QResizeEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|void
name|dragMoveEvent
argument_list|(
argument|QDragMoveEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dragLeaveEvent
argument_list|(
argument|QDragLeaveEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dropEvent
argument_list|(
argument|QDropEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|startDrag
argument_list|(
argument|Qt::DropActions supportedActions
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
comment|// QT_NO_DRAGANDDROP
name|QStyleOptionViewItem
name|viewOptions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *e
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
name|QModelIndex
name|moveCursor
argument_list|(
argument|CursorAction cursorAction
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QRect
name|rectForIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|setPositionForIndex
argument_list|(
specifier|const
name|QPoint
operator|&
name|position
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|setSelection
argument_list|(
argument|const QRect&rect
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
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
name|QModelIndexList
name|selectedIndexes
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|updateGeometries
argument_list|()
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
name|selectionChanged
argument_list|(
argument|const QItemSelection&selected
argument_list|,
argument|const QItemSelection&deselected
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|currentChanged
argument_list|(
argument|const QModelIndex&current
argument_list|,
argument|const QModelIndex&previous
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|viewportSizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|int
name|visualIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QListView
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QListView
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LISTVIEW
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLISTVIEW_H
end_comment
end_unit
