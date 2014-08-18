begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsslcertificate.h"
end_include
begin_include
include|#
directive|include
file|"qsslcertificate_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|operator ==
name|bool
name|QSslCertificate
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QSslCertificate
modifier|&
name|other
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|==
name|other
operator|.
name|d
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|isNull
name|bool
name|QSslCertificate
operator|::
name|isNull
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|isSelfSigned
name|bool
name|QSslCertificate
operator|::
name|isSelfSigned
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|version
name|QByteArray
name|QSslCertificate
operator|::
name|version
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QByteArray
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|serialNumber
name|QByteArray
name|QSslCertificate
operator|::
name|serialNumber
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QByteArray
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|issuerInfo
name|QStringList
name|QSslCertificate
operator|::
name|issuerInfo
parameter_list|(
name|SubjectInfo
name|info
parameter_list|)
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|issuerInfo
name|QStringList
name|QSslCertificate
operator|::
name|issuerInfo
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|attribute
parameter_list|)
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|subjectInfo
name|QStringList
name|QSslCertificate
operator|::
name|subjectInfo
parameter_list|(
name|SubjectInfo
name|info
parameter_list|)
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|subjectInfo
name|QStringList
name|QSslCertificate
operator|::
name|subjectInfo
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|attribute
parameter_list|)
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|subjectInfoAttributes
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QSslCertificate
operator|::
name|subjectInfoAttributes
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QList
argument_list|<
name|QByteArray
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|issuerInfoAttributes
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QSslCertificate
operator|::
name|issuerInfoAttributes
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QList
argument_list|<
name|QByteArray
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|subjectAlternativeNames
name|QMultiMap
argument_list|<
name|QSsl
operator|::
name|AlternativeNameEntryType
argument_list|,
name|QString
argument_list|>
name|QSslCertificate
operator|::
name|subjectAlternativeNames
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QMultiMap
argument_list|<
name|QSsl
operator|::
name|AlternativeNameEntryType
argument_list|,
name|QString
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|effectiveDate
name|QDateTime
name|QSslCertificate
operator|::
name|effectiveDate
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QDateTime
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|expiryDate
name|QDateTime
name|QSslCertificate
operator|::
name|expiryDate
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QDateTime
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|handle
name|Qt
operator|::
name|HANDLE
name|QSslCertificate
operator|::
name|handle
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|publicKey
name|QSslKey
name|QSslCertificate
operator|::
name|publicKey
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QSslKey
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|extensions
name|QList
argument_list|<
name|QSslCertificateExtension
argument_list|>
name|QSslCertificate
operator|::
name|extensions
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QList
argument_list|<
name|QSslCertificateExtension
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toPem
name|QByteArray
name|QSslCertificate
operator|::
name|toPem
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QByteArray
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toDer
name|QByteArray
name|QSslCertificate
operator|::
name|toDer
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QByteArray
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toText
name|QString
name|QSslCertificate
operator|::
name|toText
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|QSslCertificatePrivate
operator|::
name|init
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
name|QSsl
operator|::
name|EncodingFormat
name|format
parameter_list|)
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|certificatesFromPem
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
name|QSslCertificatePrivate
operator|::
name|certificatesFromPem
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|pem
parameter_list|,
name|int
name|count
parameter_list|)
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
name|Q_UNUSED
argument_list|(
argument|pem
argument_list|)
name|Q_UNUSED
argument_list|(
argument|count
argument_list|)
return|return
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|certificatesFromDer
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
name|QSslCertificatePrivate
operator|::
name|certificatesFromDer
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|der
parameter_list|,
name|int
name|count
parameter_list|)
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
name|Q_UNUSED
argument_list|(
argument|der
argument_list|)
name|Q_UNUSED
argument_list|(
argument|count
argument_list|)
return|return
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
