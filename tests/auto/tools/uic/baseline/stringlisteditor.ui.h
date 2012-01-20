begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'stringlisteditor.ui' ** ** Created: Fri Sep 4 10:17:14 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|STRINGLISTEDITOR_H
end_ifndef
begin_define
DECL|macro|STRINGLISTEDITOR_H
define|#
directive|define
name|STRINGLISTEDITOR_H
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
file|<QtWidgets/QDialogButtonBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGroupBox>
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
file|<QtWidgets/QListView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QToolButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|qdesigner_internal
block|{
name|class
name|Ui_Dialog
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QGroupBox
modifier|*
name|groupBox
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout1
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QToolButton
modifier|*
name|newButton
decl_stmt|;
name|QToolButton
modifier|*
name|deleteButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout1
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QLineEdit
modifier|*
name|valueEdit
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout2
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem1
decl_stmt|;
name|QToolButton
modifier|*
name|upButton
decl_stmt|;
name|QToolButton
modifier|*
name|downButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem2
decl_stmt|;
name|QListView
modifier|*
name|listView
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
name|qdesigner_internal__Dialog
parameter_list|)
block|{
if|if
condition|(
name|qdesigner_internal__Dialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|qdesigner_internal__Dialog
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"qdesigner_internal__Dialog"
argument_list|)
argument_list|)
expr_stmt|;
name|qdesigner_internal__Dialog
operator|->
name|resize
argument_list|(
literal|400
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|qdesigner_internal__Dialog
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout
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
endif|#
directive|endif
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
name|groupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|qdesigner_internal__Dialog
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
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|gridLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|gridLayout
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
endif|#
directive|endif
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
name|vboxLayout1
operator|=
name|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout1
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout1
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
endif|#
directive|endif
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
name|hboxLayout
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout
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
endif|#
directive|endif
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
name|newButton
operator|=
name|new
name|QToolButton
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|newButton
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"newButton"
argument_list|)
argument_list|)
expr_stmt|;
name|newButton
operator|->
name|setToolButtonStyle
argument_list|(
name|Qt
operator|::
name|ToolButtonTextBesideIcon
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|newButton
argument_list|)
expr_stmt|;
name|deleteButton
operator|=
name|new
name|QToolButton
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|deleteButton
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"deleteButton"
argument_list|)
argument_list|)
expr_stmt|;
name|deleteButton
operator|->
name|setToolButtonStyle
argument_list|(
name|Qt
operator|::
name|ToolButtonTextBesideIcon
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|deleteButton
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|40
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
name|hboxLayout
operator|->
name|addItem
argument_list|(
name|spacerItem
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addLayout
argument_list|(
name|hboxLayout
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout1
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|hboxLayout1
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
name|hboxLayout1
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"hboxLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|groupBox
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
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|valueEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|valueEdit
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"valueEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|valueEdit
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addLayout
argument_list|(
name|hboxLayout1
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addLayout
argument_list|(
name|vboxLayout1
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
name|vboxLayout2
operator|=
name|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout2
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
name|spacerItem1
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
name|vboxLayout2
operator|->
name|addItem
argument_list|(
name|spacerItem1
argument_list|)
expr_stmt|;
name|upButton
operator|=
name|new
name|QToolButton
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|upButton
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"upButton"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|upButton
argument_list|)
expr_stmt|;
name|downButton
operator|=
name|new
name|QToolButton
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|downButton
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"downButton"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|downButton
argument_list|)
expr_stmt|;
name|spacerItem2
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
name|vboxLayout2
operator|->
name|addItem
argument_list|(
name|spacerItem2
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addLayout
argument_list|(
name|vboxLayout2
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
name|listView
operator|=
name|new
name|QListView
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|listView
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"listView"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|listView
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
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|qdesigner_internal__Dialog
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
name|NoButton
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
name|valueEdit
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_SHORTCUT
name|retranslateUi
argument_list|(
name|qdesigner_internal__Dialog
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
name|qdesigner_internal__Dialog
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
name|qdesigner_internal__Dialog
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
name|qdesigner_internal__Dialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|qdesigner_internal__Dialog
parameter_list|)
block|{
name|qdesigner_internal__Dialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::Dialog"
argument_list|,
literal|"Dialog"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::Dialog"
argument_list|,
literal|"StringList"
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
name|QT_NO_TOOLTIP
name|newButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::Dialog"
argument_list|,
literal|"New String"
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
comment|// QT_NO_TOOLTIP
name|newButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::Dialog"
argument_list|,
literal|"&New"
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
name|QT_NO_TOOLTIP
name|deleteButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::Dialog"
argument_list|,
literal|"Delete String"
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
comment|// QT_NO_TOOLTIP
name|deleteButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::Dialog"
argument_list|,
literal|"&Delete"
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
literal|"qdesigner_internal::Dialog"
argument_list|,
literal|"&Value:"
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
name|QT_NO_TOOLTIP
name|upButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::Dialog"
argument_list|,
literal|"Move String Up"
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
comment|// QT_NO_TOOLTIP
name|upButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::Dialog"
argument_list|,
literal|"Up"
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
name|QT_NO_TOOLTIP
name|downButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::Dialog"
argument_list|,
literal|"Move String Down"
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
comment|// QT_NO_TOOLTIP
name|downButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::Dialog"
argument_list|,
literal|"Down"
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
empty_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace qdesigner_internal
end_comment
begin_decl_stmt
name|namespace
name|qdesigner_internal
block|{
name|namespace
name|Ui
block|{
name|class
name|Dialog
range|:
name|public
name|Ui_Dialog
block|{}
decl_stmt|;
block|}
comment|// namespace Ui
block|}
end_decl_stmt
begin_comment
comment|// namespace qdesigner_internal
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// STRINGLISTEDITOR_H
end_comment
end_unit
