begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLKEY_H
end_ifndef
begin_define
DECL|macro|QSSLKEY_H
define|#
directive|define
name|QSSLKEY_H
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
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qssl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Network
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
name|template
decl|<
name|typename
name|A
decl_stmt|,
name|typename
name|B
decl|> struct
name|QPair
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslKeyPrivate
name|class
name|QSslKeyPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QSslKey
block|{
name|public
label|:
name|QSslKey
argument_list|()
expr_stmt|;
name|QSslKey
argument_list|(
argument|const QByteArray&encoded
argument_list|,
argument|QSsl::KeyAlgorithm algorithm
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|,
argument|QSsl::KeyType type = QSsl::PrivateKey
argument_list|,
argument|const QByteArray&passPhrase = QByteArray()
argument_list|)
empty_stmt|;
name|QSslKey
argument_list|(
argument|QIODevice *device
argument_list|,
argument|QSsl::KeyAlgorithm algorithm
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|,
argument|QSsl::KeyType type = QSsl::PrivateKey
argument_list|,
argument|const QByteArray&passPhrase = QByteArray()
argument_list|)
empty_stmt|;
name|QSslKey
argument_list|(
specifier|const
name|QSslKey
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QSslKey
argument_list|()
expr_stmt|;
name|QSslKey
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QSslKey
operator|&
name|other
operator|)
decl_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|int
name|length
argument_list|()
specifier|const
expr_stmt|;
name|QSsl
operator|::
name|KeyType
name|type
argument_list|()
specifier|const
expr_stmt|;
name|QSsl
operator|::
name|KeyAlgorithm
name|algorithm
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|toPem
argument_list|(
specifier|const
name|QByteArray
operator|&
name|passPhrase
operator|=
name|QByteArray
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QByteArray
name|toDer
argument_list|(
specifier|const
name|QByteArray
operator|&
name|passPhrase
operator|=
name|QByteArray
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSslKey
operator|&
name|key
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSslKey
operator|&
name|key
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|key
operator|)
return|;
block|}
name|private
label|:
name|QExplicitlySharedDataPointer
operator|<
name|QSslKeyPrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QSslCertificate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
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
name|QSslKey
operator|&
name|key
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
comment|// QT_NO_OPENSSL
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
