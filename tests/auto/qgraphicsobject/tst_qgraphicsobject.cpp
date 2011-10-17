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
file|<qgraphicsitem.h>
end_include
begin_include
include|#
directive|include
file|<qgraphicsscene.h>
end_include
begin_include
include|#
directive|include
file|<qgraphicssceneevent.h>
end_include
begin_include
include|#
directive|include
file|<qgraphicsview.h>
end_include
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_class
DECL|class|tst_QGraphicsObject
class|class
name|tst_QGraphicsObject
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
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
name|pos
parameter_list|()
function_decl|;
name|void
name|x
parameter_list|()
function_decl|;
name|void
name|y
parameter_list|()
function_decl|;
name|void
name|z
parameter_list|()
function_decl|;
name|void
name|opacity
parameter_list|()
function_decl|;
name|void
name|enabled
parameter_list|()
function_decl|;
name|void
name|visible
parameter_list|()
function_decl|;
name|void
name|deleted
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// This will be called before the first test function is executed.
end_comment
begin_comment
comment|// It is only called once.
end_comment
begin_function
DECL|function|initTestCase
name|void
name|tst_QGraphicsObject
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_comment
comment|// This will be called after the last test function is executed.
end_comment
begin_comment
comment|// It is only called once.
end_comment
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QGraphicsObject
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_comment
comment|// This will be called before each test function is executed.
end_comment
begin_function
DECL|function|init
name|void
name|tst_QGraphicsObject
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_comment
comment|// This will be called after every test function.
end_comment
begin_function
DECL|function|cleanup
name|void
name|tst_QGraphicsObject
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_class
DECL|class|MyGraphicsObject
class|class
name|MyGraphicsObject
super|:
specifier|public
name|QGraphicsObject
block|{
public|public:
DECL|function|MyGraphicsObject
name|MyGraphicsObject
parameter_list|()
member_init_list|:
name|QGraphicsObject
argument_list|()
block|{}
DECL|function|boundingRect
specifier|virtual
name|QRectF
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|()
return|;
block|}
DECL|function|paint
specifier|virtual
name|void
name|paint
parameter_list|(
name|QPainter
modifier|*
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
block|{}
block|}
class|;
end_class
begin_function
DECL|function|pos
name|void
name|tst_QGraphicsObject
operator|::
name|pos
parameter_list|()
block|{
name|MyGraphicsObject
name|object
decl_stmt|;
name|QSignalSpy
name|xSpy
argument_list|(
operator|&
name|object
argument_list|,
name|SIGNAL
argument_list|(
name|xChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|ySpy
argument_list|(
operator|&
name|object
argument_list|,
name|SIGNAL
argument_list|(
name|yChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|pos
argument_list|()
operator|==
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|object
operator|.
name|setPos
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|xSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ySpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|pos
argument_list|()
operator|==
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|object
operator|.
name|setPos
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|xSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ySpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|object
operator|.
name|setProperty
argument_list|(
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|xSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ySpy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|property
argument_list|(
literal|"pos"
argument_list|)
operator|==
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|object
operator|.
name|setProperty
argument_list|(
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|xSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ySpy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|property
argument_list|(
literal|"pos"
argument_list|)
operator|==
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|object
operator|.
name|setProperty
argument_list|(
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|xSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ySpy
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|property
argument_list|(
literal|"pos"
argument_list|)
operator|==
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|x
name|void
name|tst_QGraphicsObject
operator|::
name|x
parameter_list|()
block|{
name|MyGraphicsObject
name|object
decl_stmt|;
name|QSignalSpy
name|xSpy
argument_list|(
operator|&
name|object
argument_list|,
name|SIGNAL
argument_list|(
name|xChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|ySpy
argument_list|(
operator|&
name|object
argument_list|,
name|SIGNAL
argument_list|(
name|yChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|pos
argument_list|()
operator|==
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|object
operator|.
name|setX
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|xSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ySpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|pos
argument_list|()
operator|==
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|x
argument_list|()
operator|==
literal|10
argument_list|)
expr_stmt|;
name|object
operator|.
name|setX
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|xSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ySpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|object
operator|.
name|setProperty
argument_list|(
literal|"x"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|xSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ySpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|property
argument_list|(
literal|"x"
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|y
name|void
name|tst_QGraphicsObject
operator|::
name|y
parameter_list|()
block|{
name|MyGraphicsObject
name|object
decl_stmt|;
name|QSignalSpy
name|xSpy
argument_list|(
operator|&
name|object
argument_list|,
name|SIGNAL
argument_list|(
name|xChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|ySpy
argument_list|(
operator|&
name|object
argument_list|,
name|SIGNAL
argument_list|(
name|yChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|pos
argument_list|()
operator|==
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|object
operator|.
name|setY
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|xSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ySpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|pos
argument_list|()
operator|==
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|y
argument_list|()
operator|==
literal|10
argument_list|)
expr_stmt|;
name|object
operator|.
name|setY
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|xSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ySpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|object
operator|.
name|setProperty
argument_list|(
literal|"y"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|xSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ySpy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|property
argument_list|(
literal|"y"
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|z
name|void
name|tst_QGraphicsObject
operator|::
name|z
parameter_list|()
block|{
name|MyGraphicsObject
name|object
decl_stmt|;
name|QSignalSpy
name|zSpy
argument_list|(
operator|&
name|object
argument_list|,
name|SIGNAL
argument_list|(
name|zChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|zValue
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|object
operator|.
name|setZValue
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|zSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|zValue
argument_list|()
operator|==
literal|10
argument_list|)
expr_stmt|;
name|object
operator|.
name|setZValue
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|zSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|object
operator|.
name|setProperty
argument_list|(
literal|"z"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|zSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|property
argument_list|(
literal|"z"
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|opacity
name|void
name|tst_QGraphicsObject
operator|::
name|opacity
parameter_list|()
block|{
name|MyGraphicsObject
name|object
decl_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|object
argument_list|,
name|SIGNAL
argument_list|(
name|opacityChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|opacity
argument_list|()
operator|==
literal|1.
argument_list|)
expr_stmt|;
name|object
operator|.
name|setOpacity
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|opacity
argument_list|()
operator|==
literal|0.
argument_list|)
expr_stmt|;
name|object
operator|.
name|setOpacity
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|object
operator|.
name|setProperty
argument_list|(
literal|"opacity"
argument_list|,
literal|.5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|property
argument_list|(
literal|"opacity"
argument_list|)
operator|==
literal|.5
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enabled
name|void
name|tst_QGraphicsObject
operator|::
name|enabled
parameter_list|()
block|{
name|MyGraphicsObject
name|object
decl_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|object
argument_list|,
name|SIGNAL
argument_list|(
name|enabledChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|isEnabled
argument_list|()
operator|==
literal|true
argument_list|)
expr_stmt|;
name|object
operator|.
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|isEnabled
argument_list|()
operator|==
literal|false
argument_list|)
expr_stmt|;
name|object
operator|.
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|object
operator|.
name|setProperty
argument_list|(
literal|"enabled"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|property
argument_list|(
literal|"enabled"
argument_list|)
operator|==
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visible
name|void
name|tst_QGraphicsObject
operator|::
name|visible
parameter_list|()
block|{
name|MyGraphicsObject
name|object
decl_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|object
argument_list|,
name|SIGNAL
argument_list|(
name|visibleChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|isVisible
argument_list|()
operator|==
literal|true
argument_list|)
expr_stmt|;
name|object
operator|.
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|isVisible
argument_list|()
operator|==
literal|false
argument_list|)
expr_stmt|;
name|object
operator|.
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|object
operator|.
name|setProperty
argument_list|(
literal|"visible"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|property
argument_list|(
literal|"visible"
argument_list|)
operator|==
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|DeleteTester
class|class
name|DeleteTester
super|:
specifier|public
name|QGraphicsObject
block|{
public|public:
DECL|function|DeleteTester
name|DeleteTester
parameter_list|(
name|bool
modifier|*
name|w
parameter_list|,
name|bool
modifier|*
name|pw
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QGraphicsObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|wasDeleted
argument_list|(
name|w
argument_list|)
member_init_list|,
name|parentWasDeleted
argument_list|(
name|pw
argument_list|)
block|{ }
DECL|function|~DeleteTester
name|~
name|DeleteTester
parameter_list|()
block|{
operator|*
name|wasDeleted
operator|=
name|QObjectPrivate
operator|::
name|get
argument_list|(
name|this
argument_list|)
operator|->
name|wasDeleted
expr_stmt|;
if|if
condition|(
name|QGraphicsItem
modifier|*
name|p
init|=
name|parentItem
argument_list|()
condition|)
block|{
if|if
condition|(
name|QGraphicsObject
modifier|*
name|o
init|=
name|p
operator|->
name|toGraphicsObject
argument_list|()
condition|)
operator|*
name|parentWasDeleted
operator|=
name|QObjectPrivate
operator|::
name|get
argument_list|(
name|o
argument_list|)
operator|->
name|wasDeleted
expr_stmt|;
block|}
block|}
DECL|function|paint
name|void
name|paint
parameter_list|(
name|QPainter
modifier|*
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
parameter_list|,
name|QWidget
modifier|*
init|=
literal|0
parameter_list|)
block|{ }
DECL|function|boundingRect
name|QRectF
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|()
return|;
block|}
DECL|member|wasDeleted
name|bool
modifier|*
name|wasDeleted
decl_stmt|;
DECL|member|parentWasDeleted
name|bool
modifier|*
name|parentWasDeleted
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|deleted
name|void
name|tst_QGraphicsObject
operator|::
name|deleted
parameter_list|()
block|{
name|bool
name|item1_parentWasDeleted
init|=
literal|false
decl_stmt|;
name|bool
name|item1_wasDeleted
init|=
literal|false
decl_stmt|;
name|bool
name|item2_parentWasDeleted
init|=
literal|false
decl_stmt|;
name|bool
name|item2_wasDeleted
init|=
literal|false
decl_stmt|;
name|DeleteTester
modifier|*
name|item1
init|=
operator|new
name|DeleteTester
argument_list|(
operator|&
name|item1_wasDeleted
argument_list|,
operator|&
name|item1_parentWasDeleted
argument_list|)
decl_stmt|;
name|DeleteTester
modifier|*
name|item2
init|=
operator|new
name|DeleteTester
argument_list|(
operator|&
name|item2_wasDeleted
argument_list|,
operator|&
name|item2_parentWasDeleted
argument_list|,
name|item1
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|item2
argument_list|)
expr_stmt|;
operator|delete
name|item1
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|item1_wasDeleted
argument_list|)
expr_stmt|;
comment|// destructor not called yet
name|QVERIFY
argument_list|(
operator|!
name|item1_parentWasDeleted
argument_list|)
expr_stmt|;
comment|// no parent
name|QVERIFY
argument_list|(
operator|!
name|item2_wasDeleted
argument_list|)
expr_stmt|;
comment|// destructor not called yet
name|QVERIFY
argument_list|(
name|item2_parentWasDeleted
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGraphicsObject
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qgraphicsobject.moc"
end_include
end_unit
