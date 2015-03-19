begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftgxval.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType API for validating TrueTypeGX/AAT tables (specification).   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004-2006, 2013 by                                           */
end_comment
begin_comment
comment|/*  Masatake YAMATO, Redhat K.K,                                           */
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
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/* gxvalid is derived from both gxlayout module and otvalid module.        */
end_comment
begin_comment
comment|/* Development of gxlayout is supported by the Information-technology      */
end_comment
begin_comment
comment|/* Promotion Agency(IPA), Japan.                                           */
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
name|__FTGXVAL_H__
end_ifndef
begin_define
DECL|macro|__FTGXVAL_H__
define|#
directive|define
name|__FTGXVAL_H__
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
begin_function_decl
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Section>                                                             */
comment|/*    gx_validation                                                      */
comment|/*                                                                       */
comment|/*<Title>                                                               */
comment|/*    TrueTypeGX/AAT Validation                                          */
comment|/*                                                                       */
comment|/*<Abstract>                                                            */
comment|/*    An API to validate TrueTypeGX/AAT tables.                          */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    This section contains the declaration of functions to validate     */
comment|/*    some TrueTypeGX tables (feat, mort, morx, bsln, just, kern, opbd,  */
comment|/*    trak, prop, lcar).                                                 */
comment|/*                                                                       */
comment|/*<Order>                                                               */
comment|/*    FT_TrueTypeGX_Validate                                             */
comment|/*    FT_TrueTypeGX_Free                                                 */
comment|/*                                                                       */
comment|/*    FT_ClassicKern_Validate                                            */
comment|/*    FT_ClassicKern_Free                                                */
comment|/*                                                                       */
comment|/*    FT_VALIDATE_GX_LENGTH                                              */
comment|/*    FT_VALIDATE_GXXXX                                                  */
comment|/*    FT_VALIDATE_CKERNXXX                                               */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*                                                                       */
comment|/* Warning: Use FT_VALIDATE_XXX to validate a table.                     */
comment|/*          Following definitions are for gxvalid developers.            */
comment|/*                                                                       */
comment|/*                                                                       */
comment|/*************************************************************************/
DECL|macro|FT_VALIDATE_feat_INDEX
define|#
directive|define
name|FT_VALIDATE_feat_INDEX
value|0
DECL|macro|FT_VALIDATE_mort_INDEX
define|#
directive|define
name|FT_VALIDATE_mort_INDEX
value|1
DECL|macro|FT_VALIDATE_morx_INDEX
define|#
directive|define
name|FT_VALIDATE_morx_INDEX
value|2
DECL|macro|FT_VALIDATE_bsln_INDEX
define|#
directive|define
name|FT_VALIDATE_bsln_INDEX
value|3
DECL|macro|FT_VALIDATE_just_INDEX
define|#
directive|define
name|FT_VALIDATE_just_INDEX
value|4
DECL|macro|FT_VALIDATE_kern_INDEX
define|#
directive|define
name|FT_VALIDATE_kern_INDEX
value|5
DECL|macro|FT_VALIDATE_opbd_INDEX
define|#
directive|define
name|FT_VALIDATE_opbd_INDEX
value|6
DECL|macro|FT_VALIDATE_trak_INDEX
define|#
directive|define
name|FT_VALIDATE_trak_INDEX
value|7
DECL|macro|FT_VALIDATE_prop_INDEX
define|#
directive|define
name|FT_VALIDATE_prop_INDEX
value|8
DECL|macro|FT_VALIDATE_lcar_INDEX
define|#
directive|define
name|FT_VALIDATE_lcar_INDEX
value|9
DECL|macro|FT_VALIDATE_GX_LAST_INDEX
define|#
directive|define
name|FT_VALIDATE_GX_LAST_INDEX
value|FT_VALIDATE_lcar_INDEX
comment|/*************************************************************************    *    * @macro:    *   FT_VALIDATE_GX_LENGTH    *    * @description:    *   The number of tables checked in this module.  Use it as a parameter    *   for the `table-length' argument of function @FT_TrueTypeGX_Validate.    */
DECL|macro|FT_VALIDATE_GX_LENGTH
define|#
directive|define
name|FT_VALIDATE_GX_LENGTH
value|(FT_VALIDATE_GX_LAST_INDEX + 1)
comment|/* */
comment|/* Up to 0x1000 is used by otvalid.      Ox2xxx is reserved for feature OT extension. */
DECL|macro|FT_VALIDATE_GX_START
define|#
directive|define
name|FT_VALIDATE_GX_START
value|0x4000
DECL|macro|FT_VALIDATE_GX_BITFIELD
define|#
directive|define
name|FT_VALIDATE_GX_BITFIELD
parameter_list|(
name|tag
parameter_list|)
define|\
value|( FT_VALIDATE_GX_START<< FT_VALIDATE_##tag##_INDEX )
comment|/**********************************************************************   *   * @enum:   *    FT_VALIDATE_GXXXX   *   * @description:   *    A list of bit-field constants used with @FT_TrueTypeGX_Validate to   *    indicate which TrueTypeGX/AAT Type tables should be validated.   *   * @values:   *    FT_VALIDATE_feat ::   *      Validate `feat' table.   *   *    FT_VALIDATE_mort ::   *      Validate `mort' table.   *   *    FT_VALIDATE_morx ::   *      Validate `morx' table.   *   *    FT_VALIDATE_bsln ::   *      Validate `bsln' table.   *   *    FT_VALIDATE_just ::   *      Validate `just' table.   *   *    FT_VALIDATE_kern ::   *      Validate `kern' table.   *   *    FT_VALIDATE_opbd ::   *      Validate `opbd' table.   *   *    FT_VALIDATE_trak ::   *      Validate `trak' table.   *   *    FT_VALIDATE_prop ::   *      Validate `prop' table.   *   *    FT_VALIDATE_lcar ::   *      Validate `lcar' table.   *   *    FT_VALIDATE_GX ::   *      Validate all TrueTypeGX tables (feat, mort, morx, bsln, just, kern,   *      opbd, trak, prop and lcar).   *   */
DECL|macro|FT_VALIDATE_feat
define|#
directive|define
name|FT_VALIDATE_feat
value|FT_VALIDATE_GX_BITFIELD( feat )
DECL|macro|FT_VALIDATE_mort
define|#
directive|define
name|FT_VALIDATE_mort
value|FT_VALIDATE_GX_BITFIELD( mort )
DECL|macro|FT_VALIDATE_morx
define|#
directive|define
name|FT_VALIDATE_morx
value|FT_VALIDATE_GX_BITFIELD( morx )
DECL|macro|FT_VALIDATE_bsln
define|#
directive|define
name|FT_VALIDATE_bsln
value|FT_VALIDATE_GX_BITFIELD( bsln )
DECL|macro|FT_VALIDATE_just
define|#
directive|define
name|FT_VALIDATE_just
value|FT_VALIDATE_GX_BITFIELD( just )
DECL|macro|FT_VALIDATE_kern
define|#
directive|define
name|FT_VALIDATE_kern
value|FT_VALIDATE_GX_BITFIELD( kern )
DECL|macro|FT_VALIDATE_opbd
define|#
directive|define
name|FT_VALIDATE_opbd
value|FT_VALIDATE_GX_BITFIELD( opbd )
DECL|macro|FT_VALIDATE_trak
define|#
directive|define
name|FT_VALIDATE_trak
value|FT_VALIDATE_GX_BITFIELD( trak )
DECL|macro|FT_VALIDATE_prop
define|#
directive|define
name|FT_VALIDATE_prop
value|FT_VALIDATE_GX_BITFIELD( prop )
DECL|macro|FT_VALIDATE_lcar
define|#
directive|define
name|FT_VALIDATE_lcar
value|FT_VALIDATE_GX_BITFIELD( lcar )
DECL|macro|FT_VALIDATE_GX
define|#
directive|define
name|FT_VALIDATE_GX
value|( FT_VALIDATE_feat | \                           FT_VALIDATE_mort | \                           FT_VALIDATE_morx | \                           FT_VALIDATE_bsln | \                           FT_VALIDATE_just | \                           FT_VALIDATE_kern | \                           FT_VALIDATE_opbd | \                           FT_VALIDATE_trak | \                           FT_VALIDATE_prop | \                           FT_VALIDATE_lcar )
comment|/**********************************************************************   *   * @function:   *    FT_TrueTypeGX_Validate   *   * @description:   *    Validate various TrueTypeGX tables to assure that all offsets and   *    indices are valid.  The idea is that a higher-level library that   *    actually does the text layout can access those tables without   *    error checking (which can be quite time consuming).   *   * @input:   *    face ::   *       A handle to the input face.   *   *    validation_flags ::   *       A bit field that specifies the tables to be validated.  See   *       @FT_VALIDATE_GXXXX for possible values.   *   *    table_length ::   *       The size of the `tables' array.  Normally, @FT_VALIDATE_GX_LENGTH   *       should be passed.   *   * @output:   *    tables ::   *       The array where all validated sfnt tables are stored.   *       The array itself must be allocated by a client.   *   * @return:   *   FreeType error code.  0~means success.   *   * @note:   *   This function only works with TrueTypeGX fonts, returning an error   *   otherwise.   *   *   After use, the application should deallocate the buffers pointed to by   *   each `tables' element, by calling @FT_TrueTypeGX_Free.  A NULL value   *   indicates that the table either doesn't exist in the font, the   *   application hasn't asked for validation, or the validator doesn't have   *   the ability to validate the sfnt table.   */
name|FT_EXPORT
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|FT_TrueTypeGX_Validate
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|validation_flags
parameter_list|,
name|FT_Bytes
name|tables
index|[
name|FT_VALIDATE_GX_LENGTH
index|]
parameter_list|,
name|FT_UInt
name|table_length
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**********************************************************************   *   * @function:   *    FT_TrueTypeGX_Free   *   * @description:   *    Free the buffer allocated by TrueTypeGX validator.   *   * @input:   *    face ::   *       A handle to the input face.   *   *    table ::   *       The pointer to the buffer allocated by   *       @FT_TrueTypeGX_Validate.   *   * @note:   *   This function must be used to free the buffer allocated by   *   @FT_TrueTypeGX_Validate only.   */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FT_TrueTypeGX_Free
name|FT_TrueTypeGX_Free
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_Bytes  table
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**********************************************************************   *   * @enum:   *    FT_VALIDATE_CKERNXXX   *   * @description:   *    A list of bit-field constants used with @FT_ClassicKern_Validate   *    to indicate the classic kern dialect or dialects.  If the selected   *    type doesn't fit, @FT_ClassicKern_Validate regards the table as   *    invalid.   *   * @values:   *    FT_VALIDATE_MS ::   *      Handle the `kern' table as a classic Microsoft kern table.   *   *    FT_VALIDATE_APPLE ::   *      Handle the `kern' table as a classic Apple kern table.   *   *    FT_VALIDATE_CKERN ::   *      Handle the `kern' as either classic Apple or Microsoft kern table.   */
end_comment
begin_define
DECL|macro|FT_VALIDATE_MS
define|#
directive|define
name|FT_VALIDATE_MS
value|( FT_VALIDATE_GX_START<< 0 )
end_define
begin_define
DECL|macro|FT_VALIDATE_APPLE
define|#
directive|define
name|FT_VALIDATE_APPLE
value|( FT_VALIDATE_GX_START<< 1 )
end_define
begin_define
DECL|macro|FT_VALIDATE_CKERN
define|#
directive|define
name|FT_VALIDATE_CKERN
value|( FT_VALIDATE_MS | FT_VALIDATE_APPLE )
end_define
begin_comment
comment|/**********************************************************************   *   * @function:   *    FT_ClassicKern_Validate   *   * @description:   *    Validate classic (16-bit format) kern table to assure that the offsets   *    and indices are valid.  The idea is that a higher-level library that   *    actually does the text layout can access those tables without error   *    checking (which can be quite time consuming).   *   *    The `kern' table validator in @FT_TrueTypeGX_Validate deals with both   *    the new 32-bit format and the classic 16-bit format, while   *    FT_ClassicKern_Validate only supports the classic 16-bit format.   *   * @input:   *    face ::   *       A handle to the input face.   *   *    validation_flags ::   *       A bit field that specifies the dialect to be validated.  See   *       @FT_VALIDATE_CKERNXXX for possible values.   *   * @output:   *    ckern_table ::   *       A pointer to the kern table.   *   * @return:   *   FreeType error code.  0~means success.   *   * @note:   *   After use, the application should deallocate the buffers pointed to by   *   `ckern_table', by calling @FT_ClassicKern_Free.  A NULL value   *   indicates that the table doesn't exist in the font.   */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_ClassicKern_Validate
argument_list|(
argument|FT_Face    face
argument_list|,
argument|FT_UInt    validation_flags
argument_list|,
argument|FT_Bytes  *ckern_table
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**********************************************************************   *   * @function:   *    FT_ClassicKern_Free   *   * @description:   *    Free the buffer allocated by classic Kern validator.   *   * @input:   *    face ::   *       A handle to the input face.   *   *    table ::   *       The pointer to the buffer that is allocated by   *       @FT_ClassicKern_Validate.   *   * @note:   *   This function must be used to free the buffer allocated by   *   @FT_ClassicKern_Validate only.   */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FT_ClassicKern_Free
name|FT_ClassicKern_Free
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_Bytes  table
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
comment|/* __FTGXVAL_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
