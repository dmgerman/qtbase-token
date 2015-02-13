begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
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
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
operator|::
name|setDesktopSettingsAware
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
operator|...
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_constructor
DECL|function|MyMainWidget
name|MyMainWidget
operator|::
name|MyMainWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|connect
argument_list|(
name|qApp
argument_list|,
name|SIGNAL
argument_list|(
name|commitDataRequest
argument_list|(
name|QSessionManager
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|commitData
argument_list|(
name|QSessionManager
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|commitData
name|void
name|MyMainWidget
operator|::
name|commitData
parameter_list|(
name|QSessionManager
modifier|&
name|manager
parameter_list|)
block|{
if|if
condition|(
name|manager
operator|.
name|allowsInteraction
argument_list|()
condition|)
block|{
name|int
name|ret
init|=
name|QMessageBox
operator|::
name|warning
argument_list|(
name|mainWindow
argument_list|,
name|tr
argument_list|(
literal|"My Application"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Save changes to document?"
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
name|manager
operator|.
name|release
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|saveDocument
argument_list|()
condition|)
name|manager
operator|.
name|cancel
argument_list|()
expr_stmt|;
break|break;
case|case
name|QMessageBox
operator|::
name|Discard
case|:
break|break;
case|case
name|QMessageBox
operator|::
name|Cancel
case|:
default|default:
name|manager
operator|.
name|cancel
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// we did not get permission to interact, then
comment|// do something reasonable instead
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_expr_stmt
name|appname
operator|-
name|session
name|id
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_foreach
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|command
decl|,
name|mySession
operator|.
name|restartCommand
argument_list|()
control|)
DECL|variable|command
name|do_something
argument_list|(
name|command
argument_list|)
expr_stmt|;
end_foreach
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_foreach
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|command
decl|,
name|mySession
operator|.
name|discardCommand
argument_list|()
control|)
DECL|variable|command
name|do_something
argument_list|(
name|command
argument_list|)
expr_stmt|;
end_foreach
begin_comment
comment|//! [4]
end_comment
end_unit
