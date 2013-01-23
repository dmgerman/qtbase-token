begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|"../../../qtest-config.h"
end_include
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QMetaType::Type
argument_list|)
end_macro
begin_class
DECL|class|tst_QGuiMetaType
class|class
name|tst_QGuiMetaType
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|create_data
parameter_list|()
function_decl|;
name|void
name|create
parameter_list|()
function_decl|;
name|void
name|createCopy_data
parameter_list|()
function_decl|;
name|void
name|createCopy
parameter_list|()
function_decl|;
name|void
name|sizeOf_data
parameter_list|()
function_decl|;
name|void
name|sizeOf
parameter_list|()
function_decl|;
name|void
name|flags_data
parameter_list|()
function_decl|;
name|void
name|flags
parameter_list|()
function_decl|;
name|void
name|construct_data
parameter_list|()
function_decl|;
name|void
name|construct
parameter_list|()
function_decl|;
name|void
name|constructCopy_data
parameter_list|()
function_decl|;
name|void
name|constructCopy
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_define
DECL|macro|FOR_EACH_GUI_METATYPE
define|#
directive|define
name|FOR_EACH_GUI_METATYPE
parameter_list|(
name|F
parameter_list|)
define|\
value|F(QFont, QFont) \     F(QPixmap, QPixmap) \     F(QBrush, QBrush) \     F(QColor, QColor) \     F(QPalette, QPalette) \     F(QImage, QImage) \     F(QPolygon, QPolygon) \     F(QRegion, QRegion) \     F(QBitmap, QBitmap) \     F(QCursor, QCursor) \     F(QKeySequence, QKeySequence) \     F(QPen, QPen) \     F(QTextLength, QTextLength) \     F(QTextFormat, QTextFormat) \     F(QMatrix, QMatrix) \     F(QTransform, QTransform) \     F(QMatrix4x4, QMatrix4x4) \     F(QVector2D, QVector2D) \     F(QVector3D, QVector3D) \     F(QVector4D, QVector4D) \     F(QQuaternion, QQuaternion)
end_define
begin_namespace
namespace|namespace
block|{
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
struct|struct
DECL|struct|static_assert_trigger
name|static_assert_trigger
block|{
name|Q_STATIC_ASSERT
argument_list|(
argument|( QMetaTypeId2<T>::IsBuiltIn )
argument_list|)
empty_stmt|;
DECL|enumerator|value
enum|enum
block|{
name|value
init|=
literal|true
block|}
enum|;
block|}
struct|;
block|}
end_namespace
begin_define
DECL|macro|CHECK_BUILTIN
define|#
directive|define
name|CHECK_BUILTIN
parameter_list|(
name|TYPE
parameter_list|,
name|ID
parameter_list|)
value|static_assert_trigger< TYPE>::value&&
end_define
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|(
name|FOR_EACH_GUI_METATYPE
argument_list|(
name|CHECK_BUILTIN
argument_list|)
literal|true
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_undef
DECL|macro|CHECK_BUILTIN
undef|#
directive|undef
name|CHECK_BUILTIN
end_undef
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|(
operator|!
name|QMetaTypeId2
argument_list|<
name|QList
argument_list|<
name|QPen
argument_list|>
argument_list|>
operator|::
name|IsBuiltIn
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|(
operator|!
name|QMetaTypeId2
argument_list|<
name|QMap
argument_list|<
name|QString
argument_list|,
name|QPen
argument_list|>
argument_list|>
operator|::
name|IsBuiltIn
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_struct
template|template
parameter_list|<
name|int
name|ID
parameter_list|>
struct|struct
DECL|struct|MetaEnumToType
name|MetaEnumToType
block|{
block|}
struct|;
end_struct
begin_define
DECL|macro|DEFINE_META_ENUM_TO_TYPE
define|#
directive|define
name|DEFINE_META_ENUM_TO_TYPE
parameter_list|(
name|TYPE
parameter_list|,
name|ID
parameter_list|)
define|\
value|template<> \ struct MetaEnumToType<QMetaType::ID> { \     typedef TYPE Type; \ };
end_define
begin_macro
name|FOR_EACH_GUI_METATYPE
argument_list|(
argument|DEFINE_META_ENUM_TO_TYPE
argument_list|)
end_macro
begin_undef
DECL|macro|DEFINE_META_ENUM_TO_TYPE
undef|#
directive|undef
name|DEFINE_META_ENUM_TO_TYPE
end_undef
begin_comment
comment|// Not all types have operator==
end_comment
begin_struct
template|template
parameter_list|<
name|int
name|ID
parameter_list|>
struct|struct
DECL|struct|TypeComparator
name|TypeComparator
block|{
DECL|typedef|Type
typedef|typedef
typename|typename
name|MetaEnumToType
argument_list|<
name|ID
argument_list|>
operator|::
name|Type
name|Type
typedef|;
DECL|function|equal
specifier|static
name|bool
name|equal
parameter_list|(
specifier|const
name|Type
modifier|&
name|v1
parameter_list|,
specifier|const
name|Type
modifier|&
name|v2
parameter_list|)
block|{
return|return
name|v1
operator|==
name|v2
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TypeComparator
template|template
parameter_list|<>
struct|struct
name|TypeComparator
argument_list|<
name|QMetaType
operator|::
name|QPixmap
argument_list|>
block|{
DECL|function|equal
specifier|static
name|bool
name|equal
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|v1
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|v2
parameter_list|)
block|{
return|return
name|v1
operator|.
name|size
argument_list|()
operator|==
name|v2
operator|.
name|size
argument_list|()
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TypeComparator
template|template
parameter_list|<>
struct|struct
name|TypeComparator
argument_list|<
name|QMetaType
operator|::
name|QBitmap
argument_list|>
block|{
DECL|function|equal
specifier|static
name|bool
name|equal
parameter_list|(
specifier|const
name|QBitmap
modifier|&
name|v1
parameter_list|,
specifier|const
name|QBitmap
modifier|&
name|v2
parameter_list|)
block|{
return|return
name|v1
operator|.
name|size
argument_list|()
operator|==
name|v2
operator|.
name|size
argument_list|()
return|;
block|}
block|}
struct|;
end_struct
begin_ifndef
ifndef|#
directive|ifndef
name|QTEST_NO_CURSOR
end_ifndef
begin_struct
DECL|struct|TypeComparator
template|template
parameter_list|<>
struct|struct
name|TypeComparator
argument_list|<
name|QMetaType
operator|::
name|QCursor
argument_list|>
block|{
DECL|function|equal
specifier|static
name|bool
name|equal
parameter_list|(
specifier|const
name|QCursor
modifier|&
name|v1
parameter_list|,
specifier|const
name|QCursor
modifier|&
name|v2
parameter_list|)
block|{
return|return
name|v1
operator|.
name|shape
argument_list|()
operator|==
name|v2
operator|.
name|shape
argument_list|()
return|;
block|}
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_struct
template|template
parameter_list|<
name|int
name|ID
parameter_list|>
struct|struct
DECL|struct|DefaultValueFactory
name|DefaultValueFactory
block|{
DECL|typedef|Type
typedef|typedef
typename|typename
name|MetaEnumToType
argument_list|<
name|ID
argument_list|>
operator|::
name|Type
name|Type
typedef|;
DECL|function|create
specifier|static
name|Type
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|Type
return|;
block|}
block|}
struct|;
end_struct
begin_struct
template|template
parameter_list|<
name|int
name|ID
parameter_list|>
struct|struct
DECL|struct|TestValueFactory
name|TestValueFactory
block|{
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QFont
argument_list|>
block|{
DECL|function|create
specifier|static
name|QFont
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QFont
argument_list|(
literal|"Arial"
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QPixmap
argument_list|>
block|{
DECL|function|create
specifier|static
name|QPixmap
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QPixmap
argument_list|(
literal|16
argument_list|,
literal|32
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QBrush
argument_list|>
block|{
DECL|function|create
specifier|static
name|QBrush
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QBrush
argument_list|(
name|Qt
operator|::
name|SolidPattern
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QColor
argument_list|>
block|{
DECL|function|create
specifier|static
name|QColor
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QPalette
argument_list|>
block|{
DECL|function|create
specifier|static
name|QPalette
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QPalette
argument_list|(
name|Qt
operator|::
name|yellow
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QImage
argument_list|>
block|{
DECL|function|create
specifier|static
name|QImage
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QImage
argument_list|(
literal|16
argument_list|,
literal|32
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QPolygon
argument_list|>
block|{
DECL|function|create
specifier|static
name|QPolygon
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QPolygon
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|,
literal|true
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QRegion
argument_list|>
block|{
DECL|function|create
specifier|static
name|QRegion
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QRegion
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|,
name|QRegion
operator|::
name|Ellipse
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QBitmap
argument_list|>
block|{
DECL|function|create
specifier|static
name|QBitmap
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QBitmap
argument_list|(
literal|16
argument_list|,
literal|32
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_ifndef
ifndef|#
directive|ifndef
name|QTEST_NO_CURSOR
end_ifndef
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QCursor
argument_list|>
block|{
DECL|function|create
specifier|static
name|QCursor
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QKeySequence
argument_list|>
block|{
DECL|function|create
specifier|static
name|QKeySequence
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QKeySequence
argument_list|(
name|QKeySequence
operator|::
name|Close
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QPen
argument_list|>
block|{
DECL|function|create
specifier|static
name|QPen
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QPen
argument_list|(
name|Qt
operator|::
name|DashDotDotLine
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QTextLength
argument_list|>
block|{
DECL|function|create
specifier|static
name|QTextLength
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QTextLength
argument_list|(
name|QTextLength
operator|::
name|PercentageLength
argument_list|,
literal|50
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QTextFormat
argument_list|>
block|{
DECL|function|create
specifier|static
name|QTextFormat
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QTextFormat
argument_list|(
name|QTextFormat
operator|::
name|TableFormat
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QMatrix
argument_list|>
block|{
DECL|function|create
specifier|static
name|QMatrix
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QMatrix
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|,
literal|50
argument_list|,
literal|60
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QTransform
argument_list|>
block|{
DECL|function|create
specifier|static
name|QTransform
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QTransform
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|,
literal|50
argument_list|,
literal|60
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QMatrix4x4
argument_list|>
block|{
DECL|function|create
specifier|static
name|QMatrix4x4
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QMatrix4x4
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|,
literal|8
argument_list|,
literal|9
argument_list|,
literal|10
argument_list|,
literal|11
argument_list|,
literal|12
argument_list|,
literal|13
argument_list|,
literal|14
argument_list|,
literal|15
argument_list|,
literal|16
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QVector2D
argument_list|>
block|{
DECL|function|create
specifier|static
name|QVector2D
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QVector2D
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QVector3D
argument_list|>
block|{
DECL|function|create
specifier|static
name|QVector3D
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QVector3D
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QVector4D
argument_list|>
block|{
DECL|function|create
specifier|static
name|QVector4D
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QVector4D
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestValueFactory
template|template
parameter_list|<>
struct|struct
name|TestValueFactory
argument_list|<
name|QMetaType
operator|::
name|QQuaternion
argument_list|>
block|{
DECL|function|create
specifier|static
name|QQuaternion
modifier|*
name|create
parameter_list|()
block|{
return|return
operator|new
name|QQuaternion
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_function
DECL|function|create_data
name|void
name|tst_QGuiMetaType
operator|::
name|create_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QMetaType
operator|::
name|Type
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
DECL|macro|ADD_METATYPE_TEST_ROW
define|#
directive|define
name|ADD_METATYPE_TEST_ROW
parameter_list|(
name|TYPE
parameter_list|,
name|ID
parameter_list|)
define|\
value|QTest::newRow(QMetaType::typeName(QMetaType::ID))<< QMetaType::ID;
name|FOR_EACH_GUI_METATYPE
argument_list|(
argument|ADD_METATYPE_TEST_ROW
argument_list|)
DECL|macro|ADD_METATYPE_TEST_ROW
undef|#
directive|undef
name|ADD_METATYPE_TEST_ROW
block|}
end_function
begin_function
template|template
parameter_list|<
name|int
name|ID
parameter_list|>
DECL|function|testCreateHelper
specifier|static
name|void
name|testCreateHelper
parameter_list|()
block|{
typedef|typedef
typename|typename
name|MetaEnumToType
argument_list|<
name|ID
argument_list|>
operator|::
name|Type
name|Type
typedef|;
name|void
modifier|*
name|actual
init|=
name|QMetaType
operator|::
name|create
argument_list|(
name|ID
argument_list|)
decl_stmt|;
name|Type
modifier|*
name|expected
init|=
name|DefaultValueFactory
argument_list|<
name|ID
argument_list|>
operator|::
name|create
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|TypeComparator
argument_list|<
name|ID
argument_list|>
operator|::
name|equal
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|Type
operator|*
argument_list|>
argument_list|(
name|actual
argument_list|)
argument_list|,
operator|*
name|expected
argument_list|)
argument_list|)
expr_stmt|;
operator|delete
name|expected
expr_stmt|;
name|QMetaType
operator|::
name|destroy
argument_list|(
name|ID
argument_list|,
name|actual
argument_list|)
expr_stmt|;
block|}
end_function
begin_typedef
DECL|typedef|TypeTestFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|TypeTestFunction
function_decl|)
parameter_list|()
function_decl|;
end_typedef
begin_function
DECL|function|create
name|void
name|tst_QGuiMetaType
operator|::
name|create
parameter_list|()
block|{
struct|struct
name|TypeTestFunctionGetter
block|{
specifier|static
name|TypeTestFunction
name|get
parameter_list|(
name|int
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
DECL|macro|RETURN_CREATE_FUNCTION
define|#
directive|define
name|RETURN_CREATE_FUNCTION
parameter_list|(
name|TYPE
parameter_list|,
name|ID
parameter_list|)
define|\
value|case QMetaType::ID: \             return testCreateHelper<QMetaType::ID>;
name|FOR_EACH_GUI_METATYPE
argument_list|(
argument|RETURN_CREATE_FUNCTION
argument_list|)
DECL|macro|RETURN_CREATE_FUNCTION
undef|#
directive|undef
name|RETURN_CREATE_FUNCTION
block|}
return|return
literal|0
return|;
block|}
block|}
struct|;
name|QFETCH
argument_list|(
name|QMetaType
operator|::
name|Type
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|TypeTestFunctionGetter
operator|::
name|get
function_decl|(
name|type
function_decl|)
parameter_list|()
function_decl|;
block|}
end_function
begin_function
DECL|function|createCopy_data
name|void
name|tst_QGuiMetaType
operator|::
name|createCopy_data
parameter_list|()
block|{
name|create_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|int
name|ID
parameter_list|>
DECL|function|testCreateCopyHelper
specifier|static
name|void
name|testCreateCopyHelper
parameter_list|()
block|{
typedef|typedef
typename|typename
name|MetaEnumToType
argument_list|<
name|ID
argument_list|>
operator|::
name|Type
name|Type
typedef|;
name|Type
modifier|*
name|expected
init|=
name|TestValueFactory
argument_list|<
name|ID
argument_list|>
operator|::
name|create
argument_list|()
decl_stmt|;
name|void
modifier|*
name|actual
init|=
name|QMetaType
operator|::
name|create
argument_list|(
name|ID
argument_list|,
name|expected
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|TypeComparator
argument_list|<
name|ID
argument_list|>
operator|::
name|equal
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|Type
operator|*
argument_list|>
argument_list|(
name|actual
argument_list|)
argument_list|,
operator|*
name|expected
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaType
operator|::
name|destroy
argument_list|(
name|ID
argument_list|,
name|actual
argument_list|)
expr_stmt|;
operator|delete
name|expected
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createCopy
name|void
name|tst_QGuiMetaType
operator|::
name|createCopy
parameter_list|()
block|{
struct|struct
name|TypeTestFunctionGetter
block|{
specifier|static
name|TypeTestFunction
name|get
parameter_list|(
name|int
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
DECL|macro|RETURN_CREATE_COPY_FUNCTION
define|#
directive|define
name|RETURN_CREATE_COPY_FUNCTION
parameter_list|(
name|TYPE
parameter_list|,
name|ID
parameter_list|)
define|\
value|case QMetaType::ID: \             return testCreateCopyHelper<QMetaType::ID>;
name|FOR_EACH_GUI_METATYPE
argument_list|(
argument|RETURN_CREATE_COPY_FUNCTION
argument_list|)
DECL|macro|RETURN_CREATE_COPY_FUNCTION
undef|#
directive|undef
name|RETURN_CREATE_COPY_FUNCTION
block|}
return|return
literal|0
return|;
block|}
block|}
struct|;
name|QFETCH
argument_list|(
name|QMetaType
operator|::
name|Type
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|TypeTestFunctionGetter
operator|::
name|get
function_decl|(
name|type
function_decl|)
parameter_list|()
function_decl|;
block|}
end_function
begin_function
DECL|function|sizeOf_data
name|void
name|tst_QGuiMetaType
operator|::
name|sizeOf_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QMetaType
operator|::
name|Type
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
DECL|macro|ADD_METATYPE_TEST_ROW
define|#
directive|define
name|ADD_METATYPE_TEST_ROW
parameter_list|(
name|TYPE
parameter_list|,
name|ID
parameter_list|)
define|\
value|QTest::newRow(QMetaType::typeName(QMetaType::ID))<< QMetaType::ID<< int(sizeof(TYPE));
name|FOR_EACH_GUI_METATYPE
argument_list|(
argument|ADD_METATYPE_TEST_ROW
argument_list|)
DECL|macro|ADD_METATYPE_TEST_ROW
undef|#
directive|undef
name|ADD_METATYPE_TEST_ROW
block|}
end_function
begin_function
DECL|function|sizeOf
name|void
name|tst_QGuiMetaType
operator|::
name|sizeOf
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QMetaType
operator|::
name|Type
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|sizeOf
argument_list|(
name|type
argument_list|)
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|Q_ALIGNOF
end_ifndef
begin_struct
template|template
parameter_list|<
name|uint
name|N
parameter_list|>
struct|struct
DECL|struct|RoundToNextHighestPowerOfTwo
name|RoundToNextHighestPowerOfTwo
block|{
private|private:
DECL|enumerator|V1
enum|enum
block|{
name|V1
init|=
name|N
operator|-
literal|1
block|}
enum|;
DECL|enumerator|V2
enum|enum
block|{
name|V2
init|=
name|V1
operator||
operator|(
name|V1
operator|>>
literal|1
operator|)
block|}
enum|;
DECL|enumerator|V3
enum|enum
block|{
name|V3
init|=
name|V2
operator||
operator|(
name|V2
operator|>>
literal|2
operator|)
block|}
enum|;
DECL|enumerator|V4
enum|enum
block|{
name|V4
init|=
name|V3
operator||
operator|(
name|V3
operator|>>
literal|4
operator|)
block|}
enum|;
DECL|enumerator|V5
enum|enum
block|{
name|V5
init|=
name|V4
operator||
operator|(
name|V4
operator|>>
literal|8
operator|)
block|}
enum|;
DECL|enumerator|V6
enum|enum
block|{
name|V6
init|=
name|V5
operator||
operator|(
name|V5
operator|>>
literal|16
operator|)
block|}
enum|;
public|public:
DECL|enumerator|Value
enum|enum
block|{
name|Value
init|=
name|V6
operator|+
literal|1
block|}
enum|;
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_struct
template|template
parameter_list|<
name|class
name|T
parameter_list|>
struct|struct
DECL|struct|TypeAlignment
name|TypeAlignment
block|{
ifdef|#
directive|ifdef
name|Q_ALIGNOF
DECL|enumerator|Value
enum|enum
block|{
name|Value
init|=
name|Q_ALIGNOF
argument_list|(
argument|T
argument_list|)
block|}
enum|;
else|#
directive|else
enum|enum
block|{
name|Value
init|=
name|RoundToNextHighestPowerOfTwo
operator|<
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
operator|::
name|Value
block|}
enum|;
endif|#
directive|endif
block|}
struct|;
end_struct
begin_function
DECL|function|flags_data
name|void
name|tst_QGuiMetaType
operator|::
name|flags_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"isMovable"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"isComplex"
argument_list|)
expr_stmt|;
DECL|macro|ADD_METATYPE_TEST_ROW
define|#
directive|define
name|ADD_METATYPE_TEST_ROW
parameter_list|(
name|MetaTypeName
parameter_list|,
name|MetaTypeId
parameter_list|,
name|RealType
parameter_list|)
define|\
value|QTest::newRow(#RealType)<< MetaTypeId<< bool(!QTypeInfo<RealType>::isStatic)<< bool(QTypeInfo<RealType>::isComplex);
name|QT_FOR_EACH_STATIC_GUI_CLASS
argument_list|(
argument|ADD_METATYPE_TEST_ROW
argument_list|)
DECL|macro|ADD_METATYPE_TEST_ROW
undef|#
directive|undef
name|ADD_METATYPE_TEST_ROW
block|}
end_function
begin_function
DECL|function|flags
name|void
name|tst_QGuiMetaType
operator|::
name|flags
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isMovable
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isComplex
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bool
argument_list|(
name|QMetaType
operator|::
name|typeFlags
argument_list|(
name|type
argument_list|)
operator|&
name|QMetaType
operator|::
name|NeedsConstruction
argument_list|)
argument_list|,
name|isComplex
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bool
argument_list|(
name|QMetaType
operator|::
name|typeFlags
argument_list|(
name|type
argument_list|)
operator|&
name|QMetaType
operator|::
name|NeedsDestruction
argument_list|)
argument_list|,
name|isComplex
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bool
argument_list|(
name|QMetaType
operator|::
name|typeFlags
argument_list|(
name|type
argument_list|)
operator|&
name|QMetaType
operator|::
name|MovableType
argument_list|)
argument_list|,
name|isMovable
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|construct_data
name|void
name|tst_QGuiMetaType
operator|::
name|construct_data
parameter_list|()
block|{
name|create_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|int
name|ID
parameter_list|>
DECL|function|testConstructHelper
specifier|static
name|void
name|testConstructHelper
parameter_list|()
block|{
typedef|typedef
typename|typename
name|MetaEnumToType
argument_list|<
name|ID
argument_list|>
operator|::
name|Type
name|Type
typedef|;
name|int
name|size
init|=
name|QMetaType
operator|::
name|sizeOf
argument_list|(
name|ID
argument_list|)
decl_stmt|;
name|void
modifier|*
name|storage
init|=
name|qMallocAligned
argument_list|(
name|size
argument_list|,
name|TypeAlignment
argument_list|<
name|Type
argument_list|>
operator|::
name|Value
argument_list|)
decl_stmt|;
name|void
modifier|*
name|actual
init|=
name|QMetaType
operator|::
name|construct
argument_list|(
name|ID
argument_list|,
name|storage
argument_list|,
comment|/*copy=*/
literal|0
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|actual
argument_list|,
name|storage
argument_list|)
expr_stmt|;
name|Type
modifier|*
name|expected
init|=
name|DefaultValueFactory
argument_list|<
name|ID
argument_list|>
operator|::
name|create
argument_list|()
decl_stmt|;
name|QVERIFY2
argument_list|(
name|TypeComparator
argument_list|<
name|ID
argument_list|>
operator|::
name|equal
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|Type
operator|*
argument_list|>
argument_list|(
name|actual
argument_list|)
argument_list|,
operator|*
name|expected
argument_list|)
argument_list|,
name|QMetaType
operator|::
name|typeName
argument_list|(
name|ID
argument_list|)
argument_list|)
expr_stmt|;
operator|delete
name|expected
expr_stmt|;
name|QMetaType
operator|::
name|destruct
argument_list|(
name|ID
argument_list|,
name|actual
argument_list|)
expr_stmt|;
name|qFreeAligned
argument_list|(
name|storage
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|construct
name|void
name|tst_QGuiMetaType
operator|::
name|construct
parameter_list|()
block|{
struct|struct
name|TypeTestFunctionGetter
block|{
specifier|static
name|TypeTestFunction
name|get
parameter_list|(
name|int
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
DECL|macro|RETURN_CONSTRUCT_FUNCTION
define|#
directive|define
name|RETURN_CONSTRUCT_FUNCTION
parameter_list|(
name|TYPE
parameter_list|,
name|ID
parameter_list|)
define|\
value|case QMetaType::ID: \             return testConstructHelper<QMetaType::ID>;
name|FOR_EACH_GUI_METATYPE
argument_list|(
argument|RETURN_CONSTRUCT_FUNCTION
argument_list|)
DECL|macro|RETURN_CONSTRUCT_FUNCTION
undef|#
directive|undef
name|RETURN_CONSTRUCT_FUNCTION
block|}
return|return
literal|0
return|;
block|}
block|}
struct|;
name|QFETCH
argument_list|(
name|QMetaType
operator|::
name|Type
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|TypeTestFunctionGetter
operator|::
name|get
function_decl|(
name|type
function_decl|)
parameter_list|()
function_decl|;
block|}
end_function
begin_function
DECL|function|constructCopy_data
name|void
name|tst_QGuiMetaType
operator|::
name|constructCopy_data
parameter_list|()
block|{
name|create_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|int
name|ID
parameter_list|>
DECL|function|testConstructCopyHelper
specifier|static
name|void
name|testConstructCopyHelper
parameter_list|()
block|{
typedef|typedef
typename|typename
name|MetaEnumToType
argument_list|<
name|ID
argument_list|>
operator|::
name|Type
name|Type
typedef|;
name|Type
modifier|*
name|expected
init|=
name|TestValueFactory
argument_list|<
name|ID
argument_list|>
operator|::
name|create
argument_list|()
decl_stmt|;
name|int
name|size
init|=
name|QMetaType
operator|::
name|sizeOf
argument_list|(
name|ID
argument_list|)
decl_stmt|;
name|void
modifier|*
name|storage
init|=
name|qMallocAligned
argument_list|(
name|size
argument_list|,
name|TypeAlignment
argument_list|<
name|Type
argument_list|>
operator|::
name|Value
argument_list|)
decl_stmt|;
name|void
modifier|*
name|actual
init|=
name|QMetaType
operator|::
name|construct
argument_list|(
name|ID
argument_list|,
name|storage
argument_list|,
name|expected
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|actual
argument_list|,
name|storage
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|TypeComparator
argument_list|<
name|ID
argument_list|>
operator|::
name|equal
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|Type
operator|*
argument_list|>
argument_list|(
name|actual
argument_list|)
argument_list|,
operator|*
name|expected
argument_list|)
argument_list|,
name|QMetaType
operator|::
name|typeName
argument_list|(
name|ID
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaType
operator|::
name|destruct
argument_list|(
name|ID
argument_list|,
name|actual
argument_list|)
expr_stmt|;
name|qFreeAligned
argument_list|(
name|storage
argument_list|)
expr_stmt|;
operator|delete
name|expected
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructCopy
name|void
name|tst_QGuiMetaType
operator|::
name|constructCopy
parameter_list|()
block|{
struct|struct
name|TypeTestFunctionGetter
block|{
specifier|static
name|TypeTestFunction
name|get
parameter_list|(
name|int
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
DECL|macro|RETURN_CONSTRUCT_COPY_FUNCTION
define|#
directive|define
name|RETURN_CONSTRUCT_COPY_FUNCTION
parameter_list|(
name|TYPE
parameter_list|,
name|ID
parameter_list|)
define|\
value|case QMetaType::ID: \             return testConstructCopyHelper<QMetaType::ID>;
name|FOR_EACH_GUI_METATYPE
argument_list|(
argument|RETURN_CONSTRUCT_COPY_FUNCTION
argument_list|)
DECL|macro|RETURN_CONSTRUCT_COPY_FUNCTION
undef|#
directive|undef
name|RETURN_CONSTRUCT_COPY_FUNCTION
block|}
return|return
literal|0
return|;
block|}
block|}
struct|;
name|QFETCH
argument_list|(
name|QMetaType
operator|::
name|Type
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|TypeTestFunctionGetter
operator|::
name|get
function_decl|(
name|type
function_decl|)
parameter_list|()
function_decl|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGuiMetaType
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qguimetatype.moc"
end_include
end_unit
