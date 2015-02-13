begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|createMenus
argument_list|()
expr_stmt|;
name|createToolBars
argument_list|()
expr_stmt|;
name|createDockWidgets
argument_list|()
expr_stmt|;
comment|//setMenuWidget(new QPushButton("Hello"));
block|}
end_constructor
begin_function
DECL|function|createMenus
name|void
name|MainWindow
operator|::
name|createMenus
parameter_list|()
block|{
comment|//setMenuWidget(new QPushButton("Hello"));
name|QMenu
modifier|*
name|menu
init|=
operator|new
name|QMenu
argument_list|(
literal|"File"
argument_list|)
decl_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
literal|"Save&As"
argument_list|)
expr_stmt|;
name|QMenuBar
modifier|*
name|bar
init|=
operator|new
name|QMenuBar
decl_stmt|;
name|bar
operator|->
name|addMenu
argument_list|(
name|menu
argument_list|)
expr_stmt|;
name|setMenuWidget
argument_list|(
operator|new
name|QWidget
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createToolBars
name|void
name|MainWindow
operator|::
name|createToolBars
parameter_list|()
block|{
name|setToolButtonStyle
argument_list|(
name|Qt
operator|::
name|ToolButtonTextOnly
argument_list|)
expr_stmt|;
name|QToolBar
modifier|*
name|t1
init|=
operator|new
name|QToolBar
decl_stmt|;
name|t1
operator|->
name|addAction
argument_list|(
operator|new
name|QAction
argument_list|(
literal|"t1"
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|QToolBar
modifier|*
name|t2
init|=
operator|new
name|QToolBar
decl_stmt|;
name|t2
operator|->
name|addAction
argument_list|(
operator|new
name|QAction
argument_list|(
literal|"t2"
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|addToolBar
argument_list|(
name|Qt
operator|::
name|LeftToolBarArea
argument_list|,
name|t1
argument_list|)
expr_stmt|;
name|addToolBar
argument_list|(
name|Qt
operator|::
name|LeftToolBarArea
argument_list|,
name|t2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createDockWidgets
name|void
name|MainWindow
operator|::
name|createDockWidgets
parameter_list|()
block|{
name|QWidget
modifier|*
name|dockWidgetContents
init|=
operator|new
name|QWidget
decl_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
operator|new
name|QPushButton
argument_list|(
literal|"My Button."
argument_list|)
argument_list|)
expr_stmt|;
name|dockWidgetContents
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
comment|//! [0]
name|QDockWidget
modifier|*
name|dockWidget
init|=
operator|new
name|QDockWidget
argument_list|(
name|tr
argument_list|(
literal|"Dock Widget"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|dockWidget
operator|->
name|setAllowedAreas
argument_list|(
name|Qt
operator|::
name|LeftDockWidgetArea
operator||
name|Qt
operator|::
name|RightDockWidgetArea
argument_list|)
expr_stmt|;
name|dockWidget
operator|->
name|setWidget
argument_list|(
name|dockWidgetContents
argument_list|)
expr_stmt|;
name|addDockWidget
argument_list|(
name|Qt
operator|::
name|LeftDockWidgetArea
argument_list|,
name|dockWidget
argument_list|)
expr_stmt|;
comment|//! [0]
block|}
end_function
end_unit
