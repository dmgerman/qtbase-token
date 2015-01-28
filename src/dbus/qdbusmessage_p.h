begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSMESSAGE_P_H
end_ifndef
begin_define
DECL|macro|QDBUSMESSAGE_P_H
define|#
directive|define
name|QDBUSMESSAGE_P_H
end_define
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
begin_include
include|#
directive|include
file|<qatomic.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qdbusmessage.h>
end_include
begin_include
include|#
directive|include
file|<qdbusconnection.h>
end_include
begin_struct_decl
struct_decl|struct
name|DBusMessage
struct_decl|;
end_struct_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusConnectionPrivate
name|class
name|QDBusConnectionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusMessagePrivate
block|{
name|public
label|:
name|QDBusMessagePrivate
argument_list|()
expr_stmt|;
operator|~
name|QDBusMessagePrivate
argument_list|()
expr_stmt|;
name|QList
operator|<
name|QVariant
operator|>
name|arguments
expr_stmt|;
comment|// the following parameters are "const": they are not changed after the constructors
comment|// the parametersValidated member below controls whether they've been validated already
name|QString
name|service
decl_stmt|,
name|path
decl_stmt|,
name|interface
decl_stmt|,
name|name
decl_stmt|,
name|message
decl_stmt|,
name|signature
decl_stmt|;
name|DBusMessage
modifier|*
name|msg
decl_stmt|;
name|DBusMessage
modifier|*
name|reply
decl_stmt|;
name|mutable
name|QDBusMessage
modifier|*
name|localReply
decl_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
name|QDBusMessage
operator|::
name|MessageType
name|type
expr_stmt|;
name|mutable
name|uint
name|delayedReply
range|:
literal|1
decl_stmt|;
name|uint
name|localMessage
range|:
literal|1
decl_stmt|;
name|mutable
name|uint
name|parametersValidated
range|:
literal|1
decl_stmt|;
name|uint
name|autoStartService
range|:
literal|1
decl_stmt|;
specifier|static
name|void
name|setParametersValidated
parameter_list|(
name|QDBusMessage
modifier|&
name|msg
parameter_list|,
name|bool
name|enable
parameter_list|)
block|{
name|msg
operator|.
name|d_ptr
operator|->
name|parametersValidated
operator|=
name|enable
expr_stmt|;
block|}
specifier|static
name|DBusMessage
modifier|*
name|toDBusMessage
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
name|QDBusConnection
operator|::
name|ConnectionCapabilities
name|capabilities
argument_list|,
name|QDBusError
operator|*
name|error
argument_list|)
decl_stmt|;
specifier|static
name|QDBusMessage
name|fromDBusMessage
argument_list|(
name|DBusMessage
operator|*
name|dmsg
argument_list|,
name|QDBusConnection
operator|::
name|ConnectionCapabilities
name|capabilities
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|isLocal
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|msg
parameter_list|)
function_decl|;
specifier|static
name|QDBusMessage
name|makeLocal
parameter_list|(
specifier|const
name|QDBusConnectionPrivate
modifier|&
name|conn
parameter_list|,
specifier|const
name|QDBusMessage
modifier|&
name|asSent
parameter_list|)
function_decl|;
specifier|static
name|QDBusMessage
name|makeLocalReply
parameter_list|(
specifier|const
name|QDBusConnectionPrivate
modifier|&
name|conn
parameter_list|,
specifier|const
name|QDBusMessage
modifier|&
name|asSent
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
