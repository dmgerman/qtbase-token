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
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|textEdit
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|setCentralWidget
argument_list|(
name|textEdit
argument_list|)
expr_stmt|;
name|createActions
argument_list|()
expr_stmt|;
name|createMenus
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|statusBar
argument_list|()
expr_stmt|;
name|setWindowFilePath
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|400
argument_list|,
literal|300
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|newFile
name|void
name|MainWindow
operator|::
name|newFile
parameter_list|()
block|{
name|MainWindow
modifier|*
name|other
init|=
operator|new
name|MainWindow
decl_stmt|;
name|other
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|open
name|void
name|MainWindow
operator|::
name|open
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
name|loadFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|save
name|void
name|MainWindow
operator|::
name|save
parameter_list|()
block|{
if|if
condition|(
name|curFile
operator|.
name|isEmpty
argument_list|()
condition|)
name|saveAs
argument_list|()
expr_stmt|;
else|else
name|saveFile
argument_list|(
name|curFile
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|saveAs
name|void
name|MainWindow
operator|::
name|saveAs
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
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|saveFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|openRecentFile
name|void
name|MainWindow
operator|::
name|openRecentFile
parameter_list|()
block|{
name|QAction
modifier|*
name|action
init|=
name|qobject_cast
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|action
condition|)
name|loadFile
argument_list|(
name|action
operator|->
name|data
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|about
name|void
name|MainWindow
operator|::
name|about
parameter_list|()
block|{
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"About Recent Files"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The<b>Recent Files</b> example demonstrates how to provide a "
literal|"recently used file menu in a Qt application."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createActions
name|void
name|MainWindow
operator|::
name|createActions
parameter_list|()
block|{
name|newAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&New"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|newAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|New
argument_list|)
expr_stmt|;
name|newAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Create a new file"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|newAct
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
name|newFile
argument_list|()
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
name|openAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Open
argument_list|)
expr_stmt|;
name|openAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Open an existing file"
argument_list|)
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
name|open
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|saveAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Save"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|saveAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Save
argument_list|)
expr_stmt|;
name|saveAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Save the document to disk"
argument_list|)
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
name|save
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|saveAsAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Save&As..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|saveAsAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|SaveAs
argument_list|)
expr_stmt|;
name|saveAsAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Save the document under a new name"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveAsAct
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
name|saveAs
argument_list|()
argument_list|)
argument_list|)
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
name|MaxRecentFiles
condition|;
operator|++
name|i
control|)
block|{
name|recentFileActs
index|[
name|i
index|]
operator|=
operator|new
name|QAction
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|recentFileActs
index|[
name|i
index|]
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|recentFileActs
index|[
name|i
index|]
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
name|openRecentFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
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
name|exitAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
expr_stmt|;
name|exitAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Exit the application"
argument_list|)
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
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|closeAllWindows
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|aboutAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&About"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|aboutAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Show the application's About box"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutAct
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
name|about
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|aboutQtAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"About&Qt"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|aboutQtAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Show the Qt library's About box"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutQtAct
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
name|aboutQt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
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
name|fileMenu
operator|->
name|addAction
argument_list|(
name|newAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|openAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAsAct
argument_list|)
expr_stmt|;
name|separatorAct
operator|=
name|fileMenu
operator|->
name|addSeparator
argument_list|()
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
name|MaxRecentFiles
condition|;
operator|++
name|i
control|)
name|fileMenu
operator|->
name|addAction
argument_list|(
name|recentFileActs
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exitAct
argument_list|)
expr_stmt|;
name|updateRecentFileActions
argument_list|()
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|helpMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Help"
argument_list|)
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutAct
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutQtAct
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadFile
name|void
name|MainWindow
operator|::
name|loadFile
parameter_list|(
specifier|const
name|QString
modifier|&
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
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Recent Files"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cannot read file %1:\n%2."
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|QTextStream
name|in
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|setOverrideCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|setPlainText
argument_list|(
name|in
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
name|QApplication
operator|::
name|restoreOverrideCursor
argument_list|()
expr_stmt|;
name|setCurrentFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"File loaded"
argument_list|)
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|saveFile
name|void
name|MainWindow
operator|::
name|saveFile
parameter_list|(
specifier|const
name|QString
modifier|&
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
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Recent Files"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cannot write file %1:\n%2."
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|QTextStream
name|out
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|setOverrideCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
expr_stmt|;
name|out
operator|<<
name|textEdit
operator|->
name|toPlainText
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|restoreOverrideCursor
argument_list|()
expr_stmt|;
name|setCurrentFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"File saved"
argument_list|)
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCurrentFile
name|void
name|MainWindow
operator|::
name|setCurrentFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|curFile
operator|=
name|fileName
expr_stmt|;
name|setWindowFilePath
argument_list|(
name|curFile
argument_list|)
expr_stmt|;
name|QSettings
name|settings
decl_stmt|;
name|QStringList
name|files
init|=
name|settings
operator|.
name|value
argument_list|(
literal|"recentFileList"
argument_list|)
operator|.
name|toStringList
argument_list|()
decl_stmt|;
name|files
operator|.
name|removeAll
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|files
operator|.
name|prepend
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
while|while
condition|(
name|files
operator|.
name|size
argument_list|()
operator|>
name|MaxRecentFiles
condition|)
name|files
operator|.
name|removeLast
argument_list|()
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"recentFileList"
argument_list|,
name|files
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QWidget
modifier|*
name|widget
decl|,
name|QApplication
operator|::
name|topLevelWidgets
argument_list|()
control|)
block|{
name|MainWindow
modifier|*
name|mainWin
init|=
name|qobject_cast
argument_list|<
name|MainWindow
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
decl_stmt|;
if|if
condition|(
name|mainWin
condition|)
name|mainWin
operator|->
name|updateRecentFileActions
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|updateRecentFileActions
name|void
name|MainWindow
operator|::
name|updateRecentFileActions
parameter_list|()
block|{
name|QSettings
name|settings
decl_stmt|;
name|QStringList
name|files
init|=
name|settings
operator|.
name|value
argument_list|(
literal|"recentFileList"
argument_list|)
operator|.
name|toStringList
argument_list|()
decl_stmt|;
name|int
name|numRecentFiles
init|=
name|qMin
argument_list|(
name|files
operator|.
name|size
argument_list|()
argument_list|,
operator|(
name|int
operator|)
name|MaxRecentFiles
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numRecentFiles
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|text
init|=
name|tr
argument_list|(
literal|"&%1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|+
literal|1
argument_list|)
operator|.
name|arg
argument_list|(
name|strippedName
argument_list|(
name|files
index|[
name|i
index|]
argument_list|)
argument_list|)
decl_stmt|;
name|recentFileActs
index|[
name|i
index|]
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|recentFileActs
index|[
name|i
index|]
operator|->
name|setData
argument_list|(
name|files
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|recentFileActs
index|[
name|i
index|]
operator|->
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|j
init|=
name|numRecentFiles
init|;
name|j
operator|<
name|MaxRecentFiles
condition|;
operator|++
name|j
control|)
name|recentFileActs
index|[
name|j
index|]
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|separatorAct
operator|->
name|setVisible
argument_list|(
name|numRecentFiles
operator|>
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|strippedName
name|QString
name|MainWindow
operator|::
name|strippedName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fullFileName
parameter_list|)
block|{
return|return
name|QFileInfo
argument_list|(
name|fullFileName
argument_list|)
operator|.
name|fileName
argument_list|()
return|;
block|}
end_function
end_unit
