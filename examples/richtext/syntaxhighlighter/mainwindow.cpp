begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|setupFileMenu
argument_list|()
expr_stmt|;
name|setupHelpMenu
argument_list|()
expr_stmt|;
name|setupEditor
argument_list|()
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
literal|"Syntax Highlighter"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
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
literal|"About Syntax Highlighter"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"<p>The<b>Syntax Highlighter</b> example shows how "
expr|\
literal|"to perform simple syntax highlighting by subclassing "
expr|\
literal|"the QSyntaxHighlighter class and describing "
expr|\
literal|"highlighting rules using regular expressions.</p>"
argument_list|)
argument_list|)
expr_stmt|;
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
name|editor
operator|->
name|clear
argument_list|()
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
init|=
name|path
decl_stmt|;
if|if
condition|(
name|fileName
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
literal|"Open File"
argument_list|)
argument_list|,
literal|""
argument_list|,
literal|"C++ Files (*.cpp *.h)"
argument_list|)
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
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|setupEditor
name|void
name|MainWindow
operator|::
name|setupEditor
parameter_list|()
block|{
name|QFont
name|font
decl_stmt|;
name|font
operator|.
name|setFamily
argument_list|(
literal|"Courier"
argument_list|)
expr_stmt|;
name|font
operator|.
name|setFixedPitch
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|font
operator|.
name|setPointSize
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|editor
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|editor
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|highlighter
operator|=
operator|new
name|Highlighter
argument_list|(
name|editor
operator|->
name|document
argument_list|()
argument_list|)
expr_stmt|;
name|QFile
name|file
argument_list|(
literal|"mainwindow.h"
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
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|setupFileMenu
name|void
name|MainWindow
operator|::
name|setupFileMenu
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
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|fileMenu
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&New"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|newFile
argument_list|()
argument_list|)
argument_list|,
name|QKeySequence
operator|::
name|New
argument_list|)
expr_stmt|;
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
operator|::
name|Open
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|,
name|QKeySequence
operator|::
name|Quit
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupHelpMenu
name|void
name|MainWindow
operator|::
name|setupHelpMenu
parameter_list|()
block|{
name|QMenu
modifier|*
name|helpMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Help"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|helpMenu
argument_list|)
expr_stmt|;
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
name|SLOT
argument_list|(
name|about
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
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
name|SLOT
argument_list|(
name|aboutQt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
