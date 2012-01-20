begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PLATFORMDEFS_H
end_ifndef
begin_define
DECL|macro|PLATFORMDEFS_H
define|#
directive|define
name|PLATFORMDEFS_H
end_define
begin_include
include|#
directive|include
file|<wtypes.h>
end_include
begin_undef
DECL|macro|interface
undef|#
directive|undef
name|interface
end_undef
begin_define
DECL|macro|WLAN_MAX_NAME_LENGTH
define|#
directive|define
name|WLAN_MAX_NAME_LENGTH
value|256
end_define
begin_define
DECL|macro|WLAN_MAX_PHY_TYPE_NUMBER
define|#
directive|define
name|WLAN_MAX_PHY_TYPE_NUMBER
value|8
end_define
begin_define
DECL|macro|WLAN_NOTIFICATION_SOURCE_ALL
define|#
directive|define
name|WLAN_NOTIFICATION_SOURCE_ALL
value|0x0000ffff
end_define
begin_define
DECL|macro|WLAN_AVAILABLE_NETWORK_CONNECTED
define|#
directive|define
name|WLAN_AVAILABLE_NETWORK_CONNECTED
value|1
end_define
begin_define
DECL|macro|WLAN_AVAILABLE_NETWORK_HAS_PROFILE
define|#
directive|define
name|WLAN_AVAILABLE_NETWORK_HAS_PROFILE
value|2
end_define
begin_define
DECL|macro|DOT11_SSID_MAX_LENGTH
define|#
directive|define
name|DOT11_SSID_MAX_LENGTH
value|32
end_define
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|WLAN_NOTIFICATION_DATA
struct|struct
name|WLAN_NOTIFICATION_DATA
block|{
DECL|member|NotificationSource
name|DWORD
name|NotificationSource
decl_stmt|;
DECL|member|NotificationCode
name|DWORD
name|NotificationCode
decl_stmt|;
DECL|member|InterfaceGuid
name|GUID
name|InterfaceGuid
decl_stmt|;
DECL|member|dwDataSize
name|DWORD
name|dwDataSize
decl_stmt|;
DECL|member|pData
name|PVOID
name|pData
decl_stmt|;
block|}
struct|;
end_struct
begin_enum
DECL|enum|WLAN_INTERFACE_STATE
enum|enum
name|WLAN_INTERFACE_STATE
block|{
DECL|enumerator|wlan_interface_state_not_ready
name|wlan_interface_state_not_ready
init|=
literal|0
block|,
DECL|enumerator|wlan_interface_state_connected
name|wlan_interface_state_connected
block|,
DECL|enumerator|wlan_interface_state_ad_hoc_network_formed
name|wlan_interface_state_ad_hoc_network_formed
block|,
DECL|enumerator|wlan_interface_state_disconnecting
name|wlan_interface_state_disconnecting
block|,
DECL|enumerator|wlan_interface_state_disconnected
name|wlan_interface_state_disconnected
block|,
DECL|enumerator|wlan_interface_state_associating
name|wlan_interface_state_associating
block|,
DECL|enumerator|wlan_interface_state_discovering
name|wlan_interface_state_discovering
block|,
DECL|enumerator|wlan_interface_state_authenticating
name|wlan_interface_state_authenticating
block|}
enum|;
end_enum
begin_struct
DECL|struct|WLAN_INTERFACE_INFO
struct|struct
name|WLAN_INTERFACE_INFO
block|{
DECL|member|InterfaceGuid
name|GUID
name|InterfaceGuid
decl_stmt|;
DECL|member|strInterfaceDescription
name|WCHAR
name|strInterfaceDescription
index|[
name|WLAN_MAX_NAME_LENGTH
index|]
decl_stmt|;
DECL|member|isState
name|WLAN_INTERFACE_STATE
name|isState
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|WLAN_INTERFACE_INFO_LIST
struct|struct
name|WLAN_INTERFACE_INFO_LIST
block|{
DECL|member|dwNumberOfItems
name|DWORD
name|dwNumberOfItems
decl_stmt|;
DECL|member|dwIndex
name|DWORD
name|dwIndex
decl_stmt|;
DECL|member|InterfaceInfo
name|WLAN_INTERFACE_INFO
name|InterfaceInfo
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|DOT11_SSID
struct|struct
name|DOT11_SSID
block|{
DECL|member|uSSIDLength
name|ULONG
name|uSSIDLength
decl_stmt|;
DECL|member|ucSSID
name|UCHAR
name|ucSSID
index|[
name|DOT11_SSID_MAX_LENGTH
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|NDIS_OBJECT_HEADER
struct|struct
name|NDIS_OBJECT_HEADER
block|{
DECL|member|Type
name|UCHAR
name|Type
decl_stmt|;
DECL|member|Revision
name|UCHAR
name|Revision
decl_stmt|;
DECL|member|Size
name|USHORT
name|Size
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|DOT11_MAC_ADDRESS
typedef|typedef
name|UCHAR
name|DOT11_MAC_ADDRESS
index|[
literal|6
index|]
typedef|;
end_typedef
begin_struct
DECL|struct|DOT11_BSSID_LIST
struct|struct
name|DOT11_BSSID_LIST
block|{
DECL|member|Header
name|NDIS_OBJECT_HEADER
name|Header
decl_stmt|;
DECL|member|uNumberOfEntries
name|ULONG
name|uNumberOfEntries
decl_stmt|;
DECL|member|uTotalNumOfEntries
name|ULONG
name|uTotalNumOfEntries
decl_stmt|;
DECL|member|BSSIDs
name|DOT11_MAC_ADDRESS
name|BSSIDs
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_enum
DECL|enum|DOT11_BSS_TYPE
enum|enum
name|DOT11_BSS_TYPE
block|{
DECL|enumerator|dot11_BSS_type_infrastructure
name|dot11_BSS_type_infrastructure
init|=
literal|1
block|,
DECL|enumerator|dot11_BSS_type_independent
name|dot11_BSS_type_independent
init|=
literal|2
block|,
DECL|enumerator|dot11_BSS_type_any
name|dot11_BSS_type_any
init|=
literal|3
block|}
enum|;
end_enum
begin_enum
DECL|enum|DOT11_PHY_TYPE
enum|enum
name|DOT11_PHY_TYPE
block|{
DECL|enumerator|dot11_phy_type_unknown
name|dot11_phy_type_unknown
init|=
literal|0
block|,
DECL|enumerator|dot11_phy_type_any
name|dot11_phy_type_any
init|=
name|dot11_phy_type_unknown
block|,
DECL|enumerator|dot11_phy_type_fhss
name|dot11_phy_type_fhss
init|=
literal|1
block|,
DECL|enumerator|dot11_phy_type_dsss
name|dot11_phy_type_dsss
init|=
literal|2
block|,
DECL|enumerator|dot11_phy_type_irbaseband
name|dot11_phy_type_irbaseband
init|=
literal|3
block|,
DECL|enumerator|dot11_phy_type_ofdm
name|dot11_phy_type_ofdm
init|=
literal|4
block|,
DECL|enumerator|dot11_phy_type_hrdsss
name|dot11_phy_type_hrdsss
init|=
literal|5
block|,
DECL|enumerator|dot11_phy_type_erp
name|dot11_phy_type_erp
init|=
literal|6
block|,
DECL|enumerator|dot11_phy_type_ht
name|dot11_phy_type_ht
init|=
literal|7
block|,
DECL|enumerator|dot11_phy_type_IHV_start
name|dot11_phy_type_IHV_start
init|=
literal|0x80000000
block|,
DECL|enumerator|dot11_phy_type_IHV_end
name|dot11_phy_type_IHV_end
init|=
literal|0xffffffff
block|}
enum|;
end_enum
begin_enum
DECL|enum|DOT11_AUTH_ALGORITHM
enum|enum
name|DOT11_AUTH_ALGORITHM
block|{
DECL|enumerator|DOT11_AUTH_ALGO_80211_OPEN
name|DOT11_AUTH_ALGO_80211_OPEN
init|=
literal|1
block|,
DECL|enumerator|DOT11_AUTH_ALGO_80211_SHARED_KEY
name|DOT11_AUTH_ALGO_80211_SHARED_KEY
init|=
literal|2
block|,
DECL|enumerator|DOT11_AUTH_ALGO_WPA
name|DOT11_AUTH_ALGO_WPA
init|=
literal|3
block|,
DECL|enumerator|DOT11_AUTH_ALGO_WPA_PSK
name|DOT11_AUTH_ALGO_WPA_PSK
init|=
literal|4
block|,
DECL|enumerator|DOT11_AUTH_ALGO_WPA_NONE
name|DOT11_AUTH_ALGO_WPA_NONE
init|=
literal|5
block|,
DECL|enumerator|DOT11_AUTH_ALGO_RSNA
name|DOT11_AUTH_ALGO_RSNA
init|=
literal|6
block|,
DECL|enumerator|DOT11_AUTH_ALGO_RSNA_PSK
name|DOT11_AUTH_ALGO_RSNA_PSK
init|=
literal|7
block|,
DECL|enumerator|DOT11_AUTH_ALGO_IHV_START
name|DOT11_AUTH_ALGO_IHV_START
init|=
literal|0x80000000
block|,
DECL|enumerator|DOT11_AUTH_ALGO_IHV_END
name|DOT11_AUTH_ALGO_IHV_END
init|=
literal|0xffffffff
block|}
enum|;
end_enum
begin_enum
DECL|enum|DOT11_CIPHER_ALGORITHM
enum|enum
name|DOT11_CIPHER_ALGORITHM
block|{
DECL|enumerator|DOT11_CIPHER_ALGO_NONE
name|DOT11_CIPHER_ALGO_NONE
init|=
literal|0x00
block|,
DECL|enumerator|DOT11_CIPHER_ALGO_WEP40
name|DOT11_CIPHER_ALGO_WEP40
init|=
literal|0x01
block|,
DECL|enumerator|DOT11_CIPHER_ALGO_TKIP
name|DOT11_CIPHER_ALGO_TKIP
init|=
literal|0x02
block|,
DECL|enumerator|DOT11_CIPHER_ALGO_CCMP
name|DOT11_CIPHER_ALGO_CCMP
init|=
literal|0x04
block|,
DECL|enumerator|DOT11_CIPHER_ALGO_WEP104
name|DOT11_CIPHER_ALGO_WEP104
init|=
literal|0x05
block|,
DECL|enumerator|DOT11_CIPHER_ALGO_WPA_USE_GROUP
name|DOT11_CIPHER_ALGO_WPA_USE_GROUP
init|=
literal|0x100
block|,
DECL|enumerator|DOT11_CIPHER_ALGO_RSN_USE_GROUP
name|DOT11_CIPHER_ALGO_RSN_USE_GROUP
init|=
literal|0x100
block|,
DECL|enumerator|DOT11_CIPHER_ALGO_WEP
name|DOT11_CIPHER_ALGO_WEP
init|=
literal|0x101
block|,
DECL|enumerator|DOT11_CIPHER_ALGO_IHV_START
name|DOT11_CIPHER_ALGO_IHV_START
init|=
literal|0x80000000
block|,
DECL|enumerator|DOT11_CIPHER_ALGO_IHV_END
name|DOT11_CIPHER_ALGO_IHV_END
init|=
literal|0xffffffff
block|}
enum|;
end_enum
begin_struct
DECL|struct|WLAN_AVAILABLE_NETWORK
struct|struct
name|WLAN_AVAILABLE_NETWORK
block|{
DECL|member|strProfileName
name|WCHAR
name|strProfileName
index|[
name|WLAN_MAX_NAME_LENGTH
index|]
decl_stmt|;
DECL|member|dot11Ssid
name|DOT11_SSID
name|dot11Ssid
decl_stmt|;
DECL|member|dot11BssType
name|DOT11_BSS_TYPE
name|dot11BssType
decl_stmt|;
DECL|member|uNumberOfBssids
name|ULONG
name|uNumberOfBssids
decl_stmt|;
DECL|member|bNetworkConnectable
name|BOOL
name|bNetworkConnectable
decl_stmt|;
DECL|member|wlanNotConnectableReason
name|DWORD
name|wlanNotConnectableReason
decl_stmt|;
DECL|member|uNumberOfPhyTypes
name|ULONG
name|uNumberOfPhyTypes
decl_stmt|;
DECL|member|dot11PhyTypes
name|DOT11_PHY_TYPE
name|dot11PhyTypes
index|[
name|WLAN_MAX_PHY_TYPE_NUMBER
index|]
decl_stmt|;
DECL|member|bMorePhyTypes
name|BOOL
name|bMorePhyTypes
decl_stmt|;
DECL|member|wlanSignalQuality
name|ULONG
name|wlanSignalQuality
decl_stmt|;
DECL|member|bSecurityEnabled
name|BOOL
name|bSecurityEnabled
decl_stmt|;
DECL|member|dot11DefaultAuthAlgorithm
name|DOT11_AUTH_ALGORITHM
name|dot11DefaultAuthAlgorithm
decl_stmt|;
DECL|member|dot11DefaultCipherAlgorithm
name|DOT11_CIPHER_ALGORITHM
name|dot11DefaultCipherAlgorithm
decl_stmt|;
DECL|member|dwFlags
name|DWORD
name|dwFlags
decl_stmt|;
DECL|member|dwReserved
name|DWORD
name|dwReserved
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|WLAN_AVAILABLE_NETWORK_LIST
struct|struct
name|WLAN_AVAILABLE_NETWORK_LIST
block|{
DECL|member|dwNumberOfItems
name|DWORD
name|dwNumberOfItems
decl_stmt|;
DECL|member|dwIndex
name|DWORD
name|dwIndex
decl_stmt|;
DECL|member|Network
name|WLAN_AVAILABLE_NETWORK
name|Network
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_enum
DECL|enum|WLAN_INTF_OPCODE
enum|enum
name|WLAN_INTF_OPCODE
block|{
DECL|enumerator|wlan_intf_opcode_autoconf_start
name|wlan_intf_opcode_autoconf_start
init|=
literal|0x000000000
block|,
DECL|enumerator|wlan_intf_opcode_autoconf_enabled
name|wlan_intf_opcode_autoconf_enabled
block|,
DECL|enumerator|wlan_intf_opcode_background_scan_enabled
name|wlan_intf_opcode_background_scan_enabled
block|,
DECL|enumerator|wlan_intf_opcode_media_streaming_mode
name|wlan_intf_opcode_media_streaming_mode
block|,
DECL|enumerator|wlan_intf_opcode_radio_state
name|wlan_intf_opcode_radio_state
block|,
DECL|enumerator|wlan_intf_opcode_bss_type
name|wlan_intf_opcode_bss_type
block|,
DECL|enumerator|wlan_intf_opcode_interface_state
name|wlan_intf_opcode_interface_state
block|,
DECL|enumerator|wlan_intf_opcode_current_connection
name|wlan_intf_opcode_current_connection
block|,
DECL|enumerator|wlan_intf_opcode_channel_number
name|wlan_intf_opcode_channel_number
block|,
DECL|enumerator|wlan_intf_opcode_supported_infrastructure_auth_cipher_pairs
name|wlan_intf_opcode_supported_infrastructure_auth_cipher_pairs
block|,
DECL|enumerator|wlan_intf_opcode_supported_adhoc_auth_cipher_pairs
name|wlan_intf_opcode_supported_adhoc_auth_cipher_pairs
block|,
DECL|enumerator|wlan_intf_opcode_supported_country_or_region_string_list
name|wlan_intf_opcode_supported_country_or_region_string_list
block|,
DECL|enumerator|wlan_intf_opcode_current_operation_mode
name|wlan_intf_opcode_current_operation_mode
block|,
DECL|enumerator|wlan_intf_opcode_supported_safe_mode
name|wlan_intf_opcode_supported_safe_mode
block|,
DECL|enumerator|wlan_intf_opcode_certified_safe_mode
name|wlan_intf_opcode_certified_safe_mode
block|,
DECL|enumerator|wlan_intf_opcode_autoconf_end
name|wlan_intf_opcode_autoconf_end
init|=
literal|0x0fffffff
block|,
DECL|enumerator|wlan_intf_opcode_msm_start
name|wlan_intf_opcode_msm_start
init|=
literal|0x10000100
block|,
DECL|enumerator|wlan_intf_opcode_statistics
name|wlan_intf_opcode_statistics
block|,
DECL|enumerator|wlan_intf_opcode_rssi
name|wlan_intf_opcode_rssi
block|,
DECL|enumerator|wlan_intf_opcode_msm_end
name|wlan_intf_opcode_msm_end
init|=
literal|0x1fffffff
block|,
DECL|enumerator|wlan_intf_opcode_security_start
name|wlan_intf_opcode_security_start
init|=
literal|0x20010000
block|,
DECL|enumerator|wlan_intf_opcode_security_end
name|wlan_intf_opcode_security_end
init|=
literal|0x2fffffff
block|,
DECL|enumerator|wlan_intf_opcode_ihv_start
name|wlan_intf_opcode_ihv_start
init|=
literal|0x30000000
block|,
DECL|enumerator|wlan_intf_opcode_ihv_end
name|wlan_intf_opcode_ihv_end
init|=
literal|0x3fffffff
block|}
enum|;
end_enum
begin_enum
DECL|enum|WLAN_OPCODE_VALUE_TYPE
enum|enum
name|WLAN_OPCODE_VALUE_TYPE
block|{
DECL|enumerator|wlan_opcode_value_type_query_only
name|wlan_opcode_value_type_query_only
init|=
literal|0
block|,
DECL|enumerator|wlan_opcode_value_type_set_by_group_policy
name|wlan_opcode_value_type_set_by_group_policy
block|,
DECL|enumerator|wlan_opcode_value_type_set_by_user
name|wlan_opcode_value_type_set_by_user
block|,
DECL|enumerator|wlan_opcode_value_type_invalid
name|wlan_opcode_value_type_invalid
block|}
enum|;
end_enum
begin_enum
DECL|enum|WLAN_CONNECTION_MODE
enum|enum
name|WLAN_CONNECTION_MODE
block|{
DECL|enumerator|wlan_connection_mode_profile
name|wlan_connection_mode_profile
init|=
literal|0
block|,
DECL|enumerator|wlan_connection_mode_temporary_profile
name|wlan_connection_mode_temporary_profile
block|,
DECL|enumerator|wlan_connection_mode_discovery_secure
name|wlan_connection_mode_discovery_secure
block|,
DECL|enumerator|wlan_connection_mode_discovery_unsecure
name|wlan_connection_mode_discovery_unsecure
block|,
DECL|enumerator|wlan_connection_mode_auto
name|wlan_connection_mode_auto
block|,
DECL|enumerator|wlan_connection_mode_invalid
name|wlan_connection_mode_invalid
block|}
enum|;
end_enum
begin_struct
DECL|struct|WLAN_CONNECTION_PARAMETERS
struct|struct
name|WLAN_CONNECTION_PARAMETERS
block|{
DECL|member|wlanConnectionMode
name|WLAN_CONNECTION_MODE
name|wlanConnectionMode
decl_stmt|;
DECL|member|strProfile
name|LPCWSTR
name|strProfile
decl_stmt|;
DECL|member|pDot11Ssid
name|DOT11_SSID
modifier|*
name|pDot11Ssid
decl_stmt|;
DECL|member|pDesiredBssidList
name|DOT11_BSSID_LIST
modifier|*
name|pDesiredBssidList
decl_stmt|;
DECL|member|dot11BssType
name|DOT11_BSS_TYPE
name|dot11BssType
decl_stmt|;
DECL|member|dwFlags
name|DWORD
name|dwFlags
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|WLAN_RAW_DATA
struct|struct
name|WLAN_RAW_DATA
block|{
DECL|member|dwDataSize
name|DWORD
name|dwDataSize
decl_stmt|;
DECL|member|DataBlob
name|BYTE
name|DataBlob
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_enum
DECL|enum|WLAN_NOTIFICATION_ACM
enum|enum
name|WLAN_NOTIFICATION_ACM
block|{
DECL|enumerator|wlan_notification_acm_start
name|wlan_notification_acm_start
init|=
literal|0
block|,
DECL|enumerator|wlan_notification_acm_autoconf_enabled
name|wlan_notification_acm_autoconf_enabled
block|,
DECL|enumerator|wlan_notification_acm_autoconf_disabled
name|wlan_notification_acm_autoconf_disabled
block|,
DECL|enumerator|wlan_notification_acm_background_scan_enabled
name|wlan_notification_acm_background_scan_enabled
block|,
DECL|enumerator|wlan_notification_acm_background_scan_disabled
name|wlan_notification_acm_background_scan_disabled
block|,
DECL|enumerator|wlan_notification_acm_bss_type_change
name|wlan_notification_acm_bss_type_change
block|,
DECL|enumerator|wlan_notification_acm_power_setting_change
name|wlan_notification_acm_power_setting_change
block|,
DECL|enumerator|wlan_notification_acm_scan_complete
name|wlan_notification_acm_scan_complete
block|,
DECL|enumerator|wlan_notification_acm_scan_fail
name|wlan_notification_acm_scan_fail
block|,
DECL|enumerator|wlan_notification_acm_connection_start
name|wlan_notification_acm_connection_start
block|,
DECL|enumerator|wlan_notification_acm_connection_complete
name|wlan_notification_acm_connection_complete
block|,
DECL|enumerator|wlan_notification_acm_connection_attempt_fail
name|wlan_notification_acm_connection_attempt_fail
block|,
DECL|enumerator|wlan_notification_acm_filter_list_change
name|wlan_notification_acm_filter_list_change
block|,
DECL|enumerator|wlan_notification_acm_interface_arrival
name|wlan_notification_acm_interface_arrival
block|,
DECL|enumerator|wlan_notification_acm_interface_removal
name|wlan_notification_acm_interface_removal
block|,
DECL|enumerator|wlan_notification_acm_profile_change
name|wlan_notification_acm_profile_change
block|,
DECL|enumerator|wlan_notification_acm_profile_name_change
name|wlan_notification_acm_profile_name_change
block|,
DECL|enumerator|wlan_notification_acm_profiles_exhausted
name|wlan_notification_acm_profiles_exhausted
block|,
DECL|enumerator|wlan_notification_acm_network_not_available
name|wlan_notification_acm_network_not_available
block|,
DECL|enumerator|wlan_notification_acm_network_available
name|wlan_notification_acm_network_available
block|,
DECL|enumerator|wlan_notification_acm_disconnecting
name|wlan_notification_acm_disconnecting
block|,
DECL|enumerator|wlan_notification_acm_disconnected
name|wlan_notification_acm_disconnected
block|,
DECL|enumerator|wlan_notification_acm_adhoc_network_state_change
name|wlan_notification_acm_adhoc_network_state_change
block|,
DECL|enumerator|wlan_notification_acm_end
name|wlan_notification_acm_end
block|}
enum|;
end_enum
begin_struct
DECL|struct|WLAN_ASSOCIATION_ATTRIBUTES
struct|struct
name|WLAN_ASSOCIATION_ATTRIBUTES
block|{
DECL|member|dot11Ssid
name|DOT11_SSID
name|dot11Ssid
decl_stmt|;
DECL|member|dot11BssType
name|DOT11_BSS_TYPE
name|dot11BssType
decl_stmt|;
DECL|member|dot11Bssid
name|DOT11_MAC_ADDRESS
name|dot11Bssid
decl_stmt|;
DECL|member|dot11PhyType
name|DOT11_PHY_TYPE
name|dot11PhyType
decl_stmt|;
DECL|member|uDot11PhyIndex
name|ULONG
name|uDot11PhyIndex
decl_stmt|;
DECL|member|wlanSignalQuality
name|ULONG
name|wlanSignalQuality
decl_stmt|;
DECL|member|ulRxRate
name|ULONG
name|ulRxRate
decl_stmt|;
DECL|member|ulTxRate
name|ULONG
name|ulTxRate
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|WLAN_SECURITY_ATTRIBUTES
struct|struct
name|WLAN_SECURITY_ATTRIBUTES
block|{
DECL|member|bSecurityEnabled
name|BOOL
name|bSecurityEnabled
decl_stmt|;
DECL|member|bOneXEnabled
name|BOOL
name|bOneXEnabled
decl_stmt|;
DECL|member|dot11AuthAlgorithm
name|DOT11_AUTH_ALGORITHM
name|dot11AuthAlgorithm
decl_stmt|;
DECL|member|dot11CipherAlgorithm
name|DOT11_CIPHER_ALGORITHM
name|dot11CipherAlgorithm
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|WLAN_CONNECTION_ATTRIBUTES
struct|struct
name|WLAN_CONNECTION_ATTRIBUTES
block|{
DECL|member|isState
name|WLAN_INTERFACE_STATE
name|isState
decl_stmt|;
DECL|member|wlanConnectionMode
name|WLAN_CONNECTION_MODE
name|wlanConnectionMode
decl_stmt|;
DECL|member|strProfileName
name|WCHAR
name|strProfileName
index|[
name|WLAN_MAX_NAME_LENGTH
index|]
decl_stmt|;
DECL|member|wlanAssociationAttributes
name|WLAN_ASSOCIATION_ATTRIBUTES
name|wlanAssociationAttributes
decl_stmt|;
DECL|member|wlanSecurityAttributes
name|WLAN_SECURITY_ATTRIBUTES
name|wlanSecurityAttributes
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|WLAN_NOTIFICATION_CALLBACK
typedef|typedef
name|void
function_decl|(
name|WINAPI
modifier|*
name|WLAN_NOTIFICATION_CALLBACK
function_decl|)
parameter_list|(
name|WLAN_NOTIFICATION_DATA
modifier|*
parameter_list|,
name|PVOID
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|WlanOpenHandleProto
typedef|typedef
name|DWORD
function_decl|(
name|WINAPI
modifier|*
name|WlanOpenHandleProto
function_decl|)
parameter_list|(
name|DWORD
name|dwClientVersion
parameter_list|,
name|PVOID
name|pReserved
parameter_list|,
name|PDWORD
name|pdwNegotiatedVersion
parameter_list|,
name|PHANDLE
name|phClientHandle
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|WlanRegisterNotificationProto
typedef|typedef
name|DWORD
function_decl|(
name|WINAPI
modifier|*
name|WlanRegisterNotificationProto
function_decl|)
parameter_list|(
name|HANDLE
name|hClientHandle
parameter_list|,
name|DWORD
name|dwNotifSource
parameter_list|,
name|BOOL
name|bIgnoreDuplicate
parameter_list|,
name|WLAN_NOTIFICATION_CALLBACK
name|funcCallback
parameter_list|,
name|PVOID
name|pCallbackContext
parameter_list|,
name|PVOID
name|pReserved
parameter_list|,
name|PDWORD
name|pdwPrevNotifSource
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|WlanEnumInterfacesProto
typedef|typedef
name|DWORD
function_decl|(
name|WINAPI
modifier|*
name|WlanEnumInterfacesProto
function_decl|)
parameter_list|(
name|HANDLE
name|hClientHandle
parameter_list|,
name|PVOID
name|pReserved
parameter_list|,
name|WLAN_INTERFACE_INFO_LIST
modifier|*
modifier|*
name|ppInterfaceList
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|WlanGetAvailableNetworkListProto
typedef|typedef
name|DWORD
function_decl|(
name|WINAPI
modifier|*
name|WlanGetAvailableNetworkListProto
function_decl|)
parameter_list|(
name|HANDLE
name|hClientHandle
parameter_list|,
specifier|const
name|GUID
modifier|*
name|pInterfaceGuid
parameter_list|,
name|DWORD
name|dwFlags
parameter_list|,
name|PVOID
name|pReserved
parameter_list|,
name|WLAN_AVAILABLE_NETWORK_LIST
modifier|*
modifier|*
name|ppAvailableNetworkList
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|WlanQueryInterfaceProto
typedef|typedef
name|DWORD
function_decl|(
name|WINAPI
modifier|*
name|WlanQueryInterfaceProto
function_decl|)
parameter_list|(
name|HANDLE
name|hClientHandle
parameter_list|,
specifier|const
name|GUID
modifier|*
name|pInterfaceGuid
parameter_list|,
name|WLAN_INTF_OPCODE
name|OpCode
parameter_list|,
name|PVOID
name|pReserved
parameter_list|,
name|PDWORD
name|pdwDataSize
parameter_list|,
name|PVOID
modifier|*
name|ppData
parameter_list|,
name|WLAN_OPCODE_VALUE_TYPE
modifier|*
name|pWlanOpcodeValueType
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|WlanConnectProto
typedef|typedef
name|DWORD
function_decl|(
name|WINAPI
modifier|*
name|WlanConnectProto
function_decl|)
parameter_list|(
name|HANDLE
name|hClientHandle
parameter_list|,
specifier|const
name|GUID
modifier|*
name|pInterfaceGuid
parameter_list|,
specifier|const
name|WLAN_CONNECTION_PARAMETERS
modifier|*
name|pConnectionParameters
parameter_list|,
name|PVOID
name|pReserved
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|WlanDisconnectProto
typedef|typedef
name|DWORD
function_decl|(
name|WINAPI
modifier|*
name|WlanDisconnectProto
function_decl|)
parameter_list|(
name|HANDLE
name|hClientHandle
parameter_list|,
specifier|const
name|GUID
modifier|*
name|pInterfaceGuid
parameter_list|,
name|PVOID
name|pReserved
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|WlanScanProto
typedef|typedef
name|DWORD
function_decl|(
name|WINAPI
modifier|*
name|WlanScanProto
function_decl|)
parameter_list|(
name|HANDLE
name|hClientHandle
parameter_list|,
specifier|const
name|GUID
modifier|*
name|pInterfaceGuid
parameter_list|,
specifier|const
name|DOT11_SSID
modifier|*
name|pDot11Ssid
parameter_list|,
specifier|const
name|WLAN_RAW_DATA
modifier|*
name|pIeData
parameter_list|,
name|PVOID
name|pReserved
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|WlanFreeMemoryProto
typedef|typedef
name|VOID
function_decl|(
name|WINAPI
modifier|*
name|WlanFreeMemoryProto
function_decl|)
parameter_list|(
name|PVOID
name|pMemory
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|WlanCloseHandleProto
typedef|typedef
name|DWORD
function_decl|(
name|WINAPI
modifier|*
name|WlanCloseHandleProto
function_decl|)
parameter_list|(
name|HANDLE
name|hClientHandle
parameter_list|,
name|PVOID
name|pReserved
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
specifier|extern
name|WlanOpenHandleProto
name|local_WlanOpenHandle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|WlanRegisterNotificationProto
name|local_WlanRegisterNotification
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|WlanEnumInterfacesProto
name|local_WlanEnumInterfaces
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|WlanGetAvailableNetworkListProto
name|local_WlanGetAvailableNetworkList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|WlanQueryInterfaceProto
name|local_WlanQueryInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|WlanConnectProto
name|local_WlanConnect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|WlanDisconnectProto
name|local_WlanDisconnect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|WlanScanProto
name|local_WlanScan
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|WlanFreeMemoryProto
name|local_WlanFreeMemory
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|WlanCloseHandleProto
name|local_WlanCloseHandle
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
comment|// PLATFORMDEFS_H
end_comment
end_unit
