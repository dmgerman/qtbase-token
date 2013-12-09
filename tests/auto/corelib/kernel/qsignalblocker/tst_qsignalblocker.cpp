begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Marc Mutz<marc.mutz@woboq.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|signalBlockingMoveAssignment
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|SenderObject
class|class
name|SenderObject
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|SenderObject
name|SenderObject
parameter_list|()
member_init_list|:
name|aPublicSlotCalled
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|recursionCount
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|emitSignal1AfterRecursion
name|void
name|emitSignal1AfterRecursion
parameter_list|()
block|{
if|if
condition|(
name|recursionCount
operator|++
operator|<
literal|100
condition|)
name|emitSignal1AfterRecursion
argument_list|()
expr_stmt|;
else|else
name|emitSignal1
argument_list|()
expr_stmt|;
block|}
DECL|function|emitSignal1
name|void
name|emitSignal1
parameter_list|()
block|{
emit|emit
name|signal1
argument_list|()
emit|;
block|}
DECL|function|emitSignal2
name|void
name|emitSignal2
parameter_list|()
block|{
emit|emit
name|signal2
argument_list|()
emit|;
block|}
DECL|function|emitSignal3
name|void
name|emitSignal3
parameter_list|()
block|{
emit|emit
name|signal3
argument_list|()
emit|;
block|}
DECL|function|emitSignal4
name|void
name|emitSignal4
parameter_list|()
block|{
emit|emit
name|signal4
argument_list|()
emit|;
block|}
signals|signals:
name|void
name|signal1
parameter_list|()
function_decl|;
name|void
name|signal2
parameter_list|()
function_decl|;
name|void
name|signal3
parameter_list|()
function_decl|;
name|void
name|signal4
parameter_list|()
function_decl|;
name|QT_MOC_COMPAT
name|void
name|signal5
parameter_list|()
function_decl|;
name|void
name|signal6
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|signal7
parameter_list|(
name|int
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
public|public
name|slots
public|:
DECL|function|aPublicSlot
name|void
name|aPublicSlot
parameter_list|()
block|{
name|aPublicSlotCalled
operator|++
expr_stmt|;
block|}
public|public:
DECL|function|invoke1
name|Q_INVOKABLE
name|void
name|invoke1
parameter_list|()
block|{}
DECL|function|sinvoke1
name|Q_SCRIPTABLE
name|void
name|sinvoke1
parameter_list|()
block|{}
DECL|member|aPublicSlotCalled
name|int
name|aPublicSlotCalled
decl_stmt|;
protected|protected:
DECL|function|invoke2
name|Q_INVOKABLE
name|QT_MOC_COMPAT
name|void
name|invoke2
parameter_list|()
block|{}
DECL|function|invoke2
name|Q_INVOKABLE
name|QT_MOC_COMPAT
name|void
name|invoke2
parameter_list|(
name|int
parameter_list|)
block|{}
DECL|function|sinvoke2
name|Q_SCRIPTABLE
name|QT_MOC_COMPAT
name|void
name|sinvoke2
parameter_list|()
block|{}
private|private:
DECL|function|invoke3
name|Q_INVOKABLE
name|void
name|invoke3
parameter_list|(
name|int
name|hinz
init|=
literal|0
parameter_list|,
name|int
name|kunz
init|=
literal|0
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|hinz
argument_list|)
name|Q_UNUSED
argument_list|(
argument|kunz
argument_list|)
block|}
DECL|function|sinvoke3
name|Q_SCRIPTABLE
name|void
name|sinvoke3
parameter_list|()
block|{}
DECL|member|recursionCount
name|int
name|recursionCount
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|ReceiverObject
class|class
name|ReceiverObject
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|ReceiverObject
name|ReceiverObject
parameter_list|()
member_init_list|:
name|sequence_slot1
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|sequence_slot2
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|sequence_slot3
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|sequence_slot4
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|reset
name|void
name|reset
parameter_list|()
block|{
name|sequence_slot4
operator|=
literal|0
expr_stmt|;
name|sequence_slot3
operator|=
literal|0
expr_stmt|;
name|sequence_slot2
operator|=
literal|0
expr_stmt|;
name|sequence_slot1
operator|=
literal|0
expr_stmt|;
name|count_slot1
operator|=
literal|0
expr_stmt|;
name|count_slot2
operator|=
literal|0
expr_stmt|;
name|count_slot3
operator|=
literal|0
expr_stmt|;
name|count_slot4
operator|=
literal|0
expr_stmt|;
block|}
DECL|member|sequence_slot1
name|int
name|sequence_slot1
decl_stmt|;
DECL|member|sequence_slot2
name|int
name|sequence_slot2
decl_stmt|;
DECL|member|sequence_slot3
name|int
name|sequence_slot3
decl_stmt|;
DECL|member|sequence_slot4
name|int
name|sequence_slot4
decl_stmt|;
DECL|member|count_slot1
name|int
name|count_slot1
decl_stmt|;
DECL|member|count_slot2
name|int
name|count_slot2
decl_stmt|;
DECL|member|count_slot3
name|int
name|count_slot3
decl_stmt|;
DECL|member|count_slot4
name|int
name|count_slot4
decl_stmt|;
DECL|function|called
name|bool
name|called
parameter_list|(
name|int
name|slot
parameter_list|)
block|{
switch|switch
condition|(
name|slot
condition|)
block|{
case|case
literal|1
case|:
return|return
name|sequence_slot1
return|;
case|case
literal|2
case|:
return|return
name|sequence_slot2
return|;
case|case
literal|3
case|:
return|return
name|sequence_slot3
return|;
case|case
literal|4
case|:
return|return
name|sequence_slot4
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
DECL|member|sequence
specifier|static
name|int
name|sequence
decl_stmt|;
public|public
name|slots
public|:
DECL|function|slot1
name|void
name|slot1
parameter_list|()
block|{
name|sequence_slot1
operator|=
operator|++
name|sequence
expr_stmt|;
name|count_slot1
operator|++
expr_stmt|;
block|}
DECL|function|slot2
name|void
name|slot2
parameter_list|()
block|{
name|sequence_slot2
operator|=
operator|++
name|sequence
expr_stmt|;
name|count_slot2
operator|++
expr_stmt|;
block|}
DECL|function|slot3
name|void
name|slot3
parameter_list|()
block|{
name|sequence_slot3
operator|=
operator|++
name|sequence
expr_stmt|;
name|count_slot3
operator|++
expr_stmt|;
block|}
DECL|function|slot4
name|void
name|slot4
parameter_list|()
block|{
name|sequence_slot4
operator|=
operator|++
name|sequence
expr_stmt|;
name|count_slot4
operator|++
expr_stmt|;
block|}
block|}
class|;
end_class
begin_decl_stmt
DECL|member|sequence
name|int
name|ReceiverObject
operator|::
name|sequence
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|signalBlocking
name|void
name|tst_QSignalBlocker
operator|::
name|signalBlocking
parameter_list|()
block|{
name|SenderObject
name|sender
decl_stmt|;
name|ReceiverObject
name|receiver
decl_stmt|;
name|receiver
operator|.
name|connect
argument_list|(
operator|&
name|sender
argument_list|,
name|SIGNAL
argument_list|(
name|signal1
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|slot1
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|sender
operator|.
name|emitSignal1
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|receiver
operator|.
name|called
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|receiver
operator|.
name|reset
argument_list|()
expr_stmt|;
block|{
name|QSignalBlocker
name|blocker
argument_list|(
operator|&
name|sender
argument_list|)
decl_stmt|;
name|sender
operator|.
name|emitSignal1
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|receiver
operator|.
name|called
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|receiver
operator|.
name|reset
argument_list|()
expr_stmt|;
name|sender
operator|.
name|blockSignals
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|sender
operator|.
name|emitSignal1
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|receiver
operator|.
name|called
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|receiver
operator|.
name|reset
argument_list|()
expr_stmt|;
name|sender
operator|.
name|blockSignals
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|sender
operator|.
name|emitSignal1
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|receiver
operator|.
name|called
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|receiver
operator|.
name|reset
argument_list|()
expr_stmt|;
name|blocker
operator|.
name|unblock
argument_list|()
expr_stmt|;
name|sender
operator|.
name|emitSignal1
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|receiver
operator|.
name|called
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|receiver
operator|.
name|reset
argument_list|()
expr_stmt|;
name|blocker
operator|.
name|reblock
argument_list|()
expr_stmt|;
name|sender
operator|.
name|emitSignal1
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|receiver
operator|.
name|called
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|receiver
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
name|sender
operator|.
name|emitSignal1
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|receiver
operator|.
name|called
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|receiver
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|signalBlockingMoveAssignment
name|void
name|tst_QSignalBlocker
operator|::
name|signalBlockingMoveAssignment
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
