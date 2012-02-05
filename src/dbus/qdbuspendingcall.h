begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSPENDINGCALL_H
end_ifndef
begin_define
DECL|macro|QDBUSPENDINGCALL_H
define|#
directive|define
name|QDBUSPENDINGCALL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusmacros.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusmessage.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusConnection
name|class
name|QDBusConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusError
name|class
name|QDBusError
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusPendingCallWatcher
name|class
name|QDBusPendingCallWatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusPendingCallPrivate
name|class
name|QDBusPendingCallPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_DBUS_EXPORT
name|QDBusPendingCall
block|{
name|public
label|:
name|QDBusPendingCall
argument_list|(
specifier|const
name|QDBusPendingCall
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QDBusPendingCall
argument_list|()
expr_stmt|;
name|QDBusPendingCall
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDBusPendingCall
operator|&
name|other
operator|)
decl_stmt|;
ifndef|#
directive|ifndef
name|Q_QDOC
comment|// pretend that they aren't here
name|bool
name|isFinished
argument_list|()
specifier|const
expr_stmt|;
name|void
name|waitForFinished
parameter_list|()
function_decl|;
name|bool
name|isError
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|QDBusError
name|error
argument_list|()
specifier|const
expr_stmt|;
name|QDBusMessage
name|reply
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
specifier|static
name|QDBusPendingCall
name|fromError
parameter_list|(
specifier|const
name|QDBusError
modifier|&
name|error
parameter_list|)
function_decl|;
specifier|static
name|QDBusPendingCall
name|fromCompletedCall
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|message
parameter_list|)
function_decl|;
name|protected
label|:
name|QExplicitlySharedDataPointer
operator|<
name|QDBusPendingCallPrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QDBusPendingCallPrivate
decl_stmt|;
name|friend
name|class
name|QDBusPendingCallWatcher
decl_stmt|;
name|friend
name|class
name|QDBusConnection
decl_stmt|;
name|QDBusPendingCall
argument_list|(
name|QDBusPendingCallPrivate
operator|*
name|dd
argument_list|)
expr_stmt|;
name|private
label|:
name|QDBusPendingCall
argument_list|()
expr_stmt|;
comment|// not defined
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QDBusPendingCallWatcherPrivate
name|class
name|QDBusPendingCallWatcherPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|Q_DBUS_EXPORT
name|QDBusPendingCallWatcher
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QDBusPendingCall
block|{
name|Q_OBJECT
name|public
range|:
name|QDBusPendingCallWatcher
argument_list|(
specifier|const
name|QDBusPendingCall
operator|&
name|call
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|QDBusPendingCallWatcher
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_QDOC
comment|// trick qdoc into thinking this method is here
name|bool
name|isFinished
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|void
name|waitForFinished
parameter_list|()
function_decl|;
comment|// non-virtual override
name|Q_SIGNALS
label|:
name|void
name|finished
parameter_list|(
name|QDBusPendingCallWatcher
modifier|*
name|self
parameter_list|)
function_decl|;
name|private
label|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDBusPendingCallWatcher
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_finished()
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
