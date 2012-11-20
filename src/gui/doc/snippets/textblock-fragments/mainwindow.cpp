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
begin_include
include|#
directive|include
file|"xmlwriter.h"
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
literal|"&Save..."
argument_list|)
argument_list|)
decl_stmt|;
name|saveAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+S"
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
name|insertMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Insert"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|calendarAction
init|=
name|insertMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Calendar"
argument_list|)
argument_list|)
decl_stmt|;
name|calendarAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+I"
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
name|insertMenu
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
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|calendarAction
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
name|insertCalendar
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
literal|"Save document as:"
argument_list|)
argument_list|,
literal|""
argument_list|,
name|tr
argument_list|(
literal|"XML (*.xml)"
argument_list|)
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
if|if
condition|(
name|writeXml
argument_list|(
name|fileName
argument_list|)
condition|)
name|setWindowTitle
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
else|else
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Warning"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Failed to save the document."
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Cancel
argument_list|,
name|QMessageBox
operator|::
name|NoButton
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|insertCalendar
name|void
name|MainWindow
operator|::
name|insertCalendar
parameter_list|()
block|{
name|QTextCursor
name|cursor
argument_list|(
name|editor
operator|->
name|textCursor
argument_list|()
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|format
argument_list|(
name|cursor
operator|.
name|charFormat
argument_list|()
argument_list|)
decl_stmt|;
name|format
operator|.
name|setFontFamily
argument_list|(
literal|"Courier"
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|boldFormat
init|=
name|format
decl_stmt|;
name|boldFormat
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|" "
argument_list|,
name|boldFormat
argument_list|)
expr_stmt|;
name|QDate
name|date
init|=
name|QDate
operator|::
name|currentDate
argument_list|()
decl_stmt|;
name|int
name|year
init|=
name|date
operator|.
name|year
argument_list|()
decl_stmt|,
name|month
init|=
name|date
operator|.
name|month
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|weekDay
init|=
literal|1
init|;
name|weekDay
operator|<=
literal|7
condition|;
operator|++
name|weekDay
control|)
block|{
name|cursor
operator|.
name|insertText
argument_list|(
name|QString
argument_list|(
literal|"%1 "
argument_list|)
operator|.
name|arg
argument_list|(
name|QDate
operator|::
name|shortDayName
argument_list|(
name|weekDay
argument_list|)
argument_list|,
literal|3
argument_list|)
argument_list|,
name|boldFormat
argument_list|)
expr_stmt|;
block|}
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|" "
argument_list|,
name|format
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|column
init|=
literal|1
init|;
name|column
operator|<
name|QDate
argument_list|(
name|year
argument_list|,
name|month
argument_list|,
literal|1
argument_list|)
operator|.
name|dayOfWeek
argument_list|()
condition|;
operator|++
name|column
control|)
block|{
name|cursor
operator|.
name|insertText
argument_list|(
literal|"    "
argument_list|,
name|format
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|day
init|=
literal|1
init|;
name|day
operator|<=
name|date
operator|.
name|daysInMonth
argument_list|()
condition|;
operator|++
name|day
control|)
block|{
name|int
name|weekDay
init|=
name|QDate
argument_list|(
name|year
argument_list|,
name|month
argument_list|,
name|day
argument_list|)
operator|.
name|dayOfWeek
argument_list|()
decl_stmt|;
if|if
condition|(
name|QDate
argument_list|(
name|year
argument_list|,
name|month
argument_list|,
name|day
argument_list|)
operator|==
name|date
condition|)
name|cursor
operator|.
name|insertText
argument_list|(
name|QString
argument_list|(
literal|"%1 "
argument_list|)
operator|.
name|arg
argument_list|(
name|day
argument_list|,
literal|3
argument_list|)
argument_list|,
name|boldFormat
argument_list|)
expr_stmt|;
else|else
name|cursor
operator|.
name|insertText
argument_list|(
name|QString
argument_list|(
literal|"%1 "
argument_list|)
operator|.
name|arg
argument_list|(
name|day
argument_list|,
literal|3
argument_list|)
argument_list|,
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
name|weekDay
operator|==
literal|7
condition|)
block|{
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|" "
argument_list|,
name|format
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|writeXml
name|bool
name|MainWindow
operator|::
name|writeXml
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|XmlWriter
name|documentWriter
argument_list|(
name|editor
operator|->
name|document
argument_list|()
argument_list|)
decl_stmt|;
name|QDomDocument
modifier|*
name|domDocument
init|=
name|documentWriter
operator|.
name|toXml
argument_list|()
decl_stmt|;
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
name|WriteOnly
argument_list|)
condition|)
block|{
name|QTextStream
name|textStream
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|textStream
operator|<<
name|domDocument
operator|->
name|toByteArray
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
return|return
literal|false
return|;
block|}
end_function
end_unit
