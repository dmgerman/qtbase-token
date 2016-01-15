begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Marc Mutz<marc.mutz@kdab.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QPair>
end_include
begin_include
include|#
directive|include
file|<QSize>
end_include
begin_class
DECL|class|tst_QPair
class|class
name|tst_QPair
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|Q_SLOTS
private|:
name|void
name|testConstexpr
parameter_list|()
function_decl|;
name|void
name|testConversions
parameter_list|()
function_decl|;
name|void
name|taskQTBUG_48780_pairContainingCArray
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|C
DECL|member|_
class|class
name|C
block|{
name|char
name|_
index|[
literal|4
index|]
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|M
DECL|member|_
class|class
name|M
block|{
name|char
name|_
index|[
literal|4
index|]
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|P
DECL|member|_
class|class
name|P
block|{
name|char
name|_
index|[
literal|4
index|]
decl_stmt|;
block|}
class|;
end_class
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_TYPEINFO
parameter_list|(
name|M
parameter_list|,
name|Q_MOVABLE_TYPE
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|P
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_comment
comment|// avoid the comma:
end_comment
begin_typedef
DECL|typedef|QPairCC
typedef|typedef
name|QPair
argument_list|<
name|C
argument_list|,
name|C
argument_list|>
name|QPairCC
typedef|;
end_typedef
begin_typedef
DECL|typedef|QPairCM
typedef|typedef
name|QPair
argument_list|<
name|C
argument_list|,
name|M
argument_list|>
name|QPairCM
typedef|;
end_typedef
begin_typedef
DECL|typedef|QPairCP
typedef|typedef
name|QPair
argument_list|<
name|C
argument_list|,
name|P
argument_list|>
name|QPairCP
typedef|;
end_typedef
begin_typedef
DECL|typedef|QPairMC
typedef|typedef
name|QPair
argument_list|<
name|M
argument_list|,
name|C
argument_list|>
name|QPairMC
typedef|;
end_typedef
begin_typedef
DECL|typedef|QPairMM
typedef|typedef
name|QPair
argument_list|<
name|M
argument_list|,
name|M
argument_list|>
name|QPairMM
typedef|;
end_typedef
begin_typedef
DECL|typedef|QPairMP
typedef|typedef
name|QPair
argument_list|<
name|M
argument_list|,
name|P
argument_list|>
name|QPairMP
typedef|;
end_typedef
begin_typedef
DECL|typedef|QPairPC
typedef|typedef
name|QPair
argument_list|<
name|P
argument_list|,
name|C
argument_list|>
name|QPairPC
typedef|;
end_typedef
begin_typedef
DECL|typedef|QPairPM
typedef|typedef
name|QPair
argument_list|<
name|P
argument_list|,
name|M
argument_list|>
name|QPairPM
typedef|;
end_typedef
begin_typedef
DECL|typedef|QPairPP
typedef|typedef
name|QPair
argument_list|<
name|P
argument_list|,
name|P
argument_list|>
name|QPairPP
typedef|;
end_typedef
begin_expr_stmt
DECL|variable|isComplex
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
argument_list|<
name|QPairCC
argument_list|>
operator|::
name|isComplex
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|isStatic
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
argument_list|<
name|QPairCC
argument_list|>
operator|::
name|isStatic
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|isComplex
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
argument_list|<
name|QPairCM
argument_list|>
operator|::
name|isComplex
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|isStatic
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
argument_list|<
name|QPairCM
argument_list|>
operator|::
name|isStatic
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|isComplex
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
argument_list|<
name|QPairCP
argument_list|>
operator|::
name|isComplex
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|isStatic
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
argument_list|<
name|QPairCP
argument_list|>
operator|::
name|isStatic
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|isComplex
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
argument_list|<
name|QPairMC
argument_list|>
operator|::
name|isComplex
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|isStatic
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
argument_list|<
name|QPairMC
argument_list|>
operator|::
name|isStatic
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|isComplex
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
argument_list|<
name|QPairMM
argument_list|>
operator|::
name|isComplex
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|QTypeInfo
argument_list|<
name|QPairMM
argument_list|>
operator|::
name|isStatic
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|isComplex
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
argument_list|<
name|QPairMP
argument_list|>
operator|::
name|isComplex
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|QTypeInfo
argument_list|<
name|QPairMP
argument_list|>
operator|::
name|isStatic
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|isComplex
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
argument_list|<
name|QPairPC
argument_list|>
operator|::
name|isComplex
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|isStatic
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
argument_list|<
name|QPairPC
argument_list|>
operator|::
name|isStatic
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|isComplex
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
argument_list|<
name|QPairPM
argument_list|>
operator|::
name|isComplex
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|QTypeInfo
argument_list|<
name|QPairPM
argument_list|>
operator|::
name|isStatic
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|QTypeInfo
argument_list|<
name|QPairPP
argument_list|>
operator|::
name|isComplex
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|QTypeInfo
argument_list|<
name|QPairPP
argument_list|>
operator|::
name|isStatic
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|QTypeInfo
argument_list|<
name|QPairPP
argument_list|>
operator|::
name|isDummy
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|QTypeInfo
argument_list|<
name|QPairPP
argument_list|>
operator|::
name|isPointer
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|testConstexpr
name|void
name|tst_QPair
operator|::
name|testConstexpr
parameter_list|()
block|{
name|Q_CONSTEXPR
name|QPair
argument_list|<
name|int
argument_list|,
name|double
argument_list|>
name|pID
init|=
name|qMakePair
argument_list|(
literal|0
argument_list|,
literal|0.0
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|pID
argument_list|)
expr_stmt|;
name|Q_CONSTEXPR
name|QPair
argument_list|<
name|double
argument_list|,
name|double
argument_list|>
name|pDD
init|=
name|qMakePair
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
decl_stmt|;
name|Q_CONSTEXPR
name|QPair
argument_list|<
name|double
argument_list|,
name|double
argument_list|>
name|pDD2
init|=
name|qMakePair
argument_list|(
literal|0
argument_list|,
literal|0.0
argument_list|)
decl_stmt|;
comment|// involes (rvalue) conversion ctor
name|Q_CONSTEXPR
name|bool
name|equal
init|=
name|pDD2
operator|==
name|pDD
decl_stmt|;
name|QVERIFY
argument_list|(
name|equal
argument_list|)
expr_stmt|;
name|Q_CONSTEXPR
name|QPair
argument_list|<
name|QSize
argument_list|,
name|int
argument_list|>
name|pSI
init|=
name|qMakePair
argument_list|(
name|QSize
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|)
argument_list|,
literal|6
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|pSI
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testConversions
name|void
name|tst_QPair
operator|::
name|testConversions
parameter_list|()
block|{
comment|// construction from lvalue:
block|{
specifier|const
name|QPair
argument_list|<
name|int
argument_list|,
name|double
argument_list|>
name|rhs
argument_list|(
literal|42
argument_list|,
literal|4.5
argument_list|)
decl_stmt|;
specifier|const
name|QPair
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|pii
init|=
name|rhs
decl_stmt|;
name|QCOMPARE
argument_list|(
name|pii
operator|.
name|first
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pii
operator|.
name|second
argument_list|,
literal|4
argument_list|)
expr_stmt|;
specifier|const
name|QPair
argument_list|<
name|int
argument_list|,
name|float
argument_list|>
name|pif
init|=
name|rhs
decl_stmt|;
name|QCOMPARE
argument_list|(
name|pif
operator|.
name|first
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pif
operator|.
name|second
argument_list|,
literal|4.5f
argument_list|)
expr_stmt|;
block|}
comment|// assignment from lvalue:
block|{
specifier|const
name|QPair
argument_list|<
name|int
argument_list|,
name|double
argument_list|>
name|rhs
argument_list|(
literal|42
argument_list|,
literal|4.5
argument_list|)
decl_stmt|;
name|QPair
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|pii
decl_stmt|;
name|pii
operator|=
name|rhs
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pii
operator|.
name|first
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pii
operator|.
name|second
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|QPair
argument_list|<
name|int
argument_list|,
name|float
argument_list|>
name|pif
decl_stmt|;
name|pif
operator|=
name|rhs
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pif
operator|.
name|first
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pif
operator|.
name|second
argument_list|,
literal|4.5f
argument_list|)
expr_stmt|;
block|}
comment|// construction from rvalue:
block|{
DECL|macro|rhs
define|#
directive|define
name|rhs
value|qMakePair(42, 4.5)
specifier|const
name|QPair
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|pii
init|=
name|rhs
decl_stmt|;
name|QCOMPARE
argument_list|(
name|pii
operator|.
name|first
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pii
operator|.
name|second
argument_list|,
literal|4
argument_list|)
expr_stmt|;
specifier|const
name|QPair
argument_list|<
name|int
argument_list|,
name|float
argument_list|>
name|pif
init|=
name|rhs
decl_stmt|;
name|QCOMPARE
argument_list|(
name|pif
operator|.
name|first
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pif
operator|.
name|second
argument_list|,
literal|4.5f
argument_list|)
expr_stmt|;
DECL|macro|rhs
undef|#
directive|undef
name|rhs
block|}
comment|// assignment from rvalue:
block|{
DECL|macro|rhs
define|#
directive|define
name|rhs
value|qMakePair(42, 4.5)
name|QPair
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|pii
decl_stmt|;
name|pii
operator|=
name|rhs
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pii
operator|.
name|first
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pii
operator|.
name|second
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|QPair
argument_list|<
name|int
argument_list|,
name|float
argument_list|>
name|pif
decl_stmt|;
name|pif
operator|=
name|rhs
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pif
operator|.
name|first
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pif
operator|.
name|second
argument_list|,
literal|4.5f
argument_list|)
expr_stmt|;
DECL|macro|rhs
undef|#
directive|undef
name|rhs
block|}
block|}
end_function
begin_function
DECL|function|taskQTBUG_48780_pairContainingCArray
name|void
name|tst_QPair
operator|::
name|taskQTBUG_48780_pairContainingCArray
parameter_list|()
block|{
comment|// compile-only:
name|QPair
argument_list|<
name|int
index|[
literal|2
index|]
argument_list|,
name|int
argument_list|>
name|pair
decl_stmt|;
name|pair
operator|.
name|first
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|pair
operator|.
name|first
index|[
literal|1
index|]
operator|=
literal|1
expr_stmt|;
name|pair
operator|.
name|second
operator|=
literal|2
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|pair
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QPair
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qpair.moc"
end_include
end_unit
