begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QGraphicsItem>
end_include
begin_include
include|#
directive|include
file|<QGraphicsScene>
end_include
begin_include
include|#
directive|include
file|<QGraphicsView>
end_include
begin_class
DECL|class|tst_QGraphicsScene
class|class
name|tst_QGraphicsScene
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QGraphicsScene
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QGraphicsScene
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|construct
parameter_list|()
function_decl|;
name|void
name|addItem_data
parameter_list|()
function_decl|;
name|void
name|addItem
parameter_list|()
function_decl|;
name|void
name|itemAt_data
parameter_list|()
function_decl|;
name|void
name|itemAt
parameter_list|()
function_decl|;
name|void
name|initialShow
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QGraphicsScene
name|tst_QGraphicsScene
operator|::
name|tst_QGraphicsScene
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QGraphicsScene
name|tst_QGraphicsScene
operator|::
name|~
name|tst_QGraphicsScene
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|processEvents
specifier|static
specifier|inline
name|void
name|processEvents
parameter_list|()
block|{
name|QApplication
operator|::
name|flush
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_QGraphicsScene
operator|::
name|init
parameter_list|()
block|{
name|processEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QGraphicsScene
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|construct
name|void
name|tst_QGraphicsScene
operator|::
name|construct
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QGraphicsScene
name|scene
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|addItem_data
name|void
name|tst_QGraphicsScene
operator|::
name|addItem_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"indexMethod"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRectF
argument_list|>
argument_list|(
literal|"sceneRect"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"numItems_X"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"numItems_Y"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"itemType"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRectF
argument_list|>
argument_list|(
literal|"itemRect"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|0
operator|<<
literal|0
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF() 10 x  10 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|10
operator|<<
literal|10
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF() 25 x  25 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|25
operator|<<
literal|25
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF() 100 x 100 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|100
operator|<<
literal|100
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF() 250 x 250 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|250
operator|<<
literal|250
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF()  10 x  10 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|10
operator|<<
literal|10
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF()  25 x  25 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|25
operator|<<
literal|25
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF() 100 x 100 QGraphicsEllipseItem (0,0,10,0)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|100
operator|<<
literal|100
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF() 250 x 250 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|250
operator|<<
literal|250
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF()  10 x  10 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF()  25 x  25 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|250
argument_list|,
literal|250
argument_list|)
operator|<<
literal|25
operator|<<
literal|25
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF() 100 x 100 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1000
argument_list|,
literal|1000
argument_list|)
operator|<<
literal|100
operator|<<
literal|100
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF() 250 x 250 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|2500
argument_list|,
literal|2500
argument_list|)
operator|<<
literal|250
operator|<<
literal|250
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF()  10 x  10 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF()  25 x  25 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|250
argument_list|,
literal|250
argument_list|)
operator|<<
literal|25
operator|<<
literal|25
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF() 100 x 100 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1000
argument_list|,
literal|1000
argument_list|)
operator|<<
literal|100
operator|<<
literal|100
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0 QRectF() 250 x 250 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|2500
argument_list|,
literal|2500
argument_list|)
operator|<<
literal|250
operator|<<
literal|250
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF() 10 x  10 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|10
operator|<<
literal|10
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF()  25 x  25 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|25
operator|<<
literal|25
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF() 100 x 100 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|100
operator|<<
literal|100
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF() 250 x 250 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|250
operator|<<
literal|250
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF()  10 x  10 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|10
operator|<<
literal|10
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF()  25 x  25 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|25
operator|<<
literal|25
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF() 100 x 100 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|100
operator|<<
literal|100
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF() 250 x 250 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|250
operator|<<
literal|250
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF()  10 x  10 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF()  25 x  25 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|250
argument_list|,
literal|250
argument_list|)
operator|<<
literal|25
operator|<<
literal|25
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF() 100 x 100 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1000
argument_list|,
literal|1000
argument_list|)
operator|<<
literal|100
operator|<<
literal|100
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF() 250 x 250 QGraphicsRectItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|2500
argument_list|,
literal|2500
argument_list|)
operator|<<
literal|250
operator|<<
literal|250
operator|<<
name|int
argument_list|(
name|QGraphicsRectItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF()  10 x  10 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF()  25 x  25 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|250
argument_list|,
literal|250
argument_list|)
operator|<<
literal|25
operator|<<
literal|25
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF() 100 x 100 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1000
argument_list|,
literal|1000
argument_list|)
operator|<<
literal|100
operator|<<
literal|100
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1 QRectF() 250 x 250 QGraphicsEllipseItem (0,0,10,10)"
argument_list|)
operator|<<
literal|1
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|2500
argument_list|,
literal|2500
argument_list|)
operator|<<
literal|250
operator|<<
literal|250
operator|<<
name|int
argument_list|(
name|QGraphicsEllipseItem
operator|::
name|Type
argument_list|)
operator|<<
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addItem
name|void
name|tst_QGraphicsScene
operator|::
name|addItem
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|indexMethod
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|sceneRect
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|numItems_X
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|numItems_Y
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|itemType
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|itemRect
argument_list|)
expr_stmt|;
name|QGraphicsScene
name|scene
decl_stmt|;
name|scene
operator|.
name|setItemIndexMethod
argument_list|(
name|indexMethod
condition|?
name|QGraphicsScene
operator|::
name|BspTreeIndex
else|:
name|QGraphicsScene
operator|::
name|NoIndex
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sceneRect
operator|.
name|isNull
argument_list|()
condition|)
name|scene
operator|.
name|setSceneRect
argument_list|(
name|sceneRect
argument_list|)
expr_stmt|;
name|processEvents
argument_list|()
expr_stmt|;
name|QBENCHMARK
block|{
name|QGraphicsItem
modifier|*
name|item
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|numItems_Y
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|numItems_X
condition|;
operator|++
name|x
control|)
block|{
switch|switch
condition|(
name|itemType
condition|)
block|{
case|case
name|QGraphicsRectItem
operator|::
name|Type
case|:
name|item
operator|=
operator|new
name|QGraphicsRectItem
argument_list|(
name|itemRect
argument_list|)
expr_stmt|;
break|break;
case|case
name|QGraphicsEllipseItem
operator|::
name|Type
case|:
default|default:
name|item
operator|=
operator|new
name|QGraphicsEllipseItem
argument_list|(
name|itemRect
argument_list|)
expr_stmt|;
break|break;
block|}
name|item
operator|->
name|setPos
argument_list|(
name|x
operator|*
name|itemRect
operator|.
name|width
argument_list|()
argument_list|,
name|y
operator|*
name|itemRect
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
block|}
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//let QGraphicsScene::_q_polishItems be called so ~QGraphicsItem doesn't spend all his time cleaning the unpolished list
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|itemAt_data
name|void
name|tst_QGraphicsScene
operator|::
name|itemAt_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"bspTreeDepth"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRectF
argument_list|>
argument_list|(
literal|"sceneRect"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"numItems_X"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"numItems_Y"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRectF
argument_list|>
argument_list|(
literal|"itemRect"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|0
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NoIndex 10x10"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|10
operator|<<
literal|10
operator|<<
name|QRectF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NoIndex 25x25"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|25
operator|<<
literal|25
operator|<<
name|QRectF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NoIndex 100x100"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|100
operator|<<
literal|100
operator|<<
name|QRectF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NoIndex 250x250"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|250
operator|<<
literal|250
operator|<<
name|QRectF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"BspTreeIndex depth=auto 10x10"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|10
operator|<<
literal|10
operator|<<
name|QRectF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"BspTreeIndex depth=auto 25x25"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|25
operator|<<
literal|25
operator|<<
name|QRectF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"BspTreeIndex depth=auto 100x100"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|100
operator|<<
literal|100
operator|<<
name|QRectF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"BspTreeIndex depth=auto 250x250"
argument_list|)
operator|<<
literal|0
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|250
operator|<<
literal|250
operator|<<
name|QRectF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"BspTreeIndex depth=16 10x10"
argument_list|)
operator|<<
literal|16
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|10
operator|<<
literal|10
operator|<<
name|QRectF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"BspTreeIndex depth=16 25x25"
argument_list|)
operator|<<
literal|16
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|25
operator|<<
literal|25
operator|<<
name|QRectF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"BspTreeIndex depth=16 100x100"
argument_list|)
operator|<<
literal|16
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|100
operator|<<
literal|100
operator|<<
name|QRectF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"BspTreeIndex depth=16 250x250"
argument_list|)
operator|<<
literal|16
operator|<<
name|QRectF
argument_list|()
operator|<<
literal|250
operator|<<
literal|250
operator|<<
name|QRectF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|itemAt
name|void
name|tst_QGraphicsScene
operator|::
name|itemAt
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|bspTreeDepth
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|sceneRect
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|numItems_X
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|numItems_Y
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|itemRect
argument_list|)
expr_stmt|;
name|QGraphicsScene
name|scene
decl_stmt|;
name|scene
operator|.
name|setItemIndexMethod
argument_list|(
name|bspTreeDepth
operator|>=
literal|0
condition|?
name|QGraphicsScene
operator|::
name|BspTreeIndex
else|:
name|QGraphicsScene
operator|::
name|NoIndex
argument_list|)
expr_stmt|;
if|if
condition|(
name|bspTreeDepth
operator|>
literal|0
condition|)
name|scene
operator|.
name|setBspTreeDepth
argument_list|(
name|bspTreeDepth
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sceneRect
operator|.
name|isNull
argument_list|()
condition|)
name|scene
operator|.
name|setSceneRect
argument_list|(
name|sceneRect
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|numItems_Y
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|numItems_X
condition|;
operator|++
name|x
control|)
block|{
name|QGraphicsRectItem
modifier|*
name|item
init|=
operator|new
name|QGraphicsRectItem
argument_list|(
name|itemRect
argument_list|)
decl_stmt|;
name|item
operator|->
name|setPos
argument_list|(
operator|(
name|x
operator|-
name|numItems_X
operator|/
literal|2
operator|)
operator|*
name|itemRect
operator|.
name|width
argument_list|()
argument_list|,
operator|(
name|y
operator|-
name|numItems_Y
operator|/
literal|2
operator|)
operator|*
name|itemRect
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
block|}
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|// triggers indexing
name|processEvents
argument_list|()
expr_stmt|;
name|QGraphicsItem
modifier|*
name|item
init|=
literal|0
decl_stmt|;
name|QBENCHMARK
block|{
name|item
operator|=
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|.
name|value
argument_list|(
literal|0
argument_list|,
name|Q_NULLPTR
argument_list|)
expr_stmt|;
block|}
comment|//let QGraphicsScene::_q_polishItems be called so ~QGraphicsItem doesn't spend all his time cleaning the unpolished list
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initialShow
name|void
name|tst_QGraphicsScene
operator|::
name|initialShow
parameter_list|()
block|{
name|QGraphicsScene
name|scene
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
literal|30000
condition|;
operator|++
name|y
control|)
block|{
name|QGraphicsRectItem
modifier|*
name|item
init|=
operator|new
name|QGraphicsRectItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
decl_stmt|;
name|item
operator|->
name|setPos
argument_list|(
operator|(
name|y
operator|/
literal|2
operator|)
operator|*
name|item
operator|->
name|rect
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
operator|(
name|y
operator|/
literal|2
operator|)
operator|*
name|item
operator|->
name|rect
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|// triggers indexing
comment|//This call polish the items so we bench their processing too.
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGraphicsScene
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qgraphicsscene.moc"
end_include
end_unit
