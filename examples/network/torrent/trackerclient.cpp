begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"bencodeparser.h"
end_include
begin_include
include|#
directive|include
file|"connectionmanager.h"
end_include
begin_include
include|#
directive|include
file|"torrentclient.h"
end_include
begin_include
include|#
directive|include
file|"torrentserver.h"
end_include
begin_include
include|#
directive|include
file|"trackerclient.h"
end_include
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QNetworkRequest>
end_include
begin_constructor
DECL|function|TrackerClient
name|TrackerClient
operator|::
name|TrackerClient
parameter_list|(
name|TorrentClient
modifier|*
name|downloader
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|torrentDownloader
argument_list|(
name|downloader
argument_list|)
block|{
name|length
operator|=
literal|0
expr_stmt|;
name|requestInterval
operator|=
literal|5
operator|*
literal|60
expr_stmt|;
name|requestIntervalTimer
operator|=
operator|-
literal|1
expr_stmt|;
name|firstTrackerRequest
operator|=
literal|true
expr_stmt|;
name|lastTrackerRequest
operator|=
literal|false
expr_stmt|;
name|firstSeeding
operator|=
literal|true
expr_stmt|;
name|connect
argument_list|(
operator|&
name|http
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
name|httpRequestDone
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
DECL|function|start
name|void
name|TrackerClient
operator|::
name|start
parameter_list|(
specifier|const
name|MetaInfo
modifier|&
name|info
parameter_list|)
block|{
name|metaInfo
operator|=
name|info
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|fetchPeerList
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|metaInfo
operator|.
name|fileForm
argument_list|()
operator|==
name|MetaInfo
operator|::
name|SingleFileForm
condition|)
block|{
name|length
operator|=
name|metaInfo
operator|.
name|singleFile
argument_list|()
operator|.
name|length
expr_stmt|;
block|}
else|else
block|{
name|QList
argument_list|<
name|MetaInfoMultiFile
argument_list|>
name|files
init|=
name|metaInfo
operator|.
name|multiFiles
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|files
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|length
operator|+=
name|files
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|length
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|startSeeding
name|void
name|TrackerClient
operator|::
name|startSeeding
parameter_list|()
block|{
name|firstSeeding
operator|=
literal|true
expr_stmt|;
name|fetchPeerList
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stop
name|void
name|TrackerClient
operator|::
name|stop
parameter_list|()
block|{
name|lastTrackerRequest
operator|=
literal|true
expr_stmt|;
name|fetchPeerList
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|TrackerClient
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|timerId
argument_list|()
operator|==
name|requestIntervalTimer
condition|)
block|{
name|fetchPeerList
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QObject
operator|::
name|timerEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fetchPeerList
name|void
name|TrackerClient
operator|::
name|fetchPeerList
parameter_list|()
block|{
comment|// Prepare connection details
name|QString
name|fullUrl
init|=
name|metaInfo
operator|.
name|announceUrl
argument_list|()
decl_stmt|;
name|QUrl
name|url
argument_list|(
name|fullUrl
argument_list|)
decl_stmt|;
name|QString
name|passkey
init|=
literal|"?"
decl_stmt|;
if|if
condition|(
name|fullUrl
operator|.
name|contains
argument_list|(
literal|"?passkey"
argument_list|)
condition|)
block|{
name|passkey
operator|=
name|metaInfo
operator|.
name|announceUrl
argument_list|()
operator|.
name|mid
argument_list|(
name|fullUrl
operator|.
name|indexOf
argument_list|(
literal|"?passkey"
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|passkey
operator|+=
literal|'&'
expr_stmt|;
block|}
comment|// Percent encode the hash
name|QByteArray
name|infoHash
init|=
name|torrentDownloader
operator|->
name|infoHash
argument_list|()
decl_stmt|;
name|QString
name|encodedSum
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|infoHash
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|encodedSum
operator|+=
literal|'%'
expr_stmt|;
name|encodedSum
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|infoHash
index|[
name|i
index|]
argument_list|,
literal|16
argument_list|)
operator|.
name|right
argument_list|(
literal|2
argument_list|)
operator|.
name|rightJustified
argument_list|(
literal|2
argument_list|,
literal|'0'
argument_list|)
expr_stmt|;
block|}
name|bool
name|seeding
init|=
operator|(
name|torrentDownloader
operator|->
name|state
argument_list|()
operator|==
name|TorrentClient
operator|::
name|Seeding
operator|)
decl_stmt|;
name|QByteArray
name|query
decl_stmt|;
name|query
operator|+=
name|url
operator|.
name|path
argument_list|()
operator|.
name|toLatin1
argument_list|()
expr_stmt|;
name|query
operator|+=
name|passkey
expr_stmt|;
name|query
operator|+=
literal|"info_hash="
operator|+
name|encodedSum
expr_stmt|;
name|query
operator|+=
literal|"&peer_id="
operator|+
name|ConnectionManager
operator|::
name|instance
argument_list|()
operator|->
name|clientId
argument_list|()
expr_stmt|;
name|query
operator|+=
literal|"&port="
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|TorrentServer
operator|::
name|instance
argument_list|()
operator|->
name|serverPort
argument_list|()
argument_list|)
expr_stmt|;
name|query
operator|+=
literal|"&compact=1"
expr_stmt|;
name|query
operator|+=
literal|"&uploaded="
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|torrentDownloader
operator|->
name|uploadedBytes
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|firstSeeding
condition|)
block|{
name|query
operator|+=
literal|"&downloaded=0"
expr_stmt|;
name|query
operator|+=
literal|"&left=0"
expr_stmt|;
block|}
else|else
block|{
name|query
operator|+=
literal|"&downloaded="
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|torrentDownloader
operator|->
name|downloadedBytes
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|left
init|=
name|qMax
argument_list|<
name|int
argument_list|>
argument_list|(
literal|0
argument_list|,
name|metaInfo
operator|.
name|totalSize
argument_list|()
operator|-
name|torrentDownloader
operator|->
name|downloadedBytes
argument_list|()
argument_list|)
decl_stmt|;
name|query
operator|+=
literal|"&left="
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|seeding
condition|?
literal|0
else|:
name|left
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|seeding
operator|&&
name|firstSeeding
condition|)
block|{
name|query
operator|+=
literal|"&event=completed"
expr_stmt|;
name|firstSeeding
operator|=
literal|false
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|firstTrackerRequest
condition|)
block|{
name|firstTrackerRequest
operator|=
literal|false
expr_stmt|;
name|query
operator|+=
literal|"&event=started"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|lastTrackerRequest
condition|)
block|{
name|query
operator|+=
literal|"&event=stopped"
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|trackerId
operator|.
name|isEmpty
argument_list|()
condition|)
name|query
operator|+=
literal|"&trackerid="
operator|+
name|trackerId
expr_stmt|;
name|QNetworkRequest
name|req
argument_list|(
name|url
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|url
operator|.
name|userName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|uname
operator|=
name|url
operator|.
name|userName
argument_list|()
expr_stmt|;
name|pwd
operator|=
name|url
operator|.
name|password
argument_list|()
expr_stmt|;
name|connect
argument_list|(
operator|&
name|http
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
name|provideAuthentication
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
block|}
name|http
operator|.
name|get
argument_list|(
name|req
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|httpRequestDone
name|void
name|TrackerClient
operator|::
name|httpRequestDone
parameter_list|(
name|QNetworkReply
modifier|*
name|reply
parameter_list|)
block|{
name|reply
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
if|if
condition|(
name|lastTrackerRequest
condition|)
block|{
emit|emit
name|stopped
argument_list|()
emit|;
return|return;
block|}
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
block|{
emit|emit
name|connectionError
argument_list|(
name|reply
operator|->
name|error
argument_list|()
argument_list|)
emit|;
return|return;
block|}
name|QByteArray
name|response
init|=
name|reply
operator|->
name|readAll
argument_list|()
decl_stmt|;
name|reply
operator|->
name|abort
argument_list|()
expr_stmt|;
name|BencodeParser
name|parser
decl_stmt|;
if|if
condition|(
operator|!
name|parser
operator|.
name|parse
argument_list|(
name|response
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Error parsing bencode response from tracker: %s"
argument_list|,
name|qPrintable
argument_list|(
name|parser
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QVariant
argument_list|>
name|dict
init|=
name|parser
operator|.
name|dictionary
argument_list|()
decl_stmt|;
if|if
condition|(
name|dict
operator|.
name|contains
argument_list|(
literal|"failure reason"
argument_list|)
condition|)
block|{
comment|// no other items are present
emit|emit
name|failure
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|dict
operator|.
name|value
argument_list|(
literal|"failure reason"
argument_list|)
operator|.
name|toByteArray
argument_list|()
argument_list|)
argument_list|)
emit|;
return|return;
block|}
if|if
condition|(
name|dict
operator|.
name|contains
argument_list|(
literal|"warning message"
argument_list|)
condition|)
block|{
comment|// continue processing
emit|emit
name|warning
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|dict
operator|.
name|value
argument_list|(
literal|"warning message"
argument_list|)
operator|.
name|toByteArray
argument_list|()
argument_list|)
argument_list|)
emit|;
block|}
if|if
condition|(
name|dict
operator|.
name|contains
argument_list|(
literal|"tracker id"
argument_list|)
condition|)
block|{
comment|// store it
name|trackerId
operator|=
name|dict
operator|.
name|value
argument_list|(
literal|"tracker id"
argument_list|)
operator|.
name|toByteArray
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|dict
operator|.
name|contains
argument_list|(
literal|"interval"
argument_list|)
condition|)
block|{
comment|// Mandatory item
if|if
condition|(
name|requestIntervalTimer
operator|!=
operator|-
literal|1
condition|)
name|killTimer
argument_list|(
name|requestIntervalTimer
argument_list|)
expr_stmt|;
name|requestIntervalTimer
operator|=
name|startTimer
argument_list|(
name|dict
operator|.
name|value
argument_list|(
literal|"interval"
argument_list|)
operator|.
name|toInt
argument_list|()
operator|*
literal|1000
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|dict
operator|.
name|contains
argument_list|(
literal|"peers"
argument_list|)
condition|)
block|{
comment|// store it
name|peers
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVariant
name|peerEntry
init|=
name|dict
operator|.
name|value
argument_list|(
literal|"peers"
argument_list|)
decl_stmt|;
if|if
condition|(
name|peerEntry
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|List
condition|)
block|{
name|QList
argument_list|<
name|QVariant
argument_list|>
name|peerTmp
init|=
name|peerEntry
operator|.
name|toList
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|peerTmp
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|TorrentPeer
name|tmp
decl_stmt|;
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QVariant
argument_list|>
name|peer
init|=
name|qvariant_cast
argument_list|<
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QVariant
argument_list|>
argument_list|>
argument_list|(
name|peerTmp
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|tmp
operator|.
name|id
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|peer
operator|.
name|value
argument_list|(
literal|"peer id"
argument_list|)
operator|.
name|toByteArray
argument_list|()
argument_list|)
expr_stmt|;
name|tmp
operator|.
name|address
operator|.
name|setAddress
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|peer
operator|.
name|value
argument_list|(
literal|"ip"
argument_list|)
operator|.
name|toByteArray
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|tmp
operator|.
name|port
operator|=
name|peer
operator|.
name|value
argument_list|(
literal|"port"
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|peers
operator|<<
name|tmp
expr_stmt|;
block|}
block|}
else|else
block|{
name|QByteArray
name|peerTmp
init|=
name|peerEntry
operator|.
name|toByteArray
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|peerTmp
operator|.
name|size
argument_list|()
condition|;
name|i
operator|+=
literal|6
control|)
block|{
name|TorrentPeer
name|tmp
decl_stmt|;
name|uchar
modifier|*
name|data
init|=
operator|(
name|uchar
operator|*
operator|)
name|peerTmp
operator|.
name|constData
argument_list|()
operator|+
name|i
decl_stmt|;
name|tmp
operator|.
name|port
operator|=
operator|(
name|int
argument_list|(
name|data
index|[
literal|4
index|]
argument_list|)
operator|<<
literal|8
operator|)
operator|+
name|data
index|[
literal|5
index|]
expr_stmt|;
name|uint
name|ipAddress
init|=
literal|0
decl_stmt|;
name|ipAddress
operator|+=
name|uint
argument_list|(
name|data
index|[
literal|0
index|]
argument_list|)
operator|<<
literal|24
expr_stmt|;
name|ipAddress
operator|+=
name|uint
argument_list|(
name|data
index|[
literal|1
index|]
argument_list|)
operator|<<
literal|16
expr_stmt|;
name|ipAddress
operator|+=
name|uint
argument_list|(
name|data
index|[
literal|2
index|]
argument_list|)
operator|<<
literal|8
expr_stmt|;
name|ipAddress
operator|+=
name|uint
argument_list|(
name|data
index|[
literal|3
index|]
argument_list|)
expr_stmt|;
name|tmp
operator|.
name|address
operator|.
name|setAddress
argument_list|(
name|ipAddress
argument_list|)
expr_stmt|;
name|peers
operator|<<
name|tmp
expr_stmt|;
block|}
block|}
emit|emit
name|peerListUpdated
argument_list|(
name|peers
argument_list|)
emit|;
block|}
block|}
end_function
begin_function
DECL|function|provideAuthentication
name|void
name|TrackerClient
operator|::
name|provideAuthentication
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
name|Q_UNUSED
argument_list|(
name|reply
argument_list|)
expr_stmt|;
name|auth
operator|->
name|setUser
argument_list|(
name|uname
argument_list|)
expr_stmt|;
name|auth
operator|->
name|setPassword
argument_list|(
name|pwd
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
