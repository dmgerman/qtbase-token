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
name|nameLine
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
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
name|addressText
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
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
name|editButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Edit"
argument_list|)
argument_list|)
expr_stmt|;
name|editButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|removeButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Remove"
argument_list|)
argument_list|)
expr_stmt|;
name|removeButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
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
name|findButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
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
name|nextButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Next"
argument_list|)
argument_list|)
expr_stmt|;
name|nextButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|previousButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Previous"
argument_list|)
argument_list|)
expr_stmt|;
name|previousButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|loadButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Load..."
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [tooltip 1]
name|loadButton
operator|->
name|setToolTip
argument_list|(
name|tr
argument_list|(
literal|"Load contacts from a file"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [tooltip 1]
name|saveButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Save..."
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [tooltip 2]
name|saveButton
operator|->
name|setToolTip
argument_list|(
name|tr
argument_list|(
literal|"Save contacts to a file"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [tooltip 2]
name|saveButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|dialog
operator|=
operator|new
name|FindDialog
expr_stmt|;
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
name|editButton
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
name|editContact
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
name|connect
argument_list|(
name|removeButton
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
name|removeContact
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
name|findContact
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|nextButton
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
name|next
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|previousButton
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
name|previous
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|loadButton
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
name|loadFromFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveButton
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
name|saveToFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
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
argument_list|)
expr_stmt|;
name|buttonLayout1
operator|->
name|addWidget
argument_list|(
name|editButton
argument_list|)
expr_stmt|;
name|buttonLayout1
operator|->
name|addWidget
argument_list|(
name|removeButton
argument_list|)
expr_stmt|;
name|buttonLayout1
operator|->
name|addWidget
argument_list|(
name|findButton
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
name|addWidget
argument_list|(
name|loadButton
argument_list|)
expr_stmt|;
name|buttonLayout1
operator|->
name|addWidget
argument_list|(
name|saveButton
argument_list|)
expr_stmt|;
name|buttonLayout1
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|QHBoxLayout
modifier|*
name|buttonLayout2
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|buttonLayout2
operator|->
name|addWidget
argument_list|(
name|previousButton
argument_list|)
expr_stmt|;
name|buttonLayout2
operator|->
name|addWidget
argument_list|(
name|nextButton
argument_list|)
expr_stmt|;
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
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|buttonLayout2
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
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
name|updateInterface
argument_list|(
name|AddingMode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|editContact
name|void
name|AddressBook
operator|::
name|editContact
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
name|updateInterface
argument_list|(
name|EditingMode
argument_list|)
expr_stmt|;
block|}
end_function
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
if|if
condition|(
name|currentMode
operator|==
name|AddingMode
condition|)
block|{
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
block|}
block|}
elseif|else
if|if
condition|(
name|currentMode
operator|==
name|EditingMode
condition|)
block|{
if|if
condition|(
name|oldName
operator|!=
name|name
condition|)
block|{
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
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Edit Successful"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"\"%1\" has been edited in your address book."
argument_list|)
operator|.
name|arg
argument_list|(
name|oldName
argument_list|)
argument_list|)
expr_stmt|;
name|contacts
operator|.
name|remove
argument_list|(
name|oldName
argument_list|)
expr_stmt|;
name|contacts
operator|.
name|insert
argument_list|(
name|name
argument_list|,
name|address
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
literal|"Edit Unsuccessful"
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
block|}
block|}
elseif|else
if|if
condition|(
name|oldAddress
operator|!=
name|address
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
literal|"Edit Successful"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"\"%1\" has been edited in your address book."
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
name|contacts
index|[
name|name
index|]
operator|=
name|address
expr_stmt|;
block|}
block|}
name|updateInterface
argument_list|(
name|NavigationMode
argument_list|)
expr_stmt|;
block|}
end_function
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
name|addressText
operator|->
name|setText
argument_list|(
name|oldAddress
argument_list|)
expr_stmt|;
name|updateInterface
argument_list|(
name|NavigationMode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeContact
name|void
name|AddressBook
operator|::
name|removeContact
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
name|contacts
operator|.
name|contains
argument_list|(
name|name
argument_list|)
condition|)
block|{
name|int
name|button
init|=
name|QMessageBox
operator|::
name|question
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Confirm Remove"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Are you sure you want to remove \"%1\"?"
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Yes
operator||
name|QMessageBox
operator|::
name|No
argument_list|)
decl_stmt|;
if|if
condition|(
name|button
operator|==
name|QMessageBox
operator|::
name|Yes
condition|)
block|{
name|previous
argument_list|()
expr_stmt|;
name|contacts
operator|.
name|remove
argument_list|(
name|name
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
literal|"Remove Successful"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"\"%1\" has been removed from your address book."
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|updateInterface
argument_list|(
name|NavigationMode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|next
name|void
name|AddressBook
operator|::
name|next
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
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
operator|::
name|iterator
name|i
init|=
name|contacts
operator|.
name|find
argument_list|(
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|!=
name|contacts
operator|.
name|end
argument_list|()
condition|)
name|i
operator|++
expr_stmt|;
if|if
condition|(
name|i
operator|==
name|contacts
operator|.
name|end
argument_list|()
condition|)
name|i
operator|=
name|contacts
operator|.
name|begin
argument_list|()
expr_stmt|;
name|nameLine
operator|->
name|setText
argument_list|(
name|i
operator|.
name|key
argument_list|()
argument_list|)
expr_stmt|;
name|addressText
operator|->
name|setText
argument_list|(
name|i
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|previous
name|void
name|AddressBook
operator|::
name|previous
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
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
operator|::
name|iterator
name|i
init|=
name|contacts
operator|.
name|find
argument_list|(
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|==
name|contacts
operator|.
name|end
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
return|return;
block|}
if|if
condition|(
name|i
operator|==
name|contacts
operator|.
name|begin
argument_list|()
condition|)
name|i
operator|=
name|contacts
operator|.
name|end
argument_list|()
expr_stmt|;
name|i
operator|--
expr_stmt|;
name|nameLine
operator|->
name|setText
argument_list|(
name|i
operator|.
name|key
argument_list|()
argument_list|)
expr_stmt|;
name|addressText
operator|->
name|setText
argument_list|(
name|i
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|findContact
name|void
name|AddressBook
operator|::
name|findContact
parameter_list|()
block|{
name|dialog
operator|->
name|show
argument_list|()
expr_stmt|;
if|if
condition|(
name|dialog
operator|->
name|exec
argument_list|()
operator|==
literal|1
condition|)
block|{
name|QString
name|contactName
init|=
name|dialog
operator|->
name|getFindText
argument_list|()
decl_stmt|;
if|if
condition|(
name|contacts
operator|.
name|contains
argument_list|(
name|contactName
argument_list|)
condition|)
block|{
name|nameLine
operator|->
name|setText
argument_list|(
name|contactName
argument_list|)
expr_stmt|;
name|addressText
operator|->
name|setText
argument_list|(
name|contacts
operator|.
name|value
argument_list|(
name|contactName
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
literal|"Contact Not Found"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Sorry, \"%1\" is not in your address book."
argument_list|)
operator|.
name|arg
argument_list|(
name|contactName
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|updateInterface
argument_list|(
name|NavigationMode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateInterface
name|void
name|AddressBook
operator|::
name|updateInterface
parameter_list|(
name|Mode
name|mode
parameter_list|)
block|{
name|currentMode
operator|=
name|mode
expr_stmt|;
switch|switch
condition|(
name|currentMode
condition|)
block|{
case|case
name|AddingMode
case|:
case|case
name|EditingMode
case|:
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
name|editButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|removeButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|nextButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|previousButton
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
name|loadButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|saveButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
break|break;
case|case
name|NavigationMode
case|:
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
name|int
name|number
init|=
name|contacts
operator|.
name|size
argument_list|()
decl_stmt|;
name|editButton
operator|->
name|setEnabled
argument_list|(
name|number
operator|>=
literal|1
argument_list|)
expr_stmt|;
name|removeButton
operator|->
name|setEnabled
argument_list|(
name|number
operator|>=
literal|1
argument_list|)
expr_stmt|;
name|findButton
operator|->
name|setEnabled
argument_list|(
name|number
operator|>
literal|2
argument_list|)
expr_stmt|;
name|nextButton
operator|->
name|setEnabled
argument_list|(
name|number
operator|>
literal|1
argument_list|)
expr_stmt|;
name|previousButton
operator|->
name|setEnabled
argument_list|(
name|number
operator|>
literal|1
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
name|loadButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|saveButton
operator|->
name|setEnabled
argument_list|(
name|number
operator|>=
literal|1
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function
begin_comment
comment|//! [saveToFile() function part1]
end_comment
begin_function
DECL|function|saveToFile
name|void
name|AddressBook
operator|::
name|saveToFile
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
literal|"Save Address Book"
argument_list|)
argument_list|,
literal|""
argument_list|,
name|tr
argument_list|(
literal|"Address Book (*.abk);;All Files (*)"
argument_list|)
argument_list|)
decl_stmt|;
comment|//! [saveToFile() function part1]
comment|//! [saveToFile() function part2]
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
else|else
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
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
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
literal|"Unable to open file"
argument_list|)
argument_list|,
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
comment|//! [saveToFile() function part2]
comment|//! [saveToFile() function part3]
name|QDataStream
name|out
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|out
operator|.
name|setVersion
argument_list|(
name|QDataStream
operator|::
name|Qt_4_5
argument_list|)
expr_stmt|;
name|out
operator|<<
name|contacts
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [saveToFile() function part3]
end_comment
begin_comment
comment|//! [loadFromFile() function part1]
end_comment
begin_function
DECL|function|loadFromFile
name|void
name|AddressBook
operator|::
name|loadFromFile
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
argument_list|,
name|tr
argument_list|(
literal|"Open Address Book"
argument_list|)
argument_list|,
literal|""
argument_list|,
name|tr
argument_list|(
literal|"Address Book (*.abk);;All Files (*)"
argument_list|)
argument_list|)
decl_stmt|;
comment|//! [loadFromFile() function part1]
comment|//! [loadFromFile() function part2]
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
else|else
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
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
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
literal|"Unable to open file"
argument_list|)
argument_list|,
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|QDataStream
name|in
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|in
operator|.
name|setVersion
argument_list|(
name|QDataStream
operator|::
name|Qt_4_5
argument_list|)
expr_stmt|;
name|contacts
operator|.
name|empty
argument_list|()
expr_stmt|;
comment|// empty existing contacts
name|in
operator|>>
name|contacts
expr_stmt|;
comment|//! [loadFromFile() function part2]
comment|//! [loadFromFile() function part3]
if|if
condition|(
name|contacts
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
literal|"No contacts in file"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The file you are attempting to open contains no contacts."
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
operator|::
name|iterator
name|i
init|=
name|contacts
operator|.
name|begin
argument_list|()
decl_stmt|;
name|nameLine
operator|->
name|setText
argument_list|(
name|i
operator|.
name|key
argument_list|()
argument_list|)
expr_stmt|;
name|addressText
operator|->
name|setText
argument_list|(
name|i
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|updateInterface
argument_list|(
name|NavigationMode
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [loadFromFile() function part3]
end_comment
end_unit
