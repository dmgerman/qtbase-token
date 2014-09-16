begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qtoolbutton.h>
end_include
begin_include
include|#
directive|include
file|<qmenu.h>
end_include
begin_include
include|#
directive|include
file|<qaction.h>
end_include
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<qscreen.h>
end_include
begin_include
include|#
directive|include
file|<qlabel.h>
end_include
begin_class
DECL|class|tst_QToolButton
class|class
name|tst_QToolButton
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QToolButton
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QToolButton
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|triggered
parameter_list|()
function_decl|;
name|void
name|collapseTextOnPriority
parameter_list|()
function_decl|;
name|void
name|task230994_iconSize
parameter_list|()
function_decl|;
name|void
name|task176137_autoRepeatOfAction
parameter_list|()
function_decl|;
name|void
name|qtbug_26956_popupTimerDone
parameter_list|()
function_decl|;
name|void
name|qtbug_34759_sizeHintResetWhenSettingMenu
parameter_list|()
function_decl|;
protected|protected
name|slots
protected|:
name|void
name|sendMouseClick
parameter_list|()
function_decl|;
private|private:
DECL|member|m_menu
name|QPointer
argument_list|<
name|QWidget
argument_list|>
name|m_menu
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QToolButton
name|tst_QToolButton
operator|::
name|tst_QToolButton
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QToolButton
name|tst_QToolButton
operator|::
name|~
name|tst_QToolButton
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QToolButton
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QToolButton
name|obj1
decl_stmt|;
comment|// QMenu* QToolButton::menu()
comment|// void QToolButton::setMenu(QMenu*)
name|QMenu
modifier|*
name|var1
init|=
operator|new
name|QMenu
decl_stmt|;
name|obj1
operator|.
name|setMenu
argument_list|(
name|var1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|var1
argument_list|,
name|obj1
operator|.
name|menu
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMenu
argument_list|(
operator|(
name|QMenu
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QMenu
operator|*
operator|)
literal|0
argument_list|,
name|obj1
operator|.
name|menu
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|var1
expr_stmt|;
comment|// ToolButtonPopupMode QToolButton::popupMode()
comment|// void QToolButton::setPopupMode(ToolButtonPopupMode)
name|obj1
operator|.
name|setPopupMode
argument_list|(
name|QToolButton
operator|::
name|ToolButtonPopupMode
argument_list|(
name|QToolButton
operator|::
name|DelayedPopup
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QToolButton
operator|::
name|ToolButtonPopupMode
argument_list|(
name|QToolButton
operator|::
name|DelayedPopup
argument_list|)
argument_list|,
name|obj1
operator|.
name|popupMode
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setPopupMode
argument_list|(
name|QToolButton
operator|::
name|ToolButtonPopupMode
argument_list|(
name|QToolButton
operator|::
name|MenuButtonPopup
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QToolButton
operator|::
name|ToolButtonPopupMode
argument_list|(
name|QToolButton
operator|::
name|MenuButtonPopup
argument_list|)
argument_list|,
name|obj1
operator|.
name|popupMode
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setPopupMode
argument_list|(
name|QToolButton
operator|::
name|ToolButtonPopupMode
argument_list|(
name|QToolButton
operator|::
name|InstantPopup
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QToolButton
operator|::
name|ToolButtonPopupMode
argument_list|(
name|QToolButton
operator|::
name|InstantPopup
argument_list|)
argument_list|,
name|obj1
operator|.
name|popupMode
argument_list|()
argument_list|)
expr_stmt|;
comment|// bool QToolButton::autoRaise()
comment|// void QToolButton::setAutoRaise(bool)
name|obj1
operator|.
name|setAutoRaise
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|false
argument_list|,
name|obj1
operator|.
name|autoRaise
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setAutoRaise
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|true
argument_list|,
name|obj1
operator|.
name|autoRaise
argument_list|()
argument_list|)
expr_stmt|;
comment|// QAction * QToolButton::defaultAction()
comment|// void QToolButton::setDefaultAction(QAction *)
name|QAction
modifier|*
name|var4
init|=
operator|new
name|QAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|obj1
operator|.
name|setDefaultAction
argument_list|(
name|var4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|var4
argument_list|,
name|obj1
operator|.
name|defaultAction
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setDefaultAction
argument_list|(
operator|(
name|QAction
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QAction
operator|*
operator|)
literal|0
argument_list|,
name|obj1
operator|.
name|defaultAction
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|var4
expr_stmt|;
block|}
end_function
begin_function
DECL|function|triggered
name|void
name|tst_QToolButton
operator|::
name|triggered
parameter_list|()
block|{
name|qRegisterMetaType
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
literal|"QAction *"
argument_list|)
expr_stmt|;
name|QWidget
name|mainWidget
decl_stmt|;
name|mainWidget
operator|.
name|setWindowTitle
argument_list|(
name|QStringLiteral
argument_list|(
literal|"triggered"
argument_list|)
argument_list|)
expr_stmt|;
name|mainWidget
operator|.
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|mainWidget
operator|.
name|move
argument_list|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
operator|.
name|center
argument_list|()
operator|-
name|QPoint
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|QToolButton
modifier|*
name|toolButton
init|=
operator|new
name|QToolButton
argument_list|(
operator|&
name|mainWidget
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spy
argument_list|(
name|toolButton
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|QAction
operator|*
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QScopedPointer
argument_list|<
name|QMenu
argument_list|>
name|menu
argument_list|(
operator|new
name|QMenu
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Menu"
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|one
init|=
name|menu
operator|->
name|addAction
argument_list|(
literal|"one"
argument_list|)
decl_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
literal|"two"
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|defaultAction
init|=
operator|new
name|QAction
argument_list|(
name|QStringLiteral
argument_list|(
literal|"def"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|toolButton
operator|->
name|setMenu
argument_list|(
name|menu
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|toolButton
operator|->
name|setDefaultAction
argument_list|(
name|defaultAction
argument_list|)
expr_stmt|;
name|mainWidget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|setActiveWindow
argument_list|(
operator|&
name|mainWidget
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowActive
argument_list|(
operator|&
name|mainWidget
argument_list|)
argument_list|)
expr_stmt|;
name|defaultAction
operator|->
name|trigger
argument_list|()
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
name|QCOMPARE
argument_list|(
name|qvariant_cast
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|spy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
argument_list|,
name|defaultAction
argument_list|)
expr_stmt|;
name|m_menu
operator|=
name|menu
operator|.
name|data
argument_list|()
expr_stmt|;
name|QTimer
modifier|*
name|timer
init|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|timer
operator|->
name|setInterval
argument_list|(
literal|50
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
name|sendMouseClick
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|->
name|start
argument_list|()
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|10000
argument_list|,
operator|&
name|mainWidget
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// Emergency bail-out
name|toolButton
operator|->
name|showMenu
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qvariant_cast
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|spy
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
argument_list|,
name|one
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|collapseTextOnPriority
name|void
name|tst_QToolButton
operator|::
name|collapseTextOnPriority
parameter_list|()
block|{
class|class
name|MyToolButton
super|:
specifier|public
name|QToolButton
block|{
friend|friend
class_decl|class
name|tst_QToolButton
class_decl|;
public|public:
name|void
name|initStyleOption
parameter_list|(
name|QStyleOptionToolButton
modifier|*
name|option
parameter_list|)
block|{
name|QToolButton
operator|::
name|initStyleOption
argument_list|(
name|option
argument_list|)
expr_stmt|;
block|}
block|}
class|;
name|MyToolButton
name|button
decl_stmt|;
name|button
operator|.
name|setToolButtonStyle
argument_list|(
name|Qt
operator|::
name|ToolButtonTextBesideIcon
argument_list|)
expr_stmt|;
name|QAction
name|action
argument_list|(
name|button
operator|.
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|SP_ArrowBack
argument_list|)
argument_list|,
literal|"test"
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|button
operator|.
name|setDefaultAction
argument_list|(
operator|&
name|action
argument_list|)
expr_stmt|;
name|QStyleOptionToolButton
name|option
decl_stmt|;
name|button
operator|.
name|initStyleOption
argument_list|(
operator|&
name|option
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|option
operator|.
name|toolButtonStyle
operator|==
name|Qt
operator|::
name|ToolButtonTextBesideIcon
argument_list|)
expr_stmt|;
name|action
operator|.
name|setPriority
argument_list|(
name|QAction
operator|::
name|LowPriority
argument_list|)
expr_stmt|;
name|button
operator|.
name|initStyleOption
argument_list|(
operator|&
name|option
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|option
operator|.
name|toolButtonStyle
operator|==
name|Qt
operator|::
name|ToolButtonIconOnly
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task230994_iconSize
name|void
name|tst_QToolButton
operator|::
name|task230994_iconSize
parameter_list|()
block|{
comment|//we check that the iconsize returned bu initStyleOption is valid
comment|//when the toolbutton has no parent
class|class
name|MyToolButton
super|:
specifier|public
name|QToolButton
block|{
friend|friend
class_decl|class
name|tst_QToolButton
class_decl|;
public|public:
name|void
name|initStyleOption
parameter_list|(
name|QStyleOptionToolButton
modifier|*
name|option
parameter_list|)
block|{
name|QToolButton
operator|::
name|initStyleOption
argument_list|(
name|option
argument_list|)
expr_stmt|;
block|}
block|}
class|;
name|MyToolButton
name|button
decl_stmt|;
name|QStyleOptionToolButton
name|option
decl_stmt|;
name|button
operator|.
name|initStyleOption
argument_list|(
operator|&
name|option
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|option
operator|.
name|iconSize
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task176137_autoRepeatOfAction
name|void
name|tst_QToolButton
operator|::
name|task176137_autoRepeatOfAction
parameter_list|()
block|{
name|QAction
name|action
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QWidget
name|mainWidget
decl_stmt|;
name|mainWidget
operator|.
name|setWindowTitle
argument_list|(
name|QStringLiteral
argument_list|(
literal|"task176137_autoRepeatOfAction"
argument_list|)
argument_list|)
expr_stmt|;
name|mainWidget
operator|.
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|mainWidget
operator|.
name|move
argument_list|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
operator|.
name|center
argument_list|()
operator|-
name|QPoint
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|QToolButton
modifier|*
name|toolButton
init|=
operator|new
name|QToolButton
argument_list|(
operator|&
name|mainWidget
argument_list|)
decl_stmt|;
name|toolButton
operator|->
name|setDefaultAction
argument_list|(
operator|&
name|action
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
name|QStringLiteral
argument_list|(
literal|"This test takes a while."
argument_list|)
argument_list|,
operator|&
name|mainWidget
argument_list|)
decl_stmt|;
name|label
operator|->
name|move
argument_list|(
literal|0
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|mainWidget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|setActiveWindow
argument_list|(
operator|&
name|mainWidget
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowActive
argument_list|(
operator|&
name|mainWidget
argument_list|)
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|action
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|mousePress
argument_list|(
name|toolButton
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|mouseRelease
argument_list|(
name|toolButton
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
literal|0
argument_list|,
name|QPoint
argument_list|()
argument_list|,
literal|2000
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
comment|// try again with auto repeat
name|toolButton
operator|->
name|setAutoRepeat
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QSignalSpy
name|repeatSpy
argument_list|(
operator|&
name|action
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
comment|// new spy
name|QTest
operator|::
name|mousePress
argument_list|(
name|toolButton
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|mouseRelease
argument_list|(
name|toolButton
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
literal|0
argument_list|,
name|QPoint
argument_list|()
argument_list|,
literal|3000
argument_list|)
expr_stmt|;
specifier|const
name|qreal
name|expected
init|=
operator|(
literal|3000
operator|-
name|toolButton
operator|->
name|autoRepeatDelay
argument_list|()
operator|)
operator|/
name|toolButton
operator|->
name|autoRepeatInterval
argument_list|()
operator|+
literal|1
decl_stmt|;
comment|//we check that the difference is small (on some systems timers are not super accurate)
name|qreal
name|diff
init|=
operator|(
name|expected
operator|-
name|repeatSpy
operator|.
name|count
argument_list|()
operator|)
operator|/
name|expected
decl_stmt|;
name|QVERIFY2
argument_list|(
name|qAbs
argument_list|(
name|diff
argument_list|)
operator|<
literal|0.2
argument_list|,
name|qPrintable
argument_list|(
name|QString
argument_list|(
literal|"expected: %1, actual: %2, diff (fraction): %3"
argument_list|)
operator|.
name|arg
argument_list|(
name|expected
argument_list|)
operator|.
name|arg
argument_list|(
name|repeatSpy
operator|.
name|count
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|diff
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sendMouseClick
name|void
name|tst_QToolButton
operator|::
name|sendMouseClick
parameter_list|()
block|{
if|if
condition|(
name|m_menu
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"m_menu is NULL"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|m_menu
operator|->
name|isVisible
argument_list|()
condition|)
return|return;
name|QTest
operator|::
name|mouseClick
argument_list|(
name|m_menu
operator|.
name|data
argument_list|()
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
literal|0
argument_list|,
name|QPoint
argument_list|(
literal|7
argument_list|,
literal|7
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|QTimer
modifier|*
name|timer
init|=
name|qobject_cast
argument_list|<
name|QTimer
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
condition|)
block|{
name|timer
operator|->
name|stop
argument_list|()
expr_stmt|;
name|timer
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qtbug_26956_popupTimerDone
name|void
name|tst_QToolButton
operator|::
name|qtbug_26956_popupTimerDone
parameter_list|()
block|{
name|QToolButton
modifier|*
name|tb
init|=
operator|new
name|QToolButton
decl_stmt|;
name|tb
operator|->
name|setMenu
argument_list|(
operator|new
name|QMenu
argument_list|(
name|tb
argument_list|)
argument_list|)
expr_stmt|;
name|tb
operator|->
name|menu
argument_list|()
operator|->
name|addAction
argument_list|(
literal|"Qt"
argument_list|)
expr_stmt|;
name|tb
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|tb
operator|->
name|showMenu
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qtbug_34759_sizeHintResetWhenSettingMenu
name|void
name|tst_QToolButton
operator|::
name|qtbug_34759_sizeHintResetWhenSettingMenu
parameter_list|()
block|{
comment|// There is no reliable way of checking what's ultimately a style-dependent
comment|// sizing. So the idea is checking if the size is the "correct" size w.r.t.
comment|// another toolbutton which has had a menu set before it was shown for the first time
name|QToolButton
name|button1
decl_stmt|;
name|QToolButton
name|button2
decl_stmt|;
name|button1
operator|.
name|setToolButtonStyle
argument_list|(
name|Qt
operator|::
name|ToolButtonIconOnly
argument_list|)
expr_stmt|;
name|button1
operator|.
name|setPopupMode
argument_list|(
name|QToolButton
operator|::
name|MenuButtonPopup
argument_list|)
expr_stmt|;
name|button2
operator|.
name|setToolButtonStyle
argument_list|(
name|Qt
operator|::
name|ToolButtonIconOnly
argument_list|)
expr_stmt|;
name|button2
operator|.
name|setPopupMode
argument_list|(
name|QToolButton
operator|::
name|MenuButtonPopup
argument_list|)
expr_stmt|;
name|button2
operator|.
name|setMenu
argument_list|(
operator|new
name|QMenu
argument_list|(
operator|&
name|button2
argument_list|)
argument_list|)
expr_stmt|;
name|button1
operator|.
name|show
argument_list|()
expr_stmt|;
name|button2
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|button1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|button2
argument_list|)
argument_list|)
expr_stmt|;
name|button1
operator|.
name|setMenu
argument_list|(
operator|new
name|QMenu
argument_list|(
operator|&
name|button1
argument_list|)
argument_list|)
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|button1
operator|.
name|sizeHint
argument_list|()
argument_list|,
name|button2
operator|.
name|sizeHint
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QToolButton
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtoolbutton.moc"
end_include
end_unit
