begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|()
block|{
name|createSpinBoxes
argument_list|()
expr_stmt|;
name|createDateTimeEdits
argument_list|()
expr_stmt|;
name|createDoubleSpinBoxes
argument_list|()
expr_stmt|;
name|QHBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|spinBoxesGroup
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|editsGroup
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|doubleSpinBoxesGroup
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Spin Boxes"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|createSpinBoxes
name|void
name|Window
operator|::
name|createSpinBoxes
parameter_list|()
block|{
name|spinBoxesGroup
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Spinboxes"
argument_list|)
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|integerLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Enter a value between "
literal|"%1 and %2:"
argument_list|)
operator|.
name|arg
argument_list|(
operator|-
literal|20
argument_list|)
operator|.
name|arg
argument_list|(
literal|20
argument_list|)
argument_list|)
decl_stmt|;
name|QSpinBox
modifier|*
name|integerSpinBox
init|=
operator|new
name|QSpinBox
decl_stmt|;
name|integerSpinBox
operator|->
name|setRange
argument_list|(
operator|-
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|integerSpinBox
operator|->
name|setSingleStep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|integerSpinBox
operator|->
name|setValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|QLabel
modifier|*
name|zoomLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Enter a zoom value between "
literal|"%1 and %2:"
argument_list|)
operator|.
name|arg
argument_list|(
literal|0
argument_list|)
operator|.
name|arg
argument_list|(
literal|1000
argument_list|)
argument_list|)
decl_stmt|;
comment|//! [3]
name|QSpinBox
modifier|*
name|zoomSpinBox
init|=
operator|new
name|QSpinBox
decl_stmt|;
name|zoomSpinBox
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|1000
argument_list|)
expr_stmt|;
name|zoomSpinBox
operator|->
name|setSingleStep
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|zoomSpinBox
operator|->
name|setSuffix
argument_list|(
literal|"%"
argument_list|)
expr_stmt|;
name|zoomSpinBox
operator|->
name|setSpecialValueText
argument_list|(
name|tr
argument_list|(
literal|"Automatic"
argument_list|)
argument_list|)
expr_stmt|;
name|zoomSpinBox
operator|->
name|setValue
argument_list|(
literal|100
argument_list|)
expr_stmt|;
comment|//! [2] //! [3]
comment|//! [4]
name|QLabel
modifier|*
name|priceLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Enter a price between "
literal|"%1 and %2:"
argument_list|)
operator|.
name|arg
argument_list|(
literal|0
argument_list|)
operator|.
name|arg
argument_list|(
literal|999
argument_list|)
argument_list|)
decl_stmt|;
name|QSpinBox
modifier|*
name|priceSpinBox
init|=
operator|new
name|QSpinBox
decl_stmt|;
name|priceSpinBox
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|999
argument_list|)
expr_stmt|;
name|priceSpinBox
operator|->
name|setSingleStep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|priceSpinBox
operator|->
name|setPrefix
argument_list|(
literal|"$"
argument_list|)
expr_stmt|;
name|priceSpinBox
operator|->
name|setValue
argument_list|(
literal|99
argument_list|)
expr_stmt|;
comment|//! [4] //! [5]
name|QVBoxLayout
modifier|*
name|spinBoxLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|integerLabel
argument_list|)
expr_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|integerSpinBox
argument_list|)
expr_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|zoomLabel
argument_list|)
expr_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|zoomSpinBox
argument_list|)
expr_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|priceLabel
argument_list|)
expr_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|priceSpinBox
argument_list|)
expr_stmt|;
name|spinBoxesGroup
operator|->
name|setLayout
argument_list|(
name|spinBoxLayout
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|createDateTimeEdits
name|void
name|Window
operator|::
name|createDateTimeEdits
parameter_list|()
block|{
name|editsGroup
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Date and time spin boxes"
argument_list|)
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|dateLabel
init|=
operator|new
name|QLabel
decl_stmt|;
name|QDateEdit
modifier|*
name|dateEdit
init|=
operator|new
name|QDateEdit
argument_list|(
name|QDate
operator|::
name|currentDate
argument_list|()
argument_list|)
decl_stmt|;
name|dateEdit
operator|->
name|setDateRange
argument_list|(
name|QDate
argument_list|(
literal|2005
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|,
name|QDate
argument_list|(
literal|2010
argument_list|,
literal|12
argument_list|,
literal|31
argument_list|)
argument_list|)
expr_stmt|;
name|dateLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Appointment date (between %0 and %1):"
argument_list|)
operator|.
name|arg
argument_list|(
name|dateEdit
operator|->
name|minimumDate
argument_list|()
operator|.
name|toString
argument_list|(
name|Qt
operator|::
name|ISODate
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|dateEdit
operator|->
name|maximumDate
argument_list|()
operator|.
name|toString
argument_list|(
name|Qt
operator|::
name|ISODate
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [6]
comment|//! [7]
name|QLabel
modifier|*
name|timeLabel
init|=
operator|new
name|QLabel
decl_stmt|;
name|QTimeEdit
modifier|*
name|timeEdit
init|=
operator|new
name|QTimeEdit
argument_list|(
name|QTime
operator|::
name|currentTime
argument_list|()
argument_list|)
decl_stmt|;
name|timeEdit
operator|->
name|setTimeRange
argument_list|(
name|QTime
argument_list|(
literal|9
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|16
argument_list|,
literal|30
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|timeLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Appointment time (between %0 and %1):"
argument_list|)
operator|.
name|arg
argument_list|(
name|timeEdit
operator|->
name|minimumTime
argument_list|()
operator|.
name|toString
argument_list|(
name|Qt
operator|::
name|ISODate
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|timeEdit
operator|->
name|maximumTime
argument_list|()
operator|.
name|toString
argument_list|(
name|Qt
operator|::
name|ISODate
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [7]
comment|//! [8]
name|meetingLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|meetingEdit
operator|=
operator|new
name|QDateTimeEdit
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [8]
comment|//! [9]
name|QLabel
modifier|*
name|formatLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Format string for the meeting date "
literal|"and time:"
argument_list|)
argument_list|)
decl_stmt|;
name|QComboBox
modifier|*
name|formatComboBox
init|=
operator|new
name|QComboBox
decl_stmt|;
name|formatComboBox
operator|->
name|addItem
argument_list|(
literal|"yyyy-MM-dd hh:mm:ss (zzz 'ms')"
argument_list|)
expr_stmt|;
name|formatComboBox
operator|->
name|addItem
argument_list|(
literal|"hh:mm:ss MM/dd/yyyy"
argument_list|)
expr_stmt|;
name|formatComboBox
operator|->
name|addItem
argument_list|(
literal|"hh:mm:ss dd/MM/yyyy"
argument_list|)
expr_stmt|;
name|formatComboBox
operator|->
name|addItem
argument_list|(
literal|"hh:mm:ss"
argument_list|)
expr_stmt|;
name|formatComboBox
operator|->
name|addItem
argument_list|(
literal|"hh:mm ap"
argument_list|)
expr_stmt|;
comment|//! [9] //! [10]
name|connect
argument_list|(
name|formatComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setFormatString
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [10]
name|setFormatString
argument_list|(
name|formatComboBox
operator|->
name|currentText
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [11]
name|QVBoxLayout
modifier|*
name|editsLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|editsLayout
operator|->
name|addWidget
argument_list|(
name|dateLabel
argument_list|)
expr_stmt|;
name|editsLayout
operator|->
name|addWidget
argument_list|(
name|dateEdit
argument_list|)
expr_stmt|;
name|editsLayout
operator|->
name|addWidget
argument_list|(
name|timeLabel
argument_list|)
expr_stmt|;
name|editsLayout
operator|->
name|addWidget
argument_list|(
name|timeEdit
argument_list|)
expr_stmt|;
name|editsLayout
operator|->
name|addWidget
argument_list|(
name|meetingLabel
argument_list|)
expr_stmt|;
name|editsLayout
operator|->
name|addWidget
argument_list|(
name|meetingEdit
argument_list|)
expr_stmt|;
name|editsLayout
operator|->
name|addWidget
argument_list|(
name|formatLabel
argument_list|)
expr_stmt|;
name|editsLayout
operator|->
name|addWidget
argument_list|(
name|formatComboBox
argument_list|)
expr_stmt|;
name|editsGroup
operator|->
name|setLayout
argument_list|(
name|editsLayout
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|setFormatString
name|void
name|Window
operator|::
name|setFormatString
parameter_list|(
specifier|const
name|QString
modifier|&
name|formatString
parameter_list|)
block|{
name|meetingEdit
operator|->
name|setDisplayFormat
argument_list|(
name|formatString
argument_list|)
expr_stmt|;
comment|//! [12] //! [13]
if|if
condition|(
name|meetingEdit
operator|->
name|displayedSections
argument_list|()
operator|&
name|QDateTimeEdit
operator|::
name|DateSections_Mask
condition|)
block|{
name|meetingEdit
operator|->
name|setDateRange
argument_list|(
name|QDate
argument_list|(
literal|2004
argument_list|,
literal|11
argument_list|,
literal|1
argument_list|)
argument_list|,
name|QDate
argument_list|(
literal|2005
argument_list|,
literal|11
argument_list|,
literal|30
argument_list|)
argument_list|)
expr_stmt|;
name|meetingLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Meeting date (between %0 and %1):"
argument_list|)
operator|.
name|arg
argument_list|(
name|meetingEdit
operator|->
name|minimumDate
argument_list|()
operator|.
name|toString
argument_list|(
name|Qt
operator|::
name|ISODate
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|meetingEdit
operator|->
name|maximumDate
argument_list|()
operator|.
name|toString
argument_list|(
name|Qt
operator|::
name|ISODate
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|meetingEdit
operator|->
name|setTimeRange
argument_list|(
name|QTime
argument_list|(
literal|0
argument_list|,
literal|7
argument_list|,
literal|20
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|21
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|meetingLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Meeting time (between %0 and %1):"
argument_list|)
operator|.
name|arg
argument_list|(
name|meetingEdit
operator|->
name|minimumTime
argument_list|()
operator|.
name|toString
argument_list|(
name|Qt
operator|::
name|ISODate
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|meetingEdit
operator|->
name|maximumTime
argument_list|()
operator|.
name|toString
argument_list|(
name|Qt
operator|::
name|ISODate
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_function
DECL|function|createDoubleSpinBoxes
name|void
name|Window
operator|::
name|createDoubleSpinBoxes
parameter_list|()
block|{
name|doubleSpinBoxesGroup
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Double precision spinboxes"
argument_list|)
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|precisionLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Number of decimal places "
literal|"to show:"
argument_list|)
argument_list|)
decl_stmt|;
name|QSpinBox
modifier|*
name|precisionSpinBox
init|=
operator|new
name|QSpinBox
decl_stmt|;
name|precisionSpinBox
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|precisionSpinBox
operator|->
name|setValue
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|//! [14]
comment|//! [15]
name|QLabel
modifier|*
name|doubleLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Enter a value between "
literal|"%1 and %2:"
argument_list|)
operator|.
name|arg
argument_list|(
operator|-
literal|20
argument_list|)
operator|.
name|arg
argument_list|(
literal|20
argument_list|)
argument_list|)
decl_stmt|;
name|doubleSpinBox
operator|=
operator|new
name|QDoubleSpinBox
expr_stmt|;
name|doubleSpinBox
operator|->
name|setRange
argument_list|(
operator|-
literal|20.0
argument_list|,
literal|20.0
argument_list|)
expr_stmt|;
name|doubleSpinBox
operator|->
name|setSingleStep
argument_list|(
literal|1.0
argument_list|)
expr_stmt|;
name|doubleSpinBox
operator|->
name|setValue
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
comment|//! [15]
comment|//! [16]
name|QLabel
modifier|*
name|scaleLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Enter a scale factor between "
literal|"%1 and %2:"
argument_list|)
operator|.
name|arg
argument_list|(
literal|0
argument_list|)
operator|.
name|arg
argument_list|(
literal|1000.0
argument_list|)
argument_list|)
decl_stmt|;
name|scaleSpinBox
operator|=
operator|new
name|QDoubleSpinBox
expr_stmt|;
name|scaleSpinBox
operator|->
name|setRange
argument_list|(
literal|0.0
argument_list|,
literal|1000.0
argument_list|)
expr_stmt|;
name|scaleSpinBox
operator|->
name|setSingleStep
argument_list|(
literal|10.0
argument_list|)
expr_stmt|;
name|scaleSpinBox
operator|->
name|setSuffix
argument_list|(
literal|"%"
argument_list|)
expr_stmt|;
name|scaleSpinBox
operator|->
name|setSpecialValueText
argument_list|(
name|tr
argument_list|(
literal|"No scaling"
argument_list|)
argument_list|)
expr_stmt|;
name|scaleSpinBox
operator|->
name|setValue
argument_list|(
literal|100.0
argument_list|)
expr_stmt|;
comment|//! [16]
comment|//! [17]
name|QLabel
modifier|*
name|priceLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Enter a price between "
literal|"%1 and %2:"
argument_list|)
operator|.
name|arg
argument_list|(
literal|0
argument_list|)
operator|.
name|arg
argument_list|(
literal|1000
argument_list|)
argument_list|)
decl_stmt|;
name|priceSpinBox
operator|=
operator|new
name|QDoubleSpinBox
expr_stmt|;
name|priceSpinBox
operator|->
name|setRange
argument_list|(
literal|0.0
argument_list|,
literal|1000.0
argument_list|)
expr_stmt|;
name|priceSpinBox
operator|->
name|setSingleStep
argument_list|(
literal|1.0
argument_list|)
expr_stmt|;
name|priceSpinBox
operator|->
name|setPrefix
argument_list|(
literal|"$"
argument_list|)
expr_stmt|;
name|priceSpinBox
operator|->
name|setValue
argument_list|(
literal|99.99
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|precisionSpinBox
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
comment|//! [17]
name|this
argument_list|,
name|SLOT
argument_list|(
name|changePrecision
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [18]
name|QVBoxLayout
modifier|*
name|spinBoxLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|precisionLabel
argument_list|)
expr_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|precisionSpinBox
argument_list|)
expr_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|doubleLabel
argument_list|)
expr_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|doubleSpinBox
argument_list|)
expr_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|scaleLabel
argument_list|)
expr_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|scaleSpinBox
argument_list|)
expr_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|priceLabel
argument_list|)
expr_stmt|;
name|spinBoxLayout
operator|->
name|addWidget
argument_list|(
name|priceSpinBox
argument_list|)
expr_stmt|;
name|doubleSpinBoxesGroup
operator|->
name|setLayout
argument_list|(
name|spinBoxLayout
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [18]
end_comment
begin_comment
comment|//! [19]
end_comment
begin_function
DECL|function|changePrecision
name|void
name|Window
operator|::
name|changePrecision
parameter_list|(
name|int
name|decimals
parameter_list|)
block|{
name|doubleSpinBox
operator|->
name|setDecimals
argument_list|(
name|decimals
argument_list|)
expr_stmt|;
name|scaleSpinBox
operator|->
name|setDecimals
argument_list|(
name|decimals
argument_list|)
expr_stmt|;
name|priceSpinBox
operator|->
name|setDecimals
argument_list|(
name|decimals
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [19]
end_comment
end_unit
