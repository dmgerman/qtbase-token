begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"wizardpanel.h"
end_include
begin_include
include|#
directive|include
file|<QWizard>
end_include
begin_include
include|#
directive|include
file|<QWizardPage>
end_include
begin_include
include|#
directive|include
file|<QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QRadioButton>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QButtonGroup>
end_include
begin_include
include|#
directive|include
file|<QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QStyle>
end_include
begin_include
include|#
directive|include
file|<QIcon>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QFont>
end_include
begin_include
include|#
directive|include
file|<QFontMetrics>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_function
DECL|function|coloredIcon
specifier|static
name|QIcon
name|coloredIcon
parameter_list|(
specifier|const
name|Qt
operator|::
name|GlobalColor
name|color
parameter_list|)
block|{
name|QImage
name|image
argument_list|(
name|QSize
argument_list|(
literal|24
argument_list|,
literal|24
argument_list|)
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|image
operator|.
name|fill
argument_list|(
name|color
argument_list|)
expr_stmt|;
return|return
name|QIcon
argument_list|(
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|pixmapWithText
specifier|static
name|QPixmap
name|pixmapWithText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
specifier|const
name|QColor
name|color
parameter_list|)
block|{
name|QFont
name|font
decl_stmt|;
name|QFontMetrics
name|metric
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|QRect
name|rectangle
init|=
name|metric
operator|.
name|boundingRect
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|rectangle
operator|.
name|setBottomRight
argument_list|(
name|rectangle
operator|.
name|bottomRight
argument_list|()
operator|+
name|QPoint
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|)
argument_list|)
expr_stmt|;
name|QImage
name|image
argument_list|(
name|rectangle
operator|.
name|size
argument_list|()
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|image
operator|.
name|fill
argument_list|(
name|color
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|image
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
name|rectangle
argument_list|,
name|Qt
operator|::
name|AlignHCenter
operator||
name|Qt
operator|::
name|AlignVCenter
argument_list|,
name|text
argument_list|)
expr_stmt|;
return|return
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// A radio-group control for QWizard::WizardStyle.
end_comment
begin_class
DECL|class|WizardStyleControl
class|class
name|WizardStyleControl
super|:
specifier|public
name|QGroupBox
block|{
name|Q_OBJECT
public|public:
name|WizardStyleControl
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
name|void
name|setWizardStyle
parameter_list|(
name|int
name|style
parameter_list|)
function_decl|;
name|QWizard
operator|::
name|WizardStyle
name|wizardStyle
parameter_list|()
specifier|const
function_decl|;
signals|signals:
name|void
name|wizardStyleChanged
parameter_list|(
name|int
parameter_list|)
function_decl|;
private|private:
DECL|member|m_group
name|QButtonGroup
modifier|*
name|m_group
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|WizardStyleControl
name|WizardStyleControl
operator|::
name|WizardStyleControl
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Style"
argument_list|)
argument_list|,
name|parent
argument_list|)
member_init_list|,
name|m_group
argument_list|(
operator|new
name|QButtonGroup
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|m_group
operator|->
name|setExclusive
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_group
argument_list|,
name|SIGNAL
argument_list|(
name|buttonClicked
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|wizardStyleChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|vLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QRadioButton
modifier|*
name|radioButton
init|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"None/OS Default"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|m_group
operator|->
name|addButton
argument_list|(
name|radioButton
argument_list|,
name|QWizard
operator|::
name|NStyles
argument_list|)
expr_stmt|;
name|vLayout
operator|->
name|addWidget
argument_list|(
name|radioButton
argument_list|)
expr_stmt|;
name|radioButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"ClassicStyle"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|m_group
operator|->
name|addButton
argument_list|(
name|radioButton
argument_list|,
name|QWizard
operator|::
name|ClassicStyle
argument_list|)
expr_stmt|;
name|vLayout
operator|->
name|addWidget
argument_list|(
name|radioButton
argument_list|)
expr_stmt|;
name|radioButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"ModernStyle"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|m_group
operator|->
name|addButton
argument_list|(
name|radioButton
argument_list|,
name|QWizard
operator|::
name|ModernStyle
argument_list|)
expr_stmt|;
name|vLayout
operator|->
name|addWidget
argument_list|(
name|radioButton
argument_list|)
expr_stmt|;
name|radioButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"MacStyle"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|m_group
operator|->
name|addButton
argument_list|(
name|radioButton
argument_list|,
name|QWizard
operator|::
name|MacStyle
argument_list|)
expr_stmt|;
name|vLayout
operator|->
name|addWidget
argument_list|(
name|radioButton
argument_list|)
expr_stmt|;
name|radioButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"AeroStyle"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|m_group
operator|->
name|addButton
argument_list|(
name|radioButton
argument_list|,
name|QWizard
operator|::
name|AeroStyle
argument_list|)
expr_stmt|;
name|vLayout
operator|->
name|addWidget
argument_list|(
name|radioButton
argument_list|)
expr_stmt|;
name|vLayout
operator|->
name|addItem
argument_list|(
operator|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|MinimumExpanding
argument_list|)
argument_list|)
expr_stmt|;
name|setWizardStyle
argument_list|(
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_WizardStyle
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|wizardStyle
name|QWizard
operator|::
name|WizardStyle
name|WizardStyleControl
operator|::
name|wizardStyle
parameter_list|()
specifier|const
block|{
return|return
cast|static_cast
argument_list|<
name|QWizard
operator|::
name|WizardStyle
argument_list|>
argument_list|(
name|m_group
operator|->
name|checkedId
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setWizardStyle
name|void
name|WizardStyleControl
operator|::
name|setWizardStyle
parameter_list|(
name|int
name|wizardStyle
parameter_list|)
block|{
if|if
condition|(
name|wizardStyle
argument_list|<
literal|0
operator|||
name|wizardStyle
argument_list|>
name|QWizard
operator|::
name|NStyles
condition|)
name|wizardStyle
operator|=
name|QWizard
operator|::
name|NStyles
expr_stmt|;
name|QAbstractButton
modifier|*
name|button
init|=
name|m_group
operator|->
name|button
argument_list|(
name|wizardStyle
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|button
argument_list|)
expr_stmt|;
specifier|const
name|bool
name|blocked
init|=
name|m_group
operator|->
name|blockSignals
argument_list|(
literal|true
argument_list|)
decl_stmt|;
name|button
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m_group
operator|->
name|blockSignals
argument_list|(
name|blocked
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// A control with checkboxes for QWizard::WizardOption.
end_comment
begin_class
DECL|class|WizardOptionsControl
class|class
name|WizardOptionsControl
super|:
specifier|public
name|QGroupBox
block|{
public|public:
specifier|explicit
name|WizardOptionsControl
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
name|QWizard
operator|::
name|WizardOption
name|wizardOptions
parameter_list|()
specifier|const
function_decl|;
name|void
name|setWizardOptions
parameter_list|(
name|int
name|options
parameter_list|)
function_decl|;
private|private:
DECL|typedef|CheckBoxHash
typedef|typedef
name|QHash
argument_list|<
name|int
argument_list|,
name|QCheckBox
modifier|*
argument_list|>
name|CheckBoxHash
typedef|;
name|void
name|addCheckBox
parameter_list|(
name|QVBoxLayout
modifier|*
name|layout
parameter_list|,
name|int
name|flag
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
function_decl|;
DECL|member|m_checkBoxes
name|CheckBoxHash
name|m_checkBoxes
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|WizardOptionsControl
name|WizardOptionsControl
operator|::
name|WizardOptionsControl
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Options"
argument_list|)
argument_list|,
name|parent
argument_list|)
block|{
name|QVBoxLayout
modifier|*
name|vLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|IndependentPages
argument_list|,
name|QLatin1String
argument_list|(
literal|"IndependentPages"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|IgnoreSubTitles
argument_list|,
name|QLatin1String
argument_list|(
literal|"IgnoreSubTitles"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|ExtendedWatermarkPixmap
argument_list|,
name|QLatin1String
argument_list|(
literal|"ExtendedWatermarkPixmap"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|NoDefaultButton
argument_list|,
name|QLatin1String
argument_list|(
literal|"NoDefaultButton"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|NoBackButtonOnStartPage
argument_list|,
name|QLatin1String
argument_list|(
literal|"NoBackButtonOnStartPage"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|NoBackButtonOnLastPage
argument_list|,
name|QLatin1String
argument_list|(
literal|"NoBackButtonOnLastPage"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|DisabledBackButtonOnLastPage
argument_list|,
name|QLatin1String
argument_list|(
literal|"DisabledBackButtonOnLastPage"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|HaveNextButtonOnLastPage
argument_list|,
name|QLatin1String
argument_list|(
literal|"HaveNextButtonOnLastPage"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|HaveFinishButtonOnEarlyPages
argument_list|,
name|QLatin1String
argument_list|(
literal|"HaveFinishButtonOnEarlyPages"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|NoCancelButton
argument_list|,
name|QLatin1String
argument_list|(
literal|"NoCancelButton"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|CancelButtonOnLeft
argument_list|,
name|QLatin1String
argument_list|(
literal|"CancelButtonOnLeft"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|HaveHelpButton
argument_list|,
name|QLatin1String
argument_list|(
literal|"HaveHelpButton"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|HelpButtonOnRight
argument_list|,
name|QLatin1String
argument_list|(
literal|"HelpButtonOnRight"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|HaveCustomButton1
argument_list|,
name|QLatin1String
argument_list|(
literal|"HaveCustomButton1"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|HaveCustomButton2
argument_list|,
name|QLatin1String
argument_list|(
literal|"HaveCustomButton2"
argument_list|)
argument_list|)
expr_stmt|;
name|addCheckBox
argument_list|(
name|vLayout
argument_list|,
name|QWizard
operator|::
name|HaveCustomButton3
argument_list|,
name|QLatin1String
argument_list|(
literal|"HaveCustomButton3"
argument_list|)
argument_list|)
expr_stmt|;
name|vLayout
operator|->
name|addItem
argument_list|(
operator|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|MinimumExpanding
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|addCheckBox
name|void
name|WizardOptionsControl
operator|::
name|addCheckBox
parameter_list|(
name|QVBoxLayout
modifier|*
name|layout
parameter_list|,
name|int
name|flag
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
block|{
name|QCheckBox
modifier|*
name|checkBox
init|=
operator|new
name|QCheckBox
argument_list|(
name|title
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|checkBox
argument_list|)
expr_stmt|;
name|m_checkBoxes
operator|.
name|insert
argument_list|(
name|flag
argument_list|,
name|checkBox
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wizardOptions
name|QWizard
operator|::
name|WizardOption
name|WizardOptionsControl
operator|::
name|wizardOptions
parameter_list|()
specifier|const
block|{
name|int
name|result
init|=
literal|0
decl_stmt|;
typedef|typedef
name|CheckBoxHash
operator|::
name|const_iterator
name|ConstIterator
typedef|;
specifier|const
name|ConstIterator
name|cend
init|=
name|m_checkBoxes
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
name|ConstIterator
name|it
init|=
name|m_checkBoxes
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
if|if
condition|(
name|it
operator|.
name|value
argument_list|()
operator|->
name|isChecked
argument_list|()
condition|)
name|result
operator||=
name|it
operator|.
name|key
argument_list|()
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|QWizard
operator|::
name|WizardOption
argument_list|>
argument_list|(
name|result
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setWizardOptions
name|void
name|WizardOptionsControl
operator|::
name|setWizardOptions
parameter_list|(
name|int
name|options
parameter_list|)
block|{
typedef|typedef
name|CheckBoxHash
operator|::
name|iterator
name|Iterator
typedef|;
specifier|const
name|Iterator
name|end
init|=
name|m_checkBoxes
operator|.
name|end
argument_list|()
decl_stmt|;
for|for
control|(
name|Iterator
name|it
init|=
name|m_checkBoxes
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
name|it
operator|.
name|value
argument_list|()
operator|->
name|setChecked
argument_list|(
name|options
operator|&
name|it
operator|.
name|key
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// A test wizard with a slot to change its style.
end_comment
begin_class
DECL|class|Wizard
class|class
name|Wizard
super|:
specifier|public
name|QWizard
block|{
name|Q_OBJECT
public|public:
specifier|explicit
name|Wizard
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
literal|0
parameter_list|)
constructor_decl|;
public|public
name|slots
public|:
name|void
name|changeWizardStyle
parameter_list|(
name|int
name|newStyle
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|changeWizardStyle
name|void
name|Wizard
operator|::
name|changeWizardStyle
parameter_list|(
name|int
name|newStyle
parameter_list|)
block|{
if|if
condition|(
name|newStyle
operator|>=
literal|0
operator|&&
name|newStyle
operator|<
name|int
argument_list|(
name|QWizard
operator|::
name|NStyles
argument_list|)
condition|)
name|setWizardStyle
argument_list|(
cast|static_cast
argument_list|<
name|QWizard
operator|::
name|WizardStyle
argument_list|>
argument_list|(
name|newStyle
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// A test wizard page with a WizardStyleControl.
end_comment
begin_class
DECL|class|WizardPage
class|class
name|WizardPage
super|:
specifier|public
name|QWizardPage
block|{
public|public:
specifier|explicit
name|WizardPage
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
name|void
name|initializePage
parameter_list|()
function_decl|;
private|private:
DECL|member|m_styleControl
name|WizardStyleControl
modifier|*
name|m_styleControl
decl_stmt|;
DECL|member|m_firstTimeShown
name|bool
name|m_firstTimeShown
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|WizardPage
name|WizardPage
operator|::
name|WizardPage
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWizardPage
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_styleControl
argument_list|(
operator|new
name|WizardStyleControl
argument_list|(
name|this
argument_list|)
argument_list|)
member_init_list|,
name|m_firstTimeShown
argument_list|(
literal|true
argument_list|)
block|{
name|setTitle
argument_list|(
name|title
argument_list|)
expr_stmt|;
name|setSubTitle
argument_list|(
name|title
operator|+
name|QLatin1String
argument_list|(
literal|" SubTitle"
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|vLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|vLayout
operator|->
name|addWidget
argument_list|(
name|m_styleControl
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|initializePage
name|void
name|WizardPage
operator|::
name|initializePage
parameter_list|()
block|{
name|m_styleControl
operator|->
name|setWizardStyle
argument_list|(
name|wizard
argument_list|()
operator|->
name|wizardStyle
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_firstTimeShown
condition|)
block|{
name|m_firstTimeShown
operator|=
literal|false
expr_stmt|;
name|connect
argument_list|(
name|m_styleControl
argument_list|,
name|SIGNAL
argument_list|(
name|wizardStyleChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|wizard
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|changeWizardStyle
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|Wizard
name|Wizard
operator|::
name|Wizard
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
member_init_list|:
name|QWizard
argument_list|(
name|parent
argument_list|,
name|flags
argument_list|)
block|{
name|setWindowIcon
argument_list|(
name|coloredIcon
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|QLatin1String
argument_list|(
literal|"Wizard "
argument_list|)
operator|+
name|QLatin1String
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
expr_stmt|;
name|addPage
argument_list|(
operator|new
name|WizardPage
argument_list|(
name|tr
argument_list|(
literal|"Page 1"
argument_list|)
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|addPage
argument_list|(
operator|new
name|WizardPage
argument_list|(
name|tr
argument_list|(
literal|"Page 2"
argument_list|)
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|addPage
argument_list|(
operator|new
name|WizardPage
argument_list|(
name|tr
argument_list|(
literal|"Page 3"
argument_list|)
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|// A dialog using a Wizard as child widget (emulating Qt Designer).
end_comment
begin_class
DECL|class|WizardEmbeddingDialog
class|class
name|WizardEmbeddingDialog
super|:
specifier|public
name|QDialog
block|{
public|public:
specifier|explicit
name|WizardEmbeddingDialog
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
DECL|function|wizard
name|Wizard
modifier|*
name|wizard
parameter_list|()
specifier|const
block|{
return|return
name|m_wizard
return|;
block|}
private|private:
DECL|member|m_wizard
name|Wizard
modifier|*
name|m_wizard
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|WizardEmbeddingDialog
name|WizardEmbeddingDialog
operator|::
name|WizardEmbeddingDialog
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_wizard
argument_list|(
operator|new
name|Wizard
argument_list|)
block|{
name|setWindowTitle
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Dialog Embedding QWizard %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
init|=
operator|new
name|QGridLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Above wizard"
argument_list|)
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Left of wizard"
argument_list|)
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_wizard
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"EmbeddedWizard"
argument_list|)
argument_list|)
expr_stmt|;
name|m_wizard
operator|->
name|setParent
argument_list|(
name|this
argument_list|,
name|Qt
operator|::
name|Widget
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|m_wizard
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Right of wizard"
argument_list|)
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Below wizard"
argument_list|)
argument_list|)
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|WizardPanel
name|WizardPanel
operator|::
name|WizardPanel
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
member_init_list|,
name|m_styleControl
argument_list|(
operator|new
name|WizardStyleControl
argument_list|(
name|this
argument_list|)
argument_list|)
member_init_list|,
name|m_optionsControl
argument_list|(
operator|new
name|WizardOptionsControl
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
block|{
name|QWizard
name|wizard
decl_stmt|;
name|m_optionsControl
operator|->
name|setWizardOptions
argument_list|(
name|wizard
operator|.
name|options
argument_list|()
argument_list|)
expr_stmt|;
name|m_styleControl
operator|->
name|setWizardStyle
argument_list|(
name|wizard
operator|.
name|wizardStyle
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QGridLayout
modifier|*
name|gridLayout
init|=
operator|new
name|QGridLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|m_optionsControl
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|m_styleControl
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QGroupBox
modifier|*
name|buttonGroupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|buttonGroupBox
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|button
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Show modal"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|button
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showModal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|vLayout
operator|->
name|addWidget
argument_list|(
name|button
argument_list|)
expr_stmt|;
name|button
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Show non-modal"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|button
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showNonModal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|vLayout
operator|->
name|addWidget
argument_list|(
name|button
argument_list|)
expr_stmt|;
name|button
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Show embedded"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|button
operator|->
name|setToolTip
argument_list|(
name|tr
argument_list|(
literal|"Test QWizard's behavior when used as a widget child."
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|button
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showEmbedded
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|vLayout
operator|->
name|addWidget
argument_list|(
name|button
argument_list|)
expr_stmt|;
name|vLayout
operator|->
name|addItem
argument_list|(
operator|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|MinimumExpanding
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|buttonGroupBox
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|showModal
name|void
name|WizardPanel
operator|::
name|showModal
parameter_list|()
block|{
name|Wizard
name|wizard
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|applyParameters
argument_list|(
operator|&
name|wizard
argument_list|)
expr_stmt|;
name|wizard
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showNonModal
name|void
name|WizardPanel
operator|::
name|showNonModal
parameter_list|()
block|{
name|Wizard
modifier|*
name|wizard
init|=
operator|new
name|Wizard
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|applyParameters
argument_list|(
name|wizard
argument_list|)
expr_stmt|;
name|wizard
operator|->
name|setModal
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|wizard
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|wizard
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showEmbedded
name|void
name|WizardPanel
operator|::
name|showEmbedded
parameter_list|()
block|{
name|WizardEmbeddingDialog
modifier|*
name|dialog
init|=
operator|new
name|WizardEmbeddingDialog
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|applyParameters
argument_list|(
name|dialog
operator|->
name|wizard
argument_list|()
argument_list|)
expr_stmt|;
name|dialog
operator|->
name|setModal
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|dialog
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|dialog
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|applyParameters
name|void
name|WizardPanel
operator|::
name|applyParameters
parameter_list|(
name|QWizard
modifier|*
name|wizard
parameter_list|)
specifier|const
block|{
name|wizard
operator|->
name|setWizardStyle
argument_list|(
name|m_styleControl
operator|->
name|wizardStyle
argument_list|()
argument_list|)
expr_stmt|;
name|wizard
operator|->
name|setOptions
argument_list|(
name|m_optionsControl
operator|->
name|wizardOptions
argument_list|()
argument_list|)
expr_stmt|;
name|wizard
operator|->
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|WatermarkPixmap
argument_list|,
name|pixmapWithText
argument_list|(
name|QLatin1String
argument_list|(
literal|"Watermark"
argument_list|)
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
operator|.
name|lighter
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|wizard
operator|->
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|LogoPixmap
argument_list|,
name|pixmapWithText
argument_list|(
name|QLatin1String
argument_list|(
literal|"Logo"
argument_list|)
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
argument_list|)
expr_stmt|;
name|wizard
operator|->
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|BannerPixmap
argument_list|,
name|pixmapWithText
argument_list|(
name|QLatin1String
argument_list|(
literal|"Banner"
argument_list|)
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
argument_list|)
expr_stmt|;
name|wizard
operator|->
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|BackgroundPixmap
argument_list|,
name|pixmapWithText
argument_list|(
name|QLatin1String
argument_list|(
literal|"Background"
argument_list|)
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
operator|.
name|lighter
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|"wizardpanel.moc"
end_include
end_unit
