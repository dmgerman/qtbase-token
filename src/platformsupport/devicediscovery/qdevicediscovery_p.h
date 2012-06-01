begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDEVICEDISCOVERY_H
end_ifndef
begin_define
DECL|macro|QDEVICEDISCOVERY_H
define|#
directive|define
name|QDEVICEDISCOVERY_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QSocketNotifier>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBUDEV
end_ifndef
begin_include
include|#
directive|include
file|<libudev.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_EVDEV_DEVICE_PATH
define|#
directive|define
name|QT_EVDEV_DEVICE_PATH
value|"/dev/input/"
end_define
begin_define
DECL|macro|QT_EVDEV_DEVICE_PREFIX
define|#
directive|define
name|QT_EVDEV_DEVICE_PREFIX
value|"event"
end_define
begin_define
DECL|macro|QT_EVDEV_DEVICE
define|#
directive|define
name|QT_EVDEV_DEVICE
value|QT_EVDEV_DEVICE_PATH QT_EVDEV_DEVICE_PREFIX
end_define
begin_define
DECL|macro|QT_DRM_DEVICE_PATH
define|#
directive|define
name|QT_DRM_DEVICE_PATH
value|"/dev/dri/"
end_define
begin_define
DECL|macro|QT_DRM_DEVICE_PREFIX
define|#
directive|define
name|QT_DRM_DEVICE_PREFIX
value|"card"
end_define
begin_define
DECL|macro|QT_DRM_DEVICE
define|#
directive|define
name|QT_DRM_DEVICE
value|QT_DRM_DEVICE_PATH QT_DRM_DEVICE_PREFIX
end_define
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QDeviceDiscovery
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|QDeviceType
argument_list|)
name|public
operator|:
expr|enum
name|QDeviceType
block|{
name|Device_Unknown
operator|=
literal|0x00
block|,
name|Device_Mouse
operator|=
literal|0x01
block|,
name|Device_Touchpad
operator|=
literal|0x02
block|,
name|Device_Touchscreen
operator|=
literal|0x04
block|,
name|Device_Keyboard
operator|=
literal|0x08
block|,
name|Device_DRM
operator|=
literal|0x10
block|,
name|Device_Tablet
operator|=
literal|0x20
block|,
name|Device_InputMask
operator|=
name|Device_Mouse
operator||
name|Device_Touchpad
operator||
name|Device_Touchscreen
operator||
name|Device_Keyboard
operator||
name|Device_Tablet
block|,
name|Device_VideoMask
operator|=
name|Device_DRM
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|QDeviceTypes
argument_list|,
argument|QDeviceType
argument_list|)
specifier|static
name|QDeviceDiscovery
operator|*
name|create
argument_list|(
argument|QDeviceTypes type
argument_list|,
argument|QObject *parent
argument_list|)
block|;
operator|~
name|QDeviceDiscovery
argument_list|()
block|;
name|QStringList
name|scanConnectedDevices
argument_list|()
block|;
name|signals
operator|:
name|void
name|deviceDetected
argument_list|(
specifier|const
name|QString
operator|&
name|deviceNode
argument_list|)
block|;
name|void
name|deviceRemoved
argument_list|(
specifier|const
name|QString
operator|&
name|deviceNode
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_LIBUDEV
name|private
name|slots
operator|:
name|void
name|handleUDevNotification
argument_list|()
block|;
endif|#
directive|endif
name|private
operator|:
ifndef|#
directive|ifndef
name|QT_NO_LIBUDEV
name|QDeviceDiscovery
argument_list|(
argument|QDeviceTypes types
argument_list|,
argument|struct udev *udev
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
name|bool
name|checkDeviceType
argument_list|(
expr|struct
name|udev_device
operator|*
name|dev
argument_list|)
block|;
else|#
directive|else
name|QDeviceDiscovery
argument_list|(
argument|QDeviceTypes types
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
name|bool
name|checkDeviceType
argument_list|(
specifier|const
name|QString
operator|&
name|device
argument_list|)
block|;
endif|#
directive|endif
name|QDeviceTypes
name|m_types
block|;
ifndef|#
directive|ifndef
name|QT_NO_LIBUDEV
name|void
name|startWatching
argument_list|()
block|;
name|void
name|stopWatching
argument_list|()
block|;      struct
name|udev
operator|*
name|m_udev
block|;     struct
name|udev_monitor
operator|*
name|m_udevMonitor
block|;
name|int
name|m_udevMonitorFileDescriptor
block|;
name|QSocketNotifier
operator|*
name|m_udevSocketNotifier
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QDeviceDiscovery::QDeviceTypes
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDEVICEDISCOVERY_H
end_comment
end_unit
