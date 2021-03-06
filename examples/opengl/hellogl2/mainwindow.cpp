begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_include
include|#
directive|include
file|<QMenuBar>
end_include
begin_include
include|#
directive|include
file|<QMenu>
end_include
begin_include
include|#
directive|include
file|<QMessageBox>
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|QMenuBar
modifier|*
name|menuBar
init|=
operator|new
name|QMenuBar
decl_stmt|;
name|QMenu
modifier|*
name|menuWindow
init|=
name|menuBar
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Window"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|addNew
init|=
operator|new
name|QAction
argument_list|(
name|menuWindow
argument_list|)
decl_stmt|;
name|addNew
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Add new"
argument_list|)
argument_list|)
expr_stmt|;
name|menuWindow
operator|->
name|addAction
argument_list|(
name|addNew
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|addNew
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|onAddNew
argument_list|)
expr_stmt|;
name|setMenuBar
argument_list|(
name|menuBar
argument_list|)
expr_stmt|;
name|onAddNew
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|onAddNew
name|void
name|MainWindow
operator|::
name|onAddNew
parameter_list|()
block|{
if|if
condition|(
operator|!
name|centralWidget
argument_list|()
condition|)
name|setCentralWidget
argument_list|(
operator|new
name|Window
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|QMessageBox
operator|::
name|information
argument_list|(
literal|0
argument_list|,
name|tr
argument_list|(
literal|"Cannot add new window"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Already occupied. Undock first."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
