begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"numberformats.h"
end_include
begin_include
include|#
directive|include
file|<QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QLocale>
end_include
begin_include
include|#
directive|include
file|<QVBoxLayout>
end_include
begin_constructor
DECL|function|NumberFormatsWidget
name|NumberFormatsWidget
operator|::
name|NumberFormatsWidget
parameter_list|()
block|{
name|QGridLayout
modifier|*
name|l
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|QLabel
modifier|*
name|numbersLabel
init|=
operator|new
name|QLabel
argument_list|(
literal|"Numbers:"
argument_list|)
decl_stmt|;
name|number1
operator|=
name|createLineEdit
argument_list|()
expr_stmt|;
name|number2
operator|=
name|createLineEdit
argument_list|()
expr_stmt|;
name|number3
operator|=
name|createLineEdit
argument_list|()
expr_stmt|;
name|measurementLabel
operator|=
operator|new
name|QLabel
argument_list|(
literal|"Measurement units:"
argument_list|)
expr_stmt|;
name|measurementSystem
operator|=
name|createLineEdit
argument_list|()
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|numbersLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|number1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|number2
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|number3
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|measurementLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|measurementSystem
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|v
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|v
operator|->
name|addLayout
argument_list|(
name|l
argument_list|)
expr_stmt|;
name|v
operator|->
name|addStretch
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|localeChanged
name|void
name|NumberFormatsWidget
operator|::
name|localeChanged
parameter_list|(
name|QLocale
name|locale
parameter_list|)
block|{
name|number1
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|toString
argument_list|(
operator|-
literal|123456
argument_list|)
argument_list|)
expr_stmt|;
name|number2
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|toString
argument_list|(
literal|1234.56
argument_list|,
literal|'f'
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|number3
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|toString
argument_list|(
literal|1234.56
argument_list|,
literal|'e'
argument_list|,
literal|4
argument_list|)
argument_list|)
expr_stmt|;
name|measurementSystem
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|measurementSystem
argument_list|()
operator|==
name|QLocale
operator|::
name|ImperialSystem
condition|?
literal|"US"
else|:
literal|"Metric"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createLineEdit
name|QLineEdit
modifier|*
name|NumberFormatsWidget
operator|::
name|createLineEdit
parameter_list|()
block|{
name|QLineEdit
modifier|*
name|le
init|=
operator|new
name|QLineEdit
decl_stmt|;
name|le
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
return|return
name|le
return|;
block|}
end_function
end_unit
