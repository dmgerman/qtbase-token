begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|QFile
name|data
argument_list|(
literal|"output.txt"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|data
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Truncate
argument_list|)
condition|)
block|{
name|QTextStream
name|out
argument_list|(
operator|&
name|data
argument_list|)
decl_stmt|;
name|out
operator|<<
literal|"Result: "
operator|<<
name|qSetFieldWidth
argument_list|(
literal|10
argument_list|)
operator|<<
name|left
operator|<<
literal|3.14
operator|<<
literal|2.7
expr_stmt|;
comment|// writes "Result: 3.14      2.7       "
block|}
end_if
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function_decl
name|QTextStream
name|stream
parameter_list|(
name|stdin
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|line
name|QString
name|line
decl_stmt|;
end_decl_stmt
begin_do
do|do
block|{
name|line
operator|=
name|stream
operator|.
name|readLine
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|line
operator|.
name|isNull
argument_list|()
condition|)
do|;
end_do
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|QTextStream
name|in
argument_list|(
literal|"0x50 0x20"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|firstNumber
DECL|variable|secondNumber
name|int
name|firstNumber
decl_stmt|,
name|secondNumber
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|firstNumber
name|in
operator|>>
name|firstNumber
expr_stmt|;
end_expr_stmt
begin_comment
DECL|variable|firstNumber
comment|// firstNumber == 80
end_comment
begin_expr_stmt
DECL|variable|secondNumber
name|in
operator|>>
name|dec
operator|>>
name|secondNumber
expr_stmt|;
end_expr_stmt
begin_comment
DECL|variable|secondNumber
comment|// secondNumber == 0
end_comment
begin_decl_stmt
DECL|variable|ch
name|char
name|ch
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|ch
name|in
operator|>>
name|ch
expr_stmt|;
end_expr_stmt
begin_comment
DECL|variable|ch
comment|// ch == 'x'
end_comment
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
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
comment|// read numeric arguments (123, 0x20, 4.5...)
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|argc
condition|;
operator|++
name|i
control|)
block|{
name|int
name|number
decl_stmt|;
name|QTextStream
name|in
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
decl_stmt|;
name|in
operator|>>
name|number
expr_stmt|;
operator|...
block|}
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
DECL|variable|str
name|QString
name|str
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QTextStream
name|in
parameter_list|(
name|stdin
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
DECL|variable|str
name|in
operator|>>
name|str
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
DECL|variable|s
name|QString
name|s
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|s
name|QTextStream
name|out
argument_list|(
operator|&
name|s
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|out
operator|.
name|setFieldWidth
argument_list|(
literal|10
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|out
operator|.
name|setFieldAlignment
argument_list|(
name|QTextStream
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|out
operator|.
name|setPadChar
argument_list|(
literal|'-'
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|out
operator|<<
literal|"Qt"
operator|<<
literal|"rocks!"
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_expr_stmt
operator|--
operator|--
name|Qt
operator|--
operator|--
operator|--
name|rocks
operator|!
operator|--
comment|//! [6]
comment|//! [7]
name|QTextStream
name|in
argument_list|(
name|file
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|ch1
DECL|variable|ch2
DECL|variable|ch3
name|QChar
name|ch1
decl_stmt|,
name|ch2
decl_stmt|,
name|ch3
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|ch3
name|in
operator|>>
name|ch1
operator|>>
name|ch2
operator|>>
name|ch3
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function_decl
name|QTextStream
name|out
parameter_list|(
name|stdout
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
DECL|variable|endl
name|out
operator|<<
literal|"Qt rocks!"
operator|<<
name|endl
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_expr_stmt
DECL|variable|flush
name|stream
operator|<<
literal|'\n'
operator|<<
name|flush
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
DECL|variable|file
name|QTextStream
name|out
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|out
operator|.
name|setCodec
argument_list|(
literal|"UTF-8"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [10]
end_comment
end_unit
