begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qmetatype.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_class
DECL|class|tst_QDBusMetaType
class|class
name|tst_QDBusMetaType
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|member|intStringMap
name|int
name|intStringMap
decl_stmt|;
DECL|member|stringStringMap
name|int
name|stringStringMap
decl_stmt|;
DECL|member|stringStruct1Map
name|int
name|stringStruct1Map
decl_stmt|;
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|staticTypes_data
parameter_list|()
function_decl|;
name|void
name|staticTypes
parameter_list|()
function_decl|;
name|void
name|dynamicTypes_data
parameter_list|()
function_decl|;
name|void
name|dynamicTypes
parameter_list|()
function_decl|;
name|void
name|invalidTypes_data
parameter_list|()
function_decl|;
name|void
name|invalidTypes
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_typedef
DECL|typedef|StringPair
typedef|typedef
name|QPair
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|StringPair
typedef|;
end_typedef
begin_struct
DECL|struct|Struct1
struct|struct
name|Struct1
block|{
block|}
struct|;
end_struct
begin_comment
DECL|struct|Struct1
comment|// (s)
end_comment
begin_struct
DECL|struct|Struct2
struct|struct
name|Struct2
block|{
block|}
struct|;
end_struct
begin_comment
DECL|struct|Struct2
comment|// (sos)
end_comment
begin_struct
DECL|struct|Struct3
struct|struct
name|Struct3
block|{
block|}
struct|;
end_struct
begin_comment
DECL|struct|Struct3
comment|// (sas)
end_comment
begin_struct
DECL|struct|Struct4
struct|struct
name|Struct4
comment|// (ssa(ss)sayasx)
block|{
DECL|member|m1
name|QString
name|m1
decl_stmt|;
DECL|member|m2
name|QString
name|m2
decl_stmt|;
DECL|member|m3
name|QList
argument_list|<
name|StringPair
argument_list|>
name|m3
decl_stmt|;
DECL|member|m4
name|QString
name|m4
decl_stmt|;
DECL|member|m5
name|QByteArray
name|m5
decl_stmt|;
DECL|member|m6
name|QStringList
name|m6
decl_stmt|;
DECL|member|m7
name|qlonglong
name|m7
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|Invalid0
struct|struct
name|Invalid0
block|{
block|}
struct|;
end_struct
begin_comment
DECL|struct|Invalid0
comment|// empty
end_comment
begin_struct
DECL|struct|Invalid1
struct|struct
name|Invalid1
block|{
block|}
struct|;
end_struct
begin_comment
DECL|struct|Invalid1
comment|// s
end_comment
begin_struct
DECL|struct|Invalid2
struct|struct
name|Invalid2
block|{
block|}
struct|;
end_struct
begin_comment
DECL|struct|Invalid2
comment|// o
end_comment
begin_struct
DECL|struct|Invalid3
struct|struct
name|Invalid3
block|{
block|}
struct|;
end_struct
begin_comment
DECL|struct|Invalid3
comment|// as
end_comment
begin_struct
DECL|struct|Invalid4
struct|struct
name|Invalid4
block|{
block|}
struct|;
end_struct
begin_comment
DECL|struct|Invalid4
comment|// ay
end_comment
begin_struct
DECL|struct|Invalid5
struct|struct
name|Invalid5
block|{
block|}
struct|;
end_struct
begin_comment
DECL|struct|Invalid5
comment|// ii
end_comment
begin_struct
DECL|struct|Invalid6
struct|struct
name|Invalid6
block|{
block|}
struct|;
end_struct
begin_comment
DECL|struct|Invalid6
comment|//<invalid>
end_comment
begin_struct
DECL|struct|Invalid7
struct|struct
name|Invalid7
block|{
block|}
struct|;
end_struct
begin_comment
DECL|struct|Invalid7
comment|// (<invalid>)
end_comment
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Struct1
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Struct2
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Struct3
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Struct4
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|StringPair
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<Struct1>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<Struct2>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<Struct3>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<Struct4>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Invalid0
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Invalid1
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Invalid2
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Invalid3
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Invalid4
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Invalid5
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Invalid6
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Invalid7
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<Invalid0>
argument_list|)
end_macro
begin_typedef
DECL|typedef|IntStringMap
typedef|typedef
name|QMap
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
name|IntStringMap
typedef|;
end_typedef
begin_typedef
DECL|typedef|StringStringMap
typedef|typedef
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|StringStringMap
typedef|;
end_typedef
begin_typedef
DECL|typedef|StringStruct1Map
typedef|typedef
name|QMap
argument_list|<
name|QString
argument_list|,
name|Struct1
argument_list|>
name|StringStruct1Map
typedef|;
end_typedef
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|IntStringMap
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|StringStringMap
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|StringStruct1Map
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QVariant::Type
argument_list|)
end_macro
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|Struct1
modifier|&
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|Struct2
modifier|&
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|<<
name|QString
argument_list|()
operator|<<
name|QDBusObjectPath
argument_list|()
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|Struct3
modifier|&
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|<<
name|QString
argument_list|()
operator|<<
name|QStringList
argument_list|()
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|StringPair
modifier|&
name|s
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|<<
name|s
operator|.
name|first
operator|<<
name|s
operator|.
name|second
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|Struct4
modifier|&
name|s
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|<<
name|s
operator|.
name|m1
operator|<<
name|s
operator|.
name|m2
operator|<<
name|s
operator|.
name|m3
operator|<<
name|s
operator|.
name|m4
operator|<<
name|s
operator|.
name|m5
operator|<<
name|s
operator|.
name|m6
operator|<<
name|s
operator|.
name|m7
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|Invalid0
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|Invalid1
modifier|&
parameter_list|)
block|{
name|arg
operator|<<
name|QString
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|Invalid2
modifier|&
parameter_list|)
block|{
name|arg
operator|<<
name|QDBusObjectPath
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|Invalid3
modifier|&
parameter_list|)
block|{
name|arg
operator|<<
name|QStringList
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|Invalid4
modifier|&
parameter_list|)
block|{
name|arg
operator|<<
name|QByteArray
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|Invalid5
modifier|&
parameter_list|)
block|{
name|arg
operator|<<
literal|1
operator|<<
literal|2
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_comment
comment|// no Invalid6
end_comment
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|Invalid7
modifier|&
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|<<
name|Invalid0
argument_list|()
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|Struct1
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|Struct2
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|Struct3
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|Struct4
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|StringPair
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|Invalid0
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|Invalid1
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|Invalid2
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|Invalid3
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|Invalid4
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|Invalid5
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|Invalid6
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|Invalid7
modifier|&
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function
begin_function
name|QT_END_NAMESPACE
DECL|function|initTestCase
name|void
name|tst_QDBusMetaType
operator|::
name|initTestCase
parameter_list|()
block|{
name|qDBusRegisterMetaType
argument_list|<
name|Struct1
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|Struct2
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|Struct3
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|Struct4
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|StringPair
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|Struct1
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|Struct2
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|Struct3
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|Struct4
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|Invalid0
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|Invalid1
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|Invalid2
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|Invalid3
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|Invalid4
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|Invalid5
argument_list|>
argument_list|()
expr_stmt|;
comment|// don't register Invalid6
name|qDBusRegisterMetaType
argument_list|<
name|Invalid7
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|Invalid0
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|intStringMap
operator|=
name|qDBusRegisterMetaType
argument_list|<
name|QMap
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|stringStringMap
operator|=
name|qDBusRegisterMetaType
argument_list|<
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|stringStruct1Map
operator|=
name|qDBusRegisterMetaType
argument_list|<
name|QMap
argument_list|<
name|QString
argument_list|,
name|Struct1
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|staticTypes_data
name|void
name|tst_QDBusMetaType
operator|::
name|staticTypes_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
operator|::
name|Type
argument_list|>
argument_list|(
literal|"typeId"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"signature"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"uchar"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|QMetaType
operator|::
name|UChar
argument_list|)
operator|<<
literal|"y"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"bool"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Bool
operator|<<
literal|"b"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"short"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|QMetaType
operator|::
name|Short
argument_list|)
operator|<<
literal|"n"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ushort"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|QMetaType
operator|::
name|UShort
argument_list|)
operator|<<
literal|"q"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"int"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Int
operator|<<
literal|"i"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"uint"
argument_list|)
operator|<<
name|QVariant
operator|::
name|UInt
operator|<<
literal|"u"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"qlonglong"
argument_list|)
operator|<<
name|QVariant
operator|::
name|LongLong
operator|<<
literal|"x"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"qulonglong"
argument_list|)
operator|<<
name|QVariant
operator|::
name|ULongLong
operator|<<
literal|"t"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"double"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Double
operator|<<
literal|"d"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QString"
argument_list|)
operator|<<
name|QVariant
operator|::
name|String
operator|<<
literal|"s"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDBusObjectPath"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|QDBusObjectPath
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|"o"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDBusSignature"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|QDBusSignature
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|"g"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDBusVariant"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|QDBusVariant
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|"v"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QByteArray"
argument_list|)
operator|<<
name|QVariant
operator|::
name|ByteArray
operator|<<
literal|"ay"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QStringList"
argument_list|)
operator|<<
name|QVariant
operator|::
name|StringList
operator|<<
literal|"as"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dynamicTypes_data
name|void
name|tst_QDBusMetaType
operator|::
name|dynamicTypes_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
operator|::
name|Type
argument_list|>
argument_list|(
literal|"typeId"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"signature"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QVariantList"
argument_list|)
operator|<<
name|QVariant
operator|::
name|List
operator|<<
literal|"av"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QVariantMap"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Map
operator|<<
literal|"a{sv}"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDate"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Date
operator|<<
literal|"(iii)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QTime"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Time
operator|<<
literal|"(iiii)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDateTime"
argument_list|)
operator|<<
name|QVariant
operator|::
name|DateTime
operator|<<
literal|"((iii)(iiii)i)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QRect"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Rect
operator|<<
literal|"(iiii)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QRectF"
argument_list|)
operator|<<
name|QVariant
operator|::
name|RectF
operator|<<
literal|"(dddd)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QSize"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Size
operator|<<
literal|"(ii)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QSizeF"
argument_list|)
operator|<<
name|QVariant
operator|::
name|SizeF
operator|<<
literal|"(dd)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QPoint"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Point
operator|<<
literal|"(ii)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QPointF"
argument_list|)
operator|<<
name|QVariant
operator|::
name|PointF
operator|<<
literal|"(dd)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QLine"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Line
operator|<<
literal|"((ii)(ii))"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QLineF"
argument_list|)
operator|<<
name|QVariant
operator|::
name|LineF
operator|<<
literal|"((dd)(dd))"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Struct1"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|Struct1
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|"(s)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QList<Struct1>"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|QList
argument_list|<
name|Struct1
argument_list|>
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|"a(s)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Struct2"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|Struct2
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|"(sos)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QList<Struct2>"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|QList
argument_list|<
name|Struct2
argument_list|>
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|"a(sos)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QList<Struct3>"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|QList
argument_list|<
name|Struct3
argument_list|>
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|"a(sas)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Struct3"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|Struct3
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|"(sas)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Struct4"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|Struct4
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|"(ssa(ss)sayasx)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QList<Struct4>"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|QList
argument_list|<
name|Struct4
argument_list|>
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|"a(ssa(ss)sayasx)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QMap<int,QString>"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|intStringMap
argument_list|)
operator|<<
literal|"a{is}"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QMap<QString,QString>"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|stringStringMap
argument_list|)
operator|<<
literal|"a{ss}"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QMap<QString,Struct1>"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|stringStruct1Map
argument_list|)
operator|<<
literal|"a{s(s)}"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|staticTypes
name|void
name|tst_QDBusMetaType
operator|::
name|staticTypes
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVariant
operator|::
name|Type
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|QString
name|result
init|=
name|QDBusMetaType
operator|::
name|typeToSignature
argument_list|(
name|typeId
argument_list|)
decl_stmt|;
name|QTEST
argument_list|(
name|result
argument_list|,
literal|"signature"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dynamicTypes
name|void
name|tst_QDBusMetaType
operator|::
name|dynamicTypes
parameter_list|()
block|{
comment|// same test
name|staticTypes
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|invalidTypes_data
name|void
name|tst_QDBusMetaType
operator|::
name|invalidTypes_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
operator|::
name|Type
argument_list|>
argument_list|(
literal|"typeId"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"signature"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Invalid0"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|Invalid0
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Invalid1"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|Invalid1
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Invalid2"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|Invalid2
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Invalid3"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|Invalid3
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Invalid4"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|Invalid4
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Invalid5"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|Invalid5
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Invalid6"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|Invalid6
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Invalid7"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|Invalid7
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QList<Invalid0>"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|qMetaTypeId
argument_list|<
name|QList
argument_list|<
name|Invalid0
argument_list|>
argument_list|>
argument_list|()
argument_list|)
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"long"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|QMetaType
operator|::
name|Long
argument_list|)
operator|<<
literal|""
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"void*"
argument_list|)
operator|<<
name|QVariant
operator|::
name|Type
argument_list|(
name|QMetaType
operator|::
name|VoidStar
argument_list|)
operator|<<
literal|""
expr_stmt|;
block|}
end_function
begin_function
DECL|function|invalidTypes
name|void
name|tst_QDBusMetaType
operator|::
name|invalidTypes
parameter_list|()
block|{
comment|// same test
if|if
condition|(
name|qstrcmp
argument_list|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
argument_list|,
literal|"Invalid0"
argument_list|)
operator|==
literal|0
condition|)
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QDBusMarshaller: type `Invalid0' produces invalid D-BUS signature `<empty>' (Did you forget to call beginStructure() ?)"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|qstrcmp
argument_list|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
argument_list|,
literal|"Invalid1"
argument_list|)
operator|==
literal|0
condition|)
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QDBusMarshaller: type `Invalid1' attempts to redefine basic D-BUS type 's' (QString) (Did you forget to call beginStructure() ?)"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|qstrcmp
argument_list|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
argument_list|,
literal|"Invalid2"
argument_list|)
operator|==
literal|0
condition|)
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QDBusMarshaller: type `Invalid2' attempts to redefine basic D-BUS type 'o' (QDBusObjectPath) (Did you forget to call beginStructure() ?)"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|qstrcmp
argument_list|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
argument_list|,
literal|"Invalid3"
argument_list|)
operator|==
literal|0
condition|)
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QDBusMarshaller: type `Invalid3' attempts to redefine basic D-BUS type 'as' (QStringList) (Did you forget to call beginStructure() ?)"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|qstrcmp
argument_list|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
argument_list|,
literal|"Invalid4"
argument_list|)
operator|==
literal|0
condition|)
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QDBusMarshaller: type `Invalid4' attempts to redefine basic D-BUS type 'ay' (QByteArray) (Did you forget to call beginStructure() ?)"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|qstrcmp
argument_list|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
argument_list|,
literal|"Invalid5"
argument_list|)
operator|==
literal|0
condition|)
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QDBusMarshaller: type `Invalid5' produces invalid D-BUS signature `ii' (Did you forget to call beginStructure() ?)"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|qstrcmp
argument_list|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
argument_list|,
literal|"Invalid7"
argument_list|)
operator|==
literal|0
condition|)
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QDBusMarshaller: type `Invalid7' produces invalid D-BUS signature `()' (Did you forget to call beginStructure() ?)"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|qstrcmp
argument_list|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
argument_list|,
literal|"QList<Invalid0>"
argument_list|)
operator|==
literal|0
condition|)
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QDBusMarshaller: type `QList<Invalid0>' produces invalid D-BUS signature `a' (Did you forget to call beginStructure() ?)"
argument_list|)
expr_stmt|;
name|staticTypes
argument_list|()
expr_stmt|;
name|staticTypes
argument_list|()
expr_stmt|;
comment|// run twice: the error messages should be printed once only
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QDBusMetaType
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qdbusmetatype.moc"
end_include
end_unit
