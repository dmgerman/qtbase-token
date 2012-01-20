begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
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
file|<QSslError>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QUrl>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class_decl
class_decl|class
name|QSslError
class_decl|;
end_class_decl
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_USE_NAMESPACE
DECL|class|DownloadManager
name|class
name|DownloadManager
operator|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|manager
name|QNetworkAccessManager
name|manager
block|;
DECL|member|currentDownloads
name|QList
argument_list|<
name|QNetworkReply
operator|*
argument_list|>
name|currentDownloads
block|;
specifier|public
operator|:
name|DownloadManager
argument_list|()
block|;
name|void
name|doDownload
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
block|;
name|QString
name|saveFileName
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
block|;
name|bool
name|saveToDisk
argument_list|(
specifier|const
name|QString
operator|&
name|filename
argument_list|,
name|QIODevice
operator|*
name|data
argument_list|)
block|;
specifier|public
name|slots
operator|:
name|void
name|execute
argument_list|()
block|;
name|void
name|downloadFinished
argument_list|(
name|QNetworkReply
operator|*
name|reply
argument_list|)
block|;
name|void
name|sslErrors
argument_list|(
specifier|const
name|QList
argument_list|<
name|QSslError
argument_list|>
operator|&
name|errors
argument_list|)
block|; }
expr_stmt|;
end_expr_stmt
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
name|manager
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
name|SLOT
argument_list|(
name|downloadFinished
argument_list|(
name|QNetworkReply
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|doDownload
name|void
name|DownloadManager
operator|::
name|doDownload
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|QNetworkRequest
name|request
argument_list|(
name|url
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
name|request
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|reply
argument_list|,
name|SIGNAL
argument_list|(
name|sslErrors
argument_list|(
name|QList
argument_list|<
name|QSslError
argument_list|>
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|sslErrors
argument_list|(
name|QList
argument_list|<
name|QSslError
argument_list|>
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|currentDownloads
operator|.
name|append
argument_list|(
name|reply
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|saveFileName
name|QString
name|DownloadManager
operator|::
name|saveFileName
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|QString
name|path
init|=
name|url
operator|.
name|path
argument_list|()
decl_stmt|;
name|QString
name|basename
init|=
name|QFileInfo
argument_list|(
name|path
argument_list|)
operator|.
name|fileName
argument_list|()
decl_stmt|;
if|if
condition|(
name|basename
operator|.
name|isEmpty
argument_list|()
condition|)
name|basename
operator|=
literal|"download"
expr_stmt|;
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|basename
argument_list|)
condition|)
block|{
comment|// already exists, don't overwrite
name|int
name|i
init|=
literal|0
decl_stmt|;
name|basename
operator|+=
literal|'.'
expr_stmt|;
while|while
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|basename
operator|+
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
operator|++
name|i
expr_stmt|;
name|basename
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
return|return
name|basename
return|;
block|}
end_function
begin_function
DECL|function|saveToDisk
name|bool
name|DownloadManager
operator|::
name|saveToDisk
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|,
name|QIODevice
modifier|*
name|data
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|filename
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Could not open %s for writing: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|filename
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|file
operator|.
name|write
argument_list|(
name|data
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
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|execute
name|void
name|DownloadManager
operator|::
name|execute
parameter_list|()
block|{
name|QStringList
name|args
init|=
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|arguments
argument_list|()
decl_stmt|;
name|args
operator|.
name|takeFirst
argument_list|()
expr_stmt|;
comment|// skip the first argument, which is the program's name
if|if
condition|(
name|args
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|printf
argument_list|(
literal|"Qt Download example - downloads all URLs in parallel\n"
literal|"Usage: download url1 [url2... urlN]\n"
literal|"\n"
literal|"Downloads the URLs passed in the command-line to the local directory\n"
literal|"If the target file already exists, a .0, .1, .2, etc. is appended to\n"
literal|"differentiate.\n"
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|quit
argument_list|()
expr_stmt|;
return|return;
block|}
foreach|foreach
control|(
name|QString
name|arg
decl|,
name|args
control|)
block|{
name|QUrl
name|url
init|=
name|QUrl
operator|::
name|fromEncoded
argument_list|(
name|arg
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
decl_stmt|;
name|doDownload
argument_list|(
name|url
argument_list|)
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
specifier|const
name|QList
argument_list|<
name|QSslError
argument_list|>
modifier|&
name|sslErrors
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
foreach|foreach
control|(
specifier|const
name|QSslError
modifier|&
name|error
decl|,
name|sslErrors
control|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"SSL error: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|error
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|downloadFinished
name|void
name|DownloadManager
operator|::
name|downloadFinished
parameter_list|(
name|QNetworkReply
modifier|*
name|reply
parameter_list|)
block|{
name|QUrl
name|url
init|=
name|reply
operator|->
name|url
argument_list|()
decl_stmt|;
if|if
condition|(
name|reply
operator|->
name|error
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Download of %s failed: %s\n"
argument_list|,
name|url
operator|.
name|toEncoded
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|reply
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QString
name|filename
init|=
name|saveFileName
argument_list|(
name|url
argument_list|)
decl_stmt|;
if|if
condition|(
name|saveToDisk
argument_list|(
name|filename
argument_list|,
name|reply
argument_list|)
condition|)
name|printf
argument_list|(
literal|"Download of %s succeeded (saved to %s)\n"
argument_list|,
name|url
operator|.
name|toEncoded
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|filename
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|currentDownloads
operator|.
name|removeAll
argument_list|(
name|reply
argument_list|)
expr_stmt|;
name|reply
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
if|if
condition|(
name|currentDownloads
operator|.
name|isEmpty
argument_list|()
condition|)
comment|// all downloads finished
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|quit
argument_list|()
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
modifier|*
name|argv
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
name|DownloadManager
name|manager
decl_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
operator|&
name|manager
argument_list|,
name|SLOT
argument_list|(
name|execute
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|app
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
