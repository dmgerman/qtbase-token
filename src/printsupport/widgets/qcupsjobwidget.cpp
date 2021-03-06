begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtPrintSupport module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcupsjobwidget_p.h"
end_include
begin_include
include|#
directive|include
file|<QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QDateTime>
end_include
begin_include
include|#
directive|include
file|<QFontDatabase>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QLayout>
end_include
begin_include
include|#
directive|include
file|<QTime>
end_include
begin_include
include|#
directive|include
file|<QTableWidget>
end_include
begin_include
include|#
directive|include
file|<QTableWidgetItem>
end_include
begin_include
include|#
directive|include
file|<QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QPrinter>
end_include
begin_include
include|#
directive|include
file|<QPrintEngine>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_if
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
name|QT_NO_CUPS
argument_list|)
end_if
begin_comment
comment|/*!     \internal     \class QCupsJobWidget      A widget to add to QPrintDialog to enable extra CUPS options     such as Job Scheduling, Job Priority or Job Billing     \ingroup printing     \inmodule QtPrintSupport  */
end_comment
begin_constructor
DECL|function|QCupsJobWidget
name|QCupsJobWidget
operator|::
name|QCupsJobWidget
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
name|m_ui
operator|.
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|//set all the default values
comment|//TODO restore last used values
name|initJobHold
argument_list|()
expr_stmt|;
name|initJobBilling
argument_list|()
expr_stmt|;
name|initJobPriority
argument_list|()
expr_stmt|;
name|initBannerPages
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QCupsJobWidget
name|QCupsJobWidget
operator|::
name|~
name|QCupsJobWidget
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|setPrinter
name|void
name|QCupsJobWidget
operator|::
name|setPrinter
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|)
block|{
name|m_printer
operator|=
name|printer
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupPrinter
name|void
name|QCupsJobWidget
operator|::
name|setupPrinter
parameter_list|()
block|{
name|QCUPSSupport
operator|::
name|setJobHold
argument_list|(
name|m_printer
argument_list|,
name|jobHold
argument_list|()
argument_list|,
name|jobHoldTime
argument_list|()
argument_list|)
expr_stmt|;
name|QCUPSSupport
operator|::
name|setJobBilling
argument_list|(
name|m_printer
argument_list|,
name|jobBilling
argument_list|()
argument_list|)
expr_stmt|;
name|QCUPSSupport
operator|::
name|setJobPriority
argument_list|(
name|m_printer
argument_list|,
name|jobPriority
argument_list|()
argument_list|)
expr_stmt|;
name|QCUPSSupport
operator|::
name|setBannerPages
argument_list|(
name|m_printer
argument_list|,
name|startBannerPage
argument_list|()
argument_list|,
name|endBannerPage
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initJobHold
name|void
name|QCupsJobWidget
operator|::
name|initJobHold
parameter_list|()
block|{
name|m_ui
operator|.
name|jobHoldComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Print Immediately"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|NoHold
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|jobHoldComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Hold Indefinitely"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|Indefinite
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|jobHoldComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Day (06:00 to 17:59)"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|DayTime
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|jobHoldComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Night (18:00 to 05:59)"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|Night
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|jobHoldComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Second Shift (16:00 to 23:59)"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|SecondShift
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|jobHoldComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Third Shift (00:00 to 07:59)"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|ThirdShift
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|jobHoldComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Weekend (Saturday to Sunday)"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|Weekend
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|jobHoldComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Specific Time"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|SpecificTime
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_ui
operator|.
name|jobHoldComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|toggleJobHoldTime
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setJobHold
argument_list|(
name|QCUPSSupport
operator|::
name|NoHold
argument_list|,
name|QTime
argument_list|()
argument_list|)
expr_stmt|;
name|toggleJobHoldTime
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setJobHold
name|void
name|QCupsJobWidget
operator|::
name|setJobHold
parameter_list|(
name|QCUPSSupport
operator|::
name|JobHoldUntil
name|jobHold
parameter_list|,
specifier|const
name|QTime
modifier|&
name|holdUntilTime
parameter_list|)
block|{
if|if
condition|(
name|jobHold
operator|==
name|QCUPSSupport
operator|::
name|SpecificTime
operator|&&
name|holdUntilTime
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|jobHold
operator|=
name|QCUPSSupport
operator|::
name|NoHold
expr_stmt|;
name|toggleJobHoldTime
argument_list|()
expr_stmt|;
block|}
name|m_ui
operator|.
name|jobHoldComboBox
operator|->
name|setCurrentIndex
argument_list|(
name|m_ui
operator|.
name|jobHoldComboBox
operator|->
name|findData
argument_list|(
name|QVariant
operator|::
name|fromValue
argument_list|(
name|jobHold
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|jobHoldTimeEdit
operator|->
name|setTime
argument_list|(
name|holdUntilTime
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|jobHold
name|QCUPSSupport
operator|::
name|JobHoldUntil
name|QCupsJobWidget
operator|::
name|jobHold
parameter_list|()
specifier|const
block|{
return|return
name|m_ui
operator|.
name|jobHoldComboBox
operator|->
name|itemData
argument_list|(
name|m_ui
operator|.
name|jobHoldComboBox
operator|->
name|currentIndex
argument_list|()
argument_list|)
operator|.
name|value
argument_list|<
name|QCUPSSupport
operator|::
name|JobHoldUntil
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toggleJobHoldTime
name|void
name|QCupsJobWidget
operator|::
name|toggleJobHoldTime
parameter_list|()
block|{
if|if
condition|(
name|jobHold
argument_list|()
operator|==
name|QCUPSSupport
operator|::
name|SpecificTime
condition|)
name|m_ui
operator|.
name|jobHoldTimeEdit
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
else|else
name|m_ui
operator|.
name|jobHoldTimeEdit
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|jobHoldTime
name|QTime
name|QCupsJobWidget
operator|::
name|jobHoldTime
parameter_list|()
specifier|const
block|{
return|return
name|m_ui
operator|.
name|jobHoldTimeEdit
operator|->
name|time
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|initJobBilling
name|void
name|QCupsJobWidget
operator|::
name|initJobBilling
parameter_list|()
block|{
name|setJobBilling
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setJobBilling
name|void
name|QCupsJobWidget
operator|::
name|setJobBilling
parameter_list|(
specifier|const
name|QString
modifier|&
name|jobBilling
parameter_list|)
block|{
name|m_ui
operator|.
name|jobBillingLineEdit
operator|->
name|insert
argument_list|(
name|jobBilling
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|jobBilling
name|QString
name|QCupsJobWidget
operator|::
name|jobBilling
parameter_list|()
specifier|const
block|{
return|return
name|m_ui
operator|.
name|jobBillingLineEdit
operator|->
name|text
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|initJobPriority
name|void
name|QCupsJobWidget
operator|::
name|initJobPriority
parameter_list|()
block|{
name|setJobPriority
argument_list|(
literal|50
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setJobPriority
name|void
name|QCupsJobWidget
operator|::
name|setJobPriority
parameter_list|(
name|int
name|jobPriority
parameter_list|)
block|{
name|m_ui
operator|.
name|jobPrioritySpinBox
operator|->
name|setValue
argument_list|(
name|jobPriority
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|jobPriority
name|int
name|QCupsJobWidget
operator|::
name|jobPriority
parameter_list|()
specifier|const
block|{
return|return
name|m_ui
operator|.
name|jobPrioritySpinBox
operator|->
name|value
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|initBannerPages
name|void
name|QCupsJobWidget
operator|::
name|initBannerPages
parameter_list|()
block|{
name|m_ui
operator|.
name|startBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"None"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|NoBanner
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|startBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Standard"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|Standard
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|startBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Unclassified"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|Unclassified
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|startBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Confidential"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|Confidential
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|startBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Classified"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|Classified
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|startBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Secret"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|Secret
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|startBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Top Secret"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|TopSecret
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|endBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"None"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|NoBanner
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|endBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Standard"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|Standard
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|endBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Unclassified"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|Unclassified
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|endBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Confidential"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|Confidential
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|endBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Classified"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|Classified
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|endBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Secret"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|Secret
argument_list|)
argument_list|)
expr_stmt|;
name|m_ui
operator|.
name|endBannerPageCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Top Secret"
argument_list|,
literal|"CUPS Banner page"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QCUPSSupport
operator|::
name|TopSecret
argument_list|)
argument_list|)
expr_stmt|;
name|setStartBannerPage
argument_list|(
name|QCUPSSupport
operator|::
name|NoBanner
argument_list|)
expr_stmt|;
name|setEndBannerPage
argument_list|(
name|QCUPSSupport
operator|::
name|NoBanner
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setStartBannerPage
name|void
name|QCupsJobWidget
operator|::
name|setStartBannerPage
parameter_list|(
specifier|const
name|QCUPSSupport
operator|::
name|BannerPage
name|bannerPage
parameter_list|)
block|{
name|m_ui
operator|.
name|startBannerPageCombo
operator|->
name|setCurrentIndex
argument_list|(
name|m_ui
operator|.
name|startBannerPageCombo
operator|->
name|findData
argument_list|(
name|QVariant
operator|::
name|fromValue
argument_list|(
name|bannerPage
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startBannerPage
name|QCUPSSupport
operator|::
name|BannerPage
name|QCupsJobWidget
operator|::
name|startBannerPage
parameter_list|()
specifier|const
block|{
return|return
name|m_ui
operator|.
name|startBannerPageCombo
operator|->
name|itemData
argument_list|(
name|m_ui
operator|.
name|startBannerPageCombo
operator|->
name|currentIndex
argument_list|()
argument_list|)
operator|.
name|value
argument_list|<
name|QCUPSSupport
operator|::
name|BannerPage
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setEndBannerPage
name|void
name|QCupsJobWidget
operator|::
name|setEndBannerPage
parameter_list|(
specifier|const
name|QCUPSSupport
operator|::
name|BannerPage
name|bannerPage
parameter_list|)
block|{
name|m_ui
operator|.
name|endBannerPageCombo
operator|->
name|setCurrentIndex
argument_list|(
name|m_ui
operator|.
name|endBannerPageCombo
operator|->
name|findData
argument_list|(
name|QVariant
operator|::
name|fromValue
argument_list|(
name|bannerPage
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endBannerPage
name|QCUPSSupport
operator|::
name|BannerPage
name|QCupsJobWidget
operator|::
name|endBannerPage
parameter_list|()
specifier|const
block|{
return|return
name|m_ui
operator|.
name|endBannerPageCombo
operator|->
name|itemData
argument_list|(
name|m_ui
operator|.
name|endBannerPageCombo
operator|->
name|currentIndex
argument_list|()
argument_list|)
operator|.
name|value
argument_list|<
name|QCUPSSupport
operator|::
name|BannerPage
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER / QT_NO_CUPS
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
