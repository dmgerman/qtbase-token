begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QTextStream>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QTime>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<qtconcurrentmap.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_using
using|using
namespace|namespace
name|QtConcurrent
namespace|;
end_using
begin_comment
comment|/*     Utility function that recursivily searches for files. */
end_comment
begin_function
DECL|function|findFiles
name|QStringList
name|findFiles
parameter_list|(
specifier|const
name|QString
modifier|&
name|startDir
parameter_list|,
name|QStringList
name|filters
parameter_list|)
block|{
name|QStringList
name|names
decl_stmt|;
name|QDir
name|dir
argument_list|(
name|startDir
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|QString
name|file
decl|,
name|dir
operator|.
name|entryList
argument_list|(
name|filters
argument_list|,
name|QDir
operator|::
name|Files
argument_list|)
control|)
name|names
operator|+=
name|startDir
operator|+
literal|"/"
operator|+
name|file
expr_stmt|;
foreach|foreach
control|(
name|QString
name|subdir
decl|,
name|dir
operator|.
name|entryList
argument_list|(
name|QDir
operator|::
name|AllDirs
operator||
name|QDir
operator|::
name|NoDotAndDotDot
argument_list|)
control|)
name|names
operator|+=
name|findFiles
argument_list|(
name|startDir
operator|+
literal|"/"
operator|+
name|subdir
argument_list|,
name|filters
argument_list|)
expr_stmt|;
return|return
name|names
return|;
block|}
end_function
begin_typedef
DECL|typedef|WordCount
typedef|typedef
name|QMap
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|WordCount
typedef|;
end_typedef
begin_comment
comment|/*     Single threaded word counter function. */
end_comment
begin_function
DECL|function|singleThreadedWordCount
name|WordCount
name|singleThreadedWordCount
parameter_list|(
name|QStringList
name|files
parameter_list|)
block|{
name|WordCount
name|wordCount
decl_stmt|;
foreach|foreach
control|(
name|QString
name|file
decl|,
name|files
control|)
block|{
name|QFile
name|f
argument_list|(
name|file
argument_list|)
decl_stmt|;
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QTextStream
name|textStream
argument_list|(
operator|&
name|f
argument_list|)
decl_stmt|;
while|while
condition|(
name|textStream
operator|.
name|atEnd
argument_list|()
operator|==
literal|false
condition|)
foreach|foreach
control|(
name|QString
name|word
decl|,
name|textStream
operator|.
name|readLine
argument_list|()
operator|.
name|split
argument_list|(
literal|" "
argument_list|)
control|)
name|wordCount
index|[
name|word
index|]
operator|+=
literal|1
expr_stmt|;
block|}
return|return
name|wordCount
return|;
block|}
end_function
begin_comment
comment|// countWords counts the words in a single file. This function is
end_comment
begin_comment
comment|// called in parallel by several threads and must be thread
end_comment
begin_comment
comment|// safe.
end_comment
begin_function
DECL|function|countWords
name|WordCount
name|countWords
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
block|{
name|QFile
name|f
argument_list|(
name|file
argument_list|)
decl_stmt|;
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QTextStream
name|textStream
argument_list|(
operator|&
name|f
argument_list|)
decl_stmt|;
name|WordCount
name|wordCount
decl_stmt|;
while|while
condition|(
name|textStream
operator|.
name|atEnd
argument_list|()
operator|==
literal|false
condition|)
foreach|foreach
control|(
name|QString
name|word
decl|,
name|textStream
operator|.
name|readLine
argument_list|()
operator|.
name|split
argument_list|(
literal|" "
argument_list|)
control|)
name|wordCount
index|[
name|word
index|]
operator|+=
literal|1
expr_stmt|;
return|return
name|wordCount
return|;
block|}
end_function
begin_comment
comment|// reduce adds the results from map to the final
end_comment
begin_comment
comment|// result. This functor will only be called by one thread
end_comment
begin_comment
comment|// at a time.
end_comment
begin_function
DECL|function|reduce
name|void
name|reduce
parameter_list|(
name|WordCount
modifier|&
name|result
parameter_list|,
specifier|const
name|WordCount
modifier|&
name|w
parameter_list|)
block|{
name|QMapIterator
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|i
argument_list|(
name|w
argument_list|)
decl_stmt|;
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|i
operator|.
name|next
argument_list|()
expr_stmt|;
name|result
index|[
name|i
operator|.
name|key
argument_list|()
index|]
operator|+=
name|i
operator|.
name|value
argument_list|()
expr_stmt|;
block|}
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
name|qDebug
argument_list|()
operator|<<
literal|"finding files..."
expr_stmt|;
name|QStringList
name|files
init|=
name|findFiles
argument_list|(
literal|"../../"
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"*.cpp"
operator|<<
literal|"*.h"
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|files
operator|.
name|count
argument_list|()
operator|<<
literal|"files"
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"warmup"
expr_stmt|;
block|{
name|QTime
name|time
decl_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|WordCount
name|total
init|=
name|singleThreadedWordCount
argument_list|(
name|files
argument_list|)
decl_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
literal|"warmup done"
expr_stmt|;
name|int
name|singleThreadTime
init|=
literal|0
decl_stmt|;
block|{
name|QTime
name|time
decl_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|WordCount
name|total
init|=
name|singleThreadedWordCount
argument_list|(
name|files
argument_list|)
decl_stmt|;
name|singleThreadTime
operator|=
name|time
operator|.
name|elapsed
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"single thread"
operator|<<
name|singleThreadTime
expr_stmt|;
block|}
name|int
name|mapReduceTime
init|=
literal|0
decl_stmt|;
block|{
name|QTime
name|time
decl_stmt|;
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|WordCount
name|total
init|=
name|mappedReduced
argument_list|(
name|files
argument_list|,
name|countWords
argument_list|,
name|reduce
argument_list|)
decl_stmt|;
name|mapReduceTime
operator|=
name|time
operator|.
name|elapsed
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"MapReduce"
operator|<<
name|mapReduceTime
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
literal|"MapReduce speedup x"
operator|<<
operator|(
operator|(
name|double
operator|)
name|singleThreadTime
operator|-
operator|(
name|double
operator|)
name|mapReduceTime
operator|)
operator|/
operator|(
name|double
operator|)
name|mapReduceTime
operator|+
literal|1
expr_stmt|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<QLabel>
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
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QString
name|text
argument_list|(
literal|"Qt Concurrent is not yet supported on this platform"
argument_list|)
decl_stmt|;
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|label
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|label
operator|->
name|show
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
name|text
expr_stmt|;
name|app
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
end_unit
