begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QPrinter>
end_include
begin_include
include|#
directive|include
file|<QPrintDialog>
end_include
begin_include
include|#
directive|include
file|"licensewizard.h"
end_include
begin_comment
comment|//! [0] //! [1] //! [2]
end_comment
begin_constructor
DECL|function|LicenseWizard
name|LicenseWizard
operator|::
name|LicenseWizard
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
comment|//! [0]
name|setPage
argument_list|(
name|Page_Intro
argument_list|,
operator|new
name|IntroPage
argument_list|)
expr_stmt|;
name|setPage
argument_list|(
name|Page_Evaluate
argument_list|,
operator|new
name|EvaluatePage
argument_list|)
expr_stmt|;
name|setPage
argument_list|(
name|Page_Register
argument_list|,
operator|new
name|RegisterPage
argument_list|)
expr_stmt|;
name|setPage
argument_list|(
name|Page_Details
argument_list|,
operator|new
name|DetailsPage
argument_list|)
expr_stmt|;
name|setPage
argument_list|(
name|Page_Conclusion
argument_list|,
operator|new
name|ConclusionPage
argument_list|)
expr_stmt|;
comment|//! [1]
name|setStartId
argument_list|(
name|Page_Intro
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
ifndef|#
directive|ifndef
name|Q_OS_MAC
comment|//! [3] //! [4]
name|setWizardStyle
argument_list|(
name|ModernStyle
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|//! [4] //! [5]
name|setOption
argument_list|(
name|HaveHelpButton
argument_list|,
literal|true
argument_list|)
expr_stmt|;
comment|//! [5] //! [6]
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|LogoPixmap
argument_list|,
name|QPixmap
argument_list|(
literal|":/images/logo.png"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [7]
name|connect
argument_list|(
name|this
argument_list|,
operator|&
name|QWizard
operator|::
name|helpRequested
argument_list|,
name|this
argument_list|,
operator|&
name|LicenseWizard
operator|::
name|showHelp
argument_list|)
expr_stmt|;
comment|//! [7]
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"License Wizard"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [8]
block|}
end_constructor
begin_comment
comment|//! [6] //! [8]
end_comment
begin_comment
comment|//! [9] //! [10]
end_comment
begin_function
DECL|function|showHelp
name|void
name|LicenseWizard
operator|::
name|showHelp
parameter_list|()
comment|//! [9] //! [11]
block|{
specifier|static
name|QString
name|lastHelpMessage
decl_stmt|;
name|QString
name|message
decl_stmt|;
switch|switch
condition|(
name|currentId
argument_list|()
condition|)
block|{
case|case
name|Page_Intro
case|:
name|message
operator|=
name|tr
argument_list|(
literal|"The decision you make here will affect which page you "
literal|"get to see next."
argument_list|)
expr_stmt|;
break|break;
comment|//! [10] //! [11]
case|case
name|Page_Evaluate
case|:
name|message
operator|=
name|tr
argument_list|(
literal|"Make sure to provide a valid email address, such as "
literal|"toni.buddenbrook@example.de."
argument_list|)
expr_stmt|;
break|break;
case|case
name|Page_Register
case|:
name|message
operator|=
name|tr
argument_list|(
literal|"If you don't provide an upgrade key, you will be "
literal|"asked to fill in your details."
argument_list|)
expr_stmt|;
break|break;
case|case
name|Page_Details
case|:
name|message
operator|=
name|tr
argument_list|(
literal|"Make sure to provide a valid email address, such as "
literal|"thomas.gradgrind@example.co.uk."
argument_list|)
expr_stmt|;
break|break;
case|case
name|Page_Conclusion
case|:
name|message
operator|=
name|tr
argument_list|(
literal|"You must accept the terms and conditions of the "
literal|"license to proceed."
argument_list|)
expr_stmt|;
break|break;
comment|//! [12] //! [13]
default|default:
name|message
operator|=
name|tr
argument_list|(
literal|"This help is likely not to be of any help."
argument_list|)
expr_stmt|;
block|}
comment|//! [12]
if|if
condition|(
name|lastHelpMessage
operator|==
name|message
condition|)
name|message
operator|=
name|tr
argument_list|(
literal|"Sorry, I already gave what help I could. "
literal|"Maybe you should try asking a human?"
argument_list|)
expr_stmt|;
comment|//! [14]
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"License Wizard Help"
argument_list|)
argument_list|,
name|message
argument_list|)
expr_stmt|;
comment|//! [14]
name|lastHelpMessage
operator|=
name|message
expr_stmt|;
comment|//! [15]
block|}
end_function
begin_comment
comment|//! [13] //! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_constructor
DECL|function|IntroPage
name|IntroPage
operator|::
name|IntroPage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWizardPage
argument_list|(
name|parent
argument_list|)
block|{
name|setTitle
argument_list|(
name|tr
argument_list|(
literal|"Introduction"
argument_list|)
argument_list|)
expr_stmt|;
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|WatermarkPixmap
argument_list|,
name|QPixmap
argument_list|(
literal|":/images/watermark.png"
argument_list|)
argument_list|)
expr_stmt|;
name|topLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"This wizard will help you register your copy of "
literal|"<i>Super Product One</i>&trade; or start "
literal|"evaluating the product."
argument_list|)
argument_list|)
expr_stmt|;
name|topLabel
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|registerRadioButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"&Register your copy"
argument_list|)
argument_list|)
expr_stmt|;
name|evaluateRadioButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"&Evaluate the product for 30 "
literal|"days"
argument_list|)
argument_list|)
expr_stmt|;
name|registerRadioButton
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|topLabel
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|registerRadioButton
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|evaluateRadioButton
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [16] //! [17]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_function
DECL|function|nextId
name|int
name|IntroPage
operator|::
name|nextId
parameter_list|()
specifier|const
comment|//! [17] //! [19]
block|{
if|if
condition|(
name|evaluateRadioButton
operator|->
name|isChecked
argument_list|()
condition|)
block|{
return|return
name|LicenseWizard
operator|::
name|Page_Evaluate
return|;
block|}
else|else
block|{
return|return
name|LicenseWizard
operator|::
name|Page_Register
return|;
block|}
block|}
end_function
begin_comment
comment|//! [18] //! [19]
end_comment
begin_comment
comment|//! [20]
end_comment
begin_constructor
DECL|function|EvaluatePage
name|EvaluatePage
operator|::
name|EvaluatePage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWizardPage
argument_list|(
name|parent
argument_list|)
block|{
name|setTitle
argument_list|(
name|tr
argument_list|(
literal|"Evaluate<i>Super Product One</i>&trade;"
argument_list|)
argument_list|)
expr_stmt|;
name|setSubTitle
argument_list|(
name|tr
argument_list|(
literal|"Please fill both fields. Make sure to provide a valid "
literal|"email address (e.g., john.smith@example.com)."
argument_list|)
argument_list|)
expr_stmt|;
name|nameLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"N&ame:"
argument_list|)
argument_list|)
expr_stmt|;
name|nameLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
comment|//! [20]
name|nameLabel
operator|->
name|setBuddy
argument_list|(
name|nameLineEdit
argument_list|)
expr_stmt|;
name|emailLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Email address:"
argument_list|)
argument_list|)
expr_stmt|;
name|emailLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|emailLineEdit
operator|->
name|setValidator
argument_list|(
operator|new
name|QRegExpValidator
argument_list|(
name|QRegExp
argument_list|(
literal|".*@.*"
argument_list|)
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|emailLabel
operator|->
name|setBuddy
argument_list|(
name|emailLineEdit
argument_list|)
expr_stmt|;
comment|//! [21]
name|registerField
argument_list|(
literal|"evaluate.name*"
argument_list|,
name|nameLineEdit
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"evaluate.email*"
argument_list|,
name|emailLineEdit
argument_list|)
expr_stmt|;
comment|//! [21]
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|nameLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|nameLineEdit
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|emailLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|emailLineEdit
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
comment|//! [22]
block|}
end_constructor
begin_comment
comment|//! [22]
end_comment
begin_comment
comment|//! [23]
end_comment
begin_function
DECL|function|nextId
name|int
name|EvaluatePage
operator|::
name|nextId
parameter_list|()
specifier|const
block|{
return|return
name|LicenseWizard
operator|::
name|Page_Conclusion
return|;
block|}
end_function
begin_comment
comment|//! [23]
end_comment
begin_constructor
DECL|function|RegisterPage
name|RegisterPage
operator|::
name|RegisterPage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWizardPage
argument_list|(
name|parent
argument_list|)
block|{
name|setTitle
argument_list|(
name|tr
argument_list|(
literal|"Register Your Copy of<i>Super Product One</i>&trade;"
argument_list|)
argument_list|)
expr_stmt|;
name|setSubTitle
argument_list|(
name|tr
argument_list|(
literal|"If you have an upgrade key, please fill in "
literal|"the appropriate field."
argument_list|)
argument_list|)
expr_stmt|;
name|nameLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"N&ame:"
argument_list|)
argument_list|)
expr_stmt|;
name|nameLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|nameLabel
operator|->
name|setBuddy
argument_list|(
name|nameLineEdit
argument_list|)
expr_stmt|;
name|upgradeKeyLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Upgrade key:"
argument_list|)
argument_list|)
expr_stmt|;
name|upgradeKeyLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|upgradeKeyLabel
operator|->
name|setBuddy
argument_list|(
name|upgradeKeyLineEdit
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"register.name*"
argument_list|,
name|nameLineEdit
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"register.upgradeKey"
argument_list|,
name|upgradeKeyLineEdit
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|nameLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|nameLineEdit
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|upgradeKeyLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|upgradeKeyLineEdit
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [24]
end_comment
begin_function
DECL|function|nextId
name|int
name|RegisterPage
operator|::
name|nextId
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|upgradeKeyLineEdit
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
return|return
name|LicenseWizard
operator|::
name|Page_Details
return|;
block|}
else|else
block|{
return|return
name|LicenseWizard
operator|::
name|Page_Conclusion
return|;
block|}
block|}
end_function
begin_comment
comment|//! [24]
end_comment
begin_constructor
DECL|function|DetailsPage
name|DetailsPage
operator|::
name|DetailsPage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWizardPage
argument_list|(
name|parent
argument_list|)
block|{
name|setTitle
argument_list|(
name|tr
argument_list|(
literal|"Fill In Your Details"
argument_list|)
argument_list|)
expr_stmt|;
name|setSubTitle
argument_list|(
name|tr
argument_list|(
literal|"Please fill all three fields. Make sure to provide a valid "
literal|"email address (e.g., tanaka.aya@example.co.jp)."
argument_list|)
argument_list|)
expr_stmt|;
name|companyLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Company name:"
argument_list|)
argument_list|)
expr_stmt|;
name|companyLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|companyLabel
operator|->
name|setBuddy
argument_list|(
name|companyLineEdit
argument_list|)
expr_stmt|;
name|emailLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Email address:"
argument_list|)
argument_list|)
expr_stmt|;
name|emailLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|emailLineEdit
operator|->
name|setValidator
argument_list|(
operator|new
name|QRegExpValidator
argument_list|(
name|QRegExp
argument_list|(
literal|".*@.*"
argument_list|)
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|emailLabel
operator|->
name|setBuddy
argument_list|(
name|emailLineEdit
argument_list|)
expr_stmt|;
name|postalLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Postal address:"
argument_list|)
argument_list|)
expr_stmt|;
name|postalLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|postalLabel
operator|->
name|setBuddy
argument_list|(
name|postalLineEdit
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"details.company*"
argument_list|,
name|companyLineEdit
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"details.email*"
argument_list|,
name|emailLineEdit
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"details.postal*"
argument_list|,
name|postalLineEdit
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|companyLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|companyLineEdit
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|emailLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|emailLineEdit
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|postalLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|postalLineEdit
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [25]
end_comment
begin_function
DECL|function|nextId
name|int
name|DetailsPage
operator|::
name|nextId
parameter_list|()
specifier|const
block|{
return|return
name|LicenseWizard
operator|::
name|Page_Conclusion
return|;
block|}
end_function
begin_comment
comment|//! [25]
end_comment
begin_constructor
DECL|function|ConclusionPage
name|ConclusionPage
operator|::
name|ConclusionPage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWizardPage
argument_list|(
name|parent
argument_list|)
block|{
name|setTitle
argument_list|(
name|tr
argument_list|(
literal|"Complete Your Registration"
argument_list|)
argument_list|)
expr_stmt|;
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|WatermarkPixmap
argument_list|,
name|QPixmap
argument_list|(
literal|":/images/watermark.png"
argument_list|)
argument_list|)
expr_stmt|;
name|bottomLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|bottomLabel
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|agreeCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"I agree to the terms of the license"
argument_list|)
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"conclusion.agree*"
argument_list|,
name|agreeCheckBox
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|bottomLabel
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|agreeCheckBox
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [26]
end_comment
begin_function
DECL|function|nextId
name|int
name|ConclusionPage
operator|::
name|nextId
parameter_list|()
specifier|const
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_comment
comment|//! [26]
end_comment
begin_comment
comment|//! [27]
end_comment
begin_function
DECL|function|initializePage
name|void
name|ConclusionPage
operator|::
name|initializePage
parameter_list|()
block|{
name|QString
name|licenseText
decl_stmt|;
if|if
condition|(
name|wizard
argument_list|()
operator|->
name|hasVisitedPage
argument_list|(
name|LicenseWizard
operator|::
name|Page_Evaluate
argument_list|)
condition|)
block|{
name|licenseText
operator|=
name|tr
argument_list|(
literal|"<u>Evaluation License Agreement:</u> "
literal|"You can use this software for 30 days and make one "
literal|"backup, but you are not allowed to distribute it."
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|wizard
argument_list|()
operator|->
name|hasVisitedPage
argument_list|(
name|LicenseWizard
operator|::
name|Page_Details
argument_list|)
condition|)
block|{
name|licenseText
operator|=
name|tr
argument_list|(
literal|"<u>First-Time License Agreement:</u> "
literal|"You can use this software subject to the license "
literal|"you will receive by email."
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|licenseText
operator|=
name|tr
argument_list|(
literal|"<u>Upgrade License Agreement:</u> "
literal|"This software is licensed under the terms of your "
literal|"current license."
argument_list|)
expr_stmt|;
block|}
name|bottomLabel
operator|->
name|setText
argument_list|(
name|licenseText
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [27]
end_comment
begin_comment
comment|//! [28]
end_comment
begin_function
DECL|function|setVisible
name|void
name|ConclusionPage
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|QWizardPage
operator|::
name|setVisible
argument_list|(
name|visible
argument_list|)
expr_stmt|;
if|if
condition|(
name|visible
condition|)
block|{
comment|//! [29]
name|wizard
argument_list|()
operator|->
name|setButtonText
argument_list|(
name|QWizard
operator|::
name|CustomButton1
argument_list|,
name|tr
argument_list|(
literal|"&Print"
argument_list|)
argument_list|)
expr_stmt|;
name|wizard
argument_list|()
operator|->
name|setOption
argument_list|(
name|QWizard
operator|::
name|HaveCustomButton1
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|wizard
argument_list|()
argument_list|,
operator|&
name|QWizard
operator|::
name|customButtonClicked
argument_list|,
name|this
argument_list|,
operator|&
name|ConclusionPage
operator|::
name|printButtonClicked
argument_list|)
expr_stmt|;
comment|//! [29]
block|}
else|else
block|{
name|wizard
argument_list|()
operator|->
name|setOption
argument_list|(
name|QWizard
operator|::
name|HaveCustomButton1
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|wizard
argument_list|()
argument_list|,
operator|&
name|QWizard
operator|::
name|customButtonClicked
argument_list|,
name|this
argument_list|,
operator|&
name|ConclusionPage
operator|::
name|printButtonClicked
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [28]
end_comment
begin_function
DECL|function|printButtonClicked
name|void
name|ConclusionPage
operator|::
name|printButtonClicked
parameter_list|()
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_PRINTER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_PRINTDIALOG
argument_list|)
name|QPrinter
name|printer
decl_stmt|;
name|QPrintDialog
name|dialog
argument_list|(
operator|&
name|printer
argument_list|,
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|dialog
operator|.
name|exec
argument_list|()
condition|)
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Print License"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"As an environmentally friendly measure, the "
literal|"license text will not actually be printed."
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
end_unit
