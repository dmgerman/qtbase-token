begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPROCESS_P_H
end_ifndef
begin_define
DECL|macro|QPROCESS_P_H
define|#
directive|define
name|QPROCESS_P_H
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
file|"QtCore/qprocess.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qshareddata.h"
end_include
begin_include
include|#
directive|include
file|"private/qringbuffer_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qiodevice_p.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|"QtCore/qt_windows.h"
end_include
begin_typedef
DECL|typedef|Q_PIPE
typedef|typedef
name|HANDLE
name|Q_PIPE
typedef|;
end_typedef
begin_define
DECL|macro|INVALID_Q_PIPE
define|#
directive|define
name|INVALID_Q_PIPE
value|INVALID_HANDLE_VALUE
end_define
begin_else
else|#
directive|else
end_else
begin_typedef
DECL|typedef|Q_PIPE
typedef|typedef
name|int
name|Q_PIPE
typedef|;
end_typedef
begin_define
DECL|macro|INVALID_Q_PIPE
define|#
directive|define
name|INVALID_Q_PIPE
value|-1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsPipeWriter
name|class
name|QWindowsPipeWriter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWinEventNotifier
name|class
name|QWinEventNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTimer
name|class
name|QTimer
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_decl_stmt
DECL|variable|RProcess
name|class
name|RProcess
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QProcessEnvironmentPrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|class
name|Key
operator|:
name|public
name|QString
block|{
name|public
operator|:
name|Key
argument_list|()
block|{}
name|explicit
name|Key
argument_list|(
specifier|const
name|QString
operator|&
name|other
argument_list|)
operator|:
name|QString
argument_list|(
argument|other
argument_list|)
block|{}
name|Key
argument_list|(
specifier|const
name|Key
operator|&
name|other
argument_list|)
operator|:
name|QString
argument_list|(
argument|other
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Key
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|compare
argument_list|(
name|other
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
return|;
block|}
expr|}
block|;
typedef|typedef
name|QString
name|Value
typedef|;
specifier|inline
name|Key
name|prepareName
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|{
return|return
name|Key
argument_list|(
name|name
argument_list|)
return|;
block|}
specifier|inline
name|QString
name|nameToString
argument_list|(
argument|const Key&name
argument_list|)
specifier|const
block|{
return|return
name|name
return|;
block|}
specifier|inline
name|Value
name|prepareValue
argument_list|(
argument|const QString&value
argument_list|)
specifier|const
block|{
return|return
name|value
return|;
block|}
specifier|inline
name|QString
name|valueToString
argument_list|(
argument|const Value&value
argument_list|)
specifier|const
block|{
return|return
name|value
return|;
block|}
else|#
directive|else
name|class
name|Key
block|{
name|public
operator|:
name|Key
argument_list|()
operator|:
name|hash
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|Key
argument_list|(
specifier|const
name|QByteArray
operator|&
name|other
argument_list|)
operator|:
name|key
argument_list|(
name|other
argument_list|)
block|,
name|hash
argument_list|(
argument|qHash(key)
argument_list|)
block|{}
name|Key
argument_list|(
argument|const Key&other
argument_list|)
block|{
operator|*
name|this
operator|=
name|other
block|; }
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Key
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|key
operator|==
name|other
operator|.
name|key
return|;
block|}
name|QByteArray
name|key
block|;
name|uint
name|hash
block|;     }
block|;
name|class
name|Value
block|{
name|public
operator|:
name|Value
argument_list|()
block|{}
name|Value
argument_list|(
argument|const Value&other
argument_list|)
block|{
operator|*
name|this
operator|=
name|other
block|; }
name|explicit
name|Value
argument_list|(
specifier|const
name|QString
operator|&
name|value
argument_list|)
operator|:
name|stringValue
argument_list|(
argument|value
argument_list|)
block|{}
name|explicit
name|Value
argument_list|(
specifier|const
name|QByteArray
operator|&
name|value
argument_list|)
operator|:
name|byteValue
argument_list|(
argument|value
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Value
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|byteValue
operator|.
name|isEmpty
argument_list|()
operator|&&
name|other
operator|.
name|byteValue
operator|.
name|isEmpty
argument_list|()
operator|?
name|stringValue
operator|==
name|other
operator|.
name|stringValue
operator|:
name|bytes
argument_list|()
operator|==
name|other
operator|.
name|bytes
argument_list|()
return|;
block|}
name|QByteArray
name|bytes
argument_list|()
specifier|const
block|{
if|if
condition|(
name|byteValue
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|stringValue
operator|.
name|isEmpty
argument_list|()
condition|)
name|byteValue
operator|=
name|stringValue
operator|.
name|toLocal8Bit
argument_list|()
expr_stmt|;
return|return
name|byteValue
return|;
block|}
name|QString
name|string
argument_list|()
specifier|const
block|{
if|if
condition|(
name|stringValue
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|byteValue
operator|.
name|isEmpty
argument_list|()
condition|)
name|stringValue
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|byteValue
argument_list|)
expr_stmt|;
return|return
name|stringValue
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|mutable
name|QByteArray
name|byteValue
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QString
name|stringValue
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
specifier|inline
name|Key
name|prepareName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
block|{
name|Key
modifier|&
name|ent
init|=
name|nameMap
index|[
name|name
index|]
decl_stmt|;
if|if
condition|(
name|ent
operator|.
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
name|ent
operator|=
name|Key
argument_list|(
name|name
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|ent
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QString
name|nameToString
argument_list|(
specifier|const
name|Key
operator|&
name|name
argument_list|)
decl|const
block|{
specifier|const
name|QString
name|sname
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|name
operator|.
name|key
argument_list|)
decl_stmt|;
name|nameMap
index|[
name|sname
index|]
operator|=
name|name
expr_stmt|;
return|return
name|sname
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|Value
name|prepareValue
argument_list|(
specifier|const
name|QString
operator|&
name|value
argument_list|)
decl|const
block|{
return|return
name|Value
argument_list|(
name|value
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QString
name|valueToString
argument_list|(
specifier|const
name|Value
operator|&
name|value
argument_list|)
decl|const
block|{
return|return
name|value
operator|.
name|string
argument_list|()
return|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
typedef|typedef
name|QHash
operator|<
name|Key
operator|,
name|Value
operator|>
name|Hash
expr_stmt|;
end_typedef
begin_decl_stmt
name|Hash
name|hash
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_typedef
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|Key
operator|>
name|NameHash
expr_stmt|;
end_typedef
begin_decl_stmt
name|mutable
name|NameHash
name|nameMap
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|QProcessEnvironment
name|fromList
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|list
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QStringList
name|toList
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QStringList
name|keys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|insert
parameter_list|(
specifier|const
name|QProcessEnvironmentPrivate
modifier|&
name|other
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
unit|};
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QProcessEnvironmentPrivate
operator|::
name|Key
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QProcessEnvironmentPrivate
operator|::
name|Value
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_decl_stmt
DECL|function|qHash
specifier|inline
name|uint
name|qHash
argument_list|(
specifier|const
name|QProcessEnvironmentPrivate
operator|::
name|Key
operator|&
name|key
argument_list|)
block|{
return|return
name|qHash
argument_list|(
name|key
operator|.
name|toCaseFolded
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
DECL|function|qHash
specifier|inline
name|uint
name|qHash
argument_list|(
specifier|const
name|QProcessEnvironmentPrivate
operator|::
name|Key
operator|&
name|key
argument_list|)
block|{
return|return
name|key
operator|.
name|hash
return|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QProcessPrivate
range|:
name|public
name|QIODevicePrivate
block|{
name|public
operator|:
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QProcess
argument_list|)
expr|struct
name|Channel
block|{         enum
name|ProcessChannelType
block|{
name|Normal
operator|=
literal|0
block|,
name|PipeSource
operator|=
literal|1
block|,
name|PipeSink
operator|=
literal|2
block|,
name|Redirect
operator|=
literal|3
comment|// if you add "= 4" here, increase the number of bits below
block|}
block|;
name|Channel
argument_list|()
operator|:
name|process
argument_list|(
literal|0
argument_list|)
block|,
name|notifier
argument_list|(
literal|0
argument_list|)
block|,
name|type
argument_list|(
name|Normal
argument_list|)
block|,
name|closed
argument_list|(
name|false
argument_list|)
block|,
name|append
argument_list|(
argument|false
argument_list|)
block|{
name|pipe
index|[
literal|0
index|]
operator|=
name|INVALID_Q_PIPE
block|;
name|pipe
index|[
literal|1
index|]
operator|=
name|INVALID_Q_PIPE
block|;         }
name|void
name|clear
argument_list|()
block|;
name|Channel
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QString
operator|&
name|fileName
operator|)
block|{
name|clear
argument_list|()
block|;
name|file
operator|=
name|fileName
block|;
name|type
operator|=
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|?
name|Normal
else|:
name|Redirect
block|;
return|return
operator|*
name|this
return|;
block|}
name|void
name|pipeTo
argument_list|(
argument|QProcessPrivate *other
argument_list|)
block|{
name|clear
argument_list|()
block|;
name|process
operator|=
name|other
block|;
name|type
operator|=
name|PipeSource
block|;         }
name|void
name|pipeFrom
argument_list|(
argument|QProcessPrivate *other
argument_list|)
block|{
name|clear
argument_list|()
block|;
name|process
operator|=
name|other
block|;
name|type
operator|=
name|PipeSink
block|;         }
name|QString
name|file
block|;
name|QProcessPrivate
operator|*
name|process
block|;
name|QSocketNotifier
operator|*
name|notifier
block|;
name|Q_PIPE
name|pipe
index|[
literal|2
index|]
block|;
name|unsigned
name|type
operator|:
literal|2
block|;
name|bool
name|closed
operator|:
literal|1
block|;
name|bool
name|append
operator|:
literal|1
block|;     }
block|;
name|QProcessPrivate
argument_list|()
block|;
name|virtual
operator|~
name|QProcessPrivate
argument_list|()
block|;
comment|// private slots
name|bool
name|_q_canReadStandardOutput
argument_list|()
block|;
name|bool
name|_q_canReadStandardError
argument_list|()
block|;
name|bool
name|_q_canWrite
argument_list|()
block|;
name|bool
name|_q_startupNotification
argument_list|()
block|;
name|bool
name|_q_processDied
argument_list|()
block|;
name|void
name|_q_notified
argument_list|()
block|;
name|QProcess
operator|::
name|ProcessChannel
name|processChannel
block|;
name|QProcess
operator|::
name|ProcessChannelMode
name|processChannelMode
block|;
name|QProcess
operator|::
name|ProcessError
name|processError
block|;
name|QProcess
operator|::
name|ProcessState
name|processState
block|;
name|QString
name|workingDirectory
block|;
name|Q_PID
name|pid
block|;
name|int
name|sequenceNumber
block|;
name|bool
name|dying
block|;
name|bool
name|emittedReadyRead
block|;
name|bool
name|emittedBytesWritten
block|;
name|Channel
name|stdinChannel
block|;
name|Channel
name|stdoutChannel
block|;
name|Channel
name|stderrChannel
block|;
name|bool
name|createChannel
argument_list|(
name|Channel
operator|&
name|channel
argument_list|)
block|;
name|void
name|closeWriteChannel
argument_list|()
block|;
name|QString
name|program
block|;
name|QStringList
name|arguments
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|QString
name|nativeArguments
block|;
endif|#
directive|endif
name|QProcessEnvironment
name|environment
block|;
name|QRingBuffer
name|outputReadBuffer
block|;
name|QRingBuffer
name|errorReadBuffer
block|;
name|QRingBuffer
name|writeBuffer
block|;
name|Q_PIPE
name|childStartedPipe
index|[
literal|2
index|]
block|;
name|Q_PIPE
name|deathPipe
index|[
literal|2
index|]
block|;
name|void
name|destroyPipe
argument_list|(
argument|Q_PIPE pipe[
literal|2
argument|]
argument_list|)
block|;
name|QSocketNotifier
operator|*
name|startupSocketNotifier
block|;
name|QSocketNotifier
operator|*
name|deathNotifier
block|;
comment|// the wonderful windows notifier
name|QTimer
operator|*
name|notifier
block|;
name|QWindowsPipeWriter
operator|*
name|pipeWriter
block|;
name|QWinEventNotifier
operator|*
name|processFinishedNotifier
block|;
name|void
name|startProcess
argument_list|()
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|void
name|execChild
argument_list|(
specifier|const
name|char
operator|*
name|workingDirectory
argument_list|,
name|char
operator|*
operator|*
name|path
argument_list|,
name|char
operator|*
operator|*
name|argv
argument_list|,
name|char
operator|*
operator|*
name|envp
argument_list|)
block|;
endif|#
directive|endif
name|bool
name|processStarted
argument_list|()
block|;
name|void
name|terminateProcess
argument_list|()
block|;
name|void
name|killProcess
argument_list|()
block|;
name|void
name|findExitCode
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_OS_UNIX
name|bool
name|waitForDeadChild
argument_list|()
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|void
name|flushPipeWriter
argument_list|()
block|;
name|qint64
name|pipeWriterBytesToWrite
argument_list|()
specifier|const
block|;
endif|#
directive|endif
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
operator|=
name|QString
argument_list|()
argument_list|,
name|qint64
operator|*
name|pid
operator|=
literal|0
argument_list|)
block|;
name|int
name|exitCode
block|;
name|QProcess
operator|::
name|ExitStatus
name|exitStatus
block|;
name|bool
name|crashed
block|;
ifdef|#
directive|ifdef
name|Q_OS_UNIX
name|int
name|serial
block|;
endif|#
directive|endif
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
block|;
name|bool
name|waitForBytesWritten
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|bool
name|waitForFinished
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|bool
name|waitForWrite
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|qint64
name|bytesAvailableFromStdout
argument_list|()
specifier|const
block|;
name|qint64
name|bytesAvailableFromStderr
argument_list|()
specifier|const
block|;
name|qint64
name|readFromStdout
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|readFromStderr
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|writeToStdin
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|void
name|cleanup
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_OS_UNIX
specifier|static
name|void
name|initializeProcessManager
argument_list|()
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|bool
name|processLaunched
block|;
name|RProcess
operator|*
name|symbianProcess
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPROCESS_P_H
end_comment
end_unit
