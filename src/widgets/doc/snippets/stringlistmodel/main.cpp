begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     The main function for the string list model example. This creates and     populates a model with values from a string list then displays the     contents of the model using a QListView widget. */
end_comment
begin_include
include|#
directive|include
file|<QAbstractItemModel>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QListView>
end_include
begin_include
include|#
directive|include
file|"model.h"
end_include
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
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
comment|// Unindented for quoting purposes:
comment|//! [1]
name|QStringList
name|numbers
decl_stmt|;
name|numbers
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QAbstractItemModel
modifier|*
name|model
init|=
operator|new
name|StringListModel
argument_list|(
name|numbers
argument_list|)
decl_stmt|;
comment|//! [0] //! [1] //! [2] //! [3]
name|QListView
modifier|*
name|view
init|=
operator|new
name|QListView
decl_stmt|;
comment|//! [2]
name|view
operator|->
name|setWindowTitle
argument_list|(
literal|"View onto a string list model"
argument_list|)
expr_stmt|;
comment|//! [4]
name|view
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
comment|//! [3] //! [4]
name|model
operator|->
name|insertRows
argument_list|(
literal|5
argument_list|,
literal|7
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|row
init|=
literal|5
init|;
name|row
operator|<
literal|12
condition|;
operator|++
name|row
control|)
block|{
name|QModelIndex
name|index
init|=
name|model
operator|->
name|index
argument_list|(
name|row
argument_list|,
literal|0
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
decl_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|index
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|row
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//! [5]
name|view
operator|->
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
comment|//! [5]
end_comment
end_unit
