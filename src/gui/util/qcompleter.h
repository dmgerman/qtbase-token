begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOMPLETER_H
end_ifndef
begin_define
DECL|macro|QCOMPLETER_H
define|#
directive|define
name|QCOMPLETER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
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
name|QT_NO_COMPLETER
name|class
name|QCompleterPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractItemView
name|class
name|QAbstractItemView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractProxyModel
name|class
name|QAbstractProxyModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QCompleter
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QString completionPrefix READ completionPrefix WRITE setCompletionPrefix
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|ModelSorting modelSorting READ modelSorting WRITE setModelSorting
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|CompletionMode completionMode READ completionMode WRITE setCompletionMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int completionColumn READ completionColumn WRITE setCompletionColumn
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int completionRole READ completionRole WRITE setCompletionRole
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int maxVisibleItems READ maxVisibleItems WRITE setMaxVisibleItems
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::CaseSensitivity caseSensitivity READ caseSensitivity WRITE setCaseSensitivity
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool wrapAround READ wrapAround WRITE setWrapAround
argument_list|)
name|public
operator|:
expr|enum
name|CompletionMode
block|{
name|PopupCompletion
block|,
name|UnfilteredPopupCompletion
block|,
name|InlineCompletion
block|}
block|;      enum
name|ModelSorting
block|{
name|UnsortedModel
operator|=
literal|0
block|,
name|CaseSensitivelySortedModel
block|,
name|CaseInsensitivelySortedModel
block|}
block|;
name|QCompleter
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QCompleter
argument_list|(
name|QAbstractItemModel
operator|*
name|model
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_STRINGLISTMODEL
name|QCompleter
argument_list|(
specifier|const
name|QStringList
operator|&
name|completions
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
endif|#
directive|endif
operator|~
name|QCompleter
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
name|void
name|setModel
argument_list|(
name|QAbstractItemModel
operator|*
name|c
argument_list|)
block|;
name|QAbstractItemModel
operator|*
name|model
argument_list|()
specifier|const
block|;
name|void
name|setCompletionMode
argument_list|(
argument|CompletionMode mode
argument_list|)
block|;
name|CompletionMode
name|completionMode
argument_list|()
specifier|const
block|;
name|QAbstractItemView
operator|*
name|popup
argument_list|()
specifier|const
block|;
name|void
name|setPopup
argument_list|(
name|QAbstractItemView
operator|*
name|popup
argument_list|)
block|;
name|void
name|setCaseSensitivity
argument_list|(
argument|Qt::CaseSensitivity caseSensitivity
argument_list|)
block|;
name|Qt
operator|::
name|CaseSensitivity
name|caseSensitivity
argument_list|()
specifier|const
block|;
name|void
name|setModelSorting
argument_list|(
argument|ModelSorting sorting
argument_list|)
block|;
name|ModelSorting
name|modelSorting
argument_list|()
specifier|const
block|;
name|void
name|setCompletionColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|int
name|completionColumn
argument_list|()
specifier|const
block|;
name|void
name|setCompletionRole
argument_list|(
argument|int role
argument_list|)
block|;
name|int
name|completionRole
argument_list|()
specifier|const
block|;
name|bool
name|wrapAround
argument_list|()
specifier|const
block|;
name|int
name|maxVisibleItems
argument_list|()
specifier|const
block|;
name|void
name|setMaxVisibleItems
argument_list|(
argument|int maxItems
argument_list|)
block|;
name|int
name|completionCount
argument_list|()
specifier|const
block|;
name|bool
name|setCurrentRow
argument_list|(
argument|int row
argument_list|)
block|;
name|int
name|currentRow
argument_list|()
specifier|const
block|;
name|QModelIndex
name|currentIndex
argument_list|()
specifier|const
block|;
name|QString
name|currentCompletion
argument_list|()
specifier|const
block|;
name|QAbstractItemModel
operator|*
name|completionModel
argument_list|()
specifier|const
block|;
name|QString
name|completionPrefix
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setCompletionPrefix
argument_list|(
specifier|const
name|QString
operator|&
name|prefix
argument_list|)
block|;
name|void
name|complete
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
operator|=
name|QRect
argument_list|()
argument_list|)
block|;
name|void
name|setWrapAround
argument_list|(
argument|bool wrap
argument_list|)
block|;
name|public
operator|:
name|virtual
name|QString
name|pathFromIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|virtual
name|QStringList
name|splitPath
argument_list|(
argument|const QString&path
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|o
argument_list|,
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|activated
argument_list|(
specifier|const
name|QString
operator|&
name|text
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
name|highlighted
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|highlighted
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QCompleter
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QCompleter
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_complete(QModelIndex)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_completionSelected(const QItemSelection&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_autoResizePopup()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_fileSystemModelDirectoryLoaded(const QString&)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COMPLETER
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
comment|// QCOMPLETER_H
end_comment
end_unit
