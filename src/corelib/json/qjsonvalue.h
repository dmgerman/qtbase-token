begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QJSONVALUE_H
end_ifndef
begin_define
DECL|macro|QJSONVALUE_H
define|#
directive|define
name|QJSONVALUE_H
end_define
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QJsonArray
name|class
name|QJsonArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QJsonObject
name|class
name|QJsonObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QJsonPrivate
block|{
name|class
name|Data
decl_stmt|;
name|class
name|Base
decl_stmt|;
name|class
name|Object
decl_stmt|;
name|class
name|Header
decl_stmt|;
name|class
name|Array
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|Entry
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QJsonValue
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|Null
init|=
literal|0x0
block|,
name|Bool
init|=
literal|0x1
block|,
name|Double
init|=
literal|0x2
block|,
name|String
init|=
literal|0x3
block|,
name|Array
init|=
literal|0x4
block|,
name|Object
init|=
literal|0x5
block|,
name|Undefined
init|=
literal|0x80
block|}
enum|;
name|QJsonValue
argument_list|(
name|Type
operator|=
name|Null
argument_list|)
expr_stmt|;
name|QJsonValue
argument_list|(
argument|bool b
argument_list|)
empty_stmt|;
name|QJsonValue
argument_list|(
argument|double n
argument_list|)
empty_stmt|;
name|QJsonValue
argument_list|(
argument|int n
argument_list|)
empty_stmt|;
name|QJsonValue
argument_list|(
specifier|const
name|QString
operator|&
name|s
argument_list|)
expr_stmt|;
name|QJsonValue
argument_list|(
specifier|const
name|QLatin1String
operator|&
name|s
argument_list|)
expr_stmt|;
name|QJsonValue
argument_list|(
specifier|const
name|QJsonArray
operator|&
name|a
argument_list|)
expr_stmt|;
name|QJsonValue
argument_list|(
specifier|const
name|QJsonObject
operator|&
name|o
argument_list|)
expr_stmt|;
operator|~
name|QJsonValue
argument_list|()
expr_stmt|;
name|QJsonValue
argument_list|(
specifier|const
name|QJsonValue
operator|&
name|other
argument_list|)
expr_stmt|;
name|QJsonValue
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QJsonValue
operator|&
name|other
operator|)
decl_stmt|;
specifier|static
name|QJsonValue
name|fromVariant
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|variant
parameter_list|)
function_decl|;
name|QVariant
name|toVariant
argument_list|()
specifier|const
expr_stmt|;
name|Type
name|type
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|Null
return|;
block|}
specifier|inline
name|bool
name|isBool
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|Bool
return|;
block|}
specifier|inline
name|bool
name|isDouble
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|Double
return|;
block|}
specifier|inline
name|bool
name|isString
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|String
return|;
block|}
specifier|inline
name|bool
name|isArray
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|Array
return|;
block|}
specifier|inline
name|bool
name|isObject
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|Object
return|;
block|}
specifier|inline
name|bool
name|isUndefined
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|Undefined
return|;
block|}
name|bool
name|toBool
argument_list|()
specifier|const
expr_stmt|;
name|double
name|toDouble
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|toString
argument_list|()
specifier|const
expr_stmt|;
name|QJsonArray
name|toArray
argument_list|()
specifier|const
expr_stmt|;
name|QJsonObject
name|toObject
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QJsonValue
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QJsonValue
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|private
label|:
comment|// avoid implicit conversions from char * to bool
specifier|inline
name|QJsonValue
argument_list|(
argument|const void *
argument_list|)
block|{}
name|friend
name|class
name|QJsonPrivate
operator|::
name|Value
expr_stmt|;
name|friend
name|class
name|QJsonArray
decl_stmt|;
name|friend
name|class
name|QJsonObject
decl_stmt|;
name|friend
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QJsonValue
operator|&
operator|)
expr_stmt|;
name|QJsonValue
argument_list|(
name|QJsonPrivate
operator|::
name|Data
operator|*
name|d
argument_list|,
name|QJsonPrivate
operator|::
name|Base
operator|*
name|b
argument_list|,
specifier|const
name|QJsonPrivate
operator|::
name|Value
operator|&
name|v
argument_list|)
expr_stmt|;
name|void
name|detach
parameter_list|()
function_decl|;
union|union
block|{
name|quint64
name|ui
decl_stmt|;
name|bool
name|b
decl_stmt|;
name|double
name|dbl
decl_stmt|;
name|QStringData
modifier|*
name|stringData
decl_stmt|;
name|QJsonPrivate
operator|::
name|Base
operator|*
name|base
expr_stmt|;
block|}
union|;
name|QJsonPrivate
operator|::
name|Data
operator|*
name|d
expr_stmt|;
comment|// needed for Objects and Arrays
name|Type
name|t
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QJsonValueRef
block|{
name|public
label|:
name|QJsonValueRef
argument_list|(
argument|QJsonArray *array
argument_list|,
argument|int idx
argument_list|)
block|:
name|a
argument_list|(
name|array
argument_list|)
operator|,
name|is_object
argument_list|(
name|false
argument_list|)
operator|,
name|index
argument_list|(
argument|idx
argument_list|)
block|{}
name|QJsonValueRef
argument_list|(
argument|QJsonObject *object
argument_list|,
argument|int idx
argument_list|)
operator|:
name|o
argument_list|(
name|object
argument_list|)
operator|,
name|is_object
argument_list|(
name|true
argument_list|)
operator|,
name|index
argument_list|(
argument|idx
argument_list|)
block|{}
specifier|inline
name|operator
name|QJsonValue
argument_list|()
specifier|const
block|{
return|return
name|toValue
argument_list|()
return|;
block|}
name|QJsonValueRef
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QJsonValue
operator|&
name|val
operator|)
decl_stmt|;
specifier|inline
name|QJsonValue
operator|::
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|toValue
argument_list|()
operator|.
name|type
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|QJsonValue
operator|::
name|Null
return|;
block|}
specifier|inline
name|bool
name|isBool
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|QJsonValue
operator|::
name|Bool
return|;
block|}
specifier|inline
name|bool
name|isDouble
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|QJsonValue
operator|::
name|Double
return|;
block|}
specifier|inline
name|bool
name|isString
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|QJsonValue
operator|::
name|String
return|;
block|}
specifier|inline
name|bool
name|isArray
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|QJsonValue
operator|::
name|Array
return|;
block|}
specifier|inline
name|bool
name|isObject
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|QJsonValue
operator|::
name|Object
return|;
block|}
specifier|inline
name|bool
name|isUndefined
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|QJsonValue
operator|::
name|Undefined
return|;
block|}
specifier|inline
name|bool
name|toBool
argument_list|()
specifier|const
block|{
return|return
name|toValue
argument_list|()
operator|.
name|toBool
argument_list|()
return|;
block|}
specifier|inline
name|double
name|toDouble
argument_list|()
specifier|const
block|{
return|return
name|toValue
argument_list|()
operator|.
name|toDouble
argument_list|()
return|;
block|}
specifier|inline
name|QString
name|toString
argument_list|()
specifier|const
block|{
return|return
name|toValue
argument_list|()
operator|.
name|toString
argument_list|()
return|;
block|}
name|QJsonArray
name|toArray
argument_list|()
specifier|const
expr_stmt|;
name|QJsonObject
name|toObject
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QJsonValue
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|toValue
argument_list|()
operator|==
name|other
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QJsonValue
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|toValue
argument_list|()
operator|!=
name|other
return|;
block|}
name|private
label|:
name|QJsonValue
name|toValue
argument_list|()
specifier|const
decl_stmt|;
union|union
block|{
name|QJsonArray
modifier|*
name|a
decl_stmt|;
name|QJsonObject
modifier|*
name|o
decl_stmt|;
block|}
union|;
name|uint
name|is_object
range|:
literal|1
decl_stmt|;
name|uint
name|index
range|:
literal|31
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QJsonValue
operator|&
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
comment|// QJSONVALUE_H
end_comment
end_unit
