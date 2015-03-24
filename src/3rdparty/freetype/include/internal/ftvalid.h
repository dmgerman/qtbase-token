begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftvalid.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType validation support (specification).                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2013, 2014 by                                          */
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
name|__FTVALID_H__
end_ifndef
begin_define
DECL|macro|__FTVALID_H__
define|#
directive|define
name|__FTVALID_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_CONFIG_STANDARD_LIBRARY_H
end_include
begin_comment
comment|/* for ft_setjmp and ft_longjmp */
end_comment
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                    V A L I D A T I O N                          ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* handle to a validation object */
end_comment
begin_typedef
DECL|typedef|FT_Validator
typedef|typedef
name|struct
name|FT_ValidatorRec_
specifier|volatile
modifier|*
name|FT_Validator
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* There are three distinct validation levels defined here:              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* FT_VALIDATE_DEFAULT ::                                                */
end_comment
begin_comment
comment|/*   A table that passes this validation level can be used reliably by   */
end_comment
begin_comment
comment|/*   FreeType.  It generally means that all offsets have been checked to */
end_comment
begin_comment
comment|/*   prevent out-of-bound reads, that array counts are correct, etc.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* FT_VALIDATE_TIGHT ::                                                  */
end_comment
begin_comment
comment|/*   A table that passes this validation level can be used reliably and  */
end_comment
begin_comment
comment|/*   doesn't contain invalid data.  For example, a charmap table that    */
end_comment
begin_comment
comment|/*   returns invalid glyph indices will not pass, even though it can     */
end_comment
begin_comment
comment|/*   be used with FreeType in default mode (the library will simply      */
end_comment
begin_comment
comment|/*   return an error later when trying to load the glyph).               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   It also checks that fields which must be a multiple of 2, 4, or 8,  */
end_comment
begin_comment
comment|/*   don't have incorrect values, etc.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* FT_VALIDATE_PARANOID ::                                               */
end_comment
begin_comment
comment|/*   Only for font debugging.  Checks that a table follows the           */
end_comment
begin_comment
comment|/*   specification by 100%.  Very few fonts will be able to pass this    */
end_comment
begin_comment
comment|/*   level anyway but it can be useful for certain tools like font       */
end_comment
begin_comment
comment|/*   editors/converters.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|FT_ValidationLevel_
typedef|typedef
enum|enum
name|FT_ValidationLevel_
block|{
DECL|enumerator|FT_VALIDATE_DEFAULT
name|FT_VALIDATE_DEFAULT
init|=
literal|0
block|,
DECL|enumerator|FT_VALIDATE_TIGHT
name|FT_VALIDATE_TIGHT
block|,
DECL|enumerator|FT_VALIDATE_PARANOID
name|FT_VALIDATE_PARANOID
block|}
DECL|typedef|FT_ValidationLevel
name|FT_ValidationLevel
typedef|;
end_typedef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if
begin_comment
comment|/* Visual C++ (and Intel C++) */
end_comment
begin_comment
comment|/* We disable the warning `structure was padded due to   */
end_comment
begin_comment
comment|/* __declspec(align())' in order to compile cleanly with */
end_comment
begin_comment
comment|/* the maximum level of warnings.                        */
end_comment
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
end_pragma
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4324
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _MSC_VER */
end_comment
begin_comment
comment|/* validator structure */
end_comment
begin_typedef
DECL|struct|FT_ValidatorRec_
typedef|typedef
struct|struct
name|FT_ValidatorRec_
block|{
DECL|member|jump_buffer
name|ft_jmp_buf
name|jump_buffer
decl_stmt|;
comment|/* used for exception handling      */
DECL|member|base
specifier|const
name|FT_Byte
modifier|*
name|base
decl_stmt|;
comment|/* address of table in memory       */
DECL|member|limit
specifier|const
name|FT_Byte
modifier|*
name|limit
decl_stmt|;
comment|/* `base' + sizeof(table) in memory */
DECL|member|level
name|FT_ValidationLevel
name|level
decl_stmt|;
comment|/* validation level                 */
DECL|member|error
name|FT_Error
name|error
decl_stmt|;
comment|/* error returned. 0 means success  */
block|}
DECL|typedef|FT_ValidatorRec
name|FT_ValidatorRec
typedef|;
end_typedef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|FT_VALIDATOR
define|#
directive|define
name|FT_VALIDATOR
parameter_list|(
name|x
parameter_list|)
value|( (FT_Validator)( x ) )
end_define
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|ft_validator_init
argument_list|(
argument|FT_Validator        valid
argument_list|,
argument|const FT_Byte*      base
argument_list|,
argument|const FT_Byte*      limit
argument_list|,
argument|FT_ValidationLevel  level
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Do not use this. It's broken and will cause your validator to crash */
end_comment
begin_comment
comment|/* if you run it on an invalid font.                                   */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
name|ft_validator_run
argument_list|(
argument|FT_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Sets the error field in a validator, then calls `longjmp' to return */
end_comment
begin_comment
comment|/* to high-level caller.  Using `setjmp/longjmp' avoids many stupid    */
end_comment
begin_comment
comment|/* error checks within the validation routines.                        */
end_comment
begin_comment
comment|/*                                                                     */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|ft_validator_error
name|ft_validator_error
argument_list|(
argument|FT_Validator  valid
argument_list|,
argument|FT_Error      error
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Calls ft_validate_error.  Assumes that the `valid' local variable */
end_comment
begin_comment
comment|/* holds a pointer to the current validator object.                  */
end_comment
begin_comment
comment|/*                                                                   */
end_comment
begin_define
DECL|macro|FT_INVALID
define|#
directive|define
name|FT_INVALID
parameter_list|(
name|_error
parameter_list|)
value|FT_INVALID_( _error )
end_define
begin_define
DECL|macro|FT_INVALID_
define|#
directive|define
name|FT_INVALID_
parameter_list|(
name|_error
parameter_list|)
define|\
value|ft_validator_error( valid, FT_THROW( _error ) )
end_define
begin_comment
comment|/* called when a broken table is detected */
end_comment
begin_define
DECL|macro|FT_INVALID_TOO_SHORT
define|#
directive|define
name|FT_INVALID_TOO_SHORT
define|\
value|FT_INVALID( Invalid_Table )
end_define
begin_comment
comment|/* called when an invalid offset is detected */
end_comment
begin_define
DECL|macro|FT_INVALID_OFFSET
define|#
directive|define
name|FT_INVALID_OFFSET
define|\
value|FT_INVALID( Invalid_Offset )
end_define
begin_comment
comment|/* called when an invalid format/value is detected */
end_comment
begin_define
DECL|macro|FT_INVALID_FORMAT
define|#
directive|define
name|FT_INVALID_FORMAT
define|\
value|FT_INVALID( Invalid_Table )
end_define
begin_comment
comment|/* called when an invalid glyph index is detected */
end_comment
begin_define
DECL|macro|FT_INVALID_GLYPH_ID
define|#
directive|define
name|FT_INVALID_GLYPH_ID
define|\
value|FT_INVALID( Invalid_Glyph_Index )
end_define
begin_comment
comment|/* called when an invalid field value is detected */
end_comment
begin_define
DECL|macro|FT_INVALID_DATA
define|#
directive|define
name|FT_INVALID_DATA
define|\
value|FT_INVALID( Invalid_Table )
end_define
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTVALID_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
