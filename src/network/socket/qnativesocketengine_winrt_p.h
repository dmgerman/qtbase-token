begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNATIVESOCKETENGINE_WINRT_P_H
end_ifndef
begin_define
DECL|macro|QNATIVESOCKETENGINE_WINRT_P_H
define|#
directive|define
name|QNATIVESOCKETENGINE_WINRT_P_H
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
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<windows.networking.sockets.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QNativeSocketEnginePrivate
name|class
name|QNativeSocketEnginePrivate
decl_stmt|;
end_decl_stmt
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
comment|// QNATIVESOCKETENGINE_WINRT_P_H
end_comment
end_unit
