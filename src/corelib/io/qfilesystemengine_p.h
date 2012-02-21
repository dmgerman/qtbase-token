begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILESYSTEMENGINE_P_H_INCLUDED
end_ifndef
begin_define
DECL|macro|QFILESYSTEMENGINE_P_H_INCLUDED
define|#
directive|define
name|QFILESYSTEMENGINE_P_H_INCLUDED
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
file|"qfile.h"
end_include
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
begin_include
include|#
directive|include
file|<QtCore/private/qsystemerror_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QFileSystemEngine
block|{
name|public
label|:
specifier|static
name|bool
name|isCaseSensitive
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|Q_OS_WIN
return|return
name|true
return|;
else|#
directive|else
return|return
name|false
return|;
endif|#
directive|endif
block|}
specifier|static
name|QFileSystemEntry
name|getLinkTarget
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|link
parameter_list|,
name|QFileSystemMetaData
modifier|&
name|data
parameter_list|)
function_decl|;
specifier|static
name|QFileSystemEntry
name|canonicalName
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
name|QFileSystemMetaData
modifier|&
name|data
parameter_list|)
function_decl|;
specifier|static
name|QFileSystemEntry
name|absoluteName
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|)
function_decl|;
specifier|static
name|QString
name|resolveUserName
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
name|QFileSystemMetaData
modifier|&
name|data
parameter_list|)
function_decl|;
specifier|static
name|QString
name|resolveGroupName
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
name|QFileSystemMetaData
modifier|&
name|data
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
specifier|static
name|QString
name|resolveUserName
parameter_list|(
name|uint
name|userId
parameter_list|)
function_decl|;
specifier|static
name|QString
name|resolveGroupName
parameter_list|(
name|uint
name|groupId
parameter_list|)
function_decl|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_CORESERVICES
argument_list|)
specifier|static
name|QString
name|bundleName
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|)
function_decl|;
else|#
directive|else
specifier|static
name|QString
name|bundleName
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|entry
argument_list|)
return|return
name|QString
argument_list|()
return|;
block|}
endif|#
directive|endif
specifier|static
name|bool
name|fillMetaData
argument_list|(
specifier|const
name|QFileSystemEntry
operator|&
name|entry
argument_list|,
name|QFileSystemMetaData
operator|&
name|data
argument_list|,
name|QFileSystemMetaData
operator|::
name|MetaDataFlags
name|what
argument_list|)
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
specifier|static
name|bool
name|fillMetaData
parameter_list|(
name|int
name|fd
parameter_list|,
name|QFileSystemMetaData
modifier|&
name|data
parameter_list|)
function_decl|;
comment|// what = PosixStatFlags
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
specifier|static
name|bool
name|uncListSharesOnServer
parameter_list|(
specifier|const
name|QString
modifier|&
name|server
parameter_list|,
name|QStringList
modifier|*
name|list
parameter_list|)
function_decl|;
comment|//Used also by QFSFileEngineIterator::hasNext()
specifier|static
name|bool
name|fillMetaData
argument_list|(
name|int
name|fd
argument_list|,
name|QFileSystemMetaData
operator|&
name|data
argument_list|,
name|QFileSystemMetaData
operator|::
name|MetaDataFlags
name|what
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|fillMetaData
argument_list|(
name|HANDLE
name|fHandle
argument_list|,
name|QFileSystemMetaData
operator|&
name|data
argument_list|,
name|QFileSystemMetaData
operator|::
name|MetaDataFlags
name|what
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|fillPermissions
argument_list|(
specifier|const
name|QFileSystemEntry
operator|&
name|entry
argument_list|,
name|QFileSystemMetaData
operator|&
name|data
argument_list|,
name|QFileSystemMetaData
operator|::
name|MetaDataFlags
name|what
argument_list|)
decl_stmt|;
specifier|static
name|QString
name|owner
argument_list|(
specifier|const
name|QFileSystemEntry
operator|&
name|entry
argument_list|,
name|QAbstractFileEngine
operator|::
name|FileOwner
name|own
argument_list|)
decl_stmt|;
specifier|static
name|QString
name|nativeAbsoluteFilePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|//homePath, rootPath and tempPath shall return clean paths
specifier|static
name|QString
name|homePath
parameter_list|()
function_decl|;
specifier|static
name|QString
name|rootPath
parameter_list|()
function_decl|;
specifier|static
name|QString
name|tempPath
parameter_list|()
function_decl|;
specifier|static
name|bool
name|createDirectory
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
name|bool
name|createParents
parameter_list|)
function_decl|;
specifier|static
name|bool
name|removeDirectory
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
name|bool
name|removeEmptyParents
parameter_list|)
function_decl|;
specifier|static
name|bool
name|createLink
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|source
parameter_list|,
specifier|const
name|QFileSystemEntry
modifier|&
name|target
parameter_list|,
name|QSystemError
modifier|&
name|error
parameter_list|)
function_decl|;
specifier|static
name|bool
name|copyFile
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|source
parameter_list|,
specifier|const
name|QFileSystemEntry
modifier|&
name|target
parameter_list|,
name|QSystemError
modifier|&
name|error
parameter_list|)
function_decl|;
specifier|static
name|bool
name|renameFile
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|source
parameter_list|,
specifier|const
name|QFileSystemEntry
modifier|&
name|target
parameter_list|,
name|QSystemError
modifier|&
name|error
parameter_list|)
function_decl|;
specifier|static
name|bool
name|removeFile
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
name|QSystemError
modifier|&
name|error
parameter_list|)
function_decl|;
specifier|static
name|bool
name|setPermissions
argument_list|(
specifier|const
name|QFileSystemEntry
operator|&
name|entry
argument_list|,
name|QFile
operator|::
name|Permissions
name|permissions
argument_list|,
name|QSystemError
operator|&
name|error
argument_list|,
name|QFileSystemMetaData
operator|*
name|data
operator|=
literal|0
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|setCurrentPath
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|)
function_decl|;
specifier|static
name|QFileSystemEntry
name|currentPath
parameter_list|()
function_decl|;
specifier|static
name|QAbstractFileEngine
modifier|*
name|resolveEntryAndCreateLegacyEngine
parameter_list|(
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
name|QFileSystemMetaData
modifier|&
name|data
parameter_list|)
function_decl|;
name|private
label|:
specifier|static
name|QString
name|slowCanonicalized
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
specifier|static
name|void
name|clearWinStatData
parameter_list|(
name|QFileSystemMetaData
modifier|&
name|data
parameter_list|)
function_decl|;
endif|#
directive|endif
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
comment|// include guard
end_comment
end_unit
