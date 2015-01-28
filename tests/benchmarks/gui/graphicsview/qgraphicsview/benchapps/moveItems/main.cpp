begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_DEAD_CODE_FROM_QT4_WIN
end_ifdef
begin_define
DECL|macro|CALLGRIND_START_INSTRUMENTATION
define|#
directive|define
name|CALLGRIND_START_INSTRUMENTATION
value|{}
end_define
begin_define
DECL|macro|CALLGRIND_STOP_INSTRUMENTATION
define|#
directive|define
name|CALLGRIND_STOP_INSTRUMENTATION
value|{}
end_define
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"valgrind/callgrind.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_DEAD_CODE_FROM_QT4_X11
end_ifdef
begin_function_decl
specifier|extern
name|void
name|qt_x11_wait_for_window_manager
parameter_list|(
name|QWidget
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|View
class|class
name|View
super|:
specifier|public
name|QGraphicsView
block|{
name|Q_OBJECT
public|public:
DECL|function|View
name|View
parameter_list|(
name|QGraphicsScene
modifier|*
name|scene
parameter_list|,
name|QGraphicsItem
modifier|*
name|item
parameter_list|)
member_init_list|:
name|QGraphicsView
argument_list|(
name|scene
argument_list|)
member_init_list|,
name|_item
argument_list|(
name|item
argument_list|)
block|{     }
protected|protected:
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
specifier|static
name|int
name|n
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|n
condition|)
name|CALLGRIND_START_INSTRUMENTATION
name|QGraphicsView
operator|::
name|paintEvent
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|_item
operator|->
name|moveBy
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
condition|)
name|CALLGRIND_STOP_INSTRUMENTATION
if|if
condition|(
operator|++
name|n
operator|==
literal|200
condition|)
name|qApp
operator|->
name|quit
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|_item
name|QGraphicsItem
modifier|*
name|_item
decl_stmt|;
block|}
class|;
end_class
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
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
block|{
name|qDebug
argument_list|(
literal|"usage: ./%s<numItems>"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|QGraphicsScene
name|scene
argument_list|(
operator|-
literal|150
argument_list|,
operator|-
literal|150
argument_list|,
literal|300
argument_list|,
literal|300
argument_list|)
decl_stmt|;
name|scene
operator|.
name|setItemIndexMethod
argument_list|(
name|QGraphicsScene
operator|::
name|NoIndex
argument_list|)
expr_stmt|;
name|QGraphicsRectItem
modifier|*
name|item
init|=
name|scene
operator|.
name|addRect
argument_list|(
operator|-
literal|50
argument_list|,
operator|-
literal|50
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|,
name|QPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
argument_list|,
name|QBrush
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
argument_list|)
decl_stmt|;
name|item
operator|->
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsMovable
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|atoi
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|QGraphicsRectItem
modifier|*
name|child
init|=
name|scene
operator|.
name|addRect
argument_list|(
operator|-
literal|5
argument_list|,
operator|-
literal|5
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
name|QPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
argument_list|,
name|QBrush
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
argument_list|)
decl_stmt|;
name|child
operator|->
name|setPos
argument_list|(
operator|-
literal|50
operator|+
name|qrand
argument_list|()
operator|%
literal|100
argument_list|,
operator|-
literal|50
operator|+
name|qrand
argument_list|()
operator|%
literal|100
argument_list|)
expr_stmt|;
name|child
operator|->
name|setParentItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
name|View
name|view
argument_list|(
operator|&
name|scene
argument_list|,
name|item
argument_list|)
decl_stmt|;
name|view
operator|.
name|resize
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_DEAD_CODE_FROM_QT4_X11
name|qt_x11_wait_for_window_manager
argument_list|(
operator|&
name|view
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|app
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
