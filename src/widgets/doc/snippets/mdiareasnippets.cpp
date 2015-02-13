begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_function
DECL|function|mainWindowExample
name|void
name|mainWindowExample
parameter_list|()
block|{
name|QMdiArea
modifier|*
name|mdiArea
init|=
operator|new
name|QMdiArea
decl_stmt|;
comment|//! [0]
name|QMainWindow
modifier|*
name|mainWindow
init|=
operator|new
name|QMainWindow
decl_stmt|;
name|mainWindow
operator|->
name|setCentralWidget
argument_list|(
name|mdiArea
argument_list|)
expr_stmt|;
comment|//! [0]
name|mdiArea
operator|->
name|addSubWindow
argument_list|(
operator|new
name|QPushButton
argument_list|(
literal|"Push Me Now!"
argument_list|)
argument_list|)
expr_stmt|;
name|mainWindow
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addingSubWindowsExample
name|void
name|addingSubWindowsExample
parameter_list|()
block|{
name|QWidget
modifier|*
name|internalWidget1
init|=
operator|new
name|QWidget
decl_stmt|;
name|QWidget
modifier|*
name|internalWidget2
init|=
operator|new
name|QWidget
decl_stmt|;
comment|//! [1]
name|QMdiArea
name|mdiArea
decl_stmt|;
name|QMdiSubWindow
modifier|*
name|subWindow1
init|=
operator|new
name|QMdiSubWindow
decl_stmt|;
name|subWindow1
operator|->
name|setWidget
argument_list|(
name|internalWidget1
argument_list|)
expr_stmt|;
name|subWindow1
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|mdiArea
operator|.
name|addSubWindow
argument_list|(
name|subWindow1
argument_list|)
expr_stmt|;
name|QMdiSubWindow
modifier|*
name|subWindow2
init|=
name|mdiArea
operator|.
name|addSubWindow
argument_list|(
name|internalWidget2
argument_list|)
decl_stmt|;
comment|//! [1]
name|subWindow1
operator|->
name|show
argument_list|()
expr_stmt|;
name|subWindow2
operator|->
name|show
argument_list|()
expr_stmt|;
name|mdiArea
operator|.
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argv
parameter_list|,
name|char
modifier|*
modifier|*
name|args
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argv
argument_list|,
name|args
argument_list|)
decl_stmt|;
name|mainWindowExample
argument_list|()
expr_stmt|;
comment|//addingSubWindowsExample();
name|QAction
modifier|*
name|act
init|=
operator|new
name|QAction
argument_list|(
name|qApp
argument_list|)
decl_stmt|;
name|act
operator|->
name|setShortcut
argument_list|(
name|Qt
operator|::
name|ALT
operator|+
name|Qt
operator|::
name|Key_S
argument_list|)
expr_stmt|;
name|act
operator|->
name|setShortcutContext
argument_list|(
name|Qt
operator|::
name|ApplicationShortcut
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|act
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|aboutQt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QWidget
name|widget5
decl_stmt|;
name|widget5
operator|.
name|show
argument_list|()
expr_stmt|;
name|widget5
operator|.
name|addAction
argument_list|(
name|act
argument_list|)
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
