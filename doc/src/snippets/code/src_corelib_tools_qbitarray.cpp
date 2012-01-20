begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|QBitArray
name|ba
argument_list|(
literal|200
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|ba
name|QBitArray
name|ba
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|ba
operator|.
name|resize
argument_list|(
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|ba
index|[
literal|0
index|]
operator|=
literal|true
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|ba
index|[
literal|1
index|]
operator|=
literal|false
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|ba
index|[
literal|2
index|]
operator|=
literal|true
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|QBitArray
name|ba
argument_list|(
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|ba
operator|.
name|setBit
argument_list|(
literal|0
argument_list|,
literal|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|ba
operator|.
name|setBit
argument_list|(
literal|1
argument_list|,
literal|false
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|ba
operator|.
name|setBit
argument_list|(
literal|2
argument_list|,
literal|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
name|QBitArray
name|x
argument_list|(
literal|5
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|x
operator|.
name|setBit
argument_list|(
literal|3
argument_list|,
literal|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// x: [ 0, 0, 0, 1, 0 ]
end_comment
begin_decl_stmt
name|QBitArray
name|y
argument_list|(
literal|5
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|y
operator|.
name|setBit
argument_list|(
literal|4
argument_list|,
literal|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// y: [ 0, 0, 0, 0, 1 ]
end_comment
begin_expr_stmt
name|x
operator||=
name|y
expr_stmt|;
end_expr_stmt
begin_comment
comment|// x: [ 0, 0, 0, 1, 1 ]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_expr_stmt
name|QBitArray
argument_list|()
operator|.
name|isNull
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true
end_comment
begin_expr_stmt
name|QBitArray
argument_list|()
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true
end_comment
begin_expr_stmt
name|QBitArray
argument_list|(
literal|0
argument_list|)
operator|.
name|isNull
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns false
end_comment
begin_expr_stmt
name|QBitArray
argument_list|(
literal|0
argument_list|)
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true
end_comment
begin_expr_stmt
name|QBitArray
argument_list|(
literal|3
argument_list|)
operator|.
name|isNull
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns false
end_comment
begin_expr_stmt
name|QBitArray
argument_list|(
literal|3
argument_list|)
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns false
end_comment
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_expr_stmt
name|QBitArray
argument_list|()
operator|.
name|isNull
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true
end_comment
begin_expr_stmt
name|QBitArray
argument_list|(
literal|0
argument_list|)
operator|.
name|isNull
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns false
end_comment
begin_expr_stmt
name|QBitArray
argument_list|(
literal|3
argument_list|)
operator|.
name|isNull
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns false
end_comment
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
name|QBitArray
name|ba
argument_list|(
literal|8
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|ba
operator|.
name|fill
argument_list|(
literal|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// ba: [ 1, 1, 1, 1, 1, 1, 1, 1 ]
end_comment
begin_expr_stmt
name|ba
operator|.
name|fill
argument_list|(
literal|false
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// ba: [ 0, 0 ]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_decl_stmt
name|QBitArray
name|a
argument_list|(
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|a
index|[
literal|0
index|]
operator|=
literal|false
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|1
index|]
operator|=
literal|true
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|2
index|]
operator|=
name|a
index|[
literal|0
index|]
operator|^
name|a
index|[
literal|1
index|]
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_decl_stmt
name|QBitArray
name|a
argument_list|(
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBitArray
name|b
argument_list|(
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|a
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|2
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_comment
comment|// a: [ 1, 0, 1 ]
end_comment
begin_expr_stmt
name|b
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|b
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_comment
comment|// b: [ 1, 1 ]
end_comment
begin_expr_stmt
name|a
operator|&=
name|b
expr_stmt|;
end_expr_stmt
begin_comment
comment|// a: [ 1, 0, 0 ]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_decl_stmt
name|QBitArray
name|a
argument_list|(
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBitArray
name|b
argument_list|(
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|a
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|2
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_comment
comment|// a: [ 1, 0, 1 ]
end_comment
begin_expr_stmt
name|b
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|b
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_comment
comment|// b: [ 1, 1 ]
end_comment
begin_expr_stmt
name|a
operator||=
name|b
expr_stmt|;
end_expr_stmt
begin_comment
comment|// a: [ 1, 1, 1 ]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
name|QBitArray
name|a
argument_list|(
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBitArray
name|b
argument_list|(
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|a
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|2
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_comment
comment|// a: [ 1, 0, 1 ]
end_comment
begin_expr_stmt
name|b
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|b
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_comment
comment|// b: [ 1, 1 ]
end_comment
begin_expr_stmt
name|a
operator|^=
name|b
expr_stmt|;
end_expr_stmt
begin_comment
comment|// a: [ 0, 1, 1 ]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
name|QBitArray
name|a
argument_list|(
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|b
name|QBitArray
name|b
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|a
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|2
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_comment
comment|// a: [ 1, 0, 1 ]
end_comment
begin_expr_stmt
name|b
operator|=
operator|~
name|a
expr_stmt|;
end_expr_stmt
begin_comment
comment|// b: [ 0, 1, 0 ]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_decl_stmt
name|QBitArray
name|a
argument_list|(
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBitArray
name|b
argument_list|(
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|c
name|QBitArray
name|c
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|a
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|2
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_comment
comment|// a: [ 1, 0, 1 ]
end_comment
begin_expr_stmt
name|b
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|b
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_comment
comment|// b: [ 1, 1 ]
end_comment
begin_expr_stmt
name|c
operator|=
name|a
operator|&
name|b
expr_stmt|;
end_expr_stmt
begin_comment
comment|// c: [ 1, 0, 0 ]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_decl_stmt
name|QBitArray
name|a
argument_list|(
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBitArray
name|b
argument_list|(
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|c
name|QBitArray
name|c
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|a
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|2
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_comment
comment|// a: [ 1, 0, 1 ]
end_comment
begin_expr_stmt
name|b
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|b
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_comment
comment|// b: [ 1, 1 ]
end_comment
begin_expr_stmt
name|c
operator|=
name|a
operator||
name|b
expr_stmt|;
end_expr_stmt
begin_comment
comment|// c: [ 1, 1, 1 ]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_decl_stmt
name|QBitArray
name|a
argument_list|(
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBitArray
name|b
argument_list|(
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|c
name|QBitArray
name|c
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|a
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
index|[
literal|2
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_comment
comment|// a: [ 1, 0, 1 ]
end_comment
begin_expr_stmt
name|b
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|b
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_comment
comment|// b: [ 1, 1 ]
end_comment
begin_expr_stmt
name|c
operator|=
name|a
operator|^
name|b
expr_stmt|;
end_expr_stmt
begin_comment
comment|// c: [ 0, 1, 1 ]
end_comment
begin_comment
comment|//! [14]
end_comment
end_unit
