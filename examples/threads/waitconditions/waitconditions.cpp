begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_comment
comment|//! [0]
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_S60
end_ifdef
begin_decl_stmt
DECL|variable|DataSize
specifier|const
name|int
name|DataSize
init|=
literal|300
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
DECL|variable|DataSize
specifier|const
name|int
name|DataSize
init|=
literal|100000
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|BufferSize
specifier|const
name|int
name|BufferSize
init|=
literal|8192
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|buffer
name|char
name|buffer
index|[
name|BufferSize
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|bufferNotEmpty
name|QWaitCondition
name|bufferNotEmpty
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|bufferNotFull
name|QWaitCondition
name|bufferNotFull
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|mutex
name|QMutex
name|mutex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|numUsedBytes
name|int
name|numUsedBytes
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_class
DECL|class|Producer
class|class
name|Producer
super|:
specifier|public
name|QThread
comment|//! [1] //! [2]
block|{
public|public:
DECL|function|Producer
name|Producer
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
name|NULL
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
block|{     }
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|qsrand
argument_list|(
name|QTime
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|.
name|secsTo
argument_list|(
name|QTime
operator|::
name|currentTime
argument_list|()
argument_list|)
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
name|DataSize
condition|;
operator|++
name|i
control|)
block|{
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|numUsedBytes
operator|==
name|BufferSize
condition|)
name|bufferNotFull
operator|.
name|wait
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|buffer
index|[
name|i
operator|%
name|BufferSize
index|]
operator|=
literal|"ACGT"
index|[
operator|(
name|int
operator|)
name|qrand
argument_list|()
operator|%
literal|4
index|]
expr_stmt|;
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
operator|++
name|numUsedBytes
expr_stmt|;
name|bufferNotEmpty
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
block|}
block|}
class|;
end_class
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_class
DECL|class|Consumer
class|class
name|Consumer
super|:
specifier|public
name|QThread
comment|//! [3] //! [4]
block|{
name|Q_OBJECT
public|public:
DECL|function|Consumer
name|Consumer
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
name|NULL
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
block|{     }
DECL|function|run
name|void
name|run
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|DataSize
condition|;
operator|++
name|i
control|)
block|{
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|numUsedBytes
operator|==
literal|0
condition|)
name|bufferNotEmpty
operator|.
name|wait
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_S60
emit|emit
name|stringConsumed
argument_list|(
name|QString
argument_list|(
name|buffer
index|[
name|i
operator|%
name|BufferSize
index|]
argument_list|)
argument_list|)
emit|;
else|#
directive|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%c"
argument_list|,
name|buffer
index|[
name|i
operator|%
name|BufferSize
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
operator|--
name|numUsedBytes
expr_stmt|;
name|bufferNotFull
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
block|}
signals|signals:
name|void
name|stringConsumed
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_comment
comment|//! [4]
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_S60
end_ifdef
begin_class
DECL|class|PlainTextEdit
class|class
name|PlainTextEdit
super|:
specifier|public
name|QPlainTextEdit
block|{
name|Q_OBJECT
public|public:
DECL|function|PlainTextEdit
name|PlainTextEdit
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
name|NULL
parameter_list|)
member_init_list|:
name|QPlainTextEdit
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|producer
argument_list|(
name|NULL
argument_list|)
member_init_list|,
name|consumer
argument_list|(
name|NULL
argument_list|)
block|{
name|setTextInteractionFlags
argument_list|(
name|Qt
operator|::
name|NoTextInteraction
argument_list|)
expr_stmt|;
name|producer
operator|=
operator|new
name|Producer
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|consumer
operator|=
operator|new
name|Consumer
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|consumer
argument_list|,
name|SIGNAL
argument_list|(
name|stringConsumed
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|insertPlainText
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
argument_list|)
argument_list|,
name|Qt
operator|::
name|BlockingQueuedConnection
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|startThreads
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|member|producer
name|Producer
modifier|*
name|producer
decl_stmt|;
DECL|member|consumer
name|Consumer
modifier|*
name|consumer
decl_stmt|;
protected|protected
name|slots
protected|:
DECL|function|startThreads
name|void
name|startThreads
parameter_list|()
block|{
name|producer
operator|->
name|start
argument_list|()
expr_stmt|;
name|consumer
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//! [5]
end_comment
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
name|argv
index|[]
parameter_list|)
comment|//! [5] //! [6]
block|{
ifdef|#
directive|ifdef
name|Q_WS_S60
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|PlainTextEdit
name|console
decl_stmt|;
name|console
operator|.
name|showMaximized
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
else|#
directive|else
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|Producer
name|producer
decl_stmt|;
name|Consumer
name|consumer
decl_stmt|;
name|producer
operator|.
name|start
argument_list|()
expr_stmt|;
name|consumer
operator|.
name|start
argument_list|()
expr_stmt|;
name|producer
operator|.
name|wait
argument_list|()
expr_stmt|;
name|consumer
operator|.
name|wait
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_include
include|#
directive|include
file|"waitconditions.moc"
end_include
end_unit
