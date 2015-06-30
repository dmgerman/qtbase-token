begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPROCESS_H
end_ifndef
begin_define
DECL|macro|QPROCESS_H
define|#
directive|define
name|QPROCESS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
end_ifndef
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
end_if
begin_typedef
DECL|typedef|Q_PID
typedef|typedef
name|qint64
name|Q_PID
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_typedef
typedef|typedef
name|struct
name|_PROCESS_INFORMATION
modifier|*
name|Q_PID
typedef|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
endif|#
directive|endif
DECL|variable|QProcessPrivate
name|class
name|QProcessPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QProcessEnvironmentPrivate
name|class
name|QProcessEnvironmentPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QProcessEnvironment
block|{
name|public
label|:
name|QProcessEnvironment
argument_list|()
expr_stmt|;
name|QProcessEnvironment
argument_list|(
specifier|const
name|QProcessEnvironment
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QProcessEnvironment
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QProcessEnvironment
modifier|&
name|operator
init|=
operator|(
name|QProcessEnvironment
operator|&&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|QProcessEnvironment
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QProcessEnvironment
operator|&
name|other
operator|)
decl_stmt|;
name|void
name|swap
parameter_list|(
name|QProcessEnvironment
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QProcessEnvironment
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QProcessEnvironment
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|bool
name|contains
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|void
name|insert
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
function_decl|;
name|void
name|remove
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|QString
name|value
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|defaultValue
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|toStringList
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|keys
argument_list|()
specifier|const
expr_stmt|;
name|void
name|insert
parameter_list|(
specifier|const
name|QProcessEnvironment
modifier|&
name|e
parameter_list|)
function_decl|;
specifier|static
name|QProcessEnvironment
name|systemEnvironment
parameter_list|()
function_decl|;
name|private
label|:
name|friend
name|class
name|QProcessPrivate
decl_stmt|;
name|friend
name|class
name|QProcessEnvironmentPrivate
decl_stmt|;
name|QSharedDataPointer
operator|<
name|QProcessEnvironmentPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QProcessEnvironment
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QProcess
range|:
name|public
name|QIODevice
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|ProcessError
block|{
name|FailedToStart
block|,
comment|//### file not found, resource error
name|Crashed
block|,
name|Timedout
block|,
name|ReadError
block|,
name|WriteError
block|,
name|UnknownError
block|}
block|;
name|Q_ENUM
argument_list|(
name|ProcessError
argument_list|)
expr|enum
name|ProcessState
block|{
name|NotRunning
block|,
name|Starting
block|,
name|Running
block|}
block|;
name|Q_ENUM
argument_list|(
name|ProcessState
argument_list|)
expr|enum
name|ProcessChannel
block|{
name|StandardOutput
block|,
name|StandardError
block|}
block|;
name|Q_ENUM
argument_list|(
name|ProcessChannel
argument_list|)
expr|enum
name|ProcessChannelMode
block|{
name|SeparateChannels
block|,
name|MergedChannels
block|,
name|ForwardedChannels
block|,
name|ForwardedOutputChannel
block|,
name|ForwardedErrorChannel
block|}
block|;
name|Q_ENUM
argument_list|(
name|ProcessChannelMode
argument_list|)
expr|enum
name|InputChannelMode
block|{
name|ManagedInputChannel
block|,
name|ForwardedInputChannel
block|}
block|;
name|Q_ENUM
argument_list|(
name|InputChannelMode
argument_list|)
expr|enum
name|ExitStatus
block|{
name|NormalExit
block|,
name|CrashExit
block|}
block|;
name|Q_ENUM
argument_list|(
argument|ExitStatus
argument_list|)
name|explicit
name|QProcess
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|virtual
operator|~
name|QProcess
argument_list|()
block|;
name|void
name|start
argument_list|(
argument|const QString&program
argument_list|,
argument|const QStringList&arguments
argument_list|,
argument|OpenMode mode = ReadWrite
argument_list|)
block|;
name|void
name|start
argument_list|(
argument|const QString&command
argument_list|,
argument|OpenMode mode = ReadWrite
argument_list|)
block|;
name|void
name|start
argument_list|(
argument|OpenMode mode = ReadWrite
argument_list|)
block|;
name|bool
name|open
argument_list|(
argument|OpenMode mode = ReadWrite
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QString
name|program
argument_list|()
specifier|const
block|;
name|void
name|setProgram
argument_list|(
specifier|const
name|QString
operator|&
name|program
argument_list|)
block|;
name|QStringList
name|arguments
argument_list|()
specifier|const
block|;
name|void
name|setArguments
argument_list|(
specifier|const
name|QStringList
operator|&
name|arguments
argument_list|)
block|;
name|ProcessChannelMode
name|readChannelMode
argument_list|()
specifier|const
block|;
name|void
name|setReadChannelMode
argument_list|(
argument|ProcessChannelMode mode
argument_list|)
block|;
name|ProcessChannelMode
name|processChannelMode
argument_list|()
specifier|const
block|;
name|void
name|setProcessChannelMode
argument_list|(
argument|ProcessChannelMode mode
argument_list|)
block|;
name|InputChannelMode
name|inputChannelMode
argument_list|()
specifier|const
block|;
name|void
name|setInputChannelMode
argument_list|(
argument|InputChannelMode mode
argument_list|)
block|;
name|ProcessChannel
name|readChannel
argument_list|()
specifier|const
block|;
name|void
name|setReadChannel
argument_list|(
argument|ProcessChannel channel
argument_list|)
block|;
name|void
name|closeReadChannel
argument_list|(
argument|ProcessChannel channel
argument_list|)
block|;
name|void
name|closeWriteChannel
argument_list|()
block|;
name|void
name|setStandardInputFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|void
name|setStandardOutputFile
argument_list|(
argument|const QString&fileName
argument_list|,
argument|OpenMode mode = Truncate
argument_list|)
block|;
name|void
name|setStandardErrorFile
argument_list|(
argument|const QString&fileName
argument_list|,
argument|OpenMode mode = Truncate
argument_list|)
block|;
name|void
name|setStandardOutputProcess
argument_list|(
name|QProcess
operator|*
name|destination
argument_list|)
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|QString
name|nativeArguments
argument_list|()
specifier|const
block|;
name|void
name|setNativeArguments
argument_list|(
specifier|const
name|QString
operator|&
name|arguments
argument_list|)
block|;
endif|#
directive|endif
name|QString
name|workingDirectory
argument_list|()
specifier|const
block|;
name|void
name|setWorkingDirectory
argument_list|(
specifier|const
name|QString
operator|&
name|dir
argument_list|)
block|;
name|void
name|setEnvironment
argument_list|(
specifier|const
name|QStringList
operator|&
name|environment
argument_list|)
block|;
name|QStringList
name|environment
argument_list|()
specifier|const
block|;
name|void
name|setProcessEnvironment
argument_list|(
specifier|const
name|QProcessEnvironment
operator|&
name|environment
argument_list|)
block|;
name|QProcessEnvironment
name|processEnvironment
argument_list|()
specifier|const
block|;
name|QProcess
operator|::
name|ProcessError
name|error
argument_list|()
specifier|const
block|;
name|QProcess
operator|::
name|ProcessState
name|state
argument_list|()
specifier|const
block|;
comment|// #### Qt 5: Q_PID is a pointer on Windows and a value on Unix
name|Q_PID
name|pid
argument_list|()
specifier|const
block|;
name|qint64
name|processId
argument_list|()
specifier|const
block|;
name|bool
name|waitForStarted
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|bool
name|waitForReadyRead
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|waitForBytesWritten
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|waitForFinished
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|QByteArray
name|readAllStandardOutput
argument_list|()
block|;
name|QByteArray
name|readAllStandardError
argument_list|()
block|;
name|int
name|exitCode
argument_list|()
specifier|const
block|;
name|QProcess
operator|::
name|ExitStatus
name|exitStatus
argument_list|()
specifier|const
block|;
comment|// QIODevice
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|qint64
name|bytesToWrite
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isSequential
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|canReadLine
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|close
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|atEnd
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|static
name|int
name|execute
argument_list|(
specifier|const
name|QString
operator|&
name|program
argument_list|,
specifier|const
name|QStringList
operator|&
name|arguments
argument_list|)
block|;
specifier|static
name|int
name|execute
argument_list|(
specifier|const
name|QString
operator|&
name|command
argument_list|)
block|;
specifier|static
name|bool
name|startDetached
argument_list|(
specifier|const
name|QString
operator|&
name|program
argument_list|,
specifier|const
name|QStringList
operator|&
name|arguments
argument_list|,
specifier|const
name|QString
operator|&
name|workingDirectory
if|#
directive|if
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
operator|=
name|QString
argument_list|()
endif|#
directive|endif
argument_list|,
name|qint64
operator|*
name|pid
operator|=
name|Q_NULLPTR
argument_list|)
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
specifier|static
name|bool
name|startDetached
argument_list|(
specifier|const
name|QString
operator|&
name|program
argument_list|,
specifier|const
name|QStringList
operator|&
name|arguments
argument_list|)
block|;
comment|// ### Qt6: merge overloads
endif|#
directive|endif
specifier|static
name|bool
name|startDetached
argument_list|(
specifier|const
name|QString
operator|&
name|command
argument_list|)
block|;
specifier|static
name|QStringList
name|systemEnvironment
argument_list|()
block|;
specifier|static
name|QString
name|nullDevice
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|terminate
argument_list|()
block|;
name|void
name|kill
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|started
argument_list|(
name|QPrivateSignal
argument_list|)
block|;
name|void
name|finished
argument_list|(
argument|int exitCode
argument_list|)
block|;
comment|// ### Qt 6: merge the two signals with a default value
name|void
name|finished
argument_list|(
argument|int exitCode
argument_list|,
argument|QProcess::ExitStatus exitStatus
argument_list|)
block|;
name|void
name|error
argument_list|(
argument|QProcess::ProcessError error
argument_list|)
block|;
name|void
name|stateChanged
argument_list|(
argument|QProcess::ProcessState state
argument_list|,
argument|QPrivateSignal
argument_list|)
block|;
name|void
name|readyReadStandardOutput
argument_list|(
name|QPrivateSignal
argument_list|)
block|;
name|void
name|readyReadStandardError
argument_list|(
name|QPrivateSignal
argument_list|)
block|;
name|protected
operator|:
name|void
name|setProcessState
argument_list|(
argument|ProcessState state
argument_list|)
block|;
name|virtual
name|void
name|setupChildProcess
argument_list|()
block|;
comment|// QIODevice
name|qint64
name|readData
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|qint64
name|writeData
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QProcess
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QProcess
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|bool _q_canReadStandardOutput()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|bool _q_canReadStandardError()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|bool _q_canWrite()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|bool _q_startupNotification()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|bool _q_processDied()
argument_list|)
name|friend
name|class
name|QProcessManager
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PROCESS
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPROCESS_H
end_comment
end_unit
