begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest>
end_include
begin_include
include|#
directive|include
file|<qjsondocument.h>
end_include
begin_include
include|#
directive|include
file|<qjsonobject.h>
end_include
begin_class
DECL|class|BenchmarkQtBinaryJson
class|class
name|BenchmarkQtBinaryJson
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|BenchmarkQtBinaryJson
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
private|private
name|Q_SLOTS
private|:
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
name|void
name|parseNumbers
parameter_list|()
function_decl|;
name|void
name|parseJson
parameter_list|()
function_decl|;
name|void
name|parseJsonToVariant
parameter_list|()
function_decl|;
name|void
name|toByteArray
parameter_list|()
function_decl|;
name|void
name|fromByteArray
parameter_list|()
function_decl|;
name|void
name|jsonObjectInsert
parameter_list|()
function_decl|;
name|void
name|variantMapInsert
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|BenchmarkQtBinaryJson
name|BenchmarkQtBinaryJson
operator|::
name|BenchmarkQtBinaryJson
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{  }
end_constructor
begin_function
DECL|function|initTestCase
name|void
name|BenchmarkQtBinaryJson
operator|::
name|initTestCase
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|BenchmarkQtBinaryJson
operator|::
name|cleanupTestCase
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|init
name|void
name|BenchmarkQtBinaryJson
operator|::
name|init
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|cleanup
name|void
name|BenchmarkQtBinaryJson
operator|::
name|cleanup
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|parseNumbers
name|void
name|BenchmarkQtBinaryJson
operator|::
name|parseNumbers
parameter_list|()
block|{
name|QString
name|testFile
init|=
name|QFINDTESTDATA
argument_list|(
literal|"numbers.json"
argument_list|)
decl_stmt|;
name|QVERIFY2
argument_list|(
operator|!
name|testFile
operator|.
name|isEmpty
argument_list|()
argument_list|,
literal|"cannot find test file numbers.json!"
argument_list|)
expr_stmt|;
name|QFile
name|file
argument_list|(
name|testFile
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QByteArray
name|testJson
init|=
name|file
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|QJsonDocument
name|doc
init|=
name|QJsonDocument
operator|::
name|fromJson
argument_list|(
name|testJson
argument_list|)
decl_stmt|;
name|QJsonObject
name|object
init|=
name|doc
operator|.
name|object
argument_list|()
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|parseJson
name|void
name|BenchmarkQtBinaryJson
operator|::
name|parseJson
parameter_list|()
block|{
name|QString
name|testFile
init|=
name|QFINDTESTDATA
argument_list|(
literal|"test.json"
argument_list|)
decl_stmt|;
name|QVERIFY2
argument_list|(
operator|!
name|testFile
operator|.
name|isEmpty
argument_list|()
argument_list|,
literal|"cannot find test file test.json!"
argument_list|)
expr_stmt|;
name|QFile
name|file
argument_list|(
name|testFile
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QByteArray
name|testJson
init|=
name|file
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|QJsonDocument
name|doc
init|=
name|QJsonDocument
operator|::
name|fromJson
argument_list|(
name|testJson
argument_list|)
decl_stmt|;
name|QJsonObject
name|object
init|=
name|doc
operator|.
name|object
argument_list|()
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|parseJsonToVariant
name|void
name|BenchmarkQtBinaryJson
operator|::
name|parseJsonToVariant
parameter_list|()
block|{
name|QString
name|testFile
init|=
name|QFINDTESTDATA
argument_list|(
literal|"test.json"
argument_list|)
decl_stmt|;
name|QVERIFY2
argument_list|(
operator|!
name|testFile
operator|.
name|isEmpty
argument_list|()
argument_list|,
literal|"cannot find test file test.json!"
argument_list|)
expr_stmt|;
name|QFile
name|file
argument_list|(
name|testFile
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QByteArray
name|testJson
init|=
name|file
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|QJsonDocument
name|doc
init|=
name|QJsonDocument
operator|::
name|fromJson
argument_list|(
name|testJson
argument_list|)
decl_stmt|;
name|QVariant
name|v
init|=
name|doc
operator|.
name|toVariant
argument_list|()
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|toByteArray
name|void
name|BenchmarkQtBinaryJson
operator|::
name|toByteArray
parameter_list|()
block|{
comment|// Example: send information over a datastream to another process
comment|// Measure performance of creating and processing data into bytearray
name|QBENCHMARK
block|{
name|QVariantMap
name|message
decl_stmt|;
name|message
operator|.
name|insert
argument_list|(
literal|"command"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|message
operator|.
name|insert
argument_list|(
literal|"key"
argument_list|,
literal|"some information"
argument_list|)
expr_stmt|;
name|message
operator|.
name|insert
argument_list|(
literal|"env"
argument_list|,
literal|"some environment variables"
argument_list|)
expr_stmt|;
name|QByteArray
name|msg
init|=
name|QJsonDocument
argument_list|(
name|QJsonObject
operator|::
name|fromVariantMap
argument_list|(
name|message
argument_list|)
argument_list|)
operator|.
name|toBinaryData
argument_list|()
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fromByteArray
name|void
name|BenchmarkQtBinaryJson
operator|::
name|fromByteArray
parameter_list|()
block|{
comment|// Example: receive information over a datastream from another process
comment|// Measure performance of converting content back to QVariantMap
comment|// We need to recreate the bytearray but here we only want to measure the latter
name|QVariantMap
name|message
decl_stmt|;
name|message
operator|.
name|insert
argument_list|(
literal|"command"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|message
operator|.
name|insert
argument_list|(
literal|"key"
argument_list|,
literal|"some information"
argument_list|)
expr_stmt|;
name|message
operator|.
name|insert
argument_list|(
literal|"env"
argument_list|,
literal|"some environment variables"
argument_list|)
expr_stmt|;
name|QByteArray
name|msg
init|=
name|QJsonDocument
argument_list|(
name|QJsonObject
operator|::
name|fromVariantMap
argument_list|(
name|message
argument_list|)
argument_list|)
operator|.
name|toBinaryData
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|QVariantMap
name|message
decl_stmt|;
name|message
operator|=
name|QJsonDocument
operator|::
name|fromBinaryData
argument_list|(
name|msg
argument_list|,
name|QJsonDocument
operator|::
name|Validate
argument_list|)
operator|.
name|object
argument_list|()
operator|.
name|toVariantMap
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|jsonObjectInsert
name|void
name|BenchmarkQtBinaryJson
operator|::
name|jsonObjectInsert
parameter_list|()
block|{
name|QJsonObject
name|object
decl_stmt|;
name|QString
name|test
argument_list|(
name|QStringLiteral
argument_list|(
literal|"testString"
argument_list|)
argument_list|)
decl_stmt|;
name|QJsonValue
name|value
argument_list|(
literal|1.5
argument_list|)
decl_stmt|;
name|QBENCHMARK
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
literal|1000
condition|;
name|i
operator|++
control|)
name|object
operator|.
name|insert
argument_list|(
literal|"testkey_"
operator|+
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|variantMapInsert
name|void
name|BenchmarkQtBinaryJson
operator|::
name|variantMapInsert
parameter_list|()
block|{
name|QVariantMap
name|object
decl_stmt|;
name|QString
name|test
argument_list|(
name|QStringLiteral
argument_list|(
literal|"testString"
argument_list|)
argument_list|)
decl_stmt|;
name|QVariant
name|variantValue
argument_list|(
literal|1.5
argument_list|)
decl_stmt|;
name|QBENCHMARK
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
literal|1000
condition|;
name|i
operator|++
control|)
name|object
operator|.
name|insert
argument_list|(
literal|"testkey_"
operator|+
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
argument_list|,
name|variantValue
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|BenchmarkQtBinaryJson
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_bench_qtbinaryjson.moc"
end_include
end_unit
