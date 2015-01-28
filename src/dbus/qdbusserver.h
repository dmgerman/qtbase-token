begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSSERVER_H
end_ifndef
begin_define
DECL|macro|QDBUSSERVER_H
define|#
directive|define
name|QDBUSSERVER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusmacros.h>
end_include
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
DECL|variable|QDBusError
name|class
name|QDBusError
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusConnection
name|class
name|QDBusConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_DBUS_EXPORT
name|QDBusServer
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QDBusServer
argument_list|(
specifier|const
name|QString
operator|&
name|address
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QDBusServer
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QDBusServer
argument_list|()
block|;
name|bool
name|isConnected
argument_list|()
specifier|const
block|;
name|QDBusError
name|lastError
argument_list|()
specifier|const
block|;
name|QString
name|address
argument_list|()
specifier|const
block|;
name|void
name|setAnonymousAuthenticationAllowed
argument_list|(
argument|bool value
argument_list|)
block|;
name|bool
name|isAnonymousAuthenticationAllowed
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|newConnection
argument_list|(
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QDBusServer
argument_list|)
name|QDBusConnectionPrivate
operator|*
name|d
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
