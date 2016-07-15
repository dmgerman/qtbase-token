begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusvirtualobject.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     Constructs a QDBusVirtualObject with \a parent. */
end_comment
begin_constructor
DECL|function|QDBusVirtualObject
name|QDBusVirtualObject
operator|::
name|QDBusVirtualObject
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the object, deleting all of its child objects. */
end_comment
begin_destructor
DECL|function|~QDBusVirtualObject
name|QDBusVirtualObject
operator|::
name|~
name|QDBusVirtualObject
parameter_list|()
block|{ }
end_destructor
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QDBusVirtualObject     \inmodule QtDBus     \since 5.1      \brief The QDBusVirtualObject class is used to handle several DBus paths with one class. */
end_comment
begin_comment
comment|/*!     \fn bool QDBusVirtualObject::handleMessage(const QDBusMessage&message, const QDBusConnection&connection) = 0      This function needs to handle all messages to the path of the     virtual object, when the SubPath option is specified.     The service, path, interface and methos are all part of the \a message.     Parameter \a connection is the connection handle.     Must return \c true when the message is handled, otherwise \c false (will generate dbus error message). */
end_comment
begin_comment
comment|/*!     \fn QString QDBusVirtualObject::introspect(const QString&path) const      This function needs to handle the introspection of the     virtual object on \a path. It must return xml of the form:      \code<interface name="org.qtproject.QtDBus.MyObject"><property access="readwrite" type="i" name="prop1" /></interface>     \endcode      If you pass the SubPath option, this introspection has to include all child nodes.     Otherwise QDBus handles the introspection of the child nodes. */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DBUS
end_comment
end_unit
