begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QScrollBar>
end_include
begin_include
include|#
directive|include
file|<QStyleOptionSlider>
end_include
begin_include
include|#
directive|include
file|<QScrollArea>
end_include
begin_class
DECL|class|tst_QScrollBar
class|class
name|tst_QScrollBar
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|hideAndShow
parameter_list|(
name|int
name|action
parameter_list|)
function_decl|;
private|private
name|slots
private|:
name|void
name|scrollSingleStep
parameter_list|()
function_decl|;
name|void
name|task_209492
parameter_list|()
function_decl|;
private|private:
DECL|member|testWidget
name|QScrollBar
modifier|*
name|testWidget
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_QScrollBar
operator|::
name|initTestCase
parameter_list|()
block|{
name|testWidget
operator|=
operator|new
name|QScrollBar
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|resize
argument_list|(
literal|100
argument_list|,
name|testWidget
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QScrollBar
operator|::
name|cleanupTestCase
parameter_list|()
block|{
operator|delete
name|testWidget
expr_stmt|;
name|testWidget
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hideAndShow
name|void
name|tst_QScrollBar
operator|::
name|hideAndShow
parameter_list|(
name|int
parameter_list|)
block|{
name|testWidget
operator|->
name|hide
argument_list|()
expr_stmt|;
name|testWidget
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// Check that the scrollbar doesn't scroll after calling hide and show
end_comment
begin_comment
comment|// from a slot connected to the scrollbar's actionTriggered signal.
end_comment
begin_function
DECL|function|scrollSingleStep
name|void
name|tst_QScrollBar
operator|::
name|scrollSingleStep
parameter_list|()
block|{
name|testWidget
operator|->
name|setValue
argument_list|(
name|testWidget
operator|->
name|minimum
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|value
argument_list|()
argument_list|,
name|testWidget
operator|->
name|minimum
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|testWidget
argument_list|,
name|SIGNAL
argument_list|(
name|actionTriggered
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|hideAndShow
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// Get rect for the area to click on
specifier|const
name|QStyleOptionSlider
name|opt
init|=
name|qt_qscrollbarStyleOption
argument_list|(
name|testWidget
argument_list|)
decl_stmt|;
name|QRect
name|sr
init|=
name|testWidget
operator|->
name|style
argument_list|()
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_ScrollBar
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_ScrollBarAddLine
argument_list|,
name|testWidget
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|sr
operator|.
name|isValid
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"SC_ScrollBarAddLine not valid"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|mouseClick
argument_list|(
name|testWidget
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|,
name|QPoint
argument_list|(
name|sr
operator|.
name|x
argument_list|()
argument_list|,
name|sr
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|510
argument_list|)
expr_stmt|;
comment|// initial delay is 500 for setRepeatAction
name|disconnect
argument_list|(
name|testWidget
argument_list|,
name|SIGNAL
argument_list|(
name|actionTriggered
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|value
argument_list|()
argument_list|,
name|testWidget
operator|->
name|singleStep
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task_209492
name|void
name|tst_QScrollBar
operator|::
name|task_209492
parameter_list|()
block|{
class|class
name|MyScrollArea
super|:
specifier|public
name|QScrollArea
block|{
public|public:
name|int
name|scrollCount
decl_stmt|;
name|MyScrollArea
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QScrollArea
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|scrollCount
argument_list|(
literal|0
argument_list|)
block|{}
protected|protected:
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QTest
operator|::
name|qSleep
argument_list|(
literal|600
argument_list|)
expr_stmt|;
block|}
name|void
name|scrollContentsBy
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
block|{
operator|++
name|scrollCount
expr_stmt|;
name|viewport
argument_list|()
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
block|}
class|;
name|MyScrollArea
name|scrollArea
decl_stmt|;
name|QScrollBar
modifier|*
name|verticalScrollBar
init|=
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
decl_stmt|;
name|verticalScrollBar
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|1000
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
name|verticalScrollBar
argument_list|,
name|SIGNAL
argument_list|(
name|actionTriggered
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|scrollCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// Simulate a mouse click on the "scroll down button".
specifier|const
name|QPoint
name|pressPoint
argument_list|(
name|verticalScrollBar
operator|->
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|verticalScrollBar
operator|->
name|height
argument_list|()
operator|-
literal|10
argument_list|)
decl_stmt|;
specifier|const
name|QPoint
name|globalPressPoint
init|=
name|verticalScrollBar
operator|->
name|mapToGlobal
argument_list|(
name|globalPressPoint
argument_list|)
decl_stmt|;
name|QMouseEvent
name|mousePressEvent
argument_list|(
name|QEvent
operator|::
name|MouseButtonPress
argument_list|,
name|pressPoint
argument_list|,
name|globalPressPoint
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|sendEvent
argument_list|(
name|verticalScrollBar
argument_list|,
operator|&
name|mousePressEvent
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QMouseEvent
name|mouseReleaseEvent
argument_list|(
name|QEvent
operator|::
name|MouseButtonRelease
argument_list|,
name|pressPoint
argument_list|,
name|globalPressPoint
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|sendEvent
argument_list|(
name|verticalScrollBar
argument_list|,
operator|&
name|mouseReleaseEvent
argument_list|)
expr_stmt|;
comment|// Check that the action was triggered once.
ifdef|#
directive|ifdef
name|Q_WS_MAC
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"Fix does does not work on Mac due to paint architechure differences."
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|scrollCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QScrollBar
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qscrollbar.moc"
end_include
end_unit
