begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|"../qsqldatabase/tst_databases.h"
end_include
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtSql>
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_decl_stmt
specifier|const
name|QString
name|qtest
argument_list|(
name|qTableName
argument_list|(
literal|"qtest"
argument_list|,
name|__FILE__
argument_list|,
name|QSqlDatabase
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// set this define if Oracle is built with threading support
end_comment
begin_comment
comment|//#define QOCI_THREADED
end_comment
begin_class
DECL|class|tst_QSqlThread
class|class
name|tst_QSqlThread
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QSqlThread
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QSqlThread
parameter_list|()
destructor_decl|;
name|void
name|dropTestTables
parameter_list|()
function_decl|;
name|void
name|createTestTables
parameter_list|()
function_decl|;
name|void
name|recreateTestTables
parameter_list|()
function_decl|;
name|void
name|repopulateTestTables
parameter_list|()
function_decl|;
name|void
name|generic_data
parameter_list|(
specifier|const
name|QString
modifier|&
name|engine
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
DECL|member|dbs
name|tst_Databases
name|dbs
decl_stmt|;
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
protected|protected
name|slots
protected|:
DECL|function|threadFinished
name|void
name|threadFinished
parameter_list|()
block|{
operator|++
name|threadFinishedCount
expr_stmt|;
block|}
private|private
name|slots
private|:
DECL|function|simpleThreading_data
name|void
name|simpleThreading_data
parameter_list|()
block|{
name|generic_data
argument_list|()
expr_stmt|;
block|}
name|void
name|simpleThreading
parameter_list|()
function_decl|;
DECL|function|readWriteThreading_data
name|void
name|readWriteThreading_data
parameter_list|()
block|{
name|generic_data
argument_list|()
expr_stmt|;
block|}
name|void
name|readWriteThreading
parameter_list|()
function_decl|;
DECL|function|readFromSingleConnection_data
name|void
name|readFromSingleConnection_data
parameter_list|()
block|{
name|generic_data
argument_list|()
expr_stmt|;
block|}
name|void
name|readFromSingleConnection
parameter_list|()
function_decl|;
DECL|function|readWriteFromSingleConnection_data
name|void
name|readWriteFromSingleConnection_data
parameter_list|()
block|{
name|generic_data
argument_list|()
expr_stmt|;
block|}
name|void
name|readWriteFromSingleConnection
parameter_list|()
function_decl|;
DECL|function|preparedReadWriteFromSingleConnection_data
name|void
name|preparedReadWriteFromSingleConnection_data
parameter_list|()
block|{
name|generic_data
argument_list|()
expr_stmt|;
block|}
name|void
name|preparedReadWriteFromSingleConnection
parameter_list|()
function_decl|;
DECL|function|transactionsFromSingleConnection_data
name|void
name|transactionsFromSingleConnection_data
parameter_list|()
block|{
name|generic_data
argument_list|()
expr_stmt|;
block|}
name|void
name|transactionsFromSingleConnection
parameter_list|()
function_decl|;
private|private:
DECL|member|threadFinishedCount
name|int
name|threadFinishedCount
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|counter
specifier|static
name|QAtomicInt
name|counter
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|QtTestSqlThread
class|class
name|QtTestSqlThread
super|:
specifier|public
name|QThread
block|{
name|Q_OBJECT
public|public:
DECL|function|QtTestSqlThread
name|QtTestSqlThread
parameter_list|(
specifier|const
name|QSqlDatabase
modifier|&
name|aDb
parameter_list|,
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|sourceDb
argument_list|(
name|aDb
argument_list|)
block|{}
DECL|function|runHelper
name|void
name|runHelper
parameter_list|(
specifier|const
name|QString
modifier|&
name|dbName
parameter_list|)
block|{
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|cloneDatabase
argument_list|(
name|sourceDb
argument_list|,
name|dbName
argument_list|)
decl_stmt|;
name|QVERIFY_SQL
argument_list|(
name|db
argument_list|,
name|open
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|sum
init|=
literal|0
decl_stmt|;
name|QSqlQuery
name|q
argument_list|(
literal|"select id from "
operator|+
name|qtest
argument_list|,
name|db
argument_list|)
decl_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|isActive
argument_list|()
argument_list|)
expr_stmt|;
while|while
condition|(
name|q
operator|.
name|next
argument_list|()
condition|)
name|sum
operator|+=
name|q
operator|.
name|value
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sum
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|q
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|QString
name|dbName
init|=
name|QString
argument_list|(
literal|"QThreadDb%1"
argument_list|)
operator|.
name|arg
argument_list|(
operator|(
name|size_t
operator|)
name|currentThreadId
argument_list|()
argument_list|)
decl_stmt|;
name|runHelper
argument_list|(
name|dbName
argument_list|)
expr_stmt|;
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbName
argument_list|)
operator|.
name|close
argument_list|()
expr_stmt|;
name|QSqlDatabase
operator|::
name|removeDatabase
argument_list|(
name|dbName
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|sourceDb
name|QSqlDatabase
name|sourceDb
decl_stmt|;
block|}
class|;
end_class
begin_enum
DECL|enumerator|ProdConIterations
enum|enum
block|{
name|ProdConIterations
init|=
literal|10
block|}
enum|;
end_enum
begin_class
DECL|class|SqlProducer
class|class
name|SqlProducer
super|:
specifier|public
name|QThread
block|{
name|Q_OBJECT
public|public:
DECL|function|SqlProducer
name|SqlProducer
parameter_list|(
specifier|const
name|QSqlDatabase
modifier|&
name|aDb
parameter_list|,
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|sourceDb
argument_list|(
name|aDb
argument_list|)
block|{}
DECL|function|runHelper
name|void
name|runHelper
parameter_list|(
specifier|const
name|QString
modifier|&
name|dbName
parameter_list|)
block|{
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|cloneDatabase
argument_list|(
name|sourceDb
argument_list|,
name|dbName
argument_list|)
decl_stmt|;
name|QVERIFY_SQL
argument_list|(
name|db
argument_list|,
name|open
argument_list|()
argument_list|)
expr_stmt|;
name|QSqlQuery
name|q
argument_list|(
name|db
argument_list|)
decl_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|prepare
argument_list|(
literal|"insert into "
operator|+
name|qtest
operator|+
literal|" values (?, ?, ?)"
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|id
init|=
literal|10
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ProdConIterations
condition|;
operator|++
name|i
control|)
block|{
name|q
operator|.
name|bindValue
argument_list|(
literal|0
argument_list|,
operator|++
name|id
argument_list|)
expr_stmt|;
name|q
operator|.
name|bindValue
argument_list|(
literal|1
argument_list|,
literal|"threaddy"
argument_list|)
expr_stmt|;
name|q
operator|.
name|bindValue
argument_list|(
literal|2
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|()
argument_list|)
expr_stmt|;
name|QThread
operator|::
name|yieldCurrentThread
argument_list|()
expr_stmt|;
block|}
block|}
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|QString
name|dbName
init|=
name|QString
argument_list|(
literal|"Producer%1"
argument_list|)
operator|.
name|arg
argument_list|(
operator|(
name|size_t
operator|)
name|currentThreadId
argument_list|()
argument_list|)
decl_stmt|;
name|runHelper
argument_list|(
name|dbName
argument_list|)
expr_stmt|;
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbName
argument_list|)
operator|.
name|close
argument_list|()
expr_stmt|;
name|QSqlDatabase
operator|::
name|removeDatabase
argument_list|(
name|dbName
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|sourceDb
name|QSqlDatabase
name|sourceDb
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|SqlConsumer
class|class
name|SqlConsumer
super|:
specifier|public
name|QThread
block|{
name|Q_OBJECT
public|public:
DECL|function|SqlConsumer
name|SqlConsumer
parameter_list|(
specifier|const
name|QSqlDatabase
modifier|&
name|aDb
parameter_list|,
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|sourceDb
argument_list|(
name|aDb
argument_list|)
block|{}
DECL|function|runHelper
name|void
name|runHelper
parameter_list|(
specifier|const
name|QString
modifier|&
name|dbName
parameter_list|)
block|{
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|cloneDatabase
argument_list|(
name|sourceDb
argument_list|,
name|dbName
argument_list|)
decl_stmt|;
name|QVERIFY_SQL
argument_list|(
name|db
argument_list|,
name|open
argument_list|()
argument_list|)
expr_stmt|;
name|QSqlQuery
name|q1
argument_list|(
name|db
argument_list|)
decl_stmt|,
name|q2
argument_list|(
name|db
argument_list|)
decl_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q2
argument_list|,
name|prepare
argument_list|(
literal|"delete from "
operator|+
name|qtest
operator|+
literal|" where id = :id"
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ProdConIterations
condition|;
operator|++
name|i
control|)
block|{
name|QVERIFY_SQL
argument_list|(
name|q1
argument_list|,
name|exec
argument_list|(
literal|"select max(id) from "
operator|+
name|qtest
argument_list|)
argument_list|)
expr_stmt|;
name|q1
operator|.
name|first
argument_list|()
expr_stmt|;
name|q2
operator|.
name|bindValue
argument_list|(
literal|"id"
argument_list|,
name|q1
operator|.
name|value
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|q1
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q2
argument_list|,
name|exec
argument_list|()
argument_list|)
expr_stmt|;
name|QThread
operator|::
name|yieldCurrentThread
argument_list|()
expr_stmt|;
block|}
block|}
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|QString
name|dbName
init|=
name|QString
argument_list|(
literal|"Consumer%1"
argument_list|)
operator|.
name|arg
argument_list|(
operator|(
name|size_t
operator|)
name|currentThreadId
argument_list|()
argument_list|)
decl_stmt|;
name|runHelper
argument_list|(
name|dbName
argument_list|)
expr_stmt|;
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbName
argument_list|)
operator|.
name|close
argument_list|()
expr_stmt|;
name|QSqlDatabase
operator|::
name|removeDatabase
argument_list|(
name|dbName
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|sourceDb
name|QSqlDatabase
name|sourceDb
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|SqlThread
class|class
name|SqlThread
super|:
specifier|public
name|QThread
block|{
name|Q_OBJECT
public|public:
DECL|enum|Mode
DECL|enumerator|SimpleReading
DECL|enumerator|PreparedReading
DECL|enumerator|SimpleWriting
DECL|enumerator|PreparedWriting
enum|enum
name|Mode
block|{
name|SimpleReading
block|,
name|PreparedReading
block|,
name|SimpleWriting
block|,
name|PreparedWriting
block|}
enum|;
DECL|function|SqlThread
name|SqlThread
parameter_list|(
name|Mode
name|m
parameter_list|,
specifier|const
name|QSqlDatabase
modifier|&
name|db
parameter_list|,
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|sourceDb
argument_list|(
name|db
argument_list|)
member_init_list|,
name|mode
argument_list|(
name|m
argument_list|)
block|{}
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|QSqlDatabase
modifier|&
name|db
init|=
name|sourceDb
decl_stmt|;
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|SimpleReading
case|:
block|{
comment|// Executes a Query for reading, iterates over the first 4 results
name|QSqlQuery
name|q
argument_list|(
name|sourceDb
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|ProdConIterations
condition|;
operator|++
name|j
control|)
block|{
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"select id,name from "
operator|+
name|qtest
operator|+
literal|" order by id"
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
block|{
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|next
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|q
operator|.
name|value
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
block|}
case|case
name|SimpleWriting
case|:
block|{
comment|// Executes a query for writing (appends a new row)
name|QSqlQuery
name|q
argument_list|(
name|sourceDb
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|ProdConIterations
condition|;
operator|++
name|j
control|)
block|{
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
name|QString
argument_list|(
literal|"insert into "
operator|+
name|qtest
operator|+
literal|" (id, name) values(%1, '%2')"
argument_list|)
operator|.
name|arg
argument_list|(
name|counter
operator|.
name|fetchAndAddRelaxed
argument_list|(
literal|1
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
literal|"Robert"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
case|case
name|PreparedReading
case|:
block|{
comment|// Prepares a query for reading and iterates over the results
name|QSqlQuery
name|q
argument_list|(
name|sourceDb
argument_list|)
decl_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|prepare
argument_list|(
literal|"select id, name from "
operator|+
name|qtest
operator|+
literal|" where id = ?"
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|ProdConIterations
condition|;
operator|++
name|j
control|)
block|{
name|q
operator|.
name|addBindValue
argument_list|(
name|j
operator|%
literal|3
operator|+
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|next
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|q
operator|.
name|value
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|j
operator|%
literal|3
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
case|case
name|PreparedWriting
case|:
block|{
name|QSqlQuery
name|q
argument_list|(
name|sourceDb
argument_list|)
decl_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|prepare
argument_list|(
literal|"insert into "
operator|+
name|qtest
operator|+
literal|" (id, name) "
literal|"values(?, ?)"
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ProdConIterations
condition|;
operator|++
name|i
control|)
block|{
name|q
operator|.
name|addBindValue
argument_list|(
name|counter
operator|.
name|fetchAndAddRelaxed
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|.
name|addBindValue
argument_list|(
literal|"Robert"
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|()
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
block|}
block|}
private|private:
DECL|member|sourceDb
name|QSqlDatabase
name|sourceDb
decl_stmt|;
DECL|member|mode
name|Mode
name|mode
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QSqlThread
name|tst_QSqlThread
operator|::
name|tst_QSqlThread
parameter_list|()
member_init_list|:
name|threadFinishedCount
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QSqlThread
name|tst_QSqlThread
operator|::
name|~
name|tst_QSqlThread
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|generic_data
name|void
name|tst_QSqlThread
operator|::
name|generic_data
parameter_list|(
specifier|const
name|QString
modifier|&
name|engine
parameter_list|)
block|{
if|if
condition|(
name|dbs
operator|.
name|fillTestTable
argument_list|(
name|engine
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|engine
operator|.
name|isEmpty
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"No database drivers are available in this Qt configuration"
argument_list|)
expr_stmt|;
else|else
name|QSKIP
argument_list|(
operator|(
name|QString
argument_list|(
literal|"No database drivers of type %1 are available in this Qt configuration"
argument_list|)
operator|.
name|arg
argument_list|(
name|engine
argument_list|)
operator|)
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|dropTestTables
name|void
name|tst_QSqlThread
operator|::
name|dropTestTables
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|dbs
operator|.
name|dbNames
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbs
operator|.
name|dbNames
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|QSqlQuery
name|q
argument_list|(
name|db
argument_list|)
decl_stmt|;
name|tst_Databases
operator|::
name|safeDropTables
argument_list|(
name|db
argument_list|,
name|QStringList
argument_list|()
operator|<<
name|qtest
operator|<<
name|qTableName
argument_list|(
literal|"qtest2"
argument_list|,
name|__FILE__
argument_list|,
name|db
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"emptytable"
argument_list|,
name|__FILE__
argument_list|,
name|db
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createTestTables
name|void
name|tst_QSqlThread
operator|::
name|createTestTables
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|dbs
operator|.
name|dbNames
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbs
operator|.
name|dbNames
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|QSqlQuery
name|q
argument_list|(
name|db
argument_list|)
decl_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"create table "
operator|+
name|qtest
operator|+
literal|"(id int NOT NULL primary key, name varchar(20), title int)"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"create table "
operator|+
name|qTableName
argument_list|(
literal|"qtest2"
argument_list|,
name|__FILE__
argument_list|,
name|db
argument_list|)
operator|+
literal|"(id int NOT NULL primary key, title varchar(20))"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"create table "
operator|+
name|qTableName
argument_list|(
literal|"emptytable"
argument_list|,
name|__FILE__
argument_list|,
name|db
argument_list|)
operator|+
literal|"(id int NOT NULL primary key)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|repopulateTestTables
name|void
name|tst_QSqlThread
operator|::
name|repopulateTestTables
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|dbs
operator|.
name|dbNames
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbs
operator|.
name|dbNames
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|QSqlQuery
name|q
argument_list|(
name|db
argument_list|)
decl_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"delete from "
operator|+
name|qtest
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"insert into "
operator|+
name|qtest
operator|+
literal|" values(1, 'harry', 1)"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"insert into "
operator|+
name|qtest
operator|+
literal|" values(2, 'trond', 2)"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"insert into "
operator|+
name|qtest
operator|+
literal|" values(3, 'vohi', 3)"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"delete from "
operator|+
name|qTableName
argument_list|(
literal|"qtest2"
argument_list|,
name|__FILE__
argument_list|,
name|db
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"insert into "
operator|+
name|qTableName
argument_list|(
literal|"qtest2"
argument_list|,
name|__FILE__
argument_list|,
name|db
argument_list|)
operator|+
literal|" values(1, 'herr')"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"insert into "
operator|+
name|qTableName
argument_list|(
literal|"qtest2"
argument_list|,
name|__FILE__
argument_list|,
name|db
argument_list|)
operator|+
literal|" values(2, 'mister')"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|recreateTestTables
name|void
name|tst_QSqlThread
operator|::
name|recreateTestTables
parameter_list|()
block|{
name|dropTestTables
argument_list|()
expr_stmt|;
name|createTestTables
argument_list|()
expr_stmt|;
name|repopulateTestTables
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initTestCase
name|void
name|tst_QSqlThread
operator|::
name|initTestCase
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|dbs
operator|.
name|open
argument_list|()
argument_list|)
expr_stmt|;
name|recreateTestTables
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QSqlThread
operator|::
name|cleanupTestCase
parameter_list|()
block|{
name|dropTestTables
argument_list|()
expr_stmt|;
name|dbs
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_QSqlThread
operator|::
name|init
parameter_list|()
block|{
name|threadFinishedCount
operator|=
literal|0
expr_stmt|;
name|counter
operator|.
name|store
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QSqlThread
operator|::
name|cleanup
parameter_list|()
block|{
comment|//     repopulateTestTables();
block|}
end_function
begin_comment
comment|// This test creates two threads that clone their db connection and read
end_comment
begin_comment
comment|// from it
end_comment
begin_function
DECL|function|simpleThreading
name|void
name|tst_QSqlThread
operator|::
name|simpleThreading
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|dbName
argument_list|)
expr_stmt|;
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbName
argument_list|)
decl_stmt|;
name|CHECK_DATABASE
argument_list|(
name|db
argument_list|)
expr_stmt|;
if|if
condition|(
name|db
operator|.
name|databaseName
argument_list|()
operator|==
literal|":memory:"
condition|)
name|QSKIP
argument_list|(
literal|"does not work with in-memory databases"
argument_list|)
expr_stmt|;
name|QtTestSqlThread
name|t1
argument_list|(
name|db
argument_list|)
decl_stmt|;
name|QtTestSqlThread
name|t2
argument_list|(
name|db
argument_list|)
decl_stmt|;
name|connect
argument_list|(
operator|&
name|t1
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|threadFinished
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|t2
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|threadFinished
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|t1
operator|.
name|start
argument_list|()
expr_stmt|;
name|t2
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|threadFinishedCount
operator|>=
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// This test creates two threads that clone their db connection and read
end_comment
begin_comment
comment|// or write
end_comment
begin_function
DECL|function|readWriteThreading
name|void
name|tst_QSqlThread
operator|::
name|readWriteThreading
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|dbName
argument_list|)
expr_stmt|;
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbName
argument_list|)
decl_stmt|;
name|CHECK_DATABASE
argument_list|(
name|db
argument_list|)
expr_stmt|;
if|if
condition|(
name|db
operator|.
name|databaseName
argument_list|()
operator|==
literal|":memory:"
condition|)
name|QSKIP
argument_list|(
literal|"does not work with in-memory databases"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|tst_Databases
operator|::
name|isMSAccess
argument_list|(
name|db
argument_list|)
condition|)
name|QSKIP
argument_list|(
literal|"does not work with MS Access databases"
argument_list|)
expr_stmt|;
name|SqlProducer
name|producer
argument_list|(
name|db
argument_list|)
decl_stmt|;
name|SqlConsumer
name|consumer
argument_list|(
name|db
argument_list|)
decl_stmt|;
name|connect
argument_list|(
operator|&
name|producer
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|threadFinished
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|consumer
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|threadFinished
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|producer
operator|.
name|start
argument_list|()
expr_stmt|;
name|consumer
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|threadFinishedCount
operator|>=
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// run with n threads in parallel. Change this constant to hammer the poor DB server even more
end_comment
begin_decl_stmt
DECL|variable|maxThreadCount
specifier|static
specifier|const
name|int
name|maxThreadCount
init|=
literal|4
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|readFromSingleConnection
name|void
name|tst_QSqlThread
operator|::
name|readFromSingleConnection
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QOCI_THREADED
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|dbName
argument_list|)
expr_stmt|;
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbName
argument_list|)
decl_stmt|;
name|CHECK_DATABASE
argument_list|(
name|db
argument_list|)
expr_stmt|;
if|if
condition|(
name|db
operator|.
name|databaseName
argument_list|()
operator|==
literal|":memory:"
condition|)
name|QSKIP
argument_list|(
literal|"does not work with in-memory databases"
argument_list|)
expr_stmt|;
name|QObject
name|cleanupHelper
decl_stmt|;
comment|// make sure the threads die when we exit the scope
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|maxThreadCount
condition|;
operator|++
name|i
control|)
block|{
name|SqlThread
modifier|*
name|reader
init|=
operator|new
name|SqlThread
argument_list|(
name|SqlThread
operator|::
name|SimpleReading
argument_list|,
name|db
argument_list|,
operator|&
name|cleanupHelper
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|reader
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|threadFinished
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|reader
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
name|QTRY_VERIFY
argument_list|(
name|threadFinishedCount
operator|>=
name|maxThreadCount
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|readWriteFromSingleConnection
name|void
name|tst_QSqlThread
operator|::
name|readWriteFromSingleConnection
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QOCI_THREADED
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|dbName
argument_list|)
expr_stmt|;
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbName
argument_list|)
decl_stmt|;
name|CHECK_DATABASE
argument_list|(
name|db
argument_list|)
expr_stmt|;
if|if
condition|(
name|db
operator|.
name|databaseName
argument_list|()
operator|==
literal|":memory:"
condition|)
name|QSKIP
argument_list|(
literal|"does not work with in-memory databases"
argument_list|)
expr_stmt|;
name|QObject
name|cleanupHelper
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|maxThreadCount
condition|;
operator|++
name|i
control|)
block|{
name|SqlThread
modifier|*
name|reader
init|=
operator|new
name|SqlThread
argument_list|(
name|SqlThread
operator|::
name|SimpleReading
argument_list|,
name|db
argument_list|,
operator|&
name|cleanupHelper
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|reader
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|threadFinished
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|reader
operator|->
name|start
argument_list|()
expr_stmt|;
name|SqlThread
modifier|*
name|writer
init|=
operator|new
name|SqlThread
argument_list|(
name|SqlThread
operator|::
name|SimpleWriting
argument_list|,
name|db
argument_list|,
operator|&
name|cleanupHelper
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|writer
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|threadFinished
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|writer
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
name|QTRY_VERIFY
argument_list|(
name|threadFinishedCount
operator|>=
name|maxThreadCount
operator|*
literal|2
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|preparedReadWriteFromSingleConnection
name|void
name|tst_QSqlThread
operator|::
name|preparedReadWriteFromSingleConnection
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QOCI_THREADED
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|dbName
argument_list|)
expr_stmt|;
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbName
argument_list|)
decl_stmt|;
name|CHECK_DATABASE
argument_list|(
name|db
argument_list|)
expr_stmt|;
if|if
condition|(
name|db
operator|.
name|databaseName
argument_list|()
operator|==
literal|":memory:"
condition|)
name|QSKIP
argument_list|(
literal|"does not work with in-memory databases"
argument_list|)
expr_stmt|;
name|QObject
name|cleanupHelper
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|maxThreadCount
condition|;
operator|++
name|i
control|)
block|{
name|SqlThread
modifier|*
name|reader
init|=
operator|new
name|SqlThread
argument_list|(
name|SqlThread
operator|::
name|PreparedReading
argument_list|,
name|db
argument_list|,
operator|&
name|cleanupHelper
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|reader
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|threadFinished
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|reader
operator|->
name|start
argument_list|()
expr_stmt|;
name|SqlThread
modifier|*
name|writer
init|=
operator|new
name|SqlThread
argument_list|(
name|SqlThread
operator|::
name|PreparedWriting
argument_list|,
name|db
argument_list|,
operator|&
name|cleanupHelper
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|writer
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|threadFinished
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|writer
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
name|QTRY_VERIFY
argument_list|(
name|threadFinishedCount
operator|>=
name|maxThreadCount
operator|*
literal|2
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|transactionsFromSingleConnection
name|void
name|tst_QSqlThread
operator|::
name|transactionsFromSingleConnection
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QOCI_THREADED
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|dbName
argument_list|)
expr_stmt|;
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbName
argument_list|)
decl_stmt|;
name|CHECK_DATABASE
argument_list|(
name|db
argument_list|)
expr_stmt|;
if|if
condition|(
name|db
operator|.
name|databaseName
argument_list|()
operator|==
literal|":memory:"
condition|)
name|QSKIP
argument_list|(
literal|"does not work with in-memory databases"
argument_list|)
expr_stmt|;
comment|// start and commit a transaction
name|QVERIFY_SQL
argument_list|(
name|db
argument_list|,
name|db
operator|.
name|transaction
argument_list|()
argument_list|)
expr_stmt|;
name|preparedReadWriteFromSingleConnection
argument_list|()
expr_stmt|;
comment|// read and write from multiple threads
if|if
condition|(
name|QTest
operator|::
name|currentTestFailed
argument_list|()
condition|)
return|return;
name|QVERIFY_SQL
argument_list|(
name|db
argument_list|,
name|db
operator|.
name|commit
argument_list|()
argument_list|)
expr_stmt|;
comment|// reset test environment
name|threadFinishedCount
operator|=
literal|0
expr_stmt|;
comment|// start and roll back a transaction
name|QVERIFY_SQL
argument_list|(
name|db
argument_list|,
name|db
operator|.
name|transaction
argument_list|()
argument_list|)
expr_stmt|;
name|preparedReadWriteFromSingleConnection
argument_list|()
expr_stmt|;
comment|// read and write from multiple threads
if|if
condition|(
name|QTest
operator|::
name|currentTestFailed
argument_list|()
condition|)
return|return;
name|QVERIFY_SQL
argument_list|(
name|db
argument_list|,
name|db
operator|.
name|rollback
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSqlThread
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsqlthread.moc"
end_include
end_unit
