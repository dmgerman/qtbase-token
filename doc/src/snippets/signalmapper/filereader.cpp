begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"filereader.h"
end_include
begin_constructor
DECL|function|FileReader
name|FileReader
operator|::
name|FileReader
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
name|textEdit
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|taxFileButton
operator|=
operator|new
name|QPushButton
argument_list|(
literal|"Tax File"
argument_list|)
expr_stmt|;
name|accountFileButton
operator|=
operator|new
name|QPushButton
argument_list|(
literal|"Accounts File"
argument_list|)
expr_stmt|;
name|reportFileButton
operator|=
operator|new
name|QPushButton
argument_list|(
literal|"Report File"
argument_list|)
expr_stmt|;
comment|//! [0]
name|signalMapper
operator|=
operator|new
name|QSignalMapper
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|signalMapper
operator|->
name|setMapping
argument_list|(
name|taxFileButton
argument_list|,
name|QString
argument_list|(
literal|"taxfile.txt"
argument_list|)
argument_list|)
expr_stmt|;
name|signalMapper
operator|->
name|setMapping
argument_list|(
name|accountFileButton
argument_list|,
name|QString
argument_list|(
literal|"accountsfile.txt"
argument_list|)
argument_list|)
expr_stmt|;
name|signalMapper
operator|->
name|setMapping
argument_list|(
name|reportFileButton
argument_list|,
name|QString
argument_list|(
literal|"reportfile.txt"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|taxFileButton
argument_list|,
operator|&
name|QPushButton
operator|::
name|clicked
argument_list|,
name|signalMapper
argument_list|,
operator|&
name|QSignalMapper
operator|::
name|map
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|accountFileButton
argument_list|,
operator|&
name|QPushButton
operator|::
name|clicked
argument_list|,
name|signalMapper
argument_list|,
operator|&
name|QSignalMapper
operator|::
name|map
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|reportFileButton
argument_list|,
operator|&
name|QPushButton
operator|::
name|clicked
argument_list|,
name|signalMapper
argument_list|,
operator|&
name|QSignalMapper
operator|::
name|map
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|connect
argument_list|(
name|signalMapper
argument_list|,
name|SIGNAL
argument_list|(
name|mapped
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readFile
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1]
comment|/* //! [2]     //slower due to signature normalization at runtime          connect(signalMapper, SIGNAL(mapped(const QString&)),         this, SLOT(readFile(const QString&))); //! [2] */
name|QHBoxLayout
modifier|*
name|buttonLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|buttonLayout
operator|->
name|addWidget
argument_list|(
name|taxFileButton
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addWidget
argument_list|(
name|accountFileButton
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addWidget
argument_list|(
name|reportFileButton
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
name|textEdit
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
block|}
end_constructor
begin_function
DECL|function|readFile
name|void
name|FileReader
operator|::
name|readFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|filename
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Unable to open file"
argument_list|)
argument_list|,
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|QTextStream
name|in
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|textEdit
operator|->
name|setPlainText
argument_list|(
name|in
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
