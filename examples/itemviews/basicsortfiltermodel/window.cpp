begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|()
block|{
name|proxyModel
operator|=
operator|new
name|QSortFilterProxyModel
expr_stmt|;
name|proxyModel
operator|->
name|setDynamicSortFilter
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|sourceView
operator|=
operator|new
name|QTreeView
expr_stmt|;
name|sourceView
operator|->
name|setRootIsDecorated
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|sourceView
operator|->
name|setAlternatingRowColors
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|proxyView
operator|=
operator|new
name|QTreeView
expr_stmt|;
name|proxyView
operator|->
name|setRootIsDecorated
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|proxyView
operator|->
name|setAlternatingRowColors
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|proxyView
operator|->
name|setModel
argument_list|(
name|proxyModel
argument_list|)
expr_stmt|;
name|proxyView
operator|->
name|setSortingEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|sortCaseSensitivityCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Case sensitive sorting"
argument_list|)
argument_list|)
expr_stmt|;
name|filterCaseSensitivityCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Case sensitive filter"
argument_list|)
argument_list|)
expr_stmt|;
name|filterPatternLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|filterPatternLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Filter pattern:"
argument_list|)
argument_list|)
expr_stmt|;
name|filterPatternLabel
operator|->
name|setBuddy
argument_list|(
name|filterPatternLineEdit
argument_list|)
expr_stmt|;
name|filterSyntaxComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|filterSyntaxComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Regular expression"
argument_list|)
argument_list|,
name|QRegExp
operator|::
name|RegExp
argument_list|)
expr_stmt|;
name|filterSyntaxComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Wildcard"
argument_list|)
argument_list|,
name|QRegExp
operator|::
name|Wildcard
argument_list|)
expr_stmt|;
name|filterSyntaxComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Fixed string"
argument_list|)
argument_list|,
name|QRegExp
operator|::
name|FixedString
argument_list|)
expr_stmt|;
name|filterSyntaxLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Filter&syntax:"
argument_list|)
argument_list|)
expr_stmt|;
name|filterSyntaxLabel
operator|->
name|setBuddy
argument_list|(
name|filterSyntaxComboBox
argument_list|)
expr_stmt|;
name|filterColumnComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|filterColumnComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Subject"
argument_list|)
argument_list|)
expr_stmt|;
name|filterColumnComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Sender"
argument_list|)
argument_list|)
expr_stmt|;
name|filterColumnComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Date"
argument_list|)
argument_list|)
expr_stmt|;
name|filterColumnLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Filter&column:"
argument_list|)
argument_list|)
expr_stmt|;
name|filterColumnLabel
operator|->
name|setBuddy
argument_list|(
name|filterColumnComboBox
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|filterPatternLineEdit
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
name|filterRegExpChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|filterSyntaxComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|filterRegExpChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|filterColumnComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|filterColumnChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|filterCaseSensitivityCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|filterRegExpChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|sortCaseSensitivityCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|sortChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_MAEMO_5
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_SIMULATOR
argument_list|)
name|sourceWidget
operator|=
operator|new
name|QWidget
expr_stmt|;
name|filterWidget
operator|=
operator|new
name|QWidget
expr_stmt|;
name|proxyWidget
operator|=
operator|new
name|QWidget
expr_stmt|;
name|QHBoxLayout
modifier|*
name|sourceLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|sourceLayout
operator|->
name|addWidget
argument_list|(
name|sourceView
argument_list|)
expr_stmt|;
name|sourceWidget
operator|->
name|setLayout
argument_list|(
name|sourceLayout
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|filterLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|filterLayout
operator|->
name|addWidget
argument_list|(
name|filterPatternLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|filterLayout
operator|->
name|addWidget
argument_list|(
name|filterPatternLineEdit
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|filterLayout
operator|->
name|addWidget
argument_list|(
name|filterSyntaxLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|filterLayout
operator|->
name|addWidget
argument_list|(
name|filterSyntaxComboBox
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|filterLayout
operator|->
name|addWidget
argument_list|(
name|filterColumnLabel
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|filterLayout
operator|->
name|addWidget
argument_list|(
name|filterColumnComboBox
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|filterLayout
operator|->
name|addWidget
argument_list|(
name|filterCaseSensitivityCheckBox
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|filterLayout
operator|->
name|addWidget
argument_list|(
name|sortCaseSensitivityCheckBox
argument_list|,
literal|4
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|filterWidget
operator|->
name|setLayout
argument_list|(
name|filterLayout
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|proxyLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|proxyView
argument_list|)
expr_stmt|;
name|proxyWidget
operator|->
name|setLayout
argument_list|(
name|proxyLayout
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|QTabWidget
modifier|*
name|tabWidget
init|=
operator|new
name|QTabWidget
decl_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|sourceWidget
argument_list|,
literal|"Source"
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|filterWidget
argument_list|,
literal|"Filters"
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|proxyWidget
argument_list|,
literal|"Proxy"
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|tabWidget
argument_list|)
expr_stmt|;
else|#
directive|else
name|sourceGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Original Model"
argument_list|)
argument_list|)
expr_stmt|;
name|proxyGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Sorted/Filtered Model"
argument_list|)
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|sourceLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|sourceLayout
operator|->
name|addWidget
argument_list|(
name|sourceView
argument_list|)
expr_stmt|;
name|sourceGroupBox
operator|->
name|setLayout
argument_list|(
name|sourceLayout
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|proxyLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|proxyView
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|filterPatternLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|filterPatternLineEdit
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|filterSyntaxLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|filterSyntaxComboBox
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|filterColumnLabel
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|filterColumnComboBox
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|filterCaseSensitivityCheckBox
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|sortCaseSensitivityCheckBox
argument_list|,
literal|4
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|proxyGroupBox
operator|->
name|setLayout
argument_list|(
name|proxyLayout
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|sourceGroupBox
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|proxyGroupBox
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Basic Sort/Filter Model"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|500
argument_list|,
literal|450
argument_list|)
expr_stmt|;
name|proxyView
operator|->
name|sortByColumn
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|AscendingOrder
argument_list|)
expr_stmt|;
name|filterColumnComboBox
operator|->
name|setCurrentIndex
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|filterPatternLineEdit
operator|->
name|setText
argument_list|(
literal|"Andy|Grace"
argument_list|)
expr_stmt|;
name|filterCaseSensitivityCheckBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|sortCaseSensitivityCheckBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setSourceModel
name|void
name|Window
operator|::
name|setSourceModel
parameter_list|(
name|QAbstractItemModel
modifier|*
name|model
parameter_list|)
block|{
name|proxyModel
operator|->
name|setSourceModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|sourceView
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|filterRegExpChanged
name|void
name|Window
operator|::
name|filterRegExpChanged
parameter_list|()
block|{
name|QRegExp
operator|::
name|PatternSyntax
name|syntax
init|=
name|QRegExp
operator|::
name|PatternSyntax
argument_list|(
name|filterSyntaxComboBox
operator|->
name|itemData
argument_list|(
name|filterSyntaxComboBox
operator|->
name|currentIndex
argument_list|()
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|CaseSensitivity
name|caseSensitivity
init|=
name|filterCaseSensitivityCheckBox
operator|->
name|isChecked
argument_list|()
condition|?
name|Qt
operator|::
name|CaseSensitive
else|:
name|Qt
operator|::
name|CaseInsensitive
decl_stmt|;
name|QRegExp
name|regExp
argument_list|(
name|filterPatternLineEdit
operator|->
name|text
argument_list|()
argument_list|,
name|caseSensitivity
argument_list|,
name|syntax
argument_list|)
decl_stmt|;
name|proxyModel
operator|->
name|setFilterRegExp
argument_list|(
name|regExp
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|filterColumnChanged
name|void
name|Window
operator|::
name|filterColumnChanged
parameter_list|()
block|{
name|proxyModel
operator|->
name|setFilterKeyColumn
argument_list|(
name|filterColumnComboBox
operator|->
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sortChanged
name|void
name|Window
operator|::
name|sortChanged
parameter_list|()
block|{
name|proxyModel
operator|->
name|setSortCaseSensitivity
argument_list|(
name|sortCaseSensitivityCheckBox
operator|->
name|isChecked
argument_list|()
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
end_unit
