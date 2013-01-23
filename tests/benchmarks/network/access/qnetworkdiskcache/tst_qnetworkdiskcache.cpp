begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QNetworkDiskCache>
end_include
begin_include
include|#
directive|include
file|<QNetworkCacheMetaData>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QBuffer>
end_include
begin_include
include|#
directive|include
file|<QTextStream>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QIODevice>
end_include
begin_include
include|#
directive|include
file|<QStandardPaths>
end_include
begin_enum
DECL|enum|Numbers
DECL|enumerator|NumFakeCacheObjects
enum|enum
name|Numbers
block|{
name|NumFakeCacheObjects
init|=
literal|200
block|,
comment|//entries in pre-populated cache
DECL|enumerator|NumInsertions
name|NumInsertions
init|=
literal|100
block|,
comment|//insertions to be timed
DECL|enumerator|NumRemovals
name|NumRemovals
init|=
literal|100
block|,
comment|//removals to be timed
DECL|enumerator|NumReadContent
name|NumReadContent
init|=
literal|100
block|,
comment|//meta requests to be timed
DECL|enumerator|HugeCacheLimit
name|HugeCacheLimit
init|=
literal|50
operator|*
literal|1024
operator|*
literal|1024
block|,
comment|// max size for a big cache
DECL|enumerator|TinyCacheLimit
name|TinyCacheLimit
init|=
literal|1
operator|*
literal|512
operator|*
literal|1024
block|}
enum|;
end_enum
begin_comment
DECL|enumerator|TinyCacheLimit
comment|//  max size for a tiny cache
end_comment
begin_decl_stmt
DECL|variable|fakeURLbase
specifier|const
name|QString
name|fakeURLbase
init|=
literal|"http://127.0.0.1/fake/"
decl_stmt|;
end_decl_stmt
begin_comment
comment|//fake HTTP body aka payload
end_comment
begin_decl_stmt
specifier|const
name|QByteArray
name|payload
argument_list|(
literal|"Qt rocks!"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|tst_qnetworkdiskcache
class|class
name|tst_qnetworkdiskcache
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private:
name|void
name|injectFakeData
parameter_list|()
function_decl|;
name|void
name|insertOneItem
parameter_list|()
function_decl|;
name|bool
name|isUrlCached
parameter_list|(
name|quint32
name|id
parameter_list|)
function_decl|;
name|void
name|cleanRecursive
parameter_list|(
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
name|void
name|cleanupCacheObject
parameter_list|()
function_decl|;
name|void
name|initCacheObject
parameter_list|()
function_decl|;
DECL|member|cacheDir
name|QString
name|cacheDir
decl_stmt|;
DECL|member|cache
name|QNetworkDiskCache
modifier|*
name|cache
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
private|private
name|slots
private|:
name|void
name|timeInsertion_data
parameter_list|()
function_decl|;
name|void
name|timeInsertion
parameter_list|()
function_decl|;
name|void
name|timeRead_data
parameter_list|()
function_decl|;
name|void
name|timeRead
parameter_list|()
function_decl|;
name|void
name|timeRemoval_data
parameter_list|()
function_decl|;
name|void
name|timeRemoval
parameter_list|()
function_decl|;
name|void
name|timeExpiration_data
parameter_list|()
function_decl|;
name|void
name|timeExpiration
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_qnetworkdiskcache
operator|::
name|initTestCase
parameter_list|()
block|{
name|cache
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_qnetworkdiskcache
operator|::
name|cleanupTestCase
parameter_list|()
block|{
name|cleanupCacheObject
argument_list|()
expr_stmt|;
name|cleanRecursive
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timeInsertion_data
name|void
name|tst_qnetworkdiskcache
operator|::
name|timeInsertion_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"cacheRootDirectory"
argument_list|)
expr_stmt|;
name|QString
name|cacheLoc
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|CacheLocation
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QStandardPaths Cache Location"
argument_list|)
operator|<<
name|cacheLoc
expr_stmt|;
block|}
end_function
begin_comment
comment|//This functions times an insert() operation.
end_comment
begin_comment
comment|//You can run it after populating the cache with
end_comment
begin_comment
comment|//fake data so that more realistic performance
end_comment
begin_comment
comment|//estimates are obtained.
end_comment
begin_function
DECL|function|timeInsertion
name|void
name|tst_qnetworkdiskcache
operator|::
name|timeInsertion
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|cacheRootDirectory
argument_list|)
expr_stmt|;
name|cacheDir
operator|=
name|QString
argument_list|(
name|cacheRootDirectory
operator|+
name|QDir
operator|::
name|separator
argument_list|()
operator|+
literal|"man_qndc"
argument_list|)
expr_stmt|;
name|QDir
name|d
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Setting cache directory to = "
operator|<<
name|d
operator|.
name|absoluteFilePath
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
comment|//Housekeeping
name|cleanRecursive
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
comment|// slow op.
name|initCacheObject
argument_list|()
expr_stmt|;
name|cache
operator|->
name|setCacheDirectory
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
name|cache
operator|->
name|setMaximumCacheSize
argument_list|(
name|qint64
argument_list|(
name|HugeCacheLimit
argument_list|)
argument_list|)
expr_stmt|;
name|cache
operator|->
name|clear
argument_list|()
expr_stmt|;
comment|//populate some fake data to simulate partially full cache
name|injectFakeData
argument_list|()
expr_stmt|;
comment|// SLOW
comment|//Sanity-check that the first URL that we insert below isn't already in there.
name|QVERIFY
argument_list|(
name|isUrlCached
argument_list|(
name|NumFakeCacheObjects
argument_list|)
operator|==
literal|false
argument_list|)
expr_stmt|;
comment|// IMPORTANT: max cache size should be HugeCacheLimit, to avoid evictions below
comment|//time insertion of previously-uncached URLs.
name|QBENCHMARK_ONCE
block|{
for|for
control|(
name|quint32
name|i
init|=
name|NumFakeCacheObjects
init|;
name|i
operator|<
operator|(
name|NumFakeCacheObjects
operator|+
name|NumInsertions
operator|)
condition|;
name|i
operator|++
control|)
block|{
comment|//prepare metata for url
name|QNetworkCacheMetaData
name|meta
decl_stmt|;
name|QString
name|fakeURL
decl_stmt|;
name|QTextStream
name|stream
argument_list|(
operator|&
name|fakeURL
argument_list|)
decl_stmt|;
name|stream
operator|<<
name|fakeURLbase
operator|<<
name|i
expr_stmt|;
name|QUrl
name|url
argument_list|(
name|fakeURL
argument_list|)
decl_stmt|;
name|meta
operator|.
name|setUrl
argument_list|(
name|url
argument_list|)
expr_stmt|;
name|meta
operator|.
name|setSaveToDisk
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//commit payload and metadata to disk
name|QIODevice
modifier|*
name|device
init|=
name|cache
operator|->
name|prepare
argument_list|(
name|meta
argument_list|)
decl_stmt|;
name|device
operator|->
name|write
argument_list|(
name|payload
argument_list|)
expr_stmt|;
name|cache
operator|->
name|insert
argument_list|(
name|device
argument_list|)
expr_stmt|;
block|}
block|}
comment|//SLOW cleanup
name|cleanupCacheObject
argument_list|()
expr_stmt|;
name|cleanRecursive
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timeRead_data
name|void
name|tst_qnetworkdiskcache
operator|::
name|timeRead_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"cacheRootDirectory"
argument_list|)
expr_stmt|;
name|QString
name|cacheLoc
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|CacheLocation
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QStandardPaths Cache Location"
argument_list|)
operator|<<
name|cacheLoc
expr_stmt|;
block|}
end_function
begin_comment
comment|//Times metadata as well payload lookup
end_comment
begin_comment
comment|// i.e metaData(), rawHeaders() and data()
end_comment
begin_function
DECL|function|timeRead
name|void
name|tst_qnetworkdiskcache
operator|::
name|timeRead
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|cacheRootDirectory
argument_list|)
expr_stmt|;
name|cacheDir
operator|=
name|QString
argument_list|(
name|cacheRootDirectory
operator|+
name|QDir
operator|::
name|separator
argument_list|()
operator|+
literal|"man_qndc"
argument_list|)
expr_stmt|;
name|QDir
name|d
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Setting cache directory to = "
operator|<<
name|d
operator|.
name|absoluteFilePath
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
comment|//Housekeeping
name|cleanRecursive
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
comment|// slow op.
name|initCacheObject
argument_list|()
expr_stmt|;
name|cache
operator|->
name|setCacheDirectory
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
name|cache
operator|->
name|setMaximumCacheSize
argument_list|(
name|qint64
argument_list|(
name|HugeCacheLimit
argument_list|)
argument_list|)
expr_stmt|;
name|cache
operator|->
name|clear
argument_list|()
expr_stmt|;
comment|//populate some fake data to simulate partially full cache
name|injectFakeData
argument_list|()
expr_stmt|;
comment|//Entries in the cache should be> what we try to remove
name|QVERIFY
argument_list|(
name|NumFakeCacheObjects
operator|>
name|NumReadContent
argument_list|)
expr_stmt|;
comment|//time metadata lookup of previously inserted URL.
name|QBENCHMARK_ONCE
block|{
for|for
control|(
name|quint32
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumReadContent
condition|;
name|i
operator|++
control|)
block|{
name|QString
name|fakeURL
decl_stmt|;
name|QTextStream
name|stream
argument_list|(
operator|&
name|fakeURL
argument_list|)
decl_stmt|;
name|stream
operator|<<
name|fakeURLbase
operator|<<
name|i
expr_stmt|;
name|QUrl
name|url
argument_list|(
name|fakeURL
argument_list|)
decl_stmt|;
name|QNetworkCacheMetaData
name|qndc
init|=
name|cache
operator|->
name|metaData
argument_list|(
name|url
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|qndc
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
comment|// we must have read the metadata
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
name|raw
argument_list|(
name|qndc
operator|.
name|rawHeaders
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|raw
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
comment|// we must have parsed the headers from the meta
name|QIODevice
modifier|*
name|iodevice
argument_list|(
name|cache
operator|->
name|data
argument_list|(
name|url
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|iodevice
argument_list|)
expr_stmt|;
comment|//must not be NULL
name|iodevice
operator|->
name|close
argument_list|()
expr_stmt|;
operator|delete
name|iodevice
expr_stmt|;
block|}
block|}
comment|//Cleanup (slow)
name|cleanupCacheObject
argument_list|()
expr_stmt|;
name|cleanRecursive
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timeRemoval_data
name|void
name|tst_qnetworkdiskcache
operator|::
name|timeRemoval_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"cacheRootDirectory"
argument_list|)
expr_stmt|;
name|QString
name|cacheLoc
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|CacheLocation
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QStandardPaths Cache Location"
argument_list|)
operator|<<
name|cacheLoc
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timeRemoval
name|void
name|tst_qnetworkdiskcache
operator|::
name|timeRemoval
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|cacheRootDirectory
argument_list|)
expr_stmt|;
name|cacheDir
operator|=
name|QString
argument_list|(
name|cacheRootDirectory
operator|+
name|QDir
operator|::
name|separator
argument_list|()
operator|+
literal|"man_qndc"
argument_list|)
expr_stmt|;
name|QDir
name|d
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Setting cache directory to = "
operator|<<
name|d
operator|.
name|absoluteFilePath
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
comment|//Housekeeping
name|initCacheObject
argument_list|()
expr_stmt|;
name|cleanRecursive
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
comment|// slow op.
name|cache
operator|->
name|setCacheDirectory
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
comment|// Make max cache size HUGE, so that evictions don't happen below
name|cache
operator|->
name|setMaximumCacheSize
argument_list|(
name|qint64
argument_list|(
name|HugeCacheLimit
argument_list|)
argument_list|)
expr_stmt|;
name|cache
operator|->
name|clear
argument_list|()
expr_stmt|;
comment|//populate some fake data to simulate partially full cache
name|injectFakeData
argument_list|()
expr_stmt|;
comment|//Sanity-check that the URL is already in there somewhere
name|QVERIFY
argument_list|(
name|isUrlCached
argument_list|(
name|NumRemovals
operator|-
literal|1
argument_list|)
operator|==
literal|true
argument_list|)
expr_stmt|;
comment|//Entries in the cache should be> what we try to remove
name|QVERIFY
argument_list|(
name|NumFakeCacheObjects
operator|>
name|NumRemovals
argument_list|)
expr_stmt|;
comment|//time removal of previously-inserted URL.
name|QBENCHMARK_ONCE
block|{
for|for
control|(
name|quint32
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumRemovals
condition|;
name|i
operator|++
control|)
block|{
name|QString
name|fakeURL
decl_stmt|;
name|QTextStream
name|stream
argument_list|(
operator|&
name|fakeURL
argument_list|)
decl_stmt|;
name|stream
operator|<<
name|fakeURLbase
operator|<<
name|i
expr_stmt|;
name|QUrl
name|url
argument_list|(
name|fakeURL
argument_list|)
decl_stmt|;
name|cache
operator|->
name|remove
argument_list|(
name|url
argument_list|)
expr_stmt|;
block|}
block|}
comment|//Cleanup (slow)
name|cleanupCacheObject
argument_list|()
expr_stmt|;
name|cleanRecursive
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timeExpiration_data
name|void
name|tst_qnetworkdiskcache
operator|::
name|timeExpiration_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"cacheRootDirectory"
argument_list|)
expr_stmt|;
name|QString
name|cacheLoc
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|CacheLocation
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QStandardPaths Cache Location"
argument_list|)
operator|<<
name|cacheLoc
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timeExpiration
name|void
name|tst_qnetworkdiskcache
operator|::
name|timeExpiration
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|cacheRootDirectory
argument_list|)
expr_stmt|;
name|cacheDir
operator|=
name|QString
argument_list|(
name|cacheRootDirectory
operator|+
name|QDir
operator|::
name|separator
argument_list|()
operator|+
literal|"man_qndc"
argument_list|)
expr_stmt|;
name|QDir
name|d
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Setting cache directory to = "
operator|<<
name|d
operator|.
name|absoluteFilePath
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
comment|//Housekeeping
name|initCacheObject
argument_list|()
expr_stmt|;
name|cleanRecursive
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
comment|// slow op.
name|cache
operator|->
name|setCacheDirectory
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
comment|// Make max cache size HUGE, so that evictions don't happen below
name|cache
operator|->
name|setMaximumCacheSize
argument_list|(
name|qint64
argument_list|(
name|HugeCacheLimit
argument_list|)
argument_list|)
expr_stmt|;
name|cache
operator|->
name|clear
argument_list|()
expr_stmt|;
comment|//populate some fake data to simulate partially full cache
name|injectFakeData
argument_list|()
expr_stmt|;
comment|//Sanity-check that the URL is already in there somewhere
name|QVERIFY
argument_list|(
name|isUrlCached
argument_list|(
name|NumRemovals
operator|-
literal|1
argument_list|)
operator|==
literal|true
argument_list|)
expr_stmt|;
comment|//Entries in the cache should be> what we try to remove
name|QVERIFY
argument_list|(
name|NumFakeCacheObjects
operator|>
name|NumRemovals
argument_list|)
expr_stmt|;
comment|//Set cache limit lower, so this force 1 round of eviction
name|cache
operator|->
name|setMaximumCacheSize
argument_list|(
name|qint64
argument_list|(
name|TinyCacheLimit
argument_list|)
argument_list|)
expr_stmt|;
comment|//time insertions of additional content, which is likely to internally cause evictions
name|QBENCHMARK_ONCE
block|{
for|for
control|(
name|quint32
name|i
init|=
name|NumFakeCacheObjects
init|;
name|i
operator|<
operator|(
name|NumFakeCacheObjects
operator|+
name|NumInsertions
operator|)
condition|;
name|i
operator|++
control|)
block|{
comment|//prepare metata for url
name|QNetworkCacheMetaData
name|meta
decl_stmt|;
name|QString
name|fakeURL
decl_stmt|;
name|QTextStream
name|stream
argument_list|(
operator|&
name|fakeURL
argument_list|)
decl_stmt|;
name|stream
operator|<<
name|fakeURLbase
operator|<<
name|i
expr_stmt|;
comment|//codescanner::leave
name|QUrl
name|url
argument_list|(
name|fakeURL
argument_list|)
decl_stmt|;
name|meta
operator|.
name|setUrl
argument_list|(
name|url
argument_list|)
expr_stmt|;
name|meta
operator|.
name|setSaveToDisk
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//commit payload and metadata to disk
name|QIODevice
modifier|*
name|device
init|=
name|cache
operator|->
name|prepare
argument_list|(
name|meta
argument_list|)
decl_stmt|;
name|device
operator|->
name|write
argument_list|(
name|payload
argument_list|)
expr_stmt|;
name|cache
operator|->
name|insert
argument_list|(
name|device
argument_list|)
expr_stmt|;
comment|// this should trigger evictions, if TinyCacheLimit is small enough
block|}
block|}
comment|//Cleanup (slow)
name|cleanupCacheObject
argument_list|()
expr_stmt|;
name|cleanRecursive
argument_list|(
name|cacheDir
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// This function simulates a partially or fully occupied disk cache
end_comment
begin_comment
comment|// like a normal user of a cache might encounter is real-life browsing.
end_comment
begin_comment
comment|// The point of this is to trigger degradation in file-system and media performance
end_comment
begin_comment
comment|// that occur due to the quantity and layout of data.
end_comment
begin_function
DECL|function|injectFakeData
name|void
name|tst_qnetworkdiskcache
operator|::
name|injectFakeData
parameter_list|()
block|{
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
name|headers
decl_stmt|;
name|headers
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|QByteArray
argument_list|(
literal|"X-TestHeader"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"HeaderValue"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//Prep cache dir with fake data using QNetworkDiskCache APIs
for|for
control|(
name|quint32
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumFakeCacheObjects
condition|;
name|i
operator|++
control|)
block|{
comment|//prepare metata for url
name|QNetworkCacheMetaData
name|meta
decl_stmt|;
name|QString
name|fakeURL
decl_stmt|;
name|QTextStream
name|stream
argument_list|(
operator|&
name|fakeURL
argument_list|)
decl_stmt|;
name|stream
operator|<<
name|fakeURLbase
operator|<<
name|i
expr_stmt|;
name|QUrl
name|url
argument_list|(
name|fakeURL
argument_list|)
decl_stmt|;
name|meta
operator|.
name|setUrl
argument_list|(
name|url
argument_list|)
expr_stmt|;
name|meta
operator|.
name|setRawHeaders
argument_list|(
name|headers
argument_list|)
expr_stmt|;
name|meta
operator|.
name|setSaveToDisk
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//commit payload and metadata to disk
name|QIODevice
modifier|*
name|device
init|=
name|cache
operator|->
name|prepare
argument_list|(
name|meta
argument_list|)
decl_stmt|;
name|device
operator|->
name|write
argument_list|(
name|payload
argument_list|)
expr_stmt|;
name|cache
operator|->
name|insert
argument_list|(
name|device
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|// Checks if the fake URL #id is already cached or not.
end_comment
begin_function
DECL|function|isUrlCached
name|bool
name|tst_qnetworkdiskcache
operator|::
name|isUrlCached
parameter_list|(
name|quint32
name|id
parameter_list|)
block|{
name|QString
name|str
decl_stmt|;
name|QTextStream
name|stream
argument_list|(
operator|&
name|str
argument_list|)
decl_stmt|;
name|stream
operator|<<
name|fakeURLbase
operator|<<
name|id
expr_stmt|;
name|QUrl
name|url
argument_list|(
name|str
argument_list|)
decl_stmt|;
name|QIODevice
modifier|*
name|iod
init|=
name|cache
operator|->
name|data
argument_list|(
name|url
argument_list|)
decl_stmt|;
return|return
operator|(
operator|(
name|iod
operator|==
literal|0
operator|)
condition|?
literal|false
else|:
literal|true
operator|)
return|;
block|}
end_function
begin_comment
comment|// Utility function for recursive directory cleanup.
end_comment
begin_function
DECL|function|cleanRecursive
name|void
name|tst_qnetworkdiskcache
operator|::
name|cleanRecursive
parameter_list|(
name|QString
modifier|&
name|path
parameter_list|)
block|{
name|QDirIterator
name|it
argument_list|(
name|path
argument_list|,
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|NoDotAndDotDot
argument_list|,
name|QDirIterator
operator|::
name|Subdirectories
argument_list|)
decl_stmt|;
while|while
condition|(
name|it
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|QFile
name|f
argument_list|(
name|it
operator|.
name|next
argument_list|()
argument_list|)
decl_stmt|;
name|bool
name|err
init|=
name|f
operator|.
name|remove
argument_list|()
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|err
argument_list|)
expr_stmt|;
block|}
name|QDirIterator
name|it2
argument_list|(
name|path
argument_list|,
name|QDir
operator|::
name|AllDirs
operator||
name|QDir
operator|::
name|NoDotAndDotDot
argument_list|,
name|QDirIterator
operator|::
name|Subdirectories
argument_list|)
decl_stmt|;
while|while
condition|(
name|it2
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|QString
name|s
argument_list|(
name|it2
operator|.
name|next
argument_list|()
argument_list|)
decl_stmt|;
name|QDir
name|dir
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|dir
operator|.
name|rmdir
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|cleanupCacheObject
name|void
name|tst_qnetworkdiskcache
operator|::
name|cleanupCacheObject
parameter_list|()
block|{
operator|delete
name|cache
expr_stmt|;
name|cache
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initCacheObject
name|void
name|tst_qnetworkdiskcache
operator|::
name|initCacheObject
parameter_list|()
block|{
name|cache
operator|=
operator|new
name|QNetworkDiskCache
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qnetworkdiskcache
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qnetworkdiskcache.moc"
end_include
end_unit
