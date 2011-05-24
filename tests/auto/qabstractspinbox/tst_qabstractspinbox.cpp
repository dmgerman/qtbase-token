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
file|<qabstractspinbox.h>
end_include
begin_include
include|#
directive|include
file|<qlineedit.h>
end_include
begin_include
include|#
directive|include
file|<qspinbox.h>
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_QAbstractSpinBox
class|class
name|tst_QAbstractSpinBox
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QAbstractSpinBox
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QAbstractSpinBox
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
comment|// task-specific tests below me:
name|void
name|task183108_clear
parameter_list|()
function_decl|;
name|void
name|task228728_cssselector
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QAbstractSpinBox
name|tst_QAbstractSpinBox
operator|::
name|tst_QAbstractSpinBox
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QAbstractSpinBox
name|tst_QAbstractSpinBox
operator|::
name|~
name|tst_QAbstractSpinBox
parameter_list|()
block|{ }
end_destructor
begin_class
DECL|class|MyAbstractSpinBox
class|class
name|MyAbstractSpinBox
super|:
specifier|public
name|QAbstractSpinBox
block|{
public|public:
DECL|function|MyAbstractSpinBox
name|MyAbstractSpinBox
parameter_list|()
member_init_list|:
name|QAbstractSpinBox
argument_list|()
block|{}
DECL|function|lineEdit
name|QLineEdit
modifier|*
name|lineEdit
parameter_list|()
block|{
return|return
name|QAbstractSpinBox
operator|::
name|lineEdit
argument_list|()
return|;
block|}
DECL|function|setLineEdit
name|void
name|setLineEdit
parameter_list|(
name|QLineEdit
modifier|*
name|le
parameter_list|)
block|{
name|QAbstractSpinBox
operator|::
name|setLineEdit
argument_list|(
name|le
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QAbstractSpinBox
operator|::
name|getSetCheck
parameter_list|()
block|{
name|MyAbstractSpinBox
name|obj1
decl_stmt|;
comment|// ButtonSymbols QAbstractSpinBox::buttonSymbols()
comment|// void QAbstractSpinBox::setButtonSymbols(ButtonSymbols)
name|obj1
operator|.
name|setButtonSymbols
argument_list|(
name|QAbstractSpinBox
operator|::
name|ButtonSymbols
argument_list|(
name|QAbstractSpinBox
operator|::
name|UpDownArrows
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QAbstractSpinBox
operator|::
name|ButtonSymbols
argument_list|(
name|QAbstractSpinBox
operator|::
name|UpDownArrows
argument_list|)
argument_list|,
name|obj1
operator|.
name|buttonSymbols
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setButtonSymbols
argument_list|(
name|QAbstractSpinBox
operator|::
name|ButtonSymbols
argument_list|(
name|QAbstractSpinBox
operator|::
name|PlusMinus
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QAbstractSpinBox
operator|::
name|ButtonSymbols
argument_list|(
name|QAbstractSpinBox
operator|::
name|PlusMinus
argument_list|)
argument_list|,
name|obj1
operator|.
name|buttonSymbols
argument_list|()
argument_list|)
expr_stmt|;
comment|// bool QAbstractSpinBox::wrapping()
comment|// void QAbstractSpinBox::setWrapping(bool)
name|obj1
operator|.
name|setWrapping
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|false
argument_list|,
name|obj1
operator|.
name|wrapping
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setWrapping
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|true
argument_list|,
name|obj1
operator|.
name|wrapping
argument_list|()
argument_list|)
expr_stmt|;
comment|// QLineEdit * QAbstractSpinBox::lineEdit()
comment|// void QAbstractSpinBox::setLineEdit(QLineEdit *)
name|QLineEdit
modifier|*
name|var3
init|=
operator|new
name|QLineEdit
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|obj1
operator|.
name|setLineEdit
argument_list|(
name|var3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|var3
argument_list|,
name|obj1
operator|.
name|lineEdit
argument_list|()
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_DEBUG
name|obj1
operator|.
name|setLineEdit
argument_list|(
operator|(
name|QLineEdit
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// Will assert in debug, so only test in release
name|QCOMPARE
argument_list|(
name|var3
argument_list|,
name|obj1
operator|.
name|lineEdit
argument_list|()
argument_list|)
expr_stmt|;
comment|// Setting 0 should keep the current editor
endif|#
directive|endif
comment|// delete var3; // No delete, since QAbstractSpinBox takes ownership
block|}
end_function
begin_function
DECL|function|task183108_clear
name|void
name|tst_QAbstractSpinBox
operator|::
name|task183108_clear
parameter_list|()
block|{
name|QAbstractSpinBox
modifier|*
name|sbox
decl_stmt|;
name|sbox
operator|=
operator|new
name|QSpinBox
expr_stmt|;
name|sbox
operator|->
name|clear
argument_list|()
expr_stmt|;
name|sbox
operator|->
name|show
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|sbox
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|sbox
expr_stmt|;
name|sbox
operator|=
operator|new
name|QSpinBox
expr_stmt|;
name|sbox
operator|->
name|clear
argument_list|()
expr_stmt|;
name|sbox
operator|->
name|show
argument_list|()
expr_stmt|;
name|sbox
operator|->
name|hide
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sbox
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|sbox
expr_stmt|;
name|sbox
operator|=
operator|new
name|QSpinBox
expr_stmt|;
name|sbox
operator|->
name|show
argument_list|()
expr_stmt|;
name|sbox
operator|->
name|clear
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sbox
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|sbox
expr_stmt|;
name|sbox
operator|=
operator|new
name|QSpinBox
expr_stmt|;
name|sbox
operator|->
name|show
argument_list|()
expr_stmt|;
name|sbox
operator|->
name|clear
argument_list|()
expr_stmt|;
name|sbox
operator|->
name|hide
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sbox
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|sbox
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task228728_cssselector
name|void
name|tst_QAbstractSpinBox
operator|::
name|task228728_cssselector
parameter_list|()
block|{
comment|//QAbstractSpinBox does some call to stylehint into his constructor.
comment|//so while the stylesheet want to access property, it should not crash
name|qApp
operator|->
name|setStyleSheet
argument_list|(
literal|"[alignement=\"1\"], [text=\"foo\"] { color:black; }"
argument_list|)
expr_stmt|;
name|QSpinBox
name|box
decl_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QAbstractSpinBox
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qabstractspinbox.moc"
end_include
end_unit
