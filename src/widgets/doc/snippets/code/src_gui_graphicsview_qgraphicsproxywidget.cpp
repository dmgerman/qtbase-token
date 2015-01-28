begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
modifier|*
name|argv
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
name|QTabWidget
modifier|*
name|tabWidget
init|=
operator|new
name|QTabWidget
decl_stmt|;
name|QGraphicsScene
name|scene
decl_stmt|;
name|QGraphicsProxyWidget
modifier|*
name|proxy
init|=
name|scene
operator|.
name|addWidget
argument_list|(
name|tabWidget
argument_list|)
decl_stmt|;
name|QGraphicsView
name|view
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
name|view
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
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|groupBox
name|QGroupBox
modifier|*
name|groupBox
init|=
operator|new
name|QGroupBox
argument_list|(
literal|"Contact Details"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|numberLabel
name|QLabel
modifier|*
name|numberLabel
init|=
operator|new
name|QLabel
argument_list|(
literal|"Telephone number"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|numberEdit
name|QLineEdit
modifier|*
name|numberEdit
init|=
operator|new
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|layout
name|QFormLayout
modifier|*
name|layout
init|=
operator|new
name|QFormLayout
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|layout
operator|->
name|addRow
argument_list|(
name|numberLabel
argument_list|,
name|numberEdit
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|groupBox
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|scene
name|QGraphicsScene
name|scene
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|proxy
name|QGraphicsProxyWidget
modifier|*
name|proxy
init|=
name|scene
operator|.
name|addWidget
argument_list|(
name|groupBox
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|scene
name|QGraphicsView
name|view
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|scene
name|QGraphicsScene
name|scene
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|edit
name|QLineEdit
modifier|*
name|edit
init|=
operator|new
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|proxy
name|QGraphicsProxyWidget
modifier|*
name|proxy
init|=
name|scene
operator|.
name|addWidget
argument_list|(
name|edit
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|edit
operator|->
name|isVisible
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true
end_comment
begin_expr_stmt
name|proxy
operator|->
name|isVisible
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// also returns true
end_comment
begin_expr_stmt
name|edit
operator|->
name|hide
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|edit
operator|->
name|isVisible
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns false
end_comment
begin_expr_stmt
name|proxy
operator|->
name|isVisible
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// also returns false
end_comment
begin_comment
comment|//! [2]
end_comment
end_unit
