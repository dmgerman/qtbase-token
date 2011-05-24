begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKSESSIONPRIVATE_H
end_ifndef
begin_define
DECL|macro|QNETWORKSESSIONPRIVATE_H
define|#
directive|define
name|QNETWORKSESSIONPRIVATE_H
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
file|"qnetworksession.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkconfiguration_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qsharedpointer.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_decl_stmt
DECL|variable|RConnection
name|class
name|RConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|RSocket
name|class
name|RSocket
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|RHostResolver
name|class
name|RHostResolver
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_NETWORK_EXPORT
name|QNetworkSessionPrivate
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|friend
name|class
name|QNetworkSession
block|;
name|public
operator|:
name|QNetworkSessionPrivate
argument_list|()
operator|:
name|QObject
argument_list|()
block|,
name|state
argument_list|(
name|QNetworkSession
operator|::
name|Invalid
argument_list|)
block|,
name|isOpen
argument_list|(
name|false
argument_list|)
block|,
name|mutex
argument_list|(
argument|QMutex::Recursive
argument_list|)
block|{}
name|virtual
operator|~
name|QNetworkSessionPrivate
argument_list|()
block|{}
comment|//called by QNetworkSession constructor and ensures
comment|//that the state is immediately updated (w/o actually opening
comment|//a session). Also this function should take care of
comment|//notification hooks to discover future state changes.
name|virtual
name|void
name|syncStateWithInterface
argument_list|()
operator|=
literal|0
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
name|virtual
name|QNetworkInterface
name|currentInterface
argument_list|()
specifier|const
operator|=
literal|0
block|;
endif|#
directive|endif
name|virtual
name|QVariant
name|sessionProperty
argument_list|(
argument|const QString&key
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
name|void
name|open
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|close
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|stop
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|setALREnabled
argument_list|(
argument|bool
comment|/*enabled*/
argument_list|)
block|{}
name|virtual
name|void
name|migrate
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|accept
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|ignore
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|reject
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|QString
name|errorString
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|//must return translated string
name|virtual
name|QNetworkSession
operator|::
name|SessionError
name|error
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|quint64
name|bytesWritten
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|quint64
name|bytesReceived
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|quint64
name|activeTime
argument_list|()
specifier|const
operator|=
literal|0
block|;
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
comment|// get internal RConnection (not thread safe, call only from thread that owns the QNetworkSession)
specifier|static
name|RConnection
operator|*
name|nativeSession
argument_list|(
name|QNetworkSession
operator|&
argument_list|)
block|;
name|virtual
name|RConnection
operator|*
name|nativeSession
argument_list|()
operator|=
literal|0
block|;
comment|// open socket using the internal RConnection (thread safe)
specifier|static
name|TInt
name|nativeOpenSocket
argument_list|(
argument|QNetworkSession& session
argument_list|,
argument|RSocket& socket
argument_list|,
argument|TUint family
argument_list|,
argument|TUint type
argument_list|,
argument|TUint protocol
argument_list|)
block|;
comment|// open host resolver using the internal RConnection (thread safe)
specifier|static
name|TInt
name|nativeOpenHostResolver
argument_list|(
argument|QNetworkSession& session
argument_list|,
argument|RHostResolver& resolver
argument_list|,
argument|TUint family
argument_list|,
argument|TUint protocol
argument_list|)
block|;
endif|#
directive|endif
name|protected
operator|:
specifier|inline
name|QNetworkConfigurationPrivatePointer
name|privateConfiguration
argument_list|(
argument|const QNetworkConfiguration&config
argument_list|)
specifier|const
block|{
return|return
name|config
operator|.
name|d
return|;
block|}
specifier|inline
name|void
name|setPrivateConfiguration
argument_list|(
argument|QNetworkConfiguration&config
argument_list|,
argument|QNetworkConfigurationPrivatePointer ptr
argument_list|)
specifier|const
block|{
name|config
operator|.
name|d
operator|=
name|ptr
block|;     }
name|Q_SIGNALS
operator|:
comment|//releases any pending waitForOpened() calls
name|void
name|quitPendingWaitsForOpened
argument_list|()
block|;
name|void
name|error
argument_list|(
argument|QNetworkSession::SessionError error
argument_list|)
block|;
name|void
name|stateChanged
argument_list|(
argument|QNetworkSession::State state
argument_list|)
block|;
name|void
name|closed
argument_list|()
block|;
name|void
name|newConfigurationActivated
argument_list|()
block|;
name|void
name|preferredConfigurationChanged
argument_list|(
argument|const QNetworkConfiguration&config
argument_list|,
argument|bool isSeamless
argument_list|)
block|;
name|protected
operator|:
name|QNetworkSession
operator|*
name|q
block|;
comment|// The config set on QNetworkSession.
name|QNetworkConfiguration
name|publicConfig
block|;
comment|// If publicConfig is a ServiceNetwork this is a copy of publicConfig.
comment|// If publicConfig is an UserChoice that is resolved to a ServiceNetwork this is the actual
comment|// ServiceNetwork configuration.
name|QNetworkConfiguration
name|serviceConfig
block|;
comment|// This is the actual active configuration currently in use by the session.
comment|// Either a copy of publicConfig or one of serviceConfig.children().
name|QNetworkConfiguration
name|activeConfig
block|;
name|QNetworkSession
operator|::
name|State
name|state
block|;
name|bool
name|isOpen
block|;
name|QMutex
name|mutex
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QSharedPointer
operator|<
name|QNetworkSession
operator|>
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
comment|// QNETWORKSESSIONPRIVATE_H
end_comment
end_unit
