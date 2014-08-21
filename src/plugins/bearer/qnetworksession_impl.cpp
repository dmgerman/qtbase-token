begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworksession_impl.h"
end_include
begin_include
include|#
directive|include
file|"qbearerengine_impl.h"
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworksession.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/private/qnetworkconfigmanager_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|getEngineFromId
specifier|static
name|QBearerEngineImpl
modifier|*
name|getEngineFromId
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
name|QNetworkConfigurationManagerPrivate
modifier|*
name|priv
init|=
name|qNetworkConfigurationManagerPrivate
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QBearerEngine
modifier|*
name|engine
decl|,
name|priv
operator|->
name|engines
argument_list|()
control|)
block|{
name|QBearerEngineImpl
modifier|*
name|engineImpl
init|=
name|qobject_cast
argument_list|<
name|QBearerEngineImpl
operator|*
argument_list|>
argument_list|(
name|engine
argument_list|)
decl_stmt|;
if|if
condition|(
name|engineImpl
operator|&&
name|engineImpl
operator|->
name|hasIdentifier
argument_list|(
name|id
argument_list|)
condition|)
return|return
name|engineImpl
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_class
DECL|class|QNetworkSessionManagerPrivate
class|class
name|QNetworkSessionManagerPrivate
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|QNetworkSessionManagerPrivate
name|QNetworkSessionManagerPrivate
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{}
DECL|function|~QNetworkSessionManagerPrivate
name|~
name|QNetworkSessionManagerPrivate
parameter_list|()
block|{}
DECL|function|forceSessionClose
specifier|inline
name|void
name|forceSessionClose
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|)
block|{
emit|emit
name|forcedSessionClose
argument_list|(
name|config
argument_list|)
emit|;
block|}
name|Q_SIGNALS
label|:
name|void
name|forcedSessionClose
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_include
include|#
directive|include
file|"qnetworksession_impl.moc"
end_include
begin_expr_stmt
name|Q_GLOBAL_STATIC
argument_list|(
name|QNetworkSessionManagerPrivate
argument_list|,
name|sessionManager
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|syncStateWithInterface
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|syncStateWithInterface
parameter_list|()
block|{
name|connect
argument_list|(
name|sessionManager
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|forcedSessionClose
argument_list|(
name|QNetworkConfiguration
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|forcedSessionClose
argument_list|(
name|QNetworkConfiguration
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|opened
operator|=
literal|false
expr_stmt|;
name|isOpen
operator|=
literal|false
expr_stmt|;
name|state
operator|=
name|QNetworkSession
operator|::
name|Invalid
expr_stmt|;
name|lastError
operator|=
name|QNetworkSession
operator|::
name|UnknownSessionError
expr_stmt|;
name|qRegisterMetaType
argument_list|<
name|QBearerEngineImpl
operator|::
name|ConnectionError
argument_list|>
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|publicConfig
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QNetworkConfiguration
operator|::
name|InternetAccessPoint
case|:
name|activeConfig
operator|=
name|publicConfig
expr_stmt|;
name|engine
operator|=
name|getEngineFromId
argument_list|(
name|activeConfig
operator|.
name|identifier
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|engine
condition|)
block|{
name|qRegisterMetaType
argument_list|<
name|QNetworkConfigurationPrivatePointer
argument_list|>
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|engine
argument_list|,
name|SIGNAL
argument_list|(
name|configurationChanged
argument_list|(
name|QNetworkConfigurationPrivatePointer
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|configurationChanged
argument_list|(
name|QNetworkConfigurationPrivatePointer
argument_list|)
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|engine
argument_list|,
name|SIGNAL
argument_list|(
name|connectionError
argument_list|(
name|QString
argument_list|,
name|QBearerEngineImpl
operator|::
name|ConnectionError
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|connectionError
argument_list|(
name|QString
argument_list|,
name|QBearerEngineImpl
operator|::
name|ConnectionError
argument_list|)
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|QNetworkConfiguration
operator|::
name|ServiceNetwork
case|:
name|serviceConfig
operator|=
name|publicConfig
expr_stmt|;
comment|// Defer setting engine and signals until open().
comment|// fall through
case|case
name|QNetworkConfiguration
operator|::
name|UserChoice
case|:
comment|// Defer setting serviceConfig and activeConfig until open().
comment|// fall through
default|default:
name|engine
operator|=
literal|0
expr_stmt|;
block|}
name|networkConfigurationsChanged
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|open
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|open
parameter_list|()
block|{
if|if
condition|(
name|serviceConfig
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|lastError
operator|=
name|QNetworkSession
operator|::
name|OperationNotSupportedError
expr_stmt|;
emit|emit
name|QNetworkSessionPrivate
operator|::
name|error
argument_list|(
name|lastError
argument_list|)
emit|;
block|}
elseif|else
if|if
condition|(
operator|!
name|isOpen
condition|)
block|{
if|if
condition|(
operator|(
name|activeConfig
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Discovered
operator|)
operator|!=
name|QNetworkConfiguration
operator|::
name|Discovered
condition|)
block|{
name|lastError
operator|=
name|QNetworkSession
operator|::
name|InvalidConfigurationError
expr_stmt|;
name|state
operator|=
name|QNetworkSession
operator|::
name|Invalid
expr_stmt|;
emit|emit
name|stateChanged
argument_list|(
name|state
argument_list|)
emit|;
emit|emit
name|QNetworkSessionPrivate
operator|::
name|error
argument_list|(
name|lastError
argument_list|)
emit|;
return|return;
block|}
name|opened
operator|=
literal|true
expr_stmt|;
if|if
condition|(
operator|(
name|activeConfig
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Active
operator|)
operator|!=
name|QNetworkConfiguration
operator|::
name|Active
operator|&&
operator|(
name|activeConfig
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Discovered
operator|)
operator|==
name|QNetworkConfiguration
operator|::
name|Discovered
condition|)
block|{
name|state
operator|=
name|QNetworkSession
operator|::
name|Connecting
expr_stmt|;
emit|emit
name|stateChanged
argument_list|(
name|state
argument_list|)
emit|;
name|engine
operator|->
name|connectToId
argument_list|(
name|activeConfig
operator|.
name|identifier
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|isOpen
operator|=
operator|(
name|activeConfig
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Active
operator|)
operator|==
name|QNetworkConfiguration
operator|::
name|Active
expr_stmt|;
if|if
condition|(
name|isOpen
condition|)
emit|emit
name|quitPendingWaitsForOpened
argument_list|()
emit|;
block|}
block|}
end_function
begin_function
DECL|function|close
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|close
parameter_list|()
block|{
if|if
condition|(
name|serviceConfig
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|lastError
operator|=
name|QNetworkSession
operator|::
name|OperationNotSupportedError
expr_stmt|;
emit|emit
name|QNetworkSessionPrivate
operator|::
name|error
argument_list|(
name|lastError
argument_list|)
emit|;
block|}
elseif|else
if|if
condition|(
name|isOpen
condition|)
block|{
name|opened
operator|=
literal|false
expr_stmt|;
name|isOpen
operator|=
literal|false
expr_stmt|;
emit|emit
name|closed
argument_list|()
emit|;
block|}
block|}
end_function
begin_function
DECL|function|stop
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|stop
parameter_list|()
block|{
if|if
condition|(
name|serviceConfig
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|lastError
operator|=
name|QNetworkSession
operator|::
name|OperationNotSupportedError
expr_stmt|;
emit|emit
name|QNetworkSessionPrivate
operator|::
name|error
argument_list|(
name|lastError
argument_list|)
emit|;
block|}
else|else
block|{
if|if
condition|(
operator|(
name|activeConfig
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Active
operator|)
operator|==
name|QNetworkConfiguration
operator|::
name|Active
condition|)
block|{
name|state
operator|=
name|QNetworkSession
operator|::
name|Closing
expr_stmt|;
emit|emit
name|stateChanged
argument_list|(
name|state
argument_list|)
emit|;
name|engine
operator|->
name|disconnectFromId
argument_list|(
name|activeConfig
operator|.
name|identifier
argument_list|()
argument_list|)
expr_stmt|;
name|sessionManager
argument_list|()
operator|->
name|forceSessionClose
argument_list|(
name|activeConfig
argument_list|)
expr_stmt|;
block|}
name|opened
operator|=
literal|false
expr_stmt|;
name|isOpen
operator|=
literal|false
expr_stmt|;
emit|emit
name|closed
argument_list|()
emit|;
block|}
block|}
end_function
begin_function
DECL|function|migrate
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|migrate
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|accept
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|accept
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|ignore
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|ignore
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|reject
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|reject
parameter_list|()
block|{ }
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
end_ifndef
begin_function
DECL|function|currentInterface
name|QNetworkInterface
name|QNetworkSessionPrivateImpl
operator|::
name|currentInterface
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|engine
operator|||
name|state
operator|!=
name|QNetworkSession
operator|::
name|Connected
operator|||
operator|!
name|publicConfig
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QNetworkInterface
argument_list|()
return|;
name|QString
name|interface
init|=
name|engine
operator|->
name|getInterfaceFromId
argument_list|(
name|activeConfig
operator|.
name|identifier
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|interface
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QNetworkInterface
argument_list|()
return|;
return|return
name|QNetworkInterface
operator|::
name|interfaceFromName
argument_list|(
name|interface
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|sessionProperty
name|QVariant
name|QNetworkSessionPrivateImpl
operator|::
name|sessionProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|key
operator|==
name|QLatin1String
argument_list|(
literal|"AutoCloseSessionTimeout"
argument_list|)
condition|)
block|{
if|if
condition|(
name|engine
operator|&&
name|engine
operator|->
name|requiresPolling
argument_list|()
operator|&&
operator|!
operator|(
name|engine
operator|->
name|capabilities
argument_list|()
operator|&
name|QNetworkConfigurationManager
operator|::
name|CanStartAndStopInterfaces
operator|)
condition|)
block|{
return|return
name|sessionTimeout
operator|>=
literal|0
condition|?
name|sessionTimeout
operator|*
literal|10000
else|:
operator|-
literal|1
return|;
block|}
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setSessionProperty
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|setSessionProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|key
operator|==
name|QLatin1String
argument_list|(
literal|"AutoCloseSessionTimeout"
argument_list|)
condition|)
block|{
if|if
condition|(
name|engine
operator|&&
name|engine
operator|->
name|requiresPolling
argument_list|()
operator|&&
operator|!
operator|(
name|engine
operator|->
name|capabilities
argument_list|()
operator|&
name|QNetworkConfigurationManager
operator|::
name|CanStartAndStopInterfaces
operator|)
condition|)
block|{
name|int
name|timeout
init|=
name|value
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|timeout
operator|>=
literal|0
condition|)
block|{
name|connect
argument_list|(
name|engine
argument_list|,
name|SIGNAL
argument_list|(
name|updateCompleted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|decrementTimeout
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|UniqueConnection
argument_list|)
expr_stmt|;
name|sessionTimeout
operator|=
name|timeout
operator|/
literal|10000
expr_stmt|;
comment|// convert to poll intervals
block|}
else|else
block|{
name|disconnect
argument_list|(
name|engine
argument_list|,
name|SIGNAL
argument_list|(
name|updateCompleted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|decrementTimeout
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|sessionTimeout
operator|=
operator|-
literal|1
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|errorString
name|QString
name|QNetworkSessionPrivateImpl
operator|::
name|errorString
parameter_list|()
specifier|const
block|{
switch|switch
condition|(
name|lastError
condition|)
block|{
case|case
name|QNetworkSession
operator|::
name|UnknownSessionError
case|:
return|return
name|tr
argument_list|(
literal|"Unknown session error."
argument_list|)
return|;
case|case
name|QNetworkSession
operator|::
name|SessionAbortedError
case|:
return|return
name|tr
argument_list|(
literal|"The session was aborted by the user or system."
argument_list|)
return|;
case|case
name|QNetworkSession
operator|::
name|OperationNotSupportedError
case|:
return|return
name|tr
argument_list|(
literal|"The requested operation is not supported by the system."
argument_list|)
return|;
case|case
name|QNetworkSession
operator|::
name|InvalidConfigurationError
case|:
return|return
name|tr
argument_list|(
literal|"The specified configuration cannot be used."
argument_list|)
return|;
case|case
name|QNetworkSession
operator|::
name|RoamingError
case|:
return|return
name|tr
argument_list|(
literal|"Roaming was aborted or is not possible."
argument_list|)
return|;
default|default:
break|break;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|error
name|QNetworkSession
operator|::
name|SessionError
name|QNetworkSessionPrivateImpl
operator|::
name|error
parameter_list|()
specifier|const
block|{
return|return
name|lastError
return|;
block|}
end_function
begin_function
DECL|function|bytesWritten
name|quint64
name|QNetworkSessionPrivateImpl
operator|::
name|bytesWritten
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|engine
operator|&&
name|state
operator|==
name|QNetworkSession
operator|::
name|Connected
condition|)
return|return
name|engine
operator|->
name|bytesWritten
argument_list|(
name|activeConfig
operator|.
name|identifier
argument_list|()
argument_list|)
return|;
return|return
name|Q_UINT64_C
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|bytesReceived
name|quint64
name|QNetworkSessionPrivateImpl
operator|::
name|bytesReceived
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|engine
operator|&&
name|state
operator|==
name|QNetworkSession
operator|::
name|Connected
condition|)
return|return
name|engine
operator|->
name|bytesReceived
argument_list|(
name|activeConfig
operator|.
name|identifier
argument_list|()
argument_list|)
return|;
return|return
name|Q_UINT64_C
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|activeTime
name|quint64
name|QNetworkSessionPrivateImpl
operator|::
name|activeTime
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|state
operator|==
name|QNetworkSession
operator|::
name|Connected
operator|&&
name|startTime
operator|!=
name|Q_UINT64_C
argument_list|(
literal|0
argument_list|)
condition|)
return|return
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
operator|.
name|toTime_t
argument_list|()
operator|-
name|startTime
return|;
return|return
name|Q_UINT64_C
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|usagePolicies
name|QNetworkSession
operator|::
name|UsagePolicies
name|QNetworkSessionPrivateImpl
operator|::
name|usagePolicies
parameter_list|()
specifier|const
block|{
return|return
name|currentPolicies
return|;
block|}
end_function
begin_function
DECL|function|setUsagePolicies
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|setUsagePolicies
parameter_list|(
name|QNetworkSession
operator|::
name|UsagePolicies
name|newPolicies
parameter_list|)
block|{
if|if
condition|(
name|newPolicies
operator|!=
name|currentPolicies
condition|)
block|{
name|currentPolicies
operator|=
name|newPolicies
expr_stmt|;
emit|emit
name|usagePoliciesChanged
argument_list|(
name|currentPolicies
argument_list|)
emit|;
block|}
block|}
end_function
begin_function
DECL|function|updateStateFromServiceNetwork
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|updateStateFromServiceNetwork
parameter_list|()
block|{
name|QNetworkSession
operator|::
name|State
name|oldState
init|=
name|state
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
decl|,
name|serviceConfig
operator|.
name|children
argument_list|()
control|)
block|{
if|if
condition|(
operator|(
name|config
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Active
operator|)
operator|!=
name|QNetworkConfiguration
operator|::
name|Active
condition|)
continue|continue;
if|if
condition|(
name|activeConfig
operator|!=
name|config
condition|)
block|{
if|if
condition|(
name|engine
condition|)
block|{
name|disconnect
argument_list|(
name|engine
argument_list|,
name|SIGNAL
argument_list|(
name|connectionError
argument_list|(
name|QString
argument_list|,
name|QBearerEngineImpl
operator|::
name|ConnectionError
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|connectionError
argument_list|(
name|QString
argument_list|,
name|QBearerEngineImpl
operator|::
name|ConnectionError
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|activeConfig
operator|=
name|config
expr_stmt|;
name|engine
operator|=
name|getEngineFromId
argument_list|(
name|activeConfig
operator|.
name|identifier
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|engine
condition|)
block|{
name|connect
argument_list|(
name|engine
argument_list|,
name|SIGNAL
argument_list|(
name|connectionError
argument_list|(
name|QString
argument_list|,
name|QBearerEngineImpl
operator|::
name|ConnectionError
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|connectionError
argument_list|(
name|QString
argument_list|,
name|QBearerEngineImpl
operator|::
name|ConnectionError
argument_list|)
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
emit|emit
name|newConfigurationActivated
argument_list|()
emit|;
block|}
name|state
operator|=
name|QNetworkSession
operator|::
name|Connected
expr_stmt|;
if|if
condition|(
name|state
operator|!=
name|oldState
condition|)
emit|emit
name|stateChanged
argument_list|(
name|state
argument_list|)
emit|;
return|return;
block|}
if|if
condition|(
name|serviceConfig
operator|.
name|children
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|state
operator|=
name|QNetworkSession
operator|::
name|NotAvailable
expr_stmt|;
else|else
name|state
operator|=
name|QNetworkSession
operator|::
name|Disconnected
expr_stmt|;
if|if
condition|(
name|state
operator|!=
name|oldState
condition|)
emit|emit
name|stateChanged
argument_list|(
name|state
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|updateStateFromActiveConfig
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|updateStateFromActiveConfig
parameter_list|()
block|{
if|if
condition|(
operator|!
name|engine
condition|)
return|return;
name|QNetworkSession
operator|::
name|State
name|oldState
init|=
name|state
decl_stmt|;
name|state
operator|=
name|engine
operator|->
name|sessionStateForId
argument_list|(
name|activeConfig
operator|.
name|identifier
argument_list|()
argument_list|)
expr_stmt|;
name|bool
name|oldActive
init|=
name|isOpen
decl_stmt|;
name|isOpen
operator|=
operator|(
name|state
operator|==
name|QNetworkSession
operator|::
name|Connected
operator|)
condition|?
name|opened
else|:
literal|false
expr_stmt|;
if|if
condition|(
operator|!
name|oldActive
operator|&&
name|isOpen
condition|)
emit|emit
name|quitPendingWaitsForOpened
argument_list|()
emit|;
if|if
condition|(
name|oldActive
operator|&&
operator|!
name|isOpen
condition|)
emit|emit
name|closed
argument_list|()
emit|;
if|if
condition|(
name|oldState
operator|!=
name|state
condition|)
emit|emit
name|stateChanged
argument_list|(
name|state
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|networkConfigurationsChanged
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|networkConfigurationsChanged
parameter_list|()
block|{
if|if
condition|(
name|serviceConfig
operator|.
name|isValid
argument_list|()
condition|)
name|updateStateFromServiceNetwork
argument_list|()
expr_stmt|;
else|else
name|updateStateFromActiveConfig
argument_list|()
expr_stmt|;
name|startTime
operator|=
name|engine
operator|->
name|startTime
argument_list|(
name|activeConfig
operator|.
name|identifier
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|configurationChanged
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|configurationChanged
parameter_list|(
name|QNetworkConfigurationPrivatePointer
name|config
parameter_list|)
block|{
if|if
condition|(
name|serviceConfig
operator|.
name|isValid
argument_list|()
operator|&&
operator|(
name|config
operator|->
name|id
operator|==
name|serviceConfig
operator|.
name|identifier
argument_list|()
operator|||
name|config
operator|->
name|id
operator|==
name|activeConfig
operator|.
name|identifier
argument_list|()
operator|)
condition|)
block|{
name|updateStateFromServiceNetwork
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|config
operator|->
name|id
operator|==
name|activeConfig
operator|.
name|identifier
argument_list|()
condition|)
block|{
name|updateStateFromActiveConfig
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|forcedSessionClose
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|forcedSessionClose
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|)
block|{
if|if
condition|(
name|activeConfig
operator|==
name|config
condition|)
block|{
name|opened
operator|=
literal|false
expr_stmt|;
name|isOpen
operator|=
literal|false
expr_stmt|;
emit|emit
name|closed
argument_list|()
emit|;
name|lastError
operator|=
name|QNetworkSession
operator|::
name|SessionAbortedError
expr_stmt|;
emit|emit
name|QNetworkSessionPrivate
operator|::
name|error
argument_list|(
name|lastError
argument_list|)
emit|;
block|}
block|}
end_function
begin_function
DECL|function|connectionError
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|connectionError
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|,
name|QBearerEngineImpl
operator|::
name|ConnectionError
name|error
parameter_list|)
block|{
if|if
condition|(
name|activeConfig
operator|.
name|identifier
argument_list|()
operator|==
name|id
condition|)
block|{
name|networkConfigurationsChanged
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|error
condition|)
block|{
case|case
name|QBearerEngineImpl
operator|::
name|OperationNotSupported
case|:
name|lastError
operator|=
name|QNetworkSession
operator|::
name|OperationNotSupportedError
expr_stmt|;
name|opened
operator|=
literal|false
expr_stmt|;
break|break;
case|case
name|QBearerEngineImpl
operator|::
name|InterfaceLookupError
case|:
case|case
name|QBearerEngineImpl
operator|::
name|ConnectError
case|:
case|case
name|QBearerEngineImpl
operator|::
name|DisconnectionError
case|:
default|default:
name|lastError
operator|=
name|QNetworkSession
operator|::
name|UnknownSessionError
expr_stmt|;
block|}
emit|emit
name|QNetworkSessionPrivate
operator|::
name|error
argument_list|(
name|lastError
argument_list|)
emit|;
block|}
block|}
end_function
begin_function
DECL|function|decrementTimeout
name|void
name|QNetworkSessionPrivateImpl
operator|::
name|decrementTimeout
parameter_list|()
block|{
if|if
condition|(
operator|--
name|sessionTimeout
operator|<=
literal|0
condition|)
block|{
name|disconnect
argument_list|(
name|engine
argument_list|,
name|SIGNAL
argument_list|(
name|updateCompleted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|decrementTimeout
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|sessionTimeout
operator|=
operator|-
literal|1
expr_stmt|;
name|close
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BEARERMANAGEMENT
end_comment
end_unit
