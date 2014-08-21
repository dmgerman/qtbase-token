begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qabstractnetworkcache.h>
end_include
begin_define
DECL|macro|EXAMPLE_URL
define|#
directive|define
name|EXAMPLE_URL
value|"http://user:pass@www.example.com/#foo"
end_define
begin_class
DECL|class|tst_QNetworkCacheMetaData
class|class
name|tst_QNetworkCacheMetaData
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
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
private|private
name|slots
private|:
name|void
name|qnetworkcachemetadata_data
parameter_list|()
function_decl|;
name|void
name|qnetworkcachemetadata
parameter_list|()
function_decl|;
name|void
name|expirationDate_data
parameter_list|()
function_decl|;
name|void
name|expirationDate
parameter_list|()
function_decl|;
name|void
name|isValid_data
parameter_list|()
function_decl|;
name|void
name|isValid
parameter_list|()
function_decl|;
name|void
name|lastModified_data
parameter_list|()
function_decl|;
name|void
name|lastModified
parameter_list|()
function_decl|;
name|void
name|operatorEqual_data
parameter_list|()
function_decl|;
name|void
name|operatorEqual
parameter_list|()
function_decl|;
name|void
name|operatorEqualEqual_data
parameter_list|()
function_decl|;
name|void
name|operatorEqualEqual
parameter_list|()
function_decl|;
name|void
name|rawHeaders_data
parameter_list|()
function_decl|;
name|void
name|rawHeaders
parameter_list|()
function_decl|;
name|void
name|saveToDisk_data
parameter_list|()
function_decl|;
name|void
name|saveToDisk
parameter_list|()
function_decl|;
name|void
name|url_data
parameter_list|()
function_decl|;
name|void
name|url
parameter_list|()
function_decl|;
name|void
name|stream
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// Subclass that exposes the protected functions.
end_comment
begin_class
DECL|class|SubQNetworkCacheMetaData
class|class
name|SubQNetworkCacheMetaData
super|:
specifier|public
name|QNetworkCacheMetaData
block|{
public|public:
block|}
class|;
end_class
begin_comment
comment|// This will be called before the first test function is executed.
end_comment
begin_comment
comment|// It is only called once.
end_comment
begin_function
DECL|function|initTestCase
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_comment
comment|// This will be called after the last test function is executed.
end_comment
begin_comment
comment|// It is only called once.
end_comment
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_comment
comment|// This will be called before each test function is executed.
end_comment
begin_function
DECL|function|init
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_comment
comment|// This will be called after every test function.
end_comment
begin_function
DECL|function|cleanup
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|qnetworkcachemetadata_data
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|qnetworkcachemetadata_data
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|qnetworkcachemetadata
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|qnetworkcachemetadata
parameter_list|()
block|{
name|QNetworkCacheMetaData
name|data
decl_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|expirationDate
argument_list|()
argument_list|,
name|QDateTime
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|isValid
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|lastModified
argument_list|()
argument_list|,
name|QDateTime
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|operator
name|!=
argument_list|(
name|QNetworkCacheMetaData
argument_list|()
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QNetworkCacheMetaData
name|metaData
decl_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|operator
name|=
argument_list|(
name|metaData
argument_list|)
argument_list|,
name|QNetworkCacheMetaData
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|operator
name|==
argument_list|(
name|QNetworkCacheMetaData
argument_list|()
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|rawHeaders
argument_list|()
argument_list|,
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|saveToDisk
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|url
argument_list|()
argument_list|,
name|QUrl
argument_list|()
argument_list|)
expr_stmt|;
name|data
operator|.
name|setExpirationDate
argument_list|(
name|QDateTime
argument_list|()
argument_list|)
expr_stmt|;
name|data
operator|.
name|setLastModified
argument_list|(
name|QDateTime
argument_list|()
argument_list|)
expr_stmt|;
name|data
operator|.
name|setRawHeaders
argument_list|(
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
argument_list|()
argument_list|)
expr_stmt|;
name|data
operator|.
name|setSaveToDisk
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|data
operator|.
name|setUrl
argument_list|(
name|QUrl
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|expirationDate_data
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|expirationDate_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QDateTime
argument_list|>
argument_list|(
literal|"expirationDate"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QDateTime
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"now"
argument_list|)
operator|<<
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QDateTime expirationDate() const
end_comment
begin_function
DECL|function|expirationDate
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|expirationDate
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QDateTime
argument_list|,
name|expirationDate
argument_list|)
expr_stmt|;
name|SubQNetworkCacheMetaData
name|data
decl_stmt|;
name|data
operator|.
name|setExpirationDate
argument_list|(
name|expirationDate
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|expirationDate
argument_list|()
argument_list|,
name|expirationDate
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QNetworkCacheMetaData
argument_list|)
end_macro
begin_function
DECL|function|isValid_data
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|isValid_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QNetworkCacheMetaData
argument_list|>
argument_list|(
literal|"data"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"isValid"
argument_list|)
expr_stmt|;
name|QNetworkCacheMetaData
name|metaData
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|metaData
operator|<<
literal|false
expr_stmt|;
name|QNetworkCacheMetaData
name|data1
decl_stmt|;
name|data1
operator|.
name|setUrl
argument_list|(
name|QUrl
argument_list|(
name|EXAMPLE_URL
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-1"
argument_list|)
operator|<<
name|data1
operator|<<
literal|true
expr_stmt|;
name|QNetworkCacheMetaData
name|data2
decl_stmt|;
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
name|headers
decl_stmt|;
name|headers
operator|.
name|append
argument_list|(
name|QNetworkCacheMetaData
operator|::
name|RawHeader
argument_list|(
literal|"foo"
argument_list|,
literal|"Bar"
argument_list|)
argument_list|)
expr_stmt|;
name|data2
operator|.
name|setRawHeaders
argument_list|(
name|headers
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-2"
argument_list|)
operator|<<
name|data2
operator|<<
literal|true
expr_stmt|;
name|QNetworkCacheMetaData
name|data3
decl_stmt|;
name|data3
operator|.
name|setLastModified
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-3"
argument_list|)
operator|<<
name|data3
operator|<<
literal|true
expr_stmt|;
name|QNetworkCacheMetaData
name|data4
decl_stmt|;
name|data4
operator|.
name|setExpirationDate
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-4"
argument_list|)
operator|<<
name|data4
operator|<<
literal|true
expr_stmt|;
name|QNetworkCacheMetaData
name|data5
decl_stmt|;
name|data5
operator|.
name|setSaveToDisk
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-5"
argument_list|)
operator|<<
name|data5
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|// public bool isValid() const
end_comment
begin_function
DECL|function|isValid
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|isValid
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QNetworkCacheMetaData
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isValid
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|isValid
argument_list|()
argument_list|,
name|isValid
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lastModified_data
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|lastModified_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QDateTime
argument_list|>
argument_list|(
literal|"lastModified"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QDateTime
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"now"
argument_list|)
operator|<<
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QDateTime lastModified() const
end_comment
begin_function
DECL|function|lastModified
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|lastModified
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QDateTime
argument_list|,
name|lastModified
argument_list|)
expr_stmt|;
name|SubQNetworkCacheMetaData
name|data
decl_stmt|;
name|data
operator|.
name|setLastModified
argument_list|(
name|lastModified
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|lastModified
argument_list|()
argument_list|,
name|lastModified
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operatorEqual_data
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|operatorEqual_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QNetworkCacheMetaData
argument_list|>
argument_list|(
literal|"other"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QNetworkCacheMetaData
argument_list|()
expr_stmt|;
name|QNetworkCacheMetaData
name|data
decl_stmt|;
name|data
operator|.
name|setUrl
argument_list|(
name|QUrl
argument_list|(
name|EXAMPLE_URL
argument_list|)
argument_list|)
expr_stmt|;
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
name|headers
decl_stmt|;
name|headers
operator|.
name|append
argument_list|(
name|QNetworkCacheMetaData
operator|::
name|RawHeader
argument_list|(
literal|"foo"
argument_list|,
literal|"Bar"
argument_list|)
argument_list|)
expr_stmt|;
name|data
operator|.
name|setRawHeaders
argument_list|(
name|headers
argument_list|)
expr_stmt|;
name|data
operator|.
name|setLastModified
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
expr_stmt|;
name|data
operator|.
name|setExpirationDate
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
expr_stmt|;
name|data
operator|.
name|setSaveToDisk
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid"
argument_list|)
operator|<<
name|data
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QNetworkCacheMetaData& operator=(QNetworkCacheMetaData const& other)
end_comment
begin_function
DECL|function|operatorEqual
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|operatorEqual
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QNetworkCacheMetaData
argument_list|,
name|other
argument_list|)
expr_stmt|;
name|QNetworkCacheMetaData
name|data
init|=
name|other
decl_stmt|;
name|QCOMPARE
argument_list|(
name|data
argument_list|,
name|other
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operatorEqualEqual_data
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|operatorEqualEqual_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QNetworkCacheMetaData
argument_list|>
argument_list|(
literal|"a"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QNetworkCacheMetaData
argument_list|>
argument_list|(
literal|"b"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"operatorEqualEqual"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QNetworkCacheMetaData
argument_list|()
operator|<<
name|QNetworkCacheMetaData
argument_list|()
operator|<<
literal|true
expr_stmt|;
name|QNetworkCacheMetaData
name|data1
decl_stmt|;
name|data1
operator|.
name|setUrl
argument_list|(
name|QUrl
argument_list|(
name|EXAMPLE_URL
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-1-1"
argument_list|)
operator|<<
name|data1
operator|<<
name|QNetworkCacheMetaData
argument_list|()
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-1-2"
argument_list|)
operator|<<
name|data1
operator|<<
name|data1
operator|<<
literal|true
expr_stmt|;
name|QNetworkCacheMetaData
name|data2
decl_stmt|;
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
name|headers
decl_stmt|;
name|headers
operator|.
name|append
argument_list|(
name|QNetworkCacheMetaData
operator|::
name|RawHeader
argument_list|(
literal|"foo"
argument_list|,
literal|"Bar"
argument_list|)
argument_list|)
expr_stmt|;
name|data2
operator|.
name|setRawHeaders
argument_list|(
name|headers
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-2-1"
argument_list|)
operator|<<
name|data2
operator|<<
name|QNetworkCacheMetaData
argument_list|()
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-2-2"
argument_list|)
operator|<<
name|data2
operator|<<
name|data2
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-2-3"
argument_list|)
operator|<<
name|data2
operator|<<
name|data1
operator|<<
literal|false
expr_stmt|;
name|QNetworkCacheMetaData
name|data3
decl_stmt|;
name|data3
operator|.
name|setLastModified
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-3-1"
argument_list|)
operator|<<
name|data3
operator|<<
name|QNetworkCacheMetaData
argument_list|()
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-3-2"
argument_list|)
operator|<<
name|data3
operator|<<
name|data3
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-3-3"
argument_list|)
operator|<<
name|data3
operator|<<
name|data1
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-3-4"
argument_list|)
operator|<<
name|data3
operator|<<
name|data2
operator|<<
literal|false
expr_stmt|;
name|QNetworkCacheMetaData
name|data4
decl_stmt|;
name|data4
operator|.
name|setExpirationDate
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-4-1"
argument_list|)
operator|<<
name|data4
operator|<<
name|QNetworkCacheMetaData
argument_list|()
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-4-2"
argument_list|)
operator|<<
name|data4
operator|<<
name|data4
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-4-3"
argument_list|)
operator|<<
name|data4
operator|<<
name|data1
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-4-4"
argument_list|)
operator|<<
name|data4
operator|<<
name|data2
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-4-5"
argument_list|)
operator|<<
name|data4
operator|<<
name|data3
operator|<<
literal|false
expr_stmt|;
name|QNetworkCacheMetaData
name|data5
decl_stmt|;
name|data5
operator|.
name|setSaveToDisk
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-5-1"
argument_list|)
operator|<<
name|data5
operator|<<
name|QNetworkCacheMetaData
argument_list|()
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-5-2"
argument_list|)
operator|<<
name|data5
operator|<<
name|data5
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-5-3"
argument_list|)
operator|<<
name|data5
operator|<<
name|data1
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-5-4"
argument_list|)
operator|<<
name|data5
operator|<<
name|data2
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-5-5"
argument_list|)
operator|<<
name|data5
operator|<<
name|data3
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid-5-6"
argument_list|)
operator|<<
name|data5
operator|<<
name|data4
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_comment
comment|// public bool operator==(QNetworkCacheMetaData const& other) const
end_comment
begin_function
DECL|function|operatorEqualEqual
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|operatorEqualEqual
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QNetworkCacheMetaData
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QNetworkCacheMetaData
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|operatorEqualEqual
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a
operator|==
name|b
argument_list|,
name|operatorEqualEqual
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QNetworkCacheMetaData::RawHeaderList
argument_list|)
end_macro
begin_function
DECL|function|rawHeaders_data
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|rawHeaders_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
argument_list|>
argument_list|(
literal|"rawHeaders"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
argument_list|()
expr_stmt|;
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
name|headers
decl_stmt|;
name|headers
operator|.
name|append
argument_list|(
name|QNetworkCacheMetaData
operator|::
name|RawHeader
argument_list|(
literal|"foo"
argument_list|,
literal|"Bar"
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valie"
argument_list|)
operator|<<
name|headers
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QNetworkCacheMetaData::RawHeaderList rawHeaders() const
end_comment
begin_function
DECL|function|rawHeaders
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|rawHeaders
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
argument_list|,
name|rawHeaders
argument_list|)
expr_stmt|;
name|SubQNetworkCacheMetaData
name|data
decl_stmt|;
name|data
operator|.
name|setRawHeaders
argument_list|(
name|rawHeaders
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|rawHeaders
argument_list|()
argument_list|,
name|rawHeaders
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|saveToDisk_data
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|saveToDisk_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"saveToDisk"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|// public bool saveToDisk() const
end_comment
begin_function
DECL|function|saveToDisk
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|saveToDisk
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|saveToDisk
argument_list|)
expr_stmt|;
name|SubQNetworkCacheMetaData
name|data
decl_stmt|;
name|data
operator|.
name|setSaveToDisk
argument_list|(
name|saveToDisk
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|saveToDisk
argument_list|()
argument_list|,
name|saveToDisk
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|url_data
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|url_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QUrl
argument_list|>
argument_list|(
literal|"url"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QUrl
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QUrl
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid"
argument_list|)
operator|<<
name|QUrl
argument_list|(
name|EXAMPLE_URL
argument_list|)
operator|<<
name|QUrl
argument_list|(
literal|"http://user@www.example.com/"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QUrl url() const
end_comment
begin_function
DECL|function|url
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|url
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QUrl
argument_list|,
name|url
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QUrl
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|SubQNetworkCacheMetaData
name|data
decl_stmt|;
name|data
operator|.
name|setUrl
argument_list|(
name|url
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|url
argument_list|()
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stream
name|void
name|tst_QNetworkCacheMetaData
operator|::
name|stream
parameter_list|()
block|{
name|QNetworkCacheMetaData
name|data
decl_stmt|;
name|data
operator|.
name|setUrl
argument_list|(
name|QUrl
argument_list|(
name|EXAMPLE_URL
argument_list|)
argument_list|)
expr_stmt|;
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
name|headers
decl_stmt|;
name|headers
operator|.
name|append
argument_list|(
name|QNetworkCacheMetaData
operator|::
name|RawHeader
argument_list|(
literal|"foo"
argument_list|,
literal|"Bar"
argument_list|)
argument_list|)
expr_stmt|;
name|data
operator|.
name|setRawHeaders
argument_list|(
name|headers
argument_list|)
expr_stmt|;
name|data
operator|.
name|setLastModified
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
expr_stmt|;
name|data
operator|.
name|setExpirationDate
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
expr_stmt|;
name|data
operator|.
name|setSaveToDisk
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QBuffer
name|buffer
decl_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadWrite
argument_list|)
expr_stmt|;
name|QDataStream
name|stream
argument_list|(
operator|&
name|buffer
argument_list|)
decl_stmt|;
name|stream
operator|<<
name|data
expr_stmt|;
name|buffer
operator|.
name|seek
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QNetworkCacheMetaData
name|data2
decl_stmt|;
name|stream
operator|>>
name|data2
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data2
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QNetworkCacheMetaData
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qnetworkcachemetadata.moc"
end_include
end_unit
