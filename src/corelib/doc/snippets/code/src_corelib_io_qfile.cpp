begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|file
name|QFile
name|file
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QDir
operator|::
name|setCurrent
argument_list|(
literal|"/tmp"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|file
operator|.
name|setFileName
argument_list|(
literal|"readme.txt"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDir
operator|::
name|setCurrent
argument_list|(
literal|"/home"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// opens "/home/readme.txt" under Unix
end_comment
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function_decl
name|QByteArray
name|myEncoderFunc
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function_decl
name|QString
name|myDecoderFunc
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|localFileName
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_function
DECL|function|printError
name|void
name|printError
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
name|QFile
name|file
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|stderr
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|file
operator|.
name|write
argument_list|(
name|msg
argument_list|,
name|qstrlen
argument_list|(
name|msg
argument_list|)
argument_list|)
expr_stmt|;
comment|// write to stderr
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_expr_stmt
name|CONFIG
operator|+=
name|console
end_expr_stmt
begin_comment
comment|//! [4]
end_comment
end_unit
