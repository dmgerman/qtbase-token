begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CLIENT_H
end_ifndef
begin_define
DECL|macro|CLIENT_H
define|#
directive|define
name|CLIENT_H
end_define
begin_include
include|#
directive|include
file|<QAbstractSocket>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QHostAddress>
end_include
begin_include
include|#
directive|include
file|"server.h"
end_include
begin_decl_stmt
DECL|variable|PeerManager
name|class
name|PeerManager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Client
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|Client
argument_list|()
block|;
name|void
name|sendMessage
argument_list|(
specifier|const
name|QString
operator|&
name|message
argument_list|)
block|;
name|QString
name|nickName
argument_list|()
specifier|const
block|;
name|bool
name|hasConnection
argument_list|(
argument|const QHostAddress&senderIp
argument_list|,
argument|int senderPort = -
literal|1
argument_list|)
specifier|const
block|;
name|signals
operator|:
name|void
name|newMessage
argument_list|(
specifier|const
name|QString
operator|&
name|from
argument_list|,
specifier|const
name|QString
operator|&
name|message
argument_list|)
block|;
name|void
name|newParticipant
argument_list|(
specifier|const
name|QString
operator|&
name|nick
argument_list|)
block|;
name|void
name|participantLeft
argument_list|(
specifier|const
name|QString
operator|&
name|nick
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|newConnection
argument_list|(
name|Connection
operator|*
name|connection
argument_list|)
block|;
name|void
name|connectionError
argument_list|(
argument|QAbstractSocket::SocketError socketError
argument_list|)
block|;
name|void
name|disconnected
argument_list|()
block|;
name|void
name|readyForUse
argument_list|()
block|;
name|private
operator|:
name|void
name|removeConnection
argument_list|(
name|Connection
operator|*
name|connection
argument_list|)
block|;
name|PeerManager
operator|*
name|peerManager
block|;
name|Server
name|server
block|;
name|QMultiHash
operator|<
name|QHostAddress
block|,
name|Connection
operator|*
operator|>
name|peers
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
