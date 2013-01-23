begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|q
name|QSqlQuery
name|q
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|q
operator|.
name|exec
argument_list|(
literal|"call qtestproc (@outval1, @outval2)"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|q
operator|.
name|exec
argument_list|(
literal|"select @outval1, @outval2"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|q
operator|.
name|next
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
name|q
operator|.
name|value
argument_list|(
literal|0
argument_list|)
operator|<<
name|q
operator|.
name|value
argument_list|(
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// outputs "42" and "43"
end_comment
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|// STORED_PROC uses the return statement or returns multiple result sets
end_comment
begin_decl_stmt
DECL|variable|query
name|QSqlQuery
name|query
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|query
operator|.
name|setForwardOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|query
operator|.
name|exec
argument_list|(
literal|"{call STORED_PROC}"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [24]
end_comment
begin_expr_stmt
name|db
operator|.
name|setHostName
argument_list|(
literal|"MyServer"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|db
operator|.
name|setDatabaseName
argument_list|(
literal|"C:\\test.gdb"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [24]
end_comment
begin_comment
comment|//! [25]
end_comment
begin_comment
comment|// connect to database using the Latin-1 character set
end_comment
begin_expr_stmt
name|db
operator|.
name|setConnectOptions
argument_list|(
literal|"ISC_DPB_LC_CTYPE=Latin1"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|db
operator|.
name|open
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [25]
end_comment
begin_comment
comment|//! [26]
end_comment
begin_decl_stmt
DECL|variable|q
name|QSqlQuery
name|q
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|q
operator|.
name|exec
argument_list|(
literal|"execute procedure my_procedure"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|q
operator|.
name|next
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
name|q
operator|.
name|value
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// outputs the first RETURN/OUT value
end_comment
begin_comment
comment|//! [26]
end_comment
begin_comment
comment|//! [31]
end_comment
begin_label
name|QSqlDatabase
label|:
end_label
begin_expr_stmt
name|QMYSQL
name|driver
operator|not
name|loaded
name|QSqlDatabase
operator|:
name|available
name|drivers
operator|:
name|QMYSQL
end_expr_stmt
begin_comment
comment|//! [31]
end_comment
end_unit
