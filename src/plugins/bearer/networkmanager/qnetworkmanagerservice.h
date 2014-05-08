begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKMANAGERSERVICE_H
end_ifndef
begin_define
DECL|macro|QNETWORKMANAGERSERVICE_H
define|#
directive|define
name|QNETWORKMANAGERSERVICE_H
end_define
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusConnection>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusError>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusInterface>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusMessage>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusReply>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusPendingCallWatcher>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusObjectPath>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusContext>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|"qnmdbushelper.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|NETWORK_MANAGER_H
end_ifndef
begin_typedef
DECL|enum|NMDeviceType
typedef|typedef
enum|enum
name|NMDeviceType
block|{
DECL|enumerator|DEVICE_TYPE_UNKNOWN
name|DEVICE_TYPE_UNKNOWN
init|=
literal|0
block|,
DECL|enumerator|DEVICE_TYPE_802_3_ETHERNET
name|DEVICE_TYPE_802_3_ETHERNET
block|,
DECL|enumerator|DEVICE_TYPE_802_11_WIRELESS
name|DEVICE_TYPE_802_11_WIRELESS
block|,
DECL|enumerator|DEVICE_TYPE_GSM
name|DEVICE_TYPE_GSM
block|,
DECL|enumerator|DEVICE_TYPE_CDMA
name|DEVICE_TYPE_CDMA
block|}
DECL|typedef|NMDeviceType
name|NMDeviceType
typedef|;
end_typedef
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|NM_DEVICE_STATE_UNKNOWN
name|NM_DEVICE_STATE_UNKNOWN
init|=
literal|0
block|,
DECL|enumerator|NM_DEVICE_STATE_UNMANAGED
name|NM_DEVICE_STATE_UNMANAGED
block|,
DECL|enumerator|NM_DEVICE_STATE_UNAVAILABLE
name|NM_DEVICE_STATE_UNAVAILABLE
block|,
DECL|enumerator|NM_DEVICE_STATE_DISCONNECTED
name|NM_DEVICE_STATE_DISCONNECTED
block|,
DECL|enumerator|NM_DEVICE_STATE_PREPARE
name|NM_DEVICE_STATE_PREPARE
block|,
DECL|enumerator|NM_DEVICE_STATE_CONFIG
name|NM_DEVICE_STATE_CONFIG
block|,
DECL|enumerator|NM_DEVICE_STATE_NEED_AUTH
name|NM_DEVICE_STATE_NEED_AUTH
block|,
DECL|enumerator|NM_DEVICE_STATE_IP_CONFIG
name|NM_DEVICE_STATE_IP_CONFIG
block|,
DECL|enumerator|NM_DEVICE_STATE_ACTIVATED
name|NM_DEVICE_STATE_ACTIVATED
block|,
DECL|enumerator|NM_DEVICE_STATE_FAILED
name|NM_DEVICE_STATE_FAILED
block|}
DECL|typedef|NMDeviceState
name|NMDeviceState
typedef|;
end_typedef
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|NM_ACTIVE_CONNECTION_STATE_UNKNOWN
name|NM_ACTIVE_CONNECTION_STATE_UNKNOWN
init|=
literal|0
block|,
DECL|enumerator|NM_ACTIVE_CONNECTION_STATE_ACTIVATING
name|NM_ACTIVE_CONNECTION_STATE_ACTIVATING
block|,
DECL|enumerator|NM_ACTIVE_CONNECTION_STATE_ACTIVATED
name|NM_ACTIVE_CONNECTION_STATE_ACTIVATED
block|}
DECL|typedef|NMActiveConnectionState
name|NMActiveConnectionState
typedef|;
end_typedef
begin_define
DECL|macro|NM_DBUS_SERVICE
define|#
directive|define
name|NM_DBUS_SERVICE
value|"org.freedesktop.NetworkManager"
end_define
begin_define
DECL|macro|NM_DBUS_PATH
define|#
directive|define
name|NM_DBUS_PATH
value|"/org/freedesktop/NetworkManager"
end_define
begin_define
DECL|macro|NM_DBUS_INTERFACE
define|#
directive|define
name|NM_DBUS_INTERFACE
value|"org.freedesktop.NetworkManager"
end_define
begin_define
DECL|macro|NM_DBUS_INTERFACE_DEVICE
define|#
directive|define
name|NM_DBUS_INTERFACE_DEVICE
value|NM_DBUS_INTERFACE ".Device"
end_define
begin_define
DECL|macro|NM_DBUS_INTERFACE_DEVICE_WIRED
define|#
directive|define
name|NM_DBUS_INTERFACE_DEVICE_WIRED
value|NM_DBUS_INTERFACE_DEVICE ".Wired"
end_define
begin_define
DECL|macro|NM_DBUS_INTERFACE_DEVICE_WIRELESS
define|#
directive|define
name|NM_DBUS_INTERFACE_DEVICE_WIRELESS
value|NM_DBUS_INTERFACE_DEVICE ".Wireless"
end_define
begin_define
DECL|macro|NM_DBUS_PATH_ACCESS_POINT
define|#
directive|define
name|NM_DBUS_PATH_ACCESS_POINT
value|NM_DBUS_PATH "/AccessPoint"
end_define
begin_define
DECL|macro|NM_DBUS_INTERFACE_ACCESS_POINT
define|#
directive|define
name|NM_DBUS_INTERFACE_ACCESS_POINT
value|NM_DBUS_INTERFACE ".AccessPoint"
end_define
begin_define
DECL|macro|NM_DBUS_PATH_SETTINGS
define|#
directive|define
name|NM_DBUS_PATH_SETTINGS
value|"/org/freedesktop/NetworkManagerSettings"
end_define
begin_define
DECL|macro|NM_DBUS_IFACE_SETTINGS_CONNECTION
define|#
directive|define
name|NM_DBUS_IFACE_SETTINGS_CONNECTION
value|"org.freedesktop.NetworkManagerSettings.Connection"
end_define
begin_define
DECL|macro|NM_DBUS_IFACE_SETTINGS
define|#
directive|define
name|NM_DBUS_IFACE_SETTINGS
value|"org.freedesktop.NetworkManagerSettings"
end_define
begin_define
DECL|macro|NM_DBUS_INTERFACE_ACTIVE_CONNECTION
define|#
directive|define
name|NM_DBUS_INTERFACE_ACTIVE_CONNECTION
value|NM_DBUS_INTERFACE ".Connection.Active"
end_define
begin_define
DECL|macro|NM_DBUS_INTERFACE_IP4_CONFIG
define|#
directive|define
name|NM_DBUS_INTERFACE_IP4_CONFIG
value|NM_DBUS_INTERFACE ".IP4Config"
end_define
begin_define
DECL|macro|NM_DBUS_SERVICE_USER_SETTINGS
define|#
directive|define
name|NM_DBUS_SERVICE_USER_SETTINGS
value|"org.freedesktop.NetworkManagerUserSettings"
end_define
begin_define
DECL|macro|NM_DBUS_SERVICE_SYSTEM_SETTINGS
define|#
directive|define
name|NM_DBUS_SERVICE_SYSTEM_SETTINGS
value|"org.freedesktop.NetworkManagerSystemSettings"
end_define
begin_define
DECL|macro|NM_802_11_AP_FLAGS_NONE
define|#
directive|define
name|NM_802_11_AP_FLAGS_NONE
value|0x00000000
end_define
begin_define
DECL|macro|NM_802_11_AP_FLAGS_PRIVACY
define|#
directive|define
name|NM_802_11_AP_FLAGS_PRIVACY
value|0x00000001
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|QString
DECL|typedef|QString
DECL|typedef|QNmSettingsMap
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QMap
operator|<
name|QString
operator|,
name|QVariant
operator|>
expr|>
name|QNmSettingsMap
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|ServerThing
typedef|typedef
name|QList
operator|<
name|quint32
operator|>
name|ServerThing
expr_stmt|;
end_typedef
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QT_PREPEND_NAMESPACE
argument_list|(
name|QNmSettingsMap
argument_list|)
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QT_PREPEND_NAMESPACE
argument_list|(
name|ServerThing
argument_list|)
argument_list|)
name|QT_BEGIN_NAMESPACE
name|class
name|QNetworkManagerInterfacePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkManagerInterface
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QNetworkManagerInterface
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNetworkManagerInterface
argument_list|()
block|;
name|QList
operator|<
name|QDBusObjectPath
operator|>
name|getDevices
argument_list|()
specifier|const
block|;
name|void
name|activateConnection
argument_list|(
argument|const QString&serviceName
argument_list|,
argument|QDBusObjectPath connection
argument_list|,
argument|QDBusObjectPath device
argument_list|,
argument|QDBusObjectPath specificObject
argument_list|)
block|;
name|void
name|deactivateConnection
argument_list|(
argument|QDBusObjectPath connectionPath
argument_list|)
specifier|const
block|;
name|QDBusObjectPath
name|path
argument_list|()
specifier|const
block|;
name|QDBusInterface
operator|*
name|connectionInterface
argument_list|()
specifier|const
block|;
name|bool
name|wirelessEnabled
argument_list|()
specifier|const
block|;
name|bool
name|wirelessHardwareEnabled
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QDBusObjectPath
operator|>
name|activeConnections
argument_list|()
specifier|const
block|;
name|quint32
name|state
argument_list|()
block|;
name|bool
name|setConnections
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|deviceAdded
argument_list|(
name|QDBusObjectPath
argument_list|)
block|;
name|void
name|deviceRemoved
argument_list|(
name|QDBusObjectPath
argument_list|)
block|;
name|void
name|propertiesChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|QMap
operator|<
name|QString
argument_list|,
name|QVariant
operator|>
argument_list|)
block|;
name|void
name|stateChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|quint32
argument_list|)
block|;
name|void
name|activationFinished
argument_list|(
name|QDBusPendingCallWatcher
operator|*
argument_list|)
block|;
name|private
name|Q_SLOTS
operator|:
name|private
operator|:
name|QNetworkManagerInterfacePrivate
operator|*
name|d
block|;
name|QNmDBusHelper
operator|*
name|nmDBusHelper
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkManagerInterfaceAccessPointPrivate
name|class
name|QNetworkManagerInterfaceAccessPointPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkManagerInterfaceAccessPoint
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|DeviceState
block|{
name|Unknown
operator|=
literal|0
block|,
name|Unmanaged
block|,
name|Unavailable
block|,
name|Disconnected
block|,
name|Prepare
block|,
name|Config
block|,
name|NeedAuthentication
block|,
name|IpConfig
block|,
name|Activated
block|,
name|Failed
block|}
block|;      enum
name|ApFlag
block|{
name|ApNone
operator|=
literal|0x0
block|,
name|Privacy
operator|=
literal|0x1
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|ApFlags
argument_list|,
name|ApFlag
argument_list|)
expr|enum
name|ApSecurityFlag
block|{
name|ApSecurityNone
operator|=
literal|0x0
block|,
name|PairWep40
operator|=
literal|0x1
block|,
name|PairWep104
operator|=
literal|0x2
block|,
name|PairTkip
operator|=
literal|0x4
block|,
name|PairCcmp
operator|=
literal|0x8
block|,
name|GroupWep40
operator|=
literal|0x10
block|,
name|GroupWep104
operator|=
literal|0x20
block|,
name|GroupTkip
operator|=
literal|0x40
block|,
name|GroupCcmp
operator|=
literal|0x80
block|,
name|KeyPsk
operator|=
literal|0x100
block|,
name|Key8021x
operator|=
literal|0x200
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ApSecurityFlags
argument_list|,
argument|ApSecurityFlag
argument_list|)
name|explicit
name|QNetworkManagerInterfaceAccessPoint
argument_list|(
specifier|const
name|QString
operator|&
name|dbusPathName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNetworkManagerInterfaceAccessPoint
argument_list|()
block|;
name|QDBusInterface
operator|*
name|connectionInterface
argument_list|()
specifier|const
block|;
name|quint32
name|flags
argument_list|()
specifier|const
block|;
name|quint32
name|wpaFlags
argument_list|()
specifier|const
block|;
name|quint32
name|rsnFlags
argument_list|()
specifier|const
block|;
name|QString
name|ssid
argument_list|()
specifier|const
block|;
name|quint32
name|frequency
argument_list|()
specifier|const
block|;
name|QString
name|hwAddress
argument_list|()
specifier|const
block|;
name|quint32
name|mode
argument_list|()
specifier|const
block|;
name|quint32
name|maxBitrate
argument_list|()
specifier|const
block|;
name|quint32
name|strength
argument_list|()
specifier|const
block|;
name|bool
name|setConnections
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|propertiesChanged
argument_list|(
name|QMap
operator|<
name|QString
argument_list|,
name|QVariant
operator|>
argument_list|)
block|;
name|void
name|propertiesChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|QMap
operator|<
name|QString
argument_list|,
name|QVariant
operator|>
argument_list|)
block|;
name|private
operator|:
name|QNetworkManagerInterfaceAccessPointPrivate
operator|*
name|d
block|;
name|QNmDBusHelper
operator|*
name|nmDBusHelper
block|;  }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkManagerInterfaceDevicePrivate
name|class
name|QNetworkManagerInterfaceDevicePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkManagerInterfaceDevice
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QNetworkManagerInterfaceDevice
argument_list|(
specifier|const
name|QString
operator|&
name|deviceObjectPath
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNetworkManagerInterfaceDevice
argument_list|()
block|;
name|QString
name|udi
argument_list|()
specifier|const
block|;
name|QString
name|networkInterface
argument_list|()
specifier|const
block|;
name|QDBusInterface
operator|*
name|connectionInterface
argument_list|()
specifier|const
block|;
name|quint32
name|ip4Address
argument_list|()
specifier|const
block|;
name|quint32
name|state
argument_list|()
specifier|const
block|;
name|quint32
name|deviceType
argument_list|()
specifier|const
block|;
name|QDBusObjectPath
name|ip4config
argument_list|()
specifier|const
block|;
name|bool
name|setConnections
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|stateChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|quint32
argument_list|)
block|;
name|private
operator|:
name|QNetworkManagerInterfaceDevicePrivate
operator|*
name|d
block|;
name|QNmDBusHelper
operator|*
name|nmDBusHelper
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkManagerInterfaceDeviceWiredPrivate
name|class
name|QNetworkManagerInterfaceDeviceWiredPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkManagerInterfaceDeviceWired
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QNetworkManagerInterfaceDeviceWired
argument_list|(
specifier|const
name|QString
operator|&
name|ifaceDevicePath
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNetworkManagerInterfaceDeviceWired
argument_list|()
block|;
name|QDBusInterface
operator|*
name|connectionInterface
argument_list|()
specifier|const
block|;
name|QString
name|hwAddress
argument_list|()
specifier|const
block|;
name|quint32
name|speed
argument_list|()
specifier|const
block|;
name|bool
name|carrier
argument_list|()
specifier|const
block|;
name|bool
name|setConnections
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|propertiesChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|QMap
operator|<
name|QString
argument_list|,
name|QVariant
operator|>
argument_list|)
block|;
name|private
operator|:
name|QNetworkManagerInterfaceDeviceWiredPrivate
operator|*
name|d
block|;
name|QNmDBusHelper
operator|*
name|nmDBusHelper
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkManagerInterfaceDeviceWirelessPrivate
name|class
name|QNetworkManagerInterfaceDeviceWirelessPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkManagerInterfaceDeviceWireless
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|DeviceCapability
block|{
name|None
operator|=
literal|0x0
block|,
name|Wep40
operator|=
literal|0x1
block|,
name|Wep104
operator|=
literal|0x2
block|,
name|Tkip
operator|=
literal|0x4
block|,
name|Ccmp
operator|=
literal|0x8
block|,
name|Wpa
operator|=
literal|0x10
block|,
name|Rsn
operator|=
literal|0x20
block|}
block|;
name|explicit
name|QNetworkManagerInterfaceDeviceWireless
argument_list|(
specifier|const
name|QString
operator|&
name|ifaceDevicePath
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNetworkManagerInterfaceDeviceWireless
argument_list|()
block|;
name|QDBusObjectPath
name|path
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QDBusObjectPath
operator|>
name|getAccessPoints
argument_list|()
block|;
name|QDBusInterface
operator|*
name|connectionInterface
argument_list|()
specifier|const
block|;
name|QString
name|hwAddress
argument_list|()
specifier|const
block|;
name|quint32
name|mode
argument_list|()
specifier|const
block|;
name|quint32
name|bitrate
argument_list|()
specifier|const
block|;
name|QDBusObjectPath
name|activeAccessPoint
argument_list|()
specifier|const
block|;
name|quint32
name|wirelessCapabilities
argument_list|()
specifier|const
block|;
name|bool
name|setConnections
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|propertiesChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|QMap
operator|<
name|QString
argument_list|,
name|QVariant
operator|>
argument_list|)
block|;
name|void
name|accessPointAdded
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|QDBusObjectPath
argument_list|)
block|;
name|void
name|accessPointRemoved
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|QDBusObjectPath
argument_list|)
block|;
name|private
operator|:
name|QNetworkManagerInterfaceDeviceWirelessPrivate
operator|*
name|d
block|;
name|QNmDBusHelper
operator|*
name|nmDBusHelper
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkManagerSettingsPrivate
name|class
name|QNetworkManagerSettingsPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkManagerSettings
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QNetworkManagerSettings
argument_list|(
specifier|const
name|QString
operator|&
name|settingsService
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNetworkManagerSettings
argument_list|()
block|;
name|QDBusInterface
operator|*
name|connectionInterface
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QDBusObjectPath
operator|>
name|listConnections
argument_list|()
block|;
name|bool
name|setConnections
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|newConnection
argument_list|(
name|QDBusObjectPath
argument_list|)
block|;
name|private
operator|:
name|QNetworkManagerSettingsPrivate
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkManagerSettingsConnectionPrivate
name|class
name|QNetworkManagerSettingsConnectionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkManagerSettingsConnection
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QNetworkManagerSettingsConnection
argument_list|(
specifier|const
name|QString
operator|&
name|settingsService
argument_list|,
specifier|const
name|QString
operator|&
name|connectionObjectPath
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNetworkManagerSettingsConnection
argument_list|()
block|;
name|QDBusInterface
operator|*
name|connectionInterface
argument_list|()
specifier|const
block|;
name|QNmSettingsMap
name|getSettings
argument_list|()
block|;
name|bool
name|setConnections
argument_list|()
block|;
name|NMDeviceType
name|getType
argument_list|()
block|;
name|bool
name|isAutoConnect
argument_list|()
block|;
name|quint64
name|getTimestamp
argument_list|()
block|;
name|QString
name|getId
argument_list|()
block|;
name|QString
name|getUuid
argument_list|()
block|;
name|QString
name|getSsid
argument_list|()
block|;
name|QString
name|getMacAddress
argument_list|()
block|;
name|QStringList
name|getSeenBssids
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|updated
argument_list|(
specifier|const
name|QNmSettingsMap
operator|&
name|settings
argument_list|)
block|;
name|void
name|removed
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|private
operator|:
name|QNmDBusHelper
operator|*
name|nmDBusHelper
block|;
name|QNetworkManagerSettingsConnectionPrivate
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkManagerConnectionActivePrivate
name|class
name|QNetworkManagerConnectionActivePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkManagerConnectionActive
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|ActiveConnectionState
block|{
name|Unknown
operator|=
literal|0
block|,
name|Activating
operator|=
literal|1
block|,
name|Activated
operator|=
literal|2
block|}
block|;
name|explicit
name|QNetworkManagerConnectionActive
argument_list|(
specifier|const
name|QString
operator|&
name|dbusPathName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNetworkManagerConnectionActive
argument_list|()
block|;
name|QDBusInterface
operator|*
name|connectionInterface
argument_list|()
specifier|const
block|;
name|QString
name|serviceName
argument_list|()
specifier|const
block|;
name|QDBusObjectPath
name|connection
argument_list|()
specifier|const
block|;
name|QDBusObjectPath
name|specificObject
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QDBusObjectPath
operator|>
name|devices
argument_list|()
specifier|const
block|;
name|quint32
name|state
argument_list|()
specifier|const
block|;
name|bool
name|defaultRoute
argument_list|()
specifier|const
block|;
name|bool
name|setConnections
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|propertiesChanged
argument_list|(
name|QList
operator|<
name|QDBusObjectPath
operator|>
argument_list|)
block|;
name|void
name|propertiesChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|QMap
operator|<
name|QString
argument_list|,
name|QVariant
operator|>
argument_list|)
block|;
name|private
operator|:
name|QNetworkManagerConnectionActivePrivate
operator|*
name|d
block|;
name|QNmDBusHelper
operator|*
name|nmDBusHelper
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkManagerIp4ConfigPrivate
name|class
name|QNetworkManagerIp4ConfigPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkManagerIp4Config
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QNetworkManagerIp4Config
argument_list|(
specifier|const
name|QString
operator|&
name|dbusPathName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNetworkManagerIp4Config
argument_list|()
block|;
name|QStringList
name|domains
argument_list|()
specifier|const
block|;
name|bool
name|isValid
argument_list|()
block|;
name|private
operator|:
name|QNetworkManagerIp4ConfigPrivate
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
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
begin_comment
comment|//QNETWORKMANAGERSERVICE_H
end_comment
end_unit
