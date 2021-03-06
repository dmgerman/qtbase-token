begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttpost.c                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Postcript name table processing for TrueType and OpenType fonts      */
end_comment
begin_comment
comment|/*    (body).                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2015 by                                                 */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
end_comment
begin_comment
comment|/*  this file you indicate that you have read the license and              */
end_comment
begin_comment
comment|/*  understand and accept it fully.                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The post table is not completely loaded by the core engine.  This     */
end_comment
begin_comment
comment|/* file loads the missing PS glyph names and implements an API to access */
end_comment
begin_comment
comment|/* them.                                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_TAGS_H
end_include
begin_include
include|#
directive|include
file|"ttpost.h"
end_include
begin_include
include|#
directive|include
file|"sferrors.h"
end_include
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The macro FT_COMPONENT is used in trace mode.  It is an implicit      */
end_comment
begin_comment
comment|/* parameter of the FT_TRACE() and FT_ERROR() macros, used to print/log  */
end_comment
begin_comment
comment|/* messages during execution.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_undef
DECL|macro|FT_COMPONENT
undef|#
directive|undef
name|FT_COMPONENT
end_undef
begin_define
DECL|macro|FT_COMPONENT
define|#
directive|define
name|FT_COMPONENT
value|trace_ttpost
end_define
begin_comment
comment|/* If this configuration macro is defined, we rely on the `PSNames' */
end_comment
begin_comment
comment|/* module to grab the glyph names.                                  */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_POSTSCRIPT_NAMES
end_ifdef
begin_include
include|#
directive|include
include|FT_SERVICE_POSTSCRIPT_CMAPS_H
end_include
begin_define
DECL|macro|MAC_NAME
define|#
directive|define
name|MAC_NAME
parameter_list|(
name|x
parameter_list|)
value|(FT_String*)psnames->macintosh_name( (FT_UInt)(x) )
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_POSTSCRIPT_NAMES */
end_comment
begin_comment
comment|/* Otherwise, we ignore the `PSNames' module, and provide our own  */
end_comment
begin_comment
comment|/* table of Mac names.  Thus, it is possible to build a version of */
end_comment
begin_comment
comment|/* FreeType without the Type 1 driver& PSNames module.            */
end_comment
begin_define
DECL|macro|MAC_NAME
define|#
directive|define
name|MAC_NAME
parameter_list|(
name|x
parameter_list|)
value|(FT_String*)tt_post_default_names[x]
end_define
begin_comment
comment|/* the 258 default Mac PS glyph names; see file `tools/glnames.py' */
end_comment
begin_decl_stmt
DECL|variable|tt_post_default_names
specifier|static
specifier|const
name|FT_String
modifier|*
specifier|const
name|tt_post_default_names
index|[
literal|258
index|]
init|=
block|{
comment|/*   0 */
literal|".notdef"
block|,
literal|".null"
block|,
literal|"nonmarkingreturn"
block|,
literal|"space"
block|,
literal|"exclam"
block|,
literal|"quotedbl"
block|,
literal|"numbersign"
block|,
literal|"dollar"
block|,
literal|"percent"
block|,
literal|"ampersand"
block|,
comment|/*  10 */
literal|"quotesingle"
block|,
literal|"parenleft"
block|,
literal|"parenright"
block|,
literal|"asterisk"
block|,
literal|"plus"
block|,
literal|"comma"
block|,
literal|"hyphen"
block|,
literal|"period"
block|,
literal|"slash"
block|,
literal|"zero"
block|,
comment|/*  20 */
literal|"one"
block|,
literal|"two"
block|,
literal|"three"
block|,
literal|"four"
block|,
literal|"five"
block|,
literal|"six"
block|,
literal|"seven"
block|,
literal|"eight"
block|,
literal|"nine"
block|,
literal|"colon"
block|,
comment|/*  30 */
literal|"semicolon"
block|,
literal|"less"
block|,
literal|"equal"
block|,
literal|"greater"
block|,
literal|"question"
block|,
literal|"at"
block|,
literal|"A"
block|,
literal|"B"
block|,
literal|"C"
block|,
literal|"D"
block|,
comment|/*  40 */
literal|"E"
block|,
literal|"F"
block|,
literal|"G"
block|,
literal|"H"
block|,
literal|"I"
block|,
literal|"J"
block|,
literal|"K"
block|,
literal|"L"
block|,
literal|"M"
block|,
literal|"N"
block|,
comment|/*  50 */
literal|"O"
block|,
literal|"P"
block|,
literal|"Q"
block|,
literal|"R"
block|,
literal|"S"
block|,
literal|"T"
block|,
literal|"U"
block|,
literal|"V"
block|,
literal|"W"
block|,
literal|"X"
block|,
comment|/*  60 */
literal|"Y"
block|,
literal|"Z"
block|,
literal|"bracketleft"
block|,
literal|"backslash"
block|,
literal|"bracketright"
block|,
literal|"asciicircum"
block|,
literal|"underscore"
block|,
literal|"grave"
block|,
literal|"a"
block|,
literal|"b"
block|,
comment|/*  70 */
literal|"c"
block|,
literal|"d"
block|,
literal|"e"
block|,
literal|"f"
block|,
literal|"g"
block|,
literal|"h"
block|,
literal|"i"
block|,
literal|"j"
block|,
literal|"k"
block|,
literal|"l"
block|,
comment|/*  80 */
literal|"m"
block|,
literal|"n"
block|,
literal|"o"
block|,
literal|"p"
block|,
literal|"q"
block|,
literal|"r"
block|,
literal|"s"
block|,
literal|"t"
block|,
literal|"u"
block|,
literal|"v"
block|,
comment|/*  90 */
literal|"w"
block|,
literal|"x"
block|,
literal|"y"
block|,
literal|"z"
block|,
literal|"braceleft"
block|,
literal|"bar"
block|,
literal|"braceright"
block|,
literal|"asciitilde"
block|,
literal|"Adieresis"
block|,
literal|"Aring"
block|,
comment|/* 100 */
literal|"Ccedilla"
block|,
literal|"Eacute"
block|,
literal|"Ntilde"
block|,
literal|"Odieresis"
block|,
literal|"Udieresis"
block|,
literal|"aacute"
block|,
literal|"agrave"
block|,
literal|"acircumflex"
block|,
literal|"adieresis"
block|,
literal|"atilde"
block|,
comment|/* 110 */
literal|"aring"
block|,
literal|"ccedilla"
block|,
literal|"eacute"
block|,
literal|"egrave"
block|,
literal|"ecircumflex"
block|,
literal|"edieresis"
block|,
literal|"iacute"
block|,
literal|"igrave"
block|,
literal|"icircumflex"
block|,
literal|"idieresis"
block|,
comment|/* 120 */
literal|"ntilde"
block|,
literal|"oacute"
block|,
literal|"ograve"
block|,
literal|"ocircumflex"
block|,
literal|"odieresis"
block|,
literal|"otilde"
block|,
literal|"uacute"
block|,
literal|"ugrave"
block|,
literal|"ucircumflex"
block|,
literal|"udieresis"
block|,
comment|/* 130 */
literal|"dagger"
block|,
literal|"degree"
block|,
literal|"cent"
block|,
literal|"sterling"
block|,
literal|"section"
block|,
literal|"bullet"
block|,
literal|"paragraph"
block|,
literal|"germandbls"
block|,
literal|"registered"
block|,
literal|"copyright"
block|,
comment|/* 140 */
literal|"trademark"
block|,
literal|"acute"
block|,
literal|"dieresis"
block|,
literal|"notequal"
block|,
literal|"AE"
block|,
literal|"Oslash"
block|,
literal|"infinity"
block|,
literal|"plusminus"
block|,
literal|"lessequal"
block|,
literal|"greaterequal"
block|,
comment|/* 150 */
literal|"yen"
block|,
literal|"mu"
block|,
literal|"partialdiff"
block|,
literal|"summation"
block|,
literal|"product"
block|,
literal|"pi"
block|,
literal|"integral"
block|,
literal|"ordfeminine"
block|,
literal|"ordmasculine"
block|,
literal|"Omega"
block|,
comment|/* 160 */
literal|"ae"
block|,
literal|"oslash"
block|,
literal|"questiondown"
block|,
literal|"exclamdown"
block|,
literal|"logicalnot"
block|,
literal|"radical"
block|,
literal|"florin"
block|,
literal|"approxequal"
block|,
literal|"Delta"
block|,
literal|"guillemotleft"
block|,
comment|/* 170 */
literal|"guillemotright"
block|,
literal|"ellipsis"
block|,
literal|"nonbreakingspace"
block|,
literal|"Agrave"
block|,
literal|"Atilde"
block|,
literal|"Otilde"
block|,
literal|"OE"
block|,
literal|"oe"
block|,
literal|"endash"
block|,
literal|"emdash"
block|,
comment|/* 180 */
literal|"quotedblleft"
block|,
literal|"quotedblright"
block|,
literal|"quoteleft"
block|,
literal|"quoteright"
block|,
literal|"divide"
block|,
literal|"lozenge"
block|,
literal|"ydieresis"
block|,
literal|"Ydieresis"
block|,
literal|"fraction"
block|,
literal|"currency"
block|,
comment|/* 190 */
literal|"guilsinglleft"
block|,
literal|"guilsinglright"
block|,
literal|"fi"
block|,
literal|"fl"
block|,
literal|"daggerdbl"
block|,
literal|"periodcentered"
block|,
literal|"quotesinglbase"
block|,
literal|"quotedblbase"
block|,
literal|"perthousand"
block|,
literal|"Acircumflex"
block|,
comment|/* 200 */
literal|"Ecircumflex"
block|,
literal|"Aacute"
block|,
literal|"Edieresis"
block|,
literal|"Egrave"
block|,
literal|"Iacute"
block|,
literal|"Icircumflex"
block|,
literal|"Idieresis"
block|,
literal|"Igrave"
block|,
literal|"Oacute"
block|,
literal|"Ocircumflex"
block|,
comment|/* 210 */
literal|"apple"
block|,
literal|"Ograve"
block|,
literal|"Uacute"
block|,
literal|"Ucircumflex"
block|,
literal|"Ugrave"
block|,
literal|"dotlessi"
block|,
literal|"circumflex"
block|,
literal|"tilde"
block|,
literal|"macron"
block|,
literal|"breve"
block|,
comment|/* 220 */
literal|"dotaccent"
block|,
literal|"ring"
block|,
literal|"cedilla"
block|,
literal|"hungarumlaut"
block|,
literal|"ogonek"
block|,
literal|"caron"
block|,
literal|"Lslash"
block|,
literal|"lslash"
block|,
literal|"Scaron"
block|,
literal|"scaron"
block|,
comment|/* 230 */
literal|"Zcaron"
block|,
literal|"zcaron"
block|,
literal|"brokenbar"
block|,
literal|"Eth"
block|,
literal|"eth"
block|,
literal|"Yacute"
block|,
literal|"yacute"
block|,
literal|"Thorn"
block|,
literal|"thorn"
block|,
literal|"minus"
block|,
comment|/* 240 */
literal|"multiply"
block|,
literal|"onesuperior"
block|,
literal|"twosuperior"
block|,
literal|"threesuperior"
block|,
literal|"onehalf"
block|,
literal|"onequarter"
block|,
literal|"threequarters"
block|,
literal|"franc"
block|,
literal|"Gbreve"
block|,
literal|"gbreve"
block|,
comment|/* 250 */
literal|"Idotaccent"
block|,
literal|"Scedilla"
block|,
literal|"scedilla"
block|,
literal|"Cacute"
block|,
literal|"cacute"
block|,
literal|"Ccaron"
block|,
literal|"ccaron"
block|,
literal|"dcroat"
block|,   }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_POSTSCRIPT_NAMES */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|load_format_20
name|load_format_20
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_Stream
name|stream
parameter_list|,
name|FT_ULong
name|post_limit
parameter_list|)
block|{
name|FT_Memory
name|memory
init|=
name|stream
operator|->
name|memory
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|FT_Int
name|num_glyphs
decl_stmt|;
name|FT_UShort
name|num_names
decl_stmt|;
name|FT_UShort
modifier|*
name|glyph_indices
init|=
name|NULL
decl_stmt|;
name|FT_Char
modifier|*
modifier|*
name|name_strings
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|FT_READ_USHORT
argument_list|(
name|num_glyphs
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
comment|/* UNDOCUMENTED!  The number of glyphs in this table can be smaller */
comment|/* than the value in the maxp table (cf. cyberbit.ttf).             */
comment|/* There already exist fonts which have more than 32768 glyph names */
comment|/* in this table, so the test for this threshold has been dropped.  */
if|if
condition|(
name|num_glyphs
operator|>
name|face
operator|->
name|max_profile
operator|.
name|numGlyphs
condition|)
block|{
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_File_Format
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
comment|/* load the indices */
block|{
name|FT_Int
name|n
decl_stmt|;
if|if
condition|(
name|FT_NEW_ARRAY
argument_list|(
name|glyph_indices
argument_list|,
name|num_glyphs
argument_list|)
operator|||
name|FT_FRAME_ENTER
argument_list|(
name|num_glyphs
operator|*
literal|2L
argument_list|)
condition|)
goto|goto
name|Fail
goto|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|num_glyphs
condition|;
name|n
operator|++
control|)
name|glyph_indices
index|[
name|n
index|]
operator|=
name|FT_GET_USHORT
argument_list|()
expr_stmt|;
name|FT_FRAME_EXIT
argument_list|()
expr_stmt|;
block|}
comment|/* compute number of names stored in table */
block|{
name|FT_Int
name|n
decl_stmt|;
name|num_names
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|num_glyphs
condition|;
name|n
operator|++
control|)
block|{
name|FT_Int
name|idx
decl_stmt|;
name|idx
operator|=
name|glyph_indices
index|[
name|n
index|]
expr_stmt|;
if|if
condition|(
name|idx
operator|>=
literal|258
condition|)
block|{
name|idx
operator|-=
literal|257
expr_stmt|;
if|if
condition|(
name|idx
operator|>
name|num_names
condition|)
name|num_names
operator|=
operator|(
name|FT_UShort
operator|)
name|idx
expr_stmt|;
block|}
block|}
block|}
comment|/* now load the name strings */
block|{
name|FT_UShort
name|n
decl_stmt|;
if|if
condition|(
name|FT_NEW_ARRAY
argument_list|(
name|name_strings
argument_list|,
name|num_names
argument_list|)
condition|)
goto|goto
name|Fail
goto|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|num_names
condition|;
name|n
operator|++
control|)
block|{
name|FT_UInt
name|len
decl_stmt|;
if|if
condition|(
name|FT_STREAM_POS
argument_list|()
operator|>=
name|post_limit
condition|)
break|break;
else|else
block|{
name|FT_TRACE6
argument_list|(
operator|(
literal|"load_format_20: %d byte left in post table\n"
operator|,
name|post_limit
operator|-
name|FT_STREAM_POS
argument_list|()
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|FT_READ_BYTE
argument_list|(
name|len
argument_list|)
condition|)
goto|goto
name|Fail1
goto|;
block|}
if|if
condition|(
name|len
operator|>
name|post_limit
operator|||
name|FT_STREAM_POS
argument_list|()
operator|>
name|post_limit
operator|-
name|len
condition|)
block|{
name|FT_Int
name|d
init|=
operator|(
name|FT_Int
operator|)
name|post_limit
operator|-
operator|(
name|FT_Int
operator|)
name|FT_STREAM_POS
argument_list|()
decl_stmt|;
name|FT_ERROR
argument_list|(
operator|(
literal|"load_format_20:"
literal|" exceeding string length (%d),"
literal|" truncating at end of post table (%d byte left)\n"
operator|,
name|len
operator|,
name|d
operator|)
argument_list|)
expr_stmt|;
name|len
operator|=
operator|(
name|FT_UInt
operator|)
name|FT_MAX
argument_list|(
literal|0
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|FT_NEW_ARRAY
argument_list|(
name|name_strings
index|[
name|n
index|]
argument_list|,
name|len
operator|+
literal|1
argument_list|)
operator|||
name|FT_STREAM_READ
argument_list|(
name|name_strings
index|[
name|n
index|]
argument_list|,
name|len
argument_list|)
condition|)
goto|goto
name|Fail1
goto|;
name|name_strings
index|[
name|n
index|]
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
if|if
condition|(
name|n
operator|<
name|num_names
condition|)
block|{
name|FT_ERROR
argument_list|(
operator|(
literal|"load_format_20:"
literal|" all entries in post table are already parsed,"
literal|" using NULL names for gid %d - %d\n"
operator|,
name|n
operator|,
name|num_names
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
for|for
control|(
init|;
name|n
operator|<
name|num_names
condition|;
name|n
operator|++
control|)
if|if
condition|(
name|FT_NEW_ARRAY
argument_list|(
name|name_strings
index|[
name|n
index|]
argument_list|,
literal|1
argument_list|)
condition|)
goto|goto
name|Fail1
goto|;
else|else
name|name_strings
index|[
name|n
index|]
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
block|}
comment|/* all right, set table fields and exit successfully */
block|{
name|TT_Post_20
name|table
init|=
operator|&
name|face
operator|->
name|postscript_names
operator|.
name|names
operator|.
name|format_20
decl_stmt|;
name|table
operator|->
name|num_glyphs
operator|=
operator|(
name|FT_UShort
operator|)
name|num_glyphs
expr_stmt|;
name|table
operator|->
name|num_names
operator|=
operator|(
name|FT_UShort
operator|)
name|num_names
expr_stmt|;
name|table
operator|->
name|glyph_indices
operator|=
name|glyph_indices
expr_stmt|;
name|table
operator|->
name|glyph_names
operator|=
name|name_strings
expr_stmt|;
block|}
return|return
name|FT_Err_Ok
return|;
name|Fail1
label|:
block|{
name|FT_UShort
name|n
decl_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|num_names
condition|;
name|n
operator|++
control|)
name|FT_FREE
argument_list|(
name|name_strings
index|[
name|n
index|]
argument_list|)
expr_stmt|;
block|}
name|Fail
label|:
name|FT_FREE
argument_list|(
name|name_strings
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|glyph_indices
argument_list|)
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|load_format_25
name|load_format_25
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_Stream
name|stream
parameter_list|,
name|FT_ULong
name|post_limit
parameter_list|)
block|{
name|FT_Memory
name|memory
init|=
name|stream
operator|->
name|memory
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|FT_Int
name|num_glyphs
decl_stmt|;
name|FT_Char
modifier|*
name|offset_table
init|=
name|NULL
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|post_limit
argument_list|)
expr_stmt|;
comment|/* UNDOCUMENTED!  This value appears only in the Apple TT specs. */
if|if
condition|(
name|FT_READ_USHORT
argument_list|(
name|num_glyphs
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
comment|/* check the number of glyphs */
if|if
condition|(
name|num_glyphs
operator|>
name|face
operator|->
name|max_profile
operator|.
name|numGlyphs
operator|||
name|num_glyphs
operator|>
literal|258
condition|)
block|{
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_File_Format
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|FT_NEW_ARRAY
argument_list|(
name|offset_table
argument_list|,
name|num_glyphs
argument_list|)
operator|||
name|FT_STREAM_READ
argument_list|(
name|offset_table
argument_list|,
name|num_glyphs
argument_list|)
condition|)
goto|goto
name|Fail
goto|;
comment|/* now check the offset table */
block|{
name|FT_Int
name|n
decl_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|num_glyphs
condition|;
name|n
operator|++
control|)
block|{
name|FT_Long
name|idx
init|=
operator|(
name|FT_Long
operator|)
name|n
operator|+
name|offset_table
index|[
name|n
index|]
decl_stmt|;
if|if
condition|(
name|idx
operator|<
literal|0
operator|||
name|idx
operator|>
name|num_glyphs
condition|)
block|{
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_File_Format
argument_list|)
expr_stmt|;
goto|goto
name|Fail
goto|;
block|}
block|}
block|}
comment|/* OK, set table fields and exit successfully */
block|{
name|TT_Post_25
name|table
init|=
operator|&
name|face
operator|->
name|postscript_names
operator|.
name|names
operator|.
name|format_25
decl_stmt|;
name|table
operator|->
name|num_glyphs
operator|=
operator|(
name|FT_UShort
operator|)
name|num_glyphs
expr_stmt|;
name|table
operator|->
name|offsets
operator|=
name|offset_table
expr_stmt|;
block|}
return|return
name|FT_Err_Ok
return|;
name|Fail
label|:
name|FT_FREE
argument_list|(
name|offset_table
argument_list|)
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|load_post_names
name|load_post_names
parameter_list|(
name|TT_Face
name|face
parameter_list|)
block|{
name|FT_Stream
name|stream
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|FT_Fixed
name|format
decl_stmt|;
name|FT_ULong
name|post_len
decl_stmt|;
name|FT_ULong
name|post_limit
decl_stmt|;
comment|/* get a stream for the face's resource */
name|stream
operator|=
name|face
operator|->
name|root
operator|.
name|stream
expr_stmt|;
comment|/* seek to the beginning of the PS names table */
name|error
operator|=
name|face
operator|->
name|goto_table
argument_list|(
name|face
argument_list|,
name|TTAG_post
argument_list|,
name|stream
argument_list|,
operator|&
name|post_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
name|post_limit
operator|=
name|FT_STREAM_POS
argument_list|()
operator|+
name|post_len
expr_stmt|;
name|format
operator|=
name|face
operator|->
name|postscript
operator|.
name|FormatType
expr_stmt|;
comment|/* go to beginning of subtable */
if|if
condition|(
name|FT_STREAM_SKIP
argument_list|(
literal|32
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
comment|/* now read postscript table */
if|if
condition|(
name|format
operator|==
literal|0x00020000L
condition|)
name|error
operator|=
name|load_format_20
argument_list|(
name|face
argument_list|,
name|stream
argument_list|,
name|post_limit
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|format
operator|==
literal|0x00028000L
condition|)
name|error
operator|=
name|load_format_25
argument_list|(
name|face
argument_list|,
name|stream
argument_list|,
name|post_limit
argument_list|)
expr_stmt|;
else|else
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_File_Format
argument_list|)
expr_stmt|;
name|face
operator|->
name|postscript_names
operator|.
name|loaded
operator|=
literal|1
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
block|}
end_function
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|tt_face_free_ps_names
name|tt_face_free_ps_names
argument_list|(
argument|TT_Face  face
argument_list|)
end_macro
begin_block
block|{
name|FT_Memory
name|memory
init|=
name|face
operator|->
name|root
operator|.
name|memory
decl_stmt|;
name|TT_Post_Names
name|names
init|=
operator|&
name|face
operator|->
name|postscript_names
decl_stmt|;
name|FT_Fixed
name|format
decl_stmt|;
if|if
condition|(
name|names
operator|->
name|loaded
condition|)
block|{
name|format
operator|=
name|face
operator|->
name|postscript
operator|.
name|FormatType
expr_stmt|;
if|if
condition|(
name|format
operator|==
literal|0x00020000L
condition|)
block|{
name|TT_Post_20
name|table
init|=
operator|&
name|names
operator|->
name|names
operator|.
name|format_20
decl_stmt|;
name|FT_UShort
name|n
decl_stmt|;
name|FT_FREE
argument_list|(
name|table
operator|->
name|glyph_indices
argument_list|)
expr_stmt|;
name|table
operator|->
name|num_glyphs
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|table
operator|->
name|num_names
condition|;
name|n
operator|++
control|)
name|FT_FREE
argument_list|(
name|table
operator|->
name|glyph_names
index|[
name|n
index|]
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|table
operator|->
name|glyph_names
argument_list|)
expr_stmt|;
name|table
operator|->
name|num_names
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|format
operator|==
literal|0x00028000L
condition|)
block|{
name|TT_Post_25
name|table
init|=
operator|&
name|names
operator|->
name|names
operator|.
name|format_25
decl_stmt|;
name|FT_FREE
argument_list|(
name|table
operator|->
name|offsets
argument_list|)
expr_stmt|;
name|table
operator|->
name|num_glyphs
operator|=
literal|0
expr_stmt|;
block|}
block|}
name|names
operator|->
name|loaded
operator|=
literal|0
expr_stmt|;
block|}
end_block
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    tt_face_get_ps_name                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Get the PostScript glyph name of a glyph.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face   :: A handle to the parent face.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    idx    :: The glyph index.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    PSname :: The address of a string pointer.  Will be NULL in case   */
end_comment
begin_comment
comment|/*              of error, otherwise it is a pointer to the glyph name.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*              You must not modify the returned string!                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_get_ps_name
argument_list|(
argument|TT_Face      face
argument_list|,
argument|FT_UInt      idx
argument_list|,
argument|FT_String**  PSname
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|TT_Post_Names
name|names
decl_stmt|;
name|FT_Fixed
name|format
decl_stmt|;
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_POSTSCRIPT_NAMES
name|FT_Service_PsCMaps
name|psnames
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|face
condition|)
return|return
name|FT_THROW
argument_list|(
name|Invalid_Face_Handle
argument_list|)
return|;
if|if
condition|(
name|idx
operator|>=
operator|(
name|FT_UInt
operator|)
name|face
operator|->
name|max_profile
operator|.
name|numGlyphs
condition|)
return|return
name|FT_THROW
argument_list|(
name|Invalid_Glyph_Index
argument_list|)
return|;
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_POSTSCRIPT_NAMES
name|psnames
operator|=
operator|(
name|FT_Service_PsCMaps
operator|)
name|face
operator|->
name|psnames
expr_stmt|;
if|if
condition|(
operator|!
name|psnames
condition|)
return|return
name|FT_THROW
argument_list|(
name|Unimplemented_Feature
argument_list|)
return|;
endif|#
directive|endif
name|names
operator|=
operator|&
name|face
operator|->
name|postscript_names
expr_stmt|;
comment|/* `.notdef' by default */
operator|*
name|PSname
operator|=
name|MAC_NAME
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|format
operator|=
name|face
operator|->
name|postscript
operator|.
name|FormatType
expr_stmt|;
if|if
condition|(
name|format
operator|==
literal|0x00010000L
condition|)
block|{
if|if
condition|(
name|idx
operator|<
literal|258
condition|)
comment|/* paranoid checking */
operator|*
name|PSname
operator|=
name|MAC_NAME
argument_list|(
name|idx
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|format
operator|==
literal|0x00020000L
condition|)
block|{
name|TT_Post_20
name|table
init|=
operator|&
name|names
operator|->
name|names
operator|.
name|format_20
decl_stmt|;
if|if
condition|(
operator|!
name|names
operator|->
name|loaded
condition|)
block|{
name|error
operator|=
name|load_post_names
argument_list|(
name|face
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|End
goto|;
block|}
if|if
condition|(
name|idx
operator|<
operator|(
name|FT_UInt
operator|)
name|table
operator|->
name|num_glyphs
condition|)
block|{
name|FT_UShort
name|name_index
init|=
name|table
operator|->
name|glyph_indices
index|[
name|idx
index|]
decl_stmt|;
if|if
condition|(
name|name_index
operator|<
literal|258
condition|)
operator|*
name|PSname
operator|=
name|MAC_NAME
argument_list|(
name|name_index
argument_list|)
expr_stmt|;
else|else
operator|*
name|PSname
operator|=
operator|(
name|FT_String
operator|*
operator|)
name|table
operator|->
name|glyph_names
index|[
name|name_index
operator|-
literal|258
index|]
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|format
operator|==
literal|0x00028000L
condition|)
block|{
name|TT_Post_25
name|table
init|=
operator|&
name|names
operator|->
name|names
operator|.
name|format_25
decl_stmt|;
if|if
condition|(
operator|!
name|names
operator|->
name|loaded
condition|)
block|{
name|error
operator|=
name|load_post_names
argument_list|(
name|face
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|End
goto|;
block|}
if|if
condition|(
name|idx
operator|<
operator|(
name|FT_UInt
operator|)
name|table
operator|->
name|num_glyphs
condition|)
comment|/* paranoid checking */
operator|*
name|PSname
operator|=
name|MAC_NAME
argument_list|(
operator|(
name|FT_Int
operator|)
name|idx
operator|+
name|table
operator|->
name|offsets
index|[
name|idx
index|]
argument_list|)
expr_stmt|;
block|}
comment|/* nothing to do for format == 0x00030000L */
name|End
label|:
return|return
name|FT_Err_Ok
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
