begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTREEVIEW_H
end_ifndef
begin_define
DECL|macro|QTREEVIEW_H
define|#
directive|define
name|QTREEVIEW_H
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
name|QT_NO_TREEVIEW
DECL|variable|QTreeViewPrivate
name|class
name|QTreeViewPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHeaderView
name|class
name|QHeaderView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QTreeView
range|:
name|public
name|QAbstractItemView
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int autoExpandDelay READ autoExpandDelay WRITE setAutoExpandDelay
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int indentation READ indentation WRITE setIndentation RESET resetIndentation
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool rootIsDecorated READ rootIsDecorated WRITE setRootIsDecorated
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool uniformRowHeights READ uniformRowHeights WRITE setUniformRowHeights
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool itemsExpandable READ itemsExpandable WRITE setItemsExpandable
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool sortingEnabled READ isSortingEnabled WRITE setSortingEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool animated READ isAnimated WRITE setAnimated
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool allColumnsShowFocus READ allColumnsShowFocus WRITE setAllColumnsShowFocus
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool wordWrap READ wordWrap WRITE setWordWrap
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool headerHidden READ isHeaderHidden WRITE setHeaderHidden
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool expandsOnDoubleClick READ expandsOnDoubleClick WRITE setExpandsOnDoubleClick
argument_list|)
name|public
operator|:
name|explicit
name|QTreeView
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QTreeView
argument_list|()
block|;
name|void
name|setModel
argument_list|(
argument|QAbstractItemModel *model
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setRootIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setSelectionModel
argument_list|(
argument|QItemSelectionModel *selectionModel
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QHeaderView
operator|*
name|header
argument_list|()
specifier|const
block|;
name|void
name|setHeader
argument_list|(
name|QHeaderView
operator|*
name|header
argument_list|)
block|;
name|int
name|autoExpandDelay
argument_list|()
specifier|const
block|;
name|void
name|setAutoExpandDelay
argument_list|(
argument|int delay
argument_list|)
block|;
name|int
name|indentation
argument_list|()
specifier|const
block|;
name|void
name|setIndentation
argument_list|(
argument|int i
argument_list|)
block|;
name|void
name|resetIndentation
argument_list|()
block|;
name|bool
name|rootIsDecorated
argument_list|()
specifier|const
block|;
name|void
name|setRootIsDecorated
argument_list|(
argument|bool show
argument_list|)
block|;
name|bool
name|uniformRowHeights
argument_list|()
specifier|const
block|;
name|void
name|setUniformRowHeights
argument_list|(
argument|bool uniform
argument_list|)
block|;
name|bool
name|itemsExpandable
argument_list|()
specifier|const
block|;
name|void
name|setItemsExpandable
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|expandsOnDoubleClick
argument_list|()
specifier|const
block|;
name|void
name|setExpandsOnDoubleClick
argument_list|(
argument|bool enable
argument_list|)
block|;
name|int
name|columnViewportPosition
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|int
name|columnWidth
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setColumnWidth
argument_list|(
argument|int column
argument_list|,
argument|int width
argument_list|)
block|;
name|int
name|columnAt
argument_list|(
argument|int x
argument_list|)
specifier|const
block|;
name|bool
name|isColumnHidden
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setColumnHidden
argument_list|(
argument|int column
argument_list|,
argument|bool hide
argument_list|)
block|;
name|bool
name|isHeaderHidden
argument_list|()
specifier|const
block|;
name|void
name|setHeaderHidden
argument_list|(
argument|bool hide
argument_list|)
block|;
name|bool
name|isRowHidden
argument_list|(
argument|int row
argument_list|,
argument|const QModelIndex&parent
argument_list|)
specifier|const
block|;
name|void
name|setRowHidden
argument_list|(
argument|int row
argument_list|,
argument|const QModelIndex&parent
argument_list|,
argument|bool hide
argument_list|)
block|;
name|bool
name|isFirstColumnSpanned
argument_list|(
argument|int row
argument_list|,
argument|const QModelIndex&parent
argument_list|)
specifier|const
block|;
name|void
name|setFirstColumnSpanned
argument_list|(
argument|int row
argument_list|,
argument|const QModelIndex&parent
argument_list|,
argument|bool span
argument_list|)
block|;
name|bool
name|isExpanded
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|setExpanded
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|bool expand
argument_list|)
block|;
name|void
name|setSortingEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isSortingEnabled
argument_list|()
specifier|const
block|;
name|void
name|setAnimated
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isAnimated
argument_list|()
specifier|const
block|;
name|void
name|setAllColumnsShowFocus
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|allColumnsShowFocus
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
name|setTreePosition
argument_list|(
argument|int logicalIndex
argument_list|)
block|;
name|int
name|treePosition
argument_list|()
specifier|const
block|;
name|void
name|keyboardSearch
argument_list|(
argument|const QString&search
argument_list|)
name|Q_DECL_OVERRIDE
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
name|QModelIndex
name|indexAbove
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QModelIndex
name|indexBelow
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
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
name|sortByColumn
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order
argument_list|)
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
name|selectAll
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|Q_SIGNALS
operator|:
name|void
name|expanded
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|collapsed
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|hideColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|void
name|showColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|void
name|expand
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|collapse
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|resizeColumnToContents
argument_list|(
argument|int column
argument_list|)
block|;
name|void
name|sortByColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|void
name|expandAll
argument_list|()
block|;
name|void
name|collapseAll
argument_list|()
block|;
name|void
name|expandToDepth
argument_list|(
argument|int depth
argument_list|)
block|;
name|protected
name|Q_SLOTS
operator|:
name|void
name|columnResized
argument_list|(
argument|int column
argument_list|,
argument|int oldSize
argument_list|,
argument|int newSize
argument_list|)
block|;
name|void
name|columnCountChanged
argument_list|(
argument|int oldCount
argument_list|,
argument|int newCount
argument_list|)
block|;
name|void
name|columnMoved
argument_list|()
block|;
name|void
name|reexpand
argument_list|()
block|;
name|void
name|rowsRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|protected
operator|:
name|QTreeView
argument_list|(
name|QTreeViewPrivate
operator|&
name|dd
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
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
name|QModelIndex
name|moveCursor
argument_list|(
argument|CursorAction cursorAction
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
name|timerEvent
argument_list|(
argument|QTimerEvent *event
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
name|drawTree
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QRegion&region
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|drawRow
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionViewItem&options
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|drawBranches
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QRect&rect
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|mousePressEvent
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
name|mouseDoubleClickEvent
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
name|keyPressEvent
argument_list|(
argument|QKeyEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|void
name|dragMoveEvent
argument_list|(
argument|QDragMoveEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|bool
name|viewportEvent
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|updateGeometries
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|viewportSizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|sizeHintForColumn
argument_list|(
argument|int column
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|indexRowSizeHint
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|int
name|rowHeight
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|horizontalScrollbarAction
argument_list|(
argument|int action
argument_list|)
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
name|private
operator|:
name|friend
name|class
name|QAccessibleTable
block|;
name|friend
name|class
name|QAccessibleTree
block|;
name|friend
name|class
name|QAccessibleTableCell
block|;
name|int
name|visualIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTreeView
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QTreeView
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_endAnimatedOperation()
argument_list|)
endif|#
directive|endif
comment|//QT_NO_ANIMATION
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_modelAboutToBeReset()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sortIndicatorChanged(int column, Qt::SortOrder order)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TREEVIEW
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTREEVIEW_H
end_comment
end_unit
