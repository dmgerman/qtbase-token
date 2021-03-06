begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Ruslan Nigmatullin<euroelessar@yandex.ru> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
comment|//! [0]
name|QByteArray
name|key
init|=
literal|"key"
decl_stmt|;
name|QByteArray
name|message
init|=
literal|"The quick brown fox jumps over the lazy dog"
decl_stmt|;
comment|//! [0]
comment|//! [1]
name|QMessageAuthenticationCode
name|code
argument_list|(
name|QCryptographicHash
operator|::
name|Sha1
argument_list|)
decl_stmt|;
name|code
operator|.
name|setKey
argument_list|(
name|key
argument_list|)
expr_stmt|;
name|code
operator|.
name|addData
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|code
operator|.
name|result
argument_list|()
operator|.
name|toHex
argument_list|()
expr_stmt|;
comment|// returns "de7c9b85b8b78aa6bc8a7a36f70a90701c9db4d9"
comment|//! [1]
comment|//! [2]
name|QMessageAuthenticationCode
operator|::
name|hash
argument_list|(
name|message
argument_list|,
name|key
argument_list|,
name|QCryptographicHash
operator|::
name|Sha1
argument_list|)
operator|.
name|toHex
argument_list|()
expr_stmt|;
comment|//! [2]
block|}
end_function
end_unit
