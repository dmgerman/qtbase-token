begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKREPLYIMPL_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKREPLYIMPL_P_H
define|#
directive|define
name|QNETWORKREPLYIMPL_P_H
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
file|"qnetworkaccessmanager.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkproxy.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qqueue.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbuffer.h"
end_include
begin_include
include|#
directive|include
file|"private/qringbuffer_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qbytedata_p.h"
end_include
begin_include
include|#
directive|include
file|<QSharedPointer>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QNetworkSession>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractNetworkCache
name|class
name|QAbstractNetworkCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkAccessBackend
name|class
name|QNetworkAccessBackend
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkReplyImplPrivate
name|class
name|QNetworkReplyImplPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkReplyImpl
range|:
name|public
name|QNetworkReply
block|{
name|Q_OBJECT
name|public
operator|:
name|QNetworkReplyImpl
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNetworkReplyImpl
argument_list|()
block|;
name|virtual
name|void
name|abort
argument_list|()
name|Q_DECL_OVERRIDE
block|;
comment|// reimplemented from QNetworkReply / QIODevice
name|virtual
name|void
name|close
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|setReadBufferSize
argument_list|(
argument|qint64 size
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|qint64
name|readData
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|event
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QNetworkReplyImpl
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
argument|void _q_copyReadyRead()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_copyReadChannelFinished()
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
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_networkSessionStateChanged(QNetworkSession::State)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_networkSessionUsagePoliciesChanged(QNetworkSession::UsagePolicies)
argument_list|)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|protected
operator|:
name|void
name|sslConfigurationImplementation
argument_list|(
argument|QSslConfiguration&configuration
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setSslConfigurationImplementation
argument_list|(
argument|const QSslConfiguration&configuration
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|ignoreSslErrors
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|ignoreSslErrorsImplementation
argument_list|(
argument|const QList<QSslError>&errors
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkReplyImplPrivate
range|:
name|public
name|QNetworkReplyPrivate
block|{
name|public
operator|:
expr|enum
name|InternalNotifications
block|{
name|NotifyDownstreamReadyWrite
block|,
name|NotifyCloseDownstreamChannel
block|,
name|NotifyCopyFinished
block|}
block|;
typedef|typedef
name|QQueue
operator|<
name|InternalNotifications
operator|>
name|NotificationQueue
expr_stmt|;
name|QNetworkReplyImplPrivate
argument_list|()
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|_q_startOperation
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_copyReadyRead
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_copyReadChannelFinished
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_bufferOutgoingData
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_bufferOutgoingDataFinished
parameter_list|()
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_function_decl
name|void
name|_q_networkSessionConnected
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_networkSessionFailed
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|_q_networkSessionStateChanged
argument_list|(
name|QNetworkSession
operator|::
name|State
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|_q_networkSessionUsagePoliciesChanged
argument_list|(
name|QNetworkSession
operator|::
name|UsagePolicies
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|void
name|setup
argument_list|(
name|QNetworkAccessManager
operator|::
name|Operation
name|op
argument_list|,
specifier|const
name|QNetworkRequest
operator|&
name|request
argument_list|,
name|QIODevice
operator|*
name|outgoingData
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|pauseNotificationHandling
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|resumeNotificationHandling
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|backendNotify
parameter_list|(
name|InternalNotifications
name|notification
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|handleNotifications
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|createCache
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|completeCacheSave
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// callbacks from the backend (through the manager):
end_comment
begin_function_decl
name|void
name|setCachingEnabled
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|isCachingEnabled
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|consume
parameter_list|(
name|qint64
name|count
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|emitUploadProgress
parameter_list|(
name|qint64
name|bytesSent
parameter_list|,
name|qint64
name|bytesTotal
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|qint64
name|nextDownstreamBlockSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|initCacheSaveDevice
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|appendDownstreamDataSignalEmissions
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|appendDownstreamData
parameter_list|(
name|QByteDataBuffer
modifier|&
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|appendDownstreamData
parameter_list|(
name|QIODevice
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|appendDownstreamData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|setDownloadBuffer
argument_list|(
name|QSharedPointer
operator|<
name|char
operator|>
name|sp
argument_list|,
name|qint64
name|size
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|char
modifier|*
name|getDownloadBuffer
parameter_list|(
name|qint64
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|appendDownstreamDataDownloadBuffer
parameter_list|(
name|qint64
parameter_list|,
name|qint64
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|finished
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|error
argument_list|(
name|QNetworkReply
operator|::
name|NetworkError
name|code
argument_list|,
specifier|const
name|QString
operator|&
name|errorString
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|metaDataChanged
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|redirectionRequested
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|target
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|encrypted
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|sslErrors
argument_list|(
specifier|const
name|QList
operator|<
name|QSslError
operator|>
operator|&
name|errors
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QNetworkAccessBackend
modifier|*
name|backend
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QIODevice
modifier|*
name|outgoingData
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QSharedPointer
operator|<
name|QRingBuffer
operator|>
name|outgoingDataBuffer
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QIODevice
modifier|*
name|copyDevice
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QAbstractNetworkCache
operator|*
name|networkCache
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|migrateBackend
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|bool
name|cacheEnabled
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QIODevice
modifier|*
name|cacheSaveDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|NotificationQueue
name|pendingNotifications
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|notificationHandlingPaused
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QUrl
name|urlForLastAuthentication
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_decl_stmt
name|QNetworkProxy
name|lastProxyAuthentication
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|QNetworkProxy
operator|>
name|proxyList
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|qint64
name|bytesDownloaded
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qint64
name|lastBytesDownloaded
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qint64
name|bytesUploaded
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qint64
name|preMigrationDownloaded
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|httpReasonPhrase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|httpStatusCode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|State
name|state
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Only used when the "zero copy" style is used.
end_comment
begin_comment
comment|// Please note that the whole "zero copy" download buffer API is private right now. Do not use it.
end_comment
begin_decl_stmt
name|qint64
name|downloadBufferReadPosition
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qint64
name|downloadBufferCurrentSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qint64
name|downloadBufferMaximumSize
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QSharedPointer
operator|<
name|char
operator|>
name|downloadBufferPointer
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|char
modifier|*
name|downloadBuffer
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QNetworkReplyImpl
argument_list|)
end_macro
begin_expr_stmt
unit|};
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QNetworkReplyImplPrivate
operator|::
name|InternalNotifications
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_decl_stmt
name|class
name|QDisabledNetworkReply
range|:
name|public
name|QNetworkReply
block|{
name|Q_OBJECT
name|public
operator|:
name|QDisabledNetworkReply
argument_list|(
argument|QObject *parent
argument_list|,
argument|const QNetworkRequest&req
argument_list|,
argument|QNetworkAccessManager::Operation op
argument_list|)
block|;
operator|~
name|QDisabledNetworkReply
argument_list|()
block|;
name|void
name|abort
argument_list|()
name|Q_DECL_OVERRIDE
block|{ }
name|protected
operator|:
name|qint64
name|readData
argument_list|(
argument|char *
argument_list|,
argument|qint64
argument_list|)
name|Q_DECL_OVERRIDE
block|{
return|return
operator|-
literal|1
return|;
block|}
expr|}
block|;
endif|#
directive|endif
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
argument|QSharedPointer<char>
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
