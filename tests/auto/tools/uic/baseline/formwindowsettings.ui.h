begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'formwindowsettings.ui' ** ** Created: Fri Sep 4 10:17:13 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FORMWINDOWSETTINGS_H
end_ifndef
begin_define
DECL|macro|FORMWINDOWSETTINGS_H
define|#
directive|define
name|FORMWINDOWSETTINGS_H
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
file|<QtWidgets/QFrame>
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
file|<QtWidgets/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpinBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTextEdit>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<gridpanel_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_FormWindowSettings
block|{
name|public
label|:
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QDialogButtonBox
modifier|*
name|buttonBox
decl_stmt|;
name|QFrame
modifier|*
name|line
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QGroupBox
modifier|*
name|layoutDefaultGroupBox
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout1
decl_stmt|;
name|QLabel
modifier|*
name|label_2
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QSpinBox
modifier|*
name|defaultSpacingSpinBox
decl_stmt|;
name|QSpinBox
modifier|*
name|defaultMarginSpinBox
decl_stmt|;
name|QGroupBox
modifier|*
name|layoutFunctionGroupBox
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout2
decl_stmt|;
name|QLineEdit
modifier|*
name|spacingFunctionLineEdit
decl_stmt|;
name|QLineEdit
modifier|*
name|marginFunctionLineEdit
decl_stmt|;
name|QLabel
modifier|*
name|label_3
decl_stmt|;
name|QLabel
modifier|*
name|label_3_2
decl_stmt|;
name|QGroupBox
modifier|*
name|pixmapFunctionGroupBox_2
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QLineEdit
modifier|*
name|authorLineEdit
decl_stmt|;
name|QGroupBox
modifier|*
name|includeHintsGroupBox
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout1
decl_stmt|;
name|QTextEdit
modifier|*
name|includeHintsTextEdit
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout1
decl_stmt|;
name|QGroupBox
modifier|*
name|pixmapFunctionGroupBox
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout2
decl_stmt|;
name|QLineEdit
modifier|*
name|pixmapFunctionLineEdit
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|qdesigner_internal
operator|::
name|GridPanel
operator|*
name|gridPanel
expr_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|FormWindowSettings
parameter_list|)
block|{
if|if
condition|(
name|FormWindowSettings
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|FormWindowSettings
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"FormWindowSettings"
argument_list|)
argument_list|)
expr_stmt|;
name|FormWindowSettings
operator|->
name|resize
argument_list|(
literal|433
argument_list|,
literal|465
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|FormWindowSettings
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|FormWindowSettings
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
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|,
literal|6
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|line
operator|=
name|new
name|QFrame
argument_list|(
name|FormWindowSettings
argument_list|)
expr_stmt|;
name|line
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"line"
argument_list|)
argument_list|)
expr_stmt|;
name|line
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|HLine
argument_list|)
expr_stmt|;
name|line
operator|->
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Sunken
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|line
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
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
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
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
name|layoutDefaultGroupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|FormWindowSettings
argument_list|)
expr_stmt|;
name|layoutDefaultGroupBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"layoutDefaultGroupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|layoutDefaultGroupBox
operator|->
name|setCheckable
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|gridLayout1
operator|=
name|new
name|QGridLayout
argument_list|(
name|layoutDefaultGroupBox
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|gridLayout1
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|gridLayout1
operator|->
name|setContentsMargins
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|label_2
operator|=
name|new
name|QLabel
argument_list|(
name|layoutDefaultGroupBox
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"label_2"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|label_2
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
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|layoutDefaultGroupBox
argument_list|)
expr_stmt|;
name|label
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"label"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|label
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
name|defaultSpacingSpinBox
operator|=
name|new
name|QSpinBox
argument_list|(
name|layoutDefaultGroupBox
argument_list|)
expr_stmt|;
name|defaultSpacingSpinBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"defaultSpacingSpinBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|defaultSpacingSpinBox
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
name|defaultMarginSpinBox
operator|=
name|new
name|QSpinBox
argument_list|(
name|layoutDefaultGroupBox
argument_list|)
expr_stmt|;
name|defaultMarginSpinBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"defaultMarginSpinBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|defaultMarginSpinBox
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
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|layoutDefaultGroupBox
argument_list|)
expr_stmt|;
name|layoutFunctionGroupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|FormWindowSettings
argument_list|)
expr_stmt|;
name|layoutFunctionGroupBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"layoutFunctionGroupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|layoutFunctionGroupBox
operator|->
name|setCheckable
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|gridLayout2
operator|=
name|new
name|QGridLayout
argument_list|(
name|layoutFunctionGroupBox
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|gridLayout2
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|gridLayout2
operator|->
name|setContentsMargins
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|gridLayout2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridLayout2"
argument_list|)
argument_list|)
expr_stmt|;
name|spacingFunctionLineEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|layoutFunctionGroupBox
argument_list|)
expr_stmt|;
name|spacingFunctionLineEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"spacingFunctionLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout2
operator|->
name|addWidget
argument_list|(
name|spacingFunctionLineEdit
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
name|marginFunctionLineEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|layoutFunctionGroupBox
argument_list|)
expr_stmt|;
name|marginFunctionLineEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"marginFunctionLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout2
operator|->
name|addWidget
argument_list|(
name|marginFunctionLineEdit
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
name|label_3
operator|=
name|new
name|QLabel
argument_list|(
name|layoutFunctionGroupBox
argument_list|)
expr_stmt|;
name|label_3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"label_3"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout2
operator|->
name|addWidget
argument_list|(
name|label_3
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
name|label_3_2
operator|=
name|new
name|QLabel
argument_list|(
name|layoutFunctionGroupBox
argument_list|)
expr_stmt|;
name|label_3_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"label_3_2"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout2
operator|->
name|addWidget
argument_list|(
name|label_3_2
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
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|layoutFunctionGroupBox
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|pixmapFunctionGroupBox_2
operator|=
name|new
name|QGroupBox
argument_list|(
name|FormWindowSettings
argument_list|)
expr_stmt|;
name|pixmapFunctionGroupBox_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pixmapFunctionGroupBox_2"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|pixmapFunctionGroupBox_2
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
name|vboxLayout
operator|->
name|setContentsMargins
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
expr_stmt|;
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
name|authorLineEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|pixmapFunctionGroupBox_2
argument_list|)
expr_stmt|;
name|authorLineEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"authorLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|authorLineEdit
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|pixmapFunctionGroupBox_2
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
name|includeHintsGroupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|FormWindowSettings
argument_list|)
expr_stmt|;
name|includeHintsGroupBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"includeHintsGroupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|includeHintsGroupBox
argument_list|)
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
name|vboxLayout1
operator|->
name|setContentsMargins
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vboxLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|includeHintsTextEdit
operator|=
name|new
name|QTextEdit
argument_list|(
name|includeHintsGroupBox
argument_list|)
expr_stmt|;
name|includeHintsTextEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"includeHintsTextEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addWidget
argument_list|(
name|includeHintsTextEdit
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|includeHintsGroupBox
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|1
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
name|QStringLiteral
argument_list|(
literal|"hboxLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|pixmapFunctionGroupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|FormWindowSettings
argument_list|)
expr_stmt|;
name|pixmapFunctionGroupBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pixmapFunctionGroupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|pixmapFunctionGroupBox
operator|->
name|setCheckable
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|pixmapFunctionGroupBox
argument_list|)
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
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vboxLayout2"
argument_list|)
argument_list|)
expr_stmt|;
name|pixmapFunctionLineEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|pixmapFunctionGroupBox
argument_list|)
expr_stmt|;
name|pixmapFunctionLineEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pixmapFunctionLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|pixmapFunctionLineEdit
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|pixmapFunctionGroupBox
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout1
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|111
argument_list|,
literal|115
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
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|gridPanel
operator|=
name|new
name|qdesigner_internal
operator|::
name|GridPanel
argument_list|(
name|FormWindowSettings
argument_list|)
expr_stmt|;
name|gridPanel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridPanel"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|gridPanel
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
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|label_2
operator|->
name|setBuddy
argument_list|(
name|defaultSpacingSpinBox
argument_list|)
expr_stmt|;
name|label
operator|->
name|setBuddy
argument_list|(
name|defaultMarginSpinBox
argument_list|)
expr_stmt|;
name|label_3
operator|->
name|setBuddy
argument_list|(
name|marginFunctionLineEdit
argument_list|)
expr_stmt|;
name|label_3_2
operator|->
name|setBuddy
argument_list|(
name|spacingFunctionLineEdit
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_SHORTCUT
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|authorLineEdit
argument_list|,
name|defaultMarginSpinBox
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|defaultMarginSpinBox
argument_list|,
name|defaultSpacingSpinBox
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|defaultSpacingSpinBox
argument_list|,
name|marginFunctionLineEdit
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|marginFunctionLineEdit
argument_list|,
name|spacingFunctionLineEdit
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|spacingFunctionLineEdit
argument_list|,
name|pixmapFunctionLineEdit
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|FormWindowSettings
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
name|FormWindowSettings
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
name|FormWindowSettings
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
name|FormWindowSettings
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|FormWindowSettings
parameter_list|)
block|{
name|FormWindowSettings
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FormWindowSettings"
argument_list|,
literal|"Form Settings"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|layoutDefaultGroupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FormWindowSettings"
argument_list|,
literal|"Layout&Default"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
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
literal|"FormWindowSettings"
argument_list|,
literal|"&Spacing:"
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
literal|"FormWindowSettings"
argument_list|,
literal|"&Margin:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|layoutFunctionGroupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FormWindowSettings"
argument_list|,
literal|"&Layout Function"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|label_3
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FormWindowSettings"
argument_list|,
literal|"Ma&rgin:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|label_3_2
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FormWindowSettings"
argument_list|,
literal|"Spa&cing:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|pixmapFunctionGroupBox_2
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FormWindowSettings"
argument_list|,
literal|"&Author"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|includeHintsGroupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FormWindowSettings"
argument_list|,
literal|"&Include Hints"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|pixmapFunctionGroupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FormWindowSettings"
argument_list|,
literal|"&Pixmap Function"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|gridPanel
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FormWindowSettings"
argument_list|,
literal|"Grid"
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
name|FormWindowSettings
range|:
name|public
name|Ui_FormWindowSettings
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
comment|// FORMWINDOWSETTINGS_H
end_comment
end_unit
