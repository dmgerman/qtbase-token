begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|nextId
name|int
name|LicenseWizard
operator|::
name|nextId
parameter_list|()
specifier|const
block|{
switch|switch
condition|(
name|currentId
argument_list|()
condition|)
block|{
case|case
name|Page_Intro
case|:
if|if
condition|(
name|field
argument_list|(
literal|"intro.evaluate"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
return|return
name|Page_Evaluate
return|;
block|}
else|else
block|{
return|return
name|Page_Register
return|;
block|}
case|case
name|Page_Evaluate
case|:
return|return
name|Page_Conclusion
return|;
case|case
name|Page_Register
case|:
if|if
condition|(
name|field
argument_list|(
literal|"register.upgradeKey"
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
return|return
name|Page_Details
return|;
block|}
else|else
block|{
return|return
name|Page_Conclusion
return|;
block|}
case|case
name|Page_Details
case|:
return|return
name|Page_Conclusion
return|;
case|case
name|Page_Conclusion
case|:
default|default:
return|return
operator|-
literal|1
return|;
block|}
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_constructor
DECL|function|MyWizard
name|MyWizard
operator|::
name|MyWizard
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWizard
argument_list|(
name|parent
argument_list|)
block|{
operator|...
name|QList
argument_list|<
name|QWizard
operator|::
name|WizardButton
argument_list|>
name|layout
expr_stmt|;
name|layout
operator|<<
name|QWizard
operator|::
name|Stretch
operator|<<
name|QWizard
operator|::
name|BackButton
operator|<<
name|QWizard
operator|::
name|CancelButton
operator|<<
name|QWizard
operator|::
name|NextButton
operator|<<
name|QWizard
operator|::
name|FinishButton
expr_stmt|;
name|setButtonLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
operator|...
block|}
end_constructor
begin_comment
comment|//! [1]
end_comment
end_unit
