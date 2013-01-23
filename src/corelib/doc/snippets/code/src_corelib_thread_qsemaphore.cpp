begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|QSemaphore
name|sem
argument_list|(
literal|5
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// sem.available() == 5
end_comment
begin_expr_stmt
name|sem
operator|.
name|acquire
argument_list|(
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// sem.available() == 2
end_comment
begin_expr_stmt
name|sem
operator|.
name|acquire
argument_list|(
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// sem.available() == 0
end_comment
begin_expr_stmt
name|sem
operator|.
name|release
argument_list|(
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// sem.available() == 5
end_comment
begin_expr_stmt
name|sem
operator|.
name|release
argument_list|(
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// sem.available() == 10
end_comment
begin_expr_stmt
name|sem
operator|.
name|tryAcquire
argument_list|(
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// sem.available() == 9, returns true
end_comment
begin_expr_stmt
name|sem
operator|.
name|tryAcquire
argument_list|(
literal|250
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// sem.available() == 9, returns false
end_comment
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
name|QSemaphore
name|sem
argument_list|(
literal|5
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// a semaphore that guards 5 resources
end_comment
begin_expr_stmt
name|sem
operator|.
name|acquire
argument_list|(
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// acquire all 5 resources
end_comment
begin_expr_stmt
name|sem
operator|.
name|release
argument_list|(
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// release the 5 resources
end_comment
begin_expr_stmt
name|sem
operator|.
name|release
argument_list|(
literal|10
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// "create" 10 new resources
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|QSemaphore
name|sem
argument_list|(
literal|5
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// sem.available() == 5
end_comment
begin_expr_stmt
name|sem
operator|.
name|tryAcquire
argument_list|(
literal|250
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// sem.available() == 5, returns false
end_comment
begin_expr_stmt
name|sem
operator|.
name|tryAcquire
argument_list|(
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// sem.available() == 2, returns true
end_comment
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
name|QSemaphore
name|sem
argument_list|(
literal|5
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// sem.available() == 5
end_comment
begin_expr_stmt
name|sem
operator|.
name|tryAcquire
argument_list|(
literal|250
argument_list|,
literal|1000
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// sem.available() == 5, waits 1000 milliseconds and returns false
end_comment
begin_expr_stmt
name|sem
operator|.
name|tryAcquire
argument_list|(
literal|3
argument_list|,
literal|30000
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// sem.available() == 2, returns true without waiting
end_comment
begin_comment
comment|//! [3]
end_comment
end_unit
