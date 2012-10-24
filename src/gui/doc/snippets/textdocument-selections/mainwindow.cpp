begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
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
argument_list|)
decl_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Open..."
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|openFile
argument_list|()
argument_list|)
argument_list|,
name|QKeySequence
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+O"
argument_list|,
literal|"File|Open"
argument_list|)
argument_list|)
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
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|quitAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+Q"
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|editMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Edit"
argument_list|)
argument_list|)
decl_stmt|;
name|cutAction
operator|=
name|editMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Cu&t"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|cutSelection
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|cutAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+X"
argument_list|)
argument_list|)
expr_stmt|;
name|cutAction
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|copyAction
operator|=
name|editMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Copy"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|copySelection
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|copyAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+C"
argument_list|)
argument_list|)
expr_stmt|;
name|copyAction
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|pasteAction
operator|=
name|editMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Paste"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|pasteSelection
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|pasteAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+V"
argument_list|)
argument_list|)
expr_stmt|;
name|pasteAction
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|selectMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Select"
argument_list|)
argument_list|)
decl_stmt|;
name|selectMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Word"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|selectWord
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|selectMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Line"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|selectLine
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|selectMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Block"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|selectBlock
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|selectMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Frame"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|selectFrame
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
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|editMenu
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|selectMenu
argument_list|)
expr_stmt|;
name|editor
operator|=
operator|new
name|QTextEdit
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|document
operator|=
operator|new
name|QTextDocument
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|editor
operator|->
name|setDocument
argument_list|(
name|document
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|editor
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateMenus
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|editor
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Text Document Writer"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
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
argument_list|,
name|tr
argument_list|(
literal|"Open file"
argument_list|)
argument_list|,
name|currentFile
argument_list|,
literal|"HTML files (*.html);;Text files (*.txt)"
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
name|QFileInfo
name|info
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|info
operator|.
name|completeSuffix
argument_list|()
operator|==
literal|"html"
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
argument_list|)
condition|)
block|{
name|editor
operator|->
name|setHtml
argument_list|(
name|QString
argument_list|(
name|file
operator|.
name|readAll
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
name|currentFile
operator|=
name|fileName
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|info
operator|.
name|completeSuffix
argument_list|()
operator|==
literal|"txt"
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
argument_list|)
condition|)
block|{
name|editor
operator|->
name|setPlainText
argument_list|(
name|file
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
name|currentFile
operator|=
name|fileName
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|cutSelection
name|void
name|MainWindow
operator|::
name|cutSelection
parameter_list|()
block|{
name|QTextCursor
name|cursor
init|=
name|editor
operator|->
name|textCursor
argument_list|()
decl_stmt|;
if|if
condition|(
name|cursor
operator|.
name|hasSelection
argument_list|()
condition|)
block|{
name|selection
operator|=
name|cursor
operator|.
name|selection
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|removeSelectedText
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|copySelection
name|void
name|MainWindow
operator|::
name|copySelection
parameter_list|()
block|{
name|QTextCursor
name|cursor
init|=
name|editor
operator|->
name|textCursor
argument_list|()
decl_stmt|;
if|if
condition|(
name|cursor
operator|.
name|hasSelection
argument_list|()
condition|)
block|{
name|selection
operator|=
name|cursor
operator|.
name|selection
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|clearSelection
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|pasteSelection
name|void
name|MainWindow
operator|::
name|pasteSelection
parameter_list|()
block|{
name|QTextCursor
name|cursor
init|=
name|editor
operator|->
name|textCursor
argument_list|()
decl_stmt|;
name|cursor
operator|.
name|insertFragment
argument_list|(
name|selection
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectWord
name|void
name|MainWindow
operator|::
name|selectWord
parameter_list|()
block|{
name|QTextCursor
name|cursor
init|=
name|editor
operator|->
name|textCursor
argument_list|()
decl_stmt|;
name|QTextBlock
name|block
init|=
name|cursor
operator|.
name|block
argument_list|()
decl_stmt|;
comment|//! [0]
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
comment|//! [1]
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|StartOfWord
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|EndOfWord
argument_list|,
name|QTextCursor
operator|::
name|KeepAnchor
argument_list|)
expr_stmt|;
comment|//! [1]
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
comment|//! [0]
name|editor
operator|->
name|setTextCursor
argument_list|(
name|cursor
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectLine
name|void
name|MainWindow
operator|::
name|selectLine
parameter_list|()
block|{
name|QTextCursor
name|cursor
init|=
name|editor
operator|->
name|textCursor
argument_list|()
decl_stmt|;
name|QTextBlock
name|block
init|=
name|cursor
operator|.
name|block
argument_list|()
decl_stmt|;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|StartOfLine
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|EndOfLine
argument_list|,
name|QTextCursor
operator|::
name|KeepAnchor
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
name|editor
operator|->
name|setTextCursor
argument_list|(
name|cursor
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectBlock
name|void
name|MainWindow
operator|::
name|selectBlock
parameter_list|()
block|{
name|QTextCursor
name|cursor
init|=
name|editor
operator|->
name|textCursor
argument_list|()
decl_stmt|;
name|QTextBlock
name|block
init|=
name|cursor
operator|.
name|block
argument_list|()
decl_stmt|;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|StartOfBlock
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|EndOfBlock
argument_list|,
name|QTextCursor
operator|::
name|KeepAnchor
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
name|editor
operator|->
name|setTextCursor
argument_list|(
name|cursor
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectFrame
name|void
name|MainWindow
operator|::
name|selectFrame
parameter_list|()
block|{
name|QTextCursor
name|cursor
init|=
name|editor
operator|->
name|textCursor
argument_list|()
decl_stmt|;
name|QTextFrame
modifier|*
name|frame
init|=
name|cursor
operator|.
name|currentFrame
argument_list|()
decl_stmt|;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|setPosition
argument_list|(
name|frame
operator|->
name|firstPosition
argument_list|()
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|setPosition
argument_list|(
name|frame
operator|->
name|lastPosition
argument_list|()
argument_list|,
name|QTextCursor
operator|::
name|KeepAnchor
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
name|editor
operator|->
name|setTextCursor
argument_list|(
name|cursor
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateMenus
name|void
name|MainWindow
operator|::
name|updateMenus
parameter_list|()
block|{
name|QTextCursor
name|cursor
init|=
name|editor
operator|->
name|textCursor
argument_list|()
decl_stmt|;
name|cutAction
operator|->
name|setEnabled
argument_list|(
name|cursor
operator|.
name|hasSelection
argument_list|()
argument_list|)
expr_stmt|;
name|copyAction
operator|->
name|setEnabled
argument_list|(
name|cursor
operator|.
name|hasSelection
argument_list|()
argument_list|)
expr_stmt|;
name|pasteAction
operator|->
name|setEnabled
argument_list|(
operator|!
name|selection
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
