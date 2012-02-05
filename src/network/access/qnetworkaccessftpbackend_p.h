begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKACCESSFTPBACKEND_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKACCESSFTPBACKEND_P_H
define|#
directive|define
name|QNETWORKACCESSFTPBACKEND_P_H
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
file|"qnetworkaccessbackend_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkaccesscache_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkrequest.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkreply.h"
end_include
begin_include
include|#
directive|include
file|"private/qftp_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FTP
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QNetworkAccessFtpIODevice
name|class
name|QNetworkAccessFtpIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkAccessCachedFtpConnection
name|class
name|QNetworkAccessCachedFtpConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkAccessFtpBackend
range|:
name|public
name|QNetworkAccessBackend
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|State
block|{
name|Idle
block|,
comment|//Connecting,
name|LoggingIn
block|,
name|CheckingFeatures
block|,
name|Statting
block|,
name|Transferring
block|,
name|Disconnecting
block|}
block|;
name|QNetworkAccessFtpBackend
argument_list|()
block|;
name|virtual
operator|~
name|QNetworkAccessFtpBackend
argument_list|()
block|;
name|virtual
name|void
name|open
argument_list|()
block|;
name|virtual
name|void
name|closeDownstreamChannel
argument_list|()
block|;
name|virtual
name|void
name|downstreamReadyWrite
argument_list|()
block|;
name|void
name|disconnectFromFtp
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|ftpConnectionReady
argument_list|(
name|QNetworkAccessCache
operator|::
name|CacheableObject
operator|*
name|object
argument_list|)
block|;
name|void
name|ftpDone
argument_list|()
block|;
name|void
name|ftpReadyRead
argument_list|()
block|;
name|void
name|ftpRawCommandReply
argument_list|(
argument|int code
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QNetworkAccessFtpIODevice
block|;
name|QPointer
operator|<
name|QNetworkAccessCachedFtpConnection
operator|>
name|ftp
block|;
name|QIODevice
operator|*
name|uploadDevice
block|;
name|qint64
name|totalBytes
block|;
name|int
name|helpId
block|,
name|sizeId
block|,
name|mdtmId
block|;
name|bool
name|supportsSize
block|,
name|supportsMdtm
block|;
name|State
name|state
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkAccessFtpBackendFactory
range|:
name|public
name|QNetworkAccessBackendFactory
block|{
name|public
operator|:
name|virtual
name|QNetworkAccessBackend
operator|*
name|create
argument_list|(
argument|QNetworkAccessManager::Operation op
argument_list|,
argument|const QNetworkRequest&request
argument_list|)
specifier|const
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
begin_comment
comment|// QT_NO_FTP
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
