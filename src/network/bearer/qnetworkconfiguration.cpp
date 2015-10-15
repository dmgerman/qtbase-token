begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkconfiguration.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkconfiguration_p.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QNetworkConfiguration      \brief The QNetworkConfiguration class provides an abstraction of one or more access point configurations.      \since 4.7      \inmodule QtNetwork     \ingroup network     \ingroup shared      QNetworkConfiguration encapsulates a single access point or service network.     In most cases a single access point configuration can be mapped to one network     interface. However a single network interface may not always map to only one     access point configuration. Multiple configurations for the same     network device may enable multiple access points. An example     device that could exhibit such a configuration might be a     Smartphone which allows the user to manage multiple WLAN     configurations while the device itself has only one WLAN network device.      The QNetworkConfiguration also supports the concept of service networks.     This concept allows the grouping of multiple access point configurations     into one entity. Such a group is called service network and can be     beneficial in cases whereby a network session to a     particular destination network is required (e.g. a company network).     When using a service network the user doesn't usually care which one of the     connectivity options is chosen (e.g. corporate WLAN or VPN via GPRS)     as long as he can reach the company's target server. Depending     on the current position and time some of the access points that make     up the service network may not even be available. Furthermore     automated access point roaming can be enabled which enables the device     to change the network interface configuration dynamically while maintaining     the applications connection to the target network. It allows adaption     to the changing environment and may enable optimization with regards to     cost, speed or other network parameters.      Special configurations of type UserChoice provide a placeholder configuration which is     resolved to an actual network configuration by the platform when a     \l {QNetworkSession}{session} is \l {QNetworkSession::open()}{opened}. Not all platforms     support the concept of a user choice configuration.      \section1 Configuration States      The list of available configurations can be obtained via     QNetworkConfigurationManager::allConfigurations(). A configuration can have     multiple states. The \l Defined configuration state indicates that the configuration     is stored on the device. However the configuration is not yet ready to be activated     as e.g. a WLAN may not be available at the current time.      The \l Discovered state implies that the configuration is \l Defined and     the outside conditions are such that the configuration can be used immediately     to open a new network session. An example of such an outside condition may be     that the Ethernet cable is actually connected to the device or that the WLAN     with the specified SSID is in range.      The \l Active state implies that the configuration is \l Discovered. A configuration     in this state is currently being used by an application. The underlying network     interface has a valid IP configuration and can transfer IP packets between the     device and the target network.      The \l Undefined state indicates that the system has knowledge of possible target     networks but cannot actually use that knowledge to connect to it. An example     for such a state could be an encrypted WLAN that has been discovered     but the user hasn't actually saved a configuration including the required password     which would allow the device to connect to it.      Depending on the type of configuration some states are transient in nature. A GPRS/UMTS     connection may almost always be \l Discovered if the GSM/UMTS network is available.     However if the GSM/UMTS network looses the connection the associated configuration may change its state     from \l Discovered to \l Defined as well. A similar use case might be triggered by     WLAN availability. QNetworkConfigurationManager::updateConfigurations() can be used to     manually trigger updates of states. Note that some platforms do not require such updates     as they implicitly change the state once it has been discovered. If the state of a     configuration changes all related QNetworkConfiguration instances change their state automatically.      \sa QNetworkSession, QNetworkConfigurationManager */
end_comment
begin_comment
comment|/*!     \enum QNetworkConfiguration::Type      This enum describes the type of configuration.      \value InternetAccessPoint  The configuration specifies the details for a single access point.                                 Note that configurations of type InternetAccessPoint may be part                                 of other QNetworkConfigurations of type ServiceNetwork.     \value ServiceNetwork       The configuration is based on a group of QNetworkConfigurations of                                 type InternetAccessPoint. All group members can reach the same                                 target network. This type of configuration is a mandatory                                 requirement for roaming enabled network sessions. On some                                 platforms this form of configuration may also be called Service                                 Network Access Point (SNAP).     \value UserChoice           The configuration is a placeholder which will be resolved to an                                 actual configuration by the platform when a session is opened. Depending                                 on the platform the selection may generate a popup dialog asking the user                                 for his preferred choice.     \value Invalid              The configuration is invalid. */
end_comment
begin_comment
comment|/*!     \enum QNetworkConfiguration::StateFlag      Specifies the configuration states.      \value Undefined    This state is used for transient configurations such as newly discovered                         WLANs for which the user has not actually created a configuration yet.     \value Defined      Defined configurations are known to the system but are not immediately                         usable (e.g. a configured WLAN is not within range or the Ethernet cable                         is currently not plugged into the machine).     \value Discovered   A discovered configuration can be immediately used to create a new                         QNetworkSession. An example of a discovered configuration could be a WLAN                         which is within in range. If the device moves out of range the discovered                         flag is dropped. A second example is a GPRS configuration which generally                         remains discovered for as long as the device has network coverage. A                         configuration that has this state is also in state                         QNetworkConfiguration::Defined. If the configuration is a service network                         this flag is set if at least one of the underlying access points                         configurations has the Discovered state.     \value Active       The configuration is currently used by an open network session                         (see \l QNetworkSession::isOpen()). However this does not mean that the                         current process is the entity that created the open session. It merely                         indicates that if a new QNetworkSession were to be constructed based on                         this configuration \l QNetworkSession::state() would return                         \l QNetworkSession::Connected. This state implies the                         QNetworkConfiguration::Discovered state. */
end_comment
begin_comment
comment|/*!     \enum QNetworkConfiguration::Purpose      Specifies the purpose of the configuration.      \value UnknownPurpose           The configuration doesn't specify any purpose. This is the default value.     \value PublicPurpose            The configuration can be used for general purpose internet access.     \value PrivatePurpose           The configuration is suitable to access a private network such as an office Intranet.     \value ServiceSpecificPurpose   The configuration can be used for operator specific services (e.g.                                     receiving MMS messages or content streaming). */
end_comment
begin_comment
comment|/*!     \enum QNetworkConfiguration::BearerType      Specifies the type of bearer used by a configuration.      \value BearerUnknown    The type of bearer is unknown or unspecified. The bearerTypeName()                             function may return additional information.     \value BearerEthernet   The configuration is for an Ethernet interfaces.     \value BearerWLAN       The configuration is for a Wireless LAN interface.     \value Bearer2G         The configuration is for a CSD, GPRS, HSCSD, EDGE or cdmaOne interface.     \value Bearer3G         The configuration is for a 3G interface.     \value Bearer4G         The configuration is for a 4G interface.     \value BearerCDMA2000   The configuration is for CDMA interface.     \value BearerWCDMA      The configuration is for W-CDMA/UMTS interface.     \value BearerHSPA       The configuration is for High Speed Packet Access (HSPA) interface.     \value BearerBluetooth  The configuration is for a Bluetooth interface.     \value BearerWiMAX      The configuration is for a WiMAX interface.     \value BearerEVDO       The configuration is for an EVDO (3G) interface.     \value BearerLTE        The configuration is for a LTE (4G) interface. */
end_comment
begin_comment
comment|/*!     Constructs an invalid configuration object.      \sa isValid() */
end_comment
begin_constructor
DECL|function|QNetworkConfiguration
name|QNetworkConfiguration
operator|::
name|QNetworkConfiguration
parameter_list|()
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Creates a copy of the QNetworkConfiguration object contained in \a other. */
end_comment
begin_constructor
DECL|function|QNetworkConfiguration
name|QNetworkConfiguration
operator|::
name|QNetworkConfiguration
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|other
operator|.
name|d
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Frees the resources associated with the QNetworkConfiguration object. */
end_comment
begin_destructor
DECL|function|~QNetworkConfiguration
name|QNetworkConfiguration
operator|::
name|~
name|QNetworkConfiguration
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Copies the content of the QNetworkConfiguration object contained in \a other into this one. */
end_comment
begin_function
DECL|function|operator =
name|QNetworkConfiguration
modifier|&
name|QNetworkConfiguration
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QNetworkConfiguration::swap(QNetworkConfiguration&other)     \since 5.0      Swaps this network configuration with \a other. This function is     very fast and never fails. */
end_comment
begin_comment
comment|/*!     Returns \c true, if this configuration is the same as the \a other     configuration given; otherwise returns \c false. */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QNetworkConfiguration
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|d
operator|==
name|other
operator|.
name|d
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QNetworkConfiguration::operator!=(const QNetworkConfiguration&other) const      Returns \c true if this configuration is not the same as the \a other     configuration given; otherwise returns \c false. */
end_comment
begin_comment
comment|/*!     Returns the user visible name of this configuration.      The name may either be the name of the underlying access point or the     name for service network that this configuration represents. */
end_comment
begin_function
DECL|function|name
name|QString
name|QNetworkConfiguration
operator|::
name|name
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QString
argument_list|()
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|name
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the unique and platform specific identifier for this network configuration;     otherwise an empty string. */
end_comment
begin_function
DECL|function|identifier
name|QString
name|QNetworkConfiguration
operator|::
name|identifier
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QString
argument_list|()
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|id
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the type of the configuration.      A configuration can represent a single access point configuration or     a set of access point configurations. Such a set is called service network.     A configuration that is based on a service network can potentially support     roaming of network sessions. */
end_comment
begin_function
DECL|function|type
name|QNetworkConfiguration
operator|::
name|Type
name|QNetworkConfiguration
operator|::
name|type
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QNetworkConfiguration
operator|::
name|Invalid
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|type
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if this QNetworkConfiguration object is valid.     A configuration may become invalid if the user deletes the configuration or     the configuration was default-constructed.      The addition and removal of configurations can be monitored via the     QNetworkConfigurationManager.      \sa QNetworkConfigurationManager */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QNetworkConfiguration
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|false
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|isValid
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the current state of the configuration. */
end_comment
begin_function
DECL|function|state
name|QNetworkConfiguration
operator|::
name|StateFlags
name|QNetworkConfiguration
operator|::
name|state
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QNetworkConfiguration
operator|::
name|Undefined
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|state
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the purpose of this configuration.      The purpose field may be used to programmatically determine the     purpose of a configuration. Such information is usually part of the     access point or service network meta data. */
end_comment
begin_function
DECL|function|purpose
name|QNetworkConfiguration
operator|::
name|Purpose
name|QNetworkConfiguration
operator|::
name|purpose
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QNetworkConfiguration
operator|::
name|UnknownPurpose
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|purpose
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if this configuration supports roaming; otherwise false. */
end_comment
begin_function
DECL|function|isRoamingAvailable
name|bool
name|QNetworkConfiguration
operator|::
name|isRoamingAvailable
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|false
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|roamingSupported
return|;
block|}
end_function
begin_comment
comment|/*!     Returns all sub configurations of this network configuration in priority order. The first sub     configuration in the list has the highest priority.      Only network configurations of type \l ServiceNetwork can have children. Otherwise this     function returns an empty list. */
end_comment
begin_function
DECL|function|children
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|QNetworkConfiguration
operator|::
name|children
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|results
decl_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|results
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|type
operator|!=
name|QNetworkConfiguration
operator|::
name|ServiceNetwork
operator|||
operator|!
name|d
operator|->
name|isValid
condition|)
return|return
name|results
return|;
name|QMutableMapIterator
argument_list|<
name|unsigned
name|int
argument_list|,
name|QNetworkConfigurationPrivatePointer
argument_list|>
name|i
argument_list|(
name|d
operator|->
name|serviceNetworkMembers
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
name|QNetworkConfigurationPrivatePointer
name|p
init|=
name|i
operator|.
name|value
argument_list|()
decl_stmt|;
comment|//if we have an invalid member get rid of it -> was deleted earlier on
block|{
name|QMutexLocker
name|childLocker
argument_list|(
operator|&
name|p
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|p
operator|->
name|isValid
condition|)
block|{
name|i
operator|.
name|remove
argument_list|()
expr_stmt|;
continue|continue;
block|}
block|}
name|QNetworkConfiguration
name|item
decl_stmt|;
name|item
operator|.
name|d
operator|=
name|p
expr_stmt|;
name|results
operator|<<
name|item
expr_stmt|;
block|}
return|return
name|results
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the type of bearer used by this network configuration.      If the bearer type is \l {QNetworkConfiguration::BearerUnknown}{unknown} the bearerTypeName()     function can be used to retrieve a textural type name for the bearer.      An invalid network configuration always returns the BearerUnknown value.      \sa bearerTypeName(), bearerTypeFamily() */
end_comment
begin_function
DECL|function|bearerType
name|QNetworkConfiguration
operator|::
name|BearerType
name|QNetworkConfiguration
operator|::
name|bearerType
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
name|BearerUnknown
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|bearerType
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.2      Returns the bearer type family used by this network configuration.     The following table lists how bearerType() values map to     bearerTypeFamily() values:      \table         \header             \li bearer type             \li bearer type family         \row             \li BearerUnknown, Bearer2G, BearerEthernet, BearerWLAN,             BearerBluetooth             \li (same type)         \row             \li BearerCDMA2000, BearerEVDO, BearerWCDMA, BearerHSPA, Bearer3G             \li Bearer3G         \row             \li BearerWiMAX, BearerLTE, Bearer4G             \li Bearer4G     \endtable      An invalid network configuration always returns the BearerUnknown value.      \sa bearerType(), bearerTypeName() */
end_comment
begin_function
DECL|function|bearerTypeFamily
name|QNetworkConfiguration
operator|::
name|BearerType
name|QNetworkConfiguration
operator|::
name|bearerTypeFamily
parameter_list|()
specifier|const
block|{
name|QNetworkConfiguration
operator|::
name|BearerType
name|type
init|=
name|bearerType
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QNetworkConfiguration
operator|::
name|BearerUnknown
case|:
comment|// fallthrough
case|case
name|QNetworkConfiguration
operator|::
name|Bearer2G
case|:
comment|// fallthrough
case|case
name|QNetworkConfiguration
operator|::
name|BearerEthernet
case|:
comment|// fallthrough
case|case
name|QNetworkConfiguration
operator|::
name|BearerWLAN
case|:
comment|// fallthrough
case|case
name|QNetworkConfiguration
operator|::
name|BearerBluetooth
case|:
return|return
name|type
return|;
case|case
name|QNetworkConfiguration
operator|::
name|BearerCDMA2000
case|:
comment|// fallthrough
case|case
name|QNetworkConfiguration
operator|::
name|BearerEVDO
case|:
comment|// fallthrough
case|case
name|QNetworkConfiguration
operator|::
name|BearerWCDMA
case|:
comment|// fallthrough
case|case
name|QNetworkConfiguration
operator|::
name|BearerHSPA
case|:
comment|// fallthrough
case|case
name|QNetworkConfiguration
operator|::
name|Bearer3G
case|:
return|return
name|QNetworkConfiguration
operator|::
name|Bearer3G
return|;
case|case
name|QNetworkConfiguration
operator|::
name|BearerWiMAX
case|:
comment|// fallthrough
case|case
name|QNetworkConfiguration
operator|::
name|BearerLTE
case|:
comment|// fallthrough
case|case
name|QNetworkConfiguration
operator|::
name|Bearer4G
case|:
return|return
name|QNetworkConfiguration
operator|::
name|Bearer4G
return|;
default|default:
name|qWarning
argument_list|()
operator|<<
literal|"unknown bearer type"
operator|<<
name|type
expr_stmt|;
return|return
name|QNetworkConfiguration
operator|::
name|BearerUnknown
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the type of bearer used by this network configuration as a string.      The string is not translated and therefore can not be shown to the user. The subsequent table     shows the fixed mappings between BearerType and the bearer type name for known types.  If the     BearerType is unknown this function may return additional information if it is available;     otherwise an empty string will be returned.      \table         \header             \li BearerType             \li Value         \row             \li BearerUnknown             \li The session is based on an unknown or unspecified bearer type. The value of the                string returned describes the bearer type.         \row             \li BearerEthernet             \li Ethernet         \row             \li BearerWLAN             \li WLAN         \row             \li Bearer2G             \li 2G         \row             \li Bearer3G             \li 3G         \row             \li Bearer4G             \li 4G         \row             \li BearerCDMA2000             \li CDMA2000         \row             \li BearerWCDMA             \li WCDMA         \row             \li BearerHSPA             \li HSPA         \row             \li BearerBluetooth             \li Bluetooth         \row             \li BearerWiMAX             \li WiMAX         \row             \li BearerEVDO             \li EVDO         \row             \li BearerLTE             \li LTE     \endtable      This function returns an empty string if this is an invalid configuration, a network     configuration of type \l QNetworkConfiguration::ServiceNetwork or     \l QNetworkConfiguration::UserChoice.      \sa bearerType(), bearerTypeFamily() */
end_comment
begin_function
DECL|function|bearerTypeName
name|QString
name|QNetworkConfiguration
operator|::
name|bearerTypeName
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QNetworkConfiguration
operator|::
name|ServiceNetwork
operator|||
name|d
operator|->
name|type
operator|==
name|QNetworkConfiguration
operator|::
name|UserChoice
condition|)
return|return
name|QString
argument_list|()
return|;
switch|switch
condition|(
name|d
operator|->
name|bearerType
condition|)
block|{
case|case
name|BearerEthernet
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"Ethernet"
argument_list|)
return|;
case|case
name|BearerWLAN
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"WLAN"
argument_list|)
return|;
case|case
name|Bearer2G
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"2G"
argument_list|)
return|;
case|case
name|Bearer3G
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"3G"
argument_list|)
return|;
case|case
name|Bearer4G
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"4G"
argument_list|)
return|;
case|case
name|BearerCDMA2000
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"CDMA2000"
argument_list|)
return|;
case|case
name|BearerWCDMA
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"WCDMA"
argument_list|)
return|;
case|case
name|BearerHSPA
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"HSPA"
argument_list|)
return|;
case|case
name|BearerBluetooth
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"Bluetooth"
argument_list|)
return|;
case|case
name|BearerWiMAX
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"WiMAX"
argument_list|)
return|;
case|case
name|BearerEVDO
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"EVDO"
argument_list|)
return|;
case|case
name|BearerLTE
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"LTE"
argument_list|)
return|;
case|case
name|BearerUnknown
case|:
break|break;
block|}
return|return
name|QStringLiteral
argument_list|(
literal|"Unknown"
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
