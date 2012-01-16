begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|socket
name|QSslSocket
modifier|*
name|socket
init|=
operator|new
name|QSslSocket
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|connect
argument_list|(
name|socket
argument_list|,
name|SIGNAL
argument_list|(
name|encrypted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|ready
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|socket
operator|->
name|connectToHostEncrypted
argument_list|(
literal|"imap.example.com"
argument_list|,
literal|993
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|incomingConnection
name|void
name|SslServer
operator|::
name|incomingConnection
parameter_list|(
name|qintptr
name|socketDescriptor
parameter_list|)
block|{
name|QSslSocket
modifier|*
name|serverSocket
init|=
operator|new
name|QSslSocket
decl_stmt|;
if|if
condition|(
name|serverSocket
operator|->
name|setSocketDescriptor
argument_list|(
name|socketDescriptor
argument_list|)
condition|)
block|{
name|connect
argument_list|(
name|serverSocket
argument_list|,
name|SIGNAL
argument_list|(
name|encrypted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|ready
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|serverSocket
operator|->
name|startServerEncryption
argument_list|()
expr_stmt|;
block|}
else|else
block|{
operator|delete
name|serverSocket
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|socket
name|QSslSocket
name|socket
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|socket
operator|.
name|connectToHostEncrypted
argument_list|(
literal|"http.example.com"
argument_list|,
literal|443
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|socket
operator|.
name|waitForEncrypted
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
name|socket
operator|.
name|errorString
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
end_if
begin_expr_stmt
name|socket
operator|.
name|write
argument_list|(
literal|"GET / HTTP/1.0\r\n\r\n"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_while
while|while
condition|(
name|socket
operator|.
name|waitForReadyRead
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
name|socket
operator|.
name|readAll
argument_list|()
operator|.
name|data
argument_list|()
expr_stmt|;
end_while
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
DECL|variable|socket
name|QSslSocket
name|socket
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|connect
argument_list|(
operator|&
name|socket
argument_list|,
name|SIGNAL
argument_list|(
name|encrypted
argument_list|()
argument_list|)
argument_list|,
name|receiver
argument_list|,
name|SLOT
argument_list|(
name|socketEncrypted
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|socket
operator|.
name|connectToHostEncrypted
argument_list|(
literal|"imap"
argument_list|,
literal|993
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|socket
operator|->
name|write
argument_list|(
literal|"1 CAPABILITY\r\n"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
DECL|variable|socket
name|QSslSocket
name|socket
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|socket
operator|.
name|setCiphers
argument_list|(
literal|"DHE-RSA-AES256-SHA:DHE-DSS-AES256-SHA:AES256-SHA"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_expr_stmt
name|socket
operator|->
name|connectToHostEncrypted
argument_list|(
literal|"imap"
argument_list|,
literal|993
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|socket
operator|->
name|waitForEncrypted
argument_list|(
literal|1000
argument_list|)
condition|)
name|qDebug
argument_list|(
literal|"Encrypted!"
argument_list|)
expr_stmt|;
end_if
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
DECL|variable|cert
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
name|cert
init|=
name|QSslCertificate
operator|::
name|fromPath
argument_list|(
name|QLatin1String
argument_list|(
literal|"server-certificate.pem"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSslError
name|error
argument_list|(
name|QSslError
operator|::
name|SelfSignedCertificate
argument_list|,
name|cert
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|expectedSslErrors
name|QList
argument_list|<
name|QSslError
argument_list|>
name|expectedSslErrors
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|expectedSslErrors
operator|.
name|append
argument_list|(
name|error
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|socket
name|QSslSocket
name|socket
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|socket
operator|.
name|ignoreSslErrors
argument_list|(
name|expectedSslErrors
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|socket
operator|.
name|connectToHostEncrypted
argument_list|(
literal|"server.tld"
argument_list|,
literal|443
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [6]
end_comment
end_unit
