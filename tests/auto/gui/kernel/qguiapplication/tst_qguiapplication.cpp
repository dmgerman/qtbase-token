begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_class
DECL|class|tst_QGuiApplication
class|class
name|tst_QGuiApplication
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|focusObject
parameter_list|()
function_decl|;
name|void
name|allWindows
parameter_list|()
function_decl|;
name|void
name|topLevelWindows
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|DummyWindow
class|class
name|DummyWindow
super|:
specifier|public
name|QWindow
block|{
public|public:
DECL|function|DummyWindow
name|DummyWindow
parameter_list|()
member_init_list|:
name|m_focusObject
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|focusObject
specifier|virtual
name|QObject
modifier|*
name|focusObject
parameter_list|()
specifier|const
block|{
return|return
name|m_focusObject
return|;
block|}
DECL|function|setFocusObject
name|void
name|setFocusObject
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|m_focusObject
operator|=
name|object
expr_stmt|;
emit|emit
name|focusObjectChanged
argument_list|(
name|object
argument_list|)
emit|;
block|}
DECL|member|m_focusObject
name|QObject
modifier|*
name|m_focusObject
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|focusObject
name|void
name|tst_QGuiApplication
operator|::
name|focusObject
parameter_list|()
block|{
name|int
name|argc
init|=
literal|0
decl_stmt|;
name|QGuiApplication
name|app
argument_list|(
name|argc
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QObject
name|obj1
decl_stmt|,
name|obj2
decl_stmt|,
name|obj3
decl_stmt|;
name|DummyWindow
name|window1
decl_stmt|;
name|DummyWindow
name|window2
decl_stmt|;
name|window1
operator|.
name|show
argument_list|()
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|app
argument_list|,
name|SIGNAL
argument_list|(
name|focusObjectChanged
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
comment|// verify active window focus propagates to qguiapplication
name|QTest
operator|::
name|qWaitForWindowShown
argument_list|(
operator|&
name|window1
argument_list|)
expr_stmt|;
name|window1
operator|.
name|requestActivateWindow
argument_list|()
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|app
operator|.
name|focusWindow
argument_list|()
argument_list|,
operator|&
name|window1
argument_list|)
expr_stmt|;
name|window1
operator|.
name|setFocusObject
argument_list|(
operator|&
name|obj1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|app
operator|.
name|focusObject
argument_list|()
argument_list|,
operator|&
name|obj1
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
name|window1
operator|.
name|setFocusObject
argument_list|(
operator|&
name|obj2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|app
operator|.
name|focusObject
argument_list|()
argument_list|,
operator|&
name|obj2
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
name|window2
operator|.
name|setFocusObject
argument_list|(
operator|&
name|obj3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|app
operator|.
name|focusObject
argument_list|()
argument_list|,
operator|&
name|obj2
argument_list|)
expr_stmt|;
comment|// not yet changed
name|window2
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowShown
argument_list|(
operator|&
name|window2
argument_list|)
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|app
operator|.
name|focusWindow
argument_list|()
argument_list|,
operator|&
name|window2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|app
operator|.
name|focusObject
argument_list|()
argument_list|,
operator|&
name|obj3
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
comment|// focus change on unfocused window does not show
name|spy
operator|.
name|clear
argument_list|()
expr_stmt|;
name|window1
operator|.
name|setFocusObject
argument_list|(
operator|&
name|obj1
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
name|QCOMPARE
argument_list|(
name|app
operator|.
name|focusObject
argument_list|()
argument_list|,
operator|&
name|obj3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|allWindows
name|void
name|tst_QGuiApplication
operator|::
name|allWindows
parameter_list|()
block|{
name|int
name|argc
init|=
literal|0
decl_stmt|;
name|QGuiApplication
name|app
argument_list|(
name|argc
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QWindow
modifier|*
name|window1
init|=
operator|new
name|QWindow
decl_stmt|;
name|QWindow
modifier|*
name|window2
init|=
operator|new
name|QWindow
argument_list|(
name|window1
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|app
operator|.
name|allWindows
argument_list|()
operator|.
name|contains
argument_list|(
name|window1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|app
operator|.
name|allWindows
argument_list|()
operator|.
name|contains
argument_list|(
name|window2
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|app
operator|.
name|allWindows
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
operator|delete
name|window1
expr_stmt|;
name|window1
operator|=
literal|0
expr_stmt|;
name|window2
operator|=
literal|0
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|app
operator|.
name|allWindows
argument_list|()
operator|.
name|contains
argument_list|(
name|window2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|app
operator|.
name|allWindows
argument_list|()
operator|.
name|contains
argument_list|(
name|window1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|app
operator|.
name|allWindows
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|topLevelWindows
name|void
name|tst_QGuiApplication
operator|::
name|topLevelWindows
parameter_list|()
block|{
name|int
name|argc
init|=
literal|0
decl_stmt|;
name|QGuiApplication
name|app
argument_list|(
name|argc
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QWindow
modifier|*
name|window1
init|=
operator|new
name|QWindow
decl_stmt|;
name|QWindow
modifier|*
name|window2
init|=
operator|new
name|QWindow
argument_list|(
name|window1
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|app
operator|.
name|topLevelWindows
argument_list|()
operator|.
name|contains
argument_list|(
name|window1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|app
operator|.
name|topLevelWindows
argument_list|()
operator|.
name|contains
argument_list|(
name|window2
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|app
operator|.
name|topLevelWindows
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
operator|delete
name|window1
expr_stmt|;
name|window1
operator|=
literal|0
expr_stmt|;
name|window2
operator|=
literal|0
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|app
operator|.
name|topLevelWindows
argument_list|()
operator|.
name|contains
argument_list|(
name|window2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|app
operator|.
name|topLevelWindows
argument_list|()
operator|.
name|contains
argument_list|(
name|window1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|app
operator|.
name|topLevelWindows
argument_list|()
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
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QGuiApplication
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qguiapplication.moc"
end_include
end_unit
