begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<iostream>
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
name|QDir
name|dir
decl_stmt|;
name|dir
operator|.
name|setFilter
argument_list|(
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|Hidden
operator||
name|QDir
operator|::
name|NoSymLinks
argument_list|)
expr_stmt|;
name|dir
operator|.
name|setSorting
argument_list|(
name|QDir
operator|::
name|Size
operator||
name|QDir
operator|::
name|Reversed
argument_list|)
expr_stmt|;
comment|//! [0]
name|QStringList
name|filters
decl_stmt|;
name|filters
operator|<<
literal|"*.cpp"
operator|<<
literal|"*.cxx"
operator|<<
literal|"*.cc"
expr_stmt|;
name|dir
operator|.
name|setNameFilters
argument_list|(
name|filters
argument_list|)
expr_stmt|;
comment|//! [0]
name|QFileInfoList
name|list
init|=
name|dir
operator|.
name|entryInfoList
argument_list|()
decl_stmt|;
name|std
operator|::
name|cout
operator|<<
literal|"     Bytes Filename"
operator|<<
name|std
operator|::
name|endl
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QFileInfo
name|fileInfo
init|=
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|std
operator|::
name|cout
operator|<<
name|qPrintable
argument_list|(
name|QString
argument_list|(
literal|"%1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileInfo
operator|.
name|size
argument_list|()
argument_list|,
literal|10
argument_list|)
operator|.
name|arg
argument_list|(
name|fileInfo
operator|.
name|fileName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|std
operator|::
name|cout
operator|<<
name|std
operator|::
name|endl
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
end_unit
