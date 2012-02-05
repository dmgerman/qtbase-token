begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LICENSEWIZARD_H
end_ifndef
begin_define
DECL|macro|LICENSEWIZARD_H
define|#
directive|define
name|LICENSEWIZARD_H
end_define
begin_include
include|#
directive|include
file|<QWizard>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCheckBox
name|class
name|QCheckBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRadioButton
name|class
name|QRadioButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0] //! [1]
name|class
name|LicenseWizard
range|:
name|public
name|QWizard
block|{
comment|//! [0]
name|Q_OBJECT
name|public
operator|:
comment|//! [2]
expr|enum
block|{
name|Page_Intro
block|,
name|Page_Evaluate
block|,
name|Page_Register
block|,
name|Page_Details
block|,
name|Page_Conclusion
block|}
block|;
comment|//! [2]
name|LicenseWizard
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|showHelp
argument_list|()
block|;
comment|//! [3]
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [1] //! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
name|class
name|IntroPage
range|:
name|public
name|QWizardPage
block|{
name|Q_OBJECT
name|public
operator|:
name|IntroPage
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|int
name|nextId
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QLabel
operator|*
name|topLabel
block|;
name|QRadioButton
operator|*
name|registerRadioButton
block|;
name|QRadioButton
operator|*
name|evaluateRadioButton
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
name|class
name|EvaluatePage
range|:
name|public
name|QWizardPage
block|{
name|Q_OBJECT
name|public
operator|:
name|EvaluatePage
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|int
name|nextId
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QLabel
operator|*
name|nameLabel
block|;
name|QLabel
operator|*
name|emailLabel
block|;
name|QLineEdit
operator|*
name|nameLineEdit
block|;
name|QLineEdit
operator|*
name|emailLineEdit
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
name|class
name|RegisterPage
range|:
name|public
name|QWizardPage
block|{
name|Q_OBJECT
name|public
operator|:
name|RegisterPage
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|int
name|nextId
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QLabel
operator|*
name|nameLabel
block|;
name|QLabel
operator|*
name|upgradeKeyLabel
block|;
name|QLineEdit
operator|*
name|nameLineEdit
block|;
name|QLineEdit
operator|*
name|upgradeKeyLineEdit
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|DetailsPage
range|:
name|public
name|QWizardPage
block|{
name|Q_OBJECT
name|public
operator|:
name|DetailsPage
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|int
name|nextId
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QLabel
operator|*
name|companyLabel
block|;
name|QLabel
operator|*
name|emailLabel
block|;
name|QLabel
operator|*
name|postalLabel
block|;
name|QLineEdit
operator|*
name|companyLineEdit
block|;
name|QLineEdit
operator|*
name|emailLineEdit
block|;
name|QLineEdit
operator|*
name|postalLineEdit
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
name|class
name|ConclusionPage
range|:
name|public
name|QWizardPage
block|{
name|Q_OBJECT
name|public
operator|:
name|ConclusionPage
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|initializePage
argument_list|()
block|;
name|int
name|nextId
argument_list|()
specifier|const
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|printButtonClicked
argument_list|()
block|;
name|private
operator|:
name|QLabel
operator|*
name|bottomLabel
block|;
name|QCheckBox
operator|*
name|agreeCheckBox
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [6]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
