begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [main program]
end_comment
begin_comment
comment|//! [first part]
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
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
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QWidget
name|window
decl_stmt|;
name|QLabel
modifier|*
name|queryLabel
init|=
operator|new
name|QLabel
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"nestedlayouts"
argument_list|,
literal|"Query:"
argument_list|)
argument_list|)
decl_stmt|;
name|QLineEdit
modifier|*
name|queryEdit
init|=
operator|new
name|QLineEdit
argument_list|()
decl_stmt|;
name|QTableView
modifier|*
name|resultView
init|=
operator|new
name|QTableView
argument_list|()
decl_stmt|;
name|QHBoxLayout
modifier|*
name|queryLayout
init|=
operator|new
name|QHBoxLayout
argument_list|()
decl_stmt|;
name|queryLayout
operator|->
name|addWidget
argument_list|(
name|queryLabel
argument_list|)
expr_stmt|;
name|queryLayout
operator|->
name|addWidget
argument_list|(
name|queryEdit
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
argument_list|()
decl_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|queryLayout
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|resultView
argument_list|)
expr_stmt|;
name|window
operator|.
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
comment|// Set up the model and configure the view...
comment|//! [first part]
comment|//! [set up the model]
name|QStandardItemModel
name|model
decl_stmt|;
name|model
operator|.
name|setHorizontalHeaderLabels
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"nestedlayouts"
argument_list|,
literal|"Name"
argument_list|)
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"nestedlayouts"
argument_list|,
literal|"Office"
argument_list|)
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QStringList
argument_list|>
name|rows
init|=
name|QList
argument_list|<
name|QStringList
argument_list|>
argument_list|()
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Verne Nilsen"
operator|<<
literal|"123"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Carlos Tang"
operator|<<
literal|"77"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Bronwyn Hawcroft"
operator|<<
literal|"119"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Alessandro Hanssen"
operator|<<
literal|"32"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Andrew John Bakken"
operator|<<
literal|"54"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Vanessa Weatherley"
operator|<<
literal|"85"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Rebecca Dickens"
operator|<<
literal|"17"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"David Bradley"
operator|<<
literal|"42"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Knut Walters"
operator|<<
literal|"25"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Andrea Jones"
operator|<<
literal|"34"
operator|)
decl_stmt|;
foreach|foreach
control|(
name|QStringList
name|row
decl|,
name|rows
control|)
block|{
name|QList
argument_list|<
name|QStandardItem
modifier|*
argument_list|>
name|items
decl_stmt|;
foreach|foreach
control|(
name|QString
name|text
decl|,
name|row
control|)
name|items
operator|.
name|append
argument_list|(
operator|new
name|QStandardItem
argument_list|(
name|text
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|.
name|appendRow
argument_list|(
name|items
argument_list|)
expr_stmt|;
block|}
name|resultView
operator|->
name|setModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|resultView
operator|->
name|verticalHeader
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
name|resultView
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setStretchLastSection
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [set up the model]
comment|//! [last part]
name|window
operator|.
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"nestedlayouts"
argument_list|,
literal|"Nested layouts"
argument_list|)
argument_list|)
expr_stmt|;
name|window
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
begin_comment
comment|//! [last part]
end_comment
begin_comment
comment|//! [main program]
end_comment
end_unit
