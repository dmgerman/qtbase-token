begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'phrasebookbox.ui' ** ** Created: Fri Sep 4 10:17:14 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PHRASEBOOKBOX_H
end_ifndef
begin_define
DECL|macro|PHRASEBOOKBOX_H
define|#
directive|define
name|PHRASEBOOKBOX_H
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
file|<QtWidgets/QDialog>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QHBoxLayout>
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
file|<QtWidgets/QPushButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTreeView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_PhraseBookBox
block|{
name|public
label|:
name|QHBoxLayout
modifier|*
name|unnamed
decl_stmt|;
name|QVBoxLayout
modifier|*
name|inputsLayout
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QLabel
modifier|*
name|target
decl_stmt|;
name|QLineEdit
modifier|*
name|targetLed
decl_stmt|;
name|QLabel
modifier|*
name|source
decl_stmt|;
name|QLineEdit
modifier|*
name|definitionLed
decl_stmt|;
name|QLineEdit
modifier|*
name|sourceLed
decl_stmt|;
name|QLabel
modifier|*
name|definition
decl_stmt|;
name|QTreeView
modifier|*
name|phraseList
decl_stmt|;
name|QVBoxLayout
modifier|*
name|buttonLayout
decl_stmt|;
name|QPushButton
modifier|*
name|newBut
decl_stmt|;
name|QPushButton
modifier|*
name|removeBut
decl_stmt|;
name|QPushButton
modifier|*
name|saveBut
decl_stmt|;
name|QPushButton
modifier|*
name|closeBut
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacer1
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|PhraseBookBox
parameter_list|)
block|{
if|if
condition|(
name|PhraseBookBox
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|PhraseBookBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"PhraseBookBox"
argument_list|)
argument_list|)
expr_stmt|;
name|PhraseBookBox
operator|->
name|resize
argument_list|(
literal|596
argument_list|,
literal|454
argument_list|)
expr_stmt|;
name|unnamed
operator|=
name|new
name|QHBoxLayout
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
name|unnamed
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|unnamed
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
name|unnamed
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"unnamed"
argument_list|)
argument_list|)
expr_stmt|;
name|inputsLayout
operator|=
name|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
name|inputsLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|inputsLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"inputsLayout"
argument_list|)
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
name|target
operator|=
name|new
name|QLabel
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
name|target
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"target"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|target
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
name|targetLed
operator|=
name|new
name|QLineEdit
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
name|targetLed
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"targetLed"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|targetLed
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
name|source
operator|=
name|new
name|QLabel
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
name|source
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"source"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|source
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
name|definitionLed
operator|=
name|new
name|QLineEdit
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
name|definitionLed
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"definitionLed"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|definitionLed
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
name|sourceLed
operator|=
name|new
name|QLineEdit
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
name|sourceLed
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"sourceLed"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|sourceLed
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
name|definition
operator|=
name|new
name|QLabel
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
name|definition
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"definition"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|definition
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
name|inputsLayout
operator|->
name|addLayout
argument_list|(
name|gridLayout
argument_list|)
expr_stmt|;
name|phraseList
operator|=
name|new
name|QTreeView
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
name|phraseList
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"phraseList"
argument_list|)
argument_list|)
expr_stmt|;
name|phraseList
operator|->
name|setRootIsDecorated
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|phraseList
operator|->
name|setUniformRowHeights
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|phraseList
operator|->
name|setItemsExpandable
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|phraseList
operator|->
name|setSortingEnabled
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|phraseList
operator|->
name|setExpandsOnDoubleClick
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|inputsLayout
operator|->
name|addWidget
argument_list|(
name|phraseList
argument_list|)
expr_stmt|;
name|unnamed
operator|->
name|addLayout
argument_list|(
name|inputsLayout
argument_list|)
expr_stmt|;
name|buttonLayout
operator|=
name|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
name|buttonLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"buttonLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|newBut
operator|=
name|new
name|QPushButton
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
name|newBut
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"newBut"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addWidget
argument_list|(
name|newBut
argument_list|)
expr_stmt|;
name|removeBut
operator|=
name|new
name|QPushButton
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
name|removeBut
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"removeBut"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addWidget
argument_list|(
name|removeBut
argument_list|)
expr_stmt|;
name|saveBut
operator|=
name|new
name|QPushButton
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
name|saveBut
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"saveBut"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addWidget
argument_list|(
name|saveBut
argument_list|)
expr_stmt|;
name|closeBut
operator|=
name|new
name|QPushButton
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
name|closeBut
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"closeBut"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addWidget
argument_list|(
name|closeBut
argument_list|)
expr_stmt|;
name|spacer1
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
name|buttonLayout
operator|->
name|addItem
argument_list|(
name|spacer1
argument_list|)
expr_stmt|;
name|unnamed
operator|->
name|addLayout
argument_list|(
name|buttonLayout
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|target
operator|->
name|setBuddy
argument_list|(
name|targetLed
argument_list|)
expr_stmt|;
name|source
operator|->
name|setBuddy
argument_list|(
name|sourceLed
argument_list|)
expr_stmt|;
name|definition
operator|->
name|setBuddy
argument_list|(
name|definitionLed
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_SHORTCUT
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|sourceLed
argument_list|,
name|targetLed
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|targetLed
argument_list|,
name|definitionLed
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|definitionLed
argument_list|,
name|newBut
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|newBut
argument_list|,
name|removeBut
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|removeBut
argument_list|,
name|saveBut
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|saveBut
argument_list|,
name|closeBut
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|PhraseBookBox
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|PhraseBookBox
parameter_list|)
block|{
name|PhraseBookBox
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"Edit Phrase Book"
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
name|PhraseBookBox
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"This window allows you to add, modify, or delete phrases in a phrase book."
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
name|target
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"&Translation:"
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
name|targetLed
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"This is the phrase in the target language corresponding to the source phrase."
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
name|source
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"S&ource phrase:"
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
name|definitionLed
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"This is a definition for the source phrase."
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
name|sourceLed
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"This is the phrase in the source language."
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
name|definition
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"&Definition:"
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
name|newBut
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"Click here to add the phrase to the phrase book."
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
name|newBut
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"&New Phrase"
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
name|removeBut
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"Click here to remove the phrase from the phrase book."
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
name|removeBut
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"&Remove Phrase"
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
name|saveBut
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"Click here to save the changes made."
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
name|saveBut
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"&Save"
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
name|closeBut
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
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
name|closeBut
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PhraseBookBox"
argument_list|,
literal|"Close"
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
name|PhraseBookBox
range|:
name|public
name|Ui_PhraseBookBox
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
comment|// PHRASEBOOKBOX_H
end_comment
end_unit
