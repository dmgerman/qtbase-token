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
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qaction.h>
end_include
begin_include
include|#
directive|include
file|<qmenu.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_class
DECL|class|tst_QAction
class|class
name|tst_QAction
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QAction
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QAction
parameter_list|()
destructor_decl|;
name|void
name|updateState
parameter_list|(
name|QActionEvent
modifier|*
name|e
parameter_list|)
function_decl|;
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
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|setText_data
parameter_list|()
function_decl|;
name|void
name|setText
parameter_list|()
function_decl|;
DECL|function|setIconText_data
name|void
name|setIconText_data
parameter_list|()
block|{
name|setText_data
argument_list|()
expr_stmt|;
block|}
name|void
name|setIconText
parameter_list|()
function_decl|;
name|void
name|setUnknownFont
parameter_list|()
function_decl|;
name|void
name|actionEvent
parameter_list|()
function_decl|;
name|void
name|setStandardKeys
parameter_list|()
function_decl|;
name|void
name|alternateShortcuts
parameter_list|()
function_decl|;
name|void
name|enabledVisibleInteraction
parameter_list|()
function_decl|;
name|void
name|task200823_tooltip
parameter_list|()
function_decl|;
name|void
name|task229128TriggeredSignalWithoutActiongroup
parameter_list|()
function_decl|;
name|void
name|task229128TriggeredSignalWhenInActiongroup
parameter_list|()
function_decl|;
name|void
name|repeat
parameter_list|()
function_decl|;
private|private:
DECL|member|m_lastEventType
name|int
name|m_lastEventType
decl_stmt|;
DECL|member|m_keyboardScheme
name|int
name|m_keyboardScheme
decl_stmt|;
DECL|member|m_lastAction
name|QAction
modifier|*
name|m_lastAction
decl_stmt|;
DECL|member|m_tstWidget
name|QWidget
modifier|*
name|m_tstWidget
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QAction
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QAction
name|obj1
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|// QActionGroup * QAction::actionGroup()
comment|// void QAction::setActionGroup(QActionGroup *)
name|QActionGroup
modifier|*
name|var1
init|=
operator|new
name|QActionGroup
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|obj1
operator|.
name|setActionGroup
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
name|actionGroup
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setActionGroup
argument_list|(
operator|(
name|QActionGroup
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QActionGroup
operator|*
operator|)
literal|0
argument_list|,
name|obj1
operator|.
name|actionGroup
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|var1
expr_stmt|;
comment|// QMenu * QAction::menu()
comment|// void QAction::setMenu(QMenu *)
name|QMenu
modifier|*
name|var2
init|=
operator|new
name|QMenu
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|obj1
operator|.
name|setMenu
argument_list|(
name|var2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|var2
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
name|var2
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|priority
argument_list|()
argument_list|,
name|QAction
operator|::
name|NormalPriority
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setPriority
argument_list|(
name|QAction
operator|::
name|LowPriority
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|priority
argument_list|()
argument_list|,
name|QAction
operator|::
name|LowPriority
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|MyWidget
class|class
name|MyWidget
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
DECL|function|MyWidget
name|MyWidget
parameter_list|(
name|tst_QAction
modifier|*
name|tst
parameter_list|,
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|this
operator|->
name|tst
operator|=
name|tst
expr_stmt|;
block|}
protected|protected:
DECL|function|actionEvent
specifier|virtual
name|void
name|actionEvent
parameter_list|(
name|QActionEvent
modifier|*
name|e
parameter_list|)
block|{
name|tst
operator|->
name|updateState
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|tst
name|tst_QAction
modifier|*
name|tst
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QAction
name|tst_QAction
operator|::
name|tst_QAction
parameter_list|()
member_init_list|:
name|m_keyboardScheme
argument_list|(
name|QPlatformTheme
operator|::
name|WindowsKeyboardScheme
argument_list|)
block|{
if|if
condition|(
specifier|const
name|QPlatformTheme
modifier|*
name|theme
init|=
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
condition|)
name|m_keyboardScheme
operator|=
name|theme
operator|->
name|themeHint
argument_list|(
name|QPlatformTheme
operator|::
name|KeyboardScheme
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~tst_QAction
name|tst_QAction
operator|::
name|~
name|tst_QAction
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QAction
operator|::
name|initTestCase
parameter_list|()
block|{
name|m_lastEventType
operator|=
literal|0
expr_stmt|;
name|m_lastAction
operator|=
literal|0
expr_stmt|;
name|MyWidget
modifier|*
name|mw
init|=
operator|new
name|MyWidget
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|m_tstWidget
operator|=
name|mw
expr_stmt|;
name|mw
operator|->
name|show
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|setActiveWindow
argument_list|(
name|mw
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QAction
operator|::
name|cleanupTestCase
parameter_list|()
block|{
name|QWidget
modifier|*
name|testWidget
init|=
name|m_tstWidget
decl_stmt|;
if|if
condition|(
name|testWidget
condition|)
block|{
name|testWidget
operator|->
name|hide
argument_list|()
expr_stmt|;
operator|delete
name|testWidget
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setText_data
name|void
name|tst_QAction
operator|::
name|setText_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"text"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"iconText"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"textFromIconText"
argument_list|)
expr_stmt|;
comment|//next we fill it with data
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Normal"
argument_list|)
operator|<<
literal|"Action"
operator|<<
literal|"Action"
operator|<<
literal|"Action"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Ampersand"
argument_list|)
operator|<<
literal|"Search&& Destroy"
operator|<<
literal|"Search& Destroy"
operator|<<
literal|"Search&& Destroy"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Mnemonic and ellipsis"
argument_list|)
operator|<<
literal|"O&pen File ..."
operator|<<
literal|"Open File"
operator|<<
literal|"Open File"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setText
name|void
name|tst_QAction
operator|::
name|setText
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|QAction
name|action
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|action
operator|.
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|action
operator|.
name|text
argument_list|()
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|iconText
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|action
operator|.
name|iconText
argument_list|()
argument_list|,
name|iconText
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setIconText
name|void
name|tst_QAction
operator|::
name|setIconText
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|iconText
argument_list|)
expr_stmt|;
name|QAction
name|action
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|action
operator|.
name|setIconText
argument_list|(
name|iconText
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|action
operator|.
name|iconText
argument_list|()
argument_list|,
name|iconText
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|textFromIconText
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|action
operator|.
name|text
argument_list|()
argument_list|,
name|textFromIconText
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setUnknownFont
name|void
name|tst_QAction
operator|::
name|setUnknownFont
parameter_list|()
comment|// QTBUG-42728
block|{
name|QAction
name|action
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QFont
name|font
argument_list|(
literal|"DoesNotExist"
argument_list|,
literal|11
argument_list|)
decl_stmt|;
name|action
operator|.
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|QMenu
name|menu
decl_stmt|;
name|menu
operator|.
name|addAction
argument_list|(
operator|&
name|action
argument_list|)
expr_stmt|;
comment|// should not crash
block|}
end_function
begin_function
DECL|function|updateState
name|void
name|tst_QAction
operator|::
name|updateState
parameter_list|(
name|QActionEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
operator|!
name|e
condition|)
block|{
name|m_lastEventType
operator|=
literal|0
expr_stmt|;
name|m_lastAction
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|m_lastEventType
operator|=
operator|(
name|int
operator|)
name|e
operator|->
name|type
argument_list|()
expr_stmt|;
name|m_lastAction
operator|=
name|e
operator|->
name|action
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|actionEvent
name|void
name|tst_QAction
operator|::
name|actionEvent
parameter_list|()
block|{
name|QAction
name|a
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|a
operator|.
name|setText
argument_list|(
literal|"action text"
argument_list|)
expr_stmt|;
comment|// add action
name|m_tstWidget
operator|->
name|addAction
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_lastEventType
argument_list|,
operator|(
name|int
operator|)
name|QEvent
operator|::
name|ActionAdded
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_lastAction
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
comment|// change action
name|a
operator|.
name|setText
argument_list|(
literal|"new action text"
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_lastEventType
argument_list|,
operator|(
name|int
operator|)
name|QEvent
operator|::
name|ActionChanged
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_lastAction
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
comment|// remove action
name|m_tstWidget
operator|->
name|removeAction
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_lastEventType
argument_list|,
operator|(
name|int
operator|)
name|QEvent
operator|::
name|ActionRemoved
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_lastAction
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//basic testing of standard keys
end_comment
begin_function
DECL|function|setStandardKeys
name|void
name|tst_QAction
operator|::
name|setStandardKeys
parameter_list|()
block|{
name|QAction
name|act
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|act
operator|.
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
literal|"CTRL+L"
argument_list|)
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QKeySequence
argument_list|>
name|list
decl_stmt|;
name|act
operator|.
name|setShortcuts
argument_list|(
name|list
argument_list|)
expr_stmt|;
name|act
operator|.
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Copy
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|act
operator|.
name|shortcut
argument_list|()
argument_list|,
name|act
operator|.
name|shortcuts
argument_list|()
operator|.
name|first
argument_list|()
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QKeySequence
argument_list|>
name|expected
decl_stmt|;
specifier|const
name|QKeySequence
name|ctrlC
init|=
name|QKeySequence
argument_list|(
name|QStringLiteral
argument_list|(
literal|"CTRL+C"
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QKeySequence
name|ctrlInsert
init|=
name|QKeySequence
argument_list|(
name|QStringLiteral
argument_list|(
literal|"CTRL+INSERT"
argument_list|)
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|m_keyboardScheme
condition|)
block|{
case|case
name|QPlatformTheme
operator|::
name|MacKeyboardScheme
case|:
name|expected
operator|<<
name|ctrlC
expr_stmt|;
break|break;
case|case
name|QPlatformTheme
operator|::
name|WindowsKeyboardScheme
case|:
name|expected
operator|<<
name|ctrlC
operator|<<
name|ctrlInsert
expr_stmt|;
break|break;
default|default:
comment|// X11
name|expected
operator|<<
name|ctrlC
operator|<<
name|QKeySequence
argument_list|(
name|QStringLiteral
argument_list|(
literal|"F16"
argument_list|)
argument_list|)
operator|<<
name|ctrlInsert
expr_stmt|;
break|break;
block|}
name|QCOMPARE
argument_list|(
name|act
operator|.
name|shortcuts
argument_list|()
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|alternateShortcuts
name|void
name|tst_QAction
operator|::
name|alternateShortcuts
parameter_list|()
block|{
comment|//test the alternate shortcuts (by adding more than 1 shortcut)
name|QWidget
modifier|*
name|wid
init|=
name|m_tstWidget
decl_stmt|;
block|{
name|QAction
name|act
argument_list|(
name|wid
argument_list|)
decl_stmt|;
name|wid
operator|->
name|addAction
argument_list|(
operator|&
name|act
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QKeySequence
argument_list|>
name|shlist
init|=
name|QList
argument_list|<
name|QKeySequence
argument_list|>
argument_list|()
operator|<<
name|QKeySequence
argument_list|(
literal|"CTRL+P"
argument_list|)
operator|<<
name|QKeySequence
argument_list|(
literal|"CTRL+A"
argument_list|)
decl_stmt|;
name|act
operator|.
name|setShortcuts
argument_list|(
name|shlist
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|act
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|act
operator|.
name|setAutoRepeat
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|wid
argument_list|,
name|Qt
operator|::
name|Key_A
argument_list|,
name|Qt
operator|::
name|ControlModifier
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
comment|//act should have been triggered
name|act
operator|.
name|setAutoRepeat
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|wid
argument_list|,
name|Qt
operator|::
name|Key_A
argument_list|,
name|Qt
operator|::
name|ControlModifier
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
comment|//act should have been triggered a 2nd time
comment|//end of the scope of the action, it will be destroyed and removed from wid
comment|//This action should also unregister its shortcuts
block|}
comment|//this tests a crash (if the action did not unregister its alternate shortcuts)
name|QTest
operator|::
name|keyClick
argument_list|(
name|wid
argument_list|,
name|Qt
operator|::
name|Key_A
argument_list|,
name|Qt
operator|::
name|ControlModifier
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enabledVisibleInteraction
name|void
name|tst_QAction
operator|::
name|enabledVisibleInteraction
parameter_list|()
block|{
name|QAction
name|act
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|// check defaults
name|QVERIFY
argument_list|(
name|act
operator|.
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|act
operator|.
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
comment|// !visible => !enabled
name|act
operator|.
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|act
operator|.
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|act
operator|.
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|act
operator|.
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|act
operator|.
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|act
operator|.
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
comment|// check if shortcut is disabled if not visible
name|m_tstWidget
operator|->
name|addAction
argument_list|(
operator|&
name|act
argument_list|)
expr_stmt|;
name|act
operator|.
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
literal|"Ctrl+T"
argument_list|)
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|act
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|act
operator|.
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|act
operator|.
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|m_tstWidget
argument_list|,
name|Qt
operator|::
name|Key_T
argument_list|,
name|Qt
operator|::
name|ControlModifier
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
comment|//act is not visible, so don't trigger
name|act
operator|.
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|act
operator|.
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|m_tstWidget
argument_list|,
name|Qt
operator|::
name|Key_T
argument_list|,
name|Qt
operator|::
name|ControlModifier
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
comment|//act is not visible, so don't trigger
name|act
operator|.
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|act
operator|.
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|m_tstWidget
argument_list|,
name|Qt
operator|::
name|Key_T
argument_list|,
name|Qt
operator|::
name|ControlModifier
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
comment|//act is visible and enabled, so trigger
block|}
end_function
begin_function
DECL|function|task200823_tooltip
name|void
name|tst_QAction
operator|::
name|task200823_tooltip
parameter_list|()
block|{
name|QAction
modifier|*
name|action
init|=
operator|new
name|QAction
argument_list|(
literal|"foo"
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QString
name|shortcut
argument_list|(
literal|"ctrl+o"
argument_list|)
decl_stmt|;
name|action
operator|->
name|setShortcut
argument_list|(
name|shortcut
argument_list|)
expr_stmt|;
comment|// we want a non-standard tooltip that shows the shortcut
name|action
operator|->
name|setToolTip
argument_list|(
name|action
operator|->
name|text
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|" ("
argument_list|)
operator|+
name|action
operator|->
name|shortcut
argument_list|()
operator|.
name|toString
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
argument_list|)
expr_stmt|;
name|QString
name|ref
init|=
name|QLatin1String
argument_list|(
literal|"foo ("
argument_list|)
operator|+
name|QKeySequence
argument_list|(
name|shortcut
argument_list|)
operator|.
name|toString
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|action
operator|->
name|toolTip
argument_list|()
argument_list|,
name|ref
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task229128TriggeredSignalWithoutActiongroup
name|void
name|tst_QAction
operator|::
name|task229128TriggeredSignalWithoutActiongroup
parameter_list|()
block|{
comment|// test without a group
name|QAction
modifier|*
name|actionWithoutGroup
init|=
operator|new
name|QAction
argument_list|(
literal|"Test"
argument_list|,
name|qApp
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spyWithoutGroup
argument_list|(
name|actionWithoutGroup
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|spyWithoutGroup
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|actionWithoutGroup
operator|->
name|trigger
argument_list|()
expr_stmt|;
comment|// signal should be emitted
name|QCOMPARE
argument_list|(
name|spyWithoutGroup
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// it is now a checkable checked action
name|actionWithoutGroup
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|actionWithoutGroup
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|spyWithoutGroup
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyWithoutGroup
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|actionWithoutGroup
operator|->
name|trigger
argument_list|()
expr_stmt|;
comment|// signal should be emitted
name|QCOMPARE
argument_list|(
name|spyWithoutGroup
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task229128TriggeredSignalWhenInActiongroup
name|void
name|tst_QAction
operator|::
name|task229128TriggeredSignalWhenInActiongroup
parameter_list|()
block|{
name|QActionGroup
name|ag
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|action
init|=
operator|new
name|QAction
argument_list|(
literal|"Test"
argument_list|,
operator|&
name|ag
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|checkedAction
init|=
operator|new
name|QAction
argument_list|(
literal|"Test 2"
argument_list|,
operator|&
name|ag
argument_list|)
decl_stmt|;
name|ag
operator|.
name|addAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|action
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|ag
operator|.
name|addAction
argument_list|(
name|checkedAction
argument_list|)
expr_stmt|;
name|checkedAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|checkedAction
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QSignalSpy
name|actionSpy
argument_list|(
name|checkedAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|actionGroupSpy
argument_list|(
operator|&
name|ag
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
name|QCOMPARE
argument_list|(
name|actionGroupSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|actionSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|checkedAction
operator|->
name|trigger
argument_list|()
expr_stmt|;
comment|// check that both the group and the action have emitted the signal
name|QCOMPARE
argument_list|(
name|actionGroupSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|actionSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|repeat
name|void
name|tst_QAction
operator|::
name|repeat
parameter_list|()
block|{
name|QWidget
modifier|*
name|wid
init|=
name|m_tstWidget
decl_stmt|;
name|QAction
name|act
argument_list|(
name|wid
argument_list|)
decl_stmt|;
name|wid
operator|->
name|addAction
argument_list|(
operator|&
name|act
argument_list|)
expr_stmt|;
name|act
operator|.
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
name|Qt
operator|::
name|Key_F
argument_list|)
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|act
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|act
operator|.
name|setAutoRepeat
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyPress
argument_list|(
name|wid
argument_list|,
name|Qt
operator|::
name|Key_F
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyRelease
argument_list|(
name|wid
argument_list|,
name|Qt
operator|::
name|Key_F
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
name|spy
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|keyPress
argument_list|(
name|wid
argument_list|,
name|Qt
operator|::
name|Key_F
argument_list|)
expr_stmt|;
comment|// repeat event
name|QTest
operator|::
name|simulateEvent
argument_list|(
name|wid
argument_list|,
literal|true
argument_list|,
name|Qt
operator|::
name|Key_F
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|,
name|QString
argument_list|(
literal|"f"
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|simulateEvent
argument_list|(
name|wid
argument_list|,
literal|true
argument_list|,
name|Qt
operator|::
name|Key_F
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|,
name|QString
argument_list|(
literal|"f"
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyRelease
argument_list|(
name|wid
argument_list|,
name|Qt
operator|::
name|Key_F
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|spy
operator|.
name|clear
argument_list|()
expr_stmt|;
name|act
operator|.
name|setAutoRepeat
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyPress
argument_list|(
name|wid
argument_list|,
name|Qt
operator|::
name|Key_F
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|simulateEvent
argument_list|(
name|wid
argument_list|,
literal|true
argument_list|,
name|Qt
operator|::
name|Key_F
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|,
name|QString
argument_list|(
literal|"f"
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|simulateEvent
argument_list|(
name|wid
argument_list|,
literal|true
argument_list|,
name|Qt
operator|::
name|Key_F
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|,
name|QString
argument_list|(
literal|"f"
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyRelease
argument_list|(
name|wid
argument_list|,
name|Qt
operator|::
name|Key_F
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
name|spy
operator|.
name|clear
argument_list|()
expr_stmt|;
name|act
operator|.
name|setAutoRepeat
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyPress
argument_list|(
name|wid
argument_list|,
name|Qt
operator|::
name|Key_F
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|simulateEvent
argument_list|(
name|wid
argument_list|,
literal|true
argument_list|,
name|Qt
operator|::
name|Key_F
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|,
name|QString
argument_list|(
literal|"f"
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyRelease
argument_list|(
name|wid
argument_list|,
name|Qt
operator|::
name|Key_F
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
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QAction
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qaction.moc"
end_include
end_unit
