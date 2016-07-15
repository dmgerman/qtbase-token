begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Copyright (C) 2015 Intel Corporation. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
comment|// This file is not part of the public API.  This header file may
end_comment
begin_comment
comment|// change from version to version without notice, or even be
end_comment
begin_comment
comment|// removed.
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
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSABSTRACTINTERFACE_P_H
end_ifndef
begin_define
DECL|macro|QDBUSABSTRACTINTERFACE_P_H
define|#
directive|define
name|QDBUSABSTRACTINTERFACE_P_H
end_define
begin_include
include|#
directive|include
file|<qdbusabstractinterface.h>
end_include
begin_include
include|#
directive|include
file|<qdbusconnection.h>
end_include
begin_include
include|#
directive|include
file|<qdbuserror.h>
end_include
begin_include
include|#
directive|include
file|"qdbusconnection_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_define
DECL|macro|ANNOTATION_NO_WAIT
define|#
directive|define
name|ANNOTATION_NO_WAIT
value|"org.freedesktop.DBus.Method.NoReply"
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QDBusAbstractInterfacePrivate
range|:
name|public
name|QObjectPrivate
block|{
name|public
operator|:
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QDBusAbstractInterface
argument_list|)
name|mutable
name|QDBusConnection
name|connection
block|;
comment|// mutable because we want to make calls from const functions
name|QString
name|service
block|;
name|QString
name|currentOwner
block|;
name|QString
name|path
block|;
name|QString
name|interface
block|;
name|mutable
name|QDBusError
name|lastError
block|;
name|int
name|timeout
block|;
comment|// this is set during creation and never changed
comment|// it can't be const because QDBusInterfacePrivate has one more check
name|bool
name|isValid
block|;
name|QDBusAbstractInterfacePrivate
argument_list|(
argument|const QString&serv
argument_list|,
argument|const QString&p
argument_list|,
argument|const QString&iface
argument_list|,
argument|const QDBusConnection& con
argument_list|,
argument|bool dynamic
argument_list|)
block|;
name|virtual
operator|~
name|QDBusAbstractInterfacePrivate
argument_list|()
block|{ }
name|void
name|initOwnerTracking
argument_list|()
block|;
name|bool
name|canMakeCalls
argument_list|()
specifier|const
block|;
comment|// these functions do not check if the property is valid
name|bool
name|property
argument_list|(
argument|const QMetaProperty&mp
argument_list|,
argument|void *returnValuePtr
argument_list|)
specifier|const
block|;
name|bool
name|setProperty
argument_list|(
specifier|const
name|QMetaProperty
operator|&
name|mp
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
block|;
comment|// return conn's d pointer
specifier|inline
name|QDBusConnectionPrivate
operator|*
name|connectionPrivate
argument_list|()
specifier|const
block|{
return|return
name|QDBusConnectionPrivate
operator|::
name|d
argument_list|(
name|connection
argument_list|)
return|;
block|}
name|void
name|_q_serviceOwnerChanged
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|oldOwner
argument_list|,
specifier|const
name|QString
operator|&
name|newOwner
argument_list|)
block|;
specifier|static
name|void
name|finishDisconnectNotify
argument_list|(
argument|QDBusAbstractInterface *iface
argument_list|,
argument|int signalId
argument_list|)
block|; }
decl_stmt|;
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
