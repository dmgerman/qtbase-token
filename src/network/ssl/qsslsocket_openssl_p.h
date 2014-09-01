begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** In addition, as a special exception, the copyright holders listed above give ** permission to link the code of its release of Qt with the OpenSSL project's ** "OpenSSL" library (or modified versions of the "OpenSSL" library that use the ** same license as the original version), and distribute the linked executables. ** ** You must comply with the GNU General Public License version 2 in all ** respects for all of the code used other than the "OpenSSL" code.  If you ** modify this file, you may extend this exception to your version of the file, ** but you are not obligated to do so.  If you do not wish to do so, delete ** this exception statement from your version of this file. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLSOCKET_OPENSSL_P_H
end_ifndef
begin_define
DECL|macro|QSSLSOCKET_OPENSSL_P_H
define|#
directive|define
name|QSSLSOCKET_OPENSSL_P_H
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
comment|// of the QLibrary class.  This header file may change from
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
file|"qsslsocket_p.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|OCSP_RESPONSE
argument_list|)
end_if
begin_undef
DECL|macro|OCSP_RESPONSE
undef|#
directive|undef
name|OCSP_RESPONSE
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|X509_NAME
argument_list|)
end_if
begin_undef
DECL|macro|X509_NAME
undef|#
directive|undef
name|X509_NAME
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WIN
end_comment
begin_include
include|#
directive|include
file|<openssl/asn1.h>
end_include
begin_include
include|#
directive|include
file|<openssl/bio.h>
end_include
begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include
begin_include
include|#
directive|include
file|<openssl/err.h>
end_include
begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include
begin_include
include|#
directive|include
file|<openssl/pem.h>
end_include
begin_include
include|#
directive|include
file|<openssl/pkcs12.h>
end_include
begin_include
include|#
directive|include
file|<openssl/pkcs7.h>
end_include
begin_include
include|#
directive|include
file|<openssl/rand.h>
end_include
begin_include
include|#
directive|include
file|<openssl/ssl.h>
end_include
begin_include
include|#
directive|include
file|<openssl/stack.h>
end_include
begin_include
include|#
directive|include
file|<openssl/x509.h>
end_include
begin_include
include|#
directive|include
file|<openssl/x509v3.h>
end_include
begin_include
include|#
directive|include
file|<openssl/x509_vfy.h>
end_include
begin_include
include|#
directive|include
file|<openssl/dsa.h>
end_include
begin_include
include|#
directive|include
file|<openssl/rsa.h>
end_include
begin_include
include|#
directive|include
file|<openssl/crypto.h>
end_include
begin_if
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|>=
literal|0x0090806fL
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_TLSEXT
argument_list|)
end_if
begin_include
include|#
directive|include
file|<openssl/tls1.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|>=
literal|0x10000000L
end_if
begin_typedef
DECL|typedef|STACK
typedef|typedef
name|_STACK
name|STACK
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QSslSocketBackendPrivate
range|:
name|public
name|QSslSocketPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QSslSocket
argument_list|)
name|public
operator|:
name|QSslSocketBackendPrivate
argument_list|()
block|;
name|virtual
operator|~
name|QSslSocketBackendPrivate
argument_list|()
block|;
comment|// SSL context
name|bool
name|initSslContext
argument_list|()
block|;
name|void
name|destroySslContext
argument_list|()
block|;
name|SSL
operator|*
name|ssl
block|;
name|BIO
operator|*
name|readBio
block|;
name|BIO
operator|*
name|writeBio
block|;
name|SSL_SESSION
operator|*
name|session
block|;
name|QList
operator|<
name|QPair
operator|<
name|int
block|,
name|int
operator|>
expr|>
name|errorList
block|;
comment|// Platform specific functions
name|void
name|startClientEncryption
argument_list|()
block|;
name|void
name|startServerEncryption
argument_list|()
block|;
name|void
name|transmit
argument_list|()
block|;
name|bool
name|startHandshake
argument_list|()
block|;
name|void
name|disconnectFromHost
argument_list|()
block|;
name|void
name|disconnected
argument_list|()
block|;
name|QSslCipher
name|sessionCipher
argument_list|()
specifier|const
block|;
name|QSsl
operator|::
name|SslProtocol
name|sessionProtocol
argument_list|()
specifier|const
block|;
name|void
name|continueHandshake
argument_list|()
block|;
name|bool
name|checkSslErrors
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|void
name|fetchCaRootForCert
argument_list|(
specifier|const
name|QSslCertificate
operator|&
name|cert
argument_list|)
block|;
name|void
name|_q_caRootLoaded
argument_list|(
name|QSslCertificate
argument_list|,
name|QSslCertificate
argument_list|)
block|;
endif|#
directive|endif
name|Q_AUTOTEST_EXPORT
specifier|static
name|long
name|setupOpenSslOptions
argument_list|(
argument|QSsl::SslProtocol protocol
argument_list|,
argument|QSsl::SslOptions sslOptions
argument_list|)
block|;
specifier|static
name|QSslCipher
name|QSslCipher_from_SSL_CIPHER
argument_list|(
name|SSL_CIPHER
operator|*
name|cipher
argument_list|)
block|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|STACKOFX509_to_QSslCertificates
argument_list|(
name|STACK_OF
argument_list|(
name|X509
argument_list|)
operator|*
name|x509
argument_list|)
block|;
specifier|static
name|QList
operator|<
name|QSslError
operator|>
name|verify
argument_list|(
name|QList
operator|<
name|QSslCertificate
operator|>
name|certificateChain
argument_list|,
specifier|const
name|QString
operator|&
name|hostName
argument_list|)
block|;
specifier|static
name|QString
name|getErrorsFromOpenSsl
argument_list|()
block|;
specifier|static
name|bool
name|importPKCS12
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|,
name|QSslKey
operator|*
name|key
argument_list|,
name|QSslCertificate
operator|*
name|cert
argument_list|,
name|QList
operator|<
name|QSslCertificate
operator|>
operator|*
name|caCertificates
argument_list|,
specifier|const
name|QByteArray
operator|&
name|passPhrase
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_decl_stmt
name|class
name|QWindowsCaRootFetcher
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
block|;
name|public
operator|:
name|QWindowsCaRootFetcher
argument_list|(
argument|const QSslCertificate&certificate
argument_list|,
argument|QSslSocket::SslMode sslMode
argument_list|)
block|;
operator|~
name|QWindowsCaRootFetcher
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|start
argument_list|()
block|;
name|signals
operator|:
name|void
name|finished
argument_list|(
argument|QSslCertificate brokenChain
argument_list|,
argument|QSslCertificate caroot
argument_list|)
block|;
name|private
operator|:
name|QSslCertificate
name|cert
block|;
name|QSslSocket
operator|::
name|SslMode
name|mode
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
