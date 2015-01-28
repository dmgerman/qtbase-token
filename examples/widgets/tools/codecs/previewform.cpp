begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"previewform.h"
end_include
begin_constructor
DECL|function|PreviewForm
name|PreviewForm
operator|::
name|PreviewForm
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
block|{
name|encodingComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|encodingLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Encoding:"
argument_list|)
argument_list|)
expr_stmt|;
name|encodingLabel
operator|->
name|setBuddy
argument_list|(
name|encodingComboBox
argument_list|)
expr_stmt|;
name|textEdit
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|textEdit
operator|->
name|setLineWrapMode
argument_list|(
name|QTextEdit
operator|::
name|NoWrap
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
operator|new
name|QDialogButtonBox
argument_list|(
name|QDialogButtonBox
operator|::
name|Ok
operator||
name|QDialogButtonBox
operator|::
name|Cancel
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|encodingComboBox
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
name|updateTextEdit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|accept
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|reject
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|encodingLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|encodingComboBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|textEdit
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Choose Encoding"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|400
argument_list|,
literal|300
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setCodecList
name|void
name|PreviewForm
operator|::
name|setCodecList
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QTextCodec
modifier|*
argument_list|>
modifier|&
name|list
parameter_list|)
block|{
name|encodingComboBox
operator|->
name|clear
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|QTextCodec
modifier|*
name|codec
decl|,
name|list
control|)
name|encodingComboBox
operator|->
name|addItem
argument_list|(
name|codec
operator|->
name|name
argument_list|()
argument_list|,
name|codec
operator|->
name|mibEnum
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setEncodedData
name|void
name|PreviewForm
operator|::
name|setEncodedData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|encodedData
operator|=
name|data
expr_stmt|;
name|updateTextEdit
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateTextEdit
name|void
name|PreviewForm
operator|::
name|updateTextEdit
parameter_list|()
block|{
name|int
name|mib
init|=
name|encodingComboBox
operator|->
name|itemData
argument_list|(
name|encodingComboBox
operator|->
name|currentIndex
argument_list|()
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|QTextCodec
modifier|*
name|codec
init|=
name|QTextCodec
operator|::
name|codecForMib
argument_list|(
name|mib
argument_list|)
decl_stmt|;
name|QTextStream
name|in
argument_list|(
operator|&
name|encodedData
argument_list|)
decl_stmt|;
name|in
operator|.
name|setAutoDetectUnicode
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|in
operator|.
name|setCodec
argument_list|(
name|codec
argument_list|)
expr_stmt|;
name|decodedStr
operator|=
name|in
operator|.
name|readAll
argument_list|()
expr_stmt|;
name|textEdit
operator|->
name|setPlainText
argument_list|(
name|decodedStr
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
