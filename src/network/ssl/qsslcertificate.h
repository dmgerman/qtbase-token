begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLCERTIFICATE_H
end_ifndef
begin_define
DECL|macro|QSSLCERTIFICATE_H
define|#
directive|define
name|QSSLCERTIFICATE_H
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|verify
end_ifdef
begin_undef
DECL|macro|verify
undef|#
directive|undef
name|verify
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcryptographichash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qregexp.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qssl.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SSL
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDateTime
name|class
name|QDateTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslError
name|class
name|QSslError
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslKey
name|class
name|QSslKey
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslCertificateExtension
name|class
name|QSslCertificateExtension
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslCertificate
name|class
name|QSslCertificate
decl_stmt|;
end_decl_stmt
begin_comment
comment|// qHash is a friend, but we can't use default arguments for friends (Â§8.3.6.4)
end_comment
begin_decl_stmt
name|Q_NETWORK_EXPORT
name|uint
name|qHash
argument_list|(
specifier|const
name|QSslCertificate
operator|&
name|key
argument_list|,
name|uint
name|seed
operator|=
literal|0
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslCertificatePrivate
name|class
name|QSslCertificatePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QSslCertificate
block|{
name|public
label|:
enum|enum
name|SubjectInfo
block|{
name|Organization
block|,
name|CommonName
block|,
name|LocalityName
block|,
name|OrganizationalUnitName
block|,
name|CountryName
block|,
name|StateOrProvinceName
block|,
name|DistinguishedNameQualifier
block|,
name|SerialNumber
block|,
name|EmailAddress
block|}
enum|;
name|explicit
name|QSslCertificate
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|,
name|QSsl
operator|::
name|EncodingFormat
name|format
operator|=
name|QSsl
operator|::
name|Pem
argument_list|)
decl_stmt|;
name|explicit
name|QSslCertificate
argument_list|(
specifier|const
name|QByteArray
operator|&
name|data
operator|=
name|QByteArray
argument_list|()
argument_list|,
name|QSsl
operator|::
name|EncodingFormat
name|format
operator|=
name|QSsl
operator|::
name|Pem
argument_list|)
decl_stmt|;
name|QSslCertificate
argument_list|(
specifier|const
name|QSslCertificate
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QSslCertificate
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QSslCertificate
modifier|&
name|operator
init|=
operator|(
name|QSslCertificate
operator|&&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|QSslCertificate
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QSslCertificate
operator|&
name|other
operator|)
decl_stmt|;
name|void
name|swap
parameter_list|(
name|QSslCertificate
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSslCertificate
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSslCertificate
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
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
specifier|const
name|QDateTime
name|currentTime
operator|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
block|;
return|return
name|currentTime
operator|>=
name|effectiveDate
argument_list|()
operator|&&
name|currentTime
operator|<=
name|expiryDate
argument_list|()
operator|&&
operator|!
name|isBlacklisted
argument_list|()
return|;
block|}
endif|#
directive|endif
name|bool
name|isBlacklisted
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isSelfSigned
argument_list|()
specifier|const
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
comment|// Certificate info
name|QByteArray
name|version
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|serialNumber
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|digest
argument_list|(
name|QCryptographicHash
operator|::
name|Algorithm
name|algorithm
operator|=
name|QCryptographicHash
operator|::
name|Md5
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|issuerInfo
argument_list|(
name|SubjectInfo
name|info
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|issuerInfo
argument_list|(
specifier|const
name|QByteArray
operator|&
name|attribute
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|subjectInfo
argument_list|(
name|SubjectInfo
name|info
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|subjectInfo
argument_list|(
specifier|const
name|QByteArray
operator|&
name|attribute
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|QByteArray
operator|>
name|subjectInfoAttributes
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QByteArray
operator|>
name|issuerInfoAttributes
argument_list|()
specifier|const
expr_stmt|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|QMultiMap
operator|<
name|QSsl
operator|::
name|AlternateNameEntryType
operator|,
name|QString
operator|>
name|alternateSubjectNames
argument_list|()
specifier|const
block|{
return|return
name|subjectAlternativeNames
argument_list|()
return|;
block|}
endif|#
directive|endif
name|QMultiMap
operator|<
name|QSsl
operator|::
name|AlternativeNameEntryType
operator|,
name|QString
operator|>
name|subjectAlternativeNames
argument_list|()
specifier|const
expr_stmt|;
name|QDateTime
name|effectiveDate
argument_list|()
specifier|const
expr_stmt|;
name|QDateTime
name|expiryDate
argument_list|()
specifier|const
expr_stmt|;
name|QSslKey
name|publicKey
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QSslCertificateExtension
operator|>
name|extensions
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|toPem
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|toDer
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|toText
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|fromPath
argument_list|(
argument|const QString&path
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|,
argument|QRegExp::PatternSyntax syntax = QRegExp::FixedString
argument_list|)
expr_stmt|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|fromDevice
argument_list|(
argument|QIODevice *device
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|)
expr_stmt|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|fromData
argument_list|(
argument|const QByteArray&data
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|)
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
name|QT_VERSION_CHECK
argument_list|(
literal|6
operator|,
literal|0
operator|,
literal|0
argument_list|)
specifier|static
name|QList
operator|<
name|QSslError
operator|>
name|verify
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCertificate
operator|>
operator|&
name|certificateChain
argument_list|,
specifier|const
name|QString
operator|&
name|hostName
operator|=
name|QString
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
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
operator|=
name|QString
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
specifier|static
name|bool
name|importPkcs12
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
operator|=
name|Q_NULLPTR
argument_list|,
specifier|const
name|QByteArray
operator|&
name|passPhrase
operator|=
name|QByteArray
argument_list|()
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QExplicitlySharedDataPointer
operator|<
name|QSslCertificatePrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QSslCertificatePrivate
decl_stmt|;
name|friend
name|class
name|QSslSocketBackendPrivate
decl_stmt|;
name|friend
name|Q_NETWORK_EXPORT
name|uint
name|qHash
argument_list|(
specifier|const
name|QSslCertificate
operator|&
name|key
argument_list|,
name|uint
name|seed
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QSslCertificate
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_decl_stmt
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|operator
name|Q_NETWORK_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QSslCertificate
operator|&
name|certificate
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_NETWORK_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
name|QSslCertificate
operator|::
name|SubjectInfo
name|info
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QSslCertificate
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SSL
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
