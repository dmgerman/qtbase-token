begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2014 Olivier Goffart<ogoffart@woboq.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<qmetaobject.h>
end_include
begin_class
DECL|class|tst_QMetaProperty
class|class
name|tst_QMetaProperty
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
name|EnumType
name|value
name|WRITE
name|setValue
name|READ
name|getValue
argument_list|)
name|Q_PROPERTY
argument_list|(
name|EnumType
name|value2
name|WRITE
name|set_value
name|READ
name|get_value
argument_list|)
name|Q_PROPERTY
argument_list|(
name|int
name|value8
name|READ
name|value8
argument_list|)
name|Q_PROPERTY
argument_list|(
name|int
name|value9
name|READ
name|value9
name|CONSTANT
argument_list|)
name|Q_PROPERTY
argument_list|(
name|int
name|value10
name|READ
name|value10
name|FINAL
argument_list|)
decl|private
name|slots
range|:
name|void
name|hasStdCppSet
argument_list|()
decl_stmt|;
name|void
name|isConstant
parameter_list|()
function_decl|;
name|void
name|isFinal
parameter_list|()
function_decl|;
name|void
name|gadget
parameter_list|()
function_decl|;
name|void
name|readAndWriteWithLazyRegistration
parameter_list|()
function_decl|;
public|public:
DECL|enum|EnumType
DECL|enumerator|EnumType1
enum|enum
name|EnumType
block|{
name|EnumType1
block|}
enum|;
DECL|function|setValue
name|void
name|setValue
parameter_list|(
name|EnumType
parameter_list|)
block|{}
DECL|function|getValue
name|EnumType
name|getValue
parameter_list|()
specifier|const
block|{
return|return
name|EnumType1
return|;
block|}
DECL|function|set_value
name|void
name|set_value
parameter_list|(
name|EnumType
parameter_list|)
block|{}
DECL|function|get_value
name|EnumType
name|get_value
parameter_list|()
specifier|const
block|{
return|return
name|EnumType1
return|;
block|}
DECL|function|value8
name|int
name|value8
parameter_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
DECL|function|value9
name|int
name|value9
parameter_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
DECL|function|value10
name|int
name|value10
parameter_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|hasStdCppSet
name|void
name|tst_QMetaProperty
operator|::
name|hasStdCppSet
parameter_list|()
block|{
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
name|metaObject
argument_list|()
decl_stmt|;
name|QMetaProperty
name|prop
init|=
name|mo
operator|->
name|property
argument_list|(
name|mo
operator|->
name|indexOfProperty
argument_list|(
literal|"value"
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|prop
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|prop
operator|.
name|hasStdCppSet
argument_list|()
argument_list|)
expr_stmt|;
name|prop
operator|=
name|mo
operator|->
name|property
argument_list|(
name|mo
operator|->
name|indexOfProperty
argument_list|(
literal|"value2"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|prop
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|prop
operator|.
name|hasStdCppSet
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isConstant
name|void
name|tst_QMetaProperty
operator|::
name|isConstant
parameter_list|()
block|{
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
name|metaObject
argument_list|()
decl_stmt|;
name|QMetaProperty
name|prop
init|=
name|mo
operator|->
name|property
argument_list|(
name|mo
operator|->
name|indexOfProperty
argument_list|(
literal|"value8"
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|prop
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|prop
operator|.
name|isConstant
argument_list|()
argument_list|)
expr_stmt|;
name|prop
operator|=
name|mo
operator|->
name|property
argument_list|(
name|mo
operator|->
name|indexOfProperty
argument_list|(
literal|"value9"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|prop
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|prop
operator|.
name|isConstant
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isFinal
name|void
name|tst_QMetaProperty
operator|::
name|isFinal
parameter_list|()
block|{
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
name|metaObject
argument_list|()
decl_stmt|;
name|QMetaProperty
name|prop
init|=
name|mo
operator|->
name|property
argument_list|(
name|mo
operator|->
name|indexOfProperty
argument_list|(
literal|"value10"
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|prop
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|prop
operator|.
name|isFinal
argument_list|()
argument_list|)
expr_stmt|;
name|prop
operator|=
name|mo
operator|->
name|property
argument_list|(
name|mo
operator|->
name|indexOfProperty
argument_list|(
literal|"value9"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|prop
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|prop
operator|.
name|isFinal
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|MyGadget
class|class
name|MyGadget
block|{
name|Q_GADGET
name|Q_PROPERTY
parameter_list|(
name|QString
name|value
name|READ
name|getValue
name|WRITE
name|setValue
name|RESET
name|resetValue
parameter_list|)
specifier|public
private|:
DECL|member|m_value
name|QString
name|m_value
decl_stmt|;
DECL|function|setValue
name|void
name|setValue
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
name|m_value
operator|=
name|value
expr_stmt|;
block|}
DECL|function|getValue
name|QString
name|getValue
parameter_list|()
block|{
return|return
name|m_value
return|;
block|}
DECL|function|resetValue
name|void
name|resetValue
parameter_list|()
block|{
name|m_value
operator|=
name|QLatin1Literal
argument_list|(
literal|"reset"
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|gadget
name|void
name|tst_QMetaProperty
operator|::
name|gadget
parameter_list|()
block|{
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
operator|&
name|MyGadget
operator|::
name|staticMetaObject
decl_stmt|;
name|QMetaProperty
name|valueProp
init|=
name|mo
operator|->
name|property
argument_list|(
name|mo
operator|->
name|indexOfProperty
argument_list|(
literal|"value"
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|valueProp
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|{
name|MyGadget
name|g
decl_stmt|;
name|QString
name|hello
init|=
name|QLatin1Literal
argument_list|(
literal|"hello"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|valueProp
operator|.
name|writeOnGadget
argument_list|(
operator|&
name|g
argument_list|,
name|hello
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|g
operator|.
name|m_value
argument_list|,
name|QLatin1String
argument_list|(
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|valueProp
operator|.
name|readOnGadget
argument_list|(
operator|&
name|g
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|hello
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|valueProp
operator|.
name|resetOnGadget
argument_list|(
operator|&
name|g
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|valueProp
operator|.
name|readOnGadget
argument_list|(
operator|&
name|g
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|QLatin1String
argument_list|(
literal|"reset"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_struct
DECL|struct|CustomReadObject
struct|struct
name|CustomReadObject
super|:
name|QObject
block|{
name|Q_OBJECT
block|}
struct|;
end_struct
begin_struct
DECL|struct|CustomWriteObject
struct|struct
name|CustomWriteObject
super|:
name|QObject
block|{
name|Q_OBJECT
block|}
struct|;
end_struct
begin_struct
DECL|struct|CustomWriteObjectChild
struct|struct
name|CustomWriteObjectChild
super|:
name|CustomWriteObject
block|{
name|Q_OBJECT
block|}
struct|;
end_struct
begin_struct
DECL|struct|TypeLazyRegistration
struct|struct
name|TypeLazyRegistration
super|:
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
name|CustomReadObject
operator|*
name|read
name|MEMBER
name|_read
argument_list|)
name|Q_PROPERTY
argument_list|(
name|CustomWriteObject
operator|*
name|write
name|MEMBER
name|_write
argument_list|)
DECL|member|_read
name|CustomReadObject
modifier|*
name|_read
decl_stmt|;
DECL|member|_write
name|CustomWriteObject
modifier|*
name|_write
decl_stmt|;
public|public:
DECL|function|TypeLazyRegistration
name|TypeLazyRegistration
parameter_list|()
member_init_list|:
name|_read
argument_list|()
member_init_list|,
name|_write
argument_list|()
block|{}
block|}
struct|;
end_struct
begin_function
DECL|function|readAndWriteWithLazyRegistration
name|void
name|tst_QMetaProperty
operator|::
name|readAndWriteWithLazyRegistration
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"CustomReadObject*"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|UnknownType
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"CustomWriteObject*"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|UnknownType
argument_list|)
argument_list|)
expr_stmt|;
name|TypeLazyRegistration
name|o
decl_stmt|;
name|QVERIFY
argument_list|(
name|o
operator|.
name|property
argument_list|(
literal|"read"
argument_list|)
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"CustomReadObject*"
argument_list|)
operator|!=
name|QMetaType
operator|::
name|UnknownType
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"CustomWriteObject*"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|UnknownType
argument_list|)
argument_list|)
expr_stmt|;
name|CustomWriteObjectChild
name|data
decl_stmt|;
name|QVariant
name|value
init|=
name|QVariant
operator|::
name|fromValue
argument_list|(
operator|&
name|data
argument_list|)
decl_stmt|;
comment|// this register CustomWriteObjectChild
comment|// check if base classes are not registered automatically, otherwise this test would be meaningless
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"CustomWriteObject*"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|UnknownType
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|o
operator|.
name|setProperty
argument_list|(
literal|"write"
argument_list|,
name|value
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"CustomWriteObject*"
argument_list|)
operator|!=
name|QMetaType
operator|::
name|UnknownType
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|o
operator|.
name|property
argument_list|(
literal|"write"
argument_list|)
operator|.
name|value
argument_list|<
name|CustomWriteObjectChild
operator|*
argument_list|>
argument_list|()
argument_list|,
operator|&
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QMetaProperty
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qmetaproperty.moc"
end_include
end_unit
