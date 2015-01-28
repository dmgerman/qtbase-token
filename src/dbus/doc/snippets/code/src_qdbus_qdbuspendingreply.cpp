begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_block
block|{
comment|//! [0]
name|QDBusPendingReply
argument_list|<
name|QString
argument_list|>
name|reply
init|=
name|interface
operator|->
name|asyncCall
argument_list|(
literal|"RemoteMethod"
argument_list|)
decl_stmt|;
name|reply
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
if|if
condition|(
name|reply
operator|.
name|isError
argument_list|()
condition|)
comment|// call failed. Show an error condition.
name|showError
argument_list|(
name|reply
operator|.
name|error
argument_list|()
argument_list|)
expr_stmt|;
else|else
comment|// use the returned value
name|useValue
argument_list|(
name|reply
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [2]
name|QDBusPendingReply
argument_list|<
name|bool
argument_list|,
name|QString
argument_list|>
name|reply
init|=
name|interface
operator|->
name|asyncCall
argument_list|(
literal|"RemoteMethod"
argument_list|)
decl_stmt|;
name|reply
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|reply
operator|.
name|isError
argument_list|()
condition|)
block|{
if|if
condition|(
name|reply
operator|.
name|argumentAt
argument_list|<
literal|0
argument_list|>
argument_list|()
condition|)
name|showSuccess
argument_list|(
name|reply
operator|.
name|argumentAt
argument_list|<
literal|1
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|showFailure
argument_list|(
name|reply
operator|.
name|argumentAt
argument_list|<
literal|1
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|//! [2]
block|}
end_block
end_unit
