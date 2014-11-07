begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtNetwork/qsslconfiguration.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|progressSignalInterval
specifier|const
name|int
name|QNetworkReplyPrivate
operator|::
name|progressSignalInterval
init|=
literal|100
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QNetworkReplyPrivate
name|QNetworkReplyPrivate
operator|::
name|QNetworkReplyPrivate
parameter_list|()
member_init_list|:
name|readBufferMaxSize
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|emitAllUploadProgressSignals
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|operation
argument_list|(
name|QNetworkAccessManager
operator|::
name|UnknownOperation
argument_list|)
member_init_list|,
name|errorCode
argument_list|(
name|QNetworkReply
operator|::
name|NoError
argument_list|)
member_init_list|,
name|isFinished
argument_list|(
literal|false
argument_list|)
block|{
comment|// set the default attribute values
name|attributes
operator|.
name|insert
argument_list|(
name|QNetworkRequest
operator|::
name|ConnectionEncryptedAttribute
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \class QNetworkReply     \since 4.4     \brief The QNetworkReply class contains the data and headers for a request     sent with QNetworkAccessManager      \reentrant     \ingroup network     \inmodule QtNetwork      The QNetworkReply class contains the data and meta data related to     a request posted with QNetworkAccessManager. Like QNetworkRequest,     it contains a URL and headers (both in parsed and raw form), some     information about the reply's state and the contents of the reply     itself.      QNetworkReply is a sequential-access QIODevice, which means that     once data is read from the object, it no longer kept by the     device. It is therefore the application's responsibility to keep     this data if it needs to. Whenever more data is received from the     network and processed, the readyRead() signal is emitted.      The downloadProgress() signal is also emitted when data is     received, but the number of bytes contained in it may not     represent the actual bytes received, if any transformation is done     to the contents (for example, decompressing and removing the     protocol overhead).      Even though QNetworkReply is a QIODevice connected to the contents     of the reply, it also emits the uploadProgress() signal, which     indicates the progress of the upload for operations that have such     content.      \note Do not delete the object in the slot connected to the     error() or finished() signal. Use deleteLater().      \sa QNetworkRequest, QNetworkAccessManager */
end_comment
begin_comment
comment|/*!     \enum QNetworkReply::NetworkError      Indicates all possible error conditions found during the     processing of the request.      \value NoError              no error condition.     \note When the HTTP protocol returns a redirect no error will be     reported.  You can check if there is a redirect with the     QNetworkRequest::RedirectionTargetAttribute attribute.      \value ConnectionRefusedError  the remote server refused the     connection (the server is not accepting requests)      \value RemoteHostClosedError   the remote server closed the     connection prematurely, before the entire reply was received and     processed      \value HostNotFoundError       the remote host name was not found     (invalid hostname)      \value TimeoutError            the connection to the remote server     timed out      \value OperationCanceledError  the operation was canceled via calls     to abort() or close() before it was finished.      \value SslHandshakeFailedError the SSL/TLS handshake failed and the     encrypted channel could not be established. The sslErrors() signal     should have been emitted.      \value TemporaryNetworkFailureError the connection was broken due     to disconnection from the network, however the system has initiated     roaming to another access point. The request should be resubmitted     and will be processed as soon as the connection is re-established.      \value NetworkSessionFailedError   the connection was broken due     to disconnection from the network or failure to start the network.      \value BackgroundRequestNotAllowedError the background request     is not currently allowed due to platform policy.      \value ProxyConnectionRefusedError the connection to the proxy     server was refused (the proxy server is not accepting requests)      \value ProxyConnectionClosedError  the proxy server closed the     connection prematurely, before the entire reply was received and     processed      \value ProxyNotFoundError          the proxy host name was not     found (invalid proxy hostname)      \value ProxyTimeoutError           the connection to the proxy     timed out or the proxy did not reply in time to the request sent      \value ProxyAuthenticationRequiredError the proxy requires     authentication in order to honour the request but did not accept     any credentials offered (if any)      \value ContentAccessDenied          the access to the remote     content was denied (similar to HTTP error 401)      \value ContentOperationNotPermittedError the operation requested     on the remote content is not permitted      \value ContentNotFoundError         the remote content was not     found at the server (similar to HTTP error 404)      \value AuthenticationRequiredError  the remote server requires     authentication to serve the content but the credentials provided     were not accepted (if any)      \value ContentReSendError          the request needed to be sent     again, but this failed for example because the upload data     could not be read a second time.      \value ContentConflictError         the request could not be completed due     to a conflict with the current state of the resource.      \value ContentGoneError             the requested resource is no longer     available at the server.      \value InternalServerError          the server encountered an unexpected     condition which prevented it from fulfilling the request.      \value OperationNotImplementedError the server does not support the     functionality required to fulfill the request.      \value ServiceUnavailableError      the server is unable to handle the     request at this time.      \value ProtocolUnknownError         the Network Access API cannot     honor the request because the protocol is not known      \value ProtocolInvalidOperationError the requested operation is     invalid for this protocol      \value UnknownNetworkError          an unknown network-related     error was detected      \value UnknownProxyError            an unknown proxy-related error     was detected      \value UnknownContentError          an unknown error related to     the remote content was detected      \value ProtocolFailure              a breakdown in protocol was     detected (parsing error, invalid or unexpected responses, etc.)      \value UnknownServerError           an unknown error related to     the server response was detected      \sa error() */
end_comment
begin_comment
comment|/*!     \fn void QNetworkReply::encrypted()     \since 5.1      This signal is emitted when an SSL/TLS session has successfully     completed the initial handshake. At this point, no user data     has been transmitted. The signal can be used to perform     additional checks on the certificate chain, for example to     notify users when the certificate for a website has changed.     If the reply does not match the expected criteria then it should     be aborted by calling QNetworkReply::abort() by a slot connected     to this signal. The SSL configuration in use can be inspected     using the QNetworkReply::sslConfiguration() method.      Internally, QNetworkAccessManager may open multiple connections     to a server, in order to allow it process requests in parallel.     These connections may be reused, which means that the encrypted()     signal would not be emitted. This means that you are only     guaranteed to receive this signal for the first connection to a     site in the lifespan of the QNetworkAccessManager.      \sa QSslSocket::encrypted()     \sa QNetworkAccessManager::encrypted() */
end_comment
begin_comment
comment|/*!     \fn void QNetworkReply::sslErrors(const QList<QSslError>&errors)      This signal is emitted if the SSL/TLS session encountered errors     during the set up, including certificate verification errors. The     \a errors parameter contains the list of errors.      To indicate that the errors are not fatal and that the connection     should proceed, the ignoreSslErrors() function should be called     from the slot connected to this signal. If it is not called, the     SSL session will be torn down before any data is exchanged     (including the URL).      This signal can be used to display an error message to the user     indicating that security may be compromised and display the     SSL settings (see sslConfiguration() to obtain it). If the user     decides to proceed after analyzing the remote certificate, the     slot should call ignoreSslErrors().      \sa QSslSocket::sslErrors(), QNetworkAccessManager::sslErrors(),     sslConfiguration(), ignoreSslErrors() */
end_comment
begin_comment
comment|/*!     \fn void QNetworkReply::preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator)     \since 5.5      This signal is emitted if the SSL/TLS handshake negotiates a PSK     ciphersuite, and therefore a PSK authentication is then required.      When using PSK, the client must send to the server a valid identity and a     valid pre shared key, in order for the SSL handshake to continue.     Applications can provide this information in a slot connected to this     signal, by filling in the passed \a authenticator object according to their     needs.      \note Ignoring this signal, or failing to provide the required credentials,     will cause the handshake to fail, and therefore the connection to be aborted.      \note The \a authenticator object is owned by the reply and must not be     deleted by the application.      \sa QSslPreSharedKeyAuthenticator */
end_comment
begin_comment
comment|/*!     \fn void QNetworkReply::metaDataChanged()      \omit FIXME: Update name? \endomit      This signal is emitted whenever the metadata in this reply     changes. metadata is any information that is not the content     (data) itself, including the network headers. In the majority of     cases, the metadata will be known fully by the time the first     byte of data is received. However, it is possible to receive     updates of headers or other metadata during the processing of the     data.      \sa header(), rawHeaderList(), rawHeader(), hasRawHeader() */
end_comment
begin_comment
comment|/*!     \fn void QNetworkReply::finished()      This signal is emitted when the reply has finished     processing. After this signal is emitted, there will be no more     updates to the reply's data or metadata.      Unless close() or abort() have been called, the reply will be still be opened     for reading, so the data can be retrieved by calls to read() or     readAll(). In particular, if no calls to read() were made as a     result of readyRead(), a call to readAll() will retrieve the full     contents in a QByteArray.      This signal is emitted in tandem with     QNetworkAccessManager::finished() where that signal's reply     parameter is this object.      \note Do not delete the object in the slot connected to this     signal. Use deleteLater().      You can also use isFinished() to check if a QNetworkReply     has finished even before you receive the finished() signal.      \sa QNetworkAccessManager::finished(), isFinished() */
end_comment
begin_comment
comment|/*!     \fn void QNetworkReply::error(QNetworkReply::NetworkError code)      This signal is emitted when the reply detects an error in     processing. The finished() signal will probably follow, indicating     that the connection is over.      The \a code parameter contains the code of the error that was     detected. Call errorString() to obtain a textual representation of     the error condition.      \note Do not delete the object in the slot connected to this     signal. Use deleteLater().      \sa error(), errorString() */
end_comment
begin_comment
comment|/*!     \fn void QNetworkReply::uploadProgress(qint64 bytesSent, qint64 bytesTotal)      This signal is emitted to indicate the progress of the upload part     of this network request, if there's any. If there's no upload     associated with this request, this signal will not be emitted.      The \a bytesSent     parameter indicates the number of bytes uploaded, while \a     bytesTotal indicates the total number of bytes to be uploaded. If     the number of bytes to be uploaded could not be determined, \a     bytesTotal will be -1.      The upload is finished when \a bytesSent is equal to \a     bytesTotal. At that time, \a bytesTotal will not be -1.      \sa downloadProgress() */
end_comment
begin_comment
comment|/*!     \fn void QNetworkReply::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)      This signal is emitted to indicate the progress of the download     part of this network request, if there's any. If there's no     download associated with this request, this signal will be emitted     once with 0 as the value of both \a bytesReceived and \a     bytesTotal.      The \a bytesReceived parameter indicates the number of bytes     received, while \a bytesTotal indicates the total number of bytes     expected to be downloaded. If the number of bytes to be downloaded     is not known, \a bytesTotal will be -1.      The download is finished when \a bytesReceived is equal to \a     bytesTotal. At that time, \a bytesTotal will not be -1.      Note that the values of both \a bytesReceived and \a bytesTotal     may be different from size(), the total number of bytes     obtained through read() or readAll(), or the value of the     header(ContentLengthHeader). The reason for that is that there may     be protocol overhead or the data may be compressed during the     download.      \sa uploadProgress(), bytesAvailable() */
end_comment
begin_comment
comment|/*!     \fn void QNetworkReply::abort()      Aborts the operation immediately and close down any network     connections still open. Uploads still in progress are also     aborted.      The finished() signal will also be emitted.      \sa close(), finished() */
end_comment
begin_comment
comment|/*!     Creates a QNetworkReply object with parent \a parent.      You cannot directly instantiate QNetworkReply objects. Use     QNetworkAccessManager functions to do that. */
end_comment
begin_constructor
DECL|function|QNetworkReply
name|QNetworkReply
operator|::
name|QNetworkReply
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QIODevice
argument_list|(
operator|*
operator|new
name|QNetworkReplyPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QNetworkReply
name|QNetworkReply
operator|::
name|QNetworkReply
parameter_list|(
name|QNetworkReplyPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QIODevice
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Disposes of this reply and frees any resources associated with     it. If any network connections are still open, they will be     closed.      \sa abort(), close() */
end_comment
begin_destructor
DECL|function|~QNetworkReply
name|QNetworkReply
operator|::
name|~
name|QNetworkReply
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Closes this device for reading. Unread data is discarded, but the     network resources are not discarded until they are finished. In     particular, if any upload is in progress, it will continue until     it is done.      The finished() signal is emitted when all operations are over and     the network resources are freed.      \sa abort(), finished() */
end_comment
begin_function
DECL|function|close
name|void
name|QNetworkReply
operator|::
name|close
parameter_list|()
block|{
name|QIODevice
operator|::
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|isSequential
name|bool
name|QNetworkReply
operator|::
name|isSequential
parameter_list|()
specifier|const
block|{
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the size of the read buffer, in bytes.      \sa setReadBufferSize() */
end_comment
begin_function
DECL|function|readBufferSize
name|qint64
name|QNetworkReply
operator|::
name|readBufferSize
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|readBufferMaxSize
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the size of the read buffer to be \a size bytes. The read     buffer is the buffer that holds data that is being downloaded off     the network, before it is read with QIODevice::read(). Setting the     buffer size to 0 will make the buffer unlimited in size.      QNetworkReply will try to stop reading from the network once this     buffer is full (i.e., bytesAvailable() returns \a size or more),     thus causing the download to throttle down as well. If the buffer     is not limited in size, QNetworkReply will try to download as fast     as possible from the network.      Unlike QAbstractSocket::setReadBufferSize(), QNetworkReply cannot     guarantee precision in the read buffer size. That is,     bytesAvailable() can return more than \a size.      \sa readBufferSize() */
end_comment
begin_function
DECL|function|setReadBufferSize
name|void
name|QNetworkReply
operator|::
name|setReadBufferSize
parameter_list|(
name|qint64
name|size
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QNetworkReply
argument_list|)
expr_stmt|;
name|d
operator|->
name|readBufferMaxSize
operator|=
name|size
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the QNetworkAccessManager that was used to create this     QNetworkReply object. Initially, it is also the parent object. */
end_comment
begin_function
DECL|function|manager
name|QNetworkAccessManager
modifier|*
name|QNetworkReply
operator|::
name|manager
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|manager
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the request that was posted for this reply. In special,     note that the URL for the request may be different than that of     the reply.      \sa QNetworkRequest::url(), url(), setRequest() */
end_comment
begin_function
DECL|function|request
name|QNetworkRequest
name|QNetworkReply
operator|::
name|request
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|request
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the operation that was posted for this reply.      \sa setOperation() */
end_comment
begin_function
DECL|function|operation
name|QNetworkAccessManager
operator|::
name|Operation
name|QNetworkReply
operator|::
name|operation
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|operation
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the error that was found during the processing of this     request. If no error was found, returns NoError.      \sa setError() */
end_comment
begin_function
DECL|function|error
name|QNetworkReply
operator|::
name|NetworkError
name|QNetworkReply
operator|::
name|error
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|errorCode
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.6      Returns \c true when the reply has finished or was aborted.      \sa isRunning() */
end_comment
begin_function
DECL|function|isFinished
name|bool
name|QNetworkReply
operator|::
name|isFinished
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|isFinished
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.6      Returns \c true when the request is still processing and the     reply has not finished or was aborted yet.      \sa isFinished() */
end_comment
begin_function
DECL|function|isRunning
name|bool
name|QNetworkReply
operator|::
name|isRunning
parameter_list|()
specifier|const
block|{
return|return
operator|!
name|isFinished
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the URL of the content downloaded or uploaded. Note that     the URL may be different from that of the original request.      \sa request(), setUrl(), QNetworkRequest::url() */
end_comment
begin_function
DECL|function|url
name|QUrl
name|QNetworkReply
operator|::
name|url
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|url
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the value of the known header \a header, if that header     was sent by the remote server. If the header was not sent, returns     an invalid QVariant.      \sa rawHeader(), setHeader(), QNetworkRequest::header() */
end_comment
begin_function
DECL|function|header
name|QVariant
name|QNetworkReply
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
name|d_func
argument_list|()
operator|->
name|cookedHeaders
operator|.
name|value
argument_list|(
name|header
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the raw header of name \a headerName was sent by     the remote server      \sa rawHeader() */
end_comment
begin_function
DECL|function|hasRawHeader
name|bool
name|QNetworkReply
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
name|Q_D
argument_list|(
specifier|const
name|QNetworkReply
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|findRawHeader
argument_list|(
name|headerName
argument_list|)
operator|!=
name|d
operator|->
name|rawHeaders
operator|.
name|constEnd
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the raw contents of the header \a headerName as sent by     the remote server. If there is no such header, returns an empty     byte array, which may be indistinguishable from an empty     header. Use hasRawHeader() to verify if the server sent such     header field.      \sa setRawHeader(), hasRawHeader(), header() */
end_comment
begin_function
DECL|function|rawHeader
name|QByteArray
name|QNetworkReply
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
name|Q_D
argument_list|(
specifier|const
name|QNetworkReply
argument_list|)
expr_stmt|;
name|QNetworkHeadersPrivate
operator|::
name|RawHeadersList
operator|::
name|ConstIterator
name|it
init|=
name|d
operator|->
name|findRawHeader
argument_list|(
name|headerName
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|!=
name|d
operator|->
name|rawHeaders
operator|.
name|constEnd
argument_list|()
condition|)
return|return
name|it
operator|->
name|second
return|;
return|return
name|QByteArray
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \typedef QNetworkReply::RawHeaderPair    RawHeaderPair is a QPair<QByteArray, QByteArray> where the first   QByteArray is the header name and the second is the header.  */
end_comment
begin_comment
comment|/*!   Returns a list of raw header pairs.  */
end_comment
begin_function
DECL|function|rawHeaderPairs
specifier|const
name|QList
argument_list|<
name|QNetworkReply
operator|::
name|RawHeaderPair
argument_list|>
modifier|&
name|QNetworkReply
operator|::
name|rawHeaderPairs
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QNetworkReply
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|rawHeaders
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a list of headers fields that were sent by the remote     server, in the order that they were sent. Duplicate headers are     merged together and take place of the latter duplicate. */
end_comment
begin_function
DECL|function|rawHeaderList
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QNetworkReply
operator|::
name|rawHeaderList
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|rawHeadersKeys
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the attribute associated with the code \a code. If the     attribute has not been set, it returns an invalid QVariant (type QMetaType::UnknownType).      You can expect the default values listed in     QNetworkRequest::Attribute to be applied to the values returned by     this function.      \sa setAttribute(), QNetworkRequest::Attribute */
end_comment
begin_function
DECL|function|attribute
name|QVariant
name|QNetworkReply
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
name|d_func
argument_list|()
operator|->
name|attributes
operator|.
name|value
argument_list|(
name|code
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SSL
end_ifndef
begin_comment
comment|/*!     Returns the SSL configuration and state associated with this     reply, if SSL was used. It will contain the remote server's     certificate, its certificate chain leading to the Certificate     Authority as well as the encryption ciphers in use.      The peer's certificate and its certificate chain will be known by     the time sslErrors() is emitted, if it's emitted. */
end_comment
begin_function
DECL|function|sslConfiguration
name|QSslConfiguration
name|QNetworkReply
operator|::
name|sslConfiguration
parameter_list|()
specifier|const
block|{
name|QSslConfiguration
name|config
decl_stmt|;
name|sslConfigurationImplementation
argument_list|(
name|config
argument_list|)
expr_stmt|;
return|return
name|config
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the SSL configuration for the network connection associated     with this request, if possible, to be that of \a config. */
end_comment
begin_function
DECL|function|setSslConfiguration
name|void
name|QNetworkReply
operator|::
name|setSslConfiguration
parameter_list|(
specifier|const
name|QSslConfiguration
modifier|&
name|config
parameter_list|)
block|{
name|setSslConfigurationImplementation
argument_list|(
name|config
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \overload     \since 4.6      If this function is called, the SSL errors given in \a errors     will be ignored.      \note Because most SSL errors are associated with a certificate, for most     of them you must set the expected certificate this SSL error is related to.     If, for instance, you want to issue a request to a server that uses     a self-signed certificate, consider the following snippet:      \snippet code/src_network_access_qnetworkreply.cpp 0      Multiple calls to this function will replace the list of errors that     were passed in previous calls.     You can clear the list of errors you want to ignore by calling this     function with an empty list.      \sa sslConfiguration(), sslErrors(), QSslSocket::ignoreSslErrors() */
end_comment
begin_function
DECL|function|ignoreSslErrors
name|void
name|QNetworkReply
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
name|ignoreSslErrorsImplementation
argument_list|(
name|errors
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!   \fn void QNetworkReply::sslConfigurationImplementation(QSslConfiguration&configuration) const   \since 5.0    This virtual method is provided to enable overriding the behavior of   sslConfiguration(). sslConfiguration() is a public wrapper for this method.   The configuration will be returned in \a configuration.    \sa sslConfiguration() */
end_comment
begin_function
DECL|function|sslConfigurationImplementation
name|void
name|QNetworkReply
operator|::
name|sslConfigurationImplementation
parameter_list|(
name|QSslConfiguration
modifier|&
parameter_list|)
specifier|const
block|{ }
end_function
begin_comment
comment|/*!   \fn void QNetworkReply::setSslConfigurationImplementation(const QSslConfiguration&configuration)   \since 5.0    This virtual method is provided to enable overriding the behavior of   setSslConfiguration(). setSslConfiguration() is a public wrapper for this method.   If you override this method use \a configuration to set the SSL configuration.    \sa sslConfigurationImplementation(), setSslConfiguration() */
end_comment
begin_function
DECL|function|setSslConfigurationImplementation
name|void
name|QNetworkReply
operator|::
name|setSslConfigurationImplementation
parameter_list|(
specifier|const
name|QSslConfiguration
modifier|&
parameter_list|)
block|{ }
end_function
begin_comment
comment|/*!   \fn void QNetworkReply::ignoreSslErrorsImplementation(const QList<QSslError>&errors)   \since 5.0    This virtual method is provided to enable overriding the behavior of   ignoreSslErrors(). ignoreSslErrors() is a public wrapper for this method.   \a errors contains the errors the user wishes ignored.    \sa ignoreSslErrors() */
end_comment
begin_function
DECL|function|ignoreSslErrorsImplementation
name|void
name|QNetworkReply
operator|::
name|ignoreSslErrorsImplementation
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QSslError
argument_list|>
modifier|&
parameter_list|)
block|{ }
end_function
begin_comment
comment|/*!     If this function is called, SSL errors related to network     connection will be ignored, including certificate validation     errors.      \warning Be sure to always let the user inspect the errors     reported by the sslErrors() signal, and only call this method     upon confirmation from the user that proceeding is ok.     If there are unexpected errors, the reply should be aborted.     Calling this method without inspecting the actual errors will     most likely pose a security risk for your application. Use it     with great care!      This function can be called from the slot connected to the     sslErrors() signal, which indicates which errors were     found.      \sa sslConfiguration(), sslErrors(), QSslSocket::ignoreSslErrors() */
end_comment
begin_function
DECL|function|ignoreSslErrors
name|void
name|QNetworkReply
operator|::
name|ignoreSslErrors
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|writeData
name|qint64
name|QNetworkReply
operator|::
name|writeData
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|qint64
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
comment|// you can't write
block|}
end_function
begin_comment
comment|/*!     Sets the associated operation for this object to be \a     operation. This value will be returned by operation().      \note The operation should be set when this object is created and     not changed again.      \sa operation(), setRequest() */
end_comment
begin_function
DECL|function|setOperation
name|void
name|QNetworkReply
operator|::
name|setOperation
parameter_list|(
name|QNetworkAccessManager
operator|::
name|Operation
name|operation
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QNetworkReply
argument_list|)
expr_stmt|;
name|d
operator|->
name|operation
operator|=
name|operation
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the associated request for this object to be \a request. This     value will be returned by request().      \note The request should be set when this object is created and     not changed again.      \sa request(), setOperation() */
end_comment
begin_function
DECL|function|setRequest
name|void
name|QNetworkReply
operator|::
name|setRequest
parameter_list|(
specifier|const
name|QNetworkRequest
modifier|&
name|request
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QNetworkReply
argument_list|)
expr_stmt|;
name|d
operator|->
name|request
operator|=
name|request
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the error condition to be \a errorCode. The human-readable     message is set with \a errorString.      Calling setError() does not emit the error(QNetworkReply::NetworkError)     signal.      \sa error(), errorString() */
end_comment
begin_function
DECL|function|setError
name|void
name|QNetworkReply
operator|::
name|setError
parameter_list|(
name|NetworkError
name|errorCode
parameter_list|,
specifier|const
name|QString
modifier|&
name|errorString
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QNetworkReply
argument_list|)
expr_stmt|;
name|d
operator|->
name|errorCode
operator|=
name|errorCode
expr_stmt|;
name|setErrorString
argument_list|(
name|errorString
argument_list|)
expr_stmt|;
comment|// in QIODevice
block|}
end_function
begin_comment
comment|/*!     \since 4.8     Sets the reply as \a finished.      After having this set the replies data must not change.      \sa isFinished() */
end_comment
begin_function
DECL|function|setFinished
name|void
name|QNetworkReply
operator|::
name|setFinished
parameter_list|(
name|bool
name|finished
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QNetworkReply
argument_list|)
expr_stmt|;
name|d
operator|->
name|isFinished
operator|=
name|finished
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the URL being processed to be \a url. Normally, the URL     matches that of the request that was posted, but for a variety of     reasons it can be different (for example, a file path being made     absolute or canonical).      \sa url(), request(), QNetworkRequest::url() */
end_comment
begin_function
DECL|function|setUrl
name|void
name|QNetworkReply
operator|::
name|setUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QNetworkReply
argument_list|)
expr_stmt|;
name|d
operator|->
name|url
operator|=
name|url
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the known header \a header to be of value \a value. The     corresponding raw form of the header will be set as well.      \sa header(), setRawHeader(), QNetworkRequest::setHeader() */
end_comment
begin_function
DECL|function|setHeader
name|void
name|QNetworkReply
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
name|Q_D
argument_list|(
name|QNetworkReply
argument_list|)
expr_stmt|;
name|d
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
begin_comment
comment|/*!     Sets the raw header \a headerName to be of value \a value. If \a     headerName was previously set, it is overridden. Multiple HTTP     headers of the same name are functionally equivalent to one single     header with the values concatenated, separated by commas.      If \a headerName matches a known header, the value \a value will     be parsed and the corresponding parsed form will also be set.      \sa rawHeader(), header(), setHeader(), QNetworkRequest::setRawHeader() */
end_comment
begin_function
DECL|function|setRawHeader
name|void
name|QNetworkReply
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
name|value
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QNetworkReply
argument_list|)
expr_stmt|;
name|d
operator|->
name|setRawHeader
argument_list|(
name|headerName
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the attribute \a code to have value \a value. If \a code was     previously set, it will be overridden. If \a value is an invalid     QVariant, the attribute will be unset.      \sa attribute(), QNetworkRequest::setAttribute() */
end_comment
begin_function
DECL|function|setAttribute
name|void
name|QNetworkReply
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
name|Q_D
argument_list|(
name|QNetworkReply
argument_list|)
expr_stmt|;
if|if
condition|(
name|value
operator|.
name|isValid
argument_list|()
condition|)
name|d
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
name|d
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
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
