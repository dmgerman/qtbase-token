begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkaccessbackend_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkaccessmanager_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkconfigmanager.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkrequest.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkreply.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkreply_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmutex.h"
end_include
begin_include
include|#
directive|include
file|"QtNetwork/private/qnetworksession_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkaccesscachebackend_p.h"
end_include
begin_include
include|#
directive|include
file|"qabstractnetworkcache.h"
end_include
begin_include
include|#
directive|include
file|"qhostinfo.h"
end_include
begin_include
include|#
directive|include
file|"private/qnoncontiguousbytedevice_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QNetworkAccessBackendFactoryData
class|class
name|QNetworkAccessBackendFactoryData
super|:
specifier|public
name|QList
argument_list|<
name|QNetworkAccessBackendFactory
modifier|*
argument_list|>
block|{
public|public:
DECL|function|QNetworkAccessBackendFactoryData
name|QNetworkAccessBackendFactoryData
parameter_list|()
member_init_list|:
name|mutex
argument_list|(
name|QMutex
operator|::
name|Recursive
argument_list|)
block|{
name|valid
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
DECL|function|~QNetworkAccessBackendFactoryData
name|~
name|QNetworkAccessBackendFactoryData
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
comment|// why do we need to lock?
name|valid
operator|.
name|deref
argument_list|()
expr_stmt|;
block|}
DECL|member|mutex
name|QMutex
name|mutex
decl_stmt|;
comment|//this is used to avoid (re)constructing factory data from destructors of other global classes
DECL|member|valid
specifier|static
name|QBasicAtomicInt
name|valid
decl_stmt|;
block|}
class|;
end_class
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QNetworkAccessBackendFactoryData
argument_list|,
argument|factoryData
argument_list|)
end_macro
begin_decl_stmt
DECL|member|valid
name|QBasicAtomicInt
name|QNetworkAccessBackendFactoryData
operator|::
name|valid
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QNetworkAccessBackendFactory
name|QNetworkAccessBackendFactory
operator|::
name|QNetworkAccessBackendFactory
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|factoryData
argument_list|()
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|factoryData
argument_list|()
operator|->
name|append
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QNetworkAccessBackendFactory
name|QNetworkAccessBackendFactory
operator|::
name|~
name|QNetworkAccessBackendFactory
parameter_list|()
block|{
if|if
condition|(
name|QNetworkAccessBackendFactoryData
operator|::
name|valid
operator|.
name|load
argument_list|()
condition|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|factoryData
argument_list|()
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|factoryData
argument_list|()
operator|->
name|removeAll
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|findBackend
name|QNetworkAccessBackend
modifier|*
name|QNetworkAccessManagerPrivate
operator|::
name|findBackend
parameter_list|(
name|QNetworkAccessManager
operator|::
name|Operation
name|op
parameter_list|,
specifier|const
name|QNetworkRequest
modifier|&
name|request
parameter_list|)
block|{
if|if
condition|(
name|QNetworkAccessBackendFactoryData
operator|::
name|valid
operator|.
name|load
argument_list|()
condition|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|factoryData
argument_list|()
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|QNetworkAccessBackendFactoryData
operator|::
name|ConstIterator
name|it
init|=
name|factoryData
argument_list|()
operator|->
name|constBegin
argument_list|()
decl_stmt|,
name|end
init|=
name|factoryData
argument_list|()
operator|->
name|constEnd
argument_list|()
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|end
condition|)
block|{
name|QNetworkAccessBackend
modifier|*
name|backend
init|=
operator|(
operator|*
name|it
operator|)
operator|->
name|create
argument_list|(
name|op
argument_list|,
name|request
argument_list|)
decl_stmt|;
if|if
condition|(
name|backend
condition|)
block|{
name|backend
operator|->
name|manager
operator|=
name|this
expr_stmt|;
return|return
name|backend
return|;
comment|// found a factory that handled our request
block|}
operator|++
name|it
expr_stmt|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createUploadByteDevice
name|QNonContiguousByteDevice
modifier|*
name|QNetworkAccessBackend
operator|::
name|createUploadByteDevice
parameter_list|()
block|{
if|if
condition|(
name|reply
operator|->
name|outgoingDataBuffer
condition|)
name|uploadByteDevice
operator|=
name|QSharedPointer
argument_list|<
name|QNonContiguousByteDevice
argument_list|>
argument_list|(
name|QNonContiguousByteDeviceFactory
operator|::
name|create
argument_list|(
name|reply
operator|->
name|outgoingDataBuffer
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|reply
operator|->
name|outgoingData
condition|)
block|{
name|uploadByteDevice
operator|=
name|QSharedPointer
argument_list|<
name|QNonContiguousByteDevice
argument_list|>
argument_list|(
name|QNonContiguousByteDeviceFactory
operator|::
name|create
argument_list|(
name|reply
operator|->
name|outgoingData
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
return|return
literal|0
return|;
block|}
name|bool
name|bufferDisallowed
init|=
name|reply
operator|->
name|request
operator|.
name|attribute
argument_list|(
name|QNetworkRequest
operator|::
name|DoNotBufferUploadDataAttribute
argument_list|,
name|QVariant
argument_list|(
literal|false
argument_list|)
argument_list|)
operator|==
name|QVariant
argument_list|(
literal|true
argument_list|)
decl_stmt|;
if|if
condition|(
name|bufferDisallowed
condition|)
name|uploadByteDevice
operator|->
name|disableReset
argument_list|()
expr_stmt|;
comment|// We want signal emissions only for normal asynchronous uploads
if|if
condition|(
operator|!
name|isSynchronous
argument_list|()
condition|)
name|connect
argument_list|(
name|uploadByteDevice
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|readProgress
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|emitReplyUploadProgress
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|uploadByteDevice
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// need to have this function since the reply is a private member variable
end_comment
begin_comment
comment|// and the special backends need to access this.
end_comment
begin_function
DECL|function|emitReplyUploadProgress
name|void
name|QNetworkAccessBackend
operator|::
name|emitReplyUploadProgress
parameter_list|(
name|qint64
name|bytesSent
parameter_list|,
name|qint64
name|bytesTotal
parameter_list|)
block|{
if|if
condition|(
name|reply
operator|->
name|isFinished
condition|)
return|return;
name|reply
operator|->
name|emitUploadProgress
argument_list|(
name|bytesSent
argument_list|,
name|bytesTotal
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QNetworkAccessBackend
name|QNetworkAccessBackend
operator|::
name|QNetworkAccessBackend
parameter_list|()
member_init_list|:
name|manager
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|reply
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|synchronous
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QNetworkAccessBackend
name|QNetworkAccessBackend
operator|::
name|~
name|QNetworkAccessBackend
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|downstreamReadyWrite
name|void
name|QNetworkAccessBackend
operator|::
name|downstreamReadyWrite
parameter_list|()
block|{
comment|// do nothing
block|}
end_function
begin_function
DECL|function|setDownstreamLimited
name|void
name|QNetworkAccessBackend
operator|::
name|setDownstreamLimited
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|b
argument_list|)
expr_stmt|;
comment|// do nothing
block|}
end_function
begin_function
DECL|function|copyFinished
name|void
name|QNetworkAccessBackend
operator|::
name|copyFinished
parameter_list|(
name|QIODevice
modifier|*
parameter_list|)
block|{
comment|// do nothing
block|}
end_function
begin_function
DECL|function|ignoreSslErrors
name|void
name|QNetworkAccessBackend
operator|::
name|ignoreSslErrors
parameter_list|()
block|{
comment|// do nothing
block|}
end_function
begin_function
DECL|function|ignoreSslErrors
name|void
name|QNetworkAccessBackend
operator|::
name|ignoreSslErrors
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QSslError
argument_list|>
modifier|&
name|errors
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|errors
argument_list|)
expr_stmt|;
comment|// do nothing
block|}
end_function
begin_function
DECL|function|fetchSslConfiguration
name|void
name|QNetworkAccessBackend
operator|::
name|fetchSslConfiguration
parameter_list|(
name|QSslConfiguration
modifier|&
parameter_list|)
specifier|const
block|{
comment|// do nothing
block|}
end_function
begin_function
DECL|function|setSslConfiguration
name|void
name|QNetworkAccessBackend
operator|::
name|setSslConfiguration
parameter_list|(
specifier|const
name|QSslConfiguration
modifier|&
parameter_list|)
block|{
comment|// do nothing
block|}
end_function
begin_function
DECL|function|fetchCacheMetaData
name|QNetworkCacheMetaData
name|QNetworkAccessBackend
operator|::
name|fetchCacheMetaData
parameter_list|(
specifier|const
name|QNetworkCacheMetaData
modifier|&
parameter_list|)
specifier|const
block|{
return|return
name|QNetworkCacheMetaData
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|operation
name|QNetworkAccessManager
operator|::
name|Operation
name|QNetworkAccessBackend
operator|::
name|operation
parameter_list|()
specifier|const
block|{
return|return
name|reply
operator|->
name|operation
return|;
block|}
end_function
begin_function
DECL|function|request
name|QNetworkRequest
name|QNetworkAccessBackend
operator|::
name|request
parameter_list|()
specifier|const
block|{
return|return
name|reply
operator|->
name|request
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_function
DECL|function|proxyList
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|QNetworkAccessBackend
operator|::
name|proxyList
parameter_list|()
specifier|const
block|{
return|return
name|reply
operator|->
name|proxyList
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|networkCache
name|QAbstractNetworkCache
modifier|*
name|QNetworkAccessBackend
operator|::
name|networkCache
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|manager
condition|)
return|return
literal|0
return|;
return|return
name|manager
operator|->
name|networkCache
return|;
block|}
end_function
begin_function
DECL|function|setCachingEnabled
name|void
name|QNetworkAccessBackend
operator|::
name|setCachingEnabled
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|reply
operator|->
name|setCachingEnabled
argument_list|(
name|enable
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isCachingEnabled
name|bool
name|QNetworkAccessBackend
operator|::
name|isCachingEnabled
parameter_list|()
specifier|const
block|{
return|return
name|reply
operator|->
name|isCachingEnabled
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|nextDownstreamBlockSize
name|qint64
name|QNetworkAccessBackend
operator|::
name|nextDownstreamBlockSize
parameter_list|()
specifier|const
block|{
return|return
name|reply
operator|->
name|nextDownstreamBlockSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|writeDownstreamData
name|void
name|QNetworkAccessBackend
operator|::
name|writeDownstreamData
parameter_list|(
name|QByteDataBuffer
modifier|&
name|list
parameter_list|)
block|{
name|reply
operator|->
name|appendDownstreamData
argument_list|(
name|list
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|writeDownstreamData
name|void
name|QNetworkAccessBackend
operator|::
name|writeDownstreamData
parameter_list|(
name|QIODevice
modifier|*
name|data
parameter_list|)
block|{
name|reply
operator|->
name|appendDownstreamData
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// not actually appending data, it was already written to the user buffer
end_comment
begin_function
DECL|function|writeDownstreamDataDownloadBuffer
name|void
name|QNetworkAccessBackend
operator|::
name|writeDownstreamDataDownloadBuffer
parameter_list|(
name|qint64
name|bytesReceived
parameter_list|,
name|qint64
name|bytesTotal
parameter_list|)
block|{
name|reply
operator|->
name|appendDownstreamDataDownloadBuffer
argument_list|(
name|bytesReceived
argument_list|,
name|bytesTotal
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getDownloadBuffer
name|char
modifier|*
name|QNetworkAccessBackend
operator|::
name|getDownloadBuffer
parameter_list|(
name|qint64
name|size
parameter_list|)
block|{
return|return
name|reply
operator|->
name|getDownloadBuffer
argument_list|(
name|size
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|header
name|QVariant
name|QNetworkAccessBackend
operator|::
name|header
parameter_list|(
name|QNetworkRequest
operator|::
name|KnownHeaders
name|header
parameter_list|)
specifier|const
block|{
return|return
name|reply
operator|->
name|q_func
argument_list|()
operator|->
name|header
argument_list|(
name|header
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setHeader
name|void
name|QNetworkAccessBackend
operator|::
name|setHeader
parameter_list|(
name|QNetworkRequest
operator|::
name|KnownHeaders
name|header
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
name|reply
operator|->
name|setCookedHeader
argument_list|(
name|header
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasRawHeader
name|bool
name|QNetworkAccessBackend
operator|::
name|hasRawHeader
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|headerName
parameter_list|)
specifier|const
block|{
return|return
name|reply
operator|->
name|q_func
argument_list|()
operator|->
name|hasRawHeader
argument_list|(
name|headerName
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|rawHeader
name|QByteArray
name|QNetworkAccessBackend
operator|::
name|rawHeader
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|headerName
parameter_list|)
specifier|const
block|{
return|return
name|reply
operator|->
name|q_func
argument_list|()
operator|->
name|rawHeader
argument_list|(
name|headerName
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|rawHeaderList
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QNetworkAccessBackend
operator|::
name|rawHeaderList
parameter_list|()
specifier|const
block|{
return|return
name|reply
operator|->
name|q_func
argument_list|()
operator|->
name|rawHeaderList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setRawHeader
name|void
name|QNetworkAccessBackend
operator|::
name|setRawHeader
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|headerName
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|headerValue
parameter_list|)
block|{
name|reply
operator|->
name|setRawHeader
argument_list|(
name|headerName
argument_list|,
name|headerValue
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|attribute
name|QVariant
name|QNetworkAccessBackend
operator|::
name|attribute
parameter_list|(
name|QNetworkRequest
operator|::
name|Attribute
name|code
parameter_list|)
specifier|const
block|{
return|return
name|reply
operator|->
name|q_func
argument_list|()
operator|->
name|attribute
argument_list|(
name|code
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setAttribute
name|void
name|QNetworkAccessBackend
operator|::
name|setAttribute
parameter_list|(
name|QNetworkRequest
operator|::
name|Attribute
name|code
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|value
operator|.
name|isValid
argument_list|()
condition|)
name|reply
operator|->
name|attributes
operator|.
name|insert
argument_list|(
name|code
argument_list|,
name|value
argument_list|)
expr_stmt|;
else|else
name|reply
operator|->
name|attributes
operator|.
name|remove
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|url
name|QUrl
name|QNetworkAccessBackend
operator|::
name|url
parameter_list|()
specifier|const
block|{
return|return
name|reply
operator|->
name|url
return|;
block|}
end_function
begin_function
DECL|function|setUrl
name|void
name|QNetworkAccessBackend
operator|::
name|setUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|reply
operator|->
name|url
operator|=
name|url
expr_stmt|;
block|}
end_function
begin_function
DECL|function|finished
name|void
name|QNetworkAccessBackend
operator|::
name|finished
parameter_list|()
block|{
name|reply
operator|->
name|finished
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|error
name|void
name|QNetworkAccessBackend
operator|::
name|error
parameter_list|(
name|QNetworkReply
operator|::
name|NetworkError
name|code
parameter_list|,
specifier|const
name|QString
modifier|&
name|errorString
parameter_list|)
block|{
name|reply
operator|->
name|error
argument_list|(
name|code
argument_list|,
name|errorString
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_function
DECL|function|proxyAuthenticationRequired
name|void
name|QNetworkAccessBackend
operator|::
name|proxyAuthenticationRequired
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
name|proxy
parameter_list|,
name|QAuthenticator
modifier|*
name|authenticator
parameter_list|)
block|{
name|manager
operator|->
name|proxyAuthenticationRequired
argument_list|(
name|proxy
argument_list|,
name|synchronous
argument_list|,
name|authenticator
argument_list|,
operator|&
name|reply
operator|->
name|lastProxyAuthentication
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|authenticationRequired
name|void
name|QNetworkAccessBackend
operator|::
name|authenticationRequired
parameter_list|(
name|QAuthenticator
modifier|*
name|authenticator
parameter_list|)
block|{
name|manager
operator|->
name|authenticationRequired
argument_list|(
name|authenticator
argument_list|,
name|reply
operator|->
name|q_func
argument_list|()
argument_list|,
name|synchronous
argument_list|,
name|reply
operator|->
name|url
argument_list|,
operator|&
name|reply
operator|->
name|urlForLastAuthentication
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|metaDataChanged
name|void
name|QNetworkAccessBackend
operator|::
name|metaDataChanged
parameter_list|()
block|{
name|reply
operator|->
name|metaDataChanged
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|redirectionRequested
name|void
name|QNetworkAccessBackend
operator|::
name|redirectionRequested
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|target
parameter_list|)
block|{
name|reply
operator|->
name|redirectionRequested
argument_list|(
name|target
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sslErrors
name|void
name|QNetworkAccessBackend
operator|::
name|sslErrors
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QSslError
argument_list|>
modifier|&
name|errors
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
name|reply
operator|->
name|sslErrors
argument_list|(
name|errors
argument_list|)
expr_stmt|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|errors
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     Starts the backend.  Returns true if the backend is started.  Returns false if the backend     could not be started due to an unopened or roaming session.  The caller should recall this     function once the session has been opened or the roaming process has finished. */
end_comment
begin_function
DECL|function|start
name|bool
name|QNetworkAccessBackend
operator|::
name|start
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
comment|// For bearer, check if session start is required
if|if
condition|(
name|manager
operator|->
name|networkSession
condition|)
block|{
comment|// session required
if|if
condition|(
name|manager
operator|->
name|networkSession
operator|->
name|isOpen
argument_list|()
operator|&&
name|manager
operator|->
name|networkSession
operator|->
name|state
argument_list|()
operator|==
name|QNetworkSession
operator|::
name|Connected
condition|)
block|{
comment|// Session is already open and ready to use.
comment|// copy network session down to the backend
name|setProperty
argument_list|(
literal|"_q_networksession"
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|manager
operator|->
name|networkSession
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Session not ready, but can skip for loopback connections
comment|// This is not ideal.
specifier|const
name|QString
name|host
init|=
name|reply
operator|->
name|url
operator|.
name|host
argument_list|()
decl_stmt|;
if|if
condition|(
name|host
operator|==
name|QLatin1String
argument_list|(
literal|"localhost"
argument_list|)
operator|||
name|QHostAddress
argument_list|(
name|host
argument_list|)
operator|.
name|isLoopback
argument_list|()
condition|)
block|{
comment|// Don't need an open session for localhost access.
block|}
else|else
block|{
comment|// need to wait for session to be opened
return|return
literal|false
return|;
block|}
block|}
block|}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
comment|// Get the proxy settings from the network session (in the case of service networks,
comment|// the proxy settings change depending which AP was activated)
name|QNetworkSession
modifier|*
name|session
init|=
name|manager
operator|->
name|networkSession
operator|.
name|data
argument_list|()
decl_stmt|;
name|QNetworkConfiguration
name|config
decl_stmt|;
if|if
condition|(
name|session
condition|)
block|{
name|QNetworkConfigurationManager
name|configManager
decl_stmt|;
comment|// The active configuration tells us what IAP is in use
name|QVariant
name|v
init|=
name|session
operator|->
name|sessionProperty
argument_list|(
name|QLatin1String
argument_list|(
literal|"ActiveConfiguration"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|v
operator|.
name|isValid
argument_list|()
condition|)
name|config
operator|=
name|configManager
operator|.
name|configurationFromIdentifier
argument_list|(
name|qvariant_cast
argument_list|<
name|QString
argument_list|>
argument_list|(
name|v
argument_list|)
argument_list|)
expr_stmt|;
comment|// Fallback to using the configuration if no active configuration
if|if
condition|(
operator|!
name|config
operator|.
name|isValid
argument_list|()
condition|)
name|config
operator|=
name|session
operator|->
name|configuration
argument_list|()
expr_stmt|;
comment|// or unspecified configuration if that is no good either
if|if
condition|(
operator|!
name|config
operator|.
name|isValid
argument_list|()
condition|)
name|config
operator|=
name|QNetworkConfiguration
argument_list|()
expr_stmt|;
block|}
name|reply
operator|->
name|proxyList
operator|=
name|manager
operator|->
name|queryProxy
argument_list|(
name|QNetworkProxyQuery
argument_list|(
name|config
argument_list|,
name|url
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
comment|// QT_NO_BEARERMANAGEMENT
comment|// Without bearer management, the proxy depends only on the url
name|reply
operator|->
name|proxyList
operator|=
name|manager
operator|->
name|queryProxy
argument_list|(
name|QNetworkProxyQuery
argument_list|(
name|url
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|// now start the request
name|open
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
