begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QValidator>
end_include
begin_include
include|#
directive|include
file|"ui_validators.h"
end_include
begin_class
DECL|class|ValidatorWidget
class|class
name|ValidatorWidget
super|:
specifier|public
name|QWidget
super|,
specifier|public
name|Ui
operator|::
name|ValidatorsForm
block|{
name|Q_OBJECT
public|public:
name|ValidatorWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
private|private
name|slots
private|:
name|void
name|updateValidator
parameter_list|()
function_decl|;
name|void
name|updateDoubleValidator
parameter_list|()
function_decl|;
DECL|function|_setLocale
name|void
name|_setLocale
parameter_list|(
specifier|const
name|QLocale
modifier|&
name|l
parameter_list|)
block|{
name|setLocale
argument_list|(
name|l
argument_list|)
expr_stmt|;
name|updateValidator
argument_list|()
expr_stmt|;
name|updateDoubleValidator
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|validator
name|QIntValidator
modifier|*
name|validator
decl_stmt|;
DECL|member|doubleValidator
name|QDoubleValidator
modifier|*
name|doubleValidator
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|ValidatorWidget
name|ValidatorWidget
operator|::
name|ValidatorWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|localeSelector
argument_list|,
name|SIGNAL
argument_list|(
name|localeSelected
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_setLocale
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|minVal
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateValidator
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|maxVal
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateValidator
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|editor
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|,
name|ledWidget
argument_list|,
name|SLOT
argument_list|(
name|flash
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|doubleMaxVal
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateDoubleValidator
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|doubleMinVal
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateDoubleValidator
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|doubleDecimals
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
name|updateDoubleValidator
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|doubleFormat
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
name|updateDoubleValidator
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|doubleEditor
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|,
name|doubleLedWidget
argument_list|,
name|SLOT
argument_list|(
name|flash
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|validator
operator|=
literal|0
expr_stmt|;
name|doubleValidator
operator|=
literal|0
expr_stmt|;
name|updateValidator
argument_list|()
expr_stmt|;
name|updateDoubleValidator
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function
DECL|function|updateValidator
name|void
name|ValidatorWidget
operator|::
name|updateValidator
parameter_list|()
block|{
name|QIntValidator
modifier|*
name|v
init|=
operator|new
name|QIntValidator
argument_list|(
name|minVal
operator|->
name|value
argument_list|()
argument_list|,
name|maxVal
operator|->
name|value
argument_list|()
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|v
operator|->
name|setLocale
argument_list|(
name|locale
argument_list|()
argument_list|)
expr_stmt|;
name|editor
operator|->
name|setValidator
argument_list|(
name|v
argument_list|)
expr_stmt|;
operator|delete
name|validator
expr_stmt|;
name|validator
operator|=
name|v
expr_stmt|;
name|QString
name|s
init|=
name|editor
operator|->
name|text
argument_list|()
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|validator
operator|->
name|validate
argument_list|(
name|s
argument_list|,
name|i
argument_list|)
operator|==
name|QValidator
operator|::
name|Invalid
condition|)
block|{
name|editor
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|editor
operator|->
name|setText
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|updateDoubleValidator
name|void
name|ValidatorWidget
operator|::
name|updateDoubleValidator
parameter_list|()
block|{
name|QDoubleValidator
modifier|*
name|v
init|=
operator|new
name|QDoubleValidator
argument_list|(
name|doubleMinVal
operator|->
name|value
argument_list|()
argument_list|,
name|doubleMaxVal
operator|->
name|value
argument_list|()
argument_list|,
name|doubleDecimals
operator|->
name|value
argument_list|()
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|v
operator|->
name|setNotation
argument_list|(
cast|static_cast
argument_list|<
name|QDoubleValidator
operator|::
name|Notation
argument_list|>
argument_list|(
name|doubleFormat
operator|->
name|currentIndex
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|v
operator|->
name|setLocale
argument_list|(
name|locale
argument_list|()
argument_list|)
expr_stmt|;
name|doubleEditor
operator|->
name|setValidator
argument_list|(
name|v
argument_list|)
expr_stmt|;
operator|delete
name|doubleValidator
expr_stmt|;
name|doubleValidator
operator|=
name|v
expr_stmt|;
name|QString
name|s
init|=
name|doubleEditor
operator|->
name|text
argument_list|()
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|doubleValidator
operator|->
name|validate
argument_list|(
name|s
argument_list|,
name|i
argument_list|)
operator|==
name|QValidator
operator|::
name|Invalid
condition|)
block|{
name|doubleEditor
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|doubleEditor
operator|->
name|setText
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|Q_INIT_RESOURCE
argument_list|(
name|validators
argument_list|)
expr_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|ValidatorWidget
name|w
decl_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
