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
file|<QtNetwork>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|"dialog.h"
end_include
begin_include
include|#
directive|include
file|"fortuneserver.h"
end_include
begin_constructor
DECL|function|Dialog
name|Dialog
operator|::
name|Dialog
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|statusLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|statusLabel
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|QAction
modifier|*
name|quitAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Exit"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|quitAction
operator|->
name|setSoftKeyRole
argument_list|(
name|QAction
operator|::
name|NegativeSoftKey
argument_list|)
expr_stmt|;
name|addAction
argument_list|(
name|quitAction
argument_list|)
expr_stmt|;
else|#
directive|else
name|quitButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Quit"
argument_list|)
argument_list|)
expr_stmt|;
name|quitButton
operator|->
name|setAutoDefault
argument_list|(
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|server
operator|.
name|listen
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|critical
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Threaded Fortune Server"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Unable to start the server: %1."
argument_list|)
operator|.
name|arg
argument_list|(
name|server
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|close
argument_list|()
expr_stmt|;
return|return;
block|}
name|QString
name|ipAddress
decl_stmt|;
name|QList
argument_list|<
name|QHostAddress
argument_list|>
name|ipAddressesList
init|=
name|QNetworkInterface
operator|::
name|allAddresses
argument_list|()
decl_stmt|;
comment|// use the first non-localhost IPv4 address
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ipAddressesList
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|ipAddressesList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|!=
name|QHostAddress
operator|::
name|LocalHost
operator|&&
name|ipAddressesList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toIPv4Address
argument_list|()
condition|)
block|{
name|ipAddress
operator|=
name|ipAddressesList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
comment|// if we did not find one, use IPv4 localhost
if|if
condition|(
name|ipAddress
operator|.
name|isEmpty
argument_list|()
condition|)
name|ipAddress
operator|=
name|QHostAddress
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"The server is running on\n\nIP: %1\nport: %2\n\n"
literal|"Run the Fortune Client example now."
argument_list|)
operator|.
name|arg
argument_list|(
name|ipAddress
argument_list|)
operator|.
name|arg
argument_list|(
name|server
operator|.
name|serverPort
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|connect
argument_list|(
name|quitAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|statusLabel
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
else|#
directive|else
name|connect
argument_list|(
name|quitButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|buttonLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|buttonLayout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addWidget
argument_list|(
name|quitButton
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|statusLabel
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|buttonLayout
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Threaded Fortune Server"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
end_unit
