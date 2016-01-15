begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOLUMNVIEW_H
end_ifndef
begin_define
DECL|macro|QCOLUMNVIEW_H
define|#
directive|define
name|QCOLUMNVIEW_H
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
name|QT_NO_COLUMNVIEW
DECL|variable|QColumnViewPrivate
name|class
name|QColumnViewPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QColumnView
range|:
name|public
name|QAbstractItemView
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool resizeGripsVisible READ resizeGripsVisible WRITE setResizeGripsVisible
argument_list|)
name|Q_SIGNALS
operator|:
name|void
name|updatePreviewWidget
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|public
operator|:
name|explicit
name|QColumnView
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QColumnView
argument_list|()
block|;
comment|// QAbstractItemView overloads
name|QModelIndex
name|indexAt
argument_list|(
argument|const QPoint&point
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
name|QSize
name|sizeHint
argument_list|()
specifier|const
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
name|setModel
argument_list|(
argument|QAbstractItemModel *model
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setSelectionModel
argument_list|(
argument|QItemSelectionModel * selectionModel
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
name|selectAll
argument_list|()
name|Q_DECL_OVERRIDE
block|;
comment|// QColumnView functions
name|void
name|setResizeGripsVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|bool
name|resizeGripsVisible
argument_list|()
specifier|const
block|;
name|QWidget
operator|*
name|previewWidget
argument_list|()
specifier|const
block|;
name|void
name|setPreviewWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|setColumnWidths
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|list
argument_list|)
block|;
name|QList
operator|<
name|int
operator|>
name|columnWidths
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|QColumnView
argument_list|(
name|QColumnViewPrivate
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
comment|// QAbstractItemView overloads
name|bool
name|isIndexHidden
argument_list|(
argument|const QModelIndex&index
argument_list|)
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
name|void
name|resizeEvent
argument_list|(
argument|QResizeEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setSelection
argument_list|(
argument|const QRect& rect
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
name|currentChanged
argument_list|(
argument|const QModelIndex&current
argument_list|,
argument|const QModelIndex&previous
argument_list|)
name|Q_DECL_OVERRIDE
block|;
comment|// QColumnView functions
name|void
name|scrollContentsBy
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QAbstractItemView
operator|*
name|createColumn
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|rootIndex
argument_list|)
block|;
name|void
name|initializeColumn
argument_list|(
argument|QAbstractItemView *column
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QColumnView
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QColumnView
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_gripMoved(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_changeCurrentColumn()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_clicked(const QModelIndex&)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COLUMNVIEW
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOLUMNVIEW_H
end_comment
end_unit
