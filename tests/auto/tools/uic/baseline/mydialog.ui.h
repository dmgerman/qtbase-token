begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'mydialog.ui' ** ** Created: Fri Sep 4 10:17:14 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MYDIALOG_H
end_ifndef
begin_define
DECL|macro|MYDIALOG_H
define|#
directive|define
name|MYDIALOG_H
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
file|<QtWidgets/QPushButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_MyDialog
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QLabel
modifier|*
name|aLabel
decl_stmt|;
name|QPushButton
modifier|*
name|aButton
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|MyDialog
parameter_list|)
block|{
if|if
condition|(
name|MyDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|MyDialog
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"MyDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|MyDialog
operator|->
name|resize
argument_list|(
literal|401
argument_list|,
literal|70
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|MyDialog
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
name|aLabel
operator|=
name|new
name|QLabel
argument_list|(
name|MyDialog
argument_list|)
expr_stmt|;
name|aLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"aLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|aLabel
argument_list|)
expr_stmt|;
name|aButton
operator|=
name|new
name|QPushButton
argument_list|(
name|MyDialog
argument_list|)
expr_stmt|;
name|aButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"aButton"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|aButton
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|MyDialog
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|MyDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|MyDialog
parameter_list|)
block|{
name|MyDialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"MyDialog"
argument_list|,
literal|"Mach 2!"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|aLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"MyDialog"
argument_list|,
literal|"Join the life in the fastlane; - PCH enable your project today! -"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|aButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"MyDialog"
argument_list|,
literal|"&Quit"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|aButton
operator|->
name|setShortcut
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"MyDialog"
argument_list|,
literal|"Alt+Q"
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
name|MyDialog
range|:
name|public
name|Ui_MyDialog
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
comment|// MYDIALOG_H
end_comment
end_unit
