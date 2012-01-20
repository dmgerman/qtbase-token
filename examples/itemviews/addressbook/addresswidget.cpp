begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"addresswidget.h"
end_include
begin_include
include|#
directive|include
file|"adddialog.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|AddressWidget
name|AddressWidget
operator|::
name|AddressWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QTabWidget
argument_list|(
name|parent
argument_list|)
block|{
name|table
operator|=
operator|new
name|TableModel
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|newAddressTab
operator|=
operator|new
name|NewAddressTab
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|newAddressTab
argument_list|,
name|SIGNAL
argument_list|(
name|sendDetails
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|addEntry
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|addTab
argument_list|(
name|newAddressTab
argument_list|,
literal|"Address Book"
argument_list|)
expr_stmt|;
name|setupTabs
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|addEntry
name|void
name|AddressWidget
operator|::
name|addEntry
parameter_list|()
block|{
name|AddDialog
name|aDialog
decl_stmt|;
if|if
condition|(
name|aDialog
operator|.
name|exec
argument_list|()
condition|)
block|{
name|QString
name|name
init|=
name|aDialog
operator|.
name|nameText
operator|->
name|text
argument_list|()
decl_stmt|;
name|QString
name|address
init|=
name|aDialog
operator|.
name|addressText
operator|->
name|toPlainText
argument_list|()
decl_stmt|;
name|addEntry
argument_list|(
name|name
argument_list|,
name|address
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|addEntry
name|void
name|AddressWidget
operator|::
name|addEntry
parameter_list|(
name|QString
name|name
parameter_list|,
name|QString
name|address
parameter_list|)
block|{
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
argument_list|>
name|list
init|=
name|table
operator|->
name|getList
argument_list|()
decl_stmt|;
name|QPair
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|pair
argument_list|(
name|name
argument_list|,
name|address
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|pair
argument_list|)
condition|)
block|{
name|table
operator|->
name|insertRows
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
name|QModelIndex
name|index
init|=
name|table
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
decl_stmt|;
name|table
operator|->
name|setData
argument_list|(
name|index
argument_list|,
name|name
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
expr_stmt|;
name|index
operator|=
name|table
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
name|table
operator|->
name|setData
argument_list|(
name|index
argument_list|,
name|address
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
expr_stmt|;
name|removeTab
argument_list|(
name|indexOf
argument_list|(
name|newAddressTab
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Duplicate Name"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The name \"%1\" already exists."
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4a]
end_comment
begin_function
DECL|function|editEntry
name|void
name|AddressWidget
operator|::
name|editEntry
parameter_list|()
block|{
name|QTableView
modifier|*
name|temp
init|=
cast|static_cast
argument_list|<
name|QTableView
operator|*
argument_list|>
argument_list|(
name|currentWidget
argument_list|()
argument_list|)
decl_stmt|;
name|QSortFilterProxyModel
modifier|*
name|proxy
init|=
cast|static_cast
argument_list|<
name|QSortFilterProxyModel
operator|*
argument_list|>
argument_list|(
name|temp
operator|->
name|model
argument_list|()
argument_list|)
decl_stmt|;
name|QItemSelectionModel
modifier|*
name|selectionModel
init|=
name|temp
operator|->
name|selectionModel
argument_list|()
decl_stmt|;
name|QModelIndexList
name|indexes
init|=
name|selectionModel
operator|->
name|selectedRows
argument_list|()
decl_stmt|;
name|QModelIndex
name|index
decl_stmt|,
name|i
decl_stmt|;
name|QString
name|name
decl_stmt|;
name|QString
name|address
decl_stmt|;
name|int
name|row
init|=
operator|-
literal|1
decl_stmt|;
foreach|foreach
control|(
name|index
init|,
name|indexes
control|)
block|{
name|row
operator|=
name|proxy
operator|->
name|mapToSource
argument_list|(
name|index
argument_list|)
operator|.
name|row
argument_list|()
expr_stmt|;
name|i
operator|=
name|table
operator|->
name|index
argument_list|(
name|row
argument_list|,
literal|0
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
name|QVariant
name|varName
init|=
name|table
operator|->
name|data
argument_list|(
name|i
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
decl_stmt|;
name|name
operator|=
name|varName
operator|.
name|toString
argument_list|()
expr_stmt|;
name|i
operator|=
name|table
operator|->
name|index
argument_list|(
name|row
argument_list|,
literal|1
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
name|QVariant
name|varAddr
init|=
name|table
operator|->
name|data
argument_list|(
name|i
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
decl_stmt|;
name|address
operator|=
name|varAddr
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
comment|//! [4a]
comment|//! [4b]
name|AddDialog
name|aDialog
decl_stmt|;
name|aDialog
operator|.
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Edit a Contact"
argument_list|)
argument_list|)
expr_stmt|;
name|aDialog
operator|.
name|nameText
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|aDialog
operator|.
name|nameText
operator|->
name|setText
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|aDialog
operator|.
name|addressText
operator|->
name|setText
argument_list|(
name|address
argument_list|)
expr_stmt|;
if|if
condition|(
name|aDialog
operator|.
name|exec
argument_list|()
condition|)
block|{
name|QString
name|newAddress
init|=
name|aDialog
operator|.
name|addressText
operator|->
name|toPlainText
argument_list|()
decl_stmt|;
if|if
condition|(
name|newAddress
operator|!=
name|address
condition|)
block|{
name|i
operator|=
name|table
operator|->
name|index
argument_list|(
name|row
argument_list|,
literal|1
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
name|table
operator|->
name|setData
argument_list|(
name|i
argument_list|,
name|newAddress
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|//! [4b]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|removeEntry
name|void
name|AddressWidget
operator|::
name|removeEntry
parameter_list|()
block|{
name|QTableView
modifier|*
name|temp
init|=
cast|static_cast
argument_list|<
name|QTableView
operator|*
argument_list|>
argument_list|(
name|currentWidget
argument_list|()
argument_list|)
decl_stmt|;
name|QSortFilterProxyModel
modifier|*
name|proxy
init|=
cast|static_cast
argument_list|<
name|QSortFilterProxyModel
operator|*
argument_list|>
argument_list|(
name|temp
operator|->
name|model
argument_list|()
argument_list|)
decl_stmt|;
name|QItemSelectionModel
modifier|*
name|selectionModel
init|=
name|temp
operator|->
name|selectionModel
argument_list|()
decl_stmt|;
name|QModelIndexList
name|indexes
init|=
name|selectionModel
operator|->
name|selectedRows
argument_list|()
decl_stmt|;
name|QModelIndex
name|index
decl_stmt|;
foreach|foreach
control|(
name|index
init|,
name|indexes
control|)
block|{
name|int
name|row
init|=
name|proxy
operator|->
name|mapToSource
argument_list|(
name|index
argument_list|)
operator|.
name|row
argument_list|()
decl_stmt|;
name|table
operator|->
name|removeRows
argument_list|(
name|row
argument_list|,
literal|1
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|table
operator|->
name|rowCount
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
operator|==
literal|0
condition|)
block|{
name|insertTab
argument_list|(
literal|0
argument_list|,
name|newAddressTab
argument_list|,
literal|"Address Book"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|setupTabs
name|void
name|AddressWidget
operator|::
name|setupTabs
parameter_list|()
block|{
name|QStringList
name|groups
decl_stmt|;
name|groups
operator|<<
literal|"ABC"
operator|<<
literal|"DEF"
operator|<<
literal|"GHI"
operator|<<
literal|"JKL"
operator|<<
literal|"MNO"
operator|<<
literal|"PQR"
operator|<<
literal|"STU"
operator|<<
literal|"VW"
operator|<<
literal|"XYZ"
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
name|groups
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|str
init|=
name|groups
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|proxyModel
operator|=
operator|new
name|QSortFilterProxyModel
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|proxyModel
operator|->
name|setSourceModel
argument_list|(
name|table
argument_list|)
expr_stmt|;
name|QTableView
modifier|*
name|tableView
init|=
operator|new
name|QTableView
decl_stmt|;
name|tableView
operator|->
name|setModel
argument_list|(
name|proxyModel
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|setSortingEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|setSelectionBehavior
argument_list|(
name|QAbstractItemView
operator|::
name|SelectRows
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setStretchLastSection
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|verticalHeader
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
name|tableView
operator|->
name|setEditTriggers
argument_list|(
name|QAbstractItemView
operator|::
name|NoEditTriggers
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|setSelectionMode
argument_list|(
name|QAbstractItemView
operator|::
name|SingleSelection
argument_list|)
expr_stmt|;
name|QString
name|newStr
init|=
name|QString
argument_list|(
literal|"^[%1].*"
argument_list|)
operator|.
name|arg
argument_list|(
name|str
argument_list|)
decl_stmt|;
name|proxyModel
operator|->
name|setFilterRegExp
argument_list|(
name|QRegExp
argument_list|(
name|newStr
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
argument_list|)
expr_stmt|;
name|proxyModel
operator|->
name|setFilterKeyColumn
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|proxyModel
operator|->
name|sort
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|AscendingOrder
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|tableView
operator|->
name|selectionModel
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|(
name|QItemSelection
argument_list|,
name|QItemSelection
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|(
name|QItemSelection
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|addTab
argument_list|(
name|tableView
argument_list|,
name|str
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|readFromFile
name|void
name|AddressWidget
operator|::
name|readFromFile
parameter_list|(
name|QString
name|fileName
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Unable to open file"
argument_list|)
argument_list|,
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
argument_list|>
name|pairs
init|=
name|table
operator|->
name|getList
argument_list|()
decl_stmt|;
name|QDataStream
name|in
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|in
operator|>>
name|pairs
expr_stmt|;
if|if
condition|(
name|pairs
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"No contacts in file"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The file you are attempting to open contains no contacts."
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|pairs
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QPair
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|p
init|=
name|pairs
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|addEntry
argument_list|(
name|p
operator|.
name|first
argument_list|,
name|p
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|writeToFile
name|void
name|AddressWidget
operator|::
name|writeToFile
parameter_list|(
name|QString
name|fileName
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Unable to open file"
argument_list|)
argument_list|,
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
argument_list|>
name|pairs
init|=
name|table
operator|->
name|getList
argument_list|()
decl_stmt|;
name|QDataStream
name|out
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|out
operator|<<
name|pairs
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
end_unit
