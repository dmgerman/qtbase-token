begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusxmlparser_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusutil_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qxmlstream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_comment
comment|//#define QDBUS_PARSER_DEBUG
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QDBUS_PARSER_DEBUG
end_ifdef
begin_define
DECL|macro|qDBusParserError
define|#
directive|define
name|qDBusParserError
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qDBusParserError
define|#
directive|define
name|qDBusParserError
value|if (true) {} else qDebug
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|parseArg
specifier|static
name|bool
name|parseArg
parameter_list|(
specifier|const
name|QXmlStreamAttributes
modifier|&
name|attributes
parameter_list|,
name|QDBusIntrospection
operator|::
name|Argument
modifier|&
name|argData
parameter_list|)
block|{
specifier|const
name|QString
name|argType
init|=
name|attributes
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"type"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|bool
name|ok
init|=
name|QDBusUtil
operator|::
name|isValidSingleSignature
argument_list|(
name|argType
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|qDBusParserError
argument_list|(
literal|"Invalid D-BUS type signature '%s' found while parsing introspection"
argument_list|,
name|qPrintable
argument_list|(
name|argType
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|argData
operator|.
name|name
operator|=
name|attributes
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"name"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|argData
operator|.
name|type
operator|=
name|argType
expr_stmt|;
return|return
name|ok
return|;
block|}
end_function
begin_function
DECL|function|parseAnnotation
specifier|static
name|bool
name|parseAnnotation
parameter_list|(
specifier|const
name|QXmlStreamReader
modifier|&
name|xml
parameter_list|,
name|QDBusIntrospection
operator|::
name|Annotations
modifier|&
name|annotations
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|xml
operator|.
name|isStartElement
argument_list|()
operator|&&
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"annotation"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QXmlStreamAttributes
name|attributes
init|=
name|xml
operator|.
name|attributes
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|name
init|=
name|attributes
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"name"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|QDBusUtil
operator|::
name|isValidInterfaceName
argument_list|(
name|name
argument_list|)
condition|)
block|{
name|qDBusParserError
argument_list|(
literal|"Invalid D-BUS annotation '%s' found while parsing introspection"
argument_list|,
name|qPrintable
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|annotations
operator|.
name|insert
argument_list|(
name|name
argument_list|,
name|attributes
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"value"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|parseProperty
specifier|static
name|bool
name|parseProperty
parameter_list|(
name|QXmlStreamReader
modifier|&
name|xml
parameter_list|,
name|QDBusIntrospection
operator|::
name|Property
modifier|&
name|propertyData
parameter_list|,
specifier|const
name|QString
modifier|&
name|ifaceName
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|xml
operator|.
name|isStartElement
argument_list|()
operator|&&
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"property"
argument_list|)
argument_list|)
expr_stmt|;
name|QXmlStreamAttributes
name|attributes
init|=
name|xml
operator|.
name|attributes
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|propertyName
init|=
name|attributes
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"name"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|QDBusUtil
operator|::
name|isValidMemberName
argument_list|(
name|propertyName
argument_list|)
condition|)
block|{
name|qDBusParserError
argument_list|(
literal|"Invalid D-BUS member name '%s' found in interface '%s' while parsing introspection"
argument_list|,
name|qPrintable
argument_list|(
name|propertyName
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|ifaceName
argument_list|)
argument_list|)
expr_stmt|;
name|xml
operator|.
name|skipCurrentElement
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// parse data
name|propertyData
operator|.
name|name
operator|=
name|propertyName
expr_stmt|;
name|propertyData
operator|.
name|type
operator|=
name|attributes
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"type"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|QDBusUtil
operator|::
name|isValidSingleSignature
argument_list|(
name|propertyData
operator|.
name|type
argument_list|)
condition|)
block|{
comment|// cannot be!
name|qDBusParserError
argument_list|(
literal|"Invalid D-BUS type signature '%s' found in property '%s.%s' while parsing introspection"
argument_list|,
name|qPrintable
argument_list|(
name|propertyData
operator|.
name|type
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|ifaceName
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|propertyName
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QString
name|access
init|=
name|attributes
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"access"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
name|access
operator|==
name|QLatin1String
argument_list|(
literal|"read"
argument_list|)
condition|)
name|propertyData
operator|.
name|access
operator|=
name|QDBusIntrospection
operator|::
name|Property
operator|::
name|Read
expr_stmt|;
elseif|else
if|if
condition|(
name|access
operator|==
name|QLatin1String
argument_list|(
literal|"write"
argument_list|)
condition|)
name|propertyData
operator|.
name|access
operator|=
name|QDBusIntrospection
operator|::
name|Property
operator|::
name|Write
expr_stmt|;
elseif|else
if|if
condition|(
name|access
operator|==
name|QLatin1String
argument_list|(
literal|"readwrite"
argument_list|)
condition|)
name|propertyData
operator|.
name|access
operator|=
name|QDBusIntrospection
operator|::
name|Property
operator|::
name|ReadWrite
expr_stmt|;
else|else
block|{
name|qDBusParserError
argument_list|(
literal|"Invalid D-BUS property access '%s' found in property '%s.%s' while parsing introspection"
argument_list|,
name|qPrintable
argument_list|(
name|access
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|ifaceName
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|propertyName
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
comment|// invalid one!
block|}
while|while
condition|(
name|xml
operator|.
name|readNextStartElement
argument_list|()
condition|)
block|{
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"annotation"
argument_list|)
condition|)
block|{
name|parseAnnotation
argument_list|(
name|xml
argument_list|,
name|propertyData
operator|.
name|annotations
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|prefix
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qDBusParserError
argument_list|()
operator|<<
literal|"Unknown element"
operator|<<
name|xml
operator|.
name|name
argument_list|()
operator|<<
literal|"while checking for annotations"
expr_stmt|;
block|}
name|xml
operator|.
name|skipCurrentElement
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|xml
operator|.
name|isEndElement
argument_list|()
operator|||
name|xml
operator|.
name|name
argument_list|()
operator|!=
name|QLatin1String
argument_list|(
literal|"property"
argument_list|)
condition|)
block|{
name|qDBusParserError
argument_list|()
operator|<<
literal|"Invalid property specification"
operator|<<
name|xml
operator|.
name|tokenString
argument_list|()
operator|<<
name|xml
operator|.
name|name
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|parseMethod
specifier|static
name|bool
name|parseMethod
parameter_list|(
name|QXmlStreamReader
modifier|&
name|xml
parameter_list|,
name|QDBusIntrospection
operator|::
name|Method
modifier|&
name|methodData
parameter_list|,
specifier|const
name|QString
modifier|&
name|ifaceName
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|xml
operator|.
name|isStartElement
argument_list|()
operator|&&
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"method"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QXmlStreamAttributes
name|attributes
init|=
name|xml
operator|.
name|attributes
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|methodName
init|=
name|attributes
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"name"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|QDBusUtil
operator|::
name|isValidMemberName
argument_list|(
name|methodName
argument_list|)
condition|)
block|{
name|qDBusParserError
argument_list|(
literal|"Invalid D-BUS member name '%s' found in interface '%s' while parsing introspection"
argument_list|,
name|qPrintable
argument_list|(
name|methodName
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|ifaceName
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|methodData
operator|.
name|name
operator|=
name|methodName
expr_stmt|;
name|QDBusIntrospection
operator|::
name|Arguments
name|outArguments
decl_stmt|;
name|QDBusIntrospection
operator|::
name|Arguments
name|inArguments
decl_stmt|;
name|QDBusIntrospection
operator|::
name|Annotations
name|annotations
decl_stmt|;
while|while
condition|(
name|xml
operator|.
name|readNextStartElement
argument_list|()
condition|)
block|{
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"annotation"
argument_list|)
condition|)
block|{
name|parseAnnotation
argument_list|(
name|xml
argument_list|,
name|annotations
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"arg"
argument_list|)
condition|)
block|{
specifier|const
name|QXmlStreamAttributes
name|attributes
init|=
name|xml
operator|.
name|attributes
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|direction
init|=
name|attributes
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"direction"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QDBusIntrospection
operator|::
name|Argument
name|argument
decl_stmt|;
if|if
condition|(
operator|!
name|attributes
operator|.
name|hasAttribute
argument_list|(
name|QLatin1String
argument_list|(
literal|"direction"
argument_list|)
argument_list|)
operator|||
name|direction
operator|==
name|QLatin1String
argument_list|(
literal|"in"
argument_list|)
condition|)
block|{
name|parseArg
argument_list|(
name|attributes
argument_list|,
name|argument
argument_list|)
expr_stmt|;
name|inArguments
operator|<<
name|argument
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|direction
operator|==
name|QLatin1String
argument_list|(
literal|"out"
argument_list|)
condition|)
block|{
name|parseArg
argument_list|(
name|attributes
argument_list|,
name|argument
argument_list|)
expr_stmt|;
name|outArguments
operator|<<
name|argument
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|prefix
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qDBusParserError
argument_list|()
operator|<<
literal|"Unknown element"
operator|<<
name|xml
operator|.
name|name
argument_list|()
operator|<<
literal|"while checking for method arguments"
expr_stmt|;
block|}
name|xml
operator|.
name|skipCurrentElement
argument_list|()
expr_stmt|;
block|}
name|methodData
operator|.
name|inputArgs
operator|=
name|inArguments
expr_stmt|;
name|methodData
operator|.
name|outputArgs
operator|=
name|outArguments
expr_stmt|;
name|methodData
operator|.
name|annotations
operator|=
name|annotations
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|parseSignal
specifier|static
name|bool
name|parseSignal
parameter_list|(
name|QXmlStreamReader
modifier|&
name|xml
parameter_list|,
name|QDBusIntrospection
operator|::
name|Signal
modifier|&
name|signalData
parameter_list|,
specifier|const
name|QString
modifier|&
name|ifaceName
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|xml
operator|.
name|isStartElement
argument_list|()
operator|&&
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"signal"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QXmlStreamAttributes
name|attributes
init|=
name|xml
operator|.
name|attributes
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|signalName
init|=
name|attributes
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"name"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|QDBusUtil
operator|::
name|isValidMemberName
argument_list|(
name|signalName
argument_list|)
condition|)
block|{
name|qDBusParserError
argument_list|(
literal|"Invalid D-BUS member name '%s' found in interface '%s' while parsing introspection"
argument_list|,
name|qPrintable
argument_list|(
name|signalName
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|ifaceName
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|signalData
operator|.
name|name
operator|=
name|signalName
expr_stmt|;
name|QDBusIntrospection
operator|::
name|Arguments
name|arguments
decl_stmt|;
name|QDBusIntrospection
operator|::
name|Annotations
name|annotations
decl_stmt|;
while|while
condition|(
name|xml
operator|.
name|readNextStartElement
argument_list|()
condition|)
block|{
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"annotation"
argument_list|)
condition|)
block|{
name|parseAnnotation
argument_list|(
name|xml
argument_list|,
name|annotations
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"arg"
argument_list|)
condition|)
block|{
specifier|const
name|QXmlStreamAttributes
name|attributes
init|=
name|xml
operator|.
name|attributes
argument_list|()
decl_stmt|;
name|QDBusIntrospection
operator|::
name|Argument
name|argument
decl_stmt|;
if|if
condition|(
operator|!
name|attributes
operator|.
name|hasAttribute
argument_list|(
name|QLatin1String
argument_list|(
literal|"direction"
argument_list|)
argument_list|)
operator|||
name|attributes
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"direction"
argument_list|)
argument_list|)
operator|==
name|QLatin1String
argument_list|(
literal|"out"
argument_list|)
condition|)
block|{
name|parseArg
argument_list|(
name|attributes
argument_list|,
name|argument
argument_list|)
expr_stmt|;
name|arguments
operator|<<
name|argument
expr_stmt|;
block|}
block|}
else|else
block|{
name|qDBusParserError
argument_list|()
operator|<<
literal|"Unknown element"
operator|<<
name|xml
operator|.
name|name
argument_list|()
operator|<<
literal|"while checking for signal arguments"
expr_stmt|;
block|}
name|xml
operator|.
name|skipCurrentElement
argument_list|()
expr_stmt|;
block|}
name|signalData
operator|.
name|outputArgs
operator|=
name|arguments
expr_stmt|;
name|signalData
operator|.
name|annotations
operator|=
name|annotations
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|readInterface
specifier|static
name|void
name|readInterface
parameter_list|(
name|QXmlStreamReader
modifier|&
name|xml
parameter_list|,
name|QDBusIntrospection
operator|::
name|Object
modifier|*
name|objData
parameter_list|,
name|QDBusIntrospection
operator|::
name|Interfaces
modifier|*
name|interfaces
parameter_list|)
block|{
specifier|const
name|QString
name|ifaceName
init|=
name|xml
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"name"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|QDBusUtil
operator|::
name|isValidInterfaceName
argument_list|(
name|ifaceName
argument_list|)
condition|)
block|{
name|qDBusParserError
argument_list|(
literal|"Invalid D-BUS interface name '%s' found while parsing introspection"
argument_list|,
name|qPrintable
argument_list|(
name|ifaceName
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|objData
operator|->
name|interfaces
operator|.
name|append
argument_list|(
name|ifaceName
argument_list|)
expr_stmt|;
name|QDBusIntrospection
operator|::
name|Interface
modifier|*
name|ifaceData
init|=
operator|new
name|QDBusIntrospection
operator|::
name|Interface
decl_stmt|;
name|ifaceData
operator|->
name|name
operator|=
name|ifaceName
expr_stmt|;
while|while
condition|(
name|xml
operator|.
name|readNextStartElement
argument_list|()
condition|)
block|{
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"method"
argument_list|)
condition|)
block|{
name|QDBusIntrospection
operator|::
name|Method
name|methodData
decl_stmt|;
if|if
condition|(
name|parseMethod
argument_list|(
name|xml
argument_list|,
name|methodData
argument_list|,
name|ifaceName
argument_list|)
condition|)
name|ifaceData
operator|->
name|methods
operator|.
name|insert
argument_list|(
name|methodData
operator|.
name|name
argument_list|,
name|methodData
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"signal"
argument_list|)
condition|)
block|{
name|QDBusIntrospection
operator|::
name|Signal
name|signalData
decl_stmt|;
if|if
condition|(
name|parseSignal
argument_list|(
name|xml
argument_list|,
name|signalData
argument_list|,
name|ifaceName
argument_list|)
condition|)
name|ifaceData
operator|->
name|signals_
operator|.
name|insert
argument_list|(
name|signalData
operator|.
name|name
argument_list|,
name|signalData
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"property"
argument_list|)
condition|)
block|{
name|QDBusIntrospection
operator|::
name|Property
name|propertyData
decl_stmt|;
if|if
condition|(
name|parseProperty
argument_list|(
name|xml
argument_list|,
name|propertyData
argument_list|,
name|ifaceName
argument_list|)
condition|)
name|ifaceData
operator|->
name|properties
operator|.
name|insert
argument_list|(
name|propertyData
operator|.
name|name
argument_list|,
name|propertyData
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"annotation"
argument_list|)
condition|)
block|{
name|parseAnnotation
argument_list|(
name|xml
argument_list|,
name|ifaceData
operator|->
name|annotations
argument_list|)
expr_stmt|;
name|xml
operator|.
name|skipCurrentElement
argument_list|()
expr_stmt|;
comment|// skip over annotation object
block|}
else|else
block|{
if|if
condition|(
name|xml
operator|.
name|prefix
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qDBusParserError
argument_list|()
operator|<<
literal|"Unknown element while parsing interface"
operator|<<
name|xml
operator|.
name|name
argument_list|()
expr_stmt|;
block|}
name|xml
operator|.
name|skipCurrentElement
argument_list|()
expr_stmt|;
block|}
block|}
name|interfaces
operator|->
name|insert
argument_list|(
name|ifaceName
argument_list|,
name|QSharedDataPointer
argument_list|<
name|QDBusIntrospection
operator|::
name|Interface
argument_list|>
argument_list|(
name|ifaceData
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|xml
operator|.
name|isEndElement
argument_list|()
operator|||
name|xml
operator|.
name|name
argument_list|()
operator|!=
name|QLatin1String
argument_list|(
literal|"interface"
argument_list|)
condition|)
block|{
name|qDBusParserError
argument_list|()
operator|<<
literal|"Invalid Interface specification"
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|readNode
specifier|static
name|void
name|readNode
parameter_list|(
specifier|const
name|QXmlStreamReader
modifier|&
name|xml
parameter_list|,
name|QDBusIntrospection
operator|::
name|Object
modifier|*
name|objData
parameter_list|,
name|int
name|nodeLevel
parameter_list|)
block|{
specifier|const
name|QString
name|objName
init|=
name|xml
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"name"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|fullName
init|=
name|objData
operator|->
name|path
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|?
operator|(
name|objData
operator|->
name|path
operator|+
name|objName
operator|)
else|:
name|QString
argument_list|(
name|objData
operator|->
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|objName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|QDBusUtil
operator|::
name|isValidObjectPath
argument_list|(
name|fullName
argument_list|)
condition|)
block|{
name|qDBusParserError
argument_list|(
literal|"Invalid D-BUS object path '%s' found while parsing introspection"
argument_list|,
name|qPrintable
argument_list|(
name|fullName
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|nodeLevel
operator|>
literal|0
condition|)
name|objData
operator|->
name|childObjects
operator|.
name|append
argument_list|(
name|objName
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QDBusXmlParser
name|QDBusXmlParser
operator|::
name|QDBusXmlParser
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|xmlData
parameter_list|)
member_init_list|:
name|m_service
argument_list|(
name|service
argument_list|)
member_init_list|,
name|m_path
argument_list|(
name|path
argument_list|)
member_init_list|,
name|m_object
argument_list|(
operator|new
name|QDBusIntrospection
operator|::
name|Object
argument_list|)
block|{
comment|//    qDBusParserError()<< "parsing"<< xmlData;
name|m_object
operator|->
name|service
operator|=
name|m_service
expr_stmt|;
name|m_object
operator|->
name|path
operator|=
name|m_path
expr_stmt|;
name|QXmlStreamReader
name|xml
argument_list|(
name|xmlData
argument_list|)
decl_stmt|;
name|int
name|nodeLevel
init|=
operator|-
literal|1
decl_stmt|;
while|while
condition|(
operator|!
name|xml
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|xml
operator|.
name|readNext
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|xml
operator|.
name|tokenType
argument_list|()
condition|)
block|{
case|case
name|QXmlStreamReader
operator|::
name|StartElement
case|:
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"node"
argument_list|)
condition|)
block|{
name|readNode
argument_list|(
name|xml
argument_list|,
name|m_object
argument_list|,
operator|++
name|nodeLevel
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"interface"
argument_list|)
condition|)
block|{
name|readInterface
argument_list|(
name|xml
argument_list|,
name|m_object
argument_list|,
operator|&
name|m_interfaces
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|xml
operator|.
name|prefix
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qDBusParserError
argument_list|()
operator|<<
literal|"skipping unknown element"
operator|<<
name|xml
operator|.
name|name
argument_list|()
expr_stmt|;
block|}
name|xml
operator|.
name|skipCurrentElement
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|QXmlStreamReader
operator|::
name|EndElement
case|:
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"node"
argument_list|)
condition|)
block|{
operator|--
name|nodeLevel
expr_stmt|;
block|}
else|else
block|{
name|qDBusParserError
argument_list|()
operator|<<
literal|"Invalid Node declaration"
operator|<<
name|xml
operator|.
name|name
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|QXmlStreamReader
operator|::
name|StartDocument
case|:
case|case
name|QXmlStreamReader
operator|::
name|EndDocument
case|:
case|case
name|QXmlStreamReader
operator|::
name|DTD
case|:
comment|// not interested
break|break;
case|case
name|QXmlStreamReader
operator|::
name|Comment
case|:
comment|// ignore comments and processing instructions
break|break;
default|default:
name|qDBusParserError
argument_list|()
operator|<<
literal|"unknown token"
operator|<<
name|xml
operator|.
name|name
argument_list|()
operator|<<
name|xml
operator|.
name|tokenString
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|xml
operator|.
name|hasError
argument_list|()
condition|)
block|{
name|qDBusParserError
argument_list|()
operator|<<
literal|"xml error"
operator|<<
name|xml
operator|.
name|errorString
argument_list|()
operator|<<
literal|"doc"
operator|<<
name|xmlData
expr_stmt|;
block|}
block|}
end_constructor
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DBUS
end_comment
end_unit
