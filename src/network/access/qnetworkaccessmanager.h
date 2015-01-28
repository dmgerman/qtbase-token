begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKACCESSMANAGER_H
end_ifndef
begin_define
DECL|macro|QNETWORKACCESSMANAGER_H
define|#
directive|define
name|QNETWORKACCESSMANAGER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SSL
end_ifndef
begin_include
include|#
directive|include
file|<QtNetwork/QSslConfiguration>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QSslPreSharedKeyAuthenticator>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractNetworkCache
name|class
name|QAbstractNetworkCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAuthenticator
name|class
name|QAuthenticator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QByteArray
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QList
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QNetworkCookie
name|class
name|QNetworkCookie
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkCookieJar
name|class
name|QNetworkCookieJar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkRequest
name|class
name|QNetworkRequest
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkReply
name|class
name|QNetworkReply
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkProxy
name|class
name|QNetworkProxy
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkProxyFactory
name|class
name|QNetworkProxyFactory
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslError
name|class
name|QSslError
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_decl_stmt
DECL|variable|QNetworkConfiguration
name|class
name|QNetworkConfiguration
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QHttpMultiPart
name|class
name|QHttpMultiPart
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkReplyImplPrivate
name|class
name|QNetworkReplyImplPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkAccessManagerPrivate
name|class
name|QNetworkAccessManagerPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkAccessManager
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|Q_PROPERTY
argument_list|(
argument|NetworkAccessibility networkAccessible READ networkAccessible WRITE setNetworkAccessible NOTIFY networkAccessibleChanged
argument_list|)
endif|#
directive|endif
name|public
operator|:
expr|enum
name|Operation
block|{
name|HeadOperation
operator|=
literal|1
block|,
name|GetOperation
block|,
name|PutOperation
block|,
name|PostOperation
block|,
name|DeleteOperation
block|,
name|CustomOperation
block|,
name|UnknownOperation
operator|=
literal|0
block|}
block|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
block|enum
name|NetworkAccessibility
block|{
name|UnknownAccessibility
operator|=
operator|-
literal|1
block|,
name|NotAccessible
operator|=
literal|0
block|,
name|Accessible
operator|=
literal|1
block|}
block|;
endif|#
directive|endif
name|explicit
name|QNetworkAccessManager
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNetworkAccessManager
argument_list|()
block|;
comment|// ### Qt 6: turn into virtual
name|QStringList
name|supportedSchemes
argument_list|()
specifier|const
block|;
name|void
name|clearAccessCache
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|QNetworkProxy
name|proxy
argument_list|()
specifier|const
block|;
name|void
name|setProxy
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|proxy
argument_list|)
block|;
name|QNetworkProxyFactory
operator|*
name|proxyFactory
argument_list|()
specifier|const
block|;
name|void
name|setProxyFactory
argument_list|(
name|QNetworkProxyFactory
operator|*
name|factory
argument_list|)
block|;
endif|#
directive|endif
name|QAbstractNetworkCache
operator|*
name|cache
argument_list|()
specifier|const
block|;
name|void
name|setCache
argument_list|(
name|QAbstractNetworkCache
operator|*
name|cache
argument_list|)
block|;
name|QNetworkCookieJar
operator|*
name|cookieJar
argument_list|()
specifier|const
block|;
name|void
name|setCookieJar
argument_list|(
name|QNetworkCookieJar
operator|*
name|cookieJar
argument_list|)
block|;
name|QNetworkReply
operator|*
name|head
argument_list|(
specifier|const
name|QNetworkRequest
operator|&
name|request
argument_list|)
block|;
name|QNetworkReply
operator|*
name|get
argument_list|(
specifier|const
name|QNetworkRequest
operator|&
name|request
argument_list|)
block|;
name|QNetworkReply
operator|*
name|post
argument_list|(
specifier|const
name|QNetworkRequest
operator|&
name|request
argument_list|,
name|QIODevice
operator|*
name|data
argument_list|)
block|;
name|QNetworkReply
operator|*
name|post
argument_list|(
specifier|const
name|QNetworkRequest
operator|&
name|request
argument_list|,
specifier|const
name|QByteArray
operator|&
name|data
argument_list|)
block|;
name|QNetworkReply
operator|*
name|post
argument_list|(
specifier|const
name|QNetworkRequest
operator|&
name|request
argument_list|,
name|QHttpMultiPart
operator|*
name|multiPart
argument_list|)
block|;
name|QNetworkReply
operator|*
name|put
argument_list|(
specifier|const
name|QNetworkRequest
operator|&
name|request
argument_list|,
name|QIODevice
operator|*
name|data
argument_list|)
block|;
name|QNetworkReply
operator|*
name|put
argument_list|(
specifier|const
name|QNetworkRequest
operator|&
name|request
argument_list|,
specifier|const
name|QByteArray
operator|&
name|data
argument_list|)
block|;
name|QNetworkReply
operator|*
name|put
argument_list|(
specifier|const
name|QNetworkRequest
operator|&
name|request
argument_list|,
name|QHttpMultiPart
operator|*
name|multiPart
argument_list|)
block|;
name|QNetworkReply
operator|*
name|deleteResource
argument_list|(
specifier|const
name|QNetworkRequest
operator|&
name|request
argument_list|)
block|;
name|QNetworkReply
operator|*
name|sendCustomRequest
argument_list|(
specifier|const
name|QNetworkRequest
operator|&
name|request
argument_list|,
specifier|const
name|QByteArray
operator|&
name|verb
argument_list|,
name|QIODevice
operator|*
name|data
operator|=
literal|0
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|void
name|setConfiguration
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
name|config
argument_list|)
block|;
name|QNetworkConfiguration
name|configuration
argument_list|()
specifier|const
block|;
name|QNetworkConfiguration
name|activeConfiguration
argument_list|()
specifier|const
block|;
name|void
name|setNetworkAccessible
argument_list|(
argument|NetworkAccessibility accessible
argument_list|)
block|;
name|NetworkAccessibility
name|networkAccessible
argument_list|()
specifier|const
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|void
name|connectToHostEncrypted
argument_list|(
argument|const QString&hostName
argument_list|,
argument|quint16 port =
literal|443
argument_list|,
argument|const QSslConfiguration&sslConfiguration = QSslConfiguration::defaultConfiguration()
argument_list|)
block|;
endif|#
directive|endif
name|void
name|connectToHost
argument_list|(
argument|const QString&hostName
argument_list|,
argument|quint16 port =
literal|80
argument_list|)
block|;
name|Q_SIGNALS
operator|:
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
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
endif|#
directive|endif
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
name|finished
argument_list|(
name|QNetworkReply
operator|*
name|reply
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|void
name|encrypted
argument_list|(
name|QNetworkReply
operator|*
name|reply
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
name|preSharedKeyAuthenticationRequired
argument_list|(
name|QNetworkReply
operator|*
name|reply
argument_list|,
name|QSslPreSharedKeyAuthenticator
operator|*
name|authenticator
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|void
name|networkSessionConnected
argument_list|()
block|;
name|void
name|networkAccessibleChanged
argument_list|(
argument|QNetworkAccessManager::NetworkAccessibility accessible
argument_list|)
block|;
endif|#
directive|endif
name|protected
operator|:
name|virtual
name|QNetworkReply
operator|*
name|createRequest
argument_list|(
argument|Operation op
argument_list|,
argument|const QNetworkRequest&request
argument_list|,
argument|QIODevice *outgoingData =
literal|0
argument_list|)
block|;
name|protected
name|Q_SLOTS
operator|:
name|QStringList
name|supportedSchemesImplementation
argument_list|()
specifier|const
block|;
name|private
operator|:
name|friend
name|class
name|QNetworkReplyImplPrivate
block|;
name|friend
name|class
name|QNetworkReplyHttpImpl
block|;
name|friend
name|class
name|QNetworkReplyHttpImplPrivate
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QNetworkAccessManager
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_replyFinished()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_replyEncrypted()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_replySslErrors(QList<QSslError>)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_replyPreSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator*)
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_networkSessionClosed()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_networkSessionStateChanged(QNetworkSession::State)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_onlineStateChanged(bool)
argument_list|)
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
