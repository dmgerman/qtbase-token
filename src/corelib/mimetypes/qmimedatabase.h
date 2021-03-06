begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2015 Klaralvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author David Faure<david.faure@kdab.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MIMETYPE
end_ifndef
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
comment|// QT_NO_MIMETYPE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMIMEDATABASE_H
end_comment
end_unit
