begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxfgen.c                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Generate feature registry data for gxv `feat' validator.             */
end_comment
begin_comment
comment|/*    This program is derived from gxfeatreg.c in gxlayout.                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2005, 2006 by Masatake YAMATO and Redhat K.K.          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file may only be used,                                            */
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
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxfeatreg.c                                                            */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Database of font features pre-defined by Apple Computer, Inc.        */
end_comment
begin_comment
comment|/*    http://developer.apple.com/fonts/Registry/                           */
end_comment
begin_comment
comment|/*    (body).                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003 by                                                      */
end_comment
begin_comment
comment|/*  Masatake YAMATO and Redhat K.K.                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file may only be used,                                            */
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
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/* Development of gxfeatreg.c is supported by                              */
end_comment
begin_comment
comment|/* Information-technology Promotion Agency, Japan.                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/* This file is compiled as a stand-alone executable.                      */
end_comment
begin_comment
comment|/* This file is never compiled into `libfreetype2'.                        */
end_comment
begin_comment
comment|/* The output of this file is used in `gxvfeat.c'.                         */
end_comment
begin_comment
comment|/* ----------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* Compile: gcc `pkg-config --cflags freetype2` gxvfgen.c -o gxvfgen       */
end_comment
begin_comment
comment|/* Run: ./gxvfgen> tmp.c                                                  */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*******************************************************************/
end_comment
begin_comment
comment|/* WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING */
end_comment
begin_comment
comment|/*******************************************************************/
end_comment
begin_comment
comment|/*    * If you add a new setting to a feature, check the number of settings    * in the feature.  If the number is greater than the value defined as    * FEATREG_MAX_SETTING, update the value.    */
end_comment
begin_define
DECL|macro|FEATREG_MAX_SETTING
define|#
directive|define
name|FEATREG_MAX_SETTING
value|12
end_define
begin_comment
comment|/*******************************************************************/
end_comment
begin_comment
comment|/* WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING */
end_comment
begin_comment
comment|/*******************************************************************/
end_comment
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                      Data and Types                           *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_define
DECL|macro|APPLE_RESERVED
define|#
directive|define
name|APPLE_RESERVED
value|"Apple Reserved"
end_define
begin_define
DECL|macro|APPLE_RESERVED_LENGTH
define|#
directive|define
name|APPLE_RESERVED_LENGTH
value|14
end_define
begin_typedef
DECL|struct|GX_Feature_RegistryRec_
typedef|typedef
struct|struct
name|GX_Feature_RegistryRec_
block|{
DECL|member|feat_name
specifier|const
name|char
modifier|*
name|feat_name
decl_stmt|;
DECL|member|exclusive
name|char
name|exclusive
decl_stmt|;
DECL|member|setting_name
name|char
modifier|*
name|setting_name
index|[
name|FEATREG_MAX_SETTING
index|]
decl_stmt|;
block|}
DECL|typedef|GX_Feature_RegistryRec
name|GX_Feature_RegistryRec
typedef|;
end_typedef
begin_define
DECL|macro|EMPTYFEAT
define|#
directive|define
name|EMPTYFEAT
value|{0, 0, {NULL}}
end_define
begin_decl_stmt
DECL|variable|featreg_table
specifier|static
name|GX_Feature_RegistryRec
name|featreg_table
index|[]
init|=
block|{
block|{
comment|/* 0 */
literal|"All Typographic Features"
block|,
literal|0
block|,
block|{
literal|"All Type Features"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 1 */
literal|"Ligatures"
block|,
literal|0
block|,
block|{
literal|"Required Ligatures"
block|,
literal|"Common Ligatures"
block|,
literal|"Rare Ligatures"
block|,
literal|"Logos"
block|,
literal|"Rebus Pictures"
block|,
literal|"Diphthong Ligatures"
block|,
literal|"Squared Ligatures"
block|,
literal|"Squared Ligatures, Abbreviated"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 2 */
literal|"Cursive Connection"
block|,
literal|1
block|,
block|{
literal|"Unconnected"
block|,
literal|"Partially Connected"
block|,
literal|"Cursive"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 3 */
literal|"Letter Case"
block|,
literal|1
block|,
block|{
literal|"Upper& Lower Case"
block|,
literal|"All Caps"
block|,
literal|"All Lower Case"
block|,
literal|"Small Caps"
block|,
literal|"Initial Caps"
block|,
literal|"Initial Caps& Small Caps"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 4 */
literal|"Vertical Substitution"
block|,
literal|0
block|,
block|{
comment|/* "Substitute Vertical Forms", */
literal|"Turns on the feature"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 5 */
literal|"Linguistic Rearrangement"
block|,
literal|0
block|,
block|{
comment|/* "Linguistic Rearrangement", */
literal|"Turns on the feature"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 6 */
literal|"Number Spacing"
block|,
literal|1
block|,
block|{
literal|"Monospaced Numbers"
block|,
literal|"Proportional Numbers"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 7 */
name|APPLE_RESERVED
literal|" 1"
block|,
literal|0
block|,
block|{
name|NULL
block|}
block|}
block|,
block|{
comment|/* 8 */
literal|"Smart Swashes"
block|,
literal|0
block|,
block|{
literal|"Word Initial Swashes"
block|,
literal|"Word Final Swashes"
block|,
literal|"Line Initial Swashes"
block|,
literal|"Line Final Swashes"
block|,
literal|"Non-Final Swashes"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 9 */
literal|"Diacritics"
block|,
literal|1
block|,
block|{
literal|"Show Diacritics"
block|,
literal|"Hide Diacritics"
block|,
literal|"Decompose Diacritics"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 10 */
literal|"Vertical Position"
block|,
literal|1
block|,
block|{
comment|/* "Normal Position", */
literal|"No Vertical Position"
block|,
literal|"Superiors"
block|,
literal|"Inferiors"
block|,
literal|"Ordinals"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 11 */
literal|"Fractions"
block|,
literal|1
block|,
block|{
literal|"No Fractions"
block|,
literal|"Vertical Fractions"
block|,
literal|"Diagonal Fractions"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 12 */
name|APPLE_RESERVED
literal|" 2"
block|,
literal|0
block|,
block|{
name|NULL
block|}
block|}
block|,
block|{
comment|/* 13 */
literal|"Overlapping Characters"
block|,
literal|0
block|,
block|{
comment|/* "Prevent Overlap", */
literal|"Turns on the feature"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 14 */
literal|"Typographic Extras"
block|,
literal|0
block|,
block|{
literal|"Hyphens to Em Dash"
block|,
literal|"Hyphens to En Dash"
block|,
literal|"Unslashed Zero"
block|,
literal|"Form Interrobang"
block|,
literal|"Smart Quotes"
block|,
literal|"Periods to Ellipsis"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 15 */
literal|"Mathematical Extras"
block|,
literal|0
block|,
block|{
literal|"Hyphens to Minus"
block|,
literal|"Asterisk to Multiply"
block|,
literal|"Slash to Divide"
block|,
literal|"Inequality Ligatures"
block|,
literal|"Exponents"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 16 */
literal|"Ornament Sets"
block|,
literal|1
block|,
block|{
literal|"No Ornaments"
block|,
literal|"Dingbats"
block|,
literal|"Pi Characters"
block|,
literal|"Fleurons"
block|,
literal|"Decorative Borders"
block|,
literal|"International Symbols"
block|,
literal|"Math Symbols"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 17 */
literal|"Character Alternatives"
block|,
literal|1
block|,
block|{
literal|"No Alternates"
block|,
comment|/* TODO */
name|NULL
block|}
block|}
block|,
block|{
comment|/* 18 */
literal|"Design Complexity"
block|,
literal|1
block|,
block|{
literal|"Design Level 1"
block|,
literal|"Design Level 2"
block|,
literal|"Design Level 3"
block|,
literal|"Design Level 4"
block|,
literal|"Design Level 5"
block|,
comment|/* TODO */
name|NULL
block|}
block|}
block|,
block|{
comment|/* 19 */
literal|"Style Options"
block|,
literal|1
block|,
block|{
literal|"No Style Options"
block|,
literal|"Display Text"
block|,
literal|"Engraved Text"
block|,
literal|"Illuminated Caps"
block|,
literal|"Tilling Caps"
block|,
literal|"Tall Caps"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 20 */
literal|"Character Shape"
block|,
literal|1
block|,
block|{
literal|"Traditional Characters"
block|,
literal|"Simplified Characters"
block|,
literal|"JIS 1978 Characters"
block|,
literal|"JIS 1983 Characters"
block|,
literal|"JIS 1990 Characters"
block|,
literal|"Traditional Characters, Alternative Set 1"
block|,
literal|"Traditional Characters, Alternative Set 2"
block|,
literal|"Traditional Characters, Alternative Set 3"
block|,
literal|"Traditional Characters, Alternative Set 4"
block|,
literal|"Traditional Characters, Alternative Set 5"
block|,
literal|"Expert Characters"
block|,
name|NULL
comment|/* count => 12 */
block|}
block|}
block|,
block|{
comment|/* 21 */
literal|"Number Case"
block|,
literal|1
block|,
block|{
literal|"Lower Case Numbers"
block|,
literal|"Upper Case Numbers"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 22 */
literal|"Text Spacing"
block|,
literal|1
block|,
block|{
literal|"Proportional"
block|,
literal|"Monospaced"
block|,
literal|"Half-width"
block|,
literal|"Normal"
block|,
name|NULL
block|}
block|}
block|,
comment|/* Here after Newer */
block|{
comment|/* 23 */
literal|"Transliteration"
block|,
literal|1
block|,
block|{
literal|"No Transliteration"
block|,
literal|"Hanja To Hangul"
block|,
literal|"Hiragana to Katakana"
block|,
literal|"Katakana to Hiragana"
block|,
literal|"Kana to Romanization"
block|,
literal|"Romanization to Hiragana"
block|,
literal|"Romanization to Katakana"
block|,
literal|"Hanja to Hangul, Alternative Set 1"
block|,
literal|"Hanja to Hangul, Alternative Set 2"
block|,
literal|"Hanja to Hangul, Alternative Set 3"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 24 */
literal|"Annotation"
block|,
literal|1
block|,
block|{
literal|"No Annotation"
block|,
literal|"Box Annotation"
block|,
literal|"Rounded Box Annotation"
block|,
literal|"Circle Annotation"
block|,
literal|"Inverted Circle Annotation"
block|,
literal|"Parenthesis Annotation"
block|,
literal|"Period Annotation"
block|,
literal|"Roman Numeral Annotation"
block|,
literal|"Diamond Annotation"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 25 */
literal|"Kana Spacing"
block|,
literal|1
block|,
block|{
literal|"Full Width"
block|,
literal|"Proportional"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 26 */
literal|"Ideographic Spacing"
block|,
literal|1
block|,
block|{
literal|"Full Width"
block|,
literal|"Proportional"
block|,
name|NULL
block|}
block|}
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 27-30 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 31-35 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 36-40 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 40-45 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 46-50 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 51-55 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 56-60 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 61-65 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 66-70 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 71-75 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 76-80 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 81-85 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 86-90 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 91-95 */
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
name|EMPTYFEAT
block|,
comment|/* 96-98 */
name|EMPTYFEAT
block|,
comment|/* 99 */
block|{
comment|/* 100 => 22 */
literal|"Text Spacing"
block|,
literal|1
block|,
block|{
literal|"Proportional"
block|,
literal|"Monospaced"
block|,
literal|"Half-width"
block|,
literal|"Normal"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 101 => 25 */
literal|"Kana Spacing"
block|,
literal|1
block|,
block|{
literal|"Full Width"
block|,
literal|"Proportional"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 102 => 26 */
literal|"Ideographic Spacing"
block|,
literal|1
block|,
block|{
literal|"Full Width"
block|,
literal|"Proportional"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 103 */
literal|"CJK Roman Spacing"
block|,
literal|1
block|,
block|{
literal|"Half-width"
block|,
literal|"Proportional"
block|,
literal|"Default Roman"
block|,
literal|"Full-width Roman"
block|,
name|NULL
block|}
block|}
block|,
block|{
comment|/* 104 => 1 */
literal|"All Typographic Features"
block|,
literal|0
block|,
block|{
literal|"All Type Features"
block|,
name|NULL
block|}
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                         Generator                             *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_function
name|int
DECL|function|main
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|printf
argument_list|(
literal|"  {\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   /* Generated from %s */\n"
argument_list|,
name|__FILE__
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|featreg_table
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|GX_Feature_RegistryRec
argument_list|)
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|char
modifier|*
name|feat_name
decl_stmt|;
name|int
name|nSettings
decl_stmt|;
name|feat_name
operator|=
name|featreg_table
index|[
name|i
index|]
operator|.
name|feat_name
expr_stmt|;
for|for
control|(
name|nSettings
operator|=
literal|0
init|;
name|featreg_table
index|[
name|i
index|]
operator|.
name|setting_name
index|[
name|nSettings
index|]
condition|;
name|nSettings
operator|++
control|)
empty_stmt|;
comment|/* Do nothing */
name|printf
argument_list|(
literal|"    {%1d, %1d, %1d, %2d},   /* %s */\n"
argument_list|,
name|feat_name
condition|?
literal|1
else|:
literal|0
argument_list|,
operator|(
name|feat_name
operator|&&
operator|(
name|ft_strncmp
argument_list|(
name|feat_name
argument_list|,
name|APPLE_RESERVED
argument_list|,
name|APPLE_RESERVED_LENGTH
argument_list|)
operator|==
literal|0
operator|)
operator|)
condition|?
literal|1
else|:
literal|0
argument_list|,
name|featreg_table
index|[
name|i
index|]
operator|.
name|exclusive
condition|?
literal|1
else|:
literal|0
argument_list|,
name|nSettings
argument_list|,
name|feat_name
condition|?
name|feat_name
else|:
literal|"__EMPTY__"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"  };\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/* END */
end_comment
end_unit
