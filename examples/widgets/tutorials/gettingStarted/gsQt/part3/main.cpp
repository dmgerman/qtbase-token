begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_class
DECL|class|Notepad
class|class
name|Notepad
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
name|Notepad
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|quit
parameter_list|()
function_decl|;
private|private:
DECL|member|textEdit
name|QTextEdit
modifier|*
name|textEdit
decl_stmt|;
DECL|member|quitButton
name|QPushButton
modifier|*
name|quitButton
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|Notepad
name|Notepad
operator|::
name|Notepad
parameter_list|()
block|{
name|textEdit
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|quitButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Quit"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
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
name|addWidget
argument_list|(
name|textEdit
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|quitButton
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Notepad"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|quit
name|void
name|Notepad
operator|::
name|quit
parameter_list|()
block|{
name|QMessageBox
name|messageBox
decl_stmt|;
name|messageBox
operator|.
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Notepad"
argument_list|)
argument_list|)
expr_stmt|;
name|messageBox
operator|.
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Do you really want to quit?"
argument_list|)
argument_list|)
expr_stmt|;
name|messageBox
operator|.
name|setStandardButtons
argument_list|(
name|QMessageBox
operator|::
name|Yes
operator||
name|QMessageBox
operator|::
name|No
argument_list|)
expr_stmt|;
name|messageBox
operator|.
name|setDefaultButton
argument_list|(
name|QMessageBox
operator|::
name|No
argument_list|)
expr_stmt|;
if|if
condition|(
name|messageBox
operator|.
name|exec
argument_list|()
operator|==
name|QMessageBox
operator|::
name|Yes
condition|)
name|qApp
operator|->
name|quit
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|Notepad
name|notepad
decl_stmt|;
name|notepad
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
