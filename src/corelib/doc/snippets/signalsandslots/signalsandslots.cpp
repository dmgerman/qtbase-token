begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"signalsandslots.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|setValue
name|void
name|Counter
operator|::
name|setValue
parameter_list|(
name|int
name|value
parameter_list|)
block|{
if|if
condition|(
name|value
operator|!=
name|m_value
condition|)
block|{
name|m_value
operator|=
name|value
expr_stmt|;
emit|emit
name|valueChanged
argument_list|(
name|value
argument_list|)
emit|;
block|}
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
comment|//! [1]
name|Counter
name|a
decl_stmt|,
name|b
decl_stmt|;
comment|//! [1] //! [2]
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|Counter
operator|::
name|valueChanged
argument_list|,
operator|&
name|b
argument_list|,
operator|&
name|Counter
operator|::
name|setValue
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|a
operator|.
name|setValue
argument_list|(
literal|12
argument_list|)
expr_stmt|;
comment|// a.value() == 12, b.value() == 12
comment|//! [3] //! [4]
name|b
operator|.
name|setValue
argument_list|(
literal|48
argument_list|)
expr_stmt|;
comment|// a.value() == 12, b.value() == 48
comment|//! [4]
block|}
end_function
end_unit
