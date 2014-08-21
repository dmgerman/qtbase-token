begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILEINFO_P_H
end_ifndef
begin_define
DECL|macro|QFILEINFO_P_H
define|#
directive|define
name|QFILEINFO_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|"qfileinfo.h"
end_include
begin_include
include|#
directive|include
file|"qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"qatomic.h"
end_include
begin_include
include|#
directive|include
file|"qshareddata.h"
end_include
begin_include
include|#
directive|include
file|"qfilesystemengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qvector.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qabstractfileengine_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qfilesystementry_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qfilesystemmetadata_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QFileInfoPrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
expr|enum
block|{
name|CachedFileFlags
operator|=
literal|0x01
block|,
name|CachedLinkTypeFlag
operator|=
literal|0x02
block|,
name|CachedBundleTypeFlag
operator|=
literal|0x04
block|,
name|CachedMTime
operator|=
literal|0x10
block|,
name|CachedCTime
operator|=
literal|0x20
block|,
name|CachedATime
operator|=
literal|0x40
block|,
name|CachedSize
operator|=
literal|0x08
block|,
name|CachedPerms
operator|=
literal|0x80
block|}
block|;
specifier|inline
name|QFileInfoPrivate
argument_list|()
operator|:
name|QSharedData
argument_list|()
block|,
name|fileEngine
argument_list|(
literal|0
argument_list|)
block|,
name|cachedFlags
argument_list|(
literal|0
argument_list|)
block|,
name|isDefaultConstructed
argument_list|(
name|true
argument_list|)
block|,
name|cache_enabled
argument_list|(
name|true
argument_list|)
block|,
name|fileFlags
argument_list|(
literal|0
argument_list|)
block|,
name|fileSize
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|QFileInfoPrivate
argument_list|(
specifier|const
name|QFileInfoPrivate
operator|&
name|copy
argument_list|)
operator|:
name|QSharedData
argument_list|(
name|copy
argument_list|)
block|,
name|fileEntry
argument_list|(
name|copy
operator|.
name|fileEntry
argument_list|)
block|,
name|metaData
argument_list|(
name|copy
operator|.
name|metaData
argument_list|)
block|,
name|fileEngine
argument_list|(
name|QFileSystemEngine
operator|::
name|resolveEntryAndCreateLegacyEngine
argument_list|(
name|fileEntry
argument_list|,
name|metaData
argument_list|)
argument_list|)
block|,
name|cachedFlags
argument_list|(
literal|0
argument_list|)
block|,
ifndef|#
directive|ifndef
name|QT_NO_FSFILEENGINE
name|isDefaultConstructed
argument_list|(
name|false
argument_list|)
block|,
else|#
directive|else
name|isDefaultConstructed
argument_list|(
operator|!
name|fileEngine
argument_list|)
block|,
endif|#
directive|endif
name|cache_enabled
argument_list|(
name|copy
operator|.
name|cache_enabled
argument_list|)
block|,
name|fileFlags
argument_list|(
literal|0
argument_list|)
block|,
name|fileSize
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|QFileInfoPrivate
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
operator|:
name|fileEntry
argument_list|(
name|QDir
operator|::
name|fromNativeSeparators
argument_list|(
name|file
argument_list|)
argument_list|)
block|,
name|fileEngine
argument_list|(
name|QFileSystemEngine
operator|::
name|resolveEntryAndCreateLegacyEngine
argument_list|(
name|fileEntry
argument_list|,
name|metaData
argument_list|)
argument_list|)
block|,
name|cachedFlags
argument_list|(
literal|0
argument_list|)
block|,
ifndef|#
directive|ifndef
name|QT_NO_FSFILEENGINE
name|isDefaultConstructed
argument_list|(
name|false
argument_list|)
block|,
else|#
directive|else
name|isDefaultConstructed
argument_list|(
operator|!
name|fileEngine
argument_list|)
block|,
endif|#
directive|endif
name|cache_enabled
argument_list|(
name|true
argument_list|)
block|,
name|fileFlags
argument_list|(
literal|0
argument_list|)
block|,
name|fileSize
argument_list|(
literal|0
argument_list|)
block|{     }
specifier|inline
name|QFileInfoPrivate
argument_list|(
specifier|const
name|QFileSystemEntry
operator|&
name|file
argument_list|,
specifier|const
name|QFileSystemMetaData
operator|&
name|data
argument_list|)
operator|:
name|QSharedData
argument_list|()
block|,
name|fileEntry
argument_list|(
name|file
argument_list|)
block|,
name|metaData
argument_list|(
name|data
argument_list|)
block|,
name|fileEngine
argument_list|(
name|QFileSystemEngine
operator|::
name|resolveEntryAndCreateLegacyEngine
argument_list|(
name|fileEntry
argument_list|,
name|metaData
argument_list|)
argument_list|)
block|,
name|cachedFlags
argument_list|(
literal|0
argument_list|)
block|,
name|isDefaultConstructed
argument_list|(
name|false
argument_list|)
block|,
name|cache_enabled
argument_list|(
name|true
argument_list|)
block|,
name|fileFlags
argument_list|(
literal|0
argument_list|)
block|,
name|fileSize
argument_list|(
literal|0
argument_list|)
block|{
comment|//If the file engine is not null, this maybe a "mount point" for a custom file engine
comment|//in which case we can't trust the metadata
if|if
condition|(
name|fileEngine
condition|)
name|metaData
operator|=
name|QFileSystemMetaData
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|QFileInfoPrivate
argument_list|(
specifier|const
name|QFileSystemEntry
operator|&
name|file
argument_list|,
specifier|const
name|QFileSystemMetaData
operator|&
name|data
argument_list|,
name|QAbstractFileEngine
operator|*
name|engine
argument_list|)
operator|:
name|fileEntry
argument_list|(
name|file
argument_list|)
block|,
name|metaData
argument_list|(
name|data
argument_list|)
block|,
name|fileEngine
argument_list|(
name|engine
argument_list|)
block|,
name|cachedFlags
argument_list|(
literal|0
argument_list|)
block|,
ifndef|#
directive|ifndef
name|QT_NO_FSFILEENGINE
name|isDefaultConstructed
argument_list|(
name|false
argument_list|)
block|,
else|#
directive|else
name|isDefaultConstructed
argument_list|(
operator|!
name|fileEngine
argument_list|)
block|,
endif|#
directive|endif
name|cache_enabled
argument_list|(
name|true
argument_list|)
block|,
name|fileFlags
argument_list|(
literal|0
argument_list|)
block|,
name|fileSize
argument_list|(
literal|0
argument_list|)
block|{     }
specifier|inline
name|void
name|clearFlags
argument_list|()
specifier|const
block|{
name|fileFlags
operator|=
literal|0
block|;
name|cachedFlags
operator|=
literal|0
block|;
if|if
condition|(
name|fileEngine
condition|)
operator|(
name|void
operator|)
name|fileEngine
operator|->
name|fileFlags
argument_list|(
name|QAbstractFileEngine
operator|::
name|Refresh
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|clear
argument_list|()
block|{
name|metaData
operator|.
name|clear
argument_list|()
block|;
name|clearFlags
argument_list|()
block|;
for|for
control|(
name|int
name|i
init|=
name|QAbstractFileEngine
operator|::
name|NFileNames
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
name|fileNames
index|[
name|i
index|]
operator|.
name|clear
argument_list|()
expr_stmt|;
name|fileOwners
index|[
literal|1
index|]
operator|.
name|clear
argument_list|()
block|;
name|fileOwners
index|[
literal|0
index|]
operator|.
name|clear
argument_list|()
block|;     }
name|uint
name|getFileFlags
argument_list|(
argument|QAbstractFileEngine::FileFlags
argument_list|)
specifier|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QDateTime
modifier|&
name|getFileTime
argument_list|(
name|QAbstractFileEngine
operator|::
name|FileTime
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|getFileName
argument_list|(
name|QAbstractFileEngine
operator|::
name|FileName
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|getFileOwner
argument_list|(
name|QAbstractFileEngine
operator|::
name|FileOwner
name|own
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QFileSystemEntry
name|fileEntry
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QFileSystemMetaData
name|metaData
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QScopedPointer
operator|<
name|QAbstractFileEngine
operator|>
specifier|const
name|fileEngine
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|mutable
name|QString
name|fileNames
index|[
name|QAbstractFileEngine
operator|::
name|NFileNames
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QString
name|fileOwners
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|uint
name|cachedFlags
range|:
literal|30
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
specifier|const
name|isDefaultConstructed
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_comment
comment|// QFileInfo is a default constructed instance
end_comment
begin_decl_stmt
name|bool
name|cache_enabled
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|uint
name|fileFlags
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|qint64
name|fileSize
decl_stmt|;
end_decl_stmt
begin_comment
comment|// ### Qt6: FIXME: This vector is essentially a plain array
end_comment
begin_comment
comment|// mutable QDateTime fileTimes[3], but the array is slower
end_comment
begin_comment
comment|// to initialize than the QVector as QDateTime has a pimpl.
end_comment
begin_comment
comment|// In Qt 6, QDateTime should inline its data members,
end_comment
begin_comment
comment|// and this here can be an array again.
end_comment
begin_expr_stmt
name|mutable
name|QVector
operator|<
name|QDateTime
operator|>
name|fileTimes
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|inline
name|bool
name|getCachedFlag
argument_list|(
name|uint
name|c
argument_list|)
decl|const
block|{
return|return
name|cache_enabled
condition|?
operator|(
name|cachedFlags
operator|&
name|c
operator|)
else|:
literal|0
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|void
name|setCachedFlag
argument_list|(
name|uint
name|c
argument_list|)
decl|const
block|{
if|if
condition|(
name|cache_enabled
condition|)
name|cachedFlags
operator||=
name|c
expr_stmt|;
block|}
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILEINFO_P_H
end_comment
end_unit
