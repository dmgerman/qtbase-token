begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"finddialog.h"
end_include
begin_comment
comment|//! [constructor]
end_comment
begin_constructor
DECL|function|FindDialog
name|FindDialog
operator|::
name|FindDialog
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
block|{
name|QLabel
modifier|*
name|findLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Enter the name of a contact:"
argument_list|)
argument_list|)
decl_stmt|;
name|lineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|findButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Find"
argument_list|)
argument_list|)
expr_stmt|;
name|findText
operator|=
literal|""
expr_stmt|;
name|QHBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|findLabel
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|lineEdit
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|findButton
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
literal|"Find a Contact"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|findButton
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
name|findClicked
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|findButton
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
name|accept
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [constructor]
end_comment
begin_comment
comment|//! [findClicked() function]
end_comment
begin_function
DECL|function|findClicked
name|void
name|FindDialog
operator|::
name|findClicked
parameter_list|()
block|{
name|QString
name|text
init|=
name|lineEdit
operator|->
name|text
argument_list|()
decl_stmt|;
if|if
condition|(
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Empty Field"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Please enter a name."
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
else|else
block|{
name|findText
operator|=
name|text
expr_stmt|;
name|lineEdit
operator|->
name|clear
argument_list|()
expr_stmt|;
name|hide
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [findClicked() function]
end_comment
begin_comment
comment|//! [getFindText() function]
end_comment
begin_function
DECL|function|getFindText
name|QString
name|FindDialog
operator|::
name|getFindText
parameter_list|()
block|{
return|return
name|findText
return|;
block|}
end_function
begin_comment
comment|//! [getFindText() function]
end_comment
end_unit
