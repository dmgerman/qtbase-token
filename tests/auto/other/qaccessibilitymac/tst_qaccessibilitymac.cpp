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
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|"tst_qaccessibilitymac_helpers.h"
end_include
begin_macro
name|QT_USE_NAMESPACE
end_macro
begin_class
DECL|class|AccessibleTestWindow
class|class
name|AccessibleTestWindow
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
DECL|function|AccessibleTestWindow
name|AccessibleTestWindow
parameter_list|()
block|{
operator|new
name|QHBoxLayout
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
DECL|function|addWidget
name|void
name|addWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|layout
argument_list|()
operator|->
name|addWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|widget
operator|->
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
DECL|function|clearChildren
name|void
name|clearChildren
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|children
argument_list|()
argument_list|)
expr_stmt|;
operator|new
name|QHBoxLayout
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|tst_QAccessibilityMac
class|class
name|tst_QAccessibilityMac
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|singleWidgetTest
parameter_list|()
function_decl|;
name|void
name|lineEditTest
parameter_list|()
function_decl|;
name|void
name|hierarchyTest
parameter_list|()
function_decl|;
name|void
name|notificationsTest
parameter_list|()
function_decl|;
name|void
name|checkBoxTest
parameter_list|()
function_decl|;
private|private:
DECL|member|m_window
name|AccessibleTestWindow
modifier|*
name|m_window
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|init
name|void
name|tst_QAccessibilityMac
operator|::
name|init
parameter_list|()
block|{
name|m_window
operator|=
operator|new
name|AccessibleTestWindow
argument_list|()
expr_stmt|;
name|m_window
operator|->
name|setWindowTitle
argument_list|(
literal|"Test window"
argument_list|)
expr_stmt|;
name|m_window
operator|->
name|show
argument_list|()
expr_stmt|;
name|m_window
operator|->
name|resize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|m_window
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QAccessibilityMac
operator|::
name|cleanup
parameter_list|()
block|{
operator|delete
name|m_window
expr_stmt|;
block|}
end_function
begin_function
DECL|function|singleWidgetTest
name|void
name|tst_QAccessibilityMac
operator|::
name|singleWidgetTest
parameter_list|()
block|{
if|if
condition|(
operator|!
name|macNativeAccessibilityEnabled
argument_list|()
condition|)
return|return;
operator|delete
name|m_window
expr_stmt|;
name|m_window
operator|=
literal|0
expr_stmt|;
name|QVERIFY
argument_list|(
name|singleWidget
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lineEditTest
name|void
name|tst_QAccessibilityMac
operator|::
name|lineEditTest
parameter_list|()
block|{
if|if
condition|(
operator|!
name|macNativeAccessibilityEnabled
argument_list|()
condition|)
return|return;
name|QLineEdit
modifier|*
name|lineEdit
init|=
operator|new
name|QLineEdit
argument_list|(
name|m_window
argument_list|)
decl_stmt|;
name|lineEdit
operator|->
name|setText
argument_list|(
literal|"a11y test QLineEdit"
argument_list|)
expr_stmt|;
name|m_window
operator|->
name|addWidget
argument_list|(
name|lineEdit
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|m_window
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|testLineEdit
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hierarchyTest
name|void
name|tst_QAccessibilityMac
operator|::
name|hierarchyTest
parameter_list|()
block|{
if|if
condition|(
operator|!
name|macNativeAccessibilityEnabled
argument_list|()
condition|)
return|return;
name|QWidget
modifier|*
name|w
init|=
operator|new
name|QWidget
argument_list|(
name|m_window
argument_list|)
decl_stmt|;
name|m_window
operator|->
name|addWidget
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|w
operator|->
name|setLayout
argument_list|(
operator|new
name|QVBoxLayout
argument_list|()
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|b
init|=
operator|new
name|QPushButton
argument_list|(
name|w
argument_list|)
decl_stmt|;
name|w
operator|->
name|layout
argument_list|()
operator|->
name|addWidget
argument_list|(
name|b
argument_list|)
expr_stmt|;
name|b
operator|->
name|setText
argument_list|(
literal|"I am a button"
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|b2
init|=
operator|new
name|QPushButton
argument_list|(
name|w
argument_list|)
decl_stmt|;
name|w
operator|->
name|layout
argument_list|()
operator|->
name|addWidget
argument_list|(
name|b2
argument_list|)
expr_stmt|;
name|b2
operator|->
name|setText
argument_list|(
literal|"Button 2"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|m_window
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|testHierarchy
argument_list|(
name|w
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|notificationsTest
name|void
name|tst_QAccessibilityMac
operator|::
name|notificationsTest
parameter_list|()
block|{
if|if
condition|(
operator|!
name|macNativeAccessibilityEnabled
argument_list|()
condition|)
return|return;
name|QVERIFY
argument_list|(
name|notifications
argument_list|(
name|m_window
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkBoxTest
name|void
name|tst_QAccessibilityMac
operator|::
name|checkBoxTest
parameter_list|()
block|{
if|if
condition|(
operator|!
name|macNativeAccessibilityEnabled
argument_list|()
condition|)
return|return;
name|QCheckBox
modifier|*
name|cb
init|=
operator|new
name|QCheckBox
argument_list|(
name|m_window
argument_list|)
decl_stmt|;
name|cb
operator|->
name|setText
argument_list|(
literal|"Great option"
argument_list|)
expr_stmt|;
name|m_window
operator|->
name|addWidget
argument_list|(
name|cb
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|m_window
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|testCheckBox
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QAccessibilityMac
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qaccessibilitymac.moc"
end_include
end_unit
