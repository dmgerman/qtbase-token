begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QDBUSCONNECTIONMANAGER_P_H
end_ifndef
begin_define
DECL|macro|QDBUSCONNECTIONMANAGER_P_H
define|#
directive|define
name|QDBUSCONNECTIONMANAGER_P_H
end_define
begin_include
include|#
directive|include
file|"qdbusconnection_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QDBusConnectionManager
block|{
name|public
label|:
name|QDBusConnectionManager
argument_list|()
block|{}
operator|~
name|QDBusConnectionManager
argument_list|()
expr_stmt|;
specifier|static
name|QDBusConnectionManager
modifier|*
name|instance
parameter_list|()
function_decl|;
name|QDBusConnectionPrivate
modifier|*
name|connection
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|void
name|removeConnection
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|void
name|setConnection
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|QDBusConnectionPrivate
modifier|*
name|c
parameter_list|)
function_decl|;
name|QDBusConnectionPrivate
operator|*
name|sender
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSender
parameter_list|(
specifier|const
name|QDBusConnectionPrivate
modifier|*
name|s
parameter_list|)
function_decl|;
name|mutable
name|QMutex
name|mutex
decl_stmt|;
name|private
label|:
name|QHash
operator|<
name|QString
operator|,
name|QDBusConnectionPrivate
operator|*
operator|>
name|connectionHash
expr_stmt|;
name|mutable
name|QMutex
name|senderMutex
decl_stmt|;
name|QString
name|senderName
decl_stmt|;
comment|// internal; will probably change
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
