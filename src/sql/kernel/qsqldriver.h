begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLDRIVER_H
end_ifndef
begin_define
DECL|macro|QSQLDRIVER_H
define|#
directive|define
name|QSQLDRIVER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsql.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QSqlDatabase
name|class
name|QSqlDatabase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlDriverPrivate
name|class
name|QSqlDriverPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlError
name|class
name|QSqlError
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlField
name|class
name|QSqlField
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlIndex
name|class
name|QSqlIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlRecord
name|class
name|QSqlRecord
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlResult
name|class
name|QSqlResult
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_SQL_EXPORT
name|QSqlDriver
range|:
name|public
name|QObject
block|{
name|friend
name|class
name|QSqlDatabase
block|;
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSqlDriver
argument_list|)
name|public
operator|:
expr|enum
name|DriverFeature
block|{
name|Transactions
block|,
name|QuerySize
block|,
name|BLOB
block|,
name|Unicode
block|,
name|PreparedQueries
block|,
name|NamedPlaceholders
block|,
name|PositionalPlaceholders
block|,
name|LastInsertId
block|,
name|BatchOperations
block|,
name|SimpleLocking
block|,
name|LowPrecisionNumbers
block|,
name|EventNotifications
block|,
name|FinishQuery
block|,
name|MultipleResultSets
block|}
block|;      enum
name|StatementType
block|{
name|WhereStatement
block|,
name|SelectStatement
block|,
name|UpdateStatement
block|,
name|InsertStatement
block|,
name|DeleteStatement
block|}
block|;      enum
name|IdentifierType
block|{
name|FieldName
block|,
name|TableName
block|}
block|;      enum
name|NotificationSource
block|{
name|UnknownSource
block|,
name|SelfSource
block|,
name|OtherSource
block|}
block|;
name|explicit
name|QSqlDriver
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QSqlDriver
argument_list|()
block|;
name|virtual
name|bool
name|isOpen
argument_list|()
specifier|const
block|;
name|bool
name|isOpenError
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|beginTransaction
argument_list|()
block|;
name|virtual
name|bool
name|commitTransaction
argument_list|()
block|;
name|virtual
name|bool
name|rollbackTransaction
argument_list|()
block|;
name|virtual
name|QStringList
name|tables
argument_list|(
argument|QSql::TableType tableType
argument_list|)
specifier|const
block|;
name|virtual
name|QSqlIndex
name|primaryIndex
argument_list|(
argument|const QString&tableName
argument_list|)
specifier|const
block|;
name|virtual
name|QSqlRecord
name|record
argument_list|(
argument|const QString&tableName
argument_list|)
specifier|const
block|;
name|virtual
name|QString
name|formatValue
argument_list|(
argument|const QSqlField& field
argument_list|,
argument|bool trimStrings = false
argument_list|)
specifier|const
block|;
name|virtual
name|QString
name|escapeIdentifier
argument_list|(
argument|const QString&identifier
argument_list|,
argument|IdentifierType type
argument_list|)
specifier|const
block|;
name|virtual
name|QString
name|sqlStatement
argument_list|(
argument|StatementType type
argument_list|,
argument|const QString&tableName
argument_list|,
argument|const QSqlRecord&rec
argument_list|,
argument|bool preparedStatement
argument_list|)
specifier|const
block|;
name|QSqlError
name|lastError
argument_list|()
specifier|const
block|;
name|virtual
name|QVariant
name|handle
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|hasFeature
argument_list|(
argument|DriverFeature f
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|close
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|QSqlResult
operator|*
name|createResult
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|open
argument_list|(
argument|const QString& db
argument_list|,
argument|const QString& user = QString()
argument_list|,
argument|const QString& password = QString()
argument_list|,
argument|const QString& host = QString()
argument_list|,
argument|int port = -
literal|1
argument_list|,
argument|const QString& connOpts = QString()
argument_list|)
operator|=
literal|0
block|;
name|bool
name|subscribeToNotification
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
comment|// ### Qt 5: make virtual
name|bool
name|unsubscribeFromNotification
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
comment|// ### Qt 5: make virtual
name|QStringList
name|subscribedToNotifications
argument_list|()
specifier|const
block|;
comment|// ### Qt 5: make virtual
name|bool
name|isIdentifierEscaped
argument_list|(
argument|const QString&identifier
argument_list|,
argument|IdentifierType type
argument_list|)
specifier|const
block|;
comment|// ### Qt 5: make virtual
name|QString
name|stripDelimiters
argument_list|(
argument|const QString&identifier
argument_list|,
argument|IdentifierType type
argument_list|)
specifier|const
block|;
comment|// ### Qt 5: make virtual
name|void
name|setNumericalPrecisionPolicy
argument_list|(
argument|QSql::NumericalPrecisionPolicy precisionPolicy
argument_list|)
block|;
name|QSql
operator|::
name|NumericalPrecisionPolicy
name|numericalPrecisionPolicy
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|notification
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|void
name|notification
argument_list|(
argument|const QString&name
argument_list|,
argument|NotificationSource source
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|setOpen
argument_list|(
argument|bool o
argument_list|)
block|;
name|virtual
name|void
name|setOpenError
argument_list|(
argument|bool e
argument_list|)
block|;
name|virtual
name|void
name|setLastError
argument_list|(
specifier|const
name|QSqlError
operator|&
name|e
argument_list|)
block|;
name|protected
name|Q_SLOTS
operator|:
name|bool
name|subscribeToNotificationImplementation
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
comment|// ### Qt 5: eliminate, see subscribeToNotification()
name|bool
name|unsubscribeFromNotificationImplementation
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
comment|// ### Qt 5: eliminate, see unsubscribeFromNotification()
name|QStringList
name|subscribedToNotificationsImplementation
argument_list|()
specifier|const
block|;
comment|// ### Qt 5: eliminate, see subscribedNotifications()
name|bool
name|isIdentifierEscapedImplementation
argument_list|(
argument|const QString&identifier
argument_list|,
argument|IdentifierType type
argument_list|)
specifier|const
block|;
comment|// ### Qt 5: eliminate, see isIdentifierEscaped()
name|QString
name|stripDelimitersImplementation
argument_list|(
argument|const QString&identifier
argument_list|,
argument|IdentifierType type
argument_list|)
specifier|const
block|;
comment|// ### Qt 5: eliminate, see stripDelimiters()
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QSqlDriver
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
comment|// QSQLDRIVER_H
end_comment
end_unit
