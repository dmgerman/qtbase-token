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
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QNetworkAccessManager>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QNetworkRequest>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QNetworkReply>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"../../network-settings.h"
end_include
begin_class
DECL|class|tst_QNetworkAccessManager_And_QProgressDialog
class|class
name|tst_QNetworkAccessManager_And_QProgressDialog
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QNetworkAccessManager_And_QProgressDialog
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|downloadCheck
parameter_list|()
function_decl|;
name|void
name|downloadCheck_data
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|DownloadCheckWidget
class|class
name|DownloadCheckWidget
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
DECL|function|DownloadCheckWidget
name|DownloadCheckWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|lateReadyRead
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|zeroCopy
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|progressDlg
argument_list|(
name|this
argument_list|)
member_init_list|,
name|netmanager
argument_list|(
name|this
argument_list|)
block|{
name|progressDlg
operator|.
name|setRange
argument_list|(
literal|1
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"go"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
DECL|member|lateReadyRead
name|bool
name|lateReadyRead
decl_stmt|;
DECL|member|zeroCopy
name|bool
name|zeroCopy
decl_stmt|;
public|public
name|slots
public|:
DECL|function|go
name|void
name|go
parameter_list|()
block|{
name|QNetworkRequest
name|request
argument_list|(
name|QUrl
argument_list|(
literal|"http://"
operator|+
name|QtNetworkSettings
operator|::
name|serverName
argument_list|()
operator|+
literal|"/qtest/bigfile"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|zeroCopy
condition|)
name|request
operator|.
name|setAttribute
argument_list|(
name|QNetworkRequest
operator|::
name|MaximumDownloadBufferSizeAttribute
argument_list|,
literal|10
operator|*
literal|1024
operator|*
literal|1024
argument_list|)
expr_stmt|;
name|QNetworkReply
modifier|*
name|reply
init|=
name|netmanager
operator|.
name|get
argument_list|(
name|QNetworkRequest
argument_list|(
name|QUrl
argument_list|(
literal|"http://"
operator|+
name|QtNetworkSettings
operator|::
name|serverName
argument_list|()
operator|+
literal|"/qtest/bigfile"
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|reply
argument_list|,
name|SIGNAL
argument_list|(
name|downloadProgress
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|dataReadProgress
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
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
name|this
argument_list|,
name|SLOT
argument_list|(
name|dataReadyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
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
name|this
argument_list|,
name|SLOT
argument_list|(
name|finishedFromReply
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|progressDlg
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
DECL|function|dataReadProgress
name|void
name|dataReadProgress
parameter_list|(
name|qint64
name|done
parameter_list|,
name|qint64
name|total
parameter_list|)
block|{
name|QNetworkReply
modifier|*
name|reply
init|=
name|qobject_cast
argument_list|<
name|QNetworkReply
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|reply
argument_list|)
expr_stmt|;
name|progressDlg
operator|.
name|setMaximum
argument_list|(
name|total
argument_list|)
expr_stmt|;
name|progressDlg
operator|.
name|setValue
argument_list|(
name|done
argument_list|)
expr_stmt|;
block|}
DECL|function|dataReadyRead
name|void
name|dataReadyRead
parameter_list|()
block|{
name|QNetworkReply
modifier|*
name|reply
init|=
name|qobject_cast
argument_list|<
name|QNetworkReply
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|reply
argument_list|)
expr_stmt|;
name|lateReadyRead
operator|=
literal|true
expr_stmt|;
block|}
DECL|function|finishedFromReply
name|void
name|finishedFromReply
parameter_list|()
block|{
name|QNetworkReply
modifier|*
name|reply
init|=
name|qobject_cast
argument_list|<
name|QNetworkReply
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|lateReadyRead
operator|=
literal|false
expr_stmt|;
name|reply
operator|->
name|deleteLater
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
private|private:
DECL|member|progressDlg
name|QProgressDialog
name|progressDlg
decl_stmt|;
DECL|member|netmanager
name|QNetworkAccessManager
name|netmanager
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QNetworkAccessManager_And_QProgressDialog
name|tst_QNetworkAccessManager_And_QProgressDialog
operator|::
name|tst_QNetworkAccessManager_And_QProgressDialog
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QNetworkAccessManager_And_QProgressDialog
operator|::
name|initTestCase
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QtNetworkSettings
operator|::
name|verifyTestNetworkSettings
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"No network test server available"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|downloadCheck_data
name|void
name|tst_QNetworkAccessManager_And_QProgressDialog
operator|::
name|downloadCheck_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"useZeroCopy"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"with-zeroCopy"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"without-zeroCopy"
argument_list|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|downloadCheck
name|void
name|tst_QNetworkAccessManager_And_QProgressDialog
operator|::
name|downloadCheck
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|useZeroCopy
argument_list|)
expr_stmt|;
name|DownloadCheckWidget
name|widget
decl_stmt|;
name|widget
operator|.
name|zeroCopy
operator|=
name|useZeroCopy
expr_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
comment|// run and exit on finished()
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|10
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
comment|// run some more to catch the late readyRead() (or: to not catch it)
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|)
expr_stmt|;
comment|// the following fails when a readyRead() was received after finished()
name|QVERIFY
argument_list|(
operator|!
name|widget
operator|.
name|lateReadyRead
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QNetworkAccessManager_And_QProgressDialog
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qnetworkaccessmanager_and_qprogressdialog.moc"
end_include
end_unit
