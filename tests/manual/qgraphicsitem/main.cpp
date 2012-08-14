begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets/QApplication>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsScene>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QMessageBox>
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
literal|"The red rectangle should toggle visiblity, so you should see it flash on and off"
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
