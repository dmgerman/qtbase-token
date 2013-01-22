begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusintrospection_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusxmlparser_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QDBusIntrospection     \inmodule QtDBus     \brief Information about introspected objects and interfaces on D-Bus.     \internal      This class provides structures and methods for parsing the XML introspection data for D-Bus.     Normally, you don't have to use the methods provided here: QDBusInterface and QDBusObject will     do that for you.      But they may prove useful if the XML data was obtained through other means (like parsing a file). */
comment|/*!     \class QDBusIntrospection::Argument     \inmodule QtDBus     \brief One argument to a D-Bus method or signal.      This struct represents one argument passed to a method or received from a method or signal in     D-Bus. The struct does not contain information on the direction (input or output). */
comment|/*!     \variable QDBusIntrospection::Argument::type     The argument type. */
comment|/*!     \variable QDBusIntrospection::Argument::name     The argument name. The argument name is optional, so this may be a null QString. */
comment|/*!     \fn QDBusIntrospection::Argument::operator==(const Argument&other) const     Compares this object against \a other and return true if they are the same. */
comment|/*!     \class QDBusIntrospection::Method     \inmodule QtDBus     \brief Information about one method.      This struct represents one method discovered through introspection. A method is composed of     its \a name, its input arguments, its output arguments, and, optionally, annotations. There are no     "in-out" arguments. */
comment|/*!     \variable QDBusIntrospection::Method::name     The method's name. */
comment|/*!     \variable QDBusIntrospection::Method::inputArgs     A list of the method's input arguments. */
comment|/*!     \variable QDBusIntrospection::Method::outputArgs     A list of the method's output arguments (i.e., return values). */
comment|/*!     \variable QDBusIntrospection::Method::annotations     The annotations associated with the method. Each annotation is a pair of strings, where the key     is of the same format as a D-Bus interface name. The value is arbitrary. */
comment|/*!     \fn QDBusIntrospection::Method::operator==(const Method&other) const     Compares this object against \a other and return true if they are the same. */
comment|/*!     \class QDBusIntrospection::Signal     \inmodule QtDBus     \brief Information about one signal.      This struct represents one signal discovered through introspection. A signal is composed of     its \a name, its output arguments, and, optionally, annotations. */
comment|/*!     \variable QDBusIntrospection::Signal::name     The signal's name. */
comment|/*!     \variable QDBusIntrospection::Signal::outputArgs     A list of the signal's arguments. */
comment|/*!     \variable QDBusIntrospection::Signal::annotations     The annotations associated with the signal. Each annotation is a pair of strings, where the key     is of the same format as a D-Bus interface name. The value is arbitrary. */
comment|/*!     \fn QDBusIntrospection::Signal::operator==(const Signal& other) const     Compares this object against \a other and return true if they are the same. */
comment|/*!     \class QDBusIntrospection::Property     \inmodule QtDBus     \brief Information about one property.      This struct represents one property discovered through introspection. A property is composed of     its \a name, its \a type, its \a access rights, and, optionally, annotations. */
comment|/*!     \variable QDBusIntrospection::Property::name     The property's name. */
comment|/*!     \variable QDBusIntrospection::Property::type     The property's type. */
comment|/*!     \enum QDBusIntrospection::Property::Access     The possible access rights for a property:     \value Read     \value Write     \value ReadWrite */
comment|/*!     \variable QDBusIntrospection::Property::access     The property's access rights. */
comment|/*!     \variable QDBusIntrospection::Property::annotations     The annotations associated with the property. Each annotation is a pair of strings, where the key     is of the same format as a D-Bus interface name. The value is arbitrary. */
comment|/*!     \fn QDBusIntrospection::Property::operator==(const Property&other) const     Compares this object against \a other and return true if they are the same. */
comment|/*!     \class QDBusIntrospection::Interface     \inmodule QtDBus     \brief Information about one interface on the bus.      Each interface on D-Bus has an unique \a name, identifying where that interface was defined.     Interfaces may have annotations, methods, signals and properties, but none are mandatory. */
comment|/*!     \variable QDBusIntrospection::Interface::name     The interface's name. */
comment|/*!     \variable QDBusIntrospection::Interface::introspection     The XML document fragment describing this interface.      If parsed again through parseInterface, the object returned should have the same contents as     this object. */
comment|/*!     \variable QDBusIntrospection::Interface::annotations     The annotations associated with the interface. Each annotation is a pair of strings, where the key     is of the same format as a D-Bus interface name. The value is arbitrary. */
comment|/*!     \variable QDBusIntrospection::Interface::methods     The methods available in this interface. Note that method names are not unique (i.e., methods     can be overloaded with multiple arguments types). */
comment|/*!     \variable QDBusIntrospection::Interface::signals_     The signals available in this interface. Note that signal names are not unique (i.e., signals     can be overloaded with multiple argument types).      This member is called "signals_" because "signals" is a reserved keyword in Qt. */
comment|/*!     \variable QDBusIntrospection::Interface::properties     The properties available in this interface. Property names are unique. */
comment|/*!     \fn QDBusIntrospection::Interface::operator==(const Interface&other) const     Compares this object against \a other and return true if they are the same.      Note that two interfaces are considered to be the same if they have the same name. The internal     structures in the objects are not compared. */
comment|/*!     \class QDBusIntrospection::Object     \inmodule QtDBus     \brief Information about one object on the bus.      An object on the D-Bus bus is represented by its service and path on the service but, unlike     interfaces, objects are mutable. That is, their contents can change with time. Therefore,     while the (service, path) pair uniquely identifies an object, the information contained in     this struct may no longer represent the object.      An object can contain interfaces and child (sub) objects. */
comment|/*!     \variable QDBusIntrospection::Object::service     The object's service name.      \sa parseObject() */
comment|/*!     \variable QDBusIntrospection::Object::path     The object's path on the service. This is an absolute path.      \sa parseObject() */
comment|/*!     \variable QDBusIntrospection::Object::introspection     The XML document fragment describing this object, its interfaces and sub-objects at the time     of the parsing.      The result of parseObject with this XML data should be the same as the Object struct. */
comment|/*!     \variable QDBusIntrospection::Object::interfaces     The list of interface names in this object. */
comment|/*!     \variable QDBusIntrospection::Object::childObjects     The list of child object names in this object. Note that this is a relative name, not an     absolute path. To obtain the absolute path, concatenate with \l     {QDBusIntrospection::Object::path}{path}. */
comment|/*!     \typedef QDBusIntrospection::Annotations     Contains a QMap of an annotation pair. The annotation's name is stored in the QMap key and     must be unique. The annotation's value is stored in the QMap's value and is arbitrary. */
comment|/*!     \typedef QDBusIntrospection::Arguments     Contains a list of arguments to either a Method or a Signal. The arguments' order is important. */
comment|/*!     \typedef QDBusIntrospection::Methods     Contains a QMap of methods and their names. The method's name is stored in the map's key and     is not necessarily unique. The order in which multiple methods with the same name are stored     in this map is undefined. */
comment|/*!     \typedef QDBusIntrospection::Signals     Contains a QMap of signals and their names. The signal's name is stored in the map's key and     is not necessarily unique. The order in which multiple signals with the same name are stored     in this map is undefined. */
comment|/*!     \typedef QDBusIntrospection::Properties     Contains a QMap of properties and their names. Each property must have a unique name. */
comment|/*!     \typedef QDBusIntrospection::Interfaces     Contains a QMap of interfaces and their names. Each interface has a unique name. */
comment|/*!     \typedef QDBusIntrospection::Objects     Contains a QMap of objects and their paths relative to their immediate parent. */
comment|/*!     Parses the XML document fragment (given by \a xml) containing one interface.      The first element tag in this XML data must be either \<node\> or \<interface\>. If it is     \<node\>, then the \<interface\> tag must be a child tag of the \<node\> one.      If there are multiple interfaces in this XML data, it is undefined which one will be     returned. */
name|QDBusIntrospection
operator|::
name|Interface
DECL|function|parseInterface
name|QDBusIntrospection
operator|::
name|parseInterface
parameter_list|(
specifier|const
name|QString
modifier|&
name|xml
parameter_list|)
block|{
comment|// be lazy
name|Interfaces
name|ifs
init|=
name|parseInterfaces
argument_list|(
name|xml
argument_list|)
decl_stmt|;
if|if
condition|(
name|ifs
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|Interface
argument_list|()
return|;
comment|// return the first in map order (probably alphabetical order)
return|return
operator|*
name|ifs
operator|.
name|constBegin
argument_list|()
operator|.
name|value
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Parses the XML document fragment (given by \a xml) containing several interfaces.      If the first element tag in this document fragment is \<node\>, the interfaces parsed will     be those found as child elements of the \<node\> tag. */
end_comment
begin_function
name|QDBusIntrospection
operator|::
name|Interfaces
DECL|function|parseInterfaces
name|QDBusIntrospection
operator|::
name|parseInterfaces
parameter_list|(
specifier|const
name|QString
modifier|&
name|xml
parameter_list|)
block|{
name|QString
name|null
decl_stmt|;
name|QDBusXmlParser
name|parser
argument_list|(
name|null
argument_list|,
name|null
argument_list|,
name|xml
argument_list|)
decl_stmt|;
return|return
name|parser
operator|.
name|interfaces
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Parses the XML document fragment (given by \a xml) containing one object, found at the service     \a service and path \a path.      The first element tag in this document must be \<node\>. If that tag does not contain     a name attribute, the \a path argument will be used to determine the path of this     object node.      This function does not parse the interfaces contained in the node, nor sub-object's contents.     It will only list their names. */
end_comment
begin_function
name|QDBusIntrospection
operator|::
name|Object
DECL|function|parseObject
name|QDBusIntrospection
operator|::
name|parseObject
parameter_list|(
specifier|const
name|QString
modifier|&
name|xml
parameter_list|,
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
name|QDBusXmlParser
name|parser
argument_list|(
name|service
argument_list|,
name|path
argument_list|,
name|xml
argument_list|)
decl_stmt|;
name|QSharedDataPointer
argument_list|<
name|QDBusIntrospection
operator|::
name|Object
argument_list|>
name|retval
init|=
name|parser
operator|.
name|object
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|retval
condition|)
return|return
name|QDBusIntrospection
operator|::
name|Object
argument_list|()
return|;
return|return
operator|*
name|retval
return|;
block|}
end_function
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
