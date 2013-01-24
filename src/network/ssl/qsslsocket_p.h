begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLSOCKET_P_H
end_ifndef
begin_define
DECL|macro|QSSLSOCKET_P_H
define|#
directive|define
name|QSSLSOCKET_P_H
end_define
begin_include
include|#
directive|include
file|"qsslsocket.h"
end_include
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
file|<private/qtcpsocket_p.h>
end_include
begin_include
include|#
directive|include
file|"qsslkey.h"
end_include
begin_include
include|#
directive|include
file|"qsslconfiguration_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<private/qringbuffer_p.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_include
include|#
directive|include
file|<Security/SecCertificate.h>
end_include
begin_include
include|#
directive|include
file|<CoreFoundation/CFArray.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<wincrypt.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|HCRYPTPROV_LEGACY
end_ifndef
begin_define
DECL|macro|HCRYPTPROV_LEGACY
define|#
directive|define
name|HCRYPTPROV_LEGACY
value|HCRYPTPROV
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_IOS
argument_list|)
end_if
begin_typedef
DECL|typedef|PtrSecCertificateGetData
typedef|typedef
name|OSStatus
function_decl|(
modifier|*
name|PtrSecCertificateGetData
function_decl|)
parameter_list|(
name|SecCertificateRef
parameter_list|,
name|CSSM_DATA_PTR
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrSecTrustSettingsCopyCertificates
typedef|typedef
name|OSStatus
function_decl|(
modifier|*
name|PtrSecTrustSettingsCopyCertificates
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|CFArrayRef
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrSecTrustCopyAnchorCertificates
typedef|typedef
name|OSStatus
function_decl|(
modifier|*
name|PtrSecTrustCopyAnchorCertificates
function_decl|)
parameter_list|(
name|CFArrayRef
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_typedef
DECL|typedef|PtrCertOpenSystemStoreW
typedef|typedef
name|HCERTSTORE
function_decl|(
name|WINAPI
modifier|*
name|PtrCertOpenSystemStoreW
function_decl|)
parameter_list|(
name|LPCSTR
parameter_list|,
name|DWORD
parameter_list|,
name|HCRYPTPROV_LEGACY
parameter_list|,
name|DWORD
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_typedef
DECL|typedef|PtrCertOpenSystemStoreW
typedef|typedef
name|HCERTSTORE
function_decl|(
name|WINAPI
modifier|*
name|PtrCertOpenSystemStoreW
function_decl|)
parameter_list|(
name|HCRYPTPROV_LEGACY
parameter_list|,
name|LPCWSTR
parameter_list|)
function_decl|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|PtrCertFindCertificateInStore
typedef|typedef
name|PCCERT_CONTEXT
function_decl|(
name|WINAPI
modifier|*
name|PtrCertFindCertificateInStore
function_decl|)
parameter_list|(
name|HCERTSTORE
parameter_list|,
name|DWORD
parameter_list|,
name|DWORD
parameter_list|,
name|DWORD
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|PCCERT_CONTEXT
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrCertCloseStore
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PtrCertCloseStore
function_decl|)
parameter_list|(
name|HCERTSTORE
parameter_list|,
name|DWORD
parameter_list|)
function_decl|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QSslSocketPrivate
range|:
name|public
name|QTcpSocketPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QSslSocket
argument_list|)
name|public
operator|:
name|QSslSocketPrivate
argument_list|()
block|;
name|virtual
operator|~
name|QSslSocketPrivate
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
name|bool
name|initialized
block|;
name|QSslSocket
operator|::
name|SslMode
name|mode
block|;
name|bool
name|autoStartHandshake
block|;
name|bool
name|connectionEncrypted
block|;
name|bool
name|ignoreAllSslErrors
block|;
name|QList
operator|<
name|QSslError
operator|>
name|ignoreErrorsList
block|;
name|bool
operator|*
name|readyReadEmittedPointer
block|;
name|QSslConfigurationPrivate
name|configuration
block|;
name|QList
operator|<
name|QSslError
operator|>
name|sslErrors
block|;
comment|// if set, this hostname is used for certificate validation instead of the hostname
comment|// that was used for connecting to.
name|QString
name|verificationPeerName
block|;
name|bool
name|allowRootCertOnDemandLoading
block|;
specifier|static
name|bool
name|supportsSsl
argument_list|()
block|;
specifier|static
name|long
name|sslLibraryVersionNumber
argument_list|()
block|;
specifier|static
name|QString
name|sslLibraryVersionString
argument_list|()
block|;
specifier|static
name|void
name|ensureInitialized
argument_list|()
block|;
specifier|static
name|void
name|deinitialize
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QSslCipher
operator|>
name|defaultCiphers
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QSslCipher
operator|>
name|supportedCiphers
argument_list|()
block|;
specifier|static
name|void
name|setDefaultCiphers
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCipher
operator|>
operator|&
name|ciphers
argument_list|)
block|;
specifier|static
name|void
name|setDefaultSupportedCiphers
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCipher
operator|>
operator|&
name|ciphers
argument_list|)
block|;
specifier|static
name|void
name|resetDefaultCiphers
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|defaultCaCertificates
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|systemCaCertificates
argument_list|()
block|;
specifier|static
name|void
name|setDefaultCaCertificates
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCertificate
operator|>
operator|&
name|certs
argument_list|)
block|;
specifier|static
name|bool
name|addDefaultCaCertificates
argument_list|(
argument|const QString&path
argument_list|,
argument|QSsl::EncodingFormat format
argument_list|,
argument|QRegExp::PatternSyntax syntax
argument_list|)
block|;
specifier|static
name|void
name|addDefaultCaCertificate
argument_list|(
specifier|const
name|QSslCertificate
operator|&
name|cert
argument_list|)
block|;
specifier|static
name|void
name|addDefaultCaCertificates
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCertificate
operator|>
operator|&
name|certs
argument_list|)
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_IOS
argument_list|)
specifier|static
name|PtrSecCertificateGetData
name|ptrSecCertificateGetData
block|;
specifier|static
name|PtrSecTrustSettingsCopyCertificates
name|ptrSecTrustSettingsCopyCertificates
block|;
specifier|static
name|PtrSecTrustCopyAnchorCertificates
name|ptrSecTrustCopyAnchorCertificates
block|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
specifier|static
name|PtrCertOpenSystemStoreW
name|ptrCertOpenSystemStoreW
block|;
specifier|static
name|PtrCertFindCertificateInStore
name|ptrCertFindCertificateInStore
block|;
specifier|static
name|PtrCertCloseStore
name|ptrCertCloseStore
block|;
endif|#
directive|endif
comment|// The socket itself, including private slots.
name|QTcpSocket
operator|*
name|plainSocket
block|;
name|void
name|createPlainSocket
argument_list|(
argument|QIODevice::OpenMode openMode
argument_list|)
block|;
specifier|static
name|void
name|pauseSocketNotifiers
argument_list|(
name|QSslSocket
operator|*
argument_list|)
block|;
specifier|static
name|void
name|resumeSocketNotifiers
argument_list|(
name|QSslSocket
operator|*
argument_list|)
block|;
name|bool
name|isPaused
argument_list|()
specifier|const
block|;
name|void
name|_q_connectedSlot
argument_list|()
block|;
name|void
name|_q_hostFoundSlot
argument_list|()
block|;
name|void
name|_q_disconnectedSlot
argument_list|()
block|;
name|void
name|_q_stateChangedSlot
argument_list|(
name|QAbstractSocket
operator|::
name|SocketState
argument_list|)
block|;
name|void
name|_q_errorSlot
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
argument_list|)
block|;
name|void
name|_q_readyReadSlot
argument_list|()
block|;
name|void
name|_q_bytesWrittenSlot
argument_list|(
name|qint64
argument_list|)
block|;
name|void
name|_q_flushWriteBuffer
argument_list|()
block|;
name|void
name|_q_flushReadBuffer
argument_list|()
block|;
name|void
name|_q_resumeImplementation
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|virtual
name|void
name|_q_caRootLoaded
argument_list|(
name|QSslCertificate
argument_list|,
name|QSslCertificate
argument_list|)
operator|=
literal|0
block|;
endif|#
directive|endif
name|virtual
name|qint64
name|peek
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxSize
argument_list|)
block|;
name|virtual
name|QByteArray
name|peek
argument_list|(
argument|qint64 maxSize
argument_list|)
block|;
comment|// Platform specific functions
name|virtual
name|void
name|startClientEncryption
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|startServerEncryption
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|transmit
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|disconnectFromHost
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|disconnected
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|QSslCipher
name|sessionCipher
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|continueHandshake
argument_list|()
operator|=
literal|0
block|;
name|Q_AUTOTEST_EXPORT
specifier|static
name|bool
name|rootCertOnDemandLoadingSupported
argument_list|()
block|;
name|private
operator|:
specifier|static
name|bool
name|ensureLibraryLoaded
argument_list|()
block|;
specifier|static
name|void
name|ensureCiphersAndCertsLoaded
argument_list|()
block|;
specifier|static
name|bool
name|s_libraryLoaded
block|;
specifier|static
name|bool
name|s_loadedCiphersAndCerts
block|;
name|protected
operator|:
name|bool
name|verifyErrorsHaveBeenIgnored
argument_list|()
block|;
specifier|static
name|bool
name|s_loadRootCertsOnDemand
block|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|unixRootCertDirectories
argument_list|()
block|;
name|bool
name|paused
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
