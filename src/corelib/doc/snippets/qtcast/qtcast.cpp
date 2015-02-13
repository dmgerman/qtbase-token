begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|"qtcast.h"
end_include
begin_constructor
DECL|function|MyWidget
name|MyWidget
operator|::
name|MyWidget
parameter_list|()
block|{
comment|//! [0]
name|QObject
modifier|*
name|obj
init|=
operator|new
name|MyWidget
decl_stmt|;
comment|//! [0]
comment|//! [1]
name|QWidget
modifier|*
name|widget
init|=
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|obj
argument_list|)
decl_stmt|;
comment|//! [1]
comment|//! [2]
name|MyWidget
modifier|*
name|myWidget
init|=
name|qobject_cast
argument_list|<
name|MyWidget
operator|*
argument_list|>
argument_list|(
name|obj
argument_list|)
decl_stmt|;
comment|//! [2]
comment|//! [3]
name|QLabel
modifier|*
name|label
init|=
name|qobject_cast
argument_list|<
name|QLabel
operator|*
argument_list|>
argument_list|(
name|obj
argument_list|)
decl_stmt|;
comment|//! [3] //! [4]
comment|// label is 0
comment|//! [4]
comment|//! [5]
if|if
condition|(
name|QLabel
modifier|*
name|label
init|=
name|qobject_cast
argument_list|<
name|QLabel
operator|*
argument_list|>
argument_list|(
name|obj
argument_list|)
condition|)
block|{
comment|//! [5] //! [6]
name|label
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Ping"
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|QPushButton
modifier|*
name|button
init|=
name|qobject_cast
argument_list|<
name|QPushButton
operator|*
argument_list|>
argument_list|(
name|obj
argument_list|)
condition|)
block|{
name|button
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Pong!"
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//! [6]
block|}
end_constructor
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
end_unit
