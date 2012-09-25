begin_unit
begin_comment
comment|/*  * Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies)  *  * This is part of HarfBuzz, an OpenType Layout engine library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HARFBUZZ_SHAPER_H
end_ifndef
begin_define
DECL|macro|HARFBUZZ_SHAPER_H
define|#
directive|define
name|HARFBUZZ_SHAPER_H
end_define
begin_include
include|#
directive|include
file|"harfbuzz-global.h"
end_include
begin_include
include|#
directive|include
file|"harfbuzz-gdef.h"
end_include
begin_include
include|#
directive|include
file|"harfbuzz-gpos.h"
end_include
begin_include
include|#
directive|include
file|"harfbuzz-gsub.h"
end_include
begin_include
include|#
directive|include
file|"harfbuzz-external.h"
end_include
begin_include
include|#
directive|include
file|"harfbuzz-stream-private.h"
end_include
begin_macro
name|HB_BEGIN_HEADER
end_macro
begin_comment
comment|/*    using anything else than signed or unsigned for bitfields in C is non standard,    but accepted by almost all compilers. And it gives a significant reduction in    memory consumption as HB_CharAttributes and HB_GlyphAttributes will not have    a 4 byte alignment */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__xlC__
end_ifdef
begin_typedef
DECL|typedef|hb_bitfield
typedef|typedef
name|unsigned
name|hb_bitfield
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_typedef
typedef|typedef
name|hb_uint8
name|hb_bitfield
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HB_Script_Common
name|HB_Script_Common
block|,
DECL|enumerator|HB_Script_Greek
name|HB_Script_Greek
block|,
DECL|enumerator|HB_Script_Cyrillic
name|HB_Script_Cyrillic
block|,
DECL|enumerator|HB_Script_Armenian
name|HB_Script_Armenian
block|,
DECL|enumerator|HB_Script_Hebrew
name|HB_Script_Hebrew
block|,
DECL|enumerator|HB_Script_Arabic
name|HB_Script_Arabic
block|,
DECL|enumerator|HB_Script_Syriac
name|HB_Script_Syriac
block|,
DECL|enumerator|HB_Script_Thaana
name|HB_Script_Thaana
block|,
DECL|enumerator|HB_Script_Devanagari
name|HB_Script_Devanagari
block|,
DECL|enumerator|HB_Script_Bengali
name|HB_Script_Bengali
block|,
DECL|enumerator|HB_Script_Gurmukhi
name|HB_Script_Gurmukhi
block|,
DECL|enumerator|HB_Script_Gujarati
name|HB_Script_Gujarati
block|,
DECL|enumerator|HB_Script_Oriya
name|HB_Script_Oriya
block|,
DECL|enumerator|HB_Script_Tamil
name|HB_Script_Tamil
block|,
DECL|enumerator|HB_Script_Telugu
name|HB_Script_Telugu
block|,
DECL|enumerator|HB_Script_Kannada
name|HB_Script_Kannada
block|,
DECL|enumerator|HB_Script_Malayalam
name|HB_Script_Malayalam
block|,
DECL|enumerator|HB_Script_Sinhala
name|HB_Script_Sinhala
block|,
DECL|enumerator|HB_Script_Thai
name|HB_Script_Thai
block|,
DECL|enumerator|HB_Script_Lao
name|HB_Script_Lao
block|,
DECL|enumerator|HB_Script_Tibetan
name|HB_Script_Tibetan
block|,
DECL|enumerator|HB_Script_Myanmar
name|HB_Script_Myanmar
block|,
DECL|enumerator|HB_Script_Georgian
name|HB_Script_Georgian
block|,
DECL|enumerator|HB_Script_Hangul
name|HB_Script_Hangul
block|,
DECL|enumerator|HB_Script_Ogham
name|HB_Script_Ogham
block|,
DECL|enumerator|HB_Script_Runic
name|HB_Script_Runic
block|,
DECL|enumerator|HB_Script_Khmer
name|HB_Script_Khmer
block|,
DECL|enumerator|HB_Script_Nko
name|HB_Script_Nko
block|,
DECL|enumerator|HB_Script_Inherited
name|HB_Script_Inherited
block|,
DECL|enumerator|HB_ScriptCount
name|HB_ScriptCount
init|=
name|HB_Script_Inherited
comment|/*         HB_Script_Latin = Common,         HB_Script_Ethiopic = Common,         HB_Script_Cherokee = Common,         HB_Script_CanadianAboriginal = Common,         HB_Script_Mongolian = Common,         HB_Script_Hiragana = Common,         HB_Script_Katakana = Common,         HB_Script_Bopomofo = Common,         HB_Script_Han = Common,         HB_Script_Yi = Common,         HB_Script_OldItalic = Common,         HB_Script_Gothic = Common,         HB_Script_Deseret = Common,         HB_Script_Tagalog = Common,         HB_Script_Hanunoo = Common,         HB_Script_Buhid = Common,         HB_Script_Tagbanwa = Common,         HB_Script_Limbu = Common,         HB_Script_TaiLe = Common,         HB_Script_LinearB = Common,         HB_Script_Ugaritic = Common,         HB_Script_Shavian = Common,         HB_Script_Osmanya = Common,         HB_Script_Cypriot = Common,         HB_Script_Braille = Common,         HB_Script_Buginese = Common,         HB_Script_Coptic = Common,         HB_Script_NewTaiLue = Common,         HB_Script_Glagolitic = Common,         HB_Script_Tifinagh = Common,         HB_Script_SylotiNagri = Common,         HB_Script_OldPersian = Common,         HB_Script_Kharoshthi = Common,         HB_Script_Balinese = Common,         HB_Script_Cuneiform = Common,         HB_Script_Phoenician = Common,         HB_Script_PhagsPa = Common,         */
block|}
DECL|typedef|HB_Script
name|HB_Script
typedef|;
end_typedef
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|pos
name|hb_uint32
name|pos
decl_stmt|;
DECL|member|length
name|hb_uint32
name|length
decl_stmt|;
DECL|member|script
name|HB_Script
name|script
decl_stmt|;
DECL|member|bidiLevel
name|hb_uint8
name|bidiLevel
decl_stmt|;
block|}
DECL|typedef|HB_ScriptItem
name|HB_ScriptItem
typedef|;
end_typedef
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|graphemeBoundary
name|hb_bitfield
name|graphemeBoundary
range|:
literal|1
decl_stmt|;
comment|/* Valid cursor position (for left/right arrow) */
DECL|member|wordBreak
name|hb_bitfield
name|wordBreak
range|:
literal|1
decl_stmt|;
DECL|member|sentenceBoundary
name|hb_bitfield
name|sentenceBoundary
range|:
literal|1
decl_stmt|;
DECL|member|lineBreak
name|hb_bitfield
name|lineBreak
range|:
literal|1
decl_stmt|;
DECL|member|whiteSpace
name|hb_bitfield
name|whiteSpace
range|:
literal|1
decl_stmt|;
comment|/* A unicode whitespace character */
DECL|member|wordStart
name|hb_bitfield
name|wordStart
range|:
literal|1
decl_stmt|;
DECL|member|wordEnd
name|hb_bitfield
name|wordEnd
range|:
literal|1
decl_stmt|;
DECL|member|unused
name|hb_bitfield
name|unused
range|:
literal|1
decl_stmt|;
block|}
DECL|typedef|HB_CharAttributes
name|HB_CharAttributes
typedef|;
end_typedef
begin_function_decl
name|void
name|HB_GetTailoredCharAttributes
parameter_list|(
specifier|const
name|HB_UChar16
modifier|*
name|string
parameter_list|,
name|hb_uint32
name|stringLength
parameter_list|,
specifier|const
name|HB_ScriptItem
modifier|*
name|items
parameter_list|,
name|hb_uint32
name|numItems
parameter_list|,
name|HB_CharAttributes
modifier|*
name|attributes
parameter_list|)
function_decl|;
end_function_decl
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HB_LeftToRight
name|HB_LeftToRight
init|=
literal|0
block|,
DECL|enumerator|HB_RightToLeft
name|HB_RightToLeft
init|=
literal|1
block|}
DECL|typedef|HB_StringToGlyphsFlags
name|HB_StringToGlyphsFlags
typedef|;
end_typedef
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HB_ShaperFlag_Default
name|HB_ShaperFlag_Default
init|=
literal|0
block|,
DECL|enumerator|HB_ShaperFlag_NoKerning
name|HB_ShaperFlag_NoKerning
init|=
literal|1
block|,
DECL|enumerator|HB_ShaperFlag_UseDesignMetrics
name|HB_ShaperFlag_UseDesignMetrics
init|=
literal|2
block|}
DECL|typedef|HB_ShaperFlag
name|HB_ShaperFlag
typedef|;
end_typedef
begin_comment
comment|/*     highest value means highest priority for justification. Justification is done by first inserting kashidas    starting with the highest priority positions, then stretching spaces, afterwards extending inter char    spacing, and last spacing between arabic words.    NoJustification is for example set for arabic where no Kashida can be inserted or for diacritics. */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HB_NoJustification
name|HB_NoJustification
init|=
literal|0
block|,
comment|/* Justification can't be applied after this glyph */
DECL|enumerator|HB_Arabic_Space
name|HB_Arabic_Space
init|=
literal|1
block|,
comment|/* This glyph represents a space inside arabic text */
DECL|enumerator|HB_Character
name|HB_Character
init|=
literal|2
block|,
comment|/* Inter-character justification point follows this glyph */
DECL|enumerator|HB_Space
name|HB_Space
init|=
literal|4
block|,
comment|/* This glyph represents a blank outside an Arabic run */
DECL|enumerator|HB_Arabic_Normal
name|HB_Arabic_Normal
init|=
literal|7
block|,
comment|/* Normal Middle-Of-Word glyph that connects to the right (begin) */
DECL|enumerator|HB_Arabic_Waw
name|HB_Arabic_Waw
init|=
literal|8
block|,
comment|/* Next character is final form of Waw/Ain/Qaf/Fa */
DECL|enumerator|HB_Arabic_BaRa
name|HB_Arabic_BaRa
init|=
literal|9
block|,
comment|/* Next two chars are Ba + Ra/Ya/AlefMaksura */
DECL|enumerator|HB_Arabic_Alef
name|HB_Arabic_Alef
init|=
literal|10
block|,
comment|/* Next character is final form of Alef/Tah/Lam/Kaf/Gaf */
DECL|enumerator|HB_Arabic_HaaDal
name|HB_Arabic_HaaDal
init|=
literal|11
block|,
comment|/* Next character is final form of Haa/Dal/Taa Marbutah */
DECL|enumerator|HB_Arabic_Seen
name|HB_Arabic_Seen
init|=
literal|12
block|,
comment|/* Initial or Medial form Of Seen/Sad */
DECL|enumerator|HB_Arabic_Kashida
name|HB_Arabic_Kashida
init|=
literal|13
comment|/* Kashida(U+640) in middle of word */
block|}
DECL|typedef|HB_JustificationClass
name|HB_JustificationClass
typedef|;
end_typedef
begin_comment
comment|/* This structure is binary compatible with Uniscribe's SCRIPT_VISATTR. Would be nice to keep  * it like that. If this is a problem please tell Trolltech :)  */
end_comment
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|justification
name|hb_bitfield
name|justification
range|:
literal|4
decl_stmt|;
comment|/* Justification class */
DECL|member|clusterStart
name|hb_bitfield
name|clusterStart
range|:
literal|1
decl_stmt|;
comment|/* First glyph of representation of cluster */
DECL|member|mark
name|hb_bitfield
name|mark
range|:
literal|1
decl_stmt|;
comment|/* needs to be positioned around base char */
DECL|member|zeroWidth
name|hb_bitfield
name|zeroWidth
range|:
literal|1
decl_stmt|;
comment|/* ZWJ, ZWNJ etc, with no width */
DECL|member|dontPrint
name|hb_bitfield
name|dontPrint
range|:
literal|1
decl_stmt|;
DECL|member|combiningClass
name|hb_bitfield
name|combiningClass
range|:
literal|8
decl_stmt|;
block|}
DECL|typedef|HB_GlyphAttributes
name|HB_GlyphAttributes
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_GetFontTableFunc
typedef|typedef
name|HB_Error
function_decl|(
modifier|*
name|HB_GetFontTableFunc
function_decl|)
parameter_list|(
name|void
modifier|*
name|font
parameter_list|,
name|HB_Tag
name|tag
parameter_list|,
name|HB_Byte
modifier|*
name|buffer
parameter_list|,
name|HB_UInt
modifier|*
name|length
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|struct|HB_FaceRec_
typedef|typedef
struct|struct
name|HB_FaceRec_
block|{
DECL|member|isSymbolFont
name|HB_Bool
name|isSymbolFont
decl_stmt|;
DECL|member|gdef
name|HB_GDEF
name|gdef
decl_stmt|;
DECL|member|gsub
name|HB_GSUB
name|gsub
decl_stmt|;
DECL|member|gpos
name|HB_GPOS
name|gpos
decl_stmt|;
DECL|member|supported_scripts
name|HB_Bool
name|supported_scripts
index|[
name|HB_ScriptCount
index|]
decl_stmt|;
DECL|member|buffer
name|HB_Buffer
name|buffer
decl_stmt|;
DECL|member|current_script
name|HB_Script
name|current_script
decl_stmt|;
DECL|member|current_flags
name|int
name|current_flags
decl_stmt|;
comment|/* HB_ShaperFlags */
DECL|member|has_opentype_kerning
name|HB_Bool
name|has_opentype_kerning
decl_stmt|;
DECL|member|glyphs_substituted
name|HB_Bool
name|glyphs_substituted
decl_stmt|;
DECL|member|tmpAttributes
name|HB_GlyphAttributes
modifier|*
name|tmpAttributes
decl_stmt|;
DECL|member|tmpLogClusters
name|unsigned
name|int
modifier|*
name|tmpLogClusters
decl_stmt|;
DECL|member|length
name|int
name|length
decl_stmt|;
DECL|member|orig_nglyphs
name|int
name|orig_nglyphs
decl_stmt|;
DECL|member|font_for_init
name|void
modifier|*
name|font_for_init
decl_stmt|;
DECL|member|get_font_table_func
name|HB_GetFontTableFunc
name|get_font_table_func
decl_stmt|;
block|}
DECL|typedef|HB_FaceRec
name|HB_FaceRec
typedef|;
end_typedef
begin_function_decl
name|HB_Face
name|HB_NewFace
parameter_list|(
name|void
modifier|*
name|font
parameter_list|,
name|HB_GetFontTableFunc
name|tableFunc
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|HB_Face
name|HB_AllocFace
parameter_list|(
name|void
modifier|*
name|font
parameter_list|,
name|HB_GetFontTableFunc
name|tableFunc
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|HB_Face
name|HB_LoadFace
parameter_list|(
name|HB_Face
name|face
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|HB_FreeFace
parameter_list|(
name|HB_Face
name|face
parameter_list|)
function_decl|;
end_function_decl
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|x
DECL|member|y
name|HB_Fixed
name|x
decl_stmt|,
name|y
decl_stmt|;
DECL|member|width
DECL|member|height
name|HB_Fixed
name|width
decl_stmt|,
name|height
decl_stmt|;
DECL|member|xOffset
DECL|member|yOffset
name|HB_Fixed
name|xOffset
decl_stmt|,
name|yOffset
decl_stmt|;
block|}
DECL|typedef|HB_GlyphMetrics
name|HB_GlyphMetrics
typedef|;
end_typedef
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HB_FontAscent
name|HB_FontAscent
block|}
DECL|typedef|HB_FontMetric
name|HB_FontMetric
typedef|;
end_typedef
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|convertStringToGlyphIndices
name|HB_Bool
function_decl|(
modifier|*
name|convertStringToGlyphIndices
function_decl|)
parameter_list|(
name|HB_Font
name|font
parameter_list|,
specifier|const
name|HB_UChar16
modifier|*
name|string
parameter_list|,
name|hb_uint32
name|length
parameter_list|,
name|HB_Glyph
modifier|*
name|glyphs
parameter_list|,
name|hb_uint32
modifier|*
name|numGlyphs
parameter_list|,
name|HB_Bool
name|rightToLeft
parameter_list|)
function_decl|;
DECL|member|getGlyphAdvances
name|void
function_decl|(
modifier|*
name|getGlyphAdvances
function_decl|)
parameter_list|(
name|HB_Font
name|font
parameter_list|,
specifier|const
name|HB_Glyph
modifier|*
name|glyphs
parameter_list|,
name|hb_uint32
name|numGlyphs
parameter_list|,
name|HB_Fixed
modifier|*
name|advances
parameter_list|,
name|int
name|flags
comment|/*HB_ShaperFlag*/
parameter_list|)
function_decl|;
DECL|member|canRender
name|HB_Bool
function_decl|(
modifier|*
name|canRender
function_decl|)
parameter_list|(
name|HB_Font
name|font
parameter_list|,
specifier|const
name|HB_UChar16
modifier|*
name|string
parameter_list|,
name|hb_uint32
name|length
parameter_list|)
function_decl|;
comment|/* implementation needs to make sure to load a scaled glyph, so /no/ FT_LOAD_NO_SCALE */
DECL|member|getPointInOutline
name|HB_Error
function_decl|(
modifier|*
name|getPointInOutline
function_decl|)
parameter_list|(
name|HB_Font
name|font
parameter_list|,
name|HB_Glyph
name|glyph
parameter_list|,
name|int
name|flags
comment|/*HB_ShaperFlag*/
parameter_list|,
name|hb_uint32
name|point
parameter_list|,
name|HB_Fixed
modifier|*
name|xpos
parameter_list|,
name|HB_Fixed
modifier|*
name|ypos
parameter_list|,
name|hb_uint32
modifier|*
name|nPoints
parameter_list|)
function_decl|;
DECL|member|getGlyphMetrics
name|void
function_decl|(
modifier|*
name|getGlyphMetrics
function_decl|)
parameter_list|(
name|HB_Font
name|font
parameter_list|,
name|HB_Glyph
name|glyph
parameter_list|,
name|HB_GlyphMetrics
modifier|*
name|metrics
parameter_list|)
function_decl|;
DECL|member|getFontMetric
name|HB_Fixed
function_decl|(
modifier|*
name|getFontMetric
function_decl|)
parameter_list|(
name|HB_Font
name|font
parameter_list|,
name|HB_FontMetric
name|metric
parameter_list|)
function_decl|;
block|}
DECL|typedef|HB_FontClass
name|HB_FontClass
typedef|;
end_typedef
begin_typedef
DECL|struct|HB_Font_
typedef|typedef
struct|struct
name|HB_Font_
block|{
DECL|member|klass
specifier|const
name|HB_FontClass
modifier|*
name|klass
decl_stmt|;
comment|/* Metrics */
DECL|member|x_ppem
DECL|member|y_ppem
name|HB_UShort
name|x_ppem
decl_stmt|,
name|y_ppem
decl_stmt|;
DECL|member|x_scale
DECL|member|y_scale
name|HB_16Dot16
name|x_scale
decl_stmt|,
name|y_scale
decl_stmt|;
DECL|member|userData
name|void
modifier|*
name|userData
decl_stmt|;
block|}
DECL|typedef|HB_FontRec
name|HB_FontRec
typedef|;
end_typedef
begin_typedef
DECL|typedef|HB_ShaperItem
typedef|typedef
name|struct
name|HB_ShaperItem_
name|HB_ShaperItem
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ShaperItem_
struct|struct
name|HB_ShaperItem_
block|{
DECL|member|string
specifier|const
name|HB_UChar16
modifier|*
name|string
decl_stmt|;
comment|/* input: the Unicode UTF16 text to be shaped */
DECL|member|stringLength
name|hb_uint32
name|stringLength
decl_stmt|;
comment|/* input: the length of the input in 16-bit words */
DECL|member|item
name|HB_ScriptItem
name|item
decl_stmt|;
comment|/* input: the current run to be shaped: a run of text all in the same script that is a substring of<string> */
DECL|member|font
name|HB_Font
name|font
decl_stmt|;
comment|/* input: the font: scale, units and function pointers supplying glyph indices and metrics */
DECL|member|face
name|HB_Face
name|face
decl_stmt|;
comment|/* input: the shaper state; current script, access to the OpenType tables , etc. */
DECL|member|shaperFlags
name|int
name|shaperFlags
decl_stmt|;
comment|/* input (unused) should be set to 0; intended to support flags defined in HB_ShaperFlag */
DECL|member|glyphIndicesPresent
name|HB_Bool
name|glyphIndicesPresent
decl_stmt|;
comment|/* input: true if the<glyphs> array contains glyph indices ready to be shaped */
DECL|member|initialGlyphCount
name|hb_uint32
name|initialGlyphCount
decl_stmt|;
comment|/* input: if glyphIndicesPresent is true, the number of glyph indices in the<glyphs> array */
DECL|member|num_glyphs
name|hb_uint32
name|num_glyphs
decl_stmt|;
comment|/* input: capacity of output arrays<glyphs>,<attributes>,<advances>,<offsets>, and<log_clusters>; */
comment|/* output: required capacity (may be larger than actual capacity) */
DECL|member|glyphs
name|HB_Glyph
modifier|*
name|glyphs
decl_stmt|;
comment|/* output:<num_glyphs> indices of shaped glyphs */
DECL|member|attributes
name|HB_GlyphAttributes
modifier|*
name|attributes
decl_stmt|;
comment|/* output:<num_glyphs> glyph attributes */
DECL|member|advances
name|HB_Fixed
modifier|*
name|advances
decl_stmt|;
comment|/* output:<num_glyphs> advances */
DECL|member|offsets
name|HB_FixedPoint
modifier|*
name|offsets
decl_stmt|;
comment|/* output:<num_glyphs> offsets */
DECL|member|log_clusters
name|unsigned
name|short
modifier|*
name|log_clusters
decl_stmt|;
comment|/* output: for each output glyph, the index in the input of the start of its logical cluster */
comment|/* internal */
DECL|member|kerning_applied
name|HB_Bool
name|kerning_applied
decl_stmt|;
comment|/* output: true if kerning was applied by the shaper */
block|}
struct|;
end_struct
begin_function_decl
name|HB_Bool
name|HB_ShapeItem
parameter_list|(
name|HB_ShaperItem
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|HB_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
