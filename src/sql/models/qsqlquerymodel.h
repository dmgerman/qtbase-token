begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLQUERYMODEL_H
end_ifndef
begin_define
DECL|macro|QSQLQUERYMODEL_H
define|#
directive|define
name|QSQLQUERYMODEL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsqldatabase.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QSqlQueryModelPrivate
name|class
name|QSqlQueryModelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlError
name|class
name|QSqlError
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlRecord
name|class
name|QSqlRecord
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlQuery
name|class
name|QSqlQuery
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_SQL_EXPORT
name|QSqlQueryModel
range|:
name|public
name|QAbstractTableModel
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSqlQueryModel
argument_list|)
name|public
operator|:
name|explicit
name|QSqlQueryModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QSqlQueryModel
argument_list|()
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
name|QSqlRecord
name|record
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|QSqlRecord
name|record
argument_list|()
specifier|const
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&item
argument_list|,
argument|int role = Qt::DisplayRole
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
name|setQuery
argument_list|(
specifier|const
name|QSqlQuery
operator|&
name|query
argument_list|)
block|;
name|void
name|setQuery
argument_list|(
specifier|const
name|QString
operator|&
name|query
argument_list|,
specifier|const
name|QSqlDatabase
operator|&
name|db
operator|=
name|QSqlDatabase
argument_list|()
argument_list|)
block|;
name|QSqlQuery
name|query
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|clear
argument_list|()
block|;
name|QSqlError
name|lastError
argument_list|()
specifier|const
block|;
name|void
name|fetchMore
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
name|bool
name|canFetchMore
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|void
name|beginInsertRows
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|endInsertRows
argument_list|()
block|;
name|void
name|beginRemoveRows
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|endRemoveRows
argument_list|()
block|;
name|void
name|beginInsertColumns
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|endInsertColumns
argument_list|()
block|;
name|void
name|beginRemoveColumns
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|endRemoveColumns
argument_list|()
block|;
name|void
name|beginResetModel
argument_list|()
block|;
name|void
name|endResetModel
argument_list|()
block|;
name|virtual
name|void
name|queryChange
argument_list|()
block|;
name|virtual
name|QModelIndex
name|indexInQuery
argument_list|(
argument|const QModelIndex&item
argument_list|)
specifier|const
block|;
name|void
name|setLastError
argument_list|(
specifier|const
name|QSqlError
operator|&
name|error
argument_list|)
block|;
name|QSqlQueryModel
argument_list|(
name|QSqlQueryModelPrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|; }
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
comment|// QSQLQUERYMODEL_H
end_comment
end_unit
