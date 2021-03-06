begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|QStandardItemModel
name|model
argument_list|(
literal|4
argument_list|,
literal|4
argument_list|)
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
literal|4
condition|;
operator|++
name|row
control|)
block|{
for|for
control|(
name|int
name|column
init|=
literal|0
init|;
name|column
operator|<
literal|4
condition|;
operator|++
name|column
control|)
block|{
name|QStandardItem
modifier|*
name|item
init|=
operator|new
name|QStandardItem
argument_list|(
name|QString
argument_list|(
literal|"row %0, column %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|row
argument_list|)
operator|.
name|arg
argument_list|(
name|column
argument_list|)
argument_list|)
decl_stmt|;
name|model
operator|.
name|setItem
argument_list|(
name|row
argument_list|,
name|column
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
block|}
end_for
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|model
name|QStandardItemModel
name|model
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|parentItem
name|QStandardItem
modifier|*
name|parentItem
init|=
name|model
operator|.
name|invisibleRootItem
argument_list|()
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
block|{
name|QStandardItem
modifier|*
name|item
init|=
operator|new
name|QStandardItem
argument_list|(
name|QString
argument_list|(
literal|"item %0"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|parentItem
operator|->
name|appendRow
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|parentItem
operator|=
name|item
expr_stmt|;
block|}
end_for
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|treeView
name|QTreeView
modifier|*
name|treeView
init|=
operator|new
name|QTreeView
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|treeView
operator|->
name|setModel
argument_list|(
name|myStandardItemModel
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|connect
argument_list|(
name|treeView
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|(
name|QModelIndex
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|clicked
argument_list|(
name|QModelIndex
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|clicked
name|void
name|MyWidget
operator|::
name|clicked
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
block|{
name|QStandardItem
modifier|*
name|item
init|=
name|myStandardItemModel
operator|->
name|itemFromIndex
argument_list|(
name|index
argument_list|)
decl_stmt|;
comment|// Do stuff with the item ...
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_expr_stmt
name|treeView
operator|->
name|scrollTo
argument_list|(
name|item
operator|->
name|index
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [4]
end_comment
end_unit
