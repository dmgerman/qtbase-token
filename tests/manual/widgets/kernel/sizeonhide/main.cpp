begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 ThorbjÃ¸rn Martsum - tmartsum[at]gmail.com ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_class
DECL|class|KeepSizeExampleDlg
class|class
name|KeepSizeExampleDlg
super|:
specifier|public
name|QDialog
block|{
name|Q_OBJECT
public|public:
DECL|member|gridLayout
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
DECL|member|horizontalLayout
name|QHBoxLayout
modifier|*
name|horizontalLayout
decl_stmt|;
DECL|member|verticalLayout
name|QVBoxLayout
modifier|*
name|verticalLayout
decl_stmt|;
DECL|member|checkBox
name|QCheckBox
modifier|*
name|checkBox
decl_stmt|;
DECL|member|checkBox2
name|QCheckBox
modifier|*
name|checkBox2
decl_stmt|;
DECL|member|checkBox3
name|QCheckBox
modifier|*
name|checkBox3
decl_stmt|;
DECL|member|checkBox4
name|QCheckBox
modifier|*
name|checkBox4
decl_stmt|;
DECL|member|groupBox
name|QGroupBox
modifier|*
name|groupBox
decl_stmt|;
DECL|member|verticalLayout2
name|QVBoxLayout
modifier|*
name|verticalLayout2
decl_stmt|;
DECL|member|radioButton
name|QRadioButton
modifier|*
name|radioButton
decl_stmt|;
DECL|member|radioButton2
name|QRadioButton
modifier|*
name|radioButton2
decl_stmt|;
DECL|member|radioButton3
name|QRadioButton
modifier|*
name|radioButton3
decl_stmt|;
DECL|member|tableView
name|QTableView
modifier|*
name|tableView
decl_stmt|;
DECL|member|pushButton
name|QPushButton
modifier|*
name|pushButton
decl_stmt|;
DECL|member|horizontalSpacer
name|QSpacerItem
modifier|*
name|horizontalSpacer
decl_stmt|;
DECL|function|KeepSizeExampleDlg
name|KeepSizeExampleDlg
parameter_list|()
block|{
name|QWidget
modifier|*
name|form
init|=
name|this
decl_stmt|;
name|form
operator|->
name|resize
argument_list|(
literal|408
argument_list|,
literal|295
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
operator|new
name|QGridLayout
argument_list|(
name|form
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|=
operator|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|verticalLayout
operator|=
operator|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
name|checkBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|form
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|checkBox
argument_list|)
expr_stmt|;
name|checkBox2
operator|=
operator|new
name|QCheckBox
argument_list|(
name|form
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|checkBox2
argument_list|)
expr_stmt|;
name|checkBox3
operator|=
operator|new
name|QCheckBox
argument_list|(
name|form
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|checkBox3
argument_list|)
expr_stmt|;
name|checkBox4
operator|=
operator|new
name|QCheckBox
argument_list|(
name|form
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|checkBox4
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addLayout
argument_list|(
name|verticalLayout
argument_list|)
expr_stmt|;
name|groupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|form
argument_list|)
expr_stmt|;
name|verticalLayout2
operator|=
operator|new
name|QVBoxLayout
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|radioButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|verticalLayout2
operator|->
name|addWidget
argument_list|(
name|radioButton
argument_list|)
expr_stmt|;
name|radioButton2
operator|=
operator|new
name|QRadioButton
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|verticalLayout2
operator|->
name|addWidget
argument_list|(
name|radioButton2
argument_list|)
expr_stmt|;
name|radioButton3
operator|=
operator|new
name|QRadioButton
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|verticalLayout2
operator|->
name|addWidget
argument_list|(
name|radioButton3
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addWidget
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addLayout
argument_list|(
name|horizontalLayout
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|tableView
operator|=
operator|new
name|QTableView
argument_list|(
name|form
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|tableView
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|pushButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|form
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|pushButton
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|horizontalSpacer
operator|=
operator|new
name|QSpacerItem
argument_list|(
literal|340
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addItem
argument_list|(
name|horizontalSpacer
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|checkBox
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"CheckBox1"
argument_list|)
argument_list|)
expr_stmt|;
name|checkBox2
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"CheckBox2"
argument_list|)
argument_list|)
expr_stmt|;
name|checkBox3
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"CheckBox - for client A only"
argument_list|)
argument_list|)
expr_stmt|;
name|checkBox4
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"CheckBox - also for client A"
argument_list|)
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setTitle
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"Mode"
argument_list|)
argument_list|)
expr_stmt|;
name|radioButton
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"Mode 1"
argument_list|)
argument_list|)
expr_stmt|;
name|radioButton2
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"Mode 2"
argument_list|)
argument_list|)
expr_stmt|;
name|radioButton3
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"Mode 3"
argument_list|)
argument_list|)
expr_stmt|;
name|pushButton
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"&Hide/Show"
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|pushButton
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
name|showOrHide
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
protected|protected
name|slots
protected|:
DECL|function|showOrHide
name|void
name|showOrHide
parameter_list|()
block|{
if|if
condition|(
name|checkBox3
operator|->
name|isVisible
argument_list|()
condition|)
block|{
name|checkBox3
operator|->
name|hide
argument_list|()
expr_stmt|;
name|checkBox4
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|checkBox3
operator|->
name|show
argument_list|()
expr_stmt|;
name|checkBox4
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
block|}
block|}
class|;
end_class
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
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|KeepSizeExampleDlg
name|d
decl_stmt|;
name|QSizePolicy
name|policyKeepSpace
init|=
name|d
operator|.
name|checkBox3
operator|->
name|sizePolicy
argument_list|()
decl_stmt|;
name|policyKeepSpace
operator|.
name|setRetainSizeWhenHidden
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|d
operator|.
name|checkBox3
operator|->
name|setSizePolicy
argument_list|(
name|policyKeepSpace
argument_list|)
expr_stmt|;
name|d
operator|.
name|checkBox4
operator|->
name|setSizePolicy
argument_list|(
name|policyKeepSpace
argument_list|)
expr_stmt|;
name|d
operator|.
name|show
argument_list|()
expr_stmt|;
name|app
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
