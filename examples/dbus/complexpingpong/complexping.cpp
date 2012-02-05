begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QProcess>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_include
include|#
directive|include
file|"ping-common.h"
end_include
begin_include
include|#
directive|include
file|"complexping.h"
end_include
begin_function
DECL|function|start
name|void
name|Ping
operator|::
name|start
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|oldValue
parameter_list|,
specifier|const
name|QString
modifier|&
name|newValue
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|oldValue
argument_list|)
expr_stmt|;
if|if
condition|(
name|name
operator|!=
name|SERVICE_NAME
operator|||
name|newValue
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
comment|// open stdin for reading
name|qstdin
operator|.
name|open
argument_list|(
name|stdin
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
comment|// find our remote
name|iface
operator|=
operator|new
name|QDBusInterface
argument_list|(
name|SERVICE_NAME
argument_list|,
literal|"/"
argument_list|,
literal|"com.trolltech.QtDBus.ComplexPong.Pong"
argument_list|,
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|iface
operator|->
name|isValid
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
operator|.
name|lastError
argument_list|()
operator|.
name|message
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|quit
argument_list|()
expr_stmt|;
block|}
name|connect
argument_list|(
name|iface
argument_list|,
name|SIGNAL
argument_list|(
name|aboutToQuit
argument_list|()
argument_list|)
argument_list|,
name|QCoreApplication
operator|::
name|instance
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
while|while
condition|(
literal|true
condition|)
block|{
name|printf
argument_list|(
literal|"Ask your question: "
argument_list|)
expr_stmt|;
name|QString
name|line
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qstdin
operator|.
name|readLine
argument_list|()
argument_list|)
operator|.
name|trimmed
argument_list|()
decl_stmt|;
if|if
condition|(
name|line
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|iface
operator|->
name|call
argument_list|(
literal|"quit"
argument_list|)
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
name|line
operator|==
literal|"value"
condition|)
block|{
name|QVariant
name|reply
init|=
name|iface
operator|->
name|property
argument_list|(
literal|"value"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reply
operator|.
name|isNull
argument_list|()
condition|)
name|printf
argument_list|(
literal|"value = %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|reply
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
literal|"value="
argument_list|)
condition|)
block|{
name|iface
operator|->
name|setProperty
argument_list|(
literal|"value"
argument_list|,
name|line
operator|.
name|mid
argument_list|(
literal|6
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QDBusReply
argument_list|<
name|QDBusVariant
argument_list|>
name|reply
init|=
name|iface
operator|->
name|call
argument_list|(
literal|"query"
argument_list|,
name|line
argument_list|)
decl_stmt|;
if|if
condition|(
name|reply
operator|.
name|isValid
argument_list|()
condition|)
name|printf
argument_list|(
literal|"Reply was: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|reply
operator|.
name|value
argument_list|()
operator|.
name|variant
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|iface
operator|->
name|lastError
argument_list|()
operator|.
name|isValid
argument_list|()
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Call failed: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|iface
operator|->
name|lastError
argument_list|()
operator|.
name|message
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
operator|.
name|isConnected
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Cannot connect to the D-Bus session bus.\n"
literal|"To start it, run:\n"
literal|"\teval `dbus-launch --auto-syntax`\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|Ping
name|ping
decl_stmt|;
name|ping
operator|.
name|connect
argument_list|(
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
operator|.
name|interface
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|serviceOwnerChanged
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|start
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QProcess
name|pong
decl_stmt|;
name|pong
operator|.
name|start
argument_list|(
literal|"./complexpong"
argument_list|)
expr_stmt|;
name|app
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
