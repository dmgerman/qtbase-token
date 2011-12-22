begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHEADERVIEW_H
end_ifndef
begin_define
DECL|macro|QHEADERVIEW_H
define|#
directive|define
name|QHEADERVIEW_H
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
name|QT_NO_ITEMVIEWS
DECL|variable|QHeaderViewPrivate
name|class
name|QHeaderViewPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionHeader
name|class
name|QStyleOptionHeader
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QHeaderView
range|:
name|public
name|QAbstractItemView
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool showSortIndicator READ isSortIndicatorShown WRITE setSortIndicatorShown
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool highlightSections READ highlightSections WRITE setHighlightSections
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool stretchLastSection READ stretchLastSection WRITE setStretchLastSection
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool cascadingSectionResizes READ cascadingSectionResizes WRITE setCascadingSectionResizes
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int defaultSectionSize READ defaultSectionSize WRITE setDefaultSectionSize
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int minimumSectionSize READ minimumSectionSize WRITE setMinimumSectionSize
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Alignment defaultAlignment READ defaultAlignment WRITE setDefaultAlignment
argument_list|)
name|Q_ENUMS
argument_list|(
argument|ResizeMode
argument_list|)
name|public
operator|:
expr|enum
name|ResizeMode
block|{
name|Interactive
block|,
name|Stretch
block|,
name|Fixed
block|,
name|ResizeToContents
block|,
name|Custom
operator|=
name|Fixed
block|}
block|;
name|explicit
name|QHeaderView
argument_list|(
argument|Qt::Orientation orientation
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QHeaderView
argument_list|()
block|;
name|void
name|setModel
argument_list|(
name|QAbstractItemModel
operator|*
name|model
argument_list|)
block|;
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|()
specifier|const
block|;
name|int
name|offset
argument_list|()
specifier|const
block|;
name|int
name|length
argument_list|()
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|void
name|setVisible
argument_list|(
argument|bool v
argument_list|)
block|;
name|int
name|sectionSizeHint
argument_list|(
argument|int logicalIndex
argument_list|)
specifier|const
block|;
name|int
name|visualIndexAt
argument_list|(
argument|int position
argument_list|)
specifier|const
block|;
name|int
name|logicalIndexAt
argument_list|(
argument|int position
argument_list|)
specifier|const
block|;
specifier|inline
name|int
name|logicalIndexAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
specifier|inline
name|int
name|logicalIndexAt
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
name|int
name|sectionSize
argument_list|(
argument|int logicalIndex
argument_list|)
specifier|const
block|;
name|int
name|sectionPosition
argument_list|(
argument|int logicalIndex
argument_list|)
specifier|const
block|;
name|int
name|sectionViewportPosition
argument_list|(
argument|int logicalIndex
argument_list|)
specifier|const
block|;
name|void
name|moveSection
argument_list|(
argument|int from
argument_list|,
argument|int to
argument_list|)
block|;
name|void
name|swapSections
argument_list|(
argument|int first
argument_list|,
argument|int second
argument_list|)
block|;
name|void
name|resizeSection
argument_list|(
argument|int logicalIndex
argument_list|,
argument|int size
argument_list|)
block|;
name|void
name|resizeSections
argument_list|(
argument|QHeaderView::ResizeMode mode
argument_list|)
block|;
name|bool
name|isSectionHidden
argument_list|(
argument|int logicalIndex
argument_list|)
specifier|const
block|;
name|void
name|setSectionHidden
argument_list|(
argument|int logicalIndex
argument_list|,
argument|bool hide
argument_list|)
block|;
name|int
name|hiddenSectionCount
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|hideSection
argument_list|(
argument|int logicalIndex
argument_list|)
block|;
specifier|inline
name|void
name|showSection
argument_list|(
argument|int logicalIndex
argument_list|)
block|;
name|int
name|count
argument_list|()
specifier|const
block|;
name|int
name|visualIndex
argument_list|(
argument|int logicalIndex
argument_list|)
specifier|const
block|;
name|int
name|logicalIndex
argument_list|(
argument|int visualIndex
argument_list|)
specifier|const
block|;
name|void
name|setSectionsMovable
argument_list|(
argument|bool movable
argument_list|)
block|;
name|bool
name|sectionsMovable
argument_list|()
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
specifier|inline
name|QT_DEPRECATED
name|void
name|setMovable
argument_list|(
argument|bool movable
argument_list|)
block|{
name|setSectionsMovable
argument_list|(
name|movable
argument_list|)
block|; }
specifier|inline
name|QT_DEPRECATED
name|bool
name|isMovable
argument_list|()
specifier|const
block|{
return|return
name|sectionsMovable
argument_list|()
return|;
block|}
endif|#
directive|endif
name|void
name|setSectionsClickable
argument_list|(
argument|bool clickable
argument_list|)
block|;
name|bool
name|sectionsClickable
argument_list|()
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
specifier|inline
name|QT_DEPRECATED
name|void
name|setClickable
argument_list|(
argument|bool clickable
argument_list|)
block|{
name|setSectionsClickable
argument_list|(
name|clickable
argument_list|)
block|; }
specifier|inline
name|QT_DEPRECATED
name|bool
name|isClickable
argument_list|()
specifier|const
block|{
return|return
name|sectionsClickable
argument_list|()
return|;
block|}
endif|#
directive|endif
name|void
name|setHighlightSections
argument_list|(
argument|bool highlight
argument_list|)
block|;
name|bool
name|highlightSections
argument_list|()
specifier|const
block|;
name|ResizeMode
name|sectionResizeMode
argument_list|(
argument|int logicalIndex
argument_list|)
specifier|const
block|;
name|void
name|setSectionResizeMode
argument_list|(
argument|ResizeMode mode
argument_list|)
block|;
name|void
name|setSectionResizeMode
argument_list|(
argument|int logicalIndex
argument_list|,
argument|ResizeMode mode
argument_list|)
block|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
specifier|inline
name|QT_DEPRECATED
name|void
name|setResizeMode
argument_list|(
argument|ResizeMode mode
argument_list|)
block|{
name|setSectionResizeMode
argument_list|(
name|mode
argument_list|)
block|; }
specifier|inline
name|QT_DEPRECATED
name|void
name|setResizeMode
argument_list|(
argument|int logicalindex
argument_list|,
argument|ResizeMode mode
argument_list|)
block|{
name|setSectionResizeMode
argument_list|(
name|logicalindex
argument_list|,
name|mode
argument_list|)
block|; }
specifier|inline
name|QT_DEPRECATED
name|ResizeMode
name|resizeMode
argument_list|(
argument|int logicalindex
argument_list|)
specifier|const
block|{
return|return
name|sectionResizeMode
argument_list|(
name|logicalindex
argument_list|)
return|;
block|}
endif|#
directive|endif
name|int
name|stretchSectionCount
argument_list|()
specifier|const
block|;
name|void
name|setSortIndicatorShown
argument_list|(
argument|bool show
argument_list|)
block|;
name|bool
name|isSortIndicatorShown
argument_list|()
specifier|const
block|;
name|void
name|setSortIndicator
argument_list|(
argument|int logicalIndex
argument_list|,
argument|Qt::SortOrder order
argument_list|)
block|;
name|int
name|sortIndicatorSection
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|SortOrder
name|sortIndicatorOrder
argument_list|()
specifier|const
block|;
name|bool
name|stretchLastSection
argument_list|()
specifier|const
block|;
name|void
name|setStretchLastSection
argument_list|(
argument|bool stretch
argument_list|)
block|;
name|bool
name|cascadingSectionResizes
argument_list|()
specifier|const
block|;
name|void
name|setCascadingSectionResizes
argument_list|(
argument|bool enable
argument_list|)
block|;
name|int
name|defaultSectionSize
argument_list|()
specifier|const
block|;
name|void
name|setDefaultSectionSize
argument_list|(
argument|int size
argument_list|)
block|;
name|int
name|minimumSectionSize
argument_list|()
specifier|const
block|;
name|void
name|setMinimumSectionSize
argument_list|(
argument|int size
argument_list|)
block|;
name|Qt
operator|::
name|Alignment
name|defaultAlignment
argument_list|()
specifier|const
block|;
name|void
name|setDefaultAlignment
argument_list|(
argument|Qt::Alignment alignment
argument_list|)
block|;
name|void
name|doItemsLayout
argument_list|()
block|;
name|bool
name|sectionsMoved
argument_list|()
specifier|const
block|;
name|bool
name|sectionsHidden
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|QByteArray
name|saveState
argument_list|()
specifier|const
block|;
name|bool
name|restoreState
argument_list|(
specifier|const
name|QByteArray
operator|&
name|state
argument_list|)
block|;
endif|#
directive|endif
name|void
name|reset
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setOffset
argument_list|(
argument|int offset
argument_list|)
block|;
name|void
name|setOffsetToSectionPosition
argument_list|(
argument|int visualIndex
argument_list|)
block|;
name|void
name|setOffsetToLastSection
argument_list|()
block|;
name|void
name|headerDataChanged
argument_list|(
argument|Qt::Orientation orientation
argument_list|,
argument|int logicalFirst
argument_list|,
argument|int logicalLast
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|sectionMoved
argument_list|(
argument|int logicalIndex
argument_list|,
argument|int oldVisualIndex
argument_list|,
argument|int newVisualIndex
argument_list|)
block|;
name|void
name|sectionResized
argument_list|(
argument|int logicalIndex
argument_list|,
argument|int oldSize
argument_list|,
argument|int newSize
argument_list|)
block|;
name|void
name|sectionPressed
argument_list|(
argument|int logicalIndex
argument_list|)
block|;
name|void
name|sectionClicked
argument_list|(
argument|int logicalIndex
argument_list|)
block|;
name|void
name|sectionEntered
argument_list|(
argument|int logicalIndex
argument_list|)
block|;
name|void
name|sectionDoubleClicked
argument_list|(
argument|int logicalIndex
argument_list|)
block|;
name|void
name|sectionCountChanged
argument_list|(
argument|int oldCount
argument_list|,
argument|int newCount
argument_list|)
block|;
name|void
name|sectionHandleDoubleClicked
argument_list|(
argument|int logicalIndex
argument_list|)
block|;
name|void
name|geometriesChanged
argument_list|()
block|;
name|void
name|sortIndicatorChanged
argument_list|(
argument|int logicalIndex
argument_list|,
argument|Qt::SortOrder order
argument_list|)
block|;
name|protected
name|Q_SLOTS
operator|:
name|void
name|updateSection
argument_list|(
argument|int logicalIndex
argument_list|)
block|;
name|void
name|resizeSections
argument_list|()
block|;
name|void
name|sectionsInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int logicalFirst
argument_list|,
argument|int logicalLast
argument_list|)
block|;
name|void
name|sectionsAboutToBeRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int logicalFirst
argument_list|,
argument|int logicalLast
argument_list|)
block|;
name|protected
operator|:
name|QHeaderView
argument_list|(
argument|QHeaderViewPrivate&dd
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
name|void
name|initialize
argument_list|()
block|;
name|void
name|initializeSections
argument_list|()
block|;
name|void
name|initializeSections
argument_list|(
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|void
name|currentChanged
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|current
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|old
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|mouseDoubleClickEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|bool
name|viewportEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|paintSection
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QRect&rect
argument_list|,
argument|int logicalIndex
argument_list|)
specifier|const
block|;
name|virtual
name|QSize
name|sectionSizeFromContents
argument_list|(
argument|int logicalIndex
argument_list|)
specifier|const
block|;
name|int
name|horizontalOffset
argument_list|()
specifier|const
block|;
name|int
name|verticalOffset
argument_list|()
specifier|const
block|;
name|void
name|updateGeometries
argument_list|()
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
name|dataChanged
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|topLeft
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|bottomRight
argument_list|,
specifier|const
name|QVector
operator|<
name|int
operator|>
operator|&
name|roles
operator|=
name|QVector
operator|<
name|int
operator|>
operator|(
operator|)
argument_list|)
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
block|;
name|QRect
name|visualRect
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|scrollTo
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|ScrollHint hint
argument_list|)
block|;
name|QModelIndex
name|indexAt
argument_list|(
argument|const QPoint&p
argument_list|)
specifier|const
block|;
name|bool
name|isIndexHidden
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QModelIndex
name|moveCursor
argument_list|(
name|CursorAction
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
argument_list|)
block|;
name|void
name|setSelection
argument_list|(
argument|const QRect& rect
argument_list|,
argument|QItemSelectionModel::SelectionFlags flags
argument_list|)
block|;
name|QRegion
name|visualRegionForSelection
argument_list|(
argument|const QItemSelection&selection
argument_list|)
specifier|const
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionHeader *option
argument_list|)
specifier|const
block|;
name|friend
name|class
name|QTableView
block|;
name|friend
name|class
name|QTreeView
block|;
name|private
operator|:
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sectionsRemoved(const QModelIndex&parent, int logicalFirst, int logicalLast)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_layoutAboutToBeChanged()
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QHeaderView
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QHeaderView
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|logicalIndexAt
specifier|inline
name|int
name|QHeaderView
operator|::
name|logicalIndexAt
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|)
specifier|const
block|{
return|return
name|orientation
argument_list|()
operator|==
name|Qt
operator|::
name|Horizontal
operator|?
name|logicalIndexAt
argument_list|(
name|ax
argument_list|)
operator|:
name|logicalIndexAt
argument_list|(
name|ay
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|logicalIndexAt
specifier|inline
name|int
name|QHeaderView
operator|::
name|logicalIndexAt
argument_list|(
argument|const QPoint&apos
argument_list|)
specifier|const
block|{
return|return
name|logicalIndexAt
argument_list|(
name|apos
operator|.
name|x
argument_list|()
argument_list|,
name|apos
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|hideSection
specifier|inline
name|void
name|QHeaderView
operator|::
name|hideSection
argument_list|(
argument|int alogicalIndex
argument_list|)
block|{
name|setSectionHidden
argument_list|(
name|alogicalIndex
argument_list|,
name|true
argument_list|)
block|; }
DECL|function|showSection
specifier|inline
name|void
name|QHeaderView
operator|::
name|showSection
argument_list|(
argument|int alogicalIndex
argument_list|)
block|{
name|setSectionHidden
argument_list|(
name|alogicalIndex
argument_list|,
name|false
argument_list|)
block|; }
endif|#
directive|endif
comment|// QT_NO_ITEMVIEWS
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QHEADERVIEW_H
end_comment
end_unit
