begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qprocess.h"
end_include
begin_include
include|#
directive|include
file|"qprocess_p.h"
end_include
begin_include
include|#
directive|include
file|"qwindowspipewriter_p.h"
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
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_include
include|#
directive|include
file|<qwineventnotifier.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<private/qthread_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
comment|//#define QPROCESS_DEBUG
DECL|function|destroyPipe
name|void
name|QProcessPrivate
operator|::
name|destroyPipe
parameter_list|(
name|Q_PIPE
name|pipe
index|[
literal|2
index|]
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|pipe
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|closeChannel
name|void
name|QProcessPrivate
operator|::
name|closeChannel
parameter_list|(
name|Channel
modifier|*
name|channel
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|channel
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qt_create_commandline
specifier|static
name|QString
name|qt_create_commandline
parameter_list|(
specifier|const
name|QString
modifier|&
name|program
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|arguments
parameter_list|)
block|{
name|QString
name|args
decl_stmt|;
if|if
condition|(
operator|!
name|program
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|programName
init|=
name|program
decl_stmt|;
if|if
condition|(
operator|!
name|programName
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\"'
argument_list|)
argument_list|)
operator|&&
operator|!
name|programName
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\"'
argument_list|)
argument_list|)
operator|&&
name|programName
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|)
condition|)
name|programName
operator|=
name|QLatin1Char
argument_list|(
literal|'\"'
argument_list|)
operator|+
name|programName
operator|+
name|QLatin1Char
argument_list|(
literal|'\"'
argument_list|)
expr_stmt|;
name|programName
operator|.
name|replace
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|,
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
expr_stmt|;
comment|// add the prgram as the first arg ... it works better
name|args
operator|=
name|programName
operator|+
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|arguments
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|tmp
init|=
name|arguments
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
comment|// Quotes are escaped and their preceding backslashes are doubled.
name|tmp
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
name|QLatin1String
argument_list|(
literal|"(\\\\*)\""
argument_list|)
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"\\1\\1\\\""
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|tmp
operator|.
name|isEmpty
argument_list|()
operator|||
name|tmp
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|)
operator|||
name|tmp
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\t'
argument_list|)
argument_list|)
condition|)
block|{
comment|// The argument must not end with a \ since this would be interpreted
comment|// as escaping the quote -- rather put the \ behind the quote: e.g.
comment|// rather use "foo"\ than "foo\"
name|int
name|i
init|=
name|tmp
operator|.
name|length
argument_list|()
decl_stmt|;
while|while
condition|(
name|i
operator|>
literal|0
operator|&&
name|tmp
operator|.
name|at
argument_list|(
name|i
operator|-
literal|1
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
condition|)
operator|--
name|i
expr_stmt|;
name|tmp
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
argument_list|)
expr_stmt|;
name|tmp
operator|.
name|prepend
argument_list|(
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|args
operator|+=
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
operator|+
name|tmp
expr_stmt|;
block|}
return|return
name|args
return|;
block|}
end_function
begin_function
DECL|function|systemEnvironment
name|QProcessEnvironment
name|QProcessEnvironment
operator|::
name|systemEnvironment
parameter_list|()
block|{
name|QProcessEnvironment
name|env
decl_stmt|;
return|return
name|env
return|;
block|}
end_function
begin_function
DECL|function|startProcess
name|void
name|QProcessPrivate
operator|::
name|startProcess
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QProcess
argument_list|)
expr_stmt|;
name|bool
name|success
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|pid
condition|)
block|{
name|CloseHandle
argument_list|(
name|pid
operator|->
name|hThread
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|pid
operator|->
name|hProcess
argument_list|)
expr_stmt|;
operator|delete
name|pid
expr_stmt|;
name|pid
operator|=
literal|0
expr_stmt|;
block|}
name|pid
operator|=
operator|new
name|PROCESS_INFORMATION
expr_stmt|;
name|memset
argument_list|(
name|pid
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|PROCESS_INFORMATION
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|->
name|setProcessState
argument_list|(
name|QProcess
operator|::
name|Starting
argument_list|)
expr_stmt|;
name|QString
name|args
init|=
name|qt_create_commandline
argument_list|(
name|QString
argument_list|()
argument_list|,
name|arguments
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|nativeArguments
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|args
operator|.
name|isEmpty
argument_list|()
condition|)
name|args
operator|+=
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|args
operator|+=
name|nativeArguments
expr_stmt|;
block|}
if|#
directive|if
name|defined
name|QPROCESS_DEBUG
name|qDebug
argument_list|(
literal|"Creating process"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"   program : [%s]"
argument_list|,
name|program
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"   args : %s"
argument_list|,
name|args
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"   pass environment : %s"
argument_list|,
name|environment
operator|.
name|isEmpty
argument_list|()
condition|?
literal|"no"
else|:
literal|"yes"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QString
name|fullPathProgram
init|=
name|program
decl_stmt|;
if|if
condition|(
operator|!
name|QDir
operator|::
name|isAbsolutePath
argument_list|(
name|fullPathProgram
argument_list|)
condition|)
name|fullPathProgram
operator|=
name|QFileInfo
argument_list|(
name|fullPathProgram
argument_list|)
operator|.
name|absoluteFilePath
argument_list|()
expr_stmt|;
name|fullPathProgram
operator|.
name|replace
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|,
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
expr_stmt|;
name|success
operator|=
name|CreateProcess
argument_list|(
operator|(
name|wchar_t
operator|*
operator|)
name|fullPathProgram
operator|.
name|utf16
argument_list|()
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|args
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|false
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|pid
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|success
condition|)
block|{
name|cleanup
argument_list|()
expr_stmt|;
name|processError
operator|=
name|QProcess
operator|::
name|FailedToStart
expr_stmt|;
emit|emit
name|q
operator|->
name|error
argument_list|(
name|processError
argument_list|)
emit|;
name|q
operator|->
name|setProcessState
argument_list|(
name|QProcess
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
return|return;
block|}
name|q
operator|->
name|setProcessState
argument_list|(
name|QProcess
operator|::
name|Running
argument_list|)
expr_stmt|;
comment|// User can call kill()/terminate() from the stateChanged() slot
comment|// so check before proceeding
if|if
condition|(
operator|!
name|pid
condition|)
return|return;
if|if
condition|(
name|threadData
operator|->
name|hasEventDispatcher
argument_list|()
condition|)
block|{
name|processFinishedNotifier
operator|=
operator|new
name|QWinEventNotifier
argument_list|(
name|pid
operator|->
name|hProcess
argument_list|,
name|q
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|processFinishedNotifier
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|HANDLE
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_processDied
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|processFinishedNotifier
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
comment|// give the process a chance to start ...
name|Sleep
argument_list|(
name|SLEEPMIN
operator|*
literal|2
argument_list|)
expr_stmt|;
name|_q_startupNotification
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|processStarted
name|bool
name|QProcessPrivate
operator|::
name|processStarted
parameter_list|()
block|{
return|return
name|processState
operator|==
name|QProcess
operator|::
name|Running
return|;
block|}
end_function
begin_function
DECL|function|bytesAvailableInChannel
name|qint64
name|QProcessPrivate
operator|::
name|bytesAvailableInChannel
parameter_list|(
specifier|const
name|Channel
modifier|*
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|readFromChannel
name|qint64
name|QProcessPrivate
operator|::
name|readFromChannel
parameter_list|(
specifier|const
name|Channel
modifier|*
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|qt_terminateApp
specifier|static
name|BOOL
name|QT_WIN_CALLBACK
name|qt_terminateApp
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|LPARAM
name|procId
parameter_list|)
block|{
name|DWORD
name|currentProcId
init|=
literal|0
decl_stmt|;
name|GetWindowThreadProcessId
argument_list|(
name|hwnd
argument_list|,
operator|&
name|currentProcId
argument_list|)
expr_stmt|;
if|if
condition|(
name|currentProcId
operator|==
operator|(
name|DWORD
operator|)
name|procId
condition|)
name|PostMessage
argument_list|(
name|hwnd
argument_list|,
name|WM_CLOSE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function
begin_function
DECL|function|terminateProcess
name|void
name|QProcessPrivate
operator|::
name|terminateProcess
parameter_list|()
block|{
if|if
condition|(
name|pid
condition|)
block|{
name|EnumWindows
argument_list|(
name|qt_terminateApp
argument_list|,
operator|(
name|LPARAM
operator|)
name|pid
operator|->
name|dwProcessId
argument_list|)
expr_stmt|;
name|PostThreadMessage
argument_list|(
name|pid
operator|->
name|dwThreadId
argument_list|,
name|WM_CLOSE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|killProcess
name|void
name|QProcessPrivate
operator|::
name|killProcess
parameter_list|()
block|{
if|if
condition|(
name|pid
condition|)
name|TerminateProcess
argument_list|(
name|pid
operator|->
name|hProcess
argument_list|,
literal|0xf291
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForStarted
name|bool
name|QProcessPrivate
operator|::
name|waitForStarted
parameter_list|(
name|int
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QProcess
argument_list|)
expr_stmt|;
if|if
condition|(
name|processStarted
argument_list|()
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|processError
operator|==
name|QProcess
operator|::
name|FailedToStart
condition|)
return|return
literal|false
return|;
name|processError
operator|=
name|QProcess
operator|::
name|Timedout
expr_stmt|;
name|q
operator|->
name|setErrorString
argument_list|(
name|QProcess
operator|::
name|tr
argument_list|(
literal|"Process operation timed out"
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|drainOutputPipes
name|bool
name|QProcessPrivate
operator|::
name|drainOutputPipes
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|waitForReadyRead
name|bool
name|QProcessPrivate
operator|::
name|waitForReadyRead
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|waitForBytesWritten
name|bool
name|QProcessPrivate
operator|::
name|waitForBytesWritten
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|waitForFinished
name|bool
name|QProcessPrivate
operator|::
name|waitForFinished
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QProcess
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QPROCESS_DEBUG
name|qDebug
argument_list|(
literal|"QProcessPrivate::waitForFinished(%d)"
argument_list|,
name|msecs
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QIncrementalSleepTimer
name|timer
argument_list|(
name|msecs
argument_list|)
decl_stmt|;
forever|forever
block|{
if|if
condition|(
operator|!
name|pid
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|WaitForSingleObject
argument_list|(
name|pid
operator|->
name|hProcess
argument_list|,
name|timer
operator|.
name|nextSleepTime
argument_list|()
argument_list|)
operator|==
name|WAIT_OBJECT_0
condition|)
block|{
name|_q_processDied
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
name|timer
operator|.
name|hasTimedOut
argument_list|()
condition|)
break|break;
block|}
name|processError
operator|=
name|QProcess
operator|::
name|Timedout
expr_stmt|;
name|q
operator|->
name|setErrorString
argument_list|(
name|QProcess
operator|::
name|tr
argument_list|(
literal|"Process operation timed out"
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|findExitCode
name|void
name|QProcessPrivate
operator|::
name|findExitCode
parameter_list|()
block|{
name|DWORD
name|theExitCode
decl_stmt|;
if|if
condition|(
name|GetExitCodeProcess
argument_list|(
name|pid
operator|->
name|hProcess
argument_list|,
operator|&
name|theExitCode
argument_list|)
condition|)
block|{
name|exitCode
operator|=
name|theExitCode
expr_stmt|;
comment|//### for now we assume a crash if exit code is less than -1 or the magic number
name|crashed
operator|=
operator|(
name|exitCode
operator|==
literal|0xf291
operator|||
operator|(
name|int
operator|)
name|exitCode
operator|<
literal|0
operator|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|flushPipeWriter
name|void
name|QProcessPrivate
operator|::
name|flushPipeWriter
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|pipeWriterBytesToWrite
name|qint64
name|QProcessPrivate
operator|::
name|pipeWriterBytesToWrite
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|writeToStdin
name|qint64
name|QProcessPrivate
operator|::
name|writeToStdin
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|maxlen
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|waitForWrite
name|bool
name|QProcessPrivate
operator|::
name|waitForWrite
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|msecs
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|_q_notified
name|void
name|QProcessPrivate
operator|::
name|_q_notified
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|startDetached
name|bool
name|QProcessPrivate
operator|::
name|startDetached
parameter_list|(
specifier|const
name|QString
modifier|&
name|program
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|arguments
parameter_list|,
specifier|const
name|QString
modifier|&
name|workingDir
parameter_list|,
name|qint64
modifier|*
name|pid
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|workingDir
argument_list|)
expr_stmt|;
name|QString
name|args
init|=
name|qt_create_commandline
argument_list|(
name|QString
argument_list|()
argument_list|,
name|arguments
argument_list|)
decl_stmt|;
name|bool
name|success
init|=
literal|false
decl_stmt|;
name|PROCESS_INFORMATION
name|pinfo
decl_stmt|;
name|QString
name|fullPathProgram
init|=
name|program
decl_stmt|;
if|if
condition|(
operator|!
name|QDir
operator|::
name|isAbsolutePath
argument_list|(
name|fullPathProgram
argument_list|)
condition|)
name|fullPathProgram
operator|.
name|prepend
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|fullPathProgram
operator|.
name|replace
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|,
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
expr_stmt|;
name|success
operator|=
name|CreateProcess
argument_list|(
operator|(
name|wchar_t
operator|*
operator|)
name|fullPathProgram
operator|.
name|utf16
argument_list|()
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|args
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|false
argument_list|,
name|CREATE_NEW_CONSOLE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|pinfo
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
condition|)
block|{
name|CloseHandle
argument_list|(
name|pinfo
operator|.
name|hThread
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|pinfo
operator|.
name|hProcess
argument_list|)
expr_stmt|;
if|if
condition|(
name|pid
condition|)
operator|*
name|pid
operator|=
name|pinfo
operator|.
name|dwProcessId
expr_stmt|;
block|}
return|return
name|success
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
comment|// QT_NO_PROCESS
end_comment
end_unit
