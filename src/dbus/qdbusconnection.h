begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSCONNECTION_H
end_ifndef
begin_define
DECL|macro|QDBUSCONNECTION_H
define|#
directive|define
name|QDBUSCONNECTION_H
end_define
begin_include
include|#
directive|include
file|<QtDBus/qdbusmacros.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|DBus
parameter_list|)
name|namespace
name|QDBus
decl_stmt|{     enum CallMode
block|{
name|NoBlock
operator|,
name|Block
operator|,
name|BlockWithGui
operator|,
name|AutoDetect
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
unit|}  class
DECL|variable|QDBusAbstractInterfacePrivate
name|QDBusAbstractInterfacePrivate
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QDBusInterface
name|class
name|QDBusInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusError
name|class
name|QDBusError
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusMessage
name|class
name|QDBusMessage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusPendingCall
name|class
name|QDBusPendingCall
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusConnectionInterface
name|class
name|QDBusConnectionInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusConnectionPrivate
name|class
name|QDBusConnectionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_DBUS_EXPORT
name|QDBusConnection
block|{
name|Q_GADGET
name|Q_ENUMS
argument_list|(
name|BusType
name|UnregisterMode
argument_list|)
name|Q_FLAGS
argument_list|(
name|RegisterOptions
argument_list|)
name|public
range|:     enum
name|BusType
block|{
name|SessionBus
block|,
name|SystemBus
block|,
name|ActivationBus
block|}
decl_stmt|;
enum|enum
name|RegisterOption
block|{
name|ExportAdaptors
init|=
literal|0x01
block|,
name|ExportScriptableSlots
init|=
literal|0x10
block|,
name|ExportScriptableSignals
init|=
literal|0x20
block|,
name|ExportScriptableProperties
init|=
literal|0x40
block|,
name|ExportScriptableInvokables
init|=
literal|0x80
block|,
name|ExportScriptableContents
init|=
literal|0xf0
block|,
name|ExportNonScriptableSlots
init|=
literal|0x100
block|,
name|ExportNonScriptableSignals
init|=
literal|0x200
block|,
name|ExportNonScriptableProperties
init|=
literal|0x400
block|,
name|ExportNonScriptableInvokables
init|=
literal|0x800
block|,
name|ExportNonScriptableContents
init|=
literal|0xf00
block|,
name|ExportAllSlots
init|=
name|ExportScriptableSlots
operator||
name|ExportNonScriptableSlots
block|,
name|ExportAllSignals
init|=
name|ExportScriptableSignals
operator||
name|ExportNonScriptableSignals
block|,
name|ExportAllProperties
init|=
name|ExportScriptableProperties
operator||
name|ExportNonScriptableProperties
block|,
name|ExportAllInvokables
init|=
name|ExportScriptableInvokables
operator||
name|ExportNonScriptableInvokables
block|,
name|ExportAllContents
init|=
name|ExportScriptableContents
operator||
name|ExportNonScriptableContents
block|,
ifndef|#
directive|ifndef
name|Q_QDOC
comment|// Qt 4.2 had a misspelling here
name|ExportAllSignal
init|=
name|ExportAllSignals
block|,
endif|#
directive|endif
name|ExportChildObjects
init|=
literal|0x1000
block|}
enum|;
enum|enum
name|UnregisterMode
block|{
name|UnregisterNode
block|,
name|UnregisterTree
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
name|RegisterOptions
argument_list|,
name|RegisterOption
argument_list|)
expr|enum
name|ConnectionCapability
block|{
name|UnixFileDescriptorPassing
operator|=
literal|0x0001
block|}
expr_stmt|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ConnectionCapabilities
argument_list|,
argument|ConnectionCapability
argument_list|)
name|QDBusConnection
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
expr_stmt|;
name|QDBusConnection
argument_list|(
specifier|const
name|QDBusConnection
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QDBusConnection
argument_list|()
expr_stmt|;
name|QDBusConnection
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDBusConnection
operator|&
name|other
operator|)
decl_stmt|;
name|bool
name|isConnected
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|baseService
argument_list|()
specifier|const
expr_stmt|;
name|QDBusError
name|lastError
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|ConnectionCapabilities
name|connectionCapabilities
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|send
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|)
decl|const
decl_stmt|;
name|bool
name|callWithCallback
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|returnMethod
argument_list|,
specifier|const
name|char
operator|*
name|errorMethod
argument_list|,
name|int
name|timeout
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
name|bool
name|callWithCallback
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|slot
argument_list|,
name|int
name|timeout
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
name|QDBusMessage
name|call
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
name|QDBus
operator|::
name|CallMode
name|mode
operator|=
name|QDBus
operator|::
name|Block
argument_list|,
name|int
name|timeout
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
name|QDBusPendingCall
name|asyncCall
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
name|int
name|timeout
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
name|bool
name|connect
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|slot
parameter_list|)
function_decl|;
name|bool
name|connect
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|signature
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|slot
parameter_list|)
function_decl|;
name|bool
name|connect
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|argumentMatch
parameter_list|,
specifier|const
name|QString
modifier|&
name|signature
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|slot
parameter_list|)
function_decl|;
name|bool
name|disconnect
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|slot
parameter_list|)
function_decl|;
name|bool
name|disconnect
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|signature
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|slot
parameter_list|)
function_decl|;
name|bool
name|disconnect
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|argumentMatch
parameter_list|,
specifier|const
name|QString
modifier|&
name|signature
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|slot
parameter_list|)
function_decl|;
name|bool
name|registerObject
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|QObject
modifier|*
name|object
parameter_list|,
name|RegisterOptions
name|options
init|=
name|ExportAdaptors
parameter_list|)
function_decl|;
name|void
name|unregisterObject
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|UnregisterMode
name|mode
init|=
name|UnregisterNode
parameter_list|)
function_decl|;
name|QObject
modifier|*
name|objectRegisteredAt
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
decl|const
decl_stmt|;
name|bool
name|registerService
parameter_list|(
specifier|const
name|QString
modifier|&
name|serviceName
parameter_list|)
function_decl|;
name|bool
name|unregisterService
parameter_list|(
specifier|const
name|QString
modifier|&
name|serviceName
parameter_list|)
function_decl|;
name|QDBusConnectionInterface
operator|*
name|interface
argument_list|()
specifier|const
expr_stmt|;
name|void
operator|*
name|internalPointer
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QDBusConnection
name|connectToBus
parameter_list|(
name|BusType
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
specifier|static
name|QDBusConnection
name|connectToBus
parameter_list|(
specifier|const
name|QString
modifier|&
name|address
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
specifier|static
name|QDBusConnection
name|connectToPeer
parameter_list|(
specifier|const
name|QString
modifier|&
name|address
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
specifier|static
name|void
name|disconnectFromBus
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
specifier|static
name|void
name|disconnectFromPeer
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
specifier|static
name|QDBusConnection
name|sessionBus
parameter_list|()
function_decl|;
specifier|static
name|QDBusConnection
name|systemBus
parameter_list|()
function_decl|;
specifier|static
name|QDBusConnection
name|sender
parameter_list|()
function_decl|;
name|protected
label|:
name|explicit
name|QDBusConnection
parameter_list|(
name|QDBusConnectionPrivate
modifier|*
name|dd
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|QDBusConnectionPrivate
decl_stmt|;
name|QDBusConnectionPrivate
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QDBusConnection::RegisterOptions
argument_list|)
end_macro
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
