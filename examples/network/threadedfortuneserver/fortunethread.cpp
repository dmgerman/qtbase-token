begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"fortunethread.h"
end_include
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|FortuneThread
name|FortuneThread
operator|::
name|FortuneThread
parameter_list|(
name|int
name|socketDescriptor
parameter_list|,
specifier|const
name|QString
modifier|&
name|fortune
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|socketDescriptor
argument_list|(
name|socketDescriptor
argument_list|)
member_init_list|,
name|text
argument_list|(
name|fortune
argument_list|)
block|{ }
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|run
name|void
name|FortuneThread
operator|::
name|run
parameter_list|()
block|{
name|QTcpSocket
name|tcpSocket
decl_stmt|;
comment|//! [1] //! [2]
if|if
condition|(
operator|!
name|tcpSocket
operator|.
name|setSocketDescriptor
argument_list|(
name|socketDescriptor
argument_list|)
condition|)
block|{
emit|emit
name|error
argument_list|(
name|tcpSocket
operator|.
name|error
argument_list|()
argument_list|)
emit|;
return|return;
block|}
comment|//! [2] //! [3]
name|QByteArray
name|block
decl_stmt|;
name|QDataStream
name|out
argument_list|(
operator|&
name|block
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|out
operator|.
name|setVersion
argument_list|(
name|QDataStream
operator|::
name|Qt_4_0
argument_list|)
expr_stmt|;
name|out
operator|<<
operator|(
name|quint16
operator|)
literal|0
expr_stmt|;
name|out
operator|<<
name|text
expr_stmt|;
name|out
operator|.
name|device
argument_list|()
operator|->
name|seek
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|out
operator|<<
call|(
name|quint16
call|)
argument_list|(
name|block
operator|.
name|size
argument_list|()
operator|-
sizeof|sizeof
argument_list|(
name|quint16
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [3] //! [4]
name|tcpSocket
operator|.
name|write
argument_list|(
name|block
argument_list|)
expr_stmt|;
name|tcpSocket
operator|.
name|disconnectFromHost
argument_list|()
expr_stmt|;
name|tcpSocket
operator|.
name|waitForDisconnected
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
end_unit
