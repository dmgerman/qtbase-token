begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKACCESSBACKEND_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKACCESSBACKEND_P_H
define|#
directive|define
name|QNETWORKACCESSBACKEND_P_H
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
file|"qnetworkreplyimpl_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qobject.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAuthenticator
name|class
name|QAuthenticator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkProxy
name|class
name|QNetworkProxy
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkProxyQuery
name|class
name|QNetworkProxyQuery
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkRequest
name|class
name|QNetworkRequest
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrlInfo
name|class
name|QUrlInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslConfiguration
name|class
name|QSslConfiguration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkAccessManagerPrivate
name|class
name|QNetworkAccessManagerPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkReplyImplPrivate
name|class
name|QNetworkReplyImplPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractNetworkCache
name|class
name|QAbstractNetworkCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkCacheMetaData
name|class
name|QNetworkCacheMetaData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNonContiguousByteDevice
name|class
name|QNonContiguousByteDevice
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Should support direct file upload from disk or download to disk.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// - The HTTP handler will use two QIODevices for communication (pull mechanism)
end_comment
begin_comment
comment|// - KIO uses a pull mechanism too (data/dataReq signals)
end_comment
begin_decl_stmt
name|class
name|QNetworkAccessBackend
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QNetworkAccessBackend
argument_list|()
block|;
name|virtual
operator|~
name|QNetworkAccessBackend
argument_list|()
block|;
comment|// To avoid mistaking with QIODevice names, the functions here
comment|// have different names. The Connection has two streams:
comment|//
comment|// - Upstream:
comment|//   The upstream uses a QNonContiguousByteDevice provided
comment|//   by the backend. This device emits the usual readyRead()
comment|//   signal when the backend has data available for the connection
comment|//   to write. The different backends can listen on this signal
comment|//   and then pull upload data from the QNonContiguousByteDevice and
comment|//   deal with it.
comment|//
comment|//
comment|// - Downstream:
comment|//   Downstream is the data that is being read from this
comment|//   connection and is given to the user. Downstream operates in a
comment|//   semi-"push" mechanism: the Connection object pushes the data
comment|//   it gets from the network, but it should avoid writing too
comment|//   much if the data isn't being used fast enough. The value
comment|//   returned by suggestedDownstreamBlockSize() can be used to
comment|//   determine how much should be written at a time. The
comment|//   downstreamBytesConsumed() function will be called when the
comment|//   downstream buffer is consumed by the user -- the Connection
comment|//   may choose to re-fill it with more data it has ready or get
comment|//   more data from the network (for instance, by reading from its
comment|//   socket).
name|virtual
name|void
name|open
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|start
argument_list|()
block|;
name|virtual
name|void
name|closeDownstreamChannel
argument_list|()
operator|=
literal|0
block|;
comment|// slot-like:
name|virtual
name|void
name|downstreamReadyWrite
argument_list|()
block|;
name|virtual
name|void
name|setDownstreamLimited
argument_list|(
argument|bool b
argument_list|)
block|;
name|virtual
name|void
name|copyFinished
argument_list|(
name|QIODevice
operator|*
argument_list|)
block|;
name|virtual
name|void
name|ignoreSslErrors
argument_list|()
block|;
name|virtual
name|void
name|ignoreSslErrors
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
name|virtual
name|void
name|fetchSslConfiguration
argument_list|(
argument|QSslConfiguration&configuration
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|setSslConfiguration
argument_list|(
specifier|const
name|QSslConfiguration
operator|&
name|configuration
argument_list|)
block|;
name|virtual
name|QNetworkCacheMetaData
name|fetchCacheMetaData
argument_list|(
argument|const QNetworkCacheMetaData&metaData
argument_list|)
specifier|const
block|;
comment|// information about the request
name|QNetworkAccessManager
operator|::
name|Operation
name|operation
argument_list|()
specifier|const
block|;
name|QNetworkRequest
name|request
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|QList
operator|<
name|QNetworkProxy
operator|>
name|proxyList
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|QAbstractNetworkCache
operator|*
name|networkCache
argument_list|()
specifier|const
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
comment|// information about the reply
name|QUrl
name|url
argument_list|()
specifier|const
block|;
name|void
name|setUrl
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
block|;
comment|// "cooked" headers
name|QVariant
name|header
argument_list|(
argument|QNetworkRequest::KnownHeaders header
argument_list|)
specifier|const
block|;
name|void
name|setHeader
argument_list|(
argument|QNetworkRequest::KnownHeaders header
argument_list|,
argument|const QVariant&value
argument_list|)
block|;
comment|// raw headers:
name|bool
name|hasRawHeader
argument_list|(
argument|const QByteArray&headerName
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|rawHeaderList
argument_list|()
specifier|const
block|;
name|QByteArray
name|rawHeader
argument_list|(
argument|const QByteArray&headerName
argument_list|)
specifier|const
block|;
name|void
name|setRawHeader
argument_list|(
specifier|const
name|QByteArray
operator|&
name|headerName
argument_list|,
specifier|const
name|QByteArray
operator|&
name|value
argument_list|)
block|;
comment|// attributes:
name|QVariant
name|attribute
argument_list|(
argument|QNetworkRequest::Attribute code
argument_list|)
specifier|const
block|;
name|void
name|setAttribute
argument_list|(
argument|QNetworkRequest::Attribute code
argument_list|,
argument|const QVariant&value
argument_list|)
block|;
name|bool
name|isSynchronous
argument_list|()
block|{
return|return
name|synchronous
return|;
block|}
name|void
name|setSynchronous
argument_list|(
argument|bool sync
argument_list|)
block|{
name|synchronous
operator|=
name|sync
block|; }
comment|// return true if the QNonContiguousByteDevice of the upload
comment|// data needs to support reset(). Currently needed for HTTP.
comment|// This will possibly enable buffering of the upload data.
name|virtual
name|bool
name|needsResetableUploadData
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|// Returns true if backend is able to resume downloads.
name|virtual
name|bool
name|canResume
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|void
name|setResumeOffset
argument_list|(
argument|quint64 offset
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
block|; }
name|virtual
name|bool
name|processRequestSynchronously
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|protected
operator|:
comment|// Create the device used for reading the upload data
name|QNonContiguousByteDevice
operator|*
name|createUploadByteDevice
argument_list|()
block|;
comment|// these functions control the downstream mechanism
comment|// that is, data that has come via the connection and is going out the backend
name|qint64
name|nextDownstreamBlockSize
argument_list|()
specifier|const
block|;
name|void
name|writeDownstreamData
argument_list|(
name|QByteDataBuffer
operator|&
name|list
argument_list|)
block|;
comment|// not actually appending data, it was already written to the user buffer
name|void
name|writeDownstreamDataDownloadBuffer
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
block|;
name|char
operator|*
name|getDownloadBuffer
argument_list|(
name|qint64
argument_list|)
block|;
name|QSharedPointer
operator|<
name|QNonContiguousByteDevice
operator|>
name|uploadByteDevice
block|;
name|public
name|slots
operator|:
comment|// for task 251801, needs to be a slot to be called asynchronously
name|void
name|writeDownstreamData
argument_list|(
name|QIODevice
operator|*
name|data
argument_list|)
block|;
name|protected
name|slots
operator|:
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
name|void
name|authenticationRequired
argument_list|(
name|QAuthenticator
operator|*
name|auth
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
name|destination
argument_list|)
block|;
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
block|;
name|void
name|emitReplyUploadProgress
argument_list|(
argument|qint64 bytesSent
argument_list|,
argument|qint64 bytesTotal
argument_list|)
block|;
name|protected
operator|:
comment|// FIXME In the long run we should get rid of our QNAM architecture
comment|// and scrap this ReplyImpl/Backend distinction.
name|QNetworkAccessManagerPrivate
operator|*
name|manager
block|;
name|QNetworkReplyImplPrivate
operator|*
name|reply
block|;
name|private
operator|:
name|friend
name|class
name|QNetworkAccessManager
block|;
name|friend
name|class
name|QNetworkAccessManagerPrivate
block|;
name|friend
name|class
name|QNetworkReplyImplPrivate
block|;
name|bool
name|synchronous
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkAccessBackendFactory
block|{
name|public
label|:
name|QNetworkAccessBackendFactory
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QNetworkAccessBackendFactory
argument_list|()
expr_stmt|;
name|virtual
name|QNetworkAccessBackend
modifier|*
name|create
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
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
