begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qdialog.h"
end_include
begin_include
include|#
directive|include
file|"qpushbutton.h"
end_include
begin_include
include|#
directive|include
file|"qdialogbuttonbox.h"
end_include
begin_include
include|#
directive|include
file|"private/qsoftkeymanager_p.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_include
include|#
directive|include
file|"qsymbianevent.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_S60
end_ifdef
begin_decl_stmt
DECL|variable|s60CommandStart
specifier|static
specifier|const
name|int
name|s60CommandStart
init|=
literal|6000
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_QSoftKeyManager
class|class
name|tst_QSoftKeyManager
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QSoftKeyManager
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QSoftKeyManager
parameter_list|()
destructor_decl|;
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
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|updateSoftKeysCompressed
parameter_list|()
function_decl|;
name|void
name|handleCommand
parameter_list|()
function_decl|;
name|void
name|checkSoftkeyEnableStates
parameter_list|()
function_decl|;
name|void
name|noMergingOverWindowBoundary
parameter_list|()
function_decl|;
private|private:
comment|// utils
DECL|function|simulateSymbianCommand
specifier|inline
name|void
name|simulateSymbianCommand
parameter_list|(
name|int
name|command
parameter_list|)
block|{
name|QSymbianEvent
name|event1
argument_list|(
name|QSymbianEvent
operator|::
name|CommandEvent
argument_list|,
name|command
argument_list|)
decl_stmt|;
name|qApp
operator|->
name|symbianProcessEvent
argument_list|(
operator|&
name|event1
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|EventListener
class|class
name|EventListener
super|:
specifier|public
name|QObject
block|{
public|public:
DECL|function|EventListener
name|EventListener
parameter_list|(
name|QObject
modifier|*
name|listenTo
parameter_list|)
block|{
name|resetCounts
argument_list|()
expr_stmt|;
if|if
condition|(
name|listenTo
condition|)
name|listenTo
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
DECL|function|resetCounts
name|void
name|resetCounts
parameter_list|()
block|{
name|numUpdateSoftKeys
operator|=
literal|0
expr_stmt|;
block|}
DECL|member|numUpdateSoftKeys
name|int
name|numUpdateSoftKeys
decl_stmt|;
protected|protected:
DECL|function|eventFilter
name|bool
name|eventFilter
parameter_list|(
name|QObject
modifier|*
comment|/*object*/
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|UpdateSoftKeys
condition|)
name|numUpdateSoftKeys
operator|++
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QSoftKeyManager
name|tst_QSoftKeyManager
operator|::
name|tst_QSoftKeyManager
parameter_list|()
member_init_list|:
name|QObject
argument_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QSoftKeyManager
name|tst_QSoftKeyManager
operator|::
name|~
name|tst_QSoftKeyManager
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QSoftKeyManager
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QSoftKeyManager
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|init
name|void
name|tst_QSoftKeyManager
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QSoftKeyManager
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*     This tests that we only get one UpdateSoftKeys event even though     multiple events that trigger soft keys occur. */
end_comment
begin_function
DECL|function|updateSoftKeysCompressed
name|void
name|tst_QSoftKeyManager
operator|::
name|updateSoftKeysCompressed
parameter_list|()
block|{
name|QWidget
name|w
decl_stmt|;
name|EventListener
name|listener
argument_list|(
name|qApp
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QAction
modifier|*
argument_list|>
name|softKeys
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
operator|++
name|i
control|)
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
operator|&
name|w
argument_list|)
decl_stmt|;
name|action
operator|->
name|setSoftKeyRole
argument_list|(
name|QAction
operator|::
name|PositiveSoftKey
argument_list|)
expr_stmt|;
name|softKeys
operator|<<
name|action
expr_stmt|;
block|}
name|w
operator|.
name|addActions
argument_list|(
name|softKeys
argument_list|)
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|listener
operator|.
name|numUpdateSoftKeys
operator|==
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     This tests that when the S60 environment sends us a command     that it actually gets mapped to the correct action. */
end_comment
begin_function
DECL|function|handleCommand
name|void
name|tst_QSoftKeyManager
operator|::
name|handleCommand
parameter_list|()
block|{
name|QDialog
name|w
decl_stmt|;
name|QDialogButtonBox
modifier|*
name|buttons
init|=
operator|new
name|QDialogButtonBox
argument_list|(
name|QDialogButtonBox
operator|::
name|Ok
operator||
name|QDialogButtonBox
operator|::
name|Cancel
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
operator|&
name|w
argument_list|)
decl_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|.
name|actions
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy0
argument_list|(
name|w
operator|.
name|actions
argument_list|()
index|[
literal|0
index|]
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spy1
argument_list|(
name|w
operator|.
name|actions
argument_list|()
index|[
literal|1
index|]
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
comment|// These should work eventually, but do not yet
comment|//    QTest::keyPress(&w, Qt::Key_Context1);
comment|//    QTest::keyPress(&w, Qt::Key_Context2);
name|simulateSymbianCommand
argument_list|(
name|s60CommandStart
argument_list|)
expr_stmt|;
comment|//0 = LSK position
name|simulateSymbianCommand
argument_list|(
name|s60CommandStart
operator|+
literal|2
argument_list|)
expr_stmt|;
comment|//2 = RSK position
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy0
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy1
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     This tests that the state of a widget that owns softkey action is respected when handling the softkey     command. */
end_comment
begin_function
DECL|function|checkSoftkeyEnableStates
name|void
name|tst_QSoftKeyManager
operator|::
name|checkSoftkeyEnableStates
parameter_list|()
block|{
name|QDialog
name|w
decl_stmt|;
name|QDialogButtonBox
modifier|*
name|buttons
init|=
operator|new
name|QDialogButtonBox
argument_list|(
name|QDialogButtonBox
operator|::
name|RestoreDefaults
operator||
name|QDialogButtonBox
operator|::
name|Help
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
operator|&
name|w
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|pBDefaults
init|=
name|buttons
operator|->
name|button
argument_list|(
name|QDialogButtonBox
operator|::
name|RestoreDefaults
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|pBHelp
init|=
name|buttons
operator|->
name|button
argument_list|(
name|QDialogButtonBox
operator|::
name|Help
argument_list|)
decl_stmt|;
name|pBHelp
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
comment|//According to StandardButton enum in QDialogButtonBox the Help action
comment|//is inserted before RestoreDefaults and thus help action is in index 0
name|QSignalSpy
name|spy0
argument_list|(
name|w
operator|.
name|actions
argument_list|()
index|[
literal|0
index|]
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
comment|//disabled help action
name|QSignalSpy
name|spy1
argument_list|(
name|w
operator|.
name|actions
argument_list|()
index|[
literal|1
index|]
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
comment|//restore defaults action
comment|//Verify that enabled button gets all the action trigger signals and
comment|//disabled button gets none.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
block|{
comment|//simulate "help" softkey press
name|simulateSymbianCommand
argument_list|(
name|s60CommandStart
argument_list|)
expr_stmt|;
comment|//simulate "Restore Defaults" softkey press
name|simulateSymbianCommand
argument_list|(
name|s60CommandStart
operator|+
literal|2
argument_list|)
expr_stmt|;
block|}
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
comment|//Restore defaults button is enabled and its signals are recorded to spy1
name|QCOMPARE
argument_list|(
name|spy0
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy1
operator|.
name|count
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|spy0
operator|.
name|clear
argument_list|()
expr_stmt|;
name|spy1
operator|.
name|clear
argument_list|()
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
literal|10
condition|;
name|i
operator|++
control|)
block|{
comment|//simulate "help" softkey press
name|simulateSymbianCommand
argument_list|(
name|s60CommandStart
argument_list|)
expr_stmt|;
comment|//simulate "Restore Defaults" softkey press
name|simulateSymbianCommand
argument_list|(
name|s60CommandStart
operator|+
literal|2
argument_list|)
expr_stmt|;
comment|//switch enabled button to disabled and vice versa
name|pBHelp
operator|->
name|setEnabled
argument_list|(
operator|!
name|pBHelp
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|pBDefaults
operator|->
name|setEnabled
argument_list|(
operator|!
name|pBDefaults
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy0
operator|.
name|count
argument_list|()
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy1
operator|.
name|count
argument_list|()
argument_list|,
literal|5
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     This tests that the softkeys are not merged over window boundaries. I.e. dialogs     don't get softkeys of base widget by default - QTBUG-6163. */
end_comment
begin_function
DECL|function|noMergingOverWindowBoundary
name|void
name|tst_QSoftKeyManager
operator|::
name|noMergingOverWindowBoundary
parameter_list|()
block|{
comment|// Create base window against which the dialog softkeys will ve verified
name|QWidget
name|base
decl_stmt|;
name|QAction
modifier|*
name|baseLeft
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"BaseLeft"
argument_list|)
argument_list|,
operator|&
name|base
argument_list|)
decl_stmt|;
name|baseLeft
operator|->
name|setSoftKeyRole
argument_list|(
name|QAction
operator|::
name|PositiveSoftKey
argument_list|)
expr_stmt|;
name|base
operator|.
name|addAction
argument_list|(
name|baseLeft
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|baseRight
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"BaseRight"
argument_list|)
argument_list|,
operator|&
name|base
argument_list|)
decl_stmt|;
name|baseRight
operator|->
name|setSoftKeyRole
argument_list|(
name|QAction
operator|::
name|NegativeSoftKey
argument_list|)
expr_stmt|;
name|base
operator|.
name|addAction
argument_list|(
name|baseRight
argument_list|)
expr_stmt|;
name|base
operator|.
name|showMaximized
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QSignalSpy
name|baseLeftSpy
argument_list|(
name|baseLeft
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|baseRightSpy
argument_list|(
name|baseRight
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
comment|//Verify that both base softkeys emit triggered signals
name|simulateSymbianCommand
argument_list|(
name|s60CommandStart
argument_list|)
expr_stmt|;
name|simulateSymbianCommand
argument_list|(
name|s60CommandStart
operator|+
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|baseLeftSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|baseRightSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|baseLeftSpy
operator|.
name|clear
argument_list|()
expr_stmt|;
name|baseRightSpy
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// Verify that no softkey merging when using dialog without parent
name|QDialog
name|dlg
decl_stmt|;
name|dlg
operator|.
name|show
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|simulateSymbianCommand
argument_list|(
name|s60CommandStart
argument_list|)
expr_stmt|;
name|simulateSymbianCommand
argument_list|(
name|s60CommandStart
operator|+
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|baseLeftSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|baseRightSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// Ensure base view has focus again
name|dlg
operator|.
name|hide
argument_list|()
expr_stmt|;
name|base
operator|.
name|showMaximized
argument_list|()
expr_stmt|;
comment|// Verify that no softkey merging when using dialog with parent
name|QDialog
name|dlg2
argument_list|(
operator|&
name|base
argument_list|)
decl_stmt|;
name|dlg2
operator|.
name|show
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|simulateSymbianCommand
argument_list|(
name|s60CommandStart
argument_list|)
expr_stmt|;
name|simulateSymbianCommand
argument_list|(
name|s60CommandStart
operator|+
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|baseLeftSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|baseRightSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSoftKeyManager
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsoftkeymanager.moc"
end_include
end_unit
