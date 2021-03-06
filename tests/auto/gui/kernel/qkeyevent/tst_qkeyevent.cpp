begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
file|<QtGui/qevent.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_class
DECL|class|Window
class|class
name|Window
super|:
specifier|public
name|QWindow
block|{
public|public:
DECL|function|~Window
name|~
name|Window
parameter_list|()
block|{
name|reset
argument_list|()
expr_stmt|;
block|}
DECL|function|keyPressEvent
name|void
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
name|recordEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
DECL|function|keyReleaseEvent
name|void
name|keyReleaseEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
name|recordEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
DECL|function|reset
name|void
name|reset
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|keyEvents
operator|.
name|begin
argument_list|()
argument_list|,
name|keyEvents
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|keyEvents
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|function|recordEvent
name|void
name|recordEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
name|keyEvents
operator|.
name|append
argument_list|(
operator|new
name|QKeyEvent
argument_list|(
name|event
operator|->
name|type
argument_list|()
argument_list|,
name|event
operator|->
name|key
argument_list|()
argument_list|,
name|event
operator|->
name|modifiers
argument_list|()
argument_list|,
name|event
operator|->
name|nativeScanCode
argument_list|()
argument_list|,
name|event
operator|->
name|nativeVirtualKey
argument_list|()
argument_list|,
name|event
operator|->
name|nativeModifiers
argument_list|()
argument_list|,
name|event
operator|->
name|text
argument_list|()
argument_list|,
name|event
operator|->
name|isAutoRepeat
argument_list|()
argument_list|,
name|event
operator|->
name|count
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
public|public:
DECL|member|keyEvents
name|QVector
argument_list|<
name|QKeyEvent
modifier|*
argument_list|>
name|keyEvents
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|tst_QKeyEvent
class|class
name|tst_QKeyEvent
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QKeyEvent
parameter_list|()
constructor_decl|;
name|~
name|tst_QKeyEvent
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|basicEventDelivery
parameter_list|()
function_decl|;
name|void
name|modifiers_data
parameter_list|()
function_decl|;
name|void
name|modifiers
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QKeyEvent
name|tst_QKeyEvent
operator|::
name|tst_QKeyEvent
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QKeyEvent
name|tst_QKeyEvent
operator|::
name|~
name|tst_QKeyEvent
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|basicEventDelivery
name|void
name|tst_QKeyEvent
operator|::
name|basicEventDelivery
parameter_list|()
block|{
name|Window
name|window
decl_stmt|;
name|window
operator|.
name|showNormal
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|window
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|Qt
operator|::
name|Key
name|key
init|=
name|Qt
operator|::
name|Key_A
decl_stmt|;
specifier|const
name|Qt
operator|::
name|KeyboardModifier
name|modifiers
init|=
name|Qt
operator|::
name|NoModifier
decl_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
operator|&
name|window
argument_list|,
name|key
argument_list|,
name|modifiers
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|window
operator|.
name|keyEvents
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|window
operator|.
name|keyEvents
operator|.
name|first
argument_list|()
operator|->
name|type
argument_list|()
argument_list|,
name|QKeyEvent
operator|::
name|KeyPress
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|window
operator|.
name|keyEvents
operator|.
name|last
argument_list|()
operator|->
name|type
argument_list|()
argument_list|,
name|QKeyEvent
operator|::
name|KeyRelease
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QKeyEvent
modifier|*
name|event
decl|,
name|window
operator|.
name|keyEvents
control|)
block|{
name|QCOMPARE
argument_list|(
name|Qt
operator|::
name|Key
argument_list|(
name|event
operator|->
name|key
argument_list|()
argument_list|)
argument_list|,
name|key
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|Qt
operator|::
name|KeyboardModifiers
argument_list|(
name|event
operator|->
name|modifiers
argument_list|()
argument_list|)
argument_list|,
name|modifiers
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|orderByModifier
specifier|static
name|bool
name|orderByModifier
parameter_list|(
specifier|const
name|QVector
argument_list|<
name|int
argument_list|>
modifier|&
name|v1
parameter_list|,
specifier|const
name|QVector
argument_list|<
name|int
argument_list|>
modifier|&
name|v2
parameter_list|)
block|{
if|if
condition|(
name|v1
operator|.
name|size
argument_list|()
operator|!=
name|v2
operator|.
name|size
argument_list|()
condition|)
return|return
name|v1
operator|.
name|size
argument_list|()
operator|<
name|v2
operator|.
name|size
argument_list|()
return|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|qMin
argument_list|(
name|v1
operator|.
name|size
argument_list|()
argument_list|,
name|v2
operator|.
name|size
argument_list|()
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|v1
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|v2
operator|.
name|at
argument_list|(
name|i
argument_list|)
condition|)
continue|continue;
return|return
name|v1
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|<
name|v2
operator|.
name|at
argument_list|(
name|i
argument_list|)
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|modifiersTestRowName
specifier|static
name|QByteArray
name|modifiersTestRowName
parameter_list|(
specifier|const
name|QString
modifier|&
name|keySequence
parameter_list|)
block|{
name|QByteArray
name|result
decl_stmt|;
name|QTextStream
name|str
argument_list|(
operator|&
name|result
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|,
name|size
init|=
name|keySequence
operator|.
name|size
argument_list|()
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QChar
modifier|&
name|c
init|=
name|keySequence
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
specifier|const
name|ushort
name|uc
init|=
name|c
operator|.
name|unicode
argument_list|()
decl_stmt|;
if|if
condition|(
name|uc
operator|>
literal|32
operator|&&
name|uc
operator|<
literal|128
condition|)
name|str
operator|<<
literal|'"'
operator|<<
name|c
operator|<<
literal|'"'
expr_stmt|;
else|else
name|str
operator|<<
literal|"U+"
operator|<<
name|hex
operator|<<
name|uc
operator|<<
name|dec
expr_stmt|;
if|if
condition|(
name|i
operator|<
name|size
operator|-
literal|1
condition|)
name|str
operator|<<
literal|','
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|modifiers_data
name|void
name|tst_QKeyEvent
operator|::
name|modifiers_data
parameter_list|()
block|{
struct|struct
name|Modifier
block|{
name|Qt
operator|::
name|Key
name|key
decl_stmt|;
name|Qt
operator|::
name|KeyboardModifier
name|modifier
decl_stmt|;
block|}
struct|;
specifier|static
specifier|const
name|Modifier
name|modifiers
index|[]
init|=
block|{
block|{
name|Qt
operator|::
name|Key_Shift
block|,
name|Qt
operator|::
name|ShiftModifier
block|}
block|,
block|{
name|Qt
operator|::
name|Key_Control
block|,
name|Qt
operator|::
name|ControlModifier
block|}
block|,
block|{
name|Qt
operator|::
name|Key_Alt
block|,
name|Qt
operator|::
name|AltModifier
block|}
block|,
block|{
name|Qt
operator|::
name|Key_Meta
block|,
name|Qt
operator|::
name|MetaModifier
block|}
block|,     }
decl_stmt|;
name|QVector
argument_list|<
name|QVector
argument_list|<
name|int
argument_list|>
argument_list|>
name|modifierCombinations
decl_stmt|;
comment|// Generate powerset (minus the empty set) of possible modifier combinations
specifier|static
specifier|const
name|int
name|kNumModifiers
init|=
sizeof|sizeof
argument_list|(
name|modifiers
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|Modifier
argument_list|)
decl_stmt|;
for|for
control|(
name|quint64
name|bitmask
init|=
literal|1
init|;
name|bitmask
operator|<
operator|(
literal|1
operator|<<
name|kNumModifiers
operator|)
condition|;
operator|++
name|bitmask
control|)
block|{
name|QVector
argument_list|<
name|int
argument_list|>
name|modifierCombination
decl_stmt|;
for|for
control|(
name|quint64
name|modifier
init|=
literal|0
init|;
name|modifier
operator|<
name|kNumModifiers
condition|;
operator|++
name|modifier
control|)
block|{
if|if
condition|(
name|bitmask
operator|&
operator|(
name|quint64
argument_list|(
literal|1
argument_list|)
operator|<<
name|modifier
operator|)
condition|)
name|modifierCombination
operator|.
name|append
argument_list|(
name|modifier
argument_list|)
expr_stmt|;
block|}
name|modifierCombinations
operator|.
name|append
argument_list|(
name|modifierCombination
argument_list|)
expr_stmt|;
block|}
name|qSort
argument_list|(
name|modifierCombinations
operator|.
name|begin
argument_list|()
argument_list|,
name|modifierCombinations
operator|.
name|end
argument_list|()
argument_list|,
name|orderByModifier
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|KeyboardModifiers
argument_list|>
argument_list|(
literal|"modifiers"
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QVector
argument_list|<
name|int
argument_list|>
name|combination
decl|,
name|modifierCombinations
control|)
block|{
name|int
name|keys
index|[
literal|4
index|]
init|=
block|{}
decl_stmt|;
name|Qt
operator|::
name|KeyboardModifiers
name|mods
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
name|combination
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|Modifier
name|modifier
init|=
name|modifiers
index|[
name|combination
operator|.
name|at
argument_list|(
name|i
argument_list|)
index|]
decl_stmt|;
name|keys
index|[
name|i
index|]
operator|=
name|modifier
operator|.
name|key
expr_stmt|;
name|mods
operator||=
name|modifier
operator|.
name|modifier
expr_stmt|;
block|}
name|QKeySequence
name|keySequence
argument_list|(
name|keys
index|[
literal|0
index|]
argument_list|,
name|keys
index|[
literal|1
index|]
argument_list|,
name|keys
index|[
literal|2
index|]
argument_list|,
name|keys
index|[
literal|3
index|]
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|modifiersTestRowName
argument_list|(
name|keySequence
operator|.
name|toString
argument_list|(
name|QKeySequence
operator|::
name|NativeText
argument_list|)
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
name|mods
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|modifiers
name|void
name|tst_QKeyEvent
operator|::
name|modifiers
parameter_list|()
block|{
name|Window
name|window
decl_stmt|;
name|window
operator|.
name|showNormal
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|window
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|Qt
operator|::
name|Key
name|key
init|=
name|Qt
operator|::
name|Key_A
decl_stmt|;
name|QFETCH
argument_list|(
name|Qt
operator|::
name|KeyboardModifiers
argument_list|,
name|modifiers
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
operator|&
name|window
argument_list|,
name|key
argument_list|,
name|modifiers
argument_list|)
expr_stmt|;
name|int
name|numKeys
init|=
name|qPopulationCount
argument_list|(
name|quint64
argument_list|(
name|modifiers
argument_list|)
argument_list|)
operator|+
literal|1
decl_stmt|;
name|QCOMPARE
argument_list|(
name|window
operator|.
name|keyEvents
operator|.
name|size
argument_list|()
argument_list|,
name|numKeys
operator|*
literal|2
argument_list|)
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
name|window
operator|.
name|keyEvents
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QKeyEvent
modifier|*
name|event
init|=
name|window
operator|.
name|keyEvents
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|event
operator|->
name|type
argument_list|()
argument_list|,
name|i
operator|<
name|numKeys
condition|?
name|QKeyEvent
operator|::
name|KeyPress
else|:
name|QKeyEvent
operator|::
name|KeyRelease
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
name|numKeys
operator|-
literal|1
operator|||
name|i
operator|==
name|numKeys
condition|)
block|{
name|QCOMPARE
argument_list|(
name|Qt
operator|::
name|Key
argument_list|(
name|event
operator|->
name|key
argument_list|()
argument_list|)
argument_list|,
name|key
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|event
operator|->
name|modifiers
argument_list|()
argument_list|,
name|modifiers
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QVERIFY
argument_list|(
name|Qt
operator|::
name|Key
argument_list|(
name|event
operator|->
name|key
argument_list|()
argument_list|)
operator|!=
name|key
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QKeyEvent
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qkeyevent.moc"
end_include
end_unit
