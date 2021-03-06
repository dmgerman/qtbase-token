begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Most of the code here was originally written by Serika Kurusugawa
end_comment
begin_comment
comment|// a.k.a. Junji Takagi, and is included in Qt with the author's permission,
end_comment
begin_comment
comment|// and the grateful thanks of the Qt team.
end_comment
begin_comment
comment|/*  * Copyright (C) 1999 Serika Kurusugawa, All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QJPUNICODE_P_H
end_ifndef
begin_define
DECL|macro|QJPUNICODE_P_H
define|#
directive|define
name|QJPUNICODE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_BIG_CODECS
name|class
name|QJpUnicodeConv
block|{
name|public
label|:
name|virtual
operator|~
name|QJpUnicodeConv
argument_list|()
block|{}
expr|enum
name|Rules
block|{
comment|// "ASCII" is ANSI X.3.4-1986, a.k.a. US-ASCII here.
name|Default
operator|=
literal|0x0000
block|,
name|Unicode
operator|=
literal|0x0001
block|,
name|Unicode_JISX0201
operator|=
literal|0x0001
block|,
name|Unicode_ASCII
operator|=
literal|0x0002
block|,
name|JISX0221_JISX0201
operator|=
literal|0x0003
block|,
name|JISX0221_ASCII
operator|=
literal|0x0004
block|,
name|Sun_JDK117
operator|=
literal|0x0005
block|,
name|Microsoft_CP932
operator|=
literal|0x0006
block|,
name|NEC_VDC
operator|=
literal|0x0100
block|,
comment|// NEC Vender Defined Char
name|UDC
operator|=
literal|0x0200
block|,
comment|// User Defined Char
name|IBM_VDC
operator|=
literal|0x0400
comment|// IBM Vender Defined Char
block|}
expr_stmt|;
specifier|static
name|QJpUnicodeConv
modifier|*
name|newConverter
parameter_list|(
name|int
name|rule
parameter_list|)
function_decl|;
name|virtual
name|uint
name|asciiToUnicode
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
comment|/*virtual*/
name|uint
name|jisx0201ToUnicode
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|uint
name|jisx0201LatinToUnicode
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
comment|/*virtual*/
name|uint
name|jisx0201KanaToUnicode
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|uint
name|jisx0208ToUnicode
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|uint
name|jisx0212ToUnicode
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|uint
name|asciiToUnicode
argument_list|(
name|uint
name|ascii
argument_list|)
decl|const
block|{
return|return
name|asciiToUnicode
argument_list|(
operator|(
name|ascii
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|ascii
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|uint
name|jisx0201ToUnicode
argument_list|(
name|uint
name|jis
argument_list|)
decl|const
block|{
return|return
name|jisx0201ToUnicode
argument_list|(
operator|(
name|jis
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|jis
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|uint
name|jisx0201LatinToUnicode
argument_list|(
name|uint
name|jis
argument_list|)
decl|const
block|{
return|return
name|jisx0201LatinToUnicode
argument_list|(
operator|(
name|jis
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|jis
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|uint
name|jisx0201KanaToUnicode
argument_list|(
name|uint
name|jis
argument_list|)
decl|const
block|{
return|return
name|jisx0201KanaToUnicode
argument_list|(
operator|(
name|jis
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|jis
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|uint
name|jisx0208ToUnicode
argument_list|(
name|uint
name|jis
argument_list|)
decl|const
block|{
return|return
name|jisx0208ToUnicode
argument_list|(
operator|(
name|jis
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|jis
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|uint
name|jisx0212ToUnicode
argument_list|(
name|uint
name|jis
argument_list|)
decl|const
block|{
return|return
name|jisx0212ToUnicode
argument_list|(
operator|(
name|jis
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|jis
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|virtual
name|uint
name|unicodeToAscii
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
comment|/*virtual*/
name|uint
name|unicodeToJisx0201
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|uint
name|unicodeToJisx0201Latin
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
comment|/*virtual*/
name|uint
name|unicodeToJisx0201Kana
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|uint
name|unicodeToJisx0208
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|uint
name|unicodeToJisx0212
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|uint
name|unicodeToAscii
argument_list|(
name|uint
name|unicode
argument_list|)
decl|const
block|{
return|return
name|unicodeToAscii
argument_list|(
operator|(
name|unicode
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|unicode
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|uint
name|unicodeToJisx0201
argument_list|(
name|uint
name|unicode
argument_list|)
decl|const
block|{
return|return
name|unicodeToJisx0201
argument_list|(
operator|(
name|unicode
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|unicode
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|uint
name|unicodeToJisx0201Latin
argument_list|(
name|uint
name|unicode
argument_list|)
decl|const
block|{
return|return
name|unicodeToJisx0201Latin
argument_list|(
operator|(
name|unicode
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|unicode
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|uint
name|unicodeToJisx0201Kana
argument_list|(
name|uint
name|unicode
argument_list|)
decl|const
block|{
return|return
name|unicodeToJisx0201Kana
argument_list|(
operator|(
name|unicode
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|unicode
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|uint
name|unicodeToJisx0208
argument_list|(
name|uint
name|unicode
argument_list|)
decl|const
block|{
return|return
name|unicodeToJisx0208
argument_list|(
operator|(
name|unicode
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|unicode
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|uint
name|unicodeToJisx0212
argument_list|(
name|uint
name|unicode
argument_list|)
decl|const
block|{
return|return
name|unicodeToJisx0212
argument_list|(
operator|(
name|unicode
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|unicode
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|uint
name|sjisToUnicode
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|uint
name|unicodeToSjis
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|uint
name|sjisibmvdcToUnicode
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|uint
name|unicodeToSjisibmvdc
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|uint
name|cp932ToUnicode
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|uint
name|unicodeToCp932
argument_list|(
name|uint
name|h
argument_list|,
name|uint
name|l
argument_list|)
decl|const
decl_stmt|;
name|uint
name|sjisToUnicode
argument_list|(
name|uint
name|sjis
argument_list|)
decl|const
block|{
return|return
name|sjisToUnicode
argument_list|(
operator|(
name|sjis
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|sjis
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|uint
name|unicodeToSjis
argument_list|(
name|uint
name|unicode
argument_list|)
decl|const
block|{
return|return
name|unicodeToSjis
argument_list|(
operator|(
name|unicode
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|unicode
operator|&
literal|0x00ff
operator|)
argument_list|)
return|;
block|}
name|protected
label|:
name|explicit
name|QJpUnicodeConv
argument_list|(
argument|int r
argument_list|)
block|:
name|rule
argument_list|(
argument|r
argument_list|)
block|{}
name|private
label|:
name|int
name|rule
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BIG_CODECS
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QJPUNICODE_P_H
end_comment
end_unit
