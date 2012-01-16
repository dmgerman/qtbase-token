begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_class
DECL|class|tst_qfileopenevent
class|class
name|tst_qfileopenevent
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_qfileopenevent
name|tst_qfileopenevent
parameter_list|()
block|{}
name|~
name|tst_qfileopenevent
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|constructor
parameter_list|()
function_decl|;
name|void
name|fileOpen
parameter_list|()
function_decl|;
name|void
name|handleLifetime
parameter_list|()
function_decl|;
name|void
name|multiOpen
parameter_list|()
function_decl|;
name|void
name|sendAndReceive
parameter_list|()
function_decl|;
private|private:
name|void
name|createFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|content
parameter_list|)
function_decl|;
name|QFileOpenEvent
modifier|*
name|createFileAndEvent
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|content
parameter_list|)
function_decl|;
name|void
name|checkReadAndWrite
parameter_list|(
name|QFileOpenEvent
modifier|&
name|event
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|readContent
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|writeContent
parameter_list|,
name|bool
name|writeOk
parameter_list|)
function_decl|;
name|QByteArray
name|readFileContent
parameter_list|(
name|QFileOpenEvent
modifier|&
name|event
parameter_list|)
function_decl|;
name|bool
name|appendFileContent
parameter_list|(
name|QFileOpenEvent
modifier|&
name|event
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|writeContent
parameter_list|)
function_decl|;
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_destructor
DECL|function|~tst_qfileopenevent
name|tst_qfileopenevent
operator|::
name|~
name|tst_qfileopenevent
parameter_list|()
block|{ }
end_destructor
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function
DECL|function|initTestCase
name|void
name|tst_qfileopenevent
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|createFile
name|void
name|tst_qfileopenevent
operator|::
name|createFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|content
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|filename
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|file
operator|.
name|write
argument_list|(
name|content
argument_list|)
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createFileAndEvent
name|QFileOpenEvent
modifier|*
name|tst_qfileopenevent
operator|::
name|createFileAndEvent
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|content
parameter_list|)
block|{
name|createFile
argument_list|(
name|filename
argument_list|,
name|content
argument_list|)
expr_stmt|;
return|return
operator|new
name|QFileOpenEvent
argument_list|(
name|filename
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|constructor
name|void
name|tst_qfileopenevent
operator|::
name|constructor
parameter_list|()
block|{
comment|// check that filename get/set works
name|QFileOpenEvent
name|nameTest
argument_list|(
name|QLatin1String
argument_list|(
literal|"fileNameTest"
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|nameTest
operator|.
name|file
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"fileNameTest"
argument_list|)
argument_list|)
expr_stmt|;
comment|// check that url get/set works
name|QFileOpenEvent
name|urlTest
argument_list|(
name|QUrl
argument_list|(
name|QLatin1String
argument_list|(
literal|"file:///urlNameTest"
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|urlTest
operator|.
name|url
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"file:///urlNameTest"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readFileContent
name|QByteArray
name|tst_qfileopenevent
operator|::
name|readFileContent
parameter_list|(
name|QFileOpenEvent
modifier|&
name|event
parameter_list|)
block|{
name|QFile
name|file
decl_stmt|;
name|event
operator|.
name|openFile
argument_list|(
name|file
argument_list|,
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|file
operator|.
name|seek
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QByteArray
name|data
init|=
name|file
operator|.
name|readAll
argument_list|()
decl_stmt|;
return|return
name|data
return|;
block|}
end_function
begin_function
DECL|function|appendFileContent
name|bool
name|tst_qfileopenevent
operator|::
name|appendFileContent
parameter_list|(
name|QFileOpenEvent
modifier|&
name|event
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|writeContent
parameter_list|)
block|{
name|QFile
name|file
decl_stmt|;
name|bool
name|ok
init|=
name|event
operator|.
name|openFile
argument_list|(
name|file
argument_list|,
name|QFile
operator|::
name|Append
operator||
name|QFile
operator|::
name|Unbuffered
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
name|ok
operator|=
name|file
operator|.
name|write
argument_list|(
name|writeContent
argument_list|)
operator|==
name|writeContent
operator|.
name|size
argument_list|()
expr_stmt|;
return|return
name|ok
return|;
block|}
end_function
begin_function
DECL|function|checkReadAndWrite
name|void
name|tst_qfileopenevent
operator|::
name|checkReadAndWrite
parameter_list|(
name|QFileOpenEvent
modifier|&
name|event
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|readContent
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|writeContent
parameter_list|,
name|bool
name|writeOk
parameter_list|)
block|{
name|QCOMPARE
argument_list|(
name|readFileContent
argument_list|(
name|event
argument_list|)
argument_list|,
name|readContent
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|appendFileContent
argument_list|(
name|event
argument_list|,
name|writeContent
argument_list|)
argument_list|,
name|writeOk
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|readFileContent
argument_list|(
name|event
argument_list|)
argument_list|,
name|writeOk
condition|?
name|readContent
operator|+
name|writeContent
else|:
name|readContent
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fileOpen
name|void
name|tst_qfileopenevent
operator|::
name|fileOpen
parameter_list|()
block|{
name|createFile
argument_list|(
name|QLatin1String
argument_list|(
literal|"testFileOpen"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"test content+RFileWrite"
argument_list|)
argument_list|)
expr_stmt|;
comment|// filename event
name|QUrl
name|fileUrl
decl_stmt|;
comment|// need to get the URL during the file test, for use in the URL test
block|{
name|QFileOpenEvent
name|nameTest
argument_list|(
name|QLatin1String
argument_list|(
literal|"testFileOpen"
argument_list|)
argument_list|)
decl_stmt|;
name|fileUrl
operator|=
name|nameTest
operator|.
name|url
argument_list|()
expr_stmt|;
name|checkReadAndWrite
argument_list|(
name|nameTest
argument_list|,
name|QByteArray
argument_list|(
literal|"test content+RFileWrite"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"+nameWrite"
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
comment|// url event
block|{
name|QFileOpenEvent
name|urlTest
argument_list|(
name|fileUrl
argument_list|)
decl_stmt|;
name|checkReadAndWrite
argument_list|(
name|urlTest
argument_list|,
name|QByteArray
argument_list|(
literal|"test content+RFileWrite+nameWrite"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"+urlWrite"
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
name|QFile
operator|::
name|remove
argument_list|(
name|QLatin1String
argument_list|(
literal|"testFileOpen"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleLifetime
name|void
name|tst_qfileopenevent
operator|::
name|handleLifetime
parameter_list|()
block|{
name|QScopedPointer
argument_list|<
name|QFileOpenEvent
argument_list|>
name|event
argument_list|(
name|createFileAndEvent
argument_list|(
name|QLatin1String
argument_list|(
literal|"testHandleLifetime"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"test content"
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
comment|// open a QFile after the original RFile is closed
name|QFile
name|qFile
decl_stmt|;
name|QCOMPARE
argument_list|(
name|event
operator|->
name|openFile
argument_list|(
name|qFile
argument_list|,
name|QFile
operator|::
name|Append
operator||
name|QFile
operator|::
name|Unbuffered
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|event
operator|.
name|reset
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// write to the QFile after the event is closed
name|QString
name|writeContent
argument_list|(
name|QLatin1String
argument_list|(
literal|"+closed original handles"
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|qFile
operator|.
name|write
argument_list|(
name|writeContent
operator|.
name|toUtf8
argument_list|()
argument_list|)
argument_list|)
argument_list|,
name|writeContent
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|qFile
operator|.
name|close
argument_list|()
expr_stmt|;
comment|// check the content
name|QFile
name|checkContent
argument_list|(
literal|"testHandleLifetime"
argument_list|)
decl_stmt|;
name|checkContent
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QString
name|content
argument_list|(
name|checkContent
operator|.
name|readAll
argument_list|()
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|content
argument_list|,
name|QLatin1String
argument_list|(
literal|"test content+closed original handles"
argument_list|)
argument_list|)
expr_stmt|;
name|checkContent
operator|.
name|close
argument_list|()
expr_stmt|;
name|QFile
operator|::
name|remove
argument_list|(
name|QLatin1String
argument_list|(
literal|"testHandleLifetime"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|multiOpen
name|void
name|tst_qfileopenevent
operator|::
name|multiOpen
parameter_list|()
block|{
name|QScopedPointer
argument_list|<
name|QFileOpenEvent
argument_list|>
name|event
argument_list|(
name|createFileAndEvent
argument_list|(
name|QLatin1String
argument_list|(
literal|"testMultiOpen"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"itlum"
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QFile
name|files
index|[
literal|5
index|]
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
literal|5
condition|;
name|i
operator|++
control|)
block|{
name|QCOMPARE
argument_list|(
name|event
operator|->
name|openFile
argument_list|(
name|files
index|[
name|i
index|]
argument_list|,
name|QFile
operator|::
name|ReadOnly
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|5
condition|;
name|i
operator|++
control|)
name|files
index|[
name|i
index|]
operator|.
name|seek
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QString
name|str
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|4
init|;
name|i
operator|>=
literal|0
condition|;
name|i
operator|--
control|)
block|{
name|char
name|c
decl_stmt|;
name|files
index|[
name|i
index|]
operator|.
name|getChar
argument_list|(
operator|&
name|c
argument_list|)
expr_stmt|;
name|str
operator|.
name|append
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|files
index|[
name|i
index|]
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|"multi"
argument_list|)
argument_list|)
expr_stmt|;
name|QFile
operator|::
name|remove
argument_list|(
name|QLatin1String
argument_list|(
literal|"testMultiOpen"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|tst_qfileopenevent
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|FileOpen
condition|)
return|return
name|QObject
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
name|QFileOpenEvent
modifier|*
name|fileOpenEvent
init|=
cast|static_cast
argument_list|<
name|QFileOpenEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|appendFileContent
argument_list|(
operator|*
name|fileOpenEvent
argument_list|,
literal|"+received"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|sendAndReceive
name|void
name|tst_qfileopenevent
operator|::
name|sendAndReceive
parameter_list|()
block|{
name|QScopedPointer
argument_list|<
name|QFileOpenEvent
argument_list|>
name|event
argument_list|(
name|createFileAndEvent
argument_list|(
name|QLatin1String
argument_list|(
literal|"testSendAndReceive"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"sending"
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|postEvent
argument_list|(
name|this
argument_list|,
name|event
operator|.
name|take
argument_list|()
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|processEvents
argument_list|()
expr_stmt|;
comment|// QTBUG-17468: On Mac, processEvents doesn't always process posted events
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
comment|// check the content
name|QFile
name|checkContent
argument_list|(
literal|"testSendAndReceive"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|checkContent
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QString
name|content
argument_list|(
name|checkContent
operator|.
name|readAll
argument_list|()
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|content
argument_list|,
name|QLatin1String
argument_list|(
literal|"sending+received"
argument_list|)
argument_list|)
expr_stmt|;
name|checkContent
operator|.
name|close
argument_list|()
expr_stmt|;
name|QFile
operator|::
name|remove
argument_list|(
name|QLatin1String
argument_list|(
literal|"testSendAndReceive"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qfileopenevent
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qfileopenevent.moc"
end_include
end_unit
