begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"treemodel.h"
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
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QStringList
name|headers
decl_stmt|;
name|headers
operator|<<
name|tr
argument_list|(
literal|"Title"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Description"
argument_list|)
expr_stmt|;
name|QFile
name|file
argument_list|(
literal|":/default.txt"
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
name|TreeModel
modifier|*
name|model
init|=
operator|new
name|TreeModel
argument_list|(
name|headers
argument_list|,
name|file
operator|.
name|readAll
argument_list|()
argument_list|)
decl_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
name|view
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|column
init|=
literal|0
init|;
name|column
operator|<
name|model
operator|->
name|columnCount
argument_list|()
condition|;
operator|++
name|column
control|)
name|view
operator|->
name|resizeColumnToContents
argument_list|(
name|column
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|exitAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|view
operator|->
name|selectionModel
argument_list|()
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
name|updateActions
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|actionsMenu
argument_list|,
name|SIGNAL
argument_list|(
name|aboutToShow
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateActions
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|insertRowAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|insertRow
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|insertColumnAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|insertColumn
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|removeRowAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|removeRow
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|removeColumnAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|removeColumn
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|insertChildAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|insertChild
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|updateActions
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|insertChild
name|void
name|MainWindow
operator|::
name|insertChild
parameter_list|()
block|{
name|QModelIndex
name|index
init|=
name|view
operator|->
name|selectionModel
argument_list|()
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|QAbstractItemModel
modifier|*
name|model
init|=
name|view
operator|->
name|model
argument_list|()
decl_stmt|;
if|if
condition|(
name|model
operator|->
name|columnCount
argument_list|(
name|index
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|model
operator|->
name|insertColumn
argument_list|(
literal|0
argument_list|,
name|index
argument_list|)
condition|)
return|return;
block|}
if|if
condition|(
operator|!
name|model
operator|->
name|insertRow
argument_list|(
literal|0
argument_list|,
name|index
argument_list|)
condition|)
return|return;
for|for
control|(
name|int
name|column
init|=
literal|0
init|;
name|column
operator|<
name|model
operator|->
name|columnCount
argument_list|(
name|index
argument_list|)
condition|;
operator|++
name|column
control|)
block|{
name|QModelIndex
name|child
init|=
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
name|column
argument_list|,
name|index
argument_list|)
decl_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|child
argument_list|,
name|QVariant
argument_list|(
literal|"[No data]"
argument_list|)
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|model
operator|->
name|headerData
argument_list|(
name|column
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|)
operator|.
name|isValid
argument_list|()
condition|)
name|model
operator|->
name|setHeaderData
argument_list|(
name|column
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|QVariant
argument_list|(
literal|"[No header]"
argument_list|)
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
expr_stmt|;
block|}
name|view
operator|->
name|selectionModel
argument_list|()
operator|->
name|setCurrentIndex
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|index
argument_list|)
argument_list|,
name|QItemSelectionModel
operator|::
name|ClearAndSelect
argument_list|)
expr_stmt|;
name|updateActions
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertColumn
name|bool
name|MainWindow
operator|::
name|insertColumn
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
block|{
name|QAbstractItemModel
modifier|*
name|model
init|=
name|view
operator|->
name|model
argument_list|()
decl_stmt|;
name|int
name|column
init|=
name|view
operator|->
name|selectionModel
argument_list|()
operator|->
name|currentIndex
argument_list|()
operator|.
name|column
argument_list|()
decl_stmt|;
comment|// Insert a column in the parent item.
name|bool
name|changed
init|=
name|model
operator|->
name|insertColumn
argument_list|(
name|column
operator|+
literal|1
argument_list|,
name|parent
argument_list|)
decl_stmt|;
if|if
condition|(
name|changed
condition|)
name|model
operator|->
name|setHeaderData
argument_list|(
name|column
operator|+
literal|1
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|QVariant
argument_list|(
literal|"[No header]"
argument_list|)
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
expr_stmt|;
name|updateActions
argument_list|()
expr_stmt|;
return|return
name|changed
return|;
block|}
end_function
begin_function
DECL|function|insertRow
name|void
name|MainWindow
operator|::
name|insertRow
parameter_list|()
block|{
name|QModelIndex
name|index
init|=
name|view
operator|->
name|selectionModel
argument_list|()
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|QAbstractItemModel
modifier|*
name|model
init|=
name|view
operator|->
name|model
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|model
operator|->
name|insertRow
argument_list|(
name|index
operator|.
name|row
argument_list|()
operator|+
literal|1
argument_list|,
name|index
operator|.
name|parent
argument_list|()
argument_list|)
condition|)
return|return;
name|updateActions
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|column
init|=
literal|0
init|;
name|column
operator|<
name|model
operator|->
name|columnCount
argument_list|(
name|index
operator|.
name|parent
argument_list|()
argument_list|)
condition|;
operator|++
name|column
control|)
block|{
name|QModelIndex
name|child
init|=
name|model
operator|->
name|index
argument_list|(
name|index
operator|.
name|row
argument_list|()
operator|+
literal|1
argument_list|,
name|column
argument_list|,
name|index
operator|.
name|parent
argument_list|()
argument_list|)
decl_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|child
argument_list|,
name|QVariant
argument_list|(
literal|"[No data]"
argument_list|)
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|removeColumn
name|bool
name|MainWindow
operator|::
name|removeColumn
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
block|{
name|QAbstractItemModel
modifier|*
name|model
init|=
name|view
operator|->
name|model
argument_list|()
decl_stmt|;
name|int
name|column
init|=
name|view
operator|->
name|selectionModel
argument_list|()
operator|->
name|currentIndex
argument_list|()
operator|.
name|column
argument_list|()
decl_stmt|;
comment|// Insert columns in each child of the parent item.
name|bool
name|changed
init|=
name|model
operator|->
name|removeColumn
argument_list|(
name|column
argument_list|,
name|parent
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|parent
operator|.
name|isValid
argument_list|()
operator|&&
name|changed
condition|)
name|updateActions
argument_list|()
expr_stmt|;
return|return
name|changed
return|;
block|}
end_function
begin_function
DECL|function|removeRow
name|void
name|MainWindow
operator|::
name|removeRow
parameter_list|()
block|{
name|QModelIndex
name|index
init|=
name|view
operator|->
name|selectionModel
argument_list|()
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|QAbstractItemModel
modifier|*
name|model
init|=
name|view
operator|->
name|model
argument_list|()
decl_stmt|;
if|if
condition|(
name|model
operator|->
name|removeRow
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|,
name|index
operator|.
name|parent
argument_list|()
argument_list|)
condition|)
name|updateActions
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateActions
name|void
name|MainWindow
operator|::
name|updateActions
parameter_list|()
block|{
name|bool
name|hasSelection
init|=
operator|!
name|view
operator|->
name|selectionModel
argument_list|()
operator|->
name|selection
argument_list|()
operator|.
name|isEmpty
argument_list|()
decl_stmt|;
name|removeRowAction
operator|->
name|setEnabled
argument_list|(
name|hasSelection
argument_list|)
expr_stmt|;
name|removeColumnAction
operator|->
name|setEnabled
argument_list|(
name|hasSelection
argument_list|)
expr_stmt|;
name|bool
name|hasCurrent
init|=
name|view
operator|->
name|selectionModel
argument_list|()
operator|->
name|currentIndex
argument_list|()
operator|.
name|isValid
argument_list|()
decl_stmt|;
name|insertRowAction
operator|->
name|setEnabled
argument_list|(
name|hasCurrent
argument_list|)
expr_stmt|;
name|insertColumnAction
operator|->
name|setEnabled
argument_list|(
name|hasCurrent
argument_list|)
expr_stmt|;
if|if
condition|(
name|hasCurrent
condition|)
block|{
name|view
operator|->
name|closePersistentEditor
argument_list|(
name|view
operator|->
name|selectionModel
argument_list|()
operator|->
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|row
init|=
name|view
operator|->
name|selectionModel
argument_list|()
operator|->
name|currentIndex
argument_list|()
operator|.
name|row
argument_list|()
decl_stmt|;
name|int
name|column
init|=
name|view
operator|->
name|selectionModel
argument_list|()
operator|->
name|currentIndex
argument_list|()
operator|.
name|column
argument_list|()
decl_stmt|;
if|if
condition|(
name|view
operator|->
name|selectionModel
argument_list|()
operator|->
name|currentIndex
argument_list|()
operator|.
name|parent
argument_list|()
operator|.
name|isValid
argument_list|()
condition|)
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"Position: (%1,%2)"
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
expr_stmt|;
else|else
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"Position: (%1,%2) in top level"
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
expr_stmt|;
block|}
block|}
end_function
end_unit
