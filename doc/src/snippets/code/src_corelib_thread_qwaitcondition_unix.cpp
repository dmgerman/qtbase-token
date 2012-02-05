begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_forever
forever|forever
block|{
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|keyPressed
operator|.
name|wait
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
name|do_something
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
end_forever
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_forever
forever|forever
block|{
name|getchar
argument_list|()
expr_stmt|;
name|keyPressed
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
block|}
end_forever
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_forever
forever|forever
block|{
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|keyPressed
operator|.
name|wait
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
operator|++
name|count
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|do_something
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
operator|--
name|count
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
end_forever
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_forever
forever|forever
block|{
name|getchar
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
comment|// Sleep until there are no busy worker threads
while|while
condition|(
name|count
operator|>
literal|0
condition|)
block|{
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
block|}
name|keyPressed
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
end_forever
begin_comment
comment|//! [3]
end_comment
end_unit
