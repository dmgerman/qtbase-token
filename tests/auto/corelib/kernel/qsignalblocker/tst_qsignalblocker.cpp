begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Marc Mutz<marc.mutz@woboq.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|"qobject.h"
end_include
begin_class
DECL|class|tst_QSignalBlocker
class|class
name|tst_QSignalBlocker
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|signalBlocking
parameter_list|()
function_decl|;
name|void
name|moveAssignment
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|signalBlocking
name|void
name|tst_QSignalBlocker
operator|::
name|signalBlocking
parameter_list|()
block|{
name|QObject
name|o
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
block|{
name|QSignalBlocker
name|blocker
argument_list|(
operator|&
name|o
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|o
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|o
operator|.
name|blockSignals
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|o
operator|.
name|blockSignals
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|o
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|blocker
operator|.
name|unblock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|blocker
operator|.
name|reblock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|o
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
operator|!
name|o
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|moveAssignment
name|void
name|tst_QSignalBlocker
operator|::
name|moveAssignment
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QObject
name|o1
decl_stmt|,
name|o2
decl_stmt|;
comment|// move-assignment: both block other objects
block|{
name|QSignalBlocker
name|b
argument_list|(
operator|&
name|o1
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o2
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|b
operator|=
name|QSignalBlocker
argument_list|(
operator|&
name|o2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|o2
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
operator|!
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o2
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
comment|// move-assignment: from inert other
block|{
name|QSignalBlocker
name|b
argument_list|(
operator|&
name|o1
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|b
operator|=
name|QSignalBlocker
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
operator|!
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o2
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
comment|// move-assignment: to inert *this
block|{
name|QSignalBlocker
name|b
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
block|{
name|QSignalBlocker
name|inner
argument_list|(
operator|&
name|o1
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|b
operator|=
name|std
operator|::
name|move
argument_list|(
name|inner
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
operator|!
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o2
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
comment|// move-assignment: both block the same object, neither is unblocked
block|{
name|QSignalBlocker
name|b
argument_list|(
operator|&
name|o1
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
block|{
name|b
operator|.
name|unblock
argument_list|()
expr_stmt|;
comment|// make sure inner.m_blocked = false
name|QVERIFY
argument_list|(
operator|!
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|QSignalBlocker
name|inner
argument_list|(
operator|&
name|o1
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|b
operator|.
name|reblock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|b
operator|=
name|std
operator|::
name|move
argument_list|(
name|inner
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
operator|!
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o2
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
comment|// move-assignment: both block the same object, but *this is unblocked
block|{
name|QSignalBlocker
name|b
argument_list|(
operator|&
name|o1
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|b
operator|.
name|unblock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|b
operator|=
name|QSignalBlocker
argument_list|(
operator|&
name|o1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
operator|!
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o2
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
comment|// move-assignment: both block the same object, but other is unblocked
block|{
name|QSignalBlocker
name|b
argument_list|(
operator|&
name|o1
argument_list|)
decl_stmt|;
block|{
name|QVERIFY
argument_list|(
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|QSignalBlocker
name|inner
argument_list|(
operator|&
name|o1
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|inner
operator|.
name|unblock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|b
operator|=
name|std
operator|::
name|move
argument_list|(
name|inner
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
operator|!
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
operator|!
name|o1
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|o2
operator|.
name|signalsBlocked
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|QSKIP
argument_list|(
literal|"This compiler is not in C++11 mode or doesn't support move semantics"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Q_COMPILER_RVALUE_REFS
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSignalBlocker
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsignalblocker.moc"
end_include
end_unit
