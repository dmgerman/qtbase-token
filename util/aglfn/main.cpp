begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_decl_stmt
DECL|variable|fileVersion
specifier|static
name|QByteArray
name|fileVersion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|glyphNames
specifier|static
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|glyphNames
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|glyphNameOffsets
specifier|static
name|QList
argument_list|<
name|ushort
argument_list|>
name|glyphNameOffsets
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|uni_to_agl_map
specifier|static
name|QMap
argument_list|<
name|ushort
argument_list|,
name|ushort
argument_list|>
name|uni_to_agl_map
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|uni_to_agl_map
comment|// sort by code point for bsearch
end_comment
begin_function
DECL|function|readGlyphList
specifier|static
name|void
name|readGlyphList
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"Reading aglfn.txt:"
argument_list|)
expr_stmt|;
name|QFile
name|f
argument_list|(
literal|"data/aglfn.txt"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|exists
argument_list|()
condition|)
name|qFatal
argument_list|(
literal|"Couldn't find aglfn.txt"
argument_list|)
expr_stmt|;
name|f
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|glyphNames
operator|.
name|append
argument_list|(
literal|".notdef"
argument_list|)
expr_stmt|;
name|glyphNameOffsets
operator|.
name|append
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|uni_to_agl_map
operator|.
name|insert
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|f
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QByteArray
name|line
decl_stmt|;
name|line
operator|.
name|resize
argument_list|(
literal|1024
argument_list|)
expr_stmt|;
name|int
name|len
init|=
name|f
operator|.
name|readLine
argument_list|(
name|line
operator|.
name|data
argument_list|()
argument_list|,
literal|1024
argument_list|)
decl_stmt|;
name|line
operator|.
name|resize
argument_list|(
name|len
operator|-
literal|1
argument_list|)
expr_stmt|;
name|int
name|comment
init|=
name|line
operator|.
name|indexOf
argument_list|(
literal|'#'
argument_list|)
decl_stmt|;
if|if
condition|(
name|comment
operator|!=
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|fileVersion
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|int
name|commentTableVersion
init|=
name|line
operator|.
name|indexOf
argument_list|(
literal|"Table version:"
argument_list|,
name|comment
argument_list|)
decl_stmt|;
if|if
condition|(
name|commentTableVersion
operator|!=
operator|-
literal|1
condition|)
name|fileVersion
operator|=
name|line
operator|.
name|mid
argument_list|(
name|commentTableVersion
operator|+
literal|15
argument_list|)
operator|.
name|trimmed
argument_list|()
expr_stmt|;
block|}
name|line
operator|=
name|line
operator|.
name|left
argument_list|(
name|comment
argument_list|)
expr_stmt|;
block|}
name|line
operator|=
name|line
operator|.
name|trimmed
argument_list|()
expr_stmt|;
if|if
condition|(
name|line
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|l
init|=
name|line
operator|.
name|split
argument_list|(
literal|';'
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|l
operator|.
name|size
argument_list|()
operator|==
literal|3
argument_list|)
expr_stmt|;
name|bool
name|ok
decl_stmt|;
name|ushort
name|codepoint
init|=
name|l
index|[
literal|0
index|]
operator|.
name|toUShort
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|QByteArray
name|glyphName
init|=
name|l
index|[
literal|1
index|]
operator|.
name|trimmed
argument_list|()
decl_stmt|;
name|int
name|glyphIndex
init|=
name|glyphNames
operator|.
name|indexOf
argument_list|(
name|glyphName
argument_list|)
decl_stmt|;
if|if
condition|(
name|glyphIndex
operator|==
operator|-
literal|1
condition|)
block|{
name|glyphIndex
operator|=
name|glyphNames
operator|.
name|size
argument_list|()
expr_stmt|;
name|glyphNameOffsets
operator|.
name|append
argument_list|(
name|glyphNameOffsets
operator|.
name|last
argument_list|()
operator|+
name|glyphNames
operator|.
name|last
argument_list|()
operator|.
name|size
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
name|glyphNames
operator|.
name|append
argument_list|(
name|glyphName
argument_list|)
expr_stmt|;
block|}
name|uni_to_agl_map
operator|.
name|insert
argument_list|(
name|codepoint
argument_list|,
name|glyphIndex
argument_list|)
expr_stmt|;
block|}
name|qDebug
argument_list|(
literal|"    %d unique glyph names found"
argument_list|,
name|glyphNames
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createGlyphList
specifier|static
name|QByteArray
name|createGlyphList
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"createGlyphList:"
argument_list|)
expr_stmt|;
name|QByteArray
name|out
decl_stmt|;
name|out
operator|+=
literal|"static const char glyph_names[] =\n\""
expr_stmt|;
name|int
name|linelen
init|=
literal|2
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|glyphNames
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|linelen
operator|+
name|glyphNames
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|size
argument_list|()
operator|+
literal|2
operator|>=
literal|80
condition|)
block|{
name|linelen
operator|=
literal|2
expr_stmt|;
name|out
operator|+=
literal|"\"\n\""
expr_stmt|;
block|}
name|linelen
operator|+=
name|glyphNames
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|size
argument_list|()
operator|+
literal|2
expr_stmt|;
name|out
operator|+=
name|glyphNames
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|+
literal|"\\0"
expr_stmt|;
block|}
if|if
condition|(
name|out
operator|.
name|endsWith
argument_list|(
literal|"\""
argument_list|)
condition|)
name|out
operator|.
name|chop
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|out
operator|+=
literal|"\"\n;\n\n"
expr_stmt|;
name|out
operator|+=
literal|"struct AGLEntry {\n"
literal|"    unsigned short uc;\n"
literal|"    unsigned short index;\n"
literal|"};\n"
literal|"\n"
literal|"inline bool operator<(unsigned short uc, AGLEntry entry)\n"
literal|"{ return uc< entry.uc; }\n"
literal|"inline bool operator<(AGLEntry entry, unsigned short uc)\n"
literal|"{ return entry.uc< uc; }\n"
literal|"\n"
literal|"static const AGLEntry unicode_to_agl_map[] = {"
expr_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
name|QMap
argument_list|<
name|ushort
argument_list|,
name|ushort
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|uni_to_agl_map
operator|.
name|constBegin
argument_list|()
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|uni_to_agl_map
operator|.
name|constEnd
argument_list|()
condition|)
block|{
if|if
condition|(
name|i
operator|++
operator|%
literal|4
operator|==
literal|0
condition|)
name|out
operator|+=
literal|"\n   "
expr_stmt|;
name|out
operator|+=
literal|" { 0x"
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|it
operator|.
name|key
argument_list|()
argument_list|,
literal|16
argument_list|)
operator|.
name|rightJustified
argument_list|(
literal|4
argument_list|,
literal|'0'
argument_list|)
operator|+
literal|", "
expr_stmt|;
name|out
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|glyphNameOffsets
operator|.
name|at
argument_list|(
name|it
operator|.
name|value
argument_list|()
argument_list|)
argument_list|)
operator|.
name|leftJustified
argument_list|(
literal|4
argument_list|,
literal|' '
argument_list|)
operator|+
literal|" },"
expr_stmt|;
operator|++
name|it
expr_stmt|;
block|}
name|out
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|out
operator|+=
literal|"\n};\n\n"
expr_stmt|;
name|out
operator|+=
literal|"enum { unicode_to_agl_map_size = sizeof(unicode_to_agl_map) / sizeof(unicode_to_agl_map[0]) };\n\n"
expr_stmt|;
name|qDebug
argument_list|(
literal|"    Glyph names list uses : %d bytes"
argument_list|,
name|glyphNameOffsets
operator|.
name|last
argument_list|()
operator|+
name|glyphNames
operator|.
name|last
argument_list|()
operator|.
name|size
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"    Unicode to Glyph names map uses : %d bytes"
argument_list|,
name|uni_to_agl_map
operator|.
name|size
argument_list|()
operator|*
literal|4
argument_list|)
expr_stmt|;
return|return
name|out
return|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
block|{
name|readGlyphList
argument_list|()
expr_stmt|;
name|QByteArray
name|header
init|=
literal|"/****************************************************************************\n"
literal|"**\n"
literal|"** Copyright (C) 2016 The Qt Company Ltd.\n"
literal|"** Contact: https://www.qt.io/licensing/\n"
literal|"**\n"
literal|"** This file is part of the utils of the Qt Toolkit.\n"
literal|"**\n"
literal|"** $QT_BEGIN_LICENSE:LGPL$\n"
literal|"** Commercial License Usage\n"
literal|"** Licensees holding valid commercial Qt licenses may use this file in\n"
literal|"** accordance with the commercial license agreement provided with the\n"
literal|"** Software or, alternatively, in accordance with the terms contained in\n"
literal|"** a written agreement between you and The Qt Company. For licensing terms\n"
literal|"** and conditions see https://www.qt.io/terms-conditions. For further\n"
literal|"** information use the contact form at https://www.qt.io/contact-us.\n"
literal|"**\n"
literal|"** GNU Lesser General Public License Usage\n"
literal|"** Alternatively, this file may be used under the terms of the GNU Lesser\n"
literal|"** General Public License version 3 as published by the Free Software\n"
literal|"** Foundation and appearing in the file LICENSE.LGPL3 included in the\n"
literal|"** packaging of this file. Please review the following information to\n"
literal|"** ensure the GNU Lesser General Public License version 3 requirements\n"
literal|"** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.\n"
literal|"**\n"
literal|"** GNU General Public License Usage\n"
literal|"** Alternatively, this file may be used under the terms of the GNU\n"
literal|"** General Public License version 2.0 or (at your option) the GNU General\n"
literal|"** Public license version 3 or any later version approved by the KDE Free\n"
literal|"** Qt Foundation. The licenses are as published by the Free Software\n"
literal|"** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3\n"
literal|"** included in the packaging of this file. Please review the following\n"
literal|"** information to ensure the GNU General Public License requirements will\n"
literal|"** be met: https://www.gnu.org/licenses/gpl-2.0.html and\n"
literal|"** https://www.gnu.org/licenses/gpl-3.0.html.\n"
literal|"**\n"
literal|"** $QT_END_LICENSE$\n"
literal|"**\n"
literal|"****************************************************************************/\n\n"
decl_stmt|;
name|QByteArray
name|note
init|=
literal|"/* This file is autogenerated from the Adobe Glyph List database"
operator|+
operator|(
operator|!
name|fileVersion
operator|.
name|isEmpty
argument_list|()
condition|?
literal|" v"
operator|+
name|fileVersion
else|:
literal|""
operator|)
operator|+
literal|". Do not edit */\n\n"
decl_stmt|;
name|QFile
name|f
argument_list|(
literal|"../../src/gui/text/qfontsubset_agl.cpp"
argument_list|)
decl_stmt|;
name|f
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Truncate
argument_list|)
expr_stmt|;
name|f
operator|.
name|write
argument_list|(
name|header
argument_list|)
expr_stmt|;
name|f
operator|.
name|write
argument_list|(
name|note
argument_list|)
expr_stmt|;
name|f
operator|.
name|write
argument_list|(
literal|"namespace {\n\n"
argument_list|)
expr_stmt|;
name|f
operator|.
name|write
argument_list|(
name|createGlyphList
argument_list|()
argument_list|)
expr_stmt|;
name|f
operator|.
name|write
argument_list|(
literal|"}\n"
argument_list|)
expr_stmt|;
name|f
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
