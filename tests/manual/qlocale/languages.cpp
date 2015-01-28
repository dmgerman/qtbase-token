begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"languages.h"
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QListWidget>
end_include
begin_include
include|#
directive|include
file|<QHBoxLayout>
end_include
begin_constructor
DECL|function|LanguagesWidget
name|LanguagesWidget
operator|::
name|LanguagesWidget
parameter_list|()
block|{
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
name|languagesLabel
operator|=
operator|new
name|QLabel
argument_list|(
literal|"Preferred languages:"
argument_list|)
expr_stmt|;
name|languagesList
operator|=
operator|new
name|QListWidget
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|languagesLabel
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|languagesList
argument_list|)
expr_stmt|;
name|localeChanged
argument_list|(
name|QLocale
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|localeChanged
name|void
name|LanguagesWidget
operator|::
name|localeChanged
parameter_list|(
name|QLocale
name|locale
parameter_list|)
block|{
name|languagesList
operator|->
name|clear
argument_list|()
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|lang
decl|,
name|locale
operator|.
name|uiLanguages
argument_list|()
control|)
block|{
name|QListWidgetItem
modifier|*
name|item
init|=
operator|new
name|QListWidgetItem
argument_list|(
name|lang
argument_list|,
name|languagesList
argument_list|)
decl_stmt|;
name|QLocale
name|l
argument_list|(
name|lang
argument_list|)
decl_stmt|;
if|if
condition|(
name|l
operator|.
name|language
argument_list|()
operator|!=
name|QLocale
operator|::
name|C
condition|)
block|{
name|QString
name|language
init|=
name|QLocale
operator|::
name|languageToString
argument_list|(
name|l
operator|.
name|language
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|country
init|=
name|QLocale
operator|::
name|countryToString
argument_list|(
name|l
operator|.
name|country
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|tooltip
init|=
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"%1: %2/%3"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|l
operator|.
name|name
argument_list|()
argument_list|,
name|language
argument_list|,
name|country
argument_list|)
decl_stmt|;
name|item
operator|->
name|setToolTip
argument_list|(
name|tooltip
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
end_unit
