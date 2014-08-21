begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMIMEDATABASE_H
end_ifndef
begin_define
DECL|macro|QMIMEDATABASE_H
define|#
directive|define
name|QMIMEDATABASE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qmimetype.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QByteArray
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFileInfo
name|class
name|QFileInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMimeDatabasePrivate
name|class
name|QMimeDatabasePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QMimeDatabase
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QMimeDatabase
argument_list|)
name|public
label|:
name|QMimeDatabase
argument_list|()
expr_stmt|;
operator|~
name|QMimeDatabase
argument_list|()
expr_stmt|;
name|QMimeType
name|mimeTypeForName
argument_list|(
specifier|const
name|QString
operator|&
name|nameOrAlias
argument_list|)
decl|const
decl_stmt|;
enum|enum
name|MatchMode
block|{
name|MatchDefault
init|=
literal|0x0
block|,
name|MatchExtension
init|=
literal|0x1
block|,
name|MatchContent
init|=
literal|0x2
block|}
enum|;
name|QMimeType
name|mimeTypeForFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
name|MatchMode
name|mode
operator|=
name|MatchDefault
argument_list|)
decl|const
decl_stmt|;
name|QMimeType
name|mimeTypeForFile
argument_list|(
specifier|const
name|QFileInfo
operator|&
name|fileInfo
argument_list|,
name|MatchMode
name|mode
operator|=
name|MatchDefault
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|QMimeType
operator|>
name|mimeTypesForFileName
argument_list|(
argument|const QString&fileName
argument_list|)
specifier|const
expr_stmt|;
name|QMimeType
name|mimeTypeForData
argument_list|(
specifier|const
name|QByteArray
operator|&
name|data
argument_list|)
decl|const
decl_stmt|;
name|QMimeType
name|mimeTypeForData
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|)
decl|const
decl_stmt|;
name|QMimeType
name|mimeTypeForUrl
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
decl|const
decl_stmt|;
name|QMimeType
name|mimeTypeForFileNameAndData
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
name|QIODevice
operator|*
name|device
argument_list|)
decl|const
decl_stmt|;
name|QMimeType
name|mimeTypeForFileNameAndData
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|QByteArray
operator|&
name|data
argument_list|)
decl|const
decl_stmt|;
name|QString
name|suffixForFileName
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|QMimeType
operator|>
name|allMimeTypes
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QMimeDatabasePrivate
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMIMEDATABASE_H
end_comment
end_unit
