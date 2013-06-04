begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MINIHTTPSERVER_H
end_ifndef
begin_define
DECL|macro|MINIHTTPSERVER_H
define|#
directive|define
name|MINIHTTPSERVER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTimer>
end_include
begin_decl_stmt
DECL|variable|QFile
name|class
name|QFile
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSemaphore
name|class
name|QSemaphore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTcpServer
name|class
name|QTcpServer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTcpSocket
name|class
name|QTcpSocket
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|MiniHttpServer
range|:
name|public
name|QThread
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|MiniHttpServer
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|MiniHttpServer
argument_list|()
block|;
name|int
name|port
argument_list|()
block|{
return|return
name|portnum
return|;
block|}
name|protected
operator|:
name|void
name|run
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|handleConnection
argument_list|()
block|;
name|private
operator|:
name|QTcpServer
operator|*
name|server
block|;
name|QObject
operator|*
name|quitObject
block|;
name|QSemaphore
operator|*
name|readyToGo
block|;
name|int
name|portnum
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|MiniHttpServerConnection
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|QTcpSocket
operator|*
specifier|const
name|socket
block|;
name|QFile
name|source
block|;
name|QTimer
name|timeout
block|;
name|QByteArray
name|buffer
block|;
name|bool
name|connectionClose
block|;
name|public
operator|:
name|explicit
name|MiniHttpServerConnection
argument_list|(
name|QTcpSocket
operator|*
name|socket
argument_list|)
block|;
name|void
name|sendError500
argument_list|()
block|;
name|void
name|sendError404
argument_list|()
block|;
name|void
name|handlePendingRequest
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|handleReadyRead
argument_list|()
block|;
name|void
name|handleBytesWritten
argument_list|()
block|;
name|void
name|handleDisconnected
argument_list|()
block|;
name|void
name|handleTimeout
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MINIHTTPSERVER_H
end_comment
end_unit
