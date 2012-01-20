begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qgraphicslayoutitem.h>
end_include
begin_include
include|#
directive|include
file|<float.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_class
DECL|class|tst_QGraphicsLayoutItem
class|class
name|tst_QGraphicsLayoutItem
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
name|qgraphicslayoutitem
parameter_list|()
function_decl|;
name|void
name|contentsRect
parameter_list|()
function_decl|;
name|void
name|effectiveSizeHint_data
parameter_list|()
function_decl|;
name|void
name|effectiveSizeHint
parameter_list|()
function_decl|;
name|void
name|getContentsMargins
parameter_list|()
function_decl|;
name|void
name|isLayout_data
parameter_list|()
function_decl|;
name|void
name|isLayout
parameter_list|()
function_decl|;
name|void
name|maximumSize
parameter_list|()
function_decl|;
name|void
name|minimumSize
parameter_list|()
function_decl|;
name|void
name|parentLayoutItem_data
parameter_list|()
function_decl|;
name|void
name|parentLayoutItem
parameter_list|()
function_decl|;
name|void
name|preferredSize
parameter_list|()
function_decl|;
name|void
name|setMaximumSize_data
parameter_list|()
function_decl|;
name|void
name|setMaximumSize
parameter_list|()
function_decl|;
name|void
name|setMinimumSize_data
parameter_list|()
function_decl|;
name|void
name|setMinimumSize
parameter_list|()
function_decl|;
name|void
name|setPreferredSize_data
parameter_list|()
function_decl|;
name|void
name|setPreferredSize
parameter_list|()
function_decl|;
name|void
name|setSizePolicy_data
parameter_list|()
function_decl|;
name|void
name|setPreferredSize2
parameter_list|()
function_decl|;
name|void
name|setSizePolicy
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// Subclass that exposes the protected functions.
end_comment
begin_class
DECL|class|SubQGraphicsLayoutItem
class|class
name|SubQGraphicsLayoutItem
super|:
specifier|public
name|QGraphicsLayoutItem
block|{
public|public:
DECL|function|SubQGraphicsLayoutItem
name|SubQGraphicsLayoutItem
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|par
init|=
literal|0
parameter_list|,
name|bool
name|layout
init|=
literal|false
parameter_list|)
member_init_list|:
name|QGraphicsLayoutItem
argument_list|(
name|par
argument_list|,
name|layout
argument_list|)
member_init_list|,
name|updateGeometryCalled
argument_list|(
literal|0
argument_list|)
block|{}
comment|// QGraphicsLayoutItem::geometry is a pure virtual function
DECL|function|geometry
name|QRectF
name|geometry
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|()
return|;
block|}
comment|// QGraphicsLayoutItem::setGeometry is a pure virtual function
DECL|function|setGeometry
name|void
name|setGeometry
parameter_list|(
name|QRectF
specifier|const
modifier|&
name|rect
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
comment|// QGraphicsLayoutItem::sizeHint is a pure virtual function
DECL|function|sizeHint
name|QSizeF
name|sizeHint
parameter_list|(
name|Qt
operator|::
name|SizeHint
name|which
parameter_list|,
name|QSizeF
specifier|const
modifier|&
name|constraint
init|=
name|QSizeF
argument_list|()
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|which
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|constraint
argument_list|)
expr_stmt|;
return|return
name|QSizeF
argument_list|()
return|;
block|}
DECL|function|updateGeometry
name|void
name|updateGeometry
parameter_list|()
block|{
name|updateGeometryCalled
operator|++
expr_stmt|;
name|QGraphicsLayoutItem
operator|::
name|updateGeometry
argument_list|()
expr_stmt|;
block|}
DECL|member|updateGeometryCalled
name|int
name|updateGeometryCalled
decl_stmt|;
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
name|tst_QGraphicsLayoutItem
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
name|tst_QGraphicsLayoutItem
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
name|tst_QGraphicsLayoutItem
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
name|tst_QGraphicsLayoutItem
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|qgraphicslayoutitem
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|qgraphicslayoutitem
parameter_list|()
block|{
name|SubQGraphicsLayoutItem
name|layoutItem
decl_stmt|;
name|layoutItem
operator|.
name|contentsRect
argument_list|()
expr_stmt|;
name|layoutItem
operator|.
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|MinimumSize
argument_list|)
expr_stmt|;
name|layoutItem
operator|.
name|geometry
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|isLayout
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|layoutItem
operator|.
name|maximumSize
argument_list|()
expr_stmt|;
name|layoutItem
operator|.
name|minimumSize
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|parentLayoutItem
argument_list|()
argument_list|,
operator|(
name|QGraphicsLayoutItem
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|layoutItem
operator|.
name|preferredSize
argument_list|()
expr_stmt|;
name|layoutItem
operator|.
name|sizePolicy
argument_list|()
expr_stmt|;
name|layoutItem
operator|.
name|sizeHint
argument_list|(
name|Qt
operator|::
name|MinimumSize
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// QRectF contentsRect() const public
end_comment
begin_function
DECL|function|contentsRect
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|contentsRect
parameter_list|()
block|{
name|SubQGraphicsLayoutItem
name|layoutItem
decl_stmt|;
name|QRectF
name|f
init|=
name|layoutItem
operator|.
name|contentsRect
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|f
argument_list|,
name|QRectF
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Qt::SizeHint
argument_list|)
end_macro
begin_function
DECL|function|effectiveSizeHint_data
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|effectiveSizeHint_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|SizeHint
argument_list|>
argument_list|(
literal|"sizeHint"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"constraint"
argument_list|)
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
literal|15
condition|;
operator|++
name|i
control|)
block|{
name|QTestData
modifier|&
name|data
init|=
name|QTest
operator|::
name|newRow
argument_list|(
name|QString
argument_list|(
literal|"%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|i
operator|%
literal|5
condition|)
block|{
case|case
literal|0
case|:
name|data
operator|<<
name|Qt
operator|::
name|MinimumSize
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|data
operator|<<
name|Qt
operator|::
name|PreferredSize
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|data
operator|<<
name|Qt
operator|::
name|MaximumSize
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|data
operator|<<
name|Qt
operator|::
name|MinimumDescent
expr_stmt|;
break|break;
case|case
literal|4
case|:
name|data
operator|<<
name|Qt
operator|::
name|NSizeHints
expr_stmt|;
break|break;
block|}
switch|switch
condition|(
name|i
operator|%
literal|3
condition|)
block|{
case|case
literal|0
case|:
name|data
operator|<<
name|QSizeF
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|data
operator|<<
name|QSizeF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|data
operator|<<
name|QSizeF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function
begin_comment
comment|// QSizeF effectiveSizeHint(Qt::SizeHint which, QSizeF const& constraint = QSize()) const public
end_comment
begin_function
DECL|function|effectiveSizeHint
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|effectiveSizeHint
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|Qt
operator|::
name|SizeHint
argument_list|,
name|sizeHint
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|constraint
argument_list|)
expr_stmt|;
name|SubQGraphicsLayoutItem
name|layoutItem
decl_stmt|;
name|QSizeF
name|r
init|=
name|layoutItem
operator|.
name|effectiveSizeHint
argument_list|(
name|sizeHint
argument_list|,
name|constraint
argument_list|)
decl_stmt|;
if|if
condition|(
name|constraint
operator|.
name|width
argument_list|()
operator|!=
operator|-
literal|1
condition|)
name|QCOMPARE
argument_list|(
name|r
operator|.
name|width
argument_list|()
argument_list|,
name|constraint
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|constraint
operator|.
name|height
argument_list|()
operator|!=
operator|-
literal|1
condition|)
name|QCOMPARE
argument_list|(
name|r
operator|.
name|height
argument_list|()
argument_list|,
name|constraint
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// void getContentsMargins(qreal* left, qreal* top, qreal* right, qreal* bottom) const public
end_comment
begin_function
DECL|function|getContentsMargins
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|getContentsMargins
parameter_list|()
block|{
name|SubQGraphicsLayoutItem
name|layoutItem
decl_stmt|;
name|qreal
name|left
decl_stmt|;
name|qreal
name|top
decl_stmt|;
name|qreal
name|right
decl_stmt|;
name|qreal
name|bottom
decl_stmt|;
name|layoutItem
operator|.
name|getContentsMargins
argument_list|(
operator|&
name|left
argument_list|,
operator|&
name|top
argument_list|,
operator|&
name|right
argument_list|,
operator|&
name|bottom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|left
argument_list|,
operator|(
name|qreal
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|top
argument_list|,
operator|(
name|qreal
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|right
argument_list|,
operator|(
name|qreal
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bottom
argument_list|,
operator|(
name|qreal
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isLayout_data
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|isLayout_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"isLayout"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"no"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"yes"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|// bool isLayout() const public
end_comment
begin_function
DECL|function|isLayout
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|isLayout
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isLayout
argument_list|)
expr_stmt|;
name|SubQGraphicsLayoutItem
name|layoutItem
argument_list|(
literal|0
argument_list|,
name|isLayout
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|isLayout
argument_list|()
argument_list|,
name|isLayout
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// QSizeF maximumSize() const public
end_comment
begin_function
DECL|function|maximumSize
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|maximumSize
parameter_list|()
block|{
name|SubQGraphicsLayoutItem
name|layoutItem
decl_stmt|;
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|maximumSize
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
name|QWIDGETSIZE_MAX
argument_list|,
name|QWIDGETSIZE_MAX
argument_list|)
argument_list|)
expr_stmt|;
comment|// layoutItem.effectiveSizeHint(Qt::MaximumSize);
block|}
end_function
begin_comment
comment|// QSizeF minimumSize() const public
end_comment
begin_function
DECL|function|minimumSize
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|minimumSize
parameter_list|()
block|{
name|SubQGraphicsLayoutItem
name|layoutItem
decl_stmt|;
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|minimumSize
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|// layoutItem.effectiveSizeHint(Qt::MinimumSize);
block|}
end_function
begin_function
DECL|function|parentLayoutItem_data
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|parentLayoutItem_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"parent"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"no"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"yes"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|// QGraphicsLayoutItem* parentLayoutItem() const public
end_comment
begin_function
DECL|function|parentLayoutItem
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|parentLayoutItem
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|parent
argument_list|)
expr_stmt|;
name|SubQGraphicsLayoutItem
name|parentLayout
decl_stmt|;
name|SubQGraphicsLayoutItem
name|layoutItem
argument_list|(
name|parent
condition|?
operator|&
name|parentLayout
else|:
literal|0
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|parentLayoutItem
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|QGraphicsLayoutItem
operator|*
argument_list|>
argument_list|(
name|parent
condition|?
operator|&
name|parentLayout
else|:
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// QSizeF preferredSize() const public
end_comment
begin_function
DECL|function|preferredSize
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|preferredSize
parameter_list|()
block|{
name|SubQGraphicsLayoutItem
name|layoutItem
decl_stmt|;
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|preferredSize
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|// layoutItem.effectiveSizeHint(Qt::PreferredSize));
block|}
end_function
begin_function
DECL|function|setMaximumSize_data
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|setMaximumSize_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"outputSize"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"-1"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
operator|<<
name|QSizeF
argument_list|(
name|QWIDGETSIZE_MAX
argument_list|,
name|QWIDGETSIZE_MAX
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// void setMaximumSize(QSizeF const& size) public
end_comment
begin_function
DECL|function|setMaximumSize
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|setMaximumSize
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|outputSize
argument_list|)
expr_stmt|;
name|SubQGraphicsLayoutItem
name|layoutItem
decl_stmt|;
name|QSizeF
name|oldSize
init|=
name|layoutItem
operator|.
name|maximumSize
argument_list|()
decl_stmt|;
name|layoutItem
operator|.
name|setMaximumSize
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|size
operator|.
name|isValid
argument_list|()
condition|)
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|updateGeometryCalled
argument_list|,
operator|(
name|oldSize
operator|==
name|size
operator|)
condition|?
literal|0
else|:
literal|1
argument_list|)
expr_stmt|;
else|else
name|QVERIFY
argument_list|(
operator|!
name|layoutItem
operator|.
name|updateGeometryCalled
argument_list|)
expr_stmt|;
name|layoutItem
operator|.
name|setMinimumSize
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layoutItem
operator|.
name|maximumSize
argument_list|()
operator|.
name|width
argument_list|()
operator|<=
name|outputSize
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layoutItem
operator|.
name|maximumSize
argument_list|()
operator|.
name|height
argument_list|()
operator|<=
name|outputSize
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layoutItem
operator|.
name|minimumSize
argument_list|()
operator|.
name|width
argument_list|()
operator|<=
name|outputSize
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layoutItem
operator|.
name|minimumSize
argument_list|()
operator|.
name|height
argument_list|()
operator|<=
name|outputSize
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layoutItem
operator|.
name|preferredSize
argument_list|()
operator|.
name|width
argument_list|()
operator|<=
name|outputSize
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layoutItem
operator|.
name|preferredSize
argument_list|()
operator|.
name|height
argument_list|()
operator|<=
name|outputSize
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setMinimumSize_data
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|setMinimumSize_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"outputSize"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"-1"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// void setMinimumSize(QSizeF const& size) public
end_comment
begin_function
DECL|function|setMinimumSize
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|setMinimumSize
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|outputSize
argument_list|)
expr_stmt|;
name|SubQGraphicsLayoutItem
name|layoutItem
decl_stmt|;
name|QSizeF
name|oldSize
init|=
name|layoutItem
operator|.
name|minimumSize
argument_list|()
decl_stmt|;
name|layoutItem
operator|.
name|setMinimumSize
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|size
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QEXPECT_FAIL
argument_list|(
literal|"0"
argument_list|,
literal|"updateGeometry() is called when it doesn't have to be."
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|updateGeometryCalled
argument_list|,
operator|(
name|oldSize
operator|==
name|size
operator|)
condition|?
literal|0
else|:
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QVERIFY
argument_list|(
operator|!
name|layoutItem
operator|.
name|updateGeometryCalled
argument_list|)
expr_stmt|;
block|}
name|layoutItem
operator|.
name|setMaximumSize
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|"10"
argument_list|,
literal|"layoutItem.maximumSize().width()< size.width()"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layoutItem
operator|.
name|maximumSize
argument_list|()
operator|.
name|width
argument_list|()
operator|>=
name|size
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layoutItem
operator|.
name|maximumSize
argument_list|()
operator|.
name|height
argument_list|()
operator|>=
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layoutItem
operator|.
name|minimumSize
argument_list|()
operator|.
name|width
argument_list|()
operator|>=
name|size
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layoutItem
operator|.
name|minimumSize
argument_list|()
operator|.
name|height
argument_list|()
operator|>=
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layoutItem
operator|.
name|preferredSize
argument_list|()
operator|.
name|width
argument_list|()
operator|>=
name|size
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layoutItem
operator|.
name|preferredSize
argument_list|()
operator|.
name|height
argument_list|()
operator|>=
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setPreferredSize_data
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|setPreferredSize_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizeF
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"-1"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10"
argument_list|)
operator|<<
name|QSizeF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// void setPreferredSize(QSizeF const& size) public
end_comment
begin_function
DECL|function|setPreferredSize
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|setPreferredSize
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QSizeF
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|SubQGraphicsLayoutItem
name|layoutItem
decl_stmt|;
name|QSizeF
name|oldSize
init|=
name|layoutItem
operator|.
name|preferredSize
argument_list|()
decl_stmt|;
name|layoutItem
operator|.
name|setPreferredSize
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|size
operator|.
name|isValid
argument_list|()
condition|)
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|preferredSize
argument_list|()
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|size
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QEXPECT_FAIL
argument_list|(
literal|"0"
argument_list|,
literal|"updateGeometry() is called when it doesn't have to be."
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|updateGeometryCalled
argument_list|,
operator|(
name|oldSize
operator|==
name|size
operator|)
condition|?
literal|0
else|:
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QVERIFY
argument_list|(
operator|!
name|layoutItem
operator|.
name|updateGeometryCalled
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setPreferredSize2
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|setPreferredSize2
parameter_list|()
block|{
name|SubQGraphicsLayoutItem
name|layoutItem
decl_stmt|;
name|layoutItem
operator|.
name|setPreferredSize
argument_list|(
name|QSizeF
argument_list|(
literal|30
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|preferredWidth
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|30
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setSizePolicy_data
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|setSizePolicy_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSizePolicy
argument_list|>
argument_list|(
literal|"policy"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"default"
argument_list|)
operator|<<
name|QSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|DefaultType
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rand"
argument_list|)
operator|<<
name|QSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Preferred
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// void setSizePolicy(QSizePolicy const& policy) public
end_comment
begin_function
DECL|function|setSizePolicy
name|void
name|tst_QGraphicsLayoutItem
operator|::
name|setSizePolicy
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QSizePolicy
argument_list|,
name|policy
argument_list|)
expr_stmt|;
name|SubQGraphicsLayoutItem
name|layoutItem
decl_stmt|;
name|QSizePolicy
name|defaultPolicy
argument_list|(
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|DefaultType
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|sizePolicy
argument_list|()
argument_list|,
name|defaultPolicy
argument_list|)
expr_stmt|;
name|layoutItem
operator|.
name|setSizePolicy
argument_list|(
name|policy
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|sizePolicy
argument_list|()
argument_list|,
name|policy
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layoutItem
operator|.
name|updateGeometryCalled
argument_list|,
operator|(
name|defaultPolicy
operator|==
name|policy
operator|)
condition|?
literal|0
else|:
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGraphicsLayoutItem
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qgraphicslayoutitem.moc"
end_include
end_unit
