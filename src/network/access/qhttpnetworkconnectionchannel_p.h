begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHTTPNETWORKCONNECTIONCHANNEL_H
end_ifndef
begin_define
DECL|macro|QHTTPNETWORKCONNECTIONCHANNEL_H
define|#
directive|define
name|QHTTPNETWORKCONNECTIONCHANNEL_H
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
file|<QtNetwork/qnetworkrequest.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkreply.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qabstractsocket.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<qauthenticator.h>
end_include
begin_include
include|#
directive|include
file|<qnetworkproxy.h>
end_include
begin_include
include|#
directive|include
file|<qbuffer.h>
end_include
begin_include
include|#
directive|include
file|<private/qhttpnetworkheader_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qhttpnetworkrequest_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qhttpnetworkreply_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qhttpnetworkconnection_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_HTTP
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
end_ifndef
begin_include
include|#
directive|include
file|<QtNetwork/qsslsocket.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qsslerror.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<QtNetwork/qtcpsocket.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QHttpNetworkRequest
name|class
name|QHttpNetworkRequest
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHttpNetworkReply
name|class
name|QHttpNetworkReply
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QByteArray
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|HttpMessagePair
end_ifndef
begin_typedef
DECL|typedef|QHttpNetworkRequest
DECL|typedef|HttpMessagePair
typedef|typedef
name|QPair
operator|<
name|QHttpNetworkRequest
operator|,
name|QHttpNetworkReply
operator|*
operator|>
name|HttpMessagePair
expr_stmt|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QHttpNetworkConnectionChannel
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|ChannelState
block|{
name|IdleState
operator|=
literal|0
block|,
comment|// ready to send request
name|ConnectingState
operator|=
literal|1
block|,
comment|// connecting to host
name|WritingState
operator|=
literal|2
block|,
comment|// writing the data
name|WaitingState
operator|=
literal|4
block|,
comment|// waiting for reply
name|ReadingState
operator|=
literal|8
block|,
comment|// reading the reply
name|ClosingState
operator|=
literal|16
block|,
name|BusyState
operator|=
operator|(
name|ConnectingState
operator||
name|WritingState
operator||
name|WaitingState
operator||
name|ReadingState
operator||
name|ClosingState
operator|)
block|}
block|;
name|QAbstractSocket
operator|*
name|socket
block|;
name|bool
name|ssl
block|;
name|ChannelState
name|state
block|;
name|QHttpNetworkRequest
name|request
block|;
comment|// current request
name|QHttpNetworkReply
operator|*
name|reply
block|;
comment|// current reply for this request
name|qint64
name|written
block|;
name|qint64
name|bytesTotal
block|;
name|bool
name|resendCurrent
block|;
name|int
name|lastStatus
block|;
comment|// last status received on this channel
name|bool
name|pendingEncrypt
block|;
comment|// for https (send after encrypted)
name|int
name|reconnectAttempts
block|;
comment|// maximum 2 reconnection attempts
name|QAuthenticatorPrivate
operator|::
name|Method
name|authMethod
block|;
name|QAuthenticatorPrivate
operator|::
name|Method
name|proxyAuthMethod
block|;
name|QAuthenticator
name|authenticator
block|;
name|QAuthenticator
name|proxyAuthenticator
block|;
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
name|bool
name|ignoreAllSslErrors
block|;
name|QList
operator|<
name|QSslError
operator|>
name|ignoreSslErrorsList
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
name|networkSession
block|;
endif|#
directive|endif
comment|// HTTP pipelining -> http://en.wikipedia.org/wiki/Http_pipelining
block|enum
name|PipeliningSupport
block|{
name|PipeliningSupportUnknown
block|,
comment|// default for a new connection
name|PipeliningProbablySupported
block|,
comment|// after having received a server response that indicates support
name|PipeliningNotSupported
comment|// currently not used
block|}
block|;
name|PipeliningSupport
name|pipeliningSupported
block|;
name|QList
operator|<
name|HttpMessagePair
operator|>
name|alreadyPipelinedRequests
block|;
name|QByteArray
name|pipeline
block|;
comment|// temporary buffer that gets sent to socket in pipelineFlush
name|void
name|pipelineInto
argument_list|(
name|HttpMessagePair
operator|&
name|pair
argument_list|)
block|;
name|void
name|pipelineFlush
argument_list|()
block|;
name|void
name|requeueCurrentlyPipelinedRequests
argument_list|()
block|;
name|void
name|detectPipeliningSupport
argument_list|()
block|;
name|QHttpNetworkConnectionChannel
argument_list|()
block|;
name|void
name|setConnection
argument_list|(
name|QHttpNetworkConnection
operator|*
name|c
argument_list|)
block|;
name|QPointer
operator|<
name|QHttpNetworkConnection
operator|>
name|connection
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|close
argument_list|()
block|;
name|bool
name|sendRequest
argument_list|()
block|;
name|bool
name|ensureConnection
argument_list|()
block|;
name|bool
name|expand
argument_list|(
argument|bool dataComplete
argument_list|)
block|;
name|void
name|allDone
argument_list|()
block|;
comment|// reply header + body have been read
name|void
name|handleStatus
argument_list|()
block|;
comment|// called from allDone()
name|bool
name|resetUploadData
argument_list|()
block|;
comment|// return true if resetting worked or there is no upload data
name|void
name|handleUnexpectedEOF
argument_list|()
block|;
name|void
name|closeAndResendCurrentRequest
argument_list|()
block|;
name|bool
name|isSocketBusy
argument_list|()
specifier|const
block|;
name|bool
name|isSocketWriting
argument_list|()
specifier|const
block|;
name|bool
name|isSocketWaiting
argument_list|()
specifier|const
block|;
name|bool
name|isSocketReading
argument_list|()
specifier|const
block|;
name|friend
name|class
name|QNetworkAccessHttpBackend
block|;
name|protected
name|slots
operator|:
name|void
name|_q_receiveReply
argument_list|()
block|;
name|void
name|_q_bytesWritten
argument_list|(
argument|qint64 bytes
argument_list|)
block|;
comment|// proceed sending
name|void
name|_q_readyRead
argument_list|()
block|;
comment|// pending data to read
name|void
name|_q_disconnected
argument_list|()
block|;
comment|// disconnected from host
name|void
name|_q_connected
argument_list|()
block|;
comment|// start sending request
name|void
name|_q_error
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
argument_list|)
block|;
comment|// error from socket
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|void
name|_q_proxyAuthenticationRequired
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|proxy
argument_list|,
name|QAuthenticator
operator|*
name|auth
argument_list|)
block|;
comment|// from transparent proxy
endif|#
directive|endif
name|void
name|_q_uploadDataReadyRead
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
name|void
name|_q_encrypted
argument_list|()
block|;
comment|// start sending request (https)
name|void
name|_q_sslErrors
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
comment|// ssl errors from the socket
name|void
name|_q_encryptedBytesWritten
argument_list|(
argument|qint64 bytes
argument_list|)
block|;
comment|// proceed sending
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
begin_comment
comment|// QT_NO_HTTP
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
