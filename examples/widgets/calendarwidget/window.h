begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WINDOW_H
end_ifndef
begin_define
DECL|macro|WINDOW_H
define|#
directive|define
name|WINDOW_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCalendarWidget
name|class
name|QCalendarWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCheckBox
name|class
name|QCheckBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QComboBox
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDate
name|class
name|QDate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDateEdit
name|class
name|QDateEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGridLayout
name|class
name|QGridLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGroupBox
name|class
name|QGroupBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|Window
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|Window
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|localeChanged
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|firstDayChanged
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|selectionModeChanged
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|horizontalHeaderChanged
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|verticalHeaderChanged
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|selectedDateChanged
argument_list|()
block|;
name|void
name|minimumDateChanged
argument_list|(
specifier|const
name|QDate
operator|&
name|date
argument_list|)
block|;
name|void
name|maximumDateChanged
argument_list|(
specifier|const
name|QDate
operator|&
name|date
argument_list|)
block|;
name|void
name|weekdayFormatChanged
argument_list|()
block|;
name|void
name|weekendFormatChanged
argument_list|()
block|;
name|void
name|reformatHeaders
argument_list|()
block|;
name|void
name|reformatCalendarPage
argument_list|()
block|;
name|private
operator|:
name|void
name|createPreviewGroupBox
argument_list|()
block|;
name|void
name|createGeneralOptionsGroupBox
argument_list|()
block|;
name|void
name|createDatesGroupBox
argument_list|()
block|;
name|void
name|createTextFormatsGroupBox
argument_list|()
block|;
name|QComboBox
operator|*
name|createColorComboBox
argument_list|()
block|;
name|QGroupBox
operator|*
name|previewGroupBox
block|;
name|QGridLayout
operator|*
name|previewLayout
block|;
name|QCalendarWidget
operator|*
name|calendar
block|;
name|QGroupBox
operator|*
name|generalOptionsGroupBox
block|;
name|QLabel
operator|*
name|localeLabel
block|;
name|QLabel
operator|*
name|firstDayLabel
block|;
comment|//! [0]
name|QLabel
operator|*
name|selectionModeLabel
block|;
name|QLabel
operator|*
name|horizontalHeaderLabel
block|;
name|QLabel
operator|*
name|verticalHeaderLabel
block|;
name|QComboBox
operator|*
name|localeCombo
block|;
name|QComboBox
operator|*
name|firstDayCombo
block|;
name|QComboBox
operator|*
name|selectionModeCombo
block|;
name|QCheckBox
operator|*
name|gridCheckBox
block|;
name|QCheckBox
operator|*
name|navigationCheckBox
block|;
name|QComboBox
operator|*
name|horizontalHeaderCombo
block|;
name|QComboBox
operator|*
name|verticalHeaderCombo
block|;
name|QGroupBox
operator|*
name|datesGroupBox
block|;
name|QLabel
operator|*
name|currentDateLabel
block|;
name|QLabel
operator|*
name|minimumDateLabel
block|;
name|QLabel
operator|*
name|maximumDateLabel
block|;
name|QDateEdit
operator|*
name|currentDateEdit
block|;
name|QDateEdit
operator|*
name|minimumDateEdit
block|;
name|QDateEdit
operator|*
name|maximumDateEdit
block|;
name|QGroupBox
operator|*
name|textFormatsGroupBox
block|;
name|QLabel
operator|*
name|weekdayColorLabel
block|;
name|QLabel
operator|*
name|weekendColorLabel
block|;
name|QLabel
operator|*
name|headerTextFormatLabel
block|;
name|QComboBox
operator|*
name|weekdayColorCombo
block|;
name|QComboBox
operator|*
name|weekendColorCombo
block|;
name|QComboBox
operator|*
name|headerTextFormatCombo
block|;
name|QCheckBox
operator|*
name|firstFridayCheckBox
block|;
comment|//! [1]
name|QCheckBox
operator|*
name|mayFirstCheckBox
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [1]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
