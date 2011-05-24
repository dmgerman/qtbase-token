begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQL_SQLITE2_H
end_ifndef
begin_define
DECL|macro|QSQL_SQLITE2_H
define|#
directive|define
name|QSQL_SQLITE2_H
end_define
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
begin_include
include|#
directive|include
file|<QtSql/qsqlrecord.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsqlindex.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/private/qsqlcachedresult_p.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_struct_decl
struct_decl|struct
name|sqlite
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QSQLite2DriverPrivate
name|class
name|QSQLite2DriverPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSQLite2ResultPrivate
name|class
name|QSQLite2ResultPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSQLite2Driver
name|class
name|QSQLite2Driver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QSQLite2Result
range|:
name|public
name|QSqlCachedResult
block|{
name|friend
name|class
name|QSQLite2Driver
block|;
name|friend
name|class
name|QSQLite2ResultPrivate
block|;
name|public
operator|:
name|explicit
name|QSQLite2Result
argument_list|(
specifier|const
name|QSQLite2Driver
operator|*
name|db
argument_list|)
block|;
operator|~
name|QSQLite2Result
argument_list|()
block|;
name|QVariant
name|handle
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|bool
name|gotoNext
argument_list|(
argument|QSqlCachedResult::ValueCache& row
argument_list|,
argument|int idx
argument_list|)
block|;
name|bool
name|reset
argument_list|(
specifier|const
name|QString
operator|&
name|query
argument_list|)
block|;
name|int
name|size
argument_list|()
block|;
name|int
name|numRowsAffected
argument_list|()
block|;
name|QSqlRecord
name|record
argument_list|()
specifier|const
block|;
name|void
name|virtual_hook
argument_list|(
argument|int id
argument_list|,
argument|void *data
argument_list|)
block|;
name|private
operator|:
name|QSQLite2ResultPrivate
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QSQLite2Driver
range|:
name|public
name|QSqlDriver
block|{
name|Q_OBJECT
name|friend
name|class
name|QSQLite2Result
block|;
name|public
operator|:
name|explicit
name|QSQLite2Driver
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QSQLite2Driver
argument_list|(
name|sqlite
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
name|QSQLite2Driver
argument_list|()
block|;
name|bool
name|hasFeature
argument_list|(
argument|DriverFeature f
argument_list|)
specifier|const
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
argument_list|)
block|{
return|return
name|open
argument_list|(
name|db
argument_list|,
name|user
argument_list|,
name|password
argument_list|,
name|host
argument_list|,
name|port
argument_list|,
name|QString
argument_list|()
argument_list|)
return|;
block|}
name|void
name|close
argument_list|()
block|;
name|QSqlResult
operator|*
name|createResult
argument_list|()
specifier|const
block|;
name|bool
name|beginTransaction
argument_list|()
block|;
name|bool
name|commitTransaction
argument_list|()
block|;
name|bool
name|rollbackTransaction
argument_list|()
block|;
name|QStringList
name|tables
argument_list|(
argument|QSql::TableType
argument_list|)
specifier|const
block|;
name|QSqlRecord
name|record
argument_list|(
argument|const QString& tablename
argument_list|)
specifier|const
block|;
name|QSqlIndex
name|primaryIndex
argument_list|(
argument|const QString&table
argument_list|)
specifier|const
block|;
name|QVariant
name|handle
argument_list|()
specifier|const
block|;
name|QString
name|escapeIdentifier
argument_list|(
argument|const QString&identifier
argument_list|,
argument|IdentifierType
argument_list|)
specifier|const
block|;
name|private
operator|:
name|QSQLite2DriverPrivate
operator|*
name|d
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
comment|// QSQL_SQLITE2_H
end_comment
end_unit
