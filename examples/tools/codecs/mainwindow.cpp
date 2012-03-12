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
file|"previewform.h"
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|textEdit
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|textEdit
operator|->
name|setLineWrapMode
argument_list|(
name|QTextEdit
operator|::
name|NoWrap
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|textEdit
argument_list|)
expr_stmt|;
name|findCodecs
argument_list|()
expr_stmt|;
name|previewForm
operator|=
operator|new
name|PreviewForm
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|previewForm
operator|->
name|setCodecList
argument_list|(
name|codecs
argument_list|)
expr_stmt|;
name|createActions
argument_list|()
expr_stmt|;
name|createMenus
argument_list|()
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Codecs"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|500
argument_list|,
literal|400
argument_list|)
expr_stmt|;
block|}
end_constructor
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
literal|"Codecs"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cannot read file %1:\n%2"
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
name|QByteArray
name|data
init|=
name|file
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|previewForm
operator|->
name|setEncodedData
argument_list|(
name|data
argument_list|)
expr_stmt|;
if|if
condition|(
name|previewForm
operator|->
name|exec
argument_list|()
condition|)
name|textEdit
operator|->
name|setPlainText
argument_list|(
name|previewForm
operator|->
name|decodedString
argument_list|()
argument_list|)
expr_stmt|;
block|}
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
literal|"Codecs"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cannot write file %1:\n%2"
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
name|QByteArray
name|codecName
init|=
name|action
operator|->
name|data
argument_list|()
operator|.
name|toByteArray
argument_list|()
decl_stmt|;
name|QTextStream
name|out
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|out
operator|.
name|setCodec
argument_list|(
name|codecName
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|out
operator|<<
name|textEdit
operator|->
name|toPlainText
argument_list|()
expr_stmt|;
block|}
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
literal|"About Codecs"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The<b>Codecs</b> example demonstrates how to read and write "
literal|"files using various encodings."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|aboutToShowSaveAsMenu
name|void
name|MainWindow
operator|::
name|aboutToShowSaveAsMenu
parameter_list|()
block|{
name|QString
name|currentText
init|=
name|textEdit
operator|->
name|toPlainText
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QAction
modifier|*
name|action
decl|,
name|saveAsActs
control|)
block|{
name|QByteArray
name|codecName
init|=
name|action
operator|->
name|data
argument_list|()
operator|.
name|toByteArray
argument_list|()
decl_stmt|;
name|QTextCodec
modifier|*
name|codec
init|=
name|QTextCodec
operator|::
name|codecForName
argument_list|(
name|codecName
argument_list|)
decl_stmt|;
name|action
operator|->
name|setVisible
argument_list|(
name|codec
operator|&&
name|codec
operator|->
name|canEncode
argument_list|(
name|currentText
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|findCodecs
name|void
name|MainWindow
operator|::
name|findCodecs
parameter_list|()
block|{
name|QMap
argument_list|<
name|QString
argument_list|,
name|QTextCodec
modifier|*
argument_list|>
name|codecMap
decl_stmt|;
name|QRegExp
name|iso8859RegExp
argument_list|(
literal|"ISO[- ]8859-([0-9]+).*"
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|int
name|mib
decl|,
name|QTextCodec
operator|::
name|availableMibs
argument_list|()
control|)
block|{
name|QTextCodec
modifier|*
name|codec
init|=
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
name|mib
argument_list|)
decl_stmt|;
name|QString
name|sortKey
init|=
name|codec
operator|->
name|name
argument_list|()
operator|.
name|toUpper
argument_list|()
decl_stmt|;
name|int
name|rank
decl_stmt|;
if|if
condition|(
name|sortKey
operator|.
name|startsWith
argument_list|(
literal|"UTF-8"
argument_list|)
condition|)
block|{
name|rank
operator|=
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|sortKey
operator|.
name|startsWith
argument_list|(
literal|"UTF-16"
argument_list|)
condition|)
block|{
name|rank
operator|=
literal|2
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|iso8859RegExp
operator|.
name|exactMatch
argument_list|(
name|sortKey
argument_list|)
condition|)
block|{
if|if
condition|(
name|iso8859RegExp
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
name|rank
operator|=
literal|3
expr_stmt|;
else|else
name|rank
operator|=
literal|4
expr_stmt|;
block|}
else|else
block|{
name|rank
operator|=
literal|5
expr_stmt|;
block|}
name|sortKey
operator|.
name|prepend
argument_list|(
name|QChar
argument_list|(
literal|'0'
operator|+
name|rank
argument_list|)
argument_list|)
expr_stmt|;
name|codecMap
operator|.
name|insert
argument_list|(
name|sortKey
argument_list|,
name|codec
argument_list|)
expr_stmt|;
block|}
name|codecs
operator|=
name|codecMap
operator|.
name|values
argument_list|()
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
foreach|foreach
control|(
name|QTextCodec
modifier|*
name|codec
decl|,
name|codecs
control|)
block|{
name|QString
name|text
init|=
name|tr
argument_list|(
literal|"%1..."
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
argument_list|(
name|codec
operator|->
name|name
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|action
init|=
operator|new
name|QAction
argument_list|(
name|text
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|action
operator|->
name|setData
argument_list|(
name|codec
operator|->
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|action
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
name|saveAsActs
operator|.
name|append
argument_list|(
name|action
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
name|saveAsMenu
operator|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Save As"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QAction
modifier|*
name|action
decl|,
name|saveAsActs
control|)
name|saveAsMenu
operator|->
name|addAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveAsMenu
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
name|aboutToShowSaveAsMenu
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|fileMenu
operator|=
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
name|addMenu
argument_list|(
name|saveAsMenu
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
name|helpMenu
operator|=
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
name|addSeparator
argument_list|()
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|helpMenu
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
