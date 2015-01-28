begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCONNMANENGINE_P_H
end_ifndef
begin_define
DECL|macro|QCONNMANENGINE_P_H
define|#
directive|define
name|QCONNMANENGINE_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|"../qbearerengine_impl.h"
end_include
begin_include
include|#
directive|include
file|"qconnmanservice_linux_p.h"
end_include
begin_include
include|#
directive|include
file|"../linux_common/qofonoservice_linux_p.h"
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QConnmanEngine
range|:
name|public
name|QBearerEngineImpl
block|{
name|Q_OBJECT
name|public
operator|:
name|QConnmanEngine
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QConnmanEngine
argument_list|()
block|;
name|bool
name|connmanAvailable
argument_list|()
specifier|const
block|;
name|virtual
name|QString
name|getInterfaceFromId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|bool
name|hasIdentifier
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|virtual
name|void
name|connectToId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|virtual
name|void
name|disconnectFromId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|Q_INVOKABLE
name|void
name|initialize
argument_list|()
block|;
name|Q_INVOKABLE
name|void
name|requestUpdate
argument_list|()
block|;
name|QNetworkSession
operator|::
name|State
name|sessionStateForId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|QNetworkSessionPrivate
operator|*
name|createSessionBackend
argument_list|()
block|;
name|virtual
name|quint64
name|bytesWritten
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|virtual
name|quint64
name|bytesReceived
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|virtual
name|quint64
name|startTime
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|virtual
name|QNetworkConfigurationManager
operator|::
name|Capabilities
name|capabilities
argument_list|()
specifier|const
block|;
name|virtual
name|QNetworkConfigurationPrivatePointer
name|defaultConfiguration
argument_list|()
block|;
name|QList
operator|<
name|QNetworkConfigurationPrivate
operator|*
operator|>
name|getConfigurations
argument_list|()
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|doRequestUpdate
argument_list|()
block|;
name|void
name|updateServices
argument_list|(
specifier|const
name|ConnmanMapList
operator|&
name|changed
argument_list|,
specifier|const
name|QList
operator|<
name|QDBusObjectPath
operator|>
operator|&
name|removed
argument_list|)
block|;
name|void
name|servicesReady
argument_list|(
specifier|const
name|QStringList
operator|&
argument_list|)
block|;
name|void
name|finishedScan
argument_list|()
block|;
name|void
name|changedModem
argument_list|()
block|;
name|void
name|serviceStateChanged
argument_list|(
specifier|const
name|QString
operator|&
name|state
argument_list|)
block|;
name|void
name|configurationChange
argument_list|(
name|QConnmanServiceInterface
operator|*
name|service
argument_list|)
block|;
name|void
name|reEvaluateCellular
argument_list|()
block|;
name|private
operator|:
name|QConnmanManagerInterface
operator|*
name|connmanManager
block|;
name|QOfonoManagerInterface
operator|*
name|ofonoManager
block|;
name|QOfonoNetworkRegistrationInterface
operator|*
name|ofonoNetwork
block|;
name|QOfonoDataConnectionManagerInterface
operator|*
name|ofonoContextManager
block|;
name|QList
operator|<
name|QNetworkConfigurationPrivate
operator|*
operator|>
name|foundConfigurations
block|;
name|QString
name|networkFromId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|QNetworkConfiguration
operator|::
name|StateFlags
name|getStateForService
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|)
block|;
name|QNetworkConfiguration
operator|::
name|BearerType
name|typeToBearer
argument_list|(
specifier|const
name|QString
operator|&
name|type
argument_list|)
block|;
name|void
name|removeConfiguration
argument_list|(
specifier|const
name|QString
operator|&
name|servicePath
argument_list|)
block|;
name|void
name|addServiceConfiguration
argument_list|(
specifier|const
name|QString
operator|&
name|servicePath
argument_list|)
block|;
name|QDateTime
name|activeTime
block|;
name|QMap
operator|<
name|QString
block|,
name|QConnmanTechnologyInterface
operator|*
operator|>
name|technologies
block|;
comment|// techpath, tech interface
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
name|configInterfaces
block|;
comment|// id, interface name
name|QList
operator|<
name|QString
operator|>
name|serviceNetworks
block|;
comment|//servpath
name|QNetworkConfiguration
operator|::
name|BearerType
name|ofonoTechToBearerType
argument_list|(
specifier|const
name|QString
operator|&
name|type
argument_list|)
block|;
name|bool
name|isRoamingAllowed
argument_list|(
specifier|const
name|QString
operator|&
name|context
argument_list|)
block|;
name|QMap
operator|<
name|QString
block|,
name|QConnmanServiceInterface
operator|*
operator|>
name|connmanServiceInterfaces
block|;
name|protected
operator|:
name|bool
name|requiresPolling
argument_list|()
specifier|const
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
comment|// QT_NO_BEARERMANAGEMENT
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
