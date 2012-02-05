begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLOCALSOCKET_H
end_ifndef
begin_define
DECL|macro|QLOCALSOCKET_H
define|#
directive|define
name|QLOCALSOCKET_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qabstractsocket.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_LOCALSOCKET
DECL|variable|QLocalSocketPrivate
name|class
name|QLocalSocketPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QLocalSocket
range|:
name|public
name|QIODevice
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QLocalSocket
argument_list|)
name|public
operator|:
expr|enum
name|LocalSocketError
block|{
name|ConnectionRefusedError
operator|=
name|QAbstractSocket
operator|::
name|ConnectionRefusedError
block|,
name|PeerClosedError
operator|=
name|QAbstractSocket
operator|::
name|RemoteHostClosedError
block|,
name|ServerNotFoundError
operator|=
name|QAbstractSocket
operator|::
name|HostNotFoundError
block|,
name|SocketAccessError
operator|=
name|QAbstractSocket
operator|::
name|SocketAccessError
block|,
name|SocketResourceError
operator|=
name|QAbstractSocket
operator|::
name|SocketResourceError
block|,
name|SocketTimeoutError
operator|=
name|QAbstractSocket
operator|::
name|SocketTimeoutError
block|,
name|DatagramTooLargeError
operator|=
name|QAbstractSocket
operator|::
name|DatagramTooLargeError
block|,
name|ConnectionError
operator|=
name|QAbstractSocket
operator|::
name|NetworkError
block|,
name|UnsupportedSocketOperationError
operator|=
name|QAbstractSocket
operator|::
name|UnsupportedSocketOperationError
block|,
name|UnknownSocketError
operator|=
name|QAbstractSocket
operator|::
name|UnknownSocketError
block|,
name|OperationError
operator|=
name|QAbstractSocket
operator|::
name|OperationError
block|}
block|;      enum
name|LocalSocketState
block|{
name|UnconnectedState
operator|=
name|QAbstractSocket
operator|::
name|UnconnectedState
block|,
name|ConnectingState
operator|=
name|QAbstractSocket
operator|::
name|ConnectingState
block|,
name|ConnectedState
operator|=
name|QAbstractSocket
operator|::
name|ConnectedState
block|,
name|ClosingState
operator|=
name|QAbstractSocket
operator|::
name|ClosingState
block|}
block|;
name|QLocalSocket
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QLocalSocket
argument_list|()
block|;
name|void
name|connectToServer
argument_list|(
argument|const QString&name
argument_list|,
argument|OpenMode openMode = ReadWrite
argument_list|)
block|;
name|void
name|disconnectFromServer
argument_list|()
block|;
name|QString
name|serverName
argument_list|()
specifier|const
block|;
name|QString
name|fullServerName
argument_list|()
specifier|const
block|;
name|void
name|abort
argument_list|()
block|;
name|virtual
name|bool
name|isSequential
argument_list|()
specifier|const
block|;
name|virtual
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
block|;
name|virtual
name|qint64
name|bytesToWrite
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|canReadLine
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|close
argument_list|()
block|;
name|LocalSocketError
name|error
argument_list|()
specifier|const
block|;
name|bool
name|flush
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|qint64
name|readBufferSize
argument_list|()
specifier|const
block|;
name|void
name|setReadBufferSize
argument_list|(
argument|qint64 size
argument_list|)
block|;
name|bool
name|setSocketDescriptor
argument_list|(
argument|qintptr socketDescriptor
argument_list|,
argument|LocalSocketState socketState = ConnectedState
argument_list|,
argument|OpenMode openMode = ReadWrite
argument_list|)
block|;
name|qintptr
name|socketDescriptor
argument_list|()
specifier|const
block|;
name|LocalSocketState
name|state
argument_list|()
specifier|const
block|;
name|bool
name|waitForBytesWritten
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|bool
name|waitForConnected
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|bool
name|waitForDisconnected
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
name|Q_SIGNALS
operator|:
name|void
name|connected
argument_list|()
block|;
name|void
name|disconnected
argument_list|()
block|;
name|void
name|error
argument_list|(
argument|QLocalSocket::LocalSocketError socketError
argument_list|)
block|;
name|void
name|stateChanged
argument_list|(
argument|QLocalSocket::LocalSocketState socketState
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|qint64
name|readData
argument_list|(
name|char
operator|*
argument_list|,
name|qint64
argument_list|)
block|;
name|virtual
name|qint64
name|writeData
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|qint64
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QLocalSocket
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|QT_LOCALSOCKET_TCP
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_stateChanged(QAbstractSocket::SocketState)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_error(QAbstractSocket::SocketError)
argument_list|)
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_canWrite()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_pipeClosed()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_winError(ulong, const QString&)
argument_list|)
else|#
directive|else
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_stateChanged(QAbstractSocket::SocketState)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_error(QAbstractSocket::SocketError)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_connectToSocket()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_abortConnectionAttempt()
argument_list|)
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
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
begin_expr_stmt
name|Q_NETWORK_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
name|QLocalSocket
operator|::
name|LocalSocketError
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
name|QLocalSocket
operator|::
name|LocalSocketState
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LOCALSOCKET
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLOCALSOCKET_H
end_comment
end_unit
