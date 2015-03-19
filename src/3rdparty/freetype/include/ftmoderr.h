begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftmoderr.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType module error offsets (specification).                       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2001-2005, 2010, 2013 by                                     */
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
comment|/* This file is used to define the FreeType module error codes.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* If the macro FT_CONFIG_OPTION_USE_MODULE_ERRORS in `ftoption.h' is    */
end_comment
begin_comment
comment|/* set, the lower byte of an error value identifies the error code as    */
end_comment
begin_comment
comment|/* usual.  In addition, the higher byte identifies the module.  For      */
end_comment
begin_comment
comment|/* example, the error `FT_Err_Invalid_File_Format' has value 0x0003, the */
end_comment
begin_comment
comment|/* error `TT_Err_Invalid_File_Format' has value 0x1303, the error        */
end_comment
begin_comment
comment|/* `T1_Err_Invalid_File_Format' has value 0x1403, etc.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Note that `FT_Err_Ok', `TT_Err_Ok', etc. are always equal to zero,    */
end_comment
begin_comment
comment|/* including the high byte.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* If FT_CONFIG_OPTION_USE_MODULE_ERRORS isn't set, the higher byte of   */
end_comment
begin_comment
comment|/* an error value is set to zero.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* To hide the various `XXX_Err_' prefixes in the source code, FreeType  */
end_comment
begin_comment
comment|/* provides some macros in `fttypes.h'.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   FT_ERR( err )                                                       */
end_comment
begin_comment
comment|/*     Add current error module prefix (as defined with the              */
end_comment
begin_comment
comment|/*     `FT_ERR_PREFIX' macro) to `err'.  For example, in the BDF module  */
end_comment
begin_comment
comment|/*     the line                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*       error = FT_ERR( Invalid_Outline );                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     expands to                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*       error = BDF_Err_Invalid_Outline;                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     For simplicity, you can always use `FT_Err_Ok' directly instead   */
end_comment
begin_comment
comment|/*     of `FT_ERR( Ok )'.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   FT_ERR_EQ( errcode, err )                                           */
end_comment
begin_comment
comment|/*   FT_ERR_NEQ( errcode, err )                                          */
end_comment
begin_comment
comment|/*     Compare error code `errcode' with the error `err' for equality    */
end_comment
begin_comment
comment|/*     and inequality, respectively.  Example:                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*       if ( FT_ERR_EQ( error, Invalid_Outline ) )                      */
end_comment
begin_comment
comment|/*         ...                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     Using this macro you don't have to think about error prefixes.    */
end_comment
begin_comment
comment|/*     Of course, if module errors are not active, the above example is  */
end_comment
begin_comment
comment|/*     the same as                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*       if ( error == FT_Err_Invalid_Outline )                          */
end_comment
begin_comment
comment|/*         ...                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   FT_ERROR_BASE( errcode )                                            */
end_comment
begin_comment
comment|/*   FT_ERROR_MODULE( errcode )                                          */
end_comment
begin_comment
comment|/*     Get base error and module error code, respectively.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* It can also be used to create a module error message table easily     */
end_comment
begin_comment
comment|/* with something like                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   {                                                                   */
end_comment
begin_comment
comment|/*     #undef __FTMODERR_H__                                             */
end_comment
begin_comment
comment|/*     #define FT_MODERRDEF( e, v, s )  { FT_Mod_Err_ ## e, s },         */
end_comment
begin_comment
comment|/*     #define FT_MODERR_START_LIST     {                                */
end_comment
begin_comment
comment|/*     #define FT_MODERR_END_LIST       { 0, 0 } };                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     const struct                                                      */
end_comment
begin_comment
comment|/*     {                                                                 */
end_comment
begin_comment
comment|/*       int          mod_err_offset;                                    */
end_comment
begin_comment
comment|/*       const char*  mod_err_msg                                        */
end_comment
begin_comment
comment|/*     } ft_mod_errors[] =                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     #include FT_MODULE_ERRORS_H                                       */
end_comment
begin_comment
comment|/*   }                                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTMODERR_H__
end_ifndef
begin_define
DECL|macro|__FTMODERR_H__
define|#
directive|define
name|__FTMODERR_H__
end_define
begin_comment
comment|/*******************************************************************/
end_comment
begin_comment
comment|/*******************************************************************/
end_comment
begin_comment
comment|/*****                                                         *****/
end_comment
begin_comment
comment|/*****                       SETUP MACROS                      *****/
end_comment
begin_comment
comment|/*****                                                         *****/
end_comment
begin_comment
comment|/*******************************************************************/
end_comment
begin_comment
comment|/*******************************************************************/
end_comment
begin_undef
DECL|macro|FT_NEED_EXTERN_C
undef|#
directive|undef
name|FT_NEED_EXTERN_C
end_undef
begin_ifndef
ifndef|#
directive|ifndef
name|FT_MODERRDEF
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_USE_MODULE_ERRORS
end_ifdef
begin_define
DECL|macro|FT_MODERRDEF
define|#
directive|define
name|FT_MODERRDEF
parameter_list|(
name|e
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
value|FT_Mod_Err_ ## e = v,
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_MODERRDEF
define|#
directive|define
name|FT_MODERRDEF
parameter_list|(
name|e
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
value|FT_Mod_Err_ ## e = 0,
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|FT_MODERR_START_LIST
define|#
directive|define
name|FT_MODERR_START_LIST
value|enum {
end_define
begin_define
DECL|macro|FT_MODERR_END_LIST
define|#
directive|define
name|FT_MODERR_END_LIST
value|FT_Mod_Err_Max };
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_NEED_EXTERN_C
define|#
directive|define
name|FT_NEED_EXTERN_C
end_define
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
endif|#
directive|endif
comment|/* !FT_MODERRDEF */
comment|/*******************************************************************/
comment|/*******************************************************************/
comment|/*****                                                         *****/
comment|/*****               LIST MODULE ERROR BASES                   *****/
comment|/*****                                                         *****/
comment|/*******************************************************************/
comment|/*******************************************************************/
ifdef|#
directive|ifdef
name|FT_MODERR_START_LIST
name|FT_MODERR_START_LIST
endif|#
directive|endif
name|FT_MODERRDEF
argument_list|(
name|Base
argument_list|,
literal|0x000
argument_list|,
literal|"base module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Autofit
argument_list|,
literal|0x100
argument_list|,
literal|"autofitter module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|BDF
argument_list|,
literal|0x200
argument_list|,
literal|"BDF module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Bzip2
argument_list|,
literal|0x300
argument_list|,
literal|"Bzip2 module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Cache
argument_list|,
literal|0x400
argument_list|,
literal|"cache module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|CFF
argument_list|,
literal|0x500
argument_list|,
literal|"CFF module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|CID
argument_list|,
literal|0x600
argument_list|,
literal|"CID module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Gzip
argument_list|,
literal|0x700
argument_list|,
literal|"Gzip module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|LZW
argument_list|,
literal|0x800
argument_list|,
literal|"LZW module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|OTvalid
argument_list|,
literal|0x900
argument_list|,
literal|"OpenType validation module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|PCF
argument_list|,
literal|0xA00
argument_list|,
literal|"PCF module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|PFR
argument_list|,
literal|0xB00
argument_list|,
literal|"PFR module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|PSaux
argument_list|,
literal|0xC00
argument_list|,
literal|"PS auxiliary module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|PShinter
argument_list|,
literal|0xD00
argument_list|,
literal|"PS hinter module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|PSnames
argument_list|,
literal|0xE00
argument_list|,
literal|"PS names module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Raster
argument_list|,
literal|0xF00
argument_list|,
literal|"raster module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|SFNT
argument_list|,
literal|0x1000
argument_list|,
literal|"SFNT module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Smooth
argument_list|,
literal|0x1100
argument_list|,
literal|"smooth raster module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|TrueType
argument_list|,
literal|0x1200
argument_list|,
literal|"TrueType module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Type1
argument_list|,
literal|0x1300
argument_list|,
literal|"Type 1 module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Type42
argument_list|,
literal|0x1400
argument_list|,
literal|"Type 42 module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Winfonts
argument_list|,
literal|0x1500
argument_list|,
literal|"Windows FON/FNT module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|GXvalid
argument_list|,
literal|0x1600
argument_list|,
literal|"GX validation module"
argument_list|)
ifdef|#
directive|ifdef
name|FT_MODERR_END_LIST
name|FT_MODERR_END_LIST
endif|#
directive|endif
comment|/*******************************************************************/
comment|/*******************************************************************/
comment|/*****                                                         *****/
comment|/*****                      CLEANUP                            *****/
comment|/*****                                                         *****/
comment|/*******************************************************************/
comment|/*******************************************************************/
ifdef|#
directive|ifdef
name|FT_NEED_EXTERN_C
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_undef
DECL|macro|FT_MODERR_START_LIST
undef|#
directive|undef
name|FT_MODERR_START_LIST
end_undef
begin_undef
DECL|macro|FT_MODERR_END_LIST
undef|#
directive|undef
name|FT_MODERR_END_LIST
end_undef
begin_undef
DECL|macro|FT_MODERRDEF
undef|#
directive|undef
name|FT_MODERRDEF
end_undef
begin_undef
DECL|macro|FT_NEED_EXTERN_C
undef|#
directive|undef
name|FT_NEED_EXTERN_C
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTMODERR_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
