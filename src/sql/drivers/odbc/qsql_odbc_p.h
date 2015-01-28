begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQL_ODBC_H
end_ifndef
begin_define
DECL|macro|QSQL_ODBC_H
define|#
directive|define
name|QSQL_ODBC_H
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
begin_ifdef
ifdef|#
directive|ifdef
name|QT_PLUGIN
end_ifdef
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_ODBC
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_ODBC
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_ODBC
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_ODBC
value|Q_SQL_EXPORT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_define
DECL|macro|HAVE_LONG_LONG
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define
begin_comment
DECL|macro|HAVE_LONG_LONG
comment|// force UnixODBC NOT to fall back to a struct for BIGINTs
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_BOR
argument_list|)
end_if
begin_comment
comment|// workaround for Borland to make sure that SQLBIGINT is defined
end_comment
begin_define
DECL|macro|_MSC_VER
define|#
directive|define
name|_MSC_VER
value|900
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<sql.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_BOR
argument_list|)
end_if
begin_undef
DECL|macro|_MSC_VER
undef|#
directive|undef
name|_MSC_VER
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<sqlext.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QODBCPrivate
name|class
name|QODBCPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QODBCDriverPrivate
name|class
name|QODBCDriverPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QODBCDriver
name|class
name|QODBCDriver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlRecordInfo
name|class
name|QSqlRecordInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QODBCResult
range|:
name|public
name|QSqlResult
block|{
name|public
operator|:
name|QODBCResult
argument_list|(
specifier|const
name|QODBCDriver
operator|*
name|db
argument_list|,
name|QODBCDriverPrivate
operator|*
name|p
argument_list|)
block|;
name|virtual
operator|~
name|QODBCResult
argument_list|()
block|;
name|bool
name|prepare
argument_list|(
specifier|const
name|QString
operator|&
name|query
argument_list|)
block|;
name|bool
name|exec
argument_list|()
block|;
name|QVariant
name|lastInsertId
argument_list|()
specifier|const
block|;
name|QVariant
name|handle
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setForwardOnly
argument_list|(
argument|bool forward
argument_list|)
block|;
name|protected
operator|:
name|bool
name|fetchNext
argument_list|()
block|;
name|bool
name|fetchFirst
argument_list|()
block|;
name|bool
name|fetchLast
argument_list|()
block|;
name|bool
name|fetchPrevious
argument_list|()
block|;
name|bool
name|fetch
argument_list|(
argument|int i
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
name|QVariant
name|data
argument_list|(
argument|int field
argument_list|)
block|;
name|bool
name|isNull
argument_list|(
argument|int field
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
name|void
name|detachFromResultSet
argument_list|()
block|;
name|bool
name|nextResult
argument_list|()
block|;
name|private
operator|:
name|QODBCPrivate
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_EXPORT_SQLDRIVER_ODBC
name|QODBCDriver
range|:
name|public
name|QSqlDriver
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QODBCDriver
argument_list|)
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QODBCDriver
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QODBCDriver
argument_list|(
argument|SQLHANDLE env
argument_list|,
argument|SQLHANDLE con
argument_list|,
argument|QObject * parent=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QODBCDriver
argument_list|()
block|;
name|bool
name|hasFeature
argument_list|(
argument|DriverFeature f
argument_list|)
specifier|const
block|;
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
argument|const QString& tablename
argument_list|)
specifier|const
block|;
name|QVariant
name|handle
argument_list|()
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
name|QString
name|escapeIdentifier
argument_list|(
argument|const QString&identifier
argument_list|,
argument|IdentifierType type
argument_list|)
specifier|const
block|;
name|bool
name|isIdentifierEscaped
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
name|bool
name|endTrans
argument_list|()
block|;
name|void
name|cleanup
argument_list|()
block|;
name|friend
name|class
name|QODBCPrivate
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
comment|// QSQL_ODBC_H
end_comment
end_unit
