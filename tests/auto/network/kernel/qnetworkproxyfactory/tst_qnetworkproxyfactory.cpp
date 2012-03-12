begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QTest>
end_include
begin_include
include|#
directive|include
file|<QtTest/QTestEventLoop>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qnetworkproxy.h>
end_include
begin_include
include|#
directive|include
file|<QNetworkConfiguration>
end_include
begin_include
include|#
directive|include
file|<QNetworkConfigurationManager>
end_include
begin_include
include|#
directive|include
file|<QNetworkSession>
end_include
begin_include
include|#
directive|include
file|<QNetworkAccessManager>
end_include
begin_include
include|#
directive|include
file|<QNetworkReply>
end_include
begin_include
include|#
directive|include
file|<QNetworkRequest>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_expr_stmt
DECL|variable|QNetworkConfiguration
name|Q_DECLARE_METATYPE
argument_list|(
name|QNetworkConfiguration
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QList
name|Q_DECLARE_METATYPE
argument_list|(
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
argument_list|)
expr_stmt|;
end_expr_stmt
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_class
DECL|class|tst_QNetworkProxyFactory
class|class
name|tst_QNetworkProxyFactory
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QNetworkProxyFactory
parameter_list|()
constructor_decl|;
DECL|class|QDebugProxyFactory
class|class
name|QDebugProxyFactory
super|:
specifier|public
name|QNetworkProxyFactory
block|{
public|public:
DECL|function|queryProxy
specifier|virtual
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|queryProxy
parameter_list|(
specifier|const
name|QNetworkProxyQuery
modifier|&
name|query
init|=
name|QNetworkProxyQuery
argument_list|()
parameter_list|)
block|{
name|returnedList
operator|=
name|QNetworkProxyFactory
operator|::
name|systemProxyForQuery
argument_list|(
name|query
argument_list|)
expr_stmt|;
name|requestCounter
operator|++
expr_stmt|;
return|return
name|returnedList
return|;
block|}
DECL|member|returnedList
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|returnedList
decl_stmt|;
DECL|member|requestCounter
name|int
name|requestCounter
decl_stmt|;
block|}
class|;
private|private
name|slots
private|:
name|void
name|systemProxyForQueryCalledFromThread
parameter_list|()
function_decl|;
name|void
name|systemProxyForQuery_data
parameter_list|()
function_decl|;
name|void
name|systemProxyForQuery
parameter_list|()
specifier|const
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|void
name|fromConfigurations
parameter_list|()
function_decl|;
name|void
name|inNetworkAccessManager_data
parameter_list|()
function_decl|;
name|void
name|inNetworkAccessManager
parameter_list|()
function_decl|;
endif|#
directive|endif
private|private:
name|QString
name|formatProxyName
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
name|proxy
parameter_list|)
specifier|const
function_decl|;
DECL|member|factory
name|QDebugProxyFactory
modifier|*
name|factory
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QNetworkProxyFactory
name|tst_QNetworkProxyFactory
operator|::
name|tst_QNetworkProxyFactory
parameter_list|()
block|{
name|factory
operator|=
operator|new
name|QDebugProxyFactory
expr_stmt|;
name|QNetworkProxyFactory
operator|::
name|setApplicationProxyFactory
argument_list|(
name|factory
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|formatProxyName
name|QString
name|tst_QNetworkProxyFactory
operator|::
name|formatProxyName
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
name|proxy
parameter_list|)
specifier|const
block|{
name|QString
name|proxyName
decl_stmt|;
if|if
condition|(
operator|!
name|proxy
operator|.
name|user
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
name|proxyName
operator|.
name|append
argument_list|(
literal|"%1:%2@"
argument_list|)
operator|.
name|arg
argument_list|(
name|proxy
operator|.
name|user
argument_list|()
argument_list|,
name|proxy
operator|.
name|password
argument_list|()
argument_list|)
expr_stmt|;
name|proxyName
operator|.
name|append
argument_list|(
name|QString
argument_list|(
literal|"%1:%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|proxy
operator|.
name|hostName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|proxy
operator|.
name|port
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|proxyName
operator|.
name|append
argument_list|(
name|QString
argument_list|(
literal|" (type=%1, capabilities=%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|proxy
operator|.
name|type
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|proxy
operator|.
name|capabilities
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|proxyName
return|;
block|}
end_function
begin_function
DECL|function|systemProxyForQuery_data
name|void
name|tst_QNetworkProxyFactory
operator|::
name|systemProxyForQuery_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QUrl
argument_list|>
argument_list|(
literal|"url"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"tag"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"hostName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"port"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"requiredCapabilities"
argument_list|)
expr_stmt|;
comment|//URLs
name|QTest
operator|::
name|newRow
argument_list|(
literal|"http"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|UrlRequest
operator|<<
name|QUrl
argument_list|(
literal|"http://qt-project.org"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
literal|0
operator|<<
literal|0
expr_stmt|;
comment|//windows: "intranet" should be bypassed if "bypass proxy server for local addresses" is ticked
name|QTest
operator|::
name|newRow
argument_list|(
literal|"intranet"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|UrlRequest
operator|<<
name|QUrl
argument_list|(
literal|"http://qt-test-server"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
literal|0
operator|<<
literal|0
expr_stmt|;
comment|//windows: "intranet2" should be bypassed if "*.local" is in the exceptions list (advanced settings)
name|QTest
operator|::
name|newRow
argument_list|(
literal|"intranet2"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|UrlRequest
operator|<<
name|QUrl
argument_list|(
literal|"http://qt-test-server.local"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
literal|0
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"https"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|UrlRequest
operator|<<
name|QUrl
argument_list|(
literal|"https://qt-project.org"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
literal|0
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxy
operator|::
name|TunnelingCapability
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ftp"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|UrlRequest
operator|<<
name|QUrl
argument_list|(
literal|"ftp://qt-project.org"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
literal|0
operator|<<
literal|0
expr_stmt|;
comment|//TCP
name|QTest
operator|::
name|newRow
argument_list|(
literal|"imap"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|TcpSocket
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"qt-project.org"
argument_list|)
operator|<<
literal|0
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxy
operator|::
name|TunnelingCapability
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"autobind-server"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|TcpServer
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
literal|0
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxy
operator|::
name|ListeningCapability
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"web-server"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|TcpServer
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
literal|80
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxy
operator|::
name|ListeningCapability
expr_stmt|;
comment|//UDP
name|QTest
operator|::
name|newRow
argument_list|(
literal|"udp"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|UdpSocket
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
literal|0
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxy
operator|::
name|UdpTunnelingCapability
expr_stmt|;
comment|//Protocol tags
name|QTest
operator|::
name|newRow
argument_list|(
literal|"http-tag"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|TcpSocket
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"http"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"qt-project.org"
argument_list|)
operator|<<
literal|80
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxy
operator|::
name|TunnelingCapability
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ftp-tag"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|TcpSocket
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"ftp"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"qt-project.org"
argument_list|)
operator|<<
literal|21
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxy
operator|::
name|TunnelingCapability
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"https-tag"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|TcpSocket
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"https"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"qt-project.org"
argument_list|)
operator|<<
literal|443
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxy
operator|::
name|TunnelingCapability
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
comment|//in Qt 4.8, "socks" would get the socks proxy, but we dont want to enforce that for all platforms
name|QTest
operator|::
name|newRow
argument_list|(
literal|"socks-tag"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|TcpSocket
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"socks"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"qt-project.org"
argument_list|)
operator|<<
literal|21
operator|<<
call|(
name|int
call|)
argument_list|(
name|QNetworkProxy
operator|::
name|TunnelingCapability
operator||
name|QNetworkProxy
operator|::
name|ListeningCapability
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|//windows: ssh is not a tag provided by the os, but any tunneling proxy is acceptable
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ssh-tag"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|TcpSocket
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"ssh"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"qt-project.org"
argument_list|)
operator|<<
literal|22
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxy
operator|::
name|TunnelingCapability
expr_stmt|;
comment|//Server protocol tags (ftp/http proxies are no good, we need socks or nothing)
name|QTest
operator|::
name|newRow
argument_list|(
literal|"http-server-tag"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|TcpServer
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"http"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
literal|80
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxy
operator|::
name|ListeningCapability
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ftp-server-tag"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|TcpServer
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"ftp"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
literal|21
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxy
operator|::
name|ListeningCapability
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"imap-server-tag"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|TcpServer
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"imap"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
literal|143
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxy
operator|::
name|ListeningCapability
expr_stmt|;
comment|//UDP protocol tag
name|QTest
operator|::
name|newRow
argument_list|(
literal|"sip-udp-tag"
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxyQuery
operator|::
name|UdpSocket
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"sip"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"qt-project.org"
argument_list|)
operator|<<
literal|5061
operator|<<
operator|(
name|int
operator|)
name|QNetworkProxy
operator|::
name|UdpTunnelingCapability
expr_stmt|;
block|}
end_function
begin_function
DECL|function|systemProxyForQuery
name|void
name|tst_QNetworkProxyFactory
operator|::
name|systemProxyForQuery
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QUrl
argument_list|,
name|url
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|tag
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|hostName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|port
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|requiredCapabilities
argument_list|)
expr_stmt|;
name|QNetworkProxyQuery
name|query
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QNetworkProxyQuery
operator|::
name|UrlRequest
case|:
name|query
operator|=
name|QNetworkProxyQuery
argument_list|(
name|url
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkProxyQuery
operator|::
name|TcpSocket
case|:
case|case
name|QNetworkProxyQuery
operator|::
name|UdpSocket
case|:
name|query
operator|=
name|QNetworkProxyQuery
argument_list|(
name|hostName
argument_list|,
name|port
argument_list|,
name|tag
argument_list|,
name|QNetworkProxyQuery
operator|::
name|QueryType
argument_list|(
name|type
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkProxyQuery
operator|::
name|TcpServer
case|:
name|query
operator|=
name|QNetworkProxyQuery
argument_list|(
name|quint16
argument_list|(
name|port
argument_list|)
argument_list|,
name|tag
argument_list|)
expr_stmt|;
break|break;
block|}
name|QElapsedTimer
name|sw
decl_stmt|;
name|sw
operator|.
name|start
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|systemProxyList
init|=
name|QNetworkProxyFactory
operator|::
name|systemProxyForQuery
argument_list|(
name|query
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|sw
operator|.
name|elapsed
argument_list|()
operator|<<
literal|"ms"
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|systemProxyList
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
comment|// for manual comparison with system
name|qDebug
argument_list|()
operator|<<
name|systemProxyList
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QNetworkProxy
modifier|&
name|proxy
decl|,
name|systemProxyList
control|)
block|{
name|QVERIFY
argument_list|(
operator|(
name|requiredCapabilities
operator|==
literal|0
operator|)
operator|||
operator|(
name|proxy
operator|.
name|capabilities
argument_list|()
operator|&
name|requiredCapabilities
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_comment
comment|//Purpose of this test is just to check systemProxyForQuery doesn't hang or crash
end_comment
begin_comment
comment|//with any given configuration including no configuration.
end_comment
begin_comment
comment|//We can't test it returns the right proxies without implementing the native proxy code
end_comment
begin_comment
comment|//again here, which would be testing our implementation against itself.
end_comment
begin_comment
comment|//Therefore it's just testing that something valid is returned (at least a NoProxy entry)
end_comment
begin_function
DECL|function|fromConfigurations
name|void
name|tst_QNetworkProxyFactory
operator|::
name|fromConfigurations
parameter_list|()
block|{
name|QNetworkConfigurationManager
name|manager
decl_stmt|;
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|proxies
decl_stmt|;
name|QUrl
name|url
argument_list|(
name|QLatin1String
argument_list|(
literal|"http://qt.nokia.com"
argument_list|)
argument_list|)
decl_stmt|;
comment|//get from known configurations
foreach|foreach
control|(
name|QNetworkConfiguration
name|config
decl|,
name|manager
operator|.
name|allConfigurations
argument_list|()
control|)
block|{
name|QNetworkProxyQuery
name|query
argument_list|(
name|config
argument_list|,
name|url
argument_list|,
name|QNetworkProxyQuery
operator|::
name|UrlRequest
argument_list|)
decl_stmt|;
name|proxies
operator|=
name|QNetworkProxyFactory
operator|::
name|systemProxyForQuery
argument_list|(
name|query
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|proxies
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QNetworkProxy
name|proxy
decl|,
name|proxies
control|)
block|{
name|qDebug
argument_list|()
operator|<<
name|config
operator|.
name|name
argument_list|()
operator|<<
literal|" - "
operator|<<
name|config
operator|.
name|identifier
argument_list|()
operator|<<
literal|" - "
operator|<<
name|formatProxyName
argument_list|(
name|proxy
argument_list|)
expr_stmt|;
block|}
block|}
comment|//get from default configuration
name|QNetworkProxyQuery
name|defaultquery
argument_list|(
name|url
argument_list|,
name|QNetworkProxyQuery
operator|::
name|UrlRequest
argument_list|)
decl_stmt|;
name|proxies
operator|=
name|QNetworkProxyFactory
operator|::
name|systemProxyForQuery
argument_list|(
name|defaultquery
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|proxies
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QNetworkProxy
name|proxy
decl|,
name|proxies
control|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"default - "
operator|<<
name|formatProxyName
argument_list|(
name|proxy
argument_list|)
expr_stmt|;
block|}
comment|//get from active configuration
name|QNetworkSession
name|session
argument_list|(
name|manager
operator|.
name|defaultConfiguration
argument_list|()
argument_list|)
decl_stmt|;
name|session
operator|.
name|open
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|session
operator|.
name|waitForOpened
argument_list|(
literal|30000
argument_list|)
argument_list|)
expr_stmt|;
name|proxies
operator|=
name|QNetworkProxyFactory
operator|::
name|systemProxyForQuery
argument_list|(
name|defaultquery
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|proxies
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QNetworkProxy
name|proxy
decl|,
name|proxies
control|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"active - "
operator|<<
name|formatProxyName
argument_list|(
name|proxy
argument_list|)
expr_stmt|;
block|}
comment|//get from known configurations while there is one active
foreach|foreach
control|(
name|QNetworkConfiguration
name|config
decl|,
name|manager
operator|.
name|allConfigurations
argument_list|()
control|)
block|{
name|QNetworkProxyQuery
name|query
argument_list|(
name|config
argument_list|,
name|url
argument_list|,
name|QNetworkProxyQuery
operator|::
name|UrlRequest
argument_list|)
decl_stmt|;
name|proxies
operator|=
name|QNetworkProxyFactory
operator|::
name|systemProxyForQuery
argument_list|(
name|query
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|proxies
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QNetworkProxy
name|proxy
decl|,
name|proxies
control|)
block|{
name|qDebug
argument_list|()
operator|<<
name|config
operator|.
name|name
argument_list|()
operator|<<
literal|" - "
operator|<<
name|config
operator|.
name|identifier
argument_list|()
operator|<<
literal|" - "
operator|<<
name|formatProxyName
argument_list|(
name|proxy
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|inNetworkAccessManager_data
name|void
name|tst_QNetworkProxyFactory
operator|::
name|inNetworkAccessManager_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QNetworkConfiguration
argument_list|>
argument_list|(
literal|"config"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
argument_list|>
argument_list|(
literal|"proxies"
argument_list|)
expr_stmt|;
name|QNetworkConfigurationManager
name|manager
decl_stmt|;
comment|//get from known configurations
foreach|foreach
control|(
name|QNetworkConfiguration
name|config
decl|,
name|manager
operator|.
name|allConfigurations
argument_list|()
control|)
block|{
name|QNetworkProxyQuery
name|query
argument_list|(
name|config
argument_list|,
name|QUrl
argument_list|(
name|QString
argument_list|(
literal|"http://qt.nokia.com"
argument_list|)
argument_list|)
argument_list|,
name|QNetworkProxyQuery
operator|::
name|UrlRequest
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|proxies
init|=
name|QNetworkProxyFactory
operator|::
name|systemProxyForQuery
argument_list|(
name|query
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|config
operator|.
name|name
argument_list|()
operator|.
name|toUtf8
argument_list|()
argument_list|)
operator|<<
name|config
operator|<<
name|proxies
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//Purpose of this test is to check that QNetworkAccessManager uses the proxy from the configuration it
end_comment
begin_comment
comment|//has been given. Needs two or more working configurations to be a good test.
end_comment
begin_function
DECL|function|inNetworkAccessManager
name|void
name|tst_QNetworkProxyFactory
operator|::
name|inNetworkAccessManager
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QNetworkConfiguration
argument_list|,
name|config
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
argument_list|,
name|proxies
argument_list|)
expr_stmt|;
name|int
name|count
init|=
name|factory
operator|->
name|requestCounter
decl_stmt|;
name|QNetworkAccessManager
name|manager
decl_stmt|;
name|manager
operator|.
name|setConfiguration
argument_list|(
name|config
argument_list|)
expr_stmt|;
comment|//using an internet server, because cellular APs won't have a route to the test server.
name|QNetworkRequest
name|req
argument_list|(
name|QUrl
argument_list|(
name|QString
argument_list|(
literal|"http://qt.nokia.com"
argument_list|)
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
name|req
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
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|30
argument_list|)
expr_stmt|;
operator|delete
name|reply
expr_stmt|;
if|if
condition|(
name|count
operator|==
name|factory
operator|->
name|requestCounter
condition|)
block|{
comment|//RND phones are preconfigured with several test access points which won't work without a matching SIM
comment|//If the network fails to start, QNAM won't ask the factory for proxies so we can't test.
name|QSKIP
argument_list|(
literal|"network configuration didn't start"
argument_list|)
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
literal|"testing network configuration for"
operator|<<
name|config
operator|.
name|name
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|QNetworkProxy
name|proxy
decl|,
name|factory
operator|->
name|returnedList
control|)
block|{
name|qDebug
argument_list|()
operator|<<
name|formatProxyName
argument_list|(
name|proxy
argument_list|)
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
literal|"<vs> "
expr_stmt|;
foreach|foreach
control|(
name|QNetworkProxy
name|proxy
decl|,
name|proxies
control|)
block|{
name|qDebug
argument_list|()
operator|<<
name|formatProxyName
argument_list|(
name|proxy
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|config
operator|.
name|type
argument_list|()
operator|!=
name|QNetworkConfiguration
operator|::
name|InternetAccessPoint
condition|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"QNetworkProxyFactory::systemProxyForQuery doesn't work for service networks yet"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|factory
operator|->
name|returnedList
argument_list|,
name|proxies
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_BEARERMANAGEMENT
end_comment
begin_class
DECL|class|QSPFQThread
class|class
name|QSPFQThread
super|:
specifier|public
name|QThread
block|{
protected|protected:
DECL|function|run
specifier|virtual
name|void
name|run
parameter_list|()
block|{
name|proxies
operator|=
name|QNetworkProxyFactory
operator|::
name|systemProxyForQuery
argument_list|(
name|query
argument_list|)
expr_stmt|;
block|}
public|public:
DECL|member|query
name|QNetworkProxyQuery
name|query
decl_stmt|;
DECL|member|proxies
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|proxies
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//regression test for QTBUG-18799
end_comment
begin_function
DECL|function|systemProxyForQueryCalledFromThread
name|void
name|tst_QNetworkProxyFactory
operator|::
name|systemProxyForQueryCalledFromThread
parameter_list|()
block|{
name|QUrl
name|url
argument_list|(
name|QLatin1String
argument_list|(
literal|"http://qt.nokia.com"
argument_list|)
argument_list|)
decl_stmt|;
name|QNetworkProxyQuery
name|query
argument_list|(
name|url
argument_list|)
decl_stmt|;
name|QSPFQThread
name|thread
decl_stmt|;
name|thread
operator|.
name|query
operator|=
name|query
expr_stmt|;
name|connect
argument_list|(
operator|&
name|thread
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
argument_list|)
expr_stmt|;
name|thread
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
literal|5
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|thread
operator|.
name|isFinished
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|thread
operator|.
name|proxies
argument_list|,
name|QNetworkProxyFactory
operator|::
name|systemProxyForQuery
argument_list|(
name|query
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QNetworkProxyFactory
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qnetworkproxyfactory.moc"
end_include
end_unit
