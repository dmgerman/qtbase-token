begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftotval.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType API for validating OpenType tables (specification).         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004-2007, 2013, 2014 by                                     */
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
comment|/*                                                                         */
end_comment
begin_comment
comment|/* Warning: This module might be moved to a different library in the       */
end_comment
begin_comment
comment|/*          future to avoid a tight dependency between FreeType and the    */
end_comment
begin_comment
comment|/*          OpenType specification.                                        */
end_comment
begin_comment
comment|/*                                                                         */
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
name|__FTOTVAL_H__
end_ifndef
begin_define
DECL|macro|__FTOTVAL_H__
define|#
directive|define
name|__FTOTVAL_H__
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
comment|/*    ot_validation                                                      */
comment|/*                                                                       */
comment|/*<Title>                                                               */
comment|/*    OpenType Validation                                                */
comment|/*                                                                       */
comment|/*<Abstract>                                                            */
comment|/*    An API to validate OpenType tables.                                */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    This section contains the declaration of functions to validate     */
comment|/*    some OpenType tables (BASE, GDEF, GPOS, GSUB, JSTF, MATH).         */
comment|/*                                                                       */
comment|/*<Order>                                                               */
comment|/*    FT_OpenType_Validate                                               */
comment|/*    FT_OpenType_Free                                                   */
comment|/*                                                                       */
comment|/*    FT_VALIDATE_OTXXX                                                  */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/**********************************************************************   *   * @enum:   *    FT_VALIDATE_OTXXX   *   * @description:   *    A list of bit-field constants used with @FT_OpenType_Validate to   *    indicate which OpenType tables should be validated.   *   * @values:   *    FT_VALIDATE_BASE ::   *      Validate BASE table.   *   *    FT_VALIDATE_GDEF ::   *      Validate GDEF table.   *   *    FT_VALIDATE_GPOS ::   *      Validate GPOS table.   *   *    FT_VALIDATE_GSUB ::   *      Validate GSUB table.   *   *    FT_VALIDATE_JSTF ::   *      Validate JSTF table.   *   *    FT_VALIDATE_MATH ::   *      Validate MATH table.   *   *    FT_VALIDATE_OT ::   *      Validate all OpenType tables (BASE, GDEF, GPOS, GSUB, JSTF, MATH).   *   */
DECL|macro|FT_VALIDATE_BASE
define|#
directive|define
name|FT_VALIDATE_BASE
value|0x0100
DECL|macro|FT_VALIDATE_GDEF
define|#
directive|define
name|FT_VALIDATE_GDEF
value|0x0200
DECL|macro|FT_VALIDATE_GPOS
define|#
directive|define
name|FT_VALIDATE_GPOS
value|0x0400
DECL|macro|FT_VALIDATE_GSUB
define|#
directive|define
name|FT_VALIDATE_GSUB
value|0x0800
DECL|macro|FT_VALIDATE_JSTF
define|#
directive|define
name|FT_VALIDATE_JSTF
value|0x1000
DECL|macro|FT_VALIDATE_MATH
define|#
directive|define
name|FT_VALIDATE_MATH
value|0x2000
DECL|macro|FT_VALIDATE_OT
define|#
directive|define
name|FT_VALIDATE_OT
value|FT_VALIDATE_BASE | \                         FT_VALIDATE_GDEF | \                         FT_VALIDATE_GPOS | \                         FT_VALIDATE_GSUB | \                         FT_VALIDATE_JSTF | \                         FT_VALIDATE_MATH
comment|/**********************************************************************   *   * @function:   *    FT_OpenType_Validate   *   * @description:   *    Validate various OpenType tables to assure that all offsets and   *    indices are valid.  The idea is that a higher-level library that   *    actually does the text layout can access those tables without   *    error checking (which can be quite time consuming).   *   * @input:   *    face ::   *       A handle to the input face.   *   *    validation_flags ::   *       A bit field that specifies the tables to be validated.  See   *       @FT_VALIDATE_OTXXX for possible values.   *   * @output:   *    BASE_table ::   *       A pointer to the BASE table.   *   *    GDEF_table ::   *       A pointer to the GDEF table.   *   *    GPOS_table ::   *       A pointer to the GPOS table.   *   *    GSUB_table ::   *       A pointer to the GSUB table.   *   *    JSTF_table ::   *       A pointer to the JSTF table.   *   * @return:   *   FreeType error code.  0~means success.   *   * @note:   *   This function only works with OpenType fonts, returning an error   *   otherwise.   *   *   After use, the application should deallocate the five tables with   *   @FT_OpenType_Free.  A NULL value indicates that the table either   *   doesn't exist in the font, or the application hasn't asked for   *   validation.   */
name|FT_EXPORT
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|FT_OpenType_Validate
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|validation_flags
parameter_list|,
name|FT_Bytes
modifier|*
name|BASE_table
parameter_list|,
name|FT_Bytes
modifier|*
name|GDEF_table
parameter_list|,
name|FT_Bytes
modifier|*
name|GPOS_table
parameter_list|,
name|FT_Bytes
modifier|*
name|GSUB_table
parameter_list|,
name|FT_Bytes
modifier|*
name|JSTF_table
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**********************************************************************   *   * @function:   *    FT_OpenType_Free   *   * @description:   *    Free the buffer allocated by OpenType validator.   *   * @input:   *    face ::   *       A handle to the input face.   *   *    table ::   *       The pointer to the buffer that is allocated by   *       @FT_OpenType_Validate.   *   * @note:   *   This function must be used to free the buffer allocated by   *   @FT_OpenType_Validate only.   */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FT_OpenType_Free
name|FT_OpenType_Free
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
comment|/* __FTOTVAL_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
