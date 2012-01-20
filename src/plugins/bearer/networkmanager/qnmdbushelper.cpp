begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// this class is for helping qdbus get stuff
end_comment
begin_include
include|#
directive|include
file|"qnmdbushelper.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkmanagerservice.h"
end_include
begin_include
include|#
directive|include
file|<QDBusError>
end_include
begin_include
include|#
directive|include
file|<QDBusInterface>
end_include
begin_include
include|#
directive|include
file|<QDBusMessage>
end_include
begin_include
include|#
directive|include
file|<QDBusReply>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QNmDBusHelper
name|QNmDBusHelper
operator|::
name|QNmDBusHelper
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QNmDBusHelper
name|QNmDBusHelper
operator|::
name|~
name|QNmDBusHelper
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|deviceStateChanged
name|void
name|QNmDBusHelper
operator|::
name|deviceStateChanged
parameter_list|(
name|quint32
name|state
parameter_list|)
block|{
name|QDBusMessage
name|msg
init|=
name|this
operator|->
name|message
argument_list|()
decl_stmt|;
if|if
condition|(
name|state
operator|==
name|NM_DEVICE_STATE_ACTIVATED
operator|||
name|state
operator|==
name|NM_DEVICE_STATE_DISCONNECTED
operator|||
name|state
operator|==
name|NM_DEVICE_STATE_UNAVAILABLE
operator|||
name|state
operator|==
name|NM_DEVICE_STATE_FAILED
condition|)
block|{
emit|emit
name|pathForStateChanged
argument_list|(
name|msg
operator|.
name|path
argument_list|()
argument_list|,
name|state
argument_list|)
emit|;
block|}
block|}
end_function
begin_function
DECL|function|slotAccessPointAdded
name|void
name|QNmDBusHelper
operator|::
name|slotAccessPointAdded
parameter_list|(
name|QDBusObjectPath
name|path
parameter_list|)
block|{
if|if
condition|(
name|path
operator|.
name|path
argument_list|()
operator|.
name|length
argument_list|()
operator|>
literal|2
condition|)
block|{
name|QDBusMessage
name|msg
init|=
name|this
operator|->
name|message
argument_list|()
decl_stmt|;
emit|emit
name|pathForAccessPointAdded
argument_list|(
name|msg
operator|.
name|path
argument_list|()
argument_list|,
name|path
argument_list|)
emit|;
block|}
block|}
end_function
begin_function
DECL|function|slotAccessPointRemoved
name|void
name|QNmDBusHelper
operator|::
name|slotAccessPointRemoved
parameter_list|(
name|QDBusObjectPath
name|path
parameter_list|)
block|{
if|if
condition|(
name|path
operator|.
name|path
argument_list|()
operator|.
name|length
argument_list|()
operator|>
literal|2
condition|)
block|{
name|QDBusMessage
name|msg
init|=
name|this
operator|->
name|message
argument_list|()
decl_stmt|;
emit|emit
name|pathForAccessPointRemoved
argument_list|(
name|msg
operator|.
name|path
argument_list|()
argument_list|,
name|path
argument_list|)
emit|;
block|}
block|}
end_function
begin_function
DECL|function|slotPropertiesChanged
name|void
name|QNmDBusHelper
operator|::
name|slotPropertiesChanged
parameter_list|(
name|QMap
argument_list|<
name|QString
argument_list|,
name|QVariant
argument_list|>
name|map
parameter_list|)
block|{
name|QDBusMessage
name|msg
init|=
name|this
operator|->
name|message
argument_list|()
decl_stmt|;
name|QMapIterator
argument_list|<
name|QString
argument_list|,
name|QVariant
argument_list|>
name|i
argument_list|(
name|map
argument_list|)
decl_stmt|;
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|i
operator|.
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|i
operator|.
name|key
argument_list|()
operator|==
literal|"State"
condition|)
block|{
comment|//state only applies to device interfaces
name|quint32
name|state
init|=
name|i
operator|.
name|value
argument_list|()
operator|.
name|toUInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|state
operator|==
name|NM_DEVICE_STATE_ACTIVATED
operator|||
name|state
operator|==
name|NM_DEVICE_STATE_DISCONNECTED
operator|||
name|state
operator|==
name|NM_DEVICE_STATE_UNAVAILABLE
operator|||
name|state
operator|==
name|NM_DEVICE_STATE_FAILED
condition|)
block|{
emit|emit
name|pathForPropertiesChanged
argument_list|(
name|msg
operator|.
name|path
argument_list|()
argument_list|,
name|map
argument_list|)
emit|;
block|}
block|}
elseif|else
if|if
condition|(
name|i
operator|.
name|key
argument_list|()
operator|==
literal|"ActiveAccessPoint"
condition|)
block|{
emit|emit
name|pathForPropertiesChanged
argument_list|(
name|msg
operator|.
name|path
argument_list|()
argument_list|,
name|map
argument_list|)
emit|;
comment|//            qWarning()<< __PRETTY_FUNCTION__<< i.key()<< ": "<< i.value().value<QDBusObjectPath>().path();
comment|//      } else if( i.key() == "Strength")
comment|//            qWarning()<< __PRETTY_FUNCTION__<< i.key()<< ": "<< i.value().toUInt();
comment|//   else
comment|//            qWarning()<< __PRETTY_FUNCTION__<< i.key()<< ": "<< i.value();
block|}
elseif|else
if|if
condition|(
name|i
operator|.
name|key
argument_list|()
operator|==
literal|"ActiveConnections"
condition|)
block|{
emit|emit
name|pathForPropertiesChanged
argument_list|(
name|msg
operator|.
name|path
argument_list|()
argument_list|,
name|map
argument_list|)
emit|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|slotSettingsRemoved
name|void
name|QNmDBusHelper
operator|::
name|slotSettingsRemoved
parameter_list|()
block|{
name|QDBusMessage
name|msg
init|=
name|this
operator|->
name|message
argument_list|()
decl_stmt|;
emit|emit
name|pathForSettingsRemoved
argument_list|(
name|msg
operator|.
name|path
argument_list|()
argument_list|)
emit|;
block|}
end_function
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
end_unit
