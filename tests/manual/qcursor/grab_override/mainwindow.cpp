begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"ui_mainwindow.h"
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QBitmap>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QKeyEvent>
end_include
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
member_init_list|,
name|ui
argument_list|(
operator|new
name|Ui
operator|::
name|MainWindow
argument_list|)
block|{
name|ui
operator|->
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QPixmap
name|pix
argument_list|(
literal|":/data/monkey_on_64x64.png"
argument_list|)
decl_stmt|;
name|QImage
name|mask
argument_list|(
literal|16
argument_list|,
literal|16
argument_list|,
name|QImage
operator|::
name|Format_MonoLSB
argument_list|)
decl_stmt|;
name|QImage
name|bw
argument_list|(
literal|16
argument_list|,
literal|16
argument_list|,
name|QImage
operator|::
name|Format_MonoLSB
argument_list|)
decl_stmt|;
name|mask
operator|.
name|fill
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bw
operator|.
name|fill
argument_list|(
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
literal|16
condition|;
name|x
operator|++
control|)
block|{
name|bw
operator|.
name|setPixel
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|bw
operator|.
name|setPixel
argument_list|(
name|x
argument_list|,
literal|15
operator|-
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mask
operator|.
name|setPixel
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mask
operator|.
name|setPixel
argument_list|(
name|x
argument_list|,
literal|15
operator|-
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|>
literal|0
operator|&&
name|x
operator|<
literal|15
condition|)
block|{
name|mask
operator|.
name|setPixel
argument_list|(
name|x
operator|-
literal|1
argument_list|,
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mask
operator|.
name|setPixel
argument_list|(
name|x
operator|+
literal|1
argument_list|,
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mask
operator|.
name|setPixel
argument_list|(
name|x
operator|-
literal|1
argument_list|,
literal|15
operator|-
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mask
operator|.
name|setPixel
argument_list|(
name|x
operator|+
literal|1
argument_list|,
literal|15
operator|-
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
name|ccurs
operator|=
name|QCursor
argument_list|(
name|pix
argument_list|)
expr_stmt|;
name|bcurs
operator|=
name|QCursor
argument_list|(
name|QBitmap
operator|::
name|fromImage
argument_list|(
name|bw
argument_list|)
argument_list|,
name|QBitmap
operator|::
name|fromImage
argument_list|(
name|mask
argument_list|)
argument_list|)
expr_stmt|;
name|ui
operator|->
name|label
operator|->
name|setCursor
argument_list|(
name|ccurs
argument_list|)
expr_stmt|;
name|timer
operator|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|toggleOverrideCursor
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|->
name|start
argument_list|(
literal|2000
argument_list|)
expr_stmt|;
name|override
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~MainWindow
name|MainWindow
operator|::
name|~
name|MainWindow
parameter_list|()
block|{
operator|delete
name|timer
expr_stmt|;
operator|delete
name|ui
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|toggleOverrideCursor
name|void
name|MainWindow
operator|::
name|toggleOverrideCursor
parameter_list|()
block|{
switch|switch
condition|(
name|override
condition|)
block|{
case|case
literal|0
case|:
name|QApplication
operator|::
name|setOverrideCursor
argument_list|(
name|Qt
operator|::
name|BusyCursor
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|QApplication
operator|::
name|restoreOverrideCursor
argument_list|()
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|ui
operator|->
name|label
operator|->
name|grabMouse
argument_list|(
name|Qt
operator|::
name|ForbiddenCursor
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
case|case
literal|5
case|:
name|ui
operator|->
name|label
operator|->
name|releaseMouse
argument_list|()
expr_stmt|;
break|break;
case|case
literal|4
case|:
name|ui
operator|->
name|label
operator|->
name|grabMouse
argument_list|()
expr_stmt|;
break|break;
case|case
literal|6
case|:
name|ui
operator|->
name|label
operator|->
name|setCursor
argument_list|(
name|bcurs
argument_list|)
expr_stmt|;
break|break;
case|case
literal|7
case|:
name|ui
operator|->
name|label
operator|->
name|setCursor
argument_list|(
name|ccurs
argument_list|)
expr_stmt|;
break|break;
block|}
name|override
operator|=
operator|(
name|override
operator|+
literal|1
operator|)
operator|%
literal|8
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyPressEvent
name|void
name|MainWindow
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPoint
name|off
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|event
operator|->
name|key
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|Key_Up
case|:
name|off
operator|.
name|setY
argument_list|(
operator|-
literal|4
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Down
case|:
name|off
operator|.
name|setY
argument_list|(
literal|4
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Left
case|:
name|off
operator|.
name|setX
argument_list|(
operator|-
literal|4
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Right
case|:
name|off
operator|.
name|setX
argument_list|(
literal|4
argument_list|)
expr_stmt|;
break|break;
default|default:
return|return
name|QMainWindow
operator|::
name|keyPressEvent
argument_list|(
name|event
argument_list|)
return|;
block|}
name|off
operator|+=
name|QCursor
operator|::
name|pos
argument_list|()
expr_stmt|;
name|QCursor
operator|::
name|setPos
argument_list|(
name|off
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
