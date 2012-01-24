begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFSFILEENGINE_H
end_ifndef
begin_define
DECL|macro|QFSFILEENGINE_H
define|#
directive|define
name|QFSFILEENGINE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstractfileengine.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_include
include|#
directive|include
file|<f32file.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FSFILEENGINE
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QFSFileEnginePrivate
name|class
name|QFSFileEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QFSFileEngine
range|:
name|public
name|QAbstractFileEngine
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFSFileEngine
argument_list|)
name|public
operator|:
name|QFSFileEngine
argument_list|()
block|;
name|explicit
name|QFSFileEngine
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
operator|~
name|QFSFileEngine
argument_list|()
block|;
name|bool
name|open
argument_list|(
argument|QIODevice::OpenMode openMode
argument_list|)
block|;
name|bool
name|open
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|,
argument|FILE *fh
argument_list|)
block|;
name|bool
name|close
argument_list|()
block|;
name|bool
name|flush
argument_list|()
block|;
name|qint64
name|size
argument_list|()
specifier|const
block|;
name|qint64
name|pos
argument_list|()
specifier|const
block|;
name|bool
name|seek
argument_list|(
name|qint64
argument_list|)
block|;
name|bool
name|isSequential
argument_list|()
specifier|const
block|;
name|bool
name|remove
argument_list|()
block|;
name|bool
name|copy
argument_list|(
specifier|const
name|QString
operator|&
name|newName
argument_list|)
block|;
name|bool
name|rename
argument_list|(
specifier|const
name|QString
operator|&
name|newName
argument_list|)
block|;
name|bool
name|link
argument_list|(
specifier|const
name|QString
operator|&
name|newName
argument_list|)
block|;
name|bool
name|mkdir
argument_list|(
argument|const QString&dirName
argument_list|,
argument|bool createParentDirectories
argument_list|)
specifier|const
block|;
name|bool
name|rmdir
argument_list|(
argument|const QString&dirName
argument_list|,
argument|bool recurseParentDirectories
argument_list|)
specifier|const
block|;
name|bool
name|setSize
argument_list|(
argument|qint64 size
argument_list|)
block|;
name|bool
name|caseSensitive
argument_list|()
specifier|const
block|;
name|bool
name|isRelativePath
argument_list|()
specifier|const
block|;
name|QStringList
name|entryList
argument_list|(
argument|QDir::Filters filters
argument_list|,
argument|const QStringList&filterNames
argument_list|)
specifier|const
block|;
name|FileFlags
name|fileFlags
argument_list|(
argument|FileFlags type
argument_list|)
specifier|const
block|;
name|bool
name|setPermissions
argument_list|(
argument|uint perms
argument_list|)
block|;
name|QString
name|fileName
argument_list|(
argument|FileName file
argument_list|)
specifier|const
block|;
name|uint
name|ownerId
argument_list|(
argument|FileOwner
argument_list|)
specifier|const
block|;
name|QString
name|owner
argument_list|(
argument|FileOwner
argument_list|)
specifier|const
block|;
name|QDateTime
name|fileTime
argument_list|(
argument|FileTime time
argument_list|)
specifier|const
block|;
name|void
name|setFileName
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|int
name|handle
argument_list|()
specifier|const
block|;
name|Iterator
operator|*
name|beginEntryList
argument_list|(
argument|QDir::Filters filters
argument_list|,
argument|const QStringList&filterNames
argument_list|)
block|;
name|Iterator
operator|*
name|endEntryList
argument_list|()
block|;
name|qint64
name|read
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|readLine
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|write
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
block|;
name|bool
name|extension
argument_list|(
argument|Extension extension
argument_list|,
argument|const ExtensionOption *option =
literal|0
argument_list|,
argument|ExtensionReturn *output =
literal|0
argument_list|)
block|;
name|bool
name|supportsExtension
argument_list|(
argument|Extension extension
argument_list|)
specifier|const
block|;
comment|//FS only!!
name|bool
name|open
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|,
argument|int fd
argument_list|)
block|;
name|bool
name|open
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|,
argument|int fd
argument_list|,
argument|QFile::FileHandleFlags handleFlags
argument_list|)
block|;
name|bool
name|open
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|,
argument|FILE *fh
argument_list|,
argument|QFile::FileHandleFlags handleFlags
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|bool
name|open
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|,
argument|const RFile&f
argument_list|,
argument|QFile::FileHandleFlags handleFlags
argument_list|)
block|;
endif|#
directive|endif
specifier|static
name|bool
name|setCurrentPath
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
specifier|static
name|QString
name|currentPath
argument_list|(
specifier|const
name|QString
operator|&
name|path
operator|=
name|QString
argument_list|()
argument_list|)
block|;
specifier|static
name|QString
name|homePath
argument_list|()
block|;
specifier|static
name|QString
name|rootPath
argument_list|()
block|;
specifier|static
name|QString
name|tempPath
argument_list|()
block|;
specifier|static
name|QFileInfoList
name|drives
argument_list|()
block|;
name|protected
operator|:
name|QFSFileEngine
argument_list|(
name|QFSFileEnginePrivate
operator|&
name|dd
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FSFILEENGINE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFSFILEENGINE_H
end_comment
end_unit
