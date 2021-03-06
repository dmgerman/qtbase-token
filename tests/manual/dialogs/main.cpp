begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"filedialogpanel.h"
end_include
begin_include
include|#
directive|include
file|"colordialogpanel.h"
end_include
begin_include
include|#
directive|include
file|"fontdialogpanel.h"
end_include
begin_include
include|#
directive|include
file|"printdialogpanel.h"
end_include
begin_include
include|#
directive|include
file|"wizardpanel.h"
end_include
begin_include
include|#
directive|include
file|"messageboxpanel.h"
end_include
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QMenuBar>
end_include
begin_include
include|#
directive|include
file|<QTabWidget>
end_include
begin_include
include|#
directive|include
file|<QMenu>
end_include
begin_include
include|#
directive|include
file|<QAction>
end_include
begin_include
include|#
directive|include
file|<QKeySequence>
end_include
begin_comment
comment|// Test for dialogs, allowing to play with all dialog options for implementing native dialogs.
end_comment
begin_comment
comment|// Compiles with Qt 4.8 and Qt 5.
end_comment
begin_class
DECL|class|MainWindow
class|class
name|MainWindow
super|:
specifier|public
name|QMainWindow
block|{
name|Q_OBJECT
public|public:
specifier|explicit
name|MainWindow
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QMainWindow
argument_list|(
name|parent
argument_list|)
block|{
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Dialogs Qt %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|fileMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"File"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|quitAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Quit"
argument_list|)
argument_list|)
decl_stmt|;
name|quitAction
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
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
name|QMenu
modifier|*
name|editMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Edit"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|action
init|=
name|editMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Cut"
argument_list|)
argument_list|)
decl_stmt|;
name|action
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
argument_list|)
expr_stmt|;
name|action
operator|=
name|editMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Copy"
argument_list|)
argument_list|)
expr_stmt|;
name|action
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
name|QKeySequence
operator|::
name|Copy
argument_list|)
argument_list|)
expr_stmt|;
name|action
operator|=
name|editMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Paste"
argument_list|)
argument_list|)
expr_stmt|;
name|action
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
name|QKeySequence
operator|::
name|Paste
argument_list|)
argument_list|)
expr_stmt|;
name|action
operator|=
name|editMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Select All"
argument_list|)
argument_list|)
expr_stmt|;
name|action
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
name|QKeySequence
operator|::
name|SelectAll
argument_list|)
argument_list|)
expr_stmt|;
name|QTabWidget
modifier|*
name|tabWidget
init|=
operator|new
name|QTabWidget
decl_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
operator|new
name|FileDialogPanel
argument_list|,
name|tr
argument_list|(
literal|"QFileDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
operator|new
name|ColorDialogPanel
argument_list|,
name|tr
argument_list|(
literal|"QColorDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
operator|new
name|FontDialogPanel
argument_list|,
name|tr
argument_list|(
literal|"QFontDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
operator|new
name|WizardPanel
argument_list|,
name|tr
argument_list|(
literal|"QWizard"
argument_list|)
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
operator|new
name|MessageBoxPanel
argument_list|,
name|tr
argument_list|(
literal|"QMessageBox"
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
name|tabWidget
operator|->
name|addTab
argument_list|(
operator|new
name|PrintDialogPanel
argument_list|,
name|tr
argument_list|(
literal|"QPrintDialog"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setCentralWidget
argument_list|(
name|tabWidget
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
name|a
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|MainWindow
name|w
decl_stmt|;
name|w
operator|.
name|move
argument_list|(
literal|500
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|a
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
