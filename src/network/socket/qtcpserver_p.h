begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTCPSERVER_P_H
end_ifndef
begin_define
DECL|macro|QTCPSERVER_P_H
define|#
directive|define
name|QTCPSERVER_P_H
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
file|"QtNetwork/qtcpserver.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qabstractsocketengine_p.h"
end_include
begin_include
include|#
directive|include
file|"QtNetwork/qabstractsocket.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkproxy.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qlist.h"
end_include
begin_include
include|#
directive|include
file|"qhostaddress.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QObjectPrivate
name|class
name|QTcpServerPrivate
range|:
name|public
name|QObjectPrivate
decl_stmt|,
name|public
name|QAbstractSocketEngineReceiver
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTcpServer
argument_list|)
name|public
label|:
name|QTcpServerPrivate
argument_list|()
expr_stmt|;
operator|~
name|QTcpServerPrivate
argument_list|()
expr_stmt|;
name|QList
operator|<
name|QTcpSocket
operator|*
operator|>
name|pendingConnections
expr_stmt|;
name|quint16
name|port
decl_stmt|;
name|QHostAddress
name|address
decl_stmt|;
name|QAbstractSocket
operator|::
name|SocketState
name|state
expr_stmt|;
name|QAbstractSocketEngine
modifier|*
name|socketEngine
decl_stmt|;
name|QAbstractSocket
operator|::
name|SocketError
name|serverSocketError
expr_stmt|;
name|QString
name|serverSocketErrorString
decl_stmt|;
name|int
name|maxConnections
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|QNetworkProxy
name|proxy
decl_stmt|;
name|QNetworkProxy
name|resolveProxy
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|address
parameter_list|,
name|quint16
name|port
parameter_list|)
function_decl|;
endif|#
directive|endif
name|virtual
name|void
name|configureCreatedSocket
parameter_list|()
function_decl|;
comment|// from QAbstractSocketEngineReceiver
name|void
name|readNotification
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|closeNotification
parameter_list|()
function|Q_DECL_OVERRIDE
block|{
name|readNotification
argument_list|()
expr_stmt|;
block|}
name|void
name|writeNotification
parameter_list|()
function|Q_DECL_OVERRIDE
block|{}
name|void
name|exceptionNotification
parameter_list|()
function|Q_DECL_OVERRIDE
block|{}
name|void
name|connectionNotification
parameter_list|()
function|Q_DECL_OVERRIDE
block|{}
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|void
name|proxyAuthenticationRequired
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
parameter_list|,
name|QAuthenticator
modifier|*
parameter_list|)
function|Q_DECL_OVERRIDE
block|{}
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTCPSERVER_P_H
end_comment
end_unit
