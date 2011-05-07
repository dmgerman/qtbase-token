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
parameter_list|()
block|{
name|QWidget
modifier|*
name|widget
init|=
operator|new
name|QWidget
decl_stmt|;
name|setCentralWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|QWidget
modifier|*
name|topFiller
init|=
operator|new
name|QWidget
decl_stmt|;
name|topFiller
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|infoLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"<i>Choose a menu option, or right-click to "
literal|"invoke a context menu</i>"
argument_list|)
argument_list|)
expr_stmt|;
name|infoLabel
operator|->
name|setFrameStyle
argument_list|(
name|QFrame
operator|::
name|StyledPanel
operator||
name|QFrame
operator|::
name|Sunken
argument_list|)
expr_stmt|;
name|infoLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|bottomFiller
init|=
operator|new
name|QWidget
decl_stmt|;
name|bottomFiller
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|setMargin
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|topFiller
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|infoLabel
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|bottomFiller
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|createActions
argument_list|()
expr_stmt|;
name|createMenus
argument_list|()
expr_stmt|;
name|QString
name|message
init|=
name|tr
argument_list|(
literal|"A context menu is available by right-clicking"
argument_list|)
decl_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Menus"
argument_list|)
argument_list|)
expr_stmt|;
name|setMinimumSize
argument_list|(
literal|160
argument_list|,
literal|160
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|480
argument_list|,
literal|320
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|contextMenuEvent
name|void
name|MainWindow
operator|::
name|contextMenuEvent
parameter_list|(
name|QContextMenuEvent
modifier|*
name|event
parameter_list|)
block|{
name|QMenu
name|menu
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|menu
operator|.
name|addAction
argument_list|(
name|cutAct
argument_list|)
expr_stmt|;
name|menu
operator|.
name|addAction
argument_list|(
name|copyAct
argument_list|)
expr_stmt|;
name|menu
operator|.
name|addAction
argument_list|(
name|pasteAct
argument_list|)
expr_stmt|;
name|menu
operator|.
name|exec
argument_list|(
name|event
operator|->
name|globalPos
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|newFile
name|void
name|MainWindow
operator|::
name|newFile
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>File|New</b>"
argument_list|)
argument_list|)
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
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>File|Open</b>"
argument_list|)
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
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>File|Save</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|print
name|void
name|MainWindow
operator|::
name|print
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>File|Print</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|undo
name|void
name|MainWindow
operator|::
name|undo
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Edit|Undo</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|redo
name|void
name|MainWindow
operator|::
name|redo
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Edit|Redo</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cut
name|void
name|MainWindow
operator|::
name|cut
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Edit|Cut</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|copy
name|void
name|MainWindow
operator|::
name|copy
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Edit|Copy</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paste
name|void
name|MainWindow
operator|::
name|paste
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Edit|Paste</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bold
name|void
name|MainWindow
operator|::
name|bold
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Edit|Format|Bold</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|italic
name|void
name|MainWindow
operator|::
name|italic
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Edit|Format|Italic</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|leftAlign
name|void
name|MainWindow
operator|::
name|leftAlign
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Edit|Format|Left Align</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rightAlign
name|void
name|MainWindow
operator|::
name|rightAlign
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Edit|Format|Right Align</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|justify
name|void
name|MainWindow
operator|::
name|justify
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Edit|Format|Justify</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|center
name|void
name|MainWindow
operator|::
name|center
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Edit|Format|Center</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setLineSpacing
name|void
name|MainWindow
operator|::
name|setLineSpacing
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Edit|Format|Set Line Spacing</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setParagraphSpacing
name|void
name|MainWindow
operator|::
name|setParagraphSpacing
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Edit|Format|Set Paragraph Spacing</b>"
argument_list|)
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
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Help|About</b>"
argument_list|)
argument_list|)
expr_stmt|;
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"About Menu"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The<b>Menu</b> example shows how to create "
literal|"menu-bar menus and context menus."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|aboutQt
name|void
name|MainWindow
operator|::
name|aboutQt
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invoked<b>Help|About Qt</b>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|createActions
name|void
name|MainWindow
operator|::
name|createActions
parameter_list|()
block|{
comment|//! [5]
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
comment|//! [4]
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
comment|//! [5]
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
name|printAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Print
argument_list|)
expr_stmt|;
name|printAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Print the document"
argument_list|)
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
name|this
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
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|undoAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Undo"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|undoAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Undo
argument_list|)
expr_stmt|;
name|undoAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Undo the last operation"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|undoAct
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
name|undo
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|redoAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Redo"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|redoAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Redo
argument_list|)
expr_stmt|;
name|redoAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Redo the last operation"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|redoAct
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
name|redo
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|cutAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Cu&t"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
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
name|cut
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|copyAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Copy"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
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
name|copy
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|pasteAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Paste"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
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
name|paste
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|boldAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Bold"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|boldAct
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|boldAct
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
operator|::
name|Bold
argument_list|)
expr_stmt|;
name|boldAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Make the text bold"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|boldAct
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
name|bold
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QFont
name|boldFont
init|=
name|boldAct
operator|->
name|font
argument_list|()
decl_stmt|;
name|boldFont
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|boldAct
operator|->
name|setFont
argument_list|(
name|boldFont
argument_list|)
expr_stmt|;
name|italicAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Italic"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|italicAct
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|italicAct
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
operator|::
name|Italic
argument_list|)
expr_stmt|;
name|italicAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Make the text italic"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|italicAct
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
name|italic
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QFont
name|italicFont
init|=
name|italicAct
operator|->
name|font
argument_list|()
decl_stmt|;
name|italicFont
operator|.
name|setItalic
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|italicAct
operator|->
name|setFont
argument_list|(
name|italicFont
argument_list|)
expr_stmt|;
name|setLineSpacingAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Set&Line Spacing..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|setLineSpacingAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Change the gap between the lines of a "
literal|"paragraph"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|setLineSpacingAct
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
name|setLineSpacing
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setParagraphSpacingAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Set&Paragraph Spacing..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|setLineSpacingAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Change the gap between paragraphs"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|setParagraphSpacingAct
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
name|setParagraphSpacing
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
name|this
argument_list|,
name|SLOT
argument_list|(
name|aboutQt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|leftAlignAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Left Align"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|leftAlignAct
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|leftAlignAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+L"
argument_list|)
argument_list|)
expr_stmt|;
name|leftAlignAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Left align the selected text"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|leftAlignAct
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
name|leftAlign
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|rightAlignAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Right Align"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|rightAlignAct
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|rightAlignAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+R"
argument_list|)
argument_list|)
expr_stmt|;
name|rightAlignAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Right align the selected text"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|rightAlignAct
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
name|rightAlign
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|justifyAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Justify"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|justifyAct
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|justifyAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+J"
argument_list|)
argument_list|)
expr_stmt|;
name|justifyAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Justify the selected text"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|justifyAct
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
name|justify
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|centerAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Center"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|centerAct
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|centerAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+E"
argument_list|)
argument_list|)
expr_stmt|;
name|centerAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Center the selected text"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|centerAct
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
name|center
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [6] //! [7]
name|alignmentGroup
operator|=
operator|new
name|QActionGroup
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|alignmentGroup
operator|->
name|addAction
argument_list|(
name|leftAlignAct
argument_list|)
expr_stmt|;
name|alignmentGroup
operator|->
name|addAction
argument_list|(
name|rightAlignAct
argument_list|)
expr_stmt|;
name|alignmentGroup
operator|->
name|addAction
argument_list|(
name|justifyAct
argument_list|)
expr_stmt|;
name|alignmentGroup
operator|->
name|addAction
argument_list|(
name|centerAct
argument_list|)
expr_stmt|;
name|leftAlignAct
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [6]
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|createMenus
name|void
name|MainWindow
operator|::
name|createMenus
parameter_list|()
block|{
comment|//! [9] //! [10]
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
comment|//! [9]
name|fileMenu
operator|->
name|addAction
argument_list|(
name|openAct
argument_list|)
expr_stmt|;
comment|//! [10]
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
name|printAct
argument_list|)
expr_stmt|;
comment|//! [11]
name|fileMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
comment|//! [11]
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exitAct
argument_list|)
expr_stmt|;
name|editMenu
operator|=
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
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
name|undoAct
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
name|redoAct
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
name|cutAct
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
name|copyAct
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
name|pasteAct
argument_list|)
expr_stmt|;
name|editMenu
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
comment|//! [8]
comment|//! [12]
name|formatMenu
operator|=
name|editMenu
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Format"
argument_list|)
argument_list|)
expr_stmt|;
name|formatMenu
operator|->
name|addAction
argument_list|(
name|boldAct
argument_list|)
expr_stmt|;
name|formatMenu
operator|->
name|addAction
argument_list|(
name|italicAct
argument_list|)
expr_stmt|;
name|formatMenu
operator|->
name|addSeparator
argument_list|()
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Alignment"
argument_list|)
argument_list|)
expr_stmt|;
name|formatMenu
operator|->
name|addAction
argument_list|(
name|leftAlignAct
argument_list|)
expr_stmt|;
name|formatMenu
operator|->
name|addAction
argument_list|(
name|rightAlignAct
argument_list|)
expr_stmt|;
name|formatMenu
operator|->
name|addAction
argument_list|(
name|justifyAct
argument_list|)
expr_stmt|;
name|formatMenu
operator|->
name|addAction
argument_list|(
name|centerAct
argument_list|)
expr_stmt|;
name|formatMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|formatMenu
operator|->
name|addAction
argument_list|(
name|setLineSpacingAct
argument_list|)
expr_stmt|;
name|formatMenu
operator|->
name|addAction
argument_list|(
name|setParagraphSpacingAct
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
end_unit
