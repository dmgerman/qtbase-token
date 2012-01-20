begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|RATECONTROLLER_H
end_ifndef
begin_define
DECL|macro|RATECONTROLLER_H
define|#
directive|define
name|RATECONTROLLER_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QSet>
end_include
begin_include
include|#
directive|include
file|<QTime>
end_include
begin_decl_stmt
DECL|variable|PeerWireClient
name|class
name|PeerWireClient
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|RateController
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
specifier|inline
name|RateController
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|,
name|transferScheduled
argument_list|(
argument|false
argument_list|)
block|{ }
specifier|static
name|RateController
operator|*
name|instance
argument_list|()
block|;
name|void
name|addSocket
argument_list|(
name|PeerWireClient
operator|*
name|socket
argument_list|)
block|;
name|void
name|removeSocket
argument_list|(
name|PeerWireClient
operator|*
name|socket
argument_list|)
block|;
specifier|inline
name|int
name|uploadLimit
argument_list|()
specifier|const
block|{
return|return
name|upLimit
return|;
block|}
specifier|inline
name|int
name|downloadLimit
argument_list|()
specifier|const
block|{
return|return
name|downLimit
return|;
block|}
specifier|inline
name|void
name|setUploadLimit
argument_list|(
argument|int bytesPerSecond
argument_list|)
block|{
name|upLimit
operator|=
name|bytesPerSecond
block|; }
name|void
name|setDownloadLimit
argument_list|(
argument|int bytesPerSecond
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|transfer
argument_list|()
block|;
name|void
name|scheduleTransfer
argument_list|()
block|;
name|private
operator|:
name|QTime
name|stopWatch
block|;
name|QSet
operator|<
name|PeerWireClient
operator|*
operator|>
name|sockets
block|;
name|int
name|upLimit
block|;
name|int
name|downLimit
block|;
name|bool
name|transferScheduled
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
