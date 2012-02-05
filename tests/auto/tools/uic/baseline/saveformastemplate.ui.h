begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'saveformastemplate.ui' ** ** Created: Fri Sep 4 10:17:14 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SAVEFORMASTEMPLATE_H
end_ifndef
begin_define
DECL|macro|SAVEFORMASTEMPLATE_H
define|#
directive|define
name|SAVEFORMASTEMPLATE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QAction>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QApplication>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QButtonGroup>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QComboBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QDialog>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QDialogButtonBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QFormLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QFrame>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QLabel>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_SaveFormAsTemplate
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QFormLayout
modifier|*
name|formLayout
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QLineEdit
modifier|*
name|templateNameEdit
decl_stmt|;
name|QLabel
modifier|*
name|label_2
decl_stmt|;
name|QComboBox
modifier|*
name|categoryCombo
decl_stmt|;
name|QFrame
modifier|*
name|horizontalLine
decl_stmt|;
name|QDialogButtonBox
modifier|*
name|buttonBox
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|SaveFormAsTemplate
parameter_list|)
block|{
if|if
condition|(
name|SaveFormAsTemplate
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|SaveFormAsTemplate
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"SaveFormAsTemplate"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|SaveFormAsTemplate
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"vboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|formLayout
operator|=
name|new
name|QFormLayout
argument_list|()
expr_stmt|;
name|formLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"formLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|SaveFormAsTemplate
argument_list|)
expr_stmt|;
name|label
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"label"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|NoFrame
argument_list|)
expr_stmt|;
name|label
operator|->
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Plain
argument_list|)
expr_stmt|;
name|label
operator|->
name|setTextFormat
argument_list|(
name|Qt
operator|::
name|AutoText
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|0
argument_list|,
name|QFormLayout
operator|::
name|LabelRole
argument_list|,
name|label
argument_list|)
expr_stmt|;
name|templateNameEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|SaveFormAsTemplate
argument_list|)
expr_stmt|;
name|templateNameEdit
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"templateNameEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|templateNameEdit
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|222
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|templateNameEdit
operator|->
name|setEchoMode
argument_list|(
name|QLineEdit
operator|::
name|Normal
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|0
argument_list|,
name|QFormLayout
operator|::
name|FieldRole
argument_list|,
name|templateNameEdit
argument_list|)
expr_stmt|;
name|label_2
operator|=
name|new
name|QLabel
argument_list|(
name|SaveFormAsTemplate
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"label_2"
argument_list|)
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|NoFrame
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Plain
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setTextFormat
argument_list|(
name|Qt
operator|::
name|AutoText
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|1
argument_list|,
name|QFormLayout
operator|::
name|LabelRole
argument_list|,
name|label_2
argument_list|)
expr_stmt|;
name|categoryCombo
operator|=
name|new
name|QComboBox
argument_list|(
name|SaveFormAsTemplate
argument_list|)
expr_stmt|;
name|categoryCombo
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"categoryCombo"
argument_list|)
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|1
argument_list|,
name|QFormLayout
operator|::
name|FieldRole
argument_list|,
name|categoryCombo
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|formLayout
argument_list|)
expr_stmt|;
name|horizontalLine
operator|=
name|new
name|QFrame
argument_list|(
name|SaveFormAsTemplate
argument_list|)
expr_stmt|;
name|horizontalLine
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"horizontalLine"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLine
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|HLine
argument_list|)
expr_stmt|;
name|horizontalLine
operator|->
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Sunken
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|horizontalLine
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|SaveFormAsTemplate
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"buttonBox"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setStandardButtons
argument_list|(
name|QDialogButtonBox
operator|::
name|Cancel
operator||
name|QDialogButtonBox
operator|::
name|Ok
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|label
operator|->
name|setBuddy
argument_list|(
name|templateNameEdit
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setBuddy
argument_list|(
name|categoryCombo
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_SHORTCUT
name|retranslateUi
argument_list|(
name|SaveFormAsTemplate
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|SaveFormAsTemplate
argument_list|,
name|SLOT
argument_list|(
name|accept
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|,
name|SaveFormAsTemplate
argument_list|,
name|SLOT
argument_list|(
name|reject
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|SaveFormAsTemplate
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|SaveFormAsTemplate
parameter_list|)
block|{
name|SaveFormAsTemplate
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"SaveFormAsTemplate"
argument_list|,
literal|"Save Form As Template"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"SaveFormAsTemplate"
argument_list|,
literal|"&Name:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|templateNameEdit
operator|->
name|setText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"SaveFormAsTemplate"
argument_list|,
literal|"&Category:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// retranslateUi
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|namespace
name|Ui
block|{
name|class
name|SaveFormAsTemplate
range|:
name|public
name|Ui_SaveFormAsTemplate
block|{}
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace Ui
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SAVEFORMASTEMPLATE_H
end_comment
end_unit
