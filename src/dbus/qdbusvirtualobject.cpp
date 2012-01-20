begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
comment|/*!     \internal     \class QDBusVirtualObject     \inmodule QtDBus     \since 4.8      \brief The QDBusVirtualObject class is used to handle several DBus paths with one class. */
end_comment
begin_comment
comment|/*!     \internal     \fn bool QDBusVirtualObject::handleMessage(const QDBusMessage&message, const QDBusConnection&connection) = 0      This function needs to handle all messages to the path of the     virtual object, when the SubPath option is specified.     The service, path, interface and methos are all part of the message.     Must return true when the message is handled, otherwise false (will generate dbus error message). */
end_comment
begin_comment
comment|/*!     \internal     \fn QString QDBusVirtualObject::introspect(const QString&path) const      This function needs to handle the introspection of the     virtual object. It must return xml of the form:      \code<interface name="com.trolltech.QtDBus.MyObject"><property access="readwrite" type="i" name="prop1" /></interface>     \endcode      If you pass the SubPath option, this introspection has to include all child nodes.     Otherwise QDBus handles the introspection of the child nodes. */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DBUS
end_comment
end_unit
