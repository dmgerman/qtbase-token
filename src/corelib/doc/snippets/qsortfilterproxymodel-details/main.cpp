begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QSortFilterProxyModel>
end_include
begin_class
DECL|class|MyItemModel
class|class
name|MyItemModel
super|:
specifier|public
name|QStandardItemModel
block|{
public|public:
name|MyItemModel
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|MyItemModel
name|MyItemModel
operator|::
name|MyItemModel
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QStandardItemModel
argument_list|(
name|parent
argument_list|)
block|{}
end_constructor
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_class
DECL|class|Widget
class|class
name|Widget
super|:
specifier|public
name|QWidget
block|{
public|public:
name|Widget
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|Widget
name|Widget
operator|::
name|Widget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
comment|//! [0] //! [1]
name|QTreeView
modifier|*
name|treeView
init|=
operator|new
name|QTreeView
decl_stmt|;
comment|//! [0]
name|MyItemModel
modifier|*
name|model
init|=
operator|new
name|MyItemModel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|treeView
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|MyItemModel
modifier|*
name|sourceModel
init|=
operator|new
name|MyItemModel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QSortFilterProxyModel
modifier|*
name|proxyModel
init|=
operator|new
name|QSortFilterProxyModel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|proxyModel
operator|->
name|setSourceModel
argument_list|(
name|sourceModel
argument_list|)
expr_stmt|;
name|treeView
operator|->
name|setModel
argument_list|(
name|proxyModel
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|treeView
operator|->
name|setSortingEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|proxyModel
operator|->
name|sort
argument_list|(
literal|2
argument_list|,
name|Qt
operator|::
name|AscendingOrder
argument_list|)
expr_stmt|;
comment|//! [4] //! [5]
name|proxyModel
operator|->
name|setFilterRegExp
argument_list|(
name|QRegExp
argument_list|(
literal|".png"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|,
name|QRegExp
operator|::
name|FixedString
argument_list|)
argument_list|)
expr_stmt|;
name|proxyModel
operator|->
name|setFilterKeyColumn
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|//! [5]
block|}
end_constructor
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
name|Widget
name|widget
decl_stmt|;
name|widget
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
end_unit
