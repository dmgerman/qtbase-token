begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/QProcess>
end_include
begin_class
DECL|class|tst_QProcess
class|class
name|tst_QProcess
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
private|private
name|slots
private|:
name|void
name|echoTest_performance
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|// QT_NO_PROCESS
block|}
class|;
end_class
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_comment
comment|// Reading and writing to a process is not supported on Qt/CE
end_comment
begin_function
DECL|function|echoTest_performance
name|void
name|tst_QProcess
operator|::
name|echoTest_performance
parameter_list|()
block|{
name|QProcess
name|process
decl_stmt|;
name|process
operator|.
name|start
argument_list|(
literal|"testProcessLoopback/testProcessLoopback"
argument_list|)
expr_stmt|;
name|QByteArray
name|array
decl_stmt|;
name|array
operator|.
name|resize
argument_list|(
literal|1024
operator|*
literal|1024
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
name|array
operator|.
name|size
argument_list|()
condition|;
operator|++
name|j
control|)
name|array
index|[
name|j
index|]
operator|=
literal|'a'
operator|+
operator|(
name|j
operator|%
literal|20
operator|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|process
operator|.
name|waitForStarted
argument_list|()
argument_list|)
expr_stmt|;
name|QTime
name|stopWatch
decl_stmt|;
name|stopWatch
operator|.
name|start
argument_list|()
expr_stmt|;
name|qint64
name|totalBytes
init|=
literal|0
decl_stmt|;
name|QByteArray
name|dump
decl_stmt|;
name|QSignalSpy
name|readyReadSpy
argument_list|(
operator|&
name|process
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|readyReadSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
while|while
condition|(
name|stopWatch
operator|.
name|elapsed
argument_list|()
operator|<
literal|2000
condition|)
block|{
name|process
operator|.
name|write
argument_list|(
name|array
argument_list|)
expr_stmt|;
while|while
condition|(
name|process
operator|.
name|bytesToWrite
argument_list|()
operator|>
literal|0
condition|)
block|{
name|int
name|readCount
init|=
name|readyReadSpy
operator|.
name|count
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|process
operator|.
name|waitForBytesWritten
argument_list|(
literal|5000
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|readyReadSpy
operator|.
name|count
argument_list|()
operator|==
name|readCount
condition|)
name|QVERIFY
argument_list|(
name|process
operator|.
name|waitForReadyRead
argument_list|(
literal|5000
argument_list|)
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|process
operator|.
name|bytesAvailable
argument_list|()
operator|<
name|array
operator|.
name|size
argument_list|()
condition|)
name|QVERIFY2
argument_list|(
name|process
operator|.
name|waitForReadyRead
argument_list|(
literal|5000
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|process
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|dump
operator|=
name|process
operator|.
name|readAll
argument_list|()
expr_stmt|;
name|totalBytes
operator|+=
name|dump
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
literal|"Elapsed time:"
operator|<<
name|stopWatch
operator|.
name|elapsed
argument_list|()
operator|<<
literal|"ms;"
operator|<<
literal|"transfer rate:"
operator|<<
name|totalBytes
operator|/
operator|(
literal|1048.576
operator|)
operator|/
name|stopWatch
operator|.
name|elapsed
argument_list|()
operator|<<
literal|"MB/s"
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
name|array
operator|.
name|size
argument_list|()
condition|;
operator|++
name|j
control|)
name|QCOMPARE
argument_list|(
name|char
argument_list|(
name|dump
operator|.
name|at
argument_list|(
name|j
argument_list|)
argument_list|)
argument_list|,
name|char
argument_list|(
literal|'a'
operator|+
operator|(
name|j
operator|%
literal|20
operator|)
argument_list|)
argument_list|)
expr_stmt|;
name|process
operator|.
name|closeWriteChannel
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|process
operator|.
name|waitForFinished
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WINCE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PROCESS
end_comment
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QProcess
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_bench_qprocess.moc"
end_include
end_unit
