begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftsnames.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Simple interface to access SFNT name tables (which are used          */
end_comment
begin_comment
comment|/*    to hold font names, copyright info, notices, etc.) (specification).  */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    This is _not_ used to retrieve glyph names!                          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2006, 2009, 2010 by                   */
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
name|__FT_SFNT_NAMES_H__
end_ifndef
begin_define
DECL|macro|__FT_SFNT_NAMES_H__
define|#
directive|define
name|__FT_SFNT_NAMES_H__
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
comment|/*    sfnt_names                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    SFNT Names                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    Access the names embedded in TrueType and OpenType files.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The TrueType and OpenType specifications allow the inclusion of    */
end_comment
begin_comment
comment|/*    a special `names table' in font files.  This table contains        */
end_comment
begin_comment
comment|/*    textual (and internationalized) information regarding the font,    */
end_comment
begin_comment
comment|/*    like family name, copyright, version, etc.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The definitions below are used to access them if available.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Note that this has nothing to do with glyph names!                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
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
comment|/*    FT_SfntName                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model an SFNT `name' table entry.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    platform_id :: The platform ID for `string'.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    encoding_id :: The encoding ID for `string'.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    language_id :: The language ID for `string'.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    name_id     :: An identifier for `string'.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    string      :: The `name' string.  Note that its format differs    */
end_comment
begin_comment
comment|/*                   depending on the (platform,encoding) pair.  It can  */
end_comment
begin_comment
comment|/*                   be a Pascal String, a UTF-16 one, etc.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                   Generally speaking, the string is not               */
end_comment
begin_comment
comment|/*                   zero-terminated.  Please refer to the TrueType      */
end_comment
begin_comment
comment|/*                   specification for details.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    string_len  :: The length of `string' in bytes.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Possible values for `platform_id', `encoding_id', `language_id',   */
end_comment
begin_comment
comment|/*    and `name_id' are given in the file `ttnameid.h'.  For details     */
end_comment
begin_comment
comment|/*    please refer to the TrueType or OpenType specification.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    See also @TT_PLATFORM_XXX, @TT_APPLE_ID_XXX, @TT_MAC_ID_XXX,       */
end_comment
begin_comment
comment|/*    @TT_ISO_ID_XXX, and @TT_MS_ID_XXX.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_SfntName_
typedef|typedef
struct|struct
name|FT_SfntName_
block|{
DECL|member|platform_id
name|FT_UShort
name|platform_id
decl_stmt|;
DECL|member|encoding_id
name|FT_UShort
name|encoding_id
decl_stmt|;
DECL|member|language_id
name|FT_UShort
name|language_id
decl_stmt|;
DECL|member|name_id
name|FT_UShort
name|name_id
decl_stmt|;
DECL|member|string
name|FT_Byte
modifier|*
name|string
decl_stmt|;
comment|/* this string is *not* null-terminated! */
DECL|member|string_len
name|FT_UInt
name|string_len
decl_stmt|;
comment|/* in bytes */
block|}
DECL|typedef|FT_SfntName
name|FT_SfntName
typedef|;
end_typedef
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
comment|/*    FT_Get_Sfnt_Name_Count                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Retrieve the number of name strings in the SFNT `name' table.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face :: A handle to the source face.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The number of strings in the `name' table.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_UInt
argument_list|)
end_macro
begin_macro
name|FT_Get_Sfnt_Name_Count
argument_list|(
argument|FT_Face  face
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
comment|/*    FT_Get_Sfnt_Name                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Retrieve a string of the SFNT `name' table for a given index.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face  :: A handle to the source face.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    idx   :: The index of the `name' string.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    aname :: The indexed @FT_SfntName structure.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The `string' array returned in the `aname' structure is not        */
end_comment
begin_comment
comment|/*    null-terminated.  The application should deallocate it if it is no */
end_comment
begin_comment
comment|/*    longer in use.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Use @FT_Get_Sfnt_Name_Count to get the total number of available   */
end_comment
begin_comment
comment|/*    `name' table entries, then do a loop until you get the right       */
end_comment
begin_comment
comment|/*    platform, encoding, and name ID.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Get_Sfnt_Name
name|FT_Get_Sfnt_Name
argument_list|(
argument|FT_Face       face
argument_list|,
argument|FT_UInt       idx
argument_list|,
argument|FT_SfntName  *aname
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/***************************************************************************    *    * @constant:    *   FT_PARAM_TAG_IGNORE_PREFERRED_FAMILY    *    * @description:    *   A constant used as the tag of @FT_Parameter structures to make    *   FT_Open_Face() ignore preferred family subfamily names in `name'    *   table since OpenType version 1.4.  For backwards compatibility with    *   legacy systems which has 4-face-per-family restriction.    *    */
end_comment
begin_define
DECL|macro|FT_PARAM_TAG_IGNORE_PREFERRED_FAMILY
define|#
directive|define
name|FT_PARAM_TAG_IGNORE_PREFERRED_FAMILY
value|FT_MAKE_TAG( 'i', 'g', 'p', 'f' )
end_define
begin_comment
comment|/***************************************************************************    *    * @constant:    *   FT_PARAM_TAG_IGNORE_PREFERRED_SUBFAMILY    *    * @description:    *   A constant used as the tag of @FT_Parameter structures to make    *   FT_Open_Face() ignore preferred subfamily names in `name' table since    *   OpenType version 1.4.  For backwards compatibility with legacy    *   systems which has 4-face-per-family restriction.    *    */
end_comment
begin_define
DECL|macro|FT_PARAM_TAG_IGNORE_PREFERRED_SUBFAMILY
define|#
directive|define
name|FT_PARAM_TAG_IGNORE_PREFERRED_SUBFAMILY
value|FT_MAKE_TAG( 'i', 'g', 'p', 's' )
end_define
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
comment|/* __FT_SFNT_NAMES_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
