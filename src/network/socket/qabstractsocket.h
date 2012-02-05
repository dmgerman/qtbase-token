begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTSOCKET_H
end_ifndef
begin_define
DECL|macro|QABSTRACTSOCKET_H
define|#
directive|define
name|QABSTRACTSOCKET_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QHostAddress
name|class
name|QHostAddress
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_decl_stmt
DECL|variable|QNetworkProxy
name|class
name|QNetworkProxy
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QAbstractSocketPrivate
name|class
name|QAbstractSocketPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAuthenticator
name|class
name|QAuthenticator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QAbstractSocket
range|:
name|public
name|QIODevice
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|SocketType NetworkLayerProtocol SocketError SocketState SocketOption
argument_list|)
name|public
operator|:
expr|enum
name|SocketType
block|{
name|TcpSocket
block|,
name|UdpSocket
block|,
name|UnknownSocketType
operator|=
operator|-
literal|1
block|}
block|;     enum
name|NetworkLayerProtocol
block|{
name|IPv4Protocol
block|,
name|IPv6Protocol
block|,
name|AnyIPProtocol
block|,
name|UnknownNetworkLayerProtocol
operator|=
operator|-
literal|1
block|}
block|;     enum
name|SocketError
block|{
name|ConnectionRefusedError
block|,
name|RemoteHostClosedError
block|,
name|HostNotFoundError
block|,
name|SocketAccessError
block|,
name|SocketResourceError
block|,
name|SocketTimeoutError
block|,
comment|/* 5 */
name|DatagramTooLargeError
block|,
name|NetworkError
block|,
name|AddressInUseError
block|,
name|SocketAddressNotAvailableError
block|,
name|UnsupportedSocketOperationError
block|,
comment|/* 10 */
name|UnfinishedSocketOperationError
block|,
name|ProxyAuthenticationRequiredError
block|,
name|SslHandshakeFailedError
block|,
name|ProxyConnectionRefusedError
block|,
name|ProxyConnectionClosedError
block|,
comment|/* 15 */
name|ProxyConnectionTimeoutError
block|,
name|ProxyNotFoundError
block|,
name|ProxyProtocolError
block|,
name|OperationError
block|,
name|SslInternalError
block|,
comment|/* 20 */
name|SslInvalidUserDataError
block|,
name|UnknownSocketError
operator|=
operator|-
literal|1
block|}
block|;     enum
name|SocketState
block|{
name|UnconnectedState
block|,
name|HostLookupState
block|,
name|ConnectingState
block|,
name|ConnectedState
block|,
name|BoundState
block|,
name|ListeningState
block|,
name|ClosingState
block|}
block|;     enum
name|SocketOption
block|{
name|LowDelayOption
block|,
comment|// TCP_NODELAY
name|KeepAliveOption
block|,
comment|// SO_KEEPALIVE
name|MulticastTtlOption
block|,
comment|// IP_MULTICAST_TTL
name|MulticastLoopbackOption
block|,
comment|// IP_MULTICAST_LOOPBACK
name|TypeOfServiceOption
comment|//IP_TOS
block|}
block|;     enum
name|BindFlag
block|{
name|DefaultForPlatform
operator|=
literal|0x0
block|,
name|ShareAddress
operator|=
literal|0x1
block|,
name|DontShareAddress
operator|=
literal|0x2
block|,
name|ReuseAddressHint
operator|=
literal|0x4
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|BindMode
argument_list|,
name|BindFlag
argument_list|)
expr|enum
name|PauseMode
block|{
name|PauseNever
operator|=
literal|0x0
block|,
name|PauseOnNotify
operator|=
literal|0x1
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|PauseModes
argument_list|,
argument|PauseMode
argument_list|)
name|QAbstractSocket
argument_list|(
argument|SocketType socketType
argument_list|,
argument|QObject *parent
argument_list|)
block|;
name|virtual
operator|~
name|QAbstractSocket
argument_list|()
block|;
name|virtual
name|void
name|resume
argument_list|()
block|;
comment|// to continue after proxy authentication required, SSL errors etc.
name|PauseModes
name|pauseMode
argument_list|()
specifier|const
block|;
name|void
name|setPauseMode
argument_list|(
argument|PauseModes pauseMode
argument_list|)
block|;
name|bool
name|bind
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port =
literal|0
argument_list|,
argument|BindMode mode = DefaultForPlatform
argument_list|)
block|;
name|bool
name|bind
argument_list|(
argument|quint16 port =
literal|0
argument_list|,
argument|BindMode mode = DefaultForPlatform
argument_list|)
block|;
name|virtual
name|void
name|connectToHost
argument_list|(
argument|const QString&hostName
argument_list|,
argument|quint16 port
argument_list|,
argument|OpenMode mode = ReadWrite
argument_list|,
argument|NetworkLayerProtocol protocol = AnyIPProtocol
argument_list|)
block|;
name|virtual
name|void
name|connectToHost
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|,
argument|OpenMode mode = ReadWrite
argument_list|)
block|;
name|virtual
name|void
name|disconnectFromHost
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
block|;
name|qint64
name|bytesToWrite
argument_list|()
specifier|const
block|;
name|bool
name|canReadLine
argument_list|()
specifier|const
block|;
name|quint16
name|localPort
argument_list|()
specifier|const
block|;
name|QHostAddress
name|localAddress
argument_list|()
specifier|const
block|;
name|quint16
name|peerPort
argument_list|()
specifier|const
block|;
name|QHostAddress
name|peerAddress
argument_list|()
specifier|const
block|;
name|QString
name|peerName
argument_list|()
specifier|const
block|;
name|qint64
name|readBufferSize
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setReadBufferSize
argument_list|(
argument|qint64 size
argument_list|)
block|;
name|void
name|abort
argument_list|()
block|;
name|virtual
name|qintptr
name|socketDescriptor
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|setSocketDescriptor
argument_list|(
argument|qintptr socketDescriptor
argument_list|,
argument|SocketState state = ConnectedState
argument_list|,
argument|OpenMode openMode = ReadWrite
argument_list|)
block|;
name|virtual
name|void
name|setSocketOption
argument_list|(
argument|QAbstractSocket::SocketOption option
argument_list|,
argument|const QVariant&value
argument_list|)
block|;
name|virtual
name|QVariant
name|socketOption
argument_list|(
argument|QAbstractSocket::SocketOption option
argument_list|)
block|;
name|SocketType
name|socketType
argument_list|()
specifier|const
block|;
name|SocketState
name|state
argument_list|()
specifier|const
block|;
name|SocketError
name|error
argument_list|()
specifier|const
block|;
comment|// from QIODevice
name|void
name|close
argument_list|()
block|;
name|bool
name|isSequential
argument_list|()
specifier|const
block|;
name|bool
name|atEnd
argument_list|()
specifier|const
block|;
name|bool
name|flush
argument_list|()
block|;
comment|// for synchronous access
name|virtual
name|bool
name|waitForConnected
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|bool
name|waitForReadyRead
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|bool
name|waitForBytesWritten
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|virtual
name|bool
name|waitForDisconnected
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|void
name|setProxy
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|networkProxy
argument_list|)
block|;
name|QNetworkProxy
name|proxy
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|Q_SIGNALS
operator|:
name|void
name|hostFound
argument_list|()
block|;
name|void
name|connected
argument_list|()
block|;
name|void
name|disconnected
argument_list|()
block|;
name|void
name|stateChanged
argument_list|(
name|QAbstractSocket
operator|::
name|SocketState
argument_list|)
block|;
name|void
name|error
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|void
name|proxyAuthenticationRequired
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|proxy
argument_list|,
name|QAuthenticator
operator|*
name|authenticator
argument_list|)
block|;
endif|#
directive|endif
name|protected
operator|:
name|qint64
name|readData
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|readLineData
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|writeData
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
block|;
name|void
name|setSocketState
argument_list|(
argument|SocketState state
argument_list|)
block|;
name|void
name|setSocketError
argument_list|(
argument|SocketError socketError
argument_list|)
block|;
name|void
name|setLocalPort
argument_list|(
argument|quint16 port
argument_list|)
block|;
name|void
name|setLocalAddress
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|address
argument_list|)
block|;
name|void
name|setPeerPort
argument_list|(
argument|quint16 port
argument_list|)
block|;
name|void
name|setPeerAddress
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|address
argument_list|)
block|;
name|void
name|setPeerName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|QAbstractSocket
argument_list|(
argument|SocketType socketType
argument_list|,
argument|QAbstractSocketPrivate&dd
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractSocket
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractSocket
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_connectToNextAddress()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_startConnecting(const QHostInfo&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_abortConnectionAttempt()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_testConnection()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_forceDisconnect()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QAbstractSocket::BindMode
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QAbstractSocket::PauseModes
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_NETWORK_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
name|QAbstractSocket
operator|::
name|SocketError
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_NETWORK_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
name|QAbstractSocket
operator|::
name|SocketState
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QABSTRACTSOCKET_H
end_comment
end_unit
