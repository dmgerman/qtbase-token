begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'translatedialog.ui' ** ** Created: Fri Sep 4 10:17:15 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TRANSLATEDIALOG_H
end_ifndef
begin_define
DECL|macro|TRANSLATEDIALOG_H
define|#
directive|define
name|TRANSLATEDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtGui/QAction>
end_include
begin_include
include|#
directive|include
file|<QtGui/QApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QButtonGroup>
end_include
begin_include
include|#
directive|include
file|<QtGui/QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QtGui/QDialog>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QtGui/QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QtGui/QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QtGui/QLabel>
end_include
begin_include
include|#
directive|include
file|<QtGui/QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPushButton>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtGui/QVBoxLayout>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_TranslateDialog
block|{
name|public
label|:
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QLineEdit
modifier|*
name|ledTranslateTo
decl_stmt|;
name|QLabel
modifier|*
name|findWhat
decl_stmt|;
name|QLabel
modifier|*
name|translateTo
decl_stmt|;
name|QLineEdit
modifier|*
name|ledFindWhat
decl_stmt|;
name|QGroupBox
modifier|*
name|groupBox
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout1
decl_stmt|;
name|QCheckBox
modifier|*
name|ckMatchCase
decl_stmt|;
name|QCheckBox
modifier|*
name|ckMarkFinished
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout2
decl_stmt|;
name|QPushButton
modifier|*
name|findNxt
decl_stmt|;
name|QPushButton
modifier|*
name|translate
decl_stmt|;
name|QPushButton
modifier|*
name|translateAll
decl_stmt|;
name|QPushButton
modifier|*
name|cancel
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem1
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|TranslateDialog
parameter_list|)
block|{
if|if
condition|(
name|TranslateDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|TranslateDialog
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"TranslateDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|TranslateDialog
operator|->
name|resize
argument_list|(
literal|407
argument_list|,
literal|145
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|Maximum
argument_list|)
decl_stmt|;
name|sizePolicy
operator|.
name|setHorizontalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setHeightForWidth
argument_list|(
name|TranslateDialog
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|TranslateDialog
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|hboxLayout
operator|=
name|new
name|QHBoxLayout
argument_list|(
name|TranslateDialog
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|setContentsMargins
argument_list|(
literal|11
argument_list|,
literal|11
argument_list|,
literal|11
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"hboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|setContentsMargins
argument_list|(
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
name|vboxLayout
operator|->
name|setSpacing
argument_list|(
literal|6
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
name|vboxLayout
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|()
expr_stmt|;
name|gridLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"gridLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|setHorizontalSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|setVerticalSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ledTranslateTo
operator|=
name|new
name|QLineEdit
argument_list|(
name|TranslateDialog
argument_list|)
expr_stmt|;
name|ledTranslateTo
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"ledTranslateTo"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|ledTranslateTo
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|findWhat
operator|=
name|new
name|QLabel
argument_list|(
name|TranslateDialog
argument_list|)
expr_stmt|;
name|findWhat
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"findWhat"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|findWhat
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|translateTo
operator|=
name|new
name|QLabel
argument_list|(
name|TranslateDialog
argument_list|)
expr_stmt|;
name|translateTo
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"translateTo"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|translateTo
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|ledFindWhat
operator|=
name|new
name|QLineEdit
argument_list|(
name|TranslateDialog
argument_list|)
expr_stmt|;
name|ledFindWhat
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"ledFindWhat"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|ledFindWhat
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|gridLayout
argument_list|)
expr_stmt|;
name|groupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|TranslateDialog
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"groupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|setContentsMargins
argument_list|(
literal|11
argument_list|,
literal|11
argument_list|,
literal|11
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"vboxLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|ckMatchCase
operator|=
name|new
name|QCheckBox
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|ckMatchCase
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"ckMatchCase"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addWidget
argument_list|(
name|ckMatchCase
argument_list|)
expr_stmt|;
name|ckMarkFinished
operator|=
name|new
name|QCheckBox
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|ckMarkFinished
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"ckMarkFinished"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addWidget
argument_list|(
name|ckMarkFinished
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|40
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addItem
argument_list|(
name|spacerItem
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addLayout
argument_list|(
name|vboxLayout
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|=
name|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
name|vboxLayout2
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"vboxLayout2"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|findNxt
operator|=
name|new
name|QPushButton
argument_list|(
name|TranslateDialog
argument_list|)
expr_stmt|;
name|findNxt
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"findNxt"
argument_list|)
argument_list|)
expr_stmt|;
name|findNxt
operator|->
name|setDefault
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|findNxt
operator|->
name|setFlat
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|findNxt
argument_list|)
expr_stmt|;
name|translate
operator|=
name|new
name|QPushButton
argument_list|(
name|TranslateDialog
argument_list|)
expr_stmt|;
name|translate
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"translate"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|translate
argument_list|)
expr_stmt|;
name|translateAll
operator|=
name|new
name|QPushButton
argument_list|(
name|TranslateDialog
argument_list|)
expr_stmt|;
name|translateAll
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"translateAll"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|translateAll
argument_list|)
expr_stmt|;
name|cancel
operator|=
name|new
name|QPushButton
argument_list|(
name|TranslateDialog
argument_list|)
expr_stmt|;
name|cancel
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"cancel"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|cancel
argument_list|)
expr_stmt|;
name|spacerItem1
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|51
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addItem
argument_list|(
name|spacerItem1
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addLayout
argument_list|(
name|vboxLayout2
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|findWhat
operator|->
name|setBuddy
argument_list|(
name|ledFindWhat
argument_list|)
expr_stmt|;
name|translateTo
operator|->
name|setBuddy
argument_list|(
name|ledTranslateTo
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_SHORTCUT
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|ledFindWhat
argument_list|,
name|ledTranslateTo
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|ledTranslateTo
argument_list|,
name|findNxt
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|findNxt
argument_list|,
name|translate
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|translate
argument_list|,
name|translateAll
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|translateAll
argument_list|,
name|cancel
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|cancel
argument_list|,
name|ckMatchCase
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|ckMatchCase
argument_list|,
name|ckMarkFinished
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|TranslateDialog
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|cancel
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|TranslateDialog
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
name|TranslateDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|TranslateDialog
parameter_list|)
block|{
name|TranslateDialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Qt Linguist"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|TranslateDialog
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"This window allows you to search for some text in the translation source file."
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|ledTranslateTo
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Type in the text to search for."
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|findWhat
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Find&source text:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|translateTo
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"&Translate to:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|ledFindWhat
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Type in the text to search for."
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|groupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Search options"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|ckMatchCase
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Texts such as 'TeX' and 'tex' are considered as different when checked."
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|ckMatchCase
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Match&case"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|ckMarkFinished
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Mark new translation as&finished"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|findNxt
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Click here to find the next occurrence of the text you typed in."
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|findNxt
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Find Next"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|translate
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Translate"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|translateAll
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Translate All"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|cancel
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Click here to close this window."
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|cancel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TranslateDialog"
argument_list|,
literal|"Cancel"
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
name|TranslateDialog
range|:
name|public
name|Ui_TranslateDialog
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
comment|// TRANSLATEDIALOG_H
end_comment
end_unit
