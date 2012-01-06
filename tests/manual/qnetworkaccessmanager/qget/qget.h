begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|DownloadItem
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|DownloadItem
argument_list|(
name|QNetworkReply
operator|*
name|r
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
name|QNetworkReply
operator|*
name|networkReply
argument_list|()
block|{
return|return
name|reply
return|;
block|}
name|signals
operator|:
name|void
name|downloadFinished
argument_list|(
name|DownloadItem
operator|*
name|self
argument_list|)
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
name|QNetworkAccessManager
operator|&
name|nam
block|;
name|QNetworkReply
operator|*
name|reply
block|;
name|QFile
name|file
block|;
name|QList
operator|<
name|QUrl
operator|>
name|redirects
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
argument_list|)
block|;
name|void
name|setProxy
argument_list|(
argument|const QNetworkProxy& proxy
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
name|setHttpUser
argument_list|(
argument|const QString& user
argument_list|)
block|{
name|httpUser
operator|=
name|user
block|; }
name|void
name|setHttpPassword
argument_list|(
argument|const QString& password
argument_list|)
block|{
name|httpPassword
operator|=
name|password
block|; }
name|void
name|setProxyUser
argument_list|(
argument|const QString& user
argument_list|)
block|{
name|proxyUser
operator|=
name|user
block|; }
name|void
name|setProxyPassword
argument_list|(
argument|const QString& password
argument_list|)
block|{
name|proxyPassword
operator|=
name|password
block|; }
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
name|DownloadItem
operator|*
name|item
argument_list|)
block|;
name|private
operator|:
name|QNetworkAccessManager
name|nam
block|;
name|QList
operator|<
name|DownloadItem
operator|*
operator|>
name|downloads
block|;
name|QString
name|httpUser
block|;
name|QString
name|httpPassword
block|;
name|QString
name|proxyUser
block|;
name|QString
name|proxyPassword
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
