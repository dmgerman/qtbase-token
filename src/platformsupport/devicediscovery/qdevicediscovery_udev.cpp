begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdevicediscovery_p.h"
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<linux/input.h>
end_include
begin_comment
comment|//#define QT_QPA_DEVICE_DISCOVERY_DEBUG
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_QPA_DEVICE_DISCOVERY_DEBUG
end_ifdef
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|create
name|QDeviceDiscovery
modifier|*
name|QDeviceDiscovery
operator|::
name|create
parameter_list|(
name|QDeviceTypes
name|types
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_DEVICE_DISCOVERY_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Try to create new UDeviceHelper"
expr_stmt|;
endif|#
directive|endif
name|QDeviceDiscovery
modifier|*
name|helper
init|=
literal|0
decl_stmt|;
name|struct
name|udev
modifier|*
name|udev
decl_stmt|;
name|udev
operator|=
name|udev_new
argument_list|()
expr_stmt|;
if|if
condition|(
name|udev
condition|)
block|{
name|helper
operator|=
operator|new
name|QDeviceDiscovery
argument_list|(
name|types
argument_list|,
name|udev
argument_list|,
name|parent
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"Failed to get udev library context."
argument_list|)
expr_stmt|;
block|}
return|return
name|helper
return|;
block|}
end_function
begin_constructor
DECL|function|QDeviceDiscovery
name|QDeviceDiscovery
operator|::
name|QDeviceDiscovery
parameter_list|(
name|QDeviceTypes
name|types
parameter_list|,
name|struct
name|udev
modifier|*
name|udev
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_types
argument_list|(
name|types
argument_list|)
member_init_list|,
name|m_udev
argument_list|(
name|udev
argument_list|)
member_init_list|,
name|m_udevMonitor
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_udevMonitorFileDescriptor
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|m_udevSocketNotifier
argument_list|(
literal|0
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_DEVICE_DISCOVERY_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"New UDeviceHelper created for type"
operator|<<
name|types
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|m_udev
condition|)
return|return;
name|m_udevMonitor
operator|=
name|udev_monitor_new_from_netlink
argument_list|(
name|m_udev
argument_list|,
literal|"udev"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_udevMonitor
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_DEVICE_DISCOVERY_DEBUG
name|qWarning
argument_list|(
literal|"Unable to create an Udev monitor. No devices can be detected."
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
name|udev_monitor_filter_add_match_subsystem_devtype
argument_list|(
name|m_udevMonitor
argument_list|,
literal|"input"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|udev_monitor_filter_add_match_subsystem_devtype
argument_list|(
name|m_udevMonitor
argument_list|,
literal|"drm"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|udev_monitor_enable_receiving
argument_list|(
name|m_udevMonitor
argument_list|)
expr_stmt|;
name|m_udevMonitorFileDescriptor
operator|=
name|udev_monitor_get_fd
argument_list|(
name|m_udevMonitor
argument_list|)
expr_stmt|;
name|m_udevSocketNotifier
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|m_udevMonitorFileDescriptor
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_udevSocketNotifier
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|handleUDevNotification
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QDeviceDiscovery
name|QDeviceDiscovery
operator|::
name|~
name|QDeviceDiscovery
parameter_list|()
block|{
if|if
condition|(
name|m_udevMonitor
condition|)
name|udev_monitor_unref
argument_list|(
name|m_udevMonitor
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_udev
condition|)
name|udev_unref
argument_list|(
name|m_udev
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|scanConnectedDevices
name|QStringList
name|QDeviceDiscovery
operator|::
name|scanConnectedDevices
parameter_list|()
block|{
name|QStringList
name|devices
decl_stmt|;
if|if
condition|(
operator|!
name|m_udev
condition|)
return|return
name|devices
return|;
name|udev_enumerate
modifier|*
name|ue
init|=
name|udev_enumerate_new
argument_list|(
name|m_udev
argument_list|)
decl_stmt|;
name|udev_enumerate_add_match_subsystem
argument_list|(
name|ue
argument_list|,
literal|"input"
argument_list|)
expr_stmt|;
name|udev_enumerate_add_match_subsystem
argument_list|(
name|ue
argument_list|,
literal|"drm"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_types
operator|&
name|Device_Mouse
condition|)
name|udev_enumerate_add_match_property
argument_list|(
name|ue
argument_list|,
literal|"ID_INPUT_MOUSE"
argument_list|,
literal|"1"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_types
operator|&
name|Device_Touchpad
condition|)
name|udev_enumerate_add_match_property
argument_list|(
name|ue
argument_list|,
literal|"ID_INPUT_TOUCHPAD"
argument_list|,
literal|"1"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_types
operator|&
name|Device_Touchscreen
condition|)
name|udev_enumerate_add_match_property
argument_list|(
name|ue
argument_list|,
literal|"ID_INPUT_TOUCHSCREEN"
argument_list|,
literal|"1"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_types
operator|&
name|Device_Keyboard
condition|)
name|udev_enumerate_add_match_property
argument_list|(
name|ue
argument_list|,
literal|"ID_INPUT_KEYBOARD"
argument_list|,
literal|"1"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_types
operator|&
name|Device_Tablet
condition|)
name|udev_enumerate_add_match_property
argument_list|(
name|ue
argument_list|,
literal|"ID_INPUT_TABLET"
argument_list|,
literal|"1"
argument_list|)
expr_stmt|;
if|if
condition|(
name|udev_enumerate_scan_devices
argument_list|(
name|ue
argument_list|)
operator|!=
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_DEVICE_DISCOVERY_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"UDeviceHelper scan connected devices for enumeration failed"
expr_stmt|;
endif|#
directive|endif
return|return
name|devices
return|;
block|}
name|udev_list_entry
modifier|*
name|entry
decl_stmt|;
name|udev_list_entry_foreach
argument_list|(
argument|entry
argument_list|,
argument|udev_enumerate_get_list_entry(ue)
argument_list|)
block|{
specifier|const
name|char
modifier|*
name|syspath
init|=
name|udev_list_entry_get_name
argument_list|(
name|entry
argument_list|)
decl_stmt|;
name|udev_device
modifier|*
name|udevice
init|=
name|udev_device_new_from_syspath
argument_list|(
name|m_udev
argument_list|,
name|syspath
argument_list|)
decl_stmt|;
name|QString
name|candidate
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|udev_device_get_devnode
argument_list|(
name|udevice
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|m_types
operator|&
name|Device_InputMask
operator|)
operator|&&
name|candidate
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
name|QT_EVDEV_DEVICE
argument_list|)
argument_list|)
condition|)
name|devices
operator|<<
name|candidate
expr_stmt|;
if|if
condition|(
operator|(
name|m_types
operator|&
name|Device_VideoMask
operator|)
operator|&&
name|candidate
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
name|QT_DRM_DEVICE
argument_list|)
argument_list|)
condition|)
name|devices
operator|<<
name|candidate
expr_stmt|;
name|udev_device_unref
argument_list|(
name|udevice
argument_list|)
expr_stmt|;
block|}
name|udev_enumerate_unref
argument_list|(
name|ue
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_QPA_DEVICE_DISCOVERY_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"UDeviceHelper found matching devices"
operator|<<
name|devices
expr_stmt|;
endif|#
directive|endif
return|return
name|devices
return|;
block|}
end_function
begin_function
DECL|function|handleUDevNotification
name|void
name|QDeviceDiscovery
operator|::
name|handleUDevNotification
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_udevMonitor
condition|)
return|return;
name|struct
name|udev_device
modifier|*
name|dev
decl_stmt|;
name|QString
name|devNode
decl_stmt|;
name|dev
operator|=
name|udev_monitor_receive_device
argument_list|(
name|m_udevMonitor
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dev
condition|)
goto|goto
name|cleanup
goto|;
specifier|const
name|char
modifier|*
name|action
decl_stmt|;
name|action
operator|=
name|udev_device_get_action
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|action
condition|)
goto|goto
name|cleanup
goto|;
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
name|str
operator|=
name|udev_device_get_devnode
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|str
condition|)
goto|goto
name|cleanup
goto|;
specifier|const
name|char
modifier|*
name|subsystem
decl_stmt|;
name|devNode
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|str
argument_list|)
expr_stmt|;
if|if
condition|(
name|devNode
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
name|QT_EVDEV_DEVICE
argument_list|)
argument_list|)
condition|)
name|subsystem
operator|=
literal|"input"
expr_stmt|;
elseif|else
if|if
condition|(
name|devNode
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
name|QT_DRM_DEVICE
argument_list|)
argument_list|)
condition|)
name|subsystem
operator|=
literal|"drm"
expr_stmt|;
else|else
goto|goto
name|cleanup
goto|;
comment|// if we cannot determine a type, walk up the device tree
if|if
condition|(
operator|!
name|checkDeviceType
argument_list|(
name|dev
argument_list|)
condition|)
block|{
comment|// does not increase the refcount
name|dev
operator|=
name|udev_device_get_parent_with_subsystem_devtype
argument_list|(
name|dev
argument_list|,
name|subsystem
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dev
condition|)
goto|goto
name|cleanup
goto|;
if|if
condition|(
operator|!
name|checkDeviceType
argument_list|(
name|dev
argument_list|)
condition|)
goto|goto
name|cleanup
goto|;
block|}
if|if
condition|(
name|qstrcmp
argument_list|(
name|action
argument_list|,
literal|"add"
argument_list|)
operator|==
literal|0
condition|)
emit|emit
name|deviceDetected
argument_list|(
name|devNode
argument_list|)
emit|;
if|if
condition|(
name|qstrcmp
argument_list|(
name|action
argument_list|,
literal|"remove"
argument_list|)
operator|==
literal|0
condition|)
emit|emit
name|deviceRemoved
argument_list|(
name|devNode
argument_list|)
emit|;
name|cleanup
label|:
name|udev_device_unref
argument_list|(
name|dev
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkDeviceType
name|bool
name|QDeviceDiscovery
operator|::
name|checkDeviceType
parameter_list|(
name|udev_device
modifier|*
name|dev
parameter_list|)
block|{
if|if
condition|(
operator|!
name|dev
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|m_types
operator|&
name|Device_Keyboard
operator|)
operator|&&
operator|(
name|qstrcmp
argument_list|(
name|udev_device_get_property_value
argument_list|(
name|dev
argument_list|,
literal|"ID_INPUT_KEYBOARD"
argument_list|)
argument_list|,
literal|"1"
argument_list|)
operator|==
literal|0
operator|)
condition|)
block|{
specifier|const
name|char
modifier|*
name|capabilities_key
init|=
name|udev_device_get_sysattr_value
argument_list|(
name|dev
argument_list|,
literal|"capabilities/key"
argument_list|)
decl_stmt|;
name|QStringList
name|val
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|capabilities_key
argument_list|)
operator|.
name|split
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|" "
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|val
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|bool
name|ok
decl_stmt|;
name|unsigned
name|long
name|long
name|keys
init|=
name|val
operator|.
name|last
argument_list|()
operator|.
name|toULongLong
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
block|{
comment|// Tests if the letter Q is valid for the device.  We may want to alter this test, but it seems mostly reliable.
name|bool
name|test
init|=
operator|(
name|keys
operator|>>
name|KEY_Q
operator|)
operator|&
literal|1
decl_stmt|;
if|if
condition|(
name|test
condition|)
return|return
literal|true
return|;
block|}
block|}
block|}
if|if
condition|(
operator|(
name|m_types
operator|&
name|Device_Mouse
operator|)
operator|&&
operator|(
name|qstrcmp
argument_list|(
name|udev_device_get_property_value
argument_list|(
name|dev
argument_list|,
literal|"ID_INPUT_MOUSE"
argument_list|)
argument_list|,
literal|"1"
argument_list|)
operator|==
literal|0
operator|)
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|(
name|m_types
operator|&
name|Device_Touchpad
operator|)
operator|&&
operator|(
name|qstrcmp
argument_list|(
name|udev_device_get_property_value
argument_list|(
name|dev
argument_list|,
literal|"ID_INPUT_TOUCHPAD"
argument_list|)
argument_list|,
literal|"1"
argument_list|)
operator|==
literal|0
operator|)
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|(
name|m_types
operator|&
name|Device_Touchscreen
operator|)
operator|&&
operator|(
name|qstrcmp
argument_list|(
name|udev_device_get_property_value
argument_list|(
name|dev
argument_list|,
literal|"ID_INPUT_TOUCHSCREEN"
argument_list|)
argument_list|,
literal|"1"
argument_list|)
operator|==
literal|0
operator|)
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|(
name|m_types
operator|&
name|Device_Tablet
operator|)
operator|&&
operator|(
name|qstrcmp
argument_list|(
name|udev_device_get_property_value
argument_list|(
name|dev
argument_list|,
literal|"ID_INPUT_TABLET"
argument_list|)
argument_list|,
literal|"1"
argument_list|)
operator|==
literal|0
operator|)
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|(
name|m_types
operator|&
name|Device_DRM
operator|)
operator|&&
operator|(
name|qstrcmp
argument_list|(
name|udev_device_get_subsystem
argument_list|(
name|dev
argument_list|)
argument_list|,
literal|"drm"
argument_list|)
operator|==
literal|0
operator|)
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
