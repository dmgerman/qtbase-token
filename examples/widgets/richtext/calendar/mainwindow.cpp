begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|selectedDate
operator|=
name|QDate
operator|::
name|currentDate
argument_list|()
expr_stmt|;
name|fontSize
operator|=
literal|10
expr_stmt|;
name|QWidget
modifier|*
name|centralWidget
init|=
operator|new
name|QWidget
decl_stmt|;
comment|//! [0]
comment|//! [1]
name|QLabel
modifier|*
name|dateLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Date:"
argument_list|)
argument_list|)
decl_stmt|;
name|QComboBox
modifier|*
name|monthCombo
init|=
operator|new
name|QComboBox
decl_stmt|;
for|for
control|(
name|int
name|month
init|=
literal|1
init|;
name|month
operator|<=
literal|12
condition|;
operator|++
name|month
control|)
name|monthCombo
operator|->
name|addItem
argument_list|(
name|QDate
operator|::
name|longMonthName
argument_list|(
name|month
argument_list|)
argument_list|)
expr_stmt|;
name|QDateTimeEdit
modifier|*
name|yearEdit
init|=
operator|new
name|QDateTimeEdit
decl_stmt|;
name|yearEdit
operator|->
name|setDisplayFormat
argument_list|(
literal|"yyyy"
argument_list|)
expr_stmt|;
name|yearEdit
operator|->
name|setDateRange
argument_list|(
name|QDate
argument_list|(
literal|1753
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|,
name|QDate
argument_list|(
literal|8000
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1]
name|monthCombo
operator|->
name|setCurrentIndex
argument_list|(
name|selectedDate
operator|.
name|month
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
name|yearEdit
operator|->
name|setDate
argument_list|(
name|selectedDate
argument_list|)
expr_stmt|;
comment|//! [2]
name|QLabel
modifier|*
name|fontSizeLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Font size:"
argument_list|)
argument_list|)
decl_stmt|;
name|QSpinBox
modifier|*
name|fontSizeSpinBox
init|=
operator|new
name|QSpinBox
decl_stmt|;
name|fontSizeSpinBox
operator|->
name|setRange
argument_list|(
literal|1
argument_list|,
literal|64
argument_list|)
expr_stmt|;
name|editor
operator|=
operator|new
name|QTextBrowser
expr_stmt|;
name|insertCalendar
argument_list|()
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|connect
argument_list|(
name|monthCombo
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
name|setMonth
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|yearEdit
argument_list|,
name|SIGNAL
argument_list|(
name|dateChanged
argument_list|(
name|QDate
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setYear
argument_list|(
name|QDate
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fontSizeSpinBox
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setFontSize
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [3]
name|fontSizeSpinBox
operator|->
name|setValue
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|//! [4]
name|QHBoxLayout
modifier|*
name|controlsLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|dateLabel
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|monthCombo
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|yearEdit
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addSpacing
argument_list|(
literal|24
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|fontSizeLabel
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|fontSizeSpinBox
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|centralLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|centralLayout
operator|->
name|addLayout
argument_list|(
name|controlsLayout
argument_list|)
expr_stmt|;
name|centralLayout
operator|->
name|addWidget
argument_list|(
name|editor
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|centralWidget
operator|->
name|setLayout
argument_list|(
name|centralLayout
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|centralWidget
argument_list|)
expr_stmt|;
comment|//! [4]
block|}
end_constructor
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|insertCalendar
name|void
name|MainWindow
operator|::
name|insertCalendar
parameter_list|()
block|{
name|editor
operator|->
name|clear
argument_list|()
expr_stmt|;
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
name|QDate
name|date
argument_list|(
name|selectedDate
operator|.
name|year
argument_list|()
argument_list|,
name|selectedDate
operator|.
name|month
argument_list|()
argument_list|,
literal|1
argument_list|)
decl_stmt|;
comment|//! [5]
comment|//! [6]
name|QTextTableFormat
name|tableFormat
decl_stmt|;
name|tableFormat
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|tableFormat
operator|.
name|setBackground
argument_list|(
name|QColor
argument_list|(
literal|"#e0e0e0"
argument_list|)
argument_list|)
expr_stmt|;
name|tableFormat
operator|.
name|setCellPadding
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|tableFormat
operator|.
name|setCellSpacing
argument_list|(
literal|4
argument_list|)
expr_stmt|;
comment|//! [6] //! [7]
name|QVector
argument_list|<
name|QTextLength
argument_list|>
name|constraints
decl_stmt|;
name|constraints
operator|<<
name|QTextLength
argument_list|(
name|QTextLength
operator|::
name|PercentageLength
argument_list|,
literal|14
argument_list|)
operator|<<
name|QTextLength
argument_list|(
name|QTextLength
operator|::
name|PercentageLength
argument_list|,
literal|14
argument_list|)
operator|<<
name|QTextLength
argument_list|(
name|QTextLength
operator|::
name|PercentageLength
argument_list|,
literal|14
argument_list|)
operator|<<
name|QTextLength
argument_list|(
name|QTextLength
operator|::
name|PercentageLength
argument_list|,
literal|14
argument_list|)
operator|<<
name|QTextLength
argument_list|(
name|QTextLength
operator|::
name|PercentageLength
argument_list|,
literal|14
argument_list|)
operator|<<
name|QTextLength
argument_list|(
name|QTextLength
operator|::
name|PercentageLength
argument_list|,
literal|14
argument_list|)
operator|<<
name|QTextLength
argument_list|(
name|QTextLength
operator|::
name|PercentageLength
argument_list|,
literal|14
argument_list|)
expr_stmt|;
name|tableFormat
operator|.
name|setColumnWidthConstraints
argument_list|(
name|constraints
argument_list|)
expr_stmt|;
comment|//! [7]
comment|//! [8]
name|QTextTable
modifier|*
name|table
init|=
name|cursor
operator|.
name|insertTable
argument_list|(
literal|1
argument_list|,
literal|7
argument_list|,
name|tableFormat
argument_list|)
decl_stmt|;
comment|//! [8]
comment|//! [9]
name|QTextFrame
modifier|*
name|frame
init|=
name|cursor
operator|.
name|currentFrame
argument_list|()
decl_stmt|;
name|QTextFrameFormat
name|frameFormat
init|=
name|frame
operator|->
name|frameFormat
argument_list|()
decl_stmt|;
name|frameFormat
operator|.
name|setBorder
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|frame
operator|->
name|setFrameFormat
argument_list|(
name|frameFormat
argument_list|)
expr_stmt|;
comment|//! [9]
comment|//! [10]
name|QTextCharFormat
name|format
init|=
name|cursor
operator|.
name|charFormat
argument_list|()
decl_stmt|;
name|format
operator|.
name|setFontPointSize
argument_list|(
name|fontSize
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|boldFormat
init|=
name|format
decl_stmt|;
name|boldFormat
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|highlightedFormat
init|=
name|boldFormat
decl_stmt|;
name|highlightedFormat
operator|.
name|setBackground
argument_list|(
name|Qt
operator|::
name|yellow
argument_list|)
expr_stmt|;
comment|//! [10]
comment|//! [11]
for|for
control|(
name|int
name|weekDay
init|=
literal|1
init|;
name|weekDay
operator|<=
literal|7
condition|;
operator|++
name|weekDay
control|)
block|{
name|QTextTableCell
name|cell
init|=
name|table
operator|->
name|cellAt
argument_list|(
literal|0
argument_list|,
name|weekDay
operator|-
literal|1
argument_list|)
decl_stmt|;
comment|//! [11] //! [12]
name|QTextCursor
name|cellCursor
init|=
name|cell
operator|.
name|firstCursorPosition
argument_list|()
decl_stmt|;
name|cellCursor
operator|.
name|insertText
argument_list|(
name|QString
argument_list|(
literal|"%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QDate
operator|::
name|longDayName
argument_list|(
name|weekDay
argument_list|)
argument_list|)
argument_list|,
name|boldFormat
argument_list|)
expr_stmt|;
block|}
comment|//! [12]
comment|//! [13]
name|table
operator|->
name|insertRows
argument_list|(
name|table
operator|->
name|rows
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|//! [13]
while|while
condition|(
name|date
operator|.
name|month
argument_list|()
operator|==
name|selectedDate
operator|.
name|month
argument_list|()
condition|)
block|{
name|int
name|weekDay
init|=
name|date
operator|.
name|dayOfWeek
argument_list|()
decl_stmt|;
name|QTextTableCell
name|cell
init|=
name|table
operator|->
name|cellAt
argument_list|(
name|table
operator|->
name|rows
argument_list|()
operator|-
literal|1
argument_list|,
name|weekDay
operator|-
literal|1
argument_list|)
decl_stmt|;
name|QTextCursor
name|cellCursor
init|=
name|cell
operator|.
name|firstCursorPosition
argument_list|()
decl_stmt|;
if|if
condition|(
name|date
operator|==
name|QDate
operator|::
name|currentDate
argument_list|()
condition|)
name|cellCursor
operator|.
name|insertText
argument_list|(
name|QString
argument_list|(
literal|"%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|date
operator|.
name|day
argument_list|()
argument_list|)
argument_list|,
name|highlightedFormat
argument_list|)
expr_stmt|;
else|else
name|cellCursor
operator|.
name|insertText
argument_list|(
name|QString
argument_list|(
literal|"%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|date
operator|.
name|day
argument_list|()
argument_list|)
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|date
operator|=
name|date
operator|.
name|addDays
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|weekDay
operator|==
literal|7
operator|&&
name|date
operator|.
name|month
argument_list|()
operator|==
name|selectedDate
operator|.
name|month
argument_list|()
condition|)
name|table
operator|->
name|insertRows
argument_list|(
name|table
operator|->
name|rows
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
comment|//! [14]
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Calendar for %1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|QDate
operator|::
name|longMonthName
argument_list|(
name|selectedDate
operator|.
name|month
argument_list|()
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|selectedDate
operator|.
name|year
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_function
DECL|function|setFontSize
name|void
name|MainWindow
operator|::
name|setFontSize
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|fontSize
operator|=
name|size
expr_stmt|;
name|insertCalendar
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_function
DECL|function|setMonth
name|void
name|MainWindow
operator|::
name|setMonth
parameter_list|(
name|int
name|month
parameter_list|)
block|{
name|selectedDate
operator|=
name|QDate
argument_list|(
name|selectedDate
operator|.
name|year
argument_list|()
argument_list|,
name|month
operator|+
literal|1
argument_list|,
name|selectedDate
operator|.
name|day
argument_list|()
argument_list|)
expr_stmt|;
name|insertCalendar
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_function
DECL|function|setYear
name|void
name|MainWindow
operator|::
name|setYear
parameter_list|(
name|QDate
name|date
parameter_list|)
block|{
name|selectedDate
operator|=
name|QDate
argument_list|(
name|date
operator|.
name|year
argument_list|()
argument_list|,
name|selectedDate
operator|.
name|month
argument_list|()
argument_list|,
name|selectedDate
operator|.
name|day
argument_list|()
argument_list|)
expr_stmt|;
name|insertCalendar
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [17]
end_comment
end_unit
