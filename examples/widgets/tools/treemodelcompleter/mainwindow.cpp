begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"treemodelcompleter.h"
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
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
member_init_list|,
name|completer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|lineEdit
argument_list|(
literal|0
argument_list|)
block|{
name|createMenu
argument_list|()
expr_stmt|;
name|completer
operator|=
operator|new
name|TreeModelCompleter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|completer
operator|->
name|setModel
argument_list|(
name|modelFromFile
argument_list|(
literal|":/resources/treemodel.txt"
argument_list|)
argument_list|)
expr_stmt|;
name|completer
operator|->
name|setSeparator
argument_list|(
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|completer
argument_list|,
name|SIGNAL
argument_list|(
name|highlighted
argument_list|(
name|QModelIndex
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|highlight
argument_list|(
name|QModelIndex
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|centralWidget
init|=
operator|new
name|QWidget
decl_stmt|;
name|QLabel
modifier|*
name|modelLabel
init|=
operator|new
name|QLabel
decl_stmt|;
name|modelLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Tree Model<br>(Double click items to edit)"
argument_list|)
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|modeLabel
init|=
operator|new
name|QLabel
decl_stmt|;
name|modeLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Completion Mode"
argument_list|)
argument_list|)
expr_stmt|;
name|modeCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|modeCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Inline"
argument_list|)
argument_list|)
expr_stmt|;
name|modeCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Filtered Popup"
argument_list|)
argument_list|)
expr_stmt|;
name|modeCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Unfiltered Popup"
argument_list|)
argument_list|)
expr_stmt|;
name|modeCombo
operator|->
name|setCurrentIndex
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|caseLabel
init|=
operator|new
name|QLabel
decl_stmt|;
name|caseLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Case Sensitivity"
argument_list|)
argument_list|)
expr_stmt|;
name|caseCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|caseCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Case Insensitive"
argument_list|)
argument_list|)
expr_stmt|;
name|caseCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Case Sensitive"
argument_list|)
argument_list|)
expr_stmt|;
name|caseCombo
operator|->
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|QLabel
modifier|*
name|separatorLabel
init|=
operator|new
name|QLabel
decl_stmt|;
name|separatorLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Tree Separator"
argument_list|)
argument_list|)
expr_stmt|;
name|QLineEdit
modifier|*
name|separatorLineEdit
init|=
operator|new
name|QLineEdit
decl_stmt|;
name|separatorLineEdit
operator|->
name|setText
argument_list|(
name|completer
operator|->
name|separator
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|separatorLineEdit
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|completer
argument_list|,
name|SLOT
argument_list|(
name|setSeparator
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCheckBox
modifier|*
name|wrapCheckBox
init|=
operator|new
name|QCheckBox
decl_stmt|;
name|wrapCheckBox
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Wrap around completions"
argument_list|)
argument_list|)
expr_stmt|;
name|wrapCheckBox
operator|->
name|setChecked
argument_list|(
name|completer
operator|->
name|wrapAround
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|wrapCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|completer
argument_list|,
name|SLOT
argument_list|(
name|setWrapAround
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|contentsLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|contentsLabel
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|separatorLineEdit
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateContentsLabel
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|treeView
operator|=
operator|new
name|QTreeView
expr_stmt|;
name|treeView
operator|->
name|setModel
argument_list|(
name|completer
operator|->
name|model
argument_list|()
argument_list|)
expr_stmt|;
name|treeView
operator|->
name|header
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
name|treeView
operator|->
name|expandAll
argument_list|()
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|connect
argument_list|(
name|modeCombo
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changeMode
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|caseCombo
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changeCase
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|lineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|lineEdit
operator|->
name|setCompleter
argument_list|(
name|completer
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|modelLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|treeView
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|modeLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|modeCombo
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|caseLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|caseCombo
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|separatorLabel
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|separatorLineEdit
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|wrapCheckBox
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|contentsLabel
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|lineEdit
argument_list|,
literal|6
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|centralWidget
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|centralWidget
argument_list|)
expr_stmt|;
name|changeCase
argument_list|(
name|caseCombo
operator|->
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|changeMode
argument_list|(
name|modeCombo
operator|->
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Tree Model Completer"
argument_list|)
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|createMenu
name|void
name|MainWindow
operator|::
name|createMenu
parameter_list|()
block|{
name|QAction
modifier|*
name|exitAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Exit"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|aboutAct
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"About"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|aboutQtAct
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"About Qt"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
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
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutAct
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
name|about
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutQtAct
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
literal|"File"
argument_list|)
argument_list|)
decl_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exitAction
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|helpMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"About"
argument_list|)
argument_list|)
decl_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutAct
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutQtAct
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|changeMode
name|void
name|MainWindow
operator|::
name|changeMode
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|QCompleter
operator|::
name|CompletionMode
name|mode
decl_stmt|;
if|if
condition|(
name|index
operator|==
literal|0
condition|)
name|mode
operator|=
name|QCompleter
operator|::
name|InlineCompletion
expr_stmt|;
elseif|else
if|if
condition|(
name|index
operator|==
literal|1
condition|)
name|mode
operator|=
name|QCompleter
operator|::
name|PopupCompletion
expr_stmt|;
else|else
name|mode
operator|=
name|QCompleter
operator|::
name|UnfilteredPopupCompletion
expr_stmt|;
name|completer
operator|->
name|setCompletionMode
argument_list|(
name|mode
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|modelFromFile
name|QAbstractItemModel
modifier|*
name|MainWindow
operator|::
name|modelFromFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
return|return
operator|new
name|QStringListModel
argument_list|(
name|completer
argument_list|)
return|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QApplication
operator|::
name|setOverrideCursor
argument_list|(
name|QCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QStringList
name|words
decl_stmt|;
name|QStandardItemModel
modifier|*
name|model
init|=
operator|new
name|QStandardItemModel
argument_list|(
name|completer
argument_list|)
decl_stmt|;
name|QVector
argument_list|<
name|QStandardItem
modifier|*
argument_list|>
name|parents
argument_list|(
literal|10
argument_list|)
decl_stmt|;
name|parents
index|[
literal|0
index|]
operator|=
name|model
operator|->
name|invisibleRootItem
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|file
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QString
name|line
init|=
name|file
operator|.
name|readLine
argument_list|()
decl_stmt|;
name|QString
name|trimmedLine
init|=
name|line
operator|.
name|trimmed
argument_list|()
decl_stmt|;
if|if
condition|(
name|line
operator|.
name|isEmpty
argument_list|()
operator|||
name|trimmedLine
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|QRegExp
name|re
argument_list|(
literal|"^\\s+"
argument_list|)
decl_stmt|;
name|int
name|nonws
init|=
name|re
operator|.
name|indexIn
argument_list|(
name|line
argument_list|)
decl_stmt|;
name|int
name|level
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|nonws
operator|==
operator|-
literal|1
condition|)
block|{
name|level
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
literal|"\t"
argument_list|)
condition|)
block|{
name|level
operator|=
name|re
operator|.
name|cap
argument_list|(
literal|0
argument_list|)
operator|.
name|length
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|level
operator|=
name|re
operator|.
name|cap
argument_list|(
literal|0
argument_list|)
operator|.
name|length
argument_list|()
operator|/
literal|4
expr_stmt|;
block|}
block|}
if|if
condition|(
name|level
operator|+
literal|1
operator|>=
name|parents
operator|.
name|size
argument_list|()
condition|)
name|parents
operator|.
name|resize
argument_list|(
name|parents
operator|.
name|size
argument_list|()
operator|*
literal|2
argument_list|)
expr_stmt|;
name|QStandardItem
modifier|*
name|item
init|=
operator|new
name|QStandardItem
decl_stmt|;
name|item
operator|->
name|setText
argument_list|(
name|trimmedLine
argument_list|)
expr_stmt|;
name|parents
index|[
name|level
index|]
operator|->
name|appendRow
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|parents
index|[
name|level
operator|+
literal|1
index|]
operator|=
name|item
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QApplication
operator|::
name|restoreOverrideCursor
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|model
return|;
block|}
end_function
begin_function
DECL|function|highlight
name|void
name|MainWindow
operator|::
name|highlight
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
block|{
name|QAbstractItemModel
modifier|*
name|completionModel
init|=
name|completer
operator|->
name|completionModel
argument_list|()
decl_stmt|;
name|QAbstractProxyModel
modifier|*
name|proxy
init|=
name|qobject_cast
argument_list|<
name|QAbstractProxyModel
operator|*
argument_list|>
argument_list|(
name|completionModel
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|proxy
condition|)
return|return;
name|QModelIndex
name|sourceIndex
init|=
name|proxy
operator|->
name|mapToSource
argument_list|(
name|index
argument_list|)
decl_stmt|;
name|treeView
operator|->
name|selectionModel
argument_list|()
operator|->
name|select
argument_list|(
name|sourceIndex
argument_list|,
name|QItemSelectionModel
operator|::
name|ClearAndSelect
operator||
name|QItemSelectionModel
operator|::
name|Rows
argument_list|)
expr_stmt|;
name|treeView
operator|->
name|scrollTo
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|about
name|void
name|MainWindow
operator|::
name|about
parameter_list|()
block|{
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"About"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"This example demonstrates how "
literal|"to use a QCompleter with a custom tree model."
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
DECL|function|changeCase
name|void
name|MainWindow
operator|::
name|changeCase
parameter_list|(
name|int
name|cs
parameter_list|)
block|{
name|completer
operator|->
name|setCaseSensitivity
argument_list|(
name|cs
condition|?
name|Qt
operator|::
name|CaseSensitive
else|:
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|updateContentsLabel
name|void
name|MainWindow
operator|::
name|updateContentsLabel
parameter_list|(
specifier|const
name|QString
modifier|&
name|sep
parameter_list|)
block|{
name|contentsLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Type path from model above with items at each level separated by a '%1'"
argument_list|)
operator|.
name|arg
argument_list|(
name|sep
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
