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
file|<QtCore/QScopedPointer>
end_include
begin_comment
comment|/*!  \class tst_QScopedPointer  \internal  \since 4.6  \brief Tests class QScopedPointer.   */
end_comment
begin_class
DECL|class|tst_QScopedPointer
class|class
name|tst_QScopedPointer
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|Q_SLOTS
private|:
name|void
name|defaultConstructor
parameter_list|()
function_decl|;
name|void
name|dataOnDefaultConstructed
parameter_list|()
function_decl|;
name|void
name|useSubClassInConstructor
parameter_list|()
function_decl|;
name|void
name|dataOnValue
parameter_list|()
function_decl|;
name|void
name|dataSignature
parameter_list|()
function_decl|;
name|void
name|reset
parameter_list|()
function_decl|;
name|void
name|dereferenceOperator
parameter_list|()
function_decl|;
name|void
name|dereferenceOperatorSignature
parameter_list|()
function_decl|;
name|void
name|pointerOperator
parameter_list|()
function_decl|;
name|void
name|pointerOperatorSignature
parameter_list|()
function_decl|;
name|void
name|negationOperator
parameter_list|()
function_decl|;
name|void
name|negationOperatorSignature
parameter_list|()
function_decl|;
name|void
name|operatorBool
parameter_list|()
function_decl|;
name|void
name|operatorBoolSignature
parameter_list|()
function_decl|;
name|void
name|isNull
parameter_list|()
function_decl|;
name|void
name|isNullSignature
parameter_list|()
function_decl|;
name|void
name|objectSize
parameter_list|()
function_decl|;
name|void
name|comparison
parameter_list|()
function_decl|;
name|void
name|array
parameter_list|()
function_decl|;
comment|// TODO instanciate on const object
block|}
class|;
end_class
begin_function
DECL|function|defaultConstructor
name|void
name|tst_QScopedPointer
operator|::
name|defaultConstructor
parameter_list|()
block|{
comment|/* Check that the members, one, is correctly initialized. */
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p
operator|.
name|data
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|int
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dataOnDefaultConstructed
name|void
name|tst_QScopedPointer
operator|::
name|dataOnDefaultConstructed
parameter_list|()
block|{
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p
operator|.
name|data
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|int
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|MyClass
class|class
name|MyClass
block|{
block|}
class|;
end_class
begin_class
DECL|class|MySubClass
class|class
name|MySubClass
super|:
specifier|public
name|MyClass
block|{
block|}
class|;
end_class
begin_function
DECL|function|useSubClassInConstructor
name|void
name|tst_QScopedPointer
operator|::
name|useSubClassInConstructor
parameter_list|()
block|{
comment|/* Use a syntax which users typically would do. */
name|QScopedPointer
argument_list|<
name|MyClass
argument_list|>
name|p
argument_list|(
operator|new
name|MyClass
argument_list|()
argument_list|)
decl_stmt|;
block|}
end_function
begin_function
DECL|function|dataOnValue
name|void
name|tst_QScopedPointer
operator|::
name|dataOnValue
parameter_list|()
block|{
name|int
modifier|*
specifier|const
name|rawPointer
init|=
operator|new
name|int
argument_list|(
literal|5
argument_list|)
decl_stmt|;
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
argument_list|(
name|rawPointer
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p
operator|.
name|data
argument_list|()
argument_list|,
name|rawPointer
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dataSignature
name|void
name|tst_QScopedPointer
operator|::
name|dataSignature
parameter_list|()
block|{
specifier|const
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
decl_stmt|;
comment|/* data() should be const. */
name|p
operator|.
name|data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|tst_QScopedPointer
operator|::
name|reset
parameter_list|()
block|{
comment|/* Call reset() on a default constructed value. */
block|{
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
decl_stmt|;
name|p
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p
operator|.
name|data
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|int
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* Call reset() on an active value. */
block|{
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
argument_list|(
operator|new
name|int
argument_list|(
literal|3
argument_list|)
argument_list|)
decl_stmt|;
name|p
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p
operator|.
name|data
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|int
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* Call reset() with a value, on an active value. */
block|{
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
argument_list|(
operator|new
name|int
argument_list|(
literal|3
argument_list|)
argument_list|)
decl_stmt|;
name|int
modifier|*
specifier|const
name|value
init|=
operator|new
name|int
argument_list|(
literal|9
argument_list|)
decl_stmt|;
name|p
operator|.
name|reset
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|*
name|p
operator|.
name|data
argument_list|()
argument_list|,
literal|9
argument_list|)
expr_stmt|;
block|}
comment|/* Call reset() with a value, on default constructed value. */
block|{
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
decl_stmt|;
name|int
modifier|*
specifier|const
name|value
init|=
operator|new
name|int
argument_list|(
literal|9
argument_list|)
decl_stmt|;
name|p
operator|.
name|reset
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|*
name|p
operator|.
name|data
argument_list|()
argument_list|,
literal|9
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_class
DECL|class|AbstractClass
class|class
name|AbstractClass
block|{
public|public:
DECL|function|~AbstractClass
specifier|virtual
name|~
name|AbstractClass
parameter_list|()
block|{     }
specifier|virtual
name|int
name|member
parameter_list|()
specifier|const
function_decl|=
literal|0
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|SubClass
class|class
name|SubClass
super|:
specifier|public
name|AbstractClass
block|{
public|public:
DECL|function|member
specifier|virtual
name|int
name|member
parameter_list|()
specifier|const
block|{
return|return
literal|5
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|dereferenceOperator
name|void
name|tst_QScopedPointer
operator|::
name|dereferenceOperator
parameter_list|()
block|{
comment|/* Dereference a basic value. */
block|{
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
argument_list|(
operator|new
name|int
argument_list|(
literal|5
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|int
name|value2
init|=
operator|*
name|p
decl_stmt|;
name|QCOMPARE
argument_list|(
name|value2
argument_list|,
literal|5
argument_list|)
expr_stmt|;
block|}
comment|/* Dereference a pointer to an abstract class. This verifies      * that the operator returns a reference, when compiling      * with MSVC 2005. */
block|{
name|QScopedPointer
argument_list|<
name|AbstractClass
argument_list|>
name|p
argument_list|(
operator|new
name|SubClass
argument_list|()
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
operator|(
operator|*
name|p
operator|)
operator|.
name|member
argument_list|()
argument_list|,
literal|5
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|dereferenceOperatorSignature
name|void
name|tst_QScopedPointer
operator|::
name|dereferenceOperatorSignature
parameter_list|()
block|{
comment|/* The operator should be const. */
block|{
specifier|const
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
argument_list|(
operator|new
name|int
argument_list|(
literal|5
argument_list|)
argument_list|)
decl_stmt|;
operator|*
name|p
expr_stmt|;
block|}
comment|/* A reference should be returned, not a value. */
block|{
specifier|const
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
argument_list|(
operator|new
name|int
argument_list|(
literal|5
argument_list|)
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
cast|static_cast
argument_list|<
name|int
operator|&
argument_list|>
argument_list|(
operator|*
name|p
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* Instantiated on a const object, the returned object is a const reference. */
block|{
specifier|const
name|QScopedPointer
argument_list|<
specifier|const
name|int
argument_list|>
name|p
argument_list|(
operator|new
name|int
argument_list|(
literal|5
argument_list|)
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|int
operator|&
argument_list|>
argument_list|(
operator|*
name|p
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_class
DECL|class|AnyForm
class|class
name|AnyForm
block|{
public|public:
DECL|member|value
name|int
name|value
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|pointerOperator
name|void
name|tst_QScopedPointer
operator|::
name|pointerOperator
parameter_list|()
block|{
name|QScopedPointer
argument_list|<
name|AnyForm
argument_list|>
name|p
argument_list|(
operator|new
name|AnyForm
argument_list|()
argument_list|)
decl_stmt|;
name|p
operator|->
name|value
operator|=
literal|5
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p
operator|->
name|value
argument_list|,
literal|5
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pointerOperatorSignature
name|void
name|tst_QScopedPointer
operator|::
name|pointerOperatorSignature
parameter_list|()
block|{
comment|/* The operator should be const. */
specifier|const
name|QScopedPointer
argument_list|<
name|AnyForm
argument_list|>
name|p
argument_list|(
operator|new
name|AnyForm
argument_list|)
decl_stmt|;
name|p
operator|->
name|value
operator|=
literal|5
expr_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|->
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|negationOperator
name|void
name|tst_QScopedPointer
operator|::
name|negationOperator
parameter_list|()
block|{
comment|/* Invoke on default constructed value. */
block|{
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|p
argument_list|)
expr_stmt|;
block|}
comment|/* Invoke on a value. */
block|{
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
argument_list|(
operator|new
name|int
argument_list|(
literal|2
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
operator|!
name|p
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|negationOperatorSignature
name|void
name|tst_QScopedPointer
operator|::
name|negationOperatorSignature
parameter_list|()
block|{
comment|/* The signature should be const. */
specifier|const
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
decl_stmt|;
operator|!
name|p
expr_stmt|;
comment|/* The return value should be bool. */
cast|static_cast
argument_list|<
name|bool
argument_list|>
argument_list|(
operator|!
name|p
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operatorBool
name|void
name|tst_QScopedPointer
operator|::
name|operatorBool
parameter_list|()
block|{
comment|/* Invoke on default constructed value. */
block|{
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
decl_stmt|;
name|QCOMPARE
argument_list|(
name|bool
argument_list|(
name|p
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
comment|/* Invoke on active value. */
block|{
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
argument_list|(
operator|new
name|int
argument_list|(
literal|3
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|operatorBoolSignature
name|void
name|tst_QScopedPointer
operator|::
name|operatorBoolSignature
parameter_list|()
block|{
comment|/* The signature should be const and return bool. */
specifier|const
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
decl_stmt|;
operator|(
name|void
operator|)
cast|static_cast
argument_list|<
name|bool
argument_list|>
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isNull
name|void
name|tst_QScopedPointer
operator|::
name|isNull
parameter_list|()
block|{
comment|/* Invoke on default constructed value. */
block|{
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
decl_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/* Invoke on a set value. */
block|{
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
argument_list|(
operator|new
name|int
argument_list|(
literal|69
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|p
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isNullSignature
name|void
name|tst_QScopedPointer
operator|::
name|isNullSignature
parameter_list|()
block|{
specifier|const
name|QScopedPointer
argument_list|<
name|int
argument_list|>
name|p
argument_list|(
operator|new
name|int
argument_list|(
literal|69
argument_list|)
argument_list|)
decl_stmt|;
comment|/* The signature should be const and return bool. */
cast|static_cast
argument_list|<
name|bool
argument_list|>
argument_list|(
name|p
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|objectSize
name|void
name|tst_QScopedPointer
operator|::
name|objectSize
parameter_list|()
block|{
comment|/* The size of QScopedPointer should be the same as one pointer. */
name|QCOMPARE
argument_list|(
sizeof|sizeof
argument_list|(
name|QScopedPointer
argument_list|<
name|int
argument_list|>
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_struct
DECL|struct|RefCounted
struct|struct
name|RefCounted
block|{
DECL|function|RefCounted
name|RefCounted
parameter_list|()
member_init_list|:
name|ref
argument_list|(
literal|0
argument_list|)
block|{
name|instanceCount
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
DECL|function|RefCounted
name|RefCounted
parameter_list|(
name|RefCounted
specifier|const
modifier|&
parameter_list|)
member_init_list|:
name|ref
argument_list|(
literal|0
argument_list|)
block|{
name|instanceCount
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
DECL|function|~RefCounted
name|~
name|RefCounted
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|ref
operator|.
name|load
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|instanceCount
operator|.
name|deref
argument_list|()
expr_stmt|;
block|}
DECL|function|operator =
name|RefCounted
modifier|&
name|operator
name|=
parameter_list|(
name|RefCounted
specifier|const
modifier|&
parameter_list|)
block|{
return|return
operator|*
name|this
return|;
block|}
DECL|member|ref
name|QAtomicInt
name|ref
decl_stmt|;
DECL|member|instanceCount
specifier|static
name|QAtomicInt
name|instanceCount
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|member|instanceCount
name|QAtomicInt
name|RefCounted
operator|::
name|instanceCount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
template|template
parameter_list|<
name|class
name|A1
parameter_list|,
name|class
name|A2
parameter_list|,
name|class
name|B
parameter_list|>
DECL|function|scopedPointerComparisonTest
name|void
name|scopedPointerComparisonTest
parameter_list|(
specifier|const
name|A1
modifier|&
name|a1
parameter_list|,
specifier|const
name|A2
modifier|&
name|a2
parameter_list|,
specifier|const
name|B
modifier|&
name|b
parameter_list|)
block|{
comment|// test equality on equal pointers
name|QVERIFY
argument_list|(
name|a1
operator|==
name|a2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|a2
operator|==
name|a1
argument_list|)
expr_stmt|;
comment|// test inequality on equal pointers
name|QVERIFY
argument_list|(
operator|!
operator|(
name|a1
operator|!=
name|a2
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|a2
operator|!=
name|a1
operator|)
argument_list|)
expr_stmt|;
comment|// test equality on unequal pointers
name|QVERIFY
argument_list|(
operator|!
operator|(
name|a1
operator|==
name|b
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|a2
operator|==
name|b
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|b
operator|==
name|a1
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|b
operator|==
name|a2
operator|)
argument_list|)
expr_stmt|;
comment|// test inequality on unequal pointers
name|QVERIFY
argument_list|(
name|b
operator|!=
name|a1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|b
operator|!=
name|a2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|a1
operator|!=
name|b
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|a2
operator|!=
name|b
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|comparison
name|void
name|tst_QScopedPointer
operator|::
name|comparison
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|{
name|RefCounted
modifier|*
name|a
init|=
operator|new
name|RefCounted
decl_stmt|;
name|RefCounted
modifier|*
name|b
init|=
operator|new
name|RefCounted
decl_stmt|;
name|QCOMPARE
argument_list|(
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QScopedPointer
argument_list|<
name|RefCounted
argument_list|>
name|pa1
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|QScopedPointer
argument_list|<
name|RefCounted
argument_list|>
name|pa2
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|QScopedPointer
argument_list|<
name|RefCounted
argument_list|>
name|pb
argument_list|(
name|b
argument_list|)
decl_stmt|;
name|scopedPointerComparisonTest
argument_list|(
name|pa1
argument_list|,
name|pa1
argument_list|,
name|pb
argument_list|)
expr_stmt|;
name|scopedPointerComparisonTest
argument_list|(
name|pa2
argument_list|,
name|pa2
argument_list|,
name|pb
argument_list|)
expr_stmt|;
name|scopedPointerComparisonTest
argument_list|(
name|pa1
argument_list|,
name|pa2
argument_list|,
name|pb
argument_list|)
expr_stmt|;
name|pa2
operator|.
name|take
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|{
name|RefCounted
modifier|*
name|a
init|=
operator|new
name|RefCounted
index|[
literal|42
index|]
decl_stmt|;
name|RefCounted
modifier|*
name|b
init|=
operator|new
name|RefCounted
index|[
literal|43
index|]
decl_stmt|;
name|QCOMPARE
argument_list|(
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|,
literal|85
argument_list|)
expr_stmt|;
name|QScopedArrayPointer
argument_list|<
name|RefCounted
argument_list|>
name|pa1
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|QScopedArrayPointer
argument_list|<
name|RefCounted
argument_list|>
name|pa2
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|QScopedArrayPointer
argument_list|<
name|RefCounted
argument_list|>
name|pb
argument_list|(
name|b
argument_list|)
decl_stmt|;
name|scopedPointerComparisonTest
argument_list|(
name|pa1
argument_list|,
name|pa2
argument_list|,
name|pb
argument_list|)
expr_stmt|;
name|pa2
operator|.
name|take
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|,
literal|85
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|{
comment|// QScopedSharedPointer is an internal helper class -- it is unsupported!
name|RefCounted
modifier|*
name|a
init|=
operator|new
name|RefCounted
decl_stmt|;
name|RefCounted
modifier|*
name|b
init|=
operator|new
name|RefCounted
decl_stmt|;
name|QCOMPARE
argument_list|(
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QSharedDataPointer
argument_list|<
name|RefCounted
argument_list|>
name|pa1
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|QSharedDataPointer
argument_list|<
name|RefCounted
argument_list|>
name|pa2
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|QSharedDataPointer
argument_list|<
name|RefCounted
argument_list|>
name|pb
argument_list|(
name|b
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|a
operator|->
name|ref
operator|.
name|load
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|b
operator|->
name|ref
operator|.
name|load
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|scopedPointerComparisonTest
argument_list|(
name|pa1
argument_list|,
name|pa2
argument_list|,
name|pb
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|array
name|void
name|tst_QScopedPointer
operator|::
name|array
parameter_list|()
block|{
name|int
name|instCount
init|=
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
decl_stmt|;
block|{
name|QScopedArrayPointer
argument_list|<
name|RefCounted
argument_list|>
name|array
decl_stmt|;
name|array
operator|.
name|reset
argument_list|(
operator|new
name|RefCounted
index|[
literal|42
index|]
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|instCount
operator|+
literal|42
argument_list|,
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|instCount
argument_list|,
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
block|{
name|QScopedArrayPointer
argument_list|<
name|RefCounted
argument_list|>
name|array
argument_list|(
operator|new
name|RefCounted
index|[
literal|42
index|]
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|instCount
operator|+
literal|42
argument_list|,
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
name|array
operator|.
name|reset
argument_list|(
operator|new
name|RefCounted
index|[
literal|28
index|]
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|instCount
operator|+
literal|28
argument_list|,
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
name|array
operator|.
name|reset
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|instCount
argument_list|,
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|instCount
argument_list|,
name|RefCounted
operator|::
name|instanceCount
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QScopedPointer
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qscopedpointer.moc"
end_include
end_unit
