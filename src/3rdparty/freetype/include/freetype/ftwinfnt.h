begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftwinfnt.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType API for accessing Windows fnt-specific data.                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2004, 2008 by                                          */
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
name|__FTWINFNT_H__
end_ifndef
begin_define
DECL|macro|__FTWINFNT_H__
define|#
directive|define
name|__FTWINFNT_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_FREETYPE_H
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FREETYPE_H
end_ifdef
begin_error
error|#
directive|error
literal|"freetype.h of FreeType 1 has been loaded!"
end_error
begin_error
error|#
directive|error
literal|"Please fix the directory search order for header files"
end_error
begin_error
error|#
directive|error
literal|"so that freetype.h of FreeType 2 is found first."
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    winfnt_fonts                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    Window FNT Files                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    Windows FNT specific API.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This section contains the declaration of Windows FNT specific      */
end_comment
begin_comment
comment|/*    functions.                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************    *    * @enum:    *   FT_WinFNT_ID_XXX    *    * @description:    *   A list of valid values for the `charset' byte in    *   @FT_WinFNT_HeaderRec.  Exact mapping tables for the various cpXXXX    *   encodings (except for cp1361) can be found at ftp://ftp.unicode.org    *   in the MAPPINGS/VENDORS/MICSFT/WINDOWS subdirectory.  cp1361 is    *   roughly a superset of MAPPINGS/OBSOLETE/EASTASIA/KSC/JOHAB.TXT.    *    * @values:    *   FT_WinFNT_ID_DEFAULT ::    *     This is used for font enumeration and font creation as a    *     `don't care' value.  Valid font files don't contain this value.    *     When querying for information about the character set of the font    *     that is currently selected into a specified device context, this    *     return value (of the related Windows API) simply denotes failure.    *    *   FT_WinFNT_ID_SYMBOL ::    *     There is no known mapping table available.    *    *   FT_WinFNT_ID_MAC ::    *     Mac Roman encoding.    *    *   FT_WinFNT_ID_OEM ::    *     From Michael PÃ¶ttgen<michael@poettgen.de>:    *    *       The `Windows Font Mapping' article says that FT_WinFNT_ID_OEM    *       is used for the charset of vector fonts, like `modern.fon',    *       `roman.fon', and `script.fon' on Windows.    *    *       The `CreateFont' documentation says: The FT_WinFNT_ID_OEM value    *       specifies a character set that is operating-system dependent.    *    *       The `IFIMETRICS' documentation from the `Windows Driver    *       Development Kit' says: This font supports an OEM-specific    *       character set.  The OEM character set is system dependent.    *    *       In general OEM, as opposed to ANSI (i.e., cp1252), denotes the    *       second default codepage that most international versions of    *       Windows have.  It is one of the OEM codepages from    *    *         http://www.microsoft.com/globaldev/reference/cphome.mspx,    *    *       and is used for the `DOS boxes', to support legacy applications.    *       A German Windows version for example usually uses ANSI codepage    *       1252 and OEM codepage 850.    *    *   FT_WinFNT_ID_CP874 ::    *     A superset of Thai TIS 620 and ISO 8859-11.    *    *   FT_WinFNT_ID_CP932 ::    *     A superset of Japanese Shift-JIS (with minor deviations).    *    *   FT_WinFNT_ID_CP936 ::    *     A superset of simplified Chinese GB 2312-1980 (with different    *     ordering and minor deviations).    *    *   FT_WinFNT_ID_CP949 ::    *     A superset of Korean Hangul KS~C 5601-1987 (with different    *     ordering and minor deviations).    *    *   FT_WinFNT_ID_CP950 ::    *     A superset of traditional Chinese Big~5 ETen (with different    *     ordering and minor deviations).    *    *   FT_WinFNT_ID_CP1250 ::    *     A superset of East European ISO 8859-2 (with slightly different    *     ordering).    *    *   FT_WinFNT_ID_CP1251 ::    *     A superset of Russian ISO 8859-5 (with different ordering).    *    *   FT_WinFNT_ID_CP1252 ::    *     ANSI encoding.  A superset of ISO 8859-1.    *    *   FT_WinFNT_ID_CP1253 ::    *     A superset of Greek ISO 8859-7 (with minor modifications).    *    *   FT_WinFNT_ID_CP1254 ::    *     A superset of Turkish ISO 8859-9.    *    *   FT_WinFNT_ID_CP1255 ::    *     A superset of Hebrew ISO 8859-8 (with some modifications).    *    *   FT_WinFNT_ID_CP1256 ::    *     A superset of Arabic ISO 8859-6 (with different ordering).    *    *   FT_WinFNT_ID_CP1257 ::    *     A superset of Baltic ISO 8859-13 (with some deviations).    *    *   FT_WinFNT_ID_CP1258 ::    *     For Vietnamese.  This encoding doesn't cover all necessary    *     characters.    *    *   FT_WinFNT_ID_CP1361 ::    *     Korean (Johab).    */
end_comment
begin_define
DECL|macro|FT_WinFNT_ID_CP1252
define|#
directive|define
name|FT_WinFNT_ID_CP1252
value|0
end_define
begin_define
DECL|macro|FT_WinFNT_ID_DEFAULT
define|#
directive|define
name|FT_WinFNT_ID_DEFAULT
value|1
end_define
begin_define
DECL|macro|FT_WinFNT_ID_SYMBOL
define|#
directive|define
name|FT_WinFNT_ID_SYMBOL
value|2
end_define
begin_define
DECL|macro|FT_WinFNT_ID_MAC
define|#
directive|define
name|FT_WinFNT_ID_MAC
value|77
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP932
define|#
directive|define
name|FT_WinFNT_ID_CP932
value|128
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP949
define|#
directive|define
name|FT_WinFNT_ID_CP949
value|129
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP1361
define|#
directive|define
name|FT_WinFNT_ID_CP1361
value|130
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP936
define|#
directive|define
name|FT_WinFNT_ID_CP936
value|134
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP950
define|#
directive|define
name|FT_WinFNT_ID_CP950
value|136
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP1253
define|#
directive|define
name|FT_WinFNT_ID_CP1253
value|161
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP1254
define|#
directive|define
name|FT_WinFNT_ID_CP1254
value|162
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP1258
define|#
directive|define
name|FT_WinFNT_ID_CP1258
value|163
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP1255
define|#
directive|define
name|FT_WinFNT_ID_CP1255
value|177
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP1256
define|#
directive|define
name|FT_WinFNT_ID_CP1256
value|178
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP1257
define|#
directive|define
name|FT_WinFNT_ID_CP1257
value|186
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP1251
define|#
directive|define
name|FT_WinFNT_ID_CP1251
value|204
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP874
define|#
directive|define
name|FT_WinFNT_ID_CP874
value|222
end_define
begin_define
DECL|macro|FT_WinFNT_ID_CP1250
define|#
directive|define
name|FT_WinFNT_ID_CP1250
value|238
end_define
begin_define
DECL|macro|FT_WinFNT_ID_OEM
define|#
directive|define
name|FT_WinFNT_ID_OEM
value|255
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    FT_WinFNT_HeaderRec                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Windows FNT Header info.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_WinFNT_HeaderRec_
typedef|typedef
struct|struct
name|FT_WinFNT_HeaderRec_
block|{
DECL|member|version
name|FT_UShort
name|version
decl_stmt|;
DECL|member|file_size
name|FT_ULong
name|file_size
decl_stmt|;
DECL|member|copyright
name|FT_Byte
name|copyright
index|[
literal|60
index|]
decl_stmt|;
DECL|member|file_type
name|FT_UShort
name|file_type
decl_stmt|;
DECL|member|nominal_point_size
name|FT_UShort
name|nominal_point_size
decl_stmt|;
DECL|member|vertical_resolution
name|FT_UShort
name|vertical_resolution
decl_stmt|;
DECL|member|horizontal_resolution
name|FT_UShort
name|horizontal_resolution
decl_stmt|;
DECL|member|ascent
name|FT_UShort
name|ascent
decl_stmt|;
DECL|member|internal_leading
name|FT_UShort
name|internal_leading
decl_stmt|;
DECL|member|external_leading
name|FT_UShort
name|external_leading
decl_stmt|;
DECL|member|italic
name|FT_Byte
name|italic
decl_stmt|;
DECL|member|underline
name|FT_Byte
name|underline
decl_stmt|;
DECL|member|strike_out
name|FT_Byte
name|strike_out
decl_stmt|;
DECL|member|weight
name|FT_UShort
name|weight
decl_stmt|;
DECL|member|charset
name|FT_Byte
name|charset
decl_stmt|;
DECL|member|pixel_width
name|FT_UShort
name|pixel_width
decl_stmt|;
DECL|member|pixel_height
name|FT_UShort
name|pixel_height
decl_stmt|;
DECL|member|pitch_and_family
name|FT_Byte
name|pitch_and_family
decl_stmt|;
DECL|member|avg_width
name|FT_UShort
name|avg_width
decl_stmt|;
DECL|member|max_width
name|FT_UShort
name|max_width
decl_stmt|;
DECL|member|first_char
name|FT_Byte
name|first_char
decl_stmt|;
DECL|member|last_char
name|FT_Byte
name|last_char
decl_stmt|;
DECL|member|default_char
name|FT_Byte
name|default_char
decl_stmt|;
DECL|member|break_char
name|FT_Byte
name|break_char
decl_stmt|;
DECL|member|bytes_per_row
name|FT_UShort
name|bytes_per_row
decl_stmt|;
DECL|member|device_offset
name|FT_ULong
name|device_offset
decl_stmt|;
DECL|member|face_name_offset
name|FT_ULong
name|face_name_offset
decl_stmt|;
DECL|member|bits_pointer
name|FT_ULong
name|bits_pointer
decl_stmt|;
DECL|member|bits_offset
name|FT_ULong
name|bits_offset
decl_stmt|;
DECL|member|reserved
name|FT_Byte
name|reserved
decl_stmt|;
DECL|member|flags
name|FT_ULong
name|flags
decl_stmt|;
DECL|member|A_space
name|FT_UShort
name|A_space
decl_stmt|;
DECL|member|B_space
name|FT_UShort
name|B_space
decl_stmt|;
DECL|member|C_space
name|FT_UShort
name|C_space
decl_stmt|;
DECL|member|color_table_offset
name|FT_UShort
name|color_table_offset
decl_stmt|;
DECL|member|reserved1
name|FT_ULong
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
block|}
DECL|typedef|FT_WinFNT_HeaderRec
name|FT_WinFNT_HeaderRec
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    FT_WinFNT_Header                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to an @FT_WinFNT_HeaderRec structure.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_WinFNT_Header
typedef|typedef
name|struct
name|FT_WinFNT_HeaderRec_
modifier|*
name|FT_WinFNT_Header
typedef|;
end_typedef
begin_comment
comment|/**********************************************************************    *    * @function:    *    FT_Get_WinFNT_Header    *    * @description:    *    Retrieve a Windows FNT font info header.    *    * @input:    *    face    :: A handle to the input face.    *    * @output:    *    aheader :: The WinFNT header.    *    * @return:    *   FreeType error code.  0~means success.    *    * @note:    *   This function only works with Windows FNT faces, returning an error    *   otherwise.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_WinFNT_Header
argument_list|(
argument|FT_Face               face
argument_list|,
argument|FT_WinFNT_HeaderRec  *aheader
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTWINFNT_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
begin_comment
comment|/* Local Variables: */
end_comment
begin_comment
comment|/* coding: utf-8    */
end_comment
begin_comment
comment|/* End:             */
end_comment
end_unit
