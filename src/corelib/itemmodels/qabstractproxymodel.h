begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTPROXYMODEL_H
end_ifndef
begin_define
DECL|macro|QABSTRACTPROXYMODEL_H
define|#
directive|define
name|QABSTRACTPROXYMODEL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstractitemmodel.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_PROXYMODEL
DECL|variable|QAbstractProxyModelPrivate
name|class
name|QAbstractProxyModelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QItemSelection
name|class
name|QItemSelection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAbstractProxyModel
range|:
name|public
name|QAbstractItemModel
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QAbstractItemModel* sourceModel READ sourceModel WRITE setSourceModel NOTIFY sourceModelChanged
argument_list|)
name|public
operator|:
name|explicit
name|QAbstractProxyModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QAbstractProxyModel
argument_list|()
block|;
name|virtual
name|void
name|setSourceModel
argument_list|(
name|QAbstractItemModel
operator|*
name|sourceModel
argument_list|)
block|;
name|QAbstractItemModel
operator|*
name|sourceModel
argument_list|()
specifier|const
block|;
name|Q_INVOKABLE
name|virtual
name|QModelIndex
name|mapToSource
argument_list|(
argument|const QModelIndex&proxyIndex
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|Q_INVOKABLE
name|virtual
name|QModelIndex
name|mapFromSource
argument_list|(
argument|const QModelIndex&sourceIndex
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|Q_INVOKABLE
name|virtual
name|QItemSelection
name|mapSelectionToSource
argument_list|(
argument|const QItemSelection&selection
argument_list|)
specifier|const
block|;
name|Q_INVOKABLE
name|virtual
name|QItemSelection
name|mapSelectionFromSource
argument_list|(
argument|const QItemSelection&selection
argument_list|)
specifier|const
block|;
name|bool
name|submit
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|revert
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&proxyIndex
argument_list|,
argument|int role = Qt::DisplayRole
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|QMap
operator|<
name|int
block|,
name|QVariant
operator|>
name|itemData
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|bool
name|setItemData
argument_list|(
argument|const QModelIndex& index
argument_list|,
argument|const QMap<int
argument_list|,
argument|QVariant>&roles
argument_list|)
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|QModelIndex
name|buddy
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|canFetchMore
argument_list|(
argument|const QModelIndex&parent
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|fetchMore
argument_list|(
argument|const QModelIndex&parent
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|sort
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order = Qt::AscendingOrder
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|span
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasChildren
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|QMimeData
operator|*
name|mimeData
argument_list|(
argument|const QModelIndexList&indexes
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|canDropMimeData
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
specifier|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|QStringList
name|mimeTypes
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|DropActions
name|supportedDragActions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|DropActions
name|supportedDropActions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Q_SIGNALS
operator|:
name|void
name|sourceModelChanged
argument_list|(
name|QPrivateSignal
argument_list|)
block|;
name|protected
name|Q_SLOTS
operator|:
name|void
name|resetInternalData
argument_list|()
block|;
name|protected
operator|:
name|QAbstractProxyModel
argument_list|(
name|QAbstractProxyModelPrivate
operator|&
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
argument|QAbstractProxyModel
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractProxyModel
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sourceModelDestroyed()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PROXYMODEL
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QABSTRACTPROXYMODEL_H
end_comment
end_unit
