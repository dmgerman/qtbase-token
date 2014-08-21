begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qmainwindow.h>
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
begin_class
DECL|class|tst_QActionGroup
class|class
name|tst_QActionGroup
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|enabledPropagation
parameter_list|()
function_decl|;
name|void
name|visiblePropagation
parameter_list|()
function_decl|;
name|void
name|exclusive
parameter_list|()
function_decl|;
name|void
name|separators
parameter_list|()
function_decl|;
name|void
name|testActionInTwoQActionGroup
parameter_list|()
function_decl|;
name|void
name|unCheckCurrentAction
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|enabledPropagation
name|void
name|tst_QActionGroup
operator|::
name|enabledPropagation
parameter_list|()
block|{
name|QActionGroup
name|testActionGroup
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|childAction
init|=
operator|new
name|QAction
argument_list|(
operator|&
name|testActionGroup
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|anotherChildAction
init|=
operator|new
name|QAction
argument_list|(
operator|&
name|testActionGroup
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|freeAction
init|=
operator|new
name|QAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|testActionGroup
operator|.
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childAction
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|testActionGroup
operator|.
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|testActionGroup
operator|.
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childAction
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|anotherChildAction
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|childAction
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childAction
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|anotherChildAction
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|testActionGroup
operator|.
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testActionGroup
operator|.
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childAction
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|anotherChildAction
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|testActionGroup
operator|.
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|lastChildAction
init|=
operator|new
name|QAction
argument_list|(
operator|&
name|testActionGroup
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|lastChildAction
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|testActionGroup
operator|.
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lastChildAction
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|freeAction
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|testActionGroup
operator|.
name|addAction
argument_list|(
name|freeAction
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|freeAction
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|freeAction
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visiblePropagation
name|void
name|tst_QActionGroup
operator|::
name|visiblePropagation
parameter_list|()
block|{
name|QActionGroup
name|testActionGroup
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|childAction
init|=
operator|new
name|QAction
argument_list|(
operator|&
name|testActionGroup
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|anotherChildAction
init|=
operator|new
name|QAction
argument_list|(
operator|&
name|testActionGroup
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|freeAction
init|=
operator|new
name|QAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|testActionGroup
operator|.
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childAction
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|testActionGroup
operator|.
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|testActionGroup
operator|.
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|childAction
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|anotherChildAction
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|anotherChildAction
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|testActionGroup
operator|.
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testActionGroup
operator|.
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|childAction
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|anotherChildAction
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|testActionGroup
operator|.
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|lastChildAction
init|=
operator|new
name|QAction
argument_list|(
operator|&
name|testActionGroup
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|lastChildAction
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|testActionGroup
operator|.
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lastChildAction
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|freeAction
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|testActionGroup
operator|.
name|addAction
argument_list|(
name|freeAction
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|freeAction
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|freeAction
expr_stmt|;
block|}
end_function
begin_function
DECL|function|exclusive
name|void
name|tst_QActionGroup
operator|::
name|exclusive
parameter_list|()
block|{
name|QActionGroup
name|group
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|group
operator|.
name|setExclusive
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|group
operator|.
name|isExclusive
argument_list|()
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|actOne
init|=
operator|new
name|QAction
argument_list|(
operator|&
name|group
argument_list|)
decl_stmt|;
name|actOne
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|actTwo
init|=
operator|new
name|QAction
argument_list|(
operator|&
name|group
argument_list|)
decl_stmt|;
name|actTwo
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|actThree
init|=
operator|new
name|QAction
argument_list|(
operator|&
name|group
argument_list|)
decl_stmt|;
name|actThree
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|group
operator|.
name|setExclusive
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|actOne
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|actTwo
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|actThree
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|actOne
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|actOne
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|actTwo
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|actThree
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|actTwo
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|actOne
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|actTwo
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|actThree
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|separators
name|void
name|tst_QActionGroup
operator|::
name|separators
parameter_list|()
block|{
name|QMainWindow
name|mw
decl_stmt|;
name|QMenu
name|menu
argument_list|(
operator|&
name|mw
argument_list|)
decl_stmt|;
name|QActionGroup
name|actGroup
argument_list|(
operator|&
name|mw
argument_list|)
decl_stmt|;
name|mw
operator|.
name|show
argument_list|()
expr_stmt|;
name|QAction
modifier|*
name|action
init|=
operator|new
name|QAction
argument_list|(
operator|&
name|actGroup
argument_list|)
decl_stmt|;
name|action
operator|->
name|setText
argument_list|(
literal|"test one"
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|separator
init|=
operator|new
name|QAction
argument_list|(
operator|&
name|actGroup
argument_list|)
decl_stmt|;
name|separator
operator|->
name|setSeparator
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|actGroup
operator|.
name|addAction
argument_list|(
name|separator
argument_list|)
expr_stmt|;
name|QListIterator
argument_list|<
name|QAction
modifier|*
argument_list|>
name|it
argument_list|(
name|actGroup
operator|.
name|actions
argument_list|()
argument_list|)
decl_stmt|;
while|while
condition|(
name|it
operator|.
name|hasNext
argument_list|()
condition|)
name|menu
operator|.
name|addAction
argument_list|(
name|it
operator|.
name|next
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|int
operator|)
name|menu
operator|.
name|actions
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|it
operator|=
name|QListIterator
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|actGroup
operator|.
name|actions
argument_list|()
argument_list|)
expr_stmt|;
while|while
condition|(
name|it
operator|.
name|hasNext
argument_list|()
condition|)
name|menu
operator|.
name|removeAction
argument_list|(
name|it
operator|.
name|next
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|int
operator|)
name|menu
operator|.
name|actions
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|action
operator|=
operator|new
name|QAction
argument_list|(
operator|&
name|actGroup
argument_list|)
expr_stmt|;
name|action
operator|->
name|setText
argument_list|(
literal|"test two"
argument_list|)
expr_stmt|;
name|it
operator|=
name|QListIterator
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|actGroup
operator|.
name|actions
argument_list|()
argument_list|)
expr_stmt|;
while|while
condition|(
name|it
operator|.
name|hasNext
argument_list|()
condition|)
name|menu
operator|.
name|addAction
argument_list|(
name|it
operator|.
name|next
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|int
operator|)
name|menu
operator|.
name|actions
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testActionInTwoQActionGroup
name|void
name|tst_QActionGroup
operator|::
name|testActionInTwoQActionGroup
parameter_list|()
block|{
name|QAction
name|action1
argument_list|(
literal|"Action 1"
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QActionGroup
name|group1
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QActionGroup
name|group2
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|group1
operator|.
name|addAction
argument_list|(
operator|&
name|action1
argument_list|)
expr_stmt|;
name|group2
operator|.
name|addAction
argument_list|(
operator|&
name|action1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|action1
operator|.
name|actionGroup
argument_list|()
argument_list|,
operator|&
name|group2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|group2
operator|.
name|actions
argument_list|()
operator|.
name|first
argument_list|()
argument_list|,
operator|&
name|action1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|group1
operator|.
name|actions
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unCheckCurrentAction
name|void
name|tst_QActionGroup
operator|::
name|unCheckCurrentAction
parameter_list|()
block|{
name|QActionGroup
name|group
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QAction
name|action1
argument_list|(
operator|&
name|group
argument_list|)
decl_stmt|,
name|action2
argument_list|(
operator|&
name|group
argument_list|)
decl_stmt|;
name|action1
operator|.
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|action2
operator|.
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|action1
operator|.
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|action2
operator|.
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|action1
operator|.
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|action1
operator|.
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|action2
operator|.
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|current
init|=
name|group
operator|.
name|checkedAction
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|current
argument_list|,
operator|&
name|action1
argument_list|)
expr_stmt|;
name|current
operator|->
name|setChecked
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|action1
operator|.
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|action2
operator|.
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|group
operator|.
name|checkedAction
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QActionGroup
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qactiongroup.moc"
end_include
end_unit
