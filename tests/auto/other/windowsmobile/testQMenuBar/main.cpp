begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDate>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<windows.h>
end_include
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
name|QList
argument_list|<
name|QWidget
modifier|*
argument_list|>
name|widgets
decl_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QMainWindow
name|mainWindow
decl_stmt|;
name|mainWindow
operator|.
name|setWindowTitle
argument_list|(
literal|"Test"
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|fileMenu
init|=
name|mainWindow
operator|.
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
literal|"File"
argument_list|)
decl_stmt|;
name|QMenu
modifier|*
name|editMenu
init|=
name|mainWindow
operator|.
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
literal|"Edit"
argument_list|)
decl_stmt|;
name|QMenu
modifier|*
name|viewMenu
init|=
name|mainWindow
operator|.
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
literal|"View"
argument_list|)
decl_stmt|;
name|QMenu
modifier|*
name|toolsMenu
init|=
name|mainWindow
operator|.
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
literal|"Tools"
argument_list|)
decl_stmt|;
name|QMenu
modifier|*
name|optionsMenu
init|=
name|mainWindow
operator|.
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
literal|"Options"
argument_list|)
decl_stmt|;
name|QMenu
modifier|*
name|helpMenu
init|=
name|mainWindow
operator|.
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
literal|"Help"
argument_list|)
decl_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
literal|"Open"
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|close
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
literal|"Close"
argument_list|)
decl_stmt|;
name|fileMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
literal|"Exit"
argument_list|)
expr_stmt|;
name|close
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
literal|"Cut"
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
literal|"Pase"
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
literal|"Copy"
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
literal|"Find"
argument_list|)
expr_stmt|;
name|viewMenu
operator|->
name|addAction
argument_list|(
literal|"Hide"
argument_list|)
expr_stmt|;
name|viewMenu
operator|->
name|addAction
argument_list|(
literal|"Show"
argument_list|)
expr_stmt|;
name|viewMenu
operator|->
name|addAction
argument_list|(
literal|"Explore"
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|visible
init|=
name|viewMenu
operator|->
name|addAction
argument_list|(
literal|"Visible"
argument_list|)
decl_stmt|;
name|visible
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|visible
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|toolsMenu
operator|->
name|addMenu
argument_list|(
literal|"Hammer"
argument_list|)
expr_stmt|;
name|toolsMenu
operator|->
name|addMenu
argument_list|(
literal|"Caliper"
argument_list|)
expr_stmt|;
name|toolsMenu
operator|->
name|addMenu
argument_list|(
literal|"Helm"
argument_list|)
expr_stmt|;
name|optionsMenu
operator|->
name|addMenu
argument_list|(
literal|"Settings"
argument_list|)
expr_stmt|;
name|optionsMenu
operator|->
name|addMenu
argument_list|(
literal|"Standard"
argument_list|)
expr_stmt|;
name|optionsMenu
operator|->
name|addMenu
argument_list|(
literal|"Extended"
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|subMenu
init|=
name|helpMenu
operator|->
name|addMenu
argument_list|(
literal|"Help"
argument_list|)
decl_stmt|;
name|subMenu
operator|->
name|addAction
argument_list|(
literal|"Index"
argument_list|)
expr_stmt|;
name|subMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|subMenu
operator|->
name|addAction
argument_list|(
literal|"Vodoo Help"
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
literal|"Contens"
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
literal|"About"
argument_list|)
expr_stmt|;
name|QToolBar
name|toolbar
decl_stmt|;
name|mainWindow
operator|.
name|addToolBar
argument_list|(
operator|&
name|toolbar
argument_list|)
expr_stmt|;
name|toolbar
operator|.
name|addAction
argument_list|(
name|QIcon
argument_list|(
name|qApp
operator|->
name|style
argument_list|()
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_FileIcon
argument_list|)
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"textAction"
argument_list|)
argument_list|)
expr_stmt|;
name|QTextEdit
name|textEdit
decl_stmt|;
name|mainWindow
operator|.
name|setCentralWidget
argument_list|(
operator|&
name|textEdit
argument_list|)
expr_stmt|;
name|mainWindow
operator|.
name|showMaximized
argument_list|()
expr_stmt|;
name|app
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
