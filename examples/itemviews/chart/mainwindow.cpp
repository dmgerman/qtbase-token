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
file|"pieview.h"
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
parameter_list|()
block|{
name|QMenu
modifier|*
name|fileMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|openAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Open..."
argument_list|)
argument_list|)
decl_stmt|;
name|openAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Open
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|saveAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Save As..."
argument_list|)
argument_list|)
decl_stmt|;
name|saveAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|SaveAs
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|quitAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|)
decl_stmt|;
name|quitAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
expr_stmt|;
name|setupModel
argument_list|()
expr_stmt|;
name|setupViews
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|openAction
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
name|openFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveAction
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
name|saveFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitAction
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
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|fileMenu
argument_list|)
expr_stmt|;
name|statusBar
argument_list|()
expr_stmt|;
name|openFile
argument_list|(
literal|":/Charts/qtdata.cht"
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Chart"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|870
argument_list|,
literal|550
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setupModel
name|void
name|MainWindow
operator|::
name|setupModel
parameter_list|()
block|{
name|model
operator|=
operator|new
name|QStandardItemModel
argument_list|(
literal|8
argument_list|,
literal|2
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|model
operator|->
name|setHeaderData
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|tr
argument_list|(
literal|"Label"
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setHeaderData
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|tr
argument_list|(
literal|"Quantity"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupViews
name|void
name|MainWindow
operator|::
name|setupViews
parameter_list|()
block|{
name|QSplitter
modifier|*
name|splitter
init|=
operator|new
name|QSplitter
decl_stmt|;
name|QTableView
modifier|*
name|table
init|=
operator|new
name|QTableView
decl_stmt|;
name|pieChart
operator|=
operator|new
name|PieView
expr_stmt|;
name|splitter
operator|->
name|addWidget
argument_list|(
name|table
argument_list|)
expr_stmt|;
name|splitter
operator|->
name|addWidget
argument_list|(
name|pieChart
argument_list|)
expr_stmt|;
name|splitter
operator|->
name|setStretchFactor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|splitter
operator|->
name|setStretchFactor
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|table
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|pieChart
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|QItemSelectionModel
modifier|*
name|selectionModel
init|=
operator|new
name|QItemSelectionModel
argument_list|(
name|model
argument_list|)
decl_stmt|;
name|table
operator|->
name|setSelectionModel
argument_list|(
name|selectionModel
argument_list|)
expr_stmt|;
name|pieChart
operator|->
name|setSelectionModel
argument_list|(
name|selectionModel
argument_list|)
expr_stmt|;
name|QHeaderView
modifier|*
name|headerView
init|=
name|table
operator|->
name|horizontalHeader
argument_list|()
decl_stmt|;
name|headerView
operator|->
name|setStretchLastSection
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|splitter
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|openFile
name|void
name|MainWindow
operator|::
name|openFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
name|QString
name|fileName
decl_stmt|;
if|if
condition|(
name|path
operator|.
name|isNull
argument_list|()
condition|)
name|fileName
operator|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Choose a data file"
argument_list|)
argument_list|,
literal|""
argument_list|,
literal|"*.cht"
argument_list|)
expr_stmt|;
else|else
name|fileName
operator|=
name|path
expr_stmt|;
if|if
condition|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
name|QTextStream
name|stream
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|QString
name|line
decl_stmt|;
name|model
operator|->
name|removeRows
argument_list|(
literal|0
argument_list|,
name|model
operator|->
name|rowCount
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|row
init|=
literal|0
decl_stmt|;
do|do
block|{
name|line
operator|=
name|stream
operator|.
name|readLine
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|line
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|model
operator|->
name|insertRows
argument_list|(
name|row
argument_list|,
literal|1
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
name|QStringList
name|pieces
init|=
name|line
operator|.
name|split
argument_list|(
literal|","
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
decl_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|model
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
argument_list|,
name|pieces
operator|.
name|value
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|model
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
argument_list|,
name|pieces
operator|.
name|value
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|model
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
argument_list|,
name|QColor
argument_list|(
name|pieces
operator|.
name|value
argument_list|(
literal|2
argument_list|)
argument_list|)
argument_list|,
name|Qt
operator|::
name|DecorationRole
argument_list|)
expr_stmt|;
name|row
operator|++
expr_stmt|;
block|}
block|}
do|while
condition|(
operator|!
name|line
operator|.
name|isEmpty
argument_list|()
condition|)
do|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"Loaded %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|saveFile
name|void
name|MainWindow
operator|::
name|saveFile
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getSaveFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Save file as"
argument_list|)
argument_list|,
literal|""
argument_list|,
literal|"*.cht"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|QTextStream
name|stream
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|model
operator|->
name|rowCount
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
condition|;
operator|++
name|row
control|)
block|{
name|QStringList
name|pieces
decl_stmt|;
name|pieces
operator|.
name|append
argument_list|(
name|model
operator|->
name|data
argument_list|(
name|model
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
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|pieces
operator|.
name|append
argument_list|(
name|model
operator|->
name|data
argument_list|(
name|model
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
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|pieces
operator|.
name|append
argument_list|(
name|model
operator|->
name|data
argument_list|(
name|model
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
argument_list|,
name|Qt
operator|::
name|DecorationRole
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|stream
operator|<<
name|pieces
operator|.
name|join
argument_list|(
literal|","
argument_list|)
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"Saved %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
