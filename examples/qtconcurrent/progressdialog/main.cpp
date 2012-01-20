begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_using
using|using
namespace|namespace
name|QtConcurrent
namespace|;
end_using
begin_decl_stmt
DECL|variable|iterations
specifier|const
name|int
name|iterations
init|=
literal|20
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|spin
name|void
name|spin
parameter_list|(
name|int
modifier|&
name|iteration
parameter_list|)
block|{
specifier|const
name|int
name|work
init|=
literal|1000
operator|*
literal|1000
operator|*
literal|40
decl_stmt|;
specifier|volatile
name|int
name|v
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|work
condition|;
operator|++
name|j
control|)
operator|++
name|v
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"iteration"
operator|<<
name|iteration
operator|<<
literal|"in thread"
operator|<<
name|QThread
operator|::
name|currentThreadId
argument_list|()
expr_stmt|;
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
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
comment|// Prepare the vector.
name|QVector
argument_list|<
name|int
argument_list|>
name|vector
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|iterations
condition|;
operator|++
name|i
control|)
name|vector
operator|.
name|append
argument_list|(
name|i
argument_list|)
expr_stmt|;
comment|// Create a progress dialog.
name|QProgressDialog
name|dialog
decl_stmt|;
name|dialog
operator|.
name|setLabelText
argument_list|(
name|QString
argument_list|(
literal|"Progressing using %1 thread(s)..."
argument_list|)
operator|.
name|arg
argument_list|(
name|QThread
operator|::
name|idealThreadCount
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// Create a QFutureWatcher and connect signals and slots.
name|QFutureWatcher
argument_list|<
name|void
argument_list|>
name|futureWatcher
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|futureWatcher
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
operator|&
name|dialog
argument_list|,
name|SLOT
argument_list|(
name|reset
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|dialog
argument_list|,
name|SIGNAL
argument_list|(
name|canceled
argument_list|()
argument_list|)
argument_list|,
operator|&
name|futureWatcher
argument_list|,
name|SLOT
argument_list|(
name|cancel
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|futureWatcher
argument_list|,
name|SIGNAL
argument_list|(
name|progressRangeChanged
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
operator|&
name|dialog
argument_list|,
name|SLOT
argument_list|(
name|setRange
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|futureWatcher
argument_list|,
name|SIGNAL
argument_list|(
name|progressValueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
operator|&
name|dialog
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// Start the computation.
name|futureWatcher
operator|.
name|setFuture
argument_list|(
name|QtConcurrent
operator|::
name|map
argument_list|(
name|vector
argument_list|,
name|spin
argument_list|)
argument_list|)
expr_stmt|;
comment|// Display the dialog and start the event loop.
name|dialog
operator|.
name|exec
argument_list|()
expr_stmt|;
name|futureWatcher
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
comment|// Query the future to check if was canceled.
name|qDebug
argument_list|()
operator|<<
literal|"Canceled?"
operator|<<
name|futureWatcher
operator|.
name|future
argument_list|()
operator|.
name|isCanceled
argument_list|()
expr_stmt|;
block|}
end_function
begin_else
else|#
directive|else
end_else
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
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QString
name|text
argument_list|(
literal|"Qt Concurrent is not yet supported on this platform"
argument_list|)
decl_stmt|;
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|label
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|label
operator|->
name|show
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
name|text
expr_stmt|;
name|app
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
end_unit
