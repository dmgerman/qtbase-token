begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"addressbook.h"
end_include
begin_constructor
DECL|function|AddressBook
name|AddressBook
operator|::
name|AddressBook
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
name|QLabel
modifier|*
name|nameLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Name:"
argument_list|)
argument_list|)
decl_stmt|;
name|nameLine
operator|=
operator|new
name|QLineEdit
expr_stmt|;
comment|//! [setting readonly 1]
name|nameLine
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [setting readonly 1]
name|QLabel
modifier|*
name|addressLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Address:"
argument_list|)
argument_list|)
decl_stmt|;
name|addressText
operator|=
operator|new
name|QTextEdit
expr_stmt|;
comment|//! [setting readonly 2]
name|addressText
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [setting readonly 2]
comment|//! [pushbutton declaration]
name|addButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Add"
argument_list|)
argument_list|)
expr_stmt|;
name|addButton
operator|->
name|show
argument_list|()
expr_stmt|;
name|submitButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Submit"
argument_list|)
argument_list|)
expr_stmt|;
name|submitButton
operator|->
name|hide
argument_list|()
expr_stmt|;
name|cancelButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Cancel"
argument_list|)
argument_list|)
expr_stmt|;
name|cancelButton
operator|->
name|hide
argument_list|()
expr_stmt|;
comment|//! [pushbutton declaration]
comment|//! [connecting signals and slots]
name|connect
argument_list|(
name|addButton
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
name|addContact
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|submitButton
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
name|submitContact
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|cancelButton
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
name|cancel
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [connecting signals and slots]
comment|//! [vertical layout]
name|QVBoxLayout
modifier|*
name|buttonLayout1
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|buttonLayout1
operator|->
name|addWidget
argument_list|(
name|addButton
argument_list|,
name|Qt
operator|::
name|AlignTop
argument_list|)
expr_stmt|;
name|buttonLayout1
operator|->
name|addWidget
argument_list|(
name|submitButton
argument_list|)
expr_stmt|;
name|buttonLayout1
operator|->
name|addWidget
argument_list|(
name|cancelButton
argument_list|)
expr_stmt|;
name|buttonLayout1
operator|->
name|addStretch
argument_list|()
expr_stmt|;
comment|//! [vertical layout]
comment|//! [grid layout]
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|nameLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|nameLine
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|addressLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
name|Qt
operator|::
name|AlignTop
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|addressText
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|buttonLayout1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|//! [grid layout]
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Simple Address Book"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [addContact]
end_comment
begin_function
DECL|function|addContact
name|void
name|AddressBook
operator|::
name|addContact
parameter_list|()
block|{
name|oldName
operator|=
name|nameLine
operator|->
name|text
argument_list|()
expr_stmt|;
name|oldAddress
operator|=
name|addressText
operator|->
name|toPlainText
argument_list|()
expr_stmt|;
name|nameLine
operator|->
name|clear
argument_list|()
expr_stmt|;
name|addressText
operator|->
name|clear
argument_list|()
expr_stmt|;
name|nameLine
operator|->
name|setReadOnly
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|nameLine
operator|->
name|setFocus
argument_list|(
name|Qt
operator|::
name|OtherFocusReason
argument_list|)
expr_stmt|;
name|addressText
operator|->
name|setReadOnly
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|addButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|submitButton
operator|->
name|show
argument_list|()
expr_stmt|;
name|cancelButton
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [addContact]
end_comment
begin_comment
comment|//! [submitContact part1]
end_comment
begin_function
DECL|function|submitContact
name|void
name|AddressBook
operator|::
name|submitContact
parameter_list|()
block|{
name|QString
name|name
init|=
name|nameLine
operator|->
name|text
argument_list|()
decl_stmt|;
name|QString
name|address
init|=
name|addressText
operator|->
name|toPlainText
argument_list|()
decl_stmt|;
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
operator|||
name|address
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
literal|"Please enter a name and address."
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
comment|//! [submitContact part1]
comment|//! [submitContact part2]
if|if
condition|(
operator|!
name|contacts
operator|.
name|contains
argument_list|(
name|name
argument_list|)
condition|)
block|{
name|contacts
operator|.
name|insert
argument_list|(
name|name
argument_list|,
name|address
argument_list|)
expr_stmt|;
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Add Successful"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"\"%1\" has been added to your address book."
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Add Unsuccessful"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Sorry, \"%1\" is already in your address book."
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
comment|//! [submitContact part2]
comment|//! [submitContact part3]
if|if
condition|(
name|contacts
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|nameLine
operator|->
name|clear
argument_list|()
expr_stmt|;
name|addressText
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
name|nameLine
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|addressText
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|addButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|submitButton
operator|->
name|hide
argument_list|()
expr_stmt|;
name|cancelButton
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [submitContact part3]
end_comment
begin_comment
comment|//! [cancel]
end_comment
begin_function
DECL|function|cancel
name|void
name|AddressBook
operator|::
name|cancel
parameter_list|()
block|{
name|nameLine
operator|->
name|setText
argument_list|(
name|oldName
argument_list|)
expr_stmt|;
name|nameLine
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|addressText
operator|->
name|setText
argument_list|(
name|oldAddress
argument_list|)
expr_stmt|;
name|addressText
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|addButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|submitButton
operator|->
name|hide
argument_list|()
expr_stmt|;
name|cancelButton
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [cancel]
end_comment
end_unit
