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
file|<QMessageBox>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QSplashScreen>
end_include
begin_include
include|#
directive|include
file|<QScrollBar>
end_include
begin_include
include|#
directive|include
file|<QProgressDialog>
end_include
begin_include
include|#
directive|include
file|<QSpinBox>
end_include
begin_include
include|#
directive|include
file|<guitest.h>
end_include
begin_class
DECL|class|tst_MacGui
class|class
name|tst_MacGui
super|:
specifier|public
name|GuiTester
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|scrollbarPainting
parameter_list|()
function_decl|;
name|void
name|dummy
parameter_list|()
function_decl|;
name|void
name|splashScreenModality
parameter_list|()
function_decl|;
name|void
name|nonModalOrder
parameter_list|()
function_decl|;
name|void
name|spinBoxArrowButtons
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|grabWindowContents
name|QPixmap
name|grabWindowContents
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
return|return
name|QPixmap
operator|::
name|grabWindow
argument_list|(
name|widget
operator|->
name|winId
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*     Test that vertical and horizontal mac-style scrollbars paint their     entire area. */
end_comment
begin_function
DECL|function|scrollbarPainting
name|void
name|tst_MacGui
operator|::
name|scrollbarPainting
parameter_list|()
block|{
name|ColorWidget
name|colorWidget
decl_stmt|;
name|colorWidget
operator|.
name|resize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|QSize
name|scrollBarSize
decl_stmt|;
name|QScrollBar
name|verticalScrollbar
argument_list|(
operator|&
name|colorWidget
argument_list|)
decl_stmt|;
name|verticalScrollbar
operator|.
name|move
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|scrollBarSize
operator|=
name|verticalScrollbar
operator|.
name|sizeHint
argument_list|()
expr_stmt|;
name|scrollBarSize
operator|.
name|setHeight
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|verticalScrollbar
operator|.
name|resize
argument_list|(
name|scrollBarSize
argument_list|)
expr_stmt|;
name|QScrollBar
name|horizontalScrollbar
argument_list|(
operator|&
name|colorWidget
argument_list|)
decl_stmt|;
name|horizontalScrollbar
operator|.
name|move
argument_list|(
literal|30
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|horizontalScrollbar
operator|.
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|scrollBarSize
operator|=
name|horizontalScrollbar
operator|.
name|sizeHint
argument_list|()
expr_stmt|;
name|scrollBarSize
operator|.
name|setWidth
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|horizontalScrollbar
operator|.
name|resize
argument_list|(
name|scrollBarSize
argument_list|)
expr_stmt|;
name|colorWidget
operator|.
name|show
argument_list|()
expr_stmt|;
name|colorWidget
operator|.
name|raise
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QPixmap
name|pixmap
init|=
name|grabWindowContents
argument_list|(
operator|&
name|colorWidget
argument_list|)
decl_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"QTBUG-26371"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|isContent
argument_list|(
name|pixmap
operator|.
name|toImage
argument_list|()
argument_list|,
name|verticalScrollbar
operator|.
name|geometry
argument_list|()
argument_list|,
name|GuiTester
operator|::
name|Horizontal
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|isContent
argument_list|(
name|pixmap
operator|.
name|toImage
argument_list|()
argument_list|,
name|horizontalScrollbar
operator|.
name|geometry
argument_list|()
argument_list|,
name|GuiTester
operator|::
name|Vertical
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// When running the auto-tests on scruffy, the first enter-the-event-loop-and-wait-for-a-click
end_comment
begin_comment
comment|// test that runs always times out, so we have this dummy test.
end_comment
begin_function
DECL|function|dummy
name|void
name|tst_MacGui
operator|::
name|dummy
parameter_list|()
block|{
name|QPixmap
name|pix
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
decl_stmt|;
name|QSplashScreen
name|splash
argument_list|(
name|pix
argument_list|)
decl_stmt|;
name|splash
operator|.
name|show
argument_list|()
expr_stmt|;
name|QMessageBox
modifier|*
name|box
init|=
operator|new
name|QMessageBox
argument_list|()
decl_stmt|;
name|box
operator|->
name|setText
argument_list|(
literal|"accessible?"
argument_list|)
expr_stmt|;
name|box
operator|->
name|show
argument_list|()
expr_stmt|;
comment|// Find the "OK" button and schedule a press.
name|QAccessibleInterface
modifier|*
name|interface
init|=
name|wn
operator|.
name|find
argument_list|(
name|QAccessible
operator|::
name|Name
argument_list|,
literal|"OK"
argument_list|,
name|box
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|interface
argument_list|)
expr_stmt|;
specifier|const
name|int
name|delay
init|=
literal|1000
decl_stmt|;
name|clickLater
argument_list|(
name|interface
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
name|delay
argument_list|)
expr_stmt|;
comment|// Show dialog and enter event loop.
name|connect
argument_list|(
name|wn
operator|.
name|getWidget
argument_list|(
name|interface
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|exitLoopSlot
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|int
name|timeout
init|=
literal|4
decl_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
name|timeout
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Test that a message box pops up in front of a QSplashScreen. */
end_comment
begin_function
DECL|function|splashScreenModality
name|void
name|tst_MacGui
operator|::
name|splashScreenModality
parameter_list|()
block|{
name|QPixmap
name|pix
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
decl_stmt|;
name|QSplashScreen
name|splash
argument_list|(
name|pix
argument_list|)
decl_stmt|;
name|splash
operator|.
name|show
argument_list|()
expr_stmt|;
name|QMessageBox
name|box
decl_stmt|;
comment|//box.setWindowFlags(box.windowFlags() | Qt::WindowStaysOnTopHint);
name|box
operator|.
name|setText
argument_list|(
literal|"accessible?"
argument_list|)
expr_stmt|;
name|box
operator|.
name|show
argument_list|()
expr_stmt|;
name|QSKIP
argument_list|(
literal|"QTBUG-35169"
argument_list|)
expr_stmt|;
comment|// Find the "OK" button and schedule a press.
name|QAccessibleInterface
modifier|*
name|interface
init|=
name|wn
operator|.
name|find
argument_list|(
name|QAccessible
operator|::
name|Name
argument_list|,
literal|"OK"
argument_list|,
operator|&
name|box
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|interface
argument_list|)
expr_stmt|;
specifier|const
name|int
name|delay
init|=
literal|1000
decl_stmt|;
name|clickLater
argument_list|(
name|interface
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
name|delay
argument_list|)
expr_stmt|;
comment|// Show dialog and enter event loop.
name|connect
argument_list|(
name|wn
operator|.
name|getWidget
argument_list|(
name|interface
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|exitLoopSlot
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|int
name|timeout
init|=
literal|4
decl_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
name|timeout
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|PrimaryWindowDialog
class|class
name|PrimaryWindowDialog
super|:
specifier|public
name|QDialog
block|{
name|Q_OBJECT
public|public:
name|PrimaryWindowDialog
parameter_list|()
constructor_decl|;
DECL|member|secondaryWindow
name|QWidget
modifier|*
name|secondaryWindow
decl_stmt|;
DECL|member|frontWidget
name|QWidget
modifier|*
name|frontWidget
decl_stmt|;
public|public
name|slots
public|:
name|void
name|showSecondaryWindow
parameter_list|()
function_decl|;
name|void
name|test
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|PrimaryWindowDialog
name|PrimaryWindowDialog
operator|::
name|PrimaryWindowDialog
parameter_list|()
member_init_list|:
name|QDialog
argument_list|(
literal|0
argument_list|)
block|{
name|frontWidget
operator|=
literal|0
expr_stmt|;
name|secondaryWindow
operator|=
operator|new
name|ColorWidget
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|secondaryWindow
operator|->
name|setWindowFlags
argument_list|(
name|Qt
operator|::
name|Window
argument_list|)
expr_stmt|;
name|secondaryWindow
operator|->
name|resize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|secondaryWindow
operator|->
name|move
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|1000
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showSecondaryWindow
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|2000
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|test
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|3000
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
block|}
end_constructor
begin_function
DECL|function|showSecondaryWindow
name|void
name|PrimaryWindowDialog
operator|::
name|showSecondaryWindow
parameter_list|()
block|{
name|secondaryWindow
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|test
name|void
name|PrimaryWindowDialog
operator|::
name|test
parameter_list|()
block|{
name|frontWidget
operator|=
name|QApplication
operator|::
name|widgetAt
argument_list|(
name|secondaryWindow
operator|->
name|mapToGlobal
argument_list|(
name|QPoint
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Test that a non-modal child window of a modal dialog is shown in front     of the dialog even if the dialog becomes modal after the child window     is created. */
end_comment
begin_function
DECL|function|nonModalOrder
name|void
name|tst_MacGui
operator|::
name|nonModalOrder
parameter_list|()
block|{
name|clearSequence
argument_list|()
expr_stmt|;
name|PrimaryWindowDialog
name|primary
decl_stmt|;
name|primary
operator|.
name|resize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|primary
operator|.
name|move
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|primary
operator|.
name|exec
argument_list|()
expr_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"Non-modal child windows show behind the modal dialig"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|primary
operator|.
name|frontWidget
argument_list|,
name|primary
operator|.
name|secondaryWindow
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Test that the QSpinBox buttons are correctly positioned with the Mac style. */
end_comment
begin_function
DECL|function|spinBoxArrowButtons
name|void
name|tst_MacGui
operator|::
name|spinBoxArrowButtons
parameter_list|()
block|{
name|ColorWidget
name|colorWidget
decl_stmt|;
name|colorWidget
operator|.
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|QSpinBox
name|spinBox
argument_list|(
operator|&
name|colorWidget
argument_list|)
decl_stmt|;
name|QSpinBox
name|spinBox2
argument_list|(
operator|&
name|colorWidget
argument_list|)
decl_stmt|;
name|spinBox2
operator|.
name|move
argument_list|(
literal|0
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|colorWidget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
comment|// Grab an unfocused spin box.
specifier|const
name|QImage
name|noFocus
init|=
name|grabWindowContents
argument_list|(
operator|&
name|colorWidget
argument_list|)
operator|.
name|toImage
argument_list|()
decl_stmt|;
comment|// Set focus by clicking the less button.
name|QAccessibleInterface
modifier|*
name|lessInterface
init|=
name|wn
operator|.
name|find
argument_list|(
name|QAccessible
operator|::
name|Name
argument_list|,
literal|"Less"
argument_list|,
operator|&
name|spinBox
argument_list|)
decl_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"QTBUG-26372"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lessInterface
argument_list|)
expr_stmt|;
specifier|const
name|int
name|delay
init|=
literal|500
decl_stmt|;
name|clickLater
argument_list|(
name|lessInterface
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
name|delay
argument_list|)
expr_stmt|;
specifier|const
name|int
name|timeout
init|=
literal|1
decl_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
name|timeout
argument_list|)
expr_stmt|;
comment|// Grab a focused spin box.
specifier|const
name|QImage
name|focus
init|=
name|grabWindowContents
argument_list|(
operator|&
name|colorWidget
argument_list|)
operator|.
name|toImage
argument_list|()
decl_stmt|;
comment|// Compare the arrow area of the less button to see if it moved.
specifier|const
name|QRect
name|lessRect
init|=
name|lessInterface
operator|->
name|rect
argument_list|()
decl_stmt|;
specifier|const
name|QRect
name|lessLocalRect
argument_list|(
name|colorWidget
operator|.
name|mapFromGlobal
argument_list|(
name|lessRect
operator|.
name|topLeft
argument_list|()
argument_list|)
argument_list|,
name|colorWidget
operator|.
name|mapFromGlobal
argument_list|(
name|lessRect
operator|.
name|bottomRight
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|compareRect
init|=
name|lessLocalRect
operator|.
name|adjusted
argument_list|(
literal|5
argument_list|,
literal|3
argument_list|,
operator|-
literal|5
argument_list|,
operator|-
literal|7
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|noFocus
operator|.
name|copy
argument_list|(
name|compareRect
argument_list|)
argument_list|,
name|focus
operator|.
name|copy
argument_list|(
name|compareRect
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_MacGui
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_macgui.moc"
end_include
end_unit
