begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKSESSION_H
end_ifndef
begin_define
DECL|macro|QNETWORKSESSION_H
define|#
directive|define
name|QNETWORKSESSION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkinterface.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
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
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
name|defined
argument_list|(
name|interface
argument_list|)
end_if
begin_undef
DECL|macro|interface
undef|#
directive|undef
name|interface
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QNetworkSessionPrivate
name|class
name|QNetworkSessionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkSession
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|State
block|{
name|Invalid
operator|=
literal|0
block|,
name|NotAvailable
block|,
name|Connecting
block|,
name|Connected
block|,
name|Closing
block|,
name|Disconnected
block|,
name|Roaming
block|}
block|;      enum
name|SessionError
block|{
name|UnknownSessionError
operator|=
literal|0
block|,
name|SessionAbortedError
block|,
name|RoamingError
block|,
name|OperationNotSupportedError
block|,
name|InvalidConfigurationError
block|}
block|;      enum
name|UsagePolicy
block|{
name|NoPolicy
operator|=
literal|0
block|,
name|NoBackgroundTrafficPolicy
operator|=
literal|1
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|UsagePolicies
argument_list|,
argument|UsagePolicy
argument_list|)
name|explicit
name|QNetworkSession
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
name|connConfig
argument_list|,
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|virtual
operator|~
name|QNetworkSession
argument_list|()
block|;
name|bool
name|isOpen
argument_list|()
specifier|const
block|;
name|QNetworkConfiguration
name|configuration
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
name|QNetworkInterface
name|interface
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|State
name|state
argument_list|()
specifier|const
block|;
name|SessionError
name|error
argument_list|()
specifier|const
block|;
name|QString
name|errorString
argument_list|()
specifier|const
block|;
name|QVariant
name|sessionProperty
argument_list|(
argument|const QString&key
argument_list|)
specifier|const
block|;
name|void
name|setSessionProperty
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
block|;
name|quint64
name|bytesWritten
argument_list|()
specifier|const
block|;
name|quint64
name|bytesReceived
argument_list|()
specifier|const
block|;
name|quint64
name|activeTime
argument_list|()
specifier|const
block|;
name|QNetworkSession
operator|::
name|UsagePolicies
name|usagePolicies
argument_list|()
specifier|const
block|;
name|bool
name|waitForOpened
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|open
argument_list|()
block|;
name|void
name|close
argument_list|()
block|;
name|void
name|stop
argument_list|()
block|;
comment|//roaming related slots
name|void
name|migrate
argument_list|()
block|;
name|void
name|ignore
argument_list|()
block|;
name|void
name|accept
argument_list|()
block|;
name|void
name|reject
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|stateChanged
argument_list|(
name|QNetworkSession
operator|::
name|State
argument_list|)
block|;
name|void
name|opened
argument_list|()
block|;
name|void
name|closed
argument_list|()
block|;
name|void
name|error
argument_list|(
name|QNetworkSession
operator|::
name|SessionError
argument_list|)
block|;
name|void
name|preferredConfigurationChanged
argument_list|(
argument|const QNetworkConfiguration&config
argument_list|,
argument|bool isSeamless
argument_list|)
block|;
name|void
name|newConfigurationActivated
argument_list|()
block|;
name|void
name|usagePoliciesChanged
argument_list|(
argument|QNetworkSession::UsagePolicies usagePolicies
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|connectNotify
argument_list|(
argument|const QMetaMethod&signal
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|disconnectNotify
argument_list|(
argument|const QMetaMethod&signal
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QNetworkSession
argument_list|)
name|friend
name|class
name|QNetworkSessionPrivate
block|;
name|QNetworkSessionPrivate
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QNetworkSession
operator|::
name|State
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QNetworkSession
operator|::
name|SessionError
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QNetworkSession
operator|::
name|UsagePolicies
argument_list|)
end_decl_stmt
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
comment|// QNETWORKSESSION_H
end_comment
end_unit
