begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'qtgradientview.ui' ** ** Created: Fri Sep 4 10:17:14 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTGRADIENTVIEW_H
end_ifndef
begin_define
DECL|macro|QTGRADIENTVIEW_H
define|#
directive|define
name|QTGRADIENTVIEW_H
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
file|<QtWidgets/QListWidget>
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
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_QtGradientView
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
name|QToolButton
modifier|*
name|newButton
decl_stmt|;
name|QToolButton
modifier|*
name|editButton
decl_stmt|;
name|QToolButton
modifier|*
name|renameButton
decl_stmt|;
name|QToolButton
modifier|*
name|removeButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QListWidget
modifier|*
name|listWidget
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|QtGradientView
parameter_list|)
block|{
if|if
condition|(
name|QtGradientView
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|QtGradientView
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"QtGradientView"
argument_list|)
argument_list|)
expr_stmt|;
name|QtGradientView
operator|->
name|resize
argument_list|(
literal|484
argument_list|,
literal|228
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|QtGradientView
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
name|hboxLayout
operator|=
name|new
name|QHBoxLayout
argument_list|()
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
name|newButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QtGradientView
argument_list|)
expr_stmt|;
name|newButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"newButton"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
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
name|newButton
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|newButton
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
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
name|newButton
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
name|newButton
argument_list|)
expr_stmt|;
name|editButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QtGradientView
argument_list|)
expr_stmt|;
name|editButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"editButton"
argument_list|)
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setHeightForWidth
argument_list|(
name|editButton
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|editButton
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|editButton
operator|->
name|setToolButtonStyle
argument_list|(
name|Qt
operator|::
name|ToolButtonTextBesideIcon
argument_list|)
expr_stmt|;
name|editButton
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
name|editButton
argument_list|)
expr_stmt|;
name|renameButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QtGradientView
argument_list|)
expr_stmt|;
name|renameButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"renameButton"
argument_list|)
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setHeightForWidth
argument_list|(
name|renameButton
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|renameButton
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|renameButton
operator|->
name|setToolButtonStyle
argument_list|(
name|Qt
operator|::
name|ToolButtonTextBesideIcon
argument_list|)
expr_stmt|;
name|renameButton
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
name|renameButton
argument_list|)
expr_stmt|;
name|removeButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QtGradientView
argument_list|)
expr_stmt|;
name|removeButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"removeButton"
argument_list|)
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setHeightForWidth
argument_list|(
name|removeButton
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|removeButton
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|removeButton
operator|->
name|setToolButtonStyle
argument_list|(
name|Qt
operator|::
name|ToolButtonTextBesideIcon
argument_list|)
expr_stmt|;
name|removeButton
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
name|removeButton
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|71
argument_list|,
literal|26
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
name|addLayout
argument_list|(
name|hboxLayout
argument_list|)
expr_stmt|;
name|listWidget
operator|=
name|new
name|QListWidget
argument_list|(
name|QtGradientView
argument_list|)
expr_stmt|;
name|listWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"listWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|listWidget
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|listWidget
argument_list|,
name|newButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|newButton
argument_list|,
name|editButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|editButton
argument_list|,
name|renameButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|renameButton
argument_list|,
name|removeButton
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|QtGradientView
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|QtGradientView
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|QtGradientView
parameter_list|)
block|{
name|QtGradientView
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtGradientView"
argument_list|,
literal|"Gradient View"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|newButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtGradientView"
argument_list|,
literal|"New..."
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|editButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtGradientView"
argument_list|,
literal|"Edit..."
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|renameButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtGradientView"
argument_list|,
literal|"Rename"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|removeButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtGradientView"
argument_list|,
literal|"Remove"
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
name|QtGradientView
range|:
name|public
name|Ui_QtGradientView
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
comment|// QTGRADIENTVIEW_H
end_comment
end_unit
