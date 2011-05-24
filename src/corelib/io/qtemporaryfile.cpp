begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtemporaryfile.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEMPORARYFILE
end_ifndef
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qabstractfileengine.h"
end_include
begin_include
include|#
directive|include
file|"private/qfile_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qabstractfileengine_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qfsfileengine_p.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_include
include|#
directive|include
file|<ctype.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
end_if
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_comment
comment|// overrides QT_OPEN
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_BUILD_CORE_LIB
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*  * Copyright (c) 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
comment|/*!     \internal      Generates a unique file path and returns a native handle to the open file.     \a path is used as a template when generating unique paths,     \a placeholderStart and \a placeholderEnd delimit the sub-string that will     be randomized.      Returns an open handle to the newly created file if successful, an invalid     handle otherwise. In both cases, the string in \a path will be changed and     contain the generated path name. */
DECL|function|createFileFromTemplate
specifier|static
name|int
name|createFileFromTemplate
parameter_list|(
name|char
modifier|*
specifier|const
name|path
parameter_list|,
name|char
modifier|*
specifier|const
name|placeholderStart
parameter_list|,
name|char
modifier|*
specifier|const
name|placeholderEnd
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|placeholderEnd
operator|>
name|placeholderStart
argument_list|)
expr_stmt|;
comment|// Initialize placeholder with random chars + PID.
block|{
name|char
modifier|*
name|rIter
init|=
name|placeholderEnd
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_BUILD_CORE_LIB
argument_list|)
name|qint64
name|pid
init|=
name|QCoreApplication
operator|::
name|applicationPid
argument_list|()
decl_stmt|;
do|do
block|{
operator|*
operator|--
name|rIter
operator|=
operator|(
name|pid
operator|%
literal|10
operator|)
operator|+
literal|'0'
expr_stmt|;
name|pid
operator|/=
literal|10
expr_stmt|;
block|}
do|while
condition|(
name|rIter
operator|!=
name|placeholderStart
operator|&&
name|pid
operator|!=
literal|0
condition|)
do|;
endif|#
directive|endif
while|while
condition|(
name|rIter
operator|!=
name|placeholderStart
condition|)
block|{
name|char
name|ch
init|=
name|char
argument_list|(
operator|(
name|qrand
argument_list|()
operator|&
literal|0xffff
operator|)
operator|%
operator|(
literal|26
operator|+
literal|26
operator|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|ch
operator|<
literal|26
condition|)
operator|*
operator|--
name|rIter
operator|=
name|ch
operator|+
literal|'A'
expr_stmt|;
else|else
operator|*
operator|--
name|rIter
operator|=
name|ch
operator|-
literal|26
operator|+
literal|'a'
expr_stmt|;
block|}
block|}
for|for
control|(
init|;
condition|;
control|)
block|{
comment|// Atomically create file and obtain handle
ifndef|#
directive|ifndef
name|Q_OS_WIN
block|{
name|int
name|fd
init|=
name|QT_OPEN
argument_list|(
name|path
argument_list|,
name|QT_OPEN_CREAT
operator||
name|O_EXCL
operator||
name|QT_OPEN_RDWR
operator||
name|QT_OPEN_LARGEFILE
argument_list|,
literal|0600
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|!=
operator|-
literal|1
condition|)
return|return
name|fd
return|;
if|if
condition|(
name|errno
operator|!=
name|EEXIST
condition|)
return|return
operator|-
literal|1
return|;
block|}
else|#
directive|else
if|if
condition|(
operator|!
name|QFileInfo
argument_list|(
name|QLatin1String
argument_list|(
name|path
argument_list|)
argument_list|)
operator|.
name|exists
argument_list|()
condition|)
return|return
literal|1
return|;
endif|#
directive|endif
comment|/* tricky little algorwwithm for backward compatibility */
for|for
control|(
name|char
modifier|*
name|iter
init|=
name|placeholderStart
init|;
condition|;
control|)
block|{
comment|// Character progression: [0-9] => 'a' ... 'z' => 'A' .. 'Z'
comment|// String progression: "ZZaiC" => "aabiC"
if|if
condition|(
operator|*
name|iter
operator|==
literal|'Z'
condition|)
block|{
operator|*
name|iter
operator|++
operator|=
literal|'a'
expr_stmt|;
if|if
condition|(
name|iter
operator|==
name|placeholderEnd
condition|)
return|return
operator|-
literal|1
return|;
block|}
else|else
block|{
if|if
condition|(
name|isdigit
argument_list|(
operator|*
name|iter
argument_list|)
condition|)
operator|*
name|iter
operator|=
literal|'a'
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|iter
operator|==
literal|'z'
condition|)
comment|/* inc from z to A */
operator|*
name|iter
operator|=
literal|'A'
expr_stmt|;
else|else
block|{
operator|++
operator|*
name|iter
expr_stmt|;
block|}
break|break;
block|}
block|}
block|}
comment|/*NOTREACHED*/
block|}
end_function
begin_comment
comment|//************* QTemporaryFileEngine
end_comment
begin_class
DECL|class|QTemporaryFileEngine
class|class
name|QTemporaryFileEngine
super|:
specifier|public
name|QFSFileEngine
block|{
name|Q_DECLARE_PRIVATE
parameter_list|(
name|QFSFileEngine
parameter_list|)
specifier|public
private|:
DECL|function|QTemporaryFileEngine
name|QTemporaryFileEngine
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|,
name|bool
name|fileIsTemplate
init|=
literal|true
parameter_list|)
member_init_list|:
name|QFSFileEngine
argument_list|()
member_init_list|,
name|filePathIsTemplate
argument_list|(
name|fileIsTemplate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QFSFileEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|fileEntry
operator|=
name|QFileSystemEntry
argument_list|(
name|file
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|filePathIsTemplate
condition|)
name|QFSFileEngine
operator|::
name|setFileName
argument_list|(
name|file
argument_list|)
expr_stmt|;
block|}
name|~
name|QTemporaryFileEngine
parameter_list|()
destructor_decl|;
name|bool
name|isReallyOpen
parameter_list|()
function_decl|;
name|void
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
function_decl|;
name|void
name|setFileTemplate
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileTemplate
parameter_list|)
function_decl|;
name|bool
name|open
parameter_list|(
name|QIODevice
operator|::
name|OpenMode
name|flags
parameter_list|)
function_decl|;
name|bool
name|remove
parameter_list|()
function_decl|;
name|bool
name|rename
parameter_list|(
specifier|const
name|QString
modifier|&
name|newName
parameter_list|)
function_decl|;
name|bool
name|close
parameter_list|()
function_decl|;
DECL|member|filePathIsTemplate
name|bool
name|filePathIsTemplate
decl_stmt|;
block|}
class|;
end_class
begin_destructor
DECL|function|~QTemporaryFileEngine
name|QTemporaryFileEngine
operator|::
name|~
name|QTemporaryFileEngine
parameter_list|()
block|{
name|QFSFileEngine
operator|::
name|close
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|isReallyOpen
name|bool
name|QTemporaryFileEngine
operator|::
name|isReallyOpen
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QFSFileEngine
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
operator|(
literal|0
operator|==
name|d
operator|->
name|fh
operator|)
operator|&&
operator|(
operator|-
literal|1
operator|==
name|d
operator|->
name|fd
operator|)
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
operator|(
literal|0
operator|==
name|d
operator|->
name|symbianFile
operator|.
name|SubSessionHandle
argument_list|()
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|Q_OS_WIN
operator|&&
operator|(
name|INVALID_HANDLE_VALUE
operator|==
name|d
operator|->
name|fileHandle
operator|)
endif|#
directive|endif
operator|)
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|setFileName
name|void
name|QTemporaryFileEngine
operator|::
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
block|{
comment|// Really close the file, so we don't leak
name|QFSFileEngine
operator|::
name|close
argument_list|()
expr_stmt|;
name|QFSFileEngine
operator|::
name|setFileName
argument_list|(
name|file
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setFileTemplate
name|void
name|QTemporaryFileEngine
operator|::
name|setFileTemplate
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileTemplate
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFSFileEngine
argument_list|)
expr_stmt|;
if|if
condition|(
name|filePathIsTemplate
condition|)
name|d
operator|->
name|fileEntry
operator|=
name|QFileSystemEntry
argument_list|(
name|fileTemplate
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|open
name|bool
name|QTemporaryFileEngine
operator|::
name|open
parameter_list|(
name|QIODevice
operator|::
name|OpenMode
name|openMode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFSFileEngine
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|isReallyOpen
argument_list|()
argument_list|)
expr_stmt|;
name|openMode
operator||=
name|QIODevice
operator|::
name|ReadWrite
expr_stmt|;
if|if
condition|(
operator|!
name|filePathIsTemplate
condition|)
return|return
name|QFSFileEngine
operator|::
name|open
argument_list|(
name|openMode
argument_list|)
return|;
name|QString
name|qfilename
init|=
name|d
operator|->
name|fileEntry
operator|.
name|filePath
argument_list|()
decl_stmt|;
comment|// Find placeholder string.
name|uint
name|phPos
init|=
name|qfilename
operator|.
name|length
argument_list|()
decl_stmt|;
name|uint
name|phLength
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|phPos
operator|!=
literal|0
condition|)
block|{
operator|--
name|phPos
expr_stmt|;
if|if
condition|(
name|qfilename
index|[
name|phPos
index|]
operator|==
name|QLatin1Char
argument_list|(
literal|'X'
argument_list|)
condition|)
block|{
operator|++
name|phLength
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|qfilename
index|[
name|phPos
index|]
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|||
name|phLength
operator|>=
literal|6
condition|)
block|{
operator|++
name|phPos
expr_stmt|;
break|break;
block|}
name|phLength
operator|=
literal|0
expr_stmt|;
block|}
name|QStringRef
name|prefix
decl_stmt|,
name|suffix
decl_stmt|;
if|if
condition|(
name|phLength
operator|<
literal|6
condition|)
block|{
name|qfilename
operator|+=
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
expr_stmt|;
name|prefix
operator|=
name|QStringRef
argument_list|(
operator|&
name|qfilename
argument_list|)
expr_stmt|;
name|phLength
operator|=
literal|6
expr_stmt|;
block|}
else|else
block|{
name|prefix
operator|=
name|qfilename
operator|.
name|leftRef
argument_list|(
name|phPos
argument_list|)
expr_stmt|;
name|suffix
operator|=
name|qfilename
operator|.
name|midRef
argument_list|(
name|phPos
operator|+
name|phLength
argument_list|)
expr_stmt|;
block|}
name|QByteArray
name|filename
init|=
name|prefix
operator|.
name|toLocal8Bit
argument_list|()
decl_stmt|;
name|phPos
operator|=
name|filename
operator|.
name|length
argument_list|()
expr_stmt|;
if|if
condition|(
name|suffix
operator|.
name|isEmpty
argument_list|()
condition|)
name|filename
operator|.
name|resize
argument_list|(
name|phPos
operator|+
name|phLength
argument_list|)
expr_stmt|;
else|else
name|filename
operator|.
name|insert
argument_list|(
name|phPos
operator|+
name|phLength
argument_list|,
name|suffix
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
expr_stmt|;
name|char
modifier|*
name|path
init|=
name|filename
operator|.
name|data
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WIN
name|int
name|fd
init|=
name|createFileFromTemplate
argument_list|(
name|path
argument_list|,
name|path
operator|+
name|phPos
argument_list|,
name|path
operator|+
name|phPos
operator|+
name|phLength
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|!=
operator|-
literal|1
condition|)
block|{
comment|// First open the fd as an external file descriptor to
comment|// initialize the engine properly.
if|if
condition|(
name|QFSFileEngine
operator|::
name|open
argument_list|(
name|openMode
argument_list|,
name|fd
argument_list|)
condition|)
block|{
comment|// Allow the engine to close the handle even if it's "external".
name|d
operator|->
name|closeFileHandle
operator|=
literal|true
expr_stmt|;
comment|// Restore the file names (open() resets them).
name|d
operator|->
name|fileEntry
operator|=
name|QFileSystemEntry
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|path
argument_list|,
name|filename
operator|.
name|length
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//note that filename is NOT a native path
name|filePathIsTemplate
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
name|QT_CLOSE
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
name|setError
argument_list|(
name|errno
operator|==
name|EMFILE
condition|?
name|QFile
operator|::
name|ResourceError
else|:
name|QFile
operator|::
name|OpenError
argument_list|,
name|qt_error_string
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
else|#
directive|else
if|if
condition|(
name|createFileFromTemplate
argument_list|(
name|path
argument_list|,
name|path
operator|+
name|phPos
argument_list|,
name|path
operator|+
name|phPos
operator|+
name|phLength
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
return|return
literal|false
return|;
block|}
name|QString
name|template_
init|=
name|d
operator|->
name|fileEntry
operator|.
name|filePath
argument_list|()
decl_stmt|;
name|d
operator|->
name|fileEntry
operator|=
name|QFileSystemEntry
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|path
argument_list|,
name|filename
operator|.
name|length
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|QFSFileEngine
operator|::
name|open
argument_list|(
name|openMode
argument_list|)
condition|)
block|{
name|filePathIsTemplate
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
name|d
operator|->
name|fileEntry
operator|=
name|QFileSystemEntry
argument_list|(
name|template_
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|remove
name|bool
name|QTemporaryFileEngine
operator|::
name|remove
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QFSFileEngine
argument_list|)
expr_stmt|;
comment|// Since the QTemporaryFileEngine::close() does not really close the file,
comment|// we must explicitly call QFSFileEngine::close() before we remove it.
name|QFSFileEngine
operator|::
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
name|QFSFileEngine
operator|::
name|remove
argument_list|()
condition|)
block|{
name|d
operator|->
name|fileEntry
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|rename
name|bool
name|QTemporaryFileEngine
operator|::
name|rename
parameter_list|(
specifier|const
name|QString
modifier|&
name|newName
parameter_list|)
block|{
name|QFSFileEngine
operator|::
name|close
argument_list|()
expr_stmt|;
return|return
name|QFSFileEngine
operator|::
name|rename
argument_list|(
name|newName
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|close
name|bool
name|QTemporaryFileEngine
operator|::
name|close
parameter_list|()
block|{
comment|// Don't close the file, just seek to the front.
name|seek
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setError
argument_list|(
name|QFile
operator|::
name|UnspecifiedError
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//************* QTemporaryFilePrivate
end_comment
begin_class
DECL|class|QTemporaryFilePrivate
class|class
name|QTemporaryFilePrivate
super|:
specifier|public
name|QFilePrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QTemporaryFile
parameter_list|)
specifier|protected
private|:
name|QTemporaryFilePrivate
parameter_list|()
constructor_decl|;
name|~
name|QTemporaryFilePrivate
parameter_list|()
destructor_decl|;
DECL|member|autoRemove
name|bool
name|autoRemove
decl_stmt|;
DECL|member|templateName
name|QString
name|templateName
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QTemporaryFilePrivate
name|QTemporaryFilePrivate
operator|::
name|QTemporaryFilePrivate
parameter_list|()
member_init_list|:
name|autoRemove
argument_list|(
literal|true
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QTemporaryFilePrivate
name|QTemporaryFilePrivate
operator|::
name|~
name|QTemporaryFilePrivate
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|//************* QTemporaryFile
end_comment
begin_comment
comment|/*!     \class QTemporaryFile     \reentrant     \brief The QTemporaryFile class is an I/O device that operates on temporary files.      \ingroup io       QTemporaryFile is used to create unique temporary files safely.     The file itself is created by calling open(). The name of the     temporary file is guaranteed to be unique (i.e., you are     guaranteed to not overwrite an existing file), and the file will     subsequently be removed upon destruction of the QTemporaryFile     object. This is an important technique that avoids data     corruption for applications that store data in temporary files.     The file name is either auto-generated, or created based on a     template, which is passed to QTemporaryFile's constructor.      Example:      \snippet doc/src/snippets/code/src_corelib_io_qtemporaryfile.cpp 0      Reopening a QTemporaryFile after calling close() is safe. For as long as     the QTemporaryFile object itself is not destroyed, the unique temporary     file will exist and be kept open internally by QTemporaryFile.      The file name of the temporary file can be found by calling fileName().     Note that this is only defined after the file is first opened; the function     returns an empty string before this.      A temporary file will have some static part of the name and some     part that is calculated to be unique. The default filename \c     qt_temp will be placed into the temporary path as returned by     QDir::tempPath(). If you specify your own filename, a relative     file path will not be placed in the temporary directory by     default, but be relative to the current working directory.      Specified filenames can contain the following template \c XXXXXX     (six upper case "X" characters), which will be replaced by the     auto-generated portion of the filename. Note that the template is     case sensitive. If the template is not present in the filename,     QTemporaryFile appends the generated part to the filename given.      \sa QDir::tempPath(), QFile */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_QOBJECT
end_ifdef
begin_constructor
DECL|function|QTemporaryFile
name|QTemporaryFile
operator|::
name|QTemporaryFile
parameter_list|()
member_init_list|:
name|QFile
argument_list|(
operator|*
operator|new
name|QTemporaryFilePrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QTemporaryFile
argument_list|)
expr_stmt|;
name|d
operator|->
name|templateName
operator|=
name|QDir
operator|::
name|tempPath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/qt_temp.XXXXXX"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QTemporaryFile
name|QTemporaryFile
operator|::
name|QTemporaryFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|templateName
parameter_list|)
member_init_list|:
name|QFile
argument_list|(
operator|*
operator|new
name|QTemporaryFilePrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QTemporaryFile
argument_list|)
expr_stmt|;
name|d
operator|->
name|templateName
operator|=
name|templateName
expr_stmt|;
block|}
end_constructor
begin_else
else|#
directive|else
end_else
begin_comment
comment|/*!     Constructs a QTemporaryFile in QDir::tempPath(), using the file template     "qt_temp.XXXXXX". The file is stored in the system's temporary directory.      \sa setFileTemplate(), QDir::tempPath() */
end_comment
begin_constructor
DECL|function|QTemporaryFile
name|QTemporaryFile
operator|::
name|QTemporaryFile
parameter_list|()
member_init_list|:
name|QFile
argument_list|(
operator|*
operator|new
name|QTemporaryFilePrivate
argument_list|,
literal|0
argument_list|)
block|{
name|Q_D
argument_list|(
name|QTemporaryFile
argument_list|)
expr_stmt|;
name|d
operator|->
name|templateName
operator|=
name|QDir
operator|::
name|tempPath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/qt_temp.XXXXXX"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QTemporaryFile with a template filename of \a     templateName. Upon opening the temporary file this will be used to create     a unique filename.      If the \a templateName does not contain XXXXXX it will automatically be     appended and used as the dynamic portion of the filename.      If \a templateName is a relative path, the path will be relative to the     current working directory. You can use QDir::tempPath() to construct \a     templateName if you want use the system's temporary directory.      \sa open(), fileTemplate() */
end_comment
begin_constructor
DECL|function|QTemporaryFile
name|QTemporaryFile
operator|::
name|QTemporaryFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|templateName
parameter_list|)
member_init_list|:
name|QFile
argument_list|(
operator|*
operator|new
name|QTemporaryFilePrivate
argument_list|,
literal|0
argument_list|)
block|{
name|Q_D
argument_list|(
name|QTemporaryFile
argument_list|)
expr_stmt|;
name|d
operator|->
name|templateName
operator|=
name|templateName
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QTemporaryFile (with the given \a parent) in     QDir::tempPath(), using the file template "qt_temp.XXXXXX".      \sa setFileTemplate() */
end_comment
begin_constructor
DECL|function|QTemporaryFile
name|QTemporaryFile
operator|::
name|QTemporaryFile
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QFile
argument_list|(
operator|*
operator|new
name|QTemporaryFilePrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QTemporaryFile
argument_list|)
expr_stmt|;
name|d
operator|->
name|templateName
operator|=
name|QDir
operator|::
name|tempPath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/qt_temp.XXXXXX"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QTemporaryFile with a template filename of \a     templateName and the specified \a parent.     Upon opening the temporary file this will be used to     create a unique filename.      If the \a templateName does not contain XXXXXX it will automatically be     appended and used as the dynamic portion of the filename.      If \a templateName is a relative path, the path will be relative to the     current working directory. You can use QDir::tempPath() to construct \a     templateName if you want use the system's temporary directory.      \sa open(), fileTemplate() */
end_comment
begin_constructor
DECL|function|QTemporaryFile
name|QTemporaryFile
operator|::
name|QTemporaryFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|templateName
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QFile
argument_list|(
operator|*
operator|new
name|QTemporaryFilePrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QTemporaryFile
argument_list|)
expr_stmt|;
name|d
operator|->
name|templateName
operator|=
name|templateName
expr_stmt|;
block|}
end_constructor
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Destroys the temporary file object, the file is automatically     closed if necessary and if in auto remove mode it will     automatically delete the file.      \sa autoRemove() */
end_comment
begin_destructor
DECL|function|~QTemporaryFile
name|QTemporaryFile
operator|::
name|~
name|QTemporaryFile
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QTemporaryFile
argument_list|)
expr_stmt|;
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|fileName
operator|.
name|isEmpty
argument_list|()
operator|&&
name|d
operator|->
name|autoRemove
condition|)
name|remove
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!   \fn bool QTemporaryFile::open()    A QTemporaryFile will always be opened in QIODevice::ReadWrite mode,   this allows easy access to the data in the file. This function will   return true upon success and will set the fileName() to the unique   filename used.    \sa fileName() */
end_comment
begin_comment
comment|/*!    Returns true if the QTemporaryFile is in auto remove    mode. Auto-remove mode will automatically delete the filename from    disk upon destruction. This makes it very easy to create your    QTemporaryFile object on the stack, fill it with data, read from    it, and finally on function return it will automatically clean up    after itself.     Auto-remove is on by default.     \sa setAutoRemove(), remove() */
end_comment
begin_function
DECL|function|autoRemove
name|bool
name|QTemporaryFile
operator|::
name|autoRemove
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QTemporaryFile
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|autoRemove
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the QTemporaryFile into auto-remove mode if \a b is true.      Auto-remove is on by default.      \sa autoRemove(), remove() */
end_comment
begin_function
DECL|function|setAutoRemove
name|void
name|QTemporaryFile
operator|::
name|setAutoRemove
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QTemporaryFile
argument_list|)
expr_stmt|;
name|d
operator|->
name|autoRemove
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!    Returns the complete unique filename backing the QTemporaryFile    object. This string is null before the QTemporaryFile is opened,    afterwards it will contain the fileTemplate() plus    additional characters to make it unique.     \sa fileTemplate() */
end_comment
begin_function
DECL|function|fileName
name|QString
name|QTemporaryFile
operator|::
name|fileName
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QTemporaryFile
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|fileEngine
argument_list|()
operator|->
name|fileName
argument_list|(
name|QAbstractFileEngine
operator|::
name|DefaultName
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the set file template. The default file template will be   called qt_temp and be placed in QDir::tempPath().    \sa setFileTemplate() */
end_comment
begin_function
DECL|function|fileTemplate
name|QString
name|QTemporaryFile
operator|::
name|fileTemplate
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QTemporaryFile
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|templateName
return|;
block|}
end_function
begin_comment
comment|/*!    Sets the static portion of the file name to \a name. If the file    template ends in XXXXXX that will automatically be replaced with    the unique part of the filename, otherwise a filename will be    determined automatically based on the static portion specified.      If \a name contains a relative file path, the path will be relative to the     current working directory. You can use QDir::tempPath() to construct \a     name if you want use the system's temporary directory.     \sa fileTemplate() */
end_comment
begin_function
DECL|function|setFileTemplate
name|void
name|QTemporaryFile
operator|::
name|setFileTemplate
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QTemporaryFile
argument_list|)
expr_stmt|;
name|d
operator|->
name|templateName
operator|=
name|name
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|fileEngine
condition|)
cast|static_cast
argument_list|<
name|QTemporaryFileEngine
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|fileEngine
argument_list|)
operator|->
name|setFileTemplate
argument_list|(
name|name
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \fn QTemporaryFile *QTemporaryFile::createLocalFile(const QString&fileName)   \overload    Works on the given \a fileName rather than an existing QFile   object. */
end_comment
begin_comment
comment|/*!   If \a file is not on a local disk, a temporary file is created   on a local disk, \a file is copied into the temporary local file,   and a pointer to the temporary local file is returned. If \a file   is already on a local disk, a copy is not created and 0 is returned. */
end_comment
begin_function
DECL|function|createLocalFile
name|QTemporaryFile
modifier|*
name|QTemporaryFile
operator|::
name|createLocalFile
parameter_list|(
name|QFile
modifier|&
name|file
parameter_list|)
block|{
if|if
condition|(
name|QAbstractFileEngine
modifier|*
name|engine
init|=
name|file
operator|.
name|fileEngine
argument_list|()
condition|)
block|{
if|if
condition|(
name|engine
operator|->
name|fileFlags
argument_list|(
name|QAbstractFileEngine
operator|::
name|FlagsMask
argument_list|)
operator|&
name|QAbstractFileEngine
operator|::
name|LocalDiskFlag
condition|)
return|return
literal|0
return|;
comment|//local already
comment|//cache
name|bool
name|wasOpen
init|=
name|file
operator|.
name|isOpen
argument_list|()
decl_stmt|;
name|qint64
name|old_off
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|wasOpen
condition|)
name|old_off
operator|=
name|file
operator|.
name|pos
argument_list|()
expr_stmt|;
else|else
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
comment|//dump data
name|QTemporaryFile
modifier|*
name|ret
init|=
operator|new
name|QTemporaryFile
decl_stmt|;
name|ret
operator|->
name|open
argument_list|()
expr_stmt|;
name|file
operator|.
name|seek
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|char
name|buffer
index|[
literal|1024
index|]
decl_stmt|;
while|while
condition|(
literal|true
condition|)
block|{
name|qint64
name|len
init|=
name|file
operator|.
name|read
argument_list|(
name|buffer
argument_list|,
literal|1024
argument_list|)
decl_stmt|;
if|if
condition|(
name|len
operator|<
literal|1
condition|)
break|break;
name|ret
operator|->
name|write
argument_list|(
name|buffer
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
name|ret
operator|->
name|seek
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|//restore
if|if
condition|(
name|wasOpen
condition|)
name|file
operator|.
name|seek
argument_list|(
name|old_off
argument_list|)
expr_stmt|;
else|else
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
comment|//done
return|return
name|ret
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!    \internal */
end_comment
begin_function
DECL|function|fileEngine
name|QAbstractFileEngine
modifier|*
name|QTemporaryFile
operator|::
name|fileEngine
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QTemporaryFile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|fileEngine
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|d
operator|->
name|fileEngine
operator|=
operator|new
name|QTemporaryFileEngine
argument_list|(
name|d
operator|->
name|templateName
argument_list|)
expr_stmt|;
else|else
name|d
operator|->
name|fileEngine
operator|=
operator|new
name|QTemporaryFileEngine
argument_list|(
name|d
operator|->
name|fileName
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
return|return
name|d
operator|->
name|fileEngine
return|;
block|}
end_function
begin_comment
comment|/*!    \reimp      Creates a unique file name for the temporary file, and opens it.  You can     get the unique name later by calling fileName(). The file is guaranteed to     have been created by this function (i.e., it has never existed before). */
end_comment
begin_function
DECL|function|open
name|bool
name|QTemporaryFile
operator|::
name|open
parameter_list|(
name|OpenMode
name|flags
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QTemporaryFile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
cast|static_cast
argument_list|<
name|QTemporaryFileEngine
operator|*
argument_list|>
argument_list|(
name|fileEngine
argument_list|()
argument_list|)
operator|->
name|isReallyOpen
argument_list|()
condition|)
block|{
name|setOpenMode
argument_list|(
name|flags
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
if|if
condition|(
name|QFile
operator|::
name|open
argument_list|(
name|flags
argument_list|)
condition|)
block|{
name|d
operator|->
name|fileName
operator|=
name|d
operator|->
name|fileEngine
operator|->
name|fileName
argument_list|(
name|QAbstractFileEngine
operator|::
name|DefaultName
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
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
comment|// QT_NO_TEMPORARYFILE
end_comment
end_unit
