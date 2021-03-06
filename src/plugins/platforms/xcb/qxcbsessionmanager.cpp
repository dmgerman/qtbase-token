begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Teo Mrnjavac<teo@kde.org> ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbsessionmanager.h"
end_include
begin_include
include|#
directive|include
file|<qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qplatformdefs.h>
end_include
begin_include
include|#
directive|include
file|<qsocketnotifier.h>
end_include
begin_include
include|#
directive|include
file|<X11/SM/SMlib.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_comment
comment|// ERANGE
end_comment
begin_include
include|#
directive|include
file|<cerrno>
end_include
begin_comment
comment|// ERANGE
end_comment
begin_class
DECL|class|QSmSocketReceiver
class|class
name|QSmSocketReceiver
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|QSmSocketReceiver
name|QSmSocketReceiver
parameter_list|(
name|int
name|socket
parameter_list|)
block|{
name|QSocketNotifier
modifier|*
name|sn
init|=
operator|new
name|QSocketNotifier
argument_list|(
name|socket
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|sn
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|socketActivated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
public|public
name|Q_SLOTS
public|:
name|void
name|socketActivated
parameter_list|(
name|int
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|smcConnection
specifier|static
name|SmcConn
name|smcConnection
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sm_interactionActive
specifier|static
name|bool
name|sm_interactionActive
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sm_smActive
specifier|static
name|bool
name|sm_smActive
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sm_interactStyle
specifier|static
name|int
name|sm_interactStyle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sm_saveType
specifier|static
name|int
name|sm_saveType
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sm_cancel
specifier|static
name|bool
name|sm_cancel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sm_waitingForInteraction
specifier|static
name|bool
name|sm_waitingForInteraction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sm_isshutdown
specifier|static
name|bool
name|sm_isshutdown
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sm_phase2
specifier|static
name|bool
name|sm_phase2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sm_in_phase2
specifier|static
name|bool
name|sm_in_phase2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_sm_blockUserInput
name|bool
name|qt_sm_blockUserInput
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sm_receiver
specifier|static
name|QSmSocketReceiver
modifier|*
name|sm_receiver
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|void
name|resetSmState
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|sm_setProperty
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|int
name|num_vals
parameter_list|,
name|SmPropValue
modifier|*
name|vals
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|sm_saveYourselfCallback
parameter_list|(
name|SmcConn
name|smcConn
parameter_list|,
name|SmPointer
name|clientData
parameter_list|,
name|int
name|saveType
parameter_list|,
name|Bool
name|shutdown
parameter_list|,
name|int
name|interactStyle
parameter_list|,
name|Bool
name|fast
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|sm_saveYourselfPhase2Callback
parameter_list|(
name|SmcConn
name|smcConn
parameter_list|,
name|SmPointer
name|clientData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|sm_dieCallback
parameter_list|(
name|SmcConn
name|smcConn
parameter_list|,
name|SmPointer
name|clientData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|sm_shutdownCancelledCallback
parameter_list|(
name|SmcConn
name|smcConn
parameter_list|,
name|SmPointer
name|clientData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|sm_saveCompleteCallback
parameter_list|(
name|SmcConn
name|smcConn
parameter_list|,
name|SmPointer
name|clientData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|sm_interactCallback
parameter_list|(
name|SmcConn
name|smcConn
parameter_list|,
name|SmPointer
name|clientData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|sm_performSaveYourself
parameter_list|(
name|QXcbSessionManager
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|resetSmState
specifier|static
name|void
name|resetSmState
parameter_list|()
block|{
name|sm_waitingForInteraction
operator|=
literal|false
expr_stmt|;
name|sm_interactionActive
operator|=
literal|false
expr_stmt|;
name|sm_interactStyle
operator|=
name|SmInteractStyleNone
expr_stmt|;
name|sm_smActive
operator|=
literal|false
expr_stmt|;
name|qt_sm_blockUserInput
operator|=
literal|false
expr_stmt|;
name|sm_isshutdown
operator|=
literal|false
expr_stmt|;
name|sm_phase2
operator|=
literal|false
expr_stmt|;
name|sm_in_phase2
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_comment
comment|// theoretically it's possible to set several properties at once. For
end_comment
begin_comment
comment|// simplicity, however, we do just one property at a time
end_comment
begin_function
DECL|function|sm_setProperty
specifier|static
name|void
name|sm_setProperty
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|int
name|num_vals
parameter_list|,
name|SmPropValue
modifier|*
name|vals
parameter_list|)
block|{
if|if
condition|(
name|num_vals
condition|)
block|{
name|SmProp
name|prop
decl_stmt|;
name|prop
operator|.
name|name
operator|=
cast|const_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|prop
operator|.
name|type
operator|=
cast|const_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|prop
operator|.
name|num_vals
operator|=
name|num_vals
expr_stmt|;
name|prop
operator|.
name|vals
operator|=
name|vals
expr_stmt|;
name|SmProp
modifier|*
name|props
index|[
literal|1
index|]
decl_stmt|;
name|props
index|[
literal|0
index|]
operator|=
operator|&
name|prop
expr_stmt|;
name|SmcSetProperties
argument_list|(
name|smcConnection
argument_list|,
literal|1
argument_list|,
name|props
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|char
modifier|*
name|names
index|[
literal|1
index|]
decl_stmt|;
name|names
index|[
literal|0
index|]
operator|=
cast|const_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|SmcDeleteProperties
argument_list|(
name|smcConnection
argument_list|,
literal|1
argument_list|,
name|names
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|sm_setProperty
specifier|static
name|void
name|sm_setProperty
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
block|{
name|QByteArray
name|v
init|=
name|value
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
name|SmPropValue
name|prop
decl_stmt|;
name|prop
operator|.
name|length
operator|=
name|v
operator|.
name|length
argument_list|()
expr_stmt|;
name|prop
operator|.
name|value
operator|=
operator|(
name|SmPointer
operator|)
cast|const_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|v
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|sm_setProperty
argument_list|(
name|name
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|,
name|SmARRAY8
argument_list|,
literal|1
argument_list|,
operator|&
name|prop
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sm_setProperty
specifier|static
name|void
name|sm_setProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|value
parameter_list|)
block|{
name|SmPropValue
modifier|*
name|prop
init|=
operator|new
name|SmPropValue
index|[
name|value
operator|.
name|count
argument_list|()
index|]
decl_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|vl
decl_stmt|;
name|vl
operator|.
name|reserve
argument_list|(
name|value
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|QStringList
operator|::
name|ConstIterator
name|it
init|=
name|value
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|value
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|prop
index|[
name|count
index|]
operator|.
name|length
operator|=
operator|(
operator|*
name|it
operator|)
operator|.
name|length
argument_list|()
expr_stmt|;
name|vl
operator|.
name|append
argument_list|(
operator|(
operator|*
name|it
operator|)
operator|.
name|toUtf8
argument_list|()
argument_list|)
expr_stmt|;
name|prop
index|[
name|count
index|]
operator|.
name|value
operator|=
operator|(
name|char
operator|*
operator|)
name|vl
operator|.
name|last
argument_list|()
operator|.
name|data
argument_list|()
expr_stmt|;
operator|++
name|count
expr_stmt|;
block|}
name|sm_setProperty
argument_list|(
name|name
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|,
name|SmLISTofARRAY8
argument_list|,
name|count
argument_list|,
name|prop
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|prop
expr_stmt|;
block|}
end_function
begin_comment
comment|// workaround for broken libsm, see below
end_comment
begin_struct
DECL|struct|QT_smcConn
struct|struct
name|QT_smcConn
block|{
DECL|member|save_yourself_in_progress
name|unsigned
name|int
name|save_yourself_in_progress
range|:
literal|1
decl_stmt|;
DECL|member|shutdown_in_progress
name|unsigned
name|int
name|shutdown_in_progress
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|sm_saveYourselfCallback
specifier|static
name|void
name|sm_saveYourselfCallback
parameter_list|(
name|SmcConn
name|smcConn
parameter_list|,
name|SmPointer
name|clientData
parameter_list|,
name|int
name|saveType
parameter_list|,
name|Bool
name|shutdown
parameter_list|,
name|int
name|interactStyle
parameter_list|,
name|Bool
comment|/*fast*/
parameter_list|)
block|{
if|if
condition|(
name|smcConn
operator|!=
name|smcConnection
condition|)
return|return;
name|sm_cancel
operator|=
literal|false
expr_stmt|;
name|sm_smActive
operator|=
literal|true
expr_stmt|;
name|sm_isshutdown
operator|=
name|shutdown
expr_stmt|;
name|sm_saveType
operator|=
name|saveType
expr_stmt|;
name|sm_interactStyle
operator|=
name|interactStyle
expr_stmt|;
comment|// ugly workaround for broken libSM. libSM should do that _before_
comment|// actually invoking the callback in sm_process.c
operator|(
operator|(
name|QT_smcConn
operator|*
operator|)
name|smcConn
operator|)
operator|->
name|save_yourself_in_progress
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|sm_isshutdown
condition|)
operator|(
operator|(
name|QT_smcConn
operator|*
operator|)
name|smcConn
operator|)
operator|->
name|shutdown_in_progress
operator|=
literal|true
expr_stmt|;
name|sm_performSaveYourself
argument_list|(
operator|(
name|QXcbSessionManager
operator|*
operator|)
name|clientData
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sm_isshutdown
condition|)
comment|// we cannot expect a confirmation message in that case
name|resetSmState
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sm_performSaveYourself
specifier|static
name|void
name|sm_performSaveYourself
parameter_list|(
name|QXcbSessionManager
modifier|*
name|sm
parameter_list|)
block|{
if|if
condition|(
name|sm_isshutdown
condition|)
name|qt_sm_blockUserInput
operator|=
literal|true
expr_stmt|;
comment|// generate a new session key
name|timeval
name|tv
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|tv
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sm
operator|->
name|setSessionKey
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|qulonglong
argument_list|(
name|tv
operator|.
name|tv_sec
argument_list|)
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|qulonglong
argument_list|(
name|tv
operator|.
name|tv_usec
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|arguments
init|=
name|QCoreApplication
operator|::
name|arguments
argument_list|()
decl_stmt|;
name|QString
name|argument0
init|=
name|arguments
operator|.
name|isEmpty
argument_list|()
condition|?
name|QCoreApplication
operator|::
name|applicationFilePath
argument_list|()
else|:
name|arguments
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|// tell the session manager about our program in best POSIX style
name|sm_setProperty
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|SmProgram
argument_list|)
argument_list|,
name|argument0
argument_list|)
expr_stmt|;
comment|// tell the session manager about our user as well.
name|struct
name|passwd
modifier|*
name|entryPtr
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_THREAD_SAFE_FUNCTIONS
argument_list|)
operator|&&
operator|(
name|_POSIX_THREAD_SAFE_FUNCTIONS
operator|-
literal|0
operator|>
literal|0
operator|)
name|QVarLengthArray
argument_list|<
name|char
argument_list|,
literal|1024
argument_list|>
name|buf
argument_list|(
name|qMax
argument_list|<
name|long
argument_list|>
argument_list|(
name|sysconf
argument_list|(
name|_SC_GETPW_R_SIZE_MAX
argument_list|)
argument_list|,
literal|1024L
argument_list|)
argument_list|)
decl_stmt|;
name|struct
name|passwd
name|entry
decl_stmt|;
while|while
condition|(
name|getpwuid_r
argument_list|(
name|geteuid
argument_list|()
argument_list|,
operator|&
name|entry
argument_list|,
name|buf
operator|.
name|data
argument_list|()
argument_list|,
name|buf
operator|.
name|size
argument_list|()
argument_list|,
operator|&
name|entryPtr
argument_list|)
operator|==
name|ERANGE
condition|)
block|{
if|if
condition|(
name|buf
operator|.
name|size
argument_list|()
operator|>=
literal|32768
condition|)
block|{
comment|// too big already, fail
specifier|static
name|char
name|badusername
index|[]
init|=
literal|""
decl_stmt|;
name|entryPtr
operator|=
operator|&
name|entry
expr_stmt|;
name|entry
operator|.
name|pw_name
operator|=
name|badusername
expr_stmt|;
break|break;
block|}
comment|// retry with a bigger buffer
name|buf
operator|.
name|resize
argument_list|(
name|buf
operator|.
name|size
argument_list|()
operator|*
literal|2
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|entryPtr
operator|=
name|getpwuid
argument_list|(
name|geteuid
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|entryPtr
condition|)
name|sm_setProperty
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|SmUserID
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|entryPtr
operator|->
name|pw_name
argument_list|)
argument_list|)
expr_stmt|;
comment|// generate a restart and discard command that makes sense
name|QStringList
name|restart
decl_stmt|;
name|restart
operator|<<
name|argument0
operator|<<
name|QLatin1String
argument_list|(
literal|"-session"
argument_list|)
operator|<<
name|sm
operator|->
name|sessionId
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
operator|+
name|sm
operator|->
name|sessionKey
argument_list|()
expr_stmt|;
name|QFileInfo
name|fi
init|=
name|QCoreApplication
operator|::
name|applicationFilePath
argument_list|()
decl_stmt|;
if|if
condition|(
name|qAppName
argument_list|()
operator|.
name|compare
argument_list|(
name|fi
operator|.
name|fileName
argument_list|()
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|!=
literal|0
condition|)
name|restart
operator|<<
name|QLatin1String
argument_list|(
literal|"-name"
argument_list|)
operator|<<
name|qAppName
argument_list|()
expr_stmt|;
name|sm
operator|->
name|setRestartCommand
argument_list|(
name|restart
argument_list|)
expr_stmt|;
name|QStringList
name|discard
decl_stmt|;
name|sm
operator|->
name|setDiscardCommand
argument_list|(
name|discard
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|sm_saveType
condition|)
block|{
case|case
name|SmSaveBoth
case|:
name|sm
operator|->
name|appCommitData
argument_list|()
expr_stmt|;
if|if
condition|(
name|sm_isshutdown
operator|&&
name|sm_cancel
condition|)
break|break;
comment|// we cancelled the shutdown, no need to save state
comment|// fall through
case|case
name|SmSaveLocal
case|:
name|sm
operator|->
name|appSaveState
argument_list|()
expr_stmt|;
break|break;
case|case
name|SmSaveGlobal
case|:
name|sm
operator|->
name|appCommitData
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
name|sm_phase2
operator|&&
operator|!
name|sm_in_phase2
condition|)
block|{
name|SmcRequestSaveYourselfPhase2
argument_list|(
name|smcConnection
argument_list|,
name|sm_saveYourselfPhase2Callback
argument_list|,
operator|(
name|SmPointer
operator|*
operator|)
name|sm
argument_list|)
expr_stmt|;
name|qt_sm_blockUserInput
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
comment|// close eventual interaction monitors and cancel the
comment|// shutdown, if required. Note that we can only cancel when
comment|// performing a shutdown, it does not work for checkpoints
if|if
condition|(
name|sm_interactionActive
condition|)
block|{
name|SmcInteractDone
argument_list|(
name|smcConnection
argument_list|,
name|sm_isshutdown
operator|&&
name|sm_cancel
argument_list|)
expr_stmt|;
name|sm_interactionActive
operator|=
literal|false
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|sm_cancel
operator|&&
name|sm_isshutdown
condition|)
block|{
if|if
condition|(
name|sm
operator|->
name|allowsErrorInteraction
argument_list|()
condition|)
block|{
name|SmcInteractDone
argument_list|(
name|smcConnection
argument_list|,
name|True
argument_list|)
expr_stmt|;
name|sm_interactionActive
operator|=
literal|false
expr_stmt|;
block|}
block|}
comment|// set restart and discard command in session manager
name|sm_setProperty
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|SmRestartCommand
argument_list|)
argument_list|,
name|sm
operator|->
name|restartCommand
argument_list|()
argument_list|)
expr_stmt|;
name|sm_setProperty
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|SmDiscardCommand
argument_list|)
argument_list|,
name|sm
operator|->
name|discardCommand
argument_list|()
argument_list|)
expr_stmt|;
comment|// set the restart hint
name|SmPropValue
name|prop
decl_stmt|;
name|prop
operator|.
name|length
operator|=
sizeof|sizeof
argument_list|(
name|int
argument_list|)
expr_stmt|;
name|int
name|value
init|=
name|sm
operator|->
name|restartHint
argument_list|()
decl_stmt|;
name|prop
operator|.
name|value
operator|=
operator|(
name|SmPointer
operator|)
operator|&
name|value
expr_stmt|;
name|sm_setProperty
argument_list|(
name|SmRestartStyleHint
argument_list|,
name|SmCARD8
argument_list|,
literal|1
argument_list|,
operator|&
name|prop
argument_list|)
expr_stmt|;
comment|// we are done
name|SmcSaveYourselfDone
argument_list|(
name|smcConnection
argument_list|,
operator|!
name|sm_cancel
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|sm_dieCallback
specifier|static
name|void
name|sm_dieCallback
parameter_list|(
name|SmcConn
name|smcConn
parameter_list|,
name|SmPointer
comment|/* clientData */
parameter_list|)
block|{
if|if
condition|(
name|smcConn
operator|!=
name|smcConnection
condition|)
return|return;
name|resetSmState
argument_list|()
expr_stmt|;
name|QEvent
name|quitEvent
argument_list|(
name|QEvent
operator|::
name|Quit
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendEvent
argument_list|(
name|qApp
argument_list|,
operator|&
name|quitEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sm_shutdownCancelledCallback
specifier|static
name|void
name|sm_shutdownCancelledCallback
parameter_list|(
name|SmcConn
name|smcConn
parameter_list|,
name|SmPointer
name|clientData
parameter_list|)
block|{
if|if
condition|(
name|smcConn
operator|!=
name|smcConnection
condition|)
return|return;
if|if
condition|(
name|sm_waitingForInteraction
condition|)
operator|(
operator|(
name|QXcbSessionManager
operator|*
operator|)
name|clientData
operator|)
operator|->
name|exitEventLoop
argument_list|()
expr_stmt|;
name|resetSmState
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sm_saveCompleteCallback
specifier|static
name|void
name|sm_saveCompleteCallback
parameter_list|(
name|SmcConn
name|smcConn
parameter_list|,
name|SmPointer
comment|/*clientData */
parameter_list|)
block|{
if|if
condition|(
name|smcConn
operator|!=
name|smcConnection
condition|)
return|return;
name|resetSmState
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sm_interactCallback
specifier|static
name|void
name|sm_interactCallback
parameter_list|(
name|SmcConn
name|smcConn
parameter_list|,
name|SmPointer
name|clientData
parameter_list|)
block|{
if|if
condition|(
name|smcConn
operator|!=
name|smcConnection
condition|)
return|return;
if|if
condition|(
name|sm_waitingForInteraction
condition|)
operator|(
operator|(
name|QXcbSessionManager
operator|*
operator|)
name|clientData
operator|)
operator|->
name|exitEventLoop
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sm_saveYourselfPhase2Callback
specifier|static
name|void
name|sm_saveYourselfPhase2Callback
parameter_list|(
name|SmcConn
name|smcConn
parameter_list|,
name|SmPointer
name|clientData
parameter_list|)
block|{
if|if
condition|(
name|smcConn
operator|!=
name|smcConnection
condition|)
return|return;
name|sm_in_phase2
operator|=
literal|true
expr_stmt|;
name|sm_performSaveYourself
argument_list|(
operator|(
name|QXcbSessionManager
operator|*
operator|)
name|clientData
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|socketActivated
name|void
name|QSmSocketReceiver
operator|::
name|socketActivated
parameter_list|(
name|int
parameter_list|)
block|{
name|IceProcessMessages
argument_list|(
name|SmcGetIceConnection
argument_list|(
name|smcConnection
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// QXcbSessionManager starts here
end_comment
begin_constructor
DECL|function|QXcbSessionManager
name|QXcbSessionManager
operator|::
name|QXcbSessionManager
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|,
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
member_init_list|:
name|QPlatformSessionManager
argument_list|(
name|id
argument_list|,
name|key
argument_list|)
member_init_list|,
name|m_eventLoop
argument_list|(
literal|0
argument_list|)
block|{
name|resetSmState
argument_list|()
expr_stmt|;
name|char
name|cerror
index|[
literal|256
index|]
decl_stmt|;
name|char
modifier|*
name|myId
init|=
literal|0
decl_stmt|;
name|QByteArray
name|b_id
init|=
name|id
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
name|char
modifier|*
name|prevId
init|=
name|b_id
operator|.
name|data
argument_list|()
decl_stmt|;
name|SmcCallbacks
name|cb
decl_stmt|;
name|cb
operator|.
name|save_yourself
operator|.
name|callback
operator|=
name|sm_saveYourselfCallback
expr_stmt|;
name|cb
operator|.
name|save_yourself
operator|.
name|client_data
operator|=
operator|(
name|SmPointer
operator|)
name|this
expr_stmt|;
name|cb
operator|.
name|die
operator|.
name|callback
operator|=
name|sm_dieCallback
expr_stmt|;
name|cb
operator|.
name|die
operator|.
name|client_data
operator|=
operator|(
name|SmPointer
operator|)
name|this
expr_stmt|;
name|cb
operator|.
name|save_complete
operator|.
name|callback
operator|=
name|sm_saveCompleteCallback
expr_stmt|;
name|cb
operator|.
name|save_complete
operator|.
name|client_data
operator|=
operator|(
name|SmPointer
operator|)
name|this
expr_stmt|;
name|cb
operator|.
name|shutdown_cancelled
operator|.
name|callback
operator|=
name|sm_shutdownCancelledCallback
expr_stmt|;
name|cb
operator|.
name|shutdown_cancelled
operator|.
name|client_data
operator|=
operator|(
name|SmPointer
operator|)
name|this
expr_stmt|;
comment|// avoid showing a warning message below
if|if
condition|(
operator|!
name|qEnvironmentVariableIsSet
argument_list|(
literal|"SESSION_MANAGER"
argument_list|)
condition|)
return|return;
name|smcConnection
operator|=
name|SmcOpenConnection
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
name|SmcSaveYourselfProcMask
operator||
name|SmcDieProcMask
operator||
name|SmcSaveCompleteProcMask
operator||
name|SmcShutdownCancelledProcMask
argument_list|,
operator|&
name|cb
argument_list|,
name|prevId
argument_list|,
operator|&
name|myId
argument_list|,
literal|256
argument_list|,
name|cerror
argument_list|)
expr_stmt|;
name|setSessionId
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|myId
argument_list|)
argument_list|)
expr_stmt|;
operator|::
name|free
argument_list|(
name|myId
argument_list|)
expr_stmt|;
comment|// it was allocated by C
name|QString
name|error
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|cerror
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|smcConnection
condition|)
name|qWarning
argument_list|(
literal|"Qt: Session management error: %s"
argument_list|,
name|qPrintable
argument_list|(
name|error
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|sm_receiver
operator|=
operator|new
name|QSmSocketReceiver
argument_list|(
name|IceConnectionNumber
argument_list|(
name|SmcGetIceConnection
argument_list|(
name|smcConnection
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QXcbSessionManager
name|QXcbSessionManager
operator|::
name|~
name|QXcbSessionManager
parameter_list|()
block|{
if|if
condition|(
name|smcConnection
condition|)
name|SmcCloseConnection
argument_list|(
name|smcConnection
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|smcConnection
operator|=
literal|0
expr_stmt|;
operator|delete
name|sm_receiver
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|handle
name|void
modifier|*
name|QXcbSessionManager
operator|::
name|handle
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|smcConnection
return|;
block|}
end_function
begin_function
DECL|function|allowsInteraction
name|bool
name|QXcbSessionManager
operator|::
name|allowsInteraction
parameter_list|()
block|{
if|if
condition|(
name|sm_interactionActive
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|sm_waitingForInteraction
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|sm_interactStyle
operator|==
name|SmInteractStyleAny
condition|)
block|{
name|sm_waitingForInteraction
operator|=
name|SmcInteractRequest
argument_list|(
name|smcConnection
argument_list|,
name|SmDialogNormal
argument_list|,
name|sm_interactCallback
argument_list|,
operator|(
name|SmPointer
operator|*
operator|)
name|this
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|sm_waitingForInteraction
condition|)
block|{
name|QEventLoop
name|eventLoop
decl_stmt|;
name|m_eventLoop
operator|=
operator|&
name|eventLoop
expr_stmt|;
name|eventLoop
operator|.
name|exec
argument_list|()
expr_stmt|;
name|m_eventLoop
operator|=
literal|0
expr_stmt|;
name|sm_waitingForInteraction
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|sm_smActive
condition|)
block|{
comment|// not cancelled
name|sm_interactionActive
operator|=
literal|true
expr_stmt|;
name|qt_sm_blockUserInput
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|allowsErrorInteraction
name|bool
name|QXcbSessionManager
operator|::
name|allowsErrorInteraction
parameter_list|()
block|{
if|if
condition|(
name|sm_interactionActive
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|sm_waitingForInteraction
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|sm_interactStyle
operator|==
name|SmInteractStyleAny
operator|||
name|sm_interactStyle
operator|==
name|SmInteractStyleErrors
condition|)
block|{
name|sm_waitingForInteraction
operator|=
name|SmcInteractRequest
argument_list|(
name|smcConnection
argument_list|,
name|SmDialogError
argument_list|,
name|sm_interactCallback
argument_list|,
operator|(
name|SmPointer
operator|*
operator|)
name|this
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|sm_waitingForInteraction
condition|)
block|{
name|QEventLoop
name|eventLoop
decl_stmt|;
name|m_eventLoop
operator|=
operator|&
name|eventLoop
expr_stmt|;
name|eventLoop
operator|.
name|exec
argument_list|()
expr_stmt|;
name|m_eventLoop
operator|=
literal|0
expr_stmt|;
name|sm_waitingForInteraction
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|sm_smActive
condition|)
block|{
comment|// not cancelled
name|sm_interactionActive
operator|=
literal|true
expr_stmt|;
name|qt_sm_blockUserInput
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|release
name|void
name|QXcbSessionManager
operator|::
name|release
parameter_list|()
block|{
if|if
condition|(
name|sm_interactionActive
condition|)
block|{
name|SmcInteractDone
argument_list|(
name|smcConnection
argument_list|,
name|False
argument_list|)
expr_stmt|;
name|sm_interactionActive
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|sm_smActive
operator|&&
name|sm_isshutdown
condition|)
name|qt_sm_blockUserInput
operator|=
literal|true
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|cancel
name|void
name|QXcbSessionManager
operator|::
name|cancel
parameter_list|()
block|{
name|sm_cancel
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setManagerProperty
name|void
name|QXcbSessionManager
operator|::
name|setManagerProperty
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
block|{
name|sm_setProperty
argument_list|(
name|name
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setManagerProperty
name|void
name|QXcbSessionManager
operator|::
name|setManagerProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|value
parameter_list|)
block|{
name|sm_setProperty
argument_list|(
name|name
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isPhase2
name|bool
name|QXcbSessionManager
operator|::
name|isPhase2
parameter_list|()
specifier|const
block|{
return|return
name|sm_in_phase2
return|;
block|}
end_function
begin_function
DECL|function|requestPhase2
name|void
name|QXcbSessionManager
operator|::
name|requestPhase2
parameter_list|()
block|{
name|sm_phase2
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|exitEventLoop
name|void
name|QXcbSessionManager
operator|::
name|exitEventLoop
parameter_list|()
block|{
name|m_eventLoop
operator|->
name|exit
argument_list|()
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|"qxcbsessionmanager.moc"
end_include
end_unit
