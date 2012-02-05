begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_function
DECL|function|wrapInFunction
name|void
name|wrapInFunction
parameter_list|()
block|{
comment|//! [0]
name|QVERIFY
argument_list|(
literal|1
operator|+
literal|1
operator|==
literal|2
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|QVERIFY2
argument_list|(
literal|1
operator|+
literal|1
operator|==
literal|2
argument_list|,
literal|"A breach in basic arithmetic occurred."
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|QCOMPARE
argument_list|(
name|QString
argument_list|(
literal|"hello"
argument_list|)
operator|.
name|toUpper
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"HELLO"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|void
name|TestQString
operator|::
name|toInt_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"aString"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"positive value"
argument_list|)
operator|<<
literal|"42"
operator|<<
literal|42
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"negative value"
argument_list|)
operator|<<
literal|"-42"
operator|<<
operator|-
literal|42
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"zero"
argument_list|)
operator|<<
literal|"0"
operator|<<
literal|0
expr_stmt|;
block|}
comment|//! [3]
comment|//! [4]
name|void
name|TestQString
operator|::
name|toInt
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|aString
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aString
operator|.
name|toInt
argument_list|()
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
comment|//! [4]
comment|//! [5]
if|if
condition|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|!=
literal|4
condition|)
name|QFAIL
argument_list|(
literal|"This test has not been ported to this platform yet."
argument_list|)
expr_stmt|;
comment|//! [5]
comment|//! [6]
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|myString
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
argument_list|(
literal|"hello"
argument_list|)
operator|.
name|toUpper
argument_list|()
argument_list|,
name|myString
argument_list|)
expr_stmt|;
comment|//! [6]
comment|//! [7]
name|QTEST
argument_list|(
name|QString
argument_list|(
literal|"hello"
argument_list|)
operator|.
name|toUpper
argument_list|()
argument_list|,
literal|"myString"
argument_list|)
expr_stmt|;
comment|//! [7]
comment|//! [8]
if|if
condition|(
operator|!
name|QSqlDatabase
operator|::
name|drivers
argument_list|()
operator|.
name|contains
argument_list|(
literal|"SQLITE"
argument_list|)
condition|)
name|QSKIP
argument_list|(
literal|"This test requires the SQLITE database driver"
argument_list|)
expr_stmt|;
comment|//! [8]
comment|//! [9]
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"Will fix in the next release"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|j
argument_list|,
literal|43
argument_list|)
expr_stmt|;
comment|//! [9]
comment|//! [10]
name|QEXPECT_FAIL
argument_list|(
literal|"data27"
argument_list|,
literal|"Oh my, this is soooo broken"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|42
argument_list|)
expr_stmt|;
comment|//! [10]
comment|//! [11]
class|class
name|TestQString
super|:
specifier|public
name|QObject
block|{
operator|...
block|}
class|;
name|QTEST_MAIN
argument_list|(
argument|TestQString
argument_list|)
comment|//! [11]
comment|//! [13]
name|QTest
operator|::
name|keyClick
argument_list|(
name|myWidget
argument_list|,
literal|'a'
argument_list|)
expr_stmt|;
comment|//! [13]
comment|//! [14]
name|QTest
operator|::
name|keyClick
argument_list|(
name|myWidget
argument_list|,
name|Qt
operator|::
name|Key_Escape
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|myWidget
argument_list|,
name|Qt
operator|::
name|Key_Escape
argument_list|,
name|Qt
operator|::
name|ShiftModifier
argument_list|,
literal|200
argument_list|)
expr_stmt|;
comment|//! [14]
comment|//! [15]
name|QTest
operator|::
name|keyClicks
argument_list|(
name|myWidget
argument_list|,
literal|"hello world"
argument_list|)
expr_stmt|;
comment|//! [15]
comment|//! [16]
namespace|namespace
name|QTest
block|{
template|template
parameter_list|<>
name|char
modifier|*
name|toString
parameter_list|(
specifier|const
name|MyPoint
modifier|&
name|point
parameter_list|)
block|{
name|QByteArray
name|ba
init|=
literal|"MyPoint("
decl_stmt|;
name|ba
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|point
operator|.
name|x
argument_list|()
argument_list|)
operator|+
literal|", "
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|point
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|ba
operator|+=
literal|")"
expr_stmt|;
return|return
name|qstrdup
argument_list|(
name|ba
operator|.
name|data
argument_list|()
argument_list|)
return|;
block|}
block|}
comment|//! [16]
comment|//! [17]
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|myNetworkServerNotResponding
argument_list|()
operator|&&
name|i
operator|++
operator|<
literal|50
condition|)
name|QTest
operator|::
name|qWait
argument_list|(
literal|250
argument_list|)
expr_stmt|;
comment|//! [17]
comment|//! [18]
name|MyTestObject
name|test1
decl_stmt|;
name|QTest
operator|::
name|qExec
argument_list|(
operator|&
name|test1
argument_list|)
expr_stmt|;
comment|//! [18]
comment|//! [19]
name|QDir
name|dir
decl_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QDir::mkdir: Empty or null file name(s)"
argument_list|)
expr_stmt|;
name|dir
operator|.
name|mkdir
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|//! [19]
comment|//! [20]
name|void
name|myTestFunction_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"aString"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"just hello"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"hello"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"a null string"
argument_list|)
operator|<<
name|QString
argument_list|()
expr_stmt|;
block|}
comment|//! [20]
comment|//! [21]
name|void
name|myTestFunction_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"intval"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"str"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|double
argument_list|>
argument_list|(
literal|"dbl"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"row1"
argument_list|)
operator|<<
literal|1
operator|<<
literal|"hello"
operator|<<
literal|1.5
expr_stmt|;
block|}
comment|//! [21]
comment|//! [22]
name|void
name|MyTestClass
operator|::
name|cleanup
parameter_list|()
block|{
if|if
condition|(
name|qstrcmp
argument_list|(
name|currentTestFunction
argument_list|()
argument_list|,
literal|"myDatabaseTest"
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|// clean up all database connections
name|closeAllDatabases
argument_list|()
expr_stmt|;
block|}
block|}
comment|//! [22]
comment|//! [23]
name|QTest
operator|::
name|qSleep
argument_list|(
literal|250
argument_list|)
expr_stmt|;
comment|//! [23]
comment|//! [24]
name|QWidget
name|widget
decl_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowShown
argument_list|(
operator|&
name|widget
argument_list|)
expr_stmt|;
comment|//! [24]
comment|//! [25]
name|QWidget
name|widget
decl_stmt|;
name|QTest
operator|::
name|touchEvent
argument_list|(
operator|&
name|widget
argument_list|)
operator|.
name|press
argument_list|(
literal|0
argument_list|,
name|QPoint
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|touchEvent
argument_list|(
operator|&
name|widget
argument_list|)
operator|.
name|stationary
argument_list|(
literal|0
argument_list|)
operator|.
name|press
argument_list|(
literal|1
argument_list|,
name|QPoint
argument_list|(
literal|40
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|touchEvent
argument_list|(
operator|&
name|widget
argument_list|)
operator|.
name|move
argument_list|(
literal|0
argument_list|,
name|QPoint
argument_list|(
literal|12
argument_list|,
literal|12
argument_list|)
argument_list|)
operator|.
name|move
argument_list|(
literal|1
argument_list|,
name|QPoint
argument_list|(
literal|45
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|touchEvent
argument_list|(
operator|&
name|widget
argument_list|)
operator|.
name|release
argument_list|(
literal|0
argument_list|)
operator|.
name|release
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|//! [25]
comment|//! [26]
comment|// Source: /home/user/sources/myxmlparser/tests/tst_myxmlparser/tst_myxmlparser.cpp
comment|// Build:  /home/user/build/myxmlparser/tests/tst_myxmlparser
comment|// Qt:     /usr/local/Qt-5.0.0
name|void
name|tst_MyXmlParser
operator|::
name|parse
parameter_list|()
block|{
name|MyXmlParser
name|parser
decl_stmt|;
name|QString
name|input
init|=
name|QFINDTESTDATA
argument_list|(
literal|"testxml/simple1.xml"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|parser
operator|.
name|parse
argument_list|(
name|input
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//! [26]
block|}
end_function
end_unit
