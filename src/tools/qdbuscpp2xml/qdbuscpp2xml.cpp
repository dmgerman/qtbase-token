begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qbuffer.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qvector.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<qdbusconnection.h>
end_include
begin_comment
comment|// for the Export* flags
end_comment
begin_include
include|#
directive|include
file|<private/qdbusconnection_p.h>
end_include
begin_comment
comment|// for the qDBusCheckAsyncTag
end_comment
begin_comment
comment|// copied from dbus-protocol.h:
end_comment
begin_decl_stmt
DECL|variable|docTypeHeader
specifier|static
specifier|const
name|char
name|docTypeHeader
index|[]
init|=
literal|"<!DOCTYPE node PUBLIC \"-//freedesktop//DTD D-BUS Object Introspection 1.0//EN\" "
literal|"\"http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd\">\n"
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|ANNOTATION_NO_WAIT
define|#
directive|define
name|ANNOTATION_NO_WAIT
value|"org.freedesktop.DBus.Method.NoReply"
end_define
begin_define
DECL|macro|QCLASSINFO_DBUS_INTERFACE
define|#
directive|define
name|QCLASSINFO_DBUS_INTERFACE
value|"D-Bus Interface"
end_define
begin_define
DECL|macro|QCLASSINFO_DBUS_INTROSPECTION
define|#
directive|define
name|QCLASSINFO_DBUS_INTROSPECTION
value|"D-Bus Introspection"
end_define
begin_include
include|#
directive|include
file|<qdbusmetatype.h>
end_include
begin_include
include|#
directive|include
file|<private/qdbusmetatype_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qdbusutil_p.h>
end_include
begin_include
include|#
directive|include
file|"moc.h"
end_include
begin_include
include|#
directive|include
file|"generator.h"
end_include
begin_include
include|#
directive|include
file|"preprocessor.h"
end_include
begin_define
DECL|macro|PROGRAMNAME
define|#
directive|define
name|PROGRAMNAME
value|"qdbuscpp2xml"
end_define
begin_define
DECL|macro|PROGRAMVERSION
define|#
directive|define
name|PROGRAMVERSION
value|"0.2"
end_define
begin_define
DECL|macro|PROGRAMCOPYRIGHT
define|#
directive|define
name|PROGRAMCOPYRIGHT
value|"Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies)."
end_define
begin_decl_stmt
DECL|variable|outputFile
specifier|static
name|QString
name|outputFile
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|flags
specifier|static
name|int
name|flags
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|help
specifier|static
specifier|const
name|char
name|help
index|[]
init|=
literal|"Usage: "
name|PROGRAMNAME
literal|" [options...] [files...]\n"
literal|"Parses the C++ source or header file containing a QObject-derived class and\n"
literal|"produces the D-Bus Introspection XML."
literal|"\n"
literal|"Options:\n"
literal|"  -p|-s|-m       Only parse scriptable Properties, Signals and Methods (slots)\n"
literal|"  -P|-S|-M       Parse all Properties, Signals and Methods (slots)\n"
literal|"  -a             Output all scriptable contents (equivalent to -psm)\n"
literal|"  -A             Output all contents (equivalent to -PSM)\n"
literal|"  -o<filename>  Write the output to file<filename>\n"
literal|"  -h             Show this information\n"
literal|"  -V             Show the program version and quit.\n"
literal|"\n"
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qDBusParametersForMethod
name|int
name|qDBusParametersForMethod
parameter_list|(
specifier|const
name|FunctionDef
modifier|&
name|mm
parameter_list|,
name|QVector
argument_list|<
name|int
argument_list|>
modifier|&
name|metaTypes
parameter_list|,
name|QString
modifier|&
name|errorMsg
parameter_list|)
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|parameterTypes
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|ArgumentDef
modifier|&
name|arg
decl|,
name|mm
operator|.
name|arguments
control|)
name|parameterTypes
operator|.
name|append
argument_list|(
name|arg
operator|.
name|normalizedType
argument_list|)
expr_stmt|;
return|return
name|qDBusParametersForMethod
argument_list|(
name|parameterTypes
argument_list|,
name|metaTypes
argument_list|,
name|errorMsg
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|typeNameToXml
specifier|static
specifier|inline
name|QString
name|typeNameToXml
parameter_list|(
specifier|const
name|char
modifier|*
name|typeName
parameter_list|)
block|{
name|QString
name|plain
init|=
name|QLatin1String
argument_list|(
name|typeName
argument_list|)
decl_stmt|;
return|return
name|plain
operator|.
name|toHtmlEscaped
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|addFunction
specifier|static
name|QString
name|addFunction
parameter_list|(
specifier|const
name|FunctionDef
modifier|&
name|mm
parameter_list|,
name|bool
name|isSignal
init|=
literal|false
parameter_list|)
block|{
name|QString
name|xml
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<%1 name=\"%2\">\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|isSignal
condition|?
name|QLatin1String
argument_list|(
literal|"signal"
argument_list|)
else|:
name|QLatin1String
argument_list|(
literal|"method"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|mm
operator|.
name|name
argument_list|)
argument_list|)
decl_stmt|;
comment|// check the return type first
name|int
name|typeId
init|=
name|QMetaType
operator|::
name|type
argument_list|(
name|mm
operator|.
name|normalizedType
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|typeId
operator|!=
name|QMetaType
operator|::
name|Void
condition|)
block|{
if|if
condition|(
name|typeId
condition|)
block|{
specifier|const
name|char
modifier|*
name|typeName
init|=
name|QDBusMetaType
operator|::
name|typeToSignature
argument_list|(
name|typeId
argument_list|)
decl_stmt|;
if|if
condition|(
name|typeName
condition|)
block|{
name|xml
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<arg type=\"%1\" direction=\"out\"/>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|typeNameToXml
argument_list|(
name|typeName
argument_list|)
argument_list|)
expr_stmt|;
comment|// do we need to describe this argument?
if|if
condition|(
name|QDBusMetaType
operator|::
name|signatureToType
argument_list|(
name|typeName
argument_list|)
operator|==
name|QVariant
operator|::
name|Invalid
condition|)
name|xml
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<annotation name=\"org.qtproject.QtDBus.QtTypeName.Out0\" value=\"%1\"/>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|typeNameToXml
argument_list|(
name|mm
operator|.
name|normalizedType
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
return|return
name|QString
argument_list|()
return|;
block|}
block|}
elseif|else
if|if
condition|(
operator|!
name|mm
operator|.
name|normalizedType
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
return|return
name|QString
argument_list|()
return|;
comment|// wasn't a valid type
block|}
block|}
name|QList
argument_list|<
name|ArgumentDef
argument_list|>
name|names
init|=
name|mm
operator|.
name|arguments
decl_stmt|;
name|QVector
argument_list|<
name|int
argument_list|>
name|types
decl_stmt|;
name|QString
name|errorMsg
decl_stmt|;
name|int
name|inputCount
init|=
name|qDBusParametersForMethod
argument_list|(
name|mm
argument_list|,
name|types
argument_list|,
name|errorMsg
argument_list|)
decl_stmt|;
if|if
condition|(
name|inputCount
operator|==
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
name|qPrintable
argument_list|(
name|errorMsg
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
comment|// invalid form
block|}
if|if
condition|(
name|isSignal
operator|&&
name|inputCount
operator|+
literal|1
operator|!=
name|types
operator|.
name|count
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
comment|// signal with output arguments?
if|if
condition|(
name|isSignal
operator|&&
name|types
operator|.
name|at
argument_list|(
name|inputCount
argument_list|)
operator|==
name|QDBusMetaTypeId
operator|::
name|message
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
comment|// signal with QDBusMessage argument?
name|bool
name|isScriptable
init|=
name|mm
operator|.
name|isScriptable
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|1
init|;
name|j
operator|<
name|types
operator|.
name|count
argument_list|()
condition|;
operator|++
name|j
control|)
block|{
comment|// input parameter for a slot or output for a signal
if|if
condition|(
name|types
operator|.
name|at
argument_list|(
name|j
argument_list|)
operator|==
name|QDBusMetaTypeId
operator|::
name|message
argument_list|()
condition|)
block|{
name|isScriptable
operator|=
literal|true
expr_stmt|;
continue|continue;
block|}
name|QString
name|name
decl_stmt|;
if|if
condition|(
operator|!
name|names
operator|.
name|at
argument_list|(
name|j
operator|-
literal|1
argument_list|)
operator|.
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
name|name
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"name=\"%1\" "
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|names
operator|.
name|at
argument_list|(
name|j
operator|-
literal|1
argument_list|)
operator|.
name|name
argument_list|)
argument_list|)
expr_stmt|;
name|bool
name|isOutput
init|=
name|isSignal
operator|||
name|j
operator|>
name|inputCount
decl_stmt|;
specifier|const
name|char
modifier|*
name|signature
init|=
name|QDBusMetaType
operator|::
name|typeToSignature
argument_list|(
name|types
operator|.
name|at
argument_list|(
name|j
argument_list|)
argument_list|)
decl_stmt|;
name|xml
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<arg %1type=\"%2\" direction=\"%3\"/>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|signature
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|isOutput
condition|?
name|QLatin1String
argument_list|(
literal|"out"
argument_list|)
else|:
name|QLatin1String
argument_list|(
literal|"in"
argument_list|)
argument_list|)
expr_stmt|;
comment|// do we need to describe this argument?
if|if
condition|(
name|QDBusMetaType
operator|::
name|signatureToType
argument_list|(
name|signature
argument_list|)
operator|==
name|QVariant
operator|::
name|Invalid
condition|)
block|{
specifier|const
name|char
modifier|*
name|typeName
init|=
name|QMetaType
operator|::
name|typeName
argument_list|(
name|types
operator|.
name|at
argument_list|(
name|j
argument_list|)
argument_list|)
decl_stmt|;
name|xml
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<annotation name=\"org.qtproject.QtDBus.QtTypeName.%1%2\" value=\"%3\"/>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|isOutput
condition|?
name|QLatin1String
argument_list|(
literal|"Out"
argument_list|)
else|:
name|QLatin1String
argument_list|(
literal|"In"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|isOutput
operator|&&
operator|!
name|isSignal
condition|?
name|j
operator|-
name|inputCount
else|:
name|j
operator|-
literal|1
argument_list|)
operator|.
name|arg
argument_list|(
name|typeNameToXml
argument_list|(
name|typeName
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|int
name|wantedMask
decl_stmt|;
if|if
condition|(
name|isScriptable
condition|)
name|wantedMask
operator|=
name|isSignal
condition|?
name|QDBusConnection
operator|::
name|ExportScriptableSignals
else|:
name|QDBusConnection
operator|::
name|ExportScriptableSlots
expr_stmt|;
else|else
name|wantedMask
operator|=
name|isSignal
condition|?
name|QDBusConnection
operator|::
name|ExportNonScriptableSignals
else|:
name|QDBusConnection
operator|::
name|ExportNonScriptableSlots
expr_stmt|;
if|if
condition|(
operator|(
name|flags
operator|&
name|wantedMask
operator|)
operator|!=
name|wantedMask
condition|)
return|return
name|QString
argument_list|()
return|;
if|if
condition|(
name|qDBusCheckAsyncTag
argument_list|(
name|mm
operator|.
name|tag
operator|.
name|constData
argument_list|()
argument_list|)
condition|)
comment|// add the no-reply annotation
name|xml
operator|+=
name|QLatin1String
argument_list|(
literal|"<annotation name=\""
name|ANNOTATION_NO_WAIT
literal|"\""
literal|" value=\"true\"/>\n"
argument_list|)
expr_stmt|;
name|QString
name|retval
init|=
name|xml
decl_stmt|;
name|retval
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"</%1>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|isSignal
condition|?
name|QLatin1String
argument_list|(
literal|"signal"
argument_list|)
else|:
name|QLatin1String
argument_list|(
literal|"method"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|retval
return|;
block|}
end_function
begin_function
DECL|function|generateInterfaceXml
specifier|static
name|QString
name|generateInterfaceXml
parameter_list|(
specifier|const
name|ClassDef
modifier|*
name|mo
parameter_list|)
block|{
name|QString
name|retval
decl_stmt|;
comment|// start with properties:
if|if
condition|(
name|flags
operator|&
operator|(
name|QDBusConnection
operator|::
name|ExportScriptableProperties
operator||
name|QDBusConnection
operator|::
name|ExportNonScriptableProperties
operator|)
condition|)
block|{
specifier|static
specifier|const
name|char
modifier|*
name|accessvalues
index|[]
init|=
block|{
literal|0
block|,
literal|"read"
block|,
literal|"write"
block|,
literal|"readwrite"
block|}
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|PropertyDef
modifier|&
name|mp
decl|,
name|mo
operator|->
name|propertyList
control|)
block|{
if|if
condition|(
operator|!
operator|(
operator|(
operator|!
name|mp
operator|.
name|scriptable
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|(
name|flags
operator|&
name|QDBusConnection
operator|::
name|ExportScriptableProperties
operator|)
operator|)
operator|||
operator|(
operator|!
name|mp
operator|.
name|scriptable
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|(
name|flags
operator|&
name|QDBusConnection
operator|::
name|ExportNonScriptableProperties
operator|)
operator|)
operator|)
condition|)
continue|continue;
name|int
name|access
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|mp
operator|.
name|read
operator|.
name|isEmpty
argument_list|()
condition|)
name|access
operator||=
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|mp
operator|.
name|write
operator|.
name|isEmpty
argument_list|()
condition|)
name|access
operator||=
literal|2
expr_stmt|;
name|int
name|typeId
init|=
name|QMetaType
operator|::
name|type
argument_list|(
name|mp
operator|.
name|type
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|typeId
condition|)
continue|continue;
specifier|const
name|char
modifier|*
name|signature
init|=
name|QDBusMetaType
operator|::
name|typeToSignature
argument_list|(
name|typeId
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|signature
condition|)
continue|continue;
name|retval
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<property name=\"%1\" type=\"%2\" access=\"%3\""
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|mp
operator|.
name|name
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|signature
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|accessvalues
index|[
name|access
index|]
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|QDBusMetaType
operator|::
name|signatureToType
argument_list|(
name|signature
argument_list|)
operator|==
name|QVariant
operator|::
name|Invalid
condition|)
block|{
name|retval
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|">\n<annotation name=\"org.qtproject.QtDBus.QtTypeName\" value=\"%3\"/>\n</property>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|typeNameToXml
argument_list|(
name|mp
operator|.
name|type
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|retval
operator|+=
name|QLatin1String
argument_list|(
literal|"/>\n"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|// now add methods:
if|if
condition|(
name|flags
operator|&
operator|(
name|QDBusConnection
operator|::
name|ExportScriptableSignals
operator||
name|QDBusConnection
operator|::
name|ExportNonScriptableSignals
operator|)
condition|)
block|{
foreach|foreach
control|(
specifier|const
name|FunctionDef
modifier|&
name|mm
decl|,
name|mo
operator|->
name|signalList
control|)
block|{
if|if
condition|(
name|mm
operator|.
name|wasCloned
condition|)
continue|continue;
name|retval
operator|+=
name|addFunction
argument_list|(
name|mm
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|flags
operator|&
operator|(
name|QDBusConnection
operator|::
name|ExportScriptableSlots
operator||
name|QDBusConnection
operator|::
name|ExportNonScriptableSlots
operator|)
condition|)
block|{
foreach|foreach
control|(
specifier|const
name|FunctionDef
modifier|&
name|slot
decl|,
name|mo
operator|->
name|slotList
control|)
block|{
if|if
condition|(
name|slot
operator|.
name|access
operator|==
name|FunctionDef
operator|::
name|Public
condition|)
name|retval
operator|+=
name|addFunction
argument_list|(
name|slot
argument_list|)
expr_stmt|;
block|}
foreach|foreach
control|(
specifier|const
name|FunctionDef
modifier|&
name|method
decl|,
name|mo
operator|->
name|methodList
control|)
block|{
if|if
condition|(
name|method
operator|.
name|access
operator|==
name|FunctionDef
operator|::
name|Public
condition|)
name|retval
operator|+=
name|addFunction
argument_list|(
name|method
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|retval
return|;
block|}
end_function
begin_function
DECL|function|qDBusInterfaceFromClassDef
name|QString
name|qDBusInterfaceFromClassDef
parameter_list|(
specifier|const
name|ClassDef
modifier|*
name|mo
parameter_list|)
block|{
name|QString
name|interface
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|ClassInfoDef
modifier|&
name|cid
decl|,
name|mo
operator|->
name|classInfoList
control|)
block|{
if|if
condition|(
name|cid
operator|.
name|name
operator|==
name|QCLASSINFO_DBUS_INTERFACE
condition|)
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|cid
operator|.
name|value
argument_list|)
return|;
block|}
name|interface
operator|=
name|QLatin1String
argument_list|(
name|mo
operator|->
name|classname
argument_list|)
expr_stmt|;
name|interface
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"::"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|interface
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"QDBus"
argument_list|)
argument_list|)
condition|)
block|{
name|interface
operator|.
name|prepend
argument_list|(
name|QLatin1String
argument_list|(
literal|"org.qtproject.QtDBus."
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|interface
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'Q'
argument_list|)
argument_list|)
operator|&&
name|interface
operator|.
name|length
argument_list|()
operator|>=
literal|2
operator|&&
name|interface
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|isUpper
argument_list|()
condition|)
block|{
comment|// assume it's Qt
name|interface
operator|.
name|prepend
argument_list|(
name|QLatin1String
argument_list|(
literal|"local.org.qtproject.Qt."
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|interface
operator|.
name|prepend
argument_list|(
name|QLatin1String
argument_list|(
literal|"local."
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|interface
return|;
block|}
end_function
begin_function
DECL|function|qDBusGenerateClassDefXml
name|QString
name|qDBusGenerateClassDefXml
parameter_list|(
specifier|const
name|ClassDef
modifier|*
name|cdef
parameter_list|)
block|{
foreach|foreach
control|(
specifier|const
name|ClassInfoDef
modifier|&
name|cid
decl|,
name|cdef
operator|->
name|classInfoList
control|)
block|{
if|if
condition|(
name|cid
operator|.
name|name
operator|==
name|QCLASSINFO_DBUS_INTROSPECTION
condition|)
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|cid
operator|.
name|value
argument_list|)
return|;
block|}
comment|// generate the interface name from the meta object
name|QString
name|interface
init|=
name|qDBusInterfaceFromClassDef
argument_list|(
name|cdef
argument_list|)
decl_stmt|;
name|QString
name|xml
init|=
name|generateInterfaceXml
argument_list|(
name|cdef
argument_list|)
decl_stmt|;
if|if
condition|(
name|xml
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
comment|// don't add an empty interface
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<interface name=\"%1\">\n%2</interface>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|interface
argument_list|,
name|xml
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|showHelp
specifier|static
name|void
name|showHelp
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|help
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showVersion
specifier|static
name|void
name|showVersion
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%s version %s\n"
argument_list|,
name|PROGRAMNAME
argument_list|,
name|PROGRAMVERSION
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"D-Bus QObject-to-XML converter\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parseCmdLine
specifier|static
name|void
name|parseCmdLine
parameter_list|(
name|QStringList
modifier|&
name|arguments
parameter_list|)
block|{
name|flags
operator|=
literal|0
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
name|arguments
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QString
name|arg
init|=
name|arguments
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"--help"
argument_list|)
condition|)
name|showHelp
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'-'
argument_list|)
argument_list|)
condition|)
continue|continue;
name|char
name|c
init|=
name|arg
operator|.
name|count
argument_list|()
operator|==
literal|2
condition|?
name|arg
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toLatin1
argument_list|()
else|:
name|char
argument_list|(
literal|0
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'P'
case|:
name|flags
operator||=
name|QDBusConnection
operator|::
name|ExportNonScriptableProperties
expr_stmt|;
comment|// fall through
case|case
literal|'p'
case|:
name|flags
operator||=
name|QDBusConnection
operator|::
name|ExportScriptableProperties
expr_stmt|;
break|break;
case|case
literal|'S'
case|:
name|flags
operator||=
name|QDBusConnection
operator|::
name|ExportNonScriptableSignals
expr_stmt|;
comment|// fall through
case|case
literal|'s'
case|:
name|flags
operator||=
name|QDBusConnection
operator|::
name|ExportScriptableSignals
expr_stmt|;
break|break;
case|case
literal|'M'
case|:
name|flags
operator||=
name|QDBusConnection
operator|::
name|ExportNonScriptableSlots
expr_stmt|;
comment|// fall through
case|case
literal|'m'
case|:
name|flags
operator||=
name|QDBusConnection
operator|::
name|ExportScriptableSlots
expr_stmt|;
break|break;
case|case
literal|'A'
case|:
name|flags
operator||=
name|QDBusConnection
operator|::
name|ExportNonScriptableContents
expr_stmt|;
comment|// fall through
case|case
literal|'a'
case|:
name|flags
operator||=
name|QDBusConnection
operator|::
name|ExportScriptableContents
expr_stmt|;
break|break;
case|case
literal|'o'
case|:
if|if
condition|(
name|arguments
operator|.
name|count
argument_list|()
operator|<
name|i
operator|+
literal|2
operator|||
name|arguments
operator|.
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'-'
argument_list|)
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"-o expects a filename\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|outputFile
operator|=
name|arguments
operator|.
name|takeAt
argument_list|(
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'h'
case|:
case|case
literal|'?'
case|:
name|showHelp
argument_list|()
expr_stmt|;
break|break;
case|case
literal|'V'
case|:
name|showVersion
argument_list|()
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"unknown option: \"%s\"\n"
argument_list|,
name|qPrintable
argument_list|(
name|arg
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|flags
operator|==
literal|0
condition|)
name|flags
operator|=
name|QDBusConnection
operator|::
name|ExportScriptableContents
operator||
name|QDBusConnection
operator|::
name|ExportNonScriptableContents
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QStringList
name|args
decl_stmt|;
for|for
control|(
name|int
name|n
init|=
literal|1
init|;
name|n
operator|<
name|argc
condition|;
operator|++
name|n
control|)
name|args
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|argv
index|[
name|n
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|parseCmdLine
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|ClassDef
argument_list|>
name|classes
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
name|args
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QString
name|arg
init|=
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'-'
argument_list|)
argument_list|)
condition|)
continue|continue;
name|QFile
name|f
argument_list|(
name|arg
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|PROGRAMNAME
literal|": could not open '%s': %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|arg
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|f
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|Preprocessor
name|pp
decl_stmt|;
name|Moc
name|moc
decl_stmt|;
name|pp
operator|.
name|macros
index|[
literal|"Q_MOC_RUN"
index|]
expr_stmt|;
name|pp
operator|.
name|macros
index|[
literal|"__cplusplus"
index|]
expr_stmt|;
specifier|const
name|QByteArray
name|filename
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
name|moc
operator|.
name|filename
operator|=
name|filename
expr_stmt|;
name|moc
operator|.
name|currentFilenames
operator|.
name|push
argument_list|(
name|filename
argument_list|)
expr_stmt|;
name|moc
operator|.
name|symbols
operator|=
name|pp
operator|.
name|preprocessed
argument_list|(
name|moc
operator|.
name|filename
argument_list|,
operator|&
name|f
argument_list|)
expr_stmt|;
name|moc
operator|.
name|parse
argument_list|()
expr_stmt|;
if|if
condition|(
name|moc
operator|.
name|classList
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|0
return|;
name|classes
operator|=
name|moc
operator|.
name|classList
expr_stmt|;
name|f
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
name|QFile
name|output
decl_stmt|;
if|if
condition|(
name|outputFile
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|output
operator|.
name|open
argument_list|(
name|stdout
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|output
operator|.
name|setFileName
argument_list|(
name|outputFile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|output
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|PROGRAMNAME
literal|": could not open output file '%s': %s"
argument_list|,
name|qPrintable
argument_list|(
name|outputFile
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|output
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
name|output
operator|.
name|write
argument_list|(
name|docTypeHeader
argument_list|)
expr_stmt|;
name|output
operator|.
name|write
argument_list|(
literal|"<node>\n"
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|ClassDef
modifier|&
name|cdef
decl|,
name|classes
control|)
block|{
name|QString
name|xml
init|=
name|qDBusGenerateClassDefXml
argument_list|(
operator|&
name|cdef
argument_list|)
decl_stmt|;
name|output
operator|.
name|write
argument_list|(
name|xml
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|output
operator|.
name|write
argument_list|(
literal|"</node>\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
