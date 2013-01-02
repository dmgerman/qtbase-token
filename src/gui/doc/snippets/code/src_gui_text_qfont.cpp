begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|QFont
name|serifFont
argument_list|(
literal|"Times"
argument_list|,
literal|10
argument_list|,
name|QFont
operator|::
name|Bold
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QFont
name|sansFont
argument_list|(
literal|"Helvetica [Cronyx]"
argument_list|,
literal|12
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
name|QFont
name|f
argument_list|(
literal|"Helvetica"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|QFont
name|f
argument_list|(
literal|"Helvetica [Cronyx]"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function_decl
name|QFontInfo
name|info
parameter_list|(
name|f1
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|family
name|QString
name|family
init|=
name|info
operator|.
name|family
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function_decl
name|QFontMetrics
name|fm
parameter_list|(
name|f1
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|textWidthInPixels
name|int
name|textWidthInPixels
init|=
name|fm
operator|.
name|width
argument_list|(
literal|"How many pixels wide is this text?"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|textHeightInPixels
name|int
name|textHeightInPixels
init|=
name|fm
operator|.
name|height
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [4]
end_comment
end_unit
