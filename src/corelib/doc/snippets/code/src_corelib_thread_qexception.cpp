begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_class
DECL|class|MyException
class|class
name|MyException
super|:
specifier|public
name|QException
block|{
public|public:
DECL|function|raise
name|void
name|raise
parameter_list|()
specifier|const
block|{
throw|throw
operator|*
name|this
throw|;
block|}
DECL|function|clone
name|MyException
modifier|*
name|clone
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|MyException
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_try
try|try
block|{
name|QtConcurrent
operator|::
name|blockingMap
argument_list|(
name|list
argument_list|,
name|throwFunction
argument_list|)
expr_stmt|;
comment|// throwFunction throws MyException
block|}
catch|catch
parameter_list|(
name|MyException
modifier|&
name|e
parameter_list|)
block|{
comment|// handle exception
block|}
end_try
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|raise
name|void
name|MyException
operator|::
name|raise
parameter_list|()
specifier|const
block|{
throw|throw
operator|*
name|this
throw|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|clone
name|MyException
modifier|*
name|MyException
operator|::
name|clone
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|MyException
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
end_unit
