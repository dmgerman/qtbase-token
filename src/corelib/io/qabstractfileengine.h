begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTFILEENGINE_H
end_ifndef
begin_define
DECL|macro|QABSTRACTFILEENGINE_H
define|#
directive|define
name|QABSTRACTFILEENGINE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qdir.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|open
end_ifdef
begin_error
error|#
directive|error
error|qabstractfileengine.h must be included before any header file that defines open
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|QFileExtension
decl_stmt|;
DECL|variable|QFileExtensionResult
name|class
name|QFileExtensionResult
decl_stmt|;
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
DECL|variable|QAbstractFileEngineIterator
name|class
name|QAbstractFileEngineIterator
decl_stmt|;
DECL|variable|QAbstractFileEnginePrivate
name|class
name|QAbstractFileEnginePrivate
decl_stmt|;
name|class
name|Q_CORE_EXPORT
name|QAbstractFileEngine
decl_stmt|{ public:     enum FileFlag
block|{
comment|//perms (overlaps the QFile::Permission)
name|ReadOwnerPerm
operator|=
literal|0x4000
operator|,
name|WriteOwnerPerm
operator|=
literal|0x2000
operator|,
name|ExeOwnerPerm
operator|=
literal|0x1000
operator|,
name|ReadUserPerm
operator|=
literal|0x0400
operator|,
name|WriteUserPerm
operator|=
literal|0x0200
operator|,
name|ExeUserPerm
operator|=
literal|0x0100
operator|,
name|ReadGroupPerm
operator|=
literal|0x0040
operator|,
name|WriteGroupPerm
operator|=
literal|0x0020
operator|,
name|ExeGroupPerm
operator|=
literal|0x0010
operator|,
name|ReadOtherPerm
operator|=
literal|0x0004
operator|,
name|WriteOtherPerm
operator|=
literal|0x0002
operator|,
name|ExeOtherPerm
operator|=
literal|0x0001
operator|,
comment|//types
name|LinkType
operator|=
literal|0x10000
operator|,
name|FileType
operator|=
literal|0x20000
operator|,
name|DirectoryType
operator|=
literal|0x40000
operator|,
name|BundleType
operator|=
literal|0x80000
operator|,
comment|//flags
name|HiddenFlag
operator|=
literal|0x0100000
operator|,
name|LocalDiskFlag
operator|=
literal|0x0200000
operator|,
name|ExistsFlag
operator|=
literal|0x0400000
operator|,
name|RootFlag
operator|=
literal|0x0800000
operator|,
name|Refresh
operator|=
literal|0x1000000
operator|,
comment|//masks
name|PermsMask
operator|=
literal|0x0000FFFF
operator|,
name|TypesMask
operator|=
literal|0x000F0000
operator|,
name|FlagsMask
operator|=
literal|0x0FF00000
operator|,
name|FileInfoAll
operator|=
name|FlagsMask
operator||
name|PermsMask
operator||
name|TypesMask
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_FLAGS
argument_list|(
name|FileFlags
argument_list|,
name|FileFlag
argument_list|)
expr|enum
name|FileName
block|{
name|DefaultName
block|,
name|BaseName
block|,
name|PathName
block|,
name|AbsoluteName
block|,
name|AbsolutePathName
block|,
name|LinkName
block|,
name|CanonicalName
block|,
name|CanonicalPathName
block|,
name|BundleName
block|,
name|NFileNames
operator|=
literal|9
block|}
expr_stmt|;
end_expr_stmt
begin_enum
enum|enum
name|FileOwner
block|{
name|OwnerUser
block|,
name|OwnerGroup
block|}
enum|;
end_enum
begin_enum
enum|enum
name|FileTime
block|{
name|CreationTime
block|,
name|ModificationTime
block|,
name|AccessTime
block|}
enum|;
end_enum
begin_expr_stmt
name|virtual
operator|~
name|QAbstractFileEngine
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|virtual
name|bool
name|open
argument_list|(
name|QIODevice
operator|::
name|OpenMode
name|openMode
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|virtual
name|bool
name|close
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|bool
name|flush
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
name|qint64
name|size
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|qint64
name|pos
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|virtual
name|bool
name|seek
parameter_list|(
name|qint64
name|pos
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
name|bool
name|isSequential
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|virtual
name|bool
name|remove
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|bool
name|copy
parameter_list|(
specifier|const
name|QString
modifier|&
name|newName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|bool
name|rename
parameter_list|(
specifier|const
name|QString
modifier|&
name|newName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|bool
name|link
parameter_list|(
specifier|const
name|QString
modifier|&
name|newName
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|bool
name|mkdir
argument_list|(
specifier|const
name|QString
operator|&
name|dirName
argument_list|,
name|bool
name|createParentDirectories
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|bool
name|rmdir
argument_list|(
specifier|const
name|QString
operator|&
name|dirName
argument_list|,
name|bool
name|recurseParentDirectories
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|virtual
name|bool
name|setSize
parameter_list|(
name|qint64
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
name|bool
name|caseSensitive
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|bool
name|isRelativePath
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|virtual
name|QStringList
name|entryList
argument_list|(
name|QDir
operator|::
name|Filters
name|filters
argument_list|,
specifier|const
name|QStringList
operator|&
name|filterNames
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|FileFlags
name|fileFlags
argument_list|(
name|FileFlags
name|type
operator|=
name|FileInfoAll
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|virtual
name|bool
name|setPermissions
parameter_list|(
name|uint
name|perms
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|QString
name|fileName
argument_list|(
name|FileName
name|file
operator|=
name|DefaultName
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|uint
name|ownerId
argument_list|(
name|FileOwner
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QString
name|owner
argument_list|(
name|FileOwner
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QDateTime
name|fileTime
argument_list|(
name|FileTime
name|time
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|virtual
name|void
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
name|int
name|handle
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|atEnd
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|uchar
modifier|*
name|map
argument_list|(
name|qint64
name|offset
argument_list|,
name|qint64
name|size
argument_list|,
name|QFile
operator|::
name|MemoryMapFlags
name|flags
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|bool
name|unmap
parameter_list|(
name|uchar
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl
begin_typedef
typedef|typedef
name|QAbstractFileEngineIterator
name|Iterator
typedef|;
end_typedef
begin_decl_stmt
name|virtual
name|Iterator
modifier|*
name|beginEntryList
argument_list|(
name|QDir
operator|::
name|Filters
name|filters
argument_list|,
specifier|const
name|QStringList
operator|&
name|filterNames
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|virtual
name|Iterator
modifier|*
name|endEntryList
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|qint64
name|read
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|qint64
name|readLine
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|qint64
name|write
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|len
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QFile
operator|::
name|FileError
name|error
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_enum
enum|enum
name|Extension
block|{
name|AtEndExtension
block|,
name|FastReadLineExtension
block|,
name|MapExtension
block|,
name|UnMapExtension
block|}
enum|;
end_enum
begin_decl_stmt
name|class
name|ExtensionOption
block|{}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|ExtensionReturn
block|{}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|MapExtensionOption
range|:
name|public
name|ExtensionOption
block|{
name|public
operator|:
name|qint64
name|offset
block|;
name|qint64
name|size
block|;
name|QFile
operator|::
name|MemoryMapFlags
name|flags
block|;     }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|MapExtensionReturn
range|:
name|public
name|ExtensionReturn
block|{
name|public
operator|:
name|uchar
operator|*
name|address
block|;     }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|UnMapExtensionOption
range|:
name|public
name|ExtensionOption
block|{
name|public
operator|:
name|uchar
operator|*
name|address
block|;     }
decl_stmt|;
end_decl_stmt
begin_function_decl
name|virtual
name|bool
name|extension
parameter_list|(
name|Extension
name|extension
parameter_list|,
specifier|const
name|ExtensionOption
modifier|*
name|option
init|=
literal|0
parameter_list|,
name|ExtensionReturn
modifier|*
name|output
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|bool
name|supportsExtension
argument_list|(
name|Extension
name|extension
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Factory
end_comment
begin_function_decl
specifier|static
name|QAbstractFileEngine
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_decl_stmt
name|void
name|setError
argument_list|(
name|QFile
operator|::
name|FileError
name|error
argument_list|,
specifier|const
name|QString
operator|&
name|str
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QAbstractFileEngine
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QAbstractFileEngine
argument_list|(
name|QAbstractFileEnginePrivate
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QScopedPointer
operator|<
name|QAbstractFileEnginePrivate
operator|>
name|d_ptr
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractFileEngine
argument_list|)
end_macro
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractFileEngine
argument_list|)
end_macro
begin_macro
unit|};
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QAbstractFileEngine::FileFlags
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAbstractFileEngineHandler
block|{
name|public
label|:
name|QAbstractFileEngineHandler
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QAbstractFileEngineHandler
argument_list|()
expr_stmt|;
name|virtual
name|QAbstractFileEngine
modifier|*
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QAbstractFileEngineIteratorPrivate
name|class
name|QAbstractFileEngineIteratorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAbstractFileEngineIterator
block|{
name|public
label|:
name|QAbstractFileEngineIterator
argument_list|(
argument|QDir::Filters filters
argument_list|,
argument|const QStringList&nameFilters
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|QAbstractFileEngineIterator
argument_list|()
expr_stmt|;
name|virtual
name|QString
name|next
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|hasNext
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|QString
name|path
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|nameFilters
argument_list|()
specifier|const
expr_stmt|;
name|QDir
operator|::
name|Filters
name|filters
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QString
name|currentFileName
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QFileInfo
name|currentFileInfo
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|currentFilePath
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
enum|enum
name|EntryInfoType
block|{     }
enum|;
name|virtual
name|QVariant
name|entryInfo
argument_list|(
name|EntryInfoType
name|type
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractFileEngineIterator
argument_list|)
name|friend
name|class
name|QDirIterator
decl_stmt|;
name|friend
name|class
name|QDirIteratorPrivate
decl_stmt|;
name|void
name|setPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
name|QScopedPointer
operator|<
name|QAbstractFileEngineIteratorPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QABSTRACTFILEENGINE_H
end_comment
end_unit
