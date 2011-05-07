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
file|"dialog.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Dialog
name|Dialog
operator|::
name|Dialog
parameter_list|()
block|{
name|createMenu
argument_list|()
expr_stmt|;
name|createHorizontalGroupBox
argument_list|()
expr_stmt|;
name|createGridGroupBox
argument_list|()
expr_stmt|;
name|createFormGroupBox
argument_list|()
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|bigEditor
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|bigEditor
operator|->
name|setPlainText
argument_list|(
name|tr
argument_list|(
literal|"This widget takes up all the remaining space "
literal|"in the top-level layout."
argument_list|)
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
operator|new
name|QDialogButtonBox
argument_list|(
name|QDialogButtonBox
operator|::
name|Ok
operator||
name|QDialogButtonBox
operator|::
name|Cancel
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
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
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|reject
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
comment|//! [2] //! [3]
name|mainLayout
operator|->
name|setMenuBar
argument_list|(
name|menuBar
argument_list|)
expr_stmt|;
comment|//! [3] //! [4]
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|horizontalGroupBox
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|gridGroupBox
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|formGroupBox
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|bigEditor
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
comment|//! [4] //! [5]
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Basic Layouts"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|createMenu
name|void
name|Dialog
operator|::
name|createMenu
parameter_list|()
block|{
name|menuBar
operator|=
operator|new
name|QMenuBar
expr_stmt|;
name|fileMenu
operator|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|exitAction
operator|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|)
expr_stmt|;
name|menuBar
operator|->
name|addMenu
argument_list|(
name|fileMenu
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|exitAction
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
name|accept
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|createHorizontalGroupBox
name|void
name|Dialog
operator|::
name|createHorizontalGroupBox
parameter_list|()
block|{
name|horizontalGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Horizontal layout"
argument_list|)
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumButtons
condition|;
operator|++
name|i
control|)
block|{
name|buttons
index|[
name|i
index|]
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Button %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|buttons
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|horizontalGroupBox
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|createGridGroupBox
name|void
name|Dialog
operator|::
name|createGridGroupBox
parameter_list|()
block|{
name|gridGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Grid layout"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [8]
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
comment|//! [9]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumGridRows
condition|;
operator|++
name|i
control|)
block|{
name|labels
index|[
name|i
index|]
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Line %1:"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|lineEdits
index|[
name|i
index|]
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|labels
index|[
name|i
index|]
argument_list|,
name|i
operator|+
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|lineEdits
index|[
name|i
index|]
argument_list|,
name|i
operator|+
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
comment|//! [9] //! [10]
name|smallEditor
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|smallEditor
operator|->
name|setPlainText
argument_list|(
name|tr
argument_list|(
literal|"This widget takes up about two thirds of the "
literal|"grid layout."
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|smallEditor
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|//! [10]
comment|//! [11]
name|layout
operator|->
name|setColumnStretch
argument_list|(
literal|1
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|layout
operator|->
name|setColumnStretch
argument_list|(
literal|2
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|gridGroupBox
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|createFormGroupBox
name|void
name|Dialog
operator|::
name|createFormGroupBox
parameter_list|()
block|{
name|formGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Form layout"
argument_list|)
argument_list|)
expr_stmt|;
name|QFormLayout
modifier|*
name|layout
init|=
operator|new
name|QFormLayout
decl_stmt|;
name|layout
operator|->
name|addRow
argument_list|(
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Line 1:"
argument_list|)
argument_list|)
argument_list|,
operator|new
name|QLineEdit
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addRow
argument_list|(
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Line 2, long text:"
argument_list|)
argument_list|)
argument_list|,
operator|new
name|QComboBox
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addRow
argument_list|(
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Line 3:"
argument_list|)
argument_list|)
argument_list|,
operator|new
name|QSpinBox
argument_list|)
expr_stmt|;
name|formGroupBox
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
end_unit
