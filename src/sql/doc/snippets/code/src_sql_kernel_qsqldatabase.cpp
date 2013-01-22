begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|// WRONG
end_comment
begin_decl_stmt
DECL|variable|db
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
literal|"sales"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSqlQuery
name|query
argument_list|(
literal|"SELECT NAME, DOB FROM EMPLOYEES"
argument_list|,
name|db
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QSqlDatabase
operator|::
name|removeDatabase
argument_list|(
literal|"sales"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// will output a warning
end_comment
begin_comment
comment|// "db" is now a dangling invalid database connection,
end_comment
begin_comment
comment|// "query" contains an invalid result set
end_comment
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_block
block|{
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
literal|"sales"
argument_list|)
decl_stmt|;
name|QSqlQuery
name|query
argument_list|(
literal|"SELECT NAME, DOB FROM EMPLOYEES"
argument_list|,
name|db
argument_list|)
decl_stmt|;
block|}
end_block
begin_comment
comment|// Both "db" and "query" are destroyed because they are out of scope
end_comment
begin_expr_stmt
name|QSqlDatabase
operator|::
name|removeDatabase
argument_list|(
literal|"sales"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// correct
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_expr_stmt
name|QSqlDatabase
operator|::
name|registerSqlDriver
argument_list|(
literal|"MYDRIVER"
argument_list|,
operator|new
name|QSqlDriverCreator
argument_list|<
name|MyDatabaseDriver
argument_list|>
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|db
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|addDatabase
argument_list|(
literal|"MYDRIVER"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_expr_stmt
operator|...
name|db
operator|=
name|QSqlDatabase
operator|::
name|addDatabase
argument_list|(
literal|"QODBC"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|db
operator|.
name|setDatabaseName
argument_list|(
literal|"DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=myaccessfile.mdb"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|db
operator|.
name|open
argument_list|()
condition|)
block|{
comment|// success!
block|}
end_if
begin_expr_stmt
operator|...
comment|//! [3]
comment|//! [4]
operator|...
comment|// MySQL connection
name|db
operator|.
name|setConnectOptions
argument_list|(
literal|"CLIENT_SSL=1;CLIENT_IGNORE_SPACE=1"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// use an SSL connection to the server
end_comment
begin_if
if|if
condition|(
operator|!
name|db
operator|.
name|open
argument_list|()
condition|)
block|{
name|db
operator|.
name|setConnectOptions
argument_list|()
expr_stmt|;
comment|// clears the connect option string
operator|...
block|}
end_if
begin_expr_stmt
operator|...
comment|// PostgreSQL connection
name|db
operator|.
name|setConnectOptions
argument_list|(
literal|"requiressl=1"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// enable PostgreSQL SSL connections
end_comment
begin_if
if|if
condition|(
operator|!
name|db
operator|.
name|open
argument_list|()
condition|)
block|{
name|db
operator|.
name|setConnectOptions
argument_list|()
expr_stmt|;
comment|// clear options
operator|...
block|}
end_if
begin_expr_stmt
operator|...
comment|// ODBC connection
name|db
operator|.
name|setConnectOptions
argument_list|(
literal|"SQL_ATTR_ACCESS_MODE=SQL_MODE_READ_ONLY;SQL_ATTR_TRACE=SQL_OPT_TRACE_ON"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// set ODBC options
end_comment
begin_if
if|if
condition|(
operator|!
name|db
operator|.
name|open
argument_list|()
condition|)
block|{
name|db
operator|.
name|setConnectOptions
argument_list|()
expr_stmt|;
comment|// don't try to set this option
operator|...
block|}
end_if
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_include
include|#
directive|include
file|"qtdir/src/sql/drivers/psql/qsql_psql.cpp"
end_include
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
DECL|variable|con
name|PGconn
modifier|*
name|con
init|=
name|PQconnectdb
argument_list|(
literal|"host=server user=bart password=simpson dbname=springfield"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|drv
name|QPSQLDriver
modifier|*
name|drv
init|=
operator|new
name|QPSQLDriver
argument_list|(
name|con
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|db
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|addDatabase
argument_list|(
name|drv
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|db
comment|// becomes the new default connection
end_comment
begin_decl_stmt
DECL|variable|query
name|QSqlQuery
name|query
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|query
operator|.
name|exec
argument_list|(
literal|"SELECT NAME, ID FROM STAFF"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|...
comment|//! [6]
comment|//! [7]
name|unix
operator|:
name|LIBS
operator|+=
operator|-
name|lpq
name|win32
operator|:
name|LIBS
operator|+=
name|libpqdll
operator|.
name|lib
comment|//! [7]
comment|//! [8]
name|QSqlDatabase
name|db
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
name|db
operator|.
name|isValid
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns false
end_comment
begin_expr_stmt
name|db
operator|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
literal|"sales"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
name|db
operator|.
name|isValid
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns true if "sales" connection exists
end_comment
begin_expr_stmt
name|QSqlDatabase
operator|::
name|removeDatabase
argument_list|(
literal|"sales"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
name|db
operator|.
name|isValid
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns false
end_comment
begin_comment
comment|//! [8]
end_comment
end_unit
