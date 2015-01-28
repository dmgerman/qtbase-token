begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQL_SQLITE_H
end_ifndef
begin_define
DECL|macro|QSQL_SQLITE_H
define|#
directive|define
name|QSQL_SQLITE_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtSql/qsqldriver.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsqlresult.h>
end_include
begin_struct_decl
struct_decl|struct
name|sqlite3
struct_decl|;
end_struct_decl
begin_ifdef
ifdef|#
directive|ifdef
name|QT_PLUGIN
end_ifdef
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_SQLITE
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_SQLITE
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_SQLITE
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_SQLITE
value|Q_SQL_EXPORT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSQLiteDriverPrivate
name|class
name|QSQLiteDriverPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSQLiteDriver
name|class
name|QSQLiteDriver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_EXPORT_SQLDRIVER_SQLITE
name|QSQLiteDriver
range|:
name|public
name|QSqlDriver
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSQLiteDriver
argument_list|)
name|Q_OBJECT
name|friend
name|class
name|QSQLiteResult
block|;
name|public
operator|:
name|explicit
name|QSQLiteDriver
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QSQLiteDriver
argument_list|(
name|sqlite3
operator|*
name|connection
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QSQLiteDriver
argument_list|()
block|;
name|bool
name|hasFeature
argument_list|(
argument|DriverFeature f
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|open
argument_list|(
argument|const QString& db
argument_list|,
argument|const QString& user
argument_list|,
argument|const QString& password
argument_list|,
argument|const QString& host
argument_list|,
argument|int port
argument_list|,
argument|const QString& connOpts
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|close
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QSqlResult
operator|*
name|createResult
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|beginTransaction
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|commitTransaction
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|rollbackTransaction
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QStringList
name|tables
argument_list|(
argument|QSql::TableType
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSqlRecord
name|record
argument_list|(
argument|const QString& tablename
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSqlIndex
name|primaryIndex
argument_list|(
argument|const QString&table
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|handle
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|escapeIdentifier
argument_list|(
argument|const QString&identifier
argument_list|,
argument|IdentifierType
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|; }
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
comment|// QSQL_SQLITE_H
end_comment
end_unit
