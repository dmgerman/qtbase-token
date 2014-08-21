begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'tabbedbrowser.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TABBEDBROWSER_H
end_ifndef
begin_define
DECL|macro|TABBEDBROWSER_H
define|#
directive|define
name|TABBEDBROWSER_H
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
file|<QtWidgets/QTabWidget>
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
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_TabbedBrowser
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QTabWidget
modifier|*
name|tab
decl_stmt|;
name|QWidget
modifier|*
name|frontpage
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QFrame
modifier|*
name|frameFind
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QToolButton
modifier|*
name|toolClose
decl_stmt|;
name|QLineEdit
modifier|*
name|editFind
decl_stmt|;
name|QToolButton
modifier|*
name|toolPrevious
decl_stmt|;
name|QToolButton
modifier|*
name|toolNext
decl_stmt|;
name|QCheckBox
modifier|*
name|checkCase
decl_stmt|;
name|QCheckBox
modifier|*
name|checkWholeWords
decl_stmt|;
name|QLabel
modifier|*
name|labelWrapped
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|TabbedBrowser
parameter_list|)
block|{
if|if
condition|(
name|TabbedBrowser
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|TabbedBrowser
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"TabbedBrowser"
argument_list|)
argument_list|)
expr_stmt|;
name|TabbedBrowser
operator|->
name|resize
argument_list|(
literal|710
argument_list|,
literal|664
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|TabbedBrowser
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|setSpacing
argument_list|(
literal|0
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
name|tab
operator|=
name|new
name|QTabWidget
argument_list|(
name|TabbedBrowser
argument_list|)
expr_stmt|;
name|tab
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"tab"
argument_list|)
argument_list|)
expr_stmt|;
name|frontpage
operator|=
name|new
name|QWidget
argument_list|()
expr_stmt|;
name|frontpage
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"frontpage"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|frontpage
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
name|gridLayout
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
name|tab
operator|->
name|addTab
argument_list|(
name|frontpage
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|tab
argument_list|)
expr_stmt|;
name|frameFind
operator|=
name|new
name|QFrame
argument_list|(
name|TabbedBrowser
argument_list|)
expr_stmt|;
name|frameFind
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"frameFind"
argument_list|)
argument_list|)
expr_stmt|;
name|frameFind
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|StyledPanel
argument_list|)
expr_stmt|;
name|frameFind
operator|->
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Raised
argument_list|)
expr_stmt|;
name|hboxLayout
operator|=
name|new
name|QHBoxLayout
argument_list|(
name|frameFind
argument_list|)
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
name|toolClose
operator|=
name|new
name|QToolButton
argument_list|(
name|frameFind
argument_list|)
expr_stmt|;
name|toolClose
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"toolClose"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QIcon
name|icon
init|=
name|QIcon
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|":/qt-project.org/assistant/images/close.png"
argument_list|)
argument_list|)
decl_stmt|;
name|toolClose
operator|->
name|setIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
name|toolClose
operator|->
name|setAutoRaise
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|toolClose
argument_list|)
expr_stmt|;
name|editFind
operator|=
name|new
name|QLineEdit
argument_list|(
name|frameFind
argument_list|)
expr_stmt|;
name|editFind
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"editFind"
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
literal|0
operator|)
argument_list|,
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|0
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
name|editFind
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|editFind
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|editFind
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|150
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|editFind
argument_list|)
expr_stmt|;
name|toolPrevious
operator|=
name|new
name|QToolButton
argument_list|(
name|frameFind
argument_list|)
expr_stmt|;
name|toolPrevious
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"toolPrevious"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QIcon
name|icon1
init|=
name|QIcon
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|":/qt-project.org/assistant/images/win/previous.png"
argument_list|)
argument_list|)
decl_stmt|;
name|toolPrevious
operator|->
name|setIcon
argument_list|(
name|icon1
argument_list|)
expr_stmt|;
name|toolPrevious
operator|->
name|setToolButtonStyle
argument_list|(
name|Qt
operator|::
name|ToolButtonTextBesideIcon
argument_list|)
expr_stmt|;
name|toolPrevious
operator|->
name|setAutoRaise
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|toolPrevious
argument_list|)
expr_stmt|;
name|toolNext
operator|=
name|new
name|QToolButton
argument_list|(
name|frameFind
argument_list|)
expr_stmt|;
name|toolNext
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"toolNext"
argument_list|)
argument_list|)
expr_stmt|;
name|toolNext
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QIcon
name|icon2
init|=
name|QIcon
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|":/qt-project.org/assistant/images/win/next.png"
argument_list|)
argument_list|)
decl_stmt|;
name|toolNext
operator|->
name|setIcon
argument_list|(
name|icon2
argument_list|)
expr_stmt|;
name|toolNext
operator|->
name|setToolButtonStyle
argument_list|(
name|Qt
operator|::
name|ToolButtonTextBesideIcon
argument_list|)
expr_stmt|;
name|toolNext
operator|->
name|setAutoRaise
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|toolNext
operator|->
name|setArrowType
argument_list|(
name|Qt
operator|::
name|NoArrow
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|toolNext
argument_list|)
expr_stmt|;
name|checkCase
operator|=
name|new
name|QCheckBox
argument_list|(
name|frameFind
argument_list|)
expr_stmt|;
name|checkCase
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"checkCase"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|checkCase
argument_list|)
expr_stmt|;
name|checkWholeWords
operator|=
name|new
name|QCheckBox
argument_list|(
name|frameFind
argument_list|)
expr_stmt|;
name|checkWholeWords
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"checkWholeWords"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|checkWholeWords
argument_list|)
expr_stmt|;
name|labelWrapped
operator|=
name|new
name|QLabel
argument_list|(
name|frameFind
argument_list|)
expr_stmt|;
name|labelWrapped
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"labelWrapped"
argument_list|)
argument_list|)
expr_stmt|;
name|labelWrapped
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|0
argument_list|,
literal|20
argument_list|)
argument_list|)
expr_stmt|;
name|labelWrapped
operator|->
name|setMaximumSize
argument_list|(
name|QSize
argument_list|(
literal|105
argument_list|,
literal|20
argument_list|)
argument_list|)
expr_stmt|;
name|labelWrapped
operator|->
name|setTextFormat
argument_list|(
name|Qt
operator|::
name|RichText
argument_list|)
expr_stmt|;
name|labelWrapped
operator|->
name|setScaledContents
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|labelWrapped
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeading
operator||
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|AlignVCenter
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|labelWrapped
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|81
argument_list|,
literal|21
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
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|frameFind
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|TabbedBrowser
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|TabbedBrowser
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|TabbedBrowser
parameter_list|)
block|{
name|TabbedBrowser
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TabbedBrowser"
argument_list|,
literal|"TabbedBrowser"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|tab
operator|->
name|setTabText
argument_list|(
name|tab
operator|->
name|indexOf
argument_list|(
name|frontpage
argument_list|)
argument_list|,
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TabbedBrowser"
argument_list|,
literal|"Untitled"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|toolClose
operator|->
name|setText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|toolPrevious
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TabbedBrowser"
argument_list|,
literal|"Previous"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|toolNext
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TabbedBrowser"
argument_list|,
literal|"Next"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|checkCase
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TabbedBrowser"
argument_list|,
literal|"Case Sensitive"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|checkWholeWords
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TabbedBrowser"
argument_list|,
literal|"Whole words"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|labelWrapped
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TabbedBrowser"
argument_list|,
literal|"<img src=\":/qt-project.org/assistant/images/wrap.png\">&nbsp;Search wrapped"
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
name|TabbedBrowser
range|:
name|public
name|Ui_TabbedBrowser
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
comment|// TABBEDBROWSER_H
end_comment
end_unit
