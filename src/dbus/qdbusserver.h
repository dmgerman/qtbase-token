begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|DBus
argument_list|)
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
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
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
