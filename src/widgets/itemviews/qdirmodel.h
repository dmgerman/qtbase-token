begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIRMODEL_H
end_ifndef
begin_define
DECL|macro|QDIRMODEL_H
define|#
directive|define
name|QDIRMODEL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdir.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qfileiconprovider.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_DIRMODEL
DECL|variable|QDirModelPrivate
name|class
name|QDirModelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QDirModel
range|:
name|public
name|QAbstractItemModel
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool resolveSymlinks READ resolveSymlinks WRITE setResolveSymlinks
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool readOnly READ isReadOnly WRITE setReadOnly
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool lazyChildCount READ lazyChildCount WRITE setLazyChildCount
argument_list|)
name|public
operator|:
expr|enum
name|Roles
block|{
name|FileIconRole
operator|=
name|Qt
operator|::
name|DecorationRole
block|,
name|FilePathRole
operator|=
name|Qt
operator|::
name|UserRole
operator|+
literal|1
block|,
name|FileNameRole
block|}
block|;
name|QDirModel
argument_list|(
argument|const QStringList&nameFilters
argument_list|,
argument|QDir::Filters filters
argument_list|,
argument|QDir::SortFlags sort
argument_list|,
argument|QObject *parent = Q_NULLPTR
argument_list|)
block|;
name|explicit
name|QDirModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QDirModel
argument_list|()
block|;
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
name|Q_DECL_OVERRIDE
block|;
name|QModelIndex
name|parent
argument_list|(
argument|const QModelIndex&child
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|columnCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|int role = Qt::DisplayRole
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
name|bool
name|hasChildren
argument_list|(
argument|const QModelIndex&index = QModelIndex()
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
name|void
name|sort
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order = Qt::AscendingOrder
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QStringList
name|mimeTypes
argument_list|()
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
name|Qt
operator|::
name|DropActions
name|supportedDropActions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
comment|// QDirModel specific API
name|void
name|setIconProvider
argument_list|(
name|QFileIconProvider
operator|*
name|provider
argument_list|)
block|;
name|QFileIconProvider
operator|*
name|iconProvider
argument_list|()
specifier|const
block|;
name|void
name|setNameFilters
argument_list|(
specifier|const
name|QStringList
operator|&
name|filters
argument_list|)
block|;
name|QStringList
name|nameFilters
argument_list|()
specifier|const
block|;
name|void
name|setFilter
argument_list|(
argument|QDir::Filters filters
argument_list|)
block|;
name|QDir
operator|::
name|Filters
name|filter
argument_list|()
specifier|const
block|;
name|void
name|setSorting
argument_list|(
argument|QDir::SortFlags sort
argument_list|)
block|;
name|QDir
operator|::
name|SortFlags
name|sorting
argument_list|()
specifier|const
block|;
name|void
name|setResolveSymlinks
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|resolveSymlinks
argument_list|()
specifier|const
block|;
name|void
name|setReadOnly
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isReadOnly
argument_list|()
specifier|const
block|;
name|void
name|setLazyChildCount
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|lazyChildCount
argument_list|()
specifier|const
block|;
name|QModelIndex
name|index
argument_list|(
argument|const QString&path
argument_list|,
argument|int column =
literal|0
argument_list|)
specifier|const
block|;
name|bool
name|isDir
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QModelIndex
name|mkdir
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|parent
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|bool
name|rmdir
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|bool
name|remove
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|QString
name|filePath
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QString
name|fileName
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QIcon
name|fileIcon
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QFileInfo
name|fileInfo
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|using
name|QObject
operator|::
name|parent
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|refresh
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|parent
operator|=
name|QModelIndex
argument_list|()
argument_list|)
block|;
name|protected
operator|:
name|QDirModel
argument_list|(
name|QDirModelPrivate
operator|&
argument_list|,
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|friend
name|class
name|QFileDialogPrivate
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDirModel
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QDirModel
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_refresh()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DIRMODEL
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDIRMODEL_H
end_comment
end_unit
