begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"dateformats.h"
end_include
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QScrollArea>
end_include
begin_include
include|#
directive|include
file|<QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QComboBox>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QDateTime>
end_include
begin_constructor
DECL|function|DateFormatsWidget
name|DateFormatsWidget
operator|::
name|DateFormatsWidget
parameter_list|()
block|{
name|scrollArea
operator|=
operator|new
name|QScrollArea
expr_stmt|;
name|scrollAreaWidget
operator|=
operator|new
name|QWidget
expr_stmt|;
name|scrollArea
operator|->
name|setWidget
argument_list|(
name|scrollAreaWidget
argument_list|)
expr_stmt|;
name|scrollArea
operator|->
name|setWidgetResizable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|layout
operator|=
operator|new
name|QGridLayout
argument_list|(
name|scrollAreaWidget
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|l
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|scrollArea
argument_list|)
expr_stmt|;
name|shortDateFormat
operator|=
name|addItem
argument_list|(
literal|"Date format (short):"
argument_list|)
expr_stmt|;
name|longDateFormat
operator|=
name|addItem
argument_list|(
literal|"Date format (long):"
argument_list|)
expr_stmt|;
name|shortTimeFormat
operator|=
name|addItem
argument_list|(
literal|"Time format (short):"
argument_list|)
expr_stmt|;
name|longTimeFormat
operator|=
name|addItem
argument_list|(
literal|"Time format (long):"
argument_list|)
expr_stmt|;
name|shortDateTimeFormat
operator|=
name|addItem
argument_list|(
literal|"DateTime format (short):"
argument_list|)
expr_stmt|;
name|longDateTimeFormat
operator|=
name|addItem
argument_list|(
literal|"DateTime format (long):"
argument_list|)
expr_stmt|;
name|amText
operator|=
name|addItem
argument_list|(
literal|"Before noon:"
argument_list|)
expr_stmt|;
name|pmText
operator|=
name|addItem
argument_list|(
literal|"After noon:"
argument_list|)
expr_stmt|;
name|firstDayOfWeek
operator|=
name|addItem
argument_list|(
literal|"First day of week:"
argument_list|)
expr_stmt|;
name|monthNamesShort
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|monthNamesLong
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|standaloneMonthNamesShort
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|standaloneMonthNamesLong
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|dayNamesShort
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|dayNamesLong
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|standaloneDayNamesShort
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|standaloneDayNamesLong
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|int
name|row
init|=
name|layout
operator|->
name|rowCount
argument_list|()
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
literal|"Month names [short/long]:"
argument_list|)
argument_list|,
name|row
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|monthNamesShort
argument_list|,
name|row
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|monthNamesLong
argument_list|,
name|row
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|row
operator|=
name|layout
operator|->
name|rowCount
argument_list|()
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
literal|"Standalone month names [short/long]:"
argument_list|)
argument_list|,
name|row
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|standaloneMonthNamesShort
argument_list|,
name|row
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|standaloneMonthNamesLong
argument_list|,
name|row
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|row
operator|=
name|layout
operator|->
name|rowCount
argument_list|()
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
literal|"Day names [short/long]:"
argument_list|)
argument_list|,
name|row
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|dayNamesShort
argument_list|,
name|row
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|dayNamesLong
argument_list|,
name|row
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|row
operator|=
name|layout
operator|->
name|rowCount
argument_list|()
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
literal|"Standalone day names [short/long]:"
argument_list|)
argument_list|,
name|row
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|standaloneDayNamesShort
argument_list|,
name|row
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|standaloneDayNamesLong
argument_list|,
name|row
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|toString
name|QString
name|toString
parameter_list|(
name|Qt
operator|::
name|DayOfWeek
name|dow
parameter_list|)
block|{
specifier|static
specifier|const
name|char
modifier|*
name|names
index|[]
init|=
block|{
literal|"Monday"
block|,
literal|"Tuesday"
block|,
literal|"Wednesday"
block|,
literal|"Thursday"
block|,
literal|"Friday"
block|,
literal|"Saturday"
block|,
literal|"Sunday"
block|}
decl_stmt|;
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|names
index|[
name|dow
operator|-
literal|1
index|]
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|localeChanged
name|void
name|DateFormatsWidget
operator|::
name|localeChanged
parameter_list|(
name|QLocale
name|locale
parameter_list|)
block|{
name|setLocale
argument_list|(
name|locale
argument_list|)
expr_stmt|;
name|QDateTime
name|now
init|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
decl_stmt|;
name|shortDateFormat
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|toString
argument_list|(
name|now
operator|.
name|date
argument_list|()
argument_list|,
name|QLocale
operator|::
name|ShortFormat
argument_list|)
argument_list|)
expr_stmt|;
name|shortDateFormat
operator|->
name|setToolTip
argument_list|(
name|locale
operator|.
name|dateFormat
argument_list|(
name|QLocale
operator|::
name|ShortFormat
argument_list|)
argument_list|)
expr_stmt|;
name|longDateFormat
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|toString
argument_list|(
name|now
operator|.
name|date
argument_list|()
argument_list|,
name|QLocale
operator|::
name|LongFormat
argument_list|)
argument_list|)
expr_stmt|;
name|longDateFormat
operator|->
name|setToolTip
argument_list|(
name|locale
operator|.
name|dateFormat
argument_list|(
name|QLocale
operator|::
name|LongFormat
argument_list|)
argument_list|)
expr_stmt|;
name|shortTimeFormat
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|toString
argument_list|(
name|now
operator|.
name|time
argument_list|()
argument_list|,
name|QLocale
operator|::
name|ShortFormat
argument_list|)
argument_list|)
expr_stmt|;
name|shortTimeFormat
operator|->
name|setToolTip
argument_list|(
name|locale
operator|.
name|timeFormat
argument_list|(
name|QLocale
operator|::
name|ShortFormat
argument_list|)
argument_list|)
expr_stmt|;
name|longTimeFormat
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|toString
argument_list|(
name|now
operator|.
name|time
argument_list|()
argument_list|,
name|QLocale
operator|::
name|LongFormat
argument_list|)
argument_list|)
expr_stmt|;
name|longTimeFormat
operator|->
name|setToolTip
argument_list|(
name|locale
operator|.
name|timeFormat
argument_list|(
name|QLocale
operator|::
name|LongFormat
argument_list|)
argument_list|)
expr_stmt|;
name|shortDateTimeFormat
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|toString
argument_list|(
name|now
argument_list|,
name|QLocale
operator|::
name|ShortFormat
argument_list|)
argument_list|)
expr_stmt|;
name|shortDateTimeFormat
operator|->
name|setToolTip
argument_list|(
name|locale
operator|.
name|dateTimeFormat
argument_list|(
name|QLocale
operator|::
name|ShortFormat
argument_list|)
argument_list|)
expr_stmt|;
name|longDateTimeFormat
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|toString
argument_list|(
name|now
argument_list|,
name|QLocale
operator|::
name|LongFormat
argument_list|)
argument_list|)
expr_stmt|;
name|longDateTimeFormat
operator|->
name|setToolTip
argument_list|(
name|locale
operator|.
name|dateTimeFormat
argument_list|(
name|QLocale
operator|::
name|LongFormat
argument_list|)
argument_list|)
expr_stmt|;
name|amText
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|amText
argument_list|()
argument_list|)
expr_stmt|;
name|pmText
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|pmText
argument_list|()
argument_list|)
expr_stmt|;
name|firstDayOfWeek
operator|->
name|setText
argument_list|(
name|toString
argument_list|(
name|locale
operator|.
name|firstDayOfWeek
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|mns
init|=
name|monthNamesShort
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|int
name|mnl
init|=
name|monthNamesLong
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|int
name|smns
init|=
name|standaloneMonthNamesShort
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|int
name|smnl
init|=
name|standaloneMonthNamesLong
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|int
name|dnl
init|=
name|dayNamesLong
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|int
name|dns
init|=
name|dayNamesShort
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|int
name|sdnl
init|=
name|standaloneDayNamesLong
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|int
name|sdns
init|=
name|standaloneDayNamesShort
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|monthNamesShort
operator|->
name|clear
argument_list|()
expr_stmt|;
name|monthNamesLong
operator|->
name|clear
argument_list|()
expr_stmt|;
name|standaloneMonthNamesShort
operator|->
name|clear
argument_list|()
expr_stmt|;
name|standaloneMonthNamesLong
operator|->
name|clear
argument_list|()
expr_stmt|;
name|dayNamesLong
operator|->
name|clear
argument_list|()
expr_stmt|;
name|dayNamesShort
operator|->
name|clear
argument_list|()
expr_stmt|;
name|standaloneDayNamesLong
operator|->
name|clear
argument_list|()
expr_stmt|;
name|standaloneDayNamesShort
operator|->
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
literal|12
condition|;
operator|++
name|i
control|)
name|monthNamesShort
operator|->
name|addItem
argument_list|(
name|locale
operator|.
name|monthName
argument_list|(
name|i
argument_list|,
name|QLocale
operator|::
name|ShortFormat
argument_list|)
argument_list|)
expr_stmt|;
name|monthNamesShort
operator|->
name|setCurrentIndex
argument_list|(
name|mns
operator|>=
literal|0
condition|?
name|mns
else|:
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
literal|12
condition|;
operator|++
name|i
control|)
name|monthNamesLong
operator|->
name|addItem
argument_list|(
name|locale
operator|.
name|monthName
argument_list|(
name|i
argument_list|,
name|QLocale
operator|::
name|LongFormat
argument_list|)
argument_list|)
expr_stmt|;
name|monthNamesLong
operator|->
name|setCurrentIndex
argument_list|(
name|mnl
operator|>=
literal|0
condition|?
name|mnl
else|:
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
literal|12
condition|;
operator|++
name|i
control|)
name|standaloneMonthNamesShort
operator|->
name|addItem
argument_list|(
name|locale
operator|.
name|standaloneMonthName
argument_list|(
name|i
argument_list|,
name|QLocale
operator|::
name|ShortFormat
argument_list|)
argument_list|)
expr_stmt|;
name|standaloneMonthNamesShort
operator|->
name|setCurrentIndex
argument_list|(
name|smns
operator|>=
literal|0
condition|?
name|smns
else|:
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
literal|12
condition|;
operator|++
name|i
control|)
name|standaloneMonthNamesLong
operator|->
name|addItem
argument_list|(
name|locale
operator|.
name|standaloneMonthName
argument_list|(
name|i
argument_list|,
name|QLocale
operator|::
name|LongFormat
argument_list|)
argument_list|)
expr_stmt|;
name|standaloneMonthNamesLong
operator|->
name|setCurrentIndex
argument_list|(
name|smnl
operator|>=
literal|0
condition|?
name|smnl
else|:
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
literal|7
condition|;
operator|++
name|i
control|)
name|dayNamesLong
operator|->
name|addItem
argument_list|(
name|locale
operator|.
name|dayName
argument_list|(
name|i
argument_list|,
name|QLocale
operator|::
name|LongFormat
argument_list|)
argument_list|)
expr_stmt|;
name|dayNamesLong
operator|->
name|setCurrentIndex
argument_list|(
name|dnl
operator|>=
literal|0
condition|?
name|dnl
else|:
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
literal|7
condition|;
operator|++
name|i
control|)
name|dayNamesShort
operator|->
name|addItem
argument_list|(
name|locale
operator|.
name|dayName
argument_list|(
name|i
argument_list|,
name|QLocale
operator|::
name|ShortFormat
argument_list|)
argument_list|)
expr_stmt|;
name|dayNamesShort
operator|->
name|setCurrentIndex
argument_list|(
name|dns
operator|>=
literal|0
condition|?
name|dns
else|:
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
literal|7
condition|;
operator|++
name|i
control|)
name|standaloneDayNamesLong
operator|->
name|addItem
argument_list|(
name|locale
operator|.
name|standaloneDayName
argument_list|(
name|i
argument_list|,
name|QLocale
operator|::
name|LongFormat
argument_list|)
argument_list|)
expr_stmt|;
name|standaloneDayNamesLong
operator|->
name|setCurrentIndex
argument_list|(
name|sdnl
operator|>=
literal|0
condition|?
name|sdnl
else|:
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
literal|7
condition|;
operator|++
name|i
control|)
name|standaloneDayNamesShort
operator|->
name|addItem
argument_list|(
name|locale
operator|.
name|standaloneDayName
argument_list|(
name|i
argument_list|,
name|QLocale
operator|::
name|ShortFormat
argument_list|)
argument_list|)
expr_stmt|;
name|standaloneDayNamesShort
operator|->
name|setCurrentIndex
argument_list|(
name|sdns
operator|>=
literal|0
condition|?
name|sdns
else|:
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addItem
name|void
name|DateFormatsWidget
operator|::
name|addItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|label
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
name|QLabel
modifier|*
name|lbl
init|=
operator|new
name|QLabel
argument_list|(
name|label
argument_list|)
decl_stmt|;
name|int
name|row
init|=
name|layout
operator|->
name|rowCount
argument_list|()
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|lbl
argument_list|,
name|row
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|w
argument_list|,
name|row
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addItem
name|QLineEdit
modifier|*
name|DateFormatsWidget
operator|::
name|addItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|label
parameter_list|)
block|{
name|QLineEdit
modifier|*
name|le
init|=
operator|new
name|QLineEdit
decl_stmt|;
name|le
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|addItem
argument_list|(
name|label
argument_list|,
name|le
argument_list|)
expr_stmt|;
return|return
name|le
return|;
block|}
end_function
end_unit
