begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKCONFIGURATIONMANAGER_H
end_ifndef
begin_define
DECL|macro|QNETWORKCONFIGURATIONMANAGER_H
define|#
directive|define
name|QNETWORKCONFIGURATIONMANAGER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkconfiguration.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Network
argument_list|)
name|class
name|QNetworkConfigurationManagerPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkConfigurationManager
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Capability
block|{
name|CanStartAndStopInterfaces
operator|=
literal|0x00000001
block|,
name|DirectConnectionRouting
operator|=
literal|0x00000002
block|,
name|SystemSessionSupport
operator|=
literal|0x00000004
block|,
name|ApplicationLevelRoaming
operator|=
literal|0x00000008
block|,
name|ForcedRoaming
operator|=
literal|0x00000010
block|,
name|DataStatistics
operator|=
literal|0x00000020
block|,
name|NetworkSessionRequired
operator|=
literal|0x00000040
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Capabilities
argument_list|,
argument|Capability
argument_list|)
name|explicit
name|QNetworkConfigurationManager
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QNetworkConfigurationManager
argument_list|()
block|;
name|QNetworkConfigurationManager
operator|::
name|Capabilities
name|capabilities
argument_list|()
specifier|const
block|;
name|QNetworkConfiguration
name|defaultConfiguration
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QNetworkConfiguration
operator|>
name|allConfigurations
argument_list|(
argument|QNetworkConfiguration::StateFlags flags =
literal|0
argument_list|)
specifier|const
block|;
name|QNetworkConfiguration
name|configurationFromIdentifier
argument_list|(
argument|const QString&identifier
argument_list|)
specifier|const
block|;
name|bool
name|isOnline
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|updateConfigurations
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|configurationAdded
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
name|config
argument_list|)
block|;
name|void
name|configurationRemoved
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
name|config
argument_list|)
block|;
name|void
name|configurationChanged
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
name|config
argument_list|)
block|;
name|void
name|onlineStateChanged
argument_list|(
argument|bool isOnline
argument_list|)
block|;
name|void
name|updateCompleted
argument_list|()
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QNetworkConfigurationManager
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QNetworkConfigurationManager::Capabilities
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
comment|// QT_NO_BEARERMANAGEMENT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QNETWORKCONFIGURATIONMANAGER_H
end_comment
end_unit
