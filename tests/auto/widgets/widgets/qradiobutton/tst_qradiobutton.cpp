begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QRadioButton>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_class
DECL|class|tst_QRadioButton
class|class
name|tst_QRadioButton
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QRadioButton
name|tst_QRadioButton
parameter_list|()
block|{}
empty_stmt|;
DECL|function|~tst_QRadioButton
specifier|virtual
name|~
name|tst_QRadioButton
parameter_list|()
block|{}
empty_stmt|;
private|private
name|slots
private|:
name|void
name|task190739_focus
parameter_list|()
function_decl|;
name|void
name|minimumSizeHint
parameter_list|()
function_decl|;
private|private:
block|}
class|;
end_class
begin_function
DECL|function|task190739_focus
name|void
name|tst_QRadioButton
operator|::
name|task190739_focus
parameter_list|()
block|{
name|QWidget
name|widget
decl_stmt|;
name|QPushButton
name|button1
argument_list|(
operator|&
name|widget
argument_list|)
decl_stmt|;
name|button1
operator|.
name|setText
argument_list|(
literal|"button1"
argument_list|)
expr_stmt|;
name|QLineEdit
name|edit
argument_list|(
operator|&
name|widget
argument_list|)
decl_stmt|;
name|edit
operator|.
name|setFocus
argument_list|()
expr_stmt|;
name|QRadioButton
name|radio1
argument_list|(
operator|&
name|widget
argument_list|)
decl_stmt|;
name|radio1
operator|.
name|setText
argument_list|(
literal|"radio1"
argument_list|)
expr_stmt|;
name|radio1
operator|.
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|TabFocus
argument_list|)
expr_stmt|;
name|radio1
operator|.
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
literal|"Ctrl+O"
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
name|layout
argument_list|(
operator|&
name|widget
argument_list|)
decl_stmt|;
name|layout
operator|.
name|addWidget
argument_list|(
operator|&
name|button1
argument_list|)
expr_stmt|;
name|layout
operator|.
name|addWidget
argument_list|(
operator|&
name|edit
argument_list|)
expr_stmt|;
name|layout
operator|.
name|addWidget
argument_list|(
operator|&
name|radio1
argument_list|)
expr_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|widget
operator|.
name|activateWindow
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|setActiveWindow
argument_list|(
operator|&
name|widget
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|edit
operator|.
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|radio1
operator|.
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
operator|&
name|edit
argument_list|,
name|Qt
operator|::
name|Key_O
argument_list|,
name|Qt
operator|::
name|ControlModifier
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|radio1
operator|.
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|edit
operator|.
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|radio1
operator|.
name|hasFocus
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|minimumSizeHint
name|void
name|tst_QRadioButton
operator|::
name|minimumSizeHint
parameter_list|()
block|{
name|QRadioButton
name|button
argument_list|(
name|tr
argument_list|(
literal|"QRadioButtons sizeHint is the same as it's minimumSizeHint"
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|button
operator|.
name|sizeHint
argument_list|()
argument_list|,
name|button
operator|.
name|minimumSizeHint
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QRadioButton
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qradiobutton.moc"
end_include
end_unit
