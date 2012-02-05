begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_block
block|{
comment|//! [0]
name|QDBusPendingCall
name|async
init|=
name|iface
operator|->
name|asyncCall
argument_list|(
literal|"RemoteMethod"
argument_list|,
name|value1
argument_list|,
name|value2
argument_list|)
decl_stmt|;
name|QDBusPendingCallWatcher
modifier|*
name|watcher
init|=
operator|new
name|QDBusPendingCallWatcher
argument_list|(
name|async
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|(
name|QDBusPendingCallWatcher
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|callFinishedSlot
argument_list|(
name|QDBusPendingCallWatcher
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0]
block|}
end_block
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|callFinishedSlot
name|void
name|MyClass
operator|::
name|callFinishedSlot
parameter_list|(
name|QDBusPendingCallWatcher
modifier|*
name|call
parameter_list|)
block|{
name|QDBusPendingReply
argument_list|<
name|QString
argument_list|,
name|QByteArray
argument_list|>
name|reply
init|=
operator|*
name|call
decl_stmt|;
if|if
condition|(
name|reply
operator|.
name|isError
argument_list|()
condition|)
block|{
name|showError
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QString
name|text
init|=
name|reply
operator|.
name|argumentAt
argument_list|<
literal|0
argument_list|>
argument_list|()
decl_stmt|;
name|QByteArray
name|data
init|=
name|reply
operator|.
name|argumentAt
argument_list|<
literal|1
argument_list|>
argument_list|()
decl_stmt|;
name|showReply
argument_list|(
name|text
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
name|call
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
end_unit
