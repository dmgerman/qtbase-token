begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_function
DECL|function|processSize
name|void
name|processSize
parameter_list|(
name|int
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
name|QWidget
modifier|*
name|parent
init|=
literal|0
decl_stmt|;
comment|//! [0]
name|QSplitter
modifier|*
name|splitter
init|=
operator|new
name|QSplitter
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|QListView
modifier|*
name|listview
init|=
operator|new
name|QListView
decl_stmt|;
name|QTreeView
modifier|*
name|treeview
init|=
operator|new
name|QTreeView
decl_stmt|;
name|QTextEdit
modifier|*
name|textedit
init|=
operator|new
name|QTextEdit
decl_stmt|;
name|splitter
operator|->
name|addWidget
argument_list|(
name|listview
argument_list|)
expr_stmt|;
name|splitter
operator|->
name|addWidget
argument_list|(
name|treeview
argument_list|)
expr_stmt|;
name|splitter
operator|->
name|addWidget
argument_list|(
name|textedit
argument_list|)
expr_stmt|;
comment|//! [0]
block|{
comment|// SAVE STATE
comment|//! [1]
name|QSettings
name|settings
decl_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"splitterSizes"
argument_list|,
name|splitter
operator|->
name|saveState
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [1]
block|}
block|{
comment|// RESTORE STATE
comment|//! [2]
name|QSettings
name|settings
decl_stmt|;
name|splitter
operator|->
name|restoreState
argument_list|(
name|settings
operator|.
name|value
argument_list|(
literal|"splitterSizes"
argument_list|)
operator|.
name|toByteArray
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [2]
block|}
comment|//! [3]
name|QListIterator
argument_list|<
name|int
argument_list|>
name|it
argument_list|(
name|splitter
operator|->
name|sizes
argument_list|()
argument_list|)
decl_stmt|;
while|while
condition|(
name|it
operator|.
name|hasNext
argument_list|()
condition|)
name|processSize
argument_list|(
name|it
operator|.
name|next
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [3]
return|return
literal|0
return|;
block|}
end_function
end_unit
