begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|foo
name|QString
name|foo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|type
name|QString
name|type
init|=
literal|"long"
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|foo
operator|->
name|setText
argument_list|(
name|QLatin1String
argument_list|(
literal|"vector<"
argument_list|)
operator|+
name|type
operator|+
name|QLatin1String
argument_list|(
literal|">::iterator"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|foo
operator|.
name|startsWith
argument_list|(
literal|"("
operator|+
name|type
operator|+
literal|") 0x"
argument_list|)
condition|)
operator|...
comment|//! [0]
comment|//! [3]
name|DEFINES
operator|*=
name|QT_USE_QSTRINGBUILDER
comment|//! [3]
comment|//! [5]
include|#
directive|include
file|<QStringBuilder>
name|QString
name|hello
argument_list|(
literal|"hello"
argument_list|)
expr_stmt|;
end_if
begin_decl_stmt
DECL|variable|el
name|QStringRef
name|el
argument_list|(
operator|&
name|hello
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|world
argument_list|(
literal|"world"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|message
name|QString
name|message
init|=
name|hello
operator|%
name|el
operator|%
name|world
operator|%
name|QChar
argument_list|(
literal|'!'
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [5]
end_comment
end_unit
