begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIR_P_H
end_ifndef
begin_define
DECL|macro|QDIR_P_H
define|#
directive|define
name|QDIR_P_H
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
file|"qfilesystementry_p.h"
end_include
begin_include
include|#
directive|include
file|"qfilesystemmetadata_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QDirPrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
name|explicit
name|QDirPrivate
argument_list|(
argument|const QString&path
argument_list|,
argument|const QStringList&nameFilters_ = QStringList()
argument_list|,
argument|QDir::SortFlags sort_ = QDir::SortFlags(QDir::Name | QDir::IgnoreCase)
argument_list|,
argument|QDir::Filters filters_ = QDir::AllEntries
argument_list|)
block|;
name|explicit
name|QDirPrivate
argument_list|(
specifier|const
name|QDirPrivate
operator|&
name|copy
argument_list|)
block|;
name|bool
name|exists
argument_list|()
specifier|const
block|;
name|void
name|initFileEngine
argument_list|()
block|;
name|void
name|initFileLists
argument_list|(
argument|const QDir&dir
argument_list|)
specifier|const
block|;
specifier|static
name|void
name|sortFileList
argument_list|(
name|QDir
operator|::
name|SortFlags
argument_list|,
name|QFileInfoList
operator|&
argument_list|,
name|QStringList
operator|*
argument_list|,
name|QFileInfoList
operator|*
argument_list|)
block|;
specifier|static
specifier|inline
name|QChar
name|getFilterSepChar
argument_list|(
specifier|const
name|QString
operator|&
name|nameFilter
argument_list|)
block|;
specifier|static
specifier|inline
name|QStringList
name|splitFilters
argument_list|(
argument|const QString&nameFilter
argument_list|,
argument|QChar sep =
literal|0
argument_list|)
block|;
name|void
name|setPath
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|clearFileLists
argument_list|()
block|;
name|void
name|resolveAbsoluteEntry
argument_list|()
specifier|const
block|;
name|mutable
name|bool
name|fileListsInitialized
block|;
name|mutable
name|QStringList
name|files
block|;
name|mutable
name|QFileInfoList
name|fileInfos
block|;
name|QStringList
name|nameFilters
block|;
name|QDir
operator|::
name|SortFlags
name|sort
block|;
name|QDir
operator|::
name|Filters
name|filters
block|;
name|QScopedPointer
operator|<
name|QAbstractFileEngine
operator|>
name|fileEngine
block|;
name|QFileSystemEntry
name|dirEntry
block|;
name|mutable
name|QFileSystemEntry
name|absoluteDirEntry
block|;
name|mutable
name|QFileSystemMetaData
name|metaData
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
end_unit
