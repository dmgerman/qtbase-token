begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qmutex.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qurl.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<wininet.h>
end_include
begin_include
include|#
directive|include
file|<private/qsystemlibrary_p.h>
end_include
begin_comment
comment|/*  * Information on the WinHTTP DLL:  *  http://msdn.microsoft.com/en-us/library/aa384122(VS.85).aspx example for WPAD  *  *  http://msdn.microsoft.com/en-us/library/aa384097(VS.85).aspx WinHttpGetProxyForUrl  *  http://msdn.microsoft.com/en-us/library/aa384096(VS.85).aspx WinHttpGetIEProxyConfigForCurrentUs  *  http://msdn.microsoft.com/en-us/library/aa384095(VS.85).aspx WinHttpGetDefaultProxyConfiguration  */
end_comment
begin_comment
comment|// We don't want to include winhttp.h because that's not
end_comment
begin_comment
comment|// present in some Windows SDKs (I don't know why)
end_comment
begin_comment
comment|// So, instead, copy the definitions here
end_comment
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|dwFlags
name|DWORD
name|dwFlags
decl_stmt|;
DECL|member|dwAutoDetectFlags
name|DWORD
name|dwAutoDetectFlags
decl_stmt|;
DECL|member|lpszAutoConfigUrl
name|LPCWSTR
name|lpszAutoConfigUrl
decl_stmt|;
DECL|member|lpvReserved
name|LPVOID
name|lpvReserved
decl_stmt|;
DECL|member|dwReserved
name|DWORD
name|dwReserved
decl_stmt|;
DECL|member|fAutoLogonIfChallenged
name|BOOL
name|fAutoLogonIfChallenged
decl_stmt|;
block|}
DECL|typedef|WINHTTP_AUTOPROXY_OPTIONS
name|WINHTTP_AUTOPROXY_OPTIONS
typedef|;
end_typedef
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|dwAccessType
name|DWORD
name|dwAccessType
decl_stmt|;
DECL|member|lpszProxy
name|LPWSTR
name|lpszProxy
decl_stmt|;
DECL|member|lpszProxyBypass
name|LPWSTR
name|lpszProxyBypass
decl_stmt|;
block|}
DECL|typedef|WINHTTP_PROXY_INFO
name|WINHTTP_PROXY_INFO
typedef|;
end_typedef
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|fAutoDetect
name|BOOL
name|fAutoDetect
decl_stmt|;
DECL|member|lpszAutoConfigUrl
name|LPWSTR
name|lpszAutoConfigUrl
decl_stmt|;
DECL|member|lpszProxy
name|LPWSTR
name|lpszProxy
decl_stmt|;
DECL|member|lpszProxyBypass
name|LPWSTR
name|lpszProxyBypass
decl_stmt|;
block|}
DECL|typedef|WINHTTP_CURRENT_USER_IE_PROXY_CONFIG
name|WINHTTP_CURRENT_USER_IE_PROXY_CONFIG
typedef|;
end_typedef
begin_define
DECL|macro|WINHTTP_AUTOPROXY_AUTO_DETECT
define|#
directive|define
name|WINHTTP_AUTOPROXY_AUTO_DETECT
value|0x00000001
end_define
begin_define
DECL|macro|WINHTTP_AUTOPROXY_CONFIG_URL
define|#
directive|define
name|WINHTTP_AUTOPROXY_CONFIG_URL
value|0x00000002
end_define
begin_define
DECL|macro|WINHTTP_AUTO_DETECT_TYPE_DHCP
define|#
directive|define
name|WINHTTP_AUTO_DETECT_TYPE_DHCP
value|0x00000001
end_define
begin_define
DECL|macro|WINHTTP_AUTO_DETECT_TYPE_DNS_A
define|#
directive|define
name|WINHTTP_AUTO_DETECT_TYPE_DNS_A
value|0x00000002
end_define
begin_define
DECL|macro|WINHTTP_ACCESS_TYPE_DEFAULT_PROXY
define|#
directive|define
name|WINHTTP_ACCESS_TYPE_DEFAULT_PROXY
value|0
end_define
begin_define
DECL|macro|WINHTTP_ACCESS_TYPE_NO_PROXY
define|#
directive|define
name|WINHTTP_ACCESS_TYPE_NO_PROXY
value|1
end_define
begin_define
DECL|macro|WINHTTP_ACCESS_TYPE_NAMED_PROXY
define|#
directive|define
name|WINHTTP_ACCESS_TYPE_NAMED_PROXY
value|3
end_define
begin_define
DECL|macro|WINHTTP_NO_PROXY_NAME
define|#
directive|define
name|WINHTTP_NO_PROXY_NAME
value|NULL
end_define
begin_define
DECL|macro|WINHTTP_NO_PROXY_BYPASS
define|#
directive|define
name|WINHTTP_NO_PROXY_BYPASS
value|NULL
end_define
begin_define
DECL|macro|WINHTTP_ERROR_BASE
define|#
directive|define
name|WINHTTP_ERROR_BASE
value|12000
end_define
begin_define
DECL|macro|ERROR_WINHTTP_LOGIN_FAILURE
define|#
directive|define
name|ERROR_WINHTTP_LOGIN_FAILURE
value|(WINHTTP_ERROR_BASE + 15)
end_define
begin_define
DECL|macro|ERROR_WINHTTP_AUTODETECTION_FAILED
define|#
directive|define
name|ERROR_WINHTTP_AUTODETECTION_FAILED
value|(WINHTTP_ERROR_BASE + 180)
end_define
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|PtrWinHttpGetProxyForUrl
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PtrWinHttpGetProxyForUrl
function_decl|)
parameter_list|(
name|HINTERNET
parameter_list|,
name|LPCWSTR
parameter_list|,
name|WINHTTP_AUTOPROXY_OPTIONS
modifier|*
parameter_list|,
name|WINHTTP_PROXY_INFO
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrWinHttpOpen
typedef|typedef
name|HINTERNET
function_decl|(
name|WINAPI
modifier|*
name|PtrWinHttpOpen
function_decl|)
parameter_list|(
name|LPCWSTR
parameter_list|,
name|DWORD
parameter_list|,
name|LPCWSTR
parameter_list|,
name|LPCWSTR
parameter_list|,
name|DWORD
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrWinHttpGetDefaultProxyConfiguration
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PtrWinHttpGetDefaultProxyConfiguration
function_decl|)
parameter_list|(
name|WINHTTP_PROXY_INFO
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrWinHttpGetIEProxyConfigForCurrentUser
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PtrWinHttpGetIEProxyConfigForCurrentUser
function_decl|)
parameter_list|(
name|WINHTTP_CURRENT_USER_IE_PROXY_CONFIG
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrWinHttpCloseHandle
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PtrWinHttpCloseHandle
function_decl|)
parameter_list|(
name|HINTERNET
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|ptrWinHttpGetProxyForUrl
specifier|static
name|PtrWinHttpGetProxyForUrl
name|ptrWinHttpGetProxyForUrl
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ptrWinHttpOpen
specifier|static
name|PtrWinHttpOpen
name|ptrWinHttpOpen
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ptrWinHttpGetDefaultProxyConfiguration
specifier|static
name|PtrWinHttpGetDefaultProxyConfiguration
name|ptrWinHttpGetDefaultProxyConfiguration
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ptrWinHttpGetIEProxyConfigForCurrentUser
specifier|static
name|PtrWinHttpGetIEProxyConfigForCurrentUser
name|ptrWinHttpGetIEProxyConfigForCurrentUser
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ptrWinHttpCloseHandle
specifier|static
name|PtrWinHttpCloseHandle
name|ptrWinHttpCloseHandle
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|splitSpaceSemicolon
specifier|static
name|QStringList
name|splitSpaceSemicolon
parameter_list|(
specifier|const
name|QString
modifier|&
name|source
parameter_list|)
block|{
name|QStringList
name|list
decl_stmt|;
name|int
name|start
init|=
literal|0
decl_stmt|;
name|int
name|end
decl_stmt|;
while|while
condition|(
literal|true
condition|)
block|{
name|int
name|space
init|=
name|source
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|,
name|start
argument_list|)
decl_stmt|;
name|int
name|semicolon
init|=
name|source
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|';'
argument_list|)
argument_list|,
name|start
argument_list|)
decl_stmt|;
name|end
operator|=
name|space
expr_stmt|;
if|if
condition|(
name|semicolon
operator|!=
operator|-
literal|1
operator|&&
operator|(
name|end
operator|==
operator|-
literal|1
operator|||
name|semicolon
operator|<
name|end
operator|)
condition|)
name|end
operator|=
name|semicolon
expr_stmt|;
if|if
condition|(
name|end
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|start
operator|!=
name|source
operator|.
name|length
argument_list|()
condition|)
name|list
operator|.
name|append
argument_list|(
name|source
operator|.
name|mid
argument_list|(
name|start
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|list
return|;
block|}
if|if
condition|(
name|start
operator|!=
name|end
condition|)
name|list
operator|.
name|append
argument_list|(
name|source
operator|.
name|mid
argument_list|(
name|start
argument_list|,
name|end
operator|-
name|start
argument_list|)
argument_list|)
expr_stmt|;
name|start
operator|=
name|end
operator|+
literal|1
expr_stmt|;
block|}
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|isBypassed
specifier|static
name|bool
name|isBypassed
parameter_list|(
specifier|const
name|QString
modifier|&
name|host
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|bypassList
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
comment|// does it match the list of exclusions?
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|entry
decl|,
name|bypassList
control|)
block|{
if|if
condition|(
name|isSimple
operator|&&
name|entry
operator|==
name|QLatin1String
argument_list|(
literal|"<local>"
argument_list|)
condition|)
return|return
literal|true
return|;
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
DECL|function|parseServerList
specifier|static
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|parseServerList
parameter_list|(
specifier|const
name|QNetworkProxyQuery
modifier|&
name|query
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|proxyList
parameter_list|)
block|{
comment|// Reference documentation from Microsoft:
comment|// http://msdn.microsoft.com/en-us/library/aa383912(VS.85).aspx
comment|//
comment|// According to the website, the proxy server list is
comment|// one or more of the space- or semicolon-separated strings in the format:
comment|//   ([<scheme>=][<scheme>"://"]<server>[":"<port>])
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|result
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|entry
decl|,
name|proxyList
control|)
block|{
name|int
name|server
init|=
literal|0
decl_stmt|;
name|int
name|pos
init|=
name|entry
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'='
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|pos
operator|!=
operator|-
literal|1
condition|)
block|{
name|QStringRef
name|scheme
init|=
name|entry
operator|.
name|leftRef
argument_list|(
name|pos
argument_list|)
decl_stmt|;
if|if
condition|(
name|scheme
operator|!=
name|query
operator|.
name|protocolTag
argument_list|()
condition|)
continue|continue;
name|server
operator|=
name|pos
operator|+
literal|1
expr_stmt|;
block|}
name|QNetworkProxy
operator|::
name|ProxyType
name|proxyType
init|=
name|QNetworkProxy
operator|::
name|HttpProxy
decl_stmt|;
name|quint16
name|port
init|=
literal|8080
decl_stmt|;
name|pos
operator|=
name|entry
operator|.
name|indexOf
argument_list|(
name|QLatin1String
argument_list|(
literal|"://"
argument_list|)
argument_list|,
name|server
argument_list|)
expr_stmt|;
if|if
condition|(
name|pos
operator|!=
operator|-
literal|1
condition|)
block|{
name|QStringRef
name|scheme
init|=
name|entry
operator|.
name|midRef
argument_list|(
name|server
argument_list|,
name|pos
operator|-
name|server
argument_list|)
decl_stmt|;
if|if
condition|(
name|scheme
operator|==
name|QLatin1String
argument_list|(
literal|"http"
argument_list|)
operator|||
name|scheme
operator|==
name|QLatin1String
argument_list|(
literal|"https"
argument_list|)
condition|)
block|{
comment|// no-op
comment|// defaults are above
block|}
elseif|else
if|if
condition|(
name|scheme
operator|==
name|QLatin1String
argument_list|(
literal|"socks"
argument_list|)
operator|||
name|scheme
operator|==
name|QLatin1String
argument_list|(
literal|"socks5"
argument_list|)
condition|)
block|{
name|proxyType
operator|=
name|QNetworkProxy
operator|::
name|Socks5Proxy
expr_stmt|;
name|port
operator|=
literal|1080
expr_stmt|;
block|}
else|else
block|{
comment|// unknown proxy type
continue|continue;
block|}
name|server
operator|=
name|pos
operator|+
literal|3
expr_stmt|;
block|}
name|pos
operator|=
name|entry
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|,
name|server
argument_list|)
expr_stmt|;
if|if
condition|(
name|pos
operator|!=
operator|-
literal|1
condition|)
block|{
name|bool
name|ok
decl_stmt|;
name|uint
name|value
init|=
name|entry
operator|.
name|mid
argument_list|(
name|pos
operator|+
literal|1
argument_list|)
operator|.
name|toUInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
operator|||
name|value
operator|>
literal|65535
condition|)
continue|continue;
comment|// invalid port number
name|port
operator|=
name|value
expr_stmt|;
block|}
else|else
block|{
name|pos
operator|=
name|entry
operator|.
name|length
argument_list|()
expr_stmt|;
block|}
name|result
operator|<<
name|QNetworkProxy
argument_list|(
name|proxyType
argument_list|,
name|entry
operator|.
name|mid
argument_list|(
name|server
argument_list|,
name|pos
operator|-
name|server
argument_list|)
argument_list|,
name|port
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_class
DECL|class|QWindowsSystemProxy
class|class
name|QWindowsSystemProxy
block|{
public|public:
name|QWindowsSystemProxy
parameter_list|()
constructor_decl|;
name|~
name|QWindowsSystemProxy
parameter_list|()
destructor_decl|;
name|void
name|init
parameter_list|()
function_decl|;
DECL|member|mutex
name|QMutex
name|mutex
decl_stmt|;
DECL|member|hHttpSession
name|HINTERNET
name|hHttpSession
decl_stmt|;
DECL|member|autoProxyOptions
name|WINHTTP_AUTOPROXY_OPTIONS
name|autoProxyOptions
decl_stmt|;
DECL|member|autoConfigUrl
name|QString
name|autoConfigUrl
decl_stmt|;
DECL|member|proxyServerList
name|QStringList
name|proxyServerList
decl_stmt|;
DECL|member|proxyBypass
name|QStringList
name|proxyBypass
decl_stmt|;
DECL|member|defaultResult
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|defaultResult
decl_stmt|;
DECL|member|initialized
name|bool
name|initialized
decl_stmt|;
DECL|member|functional
name|bool
name|functional
decl_stmt|;
DECL|member|isAutoConfig
name|bool
name|isAutoConfig
decl_stmt|;
block|}
class|;
end_class
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QWindowsSystemProxy
argument_list|,
argument|systemProxy
argument_list|)
end_macro
begin_constructor
DECL|function|QWindowsSystemProxy
name|QWindowsSystemProxy
operator|::
name|QWindowsSystemProxy
parameter_list|()
member_init_list|:
name|initialized
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|functional
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|isAutoConfig
argument_list|(
literal|false
argument_list|)
block|{
name|defaultResult
operator|<<
name|QNetworkProxy
operator|::
name|NoProxy
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsSystemProxy
name|QWindowsSystemProxy
operator|::
name|~
name|QWindowsSystemProxy
parameter_list|()
block|{
if|if
condition|(
name|hHttpSession
condition|)
name|ptrWinHttpCloseHandle
argument_list|(
name|hHttpSession
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|init
name|void
name|QWindowsSystemProxy
operator|::
name|init
parameter_list|()
block|{
if|if
condition|(
name|initialized
condition|)
return|return;
name|initialized
operator|=
literal|true
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE
comment|// Windows CE does not have any of the following API
return|return;
else|#
directive|else
comment|// load the winhttp.dll library
name|QSystemLibrary
name|lib
argument_list|(
literal|L"winhttp"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|lib
operator|.
name|load
argument_list|()
condition|)
return|return;
comment|// failed to load
name|ptrWinHttpOpen
operator|=
operator|(
name|PtrWinHttpOpen
operator|)
name|lib
operator|.
name|resolve
argument_list|(
literal|"WinHttpOpen"
argument_list|)
expr_stmt|;
name|ptrWinHttpCloseHandle
operator|=
operator|(
name|PtrWinHttpCloseHandle
operator|)
name|lib
operator|.
name|resolve
argument_list|(
literal|"WinHttpCloseHandle"
argument_list|)
expr_stmt|;
name|ptrWinHttpGetProxyForUrl
operator|=
operator|(
name|PtrWinHttpGetProxyForUrl
operator|)
name|lib
operator|.
name|resolve
argument_list|(
literal|"WinHttpGetProxyForUrl"
argument_list|)
expr_stmt|;
name|ptrWinHttpGetDefaultProxyConfiguration
operator|=
operator|(
name|PtrWinHttpGetDefaultProxyConfiguration
operator|)
name|lib
operator|.
name|resolve
argument_list|(
literal|"WinHttpGetDefaultProxyConfiguration"
argument_list|)
expr_stmt|;
name|ptrWinHttpGetIEProxyConfigForCurrentUser
operator|=
operator|(
name|PtrWinHttpGetIEProxyConfigForCurrentUser
operator|)
name|lib
operator|.
name|resolve
argument_list|(
literal|"WinHttpGetIEProxyConfigForCurrentUser"
argument_list|)
expr_stmt|;
comment|// Try to obtain the Internet Explorer configuration.
name|WINHTTP_CURRENT_USER_IE_PROXY_CONFIG
name|ieProxyConfig
decl_stmt|;
if|if
condition|(
name|ptrWinHttpGetIEProxyConfigForCurrentUser
argument_list|(
operator|&
name|ieProxyConfig
argument_list|)
condition|)
block|{
if|if
condition|(
name|ieProxyConfig
operator|.
name|lpszAutoConfigUrl
condition|)
block|{
name|autoConfigUrl
operator|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|ieProxyConfig
operator|.
name|lpszAutoConfigUrl
argument_list|)
expr_stmt|;
name|GlobalFree
argument_list|(
name|ieProxyConfig
operator|.
name|lpszAutoConfigUrl
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ieProxyConfig
operator|.
name|lpszProxy
condition|)
block|{
comment|// http://msdn.microsoft.com/en-us/library/aa384250%28VS.85%29.aspx speaks only about a "proxy URL",
comment|// not multiple URLs. However we tested this and it can return multiple URLs. So we use splitSpaceSemicolon
comment|// on it.
name|proxyServerList
operator|=
name|splitSpaceSemicolon
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|ieProxyConfig
operator|.
name|lpszProxy
argument_list|)
argument_list|)
expr_stmt|;
name|GlobalFree
argument_list|(
name|ieProxyConfig
operator|.
name|lpszProxy
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ieProxyConfig
operator|.
name|lpszProxyBypass
condition|)
block|{
name|proxyBypass
operator|=
name|splitSpaceSemicolon
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|ieProxyConfig
operator|.
name|lpszProxyBypass
argument_list|)
argument_list|)
expr_stmt|;
name|GlobalFree
argument_list|(
name|ieProxyConfig
operator|.
name|lpszProxyBypass
argument_list|)
expr_stmt|;
block|}
block|}
name|hHttpSession
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|ieProxyConfig
operator|.
name|fAutoDetect
operator|||
operator|!
name|autoConfigUrl
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// using proxy autoconfiguration
name|proxyServerList
operator|.
name|clear
argument_list|()
expr_stmt|;
name|proxyBypass
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// open the handle and obtain the options
name|hHttpSession
operator|=
name|ptrWinHttpOpen
argument_list|(
literal|L"Qt System Proxy access/1.0"
argument_list|,
name|WINHTTP_ACCESS_TYPE_NO_PROXY
argument_list|,
name|WINHTTP_NO_PROXY_NAME
argument_list|,
name|WINHTTP_NO_PROXY_BYPASS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hHttpSession
condition|)
return|return;
name|isAutoConfig
operator|=
literal|true
expr_stmt|;
name|memset
argument_list|(
operator|&
name|autoProxyOptions
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
name|autoProxyOptions
argument_list|)
expr_stmt|;
name|autoProxyOptions
operator|.
name|fAutoLogonIfChallenged
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|ieProxyConfig
operator|.
name|fAutoDetect
condition|)
block|{
name|autoProxyOptions
operator|.
name|dwFlags
operator|=
name|WINHTTP_AUTOPROXY_AUTO_DETECT
expr_stmt|;
name|autoProxyOptions
operator|.
name|dwAutoDetectFlags
operator|=
name|WINHTTP_AUTO_DETECT_TYPE_DHCP
operator||
name|WINHTTP_AUTO_DETECT_TYPE_DNS_A
expr_stmt|;
block|}
else|else
block|{
name|autoProxyOptions
operator|.
name|dwFlags
operator|=
name|WINHTTP_AUTOPROXY_CONFIG_URL
expr_stmt|;
name|autoProxyOptions
operator|.
name|lpszAutoConfigUrl
operator|=
operator|(
name|LPCWSTR
operator|)
name|autoConfigUrl
operator|.
name|utf16
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// not auto-detected
comment|// attempt to get the static configuration instead
name|WINHTTP_PROXY_INFO
name|proxyInfo
decl_stmt|;
if|if
condition|(
name|ptrWinHttpGetDefaultProxyConfiguration
argument_list|(
operator|&
name|proxyInfo
argument_list|)
operator|&&
name|proxyInfo
operator|.
name|dwAccessType
operator|==
name|WINHTTP_ACCESS_TYPE_NAMED_PROXY
condition|)
block|{
comment|// we got information from the registry
comment|// overwrite the IE configuration, if any
name|proxyBypass
operator|=
name|splitSpaceSemicolon
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|proxyInfo
operator|.
name|lpszProxyBypass
argument_list|)
argument_list|)
expr_stmt|;
name|proxyServerList
operator|=
name|splitSpaceSemicolon
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|proxyInfo
operator|.
name|lpszProxy
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|proxyInfo
operator|.
name|lpszProxy
condition|)
name|GlobalFree
argument_list|(
name|proxyInfo
operator|.
name|lpszProxy
argument_list|)
expr_stmt|;
if|if
condition|(
name|proxyInfo
operator|.
name|lpszProxyBypass
condition|)
name|GlobalFree
argument_list|(
name|proxyInfo
operator|.
name|lpszProxyBypass
argument_list|)
expr_stmt|;
block|}
name|functional
operator|=
name|isAutoConfig
operator|||
operator|!
name|proxyServerList
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
endif|#
directive|endif
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
name|QWindowsSystemProxy
modifier|*
name|sp
init|=
name|systemProxy
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|sp
condition|)
return|return
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
argument_list|()
operator|<<
name|QNetworkProxy
argument_list|()
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|sp
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|sp
operator|->
name|init
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|sp
operator|->
name|functional
condition|)
return|return
name|sp
operator|->
name|defaultResult
return|;
if|if
condition|(
name|sp
operator|->
name|isAutoConfig
condition|)
block|{
name|WINHTTP_PROXY_INFO
name|proxyInfo
decl_stmt|;
comment|// try to get the proxy config for the URL
name|QUrl
name|url
init|=
name|query
operator|.
name|url
argument_list|()
decl_stmt|;
comment|// url could be empty, e.g. from QNetworkProxy::applicationProxy(), that's fine,
comment|// we'll still ask for the proxy.
comment|// But for a file url, we know we don't need one.
if|if
condition|(
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"file"
argument_list|)
operator|||
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"qrc"
argument_list|)
condition|)
return|return
name|sp
operator|->
name|defaultResult
return|;
if|if
condition|(
name|query
operator|.
name|queryType
argument_list|()
operator|!=
name|QNetworkProxyQuery
operator|::
name|UrlRequest
condition|)
block|{
comment|// change the scheme to https, maybe it'll work
name|url
operator|.
name|setScheme
argument_list|(
name|QLatin1String
argument_list|(
literal|"https"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|bool
name|getProxySucceeded
init|=
name|ptrWinHttpGetProxyForUrl
argument_list|(
name|sp
operator|->
name|hHttpSession
argument_list|,
operator|(
name|LPCWSTR
operator|)
name|url
operator|.
name|toString
argument_list|()
operator|.
name|utf16
argument_list|()
argument_list|,
operator|&
name|sp
operator|->
name|autoProxyOptions
argument_list|,
operator|&
name|proxyInfo
argument_list|)
decl_stmt|;
name|DWORD
name|getProxyError
init|=
name|GetLastError
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|getProxySucceeded
operator|&&
operator|(
name|ERROR_WINHTTP_LOGIN_FAILURE
operator|==
name|getProxyError
operator|)
condition|)
block|{
comment|// We first tried without AutoLogon, because this might prevent caching the result.
comment|// But now we've to enable it (http://msdn.microsoft.com/en-us/library/aa383153%28v=VS.85%29.aspx)
name|sp
operator|->
name|autoProxyOptions
operator|.
name|fAutoLogonIfChallenged
operator|=
name|TRUE
expr_stmt|;
name|getProxySucceeded
operator|=
name|ptrWinHttpGetProxyForUrl
argument_list|(
name|sp
operator|->
name|hHttpSession
argument_list|,
operator|(
name|LPCWSTR
operator|)
name|url
operator|.
name|toString
argument_list|()
operator|.
name|utf16
argument_list|()
argument_list|,
operator|&
name|sp
operator|->
name|autoProxyOptions
argument_list|,
operator|&
name|proxyInfo
argument_list|)
expr_stmt|;
name|getProxyError
operator|=
name|GetLastError
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|getProxySucceeded
condition|)
block|{
comment|// yes, we got a config for this URL
name|QString
name|proxyBypass
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|proxyInfo
operator|.
name|lpszProxyBypass
argument_list|)
decl_stmt|;
name|QStringList
name|proxyServerList
init|=
name|splitSpaceSemicolon
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|proxyInfo
operator|.
name|lpszProxy
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|proxyInfo
operator|.
name|lpszProxy
condition|)
name|GlobalFree
argument_list|(
name|proxyInfo
operator|.
name|lpszProxy
argument_list|)
expr_stmt|;
if|if
condition|(
name|proxyInfo
operator|.
name|lpszProxyBypass
condition|)
name|GlobalFree
argument_list|(
name|proxyInfo
operator|.
name|lpszProxyBypass
argument_list|)
expr_stmt|;
if|if
condition|(
name|isBypassed
argument_list|(
name|query
operator|.
name|peerHostName
argument_list|()
argument_list|,
name|splitSpaceSemicolon
argument_list|(
name|proxyBypass
argument_list|)
argument_list|)
condition|)
return|return
name|sp
operator|->
name|defaultResult
return|;
return|return
name|parseServerList
argument_list|(
name|query
argument_list|,
name|proxyServerList
argument_list|)
return|;
block|}
comment|// GetProxyForUrl failed
if|if
condition|(
name|ERROR_WINHTTP_AUTODETECTION_FAILED
operator|==
name|getProxyError
condition|)
block|{
comment|//No config file could be retrieved on the network.
comment|//Don't search for it next time again.
name|sp
operator|->
name|isAutoConfig
operator|=
literal|false
expr_stmt|;
block|}
return|return
name|sp
operator|->
name|defaultResult
return|;
block|}
comment|// static configuration
if|if
condition|(
name|isBypassed
argument_list|(
name|query
operator|.
name|peerHostName
argument_list|()
argument_list|,
name|sp
operator|->
name|proxyBypass
argument_list|)
condition|)
return|return
name|sp
operator|->
name|defaultResult
return|;
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|result
init|=
name|parseServerList
argument_list|(
name|query
argument_list|,
name|sp
operator|->
name|proxyServerList
argument_list|)
decl_stmt|;
comment|// In some cases, this was empty. See SF task 00062670
if|if
condition|(
name|result
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|sp
operator|->
name|defaultResult
return|;
return|return
name|result
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
