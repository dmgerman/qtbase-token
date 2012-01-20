begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QTransform>
end_include
begin_class
DECL|class|tst_QTransform
class|class
name|tst_QTransform
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QTransform
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QTransform
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
name|translate_data
parameter_list|()
function_decl|;
name|void
name|translate
parameter_list|()
function_decl|;
name|void
name|scale_data
parameter_list|()
function_decl|;
name|void
name|scale
parameter_list|()
function_decl|;
name|void
name|shear_data
parameter_list|()
function_decl|;
name|void
name|shear
parameter_list|()
function_decl|;
name|void
name|rotate_data
parameter_list|()
function_decl|;
name|void
name|rotate
parameter_list|()
function_decl|;
name|void
name|rotateXYZ_data
parameter_list|()
function_decl|;
name|void
name|rotateXYZ
parameter_list|()
function_decl|;
name|void
name|operatorAssign_data
parameter_list|()
function_decl|;
name|void
name|operatorAssign
parameter_list|()
function_decl|;
name|void
name|operatorEqual_data
parameter_list|()
function_decl|;
name|void
name|operatorEqual
parameter_list|()
function_decl|;
name|void
name|operatorNotEqual_data
parameter_list|()
function_decl|;
name|void
name|operatorNotEqual
parameter_list|()
function_decl|;
name|void
name|operatorMultiply_data
parameter_list|()
function_decl|;
name|void
name|operatorMultiply
parameter_list|()
function_decl|;
name|void
name|operatorPlusEqualScalar_data
parameter_list|()
function_decl|;
name|void
name|operatorPlusEqualScalar
parameter_list|()
function_decl|;
name|void
name|operatorMinusEqualScalar_data
parameter_list|()
function_decl|;
name|void
name|operatorMinusEqualScalar
parameter_list|()
function_decl|;
name|void
name|operatorMultiplyEqual_data
parameter_list|()
function_decl|;
name|void
name|operatorMultiplyEqual
parameter_list|()
function_decl|;
name|void
name|operatorMultiplyEqualScalar_data
parameter_list|()
function_decl|;
name|void
name|operatorMultiplyEqualScalar
parameter_list|()
function_decl|;
name|void
name|operatorDivideEqualScalar_data
parameter_list|()
function_decl|;
name|void
name|operatorDivideEqualScalar
parameter_list|()
function_decl|;
name|void
name|mapQPoint_data
parameter_list|()
function_decl|;
name|void
name|mapQPoint
parameter_list|()
function_decl|;
name|void
name|mapQPointF_data
parameter_list|()
function_decl|;
name|void
name|mapQPointF
parameter_list|()
function_decl|;
name|void
name|mapRect_data
parameter_list|()
function_decl|;
name|void
name|mapRect
parameter_list|()
function_decl|;
name|void
name|mapRectF_data
parameter_list|()
function_decl|;
name|void
name|mapRectF
parameter_list|()
function_decl|;
name|void
name|mapQPolygon_data
parameter_list|()
function_decl|;
name|void
name|mapQPolygon
parameter_list|()
function_decl|;
name|void
name|mapQPolygonF_data
parameter_list|()
function_decl|;
name|void
name|mapQPolygonF
parameter_list|()
function_decl|;
name|void
name|mapQRegion_data
parameter_list|()
function_decl|;
name|void
name|mapQRegion
parameter_list|()
function_decl|;
name|void
name|mapToPolygon_data
parameter_list|()
function_decl|;
name|void
name|mapToPolygon
parameter_list|()
function_decl|;
name|void
name|mapQPainterPath_data
parameter_list|()
function_decl|;
name|void
name|mapQPainterPath
parameter_list|()
function_decl|;
name|void
name|isIdentity_data
parameter_list|()
function_decl|;
name|void
name|isIdentity
parameter_list|()
function_decl|;
name|void
name|isAffine_data
parameter_list|()
function_decl|;
name|void
name|isAffine
parameter_list|()
function_decl|;
name|void
name|isInvertible_data
parameter_list|()
function_decl|;
name|void
name|isInvertible
parameter_list|()
function_decl|;
name|void
name|isRotating_data
parameter_list|()
function_decl|;
name|void
name|isRotating
parameter_list|()
function_decl|;
name|void
name|isScaling_data
parameter_list|()
function_decl|;
name|void
name|isScaling
parameter_list|()
function_decl|;
name|void
name|isTranslating_data
parameter_list|()
function_decl|;
name|void
name|isTranslating
parameter_list|()
function_decl|;
name|void
name|type_data
parameter_list|()
function_decl|;
name|void
name|type
parameter_list|()
function_decl|;
name|void
name|determinant_data
parameter_list|()
function_decl|;
name|void
name|determinant
parameter_list|()
function_decl|;
name|void
name|adjoint_data
parameter_list|()
function_decl|;
name|void
name|adjoint
parameter_list|()
function_decl|;
name|void
name|transposed_data
parameter_list|()
function_decl|;
name|void
name|transposed
parameter_list|()
function_decl|;
name|void
name|inverted_data
parameter_list|()
function_decl|;
name|void
name|inverted
parameter_list|()
function_decl|;
private|private:
name|QMap
argument_list|<
specifier|const
name|char
modifier|*
argument_list|,
name|QTransform
argument_list|>
name|generateTransforms
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QTransform
name|tst_QTransform
operator|::
name|tst_QTransform
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QTransform
name|tst_QTransform
operator|::
name|~
name|tst_QTransform
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_QTransform
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QTransform
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|generateTransforms
name|QMap
argument_list|<
specifier|const
name|char
modifier|*
argument_list|,
name|QTransform
argument_list|>
name|tst_QTransform
operator|::
name|generateTransforms
parameter_list|()
specifier|const
block|{
name|QMap
argument_list|<
specifier|const
name|char
modifier|*
argument_list|,
name|QTransform
argument_list|>
name|x
decl_stmt|;
name|x
index|[
literal|"0: identity"
index|]
operator|=
name|QTransform
argument_list|()
expr_stmt|;
name|x
index|[
literal|"1: translate"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|translate
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|x
index|[
literal|"2: translate"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|translate
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|)
expr_stmt|;
name|x
index|[
literal|"3: rotate45"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|45
argument_list|)
expr_stmt|;
name|x
index|[
literal|"4: rotate90"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|90
argument_list|)
expr_stmt|;
name|x
index|[
literal|"5: rotate180"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|180
argument_list|)
expr_stmt|;
name|x
index|[
literal|"6: shear2,2"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|shear
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|x
index|[
literal|"7: shear-2,-2"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|shear
argument_list|(
operator|-
literal|2
argument_list|,
operator|-
literal|2
argument_list|)
expr_stmt|;
name|x
index|[
literal|"8: scaleUp2,2"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|scale
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|x
index|[
literal|"9: scaleUp2,3"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|scale
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|x
index|[
literal|"10: scaleDown0.5,0.5"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|scale
argument_list|(
literal|0.5
argument_list|,
literal|0.5
argument_list|)
expr_stmt|;
name|x
index|[
literal|"11: scaleDown0.5,0.25"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|scale
argument_list|(
literal|0.5
argument_list|,
literal|0.25
argument_list|)
expr_stmt|;
name|x
index|[
literal|"12: rotateX"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|XAxis
argument_list|)
expr_stmt|;
name|x
index|[
literal|"13: rotateY"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|YAxis
argument_list|)
expr_stmt|;
name|x
index|[
literal|"14: rotateXY"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|XAxis
argument_list|)
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|YAxis
argument_list|)
expr_stmt|;
name|x
index|[
literal|"15: rotateYZ"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|YAxis
argument_list|)
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|ZAxis
argument_list|)
expr_stmt|;
name|x
index|[
literal|"16: full"
index|]
operator|=
name|QTransform
argument_list|()
operator|.
name|translate
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
operator|.
name|rotate
argument_list|(
literal|45
argument_list|)
operator|.
name|shear
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
operator|.
name|scale
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|YAxis
argument_list|)
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|XAxis
argument_list|)
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|ZAxis
argument_list|)
expr_stmt|;
return|return
name|x
return|;
block|}
end_function
begin_function
DECL|function|construct
name|void
name|tst_QTransform
operator|::
name|construct
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QTransform
name|x
decl_stmt|;
block|}
block|}
end_function
begin_define
DECL|macro|SINGLE_DATA_IMPLEMENTATION
define|#
directive|define
name|SINGLE_DATA_IMPLEMENTATION
parameter_list|(
name|func
parameter_list|)
define|\
value|void tst_QTransform::func##_data() \ { \     QTest::addColumn<QTransform>("transform"); \     QMap<const char *, QTransform> x = generateTransforms(); \     QMapIterator<const char *, QTransform> it(x); \     while (it.hasNext()) { \         it.next(); \         QTest::newRow(it.key())<< it.value(); \     } \ }
end_define
begin_define
DECL|macro|DOUBLE_DATA_IMPLEMENTATION
define|#
directive|define
name|DOUBLE_DATA_IMPLEMENTATION
parameter_list|(
name|func
parameter_list|)
define|\
value|void tst_QTransform::func##_data() \ { \     QTest::addColumn<QTransform>("x1"); \     QTest::addColumn<QTransform>("x2"); \     QMap<const char *, QTransform> x = generateTransforms(); \     QMapIterator<const char *, QTransform> it(x); \     while (it.hasNext()) { \         it.next(); \         const char *key1 = it.key(); \         QTransform x1 = it.value(); \         QMapIterator<const char *, QTransform> it2(x); \         while (it2.hasNext()) { \             it2.next(); \             QTest::newRow(QString("%1 + %2").arg(key1).arg(it2.key()).toLatin1().constData()) \<< x1<< it2.value(); \         } \     } \ }
end_define
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|translate
argument_list|)
end_macro
begin_function
DECL|function|translate
name|void
name|tst_QTransform
operator|::
name|translate
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|translate
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|scale
argument_list|)
end_macro
begin_function
DECL|function|scale
name|void
name|tst_QTransform
operator|::
name|scale
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|scale
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|shear
argument_list|)
end_macro
begin_function
DECL|function|shear
name|void
name|tst_QTransform
operator|::
name|shear
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|shear
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|rotate
argument_list|)
end_macro
begin_function
DECL|function|rotate
name|void
name|tst_QTransform
operator|::
name|rotate
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|rotate
argument_list|(
literal|45
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|rotateXYZ
argument_list|)
end_macro
begin_function
DECL|function|rotateXYZ
name|void
name|tst_QTransform
operator|::
name|rotateXYZ
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|XAxis
argument_list|)
expr_stmt|;
name|x
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|YAxis
argument_list|)
expr_stmt|;
name|x
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|ZAxis
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|DOUBLE_DATA_IMPLEMENTATION
argument_list|(
argument|operatorAssign
argument_list|)
end_macro
begin_function
DECL|function|operatorAssign
name|void
name|tst_QTransform
operator|::
name|operatorAssign
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|x1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|x2
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|x1
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|=
name|x2
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|DOUBLE_DATA_IMPLEMENTATION
argument_list|(
argument|operatorEqual
argument_list|)
end_macro
begin_function
DECL|function|operatorEqual
name|void
name|tst_QTransform
operator|::
name|operatorEqual
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|x1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|x2
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|x1
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|==
name|x2
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|DOUBLE_DATA_IMPLEMENTATION
argument_list|(
argument|operatorNotEqual
argument_list|)
end_macro
begin_function
DECL|function|operatorNotEqual
name|void
name|tst_QTransform
operator|::
name|operatorNotEqual
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|x1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|x2
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|x1
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|!=
name|x2
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|DOUBLE_DATA_IMPLEMENTATION
argument_list|(
argument|operatorMultiply
argument_list|)
end_macro
begin_function
DECL|function|operatorMultiply
name|void
name|tst_QTransform
operator|::
name|operatorMultiply
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|x1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|x2
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|x1
decl_stmt|;
name|QBENCHMARK
block|{
name|x
modifier|*
name|x2
decl_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|operatorPlusEqualScalar
argument_list|)
end_macro
begin_function
DECL|function|operatorPlusEqualScalar
name|void
name|tst_QTransform
operator|::
name|operatorPlusEqualScalar
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|+=
literal|3.14
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|operatorMinusEqualScalar
argument_list|)
end_macro
begin_function
DECL|function|operatorMinusEqualScalar
name|void
name|tst_QTransform
operator|::
name|operatorMinusEqualScalar
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|-=
literal|3.14
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|DOUBLE_DATA_IMPLEMENTATION
argument_list|(
argument|operatorMultiplyEqual
argument_list|)
end_macro
begin_function
DECL|function|operatorMultiplyEqual
name|void
name|tst_QTransform
operator|::
name|operatorMultiplyEqual
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|x1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|x2
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|x1
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|*=
name|x2
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|operatorMultiplyEqualScalar
argument_list|)
end_macro
begin_function
DECL|function|operatorMultiplyEqualScalar
name|void
name|tst_QTransform
operator|::
name|operatorMultiplyEqualScalar
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|*
literal|3
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|operatorDivideEqualScalar
argument_list|)
end_macro
begin_function
DECL|function|operatorDivideEqualScalar
name|void
name|tst_QTransform
operator|::
name|operatorDivideEqualScalar
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|/=
literal|3
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|mapQPoint
argument_list|)
end_macro
begin_function
DECL|function|mapQPoint
name|void
name|tst_QTransform
operator|::
name|mapQPoint
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|map
argument_list|(
name|QPoint
argument_list|(
literal|3
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|mapQPointF
argument_list|)
end_macro
begin_function
DECL|function|mapQPointF
name|void
name|tst_QTransform
operator|::
name|mapQPointF
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|map
argument_list|(
name|QPointF
argument_list|(
literal|3
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|mapRect
argument_list|)
end_macro
begin_function
DECL|function|mapRect
name|void
name|tst_QTransform
operator|::
name|mapRect
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|mapRect
argument_list|(
name|QRect
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
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|mapRectF
argument_list|)
end_macro
begin_function
DECL|function|mapRectF
name|void
name|tst_QTransform
operator|::
name|mapRectF
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|mapRect
argument_list|(
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
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|mapQPolygon
argument_list|)
end_macro
begin_function
DECL|function|mapQPolygon
name|void
name|tst_QTransform
operator|::
name|mapQPolygon
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QPolygon
name|poly
init|=
name|QPolygon
argument_list|(
name|QRect
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
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|map
argument_list|(
name|poly
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|mapQPolygonF
argument_list|)
end_macro
begin_function
DECL|function|mapQPolygonF
name|void
name|tst_QTransform
operator|::
name|mapQPolygonF
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QPolygonF
name|poly
init|=
name|QPolygonF
argument_list|(
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
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|map
argument_list|(
name|poly
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|mapQRegion
argument_list|)
end_macro
begin_function
DECL|function|mapQRegion
name|void
name|tst_QTransform
operator|::
name|mapQRegion
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QRegion
name|region
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
operator|++
name|i
control|)
name|region
operator|+=
name|QRect
argument_list|(
name|i
operator|*
literal|10
argument_list|,
name|i
operator|*
literal|10
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|map
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|mapToPolygon
argument_list|)
end_macro
begin_function
DECL|function|mapToPolygon
name|void
name|tst_QTransform
operator|::
name|mapToPolygon
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|mapToPolygon
argument_list|(
name|QRect
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
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|mapQPainterPath
argument_list|)
end_macro
begin_function
DECL|function|mapQPainterPath
name|void
name|tst_QTransform
operator|::
name|mapQPainterPath
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QTransform
name|x
init|=
name|transform
decl_stmt|;
name|QPainterPath
name|path
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
operator|++
name|i
control|)
name|path
operator|.
name|addEllipse
argument_list|(
name|i
operator|*
literal|10
argument_list|,
name|i
operator|*
literal|10
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|x
operator|.
name|map
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|isIdentity
argument_list|)
end_macro
begin_function
DECL|function|isIdentity
name|void
name|tst_QTransform
operator|::
name|isIdentity
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|transform
operator|.
name|isIdentity
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|isAffine
argument_list|)
end_macro
begin_function
DECL|function|isAffine
name|void
name|tst_QTransform
operator|::
name|isAffine
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|transform
operator|.
name|isAffine
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|isInvertible
argument_list|)
end_macro
begin_function
DECL|function|isInvertible
name|void
name|tst_QTransform
operator|::
name|isInvertible
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|transform
operator|.
name|isInvertible
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|isRotating
argument_list|)
end_macro
begin_function
DECL|function|isRotating
name|void
name|tst_QTransform
operator|::
name|isRotating
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|transform
operator|.
name|isRotating
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|isScaling
argument_list|)
end_macro
begin_function
DECL|function|isScaling
name|void
name|tst_QTransform
operator|::
name|isScaling
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|transform
operator|.
name|isScaling
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|isTranslating
argument_list|)
end_macro
begin_function
DECL|function|isTranslating
name|void
name|tst_QTransform
operator|::
name|isTranslating
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|transform
operator|.
name|isTranslating
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|type
argument_list|)
end_macro
begin_function
DECL|function|type
name|void
name|tst_QTransform
operator|::
name|type
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|transform
operator|.
name|type
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|determinant
argument_list|)
end_macro
begin_function
DECL|function|determinant
name|void
name|tst_QTransform
operator|::
name|determinant
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|transform
operator|.
name|determinant
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|adjoint
argument_list|)
end_macro
begin_function
DECL|function|adjoint
name|void
name|tst_QTransform
operator|::
name|adjoint
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|transform
operator|.
name|adjoint
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|transposed
argument_list|)
end_macro
begin_function
DECL|function|transposed
name|void
name|tst_QTransform
operator|::
name|transposed
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|transform
operator|.
name|transposed
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|SINGLE_DATA_IMPLEMENTATION
argument_list|(
argument|inverted
argument_list|)
end_macro
begin_function
DECL|function|inverted
name|void
name|tst_QTransform
operator|::
name|inverted
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|transform
operator|.
name|inverted
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QTransform
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtransform.moc"
end_include
end_unit
