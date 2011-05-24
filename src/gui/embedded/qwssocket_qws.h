begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWSSOCKET_QWS_H
end_ifndef
begin_define
DECL|macro|QWSSOCKET_QWS_H
define|#
directive|define
name|QWSSOCKET_QWS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qconfig.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwsutils_qws.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_MULTIPROCESS
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SXE
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qunixsocketserver_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qunixsocket_p.h>
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
begin_include
include|#
directive|include
file|<QtNetwork/qtcpserver.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QWSSocket
range|:
name|public
name|QWS_SOCK_BASE
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QWSSocket
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QWSSocket
argument_list|()
block|;
name|bool
name|connectToLocalFile
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_SXE
name|QString
name|errorString
argument_list|()
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
name|QAbstractSocket
operator|::
name|SocketError
argument_list|)
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|forwardStateChange
argument_list|(
name|SocketState
argument_list|)
block|;
endif|#
directive|endif
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QWSSocket
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWSServerSocket
range|:
name|public
name|QWS_SOCK_SERVER_BASE
block|{
name|Q_OBJECT
name|public
operator|:
name|QWSServerSocket
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QWSServerSocket
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_SXE
name|QWSSocket
operator|*
name|nextPendingConnection
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|newConnection
argument_list|()
block|;
name|protected
operator|:
name|void
name|incomingConnection
argument_list|(
argument|int socketDescriptor
argument_list|)
block|;
name|private
operator|:
name|QMutex
name|ssmx
block|;
name|QList
operator|<
name|int
operator|>
name|inboundConnections
block|;
endif|#
directive|endif
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QWSServerSocket
argument_list|)
name|void
name|init
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QWS_MULTIPROCESS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWSSOCKET_QWS_H
end_comment
end_unit
