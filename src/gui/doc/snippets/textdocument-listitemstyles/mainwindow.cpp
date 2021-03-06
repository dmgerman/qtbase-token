begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|QMenu
modifier|*
name|fileMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
decl_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|,
name|QKeySequence
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+Q"
argument_list|,
literal|"File|Exit"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|insertMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Insert"
argument_list|)
argument_list|)
decl_stmt|;
name|insertMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&List"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|insertList
argument_list|()
argument_list|)
argument_list|,
name|QKeySequence
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+L"
argument_list|,
literal|"Insert|List"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|fileMenu
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|insertMenu
argument_list|)
expr_stmt|;
name|editor
operator|=
operator|new
name|QTextEdit
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|document
operator|=
operator|new
name|QTextDocument
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|editor
operator|->
name|setDocument
argument_list|(
name|document
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|editor
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Text Document List Item Styles"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|insertList
name|void
name|MainWindow
operator|::
name|insertList
parameter_list|()
block|{
name|QTextCursor
name|cursor
init|=
name|editor
operator|->
name|textCursor
argument_list|()
decl_stmt|;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
comment|//! [add a styled, ordered list]
name|QTextListFormat
name|listFormat
decl_stmt|;
name|listFormat
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListDecimal
argument_list|)
expr_stmt|;
name|listFormat
operator|.
name|setNumberPrefix
argument_list|(
literal|"("
argument_list|)
expr_stmt|;
name|listFormat
operator|.
name|setNumberSuffix
argument_list|(
literal|")"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertList
argument_list|(
name|listFormat
argument_list|)
expr_stmt|;
comment|//! [add a styled, ordered list]
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
