begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGET_H
end_ifndef
begin_define
DECL|macro|QGET_H
define|#
directive|define
name|QGET_H
end_define
begin_include
include|#
directive|include
file|<QNetworkAccessManager>
end_include
begin_include
include|#
directive|include
file|<QNetworkRequest>
end_include
begin_include
include|#
directive|include
file|<QNetworkReply>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_decl_stmt
name|class
name|TransferItem
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Method
block|{
name|Get
block|,
name|Put
block|,
name|Post
block|}
block|;
name|TransferItem
argument_list|(
argument|const QNetworkRequest&r
argument_list|,
argument|const QString&u
argument_list|,
argument|const QString&p
argument_list|,
argument|QNetworkAccessManager&n
argument_list|,
argument|Method m
argument_list|)
block|;
name|void
name|start
argument_list|()
block|;
name|signals
operator|:
name|void
name|downloadFinished
argument_list|(
name|TransferItem
operator|*
name|self
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|progress
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
block|;
name|public
operator|:
name|Method
name|method
block|;
name|QNetworkRequest
name|request
block|;
name|QNetworkReply
operator|*
name|reply
block|;
name|QNetworkAccessManager
operator|&
name|nam
block|;
name|QFile
operator|*
name|inputFile
block|;
name|QFile
operator|*
name|outputFile
block|;
name|QList
operator|<
name|QUrl
operator|>
name|redirects
block|;
name|QString
name|user
block|;
name|QString
name|password
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|DownloadItem
range|:
name|public
name|TransferItem
block|{
name|Q_OBJECT
name|public
operator|:
name|DownloadItem
argument_list|(
specifier|const
name|QNetworkRequest
operator|&
name|r
argument_list|,
specifier|const
name|QString
operator|&
name|user
argument_list|,
specifier|const
name|QString
operator|&
name|password
argument_list|,
name|QNetworkAccessManager
operator|&
name|nam
argument_list|)
block|;
operator|~
name|DownloadItem
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|readyRead
argument_list|()
block|;
name|void
name|finished
argument_list|()
block|;
name|private
operator|:
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|UploadItem
range|:
name|public
name|TransferItem
block|{
name|Q_OBJECT
name|public
operator|:
name|UploadItem
argument_list|(
argument|const QNetworkRequest&r
argument_list|,
argument|const QString&user
argument_list|,
argument|const QString&password
argument_list|,
argument|QNetworkAccessManager&nam
argument_list|,
argument|QFile *f
argument_list|,
argument|TransferItem::Method method
argument_list|)
block|;
operator|~
name|UploadItem
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|finished
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|DownloadManager
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|DownloadManager
argument_list|()
block|;
operator|~
name|DownloadManager
argument_list|()
block|;
name|void
name|get
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|,
specifier|const
name|QString
operator|&
name|user
argument_list|,
specifier|const
name|QString
operator|&
name|password
argument_list|)
block|;
name|void
name|upload
argument_list|(
argument|const QUrl&url
argument_list|,
argument|const QString&user
argument_list|,
argument|const QString&password
argument_list|,
argument|const QString&filename
argument_list|,
argument|const QString&contentType
argument_list|,
argument|TransferItem::Method method
argument_list|)
block|;
name|void
name|setProxy
argument_list|(
argument|const QNetworkProxy&proxy
argument_list|)
block|{
name|nam
operator|.
name|setProxy
argument_list|(
name|proxy
argument_list|)
block|; }
name|void
name|setProxyUser
argument_list|(
argument|const QString&user
argument_list|)
block|{
name|proxyUser
operator|=
name|user
block|; }
name|void
name|setProxyPassword
argument_list|(
argument|const QString&password
argument_list|)
block|{
name|proxyPassword
operator|=
name|password
block|; }
expr|enum
name|QueueMode
block|{
name|Parallel
block|,
name|Serial
block|}
block|;
name|void
name|setQueueMode
argument_list|(
argument|QueueMode mode
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|checkForAllDone
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|finished
argument_list|(
name|QNetworkReply
operator|*
name|reply
argument_list|)
block|;
name|void
name|authenticationRequired
argument_list|(
name|QNetworkReply
operator|*
name|reply
argument_list|,
name|QAuthenticator
operator|*
name|authenticator
argument_list|)
block|;
name|void
name|proxyAuthenticationRequired
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|proxy
argument_list|,
name|QAuthenticator
operator|*
name|authenticator
argument_list|)
block|;
name|void
name|sslErrors
argument_list|(
name|QNetworkReply
operator|*
name|reply
argument_list|,
specifier|const
name|QList
operator|<
name|QSslError
operator|>
operator|&
name|errors
argument_list|)
block|;
name|void
name|downloadFinished
argument_list|(
name|TransferItem
operator|*
name|item
argument_list|)
block|;
name|private
operator|:
name|TransferItem
operator|*
name|findTransfer
argument_list|(
name|QNetworkReply
operator|*
name|reply
argument_list|)
block|;
name|QNetworkAccessManager
name|nam
block|;
name|QList
operator|<
name|TransferItem
operator|*
operator|>
name|transfers
block|;
name|QString
name|proxyUser
block|;
name|QString
name|proxyPassword
block|;
name|QueueMode
name|queueMode
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGET_H
end_comment
end_unit
