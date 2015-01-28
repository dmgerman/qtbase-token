begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_class
DECL|class|ZipEngineHandler
class|class
name|ZipEngineHandler
super|:
specifier|public
name|QAbstractFileEngineHandler
block|{
public|public:
name|QAbstractFileEngine
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|create
name|QAbstractFileEngine
modifier|*
name|ZipEngineHandler
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
specifier|const
block|{
comment|// ZipEngineHandler returns a ZipEngine for all .zip files
return|return
name|fileName
operator|.
name|toLower
argument_list|()
operator|.
name|endsWith
argument_list|(
literal|".zip"
argument_list|)
condition|?
operator|new
name|ZipEngine
argument_list|(
name|fileName
argument_list|)
else|:
literal|0
return|;
block|}
end_function
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
modifier|*
name|argv
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|ZipEngineHandler
name|engine
decl_stmt|;
name|MainWindow
name|window
decl_stmt|;
name|window
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|create
name|QAbstractSocketEngine
modifier|*
name|ZipEngineHandler
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
specifier|const
block|{
comment|// ZipEngineHandler returns a ZipEngine for all .zip files
return|return
name|fileName
operator|.
name|toLower
argument_list|()
operator|.
name|endsWith
argument_list|(
literal|".zip"
argument_list|)
condition|?
operator|new
name|ZipEngine
argument_list|(
name|fileName
argument_list|)
else|:
literal|0
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
name|QAbstractFileEngineIterator
modifier|*
DECL|function|beginEntryList
name|CustomFileEngine
operator|::
name|beginEntryList
parameter_list|(
name|QDir
operator|::
name|Filters
name|filters
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|filterNames
parameter_list|)
block|{
return|return
operator|new
name|CustomFileEngineIterator
argument_list|(
name|filters
argument_list|,
name|filterNames
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_class
DECL|class|CustomIterator
class|class
name|CustomIterator
super|:
specifier|public
name|QAbstractFileEngineIterator
block|{
public|public:
DECL|function|CustomIterator
name|CustomIterator
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|nameFilters
parameter_list|,
name|QDir
operator|::
name|Filters
name|filters
parameter_list|)
member_init_list|:
name|QAbstractFileEngineIterator
argument_list|(
name|nameFilters
argument_list|,
name|filters
argument_list|)
member_init_list|,
name|index
argument_list|(
literal|0
argument_list|)
block|{
comment|// In a real iterator, these entries are fetched from the
comment|// file system based on the value of path().
name|entries
operator|<<
literal|"entry1"
operator|<<
literal|"entry2"
operator|<<
literal|"entry3"
expr_stmt|;
block|}
DECL|function|hasNext
name|bool
name|hasNext
parameter_list|()
specifier|const
block|{
return|return
name|index
operator|<
name|entries
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
DECL|function|next
name|QString
name|next
parameter_list|()
block|{
if|if
condition|(
operator|!
name|hasNext
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
operator|++
name|index
expr_stmt|;
return|return
name|currentFilePath
argument_list|()
return|;
block|}
DECL|function|currentFileName
name|QString
name|currentFileName
parameter_list|()
block|{
return|return
name|entries
operator|.
name|at
argument_list|(
name|index
argument_list|)
return|;
block|}
private|private:
DECL|member|entries
name|QStringList
name|entries
decl_stmt|;
DECL|member|index
name|int
name|index
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [3]
end_comment
end_unit
