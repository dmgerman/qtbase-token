begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|"calendar.h"
end_include
begin_include
include|#
directive|include
file|"currency.h"
end_include
begin_include
include|#
directive|include
file|"languages.h"
end_include
begin_include
include|#
directive|include
file|"dateformats.h"
end_include
begin_include
include|#
directive|include
file|"numberformats.h"
end_include
begin_include
include|#
directive|include
file|"miscellaneous.h"
end_include
begin_include
include|#
directive|include
file|"info.h"
end_include
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QComboBox
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Window
range|:
name|public
name|QMainWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|Window
argument_list|()
block|;
name|QLabel
operator|*
name|localeName
block|;
name|QComboBox
operator|*
name|localeCombo
block|;
name|QTabWidget
operator|*
name|tabWidget
block|;
name|CalendarWidget
operator|*
name|calendar
block|;
name|CurrencyWidget
operator|*
name|currency
block|;
name|LanguagesWidget
operator|*
name|languages
block|;
name|DateFormatsWidget
operator|*
name|dateFormats
block|;
name|NumberFormatsWidget
operator|*
name|numberFormats
block|;
name|MiscWidget
operator|*
name|miscellaneous
block|;
name|InfoWidget
operator|*
name|info
block|;
name|private
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|systemLocaleChanged
argument_list|()
block|;
name|signals
operator|:
name|void
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|localeChanged
argument_list|(
name|int
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
