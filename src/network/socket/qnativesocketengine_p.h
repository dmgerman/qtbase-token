begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNATIVESOCKETENGINE_P_H
end_ifndef
begin_define
DECL|macro|QNATIVESOCKETENGINE_P_H
define|#
directive|define
name|QNATIVESOCKETENGINE_P_H
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
comment|// of the QLibrary class.  This header file may change from
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
file|"QtNetwork/qhostaddress.h"
end_include
begin_include
include|#
directive|include
file|"private/qabstractsocketengine_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WIN
end_ifndef
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|<netinet/in.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<winsock2.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// Use our own defines and structs which we know are correct
end_comment
begin_define
DECL|macro|QT_SS_MAXSIZE
define|#
directive|define
name|QT_SS_MAXSIZE
value|128
end_define
begin_define
DECL|macro|QT_SS_ALIGNSIZE
define|#
directive|define
name|QT_SS_ALIGNSIZE
value|(sizeof(qint64))
end_define
begin_define
DECL|macro|QT_SS_PAD1SIZE
define|#
directive|define
name|QT_SS_PAD1SIZE
value|(QT_SS_ALIGNSIZE - sizeof (short))
end_define
begin_define
DECL|macro|QT_SS_PAD2SIZE
define|#
directive|define
name|QT_SS_PAD2SIZE
value|(QT_SS_MAXSIZE - (sizeof (short) + QT_SS_PAD1SIZE + QT_SS_ALIGNSIZE))
end_define
begin_struct
DECL|struct|qt_sockaddr_storage
struct|struct
name|qt_sockaddr_storage
block|{
DECL|member|ss_family
name|short
name|ss_family
decl_stmt|;
DECL|member|__ss_pad1
name|char
name|__ss_pad1
index|[
name|QT_SS_PAD1SIZE
index|]
decl_stmt|;
DECL|member|__ss_align
name|qint64
name|__ss_align
decl_stmt|;
DECL|member|__ss_pad2
name|char
name|__ss_pad2
index|[
name|QT_SS_PAD2SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_define
DECL|macro|QT_SOCKLEN_T
define|#
directive|define
name|QT_SOCKLEN_T
value|int
end_define
begin_define
DECL|macro|QT_SOCKOPTLEN_T
define|#
directive|define
name|QT_SOCKOPTLEN_T
value|int
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// sockaddr_in6 size changed between old and new SDK
end_comment
begin_comment
comment|// Only the new version is the correct one, so always
end_comment
begin_comment
comment|// use this structure.
end_comment
begin_struct
DECL|struct|qt_in6_addr
struct|struct
name|qt_in6_addr
block|{
DECL|member|qt_s6_addr
name|quint8
name|qt_s6_addr
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|qt_sockaddr_in6
struct|struct
name|qt_sockaddr_in6
block|{
DECL|member|sin6_family
name|short
name|sin6_family
decl_stmt|;
comment|/* AF_INET6 */
DECL|member|sin6_port
name|quint16
name|sin6_port
decl_stmt|;
comment|/* Transport level port number */
DECL|member|sin6_flowinfo
name|quint32
name|sin6_flowinfo
decl_stmt|;
comment|/* IPv6 flow information */
DECL|member|sin6_addr
name|struct
name|qt_in6_addr
name|sin6_addr
decl_stmt|;
comment|/* IPv6 address */
DECL|member|sin6_scope_id
name|quint32
name|sin6_scope_id
decl_stmt|;
comment|/* set of interfaces for a scope */
block|}
struct|;
end_struct
begin_union
DECL|union|qt_sockaddr
union|union
name|qt_sockaddr
block|{
DECL|member|a
name|sockaddr
name|a
decl_stmt|;
DECL|member|a4
name|sockaddr_in
name|a4
decl_stmt|;
DECL|member|a6
name|qt_sockaddr_in6
name|a6
decl_stmt|;
DECL|member|storage
name|qt_sockaddr_storage
name|storage
decl_stmt|;
block|}
union|;
end_union
begin_decl_stmt
DECL|variable|QNativeSocketEnginePrivate
name|class
name|QNativeSocketEnginePrivate
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
end_ifndef
begin_decl_stmt
DECL|variable|QNetworkInterface
name|class
name|QNetworkInterface
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QNativeSocketEngine
range|:
name|public
name|QAbstractSocketEngine
block|{
name|Q_OBJECT
name|public
operator|:
name|QNativeSocketEngine
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNativeSocketEngine
argument_list|()
block|;
name|bool
name|initialize
argument_list|(
argument|QAbstractSocket::SocketType type
argument_list|,
argument|QAbstractSocket::NetworkLayerProtocol protocol = QAbstractSocket::IPv4Protocol
argument_list|)
block|;
name|bool
name|initialize
argument_list|(
argument|qintptr socketDescriptor
argument_list|,
argument|QAbstractSocket::SocketState socketState = QAbstractSocket::ConnectedState
argument_list|)
block|;
name|qintptr
name|socketDescriptor
argument_list|()
specifier|const
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|bool
name|connectToHost
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|bool
name|connectToHostByName
argument_list|(
argument|const QString&name
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|bool
name|bind
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|bool
name|listen
argument_list|()
block|;
name|int
name|accept
argument_list|()
block|;
name|void
name|close
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
name|bool
name|joinMulticastGroup
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|groupAddress
argument_list|,
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
block|;
name|bool
name|leaveMulticastGroup
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|groupAddress
argument_list|,
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
block|;
name|QNetworkInterface
name|multicastInterface
argument_list|()
specifier|const
block|;
name|bool
name|setMulticastInterface
argument_list|(
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
block|;
endif|#
directive|endif
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
block|;
name|qint64
name|read
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|write
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
block|;
name|qint64
name|readDatagram
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|,
argument|QHostAddress *addr =
literal|0
argument_list|,
argument|quint16 *port =
literal|0
argument_list|)
block|;
name|qint64
name|writeDatagram
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|,
argument|const QHostAddress&addr
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|bool
name|hasPendingDatagrams
argument_list|()
specifier|const
block|;
name|qint64
name|pendingDatagramSize
argument_list|()
specifier|const
block|;
name|qint64
name|bytesToWrite
argument_list|()
specifier|const
block|;
name|qint64
name|receiveBufferSize
argument_list|()
specifier|const
block|;
name|void
name|setReceiveBufferSize
argument_list|(
argument|qint64 bufferSize
argument_list|)
block|;
name|qint64
name|sendBufferSize
argument_list|()
specifier|const
block|;
name|void
name|setSendBufferSize
argument_list|(
argument|qint64 bufferSize
argument_list|)
block|;
name|int
name|option
argument_list|(
argument|SocketOption option
argument_list|)
specifier|const
block|;
name|bool
name|setOption
argument_list|(
argument|SocketOption option
argument_list|,
argument|int value
argument_list|)
block|;
name|bool
name|waitForRead
argument_list|(
argument|int msecs =
literal|30000
argument_list|,
argument|bool *timedOut =
literal|0
argument_list|)
block|;
name|bool
name|waitForWrite
argument_list|(
argument|int msecs =
literal|30000
argument_list|,
argument|bool *timedOut =
literal|0
argument_list|)
block|;
name|bool
name|waitForReadOrWrite
argument_list|(
argument|bool *readyToRead
argument_list|,
argument|bool *readyToWrite
argument_list|,
argument|bool checkRead
argument_list|,
argument|bool checkWrite
argument_list|,
argument|int msecs =
literal|30000
argument_list|,
argument|bool *timedOut =
literal|0
argument_list|)
block|;
name|bool
name|isReadNotificationEnabled
argument_list|()
specifier|const
block|;
name|void
name|setReadNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isWriteNotificationEnabled
argument_list|()
specifier|const
block|;
name|void
name|setWriteNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isExceptionNotificationEnabled
argument_list|()
specifier|const
block|;
name|void
name|setExceptionNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
comment|// non-virtual override;
name|void
name|connectionNotification
argument_list|()
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QNativeSocketEngine
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QNativeSocketEngine
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_decl_stmt
name|class
name|QWindowsSockInit
block|{
name|public
label|:
name|QWindowsSockInit
argument_list|()
expr_stmt|;
operator|~
name|QWindowsSockInit
argument_list|()
expr_stmt|;
name|int
name|version
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNativeSocketEnginePrivate
range|:
name|public
name|QAbstractSocketEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QNativeSocketEngine
argument_list|)
name|public
operator|:
name|QNativeSocketEnginePrivate
argument_list|()
block|;
operator|~
name|QNativeSocketEnginePrivate
argument_list|()
block|;
name|qintptr
name|socketDescriptor
block|;
name|QSocketNotifier
operator|*
name|readNotifier
block|,
operator|*
name|writeNotifier
block|,
operator|*
name|exceptNotifier
block|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QWindowsSockInit
name|winSock
block|;
endif|#
directive|endif
block|enum
name|ErrorString
block|{
name|NonBlockingInitFailedErrorString
block|,
name|BroadcastingInitFailedErrorString
block|,
name|NoIpV6ErrorString
block|,
name|RemoteHostClosedErrorString
block|,
name|TimeOutErrorString
block|,
name|ResourceErrorString
block|,
name|OperationUnsupportedErrorString
block|,
name|ProtocolUnsupportedErrorString
block|,
name|InvalidSocketErrorString
block|,
name|HostUnreachableErrorString
block|,
name|NetworkUnreachableErrorString
block|,
name|AccessErrorString
block|,
name|ConnectionTimeOutErrorString
block|,
name|ConnectionRefusedErrorString
block|,
name|AddressInuseErrorString
block|,
name|AddressNotAvailableErrorString
block|,
name|AddressProtectedErrorString
block|,
name|DatagramTooLargeErrorString
block|,
name|SendDatagramErrorString
block|,
name|ReceiveDatagramErrorString
block|,
name|WriteErrorString
block|,
name|ReadErrorString
block|,
name|PortInuseErrorString
block|,
name|NotSocketErrorString
block|,
name|InvalidProxyTypeString
block|,
name|TemporaryErrorString
block|,
name|UnknownSocketErrorString
operator|=
operator|-
literal|1
block|}
block|;
name|void
name|setError
argument_list|(
argument|QAbstractSocket::SocketError error
argument_list|,
argument|ErrorString errorString
argument_list|)
specifier|const
block|;
comment|// native functions
name|int
name|option
argument_list|(
argument|QNativeSocketEngine::SocketOption option
argument_list|)
specifier|const
block|;
name|bool
name|setOption
argument_list|(
argument|QNativeSocketEngine::SocketOption option
argument_list|,
argument|int value
argument_list|)
block|;
name|bool
name|createNewSocket
argument_list|(
argument|QAbstractSocket::SocketType type
argument_list|,
argument|QAbstractSocket::NetworkLayerProtocol&protocol
argument_list|)
block|;
name|bool
name|nativeConnect
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|bool
name|nativeBind
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|bool
name|nativeListen
argument_list|(
argument|int backlog
argument_list|)
block|;
name|int
name|nativeAccept
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
name|bool
name|nativeJoinMulticastGroup
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|groupAddress
argument_list|,
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
block|;
name|bool
name|nativeLeaveMulticastGroup
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|groupAddress
argument_list|,
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
block|;
name|QNetworkInterface
name|nativeMulticastInterface
argument_list|()
specifier|const
block|;
name|bool
name|nativeSetMulticastInterface
argument_list|(
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
block|;
endif|#
directive|endif
name|qint64
name|nativeBytesAvailable
argument_list|()
specifier|const
block|;
name|bool
name|nativeHasPendingDatagrams
argument_list|()
specifier|const
block|;
name|qint64
name|nativePendingDatagramSize
argument_list|()
specifier|const
block|;
name|qint64
name|nativeReceiveDatagram
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxLength
argument_list|,
argument|QHostAddress *address
argument_list|,
argument|quint16 *port
argument_list|)
block|;
name|qint64
name|nativeSendDatagram
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 length
argument_list|,
argument|const QHostAddress&host
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|qint64
name|nativeRead
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxLength
argument_list|)
block|;
name|qint64
name|nativeWrite
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 length
argument_list|)
block|;
name|int
name|nativeSelect
argument_list|(
argument|int timeout
argument_list|,
argument|bool selectForRead
argument_list|)
specifier|const
block|;
name|int
name|nativeSelect
argument_list|(
argument|int timeout
argument_list|,
argument|bool checkRead
argument_list|,
argument|bool checkWrite
argument_list|,
argument|bool *selectForRead
argument_list|,
argument|bool *selectForWrite
argument_list|)
specifier|const
block|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|void
name|setPortAndAddress
argument_list|(
argument|sockaddr_in * sockAddrIPv4
argument_list|,
argument|qt_sockaddr_in6 * sockAddrIPv6
argument_list|,
argument|quint16 port
argument_list|,
argument|const QHostAddress& address
argument_list|,
argument|sockaddr ** sockAddrPtr
argument_list|,
argument|QT_SOCKLEN_T *sockAddrSize
argument_list|)
block|;
endif|#
directive|endif
name|void
name|nativeClose
argument_list|()
block|;
name|bool
name|checkProxy
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|address
argument_list|)
block|;
name|bool
name|fetchConnectionParameters
argument_list|()
block|; }
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
comment|// QNATIVESOCKETENGINE_P_H
end_comment
end_unit
