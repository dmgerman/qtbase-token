begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QGraphicsView>
end_include
begin_include
include|#
directive|include
file|<QGraphicsScene>
end_include
begin_include
include|#
directive|include
file|<QGraphicsItem>
end_include
begin_include
include|#
directive|include
file|<QMessageBox>
end_include
begin_class
DECL|class|MyObject
class|class
name|MyObject
super|:
specifier|public
name|QObject
block|{
public|public:
DECL|function|MyObject
name|MyObject
parameter_list|(
name|QGraphicsItem
modifier|*
name|i
parameter_list|,
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|itemToToggle
argument_list|(
name|i
argument_list|)
block|{
name|startTimer
argument_list|(
literal|500
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|function|timerEvent
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
block|{
name|itemToToggle
operator|->
name|setVisible
argument_list|(
operator|!
name|itemToToggle
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|itemToToggle
name|QGraphicsItem
modifier|*
name|itemToToggle
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
name|a
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QGraphicsView
name|gv
decl_stmt|;
name|QGraphicsScene
modifier|*
name|scene
init|=
operator|new
name|QGraphicsScene
argument_list|(
operator|&
name|gv
argument_list|)
decl_stmt|;
name|gv
operator|.
name|setScene
argument_list|(
name|scene
argument_list|)
expr_stmt|;
name|QGraphicsItem
modifier|*
name|rect
init|=
name|scene
operator|->
name|addRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|200
argument_list|,
literal|200
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
name|yellow
argument_list|)
argument_list|)
decl_stmt|;
name|rect
operator|->
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemHasNoContents
argument_list|)
expr_stmt|;
name|rect
operator|->
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemClipsChildrenToShape
argument_list|)
expr_stmt|;
name|QGraphicsItem
modifier|*
name|childRect
init|=
name|scene
operator|->
name|addRect
argument_list|(
literal|0
argument_list|,
literal|0
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
name|red
argument_list|)
argument_list|)
decl_stmt|;
name|childRect
operator|->
name|setParentItem
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|gv
operator|.
name|show
argument_list|()
expr_stmt|;
name|MyObject
name|o
argument_list|(
name|rect
argument_list|)
decl_stmt|;
name|QMessageBox
operator|::
name|information
argument_list|(
literal|0
argument_list|,
literal|"What you should see"
argument_list|,
literal|"The red rectangle should toggle visibility, so you should see it flash on and off"
argument_list|)
expr_stmt|;
return|return
name|a
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
