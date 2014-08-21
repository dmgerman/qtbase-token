begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPixmap>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_define
DECL|macro|ITERATION_COUNT
define|#
directive|define
name|ITERATION_COUNT
value|1e5
end_define
begin_class
DECL|class|tst_qvariant
class|class
name|tst_qvariant
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|testBound
parameter_list|()
function_decl|;
name|void
name|doubleVariantCreation
parameter_list|()
function_decl|;
name|void
name|floatVariantCreation
parameter_list|()
function_decl|;
name|void
name|rectVariantCreation
parameter_list|()
function_decl|;
name|void
name|stringVariantCreation
parameter_list|()
function_decl|;
name|void
name|pixmapVariantCreation
parameter_list|()
function_decl|;
name|void
name|stringListVariantCreation
parameter_list|()
function_decl|;
name|void
name|bigClassVariantCreation
parameter_list|()
function_decl|;
name|void
name|smallClassVariantCreation
parameter_list|()
function_decl|;
name|void
name|doubleVariantSetValue
parameter_list|()
function_decl|;
name|void
name|floatVariantSetValue
parameter_list|()
function_decl|;
name|void
name|rectVariantSetValue
parameter_list|()
function_decl|;
name|void
name|stringVariantSetValue
parameter_list|()
function_decl|;
name|void
name|stringListVariantSetValue
parameter_list|()
function_decl|;
name|void
name|bigClassVariantSetValue
parameter_list|()
function_decl|;
name|void
name|smallClassVariantSetValue
parameter_list|()
function_decl|;
name|void
name|doubleVariantAssignment
parameter_list|()
function_decl|;
name|void
name|floatVariantAssignment
parameter_list|()
function_decl|;
name|void
name|rectVariantAssignment
parameter_list|()
function_decl|;
name|void
name|stringVariantAssignment
parameter_list|()
function_decl|;
name|void
name|stringListVariantAssignment
parameter_list|()
function_decl|;
name|void
name|doubleVariantValue
parameter_list|()
function_decl|;
name|void
name|floatVariantValue
parameter_list|()
function_decl|;
name|void
name|rectVariantValue
parameter_list|()
function_decl|;
name|void
name|stringVariantValue
parameter_list|()
function_decl|;
name|void
name|createCoreType_data
parameter_list|()
function_decl|;
name|void
name|createCoreType
parameter_list|()
function_decl|;
name|void
name|createCoreTypeCopy_data
parameter_list|()
function_decl|;
name|void
name|createCoreTypeCopy
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_struct
DECL|struct|BigClass
struct|struct
name|BigClass
block|{
DECL|member|n
DECL|member|i
DECL|member|e
DECL|member|r
DECL|member|o
DECL|member|b
name|double
name|n
decl_stmt|,
name|i
decl_stmt|,
name|e
decl_stmt|,
name|r
decl_stmt|,
name|o
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|BigClass
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|QVariant
operator|::
name|Private
operator|::
name|Data
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_TYPEINFO
parameter_list|(
name|BigClass
parameter_list|,
name|Q_MOVABLE_TYPE
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
parameter_list|(
name|BigClass
parameter_list|)
function_decl|;
end_function_decl
begin_struct
DECL|struct|SmallClass
struct|struct
name|SmallClass
block|{
DECL|member|s
name|char
name|s
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|SmallClass
argument_list|)
operator|<=
sizeof|sizeof
argument_list|(
name|QVariant
operator|::
name|Private
operator|::
name|Data
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_TYPEINFO
parameter_list|(
name|SmallClass
parameter_list|,
name|Q_MOVABLE_TYPE
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
parameter_list|(
name|SmallClass
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|testBound
name|void
name|tst_qvariant
operator|::
name|testBound
parameter_list|()
block|{
name|qreal
name|d
init|=
name|qreal
argument_list|(
literal|.5
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ITERATION_COUNT
condition|;
operator|++
name|i
control|)
block|{
name|d
operator|=
name|qBound
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|0
argument_list|,
name|d
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|variantCreation
specifier|static
name|void
name|variantCreation
parameter_list|(
name|T
name|val
parameter_list|)
block|{
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ITERATION_COUNT
condition|;
operator|++
name|i
control|)
block|{
name|QVariant
name|v
argument_list|(
name|val
argument_list|)
decl_stmt|;
block|}
block|}
block|}
end_function
begin_function
template|template
parameter_list|<>
DECL|function|variantCreation
name|void
name|variantCreation
argument_list|<
name|BigClass
argument_list|>
parameter_list|(
name|BigClass
name|val
parameter_list|)
block|{
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ITERATION_COUNT
condition|;
operator|++
name|i
control|)
block|{
name|QVariant
operator|::
name|fromValue
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
template|template
parameter_list|<>
DECL|function|variantCreation
name|void
name|variantCreation
argument_list|<
name|SmallClass
argument_list|>
parameter_list|(
name|SmallClass
name|val
parameter_list|)
block|{
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ITERATION_COUNT
condition|;
operator|++
name|i
control|)
block|{
name|QVariant
operator|::
name|fromValue
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|doubleVariantCreation
name|void
name|tst_qvariant
operator|::
name|doubleVariantCreation
parameter_list|()
block|{
name|variantCreation
argument_list|<
name|double
argument_list|>
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|floatVariantCreation
name|void
name|tst_qvariant
operator|::
name|floatVariantCreation
parameter_list|()
block|{
name|variantCreation
argument_list|<
name|float
argument_list|>
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rectVariantCreation
name|void
name|tst_qvariant
operator|::
name|rectVariantCreation
parameter_list|()
block|{
name|variantCreation
argument_list|<
name|QRect
argument_list|>
argument_list|(
name|QRect
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stringVariantCreation
name|void
name|tst_qvariant
operator|::
name|stringVariantCreation
parameter_list|()
block|{
name|variantCreation
argument_list|<
name|QString
argument_list|>
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pixmapVariantCreation
name|void
name|tst_qvariant
operator|::
name|pixmapVariantCreation
parameter_list|()
block|{
name|variantCreation
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
name|QPixmap
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stringListVariantCreation
name|void
name|tst_qvariant
operator|::
name|stringListVariantCreation
parameter_list|()
block|{
name|variantCreation
argument_list|<
name|QStringList
argument_list|>
argument_list|(
name|QStringList
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bigClassVariantCreation
name|void
name|tst_qvariant
operator|::
name|bigClassVariantCreation
parameter_list|()
block|{
name|variantCreation
argument_list|<
name|BigClass
argument_list|>
argument_list|(
name|BigClass
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|smallClassVariantCreation
name|void
name|tst_qvariant
operator|::
name|smallClassVariantCreation
parameter_list|()
block|{
name|variantCreation
argument_list|<
name|SmallClass
argument_list|>
argument_list|(
name|SmallClass
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|variantSetValue
specifier|static
name|void
name|variantSetValue
parameter_list|(
name|T
name|d
parameter_list|)
block|{
name|QVariant
name|v
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ITERATION_COUNT
condition|;
operator|++
name|i
control|)
block|{
name|v
operator|.
name|setValue
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|doubleVariantSetValue
name|void
name|tst_qvariant
operator|::
name|doubleVariantSetValue
parameter_list|()
block|{
name|variantSetValue
argument_list|<
name|double
argument_list|>
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|floatVariantSetValue
name|void
name|tst_qvariant
operator|::
name|floatVariantSetValue
parameter_list|()
block|{
name|variantSetValue
argument_list|<
name|float
argument_list|>
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rectVariantSetValue
name|void
name|tst_qvariant
operator|::
name|rectVariantSetValue
parameter_list|()
block|{
name|variantSetValue
argument_list|<
name|QRect
argument_list|>
argument_list|(
name|QRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stringVariantSetValue
name|void
name|tst_qvariant
operator|::
name|stringVariantSetValue
parameter_list|()
block|{
name|variantSetValue
argument_list|<
name|QString
argument_list|>
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stringListVariantSetValue
name|void
name|tst_qvariant
operator|::
name|stringListVariantSetValue
parameter_list|()
block|{
name|variantSetValue
argument_list|<
name|QStringList
argument_list|>
argument_list|(
name|QStringList
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bigClassVariantSetValue
name|void
name|tst_qvariant
operator|::
name|bigClassVariantSetValue
parameter_list|()
block|{
name|variantSetValue
argument_list|<
name|BigClass
argument_list|>
argument_list|(
name|BigClass
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|smallClassVariantSetValue
name|void
name|tst_qvariant
operator|::
name|smallClassVariantSetValue
parameter_list|()
block|{
name|variantSetValue
argument_list|<
name|SmallClass
argument_list|>
argument_list|(
name|SmallClass
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|variantAssignment
specifier|static
name|void
name|variantAssignment
parameter_list|(
name|T
name|d
parameter_list|)
block|{
name|QVariant
name|v
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ITERATION_COUNT
condition|;
operator|++
name|i
control|)
block|{
name|v
operator|=
name|d
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|doubleVariantAssignment
name|void
name|tst_qvariant
operator|::
name|doubleVariantAssignment
parameter_list|()
block|{
name|variantAssignment
argument_list|<
name|double
argument_list|>
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|floatVariantAssignment
name|void
name|tst_qvariant
operator|::
name|floatVariantAssignment
parameter_list|()
block|{
name|variantAssignment
argument_list|<
name|float
argument_list|>
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rectVariantAssignment
name|void
name|tst_qvariant
operator|::
name|rectVariantAssignment
parameter_list|()
block|{
name|variantAssignment
argument_list|<
name|QRect
argument_list|>
argument_list|(
name|QRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stringVariantAssignment
name|void
name|tst_qvariant
operator|::
name|stringVariantAssignment
parameter_list|()
block|{
name|variantAssignment
argument_list|<
name|QString
argument_list|>
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stringListVariantAssignment
name|void
name|tst_qvariant
operator|::
name|stringListVariantAssignment
parameter_list|()
block|{
name|variantAssignment
argument_list|<
name|QStringList
argument_list|>
argument_list|(
name|QStringList
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doubleVariantValue
name|void
name|tst_qvariant
operator|::
name|doubleVariantValue
parameter_list|()
block|{
name|QVariant
name|v
argument_list|(
literal|0.0
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ITERATION_COUNT
condition|;
operator|++
name|i
control|)
block|{
name|v
operator|.
name|toDouble
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|floatVariantValue
name|void
name|tst_qvariant
operator|::
name|floatVariantValue
parameter_list|()
block|{
name|QVariant
name|v
argument_list|(
literal|0.0f
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ITERATION_COUNT
condition|;
operator|++
name|i
control|)
block|{
name|v
operator|.
name|toFloat
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|rectVariantValue
name|void
name|tst_qvariant
operator|::
name|rectVariantValue
parameter_list|()
block|{
name|QVariant
name|v
argument_list|(
name|QRect
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ITERATION_COUNT
condition|;
operator|++
name|i
control|)
block|{
name|v
operator|.
name|toRect
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|stringVariantValue
name|void
name|tst_qvariant
operator|::
name|stringVariantValue
parameter_list|()
block|{
name|QVariant
name|v
init|=
name|QString
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ITERATION_COUNT
condition|;
operator|++
name|i
control|)
block|{
name|v
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|createCoreType_data
name|void
name|tst_qvariant
operator|::
name|createCoreType_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"typeId"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|QMetaType
operator|::
name|FirstCoreType
init|;
name|i
operator|<=
name|QMetaType
operator|::
name|LastCoreType
condition|;
operator|++
name|i
control|)
name|QTest
operator|::
name|newRow
argument_list|(
name|QMetaType
operator|::
name|typeName
argument_list|(
name|i
argument_list|)
argument_list|)
operator|<<
name|i
expr_stmt|;
block|}
end_function
begin_comment
comment|// Tests how fast a Qt core type can be default-constructed by a
end_comment
begin_comment
comment|// QVariant. The purpose of this benchmark is to measure the overhead
end_comment
begin_comment
comment|// of creating (and destroying) a QVariant compared to creating the
end_comment
begin_comment
comment|// type directly.
end_comment
begin_function
DECL|function|createCoreType
name|void
name|tst_qvariant
operator|::
name|createCoreType
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ITERATION_COUNT
condition|;
operator|++
name|i
control|)
name|QVariant
argument_list|(
name|typeId
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createCoreTypeCopy_data
name|void
name|tst_qvariant
operator|::
name|createCoreTypeCopy_data
parameter_list|()
block|{
name|createCoreType_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// Tests how fast a Qt core type can be copy-constructed by a
end_comment
begin_comment
comment|// QVariant. The purpose of this benchmark is to measure the overhead
end_comment
begin_comment
comment|// of creating (and destroying) a QVariant compared to creating the
end_comment
begin_comment
comment|// type directly.
end_comment
begin_function
DECL|function|createCoreTypeCopy
name|void
name|tst_qvariant
operator|::
name|createCoreTypeCopy
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|QVariant
name|other
argument_list|(
name|typeId
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
decl_stmt|;
specifier|const
name|void
modifier|*
name|copy
init|=
name|other
operator|.
name|constData
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ITERATION_COUNT
condition|;
operator|++
name|i
control|)
name|QVariant
argument_list|(
name|typeId
argument_list|,
name|copy
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qvariant
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qvariant.moc"
end_include
end_unit
