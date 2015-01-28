begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [quoting modelview_a]
end_comment
begin_include
include|#
directive|include
file|<QTreeView>
end_include
begin_include
include|#
directive|include
file|<QStandardItemModel>
end_include
begin_include
include|#
directive|include
file|<QItemSelectionModel>
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QMainWindow
argument_list|(
name|parent
argument_list|)
block|{
name|treeView
operator|=
operator|new
name|QTreeView
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|treeView
argument_list|)
expr_stmt|;
name|standardModel
operator|=
operator|new
name|QStandardItemModel
expr_stmt|;
name|QStandardItem
modifier|*
name|rootNode
init|=
name|standardModel
operator|->
name|invisibleRootItem
argument_list|()
decl_stmt|;
comment|//defining a couple of items
name|QStandardItem
modifier|*
name|americaItem
init|=
operator|new
name|QStandardItem
argument_list|(
literal|"America"
argument_list|)
decl_stmt|;
name|QStandardItem
modifier|*
name|mexicoItem
init|=
operator|new
name|QStandardItem
argument_list|(
literal|"Canada"
argument_list|)
decl_stmt|;
name|QStandardItem
modifier|*
name|usaItem
init|=
operator|new
name|QStandardItem
argument_list|(
literal|"USA"
argument_list|)
decl_stmt|;
name|QStandardItem
modifier|*
name|bostonItem
init|=
operator|new
name|QStandardItem
argument_list|(
literal|"Boston"
argument_list|)
decl_stmt|;
name|QStandardItem
modifier|*
name|europeItem
init|=
operator|new
name|QStandardItem
argument_list|(
literal|"Europe"
argument_list|)
decl_stmt|;
name|QStandardItem
modifier|*
name|italyItem
init|=
operator|new
name|QStandardItem
argument_list|(
literal|"Italy"
argument_list|)
decl_stmt|;
name|QStandardItem
modifier|*
name|romeItem
init|=
operator|new
name|QStandardItem
argument_list|(
literal|"Rome"
argument_list|)
decl_stmt|;
name|QStandardItem
modifier|*
name|veronaItem
init|=
operator|new
name|QStandardItem
argument_list|(
literal|"Verona"
argument_list|)
decl_stmt|;
comment|//building up the hierarchy
name|rootNode
operator|->
name|appendRow
argument_list|(
name|americaItem
argument_list|)
expr_stmt|;
name|rootNode
operator|->
name|appendRow
argument_list|(
name|europeItem
argument_list|)
expr_stmt|;
name|americaItem
operator|->
name|appendRow
argument_list|(
name|mexicoItem
argument_list|)
expr_stmt|;
name|americaItem
operator|->
name|appendRow
argument_list|(
name|usaItem
argument_list|)
expr_stmt|;
name|usaItem
operator|->
name|appendRow
argument_list|(
name|bostonItem
argument_list|)
expr_stmt|;
name|europeItem
operator|->
name|appendRow
argument_list|(
name|italyItem
argument_list|)
expr_stmt|;
name|italyItem
operator|->
name|appendRow
argument_list|(
name|romeItem
argument_list|)
expr_stmt|;
name|italyItem
operator|->
name|appendRow
argument_list|(
name|veronaItem
argument_list|)
expr_stmt|;
comment|//register the model
name|treeView
operator|->
name|setModel
argument_list|(
name|standardModel
argument_list|)
expr_stmt|;
name|treeView
operator|->
name|expandAll
argument_list|()
expr_stmt|;
comment|//selection changes shall trigger a slot
name|QItemSelectionModel
modifier|*
name|selectionModel
init|=
name|treeView
operator|->
name|selectionModel
argument_list|()
decl_stmt|;
name|connect
argument_list|(
name|selectionModel
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|(
specifier|const
name|QItemSelection
operator|&
argument_list|,
specifier|const
name|QItemSelection
operator|&
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|selectionChangedSlot
argument_list|(
specifier|const
name|QItemSelection
operator|&
argument_list|,
specifier|const
name|QItemSelection
operator|&
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [quoting modelview_a]
end_comment
begin_comment
comment|//------------------------------------------------------------------------------------
end_comment
begin_comment
comment|//! [quoting modelview_b]
end_comment
begin_function
DECL|function|selectionChangedSlot
name|void
name|MainWindow
operator|::
name|selectionChangedSlot
parameter_list|(
specifier|const
name|QItemSelection
modifier|&
comment|/*newSelection*/
parameter_list|,
specifier|const
name|QItemSelection
modifier|&
comment|/*oldSelection*/
parameter_list|)
block|{
comment|//get the text of the selected item
specifier|const
name|QModelIndex
name|index
init|=
name|treeView
operator|->
name|selectionModel
argument_list|()
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|QString
name|selectedText
init|=
name|index
operator|.
name|data
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
comment|//find out the hierarchy level of the selected item
name|int
name|hierarchyLevel
init|=
literal|1
decl_stmt|;
name|QModelIndex
name|seekRoot
init|=
name|index
decl_stmt|;
while|while
condition|(
name|seekRoot
operator|.
name|parent
argument_list|()
operator|!=
name|QModelIndex
argument_list|()
condition|)
block|{
name|seekRoot
operator|=
name|seekRoot
operator|.
name|parent
argument_list|()
expr_stmt|;
name|hierarchyLevel
operator|++
expr_stmt|;
block|}
name|QString
name|showString
init|=
name|QString
argument_list|(
literal|"%1, Level %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|selectedText
argument_list|)
operator|.
name|arg
argument_list|(
name|hierarchyLevel
argument_list|)
decl_stmt|;
name|setWindowTitle
argument_list|(
name|showString
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [quoting modelview_b]
end_comment
end_unit
