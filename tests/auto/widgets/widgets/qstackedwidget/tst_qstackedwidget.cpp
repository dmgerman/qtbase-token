begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qstackedwidget.h>
end_include
begin_include
include|#
directive|include
file|<qpushbutton.h>
end_include
begin_include
include|#
directive|include
file|<QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<qlineedit.h>
end_include
begin_class
DECL|class|tst_QStackedWidget
class|class
name|tst_QStackedWidget
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QStackedWidget
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QStackedWidget
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
name|testMinimumSize
parameter_list|()
function_decl|;
name|void
name|dynamicPages
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QStackedWidget
name|tst_QStackedWidget
operator|::
name|tst_QStackedWidget
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QStackedWidget
name|tst_QStackedWidget
operator|::
name|~
name|tst_QStackedWidget
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|// Testing that stackedwidget respect the minimum size of it's contents (task 95319)
end_comment
begin_function
DECL|function|testMinimumSize
name|void
name|tst_QStackedWidget
operator|::
name|testMinimumSize
parameter_list|()
block|{
name|QWidget
name|w
decl_stmt|;
name|QStackedWidget
name|sw
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
name|QPushButton
name|button
argument_list|(
literal|"Text"
argument_list|,
operator|&
name|sw
argument_list|)
decl_stmt|;
name|sw
operator|.
name|addWidget
argument_list|(
operator|&
name|button
argument_list|)
expr_stmt|;
name|QHBoxLayout
name|hboxLayout
decl_stmt|;
name|hboxLayout
operator|.
name|addWidget
argument_list|(
operator|&
name|sw
argument_list|)
expr_stmt|;
name|w
operator|.
name|setLayout
argument_list|(
operator|&
name|hboxLayout
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|.
name|minimumSize
argument_list|()
operator|!=
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QStackedWidget
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QStackedWidget
name|obj1
decl_stmt|;
comment|// int QStackedWidget::currentIndex()
comment|// void QStackedWidget::setCurrentIndex(int)
name|obj1
operator|.
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|-
literal|1
argument_list|,
name|obj1
operator|.
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setCurrentIndex
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|-
literal|1
argument_list|,
name|obj1
operator|.
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setCurrentIndex
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|-
literal|1
argument_list|,
name|obj1
operator|.
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
comment|// QWidget * QStackedWidget::currentWidget()
comment|// void QStackedWidget::setCurrentWidget(QWidget *)
name|QWidget
modifier|*
name|var2
init|=
operator|new
name|QWidget
argument_list|()
decl_stmt|;
name|obj1
operator|.
name|addWidget
argument_list|(
name|var2
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setCurrentWidget
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
name|currentWidget
argument_list|()
argument_list|)
expr_stmt|;
comment|// Disabled, task to fix is 128939.
if|#
directive|if
literal|0
comment|// Layouts assert on any unknown widgets here, 0-pointers included.
comment|// This seems wrong behavior, since the setCurrentIndex(int), which
comment|// is really a convenience function for setCurrentWidget(QWidget*),
comment|// has no problem handling out-of-bounds indices.
comment|// ("convenience function" => "just another way of achieving the
comment|// same goal")
block|obj1.setCurrentWidget((QWidget *)0);     QCOMPARE(obj1.currentWidget(), var2);
endif|#
directive|endif
operator|delete
name|var2
expr_stmt|;
block|}
end_function
begin_comment
comment|// QTBUG-18242, a widget that deletes its children in hideEvent().
end_comment
begin_comment
comment|// This caused a crash in QStackedLayout::setCurrentIndex() since
end_comment
begin_comment
comment|// the focus widget was destroyed while hiding the previous page.
end_comment
begin_class
DECL|class|TestPage
class|class
name|TestPage
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|TestPage
name|TestPage
parameter_list|(
name|bool
name|staticWidgets
init|=
literal|false
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_staticWidgets
argument_list|(
name|staticWidgets
argument_list|)
block|{
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
DECL|function|~TestPage
name|~
name|TestPage
parameter_list|()
block|{
name|destroyWidgets
argument_list|()
expr_stmt|;
block|}
DECL|function|setN
name|void
name|setN
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|m_n
operator|=
name|n
expr_stmt|;
if|if
condition|(
name|m_staticWidgets
condition|)
name|createWidgets
argument_list|()
expr_stmt|;
block|}
DECL|function|showEvent
specifier|virtual
name|void
name|showEvent
parameter_list|(
name|QShowEvent
modifier|*
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_staticWidgets
condition|)
name|createWidgets
argument_list|()
expr_stmt|;
block|}
DECL|function|hideEvent
specifier|virtual
name|void
name|hideEvent
parameter_list|(
name|QHideEvent
modifier|*
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_staticWidgets
condition|)
name|destroyWidgets
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|function|createWidgets
name|void
name|createWidgets
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_n
condition|;
operator|++
name|i
control|)
block|{
name|QLineEdit
modifier|*
name|le
init|=
operator|new
name|QLineEdit
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|le
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"lineEdit%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|layout
argument_list|()
operator|->
name|addWidget
argument_list|(
name|le
argument_list|)
expr_stmt|;
name|m_les
operator|<<
name|le
expr_stmt|;
block|}
block|}
DECL|function|destroyWidgets
name|void
name|destroyWidgets
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|m_les
argument_list|)
expr_stmt|;
name|m_les
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|member|m_n
name|int
name|m_n
decl_stmt|;
DECL|member|m_staticWidgets
specifier|const
name|bool
name|m_staticWidgets
decl_stmt|;
DECL|member|m_les
name|QList
argument_list|<
name|QLineEdit
modifier|*
argument_list|>
name|m_les
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|dynamicPages
name|void
name|tst_QStackedWidget
operator|::
name|dynamicPages
parameter_list|()
block|{
name|QStackedWidget
modifier|*
name|sw
init|=
operator|new
name|QStackedWidget
decl_stmt|;
name|TestPage
modifier|*
name|w1
init|=
operator|new
name|TestPage
argument_list|(
literal|true
argument_list|)
decl_stmt|;
name|w1
operator|->
name|setN
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|TestPage
modifier|*
name|w2
init|=
operator|new
name|TestPage
decl_stmt|;
name|w2
operator|->
name|setN
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|sw
operator|->
name|addWidget
argument_list|(
name|w1
argument_list|)
expr_stmt|;
name|sw
operator|->
name|addWidget
argument_list|(
name|w2
argument_list|)
expr_stmt|;
name|QLineEdit
modifier|*
name|le11
init|=
name|w1
operator|->
name|findChild
argument_list|<
name|QLineEdit
operator|*
argument_list|>
argument_list|(
name|QLatin1String
argument_list|(
literal|"lineEdit1"
argument_list|)
argument_list|)
decl_stmt|;
name|le11
operator|->
name|setFocus
argument_list|()
expr_stmt|;
comment|// set focus to second widget in the page
name|sw
operator|->
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|sw
operator|->
name|show
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|setActiveWindow
argument_list|(
name|sw
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowActive
argument_list|(
name|sw
argument_list|)
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|QApplication
operator|::
name|focusWidget
argument_list|()
argument_list|,
name|le11
argument_list|)
expr_stmt|;
name|sw
operator|->
name|setCurrentIndex
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QLineEdit
modifier|*
name|le22
init|=
name|w2
operator|->
name|findChild
argument_list|<
name|QLineEdit
operator|*
argument_list|>
argument_list|(
name|QLatin1String
argument_list|(
literal|"lineEdit2"
argument_list|)
argument_list|)
decl_stmt|;
name|le22
operator|->
name|setFocus
argument_list|()
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|QApplication
operator|::
name|focusWidget
argument_list|()
argument_list|,
name|le22
argument_list|)
expr_stmt|;
comment|// Going back should move focus back to le11
name|sw
operator|->
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|QApplication
operator|::
name|focusWidget
argument_list|()
argument_list|,
name|le11
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QStackedWidget
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qstackedwidget.moc"
end_include
end_unit
