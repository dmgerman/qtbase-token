begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QTest>
end_include
begin_include
include|#
directive|include
file|<QDirIterator>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QStack>
end_include
begin_include
include|#
directive|include
file|"../../../../../shared/filesystem.h"
end_include
begin_class
DECL|class|bench_QDir_tree
class|class
name|bench_QDir_tree
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|bench_QDir_tree
name|bench_QDir_tree
parameter_list|()
member_init_list|:
name|prefix
argument_list|(
literal|"./test-tree/"
argument_list|)
member_init_list|,
name|musicprefix
argument_list|(
name|QLatin1String
argument_list|(
literal|"music"
argument_list|)
argument_list|)
member_init_list|,
name|photoprefix
argument_list|(
name|QLatin1String
argument_list|(
literal|"photos"
argument_list|)
argument_list|)
member_init_list|,
name|sourceprefix
argument_list|(
name|QLatin1String
argument_list|(
literal|"source"
argument_list|)
argument_list|)
member_init_list|,
name|musicsize
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|photosize
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|sourcesize
argument_list|(
literal|0
argument_list|)
block|{     }
private|private:
DECL|member|prefix
name|QByteArray
name|prefix
decl_stmt|;
DECL|member|musicprefix
name|QString
name|musicprefix
decl_stmt|;
DECL|member|photoprefix
name|QString
name|photoprefix
decl_stmt|;
DECL|member|sourceprefix
name|QString
name|sourceprefix
decl_stmt|;
DECL|member|musicsize
name|qint64
name|musicsize
decl_stmt|;
DECL|member|photosize
name|qint64
name|photosize
decl_stmt|;
DECL|member|sourcesize
name|qint64
name|sourcesize
decl_stmt|;
private|private
name|slots
private|:
DECL|function|initTestCase
name|void
name|initTestCase
parameter_list|()
block|{
name|QFile
name|list
argument_list|(
literal|":/4.6.0-list.txt"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|list
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fs
operator|.
name|createDirectory
argument_list|(
name|prefix
argument_list|)
argument_list|)
expr_stmt|;
name|QStack
argument_list|<
name|QByteArray
argument_list|>
name|stack
decl_stmt|;
name|QByteArray
name|line
decl_stmt|;
name|Q_FOREVER
block|{
name|char
name|ch
decl_stmt|;
if|if
condition|(
operator|!
name|list
operator|.
name|getChar
argument_list|(
operator|&
name|ch
argument_list|)
condition|)
break|break;
if|if
condition|(
name|ch
operator|!=
literal|' '
condition|)
block|{
name|line
operator|.
name|append
argument_list|(
name|ch
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|int
name|pop
init|=
literal|1
decl_stmt|;
if|if
condition|(
operator|!
name|line
operator|.
name|isEmpty
argument_list|()
condition|)
name|pop
operator|=
name|line
operator|.
name|toInt
argument_list|()
expr_stmt|;
while|while
condition|(
name|pop
condition|)
block|{
name|stack
operator|.
name|pop
argument_list|()
expr_stmt|;
operator|--
name|pop
expr_stmt|;
block|}
name|line
operator|=
name|list
operator|.
name|readLine
argument_list|()
expr_stmt|;
name|line
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|stack
operator|.
name|push
argument_list|(
name|line
argument_list|)
expr_stmt|;
name|line
operator|=
name|prefix
expr_stmt|;
name|Q_FOREACH
argument_list|(
specifier|const
name|QByteArray
operator|&
name|pathElement
argument_list|,
name|stack
argument_list|)
name|line
operator|+=
name|pathElement
expr_stmt|;
if|if
condition|(
name|line
operator|.
name|endsWith
argument_list|(
literal|'/'
argument_list|)
condition|)
name|QVERIFY
argument_list|(
name|fs
operator|.
name|createDirectory
argument_list|(
name|line
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|QVERIFY
argument_list|(
name|fs
operator|.
name|createFile
argument_list|(
name|line
argument_list|)
argument_list|)
expr_stmt|;
name|line
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|//Use case: music collection - 10 files in 100 directories (albums)
name|QVERIFY
argument_list|(
name|fs
operator|.
name|createDirectory
argument_list|(
name|musicprefix
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
literal|1000
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|i
operator|%
literal|10
operator|)
operator|==
literal|0
condition|)
name|QVERIFY
argument_list|(
name|fs
operator|.
name|createDirectory
argument_list|(
name|QString
argument_list|(
literal|"%1/directory%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|musicprefix
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|/
literal|10
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|qint64
name|size
init|=
name|fs
operator|.
name|createFileWithContent
argument_list|(
name|QString
argument_list|(
literal|"%1/directory%2/file%3"
argument_list|)
operator|.
name|arg
argument_list|(
name|musicprefix
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|/
literal|10
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|size
operator|>
literal|0
argument_list|)
expr_stmt|;
name|musicsize
operator|+=
name|size
expr_stmt|;
block|}
comment|//Use case: photos - 1000 files in 1 directory
name|QVERIFY
argument_list|(
name|fs
operator|.
name|createDirectory
argument_list|(
name|photoprefix
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
literal|1000
condition|;
name|i
operator|++
control|)
block|{
name|qint64
name|size
init|=
name|fs
operator|.
name|createFileWithContent
argument_list|(
name|QString
argument_list|(
literal|"%1/file%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|photoprefix
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|size
operator|>
literal|0
argument_list|)
expr_stmt|;
name|photosize
operator|+=
name|size
expr_stmt|;
block|}
comment|//Use case: source - 10 files in 10 subdirectories in 10 directories (1000 total)
name|QVERIFY
argument_list|(
name|fs
operator|.
name|createDirectory
argument_list|(
name|sourceprefix
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
literal|1000
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|i
operator|%
literal|100
operator|)
operator|==
literal|0
condition|)
name|QVERIFY
argument_list|(
name|fs
operator|.
name|createDirectory
argument_list|(
name|QString
argument_list|(
literal|"%1/directory%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|sourceprefix
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|/
literal|100
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|i
operator|%
literal|10
operator|)
operator|==
literal|0
condition|)
name|QVERIFY
argument_list|(
name|fs
operator|.
name|createDirectory
argument_list|(
name|QString
argument_list|(
literal|"%1/directory%2/subdirectory%3"
argument_list|)
operator|.
name|arg
argument_list|(
name|sourceprefix
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|/
literal|100
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|/
literal|10
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|qint64
name|size
init|=
name|fs
operator|.
name|createFileWithContent
argument_list|(
name|QString
argument_list|(
literal|"%1/directory%2/subdirectory%3/file%4"
argument_list|)
operator|.
name|arg
argument_list|(
name|sourceprefix
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|/
literal|100
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|/
literal|10
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|size
operator|>
literal|0
argument_list|)
expr_stmt|;
name|sourcesize
operator|+=
name|size
expr_stmt|;
block|}
block|}
DECL|function|fileSearch_data
name|void
name|fileSearch_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"nameFilters"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"filter"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"entryCount"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"*.cpp"
argument_list|)
operator|<<
name|QStringList
argument_list|(
literal|"*.cpp"
argument_list|)
operator|<<
name|int
argument_list|(
name|QDir
operator|::
name|Files
argument_list|)
operator|<<
literal|3813
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"executables"
argument_list|)
operator|<<
name|QStringList
argument_list|(
literal|"*"
argument_list|)
operator|<<
name|int
argument_list|(
name|QDir
operator|::
name|Executable
operator||
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|AllDirs
operator||
name|QDir
operator|::
name|NoDotAndDotDot
argument_list|)
operator|<<
literal|543
expr_stmt|;
block|}
DECL|function|fileSearch
name|void
name|fileSearch
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|nameFilters
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|filter
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|entryCount
argument_list|)
expr_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
name|QBENCHMARK
block|{
comment|// Recursive directory iteration
name|QDirIterator
name|iterator
argument_list|(
name|prefix
argument_list|,
name|nameFilters
argument_list|,
name|QDir
operator|::
name|Filter
argument_list|(
name|filter
argument_list|)
argument_list|,
name|QDirIterator
operator|::
name|Subdirectories
operator||
name|QDirIterator
operator|::
name|FollowSymlinks
argument_list|)
decl_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|iterator
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|iterator
operator|.
name|next
argument_list|()
expr_stmt|;
operator|++
name|count
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|count
argument_list|,
name|entryCount
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|count
argument_list|,
name|entryCount
argument_list|)
expr_stmt|;
block|}
DECL|function|traverseDirectory
name|void
name|traverseDirectory
parameter_list|()
specifier|const
block|{
name|int
name|count
init|=
literal|0
decl_stmt|;
name|QBENCHMARK
block|{
name|QDirIterator
name|iterator
argument_list|(
name|prefix
argument_list|,
name|QDir
operator|::
name|AllEntries
operator||
name|QDir
operator|::
name|NoDotAndDotDot
operator||
name|QDir
operator|::
name|Hidden
operator||
name|QDir
operator|::
name|System
argument_list|,
name|QDirIterator
operator|::
name|Subdirectories
operator||
name|QDirIterator
operator|::
name|FollowSymlinks
argument_list|)
decl_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|iterator
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|iterator
operator|.
name|next
argument_list|()
expr_stmt|;
operator|++
name|count
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|count
argument_list|,
literal|11963
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|count
argument_list|,
literal|11963
argument_list|)
expr_stmt|;
block|}
DECL|function|thousandFiles_data
name|void
name|thousandFiles_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"dirName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qint64
argument_list|>
argument_list|(
literal|"expectedSize"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"music"
argument_list|)
operator|<<
name|musicprefix
operator|<<
name|musicsize
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"photos"
argument_list|)
operator|<<
name|photoprefix
operator|<<
name|photosize
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"src"
argument_list|)
operator|<<
name|sourceprefix
operator|<<
name|sourcesize
expr_stmt|;
block|}
DECL|function|thousandFiles
name|void
name|thousandFiles
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|dirName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qint64
argument_list|,
name|expectedSize
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|qint64
name|totalsize
init|=
literal|0
decl_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
name|QDirIterator
name|iter
argument_list|(
name|dirName
argument_list|,
name|QDir
operator|::
name|Files
argument_list|,
name|QDirIterator
operator|::
name|Subdirectories
argument_list|)
decl_stmt|;
while|while
condition|(
name|iter
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|iter
operator|.
name|next
argument_list|()
expr_stmt|;
name|count
operator|++
expr_stmt|;
name|totalsize
operator|+=
name|iter
operator|.
name|fileInfo
argument_list|()
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|count
argument_list|,
literal|1000
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|totalsize
argument_list|,
name|expectedSize
argument_list|)
expr_stmt|;
block|}
block|}
private|private:
DECL|member|fs
name|FileSystem
name|fs
decl_stmt|;
block|}
class|;
end_class
begin_macro
name|QTEST_MAIN
argument_list|(
argument|bench_QDir_tree
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"bench_qdir_tree.moc"
end_include
end_unit
