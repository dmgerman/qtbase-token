begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSUTIL_P_H
end_ifndef
begin_define
DECL|macro|QDBUSUTIL_P_H
define|#
directive|define
name|QDBUSUTIL_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusmacros.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbuserror.h>
end_include
begin_include
include|#
directive|include
file|"qdbus_symbols_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QDBusUtil
block|{
name|Q_DBUS_EXPORT
name|bool
name|isValidInterfaceName
parameter_list|(
specifier|const
name|QString
modifier|&
name|ifaceName
parameter_list|)
function_decl|;
name|Q_DBUS_EXPORT
name|bool
name|isValidUniqueConnectionName
parameter_list|(
specifier|const
name|QString
modifier|&
name|busName
parameter_list|)
function_decl|;
name|Q_DBUS_EXPORT
name|bool
name|isValidBusName
parameter_list|(
specifier|const
name|QString
modifier|&
name|busName
parameter_list|)
function_decl|;
name|Q_DBUS_EXPORT
name|bool
name|isValidMemberName
parameter_list|(
specifier|const
name|QString
modifier|&
name|memberName
parameter_list|)
function_decl|;
name|Q_DBUS_EXPORT
name|bool
name|isValidErrorName
parameter_list|(
specifier|const
name|QString
modifier|&
name|errorName
parameter_list|)
function_decl|;
name|Q_DBUS_EXPORT
name|bool
name|isValidPartOfObjectPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
name|Q_DBUS_EXPORT
name|bool
name|isValidObjectPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
name|Q_DBUS_EXPORT
name|bool
name|isValidFixedType
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
name|Q_DBUS_EXPORT
name|bool
name|isValidBasicType
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
name|Q_DBUS_EXPORT
name|bool
name|isValidSignature
parameter_list|(
specifier|const
name|QString
modifier|&
name|signature
parameter_list|)
function_decl|;
name|Q_DBUS_EXPORT
name|bool
name|isValidSingleSignature
parameter_list|(
specifier|const
name|QString
modifier|&
name|signature
parameter_list|)
function_decl|;
name|Q_DBUS_EXPORT
name|QString
name|argumentToString
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|variant
parameter_list|)
function_decl|;
enum|enum
name|AllowEmptyFlag
block|{
name|EmptyAllowed
block|,
name|EmptyNotAllowed
block|}
enum|;
specifier|inline
name|bool
name|checkInterfaceName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|AllowEmptyFlag
name|empty
parameter_list|,
name|QDBusError
modifier|*
name|error
parameter_list|)
block|{
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|empty
operator|==
name|EmptyAllowed
condition|)
return|return
name|true
return|;
operator|*
name|error
operator|=
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|InvalidInterface
argument_list|,
name|QLatin1String
argument_list|(
literal|"Interface name cannot be empty"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
if|if
condition|(
name|isValidInterfaceName
argument_list|(
name|name
argument_list|)
condition|)
return|return
name|true
return|;
operator|*
name|error
operator|=
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|InvalidInterface
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Invalid interface class: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|checkBusName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|AllowEmptyFlag
name|empty
parameter_list|,
name|QDBusError
modifier|*
name|error
parameter_list|)
block|{
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|empty
operator|==
name|EmptyAllowed
condition|)
return|return
name|true
return|;
operator|*
name|error
operator|=
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|InvalidService
argument_list|,
name|QLatin1String
argument_list|(
literal|"Service name cannot be empty"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
if|if
condition|(
name|isValidBusName
argument_list|(
name|name
argument_list|)
condition|)
return|return
name|true
return|;
operator|*
name|error
operator|=
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|InvalidService
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Invalid service name: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|checkObjectPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|AllowEmptyFlag
name|empty
parameter_list|,
name|QDBusError
modifier|*
name|error
parameter_list|)
block|{
if|if
condition|(
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|empty
operator|==
name|EmptyAllowed
condition|)
return|return
name|true
return|;
operator|*
name|error
operator|=
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|InvalidObjectPath
argument_list|,
name|QLatin1String
argument_list|(
literal|"Object path cannot be empty"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
if|if
condition|(
name|isValidObjectPath
argument_list|(
name|path
argument_list|)
condition|)
return|return
name|true
return|;
operator|*
name|error
operator|=
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|InvalidObjectPath
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Invalid object path: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|path
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|checkMemberName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|AllowEmptyFlag
name|empty
parameter_list|,
name|QDBusError
modifier|*
name|error
parameter_list|,
specifier|const
name|char
modifier|*
name|nameType
init|=
literal|0
parameter_list|)
block|{
if|if
condition|(
operator|!
name|nameType
condition|)
name|nameType
operator|=
literal|"member"
expr_stmt|;
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|empty
operator|==
name|EmptyAllowed
condition|)
return|return
name|true
return|;
operator|*
name|error
operator|=
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|InvalidMember
argument_list|,
name|QLatin1String
argument_list|(
name|nameType
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|" name cannot be empty"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
if|if
condition|(
name|isValidMemberName
argument_list|(
name|name
argument_list|)
condition|)
return|return
name|true
return|;
operator|*
name|error
operator|=
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|InvalidMember
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Invalid %1 name: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|nameType
argument_list|)
argument_list|,
name|name
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|checkErrorName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|AllowEmptyFlag
name|empty
parameter_list|,
name|QDBusError
modifier|*
name|error
parameter_list|)
block|{
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|empty
operator|==
name|EmptyAllowed
condition|)
return|return
name|true
return|;
operator|*
name|error
operator|=
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|InvalidInterface
argument_list|,
name|QLatin1String
argument_list|(
literal|"Error name cannot be empty"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
if|if
condition|(
name|isValidErrorName
argument_list|(
name|name
argument_list|)
condition|)
return|return
name|true
return|;
operator|*
name|error
operator|=
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|InvalidInterface
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Invalid error name: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
specifier|inline
name|QString
name|dbusService
parameter_list|()
block|{
return|return
name|QStringLiteral
argument_list|(
name|DBUS_SERVICE_DBUS
argument_list|)
return|;
block|}
specifier|inline
name|QString
name|dbusPath
parameter_list|()
block|{
return|return
name|QStringLiteral
argument_list|(
name|DBUS_PATH_DBUS
argument_list|)
return|;
block|}
specifier|inline
name|QString
name|dbusInterface
parameter_list|()
block|{
comment|// it's the same string, but just be sure
name|Q_ASSERT
argument_list|(
name|dbusService
argument_list|()
operator|==
name|QLatin1String
argument_list|(
name|DBUS_INTERFACE_DBUS
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|dbusService
argument_list|()
return|;
block|}
specifier|inline
name|QString
name|dbusInterfaceProperties
parameter_list|()
block|{
return|return
name|QStringLiteral
argument_list|(
name|DBUS_INTERFACE_PROPERTIES
argument_list|)
return|;
block|}
specifier|inline
name|QString
name|dbusInterfaceIntrospectable
parameter_list|()
block|{
return|return
name|QStringLiteral
argument_list|(
name|DBUS_INTERFACE_INTROSPECTABLE
argument_list|)
return|;
block|}
specifier|inline
name|QString
name|nameOwnerChanged
parameter_list|()
block|{
return|return
name|QStringLiteral
argument_list|(
literal|"NameOwnerChanged"
argument_list|)
return|;
block|}
specifier|inline
name|QString
name|disconnectedErrorMessage
parameter_list|()
block|{
return|return
name|QStringLiteral
argument_list|(
literal|"Not connected to D-Bus server"
argument_list|)
return|;
block|}
block|}
end_decl_stmt
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
begin_endif
endif|#
directive|endif
end_endif
end_unit
