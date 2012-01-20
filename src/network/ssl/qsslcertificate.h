begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Network
parameter_list|)
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|class
name|QDateTime
decl_stmt|;
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
DECL|variable|QSslError
name|class
name|QSslError
decl_stmt|;
DECL|variable|QSslKey
name|class
name|QSslKey
decl_stmt|;
DECL|variable|QSslCertificateExtension
name|class
name|QSslCertificateExtension
decl_stmt|;
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
DECL|variable|QSslCertificatePrivate
name|class
name|QSslCertificatePrivate
decl_stmt|;
name|class
name|Q_NETWORK_EXPORT
name|QSslCertificate
decl_stmt|{ public:     enum SubjectInfo
block|{
name|Organization
operator|,
name|CommonName
operator|,
name|LocalityName
operator|,
name|OrganizationalUnitName
operator|,
name|CountryName
operator|,
name|StateOrProvinceName
operator|,
name|DistinguishedNameQualifier
operator|,
name|SerialNumber
operator|,
name|EmailAddress
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QSslCertificate
argument_list|(
argument|QIODevice *device
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QSslCertificate
argument_list|(
comment|// ### s/encoded/data (to be consistent with signature in .cpp file) ?
argument|const QByteArray&encoded = QByteArray()
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QSslCertificate
argument_list|(
specifier|const
name|QSslCertificate
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QSslCertificate
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
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
end_decl_stmt
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
end_if
begin_expr_stmt
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
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|bool
name|isBlacklisted
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|clear
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// Certificate info
end_comment
begin_expr_stmt
name|QByteArray
name|version
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QByteArray
name|serialNumber
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
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
end_decl_stmt
begin_decl_stmt
name|QStringList
name|issuerInfo
argument_list|(
name|SubjectInfo
name|info
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
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
end_decl_stmt
begin_decl_stmt
name|QStringList
name|subjectInfo
argument_list|(
name|SubjectInfo
name|info
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
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
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|QByteArray
operator|>
name|subjectInfoAttributes
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|QByteArray
operator|>
name|issuerInfoAttributes
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
end_if
begin_expr_stmt
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
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
name|QDateTime
name|effectiveDate
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDateTime
name|expiryDate
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QSslKey
name|publicKey
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|QSslCertificateExtension
operator|>
name|extensions
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QByteArray
name|toPem
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QByteArray
name|toDer
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QByteArray
name|toText
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|QExplicitlySharedDataPointer
operator|<
name|QSslCertificatePrivate
operator|>
name|d
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|friend
name|class
name|QSslCertificatePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QSslSocketBackendPrivate
decl_stmt|;
end_decl_stmt
begin_ifndef
unit|};
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_decl_stmt
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_expr_stmt
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SSL
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
