begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'previewdialogbase.ui' ** ** Created: Fri Sep 4 10:17:14 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PREVIEWDIALOGBASE_H
end_ifndef
begin_define
DECL|macro|PREVIEWDIALOGBASE_H
define|#
directive|define
name|PREVIEWDIALOGBASE_H
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
file|<QtWidgets/QProgressBar>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QScrollArea>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpacerItem>
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
name|Ui_PreviewDialogBase
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
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QComboBox
modifier|*
name|paperSizeCombo
decl_stmt|;
name|QLabel
modifier|*
name|label_2
decl_stmt|;
name|QComboBox
modifier|*
name|paperOrientationCombo
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout1
decl_stmt|;
name|QTreeWidget
modifier|*
name|pageList
decl_stmt|;
name|QScrollArea
modifier|*
name|previewArea
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout2
decl_stmt|;
name|QProgressBar
modifier|*
name|progressBar
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
name|PreviewDialogBase
parameter_list|)
block|{
if|if
condition|(
name|PreviewDialogBase
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|PreviewDialogBase
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"PreviewDialogBase"
argument_list|)
argument_list|)
expr_stmt|;
name|PreviewDialogBase
operator|->
name|resize
argument_list|(
literal|733
argument_list|,
literal|479
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|PreviewDialogBase
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
name|QStringLiteral
argument_list|(
literal|"hboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|PreviewDialogBase
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
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|paperSizeCombo
operator|=
name|new
name|QComboBox
argument_list|(
name|PreviewDialogBase
argument_list|)
expr_stmt|;
name|paperSizeCombo
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"paperSizeCombo"
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
literal|1
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
name|paperSizeCombo
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|paperSizeCombo
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|paperSizeCombo
argument_list|)
expr_stmt|;
name|label_2
operator|=
name|new
name|QLabel
argument_list|(
name|PreviewDialogBase
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
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|label_2
argument_list|)
expr_stmt|;
name|paperOrientationCombo
operator|=
name|new
name|QComboBox
argument_list|(
name|PreviewDialogBase
argument_list|)
expr_stmt|;
name|paperOrientationCombo
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"paperOrientationCombo"
argument_list|)
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setHeightForWidth
argument_list|(
name|paperOrientationCombo
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|paperOrientationCombo
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|paperOrientationCombo
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
name|vboxLayout
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
name|QStringLiteral
argument_list|(
literal|"hboxLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|pageList
operator|=
name|new
name|QTreeWidget
argument_list|(
name|PreviewDialogBase
argument_list|)
expr_stmt|;
name|pageList
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pageList"
argument_list|)
argument_list|)
expr_stmt|;
name|pageList
operator|->
name|setIndentation
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|pageList
operator|->
name|setRootIsDecorated
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|pageList
operator|->
name|setUniformRowHeights
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|pageList
operator|->
name|setItemsExpandable
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|pageList
operator|->
name|setColumnCount
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|pageList
argument_list|)
expr_stmt|;
name|previewArea
operator|=
name|new
name|QScrollArea
argument_list|(
name|PreviewDialogBase
argument_list|)
expr_stmt|;
name|previewArea
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"previewArea"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy1
argument_list|(
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|5
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
name|sizePolicy1
operator|.
name|setHorizontalStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|sizePolicy1
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy1
operator|.
name|setHeightForWidth
argument_list|(
name|previewArea
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|previewArea
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy1
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|previewArea
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout1
argument_list|)
expr_stmt|;
name|hboxLayout2
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout2
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|hboxLayout2
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
name|hboxLayout2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"hboxLayout2"
argument_list|)
argument_list|)
expr_stmt|;
name|progressBar
operator|=
name|new
name|QProgressBar
argument_list|(
name|PreviewDialogBase
argument_list|)
expr_stmt|;
name|progressBar
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"progressBar"
argument_list|)
argument_list|)
expr_stmt|;
name|progressBar
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy2
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
literal|0
operator|)
argument_list|)
decl_stmt|;
name|sizePolicy2
operator|.
name|setHorizontalStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|sizePolicy2
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy2
operator|.
name|setHeightForWidth
argument_list|(
name|progressBar
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|progressBar
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy2
argument_list|)
expr_stmt|;
name|progressBar
operator|->
name|setValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|progressBar
operator|->
name|setTextVisible
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|progressBar
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|hboxLayout2
operator|->
name|addWidget
argument_list|(
name|progressBar
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|PreviewDialogBase
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
name|hboxLayout2
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout2
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|label
operator|->
name|setBuddy
argument_list|(
name|paperSizeCombo
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setBuddy
argument_list|(
name|paperOrientationCombo
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_SHORTCUT
name|retranslateUi
argument_list|(
name|PreviewDialogBase
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
name|PreviewDialogBase
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
name|PreviewDialogBase
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
name|PreviewDialogBase
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|PreviewDialogBase
parameter_list|)
block|{
name|PreviewDialogBase
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"PreviewDialogBase"
argument_list|,
literal|"Print Preview"
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
literal|"PreviewDialogBase"
argument_list|,
literal|"&Paper Size:"
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
literal|"PreviewDialogBase"
argument_list|,
literal|"&Orientation:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|___qtreewidgetitem
init|=
name|pageList
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
literal|"PreviewDialogBase"
argument_list|,
literal|"1"
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
name|PreviewDialogBase
range|:
name|public
name|Ui_PreviewDialogBase
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
comment|// PREVIEWDIALOGBASE_H
end_comment
end_unit
