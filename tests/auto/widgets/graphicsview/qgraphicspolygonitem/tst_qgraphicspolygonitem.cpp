begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qpen.h>
end_include
begin_class
DECL|class|tst_QGraphicsPolygonItem
class|class
name|tst_QGraphicsPolygonItem
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|qgraphicspolygonitem_data
parameter_list|()
function_decl|;
name|void
name|qgraphicspolygonitem
parameter_list|()
function_decl|;
name|void
name|boundingRect_data
parameter_list|()
function_decl|;
name|void
name|boundingRect
parameter_list|()
function_decl|;
name|void
name|contains_data
parameter_list|()
function_decl|;
name|void
name|contains
parameter_list|()
function_decl|;
name|void
name|fillRule_data
parameter_list|()
function_decl|;
name|void
name|fillRule
parameter_list|()
function_decl|;
name|void
name|isObscuredBy_data
parameter_list|()
function_decl|;
name|void
name|isObscuredBy
parameter_list|()
function_decl|;
name|void
name|opaqueArea_data
parameter_list|()
function_decl|;
name|void
name|opaqueArea
parameter_list|()
function_decl|;
name|void
name|polygon_data
parameter_list|()
function_decl|;
name|void
name|polygon
parameter_list|()
function_decl|;
name|void
name|shape_data
parameter_list|()
function_decl|;
name|void
name|shape
parameter_list|()
function_decl|;
name|void
name|extension_data
parameter_list|()
function_decl|;
name|void
name|extension
parameter_list|()
function_decl|;
name|void
name|setExtension_data
parameter_list|()
function_decl|;
name|void
name|setExtension
parameter_list|()
function_decl|;
name|void
name|supportsExtension_data
parameter_list|()
function_decl|;
name|void
name|supportsExtension
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// Subclass that exposes the protected functions.
end_comment
begin_class
DECL|class|SubQGraphicsPolygonItem
class|class
name|SubQGraphicsPolygonItem
super|:
specifier|public
name|QGraphicsPolygonItem
block|{
public|public:
DECL|enum|Extension
enum|enum
name|Extension
block|{
DECL|enumerator|UserExtension
name|UserExtension
init|=
name|QGraphicsItem
operator|::
name|UserExtension
block|}
enum|;
DECL|function|SubQGraphicsPolygonItem
name|SubQGraphicsPolygonItem
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QGraphicsPolygonItem
argument_list|(
name|parent
argument_list|)
block|{     }
DECL|function|SubQGraphicsPolygonItem
name|SubQGraphicsPolygonItem
parameter_list|(
specifier|const
name|QPolygonF
modifier|&
name|polygon
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QGraphicsPolygonItem
argument_list|(
name|polygon
argument_list|,
name|parent
argument_list|)
block|{     }
DECL|function|call_extension
name|QVariant
name|call_extension
parameter_list|(
name|QVariant
specifier|const
modifier|&
name|variant
parameter_list|)
specifier|const
block|{
return|return
name|SubQGraphicsPolygonItem
operator|::
name|extension
argument_list|(
name|variant
argument_list|)
return|;
block|}
DECL|function|call_setExtension
name|void
name|call_setExtension
parameter_list|(
name|SubQGraphicsPolygonItem
operator|::
name|Extension
name|extension
parameter_list|,
name|QVariant
specifier|const
modifier|&
name|variant
parameter_list|)
block|{
return|return
name|SubQGraphicsPolygonItem
operator|::
name|setExtension
argument_list|(
operator|(
name|QGraphicsItem
operator|::
name|Extension
operator|)
name|extension
argument_list|,
name|variant
argument_list|)
return|;
block|}
DECL|function|call_supportsExtension
name|bool
name|call_supportsExtension
parameter_list|(
name|SubQGraphicsPolygonItem
operator|::
name|Extension
name|extension
parameter_list|)
specifier|const
block|{
return|return
name|SubQGraphicsPolygonItem
operator|::
name|supportsExtension
argument_list|(
operator|(
name|QGraphicsItem
operator|::
name|Extension
operator|)
name|extension
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|qgraphicspolygonitem_data
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|qgraphicspolygonitem_data
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|qgraphicspolygonitem
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|qgraphicspolygonitem
parameter_list|()
block|{
name|SubQGraphicsPolygonItem
name|item
decl_stmt|;
name|item
operator|.
name|boundingRect
argument_list|()
expr_stmt|;
name|item
operator|.
name|contains
argument_list|(
name|QPoint
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|.
name|isObscuredBy
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|item
operator|.
name|opaqueArea
argument_list|()
expr_stmt|;
comment|//item.paint();
name|item
operator|.
name|shape
argument_list|()
expr_stmt|;
name|item
operator|.
name|type
argument_list|()
expr_stmt|;
name|item
operator|.
name|call_extension
argument_list|(
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|.
name|call_setExtension
argument_list|(
name|SubQGraphicsPolygonItem
operator|::
name|UserExtension
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|.
name|call_supportsExtension
argument_list|(
name|SubQGraphicsPolygonItem
operator|::
name|UserExtension
argument_list|)
expr_stmt|;
name|item
operator|.
name|fillRule
argument_list|()
expr_stmt|;
name|item
operator|.
name|polygon
argument_list|()
expr_stmt|;
name|item
operator|.
name|setFillRule
argument_list|(
name|Qt
operator|::
name|OddEvenFill
argument_list|)
expr_stmt|;
name|item
operator|.
name|setPolygon
argument_list|(
name|QPolygonF
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|boundingRect_data
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|boundingRect_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPolygonF
argument_list|>
argument_list|(
literal|"polygon"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRectF
argument_list|>
argument_list|(
literal|"boundingRect"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QPolygonF
argument_list|()
operator|<<
name|QRectF
argument_list|()
expr_stmt|;
name|QPolygonF
name|example
decl_stmt|;
name|example
operator|<<
name|QPointF
argument_list|(
literal|10.4
argument_list|,
literal|20.5
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|20.2
argument_list|,
literal|30.2
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"example"
argument_list|)
operator|<<
name|example
operator|<<
name|example
operator|.
name|boundingRect
argument_list|()
expr_stmt|;
comment|// ### set pen width?
block|}
end_function
begin_comment
comment|// public QRectF boundingRect() const
end_comment
begin_function
DECL|function|boundingRect
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|boundingRect
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPolygonF
argument_list|,
name|polygon
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|boundingRect
argument_list|)
expr_stmt|;
name|SubQGraphicsPolygonItem
name|item
argument_list|(
name|polygon
argument_list|)
decl_stmt|;
name|item
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|item
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|boundingRect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|contains_data
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|contains_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPolygonF
argument_list|>
argument_list|(
literal|"polygon"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPointF
argument_list|>
argument_list|(
literal|"point"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"contains"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QPolygonF
argument_list|()
operator|<<
name|QPointF
argument_list|()
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_comment
comment|// public bool contains(QPointF const& point) const
end_comment
begin_function
DECL|function|contains
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|contains
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPolygonF
argument_list|,
name|polygon
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPointF
argument_list|,
name|point
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|contains
argument_list|)
expr_stmt|;
name|SubQGraphicsPolygonItem
name|item
argument_list|(
name|polygon
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|item
operator|.
name|contains
argument_list|(
name|point
argument_list|)
argument_list|,
name|contains
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Qt::FillRule
argument_list|)
end_macro
begin_function
DECL|function|fillRule_data
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|fillRule_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPolygonF
argument_list|>
argument_list|(
literal|"polygon"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|FillRule
argument_list|>
argument_list|(
literal|"fillRule"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"OddEvenFill"
argument_list|)
operator|<<
name|QPolygonF
argument_list|()
operator|<<
name|Qt
operator|::
name|OddEvenFill
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"WindingFill"
argument_list|)
operator|<<
name|QPolygonF
argument_list|()
operator|<<
name|Qt
operator|::
name|WindingFill
expr_stmt|;
block|}
end_function
begin_comment
comment|// public Qt::FillRule fillRule() const
end_comment
begin_function
DECL|function|fillRule
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|fillRule
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPolygonF
argument_list|,
name|polygon
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|Qt
operator|::
name|FillRule
argument_list|,
name|fillRule
argument_list|)
expr_stmt|;
name|SubQGraphicsPolygonItem
name|item
argument_list|(
name|polygon
argument_list|)
decl_stmt|;
name|item
operator|.
name|setFillRule
argument_list|(
name|fillRule
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|item
operator|.
name|fillRule
argument_list|()
argument_list|,
name|fillRule
argument_list|)
expr_stmt|;
comment|// ### Check that the painting is different?
block|}
end_function
begin_function
DECL|function|isObscuredBy_data
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|isObscuredBy_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPolygonF
argument_list|>
argument_list|(
literal|"polygon"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPolygonF
argument_list|>
argument_list|(
literal|"otherPolygon"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"isObscuredBy"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QPolygonF
argument_list|()
operator|<<
name|QPolygonF
argument_list|()
operator|<<
literal|false
expr_stmt|;
comment|//QTest::newRow("ontop-inside")<< QPixmap(10, 10)<< QPixmap(5, 5)<< false;
comment|//QTest::newRow("ontop-larger")<< QPixmap(10, 10)<< QPixmap(11, 11)<< true;
block|}
end_function
begin_comment
comment|// public bool isObscuredBy(QGraphicsItem const* item) const
end_comment
begin_function
DECL|function|isObscuredBy
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|isObscuredBy
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPolygonF
argument_list|,
name|polygon
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPolygonF
argument_list|,
name|otherPolygon
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isObscuredBy
argument_list|)
expr_stmt|;
name|SubQGraphicsPolygonItem
name|item
argument_list|(
name|polygon
argument_list|)
decl_stmt|;
name|SubQGraphicsPolygonItem
name|otherItem
argument_list|(
name|otherPolygon
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|item
operator|.
name|isObscuredBy
argument_list|(
operator|&
name|otherItem
argument_list|)
argument_list|,
name|isObscuredBy
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QPainterPath
argument_list|)
end_macro
begin_function
DECL|function|opaqueArea_data
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|opaqueArea_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPolygonF
argument_list|>
argument_list|(
literal|"polygon"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPainterPath
argument_list|>
argument_list|(
literal|"opaqueArea"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QPolygonF
argument_list|()
operator|<<
name|QPainterPath
argument_list|()
expr_stmt|;
comment|// Currently QGraphicsPolygonItem just calls QGraphicsItem test there
block|}
end_function
begin_comment
comment|// public QPainterPath opaqueArea() const
end_comment
begin_function
DECL|function|opaqueArea
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|opaqueArea
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPolygonF
argument_list|,
name|polygon
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPainterPath
argument_list|,
name|opaqueArea
argument_list|)
expr_stmt|;
name|SubQGraphicsPolygonItem
name|item
argument_list|(
name|polygon
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|item
operator|.
name|opaqueArea
argument_list|()
argument_list|,
name|opaqueArea
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|polygon_data
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|polygon_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPolygonF
argument_list|>
argument_list|(
literal|"polygon"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QPolygonF
argument_list|()
expr_stmt|;
name|QPolygonF
name|example
decl_stmt|;
name|example
operator|<<
name|QPointF
argument_list|(
literal|10.4
argument_list|,
literal|20.5
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|20.2
argument_list|,
literal|30.2
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"example"
argument_list|)
operator|<<
name|example
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QPolygonF polygon() const
end_comment
begin_function
DECL|function|polygon
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|polygon
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPolygonF
argument_list|,
name|polygon
argument_list|)
expr_stmt|;
name|SubQGraphicsPolygonItem
name|item
decl_stmt|;
name|item
operator|.
name|setPolygon
argument_list|(
name|polygon
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|item
operator|.
name|polygon
argument_list|()
argument_list|,
name|polygon
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|shape_data
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|shape_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPainterPath
argument_list|>
argument_list|(
literal|"shape"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QPainterPath
argument_list|()
expr_stmt|;
comment|// ### what should a normal shape look like?
block|}
end_function
begin_comment
comment|// public QPainterPath shape() const
end_comment
begin_function
DECL|function|shape
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|shape
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPainterPath
argument_list|,
name|shape
argument_list|)
expr_stmt|;
name|SubQGraphicsPolygonItem
name|item
decl_stmt|;
name|QCOMPARE
argument_list|(
name|item
operator|.
name|shape
argument_list|()
argument_list|,
name|shape
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|extension_data
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|extension_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
argument_list|>
argument_list|(
literal|"variant"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
argument_list|>
argument_list|(
literal|"extension"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QVariant
argument_list|()
operator|<<
name|QVariant
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// protected QVariant extension(QVariant const& variant) const
end_comment
begin_function
DECL|function|extension
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|extension
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|variant
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|extension
argument_list|)
expr_stmt|;
name|SubQGraphicsPolygonItem
name|item
decl_stmt|;
name|QCOMPARE
argument_list|(
name|item
operator|.
name|call_extension
argument_list|(
name|variant
argument_list|)
argument_list|,
name|extension
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|SubQGraphicsPolygonItem::Extension
argument_list|)
end_macro
begin_function
DECL|function|setExtension_data
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|setExtension_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|SubQGraphicsPolygonItem
operator|::
name|Extension
argument_list|>
argument_list|(
literal|"extension"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
argument_list|>
argument_list|(
literal|"variant"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|SubQGraphicsPolygonItem
operator|::
name|Extension
argument_list|()
operator|<<
name|QVariant
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// protected void setExtension(SubQGraphicsPolygonItem::Extension extension, QVariant const& variant)
end_comment
begin_function
DECL|function|setExtension
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|setExtension
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|SubQGraphicsPolygonItem
operator|::
name|Extension
argument_list|,
name|extension
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|variant
argument_list|)
expr_stmt|;
name|SubQGraphicsPolygonItem
name|item
decl_stmt|;
name|item
operator|.
name|call_setExtension
argument_list|(
name|extension
argument_list|,
name|variant
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|supportsExtension_data
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|supportsExtension_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|SubQGraphicsPolygonItem
operator|::
name|Extension
argument_list|>
argument_list|(
literal|"extension"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"supportsExtension"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|SubQGraphicsPolygonItem
operator|::
name|Extension
argument_list|()
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_comment
comment|// protected bool supportsExtension(SubQGraphicsPolygonItem::Extension extension) const
end_comment
begin_function
DECL|function|supportsExtension
name|void
name|tst_QGraphicsPolygonItem
operator|::
name|supportsExtension
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|SubQGraphicsPolygonItem
operator|::
name|Extension
argument_list|,
name|extension
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|supportsExtension
argument_list|)
expr_stmt|;
name|SubQGraphicsPolygonItem
name|item
decl_stmt|;
name|QCOMPARE
argument_list|(
name|item
operator|.
name|call_supportsExtension
argument_list|(
name|extension
argument_list|)
argument_list|,
name|supportsExtension
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGraphicsPolygonItem
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qgraphicspolygonitem.moc"
end_include
end_unit
