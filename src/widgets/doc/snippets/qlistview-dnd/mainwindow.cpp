begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"model.h"
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
name|QAction
modifier|*
name|quitAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|)
decl_stmt|;
name|quitAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+Q"
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
comment|//  For convenient quoting:
comment|//! [0]
name|QListView
modifier|*
name|listView
init|=
operator|new
name|QListView
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|listView
operator|->
name|setSelectionMode
argument_list|(
name|QAbstractItemView
operator|::
name|ExtendedSelection
argument_list|)
expr_stmt|;
name|listView
operator|->
name|setDragEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|listView
operator|->
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|listView
operator|->
name|setDropIndicatorShown
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [0]
name|this
operator|->
name|listView
operator|=
name|listView
expr_stmt|;
name|connect
argument_list|(
name|quitAction
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
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setupListItems
argument_list|()
expr_stmt|;
name|setCentralWidget
argument_list|(
name|listView
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"List View"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setupListItems
name|void
name|MainWindow
operator|::
name|setupListItems
parameter_list|()
block|{
name|QStringList
name|items
decl_stmt|;
name|items
operator|<<
name|tr
argument_list|(
literal|"Oak"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Fir"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Pine"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Birch"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Hazel"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Redwood"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Sycamore"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Chestnut"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Mahogany"
argument_list|)
expr_stmt|;
name|DragDropListModel
modifier|*
name|model
init|=
operator|new
name|DragDropListModel
argument_list|(
name|items
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|listView
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
