begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTITEMVIEW_H
end_ifndef
begin_define
DECL|macro|QABSTRACTITEMVIEW_H
define|#
directive|define
name|QABSTRACTITEMVIEW_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qabstractscrollarea.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qitemselectionmodel.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qabstractitemdelegate.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDrag
name|class
name|QDrag
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEvent
name|class
name|QEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractItemViewPrivate
name|class
name|QAbstractItemViewPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QAbstractItemView
range|:
name|public
name|QAbstractScrollArea
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|SelectionMode SelectionBehavior ScrollHint ScrollMode DragDropMode
argument_list|)
name|Q_FLAGS
argument_list|(
argument|EditTriggers
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool autoScroll READ hasAutoScroll WRITE setAutoScroll
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int autoScrollMargin READ autoScrollMargin WRITE setAutoScrollMargin
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|EditTriggers editTriggers READ editTriggers WRITE setEditTriggers
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool tabKeyNavigation READ tabKeyNavigation WRITE setTabKeyNavigation
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|Q_PROPERTY
argument_list|(
argument|bool showDropIndicator READ showDropIndicator WRITE setDropIndicatorShown
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool dragEnabled READ dragEnabled WRITE setDragEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool dragDropOverwriteMode READ dragDropOverwriteMode WRITE setDragDropOverwriteMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|DragDropMode dragDropMode READ dragDropMode WRITE setDragDropMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::DropAction defaultDropAction READ defaultDropAction WRITE setDefaultDropAction
argument_list|)
endif|#
directive|endif
name|Q_PROPERTY
argument_list|(
argument|bool alternatingRowColors READ alternatingRowColors WRITE setAlternatingRowColors
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|SelectionMode selectionMode READ selectionMode WRITE setSelectionMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|SelectionBehavior selectionBehavior READ selectionBehavior WRITE setSelectionBehavior
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QSize iconSize READ iconSize WRITE setIconSize
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::TextElideMode textElideMode READ textElideMode WRITE setTextElideMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|ScrollMode verticalScrollMode READ verticalScrollMode WRITE setVerticalScrollMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|ScrollMode horizontalScrollMode READ horizontalScrollMode WRITE setHorizontalScrollMode
argument_list|)
name|public
operator|:
expr|enum
name|SelectionMode
block|{
name|NoSelection
block|,
name|SingleSelection
block|,
name|MultiSelection
block|,
name|ExtendedSelection
block|,
name|ContiguousSelection
block|}
block|;      enum
name|SelectionBehavior
block|{
name|SelectItems
block|,
name|SelectRows
block|,
name|SelectColumns
block|}
block|;      enum
name|ScrollHint
block|{
name|EnsureVisible
block|,
name|PositionAtTop
block|,
name|PositionAtBottom
block|,
name|PositionAtCenter
block|}
block|;      enum
name|EditTrigger
block|{
name|NoEditTriggers
operator|=
literal|0
block|,
name|CurrentChanged
operator|=
literal|1
block|,
name|DoubleClicked
operator|=
literal|2
block|,
name|SelectedClicked
operator|=
literal|4
block|,
name|EditKeyPressed
operator|=
literal|8
block|,
name|AnyKeyPressed
operator|=
literal|16
block|,
name|AllEditTriggers
operator|=
literal|31
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|EditTriggers
argument_list|,
name|EditTrigger
argument_list|)
expr|enum
name|ScrollMode
block|{
name|ScrollPerItem
block|,
name|ScrollPerPixel
block|}
block|;
name|explicit
name|QAbstractItemView
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QAbstractItemView
argument_list|()
block|;
name|virtual
name|void
name|setModel
argument_list|(
name|QAbstractItemModel
operator|*
name|model
argument_list|)
block|;
name|QAbstractItemModel
operator|*
name|model
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setSelectionModel
argument_list|(
name|QItemSelectionModel
operator|*
name|selectionModel
argument_list|)
block|;
name|QItemSelectionModel
operator|*
name|selectionModel
argument_list|()
specifier|const
block|;
name|void
name|setItemDelegate
argument_list|(
name|QAbstractItemDelegate
operator|*
name|delegate
argument_list|)
block|;
name|QAbstractItemDelegate
operator|*
name|itemDelegate
argument_list|()
specifier|const
block|;
name|void
name|setSelectionMode
argument_list|(
argument|QAbstractItemView::SelectionMode mode
argument_list|)
block|;
name|QAbstractItemView
operator|::
name|SelectionMode
name|selectionMode
argument_list|()
specifier|const
block|;
name|void
name|setSelectionBehavior
argument_list|(
argument|QAbstractItemView::SelectionBehavior behavior
argument_list|)
block|;
name|QAbstractItemView
operator|::
name|SelectionBehavior
name|selectionBehavior
argument_list|()
specifier|const
block|;
name|QModelIndex
name|currentIndex
argument_list|()
specifier|const
block|;
name|QModelIndex
name|rootIndex
argument_list|()
specifier|const
block|;
name|void
name|setEditTriggers
argument_list|(
argument|EditTriggers triggers
argument_list|)
block|;
name|EditTriggers
name|editTriggers
argument_list|()
specifier|const
block|;
name|void
name|setVerticalScrollMode
argument_list|(
argument|ScrollMode mode
argument_list|)
block|;
name|ScrollMode
name|verticalScrollMode
argument_list|()
specifier|const
block|;
name|void
name|setHorizontalScrollMode
argument_list|(
argument|ScrollMode mode
argument_list|)
block|;
name|ScrollMode
name|horizontalScrollMode
argument_list|()
specifier|const
block|;
name|void
name|setAutoScroll
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|hasAutoScroll
argument_list|()
specifier|const
block|;
name|void
name|setAutoScrollMargin
argument_list|(
argument|int margin
argument_list|)
block|;
name|int
name|autoScrollMargin
argument_list|()
specifier|const
block|;
name|void
name|setTabKeyNavigation
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|tabKeyNavigation
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|void
name|setDropIndicatorShown
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|showDropIndicator
argument_list|()
specifier|const
block|;
name|void
name|setDragEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|dragEnabled
argument_list|()
specifier|const
block|;
name|void
name|setDragDropOverwriteMode
argument_list|(
argument|bool overwrite
argument_list|)
block|;
name|bool
name|dragDropOverwriteMode
argument_list|()
specifier|const
block|;      enum
name|DragDropMode
block|{
name|NoDragDrop
block|,
name|DragOnly
block|,
name|DropOnly
block|,
name|DragDrop
block|,
name|InternalMove
block|}
block|;
name|void
name|setDragDropMode
argument_list|(
argument|DragDropMode behavior
argument_list|)
block|;
name|DragDropMode
name|dragDropMode
argument_list|()
specifier|const
block|;
name|void
name|setDefaultDropAction
argument_list|(
argument|Qt::DropAction dropAction
argument_list|)
block|;
name|Qt
operator|::
name|DropAction
name|defaultDropAction
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|void
name|setAlternatingRowColors
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|alternatingRowColors
argument_list|()
specifier|const
block|;
name|void
name|setIconSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|QSize
name|iconSize
argument_list|()
specifier|const
block|;
name|void
name|setTextElideMode
argument_list|(
argument|Qt::TextElideMode mode
argument_list|)
block|;
name|Qt
operator|::
name|TextElideMode
name|textElideMode
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|keyboardSearch
argument_list|(
specifier|const
name|QString
operator|&
name|search
argument_list|)
block|;
name|virtual
name|QRect
name|visualRect
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|scrollTo
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|ScrollHint hint = EnsureVisible
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QModelIndex
name|indexAt
argument_list|(
argument|const QPoint&point
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|QSize
name|sizeHintForIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|sizeHintForRow
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|sizeHintForColumn
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|openPersistentEditor
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|closePersistentEditor
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|setIndexWidget
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QWidget
operator|*
name|indexWidget
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|setItemDelegateForRow
argument_list|(
argument|int row
argument_list|,
argument|QAbstractItemDelegate *delegate
argument_list|)
block|;
name|QAbstractItemDelegate
operator|*
name|itemDelegateForRow
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|void
name|setItemDelegateForColumn
argument_list|(
argument|int column
argument_list|,
argument|QAbstractItemDelegate *delegate
argument_list|)
block|;
name|QAbstractItemDelegate
operator|*
name|itemDelegateForColumn
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|QAbstractItemDelegate
operator|*
name|itemDelegate
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|virtual
name|QVariant
name|inputMethodQuery
argument_list|(
argument|Qt::InputMethodQuery query
argument_list|)
specifier|const
block|;
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
specifier|inline
name|void
name|update
argument_list|()
block|{
name|QAbstractScrollArea
operator|::
name|update
argument_list|()
block|; }
else|#
directive|else
name|using
name|QAbstractScrollArea
operator|::
name|update
block|;
endif|#
directive|endif
name|public
name|Q_SLOTS
operator|:
name|virtual
name|void
name|reset
argument_list|()
block|;
name|virtual
name|void
name|setRootIndex
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|virtual
name|void
name|doItemsLayout
argument_list|()
block|;
name|virtual
name|void
name|selectAll
argument_list|()
block|;
name|void
name|edit
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|clearSelection
argument_list|()
block|;
name|void
name|setCurrentIndex
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|scrollToTop
argument_list|()
block|;
name|void
name|scrollToBottom
argument_list|()
block|;
name|void
name|update
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|protected
name|Q_SLOTS
operator|:
name|virtual
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
argument_list|)
block|;
name|virtual
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
name|virtual
name|void
name|rowsAboutToBeRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|virtual
name|void
name|selectionChanged
argument_list|(
specifier|const
name|QItemSelection
operator|&
name|selected
argument_list|,
specifier|const
name|QItemSelection
operator|&
name|deselected
argument_list|)
block|;
name|virtual
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
name|previous
argument_list|)
block|;
name|virtual
name|void
name|updateEditorData
argument_list|()
block|;
name|virtual
name|void
name|updateEditorGeometries
argument_list|()
block|;
name|virtual
name|void
name|updateGeometries
argument_list|()
block|;
name|virtual
name|void
name|verticalScrollbarAction
argument_list|(
argument|int action
argument_list|)
block|;
name|virtual
name|void
name|horizontalScrollbarAction
argument_list|(
argument|int action
argument_list|)
block|;
name|virtual
name|void
name|verticalScrollbarValueChanged
argument_list|(
argument|int value
argument_list|)
block|;
name|virtual
name|void
name|horizontalScrollbarValueChanged
argument_list|(
argument|int value
argument_list|)
block|;
name|virtual
name|void
name|closeEditor
argument_list|(
argument|QWidget *editor
argument_list|,
argument|QAbstractItemDelegate::EndEditHint hint
argument_list|)
block|;
name|virtual
name|void
name|commitData
argument_list|(
name|QWidget
operator|*
name|editor
argument_list|)
block|;
name|virtual
name|void
name|editorDestroyed
argument_list|(
name|QObject
operator|*
name|editor
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|pressed
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|clicked
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|doubleClicked
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|activated
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|entered
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|viewportEntered
argument_list|()
block|;
name|protected
operator|:
name|QAbstractItemView
argument_list|(
name|QAbstractItemViewPrivate
operator|&
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|setHorizontalStepsPerItem
argument_list|(
argument|int steps
argument_list|)
block|;
name|int
name|horizontalStepsPerItem
argument_list|()
specifier|const
block|;
name|void
name|setVerticalStepsPerItem
argument_list|(
argument|int steps
argument_list|)
block|;
name|int
name|verticalStepsPerItem
argument_list|()
specifier|const
block|;      enum
name|CursorAction
block|{
name|MoveUp
block|,
name|MoveDown
block|,
name|MoveLeft
block|,
name|MoveRight
block|,
name|MoveHome
block|,
name|MoveEnd
block|,
name|MovePageUp
block|,
name|MovePageDown
block|,
name|MoveNext
block|,
name|MovePrevious
block|}
block|;
name|virtual
name|QModelIndex
name|moveCursor
argument_list|(
argument|CursorAction cursorAction
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|horizontalOffset
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|int
name|verticalOffset
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|isIndexHidden
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setSelection
argument_list|(
argument|const QRect&rect
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QRegion
name|visualRegionForSelection
argument_list|(
argument|const QItemSelection&selection
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QModelIndexList
name|selectedIndexes
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|edit
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|EditTrigger trigger
argument_list|,
argument|QEvent *event
argument_list|)
block|;
name|virtual
name|QItemSelectionModel
operator|::
name|SelectionFlags
name|selectionCommand
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|const QEvent *event =
literal|0
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|virtual
name|void
name|startDrag
argument_list|(
argument|Qt::DropActions supportedActions
argument_list|)
block|;
endif|#
directive|endif
name|virtual
name|QStyleOptionViewItem
name|viewOptions
argument_list|()
specifier|const
block|;      enum
name|State
block|{
name|NoState
block|,
name|DraggingState
block|,
name|DragSelectingState
block|,
name|EditingState
block|,
name|ExpandingState
block|,
name|CollapsingState
block|,
name|AnimatingState
block|}
block|;
name|State
name|state
argument_list|()
specifier|const
block|;
name|void
name|setState
argument_list|(
argument|State state
argument_list|)
block|;
name|void
name|scheduleDelayedItemsLayout
argument_list|()
block|;
name|void
name|executeDelayedItemsLayout
argument_list|()
block|;
name|void
name|setDirtyRegion
argument_list|(
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
name|void
name|scrollDirtyRegion
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|QPoint
name|dirtyRegionOffset
argument_list|()
specifier|const
block|;
name|void
name|startAutoScroll
argument_list|()
block|;
name|void
name|stopAutoScroll
argument_list|()
block|;
name|void
name|doAutoScroll
argument_list|()
block|;
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|viewportEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseDoubleClickEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|void
name|dragEnterEvent
argument_list|(
name|QDragEnterEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|dragMoveEvent
argument_list|(
name|QDragMoveEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|dragLeaveEvent
argument_list|(
name|QDragLeaveEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|dropEvent
argument_list|(
name|QDropEvent
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
name|void
name|focusInEvent
argument_list|(
name|QFocusEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|focusOutEvent
argument_list|(
name|QFocusEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|inputMethodEvent
argument_list|(
name|QInputMethodEvent
operator|*
name|event
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
block|enum
name|DropIndicatorPosition
block|{
name|OnItem
block|,
name|AboveItem
block|,
name|BelowItem
block|,
name|OnViewport
block|}
block|;
name|DropIndicatorPosition
name|dropIndicatorPosition
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractItemView
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractItemView
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_columnsAboutToBeRemoved(const QModelIndex&, int, int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_columnsRemoved(const QModelIndex&, int, int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_columnsInserted(const QModelIndex&, int, int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_rowsInserted(const QModelIndex&, int, int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_rowsRemoved(const QModelIndex&, int, int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_modelDestroyed()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_layoutChanged()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_headerDataChanged()
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_scrollerStateChanged()
argument_list|)
endif|#
directive|endif
name|friend
name|class
name|QTreeViewPrivate
block|;
comment|// needed to compile with MSVC
name|friend
name|class
name|QAccessibleItemRow
block|;
name|friend
name|class
name|QListModeViewBase
block|;
name|friend
name|class
name|QListViewPrivate
block|;
comment|// needed to compile for Symbian emulator
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QAbstractItemView::EditTriggers
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ITEMVIEWS
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QABSTRACTITEMVIEW_H
end_comment
end_unit
