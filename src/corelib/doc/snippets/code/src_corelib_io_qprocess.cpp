begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_function
DECL|function|wrapInFunction
name|void
name|wrapInFunction
parameter_list|()
block|{
comment|//! [0]
name|QProcess
name|builder
decl_stmt|;
name|builder
operator|.
name|setProcessChannelMode
argument_list|(
name|QProcess
operator|::
name|MergedChannels
argument_list|)
expr_stmt|;
name|builder
operator|.
name|start
argument_list|(
literal|"make"
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"-j2"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|builder
operator|.
name|waitForFinished
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Make failed:"
operator|<<
name|builder
operator|.
name|errorString
argument_list|()
expr_stmt|;
else|else
name|qDebug
argument_list|()
operator|<<
literal|"Make output:"
operator|<<
name|builder
operator|.
name|readAll
argument_list|()
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|QProcess
name|more
decl_stmt|;
name|more
operator|.
name|start
argument_list|(
literal|"more"
argument_list|)
expr_stmt|;
name|more
operator|.
name|write
argument_list|(
literal|"Text to display"
argument_list|)
expr_stmt|;
name|more
operator|.
name|closeWriteChannel
argument_list|()
expr_stmt|;
comment|// QProcess will emit readyRead() once "more" starts printing
comment|//! [1]
comment|//! [2]
name|command1
operator||
name|command2
comment|//! [2]
comment|//! [3]
name|QProcess
name|process1
expr_stmt|;
name|QProcess
name|process2
decl_stmt|;
name|process1
operator|.
name|setStandardOutputProcess
argument_list|(
operator|&
name|process2
argument_list|)
expr_stmt|;
name|process1
operator|.
name|start
argument_list|(
literal|"command1"
argument_list|)
expr_stmt|;
name|process2
operator|.
name|start
argument_list|(
literal|"command2"
argument_list|)
expr_stmt|;
comment|//! [3]
comment|//! [4]
class|class
name|SandboxProcess
super|:
specifier|public
name|QProcess
block|{
operator|...
specifier|protected
operator|:
name|void
name|setupChildProcess
argument_list|()
expr_stmt|;
operator|...
block|}
class|;
name|void
name|SandboxProcess
operator|::
name|setupChildProcess
parameter_list|()
block|{
comment|// Drop all privileges in the child process, and enter
comment|// a chroot jail.
if|#
directive|if
name|defined
name|Q_OS_UNIX
operator|::
name|setgroups
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|::
name|chroot
argument_list|(
literal|"/etc/safe"
argument_list|)
expr_stmt|;
operator|::
name|chdir
argument_list|(
literal|"/"
argument_list|)
expr_stmt|;
operator|::
name|setgid
argument_list|(
name|safeGid
argument_list|)
expr_stmt|;
operator|::
name|setuid
argument_list|(
name|safeUid
argument_list|)
expr_stmt|;
operator|::
name|umask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|//! [4]
comment|//! [5]
name|QProcess
name|process
decl_stmt|;
name|process
operator|.
name|start
argument_list|(
literal|"del /s *.txt"
argument_list|)
expr_stmt|;
comment|// same as process.start("del", QStringList()<< "/s"<< "*.txt");
operator|...
comment|//! [5]
comment|//! [6]
name|QProcess
name|process
expr_stmt|;
name|process
operator|.
name|start
argument_list|(
literal|"dir \"My Documents\""
argument_list|)
expr_stmt|;
comment|//! [6]
comment|//! [7]
name|QProcess
name|process
decl_stmt|;
name|process
operator|.
name|start
argument_list|(
literal|"dir \"\"\"My Documents\"\"\""
argument_list|)
expr_stmt|;
comment|//! [7]
comment|//! [8]
name|QStringList
name|environment
init|=
name|QProcess
operator|::
name|systemEnvironment
argument_list|()
decl_stmt|;
comment|// environment = {"PATH=/usr/bin:/usr/local/bin",
comment|//                "USER=greg", "HOME=/home/greg"}
comment|//! [8]
block|}
end_function
end_unit
