begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfilesystemwatcher.h"
end_include
begin_include
include|#
directive|include
file|"qfilesystemwatcher_win_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
end_ifndef
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qtextstream.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|function|~QWindowsFileSystemWatcherEngine
name|QWindowsFileSystemWatcherEngine
operator|::
name|~
name|QWindowsFileSystemWatcherEngine
operator|(
operator|)
block|{
foreach|foreach
control|(
name|QWindowsFileSystemWatcherEngineThread
modifier|*
name|thread
decl|,
name|threads
control|)
block|{
name|thread
operator|->
name|stop
argument_list|()
expr_stmt|;
name|thread
operator|->
name|wait
argument_list|()
expr_stmt|;
operator|delete
name|thread
expr_stmt|;
block|}
end_expr_stmt
begin_macro
unit|}  QStringList
DECL|function|addPaths
name|QWindowsFileSystemWatcherEngine
end_macro
begin_expr_stmt
DECL|function|addPaths
operator|::
name|addPaths
operator|(
specifier|const
name|QStringList
operator|&
name|paths
operator|,
name|QStringList
operator|*
name|files
operator|,
name|QStringList
operator|*
name|directories
operator|)
block|{
comment|// qDebug()<<"Adding"<<paths.count()<<"to existing"<<(files->count() + directories->count())<<"watchers";
name|QStringList
name|p
operator|=
name|paths
block|;
name|QMutableListIterator
argument_list|<
name|QString
argument_list|>
name|it
argument_list|(
name|p
argument_list|)
block|;
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
name|QString
name|normalPath
init|=
name|path
decl_stmt|;
if|if
condition|(
operator|(
name|normalPath
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
operator|&&
operator|!
name|normalPath
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|":/"
argument_list|)
argument_list|)
operator|)
operator|||
operator|(
name|normalPath
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
operator|&&
operator|!
name|normalPath
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|":\\"
argument_list|)
argument_list|)
operator|)
ifdef|#
directive|ifdef
name|Q_OS_WINCE
operator|&&
name|normalPath
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
else|#
directive|else
block|)
endif|#
directive|endif
name|normalPath
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QFileInfo
name|fileInfo
argument_list|(
name|normalPath
operator|.
name|toLower
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|fileInfo
operator|.
name|exists
argument_list|()
condition|)
continue|continue;
end_if
begin_decl_stmt
name|bool
name|isDir
init|=
name|fileInfo
operator|.
name|isDir
argument_list|()
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|isDir
condition|)
block|{
if|if
condition|(
name|directories
operator|->
name|contains
argument_list|(
name|path
argument_list|)
condition|)
continue|continue;
block|}
else|else
block|{
if|if
condition|(
name|files
operator|->
name|contains
argument_list|(
name|path
argument_list|)
condition|)
continue|continue;
block|}
end_if
begin_comment
comment|// qDebug()<<"Looking for a thread/handle for"<<normalPath;
end_comment
begin_decl_stmt
specifier|const
name|QString
name|absolutePath
init|=
name|isDir
condition|?
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
else|:
name|fileInfo
operator|.
name|absolutePath
argument_list|()
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|uint
name|flags
init|=
name|isDir
condition|?
operator|(
name|FILE_NOTIFY_CHANGE_DIR_NAME
operator||
name|FILE_NOTIFY_CHANGE_FILE_NAME
operator|)
else|:
operator|(
name|FILE_NOTIFY_CHANGE_DIR_NAME
operator||
name|FILE_NOTIFY_CHANGE_FILE_NAME
operator||
name|FILE_NOTIFY_CHANGE_ATTRIBUTES
operator||
name|FILE_NOTIFY_CHANGE_SIZE
operator||
name|FILE_NOTIFY_CHANGE_LAST_WRITE
operator||
name|FILE_NOTIFY_CHANGE_SECURITY
operator|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QWindowsFileSystemWatcherEngine
operator|::
name|PathInfo
name|pathInfo
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|pathInfo
operator|.
name|absolutePath
operator|=
name|absolutePath
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|pathInfo
operator|.
name|isDir
operator|=
name|isDir
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|pathInfo
operator|.
name|path
operator|=
name|path
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|pathInfo
operator|=
name|fileInfo
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Look for a thread
end_comment
begin_decl_stmt
name|QWindowsFileSystemWatcherEngineThread
modifier|*
name|thread
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QWindowsFileSystemWatcherEngine
operator|::
name|Handle
name|handle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QList
argument_list|<
name|QWindowsFileSystemWatcherEngineThread
modifier|*
argument_list|>
operator|::
name|const_iterator
name|jt
decl_stmt|,
name|end
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|end
operator|=
name|threads
operator|.
name|constEnd
argument_list|()
expr_stmt|;
end_expr_stmt
begin_for
for|for
control|(
name|jt
operator|=
name|threads
operator|.
name|constBegin
argument_list|()
init|;
name|jt
operator|!=
name|end
condition|;
operator|++
name|jt
control|)
block|{
name|thread
operator|=
operator|*
name|jt
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
operator|(
name|thread
operator|->
name|mutex
operator|)
argument_list|)
decl_stmt|;
name|handle
operator|=
name|thread
operator|->
name|handleForDir
operator|.
name|value
argument_list|(
name|absolutePath
argument_list|)
expr_stmt|;
if|if
condition|(
name|handle
operator|.
name|handle
operator|!=
name|INVALID_HANDLE_VALUE
operator|&&
name|handle
operator|.
name|flags
operator|==
name|flags
condition|)
block|{
comment|// found a thread now insert...
comment|// qDebug()<<"  Found a thread"<<thread;
name|QHash
argument_list|<
name|QString
argument_list|,
name|QWindowsFileSystemWatcherEngine
operator|::
name|PathInfo
argument_list|>
modifier|&
name|h
init|=
name|thread
operator|->
name|pathInfoForHandle
index|[
name|handle
operator|.
name|handle
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|h
operator|.
name|contains
argument_list|(
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
condition|)
block|{
name|thread
operator|->
name|pathInfoForHandle
index|[
name|handle
operator|.
name|handle
index|]
operator|.
name|insert
argument_list|(
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|,
name|pathInfo
argument_list|)
expr_stmt|;
if|if
condition|(
name|isDir
condition|)
name|directories
operator|->
name|append
argument_list|(
name|path
argument_list|)
expr_stmt|;
else|else
name|files
operator|->
name|append
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
name|it
operator|.
name|remove
argument_list|()
expr_stmt|;
name|thread
operator|->
name|wakeup
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
end_for
begin_comment
comment|// no thread found, first create a handle
end_comment
begin_if
if|if
condition|(
name|handle
operator|.
name|handle
operator|==
name|INVALID_HANDLE_VALUE
operator|||
name|handle
operator|.
name|flags
operator|!=
name|flags
condition|)
block|{
comment|// qDebug()<<"  No thread found";
comment|// Volume and folder paths need a trailing slash for proper notification
comment|// (e.g. "c:" -> "c:/").
specifier|const
name|QString
name|effectiveAbsolutePath
init|=
name|isDir
condition|?
operator|(
name|absolutePath
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|)
else|:
name|absolutePath
decl_stmt|;
name|handle
operator|.
name|handle
operator|=
name|FindFirstChangeNotification
argument_list|(
operator|(
name|wchar_t
operator|*
operator|)
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|effectiveAbsolutePath
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|,
literal|false
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|handle
operator|.
name|flags
operator|=
name|flags
expr_stmt|;
if|if
condition|(
name|handle
operator|.
name|handle
operator|==
name|INVALID_HANDLE_VALUE
condition|)
continue|continue;
comment|// now look for a thread to insert
name|bool
name|found
init|=
literal|false
decl_stmt|;
foreach|foreach
control|(
name|QWindowsFileSystemWatcherEngineThread
modifier|*
name|thread
decl|,
name|threads
control|)
block|{
name|QMutexLocker
argument_list|(
operator|&
operator|(
name|thread
operator|->
name|mutex
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|thread
operator|->
name|handles
operator|.
name|count
argument_list|()
operator|<
name|MAXIMUM_WAIT_OBJECTS
condition|)
block|{
comment|// qDebug()<< "  Added handle"<< handle.handle<< "for"<< absolutePath<< "to watch"<< fileInfo.absoluteFilePath();
comment|// qDebug()<< "  to existing thread"<<thread;
name|thread
operator|->
name|handles
operator|.
name|append
argument_list|(
name|handle
operator|.
name|handle
argument_list|)
expr_stmt|;
name|thread
operator|->
name|handleForDir
operator|.
name|insert
argument_list|(
name|absolutePath
argument_list|,
name|handle
argument_list|)
expr_stmt|;
name|thread
operator|->
name|pathInfoForHandle
index|[
name|handle
operator|.
name|handle
index|]
operator|.
name|insert
argument_list|(
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|,
name|pathInfo
argument_list|)
expr_stmt|;
if|if
condition|(
name|isDir
condition|)
name|directories
operator|->
name|append
argument_list|(
name|path
argument_list|)
expr_stmt|;
else|else
name|files
operator|->
name|append
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|it
operator|.
name|remove
argument_list|()
expr_stmt|;
name|found
operator|=
literal|true
expr_stmt|;
name|thread
operator|->
name|wakeup
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|found
condition|)
block|{
name|QWindowsFileSystemWatcherEngineThread
modifier|*
name|thread
init|=
operator|new
name|QWindowsFileSystemWatcherEngineThread
argument_list|()
decl_stmt|;
comment|//qDebug()<<"  ###Creating new thread"<<thread<<"("<<(threads.count()+1)<<"threads)";
name|thread
operator|->
name|handles
operator|.
name|append
argument_list|(
name|handle
operator|.
name|handle
argument_list|)
expr_stmt|;
name|thread
operator|->
name|handleForDir
operator|.
name|insert
argument_list|(
name|absolutePath
argument_list|,
name|handle
argument_list|)
expr_stmt|;
name|thread
operator|->
name|pathInfoForHandle
index|[
name|handle
operator|.
name|handle
index|]
operator|.
name|insert
argument_list|(
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|,
name|pathInfo
argument_list|)
expr_stmt|;
if|if
condition|(
name|isDir
condition|)
name|directories
operator|->
name|append
argument_list|(
name|path
argument_list|)
expr_stmt|;
else|else
name|files
operator|->
name|append
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|thread
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
name|this
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
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|thread
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
name|this
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
argument_list|)
expr_stmt|;
name|thread
operator|->
name|msg
operator|=
literal|'@'
expr_stmt|;
name|thread
operator|->
name|start
argument_list|()
expr_stmt|;
name|threads
operator|.
name|append
argument_list|(
name|thread
argument_list|)
expr_stmt|;
name|it
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
block|}
end_if
begin_expr_stmt
unit|}     return
name|p
expr_stmt|;
end_expr_stmt
begin_macro
unit|}  QStringList
DECL|function|removePaths
name|QWindowsFileSystemWatcherEngine
end_macro
begin_expr_stmt
DECL|function|removePaths
operator|::
name|removePaths
operator|(
specifier|const
name|QStringList
operator|&
name|paths
operator|,
name|QStringList
operator|*
name|files
operator|,
name|QStringList
operator|*
name|directories
operator|)
block|{
comment|// qDebug()<<"removePaths"<<paths;
name|QStringList
name|p
operator|=
name|paths
block|;
name|QMutableListIterator
argument_list|<
name|QString
argument_list|>
name|it
argument_list|(
name|p
argument_list|)
block|;
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
name|QString
name|normalPath
init|=
name|path
decl_stmt|;
if|if
condition|(
name|normalPath
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
operator|||
name|normalPath
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
condition|)
name|normalPath
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QFileInfo
name|fileInfo
argument_list|(
name|normalPath
operator|.
name|toLower
argument_list|()
argument_list|)
decl_stmt|;
comment|// qDebug()<<"removing"<<normalPath;
name|QString
name|absolutePath
init|=
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QWindowsFileSystemWatcherEngineThread
operator|*
argument_list|>
operator|::
name|iterator
name|jt
decl_stmt|,
name|end
decl_stmt|;
name|end
operator|=
name|threads
operator|.
name|end
argument_list|()
expr_stmt|;
for|for
control|(
name|jt
operator|=
name|threads
operator|.
name|begin
argument_list|()
init|;
name|jt
operator|!=
name|end
condition|;
operator|++
name|jt
control|)
block|{
name|QWindowsFileSystemWatcherEngineThread
modifier|*
name|thread
init|=
operator|*
name|jt
decl_stmt|;
if|if
condition|(
operator|*
name|jt
operator|==
literal|0
condition|)
continue|continue;
name|QMutexLocker
name|locker
argument_list|(
operator|&
operator|(
name|thread
operator|->
name|mutex
operator|)
argument_list|)
decl_stmt|;
name|QWindowsFileSystemWatcherEngine
operator|::
name|Handle
name|handle
init|=
name|thread
operator|->
name|handleForDir
operator|.
name|value
argument_list|(
name|absolutePath
argument_list|)
decl_stmt|;
if|if
condition|(
name|handle
operator|.
name|handle
operator|==
name|INVALID_HANDLE_VALUE
condition|)
block|{
comment|// perhaps path is a file?
name|absolutePath
operator|=
name|fileInfo
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
name|handle
operator|=
name|thread
operator|->
name|handleForDir
operator|.
name|value
argument_list|(
name|absolutePath
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_if
if|if
condition|(
name|handle
operator|.
name|handle
operator|!=
name|INVALID_HANDLE_VALUE
condition|)
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|QWindowsFileSystemWatcherEngine
operator|::
name|PathInfo
argument_list|>
modifier|&
name|h
init|=
name|thread
operator|->
name|pathInfoForHandle
index|[
name|handle
operator|.
name|handle
index|]
decl_stmt|;
if|if
condition|(
name|h
operator|.
name|remove
argument_list|(
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
condition|)
block|{
comment|// ###
name|files
operator|->
name|removeAll
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|directories
operator|->
name|removeAll
argument_list|(
name|path
argument_list|)
expr_stmt|;
if|if
condition|(
name|h
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// qDebug()<< "Closing handle"<< handle.handle;
name|FindCloseChangeNotification
argument_list|(
name|handle
operator|.
name|handle
argument_list|)
expr_stmt|;
comment|// This one might generate a notification
name|int
name|indexOfHandle
init|=
name|thread
operator|->
name|handles
operator|.
name|indexOf
argument_list|(
name|handle
operator|.
name|handle
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|indexOfHandle
operator|!=
operator|-
literal|1
argument_list|)
expr_stmt|;
name|thread
operator|->
name|handles
operator|.
name|remove
argument_list|(
name|indexOfHandle
argument_list|)
expr_stmt|;
name|thread
operator|->
name|handleForDir
operator|.
name|remove
argument_list|(
name|absolutePath
argument_list|)
expr_stmt|;
comment|// h is now invalid
name|it
operator|.
name|remove
argument_list|()
expr_stmt|;
if|if
condition|(
name|thread
operator|->
name|handleForDir
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// qDebug()<<"Stopping thread "<<thread;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|thread
operator|->
name|stop
argument_list|()
expr_stmt|;
name|thread
operator|->
name|wait
argument_list|()
expr_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
comment|// We can't delete the thread until the mutex locker is
comment|// out of scope
block|}
block|}
block|}
comment|// Found the file, go to next one
break|break;
block|}
end_if
begin_comment
unit|}     }
comment|// Remove all threads that we stopped
end_comment
begin_decl_stmt
name|QList
argument_list|<
name|QWindowsFileSystemWatcherEngineThread
modifier|*
argument_list|>
operator|::
name|iterator
name|jt
decl_stmt|,
name|end
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|end
operator|=
name|threads
operator|.
name|end
argument_list|()
expr_stmt|;
end_expr_stmt
begin_for
for|for
control|(
name|jt
operator|=
name|threads
operator|.
name|begin
argument_list|()
init|;
name|jt
operator|!=
name|end
condition|;
operator|++
name|jt
control|)
block|{
if|if
condition|(
operator|!
operator|(
operator|*
name|jt
operator|)
operator|->
name|isRunning
argument_list|()
condition|)
block|{
operator|delete
operator|*
name|jt
expr_stmt|;
operator|*
name|jt
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_for
begin_expr_stmt
name|threads
operator|.
name|removeAll
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|p
return|;
end_return
begin_comment
unit|}
comment|///////////
end_comment
begin_comment
comment|// QWindowsFileSystemWatcherEngineThread
end_comment
begin_comment
comment|///////////
end_comment
begin_expr_stmt
unit|QWindowsFileSystemWatcherEngineThread
DECL|function|QWindowsFileSystemWatcherEngineThread
operator|::
name|QWindowsFileSystemWatcherEngineThread
argument_list|()
operator|:
name|msg
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|HANDLE
name|h
init|=
name|CreateEvent
argument_list|(
literal|0
argument_list|,
literal|false
argument_list|,
literal|false
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|handles
operator|.
name|reserve
argument_list|(
name|MAXIMUM_WAIT_OBJECTS
argument_list|)
expr_stmt|;
name|handles
operator|.
name|append
argument_list|(
name|h
argument_list|)
expr_stmt|;
block|}
name|moveToThread
argument_list|(
name|this
argument_list|)
expr_stmt|;
end_expr_stmt
begin_destructor
unit|}   QWindowsFileSystemWatcherEngineThread
DECL|function|~QWindowsFileSystemWatcherEngineThread
operator|::
name|~
name|QWindowsFileSystemWatcherEngineThread
parameter_list|()
block|{
name|CloseHandle
argument_list|(
name|handles
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|handles
index|[
literal|0
index|]
operator|=
name|INVALID_HANDLE_VALUE
expr_stmt|;
foreach|foreach
control|(
name|HANDLE
name|h
decl|,
name|handles
control|)
block|{
if|if
condition|(
name|h
operator|==
name|INVALID_HANDLE_VALUE
condition|)
continue|continue;
name|FindCloseChangeNotification
argument_list|(
name|h
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|msgFindNextFailed
specifier|static
specifier|inline
name|QString
name|msgFindNextFailed
parameter_list|(
specifier|const
name|QHash
argument_list|<
name|QString
argument_list|,
name|QWindowsFileSystemWatcherEngine
operator|::
name|PathInfo
argument_list|>
modifier|&
name|pathInfos
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
name|QTextStream
name|str
argument_list|(
operator|&
name|result
argument_list|)
decl_stmt|;
name|str
operator|<<
literal|"QFileSystemWatcher: FindNextChangeNotification failed for"
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QWindowsFileSystemWatcherEngine
operator|::
name|PathInfo
modifier|&
name|pathInfo
decl|,
name|pathInfos
control|)
name|str
operator|<<
literal|" \""
operator|<<
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|pathInfo
operator|.
name|absolutePath
argument_list|)
operator|<<
literal|'"'
expr_stmt|;
name|str
operator|<<
literal|' '
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|run
name|void
name|QWindowsFileSystemWatcherEngineThread
operator|::
name|run
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
forever|forever
block|{
name|QVector
argument_list|<
name|HANDLE
argument_list|>
name|handlesCopy
init|=
name|handles
decl_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
comment|// qDebug()<< "QWindowsFileSystemWatcherThread"<<this<<"waiting on"<< handlesCopy.count()<< "handles";
name|DWORD
name|r
init|=
name|WaitForMultipleObjects
argument_list|(
name|handlesCopy
operator|.
name|count
argument_list|()
argument_list|,
name|handlesCopy
operator|.
name|constData
argument_list|()
argument_list|,
literal|false
argument_list|,
name|INFINITE
argument_list|)
decl_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
do|do
block|{
if|if
condition|(
name|r
operator|==
name|WAIT_OBJECT_0
condition|)
block|{
name|int
name|m
init|=
name|msg
decl_stmt|;
name|msg
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|m
operator|==
literal|'q'
condition|)
block|{
comment|// qDebug()<< "thread"<<this<<"told to quit";
return|return;
block|}
if|if
condition|(
name|m
operator|!=
literal|'@'
condition|)
block|{
name|qDebug
argument_list|(
literal|"QWindowsFileSystemWatcherEngine: unknown message '%c' send to thread"
argument_list|,
name|char
argument_list|(
name|m
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
elseif|else
if|if
condition|(
name|r
operator|>
name|WAIT_OBJECT_0
operator|&&
name|r
operator|<
name|WAIT_OBJECT_0
operator|+
name|uint
argument_list|(
name|handlesCopy
operator|.
name|count
argument_list|()
argument_list|)
condition|)
block|{
name|int
name|at
init|=
name|r
operator|-
name|WAIT_OBJECT_0
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|at
operator|<
name|handlesCopy
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
name|HANDLE
name|handle
init|=
name|handlesCopy
operator|.
name|at
argument_list|(
name|at
argument_list|)
decl_stmt|;
comment|// When removing a path, FindCloseChangeNotification might actually fire a notification
comment|// for some reason, so we must check if the handle exist in the handles vector
if|if
condition|(
name|handles
operator|.
name|contains
argument_list|(
name|handle
argument_list|)
condition|)
block|{
comment|// qDebug()<<"thread"<<this<<"Acknowledged handle:"<<at<<handle;
name|QHash
argument_list|<
name|QString
argument_list|,
name|QWindowsFileSystemWatcherEngine
operator|::
name|PathInfo
argument_list|>
modifier|&
name|h
init|=
name|pathInfoForHandle
index|[
name|handle
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|FindNextChangeNotification
argument_list|(
name|handle
argument_list|)
condition|)
block|{
specifier|const
name|DWORD
name|error
init|=
name|GetLastError
argument_list|()
decl_stmt|;
name|qErrnoWarning
argument_list|(
name|error
argument_list|,
literal|"%s"
argument_list|,
name|qPrintable
argument_list|(
name|msgFindNextFailed
argument_list|(
name|h
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QMutableHashIterator
argument_list|<
name|QString
argument_list|,
name|QWindowsFileSystemWatcherEngine
operator|::
name|PathInfo
argument_list|>
name|it
argument_list|(
name|h
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
name|QHash
argument_list|<
name|QString
argument_list|,
name|QWindowsFileSystemWatcherEngine
operator|::
name|PathInfo
argument_list|>
operator|::
name|iterator
name|x
init|=
name|it
operator|.
name|next
argument_list|()
decl_stmt|;
name|QString
name|absolutePath
init|=
name|x
operator|.
name|value
argument_list|()
operator|.
name|absolutePath
decl_stmt|;
name|QFileInfo
name|fileInfo
argument_list|(
name|x
operator|.
name|value
argument_list|()
operator|.
name|path
argument_list|)
decl_stmt|;
comment|// qDebug()<< "checking"<< x.key();
if|if
condition|(
operator|!
name|fileInfo
operator|.
name|exists
argument_list|()
condition|)
block|{
comment|// qDebug()<< x.key()<< "removed!";
if|if
condition|(
name|x
operator|.
name|value
argument_list|()
operator|.
name|isDir
condition|)
emit|emit
name|directoryChanged
argument_list|(
name|x
operator|.
name|value
argument_list|()
operator|.
name|path
argument_list|,
literal|true
argument_list|)
emit|;
else|else
emit|emit
name|fileChanged
argument_list|(
name|x
operator|.
name|value
argument_list|()
operator|.
name|path
argument_list|,
literal|true
argument_list|)
emit|;
name|h
operator|.
name|erase
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// close the notification handle if the directory has been removed
if|if
condition|(
name|h
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// qDebug()<< "Thread closing handle"<< handle;
name|FindCloseChangeNotification
argument_list|(
name|handle
argument_list|)
expr_stmt|;
comment|// This one might generate a notification
name|int
name|indexOfHandle
init|=
name|handles
operator|.
name|indexOf
argument_list|(
name|handle
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|indexOfHandle
operator|!=
operator|-
literal|1
argument_list|)
expr_stmt|;
name|handles
operator|.
name|remove
argument_list|(
name|indexOfHandle
argument_list|)
expr_stmt|;
name|handleForDir
operator|.
name|remove
argument_list|(
name|absolutePath
argument_list|)
expr_stmt|;
comment|// h is now invalid
block|}
block|}
elseif|else
if|if
condition|(
name|x
operator|.
name|value
argument_list|()
operator|.
name|isDir
condition|)
block|{
comment|// qDebug()<< x.key()<< "directory changed!";
emit|emit
name|directoryChanged
argument_list|(
name|x
operator|.
name|value
argument_list|()
operator|.
name|path
argument_list|,
literal|false
argument_list|)
emit|;
name|x
operator|.
name|value
argument_list|()
operator|=
name|fileInfo
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|x
operator|.
name|value
argument_list|()
operator|!=
name|fileInfo
condition|)
block|{
comment|// qDebug()<< x.key()<< "file changed!";
emit|emit
name|fileChanged
argument_list|(
name|x
operator|.
name|value
argument_list|()
operator|.
name|path
argument_list|,
literal|false
argument_list|)
emit|;
name|x
operator|.
name|value
argument_list|()
operator|=
name|fileInfo
expr_stmt|;
block|}
block|}
block|}
block|}
else|else
block|{
comment|// qErrnoWarning("QFileSystemWatcher: error while waiting for change notification");
break|break;
comment|// avoid endless loop
block|}
name|handlesCopy
operator|=
name|handles
expr_stmt|;
name|r
operator|=
name|WaitForMultipleObjects
argument_list|(
name|handlesCopy
operator|.
name|count
argument_list|()
argument_list|,
name|handlesCopy
operator|.
name|constData
argument_list|()
argument_list|,
literal|false
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|r
operator|!=
name|WAIT_TIMEOUT
condition|)
do|;
block|}
block|}
end_function
begin_function
DECL|function|stop
name|void
name|QWindowsFileSystemWatcherEngineThread
operator|::
name|stop
parameter_list|()
block|{
name|msg
operator|=
literal|'q'
expr_stmt|;
name|SetEvent
argument_list|(
name|handles
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wakeup
name|void
name|QWindowsFileSystemWatcherEngineThread
operator|::
name|wakeup
parameter_list|()
block|{
name|msg
operator|=
literal|'@'
expr_stmt|;
name|SetEvent
argument_list|(
name|handles
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FILESYSTEMWATCHER
end_comment
end_unit
