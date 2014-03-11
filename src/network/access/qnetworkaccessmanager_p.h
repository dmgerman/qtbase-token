begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKACCESSMANAGER_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKACCESSMANAGER_P_H
define|#
directive|define
name|QNETWORKACCESSMANAGER_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the Network Access API.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qnetworkaccessmanager.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkaccesscache_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkaccessbackend_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|"QtNetwork/qnetworkproxy.h"
end_include
begin_include
include|#
directive|include
file|"QtNetwork/qnetworksession.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkaccessauthenticationmanager_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_include
include|#
directive|include
file|"QtNetwork/qnetworkconfigmanager.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAuthenticator
name|class
name|QAuthenticator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractNetworkCache
name|class
name|QAbstractNetworkCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkAuthenticationCredential
name|class
name|QNetworkAuthenticationCredential
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkCookieJar
name|class
name|QNetworkCookieJar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkAccessManagerPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|public
operator|:
name|QNetworkAccessManagerPrivate
argument_list|()
operator|:
name|networkCache
argument_list|(
literal|0
argument_list|)
block|,
name|cookieJar
argument_list|(
literal|0
argument_list|)
block|,
name|httpThread
argument_list|(
literal|0
argument_list|)
block|,
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|proxyFactory
argument_list|(
literal|0
argument_list|)
block|,
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|lastSessionState
argument_list|(
name|QNetworkSession
operator|::
name|Invalid
argument_list|)
block|,
name|networkConfiguration
argument_list|(
name|networkConfigurationManager
operator|.
name|defaultConfiguration
argument_list|()
argument_list|)
block|,
name|customNetworkConfiguration
argument_list|(
name|false
argument_list|)
block|,
name|networkSessionRequired
argument_list|(
name|networkConfigurationManager
operator|.
name|capabilities
argument_list|()
operator|&
name|QNetworkConfigurationManager
operator|::
name|NetworkSessionRequired
argument_list|)
block|,
name|networkAccessible
argument_list|(
name|QNetworkAccessManager
operator|::
name|Accessible
argument_list|)
block|,
name|activeReplyCount
argument_list|(
literal|0
argument_list|)
block|,
name|online
argument_list|(
name|false
argument_list|)
block|,
name|initializeSession
argument_list|(
name|true
argument_list|)
block|,
endif|#
directive|endif
name|cookieJarCreated
argument_list|(
name|false
argument_list|)
block|,
name|authenticationManager
argument_list|(
argument|QSharedPointer<QNetworkAccessAuthenticationManager>::create()
argument_list|)
block|{ }
operator|~
name|QNetworkAccessManagerPrivate
argument_list|()
block|;
name|void
name|_q_replyFinished
argument_list|()
block|;
name|void
name|_q_replyEncrypted
argument_list|()
block|;
name|void
name|_q_replySslErrors
argument_list|(
specifier|const
name|QList
operator|<
name|QSslError
operator|>
operator|&
name|errors
argument_list|)
block|;
name|QNetworkReply
operator|*
name|postProcess
argument_list|(
name|QNetworkReply
operator|*
name|reply
argument_list|)
block|;
name|void
name|createCookieJar
argument_list|()
specifier|const
block|;
name|void
name|authenticationRequired
argument_list|(
argument|QAuthenticator *authenticator
argument_list|,
argument|QNetworkReply *reply
argument_list|,
argument|bool synchronous
argument_list|,
argument|QUrl&url
argument_list|,
argument|QUrl *urlForLastAuthentication
argument_list|,
argument|bool allowAuthenticationReuse = true
argument_list|)
block|;
name|void
name|cacheCredentials
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|,
specifier|const
name|QAuthenticator
operator|*
name|auth
argument_list|)
block|;
name|QNetworkAuthenticationCredential
operator|*
name|fetchCachedCredentials
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|,
specifier|const
name|QAuthenticator
operator|*
name|auth
operator|=
literal|0
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|void
name|proxyAuthenticationRequired
argument_list|(
argument|const QNetworkProxy&proxy
argument_list|,
argument|bool synchronous
argument_list|,
argument|QAuthenticator *authenticator
argument_list|,
argument|QNetworkProxy *lastProxyAuthentication
argument_list|)
block|;
name|void
name|cacheProxyCredentials
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|proxy
argument_list|,
specifier|const
name|QAuthenticator
operator|*
name|auth
argument_list|)
block|;
name|QNetworkAuthenticationCredential
operator|*
name|fetchCachedProxyCredentials
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|proxy
argument_list|,
specifier|const
name|QAuthenticator
operator|*
name|auth
operator|=
literal|0
argument_list|)
block|;
name|QList
operator|<
name|QNetworkProxy
operator|>
name|queryProxy
argument_list|(
specifier|const
name|QNetworkProxyQuery
operator|&
name|query
argument_list|)
block|;
endif|#
directive|endif
name|QNetworkAccessBackend
operator|*
name|findBackend
argument_list|(
argument|QNetworkAccessManager::Operation op
argument_list|,
argument|const QNetworkRequest&request
argument_list|)
block|;
name|QStringList
name|backendSupportedSchemes
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|void
name|createSession
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
name|config
argument_list|)
block|;
name|QSharedPointer
operator|<
name|QNetworkSession
operator|>
name|getNetworkSession
argument_list|()
specifier|const
block|;
name|void
name|_q_networkSessionClosed
argument_list|()
block|;
name|void
name|_q_networkSessionNewConfigurationActivated
argument_list|()
block|;
name|void
name|_q_networkSessionPreferredConfigurationChanged
argument_list|(
argument|const QNetworkConfiguration&config
argument_list|,
argument|bool isSeamless
argument_list|)
block|;
name|void
name|_q_networkSessionStateChanged
argument_list|(
argument|QNetworkSession::State state
argument_list|)
block|;
name|void
name|_q_onlineStateChanged
argument_list|(
argument|bool isOnline
argument_list|)
block|;
endif|#
directive|endif
name|QNetworkRequest
name|prepareMultipart
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
comment|// this is the cache for storing downloaded files
name|QAbstractNetworkCache
operator|*
name|networkCache
block|;
name|QNetworkCookieJar
operator|*
name|cookieJar
block|;
name|QThread
operator|*
name|httpThread
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|QNetworkProxy
name|proxy
block|;
name|QNetworkProxyFactory
operator|*
name|proxyFactory
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|QSharedPointer
operator|<
name|QNetworkSession
operator|>
name|networkSessionStrongRef
block|;
name|QWeakPointer
operator|<
name|QNetworkSession
operator|>
name|networkSessionWeakRef
block|;
name|QNetworkSession
operator|::
name|State
name|lastSessionState
block|;
name|QNetworkConfigurationManager
name|networkConfigurationManager
block|;
name|QNetworkConfiguration
name|networkConfiguration
block|;
comment|// we need to track whether the user set a config or not,
comment|// because the default config might change
name|bool
name|customNetworkConfiguration
block|;
name|bool
name|networkSessionRequired
block|;
name|QNetworkAccessManager
operator|::
name|NetworkAccessibility
name|networkAccessible
block|;
name|int
name|activeReplyCount
block|;
name|bool
name|online
block|;
name|bool
name|initializeSession
block|;
endif|#
directive|endif
name|bool
name|cookieJarCreated
block|;
comment|// The cache with authorization data:
name|QSharedPointer
operator|<
name|QNetworkAccessAuthenticationManager
operator|>
name|authenticationManager
block|;
comment|// this cache can be used by individual backends to cache e.g. their TCP connections to a server
comment|// and use the connections for multiple requests.
name|QNetworkAccessCache
name|objectCache
block|;
specifier|static
specifier|inline
name|QNetworkAccessCache
operator|*
name|getObjectCache
argument_list|(
argument|QNetworkAccessBackend *backend
argument_list|)
block|{
return|return
operator|&
name|backend
operator|->
name|manager
operator|->
name|objectCache
return|;
block|}
name|Q_AUTOTEST_EXPORT
specifier|static
name|void
name|clearCache
argument_list|(
name|QNetworkAccessManager
operator|*
name|manager
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|Q_AUTOTEST_EXPORT
specifier|static
specifier|const
name|QWeakPointer
operator|<
specifier|const
name|QNetworkSession
operator|>
name|getNetworkSession
argument_list|(
specifier|const
name|QNetworkAccessManager
operator|*
name|manager
argument_list|)
block|;
endif|#
directive|endif
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QNetworkAccessManager
argument_list|)
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
