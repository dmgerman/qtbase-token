begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_typedef
DECL|typedef|WordCountDialog
typedef|typedef
name|QDialog
name|WordCountDialog
typedef|;
end_typedef
begin_typedef
DECL|typedef|FindDialog
typedef|typedef
name|QDialog
name|FindDialog
typedef|;
end_typedef
begin_define
DECL|macro|this
define|#
directive|define
name|this
value|0
end_define
begin_define
DECL|macro|setWordCount
define|#
directive|define
name|setWordCount
parameter_list|(
name|x
parameter_list|)
value|isVisible()
end_define
begin_function
DECL|function|tr
name|QString
name|tr
parameter_list|(
specifier|const
name|char
modifier|*
name|text
parameter_list|)
block|{
return|return
name|QApplication
operator|::
name|translate
argument_list|(
name|text
argument_list|,
name|text
argument_list|)
return|;
block|}
end_function
begin_class
DECL|class|EditorWindow
class|class
name|EditorWindow
super|:
specifier|public
name|QMainWindow
block|{
public|public:
name|void
name|find
parameter_list|()
function_decl|;
name|void
name|countWords
parameter_list|()
function_decl|;
private|private:
DECL|member|findDialog
name|FindDialog
modifier|*
name|findDialog
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|find
name|void
name|EditorWindow
operator|::
name|find
parameter_list|()
block|{
if|if
condition|(
operator|!
name|findDialog
condition|)
block|{
name|findDialog
operator|=
operator|new
name|FindDialog
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|findDialog
argument_list|,
name|SIGNAL
argument_list|(
name|findNext
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|findNext
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|findDialog
operator|->
name|show
argument_list|()
expr_stmt|;
name|findDialog
operator|->
name|raise
argument_list|()
expr_stmt|;
name|findDialog
operator|->
name|activateWindow
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|countWords
name|void
name|EditorWindow
operator|::
name|countWords
parameter_list|()
block|{
name|WordCountDialog
name|dialog
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|dialog
operator|.
name|setWordCount
argument_list|(
name|document
argument_list|()
operator|.
name|wordCount
argument_list|()
argument_list|)
expr_stmt|;
name|dialog
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|boo
specifier|inline
name|bool
name|boo
parameter_list|()
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
literal|"Application name"
argument_list|,
literal|"Unable to find the user preferences file.\n"
literal|"The factory default will be used instead."
argument_list|)
expr_stmt|;
name|QString
name|filename
decl_stmt|;
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|filename
argument_list|)
operator|&&
name|QMessageBox
operator|::
name|question
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Overwrite File? -- Application Name"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"A file called %1 already exists."
literal|"Do you want to overwrite it?"
argument_list|)
operator|.
name|arg
argument_list|(
name|filename
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&Yes"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&No"
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
condition|)
return|return
literal|false
return|;
switch|switch
condition|(
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
literal|"Application name"
argument_list|,
literal|"Could not connect to the<mumble> server.\n"
literal|"This program can't function correctly "
literal|"without the server.\n\n"
argument_list|,
literal|"Retry"
argument_list|,
literal|"Quit"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
condition|)
block|{
case|case
literal|0
case|:
comment|// The user clicked the Retry again button or pressed Enter
comment|// try again
break|break;
case|case
literal|1
case|:
comment|// The user clicked the Quit or pressed Escape
comment|// exit
break|break;
block|}
switch|switch
condition|(
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
literal|"Application name here"
argument_list|,
literal|"The document contains unsaved changes\n"
literal|"Do you want to save the changes before exiting?"
argument_list|,
literal|"&Save"
argument_list|,
literal|"&Discard"
argument_list|,
literal|"Cancel"
argument_list|,
literal|0
argument_list|,
comment|// Enter == button 0
literal|2
argument_list|)
condition|)
block|{
comment|// Escape == button 2
case|case
literal|0
case|:
comment|// Save clicked or Alt+S pressed or Enter pressed.
comment|// save
break|break;
case|case
literal|1
case|:
comment|// Discard clicked or Alt+D pressed
comment|// don't save but exit
break|break;
case|case
literal|2
case|:
comment|// Cancel clicked or Escape pressed
comment|// don't exit
break|break;
block|}
switch|switch
condition|(
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
literal|"Application name here"
argument_list|,
literal|"Could not save the user preferences,\n"
literal|"because the disk is full. You can delete\n"
literal|"some files and press Retry, or you can\n"
literal|"abort the Save Preferences operation."
argument_list|,
name|QMessageBox
operator|::
name|Retry
operator||
name|QMessageBox
operator|::
name|Default
argument_list|,
name|QMessageBox
operator|::
name|Abort
operator||
name|QMessageBox
operator|::
name|Escape
argument_list|)
condition|)
block|{
case|case
name|QMessageBox
operator|::
name|Retry
case|:
comment|// Retry clicked or Enter pressed
comment|// try again
break|break;
case|case
name|QMessageBox
operator|::
name|Abort
case|:
comment|// Abort clicked or Escape pressed
comment|// abort
break|break;
block|}
name|QString
name|errorDetails
decl_stmt|;
name|QMessageBox
operator|::
name|critical
argument_list|(
literal|0
argument_list|,
literal|"Application name here"
argument_list|,
name|QString
argument_list|(
literal|"An internal error occurred. Please "
argument_list|)
operator|+
literal|"call technical support at 1234-56789 and report\n"
operator|+
literal|"these numbers:\n\n"
operator|+
name|errorDetails
operator|+
literal|"\n\nApplication will now exit."
argument_list|)
expr_stmt|;
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
literal|"About<Application>"
argument_list|,
literal|"<Application> is a<one-paragraph blurb>\n\n"
literal|"Copyright 1991-2003 Such-and-such. "
literal|"<License words here.>\n\n"
literal|"For technical support, call 1234-56789 or see\n"
literal|"http://www.such-and-such.com/Application/\n"
argument_list|)
expr_stmt|;
block|{
comment|// saving the file
name|QMessageBox
name|mb
argument_list|(
literal|"Application name here"
argument_list|,
literal|"Saving the file will overwrite the original file on the disk.\n"
literal|"Do you really want to save?"
argument_list|,
name|QMessageBox
operator|::
name|Information
argument_list|,
name|QMessageBox
operator|::
name|Yes
operator||
name|QMessageBox
operator|::
name|Default
argument_list|,
name|QMessageBox
operator|::
name|No
argument_list|,
name|QMessageBox
operator|::
name|Cancel
operator||
name|QMessageBox
operator|::
name|Escape
argument_list|)
decl_stmt|;
name|mb
operator|.
name|setButtonText
argument_list|(
name|QMessageBox
operator|::
name|Yes
argument_list|,
literal|"Save"
argument_list|)
expr_stmt|;
name|mb
operator|.
name|setButtonText
argument_list|(
name|QMessageBox
operator|::
name|No
argument_list|,
literal|"Discard"
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|mb
operator|.
name|exec
argument_list|()
condition|)
block|{
case|case
name|QMessageBox
operator|::
name|Yes
case|:
comment|// save and exit
break|break;
case|case
name|QMessageBox
operator|::
name|No
case|:
comment|// exit without saving
break|break;
case|case
name|QMessageBox
operator|::
name|Cancel
case|:
comment|// don't save and don't exit
break|break;
block|}
block|}
block|{
comment|// hardware failure
comment|//! [2]
name|QMessageBox
name|mb
argument_list|(
literal|"Application Name"
argument_list|,
literal|"Hardware failure.\n\nDisk error detected\nDo you want to stop?"
argument_list|,
name|QMessageBox
operator|::
name|Question
argument_list|,
name|QMessageBox
operator|::
name|Yes
operator||
name|QMessageBox
operator|::
name|Default
argument_list|,
name|QMessageBox
operator|::
name|No
operator||
name|QMessageBox
operator|::
name|Escape
argument_list|,
name|QMessageBox
operator|::
name|NoButton
argument_list|)
decl_stmt|;
if|if
condition|(
name|mb
operator|.
name|exec
argument_list|()
operator|==
name|QMessageBox
operator|::
name|No
condition|)
block|{
comment|// try again
comment|//! [2]
block|}
block|}
block|}
end_function
begin_function
DECL|function|moo
specifier|inline
name|void
name|moo
parameter_list|()
block|{
name|int
name|numFiles
decl_stmt|;
comment|//! [3]
name|QProgressDialog
name|progress
argument_list|(
literal|"Copying files..."
argument_list|,
literal|"Abort Copy"
argument_list|,
literal|0
argument_list|,
name|numFiles
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|progress
operator|.
name|setWindowModality
argument_list|(
name|Qt
operator|::
name|WindowModal
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
name|numFiles
condition|;
name|i
operator|++
control|)
block|{
name|progress
operator|.
name|setValue
argument_list|(
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|progress
operator|.
name|wasCanceled
argument_list|()
condition|)
break|break;
comment|//... copy one file
block|}
name|progress
operator|.
name|setValue
argument_list|(
name|numFiles
argument_list|)
expr_stmt|;
comment|//! [3]
block|}
end_function
begin_class
DECL|class|Operation
class|class
name|Operation
super|:
specifier|public
name|QObject
block|{
public|public:
name|Operation
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
constructor_decl|;
name|void
name|perform
parameter_list|()
function_decl|;
name|void
name|cancel
parameter_list|()
function_decl|;
private|private:
DECL|member|steps
name|int
name|steps
decl_stmt|;
DECL|member|pd
name|QProgressDialog
modifier|*
name|pd
decl_stmt|;
DECL|member|t
name|QTimer
modifier|*
name|t
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|// Operation constructor
end_comment
begin_constructor
DECL|function|Operation
name|Operation
operator|::
name|Operation
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|steps
argument_list|(
literal|0
argument_list|)
block|{
name|pd
operator|=
operator|new
name|QProgressDialog
argument_list|(
literal|"Operation in progress."
argument_list|,
literal|"Cancel"
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|pd
argument_list|,
name|SIGNAL
argument_list|(
name|canceled
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|cancel
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|t
operator|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|t
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|perform
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|t
operator|->
name|start
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [4] //! [5]
end_comment
begin_function
DECL|function|perform
name|void
name|Operation
operator|::
name|perform
parameter_list|()
block|{
name|pd
operator|->
name|setValue
argument_list|(
name|steps
argument_list|)
expr_stmt|;
comment|//... perform one percent of the operation
name|steps
operator|++
expr_stmt|;
if|if
condition|(
name|steps
operator|>
name|pd
operator|->
name|maximum
argument_list|()
condition|)
name|t
operator|->
name|stop
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5] //! [6]
end_comment
begin_function
DECL|function|cancel
name|void
name|Operation
operator|::
name|cancel
parameter_list|()
block|{
name|t
operator|->
name|stop
argument_list|()
expr_stmt|;
comment|//... cleanup
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{ }
end_function
end_unit
