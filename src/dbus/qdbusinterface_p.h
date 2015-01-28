begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QDBUSINTERFACE_P_H
end_ifndef
begin_define
DECL|macro|QDBUSINTERFACE_P_H
define|#
directive|define
name|QDBUSINTERFACE_P_H
end_define
begin_include
include|#
directive|include
file|"qdbusabstractinterface_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusmetaobject_p.h"
end_include
begin_include
include|#
directive|include
file|<qdbusinterface.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QDBusInterfacePrivate
range|:
name|public
name|QDBusAbstractInterfacePrivate
block|{
name|public
operator|:
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QDBusInterface
argument_list|)
name|QDBusMetaObject
operator|*
name|metaObject
block|;
name|QDBusInterfacePrivate
argument_list|(
specifier|const
name|QString
operator|&
name|serv
argument_list|,
specifier|const
name|QString
operator|&
name|p
argument_list|,
specifier|const
name|QString
operator|&
name|iface
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|con
argument_list|)
block|;
operator|~
name|QDBusInterfacePrivate
argument_list|()
block|;
name|int
name|metacall
argument_list|(
argument|QMetaObject::Call c
argument_list|,
argument|int id
argument_list|,
argument|void **argv
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
