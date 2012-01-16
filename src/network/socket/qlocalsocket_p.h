begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLOCALSOCKET_P_H
end_ifndef
begin_define
DECL|macro|QLOCALSOCKET_P_H
define|#
directive|define
name|QLOCALSOCKET_P_H
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
comment|// of the QLocalSocket class.  This header file may change from
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LOCALSOCKET
end_ifndef
begin_include
include|#
directive|include
file|"qlocalsocket.h"
end_include
begin_include
include|#
directive|include
file|"private/qiodevice_p.h"
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_LOCALSOCKET_TCP
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qtcpsocket.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"private/qwindowspipereader_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qwindowspipewriter_p.h"
end_include
begin_include
include|#
directive|include
file|<qwineventnotifier.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"private/qabstractsocketengine_p.h"
end_include
begin_include
include|#
directive|include
file|<qtcpsocket.h>
end_include
begin_include
include|#
directive|include
file|<qsocketnotifier.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_LOCALSOCKET_TCP
argument_list|)
name|class
name|QLocalUnixSocket
range|:
name|public
name|QTcpSocket
block|{
name|public
operator|:
name|QLocalUnixSocket
argument_list|()
operator|:
name|QTcpSocket
argument_list|()
block|{     }
block|;
specifier|inline
name|void
name|setSocketState
argument_list|(
argument|QAbstractSocket::SocketState state
argument_list|)
block|{
name|QTcpSocket
operator|::
name|setSocketState
argument_list|(
name|state
argument_list|)
block|;     }
block|;
specifier|inline
name|void
name|setErrorString
argument_list|(
argument|const QString&string
argument_list|)
block|{
name|QTcpSocket
operator|::
name|setErrorString
argument_list|(
name|string
argument_list|)
block|;     }
specifier|inline
name|void
name|setSocketError
argument_list|(
argument|QAbstractSocket::SocketError error
argument_list|)
block|{
name|QTcpSocket
operator|::
name|setSocketError
argument_list|(
name|error
argument_list|)
block|;     }
specifier|inline
name|qint64
name|readData
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxSize
argument_list|)
block|{
return|return
name|QTcpSocket
operator|::
name|readData
argument_list|(
name|data
argument_list|,
name|maxSize
argument_list|)
return|;
block|}
specifier|inline
name|qint64
name|writeData
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 maxSize
argument_list|)
block|{
return|return
name|QTcpSocket
operator|::
name|writeData
argument_list|(
name|data
argument_list|,
name|maxSize
argument_list|)
return|;
block|}
expr|}
block|;
endif|#
directive|endif
comment|//#if !defined(Q_OS_WIN) || defined(QT_LOCALSOCKET_TCP)
name|class
name|QLocalSocketPrivate
operator|:
name|public
name|QIODevicePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QLocalSocket
argument_list|)
name|public
operator|:
name|QLocalSocketPrivate
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
if|#
directive|if
name|defined
argument_list|(
name|QT_LOCALSOCKET_TCP
argument_list|)
name|QLocalUnixSocket
operator|*
name|tcpSocket
block|;
name|bool
name|ownsTcpSocket
block|;
name|void
name|setSocket
argument_list|(
name|QLocalUnixSocket
operator|*
argument_list|)
block|;
name|QString
name|generateErrorString
argument_list|(
argument|QLocalSocket::LocalSocketError
argument_list|,
argument|const QString&function
argument_list|)
specifier|const
block|;
name|void
name|errorOccurred
argument_list|(
name|QLocalSocket
operator|::
name|LocalSocketError
argument_list|,
specifier|const
name|QString
operator|&
name|function
argument_list|)
block|;
name|void
name|_q_stateChanged
argument_list|(
argument|QAbstractSocket::SocketState newState
argument_list|)
block|;
name|void
name|_q_error
argument_list|(
argument|QAbstractSocket::SocketError newError
argument_list|)
block|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|~
name|QLocalSocketPrivate
argument_list|()
block|;
name|void
name|destroyPipeHandles
argument_list|()
block|;
name|void
name|setErrorString
argument_list|(
specifier|const
name|QString
operator|&
name|function
argument_list|)
block|;
name|void
name|_q_canWrite
argument_list|()
block|;
name|void
name|_q_pipeClosed
argument_list|()
block|;
name|void
name|_q_winError
argument_list|(
argument|ulong windowsError
argument_list|,
argument|const QString&function
argument_list|)
block|;
name|HANDLE
name|handle
block|;
name|QWindowsPipeWriter
operator|*
name|pipeWriter
block|;
name|QWindowsPipeReader
operator|*
name|pipeReader
block|;
name|QLocalSocket
operator|::
name|LocalSocketError
name|error
block|;
else|#
directive|else
name|QLocalUnixSocket
name|unixSocket
block|;
name|QString
name|generateErrorString
argument_list|(
argument|QLocalSocket::LocalSocketError
argument_list|,
argument|const QString&function
argument_list|)
specifier|const
block|;
name|void
name|errorOccurred
argument_list|(
name|QLocalSocket
operator|::
name|LocalSocketError
argument_list|,
specifier|const
name|QString
operator|&
name|function
argument_list|)
block|;
name|void
name|_q_stateChanged
argument_list|(
argument|QAbstractSocket::SocketState newState
argument_list|)
block|;
name|void
name|_q_error
argument_list|(
argument|QAbstractSocket::SocketError newError
argument_list|)
block|;
name|void
name|_q_connectToSocket
argument_list|()
block|;
name|void
name|_q_abortConnectionAttempt
argument_list|()
block|;
name|void
name|cancelDelayedConnect
argument_list|()
block|;
name|QSocketNotifier
operator|*
name|delayConnect
block|;
name|QTimer
operator|*
name|connectTimer
block|;
name|int
name|connectingSocket
block|;
name|QString
name|connectingName
block|;
name|QIODevice
operator|::
name|OpenMode
name|connectingOpenMode
block|;
endif|#
directive|endif
name|QString
name|serverName
block|;
name|QString
name|fullServerName
block|;
name|QLocalSocket
operator|::
name|LocalSocketState
name|state
block|; }
block|;
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LOCALSOCKET
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLOCALSOCKET_P_H
end_comment
end_unit
