begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qjsonobject.h>
end_include
begin_include
include|#
directive|include
file|<qjsonvalue.h>
end_include
begin_include
include|#
directive|include
file|<qjsonarray.h>
end_include
begin_include
include|#
directive|include
file|<qvariant.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qjson_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QJsonValue     \inmodule QtCore     \ingroup json     \reentrant     \since 5.0      \brief The QJsonValue class encapsulates a value in JSON.      A value in JSON can be one of 6 basic types:      JSON is a format to store structured data. It has 6 basic data types:      \list     \li bool QJsonValue::Bool     \li double QJsonValue::Double     \li string QJsonValue::String     \li array QJsonValue::Array     \li object QJsonValue::Object     \li null QJsonValue::Null     \endlist      A value can represent any of the above data types. In addition, QJsonValue has one special     flag to represent undefined values. This can be queried with isUndefined().      The type of the value can be queried with type() or accessors like isBool(), isString(), and so on.     Likewise, the value can be converted to the type stored in it using the toBool(), toString() and so on.      Values are strictly typed internally and contrary to QVariant will not attempt to do any implicit type     conversions. This implies that converting to a type that is not stored in the value will return a default     constructed return value. */
end_comment
begin_comment
comment|/*!     Creates a QJsonValue of type \a type.      The default is to create a Null value.  */
end_comment
begin_constructor
DECL|function|QJsonValue
name|QJsonValue
operator|::
name|QJsonValue
parameter_list|(
name|Type
name|type
parameter_list|)
member_init_list|:
name|ui
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|t
argument_list|(
name|type
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal  */
end_comment
begin_constructor
DECL|function|QJsonValue
name|QJsonValue
operator|::
name|QJsonValue
parameter_list|(
name|QJsonPrivate
operator|::
name|Data
modifier|*
name|data
parameter_list|,
name|QJsonPrivate
operator|::
name|Base
modifier|*
name|base
parameter_list|,
specifier|const
name|QJsonPrivate
operator|::
name|Value
modifier|&
name|v
parameter_list|)
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
block|{
name|t
operator|=
operator|(
name|Type
operator|)
operator|(
name|uint
operator|)
name|v
operator|.
name|type
expr_stmt|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|Undefined
case|:
case|case
name|Null
case|:
name|dbl
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|Bool
case|:
name|b
operator|=
name|v
operator|.
name|toBoolean
argument_list|()
expr_stmt|;
break|break;
case|case
name|Double
case|:
name|dbl
operator|=
name|v
operator|.
name|toDouble
argument_list|(
name|base
argument_list|)
expr_stmt|;
break|break;
case|case
name|String
case|:
block|{
name|QString
name|s
init|=
name|v
operator|.
name|toString
argument_list|(
name|base
argument_list|)
decl_stmt|;
name|stringData
operator|=
name|s
operator|.
name|data_ptr
argument_list|()
expr_stmt|;
name|stringData
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
break|break;
block|}
case|case
name|Array
case|:
case|case
name|Object
case|:
name|d
operator|=
name|data
expr_stmt|;
name|this
operator|->
name|base
operator|=
name|v
operator|.
name|base
argument_list|(
name|base
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_comment
comment|/*!     Creates a value of type Bool, with value \a b.  */
end_comment
begin_constructor
DECL|function|QJsonValue
name|QJsonValue
operator|::
name|QJsonValue
parameter_list|(
name|bool
name|b
parameter_list|)
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|t
argument_list|(
name|Bool
argument_list|)
block|{
name|this
operator|->
name|b
operator|=
name|b
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Creates a value of type Double, with value \a n.  */
end_comment
begin_constructor
DECL|function|QJsonValue
name|QJsonValue
operator|::
name|QJsonValue
parameter_list|(
name|double
name|n
parameter_list|)
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|t
argument_list|(
name|Double
argument_list|)
block|{
name|this
operator|->
name|dbl
operator|=
name|n
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \overload     Creates a value of type Double, with value \a n.  */
end_comment
begin_constructor
DECL|function|QJsonValue
name|QJsonValue
operator|::
name|QJsonValue
parameter_list|(
name|int
name|n
parameter_list|)
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|t
argument_list|(
name|Double
argument_list|)
block|{
name|this
operator|->
name|dbl
operator|=
name|n
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Creates a value of type String, with value \a s.  */
end_comment
begin_constructor
DECL|function|QJsonValue
name|QJsonValue
operator|::
name|QJsonValue
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|)
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|t
argument_list|(
name|String
argument_list|)
block|{
name|stringData
operator|=
operator|*
operator|(
name|QStringData
operator|*
operator|*
operator|)
operator|(
operator|&
name|s
operator|)
expr_stmt|;
name|stringData
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_comment
comment|/*!     Creates a value of type String, with value \a s.  */
end_comment
begin_constructor
DECL|function|QJsonValue
name|QJsonValue
operator|::
name|QJsonValue
parameter_list|(
name|QLatin1String
name|s
parameter_list|)
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|t
argument_list|(
name|String
argument_list|)
block|{
comment|// ### FIXME: Avoid creating the temp QString below
name|QString
name|str
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|stringData
operator|=
operator|*
operator|(
name|QStringData
operator|*
operator|*
operator|)
operator|(
operator|&
name|str
operator|)
expr_stmt|;
name|stringData
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_comment
comment|/*!     Creates a value of type Array, with value \a a.  */
end_comment
begin_constructor
DECL|function|QJsonValue
name|QJsonValue
operator|::
name|QJsonValue
parameter_list|(
specifier|const
name|QJsonArray
modifier|&
name|a
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|a
operator|.
name|d
argument_list|)
member_init_list|,
name|t
argument_list|(
name|Array
argument_list|)
block|{
name|base
operator|=
name|a
operator|.
name|a
expr_stmt|;
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_comment
comment|/*!     Creates a value of type Object, with value \a o.  */
end_comment
begin_constructor
DECL|function|QJsonValue
name|QJsonValue
operator|::
name|QJsonValue
parameter_list|(
specifier|const
name|QJsonObject
modifier|&
name|o
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|o
operator|.
name|d
argument_list|)
member_init_list|,
name|t
argument_list|(
name|Object
argument_list|)
block|{
name|base
operator|=
name|o
operator|.
name|o
expr_stmt|;
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the value.  */
end_comment
begin_destructor
DECL|function|~QJsonValue
name|QJsonValue
operator|::
name|~
name|QJsonValue
parameter_list|()
block|{
if|if
condition|(
name|t
operator|==
name|String
operator|&&
name|stringData
operator|&&
operator|!
name|stringData
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|free
argument_list|(
name|stringData
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|&&
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Creates a copy of \a other.  */
end_comment
begin_constructor
DECL|function|QJsonValue
name|QJsonValue
operator|::
name|QJsonValue
parameter_list|(
specifier|const
name|QJsonValue
modifier|&
name|other
parameter_list|)
block|{
name|t
operator|=
name|other
operator|.
name|t
expr_stmt|;
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
name|ui
operator|=
name|other
operator|.
name|ui
expr_stmt|;
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
if|if
condition|(
name|t
operator|==
name|String
operator|&&
name|stringData
condition|)
name|stringData
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_comment
comment|/*!     Assigns the value stored in \a other to this object.  */
end_comment
begin_function
DECL|function|operator =
name|QJsonValue
modifier|&
name|QJsonValue
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QJsonValue
modifier|&
name|other
parameter_list|)
block|{
if|if
condition|(
name|t
operator|==
name|String
operator|&&
name|stringData
operator|&&
operator|!
name|stringData
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|free
argument_list|(
name|stringData
argument_list|)
expr_stmt|;
name|t
operator|=
name|other
operator|.
name|t
expr_stmt|;
name|dbl
operator|=
name|other
operator|.
name|dbl
expr_stmt|;
if|if
condition|(
name|d
operator|!=
name|other
operator|.
name|d
condition|)
block|{
if|if
condition|(
name|d
operator|&&
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
if|if
condition|(
name|t
operator|==
name|String
operator|&&
name|stringData
condition|)
name|stringData
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QJsonValue::isNull() const      Returns true if the value is null. */
end_comment
begin_comment
comment|/*!     \fn bool QJsonValue::isBool() const      Returns true if the value contains a boolean.      \sa toBool()  */
end_comment
begin_comment
comment|/*!     \fn bool QJsonValue::isDouble() const      Returns true if the value contains a double.      \sa toDouble()  */
end_comment
begin_comment
comment|/*!     \fn bool QJsonValue::isString() const      Returns true if the value contains a string.      \sa toString()  */
end_comment
begin_comment
comment|/*!     \fn bool QJsonValue::isArray() const      Returns true if the value contains an array.      \sa toArray()  */
end_comment
begin_comment
comment|/*!     \fn bool QJsonValue::isObject() const      Returns true if the value contains an object.      \sa toObject()  */
end_comment
begin_comment
comment|/*!     \fn bool QJsonValue::isUndefined() const      Returns true if the value is undefined. This can happen in certain     error cases as e.g. accessing a non existing key in a QJsonObject.  */
end_comment
begin_comment
comment|/*!     Converts \a variant to a QJsonValue and returns it.      The conversion will convert QVariant types as follows:      \list     \li QVariant::Bool to Bool     \li QVariant::Int     \li QVariant::Double     \li QVariant::LongLong     \li QVariant::ULongLong     \li QVariant::UInt to Double     \li QVariant::String to String     \li QVariant::StringList     \li QVariant::VariantList to Array     \li QVariant::VariantMap to Object     \endlist      For all other QVariant types a conversion to a QString will be attempted. If the returned string     is empty, a Null QJsonValue will be stored, otherwise a String value using the returned QString.      \sa toVariant()  */
end_comment
begin_function
DECL|function|fromVariant
name|QJsonValue
name|QJsonValue
operator|::
name|fromVariant
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|variant
parameter_list|)
block|{
switch|switch
condition|(
name|variant
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QVariant
operator|::
name|Bool
case|:
return|return
name|QJsonValue
argument_list|(
name|variant
operator|.
name|toBool
argument_list|()
argument_list|)
return|;
case|case
name|QVariant
operator|::
name|Int
case|:
case|case
name|QVariant
operator|::
name|Double
case|:
case|case
name|QVariant
operator|::
name|LongLong
case|:
case|case
name|QVariant
operator|::
name|ULongLong
case|:
case|case
name|QVariant
operator|::
name|UInt
case|:
return|return
name|QJsonValue
argument_list|(
name|variant
operator|.
name|toDouble
argument_list|()
argument_list|)
return|;
case|case
name|QVariant
operator|::
name|String
case|:
return|return
name|QJsonValue
argument_list|(
name|variant
operator|.
name|toString
argument_list|()
argument_list|)
return|;
case|case
name|QVariant
operator|::
name|StringList
case|:
return|return
name|QJsonValue
argument_list|(
name|QJsonArray
operator|::
name|fromStringList
argument_list|(
name|variant
operator|.
name|toStringList
argument_list|()
argument_list|)
argument_list|)
return|;
case|case
name|QVariant
operator|::
name|List
case|:
return|return
name|QJsonValue
argument_list|(
name|QJsonArray
operator|::
name|fromVariantList
argument_list|(
name|variant
operator|.
name|toList
argument_list|()
argument_list|)
argument_list|)
return|;
case|case
name|QVariant
operator|::
name|Map
case|:
return|return
name|QJsonValue
argument_list|(
name|QJsonObject
operator|::
name|fromVariantMap
argument_list|(
name|variant
operator|.
name|toMap
argument_list|()
argument_list|)
argument_list|)
return|;
default|default:
break|break;
block|}
name|QString
name|string
init|=
name|variant
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
name|string
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QJsonValue
argument_list|()
return|;
return|return
name|QJsonValue
argument_list|(
name|string
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Converts the value to a QVariant.      The QJsonValue types will be converted as follows:      \value Null     QVariant()     \value Bool     QVariant::Bool     \value Double   QVariant::Double     \value String   QVariant::String     \value Array    QVariantList     \value Object   QVariantMap     \value Undefined QVariant()      \sa fromVariant()  */
end_comment
begin_function
DECL|function|toVariant
name|QVariant
name|QJsonValue
operator|::
name|toVariant
parameter_list|()
specifier|const
block|{
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|Bool
case|:
return|return
name|b
return|;
case|case
name|Double
case|:
return|return
name|dbl
return|;
case|case
name|String
case|:
return|return
name|toString
argument_list|()
return|;
case|case
name|Array
case|:
return|return
name|QJsonArray
argument_list|(
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Array
operator|*
argument_list|>
argument_list|(
name|base
argument_list|)
argument_list|)
operator|.
name|toVariantList
argument_list|()
return|;
case|case
name|Object
case|:
return|return
name|QJsonObject
argument_list|(
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Object
operator|*
argument_list|>
argument_list|(
name|base
argument_list|)
argument_list|)
operator|.
name|toVariantMap
argument_list|()
return|;
case|case
name|Null
case|:
case|case
name|Undefined
case|:
break|break;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \enum QJsonValue::Type      This enum describes the type of the JSON value.      \value Null     A Null value     \value Bool     A boolean value. Use toBool() to convert to a bool.     \value Double   A double. Use toDouble() to convert to a double.     \value String   A string. Use toString() to convert to a QString.     \value Array    An array. Use toArray() to convert to a QJsonArray.     \value Object   An object. Use toObject() to convert to a QJsonObject.     \value Undefined The value is undefined. This is usually returned as an                     error condition, when trying to read an out of bounds value                     in an array or a non existent key in an object. */
end_comment
begin_comment
comment|/*!     Returns the type of the value.      \sa QJsonValue::Type  */
end_comment
begin_function
DECL|function|type
name|QJsonValue
operator|::
name|Type
name|QJsonValue
operator|::
name|type
parameter_list|()
specifier|const
block|{
return|return
name|t
return|;
block|}
end_function
begin_comment
comment|/*!     Converts the value to a bool and returns it.      If type() is not bool, the \a defaultValue will be returned.  */
end_comment
begin_function
DECL|function|toBool
name|bool
name|QJsonValue
operator|::
name|toBool
parameter_list|(
name|bool
name|defaultValue
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|t
operator|!=
name|Bool
condition|)
return|return
name|defaultValue
return|;
return|return
name|b
return|;
block|}
end_function
begin_comment
comment|/*!     Converts the value to a double and returns it.      If type() is not Double, the \a defaultValue will be returned.  */
end_comment
begin_function
DECL|function|toDouble
name|double
name|QJsonValue
operator|::
name|toDouble
parameter_list|(
name|double
name|defaultValue
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|t
operator|!=
name|Double
condition|)
return|return
name|defaultValue
return|;
return|return
name|dbl
return|;
block|}
end_function
begin_comment
comment|/*!     Converts the value to a QString and returns it.      If type() is not String, the \a defaultValue will be returned.  */
end_comment
begin_function
DECL|function|toString
name|QString
name|QJsonValue
operator|::
name|toString
parameter_list|(
specifier|const
name|QString
modifier|&
name|defaultValue
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|t
operator|!=
name|String
condition|)
return|return
name|defaultValue
return|;
name|stringData
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
comment|// the constructor below doesn't add a ref.
name|QStringDataPtr
name|holder
init|=
block|{
name|stringData
block|}
decl_stmt|;
return|return
name|QString
argument_list|(
name|holder
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Converts the value to an array and returns it.      If type() is not Array, the \a defaultValue will be returned.  */
end_comment
begin_function
DECL|function|toArray
name|QJsonArray
name|QJsonValue
operator|::
name|toArray
parameter_list|(
specifier|const
name|QJsonArray
modifier|&
name|defaultValue
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|d
operator|||
name|t
operator|!=
name|Array
condition|)
return|return
name|defaultValue
return|;
return|return
name|QJsonArray
argument_list|(
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Array
operator|*
argument_list|>
argument_list|(
name|base
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \overload      Converts the value to an array and returns it.      If type() is not Array, a QJsonArray() will be returned.  */
end_comment
begin_function
DECL|function|toArray
name|QJsonArray
name|QJsonValue
operator|::
name|toArray
parameter_list|()
specifier|const
block|{
return|return
name|toArray
argument_list|(
name|QJsonArray
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Converts the value to an object and returns it.      If type() is not Object, the \a defaultValue will be returned.  */
end_comment
begin_function
DECL|function|toObject
name|QJsonObject
name|QJsonValue
operator|::
name|toObject
parameter_list|(
specifier|const
name|QJsonObject
modifier|&
name|defaultValue
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|d
operator|||
name|t
operator|!=
name|Object
condition|)
return|return
name|defaultValue
return|;
return|return
name|QJsonObject
argument_list|(
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Object
operator|*
argument_list|>
argument_list|(
name|base
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \overload      Converts the value to an object and returns it.      If type() is not Object, the QJsonObject() will be returned.  */
end_comment
begin_function
DECL|function|toObject
name|QJsonObject
name|QJsonValue
operator|::
name|toObject
parameter_list|()
specifier|const
block|{
return|return
name|toObject
argument_list|(
name|QJsonObject
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the value is equal to \a other.  */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QJsonValue
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QJsonValue
modifier|&
name|other
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|t
operator|!=
name|other
operator|.
name|t
condition|)
return|return
literal|false
return|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|Undefined
case|:
case|case
name|Null
case|:
break|break;
case|case
name|Bool
case|:
return|return
name|b
operator|==
name|other
operator|.
name|b
return|;
case|case
name|Double
case|:
return|return
name|dbl
operator|==
name|other
operator|.
name|dbl
return|;
case|case
name|String
case|:
return|return
name|toString
argument_list|()
operator|==
name|other
operator|.
name|toString
argument_list|()
return|;
case|case
name|Array
case|:
if|if
condition|(
name|base
operator|==
name|other
operator|.
name|base
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|!
name|base
operator|||
operator|!
name|other
operator|.
name|base
condition|)
return|return
literal|false
return|;
return|return
name|QJsonArray
argument_list|(
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Array
operator|*
argument_list|>
argument_list|(
name|base
argument_list|)
argument_list|)
operator|==
name|QJsonArray
argument_list|(
name|other
operator|.
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Array
operator|*
argument_list|>
argument_list|(
name|other
operator|.
name|base
argument_list|)
argument_list|)
return|;
case|case
name|Object
case|:
if|if
condition|(
name|base
operator|==
name|other
operator|.
name|base
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|!
name|base
operator|||
operator|!
name|other
operator|.
name|base
condition|)
return|return
literal|false
return|;
return|return
name|QJsonObject
argument_list|(
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Object
operator|*
argument_list|>
argument_list|(
name|base
argument_list|)
argument_list|)
operator|==
name|QJsonObject
argument_list|(
name|other
operator|.
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Object
operator|*
argument_list|>
argument_list|(
name|other
operator|.
name|base
argument_list|)
argument_list|)
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the value is not equal to \a other.  */
end_comment
begin_function
DECL|function|operator !=
name|bool
name|QJsonValue
operator|::
name|operator
name|!=
parameter_list|(
specifier|const
name|QJsonValue
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     \internal  */
end_comment
begin_function
DECL|function|detach
name|void
name|QJsonValue
operator|::
name|detach
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return;
name|QJsonPrivate
operator|::
name|Data
modifier|*
name|x
init|=
name|d
operator|->
name|clone
argument_list|(
name|base
argument_list|)
decl_stmt|;
name|x
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
name|d
operator|=
name|x
expr_stmt|;
name|base
operator|=
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Object
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QJsonValueRef     \inmodule QtCore     \reentrant     \brief The QJsonValueRef class is a helper class for QJsonValue.      \internal      \ingroup json      When you get an object of type QJsonValueRef, if you can assign to it,     the assignment will apply to the character in the string from     which you got the reference. That is its whole purpose in life.      You can use it exactly in the same way as a reference to a QJsonValue.      The QJsonValueRef becomes invalid once modifications are made to the     string: if you want to keep the character, copy it into a QJsonValue.      Most of the QJsonValue member functions also exist in QJsonValueRef.     However, they are not explicitly documented here. */
end_comment
begin_function
DECL|function|operator =
name|QJsonValueRef
modifier|&
name|QJsonValueRef
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QJsonValue
modifier|&
name|val
parameter_list|)
block|{
if|if
condition|(
name|is_object
condition|)
name|o
operator|->
name|setValueAt
argument_list|(
name|index
argument_list|,
name|val
argument_list|)
expr_stmt|;
else|else
name|a
operator|->
name|replace
argument_list|(
name|index
argument_list|,
name|val
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_function
DECL|function|operator =
name|QJsonValueRef
modifier|&
name|QJsonValueRef
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QJsonValueRef
modifier|&
name|ref
parameter_list|)
block|{
if|if
condition|(
name|is_object
condition|)
name|o
operator|->
name|setValueAt
argument_list|(
name|index
argument_list|,
name|ref
argument_list|)
expr_stmt|;
else|else
name|a
operator|->
name|replace
argument_list|(
name|index
argument_list|,
name|ref
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_function
DECL|function|toArray
name|QJsonArray
name|QJsonValueRef
operator|::
name|toArray
parameter_list|()
specifier|const
block|{
return|return
name|toValue
argument_list|()
operator|.
name|toArray
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toObject
name|QJsonObject
name|QJsonValueRef
operator|::
name|toObject
parameter_list|()
specifier|const
block|{
return|return
name|toValue
argument_list|()
operator|.
name|toObject
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toValue
name|QJsonValue
name|QJsonValueRef
operator|::
name|toValue
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|is_object
condition|)
return|return
name|a
operator|->
name|at
argument_list|(
name|index
argument_list|)
return|;
return|return
name|o
operator|->
name|valueAt
argument_list|(
name|index
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QJsonValue
modifier|&
name|o
parameter_list|)
block|{
switch|switch
condition|(
name|o
operator|.
name|t
condition|)
block|{
case|case
name|QJsonValue
operator|::
name|Undefined
case|:
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QJsonValue(undefined)"
expr_stmt|;
break|break;
case|case
name|QJsonValue
operator|::
name|Null
case|:
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QJsonValue(null)"
expr_stmt|;
break|break;
case|case
name|QJsonValue
operator|::
name|Bool
case|:
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QJsonValue(bool, "
operator|<<
name|o
operator|.
name|toBool
argument_list|()
operator|<<
literal|")"
expr_stmt|;
break|break;
case|case
name|QJsonValue
operator|::
name|Double
case|:
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QJsonValue(double, "
operator|<<
name|o
operator|.
name|toDouble
argument_list|()
operator|<<
literal|")"
expr_stmt|;
break|break;
case|case
name|QJsonValue
operator|::
name|String
case|:
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QJsonValue(string, "
operator|<<
name|o
operator|.
name|toString
argument_list|()
operator|<<
literal|")"
expr_stmt|;
break|break;
case|case
name|QJsonValue
operator|::
name|Array
case|:
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QJsonValue(array, "
expr_stmt|;
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
name|o
operator|.
name|toArray
argument_list|()
expr_stmt|;
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|")"
expr_stmt|;
break|break;
case|case
name|QJsonValue
operator|::
name|Object
case|:
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QJsonValue(object, "
expr_stmt|;
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
name|o
operator|.
name|toObject
argument_list|()
expr_stmt|;
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|")"
expr_stmt|;
break|break;
block|}
return|return
name|dbg
operator|.
name|space
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
