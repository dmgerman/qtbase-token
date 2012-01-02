begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QVARIANT_H
end_ifndef
begin_define
DECL|macro|QVARIANT_H
define|#
directive|define
name|QVARIANT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
name|class
name|QBitArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDataStream
name|class
name|QDataStream
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDate
name|class
name|QDate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDateTime
name|class
name|QDateTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEasingCurve
name|class
name|QEasingCurve
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLine
name|class
name|QLine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineF
name|class
name|QLineF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLocale
name|class
name|QLocale
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMatrix
name|class
name|QMatrix
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTransform
name|class
name|QTransform
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTime
name|class
name|QTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPointF
name|class
name|QPointF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSize
name|class
name|QSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSizeF
name|class
name|QSizeF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRectF
name|class
name|QRectF
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_decl_stmt
DECL|variable|QRegExp
name|class
name|QRegExp
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QTextFormat
name|class
name|QTextFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextLength
name|class
name|QTextLength
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariantComparisonHelper
name|class
name|QVariantComparisonHelper
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|QVariant
name|qVariantFromValue
argument_list|(
specifier|const
name|T
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|qvariant_cast
argument_list|(
specifier|const
name|QVariant
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QVariant
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|Invalid
init|=
name|QMetaType
operator|::
name|Void
block|,
name|Bool
init|=
name|QMetaType
operator|::
name|Bool
block|,
name|Int
init|=
name|QMetaType
operator|::
name|Int
block|,
name|UInt
init|=
name|QMetaType
operator|::
name|UInt
block|,
name|LongLong
init|=
name|QMetaType
operator|::
name|LongLong
block|,
name|ULongLong
init|=
name|QMetaType
operator|::
name|ULongLong
block|,
name|Double
init|=
name|QMetaType
operator|::
name|Double
block|,
name|Char
init|=
name|QMetaType
operator|::
name|QChar
block|,
name|Map
init|=
name|QMetaType
operator|::
name|QVariantMap
block|,
name|List
init|=
name|QMetaType
operator|::
name|QVariantList
block|,
name|String
init|=
name|QMetaType
operator|::
name|QString
block|,
name|StringList
init|=
name|QMetaType
operator|::
name|QStringList
block|,
name|ByteArray
init|=
name|QMetaType
operator|::
name|QByteArray
block|,
name|BitArray
init|=
name|QMetaType
operator|::
name|QBitArray
block|,
name|Date
init|=
name|QMetaType
operator|::
name|QDate
block|,
name|Time
init|=
name|QMetaType
operator|::
name|QTime
block|,
name|DateTime
init|=
name|QMetaType
operator|::
name|QDateTime
block|,
name|Url
init|=
name|QMetaType
operator|::
name|QUrl
block|,
name|Locale
init|=
name|QMetaType
operator|::
name|QLocale
block|,
name|Rect
init|=
name|QMetaType
operator|::
name|QRect
block|,
name|RectF
init|=
name|QMetaType
operator|::
name|QRectF
block|,
name|Size
init|=
name|QMetaType
operator|::
name|QSize
block|,
name|SizeF
init|=
name|QMetaType
operator|::
name|QSizeF
block|,
name|Line
init|=
name|QMetaType
operator|::
name|QLine
block|,
name|LineF
init|=
name|QMetaType
operator|::
name|QLineF
block|,
name|Point
init|=
name|QMetaType
operator|::
name|QPoint
block|,
name|PointF
init|=
name|QMetaType
operator|::
name|QPointF
block|,
name|RegExp
init|=
name|QMetaType
operator|::
name|QRegExp
block|,
name|Hash
init|=
name|QMetaType
operator|::
name|QVariantHash
block|,
name|EasingCurve
init|=
name|QMetaType
operator|::
name|QEasingCurve
block|,
name|Uuid
init|=
name|QMetaType
operator|::
name|QUuid
block|,
name|LastCoreType
init|=
name|QMetaType
operator|::
name|LastCoreType
block|,
name|Font
init|=
name|QMetaType
operator|::
name|QFont
block|,
name|Pixmap
init|=
name|QMetaType
operator|::
name|QPixmap
block|,
name|Brush
init|=
name|QMetaType
operator|::
name|QBrush
block|,
name|Color
init|=
name|QMetaType
operator|::
name|QColor
block|,
name|Palette
init|=
name|QMetaType
operator|::
name|QPalette
block|,
name|Image
init|=
name|QMetaType
operator|::
name|QImage
block|,
name|Polygon
init|=
name|QMetaType
operator|::
name|QPolygon
block|,
name|Region
init|=
name|QMetaType
operator|::
name|QRegion
block|,
name|Bitmap
init|=
name|QMetaType
operator|::
name|QBitmap
block|,
name|Cursor
init|=
name|QMetaType
operator|::
name|QCursor
block|,
name|KeySequence
init|=
name|QMetaType
operator|::
name|QKeySequence
block|,
name|Pen
init|=
name|QMetaType
operator|::
name|QPen
block|,
name|TextLength
init|=
name|QMetaType
operator|::
name|QTextLength
block|,
name|TextFormat
init|=
name|QMetaType
operator|::
name|QTextFormat
block|,
name|Matrix
init|=
name|QMetaType
operator|::
name|QMatrix
block|,
name|Transform
init|=
name|QMetaType
operator|::
name|QTransform
block|,
name|Matrix4x4
init|=
name|QMetaType
operator|::
name|QMatrix4x4
block|,
name|Vector2D
init|=
name|QMetaType
operator|::
name|QVector2D
block|,
name|Vector3D
init|=
name|QMetaType
operator|::
name|QVector3D
block|,
name|Vector4D
init|=
name|QMetaType
operator|::
name|QVector4D
block|,
name|Quaternion
init|=
name|QMetaType
operator|::
name|QQuaternion
block|,
name|PolygonF
init|=
name|QMetaType
operator|::
name|QPolygonF
block|,
name|LastGuiType
init|=
name|QMetaType
operator|::
name|LastGuiType
block|,
name|Icon
init|=
name|QMetaType
operator|::
name|QIcon
block|,
name|SizePolicy
init|=
name|QMetaType
operator|::
name|QSizePolicy
block|,
name|UserType
init|=
literal|127
block|,
name|LastType
init|=
literal|0xffffffff
comment|// need this so that gcc>= 3.4 allocates 32 bits for Type
block|}
enum|;
specifier|inline
name|QVariant
argument_list|()
expr_stmt|;
operator|~
name|QVariant
argument_list|()
expr_stmt|;
name|QVariant
argument_list|(
argument|Type type
argument_list|)
empty_stmt|;
name|QVariant
argument_list|(
argument|int typeOrUserType
argument_list|,
argument|const void *copy
argument_list|)
empty_stmt|;
name|QVariant
argument_list|(
argument|int typeOrUserType
argument_list|,
argument|const void *copy
argument_list|,
argument|uint flags
argument_list|)
empty_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QVariant
operator|&
name|other
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|QVariant
argument_list|(
name|QDataStream
operator|&
name|s
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVariant
argument_list|(
argument|int i
argument_list|)
empty_stmt|;
name|QVariant
argument_list|(
argument|uint ui
argument_list|)
empty_stmt|;
name|QVariant
argument_list|(
argument|qlonglong ll
argument_list|)
empty_stmt|;
name|QVariant
argument_list|(
argument|qulonglong ull
argument_list|)
empty_stmt|;
name|QVariant
argument_list|(
argument|bool b
argument_list|)
empty_stmt|;
name|QVariant
argument_list|(
argument|double d
argument_list|)
empty_stmt|;
name|QVariant
argument_list|(
argument|float f
argument_list|)
block|{
name|d
operator|.
name|is_null
operator|=
name|false
expr_stmt|;
name|d
operator|.
name|type
operator|=
name|QMetaType
operator|::
name|Float
expr_stmt|;
name|d
operator|.
name|data
operator|.
name|f
operator|=
name|f
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_CAST_FROM_ASCII
name|QT_ASCII_CAST_WARN_CONSTRUCTOR
name|QVariant
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
endif|#
directive|endif
name|QVariant
argument_list|(
specifier|const
name|QByteArray
operator|&
name|bytearray
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QBitArray
operator|&
name|bitarray
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QLatin1String
operator|&
name|string
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QStringList
operator|&
name|stringlist
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QChar
operator|&
name|qchar
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QDate
operator|&
name|date
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QTime
operator|&
name|time
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QDateTime
operator|&
name|datetime
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QList
operator|<
name|QVariant
operator|>
operator|&
name|list
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QMap
operator|<
name|QString
argument_list|,
name|QVariant
operator|>
operator|&
name|map
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QHash
operator|<
name|QString
argument_list|,
name|QVariant
operator|>
operator|&
name|hash
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_GEOM_VARIANT
name|QVariant
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QSizeF
operator|&
name|size
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QPoint
operator|&
name|pt
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QPointF
operator|&
name|pt
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QLine
operator|&
name|line
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QLineF
operator|&
name|line
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVariant
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
expr_stmt|;
name|QVariant
argument_list|(
specifier|const
name|QLocale
operator|&
name|locale
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
name|QVariant
argument_list|(
specifier|const
name|QRegExp
operator|&
name|regExp
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|QVariant
argument_list|(
specifier|const
name|QEasingCurve
operator|&
name|easing
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVariant
argument_list|(
argument|Qt::GlobalColor color
argument_list|)
empty_stmt|;
name|QVariant
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QVariant
operator|&
name|other
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QVariant
modifier|&
name|operator
init|=
operator|(
name|QVariant
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
specifier|inline
name|void
name|swap
parameter_list|(
name|QVariant
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|Type
name|type
argument_list|()
specifier|const
expr_stmt|;
name|int
name|userType
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|typeName
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|canConvert
argument_list|(
name|Type
name|t
argument_list|)
decl|const
decl_stmt|;
name|bool
name|convert
parameter_list|(
name|Type
name|t
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|void
name|detach
parameter_list|()
function_decl|;
specifier|inline
name|bool
name|isDetached
argument_list|()
specifier|const
expr_stmt|;
name|int
name|toInt
argument_list|(
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|uint
name|toUInt
argument_list|(
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|qlonglong
name|toLongLong
argument_list|(
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|qulonglong
name|toULongLong
argument_list|(
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|bool
name|toBool
argument_list|()
specifier|const
expr_stmt|;
name|double
name|toDouble
argument_list|(
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|float
name|toFloat
argument_list|(
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|qreal
name|toReal
argument_list|(
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|QByteArray
name|toByteArray
argument_list|()
specifier|const
expr_stmt|;
name|QBitArray
name|toBitArray
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|toString
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|toStringList
argument_list|()
specifier|const
expr_stmt|;
name|QChar
name|toChar
argument_list|()
specifier|const
expr_stmt|;
name|QDate
name|toDate
argument_list|()
specifier|const
expr_stmt|;
name|QTime
name|toTime
argument_list|()
specifier|const
expr_stmt|;
name|QDateTime
name|toDateTime
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QVariant
operator|>
name|toList
argument_list|()
specifier|const
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QVariant
operator|>
name|toMap
argument_list|()
specifier|const
expr_stmt|;
name|QHash
operator|<
name|QString
operator|,
name|QVariant
operator|>
name|toHash
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_GEOM_VARIANT
name|QPoint
name|toPoint
argument_list|()
specifier|const
expr_stmt|;
name|QPointF
name|toPointF
argument_list|()
specifier|const
expr_stmt|;
name|QRect
name|toRect
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|toSize
argument_list|()
specifier|const
expr_stmt|;
name|QSizeF
name|toSizeF
argument_list|()
specifier|const
expr_stmt|;
name|QLine
name|toLine
argument_list|()
specifier|const
expr_stmt|;
name|QLineF
name|toLineF
argument_list|()
specifier|const
expr_stmt|;
name|QRectF
name|toRectF
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|QUrl
name|toUrl
argument_list|()
specifier|const
expr_stmt|;
name|QLocale
name|toLocale
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
name|QRegExp
name|toRegExp
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|QEasingCurve
name|toEasingCurve
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|void
name|load
parameter_list|(
name|QDataStream
modifier|&
name|ds
parameter_list|)
function_decl|;
name|void
name|save
argument_list|(
name|QDataStream
operator|&
name|ds
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
specifier|static
specifier|const
name|char
modifier|*
name|typeToName
parameter_list|(
name|Type
name|type
parameter_list|)
function_decl|;
specifier|static
name|Type
name|nameToType
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|void
modifier|*
name|data
parameter_list|()
function_decl|;
specifier|const
name|void
operator|*
name|constData
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
specifier|const
name|void
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|constData
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|setValue
argument_list|(
specifier|const
name|T
operator|&
name|value
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|value
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|T
operator|>
operator|(
operator|*
name|this
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|QVariant
name|fromValue
argument_list|(
argument|const T&value
argument_list|)
block|{
return|return
name|qVariantFromValue
argument_list|(
name|value
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|canConvert
argument_list|()
specifier|const
block|{
return|return
name|canConvert
argument_list|(
name|Type
argument_list|(
name|qMetaTypeId
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
argument_list|)
return|;
block|}
name|public
label|:
ifndef|#
directive|ifndef
name|qdoc
struct|struct
name|PrivateShared
block|{
specifier|inline
name|PrivateShared
argument_list|(
name|void
operator|*
name|v
argument_list|)
operator|:
name|ptr
argument_list|(
name|v
argument_list|)
operator|,
name|ref
argument_list|(
literal|1
argument_list|)
block|{ }
name|void
operator|*
name|ptr
expr_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
block|}
struct|;
struct|struct
name|Private
block|{
specifier|inline
name|Private
argument_list|()
operator|:
name|type
argument_list|(
name|Invalid
argument_list|)
operator|,
name|is_shared
argument_list|(
name|false
argument_list|)
operator|,
name|is_null
argument_list|(
argument|true
argument_list|)
block|{
name|data
operator|.
name|ptr
operator|=
literal|0
block|; }
specifier|inline
name|Private
argument_list|(
specifier|const
name|Private
operator|&
name|other
argument_list|)
operator|:
name|data
argument_list|(
name|other
operator|.
name|data
argument_list|)
operator|,
name|type
argument_list|(
name|other
operator|.
name|type
argument_list|)
operator|,
name|is_shared
argument_list|(
name|other
operator|.
name|is_shared
argument_list|)
operator|,
name|is_null
argument_list|(
argument|other.is_null
argument_list|)
block|{}
expr|union
name|Data
block|{
name|char
name|c
block|;
name|uchar
name|uc
block|;
name|short
name|s
block|;
name|ushort
name|us
block|;
name|int
name|i
block|;
name|uint
name|u
block|;
name|long
name|l
block|;
name|ulong
name|ul
block|;
name|bool
name|b
block|;
name|double
name|d
block|;
name|float
name|f
block|;
name|qreal
name|real
block|;
name|qlonglong
name|ll
block|;
name|qulonglong
name|ull
block|;
name|QObject
operator|*
name|o
block|;
name|void
operator|*
name|ptr
block|;
name|PrivateShared
operator|*
name|shared
block|;         }
name|data
expr_stmt|;
name|uint
name|type
range|:
literal|30
decl_stmt|;
name|uint
name|is_shared
range|:
literal|1
decl_stmt|;
name|uint
name|is_null
range|:
literal|1
decl_stmt|;
block|}
struct|;
name|public
label|:
typedef|typedef
name|void
function_decl|(
modifier|*
name|f_construct
function_decl|)
parameter_list|(
name|Private
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|f_clear
function_decl|)
parameter_list|(
name|Private
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|f_null
function_decl|)
parameter_list|(
specifier|const
name|Private
modifier|*
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
typedef|typedef
name|void
function_decl|(
modifier|*
name|f_load
function_decl|)
parameter_list|(
name|Private
modifier|*
parameter_list|,
name|QDataStream
modifier|&
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|f_save
function_decl|)
parameter_list|(
specifier|const
name|Private
modifier|*
parameter_list|,
name|QDataStream
modifier|&
parameter_list|)
function_decl|;
endif|#
directive|endif
typedef|typedef
name|bool
function_decl|(
modifier|*
name|f_compare
function_decl|)
parameter_list|(
specifier|const
name|Private
modifier|*
parameter_list|,
specifier|const
name|Private
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|bool
argument_list|(
argument|*f_convert
argument_list|)
operator|(
specifier|const
name|QVariant
operator|::
name|Private
operator|*
name|d
operator|,
name|Type
name|t
operator|,
name|void
operator|*
operator|,
name|bool
operator|*
operator|)
expr_stmt|;
typedef|typedef
name|bool
argument_list|(
argument|*f_canConvert
argument_list|)
operator|(
specifier|const
name|QVariant
operator|::
name|Private
operator|*
name|d
operator|,
name|Type
name|t
operator|)
expr_stmt|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|f_debugStream
function_decl|)
parameter_list|(
name|QDebug
parameter_list|,
specifier|const
name|QVariant
modifier|&
parameter_list|)
function_decl|;
struct|struct
name|Handler
block|{
name|f_construct
name|construct
decl_stmt|;
name|f_clear
name|clear
decl_stmt|;
name|f_null
name|isNull
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|f_load
name|load
decl_stmt|;
name|f_save
name|save
decl_stmt|;
endif|#
directive|endif
name|f_compare
name|compare
decl_stmt|;
name|f_convert
name|convert
decl_stmt|;
name|f_canConvert
name|canConvert
decl_stmt|;
name|f_debugStream
name|debugStream
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QVariant
operator|&
name|v
operator|)
specifier|const
block|{
return|return
name|cmp
argument_list|(
name|v
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QVariant
operator|&
name|v
operator|)
specifier|const
block|{
return|return
operator|!
name|cmp
argument_list|(
name|v
argument_list|)
return|;
block|}
name|protected
label|:
name|friend
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QVariant
operator|&
operator|,
specifier|const
name|QVariantComparisonHelper
operator|&
operator|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
name|friend
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QVariant
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
name|Private
name|d
decl_stmt|;
ifndef|#
directive|ifndef
name|Q_NO_TEMPLATE_FRIENDS
name|template
operator|<
name|typename
name|T
operator|>
name|friend
specifier|inline
name|T
name|qvariant_cast
argument_list|(
specifier|const
name|QVariant
operator|&
argument_list|)
expr_stmt|;
name|private
label|:
else|#
directive|else
name|public
label|:
endif|#
directive|endif
name|void
name|create
parameter_list|(
name|int
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|copy
parameter_list|)
function_decl|;
name|bool
name|cmp
argument_list|(
specifier|const
name|QVariant
operator|&
name|other
argument_list|)
decl|const
decl_stmt|;
name|bool
name|convert
argument_list|(
specifier|const
name|int
name|t
argument_list|,
name|void
operator|*
name|ptr
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|// force compile error, prevent QVariant(bool) to be called
specifier|inline
name|QVariant
argument_list|(
argument|void *
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
block|; }
ifdef|#
directive|ifdef
name|QT_NO_CAST_FROM_ASCII
comment|// force compile error when implicit conversion is not wanted
specifier|inline
name|QVariant
argument_list|(
argument|const char *
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
block|; }
endif|#
directive|endif
name|public
operator|:
typedef|typedef
name|Private
name|DataPtr
typedef|;
specifier|inline
name|DataPtr
modifier|&
name|data_ptr
parameter_list|()
block|{
return|return
name|d
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qVariantFromValue
specifier|inline
name|QVariant
name|qVariantFromValue
argument_list|(
argument|const T&t
argument_list|)
block|{
return|return
name|QVariant
argument_list|(
name|qMetaTypeId
operator|<
name|T
operator|>
operator|(
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
literal|0
operator|)
operator|)
argument_list|,
operator|&
name|t
argument_list|,
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isPointer
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
DECL|function|qVariantFromValue
specifier|inline
name|QVariant
name|qVariantFromValue
argument_list|(
argument|const QVariant&t
argument_list|)
block|{
return|return
name|t
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qVariantSetValue
specifier|inline
name|void
name|qVariantSetValue
argument_list|(
argument|QVariant&v
argument_list|,
argument|const T&t
argument_list|)
block|{
comment|//if possible we reuse the current QVariant private
specifier|const
name|uint
name|type
operator|=
name|qMetaTypeId
operator|<
name|T
operator|>
operator|(
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
literal|0
operator|)
operator|)
block|;
name|QVariant
operator|::
name|Private
operator|&
name|d
operator|=
name|v
operator|.
name|data_ptr
argument_list|()
block|;
if|if
condition|(
name|v
operator|.
name|isDetached
argument_list|()
operator|&&
operator|(
name|type
operator|==
name|d
operator|.
name|type
operator|||
operator|(
name|type
operator|<=
name|uint
argument_list|(
name|QVariant
operator|::
name|Char
argument_list|)
operator|&&
name|d
operator|.
name|type
operator|<=
name|uint
argument_list|(
name|QVariant
operator|::
name|Char
argument_list|)
operator|)
operator|)
condition|)
block|{
name|d
operator|.
name|type
operator|=
name|type
expr_stmt|;
name|d
operator|.
name|is_null
operator|=
name|false
expr_stmt|;
name|T
modifier|*
name|old
init|=
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|d
operator|.
name|is_shared
condition|?
name|d
operator|.
name|data
operator|.
name|shared
operator|->
name|ptr
else|:
operator|&
name|d
operator|.
name|data
operator|.
name|ptr
operator|)
decl_stmt|;
if|if
condition|(
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
condition|)
name|old
operator|->
expr|~
name|T
argument_list|()
expr_stmt|;
name|new
argument_list|(
argument|old
argument_list|)
name|T
argument_list|(
name|t
argument_list|)
expr_stmt|;
comment|//call the copy constructor
block|}
end_expr_stmt
begin_else
else|else
block|{
name|v
operator|=
name|QVariant
argument_list|(
name|type
argument_list|,
operator|&
name|t
argument_list|,
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isPointer
argument_list|)
expr_stmt|;
block|}
end_else
begin_expr_stmt
unit|}  template
operator|<
operator|>
DECL|function|QVariant
specifier|inline
name|void
name|qVariantSetValue
operator|<
name|QVariant
operator|>
operator|(
name|QVariant
operator|&
name|v
operator|,
specifier|const
name|QVariant
operator|&
name|t
operator|)
block|{
name|v
operator|=
name|t
block|; }
DECL|function|QVariant
specifier|inline
name|QVariant
operator|::
name|QVariant
argument_list|()
block|{}
DECL|function|isValid
specifier|inline
name|bool
name|QVariant
operator|::
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|type
operator|!=
name|Invalid
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|setValue
specifier|inline
name|void
name|QVariant
operator|::
name|setValue
argument_list|(
argument|const T&avalue
argument_list|)
block|{
name|qVariantSetValue
argument_list|(
operator|*
name|this
argument_list|,
name|avalue
argument_list|)
block|; }
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|s
operator|,
name|QVariant
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|s
operator|,
specifier|const
name|QVariant
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|s
operator|,
name|QVariant
operator|::
name|Type
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|s
operator|,
specifier|const
name|QVariant
operator|::
name|Type
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|function|isDetached
specifier|inline
name|bool
name|QVariant
operator|::
name|isDetached
argument_list|()
specifier|const
block|{
return|return
operator|!
name|d
operator|.
name|is_shared
operator|||
name|d
operator|.
name|data
operator|.
name|shared
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|==
literal|1
return|;
block|}
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|qdoc
end_ifdef
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QVariant
operator|&
name|v1
operator|,
specifier|const
name|QVariant
operator|&
name|v2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QVariant
operator|&
name|v1
operator|,
specifier|const
name|QVariant
operator|&
name|v2
operator|)
expr_stmt|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* Helper class to add one more level of indirection to prevent    implicit casts. */
end_comment
begin_decl_stmt
name|class
name|QVariantComparisonHelper
block|{
name|public
label|:
specifier|inline
name|QVariantComparisonHelper
argument_list|(
specifier|const
name|QVariant
operator|&
name|var
argument_list|)
operator|:
name|v
argument_list|(
argument|&var
argument_list|)
block|{}
name|private
operator|:
name|friend
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QVariant
operator|&
operator|,
specifier|const
name|QVariantComparisonHelper
operator|&
operator|)
expr_stmt|;
specifier|const
name|QVariant
modifier|*
name|v
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QVariant
operator|&
name|v1
operator|,
specifier|const
name|QVariantComparisonHelper
operator|&
name|v2
operator|)
block|{
return|return
name|v1
operator|.
name|cmp
argument_list|(
operator|*
name|v2
operator|.
name|v
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QVariant
operator|&
name|v1
operator|,
specifier|const
name|QVariantComparisonHelper
operator|&
name|v2
operator|)
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|v1
operator|,
name|v2
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_MOC
end_ifndef
begin_expr_stmt
DECL|function|qvariant_cast
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|qvariant_cast
argument_list|(
argument|const QVariant&v
argument_list|)
block|{
specifier|const
name|int
name|vid
operator|=
name|qMetaTypeId
operator|<
name|T
operator|>
operator|(
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
literal|0
operator|)
operator|)
block|;
if|if
condition|(
name|vid
operator|==
name|v
operator|.
name|userType
argument_list|()
condition|)
return|return
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|v
operator|.
name|constData
argument_list|()
operator|)
return|;
end_expr_stmt
begin_if
if|if
condition|(
name|vid
operator|<
name|int
argument_list|(
name|QMetaType
operator|::
name|User
argument_list|)
condition|)
block|{
name|T
name|t
decl_stmt|;
if|if
condition|(
name|v
operator|.
name|convert
argument_list|(
name|vid
argument_list|,
operator|&
name|t
argument_list|)
condition|)
return|return
name|t
return|;
block|}
end_if
begin_return
return|return
name|T
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}  template
DECL|function|QVariant
operator|<
operator|>
specifier|inline
name|QVariant
name|qvariant_cast
operator|<
name|QVariant
operator|>
operator|(
specifier|const
name|QVariant
operator|&
name|v
operator|)
block|{
if|if
condition|(
name|v
operator|.
name|userType
argument_list|()
operator|==
name|QMetaType
operator|::
name|QVariant
condition|)
return|return
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|QVariant
operator|*
operator|>
operator|(
name|v
operator|.
name|constData
argument_list|()
operator|)
return|;
end_expr_stmt
begin_return
return|return
name|v
return|;
end_return
begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|QT_DEPRECATED
end_ifdef
begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
DECL|function|qVariantValue
specifier|inline
name|QT_DEPRECATED
name|T
name|qVariantValue
argument_list|(
argument|const QVariant&variant
argument_list|)
block|{
return|return
name|qvariant_cast
operator|<
name|T
operator|>
operator|(
name|variant
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qVariantCanConvert
specifier|inline
name|QT_DEPRECATED
name|bool
name|qVariantCanConvert
argument_list|(
argument|const QVariant&variant
argument_list|)
block|{
return|return
name|variant
operator|.
name|template
name|canConvert
operator|<
name|T
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QVariant
argument_list|)
end_macro
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QVariant
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
DECL|variable|operator
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QVariant
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QVariant
operator|::
name|Type
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QVARIANT_H
end_comment
end_unit
