begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_function
DECL|function|wrapInFunction
name|void
name|wrapInFunction
parameter_list|()
block|{
comment|//! [0]
name|QFile
name|file
argument_list|(
literal|"file.dat"
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|QDataStream
name|out
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
comment|// we will serialize the data into the file
name|out
operator|<<
name|QString
argument_list|(
literal|"the answer is"
argument_list|)
expr_stmt|;
comment|// serialize a string
name|out
operator|<<
operator|(
name|qint32
operator|)
literal|42
expr_stmt|;
comment|// serialize an integer
comment|//! [0]
comment|//! [1]
name|QFile
name|file
argument_list|(
literal|"file.dat"
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QDataStream
name|in
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
comment|// read the data serialized from the file
name|QString
name|str
decl_stmt|;
name|qint32
name|a
decl_stmt|;
name|in
operator|>>
name|str
operator|>>
name|a
expr_stmt|;
comment|// extract "the answer is" and 42
comment|//! [1]
comment|//! [2]
name|stream
operator|.
name|setVersion
argument_list|(
name|QDataStream
operator|::
name|Qt_4_0
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|QFile
name|file
argument_list|(
literal|"file.xxx"
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|QDataStream
name|out
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
comment|// Write a header with a "magic number" and a version
name|out
operator|<<
operator|(
name|quint32
operator|)
literal|0xA0B0C0D0
expr_stmt|;
name|out
operator|<<
operator|(
name|qint32
operator|)
literal|123
expr_stmt|;
name|out
operator|.
name|setVersion
argument_list|(
name|QDataStream
operator|::
name|Qt_4_0
argument_list|)
expr_stmt|;
comment|// Write the data
name|out
operator|<<
name|lots_of_interesting_data
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|QFile
name|file
argument_list|(
literal|"file.xxx"
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QDataStream
name|in
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
comment|// Read and check the header
name|quint32
name|magic
decl_stmt|;
name|in
operator|>>
name|magic
expr_stmt|;
if|if
condition|(
name|magic
operator|!=
literal|0xA0B0C0D0
condition|)
return|return
name|XXX_BAD_FILE_FORMAT
return|;
comment|// Read the version
name|qint32
name|version
decl_stmt|;
name|in
operator|>>
name|version
expr_stmt|;
if|if
condition|(
name|version
operator|<
literal|100
condition|)
return|return
name|XXX_BAD_FILE_TOO_OLD
return|;
if|if
condition|(
name|version
operator|>
literal|123
condition|)
return|return
name|XXX_BAD_FILE_TOO_NEW
return|;
if|if
condition|(
name|version
operator|<=
literal|110
condition|)
name|in
operator|.
name|setVersion
argument_list|(
name|QDataStream
operator|::
name|Qt_3_2
argument_list|)
expr_stmt|;
else|else
name|in
operator|.
name|setVersion
argument_list|(
name|QDataStream
operator|::
name|Qt_4_0
argument_list|)
expr_stmt|;
comment|// Read the data
name|in
operator|>>
name|lots_of_interesting_data
expr_stmt|;
if|if
condition|(
name|version
operator|>=
literal|120
condition|)
name|in
operator|>>
name|data_new_in_XXX_version_1_2
expr_stmt|;
name|in
operator|>>
name|other_interesting_data
expr_stmt|;
comment|//! [4]
comment|//! [5]
name|QDataStream
name|out
argument_list|(
name|file
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
comment|//! [5]
block|}
end_function
end_unit
