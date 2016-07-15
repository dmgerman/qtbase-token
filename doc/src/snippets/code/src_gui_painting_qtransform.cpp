begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_expr_stmt
name|x
literal|' = m11*x + m21*y + dx y'
operator|=
name|m22
operator|*
name|y
operator|+
name|m12
operator|*
name|x
operator|+
name|dy
end_expr_stmt
begin_if
if|if
condition|(
name|is
operator|not
name|affine
condition|)
block|{
name|w
literal|' = m13*x + m23*y + m33     x'
operator|/=
name|w
literal|'     y'
operator|/=
name|w
literal|' } //! [0]   //! [1] x'
operator|=
name|m11
operator|*
name|x
operator|+
name|m21
operator|*
name|y
operator|+
name|dx
name|y
literal|' = m22*y + m12*x + dy if (is not affine) {     w'
operator|=
name|m13
operator|*
name|x
operator|+
name|m23
operator|*
name|y
operator|+
name|m33
name|x
literal|' /= w'
name|y
literal|' /= w'
block|}
end_if
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_expr_stmt
name|x
literal|' = m11*x + m21*y + dx y'
operator|=
name|m22
operator|*
name|y
operator|+
name|m12
operator|*
name|x
operator|+
name|dy
end_expr_stmt
begin_if
if|if
condition|(
name|is
operator|not
name|affine
condition|)
block|{
name|w
literal|' = m13*x + m23*y + m33     x'
operator|/=
name|w
literal|'     y'
operator|/=
name|w
literal|' } //! [2]   //! [3] x'
operator|=
name|m11
operator|*
name|x
operator|+
name|m21
operator|*
name|y
operator|+
name|dx
name|y
literal|' = m22*y + m12*x + dy if (is not affine) {     w'
operator|=
name|m13
operator|*
name|x
operator|+
name|m23
operator|*
name|y
operator|+
name|m33
name|x
literal|' /= w'
name|y
literal|' /= w'
block|}
end_if
begin_comment
comment|//! [3]
end_comment
end_unit
