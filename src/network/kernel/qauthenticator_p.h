begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QAUTHENTICATOR_P_H
end_ifndef
begin_define
DECL|macro|QAUTHENTICATOR_P_H
define|#
directive|define
name|QAUTHENTICATOR_P_H
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
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qauthenticator.h>
end_include
begin_include
include|#
directive|include
file|<qvariant.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QHttpResponseHeader
name|class
name|QHttpResponseHeader
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN32
end_ifdef
begin_decl_stmt
DECL|variable|QNtlmWindowsHandles
name|class
name|QNtlmWindowsHandles
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QAuthenticatorPrivate
block|{
name|public
label|:
enum|enum
name|Method
block|{
name|None
block|,
name|Basic
block|,
name|Plain
block|,
name|Login
block|,
name|Ntlm
block|,
name|CramMd5
block|,
name|DigestMd5
block|}
enum|;
name|QAuthenticatorPrivate
argument_list|()
expr_stmt|;
operator|~
name|QAuthenticatorPrivate
argument_list|()
expr_stmt|;
name|QString
name|user
decl_stmt|;
name|QString
name|extractedUser
decl_stmt|;
name|QString
name|password
decl_stmt|;
name|QVariantHash
name|options
decl_stmt|;
name|Method
name|method
decl_stmt|;
name|QString
name|realm
decl_stmt|;
name|QByteArray
name|challenge
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QNtlmWindowsHandles
modifier|*
name|ntlmWindowsHandles
decl_stmt|;
endif|#
directive|endif
name|bool
name|hasFailed
decl_stmt|;
comment|//credentials have been tried but rejected by server.
enum|enum
name|Phase
block|{
name|Start
block|,
name|Phase2
block|,
name|Done
block|,
name|Invalid
block|}
enum|;
name|Phase
name|phase
decl_stmt|;
comment|// digest specific
name|QByteArray
name|cnonce
decl_stmt|;
name|int
name|nonceCount
decl_stmt|;
comment|// ntlm specific
name|QString
name|workstation
decl_stmt|;
name|QString
name|userDomain
decl_stmt|;
name|QByteArray
name|calculateResponse
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|method
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|path
parameter_list|)
function_decl|;
specifier|inline
specifier|static
name|QAuthenticatorPrivate
modifier|*
name|getPrivate
parameter_list|(
name|QAuthenticator
modifier|&
name|auth
parameter_list|)
block|{
return|return
name|auth
operator|.
name|d
return|;
block|}
specifier|inline
specifier|static
specifier|const
name|QAuthenticatorPrivate
modifier|*
name|getPrivate
parameter_list|(
specifier|const
name|QAuthenticator
modifier|&
name|auth
parameter_list|)
block|{
return|return
name|auth
operator|.
name|d
return|;
block|}
name|QByteArray
name|digestMd5Response
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|challenge
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|method
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|path
parameter_list|)
function_decl|;
specifier|static
name|QHash
operator|<
name|QByteArray
operator|,
name|QByteArray
operator|>
name|parseDigestAuthenticationChallenge
argument_list|(
specifier|const
name|QByteArray
operator|&
name|challenge
argument_list|)
expr_stmt|;
name|void
name|parseHttpResponse
argument_list|(
specifier|const
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
argument_list|,
name|QByteArray
operator|>
expr|>
operator|&
argument_list|,
name|bool
name|isProxy
argument_list|)
decl_stmt|;
name|void
name|updateCredentials
parameter_list|()
function_decl|;
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
