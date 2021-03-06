begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLRELATIONALTABLEMODEL_H
end_ifndef
begin_define
DECL|macro|QSQLRELATIONALTABLEMODEL_H
define|#
directive|define
name|QSQLRELATIONALTABLEMODEL_H
end_define
begin_include
include|#
directive|include
file|<QtSql/qsqltablemodel.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_SQL_EXPORT
name|QSqlRelation
block|{
name|public
label|:
name|QSqlRelation
argument_list|()
block|{}
name|QSqlRelation
argument_list|(
specifier|const
name|QString
operator|&
name|aTableName
argument_list|,
specifier|const
name|QString
operator|&
name|indexCol
argument_list|,
specifier|const
name|QString
operator|&
name|displayCol
argument_list|)
operator|:
name|tName
argument_list|(
name|aTableName
argument_list|)
operator|,
name|iColumn
argument_list|(
name|indexCol
argument_list|)
operator|,
name|dColumn
argument_list|(
argument|displayCol
argument_list|)
block|{}
specifier|inline
name|QString
name|tableName
argument_list|()
specifier|const
block|{
return|return
name|tName
return|;
block|}
specifier|inline
name|QString
name|indexColumn
argument_list|()
specifier|const
block|{
return|return
name|iColumn
return|;
block|}
specifier|inline
name|QString
name|displayColumn
argument_list|()
specifier|const
block|{
return|return
name|dColumn
return|;
block|}
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|(
name|tName
operator|.
name|isEmpty
argument_list|()
operator|||
name|iColumn
operator|.
name|isEmpty
argument_list|()
operator|||
name|dColumn
operator|.
name|isEmpty
argument_list|()
operator|)
return|;
block|}
name|private
label|:
name|QString
name|tName
decl_stmt|,
name|iColumn
decl_stmt|,
name|dColumn
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QSqlRelationalTableModelPrivate
name|class
name|QSqlRelationalTableModelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_SQL_EXPORT
name|QSqlRelationalTableModel
range|:
name|public
name|QSqlTableModel
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|JoinMode
block|{
name|InnerJoin
block|,
name|LeftJoin
block|}
block|;
name|explicit
name|QSqlRelationalTableModel
argument_list|(
argument|QObject *parent = Q_NULLPTR
argument_list|,
argument|QSqlDatabase db = QSqlDatabase()
argument_list|)
block|;
name|virtual
operator|~
name|QSqlRelationalTableModel
argument_list|()
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&item
argument_list|,
argument|int role = Qt::DisplayRole
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|setData
argument_list|(
argument|const QModelIndex&item
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int role = Qt::EditRole
argument_list|)
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|void
name|clear
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|select
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|setTable
argument_list|(
argument|const QString&tableName
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|setRelation
argument_list|(
argument|int column
argument_list|,
argument|const QSqlRelation&relation
argument_list|)
block|;
name|QSqlRelation
name|relation
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|virtual
name|QSqlTableModel
operator|*
name|relationModel
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setJoinMode
argument_list|(
argument|QSqlRelationalTableModel::JoinMode joinMode
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|revertRow
argument_list|(
argument|int row
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|QString
name|selectStatement
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|updateRowInTable
argument_list|(
argument|int row
argument_list|,
argument|const QSqlRecord&values
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|insertRowIntoTable
argument_list|(
argument|const QSqlRecord&values
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QString
name|orderByClause
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSqlRelationalTableModel
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSQLRELATIONALTABLEMODEL_H
end_comment
end_unit
