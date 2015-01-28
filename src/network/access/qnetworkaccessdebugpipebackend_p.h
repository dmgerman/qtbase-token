begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKACCESSDEBUGPIPEBACKEND_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKACCESSDEBUGPIPEBACKEND_P_H
define|#
directive|define
name|QNETWORKACCESSDEBUGPIPEBACKEND_P_H
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
file|"qtcpsocket.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|QT_BUILD_INTERNAL
name|class
name|QNetworkAccessDebugPipeBackend
range|:
name|public
name|QNetworkAccessBackend
block|{
name|Q_OBJECT
name|public
operator|:
name|QNetworkAccessDebugPipeBackend
argument_list|()
block|;
name|virtual
operator|~
name|QNetworkAccessDebugPipeBackend
argument_list|()
block|;
name|virtual
name|void
name|open
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|closeDownstreamChannel
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|downstreamReadyWrite
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|void
name|pushFromSocketToDownstream
argument_list|()
block|;
name|void
name|pushFromUpstreamToSocket
argument_list|()
block|;
name|void
name|possiblyFinish
argument_list|()
block|;
name|QNonContiguousByteDevice
operator|*
name|uploadByteDevice
block|;
name|private
name|slots
operator|:
name|void
name|uploadReadyReadSlot
argument_list|()
block|;
name|void
name|socketReadyRead
argument_list|()
block|;
name|void
name|socketBytesWritten
argument_list|(
argument|qint64 bytes
argument_list|)
block|;
name|void
name|socketError
argument_list|()
block|;
name|void
name|socketDisconnected
argument_list|()
block|;
name|void
name|socketConnected
argument_list|()
block|;
name|private
operator|:
name|QTcpSocket
name|socket
block|;
name|bool
name|bareProtocol
block|;
name|bool
name|hasUploadFinished
block|;
name|bool
name|hasDownloadFinished
block|;
name|bool
name|hasEverythingFinished
block|;
name|qint64
name|bytesDownloaded
block|;
name|qint64
name|bytesUploaded
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNetworkAccessDebugPipeBackendFactory
range|:
name|public
name|QNetworkAccessBackendFactory
block|{
name|public
operator|:
name|virtual
name|QStringList
name|supportedSchemes
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
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
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_BUILD_INTERNAL
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
