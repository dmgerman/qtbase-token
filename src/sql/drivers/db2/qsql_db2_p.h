begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQL_DB2_H
end_ifndef
begin_define
DECL|macro|QSQL_DB2_H
define|#
directive|define
name|QSQL_DB2_H
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
file|<QtCore/qglobal.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_PLUGIN
end_ifdef
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_DB2
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_DB2
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_DB2
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_DB2
value|Q_SQL_EXPORT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtSql/qsqldriver.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDB2DriverPrivate
name|class
name|QDB2DriverPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_EXPORT_SQLDRIVER_DB2
name|QDB2Driver
range|:
name|public
name|QSqlDriver
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDB2Driver
argument_list|)
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QDB2Driver
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QDB2Driver
argument_list|(
argument|Qt::HANDLE env
argument_list|,
argument|Qt::HANDLE con
argument_list|,
argument|QObject* parent =
literal|0
argument_list|)
block|;
operator|~
name|QDB2Driver
argument_list|()
block|;
name|bool
name|hasFeature
argument_list|(
argument|DriverFeature
argument_list|)
specifier|const
block|;
name|void
name|close
argument_list|()
block|;
name|QSqlRecord
name|record
argument_list|(
argument|const QString& tableName
argument_list|)
specifier|const
block|;
name|QStringList
name|tables
argument_list|(
argument|QSql::TableType type
argument_list|)
specifier|const
block|;
name|QSqlResult
operator|*
name|createResult
argument_list|()
specifier|const
block|;
name|QSqlIndex
name|primaryIndex
argument_list|(
argument|const QString& tablename
argument_list|)
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
name|private
operator|:
name|bool
name|setAutoCommit
argument_list|(
argument|bool autoCommit
argument_list|)
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
comment|// QSQL_DB2_H
end_comment
end_unit
