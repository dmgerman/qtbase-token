begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \since 4.3     \class QDirIterator     \brief The QDirIterator class provides an iterator for directory entrylists.      You can use QDirIterator to navigate entries of a directory one at a time.     It is similar to QDir::entryList() and QDir::entryInfoList(), but because     it lists entries one at a time instead of all at once, it scales better     and is more suitable for large directories. It also supports listing     directory contents recursively, and following symbolic links. Unlike     QDir::entryList(), QDirIterator does not support sorting.      The QDirIterator constructor takes a QDir or a directory as     argument. After construction, the iterator is located before the first     directory entry. Here's how to iterate over all the entries sequentially:      \snippet doc/src/snippets/code/src_corelib_io_qdiriterator.cpp 0      The next() function returns the path to the next directory entry and     advances the iterator. You can also call filePath() to get the current     file path without advancing the iterator.  The fileName() function returns     only the name of the file, similar to how QDir::entryList() works. You can     also call fileInfo() to get a QFileInfo for the current entry.      Unlike Qt's container iterators, QDirIterator is uni-directional (i.e.,     you cannot iterate directories in reverse order) and does not allow random     access.      QDirIterator works with all supported file engines, and is implemented     using QAbstractFileEngineIterator.      \sa QDir, QDir::entryList(), QAbstractFileEngineIterator */
end_comment
begin_comment
comment|/*! \enum QDirIterator::IteratorFlag      This enum describes flags that you can combine to configure the behavior     of QDirIterator.      \value NoIteratorFlags The default value, representing no flags. The     iterator will return entries for the assigned path.      \value Subdirectories List entries inside all subdirectories as well.      \value FollowSymlinks When combined with Subdirectories, this flag     enables iterating through all subdirectories of the assigned path,     following all symbolic links. Symbolic link loops (e.g., "link" => "." or     "link" => "..") are automatically detected and ignored. */
end_comment
begin_include
include|#
directive|include
file|"qdiriterator.h"
end_include
begin_include
include|#
directive|include
file|"qdir_p.h"
end_include
begin_include
include|#
directive|include
file|"qabstractfileengine.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstack.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qfilesystemiterator_p.h>
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
begin_include
include|#
directive|include
file|<QtCore/private/qfilesystemengine_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfsfileengine.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qfileinfo_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
template|template
parameter_list|<
name|class
name|Iterator
parameter_list|>
class|class
DECL|class|QDirIteratorPrivateIteratorStack
name|QDirIteratorPrivateIteratorStack
super|:
specifier|public
name|QStack
argument_list|<
name|Iterator
modifier|*
argument_list|>
block|{
public|public:
DECL|function|~QDirIteratorPrivateIteratorStack
name|~
name|QDirIteratorPrivateIteratorStack
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|QDirIteratorPrivate
class|class
name|QDirIteratorPrivate
block|{
public|public:
name|QDirIteratorPrivate
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|nameFilters
parameter_list|,
name|QDir
operator|::
name|Filters
name|filters
parameter_list|,
name|QDirIterator
operator|::
name|IteratorFlags
name|flags
parameter_list|,
name|bool
name|resolveEngine
init|=
literal|true
parameter_list|)
constructor_decl|;
name|void
name|advance
parameter_list|()
function_decl|;
name|bool
name|entryMatches
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|)
function_decl|;
name|void
name|pushDirectory
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|)
function_decl|;
name|void
name|checkAndPushDirectory
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
parameter_list|)
function_decl|;
name|bool
name|matchesFilters
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QFileInfo
modifier|&
name|fi
parameter_list|)
specifier|const
function_decl|;
DECL|member|engine
name|QScopedPointer
argument_list|<
name|QAbstractFileEngine
argument_list|>
name|engine
decl_stmt|;
DECL|member|dirEntry
name|QFileSystemEntry
name|dirEntry
decl_stmt|;
DECL|member|nameFilters
specifier|const
name|QStringList
name|nameFilters
decl_stmt|;
DECL|member|filters
specifier|const
name|QDir
operator|::
name|Filters
name|filters
decl_stmt|;
DECL|member|iteratorFlags
specifier|const
name|QDirIterator
operator|::
name|IteratorFlags
name|iteratorFlags
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
DECL|member|nameRegExps
name|QVector
argument_list|<
name|QRegExp
argument_list|>
name|nameRegExps
decl_stmt|;
endif|#
directive|endif
DECL|member|fileEngineIterators
name|QDirIteratorPrivateIteratorStack
argument_list|<
name|QAbstractFileEngineIterator
argument_list|>
name|fileEngineIterators
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMITERATOR
DECL|member|nativeIterators
name|QDirIteratorPrivateIteratorStack
argument_list|<
name|QFileSystemIterator
argument_list|>
name|nativeIterators
decl_stmt|;
endif|#
directive|endif
DECL|member|currentFileInfo
name|QFileInfo
name|currentFileInfo
decl_stmt|;
DECL|member|nextFileInfo
name|QFileInfo
name|nextFileInfo
decl_stmt|;
comment|// Loop protection
DECL|member|visitedLinks
name|QSet
argument_list|<
name|QString
argument_list|>
name|visitedLinks
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QDirIteratorPrivate
name|QDirIteratorPrivate
operator|::
name|QDirIteratorPrivate
parameter_list|(
specifier|const
name|QFileSystemEntry
modifier|&
name|entry
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|nameFilters
parameter_list|,
name|QDir
operator|::
name|Filters
name|filters
parameter_list|,
name|QDirIterator
operator|::
name|IteratorFlags
name|flags
parameter_list|,
name|bool
name|resolveEngine
parameter_list|)
member_init_list|:
name|dirEntry
argument_list|(
name|entry
argument_list|)
member_init_list|,
name|nameFilters
argument_list|(
name|nameFilters
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"*"
argument_list|)
argument_list|)
condition|?
name|QStringList
argument_list|()
else|:
name|nameFilters
argument_list|)
member_init_list|,
name|filters
argument_list|(
name|QDir
operator|::
name|NoFilter
operator|==
name|filters
condition|?
name|QDir
operator|::
name|AllEntries
else|:
name|filters
argument_list|)
member_init_list|,
name|iteratorFlags
argument_list|(
name|flags
argument_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
name|nameRegExps
operator|.
name|reserve
argument_list|(
name|nameFilters
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|nameFilters
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|nameRegExps
operator|.
name|append
argument_list|(
name|QRegExp
argument_list|(
name|nameFilters
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
operator|(
name|filters
operator|&
name|QDir
operator|::
name|CaseSensitive
operator|)
condition|?
name|Qt
operator|::
name|CaseSensitive
else|:
name|Qt
operator|::
name|CaseInsensitive
argument_list|,
name|QRegExp
operator|::
name|Wildcard
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QFileSystemMetaData
name|metaData
decl_stmt|;
if|if
condition|(
name|resolveEngine
condition|)
name|engine
operator|.
name|reset
argument_list|(
name|QFileSystemEngine
operator|::
name|resolveEntryAndCreateLegacyEngine
argument_list|(
name|dirEntry
argument_list|,
name|metaData
argument_list|)
argument_list|)
expr_stmt|;
name|QFileInfo
name|fileInfo
argument_list|(
operator|new
name|QFileInfoPrivate
argument_list|(
name|dirEntry
argument_list|,
name|metaData
argument_list|)
argument_list|)
decl_stmt|;
comment|// Populate fields for hasNext() and next()
name|pushDirectory
argument_list|(
name|fileInfo
argument_list|)
expr_stmt|;
name|advance
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|pushDirectory
name|void
name|QDirIteratorPrivate
operator|::
name|pushDirectory
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|)
block|{
name|QString
name|path
init|=
name|fileInfo
operator|.
name|filePath
argument_list|()
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|fileInfo
operator|.
name|isSymLink
argument_list|()
condition|)
name|path
operator|=
name|fileInfo
operator|.
name|canonicalFilePath
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|iteratorFlags
operator|&
name|QDirIterator
operator|::
name|FollowSymlinks
condition|)
name|visitedLinks
operator|<<
name|fileInfo
operator|.
name|canonicalFilePath
argument_list|()
expr_stmt|;
if|if
condition|(
name|engine
condition|)
block|{
name|engine
operator|->
name|setFileName
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|QAbstractFileEngineIterator
modifier|*
name|it
init|=
name|engine
operator|->
name|beginEntryList
argument_list|(
name|filters
argument_list|,
name|nameFilters
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
condition|)
block|{
name|it
operator|->
name|setPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|fileEngineIterators
operator|<<
name|it
expr_stmt|;
block|}
else|else
block|{
comment|// No iterator; no entry list.
block|}
block|}
else|else
block|{
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMITERATOR
name|QFileSystemIterator
modifier|*
name|it
init|=
operator|new
name|QFileSystemIterator
argument_list|(
name|fileInfo
operator|.
name|d_ptr
operator|->
name|fileEntry
argument_list|,
name|filters
argument_list|,
name|nameFilters
argument_list|,
name|iteratorFlags
argument_list|)
decl_stmt|;
name|nativeIterators
operator|<<
name|it
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_function
DECL|function|entryMatches
specifier|inline
name|bool
name|QDirIteratorPrivate
operator|::
name|entryMatches
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|)
block|{
name|checkAndPushDirectory
argument_list|(
name|fileInfo
argument_list|)
expr_stmt|;
if|if
condition|(
name|matchesFilters
argument_list|(
name|fileName
argument_list|,
name|fileInfo
argument_list|)
condition|)
block|{
name|currentFileInfo
operator|=
name|nextFileInfo
expr_stmt|;
name|nextFileInfo
operator|=
name|fileInfo
expr_stmt|;
comment|//We found a matching entry.
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|advance
name|void
name|QDirIteratorPrivate
operator|::
name|advance
parameter_list|()
block|{
if|if
condition|(
name|engine
condition|)
block|{
while|while
condition|(
operator|!
name|fileEngineIterators
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// Find the next valid iterator that matches the filters.
name|QAbstractFileEngineIterator
modifier|*
name|it
decl_stmt|;
while|while
condition|(
name|it
operator|=
name|fileEngineIterators
operator|.
name|top
argument_list|()
operator|,
name|it
operator|->
name|hasNext
argument_list|()
condition|)
block|{
name|it
operator|->
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|entryMatches
argument_list|(
name|it
operator|->
name|currentFileName
argument_list|()
argument_list|,
name|it
operator|->
name|currentFileInfo
argument_list|()
argument_list|)
condition|)
return|return;
block|}
name|fileEngineIterators
operator|.
name|pop
argument_list|()
expr_stmt|;
operator|delete
name|it
expr_stmt|;
block|}
block|}
else|else
block|{
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMITERATOR
name|QFileSystemEntry
name|nextEntry
decl_stmt|;
name|QFileSystemMetaData
name|nextMetaData
decl_stmt|;
while|while
condition|(
operator|!
name|nativeIterators
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// Find the next valid iterator that matches the filters.
name|QFileSystemIterator
modifier|*
name|it
decl_stmt|;
while|while
condition|(
name|it
operator|=
name|nativeIterators
operator|.
name|top
argument_list|()
operator|,
name|it
operator|->
name|advance
argument_list|(
name|nextEntry
argument_list|,
name|nextMetaData
argument_list|)
condition|)
block|{
name|QFileInfo
name|info
argument_list|(
operator|new
name|QFileInfoPrivate
argument_list|(
name|nextEntry
argument_list|,
name|nextMetaData
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|entryMatches
argument_list|(
name|nextEntry
operator|.
name|fileName
argument_list|()
argument_list|,
name|info
argument_list|)
condition|)
return|return;
block|}
name|nativeIterators
operator|.
name|pop
argument_list|()
expr_stmt|;
operator|delete
name|it
expr_stmt|;
block|}
endif|#
directive|endif
block|}
name|currentFileInfo
operator|=
name|nextFileInfo
expr_stmt|;
name|nextFileInfo
operator|=
name|QFileInfo
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal  */
end_comment
begin_function
DECL|function|checkAndPushDirectory
name|void
name|QDirIteratorPrivate
operator|::
name|checkAndPushDirectory
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|)
block|{
comment|// If we're doing flat iteration, we're done.
if|if
condition|(
operator|!
operator|(
name|iteratorFlags
operator|&
name|QDirIterator
operator|::
name|Subdirectories
operator|)
condition|)
return|return;
comment|// Never follow non-directory entries
if|if
condition|(
operator|!
name|fileInfo
operator|.
name|isDir
argument_list|()
condition|)
return|return;
comment|// Follow symlinks only when asked
if|if
condition|(
operator|!
operator|(
name|iteratorFlags
operator|&
name|QDirIterator
operator|::
name|FollowSymlinks
operator|)
operator|&&
name|fileInfo
operator|.
name|isSymLink
argument_list|()
condition|)
return|return;
comment|// Never follow . and ..
name|QString
name|fileName
init|=
name|fileInfo
operator|.
name|fileName
argument_list|()
decl_stmt|;
if|if
condition|(
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
operator|==
name|fileName
operator|||
name|QLatin1String
argument_list|(
literal|".."
argument_list|)
operator|==
name|fileName
condition|)
return|return;
comment|// No hidden directories unless requested
if|if
condition|(
operator|!
operator|(
name|filters
operator|&
name|QDir
operator|::
name|AllDirs
operator|)
operator|&&
operator|!
operator|(
name|filters
operator|&
name|QDir
operator|::
name|Hidden
operator|)
operator|&&
name|fileInfo
operator|.
name|isHidden
argument_list|()
condition|)
return|return;
comment|// Stop link loops
if|if
condition|(
operator|!
name|visitedLinks
operator|.
name|isEmpty
argument_list|()
operator|&&
name|visitedLinks
operator|.
name|contains
argument_list|(
name|fileInfo
operator|.
name|canonicalFilePath
argument_list|()
argument_list|)
condition|)
return|return;
name|pushDirectory
argument_list|(
name|fileInfo
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal      This convenience function implements the iterator's filtering logics and     applies then to the current directory entry.      It returns true if the current entry matches the filters (i.e., the     current entry will be returned as part of the directory iteration);     otherwise, false is returned. */
end_comment
begin_function
DECL|function|matchesFilters
name|bool
name|QDirIteratorPrivate
operator|::
name|matchesFilters
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QFileInfo
modifier|&
name|fi
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
comment|// filter . and ..?
specifier|const
name|int
name|fileNameSize
init|=
name|fileName
operator|.
name|size
argument_list|()
decl_stmt|;
specifier|const
name|bool
name|dotOrDotDot
init|=
name|fileName
index|[
literal|0
index|]
operator|==
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
operator|&&
operator|(
operator|(
name|fileNameSize
operator|==
literal|1
operator|)
operator|||
operator|(
name|fileNameSize
operator|==
literal|2
operator|&&
name|fileName
index|[
literal|1
index|]
operator|==
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
operator|)
operator|)
decl_stmt|;
if|if
condition|(
operator|(
name|filters
operator|&
name|QDir
operator|::
name|NoDot
operator|)
operator|&&
name|dotOrDotDot
operator|&&
name|fileNameSize
operator|==
literal|1
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|filters
operator|&
name|QDir
operator|::
name|NoDotDot
operator|)
operator|&&
name|dotOrDotDot
operator|&&
name|fileNameSize
operator|==
literal|2
condition|)
return|return
literal|false
return|;
comment|// name filter
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
comment|// Pass all entries through name filters, except dirs if the AllDirs
if|if
condition|(
operator|!
name|nameFilters
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
operator|(
operator|(
name|filters
operator|&
name|QDir
operator|::
name|AllDirs
operator|)
operator|&&
name|fi
operator|.
name|isDir
argument_list|()
operator|)
condition|)
block|{
name|bool
name|matched
init|=
literal|false
decl_stmt|;
for|for
control|(
name|QVector
argument_list|<
name|QRegExp
argument_list|>
operator|::
name|const_iterator
name|iter
init|=
name|nameRegExps
operator|.
name|constBegin
argument_list|()
init|,
name|end
init|=
name|nameRegExps
operator|.
name|constEnd
argument_list|()
init|;
name|iter
operator|!=
name|end
condition|;
operator|++
name|iter
control|)
block|{
if|if
condition|(
name|iter
operator|->
name|exactMatch
argument_list|(
name|fileName
argument_list|)
condition|)
block|{
name|matched
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|matched
condition|)
return|return
literal|false
return|;
block|}
endif|#
directive|endif
comment|// skip symlinks
specifier|const
name|bool
name|skipSymlinks
init|=
operator|(
name|filters
operator|&
name|QDir
operator|::
name|NoSymLinks
operator|)
decl_stmt|;
specifier|const
name|bool
name|includeSystem
init|=
operator|(
name|filters
operator|&
name|QDir
operator|::
name|System
operator|)
decl_stmt|;
if|if
condition|(
name|skipSymlinks
operator|&&
name|fi
operator|.
name|isSymLink
argument_list|()
condition|)
block|{
comment|// The only reason to save this file is if it is a broken link and we are requesting system files.
if|if
condition|(
operator|!
name|includeSystem
operator|||
name|fi
operator|.
name|exists
argument_list|()
condition|)
return|return
literal|false
return|;
block|}
comment|// filter hidden
specifier|const
name|bool
name|includeHidden
init|=
operator|(
name|filters
operator|&
name|QDir
operator|::
name|Hidden
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|includeHidden
operator|&&
operator|!
name|dotOrDotDot
operator|&&
name|fi
operator|.
name|isHidden
argument_list|()
condition|)
return|return
literal|false
return|;
comment|// filter system files
if|if
condition|(
operator|!
name|includeSystem
operator|&&
operator|(
operator|!
operator|(
name|fi
operator|.
name|isFile
argument_list|()
operator|||
name|fi
operator|.
name|isDir
argument_list|()
operator|||
name|fi
operator|.
name|isSymLink
argument_list|()
operator|)
operator|||
operator|(
operator|!
name|fi
operator|.
name|exists
argument_list|()
operator|&&
name|fi
operator|.
name|isSymLink
argument_list|()
operator|)
operator|)
condition|)
return|return
literal|false
return|;
comment|// skip directories
specifier|const
name|bool
name|skipDirs
init|=
operator|!
operator|(
name|filters
operator|&
operator|(
name|QDir
operator|::
name|Dirs
operator||
name|QDir
operator|::
name|AllDirs
operator|)
operator|)
decl_stmt|;
if|if
condition|(
name|skipDirs
operator|&&
name|fi
operator|.
name|isDir
argument_list|()
condition|)
return|return
literal|false
return|;
comment|// skip files
specifier|const
name|bool
name|skipFiles
init|=
operator|!
operator|(
name|filters
operator|&
name|QDir
operator|::
name|Files
operator|)
decl_stmt|;
if|if
condition|(
name|skipFiles
operator|&&
name|fi
operator|.
name|isFile
argument_list|()
condition|)
comment|// Basically we need a reason not to exclude this file otherwise we just eliminate it.
return|return
literal|false
return|;
comment|// filter permissions
specifier|const
name|bool
name|filterPermissions
init|=
operator|(
operator|(
name|filters
operator|&
name|QDir
operator|::
name|PermissionMask
operator|)
operator|&&
operator|(
name|filters
operator|&
name|QDir
operator|::
name|PermissionMask
operator|)
operator|!=
name|QDir
operator|::
name|PermissionMask
operator|)
decl_stmt|;
specifier|const
name|bool
name|doWritable
init|=
operator|!
name|filterPermissions
operator|||
operator|(
name|filters
operator|&
name|QDir
operator|::
name|Writable
operator|)
decl_stmt|;
specifier|const
name|bool
name|doExecutable
init|=
operator|!
name|filterPermissions
operator|||
operator|(
name|filters
operator|&
name|QDir
operator|::
name|Executable
operator|)
decl_stmt|;
specifier|const
name|bool
name|doReadable
init|=
operator|!
name|filterPermissions
operator|||
operator|(
name|filters
operator|&
name|QDir
operator|::
name|Readable
operator|)
decl_stmt|;
if|if
condition|(
name|filterPermissions
operator|&&
operator|(
operator|(
name|doReadable
operator|&&
operator|!
name|fi
operator|.
name|isReadable
argument_list|()
operator|)
operator|||
operator|(
name|doWritable
operator|&&
operator|!
name|fi
operator|.
name|isWritable
argument_list|()
operator|)
operator|||
operator|(
name|doExecutable
operator|&&
operator|!
name|fi
operator|.
name|isExecutable
argument_list|()
operator|)
operator|)
condition|)
block|{
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     Constructs a QDirIterator that can iterate over \a dir's entrylist, using     \a dir's name filters and regular filters. You can pass options via \a     flags to decide how the directory should be iterated.      By default, \a flags is NoIteratorFlags, which provides the same behavior     as in QDir::entryList().      The sorting in \a dir is ignored.      \note To list symlinks that point to non existing files, QDir::System must be      passed to the flags.      \sa hasNext(), next(), IteratorFlags */
end_comment
begin_constructor
DECL|function|QDirIterator
name|QDirIterator
operator|::
name|QDirIterator
parameter_list|(
specifier|const
name|QDir
modifier|&
name|dir
parameter_list|,
name|IteratorFlags
name|flags
parameter_list|)
block|{
comment|// little trick to get hold of the QDirPrivate while there is no API on QDir to give it to us
class|class
name|MyQDir
super|:
specifier|public
name|QDir
block|{
public|public:
specifier|const
name|QDirPrivate
modifier|*
name|priv
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|.
name|constData
argument_list|()
return|;
block|}
block|}
class|;
specifier|const
name|QDirPrivate
modifier|*
name|other
init|=
cast|static_cast
argument_list|<
specifier|const
name|MyQDir
operator|*
argument_list|>
argument_list|(
operator|&
name|dir
argument_list|)
operator|->
name|priv
argument_list|()
decl_stmt|;
name|d
operator|.
name|reset
argument_list|(
operator|new
name|QDirIteratorPrivate
argument_list|(
name|other
operator|->
name|dirEntry
argument_list|,
name|other
operator|->
name|nameFilters
argument_list|,
name|other
operator|->
name|filters
argument_list|,
name|flags
argument_list|,
operator|!
name|other
operator|->
name|fileEngine
operator|.
name|isNull
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QDirIterator that can iterate over \a path, with no name     filtering and \a filters for entry filtering. You can pass options via \a     flags to decide how the directory should be iterated.      By default, \a filters is QDir::NoFilter, and \a flags is NoIteratorFlags,     which provides the same behavior as in QDir::entryList().      \note To list symlinks that point to non existing files, QDir::System must be      passed to the flags.      \sa hasNext(), next(), IteratorFlags */
end_comment
begin_constructor
DECL|function|QDirIterator
name|QDirIterator
operator|::
name|QDirIterator
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|QDir
operator|::
name|Filters
name|filters
parameter_list|,
name|IteratorFlags
name|flags
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QDirIteratorPrivate
argument_list|(
name|QFileSystemEntry
argument_list|(
name|path
argument_list|)
argument_list|,
name|QStringList
argument_list|()
argument_list|,
name|filters
argument_list|,
name|flags
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a QDirIterator that can iterate over \a path. You can pass     options via \a flags to decide how the directory should be iterated.      By default, \a flags is NoIteratorFlags, which provides the same behavior     as in QDir::entryList().      \note To list symlinks that point to non existing files, QDir::System must be      passed to the flags.      \sa hasNext(), next(), IteratorFlags */
end_comment
begin_constructor
DECL|function|QDirIterator
name|QDirIterator
operator|::
name|QDirIterator
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|IteratorFlags
name|flags
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QDirIteratorPrivate
argument_list|(
name|QFileSystemEntry
argument_list|(
name|path
argument_list|)
argument_list|,
name|QStringList
argument_list|()
argument_list|,
name|QDir
operator|::
name|NoFilter
argument_list|,
name|flags
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a QDirIterator that can iterate over \a path, using \a     nameFilters and \a filters. You can pass options via \a flags to decide     how the directory should be iterated.      By default, \a flags is NoIteratorFlags, which provides the same behavior     as QDir::entryList().      \note To list symlinks that point to non existing files, QDir::System must be      passed to the flags.      \sa hasNext(), next(), IteratorFlags */
end_comment
begin_constructor
DECL|function|QDirIterator
name|QDirIterator
operator|::
name|QDirIterator
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|nameFilters
parameter_list|,
name|QDir
operator|::
name|Filters
name|filters
parameter_list|,
name|IteratorFlags
name|flags
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QDirIteratorPrivate
argument_list|(
name|QFileSystemEntry
argument_list|(
name|path
argument_list|)
argument_list|,
name|nameFilters
argument_list|,
name|filters
argument_list|,
name|flags
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the QDirIterator. */
end_comment
begin_destructor
DECL|function|~QDirIterator
name|QDirIterator
operator|::
name|~
name|QDirIterator
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Advances the iterator to the next entry, and returns the file path of this     new entry. If hasNext() returns false, this function does nothing, and     returns a null QString.      You can call fileName() or filePath() to get the current entry file name     or path, or fileInfo() to get a QFileInfo for the current entry.      \sa hasNext(), fileName(), filePath(), fileInfo() */
end_comment
begin_function
DECL|function|next
name|QString
name|QDirIterator
operator|::
name|next
parameter_list|()
block|{
name|d
operator|->
name|advance
argument_list|()
expr_stmt|;
return|return
name|filePath
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if there is at least one more entry in the directory;     otherwise, false is returned.      \sa next(), fileName(), filePath(), fileInfo() */
end_comment
begin_function
DECL|function|hasNext
name|bool
name|QDirIterator
operator|::
name|hasNext
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|engine
condition|)
return|return
operator|!
name|d
operator|->
name|fileEngineIterators
operator|.
name|isEmpty
argument_list|()
return|;
else|else
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMITERATOR
return|return
operator|!
name|d
operator|->
name|nativeIterators
operator|.
name|isEmpty
argument_list|()
return|;
else|#
directive|else
return|return
literal|false
return|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     Returns the file name for the current directory entry, without the path     prepended.      This function is convenient when iterating a single directory. When using     the QDirIterator::Subdirectories flag, you can use filePath() to get the     full path.      \sa filePath(), fileInfo() */
end_comment
begin_function
DECL|function|fileName
name|QString
name|QDirIterator
operator|::
name|fileName
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|currentFileInfo
operator|.
name|fileName
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the full file path for the current directory entry.      \sa fileInfo(), fileName() */
end_comment
begin_function
DECL|function|filePath
name|QString
name|QDirIterator
operator|::
name|filePath
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|currentFileInfo
operator|.
name|filePath
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a QFileInfo for the current directory entry.      \sa filePath(), fileName() */
end_comment
begin_function
DECL|function|fileInfo
name|QFileInfo
name|QDirIterator
operator|::
name|fileInfo
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|currentFileInfo
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the base directory of the iterator. */
end_comment
begin_function
DECL|function|path
name|QString
name|QDirIterator
operator|::
name|path
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|dirEntry
operator|.
name|filePath
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
