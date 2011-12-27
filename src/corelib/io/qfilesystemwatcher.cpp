begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfilesystemwatcher.h"
end_include
begin_include
include|#
directive|include
file|"qfilesystemwatcher_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
end_ifndef
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qmutex.h>
end_include
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qfilesystemwatcher_win_p.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"qfilesystemwatcher_inotify_p.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_FREEBSD
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_elif
begin_if
if|#
directive|if
operator|(
name|defined
name|Q_OS_MAC
operator|)
operator|&&
operator|(
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_5
operator|)
end_if
begin_include
include|#
directive|include
file|"qfilesystemwatcher_fsevents_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//MAC_OS_X_VERSION_MAX_ALLOWED>= MAC_OS_X_VERSION_10_5)
end_comment
begin_include
include|#
directive|include
file|"qfilesystemwatcher_kqueue_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enumerator|PollingInterval
name|enum
type|{
name|PollingInterval
init|=
literal|1000
end_decl_stmt
begin_class
DECL|class|QPollingFileSystemWatcherEngine
unit|};
class|class
name|QPollingFileSystemWatcherEngine
super|:
specifier|public
name|QFileSystemWatcherEngine
block|{
name|Q_OBJECT
DECL|class|FileInfo
class|class
name|FileInfo
block|{
DECL|member|ownerId
name|uint
name|ownerId
decl_stmt|;
DECL|member|groupId
name|uint
name|groupId
decl_stmt|;
DECL|member|permissions
name|QFile
operator|::
name|Permissions
name|permissions
decl_stmt|;
DECL|member|lastModified
name|QDateTime
name|lastModified
decl_stmt|;
DECL|member|entries
name|QStringList
name|entries
decl_stmt|;
public|public:
DECL|function|FileInfo
name|FileInfo
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|)
member_init_list|:
name|ownerId
argument_list|(
name|fileInfo
operator|.
name|ownerId
argument_list|()
argument_list|)
member_init_list|,
name|groupId
argument_list|(
name|fileInfo
operator|.
name|groupId
argument_list|()
argument_list|)
member_init_list|,
name|permissions
argument_list|(
name|fileInfo
operator|.
name|permissions
argument_list|()
argument_list|)
member_init_list|,
name|lastModified
argument_list|(
name|fileInfo
operator|.
name|lastModified
argument_list|()
argument_list|)
block|{
if|if
condition|(
name|fileInfo
operator|.
name|isDir
argument_list|()
condition|)
block|{
name|entries
operator|=
name|fileInfo
operator|.
name|absoluteDir
argument_list|()
operator|.
name|entryList
argument_list|(
name|QDir
operator|::
name|AllEntries
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|operator =
name|FileInfo
modifier|&
name|operator
name|=
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|)
block|{
operator|*
name|this
operator|=
name|FileInfo
argument_list|(
name|fileInfo
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator !=
name|bool
name|operator
name|!=
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|fileInfo
operator|.
name|isDir
argument_list|()
operator|&&
name|entries
operator|!=
name|fileInfo
operator|.
name|absoluteDir
argument_list|()
operator|.
name|entryList
argument_list|(
name|QDir
operator|::
name|AllEntries
argument_list|)
condition|)
return|return
literal|true
return|;
return|return
operator|(
name|ownerId
operator|!=
name|fileInfo
operator|.
name|ownerId
argument_list|()
operator|||
name|groupId
operator|!=
name|fileInfo
operator|.
name|groupId
argument_list|()
operator|||
name|permissions
operator|!=
name|fileInfo
operator|.
name|permissions
argument_list|()
operator|||
name|lastModified
operator|!=
name|fileInfo
operator|.
name|lastModified
argument_list|()
operator|)
return|;
block|}
block|}
class|;
DECL|member|mutex
specifier|mutable
name|QMutex
name|mutex
decl_stmt|;
DECL|member|files
DECL|member|directories
name|QHash
argument_list|<
name|QString
argument_list|,
name|FileInfo
argument_list|>
name|files
decl_stmt|,
name|directories
decl_stmt|;
public|public:
name|QPollingFileSystemWatcherEngine
parameter_list|()
constructor_decl|;
name|void
name|run
parameter_list|()
function_decl|;
name|QStringList
name|addPaths
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|,
name|QStringList
modifier|*
name|files
parameter_list|,
name|QStringList
modifier|*
name|directories
parameter_list|)
function_decl|;
name|QStringList
name|removePaths
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|,
name|QStringList
modifier|*
name|files
parameter_list|,
name|QStringList
modifier|*
name|directories
parameter_list|)
function_decl|;
name|void
name|stop
parameter_list|()
function_decl|;
private|private
name|Q_SLOTS
private|:
name|void
name|timeout
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QPollingFileSystemWatcherEngine
name|QPollingFileSystemWatcherEngine
operator|::
name|QPollingFileSystemWatcherEngine
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_THREAD
name|moveToThread
argument_list|(
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_function
DECL|function|run
name|void
name|QPollingFileSystemWatcherEngine
operator|::
name|run
parameter_list|()
block|{
name|QTimer
name|timer
decl_stmt|;
name|connect
argument_list|(
operator|&
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|.
name|start
argument_list|(
name|PollingInterval
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addPaths
name|QStringList
name|QPollingFileSystemWatcherEngine
operator|::
name|addPaths
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|,
name|QStringList
modifier|*
name|files
parameter_list|,
name|QStringList
modifier|*
name|directories
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|QStringList
name|p
init|=
name|paths
decl_stmt|;
name|QMutableListIterator
argument_list|<
name|QString
argument_list|>
name|it
argument_list|(
name|p
argument_list|)
decl_stmt|;
while|while
condition|(
name|it
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|QString
name|path
init|=
name|it
operator|.
name|next
argument_list|()
decl_stmt|;
name|QFileInfo
name|fi
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fi
operator|.
name|exists
argument_list|()
condition|)
continue|continue;
if|if
condition|(
name|fi
operator|.
name|isDir
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|directories
operator|->
name|contains
argument_list|(
name|path
argument_list|)
condition|)
name|directories
operator|->
name|append
argument_list|(
name|path
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|fi
operator|=
name|QFileInfo
argument_list|(
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
expr_stmt|;
name|this
operator|->
name|directories
operator|.
name|insert
argument_list|(
name|path
argument_list|,
name|fi
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|files
operator|->
name|contains
argument_list|(
name|path
argument_list|)
condition|)
name|files
operator|->
name|append
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|this
operator|->
name|files
operator|.
name|insert
argument_list|(
name|path
argument_list|,
name|fi
argument_list|)
expr_stmt|;
block|}
name|it
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
name|start
argument_list|()
expr_stmt|;
return|return
name|p
return|;
block|}
end_function
begin_function
DECL|function|removePaths
name|QStringList
name|QPollingFileSystemWatcherEngine
operator|::
name|removePaths
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|,
name|QStringList
modifier|*
name|files
parameter_list|,
name|QStringList
modifier|*
name|directories
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|QStringList
name|p
init|=
name|paths
decl_stmt|;
name|QMutableListIterator
argument_list|<
name|QString
argument_list|>
name|it
argument_list|(
name|p
argument_list|)
decl_stmt|;
while|while
condition|(
name|it
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|QString
name|path
init|=
name|it
operator|.
name|next
argument_list|()
decl_stmt|;
if|if
condition|(
name|this
operator|->
name|directories
operator|.
name|remove
argument_list|(
name|path
argument_list|)
condition|)
block|{
name|directories
operator|->
name|removeAll
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|it
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|this
operator|->
name|files
operator|.
name|remove
argument_list|(
name|path
argument_list|)
condition|)
block|{
name|files
operator|->
name|removeAll
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|it
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
name|this
operator|->
name|files
operator|.
name|isEmpty
argument_list|()
operator|&&
name|this
operator|->
name|directories
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|stop
argument_list|()
expr_stmt|;
name|wait
argument_list|()
expr_stmt|;
block|}
return|return
name|p
return|;
block|}
end_function
begin_function
DECL|function|stop
name|void
name|QPollingFileSystemWatcherEngine
operator|::
name|stop
parameter_list|()
block|{
name|quit
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timeout
name|void
name|QPollingFileSystemWatcherEngine
operator|::
name|timeout
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|QMutableHashIterator
argument_list|<
name|QString
argument_list|,
name|FileInfo
argument_list|>
name|fit
argument_list|(
name|files
argument_list|)
decl_stmt|;
while|while
condition|(
name|fit
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|FileInfo
argument_list|>
operator|::
name|iterator
name|x
init|=
name|fit
operator|.
name|next
argument_list|()
decl_stmt|;
name|QString
name|path
init|=
name|x
operator|.
name|key
argument_list|()
decl_stmt|;
name|QFileInfo
name|fi
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fi
operator|.
name|exists
argument_list|()
condition|)
block|{
name|fit
operator|.
name|remove
argument_list|()
expr_stmt|;
emit|emit
name|fileChanged
argument_list|(
name|path
argument_list|,
literal|true
argument_list|)
emit|;
block|}
elseif|else
if|if
condition|(
name|x
operator|.
name|value
argument_list|()
operator|!=
name|fi
condition|)
block|{
name|x
operator|.
name|value
argument_list|()
operator|=
name|fi
expr_stmt|;
emit|emit
name|fileChanged
argument_list|(
name|path
argument_list|,
literal|false
argument_list|)
emit|;
block|}
block|}
name|QMutableHashIterator
argument_list|<
name|QString
argument_list|,
name|FileInfo
argument_list|>
name|dit
argument_list|(
name|directories
argument_list|)
decl_stmt|;
while|while
condition|(
name|dit
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|FileInfo
argument_list|>
operator|::
name|iterator
name|x
init|=
name|dit
operator|.
name|next
argument_list|()
decl_stmt|;
name|QString
name|path
init|=
name|x
operator|.
name|key
argument_list|()
decl_stmt|;
name|QFileInfo
name|fi
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|fi
operator|=
name|QFileInfo
argument_list|(
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|fi
operator|.
name|exists
argument_list|()
condition|)
block|{
name|dit
operator|.
name|remove
argument_list|()
expr_stmt|;
emit|emit
name|directoryChanged
argument_list|(
name|path
argument_list|,
literal|true
argument_list|)
emit|;
block|}
elseif|else
if|if
condition|(
name|x
operator|.
name|value
argument_list|()
operator|!=
name|fi
condition|)
block|{
name|fi
operator|.
name|refresh
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|fi
operator|.
name|exists
argument_list|()
condition|)
block|{
name|dit
operator|.
name|remove
argument_list|()
expr_stmt|;
emit|emit
name|directoryChanged
argument_list|(
name|path
argument_list|,
literal|true
argument_list|)
emit|;
block|}
else|else
block|{
name|x
operator|.
name|value
argument_list|()
operator|=
name|fi
expr_stmt|;
emit|emit
name|directoryChanged
argument_list|(
name|path
argument_list|,
literal|false
argument_list|)
emit|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|createNativeEngine
name|QFileSystemWatcherEngine
modifier|*
name|QFileSystemWatcherPrivate
operator|::
name|createNativeEngine
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
return|return
operator|new
name|QWindowsFileSystemWatcherEngine
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
comment|// there is a chance that inotify may fail on Linux pre-2.6.13 (August
comment|// 2005), so we can't just new inotify directly.
return|return
name|QInotifyFileSystemWatcherEngine
operator|::
name|create
argument_list|()
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_FREEBSD
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
if|#
directive|if
literal|0
operator|&&
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
operator|(
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_5
operator|)
block|if (QSysInfo::MacintoshVersion>= QSysInfo::MV_10_5)         return QFSEventsFileSystemWatcherEngine::create();     else
endif|#
directive|endif
return|return
name|QKqueueFileSystemWatcherEngine
operator|::
name|create
argument_list|()
return|;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_constructor
DECL|function|QFileSystemWatcherPrivate
name|QFileSystemWatcherPrivate
operator|::
name|QFileSystemWatcherPrivate
parameter_list|()
member_init_list|:
name|native
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|poller
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|init
name|void
name|QFileSystemWatcherPrivate
operator|::
name|init
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
name|native
operator|=
name|createNativeEngine
argument_list|()
expr_stmt|;
if|if
condition|(
name|native
condition|)
block|{
name|QObject
operator|::
name|connect
argument_list|(
name|native
argument_list|,
name|SIGNAL
argument_list|(
name|fileChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_fileChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|native
argument_list|,
name|SIGNAL
argument_list|(
name|directoryChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_directoryChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|initPollerEngine
name|void
name|QFileSystemWatcherPrivate
operator|::
name|initPollerEngine
parameter_list|()
block|{
if|if
condition|(
name|poller
condition|)
return|return;
name|Q_Q
argument_list|(
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
name|poller
operator|=
operator|new
name|QPollingFileSystemWatcherEngine
expr_stmt|;
comment|// that was a mouthful
name|QObject
operator|::
name|connect
argument_list|(
name|poller
argument_list|,
name|SIGNAL
argument_list|(
name|fileChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_fileChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|poller
argument_list|,
name|SIGNAL
argument_list|(
name|directoryChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_directoryChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_fileChanged
name|void
name|QFileSystemWatcherPrivate
operator|::
name|_q_fileChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|bool
name|removed
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|files
operator|.
name|contains
argument_list|(
name|path
argument_list|)
condition|)
block|{
comment|// the path was removed after a change was detected, but before we delivered the signal
return|return;
block|}
if|if
condition|(
name|removed
condition|)
name|files
operator|.
name|removeAll
argument_list|(
name|path
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|fileChanged
argument_list|(
name|path
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|_q_directoryChanged
name|void
name|QFileSystemWatcherPrivate
operator|::
name|_q_directoryChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|bool
name|removed
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|directories
operator|.
name|contains
argument_list|(
name|path
argument_list|)
condition|)
block|{
comment|// perhaps the path was removed after a change was detected, but before we delivered the signal
return|return;
block|}
if|if
condition|(
name|removed
condition|)
name|directories
operator|.
name|removeAll
argument_list|(
name|path
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|directoryChanged
argument_list|(
name|path
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|/*!     \class QFileSystemWatcher     \brief The QFileSystemWatcher class provides an interface for monitoring files and directories for modifications.     \ingroup io     \since 4.2     \reentrant      QFileSystemWatcher monitors the file system for changes to files     and directories by watching a list of specified paths.      Call addPath() to watch a particular file or directory. Multiple     paths can be added using the addPaths() function. Existing paths can     be removed by using the removePath() and removePaths() functions.      QFileSystemWatcher examines each path added to it. Files that have     been added to the QFileSystemWatcher can be accessed using the     files() function, and directories using the directories() function.      The fileChanged() signal is emitted when a file has been modified,     renamed or removed from disk. Similarly, the directoryChanged()     signal is emitted when a directory or its contents is modified or     removed.  Note that QFileSystemWatcher stops monitoring files once     they have been renamed or removed from disk, and directories once     they have been removed from disk.      \note On systems running a Linux kernel without inotify support,     file systems that contain watched paths cannot be unmounted.      \note Windows CE does not support directory monitoring by     default as this depends on the file system driver installed.      \note The act of monitoring files and directories for     modifications consumes system resources. This implies there is a     limit to the number of files and directories your process can     monitor simultaneously. On Mac OS X 10.4 and all BSD variants, for     example, an open file descriptor is required for each monitored     file. Some system limits the number of open file descriptors to 256     by default. This means that addPath() and addPaths() will fail if     your process tries to add more than 256 files or directories to     the file system monitor. Also note that your process may have     other file descriptors open in addition to the ones for files     being monitored, and these other open descriptors also count in     the total. Mac OS X 10.5 and up use a different backend and do not     suffer from this issue.       \sa QFile, QDir */
end_comment
begin_comment
comment|/*!     Constructs a new file system watcher object with the given \a parent. */
end_comment
begin_constructor
DECL|function|QFileSystemWatcher
name|QFileSystemWatcher
operator|::
name|QFileSystemWatcher
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QFileSystemWatcherPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a new file system watcher object with the given \a parent     which monitors the specified \a paths list. */
end_comment
begin_constructor
DECL|function|QFileSystemWatcher
name|QFileSystemWatcher
operator|::
name|QFileSystemWatcher
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QFileSystemWatcherPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|init
argument_list|()
expr_stmt|;
name|addPaths
argument_list|(
name|paths
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the file system watcher. */
end_comment
begin_destructor
DECL|function|~QFileSystemWatcher
name|QFileSystemWatcher
operator|::
name|~
name|QFileSystemWatcher
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|native
condition|)
block|{
name|d
operator|->
name|native
operator|->
name|stop
argument_list|()
expr_stmt|;
name|d
operator|->
name|native
operator|->
name|wait
argument_list|()
expr_stmt|;
operator|delete
name|d
operator|->
name|native
expr_stmt|;
name|d
operator|->
name|native
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|poller
condition|)
block|{
name|d
operator|->
name|poller
operator|->
name|stop
argument_list|()
expr_stmt|;
name|d
operator|->
name|poller
operator|->
name|wait
argument_list|()
expr_stmt|;
operator|delete
name|d
operator|->
name|poller
expr_stmt|;
name|d
operator|->
name|poller
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_destructor
begin_comment
comment|/*!     Adds \a path to the file system watcher if \a path exists. The     path is not added if it does not exist, or if it is already being     monitored by the file system watcher.      If \a path specifies a directory, the directoryChanged() signal     will be emitted when \a path is modified or removed from disk;     otherwise the fileChanged() signal is emitted when \a path is     modified, renamed or removed.      \note There is a system dependent limit to the number of files and     directories that can be monitored simultaneously. If this limit     has been reached, \a path will not be added to the file system     watcher, and a warning message will be printed to \e{stderr}.      \sa addPaths(), removePath() */
end_comment
begin_function
DECL|function|addPath
name|void
name|QFileSystemWatcher
operator|::
name|addPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
if|if
condition|(
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QFileSystemWatcher::addPath: path is empty"
argument_list|)
expr_stmt|;
return|return;
block|}
name|addPaths
argument_list|(
name|QStringList
argument_list|(
name|path
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Adds each path in \a paths to the file system watcher. Paths are     not added if they not exist, or if they are already being     monitored by the file system watcher.      If a path specifies a directory, the directoryChanged() signal     will be emitted when the path is modified or removed from disk;     otherwise the fileChanged() signal is emitted when the path is     modified, renamed, or removed.      \note There is a system dependent limit to the number of files and     directories that can be monitored simultaneously. If this limit     has been reached, the excess \a paths will not be added to the     file system watcher, and a warning message will be printed to     \e{stderr} for each path that could not be added.      \sa addPath(), removePaths() */
end_comment
begin_function
DECL|function|addPaths
name|void
name|QFileSystemWatcher
operator|::
name|addPaths
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
name|paths
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QFileSystemWatcher::addPaths: list is empty"
argument_list|)
expr_stmt|;
return|return;
block|}
name|QStringList
name|p
init|=
name|paths
decl_stmt|;
name|QFileSystemWatcherEngine
modifier|*
name|engine
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|objectName
argument_list|()
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"_qt_autotest_force_engine_"
argument_list|)
argument_list|)
condition|)
block|{
comment|// Normal runtime case - search intelligently for best engine
if|if
condition|(
name|d
operator|->
name|native
condition|)
block|{
name|engine
operator|=
name|d
operator|->
name|native
expr_stmt|;
block|}
else|else
block|{
name|d_func
argument_list|()
operator|->
name|initPollerEngine
argument_list|()
expr_stmt|;
name|engine
operator|=
name|d
operator|->
name|poller
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// Autotest override case - use the explicitly selected engine only
name|QString
name|forceName
init|=
name|objectName
argument_list|()
operator|.
name|mid
argument_list|(
literal|26
argument_list|)
decl_stmt|;
if|if
condition|(
name|forceName
operator|==
name|QLatin1String
argument_list|(
literal|"poller"
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"QFileSystemWatcher: skipping native engine, using only polling engine"
expr_stmt|;
name|d_func
argument_list|()
operator|->
name|initPollerEngine
argument_list|()
expr_stmt|;
name|engine
operator|=
name|d
operator|->
name|poller
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|forceName
operator|==
name|QLatin1String
argument_list|(
literal|"native"
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"QFileSystemWatcher: skipping polling engine, using only native engine"
expr_stmt|;
name|engine
operator|=
name|d
operator|->
name|native
expr_stmt|;
block|}
block|}
if|if
condition|(
name|engine
condition|)
name|p
operator|=
name|engine
operator|->
name|addPaths
argument_list|(
name|p
argument_list|,
operator|&
name|d
operator|->
name|files
argument_list|,
operator|&
name|d
operator|->
name|directories
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|p
operator|.
name|isEmpty
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"QFileSystemWatcher: failed to add paths: %s"
argument_list|,
name|qPrintable
argument_list|(
name|p
operator|.
name|join
argument_list|(
name|QLatin1String
argument_list|(
literal|", "
argument_list|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes the specified \a path from the file system watcher.      \sa removePaths(), addPath() */
end_comment
begin_function
DECL|function|removePath
name|void
name|QFileSystemWatcher
operator|::
name|removePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
if|if
condition|(
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QFileSystemWatcher::removePath: path is empty"
argument_list|)
expr_stmt|;
return|return;
block|}
name|removePaths
argument_list|(
name|QStringList
argument_list|(
name|path
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes the specified \a paths from the file system watcher.      \sa removePath(), addPaths() */
end_comment
begin_function
DECL|function|removePaths
name|void
name|QFileSystemWatcher
operator|::
name|removePaths
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|)
block|{
if|if
condition|(
name|paths
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QFileSystemWatcher::removePaths: list is empty"
argument_list|)
expr_stmt|;
return|return;
block|}
name|Q_D
argument_list|(
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
name|QStringList
name|p
init|=
name|paths
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|native
condition|)
name|p
operator|=
name|d
operator|->
name|native
operator|->
name|removePaths
argument_list|(
name|p
argument_list|,
operator|&
name|d
operator|->
name|files
argument_list|,
operator|&
name|d
operator|->
name|directories
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|poller
condition|)
name|p
operator|=
name|d
operator|->
name|poller
operator|->
name|removePaths
argument_list|(
name|p
argument_list|,
operator|&
name|d
operator|->
name|files
argument_list|,
operator|&
name|d
operator|->
name|directories
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn void QFileSystemWatcher::fileChanged(const QString&path)      This signal is emitted when the file at the specified \a path is     modified, renamed or removed from disk.      \sa directoryChanged() */
end_comment
begin_comment
comment|/*!     \fn void QFileSystemWatcher::directoryChanged(const QString&path)      This signal is emitted when the directory at a specified \a path,     is modified (e.g., when a file is added, modified or deleted) or     removed from disk. Note that if there are several changes during a     short period of time, some of the changes might not emit this     signal. However, the last change in the sequence of changes will     always generate this signal.      \sa fileChanged() */
end_comment
begin_comment
comment|/*!     \fn QStringList QFileSystemWatcher::directories() const      Returns a list of paths to directories that are being watched.      \sa files() */
end_comment
begin_comment
comment|/*!     \fn QStringList QFileSystemWatcher::files() const      Returns a list of paths to files that are being watched.      \sa directories() */
end_comment
begin_function
DECL|function|directories
name|QStringList
name|QFileSystemWatcher
operator|::
name|directories
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|directories
return|;
block|}
end_function
begin_function
DECL|function|files
name|QStringList
name|QFileSystemWatcher
operator|::
name|files
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|files
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qfilesystemwatcher.cpp"
end_include
begin_include
include|#
directive|include
file|"qfilesystemwatcher.moc"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FILESYSTEMWATCHER
end_comment
end_unit
