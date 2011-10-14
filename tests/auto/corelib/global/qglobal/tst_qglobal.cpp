begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QGlobal
class|class
name|tst_QGlobal
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|qIsNull
parameter_list|()
function_decl|;
name|void
name|qInternalCallbacks
parameter_list|()
function_decl|;
name|void
name|for_each
parameter_list|()
function_decl|;
name|void
name|qassert
parameter_list|()
function_decl|;
name|void
name|qtry
parameter_list|()
function_decl|;
name|void
name|checkptr
parameter_list|()
function_decl|;
name|void
name|qstaticassert
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|qIsNull
name|void
name|tst_QGlobal
operator|::
name|qIsNull
parameter_list|()
block|{
name|double
name|d
init|=
literal|0.0
decl_stmt|;
name|float
name|f
init|=
literal|0.0f
decl_stmt|;
name|QVERIFY
argument_list|(
operator|::
name|qIsNull
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|::
name|qIsNull
argument_list|(
name|f
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|+=
literal|0.000000001
expr_stmt|;
name|f
operator|+=
literal|0.0000001f
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|::
name|qIsNull
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|::
name|qIsNull
argument_list|(
name|f
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_struct
DECL|struct|ConnectInfo
struct|struct
name|ConnectInfo
block|{
DECL|member|sender
name|QObject
modifier|*
name|sender
decl_stmt|;
DECL|member|receiver
name|QObject
modifier|*
name|receiver
decl_stmt|;
DECL|member|signal
DECL|member|slot
name|QString
name|signal
decl_stmt|,
name|slot
decl_stmt|;
DECL|member|type
name|int
name|type
decl_stmt|;
DECL|function|reset
name|void
name|reset
parameter_list|()
block|{
name|sender
operator|=
name|receiver
operator|=
literal|0
expr_stmt|;
name|signal
operator|=
name|slot
operator|=
name|QString
argument_list|()
expr_stmt|;
name|type
operator|=
operator|-
literal|1
expr_stmt|;
block|}
block|}
DECL|variable|connect_info
name|connect_info
struct|;
end_struct
begin_function
DECL|function|disconnect_callback
name|bool
name|disconnect_callback
parameter_list|(
name|void
modifier|*
modifier|*
name|data
parameter_list|)
block|{
name|connect_info
operator|.
name|sender
operator|=
operator|(
name|QObject
operator|*
operator|)
operator|(
name|data
index|[
literal|0
index|]
operator|)
expr_stmt|;
name|connect_info
operator|.
name|receiver
operator|=
operator|(
name|QObject
operator|*
operator|)
operator|(
name|data
index|[
literal|2
index|]
operator|)
expr_stmt|;
name|connect_info
operator|.
name|signal
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|data
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|connect_info
operator|.
name|slot
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|data
index|[
literal|3
index|]
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|connect_callback
name|bool
name|connect_callback
parameter_list|(
name|void
modifier|*
modifier|*
name|data
parameter_list|)
block|{
name|disconnect_callback
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|connect_info
operator|.
name|type
operator|=
operator|*
operator|(
name|int
operator|*
operator|)
name|data
index|[
literal|4
index|]
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|qInternalCallbacks
name|void
name|tst_QGlobal
operator|::
name|qInternalCallbacks
parameter_list|()
block|{
name|QInternal
operator|::
name|registerCallback
argument_list|(
name|QInternal
operator|::
name|ConnectCallback
argument_list|,
name|connect_callback
argument_list|)
expr_stmt|;
name|QInternal
operator|::
name|registerCallback
argument_list|(
name|QInternal
operator|::
name|DisconnectCallback
argument_list|,
name|disconnect_callback
argument_list|)
expr_stmt|;
name|QObject
name|a
decl_stmt|,
name|b
decl_stmt|;
name|QString
name|signal
init|=
name|QLatin1String
argument_list|(
literal|"2mysignal(x)"
argument_list|)
decl_stmt|;
name|QString
name|slot
init|=
name|QLatin1String
argument_list|(
literal|"1myslot(x)"
argument_list|)
decl_stmt|;
comment|// Test that connect works as expected...
name|connect_info
operator|.
name|reset
argument_list|()
expr_stmt|;
name|bool
name|ok
init|=
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|a
argument_list|,
name|signal
operator|.
name|toLatin1
argument_list|()
argument_list|,
operator|&
name|b
argument_list|,
name|slot
operator|.
name|toLatin1
argument_list|()
argument_list|,
name|Qt
operator|::
name|AutoConnection
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|&
name|a
argument_list|,
name|connect_info
operator|.
name|sender
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|&
name|b
argument_list|,
name|connect_info
operator|.
name|receiver
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|signal
argument_list|,
name|connect_info
operator|.
name|signal
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|slot
argument_list|,
name|connect_info
operator|.
name|slot
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|int
operator|)
name|Qt
operator|::
name|AutoConnection
argument_list|,
name|connect_info
operator|.
name|type
argument_list|)
expr_stmt|;
comment|// Test that disconnect works as expected
name|connect_info
operator|.
name|reset
argument_list|()
expr_stmt|;
name|ok
operator|=
name|QObject
operator|::
name|disconnect
argument_list|(
operator|&
name|a
argument_list|,
name|signal
operator|.
name|toLatin1
argument_list|()
argument_list|,
operator|&
name|b
argument_list|,
name|slot
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|&
name|a
argument_list|,
name|connect_info
operator|.
name|sender
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|&
name|b
argument_list|,
name|connect_info
operator|.
name|receiver
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|signal
argument_list|,
name|connect_info
operator|.
name|signal
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|slot
argument_list|,
name|connect_info
operator|.
name|slot
argument_list|)
expr_stmt|;
comment|// Unregister callbacks and verify that they are not triggered...
name|QInternal
operator|::
name|unregisterCallback
argument_list|(
name|QInternal
operator|::
name|ConnectCallback
argument_list|,
name|connect_callback
argument_list|)
expr_stmt|;
name|QInternal
operator|::
name|unregisterCallback
argument_list|(
name|QInternal
operator|::
name|DisconnectCallback
argument_list|,
name|disconnect_callback
argument_list|)
expr_stmt|;
name|connect_info
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"Object::connect: No such signal QObject::mysignal(x)"
argument_list|)
expr_stmt|;
name|ok
operator|=
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|a
argument_list|,
name|signal
operator|.
name|toLatin1
argument_list|()
argument_list|,
operator|&
name|b
argument_list|,
name|slot
operator|.
name|toLatin1
argument_list|()
argument_list|,
name|Qt
operator|::
name|AutoConnection
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|ok
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|connect_info
operator|.
name|sender
argument_list|,
operator|(
name|QObject
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"Object::disconnect: No such signal QObject::mysignal(x)"
argument_list|)
expr_stmt|;
name|ok
operator|=
name|QObject
operator|::
name|disconnect
argument_list|(
operator|&
name|a
argument_list|,
name|signal
operator|.
name|toLatin1
argument_list|()
argument_list|,
operator|&
name|b
argument_list|,
name|slot
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|ok
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|connect_info
operator|.
name|sender
argument_list|,
operator|(
name|QObject
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|for_each
name|void
name|tst_QGlobal
operator|::
name|for_each
parameter_list|()
block|{
name|QList
argument_list|<
name|int
argument_list|>
name|list
decl_stmt|;
name|list
operator|<<
literal|0
operator|<<
literal|1
operator|<<
literal|2
operator|<<
literal|3
operator|<<
literal|4
operator|<<
literal|5
expr_stmt|;
name|int
name|counter
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|int
name|i
decl|,
name|list
control|)
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
name|counter
operator|++
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|counter
argument_list|,
name|list
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
comment|// do it again, to make sure we don't have any for-scoping
comment|// problems with older compilers
name|counter
operator|=
literal|0
expr_stmt|;
foreach|foreach
control|(
name|int
name|i
decl|,
name|list
control|)
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
name|counter
operator|++
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|counter
argument_list|,
name|list
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qassert
name|void
name|tst_QGlobal
operator|::
name|qassert
parameter_list|()
block|{
name|bool
name|passed
init|=
literal|false
decl_stmt|;
if|if
condition|(
literal|false
condition|)
block|{
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|passed
operator|=
literal|true
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|passed
argument_list|)
expr_stmt|;
name|passed
operator|=
literal|false
expr_stmt|;
if|if
condition|(
literal|false
condition|)
block|{
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"tst_QGlobal"
argument_list|,
literal|"qassert"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|passed
operator|=
literal|true
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|passed
argument_list|)
expr_stmt|;
name|passed
operator|=
literal|false
expr_stmt|;
if|if
condition|(
literal|false
condition|)
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
else|else
name|passed
operator|=
literal|true
expr_stmt|;
name|QVERIFY
argument_list|(
name|passed
argument_list|)
expr_stmt|;
name|passed
operator|=
literal|false
expr_stmt|;
if|if
condition|(
literal|false
condition|)
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"tst_QGlobal"
argument_list|,
literal|"qassert"
argument_list|)
expr_stmt|;
else|else
name|passed
operator|=
literal|true
expr_stmt|;
name|QVERIFY
argument_list|(
name|passed
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qtry
name|void
name|tst_QGlobal
operator|::
name|qtry
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
name|QT_TRY
block|{
name|i
operator|=
literal|1
expr_stmt|;
name|QT_THROW
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|i
operator|=
literal|2
expr_stmt|;
block|}
name|QT_CATCH
argument_list|(
argument|int
argument_list|)
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|i
operator|=
literal|7
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QT_NO_EXCEPTIONS
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
else|#
directive|else
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|7
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// check propper if/else scoping
name|i
operator|=
literal|0
expr_stmt|;
if|if
condition|(
literal|true
condition|)
block|{
name|QT_TRY
block|{
name|i
operator|=
literal|2
expr_stmt|;
name|QT_THROW
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|i
operator|=
literal|4
expr_stmt|;
block|}
name|QT_CATCH
argument_list|(
argument|int
argument_list|)
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|i
operator|=
literal|4
expr_stmt|;
block|}
block|}
else|else
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
if|if
condition|(
literal|false
condition|)
block|{
name|QT_TRY
block|{
name|i
operator|=
literal|2
expr_stmt|;
name|QT_THROW
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|i
operator|=
literal|4
expr_stmt|;
block|}
name|QT_CATCH
argument_list|(
argument|int
argument_list|)
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|i
operator|=
literal|2
expr_stmt|;
block|}
block|}
else|else
block|{
name|i
operator|=
literal|8
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
if|if
condition|(
literal|false
condition|)
block|{
name|i
operator|=
literal|42
expr_stmt|;
block|}
else|else
block|{
name|QT_TRY
block|{
name|i
operator|=
literal|2
expr_stmt|;
name|QT_THROW
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|i
operator|=
literal|4
expr_stmt|;
block|}
name|QT_CATCH
argument_list|(
argument|int
argument_list|)
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|i
operator|=
literal|4
expr_stmt|;
block|}
block|}
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkptr
name|void
name|tst_QGlobal
operator|::
name|checkptr
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|QCOMPARE
argument_list|(
name|q_check_ptr
argument_list|(
operator|&
name|i
argument_list|)
argument_list|,
operator|&
name|i
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|c
init|=
literal|"hello"
decl_stmt|;
name|QCOMPARE
argument_list|(
name|q_check_ptr
argument_list|(
name|c
argument_list|)
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Check Q_STATIC_ASSERT, It should compile
end_comment
begin_comment
comment|// note that, we are not able to test Q_STATIC_ASSERT(false), to do it manually someone has
end_comment
begin_comment
comment|// to replace expressions (in the asserts) one by one to false, and check if it breaks build.
end_comment
begin_class
DECL|class|MyTrue
class|class
name|MyTrue
block|{
public|public:
DECL|function|MyTrue
name|MyTrue
parameter_list|()
block|{
name|Q_STATIC_ASSERT
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
operator|!
literal|false
argument_list|)
expr_stmt|;
block|}
DECL|function|~MyTrue
name|~
name|MyTrue
parameter_list|()
block|{
name|Q_STATIC_ASSERT
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
operator|!
literal|false
argument_list|)
expr_stmt|;
block|}
name|Q_STATIC_ASSERT
argument_list|(
literal|true
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
argument|!
literal|false
argument_list|)
empty_stmt|;
block|}
class|;
end_class
begin_struct
DECL|struct|MyExpresion
struct|struct
name|MyExpresion
block|{
DECL|function|foo
name|void
name|foo
parameter_list|()
block|{
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|MyTrue
argument_list|)
operator|>
literal|0
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|MyTrue
argument_list|)
operator|>
literal|0
argument_list|)
expr_stmt|;
block|}
private|private:
name|Q_STATIC_ASSERT
argument_list|(
argument|sizeof(MyTrue)>
literal|0
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
argument|sizeof(MyTrue)>
literal|0
argument_list|)
empty_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|TypeDef
struct|struct
name|TypeDef
block|{
DECL|typedef|T
typedef|typedef
name|int
name|T
typedef|;
name|Q_STATIC_ASSERT
argument_list|(
argument|sizeof(T)
argument_list|)
empty_stmt|;
block|}
struct|;
end_struct
begin_struct
template|template
parameter_list|<
name|typename
name|T1
parameter_list|,
name|typename
name|T2
parameter_list|>
struct|struct
DECL|struct|Template
name|Template
block|{
DECL|member|True
specifier|static
specifier|const
name|bool
name|True
init|=
literal|true
decl_stmt|;
DECL|typedef|DependentType
typedef|typedef
typename|typename
name|T1
operator|::
name|T
name|DependentType
typedef|;
name|Q_STATIC_ASSERT
parameter_list|(
name|True
parameter_list|)
constructor_decl|;
name|Q_STATIC_ASSERT
argument_list|(
argument|!!True
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
argument|sizeof(DependentType)
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
argument|!!sizeof(DependentType)
argument_list|)
empty_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|MyTemplate
struct|struct
name|MyTemplate
block|{
name|Q_STATIC_ASSERT
parameter_list|(
name|Template
argument_list|<
name|TypeDef
argument_list|,
name|int
argument_list|>
operator|::
name|True
parameter_list|)
constructor_decl|;
name|Q_STATIC_ASSERT
argument_list|(
argument|!!Template<TypeDef
argument_list|,
argument|int>::True
argument_list|)
empty_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|qstaticassert
name|void
name|tst_QGlobal
operator|::
name|qstaticassert
parameter_list|()
block|{
comment|// Force compilation of these classes
name|MyTrue
name|tmp1
decl_stmt|;
name|MyExpresion
name|tmp2
decl_stmt|;
name|MyTemplate
name|tmp3
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|tmp1
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|tmp2
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|tmp3
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|// if the test compiles it has passed.
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGlobal
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qglobal.moc"
end_include
end_unit
