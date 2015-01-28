begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"struct_marshallers_p.h"
end_include
begin_include
include|#
directive|include
file|<atspi/atspi-constants.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusmetatype.h>
end_include
begin_include
include|#
directive|include
file|"bridge_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QSpiObjectReference
name|QSpiObjectReference
operator|::
name|QSpiObjectReference
parameter_list|()
member_init_list|:
name|path
argument_list|(
name|QDBusObjectPath
argument_list|(
name|ATSPI_DBUS_PATH_NULL
argument_list|)
argument_list|)
block|{}
end_constructor
begin_comment
comment|/* QSpiAccessibleCacheArray */
end_comment
begin_comment
comment|/*---------------------------------------------------------------------------*/
end_comment
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|QSpiAccessibleCacheItem
modifier|&
name|item
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|item
operator|.
name|path
expr_stmt|;
name|argument
operator|<<
name|item
operator|.
name|application
expr_stmt|;
name|argument
operator|<<
name|item
operator|.
name|parent
expr_stmt|;
name|argument
operator|<<
name|item
operator|.
name|children
expr_stmt|;
name|argument
operator|<<
name|item
operator|.
name|supportedInterfaces
expr_stmt|;
name|argument
operator|<<
name|item
operator|.
name|name
expr_stmt|;
name|argument
operator|<<
name|item
operator|.
name|role
expr_stmt|;
name|argument
operator|<<
name|item
operator|.
name|description
expr_stmt|;
name|argument
operator|<<
name|item
operator|.
name|state
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|QSpiAccessibleCacheItem
modifier|&
name|item
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
name|item
operator|.
name|path
expr_stmt|;
name|argument
operator|>>
name|item
operator|.
name|application
expr_stmt|;
name|argument
operator|>>
name|item
operator|.
name|parent
expr_stmt|;
name|argument
operator|>>
name|item
operator|.
name|children
expr_stmt|;
name|argument
operator|>>
name|item
operator|.
name|supportedInterfaces
expr_stmt|;
name|argument
operator|>>
name|item
operator|.
name|name
expr_stmt|;
name|argument
operator|>>
name|item
operator|.
name|role
expr_stmt|;
name|argument
operator|>>
name|item
operator|.
name|description
expr_stmt|;
name|argument
operator|>>
name|item
operator|.
name|state
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|/* QSpiObjectReference */
end_comment
begin_comment
comment|/*---------------------------------------------------------------------------*/
end_comment
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|QSpiObjectReference
modifier|&
name|address
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|address
operator|.
name|service
expr_stmt|;
name|argument
operator|<<
name|address
operator|.
name|path
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|QSpiObjectReference
modifier|&
name|address
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
name|address
operator|.
name|service
expr_stmt|;
name|argument
operator|>>
name|address
operator|.
name|path
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|/* QSpiAction */
end_comment
begin_comment
comment|/*---------------------------------------------------------------------------*/
end_comment
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|QSpiAction
modifier|&
name|action
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|action
operator|.
name|name
expr_stmt|;
name|argument
operator|<<
name|action
operator|.
name|description
expr_stmt|;
name|argument
operator|<<
name|action
operator|.
name|keyBinding
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|QSpiAction
modifier|&
name|action
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
name|action
operator|.
name|name
expr_stmt|;
name|argument
operator|>>
name|action
operator|.
name|description
expr_stmt|;
name|argument
operator|>>
name|action
operator|.
name|keyBinding
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|QSpiEventListener
modifier|&
name|ev
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|ev
operator|.
name|listenerAddress
expr_stmt|;
name|argument
operator|<<
name|ev
operator|.
name|eventName
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|QSpiEventListener
modifier|&
name|ev
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
name|ev
operator|.
name|listenerAddress
expr_stmt|;
name|argument
operator|>>
name|ev
operator|.
name|eventName
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|/* QSpiAppUpdate */
end_comment
begin_comment
comment|/*---------------------------------------------------------------------------*/
end_comment
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|QSpiAppUpdate
modifier|&
name|update
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|update
operator|.
name|type
operator|<<
name|update
operator|.
name|address
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|QSpiAppUpdate
modifier|&
name|update
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
name|update
operator|.
name|type
operator|>>
name|update
operator|.
name|address
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|/* QSpiRelationArrayEntry */
end_comment
begin_comment
comment|/*---------------------------------------------------------------------------*/
end_comment
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|QSpiRelationArrayEntry
modifier|&
name|entry
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|entry
operator|.
name|first
operator|<<
name|entry
operator|.
name|second
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|QSpiRelationArrayEntry
modifier|&
name|entry
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
name|entry
operator|.
name|first
operator|>>
name|entry
operator|.
name|second
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|/* QSpiDeviceEvent */
end_comment
begin_comment
comment|/*---------------------------------------------------------------------------*/
end_comment
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|QSpiDeviceEvent
modifier|&
name|event
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|event
operator|.
name|type
operator|<<
name|event
operator|.
name|id
operator|<<
name|event
operator|.
name|hardwareCode
operator|<<
name|event
operator|.
name|modifiers
operator|<<
name|event
operator|.
name|timestamp
operator|<<
name|event
operator|.
name|text
operator|<<
name|event
operator|.
name|isText
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|QSpiDeviceEvent
modifier|&
name|event
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
name|event
operator|.
name|type
operator|>>
name|event
operator|.
name|id
operator|>>
name|event
operator|.
name|hardwareCode
operator|>>
name|event
operator|.
name|modifiers
operator|>>
name|event
operator|.
name|timestamp
operator|>>
name|event
operator|.
name|text
operator|>>
name|event
operator|.
name|isText
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_function
DECL|function|qSpiInitializeStructTypes
name|void
name|qSpiInitializeStructTypes
parameter_list|()
block|{
name|qDBusRegisterMetaType
argument_list|<
name|QSpiIntList
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiUIntList
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiAccessibleCacheItem
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiAccessibleCacheArray
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiObjectReference
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiObjectReferenceArray
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiAttributeSet
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiAction
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiActionArray
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiEventListener
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiEventListenerArray
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiDeviceEvent
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiAppUpdate
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiRelationArrayEntry
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QSpiRelationArray
argument_list|>
argument_list|()
expr_stmt|;
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
comment|//QT_NO_ACCESSIBILITY
end_comment
end_unit
