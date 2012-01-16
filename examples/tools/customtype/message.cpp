begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"message.h"
end_include
begin_comment
comment|//! [Message class implementation]
end_comment
begin_constructor
DECL|function|Message
name|Message
operator|::
name|Message
parameter_list|()
block|{ }
end_constructor
begin_constructor
DECL|function|Message
name|Message
operator|::
name|Message
parameter_list|(
specifier|const
name|Message
modifier|&
name|other
parameter_list|)
block|{
name|m_body
operator|=
name|other
operator|.
name|m_body
expr_stmt|;
name|m_headers
operator|=
name|other
operator|.
name|m_headers
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~Message
name|Message
operator|::
name|~
name|Message
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|//! [Message class implementation]
end_comment
begin_constructor
DECL|function|Message
name|Message
operator|::
name|Message
parameter_list|(
specifier|const
name|QString
modifier|&
name|body
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|headers
parameter_list|)
block|{
name|m_body
operator|=
name|body
expr_stmt|;
name|m_headers
operator|=
name|headers
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [custom type streaming operator]
end_comment
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|Message
modifier|&
name|message
parameter_list|)
block|{
name|QStringList
name|pieces
init|=
name|message
operator|.
name|body
argument_list|()
operator|.
name|split
argument_list|(
literal|"\r\n"
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
decl_stmt|;
if|if
condition|(
name|pieces
operator|.
name|isEmpty
argument_list|()
condition|)
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"Message()"
expr_stmt|;
elseif|else
if|if
condition|(
name|pieces
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"Message("
operator|<<
name|pieces
operator|.
name|first
argument_list|()
operator|<<
literal|")"
expr_stmt|;
else|else
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"Message("
operator|<<
name|pieces
operator|.
name|first
argument_list|()
operator|<<
literal|" ...)"
expr_stmt|;
return|return
name|dbg
operator|.
name|maybeSpace
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [custom type streaming operator]
end_comment
begin_comment
comment|//! [getter functions]
end_comment
begin_function
DECL|function|body
name|QString
name|Message
operator|::
name|body
parameter_list|()
specifier|const
block|{
return|return
name|m_body
return|;
block|}
end_function
begin_function
DECL|function|headers
name|QStringList
name|Message
operator|::
name|headers
parameter_list|()
specifier|const
block|{
return|return
name|m_headers
return|;
block|}
end_function
begin_comment
comment|//! [getter functions]
end_comment
end_unit
