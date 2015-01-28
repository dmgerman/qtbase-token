begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QMainWindow
argument_list|(
name|parent
argument_list|)
block|{
comment|//! [0]
comment|//! [1]
name|fileToolbar
operator|->
name|setAllowedAreas
argument_list|(
name|Qt
operator|::
name|TopToolBarArea
operator||
name|Qt
operator|::
name|BottomToolBarArea
argument_list|)
expr_stmt|;
name|addToolBar
argument_list|(
name|Qt
operator|::
name|TopToolBarArea
argument_list|,
name|fileToolbar
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|setCorner
argument_list|(
name|Qt
operator|::
name|TopLeftCorner
argument_list|,
name|Qt
operator|::
name|LeftDockWidgetArea
argument_list|)
expr_stmt|;
name|setCorner
argument_list|(
name|Qt
operator|::
name|BottomLeftCorner
argument_list|,
name|Qt
operator|::
name|LeftDockWidgetArea
argument_list|)
expr_stmt|;
name|setCorner
argument_list|(
name|Qt
operator|::
name|TopRightCorner
argument_list|,
name|Qt
operator|::
name|RightDockWidgetArea
argument_list|)
expr_stmt|;
name|setCorner
argument_list|(
name|Qt
operator|::
name|BottomRightCorner
argument_list|,
name|Qt
operator|::
name|RightDockWidgetArea
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|QWidget
modifier|*
name|centralWidget
init|=
operator|new
name|QWidget
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|setCentralWidget
argument_list|(
name|centralWidget
argument_list|)
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|QPopupMenu
modifier|*
name|fileMenu
init|=
operator|new
name|QPopupMenu
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|openAction
operator|->
name|addTo
argument_list|(
name|fileMenu
argument_list|)
expr_stmt|;
name|saveAction
operator|->
name|addTo
argument_list|(
name|fileMenu
argument_list|)
expr_stmt|;
operator|...
name|menuBar
argument_list|()
operator|->
name|insertItem
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|,
name|fileMenu
argument_list|)
expr_stmt|;
comment|//! [4]
comment|//! [5]
name|QMenu
modifier|*
name|fileMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
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
name|openAction
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAction
argument_list|)
expr_stmt|;
operator|...
comment|//! [5]
comment|//! [6]
name|QToolBar
operator|*
name|fileTools
operator|=
operator|new
name|QToolBar
argument_list|(
name|this
argument_list|,
literal|"file toolbar"
argument_list|)
expr_stmt|;
name|openAction
operator|->
name|addTo
argument_list|(
name|fileTools
argument_list|)
expr_stmt|;
name|saveAction
operator|->
name|addTo
argument_list|(
name|fileTools
argument_list|)
expr_stmt|;
operator|...
comment|//! [6]
comment|//! [7]
name|QToolBar
operator|*
name|fileTools
operator|=
name|addToolBar
argument_list|(
name|tr
argument_list|(
literal|"File Tool Bar"
argument_list|)
argument_list|)
expr_stmt|;
name|fileTools
operator|->
name|addAction
argument_list|(
name|openAction
argument_list|)
expr_stmt|;
name|fileTools
operator|->
name|addAction
argument_list|(
name|saveAction
argument_list|)
expr_stmt|;
operator|...
comment|//! [7]
comment|//! [8]
name|QDockWidget
operator|*
name|dockWidget
operator|=
operator|new
name|QDockWidget
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|mainWin
operator|->
name|moveDockWidget
argument_list|(
name|dockWidget
argument_list|,
name|Qt
operator|::
name|DockLeft
argument_list|)
expr_stmt|;
comment|//! [8]
comment|//! [9]
name|QDockWidget
modifier|*
name|dockWidget
init|=
operator|new
name|QDockWidget
argument_list|(
name|mainWindow
argument_list|)
decl_stmt|;
name|mainWindow
operator|->
name|addDockWidget
argument_list|(
name|Qt
operator|::
name|LeftDockWidgetArea
argument_list|,
name|dockWidget
argument_list|)
expr_stmt|;
end_constructor
begin_comment
comment|//! [9]
end_comment
end_unit
