begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttnameid.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueType name ID definitions (specification only).                   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2004, 2006-2008, 2012-2014 by                           */
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
begin_ifndef
ifndef|#
directive|ifndef
name|__TTNAMEID_H__
end_ifndef
begin_define
DECL|macro|__TTNAMEID_H__
define|#
directive|define
name|__TTNAMEID_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_expr_stmt
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Section>                                                             */
comment|/*    truetype_tables                                                    */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Possible values for the `platform' identifier code in the name        */
comment|/* records of the TTF `name' table.                                      */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/***********************************************************************    *    * @enum:    *   TT_PLATFORM_XXX    *    * @description:    *   A list of valid values for the `platform_id' identifier code in    *   @FT_CharMapRec and @FT_SfntName structures.    *    * @values:    *   TT_PLATFORM_APPLE_UNICODE ::    *     Used by Apple to indicate a Unicode character map and/or name entry.    *     See @TT_APPLE_ID_XXX for corresponding `encoding_id' values.  Note    *     that name entries in this format are coded as big-endian UCS-2    *     character codes _only_.    *    *   TT_PLATFORM_MACINTOSH ::    *     Used by Apple to indicate a MacOS-specific charmap and/or name entry.    *     See @TT_MAC_ID_XXX for corresponding `encoding_id' values.  Note that    *     most TrueType fonts contain an Apple roman charmap to be usable on    *     MacOS systems (even if they contain a Microsoft charmap as well).    *    *   TT_PLATFORM_ISO ::    *     This value was used to specify ISO/IEC 10646 charmaps.  It is however    *     now deprecated.  See @TT_ISO_ID_XXX for a list of corresponding    *     `encoding_id' values.    *    *   TT_PLATFORM_MICROSOFT ::    *     Used by Microsoft to indicate Windows-specific charmaps.  See    *     @TT_MS_ID_XXX for a list of corresponding `encoding_id' values.    *     Note that most fonts contain a Unicode charmap using    *     (TT_PLATFORM_MICROSOFT, @TT_MS_ID_UNICODE_CS).    *    *   TT_PLATFORM_CUSTOM ::    *     Used to indicate application-specific charmaps.    *    *   TT_PLATFORM_ADOBE ::    *     This value isn't part of any font format specification, but is used    *     by FreeType to report Adobe-specific charmaps in an @FT_CharMapRec    *     structure.  See @TT_ADOBE_ID_XXX.    */
DECL|macro|TT_PLATFORM_APPLE_UNICODE
define|#
directive|define
name|TT_PLATFORM_APPLE_UNICODE
value|0
DECL|macro|TT_PLATFORM_MACINTOSH
define|#
directive|define
name|TT_PLATFORM_MACINTOSH
value|1
DECL|macro|TT_PLATFORM_ISO
define|#
directive|define
name|TT_PLATFORM_ISO
value|2
comment|/* deprecated */
DECL|macro|TT_PLATFORM_MICROSOFT
define|#
directive|define
name|TT_PLATFORM_MICROSOFT
value|3
DECL|macro|TT_PLATFORM_CUSTOM
define|#
directive|define
name|TT_PLATFORM_CUSTOM
value|4
DECL|macro|TT_PLATFORM_ADOBE
define|#
directive|define
name|TT_PLATFORM_ADOBE
value|7
comment|/* artificial */
comment|/***********************************************************************    *    * @enum:    *   TT_APPLE_ID_XXX    *    * @description:    *   A list of valid values for the `encoding_id' for    *   @TT_PLATFORM_APPLE_UNICODE charmaps and name entries.    *    * @values:    *   TT_APPLE_ID_DEFAULT ::    *     Unicode version 1.0.    *    *   TT_APPLE_ID_UNICODE_1_1 ::    *     Unicode 1.1; specifies Hangul characters starting at U+34xx.    *    *   TT_APPLE_ID_ISO_10646 ::    *     Deprecated (identical to preceding).    *    *   TT_APPLE_ID_UNICODE_2_0 ::    *     Unicode 2.0 and beyond (UTF-16 BMP only).    *    *   TT_APPLE_ID_UNICODE_32 ::    *     Unicode 3.1 and beyond, using UTF-32.    *    *   TT_APPLE_ID_VARIANT_SELECTOR ::    *     From Adobe, not Apple.  Not a normal cmap.  Specifies variations    *     on a real cmap.    */
DECL|macro|TT_APPLE_ID_DEFAULT
define|#
directive|define
name|TT_APPLE_ID_DEFAULT
value|0
comment|/* Unicode 1.0 */
DECL|macro|TT_APPLE_ID_UNICODE_1_1
define|#
directive|define
name|TT_APPLE_ID_UNICODE_1_1
value|1
comment|/* specify Hangul at U+34xx */
DECL|macro|TT_APPLE_ID_ISO_10646
define|#
directive|define
name|TT_APPLE_ID_ISO_10646
value|2
comment|/* deprecated */
DECL|macro|TT_APPLE_ID_UNICODE_2_0
define|#
directive|define
name|TT_APPLE_ID_UNICODE_2_0
value|3
comment|/* or later */
DECL|macro|TT_APPLE_ID_UNICODE_32
define|#
directive|define
name|TT_APPLE_ID_UNICODE_32
value|4
comment|/* 2.0 or later, full repertoire */
DECL|macro|TT_APPLE_ID_VARIANT_SELECTOR
define|#
directive|define
name|TT_APPLE_ID_VARIANT_SELECTOR
value|5
comment|/* variation selector data */
comment|/***********************************************************************    *    * @enum:    *   TT_MAC_ID_XXX    *    * @description:    *   A list of valid values for the `encoding_id' for    *   @TT_PLATFORM_MACINTOSH charmaps and name entries.    *    * @values:    *   TT_MAC_ID_ROMAN ::    *   TT_MAC_ID_JAPANESE ::    *   TT_MAC_ID_TRADITIONAL_CHINESE ::    *   TT_MAC_ID_KOREAN ::    *   TT_MAC_ID_ARABIC ::    *   TT_MAC_ID_HEBREW ::    *   TT_MAC_ID_GREEK ::    *   TT_MAC_ID_RUSSIAN ::    *   TT_MAC_ID_RSYMBOL ::    *   TT_MAC_ID_DEVANAGARI ::    *   TT_MAC_ID_GURMUKHI ::    *   TT_MAC_ID_GUJARATI ::    *   TT_MAC_ID_ORIYA ::    *   TT_MAC_ID_BENGALI ::    *   TT_MAC_ID_TAMIL ::    *   TT_MAC_ID_TELUGU ::    *   TT_MAC_ID_KANNADA ::    *   TT_MAC_ID_MALAYALAM ::    *   TT_MAC_ID_SINHALESE ::    *   TT_MAC_ID_BURMESE ::    *   TT_MAC_ID_KHMER ::    *   TT_MAC_ID_THAI ::    *   TT_MAC_ID_LAOTIAN ::    *   TT_MAC_ID_GEORGIAN ::    *   TT_MAC_ID_ARMENIAN ::    *   TT_MAC_ID_MALDIVIAN ::    *   TT_MAC_ID_SIMPLIFIED_CHINESE ::    *   TT_MAC_ID_TIBETAN ::    *   TT_MAC_ID_MONGOLIAN ::    *   TT_MAC_ID_GEEZ ::    *   TT_MAC_ID_SLAVIC ::    *   TT_MAC_ID_VIETNAMESE ::    *   TT_MAC_ID_SINDHI ::    *   TT_MAC_ID_UNINTERP ::    */
DECL|macro|TT_MAC_ID_ROMAN
define|#
directive|define
name|TT_MAC_ID_ROMAN
value|0
DECL|macro|TT_MAC_ID_JAPANESE
define|#
directive|define
name|TT_MAC_ID_JAPANESE
value|1
DECL|macro|TT_MAC_ID_TRADITIONAL_CHINESE
define|#
directive|define
name|TT_MAC_ID_TRADITIONAL_CHINESE
value|2
DECL|macro|TT_MAC_ID_KOREAN
define|#
directive|define
name|TT_MAC_ID_KOREAN
value|3
DECL|macro|TT_MAC_ID_ARABIC
define|#
directive|define
name|TT_MAC_ID_ARABIC
value|4
DECL|macro|TT_MAC_ID_HEBREW
define|#
directive|define
name|TT_MAC_ID_HEBREW
value|5
DECL|macro|TT_MAC_ID_GREEK
define|#
directive|define
name|TT_MAC_ID_GREEK
value|6
DECL|macro|TT_MAC_ID_RUSSIAN
define|#
directive|define
name|TT_MAC_ID_RUSSIAN
value|7
DECL|macro|TT_MAC_ID_RSYMBOL
define|#
directive|define
name|TT_MAC_ID_RSYMBOL
value|8
DECL|macro|TT_MAC_ID_DEVANAGARI
define|#
directive|define
name|TT_MAC_ID_DEVANAGARI
value|9
DECL|macro|TT_MAC_ID_GURMUKHI
define|#
directive|define
name|TT_MAC_ID_GURMUKHI
value|10
DECL|macro|TT_MAC_ID_GUJARATI
define|#
directive|define
name|TT_MAC_ID_GUJARATI
value|11
DECL|macro|TT_MAC_ID_ORIYA
define|#
directive|define
name|TT_MAC_ID_ORIYA
value|12
DECL|macro|TT_MAC_ID_BENGALI
define|#
directive|define
name|TT_MAC_ID_BENGALI
value|13
DECL|macro|TT_MAC_ID_TAMIL
define|#
directive|define
name|TT_MAC_ID_TAMIL
value|14
DECL|macro|TT_MAC_ID_TELUGU
define|#
directive|define
name|TT_MAC_ID_TELUGU
value|15
DECL|macro|TT_MAC_ID_KANNADA
define|#
directive|define
name|TT_MAC_ID_KANNADA
value|16
DECL|macro|TT_MAC_ID_MALAYALAM
define|#
directive|define
name|TT_MAC_ID_MALAYALAM
value|17
DECL|macro|TT_MAC_ID_SINHALESE
define|#
directive|define
name|TT_MAC_ID_SINHALESE
value|18
DECL|macro|TT_MAC_ID_BURMESE
define|#
directive|define
name|TT_MAC_ID_BURMESE
value|19
DECL|macro|TT_MAC_ID_KHMER
define|#
directive|define
name|TT_MAC_ID_KHMER
value|20
DECL|macro|TT_MAC_ID_THAI
define|#
directive|define
name|TT_MAC_ID_THAI
value|21
DECL|macro|TT_MAC_ID_LAOTIAN
define|#
directive|define
name|TT_MAC_ID_LAOTIAN
value|22
DECL|macro|TT_MAC_ID_GEORGIAN
define|#
directive|define
name|TT_MAC_ID_GEORGIAN
value|23
DECL|macro|TT_MAC_ID_ARMENIAN
define|#
directive|define
name|TT_MAC_ID_ARMENIAN
value|24
DECL|macro|TT_MAC_ID_MALDIVIAN
define|#
directive|define
name|TT_MAC_ID_MALDIVIAN
value|25
DECL|macro|TT_MAC_ID_SIMPLIFIED_CHINESE
define|#
directive|define
name|TT_MAC_ID_SIMPLIFIED_CHINESE
value|25
DECL|macro|TT_MAC_ID_TIBETAN
define|#
directive|define
name|TT_MAC_ID_TIBETAN
value|26
DECL|macro|TT_MAC_ID_MONGOLIAN
define|#
directive|define
name|TT_MAC_ID_MONGOLIAN
value|27
DECL|macro|TT_MAC_ID_GEEZ
define|#
directive|define
name|TT_MAC_ID_GEEZ
value|28
DECL|macro|TT_MAC_ID_SLAVIC
define|#
directive|define
name|TT_MAC_ID_SLAVIC
value|29
DECL|macro|TT_MAC_ID_VIETNAMESE
define|#
directive|define
name|TT_MAC_ID_VIETNAMESE
value|30
DECL|macro|TT_MAC_ID_SINDHI
define|#
directive|define
name|TT_MAC_ID_SINDHI
value|31
DECL|macro|TT_MAC_ID_UNINTERP
define|#
directive|define
name|TT_MAC_ID_UNINTERP
value|32
comment|/***********************************************************************    *    * @enum:    *   TT_ISO_ID_XXX    *    * @description:    *   A list of valid values for the `encoding_id' for    *   @TT_PLATFORM_ISO charmaps and name entries.    *    *   Their use is now deprecated.    *    * @values:    *   TT_ISO_ID_7BIT_ASCII ::    *     ASCII.    *   TT_ISO_ID_10646 ::    *     ISO/10646.    *   TT_ISO_ID_8859_1 ::    *     Also known as Latin-1.    */
DECL|macro|TT_ISO_ID_7BIT_ASCII
define|#
directive|define
name|TT_ISO_ID_7BIT_ASCII
value|0
DECL|macro|TT_ISO_ID_10646
define|#
directive|define
name|TT_ISO_ID_10646
value|1
DECL|macro|TT_ISO_ID_8859_1
define|#
directive|define
name|TT_ISO_ID_8859_1
value|2
comment|/***********************************************************************    *    * @enum:    *   TT_MS_ID_XXX    *    * @description:    *   A list of valid values for the `encoding_id' for    *   @TT_PLATFORM_MICROSOFT charmaps and name entries.    *    * @values:    *   TT_MS_ID_SYMBOL_CS ::    *     Corresponds to Microsoft symbol encoding. See    *     @FT_ENCODING_MS_SYMBOL.    *    *   TT_MS_ID_UNICODE_CS ::    *     Corresponds to a Microsoft WGL4 charmap, matching Unicode.  See    *     @FT_ENCODING_UNICODE.    *    *   TT_MS_ID_SJIS ::    *     Corresponds to SJIS Japanese encoding.  See @FT_ENCODING_SJIS.    *    *   TT_MS_ID_GB2312 ::    *     Corresponds to Simplified Chinese as used in Mainland China.  See    *     @FT_ENCODING_GB2312.    *    *   TT_MS_ID_BIG_5 ::    *     Corresponds to Traditional Chinese as used in Taiwan and Hong Kong.    *     See @FT_ENCODING_BIG5.    *    *   TT_MS_ID_WANSUNG ::    *     Corresponds to Korean Wansung encoding.  See @FT_ENCODING_WANSUNG.    *    *   TT_MS_ID_JOHAB ::    *     Corresponds to Johab encoding.  See @FT_ENCODING_JOHAB.    *    *   TT_MS_ID_UCS_4 ::    *     Corresponds to UCS-4 or UTF-32 charmaps.  This has been added to    *     the OpenType specification version 1.4 (mid-2001.)    */
DECL|macro|TT_MS_ID_SYMBOL_CS
define|#
directive|define
name|TT_MS_ID_SYMBOL_CS
value|0
DECL|macro|TT_MS_ID_UNICODE_CS
define|#
directive|define
name|TT_MS_ID_UNICODE_CS
value|1
DECL|macro|TT_MS_ID_SJIS
define|#
directive|define
name|TT_MS_ID_SJIS
value|2
DECL|macro|TT_MS_ID_GB2312
define|#
directive|define
name|TT_MS_ID_GB2312
value|3
DECL|macro|TT_MS_ID_BIG_5
define|#
directive|define
name|TT_MS_ID_BIG_5
value|4
DECL|macro|TT_MS_ID_WANSUNG
define|#
directive|define
name|TT_MS_ID_WANSUNG
value|5
DECL|macro|TT_MS_ID_JOHAB
define|#
directive|define
name|TT_MS_ID_JOHAB
value|6
DECL|macro|TT_MS_ID_UCS_4
define|#
directive|define
name|TT_MS_ID_UCS_4
value|10
comment|/***********************************************************************    *    * @enum:    *   TT_ADOBE_ID_XXX    *    * @description:    *   A list of valid values for the `encoding_id' for    *   @TT_PLATFORM_ADOBE charmaps.  This is a FreeType-specific extension!    *    * @values:    *   TT_ADOBE_ID_STANDARD ::    *     Adobe standard encoding.    *   TT_ADOBE_ID_EXPERT ::    *     Adobe expert encoding.    *   TT_ADOBE_ID_CUSTOM ::    *     Adobe custom encoding.    *   TT_ADOBE_ID_LATIN_1 ::    *     Adobe Latin~1 encoding.    */
DECL|macro|TT_ADOBE_ID_STANDARD
define|#
directive|define
name|TT_ADOBE_ID_STANDARD
value|0
DECL|macro|TT_ADOBE_ID_EXPERT
define|#
directive|define
name|TT_ADOBE_ID_EXPERT
value|1
DECL|macro|TT_ADOBE_ID_CUSTOM
define|#
directive|define
name|TT_ADOBE_ID_CUSTOM
value|2
DECL|macro|TT_ADOBE_ID_LATIN_1
define|#
directive|define
name|TT_ADOBE_ID_LATIN_1
value|3
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Possible values of the language identifier field in the name records  */
comment|/* of the TTF `name' table if the `platform' identifier code is          */
comment|/* TT_PLATFORM_MACINTOSH.  These values are also used as return values   */
comment|/* for function @FT_Get_CMap_Language_ID.                                */
comment|/*                                                                       */
comment|/* The canonical source for the Apple assigned Language ID's is at       */
comment|/*                                                                       */
comment|/*   https://developer.apple.com/fonts/TTRefMan/RM06/Chap6name.html      */
comment|/*                                                                       */
DECL|macro|TT_MAC_LANGID_ENGLISH
define|#
directive|define
name|TT_MAC_LANGID_ENGLISH
value|0
DECL|macro|TT_MAC_LANGID_FRENCH
define|#
directive|define
name|TT_MAC_LANGID_FRENCH
value|1
DECL|macro|TT_MAC_LANGID_GERMAN
define|#
directive|define
name|TT_MAC_LANGID_GERMAN
value|2
DECL|macro|TT_MAC_LANGID_ITALIAN
define|#
directive|define
name|TT_MAC_LANGID_ITALIAN
value|3
DECL|macro|TT_MAC_LANGID_DUTCH
define|#
directive|define
name|TT_MAC_LANGID_DUTCH
value|4
DECL|macro|TT_MAC_LANGID_SWEDISH
define|#
directive|define
name|TT_MAC_LANGID_SWEDISH
value|5
DECL|macro|TT_MAC_LANGID_SPANISH
define|#
directive|define
name|TT_MAC_LANGID_SPANISH
value|6
DECL|macro|TT_MAC_LANGID_DANISH
define|#
directive|define
name|TT_MAC_LANGID_DANISH
value|7
DECL|macro|TT_MAC_LANGID_PORTUGUESE
define|#
directive|define
name|TT_MAC_LANGID_PORTUGUESE
value|8
DECL|macro|TT_MAC_LANGID_NORWEGIAN
define|#
directive|define
name|TT_MAC_LANGID_NORWEGIAN
value|9
DECL|macro|TT_MAC_LANGID_HEBREW
define|#
directive|define
name|TT_MAC_LANGID_HEBREW
value|10
DECL|macro|TT_MAC_LANGID_JAPANESE
define|#
directive|define
name|TT_MAC_LANGID_JAPANESE
value|11
DECL|macro|TT_MAC_LANGID_ARABIC
define|#
directive|define
name|TT_MAC_LANGID_ARABIC
value|12
DECL|macro|TT_MAC_LANGID_FINNISH
define|#
directive|define
name|TT_MAC_LANGID_FINNISH
value|13
DECL|macro|TT_MAC_LANGID_GREEK
define|#
directive|define
name|TT_MAC_LANGID_GREEK
value|14
DECL|macro|TT_MAC_LANGID_ICELANDIC
define|#
directive|define
name|TT_MAC_LANGID_ICELANDIC
value|15
DECL|macro|TT_MAC_LANGID_MALTESE
define|#
directive|define
name|TT_MAC_LANGID_MALTESE
value|16
DECL|macro|TT_MAC_LANGID_TURKISH
define|#
directive|define
name|TT_MAC_LANGID_TURKISH
value|17
DECL|macro|TT_MAC_LANGID_CROATIAN
define|#
directive|define
name|TT_MAC_LANGID_CROATIAN
value|18
DECL|macro|TT_MAC_LANGID_CHINESE_TRADITIONAL
define|#
directive|define
name|TT_MAC_LANGID_CHINESE_TRADITIONAL
value|19
DECL|macro|TT_MAC_LANGID_URDU
define|#
directive|define
name|TT_MAC_LANGID_URDU
value|20
DECL|macro|TT_MAC_LANGID_HINDI
define|#
directive|define
name|TT_MAC_LANGID_HINDI
value|21
DECL|macro|TT_MAC_LANGID_THAI
define|#
directive|define
name|TT_MAC_LANGID_THAI
value|22
DECL|macro|TT_MAC_LANGID_KOREAN
define|#
directive|define
name|TT_MAC_LANGID_KOREAN
value|23
DECL|macro|TT_MAC_LANGID_LITHUANIAN
define|#
directive|define
name|TT_MAC_LANGID_LITHUANIAN
value|24
DECL|macro|TT_MAC_LANGID_POLISH
define|#
directive|define
name|TT_MAC_LANGID_POLISH
value|25
DECL|macro|TT_MAC_LANGID_HUNGARIAN
define|#
directive|define
name|TT_MAC_LANGID_HUNGARIAN
value|26
DECL|macro|TT_MAC_LANGID_ESTONIAN
define|#
directive|define
name|TT_MAC_LANGID_ESTONIAN
value|27
DECL|macro|TT_MAC_LANGID_LETTISH
define|#
directive|define
name|TT_MAC_LANGID_LETTISH
value|28
DECL|macro|TT_MAC_LANGID_SAAMISK
define|#
directive|define
name|TT_MAC_LANGID_SAAMISK
value|29
DECL|macro|TT_MAC_LANGID_FAEROESE
define|#
directive|define
name|TT_MAC_LANGID_FAEROESE
value|30
DECL|macro|TT_MAC_LANGID_FARSI
define|#
directive|define
name|TT_MAC_LANGID_FARSI
value|31
DECL|macro|TT_MAC_LANGID_RUSSIAN
define|#
directive|define
name|TT_MAC_LANGID_RUSSIAN
value|32
DECL|macro|TT_MAC_LANGID_CHINESE_SIMPLIFIED
define|#
directive|define
name|TT_MAC_LANGID_CHINESE_SIMPLIFIED
value|33
DECL|macro|TT_MAC_LANGID_FLEMISH
define|#
directive|define
name|TT_MAC_LANGID_FLEMISH
value|34
DECL|macro|TT_MAC_LANGID_IRISH
define|#
directive|define
name|TT_MAC_LANGID_IRISH
value|35
DECL|macro|TT_MAC_LANGID_ALBANIAN
define|#
directive|define
name|TT_MAC_LANGID_ALBANIAN
value|36
DECL|macro|TT_MAC_LANGID_ROMANIAN
define|#
directive|define
name|TT_MAC_LANGID_ROMANIAN
value|37
DECL|macro|TT_MAC_LANGID_CZECH
define|#
directive|define
name|TT_MAC_LANGID_CZECH
value|38
DECL|macro|TT_MAC_LANGID_SLOVAK
define|#
directive|define
name|TT_MAC_LANGID_SLOVAK
value|39
DECL|macro|TT_MAC_LANGID_SLOVENIAN
define|#
directive|define
name|TT_MAC_LANGID_SLOVENIAN
value|40
DECL|macro|TT_MAC_LANGID_YIDDISH
define|#
directive|define
name|TT_MAC_LANGID_YIDDISH
value|41
DECL|macro|TT_MAC_LANGID_SERBIAN
define|#
directive|define
name|TT_MAC_LANGID_SERBIAN
value|42
DECL|macro|TT_MAC_LANGID_MACEDONIAN
define|#
directive|define
name|TT_MAC_LANGID_MACEDONIAN
value|43
DECL|macro|TT_MAC_LANGID_BULGARIAN
define|#
directive|define
name|TT_MAC_LANGID_BULGARIAN
value|44
DECL|macro|TT_MAC_LANGID_UKRAINIAN
define|#
directive|define
name|TT_MAC_LANGID_UKRAINIAN
value|45
DECL|macro|TT_MAC_LANGID_BYELORUSSIAN
define|#
directive|define
name|TT_MAC_LANGID_BYELORUSSIAN
value|46
DECL|macro|TT_MAC_LANGID_UZBEK
define|#
directive|define
name|TT_MAC_LANGID_UZBEK
value|47
DECL|macro|TT_MAC_LANGID_KAZAKH
define|#
directive|define
name|TT_MAC_LANGID_KAZAKH
value|48
DECL|macro|TT_MAC_LANGID_AZERBAIJANI
define|#
directive|define
name|TT_MAC_LANGID_AZERBAIJANI
value|49
DECL|macro|TT_MAC_LANGID_AZERBAIJANI_CYRILLIC_SCRIPT
define|#
directive|define
name|TT_MAC_LANGID_AZERBAIJANI_CYRILLIC_SCRIPT
value|49
DECL|macro|TT_MAC_LANGID_AZERBAIJANI_ARABIC_SCRIPT
define|#
directive|define
name|TT_MAC_LANGID_AZERBAIJANI_ARABIC_SCRIPT
value|50
DECL|macro|TT_MAC_LANGID_ARMENIAN
define|#
directive|define
name|TT_MAC_LANGID_ARMENIAN
value|51
DECL|macro|TT_MAC_LANGID_GEORGIAN
define|#
directive|define
name|TT_MAC_LANGID_GEORGIAN
value|52
DECL|macro|TT_MAC_LANGID_MOLDAVIAN
define|#
directive|define
name|TT_MAC_LANGID_MOLDAVIAN
value|53
DECL|macro|TT_MAC_LANGID_KIRGHIZ
define|#
directive|define
name|TT_MAC_LANGID_KIRGHIZ
value|54
DECL|macro|TT_MAC_LANGID_TAJIKI
define|#
directive|define
name|TT_MAC_LANGID_TAJIKI
value|55
DECL|macro|TT_MAC_LANGID_TURKMEN
define|#
directive|define
name|TT_MAC_LANGID_TURKMEN
value|56
DECL|macro|TT_MAC_LANGID_MONGOLIAN
define|#
directive|define
name|TT_MAC_LANGID_MONGOLIAN
value|57
DECL|macro|TT_MAC_LANGID_MONGOLIAN_MONGOLIAN_SCRIPT
define|#
directive|define
name|TT_MAC_LANGID_MONGOLIAN_MONGOLIAN_SCRIPT
value|57
DECL|macro|TT_MAC_LANGID_MONGOLIAN_CYRILLIC_SCRIPT
define|#
directive|define
name|TT_MAC_LANGID_MONGOLIAN_CYRILLIC_SCRIPT
value|58
DECL|macro|TT_MAC_LANGID_PASHTO
define|#
directive|define
name|TT_MAC_LANGID_PASHTO
value|59
DECL|macro|TT_MAC_LANGID_KURDISH
define|#
directive|define
name|TT_MAC_LANGID_KURDISH
value|60
DECL|macro|TT_MAC_LANGID_KASHMIRI
define|#
directive|define
name|TT_MAC_LANGID_KASHMIRI
value|61
DECL|macro|TT_MAC_LANGID_SINDHI
define|#
directive|define
name|TT_MAC_LANGID_SINDHI
value|62
DECL|macro|TT_MAC_LANGID_TIBETAN
define|#
directive|define
name|TT_MAC_LANGID_TIBETAN
value|63
DECL|macro|TT_MAC_LANGID_NEPALI
define|#
directive|define
name|TT_MAC_LANGID_NEPALI
value|64
DECL|macro|TT_MAC_LANGID_SANSKRIT
define|#
directive|define
name|TT_MAC_LANGID_SANSKRIT
value|65
DECL|macro|TT_MAC_LANGID_MARATHI
define|#
directive|define
name|TT_MAC_LANGID_MARATHI
value|66
DECL|macro|TT_MAC_LANGID_BENGALI
define|#
directive|define
name|TT_MAC_LANGID_BENGALI
value|67
DECL|macro|TT_MAC_LANGID_ASSAMESE
define|#
directive|define
name|TT_MAC_LANGID_ASSAMESE
value|68
DECL|macro|TT_MAC_LANGID_GUJARATI
define|#
directive|define
name|TT_MAC_LANGID_GUJARATI
value|69
DECL|macro|TT_MAC_LANGID_PUNJABI
define|#
directive|define
name|TT_MAC_LANGID_PUNJABI
value|70
DECL|macro|TT_MAC_LANGID_ORIYA
define|#
directive|define
name|TT_MAC_LANGID_ORIYA
value|71
DECL|macro|TT_MAC_LANGID_MALAYALAM
define|#
directive|define
name|TT_MAC_LANGID_MALAYALAM
value|72
DECL|macro|TT_MAC_LANGID_KANNADA
define|#
directive|define
name|TT_MAC_LANGID_KANNADA
value|73
DECL|macro|TT_MAC_LANGID_TAMIL
define|#
directive|define
name|TT_MAC_LANGID_TAMIL
value|74
DECL|macro|TT_MAC_LANGID_TELUGU
define|#
directive|define
name|TT_MAC_LANGID_TELUGU
value|75
DECL|macro|TT_MAC_LANGID_SINHALESE
define|#
directive|define
name|TT_MAC_LANGID_SINHALESE
value|76
DECL|macro|TT_MAC_LANGID_BURMESE
define|#
directive|define
name|TT_MAC_LANGID_BURMESE
value|77
DECL|macro|TT_MAC_LANGID_KHMER
define|#
directive|define
name|TT_MAC_LANGID_KHMER
value|78
DECL|macro|TT_MAC_LANGID_LAO
define|#
directive|define
name|TT_MAC_LANGID_LAO
value|79
DECL|macro|TT_MAC_LANGID_VIETNAMESE
define|#
directive|define
name|TT_MAC_LANGID_VIETNAMESE
value|80
DECL|macro|TT_MAC_LANGID_INDONESIAN
define|#
directive|define
name|TT_MAC_LANGID_INDONESIAN
value|81
DECL|macro|TT_MAC_LANGID_TAGALOG
define|#
directive|define
name|TT_MAC_LANGID_TAGALOG
value|82
DECL|macro|TT_MAC_LANGID_MALAY_ROMAN_SCRIPT
define|#
directive|define
name|TT_MAC_LANGID_MALAY_ROMAN_SCRIPT
value|83
DECL|macro|TT_MAC_LANGID_MALAY_ARABIC_SCRIPT
define|#
directive|define
name|TT_MAC_LANGID_MALAY_ARABIC_SCRIPT
value|84
DECL|macro|TT_MAC_LANGID_AMHARIC
define|#
directive|define
name|TT_MAC_LANGID_AMHARIC
value|85
DECL|macro|TT_MAC_LANGID_TIGRINYA
define|#
directive|define
name|TT_MAC_LANGID_TIGRINYA
value|86
DECL|macro|TT_MAC_LANGID_GALLA
define|#
directive|define
name|TT_MAC_LANGID_GALLA
value|87
DECL|macro|TT_MAC_LANGID_SOMALI
define|#
directive|define
name|TT_MAC_LANGID_SOMALI
value|88
DECL|macro|TT_MAC_LANGID_SWAHILI
define|#
directive|define
name|TT_MAC_LANGID_SWAHILI
value|89
DECL|macro|TT_MAC_LANGID_RUANDA
define|#
directive|define
name|TT_MAC_LANGID_RUANDA
value|90
DECL|macro|TT_MAC_LANGID_RUNDI
define|#
directive|define
name|TT_MAC_LANGID_RUNDI
value|91
DECL|macro|TT_MAC_LANGID_CHEWA
define|#
directive|define
name|TT_MAC_LANGID_CHEWA
value|92
DECL|macro|TT_MAC_LANGID_MALAGASY
define|#
directive|define
name|TT_MAC_LANGID_MALAGASY
value|93
DECL|macro|TT_MAC_LANGID_ESPERANTO
define|#
directive|define
name|TT_MAC_LANGID_ESPERANTO
value|94
DECL|macro|TT_MAC_LANGID_WELSH
define|#
directive|define
name|TT_MAC_LANGID_WELSH
value|128
DECL|macro|TT_MAC_LANGID_BASQUE
define|#
directive|define
name|TT_MAC_LANGID_BASQUE
value|129
DECL|macro|TT_MAC_LANGID_CATALAN
define|#
directive|define
name|TT_MAC_LANGID_CATALAN
value|130
DECL|macro|TT_MAC_LANGID_LATIN
define|#
directive|define
name|TT_MAC_LANGID_LATIN
value|131
DECL|macro|TT_MAC_LANGID_QUECHUA
define|#
directive|define
name|TT_MAC_LANGID_QUECHUA
value|132
DECL|macro|TT_MAC_LANGID_GUARANI
define|#
directive|define
name|TT_MAC_LANGID_GUARANI
value|133
DECL|macro|TT_MAC_LANGID_AYMARA
define|#
directive|define
name|TT_MAC_LANGID_AYMARA
value|134
DECL|macro|TT_MAC_LANGID_TATAR
define|#
directive|define
name|TT_MAC_LANGID_TATAR
value|135
DECL|macro|TT_MAC_LANGID_UIGHUR
define|#
directive|define
name|TT_MAC_LANGID_UIGHUR
value|136
DECL|macro|TT_MAC_LANGID_DZONGKHA
define|#
directive|define
name|TT_MAC_LANGID_DZONGKHA
value|137
DECL|macro|TT_MAC_LANGID_JAVANESE
define|#
directive|define
name|TT_MAC_LANGID_JAVANESE
value|138
DECL|macro|TT_MAC_LANGID_SUNDANESE
define|#
directive|define
name|TT_MAC_LANGID_SUNDANESE
value|139
if|#
directive|if
literal|0
comment|/* these seem to be errors that have been dropped */
define|#
directive|define
name|TT_MAC_LANGID_SCOTTISH_GAELIC
value|140
define|#
directive|define
name|TT_MAC_LANGID_IRISH_GAELIC
value|141
endif|#
directive|endif
comment|/* The following codes are new as of 2000-03-10 */
DECL|macro|TT_MAC_LANGID_GALICIAN
define|#
directive|define
name|TT_MAC_LANGID_GALICIAN
value|140
DECL|macro|TT_MAC_LANGID_AFRIKAANS
define|#
directive|define
name|TT_MAC_LANGID_AFRIKAANS
value|141
DECL|macro|TT_MAC_LANGID_BRETON
define|#
directive|define
name|TT_MAC_LANGID_BRETON
value|142
DECL|macro|TT_MAC_LANGID_INUKTITUT
define|#
directive|define
name|TT_MAC_LANGID_INUKTITUT
value|143
DECL|macro|TT_MAC_LANGID_SCOTTISH_GAELIC
define|#
directive|define
name|TT_MAC_LANGID_SCOTTISH_GAELIC
value|144
DECL|macro|TT_MAC_LANGID_MANX_GAELIC
define|#
directive|define
name|TT_MAC_LANGID_MANX_GAELIC
value|145
DECL|macro|TT_MAC_LANGID_IRISH_GAELIC
define|#
directive|define
name|TT_MAC_LANGID_IRISH_GAELIC
value|146
DECL|macro|TT_MAC_LANGID_TONGAN
define|#
directive|define
name|TT_MAC_LANGID_TONGAN
value|147
DECL|macro|TT_MAC_LANGID_GREEK_POLYTONIC
define|#
directive|define
name|TT_MAC_LANGID_GREEK_POLYTONIC
value|148
DECL|macro|TT_MAC_LANGID_GREELANDIC
define|#
directive|define
name|TT_MAC_LANGID_GREELANDIC
value|149
DECL|macro|TT_MAC_LANGID_AZERBAIJANI_ROMAN_SCRIPT
define|#
directive|define
name|TT_MAC_LANGID_AZERBAIJANI_ROMAN_SCRIPT
value|150
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Possible values of the language identifier field in the name records  */
comment|/* of the TTF `name' table if the `platform' identifier code is          */
comment|/* TT_PLATFORM_MICROSOFT.                                                */
comment|/*                                                                       */
comment|/* The canonical source for the MS assigned LCIDs is                     */
comment|/*                                                                       */
comment|/*   http://www.microsoft.com/globaldev/reference/lcid-all.mspx          */
comment|/*                                                                       */
DECL|macro|TT_MS_LANGID_ARABIC_GENERAL
define|#
directive|define
name|TT_MS_LANGID_ARABIC_GENERAL
value|0x0001
DECL|macro|TT_MS_LANGID_ARABIC_SAUDI_ARABIA
define|#
directive|define
name|TT_MS_LANGID_ARABIC_SAUDI_ARABIA
value|0x0401
DECL|macro|TT_MS_LANGID_ARABIC_IRAQ
define|#
directive|define
name|TT_MS_LANGID_ARABIC_IRAQ
value|0x0801
DECL|macro|TT_MS_LANGID_ARABIC_EGYPT
define|#
directive|define
name|TT_MS_LANGID_ARABIC_EGYPT
value|0x0C01
DECL|macro|TT_MS_LANGID_ARABIC_LIBYA
define|#
directive|define
name|TT_MS_LANGID_ARABIC_LIBYA
value|0x1001
DECL|macro|TT_MS_LANGID_ARABIC_ALGERIA
define|#
directive|define
name|TT_MS_LANGID_ARABIC_ALGERIA
value|0x1401
DECL|macro|TT_MS_LANGID_ARABIC_MOROCCO
define|#
directive|define
name|TT_MS_LANGID_ARABIC_MOROCCO
value|0x1801
DECL|macro|TT_MS_LANGID_ARABIC_TUNISIA
define|#
directive|define
name|TT_MS_LANGID_ARABIC_TUNISIA
value|0x1C01
DECL|macro|TT_MS_LANGID_ARABIC_OMAN
define|#
directive|define
name|TT_MS_LANGID_ARABIC_OMAN
value|0x2001
DECL|macro|TT_MS_LANGID_ARABIC_YEMEN
define|#
directive|define
name|TT_MS_LANGID_ARABIC_YEMEN
value|0x2401
DECL|macro|TT_MS_LANGID_ARABIC_SYRIA
define|#
directive|define
name|TT_MS_LANGID_ARABIC_SYRIA
value|0x2801
DECL|macro|TT_MS_LANGID_ARABIC_JORDAN
define|#
directive|define
name|TT_MS_LANGID_ARABIC_JORDAN
value|0x2C01
DECL|macro|TT_MS_LANGID_ARABIC_LEBANON
define|#
directive|define
name|TT_MS_LANGID_ARABIC_LEBANON
value|0x3001
DECL|macro|TT_MS_LANGID_ARABIC_KUWAIT
define|#
directive|define
name|TT_MS_LANGID_ARABIC_KUWAIT
value|0x3401
DECL|macro|TT_MS_LANGID_ARABIC_UAE
define|#
directive|define
name|TT_MS_LANGID_ARABIC_UAE
value|0x3801
DECL|macro|TT_MS_LANGID_ARABIC_BAHRAIN
define|#
directive|define
name|TT_MS_LANGID_ARABIC_BAHRAIN
value|0x3C01
DECL|macro|TT_MS_LANGID_ARABIC_QATAR
define|#
directive|define
name|TT_MS_LANGID_ARABIC_QATAR
value|0x4001
DECL|macro|TT_MS_LANGID_BULGARIAN_BULGARIA
define|#
directive|define
name|TT_MS_LANGID_BULGARIAN_BULGARIA
value|0x0402
DECL|macro|TT_MS_LANGID_CATALAN_SPAIN
define|#
directive|define
name|TT_MS_LANGID_CATALAN_SPAIN
value|0x0403
DECL|macro|TT_MS_LANGID_CHINESE_GENERAL
define|#
directive|define
name|TT_MS_LANGID_CHINESE_GENERAL
value|0x0004
DECL|macro|TT_MS_LANGID_CHINESE_TAIWAN
define|#
directive|define
name|TT_MS_LANGID_CHINESE_TAIWAN
value|0x0404
DECL|macro|TT_MS_LANGID_CHINESE_PRC
define|#
directive|define
name|TT_MS_LANGID_CHINESE_PRC
value|0x0804
DECL|macro|TT_MS_LANGID_CHINESE_HONG_KONG
define|#
directive|define
name|TT_MS_LANGID_CHINESE_HONG_KONG
value|0x0C04
DECL|macro|TT_MS_LANGID_CHINESE_SINGAPORE
define|#
directive|define
name|TT_MS_LANGID_CHINESE_SINGAPORE
value|0x1004
if|#
directive|if
literal|1
comment|/* this looks like the correct value */
DECL|macro|TT_MS_LANGID_CHINESE_MACAU
define|#
directive|define
name|TT_MS_LANGID_CHINESE_MACAU
value|0x1404
else|#
directive|else
comment|/* but beware, Microsoft may change its mind...           the most recent Word reference has the following: */
define|#
directive|define
name|TT_MS_LANGID_CHINESE_MACAU
value|TT_MS_LANGID_CHINESE_HONG_KONG
endif|#
directive|endif
if|#
directive|if
literal|0
comment|/* used only with .NET `cultures'; commented out */
define|#
directive|define
name|TT_MS_LANGID_CHINESE_TRADITIONAL
value|0x7C04
endif|#
directive|endif
DECL|macro|TT_MS_LANGID_CZECH_CZECH_REPUBLIC
define|#
directive|define
name|TT_MS_LANGID_CZECH_CZECH_REPUBLIC
value|0x0405
DECL|macro|TT_MS_LANGID_DANISH_DENMARK
define|#
directive|define
name|TT_MS_LANGID_DANISH_DENMARK
value|0x0406
DECL|macro|TT_MS_LANGID_GERMAN_GERMANY
define|#
directive|define
name|TT_MS_LANGID_GERMAN_GERMANY
value|0x0407
DECL|macro|TT_MS_LANGID_GERMAN_SWITZERLAND
define|#
directive|define
name|TT_MS_LANGID_GERMAN_SWITZERLAND
value|0x0807
DECL|macro|TT_MS_LANGID_GERMAN_AUSTRIA
define|#
directive|define
name|TT_MS_LANGID_GERMAN_AUSTRIA
value|0x0C07
DECL|macro|TT_MS_LANGID_GERMAN_LUXEMBOURG
define|#
directive|define
name|TT_MS_LANGID_GERMAN_LUXEMBOURG
value|0x1007
DECL|macro|TT_MS_LANGID_GERMAN_LIECHTENSTEI
define|#
directive|define
name|TT_MS_LANGID_GERMAN_LIECHTENSTEI
value|0x1407
DECL|macro|TT_MS_LANGID_GREEK_GREECE
define|#
directive|define
name|TT_MS_LANGID_GREEK_GREECE
value|0x0408
comment|/* don't ask what this one means... It is commented out currently. */
if|#
directive|if
literal|0
define|#
directive|define
name|TT_MS_LANGID_GREEK_GREECE2
value|0x2008
endif|#
directive|endif
DECL|macro|TT_MS_LANGID_ENGLISH_GENERAL
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_GENERAL
value|0x0009
DECL|macro|TT_MS_LANGID_ENGLISH_UNITED_STATES
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_UNITED_STATES
value|0x0409
DECL|macro|TT_MS_LANGID_ENGLISH_UNITED_KINGDOM
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_UNITED_KINGDOM
value|0x0809
DECL|macro|TT_MS_LANGID_ENGLISH_AUSTRALIA
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_AUSTRALIA
value|0x0C09
DECL|macro|TT_MS_LANGID_ENGLISH_CANADA
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_CANADA
value|0x1009
DECL|macro|TT_MS_LANGID_ENGLISH_NEW_ZEALAND
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_NEW_ZEALAND
value|0x1409
DECL|macro|TT_MS_LANGID_ENGLISH_IRELAND
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_IRELAND
value|0x1809
DECL|macro|TT_MS_LANGID_ENGLISH_SOUTH_AFRICA
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_SOUTH_AFRICA
value|0x1C09
DECL|macro|TT_MS_LANGID_ENGLISH_JAMAICA
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_JAMAICA
value|0x2009
DECL|macro|TT_MS_LANGID_ENGLISH_CARIBBEAN
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_CARIBBEAN
value|0x2409
DECL|macro|TT_MS_LANGID_ENGLISH_BELIZE
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_BELIZE
value|0x2809
DECL|macro|TT_MS_LANGID_ENGLISH_TRINIDAD
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_TRINIDAD
value|0x2C09
DECL|macro|TT_MS_LANGID_ENGLISH_ZIMBABWE
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_ZIMBABWE
value|0x3009
DECL|macro|TT_MS_LANGID_ENGLISH_PHILIPPINES
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_PHILIPPINES
value|0x3409
DECL|macro|TT_MS_LANGID_ENGLISH_INDONESIA
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_INDONESIA
value|0x3809
DECL|macro|TT_MS_LANGID_ENGLISH_HONG_KONG
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_HONG_KONG
value|0x3C09
DECL|macro|TT_MS_LANGID_ENGLISH_INDIA
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_INDIA
value|0x4009
DECL|macro|TT_MS_LANGID_ENGLISH_MALAYSIA
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_MALAYSIA
value|0x4409
DECL|macro|TT_MS_LANGID_ENGLISH_SINGAPORE
define|#
directive|define
name|TT_MS_LANGID_ENGLISH_SINGAPORE
value|0x4809
DECL|macro|TT_MS_LANGID_SPANISH_SPAIN_TRADITIONAL_SORT
define|#
directive|define
name|TT_MS_LANGID_SPANISH_SPAIN_TRADITIONAL_SORT
value|0x040A
DECL|macro|TT_MS_LANGID_SPANISH_MEXICO
define|#
directive|define
name|TT_MS_LANGID_SPANISH_MEXICO
value|0x080A
DECL|macro|TT_MS_LANGID_SPANISH_SPAIN_INTERNATIONAL_SORT
define|#
directive|define
name|TT_MS_LANGID_SPANISH_SPAIN_INTERNATIONAL_SORT
value|0x0C0A
DECL|macro|TT_MS_LANGID_SPANISH_GUATEMALA
define|#
directive|define
name|TT_MS_LANGID_SPANISH_GUATEMALA
value|0x100A
DECL|macro|TT_MS_LANGID_SPANISH_COSTA_RICA
define|#
directive|define
name|TT_MS_LANGID_SPANISH_COSTA_RICA
value|0x140A
DECL|macro|TT_MS_LANGID_SPANISH_PANAMA
define|#
directive|define
name|TT_MS_LANGID_SPANISH_PANAMA
value|0x180A
DECL|macro|TT_MS_LANGID_SPANISH_DOMINICAN_REPUBLIC
define|#
directive|define
name|TT_MS_LANGID_SPANISH_DOMINICAN_REPUBLIC
value|0x1C0A
DECL|macro|TT_MS_LANGID_SPANISH_VENEZUELA
define|#
directive|define
name|TT_MS_LANGID_SPANISH_VENEZUELA
value|0x200A
DECL|macro|TT_MS_LANGID_SPANISH_COLOMBIA
define|#
directive|define
name|TT_MS_LANGID_SPANISH_COLOMBIA
value|0x240A
DECL|macro|TT_MS_LANGID_SPANISH_PERU
define|#
directive|define
name|TT_MS_LANGID_SPANISH_PERU
value|0x280A
DECL|macro|TT_MS_LANGID_SPANISH_ARGENTINA
define|#
directive|define
name|TT_MS_LANGID_SPANISH_ARGENTINA
value|0x2C0A
DECL|macro|TT_MS_LANGID_SPANISH_ECUADOR
define|#
directive|define
name|TT_MS_LANGID_SPANISH_ECUADOR
value|0x300A
DECL|macro|TT_MS_LANGID_SPANISH_CHILE
define|#
directive|define
name|TT_MS_LANGID_SPANISH_CHILE
value|0x340A
DECL|macro|TT_MS_LANGID_SPANISH_URUGUAY
define|#
directive|define
name|TT_MS_LANGID_SPANISH_URUGUAY
value|0x380A
DECL|macro|TT_MS_LANGID_SPANISH_PARAGUAY
define|#
directive|define
name|TT_MS_LANGID_SPANISH_PARAGUAY
value|0x3C0A
DECL|macro|TT_MS_LANGID_SPANISH_BOLIVIA
define|#
directive|define
name|TT_MS_LANGID_SPANISH_BOLIVIA
value|0x400A
DECL|macro|TT_MS_LANGID_SPANISH_EL_SALVADOR
define|#
directive|define
name|TT_MS_LANGID_SPANISH_EL_SALVADOR
value|0x440A
DECL|macro|TT_MS_LANGID_SPANISH_HONDURAS
define|#
directive|define
name|TT_MS_LANGID_SPANISH_HONDURAS
value|0x480A
DECL|macro|TT_MS_LANGID_SPANISH_NICARAGUA
define|#
directive|define
name|TT_MS_LANGID_SPANISH_NICARAGUA
value|0x4C0A
DECL|macro|TT_MS_LANGID_SPANISH_PUERTO_RICO
define|#
directive|define
name|TT_MS_LANGID_SPANISH_PUERTO_RICO
value|0x500A
DECL|macro|TT_MS_LANGID_SPANISH_UNITED_STATES
define|#
directive|define
name|TT_MS_LANGID_SPANISH_UNITED_STATES
value|0x540A
comment|/* The following ID blatantly violate MS specs by using a */
comment|/* sublanguage> 0x1F.                                    */
DECL|macro|TT_MS_LANGID_SPANISH_LATIN_AMERICA
define|#
directive|define
name|TT_MS_LANGID_SPANISH_LATIN_AMERICA
value|0xE40AU
DECL|macro|TT_MS_LANGID_FINNISH_FINLAND
define|#
directive|define
name|TT_MS_LANGID_FINNISH_FINLAND
value|0x040B
DECL|macro|TT_MS_LANGID_FRENCH_FRANCE
define|#
directive|define
name|TT_MS_LANGID_FRENCH_FRANCE
value|0x040C
DECL|macro|TT_MS_LANGID_FRENCH_BELGIUM
define|#
directive|define
name|TT_MS_LANGID_FRENCH_BELGIUM
value|0x080C
DECL|macro|TT_MS_LANGID_FRENCH_CANADA
define|#
directive|define
name|TT_MS_LANGID_FRENCH_CANADA
value|0x0C0C
DECL|macro|TT_MS_LANGID_FRENCH_SWITZERLAND
define|#
directive|define
name|TT_MS_LANGID_FRENCH_SWITZERLAND
value|0x100C
DECL|macro|TT_MS_LANGID_FRENCH_LUXEMBOURG
define|#
directive|define
name|TT_MS_LANGID_FRENCH_LUXEMBOURG
value|0x140C
DECL|macro|TT_MS_LANGID_FRENCH_MONACO
define|#
directive|define
name|TT_MS_LANGID_FRENCH_MONACO
value|0x180C
DECL|macro|TT_MS_LANGID_FRENCH_WEST_INDIES
define|#
directive|define
name|TT_MS_LANGID_FRENCH_WEST_INDIES
value|0x1C0C
DECL|macro|TT_MS_LANGID_FRENCH_REUNION
define|#
directive|define
name|TT_MS_LANGID_FRENCH_REUNION
value|0x200C
DECL|macro|TT_MS_LANGID_FRENCH_CONGO
define|#
directive|define
name|TT_MS_LANGID_FRENCH_CONGO
value|0x240C
comment|/* which was formerly: */
DECL|macro|TT_MS_LANGID_FRENCH_ZAIRE
define|#
directive|define
name|TT_MS_LANGID_FRENCH_ZAIRE
value|TT_MS_LANGID_FRENCH_CONGO
DECL|macro|TT_MS_LANGID_FRENCH_SENEGAL
define|#
directive|define
name|TT_MS_LANGID_FRENCH_SENEGAL
value|0x280C
DECL|macro|TT_MS_LANGID_FRENCH_CAMEROON
define|#
directive|define
name|TT_MS_LANGID_FRENCH_CAMEROON
value|0x2C0C
DECL|macro|TT_MS_LANGID_FRENCH_COTE_D_IVOIRE
define|#
directive|define
name|TT_MS_LANGID_FRENCH_COTE_D_IVOIRE
value|0x300C
DECL|macro|TT_MS_LANGID_FRENCH_MALI
define|#
directive|define
name|TT_MS_LANGID_FRENCH_MALI
value|0x340C
DECL|macro|TT_MS_LANGID_FRENCH_MOROCCO
define|#
directive|define
name|TT_MS_LANGID_FRENCH_MOROCCO
value|0x380C
DECL|macro|TT_MS_LANGID_FRENCH_HAITI
define|#
directive|define
name|TT_MS_LANGID_FRENCH_HAITI
value|0x3C0C
comment|/* and another violation of the spec (see 0xE40AU) */
DECL|macro|TT_MS_LANGID_FRENCH_NORTH_AFRICA
define|#
directive|define
name|TT_MS_LANGID_FRENCH_NORTH_AFRICA
value|0xE40CU
DECL|macro|TT_MS_LANGID_HEBREW_ISRAEL
define|#
directive|define
name|TT_MS_LANGID_HEBREW_ISRAEL
value|0x040D
DECL|macro|TT_MS_LANGID_HUNGARIAN_HUNGARY
define|#
directive|define
name|TT_MS_LANGID_HUNGARIAN_HUNGARY
value|0x040E
DECL|macro|TT_MS_LANGID_ICELANDIC_ICELAND
define|#
directive|define
name|TT_MS_LANGID_ICELANDIC_ICELAND
value|0x040F
DECL|macro|TT_MS_LANGID_ITALIAN_ITALY
define|#
directive|define
name|TT_MS_LANGID_ITALIAN_ITALY
value|0x0410
DECL|macro|TT_MS_LANGID_ITALIAN_SWITZERLAND
define|#
directive|define
name|TT_MS_LANGID_ITALIAN_SWITZERLAND
value|0x0810
DECL|macro|TT_MS_LANGID_JAPANESE_JAPAN
define|#
directive|define
name|TT_MS_LANGID_JAPANESE_JAPAN
value|0x0411
DECL|macro|TT_MS_LANGID_KOREAN_EXTENDED_WANSUNG_KOREA
define|#
directive|define
name|TT_MS_LANGID_KOREAN_EXTENDED_WANSUNG_KOREA
value|0x0412
DECL|macro|TT_MS_LANGID_KOREAN_JOHAB_KOREA
define|#
directive|define
name|TT_MS_LANGID_KOREAN_JOHAB_KOREA
value|0x0812
DECL|macro|TT_MS_LANGID_DUTCH_NETHERLANDS
define|#
directive|define
name|TT_MS_LANGID_DUTCH_NETHERLANDS
value|0x0413
DECL|macro|TT_MS_LANGID_DUTCH_BELGIUM
define|#
directive|define
name|TT_MS_LANGID_DUTCH_BELGIUM
value|0x0813
DECL|macro|TT_MS_LANGID_NORWEGIAN_NORWAY_BOKMAL
define|#
directive|define
name|TT_MS_LANGID_NORWEGIAN_NORWAY_BOKMAL
value|0x0414
DECL|macro|TT_MS_LANGID_NORWEGIAN_NORWAY_NYNORSK
define|#
directive|define
name|TT_MS_LANGID_NORWEGIAN_NORWAY_NYNORSK
value|0x0814
DECL|macro|TT_MS_LANGID_POLISH_POLAND
define|#
directive|define
name|TT_MS_LANGID_POLISH_POLAND
value|0x0415
DECL|macro|TT_MS_LANGID_PORTUGUESE_BRAZIL
define|#
directive|define
name|TT_MS_LANGID_PORTUGUESE_BRAZIL
value|0x0416
DECL|macro|TT_MS_LANGID_PORTUGUESE_PORTUGAL
define|#
directive|define
name|TT_MS_LANGID_PORTUGUESE_PORTUGAL
value|0x0816
DECL|macro|TT_MS_LANGID_RHAETO_ROMANIC_SWITZERLAND
define|#
directive|define
name|TT_MS_LANGID_RHAETO_ROMANIC_SWITZERLAND
value|0x0417
DECL|macro|TT_MS_LANGID_ROMANIAN_ROMANIA
define|#
directive|define
name|TT_MS_LANGID_ROMANIAN_ROMANIA
value|0x0418
DECL|macro|TT_MS_LANGID_MOLDAVIAN_MOLDAVIA
define|#
directive|define
name|TT_MS_LANGID_MOLDAVIAN_MOLDAVIA
value|0x0818
DECL|macro|TT_MS_LANGID_RUSSIAN_RUSSIA
define|#
directive|define
name|TT_MS_LANGID_RUSSIAN_RUSSIA
value|0x0419
DECL|macro|TT_MS_LANGID_RUSSIAN_MOLDAVIA
define|#
directive|define
name|TT_MS_LANGID_RUSSIAN_MOLDAVIA
value|0x0819
DECL|macro|TT_MS_LANGID_CROATIAN_CROATIA
define|#
directive|define
name|TT_MS_LANGID_CROATIAN_CROATIA
value|0x041A
DECL|macro|TT_MS_LANGID_SERBIAN_SERBIA_LATIN
define|#
directive|define
name|TT_MS_LANGID_SERBIAN_SERBIA_LATIN
value|0x081A
DECL|macro|TT_MS_LANGID_SERBIAN_SERBIA_CYRILLIC
define|#
directive|define
name|TT_MS_LANGID_SERBIAN_SERBIA_CYRILLIC
value|0x0C1A
if|#
directive|if
literal|0
comment|/* this used to be this value, but it looks like we were wrong */
define|#
directive|define
name|TT_MS_LANGID_BOSNIAN_BOSNIA_HERZEGOVINA
value|0x101A
else|#
directive|else
comment|/* current sources say */
DECL|macro|TT_MS_LANGID_CROATIAN_BOSNIA_HERZEGOVINA
define|#
directive|define
name|TT_MS_LANGID_CROATIAN_BOSNIA_HERZEGOVINA
value|0x101A
DECL|macro|TT_MS_LANGID_BOSNIAN_BOSNIA_HERZEGOVINA
define|#
directive|define
name|TT_MS_LANGID_BOSNIAN_BOSNIA_HERZEGOVINA
value|0x141A
comment|/* and XPsp2 Platform SDK added (2004-07-26) */
comment|/* Names are shortened to be significant within 40 chars. */
DECL|macro|TT_MS_LANGID_SERBIAN_BOSNIA_HERZ_LATIN
define|#
directive|define
name|TT_MS_LANGID_SERBIAN_BOSNIA_HERZ_LATIN
value|0x181A
DECL|macro|TT_MS_LANGID_SERBIAN_BOSNIA_HERZ_CYRILLIC
define|#
directive|define
name|TT_MS_LANGID_SERBIAN_BOSNIA_HERZ_CYRILLIC
value|0x181A
endif|#
directive|endif
DECL|macro|TT_MS_LANGID_SLOVAK_SLOVAKIA
define|#
directive|define
name|TT_MS_LANGID_SLOVAK_SLOVAKIA
value|0x041B
DECL|macro|TT_MS_LANGID_ALBANIAN_ALBANIA
define|#
directive|define
name|TT_MS_LANGID_ALBANIAN_ALBANIA
value|0x041C
DECL|macro|TT_MS_LANGID_SWEDISH_SWEDEN
define|#
directive|define
name|TT_MS_LANGID_SWEDISH_SWEDEN
value|0x041D
DECL|macro|TT_MS_LANGID_SWEDISH_FINLAND
define|#
directive|define
name|TT_MS_LANGID_SWEDISH_FINLAND
value|0x081D
DECL|macro|TT_MS_LANGID_THAI_THAILAND
define|#
directive|define
name|TT_MS_LANGID_THAI_THAILAND
value|0x041E
DECL|macro|TT_MS_LANGID_TURKISH_TURKEY
define|#
directive|define
name|TT_MS_LANGID_TURKISH_TURKEY
value|0x041F
DECL|macro|TT_MS_LANGID_URDU_PAKISTAN
define|#
directive|define
name|TT_MS_LANGID_URDU_PAKISTAN
value|0x0420
DECL|macro|TT_MS_LANGID_URDU_INDIA
define|#
directive|define
name|TT_MS_LANGID_URDU_INDIA
value|0x0820
DECL|macro|TT_MS_LANGID_INDONESIAN_INDONESIA
define|#
directive|define
name|TT_MS_LANGID_INDONESIAN_INDONESIA
value|0x0421
DECL|macro|TT_MS_LANGID_UKRAINIAN_UKRAINE
define|#
directive|define
name|TT_MS_LANGID_UKRAINIAN_UKRAINE
value|0x0422
DECL|macro|TT_MS_LANGID_BELARUSIAN_BELARUS
define|#
directive|define
name|TT_MS_LANGID_BELARUSIAN_BELARUS
value|0x0423
DECL|macro|TT_MS_LANGID_SLOVENE_SLOVENIA
define|#
directive|define
name|TT_MS_LANGID_SLOVENE_SLOVENIA
value|0x0424
DECL|macro|TT_MS_LANGID_ESTONIAN_ESTONIA
define|#
directive|define
name|TT_MS_LANGID_ESTONIAN_ESTONIA
value|0x0425
DECL|macro|TT_MS_LANGID_LATVIAN_LATVIA
define|#
directive|define
name|TT_MS_LANGID_LATVIAN_LATVIA
value|0x0426
DECL|macro|TT_MS_LANGID_LITHUANIAN_LITHUANIA
define|#
directive|define
name|TT_MS_LANGID_LITHUANIAN_LITHUANIA
value|0x0427
DECL|macro|TT_MS_LANGID_CLASSIC_LITHUANIAN_LITHUANIA
define|#
directive|define
name|TT_MS_LANGID_CLASSIC_LITHUANIAN_LITHUANIA
value|0x0827
DECL|macro|TT_MS_LANGID_TAJIK_TAJIKISTAN
define|#
directive|define
name|TT_MS_LANGID_TAJIK_TAJIKISTAN
value|0x0428
DECL|macro|TT_MS_LANGID_FARSI_IRAN
define|#
directive|define
name|TT_MS_LANGID_FARSI_IRAN
value|0x0429
DECL|macro|TT_MS_LANGID_VIETNAMESE_VIET_NAM
define|#
directive|define
name|TT_MS_LANGID_VIETNAMESE_VIET_NAM
value|0x042A
DECL|macro|TT_MS_LANGID_ARMENIAN_ARMENIA
define|#
directive|define
name|TT_MS_LANGID_ARMENIAN_ARMENIA
value|0x042B
DECL|macro|TT_MS_LANGID_AZERI_AZERBAIJAN_LATIN
define|#
directive|define
name|TT_MS_LANGID_AZERI_AZERBAIJAN_LATIN
value|0x042C
DECL|macro|TT_MS_LANGID_AZERI_AZERBAIJAN_CYRILLIC
define|#
directive|define
name|TT_MS_LANGID_AZERI_AZERBAIJAN_CYRILLIC
value|0x082C
DECL|macro|TT_MS_LANGID_BASQUE_SPAIN
define|#
directive|define
name|TT_MS_LANGID_BASQUE_SPAIN
value|0x042D
DECL|macro|TT_MS_LANGID_SORBIAN_GERMANY
define|#
directive|define
name|TT_MS_LANGID_SORBIAN_GERMANY
value|0x042E
DECL|macro|TT_MS_LANGID_MACEDONIAN_MACEDONIA
define|#
directive|define
name|TT_MS_LANGID_MACEDONIAN_MACEDONIA
value|0x042F
DECL|macro|TT_MS_LANGID_SUTU_SOUTH_AFRICA
define|#
directive|define
name|TT_MS_LANGID_SUTU_SOUTH_AFRICA
value|0x0430
DECL|macro|TT_MS_LANGID_TSONGA_SOUTH_AFRICA
define|#
directive|define
name|TT_MS_LANGID_TSONGA_SOUTH_AFRICA
value|0x0431
DECL|macro|TT_MS_LANGID_TSWANA_SOUTH_AFRICA
define|#
directive|define
name|TT_MS_LANGID_TSWANA_SOUTH_AFRICA
value|0x0432
DECL|macro|TT_MS_LANGID_VENDA_SOUTH_AFRICA
define|#
directive|define
name|TT_MS_LANGID_VENDA_SOUTH_AFRICA
value|0x0433
DECL|macro|TT_MS_LANGID_XHOSA_SOUTH_AFRICA
define|#
directive|define
name|TT_MS_LANGID_XHOSA_SOUTH_AFRICA
value|0x0434
DECL|macro|TT_MS_LANGID_ZULU_SOUTH_AFRICA
define|#
directive|define
name|TT_MS_LANGID_ZULU_SOUTH_AFRICA
value|0x0435
DECL|macro|TT_MS_LANGID_AFRIKAANS_SOUTH_AFRICA
define|#
directive|define
name|TT_MS_LANGID_AFRIKAANS_SOUTH_AFRICA
value|0x0436
DECL|macro|TT_MS_LANGID_GEORGIAN_GEORGIA
define|#
directive|define
name|TT_MS_LANGID_GEORGIAN_GEORGIA
value|0x0437
DECL|macro|TT_MS_LANGID_FAEROESE_FAEROE_ISLANDS
define|#
directive|define
name|TT_MS_LANGID_FAEROESE_FAEROE_ISLANDS
value|0x0438
DECL|macro|TT_MS_LANGID_HINDI_INDIA
define|#
directive|define
name|TT_MS_LANGID_HINDI_INDIA
value|0x0439
DECL|macro|TT_MS_LANGID_MALTESE_MALTA
define|#
directive|define
name|TT_MS_LANGID_MALTESE_MALTA
value|0x043A
comment|/* Added by XPsp2 Platform SDK (2004-07-26) */
DECL|macro|TT_MS_LANGID_SAMI_NORTHERN_NORWAY
define|#
directive|define
name|TT_MS_LANGID_SAMI_NORTHERN_NORWAY
value|0x043B
DECL|macro|TT_MS_LANGID_SAMI_NORTHERN_SWEDEN
define|#
directive|define
name|TT_MS_LANGID_SAMI_NORTHERN_SWEDEN
value|0x083B
DECL|macro|TT_MS_LANGID_SAMI_NORTHERN_FINLAND
define|#
directive|define
name|TT_MS_LANGID_SAMI_NORTHERN_FINLAND
value|0x0C3B
DECL|macro|TT_MS_LANGID_SAMI_LULE_NORWAY
define|#
directive|define
name|TT_MS_LANGID_SAMI_LULE_NORWAY
value|0x103B
DECL|macro|TT_MS_LANGID_SAMI_LULE_SWEDEN
define|#
directive|define
name|TT_MS_LANGID_SAMI_LULE_SWEDEN
value|0x143B
DECL|macro|TT_MS_LANGID_SAMI_SOUTHERN_NORWAY
define|#
directive|define
name|TT_MS_LANGID_SAMI_SOUTHERN_NORWAY
value|0x183B
DECL|macro|TT_MS_LANGID_SAMI_SOUTHERN_SWEDEN
define|#
directive|define
name|TT_MS_LANGID_SAMI_SOUTHERN_SWEDEN
value|0x1C3B
DECL|macro|TT_MS_LANGID_SAMI_SKOLT_FINLAND
define|#
directive|define
name|TT_MS_LANGID_SAMI_SKOLT_FINLAND
value|0x203B
DECL|macro|TT_MS_LANGID_SAMI_INARI_FINLAND
define|#
directive|define
name|TT_MS_LANGID_SAMI_INARI_FINLAND
value|0x243B
comment|/* ... and we also keep our old identifier... */
DECL|macro|TT_MS_LANGID_SAAMI_LAPONIA
define|#
directive|define
name|TT_MS_LANGID_SAAMI_LAPONIA
value|0x043B
if|#
directive|if
literal|0
comment|/* this seems to be a previous inversion */
define|#
directive|define
name|TT_MS_LANGID_IRISH_GAELIC_IRELAND
value|0x043C
define|#
directive|define
name|TT_MS_LANGID_SCOTTISH_GAELIC_UNITED_KINGDOM
value|0x083C
else|#
directive|else
DECL|macro|TT_MS_LANGID_SCOTTISH_GAELIC_UNITED_KINGDOM
define|#
directive|define
name|TT_MS_LANGID_SCOTTISH_GAELIC_UNITED_KINGDOM
value|0x083C
DECL|macro|TT_MS_LANGID_IRISH_GAELIC_IRELAND
define|#
directive|define
name|TT_MS_LANGID_IRISH_GAELIC_IRELAND
value|0x043C
endif|#
directive|endif
DECL|macro|TT_MS_LANGID_YIDDISH_GERMANY
define|#
directive|define
name|TT_MS_LANGID_YIDDISH_GERMANY
value|0x043D
DECL|macro|TT_MS_LANGID_MALAY_MALAYSIA
define|#
directive|define
name|TT_MS_LANGID_MALAY_MALAYSIA
value|0x043E
DECL|macro|TT_MS_LANGID_MALAY_BRUNEI_DARUSSALAM
define|#
directive|define
name|TT_MS_LANGID_MALAY_BRUNEI_DARUSSALAM
value|0x083E
DECL|macro|TT_MS_LANGID_KAZAK_KAZAKSTAN
define|#
directive|define
name|TT_MS_LANGID_KAZAK_KAZAKSTAN
value|0x043F
DECL|macro|TT_MS_LANGID_KIRGHIZ_KIRGHIZSTAN
define|#
directive|define
name|TT_MS_LANGID_KIRGHIZ_KIRGHIZSTAN
comment|/* Cyrillic*/
value|0x0440
comment|/* alias declared in Windows 2000 */
DECL|macro|TT_MS_LANGID_KIRGHIZ_KIRGHIZ_REPUBLIC
define|#
directive|define
name|TT_MS_LANGID_KIRGHIZ_KIRGHIZ_REPUBLIC
define|\
value|TT_MS_LANGID_KIRGHIZ_KIRGHIZSTAN
DECL|macro|TT_MS_LANGID_SWAHILI_KENYA
define|#
directive|define
name|TT_MS_LANGID_SWAHILI_KENYA
value|0x0441
DECL|macro|TT_MS_LANGID_TURKMEN_TURKMENISTAN
define|#
directive|define
name|TT_MS_LANGID_TURKMEN_TURKMENISTAN
value|0x0442
DECL|macro|TT_MS_LANGID_UZBEK_UZBEKISTAN_LATIN
define|#
directive|define
name|TT_MS_LANGID_UZBEK_UZBEKISTAN_LATIN
value|0x0443
DECL|macro|TT_MS_LANGID_UZBEK_UZBEKISTAN_CYRILLIC
define|#
directive|define
name|TT_MS_LANGID_UZBEK_UZBEKISTAN_CYRILLIC
value|0x0843
DECL|macro|TT_MS_LANGID_TATAR_TATARSTAN
define|#
directive|define
name|TT_MS_LANGID_TATAR_TATARSTAN
value|0x0444
DECL|macro|TT_MS_LANGID_BENGALI_INDIA
define|#
directive|define
name|TT_MS_LANGID_BENGALI_INDIA
value|0x0445
DECL|macro|TT_MS_LANGID_BENGALI_BANGLADESH
define|#
directive|define
name|TT_MS_LANGID_BENGALI_BANGLADESH
value|0x0845
DECL|macro|TT_MS_LANGID_PUNJABI_INDIA
define|#
directive|define
name|TT_MS_LANGID_PUNJABI_INDIA
value|0x0446
DECL|macro|TT_MS_LANGID_PUNJABI_ARABIC_PAKISTAN
define|#
directive|define
name|TT_MS_LANGID_PUNJABI_ARABIC_PAKISTAN
value|0x0846
DECL|macro|TT_MS_LANGID_GUJARATI_INDIA
define|#
directive|define
name|TT_MS_LANGID_GUJARATI_INDIA
value|0x0447
DECL|macro|TT_MS_LANGID_ORIYA_INDIA
define|#
directive|define
name|TT_MS_LANGID_ORIYA_INDIA
value|0x0448
DECL|macro|TT_MS_LANGID_TAMIL_INDIA
define|#
directive|define
name|TT_MS_LANGID_TAMIL_INDIA
value|0x0449
DECL|macro|TT_MS_LANGID_TELUGU_INDIA
define|#
directive|define
name|TT_MS_LANGID_TELUGU_INDIA
value|0x044A
DECL|macro|TT_MS_LANGID_KANNADA_INDIA
define|#
directive|define
name|TT_MS_LANGID_KANNADA_INDIA
value|0x044B
DECL|macro|TT_MS_LANGID_MALAYALAM_INDIA
define|#
directive|define
name|TT_MS_LANGID_MALAYALAM_INDIA
value|0x044C
DECL|macro|TT_MS_LANGID_ASSAMESE_INDIA
define|#
directive|define
name|TT_MS_LANGID_ASSAMESE_INDIA
value|0x044D
DECL|macro|TT_MS_LANGID_MARATHI_INDIA
define|#
directive|define
name|TT_MS_LANGID_MARATHI_INDIA
value|0x044E
DECL|macro|TT_MS_LANGID_SANSKRIT_INDIA
define|#
directive|define
name|TT_MS_LANGID_SANSKRIT_INDIA
value|0x044F
DECL|macro|TT_MS_LANGID_MONGOLIAN_MONGOLIA
define|#
directive|define
name|TT_MS_LANGID_MONGOLIAN_MONGOLIA
comment|/* Cyrillic */
value|0x0450
DECL|macro|TT_MS_LANGID_MONGOLIAN_MONGOLIA_MONGOLIAN
define|#
directive|define
name|TT_MS_LANGID_MONGOLIAN_MONGOLIA_MONGOLIAN
value|0x0850
DECL|macro|TT_MS_LANGID_TIBETAN_CHINA
define|#
directive|define
name|TT_MS_LANGID_TIBETAN_CHINA
value|0x0451
comment|/* Don't use the next constant!  It has            */
comment|/*   (1) the wrong spelling (Dzonghka)             */
comment|/*   (2) Microsoft doesn't officially define it -- */
comment|/*       at least it is not in the List of Local   */
comment|/*       ID Values.                                */
comment|/*   (3) Dzongkha is not the same language as      */
comment|/*       Tibetan, so merging it is wrong anyway.   */
comment|/*                                                 */
comment|/* TT_MS_LANGID_TIBETAN_BHUTAN is correct, BTW.    */
DECL|macro|TT_MS_LANGID_DZONGHKA_BHUTAN
define|#
directive|define
name|TT_MS_LANGID_DZONGHKA_BHUTAN
value|0x0851
if|#
directive|if
literal|0
comment|/* the following used to be defined */
define|#
directive|define
name|TT_MS_LANGID_TIBETAN_BHUTAN
value|0x0451
comment|/* ... but it was changed; */
else|#
directive|else
comment|/* So we will continue to #define it, but with the correct value */
DECL|macro|TT_MS_LANGID_TIBETAN_BHUTAN
define|#
directive|define
name|TT_MS_LANGID_TIBETAN_BHUTAN
value|TT_MS_LANGID_DZONGHKA_BHUTAN
endif|#
directive|endif
DECL|macro|TT_MS_LANGID_WELSH_WALES
define|#
directive|define
name|TT_MS_LANGID_WELSH_WALES
value|0x0452
DECL|macro|TT_MS_LANGID_KHMER_CAMBODIA
define|#
directive|define
name|TT_MS_LANGID_KHMER_CAMBODIA
value|0x0453
DECL|macro|TT_MS_LANGID_LAO_LAOS
define|#
directive|define
name|TT_MS_LANGID_LAO_LAOS
value|0x0454
DECL|macro|TT_MS_LANGID_BURMESE_MYANMAR
define|#
directive|define
name|TT_MS_LANGID_BURMESE_MYANMAR
value|0x0455
DECL|macro|TT_MS_LANGID_GALICIAN_SPAIN
define|#
directive|define
name|TT_MS_LANGID_GALICIAN_SPAIN
value|0x0456
DECL|macro|TT_MS_LANGID_KONKANI_INDIA
define|#
directive|define
name|TT_MS_LANGID_KONKANI_INDIA
value|0x0457
DECL|macro|TT_MS_LANGID_MANIPURI_INDIA
define|#
directive|define
name|TT_MS_LANGID_MANIPURI_INDIA
comment|/* Bengali */
value|0x0458
DECL|macro|TT_MS_LANGID_SINDHI_INDIA
define|#
directive|define
name|TT_MS_LANGID_SINDHI_INDIA
comment|/* Arabic */
value|0x0459
DECL|macro|TT_MS_LANGID_SINDHI_PAKISTAN
define|#
directive|define
name|TT_MS_LANGID_SINDHI_PAKISTAN
value|0x0859
comment|/* Missing a LCID for Sindhi in Devanagari script */
DECL|macro|TT_MS_LANGID_SYRIAC_SYRIA
define|#
directive|define
name|TT_MS_LANGID_SYRIAC_SYRIA
value|0x045A
DECL|macro|TT_MS_LANGID_SINHALESE_SRI_LANKA
define|#
directive|define
name|TT_MS_LANGID_SINHALESE_SRI_LANKA
value|0x045B
DECL|macro|TT_MS_LANGID_CHEROKEE_UNITED_STATES
define|#
directive|define
name|TT_MS_LANGID_CHEROKEE_UNITED_STATES
value|0x045C
DECL|macro|TT_MS_LANGID_INUKTITUT_CANADA
define|#
directive|define
name|TT_MS_LANGID_INUKTITUT_CANADA
value|0x045D
DECL|macro|TT_MS_LANGID_AMHARIC_ETHIOPIA
define|#
directive|define
name|TT_MS_LANGID_AMHARIC_ETHIOPIA
value|0x045E
DECL|macro|TT_MS_LANGID_TAMAZIGHT_MOROCCO
define|#
directive|define
name|TT_MS_LANGID_TAMAZIGHT_MOROCCO
comment|/* Arabic */
value|0x045F
DECL|macro|TT_MS_LANGID_TAMAZIGHT_MOROCCO_LATIN
define|#
directive|define
name|TT_MS_LANGID_TAMAZIGHT_MOROCCO_LATIN
value|0x085F
comment|/* Missing a LCID for Tifinagh script */
DECL|macro|TT_MS_LANGID_KASHMIRI_PAKISTAN
define|#
directive|define
name|TT_MS_LANGID_KASHMIRI_PAKISTAN
comment|/* Arabic */
value|0x0460
comment|/* Spelled this way by XPsp2 Platform SDK (2004-07-26) */
comment|/* script is yet unclear... might be Arabic, Nagari or Sharada */
DECL|macro|TT_MS_LANGID_KASHMIRI_SASIA
define|#
directive|define
name|TT_MS_LANGID_KASHMIRI_SASIA
value|0x0860
comment|/* ... and aliased (by MS) for compatibility reasons. */
DECL|macro|TT_MS_LANGID_KASHMIRI_INDIA
define|#
directive|define
name|TT_MS_LANGID_KASHMIRI_INDIA
value|TT_MS_LANGID_KASHMIRI_SASIA
DECL|macro|TT_MS_LANGID_NEPALI_NEPAL
define|#
directive|define
name|TT_MS_LANGID_NEPALI_NEPAL
value|0x0461
DECL|macro|TT_MS_LANGID_NEPALI_INDIA
define|#
directive|define
name|TT_MS_LANGID_NEPALI_INDIA
value|0x0861
DECL|macro|TT_MS_LANGID_FRISIAN_NETHERLANDS
define|#
directive|define
name|TT_MS_LANGID_FRISIAN_NETHERLANDS
value|0x0462
DECL|macro|TT_MS_LANGID_PASHTO_AFGHANISTAN
define|#
directive|define
name|TT_MS_LANGID_PASHTO_AFGHANISTAN
value|0x0463
DECL|macro|TT_MS_LANGID_FILIPINO_PHILIPPINES
define|#
directive|define
name|TT_MS_LANGID_FILIPINO_PHILIPPINES
value|0x0464
DECL|macro|TT_MS_LANGID_DHIVEHI_MALDIVES
define|#
directive|define
name|TT_MS_LANGID_DHIVEHI_MALDIVES
value|0x0465
comment|/* alias declared in Windows 2000 */
DECL|macro|TT_MS_LANGID_DIVEHI_MALDIVES
define|#
directive|define
name|TT_MS_LANGID_DIVEHI_MALDIVES
value|TT_MS_LANGID_DHIVEHI_MALDIVES
DECL|macro|TT_MS_LANGID_EDO_NIGERIA
define|#
directive|define
name|TT_MS_LANGID_EDO_NIGERIA
value|0x0466
DECL|macro|TT_MS_LANGID_FULFULDE_NIGERIA
define|#
directive|define
name|TT_MS_LANGID_FULFULDE_NIGERIA
value|0x0467
DECL|macro|TT_MS_LANGID_HAUSA_NIGERIA
define|#
directive|define
name|TT_MS_LANGID_HAUSA_NIGERIA
value|0x0468
DECL|macro|TT_MS_LANGID_IBIBIO_NIGERIA
define|#
directive|define
name|TT_MS_LANGID_IBIBIO_NIGERIA
value|0x0469
DECL|macro|TT_MS_LANGID_YORUBA_NIGERIA
define|#
directive|define
name|TT_MS_LANGID_YORUBA_NIGERIA
value|0x046A
DECL|macro|TT_MS_LANGID_QUECHUA_BOLIVIA
define|#
directive|define
name|TT_MS_LANGID_QUECHUA_BOLIVIA
value|0x046B
DECL|macro|TT_MS_LANGID_QUECHUA_ECUADOR
define|#
directive|define
name|TT_MS_LANGID_QUECHUA_ECUADOR
value|0x086B
DECL|macro|TT_MS_LANGID_QUECHUA_PERU
define|#
directive|define
name|TT_MS_LANGID_QUECHUA_PERU
value|0x0C6B
DECL|macro|TT_MS_LANGID_SEPEDI_SOUTH_AFRICA
define|#
directive|define
name|TT_MS_LANGID_SEPEDI_SOUTH_AFRICA
value|0x046C
comment|/* Also spelled by XPsp2 Platform SDK (2004-07-26) */
DECL|macro|TT_MS_LANGID_SOTHO_SOUTHERN_SOUTH_AFRICA
define|#
directive|define
name|TT_MS_LANGID_SOTHO_SOUTHERN_SOUTH_AFRICA
define|\
value|TT_MS_LANGID_SEPEDI_SOUTH_AFRICA
comment|/* language codes 0x046D, 0x046E and 0x046F are (still) unknown. */
DECL|macro|TT_MS_LANGID_IGBO_NIGERIA
define|#
directive|define
name|TT_MS_LANGID_IGBO_NIGERIA
value|0x0470
DECL|macro|TT_MS_LANGID_KANURI_NIGERIA
define|#
directive|define
name|TT_MS_LANGID_KANURI_NIGERIA
value|0x0471
DECL|macro|TT_MS_LANGID_OROMO_ETHIOPIA
define|#
directive|define
name|TT_MS_LANGID_OROMO_ETHIOPIA
value|0x0472
DECL|macro|TT_MS_LANGID_TIGRIGNA_ETHIOPIA
define|#
directive|define
name|TT_MS_LANGID_TIGRIGNA_ETHIOPIA
value|0x0473
DECL|macro|TT_MS_LANGID_TIGRIGNA_ERYTHREA
define|#
directive|define
name|TT_MS_LANGID_TIGRIGNA_ERYTHREA
value|0x0873
comment|/* also spelled in the `Passport SDK' list as: */
DECL|macro|TT_MS_LANGID_TIGRIGNA_ERYTREA
define|#
directive|define
name|TT_MS_LANGID_TIGRIGNA_ERYTREA
value|TT_MS_LANGID_TIGRIGNA_ERYTHREA
DECL|macro|TT_MS_LANGID_GUARANI_PARAGUAY
define|#
directive|define
name|TT_MS_LANGID_GUARANI_PARAGUAY
value|0x0474
DECL|macro|TT_MS_LANGID_HAWAIIAN_UNITED_STATES
define|#
directive|define
name|TT_MS_LANGID_HAWAIIAN_UNITED_STATES
value|0x0475
DECL|macro|TT_MS_LANGID_LATIN
define|#
directive|define
name|TT_MS_LANGID_LATIN
value|0x0476
DECL|macro|TT_MS_LANGID_SOMALI_SOMALIA
define|#
directive|define
name|TT_MS_LANGID_SOMALI_SOMALIA
value|0x0477
comment|/* Note: Yi does not have a (proper) ISO 639-2 code, since it is mostly */
comment|/*       not written (but OTOH the peculiar writing system is worth     */
comment|/*       studying).                                                     */
DECL|macro|TT_MS_LANGID_YI_CHINA
define|#
directive|define
name|TT_MS_LANGID_YI_CHINA
value|0x0478
DECL|macro|TT_MS_LANGID_PAPIAMENTU_NETHERLANDS_ANTILLES
define|#
directive|define
name|TT_MS_LANGID_PAPIAMENTU_NETHERLANDS_ANTILLES
value|0x0479
comment|/* language codes from 0x047A to 0x047F are (still) unknown. */
DECL|macro|TT_MS_LANGID_UIGHUR_CHINA
define|#
directive|define
name|TT_MS_LANGID_UIGHUR_CHINA
value|0x0480
DECL|macro|TT_MS_LANGID_MAORI_NEW_ZEALAND
define|#
directive|define
name|TT_MS_LANGID_MAORI_NEW_ZEALAND
value|0x0481
if|#
directive|if
literal|0
comment|/* not deemed useful for fonts */
define|#
directive|define
name|TT_MS_LANGID_HUMAN_INTERFACE_DEVICE
value|0x04FF
endif|#
directive|endif
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Possible values of the `name' identifier field in the name records of */
comment|/* the TTF `name' table.  These values are platform independent.         */
comment|/*                                                                       */
DECL|macro|TT_NAME_ID_COPYRIGHT
define|#
directive|define
name|TT_NAME_ID_COPYRIGHT
value|0
DECL|macro|TT_NAME_ID_FONT_FAMILY
define|#
directive|define
name|TT_NAME_ID_FONT_FAMILY
value|1
DECL|macro|TT_NAME_ID_FONT_SUBFAMILY
define|#
directive|define
name|TT_NAME_ID_FONT_SUBFAMILY
value|2
DECL|macro|TT_NAME_ID_UNIQUE_ID
define|#
directive|define
name|TT_NAME_ID_UNIQUE_ID
value|3
DECL|macro|TT_NAME_ID_FULL_NAME
define|#
directive|define
name|TT_NAME_ID_FULL_NAME
value|4
DECL|macro|TT_NAME_ID_VERSION_STRING
define|#
directive|define
name|TT_NAME_ID_VERSION_STRING
value|5
DECL|macro|TT_NAME_ID_PS_NAME
define|#
directive|define
name|TT_NAME_ID_PS_NAME
value|6
DECL|macro|TT_NAME_ID_TRADEMARK
define|#
directive|define
name|TT_NAME_ID_TRADEMARK
value|7
comment|/* the following values are from the OpenType spec */
DECL|macro|TT_NAME_ID_MANUFACTURER
define|#
directive|define
name|TT_NAME_ID_MANUFACTURER
value|8
DECL|macro|TT_NAME_ID_DESIGNER
define|#
directive|define
name|TT_NAME_ID_DESIGNER
value|9
DECL|macro|TT_NAME_ID_DESCRIPTION
define|#
directive|define
name|TT_NAME_ID_DESCRIPTION
value|10
DECL|macro|TT_NAME_ID_VENDOR_URL
define|#
directive|define
name|TT_NAME_ID_VENDOR_URL
value|11
DECL|macro|TT_NAME_ID_DESIGNER_URL
define|#
directive|define
name|TT_NAME_ID_DESIGNER_URL
value|12
DECL|macro|TT_NAME_ID_LICENSE
define|#
directive|define
name|TT_NAME_ID_LICENSE
value|13
DECL|macro|TT_NAME_ID_LICENSE_URL
define|#
directive|define
name|TT_NAME_ID_LICENSE_URL
value|14
comment|/* number 15 is reserved */
DECL|macro|TT_NAME_ID_PREFERRED_FAMILY
define|#
directive|define
name|TT_NAME_ID_PREFERRED_FAMILY
value|16
DECL|macro|TT_NAME_ID_PREFERRED_SUBFAMILY
define|#
directive|define
name|TT_NAME_ID_PREFERRED_SUBFAMILY
value|17
DECL|macro|TT_NAME_ID_MAC_FULL_NAME
define|#
directive|define
name|TT_NAME_ID_MAC_FULL_NAME
value|18
comment|/* The following code is new as of 2000-01-21 */
DECL|macro|TT_NAME_ID_SAMPLE_TEXT
define|#
directive|define
name|TT_NAME_ID_SAMPLE_TEXT
value|19
comment|/* This is new in OpenType 1.3 */
DECL|macro|TT_NAME_ID_CID_FINDFONT_NAME
define|#
directive|define
name|TT_NAME_ID_CID_FINDFONT_NAME
value|20
comment|/* This is new in OpenType 1.5 */
DECL|macro|TT_NAME_ID_WWS_FAMILY
define|#
directive|define
name|TT_NAME_ID_WWS_FAMILY
value|21
DECL|macro|TT_NAME_ID_WWS_SUBFAMILY
define|#
directive|define
name|TT_NAME_ID_WWS_SUBFAMILY
value|22
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Bit mask values for the Unicode Ranges from the TTF `OS2 ' table.     */
comment|/*                                                                       */
comment|/* Updated 08-Nov-2008.                                                  */
comment|/*                                                                       */
comment|/* Bit  0   Basic Latin */
DECL|macro|TT_UCR_BASIC_LATIN
define|#
directive|define
name|TT_UCR_BASIC_LATIN
value|(1L<<  0)
comment|/* U+0020-U+007E */
comment|/* Bit  1   C1 Controls and Latin-1 Supplement */
DECL|macro|TT_UCR_LATIN1_SUPPLEMENT
define|#
directive|define
name|TT_UCR_LATIN1_SUPPLEMENT
value|(1L<<  1)
comment|/* U+0080-U+00FF */
comment|/* Bit  2   Latin Extended-A */
DECL|macro|TT_UCR_LATIN_EXTENDED_A
define|#
directive|define
name|TT_UCR_LATIN_EXTENDED_A
value|(1L<<  2)
comment|/* U+0100-U+017F */
comment|/* Bit  3   Latin Extended-B */
DECL|macro|TT_UCR_LATIN_EXTENDED_B
define|#
directive|define
name|TT_UCR_LATIN_EXTENDED_B
value|(1L<<  3)
comment|/* U+0180-U+024F */
comment|/* Bit  4   IPA Extensions                 */
comment|/*          Phonetic Extensions            */
comment|/*          Phonetic Extensions Supplement */
DECL|macro|TT_UCR_IPA_EXTENSIONS
define|#
directive|define
name|TT_UCR_IPA_EXTENSIONS
value|(1L<<  4)
comment|/* U+0250-U+02AF */
comment|/* U+1D00-U+1D7F */
comment|/* U+1D80-U+1DBF */
comment|/* Bit  5   Spacing Modifier Letters */
comment|/*          Modifier Tone Letters    */
DECL|macro|TT_UCR_SPACING_MODIFIER
define|#
directive|define
name|TT_UCR_SPACING_MODIFIER
value|(1L<<  5)
comment|/* U+02B0-U+02FF */
comment|/* U+A700-U+A71F */
comment|/* Bit  6   Combining Diacritical Marks            */
comment|/*          Combining Diacritical Marks Supplement */
DECL|macro|TT_UCR_COMBINING_DIACRITICS
define|#
directive|define
name|TT_UCR_COMBINING_DIACRITICS
value|(1L<<  6)
comment|/* U+0300-U+036F */
comment|/* U+1DC0-U+1DFF */
comment|/* Bit  7   Greek and Coptic */
DECL|macro|TT_UCR_GREEK
define|#
directive|define
name|TT_UCR_GREEK
value|(1L<<  7)
comment|/* U+0370-U+03FF */
comment|/* Bit  8   Coptic */
DECL|macro|TT_UCR_COPTIC
define|#
directive|define
name|TT_UCR_COPTIC
value|(1L<<  8)
comment|/* U+2C80-U+2CFF */
comment|/* Bit  9   Cyrillic            */
comment|/*          Cyrillic Supplement */
comment|/*          Cyrillic Extended-A */
comment|/*          Cyrillic Extended-B */
DECL|macro|TT_UCR_CYRILLIC
define|#
directive|define
name|TT_UCR_CYRILLIC
value|(1L<<  9)
comment|/* U+0400-U+04FF */
comment|/* U+0500-U+052F */
comment|/* U+2DE0-U+2DFF */
comment|/* U+A640-U+A69F */
comment|/* Bit 10   Armenian */
DECL|macro|TT_UCR_ARMENIAN
define|#
directive|define
name|TT_UCR_ARMENIAN
value|(1L<< 10)
comment|/* U+0530-U+058F */
comment|/* Bit 11   Hebrew */
DECL|macro|TT_UCR_HEBREW
define|#
directive|define
name|TT_UCR_HEBREW
value|(1L<< 11)
comment|/* U+0590-U+05FF */
comment|/* Bit 12   Vai */
DECL|macro|TT_UCR_VAI
define|#
directive|define
name|TT_UCR_VAI
value|(1L<< 12)
comment|/* U+A500-U+A63F */
comment|/* Bit 13   Arabic            */
comment|/*          Arabic Supplement */
DECL|macro|TT_UCR_ARABIC
define|#
directive|define
name|TT_UCR_ARABIC
value|(1L<< 13)
comment|/* U+0600-U+06FF */
comment|/* U+0750-U+077F */
comment|/* Bit 14   NKo */
DECL|macro|TT_UCR_NKO
define|#
directive|define
name|TT_UCR_NKO
value|(1L<< 14)
comment|/* U+07C0-U+07FF */
comment|/* Bit 15   Devanagari */
DECL|macro|TT_UCR_DEVANAGARI
define|#
directive|define
name|TT_UCR_DEVANAGARI
value|(1L<< 15)
comment|/* U+0900-U+097F */
comment|/* Bit 16   Bengali */
DECL|macro|TT_UCR_BENGALI
define|#
directive|define
name|TT_UCR_BENGALI
value|(1L<< 16)
comment|/* U+0980-U+09FF */
comment|/* Bit 17   Gurmukhi */
DECL|macro|TT_UCR_GURMUKHI
define|#
directive|define
name|TT_UCR_GURMUKHI
value|(1L<< 17)
comment|/* U+0A00-U+0A7F */
comment|/* Bit 18   Gujarati */
DECL|macro|TT_UCR_GUJARATI
define|#
directive|define
name|TT_UCR_GUJARATI
value|(1L<< 18)
comment|/* U+0A80-U+0AFF */
comment|/* Bit 19   Oriya */
DECL|macro|TT_UCR_ORIYA
define|#
directive|define
name|TT_UCR_ORIYA
value|(1L<< 19)
comment|/* U+0B00-U+0B7F */
comment|/* Bit 20   Tamil */
DECL|macro|TT_UCR_TAMIL
define|#
directive|define
name|TT_UCR_TAMIL
value|(1L<< 20)
comment|/* U+0B80-U+0BFF */
comment|/* Bit 21   Telugu */
DECL|macro|TT_UCR_TELUGU
define|#
directive|define
name|TT_UCR_TELUGU
value|(1L<< 21)
comment|/* U+0C00-U+0C7F */
comment|/* Bit 22   Kannada */
DECL|macro|TT_UCR_KANNADA
define|#
directive|define
name|TT_UCR_KANNADA
value|(1L<< 22)
comment|/* U+0C80-U+0CFF */
comment|/* Bit 23   Malayalam */
DECL|macro|TT_UCR_MALAYALAM
define|#
directive|define
name|TT_UCR_MALAYALAM
value|(1L<< 23)
comment|/* U+0D00-U+0D7F */
comment|/* Bit 24   Thai */
DECL|macro|TT_UCR_THAI
define|#
directive|define
name|TT_UCR_THAI
value|(1L<< 24)
comment|/* U+0E00-U+0E7F */
comment|/* Bit 25   Lao */
DECL|macro|TT_UCR_LAO
define|#
directive|define
name|TT_UCR_LAO
value|(1L<< 25)
comment|/* U+0E80-U+0EFF */
comment|/* Bit 26   Georgian            */
comment|/*          Georgian Supplement */
DECL|macro|TT_UCR_GEORGIAN
define|#
directive|define
name|TT_UCR_GEORGIAN
value|(1L<< 26)
comment|/* U+10A0-U+10FF */
comment|/* U+2D00-U+2D2F */
comment|/* Bit 27   Balinese */
DECL|macro|TT_UCR_BALINESE
define|#
directive|define
name|TT_UCR_BALINESE
value|(1L<< 27)
comment|/* U+1B00-U+1B7F */
comment|/* Bit 28   Hangul Jamo */
DECL|macro|TT_UCR_HANGUL_JAMO
define|#
directive|define
name|TT_UCR_HANGUL_JAMO
value|(1L<< 28)
comment|/* U+1100-U+11FF */
comment|/* Bit 29   Latin Extended Additional */
comment|/*          Latin Extended-C          */
comment|/*          Latin Extended-D          */
DECL|macro|TT_UCR_LATIN_EXTENDED_ADDITIONAL
define|#
directive|define
name|TT_UCR_LATIN_EXTENDED_ADDITIONAL
value|(1L<< 29)
comment|/* U+1E00-U+1EFF */
comment|/* U+2C60-U+2C7F */
comment|/* U+A720-U+A7FF */
comment|/* Bit 30   Greek Extended */
DECL|macro|TT_UCR_GREEK_EXTENDED
define|#
directive|define
name|TT_UCR_GREEK_EXTENDED
value|(1L<< 30)
comment|/* U+1F00-U+1FFF */
comment|/* Bit 31   General Punctuation      */
comment|/*          Supplemental Punctuation */
DECL|macro|TT_UCR_GENERAL_PUNCTUATION
define|#
directive|define
name|TT_UCR_GENERAL_PUNCTUATION
value|(1L<< 31)
comment|/* U+2000-U+206F */
comment|/* U+2E00-U+2E7F */
comment|/* Bit 32   Superscripts And Subscripts */
DECL|macro|TT_UCR_SUPERSCRIPTS_SUBSCRIPTS
define|#
directive|define
name|TT_UCR_SUPERSCRIPTS_SUBSCRIPTS
value|(1L<<  0)
comment|/* U+2070-U+209F */
comment|/* Bit 33   Currency Symbols */
DECL|macro|TT_UCR_CURRENCY_SYMBOLS
define|#
directive|define
name|TT_UCR_CURRENCY_SYMBOLS
value|(1L<<  1)
comment|/* U+20A0-U+20CF */
comment|/* Bit 34   Combining Diacritical Marks For Symbols */
DECL|macro|TT_UCR_COMBINING_DIACRITICS_SYMB
define|#
directive|define
name|TT_UCR_COMBINING_DIACRITICS_SYMB
value|(1L<<  2)
comment|/* U+20D0-U+20FF */
comment|/* Bit 35   Letterlike Symbols */
DECL|macro|TT_UCR_LETTERLIKE_SYMBOLS
define|#
directive|define
name|TT_UCR_LETTERLIKE_SYMBOLS
value|(1L<<  3)
comment|/* U+2100-U+214F */
comment|/* Bit 36   Number Forms */
DECL|macro|TT_UCR_NUMBER_FORMS
define|#
directive|define
name|TT_UCR_NUMBER_FORMS
value|(1L<<  4)
comment|/* U+2150-U+218F */
comment|/* Bit 37   Arrows                           */
comment|/*          Supplemental Arrows-A            */
comment|/*          Supplemental Arrows-B            */
comment|/*          Miscellaneous Symbols and Arrows */
DECL|macro|TT_UCR_ARROWS
define|#
directive|define
name|TT_UCR_ARROWS
value|(1L<<  5)
comment|/* U+2190-U+21FF */
comment|/* U+27F0-U+27FF */
comment|/* U+2900-U+297F */
comment|/* U+2B00-U+2BFF */
comment|/* Bit 38   Mathematical Operators               */
comment|/*          Supplemental Mathematical Operators  */
comment|/*          Miscellaneous Mathematical Symbols-A */
comment|/*          Miscellaneous Mathematical Symbols-B */
DECL|macro|TT_UCR_MATHEMATICAL_OPERATORS
define|#
directive|define
name|TT_UCR_MATHEMATICAL_OPERATORS
value|(1L<<  6)
comment|/* U+2200-U+22FF */
comment|/* U+2A00-U+2AFF */
comment|/* U+27C0-U+27EF */
comment|/* U+2980-U+29FF */
comment|/* Bit 39 Miscellaneous Technical */
DECL|macro|TT_UCR_MISCELLANEOUS_TECHNICAL
define|#
directive|define
name|TT_UCR_MISCELLANEOUS_TECHNICAL
value|(1L<<  7)
comment|/* U+2300-U+23FF */
comment|/* Bit 40   Control Pictures */
DECL|macro|TT_UCR_CONTROL_PICTURES
define|#
directive|define
name|TT_UCR_CONTROL_PICTURES
value|(1L<<  8)
comment|/* U+2400-U+243F */
comment|/* Bit 41   Optical Character Recognition */
DECL|macro|TT_UCR_OCR
define|#
directive|define
name|TT_UCR_OCR
value|(1L<<  9)
comment|/* U+2440-U+245F */
comment|/* Bit 42   Enclosed Alphanumerics */
DECL|macro|TT_UCR_ENCLOSED_ALPHANUMERICS
define|#
directive|define
name|TT_UCR_ENCLOSED_ALPHANUMERICS
value|(1L<< 10)
comment|/* U+2460-U+24FF */
comment|/* Bit 43   Box Drawing */
DECL|macro|TT_UCR_BOX_DRAWING
define|#
directive|define
name|TT_UCR_BOX_DRAWING
value|(1L<< 11)
comment|/* U+2500-U+257F */
comment|/* Bit 44   Block Elements */
DECL|macro|TT_UCR_BLOCK_ELEMENTS
define|#
directive|define
name|TT_UCR_BLOCK_ELEMENTS
value|(1L<< 12)
comment|/* U+2580-U+259F */
comment|/* Bit 45   Geometric Shapes */
DECL|macro|TT_UCR_GEOMETRIC_SHAPES
define|#
directive|define
name|TT_UCR_GEOMETRIC_SHAPES
value|(1L<< 13)
comment|/* U+25A0-U+25FF */
comment|/* Bit 46   Miscellaneous Symbols */
DECL|macro|TT_UCR_MISCELLANEOUS_SYMBOLS
define|#
directive|define
name|TT_UCR_MISCELLANEOUS_SYMBOLS
value|(1L<< 14)
comment|/* U+2600-U+26FF */
comment|/* Bit 47   Dingbats */
DECL|macro|TT_UCR_DINGBATS
define|#
directive|define
name|TT_UCR_DINGBATS
value|(1L<< 15)
comment|/* U+2700-U+27BF */
comment|/* Bit 48   CJK Symbols and Punctuation */
DECL|macro|TT_UCR_CJK_SYMBOLS
define|#
directive|define
name|TT_UCR_CJK_SYMBOLS
value|(1L<< 16)
comment|/* U+3000-U+303F */
comment|/* Bit 49   Hiragana */
DECL|macro|TT_UCR_HIRAGANA
define|#
directive|define
name|TT_UCR_HIRAGANA
value|(1L<< 17)
comment|/* U+3040-U+309F */
comment|/* Bit 50   Katakana                     */
comment|/*          Katakana Phonetic Extensions */
DECL|macro|TT_UCR_KATAKANA
define|#
directive|define
name|TT_UCR_KATAKANA
value|(1L<< 18)
comment|/* U+30A0-U+30FF */
comment|/* U+31F0-U+31FF */
comment|/* Bit 51   Bopomofo          */
comment|/*          Bopomofo Extended */
DECL|macro|TT_UCR_BOPOMOFO
define|#
directive|define
name|TT_UCR_BOPOMOFO
value|(1L<< 19)
comment|/* U+3100-U+312F */
comment|/* U+31A0-U+31BF */
comment|/* Bit 52   Hangul Compatibility Jamo */
DECL|macro|TT_UCR_HANGUL_COMPATIBILITY_JAMO
define|#
directive|define
name|TT_UCR_HANGUL_COMPATIBILITY_JAMO
value|(1L<< 20)
comment|/* U+3130-U+318F */
comment|/* Bit 53   Phags-Pa */
DECL|macro|TT_UCR_CJK_MISC
define|#
directive|define
name|TT_UCR_CJK_MISC
value|(1L<< 21)
comment|/* U+A840-U+A87F */
DECL|macro|TT_UCR_KANBUN
define|#
directive|define
name|TT_UCR_KANBUN
value|TT_UCR_CJK_MISC
comment|/* deprecated */
DECL|macro|TT_UCR_PHAGSPA
define|#
directive|define
name|TT_UCR_PHAGSPA
comment|/* Bit 54   Enclosed CJK Letters and Months */
DECL|macro|TT_UCR_ENCLOSED_CJK_LETTERS_MONTHS
define|#
directive|define
name|TT_UCR_ENCLOSED_CJK_LETTERS_MONTHS
value|(1L<< 22)
comment|/* U+3200-U+32FF */
comment|/* Bit 55   CJK Compatibility */
DECL|macro|TT_UCR_CJK_COMPATIBILITY
define|#
directive|define
name|TT_UCR_CJK_COMPATIBILITY
value|(1L<< 23)
comment|/* U+3300-U+33FF */
comment|/* Bit 56   Hangul Syllables */
DECL|macro|TT_UCR_HANGUL
define|#
directive|define
name|TT_UCR_HANGUL
value|(1L<< 24)
comment|/* U+AC00-U+D7A3 */
comment|/* Bit 57   High Surrogates              */
comment|/*          High Private Use Surrogates  */
comment|/*          Low Surrogates               */
comment|/*                                       */
comment|/* According to OpenType specs v.1.3+,   */
comment|/* setting bit 57 implies that there is  */
comment|/* at least one codepoint beyond the     */
comment|/* Basic Multilingual Plane that is      */
comment|/* supported by this font.  So it really */
comment|/* means>= U+10000                      */
DECL|macro|TT_UCR_SURROGATES
define|#
directive|define
name|TT_UCR_SURROGATES
value|(1L<< 25)
comment|/* U+D800-U+DB7F */
comment|/* U+DB80-U+DBFF */
comment|/* U+DC00-U+DFFF */
DECL|macro|TT_UCR_NON_PLANE_0
define|#
directive|define
name|TT_UCR_NON_PLANE_0
value|TT_UCR_SURROGATES
comment|/* Bit 58  Phoenician */
DECL|macro|TT_UCR_PHOENICIAN
define|#
directive|define
name|TT_UCR_PHOENICIAN
value|(1L<< 26)
comment|/*U+10900-U+1091F*/
comment|/* Bit 59   CJK Unified Ideographs             */
comment|/*          CJK Radicals Supplement            */
comment|/*          Kangxi Radicals                    */
comment|/*          Ideographic Description Characters */
comment|/*          CJK Unified Ideographs Extension A */
comment|/*          CJK Unified Ideographs Extension B */
comment|/*          Kanbun                             */
DECL|macro|TT_UCR_CJK_UNIFIED_IDEOGRAPHS
define|#
directive|define
name|TT_UCR_CJK_UNIFIED_IDEOGRAPHS
value|(1L<< 27)
comment|/* U+4E00-U+9FFF */
comment|/* U+2E80-U+2EFF */
comment|/* U+2F00-U+2FDF */
comment|/* U+2FF0-U+2FFF */
comment|/* U+3400-U+4DB5 */
comment|/*U+20000-U+2A6DF*/
comment|/* U+3190-U+319F */
comment|/* Bit 60   Private Use */
DECL|macro|TT_UCR_PRIVATE_USE
define|#
directive|define
name|TT_UCR_PRIVATE_USE
value|(1L<< 28)
comment|/* U+E000-U+F8FF */
comment|/* Bit 61   CJK Strokes                             */
comment|/*          CJK Compatibility Ideographs            */
comment|/*          CJK Compatibility Ideographs Supplement */
DECL|macro|TT_UCR_CJK_COMPATIBILITY_IDEOGRAPHS
define|#
directive|define
name|TT_UCR_CJK_COMPATIBILITY_IDEOGRAPHS
value|(1L<< 29)
comment|/* U+31C0-U+31EF */
comment|/* U+F900-U+FAFF */
comment|/*U+2F800-U+2FA1F*/
comment|/* Bit 62   Alphabetic Presentation Forms */
DECL|macro|TT_UCR_ALPHABETIC_PRESENTATION_FORMS
define|#
directive|define
name|TT_UCR_ALPHABETIC_PRESENTATION_FORMS
value|(1L<< 30)
comment|/* U+FB00-U+FB4F */
comment|/* Bit 63   Arabic Presentation Forms-A */
DECL|macro|TT_UCR_ARABIC_PRESENTATIONS_A
define|#
directive|define
name|TT_UCR_ARABIC_PRESENTATIONS_A
value|(1L<< 31)
comment|/* U+FB50-U+FDFF */
comment|/* Bit 64   Combining Half Marks */
DECL|macro|TT_UCR_COMBINING_HALF_MARKS
define|#
directive|define
name|TT_UCR_COMBINING_HALF_MARKS
value|(1L<<  0)
comment|/* U+FE20-U+FE2F */
comment|/* Bit 65   Vertical forms          */
comment|/*          CJK Compatibility Forms */
DECL|macro|TT_UCR_CJK_COMPATIBILITY_FORMS
define|#
directive|define
name|TT_UCR_CJK_COMPATIBILITY_FORMS
value|(1L<<  1)
comment|/* U+FE10-U+FE1F */
comment|/* U+FE30-U+FE4F */
comment|/* Bit 66   Small Form Variants */
DECL|macro|TT_UCR_SMALL_FORM_VARIANTS
define|#
directive|define
name|TT_UCR_SMALL_FORM_VARIANTS
value|(1L<<  2)
comment|/* U+FE50-U+FE6F */
comment|/* Bit 67   Arabic Presentation Forms-B */
DECL|macro|TT_UCR_ARABIC_PRESENTATIONS_B
define|#
directive|define
name|TT_UCR_ARABIC_PRESENTATIONS_B
value|(1L<<  3)
comment|/* U+FE70-U+FEFE */
comment|/* Bit 68   Halfwidth and Fullwidth Forms */
DECL|macro|TT_UCR_HALFWIDTH_FULLWIDTH_FORMS
define|#
directive|define
name|TT_UCR_HALFWIDTH_FULLWIDTH_FORMS
value|(1L<<  4)
comment|/* U+FF00-U+FFEF */
comment|/* Bit 69   Specials */
DECL|macro|TT_UCR_SPECIALS
define|#
directive|define
name|TT_UCR_SPECIALS
value|(1L<<  5)
comment|/* U+FFF0-U+FFFD */
comment|/* Bit 70   Tibetan */
DECL|macro|TT_UCR_TIBETAN
define|#
directive|define
name|TT_UCR_TIBETAN
value|(1L<<  6)
comment|/* U+0F00-U+0FFF */
comment|/* Bit 71   Syriac */
DECL|macro|TT_UCR_SYRIAC
define|#
directive|define
name|TT_UCR_SYRIAC
value|(1L<<  7)
comment|/* U+0700-U+074F */
comment|/* Bit 72   Thaana */
DECL|macro|TT_UCR_THAANA
define|#
directive|define
name|TT_UCR_THAANA
value|(1L<<  8)
comment|/* U+0780-U+07BF */
comment|/* Bit 73   Sinhala */
DECL|macro|TT_UCR_SINHALA
define|#
directive|define
name|TT_UCR_SINHALA
value|(1L<<  9)
comment|/* U+0D80-U+0DFF */
comment|/* Bit 74   Myanmar */
DECL|macro|TT_UCR_MYANMAR
define|#
directive|define
name|TT_UCR_MYANMAR
value|(1L<< 10)
comment|/* U+1000-U+109F */
comment|/* Bit 75   Ethiopic            */
comment|/*          Ethiopic Supplement */
comment|/*          Ethiopic Extended   */
DECL|macro|TT_UCR_ETHIOPIC
define|#
directive|define
name|TT_UCR_ETHIOPIC
value|(1L<< 11)
comment|/* U+1200-U+137F */
comment|/* U+1380-U+139F */
comment|/* U+2D80-U+2DDF */
comment|/* Bit 76   Cherokee */
DECL|macro|TT_UCR_CHEROKEE
define|#
directive|define
name|TT_UCR_CHEROKEE
value|(1L<< 12)
comment|/* U+13A0-U+13FF */
comment|/* Bit 77   Unified Canadian Aboriginal Syllabics */
DECL|macro|TT_UCR_CANADIAN_ABORIGINAL_SYLLABICS
define|#
directive|define
name|TT_UCR_CANADIAN_ABORIGINAL_SYLLABICS
value|(1L<< 13)
comment|/* U+1400-U+167F */
comment|/* Bit 78   Ogham */
DECL|macro|TT_UCR_OGHAM
define|#
directive|define
name|TT_UCR_OGHAM
value|(1L<< 14)
comment|/* U+1680-U+169F */
comment|/* Bit 79   Runic */
DECL|macro|TT_UCR_RUNIC
define|#
directive|define
name|TT_UCR_RUNIC
value|(1L<< 15)
comment|/* U+16A0-U+16FF */
comment|/* Bit 80   Khmer         */
comment|/*          Khmer Symbols */
DECL|macro|TT_UCR_KHMER
define|#
directive|define
name|TT_UCR_KHMER
value|(1L<< 16)
comment|/* U+1780-U+17FF */
comment|/* U+19E0-U+19FF */
comment|/* Bit 81   Mongolian */
DECL|macro|TT_UCR_MONGOLIAN
define|#
directive|define
name|TT_UCR_MONGOLIAN
value|(1L<< 17)
comment|/* U+1800-U+18AF */
comment|/* Bit 82   Braille Patterns */
DECL|macro|TT_UCR_BRAILLE
define|#
directive|define
name|TT_UCR_BRAILLE
value|(1L<< 18)
comment|/* U+2800-U+28FF */
comment|/* Bit 83   Yi Syllables */
comment|/*          Yi Radicals  */
DECL|macro|TT_UCR_YI
define|#
directive|define
name|TT_UCR_YI
value|(1L<< 19)
comment|/* U+A000-U+A48F */
comment|/* U+A490-U+A4CF */
comment|/* Bit 84   Tagalog  */
comment|/*          Hanunoo  */
comment|/*          Buhid    */
comment|/*          Tagbanwa */
DECL|macro|TT_UCR_PHILIPPINE
define|#
directive|define
name|TT_UCR_PHILIPPINE
value|(1L<< 20)
comment|/* U+1700-U+171F */
comment|/* U+1720-U+173F */
comment|/* U+1740-U+175F */
comment|/* U+1760-U+177F */
comment|/* Bit 85   Old Italic */
DECL|macro|TT_UCR_OLD_ITALIC
define|#
directive|define
name|TT_UCR_OLD_ITALIC
value|(1L<< 21)
comment|/*U+10300-U+1032F*/
comment|/* Bit 86   Gothic */
DECL|macro|TT_UCR_GOTHIC
define|#
directive|define
name|TT_UCR_GOTHIC
value|(1L<< 22)
comment|/*U+10330-U+1034F*/
comment|/* Bit 87   Deseret */
DECL|macro|TT_UCR_DESERET
define|#
directive|define
name|TT_UCR_DESERET
value|(1L<< 23)
comment|/*U+10400-U+1044F*/
comment|/* Bit 88   Byzantine Musical Symbols      */
comment|/*          Musical Symbols                */
comment|/*          Ancient Greek Musical Notation */
DECL|macro|TT_UCR_MUSICAL_SYMBOLS
define|#
directive|define
name|TT_UCR_MUSICAL_SYMBOLS
value|(1L<< 24)
comment|/*U+1D000-U+1D0FF*/
comment|/*U+1D100-U+1D1FF*/
comment|/*U+1D200-U+1D24F*/
comment|/* Bit 89   Mathematical Alphanumeric Symbols */
DECL|macro|TT_UCR_MATH_ALPHANUMERIC_SYMBOLS
define|#
directive|define
name|TT_UCR_MATH_ALPHANUMERIC_SYMBOLS
value|(1L<< 25)
comment|/*U+1D400-U+1D7FF*/
comment|/* Bit 90   Private Use (plane 15) */
comment|/*          Private Use (plane 16) */
DECL|macro|TT_UCR_PRIVATE_USE_SUPPLEMENTARY
define|#
directive|define
name|TT_UCR_PRIVATE_USE_SUPPLEMENTARY
value|(1L<< 26)
comment|/*U+F0000-U+FFFFD*/
comment|/*U+100000-U+10FFFD*/
comment|/* Bit 91   Variation Selectors            */
comment|/*          Variation Selectors Supplement */
DECL|macro|TT_UCR_VARIATION_SELECTORS
define|#
directive|define
name|TT_UCR_VARIATION_SELECTORS
value|(1L<< 27)
comment|/* U+FE00-U+FE0F */
comment|/*U+E0100-U+E01EF*/
comment|/* Bit 92   Tags */
DECL|macro|TT_UCR_TAGS
define|#
directive|define
name|TT_UCR_TAGS
value|(1L<< 28)
comment|/*U+E0000-U+E007F*/
comment|/* Bit 93   Limbu */
DECL|macro|TT_UCR_LIMBU
define|#
directive|define
name|TT_UCR_LIMBU
value|(1L<< 29)
comment|/* U+1900-U+194F */
comment|/* Bit 94   Tai Le */
DECL|macro|TT_UCR_TAI_LE
define|#
directive|define
name|TT_UCR_TAI_LE
value|(1L<< 30)
comment|/* U+1950-U+197F */
comment|/* Bit 95   New Tai Lue */
DECL|macro|TT_UCR_NEW_TAI_LUE
define|#
directive|define
name|TT_UCR_NEW_TAI_LUE
value|(1L<< 31)
comment|/* U+1980-U+19DF */
comment|/* Bit 96   Buginese */
DECL|macro|TT_UCR_BUGINESE
define|#
directive|define
name|TT_UCR_BUGINESE
value|(1L<<  0)
comment|/* U+1A00-U+1A1F */
comment|/* Bit 97   Glagolitic */
DECL|macro|TT_UCR_GLAGOLITIC
define|#
directive|define
name|TT_UCR_GLAGOLITIC
value|(1L<<  1)
comment|/* U+2C00-U+2C5F */
comment|/* Bit 98   Tifinagh */
DECL|macro|TT_UCR_TIFINAGH
define|#
directive|define
name|TT_UCR_TIFINAGH
value|(1L<<  2)
comment|/* U+2D30-U+2D7F */
comment|/* Bit 99   Yijing Hexagram Symbols */
DECL|macro|TT_UCR_YIJING
define|#
directive|define
name|TT_UCR_YIJING
value|(1L<<  3)
comment|/* U+4DC0-U+4DFF */
comment|/* Bit 100  Syloti Nagri */
DECL|macro|TT_UCR_SYLOTI_NAGRI
define|#
directive|define
name|TT_UCR_SYLOTI_NAGRI
value|(1L<<  4)
comment|/* U+A800-U+A82F */
comment|/* Bit 101  Linear B Syllabary */
comment|/*          Linear B Ideograms */
comment|/*          Aegean Numbers     */
DECL|macro|TT_UCR_LINEAR_B
define|#
directive|define
name|TT_UCR_LINEAR_B
value|(1L<<  5)
comment|/*U+10000-U+1007F*/
comment|/*U+10080-U+100FF*/
comment|/*U+10100-U+1013F*/
comment|/* Bit 102  Ancient Greek Numbers */
DECL|macro|TT_UCR_ANCIENT_GREEK_NUMBERS
define|#
directive|define
name|TT_UCR_ANCIENT_GREEK_NUMBERS
value|(1L<<  6)
comment|/*U+10140-U+1018F*/
comment|/* Bit 103  Ugaritic */
DECL|macro|TT_UCR_UGARITIC
define|#
directive|define
name|TT_UCR_UGARITIC
value|(1L<<  7)
comment|/*U+10380-U+1039F*/
comment|/* Bit 104  Old Persian */
DECL|macro|TT_UCR_OLD_PERSIAN
define|#
directive|define
name|TT_UCR_OLD_PERSIAN
value|(1L<<  8)
comment|/*U+103A0-U+103DF*/
comment|/* Bit 105  Shavian */
DECL|macro|TT_UCR_SHAVIAN
define|#
directive|define
name|TT_UCR_SHAVIAN
value|(1L<<  9)
comment|/*U+10450-U+1047F*/
comment|/* Bit 106  Osmanya */
DECL|macro|TT_UCR_OSMANYA
define|#
directive|define
name|TT_UCR_OSMANYA
value|(1L<< 10)
comment|/*U+10480-U+104AF*/
comment|/* Bit 107  Cypriot Syllabary */
DECL|macro|TT_UCR_CYPRIOT_SYLLABARY
define|#
directive|define
name|TT_UCR_CYPRIOT_SYLLABARY
value|(1L<< 11)
comment|/*U+10800-U+1083F*/
comment|/* Bit 108  Kharoshthi */
DECL|macro|TT_UCR_KHAROSHTHI
define|#
directive|define
name|TT_UCR_KHAROSHTHI
value|(1L<< 12)
comment|/*U+10A00-U+10A5F*/
comment|/* Bit 109  Tai Xuan Jing Symbols */
DECL|macro|TT_UCR_TAI_XUAN_JING
define|#
directive|define
name|TT_UCR_TAI_XUAN_JING
value|(1L<< 13)
comment|/*U+1D300-U+1D35F*/
comment|/* Bit 110  Cuneiform                         */
comment|/*          Cuneiform Numbers and Punctuation */
DECL|macro|TT_UCR_CUNEIFORM
define|#
directive|define
name|TT_UCR_CUNEIFORM
value|(1L<< 14)
comment|/*U+12000-U+123FF*/
comment|/*U+12400-U+1247F*/
comment|/* Bit 111  Counting Rod Numerals */
DECL|macro|TT_UCR_COUNTING_ROD_NUMERALS
define|#
directive|define
name|TT_UCR_COUNTING_ROD_NUMERALS
value|(1L<< 15)
comment|/*U+1D360-U+1D37F*/
comment|/* Bit 112  Sundanese */
DECL|macro|TT_UCR_SUNDANESE
define|#
directive|define
name|TT_UCR_SUNDANESE
value|(1L<< 16)
comment|/* U+1B80-U+1BBF */
comment|/* Bit 113  Lepcha */
DECL|macro|TT_UCR_LEPCHA
define|#
directive|define
name|TT_UCR_LEPCHA
value|(1L<< 17)
comment|/* U+1C00-U+1C4F */
comment|/* Bit 114  Ol Chiki */
DECL|macro|TT_UCR_OL_CHIKI
define|#
directive|define
name|TT_UCR_OL_CHIKI
value|(1L<< 18)
comment|/* U+1C50-U+1C7F */
comment|/* Bit 115  Saurashtra */
DECL|macro|TT_UCR_SAURASHTRA
define|#
directive|define
name|TT_UCR_SAURASHTRA
value|(1L<< 19)
comment|/* U+A880-U+A8DF */
comment|/* Bit 116  Kayah Li */
DECL|macro|TT_UCR_KAYAH_LI
define|#
directive|define
name|TT_UCR_KAYAH_LI
value|(1L<< 20)
comment|/* U+A900-U+A92F */
comment|/* Bit 117  Rejang */
DECL|macro|TT_UCR_REJANG
define|#
directive|define
name|TT_UCR_REJANG
value|(1L<< 21)
comment|/* U+A930-U+A95F */
comment|/* Bit 118  Cham */
DECL|macro|TT_UCR_CHAM
define|#
directive|define
name|TT_UCR_CHAM
value|(1L<< 22)
comment|/* U+AA00-U+AA5F */
comment|/* Bit 119  Ancient Symbols */
DECL|macro|TT_UCR_ANCIENT_SYMBOLS
define|#
directive|define
name|TT_UCR_ANCIENT_SYMBOLS
value|(1L<< 23)
comment|/*U+10190-U+101CF*/
comment|/* Bit 120  Phaistos Disc */
DECL|macro|TT_UCR_PHAISTOS_DISC
define|#
directive|define
name|TT_UCR_PHAISTOS_DISC
value|(1L<< 24)
comment|/*U+101D0-U+101FF*/
comment|/* Bit 121  Carian */
comment|/*          Lycian */
comment|/*          Lydian */
DECL|macro|TT_UCR_OLD_ANATOLIAN
define|#
directive|define
name|TT_UCR_OLD_ANATOLIAN
value|(1L<< 25)
comment|/*U+102A0-U+102DF*/
comment|/*U+10280-U+1029F*/
comment|/*U+10920-U+1093F*/
comment|/* Bit 122  Domino Tiles  */
comment|/*          Mahjong Tiles */
DECL|macro|TT_UCR_GAME_TILES
define|#
directive|define
name|TT_UCR_GAME_TILES
value|(1L<< 26)
comment|/*U+1F030-U+1F09F*/
comment|/*U+1F000-U+1F02F*/
comment|/* Bit 123-127 Reserved for process-internal usage */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Some compilers have a very limited length of identifiers.             */
comment|/*                                                                       */
if|#
directive|if
name|defined
argument_list|(
name|__TURBOC__
argument_list|)
operator|&&
name|__TURBOC__
operator|<
literal|0x0410
operator|||
name|defined
argument_list|(
name|__PACIFIC__
argument_list|)
DECL|macro|HAVE_LIMIT_ON_IDENTS
define|#
directive|define
name|HAVE_LIMIT_ON_IDENTS
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_LIMIT_ON_IDENTS
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Here some alias #defines in order to be clearer.                      */
comment|/*                                                                       */
comment|/* These are not always #defined to stay within the 31~character limit,  */
comment|/* which some compilers have.                                            */
comment|/*                                                                       */
comment|/* Credits go to Dave Hoo<dhoo@flash.net> for pointing out that modern  */
comment|/* Borland compilers (read: from BC++ 3.1 on) can increase this limit.   */
comment|/* If you get a warning with such a compiler, use the -i40 switch.       */
comment|/*                                                                       */
DECL|macro|TT_UCR_ARABIC_PRESENTATION_FORMS_A
define|#
directive|define
name|TT_UCR_ARABIC_PRESENTATION_FORMS_A
define|\
value|TT_UCR_ARABIC_PRESENTATIONS_A
DECL|macro|TT_UCR_ARABIC_PRESENTATION_FORMS_B
define|#
directive|define
name|TT_UCR_ARABIC_PRESENTATION_FORMS_B
define|\
value|TT_UCR_ARABIC_PRESENTATIONS_B
DECL|macro|TT_UCR_COMBINING_DIACRITICAL_MARKS
define|#
directive|define
name|TT_UCR_COMBINING_DIACRITICAL_MARKS
define|\
value|TT_UCR_COMBINING_DIACRITICS
DECL|macro|TT_UCR_COMBINING_DIACRITICAL_MARKS_SYMB
define|#
directive|define
name|TT_UCR_COMBINING_DIACRITICAL_MARKS_SYMB
define|\
value|TT_UCR_COMBINING_DIACRITICS_SYMB
endif|#
directive|endif
comment|/* !HAVE_LIMIT_ON_IDENTS */
name|FT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __TTNAMEID_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
