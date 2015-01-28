begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"filterwidget.h"
end_include
begin_include
include|#
directive|include
file|<QIcon>
end_include
begin_include
include|#
directive|include
file|<QPixmap>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QMenu>
end_include
begin_include
include|#
directive|include
file|<QAction>
end_include
begin_include
include|#
directive|include
file|<QActionGroup>
end_include
begin_include
include|#
directive|include
file|<QToolButton>
end_include
begin_include
include|#
directive|include
file|<QWidgetAction>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_constructor
DECL|function|FilterWidget
name|FilterWidget
operator|::
name|FilterWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QLineEdit
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_patternGroup
argument_list|(
operator|new
name|QActionGroup
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|setClearButtonEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
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
name|SIGNAL
argument_list|(
name|filterChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|menu
init|=
operator|new
name|QMenu
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|m_caseSensitivityAction
operator|=
name|menu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Case Sensitive"
argument_list|)
argument_list|)
expr_stmt|;
name|m_caseSensitivityAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_caseSensitivityAction
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
name|SIGNAL
argument_list|(
name|filterChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|m_patternGroup
operator|->
name|setExclusive
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|patternAction
init|=
name|menu
operator|->
name|addAction
argument_list|(
literal|"Fixed String"
argument_list|)
decl_stmt|;
name|patternAction
operator|->
name|setData
argument_list|(
name|QVariant
argument_list|(
name|int
argument_list|(
name|QRegExp
operator|::
name|FixedString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|patternAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|patternAction
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m_patternGroup
operator|->
name|addAction
argument_list|(
name|patternAction
argument_list|)
expr_stmt|;
name|patternAction
operator|=
name|menu
operator|->
name|addAction
argument_list|(
literal|"Regular Expression"
argument_list|)
expr_stmt|;
name|patternAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|patternAction
operator|->
name|setData
argument_list|(
name|QVariant
argument_list|(
name|int
argument_list|(
name|QRegExp
operator|::
name|RegExp2
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_patternGroup
operator|->
name|addAction
argument_list|(
name|patternAction
argument_list|)
expr_stmt|;
name|patternAction
operator|=
name|menu
operator|->
name|addAction
argument_list|(
literal|"Wildcard"
argument_list|)
expr_stmt|;
name|patternAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|patternAction
operator|->
name|setData
argument_list|(
name|QVariant
argument_list|(
name|int
argument_list|(
name|QRegExp
operator|::
name|Wildcard
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_patternGroup
operator|->
name|addAction
argument_list|(
name|patternAction
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_patternGroup
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|QAction
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|filterChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QIcon
name|icon
init|=
name|QIcon
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/find.png"
argument_list|)
argument_list|)
decl_stmt|;
name|QToolButton
modifier|*
name|optionsButton
init|=
operator|new
name|QToolButton
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|optionsButton
operator|->
name|setCursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|optionsButton
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|NoFocus
argument_list|)
expr_stmt|;
name|optionsButton
operator|->
name|setStyleSheet
argument_list|(
literal|"* { border: none; }"
argument_list|)
expr_stmt|;
name|optionsButton
operator|->
name|setIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
name|optionsButton
operator|->
name|setMenu
argument_list|(
name|menu
argument_list|)
expr_stmt|;
name|optionsButton
operator|->
name|setPopupMode
argument_list|(
name|QToolButton
operator|::
name|InstantPopup
argument_list|)
expr_stmt|;
name|QWidgetAction
modifier|*
name|optionsAction
init|=
operator|new
name|QWidgetAction
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|optionsAction
operator|->
name|setDefaultWidget
argument_list|(
name|optionsButton
argument_list|)
expr_stmt|;
name|addAction
argument_list|(
name|optionsAction
argument_list|,
name|QLineEdit
operator|::
name|LeadingPosition
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|caseSensitivity
name|Qt
operator|::
name|CaseSensitivity
name|FilterWidget
operator|::
name|caseSensitivity
parameter_list|()
specifier|const
block|{
return|return
name|m_caseSensitivityAction
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
return|;
block|}
end_function
begin_function
DECL|function|setCaseSensitivity
name|void
name|FilterWidget
operator|::
name|setCaseSensitivity
parameter_list|(
name|Qt
operator|::
name|CaseSensitivity
name|cs
parameter_list|)
block|{
name|m_caseSensitivityAction
operator|->
name|setChecked
argument_list|(
name|cs
operator|==
name|Qt
operator|::
name|CaseSensitive
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|patternSyntaxFromAction
specifier|static
specifier|inline
name|QRegExp
operator|::
name|PatternSyntax
name|patternSyntaxFromAction
parameter_list|(
specifier|const
name|QAction
modifier|*
name|a
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
name|QRegExp
operator|::
name|PatternSyntax
argument_list|>
argument_list|(
name|a
operator|->
name|data
argument_list|()
operator|.
name|toInt
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|patternSyntax
name|QRegExp
operator|::
name|PatternSyntax
name|FilterWidget
operator|::
name|patternSyntax
parameter_list|()
specifier|const
block|{
return|return
name|patternSyntaxFromAction
argument_list|(
name|m_patternGroup
operator|->
name|checkedAction
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setPatternSyntax
name|void
name|FilterWidget
operator|::
name|setPatternSyntax
parameter_list|(
name|QRegExp
operator|::
name|PatternSyntax
name|s
parameter_list|)
block|{
foreach|foreach
control|(
name|QAction
modifier|*
name|a
decl|,
name|m_patternGroup
operator|->
name|actions
argument_list|()
control|)
block|{
if|if
condition|(
name|patternSyntaxFromAction
argument_list|(
name|a
argument_list|)
operator|==
name|s
condition|)
block|{
name|a
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function
end_unit
