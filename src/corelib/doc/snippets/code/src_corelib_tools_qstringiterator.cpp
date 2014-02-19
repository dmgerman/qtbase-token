begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Giuseppe D'Angelo<giuseppe.dangelo@kdab.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QStringIterator>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
block|{
comment|//! [0]
name|QString
name|string
argument_list|(
name|QStringLiteral
argument_list|(
literal|"a string"
argument_list|)
argument_list|)
decl_stmt|;
name|QStringIterator
name|i
argument_list|(
name|string
argument_list|)
decl_stmt|;
comment|//! [0]
comment|//! [1]
comment|// will print 97, 32, 115, 116, etc.;
comment|// that is, the decimal value of the code points in the Unicode string "a string"
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
name|i
operator|.
name|next
argument_list|()
expr_stmt|;
comment|//! [1]
block|}
block|{
comment|//! [2]
name|QString
name|string
argument_list|(
name|QStringLiteral
argument_list|(
literal|"ð is the G clef"
argument_list|)
argument_list|)
decl_stmt|;
name|QStringIterator
name|i
argument_list|(
name|string
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|hex
operator|<<
name|i
operator|.
name|next
argument_list|()
expr_stmt|;
comment|// will print 1d11e (U+1D11E, MUSICAL SYMBOL G CLEF)
name|qDebug
argument_list|()
operator|<<
name|hex
operator|<<
name|i
operator|.
name|next
argument_list|()
expr_stmt|;
comment|// will print 20 (U+0020, SPACE)
name|qDebug
argument_list|()
operator|<<
name|hex
operator|<<
name|i
operator|.
name|next
argument_list|()
expr_stmt|;
comment|// will print 69 (U+0069, LATIN SMALL LETTER I)
comment|//! [2]
block|}
block|}
end_function
end_unit
