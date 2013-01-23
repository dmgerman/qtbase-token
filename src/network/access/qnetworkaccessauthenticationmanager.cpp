begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkaccessauthenticationmanager_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkaccessmanager.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkaccessmanager_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbuffer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qurl.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvector.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/QMutexLocker"
end_include
begin_include
include|#
directive|include
file|"QtNetwork/qauthenticator.h"
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QNetworkAuthenticationCache
class|class
name|QNetworkAuthenticationCache
super|:
specifier|private
name|QVector
argument_list|<
name|QNetworkAuthenticationCredential
argument_list|>
super|,
specifier|public
name|QNetworkAccessCache
operator|::
name|CacheableObject
block|{
public|public:
DECL|function|QNetworkAuthenticationCache
name|QNetworkAuthenticationCache
parameter_list|()
block|{
name|setExpires
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setShareable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|reserve
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
DECL|function|findClosestMatch
name|QNetworkAuthenticationCredential
modifier|*
name|findClosestMatch
parameter_list|(
specifier|const
name|QString
modifier|&
name|domain
parameter_list|)
block|{
name|iterator
name|it
init|=
name|std
operator|::
name|lower_bound
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|,
name|domain
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|end
argument_list|()
operator|&&
operator|!
name|isEmpty
argument_list|()
condition|)
operator|--
name|it
expr_stmt|;
if|if
condition|(
name|it
operator|==
name|end
argument_list|()
operator|||
operator|!
name|domain
operator|.
name|startsWith
argument_list|(
name|it
operator|->
name|domain
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
operator|&
operator|*
name|it
return|;
block|}
DECL|function|insert
name|void
name|insert
parameter_list|(
specifier|const
name|QString
modifier|&
name|domain
parameter_list|,
specifier|const
name|QString
modifier|&
name|user
parameter_list|,
specifier|const
name|QString
modifier|&
name|password
parameter_list|)
block|{
name|QNetworkAuthenticationCredential
modifier|*
name|closestMatch
init|=
name|findClosestMatch
argument_list|(
name|domain
argument_list|)
decl_stmt|;
if|if
condition|(
name|closestMatch
operator|&&
name|closestMatch
operator|->
name|domain
operator|==
name|domain
condition|)
block|{
comment|// we're overriding the current credentials
name|closestMatch
operator|->
name|user
operator|=
name|user
expr_stmt|;
name|closestMatch
operator|->
name|password
operator|=
name|password
expr_stmt|;
block|}
else|else
block|{
name|QNetworkAuthenticationCredential
name|newCredential
decl_stmt|;
name|newCredential
operator|.
name|domain
operator|=
name|domain
expr_stmt|;
name|newCredential
operator|.
name|user
operator|=
name|user
expr_stmt|;
name|newCredential
operator|.
name|password
operator|=
name|password
expr_stmt|;
if|if
condition|(
name|closestMatch
condition|)
name|QVector
argument_list|<
name|QNetworkAuthenticationCredential
argument_list|>
operator|::
name|insert
argument_list|(
operator|++
name|closestMatch
argument_list|,
name|newCredential
argument_list|)
expr_stmt|;
else|else
name|QVector
argument_list|<
name|QNetworkAuthenticationCredential
argument_list|>
operator|::
name|insert
argument_list|(
name|end
argument_list|()
argument_list|,
name|newCredential
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|dispose
specifier|virtual
name|void
name|dispose
parameter_list|()
block|{
operator|delete
name|this
expr_stmt|;
block|}
block|}
class|;
end_class
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_function
DECL|function|proxyAuthenticationKey
specifier|static
name|QByteArray
name|proxyAuthenticationKey
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
name|proxy
parameter_list|,
specifier|const
name|QString
modifier|&
name|realm
parameter_list|)
block|{
name|QUrl
name|key
decl_stmt|;
switch|switch
condition|(
name|proxy
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QNetworkProxy
operator|::
name|Socks5Proxy
case|:
name|key
operator|.
name|setScheme
argument_list|(
name|QLatin1String
argument_list|(
literal|"proxy-socks5"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkProxy
operator|::
name|HttpProxy
case|:
case|case
name|QNetworkProxy
operator|::
name|HttpCachingProxy
case|:
name|key
operator|.
name|setScheme
argument_list|(
name|QLatin1String
argument_list|(
literal|"proxy-http"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkProxy
operator|::
name|FtpCachingProxy
case|:
name|key
operator|.
name|setScheme
argument_list|(
name|QLatin1String
argument_list|(
literal|"proxy-ftp"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkProxy
operator|::
name|DefaultProxy
case|:
case|case
name|QNetworkProxy
operator|::
name|NoProxy
case|:
comment|// shouldn't happen
return|return
name|QByteArray
argument_list|()
return|;
comment|// no default:
comment|// let there be errors if a new proxy type is added in the future
block|}
if|if
condition|(
name|key
operator|.
name|scheme
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
comment|// proxy type not handled
return|return
name|QByteArray
argument_list|()
return|;
name|key
operator|.
name|setUserName
argument_list|(
name|proxy
operator|.
name|user
argument_list|()
argument_list|)
expr_stmt|;
name|key
operator|.
name|setHost
argument_list|(
name|proxy
operator|.
name|hostName
argument_list|()
argument_list|)
expr_stmt|;
name|key
operator|.
name|setPort
argument_list|(
name|proxy
operator|.
name|port
argument_list|()
argument_list|)
expr_stmt|;
name|key
operator|.
name|setFragment
argument_list|(
name|realm
argument_list|)
expr_stmt|;
return|return
literal|"auth:"
operator|+
name|key
operator|.
name|toEncoded
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|authenticationKey
specifier|static
specifier|inline
name|QByteArray
name|authenticationKey
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|,
specifier|const
name|QString
modifier|&
name|realm
parameter_list|)
block|{
name|QUrl
name|copy
init|=
name|url
decl_stmt|;
name|copy
operator|.
name|setFragment
argument_list|(
name|realm
argument_list|)
expr_stmt|;
return|return
literal|"auth:"
operator|+
name|copy
operator|.
name|toEncoded
argument_list|(
name|QUrl
operator|::
name|RemovePassword
operator||
name|QUrl
operator|::
name|RemovePath
operator||
name|QUrl
operator|::
name|RemoveQuery
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_function
DECL|function|cacheProxyCredentials
name|void
name|QNetworkAccessAuthenticationManager
operator|::
name|cacheProxyCredentials
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
name|p
parameter_list|,
specifier|const
name|QAuthenticator
modifier|*
name|authenticator
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|authenticator
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|p
operator|.
name|type
argument_list|()
operator|!=
name|QNetworkProxy
operator|::
name|DefaultProxy
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|p
operator|.
name|type
argument_list|()
operator|!=
name|QNetworkProxy
operator|::
name|NoProxy
argument_list|)
expr_stmt|;
name|QMutexLocker
name|mutexLocker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|QString
name|realm
init|=
name|authenticator
operator|->
name|realm
argument_list|()
decl_stmt|;
name|QNetworkProxy
name|proxy
init|=
name|p
decl_stmt|;
name|proxy
operator|.
name|setUser
argument_list|(
name|authenticator
operator|->
name|user
argument_list|()
argument_list|)
expr_stmt|;
comment|// don't cache null passwords, empty password may be valid though
if|if
condition|(
name|authenticator
operator|->
name|password
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
return|return;
comment|// Set two credentials: one with the username and one without
do|do
block|{
comment|// Set two credentials actually: one with and one without the realm
do|do
block|{
name|QByteArray
name|cacheKey
init|=
name|proxyAuthenticationKey
argument_list|(
name|proxy
argument_list|,
name|realm
argument_list|)
decl_stmt|;
if|if
condition|(
name|cacheKey
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
comment|// should not happen
name|QNetworkAuthenticationCache
modifier|*
name|auth
init|=
operator|new
name|QNetworkAuthenticationCache
decl_stmt|;
name|auth
operator|->
name|insert
argument_list|(
name|QString
argument_list|()
argument_list|,
name|authenticator
operator|->
name|user
argument_list|()
argument_list|,
name|authenticator
operator|->
name|password
argument_list|()
argument_list|)
expr_stmt|;
name|authenticationCache
operator|.
name|addEntry
argument_list|(
name|cacheKey
argument_list|,
name|auth
argument_list|)
expr_stmt|;
comment|// replace the existing one, if there's any
if|if
condition|(
name|realm
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
break|break;
block|}
else|else
block|{
name|realm
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
do|while
condition|(
literal|true
condition|)
do|;
if|if
condition|(
name|proxy
operator|.
name|user
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
break|break;
else|else
name|proxy
operator|.
name|setUser
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
literal|true
condition|)
do|;
block|}
end_function
begin_function
name|QNetworkAuthenticationCredential
DECL|function|fetchCachedProxyCredentials
name|QNetworkAccessAuthenticationManager
operator|::
name|fetchCachedProxyCredentials
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
name|p
parameter_list|,
specifier|const
name|QAuthenticator
modifier|*
name|authenticator
parameter_list|)
block|{
name|QNetworkProxy
name|proxy
init|=
name|p
decl_stmt|;
if|if
condition|(
name|proxy
operator|.
name|type
argument_list|()
operator|==
name|QNetworkProxy
operator|::
name|DefaultProxy
condition|)
block|{
name|proxy
operator|=
name|QNetworkProxy
operator|::
name|applicationProxy
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|proxy
operator|.
name|password
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QNetworkAuthenticationCredential
argument_list|()
return|;
comment|// no need to set credentials if it already has them
name|QString
name|realm
decl_stmt|;
if|if
condition|(
name|authenticator
condition|)
name|realm
operator|=
name|authenticator
operator|->
name|realm
argument_list|()
expr_stmt|;
name|QMutexLocker
name|mutexLocker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|QByteArray
name|cacheKey
init|=
name|proxyAuthenticationKey
argument_list|(
name|proxy
argument_list|,
name|realm
argument_list|)
decl_stmt|;
if|if
condition|(
name|cacheKey
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QNetworkAuthenticationCredential
argument_list|()
return|;
if|if
condition|(
operator|!
name|authenticationCache
operator|.
name|hasEntry
argument_list|(
name|cacheKey
argument_list|)
condition|)
return|return
name|QNetworkAuthenticationCredential
argument_list|()
return|;
name|QNetworkAuthenticationCache
modifier|*
name|auth
init|=
cast|static_cast
argument_list|<
name|QNetworkAuthenticationCache
operator|*
argument_list|>
argument_list|(
name|authenticationCache
operator|.
name|requestEntryNow
argument_list|(
name|cacheKey
argument_list|)
argument_list|)
decl_stmt|;
name|QNetworkAuthenticationCredential
name|cred
init|=
operator|*
name|auth
operator|->
name|findClosestMatch
argument_list|(
name|QString
argument_list|()
argument_list|)
decl_stmt|;
name|authenticationCache
operator|.
name|releaseEntry
argument_list|(
name|cacheKey
argument_list|)
expr_stmt|;
comment|// proxy cache credentials always have exactly one item
name|Q_ASSERT_X
argument_list|(
operator|!
name|cred
operator|.
name|isNull
argument_list|()
argument_list|,
literal|"QNetworkAccessManager"
argument_list|,
literal|"Internal inconsistency: found a cache key for a proxy, but it's empty"
argument_list|)
expr_stmt|;
return|return
name|cred
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|cacheCredentials
name|void
name|QNetworkAccessAuthenticationManager
operator|::
name|cacheCredentials
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|,
specifier|const
name|QAuthenticator
modifier|*
name|authenticator
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|authenticator
argument_list|)
expr_stmt|;
name|QString
name|domain
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/"
argument_list|)
decl_stmt|;
comment|// FIXME: make QAuthenticator return the domain
name|QString
name|realm
init|=
name|authenticator
operator|->
name|realm
argument_list|()
decl_stmt|;
name|QMutexLocker
name|mutexLocker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
comment|// Set two credentials actually: one with and one without the username in the URL
name|QUrl
name|copy
init|=
name|url
decl_stmt|;
name|copy
operator|.
name|setUserName
argument_list|(
name|authenticator
operator|->
name|user
argument_list|()
argument_list|)
expr_stmt|;
do|do
block|{
name|QByteArray
name|cacheKey
init|=
name|authenticationKey
argument_list|(
name|copy
argument_list|,
name|realm
argument_list|)
decl_stmt|;
if|if
condition|(
name|authenticationCache
operator|.
name|hasEntry
argument_list|(
name|cacheKey
argument_list|)
condition|)
block|{
name|QNetworkAuthenticationCache
modifier|*
name|auth
init|=
cast|static_cast
argument_list|<
name|QNetworkAuthenticationCache
operator|*
argument_list|>
argument_list|(
name|authenticationCache
operator|.
name|requestEntryNow
argument_list|(
name|cacheKey
argument_list|)
argument_list|)
decl_stmt|;
name|auth
operator|->
name|insert
argument_list|(
name|domain
argument_list|,
name|authenticator
operator|->
name|user
argument_list|()
argument_list|,
name|authenticator
operator|->
name|password
argument_list|()
argument_list|)
expr_stmt|;
name|authenticationCache
operator|.
name|releaseEntry
argument_list|(
name|cacheKey
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QNetworkAuthenticationCache
modifier|*
name|auth
init|=
operator|new
name|QNetworkAuthenticationCache
decl_stmt|;
name|auth
operator|->
name|insert
argument_list|(
name|domain
argument_list|,
name|authenticator
operator|->
name|user
argument_list|()
argument_list|,
name|authenticator
operator|->
name|password
argument_list|()
argument_list|)
expr_stmt|;
name|authenticationCache
operator|.
name|addEntry
argument_list|(
name|cacheKey
argument_list|,
name|auth
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|copy
operator|.
name|userName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
break|break;
block|}
else|else
block|{
name|copy
operator|.
name|setUserName
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
do|while
condition|(
literal|true
condition|)
do|;
block|}
end_function
begin_comment
comment|/*!     Fetch the credential data from the credential cache.      If auth is 0 (as it is when called from createRequest()), this will try to     look up with an empty realm. That fails in most cases for HTTP (because the     realm is seldom empty for HTTP challenges). In any case, QHttpNetworkConnection     never sends the credentials on the first attempt: it needs to find out what     authentication methods the server supports.      For FTP, realm is always empty. */
end_comment
begin_function
name|QNetworkAuthenticationCredential
DECL|function|fetchCachedCredentials
name|QNetworkAccessAuthenticationManager
operator|::
name|fetchCachedCredentials
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|,
specifier|const
name|QAuthenticator
modifier|*
name|authentication
parameter_list|)
block|{
if|if
condition|(
operator|!
name|url
operator|.
name|password
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QNetworkAuthenticationCredential
argument_list|()
return|;
comment|// no need to set credentials if it already has them
name|QString
name|realm
decl_stmt|;
if|if
condition|(
name|authentication
condition|)
name|realm
operator|=
name|authentication
operator|->
name|realm
argument_list|()
expr_stmt|;
name|QByteArray
name|cacheKey
init|=
name|authenticationKey
argument_list|(
name|url
argument_list|,
name|realm
argument_list|)
decl_stmt|;
name|QMutexLocker
name|mutexLocker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|authenticationCache
operator|.
name|hasEntry
argument_list|(
name|cacheKey
argument_list|)
condition|)
return|return
name|QNetworkAuthenticationCredential
argument_list|()
return|;
name|QNetworkAuthenticationCache
modifier|*
name|auth
init|=
cast|static_cast
argument_list|<
name|QNetworkAuthenticationCache
operator|*
argument_list|>
argument_list|(
name|authenticationCache
operator|.
name|requestEntryNow
argument_list|(
name|cacheKey
argument_list|)
argument_list|)
decl_stmt|;
name|QNetworkAuthenticationCredential
modifier|*
name|cred
init|=
name|auth
operator|->
name|findClosestMatch
argument_list|(
name|url
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|QNetworkAuthenticationCredential
name|ret
decl_stmt|;
if|if
condition|(
name|cred
condition|)
name|ret
operator|=
operator|*
name|cred
expr_stmt|;
name|authenticationCache
operator|.
name|releaseEntry
argument_list|(
name|cacheKey
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|clearCache
name|void
name|QNetworkAccessAuthenticationManager
operator|::
name|clearCache
parameter_list|()
block|{
name|authenticationCache
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
