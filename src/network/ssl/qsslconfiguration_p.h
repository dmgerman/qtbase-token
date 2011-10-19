begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** In addition, as a special exception, Nokia gives permission to link ** the code of its release of Qt with the OpenSSL project's "OpenSSL" library ** (or modified versions of the "OpenSSL" library that use the same license ** as the original version), and distribute the linked executables. ** ** You must comply with the GNU General Public License version 2 in all ** respects for all of the code used other than the "OpenSSL" code.  If you ** modify this file, you may extend this exception to your version of the file, ** but you are not obligated to do so.  If you do not wish to do so, delete ** this exception statement from your version of this file. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLCONFIGURATION_P_H
end_ifndef
begin_define
DECL|macro|QSSLCONFIGURATION_P_H
define|#
directive|define
name|QSSLCONFIGURATION_P_H
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
comment|// of the QSslSocket API.  This header file may change from
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
file|"qsslconfiguration.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_include
include|#
directive|include
file|"qsslcertificate.h"
end_include
begin_include
include|#
directive|include
file|"qsslcipher.h"
end_include
begin_include
include|#
directive|include
file|"qsslkey.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QSslConfigurationPrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
name|QSslConfigurationPrivate
argument_list|()
operator|:
name|protocol
argument_list|(
name|QSsl
operator|::
name|SecureProtocols
argument_list|)
block|,
name|peerVerifyMode
argument_list|(
name|QSslSocket
operator|::
name|AutoVerifyPeer
argument_list|)
block|,
name|peerVerifyDepth
argument_list|(
literal|0
argument_list|)
block|{ }
name|QSslCertificate
name|peerCertificate
block|;
name|QList
operator|<
name|QSslCertificate
operator|>
name|peerCertificateChain
block|;
name|QSslCertificate
name|localCertificate
block|;
name|QSslKey
name|privateKey
block|;
name|QSslCipher
name|sessionCipher
block|;
name|QList
operator|<
name|QSslCipher
operator|>
name|ciphers
block|;
name|QList
operator|<
name|QSslCertificate
operator|>
name|caCertificates
block|;
name|QSsl
operator|::
name|SslProtocol
name|protocol
block|;
name|QSslSocket
operator|::
name|PeerVerifyMode
name|peerVerifyMode
block|;
name|int
name|peerVerifyDepth
block|;
name|QSsl
operator|::
name|SslOptions
name|sslOptions
block|;
comment|// in qsslsocket.cpp:
specifier|static
name|QSslConfiguration
name|defaultConfiguration
argument_list|()
block|;
specifier|static
name|void
name|setDefaultConfiguration
argument_list|(
specifier|const
name|QSslConfiguration
operator|&
name|configuration
argument_list|)
block|;
specifier|static
name|void
name|deepCopyDefaultConfiguration
argument_list|(
name|QSslConfigurationPrivate
operator|*
name|config
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// implemented here for inlining purposes
end_comment
begin_expr_stmt
DECL|function|QSslConfiguration
specifier|inline
name|QSslConfiguration
operator|::
name|QSslConfiguration
argument_list|(
name|QSslConfigurationPrivate
operator|*
name|dd
argument_list|)
operator|:
name|d
argument_list|(
argument|dd
argument_list|)
block|{ }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
