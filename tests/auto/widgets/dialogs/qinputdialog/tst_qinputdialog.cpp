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
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QSpinBox>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QComboBox>
end_include
begin_include
include|#
directive|include
file|<QDialogButtonBox>
end_include
begin_include
include|#
directive|include
file|<qinputdialog.h>
end_include
begin_class
DECL|class|tst_QInputDialog
class|class
name|tst_QInputDialog
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|parent
name|QWidget
modifier|*
name|parent
decl_stmt|;
DECL|member|doneCode
name|QDialog
operator|::
name|DialogCode
name|doneCode
decl_stmt|;
DECL|member|testFunc
name|void
function_decl|(
modifier|*
name|testFunc
function_decl|)
parameter_list|(
name|QInputDialog
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|void
name|testFuncGetInt
parameter_list|(
name|QInputDialog
modifier|*
name|dialog
parameter_list|)
function_decl|;
specifier|static
name|void
name|testFuncGetDouble
parameter_list|(
name|QInputDialog
modifier|*
name|dialog
parameter_list|)
function_decl|;
specifier|static
name|void
name|testFuncGetText
parameter_list|(
name|QInputDialog
modifier|*
name|dialog
parameter_list|)
function_decl|;
specifier|static
name|void
name|testFuncGetItem
parameter_list|(
name|QInputDialog
modifier|*
name|dialog
parameter_list|)
function_decl|;
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
function_decl|;
private|private
name|slots
private|:
name|void
name|getInt_data
parameter_list|()
function_decl|;
name|void
name|getInt
parameter_list|()
function_decl|;
name|void
name|getDouble_data
parameter_list|()
function_decl|;
name|void
name|getDouble
parameter_list|()
function_decl|;
name|void
name|task255502getDouble
parameter_list|()
function_decl|;
name|void
name|getText_data
parameter_list|()
function_decl|;
name|void
name|getText
parameter_list|()
function_decl|;
name|void
name|getItem_data
parameter_list|()
function_decl|;
name|void
name|getItem
parameter_list|()
function_decl|;
name|void
name|task256299_getTextReturnNullStringOnRejected
parameter_list|()
function_decl|;
name|void
name|inputMethodHintsOfChildWidget
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|stripFraction
name|QString
name|stripFraction
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|)
block|{
name|int
name|period
decl_stmt|;
if|if
condition|(
name|s
operator|.
name|contains
argument_list|(
literal|'.'
argument_list|)
condition|)
name|period
operator|=
name|s
operator|.
name|indexOf
argument_list|(
literal|'.'
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|s
operator|.
name|contains
argument_list|(
literal|','
argument_list|)
condition|)
name|period
operator|=
name|s
operator|.
name|indexOf
argument_list|(
literal|','
argument_list|)
expr_stmt|;
else|else
return|return
name|s
return|;
name|int
name|end
decl_stmt|;
for|for
control|(
name|end
operator|=
name|s
operator|.
name|size
argument_list|()
operator|-
literal|1
init|;
name|end
operator|>
name|period
operator|&&
name|s
index|[
name|end
index|]
operator|==
literal|'0'
condition|;
operator|--
name|end
control|)
empty_stmt|;
return|return
name|s
operator|.
name|left
argument_list|(
name|end
operator|+
operator|(
name|end
operator|==
name|period
condition|?
literal|0
else|:
literal|1
operator|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|normalizeNumericString
name|QString
name|normalizeNumericString
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|)
block|{
return|return
name|stripFraction
argument_list|(
name|s
argument_list|)
return|;
comment|// assumed to be sufficient
block|}
end_function
begin_function
DECL|function|_keyClick
name|void
name|_keyClick
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|char
name|key
parameter_list|)
block|{
name|QTest
operator|::
name|keyClick
argument_list|(
name|widget
argument_list|,
name|key
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_keyClick
name|void
name|_keyClick
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|Qt
operator|::
name|Key
name|key
parameter_list|)
block|{
name|QTest
operator|::
name|keyClick
argument_list|(
name|widget
argument_list|,
name|key
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|SpinBoxType
parameter_list|>
DECL|function|testTypingValue
name|void
name|testTypingValue
parameter_list|(
name|SpinBoxType
modifier|*
name|sbox
parameter_list|,
name|QPushButton
modifier|*
name|okButton
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
name|sbox
operator|->
name|selectAll
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
name|value
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QChar
name|valChar
init|=
name|value
index|[
name|i
index|]
decl_stmt|;
name|_keyClick
argument_list|(
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|sbox
argument_list|)
argument_list|,
name|valChar
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
comment|// ### always guaranteed to work?
if|if
condition|(
name|sbox
operator|->
name|hasAcceptableInput
argument_list|()
condition|)
name|QVERIFY
argument_list|(
name|okButton
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|QVERIFY
argument_list|(
operator|!
name|okButton
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|testTypingValue
name|void
name|testTypingValue
parameter_list|(
name|QLineEdit
modifier|*
name|ledit
parameter_list|,
name|QPushButton
modifier|*
name|okButton
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
name|ledit
operator|->
name|selectAll
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
name|value
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QChar
name|valChar
init|=
name|value
index|[
name|i
index|]
decl_stmt|;
name|_keyClick
argument_list|(
name|ledit
argument_list|,
name|valChar
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
comment|// ### always guaranteed to work?
name|QVERIFY
argument_list|(
name|ledit
operator|->
name|hasAcceptableInput
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|okButton
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|SpinBoxType
parameter_list|,
name|typename
name|ValueType
parameter_list|>
DECL|function|testInvalidateAndRestore
name|void
name|testInvalidateAndRestore
parameter_list|(
name|SpinBoxType
modifier|*
name|sbox
parameter_list|,
name|QPushButton
modifier|*
name|okButton
parameter_list|,
name|QLineEdit
modifier|*
name|ledit
parameter_list|,
name|ValueType
modifier|*
init|=
literal|0
parameter_list|)
block|{
specifier|const
name|ValueType
name|lastValidValue
init|=
name|sbox
operator|->
name|value
argument_list|()
decl_stmt|;
name|sbox
operator|->
name|selectAll
argument_list|()
expr_stmt|;
name|_keyClick
argument_list|(
name|ledit
argument_list|,
name|Qt
operator|::
name|Key_Delete
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|sbox
operator|->
name|hasAcceptableInput
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|okButton
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|_keyClick
argument_list|(
name|ledit
argument_list|,
name|Qt
operator|::
name|Key_Return
argument_list|)
expr_stmt|;
comment|// should work with Qt::Key_Enter too
name|QVERIFY
argument_list|(
name|sbox
operator|->
name|hasAcceptableInput
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|okButton
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sbox
operator|->
name|value
argument_list|()
argument_list|,
name|lastValidValue
argument_list|)
expr_stmt|;
name|QLocale
name|loc
decl_stmt|;
name|QCOMPARE
argument_list|(
name|normalizeNumericString
argument_list|(
name|ledit
operator|->
name|text
argument_list|()
argument_list|)
argument_list|,
name|normalizeNumericString
argument_list|(
name|loc
operator|.
name|toString
argument_list|(
name|sbox
operator|->
name|value
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|SpinBoxType
parameter_list|,
name|typename
name|ValueType
parameter_list|>
DECL|function|testGetNumeric
name|void
name|testGetNumeric
parameter_list|(
name|QInputDialog
modifier|*
name|dialog
parameter_list|,
name|SpinBoxType
modifier|*
init|=
literal|0
parameter_list|,
name|ValueType
modifier|*
init|=
literal|0
parameter_list|)
block|{
name|SpinBoxType
modifier|*
name|sbox
init|=
name|qFindChild
argument_list|<
name|SpinBoxType
operator|*
argument_list|>
argument_list|(
name|dialog
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|sbox
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QLineEdit
modifier|*
name|ledit
init|=
name|qFindChild
argument_list|<
name|QLineEdit
operator|*
argument_list|>
argument_list|(
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
name|sbox
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|ledit
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QDialogButtonBox
modifier|*
name|bbox
init|=
name|qFindChild
argument_list|<
name|QDialogButtonBox
operator|*
argument_list|>
argument_list|(
name|dialog
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|bbox
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|okButton
init|=
name|bbox
operator|->
name|button
argument_list|(
name|QDialogButtonBox
operator|::
name|Ok
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|okButton
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sbox
operator|->
name|value
argument_list|()
operator|>=
name|sbox
operator|->
name|minimum
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sbox
operator|->
name|value
argument_list|()
operator|<=
name|sbox
operator|->
name|maximum
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sbox
operator|->
name|hasAcceptableInput
argument_list|()
argument_list|)
expr_stmt|;
name|QLocale
name|loc
decl_stmt|;
name|QCOMPARE
argument_list|(
name|normalizeNumericString
argument_list|(
name|ledit
operator|->
name|selectedText
argument_list|()
argument_list|)
argument_list|,
name|normalizeNumericString
argument_list|(
name|loc
operator|.
name|toString
argument_list|(
name|sbox
operator|->
name|value
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|okButton
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|ValueType
name|origValue
init|=
name|sbox
operator|->
name|value
argument_list|()
decl_stmt|;
name|testInvalidateAndRestore
argument_list|<
name|SpinBoxType
argument_list|,
name|ValueType
argument_list|>
argument_list|(
name|sbox
argument_list|,
name|okButton
argument_list|,
name|ledit
argument_list|)
expr_stmt|;
name|testTypingValue
argument_list|<
name|SpinBoxType
argument_list|>
argument_list|(
name|sbox
argument_list|,
name|okButton
argument_list|,
name|QString
argument_list|(
literal|"%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|sbox
operator|->
name|minimum
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|testTypingValue
argument_list|<
name|SpinBoxType
argument_list|>
argument_list|(
name|sbox
argument_list|,
name|okButton
argument_list|,
name|QString
argument_list|(
literal|"%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|sbox
operator|->
name|maximum
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|testTypingValue
argument_list|<
name|SpinBoxType
argument_list|>
argument_list|(
name|sbox
argument_list|,
name|okButton
argument_list|,
name|QString
argument_list|(
literal|"%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|sbox
operator|->
name|minimum
argument_list|()
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|testTypingValue
argument_list|<
name|SpinBoxType
argument_list|>
argument_list|(
name|sbox
argument_list|,
name|okButton
argument_list|,
name|QString
argument_list|(
literal|"%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|sbox
operator|->
name|maximum
argument_list|()
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|testTypingValue
argument_list|<
name|SpinBoxType
argument_list|>
argument_list|(
name|sbox
argument_list|,
name|okButton
argument_list|,
literal|"0"
argument_list|)
expr_stmt|;
name|testTypingValue
argument_list|<
name|SpinBoxType
argument_list|>
argument_list|(
name|sbox
argument_list|,
name|okButton
argument_list|,
literal|"0.0"
argument_list|)
expr_stmt|;
name|testTypingValue
argument_list|<
name|SpinBoxType
argument_list|>
argument_list|(
name|sbox
argument_list|,
name|okButton
argument_list|,
literal|"foobar"
argument_list|)
expr_stmt|;
name|testTypingValue
argument_list|<
name|SpinBoxType
argument_list|>
argument_list|(
name|sbox
argument_list|,
name|okButton
argument_list|,
name|loc
operator|.
name|toString
argument_list|(
name|origValue
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testGetText
name|void
name|testGetText
parameter_list|(
name|QInputDialog
modifier|*
name|dialog
parameter_list|)
block|{
name|QLineEdit
modifier|*
name|ledit
init|=
name|qFindChild
argument_list|<
name|QLineEdit
operator|*
argument_list|>
argument_list|(
name|dialog
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|ledit
argument_list|)
expr_stmt|;
name|QDialogButtonBox
modifier|*
name|bbox
init|=
name|qFindChild
argument_list|<
name|QDialogButtonBox
operator|*
argument_list|>
argument_list|(
name|dialog
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|bbox
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|okButton
init|=
name|bbox
operator|->
name|button
argument_list|(
name|QDialogButtonBox
operator|::
name|Ok
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|okButton
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|ledit
operator|->
name|hasAcceptableInput
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ledit
operator|->
name|selectedText
argument_list|()
argument_list|,
name|ledit
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|okButton
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|origValue
init|=
name|ledit
operator|->
name|text
argument_list|()
decl_stmt|;
name|testTypingValue
argument_list|(
name|ledit
argument_list|,
name|okButton
argument_list|,
name|origValue
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testGetItem
name|void
name|testGetItem
parameter_list|(
name|QInputDialog
modifier|*
name|dialog
parameter_list|)
block|{
name|QComboBox
modifier|*
name|cbox
init|=
name|qFindChild
argument_list|<
name|QComboBox
operator|*
argument_list|>
argument_list|(
name|dialog
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|cbox
argument_list|)
expr_stmt|;
name|QDialogButtonBox
modifier|*
name|bbox
init|=
name|qFindChild
argument_list|<
name|QDialogButtonBox
operator|*
argument_list|>
argument_list|(
name|dialog
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|bbox
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|okButton
init|=
name|bbox
operator|->
name|button
argument_list|(
name|QDialogButtonBox
operator|::
name|Ok
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|okButton
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|okButton
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|int
name|origIndex
init|=
name|cbox
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|cbox
operator|->
name|setCurrentIndex
argument_list|(
name|origIndex
operator|-
literal|1
argument_list|)
expr_stmt|;
name|cbox
operator|->
name|setCurrentIndex
argument_list|(
name|origIndex
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|okButton
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testFuncGetInt
name|void
name|tst_QInputDialog
operator|::
name|testFuncGetInt
parameter_list|(
name|QInputDialog
modifier|*
name|dialog
parameter_list|)
block|{
name|testGetNumeric
argument_list|<
name|QSpinBox
argument_list|,
name|int
argument_list|>
argument_list|(
name|dialog
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testFuncGetDouble
name|void
name|tst_QInputDialog
operator|::
name|testFuncGetDouble
parameter_list|(
name|QInputDialog
modifier|*
name|dialog
parameter_list|)
block|{
name|testGetNumeric
argument_list|<
name|QDoubleSpinBox
argument_list|,
name|double
argument_list|>
argument_list|(
name|dialog
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testFuncGetText
name|void
name|tst_QInputDialog
operator|::
name|testFuncGetText
parameter_list|(
name|QInputDialog
modifier|*
name|dialog
parameter_list|)
block|{
operator|::
name|testGetText
argument_list|(
name|dialog
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testFuncGetItem
name|void
name|tst_QInputDialog
operator|::
name|testFuncGetItem
parameter_list|(
name|QInputDialog
modifier|*
name|dialog
parameter_list|)
block|{
operator|::
name|testGetItem
argument_list|(
name|dialog
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|tst_QInputDialog
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
block|{
name|killTimer
argument_list|(
name|event
operator|->
name|timerId
argument_list|()
argument_list|)
expr_stmt|;
name|QInputDialog
modifier|*
name|dialog
init|=
name|qFindChild
argument_list|<
name|QInputDialog
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|dialog
argument_list|)
expr_stmt|;
if|if
condition|(
name|testFunc
condition|)
name|testFunc
argument_list|(
name|dialog
argument_list|)
expr_stmt|;
name|dialog
operator|->
name|done
argument_list|(
name|doneCode
argument_list|)
expr_stmt|;
comment|// cause static function call to return
block|}
end_function
begin_function
DECL|function|getInt_data
name|void
name|tst_QInputDialog
operator|::
name|getInt_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"min"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"max"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getInt() - -"
argument_list|)
operator|<<
operator|-
literal|20
operator|<<
operator|-
literal|10
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getInt() - 0"
argument_list|)
operator|<<
operator|-
literal|20
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getInt() - +"
argument_list|)
operator|<<
operator|-
literal|20
operator|<<
literal|20
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getInt() 0 +"
argument_list|)
operator|<<
literal|0
operator|<<
literal|20
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getInt() + +"
argument_list|)
operator|<<
literal|10
operator|<<
literal|20
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getInt
name|void
name|tst_QInputDialog
operator|::
name|getInt
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|min
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|max
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|min
operator|<
name|max
argument_list|)
expr_stmt|;
name|parent
operator|=
operator|new
name|QWidget
expr_stmt|;
name|doneCode
operator|=
name|QDialog
operator|::
name|Accepted
expr_stmt|;
name|testFunc
operator|=
operator|&
name|tst_QInputDialog
operator|::
name|testFuncGetInt
expr_stmt|;
name|startTimer
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
literal|false
decl_stmt|;
specifier|const
name|int
name|value
init|=
name|min
operator|+
operator|(
name|max
operator|-
name|min
operator|)
operator|/
literal|2
decl_stmt|;
specifier|const
name|int
name|result
init|=
name|QInputDialog
operator|::
name|getInt
argument_list|(
name|parent
argument_list|,
literal|""
argument_list|,
literal|""
argument_list|,
name|value
argument_list|,
name|min
argument_list|,
name|max
argument_list|,
literal|1
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|value
argument_list|)
expr_stmt|;
operator|delete
name|parent
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getDouble_data
name|void
name|tst_QInputDialog
operator|::
name|getDouble_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|double
argument_list|>
argument_list|(
literal|"min"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|double
argument_list|>
argument_list|(
literal|"max"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"decimals"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() - - d0"
argument_list|)
operator|<<
operator|-
literal|20.0
operator|<<
operator|-
literal|10.0
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() - 0 d0"
argument_list|)
operator|<<
operator|-
literal|20.0
operator|<<
literal|0.0
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() - + d0"
argument_list|)
operator|<<
operator|-
literal|20.0
operator|<<
literal|20.0
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() 0 + d0"
argument_list|)
operator|<<
literal|0.0
operator|<<
literal|20.0
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() + + d0"
argument_list|)
operator|<<
literal|10.0
operator|<<
literal|20.0
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() - - d1"
argument_list|)
operator|<<
operator|-
literal|20.5
operator|<<
operator|-
literal|10.5
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() - 0 d1"
argument_list|)
operator|<<
operator|-
literal|20.5
operator|<<
literal|0.0
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() - + d1"
argument_list|)
operator|<<
operator|-
literal|20.5
operator|<<
literal|20.5
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() 0 + d1"
argument_list|)
operator|<<
literal|0.0
operator|<<
literal|20.5
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() + + d1"
argument_list|)
operator|<<
literal|10.5
operator|<<
literal|20.5
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() - - d2"
argument_list|)
operator|<<
operator|-
literal|20.05
operator|<<
operator|-
literal|10.05
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() - 0 d2"
argument_list|)
operator|<<
operator|-
literal|20.05
operator|<<
literal|0.0
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() - + d2"
argument_list|)
operator|<<
operator|-
literal|20.05
operator|<<
literal|20.05
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() 0 + d2"
argument_list|)
operator|<<
literal|0.0
operator|<<
literal|20.05
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getDouble() + + d2"
argument_list|)
operator|<<
literal|10.05
operator|<<
literal|20.05
operator|<<
literal|2
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getDouble
name|void
name|tst_QInputDialog
operator|::
name|getDouble
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|double
argument_list|,
name|min
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|double
argument_list|,
name|max
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|decimals
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|min
operator|<
name|max
operator|&&
name|decimals
operator|>=
literal|0
operator|&&
name|decimals
operator|<=
literal|13
argument_list|)
expr_stmt|;
name|parent
operator|=
operator|new
name|QWidget
expr_stmt|;
name|doneCode
operator|=
name|QDialog
operator|::
name|Accepted
expr_stmt|;
name|testFunc
operator|=
operator|&
name|tst_QInputDialog
operator|::
name|testFuncGetDouble
expr_stmt|;
name|startTimer
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
literal|false
decl_stmt|;
comment|// avoid decimals due to inconsistent roundoff behavior in QInputDialog::getDouble()
comment|// (at one decimal, 10.25 is rounded off to 10.2, while at two decimals, 10.025 is
comment|// rounded off to 10.03)
specifier|const
name|double
name|value
init|=
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|min
operator|+
operator|(
name|max
operator|-
name|min
operator|)
operator|/
literal|2
argument_list|)
decl_stmt|;
specifier|const
name|double
name|result
init|=
name|QInputDialog
operator|::
name|getDouble
argument_list|(
name|parent
argument_list|,
literal|""
argument_list|,
literal|""
argument_list|,
name|value
argument_list|,
name|min
argument_list|,
name|max
argument_list|,
name|decimals
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|value
argument_list|)
expr_stmt|;
operator|delete
name|parent
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task255502getDouble
name|void
name|tst_QInputDialog
operator|::
name|task255502getDouble
parameter_list|()
block|{
name|parent
operator|=
operator|new
name|QWidget
expr_stmt|;
name|doneCode
operator|=
name|QDialog
operator|::
name|Accepted
expr_stmt|;
name|testFunc
operator|=
operator|&
name|tst_QInputDialog
operator|::
name|testFuncGetDouble
expr_stmt|;
name|startTimer
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
literal|false
decl_stmt|;
specifier|const
name|double
name|value
init|=
literal|0.001
decl_stmt|;
specifier|const
name|double
name|result
init|=
name|QInputDialog
operator|::
name|getDouble
argument_list|(
name|parent
argument_list|,
literal|""
argument_list|,
literal|""
argument_list|,
name|value
argument_list|,
operator|-
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|value
argument_list|)
expr_stmt|;
operator|delete
name|parent
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getText_data
name|void
name|tst_QInputDialog
operator|::
name|getText_data
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
name|newRow
argument_list|(
literal|"getText() 1"
argument_list|)
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getText() 2"
argument_list|)
operator|<<
literal|"foobar"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getText() 3"
argument_list|)
operator|<<
literal|"  foobar"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getText() 4"
argument_list|)
operator|<<
literal|"foobar  "
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getText() 5"
argument_list|)
operator|<<
literal|"aAzZ`1234567890-=~!@#$%^&*()_+[]{}\\|;:'\",.<>/?"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getText
name|void
name|tst_QInputDialog
operator|::
name|getText
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|parent
operator|=
operator|new
name|QWidget
expr_stmt|;
name|doneCode
operator|=
name|QDialog
operator|::
name|Accepted
expr_stmt|;
name|testFunc
operator|=
operator|&
name|tst_QInputDialog
operator|::
name|testFuncGetText
expr_stmt|;
name|startTimer
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
literal|false
decl_stmt|;
specifier|const
name|QString
name|result
init|=
name|QInputDialog
operator|::
name|getText
argument_list|(
name|parent
argument_list|,
literal|""
argument_list|,
literal|""
argument_list|,
name|QLineEdit
operator|::
name|Normal
argument_list|,
name|text
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|text
argument_list|)
expr_stmt|;
operator|delete
name|parent
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task256299_getTextReturnNullStringOnRejected
name|void
name|tst_QInputDialog
operator|::
name|task256299_getTextReturnNullStringOnRejected
parameter_list|()
block|{
name|parent
operator|=
operator|new
name|QWidget
expr_stmt|;
name|doneCode
operator|=
name|QDialog
operator|::
name|Rejected
expr_stmt|;
name|testFunc
operator|=
literal|0
expr_stmt|;
name|startTimer
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
literal|true
decl_stmt|;
specifier|const
name|QString
name|result
init|=
name|QInputDialog
operator|::
name|getText
argument_list|(
name|parent
argument_list|,
literal|""
argument_list|,
literal|""
argument_list|,
name|QLineEdit
operator|::
name|Normal
argument_list|,
literal|"foobar"
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|ok
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|parent
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getItem_data
name|void
name|tst_QInputDialog
operator|::
name|getItem_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"items"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"editable"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getItem() 1 true"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|""
operator|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getItem() 2 true"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"spring"
operator|<<
literal|"summer"
operator|<<
literal|"fall"
operator|<<
literal|"winter"
operator|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getItem() 1 false"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|""
operator|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"getItem() 2 false"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"spring"
operator|<<
literal|"summer"
operator|<<
literal|"fall"
operator|<<
literal|"winter"
operator|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getItem
name|void
name|tst_QInputDialog
operator|::
name|getItem
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|items
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|editable
argument_list|)
expr_stmt|;
name|parent
operator|=
operator|new
name|QWidget
expr_stmt|;
name|doneCode
operator|=
name|QDialog
operator|::
name|Accepted
expr_stmt|;
name|testFunc
operator|=
operator|&
name|tst_QInputDialog
operator|::
name|testFuncGetItem
expr_stmt|;
name|startTimer
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
literal|false
decl_stmt|;
specifier|const
name|int
name|index
init|=
name|items
operator|.
name|size
argument_list|()
operator|/
literal|2
decl_stmt|;
specifier|const
name|QString
name|result
init|=
name|QInputDialog
operator|::
name|getItem
argument_list|(
name|parent
argument_list|,
literal|""
argument_list|,
literal|""
argument_list|,
name|items
argument_list|,
name|index
argument_list|,
name|editable
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|items
index|[
name|index
index|]
argument_list|)
expr_stmt|;
operator|delete
name|parent
expr_stmt|;
block|}
end_function
begin_function
DECL|function|inputMethodHintsOfChildWidget
name|void
name|tst_QInputDialog
operator|::
name|inputMethodHintsOfChildWidget
parameter_list|()
block|{
name|QInputDialog
name|dialog
decl_stmt|;
name|dialog
operator|.
name|setInputMode
argument_list|(
name|QInputDialog
operator|::
name|TextInput
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QObject
modifier|*
argument_list|>
name|children
init|=
name|dialog
operator|.
name|children
argument_list|()
decl_stmt|;
name|QLineEdit
modifier|*
name|editWidget
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|children
operator|.
name|size
argument_list|()
condition|;
name|c
operator|++
control|)
block|{
name|editWidget
operator|=
name|qobject_cast
argument_list|<
name|QLineEdit
operator|*
argument_list|>
argument_list|(
name|children
operator|.
name|at
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|editWidget
condition|)
break|break;
block|}
name|QVERIFY
argument_list|(
name|editWidget
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|editWidget
operator|->
name|inputMethodHints
argument_list|()
argument_list|,
name|dialog
operator|.
name|inputMethodHints
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|editWidget
operator|->
name|inputMethodHints
argument_list|()
argument_list|,
name|Qt
operator|::
name|ImhNone
argument_list|)
expr_stmt|;
name|dialog
operator|.
name|setInputMethodHints
argument_list|(
name|Qt
operator|::
name|ImhDigitsOnly
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|editWidget
operator|->
name|inputMethodHints
argument_list|()
argument_list|,
name|dialog
operator|.
name|inputMethodHints
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|editWidget
operator|->
name|inputMethodHints
argument_list|()
argument_list|,
name|Qt
operator|::
name|ImhDigitsOnly
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QInputDialog
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qinputdialog.moc"
end_include
end_unit
