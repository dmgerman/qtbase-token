begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// This file contains benchmarks for QNetworkReply functions.
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkreply.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkrequest.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkaccessmanager.h>
end_include
begin_include
include|#
directive|include
file|"../../auto/network-settings.h"
end_include
begin_define
DECL|macro|BANDWIDTH_LIMIT_BYTES
define|#
directive|define
name|BANDWIDTH_LIMIT_BYTES
value|(1024*100)
end_define
begin_define
DECL|macro|TIME_ESTIMATION_SECONDS
define|#
directive|define
name|TIME_ESTIMATION_SECONDS
value|(97)
end_define
begin_class
DECL|class|tst_qnetworkreply
class|class
name|tst_qnetworkreply
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|limiting_data
parameter_list|()
function_decl|;
name|void
name|limiting
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|reply
name|QNetworkReply
modifier|*
name|reply
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|HttpReceiver
class|class
name|HttpReceiver
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public
name|slots
public|:
DECL|function|finishedSlot
name|void
name|finishedSlot
parameter_list|()
block|{
name|quint64
name|bytesPerSec
init|=
operator|(
name|reply
operator|->
name|header
argument_list|(
name|QNetworkRequest
operator|::
name|ContentLengthHeader
argument_list|)
operator|.
name|toLongLong
argument_list|()
operator|)
operator|/
operator|(
name|stopwatch
operator|.
name|elapsed
argument_list|()
operator|/
literal|1000.0
operator|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Finished HTTP(S) request with"
operator|<<
name|bytesPerSec
operator|<<
literal|"bytes/sec"
expr_stmt|;
name|QVERIFY
argument_list|(
name|bytesPerSec
operator|<
name|BANDWIDTH_LIMIT_BYTES
operator|*
literal|1.05
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|bytesPerSec
operator|>
name|BANDWIDTH_LIMIT_BYTES
operator|*
literal|0.95
argument_list|)
expr_stmt|;
name|timer
operator|->
name|stop
argument_list|()
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|exitLoop
argument_list|()
expr_stmt|;
block|}
DECL|function|readyReadSlot
name|void
name|readyReadSlot
parameter_list|()
block|{     }
DECL|function|timeoutSlot
name|void
name|timeoutSlot
parameter_list|()
block|{
name|reply
operator|->
name|read
argument_list|(
name|BANDWIDTH_LIMIT_BYTES
argument_list|)
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
DECL|function|startTimer
name|void
name|startTimer
parameter_list|()
block|{
name|stopwatch
operator|.
name|start
argument_list|()
expr_stmt|;
name|timer
operator|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|timeoutSlot
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|->
name|start
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|member|timer
name|QTimer
modifier|*
name|timer
decl_stmt|;
DECL|member|stopwatch
name|QTime
name|stopwatch
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_qnetworkreply
operator|::
name|initTestCase
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|QtNetworkSettings
operator|::
name|verifyTestNetworkSettings
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|limiting_data
name|void
name|tst_qnetworkreply
operator|::
name|limiting_data
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
name|newRow
argument_list|(
literal|"HTTP"
argument_list|)
operator|<<
name|QUrl
argument_list|(
literal|"http://"
operator|+
name|QtNetworkSettings
operator|::
name|serverName
argument_list|()
operator|+
literal|"/mediumfile"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|QTest
operator|::
name|newRow
argument_list|(
literal|"HTTP+SSL"
argument_list|)
operator|<<
name|QUrl
argument_list|(
literal|"https://"
operator|+
name|QtNetworkSettings
operator|::
name|serverName
argument_list|()
operator|+
literal|"/mediumfile"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|limiting
name|void
name|tst_qnetworkreply
operator|::
name|limiting
parameter_list|()
block|{
name|HttpReceiver
name|receiver
decl_stmt|;
name|QNetworkAccessManager
name|manager
decl_stmt|;
name|QFETCH
argument_list|(
name|QUrl
argument_list|,
name|url
argument_list|)
expr_stmt|;
name|QNetworkRequest
name|req
argument_list|(
name|url
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Starting. This will take a while (around"
operator|<<
name|TIME_ESTIMATION_SECONDS
operator|<<
literal|"sec)."
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Please check the actual bandwidth usage with a network monitor, e.g. the KDE"
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"network plasma widget. It should be around"
operator|<<
name|BANDWIDTH_LIMIT_BYTES
operator|<<
literal|"bytes/sec."
expr_stmt|;
name|reply
operator|=
name|manager
operator|.
name|get
argument_list|(
name|req
argument_list|)
expr_stmt|;
name|reply
operator|->
name|ignoreSslErrors
argument_list|()
expr_stmt|;
name|reply
operator|->
name|setReadBufferSize
argument_list|(
name|BANDWIDTH_LIMIT_BYTES
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|reply
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
operator|&
name|receiver
argument_list|,
name|SLOT
argument_list|(
name|readyReadSlot
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|reply
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
operator|&
name|receiver
argument_list|,
name|SLOT
argument_list|(
name|finishedSlot
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|receiver
operator|.
name|startTimer
argument_list|()
expr_stmt|;
comment|// event loop
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
name|TIME_ESTIMATION_SECONDS
operator|+
literal|20
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qnetworkreply
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
