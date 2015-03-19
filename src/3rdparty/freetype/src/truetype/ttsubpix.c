begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttsubpix.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueType Subpixel Hinting.                                           */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2010-2013 by                                                 */
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
include|FT_INTERNAL_CALC_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_SFNT_H
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_TAGS_H
end_include
begin_include
include|#
directive|include
include|FT_OUTLINE_H
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_DRIVER_H
end_include
begin_include
include|#
directive|include
file|"ttsubpix.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_SUBPIXEL_HINTING
end_ifdef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* These rules affect how the TT Interpreter does hinting, with the      */
end_comment
begin_comment
comment|/* goal of doing subpixel hinting by (in general) ignoring x moves.      */
end_comment
begin_comment
comment|/* Some of these rules are fixes that go above and beyond the            */
end_comment
begin_comment
comment|/* stated techniques in the MS whitepaper on Cleartype, due to           */
end_comment
begin_comment
comment|/* artifacts in many glyphs.  So, these rules make some glyphs render    */
end_comment
begin_comment
comment|/* better than they do in the MS rasterizer.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* "" string or 0 int/char indicates to apply to all glyphs.             */
end_comment
begin_comment
comment|/* "-" used as dummy placeholders, but any non-matching string works.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Some of this could arguably be implemented in fontconfig, however:    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*  - Fontconfig can't set things on a glyph-by-glyph basis.             */
end_comment
begin_comment
comment|/*  - The tweaks that happen here are very low-level, from an average    */
end_comment
begin_comment
comment|/*    user's point of view and are best implemented in the hinter.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The goal is to make the subpixel hinting techniques as generalized    */
end_comment
begin_comment
comment|/* as possible across all fonts to prevent the need for extra rules such */
end_comment
begin_comment
comment|/* as these.                                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The rule structure is designed so that entirely new rules can easily  */
end_comment
begin_comment
comment|/* be added when a new compatibility feature is discovered.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The rule structures could also use some enhancement to handle ranges. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     ****************** WORK IN PROGRESS *******************           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* These are `classes' of fonts that can be grouped together and used in */
end_comment
begin_comment
comment|/* rules below.  A blank entry "" is required at the end of these!       */
end_comment
begin_define
DECL|macro|FAMILY_CLASS_RULES_SIZE
define|#
directive|define
name|FAMILY_CLASS_RULES_SIZE
value|7
end_define
begin_decl_stmt
DECL|variable|FAMILY_CLASS_Rules
specifier|static
specifier|const
name|SPH_Font_Class
name|FAMILY_CLASS_Rules
index|[
name|FAMILY_CLASS_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"MS Legacy Fonts"
block|,
block|{
literal|"Aharoni"
block|,
literal|"Andale Mono"
block|,
literal|"Andalus"
block|,
literal|"Angsana New"
block|,
literal|"AngsanaUPC"
block|,
literal|"Arabic Transparent"
block|,
literal|"Arial Black"
block|,
literal|"Arial Narrow"
block|,
literal|"Arial Unicode MS"
block|,
literal|"Arial"
block|,
literal|"Batang"
block|,
literal|"Browallia New"
block|,
literal|"BrowalliaUPC"
block|,
literal|"Comic Sans MS"
block|,
literal|"Cordia New"
block|,
literal|"CordiaUPC"
block|,
literal|"Courier New"
block|,
literal|"DFKai-SB"
block|,
literal|"David Transparent"
block|,
literal|"David"
block|,
literal|"DilleniaUPC"
block|,
literal|"Estrangelo Edessa"
block|,
literal|"EucrosiaUPC"
block|,
literal|"FangSong_GB2312"
block|,
literal|"Fixed Miriam Transparent"
block|,
literal|"FrankRuehl"
block|,
literal|"Franklin Gothic Medium"
block|,
literal|"FreesiaUPC"
block|,
literal|"Garamond"
block|,
literal|"Gautami"
block|,
literal|"Georgia"
block|,
literal|"Gulim"
block|,
literal|"Impact"
block|,
literal|"IrisUPC"
block|,
literal|"JasmineUPC"
block|,
literal|"KaiTi_GB2312"
block|,
literal|"KodchiangUPC"
block|,
literal|"Latha"
block|,
literal|"Levenim MT"
block|,
literal|"LilyUPC"
block|,
literal|"Lucida Console"
block|,
literal|"Lucida Sans Unicode"
block|,
literal|"MS Gothic"
block|,
literal|"MS Mincho"
block|,
literal|"MV Boli"
block|,
literal|"Mangal"
block|,
literal|"Marlett"
block|,
literal|"Microsoft Sans Serif"
block|,
literal|"Mingliu"
block|,
literal|"Miriam Fixed"
block|,
literal|"Miriam Transparent"
block|,
literal|"Miriam"
block|,
literal|"Narkisim"
block|,
literal|"Palatino Linotype"
block|,
literal|"Raavi"
block|,
literal|"Rod Transparent"
block|,
literal|"Rod"
block|,
literal|"Shruti"
block|,
literal|"SimHei"
block|,
literal|"Simplified Arabic Fixed"
block|,
literal|"Simplified Arabic"
block|,
literal|"Simsun"
block|,
literal|"Sylfaen"
block|,
literal|"Symbol"
block|,
literal|"Tahoma"
block|,
literal|"Times New Roman"
block|,
literal|"Traditional Arabic"
block|,
literal|"Trebuchet MS"
block|,
literal|"Tunga"
block|,
literal|"Verdana"
block|,
literal|"Webdings"
block|,
literal|"Wingdings"
block|,
literal|""
block|,       }
block|,     }
block|,
block|{
literal|"Core MS Legacy Fonts"
block|,
block|{
literal|"Arial Black"
block|,
literal|"Arial Narrow"
block|,
literal|"Arial Unicode MS"
block|,
literal|"Arial"
block|,
literal|"Comic Sans MS"
block|,
literal|"Courier New"
block|,
literal|"Garamond"
block|,
literal|"Georgia"
block|,
literal|"Impact"
block|,
literal|"Lucida Console"
block|,
literal|"Lucida Sans Unicode"
block|,
literal|"Microsoft Sans Serif"
block|,
literal|"Palatino Linotype"
block|,
literal|"Tahoma"
block|,
literal|"Times New Roman"
block|,
literal|"Trebuchet MS"
block|,
literal|"Verdana"
block|,
literal|""
block|,       }
block|,     }
block|,
block|{
literal|"Apple Legacy Fonts"
block|,
block|{
literal|"Geneva"
block|,
literal|"Times"
block|,
literal|"Monaco"
block|,
literal|"Century"
block|,
literal|"Chalkboard"
block|,
literal|"Lobster"
block|,
literal|"Century Gothic"
block|,
literal|"Optima"
block|,
literal|"Lucida Grande"
block|,
literal|"Gill Sans"
block|,
literal|"Baskerville"
block|,
literal|"Helvetica"
block|,
literal|"Helvetica Neue"
block|,
literal|""
block|,       }
block|,     }
block|,
block|{
literal|"Legacy Sans Fonts"
block|,
block|{
literal|"Andale Mono"
block|,
literal|"Arial Unicode MS"
block|,
literal|"Arial"
block|,
literal|"Century Gothic"
block|,
literal|"Comic Sans MS"
block|,
literal|"Franklin Gothic Medium"
block|,
literal|"Geneva"
block|,
literal|"Lucida Console"
block|,
literal|"Lucida Grande"
block|,
literal|"Lucida Sans Unicode"
block|,
literal|"Lucida Sans Typewriter"
block|,
literal|"Microsoft Sans Serif"
block|,
literal|"Monaco"
block|,
literal|"Tahoma"
block|,
literal|"Trebuchet MS"
block|,
literal|"Verdana"
block|,
literal|""
block|,       }
block|,     }
block|,
block|{
literal|"Misc Legacy Fonts"
block|,
block|{
literal|"Dark Courier"
block|,
literal|""
block|, }
block|, }
block|,
block|{
literal|"Verdana Clones"
block|,
block|{
literal|"DejaVu Sans"
block|,
literal|"Bitstream Vera Sans"
block|,
literal|""
block|, }
block|, }
block|,
block|{
literal|"Verdana and Clones"
block|,
block|{
literal|"DejaVu Sans"
block|,
literal|"Bitstream Vera Sans"
block|,
literal|"Verdana"
block|,
literal|""
block|, }
block|, }
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Define this to force natural (i.e. not bitmap-compatible) widths.     */
end_comment
begin_comment
comment|/* The default leans strongly towards natural widths except for a few    */
end_comment
begin_comment
comment|/* legacy fonts where a selective combination produces nicer results.    */
end_comment
begin_comment
comment|/* #define FORCE_NATURAL_WIDTHS   */
end_comment
begin_comment
comment|/* Define `classes' of styles that can be grouped together and used in   */
end_comment
begin_comment
comment|/* rules below.  A blank entry "" is required at the end of these!       */
end_comment
begin_define
DECL|macro|STYLE_CLASS_RULES_SIZE
define|#
directive|define
name|STYLE_CLASS_RULES_SIZE
value|5
end_define
begin_decl_stmt
DECL|variable|STYLE_CLASS_Rules
specifier|const
name|SPH_Font_Class
name|STYLE_CLASS_Rules
index|[
name|STYLE_CLASS_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"Regular Class"
block|,
block|{
literal|"Regular"
block|,
literal|"Book"
block|,
literal|"Medium"
block|,
literal|"Roman"
block|,
literal|"Normal"
block|,
literal|""
block|,       }
block|,     }
block|,
block|{
literal|"Regular/Italic Class"
block|,
block|{
literal|"Regular"
block|,
literal|"Book"
block|,
literal|"Medium"
block|,
literal|"Italic"
block|,
literal|"Oblique"
block|,
literal|"Roman"
block|,
literal|"Normal"
block|,
literal|""
block|,       }
block|,     }
block|,
block|{
literal|"Bold/BoldItalic Class"
block|,
block|{
literal|"Bold"
block|,
literal|"Bold Italic"
block|,
literal|"Black"
block|,
literal|""
block|,       }
block|,     }
block|,
block|{
literal|"Bold/Italic/BoldItalic Class"
block|,
block|{
literal|"Bold"
block|,
literal|"Bold Italic"
block|,
literal|"Black"
block|,
literal|"Italic"
block|,
literal|"Oblique"
block|,
literal|""
block|,       }
block|,     }
block|,
block|{
literal|"Regular/Bold Class"
block|,
block|{
literal|"Regular"
block|,
literal|"Book"
block|,
literal|"Medium"
block|,
literal|"Normal"
block|,
literal|"Roman"
block|,
literal|"Bold"
block|,
literal|"Black"
block|,
literal|""
block|,       }
block|,     }
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Force special legacy fixes for fonts.                                 */
end_comment
begin_define
DECL|macro|COMPATIBILITY_MODE_RULES_SIZE
define|#
directive|define
name|COMPATIBILITY_MODE_RULES_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|COMPATIBILITY_MODE_Rules
specifier|const
name|SPH_TweakRule
name|COMPATIBILITY_MODE_Rules
index|[
name|COMPATIBILITY_MODE_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"Verdana Clones"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Don't do subpixel (ignore_x_mode) hinting; do normal hinting.         */
end_comment
begin_define
DECL|macro|PIXEL_HINTING_RULES_SIZE
define|#
directive|define
name|PIXEL_HINTING_RULES_SIZE
value|2
end_define
begin_decl_stmt
DECL|variable|PIXEL_HINTING_Rules
specifier|const
name|SPH_TweakRule
name|PIXEL_HINTING_Rules
index|[
name|PIXEL_HINTING_RULES_SIZE
index|]
init|=
block|{
comment|/* these characters are almost always safe */
block|{
literal|"Courier New"
block|,
literal|12
block|,
literal|"Italic"
block|,
literal|'z'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|11
block|,
literal|"Italic"
block|,
literal|'z'
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Subpixel hinting ignores SHPIX rules on X.  Force SHPIX for these.    */
end_comment
begin_define
DECL|macro|DO_SHPIX_RULES_SIZE
define|#
directive|define
name|DO_SHPIX_RULES_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|DO_SHPIX_Rules
specifier|const
name|SPH_TweakRule
name|DO_SHPIX_Rules
index|[
name|DO_SHPIX_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"-"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Skip Y moves that start with a point that is not on a Y pixel         */
end_comment
begin_comment
comment|/* boundary and don't move that point to a Y pixel boundary.             */
end_comment
begin_define
DECL|macro|SKIP_NONPIXEL_Y_MOVES_RULES_SIZE
define|#
directive|define
name|SKIP_NONPIXEL_Y_MOVES_RULES_SIZE
value|4
end_define
begin_decl_stmt
DECL|variable|SKIP_NONPIXEL_Y_MOVES_Rules
specifier|const
name|SPH_TweakRule
name|SKIP_NONPIXEL_Y_MOVES_Rules
index|[
name|SKIP_NONPIXEL_Y_MOVES_RULES_SIZE
index|]
init|=
block|{
comment|/* fix vwxyz thinness*/
block|{
literal|"Consolas"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,
comment|/* Fix thin middle stems */
block|{
literal|"Core MS Legacy Fonts"
block|,
literal|0
block|,
literal|"Regular"
block|,
literal|0
block|}
block|,
comment|/* Cyrillic small letter I */
block|{
literal|"Legacy Sans Fonts"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,
comment|/* Fix artifacts with some Regular& Bold */
block|{
literal|"Verdana Clones"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|SKIP_NONPIXEL_Y_MOVES_RULES_EXCEPTIONS_SIZE
define|#
directive|define
name|SKIP_NONPIXEL_Y_MOVES_RULES_EXCEPTIONS_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|SKIP_NONPIXEL_Y_MOVES_Rules_Exceptions
specifier|const
name|SPH_TweakRule
name|SKIP_NONPIXEL_Y_MOVES_Rules_Exceptions
index|[
name|SKIP_NONPIXEL_Y_MOVES_RULES_EXCEPTIONS_SIZE
index|]
init|=
block|{
comment|/* Fixes< and> */
block|{
literal|"Courier New"
block|,
literal|0
block|,
literal|"Regular"
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Skip Y moves that start with a point that is not on a Y pixel         */
end_comment
begin_comment
comment|/* boundary and don't move that point to a Y pixel boundary.             */
end_comment
begin_define
DECL|macro|SKIP_NONPIXEL_Y_MOVES_DELTAP_RULES_SIZE
define|#
directive|define
name|SKIP_NONPIXEL_Y_MOVES_DELTAP_RULES_SIZE
value|2
end_define
begin_decl_stmt
DECL|variable|SKIP_NONPIXEL_Y_MOVES_DELTAP_Rules
specifier|const
name|SPH_TweakRule
name|SKIP_NONPIXEL_Y_MOVES_DELTAP_Rules
index|[
name|SKIP_NONPIXEL_Y_MOVES_DELTAP_RULES_SIZE
index|]
init|=
block|{
comment|/* Maintain thickness of diagonal in 'N' */
block|{
literal|"Times New Roman"
block|,
literal|0
block|,
literal|"Regular/Bold Class"
block|,
literal|'N'
block|}
block|,
block|{
literal|"Georgia"
block|,
literal|0
block|,
literal|"Regular/Bold Class"
block|,
literal|'N'
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Skip Y moves that move a point off a Y pixel boundary.                */
end_comment
begin_define
DECL|macro|SKIP_OFFPIXEL_Y_MOVES_RULES_SIZE
define|#
directive|define
name|SKIP_OFFPIXEL_Y_MOVES_RULES_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|SKIP_OFFPIXEL_Y_MOVES_Rules
specifier|const
name|SPH_TweakRule
name|SKIP_OFFPIXEL_Y_MOVES_Rules
index|[
name|SKIP_OFFPIXEL_Y_MOVES_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"-"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|SKIP_OFFPIXEL_Y_MOVES_RULES_EXCEPTIONS_SIZE
define|#
directive|define
name|SKIP_OFFPIXEL_Y_MOVES_RULES_EXCEPTIONS_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|SKIP_OFFPIXEL_Y_MOVES_Rules_Exceptions
specifier|const
name|SPH_TweakRule
name|SKIP_OFFPIXEL_Y_MOVES_Rules_Exceptions
index|[
name|SKIP_OFFPIXEL_Y_MOVES_RULES_EXCEPTIONS_SIZE
index|]
init|=
block|{
block|{
literal|"-"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Round moves that don't move a point to a Y pixel boundary.            */
end_comment
begin_define
DECL|macro|ROUND_NONPIXEL_Y_MOVES_RULES_SIZE
define|#
directive|define
name|ROUND_NONPIXEL_Y_MOVES_RULES_SIZE
value|2
end_define
begin_decl_stmt
DECL|variable|ROUND_NONPIXEL_Y_MOVES_Rules
specifier|const
name|SPH_TweakRule
name|ROUND_NONPIXEL_Y_MOVES_Rules
index|[
name|ROUND_NONPIXEL_Y_MOVES_RULES_SIZE
index|]
init|=
block|{
comment|/* Droid font instructions don't snap Y to pixels */
block|{
literal|"Droid Sans"
block|,
literal|0
block|,
literal|"Regular/Italic Class"
block|,
literal|0
block|}
block|,
block|{
literal|"Droid Sans Mono"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|ROUND_NONPIXEL_Y_MOVES_RULES_EXCEPTIONS_SIZE
define|#
directive|define
name|ROUND_NONPIXEL_Y_MOVES_RULES_EXCEPTIONS_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|ROUND_NONPIXEL_Y_MOVES_Rules_Exceptions
specifier|const
name|SPH_TweakRule
name|ROUND_NONPIXEL_Y_MOVES_Rules_Exceptions
index|[
name|ROUND_NONPIXEL_Y_MOVES_RULES_EXCEPTIONS_SIZE
index|]
init|=
block|{
block|{
literal|"-"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Allow a Direct_Move along X freedom vector if matched.                */
end_comment
begin_define
DECL|macro|ALLOW_X_DMOVE_RULES_SIZE
define|#
directive|define
name|ALLOW_X_DMOVE_RULES_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|ALLOW_X_DMOVE_Rules
specifier|const
name|SPH_TweakRule
name|ALLOW_X_DMOVE_Rules
index|[
name|ALLOW_X_DMOVE_RULES_SIZE
index|]
init|=
block|{
comment|/* Fixes vanishing diagonal in 4 */
block|{
literal|"Verdana"
block|,
literal|0
block|,
literal|"Regular"
block|,
literal|'4'
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Return MS rasterizer version 35 if matched.                           */
end_comment
begin_define
DECL|macro|RASTERIZER_35_RULES_SIZE
define|#
directive|define
name|RASTERIZER_35_RULES_SIZE
value|8
end_define
begin_decl_stmt
DECL|variable|RASTERIZER_35_Rules
specifier|const
name|SPH_TweakRule
name|RASTERIZER_35_Rules
index|[
name|RASTERIZER_35_RULES_SIZE
index|]
init|=
block|{
comment|/* This seems to be the only way to make these look good */
block|{
literal|"Times New Roman"
block|,
literal|0
block|,
literal|"Regular"
block|,
literal|'i'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|0
block|,
literal|"Regular"
block|,
literal|'j'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|0
block|,
literal|"Regular"
block|,
literal|'m'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|0
block|,
literal|"Regular"
block|,
literal|'r'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|0
block|,
literal|"Regular"
block|,
literal|'a'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|0
block|,
literal|"Regular"
block|,
literal|'n'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|0
block|,
literal|"Regular"
block|,
literal|'p'
block|}
block|,
block|{
literal|"Times"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Don't round to the subpixel grid.  Round to pixel grid.               */
end_comment
begin_define
DECL|macro|NORMAL_ROUND_RULES_SIZE
define|#
directive|define
name|NORMAL_ROUND_RULES_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|NORMAL_ROUND_Rules
specifier|const
name|SPH_TweakRule
name|NORMAL_ROUND_Rules
index|[
name|NORMAL_ROUND_RULES_SIZE
index|]
init|=
block|{
comment|/* Fix serif thickness for certain ppems */
comment|/* Can probably be generalized somehow   */
block|{
literal|"Courier New"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Skip IUP instructions if matched.                                     */
end_comment
begin_define
DECL|macro|SKIP_IUP_RULES_SIZE
define|#
directive|define
name|SKIP_IUP_RULES_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|SKIP_IUP_Rules
specifier|const
name|SPH_TweakRule
name|SKIP_IUP_Rules
index|[
name|SKIP_IUP_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"Arial"
block|,
literal|13
block|,
literal|"Regular"
block|,
literal|'a'
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Skip MIAP Twilight hack if matched.                                   */
end_comment
begin_define
DECL|macro|MIAP_HACK_RULES_SIZE
define|#
directive|define
name|MIAP_HACK_RULES_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|MIAP_HACK_Rules
specifier|const
name|SPH_TweakRule
name|MIAP_HACK_Rules
index|[
name|MIAP_HACK_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"Geneva"
block|,
literal|12
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Skip DELTAP instructions if matched.                                  */
end_comment
begin_define
DECL|macro|ALWAYS_SKIP_DELTAP_RULES_SIZE
define|#
directive|define
name|ALWAYS_SKIP_DELTAP_RULES_SIZE
value|23
end_define
begin_decl_stmt
DECL|variable|ALWAYS_SKIP_DELTAP_Rules
specifier|const
name|SPH_TweakRule
name|ALWAYS_SKIP_DELTAP_Rules
index|[
name|ALWAYS_SKIP_DELTAP_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"Georgia"
block|,
literal|0
block|,
literal|"Regular"
block|,
literal|'k'
block|}
block|,
comment|/* fix various problems with e in different versions */
block|{
literal|"Trebuchet MS"
block|,
literal|14
block|,
literal|"Regular"
block|,
literal|'e'
block|}
block|,
block|{
literal|"Trebuchet MS"
block|,
literal|13
block|,
literal|"Regular"
block|,
literal|'e'
block|}
block|,
block|{
literal|"Trebuchet MS"
block|,
literal|15
block|,
literal|"Regular"
block|,
literal|'e'
block|}
block|,
block|{
literal|"Trebuchet MS"
block|,
literal|0
block|,
literal|"Italic"
block|,
literal|'v'
block|}
block|,
block|{
literal|"Trebuchet MS"
block|,
literal|0
block|,
literal|"Italic"
block|,
literal|'w'
block|}
block|,
block|{
literal|"Trebuchet MS"
block|,
literal|0
block|,
literal|"Regular"
block|,
literal|'Y'
block|}
block|,
block|{
literal|"Arial"
block|,
literal|11
block|,
literal|"Regular"
block|,
literal|'s'
block|}
block|,
comment|/* prevent problems with '3' and others */
block|{
literal|"Verdana"
block|,
literal|10
block|,
literal|"Regular"
block|,
literal|0
block|}
block|,
block|{
literal|"Verdana"
block|,
literal|9
block|,
literal|"Regular"
block|,
literal|0
block|}
block|,
comment|/* Cyrillic small letter short I */
block|{
literal|"Legacy Sans Fonts"
block|,
literal|0
block|,
literal|""
block|,
literal|0x438
block|}
block|,
block|{
literal|"Legacy Sans Fonts"
block|,
literal|0
block|,
literal|""
block|,
literal|0x439
block|}
block|,
block|{
literal|"Arial"
block|,
literal|10
block|,
literal|"Regular"
block|,
literal|'6'
block|}
block|,
block|{
literal|"Arial"
block|,
literal|0
block|,
literal|"Bold/BoldItalic Class"
block|,
literal|'a'
block|}
block|,
comment|/* Make horizontal stems consistent with the rest */
block|{
literal|"Arial"
block|,
literal|24
block|,
literal|"Bold"
block|,
literal|'a'
block|}
block|,
block|{
literal|"Arial"
block|,
literal|25
block|,
literal|"Bold"
block|,
literal|'a'
block|}
block|,
block|{
literal|"Arial"
block|,
literal|24
block|,
literal|"Bold"
block|,
literal|'s'
block|}
block|,
block|{
literal|"Arial"
block|,
literal|25
block|,
literal|"Bold"
block|,
literal|'s'
block|}
block|,
block|{
literal|"Arial"
block|,
literal|34
block|,
literal|"Bold"
block|,
literal|'s'
block|}
block|,
block|{
literal|"Arial"
block|,
literal|35
block|,
literal|"Bold"
block|,
literal|'s'
block|}
block|,
block|{
literal|"Arial"
block|,
literal|36
block|,
literal|"Bold"
block|,
literal|'s'
block|}
block|,
block|{
literal|"Arial"
block|,
literal|25
block|,
literal|"Regular"
block|,
literal|'s'
block|}
block|,
block|{
literal|"Arial"
block|,
literal|26
block|,
literal|"Regular"
block|,
literal|'s'
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Always do DELTAP instructions if matched.                             */
end_comment
begin_define
DECL|macro|ALWAYS_DO_DELTAP_RULES_SIZE
define|#
directive|define
name|ALWAYS_DO_DELTAP_RULES_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|ALWAYS_DO_DELTAP_Rules
specifier|const
name|SPH_TweakRule
name|ALWAYS_DO_DELTAP_Rules
index|[
name|ALWAYS_DO_DELTAP_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"-"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Don't allow ALIGNRP after IUP.                                        */
end_comment
begin_define
DECL|macro|NO_ALIGNRP_AFTER_IUP_RULES_SIZE
define|#
directive|define
name|NO_ALIGNRP_AFTER_IUP_RULES_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|NO_ALIGNRP_AFTER_IUP_Rules
specifier|static
specifier|const
name|SPH_TweakRule
name|NO_ALIGNRP_AFTER_IUP_Rules
index|[
name|NO_ALIGNRP_AFTER_IUP_RULES_SIZE
index|]
init|=
block|{
comment|/* Prevent creation of dents in outline */
block|{
literal|"-"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Don't allow DELTAP after IUP.                                         */
end_comment
begin_define
DECL|macro|NO_DELTAP_AFTER_IUP_RULES_SIZE
define|#
directive|define
name|NO_DELTAP_AFTER_IUP_RULES_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|NO_DELTAP_AFTER_IUP_Rules
specifier|static
specifier|const
name|SPH_TweakRule
name|NO_DELTAP_AFTER_IUP_Rules
index|[
name|NO_DELTAP_AFTER_IUP_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"-"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Don't allow CALL after IUP.                                           */
end_comment
begin_define
DECL|macro|NO_CALL_AFTER_IUP_RULES_SIZE
define|#
directive|define
name|NO_CALL_AFTER_IUP_RULES_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|NO_CALL_AFTER_IUP_Rules
specifier|static
specifier|const
name|SPH_TweakRule
name|NO_CALL_AFTER_IUP_Rules
index|[
name|NO_CALL_AFTER_IUP_RULES_SIZE
index|]
init|=
block|{
comment|/* Prevent creation of dents in outline */
block|{
literal|"-"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* De-embolden these glyphs slightly.                                    */
end_comment
begin_define
DECL|macro|DEEMBOLDEN_RULES_SIZE
define|#
directive|define
name|DEEMBOLDEN_RULES_SIZE
value|9
end_define
begin_decl_stmt
DECL|variable|DEEMBOLDEN_Rules
specifier|static
specifier|const
name|SPH_TweakRule
name|DEEMBOLDEN_Rules
index|[
name|DEEMBOLDEN_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"Courier New"
block|,
literal|0
block|,
literal|"Bold"
block|,
literal|'A'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|0
block|,
literal|"Bold"
block|,
literal|'W'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|0
block|,
literal|"Bold"
block|,
literal|'w'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|0
block|,
literal|"Bold"
block|,
literal|'M'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|0
block|,
literal|"Bold"
block|,
literal|'X'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|0
block|,
literal|"Bold"
block|,
literal|'K'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|0
block|,
literal|"Bold"
block|,
literal|'x'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|0
block|,
literal|"Bold"
block|,
literal|'z'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|0
block|,
literal|"Bold"
block|,
literal|'v'
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Embolden these glyphs slightly.                                       */
end_comment
begin_define
DECL|macro|EMBOLDEN_RULES_SIZE
define|#
directive|define
name|EMBOLDEN_RULES_SIZE
value|2
end_define
begin_decl_stmt
DECL|variable|EMBOLDEN_Rules
specifier|static
specifier|const
name|SPH_TweakRule
name|EMBOLDEN_Rules
index|[
name|EMBOLDEN_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"Courier New"
block|,
literal|0
block|,
literal|"Regular"
block|,
literal|0
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|0
block|,
literal|"Italic"
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* This is a CVT hack that makes thick horizontal stems on 2, 5, 7       */
end_comment
begin_comment
comment|/* similar to Windows XP.                                                */
end_comment
begin_define
DECL|macro|TIMES_NEW_ROMAN_HACK_RULES_SIZE
define|#
directive|define
name|TIMES_NEW_ROMAN_HACK_RULES_SIZE
value|12
end_define
begin_decl_stmt
DECL|variable|TIMES_NEW_ROMAN_HACK_Rules
specifier|static
specifier|const
name|SPH_TweakRule
name|TIMES_NEW_ROMAN_HACK_Rules
index|[
name|TIMES_NEW_ROMAN_HACK_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"Times New Roman"
block|,
literal|16
block|,
literal|"Italic"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|16
block|,
literal|"Italic"
block|,
literal|'5'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|16
block|,
literal|"Italic"
block|,
literal|'7'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|16
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|16
block|,
literal|"Regular"
block|,
literal|'5'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|16
block|,
literal|"Regular"
block|,
literal|'7'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|17
block|,
literal|"Italic"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|17
block|,
literal|"Italic"
block|,
literal|'5'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|17
block|,
literal|"Italic"
block|,
literal|'7'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|17
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|17
block|,
literal|"Regular"
block|,
literal|'5'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|17
block|,
literal|"Regular"
block|,
literal|'7'
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* This fudges distance on 2 to get rid of the vanishing stem issue.     */
end_comment
begin_comment
comment|/* A real solution to this is certainly welcome.                         */
end_comment
begin_define
DECL|macro|COURIER_NEW_2_HACK_RULES_SIZE
define|#
directive|define
name|COURIER_NEW_2_HACK_RULES_SIZE
value|15
end_define
begin_decl_stmt
DECL|variable|COURIER_NEW_2_HACK_Rules
specifier|static
specifier|const
name|SPH_TweakRule
name|COURIER_NEW_2_HACK_Rules
index|[
name|COURIER_NEW_2_HACK_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"Courier New"
block|,
literal|10
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|11
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|12
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|13
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|14
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|15
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|16
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|17
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|18
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|19
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|20
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|21
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|22
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|23
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,
block|{
literal|"Courier New"
block|,
literal|24
block|,
literal|"Regular"
block|,
literal|'2'
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|FORCE_NATURAL_WIDTHS
end_ifndef
begin_comment
comment|/* Use compatible widths with these glyphs.  Compatible widths is always */
end_comment
begin_comment
comment|/* on when doing B/W TrueType instructing, but is used selectively here, */
end_comment
begin_comment
comment|/* typically on glyphs with 3 or more vertical stems.                    */
end_comment
begin_define
DECL|macro|COMPATIBLE_WIDTHS_RULES_SIZE
define|#
directive|define
name|COMPATIBLE_WIDTHS_RULES_SIZE
value|38
end_define
begin_decl_stmt
DECL|variable|COMPATIBLE_WIDTHS_Rules
specifier|static
specifier|const
name|SPH_TweakRule
name|COMPATIBLE_WIDTHS_Rules
index|[
name|COMPATIBLE_WIDTHS_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"Arial Unicode MS"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'m'
block|}
block|,
block|{
literal|"Arial Unicode MS"
block|,
literal|14
block|,
literal|"Regular Class"
block|,
literal|'m'
block|}
block|,
comment|/* Cyrillic small letter sha */
block|{
literal|"Arial"
block|,
literal|10
block|,
literal|"Regular Class"
block|,
literal|0x448
block|}
block|,
block|{
literal|"Arial"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|'m'
block|}
block|,
block|{
literal|"Arial"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'m'
block|}
block|,
comment|/* Cyrillic small letter sha */
block|{
literal|"Arial"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|0x448
block|}
block|,
block|{
literal|"Arial"
block|,
literal|13
block|,
literal|"Regular Class"
block|,
literal|0x448
block|}
block|,
block|{
literal|"Arial"
block|,
literal|14
block|,
literal|"Regular Class"
block|,
literal|'m'
block|}
block|,
comment|/* Cyrillic small letter sha */
block|{
literal|"Arial"
block|,
literal|14
block|,
literal|"Regular Class"
block|,
literal|0x448
block|}
block|,
block|{
literal|"Arial"
block|,
literal|15
block|,
literal|"Regular Class"
block|,
literal|0x448
block|}
block|,
block|{
literal|"Arial"
block|,
literal|17
block|,
literal|"Regular Class"
block|,
literal|'m'
block|}
block|,
block|{
literal|"DejaVu Sans"
block|,
literal|15
block|,
literal|"Regular Class"
block|,
literal|0
block|}
block|,
block|{
literal|"Microsoft Sans Serif"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|0
block|}
block|,
block|{
literal|"Microsoft Sans Serif"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|0
block|}
block|,
block|{
literal|"Segoe UI"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|0
block|}
block|,
block|{
literal|"Monaco"
block|,
literal|0
block|,
literal|"Regular Class"
block|,
literal|0
block|}
block|,
block|{
literal|"Segoe UI"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'m'
block|}
block|,
block|{
literal|"Segoe UI"
block|,
literal|14
block|,
literal|"Regular Class"
block|,
literal|'m'
block|}
block|,
block|{
literal|"Tahoma"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|0
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|16
block|,
literal|"Regular Class"
block|,
literal|'c'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|16
block|,
literal|"Regular Class"
block|,
literal|'m'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|16
block|,
literal|"Regular Class"
block|,
literal|'o'
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|16
block|,
literal|"Regular Class"
block|,
literal|'w'
block|}
block|,
block|{
literal|"Trebuchet MS"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|0
block|}
block|,
block|{
literal|"Trebuchet MS"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|0
block|}
block|,
block|{
literal|"Trebuchet MS"
block|,
literal|14
block|,
literal|"Regular Class"
block|,
literal|0
block|}
block|,
block|{
literal|"Trebuchet MS"
block|,
literal|15
block|,
literal|"Regular Class"
block|,
literal|0
block|}
block|,
block|{
literal|"Ubuntu"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'m'
block|}
block|,
comment|/* Cyrillic small letter sha */
block|{
literal|"Verdana"
block|,
literal|10
block|,
literal|"Regular Class"
block|,
literal|0x448
block|}
block|,
block|{
literal|"Verdana"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|0x448
block|}
block|,
block|{
literal|"Verdana and Clones"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'i'
block|}
block|,
block|{
literal|"Verdana and Clones"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'j'
block|}
block|,
block|{
literal|"Verdana and Clones"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'l'
block|}
block|,
block|{
literal|"Verdana and Clones"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'m'
block|}
block|,
block|{
literal|"Verdana and Clones"
block|,
literal|13
block|,
literal|"Regular Class"
block|,
literal|'i'
block|}
block|,
block|{
literal|"Verdana and Clones"
block|,
literal|13
block|,
literal|"Regular Class"
block|,
literal|'j'
block|}
block|,
block|{
literal|"Verdana and Clones"
block|,
literal|13
block|,
literal|"Regular Class"
block|,
literal|'l'
block|}
block|,
block|{
literal|"Verdana and Clones"
block|,
literal|14
block|,
literal|"Regular Class"
block|,
literal|'m'
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Scaling slightly in the x-direction prior to hinting results in       */
end_comment
begin_comment
comment|/* more visually pleasing glyphs in certain cases.                       */
end_comment
begin_comment
comment|/* This sometimes needs to be coordinated with compatible width rules.   */
end_comment
begin_comment
comment|/* A value of 1000 corresponds to a scaled value of 1.0.                 */
end_comment
begin_define
DECL|macro|X_SCALING_RULES_SIZE
define|#
directive|define
name|X_SCALING_RULES_SIZE
value|50
end_define
begin_decl_stmt
DECL|variable|X_SCALING_Rules
specifier|static
specifier|const
name|SPH_ScaleRule
name|X_SCALING_Rules
index|[
name|X_SCALING_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"DejaVu Sans"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|950
block|}
block|,
block|{
literal|"Verdana and Clones"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'a'
block|,
literal|1100
block|}
block|,
block|{
literal|"Verdana and Clones"
block|,
literal|13
block|,
literal|"Regular Class"
block|,
literal|'a'
block|,
literal|1050
block|}
block|,
block|{
literal|"Arial"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|975
block|}
block|,
block|{
literal|"Arial"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|1050
block|}
block|,
comment|/* Cyrillic small letter el */
block|{
literal|"Arial"
block|,
literal|13
block|,
literal|"Regular Class"
block|,
literal|0x43B
block|,
literal|950
block|}
block|,
block|{
literal|"Arial"
block|,
literal|13
block|,
literal|"Regular Class"
block|,
literal|'o'
block|,
literal|950
block|}
block|,
block|{
literal|"Arial"
block|,
literal|13
block|,
literal|"Regular Class"
block|,
literal|'e'
block|,
literal|950
block|}
block|,
block|{
literal|"Arial"
block|,
literal|14
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|950
block|}
block|,
comment|/* Cyrillic small letter el */
block|{
literal|"Arial"
block|,
literal|15
block|,
literal|"Regular Class"
block|,
literal|0x43B
block|,
literal|925
block|}
block|,
block|{
literal|"Bitstream Vera Sans"
block|,
literal|10
block|,
literal|"Regular/Italic Class"
block|,
literal|0
block|,
literal|1100
block|}
block|,
block|{
literal|"Bitstream Vera Sans"
block|,
literal|12
block|,
literal|"Regular/Italic Class"
block|,
literal|0
block|,
literal|1050
block|}
block|,
block|{
literal|"Bitstream Vera Sans"
block|,
literal|16
block|,
literal|"Regular Class"
block|,
literal|0
block|,
literal|1050
block|}
block|,
block|{
literal|"Bitstream Vera Sans"
block|,
literal|9
block|,
literal|"Regular/Italic Class"
block|,
literal|0
block|,
literal|1050
block|}
block|,
block|{
literal|"DejaVu Sans"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'l'
block|,
literal|975
block|}
block|,
block|{
literal|"DejaVu Sans"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'i'
block|,
literal|975
block|}
block|,
block|{
literal|"DejaVu Sans"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'j'
block|,
literal|975
block|}
block|,
block|{
literal|"DejaVu Sans"
block|,
literal|13
block|,
literal|"Regular Class"
block|,
literal|'l'
block|,
literal|950
block|}
block|,
block|{
literal|"DejaVu Sans"
block|,
literal|13
block|,
literal|"Regular Class"
block|,
literal|'i'
block|,
literal|950
block|}
block|,
block|{
literal|"DejaVu Sans"
block|,
literal|13
block|,
literal|"Regular Class"
block|,
literal|'j'
block|,
literal|950
block|}
block|,
block|{
literal|"DejaVu Sans"
block|,
literal|10
block|,
literal|"Regular/Italic Class"
block|,
literal|0
block|,
literal|1100
block|}
block|,
block|{
literal|"DejaVu Sans"
block|,
literal|12
block|,
literal|"Regular/Italic Class"
block|,
literal|0
block|,
literal|1050
block|}
block|,
block|{
literal|"Georgia"
block|,
literal|10
block|,
literal|""
block|,
literal|0
block|,
literal|1050
block|}
block|,
block|{
literal|"Georgia"
block|,
literal|11
block|,
literal|""
block|,
literal|0
block|,
literal|1100
block|}
block|,
block|{
literal|"Georgia"
block|,
literal|12
block|,
literal|""
block|,
literal|0
block|,
literal|1025
block|}
block|,
block|{
literal|"Georgia"
block|,
literal|13
block|,
literal|""
block|,
literal|0
block|,
literal|1050
block|}
block|,
block|{
literal|"Georgia"
block|,
literal|16
block|,
literal|""
block|,
literal|0
block|,
literal|1050
block|}
block|,
block|{
literal|"Georgia"
block|,
literal|17
block|,
literal|""
block|,
literal|0
block|,
literal|1030
block|}
block|,
block|{
literal|"Liberation Sans"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|1100
block|}
block|,
block|{
literal|"Lucida Grande"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|1100
block|}
block|,
block|{
literal|"Microsoft Sans Serif"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|950
block|}
block|,
block|{
literal|"Microsoft Sans Serif"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|1050
block|}
block|,
block|{
literal|"Segoe UI"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'H'
block|,
literal|1050
block|}
block|,
block|{
literal|"Segoe UI"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|1050
block|}
block|,
block|{
literal|"Segoe UI"
block|,
literal|14
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|1050
block|}
block|,
block|{
literal|"Tahoma"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|'i'
block|,
literal|975
block|}
block|,
block|{
literal|"Tahoma"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|'l'
block|,
literal|975
block|}
block|,
block|{
literal|"Tahoma"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|'j'
block|,
literal|900
block|}
block|,
block|{
literal|"Tahoma"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|918
block|}
block|,
block|{
literal|"Verdana"
block|,
literal|10
block|,
literal|"Regular/Italic Class"
block|,
literal|0
block|,
literal|1100
block|}
block|,
block|{
literal|"Verdana"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|975
block|}
block|,
block|{
literal|"Verdana"
block|,
literal|12
block|,
literal|"Regular/Italic Class"
block|,
literal|0
block|,
literal|1050
block|}
block|,
block|{
literal|"Verdana"
block|,
literal|13
block|,
literal|"Regular/Italic Class"
block|,
literal|'i'
block|,
literal|950
block|}
block|,
block|{
literal|"Verdana"
block|,
literal|13
block|,
literal|"Regular/Italic Class"
block|,
literal|'j'
block|,
literal|950
block|}
block|,
block|{
literal|"Verdana"
block|,
literal|13
block|,
literal|"Regular/Italic Class"
block|,
literal|'l'
block|,
literal|950
block|}
block|,
block|{
literal|"Verdana"
block|,
literal|16
block|,
literal|"Regular Class"
block|,
literal|0
block|,
literal|1050
block|}
block|,
block|{
literal|"Verdana"
block|,
literal|9
block|,
literal|"Regular/Italic Class"
block|,
literal|0
block|,
literal|1050
block|}
block|,
block|{
literal|"Times New Roman"
block|,
literal|16
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|918
block|}
block|,
block|{
literal|"Trebuchet MS"
block|,
literal|11
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|800
block|}
block|,
block|{
literal|"Trebuchet MS"
block|,
literal|12
block|,
literal|"Regular Class"
block|,
literal|'m'
block|,
literal|800
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|COMPATIBLE_WIDTHS_RULES_SIZE
define|#
directive|define
name|COMPATIBLE_WIDTHS_RULES_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|COMPATIBLE_WIDTHS_Rules
specifier|static
specifier|const
name|SPH_TweakRule
name|COMPATIBLE_WIDTHS_Rules
index|[
name|COMPATIBLE_WIDTHS_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"-"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|X_SCALING_RULES_SIZE
define|#
directive|define
name|X_SCALING_RULES_SIZE
value|1
end_define
begin_decl_stmt
DECL|variable|X_SCALING_Rules
specifier|static
specifier|const
name|SPH_ScaleRule
name|X_SCALING_Rules
index|[
name|X_SCALING_RULES_SIZE
index|]
init|=
block|{
block|{
literal|"-"
block|,
literal|0
block|,
literal|""
block|,
literal|0
block|,
literal|1000
block|}
block|,   }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FORCE_NATURAL_WIDTHS */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|is_member_of_family_class
argument_list|(
argument|const FT_String*  detected_font_name
argument_list|,
argument|const FT_String*  rule_font_name
argument_list|)
end_macro
begin_block
block|{
name|FT_UInt
name|i
decl_stmt|,
name|j
decl_stmt|;
comment|/* Does font name match rule family? */
if|if
condition|(
name|strcmp
argument_list|(
name|detected_font_name
argument_list|,
name|rule_font_name
argument_list|)
operator|==
literal|0
condition|)
return|return
name|TRUE
return|;
comment|/* Is font name a wildcard ""? */
if|if
condition|(
name|strcmp
argument_list|(
name|rule_font_name
argument_list|,
literal|""
argument_list|)
operator|==
literal|0
condition|)
return|return
name|TRUE
return|;
comment|/* Is font name contained in a class list? */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|FAMILY_CLASS_RULES_SIZE
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|FAMILY_CLASS_Rules
index|[
name|i
index|]
operator|.
name|name
argument_list|,
name|rule_font_name
argument_list|)
operator|==
literal|0
condition|)
block|{
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|SPH_MAX_CLASS_MEMBERS
condition|;
name|j
operator|++
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|FAMILY_CLASS_Rules
index|[
name|i
index|]
operator|.
name|member
index|[
name|j
index|]
argument_list|,
literal|""
argument_list|)
operator|==
literal|0
condition|)
continue|continue;
if|if
condition|(
name|strcmp
argument_list|(
name|FAMILY_CLASS_Rules
index|[
name|i
index|]
operator|.
name|member
index|[
name|j
index|]
argument_list|,
name|detected_font_name
argument_list|)
operator|==
literal|0
condition|)
return|return
name|TRUE
return|;
block|}
block|}
block|}
return|return
name|FALSE
return|;
block|}
end_block
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|is_member_of_style_class
argument_list|(
argument|const FT_String*  detected_font_style
argument_list|,
argument|const FT_String*  rule_font_style
argument_list|)
end_macro
begin_block
block|{
name|FT_UInt
name|i
decl_stmt|,
name|j
decl_stmt|;
comment|/* Does font style match rule style? */
if|if
condition|(
name|strcmp
argument_list|(
name|detected_font_style
argument_list|,
name|rule_font_style
argument_list|)
operator|==
literal|0
condition|)
return|return
name|TRUE
return|;
comment|/* Is font style a wildcard ""? */
if|if
condition|(
name|strcmp
argument_list|(
name|rule_font_style
argument_list|,
literal|""
argument_list|)
operator|==
literal|0
condition|)
return|return
name|TRUE
return|;
comment|/* Is font style contained in a class list? */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|STYLE_CLASS_RULES_SIZE
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|STYLE_CLASS_Rules
index|[
name|i
index|]
operator|.
name|name
argument_list|,
name|rule_font_style
argument_list|)
operator|==
literal|0
condition|)
block|{
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|SPH_MAX_CLASS_MEMBERS
condition|;
name|j
operator|++
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|STYLE_CLASS_Rules
index|[
name|i
index|]
operator|.
name|member
index|[
name|j
index|]
argument_list|,
literal|""
argument_list|)
operator|==
literal|0
condition|)
continue|continue;
if|if
condition|(
name|strcmp
argument_list|(
name|STYLE_CLASS_Rules
index|[
name|i
index|]
operator|.
name|member
index|[
name|j
index|]
argument_list|,
name|detected_font_style
argument_list|)
operator|==
literal|0
condition|)
return|return
name|TRUE
return|;
block|}
block|}
block|}
return|return
name|FALSE
return|;
block|}
end_block
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|sph_test_tweak
argument_list|(
argument|TT_Face               face
argument_list|,
argument|const FT_String*      family
argument_list|,
argument|FT_UInt               ppem
argument_list|,
argument|const FT_String*      style
argument_list|,
argument|FT_UInt               glyph_index
argument_list|,
argument|const SPH_TweakRule*  rule
argument_list|,
argument|FT_UInt               num_rules
argument_list|)
end_macro
begin_block
block|{
name|FT_UInt
name|i
decl_stmt|;
comment|/* rule checks may be able to be optimized further */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|num_rules
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|family
operator|&&
operator|(
name|is_member_of_family_class
argument_list|(
name|family
argument_list|,
name|rule
index|[
name|i
index|]
operator|.
name|family
argument_list|)
operator|)
condition|)
if|if
condition|(
name|rule
index|[
name|i
index|]
operator|.
name|ppem
operator|==
literal|0
operator|||
name|rule
index|[
name|i
index|]
operator|.
name|ppem
operator|==
name|ppem
condition|)
if|if
condition|(
name|style
operator|&&
name|is_member_of_style_class
argument_list|(
name|style
argument_list|,
name|rule
index|[
name|i
index|]
operator|.
name|style
argument_list|)
condition|)
if|if
condition|(
name|rule
index|[
name|i
index|]
operator|.
name|glyph
operator|==
literal|0
operator|||
name|FT_Get_Char_Index
argument_list|(
operator|(
name|FT_Face
operator|)
name|face
argument_list|,
name|rule
index|[
name|i
index|]
operator|.
name|glyph
argument_list|)
operator|==
name|glyph_index
condition|)
return|return
name|TRUE
return|;
block|}
return|return
name|FALSE
return|;
block|}
end_block
begin_function
specifier|static
name|FT_UInt
DECL|function|scale_test_tweak
name|scale_test_tweak
parameter_list|(
name|TT_Face
name|face
parameter_list|,
specifier|const
name|FT_String
modifier|*
name|family
parameter_list|,
name|FT_UInt
name|ppem
parameter_list|,
specifier|const
name|FT_String
modifier|*
name|style
parameter_list|,
name|FT_UInt
name|glyph_index
parameter_list|,
specifier|const
name|SPH_ScaleRule
modifier|*
name|rule
parameter_list|,
name|FT_UInt
name|num_rules
parameter_list|)
block|{
name|FT_UInt
name|i
decl_stmt|;
comment|/* rule checks may be able to be optimized further */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|num_rules
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|family
operator|&&
operator|(
name|is_member_of_family_class
argument_list|(
name|family
argument_list|,
name|rule
index|[
name|i
index|]
operator|.
name|family
argument_list|)
operator|)
condition|)
if|if
condition|(
name|rule
index|[
name|i
index|]
operator|.
name|ppem
operator|==
literal|0
operator|||
name|rule
index|[
name|i
index|]
operator|.
name|ppem
operator|==
name|ppem
condition|)
if|if
condition|(
name|style
operator|&&
name|is_member_of_style_class
argument_list|(
name|style
argument_list|,
name|rule
index|[
name|i
index|]
operator|.
name|style
argument_list|)
condition|)
if|if
condition|(
name|rule
index|[
name|i
index|]
operator|.
name|glyph
operator|==
literal|0
operator|||
name|FT_Get_Char_Index
argument_list|(
operator|(
name|FT_Face
operator|)
name|face
argument_list|,
name|rule
index|[
name|i
index|]
operator|.
name|glyph
argument_list|)
operator|==
name|glyph_index
condition|)
return|return
name|rule
index|[
name|i
index|]
operator|.
name|scale
return|;
block|}
return|return
literal|1000
return|;
block|}
end_function
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_UInt
argument_list|)
end_macro
begin_macro
name|sph_test_tweak_x_scaling
argument_list|(
argument|TT_Face           face
argument_list|,
argument|const FT_String*  family
argument_list|,
argument|FT_UInt           ppem
argument_list|,
argument|const FT_String*  style
argument_list|,
argument|FT_UInt           glyph_index
argument_list|)
end_macro
begin_block
block|{
return|return
name|scale_test_tweak
argument_list|(
name|face
argument_list|,
name|family
argument_list|,
name|ppem
argument_list|,
name|style
argument_list|,
name|glyph_index
argument_list|,
name|X_SCALING_Rules
argument_list|,
name|X_SCALING_RULES_SIZE
argument_list|)
return|;
block|}
end_block
begin_define
DECL|macro|TWEAK_RULES
define|#
directive|define
name|TWEAK_RULES
parameter_list|(
name|x
parameter_list|)
define|\
value|if ( sph_test_tweak( face, family, ppem, style, glyph_index, \                        x##_Rules, x##_RULES_SIZE ) )           \     loader->exec->sph_tweak_flags |= SPH_TWEAK_##x;
end_define
begin_define
DECL|macro|TWEAK_RULES_EXCEPTIONS
define|#
directive|define
name|TWEAK_RULES_EXCEPTIONS
parameter_list|(
name|x
parameter_list|)
define|\
value|if ( sph_test_tweak( face, family, ppem, style, glyph_index,             \                        x##_Rules_Exceptions, x##_RULES_EXCEPTIONS_SIZE ) ) \     loader->exec->sph_tweak_flags&= ~SPH_TWEAK_##x;
end_define
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|sph_set_tweaks
name|sph_set_tweaks
argument_list|(
argument|TT_Loader  loader
argument_list|,
argument|FT_UInt    glyph_index
argument_list|)
end_macro
begin_block
block|{
name|TT_Face
name|face
init|=
operator|(
name|TT_Face
operator|)
name|loader
operator|->
name|face
decl_stmt|;
name|FT_String
modifier|*
name|family
init|=
name|face
operator|->
name|root
operator|.
name|family_name
decl_stmt|;
name|int
name|ppem
init|=
name|loader
operator|->
name|size
operator|->
name|metrics
operator|.
name|x_ppem
decl_stmt|;
name|FT_String
modifier|*
name|style
init|=
name|face
operator|->
name|root
operator|.
name|style_name
decl_stmt|;
comment|/* don't apply rules if style isn't set */
if|if
condition|(
operator|!
name|face
operator|->
name|root
operator|.
name|style_name
condition|)
return|return;
ifdef|#
directive|ifdef
name|SPH_DEBUG_MORE_VERBOSE
name|printf
argument_list|(
literal|"%s,%d,%s,%c=%d "
argument_list|,
name|family
argument_list|,
name|ppem
argument_list|,
name|style
argument_list|,
name|glyph_index
argument_list|,
name|glyph_index
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|TWEAK_RULES
argument_list|(
name|PIXEL_HINTING
argument_list|)
expr_stmt|;
if|if
condition|(
name|loader
operator|->
name|exec
operator|->
name|sph_tweak_flags
operator|&
name|SPH_TWEAK_PIXEL_HINTING
condition|)
block|{
name|loader
operator|->
name|exec
operator|->
name|ignore_x_mode
operator|=
name|FALSE
expr_stmt|;
return|return;
block|}
name|TWEAK_RULES
argument_list|(
name|ALLOW_X_DMOVE
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|ALWAYS_DO_DELTAP
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|ALWAYS_SKIP_DELTAP
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|DEEMBOLDEN
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|DO_SHPIX
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|EMBOLDEN
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|MIAP_HACK
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|NORMAL_ROUND
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|NO_ALIGNRP_AFTER_IUP
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|NO_CALL_AFTER_IUP
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|NO_DELTAP_AFTER_IUP
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|RASTERIZER_35
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|SKIP_IUP
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|SKIP_OFFPIXEL_Y_MOVES
argument_list|)
expr_stmt|;
name|TWEAK_RULES_EXCEPTIONS
argument_list|(
name|SKIP_OFFPIXEL_Y_MOVES
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|SKIP_NONPIXEL_Y_MOVES_DELTAP
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|SKIP_NONPIXEL_Y_MOVES
argument_list|)
expr_stmt|;
name|TWEAK_RULES_EXCEPTIONS
argument_list|(
name|SKIP_NONPIXEL_Y_MOVES
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|ROUND_NONPIXEL_Y_MOVES
argument_list|)
expr_stmt|;
name|TWEAK_RULES_EXCEPTIONS
argument_list|(
name|ROUND_NONPIXEL_Y_MOVES
argument_list|)
expr_stmt|;
if|if
condition|(
name|loader
operator|->
name|exec
operator|->
name|sph_tweak_flags
operator|&
name|SPH_TWEAK_RASTERIZER_35
condition|)
block|{
if|if
condition|(
name|loader
operator|->
name|exec
operator|->
name|rasterizer_version
operator|!=
name|TT_INTERPRETER_VERSION_35
condition|)
block|{
name|loader
operator|->
name|exec
operator|->
name|rasterizer_version
operator|=
name|TT_INTERPRETER_VERSION_35
expr_stmt|;
name|loader
operator|->
name|exec
operator|->
name|size
operator|->
name|cvt_ready
operator|=
operator|-
literal|1
expr_stmt|;
name|tt_size_ready_bytecode
argument_list|(
name|loader
operator|->
name|exec
operator|->
name|size
argument_list|,
name|FT_BOOL
argument_list|(
name|loader
operator|->
name|load_flags
operator|&
name|FT_LOAD_PEDANTIC
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|loader
operator|->
name|exec
operator|->
name|rasterizer_version
operator|=
name|TT_INTERPRETER_VERSION_35
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|loader
operator|->
name|exec
operator|->
name|rasterizer_version
operator|!=
name|SPH_OPTION_SET_RASTERIZER_VERSION
condition|)
block|{
name|loader
operator|->
name|exec
operator|->
name|rasterizer_version
operator|=
name|SPH_OPTION_SET_RASTERIZER_VERSION
expr_stmt|;
name|loader
operator|->
name|exec
operator|->
name|size
operator|->
name|cvt_ready
operator|=
operator|-
literal|1
expr_stmt|;
name|tt_size_ready_bytecode
argument_list|(
name|loader
operator|->
name|exec
operator|->
name|size
argument_list|,
name|FT_BOOL
argument_list|(
name|loader
operator|->
name|load_flags
operator|&
name|FT_LOAD_PEDANTIC
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|loader
operator|->
name|exec
operator|->
name|rasterizer_version
operator|=
name|SPH_OPTION_SET_RASTERIZER_VERSION
expr_stmt|;
block|}
if|if
condition|(
name|IS_HINTED
argument_list|(
name|loader
operator|->
name|load_flags
argument_list|)
condition|)
block|{
name|TWEAK_RULES
argument_list|(
name|TIMES_NEW_ROMAN_HACK
argument_list|)
expr_stmt|;
name|TWEAK_RULES
argument_list|(
name|COURIER_NEW_2_HACK
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|sph_test_tweak
argument_list|(
name|face
argument_list|,
name|family
argument_list|,
name|ppem
argument_list|,
name|style
argument_list|,
name|glyph_index
argument_list|,
name|COMPATIBILITY_MODE_Rules
argument_list|,
name|COMPATIBILITY_MODE_RULES_SIZE
argument_list|)
condition|)
name|loader
operator|->
name|exec
operator|->
name|face
operator|->
name|sph_compatibility_mode
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
name|IS_HINTED
argument_list|(
name|loader
operator|->
name|load_flags
argument_list|)
condition|)
block|{
if|if
condition|(
name|sph_test_tweak
argument_list|(
name|face
argument_list|,
name|family
argument_list|,
name|ppem
argument_list|,
name|style
argument_list|,
name|glyph_index
argument_list|,
name|COMPATIBLE_WIDTHS_Rules
argument_list|,
name|COMPATIBLE_WIDTHS_RULES_SIZE
argument_list|)
condition|)
name|loader
operator|->
name|exec
operator|->
name|compatible_widths
operator||=
name|TRUE
expr_stmt|;
block|}
block|}
end_block
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !TT_CONFIG_OPTION_SUBPIXEL_HINTING */
end_comment
begin_comment
comment|/* ANSI C doesn't like empty source files */
end_comment
begin_typedef
DECL|typedef|_tt_subpix_dummy
typedef|typedef
name|int
name|_tt_subpix_dummy
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !TT_CONFIG_OPTION_SUBPIXEL_HINTING */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
