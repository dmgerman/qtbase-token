begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ADDRESSBOOK_H
end_ifndef
begin_define
DECL|macro|ADDRESSBOOK_H
define|#
directive|define
name|ADDRESSBOOK_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|"finddialog.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextEdit
name|class
name|QTextEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|AddressBook
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|AddressBook
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;     enum
name|Mode
block|{
name|NavigationMode
block|,
name|AddingMode
block|,
name|EditingMode
block|}
block|;
name|public
name|slots
operator|:
name|void
name|addContact
argument_list|()
block|;
name|void
name|editContact
argument_list|()
block|;
name|void
name|submitContact
argument_list|()
block|;
name|void
name|cancel
argument_list|()
block|;
name|void
name|removeContact
argument_list|()
block|;
name|void
name|findContact
argument_list|()
block|;
name|void
name|next
argument_list|()
block|;
name|void
name|previous
argument_list|()
block|;
comment|//! [save and load functions declaration]
name|void
name|saveToFile
argument_list|()
block|;
name|void
name|loadFromFile
argument_list|()
block|;
comment|//! [save and load functions declaration]
name|private
operator|:
name|void
name|updateInterface
argument_list|(
argument|Mode mode
argument_list|)
block|;
name|QPushButton
operator|*
name|addButton
block|;
name|QPushButton
operator|*
name|editButton
block|;
name|QPushButton
operator|*
name|removeButton
block|;
name|QPushButton
operator|*
name|findButton
block|;
name|QPushButton
operator|*
name|submitButton
block|;
name|QPushButton
operator|*
name|cancelButton
block|;
name|QPushButton
operator|*
name|nextButton
block|;
name|QPushButton
operator|*
name|previousButton
block|;
comment|//! [save and load buttons declaration]
name|QPushButton
operator|*
name|loadButton
block|;
name|QPushButton
operator|*
name|saveButton
block|;
comment|//! [save and load buttons declaration]
name|QLineEdit
operator|*
name|nameLine
block|;
name|QTextEdit
operator|*
name|addressText
block|;
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
name|contacts
block|;
name|FindDialog
operator|*
name|dialog
block|;
name|QString
name|oldName
block|;
name|QString
name|oldAddress
block|;
name|Mode
name|currentMode
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
