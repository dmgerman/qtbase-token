begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMETATYPE_H
end_ifndef
begin_define
DECL|macro|QMETATYPE_H
define|#
directive|define
name|QMETATYPE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<new>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Bool
end_ifdef
begin_error
error|#
directive|error
error|qmetatype.h must be included before any header file that defines Bool
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
comment|// F is a tuple: (QMetaType::TypeName, QMetaType::TypeNameID, RealType)
DECL|macro|QT_FOR_EACH_STATIC_PRIMITIVE_TYPE
define|#
directive|define
name|QT_FOR_EACH_STATIC_PRIMITIVE_TYPE
parameter_list|(
name|F
parameter_list|)
define|\
value|F(Void, 0, void) \     F(Bool, 1, bool) \     F(Int, 2, int) \     F(UInt, 3, uint) \     F(LongLong, 4, qlonglong) \     F(ULongLong, 5, qulonglong) \     F(Double, 6, double) \     F(Long, 129, long) \     F(Short, 130, short) \     F(Char, 131, char) \     F(ULong, 132, ulong) \     F(UShort, 133, ushort) \     F(UChar, 134, uchar) \     F(Float, 135, float) \  #define QT_FOR_EACH_STATIC_PRIMITIVE_POINTER(F)\     F(VoidStar, 128, void*) \  #define QT_FOR_EACH_STATIC_CORE_CLASS(F)\     F(QChar, 7, QChar) \     F(QString, 10, QString) \     F(QStringList, 11, QStringList) \     F(QByteArray, 12, QByteArray) \     F(QBitArray, 13, QBitArray) \     F(QDate, 14, QDate) \     F(QTime, 15, QTime) \     F(QDateTime, 16, QDateTime) \     F(QUrl, 17, QUrl) \     F(QLocale, 18, QLocale) \     F(QRect, 19, QRect) \     F(QRectF, 20, QRectF) \     F(QSize, 21, QSize) \     F(QSizeF, 22, QSizeF) \     F(QLine, 23, QLine) \     F(QLineF, 24, QLineF) \     F(QPoint, 25, QPoint) \     F(QPointF, 26, QPointF) \     F(QRegExp, 27, QRegExp) \     F(QEasingCurve, 29, QEasingCurve) \     F(QUuid, 30, QUuid) \     F(QModelIndex, 31, QModelIndex) \     F(QVariant, 138, QVariant) \  #define QT_FOR_EACH_STATIC_CORE_POINTER(F)\     F(QObjectStar, 136, QObject*) \     F(QWidgetStar, 137, QWidget*) \  #define QT_FOR_EACH_STATIC_CORE_TEMPLATE(F)\     F(QVariantMap, 8, QVariantMap) \     F(QVariantList, 9, QVariantList) \     F(QVariantHash, 28, QVariantHash) \  #define QT_FOR_EACH_STATIC_GUI_CLASS(F)\     F(QFont, 64, QFont) \     F(QPixmap, 65, QPixmap) \     F(QBrush, 66, QBrush) \     F(QColor, 67, QColor) \     F(QPalette, 68, QPalette) \     F(QImage, 69, QImage) \     F(QPolygon, 70, QPolygon) \     F(QRegion, 71, QRegion) \     F(QBitmap, 72, QBitmap) \     F(QCursor, 73, QCursor) \     F(QKeySequence, 74, QKeySequence) \     F(QPen, 75, QPen) \     F(QTextLength, 76, QTextLength) \     F(QTextFormat, 77, QTextFormat) \     F(QMatrix, 78, QMatrix) \     F(QTransform, 79, QTransform) \     F(QMatrix4x4, 80, QMatrix4x4) \     F(QVector2D, 81, QVector2D) \     F(QVector3D, 82, QVector3D) \     F(QVector4D, 83, QVector4D) \     F(QQuaternion, 84, QQuaternion) \     F(QPolygonF, 85, QPolygonF) \  #define QT_FOR_EACH_STATIC_WIDGETS_CLASS(F)\     F(QIcon, 120, QIcon) \     F(QSizePolicy, 121, QSizePolicy)
function|\
comment|// ### FIXME kill that set
DECL|macro|QT_FOR_EACH_STATIC_HACKS_TYPE
define|#
directive|define
name|QT_FOR_EACH_STATIC_HACKS_TYPE
parameter_list|(
name|F
parameter_list|)
define|\
value|F(QMetaTypeId2<qreal>::MetaType, -1, qreal)
comment|// F is a tuple: (QMetaType::TypeName, QMetaType::TypeNameID, AliasingType, "RealType")
DECL|macro|QT_FOR_EACH_STATIC_ALIAS_TYPE
define|#
directive|define
name|QT_FOR_EACH_STATIC_ALIAS_TYPE
parameter_list|(
name|F
parameter_list|)
define|\
value|F(ULong, -1, ulong, "unsigned long") \     F(UInt, -1, uint, "unsigned int") \     F(UShort, -1, ushort, "unsigned short") \     F(UChar, -1, uchar, "unsigned char") \     F(LongLong, -1, qlonglong, "long long") \     F(ULongLong, -1, qulonglong, "unsigned long long") \     F(Char, -1, char, "qint8") \     F(Char, -1, char, "signed char") \     F(UChar, -1, uchar, "quint8") \     F(Short, -1, short, "qint16") \     F(UShort, -1, ushort, "quint16") \     F(Int, -1, int, "qint32") \     F(UInt, -1, uint, "quint32") \     F(LongLong, -1, qlonglong, "qint64") \     F(ULongLong, -1, qulonglong, "quint64") \     F(QVariantList, -1, QVariantList, "QList<QVariant>") \     F(QVariantMap, -1, QVariantMap, "QMap<QString,QVariant>") \     F(QVariantHash, -1, QVariantHash, "QHash<QString,QVariant>") \  #define QT_FOR_EACH_STATIC_TYPE(F)\     QT_FOR_EACH_STATIC_PRIMITIVE_TYPE(F)\     QT_FOR_EACH_STATIC_PRIMITIVE_POINTER(F)\     QT_FOR_EACH_STATIC_CORE_CLASS(F)\     QT_FOR_EACH_STATIC_CORE_POINTER(F)\     QT_FOR_EACH_STATIC_CORE_TEMPLATE(F)\     QT_FOR_EACH_STATIC_GUI_CLASS(F)\     QT_FOR_EACH_STATIC_WIDGETS_CLASS(F)\  #define QT_DEFINE_METATYPE_ID(TypeName, Id, Name) \     TypeName = Id,
name|class
name|QDataStream
decl_stmt|;
name|class
name|Q_CORE_EXPORT
name|QMetaType
decl_stmt|{ public:     enum Type
block|{
comment|// these are merged with QVariant
name|QT_FOR_EACH_STATIC_TYPE
argument_list|(
argument|QT_DEFINE_METATYPE_ID
argument_list|)
name|LastCoreType
operator|=
name|QModelIndex
operator|,
name|FirstGuiType
operator|=
name|QFont
operator|,
name|LastGuiType
operator|=
name|QPolygonF
operator|,
name|FirstWidgetsType
operator|=
name|QIcon
operator|,
name|LastWidgetsType
operator|=
name|QSizePolicy
operator|,
name|FirstCoreExtType
operator|=
name|VoidStar
operator|,
name|LastCoreExtType
operator|=
name|QVariant
operator|,
comment|// This logic must match the one in qglobal.h
if|#
directive|if
name|defined
argument_list|(
name|QT_COORD_TYPE
argument_list|)
name|QReal
operator|=
literal|0
operator|,
elif|#
directive|elif
name|defined
argument_list|(
name|QT_NO_FPU
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_ARCH_ARM
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_ARCH_WINDOWSCE
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_ARCH_SYMBIAN
argument_list|)
name|QReal
operator|=
name|Float
operator|,
else|#
directive|else
name|QReal
operator|=
name|Double
operator|,
endif|#
directive|endif
name|User
operator|=
literal|256
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_enum
enum|enum
name|TypeFlag
block|{
name|NeedsConstruction
init|=
literal|0x1
block|,
name|NeedsDestruction
init|=
literal|0x2
block|,
name|MovableType
init|=
literal|0x4
block|}
enum|;
end_enum
begin_macro
name|Q_DECLARE_FLAGS
argument_list|(
argument|TypeFlags
argument_list|,
argument|TypeFlag
argument_list|)
end_macro
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|Deleter
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|Creator
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|Destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|Constructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|SaveOperator
function_decl|)
parameter_list|(
name|QDataStream
modifier|&
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LoadOperator
function_decl|)
parameter_list|(
name|QDataStream
modifier|&
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_function_decl
specifier|static
name|void
name|registerStreamOperators
parameter_list|(
specifier|const
name|char
modifier|*
name|typeName
parameter_list|,
name|SaveOperator
name|saveOp
parameter_list|,
name|LoadOperator
name|loadOp
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|registerStreamOperators
parameter_list|(
name|int
name|type
parameter_list|,
name|SaveOperator
name|saveOp
parameter_list|,
name|LoadOperator
name|loadOp
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|int
name|registerType
parameter_list|(
specifier|const
name|char
modifier|*
name|typeName
parameter_list|,
name|Deleter
name|deleter
parameter_list|,
name|Creator
name|creator
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
name|int
name|registerType
argument_list|(
specifier|const
name|char
operator|*
name|typeName
argument_list|,
name|Deleter
name|deleter
argument_list|,
name|Creator
name|creator
argument_list|,
name|Destructor
name|destructor
argument_list|,
name|Constructor
name|constructor
argument_list|,
name|int
name|size
argument_list|,
name|QMetaType
operator|::
name|TypeFlags
name|flags
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|int
name|registerTypedef
parameter_list|(
specifier|const
name|char
modifier|*
name|typeName
parameter_list|,
name|int
name|aliasId
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|int
name|type
parameter_list|(
specifier|const
name|char
modifier|*
name|typeName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
specifier|const
name|char
modifier|*
name|typeName
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|int
name|sizeOf
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|TypeFlags
name|typeFlags
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|isRegistered
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
modifier|*
name|create
parameter_list|(
name|int
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|copy
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
end_if
begin_function
name|QT_DEPRECATED
specifier|static
name|void
modifier|*
name|construct
parameter_list|(
name|int
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|copy
init|=
literal|0
parameter_list|)
block|{
return|return
name|create
argument_list|(
name|type
argument_list|,
name|copy
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|void
name|destroy
parameter_list|(
name|int
name|type
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
modifier|*
name|construct
parameter_list|(
name|int
name|type
parameter_list|,
name|void
modifier|*
name|where
parameter_list|,
specifier|const
name|void
modifier|*
name|copy
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|destruct
parameter_list|(
name|int
name|type
parameter_list|,
name|void
modifier|*
name|where
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|unregisterType
parameter_list|(
specifier|const
name|char
modifier|*
name|typeName
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_function_decl
specifier|static
name|bool
name|save
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|load
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_undef
DECL|macro|QT_DEFINE_METATYPE_ID
unit|};
undef|#
directive|undef
name|QT_DEFINE_METATYPE_ID
end_undef
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QMetaType::TypeFlags
argument_list|)
end_macro
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qMetaTypeDeleteHelper
name|void
name|qMetaTypeDeleteHelper
argument_list|(
argument|T *t
argument_list|)
block|{
name|delete
name|t
block|; }
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qMetaTypeCreateHelper
name|void
operator|*
name|qMetaTypeCreateHelper
argument_list|(
argument|const T *t
argument_list|)
block|{
if|if
condition|(
name|t
condition|)
return|return
name|new
name|T
argument_list|(
operator|*
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|t
operator|)
argument_list|)
return|;
end_expr_stmt
begin_return
return|return
name|new
name|T
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|qMetaTypeDestructHelper
name|void
name|qMetaTypeDestructHelper
argument_list|(
argument|T *t
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|t
argument_list|)
comment|// Silence MSVC that warns for POD types.
name|t
operator|->
expr|~
name|T
argument_list|()
block|; }
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qMetaTypeConstructHelper
name|void
operator|*
name|qMetaTypeConstructHelper
argument_list|(
argument|void *where
argument_list|,
argument|const T *t
argument_list|)
block|{
if|if
condition|(
name|t
condition|)
return|return
name|new
argument_list|(
argument|where
argument_list|)
name|T
argument_list|(
operator|*
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|t
operator|)
argument_list|)
return|;
end_expr_stmt
begin_return
return|return
name|new
argument_list|(
argument|where
argument_list|)
name|T
return|;
end_return
begin_ifndef
unit|}
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
DECL|function|qMetaTypeSaveHelper
name|void
name|qMetaTypeSaveHelper
argument_list|(
argument|QDataStream&stream
argument_list|,
argument|const T *t
argument_list|)
block|{
name|stream
operator|<<
operator|*
name|t
block|; }
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qMetaTypeLoadHelper
name|void
name|qMetaTypeLoadHelper
argument_list|(
argument|QDataStream&stream
argument_list|,
argument|T *t
argument_list|)
block|{
name|stream
operator|>>
operator|*
name|t
block|; }
endif|#
directive|endif
comment|// QT_NO_DATASTREAM
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
DECL|struct|QMetaTypeId
name|QMetaTypeId
block|{     enum
DECL|enumerator|Defined
block|{
name|Defined
operator|=
literal|0
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
DECL|struct|QMetaTypeId2
name|QMetaTypeId2
block|{     enum
DECL|enumerator|Defined
block|{
name|Defined
operator|=
name|QMetaTypeId
operator|<
name|T
operator|>
operator|::
name|Defined
block|}
block|;
DECL|function|qt_metatype_id
specifier|static
specifier|inline
name|int
name|qt_metatype_id
argument_list|()
block|{
return|return
name|QMetaTypeId
operator|<
name|T
operator|>
operator|::
name|qt_metatype_id
argument_list|()
return|;
block|}
end_expr_stmt
begin_decl_stmt
DECL|function|qt_metatype_id
unit|};
name|namespace
name|QtPrivate
block|{
name|template
operator|<
name|typename
name|T
operator|,
name|bool
name|Defined
operator|=
name|QMetaTypeId2
operator|<
name|T
operator|>
operator|::
name|Defined
operator|>
expr|struct
name|QMetaTypeIdHelper
block|{
specifier|static
specifier|inline
name|int
name|qt_metatype_id
argument_list|()
block|{
return|return
name|QMetaTypeId2
operator|<
name|T
operator|>
operator|::
name|qt_metatype_id
argument_list|()
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|QMetaTypeIdHelper
operator|<
name|T
block|,
name|false
operator|>
block|{
specifier|static
specifier|inline
name|int
name|qt_metatype_id
argument_list|()
block|{
return|return
operator|-
literal|1
return|;
block|}
expr|}
block|; }
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qRegisterMetaType
name|int
name|qRegisterMetaType
argument_list|(
argument|const char *typeName
ifndef|#
directive|ifndef
name|qdoc
argument_list|,
argument|T * dummy =
literal|0
endif|#
directive|endif
argument_list|)
block|{
specifier|const
name|int
name|typedefOf
operator|=
name|dummy
operator|?
operator|-
literal|1
operator|:
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|T
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|;
if|if
condition|(
name|typedefOf
operator|!=
operator|-
literal|1
condition|)
return|return
name|QMetaType
operator|::
name|registerTypedef
argument_list|(
name|typeName
argument_list|,
name|typedefOf
argument_list|)
return|;
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|CreatePtr
function_decl|)
parameter_list|(
specifier|const
name|T
modifier|*
parameter_list|)
function_decl|;
name|CreatePtr
name|cptr
operator|=
name|qMetaTypeCreateHelper
operator|<
name|T
operator|>
expr_stmt|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|DeletePtr
function_decl|)
parameter_list|(
name|T
modifier|*
parameter_list|)
function_decl|;
name|DeletePtr
name|dptr
init|=
name|qMetaTypeDeleteHelper
operator|<
name|T
operator|>
decl_stmt|;
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|ConstructPtr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|T
modifier|*
parameter_list|)
function_decl|;
name|ConstructPtr
name|ipcptr
init|=
name|qMetaTypeConstructHelper
operator|<
name|T
operator|>
decl_stmt|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|DestructPtr
function_decl|)
parameter_list|(
name|T
modifier|*
parameter_list|)
function_decl|;
name|DestructPtr
name|ipdptr
init|=
name|qMetaTypeDestructHelper
operator|<
name|T
operator|>
decl_stmt|;
name|QMetaType
operator|::
name|TypeFlags
name|flags
expr_stmt|;
if|if
condition|(
operator|!
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isStatic
condition|)
name|flags
operator||=
name|QMetaType
operator|::
name|MovableType
expr_stmt|;
if|if
condition|(
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
condition|)
block|{
name|flags
operator||=
name|QMetaType
operator|::
name|NeedsConstruction
expr_stmt|;
name|flags
operator||=
name|QMetaType
operator|::
name|NeedsDestruction
expr_stmt|;
block|}
return|return
name|QMetaType
operator|::
name|registerType
argument_list|(
name|typeName
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|Deleter
operator|>
operator|(
name|dptr
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|Creator
operator|>
operator|(
name|cptr
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|Destructor
operator|>
operator|(
name|ipdptr
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|Constructor
operator|>
operator|(
name|ipcptr
operator|)
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|flags
argument_list|)
return|;
block|}
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qRegisterMetaTypeStreamOperators
name|void
name|qRegisterMetaTypeStreamOperators
argument_list|(
argument|const char *typeName
ifndef|#
directive|ifndef
name|qdoc
argument_list|,
argument|T *
comment|/* dummy */
argument|=
literal|0
endif|#
directive|endif
argument_list|)
block|{
typedef|typedef
name|void
function_decl|(
modifier|*
name|SavePtr
function_decl|)
parameter_list|(
name|QDataStream
modifier|&
parameter_list|,
specifier|const
name|T
modifier|*
parameter_list|)
function_decl|;
end_expr_stmt
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LoadPtr
function_decl|)
parameter_list|(
name|QDataStream
modifier|&
parameter_list|,
name|T
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
name|SavePtr
name|sptr
init|=
name|qMetaTypeSaveHelper
operator|<
name|T
operator|>
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|LoadPtr
name|lptr
init|=
name|qMetaTypeLoadHelper
operator|<
name|T
operator|>
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qRegisterMetaType
operator|<
name|T
operator|>
operator|(
name|typeName
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMetaType
operator|::
name|registerStreamOperators
argument_list|(
name|typeName
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|SaveOperator
operator|>
operator|(
name|sptr
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|LoadOperator
operator|>
operator|(
name|lptr
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
DECL|function|qMetaTypeId
specifier|inline
name|int
name|qMetaTypeId
argument_list|(
ifndef|#
directive|ifndef
name|qdoc
argument|T *
comment|/* dummy */
argument|=
literal|0
endif|#
directive|endif
argument_list|)
block|{
return|return
name|QMetaTypeId2
operator|<
name|T
operator|>
operator|::
name|qt_metatype_id
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qRegisterMetaType
specifier|inline
name|int
name|qRegisterMetaType
argument_list|(
if|#
directive|if
operator|!
name|defined
argument_list|(
name|qdoc
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_SUN
argument_list|)
argument|T * dummy =
literal|0
endif|#
directive|endif
argument_list|)
block|{
ifdef|#
directive|ifdef
name|Q_CC_SUN
return|return
name|qMetaTypeId
argument_list|(
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
literal|0
operator|)
argument_list|)
return|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_return
return|return
name|qMetaTypeId
argument_list|(
name|dummy
argument_list|)
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
unit|}
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
DECL|function|qRegisterMetaTypeStreamOperators
specifier|inline
name|int
name|qRegisterMetaTypeStreamOperators
argument_list|()
block|{
typedef|typedef
name|void
function_decl|(
modifier|*
name|SavePtr
function_decl|)
parameter_list|(
name|QDataStream
modifier|&
parameter_list|,
specifier|const
name|T
modifier|*
parameter_list|)
function_decl|;
end_expr_stmt
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LoadPtr
function_decl|)
parameter_list|(
name|QDataStream
modifier|&
parameter_list|,
name|T
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
name|SavePtr
name|sptr
init|=
name|qMetaTypeSaveHelper
operator|<
name|T
operator|>
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|LoadPtr
name|lptr
init|=
name|qMetaTypeLoadHelper
operator|<
name|T
operator|>
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|register
name|int
name|id
init|=
name|qMetaTypeId
operator|<
name|T
operator|>
operator|(
operator|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QMetaType
operator|::
name|registerStreamOperators
argument_list|(
name|id
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|SaveOperator
operator|>
operator|(
name|sptr
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|LoadOperator
operator|>
operator|(
name|lptr
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|id
return|;
end_return
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_DECLARE_METATYPE
define|#
directive|define
name|Q_DECLARE_METATYPE
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|QT_BEGIN_NAMESPACE                                                  \     template<>                                                         \     struct QMetaTypeId< TYPE>                                          \     {                                                                   \         enum { Defined = 1 };                                           \         static int qt_metatype_id()                                     \             {                                                           \                 static QBasicAtomicInt metatype_id = Q_BASIC_ATOMIC_INITIALIZER(0); \                 if (!metatype_id.load())                                \                     metatype_id.storeRelease(qRegisterMetaType< TYPE>(#TYPE, \                                reinterpret_cast< TYPE *>(quintptr(-1)))); \                 return metatype_id.loadAcquire();                       \             }                                                           \     };                                                                  \     QT_END_NAMESPACE
end_define
begin_define
DECL|macro|Q_DECLARE_BUILTIN_METATYPE
define|#
directive|define
name|Q_DECLARE_BUILTIN_METATYPE
parameter_list|(
name|TYPE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|QT_BEGIN_NAMESPACE \     template<> struct QMetaTypeId2<TYPE> \     { \         enum { Defined = 1, MetaType = QMetaType::NAME }; \         static inline int qt_metatype_id() { return QMetaType::NAME; } \     }; \     QT_END_NAMESPACE
end_define
begin_define
DECL|macro|QT_FORWARD_DECLARE_STATIC_TYPES_ITER
define|#
directive|define
name|QT_FORWARD_DECLARE_STATIC_TYPES_ITER
parameter_list|(
name|TypeName
parameter_list|,
name|TypeId
parameter_list|,
name|Name
parameter_list|)
define|\
value|class Name;
end_define
begin_expr_stmt
unit|QT_FOR_EACH_STATIC_CORE_CLASS
operator|(
name|QT_FORWARD_DECLARE_STATIC_TYPES_ITER
operator|)
name|QT_FOR_EACH_STATIC_GUI_CLASS
argument_list|(
argument|QT_FORWARD_DECLARE_STATIC_TYPES_ITER
argument_list|)
name|QT_FOR_EACH_STATIC_WIDGETS_CLASS
argument_list|(
argument|QT_FORWARD_DECLARE_STATIC_TYPES_ITER
argument_list|)
DECL|macro|QT_FORWARD_DECLARE_STATIC_TYPES_ITER
undef|#
directive|undef
name|QT_FORWARD_DECLARE_STATIC_TYPES_ITER
name|class
name|QWidget
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QList
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
DECL|variable|QMap
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
name|class
name|QMap
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
DECL|variable|QHash
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
name|class
name|QHash
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|QVariantList
typedef|typedef
name|QList
operator|<
name|QVariant
operator|>
name|QVariantList
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QString
DECL|typedef|QVariantMap
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QVariant
operator|>
name|QVariantMap
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QString
DECL|typedef|QVariantHash
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|QVariant
operator|>
name|QVariantHash
expr_stmt|;
end_typedef
begin_decl_stmt
name|QT_END_NAMESPACE
DECL|macro|QT_DECLARE_BUILTIN_METATYPE_ITER
define|#
directive|define
name|QT_DECLARE_BUILTIN_METATYPE_ITER
parameter_list|(
name|MetaTypeName
parameter_list|,
name|MetaTypeId
parameter_list|,
name|Name
parameter_list|)
define|\
value|Q_DECLARE_BUILTIN_METATYPE(Name, MetaTypeName)
name|QT_FOR_EACH_STATIC_TYPE
argument_list|(
name|QT_DECLARE_BUILTIN_METATYPE_ITER
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|signed
name|char
argument_list|,
name|Char
argument_list|)
DECL|macro|QT_DECLARE_BUILTIN_METATYPE_ITER
undef|#
directive|undef
name|QT_DECLARE_BUILTIN_METATYPE_ITER
name|QT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMETATYPE_H
end_comment
end_unit
