begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_include
include|#
directive|include
file|<apgcli.h>
end_include
begin_include
include|#
directive|include
file|"private/qcore_symbian_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
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
name|void
name|external_data
parameter_list|()
function_decl|;
name|void
name|external
parameter_list|()
function_decl|;
private|private:
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|RFile
name|createRFile
parameter_list|(
specifier|const
name|TDesC
modifier|&
name|filename
parameter_list|,
specifier|const
name|TDesC8
modifier|&
name|content
parameter_list|)
function_decl|;
else|#
directive|else
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
endif|#
directive|endif
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
private|private:
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
DECL|struct|AutoRFs
struct|struct
name|AutoRFs
super|:
specifier|public
name|RFs
block|{
DECL|function|AutoRFs
name|AutoRFs
parameter_list|()
block|{
name|qt_symbian_throwIfError
argument_list|(
name|Connect
argument_list|()
argument_list|)
expr_stmt|;
name|qt_symbian_throwIfError
argument_list|(
name|ShareProtected
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|~AutoRFs
name|~
name|AutoRFs
parameter_list|()
block|{
name|Close
argument_list|()
expr_stmt|;
block|}
block|}
struct|;
DECL|member|fsSession
name|AutoRFs
name|fsSession
decl_stmt|;
endif|#
directive|endif
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
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_function
DECL|function|createRFile
name|RFile
name|tst_qfileopenevent
operator|::
name|createRFile
parameter_list|(
specifier|const
name|TDesC
modifier|&
name|filename
parameter_list|,
specifier|const
name|TDesC8
modifier|&
name|content
parameter_list|)
block|{
name|RFile
name|file
decl_stmt|;
name|qt_symbian_throwIfError
argument_list|(
name|file
operator|.
name|Replace
argument_list|(
name|fsSession
argument_list|,
name|filename
argument_list|,
name|EFileWrite
argument_list|)
argument_list|)
expr_stmt|;
name|qt_symbian_throwIfError
argument_list|(
name|file
operator|.
name|Write
argument_list|(
name|content
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|file
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
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
begin_endif
endif|#
directive|endif
end_endif
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
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|RFile
name|rFile
init|=
name|createRFile
argument_list|(
name|qt_QString2TPtrC
argument_list|(
name|filename
argument_list|)
argument_list|,
name|TPtrC8
argument_list|(
operator|(
name|TText8
operator|*
operator|)
name|content
operator|.
name|constData
argument_list|()
argument_list|,
name|content
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QScopedPointer
argument_list|<
name|RFile
argument_list|,
name|QScopedPointerRCloser
argument_list|<
name|RFile
argument_list|>
argument_list|>
name|closeRFile
argument_list|(
operator|&
name|rFile
argument_list|)
decl_stmt|;
return|return
operator|new
name|QFileOpenEvent
argument_list|(
name|rFile
argument_list|)
return|;
else|#
directive|else
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
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
comment|// check that RFile construction works
name|RFile
name|rFile
init|=
name|createRFile
argument_list|(
name|_L
argument_list|(
literal|"testRFile"
argument_list|)
argument_list|,
name|_L8
argument_list|(
literal|"test content"
argument_list|)
argument_list|)
decl_stmt|;
name|QFileOpenEvent
name|rFileTest
argument_list|(
name|rFile
argument_list|)
decl_stmt|;
name|QString
name|targetName
argument_list|(
name|QLatin1String
argument_list|(
literal|"testRFile"
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|rFileTest
operator|.
name|file
argument_list|()
operator|.
name|right
argument_list|(
name|targetName
operator|.
name|size
argument_list|()
argument_list|)
argument_list|,
name|targetName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rFileTest
operator|.
name|url
argument_list|()
operator|.
name|toString
argument_list|()
operator|.
name|right
argument_list|(
name|targetName
operator|.
name|size
argument_list|()
argument_list|)
argument_list|,
name|targetName
argument_list|)
expr_stmt|;
name|rFile
operator|.
name|Close
argument_list|()
expr_stmt|;
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
comment|// create writeable file
block|{
name|RFile
name|rFile
init|=
name|createRFile
argument_list|(
name|_L
argument_list|(
literal|"testFileOpen"
argument_list|)
argument_list|,
name|_L8
argument_list|(
literal|"test content"
argument_list|)
argument_list|)
decl_stmt|;
name|QFileOpenEvent
name|rFileTest
argument_list|(
name|rFile
argument_list|)
decl_stmt|;
name|checkReadAndWrite
argument_list|(
name|rFileTest
argument_list|,
name|QByteArray
argument_list|(
literal|"test content"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"+RFileWrite"
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|rFile
operator|.
name|Close
argument_list|()
expr_stmt|;
block|}
comment|// open read-only RFile
block|{
name|RFile
name|rFile
decl_stmt|;
name|int
name|err
init|=
name|rFile
operator|.
name|Open
argument_list|(
name|fsSession
argument_list|,
name|_L
argument_list|(
literal|"testFileOpen"
argument_list|)
argument_list|,
name|EFileRead
argument_list|)
decl_stmt|;
name|QFileOpenEvent
name|rFileTest
argument_list|(
name|rFile
argument_list|)
decl_stmt|;
name|checkReadAndWrite
argument_list|(
name|rFileTest
argument_list|,
name|QByteArray
argument_list|(
literal|"test content+RFileWrite"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"+RFileRead"
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|rFile
operator|.
name|Close
argument_list|()
expr_stmt|;
block|}
else|#
directive|else
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
endif|#
directive|endif
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
name|check
argument_list|(
literal|"testHandleLifetime"
argument_list|)
decl_stmt|;
name|check
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
name|check
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
name|check
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
name|check
argument_list|(
literal|"testSendAndReceive"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|check
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
name|check
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
name|check
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
begin_function
DECL|function|external_data
name|void
name|tst_qfileopenevent
operator|::
name|external_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"filename"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"targetContent"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"sendHandle"
argument_list|)
expr_stmt|;
name|QString
name|privateName
argument_list|(
name|QLatin1String
argument_list|(
literal|"tst_qfileopenevent_external"
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|publicName
argument_list|(
name|QLatin1String
argument_list|(
literal|"C:\\Data\\tst_qfileopenevent_external"
argument_list|)
argument_list|)
decl_stmt|;
name|QByteArray
name|writeSuccess
argument_list|(
literal|"original+external"
argument_list|)
decl_stmt|;
name|QByteArray
name|writeFail
argument_list|(
literal|"original"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"public name"
argument_list|)
operator|<<
name|publicName
operator|<<
name|writeSuccess
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data caged name"
argument_list|)
operator|<<
name|privateName
operator|<<
name|writeFail
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"public handle"
argument_list|)
operator|<<
name|publicName
operator|<<
name|writeSuccess
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data caged handle"
argument_list|)
operator|<<
name|privateName
operator|<<
name|writeSuccess
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|external
name|void
name|tst_qfileopenevent
operator|::
name|external
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|Q_OS_SYMBIAN
name|QSKIP
argument_list|(
literal|"external app file open test only valid in Symbian"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
else|#
directive|else
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|targetContent
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|sendHandle
argument_list|)
expr_stmt|;
name|RFile
name|rFile
init|=
name|createRFile
argument_list|(
name|qt_QString2TPtrC
argument_list|(
name|filename
argument_list|)
argument_list|,
name|_L8
argument_list|(
literal|"original"
argument_list|)
argument_list|)
decl_stmt|;
comment|// launch app with the file
name|RApaLsSession
name|apa
decl_stmt|;
name|QCOMPARE
argument_list|(
name|apa
operator|.
name|Connect
argument_list|()
argument_list|,
name|KErrNone
argument_list|)
expr_stmt|;
name|TThreadId
name|threadId
decl_stmt|;
name|TDataType
name|type
argument_list|(
name|_L8
argument_list|(
literal|"application/x-tst_qfileopenevent"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|sendHandle
condition|)
block|{
name|QCOMPARE
argument_list|(
name|apa
operator|.
name|StartDocument
argument_list|(
name|rFile
argument_list|,
name|type
argument_list|,
name|threadId
argument_list|)
argument_list|,
name|KErrNone
argument_list|)
expr_stmt|;
name|rFile
operator|.
name|Close
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|TFileName
name|fullName
decl_stmt|;
name|rFile
operator|.
name|FullName
argument_list|(
name|fullName
argument_list|)
expr_stmt|;
name|rFile
operator|.
name|Close
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|apa
operator|.
name|StartDocument
argument_list|(
name|fullName
argument_list|,
name|type
argument_list|,
name|threadId
argument_list|)
argument_list|,
name|KErrNone
argument_list|)
expr_stmt|;
block|}
comment|// wait for app exit
name|RThread
name|appThread
decl_stmt|;
if|if
condition|(
name|appThread
operator|.
name|Open
argument_list|(
name|threadId
argument_list|)
operator|==
name|KErrNone
condition|)
block|{
name|TRequestStatus
name|status
decl_stmt|;
name|appThread
operator|.
name|Logon
argument_list|(
name|status
argument_list|)
expr_stmt|;
name|User
operator|::
name|WaitForRequest
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
comment|// check the contents
name|QFile
name|check
argument_list|(
name|filename
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|check
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
name|QCOMPARE
argument_list|(
name|check
operator|.
name|readAll
argument_list|()
argument_list|,
name|targetContent
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
name|check
operator|.
name|remove
argument_list|()
decl_stmt|;
name|QFile
operator|::
name|remove
argument_list|(
name|filename
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
