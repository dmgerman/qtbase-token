begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"previewwindow.h"
end_include
begin_function
DECL|function|windowFlagsToString
specifier|static
name|QString
name|windowFlagsToString
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
block|{
name|QString
name|text
decl_stmt|;
name|Qt
operator|::
name|WindowFlags
name|type
init|=
operator|(
name|flags
operator|&
name|Qt
operator|::
name|WindowType_Mask
operator|)
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|Window
condition|)
block|{
name|text
operator|=
literal|"Qt::Window"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|Dialog
condition|)
block|{
name|text
operator|=
literal|"Qt::Dialog"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|Sheet
condition|)
block|{
name|text
operator|=
literal|"Qt::Sheet"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|Drawer
condition|)
block|{
name|text
operator|=
literal|"Qt::Drawer"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|Popup
condition|)
block|{
name|text
operator|=
literal|"Qt::Popup"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|Tool
condition|)
block|{
name|text
operator|=
literal|"Qt::Tool"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|ToolTip
condition|)
block|{
name|text
operator|=
literal|"Qt::ToolTip"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|SplashScreen
condition|)
block|{
name|text
operator|=
literal|"Qt::SplashScreen"
expr_stmt|;
block|}
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|MSWindowsFixedSizeDialogHint
condition|)
name|text
operator|+=
literal|"\n| Qt::MSWindowsFixedSizeDialogHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|X11BypassWindowManagerHint
condition|)
name|text
operator|+=
literal|"\n| Qt::X11BypassWindowManagerHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|FramelessWindowHint
condition|)
name|text
operator|+=
literal|"\n| Qt::FramelessWindowHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowTitleHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowTitleHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowSystemMenuHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowSystemMenuHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowMinimizeButtonHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowMinimizeButtonHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowMaximizeButtonHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowMaximizeButtonHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowCloseButtonHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowCloseButtonHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowContextHelpButtonHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowContextHelpButtonHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowShadeButtonHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowShadeButtonHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowStaysOnTopHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowStaysOnTopHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|CustomizeWindowHint
condition|)
name|text
operator|+=
literal|"\n| Qt::CustomizeWindowHint"
expr_stmt|;
return|return
name|text
return|;
block|}
end_function
begin_constructor
DECL|function|PreviewWindow
name|PreviewWindow
operator|::
name|PreviewWindow
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|textEdit
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|textEdit
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|setLineWrapMode
argument_list|(
name|QTextEdit
operator|::
name|NoWrap
argument_list|)
expr_stmt|;
name|closeButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Close"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|closeButton
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
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|showNormalButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Show normal"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|showNormalButton
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
name|showNormal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|showMaximizedButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Show maximized"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|showMaximizedButton
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
name|showMaximized
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|showFullScreenButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Show fullscreen"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|showFullScreenButton
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
name|showFullScreen
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|textEdit
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|showNormalButton
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|showMaximizedButton
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|showFullScreenButton
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|closeButton
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Preview<QWidget>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setWindowFlags
name|void
name|PreviewWindow
operator|::
name|setWindowFlags
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
block|{
name|QWidget
operator|::
name|setWindowFlags
argument_list|(
name|flags
argument_list|)
expr_stmt|;
name|QString
name|text
init|=
name|windowFlagsToString
argument_list|(
name|flags
argument_list|)
decl_stmt|;
name|textEdit
operator|->
name|setPlainText
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|PreviewDialog
name|PreviewDialog
operator|::
name|PreviewDialog
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
block|{
name|textEdit
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|textEdit
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|setLineWrapMode
argument_list|(
name|QTextEdit
operator|::
name|NoWrap
argument_list|)
expr_stmt|;
name|closeButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Close"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|closeButton
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
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|showNormalButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Show normal"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|showNormalButton
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
name|showNormal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|showMaximizedButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Show maximized"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|showMaximizedButton
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
name|showMaximized
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|showFullScreenButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Show fullscreen"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|showFullScreenButton
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
name|showFullScreen
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|textEdit
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|showNormalButton
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|showMaximizedButton
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|showFullScreenButton
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|closeButton
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Preview<QDialog>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setWindowFlags
name|void
name|PreviewDialog
operator|::
name|setWindowFlags
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
block|{
name|QWidget
operator|::
name|setWindowFlags
argument_list|(
name|flags
argument_list|)
expr_stmt|;
name|QString
name|text
init|=
name|windowFlagsToString
argument_list|(
name|flags
argument_list|)
decl_stmt|;
name|textEdit
operator|->
name|setPlainText
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
