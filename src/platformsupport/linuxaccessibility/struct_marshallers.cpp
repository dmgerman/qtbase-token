begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|Q_UNUSED
argument_list|(
argument|action
argument_list|)
name|qWarning
argument_list|()
operator|<<
literal|"QDBusArgument&operator>>(const QDBusArgument&argument, QSpiAction&action): implement me!"
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
end_unit
