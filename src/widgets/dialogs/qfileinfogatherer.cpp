begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfileinfogatherer_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qdiriterator.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WIN
end_ifndef
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMMODEL
ifdef|#
directive|ifdef
name|QT_BUILD_INTERNAL
DECL|variable|fetchedRoot
specifier|static
name|QBasicAtomicInt
name|fetchedRoot
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|false
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qt_test_resetFetchedRoot
name|Q_AUTOTEST_EXPORT
name|void
name|qt_test_resetFetchedRoot
parameter_list|()
block|{
name|fetchedRoot
operator|.
name|store
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qt_test_isFetchedRoot
name|Q_AUTOTEST_EXPORT
name|bool
name|qt_test_isFetchedRoot
parameter_list|()
block|{
return|return
name|fetchedRoot
operator|.
name|load
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Creates thread */
end_comment
begin_constructor
DECL|function|QFileInfoGatherer
name|QFileInfoGatherer
operator|::
name|QFileInfoGatherer
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|abort
argument_list|(
literal|false
argument_list|)
member_init_list|,
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
name|watcher
argument_list|(
literal|0
argument_list|)
member_init_list|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|m_resolveSymlinks
argument_list|(
literal|true
argument_list|)
member_init_list|,
endif|#
directive|endif
name|m_iconProvider
argument_list|(
operator|&
name|defaultProvider
argument_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
name|watcher
operator|=
operator|new
name|QFileSystemWatcher
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|directoryChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|list
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|fileChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateFile
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|start
argument_list|(
name|LowPriority
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys thread */
end_comment
begin_destructor
DECL|function|~QFileInfoGatherer
name|QFileInfoGatherer
operator|::
name|~
name|QFileInfoGatherer
parameter_list|()
block|{
name|abort
operator|.
name|store
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|condition
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|wait
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setResolveSymlinks
name|void
name|QFileInfoGatherer
operator|::
name|setResolveSymlinks
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|enable
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|m_resolveSymlinks
operator|=
name|enable
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|resolveSymlinks
name|bool
name|QFileInfoGatherer
operator|::
name|resolveSymlinks
parameter_list|()
specifier|const
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
return|return
name|m_resolveSymlinks
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
begin_function
DECL|function|setIconProvider
name|void
name|QFileInfoGatherer
operator|::
name|setIconProvider
parameter_list|(
name|QFileIconProvider
modifier|*
name|provider
parameter_list|)
block|{
name|m_iconProvider
operator|=
name|provider
expr_stmt|;
block|}
end_function
begin_function
DECL|function|iconProvider
name|QFileIconProvider
modifier|*
name|QFileInfoGatherer
operator|::
name|iconProvider
parameter_list|()
specifier|const
block|{
return|return
name|m_iconProvider
return|;
block|}
end_function
begin_comment
comment|/*!     Fetch extended information for all \a files in \a path      \sa updateFile(), update(), resolvedName() */
end_comment
begin_function
DECL|function|fetchExtendedInformation
name|void
name|QFileInfoGatherer
operator|::
name|fetchExtendedInformation
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|files
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
comment|// See if we already have this dir/file in our queue
name|int
name|loc
init|=
name|this
operator|->
name|path
operator|.
name|lastIndexOf
argument_list|(
name|path
argument_list|)
decl_stmt|;
while|while
condition|(
name|loc
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|this
operator|->
name|files
operator|.
name|at
argument_list|(
name|loc
argument_list|)
operator|==
name|files
condition|)
block|{
return|return;
block|}
name|loc
operator|=
name|this
operator|->
name|path
operator|.
name|lastIndexOf
argument_list|(
name|path
argument_list|,
name|loc
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|this
operator|->
name|path
operator|.
name|push
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|this
operator|->
name|files
operator|.
name|push
argument_list|(
name|files
argument_list|)
expr_stmt|;
name|condition
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
if|if
condition|(
name|files
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|path
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"//"
argument_list|)
argument_list|)
comment|/*don't watch UNC path*/
condition|)
block|{
if|if
condition|(
operator|!
name|watcher
operator|->
name|directories
argument_list|()
operator|.
name|contains
argument_list|(
name|path
argument_list|)
condition|)
name|watcher
operator|->
name|addPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     Fetch extended information for all \a filePath      \sa fetchExtendedInformation() */
end_comment
begin_function
DECL|function|updateFile
name|void
name|QFileInfoGatherer
operator|::
name|updateFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
block|{
name|QString
name|dir
init|=
name|filePath
operator|.
name|mid
argument_list|(
literal|0
argument_list|,
name|filePath
operator|.
name|lastIndexOf
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|fileName
init|=
name|filePath
operator|.
name|mid
argument_list|(
name|dir
operator|.
name|length
argument_list|()
operator|+
literal|1
argument_list|)
decl_stmt|;
name|fetchExtendedInformation
argument_list|(
name|dir
argument_list|,
name|QStringList
argument_list|(
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     List all files in \a directoryPath      \sa listed() */
end_comment
begin_function
DECL|function|clear
name|void
name|QFileInfoGatherer
operator|::
name|clear
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|watcher
operator|->
name|removePaths
argument_list|(
name|watcher
operator|->
name|files
argument_list|()
argument_list|)
expr_stmt|;
name|watcher
operator|->
name|removePaths
argument_list|(
name|watcher
operator|->
name|directories
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*     Remove a \a path from the watcher      \sa listed() */
end_comment
begin_function
DECL|function|removePath
name|void
name|QFileInfoGatherer
operator|::
name|removePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|watcher
operator|->
name|removePath
argument_list|(
name|path
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*     List all files in \a directoryPath      \sa listed() */
end_comment
begin_function
DECL|function|list
name|void
name|QFileInfoGatherer
operator|::
name|list
parameter_list|(
specifier|const
name|QString
modifier|&
name|directoryPath
parameter_list|)
block|{
name|fetchExtendedInformation
argument_list|(
name|directoryPath
argument_list|,
name|QStringList
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Until aborted wait to fetch a directory or files */
end_comment
begin_function
DECL|function|run
name|void
name|QFileInfoGatherer
operator|::
name|run
parameter_list|()
block|{
forever|forever
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|abort
operator|.
name|load
argument_list|()
operator|&&
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
name|condition
operator|.
name|wait
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
if|if
condition|(
name|abort
operator|.
name|load
argument_list|()
condition|)
return|return;
specifier|const
name|QString
name|thisPath
init|=
name|path
operator|.
name|front
argument_list|()
decl_stmt|;
name|path
operator|.
name|pop_front
argument_list|()
expr_stmt|;
specifier|const
name|QStringList
name|thisList
init|=
name|files
operator|.
name|front
argument_list|()
decl_stmt|;
name|files
operator|.
name|pop_front
argument_list|()
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|getFileInfos
argument_list|(
name|thisPath
argument_list|,
name|thisList
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|getInfo
name|QExtendedInformation
name|QFileInfoGatherer
operator|::
name|getInfo
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|)
specifier|const
block|{
name|QExtendedInformation
name|info
argument_list|(
name|fileInfo
argument_list|)
decl_stmt|;
name|info
operator|.
name|icon
operator|=
name|m_iconProvider
operator|->
name|icon
argument_list|(
name|fileInfo
argument_list|)
expr_stmt|;
name|info
operator|.
name|displayType
operator|=
name|m_iconProvider
operator|->
name|type
argument_list|(
name|fileInfo
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
comment|// ### Not ready to listen all modifications
if|#
directive|if
literal|0
comment|// Enable the next two commented out lines to get updates when the file sizes change...
block|if (!fileInfo.exists()&& !fileInfo.isSymLink()) {             info.size = -1;
comment|//watcher->removePath(fileInfo.absoluteFilePath());
block|} else {             if (!fileInfo.absoluteFilePath().isEmpty()&& fileInfo.exists()&& fileInfo.isReadable()&& !watcher->files().contains(fileInfo.absoluteFilePath())) {
comment|//watcher->addPath(fileInfo.absoluteFilePath());
block|}         }
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|m_resolveSymlinks
operator|&&
name|info
operator|.
name|isSymLink
argument_list|(
comment|/* ignoreNtfsSymLinks = */
literal|true
argument_list|)
condition|)
block|{
name|QFileInfo
name|resolvedInfo
argument_list|(
name|fileInfo
operator|.
name|symLinkTarget
argument_list|()
argument_list|)
decl_stmt|;
name|resolvedInfo
operator|=
name|resolvedInfo
operator|.
name|canonicalFilePath
argument_list|()
expr_stmt|;
if|if
condition|(
name|resolvedInfo
operator|.
name|exists
argument_list|()
condition|)
block|{
emit|emit
name|nameResolved
argument_list|(
name|fileInfo
operator|.
name|filePath
argument_list|()
argument_list|,
name|resolvedInfo
operator|.
name|fileName
argument_list|()
argument_list|)
emit|;
block|}
block|}
endif|#
directive|endif
return|return
name|info
return|;
block|}
end_function
begin_function
DECL|function|translateDriveName
specifier|static
name|QString
name|translateDriveName
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|drive
parameter_list|)
block|{
name|QString
name|driveName
init|=
name|drive
operator|.
name|absoluteFilePath
argument_list|()
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
if|if
condition|(
name|driveName
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
comment|// UNC host
return|return
name|drive
operator|.
name|fileName
argument_list|()
return|;
if|if
condition|(
name|driveName
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|driveName
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|driveName
return|;
block|}
end_function
begin_comment
comment|/*     Get specific file info's, batch the files so update when we have 100     items and every 200ms after that  */
end_comment
begin_function
DECL|function|getFileInfos
name|void
name|QFileInfoGatherer
operator|::
name|getFileInfos
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|files
parameter_list|)
block|{
comment|// List drives
if|if
condition|(
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_BUILD_INTERNAL
name|fetchedRoot
operator|.
name|store
argument_list|(
literal|true
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QFileInfoList
name|infoList
decl_stmt|;
if|if
condition|(
name|files
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|infoList
operator|=
name|QDir
operator|::
name|drives
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|infoList
operator|.
name|reserve
argument_list|(
name|files
operator|.
name|count
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
name|files
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|infoList
operator|<<
name|QFileInfo
argument_list|(
name|files
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
name|infoList
operator|.
name|count
argument_list|()
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
block|{
name|QString
name|driveName
init|=
name|translateDriveName
argument_list|(
name|infoList
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|QFileInfo
argument_list|>
argument_list|>
name|updatedFiles
decl_stmt|;
name|updatedFiles
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|QString
argument_list|,
name|QFileInfo
argument_list|>
argument_list|(
name|driveName
argument_list|,
name|infoList
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
emit|emit
name|updates
argument_list|(
name|path
argument_list|,
name|updatedFiles
argument_list|)
emit|;
block|}
return|return;
block|}
name|QElapsedTimer
name|base
decl_stmt|;
name|base
operator|.
name|start
argument_list|()
expr_stmt|;
name|QFileInfo
name|fileInfo
decl_stmt|;
name|bool
name|firstTime
init|=
literal|true
decl_stmt|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|QFileInfo
argument_list|>
argument_list|>
name|updatedFiles
decl_stmt|;
name|QStringList
name|filesToCheck
init|=
name|files
decl_stmt|;
name|QString
name|itPath
init|=
name|QDir
operator|::
name|fromNativeSeparators
argument_list|(
name|files
operator|.
name|isEmpty
argument_list|()
condition|?
name|path
else|:
name|QLatin1String
argument_list|(
literal|""
argument_list|)
argument_list|)
decl_stmt|;
name|QDirIterator
name|dirIt
argument_list|(
name|itPath
argument_list|,
name|QDir
operator|::
name|AllEntries
operator||
name|QDir
operator|::
name|System
operator||
name|QDir
operator|::
name|Hidden
argument_list|)
decl_stmt|;
name|QStringList
name|allFiles
decl_stmt|;
while|while
condition|(
operator|!
name|abort
operator|.
name|load
argument_list|()
operator|&&
name|dirIt
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|dirIt
operator|.
name|next
argument_list|()
expr_stmt|;
name|fileInfo
operator|=
name|dirIt
operator|.
name|fileInfo
argument_list|()
expr_stmt|;
name|allFiles
operator|.
name|append
argument_list|(
name|fileInfo
operator|.
name|fileName
argument_list|()
argument_list|)
expr_stmt|;
name|fetch
argument_list|(
name|fileInfo
argument_list|,
name|base
argument_list|,
name|firstTime
argument_list|,
name|updatedFiles
argument_list|,
name|path
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|allFiles
operator|.
name|isEmpty
argument_list|()
condition|)
emit|emit
name|newListOfFiles
argument_list|(
name|path
argument_list|,
name|allFiles
argument_list|)
emit|;
name|QStringList
operator|::
name|const_iterator
name|filesIt
init|=
name|filesToCheck
operator|.
name|constBegin
argument_list|()
decl_stmt|;
while|while
condition|(
operator|!
name|abort
operator|.
name|load
argument_list|()
operator|&&
name|filesIt
operator|!=
name|filesToCheck
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|fileInfo
operator|.
name|setFile
argument_list|(
name|path
operator|+
name|QDir
operator|::
name|separator
argument_list|()
operator|+
operator|*
name|filesIt
argument_list|)
expr_stmt|;
operator|++
name|filesIt
expr_stmt|;
name|fetch
argument_list|(
name|fileInfo
argument_list|,
name|base
argument_list|,
name|firstTime
argument_list|,
name|updatedFiles
argument_list|,
name|path
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|updatedFiles
operator|.
name|isEmpty
argument_list|()
condition|)
emit|emit
name|updates
argument_list|(
name|path
argument_list|,
name|updatedFiles
argument_list|)
emit|;
emit|emit
name|directoryLoaded
argument_list|(
name|path
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|fetch
name|void
name|QFileInfoGatherer
operator|::
name|fetch
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|,
name|QElapsedTimer
modifier|&
name|base
parameter_list|,
name|bool
modifier|&
name|firstTime
parameter_list|,
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|QFileInfo
argument_list|>
argument_list|>
modifier|&
name|updatedFiles
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
name|updatedFiles
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|QString
argument_list|,
name|QFileInfo
argument_list|>
argument_list|(
name|fileInfo
operator|.
name|fileName
argument_list|()
argument_list|,
name|fileInfo
argument_list|)
argument_list|)
expr_stmt|;
name|QElapsedTimer
name|current
decl_stmt|;
name|current
operator|.
name|start
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|firstTime
operator|&&
name|updatedFiles
operator|.
name|count
argument_list|()
operator|>
literal|100
operator|)
operator|||
name|base
operator|.
name|msecsTo
argument_list|(
name|current
argument_list|)
operator|>
literal|1000
condition|)
block|{
emit|emit
name|updates
argument_list|(
name|path
argument_list|,
name|updatedFiles
argument_list|)
emit|;
name|updatedFiles
operator|.
name|clear
argument_list|()
expr_stmt|;
name|base
operator|=
name|current
expr_stmt|;
name|firstTime
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FILESYSTEMMODEL
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
