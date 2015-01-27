begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkproxy.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUrl>
end_include
begin_include
include|#
directive|include
file|<proxy.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QLibProxyWrapper
class|class
name|QLibProxyWrapper
block|{
public|public:
DECL|function|QLibProxyWrapper
name|QLibProxyWrapper
parameter_list|()
member_init_list|:
name|factory
argument_list|(
name|px_proxy_factory_new
argument_list|()
argument_list|)
block|{
if|if
condition|(
operator|!
name|factory
condition|)
name|qWarning
argument_list|(
literal|"libproxy initialization failed."
argument_list|)
expr_stmt|;
block|}
DECL|function|~QLibProxyWrapper
name|~
name|QLibProxyWrapper
parameter_list|()
block|{
name|px_proxy_factory_free
argument_list|(
name|factory
argument_list|)
expr_stmt|;
block|}
name|QList
argument_list|<
name|QUrl
argument_list|>
name|getProxies
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
function_decl|;
private|private:
DECL|member|factory
name|pxProxyFactory
modifier|*
name|factory
decl_stmt|;
block|}
class|;
end_class
begin_expr_stmt
name|Q_GLOBAL_STATIC
argument_list|(
name|QLibProxyWrapper
argument_list|,
name|libProxyWrapper
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*     Gets the list of proxies from libproxy, converted to QUrl list.     Thread safe, according to libproxy documentation. */
end_comment
begin_function
DECL|function|getProxies
name|QList
argument_list|<
name|QUrl
argument_list|>
name|QLibProxyWrapper
operator|::
name|getProxies
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|QList
argument_list|<
name|QUrl
argument_list|>
name|ret
decl_stmt|;
if|if
condition|(
name|factory
condition|)
block|{
name|char
modifier|*
modifier|*
name|proxies
init|=
name|px_proxy_factory_get_proxies
argument_list|(
name|factory
argument_list|,
name|url
operator|.
name|toEncoded
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|proxies
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|proxies
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
block|{
name|ret
operator|.
name|append
argument_list|(
name|QUrl
operator|::
name|fromEncoded
argument_list|(
name|proxies
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|proxies
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|proxies
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|systemProxyForQuery
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|QNetworkProxyFactory
operator|::
name|systemProxyForQuery
parameter_list|(
specifier|const
name|QNetworkProxyQuery
modifier|&
name|query
parameter_list|)
block|{
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|proxyList
decl_stmt|;
name|QUrl
name|queryUrl
decl_stmt|;
name|QNetworkProxy
operator|::
name|Capabilities
name|requiredCapabilities
argument_list|(
literal|0
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|query
operator|.
name|queryType
argument_list|()
condition|)
block|{
comment|//URL requests are directly supported by libproxy
case|case
name|QNetworkProxyQuery
operator|::
name|UrlRequest
case|:
name|queryUrl
operator|=
name|query
operator|.
name|url
argument_list|()
expr_stmt|;
break|break;
comment|// fake URLs to get libproxy to tell us the SOCKS proxy
case|case
name|QNetworkProxyQuery
operator|::
name|TcpSocket
case|:
name|queryUrl
operator|.
name|setScheme
argument_list|(
name|QStringLiteral
argument_list|(
literal|"tcp"
argument_list|)
argument_list|)
expr_stmt|;
name|queryUrl
operator|.
name|setHost
argument_list|(
name|query
operator|.
name|peerHostName
argument_list|()
argument_list|)
expr_stmt|;
name|queryUrl
operator|.
name|setPort
argument_list|(
name|query
operator|.
name|peerPort
argument_list|()
argument_list|)
expr_stmt|;
name|requiredCapabilities
operator||=
name|QNetworkProxy
operator|::
name|TunnelingCapability
expr_stmt|;
break|break;
case|case
name|QNetworkProxyQuery
operator|::
name|UdpSocket
case|:
name|queryUrl
operator|.
name|setScheme
argument_list|(
name|QStringLiteral
argument_list|(
literal|"udp"
argument_list|)
argument_list|)
expr_stmt|;
name|queryUrl
operator|.
name|setHost
argument_list|(
name|query
operator|.
name|peerHostName
argument_list|()
argument_list|)
expr_stmt|;
name|queryUrl
operator|.
name|setPort
argument_list|(
name|query
operator|.
name|peerPort
argument_list|()
argument_list|)
expr_stmt|;
name|requiredCapabilities
operator||=
name|QNetworkProxy
operator|::
name|UdpTunnelingCapability
expr_stmt|;
break|break;
default|default:
name|proxyList
operator|.
name|append
argument_list|(
name|QNetworkProxy
argument_list|(
name|QNetworkProxy
operator|::
name|NoProxy
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|proxyList
return|;
block|}
name|QList
argument_list|<
name|QUrl
argument_list|>
name|rawProxies
init|=
name|libProxyWrapper
argument_list|()
operator|->
name|getProxies
argument_list|(
name|queryUrl
argument_list|)
decl_stmt|;
name|bool
name|haveDirectConnection
init|=
literal|false
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QUrl
modifier|&
name|url
decl|,
name|rawProxies
control|)
block|{
name|QNetworkProxy
operator|::
name|ProxyType
name|type
decl_stmt|;
if|if
condition|(
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QStringLiteral
argument_list|(
literal|"http"
argument_list|)
condition|)
block|{
name|type
operator|=
name|QNetworkProxy
operator|::
name|HttpProxy
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QStringLiteral
argument_list|(
literal|"socks"
argument_list|)
operator|||
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QStringLiteral
argument_list|(
literal|"socks5"
argument_list|)
condition|)
block|{
name|type
operator|=
name|QNetworkProxy
operator|::
name|Socks5Proxy
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QStringLiteral
argument_list|(
literal|"ftp"
argument_list|)
condition|)
block|{
name|type
operator|=
name|QNetworkProxy
operator|::
name|FtpCachingProxy
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QStringLiteral
argument_list|(
literal|"direct"
argument_list|)
condition|)
block|{
name|type
operator|=
name|QNetworkProxy
operator|::
name|NoProxy
expr_stmt|;
name|haveDirectConnection
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
continue|continue;
comment|//unsupported proxy type e.g. socks4
block|}
name|QNetworkProxy
name|proxy
argument_list|(
name|type
argument_list|,
name|url
operator|.
name|host
argument_list|(
name|QUrl
operator|::
name|EncodeUnicode
argument_list|)
argument_list|,
name|url
operator|.
name|port
argument_list|(
literal|0
argument_list|)
argument_list|,
name|url
operator|.
name|userName
argument_list|(
name|QUrl
operator|::
name|FullyDecoded
argument_list|)
argument_list|,
name|url
operator|.
name|password
argument_list|(
name|QUrl
operator|::
name|FullyDecoded
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|proxy
operator|.
name|capabilities
argument_list|()
operator|&
name|requiredCapabilities
operator|==
name|requiredCapabilities
condition|)
name|proxyList
operator|.
name|append
argument_list|(
name|proxy
argument_list|)
expr_stmt|;
block|}
comment|// fallback is direct connection
if|if
condition|(
name|proxyList
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|haveDirectConnection
condition|)
name|proxyList
operator|.
name|append
argument_list|(
name|QNetworkProxy
argument_list|(
name|QNetworkProxy
operator|::
name|NoProxy
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|proxyList
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
