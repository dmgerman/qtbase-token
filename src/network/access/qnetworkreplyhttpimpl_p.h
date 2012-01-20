begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKREPLYHTTPIMPL_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKREPLYHTTPIMPL_P_H
define|#
directive|define
name|QNETWORKREPLYHTTPIMPL_P_H
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
comment|// of the Network Access API.  This header file may change from
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
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qsharedpointer.h"
end_include
begin_include
include|#
directive|include
file|"qatomic.h"
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QNetworkCacheMetaData>
end_include
begin_include
include|#
directive|include
file|<private/qhttpnetworkrequest_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qbytedata_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qnetworkreply_p.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QNetworkProxy>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
end_ifndef
begin_include
include|#
directive|include
file|<QtNetwork/QSslConfiguration>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_HTTP
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkReplyHttpImplPrivate
name|class
name|QNetworkReplyHttpImplPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkReplyHttpImpl
range|:
name|public
name|QNetworkReply
block|{
name|Q_OBJECT
name|public
operator|:
name|QNetworkReplyHttpImpl
argument_list|(
name|QNetworkAccessManager
operator|*
specifier|const
argument_list|,
specifier|const
name|QNetworkRequest
operator|&
argument_list|,
name|QNetworkAccessManager
operator|::
name|Operation
operator|&
argument_list|,
name|QIODevice
operator|*
name|outgoingData
argument_list|)
block|;
name|virtual
operator|~
name|QNetworkReplyHttpImpl
argument_list|()
block|;
name|void
name|close
argument_list|()
block|;
name|void
name|abort
argument_list|()
block|;
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
block|;
name|bool
name|isSequential
argument_list|()
specifier|const
block|;
name|qint64
name|size
argument_list|()
specifier|const
block|;
name|qint64
name|readData
argument_list|(
name|char
operator|*
argument_list|,
name|qint64
argument_list|)
block|;
name|void
name|setReadBufferSize
argument_list|(
argument|qint64 size
argument_list|)
block|;
name|bool
name|canReadLine
argument_list|()
specifier|const
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QNetworkReplyHttpImpl
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_startOperation()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_cacheLoadReadyRead()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_bufferOutgoingData()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_bufferOutgoingDataFinished()
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_networkSessionConnected()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_networkSessionFailed()
argument_list|)
endif|#
directive|endif
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_finished()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_error(QNetworkReply::NetworkError, const QString&)
argument_list|)
comment|// From reply
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void replyDownloadData(QByteArray)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void replyFinished()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void replyDownloadMetaData(QList<QPair<QByteArray,QByteArray>>,int,QString,bool,QSharedPointer<char>,qint64)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void replyDownloadProgressSlot(qint64,qint64)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void httpAuthenticationRequired(const QHttpNetworkRequest&, QAuthenticator *)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void httpError(QNetworkReply::NetworkError, const QString&)
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void replySslErrors(const QList<QSslError>&, bool *, QList<QSslError> *)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void replySslConfigurationChanged(const QSslConfiguration&)
argument_list|)
endif|#
directive|endif
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void proxyAuthenticationRequired(const QNetworkProxy&proxy, QAuthenticator *auth)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void resetUploadDataSlot(bool *r)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void wantUploadDataSlot(qint64)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void sentUploadDataSlot(qint64)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void emitReplyUploadProgress(qint64, qint64)
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
name|protected
operator|:
name|void
name|ignoreSslErrors
argument_list|()
block|;
name|void
name|ignoreSslErrorsImplementation
argument_list|(
specifier|const
name|QList
operator|<
name|QSslError
operator|>
operator|&
name|errors
argument_list|)
block|;
name|void
name|setSslConfigurationImplementation
argument_list|(
specifier|const
name|QSslConfiguration
operator|&
name|configuration
argument_list|)
block|;
name|void
name|sslConfigurationImplementation
argument_list|(
argument|QSslConfiguration&configuration
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|signals
operator|:
comment|// To HTTP thread:
name|void
name|startHttpRequest
argument_list|()
block|;
name|void
name|abortHttpRequest
argument_list|()
block|;
name|void
name|startHttpRequestSynchronously
argument_list|()
block|;
name|void
name|haveUploadData
argument_list|(
argument|QByteArray dataArray
argument_list|,
argument|bool dataAtEnd
argument_list|,
argument|qint64 dataSize
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkReplyHttpImplPrivate
range|:
name|public
name|QNetworkReplyPrivate
block|{
name|public
operator|:
specifier|static
name|QHttpNetworkRequest
operator|::
name|Priority
name|convert
argument_list|(
specifier|const
name|QNetworkRequest
operator|::
name|Priority
operator|&
name|prio
argument_list|)
block|;      enum
name|State
block|{
name|Idle
block|,
comment|// The reply is idle.
name|Buffering
block|,
comment|// The reply is buffering outgoing data.
name|Working
block|,
comment|// The reply is uploading/downloading data.
name|Finished
block|,
comment|// The reply has finished.
name|Aborted
block|,
comment|// The reply has been aborted.
name|WaitingForSession
block|,
comment|// The reply is waiting for the session to open before connecting.
name|Reconnecting
comment|// The reply will reconnect to once roaming has completed.
block|}
block|;
name|QNetworkReplyHttpImplPrivate
argument_list|()
block|;
operator|~
name|QNetworkReplyHttpImplPrivate
argument_list|()
block|;
name|bool
name|start
argument_list|()
block|;
name|void
name|_q_startOperation
argument_list|()
block|;
name|void
name|_q_cacheLoadReadyRead
argument_list|()
block|;
name|void
name|_q_bufferOutgoingData
argument_list|()
block|;
name|void
name|_q_bufferOutgoingDataFinished
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|void
name|_q_networkSessionConnected
argument_list|()
block|;
name|void
name|_q_networkSessionFailed
argument_list|()
block|;
endif|#
directive|endif
name|void
name|_q_finished
argument_list|()
block|;
comment|// FIXME
name|void
name|finished
argument_list|()
block|;
name|void
name|error
argument_list|(
argument|QNetworkReply::NetworkError code
argument_list|,
argument|const QString&errorString
argument_list|)
block|;
name|void
name|_q_error
argument_list|(
argument|QNetworkReply::NetworkError code
argument_list|,
argument|const QString&errorString
argument_list|)
block|;
name|void
name|metaDataChanged
argument_list|()
block|;
name|void
name|redirectionRequested
argument_list|(
specifier|const
name|QUrl
operator|&
name|target
argument_list|)
block|;
name|void
name|checkForRedirect
argument_list|(
argument|const int statusCode
argument_list|)
block|;
comment|// incoming from user
name|QNetworkAccessManager
operator|*
name|manager
block|;
name|QNetworkAccessManagerPrivate
operator|*
name|managerPrivate
block|;
name|QHttpNetworkRequest
name|httpRequest
block|;
comment|// There is also a copy in the HTTP thread
name|bool
name|synchronous
block|;
name|State
name|state
block|;
comment|// from http thread
name|int
name|statusCode
block|;
name|QString
name|reasonPhrase
block|;
comment|// upload
name|QNonContiguousByteDevice
operator|*
name|createUploadByteDevice
argument_list|()
block|;
name|QSharedPointer
operator|<
name|QNonContiguousByteDevice
operator|>
name|uploadByteDevice
block|;
name|QIODevice
operator|*
name|outgoingData
block|;
name|QSharedPointer
operator|<
name|QRingBuffer
operator|>
name|outgoingDataBuffer
block|;
name|void
name|emitReplyUploadProgress
argument_list|(
argument|qint64 bytesSent
argument_list|,
argument|qint64 bytesTotal
argument_list|)
block|;
comment|// dup?
name|qint64
name|bytesUploaded
block|;
comment|// cache
name|void
name|createCache
argument_list|()
block|;
name|void
name|completeCacheSave
argument_list|()
block|;
name|void
name|setCachingEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isCachingEnabled
argument_list|()
specifier|const
block|;
name|void
name|initCacheSaveDevice
argument_list|()
block|;
name|QAbstractNetworkCache
operator|*
name|networkCache
argument_list|()
specifier|const
block|;
name|QIODevice
operator|*
name|cacheLoadDevice
block|;
name|bool
name|loadingFromCache
block|;
name|QIODevice
operator|*
name|cacheSaveDevice
block|;
name|bool
name|cacheEnabled
block|;
comment|// is this for saving?
name|QUrl
name|urlForLastAuthentication
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|QNetworkProxy
name|lastProxyAuthentication
block|;
name|QList
operator|<
name|QNetworkProxy
operator|>
name|proxyList
block|;
endif|#
directive|endif
name|bool
name|migrateBackend
argument_list|()
block|;
name|bool
name|canResume
argument_list|()
specifier|const
block|;
name|void
name|setResumeOffset
argument_list|(
argument|quint64 offset
argument_list|)
block|;
name|quint64
name|resumeOffset
block|;
name|qint64
name|preMigrationDownloaded
block|;
comment|// Used for normal downloading. For "zero copy" the downloadZerocopyBuffer is used
name|QByteDataBuffer
name|downloadMultiBuffer
block|;
name|QByteDataBuffer
name|pendingDownloadData
block|;
comment|// For signal compression
name|qint64
name|bytesDownloaded
block|;
name|qint64
name|lastBytesDownloaded
block|;
name|void
name|setDownloadBuffer
argument_list|(
argument|QSharedPointer<char> sp
argument_list|,
argument|qint64 size
argument_list|)
block|;
name|char
operator|*
name|getDownloadBuffer
argument_list|(
argument|qint64 size
argument_list|)
block|;
comment|// only used when the "zero copy" style is used. Else downloadMultiBuffer is used.
comment|// Please note that the whole "zero copy" download buffer API is private right now. Do not use it.
name|qint64
name|downloadBufferReadPosition
block|;
name|qint64
name|downloadBufferCurrentSize
block|;
name|qint64
name|downloadBufferMaximumSize
block|;
name|QSharedPointer
operator|<
name|char
operator|>
name|downloadBufferPointer
block|;
name|char
operator|*
name|downloadZerocopyBuffer
block|;
comment|// Will be increased by HTTP thread:
name|QSharedPointer
operator|<
name|QAtomicInt
operator|>
name|pendingDownloadDataEmissions
block|;
name|QSharedPointer
operator|<
name|QAtomicInt
operator|>
name|pendingDownloadProgressEmissions
block|;
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
name|QSslConfiguration
name|sslConfiguration
block|;
name|bool
name|pendingIgnoreAllSslErrors
block|;
name|QList
operator|<
name|QSslError
operator|>
name|pendingIgnoreSslErrorsList
block|;
endif|#
directive|endif
name|bool
name|loadFromCacheIfAllowed
argument_list|(
name|QHttpNetworkRequest
operator|&
name|httpRequest
argument_list|)
block|;
name|void
name|invalidateCache
argument_list|()
block|;
name|bool
name|sendCacheContents
argument_list|(
specifier|const
name|QNetworkCacheMetaData
operator|&
name|metaData
argument_list|)
block|;
name|QNetworkCacheMetaData
name|fetchCacheMetaData
argument_list|(
argument|const QNetworkCacheMetaData&metaData
argument_list|)
specifier|const
block|;
name|void
name|postRequest
argument_list|()
block|;
name|public
operator|:
comment|// From HTTP thread:
name|void
name|replyDownloadData
argument_list|(
name|QByteArray
argument_list|)
block|;
name|void
name|replyFinished
argument_list|()
block|;
name|void
name|replyDownloadMetaData
argument_list|(
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
argument_list|,
name|QByteArray
operator|>
expr|>
argument_list|,
name|int
argument_list|,
name|QString
argument_list|,
name|bool
argument_list|,
name|QSharedPointer
operator|<
name|char
operator|>
argument_list|,
name|qint64
argument_list|)
block|;
name|void
name|replyDownloadProgressSlot
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
block|;
name|void
name|httpAuthenticationRequired
argument_list|(
specifier|const
name|QHttpNetworkRequest
operator|&
name|request
argument_list|,
name|QAuthenticator
operator|*
name|auth
argument_list|)
block|;
name|void
name|httpError
argument_list|(
argument|QNetworkReply::NetworkError error
argument_list|,
argument|const QString&errorString
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
name|void
name|replySslErrors
argument_list|(
specifier|const
name|QList
operator|<
name|QSslError
operator|>
operator|&
argument_list|,
name|bool
operator|*
argument_list|,
name|QList
operator|<
name|QSslError
operator|>
operator|*
argument_list|)
block|;
name|void
name|replySslConfigurationChanged
argument_list|(
specifier|const
name|QSslConfiguration
operator|&
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|void
name|proxyAuthenticationRequired
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|proxy
argument_list|,
name|QAuthenticator
operator|*
name|auth
argument_list|)
block|;
endif|#
directive|endif
comment|// From QNonContiguousByteDeviceThreadForwardImpl in HTTP thread:
name|void
name|resetUploadDataSlot
argument_list|(
name|bool
operator|*
name|r
argument_list|)
block|;
name|void
name|wantUploadDataSlot
argument_list|(
name|qint64
argument_list|)
block|;
name|void
name|sentUploadDataSlot
argument_list|(
name|qint64
argument_list|)
block|;
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QNetworkReplyHttpImpl
argument_list|)
block|}
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
comment|// QT_NO_HTTP
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
