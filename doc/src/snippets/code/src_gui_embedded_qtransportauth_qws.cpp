begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_function
DECL|function|wrapInFunction
name|void
name|wrapInFunction
parameter_list|()
block|{
comment|//! [0]
name|QTransportAuth
operator|::
name|Data
modifier|*
name|conData
decl_stmt|;
name|QTransportAuth
modifier|*
name|a
init|=
name|QTransportAuth
operator|::
name|getInstance
argument_list|()
decl_stmt|;
name|conData
operator|=
name|a
operator|->
name|connectTransport
argument_list|(
name|QTransportAuth
operator|::
name|Trusted
operator||
name|QTransportAuth
operator|::
name|UnixStreamSock
argument_list|,
name|socketDescriptor
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
comment|// mySocket can be any QIODevice subclass
name|AuthDevice
modifier|*
name|ad
init|=
name|a
operator|->
name|recvBuf
argument_list|(
name|d
argument_list|,
name|mySocket
argument_list|)
decl_stmt|;
comment|// proxy in the auth device where the socket would have gone
name|connect
argument_list|(
name|ad
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|mySocketReadyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|AuthDevice
modifier|*
name|ad
init|=
name|a
operator|->
name|authBuf
argument_list|(
name|d
argument_list|,
name|mySocket
argument_list|)
decl_stmt|;
name|ad
operator|->
name|write
argument_list|(
name|someData
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|policyCheck
argument_list|(
argument|QTransportAuth::Data&
argument_list|,
argument|const QString&
argument_list|)
comment|//! [3]
comment|//! [4]
name|QTransportAuth
operator|::
name|Result
name|r
init|=
name|d
operator|.
name|status
operator|&
name|QTransportAuth
operator|::
name|ErrMask
decl_stmt|;
name|qWarning
argument_list|(
literal|"error: %s"
argument_list|,
name|QTransportAuth
operator|::
name|errorStrings
index|[
name|r
index|]
argument_list|)
expr_stmt|;
comment|//! [4]
comment|//! [5]
name|MD5
argument_list|(
argument|K XOR opad
argument_list|,
argument|MD5(K XOR ipad, text)
argument_list|)
comment|//! [5]
block|}
end_function
end_unit
