begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Stephen Kelly<stephen.kelly@kdab.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIDENTITYPROXYMODEL_H
end_ifndef
begin_define
DECL|macro|QIDENTITYPROXYMODEL_H
define|#
directive|define
name|QIDENTITYPROXYMODEL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstractproxymodel.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IDENTITYPROXYMODEL
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QIdentityProxyModelPrivate
name|class
name|QIdentityProxyModelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QIdentityProxyModel
range|:
name|public
name|QAbstractProxyModel
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QIdentityProxyModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QIdentityProxyModel
argument_list|()
block|;
name|int
name|columnCount
argument_list|(
argument|const QModelIndex& parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|QModelIndex
name|index
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex& parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|QModelIndex
name|mapFromSource
argument_list|(
argument|const QModelIndex& sourceIndex
argument_list|)
specifier|const
block|;
name|QModelIndex
name|mapToSource
argument_list|(
argument|const QModelIndex& proxyIndex
argument_list|)
specifier|const
block|;
name|QModelIndex
name|parent
argument_list|(
argument|const QModelIndex& child
argument_list|)
specifier|const
block|;
name|int
name|rowCount
argument_list|(
argument|const QModelIndex& parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|QVariant
name|headerData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|int role
argument_list|)
specifier|const
block|;
name|bool
name|dropMimeData
argument_list|(
argument|const QMimeData* data
argument_list|,
argument|Qt::DropAction action
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex& parent
argument_list|)
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
name|QItemSelection
name|mapSelectionFromSource
argument_list|(
argument|const QItemSelection& selection
argument_list|)
specifier|const
block|;
name|QItemSelection
name|mapSelectionToSource
argument_list|(
argument|const QItemSelection& selection
argument_list|)
specifier|const
block|;
name|QModelIndexList
name|match
argument_list|(
argument|const QModelIndex& start
argument_list|,
argument|int role
argument_list|,
argument|const QVariant& value
argument_list|,
argument|int hits =
literal|1
argument_list|,
argument|Qt::MatchFlags flags = Qt::MatchFlags(Qt::MatchStartsWith|Qt::MatchWrap)
argument_list|)
specifier|const
block|;
name|void
name|setSourceModel
argument_list|(
name|QAbstractItemModel
operator|*
name|sourceModel
argument_list|)
block|;
name|bool
name|insertColumns
argument_list|(
argument|int column
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex& parent = QModelIndex()
argument_list|)
block|;
name|bool
name|insertRows
argument_list|(
argument|int row
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex& parent = QModelIndex()
argument_list|)
block|;
name|bool
name|removeColumns
argument_list|(
argument|int column
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex& parent = QModelIndex()
argument_list|)
block|;
name|bool
name|removeRows
argument_list|(
argument|int row
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex& parent = QModelIndex()
argument_list|)
block|;
name|protected
operator|:
name|QIdentityProxyModel
argument_list|(
name|QIdentityProxyModelPrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QIdentityProxyModel
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QIdentityProxyModel
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceRowsAboutToBeInserted(QModelIndex,int,int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceRowsInserted(QModelIndex,int,int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceRowsAboutToBeRemoved(QModelIndex,int,int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceRowsRemoved(QModelIndex,int,int)
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
argument|void _q_sourceColumnsAboutToBeInserted(QModelIndex,int,int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceColumnsInserted(QModelIndex,int,int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceColumnsAboutToBeRemoved(QModelIndex,int,int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceColumnsRemoved(QModelIndex,int,int)
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
argument|void _q_sourceDataChanged(QModelIndex,QModelIndex,QVector<int>)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceHeaderDataChanged(Qt::Orientation orientation, int first, int last)
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
argument|void _q_sourceModelAboutToBeReset()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceModelReset()
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
comment|// QT_NO_IDENTITYPROXYMODEL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QIDENTITYPROXYMODEL_H
end_comment
end_unit
