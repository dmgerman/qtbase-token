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
file|"finddialog.h"
end_include
begin_comment
comment|//! [0]
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
name|label
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Find&what:"
argument_list|)
argument_list|)
expr_stmt|;
name|lineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|label
operator|->
name|setBuddy
argument_list|(
name|lineEdit
argument_list|)
expr_stmt|;
name|caseCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Match&case"
argument_list|)
argument_list|)
expr_stmt|;
name|fromStartCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Search from&start"
argument_list|)
argument_list|)
expr_stmt|;
name|fromStartCheckBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [1]
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
name|setDefault
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|moreButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&More"
argument_list|)
argument_list|)
expr_stmt|;
name|moreButton
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [0]
name|moreButton
operator|->
name|setAutoDefault
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
operator|new
name|QDialogButtonBox
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|addButton
argument_list|(
name|findButton
argument_list|,
name|QDialogButtonBox
operator|::
name|ActionRole
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|addButton
argument_list|(
name|moreButton
argument_list|,
name|QDialogButtonBox
operator|::
name|ActionRole
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|extension
operator|=
operator|new
name|QWidget
expr_stmt|;
name|wholeWordsCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&Whole words"
argument_list|)
argument_list|)
expr_stmt|;
name|backwardCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Search&backward"
argument_list|)
argument_list|)
expr_stmt|;
name|searchSelectionCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Search se&lection"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|connect
argument_list|(
name|moreButton
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|extension
argument_list|,
name|SLOT
argument_list|(
name|setVisible
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|extensionLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|extensionLayout
operator|->
name|setMargin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|extensionLayout
operator|->
name|addWidget
argument_list|(
name|wholeWordsCheckBox
argument_list|)
expr_stmt|;
name|extensionLayout
operator|->
name|addWidget
argument_list|(
name|backwardCheckBox
argument_list|)
expr_stmt|;
name|extensionLayout
operator|->
name|addWidget
argument_list|(
name|searchSelectionCheckBox
argument_list|)
expr_stmt|;
name|extension
operator|->
name|setLayout
argument_list|(
name|extensionLayout
argument_list|)
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|QHBoxLayout
modifier|*
name|topLeftLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|topLeftLayout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|topLeftLayout
operator|->
name|addWidget
argument_list|(
name|lineEdit
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|leftLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|leftLayout
operator|->
name|addLayout
argument_list|(
name|topLeftLayout
argument_list|)
expr_stmt|;
name|leftLayout
operator|->
name|addWidget
argument_list|(
name|caseCheckBox
argument_list|)
expr_stmt|;
name|leftLayout
operator|->
name|addWidget
argument_list|(
name|fromStartCheckBox
argument_list|)
expr_stmt|;
name|leftLayout
operator|->
name|addStretch
argument_list|(
literal|1
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
name|setSizeConstraint
argument_list|(
name|QLayout
operator|::
name|SetFixedSize
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|leftLayout
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
name|buttonBox
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
name|extension
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
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
literal|"Extension"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [4] //! [5]
name|extension
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [5]
end_comment
end_unit
