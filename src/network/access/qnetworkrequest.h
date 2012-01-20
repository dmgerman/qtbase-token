begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKREQUEST_H
end_ifndef
begin_define
DECL|macro|QNETWORKREQUEST_H
define|#
directive|define
name|QNETWORKREQUEST_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QSharedDataPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUrl>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Network
parameter_list|)
name|class
name|QSslConfiguration
decl_stmt|;
DECL|variable|QNetworkRequestPrivate
name|class
name|QNetworkRequestPrivate
decl_stmt|;
name|class
name|Q_NETWORK_EXPORT
name|QNetworkRequest
decl_stmt|{ public:     enum KnownHeaders
block|{
name|ContentTypeHeader
operator|,
name|ContentLengthHeader
operator|,
name|LocationHeader
operator|,
name|LastModifiedHeader
operator|,
name|CookieHeader
operator|,
name|SetCookieHeader
operator|,
name|ContentDispositionHeader
operator|,
comment|// added for QMultipartMessage
name|UserAgentHeader
operator|,
name|ServerHeader
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_enum
enum|enum
name|Attribute
block|{
name|HttpStatusCodeAttribute
block|,
name|HttpReasonPhraseAttribute
block|,
name|RedirectionTargetAttribute
block|,
name|ConnectionEncryptedAttribute
block|,
name|CacheLoadControlAttribute
block|,
name|CacheSaveControlAttribute
block|,
name|SourceIsFromCacheAttribute
block|,
name|DoNotBufferUploadDataAttribute
block|,
name|HttpPipeliningAllowedAttribute
block|,
name|HttpPipeliningWasUsedAttribute
block|,
name|CustomVerbAttribute
block|,
name|CookieLoadControlAttribute
block|,
name|AuthenticationReuseAttribute
block|,
name|CookieSaveControlAttribute
block|,
name|MaximumDownloadBufferSizeAttribute
block|,
comment|// internal
name|DownloadBufferAttribute
block|,
comment|// internal
name|SynchronousRequestAttribute
block|,
comment|// internal
name|User
init|=
literal|1000
block|,
name|UserMax
init|=
literal|32767
block|}
enum|;
end_enum
begin_enum
enum|enum
name|CacheLoadControl
block|{
name|AlwaysNetwork
block|,
name|PreferNetwork
block|,
name|PreferCache
block|,
name|AlwaysCache
block|}
enum|;
end_enum
begin_enum
enum|enum
name|LoadControl
block|{
name|Automatic
init|=
literal|0
block|,
name|Manual
block|}
enum|;
end_enum
begin_enum
enum|enum
name|Priority
block|{
name|HighPriority
init|=
literal|1
block|,
name|NormalPriority
init|=
literal|3
block|,
name|LowPriority
init|=
literal|5
block|}
enum|;
end_enum
begin_function_decl
name|explicit
name|QNetworkRequest
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
init|=
name|QUrl
argument_list|()
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QNetworkRequest
argument_list|(
specifier|const
name|QNetworkRequest
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QNetworkRequest
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QNetworkRequest
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QNetworkRequest
operator|&
name|other
operator|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QNetworkRequest
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QNetworkRequest
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QUrl
name|url
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// "cooked" headers
end_comment
begin_decl_stmt
name|QVariant
name|header
argument_list|(
name|KnownHeaders
name|header
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setHeader
parameter_list|(
name|KnownHeaders
name|header
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// raw headers:
end_comment
begin_decl_stmt
name|bool
name|hasRawHeader
argument_list|(
specifier|const
name|QByteArray
operator|&
name|headerName
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|QByteArray
operator|>
name|rawHeaderList
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QByteArray
name|rawHeader
argument_list|(
specifier|const
name|QByteArray
operator|&
name|headerName
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
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
function_decl|;
end_function_decl
begin_comment
comment|// attributes
end_comment
begin_decl_stmt
name|QVariant
name|attribute
argument_list|(
name|Attribute
name|code
argument_list|,
specifier|const
name|QVariant
operator|&
name|defaultValue
operator|=
name|QVariant
argument_list|()
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setAttribute
parameter_list|(
name|Attribute
name|code
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
end_ifndef
begin_expr_stmt
name|QSslConfiguration
name|sslConfiguration
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setSslConfiguration
parameter_list|(
specifier|const
name|QSslConfiguration
modifier|&
name|configuration
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|setOriginatingObject
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QObject
operator|*
name|originatingObject
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Priority
name|priority
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPriority
parameter_list|(
name|Priority
name|priority
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|QSharedDataPointer
operator|<
name|QNetworkRequestPrivate
operator|>
name|d
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|friend
name|class
name|QNetworkRequestPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QNetworkRequest
argument_list|)
name|QT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
