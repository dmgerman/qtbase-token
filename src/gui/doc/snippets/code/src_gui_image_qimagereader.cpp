begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|reader
name|QImageReader
name|reader
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|reader
operator|.
name|setFormat
argument_list|(
literal|"png"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// same as reader.setFormat("PNG");
end_comment
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
name|QImageReader
name|reader
argument_list|(
literal|"image.png"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// reader.format() == "png"
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|QImage
name|icon
argument_list|(
literal|64
argument_list|,
literal|64
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QImageReader
name|reader
argument_list|(
literal|"icon_64x64.bmp"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|reader
operator|.
name|read
argument_list|(
operator|&
name|icon
argument_list|)
condition|)
block|{
comment|// Display icon
block|}
end_if
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
name|QImageReader
name|reader
argument_list|(
literal|":/image.png"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|reader
operator|.
name|supportsOption
argument_list|(
name|QImageIOHandler
operator|::
name|Size
argument_list|)
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Size:"
operator|<<
name|reader
operator|.
name|size
argument_list|()
expr_stmt|;
end_if
begin_comment
comment|//! [3]
end_comment
end_unit
