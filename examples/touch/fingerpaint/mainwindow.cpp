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
begin_include
include|#
directive|include
file|"scribblearea.h"
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
name|scribbleArea
operator|=
operator|new
name|ScribbleArea
expr_stmt|;
name|setCentralWidget
argument_list|(
name|scribbleArea
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
literal|"Finger Paint"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|500
argument_list|,
literal|500
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
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
comment|//! [1] //! [2]
block|{
if|if
condition|(
name|maybeSave
argument_list|()
condition|)
block|{
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
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|open
name|void
name|MainWindow
operator|::
name|open
parameter_list|()
comment|//! [3] //! [4]
block|{
if|if
condition|(
name|maybeSave
argument_list|()
condition|)
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
literal|"Open File"
argument_list|)
argument_list|,
name|QDir
operator|::
name|currentPath
argument_list|()
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
name|scribbleArea
operator|->
name|openImage
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|save
name|void
name|MainWindow
operator|::
name|save
parameter_list|()
comment|//! [5] //! [6]
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
name|QByteArray
name|fileFormat
init|=
name|action
operator|->
name|data
argument_list|()
operator|.
name|toByteArray
argument_list|()
decl_stmt|;
name|saveFile
argument_list|(
name|fileFormat
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|about
name|void
name|MainWindow
operator|::
name|about
parameter_list|()
comment|//! [11] //! [12]
block|{
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"About Scribble"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"<p>The<b>Scribble</b> example shows how to use QMainWindow as the "
literal|"base widget for an application, and how to reimplement some of "
literal|"QWidget's event handlers to receive the events generated for "
literal|"the application's widgets:</p><p> We reimplement the mouse event "
literal|"handlers to facilitate drawing, the paint event handler to "
literal|"update the application and the resize event handler to optimize "
literal|"the application's appearance. In addition we reimplement the "
literal|"close event handler to intercept the close events before "
literal|"terminating the application.</p><p> The example also demonstrates "
literal|"how to use QPainter to draw an image in real time, as well as "
literal|"to repaint widgets.</p>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_function
DECL|function|createActions
name|void
name|MainWindow
operator|::
name|createActions
parameter_list|()
comment|//! [13] //! [14]
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
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+O"
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
foreach|foreach
control|(
name|QByteArray
name|format
decl|,
name|QImageWriter
operator|::
name|supportedImageFormats
argument_list|()
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
name|format
argument_list|)
operator|.
name|toUpper
argument_list|()
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
name|format
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
name|printAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Print..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|printAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|scribbleArea
argument_list|,
name|SLOT
argument_list|(
name|print
argument_list|()
argument_list|)
argument_list|)
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
name|exitAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+Q"
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
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|clearScreenAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Clear Screen"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|clearScreenAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+L"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|clearScreenAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|scribbleArea
argument_list|,
name|SLOT
argument_list|(
name|clearImage
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
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_function
DECL|function|createMenus
name|void
name|MainWindow
operator|::
name|createMenus
parameter_list|()
comment|//! [15] //! [16]
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
name|addAction
argument_list|(
name|printAct
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
name|optionMenu
operator|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Options"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|optionMenu
operator|->
name|addAction
argument_list|(
name|clearScreenAct
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
name|addMenu
argument_list|(
name|optionMenu
argument_list|)
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
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_function
DECL|function|maybeSave
name|bool
name|MainWindow
operator|::
name|maybeSave
parameter_list|()
comment|//! [17] //! [18]
block|{
if|if
condition|(
name|scribbleArea
operator|->
name|isModified
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|StandardButton
name|ret
decl_stmt|;
name|ret
operator|=
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Scribble"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The image has been modified.\n"
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
expr_stmt|;
if|if
condition|(
name|ret
operator|==
name|QMessageBox
operator|::
name|Save
condition|)
block|{
return|return
name|saveFile
argument_list|(
literal|"png"
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|ret
operator|==
name|QMessageBox
operator|::
name|Cancel
condition|)
block|{
return|return
literal|false
return|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [18]
end_comment
begin_comment
comment|//! [19]
end_comment
begin_function
DECL|function|saveFile
name|bool
name|MainWindow
operator|::
name|saveFile
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fileFormat
parameter_list|)
comment|//! [19] //! [20]
block|{
name|QString
name|initialPath
init|=
name|QDir
operator|::
name|currentPath
argument_list|()
operator|+
literal|"/untitled."
operator|+
name|fileFormat
decl_stmt|;
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
name|initialPath
argument_list|,
name|tr
argument_list|(
literal|"%1 Files (*.%2);;All Files (*)"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|fileFormat
operator|.
name|toUpper
argument_list|()
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|fileFormat
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
return|return
literal|false
return|;
block|}
else|else
block|{
return|return
name|scribbleArea
operator|->
name|saveImage
argument_list|(
name|fileName
argument_list|,
name|fileFormat
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
block|}
end_function
begin_comment
comment|//! [20]
end_comment
end_unit
