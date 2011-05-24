begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSCONTEXT_H
end_ifndef
begin_define
DECL|macro|QDBUSCONTEXT_H
define|#
directive|define
name|QDBUSCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbuserror.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|DBus
parameter_list|)
name|class
name|QDBusConnection
decl_stmt|;
DECL|variable|QDBusMessage
name|class
name|QDBusMessage
decl_stmt|;
DECL|variable|QDBusContextPrivate
name|class
name|QDBusContextPrivate
decl_stmt|;
name|class
name|Q_DBUS_EXPORT
name|QDBusContext
decl_stmt|{ public:     QDBusContext(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
operator|~
name|QDBusContext
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|calledFromDBus
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDBusConnection
name|connection
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|// convenience methods
end_comment
begin_expr_stmt
name|bool
name|isDelayedReply
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|// yes, they are const, so that you can use them even from const methods
end_comment
begin_decl_stmt
name|void
name|setDelayedReply
argument_list|(
name|bool
name|enable
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|sendErrorReply
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|msg
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|sendErrorReply
argument_list|(
name|QDBusError
operator|::
name|ErrorType
name|type
argument_list|,
specifier|const
name|QString
operator|&
name|msg
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QDBusContextPrivate
modifier|*
name|d_ptr
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QDBusContextPrivate
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
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
