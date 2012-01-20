begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_class
DECL|class|tst_qhttpnetworkconnection
class|class
name|tst_qhttpnetworkconnection
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|bigRemoteFile
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|bigRemoteFile
name|void
name|tst_qhttpnetworkconnection
operator|::
name|bigRemoteFile
parameter_list|()
block|{
name|QNetworkAccessManager
name|manager
decl_stmt|;
name|qint64
name|size
decl_stmt|;
name|QTime
name|t
decl_stmt|;
name|QNetworkRequest
name|request
argument_list|(
name|QUrl
argument_list|(
literal|"http://nds1.nokia.com/files/support/global/phones/software/Nokia_Ovi_Suite_webinstaller.exe"
argument_list|)
argument_list|)
decl_stmt|;
name|QNetworkReply
modifier|*
name|reply
init|=
name|manager
operator|.
name|get
argument_list|(
name|request
argument_list|)
decl_stmt|;
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
name|QTestEventLoop
operator|::
name|instance
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|exitLoop
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Starting download"
expr_stmt|;
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|50
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
name|size
operator|=
name|reply
operator|->
name|size
argument_list|()
expr_stmt|;
operator|delete
name|reply
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Finished!"
operator|<<
name|endl
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Time:"
operator|<<
name|t
operator|.
name|elapsed
argument_list|()
operator|<<
literal|"msec"
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Bytes:"
operator|<<
name|size
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Speed:"
operator|<<
operator|(
name|size
operator|/
literal|1024
operator|)
operator|/
operator|(
name|t
operator|.
name|elapsed
argument_list|()
operator|/
literal|1000
operator|)
operator|<<
literal|"KB/sec"
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qhttpnetworkconnection
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
