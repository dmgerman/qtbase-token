begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|BASELINESERVER_H
end_ifndef
begin_define
DECL|macro|BASELINESERVER_H
define|#
directive|define
name|BASELINESERVER_H
end_define
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QTcpServer>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<QTcpSocket>
end_include
begin_include
include|#
directive|include
file|<QScopedPointer>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QDateTime>
end_include
begin_include
include|#
directive|include
file|<QSettings>
end_include
begin_include
include|#
directive|include
file|"baselineprotocol.h"
end_include
begin_include
include|#
directive|include
file|"report.h"
end_include
begin_comment
comment|// #seconds between update checks
end_comment
begin_define
DECL|macro|HEARTBEAT
define|#
directive|define
name|HEARTBEAT
value|10
end_define
begin_define
DECL|macro|MetadataFileExt
define|#
directive|define
name|MetadataFileExt
value|"metadata"
end_define
begin_decl_stmt
name|class
name|BaselineServer
range|:
name|public
name|QTcpServer
block|{
name|Q_OBJECT
name|public
operator|:
name|BaselineServer
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|QString
name|storagePath
argument_list|()
block|;
specifier|static
name|QString
name|baseUrl
argument_list|()
block|;
specifier|static
name|QString
name|settingsFilePath
argument_list|()
block|;
name|protected
operator|:
name|void
name|incomingConnection
argument_list|(
argument|int socketDescriptor
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|heartbeat
argument_list|()
block|;
name|private
operator|:
name|QTimer
operator|*
name|heartbeatTimer
block|;
name|QDateTime
name|meLastMod
block|;
name|QString
name|lastRunId
block|;
name|int
name|lastRunIdIdx
block|;
specifier|static
name|QString
name|storage
block|;
specifier|static
name|QString
name|url
block|;
specifier|static
name|QString
name|settingsFile
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|BaselineThread
range|:
name|public
name|QThread
block|{
name|Q_OBJECT
name|public
operator|:
name|BaselineThread
argument_list|(
argument|const QString&runId
argument_list|,
argument|int socketDescriptor
argument_list|,
argument|QObject *parent
argument_list|)
block|;
name|void
name|run
argument_list|()
block|;
name|private
operator|:
name|QString
name|runId
block|;
name|int
name|socketDescriptor
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|BaselineHandler
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|BaselineHandler
argument_list|(
argument|const QString&runId
argument_list|,
argument|int socketDescriptor = -
literal|1
argument_list|)
block|;
name|void
name|testPathMapping
argument_list|()
block|;
name|QString
name|pathForItem
argument_list|(
argument|const ImageItem&item
argument_list|,
argument|bool isBaseline = true
argument_list|,
argument|bool absolute = true
argument_list|)
specifier|const
block|;
comment|// CGI callbacks:
specifier|static
name|QString
name|view
argument_list|(
specifier|const
name|QString
operator|&
name|baseline
argument_list|,
specifier|const
name|QString
operator|&
name|rendered
argument_list|,
specifier|const
name|QString
operator|&
name|compared
argument_list|)
block|;
specifier|static
name|QString
name|clearAllBaselines
argument_list|(
specifier|const
name|QString
operator|&
name|context
argument_list|)
block|;
specifier|static
name|QString
name|updateBaselines
argument_list|(
specifier|const
name|QString
operator|&
name|context
argument_list|,
specifier|const
name|QString
operator|&
name|mismatchContext
argument_list|,
specifier|const
name|QString
operator|&
name|itemFile
argument_list|)
block|;
specifier|static
name|QString
name|blacklistTest
argument_list|(
argument|const QString&context
argument_list|,
argument|const QString&itemId
argument_list|,
argument|bool removeFromBlacklist = false
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|receiveRequest
argument_list|()
block|;
name|void
name|receiveDisconnect
argument_list|()
block|;
name|private
operator|:
name|bool
name|establishConnection
argument_list|()
block|;
name|void
name|provideBaselineChecksums
argument_list|(
specifier|const
name|QByteArray
operator|&
name|itemListBlock
argument_list|)
block|;
name|void
name|storeImage
argument_list|(
argument|const QByteArray&itemBlock
argument_list|,
argument|bool isBaseline
argument_list|)
block|;
name|void
name|storeItemMetadata
argument_list|(
specifier|const
name|PlatformInfo
operator|&
name|metadata
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|PlatformInfo
name|fetchItemMetadata
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|mapPlatformInfo
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|logtime
argument_list|()
block|;
name|QString
name|computeMismatchScore
argument_list|(
specifier|const
name|QImage
operator|&
name|baseline
argument_list|,
specifier|const
name|QImage
operator|&
name|rendered
argument_list|)
block|;
name|BaselineProtocol
name|proto
block|;
name|PlatformInfo
name|plat
block|;
name|mutable
name|PlatformInfo
name|mapped
block|;
name|QString
name|runId
block|;
name|bool
name|connectionEstablished
block|;
name|Report
name|report
block|;
name|QSettings
operator|*
name|settings
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// BASELINESERVER_H
end_comment
end_unit
