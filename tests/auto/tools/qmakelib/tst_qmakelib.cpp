begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<ioutils.h>
end_include
begin_include
include|#
directive|include
file|<proitems.h>
end_include
begin_include
include|#
directive|include
file|<qmakevfs.h>
end_include
begin_include
include|#
directive|include
file|<qmakeparser.h>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_using
using|using
namespace|namespace
name|QMakeInternal
namespace|;
end_using
begin_class
DECL|class|tst_qmakelib
class|class
name|tst_qmakelib
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_qmakelib
name|tst_qmakelib
parameter_list|()
block|{}
DECL|function|~tst_qmakelib
specifier|virtual
name|~
name|tst_qmakelib
parameter_list|()
block|{}
private|private
name|slots
private|:
name|void
name|quoteArgUnix_data
parameter_list|()
function_decl|;
name|void
name|quoteArgUnix
parameter_list|()
function_decl|;
name|void
name|quoteArgWin_data
parameter_list|()
function_decl|;
name|void
name|quoteArgWin
parameter_list|()
function_decl|;
name|void
name|pathUtils
parameter_list|()
function_decl|;
name|void
name|proString
parameter_list|()
function_decl|;
name|void
name|proStringList
parameter_list|()
function_decl|;
name|void
name|proParser_data
parameter_list|()
function_decl|;
name|void
name|proParser
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|proString
name|void
name|tst_qmakelib
operator|::
name|proString
parameter_list|()
block|{
name|QString
name|qs1
argument_list|(
name|QStringLiteral
argument_list|(
literal|"this is a string"
argument_list|)
argument_list|)
decl_stmt|;
name|ProString
name|s1
argument_list|(
name|qs1
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|s1
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"this is a string"
argument_list|)
argument_list|)
expr_stmt|;
name|ProString
name|s2
argument_list|(
name|qs1
argument_list|,
literal|5
argument_list|,
literal|8
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|s2
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"is a str"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s2
operator|.
name|hash
argument_list|()
argument_list|,
literal|0x80000000
argument_list|)
expr_stmt|;
name|qHash
argument_list|(
name|s2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s2
operator|.
name|hash
argument_list|()
argument_list|,
literal|90404018U
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s2
operator|.
name|mid
argument_list|(
literal|0
argument_list|,
literal|10
argument_list|)
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"is a str"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s2
operator|.
name|mid
argument_list|(
literal|1
argument_list|,
literal|5
argument_list|)
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"s a s"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s2
operator|.
name|mid
argument_list|(
literal|10
argument_list|,
literal|3
argument_list|)
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|""
argument_list|)
argument_list|)
expr_stmt|;
name|QString
name|qs2
argument_list|(
name|QStringLiteral
argument_list|(
literal|"   spacy  string   "
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|ProString
argument_list|(
name|qs2
argument_list|,
literal|3
argument_list|,
literal|13
argument_list|)
operator|.
name|trimmed
argument_list|()
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"spacy  string"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ProString
argument_list|(
name|qs2
argument_list|,
literal|1
argument_list|,
literal|17
argument_list|)
operator|.
name|trimmed
argument_list|()
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"spacy  string"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|s2
operator|.
name|toQStringRef
argument_list|()
operator|.
name|string
argument_list|()
operator|->
name|isSharedWith
argument_list|(
name|qs1
argument_list|)
argument_list|)
expr_stmt|;
name|s2
operator|.
name|prepend
argument_list|(
name|ProString
argument_list|(
literal|"there "
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s2
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"there is a str"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|s2
operator|.
name|toQStringRef
argument_list|()
operator|.
name|string
argument_list|()
operator|->
name|isSharedWith
argument_list|(
name|qs1
argument_list|)
argument_list|)
expr_stmt|;
name|ProString
name|s3
argument_list|(
literal|"this is a longish string with bells and whistles"
argument_list|)
decl_stmt|;
name|s3
operator|=
name|s3
operator|.
name|mid
argument_list|(
literal|18
argument_list|,
literal|17
argument_list|)
expr_stmt|;
comment|// Prepend to detached string with lots of spare space in it.
name|s3
operator|.
name|prepend
argument_list|(
name|ProString
argument_list|(
literal|"another "
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s3
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"another string with bells"
argument_list|)
argument_list|)
expr_stmt|;
comment|// Note: The string still has plenty of spare space.
name|s3
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s3
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"another string with bells."
argument_list|)
argument_list|)
expr_stmt|;
name|s3
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|" eh?"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s3
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"another string with bells. eh?"
argument_list|)
argument_list|)
expr_stmt|;
name|s3
operator|.
name|append
argument_list|(
name|ProString
argument_list|(
literal|" yeah!"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s3
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"another string with bells. eh? yeah!"
argument_list|)
argument_list|)
expr_stmt|;
name|bool
name|pending
init|=
literal|false
decl_stmt|;
comment|// Not in string, but joining => add space
name|s3
operator|.
name|append
argument_list|(
name|ProString
argument_list|(
literal|"..."
argument_list|)
argument_list|,
operator|&
name|pending
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s3
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"another string with bells. eh? yeah! ..."
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|pending
argument_list|)
expr_stmt|;
name|ProStringList
name|sl1
decl_stmt|;
name|sl1
operator|<<
name|ProString
argument_list|(
literal|""
argument_list|)
operator|<<
name|ProString
argument_list|(
literal|"foo"
argument_list|)
operator|<<
name|ProString
argument_list|(
literal|"barbaz"
argument_list|)
expr_stmt|;
name|ProString
name|s4a
argument_list|(
literal|"hallo"
argument_list|)
decl_stmt|;
name|s4a
operator|.
name|append
argument_list|(
name|sl1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s4a
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"hallo foo barbaz"
argument_list|)
argument_list|)
expr_stmt|;
name|ProString
name|s4b
argument_list|(
literal|"hallo"
argument_list|)
decl_stmt|;
name|pending
operator|=
literal|false
expr_stmt|;
name|s4b
operator|.
name|append
argument_list|(
name|sl1
argument_list|,
operator|&
name|pending
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s4b
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"hallo  foo barbaz"
argument_list|)
argument_list|)
expr_stmt|;
name|ProString
name|s4c
decl_stmt|;
name|pending
operator|=
literal|false
expr_stmt|;
name|s4c
operator|.
name|append
argument_list|(
name|sl1
argument_list|,
operator|&
name|pending
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s4c
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|" foo barbaz"
argument_list|)
argument_list|)
expr_stmt|;
comment|// bizarreness
name|ProString
name|s4d
argument_list|(
literal|"hallo"
argument_list|)
decl_stmt|;
name|pending
operator|=
literal|false
expr_stmt|;
name|s4d
operator|.
name|append
argument_list|(
name|sl1
argument_list|,
operator|&
name|pending
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s4d
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"hallo foo barbaz"
argument_list|)
argument_list|)
expr_stmt|;
name|ProString
name|s4e
decl_stmt|;
name|pending
operator|=
literal|false
expr_stmt|;
name|s4e
operator|.
name|append
argument_list|(
name|sl1
argument_list|,
operator|&
name|pending
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s4e
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"foo barbaz"
argument_list|)
argument_list|)
expr_stmt|;
name|ProStringList
name|sl2
decl_stmt|;
name|sl2
operator|<<
name|ProString
argument_list|(
literal|"foo"
argument_list|)
expr_stmt|;
name|ProString
name|s5
decl_stmt|;
name|s5
operator|.
name|append
argument_list|(
name|sl2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s5
operator|.
name|toQString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"foo"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|s5
operator|.
name|toQStringRef
argument_list|()
operator|.
name|string
argument_list|()
operator|->
name|isSharedWith
argument_list|(
operator|*
name|sl2
operator|.
name|first
argument_list|()
operator|.
name|toQStringRef
argument_list|()
operator|.
name|string
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ProString
argument_list|(
literal|"one"
argument_list|)
operator|+
name|ProString
argument_list|(
literal|" more"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"one more"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|proStringList
name|void
name|tst_qmakelib
operator|::
name|proStringList
parameter_list|()
block|{
name|ProStringList
name|sl1
decl_stmt|;
name|sl1
operator|<<
name|ProString
argument_list|(
literal|"qt"
argument_list|)
operator|<<
name|ProString
argument_list|(
name|QLatin1String
argument_list|(
literal|"is"
argument_list|)
argument_list|)
operator|<<
name|ProString
argument_list|(
name|QStringLiteral
argument_list|(
literal|"uncool"
argument_list|)
argument_list|)
operator|.
name|mid
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sl1
operator|.
name|toQStringList
argument_list|()
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"qt"
operator|<<
literal|"is"
operator|<<
literal|"cool"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sl1
operator|.
name|join
argument_list|(
name|QStringLiteral
argument_list|(
literal|"~~"
argument_list|)
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"qt~~is~~cool"
argument_list|)
argument_list|)
expr_stmt|;
name|ProStringList
name|sl2
decl_stmt|;
name|sl2
operator|<<
name|ProString
argument_list|(
literal|"mostly"
argument_list|)
operator|<<
name|ProString
argument_list|(
literal|"..."
argument_list|)
operator|<<
name|ProString
argument_list|(
literal|"is"
argument_list|)
operator|<<
name|ProString
argument_list|(
literal|"..."
argument_list|)
expr_stmt|;
name|sl1
operator|.
name|insertUnique
argument_list|(
name|sl2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sl1
operator|.
name|toQStringList
argument_list|()
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"qt"
operator|<<
literal|"is"
operator|<<
literal|"cool"
operator|<<
literal|"mostly"
operator|<<
literal|"..."
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sl1
operator|.
name|contains
argument_list|(
literal|"cool"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|sl1
operator|.
name|contains
argument_list|(
literal|"COOL"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sl1
operator|.
name|contains
argument_list|(
literal|"COOL"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|quoteArgUnix_data
name|void
name|tst_qmakelib
operator|::
name|quoteArgUnix_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"in"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"out"
argument_list|)
expr_stmt|;
specifier|static
specifier|const
struct|struct
block|{
specifier|const
name|char
modifier|*
specifier|const
name|in
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|out
decl_stmt|;
block|}
name|vals
index|[]
init|=
block|{
block|{
literal|""
block|,
literal|"''"
block|}
block|,
block|{
literal|"hallo"
block|,
literal|"hallo"
block|}
block|,
block|{
literal|"hallo du"
block|,
literal|"'hallo du'"
block|}
block|,
block|{
literal|"ha'llo"
block|,
literal|"'ha'\\''llo'"
block|}
block|,     }
struct|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|vals
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|vals
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
name|QTest
operator|::
name|newRow
argument_list|(
name|vals
index|[
name|i
index|]
operator|.
name|in
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
name|vals
index|[
name|i
index|]
operator|.
name|in
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
name|vals
index|[
name|i
index|]
operator|.
name|out
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|quoteArgUnix
name|void
name|tst_qmakelib
operator|::
name|quoteArgUnix
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|in
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|out
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|IoUtils
operator|::
name|shellQuoteUnix
argument_list|(
name|in
argument_list|)
argument_list|,
name|out
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|quoteArgWin_data
name|void
name|tst_qmakelib
operator|::
name|quoteArgWin_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"in"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"out"
argument_list|)
expr_stmt|;
specifier|static
specifier|const
struct|struct
block|{
specifier|const
name|char
modifier|*
specifier|const
name|in
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|out
decl_stmt|;
block|}
name|vals
index|[]
init|=
block|{
block|{
literal|""
block|,
literal|"\"\""
block|}
block|,
block|{
literal|"hallo"
block|,
literal|"hallo"
block|}
block|,
block|{
literal|"hallo du"
block|,
literal|"\"hallo du\""
block|}
block|,
block|{
literal|"hallo\\"
block|,
literal|"hallo\\"
block|}
block|,
block|{
literal|"hallo du\\"
block|,
literal|"\"hallo du\\\\\""
block|}
block|,
block|{
literal|"ha\"llo"
block|,
literal|"\"ha\\\"llo^\""
block|}
block|,
block|{
literal|"ha\\\"llo"
block|,
literal|"\"ha\\\\\\\"llo^\""
block|}
block|,     }
struct|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|vals
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|vals
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
name|QTest
operator|::
name|newRow
argument_list|(
name|vals
index|[
name|i
index|]
operator|.
name|in
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
name|vals
index|[
name|i
index|]
operator|.
name|in
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
name|vals
index|[
name|i
index|]
operator|.
name|out
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|quoteArgWin
name|void
name|tst_qmakelib
operator|::
name|quoteArgWin
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|in
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|out
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|IoUtils
operator|::
name|shellQuoteWin
argument_list|(
name|in
argument_list|)
argument_list|,
name|out
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pathUtils
name|void
name|tst_qmakelib
operator|::
name|pathUtils
parameter_list|()
block|{
name|QString
name|afp
init|=
name|QCoreApplication
operator|::
name|applicationFilePath
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|IoUtils
operator|::
name|exists
argument_list|(
name|afp
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|IoUtils
operator|::
name|exists
argument_list|(
name|afp
operator|+
literal|"-tehfail"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|IoUtils
operator|::
name|fileType
argument_list|(
name|afp
argument_list|)
argument_list|,
name|IoUtils
operator|::
name|FileIsRegular
argument_list|)
expr_stmt|;
name|QString
name|adp
init|=
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|IoUtils
operator|::
name|fileType
argument_list|(
name|adp
argument_list|)
argument_list|,
name|IoUtils
operator|::
name|FileIsDir
argument_list|)
expr_stmt|;
name|QString
name|fn0
init|=
literal|"file/path"
decl_stmt|;
name|QVERIFY
argument_list|(
name|IoUtils
operator|::
name|isRelativePath
argument_list|(
name|fn0
argument_list|)
argument_list|)
expr_stmt|;
name|QString
name|fn1
init|=
literal|"/a/unix/file/path"
decl_stmt|;
name|QVERIFY
argument_list|(
name|IoUtils
operator|::
name|isAbsolutePath
argument_list|(
name|fn1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|IoUtils
operator|::
name|pathName
argument_list|(
name|fn1
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"/a/unix/file/"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|IoUtils
operator|::
name|fileName
argument_list|(
name|fn1
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"path"
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QString
name|fn0a
init|=
literal|"c:file/path"
decl_stmt|;
name|QVERIFY
argument_list|(
name|IoUtils
operator|::
name|isRelativePath
argument_list|(
name|fn0a
argument_list|)
argument_list|)
expr_stmt|;
name|QString
name|fn1a
init|=
literal|"c:\\file\\path"
decl_stmt|;
name|QVERIFY
argument_list|(
name|IoUtils
operator|::
name|isAbsolutePath
argument_list|(
name|fn1a
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QString
name|fnbase
init|=
literal|"/another/dir"
decl_stmt|;
name|QCOMPARE
argument_list|(
name|IoUtils
operator|::
name|resolvePath
argument_list|(
name|fnbase
argument_list|,
name|fn0
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"/another/dir/file/path"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|IoUtils
operator|::
name|resolvePath
argument_list|(
name|fnbase
argument_list|,
name|fn1
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"/a/unix/file/path"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QMakeHandler
class|class
name|QMakeHandler
super|:
specifier|public
name|QMakeParserHandler
block|{
public|public:
DECL|function|QMakeHandler
name|QMakeHandler
parameter_list|()
member_init_list|:
name|QMakeParserHandler
argument_list|()
member_init_list|,
name|printed
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|message
specifier|virtual
name|void
name|message
parameter_list|(
name|int
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|msg
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|int
name|lineNo
parameter_list|)
block|{
name|print
argument_list|(
name|fileName
argument_list|,
name|lineNo
argument_list|,
name|type
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
DECL|function|setExpectedMessages
name|void
name|setExpectedMessages
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|msgs
parameter_list|)
block|{
name|expected
operator|=
name|msgs
expr_stmt|;
block|}
DECL|function|expectedMessages
name|QStringList
name|expectedMessages
parameter_list|()
specifier|const
block|{
return|return
name|expected
return|;
block|}
DECL|function|printedMessages
name|bool
name|printedMessages
parameter_list|()
specifier|const
block|{
return|return
name|printed
return|;
block|}
private|private:
DECL|function|print
name|void
name|print
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|int
name|lineNo
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|msg
parameter_list|)
block|{
name|QString
name|pfx
init|=
operator|(
operator|(
name|type
operator|&
name|QMakeParserHandler
operator|::
name|CategoryMask
operator|)
operator|==
name|QMakeParserHandler
operator|::
name|WarningMessage
operator|)
condition|?
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"WARNING: "
argument_list|)
else|:
name|QString
argument_list|()
decl_stmt|;
name|QString
name|out
decl_stmt|;
if|if
condition|(
name|lineNo
condition|)
name|out
operator|=
name|QStringLiteral
argument_list|(
literal|"%1%2:%3: %4"
argument_list|)
operator|.
name|arg
argument_list|(
name|pfx
argument_list|,
name|fileName
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|lineNo
argument_list|)
argument_list|,
name|msg
argument_list|)
expr_stmt|;
else|else
name|out
operator|=
name|QStringLiteral
argument_list|(
literal|"%1%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|pfx
argument_list|,
name|msg
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|expected
operator|.
name|isEmpty
argument_list|()
operator|&&
name|expected
operator|.
name|first
argument_list|()
operator|==
name|out
condition|)
block|{
name|expected
operator|.
name|removeAt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
name|qWarning
argument_list|(
literal|"%s"
argument_list|,
name|qPrintable
argument_list|(
name|out
argument_list|)
argument_list|)
expr_stmt|;
name|printed
operator|=
literal|true
expr_stmt|;
block|}
DECL|member|expected
name|QStringList
name|expected
decl_stmt|;
DECL|member|printed
name|bool
name|printed
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|qmakeHandler
specifier|static
name|QMakeHandler
name|qmakeHandler
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|TokenStream
class|class
name|TokenStream
block|{
public|public:
DECL|function|TokenStream
name|TokenStream
parameter_list|()
block|{}
DECL|function|toString
name|QString
name|toString
parameter_list|()
specifier|const
block|{
return|return
name|ts
return|;
block|}
DECL|function|operator <<
name|TokenStream
modifier|&
name|operator
name|<<
parameter_list|(
name|ushort
name|n
parameter_list|)
block|{
name|ts
operator|+=
name|QChar
argument_list|(
name|n
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator <<
name|TokenStream
modifier|&
name|operator
name|<<
parameter_list|(
name|uint
name|n
parameter_list|)
block|{
name|ts
operator|+=
name|QChar
argument_list|(
name|n
operator|&
literal|0xffff
argument_list|)
expr_stmt|;
name|ts
operator|+=
name|QChar
argument_list|(
name|n
operator|>>
literal|16
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator <<
name|TokenStream
modifier|&
name|operator
name|<<
parameter_list|(
specifier|const
name|QStringRef
modifier|&
name|s
parameter_list|)
block|{
name|ts
operator|+=
name|s
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator <<
name|TokenStream
modifier|&
name|operator
name|<<
parameter_list|(
specifier|const
name|ProString
modifier|&
name|s
parameter_list|)
block|{
return|return
operator|*
name|this
operator|<<
name|ushort
argument_list|(
name|s
operator|.
name|length
argument_list|()
argument_list|)
operator|<<
name|s
operator|.
name|toQStringRef
argument_list|()
return|;
block|}
DECL|function|operator <<
name|TokenStream
modifier|&
name|operator
name|<<
parameter_list|(
specifier|const
name|ProKey
modifier|&
name|s
parameter_list|)
block|{
return|return
operator|*
name|this
operator|<<
name|s
operator|.
name|hash
argument_list|()
operator|<<
name|s
operator|.
name|toString
argument_list|()
return|;
block|}
private|private:
DECL|member|ts
name|QString
name|ts
decl_stmt|;
block|}
class|;
end_class
begin_define
DECL|macro|TS
define|#
directive|define
name|TS
parameter_list|(
name|s
parameter_list|)
value|(TokenStream() s).toString()
end_define
begin_define
DECL|macro|H
define|#
directive|define
name|H
parameter_list|(
name|n
parameter_list|)
value|ushort(n)
end_define
begin_define
DECL|macro|I
define|#
directive|define
name|I
parameter_list|(
name|n
parameter_list|)
value|uint(n)
end_define
begin_define
DECL|macro|S
define|#
directive|define
name|S
parameter_list|(
name|s
parameter_list|)
value|ProString(QString::fromWCharArray(s))
end_define
begin_define
DECL|macro|HS
define|#
directive|define
name|HS
parameter_list|(
name|s
parameter_list|)
value|ProKey(QString::fromWCharArray(s))
end_define
begin_decl_stmt
name|QT_WARNING_PUSH
name|QT_WARNING_DISABLE_MSVC
argument_list|(
literal|4003
argument_list|)
comment|// "not enough actual parameters for macro TS()"
DECL|function|proParser_data
name|void
name|tst_qmakelib
operator|::
name|proParser_data
argument_list|()
argument_list|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"in"
argument_list|)
argument_list|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"out"
argument_list|)
argument_list|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"msgs"
argument_list|)
argument_list|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"ok"
argument_list|)
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty"
argument_list|)
operator|<<
literal|""
operator|<<
name|TS
argument_list|()
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty (whitespace)"
argument_list|)
operator|<<
literal|"  \t   \t"
operator|<<
name|TS
argument_list|()
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
comment|// Variable operators
name|QTest
operator|::
name|newRow
argument_list|(
literal|"assign none"
argument_list|)
operator|<<
literal|"VAR ="
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"append none"
argument_list|)
operator|<<
literal|"VAR +="
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokAppend
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unique append none"
argument_list|)
operator|<<
literal|"VAR *="
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokAppendUnique
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"remove none"
argument_list|)
operator|<<
literal|"VAR -="
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokRemove
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"replace empty"
argument_list|)
operator|<<
literal|"VAR ~="
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokReplace
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"assignment without variable"
argument_list|)
operator|<<
literal|"="
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*     4 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Assignment needs exactly one word on the left hand side."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"assignment with multiple variables"
argument_list|)
operator|<<
literal|"VAR VAR ="
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*     4 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Assignment needs exactly one word on the left hand side."
operator|<<
literal|false
argument_list|;
comment|// Values
DECL|macro|ASSIGN_VAR
define|#
directive|define
name|ASSIGN_VAR
parameter_list|(
name|h
parameter_list|)
define|\
value|H(TokLine)<< H(1) \<< H(TokHashLiteral)<< HS(L"VAR") \<< H(TokAssign)<< H(h)
name|QTest
operator|::
name|newRow
argument_list|(
literal|"one literal"
argument_list|)
operator|<<
literal|"VAR = val"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"val"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"one literal (squeezed)"
argument_list|)
operator|<<
literal|"VAR=val"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"val"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"many literals"
argument_list|)
operator|<<
literal|"VAR = foo barbaz bak hello"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|4
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"barbaz"
argument_list|)
comment|/*    24 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"bak"
argument_list|)
comment|/*    29 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"hello"
argument_list|)
comment|/*    36 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"many literals (tab-separated"
argument_list|)
operator|<<
literal|"VAR\t=\tfoo\tbarbaz\tbak\thello"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|4
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"barbaz"
argument_list|)
comment|/*    24 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"bak"
argument_list|)
comment|/*    29 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"hello"
argument_list|)
comment|/*    36 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"one quoted literal"
argument_list|)
operator|<<
literal|"VAR = \"val ue\""
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"val ue"
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"quoted literal with missing quote"
argument_list|)
operator|<<
literal|"VAR = val \"ue"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Missing closing \" quote"
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"many quoted literals"
argument_list|)
operator|<<
literal|"VAR = \"foo\" barbaz    'bak hello' \"\""
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|3
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"barbaz"
argument_list|)
comment|/*    24 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"bak hello"
argument_list|)
comment|/*    35 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"many quoted literals (with tabs)"
argument_list|)
operator|<<
literal|"VAR\t=\t\"foo\"\tbarbaz\t'bak\thello'"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|3
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"barbaz"
argument_list|)
comment|/*    24 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"bak\thello"
argument_list|)
comment|/*    35 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"quoted and unquoted spaces"
argument_list|)
operator|<<
literal|"  VAR = \"val ue   \"   "
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"val ue   "
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"funny literals"
argument_list|)
operator|<<
literal|"VAR = foo:bar|!baz(blam!, ${foo})"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|2
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo:bar|!baz(blam!,"
argument_list|)
comment|/*    32 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"${foo})"
argument_list|)
comment|/*    41 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"literals with escapes"
argument_list|)
operator|<<
literal|"VAR = \\{hi\\} \\[ho\\] \\)uh\\( \"\\\\oh\\$\"\\' \\$\\${FOO}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|5
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"{hi}"
argument_list|)
comment|/*    17 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"[ho]"
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L")uh("
argument_list|)
comment|/*    29 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"\\oh$'"
argument_list|)
comment|/*    36 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"$${FOO}"
argument_list|)
comment|/*    45 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"magic variables"
argument_list|)
operator|<<
literal|"VAR = $$LITERAL_HASH $$LITERAL_DOLLAR $$LITERAL_WHITESPACE $$_FILE_ $$_LINE_"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|5
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"#"
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"$"
argument_list|)
comment|/*    17 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"\t"
argument_list|)
comment|/*    20 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"in"
argument_list|)
comment|/*    24 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"1"
argument_list|)
comment|/*    27 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"continuations and comments"
argument_list|)
operator|<<
literal|"VAR = foo \\\n  bar\n  \n"
literal|"GAR = foo \\ # comment\n  bar \\\n   # comment\n baz \\\n"
literal|"\"quoted \\ #comment\n    escape\" \\\n    right\\\n      after \\\n    gorilla!\n \n\n"
literal|"MOO = \\\n  kuh # comment\nLOO =\n\n"
literal|"FOO = bar \\\n# comment\n   baz \\\n    \n# comment\n"
literal|"GAZ="
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    21 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|4
argument_list|)
comment|/*    24 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"GAR"
argument_list|)
comment|/*    31 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|7
argument_list|)
comment|/*    33 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    38 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    43 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"baz"
argument_list|)
comment|/*    48 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"quoted  escape"
argument_list|)
comment|/*    64 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"right"
argument_list|)
comment|/*    71 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"after"
argument_list|)
comment|/*    78 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"gorilla!"
argument_list|)
comment|/*    88 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    89 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|15
argument_list|)
comment|/*    91 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"MOO"
argument_list|)
comment|/*    98 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*   100 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"kuh"
argument_list|)
comment|/*   105 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*   106 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|17
argument_list|)
comment|/*   108 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"LOO"
argument_list|)
comment|/*   115 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*   117 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*   118 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|19
argument_list|)
comment|/*   120 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"FOO"
argument_list|)
comment|/*   127 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*   129 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"bar"
argument_list|)
comment|/*   134 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"baz"
argument_list|)
comment|/*   139 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*   140 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|24
argument_list|)
comment|/*   142 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"GAZ"
argument_list|)
comment|/*   149 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*   151 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"accidental continuation"
argument_list|)
operator|<<
literal|"VAR0 = \\\n    this \\\n    is \\\n    ok\n"
literal|"VAR1 = \\\n    this \\\n    is=still \\\n    ok\n"
literal|"VAR2 = \\\n    this \\\n    is \\\n"
literal|"VAR3 = \\\n    not ok\n"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR0"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|3
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"this"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"is"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"ok"
argument_list|)
comment|/*    26 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    27 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|5
argument_list|)
comment|/*    29 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR1"
argument_list|)
comment|/*    37 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|3
argument_list|)
comment|/*    39 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"this"
argument_list|)
comment|/*    45 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"is=still"
argument_list|)
comment|/*    55 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"ok"
argument_list|)
comment|/*    59 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    60 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|9
argument_list|)
comment|/*    62 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR2"
argument_list|)
comment|/*    70 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|6
argument_list|)
comment|/*    72 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"this"
argument_list|)
comment|/*    78 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"is"
argument_list|)
comment|/*    82 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"VAR3"
argument_list|)
comment|/*    88 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"="
argument_list|)
comment|/*    91 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"not"
argument_list|)
comment|/*    96 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"ok"
argument_list|)
comment|/*   100 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|"WARNING: in:12: Possible accidental line continuation"
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"plain variable expansion"
argument_list|)
operator|<<
literal|"VAR = $$bar"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"braced variable expansion"
argument_list|)
operator|<<
literal|"VAR = $${foo/bar}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo/bar"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"bogus variable expansion"
argument_list|)
operator|<<
literal|"VAR = $$  "
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L""
argument_list|)
comment|/*    15 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|"WARNING: in:1: Missing name in expansion"
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"bogus braced variable expansion"
argument_list|)
operator|<<
literal|"VAR = $${}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L""
argument_list|)
comment|/*    15 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|"WARNING: in:1: Missing name in expansion"
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unterminated braced variable expansion"
argument_list|)
operator|<<
literal|"VAR = $${FOO"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"FOO"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Missing } terminator [found end-of-line]"
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"invalid identifier in braced variable expansion"
argument_list|)
operator|<<
literal|"VAR = $${FOO/BAR+BAZ}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"FOO/BAR"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokLiteral
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"+BAZ"
argument_list|)
comment|/*    28 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Missing } terminator [found +]"
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"property expansion"
argument_list|)
operator|<<
literal|"VAR = $$[bar]"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokProperty
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"environment expansion"
argument_list|)
operator|<<
literal|"VAR = $$(bar)"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokEnvVar
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"plain function call"
argument_list|)
operator|<<
literal|"VAR = $$bar()"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokFuncName
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"braced function call"
argument_list|)
operator|<<
literal|"VAR = $${bar()}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokFuncName
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"function call with one argument"
argument_list|)
operator|<<
literal|"VAR = $$bar(blubb)"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokFuncName
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"blubb"
argument_list|)
comment|/*    25 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
comment|/*    26 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"function call with multiple arguments"
argument_list|)
operator|<<
literal|"VAR = $$bar(  blubb blubb, hey  ,$$you)"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokFuncName
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"blubb"
argument_list|)
comment|/*    25 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"blubb"
argument_list|)
comment|/*    32 */
operator|<<
name|H
argument_list|(
name|TokArgSeparator
argument_list|)
comment|/*    33 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"hey"
argument_list|)
comment|/*    38 */
operator|<<
name|H
argument_list|(
name|TokArgSeparator
argument_list|)
comment|/*    39 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"you"
argument_list|)
comment|/*    46 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
comment|/*    47 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"nested function call"
argument_list|)
operator|<<
literal|"VAR = $$foo(yo, $$bar(blubb))"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokFuncName
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"yo"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokArgSeparator
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokFuncName
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    30 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"blubb"
argument_list|)
comment|/*    37 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
comment|/*    38 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
comment|/*    39 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
comment|// This is a rather questionable "feature"
name|QTest
operator|::
name|newRow
argument_list|(
literal|"function call with parenthesized argument"
argument_list|)
operator|<<
literal|"VAR = $$bar(blubb (yo, man) blabb, nope)"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokFuncName
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"blubb"
argument_list|)
comment|/*    25 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"(yo,"
argument_list|)
comment|/*    31 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"man)"
argument_list|)
comment|/*    37 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"blabb"
argument_list|)
comment|/*    44 */
operator|<<
name|H
argument_list|(
name|TokArgSeparator
argument_list|)
comment|/*    45 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"nope"
argument_list|)
comment|/*    51 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
comment|/*    52 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"separate literal and expansion"
argument_list|)
operator|<<
literal|"VAR = foo $$bar"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|2
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"separate expansion and literal"
argument_list|)
operator|<<
literal|"VAR = $$bar foo"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"joined literal and expansion"
argument_list|)
operator|<<
literal|"VAR = foo$$bar"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokVariable
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"joined expansion and literal"
argument_list|)
operator|<<
literal|"VAR = $${bar}foo"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokLiteral
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"plain variable expansion with funny name and literal"
argument_list|)
operator|<<
literal|"VAR = $$az_AZ_09.dot/nix"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"az_AZ_09.dot"
argument_list|)
comment|/*    27 */
operator|<<
name|H
argument_list|(
name|TokLiteral
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"/nix"
argument_list|)
comment|/*    33 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"braced variable expansion with funny name"
argument_list|)
operator|<<
literal|"VAR = $${az_AZ_09.dot/nix}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"az_AZ_09.dot/nix"
argument_list|)
comment|/*    31 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"quoted joined literal and expansion"
argument_list|)
operator|<<
literal|"VAR = 'foo$$bar'"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|ASSIGN_VAR
argument_list|(
literal|0
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokQuoted
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"assignment with expansion in variable name"
argument_list|)
operator|<<
literal|"VAR$$EXTRA ="
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokVariable
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"EXTRA"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    20 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
comment|// Conditionals ("Tests")
name|QTest
operator|::
name|newRow
argument_list|(
literal|"one test"
argument_list|)
operator|<<
literal|"foo"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"wildcard-test"
argument_list|)
operator|<<
literal|"foo-*"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo-*"
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
comment|// This is a rather questionable "feature"
name|QTest
operator|::
name|newRow
argument_list|(
literal|"one quoted test"
argument_list|)
operator|<<
literal|"\"foo\""
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"two tests"
argument_list|)
operator|<<
literal|"foo\nbar"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"bogus two tests"
argument_list|)
operator|<<
literal|"foo bar\nbaz"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: Extra characters after test expression."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-AND-test"
argument_list|)
operator|<<
literal|"foo:bar"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokAnd
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-OR-test"
argument_list|)
operator|<<
literal|"  foo  | bar "
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokOr
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NOT-test"
argument_list|)
operator|<<
literal|"!foo"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokNot
argument_list|)
comment|/*     3 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NOT-NOT-test"
argument_list|)
operator|<<
literal|"!!foo"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
comment|// This is a rather questionable "feature"
name|QTest
operator|::
name|newRow
argument_list|(
literal|"quoted-NOT-test"
argument_list|)
operator|<<
literal|"\"!foo\""
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokNot
argument_list|)
comment|/*     3 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
comment|// This is a rather questionable "feature"
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NOT-quoted-test"
argument_list|)
operator|<<
literal|"!\"foo\""
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokNot
argument_list|)
comment|/*     3 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-AND-NOT-test"
argument_list|)
operator|<<
literal|"foo:!bar"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokAnd
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokNot
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-assignment"
argument_list|)
operator|<<
literal|"foo\nVAR="
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    21 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-AND-assignment"
argument_list|)
operator|<<
literal|"foo: VAR ="
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    11 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|11
argument_list|)
comment|/*    13 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*    20 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    24 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-else-test"
argument_list|)
operator|<<
literal|"foo\nelse: bar"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    11 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*    13 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|11
argument_list|)
comment|/*    15 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    17 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    24 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    25 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"function-else-test"
argument_list|)
operator|<<
literal|"foo()\nelse: bar"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*    14 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|11
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    25 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    26 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-AND-test-else-test"
argument_list|)
operator|<<
literal|"foo:bar\nelse: baz"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokAnd
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    20 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*    22 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|11
argument_list|)
comment|/*    24 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    26 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"baz"
argument_list|)
comment|/*    33 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    34 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-AND-test-else-test-else-test-function"
argument_list|)
operator|<<
literal|"foo:bar\nelse: baz\nelse: bak\nbuzz()"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokAnd
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    20 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*    22 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|27
argument_list|)
comment|/*    24 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    26 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"baz"
argument_list|)
comment|/*    33 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    34 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    35 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*    37 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|11
argument_list|)
comment|/*    39 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|3
argument_list|)
comment|/*    41 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bak"
argument_list|)
comment|/*    48 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    49 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    50 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    51 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|4
argument_list|)
comment|/*    53 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"buzz"
argument_list|)
comment|/*    61 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    62 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-assignment-else-assignment"
argument_list|)
operator|<<
literal|"foo: VAR =\nelse: VAR="
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    11 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|11
argument_list|)
comment|/*    13 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*    20 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    24 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|13
argument_list|)
comment|/*    26 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    28 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*    35 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    37 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    38 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-else-test-assignment"
argument_list|)
operator|<<
literal|"foo\nelse: bar: VAR ="
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    11 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*    13 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|27
argument_list|)
comment|/*    15 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    17 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    24 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    25 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    26 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|11
argument_list|)
comment|/*    28 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*    35 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    37 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    38 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    39 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*    41 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"one function"
argument_list|)
operator|<<
literal|"foo()"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"one function (with spaces)"
argument_list|)
operator|<<
literal|" foo(  ) "
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unterminated function call"
argument_list|)
operator|<<
literal|"foo(\nfoo"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: Missing closing parenthesis in function call"
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"function with arguments"
argument_list|)
operator|<<
literal|"foo(blah, hi ho)"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"blah"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokArgSeparator
argument_list|)
comment|/*    17 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"hi"
argument_list|)
comment|/*    21 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"ho"
argument_list|)
comment|/*    25 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"function with empty arguments"
argument_list|)
operator|<<
literal|"foo(,)"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokArgSeparator
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"function with funny arguments"
argument_list|)
operator|<<
literal|"foo(blah\\, \"hi ,  \\ho\" ,uh\\  ,\\oh  ,,   )"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"blah\\"
argument_list|)
comment|/*    17 */
operator|<<
name|H
argument_list|(
name|TokArgSeparator
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"hi ,  \\ho"
argument_list|)
comment|/*    29 */
operator|<<
name|H
argument_list|(
name|TokArgSeparator
argument_list|)
comment|/*    30 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"uh\\"
argument_list|)
comment|/*    35 */
operator|<<
name|H
argument_list|(
name|TokArgSeparator
argument_list|)
comment|/*    36 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"\\oh"
argument_list|)
comment|/*    41 */
operator|<<
name|H
argument_list|(
name|TokArgSeparator
argument_list|)
comment|/*    42 */
operator|<<
name|H
argument_list|(
name|TokArgSeparator
argument_list|)
comment|/*    43 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
argument_list|)
operator|<<
literal|"WARNING: in:1: Unescaped backslashes are deprecated\n"
literal|"WARNING: in:1: Unescaped backslashes are deprecated\n"
literal|"WARNING: in:1: Unescaped backslashes are deprecated\n"
literal|"WARNING: in:1: Unescaped backslashes are deprecated"
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"function with nested call"
argument_list|)
operator|<<
literal|"foo($$blah(hi ho))"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokFuncName
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"blah"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"hi"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"ho"
argument_list|)
comment|/*    26 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
comment|/*    27 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"stand-alone parentheses"
argument_list|)
operator|<<
literal|"()"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*     3 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Opening parenthesis without prior test name."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"bogus test and function"
argument_list|)
operator|<<
literal|"foo bar()"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*     3 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Extra characters after test expression."
operator|<<
literal|false
argument_list|;
comment|// This is a rather questionable "feature"
name|QTest
operator|::
name|newRow
argument_list|(
literal|"two functions"
argument_list|)
operator|<<
literal|"foo() bar()"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"function-AND-test"
argument_list|)
operator|<<
literal|"foo():bar"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokAnd
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-AND-function"
argument_list|)
operator|<<
literal|"foo:bar()"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokAnd
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    18 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NOT-function-AND-test"
argument_list|)
operator|<<
literal|"!foo():bar"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokNot
argument_list|)
comment|/*     3 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokAnd
argument_list|)
comment|/*    13 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    20 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-AND-NOT-function"
argument_list|)
operator|<<
literal|"foo:!bar()"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"foo"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokAnd
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokNot
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|/*    20 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
comment|// Control statements
name|QTest
operator|::
name|newRow
argument_list|(
literal|"for(VAR, LIST) loop"
argument_list|)
operator|<<
literal|"for(VAR, LIST)"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokForLoop
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*     9 */
comment|/* iterator */
operator|<<
name|I
argument_list|(
literal|7
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"LIST"
argument_list|)
comment|/*    17 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    18 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    20 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"for(ever) loop"
argument_list|)
operator|<<
literal|"for(ever)"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokForLoop
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L""
argument_list|)
comment|/*     6 */
comment|/* iterator */
operator|<<
name|I
argument_list|(
literal|9
argument_list|)
comment|/*     8 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"ever"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    17 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
comment|// This is a rather questionable "feature"
name|QTest
operator|::
name|newRow
argument_list|(
literal|"for($$blub) loop"
argument_list|)
operator|<<
literal|"for($$blub)"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokForLoop
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L""
argument_list|)
comment|/*     6 */
comment|/* iterator */
operator|<<
name|I
argument_list|(
literal|9
argument_list|)
comment|/*     8 */
operator|<<
name|H
argument_list|(
name|TokVariable
operator||
name|TokNewStr
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"blub"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    17 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-for-test-else-test"
argument_list|)
operator|<<
literal|"true:for(VAR, LIST): true\nelse: true"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|31
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokForLoop
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*    21 */
comment|/* iterator */
operator|<<
name|I
argument_list|(
literal|7
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"LIST"
argument_list|)
comment|/*    29 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    30 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|12
argument_list|)
comment|/*    32 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*    34 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    42 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    43 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    44 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    45 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|12
argument_list|)
comment|/*    47 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    49 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    57 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    58 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"next()"
argument_list|)
operator|<<
literal|"for(ever): next()"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokForLoop
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L""
argument_list|)
comment|/*     6 */
comment|/* iterator */
operator|<<
name|I
argument_list|(
literal|9
argument_list|)
comment|/*     8 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"ever"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    17 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|4
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*    21 */
operator|<<
name|H
argument_list|(
name|TokNext
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"break()"
argument_list|)
operator|<<
literal|"for(ever): break()"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokForLoop
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L""
argument_list|)
comment|/*     6 */
comment|/* iterator */
operator|<<
name|I
argument_list|(
literal|9
argument_list|)
comment|/*     8 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"ever"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    17 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|4
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*    21 */
operator|<<
name|H
argument_list|(
name|TokBreak
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"top-level return()"
argument_list|)
operator|<<
literal|"return()"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokReturn
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"else"
argument_list|)
operator|<<
literal|"else"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: Unexpected 'else'."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-{else}"
argument_list|)
operator|<<
literal|"test { else }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    15 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Unexpected 'else'."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defineTest-{else}"
argument_list|)
operator|<<
literal|"defineTest(fn) { else }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokTestDef
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"fn"
argument_list|)
comment|/*     8 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Unexpected 'else'."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"for-else"
argument_list|)
operator|<<
literal|"for(ever) { else }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokForLoop
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L""
argument_list|)
comment|/*     6 */
comment|/* iterator */
operator|<<
name|I
argument_list|(
literal|9
argument_list|)
comment|/*     8 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"ever"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    17 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Unexpected 'else'."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"double-test-else"
argument_list|)
operator|<<
literal|"foo bar\nelse"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*     1 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*     3 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|// This seems weird
comment|/*     5 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Extra characters after test expression."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-function-else"
argument_list|)
operator|<<
literal|"foo bar()\nelse"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokTestCall
argument_list|)
comment|// This seems pointless
comment|/*     3 */
operator|<<
name|H
argument_list|(
name|TokFuncTerminator
argument_list|)
comment|/*     4 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*     5 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*     7 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|// This seems weird
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Extra characters after test expression."
operator|<<
literal|false
argument_list|;
comment|// Braces
name|QTest
operator|::
name|newRow
argument_list|(
literal|"{}"
argument_list|)
operator|<<
literal|"{ }"
operator|<<
name|TS
argument_list|()
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"{}-newlines"
argument_list|)
operator|<<
literal|"\n\n{ }\n\n"
operator|<<
name|TS
argument_list|()
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"{"
argument_list|)
operator|<<
literal|"{"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:2: Missing closing brace(s)."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test {"
argument_list|)
operator|<<
literal|"test {"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    15 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|"in:2: Missing closing brace(s)."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"}"
argument_list|)
operator|<<
literal|"}"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: Excess closing brace."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"{test}"
argument_list|)
operator|<<
literal|"{ true }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"{test-newlines}"
argument_list|)
operator|<<
literal|"{\ntrue\n}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"{assignment-test}-test"
argument_list|)
operator|<<
literal|"{ VAR = { foo } bar } true"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|4
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"{"
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"}"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    27 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    28 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    36 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"assignment with excess opening brace"
argument_list|)
operator|<<
literal|"VAR = { { foo }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*     9 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|4
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"{"
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"{"
argument_list|)
comment|/*    17 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"}"
argument_list|)
comment|/*    25 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
argument_list|)
operator|<<
literal|"WARNING: in:1: Possible braces mismatch"
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-{}"
argument_list|)
operator|<<
literal|"true {}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    15 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-{newlines}"
argument_list|)
operator|<<
literal|"true {\n}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    15 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-{test}"
argument_list|)
operator|<<
literal|"true { true }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|10
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    24 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test:-{test}"
argument_list|)
operator|<<
literal|"true: { true }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|10
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    24 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|"WARNING: in:1: Excess colon in front of opening brace."
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-{test-newlines}"
argument_list|)
operator|<<
literal|"true {\ntrue\n}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|12
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    24 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    25 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    26 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test:-{test-newlines}"
argument_list|)
operator|<<
literal|"true: {\ntrue\n}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|12
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    24 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    25 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    26 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|"WARNING: in:1: Excess colon in front of opening brace."
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-{assignment}"
argument_list|)
operator|<<
literal|"true { VAR = {foo} }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|18
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*    21 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"{foo}"
argument_list|)
comment|/*    30 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    31 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    32 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-{test-assignment}"
argument_list|)
operator|<<
literal|"true { true: VAR = {foo} }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|33
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    24 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|18
argument_list|)
comment|/*    26 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*    33 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    35 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"{foo}"
argument_list|)
comment|/*    42 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    43 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    44 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*    46 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    47 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-{assignment-newlines}"
argument_list|)
operator|<<
literal|"true {\nVAR = {foo}\n}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|20
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokAssign
argument_list|)
operator|<<
name|H
argument_list|(
literal|0
argument_list|)
comment|/*    25 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"{foo}"
argument_list|)
comment|/*    32 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    33 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    34 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-{}-else-test-{}"
argument_list|)
operator|<<
literal|"true {} else: true {}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    15 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|18
argument_list|)
comment|/*    17 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    27 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    28 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    29 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    31 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    32 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*    34 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-{}-else-test-{}-newlines"
argument_list|)
operator|<<
literal|"true {\n}\nelse: true {\n}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    15 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|18
argument_list|)
comment|/*    17 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|3
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    27 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    28 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    29 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    31 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    32 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*    34 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-{test}-else-test-{}-newlines"
argument_list|)
operator|<<
literal|"true {\ntrue\n}\nelse: true {\n}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|12
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    24 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    25 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    26 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|18
argument_list|)
comment|/*    28 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|4
argument_list|)
comment|/*    30 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    38 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    39 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    40 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    42 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    43 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*    45 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"for-{next}"
argument_list|)
operator|<<
literal|"for(ever) { next() }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokForLoop
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L""
argument_list|)
comment|/*     6 */
comment|/* iterator */
operator|<<
name|I
argument_list|(
literal|9
argument_list|)
comment|/*     8 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"ever"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    17 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|4
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*    21 */
operator|<<
name|H
argument_list|(
name|TokNext
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"for:-{next}"
argument_list|)
operator|<<
literal|"for(ever): { next() }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokForLoop
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L""
argument_list|)
comment|/*     6 */
comment|/* iterator */
operator|<<
name|I
argument_list|(
literal|9
argument_list|)
comment|/*     8 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"ever"
argument_list|)
comment|/*    16 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    17 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|4
argument_list|)
comment|/*    19 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*    21 */
operator|<<
name|H
argument_list|(
name|TokNext
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|"WARNING: in:1: Excess colon in front of opening brace."
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-for-{test-else-test-newlines}"
argument_list|)
operator|<<
literal|"true:for(VAR, LIST) {\ntrue\nelse: true\n}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|48
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokForLoop
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*    21 */
comment|/* iterator */
operator|<<
name|I
argument_list|(
literal|7
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"LIST"
argument_list|)
comment|/*    29 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    30 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|29
argument_list|)
comment|/*    32 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    34 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    42 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    43 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    44 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*    46 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|12
argument_list|)
comment|/*    48 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|3
argument_list|)
comment|/*    50 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    58 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    59 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    60 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    61 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    62 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-for-{test-else-test}"
argument_list|)
operator|<<
literal|"true:for(VAR, LIST) { true\nelse: true }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|48
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokForLoop
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"VAR"
argument_list|)
comment|/*    21 */
comment|/* iterator */
operator|<<
name|I
argument_list|(
literal|7
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"LIST"
argument_list|)
comment|/*    29 */
operator|<<
name|H
argument_list|(
name|TokValueTerminator
argument_list|)
comment|/*    30 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|29
argument_list|)
comment|/*    32 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*    34 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    42 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    43 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    44 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
comment|/*    46 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|12
argument_list|)
comment|/*    48 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|2
argument_list|)
comment|/*    50 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"true"
argument_list|)
comment|/*    58 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    59 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    60 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    61 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    62 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
comment|// Custom functions
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defineTest-{newlines}"
argument_list|)
operator|<<
literal|"defineTest(test) {\n}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokTestDef
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defineTest:-test"
argument_list|)
operator|<<
literal|"defineTest(test): test"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokTestDef
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|12
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defineTest-{test}"
argument_list|)
operator|<<
literal|"defineTest(test) { test }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokTestDef
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|12
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defineTest-{return}"
argument_list|)
operator|<<
literal|"defineTest(test) { return() }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokTestDef
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|4
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokReturn
argument_list|)
comment|/*    15 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defineReplace-{return-stuff}"
argument_list|)
operator|<<
literal|"defineReplace(stuff) { return(foo bar) }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokReplaceDef
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"stuff"
argument_list|)
comment|/*    11 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|14
argument_list|)
comment|/*    13 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*    15 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"foo"
argument_list|)
comment|/*    20 */
operator|<<
name|H
argument_list|(
name|TokLiteral
operator||
name|TokNewStr
argument_list|)
operator|<<
name|S
argument_list|(
literal|L"bar"
argument_list|)
comment|/*    25 */
operator|<<
name|H
argument_list|(
name|TokReturn
argument_list|)
comment|/*    26 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-AND-defineTest-{}"
argument_list|)
operator|<<
literal|"test: defineTest(test) {}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokAnd
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokTestDef
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    20 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-OR-defineTest-{}"
argument_list|)
operator|<<
literal|"test| defineTest(test) {}"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokOr
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokTestDef
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    20 */
comment|/* body */
operator|<<
name|I
argument_list|(
literal|1
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
comment|// Operator abuse
name|QTest
operator|::
name|newRow
argument_list|(
literal|"!"
argument_list|)
operator|<<
literal|""
operator|<<
name|TS
argument_list|()
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"|"
argument_list|)
operator|<<
literal|""
operator|<<
name|TS
argument_list|()
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|":"
argument_list|)
operator|<<
literal|""
operator|<<
name|TS
argument_list|()
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NOT-assignment"
argument_list|)
operator|<<
literal|"!VAR ="
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: Unexpected NOT operator in front of assignment."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NOT-{}"
argument_list|)
operator|<<
literal|"!{}"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: Unexpected NOT operator in front of opening brace."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NOT-else"
argument_list|)
operator|<<
literal|"test\n!else {}"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:2: Unexpected NOT operator in front of else."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NOT-for-{}"
argument_list|)
operator|<<
literal|"!for(ever) {}"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: Unexpected NOT operator in front of for()."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NOT-defineTest-{}"
argument_list|)
operator|<<
literal|"!defineTest(test) {}"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: Unexpected NOT operator in front of function definition."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"AND-test"
argument_list|)
operator|<<
literal|":test"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|"in:1: AND operator without prior condition."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-AND-else"
argument_list|)
operator|<<
literal|"test:else"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Unexpected AND operator in front of else."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-AND-AND-test"
argument_list|)
operator|<<
literal|"test::test"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokAnd
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    20 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|"WARNING: in:1: Stray AND operator in front of AND operator."
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-AND-OR-test"
argument_list|)
operator|<<
literal|"test:|test"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokOr
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    20 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|"WARNING: in:1: Stray AND operator in front of OR operator."
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-{AND-test}"
argument_list|)
operator|<<
literal|"test { :test }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|10
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    24 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|"in:1: AND operator without prior condition."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-OR-assignment"
argument_list|)
operator|<<
literal|"foo| VAR ="
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: Unexpected OR operator in front of assignment."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-OR-{}"
argument_list|)
operator|<<
literal|"foo|{}"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: Unexpected OR operator in front of opening brace."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-OR-for"
argument_list|)
operator|<<
literal|"foo|for(ever) {}"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: Unexpected OR operator in front of for()."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"OR-test"
argument_list|)
operator|<<
literal|"|test"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|"in:1: OR operator without prior condition."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-OR-else"
argument_list|)
operator|<<
literal|"test|else"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|"in:1: Unexpected OR operator in front of else."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-OR-OR-test"
argument_list|)
operator|<<
literal|"test||test"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokOr
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    20 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|"WARNING: in:1: Stray OR operator in front of OR operator."
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-OR-AND-test"
argument_list|)
operator|<<
literal|"test|:test"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokAnd
argument_list|)
comment|/*    12 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    20 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
argument_list|)
operator|<<
literal|"WARNING: in:1: Stray OR operator in front of AND operator."
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test-{OR-test}"
argument_list|)
operator|<<
literal|"test { |test }"
operator|<<
name|TS
argument_list|(
comment|/*     0 */
operator|<<
name|H
argument_list|(
name|TokLine
argument_list|)
operator|<<
name|H
argument_list|(
literal|1
argument_list|)
comment|/*     2 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    10 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    11 */
operator|<<
name|H
argument_list|(
name|TokBranch
argument_list|)
comment|/*    12 */
comment|/* then branch */
operator|<<
name|I
argument_list|(
literal|10
argument_list|)
comment|/*    14 */
operator|<<
name|H
argument_list|(
name|TokHashLiteral
argument_list|)
operator|<<
name|HS
argument_list|(
literal|L"test"
argument_list|)
comment|/*    22 */
operator|<<
name|H
argument_list|(
name|TokCondition
argument_list|)
comment|/*    23 */
operator|<<
name|H
argument_list|(
name|TokTerminator
argument_list|)
comment|/*    24 */
comment|/* else branch */
operator|<<
name|I
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|"in:1: OR operator without prior condition."
operator|<<
literal|false
argument_list|;
comment|// option() (these produce no tokens)
name|QTest
operator|::
name|newRow
argument_list|(
literal|"option(host_build)"
argument_list|)
operator|<<
literal|"option(host_build)"
operator|<<
name|TS
argument_list|()
operator|<<
literal|""
operator|<<
literal|true
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"option()"
argument_list|)
operator|<<
literal|"option()"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: option() requires one literal argument."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"option(host_build magic)"
argument_list|)
operator|<<
literal|"option(host_build magic)"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: option() requires one literal argument."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"option(host_build, magic)"
argument_list|)
operator|<<
literal|"option(host_build, magic)"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: option() requires one literal argument."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"option($$OPTION)"
argument_list|)
operator|<<
literal|"option($$OPTION)"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: option() requires one literal argument."
operator|<<
literal|false
argument_list|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"{option(host_build)}"
argument_list|)
operator|<<
literal|"{option(host_build)}"
operator|<<
name|TS
argument_list|()
operator|<<
literal|"in:1: option() must appear outside any control structures."
operator|<<
literal|false
argument_list|; }
name|QT_WARNING_POP
DECL|function|proParser
name|void
name|tst_qmakelib
operator|::
name|proParser
argument_list|()
argument_list|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|in
argument_list|)
argument_list|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|out
argument_list|)
argument_list|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|msgs
argument_list|)
argument_list|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|ok
argument_list|)
argument_list|;
name|bool
name|verified
operator|=
literal|true
argument_list|;
name|QMakeHandler
name|handler
argument_list|;
name|handler
operator|.
name|setExpectedMessages
argument_list|(
name|msgs
operator|.
name|split
argument_list|(
literal|'\n'
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
argument_list|)
argument_list|;
name|QMakeVfs
name|vfs
argument_list|;
name|QMakeParser
name|parser
argument_list|(
literal|0
argument_list|,
operator|&
name|vfs
argument_list|,
operator|&
name|handler
argument_list|)
argument_list|;
name|ProFile
operator|*
name|pro
operator|=
name|parser
operator|.
name|parsedProBlock
argument_list|(
name|in
argument_list|,
literal|"in"
argument_list|,
literal|1
argument_list|,
name|QMakeParser
operator|::
name|FullGrammar
argument_list|)
argument_list|;     if
operator|(
name|handler
operator|.
name|printedMessages
argument_list|()
operator|)
block|{
name|qWarning
argument_list|(
literal|"Got unexpected message(s)"
argument_list|)
block|;
name|verified
operator|=
literal|false
block|;     }
name|QStringList
name|missingMsgs
operator|=
name|handler
operator|.
name|expectedMessages
argument_list|()
argument_list|;     if
operator|(
operator|!
name|missingMsgs
operator|.
name|isEmpty
argument_list|()
operator|)
block|{
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|msg
decl|,
name|missingMsgs
control|)
name|qWarning
argument_list|(
literal|"Missing message: %s"
argument_list|,
name|qPrintable
argument_list|(
name|msg
argument_list|)
argument_list|)
expr_stmt|;
name|verified
operator|=
literal|false
argument_list|;     }
decl|if
argument_list|(
name|pro
operator|->
name|isOk
argument_list|()
operator|!=
name|ok
argument_list|)
argument_list|{
specifier|static
specifier|const
name|char
operator|*
specifier|const
name|lbl
index|[]
operator|=
block|{
literal|"failure"
block|,
literal|"success"
block|}
argument_list|;
name|qWarning
argument_list|(
literal|"Expected %s, got %s"
argument_list|,
name|lbl
index|[
name|int
argument_list|(
name|ok
argument_list|)
index|]
argument_list|,
name|lbl
index|[
literal|1
operator|-
name|int
argument_list|(
name|ok
argument_list|)
index|]
argument_list|)
argument_list|;
name|verified
operator|=
literal|false
argument_list|;     }
decl|if
argument_list|(
name|pro
operator|->
name|items
argument_list|()
operator|!=
name|out
operator|&&
operator|(
name|ok
operator|||
operator|!
name|out
operator|.
name|isEmpty
argument_list|()
operator|)
argument_list|)
argument_list|{
name|qWarning
argument_list|(
literal|"Bytecode mismatch.\nActual:%s\nExpected:%s"
argument_list|,
name|qPrintable
argument_list|(
name|QMakeParser
operator|::
name|formatProBlock
argument_list|(
name|pro
operator|->
name|items
argument_list|()
argument_list|)
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|QMakeParser
operator|::
name|formatProBlock
argument_list|(
name|out
argument_list|)
argument_list|)
argument_list|)
argument_list|;
name|verified
operator|=
literal|false
argument_list|;     }
name|pro
operator|->
name|deref
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QVERIFY
argument_list|(
name|verified
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  QTEST_MAIN
operator|(
name|tst_qmakelib
operator|)
end_expr_stmt
begin_include
include|#
directive|include
file|"tst_qmakelib.moc"
end_include
end_unit
