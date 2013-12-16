begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsqlerror.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QSqlError
modifier|&
name|s
parameter_list|)
block|{
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QSqlError("
operator|<<
name|s
operator|.
name|nativeErrorCode
argument_list|()
operator|<<
literal|", "
operator|<<
name|s
operator|.
name|driverText
argument_list|()
operator|<<
literal|", "
operator|<<
name|s
operator|.
name|databaseText
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|dbg
operator|.
name|space
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|QSqlErrorPrivate
class|class
name|QSqlErrorPrivate
block|{
public|public:
DECL|member|driverError
name|QString
name|driverError
decl_stmt|;
DECL|member|databaseError
name|QString
name|databaseError
decl_stmt|;
DECL|member|errorType
name|QSqlError
operator|::
name|ErrorType
name|errorType
decl_stmt|;
DECL|member|errorCode
name|QString
name|errorCode
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QSqlError     \brief The QSqlError class provides SQL database error information.      \ingroup database     \inmodule QtSql      A QSqlError object can provide database-specific error data,     including the driverText() and databaseText() messages (or both     concatenated together as text()), and the nativeErrorCode() and     type().      \sa QSqlDatabase::lastError(), QSqlQuery::lastError() */
end_comment
begin_comment
comment|/*!     \enum QSqlError::ErrorType      This enum type describes the context in which the error occurred, e.g., a connection error, a statement error, etc.      \value NoError  No error occurred.     \value ConnectionError  Connection error.     \value StatementError  SQL statement syntax error.     \value TransactionError  Transaction failed error.     \value UnknownError  Unknown error. */
end_comment
begin_comment
comment|/*!     \obsolete      Constructs an error containing the driver error text \a     driverText, the database-specific error text \a databaseText, the     type \a type and the optional error number \a number. */
end_comment
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|3
argument_list|)
end_if
begin_constructor
DECL|function|QSqlError
name|QSqlError
operator|::
name|QSqlError
parameter_list|(
specifier|const
name|QString
modifier|&
name|driverText
parameter_list|,
specifier|const
name|QString
modifier|&
name|databaseText
parameter_list|,
name|ErrorType
name|type
parameter_list|,
name|int
name|number
parameter_list|)
block|{
name|d
operator|=
operator|new
name|QSqlErrorPrivate
expr_stmt|;
name|d
operator|->
name|driverError
operator|=
name|driverText
expr_stmt|;
name|d
operator|->
name|databaseError
operator|=
name|databaseText
expr_stmt|;
name|d
operator|->
name|errorType
operator|=
name|type
expr_stmt|;
name|d
operator|->
name|errorCode
operator|=
name|QString
operator|::
name|number
argument_list|(
name|number
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Constructs an error containing the driver error text \a     driverText, the database-specific error text \a databaseText, the     type \a type and the error code \a code. */
end_comment
begin_constructor
DECL|function|QSqlError
name|QSqlError
operator|::
name|QSqlError
parameter_list|(
specifier|const
name|QString
modifier|&
name|driverText
parameter_list|,
specifier|const
name|QString
modifier|&
name|databaseText
parameter_list|,
name|ErrorType
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|code
parameter_list|)
block|{
name|d
operator|=
operator|new
name|QSqlErrorPrivate
expr_stmt|;
name|d
operator|->
name|driverError
operator|=
name|driverText
expr_stmt|;
name|d
operator|->
name|databaseError
operator|=
name|databaseText
expr_stmt|;
name|d
operator|->
name|errorType
operator|=
name|type
expr_stmt|;
name|d
operator|->
name|errorCode
operator|=
name|code
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Creates a copy of \a other. */
end_comment
begin_constructor
DECL|function|QSqlError
name|QSqlError
operator|::
name|QSqlError
parameter_list|(
specifier|const
name|QSqlError
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
operator|new
name|QSqlErrorPrivate
expr_stmt|;
operator|*
name|d
operator|=
operator|*
name|other
operator|.
name|d
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Assigns the \a other error's values to this error. */
end_comment
begin_function
DECL|function|operator =
name|QSqlError
modifier|&
name|QSqlError
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QSqlError
modifier|&
name|other
parameter_list|)
block|{
operator|*
name|d
operator|=
operator|*
name|other
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Compare the \a other error's values to this error and returns \c true, if it equal. */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QSqlError
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QSqlError
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|d
operator|->
name|errorType
operator|==
name|other
operator|.
name|d
operator|->
name|errorType
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Compare the \a other error's values to this error and returns \c true if it is not equal. */
end_comment
begin_function
DECL|function|operator !=
name|bool
name|QSqlError
operator|::
name|operator
name|!=
parameter_list|(
specifier|const
name|QSqlError
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|d
operator|->
name|errorType
operator|!=
name|other
operator|.
name|d
operator|->
name|errorType
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Destroys the object and frees any allocated resources. */
end_comment
begin_destructor
DECL|function|~QSqlError
name|QSqlError
operator|::
name|~
name|QSqlError
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns the text of the error as reported by the driver. This may     contain database-specific descriptions. It may also be empty.      \sa databaseText(), text() */
end_comment
begin_function
DECL|function|driverText
name|QString
name|QSqlError
operator|::
name|driverText
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|driverError
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QSqlError::setDriverText(const QString&driverText)     \obsolete      Sets the driver error text to the value of \a driverText.      Use QSqlError(const QString&driverText, const QString&databaseText,                   ErrorType type, int number) instead      \sa driverText(), setDatabaseText(), text() */
end_comment
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|1
argument_list|)
end_if
begin_function
DECL|function|setDriverText
name|void
name|QSqlError
operator|::
name|setDriverText
parameter_list|(
specifier|const
name|QString
modifier|&
name|driverText
parameter_list|)
block|{
name|d
operator|->
name|driverError
operator|=
name|driverText
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Returns the text of the error as reported by the database. This     may contain database-specific descriptions; it may be empty.      \sa driverText(), text() */
end_comment
begin_function
DECL|function|databaseText
name|QString
name|QSqlError
operator|::
name|databaseText
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|databaseError
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QSqlError::setDatabaseText(const QString&databaseText)     \obsolete      Sets the database error text to the value of \a databaseText.      Use QSqlError(const QString&driverText, const QString&databaseText,                   ErrorType type, int number) instead      \sa databaseText(), setDriverText(), text() */
end_comment
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|1
argument_list|)
end_if
begin_function
DECL|function|setDatabaseText
name|void
name|QSqlError
operator|::
name|setDatabaseText
parameter_list|(
specifier|const
name|QString
modifier|&
name|databaseText
parameter_list|)
block|{
name|d
operator|->
name|databaseError
operator|=
name|databaseText
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Returns the error type, or -1 if the type cannot be determined. */
end_comment
begin_function
DECL|function|type
name|QSqlError
operator|::
name|ErrorType
name|QSqlError
operator|::
name|type
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|errorType
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QSqlError::setType(ErrorType type)     \obsolete      Sets the error type to the value of \a type.      Use QSqlError(const QString&driverText, const QString&databaseText,                   ErrorType type, int number) instead      \sa type() */
end_comment
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|1
argument_list|)
end_if
begin_function
DECL|function|setType
name|void
name|QSqlError
operator|::
name|setType
parameter_list|(
name|ErrorType
name|type
parameter_list|)
block|{
name|d
operator|->
name|errorType
operator|=
name|type
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \fn int QSqlError::number() const     \obsolete      Returns the database-specific error number, or -1 if it cannot be     determined.      Returns 0 if the error code is not an integer.      \warning Some databases use alphanumeric error codes, which makes              number() unreliable if such a database is used.      Use nativeErrorCode() instead      \sa nativeErrorCode() */
end_comment
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|3
argument_list|)
end_if
begin_function
DECL|function|number
name|int
name|QSqlError
operator|::
name|number
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|errorCode
operator|.
name|toInt
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \fn void QSqlError::setNumber(int number)     \obsolete      Sets the database-specific error number to \a number.      Use QSqlError(const QString&driverText, const QString&databaseText,                   ErrorType type, int number) instead      \sa number() */
end_comment
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|1
argument_list|)
end_if
begin_function
DECL|function|setNumber
name|void
name|QSqlError
operator|::
name|setNumber
parameter_list|(
name|int
name|number
parameter_list|)
block|{
name|d
operator|->
name|errorCode
operator|=
name|QString
operator|::
name|number
argument_list|(
name|number
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Returns the database-specific error code, or an empty string if     it cannot be determined. */
end_comment
begin_function
DECL|function|nativeErrorCode
name|QString
name|QSqlError
operator|::
name|nativeErrorCode
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|errorCode
return|;
block|}
end_function
begin_comment
comment|/*!     This is a convenience function that returns databaseText() and     driverText() concatenated into a single string.      \sa driverText(), databaseText() */
end_comment
begin_function
DECL|function|text
name|QString
name|QSqlError
operator|::
name|text
parameter_list|()
specifier|const
block|{
name|QString
name|result
init|=
name|d
operator|->
name|databaseError
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|databaseError
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"\n"
argument_list|)
argument_list|)
condition|)
name|result
operator|+=
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|result
operator|+=
name|d
operator|->
name|driverError
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if an error is set, otherwise false.      Example:     \snippet code/src_sql_kernel_qsqlerror.cpp 0      \sa type() */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QSqlError
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|errorType
operator|!=
name|NoError
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
