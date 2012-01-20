begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<CoreFoundation/CoreFoundation.h>
end_include
begin_include
include|#
directive|include
file|<SystemConfiguration/SystemConfiguration.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRegExp>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/qendian.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|"private/qcore_mac_p.h"
end_include
begin_comment
comment|/*  * MacOS X has a proxy configuration module in System Preferences (on  * MacOS X 10.5, it's in Network, Advanced), where one can set the  * proxy settings for:  *  * \list  *   \o FTP proxy  *   \o Web Proxy (HTTP)  *   \o Secure Web Proxy (HTTPS)  *   \o Streaming Proxy (RTSP)  *   \o SOCKS Proxy  *   \o Gopher Proxy  *   \o URL for Automatic Proxy Configuration (PAC scripts)  *   \o Bypass list (by default: *.local, 169.254/16)  * \endlist  *  * The matching configuration can be obtained by calling SCDynamicStoreCopyProxies  * (from<SystemConfiguration/SCDynamicStoreCopySpecific.h>). See  * Apple's documentation:  *  * http://developer.apple.com/DOCUMENTATION/Networking/Reference/SysConfig/SCDynamicStoreCopySpecific/CompositePage.html#//apple_ref/c/func/SCDynamicStoreCopyProxies  *  */
end_comment
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|isHostExcluded
specifier|static
name|bool
name|isHostExcluded
parameter_list|(
name|CFDictionaryRef
name|dict
parameter_list|,
specifier|const
name|QString
modifier|&
name|host
parameter_list|)
block|{
if|if
condition|(
name|host
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|true
return|;
name|bool
name|isSimple
init|=
operator|!
name|host
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|)
operator|&&
operator|!
name|host
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
decl_stmt|;
name|CFNumberRef
name|excludeSimples
decl_stmt|;
if|if
condition|(
name|isSimple
operator|&&
operator|(
name|excludeSimples
operator|=
operator|(
name|CFNumberRef
operator|)
name|CFDictionaryGetValue
argument_list|(
name|dict
argument_list|,
name|kSCPropNetProxiesExcludeSimpleHostnames
argument_list|)
operator|)
condition|)
block|{
name|int
name|enabled
decl_stmt|;
if|if
condition|(
name|CFNumberGetValue
argument_list|(
name|excludeSimples
argument_list|,
name|kCFNumberIntType
argument_list|,
operator|&
name|enabled
argument_list|)
operator|&&
name|enabled
condition|)
return|return
literal|true
return|;
block|}
name|QHostAddress
name|ipAddress
decl_stmt|;
name|bool
name|isIpAddress
init|=
name|ipAddress
operator|.
name|setAddress
argument_list|(
name|host
argument_list|)
decl_stmt|;
comment|// not a simple host name
comment|// does it match the list of exclusions?
name|CFArrayRef
name|exclusionList
init|=
operator|(
name|CFArrayRef
operator|)
name|CFDictionaryGetValue
argument_list|(
name|dict
argument_list|,
name|kSCPropNetProxiesExceptionsList
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|exclusionList
condition|)
return|return
literal|false
return|;
name|CFIndex
name|size
init|=
name|CFArrayGetCount
argument_list|(
name|exclusionList
argument_list|)
decl_stmt|;
for|for
control|(
name|CFIndex
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
block|{
name|CFStringRef
name|cfentry
init|=
operator|(
name|CFStringRef
operator|)
name|CFArrayGetValueAtIndex
argument_list|(
name|exclusionList
argument_list|,
name|i
argument_list|)
decl_stmt|;
name|QString
name|entry
init|=
name|QCFString
operator|::
name|toQString
argument_list|(
name|cfentry
argument_list|)
decl_stmt|;
if|if
condition|(
name|isIpAddress
operator|&&
name|ipAddress
operator|.
name|isInSubnet
argument_list|(
name|QHostAddress
operator|::
name|parseSubnet
argument_list|(
name|entry
argument_list|)
argument_list|)
condition|)
block|{
return|return
literal|true
return|;
comment|// excluded
block|}
else|else
block|{
comment|// do wildcard matching
name|QRegExp
name|rx
argument_list|(
name|entry
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|,
name|QRegExp
operator|::
name|Wildcard
argument_list|)
decl_stmt|;
if|if
condition|(
name|rx
operator|.
name|exactMatch
argument_list|(
name|host
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
block|}
comment|// host was not excluded
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|proxyFromDictionary
specifier|static
name|QNetworkProxy
name|proxyFromDictionary
parameter_list|(
name|CFDictionaryRef
name|dict
parameter_list|,
name|QNetworkProxy
operator|::
name|ProxyType
name|type
parameter_list|,
name|CFStringRef
name|enableKey
parameter_list|,
name|CFStringRef
name|hostKey
parameter_list|,
name|CFStringRef
name|portKey
parameter_list|)
block|{
name|CFNumberRef
name|protoEnabled
decl_stmt|;
name|CFNumberRef
name|protoPort
decl_stmt|;
name|CFStringRef
name|protoHost
decl_stmt|;
if|if
condition|(
name|enableKey
operator|&&
operator|(
name|protoEnabled
operator|=
operator|(
name|CFNumberRef
operator|)
name|CFDictionaryGetValue
argument_list|(
name|dict
argument_list|,
name|enableKey
argument_list|)
operator|)
operator|&&
operator|(
name|protoHost
operator|=
operator|(
name|CFStringRef
operator|)
name|CFDictionaryGetValue
argument_list|(
name|dict
argument_list|,
name|hostKey
argument_list|)
operator|)
operator|&&
operator|(
name|protoPort
operator|=
operator|(
name|CFNumberRef
operator|)
name|CFDictionaryGetValue
argument_list|(
name|dict
argument_list|,
name|portKey
argument_list|)
operator|)
condition|)
block|{
name|int
name|enabled
decl_stmt|;
if|if
condition|(
name|CFNumberGetValue
argument_list|(
name|protoEnabled
argument_list|,
name|kCFNumberIntType
argument_list|,
operator|&
name|enabled
argument_list|)
operator|&&
name|enabled
condition|)
block|{
name|QString
name|host
init|=
name|QCFString
operator|::
name|toQString
argument_list|(
name|protoHost
argument_list|)
decl_stmt|;
name|int
name|port
decl_stmt|;
name|CFNumberGetValue
argument_list|(
name|protoPort
argument_list|,
name|kCFNumberIntType
argument_list|,
operator|&
name|port
argument_list|)
expr_stmt|;
return|return
name|QNetworkProxy
argument_list|(
name|type
argument_list|,
name|host
argument_list|,
name|port
argument_list|)
return|;
block|}
block|}
comment|// proxy not enabled
return|return
name|QNetworkProxy
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|macQueryInternal
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|macQueryInternal
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
name|result
decl_stmt|;
comment|// obtain a dictionary to the proxy settings:
name|CFDictionaryRef
name|dict
init|=
name|SCDynamicStoreCopyProxies
argument_list|(
name|NULL
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|dict
condition|)
block|{
name|qWarning
argument_list|(
literal|"QNetworkProxyFactory::systemProxyForQuery: SCDynamicStoreCopyProxies returned NULL"
argument_list|)
expr_stmt|;
return|return
name|result
return|;
comment|// failed
block|}
if|if
condition|(
name|isHostExcluded
argument_list|(
name|dict
argument_list|,
name|query
operator|.
name|peerHostName
argument_list|()
argument_list|)
condition|)
block|{
name|CFRelease
argument_list|(
name|dict
argument_list|)
expr_stmt|;
return|return
name|result
return|;
comment|// no proxy for this host
block|}
comment|// is there a PAC enabled? If so, use it first.
name|CFNumberRef
name|pacEnabled
decl_stmt|;
if|if
condition|(
operator|(
name|pacEnabled
operator|=
operator|(
name|CFNumberRef
operator|)
name|CFDictionaryGetValue
argument_list|(
name|dict
argument_list|,
name|kSCPropNetProxiesProxyAutoConfigEnable
argument_list|)
operator|)
condition|)
block|{
name|int
name|enabled
decl_stmt|;
if|if
condition|(
name|CFNumberGetValue
argument_list|(
name|pacEnabled
argument_list|,
name|kCFNumberIntType
argument_list|,
operator|&
name|enabled
argument_list|)
operator|&&
name|enabled
condition|)
block|{
comment|// PAC is enabled
name|CFStringRef
name|pacUrl
init|=
operator|(
name|CFStringRef
operator|)
name|CFDictionaryGetValue
argument_list|(
name|dict
argument_list|,
name|kSCPropNetProxiesProxyAutoConfigURLString
argument_list|)
decl_stmt|;
name|QString
name|url
init|=
name|QCFString
operator|::
name|toQString
argument_list|(
name|pacUrl
argument_list|)
decl_stmt|;
comment|// ### TODO: Use PAC somehow
block|}
block|}
comment|// no PAC, decide which proxy we're looking for based on the query
name|bool
name|isHttps
init|=
literal|false
decl_stmt|;
name|QString
name|protocol
init|=
name|query
operator|.
name|protocolTag
argument_list|()
operator|.
name|toLower
argument_list|()
decl_stmt|;
comment|// try the protocol-specific proxy
name|QNetworkProxy
name|protocolSpecificProxy
decl_stmt|;
if|if
condition|(
name|protocol
operator|==
name|QLatin1String
argument_list|(
literal|"ftp"
argument_list|)
condition|)
block|{
name|protocolSpecificProxy
operator|=
name|proxyFromDictionary
argument_list|(
name|dict
argument_list|,
name|QNetworkProxy
operator|::
name|FtpCachingProxy
argument_list|,
name|kSCPropNetProxiesFTPEnable
argument_list|,
name|kSCPropNetProxiesFTPProxy
argument_list|,
name|kSCPropNetProxiesFTPPort
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|protocol
operator|==
name|QLatin1String
argument_list|(
literal|"http"
argument_list|)
condition|)
block|{
name|protocolSpecificProxy
operator|=
name|proxyFromDictionary
argument_list|(
name|dict
argument_list|,
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|,
name|kSCPropNetProxiesHTTPEnable
argument_list|,
name|kSCPropNetProxiesHTTPProxy
argument_list|,
name|kSCPropNetProxiesHTTPPort
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|protocol
operator|==
name|QLatin1String
argument_list|(
literal|"https"
argument_list|)
condition|)
block|{
name|isHttps
operator|=
literal|true
expr_stmt|;
name|protocolSpecificProxy
operator|=
name|proxyFromDictionary
argument_list|(
name|dict
argument_list|,
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|,
name|kSCPropNetProxiesHTTPSEnable
argument_list|,
name|kSCPropNetProxiesHTTPSProxy
argument_list|,
name|kSCPropNetProxiesHTTPSPort
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|protocolSpecificProxy
operator|.
name|type
argument_list|()
operator|!=
name|QNetworkProxy
operator|::
name|DefaultProxy
condition|)
name|result
operator|<<
name|protocolSpecificProxy
expr_stmt|;
comment|// let's add SOCKSv5 if present too
name|QNetworkProxy
name|socks5
init|=
name|proxyFromDictionary
argument_list|(
name|dict
argument_list|,
name|QNetworkProxy
operator|::
name|Socks5Proxy
argument_list|,
name|kSCPropNetProxiesSOCKSEnable
argument_list|,
name|kSCPropNetProxiesSOCKSProxy
argument_list|,
name|kSCPropNetProxiesSOCKSPort
argument_list|)
decl_stmt|;
if|if
condition|(
name|socks5
operator|.
name|type
argument_list|()
operator|!=
name|QNetworkProxy
operator|::
name|DefaultProxy
condition|)
name|result
operator|<<
name|socks5
expr_stmt|;
comment|// let's add the HTTPS proxy if present (and if we haven't added
comment|// yet)
if|if
condition|(
operator|!
name|isHttps
condition|)
block|{
name|QNetworkProxy
name|https
init|=
name|proxyFromDictionary
argument_list|(
name|dict
argument_list|,
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|,
name|kSCPropNetProxiesHTTPSEnable
argument_list|,
name|kSCPropNetProxiesHTTPSProxy
argument_list|,
name|kSCPropNetProxiesHTTPSPort
argument_list|)
decl_stmt|;
if|if
condition|(
name|https
operator|.
name|type
argument_list|()
operator|!=
name|QNetworkProxy
operator|::
name|DefaultProxy
operator|&&
name|https
operator|!=
name|protocolSpecificProxy
condition|)
name|result
operator|<<
name|https
expr_stmt|;
block|}
name|CFRelease
argument_list|(
name|dict
argument_list|)
expr_stmt|;
return|return
name|result
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
name|result
init|=
name|macQueryInternal
argument_list|(
name|query
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|.
name|isEmpty
argument_list|()
condition|)
name|result
operator|<<
name|QNetworkProxy
operator|::
name|NoProxy
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
