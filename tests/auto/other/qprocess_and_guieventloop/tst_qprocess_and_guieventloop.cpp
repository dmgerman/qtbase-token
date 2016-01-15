begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Intel Corporation ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
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
DECL|class|tst_QProcess_and_GuiEventLoop
class|class
name|tst_QProcess_and_GuiEventLoop
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|waitForAndEventLoop
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|waitForAndEventLoop
name|void
name|tst_QProcess_and_GuiEventLoop
operator|::
name|waitForAndEventLoop
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_PROCESS
argument_list|)
name|QSKIP
argument_list|(
literal|"QProcess not supported"
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID_NO_SDK
argument_list|)
name|QSKIP
argument_list|(
literal|"Not supported on Android"
argument_list|)
expr_stmt|;
else|#
directive|else
comment|// based on testcase provided in QTBUG-39488
name|QByteArray
name|msg
init|=
literal|"Hello World"
decl_stmt|;
name|QProcess
name|process
decl_stmt|;
name|process
operator|.
name|start
argument_list|(
literal|"write-read-write/write-read-write"
argument_list|,
name|QStringList
argument_list|()
operator|<<
name|msg
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|process
operator|.
name|waitForStarted
argument_list|(
literal|5000
argument_list|)
argument_list|)
expr_stmt|;
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
name|QCOMPARE
argument_list|(
name|process
operator|.
name|readAll
argument_list|()
operator|.
name|trimmed
argument_list|()
argument_list|,
name|msg
argument_list|)
expr_stmt|;
comment|// run the GUI event dispatcher once
name|QSignalSpy
name|spy
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
name|qApp
operator|->
name|processEvents
argument_list|(
name|QEventLoop
operator|::
name|AllEvents
argument_list|,
literal|100
argument_list|)
expr_stmt|;
comment|// we mustn't have read anything in the event loop
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// ensure the process hasn't died
name|QVERIFY
argument_list|(
operator|!
name|process
operator|.
name|waitForFinished
argument_list|(
literal|250
argument_list|)
argument_list|)
expr_stmt|;
comment|// we mustn't have read anything during waitForFinished either
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// release the child for the second write
name|process
operator|.
name|write
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|process
operator|.
name|waitForFinished
argument_list|(
literal|5000
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|process
operator|.
name|exitStatus
argument_list|()
argument_list|)
argument_list|,
name|int
argument_list|(
name|QProcess
operator|::
name|NormalExit
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|process
operator|.
name|exitCode
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|process
operator|.
name|readAll
argument_list|()
operator|.
name|trimmed
argument_list|()
argument_list|,
name|msg
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QProcess_and_GuiEventLoop
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qprocess_and_guieventloop.moc"
end_include
end_unit
