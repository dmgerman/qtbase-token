begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'newform.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|NEWFORM_H
end_ifndef
begin_define
DECL|macro|NEWFORM_H
define|#
directive|define
name|NEWFORM_H
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
file|<QtWidgets/QCheckBox>
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
file|<QtWidgets/QFrame>
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
file|<QtWidgets/QTreeWidget>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_NewForm
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QTreeWidget
modifier|*
name|treeWidget
decl_stmt|;
name|QLabel
modifier|*
name|lblPreview
decl_stmt|;
name|QFrame
modifier|*
name|horizontalLine
decl_stmt|;
name|QCheckBox
modifier|*
name|chkShowOnStartup
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
name|NewForm
parameter_list|)
block|{
if|if
condition|(
name|NewForm
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|NewForm
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"NewForm"
argument_list|)
argument_list|)
expr_stmt|;
name|NewForm
operator|->
name|resize
argument_list|(
literal|495
argument_list|,
literal|319
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|NewForm
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
name|QStringLiteral
argument_list|(
literal|"vboxLayout"
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
name|hboxLayout
operator|->
name|setContentsMargins
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"hboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|treeWidget
operator|=
name|new
name|QTreeWidget
argument_list|(
name|NewForm
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"treeWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setIconSize
argument_list|(
name|QSize
argument_list|(
literal|128
argument_list|,
literal|128
argument_list|)
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setRootIsDecorated
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setColumnCount
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|treeWidget
argument_list|)
expr_stmt|;
name|lblPreview
operator|=
name|new
name|QLabel
argument_list|(
name|NewForm
argument_list|)
expr_stmt|;
name|lblPreview
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"lblPreview"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy
argument_list|(
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|7
operator|)
argument_list|,
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|5
operator|)
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
name|lblPreview
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|lblPreview
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|lblPreview
operator|->
name|setLineWidth
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|lblPreview
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
name|lblPreview
operator|->
name|setMargin
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|lblPreview
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout
argument_list|)
expr_stmt|;
name|horizontalLine
operator|=
name|new
name|QFrame
argument_list|(
name|NewForm
argument_list|)
expr_stmt|;
name|horizontalLine
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
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
name|chkShowOnStartup
operator|=
name|new
name|QCheckBox
argument_list|(
name|NewForm
argument_list|)
expr_stmt|;
name|chkShowOnStartup
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"chkShowOnStartup"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|chkShowOnStartup
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|NewForm
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"buttonBox"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|NewForm
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|NewForm
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|NewForm
parameter_list|)
block|{
name|NewForm
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"NewForm"
argument_list|,
literal|"New Form"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|___qtreewidgetitem
init|=
name|treeWidget
operator|->
name|headerItem
argument_list|()
decl_stmt|;
name|___qtreewidgetitem
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|QApplication
operator|::
name|translate
argument_list|(
literal|"NewForm"
argument_list|,
literal|"0"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|lblPreview
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"NewForm"
argument_list|,
literal|"Choose a template for a preview"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|chkShowOnStartup
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"NewForm"
argument_list|,
literal|"Show this Dialog on Startup"
argument_list|,
literal|0
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
name|NewForm
range|:
name|public
name|Ui_NewForm
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
comment|// NEWFORM_H
end_comment
end_unit
