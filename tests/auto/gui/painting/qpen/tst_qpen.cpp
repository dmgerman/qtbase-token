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
file|"qpen.h"
end_include
begin_include
include|#
directive|include
file|"qbrush.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_class
DECL|class|tst_QPen
class|class
name|tst_QPen
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QPen
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|swap
parameter_list|()
function_decl|;
name|void
name|operator_eq_eq
parameter_list|()
function_decl|;
name|void
name|operator_eq_eq_data
parameter_list|()
function_decl|;
name|void
name|stream
parameter_list|()
function_decl|;
name|void
name|stream_data
parameter_list|()
function_decl|;
name|void
name|constructor
parameter_list|()
function_decl|;
name|void
name|constructor_data
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QPen
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QPen
name|obj1
decl_stmt|;
comment|// qreal QPen::miterLimit()
comment|// void QPen::setMiterLimit(qreal)
name|obj1
operator|.
name|setMiterLimit
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0.0
argument_list|,
name|obj1
operator|.
name|miterLimit
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMiterLimit
argument_list|(
name|qreal
argument_list|(
literal|1.1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qreal
argument_list|(
literal|1.1
argument_list|)
argument_list|,
name|obj1
operator|.
name|miterLimit
argument_list|()
argument_list|)
expr_stmt|;
comment|// qreal QPen::widthF()
comment|// void QPen::setWidthF(qreal)
name|obj1
operator|.
name|setWidthF
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0.0
argument_list|,
name|obj1
operator|.
name|widthF
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setWidthF
argument_list|(
name|qreal
argument_list|(
literal|1.1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qreal
argument_list|(
literal|1.1
argument_list|)
argument_list|,
name|obj1
operator|.
name|widthF
argument_list|()
argument_list|)
expr_stmt|;
comment|// int QPen::width()
comment|// void QPen::setWidth(int)
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100
condition|;
operator|++
name|i
control|)
block|{
name|obj1
operator|.
name|setWidth
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|i
argument_list|,
name|obj1
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|swap
name|void
name|tst_QPen
operator|::
name|swap
parameter_list|()
block|{
name|QPen
name|p1
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
decl_stmt|,
name|p2
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
decl_stmt|;
name|p1
operator|.
name|swap
argument_list|(
name|p2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|color
argument_list|()
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p2
operator|.
name|color
argument_list|()
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QPen
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QBrush
argument_list|)
end_macro
begin_constructor
DECL|function|tst_QPen
name|tst_QPen
operator|::
name|tst_QPen
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|operator_eq_eq_data
name|void
name|tst_QPen
operator|::
name|operator_eq_eq_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPen
argument_list|>
argument_list|(
literal|"pen1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPen
argument_list|>
argument_list|(
literal|"pen2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"isEqual"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"differentColor"
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"differentWidth"
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|,
literal|2
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|,
literal|3
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"differentPenStyle"
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|DashLine
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|DotLine
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"differentCapStyle"
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|DashLine
argument_list|,
name|Qt
operator|::
name|RoundCap
argument_list|,
name|Qt
operator|::
name|BevelJoin
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|DashLine
argument_list|,
name|Qt
operator|::
name|SquareCap
argument_list|,
name|Qt
operator|::
name|BevelJoin
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"differentJoinStyle"
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|DashLine
argument_list|,
name|Qt
operator|::
name|RoundCap
argument_list|,
name|Qt
operator|::
name|BevelJoin
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|DashLine
argument_list|,
name|Qt
operator|::
name|RoundCap
argument_list|,
name|Qt
operator|::
name|MiterJoin
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"same"
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|DashLine
argument_list|,
name|Qt
operator|::
name|RoundCap
argument_list|,
name|Qt
operator|::
name|BevelJoin
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|DashLine
argument_list|,
name|Qt
operator|::
name|RoundCap
argument_list|,
name|Qt
operator|::
name|BevelJoin
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_eq_eq
name|void
name|tst_QPen
operator|::
name|operator_eq_eq
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPen
argument_list|,
name|pen1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPen
argument_list|,
name|pen2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isEqual
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pen1
operator|==
name|pen2
argument_list|,
name|isEqual
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructor_data
name|void
name|tst_QPen
operator|::
name|constructor_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPen
argument_list|>
argument_list|(
literal|"pen"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QBrush
argument_list|>
argument_list|(
literal|"brush"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|double
argument_list|>
argument_list|(
literal|"width"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"style"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"capStyle"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"joinStyle"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"solid_black"
argument_list|)
operator|<<
name|QPen
argument_list|()
operator|<<
name|QBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
operator|<<
literal|0.
operator|<<
operator|(
name|int
operator|)
name|Qt
operator|::
name|SolidLine
operator|<<
operator|(
name|int
operator|)
name|Qt
operator|::
name|SquareCap
operator|<<
operator|(
name|int
operator|)
name|Qt
operator|::
name|BevelJoin
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"solid_red"
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
operator|<<
literal|0.
operator|<<
operator|(
name|int
operator|)
name|Qt
operator|::
name|SolidLine
operator|<<
operator|(
name|int
operator|)
name|Qt
operator|::
name|SquareCap
operator|<<
operator|(
name|int
operator|)
name|Qt
operator|::
name|BevelJoin
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"full"
argument_list|)
operator|<<
name|QPen
argument_list|(
name|QBrush
argument_list|(
name|QLinearGradient
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
argument_list|,
literal|10
argument_list|,
name|Qt
operator|::
name|SolidLine
argument_list|,
name|Qt
operator|::
name|RoundCap
argument_list|,
name|Qt
operator|::
name|MiterJoin
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|QLinearGradient
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
operator|<<
literal|10.
operator|<<
operator|(
name|int
operator|)
name|Qt
operator|::
name|SolidLine
operator|<<
operator|(
name|int
operator|)
name|Qt
operator|::
name|RoundCap
operator|<<
operator|(
name|int
operator|)
name|Qt
operator|::
name|MiterJoin
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructor
name|void
name|tst_QPen
operator|::
name|constructor
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPen
argument_list|,
name|pen
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QBrush
argument_list|,
name|brush
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|double
argument_list|,
name|width
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|style
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|capStyle
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|joinStyle
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pen
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|PenStyle
argument_list|(
name|style
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pen
operator|.
name|capStyle
argument_list|()
argument_list|,
name|Qt
operator|::
name|PenCapStyle
argument_list|(
name|capStyle
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pen
operator|.
name|joinStyle
argument_list|()
argument_list|,
name|Qt
operator|::
name|PenJoinStyle
argument_list|(
name|joinStyle
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pen
operator|.
name|widthF
argument_list|()
argument_list|,
name|width
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pen
operator|.
name|brush
argument_list|()
argument_list|,
name|brush
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stream_data
name|void
name|tst_QPen
operator|::
name|stream_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPen
argument_list|>
argument_list|(
literal|"pen"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"solid_black"
argument_list|)
operator|<<
name|QPen
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"solid_red"
argument_list|)
operator|<<
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"full"
argument_list|)
operator|<<
name|QPen
argument_list|(
name|QBrush
argument_list|(
name|QLinearGradient
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
argument_list|,
literal|10
argument_list|,
name|Qt
operator|::
name|SolidLine
argument_list|,
name|Qt
operator|::
name|RoundCap
argument_list|,
name|Qt
operator|::
name|MiterJoin
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stream
name|void
name|tst_QPen
operator|::
name|stream
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPen
argument_list|,
name|pen
argument_list|)
expr_stmt|;
name|QByteArray
name|bytes
decl_stmt|;
block|{
name|QDataStream
name|stream
argument_list|(
operator|&
name|bytes
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|stream
operator|<<
name|pen
expr_stmt|;
block|}
name|QPen
name|cmp
decl_stmt|;
block|{
name|QDataStream
name|stream
argument_list|(
operator|&
name|bytes
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|stream
operator|>>
name|cmp
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|pen
operator|.
name|widthF
argument_list|()
argument_list|,
name|cmp
operator|.
name|widthF
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pen
operator|.
name|style
argument_list|()
argument_list|,
name|cmp
operator|.
name|style
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pen
operator|.
name|capStyle
argument_list|()
argument_list|,
name|cmp
operator|.
name|capStyle
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pen
operator|.
name|joinStyle
argument_list|()
argument_list|,
name|cmp
operator|.
name|joinStyle
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pen
operator|.
name|brush
argument_list|()
argument_list|,
name|cmp
operator|.
name|brush
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pen
argument_list|,
name|cmp
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QPen
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qpen.moc"
end_include
end_unit
