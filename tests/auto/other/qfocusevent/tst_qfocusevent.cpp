begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qlineedit.h>
end_include
begin_include
include|#
directive|include
file|<qmenu.h>
end_include
begin_include
include|#
directive|include
file|<qlabel.h>
end_include
begin_include
include|#
directive|include
file|<qdialog.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qlineedit.h>
end_include
begin_include
include|#
directive|include
file|<QBoxLayout>
end_include
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QWidget
argument_list|)
end_macro
begin_class
DECL|class|FocusLineEdit
class|class
name|FocusLineEdit
super|:
specifier|public
name|QLineEdit
block|{
public|public:
DECL|function|FocusLineEdit
name|FocusLineEdit
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
specifier|const
name|char
modifier|*
name|name
init|=
literal|0
parameter_list|)
member_init_list|:
name|QLineEdit
argument_list|(
name|name
argument_list|,
name|parent
argument_list|)
block|{}
DECL|member|focusInEventReason
name|int
name|focusInEventReason
decl_stmt|;
DECL|member|focusOutEventReason
name|int
name|focusOutEventReason
decl_stmt|;
DECL|member|focusInEventRecieved
name|bool
name|focusInEventRecieved
decl_stmt|;
DECL|member|focusInEventGotFocus
name|bool
name|focusInEventGotFocus
decl_stmt|;
DECL|member|focusOutEventRecieved
name|bool
name|focusOutEventRecieved
decl_stmt|;
DECL|member|focusOutEventLostFocus
name|bool
name|focusOutEventLostFocus
decl_stmt|;
protected|protected:
DECL|function|keyPressEvent
specifier|virtual
name|void
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|e
parameter_list|)
block|{
comment|//        qDebug( QString("keyPressEvent: %1").arg(e->key()) );
name|QLineEdit
operator|::
name|keyPressEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
DECL|function|focusInEvent
name|void
name|focusInEvent
parameter_list|(
name|QFocusEvent
modifier|*
name|e
parameter_list|)
block|{
name|QLineEdit
operator|::
name|focusInEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
name|focusInEventReason
operator|=
name|e
operator|->
name|reason
argument_list|()
expr_stmt|;
name|focusInEventGotFocus
operator|=
name|e
operator|->
name|gotFocus
argument_list|()
expr_stmt|;
name|focusInEventRecieved
operator|=
literal|true
expr_stmt|;
block|}
DECL|function|focusOutEvent
name|void
name|focusOutEvent
parameter_list|(
name|QFocusEvent
modifier|*
name|e
parameter_list|)
block|{
name|QLineEdit
operator|::
name|focusOutEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
name|focusOutEventReason
operator|=
name|e
operator|->
name|reason
argument_list|()
expr_stmt|;
name|focusOutEventLostFocus
operator|=
operator|!
name|e
operator|->
name|gotFocus
argument_list|()
expr_stmt|;
name|focusOutEventRecieved
operator|=
literal|true
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|tst_QFocusEvent
class|class
name|tst_QFocusEvent
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|void
name|initWidget
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|checkReason_Tab
parameter_list|()
function_decl|;
name|void
name|checkReason_ShiftTab
parameter_list|()
function_decl|;
name|void
name|checkReason_BackTab
parameter_list|()
function_decl|;
name|void
name|checkReason_Popup
parameter_list|()
function_decl|;
name|void
name|checkReason_focusWidget
parameter_list|()
function_decl|;
name|void
name|checkReason_Shortcut
parameter_list|()
function_decl|;
name|void
name|checkReason_ActiveWindow
parameter_list|()
function_decl|;
private|private:
DECL|member|testFocusWidget
name|QWidget
modifier|*
name|testFocusWidget
decl_stmt|;
DECL|member|childFocusWidgetOne
name|FocusLineEdit
modifier|*
name|childFocusWidgetOne
decl_stmt|;
DECL|member|childFocusWidgetTwo
name|FocusLineEdit
modifier|*
name|childFocusWidgetTwo
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_QFocusEvent
operator|::
name|initTestCase
parameter_list|()
block|{
name|testFocusWidget
operator|=
operator|new
name|QWidget
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|childFocusWidgetOne
operator|=
operator|new
name|FocusLineEdit
argument_list|(
name|testFocusWidget
argument_list|)
expr_stmt|;
name|childFocusWidgetOne
operator|->
name|setGeometry
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|180
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|childFocusWidgetTwo
operator|=
operator|new
name|FocusLineEdit
argument_list|(
name|testFocusWidget
argument_list|)
expr_stmt|;
name|childFocusWidgetTwo
operator|->
name|setGeometry
argument_list|(
literal|10
argument_list|,
literal|50
argument_list|,
literal|180
argument_list|,
literal|20
argument_list|)
expr_stmt|;
comment|//qApp->setMainWidget( testFocusWidget ); Qt4
name|testFocusWidget
operator|->
name|resize
argument_list|(
literal|200
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|testFocusWidget
operator|->
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|testFocusWidget
argument_list|)
argument_list|)
expr_stmt|;
comment|// Applications don't get focus when launched from the command line on Mac.
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|testFocusWidget
operator|->
name|raise
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QFocusEvent
operator|::
name|cleanupTestCase
parameter_list|()
block|{
operator|delete
name|testFocusWidget
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QFocusEvent
operator|::
name|cleanup
parameter_list|()
block|{
name|childFocusWidgetTwo
operator|->
name|setGeometry
argument_list|(
literal|10
argument_list|,
literal|50
argument_list|,
literal|180
argument_list|,
literal|20
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initWidget
name|void
name|tst_QFocusEvent
operator|::
name|initWidget
parameter_list|()
block|{
comment|// On X11 we have to ensure the event was processed before doing any checking, on Windows
comment|// this is processed straight away.
name|QApplication
operator|::
name|setActiveWindow
argument_list|(
name|testFocusWidget
argument_list|)
expr_stmt|;
name|childFocusWidgetOne
operator|->
name|setFocus
argument_list|()
expr_stmt|;
comment|// The first lineedit should have focus
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowActive
argument_list|(
name|testFocusWidget
argument_list|)
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|childFocusWidgetOne
operator|->
name|focusInEventRecieved
operator|=
literal|false
expr_stmt|;
name|childFocusWidgetOne
operator|->
name|focusInEventGotFocus
operator|=
literal|false
expr_stmt|;
name|childFocusWidgetOne
operator|->
name|focusInEventReason
operator|=
operator|-
literal|1
expr_stmt|;
name|childFocusWidgetOne
operator|->
name|focusOutEventRecieved
operator|=
literal|false
expr_stmt|;
name|childFocusWidgetOne
operator|->
name|focusOutEventLostFocus
operator|=
literal|false
expr_stmt|;
name|childFocusWidgetOne
operator|->
name|focusOutEventReason
operator|=
operator|-
literal|1
expr_stmt|;
name|childFocusWidgetTwo
operator|->
name|focusInEventRecieved
operator|=
literal|false
expr_stmt|;
name|childFocusWidgetTwo
operator|->
name|focusInEventGotFocus
operator|=
literal|false
expr_stmt|;
name|childFocusWidgetTwo
operator|->
name|focusInEventReason
operator|=
operator|-
literal|1
expr_stmt|;
name|childFocusWidgetTwo
operator|->
name|focusOutEventRecieved
operator|=
literal|false
expr_stmt|;
name|childFocusWidgetTwo
operator|->
name|focusOutEventLostFocus
operator|=
literal|false
expr_stmt|;
name|childFocusWidgetTwo
operator|->
name|focusOutEventReason
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkReason_Tab
name|void
name|tst_QFocusEvent
operator|::
name|checkReason_Tab
parameter_list|()
block|{
name|initWidget
argument_list|()
expr_stmt|;
comment|// Now test the tab key
name|QTest
operator|::
name|keyClick
argument_list|(
name|childFocusWidgetOne
argument_list|,
name|Qt
operator|::
name|Key_Tab
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventLostFocus
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|focusInEventGotFocus
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventReason
argument_list|,
operator|(
name|int
operator|)
name|Qt
operator|::
name|TabFocusReason
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childFocusWidgetTwo
operator|->
name|focusInEventReason
argument_list|,
operator|(
name|int
operator|)
name|Qt
operator|::
name|TabFocusReason
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkReason_ShiftTab
name|void
name|tst_QFocusEvent
operator|::
name|checkReason_ShiftTab
parameter_list|()
block|{
name|initWidget
argument_list|()
expr_stmt|;
comment|// Now test the shift + tab key
name|QTest
operator|::
name|keyClick
argument_list|(
name|childFocusWidgetOne
argument_list|,
name|Qt
operator|::
name|Key_Tab
argument_list|,
name|Qt
operator|::
name|ShiftModifier
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventLostFocus
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|focusInEventGotFocus
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventReason
argument_list|,
operator|(
name|int
operator|)
name|Qt
operator|::
name|BacktabFocusReason
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childFocusWidgetTwo
operator|->
name|focusInEventReason
argument_list|,
operator|(
name|int
operator|)
name|Qt
operator|::
name|BacktabFocusReason
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     In this test we verify that the Qt::KeyBacktab key is handled in a qfocusevent */
end_comment
begin_function
DECL|function|checkReason_BackTab
name|void
name|tst_QFocusEvent
operator|::
name|checkReason_BackTab
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN32
comment|// key is not supported on Windows
name|QSKIP
argument_list|(
literal|"Backtab is not supported on Windows"
argument_list|)
expr_stmt|;
else|#
directive|else
name|initWidget
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
comment|// Now test the backtab key
name|QTest
operator|::
name|keyClick
argument_list|(
name|childFocusWidgetOne
argument_list|,
name|Qt
operator|::
name|Key_Backtab
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventLostFocus
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|focusInEventGotFocus
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventReason
argument_list|,
name|int
argument_list|(
name|Qt
operator|::
name|BacktabFocusReason
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childFocusWidgetTwo
operator|->
name|focusInEventReason
argument_list|,
name|int
argument_list|(
name|Qt
operator|::
name|BacktabFocusReason
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|checkReason_Popup
name|void
name|tst_QFocusEvent
operator|::
name|checkReason_Popup
parameter_list|()
block|{
name|initWidget
argument_list|()
expr_stmt|;
comment|// Now test the popup reason
name|QMenu
modifier|*
name|popupMenu
init|=
operator|new
name|QMenu
argument_list|(
name|testFocusWidget
argument_list|)
decl_stmt|;
name|popupMenu
operator|->
name|addMenu
argument_list|(
literal|"Test"
argument_list|)
expr_stmt|;
name|popupMenu
operator|->
name|popup
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventLostFocus
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childFocusWidgetOne
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childFocusWidgetTwo
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childFocusWidgetTwo
operator|->
name|focusOutEventRecieved
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventReason
argument_list|,
name|int
argument_list|(
name|Qt
operator|::
name|PopupFocusReason
argument_list|)
argument_list|)
expr_stmt|;
name|popupMenu
operator|->
name|hide
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusInEventGotFocus
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childFocusWidgetTwo
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childFocusWidgetTwo
operator|->
name|focusOutEventRecieved
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_function_decl
name|QT_BEGIN_NAMESPACE
specifier|extern
name|void
name|qt_set_sequence_auto_mnemonic
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl
begin_function
name|QT_END_NAMESPACE
endif|#
directive|endif
DECL|function|checkReason_Shortcut
name|void
name|tst_QFocusEvent
operator|::
name|checkReason_Shortcut
parameter_list|()
block|{
name|initWidget
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|qt_set_sequence_auto_mnemonic
argument_list|(
literal|true
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
literal|"&Test"
argument_list|,
name|testFocusWidget
argument_list|)
decl_stmt|;
name|label
operator|->
name|setBuddy
argument_list|(
name|childFocusWidgetTwo
argument_list|)
expr_stmt|;
name|label
operator|->
name|setGeometry
argument_list|(
literal|10
argument_list|,
literal|50
argument_list|,
literal|90
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|childFocusWidgetTwo
operator|->
name|setGeometry
argument_list|(
literal|105
argument_list|,
literal|50
argument_list|,
literal|95
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|label
operator|->
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childFocusWidgetTwo
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|label
argument_list|,
name|Qt
operator|::
name|Key_T
argument_list|,
name|Qt
operator|::
name|AltModifier
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventLostFocus
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|focusInEventGotFocus
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childFocusWidgetOne
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventRecieved
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventReason
argument_list|,
operator|(
name|int
operator|)
name|Qt
operator|::
name|ShortcutFocusReason
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childFocusWidgetTwo
operator|->
name|focusInEventReason
argument_list|,
operator|(
name|int
operator|)
name|Qt
operator|::
name|ShortcutFocusReason
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childFocusWidgetTwo
operator|->
name|focusOutEventRecieved
argument_list|)
expr_stmt|;
name|label
operator|->
name|hide
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetTwo
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childFocusWidgetOne
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|qt_set_sequence_auto_mnemonic
argument_list|(
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|checkReason_focusWidget
name|void
name|tst_QFocusEvent
operator|::
name|checkReason_focusWidget
parameter_list|()
block|{
comment|// This test checks that a widget doesn't loose
comment|// its focuswidget just because the focuswidget looses focus.
name|QWidget
name|window1
decl_stmt|;
name|QWidget
name|frame1
decl_stmt|;
name|QWidget
name|frame2
decl_stmt|;
name|QLineEdit
name|edit1
decl_stmt|;
name|QLineEdit
name|edit2
decl_stmt|;
name|QVBoxLayout
name|outerLayout
decl_stmt|;
name|outerLayout
operator|.
name|addWidget
argument_list|(
operator|&
name|frame1
argument_list|)
expr_stmt|;
name|outerLayout
operator|.
name|addWidget
argument_list|(
operator|&
name|frame2
argument_list|)
expr_stmt|;
name|window1
operator|.
name|setLayout
argument_list|(
operator|&
name|outerLayout
argument_list|)
expr_stmt|;
name|QVBoxLayout
name|leftLayout
decl_stmt|;
name|QVBoxLayout
name|rightLayout
decl_stmt|;
name|leftLayout
operator|.
name|addWidget
argument_list|(
operator|&
name|edit1
argument_list|)
expr_stmt|;
name|rightLayout
operator|.
name|addWidget
argument_list|(
operator|&
name|edit2
argument_list|)
expr_stmt|;
name|frame1
operator|.
name|setLayout
argument_list|(
operator|&
name|leftLayout
argument_list|)
expr_stmt|;
name|frame2
operator|.
name|setLayout
argument_list|(
operator|&
name|rightLayout
argument_list|)
expr_stmt|;
name|window1
operator|.
name|show
argument_list|()
expr_stmt|;
name|edit1
operator|.
name|setFocus
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|edit2
operator|.
name|setFocus
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|frame1
operator|.
name|focusWidget
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|frame2
operator|.
name|focusWidget
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkReason_ActiveWindow
name|void
name|tst_QFocusEvent
operator|::
name|checkReason_ActiveWindow
parameter_list|()
block|{
name|initWidget
argument_list|()
expr_stmt|;
name|QDialog
modifier|*
name|d
init|=
operator|new
name|QDialog
argument_list|(
name|testFocusWidget
argument_list|)
decl_stmt|;
name|d
operator|->
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|activateWindow
argument_list|()
expr_stmt|;
comment|// ### CDE
name|QApplication
operator|::
name|setActiveWindow
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowActive
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventLostFocus
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childFocusWidgetOne
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventRecieved
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusOutEventReason
argument_list|,
operator|(
name|int
operator|)
name|Qt
operator|::
name|ActiveWindowFocusReason
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childFocusWidgetOne
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|hide
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_IRIX
argument_list|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"IRIX requires explicit activateWindow(), so this test does not make any sense."
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QTRY_VERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusInEventGotFocus
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusInEventRecieved
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childFocusWidgetOne
operator|->
name|focusInEventReason
argument_list|,
operator|(
name|int
operator|)
name|Qt
operator|::
name|ActiveWindowFocusReason
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QFocusEvent
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qfocusevent.moc"
end_include
end_unit
