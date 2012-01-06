begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qget.h"
end_include
begin_include
include|#
directive|include
file|<QSslError>
end_include
begin_include
include|#
directive|include
file|<QNetworkProxy>
end_include
begin_include
include|#
directive|include
file|<QAuthenticator>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QStringList>
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
begin_constructor
DECL|function|DownloadManager
name|DownloadManager
operator|::
name|DownloadManager
parameter_list|()
block|{
name|connect
argument_list|(
operator|&
name|nam
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|(
name|QNetworkReply
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|finished
argument_list|(
name|QNetworkReply
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|nam
argument_list|,
name|SIGNAL
argument_list|(
name|authenticationRequired
argument_list|(
name|QNetworkReply
operator|*
argument_list|,
name|QAuthenticator
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|authenticationRequired
argument_list|(
name|QNetworkReply
operator|*
argument_list|,
name|QAuthenticator
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|nam
argument_list|,
name|SIGNAL
argument_list|(
name|proxyAuthenticationRequired
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
argument_list|,
name|QAuthenticator
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|proxyAuthenticationRequired
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
argument_list|,
name|QAuthenticator
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|nam
argument_list|,
name|SIGNAL
argument_list|(
name|sslErrors
argument_list|(
name|QNetworkReply
operator|*
argument_list|,
specifier|const
name|QList
argument_list|<
name|QSslError
argument_list|>
operator|&
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|sslErrors
argument_list|(
name|QNetworkReply
operator|*
argument_list|,
specifier|const
name|QList
argument_list|<
name|QSslError
argument_list|>
operator|&
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~DownloadManager
name|DownloadManager
operator|::
name|~
name|DownloadManager
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|get
name|void
name|DownloadManager
operator|::
name|get
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
comment|//currently multiple downloads are processed in parallel.
comment|//could add an option for serial using the downloads list as a queue
comment|//which would require DownloadItem to hold a request rather than a reply
name|QNetworkReply
modifier|*
name|reply
init|=
name|nam
operator|.
name|get
argument_list|(
name|QNetworkRequest
argument_list|(
name|url
argument_list|)
argument_list|)
decl_stmt|;
name|DownloadItem
modifier|*
name|dl
init|=
operator|new
name|DownloadItem
argument_list|(
name|reply
argument_list|,
name|nam
argument_list|)
decl_stmt|;
name|downloads
operator|.
name|append
argument_list|(
name|dl
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|dl
argument_list|,
name|SIGNAL
argument_list|(
name|downloadFinished
argument_list|(
name|DownloadItem
operator|*
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|downloadFinished
argument_list|(
name|DownloadItem
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|finished
name|void
name|DownloadManager
operator|::
name|finished
parameter_list|(
name|QNetworkReply
modifier|*
name|reply
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|downloadFinished
name|void
name|DownloadManager
operator|::
name|downloadFinished
parameter_list|(
name|DownloadItem
modifier|*
name|item
parameter_list|)
block|{
name|downloads
operator|.
name|removeOne
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|item
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|checkForAllDone
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkForAllDone
name|void
name|DownloadManager
operator|::
name|checkForAllDone
parameter_list|()
block|{
if|if
condition|(
name|downloads
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"All Done."
expr_stmt|;
name|QCoreApplication
operator|::
name|quit
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|authenticationRequired
name|void
name|DownloadManager
operator|::
name|authenticationRequired
parameter_list|(
name|QNetworkReply
modifier|*
name|reply
parameter_list|,
name|QAuthenticator
modifier|*
name|auth
parameter_list|)
block|{
comment|//provide the credentials exactly once, so that it fails if credentials are incorrect.
if|if
condition|(
operator|!
name|httpUser
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|httpPassword
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|auth
operator|->
name|setUser
argument_list|(
name|httpUser
argument_list|)
expr_stmt|;
name|auth
operator|->
name|setPassword
argument_list|(
name|httpPassword
argument_list|)
expr_stmt|;
name|httpUser
operator|.
name|clear
argument_list|()
expr_stmt|;
name|httpPassword
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|proxyAuthenticationRequired
name|void
name|DownloadManager
operator|::
name|proxyAuthenticationRequired
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
name|proxy
parameter_list|,
name|QAuthenticator
modifier|*
name|auth
parameter_list|)
block|{
comment|//provide the credentials exactly once, so that it fails if credentials are incorrect.
if|if
condition|(
operator|!
name|proxyUser
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|proxyPassword
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|auth
operator|->
name|setUser
argument_list|(
name|proxyUser
argument_list|)
expr_stmt|;
name|auth
operator|->
name|setPassword
argument_list|(
name|proxyPassword
argument_list|)
expr_stmt|;
name|proxyUser
operator|.
name|clear
argument_list|()
expr_stmt|;
name|proxyPassword
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|sslErrors
name|void
name|DownloadManager
operator|::
name|sslErrors
parameter_list|(
name|QNetworkReply
modifier|*
name|reply
parameter_list|,
specifier|const
name|QList
argument_list|<
name|QSslError
argument_list|>
modifier|&
name|errors
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"sslErrors"
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QSslError
modifier|&
name|error
decl|,
name|errors
control|)
block|{
name|qDebug
argument_list|()
operator|<<
name|error
operator|.
name|errorString
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
name|error
operator|.
name|certificate
argument_list|()
operator|.
name|toPem
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|DownloadItem
name|DownloadItem
operator|::
name|DownloadItem
parameter_list|(
name|QNetworkReply
modifier|*
name|r
parameter_list|,
name|QNetworkAccessManager
modifier|&
name|manager
parameter_list|)
member_init_list|:
name|reply
argument_list|(
name|r
argument_list|)
member_init_list|,
name|nam
argument_list|(
name|manager
argument_list|)
block|{
name|reply
operator|->
name|setParent
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|reply
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
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
name|this
argument_list|,
name|SLOT
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~DownloadItem
name|DownloadItem
operator|::
name|~
name|DownloadItem
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|readyRead
name|void
name|DownloadItem
operator|::
name|readyRead
parameter_list|()
block|{
if|if
condition|(
operator|!
name|file
operator|.
name|isOpen
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
name|reply
operator|->
name|header
argument_list|(
name|QNetworkRequest
operator|::
name|ContentTypeHeader
argument_list|)
operator|<<
name|reply
operator|->
name|header
argument_list|(
name|QNetworkRequest
operator|::
name|ContentLengthHeader
argument_list|)
expr_stmt|;
name|QString
name|path
init|=
name|reply
operator|->
name|url
argument_list|()
operator|.
name|path
argument_list|()
decl_stmt|;
name|path
operator|=
name|path
operator|.
name|mid
argument_list|(
name|path
operator|.
name|lastIndexOf
argument_list|(
literal|'/'
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
name|path
operator|=
name|QLatin1String
argument_list|(
literal|"index.html"
argument_list|)
expr_stmt|;
name|file
operator|.
name|setFileName
argument_list|(
name|path
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
literal|1000
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|file
operator|.
name|exists
argument_list|()
operator|&&
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Truncate
argument_list|)
condition|)
break|break;
name|file
operator|.
name|setFileName
argument_list|(
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"%1.%2"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|path
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|file
operator|.
name|isOpen
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"couldn't open output file"
expr_stmt|;
name|reply
operator|->
name|abort
argument_list|()
expr_stmt|;
return|return;
block|}
name|qDebug
argument_list|()
operator|<<
name|reply
operator|->
name|url
argument_list|()
operator|<<
literal|" -> "
operator|<<
name|file
operator|.
name|fileName
argument_list|()
expr_stmt|;
block|}
name|file
operator|.
name|write
argument_list|(
name|reply
operator|->
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|finished
name|void
name|DownloadItem
operator|::
name|finished
parameter_list|()
block|{
if|if
condition|(
name|reply
operator|->
name|attribute
argument_list|(
name|QNetworkRequest
operator|::
name|RedirectionTargetAttribute
argument_list|)
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QUrl
name|url
init|=
name|reply
operator|->
name|attribute
argument_list|(
name|QNetworkRequest
operator|::
name|RedirectionTargetAttribute
argument_list|)
operator|.
name|toUrl
argument_list|()
decl_stmt|;
name|url
operator|=
name|reply
operator|->
name|url
argument_list|()
operator|.
name|resolved
argument_list|(
name|url
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
name|reply
operator|->
name|url
argument_list|()
operator|<<
literal|"redirected to "
operator|<<
name|url
expr_stmt|;
if|if
condition|(
name|redirects
operator|.
name|contains
argument_list|(
name|url
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"redirect loop detected"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|redirects
operator|.
name|count
argument_list|()
operator|>
literal|10
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"too many redirects"
expr_stmt|;
block|}
else|else
block|{
comment|//follow redirect
if|if
condition|(
name|file
operator|.
name|isOpen
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|file
operator|.
name|seek
argument_list|(
literal|0
argument_list|)
operator|||
operator|!
name|file
operator|.
name|resize
argument_list|(
literal|0
argument_list|)
condition|)
block|{
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
name|file
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
block|}
name|reply
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|reply
operator|=
name|nam
operator|.
name|get
argument_list|(
name|QNetworkRequest
argument_list|(
name|url
argument_list|)
argument_list|)
expr_stmt|;
name|reply
operator|->
name|setParent
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|reply
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
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
name|this
argument_list|,
name|SLOT
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|redirects
operator|.
name|append
argument_list|(
name|url
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
if|if
condition|(
name|file
operator|.
name|isOpen
argument_list|()
condition|)
block|{
name|file
operator|.
name|write
argument_list|(
name|reply
operator|->
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
literal|"finished "
operator|<<
name|reply
operator|->
name|url
argument_list|()
operator|<<
literal|" with http status: "
operator|<<
name|reply
operator|->
name|attribute
argument_list|(
name|QNetworkRequest
operator|::
name|HttpStatusCodeAttribute
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
if|if
condition|(
name|reply
operator|->
name|error
argument_list|()
operator|!=
name|QNetworkReply
operator|::
name|NoError
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"and error: "
operator|<<
name|reply
operator|->
name|error
argument_list|()
operator|<<
name|reply
operator|->
name|errorString
argument_list|()
expr_stmt|;
emit|emit
name|downloadFinished
argument_list|(
name|this
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|printShortUsage
name|void
name|printShortUsage
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
operator|<<
literal|" [options] [list of urls]"
operator|<<
name|endl
operator|<<
literal|"Get one or more urls using QNetworkAccessManager"
operator|<<
name|endl
operator|<<
literal|"--help to display detailed usage"
operator|<<
name|endl
expr_stmt|;
block|}
end_function
begin_function
DECL|function|printUsage
name|void
name|printUsage
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
operator|<<
literal|" [options] [list of urls]"
operator|<<
name|endl
operator|<<
literal|"Get one or more urls using QNetworkAccessManager"
operator|<<
name|endl
operator|<<
literal|"Options:"
operator|<<
literal|"--help                             This message"
operator|<<
name|endl
operator|<<
literal|"--http-user=<username>             Set username to use for http 401 challenges"
operator|<<
name|endl
operator|<<
literal|"--http-password=<password>         Set password to use for http 401 challenges"
operator|<<
name|endl
operator|<<
literal|"--proxy-user=<username>            Set username to use for proxy authentication"
operator|<<
name|endl
operator|<<
literal|"--proxy-password=<password>        Set password to use for proxy authentication"
operator|<<
name|endl
operator|<<
literal|"--proxy=on                         Use system proxy (default)"
operator|<<
name|endl
operator|<<
literal|"--proxy=off                        Don't use system proxy"
operator|<<
name|endl
operator|<<
literal|"--proxy=<host:port>[,type]         Use specified proxy"
operator|<<
name|endl
operator|<<
literal|"                   ,http           HTTP proxy (default)"
operator|<<
name|endl
operator|<<
literal|"                   ,socks          SOCKS5 proxy"
operator|<<
name|endl
operator|<<
literal|"                   ,ftp            FTP proxy"
operator|<<
name|endl
operator|<<
literal|"                   ,httpcaching    HTTP caching proxy (no CONNECT method)"
operator|<<
name|endl
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
block|{
name|printShortUsage
argument_list|()
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
comment|//use system proxy (by default)
name|QNetworkProxyFactory
operator|::
name|setUseSystemConfiguration
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|DownloadManager
name|dl
decl_stmt|;
comment|//arguments match wget where possible
foreach|foreach
control|(
name|QString
name|str
decl|,
name|app
operator|.
name|arguments
argument_list|()
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
control|)
block|{
if|if
condition|(
name|str
operator|==
literal|"--help"
condition|)
name|printUsage
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--http-user="
argument_list|)
condition|)
name|dl
operator|.
name|setHttpUser
argument_list|(
name|str
operator|.
name|mid
argument_list|(
literal|12
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--http-passwd="
argument_list|)
condition|)
name|dl
operator|.
name|setHttpPassword
argument_list|(
name|str
operator|.
name|mid
argument_list|(
literal|14
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--proxy-user="
argument_list|)
condition|)
name|dl
operator|.
name|setProxyUser
argument_list|(
name|str
operator|.
name|mid
argument_list|(
literal|13
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--proxy-passwd="
argument_list|)
condition|)
name|dl
operator|.
name|setProxyPassword
argument_list|(
name|str
operator|.
name|mid
argument_list|(
literal|15
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|==
literal|"--proxy=off"
condition|)
name|QNetworkProxyFactory
operator|::
name|setUseSystemConfiguration
argument_list|(
literal|false
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|==
literal|"--proxy=on"
condition|)
name|QNetworkProxyFactory
operator|::
name|setUseSystemConfiguration
argument_list|(
literal|true
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--proxy="
argument_list|)
condition|)
block|{
comment|//parse "--proxy=host:port[,type]"
name|QNetworkProxy
name|proxy
decl_stmt|;
name|str
operator|=
name|str
operator|.
name|mid
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|int
name|sep
init|=
name|str
operator|.
name|indexOf
argument_list|(
literal|':'
argument_list|)
decl_stmt|;
name|proxy
operator|.
name|setHostName
argument_list|(
name|str
operator|.
name|left
argument_list|(
name|sep
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|=
name|str
operator|.
name|mid
argument_list|(
name|sep
operator|+
literal|1
argument_list|)
expr_stmt|;
name|sep
operator|=
name|str
operator|.
name|indexOf
argument_list|(
literal|','
argument_list|)
expr_stmt|;
name|QString
name|port
decl_stmt|;
if|if
condition|(
name|sep
operator|<
literal|0
condition|)
block|{
name|port
operator|=
name|str
expr_stmt|;
name|proxy
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|port
operator|=
name|str
operator|.
name|left
argument_list|(
name|sep
argument_list|)
expr_stmt|;
name|str
operator|=
name|str
operator|.
name|mid
argument_list|(
name|sep
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|str
operator|==
literal|"socks"
condition|)
name|proxy
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|Socks5Proxy
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|==
literal|"ftp"
condition|)
name|proxy
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|FtpCachingProxy
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|==
literal|"httpcaching"
condition|)
name|proxy
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|HttpCachingProxy
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|==
literal|"http"
condition|)
name|proxy
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|)
expr_stmt|;
else|else
block|{
name|qDebug
argument_list|()
operator|<<
literal|"unknown proxy type"
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
block|}
name|bool
name|ok
decl_stmt|;
name|quint16
name|p
init|=
name|port
operator|.
name|toUShort
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"couldn't parse proxy"
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
name|proxy
operator|.
name|setPort
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"proxy:"
operator|<<
name|proxy
operator|.
name|hostName
argument_list|()
operator|<<
name|proxy
operator|.
name|port
argument_list|()
operator|<<
name|proxy
operator|.
name|type
argument_list|()
expr_stmt|;
name|dl
operator|.
name|setProxy
argument_list|(
name|proxy
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"-"
argument_list|)
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"unsupported option"
operator|<<
name|str
expr_stmt|;
else|else
name|dl
operator|.
name|get
argument_list|(
name|QUrl
operator|::
name|fromUserInput
argument_list|(
name|str
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
operator|&
name|dl
argument_list|,
literal|"checkForAllDone"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
