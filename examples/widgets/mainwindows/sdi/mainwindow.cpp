begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|init
argument_list|()
expr_stmt|;
name|setCurrentFile
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|init
argument_list|()
expr_stmt|;
name|loadFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|closeEvent
name|void
name|MainWindow
operator|::
name|closeEvent
parameter_list|(
name|QCloseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|maybeSave
argument_list|()
condition|)
block|{
name|writeSettings
argument_list|()
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
block|}
end_function
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
name|tile
argument_list|(
name|this
argument_list|)
expr_stmt|;
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
specifier|const
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
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|MainWindow
modifier|*
name|existing
init|=
name|findMainWindow
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|existing
condition|)
block|{
name|existing
operator|->
name|show
argument_list|()
expr_stmt|;
name|existing
operator|->
name|raise
argument_list|()
expr_stmt|;
name|existing
operator|->
name|activateWindow
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|isUntitled
operator|&&
name|textEdit
operator|->
name|document
argument_list|()
operator|->
name|isEmpty
argument_list|()
operator|&&
operator|!
name|isWindowModified
argument_list|()
condition|)
block|{
name|loadFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
return|return;
block|}
name|MainWindow
modifier|*
name|other
init|=
operator|new
name|MainWindow
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|other
operator|->
name|isUntitled
condition|)
block|{
operator|delete
name|other
expr_stmt|;
return|return;
block|}
name|other
operator|->
name|tile
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|other
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|save
name|bool
name|MainWindow
operator|::
name|save
parameter_list|()
block|{
return|return
name|isUntitled
condition|?
name|saveAs
argument_list|()
else|:
name|saveFile
argument_list|(
name|curFile
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|saveAs
name|bool
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
argument_list|,
name|tr
argument_list|(
literal|"Save As"
argument_list|)
argument_list|,
name|curFile
argument_list|)
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
return|return
name|saveFile
argument_list|(
name|fileName
argument_list|)
return|;
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
literal|"About SDI"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The<b>SDI</b> example demonstrates how to write single "
literal|"document interface applications using Qt."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|documentWasModified
name|void
name|MainWindow
operator|::
name|documentWasModified
parameter_list|()
block|{
name|setWindowModified
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|MainWindow
operator|::
name|init
parameter_list|()
block|{
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|isUntitled
operator|=
literal|true
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
name|createStatusBar
argument_list|()
expr_stmt|;
name|readSettings
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|textEdit
operator|->
name|document
argument_list|()
argument_list|,
operator|&
name|QTextDocument
operator|::
name|contentsChanged
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|documentWasModified
argument_list|)
expr_stmt|;
name|setUnifiedTitleAndToolBarOnMac
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tile
name|void
name|MainWindow
operator|::
name|tile
parameter_list|(
specifier|const
name|QMainWindow
modifier|*
name|previous
parameter_list|)
block|{
if|if
condition|(
operator|!
name|previous
condition|)
return|return;
name|int
name|topFrameWidth
init|=
name|previous
operator|->
name|geometry
argument_list|()
operator|.
name|top
argument_list|()
operator|-
name|previous
operator|->
name|pos
argument_list|()
operator|.
name|y
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|topFrameWidth
condition|)
name|topFrameWidth
operator|=
literal|40
expr_stmt|;
specifier|const
name|QPoint
name|pos
init|=
name|previous
operator|->
name|pos
argument_list|()
operator|+
literal|2
operator|*
name|QPoint
argument_list|(
name|topFrameWidth
argument_list|,
name|topFrameWidth
argument_list|)
decl_stmt|;
if|if
condition|(
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|availableGeometry
argument_list|(
name|this
argument_list|)
operator|.
name|contains
argument_list|(
name|rect
argument_list|()
operator|.
name|bottomRight
argument_list|()
operator|+
name|pos
argument_list|)
condition|)
name|move
argument_list|(
name|pos
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [implicit tr context]
end_comment
begin_function
DECL|function|createActions
name|void
name|MainWindow
operator|::
name|createActions
parameter_list|()
block|{
name|QMenu
modifier|*
name|fileMenu
init|=
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
decl_stmt|;
comment|//! [implicit tr context]
name|QToolBar
modifier|*
name|fileToolBar
init|=
name|addToolBar
argument_list|(
name|tr
argument_list|(
literal|"File"
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QIcon
name|newIcon
init|=
name|QIcon
operator|::
name|fromTheme
argument_list|(
literal|"document-new"
argument_list|,
name|QIcon
argument_list|(
literal|":/images/new.png"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|newAct
init|=
operator|new
name|QAction
argument_list|(
name|newIcon
argument_list|,
name|tr
argument_list|(
literal|"&New"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
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
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|newFile
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|newAct
argument_list|)
expr_stmt|;
name|fileToolBar
operator|->
name|addAction
argument_list|(
name|newAct
argument_list|)
expr_stmt|;
specifier|const
name|QIcon
name|openIcon
init|=
name|QIcon
operator|::
name|fromTheme
argument_list|(
literal|"document-open"
argument_list|,
name|QIcon
argument_list|(
literal|":/images/open.png"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|openAct
init|=
operator|new
name|QAction
argument_list|(
name|openIcon
argument_list|,
name|tr
argument_list|(
literal|"&Open..."
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
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
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|open
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|openAct
argument_list|)
expr_stmt|;
name|fileToolBar
operator|->
name|addAction
argument_list|(
name|openAct
argument_list|)
expr_stmt|;
specifier|const
name|QIcon
name|saveIcon
init|=
name|QIcon
operator|::
name|fromTheme
argument_list|(
literal|"document-save"
argument_list|,
name|QIcon
argument_list|(
literal|":/images/save.png"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|saveAct
init|=
operator|new
name|QAction
argument_list|(
name|saveIcon
argument_list|,
name|tr
argument_list|(
literal|"&Save"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
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
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|save
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAct
argument_list|)
expr_stmt|;
name|fileToolBar
operator|->
name|addAction
argument_list|(
name|saveAct
argument_list|)
expr_stmt|;
specifier|const
name|QIcon
name|saveAsIcon
init|=
name|QIcon
operator|::
name|fromTheme
argument_list|(
literal|"document-save-as"
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|saveAsAct
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAsIcon
argument_list|,
name|tr
argument_list|(
literal|"Save&As..."
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|saveAs
argument_list|)
decl_stmt|;
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
name|fileMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|QAction
modifier|*
name|closeAct
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Close"
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|QWidget
operator|::
name|close
argument_list|)
decl_stmt|;
name|closeAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+W"
argument_list|)
argument_list|)
expr_stmt|;
name|closeAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Close this window"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QIcon
name|exitIcon
init|=
name|QIcon
operator|::
name|fromTheme
argument_list|(
literal|"application-exit"
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|exitAct
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exitIcon
argument_list|,
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|,
name|qApp
argument_list|,
operator|&
name|QApplication
operator|::
name|closeAllWindows
argument_list|)
decl_stmt|;
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
name|QMenu
modifier|*
name|editMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Edit"
argument_list|)
argument_list|)
decl_stmt|;
name|QToolBar
modifier|*
name|editToolBar
init|=
name|addToolBar
argument_list|(
name|tr
argument_list|(
literal|"Edit"
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QIcon
name|cutIcon
init|=
name|QIcon
operator|::
name|fromTheme
argument_list|(
literal|"edit-cut"
argument_list|,
name|QIcon
argument_list|(
literal|":/images/cut.png"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|cutAct
init|=
operator|new
name|QAction
argument_list|(
name|cutIcon
argument_list|,
name|tr
argument_list|(
literal|"Cu&t"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|cutAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Cut
argument_list|)
expr_stmt|;
name|cutAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Cut the current selection's contents to the "
literal|"clipboard"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|cutAct
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|textEdit
argument_list|,
operator|&
name|QTextEdit
operator|::
name|cut
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
name|cutAct
argument_list|)
expr_stmt|;
name|editToolBar
operator|->
name|addAction
argument_list|(
name|cutAct
argument_list|)
expr_stmt|;
specifier|const
name|QIcon
name|copyIcon
init|=
name|QIcon
operator|::
name|fromTheme
argument_list|(
literal|"edit-copy"
argument_list|,
name|QIcon
argument_list|(
literal|":/images/copy.png"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|copyAct
init|=
operator|new
name|QAction
argument_list|(
name|copyIcon
argument_list|,
name|tr
argument_list|(
literal|"&Copy"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|copyAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Copy
argument_list|)
expr_stmt|;
name|copyAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Copy the current selection's contents to the "
literal|"clipboard"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|copyAct
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|textEdit
argument_list|,
operator|&
name|QTextEdit
operator|::
name|copy
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
name|copyAct
argument_list|)
expr_stmt|;
name|editToolBar
operator|->
name|addAction
argument_list|(
name|copyAct
argument_list|)
expr_stmt|;
specifier|const
name|QIcon
name|pasteIcon
init|=
name|QIcon
operator|::
name|fromTheme
argument_list|(
literal|"edit-paste"
argument_list|,
name|QIcon
argument_list|(
literal|":/images/paste.png"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|pasteAct
init|=
operator|new
name|QAction
argument_list|(
name|pasteIcon
argument_list|,
name|tr
argument_list|(
literal|"&Paste"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|pasteAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Paste
argument_list|)
expr_stmt|;
name|pasteAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Paste the clipboard's contents into the current "
literal|"selection"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|pasteAct
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|textEdit
argument_list|,
operator|&
name|QTextEdit
operator|::
name|paste
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
name|pasteAct
argument_list|)
expr_stmt|;
name|editToolBar
operator|->
name|addAction
argument_list|(
name|pasteAct
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|QMenu
modifier|*
name|helpMenu
init|=
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
decl_stmt|;
name|QAction
modifier|*
name|aboutAct
init|=
name|helpMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&About"
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|about
argument_list|)
decl_stmt|;
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
name|QAction
modifier|*
name|aboutQtAct
init|=
name|helpMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"About&Qt"
argument_list|)
argument_list|,
name|qApp
argument_list|,
operator|&
name|QApplication
operator|::
name|aboutQt
argument_list|)
decl_stmt|;
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
name|cutAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|copyAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|textEdit
argument_list|,
operator|&
name|QTextEdit
operator|::
name|copyAvailable
argument_list|,
name|cutAct
argument_list|,
operator|&
name|QAction
operator|::
name|setEnabled
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|textEdit
argument_list|,
operator|&
name|QTextEdit
operator|::
name|copyAvailable
argument_list|,
name|copyAct
argument_list|,
operator|&
name|QAction
operator|::
name|setEnabled
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createStatusBar
name|void
name|MainWindow
operator|::
name|createStatusBar
parameter_list|()
block|{
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"Ready"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readSettings
name|void
name|MainWindow
operator|::
name|readSettings
parameter_list|()
block|{
name|QSettings
name|settings
argument_list|(
name|QCoreApplication
operator|::
name|organizationName
argument_list|()
argument_list|,
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QByteArray
name|geometry
init|=
name|settings
operator|.
name|value
argument_list|(
literal|"geometry"
argument_list|,
name|QByteArray
argument_list|()
argument_list|)
operator|.
name|toByteArray
argument_list|()
decl_stmt|;
if|if
condition|(
name|geometry
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|QRect
name|availableGeometry
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|availableGeometry
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|resize
argument_list|(
name|availableGeometry
operator|.
name|width
argument_list|()
operator|/
literal|3
argument_list|,
name|availableGeometry
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|move
argument_list|(
operator|(
name|availableGeometry
operator|.
name|width
argument_list|()
operator|-
name|width
argument_list|()
operator|)
operator|/
literal|2
argument_list|,
operator|(
name|availableGeometry
operator|.
name|height
argument_list|()
operator|-
name|height
argument_list|()
operator|)
operator|/
literal|2
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|restoreGeometry
argument_list|(
name|geometry
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|writeSettings
name|void
name|MainWindow
operator|::
name|writeSettings
parameter_list|()
block|{
name|QSettings
name|settings
argument_list|(
name|QCoreApplication
operator|::
name|organizationName
argument_list|()
argument_list|,
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
argument_list|)
decl_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"geometry"
argument_list|,
name|saveGeometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|maybeSave
name|bool
name|MainWindow
operator|::
name|maybeSave
parameter_list|()
block|{
if|if
condition|(
operator|!
name|textEdit
operator|->
name|document
argument_list|()
operator|->
name|isModified
argument_list|()
condition|)
return|return
literal|true
return|;
specifier|const
name|QMessageBox
operator|::
name|StandardButton
name|ret
init|=
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"SDI"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The document has been modified.\n"
literal|"Do you want to save your changes?"
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Save
operator||
name|QMessageBox
operator|::
name|Discard
operator||
name|QMessageBox
operator|::
name|Cancel
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|ret
condition|)
block|{
case|case
name|QMessageBox
operator|::
name|Save
case|:
return|return
name|save
argument_list|()
return|;
case|case
name|QMessageBox
operator|::
name|Cancel
case|:
return|return
literal|false
return|;
default|default:
break|break;
block|}
return|return
literal|true
return|;
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
literal|"SDI"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cannot read file %1:\n%2."
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileName
argument_list|)
argument_list|,
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
name|bool
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
literal|"SDI"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cannot write file %1:\n%2."
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileName
argument_list|)
argument_list|,
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
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
return|return
literal|true
return|;
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
specifier|static
name|int
name|sequenceNumber
init|=
literal|1
decl_stmt|;
name|isUntitled
operator|=
name|fileName
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
if|if
condition|(
name|isUntitled
condition|)
block|{
name|curFile
operator|=
name|tr
argument_list|(
literal|"document%1.txt"
argument_list|)
operator|.
name|arg
argument_list|(
name|sequenceNumber
operator|++
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|curFile
operator|=
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|canonicalFilePath
argument_list|()
expr_stmt|;
block|}
name|textEdit
operator|->
name|document
argument_list|()
operator|->
name|setModified
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setWindowModified
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setWindowFilePath
argument_list|(
name|curFile
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
begin_function
DECL|function|findMainWindow
name|MainWindow
modifier|*
name|MainWindow
operator|::
name|findMainWindow
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
specifier|const
block|{
name|QString
name|canonicalFilePath
init|=
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|canonicalFilePath
argument_list|()
decl_stmt|;
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
operator|&&
name|mainWin
operator|->
name|curFile
operator|==
name|canonicalFilePath
condition|)
return|return
name|mainWin
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
end_unit
