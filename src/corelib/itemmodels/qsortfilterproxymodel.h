begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSORTFILTERPROXYMODEL_H
end_ifndef
begin_define
DECL|macro|QSORTFILTERPROXYMODEL_H
define|#
directive|define
name|QSORTFILTERPROXYMODEL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstractproxymodel.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SORTFILTERPROXYMODEL
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qregexp.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QSortFilterProxyModelPrivate
name|class
name|QSortFilterProxyModelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSortFilterProxyModelLessThan
name|class
name|QSortFilterProxyModelLessThan
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSortFilterProxyModelGreaterThan
name|class
name|QSortFilterProxyModelGreaterThan
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QSortFilterProxyModel
range|:
name|public
name|QAbstractProxyModel
block|{
name|friend
name|class
name|QSortFilterProxyModelLessThan
block|;
name|friend
name|class
name|QSortFilterProxyModelGreaterThan
block|;
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QRegExp filterRegExp READ filterRegExp WRITE setFilterRegExp
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int filterKeyColumn READ filterKeyColumn WRITE setFilterKeyColumn
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool dynamicSortFilter READ dynamicSortFilter WRITE setDynamicSortFilter
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::CaseSensitivity filterCaseSensitivity READ filterCaseSensitivity WRITE setFilterCaseSensitivity
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::CaseSensitivity sortCaseSensitivity READ sortCaseSensitivity WRITE setSortCaseSensitivity
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool isSortLocaleAware READ isSortLocaleAware WRITE setSortLocaleAware
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int sortRole READ sortRole WRITE setSortRole
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int filterRole READ filterRole WRITE setFilterRole
argument_list|)
name|public
operator|:
name|explicit
name|QSortFilterProxyModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QSortFilterProxyModel
argument_list|()
block|;
name|void
name|setSourceModel
argument_list|(
name|QAbstractItemModel
operator|*
name|sourceModel
argument_list|)
block|;
name|QModelIndex
name|mapToSource
argument_list|(
argument|const QModelIndex&proxyIndex
argument_list|)
specifier|const
block|;
name|QModelIndex
name|mapFromSource
argument_list|(
argument|const QModelIndex&sourceIndex
argument_list|)
specifier|const
block|;
name|QItemSelection
name|mapSelectionToSource
argument_list|(
argument|const QItemSelection&proxySelection
argument_list|)
specifier|const
block|;
name|QItemSelection
name|mapSelectionFromSource
argument_list|(
argument|const QItemSelection&sourceSelection
argument_list|)
specifier|const
block|;
name|QRegExp
name|filterRegExp
argument_list|()
specifier|const
block|;
name|void
name|setFilterRegExp
argument_list|(
specifier|const
name|QRegExp
operator|&
name|regExp
argument_list|)
block|;
name|int
name|filterKeyColumn
argument_list|()
specifier|const
block|;
name|void
name|setFilterKeyColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|Qt
operator|::
name|CaseSensitivity
name|filterCaseSensitivity
argument_list|()
specifier|const
block|;
name|void
name|setFilterCaseSensitivity
argument_list|(
argument|Qt::CaseSensitivity cs
argument_list|)
block|;
name|Qt
operator|::
name|CaseSensitivity
name|sortCaseSensitivity
argument_list|()
specifier|const
block|;
name|void
name|setSortCaseSensitivity
argument_list|(
argument|Qt::CaseSensitivity cs
argument_list|)
block|;
name|bool
name|isSortLocaleAware
argument_list|()
specifier|const
block|;
name|void
name|setSortLocaleAware
argument_list|(
argument|bool on
argument_list|)
block|;
name|int
name|sortColumn
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|SortOrder
name|sortOrder
argument_list|()
specifier|const
block|;
name|bool
name|dynamicSortFilter
argument_list|()
specifier|const
block|;
name|void
name|setDynamicSortFilter
argument_list|(
argument|bool enable
argument_list|)
block|;
name|int
name|sortRole
argument_list|()
specifier|const
block|;
name|void
name|setSortRole
argument_list|(
argument|int role
argument_list|)
block|;
name|int
name|filterRole
argument_list|()
specifier|const
block|;
name|void
name|setFilterRole
argument_list|(
argument|int role
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setFilterRegExp
argument_list|(
specifier|const
name|QString
operator|&
name|pattern
argument_list|)
block|;
name|void
name|setFilterWildcard
argument_list|(
specifier|const
name|QString
operator|&
name|pattern
argument_list|)
block|;
name|void
name|setFilterFixedString
argument_list|(
specifier|const
name|QString
operator|&
name|pattern
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|void
name|invalidate
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|bool
name|filterAcceptsRow
argument_list|(
argument|int source_row
argument_list|,
argument|const QModelIndex&source_parent
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|filterAcceptsColumn
argument_list|(
argument|int source_column
argument_list|,
argument|const QModelIndex&source_parent
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|lessThan
argument_list|(
argument|const QModelIndex&left
argument_list|,
argument|const QModelIndex&right
argument_list|)
specifier|const
block|;
name|void
name|filterChanged
argument_list|()
block|;
name|void
name|invalidateFilter
argument_list|()
block|;
name|public
operator|:
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
specifier|inline
name|QObject
operator|*
name|parent
argument_list|()
specifier|const
block|{
return|return
name|QObject
operator|::
name|parent
argument_list|()
return|;
block|}
else|#
directive|else
name|using
name|QObject
operator|::
name|parent
block|;
endif|#
directive|endif
name|QModelIndex
name|index
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|QModelIndex
name|parent
argument_list|(
argument|const QModelIndex&child
argument_list|)
specifier|const
block|;
name|QModelIndex
name|sibling
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex&idx
argument_list|)
specifier|const
block|;
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|int
name|columnCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|bool
name|hasChildren
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|int role = Qt::DisplayRole
argument_list|)
specifier|const
block|;
name|bool
name|setData
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int role = Qt::EditRole
argument_list|)
block|;
name|QVariant
name|headerData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|int role = Qt::DisplayRole
argument_list|)
specifier|const
block|;
name|bool
name|setHeaderData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int role = Qt::EditRole
argument_list|)
block|;
name|QMimeData
operator|*
name|mimeData
argument_list|(
argument|const QModelIndexList&indexes
argument_list|)
specifier|const
block|;
name|bool
name|dropMimeData
argument_list|(
argument|const QMimeData *data
argument_list|,
argument|Qt::DropAction action
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex&parent
argument_list|)
block|;
name|bool
name|insertRows
argument_list|(
argument|int row
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|bool
name|insertColumns
argument_list|(
argument|int column
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|bool
name|removeRows
argument_list|(
argument|int row
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|bool
name|removeColumns
argument_list|(
argument|int column
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|void
name|fetchMore
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|parent
argument_list|)
block|;
name|bool
name|canFetchMore
argument_list|(
argument|const QModelIndex&parent
argument_list|)
specifier|const
block|;
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QModelIndex
name|buddy
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QModelIndexList
name|match
argument_list|(
argument|const QModelIndex&start
argument_list|,
argument|int role
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int hits =
literal|1
argument_list|,
argument|Qt::MatchFlags flags =                           Qt::MatchFlags(Qt::MatchStartsWith|Qt::MatchWrap)
argument_list|)
specifier|const
block|;
name|QSize
name|span
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|sort
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order = Qt::AscendingOrder
argument_list|)
block|;
name|QStringList
name|mimeTypes
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|DropActions
name|supportedDropActions
argument_list|()
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSortFilterProxyModel
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QSortFilterProxyModel
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceDataChanged(const QModelIndex&source_top_left, const QModelIndex&source_bottom_right)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceHeaderDataChanged(Qt::Orientation orientation, int start, int end)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceAboutToBeReset()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceReset()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceLayoutAboutToBeChanged(const QList<QPersistentModelIndex>&sourceParents, QAbstractItemModel::LayoutChangeHint hint)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceLayoutChanged(const QList<QPersistentModelIndex>&sourceParents, QAbstractItemModel::LayoutChangeHint hint)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceRowsAboutToBeInserted(const QModelIndex&source_parent, int start, int end)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceRowsInserted(const QModelIndex&source_parent, int start, int end)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceRowsAboutToBeRemoved(const QModelIndex&source_parent, int start, int end)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceRowsRemoved(const QModelIndex&source_parent, int start, int end)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceRowsAboutToBeMoved(QModelIndex,int,int,QModelIndex,int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceRowsMoved(QModelIndex,int,int,QModelIndex,int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceColumnsAboutToBeInserted(const QModelIndex&source_parent, int start, int end)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceColumnsInserted(const QModelIndex&source_parent, int start, int end)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceColumnsAboutToBeRemoved(const QModelIndex&source_parent, int start, int end)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceColumnsRemoved(const QModelIndex&source_parent, int start, int end)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceColumnsAboutToBeMoved(QModelIndex,int,int,QModelIndex,int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceColumnsMoved(QModelIndex,int,int,QModelIndex,int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_clearMapping()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SORTFILTERPROXYMODEL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSORTFILTERPROXYMODEL_H
end_comment
end_unit
