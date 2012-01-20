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
file|"mainwindow.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|addressWidget
operator|=
operator|new
name|AddressWidget
expr_stmt|;
name|setCentralWidget
argument_list|(
name|addressWidget
argument_list|)
expr_stmt|;
name|createMenus
argument_list|()
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Address Book"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1a]
end_comment
begin_function
DECL|function|createMenus
name|void
name|MainWindow
operator|::
name|createMenus
parameter_list|()
block|{
name|fileMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
expr_stmt|;
name|openAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Open..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|openAct
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openAct
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
comment|//! [1a]
name|saveAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Save As..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAct
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveAct
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
name|fileMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|exitAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exitAct
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|exitAct
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
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|toolMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Tools"
argument_list|)
argument_list|)
expr_stmt|;
name|addAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Add Entry..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|toolMenu
operator|->
name|addAction
argument_list|(
name|addAct
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|addAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|addressWidget
argument_list|,
name|SLOT
argument_list|(
name|addEntry
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1b]
name|editAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Edit Entry..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|editAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|toolMenu
operator|->
name|addAction
argument_list|(
name|editAct
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|editAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|addressWidget
argument_list|,
name|SLOT
argument_list|(
name|editEntry
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|toolMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|removeAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Remove Entry"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|removeAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|toolMenu
operator|->
name|addAction
argument_list|(
name|removeAct
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|removeAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|addressWidget
argument_list|,
name|SLOT
argument_list|(
name|removeEntry
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|addressWidget
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|(
name|QItemSelection
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateActions
argument_list|(
name|QItemSelection
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1b]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|openFile
name|void
name|MainWindow
operator|::
name|openFile
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
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
name|addressWidget
operator|->
name|readFromFile
argument_list|(
name|fileName
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
name|addressWidget
operator|->
name|writeToFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|updateActions
name|void
name|MainWindow
operator|::
name|updateActions
parameter_list|(
specifier|const
name|QItemSelection
modifier|&
name|selection
parameter_list|)
block|{
name|QModelIndexList
name|indexes
init|=
name|selection
operator|.
name|indexes
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|indexes
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|removeAct
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|editAct
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|removeAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|editAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [4]
end_comment
end_unit
