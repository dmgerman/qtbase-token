begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSABSTRACTINTERFACE_H
end_ifndef
begin_define
DECL|macro|QDBUSABSTRACTINTERFACE_H
define|#
directive|define
name|QDBUSABSTRACTINTERFACE_H
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
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusmessage.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusextratypes.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusconnection.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusError
name|class
name|QDBusError
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusPendingCall
name|class
name|QDBusPendingCall
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusAbstractInterfacePrivate
name|class
name|QDBusAbstractInterfacePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_DBUS_EXPORT
name|QDBusAbstractInterfaceBase
range|:
name|public
name|QObject
block|{
name|public
operator|:
name|int
name|qt_metacall
argument_list|(
name|QMetaObject
operator|::
name|Call
argument_list|,
name|int
argument_list|,
name|void
operator|*
operator|*
argument_list|)
block|;
name|protected
operator|:
name|QDBusAbstractInterfaceBase
argument_list|(
name|QDBusAbstractInterfacePrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDBusAbstractInterface
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_DBUS_EXPORT
name|QDBusAbstractInterface
range|:
ifdef|#
directive|ifdef
name|Q_QDOC
name|public
name|QObject
else|#
directive|else
name|public
name|QDBusAbstractInterfaceBase
endif|#
directive|endif
block|{
name|Q_OBJECT
name|public
operator|:
name|virtual
operator|~
name|QDBusAbstractInterface
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|QDBusConnection
name|connection
argument_list|()
specifier|const
block|;
name|QString
name|service
argument_list|()
specifier|const
block|;
name|QString
name|path
argument_list|()
specifier|const
block|;
name|QString
name|interface
argument_list|()
specifier|const
block|;
name|QDBusError
name|lastError
argument_list|()
specifier|const
block|;
name|void
name|setTimeout
argument_list|(
argument|int timeout
argument_list|)
block|;
name|int
name|timeout
argument_list|()
specifier|const
block|;
name|QDBusMessage
name|call
argument_list|(
specifier|const
name|QString
operator|&
name|method
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg1
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg2
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg3
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg4
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg5
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg6
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg7
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg8
operator|=
name|QVariant
argument_list|()
argument_list|)
block|;
name|QDBusMessage
name|call
argument_list|(
argument|QDBus::CallMode mode
argument_list|,
argument|const QString&method
argument_list|,
argument|const QVariant&arg1 = QVariant()
argument_list|,
argument|const QVariant&arg2 = QVariant()
argument_list|,
argument|const QVariant&arg3 = QVariant()
argument_list|,
argument|const QVariant&arg4 = QVariant()
argument_list|,
argument|const QVariant&arg5 = QVariant()
argument_list|,
argument|const QVariant&arg6 = QVariant()
argument_list|,
argument|const QVariant&arg7 = QVariant()
argument_list|,
argument|const QVariant&arg8 = QVariant()
argument_list|)
block|;
name|QDBusMessage
name|callWithArgumentList
argument_list|(
argument|QDBus::CallMode mode
argument_list|,
argument|const QString&method
argument_list|,
argument|const QList<QVariant>&args
argument_list|)
block|;
name|bool
name|callWithCallback
argument_list|(
specifier|const
name|QString
operator|&
name|method
argument_list|,
specifier|const
name|QList
operator|<
name|QVariant
operator|>
operator|&
name|args
argument_list|,
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|,
specifier|const
name|char
operator|*
name|errorSlot
argument_list|)
block|;
name|bool
name|callWithCallback
argument_list|(
specifier|const
name|QString
operator|&
name|method
argument_list|,
specifier|const
name|QList
operator|<
name|QVariant
operator|>
operator|&
name|args
argument_list|,
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|)
block|;
name|QDBusPendingCall
name|asyncCall
argument_list|(
specifier|const
name|QString
operator|&
name|method
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg1
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg2
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg3
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg4
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg5
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg6
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg7
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg8
operator|=
name|QVariant
argument_list|()
argument_list|)
block|;
name|QDBusPendingCall
name|asyncCallWithArgumentList
argument_list|(
specifier|const
name|QString
operator|&
name|method
argument_list|,
specifier|const
name|QList
operator|<
name|QVariant
operator|>
operator|&
name|args
argument_list|)
block|;
name|protected
operator|:
name|QDBusAbstractInterface
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|char
operator|*
name|interface
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|QDBusAbstractInterface
argument_list|(
name|QDBusAbstractInterfacePrivate
operator|&
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|void
name|connectNotify
argument_list|(
specifier|const
name|QMetaMethod
operator|&
name|signal
argument_list|)
block|;
name|void
name|disconnectNotify
argument_list|(
specifier|const
name|QMetaMethod
operator|&
name|signal
argument_list|)
block|;
name|QVariant
name|internalPropGet
argument_list|(
argument|const char *propname
argument_list|)
specifier|const
block|;
name|void
name|internalPropSet
argument_list|(
specifier|const
name|char
operator|*
name|propname
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
block|;
name|QDBusMessage
name|internalConstCall
argument_list|(
argument|QDBus::CallMode mode
argument_list|,
argument|const QString&method
argument_list|,
argument|const QList<QVariant>&args = QList<QVariant>()
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDBusAbstractInterface
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_serviceOwnerChanged(QString,QString,QString)
argument_list|)
block|}
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
