begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QRadioButton>
end_include
begin_include
include|#
directive|include
file|<QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|"controllerwindow.h"
end_include
begin_include
include|#
directive|include
file|"controls.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|ControllerWindow
name|ControllerWindow
operator|::
name|ControllerWindow
parameter_list|()
member_init_list|:
name|previewWidget
argument_list|(
literal|0
argument_list|)
block|{
name|parentWindow
operator|=
operator|new
name|QMainWindow
expr_stmt|;
name|parentWindow
operator|->
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Preview parent window"
argument_list|)
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Parent window"
argument_list|)
argument_list|)
decl_stmt|;
name|parentWindow
operator|->
name|setCentralWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|previewWindow
operator|=
operator|new
name|PreviewWindow
expr_stmt|;
name|previewWindow
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|previewDialog
operator|=
operator|new
name|PreviewDialog
expr_stmt|;
name|previewDialog
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|createTypeGroupBox
argument_list|()
expr_stmt|;
name|quitButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Quit"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|bottomLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|bottomLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|QPushButton
modifier|*
name|updateControlsButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Update"
argument_list|)
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|updateControlsButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateStateControl
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|bottomLayout
operator|->
name|addWidget
argument_list|(
name|updateControlsButton
argument_list|)
expr_stmt|;
name|bottomLayout
operator|->
name|addWidget
argument_list|(
name|quitButton
argument_list|)
expr_stmt|;
name|hintsControl
operator|=
operator|new
name|HintControl
expr_stmt|;
name|hintsControl
operator|->
name|setHints
argument_list|(
name|previewWindow
operator|->
name|windowFlags
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|hintsControl
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|(
name|Qt
operator|::
name|WindowFlags
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updatePreview
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|statesControl
operator|=
operator|new
name|WindowStatesControl
argument_list|(
name|WindowStatesControl
operator|::
name|WantVisibleCheckBox
operator||
name|WindowStatesControl
operator|::
name|WantActiveCheckBox
argument_list|)
expr_stmt|;
name|statesControl
operator|->
name|setStates
argument_list|(
name|previewWindow
operator|->
name|windowState
argument_list|()
argument_list|)
expr_stmt|;
name|statesControl
operator|->
name|setVisibleValue
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|statesControl
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updatePreview
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|typeControl
operator|=
operator|new
name|TypeControl
expr_stmt|;
name|typeControl
operator|->
name|setType
argument_list|(
name|previewWindow
operator|->
name|windowFlags
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|typeControl
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|(
name|Qt
operator|::
name|WindowFlags
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updatePreview
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|widgetTypeGroupBox
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|additionalOptionsGroupBox
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|typeControl
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|hintsControl
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|statesControl
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|bottomLayout
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Window Flags (Qt version %1, %2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|qVersion
argument_list|()
argument_list|)
argument_list|,
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
name|qApp
operator|->
name|platformName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|QLatin1String
argument_list|(
literal|"<unknown>"
argument_list|)
block|)
end_constructor
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|updatePreview
argument_list|()
expr_stmt|;
end_expr_stmt
begin_macro
unit|}  bool
DECL|function|eventFilter
name|ControllerWindow
end_macro
begin_expr_stmt
DECL|function|eventFilter
operator|::
name|eventFilter
operator|(
name|QObject
operator|*
name|o
operator|,
name|QEvent
operator|*
name|e
operator|)
block|{
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|WindowStateChange
condition|)
name|updateStateControl
argument_list|()
expr_stmt|;
end_expr_stmt
begin_return
return|return
literal|false
return|;
end_return
begin_macro
unit|}  void
DECL|function|updateStateControl
name|ControllerWindow
end_macro
begin_expr_stmt
DECL|function|updateStateControl
operator|::
name|updateStateControl
operator|(
operator|)
block|{
if|if
condition|(
name|previewWidget
condition|)
name|statesControl
operator|->
name|setStates
argument_list|(
name|previewWidget
operator|->
name|windowState
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_function
DECL|function|updatePreview
name|void
name|ControllerWindow
operator|::
name|updatePreview
parameter_list|()
block|{
specifier|const
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
name|typeControl
operator|->
name|type
argument_list|()
operator||
name|hintsControl
operator|->
name|hints
argument_list|()
decl_stmt|;
name|previewWindow
operator|->
name|hide
argument_list|()
expr_stmt|;
name|previewDialog
operator|->
name|hide
argument_list|()
expr_stmt|;
if|if
condition|(
name|previewWidgetButton
operator|->
name|isChecked
argument_list|()
condition|)
name|previewWidget
operator|=
name|previewWindow
expr_stmt|;
else|else
name|previewWidget
operator|=
name|previewDialog
expr_stmt|;
if|if
condition|(
name|modalWindowCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|parentWindow
operator|->
name|show
argument_list|()
expr_stmt|;
name|previewWidget
operator|->
name|setWindowModality
argument_list|(
name|Qt
operator|::
name|WindowModal
argument_list|)
expr_stmt|;
name|previewWidget
operator|->
name|setParent
argument_list|(
name|parentWindow
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|previewWidget
operator|->
name|setWindowModality
argument_list|(
name|Qt
operator|::
name|NonModal
argument_list|)
expr_stmt|;
name|previewWidget
operator|->
name|setParent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|parentWindow
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
name|previewWidget
operator|->
name|setWindowFlags
argument_list|(
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
name|fixedSizeWindowCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|previewWidget
operator|->
name|setFixedSize
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|previewWidget
operator|->
name|setFixedSize
argument_list|(
name|QWIDGETSIZE_MAX
argument_list|,
name|QWIDGETSIZE_MAX
argument_list|)
expr_stmt|;
block|}
name|QPoint
name|pos
init|=
name|previewWidget
operator|->
name|pos
argument_list|()
decl_stmt|;
if|if
condition|(
name|pos
operator|.
name|x
argument_list|()
operator|<
literal|0
condition|)
name|pos
operator|.
name|setX
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|pos
operator|.
name|y
argument_list|()
operator|<
literal|0
condition|)
name|pos
operator|.
name|setY
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|previewWidget
operator|->
name|move
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|previewWidget
operator|->
name|setWindowState
argument_list|(
name|statesControl
operator|->
name|states
argument_list|()
argument_list|)
expr_stmt|;
name|previewWidget
operator|->
name|setVisible
argument_list|(
name|statesControl
operator|->
name|visibleValue
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createTypeGroupBox
name|void
name|ControllerWindow
operator|::
name|createTypeGroupBox
parameter_list|()
block|{
name|widgetTypeGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Widget Type"
argument_list|)
argument_list|)
expr_stmt|;
name|previewWidgetButton
operator|=
name|createRadioButton
argument_list|(
name|tr
argument_list|(
literal|"QWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|previewWidgetButton
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|previewDialogButton
operator|=
name|createRadioButton
argument_list|(
name|tr
argument_list|(
literal|"QDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|l
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|previewWidgetButton
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|previewDialogButton
argument_list|)
expr_stmt|;
name|widgetTypeGroupBox
operator|->
name|setLayout
argument_list|(
name|l
argument_list|)
expr_stmt|;
name|additionalOptionsGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Additional options"
argument_list|)
argument_list|)
expr_stmt|;
name|l
operator|=
operator|new
name|QHBoxLayout
expr_stmt|;
name|modalWindowCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Modal window"
argument_list|)
argument_list|)
expr_stmt|;
name|fixedSizeWindowCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Fixed size window"
argument_list|)
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|modalWindowCheckBox
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|fixedSizeWindowCheckBox
argument_list|)
expr_stmt|;
name|additionalOptionsGroupBox
operator|->
name|setLayout
argument_list|(
name|l
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|createCheckBox
name|QCheckBox
modifier|*
name|ControllerWindow
operator|::
name|createCheckBox
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QCheckBox
modifier|*
name|checkBox
init|=
operator|new
name|QCheckBox
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|checkBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updatePreview
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|checkBox
return|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|createRadioButton
name|QRadioButton
modifier|*
name|ControllerWindow
operator|::
name|createRadioButton
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QRadioButton
modifier|*
name|button
init|=
operator|new
name|QRadioButton
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|button
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updatePreview
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|button
return|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
end_unit
