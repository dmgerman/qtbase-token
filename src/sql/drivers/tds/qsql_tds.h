begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQL_TDS_H
end_ifndef
begin_define
DECL|macro|QSQL_TDS_H
define|#
directive|define
name|QSQL_TDS_H
end_define
begin_include
include|#
directive|include
file|<QtSql/qsqlresult.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsqldriver.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/private/qsqlcachedresult_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN32
end_ifdef
begin_define
DECL|macro|WIN32_LEAN_AND_MEAN
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|Q_USE_SYBASE
end_ifndef
begin_define
DECL|macro|DBNTWIN32
define|#
directive|define
name|DBNTWIN32
end_define
begin_comment
DECL|macro|DBNTWIN32
comment|// indicates 32bit windows dblib
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<winsock2.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<sqlfront.h>
end_include
begin_include
include|#
directive|include
file|<sqldb.h>
end_include
begin_define
DECL|macro|CS_PUBLIC
define|#
directive|define
name|CS_PUBLIC
end_define
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<sybfront.h>
end_include
begin_include
include|#
directive|include
file|<sybdb.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//Q_OS_WIN32
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_PLUGIN
end_ifdef
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_TDS
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_TDS
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_TDS
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_TDS
value|Q_SQL_EXPORT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QTDSDriverPrivate
name|class
name|QTDSDriverPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTDSResultPrivate
name|class
name|QTDSResultPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTDSDriver
name|class
name|QTDSDriver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTDSResult
range|:
name|public
name|QSqlCachedResult
block|{
name|public
operator|:
name|explicit
name|QTDSResult
argument_list|(
specifier|const
name|QTDSDriver
operator|*
name|db
argument_list|)
block|;
operator|~
name|QTDSResult
argument_list|()
block|;
name|QVariant
name|handle
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|void
name|cleanup
argument_list|()
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
name|bool
name|gotoNext
argument_list|(
argument|QSqlCachedResult::ValueCache&values
argument_list|,
argument|int index
argument_list|)
block|;
name|QSqlRecord
name|record
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QTDSResultPrivate
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_EXPORT_SQLDRIVER_TDS
name|QTDSDriver
range|:
name|public
name|QSqlDriver
block|{
name|Q_OBJECT
name|friend
name|class
name|QTDSResult
block|;
name|public
operator|:
name|explicit
name|QTDSDriver
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QTDSDriver
argument_list|(
name|LOGINREC
operator|*
name|rec
argument_list|,
specifier|const
name|QString
operator|&
name|host
argument_list|,
specifier|const
name|QString
operator|&
name|db
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QTDSDriver
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
name|void
name|close
argument_list|()
block|;
name|QStringList
name|tables
argument_list|(
argument|QSql::TableType
argument_list|)
specifier|const
block|;
name|QSqlResult
operator|*
name|createResult
argument_list|()
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
argument|const QString& tablename
argument_list|)
specifier|const
block|;
name|QString
name|formatValue
argument_list|(
argument|const QSqlField&field
argument_list|,
argument|bool trimStrings
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
argument|IdentifierType type
argument_list|)
specifier|const
block|;
name|protected
operator|:
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
name|private
operator|:
name|void
name|init
argument_list|()
block|;
name|QTDSDriverPrivate
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
comment|// QSQL_TDS_H
end_comment
end_unit
