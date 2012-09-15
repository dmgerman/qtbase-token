begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PEERWIRECLIENT_H
end_ifndef
begin_define
DECL|macro|PEERWIRECLIENT_H
define|#
directive|define
name|PEERWIRECLIENT_H
end_define
begin_include
include|#
directive|include
file|<QBitArray>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QTcpSocket>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QHostAddress
name|class
name|QHostAddress
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTimerEvent
name|class
name|QTimerEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
DECL|variable|TorrentPeer
name|class
name|TorrentPeer
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|TorrentBlock
struct|struct
name|TorrentBlock
block|{
DECL|function|TorrentBlock
specifier|inline
name|TorrentBlock
argument_list|(
argument|int p
argument_list|,
argument|int o
argument_list|,
argument|int l
argument_list|)
operator|:
name|pieceIndex
argument_list|(
name|p
argument_list|)
operator|,
name|offset
argument_list|(
name|o
argument_list|)
operator|,
name|length
argument_list|(
argument|l
argument_list|)
block|{     }
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|TorrentBlock
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|pieceIndex
operator|==
name|other
operator|.
name|pieceIndex
operator|&&
name|offset
operator|==
name|other
operator|.
name|offset
operator|&&
name|length
operator|==
name|other
operator|.
name|length
return|;
block|}
DECL|member|pieceIndex
name|int
name|pieceIndex
decl_stmt|;
DECL|member|offset
name|int
name|offset
decl_stmt|;
DECL|member|length
name|int
name|length
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|PeerWireClient
range|:
name|public
name|QTcpSocket
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|PeerWireStateFlag
block|{
name|ChokingPeer
operator|=
literal|0x1
block|,
name|InterestedInPeer
operator|=
literal|0x2
block|,
name|ChokedByPeer
operator|=
literal|0x4
block|,
name|PeerIsInterested
operator|=
literal|0x8
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|PeerWireState
argument_list|,
argument|PeerWireStateFlag
argument_list|)
name|explicit
name|PeerWireClient
argument_list|(
specifier|const
name|QByteArray
operator|&
name|peerId
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|initialize
argument_list|(
argument|const QByteArray&infoHash
argument_list|,
argument|int pieceCount
argument_list|)
block|;
name|void
name|setPeer
argument_list|(
name|TorrentPeer
operator|*
name|peer
argument_list|)
block|;
name|TorrentPeer
operator|*
name|peer
argument_list|()
specifier|const
block|;
comment|// State
specifier|inline
name|PeerWireState
name|peerWireState
argument_list|()
specifier|const
block|{
return|return
name|pwState
return|;
block|}
name|QBitArray
name|availablePieces
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|TorrentBlock
operator|>
name|incomingBlocks
argument_list|()
specifier|const
block|;
comment|// Protocol
name|void
name|chokePeer
argument_list|()
block|;
name|void
name|unchokePeer
argument_list|()
block|;
name|void
name|sendInterested
argument_list|()
block|;
name|void
name|sendKeepAlive
argument_list|()
block|;
name|void
name|sendNotInterested
argument_list|()
block|;
name|void
name|sendPieceNotification
argument_list|(
argument|int piece
argument_list|)
block|;
name|void
name|sendPieceList
argument_list|(
specifier|const
name|QBitArray
operator|&
name|bitField
argument_list|)
block|;
name|void
name|requestBlock
argument_list|(
argument|int piece
argument_list|,
argument|int offset
argument_list|,
argument|int length
argument_list|)
block|;
name|void
name|cancelRequest
argument_list|(
argument|int piece
argument_list|,
argument|int offset
argument_list|,
argument|int length
argument_list|)
block|;
name|void
name|sendBlock
argument_list|(
argument|int piece
argument_list|,
argument|int offset
argument_list|,
argument|const QByteArray&data
argument_list|)
block|;
comment|// Rate control
name|qint64
name|writeToSocket
argument_list|(
argument|qint64 bytes
argument_list|)
block|;
name|qint64
name|readFromSocket
argument_list|(
argument|qint64 bytes
argument_list|)
block|;
name|qint64
name|downloadSpeed
argument_list|()
specifier|const
block|;
name|qint64
name|uploadSpeed
argument_list|()
specifier|const
block|;
name|bool
name|canTransferMore
argument_list|()
specifier|const
block|;
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
block|{
return|return
name|incomingBuffer
operator|.
name|size
argument_list|()
operator|+
name|QTcpSocket
operator|::
name|bytesAvailable
argument_list|()
return|;
block|}
name|qint64
name|socketBytesAvailable
argument_list|()
specifier|const
block|{
return|return
name|socket
operator|.
name|bytesAvailable
argument_list|()
return|;
block|}
name|qint64
name|socketBytesToWrite
argument_list|()
specifier|const
block|{
return|return
name|socket
operator|.
name|bytesToWrite
argument_list|()
return|;
block|}
name|void
name|setReadBufferSize
argument_list|(
argument|qint64 size
argument_list|)
block|;
name|signals
operator|:
name|void
name|infoHashReceived
argument_list|(
specifier|const
name|QByteArray
operator|&
name|infoHash
argument_list|)
block|;
name|void
name|readyToTransfer
argument_list|()
block|;
name|void
name|choked
argument_list|()
block|;
name|void
name|unchoked
argument_list|()
block|;
name|void
name|interested
argument_list|()
block|;
name|void
name|notInterested
argument_list|()
block|;
name|void
name|piecesAvailable
argument_list|(
specifier|const
name|QBitArray
operator|&
name|pieces
argument_list|)
block|;
name|void
name|blockRequested
argument_list|(
argument|int pieceIndex
argument_list|,
argument|int begin
argument_list|,
argument|int length
argument_list|)
block|;
name|void
name|blockReceived
argument_list|(
argument|int pieceIndex
argument_list|,
argument|int begin
argument_list|,
argument|const QByteArray&data
argument_list|)
block|;
name|void
name|bytesReceived
argument_list|(
argument|qint64 size
argument_list|)
block|;
name|protected
name|slots
operator|:
name|void
name|connectToHostImplementation
argument_list|(
argument|const QString&hostName
argument_list|,
argument|quint16 port
argument_list|,
argument|OpenMode openMode = ReadWrite
argument_list|)
block|;
name|void
name|diconnectFromHostImplementation
argument_list|()
block|;
name|protected
operator|:
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|event
argument_list|)
block|;
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
name|private
name|slots
operator|:
name|void
name|sendHandShake
argument_list|()
block|;
name|void
name|processIncomingData
argument_list|()
block|;
name|void
name|socketStateChanged
argument_list|(
argument|QAbstractSocket::SocketState state
argument_list|)
block|;
name|private
operator|:
comment|// Data waiting to be read/written
name|QByteArray
name|incomingBuffer
block|;
name|QByteArray
name|outgoingBuffer
block|;      struct
name|BlockInfo
block|{
name|int
name|pieceIndex
block|;
name|int
name|offset
block|;
name|int
name|length
block|;
name|QByteArray
name|block
block|;     }
block|;
name|QList
operator|<
name|BlockInfo
operator|>
name|pendingBlocks
block|;
name|int
name|pendingBlockSizes
block|;
name|QList
operator|<
name|TorrentBlock
operator|>
name|incoming
block|;      enum
name|PacketType
block|{
name|ChokePacket
operator|=
literal|0
block|,
name|UnchokePacket
operator|=
literal|1
block|,
name|InterestedPacket
operator|=
literal|2
block|,
name|NotInterestedPacket
operator|=
literal|3
block|,
name|HavePacket
operator|=
literal|4
block|,
name|BitFieldPacket
operator|=
literal|5
block|,
name|RequestPacket
operator|=
literal|6
block|,
name|PiecePacket
operator|=
literal|7
block|,
name|CancelPacket
operator|=
literal|8
block|}
block|;
comment|// State
name|PeerWireState
name|pwState
block|;
name|bool
name|receivedHandShake
block|;
name|bool
name|gotPeerId
block|;
name|bool
name|sentHandShake
block|;
name|int
name|nextPacketLength
block|;
comment|// Upload/download speed records
name|qint64
name|uploadSpeedData
index|[
literal|8
index|]
block|;
name|qint64
name|downloadSpeedData
index|[
literal|8
index|]
block|;
name|int
name|transferSpeedTimer
block|;
comment|// Timeout handling
name|int
name|timeoutTimer
block|;
name|int
name|pendingRequestTimer
block|;
name|bool
name|invalidateTimeout
block|;
name|int
name|keepAliveTimer
block|;
comment|// Checksum, peer ID and set of available pieces
name|QByteArray
name|infoHash
block|;
name|QByteArray
name|peerIdString
block|;
name|QBitArray
name|peerPieces
block|;
name|TorrentPeer
operator|*
name|torrentPeer
block|;
name|QTcpSocket
name|socket
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|PeerWireClient::PeerWireState
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
