begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKACCESSAUTHENTICATIONMANAGER_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKACCESSAUTHENTICATIONMANAGER_P_H
define|#
directive|define
name|QNETWORKACCESSAUTHENTICATIONMANAGER_P_H
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
file|"qnetworkaccessmanager.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkaccesscache_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkaccessbackend_p.h"
end_include
begin_include
include|#
directive|include
file|"QtNetwork/qnetworkproxy.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/QMutex"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAuthenticator
name|class
name|QAuthenticator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractNetworkCache
name|class
name|QAbstractNetworkCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkAuthenticationCredential
name|class
name|QNetworkAuthenticationCredential
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkCookieJar
name|class
name|QNetworkCookieJar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkAuthenticationCredential
block|{
name|public
label|:
name|QString
name|domain
decl_stmt|;
name|QString
name|user
decl_stmt|;
name|QString
name|password
decl_stmt|;
name|bool
name|isNull
parameter_list|()
block|{
return|return
name|domain
operator|.
name|isNull
argument_list|()
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QNetworkAuthenticationCredential
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QNetworkAuthenticationCredential
operator|&
name|t1
operator|,
specifier|const
name|QString
operator|&
name|t2
operator|)
block|{
return|return
name|t1
operator|.
name|domain
operator|<
name|t2
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|class
name|QNetworkAccessAuthenticationManager
block|{
name|public
label|:
name|QNetworkAccessAuthenticationManager
argument_list|()
block|{ }
empty_stmt|;
name|void
name|cacheCredentials
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|,
specifier|const
name|QAuthenticator
modifier|*
name|auth
parameter_list|)
function_decl|;
name|QNetworkAuthenticationCredential
name|fetchCachedCredentials
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|,
specifier|const
name|QAuthenticator
modifier|*
name|auth
init|=
literal|0
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|void
name|cacheProxyCredentials
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
name|proxy
parameter_list|,
specifier|const
name|QAuthenticator
modifier|*
name|auth
parameter_list|)
function_decl|;
name|QNetworkAuthenticationCredential
name|fetchCachedProxyCredentials
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
name|proxy
parameter_list|,
specifier|const
name|QAuthenticator
modifier|*
name|auth
init|=
literal|0
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|clearCache
parameter_list|()
function_decl|;
name|protected
label|:
name|QNetworkAccessCache
name|authenticationCache
decl_stmt|;
name|QMutex
name|mutex
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
